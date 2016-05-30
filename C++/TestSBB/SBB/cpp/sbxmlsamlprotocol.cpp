#include "sbxmlsamlprotocol.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLExtensionsElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLExtensionsElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLExtensionsElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLExtensionsElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

TElSAMLExtensionsElement::TElSAMLExtensionsElement(TElSAMLExtensionsElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
}

TElSAMLExtensionsElement::TElSAMLExtensionsElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLExtensionsElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT */

#ifdef SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE TElSAMLRequestAbstractTypeHandle TElSAMLRequestAbstractType::GetInstance(TElXMLDOMDocument &Doc)
{
	TElSAMLRequestAbstractTypeHandle OutResult;
	SBCheckError(TElSAMLRequestAbstractType_GetInstance(Doc.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElSAMLRequestAbstractTypeHandle TElSAMLRequestAbstractType::GetInstance(TElXMLDOMDocument *Doc)
{
	TElSAMLRequestAbstractTypeHandle OutResult;
	SBCheckError(TElSAMLRequestAbstractType_GetInstance((Doc != NULL) ? Doc->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE TElSAMLRequestAbstractTypeHandle TElSAMLRequestAbstractType::GetInstance_Inst(TElXMLDOMDocument &Doc)
{
	TElSAMLRequestAbstractTypeHandle OutResult;
	SBCheckError(TElSAMLRequestAbstractType_GetInstance_1(_Handle, Doc.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElSAMLRequestAbstractTypeHandle TElSAMLRequestAbstractType::GetInstance_Inst(TElXMLDOMDocument *Doc)
{
	TElSAMLRequestAbstractTypeHandle OutResult;
	SBCheckError(TElSAMLRequestAbstractType_GetInstance_1(_Handle, (Doc != NULL) ? Doc->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

SB_INLINE void TElSAMLRequestAbstractType::Clear()
{
	SBCheckError(TElSAMLRequestAbstractType_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLRequestAbstractType::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLRequestAbstractType_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLRequestAbstractType::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLRequestAbstractType_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLRequestAbstractType::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLRequestAbstractType_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLRequestAbstractType::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLRequestAbstractType_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElSAMLRequestAbstractType::get_ElementName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLRequestAbstractType_get_ElementName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1748680126, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLRequestAbstractType::set_ElementName(const std::string &Value)
{
	SBCheckError(TElSAMLRequestAbstractType_set_ElementName(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSAMLRequestAbstractType::get_Signed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLRequestAbstractType_get_Signed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLRequestAbstractType::set_Signed(bool Value)
{
	SBCheckError(TElSAMLRequestAbstractType_set_Signed(_Handle, (int8_t)Value));
}

void TElSAMLRequestAbstractType::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLRequestAbstractType_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1969725398, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLRequestAbstractType::set_ID(const std::string &Value)
{
	SBCheckError(TElSAMLRequestAbstractType_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLRequestAbstractType::get_Version(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLRequestAbstractType_get_Version(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(715920606, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLRequestAbstractType::set_Version(const std::string &Value)
{
	SBCheckError(TElSAMLRequestAbstractType_set_Version(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElSAMLRequestAbstractType::get_IssueInstant()
{
	int64_t OutResult;
	SBCheckError(TElSAMLRequestAbstractType_get_IssueInstant(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLRequestAbstractType::set_IssueInstant(int64_t Value)
{
	SBCheckError(TElSAMLRequestAbstractType_set_IssueInstant(_Handle, Value));
}

void TElSAMLRequestAbstractType::get_Destination(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLRequestAbstractType_get_Destination(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1303455554, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLRequestAbstractType::set_Destination(const std::string &Value)
{
	SBCheckError(TElSAMLRequestAbstractType_set_Destination(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLRequestAbstractType::get_Consent(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLRequestAbstractType_get_Consent(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-157102323, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLRequestAbstractType::set_Consent(const std::string &Value)
{
	SBCheckError(TElSAMLRequestAbstractType_set_Consent(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELSAMLISSUERELEMENT
TElSAMLIssuerElement* TElSAMLRequestAbstractType::get_Issuer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLRequestAbstractType_get_Issuer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Issuer)
		this->_Inst_Issuer = new TElSAMLIssuerElement(hOutResult, ohFalse);
	else
		this->_Inst_Issuer->updateHandle(hOutResult);
	return this->_Inst_Issuer;
}

SB_INLINE void TElSAMLRequestAbstractType::set_Issuer(TElSAMLIssuerElement &Value)
{
	SBCheckError(TElSAMLRequestAbstractType_set_Issuer(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLRequestAbstractType::set_Issuer(TElSAMLIssuerElement *Value)
{
	SBCheckError(TElSAMLRequestAbstractType_set_Issuer(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLISSUERELEMENT */

#ifdef SB_USE_CLASS_TELXMLSIGNATURE
TElXMLSignature* TElSAMLRequestAbstractType::get_Signature()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLRequestAbstractType_get_Signature(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signature)
		this->_Inst_Signature = new TElXMLSignature(hOutResult, ohFalse);
	else
		this->_Inst_Signature->updateHandle(hOutResult);
	return this->_Inst_Signature;
}
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */

#ifdef SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT
TElSAMLExtensionsElement* TElSAMLRequestAbstractType::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLRequestAbstractType_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TElSAMLExtensionsElement(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}

SB_INLINE void TElSAMLRequestAbstractType::set_Extensions(TElSAMLExtensionsElement &Value)
{
	SBCheckError(TElSAMLRequestAbstractType_set_Extensions(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLRequestAbstractType::set_Extensions(TElSAMLExtensionsElement *Value)
{
	SBCheckError(TElSAMLRequestAbstractType_set_Extensions(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT */

void TElSAMLRequestAbstractType::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLISSUERELEMENT
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TELSAMLISSUERELEMENT */
#ifdef SB_USE_CLASS_TELXMLSIGNATURE
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */
#ifdef SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT */
}

TElSAMLRequestAbstractType::TElSAMLRequestAbstractType(TElSAMLRequestAbstractTypeHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLRequestAbstractType::TElSAMLRequestAbstractType() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLRequestAbstractType_Create(&_Handle));
}

TElSAMLRequestAbstractType::~TElSAMLRequestAbstractType()
{
#ifdef SB_USE_CLASS_TELSAMLISSUERELEMENT
	delete this->_Inst_Issuer;
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TELSAMLISSUERELEMENT */
#ifdef SB_USE_CLASS_TELXMLSIGNATURE
	delete this->_Inst_Signature;
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */
#ifdef SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT */
}
#endif /* SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE */

#ifdef SB_USE_CLASS_TELSAMLSTATUSCODEELEMENT

SB_INLINE void TElSAMLStatusCodeElement::Assign(TElSAMLElement &Other)
{
	SBCheckError(TElSAMLStatusCodeElement_Assign(_Handle, Other.getHandle()));
}

SB_INLINE void TElSAMLStatusCodeElement::Assign(TElSAMLElement *Other)
{
	SBCheckError(TElSAMLStatusCodeElement_Assign(_Handle, (Other != NULL) ? Other->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElSAMLStatusCodeElement::Clear()
{
	SBCheckError(TElSAMLStatusCodeElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLStatusCodeElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLStatusCodeElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLStatusCodeElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLStatusCodeElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLStatusCodeElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLStatusCodeElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLStatusCodeElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLStatusCodeElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElSAMLStatusCodeElement::get_Value(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLStatusCodeElement_get_Value(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(781074810, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLStatusCodeElement::set_Value(const std::string &Value)
{
	SBCheckError(TElSAMLStatusCodeElement_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLStatusCodeElement::get_SubValue(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLStatusCodeElement_get_SubValue(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2082538145, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLStatusCodeElement::set_SubValue(const std::string &Value)
{
	SBCheckError(TElSAMLStatusCodeElement_set_SubValue(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSAMLStatusCodeElement::TElSAMLStatusCodeElement(TElSAMLStatusCodeElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
}

TElSAMLStatusCodeElement::TElSAMLStatusCodeElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLStatusCodeElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLSTATUSCODEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATUSMESSAGEELEMENT

SB_INLINE void TElSAMLStatusMessageElement::Assign(TElSAMLElement &Other)
{
	SBCheckError(TElSAMLStatusMessageElement_Assign(_Handle, Other.getHandle()));
}

SB_INLINE void TElSAMLStatusMessageElement::Assign(TElSAMLElement *Other)
{
	SBCheckError(TElSAMLStatusMessageElement_Assign(_Handle, (Other != NULL) ? Other->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElSAMLStatusMessageElement::Clear()
{
	SBCheckError(TElSAMLStatusMessageElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLStatusMessageElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLStatusMessageElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLStatusMessageElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLStatusMessageElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLStatusMessageElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLStatusMessageElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLStatusMessageElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLStatusMessageElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElSAMLStatusMessageElement::get_StatusMessage(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLStatusMessageElement_get_StatusMessage(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-480094207, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLStatusMessageElement::set_StatusMessage(const std::string &Value)
{
	SBCheckError(TElSAMLStatusMessageElement_set_StatusMessage(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSAMLStatusMessageElement::TElSAMLStatusMessageElement(TElSAMLStatusMessageElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
}

TElSAMLStatusMessageElement::TElSAMLStatusMessageElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLStatusMessageElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLSTATUSMESSAGEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATUSDETAILELEMENT

SB_INLINE void TElSAMLStatusDetailElement::Assign(TElSAMLElement &Other)
{
	SBCheckError(TElSAMLStatusDetailElement_Assign(_Handle, Other.getHandle()));
}

SB_INLINE void TElSAMLStatusDetailElement::Assign(TElSAMLElement *Other)
{
	SBCheckError(TElSAMLStatusDetailElement_Assign(_Handle, (Other != NULL) ? Other->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElSAMLStatusDetailElement::Clear()
{
	SBCheckError(TElSAMLStatusDetailElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLStatusDetailElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLStatusDetailElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLStatusDetailElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLStatusDetailElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLStatusDetailElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLStatusDetailElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLStatusDetailElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLStatusDetailElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int32_t TElSAMLStatusDetailElement::AddElement(TElSAMLElement &Elem)
{
	int32_t OutResult;
	SBCheckError(TElSAMLStatusDetailElement_AddElement(_Handle, Elem.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLStatusDetailElement::AddElement(TElSAMLElement *Elem)
{
	int32_t OutResult;
	SBCheckError(TElSAMLStatusDetailElement_AddElement(_Handle, (Elem != NULL) ? Elem->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLStatusDetailElement::RemoveElement(int32_t Index)
{
	SBCheckError(TElSAMLStatusDetailElement_RemoveElement(_Handle, Index));
}

TElSAMLElement* TElSAMLStatusDetailElement::get_Elements(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLStatusDetailElement_get_Elements(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Elements)
		this->_Inst_Elements = new TElSAMLElement(hOutResult, ohFalse);
	else
		this->_Inst_Elements->updateHandle(hOutResult);
	return this->_Inst_Elements;
}

SB_INLINE int32_t TElSAMLStatusDetailElement::get_ElementCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLStatusDetailElement_get_ElementCount(_Handle, &OutResult));
	return OutResult;
}

void TElSAMLStatusDetailElement::initInstances()
{
	this->_Inst_Elements = NULL;
}

TElSAMLStatusDetailElement::TElSAMLStatusDetailElement(TElSAMLStatusDetailElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLStatusDetailElement::TElSAMLStatusDetailElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLStatusDetailElement_Create(&_Handle));
}

TElSAMLStatusDetailElement::~TElSAMLStatusDetailElement()
{
	delete this->_Inst_Elements;
	this->_Inst_Elements = NULL;
}
#endif /* SB_USE_CLASS_TELSAMLSTATUSDETAILELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATUSELEMENT

SB_INLINE void TElSAMLStatusElement::Assign(TElSAMLElement &Other)
{
	SBCheckError(TElSAMLStatusElement_Assign(_Handle, Other.getHandle()));
}

SB_INLINE void TElSAMLStatusElement::Assign(TElSAMLElement *Other)
{
	SBCheckError(TElSAMLStatusElement_Assign(_Handle, (Other != NULL) ? Other->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElSAMLStatusElement::Clear()
{
	SBCheckError(TElSAMLStatusElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLStatusElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLStatusElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLStatusElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLStatusElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLStatusElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLStatusElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLStatusElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLStatusElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATUSCODEELEMENT
TElSAMLStatusCodeElement* TElSAMLStatusElement::get_StatusCode()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLStatusElement_get_StatusCode(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_StatusCode)
		this->_Inst_StatusCode = new TElSAMLStatusCodeElement(hOutResult, ohFalse);
	else
		this->_Inst_StatusCode->updateHandle(hOutResult);
	return this->_Inst_StatusCode;
}

SB_INLINE void TElSAMLStatusElement::set_StatusCode(TElSAMLStatusCodeElement &Value)
{
	SBCheckError(TElSAMLStatusElement_set_StatusCode(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLStatusElement::set_StatusCode(TElSAMLStatusCodeElement *Value)
{
	SBCheckError(TElSAMLStatusElement_set_StatusCode(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLSTATUSCODEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATUSMESSAGEELEMENT
TElSAMLStatusMessageElement* TElSAMLStatusElement::get_StatusMessage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLStatusElement_get_StatusMessage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_StatusMessage)
		this->_Inst_StatusMessage = new TElSAMLStatusMessageElement(hOutResult, ohFalse);
	else
		this->_Inst_StatusMessage->updateHandle(hOutResult);
	return this->_Inst_StatusMessage;
}

SB_INLINE void TElSAMLStatusElement::set_StatusMessage(TElSAMLStatusMessageElement &Value)
{
	SBCheckError(TElSAMLStatusElement_set_StatusMessage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLStatusElement::set_StatusMessage(TElSAMLStatusMessageElement *Value)
{
	SBCheckError(TElSAMLStatusElement_set_StatusMessage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLSTATUSMESSAGEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATUSDETAILELEMENT
TElSAMLStatusDetailElement* TElSAMLStatusElement::get_StatusDetail()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLStatusElement_get_StatusDetail(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_StatusDetail)
		this->_Inst_StatusDetail = new TElSAMLStatusDetailElement(hOutResult, ohFalse);
	else
		this->_Inst_StatusDetail->updateHandle(hOutResult);
	return this->_Inst_StatusDetail;
}

SB_INLINE void TElSAMLStatusElement::set_StatusDetail(TElSAMLStatusDetailElement &Value)
{
	SBCheckError(TElSAMLStatusElement_set_StatusDetail(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLStatusElement::set_StatusDetail(TElSAMLStatusDetailElement *Value)
{
	SBCheckError(TElSAMLStatusElement_set_StatusDetail(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLSTATUSDETAILELEMENT */

void TElSAMLStatusElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLSTATUSCODEELEMENT
	this->_Inst_StatusCode = NULL;
#endif /* SB_USE_CLASS_TELSAMLSTATUSCODEELEMENT */
#ifdef SB_USE_CLASS_TELSAMLSTATUSMESSAGEELEMENT
	this->_Inst_StatusMessage = NULL;
#endif /* SB_USE_CLASS_TELSAMLSTATUSMESSAGEELEMENT */
#ifdef SB_USE_CLASS_TELSAMLSTATUSDETAILELEMENT
	this->_Inst_StatusDetail = NULL;
#endif /* SB_USE_CLASS_TELSAMLSTATUSDETAILELEMENT */
}

TElSAMLStatusElement::TElSAMLStatusElement(TElSAMLStatusElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLStatusElement::TElSAMLStatusElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLStatusElement_Create(&_Handle));
}

TElSAMLStatusElement::~TElSAMLStatusElement()
{
#ifdef SB_USE_CLASS_TELSAMLSTATUSCODEELEMENT
	delete this->_Inst_StatusCode;
	this->_Inst_StatusCode = NULL;
#endif /* SB_USE_CLASS_TELSAMLSTATUSCODEELEMENT */
#ifdef SB_USE_CLASS_TELSAMLSTATUSMESSAGEELEMENT
	delete this->_Inst_StatusMessage;
	this->_Inst_StatusMessage = NULL;
#endif /* SB_USE_CLASS_TELSAMLSTATUSMESSAGEELEMENT */
#ifdef SB_USE_CLASS_TELSAMLSTATUSDETAILELEMENT
	delete this->_Inst_StatusDetail;
	this->_Inst_StatusDetail = NULL;
#endif /* SB_USE_CLASS_TELSAMLSTATUSDETAILELEMENT */
}
#endif /* SB_USE_CLASS_TELSAMLSTATUSELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATUSRESPONSETYPE

SB_INLINE void TElSAMLStatusResponseType::Clear()
{
	SBCheckError(TElSAMLStatusResponseType_Clear(_Handle));
}

SB_INLINE TElSAMLStatusResponseTypeHandle TElSAMLStatusResponseType::CreateByName(const std::string &Name)
{
	TElSAMLStatusResponseTypeHandle OutResult;
	SBCheckError(TElSAMLStatusResponseType_CreateByName(Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElSAMLStatusResponseTypeHandle TElSAMLStatusResponseType::CreateByName_Inst(const std::string &Name)
{
	TElSAMLStatusResponseTypeHandle OutResult;
	SBCheckError(TElSAMLStatusResponseType_CreateByName_1(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE
SB_INLINE TElSAMLStatusResponseTypeHandle TElSAMLStatusResponseType::CreateByRequest(TElSAMLRequestAbstractType &Req)
{
	TElSAMLStatusResponseTypeHandle OutResult;
	SBCheckError(TElSAMLStatusResponseType_CreateByRequest(Req.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElSAMLStatusResponseTypeHandle TElSAMLStatusResponseType::CreateByRequest(TElSAMLRequestAbstractType *Req)
{
	TElSAMLStatusResponseTypeHandle OutResult;
	SBCheckError(TElSAMLStatusResponseType_CreateByRequest((Req != NULL) ? Req->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE */

#ifdef SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE
SB_INLINE TElSAMLStatusResponseTypeHandle TElSAMLStatusResponseType::CreateByRequest_Inst(TElSAMLRequestAbstractType &Req)
{
	TElSAMLStatusResponseTypeHandle OutResult;
	SBCheckError(TElSAMLStatusResponseType_CreateByRequest_1(_Handle, Req.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElSAMLStatusResponseTypeHandle TElSAMLStatusResponseType::CreateByRequest_Inst(TElSAMLRequestAbstractType *Req)
{
	TElSAMLStatusResponseTypeHandle OutResult;
	SBCheckError(TElSAMLStatusResponseType_CreateByRequest_1(_Handle, (Req != NULL) ? Req->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLStatusResponseType::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLStatusResponseType_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLStatusResponseType::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLStatusResponseType_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLStatusResponseType::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLStatusResponseType_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLStatusResponseType::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLStatusResponseType_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElSAMLStatusResponseType::get_ElementName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLStatusResponseType_get_ElementName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1746352572, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLStatusResponseType::set_ElementName(const std::string &Value)
{
	SBCheckError(TElSAMLStatusResponseType_set_ElementName(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSAMLStatusResponseType::get_Signed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLStatusResponseType_get_Signed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLStatusResponseType::set_Signed(bool Value)
{
	SBCheckError(TElSAMLStatusResponseType_set_Signed(_Handle, (int8_t)Value));
}

void TElSAMLStatusResponseType::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLStatusResponseType_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1277467938, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLStatusResponseType::set_ID(const std::string &Value)
{
	SBCheckError(TElSAMLStatusResponseType_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLStatusResponseType::get_InResponseTo(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLStatusResponseType_get_InResponseTo(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1687719987, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLStatusResponseType::set_InResponseTo(const std::string &Value)
{
	SBCheckError(TElSAMLStatusResponseType_set_InResponseTo(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLStatusResponseType::get_Version(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLStatusResponseType_get_Version(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1060431577, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLStatusResponseType::set_Version(const std::string &Value)
{
	SBCheckError(TElSAMLStatusResponseType_set_Version(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElSAMLStatusResponseType::get_IssueInstant()
{
	int64_t OutResult;
	SBCheckError(TElSAMLStatusResponseType_get_IssueInstant(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLStatusResponseType::set_IssueInstant(int64_t Value)
{
	SBCheckError(TElSAMLStatusResponseType_set_IssueInstant(_Handle, Value));
}

void TElSAMLStatusResponseType::get_Destination(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLStatusResponseType_get_Destination(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1302111044, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLStatusResponseType::set_Destination(const std::string &Value)
{
	SBCheckError(TElSAMLStatusResponseType_set_Destination(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLStatusResponseType::get_Consent(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLStatusResponseType_get_Consent(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-482722550, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLStatusResponseType::set_Consent(const std::string &Value)
{
	SBCheckError(TElSAMLStatusResponseType_set_Consent(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELSAMLISSUERELEMENT
TElSAMLIssuerElement* TElSAMLStatusResponseType::get_Issuer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLStatusResponseType_get_Issuer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Issuer)
		this->_Inst_Issuer = new TElSAMLIssuerElement(hOutResult, ohFalse);
	else
		this->_Inst_Issuer->updateHandle(hOutResult);
	return this->_Inst_Issuer;
}

SB_INLINE void TElSAMLStatusResponseType::set_Issuer(TElSAMLIssuerElement &Value)
{
	SBCheckError(TElSAMLStatusResponseType_set_Issuer(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLStatusResponseType::set_Issuer(TElSAMLIssuerElement *Value)
{
	SBCheckError(TElSAMLStatusResponseType_set_Issuer(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLISSUERELEMENT */

#ifdef SB_USE_CLASS_TELXMLSIGNATURE
TElXMLSignature* TElSAMLStatusResponseType::get_Signature()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLStatusResponseType_get_Signature(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signature)
		this->_Inst_Signature = new TElXMLSignature(hOutResult, ohFalse);
	else
		this->_Inst_Signature->updateHandle(hOutResult);
	return this->_Inst_Signature;
}
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */

#ifdef SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT
TElSAMLExtensionsElement* TElSAMLStatusResponseType::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLStatusResponseType_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TElSAMLExtensionsElement(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}

SB_INLINE void TElSAMLStatusResponseType::set_Extensions(TElSAMLExtensionsElement &Value)
{
	SBCheckError(TElSAMLStatusResponseType_set_Extensions(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLStatusResponseType::set_Extensions(TElSAMLExtensionsElement *Value)
{
	SBCheckError(TElSAMLStatusResponseType_set_Extensions(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATUSELEMENT
TElSAMLStatusElement* TElSAMLStatusResponseType::get_Status()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLStatusResponseType_get_Status(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Status)
		this->_Inst_Status = new TElSAMLStatusElement(hOutResult, ohFalse);
	else
		this->_Inst_Status->updateHandle(hOutResult);
	return this->_Inst_Status;
}

SB_INLINE void TElSAMLStatusResponseType::set_Status(TElSAMLStatusElement &Value)
{
	SBCheckError(TElSAMLStatusResponseType_set_Status(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLStatusResponseType::set_Status(TElSAMLStatusElement *Value)
{
	SBCheckError(TElSAMLStatusResponseType_set_Status(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLSTATUSELEMENT */

void TElSAMLStatusResponseType::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLISSUERELEMENT
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TELSAMLISSUERELEMENT */
#ifdef SB_USE_CLASS_TELXMLSIGNATURE
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */
#ifdef SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT */
#ifdef SB_USE_CLASS_TELSAMLSTATUSELEMENT
	this->_Inst_Status = NULL;
#endif /* SB_USE_CLASS_TELSAMLSTATUSELEMENT */
}

TElSAMLStatusResponseType::TElSAMLStatusResponseType(TElSAMLStatusResponseTypeHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLStatusResponseType::TElSAMLStatusResponseType() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLStatusResponseType_Create(&_Handle));
}

TElSAMLStatusResponseType::~TElSAMLStatusResponseType()
{
#ifdef SB_USE_CLASS_TELSAMLISSUERELEMENT
	delete this->_Inst_Issuer;
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TELSAMLISSUERELEMENT */
#ifdef SB_USE_CLASS_TELXMLSIGNATURE
	delete this->_Inst_Signature;
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */
#ifdef SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT */
#ifdef SB_USE_CLASS_TELSAMLSTATUSELEMENT
	delete this->_Inst_Status;
	this->_Inst_Status = NULL;
#endif /* SB_USE_CLASS_TELSAMLSTATUSELEMENT */
}
#endif /* SB_USE_CLASS_TELSAMLSTATUSRESPONSETYPE */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONIDREQUESTELEMENT

SB_INLINE void TElSAMLAssertionIDRequestElement::Clear()
{
	SBCheckError(TElSAMLAssertionIDRequestElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLAssertionIDRequestElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLAssertionIDRequestElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLAssertionIDRequestElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLAssertionIDRequestElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLAssertionIDRequestElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAssertionIDRequestElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLAssertionIDRequestElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAssertionIDRequestElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int32_t TElSAMLAssertionIDRequestElement::AddReference()
{
	int32_t OutResult;
	SBCheckError(TElSAMLAssertionIDRequestElement_AddReference(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLAssertionIDRequestElement::RemoveReference(int32_t Index)
{
	SBCheckError(TElSAMLAssertionIDRequestElement_RemoveReference(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELSAMLASSERTIONIDREFELEMENT
TElSAMLAssertionIDRefElement* TElSAMLAssertionIDRequestElement::get_References(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAssertionIDRequestElement_get_References(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_References)
		this->_Inst_References = new TElSAMLAssertionIDRefElement(hOutResult, ohFalse);
	else
		this->_Inst_References->updateHandle(hOutResult);
	return this->_Inst_References;
}
#endif /* SB_USE_CLASS_TELSAMLASSERTIONIDREFELEMENT */

SB_INLINE int32_t TElSAMLAssertionIDRequestElement::get_ReferenceCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLAssertionIDRequestElement_get_ReferenceCount(_Handle, &OutResult));
	return OutResult;
}

void TElSAMLAssertionIDRequestElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLASSERTIONIDREFELEMENT
	this->_Inst_References = NULL;
#endif /* SB_USE_CLASS_TELSAMLASSERTIONIDREFELEMENT */
}

TElSAMLAssertionIDRequestElement::TElSAMLAssertionIDRequestElement(TElSAMLAssertionIDRequestElementHandle handle, TElOwnHandle ownHandle) : TElSAMLRequestAbstractType(handle, ownHandle)
{
	initInstances();
}

TElSAMLAssertionIDRequestElement::TElSAMLAssertionIDRequestElement() : TElSAMLRequestAbstractType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLAssertionIDRequestElement_Create(&_Handle));
}

TElSAMLAssertionIDRequestElement::~TElSAMLAssertionIDRequestElement()
{
#ifdef SB_USE_CLASS_TELSAMLASSERTIONIDREFELEMENT
	delete this->_Inst_References;
	this->_Inst_References = NULL;
#endif /* SB_USE_CLASS_TELSAMLASSERTIONIDREFELEMENT */
}
#endif /* SB_USE_CLASS_TELSAMLASSERTIONIDREQUESTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTQUERYABSTRACTTYPE

SB_INLINE void TElSAMLSubjectQueryAbstractType::Clear()
{
	SBCheckError(TElSAMLSubjectQueryAbstractType_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLSubjectQueryAbstractType::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLSubjectQueryAbstractType_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLSubjectQueryAbstractType::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLSubjectQueryAbstractType_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLSubjectQueryAbstractType::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLSubjectQueryAbstractType_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLSubjectQueryAbstractType::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLSubjectQueryAbstractType_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTELEMENT
TElSAMLSubjectElement* TElSAMLSubjectQueryAbstractType::get_Subject()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLSubjectQueryAbstractType_get_Subject(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Subject)
		this->_Inst_Subject = new TElSAMLSubjectElement(hOutResult, ohFalse);
	else
		this->_Inst_Subject->updateHandle(hOutResult);
	return this->_Inst_Subject;
}

SB_INLINE void TElSAMLSubjectQueryAbstractType::set_Subject(TElSAMLSubjectElement &Value)
{
	SBCheckError(TElSAMLSubjectQueryAbstractType_set_Subject(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLSubjectQueryAbstractType::set_Subject(TElSAMLSubjectElement *Value)
{
	SBCheckError(TElSAMLSubjectQueryAbstractType_set_Subject(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLSUBJECTELEMENT */

void TElSAMLSubjectQueryAbstractType::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLSUBJECTELEMENT
	this->_Inst_Subject = NULL;
#endif /* SB_USE_CLASS_TELSAMLSUBJECTELEMENT */
}

TElSAMLSubjectQueryAbstractType::TElSAMLSubjectQueryAbstractType(TElSAMLSubjectQueryAbstractTypeHandle handle, TElOwnHandle ownHandle) : TElSAMLRequestAbstractType(handle, ownHandle)
{
	initInstances();
}

TElSAMLSubjectQueryAbstractType::TElSAMLSubjectQueryAbstractType() : TElSAMLRequestAbstractType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLSubjectQueryAbstractType_Create(&_Handle));
}

TElSAMLSubjectQueryAbstractType::~TElSAMLSubjectQueryAbstractType()
{
#ifdef SB_USE_CLASS_TELSAMLSUBJECTELEMENT
	delete this->_Inst_Subject;
	this->_Inst_Subject = NULL;
#endif /* SB_USE_CLASS_TELSAMLSUBJECTELEMENT */
}
#endif /* SB_USE_CLASS_TELSAMLSUBJECTQUERYABSTRACTTYPE */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTQUERYELEMENT

TElSAMLSubjectQueryElement::TElSAMLSubjectQueryElement(TElSAMLSubjectQueryElementHandle handle, TElOwnHandle ownHandle) : TElSAMLSubjectQueryAbstractType(handle, ownHandle)
{
}

TElSAMLSubjectQueryElement::TElSAMLSubjectQueryElement() : TElSAMLSubjectQueryAbstractType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLSubjectQueryElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLSUBJECTQUERYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT

SB_INLINE void TElSAMLRequestedAuthnContextElement::Clear()
{
	SBCheckError(TElSAMLRequestedAuthnContextElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLRequestedAuthnContextElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLRequestedAuthnContextElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLRequestedAuthnContextElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLRequestedAuthnContextElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLRequestedAuthnContextElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLRequestedAuthnContextElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLRequestedAuthnContextElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLRequestedAuthnContextElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

TSBSAMLAuthnContextRefType TElSAMLRequestedAuthnContextElement::get_RefType()
{
	TSBSAMLAuthnContextRefTypeRaw OutResultRaw = 0;
	SBCheckError(TElSAMLRequestedAuthnContextElement_get_RefType(_Handle, &OutResultRaw));
	return (TSBSAMLAuthnContextRefType)OutResultRaw;
}

SB_INLINE void TElSAMLRequestedAuthnContextElement::set_RefType(TSBSAMLAuthnContextRefType Value)
{
	SBCheckError(TElSAMLRequestedAuthnContextElement_set_RefType(_Handle, (TSBSAMLAuthnContextRefTypeRaw)Value));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSAMLRequestedAuthnContextElement::get_List()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLRequestedAuthnContextElement_get_List(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_List)
		this->_Inst_List = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_List->updateHandle(hOutResult);
	return this->_Inst_List;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSAMLRequestedAuthnContextElement::get_List()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLRequestedAuthnContextElement_get_List(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_List)
		this->_Inst_List = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_List->updateHandle(hOutResult);
	return this->_Inst_List;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

TSBSAMLAuthnContextComparisonType TElSAMLRequestedAuthnContextElement::get_Comparison()
{
	TSBSAMLAuthnContextComparisonTypeRaw OutResultRaw = 0;
	SBCheckError(TElSAMLRequestedAuthnContextElement_get_Comparison(_Handle, &OutResultRaw));
	return (TSBSAMLAuthnContextComparisonType)OutResultRaw;
}

SB_INLINE void TElSAMLRequestedAuthnContextElement::set_Comparison(TSBSAMLAuthnContextComparisonType Value)
{
	SBCheckError(TElSAMLRequestedAuthnContextElement_set_Comparison(_Handle, (TSBSAMLAuthnContextComparisonTypeRaw)Value));
}

void TElSAMLRequestedAuthnContextElement::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_List = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_List = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElSAMLRequestedAuthnContextElement::TElSAMLRequestedAuthnContextElement(TElSAMLRequestedAuthnContextElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLRequestedAuthnContextElement::TElSAMLRequestedAuthnContextElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLRequestedAuthnContextElement_Create(&_Handle));
}

TElSAMLRequestedAuthnContextElement::~TElSAMLRequestedAuthnContextElement()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_List;
	this->_Inst_List = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_List;
	this->_Inst_List = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUTHNQUERYELEMENT

SB_INLINE void TElSAMLAuthnQueryElement::Clear()
{
	SBCheckError(TElSAMLAuthnQueryElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLAuthnQueryElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLAuthnQueryElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLAuthnQueryElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLAuthnQueryElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLAuthnQueryElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAuthnQueryElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLAuthnQueryElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAuthnQueryElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT
TElSAMLRequestedAuthnContextElement* TElSAMLAuthnQueryElement::get_RequestedAuthnContext()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAuthnQueryElement_get_RequestedAuthnContext(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RequestedAuthnContext)
		this->_Inst_RequestedAuthnContext = new TElSAMLRequestedAuthnContextElement(hOutResult, ohFalse);
	else
		this->_Inst_RequestedAuthnContext->updateHandle(hOutResult);
	return this->_Inst_RequestedAuthnContext;
}

SB_INLINE void TElSAMLAuthnQueryElement::set_RequestedAuthnContext(TElSAMLRequestedAuthnContextElement &Value)
{
	SBCheckError(TElSAMLAuthnQueryElement_set_RequestedAuthnContext(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLAuthnQueryElement::set_RequestedAuthnContext(TElSAMLRequestedAuthnContextElement *Value)
{
	SBCheckError(TElSAMLAuthnQueryElement_set_RequestedAuthnContext(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT */

void TElSAMLAuthnQueryElement::get_SessionIndex(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAuthnQueryElement_get_SessionIndex(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2072666094, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLAuthnQueryElement::set_SessionIndex(const std::string &Value)
{
	SBCheckError(TElSAMLAuthnQueryElement_set_SessionIndex(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLAuthnQueryElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT
	this->_Inst_RequestedAuthnContext = NULL;
#endif /* SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT */
}

TElSAMLAuthnQueryElement::TElSAMLAuthnQueryElement(TElSAMLAuthnQueryElementHandle handle, TElOwnHandle ownHandle) : TElSAMLSubjectQueryAbstractType(handle, ownHandle)
{
	initInstances();
}

TElSAMLAuthnQueryElement::TElSAMLAuthnQueryElement() : TElSAMLSubjectQueryAbstractType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLAuthnQueryElement_Create(&_Handle));
}

TElSAMLAuthnQueryElement::~TElSAMLAuthnQueryElement()
{
#ifdef SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT
	delete this->_Inst_RequestedAuthnContext;
	this->_Inst_RequestedAuthnContext = NULL;
#endif /* SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT */
}
#endif /* SB_USE_CLASS_TELSAMLAUTHNQUERYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEQUERYELEMENT

SB_INLINE void TElSAMLAttributeQueryElement::Clear()
{
	SBCheckError(TElSAMLAttributeQueryElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLAttributeQueryElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLAttributeQueryElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLAttributeQueryElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLAttributeQueryElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLAttributeQueryElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAttributeQueryElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLAttributeQueryElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAttributeQueryElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int32_t TElSAMLAttributeQueryElement::AddAttribute()
{
	int32_t OutResult;
	SBCheckError(TElSAMLAttributeQueryElement_AddAttribute(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLAttributeQueryElement::RemoveAttribute(int32_t Index)
{
	SBCheckError(TElSAMLAttributeQueryElement_RemoveAttribute(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT
TElSAMLAttributeElement* TElSAMLAttributeQueryElement::get_Attributes(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAttributeQueryElement_get_Attributes(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Attributes)
		this->_Inst_Attributes = new TElSAMLAttributeElement(hOutResult, ohFalse);
	else
		this->_Inst_Attributes->updateHandle(hOutResult);
	return this->_Inst_Attributes;
}
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT */

SB_INLINE int32_t TElSAMLAttributeQueryElement::get_AttributeCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLAttributeQueryElement_get_AttributeCount(_Handle, &OutResult));
	return OutResult;
}

void TElSAMLAttributeQueryElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT */
}

TElSAMLAttributeQueryElement::TElSAMLAttributeQueryElement(TElSAMLAttributeQueryElementHandle handle, TElOwnHandle ownHandle) : TElSAMLSubjectQueryAbstractType(handle, ownHandle)
{
	initInstances();
}

TElSAMLAttributeQueryElement::TElSAMLAttributeQueryElement() : TElSAMLSubjectQueryAbstractType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLAttributeQueryElement_Create(&_Handle));
}

TElSAMLAttributeQueryElement::~TElSAMLAttributeQueryElement()
{
#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT
	delete this->_Inst_Attributes;
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT */
}
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEQUERYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUTHZDECISIONQUERYELEMENT

SB_INLINE void TElSAMLAuthzDecisionQueryElement::Clear()
{
	SBCheckError(TElSAMLAuthzDecisionQueryElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLAuthzDecisionQueryElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLAuthzDecisionQueryElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLAuthzDecisionQueryElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLAuthzDecisionQueryElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLAuthzDecisionQueryElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAuthzDecisionQueryElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLAuthzDecisionQueryElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAuthzDecisionQueryElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int32_t TElSAMLAuthzDecisionQueryElement::AddAction()
{
	int32_t OutResult;
	SBCheckError(TElSAMLAuthzDecisionQueryElement_AddAction(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLAuthzDecisionQueryElement::RemoveAction(int32_t Index)
{
	SBCheckError(TElSAMLAuthzDecisionQueryElement_RemoveAction(_Handle, Index));
}

void TElSAMLAuthzDecisionQueryElement::get_Resource(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAuthzDecisionQueryElement_get_Resource(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1720227700, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLAuthzDecisionQueryElement::set_Resource(const std::string &Value)
{
	SBCheckError(TElSAMLAuthzDecisionQueryElement_set_Resource(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELSAMLEVIDENCEELEMENT
TElSAMLEvidenceElement* TElSAMLAuthzDecisionQueryElement::get_Evidence()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAuthzDecisionQueryElement_get_Evidence(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Evidence)
		this->_Inst_Evidence = new TElSAMLEvidenceElement(hOutResult, ohFalse);
	else
		this->_Inst_Evidence->updateHandle(hOutResult);
	return this->_Inst_Evidence;
}

SB_INLINE void TElSAMLAuthzDecisionQueryElement::set_Evidence(TElSAMLEvidenceElement &Value)
{
	SBCheckError(TElSAMLAuthzDecisionQueryElement_set_Evidence(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLAuthzDecisionQueryElement::set_Evidence(TElSAMLEvidenceElement *Value)
{
	SBCheckError(TElSAMLAuthzDecisionQueryElement_set_Evidence(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLEVIDENCEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLACTIONELEMENT
TElSAMLActionElement* TElSAMLAuthzDecisionQueryElement::get_Actions(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAuthzDecisionQueryElement_get_Actions(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Actions)
		this->_Inst_Actions = new TElSAMLActionElement(hOutResult, ohFalse);
	else
		this->_Inst_Actions->updateHandle(hOutResult);
	return this->_Inst_Actions;
}
#endif /* SB_USE_CLASS_TELSAMLACTIONELEMENT */

SB_INLINE int32_t TElSAMLAuthzDecisionQueryElement::get_ActionCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLAuthzDecisionQueryElement_get_ActionCount(_Handle, &OutResult));
	return OutResult;
}

void TElSAMLAuthzDecisionQueryElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLEVIDENCEELEMENT
	this->_Inst_Evidence = NULL;
#endif /* SB_USE_CLASS_TELSAMLEVIDENCEELEMENT */
#ifdef SB_USE_CLASS_TELSAMLACTIONELEMENT
	this->_Inst_Actions = NULL;
#endif /* SB_USE_CLASS_TELSAMLACTIONELEMENT */
}

TElSAMLAuthzDecisionQueryElement::TElSAMLAuthzDecisionQueryElement(TElSAMLAuthzDecisionQueryElementHandle handle, TElOwnHandle ownHandle) : TElSAMLSubjectQueryAbstractType(handle, ownHandle)
{
	initInstances();
}

TElSAMLAuthzDecisionQueryElement::TElSAMLAuthzDecisionQueryElement() : TElSAMLSubjectQueryAbstractType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLAuthzDecisionQueryElement_Create(&_Handle));
}

TElSAMLAuthzDecisionQueryElement::~TElSAMLAuthzDecisionQueryElement()
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
#endif /* SB_USE_CLASS_TELSAMLAUTHZDECISIONQUERYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLRESPONSEELEMENT

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE TElSAMLStatusResponseTypeHandle TElSAMLResponseElement::GetInstance(TElXMLDOMDocument &Doc)
{
	TElSAMLStatusResponseTypeHandle OutResult;
	SBCheckError(TElSAMLResponseElement_GetInstance(Doc.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElSAMLStatusResponseTypeHandle TElSAMLResponseElement::GetInstance(TElXMLDOMDocument *Doc)
{
	TElSAMLStatusResponseTypeHandle OutResult;
	SBCheckError(TElSAMLResponseElement_GetInstance((Doc != NULL) ? Doc->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE TElSAMLStatusResponseTypeHandle TElSAMLResponseElement::GetInstance_Inst(TElXMLDOMDocument &Doc)
{
	TElSAMLStatusResponseTypeHandle OutResult;
	SBCheckError(TElSAMLResponseElement_GetInstance_1(_Handle, Doc.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElSAMLStatusResponseTypeHandle TElSAMLResponseElement::GetInstance_Inst(TElXMLDOMDocument *Doc)
{
	TElSAMLStatusResponseTypeHandle OutResult;
	SBCheckError(TElSAMLResponseElement_GetInstance_1(_Handle, (Doc != NULL) ? Doc->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

SB_INLINE void TElSAMLResponseElement::Clear()
{
	SBCheckError(TElSAMLResponseElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLResponseElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLResponseElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLResponseElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLResponseElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLResponseElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLResponseElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLResponseElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLResponseElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONTYPE
SB_INLINE int32_t TElSAMLResponseElement::AddAssertion(TElSAMLAssertionType &Assertion)
{
	int32_t OutResult;
	SBCheckError(TElSAMLResponseElement_AddAssertion(_Handle, Assertion.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLResponseElement::AddAssertion(TElSAMLAssertionType *Assertion)
{
	int32_t OutResult;
	SBCheckError(TElSAMLResponseElement_AddAssertion(_Handle, (Assertion != NULL) ? Assertion->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLASSERTIONTYPE */

SB_INLINE void TElSAMLResponseElement::RemoveAssertion(int32_t Index)
{
	SBCheckError(TElSAMLResponseElement_RemoveAssertion(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELSAMLASSERTIONTYPE
TElSAMLAssertionType* TElSAMLResponseElement::get_Assertions(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLResponseElement_get_Assertions(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Assertions)
		this->_Inst_Assertions = new TElSAMLAssertionType(hOutResult, ohFalse);
	else
		this->_Inst_Assertions->updateHandle(hOutResult);
	return this->_Inst_Assertions;
}
#endif /* SB_USE_CLASS_TELSAMLASSERTIONTYPE */

SB_INLINE int32_t TElSAMLResponseElement::get_AssertionCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLResponseElement_get_AssertionCount(_Handle, &OutResult));
	return OutResult;
}

void TElSAMLResponseElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLASSERTIONTYPE
	this->_Inst_Assertions = NULL;
#endif /* SB_USE_CLASS_TELSAMLASSERTIONTYPE */
}

TElSAMLResponseElement::TElSAMLResponseElement(TElSAMLResponseElementHandle handle, TElOwnHandle ownHandle) : TElSAMLStatusResponseType(handle, ownHandle)
{
	initInstances();
}

TElSAMLResponseElement::TElSAMLResponseElement() : TElSAMLStatusResponseType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLResponseElement_Create(&_Handle));
}

TElSAMLResponseElement::~TElSAMLResponseElement()
{
#ifdef SB_USE_CLASS_TELSAMLASSERTIONTYPE
	delete this->_Inst_Assertions;
	this->_Inst_Assertions = NULL;
#endif /* SB_USE_CLASS_TELSAMLASSERTIONTYPE */
}
#endif /* SB_USE_CLASS_TELSAMLRESPONSEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT

SB_INLINE void TElSAMLNameIDPolicyElement::Clear()
{
	SBCheckError(TElSAMLNameIDPolicyElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLNameIDPolicyElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLNameIDPolicyElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLNameIDPolicyElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLNameIDPolicyElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLNameIDPolicyElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLNameIDPolicyElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLNameIDPolicyElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLNameIDPolicyElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElSAMLNameIDPolicyElement::get_Format(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLNameIDPolicyElement_get_Format(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-842602523, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLNameIDPolicyElement::set_Format(const std::string &Value)
{
	SBCheckError(TElSAMLNameIDPolicyElement_set_Format(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLNameIDPolicyElement::get_SPNameQualifier(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLNameIDPolicyElement_get_SPNameQualifier(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1819181110, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLNameIDPolicyElement::set_SPNameQualifier(const std::string &Value)
{
	SBCheckError(TElSAMLNameIDPolicyElement_set_SPNameQualifier(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSAMLNameIDPolicyElement::get_AllowCreate()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLNameIDPolicyElement_get_AllowCreate(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLNameIDPolicyElement::set_AllowCreate(bool Value)
{
	SBCheckError(TElSAMLNameIDPolicyElement_set_AllowCreate(_Handle, (int8_t)Value));
}

bool TElSAMLNameIDPolicyElement::get_UseAllowCreate()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLNameIDPolicyElement_get_UseAllowCreate(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLNameIDPolicyElement::set_UseAllowCreate(bool Value)
{
	SBCheckError(TElSAMLNameIDPolicyElement_set_UseAllowCreate(_Handle, (int8_t)Value));
}

TElSAMLNameIDPolicyElement::TElSAMLNameIDPolicyElement(TElSAMLNameIDPolicyElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
}

TElSAMLNameIDPolicyElement::TElSAMLNameIDPolicyElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLNameIDPolicyElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLIDPENTRYELEMENT

SB_INLINE void TElSAMLIDPEntryElement::Clear()
{
	SBCheckError(TElSAMLIDPEntryElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLIDPEntryElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLIDPEntryElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLIDPEntryElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLIDPEntryElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLIDPEntryElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLIDPEntryElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLIDPEntryElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLIDPEntryElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElSAMLIDPEntryElement::get_ProviderID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIDPEntryElement_get_ProviderID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1697275696, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIDPEntryElement::set_ProviderID(const std::string &Value)
{
	SBCheckError(TElSAMLIDPEntryElement_set_ProviderID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLIDPEntryElement::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIDPEntryElement_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1515102525, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIDPEntryElement::set_Name(const std::string &Value)
{
	SBCheckError(TElSAMLIDPEntryElement_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLIDPEntryElement::get_Loc(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIDPEntryElement_get_Loc(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1051427675, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIDPEntryElement::set_Loc(const std::string &Value)
{
	SBCheckError(TElSAMLIDPEntryElement_set_Loc(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSAMLIDPEntryElement::TElSAMLIDPEntryElement(TElSAMLIDPEntryElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
}

TElSAMLIDPEntryElement::TElSAMLIDPEntryElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLIDPEntryElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLIDPENTRYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLIDPLISTELEMENT

SB_INLINE void TElSAMLIDPListElement::Clear()
{
	SBCheckError(TElSAMLIDPListElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLIDPListElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLIDPListElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLIDPListElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLIDPListElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLIDPListElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLIDPListElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLIDPListElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLIDPListElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int32_t TElSAMLIDPListElement::AddIDPEntry()
{
	int32_t OutResult;
	SBCheckError(TElSAMLIDPListElement_AddIDPEntry(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLIDPListElement::RemoveIDPEntry(int32_t Index)
{
	SBCheckError(TElSAMLIDPListElement_RemoveIDPEntry(_Handle, Index));
}

void TElSAMLIDPListElement::get_GetComplete(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIDPListElement_get_GetComplete(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-615529253, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIDPListElement::set_GetComplete(const std::string &Value)
{
	SBCheckError(TElSAMLIDPListElement_set_GetComplete(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELSAMLIDPENTRYELEMENT
TElSAMLIDPEntryElement* TElSAMLIDPListElement::get_IDPEntries(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIDPListElement_get_IDPEntries(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IDPEntries)
		this->_Inst_IDPEntries = new TElSAMLIDPEntryElement(hOutResult, ohFalse);
	else
		this->_Inst_IDPEntries->updateHandle(hOutResult);
	return this->_Inst_IDPEntries;
}
#endif /* SB_USE_CLASS_TELSAMLIDPENTRYELEMENT */

SB_INLINE int32_t TElSAMLIDPListElement::get_IDPEntryCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLIDPListElement_get_IDPEntryCount(_Handle, &OutResult));
	return OutResult;
}

void TElSAMLIDPListElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLIDPENTRYELEMENT
	this->_Inst_IDPEntries = NULL;
#endif /* SB_USE_CLASS_TELSAMLIDPENTRYELEMENT */
}

TElSAMLIDPListElement::TElSAMLIDPListElement(TElSAMLIDPListElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLIDPListElement::TElSAMLIDPListElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLIDPListElement_Create(&_Handle));
}

TElSAMLIDPListElement::~TElSAMLIDPListElement()
{
#ifdef SB_USE_CLASS_TELSAMLIDPENTRYELEMENT
	delete this->_Inst_IDPEntries;
	this->_Inst_IDPEntries = NULL;
#endif /* SB_USE_CLASS_TELSAMLIDPENTRYELEMENT */
}
#endif /* SB_USE_CLASS_TELSAMLIDPLISTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSCOPINGELEMENT

SB_INLINE void TElSAMLScopingElement::Clear()
{
	SBCheckError(TElSAMLScopingElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLScopingElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLScopingElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLScopingElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLScopingElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLScopingElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLScopingElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLScopingElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLScopingElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int32_t TElSAMLScopingElement::get_ProxyCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLScopingElement_get_ProxyCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLScopingElement::set_ProxyCount(int32_t Value)
{
	SBCheckError(TElSAMLScopingElement_set_ProxyCount(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELSAMLIDPLISTELEMENT
TElSAMLIDPListElement* TElSAMLScopingElement::get_IDPList()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLScopingElement_get_IDPList(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IDPList)
		this->_Inst_IDPList = new TElSAMLIDPListElement(hOutResult, ohFalse);
	else
		this->_Inst_IDPList->updateHandle(hOutResult);
	return this->_Inst_IDPList;
}

SB_INLINE void TElSAMLScopingElement::set_IDPList(TElSAMLIDPListElement &Value)
{
	SBCheckError(TElSAMLScopingElement_set_IDPList(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLScopingElement::set_IDPList(TElSAMLIDPListElement *Value)
{
	SBCheckError(TElSAMLScopingElement_set_IDPList(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLIDPLISTELEMENT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSAMLScopingElement::get_RequesterIDs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLScopingElement_get_RequesterIDs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RequesterIDs)
		this->_Inst_RequesterIDs = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_RequesterIDs->updateHandle(hOutResult);
	return this->_Inst_RequesterIDs;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSAMLScopingElement::get_RequesterIDs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLScopingElement_get_RequesterIDs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RequesterIDs)
		this->_Inst_RequesterIDs = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_RequesterIDs->updateHandle(hOutResult);
	return this->_Inst_RequesterIDs;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElSAMLScopingElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLIDPLISTELEMENT
	this->_Inst_IDPList = NULL;
#endif /* SB_USE_CLASS_TELSAMLIDPLISTELEMENT */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_RequesterIDs = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_RequesterIDs = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElSAMLScopingElement::TElSAMLScopingElement(TElSAMLScopingElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLScopingElement::TElSAMLScopingElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLScopingElement_Create(&_Handle));
}

TElSAMLScopingElement::~TElSAMLScopingElement()
{
#ifdef SB_USE_CLASS_TELSAMLIDPLISTELEMENT
	delete this->_Inst_IDPList;
	this->_Inst_IDPList = NULL;
#endif /* SB_USE_CLASS_TELSAMLIDPLISTELEMENT */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_RequesterIDs;
	this->_Inst_RequesterIDs = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_RequesterIDs;
	this->_Inst_RequesterIDs = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELSAMLSCOPINGELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUTHNREQUESTELEMENT

SB_INLINE void TElSAMLAuthnRequestElement::Clear()
{
	SBCheckError(TElSAMLAuthnRequestElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLAuthnRequestElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLAuthnRequestElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLAuthnRequestElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLAuthnRequestElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLAuthnRequestElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAuthnRequestElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLAuthnRequestElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAuthnRequestElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

bool TElSAMLAuthnRequestElement::get_ForceAuthn()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLAuthnRequestElement_get_ForceAuthn(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLAuthnRequestElement::set_ForceAuthn(bool Value)
{
	SBCheckError(TElSAMLAuthnRequestElement_set_ForceAuthn(_Handle, (int8_t)Value));
}

bool TElSAMLAuthnRequestElement::get_IsPassive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLAuthnRequestElement_get_IsPassive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLAuthnRequestElement::set_IsPassive(bool Value)
{
	SBCheckError(TElSAMLAuthnRequestElement_set_IsPassive(_Handle, (int8_t)Value));
}

bool TElSAMLAuthnRequestElement::get_UseForceAuthn()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLAuthnRequestElement_get_UseForceAuthn(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLAuthnRequestElement::set_UseForceAuthn(bool Value)
{
	SBCheckError(TElSAMLAuthnRequestElement_set_UseForceAuthn(_Handle, (int8_t)Value));
}

bool TElSAMLAuthnRequestElement::get_UseIsPassive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLAuthnRequestElement_get_UseIsPassive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLAuthnRequestElement::set_UseIsPassive(bool Value)
{
	SBCheckError(TElSAMLAuthnRequestElement_set_UseIsPassive(_Handle, (int8_t)Value));
}

void TElSAMLAuthnRequestElement::get_ProtocolBinding(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAuthnRequestElement_get_ProtocolBinding(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1042075862, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLAuthnRequestElement::set_ProtocolBinding(const std::string &Value)
{
	SBCheckError(TElSAMLAuthnRequestElement_set_ProtocolBinding(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSAMLAuthnRequestElement::get_AssertionConsumerServiceIndex()
{
	int32_t OutResult;
	SBCheckError(TElSAMLAuthnRequestElement_get_AssertionConsumerServiceIndex(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLAuthnRequestElement::set_AssertionConsumerServiceIndex(int32_t Value)
{
	SBCheckError(TElSAMLAuthnRequestElement_set_AssertionConsumerServiceIndex(_Handle, Value));
}

void TElSAMLAuthnRequestElement::get_AssertionConsumerServiceURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAuthnRequestElement_get_AssertionConsumerServiceURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1529302967, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLAuthnRequestElement::set_AssertionConsumerServiceURL(const std::string &Value)
{
	SBCheckError(TElSAMLAuthnRequestElement_set_AssertionConsumerServiceURL(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSAMLAuthnRequestElement::get_AttributeConsumingServiceIndex()
{
	int32_t OutResult;
	SBCheckError(TElSAMLAuthnRequestElement_get_AttributeConsumingServiceIndex(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLAuthnRequestElement::set_AttributeConsumingServiceIndex(int32_t Value)
{
	SBCheckError(TElSAMLAuthnRequestElement_set_AttributeConsumingServiceIndex(_Handle, Value));
}

void TElSAMLAuthnRequestElement::get_ProviderName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAuthnRequestElement_get_ProviderName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1957466537, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLAuthnRequestElement::set_ProviderName(const std::string &Value)
{
	SBCheckError(TElSAMLAuthnRequestElement_set_ProviderName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELSAMLSUBJECTELEMENT
TElSAMLSubjectElement* TElSAMLAuthnRequestElement::get_Subject()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAuthnRequestElement_get_Subject(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Subject)
		this->_Inst_Subject = new TElSAMLSubjectElement(hOutResult, ohFalse);
	else
		this->_Inst_Subject->updateHandle(hOutResult);
	return this->_Inst_Subject;
}

SB_INLINE void TElSAMLAuthnRequestElement::set_Subject(TElSAMLSubjectElement &Value)
{
	SBCheckError(TElSAMLAuthnRequestElement_set_Subject(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLAuthnRequestElement::set_Subject(TElSAMLSubjectElement *Value)
{
	SBCheckError(TElSAMLAuthnRequestElement_set_Subject(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLSUBJECTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT
TElSAMLNameIDPolicyElement* TElSAMLAuthnRequestElement::get_NameIDPolicy()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAuthnRequestElement_get_NameIDPolicy(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NameIDPolicy)
		this->_Inst_NameIDPolicy = new TElSAMLNameIDPolicyElement(hOutResult, ohFalse);
	else
		this->_Inst_NameIDPolicy->updateHandle(hOutResult);
	return this->_Inst_NameIDPolicy;
}

SB_INLINE void TElSAMLAuthnRequestElement::set_NameIDPolicy(TElSAMLNameIDPolicyElement &Value)
{
	SBCheckError(TElSAMLAuthnRequestElement_set_NameIDPolicy(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLAuthnRequestElement::set_NameIDPolicy(TElSAMLNameIDPolicyElement *Value)
{
	SBCheckError(TElSAMLAuthnRequestElement_set_NameIDPolicy(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLCONDITIONSELEMENT
TElSAMLConditionsElement* TElSAMLAuthnRequestElement::get_Conditions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAuthnRequestElement_get_Conditions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Conditions)
		this->_Inst_Conditions = new TElSAMLConditionsElement(hOutResult, ohFalse);
	else
		this->_Inst_Conditions->updateHandle(hOutResult);
	return this->_Inst_Conditions;
}

SB_INLINE void TElSAMLAuthnRequestElement::set_Conditions(TElSAMLConditionsElement &Value)
{
	SBCheckError(TElSAMLAuthnRequestElement_set_Conditions(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLAuthnRequestElement::set_Conditions(TElSAMLConditionsElement *Value)
{
	SBCheckError(TElSAMLAuthnRequestElement_set_Conditions(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLCONDITIONSELEMENT */

#ifdef SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT
TElSAMLRequestedAuthnContextElement* TElSAMLAuthnRequestElement::get_RequestedAuthnContext()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAuthnRequestElement_get_RequestedAuthnContext(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RequestedAuthnContext)
		this->_Inst_RequestedAuthnContext = new TElSAMLRequestedAuthnContextElement(hOutResult, ohFalse);
	else
		this->_Inst_RequestedAuthnContext->updateHandle(hOutResult);
	return this->_Inst_RequestedAuthnContext;
}

SB_INLINE void TElSAMLAuthnRequestElement::set_RequestedAuthnContext(TElSAMLRequestedAuthnContextElement &Value)
{
	SBCheckError(TElSAMLAuthnRequestElement_set_RequestedAuthnContext(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLAuthnRequestElement::set_RequestedAuthnContext(TElSAMLRequestedAuthnContextElement *Value)
{
	SBCheckError(TElSAMLAuthnRequestElement_set_RequestedAuthnContext(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSCOPINGELEMENT
TElSAMLScopingElement* TElSAMLAuthnRequestElement::get_Scoping()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAuthnRequestElement_get_Scoping(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Scoping)
		this->_Inst_Scoping = new TElSAMLScopingElement(hOutResult, ohFalse);
	else
		this->_Inst_Scoping->updateHandle(hOutResult);
	return this->_Inst_Scoping;
}

SB_INLINE void TElSAMLAuthnRequestElement::set_Scoping(TElSAMLScopingElement &Value)
{
	SBCheckError(TElSAMLAuthnRequestElement_set_Scoping(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLAuthnRequestElement::set_Scoping(TElSAMLScopingElement *Value)
{
	SBCheckError(TElSAMLAuthnRequestElement_set_Scoping(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLSCOPINGELEMENT */

void TElSAMLAuthnRequestElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLSUBJECTELEMENT
	this->_Inst_Subject = NULL;
#endif /* SB_USE_CLASS_TELSAMLSUBJECTELEMENT */
#ifdef SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT
	this->_Inst_NameIDPolicy = NULL;
#endif /* SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT */
#ifdef SB_USE_CLASS_TELSAMLCONDITIONSELEMENT
	this->_Inst_Conditions = NULL;
#endif /* SB_USE_CLASS_TELSAMLCONDITIONSELEMENT */
#ifdef SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT
	this->_Inst_RequestedAuthnContext = NULL;
#endif /* SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT */
#ifdef SB_USE_CLASS_TELSAMLSCOPINGELEMENT
	this->_Inst_Scoping = NULL;
#endif /* SB_USE_CLASS_TELSAMLSCOPINGELEMENT */
}

TElSAMLAuthnRequestElement::TElSAMLAuthnRequestElement(TElSAMLAuthnRequestElementHandle handle, TElOwnHandle ownHandle) : TElSAMLRequestAbstractType(handle, ownHandle)
{
	initInstances();
}

TElSAMLAuthnRequestElement::TElSAMLAuthnRequestElement() : TElSAMLRequestAbstractType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLAuthnRequestElement_Create(&_Handle));
}

TElSAMLAuthnRequestElement::~TElSAMLAuthnRequestElement()
{
#ifdef SB_USE_CLASS_TELSAMLSUBJECTELEMENT
	delete this->_Inst_Subject;
	this->_Inst_Subject = NULL;
#endif /* SB_USE_CLASS_TELSAMLSUBJECTELEMENT */
#ifdef SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT
	delete this->_Inst_NameIDPolicy;
	this->_Inst_NameIDPolicy = NULL;
#endif /* SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT */
#ifdef SB_USE_CLASS_TELSAMLCONDITIONSELEMENT
	delete this->_Inst_Conditions;
	this->_Inst_Conditions = NULL;
#endif /* SB_USE_CLASS_TELSAMLCONDITIONSELEMENT */
#ifdef SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT
	delete this->_Inst_RequestedAuthnContext;
	this->_Inst_RequestedAuthnContext = NULL;
#endif /* SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT */
#ifdef SB_USE_CLASS_TELSAMLSCOPINGELEMENT
	delete this->_Inst_Scoping;
	this->_Inst_Scoping = NULL;
#endif /* SB_USE_CLASS_TELSAMLSCOPINGELEMENT */
}
#endif /* SB_USE_CLASS_TELSAMLAUTHNREQUESTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLARTIFACTRESOLVEELEMENT

SB_INLINE void TElSAMLArtifactResolveElement::Clear()
{
	SBCheckError(TElSAMLArtifactResolveElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLArtifactResolveElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLArtifactResolveElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLArtifactResolveElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLArtifactResolveElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLArtifactResolveElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLArtifactResolveElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLArtifactResolveElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLArtifactResolveElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElSAMLArtifactResolveElement::get_Artifact(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLArtifactResolveElement_get_Artifact(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(230250814, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLArtifactResolveElement::set_Artifact(const std::string &Value)
{
	SBCheckError(TElSAMLArtifactResolveElement_set_Artifact(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSAMLArtifactResolveElement::TElSAMLArtifactResolveElement(TElSAMLArtifactResolveElementHandle handle, TElOwnHandle ownHandle) : TElSAMLRequestAbstractType(handle, ownHandle)
{
}

TElSAMLArtifactResolveElement::TElSAMLArtifactResolveElement() : TElSAMLRequestAbstractType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLArtifactResolveElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLARTIFACTRESOLVEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLARTIFACTRESPONSEELEMENT

SB_INLINE void TElSAMLArtifactResponseElement::Clear()
{
	SBCheckError(TElSAMLArtifactResponseElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLArtifactResponseElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLArtifactResponseElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLArtifactResponseElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLArtifactResponseElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLArtifactResponseElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLArtifactResponseElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLArtifactResponseElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLArtifactResponseElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLDOMElement* TElSAMLArtifactResponseElement::get_Optional()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLArtifactResponseElement_get_Optional(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Optional)
		this->_Inst_Optional = new TElXMLDOMElement(hOutResult, ohFalse);
	else
		this->_Inst_Optional->updateHandle(hOutResult);
	return this->_Inst_Optional;
}

SB_INLINE void TElSAMLArtifactResponseElement::set_Optional(TElXMLDOMElement &Value)
{
	SBCheckError(TElSAMLArtifactResponseElement_set_Optional(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLArtifactResponseElement::set_Optional(TElXMLDOMElement *Value)
{
	SBCheckError(TElSAMLArtifactResponseElement_set_Optional(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

void TElSAMLArtifactResponseElement::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	this->_Inst_Optional = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
}

TElSAMLArtifactResponseElement::TElSAMLArtifactResponseElement(TElSAMLArtifactResponseElementHandle handle, TElOwnHandle ownHandle) : TElSAMLStatusResponseType(handle, ownHandle)
{
	initInstances();
}

TElSAMLArtifactResponseElement::TElSAMLArtifactResponseElement() : TElSAMLStatusResponseType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLArtifactResponseElement_Create(&_Handle));
}

TElSAMLArtifactResponseElement::~TElSAMLArtifactResponseElement()
{
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	delete this->_Inst_Optional;
	this->_Inst_Optional = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
}
#endif /* SB_USE_CLASS_TELSAMLARTIFACTRESPONSEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLMANAGENAMEIDREQUESTELEMENT

SB_INLINE void TElSAMLManageNameIDRequestElement::Clear()
{
	SBCheckError(TElSAMLManageNameIDRequestElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLManageNameIDRequestElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLManageNameIDRequestElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLManageNameIDRequestElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLManageNameIDRequestElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLManageNameIDRequestElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLManageNameIDRequestElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLManageNameIDRequestElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLManageNameIDRequestElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELSAMLID
TElSAMLID* TElSAMLManageNameIDRequestElement::get_NameID()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLManageNameIDRequestElement_get_NameID(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NameID)
		this->_Inst_NameID = new TElSAMLID(hOutResult, ohFalse);
	else
		this->_Inst_NameID->updateHandle(hOutResult);
	return this->_Inst_NameID;
}

SB_INLINE void TElSAMLManageNameIDRequestElement::set_NameID(TElSAMLID &Value)
{
	SBCheckError(TElSAMLManageNameIDRequestElement_set_NameID(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLManageNameIDRequestElement::set_NameID(TElSAMLID *Value)
{
	SBCheckError(TElSAMLManageNameIDRequestElement_set_NameID(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLID */

void TElSAMLManageNameIDRequestElement::get_NewID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLManageNameIDRequestElement_get_NewID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1639243716, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLManageNameIDRequestElement::set_NewID(const std::string &Value)
{
	SBCheckError(TElSAMLManageNameIDRequestElement_set_NewID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT
TElSAMLEncryptedElement* TElSAMLManageNameIDRequestElement::get_NewEncryptedID()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLManageNameIDRequestElement_get_NewEncryptedID(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NewEncryptedID)
		this->_Inst_NewEncryptedID = new TElSAMLEncryptedElement(hOutResult, ohFalse);
	else
		this->_Inst_NewEncryptedID->updateHandle(hOutResult);
	return this->_Inst_NewEncryptedID;
}

SB_INLINE void TElSAMLManageNameIDRequestElement::set_NewEncryptedID(TElSAMLEncryptedElement &Value)
{
	SBCheckError(TElSAMLManageNameIDRequestElement_set_NewEncryptedID(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLManageNameIDRequestElement::set_NewEncryptedID(TElSAMLEncryptedElement *Value)
{
	SBCheckError(TElSAMLManageNameIDRequestElement_set_NewEncryptedID(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT */

TElSAMLElement* TElSAMLManageNameIDRequestElement::get_Terminate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLManageNameIDRequestElement_get_Terminate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Terminate)
		this->_Inst_Terminate = new TElSAMLElement(hOutResult, ohFalse);
	else
		this->_Inst_Terminate->updateHandle(hOutResult);
	return this->_Inst_Terminate;
}

SB_INLINE void TElSAMLManageNameIDRequestElement::set_Terminate(TElSAMLElement &Value)
{
	SBCheckError(TElSAMLManageNameIDRequestElement_set_Terminate(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLManageNameIDRequestElement::set_Terminate(TElSAMLElement *Value)
{
	SBCheckError(TElSAMLManageNameIDRequestElement_set_Terminate(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

void TElSAMLManageNameIDRequestElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLID
	this->_Inst_NameID = NULL;
#endif /* SB_USE_CLASS_TELSAMLID */
#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT
	this->_Inst_NewEncryptedID = NULL;
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT */
	this->_Inst_Terminate = NULL;
}

TElSAMLManageNameIDRequestElement::TElSAMLManageNameIDRequestElement(TElSAMLManageNameIDRequestElementHandle handle, TElOwnHandle ownHandle) : TElSAMLRequestAbstractType(handle, ownHandle)
{
	initInstances();
}

TElSAMLManageNameIDRequestElement::TElSAMLManageNameIDRequestElement() : TElSAMLRequestAbstractType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLManageNameIDRequestElement_Create(&_Handle));
}

TElSAMLManageNameIDRequestElement::~TElSAMLManageNameIDRequestElement()
{
#ifdef SB_USE_CLASS_TELSAMLID
	delete this->_Inst_NameID;
	this->_Inst_NameID = NULL;
#endif /* SB_USE_CLASS_TELSAMLID */
#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT
	delete this->_Inst_NewEncryptedID;
	this->_Inst_NewEncryptedID = NULL;
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT */
	delete this->_Inst_Terminate;
	this->_Inst_Terminate = NULL;
}
#endif /* SB_USE_CLASS_TELSAMLMANAGENAMEIDREQUESTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLMANAGENAMEIDRESPONSEELEMENT

TElSAMLManageNameIDResponseElement::TElSAMLManageNameIDResponseElement(TElSAMLManageNameIDResponseElementHandle handle, TElOwnHandle ownHandle) : TElSAMLStatusResponseType(handle, ownHandle)
{
}

TElSAMLManageNameIDResponseElement::TElSAMLManageNameIDResponseElement() : TElSAMLStatusResponseType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLManageNameIDResponseElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLMANAGENAMEIDRESPONSEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLLOGOUTREQUESTELEMENT

SB_INLINE void TElSAMLLogoutRequestElement::Clear()
{
	SBCheckError(TElSAMLLogoutRequestElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLLogoutRequestElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLLogoutRequestElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLLogoutRequestElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLLogoutRequestElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLLogoutRequestElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLLogoutRequestElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLLogoutRequestElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLLogoutRequestElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELSAMLID
TElSAMLID* TElSAMLLogoutRequestElement::get_NameID()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLLogoutRequestElement_get_NameID(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NameID)
		this->_Inst_NameID = new TElSAMLID(hOutResult, ohFalse);
	else
		this->_Inst_NameID->updateHandle(hOutResult);
	return this->_Inst_NameID;
}

SB_INLINE void TElSAMLLogoutRequestElement::set_NameID(TElSAMLID &Value)
{
	SBCheckError(TElSAMLLogoutRequestElement_set_NameID(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLLogoutRequestElement::set_NameID(TElSAMLID *Value)
{
	SBCheckError(TElSAMLLogoutRequestElement_set_NameID(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLID */

void TElSAMLLogoutRequestElement::get_Reason(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLLogoutRequestElement_get_Reason(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1728937010, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLLogoutRequestElement::set_Reason(const std::string &Value)
{
	SBCheckError(TElSAMLLogoutRequestElement_set_Reason(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElSAMLLogoutRequestElement::get_NotOnOrAfter()
{
	int64_t OutResult;
	SBCheckError(TElSAMLLogoutRequestElement_get_NotOnOrAfter(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLLogoutRequestElement::set_NotOnOrAfter(int64_t Value)
{
	SBCheckError(TElSAMLLogoutRequestElement_set_NotOnOrAfter(_Handle, Value));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSAMLLogoutRequestElement::get_SessionIndexes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLLogoutRequestElement_get_SessionIndexes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SessionIndexes)
		this->_Inst_SessionIndexes = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_SessionIndexes->updateHandle(hOutResult);
	return this->_Inst_SessionIndexes;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSAMLLogoutRequestElement::get_SessionIndexes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLLogoutRequestElement_get_SessionIndexes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SessionIndexes)
		this->_Inst_SessionIndexes = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_SessionIndexes->updateHandle(hOutResult);
	return this->_Inst_SessionIndexes;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElSAMLLogoutRequestElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLID
	this->_Inst_NameID = NULL;
#endif /* SB_USE_CLASS_TELSAMLID */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_SessionIndexes = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_SessionIndexes = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElSAMLLogoutRequestElement::TElSAMLLogoutRequestElement(TElSAMLLogoutRequestElementHandle handle, TElOwnHandle ownHandle) : TElSAMLRequestAbstractType(handle, ownHandle)
{
	initInstances();
}

TElSAMLLogoutRequestElement::TElSAMLLogoutRequestElement() : TElSAMLRequestAbstractType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLLogoutRequestElement_Create(&_Handle));
}

TElSAMLLogoutRequestElement::~TElSAMLLogoutRequestElement()
{
#ifdef SB_USE_CLASS_TELSAMLID
	delete this->_Inst_NameID;
	this->_Inst_NameID = NULL;
#endif /* SB_USE_CLASS_TELSAMLID */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_SessionIndexes;
	this->_Inst_SessionIndexes = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_SessionIndexes;
	this->_Inst_SessionIndexes = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELSAMLLOGOUTREQUESTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLLOGOUTRESPONSEELEMENT

TElSAMLLogoutResponseElement::TElSAMLLogoutResponseElement(TElSAMLLogoutResponseElementHandle handle, TElOwnHandle ownHandle) : TElSAMLStatusResponseType(handle, ownHandle)
{
}

TElSAMLLogoutResponseElement::TElSAMLLogoutResponseElement() : TElSAMLStatusResponseType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLLogoutResponseElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLLOGOUTRESPONSEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLNAMEIDMAPPINGREQUESTELEMENT

SB_INLINE void TElSAMLNameIDMappingRequestElement::Clear()
{
	SBCheckError(TElSAMLNameIDMappingRequestElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLNameIDMappingRequestElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLNameIDMappingRequestElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLNameIDMappingRequestElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLNameIDMappingRequestElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLNameIDMappingRequestElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLNameIDMappingRequestElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLNameIDMappingRequestElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLNameIDMappingRequestElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELSAMLID
TElSAMLID* TElSAMLNameIDMappingRequestElement::get_NameID()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLNameIDMappingRequestElement_get_NameID(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NameID)
		this->_Inst_NameID = new TElSAMLID(hOutResult, ohFalse);
	else
		this->_Inst_NameID->updateHandle(hOutResult);
	return this->_Inst_NameID;
}

SB_INLINE void TElSAMLNameIDMappingRequestElement::set_NameID(TElSAMLID &Value)
{
	SBCheckError(TElSAMLNameIDMappingRequestElement_set_NameID(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLNameIDMappingRequestElement::set_NameID(TElSAMLID *Value)
{
	SBCheckError(TElSAMLNameIDMappingRequestElement_set_NameID(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLID */

#ifdef SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT
TElSAMLNameIDPolicyElement* TElSAMLNameIDMappingRequestElement::get_NameIDPolicy()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLNameIDMappingRequestElement_get_NameIDPolicy(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NameIDPolicy)
		this->_Inst_NameIDPolicy = new TElSAMLNameIDPolicyElement(hOutResult, ohFalse);
	else
		this->_Inst_NameIDPolicy->updateHandle(hOutResult);
	return this->_Inst_NameIDPolicy;
}

SB_INLINE void TElSAMLNameIDMappingRequestElement::set_NameIDPolicy(TElSAMLNameIDPolicyElement &Value)
{
	SBCheckError(TElSAMLNameIDMappingRequestElement_set_NameIDPolicy(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLNameIDMappingRequestElement::set_NameIDPolicy(TElSAMLNameIDPolicyElement *Value)
{
	SBCheckError(TElSAMLNameIDMappingRequestElement_set_NameIDPolicy(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT */

void TElSAMLNameIDMappingRequestElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLID
	this->_Inst_NameID = NULL;
#endif /* SB_USE_CLASS_TELSAMLID */
#ifdef SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT
	this->_Inst_NameIDPolicy = NULL;
#endif /* SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT */
}

TElSAMLNameIDMappingRequestElement::TElSAMLNameIDMappingRequestElement(TElSAMLNameIDMappingRequestElementHandle handle, TElOwnHandle ownHandle) : TElSAMLRequestAbstractType(handle, ownHandle)
{
	initInstances();
}

TElSAMLNameIDMappingRequestElement::TElSAMLNameIDMappingRequestElement() : TElSAMLRequestAbstractType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLNameIDMappingRequestElement_Create(&_Handle));
}

TElSAMLNameIDMappingRequestElement::~TElSAMLNameIDMappingRequestElement()
{
#ifdef SB_USE_CLASS_TELSAMLID
	delete this->_Inst_NameID;
	this->_Inst_NameID = NULL;
#endif /* SB_USE_CLASS_TELSAMLID */
#ifdef SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT
	delete this->_Inst_NameIDPolicy;
	this->_Inst_NameIDPolicy = NULL;
#endif /* SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT */
}
#endif /* SB_USE_CLASS_TELSAMLNAMEIDMAPPINGREQUESTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLNAMEIDMAPPINGRESPONSEELEMENT

SB_INLINE void TElSAMLNameIDMappingResponseElement::Clear()
{
	SBCheckError(TElSAMLNameIDMappingResponseElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLNameIDMappingResponseElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLNameIDMappingResponseElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLNameIDMappingResponseElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLNameIDMappingResponseElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLNameIDMappingResponseElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLNameIDMappingResponseElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLNameIDMappingResponseElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLNameIDMappingResponseElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELSAMLID
TElSAMLID* TElSAMLNameIDMappingResponseElement::get_NameID()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLNameIDMappingResponseElement_get_NameID(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NameID)
		this->_Inst_NameID = new TElSAMLID(hOutResult, ohFalse);
	else
		this->_Inst_NameID->updateHandle(hOutResult);
	return this->_Inst_NameID;
}

SB_INLINE void TElSAMLNameIDMappingResponseElement::set_NameID(TElSAMLID &Value)
{
	SBCheckError(TElSAMLNameIDMappingResponseElement_set_NameID(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLNameIDMappingResponseElement::set_NameID(TElSAMLID *Value)
{
	SBCheckError(TElSAMLNameIDMappingResponseElement_set_NameID(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLID */

void TElSAMLNameIDMappingResponseElement::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLID
	this->_Inst_NameID = NULL;
#endif /* SB_USE_CLASS_TELSAMLID */
}

TElSAMLNameIDMappingResponseElement::TElSAMLNameIDMappingResponseElement(TElSAMLNameIDMappingResponseElementHandle handle, TElOwnHandle ownHandle) : TElSAMLStatusResponseType(handle, ownHandle)
{
	initInstances();
}

TElSAMLNameIDMappingResponseElement::TElSAMLNameIDMappingResponseElement() : TElSAMLStatusResponseType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLNameIDMappingResponseElement_Create(&_Handle));
}

TElSAMLNameIDMappingResponseElement::~TElSAMLNameIDMappingResponseElement()
{
#ifdef SB_USE_CLASS_TELSAMLID
	delete this->_Inst_NameID;
	this->_Inst_NameID = NULL;
#endif /* SB_USE_CLASS_TELSAMLID */
}
#endif /* SB_USE_CLASS_TELSAMLNAMEIDMAPPINGRESPONSEELEMENT */

};	/* namespace SecureBlackbox */
