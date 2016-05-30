#include "sbxmlades.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELXMLADESELEMENT

SB_INLINE void TElXMLAdESElement::Assign(TElXMLAdESElement &Source)
{
	SBCheckError(TElXMLAdESElement_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElXMLAdESElement::Assign(TElXMLAdESElement *Source)
{
	SBCheckError(TElXMLAdESElement_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

bool TElXMLAdESElement::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLAdESElement_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TSBXAdESVersion TElXMLAdESElement::get_XAdESVersion()
{
	TSBXAdESVersionRaw OutResultRaw = 0;
	SBCheckError(TElXMLAdESElement_get_XAdESVersion(_Handle, &OutResultRaw));
	return (TSBXAdESVersion)OutResultRaw;
}

TElXMLAdESElement::TElXMLAdESElement(TElXMLAdESElementHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
}

TElXMLAdESElement::TElXMLAdESElement(TSBXAdESVersion AVersion) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLAdESElement_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLAdESElement::TElXMLAdESElement(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLAdESElement_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLAdESElement::TElXMLAdESElement(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLAdESElement_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLAdESElement::TElXMLAdESElement(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLAdESElement_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLAdESElement::TElXMLAdESElement(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLAdESElement_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLADESELEMENT */

#ifdef SB_USE_CLASS_TELXMLANYTYPE

SB_INLINE void TElXMLAnyType::Assign(TElXMLAdESElement &Source)
{
	SBCheckError(TElXMLAnyType_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElXMLAnyType::Assign(TElXMLAdESElement *Source)
{
	SBCheckError(TElXMLAnyType_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElXMLAnyType::Clear()
{
	SBCheckError(TElXMLAnyType_Clear(_Handle));
}

bool TElXMLAnyType::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLAnyType_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLAnyType::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLAnyType_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLAnyType::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLAnyType_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLAnyType::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLAnyType_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLAnyType::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLAnyType_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TElXMLDOMNode* TElXMLAnyType::get_Value()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLAnyType_get_Value(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Value)
		this->_Inst_Value = new TElXMLDOMNode(hOutResult, ohFalse);
	else
		this->_Inst_Value->updateHandle(hOutResult);
	return this->_Inst_Value;
}

SB_INLINE void TElXMLAnyType::set_Value(TElXMLDOMNode &Value)
{
	SBCheckError(TElXMLAnyType_set_Value(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLAnyType::set_Value(TElXMLDOMNode *Value)
{
	SBCheckError(TElXMLAnyType_set_Value(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

void TElXMLAnyType::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	this->_Inst_Value = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
}

TElXMLAnyType::TElXMLAnyType(TElXMLAnyTypeHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLAnyType::TElXMLAnyType(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLAnyType_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLAnyType::TElXMLAnyType(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLAnyType_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLAnyType::TElXMLAnyType(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLAnyType_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLAnyType::TElXMLAnyType(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLAnyType_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLAnyType::TElXMLAnyType(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLAnyType_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLAnyType::~TElXMLAnyType()
{
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	delete this->_Inst_Value;
	this->_Inst_Value = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
}
#endif /* SB_USE_CLASS_TELXMLANYTYPE */

#ifdef SB_USE_CLASS_TELXMLANYTYPELIST

SB_INLINE void TElXMLAnyTypeList::Assign(TElXMLAnyTypeList &Source, TSBXAdESVersion AVersion)
{
	SBCheckError(TElXMLAnyTypeList_Assign(_Handle, Source.getHandle(), (TSBXAdESVersionRaw)AVersion));
}

SB_INLINE void TElXMLAnyTypeList::Assign(TElXMLAnyTypeList *Source, TSBXAdESVersion AVersion)
{
	SBCheckError(TElXMLAnyTypeList_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (TSBXAdESVersionRaw)AVersion));
}

#ifdef SB_USE_CLASS_TELXMLANYTYPE
SB_INLINE int32_t TElXMLAnyTypeList::Add(TElXMLAnyType &AItem)
{
	int32_t OutResult;
	SBCheckError(TElXMLAnyTypeList_Add(_Handle, AItem.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLAnyTypeList::Add(TElXMLAnyType *AItem)
{
	int32_t OutResult;
	SBCheckError(TElXMLAnyTypeList_Add(_Handle, (AItem != NULL) ? AItem->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLANYTYPE */

#ifdef SB_USE_CLASS_TELXMLANYTYPE
SB_INLINE void TElXMLAnyTypeList::Insert(int32_t Index, TElXMLAnyType &AItem)
{
	SBCheckError(TElXMLAnyTypeList_Insert(_Handle, Index, AItem.getHandle()));
}

SB_INLINE void TElXMLAnyTypeList::Insert(int32_t Index, TElXMLAnyType *AItem)
{
	SBCheckError(TElXMLAnyTypeList_Insert(_Handle, Index, (AItem != NULL) ? AItem->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLANYTYPE */

SB_INLINE void TElXMLAnyTypeList::Delete(int32_t Index)
{
	SBCheckError(TElXMLAnyTypeList_Delete(_Handle, Index));
}

SB_INLINE void TElXMLAnyTypeList::Clear()
{
	SBCheckError(TElXMLAnyTypeList_Clear(_Handle));
}

SB_INLINE int32_t TElXMLAnyTypeList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLAnyTypeList_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLANYTYPE
TElXMLAnyType* TElXMLAnyTypeList::get_Item(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLAnyTypeList_get_Item(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Item)
		this->_Inst_Item = new TElXMLAnyType(hOutResult, ohFalse);
	else
		this->_Inst_Item->updateHandle(hOutResult);
	return this->_Inst_Item;
}
#endif /* SB_USE_CLASS_TELXMLANYTYPE */

void TElXMLAnyTypeList::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLANYTYPE
	this->_Inst_Item = NULL;
#endif /* SB_USE_CLASS_TELXMLANYTYPE */
}

TElXMLAnyTypeList::TElXMLAnyTypeList(TElXMLAnyTypeListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElXMLAnyTypeList::TElXMLAnyTypeList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLAnyTypeList_Create(&_Handle));
}

TElXMLAnyTypeList::~TElXMLAnyTypeList()
{
#ifdef SB_USE_CLASS_TELXMLANYTYPE
	delete this->_Inst_Item;
	this->_Inst_Item = NULL;
#endif /* SB_USE_CLASS_TELXMLANYTYPE */
}
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */

#ifdef SB_USE_CLASS_TELXMLOBJECTIDENTIFIER

SB_INLINE void TElXMLObjectIdentifier::Assign(TElXMLAdESElement &Source)
{
	SBCheckError(TElXMLObjectIdentifier_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElXMLObjectIdentifier::Assign(TElXMLAdESElement *Source)
{
	SBCheckError(TElXMLObjectIdentifier_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElXMLObjectIdentifier::Clear()
{
	SBCheckError(TElXMLObjectIdentifier_Clear(_Handle));
}

bool TElXMLObjectIdentifier::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLObjectIdentifier_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLObjectIdentifier::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLObjectIdentifier_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLObjectIdentifier::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLObjectIdentifier_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLObjectIdentifier::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLObjectIdentifier_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLObjectIdentifier::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLObjectIdentifier_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLObjectIdentifier::get_Description(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLObjectIdentifier_get_Description(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-185012644, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLObjectIdentifier::get_Description(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLObjectIdentifier_get_Description(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-185012644, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLObjectIdentifier::set_Description(const sb_u16string &Value)
{
	SBCheckError(TElXMLObjectIdentifier_set_Description(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLObjectIdentifier::set_Description(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLObjectIdentifier_set_Description(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElXMLObjectIdentifier::get_DocumentationReferences()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLObjectIdentifier_get_DocumentationReferences(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DocumentationReferences)
		this->_Inst_DocumentationReferences = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_DocumentationReferences->updateHandle(hOutResult);
	return this->_Inst_DocumentationReferences;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

void TElXMLObjectIdentifier::get_Identifier(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLObjectIdentifier_get_Identifier(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1840984911, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLObjectIdentifier::get_Identifier(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLObjectIdentifier_get_Identifier(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1840984911, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLObjectIdentifier::set_Identifier(const sb_u16string &Value)
{
	SBCheckError(TElXMLObjectIdentifier_set_Identifier(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLObjectIdentifier::set_Identifier(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLObjectIdentifier_set_Identifier(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TSBXAdESQualifierType TElXMLObjectIdentifier::get_IdentifierQualifier()
{
	TSBXAdESQualifierTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLObjectIdentifier_get_IdentifierQualifier(_Handle, &OutResultRaw));
	return (TSBXAdESQualifierType)OutResultRaw;
}

SB_INLINE void TElXMLObjectIdentifier::set_IdentifierQualifier(TSBXAdESQualifierType Value)
{
	SBCheckError(TElXMLObjectIdentifier_set_IdentifierQualifier(_Handle, (TSBXAdESQualifierTypeRaw)Value));
}

void TElXMLObjectIdentifier::initInstances()
{
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_DocumentationReferences = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}

TElXMLObjectIdentifier::TElXMLObjectIdentifier(TElXMLObjectIdentifierHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLObjectIdentifier::TElXMLObjectIdentifier(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLObjectIdentifier_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLObjectIdentifier::TElXMLObjectIdentifier(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLObjectIdentifier_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLObjectIdentifier::TElXMLObjectIdentifier(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLObjectIdentifier_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLObjectIdentifier::TElXMLObjectIdentifier(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLObjectIdentifier_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLObjectIdentifier::TElXMLObjectIdentifier(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLObjectIdentifier_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLObjectIdentifier::~TElXMLObjectIdentifier()
{
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_DocumentationReferences;
	this->_Inst_DocumentationReferences = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}
#endif /* SB_USE_CLASS_TELXMLOBJECTIDENTIFIER */

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA

SB_INLINE void TElXMLEncapsulatedPKIData::Assign(TElXMLAdESElement &Source)
{
	SBCheckError(TElXMLEncapsulatedPKIData_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElXMLEncapsulatedPKIData::Assign(TElXMLAdESElement *Source)
{
	SBCheckError(TElXMLEncapsulatedPKIData_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElXMLEncapsulatedPKIData::Clear()
{
	SBCheckError(TElXMLEncapsulatedPKIData_Clear(_Handle));
}

bool TElXMLEncapsulatedPKIData::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLEncapsulatedPKIData_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLEncapsulatedPKIData::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLEncapsulatedPKIData_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLEncapsulatedPKIData::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLEncapsulatedPKIData_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLEncapsulatedPKIData::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLEncapsulatedPKIData_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLEncapsulatedPKIData::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLEncapsulatedPKIData_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLEncapsulatedPKIData::get_Data(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLEncapsulatedPKIData_get_Data(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-659652681, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElXMLEncapsulatedPKIData::set_Data(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElXMLEncapsulatedPKIData_set_Data(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElXMLEncapsulatedPKIData::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLEncapsulatedPKIData_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(382146332, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLEncapsulatedPKIData::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLEncapsulatedPKIData_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(382146332, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLEncapsulatedPKIData::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLEncapsulatedPKIData_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLEncapsulatedPKIData::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLEncapsulatedPKIData_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TSBXAdESEncodingMethod TElXMLEncapsulatedPKIData::get_Encoding()
{
	TSBXAdESEncodingMethodRaw OutResultRaw = 0;
	SBCheckError(TElXMLEncapsulatedPKIData_get_Encoding(_Handle, &OutResultRaw));
	return (TSBXAdESEncodingMethod)OutResultRaw;
}

SB_INLINE void TElXMLEncapsulatedPKIData::set_Encoding(TSBXAdESEncodingMethod Value)
{
	SBCheckError(TElXMLEncapsulatedPKIData_set_Encoding(_Handle, (TSBXAdESEncodingMethodRaw)Value));
}

TElXMLEncapsulatedPKIData::TElXMLEncapsulatedPKIData(TElXMLEncapsulatedPKIDataHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
}

TElXMLEncapsulatedPKIData::TElXMLEncapsulatedPKIData(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLEncapsulatedPKIData_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLEncapsulatedPKIData::TElXMLEncapsulatedPKIData(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLEncapsulatedPKIData_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLEncapsulatedPKIData::TElXMLEncapsulatedPKIData(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLEncapsulatedPKIData_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLEncapsulatedPKIData::TElXMLEncapsulatedPKIData(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLEncapsulatedPKIData_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLEncapsulatedPKIData::TElXMLEncapsulatedPKIData(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLEncapsulatedPKIData_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA */

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATALIST

SB_INLINE void TElXMLEncapsulatedPKIDataList::Assign(TElXMLEncapsulatedPKIDataList &Source, TSBXAdESVersion AVersion)
{
	SBCheckError(TElXMLEncapsulatedPKIDataList_Assign(_Handle, Source.getHandle(), (TSBXAdESVersionRaw)AVersion));
}

SB_INLINE void TElXMLEncapsulatedPKIDataList::Assign(TElXMLEncapsulatedPKIDataList *Source, TSBXAdESVersion AVersion)
{
	SBCheckError(TElXMLEncapsulatedPKIDataList_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (TSBXAdESVersionRaw)AVersion));
}

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA
SB_INLINE int32_t TElXMLEncapsulatedPKIDataList::Add(TElXMLEncapsulatedPKIData &APKIData)
{
	int32_t OutResult;
	SBCheckError(TElXMLEncapsulatedPKIDataList_Add(_Handle, APKIData.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLEncapsulatedPKIDataList::Add(TElXMLEncapsulatedPKIData *APKIData)
{
	int32_t OutResult;
	SBCheckError(TElXMLEncapsulatedPKIDataList_Add(_Handle, (APKIData != NULL) ? APKIData->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA */

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA
SB_INLINE void TElXMLEncapsulatedPKIDataList::Insert(int32_t Index, TElXMLEncapsulatedPKIData &APKIData)
{
	SBCheckError(TElXMLEncapsulatedPKIDataList_Insert(_Handle, Index, APKIData.getHandle()));
}

SB_INLINE void TElXMLEncapsulatedPKIDataList::Insert(int32_t Index, TElXMLEncapsulatedPKIData *APKIData)
{
	SBCheckError(TElXMLEncapsulatedPKIDataList_Insert(_Handle, Index, (APKIData != NULL) ? APKIData->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA */

SB_INLINE void TElXMLEncapsulatedPKIDataList::Delete(int32_t Index)
{
	SBCheckError(TElXMLEncapsulatedPKIDataList_Delete(_Handle, Index));
}

SB_INLINE void TElXMLEncapsulatedPKIDataList::Clear()
{
	SBCheckError(TElXMLEncapsulatedPKIDataList_Clear(_Handle));
}

SB_INLINE int32_t TElXMLEncapsulatedPKIDataList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLEncapsulatedPKIDataList_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA
TElXMLEncapsulatedPKIData* TElXMLEncapsulatedPKIDataList::get_PKIData(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLEncapsulatedPKIDataList_get_PKIData(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PKIData)
		this->_Inst_PKIData = new TElXMLEncapsulatedPKIData(hOutResult, ohFalse);
	else
		this->_Inst_PKIData->updateHandle(hOutResult);
	return this->_Inst_PKIData;
}
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA */

void TElXMLEncapsulatedPKIDataList::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA
	this->_Inst_PKIData = NULL;
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA */
}

TElXMLEncapsulatedPKIDataList::TElXMLEncapsulatedPKIDataList(TElXMLEncapsulatedPKIDataListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElXMLEncapsulatedPKIDataList::TElXMLEncapsulatedPKIDataList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLEncapsulatedPKIDataList_Create(&_Handle));
}

TElXMLEncapsulatedPKIDataList::~TElXMLEncapsulatedPKIDataList()
{
#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA
	delete this->_Inst_PKIData;
	this->_Inst_PKIData = NULL;
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA */
}
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATALIST */

#ifdef SB_USE_CLASS_TELXMLHASHDATAINFO

SB_INLINE void TElXMLHashDataInfo::Clear()
{
	SBCheckError(TElXMLHashDataInfo_Clear(_Handle));
}

bool TElXMLHashDataInfo::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLHashDataInfo_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLHashDataInfo::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLHashDataInfo_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLHashDataInfo::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLHashDataInfo_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLHashDataInfo::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLHashDataInfo_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLHashDataInfo::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLHashDataInfo_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLHashDataInfo::GetHashData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLHashDataInfo_GetHashData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-356156926, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
TElXMLTransformChain* TElXMLHashDataInfo::get_TransformChain()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLHashDataInfo_get_TransformChain(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TransformChain)
		this->_Inst_TransformChain = new TElXMLTransformChain(hOutResult, ohFalse);
	else
		this->_Inst_TransformChain->updateHandle(hOutResult);
	return this->_Inst_TransformChain;
}

SB_INLINE void TElXMLHashDataInfo::set_TransformChain(TElXMLTransformChain &Value)
{
	SBCheckError(TElXMLHashDataInfo_set_TransformChain(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLHashDataInfo::set_TransformChain(TElXMLTransformChain *Value)
{
	SBCheckError(TElXMLHashDataInfo_set_TransformChain(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */

void TElXMLHashDataInfo::get_URI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLHashDataInfo_get_URI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-699568962, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLHashDataInfo::get_URI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLHashDataInfo_get_URI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-699568962, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLHashDataInfo::set_URI(const sb_u16string &Value)
{
	SBCheckError(TElXMLHashDataInfo_set_URI(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLHashDataInfo::set_URI(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLHashDataInfo_set_URI(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLHashDataInfo::get_URIData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLHashDataInfo_get_URIData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1165832699, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElXMLHashDataInfo::set_URIData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElXMLHashDataInfo_set_URIData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TElXMLDOMNode* TElXMLHashDataInfo::get_URINode()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLHashDataInfo_get_URINode(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_URINode)
		this->_Inst_URINode = new TElXMLDOMNode(hOutResult, ohFalse);
	else
		this->_Inst_URINode->updateHandle(hOutResult);
	return this->_Inst_URINode;
}

SB_INLINE void TElXMLHashDataInfo::set_URINode(TElXMLDOMNode &Value)
{
	SBCheckError(TElXMLHashDataInfo_set_URINode(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLHashDataInfo::set_URINode(TElXMLDOMNode *Value)
{
	SBCheckError(TElXMLHashDataInfo_set_URINode(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

void TElXMLHashDataInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
	this->_Inst_TransformChain = NULL;
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	this->_Inst_URINode = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
}

TElXMLHashDataInfo::TElXMLHashDataInfo(TElXMLHashDataInfoHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLHashDataInfo::TElXMLHashDataInfo(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLHashDataInfo_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLHashDataInfo::TElXMLHashDataInfo(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLHashDataInfo_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLHashDataInfo::TElXMLHashDataInfo(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLHashDataInfo_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLHashDataInfo::TElXMLHashDataInfo(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLHashDataInfo_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLHashDataInfo::TElXMLHashDataInfo(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLHashDataInfo_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLHashDataInfo::~TElXMLHashDataInfo()
{
#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
	delete this->_Inst_TransformChain;
	this->_Inst_TransformChain = NULL;
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	delete this->_Inst_URINode;
	this->_Inst_URINode = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
}
#endif /* SB_USE_CLASS_TELXMLHASHDATAINFO */

#ifdef SB_USE_CLASS_TELXMLHASHDATAINFOLIST

#ifdef SB_USE_CLASS_TELXMLHASHDATAINFO
SB_INLINE int32_t TElXMLHashDataInfoList::Add(TElXMLHashDataInfo &AHashDataInfo)
{
	int32_t OutResult;
	SBCheckError(TElXMLHashDataInfoList_Add(_Handle, AHashDataInfo.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLHashDataInfoList::Add(TElXMLHashDataInfo *AHashDataInfo)
{
	int32_t OutResult;
	SBCheckError(TElXMLHashDataInfoList_Add(_Handle, (AHashDataInfo != NULL) ? AHashDataInfo->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLHASHDATAINFO */

#ifdef SB_USE_CLASS_TELXMLHASHDATAINFO
SB_INLINE void TElXMLHashDataInfoList::Insert(int32_t Index, TElXMLHashDataInfo &AHashDataInfo)
{
	SBCheckError(TElXMLHashDataInfoList_Insert(_Handle, Index, AHashDataInfo.getHandle()));
}

SB_INLINE void TElXMLHashDataInfoList::Insert(int32_t Index, TElXMLHashDataInfo *AHashDataInfo)
{
	SBCheckError(TElXMLHashDataInfoList_Insert(_Handle, Index, (AHashDataInfo != NULL) ? AHashDataInfo->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLHASHDATAINFO */

SB_INLINE void TElXMLHashDataInfoList::Delete(int32_t Index)
{
	SBCheckError(TElXMLHashDataInfoList_Delete(_Handle, Index));
}

SB_INLINE void TElXMLHashDataInfoList::Clear()
{
	SBCheckError(TElXMLHashDataInfoList_Clear(_Handle));
}

SB_INLINE int32_t TElXMLHashDataInfoList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLHashDataInfoList_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLHASHDATAINFO
TElXMLHashDataInfo* TElXMLHashDataInfoList::get_HashDataInfo(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLHashDataInfoList_get_HashDataInfo(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HashDataInfo)
		this->_Inst_HashDataInfo = new TElXMLHashDataInfo(hOutResult, ohFalse);
	else
		this->_Inst_HashDataInfo->updateHandle(hOutResult);
	return this->_Inst_HashDataInfo;
}
#endif /* SB_USE_CLASS_TELXMLHASHDATAINFO */

void TElXMLHashDataInfoList::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLHASHDATAINFO
	this->_Inst_HashDataInfo = NULL;
#endif /* SB_USE_CLASS_TELXMLHASHDATAINFO */
}

TElXMLHashDataInfoList::TElXMLHashDataInfoList(TElXMLHashDataInfoListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElXMLHashDataInfoList::TElXMLHashDataInfoList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLHashDataInfoList_Create(&_Handle));
}

TElXMLHashDataInfoList::~TElXMLHashDataInfoList()
{
#ifdef SB_USE_CLASS_TELXMLHASHDATAINFO
	delete this->_Inst_HashDataInfo;
	this->_Inst_HashDataInfo = NULL;
#endif /* SB_USE_CLASS_TELXMLHASHDATAINFO */
}
#endif /* SB_USE_CLASS_TELXMLHASHDATAINFOLIST */

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
SB_INLINE TElClientTSPInfoHandle TElXMLCustomTimestamp::GetTimestampInfo()
{
	TElClientTSPInfoHandle OutResult;
	SBCheckError(TElXMLCustomTimestamp_GetTimestampInfo(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
bool TElXMLCustomTimestamp::CheckTimestamp(TElClientTSPInfo &Info)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLCustomTimestamp_CheckTimestamp(_Handle, Info.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElXMLCustomTimestamp::CheckTimestamp(TElClientTSPInfo *Info)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLCustomTimestamp_CheckTimestamp(_Handle, (Info != NULL) ? Info->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

#ifdef SB_USE_CLASSES_TELCLIENTTSPINFO_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
bool TElXMLCustomTimestamp::CheckTimestamp(TElClientTSPInfo &Info, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLCustomTimestamp_CheckTimestamp_1(_Handle, Info.getHandle(), Manager.getHandle(), Prov.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElXMLCustomTimestamp::CheckTimestamp(TElClientTSPInfo *Info, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLCustomTimestamp_CheckTimestamp_1(_Handle, (Info != NULL) ? Info->getHandle() : SB_NULL_HANDLE, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELCLIENTTSPINFO_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE int32_t TElXMLCustomTimestamp::Timestamp(TElCustomTSPClient &TSPClient)
{
	int32_t OutResult;
	SBCheckError(TElXMLCustomTimestamp_Timestamp(_Handle, TSPClient.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLCustomTimestamp::Timestamp(TElCustomTSPClient *TSPClient)
{
	int32_t OutResult;
	SBCheckError(TElXMLCustomTimestamp_Timestamp(_Handle, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELCUSTOMTSPCLIENT
SB_INLINE int32_t TElXMLCustomTimestamp::Timestamp(TElCustomTSPClient &TSPClient, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov)
{
	int32_t OutResult;
	SBCheckError(TElXMLCustomTimestamp_Timestamp_1(_Handle, TSPClient.getHandle(), Manager.getHandle(), Prov.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLCustomTimestamp::Timestamp(TElCustomTSPClient *TSPClient, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov)
{
	int32_t OutResult;
	SBCheckError(TElXMLCustomTimestamp_Timestamp_1(_Handle, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELCUSTOMTSPCLIENT */

TElXMLCustomTimestamp::TElXMLCustomTimestamp(TElXMLCustomTimestampHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
}

TElXMLCustomTimestamp::TElXMLCustomTimestamp(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLCustomTimestamp_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLCustomTimestamp::TElXMLCustomTimestamp(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLCustomTimestamp_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLCustomTimestamp::TElXMLCustomTimestamp(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLCustomTimestamp_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLCustomTimestamp::TElXMLCustomTimestamp(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLCustomTimestamp_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLCustomTimestamp::TElXMLCustomTimestamp(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLCustomTimestamp_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP */

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP
SB_INLINE int32_t TElXMLCustomTimestampList::Add(TElXMLCustomTimestamp &ATimestamp)
{
	int32_t OutResult;
	SBCheckError(TElXMLCustomTimestampList_Add(_Handle, ATimestamp.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLCustomTimestampList::Add(TElXMLCustomTimestamp *ATimestamp)
{
	int32_t OutResult;
	SBCheckError(TElXMLCustomTimestampList_Add(_Handle, (ATimestamp != NULL) ? ATimestamp->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP */

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP
SB_INLINE void TElXMLCustomTimestampList::Insert(int32_t Index, TElXMLCustomTimestamp &ATimestamp)
{
	SBCheckError(TElXMLCustomTimestampList_Insert(_Handle, Index, ATimestamp.getHandle()));
}

SB_INLINE void TElXMLCustomTimestampList::Insert(int32_t Index, TElXMLCustomTimestamp *ATimestamp)
{
	SBCheckError(TElXMLCustomTimestampList_Insert(_Handle, Index, (ATimestamp != NULL) ? ATimestamp->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP */

SB_INLINE void TElXMLCustomTimestampList::Delete(int32_t Index)
{
	SBCheckError(TElXMLCustomTimestampList_Delete(_Handle, Index));
}

SB_INLINE void TElXMLCustomTimestampList::Clear()
{
	SBCheckError(TElXMLCustomTimestampList_Clear(_Handle));
}

SB_INLINE int32_t TElXMLCustomTimestampList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLCustomTimestampList_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP
TElXMLCustomTimestamp* TElXMLCustomTimestampList::get_Timestamp(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCustomTimestampList_get_Timestamp(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Timestamp)
		this->_Inst_Timestamp = new TElXMLCustomTimestamp(hOutResult, ohFalse);
	else
		this->_Inst_Timestamp->updateHandle(hOutResult);
	return this->_Inst_Timestamp;
}
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP */

void TElXMLCustomTimestampList::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP
	this->_Inst_Timestamp = NULL;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP */
}

TElXMLCustomTimestampList::TElXMLCustomTimestampList(TElXMLCustomTimestampListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElXMLCustomTimestampList::TElXMLCustomTimestampList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCustomTimestampList_Create(&_Handle));
}

TElXMLCustomTimestampList::~TElXMLCustomTimestampList()
{
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP
	delete this->_Inst_Timestamp;
	this->_Inst_Timestamp = NULL;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP */
}
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMP

SB_INLINE void TElXMLTimestamp::Clear()
{
	SBCheckError(TElXMLTimestamp_Clear(_Handle));
}

bool TElXMLTimestamp::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLTimestamp_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLTimestamp::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLTimestamp_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLTimestamp::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLTimestamp_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLTimestamp::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLTimestamp_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLTimestamp::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLTimestamp_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
SB_INLINE TElClientTSPInfoHandle TElXMLTimestamp::GetTimestampInfo()
{
	TElClientTSPInfoHandle OutResult;
	SBCheckError(TElXMLTimestamp_GetTimestampInfo(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

#ifdef SB_USE_CLASSES_TELCLIENTTSPINFO_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
bool TElXMLTimestamp::CheckTimestamp(TElClientTSPInfo &Info, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLTimestamp_CheckTimestamp(_Handle, Info.getHandle(), Manager.getHandle(), Prov.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElXMLTimestamp::CheckTimestamp(TElClientTSPInfo *Info, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLTimestamp_CheckTimestamp(_Handle, (Info != NULL) ? Info->getHandle() : SB_NULL_HANDLE, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELCLIENTTSPINFO_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELCUSTOMTSPCLIENT
SB_INLINE int32_t TElXMLTimestamp::Timestamp(TElCustomTSPClient &TSPClient, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov)
{
	int32_t OutResult;
	SBCheckError(TElXMLTimestamp_Timestamp(_Handle, TSPClient.getHandle(), Manager.getHandle(), Prov.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLTimestamp::Timestamp(TElCustomTSPClient *TSPClient, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov)
{
	int32_t OutResult;
	SBCheckError(TElXMLTimestamp_Timestamp(_Handle, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELXMLHASHDATAINFOLIST
TElXMLHashDataInfoList* TElXMLTimestamp::get_HashDataInfos()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLTimestamp_get_HashDataInfos(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HashDataInfos)
		this->_Inst_HashDataInfos = new TElXMLHashDataInfoList(hOutResult, ohFalse);
	else
		this->_Inst_HashDataInfos->updateHandle(hOutResult);
	return this->_Inst_HashDataInfos;
}
#endif /* SB_USE_CLASS_TELXMLHASHDATAINFOLIST */

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA
TElXMLEncapsulatedPKIData* TElXMLTimestamp::get_EncapsulatedTimestamp()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLTimestamp_get_EncapsulatedTimestamp(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncapsulatedTimestamp)
		this->_Inst_EncapsulatedTimestamp = new TElXMLEncapsulatedPKIData(hOutResult, ohFalse);
	else
		this->_Inst_EncapsulatedTimestamp->updateHandle(hOutResult);
	return this->_Inst_EncapsulatedTimestamp;
}

SB_INLINE void TElXMLTimestamp::set_EncapsulatedTimestamp(TElXMLEncapsulatedPKIData &Value)
{
	SBCheckError(TElXMLTimestamp_set_EncapsulatedTimestamp(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLTimestamp::set_EncapsulatedTimestamp(TElXMLEncapsulatedPKIData *Value)
{
	SBCheckError(TElXMLTimestamp_set_EncapsulatedTimestamp(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA */

#ifdef SB_USE_CLASS_TELXMLANYTYPE
TElXMLAnyType* TElXMLTimestamp::get_XMLTimestamp()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLTimestamp_get_XMLTimestamp(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_XMLTimestamp)
		this->_Inst_XMLTimestamp = new TElXMLAnyType(hOutResult, ohFalse);
	else
		this->_Inst_XMLTimestamp->updateHandle(hOutResult);
	return this->_Inst_XMLTimestamp;
}

SB_INLINE void TElXMLTimestamp::set_XMLTimestamp(TElXMLAnyType &Value)
{
	SBCheckError(TElXMLTimestamp_set_XMLTimestamp(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLTimestamp::set_XMLTimestamp(TElXMLAnyType *Value)
{
	SBCheckError(TElXMLTimestamp_set_XMLTimestamp(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLANYTYPE */

void TElXMLTimestamp::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLHASHDATAINFOLIST
	this->_Inst_HashDataInfos = NULL;
#endif /* SB_USE_CLASS_TELXMLHASHDATAINFOLIST */
#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA
	this->_Inst_EncapsulatedTimestamp = NULL;
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA */
#ifdef SB_USE_CLASS_TELXMLANYTYPE
	this->_Inst_XMLTimestamp = NULL;
#endif /* SB_USE_CLASS_TELXMLANYTYPE */
}

TElXMLTimestamp::TElXMLTimestamp(TElXMLTimestampHandle handle, TElOwnHandle ownHandle) : TElXMLCustomTimestamp(handle, ownHandle)
{
	initInstances();
}

TElXMLTimestamp::TElXMLTimestamp(TSBXAdESVersion AVersion) : TElXMLCustomTimestamp(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLTimestamp_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLTimestamp::TElXMLTimestamp(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLCustomTimestamp(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLTimestamp_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLTimestamp::TElXMLTimestamp(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLCustomTimestamp(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLTimestamp_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLTimestamp::TElXMLTimestamp(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLCustomTimestamp(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLTimestamp_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLTimestamp::TElXMLTimestamp(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLCustomTimestamp(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLTimestamp_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLTimestamp::~TElXMLTimestamp()
{
#ifdef SB_USE_CLASS_TELXMLHASHDATAINFOLIST
	delete this->_Inst_HashDataInfos;
	this->_Inst_HashDataInfos = NULL;
#endif /* SB_USE_CLASS_TELXMLHASHDATAINFOLIST */
#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA
	delete this->_Inst_EncapsulatedTimestamp;
	this->_Inst_EncapsulatedTimestamp = NULL;
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA */
#ifdef SB_USE_CLASS_TELXMLANYTYPE
	delete this->_Inst_XMLTimestamp;
	this->_Inst_XMLTimestamp = NULL;
#endif /* SB_USE_CLASS_TELXMLANYTYPE */
}
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMPLIST

#ifdef SB_USE_CLASS_TELXMLTIMESTAMP
SB_INLINE int32_t TElXMLTimestampList::Add(TElXMLTimestamp &ATimestamp)
{
	int32_t OutResult;
	SBCheckError(TElXMLTimestampList_Add(_Handle, ATimestamp.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLTimestampList::Add(TElXMLTimestamp *ATimestamp)
{
	int32_t OutResult;
	SBCheckError(TElXMLTimestampList_Add(_Handle, (ATimestamp != NULL) ? ATimestamp->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMP
SB_INLINE void TElXMLTimestampList::Insert(int32_t Index, TElXMLTimestamp &ATimestamp)
{
	SBCheckError(TElXMLTimestampList_Insert(_Handle, Index, ATimestamp.getHandle()));
}

SB_INLINE void TElXMLTimestampList::Insert(int32_t Index, TElXMLTimestamp *ATimestamp)
{
	SBCheckError(TElXMLTimestampList_Insert(_Handle, Index, (ATimestamp != NULL) ? ATimestamp->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMP
TElXMLTimestamp* TElXMLTimestampList::get_Timestamp_TElXMLTimestamp(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLTimestampList_get_Timestamp_TElXMLTimestamp(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Timestamp)
		this->_Inst_Timestamp = new TElXMLTimestamp(hOutResult, ohFalse);
	else
		this->_Inst_Timestamp->updateHandle(hOutResult);
	return this->_Inst_Timestamp;
}
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP */

void TElXMLTimestampList::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLTIMESTAMP
	this->_Inst_Timestamp = NULL;
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP */
}

TElXMLTimestampList::TElXMLTimestampList(TElXMLTimestampListHandle handle, TElOwnHandle ownHandle) : TElXMLCustomTimestampList(handle, ownHandle)
{
	initInstances();
}

TElXMLTimestampList::TElXMLTimestampList() : TElXMLCustomTimestampList(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLTimestampList_Create(&_Handle));
}

TElXMLTimestampList::~TElXMLTimestampList()
{
#ifdef SB_USE_CLASS_TELXMLTIMESTAMP
	delete this->_Inst_Timestamp;
	this->_Inst_Timestamp = NULL;
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP */
}
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPLIST */

#ifdef SB_USE_CLASS_TELXMLINCLUDE

SB_INLINE void TElXMLInclude::Clear()
{
	SBCheckError(TElXMLInclude_Clear(_Handle));
}

bool TElXMLInclude::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLInclude_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLInclude::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLInclude_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLInclude::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLInclude_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLInclude::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLInclude_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLInclude::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLInclude_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELHASHFUNCTION
SB_INLINE void TElXMLInclude::ProcessIncludeData(TElXMLCanonicalizationMethod CanonicalizationMethod, TElHashFunction &HashFunc)
{
	SBCheckError(TElXMLInclude_ProcessIncludeData(_Handle, (TElXMLCanonicalizationMethodRaw)CanonicalizationMethod, HashFunc.getHandle()));
}

SB_INLINE void TElXMLInclude::ProcessIncludeData(TElXMLCanonicalizationMethod CanonicalizationMethod, TElHashFunction *HashFunc)
{
	SBCheckError(TElXMLInclude_ProcessIncludeData(_Handle, (TElXMLCanonicalizationMethodRaw)CanonicalizationMethod, (HashFunc != NULL) ? HashFunc->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHASHFUNCTION */

bool TElXMLInclude::get_ReferencedData()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLInclude_get_ReferencedData(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLInclude::set_ReferencedData(bool Value)
{
	SBCheckError(TElXMLInclude_set_ReferencedData(_Handle, (int8_t)Value));
}

void TElXMLInclude::get_URI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLInclude_get_URI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1475280180, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLInclude::get_URI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLInclude_get_URI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1475280180, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLInclude::set_URI(const sb_u16string &Value)
{
	SBCheckError(TElXMLInclude_set_URI(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLInclude::set_URI(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLInclude_set_URI(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLInclude::get_URIData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLInclude_get_URIData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-618523135, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElXMLInclude::set_URIData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElXMLInclude_set_URIData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TElXMLDOMNode* TElXMLInclude::get_URINode()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLInclude_get_URINode(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_URINode)
		this->_Inst_URINode = new TElXMLDOMNode(hOutResult, ohFalse);
	else
		this->_Inst_URINode->updateHandle(hOutResult);
	return this->_Inst_URINode;
}

SB_INLINE void TElXMLInclude::set_URINode(TElXMLDOMNode &Value)
{
	SBCheckError(TElXMLInclude_set_URINode(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLInclude::set_URINode(TElXMLDOMNode *Value)
{
	SBCheckError(TElXMLInclude_set_URINode(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLREFERENCE
TElXMLReference* TElXMLInclude::get_URIReference()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLInclude_get_URIReference(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_URIReference)
		this->_Inst_URIReference = new TElXMLReference(hOutResult, ohFalse);
	else
		this->_Inst_URIReference->updateHandle(hOutResult);
	return this->_Inst_URIReference;
}

SB_INLINE void TElXMLInclude::set_URIReference(TElXMLReference &Value)
{
	SBCheckError(TElXMLInclude_set_URIReference(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLInclude::set_URIReference(TElXMLReference *Value)
{
	SBCheckError(TElXMLInclude_set_URIReference(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLREFERENCE */

void TElXMLInclude::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	this->_Inst_URINode = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
#ifdef SB_USE_CLASS_TELXMLREFERENCE
	this->_Inst_URIReference = NULL;
#endif /* SB_USE_CLASS_TELXMLREFERENCE */
}

TElXMLInclude::TElXMLInclude(TElXMLIncludeHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLInclude::TElXMLInclude(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLInclude_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLInclude::TElXMLInclude(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLInclude_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLInclude::TElXMLInclude(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLInclude_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLInclude::TElXMLInclude(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLInclude_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLInclude::TElXMLInclude(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLInclude_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLInclude::~TElXMLInclude()
{
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	delete this->_Inst_URINode;
	this->_Inst_URINode = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
#ifdef SB_USE_CLASS_TELXMLREFERENCE
	delete this->_Inst_URIReference;
	this->_Inst_URIReference = NULL;
#endif /* SB_USE_CLASS_TELXMLREFERENCE */
}
#endif /* SB_USE_CLASS_TELXMLINCLUDE */

#ifdef SB_USE_CLASS_TELXMLINCLUDELIST

#ifdef SB_USE_CLASS_TELXMLINCLUDE
SB_INLINE int32_t TElXMLIncludeList::Add(TElXMLInclude &AInclude)
{
	int32_t OutResult;
	SBCheckError(TElXMLIncludeList_Add(_Handle, AInclude.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLIncludeList::Add(TElXMLInclude *AInclude)
{
	int32_t OutResult;
	SBCheckError(TElXMLIncludeList_Add(_Handle, (AInclude != NULL) ? AInclude->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLINCLUDE */

#ifdef SB_USE_CLASS_TELXMLINCLUDE
SB_INLINE void TElXMLIncludeList::Insert(int32_t Index, TElXMLInclude &AInclude)
{
	SBCheckError(TElXMLIncludeList_Insert(_Handle, Index, AInclude.getHandle()));
}

SB_INLINE void TElXMLIncludeList::Insert(int32_t Index, TElXMLInclude *AInclude)
{
	SBCheckError(TElXMLIncludeList_Insert(_Handle, Index, (AInclude != NULL) ? AInclude->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLINCLUDE */

SB_INLINE void TElXMLIncludeList::Delete(int32_t Index)
{
	SBCheckError(TElXMLIncludeList_Delete(_Handle, Index));
}

SB_INLINE void TElXMLIncludeList::Clear()
{
	SBCheckError(TElXMLIncludeList_Clear(_Handle));
}

SB_INLINE int32_t TElXMLIncludeList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLIncludeList_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLINCLUDE
TElXMLInclude* TElXMLIncludeList::get_Includes(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLIncludeList_get_Includes(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Includes)
		this->_Inst_Includes = new TElXMLInclude(hOutResult, ohFalse);
	else
		this->_Inst_Includes->updateHandle(hOutResult);
	return this->_Inst_Includes;
}
#endif /* SB_USE_CLASS_TELXMLINCLUDE */

void TElXMLIncludeList::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLINCLUDE
	this->_Inst_Includes = NULL;
#endif /* SB_USE_CLASS_TELXMLINCLUDE */
}

TElXMLIncludeList::TElXMLIncludeList(TElXMLIncludeListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElXMLIncludeList::TElXMLIncludeList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLIncludeList_Create(&_Handle));
}

TElXMLIncludeList::~TElXMLIncludeList()
{
#ifdef SB_USE_CLASS_TELXMLINCLUDE
	delete this->_Inst_Includes;
	this->_Inst_Includes = NULL;
#endif /* SB_USE_CLASS_TELXMLINCLUDE */
}
#endif /* SB_USE_CLASS_TELXMLINCLUDELIST */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2

SB_INLINE void TElXMLTimestamp_v1_2_2::Clear()
{
	SBCheckError(TElXMLTimestamp_v1_2_2_Clear(_Handle));
}

bool TElXMLTimestamp_v1_2_2::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLTimestamp_v1_2_2_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLTimestamp_v1_2_2::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLTimestamp_v1_2_2_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLTimestamp_v1_2_2::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLTimestamp_v1_2_2_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLTimestamp_v1_2_2::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLTimestamp_v1_2_2_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLTimestamp_v1_2_2::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLTimestamp_v1_2_2_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
SB_INLINE TElClientTSPInfoHandle TElXMLTimestamp_v1_2_2::GetTimestampInfo()
{
	TElClientTSPInfoHandle OutResult;
	SBCheckError(TElXMLTimestamp_v1_2_2_GetTimestampInfo(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

#ifdef SB_USE_CLASSES_TELCLIENTTSPINFO_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
bool TElXMLTimestamp_v1_2_2::CheckTimestamp(TElClientTSPInfo &Info, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLTimestamp_v1_2_2_CheckTimestamp(_Handle, Info.getHandle(), Manager.getHandle(), Prov.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElXMLTimestamp_v1_2_2::CheckTimestamp(TElClientTSPInfo *Info, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLTimestamp_v1_2_2_CheckTimestamp(_Handle, (Info != NULL) ? Info->getHandle() : SB_NULL_HANDLE, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELCLIENTTSPINFO_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELCUSTOMTSPCLIENT
SB_INLINE int32_t TElXMLTimestamp_v1_2_2::Timestamp(TElCustomTSPClient &TSPClient, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov)
{
	int32_t OutResult;
	SBCheckError(TElXMLTimestamp_v1_2_2_Timestamp(_Handle, TSPClient.getHandle(), Manager.getHandle(), Prov.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLTimestamp_v1_2_2::Timestamp(TElCustomTSPClient *TSPClient, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov)
{
	int32_t OutResult;
	SBCheckError(TElXMLTimestamp_v1_2_2_Timestamp(_Handle, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELCUSTOMTSPCLIENT */

void TElXMLTimestamp_v1_2_2::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLTimestamp_v1_2_2_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1794272793, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLTimestamp_v1_2_2::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLTimestamp_v1_2_2_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1794272793, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLTimestamp_v1_2_2::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLTimestamp_v1_2_2_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLTimestamp_v1_2_2::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLTimestamp_v1_2_2_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLCanonicalizationMethod TElXMLTimestamp_v1_2_2::get_CanonicalizationMethod()
{
	TElXMLCanonicalizationMethodRaw OutResultRaw = 0;
	SBCheckError(TElXMLTimestamp_v1_2_2_get_CanonicalizationMethod(_Handle, &OutResultRaw));
	return (TElXMLCanonicalizationMethod)OutResultRaw;
}

SB_INLINE void TElXMLTimestamp_v1_2_2::set_CanonicalizationMethod(TElXMLCanonicalizationMethod Value)
{
	SBCheckError(TElXMLTimestamp_v1_2_2_set_CanonicalizationMethod(_Handle, (TElXMLCanonicalizationMethodRaw)Value));
}

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA
TElXMLEncapsulatedPKIData* TElXMLTimestamp_v1_2_2::get_EncapsulatedTimestamp()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLTimestamp_v1_2_2_get_EncapsulatedTimestamp(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncapsulatedTimestamp)
		this->_Inst_EncapsulatedTimestamp = new TElXMLEncapsulatedPKIData(hOutResult, ohFalse);
	else
		this->_Inst_EncapsulatedTimestamp->updateHandle(hOutResult);
	return this->_Inst_EncapsulatedTimestamp;
}

SB_INLINE void TElXMLTimestamp_v1_2_2::set_EncapsulatedTimestamp(TElXMLEncapsulatedPKIData &Value)
{
	SBCheckError(TElXMLTimestamp_v1_2_2_set_EncapsulatedTimestamp(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLTimestamp_v1_2_2::set_EncapsulatedTimestamp(TElXMLEncapsulatedPKIData *Value)
{
	SBCheckError(TElXMLTimestamp_v1_2_2_set_EncapsulatedTimestamp(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA */

#ifdef SB_USE_CLASS_TELXMLANYTYPE
TElXMLAnyType* TElXMLTimestamp_v1_2_2::get_XMLTimestamp()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLTimestamp_v1_2_2_get_XMLTimestamp(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_XMLTimestamp)
		this->_Inst_XMLTimestamp = new TElXMLAnyType(hOutResult, ohFalse);
	else
		this->_Inst_XMLTimestamp->updateHandle(hOutResult);
	return this->_Inst_XMLTimestamp;
}

SB_INLINE void TElXMLTimestamp_v1_2_2::set_XMLTimestamp(TElXMLAnyType &Value)
{
	SBCheckError(TElXMLTimestamp_v1_2_2_set_XMLTimestamp(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLTimestamp_v1_2_2::set_XMLTimestamp(TElXMLAnyType *Value)
{
	SBCheckError(TElXMLTimestamp_v1_2_2_set_XMLTimestamp(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLANYTYPE */

#ifdef SB_USE_CLASS_TELXMLINCLUDELIST
TElXMLIncludeList* TElXMLTimestamp_v1_2_2::get_Includes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLTimestamp_v1_2_2_get_Includes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Includes)
		this->_Inst_Includes = new TElXMLIncludeList(hOutResult, ohFalse);
	else
		this->_Inst_Includes->updateHandle(hOutResult);
	return this->_Inst_Includes;
}
#endif /* SB_USE_CLASS_TELXMLINCLUDELIST */

void TElXMLTimestamp_v1_2_2::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA
	this->_Inst_EncapsulatedTimestamp = NULL;
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA */
#ifdef SB_USE_CLASS_TELXMLANYTYPE
	this->_Inst_XMLTimestamp = NULL;
#endif /* SB_USE_CLASS_TELXMLANYTYPE */
#ifdef SB_USE_CLASS_TELXMLINCLUDELIST
	this->_Inst_Includes = NULL;
#endif /* SB_USE_CLASS_TELXMLINCLUDELIST */
}

TElXMLTimestamp_v1_2_2::TElXMLTimestamp_v1_2_2(TElXMLTimestamp_v1_2_2Handle handle, TElOwnHandle ownHandle) : TElXMLCustomTimestamp(handle, ownHandle)
{
	initInstances();
}

TElXMLTimestamp_v1_2_2::TElXMLTimestamp_v1_2_2(TSBXAdESVersion AVersion) : TElXMLCustomTimestamp(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLTimestamp_v1_2_2_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLTimestamp_v1_2_2::TElXMLTimestamp_v1_2_2(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLCustomTimestamp(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLTimestamp_v1_2_2_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLTimestamp_v1_2_2::TElXMLTimestamp_v1_2_2(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLCustomTimestamp(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLTimestamp_v1_2_2_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLTimestamp_v1_2_2::TElXMLTimestamp_v1_2_2(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLCustomTimestamp(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLTimestamp_v1_2_2_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLTimestamp_v1_2_2::TElXMLTimestamp_v1_2_2(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLCustomTimestamp(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLTimestamp_v1_2_2_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLTimestamp_v1_2_2::~TElXMLTimestamp_v1_2_2()
{
#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA
	delete this->_Inst_EncapsulatedTimestamp;
	this->_Inst_EncapsulatedTimestamp = NULL;
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA */
#ifdef SB_USE_CLASS_TELXMLANYTYPE
	delete this->_Inst_XMLTimestamp;
	this->_Inst_XMLTimestamp = NULL;
#endif /* SB_USE_CLASS_TELXMLANYTYPE */
#ifdef SB_USE_CLASS_TELXMLINCLUDELIST
	delete this->_Inst_Includes;
	this->_Inst_Includes = NULL;
#endif /* SB_USE_CLASS_TELXMLINCLUDELIST */
}
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2 */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMPLIST_V1_2_2

#ifdef SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2
SB_INLINE int32_t TElXMLTimestampList_v1_2_2::Add(TElXMLTimestamp_v1_2_2 &ATimestamp)
{
	int32_t OutResult;
	SBCheckError(TElXMLTimestampList_v1_2_2_Add(_Handle, ATimestamp.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLTimestampList_v1_2_2::Add(TElXMLTimestamp_v1_2_2 *ATimestamp)
{
	int32_t OutResult;
	SBCheckError(TElXMLTimestampList_v1_2_2_Add(_Handle, (ATimestamp != NULL) ? ATimestamp->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2 */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2
SB_INLINE void TElXMLTimestampList_v1_2_2::Insert(int32_t Index, TElXMLTimestamp_v1_2_2 &ATimestamp)
{
	SBCheckError(TElXMLTimestampList_v1_2_2_Insert(_Handle, Index, ATimestamp.getHandle()));
}

SB_INLINE void TElXMLTimestampList_v1_2_2::Insert(int32_t Index, TElXMLTimestamp_v1_2_2 *ATimestamp)
{
	SBCheckError(TElXMLTimestampList_v1_2_2_Insert(_Handle, Index, (ATimestamp != NULL) ? ATimestamp->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2 */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2
TElXMLTimestamp_v1_2_2* TElXMLTimestampList_v1_2_2::get_Timestamp_TElXMLTimestamp_v1_2_2(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLTimestampList_v1_2_2_get_Timestamp_TElXMLTimestamp_v1_2_2(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Timestamp)
		this->_Inst_Timestamp = new TElXMLTimestamp_v1_2_2(hOutResult, ohFalse);
	else
		this->_Inst_Timestamp->updateHandle(hOutResult);
	return this->_Inst_Timestamp;
}
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2 */

void TElXMLTimestampList_v1_2_2::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2
	this->_Inst_Timestamp = NULL;
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2 */
}

TElXMLTimestampList_v1_2_2::TElXMLTimestampList_v1_2_2(TElXMLTimestampList_v1_2_2Handle handle, TElOwnHandle ownHandle) : TElXMLCustomTimestampList(handle, ownHandle)
{
	initInstances();
}

TElXMLTimestampList_v1_2_2::TElXMLTimestampList_v1_2_2() : TElXMLCustomTimestampList(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLTimestampList_v1_2_2_Create(&_Handle));
}

TElXMLTimestampList_v1_2_2::~TElXMLTimestampList_v1_2_2()
{
#ifdef SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2
	delete this->_Inst_Timestamp;
	this->_Inst_Timestamp = NULL;
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2 */
}
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPLIST_V1_2_2 */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENTLIST

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE int32_t TElCustomTSPClientList::Add(TElCustomTSPClient &ATSPClient)
{
	int32_t OutResult;
	SBCheckError(TElCustomTSPClientList_Add(_Handle, ATSPClient.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomTSPClientList::Add(TElCustomTSPClient *ATSPClient)
{
	int32_t OutResult;
	SBCheckError(TElCustomTSPClientList_Add(_Handle, (ATSPClient != NULL) ? ATSPClient->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCustomTSPClientList::Insert(int32_t Index, TElCustomTSPClient &ATSPClient)
{
	SBCheckError(TElCustomTSPClientList_Insert(_Handle, Index, ATSPClient.getHandle()));
}

SB_INLINE void TElCustomTSPClientList::Insert(int32_t Index, TElCustomTSPClient *ATSPClient)
{
	SBCheckError(TElCustomTSPClientList_Insert(_Handle, Index, (ATSPClient != NULL) ? ATSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

SB_INLINE void TElCustomTSPClientList::Delete(int32_t Index)
{
	SBCheckError(TElCustomTSPClientList_Delete(_Handle, Index));
}

SB_INLINE void TElCustomTSPClientList::Clear()
{
	SBCheckError(TElCustomTSPClientList_Clear(_Handle));
}

SB_INLINE int32_t TElCustomTSPClientList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElCustomTSPClientList_get_Count(_Handle, &OutResult));
	return OutResult;
}

bool TElCustomTSPClientList::get_OwnItems()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomTSPClientList_get_OwnItems(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
TElCustomTSPClient* TElCustomTSPClientList::get_TSPClients(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomTSPClientList_get_TSPClients(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TSPClients)
		this->_Inst_TSPClients = new TElCustomTSPClient(hOutResult, ohFalse);
	else
		this->_Inst_TSPClients->updateHandle(hOutResult);
	return this->_Inst_TSPClients;
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

void TElCustomTSPClientList::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
	this->_Inst_TSPClients = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */
}

TElCustomTSPClientList::TElCustomTSPClientList(TElCustomTSPClientListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCustomTSPClientList::TElCustomTSPClientList(bool AOwnItems) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomTSPClientList_Create((int8_t)AOwnItems, &_Handle));
}

TElCustomTSPClientList::~TElCustomTSPClientList()
{
#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
	delete this->_Inst_TSPClients;
	this->_Inst_TSPClients = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENTLIST */

#ifdef SB_USE_CLASS_TELXMLGENERICTIMESTAMP

SB_INLINE void TElXMLGenericTimestamp::Clear()
{
	SBCheckError(TElXMLGenericTimestamp_Clear(_Handle));
}

bool TElXMLGenericTimestamp::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLGenericTimestamp_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLGenericTimestamp::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLGenericTimestamp_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLGenericTimestamp::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLGenericTimestamp_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLGenericTimestamp::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLGenericTimestamp_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLGenericTimestamp::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLGenericTimestamp_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
SB_INLINE TElClientTSPInfoHandle TElXMLGenericTimestamp::GetTimestampInfo()
{
	TElClientTSPInfoHandle OutResult;
	SBCheckError(TElXMLGenericTimestamp_GetTimestampInfo(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
SB_INLINE TElClientTSPInfoHandle TElXMLGenericTimestamp::GetTimestampInfo(int32_t Index)
{
	TElClientTSPInfoHandle OutResult;
	SBCheckError(TElXMLGenericTimestamp_GetTimestampInfo_1(_Handle, Index, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

SB_INLINE void TElXMLGenericTimestamp::AddTimestampData(const std::vector<uint8_t> &Data)
{
	SBCheckError(TElXMLGenericTimestamp_AddTimestampData(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size()));
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
SB_INLINE void TElXMLGenericTimestamp::AddTimestampData(const TElXMLDOMNode &Node)
{
	SBCheckError(TElXMLGenericTimestamp_AddTimestampData_1(_Handle, Node.getHandle()));
}

SB_INLINE void TElXMLGenericTimestamp::AddTimestampData(const TElXMLDOMNode *Node)
{
	SBCheckError(TElXMLGenericTimestamp_AddTimestampData_1(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLREFERENCE
SB_INLINE void TElXMLGenericTimestamp::AddTimestampData(const TElXMLReference &Ref)
{
	SBCheckError(TElXMLGenericTimestamp_AddTimestampData_2(_Handle, Ref.getHandle()));
}

SB_INLINE void TElXMLGenericTimestamp::AddTimestampData(const TElXMLReference *Ref)
{
	SBCheckError(TElXMLGenericTimestamp_AddTimestampData_2(_Handle, (Ref != NULL) ? Ref->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLREFERENCE */

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
SB_INLINE void TElXMLGenericTimestamp::StartTimestampCheck(TElClientTSPInfo &Info)
{
	SBCheckError(TElXMLGenericTimestamp_StartTimestampCheck(_Handle, Info.getHandle()));
}

SB_INLINE void TElXMLGenericTimestamp::StartTimestampCheck(TElClientTSPInfo *Info)
{
	SBCheckError(TElXMLGenericTimestamp_StartTimestampCheck(_Handle, (Info != NULL) ? Info->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

bool TElXMLGenericTimestamp::FinishTimestampCheck()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLGenericTimestamp_FinishTimestampCheck(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASSES_TELCLIENTTSPINFO_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
bool TElXMLGenericTimestamp::CheckTimestamp(TElClientTSPInfo &Info, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLGenericTimestamp_CheckTimestamp(_Handle, Info.getHandle(), Manager.getHandle(), Prov.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElXMLGenericTimestamp::CheckTimestamp(TElClientTSPInfo *Info, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLGenericTimestamp_CheckTimestamp(_Handle, (Info != NULL) ? Info->getHandle() : SB_NULL_HANDLE, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELCLIENTTSPINFO_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

SB_INLINE int32_t TElXMLGenericTimestamp::Timestamp()
{
	int32_t OutResult;
	SBCheckError(TElXMLGenericTimestamp_Timestamp(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELCUSTOMTSPCLIENT
SB_INLINE int32_t TElXMLGenericTimestamp::Timestamp(TElCustomTSPClient &TSPClient, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov)
{
	int32_t OutResult;
	SBCheckError(TElXMLGenericTimestamp_Timestamp_1(_Handle, TSPClient.getHandle(), Manager.getHandle(), Prov.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLGenericTimestamp::Timestamp(TElCustomTSPClient *TSPClient, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov)
{
	int32_t OutResult;
	SBCheckError(TElXMLGenericTimestamp_Timestamp_1(_Handle, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELCUSTOMTSPCLIENT */

SB_INLINE int32_t TElXMLGenericTimestamp::get_TimestampInfoCount()
{
	int32_t OutResult;
	SBCheckError(TElXMLGenericTimestamp_get_TimestampInfoCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENTLIST
TElCustomTSPClientList* TElXMLGenericTimestamp::get_TSPClients()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLGenericTimestamp_get_TSPClients(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TSPClients)
		this->_Inst_TSPClients = new TElCustomTSPClientList(hOutResult, ohFalse);
	else
		this->_Inst_TSPClients->updateHandle(hOutResult);
	return this->_Inst_TSPClients;
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENTLIST */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElXMLGenericTimestamp::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLGenericTimestamp_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElXMLGenericTimestamp::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElXMLGenericTimestamp_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLGenericTimestamp::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElXMLGenericTimestamp_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

void TElXMLGenericTimestamp::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLGenericTimestamp_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1089527174, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLGenericTimestamp::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLGenericTimestamp_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1089527174, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLGenericTimestamp::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLGenericTimestamp_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLGenericTimestamp::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLGenericTimestamp_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLCanonicalizationMethod TElXMLGenericTimestamp::get_CanonicalizationMethod()
{
	TElXMLCanonicalizationMethodRaw OutResultRaw = 0;
	SBCheckError(TElXMLGenericTimestamp_get_CanonicalizationMethod(_Handle, &OutResultRaw));
	return (TElXMLCanonicalizationMethod)OutResultRaw;
}

SB_INLINE void TElXMLGenericTimestamp::set_CanonicalizationMethod(TElXMLCanonicalizationMethod Value)
{
	SBCheckError(TElXMLGenericTimestamp_set_CanonicalizationMethod(_Handle, (TElXMLCanonicalizationMethodRaw)Value));
}

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATALIST
TElXMLEncapsulatedPKIDataList* TElXMLGenericTimestamp::get_EncapsulatedTimestamps()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLGenericTimestamp_get_EncapsulatedTimestamps(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncapsulatedTimestamps)
		this->_Inst_EncapsulatedTimestamps = new TElXMLEncapsulatedPKIDataList(hOutResult, ohFalse);
	else
		this->_Inst_EncapsulatedTimestamps->updateHandle(hOutResult);
	return this->_Inst_EncapsulatedTimestamps;
}
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATALIST */

#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
TElXMLAnyTypeList* TElXMLGenericTimestamp::get_XMLTimestamps()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLGenericTimestamp_get_XMLTimestamps(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_XMLTimestamps)
		this->_Inst_XMLTimestamps = new TElXMLAnyTypeList(hOutResult, ohFalse);
	else
		this->_Inst_XMLTimestamps->updateHandle(hOutResult);
	return this->_Inst_XMLTimestamps;
}
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */

#ifdef SB_USE_CLASS_TELXMLINCLUDELIST
TElXMLIncludeList* TElXMLGenericTimestamp::get_Includes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLGenericTimestamp_get_Includes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Includes)
		this->_Inst_Includes = new TElXMLIncludeList(hOutResult, ohFalse);
	else
		this->_Inst_Includes->updateHandle(hOutResult);
	return this->_Inst_Includes;
}
#endif /* SB_USE_CLASS_TELXMLINCLUDELIST */

void TElXMLGenericTimestamp::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENTLIST
	this->_Inst_TSPClients = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENTLIST */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATALIST
	this->_Inst_EncapsulatedTimestamps = NULL;
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATALIST */
#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
	this->_Inst_XMLTimestamps = NULL;
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */
#ifdef SB_USE_CLASS_TELXMLINCLUDELIST
	this->_Inst_Includes = NULL;
#endif /* SB_USE_CLASS_TELXMLINCLUDELIST */
}

TElXMLGenericTimestamp::TElXMLGenericTimestamp(TElXMLGenericTimestampHandle handle, TElOwnHandle ownHandle) : TElXMLCustomTimestamp(handle, ownHandle)
{
	initInstances();
}

TElXMLGenericTimestamp::TElXMLGenericTimestamp(TSBXAdESVersion AVersion) : TElXMLCustomTimestamp(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLGenericTimestamp_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLGenericTimestamp::TElXMLGenericTimestamp(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLCustomTimestamp(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLGenericTimestamp_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLGenericTimestamp::TElXMLGenericTimestamp(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLCustomTimestamp(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLGenericTimestamp_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLGenericTimestamp::TElXMLGenericTimestamp(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLCustomTimestamp(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLGenericTimestamp_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLGenericTimestamp::TElXMLGenericTimestamp(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLCustomTimestamp(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLGenericTimestamp_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLGenericTimestamp::~TElXMLGenericTimestamp()
{
#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENTLIST
	delete this->_Inst_TSPClients;
	this->_Inst_TSPClients = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENTLIST */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATALIST
	delete this->_Inst_EncapsulatedTimestamps;
	this->_Inst_EncapsulatedTimestamps = NULL;
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATALIST */
#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
	delete this->_Inst_XMLTimestamps;
	this->_Inst_XMLTimestamps = NULL;
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */
#ifdef SB_USE_CLASS_TELXMLINCLUDELIST
	delete this->_Inst_Includes;
	this->_Inst_Includes = NULL;
#endif /* SB_USE_CLASS_TELXMLINCLUDELIST */
}
#endif /* SB_USE_CLASS_TELXMLGENERICTIMESTAMP */

#ifdef SB_USE_CLASS_TELXMLGENERICTIMESTAMPLIST

#ifdef SB_USE_CLASS_TELXMLGENERICTIMESTAMP
SB_INLINE int32_t TElXMLGenericTimestampList::Add(TElXMLGenericTimestamp &ATimestamp)
{
	int32_t OutResult;
	SBCheckError(TElXMLGenericTimestampList_Add(_Handle, ATimestamp.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLGenericTimestampList::Add(TElXMLGenericTimestamp *ATimestamp)
{
	int32_t OutResult;
	SBCheckError(TElXMLGenericTimestampList_Add(_Handle, (ATimestamp != NULL) ? ATimestamp->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLGENERICTIMESTAMP */

#ifdef SB_USE_CLASS_TELXMLGENERICTIMESTAMP
SB_INLINE void TElXMLGenericTimestampList::Insert(int32_t Index, TElXMLGenericTimestamp &ATimestamp)
{
	SBCheckError(TElXMLGenericTimestampList_Insert(_Handle, Index, ATimestamp.getHandle()));
}

SB_INLINE void TElXMLGenericTimestampList::Insert(int32_t Index, TElXMLGenericTimestamp *ATimestamp)
{
	SBCheckError(TElXMLGenericTimestampList_Insert(_Handle, Index, (ATimestamp != NULL) ? ATimestamp->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLGENERICTIMESTAMP */

#ifdef SB_USE_CLASS_TELXMLGENERICTIMESTAMP
TElXMLGenericTimestamp* TElXMLGenericTimestampList::get_Timestamp_TElXMLGenericTimestamp(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLGenericTimestampList_get_Timestamp_TElXMLGenericTimestamp(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Timestamp)
		this->_Inst_Timestamp = new TElXMLGenericTimestamp(hOutResult, ohFalse);
	else
		this->_Inst_Timestamp->updateHandle(hOutResult);
	return this->_Inst_Timestamp;
}
#endif /* SB_USE_CLASS_TELXMLGENERICTIMESTAMP */

void TElXMLGenericTimestampList::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLGENERICTIMESTAMP
	this->_Inst_Timestamp = NULL;
#endif /* SB_USE_CLASS_TELXMLGENERICTIMESTAMP */
}

TElXMLGenericTimestampList::TElXMLGenericTimestampList(TElXMLGenericTimestampListHandle handle, TElOwnHandle ownHandle) : TElXMLCustomTimestampList(handle, ownHandle)
{
	initInstances();
}

TElXMLGenericTimestampList::TElXMLGenericTimestampList() : TElXMLCustomTimestampList(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLGenericTimestampList_Create(&_Handle));
}

TElXMLGenericTimestampList::~TElXMLGenericTimestampList()
{
#ifdef SB_USE_CLASS_TELXMLGENERICTIMESTAMP
	delete this->_Inst_Timestamp;
	this->_Inst_Timestamp = NULL;
#endif /* SB_USE_CLASS_TELXMLGENERICTIMESTAMP */
}
#endif /* SB_USE_CLASS_TELXMLGENERICTIMESTAMPLIST */

#ifdef SB_USE_CLASS_TELXMLDIGESTALGANDVALUE

SB_INLINE void TElXMLDigestAlgAndValue::Assign(TElXMLAdESElement &Source)
{
	SBCheckError(TElXMLDigestAlgAndValue_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElXMLDigestAlgAndValue::Assign(TElXMLAdESElement *Source)
{
	SBCheckError(TElXMLDigestAlgAndValue_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElXMLDigestAlgAndValue::Clear()
{
	SBCheckError(TElXMLDigestAlgAndValue_Clear(_Handle));
}

bool TElXMLDigestAlgAndValue::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLDigestAlgAndValue_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLDigestAlgAndValue::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLDigestAlgAndValue_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLDigestAlgAndValue::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLDigestAlgAndValue_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLDigestAlgAndValue::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLDigestAlgAndValue_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLDigestAlgAndValue::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLDigestAlgAndValue_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLDigestAlgAndValue::get_DigestMethod(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDigestAlgAndValue_get_DigestMethod(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1020954402, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDigestAlgAndValue::get_DigestMethod(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDigestAlgAndValue_get_DigestMethod(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1020954402, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLDigestAlgAndValue::set_DigestMethod(const sb_u16string &Value)
{
	SBCheckError(TElXMLDigestAlgAndValue_set_DigestMethod(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLDigestAlgAndValue::set_DigestMethod(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLDigestAlgAndValue_set_DigestMethod(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLDigestAlgAndValue::get_DigestValue(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLDigestAlgAndValue_get_DigestValue(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1287501134, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElXMLDigestAlgAndValue::set_DigestValue(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElXMLDigestAlgAndValue_set_DigestValue(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElXMLDigestAlgAndValue::TElXMLDigestAlgAndValue(TElXMLDigestAlgAndValueHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
}

TElXMLDigestAlgAndValue::TElXMLDigestAlgAndValue(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLDigestAlgAndValue_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLDigestAlgAndValue::TElXMLDigestAlgAndValue(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLDigestAlgAndValue_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLDigestAlgAndValue::TElXMLDigestAlgAndValue(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLDigestAlgAndValue_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLDigestAlgAndValue::TElXMLDigestAlgAndValue(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLDigestAlgAndValue_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLDigestAlgAndValue::TElXMLDigestAlgAndValue(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLDigestAlgAndValue_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDIGESTALGANDVALUE */

#ifdef SB_USE_CLASS_TELXMLCERTID

SB_INLINE void TElXMLCertID::Clear()
{
	SBCheckError(TElXMLCertID_Clear(_Handle));
}

bool TElXMLCertID::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLCertID_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLCertID::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLCertID_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLCertID::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLCertID_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLCertID::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCertID_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLCertID::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCertID_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
bool TElXMLCertID::IsMatch(TElX509Certificate &Cert)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLCertID_IsMatch(_Handle, Cert.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElXMLCertID::IsMatch(TElX509Certificate *Cert)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLCertID_IsMatch(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
bool TElXMLCertID::IsMatch(TElX509Certificate &Cert, bool LiberalMode)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLCertID_IsMatch_1(_Handle, Cert.getHandle(), (int8_t)LiberalMode, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElXMLCertID::IsMatch(TElX509Certificate *Cert, bool LiberalMode)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLCertID_IsMatch_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (int8_t)LiberalMode, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELXMLDIGESTALGANDVALUE
TElXMLDigestAlgAndValue* TElXMLCertID::get_CertDigest()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCertID_get_CertDigest(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertDigest)
		this->_Inst_CertDigest = new TElXMLDigestAlgAndValue(hOutResult, ohFalse);
	else
		this->_Inst_CertDigest->updateHandle(hOutResult);
	return this->_Inst_CertDigest;
}

SB_INLINE void TElXMLCertID::set_CertDigest(TElXMLDigestAlgAndValue &Value)
{
	SBCheckError(TElXMLCertID_set_CertDigest(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLCertID::set_CertDigest(TElXMLDigestAlgAndValue *Value)
{
	SBCheckError(TElXMLCertID_set_CertDigest(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDIGESTALGANDVALUE */

#ifdef SB_USE_CLASS_TELXMLISSUERSERIAL
TElXMLIssuerSerial* TElXMLCertID::get_IssuerSerial()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCertID_get_IssuerSerial(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IssuerSerial)
		this->_Inst_IssuerSerial = new TElXMLIssuerSerial(hOutResult, ohFalse);
	else
		this->_Inst_IssuerSerial->updateHandle(hOutResult);
	return this->_Inst_IssuerSerial;
}

SB_INLINE void TElXMLCertID::set_IssuerSerial(TElXMLIssuerSerial &Value)
{
	SBCheckError(TElXMLCertID_set_IssuerSerial(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLCertID::set_IssuerSerial(TElXMLIssuerSerial *Value)
{
	SBCheckError(TElXMLCertID_set_IssuerSerial(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLISSUERSERIAL */

void TElXMLCertID::get_URI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLCertID_get_URI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-894692377, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLCertID::get_URI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLCertID_get_URI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-894692377, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLCertID::set_URI(const sb_u16string &Value)
{
	SBCheckError(TElXMLCertID_set_URI(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLCertID::set_URI(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLCertID_set_URI(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLCertID::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDIGESTALGANDVALUE
	this->_Inst_CertDigest = NULL;
#endif /* SB_USE_CLASS_TELXMLDIGESTALGANDVALUE */
#ifdef SB_USE_CLASS_TELXMLISSUERSERIAL
	this->_Inst_IssuerSerial = NULL;
#endif /* SB_USE_CLASS_TELXMLISSUERSERIAL */
}

TElXMLCertID::TElXMLCertID(TElXMLCertIDHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLCertID::TElXMLCertID(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCertID_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLCertID::TElXMLCertID(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCertID_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLCertID::TElXMLCertID(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLCertID_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLCertID::TElXMLCertID(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCertID_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLCertID::TElXMLCertID(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLCertID_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLCertID::~TElXMLCertID()
{
#ifdef SB_USE_CLASS_TELXMLDIGESTALGANDVALUE
	delete this->_Inst_CertDigest;
	this->_Inst_CertDigest = NULL;
#endif /* SB_USE_CLASS_TELXMLDIGESTALGANDVALUE */
#ifdef SB_USE_CLASS_TELXMLISSUERSERIAL
	delete this->_Inst_IssuerSerial;
	this->_Inst_IssuerSerial = NULL;
#endif /* SB_USE_CLASS_TELXMLISSUERSERIAL */
}
#endif /* SB_USE_CLASS_TELXMLCERTID */

#ifdef SB_USE_CLASS_TELXMLCERTIDLIST

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE int32_t TElXMLCertIDList::HasCertificate(TElX509Certificate &ACertificate)
{
	int32_t OutResult;
	SBCheckError(TElXMLCertIDList_HasCertificate(_Handle, ACertificate.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLCertIDList::HasCertificate(TElX509Certificate *ACertificate)
{
	int32_t OutResult;
	SBCheckError(TElXMLCertIDList_HasCertificate(_Handle, (ACertificate != NULL) ? ACertificate->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE int32_t TElXMLCertIDList::AddCertificate(TElX509Certificate &ACertificate, TSBXAdESVersion AXAdESVersion)
{
	int32_t OutResult;
	SBCheckError(TElXMLCertIDList_AddCertificate(_Handle, ACertificate.getHandle(), (TSBXAdESVersionRaw)AXAdESVersion, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLCertIDList::AddCertificate(TElX509Certificate *ACertificate, TSBXAdESVersion AXAdESVersion)
{
	int32_t OutResult;
	SBCheckError(TElXMLCertIDList_AddCertificate(_Handle, (ACertificate != NULL) ? ACertificate->getHandle() : SB_NULL_HANDLE, (TSBXAdESVersionRaw)AXAdESVersion, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE int32_t TElXMLCertIDList::AddCertificate(TElX509Certificate &ACertificate, TElXMLDigestMethod DigestMethod, TSBXAdESVersion AXAdESVersion)
{
	int32_t OutResult;
	SBCheckError(TElXMLCertIDList_AddCertificate_1(_Handle, ACertificate.getHandle(), (TElXMLDigestMethodRaw)DigestMethod, (TSBXAdESVersionRaw)AXAdESVersion, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLCertIDList::AddCertificate(TElX509Certificate *ACertificate, TElXMLDigestMethod DigestMethod, TSBXAdESVersion AXAdESVersion)
{
	int32_t OutResult;
	SBCheckError(TElXMLCertIDList_AddCertificate_1(_Handle, (ACertificate != NULL) ? ACertificate->getHandle() : SB_NULL_HANDLE, (TElXMLDigestMethodRaw)DigestMethod, (TSBXAdESVersionRaw)AXAdESVersion, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE int32_t TElXMLCertIDList::AddCertificate(TElX509Certificate &ACertificate, TElXMLDigestMethod DigestMethod, bool HexSerialNumber, TSBXAdESVersion AXAdESVersion)
{
	int32_t OutResult;
	SBCheckError(TElXMLCertIDList_AddCertificate_2(_Handle, ACertificate.getHandle(), (TElXMLDigestMethodRaw)DigestMethod, (int8_t)HexSerialNumber, (TSBXAdESVersionRaw)AXAdESVersion, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLCertIDList::AddCertificate(TElX509Certificate *ACertificate, TElXMLDigestMethod DigestMethod, bool HexSerialNumber, TSBXAdESVersion AXAdESVersion)
{
	int32_t OutResult;
	SBCheckError(TElXMLCertIDList_AddCertificate_2(_Handle, (ACertificate != NULL) ? ACertificate->getHandle() : SB_NULL_HANDLE, (TElXMLDigestMethodRaw)DigestMethod, (int8_t)HexSerialNumber, (TSBXAdESVersionRaw)AXAdESVersion, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELXMLCERTID
SB_INLINE int32_t TElXMLCertIDList::Add(TElXMLCertID &ACertID)
{
	int32_t OutResult;
	SBCheckError(TElXMLCertIDList_Add(_Handle, ACertID.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLCertIDList::Add(TElXMLCertID *ACertID)
{
	int32_t OutResult;
	SBCheckError(TElXMLCertIDList_Add(_Handle, (ACertID != NULL) ? ACertID->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLCERTID */

#ifdef SB_USE_CLASS_TELXMLCERTID
SB_INLINE void TElXMLCertIDList::Insert(int32_t Index, TElXMLCertID &ACertID)
{
	SBCheckError(TElXMLCertIDList_Insert(_Handle, Index, ACertID.getHandle()));
}

SB_INLINE void TElXMLCertIDList::Insert(int32_t Index, TElXMLCertID *ACertID)
{
	SBCheckError(TElXMLCertIDList_Insert(_Handle, Index, (ACertID != NULL) ? ACertID->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLCERTID */

SB_INLINE void TElXMLCertIDList::Delete(int32_t Index)
{
	SBCheckError(TElXMLCertIDList_Delete(_Handle, Index));
}

SB_INLINE void TElXMLCertIDList::Clear()
{
	SBCheckError(TElXMLCertIDList_Clear(_Handle));
}

SB_INLINE int32_t TElXMLCertIDList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLCertIDList_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLCERTID
TElXMLCertID* TElXMLCertIDList::get_CertIDs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCertIDList_get_CertIDs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertIDs)
		this->_Inst_CertIDs = new TElXMLCertID(hOutResult, ohFalse);
	else
		this->_Inst_CertIDs->updateHandle(hOutResult);
	return this->_Inst_CertIDs;
}
#endif /* SB_USE_CLASS_TELXMLCERTID */

void TElXMLCertIDList::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLCERTID
	this->_Inst_CertIDs = NULL;
#endif /* SB_USE_CLASS_TELXMLCERTID */
}

TElXMLCertIDList::TElXMLCertIDList(TElXMLCertIDListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElXMLCertIDList::TElXMLCertIDList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCertIDList_Create(&_Handle));
}

TElXMLCertIDList::~TElXMLCertIDList()
{
#ifdef SB_USE_CLASS_TELXMLCERTID
	delete this->_Inst_CertIDs;
	this->_Inst_CertIDs = NULL;
#endif /* SB_USE_CLASS_TELXMLCERTID */
}
#endif /* SB_USE_CLASS_TELXMLCERTIDLIST */

#ifdef SB_USE_CLASS_TELXMLNOTICEREFERENCE

SB_INLINE void TElXMLNoticeReference::Clear()
{
	SBCheckError(TElXMLNoticeReference_Clear(_Handle));
}

bool TElXMLNoticeReference::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLNoticeReference_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLNoticeReference::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLNoticeReference_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLNoticeReference::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLNoticeReference_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLNoticeReference::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLNoticeReference_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLNoticeReference::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLNoticeReference_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLNoticeReference::get_Organization(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLNoticeReference_get_Organization(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(733670047, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLNoticeReference::get_Organization(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLNoticeReference_get_Organization(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(733670047, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLNoticeReference::set_Organization(const sb_u16string &Value)
{
	SBCheckError(TElXMLNoticeReference_set_Organization(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLNoticeReference::set_Organization(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLNoticeReference_set_Organization(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLNoticeReference::get_NoticeNumbers(std::vector<int32_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size() * 4;
	uint32_t _err = TElXMLNoticeReference_get_NoticeNumbers(_Handle, (int32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult / 4);
		SBCheckError(SBGetLastReturnBuffer(-235971907, 1, (int32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult / 4);
}

SB_INLINE void TElXMLNoticeReference::set_NoticeNumbers(const std::vector<int32_t> &Value)
{
	SBCheckError(TElXMLNoticeReference_set_NoticeNumbers(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElXMLNoticeReference::TElXMLNoticeReference(TElXMLNoticeReferenceHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
}

TElXMLNoticeReference::TElXMLNoticeReference(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLNoticeReference_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLNoticeReference::TElXMLNoticeReference(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLNoticeReference_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLNoticeReference::TElXMLNoticeReference(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLNoticeReference_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLNoticeReference::TElXMLNoticeReference(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLNoticeReference_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLNoticeReference::TElXMLNoticeReference(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLNoticeReference_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLNOTICEREFERENCE */

#ifdef SB_USE_CLASS_TELXMLSPUSERNOTICE

SB_INLINE void TElXMLSPUserNotice::Clear()
{
	SBCheckError(TElXMLSPUserNotice_Clear(_Handle));
}

bool TElXMLSPUserNotice::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLSPUserNotice_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSPUserNotice::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSPUserNotice_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSPUserNotice::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSPUserNotice_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLSPUserNotice::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSPUserNotice_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLSPUserNotice::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSPUserNotice_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLNOTICEREFERENCE
TElXMLNoticeReference* TElXMLSPUserNotice::get_NoticeRef()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSPUserNotice_get_NoticeRef(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NoticeRef)
		this->_Inst_NoticeRef = new TElXMLNoticeReference(hOutResult, ohFalse);
	else
		this->_Inst_NoticeRef->updateHandle(hOutResult);
	return this->_Inst_NoticeRef;
}

SB_INLINE void TElXMLSPUserNotice::set_NoticeRef(TElXMLNoticeReference &Value)
{
	SBCheckError(TElXMLSPUserNotice_set_NoticeRef(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLSPUserNotice::set_NoticeRef(TElXMLNoticeReference *Value)
{
	SBCheckError(TElXMLSPUserNotice_set_NoticeRef(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLNOTICEREFERENCE */

void TElXMLSPUserNotice::get_ExplicitTex(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSPUserNotice_get_ExplicitTex(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-805293162, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSPUserNotice::get_ExplicitTex(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSPUserNotice_get_ExplicitTex(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-805293162, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSPUserNotice::set_ExplicitTex(const sb_u16string &Value)
{
	SBCheckError(TElXMLSPUserNotice_set_ExplicitTex(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSPUserNotice::set_ExplicitTex(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSPUserNotice_set_ExplicitTex(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSPUserNotice::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLNOTICEREFERENCE
	this->_Inst_NoticeRef = NULL;
#endif /* SB_USE_CLASS_TELXMLNOTICEREFERENCE */
}

TElXMLSPUserNotice::TElXMLSPUserNotice(TElXMLSPUserNoticeHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLSPUserNotice::TElXMLSPUserNotice(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSPUserNotice_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLSPUserNotice::TElXMLSPUserNotice(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSPUserNotice_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSPUserNotice::TElXMLSPUserNotice(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSPUserNotice_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLSPUserNotice::TElXMLSPUserNotice(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSPUserNotice_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSPUserNotice::TElXMLSPUserNotice(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSPUserNotice_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLSPUserNotice::~TElXMLSPUserNotice()
{
#ifdef SB_USE_CLASS_TELXMLNOTICEREFERENCE
	delete this->_Inst_NoticeRef;
	this->_Inst_NoticeRef = NULL;
#endif /* SB_USE_CLASS_TELXMLNOTICEREFERENCE */
}
#endif /* SB_USE_CLASS_TELXMLSPUSERNOTICE */

#ifdef SB_USE_CLASS_TELXMLSPURI

SB_INLINE void TElXMLSPURI::Clear()
{
	SBCheckError(TElXMLSPURI_Clear(_Handle));
}

bool TElXMLSPURI::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLSPURI_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSPURI::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSPURI_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSPURI::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSPURI_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLSPURI::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSPURI_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLSPURI::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSPURI_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLSPURI::get_URI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSPURI_get_URI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-54001001, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSPURI::get_URI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSPURI_get_URI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-54001001, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSPURI::set_URI(const sb_u16string &Value)
{
	SBCheckError(TElXMLSPURI_set_URI(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSPURI::set_URI(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSPURI_set_URI(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLSPURI::TElXMLSPURI(TElXMLSPURIHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
}

TElXMLSPURI::TElXMLSPURI(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSPURI_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLSPURI::TElXMLSPURI(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSPURI_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSPURI::TElXMLSPURI(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSPURI_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLSPURI::TElXMLSPURI(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSPURI_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSPURI::TElXMLSPURI(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSPURI_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLSPURI */

#ifdef SB_USE_CLASS_TELXMLSIGPOLICYQUALIFIER

TElXMLSigPolicyQualifier::TElXMLSigPolicyQualifier(TElXMLSigPolicyQualifierHandle handle, TElOwnHandle ownHandle) : TElXMLAnyType(handle, ownHandle)
{
}

TElXMLSigPolicyQualifier::TElXMLSigPolicyQualifier(TSBXAdESVersion AVersion) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSigPolicyQualifier_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLSigPolicyQualifier::TElXMLSigPolicyQualifier(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSigPolicyQualifier_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSigPolicyQualifier::TElXMLSigPolicyQualifier(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSigPolicyQualifier_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLSigPolicyQualifier::TElXMLSigPolicyQualifier(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSigPolicyQualifier_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSigPolicyQualifier::TElXMLSigPolicyQualifier(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSigPolicyQualifier_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLSIGPOLICYQUALIFIER */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYID

SB_INLINE void TElXMLSignaturePolicyId::Assign(TElXMLAdESElement &Source)
{
	SBCheckError(TElXMLSignaturePolicyId_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElXMLSignaturePolicyId::Assign(TElXMLAdESElement *Source)
{
	SBCheckError(TElXMLSignaturePolicyId_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElXMLSignaturePolicyId::Clear()
{
	SBCheckError(TElXMLSignaturePolicyId_Clear(_Handle));
}

bool TElXMLSignaturePolicyId::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLSignaturePolicyId_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSignaturePolicyId::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSignaturePolicyId_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSignaturePolicyId::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSignaturePolicyId_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLSignaturePolicyId::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSignaturePolicyId_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLSignaturePolicyId::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSignaturePolicyId_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLOBJECTIDENTIFIER
TElXMLObjectIdentifier* TElXMLSignaturePolicyId::get_SigPolicyId()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignaturePolicyId_get_SigPolicyId(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SigPolicyId)
		this->_Inst_SigPolicyId = new TElXMLObjectIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_SigPolicyId->updateHandle(hOutResult);
	return this->_Inst_SigPolicyId;
}
#endif /* SB_USE_CLASS_TELXMLOBJECTIDENTIFIER */

#ifdef SB_USE_CLASS_TELXMLDIGESTALGANDVALUE
TElXMLDigestAlgAndValue* TElXMLSignaturePolicyId::get_SigPolicyHash()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignaturePolicyId_get_SigPolicyHash(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SigPolicyHash)
		this->_Inst_SigPolicyHash = new TElXMLDigestAlgAndValue(hOutResult, ohFalse);
	else
		this->_Inst_SigPolicyHash->updateHandle(hOutResult);
	return this->_Inst_SigPolicyHash;
}
#endif /* SB_USE_CLASS_TELXMLDIGESTALGANDVALUE */

#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
TElXMLAnyTypeList* TElXMLSignaturePolicyId::get_SigPolicyQualifiers()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignaturePolicyId_get_SigPolicyQualifiers(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SigPolicyQualifiers)
		this->_Inst_SigPolicyQualifiers = new TElXMLAnyTypeList(hOutResult, ohFalse);
	else
		this->_Inst_SigPolicyQualifiers->updateHandle(hOutResult);
	return this->_Inst_SigPolicyQualifiers;
}
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */

#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
TElXMLTransformChain* TElXMLSignaturePolicyId::get_TransformChain()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignaturePolicyId_get_TransformChain(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TransformChain)
		this->_Inst_TransformChain = new TElXMLTransformChain(hOutResult, ohFalse);
	else
		this->_Inst_TransformChain->updateHandle(hOutResult);
	return this->_Inst_TransformChain;
}
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */

void TElXMLSignaturePolicyId::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLOBJECTIDENTIFIER
	this->_Inst_SigPolicyId = NULL;
#endif /* SB_USE_CLASS_TELXMLOBJECTIDENTIFIER */
#ifdef SB_USE_CLASS_TELXMLDIGESTALGANDVALUE
	this->_Inst_SigPolicyHash = NULL;
#endif /* SB_USE_CLASS_TELXMLDIGESTALGANDVALUE */
#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
	this->_Inst_SigPolicyQualifiers = NULL;
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */
#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
	this->_Inst_TransformChain = NULL;
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */
}

TElXMLSignaturePolicyId::TElXMLSignaturePolicyId(TElXMLSignaturePolicyIdHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLSignaturePolicyId::TElXMLSignaturePolicyId(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSignaturePolicyId_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLSignaturePolicyId::TElXMLSignaturePolicyId(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSignaturePolicyId_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSignaturePolicyId::TElXMLSignaturePolicyId(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSignaturePolicyId_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLSignaturePolicyId::TElXMLSignaturePolicyId(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSignaturePolicyId_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSignaturePolicyId::TElXMLSignaturePolicyId(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSignaturePolicyId_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLSignaturePolicyId::~TElXMLSignaturePolicyId()
{
#ifdef SB_USE_CLASS_TELXMLOBJECTIDENTIFIER
	delete this->_Inst_SigPolicyId;
	this->_Inst_SigPolicyId = NULL;
#endif /* SB_USE_CLASS_TELXMLOBJECTIDENTIFIER */
#ifdef SB_USE_CLASS_TELXMLDIGESTALGANDVALUE
	delete this->_Inst_SigPolicyHash;
	this->_Inst_SigPolicyHash = NULL;
#endif /* SB_USE_CLASS_TELXMLDIGESTALGANDVALUE */
#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
	delete this->_Inst_SigPolicyQualifiers;
	this->_Inst_SigPolicyQualifiers = NULL;
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */
#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
	delete this->_Inst_TransformChain;
	this->_Inst_TransformChain = NULL;
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */
}
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYID */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYIDENTIFIER

SB_INLINE void TElXMLSignaturePolicyIdentifier::Assign(TElXMLAdESElement &Source)
{
	SBCheckError(TElXMLSignaturePolicyIdentifier_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElXMLSignaturePolicyIdentifier::Assign(TElXMLAdESElement *Source)
{
	SBCheckError(TElXMLSignaturePolicyIdentifier_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElXMLSignaturePolicyIdentifier::Clear()
{
	SBCheckError(TElXMLSignaturePolicyIdentifier_Clear(_Handle));
}

bool TElXMLSignaturePolicyIdentifier::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLSignaturePolicyIdentifier_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSignaturePolicyIdentifier::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSignaturePolicyIdentifier_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSignaturePolicyIdentifier::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSignaturePolicyIdentifier_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLSignaturePolicyIdentifier::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSignaturePolicyIdentifier_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLSignaturePolicyIdentifier::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSignaturePolicyIdentifier_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYID
TElXMLSignaturePolicyId* TElXMLSignaturePolicyIdentifier::get_SignaturePolicyId()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignaturePolicyIdentifier_get_SignaturePolicyId(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignaturePolicyId)
		this->_Inst_SignaturePolicyId = new TElXMLSignaturePolicyId(hOutResult, ohFalse);
	else
		this->_Inst_SignaturePolicyId->updateHandle(hOutResult);
	return this->_Inst_SignaturePolicyId;
}

SB_INLINE void TElXMLSignaturePolicyIdentifier::set_SignaturePolicyId(TElXMLSignaturePolicyId &Value)
{
	SBCheckError(TElXMLSignaturePolicyIdentifier_set_SignaturePolicyId(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLSignaturePolicyIdentifier::set_SignaturePolicyId(TElXMLSignaturePolicyId *Value)
{
	SBCheckError(TElXMLSignaturePolicyIdentifier_set_SignaturePolicyId(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYID */

bool TElXMLSignaturePolicyIdentifier::get_SignaturePolicyImplied()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLSignaturePolicyIdentifier_get_SignaturePolicyImplied(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLSignaturePolicyIdentifier::set_SignaturePolicyImplied(bool Value)
{
	SBCheckError(TElXMLSignaturePolicyIdentifier_set_SignaturePolicyImplied(_Handle, (int8_t)Value));
}

void TElXMLSignaturePolicyIdentifier::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYID
	this->_Inst_SignaturePolicyId = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYID */
}

TElXMLSignaturePolicyIdentifier::TElXMLSignaturePolicyIdentifier(TElXMLSignaturePolicyIdentifierHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLSignaturePolicyIdentifier::TElXMLSignaturePolicyIdentifier(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSignaturePolicyIdentifier_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLSignaturePolicyIdentifier::TElXMLSignaturePolicyIdentifier(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSignaturePolicyIdentifier_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSignaturePolicyIdentifier::TElXMLSignaturePolicyIdentifier(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSignaturePolicyIdentifier_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLSignaturePolicyIdentifier::TElXMLSignaturePolicyIdentifier(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSignaturePolicyIdentifier_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSignaturePolicyIdentifier::TElXMLSignaturePolicyIdentifier(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSignaturePolicyIdentifier_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLSignaturePolicyIdentifier::~TElXMLSignaturePolicyIdentifier()
{
#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYID
	delete this->_Inst_SignaturePolicyId;
	this->_Inst_SignaturePolicyId = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYID */
}
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYIDENTIFIER */

#ifdef SB_USE_CLASS_TELXMLCOUNTERSIGNATURE

SB_INLINE void TElXMLCounterSignature::Clear()
{
	SBCheckError(TElXMLCounterSignature_Clear(_Handle));
}

bool TElXMLCounterSignature::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLCounterSignature_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLCounterSignature::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLCounterSignature_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLCounterSignature::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLCounterSignature_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLCounterSignature::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCounterSignature_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLCounterSignature::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCounterSignature_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLDOMElement* TElXMLCounterSignature::get_Signature()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCounterSignature_get_Signature(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signature)
		this->_Inst_Signature = new TElXMLDOMElement(hOutResult, ohFalse);
	else
		this->_Inst_Signature->updateHandle(hOutResult);
	return this->_Inst_Signature;
}

SB_INLINE void TElXMLCounterSignature::set_Signature(TElXMLDOMElement &Value)
{
	SBCheckError(TElXMLCounterSignature_set_Signature(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLCounterSignature::set_Signature(TElXMLDOMElement *Value)
{
	SBCheckError(TElXMLCounterSignature_set_Signature(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

void TElXMLCounterSignature::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
}

TElXMLCounterSignature::TElXMLCounterSignature(TElXMLCounterSignatureHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLCounterSignature::TElXMLCounterSignature(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCounterSignature_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLCounterSignature::TElXMLCounterSignature(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCounterSignature_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLCounterSignature::TElXMLCounterSignature(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLCounterSignature_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLCounterSignature::TElXMLCounterSignature(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCounterSignature_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLCounterSignature::TElXMLCounterSignature(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLCounterSignature_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLCounterSignature::~TElXMLCounterSignature()
{
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	delete this->_Inst_Signature;
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
}
#endif /* SB_USE_CLASS_TELXMLCOUNTERSIGNATURE */

#ifdef SB_USE_CLASS_TELXMLCOUNTERSIGNATURELIST

#ifdef SB_USE_CLASS_TELXMLCOUNTERSIGNATURE
SB_INLINE int32_t TElXMLCounterSignatureList::Add(TElXMLCounterSignature &ACounterSignature)
{
	int32_t OutResult;
	SBCheckError(TElXMLCounterSignatureList_Add(_Handle, ACounterSignature.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLCounterSignatureList::Add(TElXMLCounterSignature *ACounterSignature)
{
	int32_t OutResult;
	SBCheckError(TElXMLCounterSignatureList_Add(_Handle, (ACounterSignature != NULL) ? ACounterSignature->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLCOUNTERSIGNATURE */

#ifdef SB_USE_CLASS_TELXMLCOUNTERSIGNATURE
SB_INLINE void TElXMLCounterSignatureList::Insert(int32_t Index, TElXMLCounterSignature &ACounterSignature)
{
	SBCheckError(TElXMLCounterSignatureList_Insert(_Handle, Index, ACounterSignature.getHandle()));
}

SB_INLINE void TElXMLCounterSignatureList::Insert(int32_t Index, TElXMLCounterSignature *ACounterSignature)
{
	SBCheckError(TElXMLCounterSignatureList_Insert(_Handle, Index, (ACounterSignature != NULL) ? ACounterSignature->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLCOUNTERSIGNATURE */

SB_INLINE void TElXMLCounterSignatureList::Delete(int32_t Index)
{
	SBCheckError(TElXMLCounterSignatureList_Delete(_Handle, Index));
}

SB_INLINE void TElXMLCounterSignatureList::Clear()
{
	SBCheckError(TElXMLCounterSignatureList_Clear(_Handle));
}

SB_INLINE int32_t TElXMLCounterSignatureList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLCounterSignatureList_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLCOUNTERSIGNATURE
TElXMLCounterSignature* TElXMLCounterSignatureList::get_CounterSignature(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCounterSignatureList_get_CounterSignature(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CounterSignature)
		this->_Inst_CounterSignature = new TElXMLCounterSignature(hOutResult, ohFalse);
	else
		this->_Inst_CounterSignature->updateHandle(hOutResult);
	return this->_Inst_CounterSignature;
}
#endif /* SB_USE_CLASS_TELXMLCOUNTERSIGNATURE */

void TElXMLCounterSignatureList::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLCOUNTERSIGNATURE
	this->_Inst_CounterSignature = NULL;
#endif /* SB_USE_CLASS_TELXMLCOUNTERSIGNATURE */
}

TElXMLCounterSignatureList::TElXMLCounterSignatureList(TElXMLCounterSignatureListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElXMLCounterSignatureList::TElXMLCounterSignatureList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCounterSignatureList_Create(&_Handle));
}

TElXMLCounterSignatureList::~TElXMLCounterSignatureList()
{
#ifdef SB_USE_CLASS_TELXMLCOUNTERSIGNATURE
	delete this->_Inst_CounterSignature;
	this->_Inst_CounterSignature = NULL;
#endif /* SB_USE_CLASS_TELXMLCOUNTERSIGNATURE */
}
#endif /* SB_USE_CLASS_TELXMLCOUNTERSIGNATURELIST */

#ifdef SB_USE_CLASS_TELXMLDATAOBJECTFORMAT

SB_INLINE void TElXMLDataObjectFormat::Clear()
{
	SBCheckError(TElXMLDataObjectFormat_Clear(_Handle));
}

bool TElXMLDataObjectFormat::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLDataObjectFormat_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLDataObjectFormat::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLDataObjectFormat_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLDataObjectFormat::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLDataObjectFormat_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLDataObjectFormat::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLDataObjectFormat_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLDataObjectFormat::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLDataObjectFormat_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLDataObjectFormat::get_Description(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDataObjectFormat_get_Description(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(305403976, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDataObjectFormat::get_Description(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDataObjectFormat_get_Description(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(305403976, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLDataObjectFormat::set_Description(const sb_u16string &Value)
{
	SBCheckError(TElXMLDataObjectFormat_set_Description(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLDataObjectFormat::set_Description(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLDataObjectFormat_set_Description(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLOBJECTIDENTIFIER
TElXMLObjectIdentifier* TElXMLDataObjectFormat::get_ObjectIdentifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLDataObjectFormat_get_ObjectIdentifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ObjectIdentifier)
		this->_Inst_ObjectIdentifier = new TElXMLObjectIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_ObjectIdentifier->updateHandle(hOutResult);
	return this->_Inst_ObjectIdentifier;
}

SB_INLINE void TElXMLDataObjectFormat::set_ObjectIdentifier(TElXMLObjectIdentifier &Value)
{
	SBCheckError(TElXMLDataObjectFormat_set_ObjectIdentifier(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLDataObjectFormat::set_ObjectIdentifier(TElXMLObjectIdentifier *Value)
{
	SBCheckError(TElXMLDataObjectFormat_set_ObjectIdentifier(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLOBJECTIDENTIFIER */

void TElXMLDataObjectFormat::get_MimeType(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDataObjectFormat_get_MimeType(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(39474603, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDataObjectFormat::get_MimeType(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDataObjectFormat_get_MimeType(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(39474603, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLDataObjectFormat::set_MimeType(const sb_u16string &Value)
{
	SBCheckError(TElXMLDataObjectFormat_set_MimeType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLDataObjectFormat::set_MimeType(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLDataObjectFormat_set_MimeType(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLDataObjectFormat::get_Encoding(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDataObjectFormat_get_Encoding(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1293939613, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDataObjectFormat::get_Encoding(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDataObjectFormat_get_Encoding(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1293939613, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLDataObjectFormat::set_Encoding(const sb_u16string &Value)
{
	SBCheckError(TElXMLDataObjectFormat_set_Encoding(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLDataObjectFormat::set_Encoding(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLDataObjectFormat_set_Encoding(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLDataObjectFormat::get_ObjectReference(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDataObjectFormat_get_ObjectReference(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(232057390, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDataObjectFormat::get_ObjectReference(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDataObjectFormat_get_ObjectReference(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(232057390, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLDataObjectFormat::set_ObjectReference(const sb_u16string &Value)
{
	SBCheckError(TElXMLDataObjectFormat_set_ObjectReference(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLDataObjectFormat::set_ObjectReference(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLDataObjectFormat_set_ObjectReference(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLDataObjectFormat::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLOBJECTIDENTIFIER
	this->_Inst_ObjectIdentifier = NULL;
#endif /* SB_USE_CLASS_TELXMLOBJECTIDENTIFIER */
}

TElXMLDataObjectFormat::TElXMLDataObjectFormat(TElXMLDataObjectFormatHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLDataObjectFormat::TElXMLDataObjectFormat(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLDataObjectFormat_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLDataObjectFormat::TElXMLDataObjectFormat(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLDataObjectFormat_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLDataObjectFormat::TElXMLDataObjectFormat(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLDataObjectFormat_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLDataObjectFormat::TElXMLDataObjectFormat(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLDataObjectFormat_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLDataObjectFormat::TElXMLDataObjectFormat(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLDataObjectFormat_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLDataObjectFormat::~TElXMLDataObjectFormat()
{
#ifdef SB_USE_CLASS_TELXMLOBJECTIDENTIFIER
	delete this->_Inst_ObjectIdentifier;
	this->_Inst_ObjectIdentifier = NULL;
#endif /* SB_USE_CLASS_TELXMLOBJECTIDENTIFIER */
}
#endif /* SB_USE_CLASS_TELXMLDATAOBJECTFORMAT */

#ifdef SB_USE_CLASS_TELXMLDATAOBJECTFORMATLIST

#ifdef SB_USE_CLASS_TELXMLDATAOBJECTFORMAT
SB_INLINE int32_t TElXMLDataObjectFormatList::Add(TElXMLDataObjectFormat &ADataObjectFormat)
{
	int32_t OutResult;
	SBCheckError(TElXMLDataObjectFormatList_Add(_Handle, ADataObjectFormat.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLDataObjectFormatList::Add(TElXMLDataObjectFormat *ADataObjectFormat)
{
	int32_t OutResult;
	SBCheckError(TElXMLDataObjectFormatList_Add(_Handle, (ADataObjectFormat != NULL) ? ADataObjectFormat->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDATAOBJECTFORMAT */

#ifdef SB_USE_CLASS_TELXMLDATAOBJECTFORMAT
SB_INLINE void TElXMLDataObjectFormatList::Insert(int32_t Index, TElXMLDataObjectFormat &ADataObjectFormat)
{
	SBCheckError(TElXMLDataObjectFormatList_Insert(_Handle, Index, ADataObjectFormat.getHandle()));
}

SB_INLINE void TElXMLDataObjectFormatList::Insert(int32_t Index, TElXMLDataObjectFormat *ADataObjectFormat)
{
	SBCheckError(TElXMLDataObjectFormatList_Insert(_Handle, Index, (ADataObjectFormat != NULL) ? ADataObjectFormat->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDATAOBJECTFORMAT */

SB_INLINE void TElXMLDataObjectFormatList::Delete(int32_t Index)
{
	SBCheckError(TElXMLDataObjectFormatList_Delete(_Handle, Index));
}

SB_INLINE void TElXMLDataObjectFormatList::Clear()
{
	SBCheckError(TElXMLDataObjectFormatList_Clear(_Handle));
}

SB_INLINE int32_t TElXMLDataObjectFormatList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLDataObjectFormatList_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLDATAOBJECTFORMAT
TElXMLDataObjectFormat* TElXMLDataObjectFormatList::get_DataObjectFormat(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLDataObjectFormatList_get_DataObjectFormat(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DataObjectFormat)
		this->_Inst_DataObjectFormat = new TElXMLDataObjectFormat(hOutResult, ohFalse);
	else
		this->_Inst_DataObjectFormat->updateHandle(hOutResult);
	return this->_Inst_DataObjectFormat;
}
#endif /* SB_USE_CLASS_TELXMLDATAOBJECTFORMAT */

void TElXMLDataObjectFormatList::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDATAOBJECTFORMAT
	this->_Inst_DataObjectFormat = NULL;
#endif /* SB_USE_CLASS_TELXMLDATAOBJECTFORMAT */
}

TElXMLDataObjectFormatList::TElXMLDataObjectFormatList(TElXMLDataObjectFormatListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElXMLDataObjectFormatList::TElXMLDataObjectFormatList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLDataObjectFormatList_Create(&_Handle));
}

TElXMLDataObjectFormatList::~TElXMLDataObjectFormatList()
{
#ifdef SB_USE_CLASS_TELXMLDATAOBJECTFORMAT
	delete this->_Inst_DataObjectFormat;
	this->_Inst_DataObjectFormat = NULL;
#endif /* SB_USE_CLASS_TELXMLDATAOBJECTFORMAT */
}
#endif /* SB_USE_CLASS_TELXMLDATAOBJECTFORMATLIST */

#ifdef SB_USE_CLASS_TELXMLCOMMITMENTTYPEQUALIFIER

TElXMLCommitmentTypeQualifier::TElXMLCommitmentTypeQualifier(TElXMLCommitmentTypeQualifierHandle handle, TElOwnHandle ownHandle) : TElXMLAnyType(handle, ownHandle)
{
}

TElXMLCommitmentTypeQualifier::TElXMLCommitmentTypeQualifier(TSBXAdESVersion AVersion) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLCommitmentTypeQualifier_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLCommitmentTypeQualifier::TElXMLCommitmentTypeQualifier(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLCommitmentTypeQualifier_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLCommitmentTypeQualifier::TElXMLCommitmentTypeQualifier(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLCommitmentTypeQualifier_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLCommitmentTypeQualifier::TElXMLCommitmentTypeQualifier(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLCommitmentTypeQualifier_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLCommitmentTypeQualifier::TElXMLCommitmentTypeQualifier(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLCommitmentTypeQualifier_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLCOMMITMENTTYPEQUALIFIER */

#ifdef SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION

SB_INLINE void TElXMLCommitmentTypeIndication::Clear()
{
	SBCheckError(TElXMLCommitmentTypeIndication_Clear(_Handle));
}

bool TElXMLCommitmentTypeIndication::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLCommitmentTypeIndication_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLCommitmentTypeIndication::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLCommitmentTypeIndication_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLCommitmentTypeIndication::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLCommitmentTypeIndication_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLCommitmentTypeIndication::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCommitmentTypeIndication_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLCommitmentTypeIndication::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCommitmentTypeIndication_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

bool TElXMLCommitmentTypeIndication::get_AllSignedDataObjects()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLCommitmentTypeIndication_get_AllSignedDataObjects(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLCommitmentTypeIndication::set_AllSignedDataObjects(bool Value)
{
	SBCheckError(TElXMLCommitmentTypeIndication_set_AllSignedDataObjects(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELXMLOBJECTIDENTIFIER
TElXMLObjectIdentifier* TElXMLCommitmentTypeIndication::get_CommitmentTypeId()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCommitmentTypeIndication_get_CommitmentTypeId(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CommitmentTypeId)
		this->_Inst_CommitmentTypeId = new TElXMLObjectIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_CommitmentTypeId->updateHandle(hOutResult);
	return this->_Inst_CommitmentTypeId;
}
#endif /* SB_USE_CLASS_TELXMLOBJECTIDENTIFIER */

#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
TElXMLAnyTypeList* TElXMLCommitmentTypeIndication::get_CommitmentTypeQualifiers()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCommitmentTypeIndication_get_CommitmentTypeQualifiers(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CommitmentTypeQualifiers)
		this->_Inst_CommitmentTypeQualifiers = new TElXMLAnyTypeList(hOutResult, ohFalse);
	else
		this->_Inst_CommitmentTypeQualifiers->updateHandle(hOutResult);
	return this->_Inst_CommitmentTypeQualifiers;
}
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElXMLCommitmentTypeIndication::get_ObjectReference()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCommitmentTypeIndication_get_ObjectReference(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ObjectReference)
		this->_Inst_ObjectReference = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_ObjectReference->updateHandle(hOutResult);
	return this->_Inst_ObjectReference;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

void TElXMLCommitmentTypeIndication::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLOBJECTIDENTIFIER
	this->_Inst_CommitmentTypeId = NULL;
#endif /* SB_USE_CLASS_TELXMLOBJECTIDENTIFIER */
#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
	this->_Inst_CommitmentTypeQualifiers = NULL;
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_ObjectReference = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}

TElXMLCommitmentTypeIndication::TElXMLCommitmentTypeIndication(TElXMLCommitmentTypeIndicationHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLCommitmentTypeIndication::TElXMLCommitmentTypeIndication(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCommitmentTypeIndication_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLCommitmentTypeIndication::TElXMLCommitmentTypeIndication(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCommitmentTypeIndication_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLCommitmentTypeIndication::TElXMLCommitmentTypeIndication(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLCommitmentTypeIndication_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLCommitmentTypeIndication::TElXMLCommitmentTypeIndication(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCommitmentTypeIndication_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLCommitmentTypeIndication::TElXMLCommitmentTypeIndication(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLCommitmentTypeIndication_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLCommitmentTypeIndication::~TElXMLCommitmentTypeIndication()
{
#ifdef SB_USE_CLASS_TELXMLOBJECTIDENTIFIER
	delete this->_Inst_CommitmentTypeId;
	this->_Inst_CommitmentTypeId = NULL;
#endif /* SB_USE_CLASS_TELXMLOBJECTIDENTIFIER */
#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
	delete this->_Inst_CommitmentTypeQualifiers;
	this->_Inst_CommitmentTypeQualifiers = NULL;
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_ObjectReference;
	this->_Inst_ObjectReference = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}
#endif /* SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION */

#ifdef SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATIONLIST

#ifdef SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION
SB_INLINE int32_t TElXMLCommitmentTypeIndicationList::Add(TElXMLCommitmentTypeIndication &ACommitmentTypeIndication)
{
	int32_t OutResult;
	SBCheckError(TElXMLCommitmentTypeIndicationList_Add(_Handle, ACommitmentTypeIndication.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLCommitmentTypeIndicationList::Add(TElXMLCommitmentTypeIndication *ACommitmentTypeIndication)
{
	int32_t OutResult;
	SBCheckError(TElXMLCommitmentTypeIndicationList_Add(_Handle, (ACommitmentTypeIndication != NULL) ? ACommitmentTypeIndication->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION */

#ifdef SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION
SB_INLINE void TElXMLCommitmentTypeIndicationList::Insert(int32_t Index, TElXMLCommitmentTypeIndication &ACommitmentTypeIndication)
{
	SBCheckError(TElXMLCommitmentTypeIndicationList_Insert(_Handle, Index, ACommitmentTypeIndication.getHandle()));
}

SB_INLINE void TElXMLCommitmentTypeIndicationList::Insert(int32_t Index, TElXMLCommitmentTypeIndication *ACommitmentTypeIndication)
{
	SBCheckError(TElXMLCommitmentTypeIndicationList_Insert(_Handle, Index, (ACommitmentTypeIndication != NULL) ? ACommitmentTypeIndication->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION */

SB_INLINE void TElXMLCommitmentTypeIndicationList::Delete(int32_t Index)
{
	SBCheckError(TElXMLCommitmentTypeIndicationList_Delete(_Handle, Index));
}

SB_INLINE void TElXMLCommitmentTypeIndicationList::Clear()
{
	SBCheckError(TElXMLCommitmentTypeIndicationList_Clear(_Handle));
}

SB_INLINE int32_t TElXMLCommitmentTypeIndicationList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLCommitmentTypeIndicationList_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION
TElXMLCommitmentTypeIndication* TElXMLCommitmentTypeIndicationList::get_CommitmentTypeIndication(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCommitmentTypeIndicationList_get_CommitmentTypeIndication(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CommitmentTypeIndication)
		this->_Inst_CommitmentTypeIndication = new TElXMLCommitmentTypeIndication(hOutResult, ohFalse);
	else
		this->_Inst_CommitmentTypeIndication->updateHandle(hOutResult);
	return this->_Inst_CommitmentTypeIndication;
}
#endif /* SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION */

void TElXMLCommitmentTypeIndicationList::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION
	this->_Inst_CommitmentTypeIndication = NULL;
#endif /* SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION */
}

TElXMLCommitmentTypeIndicationList::TElXMLCommitmentTypeIndicationList(TElXMLCommitmentTypeIndicationListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElXMLCommitmentTypeIndicationList::TElXMLCommitmentTypeIndicationList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCommitmentTypeIndicationList_Create(&_Handle));
}

TElXMLCommitmentTypeIndicationList::~TElXMLCommitmentTypeIndicationList()
{
#ifdef SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION
	delete this->_Inst_CommitmentTypeIndication;
	this->_Inst_CommitmentTypeIndication = NULL;
#endif /* SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION */
}
#endif /* SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATIONLIST */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE

SB_INLINE void TElXMLSignatureProductionPlace::Assign(TElXMLAdESElement &Source)
{
	SBCheckError(TElXMLSignatureProductionPlace_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElXMLSignatureProductionPlace::Assign(TElXMLAdESElement *Source)
{
	SBCheckError(TElXMLSignatureProductionPlace_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElXMLSignatureProductionPlace::Clear()
{
	SBCheckError(TElXMLSignatureProductionPlace_Clear(_Handle));
}

bool TElXMLSignatureProductionPlace::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLSignatureProductionPlace_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSignatureProductionPlace::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSignatureProductionPlace_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSignatureProductionPlace::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSignatureProductionPlace_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLSignatureProductionPlace::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSignatureProductionPlace_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLSignatureProductionPlace::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSignatureProductionPlace_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLSignatureProductionPlace::get_City(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSignatureProductionPlace_get_City(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1831244117, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSignatureProductionPlace::get_City(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSignatureProductionPlace_get_City(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1831244117, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSignatureProductionPlace::set_City(const sb_u16string &Value)
{
	SBCheckError(TElXMLSignatureProductionPlace_set_City(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSignatureProductionPlace::set_City(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSignatureProductionPlace_set_City(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSignatureProductionPlace::get_StateOrProvince(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSignatureProductionPlace_get_StateOrProvince(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(2042757021, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSignatureProductionPlace::get_StateOrProvince(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSignatureProductionPlace_get_StateOrProvince(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(2042757021, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSignatureProductionPlace::set_StateOrProvince(const sb_u16string &Value)
{
	SBCheckError(TElXMLSignatureProductionPlace_set_StateOrProvince(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSignatureProductionPlace::set_StateOrProvince(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSignatureProductionPlace_set_StateOrProvince(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSignatureProductionPlace::get_PostalCode(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSignatureProductionPlace_get_PostalCode(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-924118332, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSignatureProductionPlace::get_PostalCode(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSignatureProductionPlace_get_PostalCode(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-924118332, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSignatureProductionPlace::set_PostalCode(const sb_u16string &Value)
{
	SBCheckError(TElXMLSignatureProductionPlace_set_PostalCode(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSignatureProductionPlace::set_PostalCode(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSignatureProductionPlace_set_PostalCode(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSignatureProductionPlace::get_CountryName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSignatureProductionPlace_get_CountryName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(962297554, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSignatureProductionPlace::get_CountryName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSignatureProductionPlace_get_CountryName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(962297554, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSignatureProductionPlace::set_CountryName(const sb_u16string &Value)
{
	SBCheckError(TElXMLSignatureProductionPlace_set_CountryName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSignatureProductionPlace::set_CountryName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSignatureProductionPlace_set_CountryName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLSignatureProductionPlace::TElXMLSignatureProductionPlace(TElXMLSignatureProductionPlaceHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
}

TElXMLSignatureProductionPlace::TElXMLSignatureProductionPlace(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSignatureProductionPlace_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLSignatureProductionPlace::TElXMLSignatureProductionPlace(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSignatureProductionPlace_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSignatureProductionPlace::TElXMLSignatureProductionPlace(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSignatureProductionPlace_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLSignatureProductionPlace::TElXMLSignatureProductionPlace(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSignatureProductionPlace_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSignatureProductionPlace::TElXMLSignatureProductionPlace(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSignatureProductionPlace_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE */

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDX509CERTIFICATES

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE int32_t TElXMLEncapsulatedX509Certificates::AddCertificate(TElX509Certificate &ACert, TSBXAdESVersion AXAdESVersion)
{
	int32_t OutResult;
	SBCheckError(TElXMLEncapsulatedX509Certificates_AddCertificate(_Handle, ACert.getHandle(), (TSBXAdESVersionRaw)AXAdESVersion, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLEncapsulatedX509Certificates::AddCertificate(TElX509Certificate *ACert, TSBXAdESVersion AXAdESVersion)
{
	int32_t OutResult;
	SBCheckError(TElXMLEncapsulatedX509Certificates_AddCertificate(_Handle, (ACert != NULL) ? ACert->getHandle() : SB_NULL_HANDLE, (TSBXAdESVersionRaw)AXAdESVersion, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE void TElXMLEncapsulatedX509Certificates::Clear()
{
	SBCheckError(TElXMLEncapsulatedX509Certificates_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElXMLEncapsulatedX509Certificates::get_Certificates(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLEncapsulatedX509Certificates_get_Certificates(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

void TElXMLEncapsulatedX509Certificates::initInstances()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
}

TElXMLEncapsulatedX509Certificates::TElXMLEncapsulatedX509Certificates(TElXMLEncapsulatedX509CertificatesHandle handle, TElOwnHandle ownHandle) : TElXMLEncapsulatedPKIDataList(handle, ownHandle)
{
	initInstances();
}

TElXMLEncapsulatedX509Certificates::TElXMLEncapsulatedX509Certificates() : TElXMLEncapsulatedPKIDataList(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLEncapsulatedX509Certificates_Create(&_Handle));
}

TElXMLEncapsulatedX509Certificates::~TElXMLEncapsulatedX509Certificates()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
}
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDX509CERTIFICATES */

#ifdef SB_USE_CLASS_TELXMLCERTIFIEDROLE

TElXMLCertifiedRole::TElXMLCertifiedRole(TElXMLCertifiedRoleHandle handle, TElOwnHandle ownHandle) : TElXMLEncapsulatedPKIData(handle, ownHandle)
{
}

TElXMLCertifiedRole::TElXMLCertifiedRole(TSBXAdESVersion AVersion) : TElXMLEncapsulatedPKIData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLCertifiedRole_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLCertifiedRole::TElXMLCertifiedRole(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLEncapsulatedPKIData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLCertifiedRole_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLCertifiedRole::TElXMLCertifiedRole(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLEncapsulatedPKIData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLCertifiedRole_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLCertifiedRole::TElXMLCertifiedRole(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLEncapsulatedPKIData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLCertifiedRole_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLCertifiedRole::TElXMLCertifiedRole(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLEncapsulatedPKIData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLCertifiedRole_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLCERTIFIEDROLE */

#ifdef SB_USE_CLASS_TELXMLCERTIFIEDROLESLIST

TElXMLCertifiedRolesList::TElXMLCertifiedRolesList(TElXMLCertifiedRolesListHandle handle, TElOwnHandle ownHandle) : TElXMLEncapsulatedX509Certificates(handle, ownHandle)
{
}

TElXMLCertifiedRolesList::TElXMLCertifiedRolesList() : TElXMLEncapsulatedX509Certificates(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLCertifiedRolesList_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLCERTIFIEDROLESLIST */

#ifdef SB_USE_CLASS_TELXMLCLAIMEDROLE

TElXMLClaimedRole::TElXMLClaimedRole(TElXMLClaimedRoleHandle handle, TElOwnHandle ownHandle) : TElXMLAnyType(handle, ownHandle)
{
}

TElXMLClaimedRole::TElXMLClaimedRole(TSBXAdESVersion AVersion) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLClaimedRole_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLClaimedRole::TElXMLClaimedRole(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLClaimedRole_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLClaimedRole::TElXMLClaimedRole(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLClaimedRole_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLClaimedRole::TElXMLClaimedRole(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLClaimedRole_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLClaimedRole::TElXMLClaimedRole(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLClaimedRole_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLCLAIMEDROLE */

#ifdef SB_USE_CLASS_TELXMLCLAIMEDROLESLIST

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE int32_t TElXMLClaimedRolesList::AddText(TSBXAdESVersion AVersion, TElXMLDOMDocument &OwnerDocument, const sb_u16string &Text)
{
	int32_t OutResult;
	SBCheckError(TElXMLClaimedRolesList_AddText(_Handle, (TSBXAdESVersionRaw)AVersion, OwnerDocument.getHandle(), Text.data(), (int32_t)Text.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLClaimedRolesList::AddText(TSBXAdESVersion AVersion, TElXMLDOMDocument *OwnerDocument, const sb_u16string &Text)
{
	int32_t OutResult;
	SBCheckError(TElXMLClaimedRolesList_AddText(_Handle, (TSBXAdESVersionRaw)AVersion, (OwnerDocument != NULL) ? OwnerDocument->getHandle() : SB_NULL_HANDLE, Text.data(), (int32_t)Text.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLClaimedRolesList::AddText(TSBXAdESVersion AVersion, TElXMLDOMDocument &OwnerDocument, const std::wstring &Text)
{
	int32_t OutResult;
	std::string u16Text;
	sb_to_u16string(Text, u16Text);
	SBCheckError(TElXMLClaimedRolesList_AddText(_Handle, (TSBXAdESVersionRaw)AVersion, OwnerDocument.getHandle(), reinterpret_cast<const sb_char16_t*>(u16Text.data()), (int32_t)u16Text.length() >> 1, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLClaimedRolesList::AddText(TSBXAdESVersion AVersion, TElXMLDOMDocument *OwnerDocument, const std::wstring &Text)
{
	int32_t OutResult;
	std::string u16Text;
	sb_to_u16string(Text, u16Text);
	SBCheckError(TElXMLClaimedRolesList_AddText(_Handle, (TSBXAdESVersionRaw)AVersion, (OwnerDocument != NULL) ? OwnerDocument->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16Text.data()), (int32_t)u16Text.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

TElXMLClaimedRolesList::TElXMLClaimedRolesList(TElXMLClaimedRolesListHandle handle, TElOwnHandle ownHandle) : TElXMLAnyTypeList(handle, ownHandle)
{
}

TElXMLClaimedRolesList::TElXMLClaimedRolesList() : TElXMLAnyTypeList(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLClaimedRolesList_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLCLAIMEDROLESLIST */

#ifdef SB_USE_CLASS_TELXMLSIGNERROLE

SB_INLINE void TElXMLSignerRole::Assign(TElXMLAdESElement &Source)
{
	SBCheckError(TElXMLSignerRole_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElXMLSignerRole::Assign(TElXMLAdESElement *Source)
{
	SBCheckError(TElXMLSignerRole_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElXMLSignerRole::Clear()
{
	SBCheckError(TElXMLSignerRole_Clear(_Handle));
}

bool TElXMLSignerRole::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLSignerRole_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSignerRole::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSignerRole_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSignerRole::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSignerRole_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLSignerRole::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSignerRole_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLSignerRole::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSignerRole_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLCLAIMEDROLESLIST
TElXMLClaimedRolesList* TElXMLSignerRole::get_ClaimedRoles()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignerRole_get_ClaimedRoles(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ClaimedRoles)
		this->_Inst_ClaimedRoles = new TElXMLClaimedRolesList(hOutResult, ohFalse);
	else
		this->_Inst_ClaimedRoles->updateHandle(hOutResult);
	return this->_Inst_ClaimedRoles;
}
#endif /* SB_USE_CLASS_TELXMLCLAIMEDROLESLIST */

#ifdef SB_USE_CLASS_TELXMLCERTIFIEDROLESLIST
TElXMLCertifiedRolesList* TElXMLSignerRole::get_CertifiedRoles()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignerRole_get_CertifiedRoles(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertifiedRoles)
		this->_Inst_CertifiedRoles = new TElXMLCertifiedRolesList(hOutResult, ohFalse);
	else
		this->_Inst_CertifiedRoles->updateHandle(hOutResult);
	return this->_Inst_CertifiedRoles;
}
#endif /* SB_USE_CLASS_TELXMLCERTIFIEDROLESLIST */

void TElXMLSignerRole::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLCLAIMEDROLESLIST
	this->_Inst_ClaimedRoles = NULL;
#endif /* SB_USE_CLASS_TELXMLCLAIMEDROLESLIST */
#ifdef SB_USE_CLASS_TELXMLCERTIFIEDROLESLIST
	this->_Inst_CertifiedRoles = NULL;
#endif /* SB_USE_CLASS_TELXMLCERTIFIEDROLESLIST */
}

TElXMLSignerRole::TElXMLSignerRole(TElXMLSignerRoleHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLSignerRole::TElXMLSignerRole(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSignerRole_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLSignerRole::TElXMLSignerRole(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSignerRole_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSignerRole::TElXMLSignerRole(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSignerRole_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLSignerRole::TElXMLSignerRole(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSignerRole_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSignerRole::TElXMLSignerRole(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSignerRole_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLSignerRole::~TElXMLSignerRole()
{
#ifdef SB_USE_CLASS_TELXMLCLAIMEDROLESLIST
	delete this->_Inst_ClaimedRoles;
	this->_Inst_ClaimedRoles = NULL;
#endif /* SB_USE_CLASS_TELXMLCLAIMEDROLESLIST */
#ifdef SB_USE_CLASS_TELXMLCERTIFIEDROLESLIST
	delete this->_Inst_CertifiedRoles;
	this->_Inst_CertifiedRoles = NULL;
#endif /* SB_USE_CLASS_TELXMLCERTIFIEDROLESLIST */
}
#endif /* SB_USE_CLASS_TELXMLSIGNERROLE */

#ifdef SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS

SB_INLINE void TElXMLCompleteCertificateRefs::Clear()
{
	SBCheckError(TElXMLCompleteCertificateRefs_Clear(_Handle));
}

bool TElXMLCompleteCertificateRefs::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLCompleteCertificateRefs_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLCompleteCertificateRefs::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLCompleteCertificateRefs_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLCompleteCertificateRefs::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLCompleteCertificateRefs_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLCompleteCertificateRefs::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCompleteCertificateRefs_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLCompleteCertificateRefs::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCompleteCertificateRefs_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLCompleteCertificateRefs::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLCompleteCertificateRefs_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(381049014, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLCompleteCertificateRefs::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLCompleteCertificateRefs_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(381049014, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLCompleteCertificateRefs::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLCompleteCertificateRefs_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLCompleteCertificateRefs::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLCompleteCertificateRefs_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLCERTIDLIST
TElXMLCertIDList* TElXMLCompleteCertificateRefs::get_CertRefs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCompleteCertificateRefs_get_CertRefs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertRefs)
		this->_Inst_CertRefs = new TElXMLCertIDList(hOutResult, ohFalse);
	else
		this->_Inst_CertRefs->updateHandle(hOutResult);
	return this->_Inst_CertRefs;
}
#endif /* SB_USE_CLASS_TELXMLCERTIDLIST */

void TElXMLCompleteCertificateRefs::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLCERTIDLIST
	this->_Inst_CertRefs = NULL;
#endif /* SB_USE_CLASS_TELXMLCERTIDLIST */
}

TElXMLCompleteCertificateRefs::TElXMLCompleteCertificateRefs(TElXMLCompleteCertificateRefsHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLCompleteCertificateRefs::TElXMLCompleteCertificateRefs(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCompleteCertificateRefs_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLCompleteCertificateRefs::TElXMLCompleteCertificateRefs(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCompleteCertificateRefs_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLCompleteCertificateRefs::TElXMLCompleteCertificateRefs(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLCompleteCertificateRefs_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLCompleteCertificateRefs::TElXMLCompleteCertificateRefs(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCompleteCertificateRefs_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLCompleteCertificateRefs::TElXMLCompleteCertificateRefs(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLCompleteCertificateRefs_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLCompleteCertificateRefs::~TElXMLCompleteCertificateRefs()
{
#ifdef SB_USE_CLASS_TELXMLCERTIDLIST
	delete this->_Inst_CertRefs;
	this->_Inst_CertRefs = NULL;
#endif /* SB_USE_CLASS_TELXMLCERTIDLIST */
}
#endif /* SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS */

#ifdef SB_USE_CLASS_TELXMLCRLIDENTIFIER

SB_INLINE void TElXMLCRLIdentifier::Clear()
{
	SBCheckError(TElXMLCRLIdentifier_Clear(_Handle));
}

bool TElXMLCRLIdentifier::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLCRLIdentifier_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLCRLIdentifier::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLCRLIdentifier_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLCRLIdentifier::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLCRLIdentifier_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLCRLIdentifier::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCRLIdentifier_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLCRLIdentifier::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCRLIdentifier_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLCRLIdentifier::get_Issuer(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLCRLIdentifier_get_Issuer(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(542193400, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLCRLIdentifier::get_Issuer(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLCRLIdentifier_get_Issuer(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(542193400, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLCRLIdentifier::set_Issuer(const sb_u16string &Value)
{
	SBCheckError(TElXMLCRLIdentifier_set_Issuer(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLCRLIdentifier::set_Issuer(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLCRLIdentifier_set_Issuer(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLCRLIdentifier::get_IssueTime(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLCRLIdentifier_get_IssueTime(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(24334895, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLCRLIdentifier::get_IssueTime(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLCRLIdentifier_get_IssueTime(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(24334895, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLCRLIdentifier::set_IssueTime(const sb_u16string &Value)
{
	SBCheckError(TElXMLCRLIdentifier_set_IssueTime(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLCRLIdentifier::set_IssueTime(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLCRLIdentifier_set_IssueTime(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE int64_t TElXMLCRLIdentifier::get_IssueTimeUTC()
{
	int64_t OutResult;
	SBCheckError(TElXMLCRLIdentifier_get_IssueTimeUTC(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLCRLIdentifier::set_IssueTimeUTC(int64_t Value)
{
	SBCheckError(TElXMLCRLIdentifier_set_IssueTimeUTC(_Handle, Value));
}

SB_INLINE int32_t TElXMLCRLIdentifier::get_Number()
{
	int32_t OutResult;
	SBCheckError(TElXMLCRLIdentifier_get_Number(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLCRLIdentifier::set_Number(int32_t Value)
{
	SBCheckError(TElXMLCRLIdentifier_set_Number(_Handle, Value));
}

void TElXMLCRLIdentifier::get_URI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLCRLIdentifier_get_URI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1846533471, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLCRLIdentifier::get_URI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLCRLIdentifier_get_URI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1846533471, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLCRLIdentifier::set_URI(const sb_u16string &Value)
{
	SBCheckError(TElXMLCRLIdentifier_set_URI(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLCRLIdentifier::set_URI(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLCRLIdentifier_set_URI(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLCRLIdentifier::TElXMLCRLIdentifier(TElXMLCRLIdentifierHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
}

TElXMLCRLIdentifier::TElXMLCRLIdentifier(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLCRLIdentifier_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLCRLIdentifier::TElXMLCRLIdentifier(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLCRLIdentifier_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLCRLIdentifier::TElXMLCRLIdentifier(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLCRLIdentifier_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLCRLIdentifier::TElXMLCRLIdentifier(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLCRLIdentifier_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLCRLIdentifier::TElXMLCRLIdentifier(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLCRLIdentifier_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLCRLIDENTIFIER */

#ifdef SB_USE_CLASS_TELXMLCRLREF

SB_INLINE void TElXMLCRLRef::Clear()
{
	SBCheckError(TElXMLCRLRef_Clear(_Handle));
}

bool TElXMLCRLRef::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLCRLRef_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
bool TElXMLCRLRef::IsMatch(TElCertificateRevocationList &ACRL)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLCRLRef_IsMatch(_Handle, ACRL.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElXMLCRLRef::IsMatch(TElCertificateRevocationList *ACRL)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLCRLRef_IsMatch(_Handle, (ACRL != NULL) ? ACRL->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLCRLRef::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLCRLRef_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLCRLRef::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLCRLRef_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLCRLRef::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCRLRef_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLCRLRef::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCRLRef_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDIGESTALGANDVALUE
TElXMLDigestAlgAndValue* TElXMLCRLRef::get_DigestAlgAndValue()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCRLRef_get_DigestAlgAndValue(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DigestAlgAndValue)
		this->_Inst_DigestAlgAndValue = new TElXMLDigestAlgAndValue(hOutResult, ohFalse);
	else
		this->_Inst_DigestAlgAndValue->updateHandle(hOutResult);
	return this->_Inst_DigestAlgAndValue;
}
#endif /* SB_USE_CLASS_TELXMLDIGESTALGANDVALUE */

#ifdef SB_USE_CLASS_TELXMLCRLIDENTIFIER
TElXMLCRLIdentifier* TElXMLCRLRef::get_CRLIdentifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCRLRef_get_CRLIdentifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CRLIdentifier)
		this->_Inst_CRLIdentifier = new TElXMLCRLIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_CRLIdentifier->updateHandle(hOutResult);
	return this->_Inst_CRLIdentifier;
}

SB_INLINE void TElXMLCRLRef::set_CRLIdentifier(TElXMLCRLIdentifier &Value)
{
	SBCheckError(TElXMLCRLRef_set_CRLIdentifier(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLCRLRef::set_CRLIdentifier(TElXMLCRLIdentifier *Value)
{
	SBCheckError(TElXMLCRLRef_set_CRLIdentifier(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLCRLIDENTIFIER */

void TElXMLCRLRef::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDIGESTALGANDVALUE
	this->_Inst_DigestAlgAndValue = NULL;
#endif /* SB_USE_CLASS_TELXMLDIGESTALGANDVALUE */
#ifdef SB_USE_CLASS_TELXMLCRLIDENTIFIER
	this->_Inst_CRLIdentifier = NULL;
#endif /* SB_USE_CLASS_TELXMLCRLIDENTIFIER */
}

TElXMLCRLRef::TElXMLCRLRef(TElXMLCRLRefHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLCRLRef::TElXMLCRLRef(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCRLRef_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLCRLRef::TElXMLCRLRef(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCRLRef_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLCRLRef::TElXMLCRLRef(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLCRLRef_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLCRLRef::TElXMLCRLRef(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCRLRef_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLCRLRef::TElXMLCRLRef(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLCRLRef_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLCRLRef::~TElXMLCRLRef()
{
#ifdef SB_USE_CLASS_TELXMLDIGESTALGANDVALUE
	delete this->_Inst_DigestAlgAndValue;
	this->_Inst_DigestAlgAndValue = NULL;
#endif /* SB_USE_CLASS_TELXMLDIGESTALGANDVALUE */
#ifdef SB_USE_CLASS_TELXMLCRLIDENTIFIER
	delete this->_Inst_CRLIdentifier;
	this->_Inst_CRLIdentifier = NULL;
#endif /* SB_USE_CLASS_TELXMLCRLIDENTIFIER */
}
#endif /* SB_USE_CLASS_TELXMLCRLREF */

#ifdef SB_USE_CLASS_TELXMLCRLREFS

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
SB_INLINE int32_t TElXMLCRLRefs::AddCRL(TElCertificateRevocationList &ACRL, TSBXAdESVersion AXAdESVersion)
{
	int32_t OutResult;
	SBCheckError(TElXMLCRLRefs_AddCRL(_Handle, ACRL.getHandle(), (TSBXAdESVersionRaw)AXAdESVersion, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLCRLRefs::AddCRL(TElCertificateRevocationList *ACRL, TSBXAdESVersion AXAdESVersion)
{
	int32_t OutResult;
	SBCheckError(TElXMLCRLRefs_AddCRL(_Handle, (ACRL != NULL) ? ACRL->getHandle() : SB_NULL_HANDLE, (TSBXAdESVersionRaw)AXAdESVersion, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
SB_INLINE int32_t TElXMLCRLRefs::AddCRL(TElCertificateRevocationList &ACRL, TElXMLDigestMethod DigestMethod, TSBXAdESVersion AXAdESVersion)
{
	int32_t OutResult;
	SBCheckError(TElXMLCRLRefs_AddCRL_1(_Handle, ACRL.getHandle(), (TElXMLDigestMethodRaw)DigestMethod, (TSBXAdESVersionRaw)AXAdESVersion, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLCRLRefs::AddCRL(TElCertificateRevocationList *ACRL, TElXMLDigestMethod DigestMethod, TSBXAdESVersion AXAdESVersion)
{
	int32_t OutResult;
	SBCheckError(TElXMLCRLRefs_AddCRL_1(_Handle, (ACRL != NULL) ? ACRL->getHandle() : SB_NULL_HANDLE, (TElXMLDigestMethodRaw)DigestMethod, (TSBXAdESVersionRaw)AXAdESVersion, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

#ifdef SB_USE_CLASS_TELXMLCRLREF
SB_INLINE int32_t TElXMLCRLRefs::Add(TElXMLCRLRef &ACRLRef)
{
	int32_t OutResult;
	SBCheckError(TElXMLCRLRefs_Add(_Handle, ACRLRef.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLCRLRefs::Add(TElXMLCRLRef *ACRLRef)
{
	int32_t OutResult;
	SBCheckError(TElXMLCRLRefs_Add(_Handle, (ACRLRef != NULL) ? ACRLRef->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLCRLREF */

#ifdef SB_USE_CLASS_TELXMLCRLREF
SB_INLINE void TElXMLCRLRefs::Insert(int32_t Index, TElXMLCRLRef &ACRLRef)
{
	SBCheckError(TElXMLCRLRefs_Insert(_Handle, Index, ACRLRef.getHandle()));
}

SB_INLINE void TElXMLCRLRefs::Insert(int32_t Index, TElXMLCRLRef *ACRLRef)
{
	SBCheckError(TElXMLCRLRefs_Insert(_Handle, Index, (ACRLRef != NULL) ? ACRLRef->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLCRLREF */

SB_INLINE void TElXMLCRLRefs::Delete(int32_t Index)
{
	SBCheckError(TElXMLCRLRefs_Delete(_Handle, Index));
}

SB_INLINE void TElXMLCRLRefs::Clear()
{
	SBCheckError(TElXMLCRLRefs_Clear(_Handle));
}

SB_INLINE int32_t TElXMLCRLRefs::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLCRLRefs_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLCRLREF
TElXMLCRLRef* TElXMLCRLRefs::get_CRLRef(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCRLRefs_get_CRLRef(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CRLRef)
		this->_Inst_CRLRef = new TElXMLCRLRef(hOutResult, ohFalse);
	else
		this->_Inst_CRLRef->updateHandle(hOutResult);
	return this->_Inst_CRLRef;
}
#endif /* SB_USE_CLASS_TELXMLCRLREF */

void TElXMLCRLRefs::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLCRLREF
	this->_Inst_CRLRef = NULL;
#endif /* SB_USE_CLASS_TELXMLCRLREF */
}

TElXMLCRLRefs::TElXMLCRLRefs(TElXMLCRLRefsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElXMLCRLRefs::TElXMLCRLRefs() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCRLRefs_Create(&_Handle));
}

TElXMLCRLRefs::~TElXMLCRLRefs()
{
#ifdef SB_USE_CLASS_TELXMLCRLREF
	delete this->_Inst_CRLRef;
	this->_Inst_CRLRef = NULL;
#endif /* SB_USE_CLASS_TELXMLCRLREF */
}
#endif /* SB_USE_CLASS_TELXMLCRLREFS */

#ifdef SB_USE_CLASS_TELXMLOCSPIDENTIFIER

SB_INLINE void TElXMLOCSPIdentifier::Clear()
{
	SBCheckError(TElXMLOCSPIdentifier_Clear(_Handle));
}

bool TElXMLOCSPIdentifier::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLOCSPIdentifier_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLOCSPIdentifier::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLOCSPIdentifier_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLOCSPIdentifier::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLOCSPIdentifier_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLOCSPIdentifier::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLOCSPIdentifier_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLOCSPIdentifier::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLOCSPIdentifier_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLOCSPIdentifier::get_ResponderID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLOCSPIdentifier_get_ResponderID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1898241385, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLOCSPIdentifier::get_ResponderID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLOCSPIdentifier_get_ResponderID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1898241385, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLOCSPIdentifier::set_ResponderID(const sb_u16string &Value)
{
	SBCheckError(TElXMLOCSPIdentifier_set_ResponderID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLOCSPIdentifier::set_ResponderID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLOCSPIdentifier_set_ResponderID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLOCSPIdentifier::get_ProducedAt(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLOCSPIdentifier_get_ProducedAt(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1373027837, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLOCSPIdentifier::get_ProducedAt(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLOCSPIdentifier_get_ProducedAt(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1373027837, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLOCSPIdentifier::set_ProducedAt(const sb_u16string &Value)
{
	SBCheckError(TElXMLOCSPIdentifier_set_ProducedAt(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLOCSPIdentifier::set_ProducedAt(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLOCSPIdentifier_set_ProducedAt(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE int64_t TElXMLOCSPIdentifier::get_ProducedAtUTC()
{
	int64_t OutResult;
	SBCheckError(TElXMLOCSPIdentifier_get_ProducedAtUTC(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLOCSPIdentifier::set_ProducedAtUTC(int64_t Value)
{
	SBCheckError(TElXMLOCSPIdentifier_set_ProducedAtUTC(_Handle, Value));
}

void TElXMLOCSPIdentifier::get_URI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLOCSPIdentifier_get_URI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(124981417, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLOCSPIdentifier::get_URI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLOCSPIdentifier_get_URI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(124981417, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLOCSPIdentifier::set_URI(const sb_u16string &Value)
{
	SBCheckError(TElXMLOCSPIdentifier_set_URI(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLOCSPIdentifier::set_URI(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLOCSPIdentifier_set_URI(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TSBXAdESResponderIDType TElXMLOCSPIdentifier::get_ResponderIDType()
{
	TSBXAdESResponderIDTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLOCSPIdentifier_get_ResponderIDType(_Handle, &OutResultRaw));
	return (TSBXAdESResponderIDType)OutResultRaw;
}

SB_INLINE void TElXMLOCSPIdentifier::set_ResponderIDType(TSBXAdESResponderIDType Value)
{
	SBCheckError(TElXMLOCSPIdentifier_set_ResponderIDType(_Handle, (TSBXAdESResponderIDTypeRaw)Value));
}

TElXMLOCSPIdentifier::TElXMLOCSPIdentifier(TElXMLOCSPIdentifierHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
}

TElXMLOCSPIdentifier::TElXMLOCSPIdentifier(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLOCSPIdentifier_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLOCSPIdentifier::TElXMLOCSPIdentifier(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLOCSPIdentifier_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLOCSPIdentifier::TElXMLOCSPIdentifier(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLOCSPIdentifier_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLOCSPIdentifier::TElXMLOCSPIdentifier(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLOCSPIdentifier_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLOCSPIdentifier::TElXMLOCSPIdentifier(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLOCSPIdentifier_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLOCSPIDENTIFIER */

#ifdef SB_USE_CLASS_TELXMLOCSPREF

SB_INLINE void TElXMLOCSPRef::Clear()
{
	SBCheckError(TElXMLOCSPRef_Clear(_Handle));
}

bool TElXMLOCSPRef::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLOCSPRef_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLOCSPRef::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLOCSPRef_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLOCSPRef::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLOCSPRef_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLOCSPRef::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLOCSPRef_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLOCSPRef::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLOCSPRef_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
bool TElXMLOCSPRef::IsMatch(TElOCSPResponse &OCSPResponse)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLOCSPRef_IsMatch(_Handle, OCSPResponse.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElXMLOCSPRef::IsMatch(TElOCSPResponse *OCSPResponse)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLOCSPRef_IsMatch(_Handle, (OCSPResponse != NULL) ? OCSPResponse->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

#ifdef SB_USE_CLASS_TELXMLDIGESTALGANDVALUE
TElXMLDigestAlgAndValue* TElXMLOCSPRef::get_DigestAlgAndValue()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLOCSPRef_get_DigestAlgAndValue(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DigestAlgAndValue)
		this->_Inst_DigestAlgAndValue = new TElXMLDigestAlgAndValue(hOutResult, ohFalse);
	else
		this->_Inst_DigestAlgAndValue->updateHandle(hOutResult);
	return this->_Inst_DigestAlgAndValue;
}

SB_INLINE void TElXMLOCSPRef::set_DigestAlgAndValue(TElXMLDigestAlgAndValue &Value)
{
	SBCheckError(TElXMLOCSPRef_set_DigestAlgAndValue(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLOCSPRef::set_DigestAlgAndValue(TElXMLDigestAlgAndValue *Value)
{
	SBCheckError(TElXMLOCSPRef_set_DigestAlgAndValue(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDIGESTALGANDVALUE */

#ifdef SB_USE_CLASS_TELXMLOCSPIDENTIFIER
TElXMLOCSPIdentifier* TElXMLOCSPRef::get_OCSPIdentifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLOCSPRef_get_OCSPIdentifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OCSPIdentifier)
		this->_Inst_OCSPIdentifier = new TElXMLOCSPIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_OCSPIdentifier->updateHandle(hOutResult);
	return this->_Inst_OCSPIdentifier;
}
#endif /* SB_USE_CLASS_TELXMLOCSPIDENTIFIER */

void TElXMLOCSPRef::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDIGESTALGANDVALUE
	this->_Inst_DigestAlgAndValue = NULL;
#endif /* SB_USE_CLASS_TELXMLDIGESTALGANDVALUE */
#ifdef SB_USE_CLASS_TELXMLOCSPIDENTIFIER
	this->_Inst_OCSPIdentifier = NULL;
#endif /* SB_USE_CLASS_TELXMLOCSPIDENTIFIER */
}

TElXMLOCSPRef::TElXMLOCSPRef(TElXMLOCSPRefHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLOCSPRef::TElXMLOCSPRef(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLOCSPRef_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLOCSPRef::TElXMLOCSPRef(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLOCSPRef_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLOCSPRef::TElXMLOCSPRef(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLOCSPRef_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLOCSPRef::TElXMLOCSPRef(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLOCSPRef_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLOCSPRef::TElXMLOCSPRef(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLOCSPRef_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLOCSPRef::~TElXMLOCSPRef()
{
#ifdef SB_USE_CLASS_TELXMLDIGESTALGANDVALUE
	delete this->_Inst_DigestAlgAndValue;
	this->_Inst_DigestAlgAndValue = NULL;
#endif /* SB_USE_CLASS_TELXMLDIGESTALGANDVALUE */
#ifdef SB_USE_CLASS_TELXMLOCSPIDENTIFIER
	delete this->_Inst_OCSPIdentifier;
	this->_Inst_OCSPIdentifier = NULL;
#endif /* SB_USE_CLASS_TELXMLOCSPIDENTIFIER */
}
#endif /* SB_USE_CLASS_TELXMLOCSPREF */

#ifdef SB_USE_CLASS_TELXMLOCSPREFS

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
SB_INLINE int32_t TElXMLOCSPRefs::AddOCSP(TElOCSPResponse &OCSPResponse, bool ByKey, TSBXAdESVersion AXAdESVersion)
{
	int32_t OutResult;
	SBCheckError(TElXMLOCSPRefs_AddOCSP(_Handle, OCSPResponse.getHandle(), (int8_t)ByKey, (TSBXAdESVersionRaw)AXAdESVersion, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLOCSPRefs::AddOCSP(TElOCSPResponse *OCSPResponse, bool ByKey, TSBXAdESVersion AXAdESVersion)
{
	int32_t OutResult;
	SBCheckError(TElXMLOCSPRefs_AddOCSP(_Handle, (OCSPResponse != NULL) ? OCSPResponse->getHandle() : SB_NULL_HANDLE, (int8_t)ByKey, (TSBXAdESVersionRaw)AXAdESVersion, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
SB_INLINE int32_t TElXMLOCSPRefs::AddOCSP(TElOCSPResponse &OCSPResponse, bool ByKey, TElXMLDigestMethod DigestMethod, TSBXAdESVersion AXAdESVersion)
{
	int32_t OutResult;
	SBCheckError(TElXMLOCSPRefs_AddOCSP_1(_Handle, OCSPResponse.getHandle(), (int8_t)ByKey, (TElXMLDigestMethodRaw)DigestMethod, (TSBXAdESVersionRaw)AXAdESVersion, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLOCSPRefs::AddOCSP(TElOCSPResponse *OCSPResponse, bool ByKey, TElXMLDigestMethod DigestMethod, TSBXAdESVersion AXAdESVersion)
{
	int32_t OutResult;
	SBCheckError(TElXMLOCSPRefs_AddOCSP_1(_Handle, (OCSPResponse != NULL) ? OCSPResponse->getHandle() : SB_NULL_HANDLE, (int8_t)ByKey, (TElXMLDigestMethodRaw)DigestMethod, (TSBXAdESVersionRaw)AXAdESVersion, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

#ifdef SB_USE_CLASS_TELXMLOCSPREF
SB_INLINE int32_t TElXMLOCSPRefs::Add(TElXMLOCSPRef &AOCSPRef)
{
	int32_t OutResult;
	SBCheckError(TElXMLOCSPRefs_Add(_Handle, AOCSPRef.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLOCSPRefs::Add(TElXMLOCSPRef *AOCSPRef)
{
	int32_t OutResult;
	SBCheckError(TElXMLOCSPRefs_Add(_Handle, (AOCSPRef != NULL) ? AOCSPRef->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLOCSPREF */

#ifdef SB_USE_CLASS_TELXMLOCSPREF
SB_INLINE void TElXMLOCSPRefs::Insert(int32_t Index, TElXMLOCSPRef &AOCSPRef)
{
	SBCheckError(TElXMLOCSPRefs_Insert(_Handle, Index, AOCSPRef.getHandle()));
}

SB_INLINE void TElXMLOCSPRefs::Insert(int32_t Index, TElXMLOCSPRef *AOCSPRef)
{
	SBCheckError(TElXMLOCSPRefs_Insert(_Handle, Index, (AOCSPRef != NULL) ? AOCSPRef->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLOCSPREF */

SB_INLINE void TElXMLOCSPRefs::Delete(int32_t Index)
{
	SBCheckError(TElXMLOCSPRefs_Delete(_Handle, Index));
}

SB_INLINE void TElXMLOCSPRefs::Clear()
{
	SBCheckError(TElXMLOCSPRefs_Clear(_Handle));
}

SB_INLINE int32_t TElXMLOCSPRefs::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLOCSPRefs_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLOCSPREF
TElXMLOCSPRef* TElXMLOCSPRefs::get_OCSPRef(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLOCSPRefs_get_OCSPRef(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OCSPRef)
		this->_Inst_OCSPRef = new TElXMLOCSPRef(hOutResult, ohFalse);
	else
		this->_Inst_OCSPRef->updateHandle(hOutResult);
	return this->_Inst_OCSPRef;
}
#endif /* SB_USE_CLASS_TELXMLOCSPREF */

void TElXMLOCSPRefs::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLOCSPREF
	this->_Inst_OCSPRef = NULL;
#endif /* SB_USE_CLASS_TELXMLOCSPREF */
}

TElXMLOCSPRefs::TElXMLOCSPRefs(TElXMLOCSPRefsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElXMLOCSPRefs::TElXMLOCSPRefs() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLOCSPRefs_Create(&_Handle));
}

TElXMLOCSPRefs::~TElXMLOCSPRefs()
{
#ifdef SB_USE_CLASS_TELXMLOCSPREF
	delete this->_Inst_OCSPRef;
	this->_Inst_OCSPRef = NULL;
#endif /* SB_USE_CLASS_TELXMLOCSPREF */
}
#endif /* SB_USE_CLASS_TELXMLOCSPREFS */

#ifdef SB_USE_CLASS_TELXMLOTHERREF

TElXMLOtherRef::TElXMLOtherRef(TElXMLOtherRefHandle handle, TElOwnHandle ownHandle) : TElXMLAnyType(handle, ownHandle)
{
}

TElXMLOtherRef::TElXMLOtherRef(TSBXAdESVersion AVersion) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLOtherRef_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLOtherRef::TElXMLOtherRef(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLOtherRef_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLOtherRef::TElXMLOtherRef(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLOtherRef_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLOtherRef::TElXMLOtherRef(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLOtherRef_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLOtherRef::TElXMLOtherRef(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLOtherRef_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLOTHERREF */

#ifdef SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS

SB_INLINE void TElXMLCompleteRevocationRefs::Clear()
{
	SBCheckError(TElXMLCompleteRevocationRefs_Clear(_Handle));
}

bool TElXMLCompleteRevocationRefs::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLCompleteRevocationRefs_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLCompleteRevocationRefs::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLCompleteRevocationRefs_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLCompleteRevocationRefs::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLCompleteRevocationRefs_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLCompleteRevocationRefs::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCompleteRevocationRefs_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLCompleteRevocationRefs::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCompleteRevocationRefs_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLCompleteRevocationRefs::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLCompleteRevocationRefs_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1520742958, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLCompleteRevocationRefs::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLCompleteRevocationRefs_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1520742958, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLCompleteRevocationRefs::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLCompleteRevocationRefs_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLCompleteRevocationRefs::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLCompleteRevocationRefs_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLCRLREFS
TElXMLCRLRefs* TElXMLCompleteRevocationRefs::get_CRLRefs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCompleteRevocationRefs_get_CRLRefs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CRLRefs)
		this->_Inst_CRLRefs = new TElXMLCRLRefs(hOutResult, ohFalse);
	else
		this->_Inst_CRLRefs->updateHandle(hOutResult);
	return this->_Inst_CRLRefs;
}
#endif /* SB_USE_CLASS_TELXMLCRLREFS */

#ifdef SB_USE_CLASS_TELXMLOCSPREFS
TElXMLOCSPRefs* TElXMLCompleteRevocationRefs::get_OCSPRefs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCompleteRevocationRefs_get_OCSPRefs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OCSPRefs)
		this->_Inst_OCSPRefs = new TElXMLOCSPRefs(hOutResult, ohFalse);
	else
		this->_Inst_OCSPRefs->updateHandle(hOutResult);
	return this->_Inst_OCSPRefs;
}
#endif /* SB_USE_CLASS_TELXMLOCSPREFS */

#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
TElXMLAnyTypeList* TElXMLCompleteRevocationRefs::get_OtherRefs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCompleteRevocationRefs_get_OtherRefs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OtherRefs)
		this->_Inst_OtherRefs = new TElXMLAnyTypeList(hOutResult, ohFalse);
	else
		this->_Inst_OtherRefs->updateHandle(hOutResult);
	return this->_Inst_OtherRefs;
}
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */

void TElXMLCompleteRevocationRefs::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLCRLREFS
	this->_Inst_CRLRefs = NULL;
#endif /* SB_USE_CLASS_TELXMLCRLREFS */
#ifdef SB_USE_CLASS_TELXMLOCSPREFS
	this->_Inst_OCSPRefs = NULL;
#endif /* SB_USE_CLASS_TELXMLOCSPREFS */
#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
	this->_Inst_OtherRefs = NULL;
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */
}

TElXMLCompleteRevocationRefs::TElXMLCompleteRevocationRefs(TElXMLCompleteRevocationRefsHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLCompleteRevocationRefs::TElXMLCompleteRevocationRefs(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCompleteRevocationRefs_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLCompleteRevocationRefs::TElXMLCompleteRevocationRefs(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCompleteRevocationRefs_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLCompleteRevocationRefs::TElXMLCompleteRevocationRefs(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLCompleteRevocationRefs_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLCompleteRevocationRefs::TElXMLCompleteRevocationRefs(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCompleteRevocationRefs_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLCompleteRevocationRefs::TElXMLCompleteRevocationRefs(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLCompleteRevocationRefs_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLCompleteRevocationRefs::~TElXMLCompleteRevocationRefs()
{
#ifdef SB_USE_CLASS_TELXMLCRLREFS
	delete this->_Inst_CRLRefs;
	this->_Inst_CRLRefs = NULL;
#endif /* SB_USE_CLASS_TELXMLCRLREFS */
#ifdef SB_USE_CLASS_TELXMLOCSPREFS
	delete this->_Inst_OCSPRefs;
	this->_Inst_OCSPRefs = NULL;
#endif /* SB_USE_CLASS_TELXMLOCSPREFS */
#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
	delete this->_Inst_OtherRefs;
	this->_Inst_OtherRefs = NULL;
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */
}
#endif /* SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS */

#ifdef SB_USE_CLASS_TELXMLCERTIFICATEVALUES

SB_INLINE void TElXMLCertificateValues::Clear()
{
	SBCheckError(TElXMLCertificateValues_Clear(_Handle));
}

bool TElXMLCertificateValues::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLCertificateValues_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLCertificateValues::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLCertificateValues_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLCertificateValues::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLCertificateValues_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLCertificateValues::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCertificateValues_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLCertificateValues::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCertificateValues_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLCertificateValues::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLCertificateValues_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(497084481, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLCertificateValues::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLCertificateValues_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(497084481, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLCertificateValues::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLCertificateValues_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLCertificateValues::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLCertificateValues_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDX509CERTIFICATES
TElXMLEncapsulatedX509Certificates* TElXMLCertificateValues::get_EncapsulatedX509Certificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCertificateValues_get_EncapsulatedX509Certificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncapsulatedX509Certificates)
		this->_Inst_EncapsulatedX509Certificates = new TElXMLEncapsulatedX509Certificates(hOutResult, ohFalse);
	else
		this->_Inst_EncapsulatedX509Certificates->updateHandle(hOutResult);
	return this->_Inst_EncapsulatedX509Certificates;
}
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDX509CERTIFICATES */

#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
TElXMLAnyTypeList* TElXMLCertificateValues::get_OtherCertificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCertificateValues_get_OtherCertificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OtherCertificates)
		this->_Inst_OtherCertificates = new TElXMLAnyTypeList(hOutResult, ohFalse);
	else
		this->_Inst_OtherCertificates->updateHandle(hOutResult);
	return this->_Inst_OtherCertificates;
}
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */

void TElXMLCertificateValues::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDX509CERTIFICATES
	this->_Inst_EncapsulatedX509Certificates = NULL;
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDX509CERTIFICATES */
#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
	this->_Inst_OtherCertificates = NULL;
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */
}

TElXMLCertificateValues::TElXMLCertificateValues(TElXMLCertificateValuesHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLCertificateValues::TElXMLCertificateValues(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCertificateValues_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLCertificateValues::TElXMLCertificateValues(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCertificateValues_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLCertificateValues::TElXMLCertificateValues(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLCertificateValues_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLCertificateValues::TElXMLCertificateValues(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCertificateValues_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLCertificateValues::TElXMLCertificateValues(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLCertificateValues_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLCertificateValues::~TElXMLCertificateValues()
{
#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDX509CERTIFICATES
	delete this->_Inst_EncapsulatedX509Certificates;
	this->_Inst_EncapsulatedX509Certificates = NULL;
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDX509CERTIFICATES */
#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
	delete this->_Inst_OtherCertificates;
	this->_Inst_OtherCertificates = NULL;
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */
}
#endif /* SB_USE_CLASS_TELXMLCERTIFICATEVALUES */

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDCRLVALUE

TElXMLEncapsulatedCRLValue::TElXMLEncapsulatedCRLValue(TElXMLEncapsulatedCRLValueHandle handle, TElOwnHandle ownHandle) : TElXMLEncapsulatedPKIData(handle, ownHandle)
{
}

TElXMLEncapsulatedCRLValue::TElXMLEncapsulatedCRLValue(TSBXAdESVersion AVersion) : TElXMLEncapsulatedPKIData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLEncapsulatedCRLValue_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLEncapsulatedCRLValue::TElXMLEncapsulatedCRLValue(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLEncapsulatedPKIData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLEncapsulatedCRLValue_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLEncapsulatedCRLValue::TElXMLEncapsulatedCRLValue(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLEncapsulatedPKIData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLEncapsulatedCRLValue_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLEncapsulatedCRLValue::TElXMLEncapsulatedCRLValue(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLEncapsulatedPKIData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLEncapsulatedCRLValue_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLEncapsulatedCRLValue::TElXMLEncapsulatedCRLValue(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLEncapsulatedPKIData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLEncapsulatedCRLValue_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDCRLVALUE */

#ifdef SB_USE_CLASS_TELXMLCRLVALUES

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
SB_INLINE int32_t TElXMLCRLValues::AddCRL(TElCertificateRevocationList &ACRL, TSBXAdESVersion AXAdESVersion)
{
	int32_t OutResult;
	SBCheckError(TElXMLCRLValues_AddCRL(_Handle, ACRL.getHandle(), (TSBXAdESVersionRaw)AXAdESVersion, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLCRLValues::AddCRL(TElCertificateRevocationList *ACRL, TSBXAdESVersion AXAdESVersion)
{
	int32_t OutResult;
	SBCheckError(TElXMLCRLValues_AddCRL(_Handle, (ACRL != NULL) ? ACRL->getHandle() : SB_NULL_HANDLE, (TSBXAdESVersionRaw)AXAdESVersion, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

SB_INLINE void TElXMLCRLValues::Clear()
{
	SBCheckError(TElXMLCRLValues_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
TElCertificateRevocationList* TElXMLCRLValues::get_CRLs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCRLValues_get_CRLs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CRLs)
		this->_Inst_CRLs = new TElCertificateRevocationList(hOutResult, ohFalse);
	else
		this->_Inst_CRLs->updateHandle(hOutResult);
	return this->_Inst_CRLs;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

void TElXMLCRLValues::initInstances()
{
#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
	this->_Inst_CRLs = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */
}

TElXMLCRLValues::TElXMLCRLValues(TElXMLCRLValuesHandle handle, TElOwnHandle ownHandle) : TElXMLEncapsulatedPKIDataList(handle, ownHandle)
{
	initInstances();
}

TElXMLCRLValues::TElXMLCRLValues() : TElXMLEncapsulatedPKIDataList(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCRLValues_Create(&_Handle));
}

TElXMLCRLValues::~TElXMLCRLValues()
{
#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
	delete this->_Inst_CRLs;
	this->_Inst_CRLs = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */
}
#endif /* SB_USE_CLASS_TELXMLCRLVALUES */

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDOCSPVALUE

TElXMLEncapsulatedOCSPValue::TElXMLEncapsulatedOCSPValue(TElXMLEncapsulatedOCSPValueHandle handle, TElOwnHandle ownHandle) : TElXMLEncapsulatedPKIData(handle, ownHandle)
{
}

TElXMLEncapsulatedOCSPValue::TElXMLEncapsulatedOCSPValue(TSBXAdESVersion AVersion) : TElXMLEncapsulatedPKIData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLEncapsulatedOCSPValue_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLEncapsulatedOCSPValue::TElXMLEncapsulatedOCSPValue(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLEncapsulatedPKIData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLEncapsulatedOCSPValue_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLEncapsulatedOCSPValue::TElXMLEncapsulatedOCSPValue(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLEncapsulatedPKIData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLEncapsulatedOCSPValue_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLEncapsulatedOCSPValue::TElXMLEncapsulatedOCSPValue(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLEncapsulatedPKIData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLEncapsulatedOCSPValue_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLEncapsulatedOCSPValue::TElXMLEncapsulatedOCSPValue(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLEncapsulatedPKIData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLEncapsulatedOCSPValue_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDOCSPVALUE */

#ifdef SB_USE_CLASS_TELXMLOCSPVALUES

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
SB_INLINE int32_t TElXMLOCSPValues::AddOCSPResponse(TElOCSPResponse &AOCSPResponse, TSBXAdESVersion AXAdESVersion)
{
	int32_t OutResult;
	SBCheckError(TElXMLOCSPValues_AddOCSPResponse(_Handle, AOCSPResponse.getHandle(), (TSBXAdESVersionRaw)AXAdESVersion, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLOCSPValues::AddOCSPResponse(TElOCSPResponse *AOCSPResponse, TSBXAdESVersion AXAdESVersion)
{
	int32_t OutResult;
	SBCheckError(TElXMLOCSPValues_AddOCSPResponse(_Handle, (AOCSPResponse != NULL) ? AOCSPResponse->getHandle() : SB_NULL_HANDLE, (TSBXAdESVersionRaw)AXAdESVersion, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

SB_INLINE void TElXMLOCSPValues::Clear()
{
	SBCheckError(TElXMLOCSPValues_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
TElOCSPResponse* TElXMLOCSPValues::get_OCSPResponses(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLOCSPValues_get_OCSPResponses(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OCSPResponses)
		this->_Inst_OCSPResponses = new TElOCSPResponse(hOutResult, ohFalse);
	else
		this->_Inst_OCSPResponses->updateHandle(hOutResult);
	return this->_Inst_OCSPResponses;
}
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

void TElXMLOCSPValues::initInstances()
{
#ifdef SB_USE_CLASS_TELOCSPRESPONSE
	this->_Inst_OCSPResponses = NULL;
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */
}

TElXMLOCSPValues::TElXMLOCSPValues(TElXMLOCSPValuesHandle handle, TElOwnHandle ownHandle) : TElXMLEncapsulatedPKIDataList(handle, ownHandle)
{
	initInstances();
}

TElXMLOCSPValues::TElXMLOCSPValues() : TElXMLEncapsulatedPKIDataList(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLOCSPValues_Create(&_Handle));
}

TElXMLOCSPValues::~TElXMLOCSPValues()
{
#ifdef SB_USE_CLASS_TELOCSPRESPONSE
	delete this->_Inst_OCSPResponses;
	this->_Inst_OCSPResponses = NULL;
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */
}
#endif /* SB_USE_CLASS_TELXMLOCSPVALUES */

#ifdef SB_USE_CLASS_TELXMLREVOCATIONVALUES

SB_INLINE void TElXMLRevocationValues::Clear()
{
	SBCheckError(TElXMLRevocationValues_Clear(_Handle));
}

bool TElXMLRevocationValues::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLRevocationValues_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLRevocationValues::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLRevocationValues_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLRevocationValues::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLRevocationValues_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLRevocationValues::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLRevocationValues_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLRevocationValues::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLRevocationValues_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLRevocationValues::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLRevocationValues_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(186450251, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLRevocationValues::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLRevocationValues_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(186450251, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLRevocationValues::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLRevocationValues_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLRevocationValues::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLRevocationValues_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLCRLVALUES
TElXMLCRLValues* TElXMLRevocationValues::get_CRLValues()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLRevocationValues_get_CRLValues(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CRLValues)
		this->_Inst_CRLValues = new TElXMLCRLValues(hOutResult, ohFalse);
	else
		this->_Inst_CRLValues->updateHandle(hOutResult);
	return this->_Inst_CRLValues;
}
#endif /* SB_USE_CLASS_TELXMLCRLVALUES */

#ifdef SB_USE_CLASS_TELXMLOCSPVALUES
TElXMLOCSPValues* TElXMLRevocationValues::get_OCSPValues()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLRevocationValues_get_OCSPValues(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OCSPValues)
		this->_Inst_OCSPValues = new TElXMLOCSPValues(hOutResult, ohFalse);
	else
		this->_Inst_OCSPValues->updateHandle(hOutResult);
	return this->_Inst_OCSPValues;
}
#endif /* SB_USE_CLASS_TELXMLOCSPVALUES */

#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
TElXMLAnyTypeList* TElXMLRevocationValues::get_OtherValues()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLRevocationValues_get_OtherValues(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OtherValues)
		this->_Inst_OtherValues = new TElXMLAnyTypeList(hOutResult, ohFalse);
	else
		this->_Inst_OtherValues->updateHandle(hOutResult);
	return this->_Inst_OtherValues;
}
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */

void TElXMLRevocationValues::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLCRLVALUES
	this->_Inst_CRLValues = NULL;
#endif /* SB_USE_CLASS_TELXMLCRLVALUES */
#ifdef SB_USE_CLASS_TELXMLOCSPVALUES
	this->_Inst_OCSPValues = NULL;
#endif /* SB_USE_CLASS_TELXMLOCSPVALUES */
#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
	this->_Inst_OtherValues = NULL;
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */
}

TElXMLRevocationValues::TElXMLRevocationValues(TElXMLRevocationValuesHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLRevocationValues::TElXMLRevocationValues(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLRevocationValues_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLRevocationValues::TElXMLRevocationValues(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLRevocationValues_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLRevocationValues::TElXMLRevocationValues(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLRevocationValues_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLRevocationValues::TElXMLRevocationValues(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLRevocationValues_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLRevocationValues::TElXMLRevocationValues(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLRevocationValues_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLRevocationValues::~TElXMLRevocationValues()
{
#ifdef SB_USE_CLASS_TELXMLCRLVALUES
	delete this->_Inst_CRLValues;
	this->_Inst_CRLValues = NULL;
#endif /* SB_USE_CLASS_TELXMLCRLVALUES */
#ifdef SB_USE_CLASS_TELXMLOCSPVALUES
	delete this->_Inst_OCSPValues;
	this->_Inst_OCSPValues = NULL;
#endif /* SB_USE_CLASS_TELXMLOCSPVALUES */
#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
	delete this->_Inst_OtherValues;
	this->_Inst_OtherValues = NULL;
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */
}
#endif /* SB_USE_CLASS_TELXMLREVOCATIONVALUES */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA

SB_INLINE void TElXMLTimeStampValidationData::Clear()
{
	SBCheckError(TElXMLTimeStampValidationData_Clear(_Handle));
}

bool TElXMLTimeStampValidationData::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLTimeStampValidationData_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLTimeStampValidationData::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLTimeStampValidationData_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLTimeStampValidationData::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLTimeStampValidationData_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLTimeStampValidationData::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLTimeStampValidationData_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLTimeStampValidationData::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLTimeStampValidationData_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLTimeStampValidationData::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLTimeStampValidationData_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1589131858, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLTimeStampValidationData::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLTimeStampValidationData_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1589131858, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLTimeStampValidationData::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLTimeStampValidationData_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLTimeStampValidationData::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLTimeStampValidationData_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLTimeStampValidationData::get_URI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLTimeStampValidationData_get_URI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(929816541, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLTimeStampValidationData::get_URI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLTimeStampValidationData_get_URI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(929816541, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLTimeStampValidationData::set_URI(const sb_u16string &Value)
{
	SBCheckError(TElXMLTimeStampValidationData_set_URI(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLTimeStampValidationData::set_URI(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLTimeStampValidationData_set_URI(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLCERTIFICATEVALUES
TElXMLCertificateValues* TElXMLTimeStampValidationData::get_CertificateValues()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLTimeStampValidationData_get_CertificateValues(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertificateValues)
		this->_Inst_CertificateValues = new TElXMLCertificateValues(hOutResult, ohFalse);
	else
		this->_Inst_CertificateValues->updateHandle(hOutResult);
	return this->_Inst_CertificateValues;
}

SB_INLINE void TElXMLTimeStampValidationData::set_CertificateValues(TElXMLCertificateValues &Value)
{
	SBCheckError(TElXMLTimeStampValidationData_set_CertificateValues(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLTimeStampValidationData::set_CertificateValues(TElXMLCertificateValues *Value)
{
	SBCheckError(TElXMLTimeStampValidationData_set_CertificateValues(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLCERTIFICATEVALUES */

#ifdef SB_USE_CLASS_TELXMLREVOCATIONVALUES
TElXMLRevocationValues* TElXMLTimeStampValidationData::get_RevocationValues()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLTimeStampValidationData_get_RevocationValues(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RevocationValues)
		this->_Inst_RevocationValues = new TElXMLRevocationValues(hOutResult, ohFalse);
	else
		this->_Inst_RevocationValues->updateHandle(hOutResult);
	return this->_Inst_RevocationValues;
}

SB_INLINE void TElXMLTimeStampValidationData::set_RevocationValues(TElXMLRevocationValues &Value)
{
	SBCheckError(TElXMLTimeStampValidationData_set_RevocationValues(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLTimeStampValidationData::set_RevocationValues(TElXMLRevocationValues *Value)
{
	SBCheckError(TElXMLTimeStampValidationData_set_RevocationValues(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLREVOCATIONVALUES */

void TElXMLTimeStampValidationData::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLCERTIFICATEVALUES
	this->_Inst_CertificateValues = NULL;
#endif /* SB_USE_CLASS_TELXMLCERTIFICATEVALUES */
#ifdef SB_USE_CLASS_TELXMLREVOCATIONVALUES
	this->_Inst_RevocationValues = NULL;
#endif /* SB_USE_CLASS_TELXMLREVOCATIONVALUES */
}

TElXMLTimeStampValidationData::TElXMLTimeStampValidationData(TElXMLTimeStampValidationDataHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLTimeStampValidationData::TElXMLTimeStampValidationData(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLTimeStampValidationData_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLTimeStampValidationData::TElXMLTimeStampValidationData(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLTimeStampValidationData_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLTimeStampValidationData::TElXMLTimeStampValidationData(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLTimeStampValidationData_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLTimeStampValidationData::TElXMLTimeStampValidationData(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLTimeStampValidationData_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLTimeStampValidationData::TElXMLTimeStampValidationData(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLTimeStampValidationData_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLTimeStampValidationData::~TElXMLTimeStampValidationData()
{
#ifdef SB_USE_CLASS_TELXMLCERTIFICATEVALUES
	delete this->_Inst_CertificateValues;
	this->_Inst_CertificateValues = NULL;
#endif /* SB_USE_CLASS_TELXMLCERTIFICATEVALUES */
#ifdef SB_USE_CLASS_TELXMLREVOCATIONVALUES
	delete this->_Inst_RevocationValues;
	this->_Inst_RevocationValues = NULL;
#endif /* SB_USE_CLASS_TELXMLREVOCATIONVALUES */
}
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST

#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA
SB_INLINE int32_t TElXMLTimeStampValidationDataList::Add(TElXMLTimeStampValidationData &ATSPValidationData)
{
	int32_t OutResult;
	SBCheckError(TElXMLTimeStampValidationDataList_Add(_Handle, ATSPValidationData.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLTimeStampValidationDataList::Add(TElXMLTimeStampValidationData *ATSPValidationData)
{
	int32_t OutResult;
	SBCheckError(TElXMLTimeStampValidationDataList_Add(_Handle, (ATSPValidationData != NULL) ? ATSPValidationData->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA
SB_INLINE void TElXMLTimeStampValidationDataList::Insert(int32_t Index, TElXMLTimeStampValidationData &ATSPValidationData)
{
	SBCheckError(TElXMLTimeStampValidationDataList_Insert(_Handle, Index, ATSPValidationData.getHandle()));
}

SB_INLINE void TElXMLTimeStampValidationDataList::Insert(int32_t Index, TElXMLTimeStampValidationData *ATSPValidationData)
{
	SBCheckError(TElXMLTimeStampValidationDataList_Insert(_Handle, Index, (ATSPValidationData != NULL) ? ATSPValidationData->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA */

SB_INLINE void TElXMLTimeStampValidationDataList::Delete(int32_t Index)
{
	SBCheckError(TElXMLTimeStampValidationDataList_Delete(_Handle, Index));
}

SB_INLINE void TElXMLTimeStampValidationDataList::Clear()
{
	SBCheckError(TElXMLTimeStampValidationDataList_Clear(_Handle));
}

SB_INLINE int32_t TElXMLTimeStampValidationDataList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLTimeStampValidationDataList_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA
TElXMLTimeStampValidationData* TElXMLTimeStampValidationDataList::get_TimeStampValidationData(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLTimeStampValidationDataList_get_TimeStampValidationData(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TimeStampValidationData)
		this->_Inst_TimeStampValidationData = new TElXMLTimeStampValidationData(hOutResult, ohFalse);
	else
		this->_Inst_TimeStampValidationData->updateHandle(hOutResult);
	return this->_Inst_TimeStampValidationData;
}
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA */

void TElXMLTimeStampValidationDataList::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA
	this->_Inst_TimeStampValidationData = NULL;
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA */
}

TElXMLTimeStampValidationDataList::TElXMLTimeStampValidationDataList(TElXMLTimeStampValidationDataListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElXMLTimeStampValidationDataList::TElXMLTimeStampValidationDataList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLTimeStampValidationDataList_Create(&_Handle));
}

TElXMLTimeStampValidationDataList::~TElXMLTimeStampValidationDataList()
{
#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA
	delete this->_Inst_TimeStampValidationData;
	this->_Inst_TimeStampValidationData = NULL;
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA */
}
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST */

#ifdef SB_USE_CLASS_TELXMLSIGNEDDATAOBJECTPROPERTIES

SB_INLINE void TElXMLSignedDataObjectProperties::Clear()
{
	SBCheckError(TElXMLSignedDataObjectProperties_Clear(_Handle));
}

bool TElXMLSignedDataObjectProperties::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLSignedDataObjectProperties_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSignedDataObjectProperties::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSignedDataObjectProperties_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSignedDataObjectProperties::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSignedDataObjectProperties_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLSignedDataObjectProperties::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSignedDataObjectProperties_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLSignedDataObjectProperties::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSignedDataObjectProperties_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDATAOBJECTFORMATLIST
TElXMLDataObjectFormatList* TElXMLSignedDataObjectProperties::get_DataObjectFormats()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignedDataObjectProperties_get_DataObjectFormats(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DataObjectFormats)
		this->_Inst_DataObjectFormats = new TElXMLDataObjectFormatList(hOutResult, ohFalse);
	else
		this->_Inst_DataObjectFormats->updateHandle(hOutResult);
	return this->_Inst_DataObjectFormats;
}
#endif /* SB_USE_CLASS_TELXMLDATAOBJECTFORMATLIST */

#ifdef SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATIONLIST
TElXMLCommitmentTypeIndicationList* TElXMLSignedDataObjectProperties::get_CommitmentTypeIndications()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignedDataObjectProperties_get_CommitmentTypeIndications(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CommitmentTypeIndications)
		this->_Inst_CommitmentTypeIndications = new TElXMLCommitmentTypeIndicationList(hOutResult, ohFalse);
	else
		this->_Inst_CommitmentTypeIndications->updateHandle(hOutResult);
	return this->_Inst_CommitmentTypeIndications;
}
#endif /* SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATIONLIST */

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
TElXMLCustomTimestampList* TElXMLSignedDataObjectProperties::get_AllDataObjectsTimestamps()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignedDataObjectProperties_get_AllDataObjectsTimestamps(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AllDataObjectsTimestamps)
		this->_Inst_AllDataObjectsTimestamps = new TElXMLCustomTimestampList(hOutResult, ohFalse);
	else
		this->_Inst_AllDataObjectsTimestamps->updateHandle(hOutResult);
	return this->_Inst_AllDataObjectsTimestamps;
}
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
TElXMLCustomTimestampList* TElXMLSignedDataObjectProperties::get_IndividualDataObjectsTimestamps()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignedDataObjectProperties_get_IndividualDataObjectsTimestamps(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IndividualDataObjectsTimestamps)
		this->_Inst_IndividualDataObjectsTimestamps = new TElXMLCustomTimestampList(hOutResult, ohFalse);
	else
		this->_Inst_IndividualDataObjectsTimestamps->updateHandle(hOutResult);
	return this->_Inst_IndividualDataObjectsTimestamps;
}
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */

void TElXMLSignedDataObjectProperties::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSignedDataObjectProperties_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(14823178, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSignedDataObjectProperties::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSignedDataObjectProperties_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(14823178, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSignedDataObjectProperties::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLSignedDataObjectProperties_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSignedDataObjectProperties::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSignedDataObjectProperties_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSignedDataObjectProperties::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDATAOBJECTFORMATLIST
	this->_Inst_DataObjectFormats = NULL;
#endif /* SB_USE_CLASS_TELXMLDATAOBJECTFORMATLIST */
#ifdef SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATIONLIST
	this->_Inst_CommitmentTypeIndications = NULL;
#endif /* SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATIONLIST */
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
	this->_Inst_AllDataObjectsTimestamps = NULL;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
	this->_Inst_IndividualDataObjectsTimestamps = NULL;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */
}

TElXMLSignedDataObjectProperties::TElXMLSignedDataObjectProperties(TElXMLSignedDataObjectPropertiesHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLSignedDataObjectProperties::TElXMLSignedDataObjectProperties(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSignedDataObjectProperties_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLSignedDataObjectProperties::TElXMLSignedDataObjectProperties(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSignedDataObjectProperties_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSignedDataObjectProperties::TElXMLSignedDataObjectProperties(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSignedDataObjectProperties_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLSignedDataObjectProperties::TElXMLSignedDataObjectProperties(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSignedDataObjectProperties_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSignedDataObjectProperties::TElXMLSignedDataObjectProperties(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSignedDataObjectProperties_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLSignedDataObjectProperties::~TElXMLSignedDataObjectProperties()
{
#ifdef SB_USE_CLASS_TELXMLDATAOBJECTFORMATLIST
	delete this->_Inst_DataObjectFormats;
	this->_Inst_DataObjectFormats = NULL;
#endif /* SB_USE_CLASS_TELXMLDATAOBJECTFORMATLIST */
#ifdef SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATIONLIST
	delete this->_Inst_CommitmentTypeIndications;
	this->_Inst_CommitmentTypeIndications = NULL;
#endif /* SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATIONLIST */
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
	delete this->_Inst_AllDataObjectsTimestamps;
	this->_Inst_AllDataObjectsTimestamps = NULL;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
	delete this->_Inst_IndividualDataObjectsTimestamps;
	this->_Inst_IndividualDataObjectsTimestamps = NULL;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */
}
#endif /* SB_USE_CLASS_TELXMLSIGNEDDATAOBJECTPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLUNSIGNEDDATAOBJECTPROPERTY

TElXMLUnsignedDataObjectProperty::TElXMLUnsignedDataObjectProperty(TElXMLUnsignedDataObjectPropertyHandle handle, TElOwnHandle ownHandle) : TElXMLAnyType(handle, ownHandle)
{
}

TElXMLUnsignedDataObjectProperty::TElXMLUnsignedDataObjectProperty(TSBXAdESVersion AVersion) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLUnsignedDataObjectProperty_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLUnsignedDataObjectProperty::TElXMLUnsignedDataObjectProperty(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLUnsignedDataObjectProperty_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLUnsignedDataObjectProperty::TElXMLUnsignedDataObjectProperty(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLUnsignedDataObjectProperty_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLUnsignedDataObjectProperty::TElXMLUnsignedDataObjectProperty(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLUnsignedDataObjectProperty_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLUnsignedDataObjectProperty::TElXMLUnsignedDataObjectProperty(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAnyType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLUnsignedDataObjectProperty_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLUNSIGNEDDATAOBJECTPROPERTY */

#ifdef SB_USE_CLASS_TELXMLSIGNEDSIGNATUREPROPERTIES

SB_INLINE void TElXMLSignedSignatureProperties::Clear()
{
	SBCheckError(TElXMLSignedSignatureProperties_Clear(_Handle));
}

bool TElXMLSignedSignatureProperties::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLSignedSignatureProperties_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSignedSignatureProperties::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSignedSignatureProperties_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSignedSignatureProperties::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSignedSignatureProperties_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLSignedSignatureProperties::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSignedSignatureProperties_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLSignedSignatureProperties::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSignedSignatureProperties_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLSignedSignatureProperties::get_SignedTime(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSignedSignatureProperties_get_SignedTime(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-562584946, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSignedSignatureProperties::get_SignedTime(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSignedSignatureProperties_get_SignedTime(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-562584946, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSignedSignatureProperties::set_SignedTime(const sb_u16string &Value)
{
	SBCheckError(TElXMLSignedSignatureProperties_set_SignedTime(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSignedSignatureProperties::set_SignedTime(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSignedSignatureProperties_set_SignedTime(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE int64_t TElXMLSignedSignatureProperties::get_SignedTimeUTC()
{
	int64_t OutResult;
	SBCheckError(TElXMLSignedSignatureProperties_get_SignedTimeUTC(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLSignedSignatureProperties::set_SignedTimeUTC(int64_t Value)
{
	SBCheckError(TElXMLSignedSignatureProperties_set_SignedTimeUTC(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELXMLCERTIDLIST
TElXMLCertIDList* TElXMLSignedSignatureProperties::get_SigningCertificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignedSignatureProperties_get_SigningCertificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SigningCertificate)
		this->_Inst_SigningCertificate = new TElXMLCertIDList(hOutResult, ohFalse);
	else
		this->_Inst_SigningCertificate->updateHandle(hOutResult);
	return this->_Inst_SigningCertificate;
}
#endif /* SB_USE_CLASS_TELXMLCERTIDLIST */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYIDENTIFIER
TElXMLSignaturePolicyIdentifier* TElXMLSignedSignatureProperties::get_SignaturePolicyIdentifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignedSignatureProperties_get_SignaturePolicyIdentifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignaturePolicyIdentifier)
		this->_Inst_SignaturePolicyIdentifier = new TElXMLSignaturePolicyIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_SignaturePolicyIdentifier->updateHandle(hOutResult);
	return this->_Inst_SignaturePolicyIdentifier;
}
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYIDENTIFIER */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE
TElXMLSignatureProductionPlace* TElXMLSignedSignatureProperties::get_SignatureProductionPlace()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignedSignatureProperties_get_SignatureProductionPlace(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureProductionPlace)
		this->_Inst_SignatureProductionPlace = new TElXMLSignatureProductionPlace(hOutResult, ohFalse);
	else
		this->_Inst_SignatureProductionPlace->updateHandle(hOutResult);
	return this->_Inst_SignatureProductionPlace;
}

SB_INLINE void TElXMLSignedSignatureProperties::set_SignatureProductionPlace(TElXMLSignatureProductionPlace &Value)
{
	SBCheckError(TElXMLSignedSignatureProperties_set_SignatureProductionPlace(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLSignedSignatureProperties::set_SignatureProductionPlace(TElXMLSignatureProductionPlace *Value)
{
	SBCheckError(TElXMLSignedSignatureProperties_set_SignatureProductionPlace(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE */

#ifdef SB_USE_CLASS_TELXMLSIGNERROLE
TElXMLSignerRole* TElXMLSignedSignatureProperties::get_SignerRole()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignedSignatureProperties_get_SignerRole(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignerRole)
		this->_Inst_SignerRole = new TElXMLSignerRole(hOutResult, ohFalse);
	else
		this->_Inst_SignerRole->updateHandle(hOutResult);
	return this->_Inst_SignerRole;
}

SB_INLINE void TElXMLSignedSignatureProperties::set_SignerRole(TElXMLSignerRole &Value)
{
	SBCheckError(TElXMLSignedSignatureProperties_set_SignerRole(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLSignedSignatureProperties::set_SignerRole(TElXMLSignerRole *Value)
{
	SBCheckError(TElXMLSignedSignatureProperties_set_SignerRole(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLSIGNERROLE */

void TElXMLSignedSignatureProperties::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSignedSignatureProperties_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-2067825072, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSignedSignatureProperties::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSignedSignatureProperties_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-2067825072, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSignedSignatureProperties::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLSignedSignatureProperties_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSignedSignatureProperties::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSignedSignatureProperties_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSignedSignatureProperties::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLCERTIDLIST
	this->_Inst_SigningCertificate = NULL;
#endif /* SB_USE_CLASS_TELXMLCERTIDLIST */
#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYIDENTIFIER
	this->_Inst_SignaturePolicyIdentifier = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYIDENTIFIER */
#ifdef SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE
	this->_Inst_SignatureProductionPlace = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE */
#ifdef SB_USE_CLASS_TELXMLSIGNERROLE
	this->_Inst_SignerRole = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNERROLE */
}

TElXMLSignedSignatureProperties::TElXMLSignedSignatureProperties(TElXMLSignedSignaturePropertiesHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLSignedSignatureProperties::TElXMLSignedSignatureProperties(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSignedSignatureProperties_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLSignedSignatureProperties::TElXMLSignedSignatureProperties(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSignedSignatureProperties_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSignedSignatureProperties::TElXMLSignedSignatureProperties(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSignedSignatureProperties_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLSignedSignatureProperties::TElXMLSignedSignatureProperties(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSignedSignatureProperties_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSignedSignatureProperties::TElXMLSignedSignatureProperties(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSignedSignatureProperties_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLSignedSignatureProperties::~TElXMLSignedSignatureProperties()
{
#ifdef SB_USE_CLASS_TELXMLCERTIDLIST
	delete this->_Inst_SigningCertificate;
	this->_Inst_SigningCertificate = NULL;
#endif /* SB_USE_CLASS_TELXMLCERTIDLIST */
#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYIDENTIFIER
	delete this->_Inst_SignaturePolicyIdentifier;
	this->_Inst_SignaturePolicyIdentifier = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYIDENTIFIER */
#ifdef SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE
	delete this->_Inst_SignatureProductionPlace;
	this->_Inst_SignatureProductionPlace = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE */
#ifdef SB_USE_CLASS_TELXMLSIGNERROLE
	delete this->_Inst_SignerRole;
	this->_Inst_SignerRole = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNERROLE */
}
#endif /* SB_USE_CLASS_TELXMLSIGNEDSIGNATUREPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLUNSIGNEDSIGNATUREPROPERTIES

SB_INLINE void TElXMLUnsignedSignatureProperties::Clear()
{
	SBCheckError(TElXMLUnsignedSignatureProperties_Clear(_Handle));
}

bool TElXMLUnsignedSignatureProperties::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLUnsignedSignatureProperties_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLUnsignedSignatureProperties::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLUnsignedSignatureProperties_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLUnsignedSignatureProperties::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLUnsignedSignatureProperties_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLUnsignedSignatureProperties::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLUnsignedSignatureProperties_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLUnsignedSignatureProperties::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLUnsignedSignatureProperties_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

TSBXAdESForm TElXMLUnsignedSignatureProperties::get_XAdESForm()
{
	TSBXAdESFormRaw OutResultRaw = 0;
	SBCheckError(TElXMLUnsignedSignatureProperties_get_XAdESForm(_Handle, &OutResultRaw));
	return (TSBXAdESForm)OutResultRaw;
}

SB_INLINE void TElXMLUnsignedSignatureProperties::set_XAdESForm(TSBXAdESForm Value)
{
	SBCheckError(TElXMLUnsignedSignatureProperties_set_XAdESForm(_Handle, (TSBXAdESFormRaw)Value));
}

void TElXMLUnsignedSignatureProperties::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLUnsignedSignatureProperties_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(2131752683, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLUnsignedSignatureProperties::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLUnsignedSignatureProperties_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(2131752683, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLUnsignedSignatureProperties::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLUnsignedSignatureProperties_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLUnsignedSignatureProperties::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLUnsignedSignatureProperties_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLCOUNTERSIGNATURELIST
TElXMLCounterSignatureList* TElXMLUnsignedSignatureProperties::get_CounterSignatures()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLUnsignedSignatureProperties_get_CounterSignatures(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CounterSignatures)
		this->_Inst_CounterSignatures = new TElXMLCounterSignatureList(hOutResult, ohFalse);
	else
		this->_Inst_CounterSignatures->updateHandle(hOutResult);
	return this->_Inst_CounterSignatures;
}
#endif /* SB_USE_CLASS_TELXMLCOUNTERSIGNATURELIST */

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
TElXMLCustomTimestampList* TElXMLUnsignedSignatureProperties::get_SignatureTimestamps()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLUnsignedSignatureProperties_get_SignatureTimestamps(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureTimestamps)
		this->_Inst_SignatureTimestamps = new TElXMLCustomTimestampList(hOutResult, ohFalse);
	else
		this->_Inst_SignatureTimestamps->updateHandle(hOutResult);
	return this->_Inst_SignatureTimestamps;
}
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */

#ifdef SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS
TElXMLCompleteCertificateRefs* TElXMLUnsignedSignatureProperties::get_CompleteCertificateRefs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLUnsignedSignatureProperties_get_CompleteCertificateRefs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CompleteCertificateRefs)
		this->_Inst_CompleteCertificateRefs = new TElXMLCompleteCertificateRefs(hOutResult, ohFalse);
	else
		this->_Inst_CompleteCertificateRefs->updateHandle(hOutResult);
	return this->_Inst_CompleteCertificateRefs;
}

SB_INLINE void TElXMLUnsignedSignatureProperties::set_CompleteCertificateRefs(TElXMLCompleteCertificateRefs &Value)
{
	SBCheckError(TElXMLUnsignedSignatureProperties_set_CompleteCertificateRefs(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLUnsignedSignatureProperties::set_CompleteCertificateRefs(TElXMLCompleteCertificateRefs *Value)
{
	SBCheckError(TElXMLUnsignedSignatureProperties_set_CompleteCertificateRefs(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS */

#ifdef SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS
TElXMLCompleteRevocationRefs* TElXMLUnsignedSignatureProperties::get_CompleteRevocationRefs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLUnsignedSignatureProperties_get_CompleteRevocationRefs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CompleteRevocationRefs)
		this->_Inst_CompleteRevocationRefs = new TElXMLCompleteRevocationRefs(hOutResult, ohFalse);
	else
		this->_Inst_CompleteRevocationRefs->updateHandle(hOutResult);
	return this->_Inst_CompleteRevocationRefs;
}

SB_INLINE void TElXMLUnsignedSignatureProperties::set_CompleteRevocationRefs(TElXMLCompleteRevocationRefs &Value)
{
	SBCheckError(TElXMLUnsignedSignatureProperties_set_CompleteRevocationRefs(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLUnsignedSignatureProperties::set_CompleteRevocationRefs(TElXMLCompleteRevocationRefs *Value)
{
	SBCheckError(TElXMLUnsignedSignatureProperties_set_CompleteRevocationRefs(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS */

#ifdef SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS
TElXMLCompleteCertificateRefs* TElXMLUnsignedSignatureProperties::get_AttributeCertificateRefs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLUnsignedSignatureProperties_get_AttributeCertificateRefs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AttributeCertificateRefs)
		this->_Inst_AttributeCertificateRefs = new TElXMLCompleteCertificateRefs(hOutResult, ohFalse);
	else
		this->_Inst_AttributeCertificateRefs->updateHandle(hOutResult);
	return this->_Inst_AttributeCertificateRefs;
}

SB_INLINE void TElXMLUnsignedSignatureProperties::set_AttributeCertificateRefs(TElXMLCompleteCertificateRefs &Value)
{
	SBCheckError(TElXMLUnsignedSignatureProperties_set_AttributeCertificateRefs(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLUnsignedSignatureProperties::set_AttributeCertificateRefs(TElXMLCompleteCertificateRefs *Value)
{
	SBCheckError(TElXMLUnsignedSignatureProperties_set_AttributeCertificateRefs(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS */

#ifdef SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS
TElXMLCompleteRevocationRefs* TElXMLUnsignedSignatureProperties::get_AttributeRevocationRefs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLUnsignedSignatureProperties_get_AttributeRevocationRefs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AttributeRevocationRefs)
		this->_Inst_AttributeRevocationRefs = new TElXMLCompleteRevocationRefs(hOutResult, ohFalse);
	else
		this->_Inst_AttributeRevocationRefs->updateHandle(hOutResult);
	return this->_Inst_AttributeRevocationRefs;
}

SB_INLINE void TElXMLUnsignedSignatureProperties::set_AttributeRevocationRefs(TElXMLCompleteRevocationRefs &Value)
{
	SBCheckError(TElXMLUnsignedSignatureProperties_set_AttributeRevocationRefs(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLUnsignedSignatureProperties::set_AttributeRevocationRefs(TElXMLCompleteRevocationRefs *Value)
{
	SBCheckError(TElXMLUnsignedSignatureProperties_set_AttributeRevocationRefs(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS */

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
TElXMLCustomTimestampList* TElXMLUnsignedSignatureProperties::get_SigAndRefsTimestamps()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLUnsignedSignatureProperties_get_SigAndRefsTimestamps(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SigAndRefsTimestamps)
		this->_Inst_SigAndRefsTimestamps = new TElXMLCustomTimestampList(hOutResult, ohFalse);
	else
		this->_Inst_SigAndRefsTimestamps->updateHandle(hOutResult);
	return this->_Inst_SigAndRefsTimestamps;
}
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
TElXMLCustomTimestampList* TElXMLUnsignedSignatureProperties::get_RefsOnlyTimestamps()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLUnsignedSignatureProperties_get_RefsOnlyTimestamps(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RefsOnlyTimestamps)
		this->_Inst_RefsOnlyTimestamps = new TElXMLCustomTimestampList(hOutResult, ohFalse);
	else
		this->_Inst_RefsOnlyTimestamps->updateHandle(hOutResult);
	return this->_Inst_RefsOnlyTimestamps;
}
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */

#ifdef SB_USE_CLASS_TELXMLCERTIFICATEVALUES
TElXMLCertificateValues* TElXMLUnsignedSignatureProperties::get_CertificateValues()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLUnsignedSignatureProperties_get_CertificateValues(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertificateValues)
		this->_Inst_CertificateValues = new TElXMLCertificateValues(hOutResult, ohFalse);
	else
		this->_Inst_CertificateValues->updateHandle(hOutResult);
	return this->_Inst_CertificateValues;
}

SB_INLINE void TElXMLUnsignedSignatureProperties::set_CertificateValues(TElXMLCertificateValues &Value)
{
	SBCheckError(TElXMLUnsignedSignatureProperties_set_CertificateValues(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLUnsignedSignatureProperties::set_CertificateValues(TElXMLCertificateValues *Value)
{
	SBCheckError(TElXMLUnsignedSignatureProperties_set_CertificateValues(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLCERTIFICATEVALUES */

#ifdef SB_USE_CLASS_TELXMLREVOCATIONVALUES
TElXMLRevocationValues* TElXMLUnsignedSignatureProperties::get_RevocationValues()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLUnsignedSignatureProperties_get_RevocationValues(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RevocationValues)
		this->_Inst_RevocationValues = new TElXMLRevocationValues(hOutResult, ohFalse);
	else
		this->_Inst_RevocationValues->updateHandle(hOutResult);
	return this->_Inst_RevocationValues;
}

SB_INLINE void TElXMLUnsignedSignatureProperties::set_RevocationValues(TElXMLRevocationValues &Value)
{
	SBCheckError(TElXMLUnsignedSignatureProperties_set_RevocationValues(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLUnsignedSignatureProperties::set_RevocationValues(TElXMLRevocationValues *Value)
{
	SBCheckError(TElXMLUnsignedSignatureProperties_set_RevocationValues(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLREVOCATIONVALUES */

#ifdef SB_USE_CLASS_TELXMLCERTIFICATEVALUES
TElXMLCertificateValues* TElXMLUnsignedSignatureProperties::get_AttrAuthoritiesCertValues()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLUnsignedSignatureProperties_get_AttrAuthoritiesCertValues(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AttrAuthoritiesCertValues)
		this->_Inst_AttrAuthoritiesCertValues = new TElXMLCertificateValues(hOutResult, ohFalse);
	else
		this->_Inst_AttrAuthoritiesCertValues->updateHandle(hOutResult);
	return this->_Inst_AttrAuthoritiesCertValues;
}

SB_INLINE void TElXMLUnsignedSignatureProperties::set_AttrAuthoritiesCertValues(TElXMLCertificateValues &Value)
{
	SBCheckError(TElXMLUnsignedSignatureProperties_set_AttrAuthoritiesCertValues(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLUnsignedSignatureProperties::set_AttrAuthoritiesCertValues(TElXMLCertificateValues *Value)
{
	SBCheckError(TElXMLUnsignedSignatureProperties_set_AttrAuthoritiesCertValues(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLCERTIFICATEVALUES */

#ifdef SB_USE_CLASS_TELXMLREVOCATIONVALUES
TElXMLRevocationValues* TElXMLUnsignedSignatureProperties::get_AttributeRevocationValues()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLUnsignedSignatureProperties_get_AttributeRevocationValues(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AttributeRevocationValues)
		this->_Inst_AttributeRevocationValues = new TElXMLRevocationValues(hOutResult, ohFalse);
	else
		this->_Inst_AttributeRevocationValues->updateHandle(hOutResult);
	return this->_Inst_AttributeRevocationValues;
}

SB_INLINE void TElXMLUnsignedSignatureProperties::set_AttributeRevocationValues(TElXMLRevocationValues &Value)
{
	SBCheckError(TElXMLUnsignedSignatureProperties_set_AttributeRevocationValues(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLUnsignedSignatureProperties::set_AttributeRevocationValues(TElXMLRevocationValues *Value)
{
	SBCheckError(TElXMLUnsignedSignatureProperties_set_AttributeRevocationValues(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLREVOCATIONVALUES */

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
TElXMLCustomTimestampList* TElXMLUnsignedSignatureProperties::get_ArchiveTimestamps()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLUnsignedSignatureProperties_get_ArchiveTimestamps(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ArchiveTimestamps)
		this->_Inst_ArchiveTimestamps = new TElXMLCustomTimestampList(hOutResult, ohFalse);
	else
		this->_Inst_ArchiveTimestamps->updateHandle(hOutResult);
	return this->_Inst_ArchiveTimestamps;
}
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
TElXMLCustomTimestampList* TElXMLUnsignedSignatureProperties::get_ArchiveTimestampsV141()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLUnsignedSignatureProperties_get_ArchiveTimestampsV141(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ArchiveTimestampsV141)
		this->_Inst_ArchiveTimestampsV141 = new TElXMLCustomTimestampList(hOutResult, ohFalse);
	else
		this->_Inst_ArchiveTimestampsV141->updateHandle(hOutResult);
	return this->_Inst_ArchiveTimestampsV141;
}
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST
TElXMLTimeStampValidationDataList* TElXMLUnsignedSignatureProperties::get_TimeStampValidationDataList()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLUnsignedSignatureProperties_get_TimeStampValidationDataList(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TimeStampValidationDataList)
		this->_Inst_TimeStampValidationDataList = new TElXMLTimeStampValidationDataList(hOutResult, ohFalse);
	else
		this->_Inst_TimeStampValidationDataList->updateHandle(hOutResult);
	return this->_Inst_TimeStampValidationDataList;
}
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST */

void TElXMLUnsignedSignatureProperties::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLCOUNTERSIGNATURELIST
	this->_Inst_CounterSignatures = NULL;
#endif /* SB_USE_CLASS_TELXMLCOUNTERSIGNATURELIST */
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
	this->_Inst_SignatureTimestamps = NULL;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */
#ifdef SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS
	this->_Inst_CompleteCertificateRefs = NULL;
#endif /* SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS */
#ifdef SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS
	this->_Inst_CompleteRevocationRefs = NULL;
#endif /* SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS */
#ifdef SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS
	this->_Inst_AttributeCertificateRefs = NULL;
#endif /* SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS */
#ifdef SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS
	this->_Inst_AttributeRevocationRefs = NULL;
#endif /* SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS */
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
	this->_Inst_SigAndRefsTimestamps = NULL;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
	this->_Inst_RefsOnlyTimestamps = NULL;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */
#ifdef SB_USE_CLASS_TELXMLCERTIFICATEVALUES
	this->_Inst_CertificateValues = NULL;
#endif /* SB_USE_CLASS_TELXMLCERTIFICATEVALUES */
#ifdef SB_USE_CLASS_TELXMLREVOCATIONVALUES
	this->_Inst_RevocationValues = NULL;
#endif /* SB_USE_CLASS_TELXMLREVOCATIONVALUES */
#ifdef SB_USE_CLASS_TELXMLCERTIFICATEVALUES
	this->_Inst_AttrAuthoritiesCertValues = NULL;
#endif /* SB_USE_CLASS_TELXMLCERTIFICATEVALUES */
#ifdef SB_USE_CLASS_TELXMLREVOCATIONVALUES
	this->_Inst_AttributeRevocationValues = NULL;
#endif /* SB_USE_CLASS_TELXMLREVOCATIONVALUES */
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
	this->_Inst_ArchiveTimestamps = NULL;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
	this->_Inst_ArchiveTimestampsV141 = NULL;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */
#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST
	this->_Inst_TimeStampValidationDataList = NULL;
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST */
}

TElXMLUnsignedSignatureProperties::TElXMLUnsignedSignatureProperties(TElXMLUnsignedSignaturePropertiesHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLUnsignedSignatureProperties::TElXMLUnsignedSignatureProperties(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLUnsignedSignatureProperties_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLUnsignedSignatureProperties::TElXMLUnsignedSignatureProperties(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLUnsignedSignatureProperties_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLUnsignedSignatureProperties::TElXMLUnsignedSignatureProperties(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLUnsignedSignatureProperties_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLUnsignedSignatureProperties::TElXMLUnsignedSignatureProperties(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLUnsignedSignatureProperties_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLUnsignedSignatureProperties::TElXMLUnsignedSignatureProperties(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLUnsignedSignatureProperties_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLUnsignedSignatureProperties::~TElXMLUnsignedSignatureProperties()
{
#ifdef SB_USE_CLASS_TELXMLCOUNTERSIGNATURELIST
	delete this->_Inst_CounterSignatures;
	this->_Inst_CounterSignatures = NULL;
#endif /* SB_USE_CLASS_TELXMLCOUNTERSIGNATURELIST */
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
	delete this->_Inst_SignatureTimestamps;
	this->_Inst_SignatureTimestamps = NULL;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */
#ifdef SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS
	delete this->_Inst_CompleteCertificateRefs;
	this->_Inst_CompleteCertificateRefs = NULL;
#endif /* SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS */
#ifdef SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS
	delete this->_Inst_CompleteRevocationRefs;
	this->_Inst_CompleteRevocationRefs = NULL;
#endif /* SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS */
#ifdef SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS
	delete this->_Inst_AttributeCertificateRefs;
	this->_Inst_AttributeCertificateRefs = NULL;
#endif /* SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS */
#ifdef SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS
	delete this->_Inst_AttributeRevocationRefs;
	this->_Inst_AttributeRevocationRefs = NULL;
#endif /* SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS */
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
	delete this->_Inst_SigAndRefsTimestamps;
	this->_Inst_SigAndRefsTimestamps = NULL;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
	delete this->_Inst_RefsOnlyTimestamps;
	this->_Inst_RefsOnlyTimestamps = NULL;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */
#ifdef SB_USE_CLASS_TELXMLCERTIFICATEVALUES
	delete this->_Inst_CertificateValues;
	this->_Inst_CertificateValues = NULL;
#endif /* SB_USE_CLASS_TELXMLCERTIFICATEVALUES */
#ifdef SB_USE_CLASS_TELXMLREVOCATIONVALUES
	delete this->_Inst_RevocationValues;
	this->_Inst_RevocationValues = NULL;
#endif /* SB_USE_CLASS_TELXMLREVOCATIONVALUES */
#ifdef SB_USE_CLASS_TELXMLCERTIFICATEVALUES
	delete this->_Inst_AttrAuthoritiesCertValues;
	this->_Inst_AttrAuthoritiesCertValues = NULL;
#endif /* SB_USE_CLASS_TELXMLCERTIFICATEVALUES */
#ifdef SB_USE_CLASS_TELXMLREVOCATIONVALUES
	delete this->_Inst_AttributeRevocationValues;
	this->_Inst_AttributeRevocationValues = NULL;
#endif /* SB_USE_CLASS_TELXMLREVOCATIONVALUES */
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
	delete this->_Inst_ArchiveTimestamps;
	this->_Inst_ArchiveTimestamps = NULL;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
	delete this->_Inst_ArchiveTimestampsV141;
	this->_Inst_ArchiveTimestampsV141 = NULL;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */
#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST
	delete this->_Inst_TimeStampValidationDataList;
	this->_Inst_TimeStampValidationDataList = NULL;
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST */
}
#endif /* SB_USE_CLASS_TELXMLUNSIGNEDSIGNATUREPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLSIGNEDPROPERTIES

SB_INLINE void TElXMLSignedProperties::Clear()
{
	SBCheckError(TElXMLSignedProperties_Clear(_Handle));
}

bool TElXMLSignedProperties::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLSignedProperties_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSignedProperties::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSignedProperties_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSignedProperties::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSignedProperties_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLSignedProperties::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSignedProperties_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLSignedProperties::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSignedProperties_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLSignedProperties::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSignedProperties_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(421465504, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSignedProperties::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSignedProperties_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(421465504, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSignedProperties::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLSignedProperties_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSignedProperties::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSignedProperties_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLSIGNEDSIGNATUREPROPERTIES
TElXMLSignedSignatureProperties* TElXMLSignedProperties::get_SignedSignatureProperties()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignedProperties_get_SignedSignatureProperties(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignedSignatureProperties)
		this->_Inst_SignedSignatureProperties = new TElXMLSignedSignatureProperties(hOutResult, ohFalse);
	else
		this->_Inst_SignedSignatureProperties->updateHandle(hOutResult);
	return this->_Inst_SignedSignatureProperties;
}

SB_INLINE void TElXMLSignedProperties::set_SignedSignatureProperties(TElXMLSignedSignatureProperties &Value)
{
	SBCheckError(TElXMLSignedProperties_set_SignedSignatureProperties(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLSignedProperties::set_SignedSignatureProperties(TElXMLSignedSignatureProperties *Value)
{
	SBCheckError(TElXMLSignedProperties_set_SignedSignatureProperties(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLSIGNEDSIGNATUREPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLSIGNEDDATAOBJECTPROPERTIES
TElXMLSignedDataObjectProperties* TElXMLSignedProperties::get_SignedDataObjectProperties()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignedProperties_get_SignedDataObjectProperties(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignedDataObjectProperties)
		this->_Inst_SignedDataObjectProperties = new TElXMLSignedDataObjectProperties(hOutResult, ohFalse);
	else
		this->_Inst_SignedDataObjectProperties->updateHandle(hOutResult);
	return this->_Inst_SignedDataObjectProperties;
}

SB_INLINE void TElXMLSignedProperties::set_SignedDataObjectProperties(TElXMLSignedDataObjectProperties &Value)
{
	SBCheckError(TElXMLSignedProperties_set_SignedDataObjectProperties(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLSignedProperties::set_SignedDataObjectProperties(TElXMLSignedDataObjectProperties *Value)
{
	SBCheckError(TElXMLSignedProperties_set_SignedDataObjectProperties(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLSIGNEDDATAOBJECTPROPERTIES */

void TElXMLSignedProperties::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLSIGNEDSIGNATUREPROPERTIES
	this->_Inst_SignedSignatureProperties = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNEDSIGNATUREPROPERTIES */
#ifdef SB_USE_CLASS_TELXMLSIGNEDDATAOBJECTPROPERTIES
	this->_Inst_SignedDataObjectProperties = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNEDDATAOBJECTPROPERTIES */
}

TElXMLSignedProperties::TElXMLSignedProperties(TElXMLSignedPropertiesHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLSignedProperties::TElXMLSignedProperties(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSignedProperties_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLSignedProperties::TElXMLSignedProperties(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSignedProperties_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSignedProperties::TElXMLSignedProperties(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSignedProperties_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLSignedProperties::TElXMLSignedProperties(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSignedProperties_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSignedProperties::TElXMLSignedProperties(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSignedProperties_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLSignedProperties::~TElXMLSignedProperties()
{
#ifdef SB_USE_CLASS_TELXMLSIGNEDSIGNATUREPROPERTIES
	delete this->_Inst_SignedSignatureProperties;
	this->_Inst_SignedSignatureProperties = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNEDSIGNATUREPROPERTIES */
#ifdef SB_USE_CLASS_TELXMLSIGNEDDATAOBJECTPROPERTIES
	delete this->_Inst_SignedDataObjectProperties;
	this->_Inst_SignedDataObjectProperties = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNEDDATAOBJECTPROPERTIES */
}
#endif /* SB_USE_CLASS_TELXMLSIGNEDPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLUNSIGNEDPROPERTIES

SB_INLINE void TElXMLUnsignedProperties::Clear()
{
	SBCheckError(TElXMLUnsignedProperties_Clear(_Handle));
}

bool TElXMLUnsignedProperties::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLUnsignedProperties_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLUnsignedProperties::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLUnsignedProperties_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLUnsignedProperties::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLUnsignedProperties_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLUnsignedProperties::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLUnsignedProperties_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLUnsignedProperties::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLUnsignedProperties_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLUnsignedProperties::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLUnsignedProperties_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(223308992, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLUnsignedProperties::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLUnsignedProperties_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(223308992, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLUnsignedProperties::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLUnsignedProperties_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLUnsignedProperties::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLUnsignedProperties_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLUNSIGNEDSIGNATUREPROPERTIES
TElXMLUnsignedSignatureProperties* TElXMLUnsignedProperties::get_UnsignedSignatureProperties()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLUnsignedProperties_get_UnsignedSignatureProperties(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_UnsignedSignatureProperties)
		this->_Inst_UnsignedSignatureProperties = new TElXMLUnsignedSignatureProperties(hOutResult, ohFalse);
	else
		this->_Inst_UnsignedSignatureProperties->updateHandle(hOutResult);
	return this->_Inst_UnsignedSignatureProperties;
}

SB_INLINE void TElXMLUnsignedProperties::set_UnsignedSignatureProperties(TElXMLUnsignedSignatureProperties &Value)
{
	SBCheckError(TElXMLUnsignedProperties_set_UnsignedSignatureProperties(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLUnsignedProperties::set_UnsignedSignatureProperties(TElXMLUnsignedSignatureProperties *Value)
{
	SBCheckError(TElXMLUnsignedProperties_set_UnsignedSignatureProperties(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLUNSIGNEDSIGNATUREPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
TElXMLAnyTypeList* TElXMLUnsignedProperties::get_UnsignedDataObjectProperties()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLUnsignedProperties_get_UnsignedDataObjectProperties(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_UnsignedDataObjectProperties)
		this->_Inst_UnsignedDataObjectProperties = new TElXMLAnyTypeList(hOutResult, ohFalse);
	else
		this->_Inst_UnsignedDataObjectProperties->updateHandle(hOutResult);
	return this->_Inst_UnsignedDataObjectProperties;
}
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */

void TElXMLUnsignedProperties::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLUNSIGNEDSIGNATUREPROPERTIES
	this->_Inst_UnsignedSignatureProperties = NULL;
#endif /* SB_USE_CLASS_TELXMLUNSIGNEDSIGNATUREPROPERTIES */
#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
	this->_Inst_UnsignedDataObjectProperties = NULL;
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */
}

TElXMLUnsignedProperties::TElXMLUnsignedProperties(TElXMLUnsignedPropertiesHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLUnsignedProperties::TElXMLUnsignedProperties(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLUnsignedProperties_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLUnsignedProperties::TElXMLUnsignedProperties(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLUnsignedProperties_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLUnsignedProperties::TElXMLUnsignedProperties(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLUnsignedProperties_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLUnsignedProperties::TElXMLUnsignedProperties(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLUnsignedProperties_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLUnsignedProperties::TElXMLUnsignedProperties(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLUnsignedProperties_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLUnsignedProperties::~TElXMLUnsignedProperties()
{
#ifdef SB_USE_CLASS_TELXMLUNSIGNEDSIGNATUREPROPERTIES
	delete this->_Inst_UnsignedSignatureProperties;
	this->_Inst_UnsignedSignatureProperties = NULL;
#endif /* SB_USE_CLASS_TELXMLUNSIGNEDSIGNATUREPROPERTIES */
#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
	delete this->_Inst_UnsignedDataObjectProperties;
	this->_Inst_UnsignedDataObjectProperties = NULL;
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */
}
#endif /* SB_USE_CLASS_TELXMLUNSIGNEDPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES

SB_INLINE void TElXMLQualifyingProperties::Clear()
{
	SBCheckError(TElXMLQualifyingProperties_Clear(_Handle));
}

bool TElXMLQualifyingProperties::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLQualifyingProperties_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLQualifyingProperties::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLQualifyingProperties_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLQualifyingProperties::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLQualifyingProperties_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLQualifyingProperties::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLQualifyingProperties_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLQualifyingProperties::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLQualifyingProperties_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLQualifyingProperties::get_XAdESPrefix(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLQualifyingProperties_get_XAdESPrefix(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-244257356, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLQualifyingProperties::get_XAdESPrefix(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLQualifyingProperties_get_XAdESPrefix(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-244257356, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLQualifyingProperties::set_XAdESPrefix(const sb_u16string &Value)
{
	SBCheckError(TElXMLQualifyingProperties_set_XAdESPrefix(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLQualifyingProperties::set_XAdESPrefix(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLQualifyingProperties_set_XAdESPrefix(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLQualifyingProperties::get_XAdESv141Prefix(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLQualifyingProperties_get_XAdESv141Prefix(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-812933391, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLQualifyingProperties::get_XAdESv141Prefix(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLQualifyingProperties_get_XAdESv141Prefix(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-812933391, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLQualifyingProperties::set_XAdESv141Prefix(const sb_u16string &Value)
{
	SBCheckError(TElXMLQualifyingProperties_set_XAdESv141Prefix(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLQualifyingProperties::set_XAdESv141Prefix(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLQualifyingProperties_set_XAdESv141Prefix(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLQualifyingProperties::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLQualifyingProperties_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1294132056, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLQualifyingProperties::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLQualifyingProperties_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1294132056, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLQualifyingProperties::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLQualifyingProperties_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLQualifyingProperties::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLQualifyingProperties_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLQualifyingProperties::get_Target(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLQualifyingProperties_get_Target(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(2145852669, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLQualifyingProperties::get_Target(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLQualifyingProperties_get_Target(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(2145852669, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLQualifyingProperties::set_Target(const sb_u16string &Value)
{
	SBCheckError(TElXMLQualifyingProperties_set_Target(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLQualifyingProperties::set_Target(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLQualifyingProperties_set_Target(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLSIGNEDPROPERTIES
TElXMLSignedProperties* TElXMLQualifyingProperties::get_SignedProperties()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLQualifyingProperties_get_SignedProperties(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignedProperties)
		this->_Inst_SignedProperties = new TElXMLSignedProperties(hOutResult, ohFalse);
	else
		this->_Inst_SignedProperties->updateHandle(hOutResult);
	return this->_Inst_SignedProperties;
}

SB_INLINE void TElXMLQualifyingProperties::set_SignedProperties(TElXMLSignedProperties &Value)
{
	SBCheckError(TElXMLQualifyingProperties_set_SignedProperties(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLQualifyingProperties::set_SignedProperties(TElXMLSignedProperties *Value)
{
	SBCheckError(TElXMLQualifyingProperties_set_SignedProperties(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLSIGNEDPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLUNSIGNEDPROPERTIES
TElXMLUnsignedProperties* TElXMLQualifyingProperties::get_UnsignedProperties()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLQualifyingProperties_get_UnsignedProperties(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_UnsignedProperties)
		this->_Inst_UnsignedProperties = new TElXMLUnsignedProperties(hOutResult, ohFalse);
	else
		this->_Inst_UnsignedProperties->updateHandle(hOutResult);
	return this->_Inst_UnsignedProperties;
}

SB_INLINE void TElXMLQualifyingProperties::set_UnsignedProperties(TElXMLUnsignedProperties &Value)
{
	SBCheckError(TElXMLQualifyingProperties_set_UnsignedProperties(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLQualifyingProperties::set_UnsignedProperties(TElXMLUnsignedProperties *Value)
{
	SBCheckError(TElXMLQualifyingProperties_set_UnsignedProperties(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLUNSIGNEDPROPERTIES */

void TElXMLQualifyingProperties::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLSIGNEDPROPERTIES
	this->_Inst_SignedProperties = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNEDPROPERTIES */
#ifdef SB_USE_CLASS_TELXMLUNSIGNEDPROPERTIES
	this->_Inst_UnsignedProperties = NULL;
#endif /* SB_USE_CLASS_TELXMLUNSIGNEDPROPERTIES */
}

TElXMLQualifyingProperties::TElXMLQualifyingProperties(TElXMLQualifyingPropertiesHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLQualifyingProperties::TElXMLQualifyingProperties(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLQualifyingProperties_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLQualifyingProperties::TElXMLQualifyingProperties(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLQualifyingProperties_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLQualifyingProperties::TElXMLQualifyingProperties(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLQualifyingProperties_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLQualifyingProperties::TElXMLQualifyingProperties(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLQualifyingProperties_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLQualifyingProperties::TElXMLQualifyingProperties(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLQualifyingProperties_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLQualifyingProperties::~TElXMLQualifyingProperties()
{
#ifdef SB_USE_CLASS_TELXMLSIGNEDPROPERTIES
	delete this->_Inst_SignedProperties;
	this->_Inst_SignedProperties = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNEDPROPERTIES */
#ifdef SB_USE_CLASS_TELXMLUNSIGNEDPROPERTIES
	delete this->_Inst_UnsignedProperties;
	this->_Inst_UnsignedProperties = NULL;
#endif /* SB_USE_CLASS_TELXMLUNSIGNEDPROPERTIES */
}
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE

SB_INLINE void TElXMLQualifyingPropertiesReference::Clear()
{
	SBCheckError(TElXMLQualifyingPropertiesReference_Clear(_Handle));
}

bool TElXMLQualifyingPropertiesReference::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLQualifyingPropertiesReference_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLQualifyingPropertiesReference::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLQualifyingPropertiesReference_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLQualifyingPropertiesReference::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLQualifyingPropertiesReference_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLQualifyingPropertiesReference::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLQualifyingPropertiesReference_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLQualifyingPropertiesReference::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLQualifyingPropertiesReference_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLQualifyingPropertiesReference::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLQualifyingPropertiesReference_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1301779987, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLQualifyingPropertiesReference::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLQualifyingPropertiesReference_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1301779987, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLQualifyingPropertiesReference::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLQualifyingPropertiesReference_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLQualifyingPropertiesReference::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLQualifyingPropertiesReference_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLQualifyingPropertiesReference::get_URI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLQualifyingPropertiesReference_get_URI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-2108178241, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLQualifyingPropertiesReference::get_URI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLQualifyingPropertiesReference_get_URI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-2108178241, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLQualifyingPropertiesReference::set_URI(const sb_u16string &Value)
{
	SBCheckError(TElXMLQualifyingPropertiesReference_set_URI(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLQualifyingPropertiesReference::set_URI(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLQualifyingPropertiesReference_set_URI(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
TElXMLTransformChain* TElXMLQualifyingPropertiesReference::get_TransformChain()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLQualifyingPropertiesReference_get_TransformChain(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TransformChain)
		this->_Inst_TransformChain = new TElXMLTransformChain(hOutResult, ohFalse);
	else
		this->_Inst_TransformChain->updateHandle(hOutResult);
	return this->_Inst_TransformChain;
}
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLDOMElement* TElXMLQualifyingPropertiesReference::get_QualifyingProperties()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLQualifyingPropertiesReference_get_QualifyingProperties(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_QualifyingProperties)
		this->_Inst_QualifyingProperties = new TElXMLDOMElement(hOutResult, ohFalse);
	else
		this->_Inst_QualifyingProperties->updateHandle(hOutResult);
	return this->_Inst_QualifyingProperties;
}

SB_INLINE void TElXMLQualifyingPropertiesReference::set_QualifyingProperties(TElXMLDOMElement &Value)
{
	SBCheckError(TElXMLQualifyingPropertiesReference_set_QualifyingProperties(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLQualifyingPropertiesReference::set_QualifyingProperties(TElXMLDOMElement *Value)
{
	SBCheckError(TElXMLQualifyingPropertiesReference_set_QualifyingProperties(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

void TElXMLQualifyingPropertiesReference::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
	this->_Inst_TransformChain = NULL;
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	this->_Inst_QualifyingProperties = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
}

TElXMLQualifyingPropertiesReference::TElXMLQualifyingPropertiesReference(TElXMLQualifyingPropertiesReferenceHandle handle, TElOwnHandle ownHandle) : TElXMLAdESElement(handle, ownHandle)
{
	initInstances();
}

TElXMLQualifyingPropertiesReference::TElXMLQualifyingPropertiesReference(TSBXAdESVersion AVersion) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLQualifyingPropertiesReference_Create((TSBXAdESVersionRaw)AVersion, &_Handle));
}

TElXMLQualifyingPropertiesReference::TElXMLQualifyingPropertiesReference(TSBXAdESVersion AVersion, const sb_u16string &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLQualifyingPropertiesReference_Create_1((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLQualifyingPropertiesReference::TElXMLQualifyingPropertiesReference(TSBXAdESVersion AVersion, const std::wstring &AName) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLQualifyingPropertiesReference_Create_1((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLQualifyingPropertiesReference::TElXMLQualifyingPropertiesReference(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLQualifyingPropertiesReference_Create_2((TSBXAdESVersionRaw)AVersion, AName.data(), (int32_t)AName.length(), (int8_t)SupportedV141, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLQualifyingPropertiesReference::TElXMLQualifyingPropertiesReference(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141) : TElXMLAdESElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLQualifyingPropertiesReference_Create_2((TSBXAdESVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, (int8_t)SupportedV141, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLQualifyingPropertiesReference::~TElXMLQualifyingPropertiesReference()
{
#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
	delete this->_Inst_TransformChain;
	this->_Inst_TransformChain = NULL;
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	delete this->_Inst_QualifyingProperties;
	this->_Inst_QualifyingProperties = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
}
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE */

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE
SB_INLINE int32_t TElXMLQualifyingPropertiesReferenceList::Add(TElXMLQualifyingPropertiesReference &AQualifyingPropertiesRef)
{
	int32_t OutResult;
	SBCheckError(TElXMLQualifyingPropertiesReferenceList_Add(_Handle, AQualifyingPropertiesRef.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLQualifyingPropertiesReferenceList::Add(TElXMLQualifyingPropertiesReference *AQualifyingPropertiesRef)
{
	int32_t OutResult;
	SBCheckError(TElXMLQualifyingPropertiesReferenceList_Add(_Handle, (AQualifyingPropertiesRef != NULL) ? AQualifyingPropertiesRef->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE */

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE
SB_INLINE void TElXMLQualifyingPropertiesReferenceList::Insert(int32_t Index, TElXMLQualifyingPropertiesReference &AQualifyingPropertiesRef)
{
	SBCheckError(TElXMLQualifyingPropertiesReferenceList_Insert(_Handle, Index, AQualifyingPropertiesRef.getHandle()));
}

SB_INLINE void TElXMLQualifyingPropertiesReferenceList::Insert(int32_t Index, TElXMLQualifyingPropertiesReference *AQualifyingPropertiesRef)
{
	SBCheckError(TElXMLQualifyingPropertiesReferenceList_Insert(_Handle, Index, (AQualifyingPropertiesRef != NULL) ? AQualifyingPropertiesRef->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE */

SB_INLINE void TElXMLQualifyingPropertiesReferenceList::Delete(int32_t Index)
{
	SBCheckError(TElXMLQualifyingPropertiesReferenceList_Delete(_Handle, Index));
}

SB_INLINE void TElXMLQualifyingPropertiesReferenceList::Clear()
{
	SBCheckError(TElXMLQualifyingPropertiesReferenceList_Clear(_Handle));
}

SB_INLINE int32_t TElXMLQualifyingPropertiesReferenceList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLQualifyingPropertiesReferenceList_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE
TElXMLQualifyingPropertiesReference* TElXMLQualifyingPropertiesReferenceList::get_QualifyingPropertiesReference(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLQualifyingPropertiesReferenceList_get_QualifyingPropertiesReference(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_QualifyingPropertiesReference)
		this->_Inst_QualifyingPropertiesReference = new TElXMLQualifyingPropertiesReference(hOutResult, ohFalse);
	else
		this->_Inst_QualifyingPropertiesReference->updateHandle(hOutResult);
	return this->_Inst_QualifyingPropertiesReference;
}
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE */

void TElXMLQualifyingPropertiesReferenceList::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE
	this->_Inst_QualifyingPropertiesReference = NULL;
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE */
}

TElXMLQualifyingPropertiesReferenceList::TElXMLQualifyingPropertiesReferenceList(TElXMLQualifyingPropertiesReferenceListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElXMLQualifyingPropertiesReferenceList::TElXMLQualifyingPropertiesReferenceList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLQualifyingPropertiesReferenceList_Create(&_Handle));
}

TElXMLQualifyingPropertiesReferenceList::~TElXMLQualifyingPropertiesReferenceList()
{
#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE
	delete this->_Inst_QualifyingPropertiesReference;
	this->_Inst_QualifyingPropertiesReference = NULL;
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE */
}
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST */

#ifdef SB_USE_GLOBAL_PROCS_XMLADES

TSBXAdESVersion GetXAdESVersion(const sb_u16string &NamespaceURI)
{
	TSBXAdESVersionRaw OutResultRaw = 0;
	SBCheckError(SBXMLAdES_GetXAdESVersion(NamespaceURI.data(), (int32_t)NamespaceURI.length(), &OutResultRaw));
	return (TSBXAdESVersion)OutResultRaw;
}
#ifdef SB_U16STRING_USED
TSBXAdESVersion GetXAdESVersion(const std::wstring &NamespaceURI)
{
	std::string u16NamespaceURI;
	sb_to_u16string(NamespaceURI, u16NamespaceURI);
	TSBXAdESVersionRaw OutResultRaw = 0;
	SBCheckError(SBXMLAdES_GetXAdESVersion(reinterpret_cast<const sb_char16_t*>(u16NamespaceURI.data()), (int32_t)u16NamespaceURI.length() >> 1, &OutResultRaw));
	return (TSBXAdESVersion)OutResultRaw;
}
#endif /* SB_U16STRING_USED */

void GetXAdESNamespaceURI(TSBXAdESVersion Version, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLAdES_GetXAdESNamespaceURI((TSBXAdESVersionRaw)Version, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1707148730, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void GetXAdESNamespaceURI(TSBXAdESVersion Version, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLAdES_GetXAdESNamespaceURI((TSBXAdESVersionRaw)Version, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1707148730, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void GetXAdESNamespaceURI(TSBXAdESVersion Version, bool SupportedV141, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLAdES_GetXAdESNamespaceURI_1((TSBXAdESVersionRaw)Version, (int8_t)SupportedV141, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1088482806, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void GetXAdESNamespaceURI(TSBXAdESVersion Version, bool SupportedV141, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLAdES_GetXAdESNamespaceURI_1((TSBXAdESVersionRaw)Version, (int8_t)SupportedV141, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1088482806, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void GetXAdESReferenceType(TSBXAdESVersion Version, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLAdES_GetXAdESReferenceType((TSBXAdESVersionRaw)Version, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1396467214, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void GetXAdESReferenceType(TSBXAdESVersion Version, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLAdES_GetXAdESReferenceType((TSBXAdESVersionRaw)Version, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1396467214, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void XAdESVersionToString(TSBXAdESVersion XAdESVersion, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLAdES_XAdESVersionToString((TSBXAdESVersionRaw)XAdESVersion, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1391028805, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void XAdESFormToString(TSBXAdESForm XAdESForm, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLAdES_XAdESFormToString((TSBXAdESFormRaw)XAdESForm, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(639363606, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#endif /* SB_USE_GLOBAL_PROCS_XMLADES */

};	/* namespace SecureBlackbox */

