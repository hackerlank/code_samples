#include "sbxmlsamlcore.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSAMLELEMENT

SB_INLINE void TElSAMLElement::Assign(TElSAMLElement &Other)
{
	SBCheckError(TElSAMLElement_Assign(_Handle, Other.getHandle()));
}

SB_INLINE void TElSAMLElement::Assign(TElSAMLElement *Other)
{
	SBCheckError(TElSAMLElement_Assign(_Handle, (Other != NULL) ? Other->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

TObject* TElSAMLElement::get_Tag()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLElement_get_Tag(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Tag)
		this->_Inst_Tag = new TObject(hOutResult, ohFalse);
	else
		this->_Inst_Tag->updateHandle(hOutResult);
	return this->_Inst_Tag;
}

SB_INLINE void TElSAMLElement::set_Tag(TObject &Value)
{
	SBCheckError(TElSAMLElement_set_Tag(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLElement::set_Tag(TObject *Value)
{
	SBCheckError(TElSAMLElement_set_Tag(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELSAMLSECURITYHANDLER
TElSAMLSecurityHandler* TElSAMLElement::get_Handler()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLElement_get_Handler(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Handler)
		this->_Inst_Handler = new TElSAMLSecurityHandler(hOutResult, ohFalse);
	else
		this->_Inst_Handler->updateHandle(hOutResult);
	return this->_Inst_Handler;
}

SB_INLINE void TElSAMLElement::set_Handler(TElSAMLSecurityHandler &Value)
{
	SBCheckError(TElSAMLElement_set_Handler(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLElement::set_Handler(TElSAMLSecurityHandler *Value)
{
	SBCheckError(TElSAMLElement_set_Handler(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLSECURITYHANDLER */

void TElSAMLElement::get_TextValue(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLElement_get_TextValue(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(555295703, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSAMLElement::initInstances()
{
	this->_Inst_Tag = NULL;
#ifdef SB_USE_CLASS_TELSAMLSECURITYHANDLER
	this->_Inst_Handler = NULL;
#endif /* SB_USE_CLASS_TELSAMLSECURITYHANDLER */
}

TElSAMLElement::TElSAMLElement(TElSAMLElementHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLElement::TElSAMLElement() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLElement_Create(&_Handle));
}

TElSAMLElement::~TElSAMLElement()
{
	delete this->_Inst_Tag;
	this->_Inst_Tag = NULL;
#ifdef SB_USE_CLASS_TELSAMLSECURITYHANDLER
	delete this->_Inst_Handler;
	this->_Inst_Handler = NULL;
#endif /* SB_USE_CLASS_TELSAMLSECURITYHANDLER */
}
#endif /* SB_USE_CLASS_TELSAMLELEMENT */

#ifdef SB_USE_CLASS_TELSAMLCONDITIONSELEMENT

SB_INLINE void TElSAMLConditionsElement::Clear()
{
	SBCheckError(TElSAMLConditionsElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLConditionsElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLConditionsElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLConditionsElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLConditionsElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLConditionsElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLConditionsElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLConditionsElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLConditionsElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELSAMLCONDITIONABSTRACTTYPE
SB_INLINE int32_t TElSAMLConditionsElement::AddCondition(TElSAMLConditionAbstractType &Cond)
{
	int32_t OutResult;
	SBCheckError(TElSAMLConditionsElement_AddCondition(_Handle, Cond.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLConditionsElement::AddCondition(TElSAMLConditionAbstractType *Cond)
{
	int32_t OutResult;
	SBCheckError(TElSAMLConditionsElement_AddCondition(_Handle, (Cond != NULL) ? Cond->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLCONDITIONABSTRACTTYPE */

SB_INLINE void TElSAMLConditionsElement::RemoveCondition(int32_t Index)
{
	SBCheckError(TElSAMLConditionsElement_RemoveCondition(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELSAMLONETIMEUSEELEMENT
TElSAMLOneTimeUseElement* TElSAMLConditionsElement::get_OneTimeUse()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLConditionsElement_get_OneTimeUse(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OneTimeUse)
		this->_Inst_OneTimeUse = new TElSAMLOneTimeUseElement(hOutResult, ohFalse);
	else
		this->_Inst_OneTimeUse->updateHandle(hOutResult);
	return this->_Inst_OneTimeUse;
}
#endif /* SB_USE_CLASS_TELSAMLONETIMEUSEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLPROXYRESTRICTIONELEMENT
TElSAMLProxyRestrictionElement* TElSAMLConditionsElement::get_ProxyRestriction()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLConditionsElement_get_ProxyRestriction(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ProxyRestriction)
		this->_Inst_ProxyRestriction = new TElSAMLProxyRestrictionElement(hOutResult, ohFalse);
	else
		this->_Inst_ProxyRestriction->updateHandle(hOutResult);
	return this->_Inst_ProxyRestriction;
}
#endif /* SB_USE_CLASS_TELSAMLPROXYRESTRICTIONELEMENT */

SB_INLINE int64_t TElSAMLConditionsElement::get_NotBefore()
{
	int64_t OutResult;
	SBCheckError(TElSAMLConditionsElement_get_NotBefore(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLConditionsElement::set_NotBefore(int64_t Value)
{
	SBCheckError(TElSAMLConditionsElement_set_NotBefore(_Handle, Value));
}

SB_INLINE int64_t TElSAMLConditionsElement::get_NotOnOrAfter()
{
	int64_t OutResult;
	SBCheckError(TElSAMLConditionsElement_get_NotOnOrAfter(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLConditionsElement::set_NotOnOrAfter(int64_t Value)
{
	SBCheckError(TElSAMLConditionsElement_set_NotOnOrAfter(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELSAMLCONDITIONABSTRACTTYPE
TElSAMLConditionAbstractType* TElSAMLConditionsElement::get_Conditions(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLConditionsElement_get_Conditions(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Conditions)
		this->_Inst_Conditions = new TElSAMLConditionAbstractType(hOutResult, ohFalse);
	else
		this->_Inst_Conditions->updateHandle(hOutResult);
	return this->_Inst_Conditions;
}
#endif /* SB_USE_CLASS_TELSAMLCONDITIONABSTRACTTYPE */

SB_INLINE int32_t TElSAMLConditionsElement::get_ConditionCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLConditionsElement_get_ConditionCount(_Handle, &OutResult));
	return OutResult;
}

void TElSAMLConditionsElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLONETIMEUSEELEMENT
	this->_Inst_OneTimeUse = NULL;
#endif /* SB_USE_CLASS_TELSAMLONETIMEUSEELEMENT */
#ifdef SB_USE_CLASS_TELSAMLPROXYRESTRICTIONELEMENT
	this->_Inst_ProxyRestriction = NULL;
#endif /* SB_USE_CLASS_TELSAMLPROXYRESTRICTIONELEMENT */
#ifdef SB_USE_CLASS_TELSAMLCONDITIONABSTRACTTYPE
	this->_Inst_Conditions = NULL;
#endif /* SB_USE_CLASS_TELSAMLCONDITIONABSTRACTTYPE */
}

TElSAMLConditionsElement::TElSAMLConditionsElement(TElSAMLConditionsElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLConditionsElement::TElSAMLConditionsElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLConditionsElement_Create(&_Handle));
}

TElSAMLConditionsElement::~TElSAMLConditionsElement()
{
#ifdef SB_USE_CLASS_TELSAMLONETIMEUSEELEMENT
	delete this->_Inst_OneTimeUse;
	this->_Inst_OneTimeUse = NULL;
#endif /* SB_USE_CLASS_TELSAMLONETIMEUSEELEMENT */
#ifdef SB_USE_CLASS_TELSAMLPROXYRESTRICTIONELEMENT
	delete this->_Inst_ProxyRestriction;
	this->_Inst_ProxyRestriction = NULL;
#endif /* SB_USE_CLASS_TELSAMLPROXYRESTRICTIONELEMENT */
#ifdef SB_USE_CLASS_TELSAMLCONDITIONABSTRACTTYPE
	delete this->_Inst_Conditions;
	this->_Inst_Conditions = NULL;
#endif /* SB_USE_CLASS_TELSAMLCONDITIONABSTRACTTYPE */
}
#endif /* SB_USE_CLASS_TELSAMLCONDITIONSELEMENT */

#ifdef SB_USE_CLASS_TELSAMLADVICEELEMENT

SB_INLINE void TElSAMLAdviceElement::Clear()
{
	SBCheckError(TElSAMLAdviceElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLAdviceElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLAdviceElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLAdviceElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLAdviceElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLAdviceElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAdviceElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLAdviceElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAdviceElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONTYPE
SB_INLINE int32_t TElSAMLAdviceElement::AddAssertion(TElSAMLAssertionType &Assertion)
{
	int32_t OutResult;
	SBCheckError(TElSAMLAdviceElement_AddAssertion(_Handle, Assertion.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLAdviceElement::AddAssertion(TElSAMLAssertionType *Assertion)
{
	int32_t OutResult;
	SBCheckError(TElSAMLAdviceElement_AddAssertion(_Handle, (Assertion != NULL) ? Assertion->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLASSERTIONTYPE */

SB_INLINE void TElSAMLAdviceElement::RemoveAssertion(int32_t Index)
{
	SBCheckError(TElSAMLAdviceElement_RemoveAssertion(_Handle, Index));
}

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLAdviceElement::get_Others()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAdviceElement_get_Others(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Others)
		this->_Inst_Others = new TList(hOutResult, ohFalse);
	else
		this->_Inst_Others->updateHandle(hOutResult);
	return this->_Inst_Others;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONTYPE
TElSAMLAssertionType* TElSAMLAdviceElement::get_Assertions(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAdviceElement_get_Assertions(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Assertions)
		this->_Inst_Assertions = new TElSAMLAssertionType(hOutResult, ohFalse);
	else
		this->_Inst_Assertions->updateHandle(hOutResult);
	return this->_Inst_Assertions;
}
#endif /* SB_USE_CLASS_TELSAMLASSERTIONTYPE */

SB_INLINE int32_t TElSAMLAdviceElement::get_AssertionCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLAdviceElement_get_AssertionCount(_Handle, &OutResult));
	return OutResult;
}

void TElSAMLAdviceElement::initInstances()
{
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_Others = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TELSAMLASSERTIONTYPE
	this->_Inst_Assertions = NULL;
#endif /* SB_USE_CLASS_TELSAMLASSERTIONTYPE */
}

TElSAMLAdviceElement::TElSAMLAdviceElement(TElSAMLAdviceElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLAdviceElement::TElSAMLAdviceElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLAdviceElement_Create(&_Handle));
}

TElSAMLAdviceElement::~TElSAMLAdviceElement()
{
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_Others;
	this->_Inst_Others = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TELSAMLASSERTIONTYPE
	delete this->_Inst_Assertions;
	this->_Inst_Assertions = NULL;
#endif /* SB_USE_CLASS_TELSAMLASSERTIONTYPE */
}
#endif /* SB_USE_CLASS_TELSAMLADVICEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONDATAELEMENT

SB_INLINE void TElSAMLSubjectConfirmationDataElement::Clear()
{
	SBCheckError(TElSAMLSubjectConfirmationDataElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLSubjectConfirmationDataElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLSubjectConfirmationDataElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLSubjectConfirmationDataElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLSubjectConfirmationDataElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLSubjectConfirmationDataElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLSubjectConfirmationDataElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLSubjectConfirmationDataElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLSubjectConfirmationDataElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int32_t TElSAMLSubjectConfirmationDataElement::AddArbitraryElement(TElXMLCustomElement &Elem)
{
	int32_t OutResult;
	SBCheckError(TElSAMLSubjectConfirmationDataElement_AddArbitraryElement(_Handle, Elem.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLSubjectConfirmationDataElement::AddArbitraryElement(TElXMLCustomElement *Elem)
{
	int32_t OutResult;
	SBCheckError(TElSAMLSubjectConfirmationDataElement_AddArbitraryElement(_Handle, (Elem != NULL) ? Elem->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLDOMATTR
SB_INLINE int32_t TElSAMLSubjectConfirmationDataElement::AddArbitraryAttribute(TElXMLDOMAttr &Attr)
{
	int32_t OutResult;
	SBCheckError(TElSAMLSubjectConfirmationDataElement_AddArbitraryAttribute(_Handle, Attr.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLSubjectConfirmationDataElement::AddArbitraryAttribute(TElXMLDOMAttr *Attr)
{
	int32_t OutResult;
	SBCheckError(TElSAMLSubjectConfirmationDataElement_AddArbitraryAttribute(_Handle, (Attr != NULL) ? Attr->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

SB_INLINE void TElSAMLSubjectConfirmationDataElement::RemoveArbitraryElement(int32_t Index)
{
	SBCheckError(TElSAMLSubjectConfirmationDataElement_RemoveArbitraryElement(_Handle, Index));
}

SB_INLINE void TElSAMLSubjectConfirmationDataElement::RemoveArbitraryAttribute(int32_t Index)
{
	SBCheckError(TElSAMLSubjectConfirmationDataElement_RemoveArbitraryAttribute(_Handle, Index));
}

void TElSAMLSubjectConfirmationDataElement::get_AType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLSubjectConfirmationDataElement_get_AType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1416147377, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLSubjectConfirmationDataElement::set_AType(const std::string &Value)
{
	SBCheckError(TElSAMLSubjectConfirmationDataElement_set_AType(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElSAMLSubjectConfirmationDataElement::get_NotBefore()
{
	int64_t OutResult;
	SBCheckError(TElSAMLSubjectConfirmationDataElement_get_NotBefore(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLSubjectConfirmationDataElement::set_NotBefore(int64_t Value)
{
	SBCheckError(TElSAMLSubjectConfirmationDataElement_set_NotBefore(_Handle, Value));
}

SB_INLINE int64_t TElSAMLSubjectConfirmationDataElement::get_NotOnOrAfter()
{
	int64_t OutResult;
	SBCheckError(TElSAMLSubjectConfirmationDataElement_get_NotOnOrAfter(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLSubjectConfirmationDataElement::set_NotOnOrAfter(int64_t Value)
{
	SBCheckError(TElSAMLSubjectConfirmationDataElement_set_NotOnOrAfter(_Handle, Value));
}

void TElSAMLSubjectConfirmationDataElement::get_Recipient(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLSubjectConfirmationDataElement_get_Recipient(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-250713820, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLSubjectConfirmationDataElement::set_Recipient(const std::string &Value)
{
	SBCheckError(TElSAMLSubjectConfirmationDataElement_set_Recipient(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLSubjectConfirmationDataElement::get_InResponseTo(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLSubjectConfirmationDataElement_get_InResponseTo(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1580134387, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLSubjectConfirmationDataElement::set_InResponseTo(const std::string &Value)
{
	SBCheckError(TElSAMLSubjectConfirmationDataElement_set_InResponseTo(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLSubjectConfirmationDataElement::get_Address(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLSubjectConfirmationDataElement_get_Address(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(496501356, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLSubjectConfirmationDataElement::set_Address(const std::string &Value)
{
	SBCheckError(TElSAMLSubjectConfirmationDataElement_set_Address(_Handle, Value.data(), (int32_t)Value.length()));
}

TElXMLCustomElement* TElSAMLSubjectConfirmationDataElement::get_ArbitraryElements(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLSubjectConfirmationDataElement_get_ArbitraryElements(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ArbitraryElements)
		this->_Inst_ArbitraryElements = new TElXMLCustomElement(hOutResult, ohFalse);
	else
		this->_Inst_ArbitraryElements->updateHandle(hOutResult);
	return this->_Inst_ArbitraryElements;
}

#ifdef SB_USE_CLASS_TELXMLDOMATTR
TElXMLDOMAttr* TElSAMLSubjectConfirmationDataElement::get_ArbitraryAttributes(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLSubjectConfirmationDataElement_get_ArbitraryAttributes(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ArbitraryAttributes)
		this->_Inst_ArbitraryAttributes = new TElXMLDOMAttr(hOutResult, ohFalse);
	else
		this->_Inst_ArbitraryAttributes->updateHandle(hOutResult);
	return this->_Inst_ArbitraryAttributes;
}
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

SB_INLINE int32_t TElSAMLSubjectConfirmationDataElement::get_ArbitraryElementCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLSubjectConfirmationDataElement_get_ArbitraryElementCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLSubjectConfirmationDataElement::get_ArbitraryAttributeCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLSubjectConfirmationDataElement_get_ArbitraryAttributeCount(_Handle, &OutResult));
	return OutResult;
}

void TElSAMLSubjectConfirmationDataElement::initInstances()
{
	this->_Inst_ArbitraryElements = NULL;
#ifdef SB_USE_CLASS_TELXMLDOMATTR
	this->_Inst_ArbitraryAttributes = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMATTR */
}

TElSAMLSubjectConfirmationDataElement::TElSAMLSubjectConfirmationDataElement(TElSAMLSubjectConfirmationDataElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLSubjectConfirmationDataElement::TElSAMLSubjectConfirmationDataElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLSubjectConfirmationDataElement_Create(&_Handle));
}

TElSAMLSubjectConfirmationDataElement::~TElSAMLSubjectConfirmationDataElement()
{
	delete this->_Inst_ArbitraryElements;
	this->_Inst_ArbitraryElements = NULL;
#ifdef SB_USE_CLASS_TELXMLDOMATTR
	delete this->_Inst_ArbitraryAttributes;
	this->_Inst_ArbitraryAttributes = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMATTR */
}
#endif /* SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONDATAELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATEMENTABSTRACTTYPE

TElSAMLStatementAbstractType::TElSAMLStatementAbstractType(TElSAMLStatementAbstractTypeHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
}

TElSAMLStatementAbstractType::TElSAMLStatementAbstractType() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLStatementAbstractType_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLSTATEMENTABSTRACTTYPE */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONELEMENT

SB_INLINE void TElSAMLSubjectConfirmationElement::Clear()
{
	SBCheckError(TElSAMLSubjectConfirmationElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLSubjectConfirmationElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLSubjectConfirmationElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLSubjectConfirmationElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLSubjectConfirmationElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLSubjectConfirmationElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLSubjectConfirmationElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLSubjectConfirmationElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLSubjectConfirmationElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELSAMLID
TElSAMLID* TElSAMLSubjectConfirmationElement::get_ID()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLSubjectConfirmationElement_get_ID(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ID)
		this->_Inst_ID = new TElSAMLID(hOutResult, ohFalse);
	else
		this->_Inst_ID->updateHandle(hOutResult);
	return this->_Inst_ID;
}

SB_INLINE void TElSAMLSubjectConfirmationElement::set_ID(TElSAMLID &Value)
{
	SBCheckError(TElSAMLSubjectConfirmationElement_set_ID(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLSubjectConfirmationElement::set_ID(TElSAMLID *Value)
{
	SBCheckError(TElSAMLSubjectConfirmationElement_set_ID(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLID */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONDATAELEMENT
TElSAMLSubjectConfirmationDataElement* TElSAMLSubjectConfirmationElement::get_SubjectConfirmationData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLSubjectConfirmationElement_get_SubjectConfirmationData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SubjectConfirmationData)
		this->_Inst_SubjectConfirmationData = new TElSAMLSubjectConfirmationDataElement(hOutResult, ohFalse);
	else
		this->_Inst_SubjectConfirmationData->updateHandle(hOutResult);
	return this->_Inst_SubjectConfirmationData;
}

SB_INLINE void TElSAMLSubjectConfirmationElement::set_SubjectConfirmationData(TElSAMLSubjectConfirmationDataElement &Value)
{
	SBCheckError(TElSAMLSubjectConfirmationElement_set_SubjectConfirmationData(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLSubjectConfirmationElement::set_SubjectConfirmationData(TElSAMLSubjectConfirmationDataElement *Value)
{
	SBCheckError(TElSAMLSubjectConfirmationElement_set_SubjectConfirmationData(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONDATAELEMENT */

void TElSAMLSubjectConfirmationElement::get__Method(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLSubjectConfirmationElement_get__Method(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1133655517, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLSubjectConfirmationElement::set__Method(const std::string &Value)
{
	SBCheckError(TElSAMLSubjectConfirmationElement_set__Method(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLSubjectConfirmationElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLID
	this->_Inst_ID = NULL;
#endif /* SB_USE_CLASS_TELSAMLID */
#ifdef SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONDATAELEMENT
	this->_Inst_SubjectConfirmationData = NULL;
#endif /* SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONDATAELEMENT */
}

TElSAMLSubjectConfirmationElement::TElSAMLSubjectConfirmationElement(TElSAMLSubjectConfirmationElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLSubjectConfirmationElement::TElSAMLSubjectConfirmationElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLSubjectConfirmationElement_Create(&_Handle));
}

TElSAMLSubjectConfirmationElement::~TElSAMLSubjectConfirmationElement()
{
#ifdef SB_USE_CLASS_TELSAMLID
	delete this->_Inst_ID;
	this->_Inst_ID = NULL;
#endif /* SB_USE_CLASS_TELSAMLID */
#ifdef SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONDATAELEMENT
	delete this->_Inst_SubjectConfirmationData;
	this->_Inst_SubjectConfirmationData = NULL;
#endif /* SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONDATAELEMENT */
}
#endif /* SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSECURITYHANDLER

#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLSecurityHandler::Protect(TElXMLDOMDocument &Document, TElXMLDOMElement &Node)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLSecurityHandler_Protect(_Handle, Document.getHandle(), Node.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLSecurityHandler::Protect(TElXMLDOMDocument *Document, TElXMLDOMElement *Node)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLSecurityHandler_Protect(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
bool TElSAMLSecurityHandler::Unprotect(TElXMLDOMDocument &Document, TElXMLDOMElement &Input, TElXMLDOMElement &Output)
{
	TElClassHandle hOutput = SB_NULL_HANDLE;
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLSecurityHandler_Unprotect(_Handle, Document.getHandle(), Input.getHandle(), &hOutput, &OutResultRaw));
	Output.updateHandle(hOutput);
	return (OutResultRaw != 0);
}

bool TElSAMLSecurityHandler::Unprotect(TElXMLDOMDocument *Document, TElXMLDOMElement *Input, TElXMLDOMElement &Output)
{
	TElClassHandle hOutput = SB_NULL_HANDLE;
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLSecurityHandler_Unprotect(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Input != NULL) ? Input->getHandle() : SB_NULL_HANDLE, &hOutput, &OutResultRaw));
	Output.updateHandle(hOutput);
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

TElSAMLSecurityHandler::TElSAMLSecurityHandler(TElSAMLSecurityHandlerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSAMLSecurityHandler::TElSAMLSecurityHandler() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLSecurityHandler_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLSECURITYHANDLER */

#ifdef SB_USE_CLASS_TELSAMLSIGNATUREHANDLER

#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLSignatureHandler::Protect(TElXMLDOMDocument &Document, TElXMLDOMElement &Elem)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLSignatureHandler_Protect(_Handle, Document.getHandle(), Elem.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLSignatureHandler::Protect(TElXMLDOMDocument *Document, TElXMLDOMElement *Elem)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLSignatureHandler_Protect(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Elem != NULL) ? Elem->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
bool TElSAMLSignatureHandler::Unprotect(TElXMLDOMDocument &Document, TElXMLDOMElement &Input, TElXMLDOMElement &Output)
{
	TElClassHandle hOutput = SB_NULL_HANDLE;
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLSignatureHandler_Unprotect(_Handle, Document.getHandle(), Input.getHandle(), &hOutput, &OutResultRaw));
	Output.updateHandle(hOutput);
	return (OutResultRaw != 0);
}

bool TElSAMLSignatureHandler::Unprotect(TElXMLDOMDocument *Document, TElXMLDOMElement *Input, TElXMLDOMElement &Output)
{
	TElClassHandle hOutput = SB_NULL_HANDLE;
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLSignatureHandler_Unprotect(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Input != NULL) ? Input->getHandle() : SB_NULL_HANDLE, &hOutput, &OutResultRaw));
	Output.updateHandle(hOutput);
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElSAMLSignatureHandler::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLSignatureHandler_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElSAMLSignatureHandler::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElSAMLSignatureHandler_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLSignatureHandler::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElSAMLSignatureHandler_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElSAMLSignatureHandler::get_Certificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLSignatureHandler_get_Certificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificate)
		this->_Inst_Certificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_Certificate->updateHandle(hOutResult);
	return this->_Inst_Certificate;
}

SB_INLINE void TElSAMLSignatureHandler::set_Certificate(TElX509Certificate &Value)
{
	SBCheckError(TElSAMLSignatureHandler_set_Certificate(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLSignatureHandler::set_Certificate(TElX509Certificate *Value)
{
	SBCheckError(TElSAMLSignatureHandler_set_Certificate(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

void TElSAMLSignatureHandler::get_VerificationResult(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLSignatureHandler_get_VerificationResult(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-662041688, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElSAMLSignatureHandler::get_ValidateCertificate()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLSignatureHandler_get_ValidateCertificate(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLSignatureHandler::set_ValidateCertificate(bool Value)
{
	SBCheckError(TElSAMLSignatureHandler_set_ValidateCertificate(_Handle, (int8_t)Value));
}

bool TElSAMLSignatureHandler::get_ValidateReferences()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLSignatureHandler_get_ValidateReferences(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLSignatureHandler::set_ValidateReferences(bool Value)
{
	SBCheckError(TElSAMLSignatureHandler_set_ValidateReferences(_Handle, (int8_t)Value));
}

TElXMLCanonicalizationMethod TElSAMLSignatureHandler::get_CanonicalizationMethod()
{
	TElXMLCanonicalizationMethodRaw OutResultRaw = 0;
	SBCheckError(TElSAMLSignatureHandler_get_CanonicalizationMethod(_Handle, &OutResultRaw));
	return (TElXMLCanonicalizationMethod)OutResultRaw;
}

SB_INLINE void TElSAMLSignatureHandler::set_CanonicalizationMethod(TElXMLCanonicalizationMethod Value)
{
	SBCheckError(TElSAMLSignatureHandler_set_CanonicalizationMethod(_Handle, (TElXMLCanonicalizationMethodRaw)Value));
}

bool TElSAMLSignatureHandler::get_SignatureAfterIssuer()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLSignatureHandler_get_SignatureAfterIssuer(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLSignatureHandler::set_SignatureAfterIssuer(bool Value)
{
	SBCheckError(TElSAMLSignatureHandler_set_SignatureAfterIssuer(_Handle, (int8_t)Value));
}

SB_INLINE void TElSAMLSignatureHandler::get_OnValidatorPrepared(TSBSAMLCertValidatorPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLSignatureHandler_get_OnValidatorPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLSignatureHandler::set_OnValidatorPrepared(TSBSAMLCertValidatorPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLSignatureHandler_set_OnValidatorPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLSignatureHandler::get_OnSignerPrepared(TSBSAMLXMLSignerPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLSignatureHandler_get_OnSignerPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLSignatureHandler::set_OnSignerPrepared(TSBSAMLXMLSignerPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLSignatureHandler_set_OnSignerPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLSignatureHandler::get_OnVerifierPrepared(TSBSAMLXMLVerifierPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLSignatureHandler_get_OnVerifierPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLSignatureHandler::set_OnVerifierPrepared(TSBSAMLXMLVerifierPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLSignatureHandler_set_OnVerifierPrepared(_Handle, pMethodValue, pDataValue));
}

void TElSAMLSignatureHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_Certificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
}

TElSAMLSignatureHandler::TElSAMLSignatureHandler(TElSAMLSignatureHandlerHandle handle, TElOwnHandle ownHandle) : TElSAMLSecurityHandler(handle, ownHandle)
{
	initInstances();
}

TElSAMLSignatureHandler::TElSAMLSignatureHandler() : TElSAMLSecurityHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLSignatureHandler_Create(&_Handle));
}

TElSAMLSignatureHandler::~TElSAMLSignatureHandler()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_Certificate;
	this->_Inst_Certificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
}
#endif /* SB_USE_CLASS_TELSAMLSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELSAMLENCRYPTIONHANDLER

#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLEncryptionHandler::Protect(TElXMLDOMDocument &Document, TElXMLDOMElement &Elem)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLEncryptionHandler_Protect(_Handle, Document.getHandle(), Elem.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLEncryptionHandler::Protect(TElXMLDOMDocument *Document, TElXMLDOMElement *Elem)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLEncryptionHandler_Protect(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Elem != NULL) ? Elem->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
bool TElSAMLEncryptionHandler::Unprotect(TElXMLDOMDocument &Document, TElXMLDOMElement &Input, TElXMLDOMElement &Output)
{
	TElClassHandle hOutput = SB_NULL_HANDLE;
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLEncryptionHandler_Unprotect(_Handle, Document.getHandle(), Input.getHandle(), &hOutput, &OutResultRaw));
	Output.updateHandle(hOutput);
	return (OutResultRaw != 0);
}

bool TElSAMLEncryptionHandler::Unprotect(TElXMLDOMDocument *Document, TElXMLDOMElement *Input, TElXMLDOMElement &Output)
{
	TElClassHandle hOutput = SB_NULL_HANDLE;
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLEncryptionHandler_Unprotect(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Input != NULL) ? Input->getHandle() : SB_NULL_HANDLE, &hOutput, &OutResultRaw));
	Output.updateHandle(hOutput);
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElSAMLEncryptionHandler::get_Certificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLEncryptionHandler_get_Certificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificate)
		this->_Inst_Certificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_Certificate->updateHandle(hOutResult);
	return this->_Inst_Certificate;
}

SB_INLINE void TElSAMLEncryptionHandler::set_Certificate(TElX509Certificate &Value)
{
	SBCheckError(TElSAMLEncryptionHandler_set_Certificate(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLEncryptionHandler::set_Certificate(TElX509Certificate *Value)
{
	SBCheckError(TElSAMLEncryptionHandler_set_Certificate(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE int32_t TElSAMLEncryptionHandler::get_DecryptionResult()
{
	int32_t OutResult;
	SBCheckError(TElSAMLEncryptionHandler_get_DecryptionResult(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLEncryptionHandler::set_DecryptionResult(int32_t Value)
{
	SBCheckError(TElSAMLEncryptionHandler_set_DecryptionResult(_Handle, Value));
}

SB_INLINE void TElSAMLEncryptionHandler::get_OnXMLEncryptorPrepared(TSBSAMLXMLEncryptorPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLEncryptionHandler_get_OnXMLEncryptorPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLEncryptionHandler::set_OnXMLEncryptorPrepared(TSBSAMLXMLEncryptorPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLEncryptionHandler_set_OnXMLEncryptorPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLEncryptionHandler::get_OnXMLDecryptorPrepared(TSBSAMLXMLDecryptorPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLEncryptionHandler_get_OnXMLDecryptorPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLEncryptionHandler::set_OnXMLDecryptorPrepared(TSBSAMLXMLDecryptorPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLEncryptionHandler_set_OnXMLDecryptorPrepared(_Handle, pMethodValue, pDataValue));
}

void TElSAMLEncryptionHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_Certificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
}

TElSAMLEncryptionHandler::TElSAMLEncryptionHandler(TElSAMLEncryptionHandlerHandle handle, TElOwnHandle ownHandle) : TElSAMLSecurityHandler(handle, ownHandle)
{
	initInstances();
}

TElSAMLEncryptionHandler::TElSAMLEncryptionHandler() : TElSAMLSecurityHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLEncryptionHandler_Create(&_Handle));
}

TElSAMLEncryptionHandler::~TElSAMLEncryptionHandler()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_Certificate;
	this->_Inst_Certificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
}
#endif /* SB_USE_CLASS_TELSAMLENCRYPTIONHANDLER */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTELEMENT

SB_INLINE void TElSAMLSubjectElement::Clear()
{
	SBCheckError(TElSAMLSubjectElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLSubjectElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLSubjectElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLSubjectElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLSubjectElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLSubjectElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLSubjectElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLSubjectElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLSubjectElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int32_t TElSAMLSubjectElement::AddSubjectConfirmation()
{
	int32_t OutResult;
	SBCheckError(TElSAMLSubjectElement_AddSubjectConfirmation(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLSubjectElement::RemoveSubjectConfirmation(int32_t Index)
{
	SBCheckError(TElSAMLSubjectElement_RemoveSubjectConfirmation(_Handle, Index));
}

bool TElSAMLSubjectElement::get_Sequence()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLSubjectElement_get_Sequence(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELSAMLID
TElSAMLID* TElSAMLSubjectElement::get_ID()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLSubjectElement_get_ID(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ID)
		this->_Inst_ID = new TElSAMLID(hOutResult, ohFalse);
	else
		this->_Inst_ID->updateHandle(hOutResult);
	return this->_Inst_ID;
}

SB_INLINE void TElSAMLSubjectElement::set_ID(TElSAMLID &Value)
{
	SBCheckError(TElSAMLSubjectElement_set_ID(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLSubjectElement::set_ID(TElSAMLID *Value)
{
	SBCheckError(TElSAMLSubjectElement_set_ID(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLID */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONELEMENT
TElSAMLSubjectConfirmationElement* TElSAMLSubjectElement::get_SubjectConfirmations(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLSubjectElement_get_SubjectConfirmations(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SubjectConfirmations)
		this->_Inst_SubjectConfirmations = new TElSAMLSubjectConfirmationElement(hOutResult, ohFalse);
	else
		this->_Inst_SubjectConfirmations->updateHandle(hOutResult);
	return this->_Inst_SubjectConfirmations;
}
#endif /* SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONELEMENT */

SB_INLINE int32_t TElSAMLSubjectElement::get_SubjectConfirmationCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLSubjectElement_get_SubjectConfirmationCount(_Handle, &OutResult));
	return OutResult;
}

void TElSAMLSubjectElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLID
	this->_Inst_ID = NULL;
#endif /* SB_USE_CLASS_TELSAMLID */
#ifdef SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONELEMENT
	this->_Inst_SubjectConfirmations = NULL;
#endif /* SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONELEMENT */
}

TElSAMLSubjectElement::TElSAMLSubjectElement(TElSAMLSubjectElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLSubjectElement::TElSAMLSubjectElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLSubjectElement_Create(&_Handle));
}

TElSAMLSubjectElement::~TElSAMLSubjectElement()
{
#ifdef SB_USE_CLASS_TELSAMLID
	delete this->_Inst_ID;
	this->_Inst_ID = NULL;
#endif /* SB_USE_CLASS_TELSAMLID */
#ifdef SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONELEMENT
	delete this->_Inst_SubjectConfirmations;
	this->_Inst_SubjectConfirmations = NULL;
#endif /* SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONELEMENT */
}
#endif /* SB_USE_CLASS_TELSAMLSUBJECTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLID

bool TElSAMLID::CompareTo(TElSAMLID &Other)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLID_CompareTo(_Handle, Other.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSAMLID::CompareTo(TElSAMLID *Other)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLID_CompareTo(_Handle, (Other != NULL) ? Other->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TElSAMLIDHandle TElSAMLID::CreateByName(const std::string &Name)
{
	TElSAMLIDHandle OutResult;
	SBCheckError(TElSAMLID_CreateByName(Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElSAMLIDHandle TElSAMLID::CreateByName_Inst(const std::string &Name)
{
	TElSAMLIDHandle OutResult;
	SBCheckError(TElSAMLID_CreateByName_1(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}

TElSAMLID::TElSAMLID(TElSAMLIDHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
}

TElSAMLID::TElSAMLID() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLID_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLID */

#ifdef SB_USE_CLASS_TELSAMLBASEIDELEMENT

SB_INLINE void TElSAMLBaseIDElement::Clear()
{
	SBCheckError(TElSAMLBaseIDElement_Clear(_Handle));
}

bool TElSAMLBaseIDElement::CompareTo(TElSAMLID &Other)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLBaseIDElement_CompareTo(_Handle, Other.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSAMLBaseIDElement::CompareTo(TElSAMLID *Other)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLBaseIDElement_CompareTo(_Handle, (Other != NULL) ? Other->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLBaseIDElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLBaseIDElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLBaseIDElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLBaseIDElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLBaseIDElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLBaseIDElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLBaseIDElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLBaseIDElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElSAMLBaseIDElement::get_NameQualifier(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLBaseIDElement_get_NameQualifier(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-416329181, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLBaseIDElement::set_NameQualifier(const std::string &Value)
{
	SBCheckError(TElSAMLBaseIDElement_set_NameQualifier(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLBaseIDElement::get_SPNameQualifier(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLBaseIDElement_get_SPNameQualifier(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-958183618, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLBaseIDElement::set_SPNameQualifier(const std::string &Value)
{
	SBCheckError(TElSAMLBaseIDElement_set_SPNameQualifier(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSAMLBaseIDElement::TElSAMLBaseIDElement(TElSAMLBaseIDElementHandle handle, TElOwnHandle ownHandle) : TElSAMLID(handle, ownHandle)
{
}

TElSAMLBaseIDElement::TElSAMLBaseIDElement() : TElSAMLID(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLBaseIDElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLBASEIDELEMENT */

#ifdef SB_USE_CLASS_TELSAMLNAMEIDELEMENT

SB_INLINE void TElSAMLNameIDElement::Assign(TElSAMLElement &Other)
{
	SBCheckError(TElSAMLNameIDElement_Assign(_Handle, Other.getHandle()));
}

SB_INLINE void TElSAMLNameIDElement::Assign(TElSAMLElement *Other)
{
	SBCheckError(TElSAMLNameIDElement_Assign(_Handle, (Other != NULL) ? Other->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElSAMLNameIDElement::Clear()
{
	SBCheckError(TElSAMLNameIDElement_Clear(_Handle));
}

bool TElSAMLNameIDElement::CompareTo(TElSAMLID &Other)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLNameIDElement_CompareTo(_Handle, Other.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSAMLNameIDElement::CompareTo(TElSAMLID *Other)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLNameIDElement_CompareTo(_Handle, (Other != NULL) ? Other->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLNameIDElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLNameIDElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLNameIDElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLNameIDElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLNameIDElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLNameIDElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLNameIDElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLNameIDElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElSAMLNameIDElement::get_Value(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLNameIDElement_get_Value(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1573865641, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLNameIDElement::set_Value(const std::string &Value)
{
	SBCheckError(TElSAMLNameIDElement_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLNameIDElement::get_NameQualifier(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLNameIDElement_get_NameQualifier(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(318386129, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLNameIDElement::set_NameQualifier(const std::string &Value)
{
	SBCheckError(TElSAMLNameIDElement_set_NameQualifier(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLNameIDElement::get_SPNameQualifier(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLNameIDElement_get_SPNameQualifier(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-824361899, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLNameIDElement::set_SPNameQualifier(const std::string &Value)
{
	SBCheckError(TElSAMLNameIDElement_set_SPNameQualifier(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLNameIDElement::get_Format(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLNameIDElement_get_Format(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-658707873, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLNameIDElement::set_Format(const std::string &Value)
{
	SBCheckError(TElSAMLNameIDElement_set_Format(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLNameIDElement::get_SPProvidedID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLNameIDElement_get_SPProvidedID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1911942527, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLNameIDElement::set_SPProvidedID(const std::string &Value)
{
	SBCheckError(TElSAMLNameIDElement_set_SPProvidedID(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSAMLNameIDElement::TElSAMLNameIDElement(TElSAMLNameIDElementHandle handle, TElOwnHandle ownHandle) : TElSAMLID(handle, ownHandle)
{
}

TElSAMLNameIDElement::TElSAMLNameIDElement() : TElSAMLID(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLNameIDElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLNAMEIDELEMENT */

#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT

SB_INLINE void TElSAMLEncryptedElement::Clear()
{
	SBCheckError(TElSAMLEncryptedElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLEncryptedElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLEncryptedElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLEncryptedElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLEncryptedElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLEncryptedElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLEncryptedElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLEncryptedElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLEncryptedElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE void TElSAMLEncryptedElement::Encrypt()
{
	SBCheckError(TElSAMLEncryptedElement_Encrypt(_Handle));
}

SB_INLINE void TElSAMLEncryptedElement::Decrypt()
{
	SBCheckError(TElSAMLEncryptedElement_Decrypt(_Handle));
}

void TElSAMLEncryptedElement::get_ElementName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLEncryptedElement_get_ElementName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(351879124, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLEncryptedElement::set_ElementName(const std::string &Value)
{
	SBCheckError(TElSAMLEncryptedElement_set_ElementName(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSAMLEncryptedElement::get_Decrypted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLEncryptedElement_get_Decrypted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLEncryptedElement::set_Decrypted(bool Value)
{
	SBCheckError(TElSAMLEncryptedElement_set_Decrypted(_Handle, (int8_t)Value));
}

TElSAMLEncryptedElement::TElSAMLEncryptedElement(TElSAMLEncryptedElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
}

TElSAMLEncryptedElement::TElSAMLEncryptedElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLEncryptedElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT */

#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDIDELEMENT

SB_INLINE void TElSAMLEncryptedIDElement::Clear()
{
	SBCheckError(TElSAMLEncryptedIDElement_Clear(_Handle));
}

bool TElSAMLEncryptedIDElement::CompareTo(TElSAMLID &Other)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLEncryptedIDElement_CompareTo(_Handle, Other.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSAMLEncryptedIDElement::CompareTo(TElSAMLID *Other)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLEncryptedIDElement_CompareTo(_Handle, (Other != NULL) ? Other->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLEncryptedIDElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLEncryptedIDElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLEncryptedIDElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLEncryptedIDElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLEncryptedIDElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLEncryptedIDElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLEncryptedIDElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLEncryptedIDElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE void TElSAMLEncryptedIDElement::Encrypt()
{
	SBCheckError(TElSAMLEncryptedIDElement_Encrypt(_Handle));
}

SB_INLINE void TElSAMLEncryptedIDElement::Decrypt()
{
	SBCheckError(TElSAMLEncryptedIDElement_Decrypt(_Handle));
}

#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT
TElSAMLEncryptedElement* TElSAMLEncryptedIDElement::get_EncryptedElement()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLEncryptedIDElement_get_EncryptedElement(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptedElement)
		this->_Inst_EncryptedElement = new TElSAMLEncryptedElement(hOutResult, ohFalse);
	else
		this->_Inst_EncryptedElement->updateHandle(hOutResult);
	return this->_Inst_EncryptedElement;
}

SB_INLINE void TElSAMLEncryptedIDElement::set_EncryptedElement(TElSAMLEncryptedElement &Value)
{
	SBCheckError(TElSAMLEncryptedIDElement_set_EncryptedElement(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLEncryptedIDElement::set_EncryptedElement(TElSAMLEncryptedElement *Value)
{
	SBCheckError(TElSAMLEncryptedIDElement_set_EncryptedElement(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT */

TElSAMLID* TElSAMLEncryptedIDElement::get_ID()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLEncryptedIDElement_get_ID(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ID)
		this->_Inst_ID = new TElSAMLID(hOutResult, ohFalse);
	else
		this->_Inst_ID->updateHandle(hOutResult);
	return this->_Inst_ID;
}

SB_INLINE void TElSAMLEncryptedIDElement::set_ID(TElSAMLID &Value)
{
	SBCheckError(TElSAMLEncryptedIDElement_set_ID(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLEncryptedIDElement::set_ID(TElSAMLID *Value)
{
	SBCheckError(TElSAMLEncryptedIDElement_set_ID(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

void TElSAMLEncryptedIDElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT
	this->_Inst_EncryptedElement = NULL;
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT */
	this->_Inst_ID = NULL;
}

TElSAMLEncryptedIDElement::TElSAMLEncryptedIDElement(TElSAMLEncryptedIDElementHandle handle, TElOwnHandle ownHandle) : TElSAMLID(handle, ownHandle)
{
	initInstances();
}

TElSAMLEncryptedIDElement::TElSAMLEncryptedIDElement() : TElSAMLID(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLEncryptedIDElement_Create(&_Handle));
}

TElSAMLEncryptedIDElement::~TElSAMLEncryptedIDElement()
{
#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT
	delete this->_Inst_EncryptedElement;
	this->_Inst_EncryptedElement = NULL;
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT */
	delete this->_Inst_ID;
	this->_Inst_ID = NULL;
}
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDIDELEMENT */

#ifdef SB_USE_CLASS_TELSAMLISSUERELEMENT

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLIssuerElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLIssuerElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLIssuerElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLIssuerElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

TElSAMLIssuerElement::TElSAMLIssuerElement(TElSAMLIssuerElementHandle handle, TElOwnHandle ownHandle) : TElSAMLNameIDElement(handle, ownHandle)
{
}

TElSAMLIssuerElement::TElSAMLIssuerElement() : TElSAMLNameIDElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLIssuerElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLISSUERELEMENT */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONTYPE

TElSAMLAssertionType::TElSAMLAssertionType(TElSAMLAssertionTypeHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
}

TElSAMLAssertionType::TElSAMLAssertionType() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLAssertionType_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLASSERTIONTYPE */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONIDREFELEMENT

SB_INLINE void TElSAMLAssertionIDRefElement::Clear()
{
	SBCheckError(TElSAMLAssertionIDRefElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLAssertionIDRefElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLAssertionIDRefElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLAssertionIDRefElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLAssertionIDRefElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLAssertionIDRefElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAssertionIDRefElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLAssertionIDRefElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAssertionIDRefElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElSAMLAssertionIDRefElement::get_Value(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAssertionIDRefElement_get_Value(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2101556489, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLAssertionIDRefElement::set_Value(const std::string &Value)
{
	SBCheckError(TElSAMLAssertionIDRefElement_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSAMLAssertionIDRefElement::TElSAMLAssertionIDRefElement(TElSAMLAssertionIDRefElementHandle handle, TElOwnHandle ownHandle) : TElSAMLAssertionType(handle, ownHandle)
{
}

TElSAMLAssertionIDRefElement::TElSAMLAssertionIDRefElement() : TElSAMLAssertionType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLAssertionIDRefElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLASSERTIONIDREFELEMENT */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONURIREFELEMENT

SB_INLINE void TElSAMLAssertionURIRefElement::Clear()
{
	SBCheckError(TElSAMLAssertionURIRefElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLAssertionURIRefElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLAssertionURIRefElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLAssertionURIRefElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLAssertionURIRefElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLAssertionURIRefElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAssertionURIRefElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLAssertionURIRefElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAssertionURIRefElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElSAMLAssertionURIRefElement::get_Value(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAssertionURIRefElement_get_Value(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-538814587, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLAssertionURIRefElement::set_Value(const std::string &Value)
{
	SBCheckError(TElSAMLAssertionURIRefElement_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSAMLAssertionURIRefElement::TElSAMLAssertionURIRefElement(TElSAMLAssertionURIRefElementHandle handle, TElOwnHandle ownHandle) : TElSAMLAssertionType(handle, ownHandle)
{
}

TElSAMLAssertionURIRefElement::TElSAMLAssertionURIRefElement() : TElSAMLAssertionType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLAssertionURIRefElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLASSERTIONURIREFELEMENT */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONELEMENT

SB_INLINE void TElSAMLAssertionElement::Clear()
{
	SBCheckError(TElSAMLAssertionElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLAssertionElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLAssertionElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLAssertionElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLAssertionElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLAssertionElement::LoadFromXML(TElXMLDOMElement &Element, bool ClearBefore)
{
	SBCheckError(TElSAMLAssertionElement_LoadFromXML_1(_Handle, Element.getHandle(), (int8_t)ClearBefore));
}

SB_INLINE void TElSAMLAssertionElement::LoadFromXML(TElXMLDOMElement *Element, bool ClearBefore)
{
	SBCheckError(TElSAMLAssertionElement_LoadFromXML_1(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, (int8_t)ClearBefore));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLAssertionElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAssertionElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLAssertionElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAssertionElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATEMENTABSTRACTTYPE
SB_INLINE int32_t TElSAMLAssertionElement::AddStatement(TElSAMLStatementAbstractType &St)
{
	int32_t OutResult;
	SBCheckError(TElSAMLAssertionElement_AddStatement(_Handle, St.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLAssertionElement::AddStatement(TElSAMLStatementAbstractType *St)
{
	int32_t OutResult;
	SBCheckError(TElSAMLAssertionElement_AddStatement(_Handle, (St != NULL) ? St->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLSTATEMENTABSTRACTTYPE */

SB_INLINE void TElSAMLAssertionElement::RemoveStatement(int32_t Index)
{
	SBCheckError(TElSAMLAssertionElement_RemoveStatement(_Handle, Index));
}

bool TElSAMLAssertionElement::get_Signed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLAssertionElement_get_Signed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLAssertionElement::set_Signed(bool Value)
{
	SBCheckError(TElSAMLAssertionElement_set_Signed(_Handle, (int8_t)Value));
}

void TElSAMLAssertionElement::get_Version(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAssertionElement_get_Version(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2133065494, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLAssertionElement::set_Version(const std::string &Value)
{
	SBCheckError(TElSAMLAssertionElement_set_Version(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLAssertionElement::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAssertionElement_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1006347946, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLAssertionElement::set_ID(const std::string &Value)
{
	SBCheckError(TElSAMLAssertionElement_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElSAMLAssertionElement::get_IssueInstant()
{
	int64_t OutResult;
	SBCheckError(TElSAMLAssertionElement_get_IssueInstant(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLAssertionElement::set_IssueInstant(int64_t Value)
{
	SBCheckError(TElSAMLAssertionElement_set_IssueInstant(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELSAMLISSUERELEMENT
TElSAMLIssuerElement* TElSAMLAssertionElement::get_Issuer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAssertionElement_get_Issuer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Issuer)
		this->_Inst_Issuer = new TElSAMLIssuerElement(hOutResult, ohFalse);
	else
		this->_Inst_Issuer->updateHandle(hOutResult);
	return this->_Inst_Issuer;
}

SB_INLINE void TElSAMLAssertionElement::set_Issuer(TElSAMLIssuerElement &Value)
{
	SBCheckError(TElSAMLAssertionElement_set_Issuer(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLAssertionElement::set_Issuer(TElSAMLIssuerElement *Value)
{
	SBCheckError(TElSAMLAssertionElement_set_Issuer(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLISSUERELEMENT */

#ifdef SB_USE_CLASS_TELXMLSIGNATURE
TElXMLSignature* TElSAMLAssertionElement::get_Signature()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAssertionElement_get_Signature(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signature)
		this->_Inst_Signature = new TElXMLSignature(hOutResult, ohFalse);
	else
		this->_Inst_Signature->updateHandle(hOutResult);
	return this->_Inst_Signature;
}
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTELEMENT
TElSAMLSubjectElement* TElSAMLAssertionElement::get_Subject()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAssertionElement_get_Subject(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Subject)
		this->_Inst_Subject = new TElSAMLSubjectElement(hOutResult, ohFalse);
	else
		this->_Inst_Subject->updateHandle(hOutResult);
	return this->_Inst_Subject;
}

SB_INLINE void TElSAMLAssertionElement::set_Subject(TElSAMLSubjectElement &Value)
{
	SBCheckError(TElSAMLAssertionElement_set_Subject(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLAssertionElement::set_Subject(TElSAMLSubjectElement *Value)
{
	SBCheckError(TElSAMLAssertionElement_set_Subject(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLSUBJECTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLCONDITIONSELEMENT
TElSAMLConditionsElement* TElSAMLAssertionElement::get_Conditions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAssertionElement_get_Conditions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Conditions)
		this->_Inst_Conditions = new TElSAMLConditionsElement(hOutResult, ohFalse);
	else
		this->_Inst_Conditions->updateHandle(hOutResult);
	return this->_Inst_Conditions;
}

SB_INLINE void TElSAMLAssertionElement::set_Conditions(TElSAMLConditionsElement &Value)
{
	SBCheckError(TElSAMLAssertionElement_set_Conditions(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLAssertionElement::set_Conditions(TElSAMLConditionsElement *Value)
{
	SBCheckError(TElSAMLAssertionElement_set_Conditions(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLCONDITIONSELEMENT */

#ifdef SB_USE_CLASS_TELSAMLADVICEELEMENT
TElSAMLAdviceElement* TElSAMLAssertionElement::get_Advice()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAssertionElement_get_Advice(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Advice)
		this->_Inst_Advice = new TElSAMLAdviceElement(hOutResult, ohFalse);
	else
		this->_Inst_Advice->updateHandle(hOutResult);
	return this->_Inst_Advice;
}

SB_INLINE void TElSAMLAssertionElement::set_Advice(TElSAMLAdviceElement &Value)
{
	SBCheckError(TElSAMLAssertionElement_set_Advice(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLAssertionElement::set_Advice(TElSAMLAdviceElement *Value)
{
	SBCheckError(TElSAMLAssertionElement_set_Advice(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLADVICEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATEMENTABSTRACTTYPE
TElSAMLStatementAbstractType* TElSAMLAssertionElement::get_Statements(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAssertionElement_get_Statements(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Statements)
		this->_Inst_Statements = new TElSAMLStatementAbstractType(hOutResult, ohFalse);
	else
		this->_Inst_Statements->updateHandle(hOutResult);
	return this->_Inst_Statements;
}
#endif /* SB_USE_CLASS_TELSAMLSTATEMENTABSTRACTTYPE */

SB_INLINE int32_t TElSAMLAssertionElement::get_StatementCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLAssertionElement_get_StatementCount(_Handle, &OutResult));
	return OutResult;
}

void TElSAMLAssertionElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLISSUERELEMENT
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TELSAMLISSUERELEMENT */
#ifdef SB_USE_CLASS_TELXMLSIGNATURE
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */
#ifdef SB_USE_CLASS_TELSAMLSUBJECTELEMENT
	this->_Inst_Subject = NULL;
#endif /* SB_USE_CLASS_TELSAMLSUBJECTELEMENT */
#ifdef SB_USE_CLASS_TELSAMLCONDITIONSELEMENT
	this->_Inst_Conditions = NULL;
#endif /* SB_USE_CLASS_TELSAMLCONDITIONSELEMENT */
#ifdef SB_USE_CLASS_TELSAMLADVICEELEMENT
	this->_Inst_Advice = NULL;
#endif /* SB_USE_CLASS_TELSAMLADVICEELEMENT */
#ifdef SB_USE_CLASS_TELSAMLSTATEMENTABSTRACTTYPE
	this->_Inst_Statements = NULL;
#endif /* SB_USE_CLASS_TELSAMLSTATEMENTABSTRACTTYPE */
}

TElSAMLAssertionElement::TElSAMLAssertionElement(TElSAMLAssertionElementHandle handle, TElOwnHandle ownHandle) : TElSAMLAssertionType(handle, ownHandle)
{
	initInstances();
}

TElSAMLAssertionElement::TElSAMLAssertionElement() : TElSAMLAssertionType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLAssertionElement_Create(&_Handle));
}

TElSAMLAssertionElement::~TElSAMLAssertionElement()
{
#ifdef SB_USE_CLASS_TELSAMLISSUERELEMENT
	delete this->_Inst_Issuer;
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TELSAMLISSUERELEMENT */
#ifdef SB_USE_CLASS_TELXMLSIGNATURE
	delete this->_Inst_Signature;
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */
#ifdef SB_USE_CLASS_TELSAMLSUBJECTELEMENT
	delete this->_Inst_Subject;
	this->_Inst_Subject = NULL;
#endif /* SB_USE_CLASS_TELSAMLSUBJECTELEMENT */
#ifdef SB_USE_CLASS_TELSAMLCONDITIONSELEMENT
	delete this->_Inst_Conditions;
	this->_Inst_Conditions = NULL;
#endif /* SB_USE_CLASS_TELSAMLCONDITIONSELEMENT */
#ifdef SB_USE_CLASS_TELSAMLADVICEELEMENT
	delete this->_Inst_Advice;
	this->_Inst_Advice = NULL;
#endif /* SB_USE_CLASS_TELSAMLADVICEELEMENT */
#ifdef SB_USE_CLASS_TELSAMLSTATEMENTABSTRACTTYPE
	delete this->_Inst_Statements;
	this->_Inst_Statements = NULL;
#endif /* SB_USE_CLASS_TELSAMLSTATEMENTABSTRACTTYPE */
}
#endif /* SB_USE_CLASS_TELSAMLASSERTIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDASSERTIONELEMENT

SB_INLINE void TElSAMLEncryptedAssertionElement::Clear()
{
	SBCheckError(TElSAMLEncryptedAssertionElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLEncryptedAssertionElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLEncryptedAssertionElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLEncryptedAssertionElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLEncryptedAssertionElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLEncryptedAssertionElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLEncryptedAssertionElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLEncryptedAssertionElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLEncryptedAssertionElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE void TElSAMLEncryptedAssertionElement::Decrypt()
{
	SBCheckError(TElSAMLEncryptedAssertionElement_Decrypt(_Handle));
}

bool TElSAMLEncryptedAssertionElement::get_Decrypted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLEncryptedAssertionElement_get_Decrypted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT
TElSAMLEncryptedElement* TElSAMLEncryptedAssertionElement::get_EncryptedElement()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLEncryptedAssertionElement_get_EncryptedElement(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptedElement)
		this->_Inst_EncryptedElement = new TElSAMLEncryptedElement(hOutResult, ohFalse);
	else
		this->_Inst_EncryptedElement->updateHandle(hOutResult);
	return this->_Inst_EncryptedElement;
}
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT */

void TElSAMLEncryptedAssertionElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT
	this->_Inst_EncryptedElement = NULL;
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT */
}

TElSAMLEncryptedAssertionElement::TElSAMLEncryptedAssertionElement(TElSAMLEncryptedAssertionElementHandle handle, TElOwnHandle ownHandle) : TElSAMLAssertionElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLEncryptedAssertionElement::TElSAMLEncryptedAssertionElement() : TElSAMLAssertionElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLEncryptedAssertionElement_Create(&_Handle));
}

TElSAMLEncryptedAssertionElement::~TElSAMLEncryptedAssertionElement()
{
#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT
	delete this->_Inst_EncryptedElement;
	this->_Inst_EncryptedElement = NULL;
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT */
}
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDASSERTIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLCONDITIONABSTRACTTYPE

TElSAMLConditionAbstractType::TElSAMLConditionAbstractType(TElSAMLConditionAbstractTypeHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
}

TElSAMLConditionAbstractType::TElSAMLConditionAbstractType() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLConditionAbstractType_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLCONDITIONABSTRACTTYPE */

#ifdef SB_USE_CLASS_TELSAMLAUDIENCEELEMENT

SB_INLINE void TElSAMLAudienceElement::Clear()
{
	SBCheckError(TElSAMLAudienceElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLAudienceElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLAudienceElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLAudienceElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLAudienceElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLAudienceElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAudienceElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLAudienceElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAudienceElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElSAMLAudienceElement::get_Value(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAudienceElement_get_Value(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1019261914, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLAudienceElement::set_Value(const std::string &Value)
{
	SBCheckError(TElSAMLAudienceElement_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSAMLAudienceElement::TElSAMLAudienceElement(TElSAMLAudienceElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
}

TElSAMLAudienceElement::TElSAMLAudienceElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLAudienceElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLAUDIENCEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUDIENCERESTRICTIONELEMENT

SB_INLINE void TElSAMLAudienceRestrictionElement::Clear()
{
	SBCheckError(TElSAMLAudienceRestrictionElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLAudienceRestrictionElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLAudienceRestrictionElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLAudienceRestrictionElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLAudienceRestrictionElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLAudienceRestrictionElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAudienceRestrictionElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLAudienceRestrictionElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAudienceRestrictionElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int32_t TElSAMLAudienceRestrictionElement::AddAudience()
{
	int32_t OutResult;
	SBCheckError(TElSAMLAudienceRestrictionElement_AddAudience(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLAudienceRestrictionElement::RemoveAudience(int32_t Index)
{
	SBCheckError(TElSAMLAudienceRestrictionElement_RemoveAudience(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELSAMLAUDIENCEELEMENT
TElSAMLAudienceElement* TElSAMLAudienceRestrictionElement::get_AudienceList(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAudienceRestrictionElement_get_AudienceList(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AudienceList)
		this->_Inst_AudienceList = new TElSAMLAudienceElement(hOutResult, ohFalse);
	else
		this->_Inst_AudienceList->updateHandle(hOutResult);
	return this->_Inst_AudienceList;
}
#endif /* SB_USE_CLASS_TELSAMLAUDIENCEELEMENT */

SB_INLINE int32_t TElSAMLAudienceRestrictionElement::get_AudienceCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLAudienceRestrictionElement_get_AudienceCount(_Handle, &OutResult));
	return OutResult;
}

void TElSAMLAudienceRestrictionElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLAUDIENCEELEMENT
	this->_Inst_AudienceList = NULL;
#endif /* SB_USE_CLASS_TELSAMLAUDIENCEELEMENT */
}

TElSAMLAudienceRestrictionElement::TElSAMLAudienceRestrictionElement(TElSAMLAudienceRestrictionElementHandle handle, TElOwnHandle ownHandle) : TElSAMLConditionAbstractType(handle, ownHandle)
{
	initInstances();
}

TElSAMLAudienceRestrictionElement::TElSAMLAudienceRestrictionElement() : TElSAMLConditionAbstractType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLAudienceRestrictionElement_Create(&_Handle));
}

TElSAMLAudienceRestrictionElement::~TElSAMLAudienceRestrictionElement()
{
#ifdef SB_USE_CLASS_TELSAMLAUDIENCEELEMENT
	delete this->_Inst_AudienceList;
	this->_Inst_AudienceList = NULL;
#endif /* SB_USE_CLASS_TELSAMLAUDIENCEELEMENT */
}
#endif /* SB_USE_CLASS_TELSAMLAUDIENCERESTRICTIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLONETIMEUSEELEMENT

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLOneTimeUseElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLOneTimeUseElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLOneTimeUseElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLOneTimeUseElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLOneTimeUseElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLOneTimeUseElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLOneTimeUseElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLOneTimeUseElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

TElSAMLOneTimeUseElement::TElSAMLOneTimeUseElement(TElSAMLOneTimeUseElementHandle handle, TElOwnHandle ownHandle) : TElSAMLConditionAbstractType(handle, ownHandle)
{
}

TElSAMLOneTimeUseElement::TElSAMLOneTimeUseElement() : TElSAMLConditionAbstractType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLOneTimeUseElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLONETIMEUSEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLPROXYRESTRICTIONELEMENT

SB_INLINE void TElSAMLProxyRestrictionElement::Clear()
{
	SBCheckError(TElSAMLProxyRestrictionElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLProxyRestrictionElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLProxyRestrictionElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLProxyRestrictionElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLProxyRestrictionElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLProxyRestrictionElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLProxyRestrictionElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLProxyRestrictionElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLProxyRestrictionElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int32_t TElSAMLProxyRestrictionElement::AddAudience()
{
	int32_t OutResult;
	SBCheckError(TElSAMLProxyRestrictionElement_AddAudience(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLProxyRestrictionElement::RemoveAudience(int32_t Index)
{
	SBCheckError(TElSAMLProxyRestrictionElement_RemoveAudience(_Handle, Index));
}

SB_INLINE int32_t TElSAMLProxyRestrictionElement::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElSAMLProxyRestrictionElement_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSAMLAUDIENCEELEMENT
TElSAMLAudienceElement* TElSAMLProxyRestrictionElement::get_AudienceList(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLProxyRestrictionElement_get_AudienceList(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AudienceList)
		this->_Inst_AudienceList = new TElSAMLAudienceElement(hOutResult, ohFalse);
	else
		this->_Inst_AudienceList->updateHandle(hOutResult);
	return this->_Inst_AudienceList;
}
#endif /* SB_USE_CLASS_TELSAMLAUDIENCEELEMENT */

SB_INLINE int32_t TElSAMLProxyRestrictionElement::get_AudienceCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLProxyRestrictionElement_get_AudienceCount(_Handle, &OutResult));
	return OutResult;
}

void TElSAMLProxyRestrictionElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLAUDIENCEELEMENT
	this->_Inst_AudienceList = NULL;
#endif /* SB_USE_CLASS_TELSAMLAUDIENCEELEMENT */
}

TElSAMLProxyRestrictionElement::TElSAMLProxyRestrictionElement(TElSAMLProxyRestrictionElementHandle handle, TElOwnHandle ownHandle) : TElSAMLConditionAbstractType(handle, ownHandle)
{
	initInstances();
}

TElSAMLProxyRestrictionElement::TElSAMLProxyRestrictionElement() : TElSAMLConditionAbstractType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLProxyRestrictionElement_Create(&_Handle));
}

TElSAMLProxyRestrictionElement::~TElSAMLProxyRestrictionElement()
{
#ifdef SB_USE_CLASS_TELSAMLAUDIENCEELEMENT
	delete this->_Inst_AudienceList;
	this->_Inst_AudienceList = NULL;
#endif /* SB_USE_CLASS_TELSAMLAUDIENCEELEMENT */
}
#endif /* SB_USE_CLASS_TELSAMLPROXYRESTRICTIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTLOCALITYELEMENT

SB_INLINE void TElSAMLSubjectLocalityElement::Clear()
{
	SBCheckError(TElSAMLSubjectLocalityElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLSubjectLocalityElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLSubjectLocalityElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLSubjectLocalityElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLSubjectLocalityElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLSubjectLocalityElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLSubjectLocalityElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLSubjectLocalityElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLSubjectLocalityElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElSAMLSubjectLocalityElement::get_Address(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLSubjectLocalityElement_get_Address(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(709745831, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLSubjectLocalityElement::set_Address(const std::string &Value)
{
	SBCheckError(TElSAMLSubjectLocalityElement_set_Address(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLSubjectLocalityElement::get_DNSName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLSubjectLocalityElement_get_DNSName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1344459917, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLSubjectLocalityElement::set_DNSName(const std::string &Value)
{
	SBCheckError(TElSAMLSubjectLocalityElement_set_DNSName(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSAMLSubjectLocalityElement::TElSAMLSubjectLocalityElement(TElSAMLSubjectLocalityElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
}

TElSAMLSubjectLocalityElement::TElSAMLSubjectLocalityElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLSubjectLocalityElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLSUBJECTLOCALITYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUTHNCONTEXTELEMENT

SB_INLINE void TElSAMLAuthnContextElement::Clear()
{
	SBCheckError(TElSAMLAuthnContextElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLAuthnContextElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLAuthnContextElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLAuthnContextElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLAuthnContextElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLAuthnContextElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAuthnContextElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLAuthnContextElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAuthnContextElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

TSBSAMLAuthnContextChoice TElSAMLAuthnContextElement::get_Choice()
{
	TSBSAMLAuthnContextChoiceRaw OutResultRaw = 0;
	SBCheckError(TElSAMLAuthnContextElement_get_Choice(_Handle, &OutResultRaw));
	return (TSBSAMLAuthnContextChoice)OutResultRaw;
}

SB_INLINE void TElSAMLAuthnContextElement::set_Choice(TSBSAMLAuthnContextChoice Value)
{
	SBCheckError(TElSAMLAuthnContextElement_set_Choice(_Handle, (TSBSAMLAuthnContextChoiceRaw)Value));
}

void TElSAMLAuthnContextElement::get_AuthnContextClassRef(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAuthnContextElement_get_AuthnContextClassRef(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1888874211, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLAuthnContextElement::set_AuthnContextClassRef(const std::string &Value)
{
	SBCheckError(TElSAMLAuthnContextElement_set_AuthnContextClassRef(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSAMLElement* TElSAMLAuthnContextElement::get_AuthnContextDecl()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAuthnContextElement_get_AuthnContextDecl(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AuthnContextDecl)
		this->_Inst_AuthnContextDecl = new TElSAMLElement(hOutResult, ohFalse);
	else
		this->_Inst_AuthnContextDecl->updateHandle(hOutResult);
	return this->_Inst_AuthnContextDecl;
}

SB_INLINE void TElSAMLAuthnContextElement::set_AuthnContextDecl(TElSAMLElement &Value)
{
	SBCheckError(TElSAMLAuthnContextElement_set_AuthnContextDecl(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLAuthnContextElement::set_AuthnContextDecl(TElSAMLElement *Value)
{
	SBCheckError(TElSAMLAuthnContextElement_set_AuthnContextDecl(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

void TElSAMLAuthnContextElement::get_AuthnContextDeclRef(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAuthnContextElement_get_AuthnContextDeclRef(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1357102068, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLAuthnContextElement::set_AuthnContextDeclRef(const std::string &Value)
{
	SBCheckError(TElSAMLAuthnContextElement_set_AuthnContextDeclRef(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSAMLAuthnContextElement::get_AuthenticatingAuthorities()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAuthnContextElement_get_AuthenticatingAuthorities(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AuthenticatingAuthorities)
		this->_Inst_AuthenticatingAuthorities = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_AuthenticatingAuthorities->updateHandle(hOutResult);
	return this->_Inst_AuthenticatingAuthorities;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSAMLAuthnContextElement::get_AuthenticatingAuthorities()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAuthnContextElement_get_AuthenticatingAuthorities(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AuthenticatingAuthorities)
		this->_Inst_AuthenticatingAuthorities = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_AuthenticatingAuthorities->updateHandle(hOutResult);
	return this->_Inst_AuthenticatingAuthorities;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElSAMLAuthnContextElement::initInstances()
{
	this->_Inst_AuthnContextDecl = NULL;
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_AuthenticatingAuthorities = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_AuthenticatingAuthorities = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElSAMLAuthnContextElement::TElSAMLAuthnContextElement(TElSAMLAuthnContextElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLAuthnContextElement::TElSAMLAuthnContextElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLAuthnContextElement_Create(&_Handle));
}

TElSAMLAuthnContextElement::~TElSAMLAuthnContextElement()
{
	delete this->_Inst_AuthnContextDecl;
	this->_Inst_AuthnContextDecl = NULL;
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_AuthenticatingAuthorities;
	this->_Inst_AuthenticatingAuthorities = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_AuthenticatingAuthorities;
	this->_Inst_AuthenticatingAuthorities = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELSAMLAUTHNCONTEXTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUTHNSTATEMENTELEMENT

SB_INLINE void TElSAMLAuthnStatementElement::Clear()
{
	SBCheckError(TElSAMLAuthnStatementElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLAuthnStatementElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLAuthnStatementElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLAuthnStatementElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLAuthnStatementElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLAuthnStatementElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAuthnStatementElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLAuthnStatementElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAuthnStatementElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int64_t TElSAMLAuthnStatementElement::get_AuthnInstant()
{
	int64_t OutResult;
	SBCheckError(TElSAMLAuthnStatementElement_get_AuthnInstant(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLAuthnStatementElement::set_AuthnInstant(int64_t Value)
{
	SBCheckError(TElSAMLAuthnStatementElement_set_AuthnInstant(_Handle, Value));
}

void TElSAMLAuthnStatementElement::get_SessionIndex(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAuthnStatementElement_get_SessionIndex(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-979391094, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLAuthnStatementElement::set_SessionIndex(const std::string &Value)
{
	SBCheckError(TElSAMLAuthnStatementElement_set_SessionIndex(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElSAMLAuthnStatementElement::get_SessionNotOnOrAfter()
{
	int64_t OutResult;
	SBCheckError(TElSAMLAuthnStatementElement_get_SessionNotOnOrAfter(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLAuthnStatementElement::set_SessionNotOnOrAfter(int64_t Value)
{
	SBCheckError(TElSAMLAuthnStatementElement_set_SessionNotOnOrAfter(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELSAMLSUBJECTLOCALITYELEMENT
TElSAMLSubjectLocalityElement* TElSAMLAuthnStatementElement::get_SubjectLocality()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAuthnStatementElement_get_SubjectLocality(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SubjectLocality)
		this->_Inst_SubjectLocality = new TElSAMLSubjectLocalityElement(hOutResult, ohFalse);
	else
		this->_Inst_SubjectLocality->updateHandle(hOutResult);
	return this->_Inst_SubjectLocality;
}

SB_INLINE void TElSAMLAuthnStatementElement::set_SubjectLocality(TElSAMLSubjectLocalityElement &Value)
{
	SBCheckError(TElSAMLAuthnStatementElement_set_SubjectLocality(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLAuthnStatementElement::set_SubjectLocality(TElSAMLSubjectLocalityElement *Value)
{
	SBCheckError(TElSAMLAuthnStatementElement_set_SubjectLocality(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLSUBJECTLOCALITYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUTHNCONTEXTELEMENT
TElSAMLAuthnContextElement* TElSAMLAuthnStatementElement::get_AuthnContext()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAuthnStatementElement_get_AuthnContext(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AuthnContext)
		this->_Inst_AuthnContext = new TElSAMLAuthnContextElement(hOutResult, ohFalse);
	else
		this->_Inst_AuthnContext->updateHandle(hOutResult);
	return this->_Inst_AuthnContext;
}

SB_INLINE void TElSAMLAuthnStatementElement::set_AuthnContext(TElSAMLAuthnContextElement &Value)
{
	SBCheckError(TElSAMLAuthnStatementElement_set_AuthnContext(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLAuthnStatementElement::set_AuthnContext(TElSAMLAuthnContextElement *Value)
{
	SBCheckError(TElSAMLAuthnStatementElement_set_AuthnContext(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLAUTHNCONTEXTELEMENT */

void TElSAMLAuthnStatementElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLSUBJECTLOCALITYELEMENT
	this->_Inst_SubjectLocality = NULL;
#endif /* SB_USE_CLASS_TELSAMLSUBJECTLOCALITYELEMENT */
#ifdef SB_USE_CLASS_TELSAMLAUTHNCONTEXTELEMENT
	this->_Inst_AuthnContext = NULL;
#endif /* SB_USE_CLASS_TELSAMLAUTHNCONTEXTELEMENT */
}

TElSAMLAuthnStatementElement::TElSAMLAuthnStatementElement(TElSAMLAuthnStatementElementHandle handle, TElOwnHandle ownHandle) : TElSAMLStatementAbstractType(handle, ownHandle)
{
	initInstances();
}

TElSAMLAuthnStatementElement::TElSAMLAuthnStatementElement() : TElSAMLStatementAbstractType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLAuthnStatementElement_Create(&_Handle));
}

TElSAMLAuthnStatementElement::~TElSAMLAuthnStatementElement()
{
#ifdef SB_USE_CLASS_TELSAMLSUBJECTLOCALITYELEMENT
	delete this->_Inst_SubjectLocality;
	this->_Inst_SubjectLocality = NULL;
#endif /* SB_USE_CLASS_TELSAMLSUBJECTLOCALITYELEMENT */
#ifdef SB_USE_CLASS_TELSAMLAUTHNCONTEXTELEMENT
	delete this->_Inst_AuthnContext;
	this->_Inst_AuthnContext = NULL;
#endif /* SB_USE_CLASS_TELSAMLAUTHNCONTEXTELEMENT */
}
#endif /* SB_USE_CLASS_TELSAMLAUTHNSTATEMENTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTETYPE

TElSAMLAttributeType::TElSAMLAttributeType(TElSAMLAttributeTypeHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
}

TElSAMLAttributeType::TElSAMLAttributeType() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLAttributeType_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLATTRIBUTETYPE */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEVALUE

SB_INLINE void TElSAMLAttributeValue::Clear()
{
	SBCheckError(TElSAMLAttributeValue_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLAttributeValue::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLAttributeValue_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLAttributeValue::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLAttributeValue_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLAttributeValue::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAttributeValue_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLAttributeValue::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAttributeValue_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElSAMLAttributeValue::get_Value(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAttributeValue_get_Value(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(477033646, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLAttributeValue::set_Value(const std::string &Value)
{
	SBCheckError(TElSAMLAttributeValue_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLAttributeValue::get_ContentType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAttributeValue_get_ContentType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1079452459, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLAttributeValue::set_ContentType(const std::string &Value)
{
	SBCheckError(TElSAMLAttributeValue_set_ContentType(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSAMLAttributeValue::TElSAMLAttributeValue(TElSAMLAttributeValueHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
}

TElSAMLAttributeValue::TElSAMLAttributeValue() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLAttributeValue_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEVALUE */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT

SB_INLINE void TElSAMLAttributeElement::Clear()
{
	SBCheckError(TElSAMLAttributeElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLAttributeElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLAttributeElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLAttributeElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLAttributeElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLAttributeElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAttributeElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLAttributeElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAttributeElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMATTR
SB_INLINE int32_t TElSAMLAttributeElement::AddArbitraryAttribute(TElXMLDOMAttr &Attr)
{
	int32_t OutResult;
	SBCheckError(TElSAMLAttributeElement_AddArbitraryAttribute(_Handle, Attr.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLAttributeElement::AddArbitraryAttribute(TElXMLDOMAttr *Attr)
{
	int32_t OutResult;
	SBCheckError(TElSAMLAttributeElement_AddArbitraryAttribute(_Handle, (Attr != NULL) ? Attr->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

SB_INLINE void TElSAMLAttributeElement::RemoveArbitraryAttribute(int32_t Index)
{
	SBCheckError(TElSAMLAttributeElement_RemoveArbitraryAttribute(_Handle, Index));
}

SB_INLINE int32_t TElSAMLAttributeElement::AddValue()
{
	int32_t OutResult;
	SBCheckError(TElSAMLAttributeElement_AddValue(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLAttributeElement::RemoveValue(int32_t Index)
{
	SBCheckError(TElSAMLAttributeElement_RemoveValue(_Handle, Index));
}

void TElSAMLAttributeElement::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAttributeElement_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1250963866, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLAttributeElement::set_Name(const std::string &Value)
{
	SBCheckError(TElSAMLAttributeElement_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLAttributeElement::get_NameFormat(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAttributeElement_get_NameFormat(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2010801173, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLAttributeElement::set_NameFormat(const std::string &Value)
{
	SBCheckError(TElSAMLAttributeElement_set_NameFormat(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLAttributeElement::get_FriendlyName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAttributeElement_get_FriendlyName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1773911550, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLAttributeElement::set_FriendlyName(const std::string &Value)
{
	SBCheckError(TElSAMLAttributeElement_set_FriendlyName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEVALUE
TElSAMLAttributeValue* TElSAMLAttributeElement::get_Values(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAttributeElement_get_Values(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Values)
		this->_Inst_Values = new TElSAMLAttributeValue(hOutResult, ohFalse);
	else
		this->_Inst_Values->updateHandle(hOutResult);
	return this->_Inst_Values;
}
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEVALUE */

SB_INLINE int32_t TElSAMLAttributeElement::get_ValueCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLAttributeElement_get_ValueCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLDOMATTR
TElXMLDOMAttr* TElSAMLAttributeElement::get_ArbitraryAttributes(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAttributeElement_get_ArbitraryAttributes(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ArbitraryAttributes)
		this->_Inst_ArbitraryAttributes = new TElXMLDOMAttr(hOutResult, ohFalse);
	else
		this->_Inst_ArbitraryAttributes->updateHandle(hOutResult);
	return this->_Inst_ArbitraryAttributes;
}
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

SB_INLINE int32_t TElSAMLAttributeElement::get_ArbitraryAttributeCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLAttributeElement_get_ArbitraryAttributeCount(_Handle, &OutResult));
	return OutResult;
}

void TElSAMLAttributeElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEVALUE
	this->_Inst_Values = NULL;
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEVALUE */
#ifdef SB_USE_CLASS_TELXMLDOMATTR
	this->_Inst_ArbitraryAttributes = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMATTR */
}

TElSAMLAttributeElement::TElSAMLAttributeElement(TElSAMLAttributeElementHandle handle, TElOwnHandle ownHandle) : TElSAMLAttributeType(handle, ownHandle)
{
	initInstances();
}

TElSAMLAttributeElement::TElSAMLAttributeElement() : TElSAMLAttributeType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLAttributeElement_Create(&_Handle));
}

TElSAMLAttributeElement::~TElSAMLAttributeElement()
{
#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEVALUE
	delete this->_Inst_Values;
	this->_Inst_Values = NULL;
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEVALUE */
#ifdef SB_USE_CLASS_TELXMLDOMATTR
	delete this->_Inst_ArbitraryAttributes;
	this->_Inst_ArbitraryAttributes = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMATTR */
}
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDATTRIBUTEELEMENT

SB_INLINE void TElSAMLEncryptedAttributeElement::Clear()
{
	SBCheckError(TElSAMLEncryptedAttributeElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLEncryptedAttributeElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLEncryptedAttributeElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLEncryptedAttributeElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLEncryptedAttributeElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLEncryptedAttributeElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLEncryptedAttributeElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLEncryptedAttributeElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLEncryptedAttributeElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT
TElSAMLEncryptedElement* TElSAMLEncryptedAttributeElement::get_EncryptedElement()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLEncryptedAttributeElement_get_EncryptedElement(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptedElement)
		this->_Inst_EncryptedElement = new TElSAMLEncryptedElement(hOutResult, ohFalse);
	else
		this->_Inst_EncryptedElement->updateHandle(hOutResult);
	return this->_Inst_EncryptedElement;
}

SB_INLINE void TElSAMLEncryptedAttributeElement::set_EncryptedElement(TElSAMLEncryptedElement &Value)
{
	SBCheckError(TElSAMLEncryptedAttributeElement_set_EncryptedElement(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLEncryptedAttributeElement::set_EncryptedElement(TElSAMLEncryptedElement *Value)
{
	SBCheckError(TElSAMLEncryptedAttributeElement_set_EncryptedElement(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT */

void TElSAMLEncryptedAttributeElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT
	this->_Inst_EncryptedElement = NULL;
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT */
}

TElSAMLEncryptedAttributeElement::TElSAMLEncryptedAttributeElement(TElSAMLEncryptedAttributeElementHandle handle, TElOwnHandle ownHandle) : TElSAMLAttributeType(handle, ownHandle)
{
	initInstances();
}

TElSAMLEncryptedAttributeElement::TElSAMLEncryptedAttributeElement() : TElSAMLAttributeType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLEncryptedAttributeElement_Create(&_Handle));
}

TElSAMLEncryptedAttributeElement::~TElSAMLEncryptedAttributeElement()
{
#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT
	delete this->_Inst_EncryptedElement;
	this->_Inst_EncryptedElement = NULL;
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT */
}
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDATTRIBUTEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTESTATEMENTELEMENT

SB_INLINE void TElSAMLAttributeStatementElement::Clear()
{
	SBCheckError(TElSAMLAttributeStatementElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLAttributeStatementElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLAttributeStatementElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLAttributeStatementElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLAttributeStatementElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLAttributeStatementElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAttributeStatementElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLAttributeStatementElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAttributeStatementElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTETYPE
SB_INLINE int32_t TElSAMLAttributeStatementElement::AddAttribute(TElSAMLAttributeType &Attr)
{
	int32_t OutResult;
	SBCheckError(TElSAMLAttributeStatementElement_AddAttribute(_Handle, Attr.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLAttributeStatementElement::AddAttribute(TElSAMLAttributeType *Attr)
{
	int32_t OutResult;
	SBCheckError(TElSAMLAttributeStatementElement_AddAttribute(_Handle, (Attr != NULL) ? Attr->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTETYPE */

SB_INLINE void TElSAMLAttributeStatementElement::RemoveAttribute(int32_t Index)
{
	SBCheckError(TElSAMLAttributeStatementElement_RemoveAttribute(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTETYPE
TElSAMLAttributeType* TElSAMLAttributeStatementElement::get_Attributes(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAttributeStatementElement_get_Attributes(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Attributes)
		this->_Inst_Attributes = new TElSAMLAttributeType(hOutResult, ohFalse);
	else
		this->_Inst_Attributes->updateHandle(hOutResult);
	return this->_Inst_Attributes;
}
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTETYPE */

SB_INLINE int32_t TElSAMLAttributeStatementElement::get_AttributeCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLAttributeStatementElement_get_AttributeCount(_Handle, &OutResult));
	return OutResult;
}

void TElSAMLAttributeStatementElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLATTRIBUTETYPE
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTETYPE */
}

TElSAMLAttributeStatementElement::TElSAMLAttributeStatementElement(TElSAMLAttributeStatementElementHandle handle, TElOwnHandle ownHandle) : TElSAMLStatementAbstractType(handle, ownHandle)
{
	initInstances();
}

TElSAMLAttributeStatementElement::TElSAMLAttributeStatementElement() : TElSAMLStatementAbstractType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLAttributeStatementElement_Create(&_Handle));
}

TElSAMLAttributeStatementElement::~TElSAMLAttributeStatementElement()
{
#ifdef SB_USE_CLASS_TELSAMLATTRIBUTETYPE
	delete this->_Inst_Attributes;
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTETYPE */
}
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTESTATEMENTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLACTIONELEMENT

SB_INLINE void TElSAMLActionElement::Clear()
{
	SBCheckError(TElSAMLActionElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLActionElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLActionElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLActionElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLActionElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLActionElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLActionElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLActionElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLActionElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElSAMLActionElement::get__Namespace(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLActionElement_get__Namespace(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1984242241, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLActionElement::set__Namespace(const std::string &Value)
{
	SBCheckError(TElSAMLActionElement_set__Namespace(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSAMLActionElement::TElSAMLActionElement(TElSAMLActionElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
}

TElSAMLActionElement::TElSAMLActionElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLActionElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLACTIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLEVIDENCEELEMENT

SB_INLINE void TElSAMLEvidenceElement::Clear()
{
	SBCheckError(TElSAMLEvidenceElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLEvidenceElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLEvidenceElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLEvidenceElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLEvidenceElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLEvidenceElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLEvidenceElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLEvidenceElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLEvidenceElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONTYPE
SB_INLINE int32_t TElSAMLEvidenceElement::AddAssertion(TElSAMLAssertionType &Assertion)
{
	int32_t OutResult;
	SBCheckError(TElSAMLEvidenceElement_AddAssertion(_Handle, Assertion.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLEvidenceElement::AddAssertion(TElSAMLAssertionType *Assertion)
{
	int32_t OutResult;
	SBCheckError(TElSAMLEvidenceElement_AddAssertion(_Handle, (Assertion != NULL) ? Assertion->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLASSERTIONTYPE */

SB_INLINE void TElSAMLEvidenceElement::RemoveAssertion(int32_t Index)
{
	SBCheckError(TElSAMLEvidenceElement_RemoveAssertion(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELSAMLASSERTIONTYPE
TElSAMLAssertionType* TElSAMLEvidenceElement::get_Assertions(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLEvidenceElement_get_Assertions(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Assertions)
		this->_Inst_Assertions = new TElSAMLAssertionType(hOutResult, ohFalse);
	else
		this->_Inst_Assertions->updateHandle(hOutResult);
	return this->_Inst_Assertions;
}
#endif /* SB_USE_CLASS_TELSAMLASSERTIONTYPE */

SB_INLINE int32_t TElSAMLEvidenceElement::get_AssertionCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLEvidenceElement_get_AssertionCount(_Handle, &OutResult));
	return OutResult;
}

void TElSAMLEvidenceElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLASSERTIONTYPE
	this->_Inst_Assertions = NULL;
#endif /* SB_USE_CLASS_TELSAMLASSERTIONTYPE */
}

TElSAMLEvidenceElement::TElSAMLEvidenceElement(TElSAMLEvidenceElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLEvidenceElement::TElSAMLEvidenceElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLEvidenceElement_Create(&_Handle));
}

TElSAMLEvidenceElement::~TElSAMLEvidenceElement()
{
#ifdef SB_USE_CLASS_TELSAMLASSERTIONTYPE
	delete this->_Inst_Assertions;
	this->_Inst_Assertions = NULL;
#endif /* SB_USE_CLASS_TELSAMLASSERTIONTYPE */
}
#endif /* SB_USE_CLASS_TELSAMLEVIDENCEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUTHZDECISIONSTATEMENTELEMENT

SB_INLINE void TElSAMLAuthzDecisionStatementElement::Clear()
{
	SBCheckError(TElSAMLAuthzDecisionStatementElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLAuthzDecisionStatementElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLAuthzDecisionStatementElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLAuthzDecisionStatementElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLAuthzDecisionStatementElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLAuthzDecisionStatementElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAuthzDecisionStatementElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLAuthzDecisionStatementElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAuthzDecisionStatementElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int32_t TElSAMLAuthzDecisionStatementElement::AddAction()
{
	int32_t OutResult;
	SBCheckError(TElSAMLAuthzDecisionStatementElement_AddAction(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLAuthzDecisionStatementElement::RemoveAction(int32_t Index)
{
	SBCheckError(TElSAMLAuthzDecisionStatementElement_RemoveAction(_Handle, Index));
}

void TElSAMLAuthzDecisionStatementElement::get_Resource(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAuthzDecisionStatementElement_get_Resource(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(69930981, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLAuthzDecisionStatementElement::set_Resource(const std::string &Value)
{
	SBCheckError(TElSAMLAuthzDecisionStatementElement_set_Resource(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBSAMLDecision TElSAMLAuthzDecisionStatementElement::get_Decision()
{
	TSBSAMLDecisionRaw OutResultRaw = 0;
	SBCheckError(TElSAMLAuthzDecisionStatementElement_get_Decision(_Handle, &OutResultRaw));
	return (TSBSAMLDecision)OutResultRaw;
}

SB_INLINE void TElSAMLAuthzDecisionStatementElement::set_Decision(TSBSAMLDecision Value)
{
	SBCheckError(TElSAMLAuthzDecisionStatementElement_set_Decision(_Handle, (TSBSAMLDecisionRaw)Value));
}

#ifdef SB_USE_CLASS_TELSAMLEVIDENCEELEMENT
TElSAMLEvidenceElement* TElSAMLAuthzDecisionStatementElement::get_Evidence()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAuthzDecisionStatementElement_get_Evidence(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Evidence)
		this->_Inst_Evidence = new TElSAMLEvidenceElement(hOutResult, ohFalse);
	else
		this->_Inst_Evidence->updateHandle(hOutResult);
	return this->_Inst_Evidence;
}

SB_INLINE void TElSAMLAuthzDecisionStatementElement::set_Evidence(TElSAMLEvidenceElement &Value)
{
	SBCheckError(TElSAMLAuthzDecisionStatementElement_set_Evidence(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLAuthzDecisionStatementElement::set_Evidence(TElSAMLEvidenceElement *Value)
{
	SBCheckError(TElSAMLAuthzDecisionStatementElement_set_Evidence(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLEVIDENCEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLACTIONELEMENT
TElSAMLActionElement* TElSAMLAuthzDecisionStatementElement::get_Actions(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAuthzDecisionStatementElement_get_Actions(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Actions)
		this->_Inst_Actions = new TElSAMLActionElement(hOutResult, ohFalse);
	else
		this->_Inst_Actions->updateHandle(hOutResult);
	return this->_Inst_Actions;
}
#endif /* SB_USE_CLASS_TELSAMLACTIONELEMENT */

SB_INLINE int32_t TElSAMLAuthzDecisionStatementElement::get_ActionCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLAuthzDecisionStatementElement_get_ActionCount(_Handle, &OutResult));
	return OutResult;
}

void TElSAMLAuthzDecisionStatementElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLEVIDENCEELEMENT
	this->_Inst_Evidence = NULL;
#endif /* SB_USE_CLASS_TELSAMLEVIDENCEELEMENT */
#ifdef SB_USE_CLASS_TELSAMLACTIONELEMENT
	this->_Inst_Actions = NULL;
#endif /* SB_USE_CLASS_TELSAMLACTIONELEMENT */
}

TElSAMLAuthzDecisionStatementElement::TElSAMLAuthzDecisionStatementElement(TElSAMLAuthzDecisionStatementElementHandle handle, TElOwnHandle ownHandle) : TElSAMLStatementAbstractType(handle, ownHandle)
{
	initInstances();
}

TElSAMLAuthzDecisionStatementElement::TElSAMLAuthzDecisionStatementElement() : TElSAMLStatementAbstractType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLAuthzDecisionStatementElement_Create(&_Handle));
}

TElSAMLAuthzDecisionStatementElement::~TElSAMLAuthzDecisionStatementElement()
{
#ifdef SB_USE_CLASS_TELSAMLEVIDENCEELEMENT
	delete this->_Inst_Evidence;
	this->_Inst_Evidence = NULL;
#endif /* SB_USE_CLASS_TELSAMLEVIDENCEELEMENT */
#ifdef SB_USE_CLASS_TELSAMLACTIONELEMENT
	delete this->_Inst_Actions;
	this->_Inst_Actions = NULL;
#endif /* SB_USE_CLASS_TELSAMLACTIONELEMENT */
}
#endif /* SB_USE_CLASS_TELSAMLAUTHZDECISIONSTATEMENTELEMENT */

#ifdef SB_USE_GLOBAL_PROCS_XMLSAMLCORE

#ifdef SB_USE_CLASS_TELXMLNAMESPACEMAP
SB_INLINE TElXMLNamespaceMapHandle GetSAMLNSMap()
{
	TElXMLNamespaceMapHandle OutResult;
	SBCheckError(SBXMLSAMLCore_GetSAMLNSMap(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLNAMESPACEMAP */

#ifdef SB_USE_CLASS_TELXMLNAMESPACEMAP
SB_INLINE void SetSAMLNSMap(TElXMLNamespaceMap &Value)
{
	SBCheckError(SBXMLSAMLCore_SetSAMLNSMap(Value.getHandle()));
}
SB_INLINE void SetSAMLNSMap(TElXMLNamespaceMap *Value)
{
	SBCheckError(SBXMLSAMLCore_SetSAMLNSMap((Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLNAMESPACEMAP */

#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle CreateElementNS(TElXMLDOMDocument &Document, const std::string &URI, const std::string &Name)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBXMLSAMLCore_CreateElementNS(Document.getHandle(), URI.data(), (int32_t)URI.length(), Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMElementHandle CreateElementNS(TElXMLDOMDocument *Document, const std::string &URI, const std::string &Name)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBXMLSAMLCore_CreateElementNS((Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, URI.data(), (int32_t)URI.length(), Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TSTREAM
void StreamToStr(TStream &Input, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLSAMLCore_StreamToStr(Input.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2086217162, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void StreamToStr(TStream *Input, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLSAMLCore_StreamToStr((Input != NULL) ? Input->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2086217162, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
void StreamToStrUTF8(TStream &Input, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLSAMLCore_StreamToStrUTF8(Input.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2108430952, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void StreamToStrUTF8(TStream *Input, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLSAMLCore_StreamToStrUTF8((Input != NULL) ? Input->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2108430952, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
void StreamToArray(TStream &Input, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBXMLSAMLCore_StreamToArray(Input.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(649955445, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void StreamToArray(TStream *Input, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBXMLSAMLCore_StreamToArray((Input != NULL) ? Input->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(649955445, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle FindChildElement(const TElXMLDOMElement &Element, const sb_u16string &Name, const sb_u16string &NamespaceURI)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBXMLSAMLCore_FindChildElement(Element.getHandle(), Name.data(), (int32_t)Name.length(), NamespaceURI.data(), (int32_t)NamespaceURI.length(), &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMElementHandle FindChildElement(const TElXMLDOMElement *Element, const sb_u16string &Name, const sb_u16string &NamespaceURI)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBXMLSAMLCore_FindChildElement((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), NamespaceURI.data(), (int32_t)NamespaceURI.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMElementHandle FindChildElement(const TElXMLDOMElement &Element, const std::wstring &Name, const std::wstring &NamespaceURI)
{
	TElXMLDOMElementHandle OutResult;
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	std::string u16NamespaceURI;
	sb_to_u16string(NamespaceURI, u16NamespaceURI);
	SBCheckError(SBXMLSAMLCore_FindChildElement(Element.getHandle(), reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16NamespaceURI.data()), (int32_t)u16NamespaceURI.length() >> 1, &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMElementHandle FindChildElement(const TElXMLDOMElement *Element, const std::wstring &Name, const std::wstring &NamespaceURI)
{
	TElXMLDOMElementHandle OutResult;
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	std::string u16NamespaceURI;
	sb_to_u16string(NamespaceURI, u16NamespaceURI);
	SBCheckError(SBXMLSAMLCore_FindChildElement((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16NamespaceURI.data()), (int32_t)u16NamespaceURI.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE void FreeList(TList &List)
{
	SBCheckError(SBXMLSAMLCore_FreeList(List.getHandle()));
}
SB_INLINE void FreeList(TList *List)
{
	SBCheckError(SBXMLSAMLCore_FreeList((List != NULL) ? List->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TLIST */

bool XMLStrToBool(const std::string &S)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBXMLSAMLCore_XMLStrToBool(S.data(), (int32_t)S.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void BoolToXMLStr(bool B, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLSAMLCore_BoolToXMLStr((int8_t)B, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(210526793, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void GenerateID(int32_t Len, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLSAMLCore_GenerateID(Len, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2144510525, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void GenerateID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLSAMLCore_GenerateID_1((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1398244008, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void RandomString(int32_t Len, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLSAMLCore_RandomString(Len, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(648203179, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void RandomString(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLSAMLCore_RandomString_1((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(582899431, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SBXMLSAMLCore_DateTimeToString(int64_t DT, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLSAMLCore_DateTimeToString(DT, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1180590213, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t CurrentDateTime()
{
	int64_t OutResult;
	SBCheckError(SBXMLSAMLCore_CurrentDateTime(&OutResult));
	return OutResult;
}

#endif /* SB_USE_GLOBAL_PROCS_XMLSAMLCORE */

};	/* namespace SecureBlackbox */
