#include "sbxmlsamlmetadata.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSAMLMETADATAROOTELEMENT

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TSBSAMLMetaRootElementType TElSAMLMetadataRootElement::DetectType(TElXMLDOMElement &Element)
{
	TSBSAMLMetaRootElementTypeRaw OutResultRaw = 0;
	SBCheckError(TElSAMLMetadataRootElement_DetectType(Element.getHandle(), &OutResultRaw));
	return (TSBSAMLMetaRootElementType)OutResultRaw;
}

TSBSAMLMetaRootElementType TElSAMLMetadataRootElement::DetectType(TElXMLDOMElement *Element)
{
	TSBSAMLMetaRootElementTypeRaw OutResultRaw = 0;
	SBCheckError(TElSAMLMetadataRootElement_DetectType((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBSAMLMetaRootElementType)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TSBSAMLMetaRootElementType TElSAMLMetadataRootElement::DetectType_Inst(TElXMLDOMElement &Element)
{
	TSBSAMLMetaRootElementTypeRaw OutResultRaw = 0;
	SBCheckError(TElSAMLMetadataRootElement_DetectType_1(_Handle, Element.getHandle(), &OutResultRaw));
	return (TSBSAMLMetaRootElementType)OutResultRaw;
}

TSBSAMLMetaRootElementType TElSAMLMetadataRootElement::DetectType_Inst(TElXMLDOMElement *Element)
{
	TSBSAMLMetaRootElementTypeRaw OutResultRaw = 0;
	SBCheckError(TElSAMLMetadataRootElement_DetectType_1(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBSAMLMetaRootElementType)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

TElSAMLMetadataRootElement::TElSAMLMetadataRootElement(TElSAMLMetadataRootElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
}

TElSAMLMetadataRootElement::TElSAMLMetadataRootElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLMetadataRootElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLMETADATAROOTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLLOCALIZEDNAMETYPE

SB_INLINE void TElSAMLLocalizedNameType::Clear()
{
	SBCheckError(TElSAMLLocalizedNameType_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLLocalizedNameType::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLLocalizedNameType_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLLocalizedNameType::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLLocalizedNameType_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLLocalizedNameType::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLLocalizedNameType_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLLocalizedNameType::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLLocalizedNameType_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElSAMLLocalizedNameType::get_Lang(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLLocalizedNameType_get_Lang(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-760945008, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLLocalizedNameType::set_Lang(const std::string &Value)
{
	SBCheckError(TElSAMLLocalizedNameType_set_Lang(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSAMLLocalizedNameType::TElSAMLLocalizedNameType(TElSAMLLocalizedNameTypeHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
}

TElSAMLLocalizedNameType::TElSAMLLocalizedNameType() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLLocalizedNameType_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLLOCALIZEDNAMETYPE */

#ifdef SB_USE_CLASS_TELSAMLLOCALIZEDURITYPE

SB_INLINE void TElSAMLLocalizedURIType::Clear()
{
	SBCheckError(TElSAMLLocalizedURIType_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLLocalizedURIType::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLLocalizedURIType_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLLocalizedURIType::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLLocalizedURIType_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLLocalizedURIType::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLLocalizedURIType_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLLocalizedURIType::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLLocalizedURIType_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElSAMLLocalizedURIType::get_Lang(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLLocalizedURIType_get_Lang(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-178598613, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLLocalizedURIType::set_Lang(const std::string &Value)
{
	SBCheckError(TElSAMLLocalizedURIType_set_Lang(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSAMLLocalizedURIType::TElSAMLLocalizedURIType(TElSAMLLocalizedURITypeHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
}

TElSAMLLocalizedURIType::TElSAMLLocalizedURIType() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLLocalizedURIType_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLLOCALIZEDURITYPE */

#ifdef SB_USE_CLASS_TELSAMLENDPOINTTYPE

SB_INLINE void TElSAMLEndpointType::Clear()
{
	SBCheckError(TElSAMLEndpointType_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLEndpointType::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLEndpointType_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLEndpointType::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLEndpointType_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLEndpointType::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLEndpointType_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLEndpointType::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLEndpointType_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElSAMLEndpointType::get_Binding(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLEndpointType_get_Binding(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(12739884, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLEndpointType::set_Binding(const std::string &Value)
{
	SBCheckError(TElSAMLEndpointType_set_Binding(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLEndpointType::get_Location(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLEndpointType_get_Location(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-183285072, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLEndpointType::set_Location(const std::string &Value)
{
	SBCheckError(TElSAMLEndpointType_set_Location(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLEndpointType::get_ResponseLocation(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLEndpointType_get_ResponseLocation(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1272040794, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLEndpointType::set_ResponseLocation(const std::string &Value)
{
	SBCheckError(TElSAMLEndpointType_set_ResponseLocation(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSAMLEndpointType::TElSAMLEndpointType(TElSAMLEndpointTypeHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
}

TElSAMLEndpointType::TElSAMLEndpointType() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLEndpointType_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLENDPOINTTYPE */

#ifdef SB_USE_CLASS_TELSAMLINDEXEDENDPOINTTYPE

SB_INLINE void TElSAMLIndexedEndpointType::Clear()
{
	SBCheckError(TElSAMLIndexedEndpointType_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLIndexedEndpointType::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLIndexedEndpointType_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLIndexedEndpointType::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLIndexedEndpointType_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLIndexedEndpointType::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLIndexedEndpointType_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLIndexedEndpointType::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLIndexedEndpointType_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int32_t TElSAMLIndexedEndpointType::get__Index()
{
	int32_t OutResult;
	SBCheckError(TElSAMLIndexedEndpointType_get__Index(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLIndexedEndpointType::set__Index(int32_t Value)
{
	SBCheckError(TElSAMLIndexedEndpointType_set__Index(_Handle, Value));
}

bool TElSAMLIndexedEndpointType::get_IsDefault()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLIndexedEndpointType_get_IsDefault(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLIndexedEndpointType::set_IsDefault(bool Value)
{
	SBCheckError(TElSAMLIndexedEndpointType_set_IsDefault(_Handle, (int8_t)Value));
}

bool TElSAMLIndexedEndpointType::get_UseDefault()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLIndexedEndpointType_get_UseDefault(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLIndexedEndpointType::set_UseDefault(bool Value)
{
	SBCheckError(TElSAMLIndexedEndpointType_set_UseDefault(_Handle, (int8_t)Value));
}

TElSAMLIndexedEndpointType::TElSAMLIndexedEndpointType(TElSAMLIndexedEndpointTypeHandle handle, TElOwnHandle ownHandle) : TElSAMLEndpointType(handle, ownHandle)
{
}

TElSAMLIndexedEndpointType::TElSAMLIndexedEndpointType() : TElSAMLEndpointType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLIndexedEndpointType_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLINDEXEDENDPOINTTYPE */

#ifdef SB_USE_CLASS_TELSAMLENTITYDESCRIPTORELEMENT

SB_INLINE void TElSAMLEntityDescriptorElement::Clear()
{
	SBCheckError(TElSAMLEntityDescriptorElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLEntityDescriptorElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLEntityDescriptorElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLEntityDescriptorElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLEntityDescriptorElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLEntityDescriptorElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLEntityDescriptorElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLEntityDescriptorElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLEntityDescriptorElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

bool TElSAMLEntityDescriptorElement::get_Signed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLEntityDescriptorElement_get_Signed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLEntityDescriptorElement::set_Signed(bool Value)
{
	SBCheckError(TElSAMLEntityDescriptorElement_set_Signed(_Handle, (int8_t)Value));
}

void TElSAMLEntityDescriptorElement::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLEntityDescriptorElement_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1027557691, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLEntityDescriptorElement::set_ID(const std::string &Value)
{
	SBCheckError(TElSAMLEntityDescriptorElement_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElSAMLEntityDescriptorElement::get_ValidUntil()
{
	int64_t OutResult;
	SBCheckError(TElSAMLEntityDescriptorElement_get_ValidUntil(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLEntityDescriptorElement::set_ValidUntil(int64_t Value)
{
	SBCheckError(TElSAMLEntityDescriptorElement_set_ValidUntil(_Handle, Value));
}

void TElSAMLEntityDescriptorElement::get_CacheDuration(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLEntityDescriptorElement_get_CacheDuration(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(999304954, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLEntityDescriptorElement::set_CacheDuration(const std::string &Value)
{
	SBCheckError(TElSAMLEntityDescriptorElement_set_CacheDuration(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELXMLSIGNATURE
TElXMLSignature* TElSAMLEntityDescriptorElement::get_Signature()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLEntityDescriptorElement_get_Signature(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signature)
		this->_Inst_Signature = new TElXMLSignature(hOutResult, ohFalse);
	else
		this->_Inst_Signature->updateHandle(hOutResult);
	return this->_Inst_Signature;
}
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLEntityDescriptorElement::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLEntityDescriptorElement_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TList(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TLIST */

void TElSAMLEntityDescriptorElement::get_EntityID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLEntityDescriptorElement_get_EntityID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1747021765, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLEntityDescriptorElement::set_EntityID(const std::string &Value)
{
	SBCheckError(TElSAMLEntityDescriptorElement_set_EntityID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELSAMLAFFILIATIONDESCRIPTORELEMENT
TElSAMLAffiliationDescriptorElement* TElSAMLEntityDescriptorElement::get_AffiliationDescriptor()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLEntityDescriptorElement_get_AffiliationDescriptor(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AffiliationDescriptor)
		this->_Inst_AffiliationDescriptor = new TElSAMLAffiliationDescriptorElement(hOutResult, ohFalse);
	else
		this->_Inst_AffiliationDescriptor->updateHandle(hOutResult);
	return this->_Inst_AffiliationDescriptor;
}

SB_INLINE void TElSAMLEntityDescriptorElement::set_AffiliationDescriptor(TElSAMLAffiliationDescriptorElement &Value)
{
	SBCheckError(TElSAMLEntityDescriptorElement_set_AffiliationDescriptor(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLEntityDescriptorElement::set_AffiliationDescriptor(TElSAMLAffiliationDescriptorElement *Value)
{
	SBCheckError(TElSAMLEntityDescriptorElement_set_AffiliationDescriptor(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLAFFILIATIONDESCRIPTORELEMENT */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLEntityDescriptorElement::get_Descriptors()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLEntityDescriptorElement_get_Descriptors(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Descriptors)
		this->_Inst_Descriptors = new TList(hOutResult, ohFalse);
	else
		this->_Inst_Descriptors->updateHandle(hOutResult);
	return this->_Inst_Descriptors;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TELSAMLORGANIZATIONELEMENT
TElSAMLOrganizationElement* TElSAMLEntityDescriptorElement::get_Organization()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLEntityDescriptorElement_get_Organization(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Organization)
		this->_Inst_Organization = new TElSAMLOrganizationElement(hOutResult, ohFalse);
	else
		this->_Inst_Organization->updateHandle(hOutResult);
	return this->_Inst_Organization;
}

SB_INLINE void TElSAMLEntityDescriptorElement::set_Organization(TElSAMLOrganizationElement &Value)
{
	SBCheckError(TElSAMLEntityDescriptorElement_set_Organization(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLEntityDescriptorElement::set_Organization(TElSAMLOrganizationElement *Value)
{
	SBCheckError(TElSAMLEntityDescriptorElement_set_Organization(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLORGANIZATIONELEMENT */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLEntityDescriptorElement::get_ContactPersons()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLEntityDescriptorElement_get_ContactPersons(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ContactPersons)
		this->_Inst_ContactPersons = new TList(hOutResult, ohFalse);
	else
		this->_Inst_ContactPersons->updateHandle(hOutResult);
	return this->_Inst_ContactPersons;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLEntityDescriptorElement::get_AdditionalMetadataLocations()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLEntityDescriptorElement_get_AdditionalMetadataLocations(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AdditionalMetadataLocations)
		this->_Inst_AdditionalMetadataLocations = new TList(hOutResult, ohFalse);
	else
		this->_Inst_AdditionalMetadataLocations->updateHandle(hOutResult);
	return this->_Inst_AdditionalMetadataLocations;
}
#endif /* SB_USE_CLASS_TLIST */

void TElSAMLEntityDescriptorElement::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLSIGNATURE
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TELSAMLAFFILIATIONDESCRIPTORELEMENT
	this->_Inst_AffiliationDescriptor = NULL;
#endif /* SB_USE_CLASS_TELSAMLAFFILIATIONDESCRIPTORELEMENT */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_Descriptors = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TELSAMLORGANIZATIONELEMENT
	this->_Inst_Organization = NULL;
#endif /* SB_USE_CLASS_TELSAMLORGANIZATIONELEMENT */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_ContactPersons = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_AdditionalMetadataLocations = NULL;
#endif /* SB_USE_CLASS_TLIST */
}

TElSAMLEntityDescriptorElement::TElSAMLEntityDescriptorElement(TElSAMLEntityDescriptorElementHandle handle, TElOwnHandle ownHandle) : TElSAMLMetadataRootElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLEntityDescriptorElement::TElSAMLEntityDescriptorElement() : TElSAMLMetadataRootElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLEntityDescriptorElement_Create(&_Handle));
}

TElSAMLEntityDescriptorElement::~TElSAMLEntityDescriptorElement()
{
#ifdef SB_USE_CLASS_TELXMLSIGNATURE
	delete this->_Inst_Signature;
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TELSAMLAFFILIATIONDESCRIPTORELEMENT
	delete this->_Inst_AffiliationDescriptor;
	this->_Inst_AffiliationDescriptor = NULL;
#endif /* SB_USE_CLASS_TELSAMLAFFILIATIONDESCRIPTORELEMENT */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_Descriptors;
	this->_Inst_Descriptors = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TELSAMLORGANIZATIONELEMENT
	delete this->_Inst_Organization;
	this->_Inst_Organization = NULL;
#endif /* SB_USE_CLASS_TELSAMLORGANIZATIONELEMENT */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_ContactPersons;
	this->_Inst_ContactPersons = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_AdditionalMetadataLocations;
	this->_Inst_AdditionalMetadataLocations = NULL;
#endif /* SB_USE_CLASS_TLIST */
}
#endif /* SB_USE_CLASS_TELSAMLENTITYDESCRIPTORELEMENT */

#ifdef SB_USE_CLASS_TELSAMLENTITIESDESCRIPTORELEMENT

SB_INLINE void TElSAMLEntitiesDescriptorElement::Clear()
{
	SBCheckError(TElSAMLEntitiesDescriptorElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLEntitiesDescriptorElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLEntitiesDescriptorElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLEntitiesDescriptorElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLEntitiesDescriptorElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLEntitiesDescriptorElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLEntitiesDescriptorElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLEntitiesDescriptorElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLEntitiesDescriptorElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

bool TElSAMLEntitiesDescriptorElement::get_Signed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLEntitiesDescriptorElement_get_Signed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLEntitiesDescriptorElement::set_Signed(bool Value)
{
	SBCheckError(TElSAMLEntitiesDescriptorElement_set_Signed(_Handle, (int8_t)Value));
}

void TElSAMLEntitiesDescriptorElement::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLEntitiesDescriptorElement_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1633441119, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLEntitiesDescriptorElement::set_ID(const std::string &Value)
{
	SBCheckError(TElSAMLEntitiesDescriptorElement_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElSAMLEntitiesDescriptorElement::get_ValidUntil()
{
	int64_t OutResult;
	SBCheckError(TElSAMLEntitiesDescriptorElement_get_ValidUntil(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLEntitiesDescriptorElement::set_ValidUntil(int64_t Value)
{
	SBCheckError(TElSAMLEntitiesDescriptorElement_set_ValidUntil(_Handle, Value));
}

void TElSAMLEntitiesDescriptorElement::get_CacheDuration(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLEntitiesDescriptorElement_get_CacheDuration(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2123828786, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLEntitiesDescriptorElement::set_CacheDuration(const std::string &Value)
{
	SBCheckError(TElSAMLEntitiesDescriptorElement_set_CacheDuration(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELXMLSIGNATURE
TElXMLSignature* TElSAMLEntitiesDescriptorElement::get_Signature()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLEntitiesDescriptorElement_get_Signature(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signature)
		this->_Inst_Signature = new TElXMLSignature(hOutResult, ohFalse);
	else
		this->_Inst_Signature->updateHandle(hOutResult);
	return this->_Inst_Signature;
}
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLEntitiesDescriptorElement::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLEntitiesDescriptorElement_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TList(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TLIST */

void TElSAMLEntitiesDescriptorElement::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLEntitiesDescriptorElement_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1761130803, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLEntitiesDescriptorElement::set_Name(const std::string &Value)
{
	SBCheckError(TElSAMLEntitiesDescriptorElement_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLEntitiesDescriptorElement::get_Entities()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLEntitiesDescriptorElement_get_Entities(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Entities)
		this->_Inst_Entities = new TList(hOutResult, ohFalse);
	else
		this->_Inst_Entities->updateHandle(hOutResult);
	return this->_Inst_Entities;
}
#endif /* SB_USE_CLASS_TLIST */

void TElSAMLEntitiesDescriptorElement::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLSIGNATURE
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_Entities = NULL;
#endif /* SB_USE_CLASS_TLIST */
}

TElSAMLEntitiesDescriptorElement::TElSAMLEntitiesDescriptorElement(TElSAMLEntitiesDescriptorElementHandle handle, TElOwnHandle ownHandle) : TElSAMLMetadataRootElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLEntitiesDescriptorElement::TElSAMLEntitiesDescriptorElement() : TElSAMLMetadataRootElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLEntitiesDescriptorElement_Create(&_Handle));
}

TElSAMLEntitiesDescriptorElement::~TElSAMLEntitiesDescriptorElement()
{
#ifdef SB_USE_CLASS_TELXMLSIGNATURE
	delete this->_Inst_Signature;
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_Entities;
	this->_Inst_Entities = NULL;
#endif /* SB_USE_CLASS_TLIST */
}
#endif /* SB_USE_CLASS_TELSAMLENTITIESDESCRIPTORELEMENT */

#ifdef SB_USE_CLASS_TELSAMLKEYDESCRIPTORELEMENT

SB_INLINE void TElSAMLKeyDescriptorElement::Clear()
{
	SBCheckError(TElSAMLKeyDescriptorElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLKeyDescriptorElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLKeyDescriptorElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLKeyDescriptorElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLKeyDescriptorElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLKeyDescriptorElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLKeyDescriptorElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLKeyDescriptorElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLKeyDescriptorElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElSAMLKeyDescriptorElement::Init(TElX509Certificate &Cert)
{
	SBCheckError(TElSAMLKeyDescriptorElement_Init(_Handle, Cert.getHandle()));
}

SB_INLINE void TElSAMLKeyDescriptorElement::Init(TElX509Certificate *Cert)
{
	SBCheckError(TElSAMLKeyDescriptorElement_Init(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

TSBSAMLKeyUse TElSAMLKeyDescriptorElement::get_Use()
{
	TSBSAMLKeyUseRaw OutResultRaw = 0;
	SBCheckError(TElSAMLKeyDescriptorElement_get_Use(_Handle, &OutResultRaw));
	return (TSBSAMLKeyUse)OutResultRaw;
}

SB_INLINE void TElSAMLKeyDescriptorElement::set_Use(TSBSAMLKeyUse Value)
{
	SBCheckError(TElSAMLKeyDescriptorElement_set_Use(_Handle, (TSBSAMLKeyUseRaw)Value));
}

#ifdef SB_USE_CLASS_TELXMLKEYINFO
TElXMLKeyInfo* TElSAMLKeyDescriptorElement::get_KeyInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLKeyDescriptorElement_get_KeyInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyInfo)
		this->_Inst_KeyInfo = new TElXMLKeyInfo(hOutResult, ohFalse);
	else
		this->_Inst_KeyInfo->updateHandle(hOutResult);
	return this->_Inst_KeyInfo;
}

SB_INLINE void TElSAMLKeyDescriptorElement::set_KeyInfo(TElXMLKeyInfo &Value)
{
	SBCheckError(TElSAMLKeyDescriptorElement_set_KeyInfo(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLKeyDescriptorElement::set_KeyInfo(TElXMLKeyInfo *Value)
{
	SBCheckError(TElSAMLKeyDescriptorElement_set_KeyInfo(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLKEYINFO */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLKeyDescriptorElement::get_EncryptionMethods()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLKeyDescriptorElement_get_EncryptionMethods(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptionMethods)
		this->_Inst_EncryptionMethods = new TList(hOutResult, ohFalse);
	else
		this->_Inst_EncryptionMethods->updateHandle(hOutResult);
	return this->_Inst_EncryptionMethods;
}

SB_INLINE void TElSAMLKeyDescriptorElement::set_EncryptionMethods(TList &Value)
{
	SBCheckError(TElSAMLKeyDescriptorElement_set_EncryptionMethods(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLKeyDescriptorElement::set_EncryptionMethods(TList *Value)
{
	SBCheckError(TElSAMLKeyDescriptorElement_set_EncryptionMethods(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TLIST */

void TElSAMLKeyDescriptorElement::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLKEYINFO
	this->_Inst_KeyInfo = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFO */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_EncryptionMethods = NULL;
#endif /* SB_USE_CLASS_TLIST */
}

TElSAMLKeyDescriptorElement::TElSAMLKeyDescriptorElement(TElSAMLKeyDescriptorElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLKeyDescriptorElement::TElSAMLKeyDescriptorElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLKeyDescriptorElement_Create(&_Handle));
}

TElSAMLKeyDescriptorElement::~TElSAMLKeyDescriptorElement()
{
#ifdef SB_USE_CLASS_TELXMLKEYINFO
	delete this->_Inst_KeyInfo;
	this->_Inst_KeyInfo = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFO */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_EncryptionMethods;
	this->_Inst_EncryptionMethods = NULL;
#endif /* SB_USE_CLASS_TLIST */
}
#endif /* SB_USE_CLASS_TELSAMLKEYDESCRIPTORELEMENT */

#ifdef SB_USE_CLASS_TELSAMLORGANIZATIONELEMENT

SB_INLINE void TElSAMLOrganizationElement::Clear()
{
	SBCheckError(TElSAMLOrganizationElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLOrganizationElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLOrganizationElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLOrganizationElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLOrganizationElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLOrganizationElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLOrganizationElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLOrganizationElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLOrganizationElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLOrganizationElement::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLOrganizationElement_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TList(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLOrganizationElement::get_OrganizationNames()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLOrganizationElement_get_OrganizationNames(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OrganizationNames)
		this->_Inst_OrganizationNames = new TList(hOutResult, ohFalse);
	else
		this->_Inst_OrganizationNames->updateHandle(hOutResult);
	return this->_Inst_OrganizationNames;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLOrganizationElement::get_OrganizationDisplayNames()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLOrganizationElement_get_OrganizationDisplayNames(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OrganizationDisplayNames)
		this->_Inst_OrganizationDisplayNames = new TList(hOutResult, ohFalse);
	else
		this->_Inst_OrganizationDisplayNames->updateHandle(hOutResult);
	return this->_Inst_OrganizationDisplayNames;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLOrganizationElement::get_OrganizationURLs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLOrganizationElement_get_OrganizationURLs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OrganizationURLs)
		this->_Inst_OrganizationURLs = new TList(hOutResult, ohFalse);
	else
		this->_Inst_OrganizationURLs->updateHandle(hOutResult);
	return this->_Inst_OrganizationURLs;
}
#endif /* SB_USE_CLASS_TLIST */

void TElSAMLOrganizationElement::initInstances()
{
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_OrganizationNames = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_OrganizationDisplayNames = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_OrganizationURLs = NULL;
#endif /* SB_USE_CLASS_TLIST */
}

TElSAMLOrganizationElement::TElSAMLOrganizationElement(TElSAMLOrganizationElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLOrganizationElement::TElSAMLOrganizationElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLOrganizationElement_Create(&_Handle));
}

TElSAMLOrganizationElement::~TElSAMLOrganizationElement()
{
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_OrganizationNames;
	this->_Inst_OrganizationNames = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_OrganizationDisplayNames;
	this->_Inst_OrganizationDisplayNames = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_OrganizationURLs;
	this->_Inst_OrganizationURLs = NULL;
#endif /* SB_USE_CLASS_TLIST */
}
#endif /* SB_USE_CLASS_TELSAMLORGANIZATIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLCONTACTPERSONELEMENT

SB_INLINE void TElSAMLContactPersonElement::Clear()
{
	SBCheckError(TElSAMLContactPersonElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLContactPersonElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLContactPersonElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLContactPersonElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLContactPersonElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLContactPersonElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLContactPersonElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLContactPersonElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLContactPersonElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

TSBSAMLContactType TElSAMLContactPersonElement::get_ContactType()
{
	TSBSAMLContactTypeRaw OutResultRaw = 0;
	SBCheckError(TElSAMLContactPersonElement_get_ContactType(_Handle, &OutResultRaw));
	return (TSBSAMLContactType)OutResultRaw;
}

SB_INLINE void TElSAMLContactPersonElement::set_ContactType(TSBSAMLContactType Value)
{
	SBCheckError(TElSAMLContactPersonElement_set_ContactType(_Handle, (TSBSAMLContactTypeRaw)Value));
}

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLContactPersonElement::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLContactPersonElement_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TList(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TLIST */

void TElSAMLContactPersonElement::get_Company(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLContactPersonElement_get_Company(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1231702829, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLContactPersonElement::set_Company(const std::string &Value)
{
	SBCheckError(TElSAMLContactPersonElement_set_Company(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLContactPersonElement::get_GivenName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLContactPersonElement_get_GivenName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(377757265, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLContactPersonElement::set_GivenName(const std::string &Value)
{
	SBCheckError(TElSAMLContactPersonElement_set_GivenName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLContactPersonElement::get_SurName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLContactPersonElement_get_SurName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1100052051, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLContactPersonElement::set_SurName(const std::string &Value)
{
	SBCheckError(TElSAMLContactPersonElement_set_SurName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSAMLContactPersonElement::get_EmailAddresses()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLContactPersonElement_get_EmailAddresses(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EmailAddresses)
		this->_Inst_EmailAddresses = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_EmailAddresses->updateHandle(hOutResult);
	return this->_Inst_EmailAddresses;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSAMLContactPersonElement::get_EmailAddresses()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLContactPersonElement_get_EmailAddresses(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EmailAddresses)
		this->_Inst_EmailAddresses = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_EmailAddresses->updateHandle(hOutResult);
	return this->_Inst_EmailAddresses;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSAMLContactPersonElement::get_TelephoneNumbers()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLContactPersonElement_get_TelephoneNumbers(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TelephoneNumbers)
		this->_Inst_TelephoneNumbers = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_TelephoneNumbers->updateHandle(hOutResult);
	return this->_Inst_TelephoneNumbers;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSAMLContactPersonElement::get_TelephoneNumbers()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLContactPersonElement_get_TelephoneNumbers(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TelephoneNumbers)
		this->_Inst_TelephoneNumbers = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_TelephoneNumbers->updateHandle(hOutResult);
	return this->_Inst_TelephoneNumbers;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElSAMLContactPersonElement::initInstances()
{
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_EmailAddresses = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_EmailAddresses = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_TelephoneNumbers = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_TelephoneNumbers = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElSAMLContactPersonElement::TElSAMLContactPersonElement(TElSAMLContactPersonElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLContactPersonElement::TElSAMLContactPersonElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLContactPersonElement_Create(&_Handle));
}

TElSAMLContactPersonElement::~TElSAMLContactPersonElement()
{
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_EmailAddresses;
	this->_Inst_EmailAddresses = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_EmailAddresses;
	this->_Inst_EmailAddresses = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_TelephoneNumbers;
	this->_Inst_TelephoneNumbers = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_TelephoneNumbers;
	this->_Inst_TelephoneNumbers = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELSAMLCONTACTPERSONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLROLEDESCRIPTORELEMENT

SB_INLINE void TElSAMLRoleDescriptorElement::Clear()
{
	SBCheckError(TElSAMLRoleDescriptorElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLRoleDescriptorElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLRoleDescriptorElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLRoleDescriptorElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLRoleDescriptorElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLRoleDescriptorElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLRoleDescriptorElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLRoleDescriptorElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLRoleDescriptorElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

bool TElSAMLRoleDescriptorElement::get_Signed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLRoleDescriptorElement_get_Signed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLRoleDescriptorElement::set_Signed(bool Value)
{
	SBCheckError(TElSAMLRoleDescriptorElement_set_Signed(_Handle, (int8_t)Value));
}

void TElSAMLRoleDescriptorElement::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLRoleDescriptorElement_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(958938671, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLRoleDescriptorElement::set_ID(const std::string &Value)
{
	SBCheckError(TElSAMLRoleDescriptorElement_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElSAMLRoleDescriptorElement::get_ValidUntil()
{
	int64_t OutResult;
	SBCheckError(TElSAMLRoleDescriptorElement_get_ValidUntil(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLRoleDescriptorElement::set_ValidUntil(int64_t Value)
{
	SBCheckError(TElSAMLRoleDescriptorElement_set_ValidUntil(_Handle, Value));
}

void TElSAMLRoleDescriptorElement::get_CacheDuration(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLRoleDescriptorElement_get_CacheDuration(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2109810192, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLRoleDescriptorElement::set_CacheDuration(const std::string &Value)
{
	SBCheckError(TElSAMLRoleDescriptorElement_set_CacheDuration(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSAMLRoleDescriptorElement::get_ProtocolSupportEnumeration()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLRoleDescriptorElement_get_ProtocolSupportEnumeration(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ProtocolSupportEnumeration)
		this->_Inst_ProtocolSupportEnumeration = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_ProtocolSupportEnumeration->updateHandle(hOutResult);
	return this->_Inst_ProtocolSupportEnumeration;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSAMLRoleDescriptorElement::get_ProtocolSupportEnumeration()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLRoleDescriptorElement_get_ProtocolSupportEnumeration(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ProtocolSupportEnumeration)
		this->_Inst_ProtocolSupportEnumeration = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_ProtocolSupportEnumeration->updateHandle(hOutResult);
	return this->_Inst_ProtocolSupportEnumeration;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElSAMLRoleDescriptorElement::get_ErrorURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLRoleDescriptorElement_get_ErrorURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1004902298, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLRoleDescriptorElement::set_ErrorURL(const std::string &Value)
{
	SBCheckError(TElSAMLRoleDescriptorElement_set_ErrorURL(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELXMLSIGNATURE
TElXMLSignature* TElSAMLRoleDescriptorElement::get_Signature()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLRoleDescriptorElement_get_Signature(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signature)
		this->_Inst_Signature = new TElXMLSignature(hOutResult, ohFalse);
	else
		this->_Inst_Signature->updateHandle(hOutResult);
	return this->_Inst_Signature;
}
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLRoleDescriptorElement::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLRoleDescriptorElement_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TList(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLRoleDescriptorElement::get_KeyDescriptors()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLRoleDescriptorElement_get_KeyDescriptors(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyDescriptors)
		this->_Inst_KeyDescriptors = new TList(hOutResult, ohFalse);
	else
		this->_Inst_KeyDescriptors->updateHandle(hOutResult);
	return this->_Inst_KeyDescriptors;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TELSAMLORGANIZATIONELEMENT
TElSAMLOrganizationElement* TElSAMLRoleDescriptorElement::get_Organization()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLRoleDescriptorElement_get_Organization(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Organization)
		this->_Inst_Organization = new TElSAMLOrganizationElement(hOutResult, ohFalse);
	else
		this->_Inst_Organization->updateHandle(hOutResult);
	return this->_Inst_Organization;
}

SB_INLINE void TElSAMLRoleDescriptorElement::set_Organization(TElSAMLOrganizationElement &Value)
{
	SBCheckError(TElSAMLRoleDescriptorElement_set_Organization(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLRoleDescriptorElement::set_Organization(TElSAMLOrganizationElement *Value)
{
	SBCheckError(TElSAMLRoleDescriptorElement_set_Organization(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLORGANIZATIONELEMENT */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLRoleDescriptorElement::get_ContactPersons()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLRoleDescriptorElement_get_ContactPersons(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ContactPersons)
		this->_Inst_ContactPersons = new TList(hOutResult, ohFalse);
	else
		this->_Inst_ContactPersons->updateHandle(hOutResult);
	return this->_Inst_ContactPersons;
}
#endif /* SB_USE_CLASS_TLIST */

void TElSAMLRoleDescriptorElement::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_ProtocolSupportEnumeration = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_ProtocolSupportEnumeration = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELXMLSIGNATURE
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_KeyDescriptors = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TELSAMLORGANIZATIONELEMENT
	this->_Inst_Organization = NULL;
#endif /* SB_USE_CLASS_TELSAMLORGANIZATIONELEMENT */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_ContactPersons = NULL;
#endif /* SB_USE_CLASS_TLIST */
}

TElSAMLRoleDescriptorElement::TElSAMLRoleDescriptorElement(TElSAMLRoleDescriptorElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLRoleDescriptorElement::TElSAMLRoleDescriptorElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLRoleDescriptorElement_Create(&_Handle));
}

TElSAMLRoleDescriptorElement::~TElSAMLRoleDescriptorElement()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_ProtocolSupportEnumeration;
	this->_Inst_ProtocolSupportEnumeration = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_ProtocolSupportEnumeration;
	this->_Inst_ProtocolSupportEnumeration = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELXMLSIGNATURE
	delete this->_Inst_Signature;
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_KeyDescriptors;
	this->_Inst_KeyDescriptors = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TELSAMLORGANIZATIONELEMENT
	delete this->_Inst_Organization;
	this->_Inst_Organization = NULL;
#endif /* SB_USE_CLASS_TELSAMLORGANIZATIONELEMENT */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_ContactPersons;
	this->_Inst_ContactPersons = NULL;
#endif /* SB_USE_CLASS_TLIST */
}
#endif /* SB_USE_CLASS_TELSAMLROLEDESCRIPTORELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUTHNQUERYSERVICEELEMENT

TElSAMLAuthnQueryServiceElement::TElSAMLAuthnQueryServiceElement(TElSAMLAuthnQueryServiceElementHandle handle, TElOwnHandle ownHandle) : TElSAMLEndpointType(handle, ownHandle)
{
}

TElSAMLAuthnQueryServiceElement::TElSAMLAuthnQueryServiceElement() : TElSAMLEndpointType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLAuthnQueryServiceElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLAUTHNQUERYSERVICEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONIDREQUESTSERVICEELEMENT

TElSAMLAssertionIDRequestServiceElement::TElSAMLAssertionIDRequestServiceElement(TElSAMLAssertionIDRequestServiceElementHandle handle, TElOwnHandle ownHandle) : TElSAMLEndpointType(handle, ownHandle)
{
}

TElSAMLAssertionIDRequestServiceElement::TElSAMLAssertionIDRequestServiceElement() : TElSAMLEndpointType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLAssertionIDRequestServiceElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLASSERTIONIDREQUESTSERVICEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUTHNAUTHORITYDESCRIPTORELEMENT

SB_INLINE void TElSAMLAuthnAuthorityDescriptorElement::Clear()
{
	SBCheckError(TElSAMLAuthnAuthorityDescriptorElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLAuthnAuthorityDescriptorElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLAuthnAuthorityDescriptorElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLAuthnAuthorityDescriptorElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLAuthnAuthorityDescriptorElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLAuthnAuthorityDescriptorElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAuthnAuthorityDescriptorElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLAuthnAuthorityDescriptorElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAuthnAuthorityDescriptorElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLAuthnAuthorityDescriptorElement::get_AuthnQueryServices()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAuthnAuthorityDescriptorElement_get_AuthnQueryServices(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AuthnQueryServices)
		this->_Inst_AuthnQueryServices = new TList(hOutResult, ohFalse);
	else
		this->_Inst_AuthnQueryServices->updateHandle(hOutResult);
	return this->_Inst_AuthnQueryServices;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLAuthnAuthorityDescriptorElement::get_AssertionIDRequestServices()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAuthnAuthorityDescriptorElement_get_AssertionIDRequestServices(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AssertionIDRequestServices)
		this->_Inst_AssertionIDRequestServices = new TList(hOutResult, ohFalse);
	else
		this->_Inst_AssertionIDRequestServices->updateHandle(hOutResult);
	return this->_Inst_AssertionIDRequestServices;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSAMLAuthnAuthorityDescriptorElement::get_NameIDFormats()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAuthnAuthorityDescriptorElement_get_NameIDFormats(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NameIDFormats)
		this->_Inst_NameIDFormats = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_NameIDFormats->updateHandle(hOutResult);
	return this->_Inst_NameIDFormats;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSAMLAuthnAuthorityDescriptorElement::get_NameIDFormats()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAuthnAuthorityDescriptorElement_get_NameIDFormats(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NameIDFormats)
		this->_Inst_NameIDFormats = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_NameIDFormats->updateHandle(hOutResult);
	return this->_Inst_NameIDFormats;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElSAMLAuthnAuthorityDescriptorElement::initInstances()
{
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_AuthnQueryServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_AssertionIDRequestServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_NameIDFormats = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_NameIDFormats = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElSAMLAuthnAuthorityDescriptorElement::TElSAMLAuthnAuthorityDescriptorElement(TElSAMLAuthnAuthorityDescriptorElementHandle handle, TElOwnHandle ownHandle) : TElSAMLRoleDescriptorElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLAuthnAuthorityDescriptorElement::TElSAMLAuthnAuthorityDescriptorElement() : TElSAMLRoleDescriptorElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLAuthnAuthorityDescriptorElement_Create(&_Handle));
}

TElSAMLAuthnAuthorityDescriptorElement::~TElSAMLAuthnAuthorityDescriptorElement()
{
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_AuthnQueryServices;
	this->_Inst_AuthnQueryServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_AssertionIDRequestServices;
	this->_Inst_AssertionIDRequestServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_NameIDFormats;
	this->_Inst_NameIDFormats = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_NameIDFormats;
	this->_Inst_NameIDFormats = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELSAMLAUTHNAUTHORITYDESCRIPTORELEMENT */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTESERVICEELEMENT

TElSAMLAttributeServiceElement::TElSAMLAttributeServiceElement(TElSAMLAttributeServiceElementHandle handle, TElOwnHandle ownHandle) : TElSAMLEndpointType(handle, ownHandle)
{
}

TElSAMLAttributeServiceElement::TElSAMLAttributeServiceElement() : TElSAMLEndpointType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLAttributeServiceElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLATTRIBUTESERVICEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEAUTHORITYDESCRIPTORELEMENT

SB_INLINE void TElSAMLAttributeAuthorityDescriptorElement::Clear()
{
	SBCheckError(TElSAMLAttributeAuthorityDescriptorElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLAttributeAuthorityDescriptorElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLAttributeAuthorityDescriptorElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLAttributeAuthorityDescriptorElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLAttributeAuthorityDescriptorElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLAttributeAuthorityDescriptorElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAttributeAuthorityDescriptorElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLAttributeAuthorityDescriptorElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAttributeAuthorityDescriptorElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLAttributeAuthorityDescriptorElement::get_AttributeServices()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAttributeAuthorityDescriptorElement_get_AttributeServices(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AttributeServices)
		this->_Inst_AttributeServices = new TList(hOutResult, ohFalse);
	else
		this->_Inst_AttributeServices->updateHandle(hOutResult);
	return this->_Inst_AttributeServices;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLAttributeAuthorityDescriptorElement::get_AssertionIDRequestServices()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAttributeAuthorityDescriptorElement_get_AssertionIDRequestServices(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AssertionIDRequestServices)
		this->_Inst_AssertionIDRequestServices = new TList(hOutResult, ohFalse);
	else
		this->_Inst_AssertionIDRequestServices->updateHandle(hOutResult);
	return this->_Inst_AssertionIDRequestServices;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSAMLAttributeAuthorityDescriptorElement::get_NameIDFormats()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAttributeAuthorityDescriptorElement_get_NameIDFormats(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NameIDFormats)
		this->_Inst_NameIDFormats = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_NameIDFormats->updateHandle(hOutResult);
	return this->_Inst_NameIDFormats;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSAMLAttributeAuthorityDescriptorElement::get_NameIDFormats()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAttributeAuthorityDescriptorElement_get_NameIDFormats(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NameIDFormats)
		this->_Inst_NameIDFormats = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_NameIDFormats->updateHandle(hOutResult);
	return this->_Inst_NameIDFormats;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSAMLAttributeAuthorityDescriptorElement::get_AttributeProfiles()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAttributeAuthorityDescriptorElement_get_AttributeProfiles(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AttributeProfiles)
		this->_Inst_AttributeProfiles = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_AttributeProfiles->updateHandle(hOutResult);
	return this->_Inst_AttributeProfiles;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSAMLAttributeAuthorityDescriptorElement::get_AttributeProfiles()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAttributeAuthorityDescriptorElement_get_AttributeProfiles(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AttributeProfiles)
		this->_Inst_AttributeProfiles = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_AttributeProfiles->updateHandle(hOutResult);
	return this->_Inst_AttributeProfiles;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLAttributeAuthorityDescriptorElement::get_Attributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAttributeAuthorityDescriptorElement_get_Attributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Attributes)
		this->_Inst_Attributes = new TList(hOutResult, ohFalse);
	else
		this->_Inst_Attributes->updateHandle(hOutResult);
	return this->_Inst_Attributes;
}
#endif /* SB_USE_CLASS_TLIST */

void TElSAMLAttributeAuthorityDescriptorElement::initInstances()
{
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_AttributeServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_AssertionIDRequestServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_NameIDFormats = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_NameIDFormats = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_AttributeProfiles = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_AttributeProfiles = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TLIST */
}

TElSAMLAttributeAuthorityDescriptorElement::TElSAMLAttributeAuthorityDescriptorElement(TElSAMLAttributeAuthorityDescriptorElementHandle handle, TElOwnHandle ownHandle) : TElSAMLRoleDescriptorElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLAttributeAuthorityDescriptorElement::TElSAMLAttributeAuthorityDescriptorElement() : TElSAMLRoleDescriptorElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLAttributeAuthorityDescriptorElement_Create(&_Handle));
}

TElSAMLAttributeAuthorityDescriptorElement::~TElSAMLAttributeAuthorityDescriptorElement()
{
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_AttributeServices;
	this->_Inst_AttributeServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_AssertionIDRequestServices;
	this->_Inst_AssertionIDRequestServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_NameIDFormats;
	this->_Inst_NameIDFormats = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_NameIDFormats;
	this->_Inst_NameIDFormats = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_AttributeProfiles;
	this->_Inst_AttributeProfiles = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_AttributeProfiles;
	this->_Inst_AttributeProfiles = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_Attributes;
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TLIST */
}
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEAUTHORITYDESCRIPTORELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUTHZSERVICEELEMENT

TElSAMLAuthzServiceElement::TElSAMLAuthzServiceElement(TElSAMLAuthzServiceElementHandle handle, TElOwnHandle ownHandle) : TElSAMLEndpointType(handle, ownHandle)
{
}

TElSAMLAuthzServiceElement::TElSAMLAuthzServiceElement() : TElSAMLEndpointType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLAuthzServiceElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLAUTHZSERVICEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLPDPDESCRIPTORELEMENT

SB_INLINE void TElSAMLPDPDescriptorElement::Clear()
{
	SBCheckError(TElSAMLPDPDescriptorElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLPDPDescriptorElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLPDPDescriptorElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLPDPDescriptorElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLPDPDescriptorElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLPDPDescriptorElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLPDPDescriptorElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLPDPDescriptorElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLPDPDescriptorElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLPDPDescriptorElement::get_AuthzServices()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLPDPDescriptorElement_get_AuthzServices(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AuthzServices)
		this->_Inst_AuthzServices = new TList(hOutResult, ohFalse);
	else
		this->_Inst_AuthzServices->updateHandle(hOutResult);
	return this->_Inst_AuthzServices;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLPDPDescriptorElement::get_AssertionIDRequestServices()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLPDPDescriptorElement_get_AssertionIDRequestServices(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AssertionIDRequestServices)
		this->_Inst_AssertionIDRequestServices = new TList(hOutResult, ohFalse);
	else
		this->_Inst_AssertionIDRequestServices->updateHandle(hOutResult);
	return this->_Inst_AssertionIDRequestServices;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSAMLPDPDescriptorElement::get_NameIDFormats()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLPDPDescriptorElement_get_NameIDFormats(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NameIDFormats)
		this->_Inst_NameIDFormats = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_NameIDFormats->updateHandle(hOutResult);
	return this->_Inst_NameIDFormats;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSAMLPDPDescriptorElement::get_NameIDFormats()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLPDPDescriptorElement_get_NameIDFormats(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NameIDFormats)
		this->_Inst_NameIDFormats = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_NameIDFormats->updateHandle(hOutResult);
	return this->_Inst_NameIDFormats;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElSAMLPDPDescriptorElement::initInstances()
{
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_AuthzServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_AssertionIDRequestServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_NameIDFormats = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_NameIDFormats = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElSAMLPDPDescriptorElement::TElSAMLPDPDescriptorElement(TElSAMLPDPDescriptorElementHandle handle, TElOwnHandle ownHandle) : TElSAMLRoleDescriptorElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLPDPDescriptorElement::TElSAMLPDPDescriptorElement() : TElSAMLRoleDescriptorElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLPDPDescriptorElement_Create(&_Handle));
}

TElSAMLPDPDescriptorElement::~TElSAMLPDPDescriptorElement()
{
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_AuthzServices;
	this->_Inst_AuthzServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_AssertionIDRequestServices;
	this->_Inst_AssertionIDRequestServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_NameIDFormats;
	this->_Inst_NameIDFormats = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_NameIDFormats;
	this->_Inst_NameIDFormats = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELSAMLPDPDESCRIPTORELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAFFILIATIONDESCRIPTORELEMENT

SB_INLINE void TElSAMLAffiliationDescriptorElement::Clear()
{
	SBCheckError(TElSAMLAffiliationDescriptorElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLAffiliationDescriptorElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLAffiliationDescriptorElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLAffiliationDescriptorElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLAffiliationDescriptorElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLAffiliationDescriptorElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAffiliationDescriptorElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLAffiliationDescriptorElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAffiliationDescriptorElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

bool TElSAMLAffiliationDescriptorElement::get_Signed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLAffiliationDescriptorElement_get_Signed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLAffiliationDescriptorElement::set_Signed(bool Value)
{
	SBCheckError(TElSAMLAffiliationDescriptorElement_set_Signed(_Handle, (int8_t)Value));
}

void TElSAMLAffiliationDescriptorElement::get_AffiliationOwnerID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAffiliationDescriptorElement_get_AffiliationOwnerID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1708655831, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLAffiliationDescriptorElement::set_AffiliationOwnerID(const std::string &Value)
{
	SBCheckError(TElSAMLAffiliationDescriptorElement_set_AffiliationOwnerID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLAffiliationDescriptorElement::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAffiliationDescriptorElement_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(959808201, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLAffiliationDescriptorElement::set_ID(const std::string &Value)
{
	SBCheckError(TElSAMLAffiliationDescriptorElement_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElSAMLAffiliationDescriptorElement::get_ValidUntil()
{
	int64_t OutResult;
	SBCheckError(TElSAMLAffiliationDescriptorElement_get_ValidUntil(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLAffiliationDescriptorElement::set_ValidUntil(int64_t Value)
{
	SBCheckError(TElSAMLAffiliationDescriptorElement_set_ValidUntil(_Handle, Value));
}

void TElSAMLAffiliationDescriptorElement::get_CacheDuration(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAffiliationDescriptorElement_get_CacheDuration(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2063892837, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLAffiliationDescriptorElement::set_CacheDuration(const std::string &Value)
{
	SBCheckError(TElSAMLAffiliationDescriptorElement_set_CacheDuration(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELXMLSIGNATURE
TElXMLSignature* TElSAMLAffiliationDescriptorElement::get_Signature()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAffiliationDescriptorElement_get_Signature(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signature)
		this->_Inst_Signature = new TElXMLSignature(hOutResult, ohFalse);
	else
		this->_Inst_Signature->updateHandle(hOutResult);
	return this->_Inst_Signature;
}
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLAffiliationDescriptorElement::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAffiliationDescriptorElement_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TList(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSAMLAffiliationDescriptorElement::get_AffiliateMembers()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAffiliationDescriptorElement_get_AffiliateMembers(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AffiliateMembers)
		this->_Inst_AffiliateMembers = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_AffiliateMembers->updateHandle(hOutResult);
	return this->_Inst_AffiliateMembers;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSAMLAffiliationDescriptorElement::get_AffiliateMembers()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAffiliationDescriptorElement_get_AffiliateMembers(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AffiliateMembers)
		this->_Inst_AffiliateMembers = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_AffiliateMembers->updateHandle(hOutResult);
	return this->_Inst_AffiliateMembers;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLAffiliationDescriptorElement::get_KeyDescriptors()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAffiliationDescriptorElement_get_KeyDescriptors(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyDescriptors)
		this->_Inst_KeyDescriptors = new TList(hOutResult, ohFalse);
	else
		this->_Inst_KeyDescriptors->updateHandle(hOutResult);
	return this->_Inst_KeyDescriptors;
}
#endif /* SB_USE_CLASS_TLIST */

void TElSAMLAffiliationDescriptorElement::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLSIGNATURE
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_AffiliateMembers = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_AffiliateMembers = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_KeyDescriptors = NULL;
#endif /* SB_USE_CLASS_TLIST */
}

TElSAMLAffiliationDescriptorElement::TElSAMLAffiliationDescriptorElement(TElSAMLAffiliationDescriptorElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLAffiliationDescriptorElement::TElSAMLAffiliationDescriptorElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLAffiliationDescriptorElement_Create(&_Handle));
}

TElSAMLAffiliationDescriptorElement::~TElSAMLAffiliationDescriptorElement()
{
#ifdef SB_USE_CLASS_TELXMLSIGNATURE
	delete this->_Inst_Signature;
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_AffiliateMembers;
	this->_Inst_AffiliateMembers = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_AffiliateMembers;
	this->_Inst_AffiliateMembers = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_KeyDescriptors;
	this->_Inst_KeyDescriptors = NULL;
#endif /* SB_USE_CLASS_TLIST */
}
#endif /* SB_USE_CLASS_TELSAMLAFFILIATIONDESCRIPTORELEMENT */

#ifdef SB_USE_CLASS_TELSAMLORGANIZATIONNAMEELEMENT

TElSAMLOrganizationNameElement::TElSAMLOrganizationNameElement(TElSAMLOrganizationNameElementHandle handle, TElOwnHandle ownHandle) : TElSAMLLocalizedNameType(handle, ownHandle)
{
}

TElSAMLOrganizationNameElement::TElSAMLOrganizationNameElement() : TElSAMLLocalizedNameType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLOrganizationNameElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLORGANIZATIONNAMEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLORGANIZATIONDISPLAYNAMEELEMENT

TElSAMLOrganizationDisplayNameElement::TElSAMLOrganizationDisplayNameElement(TElSAMLOrganizationDisplayNameElementHandle handle, TElOwnHandle ownHandle) : TElSAMLLocalizedNameType(handle, ownHandle)
{
}

TElSAMLOrganizationDisplayNameElement::TElSAMLOrganizationDisplayNameElement() : TElSAMLLocalizedNameType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLOrganizationDisplayNameElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLORGANIZATIONDISPLAYNAMEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLORGANIZATIONURLELEMENT

TElSAMLOrganizationURLElement::TElSAMLOrganizationURLElement(TElSAMLOrganizationURLElementHandle handle, TElOwnHandle ownHandle) : TElSAMLLocalizedURIType(handle, ownHandle)
{
}

TElSAMLOrganizationURLElement::TElSAMLOrganizationURLElement() : TElSAMLLocalizedURIType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLOrganizationURLElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLORGANIZATIONURLELEMENT */

#ifdef SB_USE_CLASS_TELSAMLADDITIONALMETADATALOCATIONELEMENT

SB_INLINE void TElSAMLAdditionalMetadataLocationElement::Clear()
{
	SBCheckError(TElSAMLAdditionalMetadataLocationElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLAdditionalMetadataLocationElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLAdditionalMetadataLocationElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLAdditionalMetadataLocationElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLAdditionalMetadataLocationElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLAdditionalMetadataLocationElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAdditionalMetadataLocationElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLAdditionalMetadataLocationElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAdditionalMetadataLocationElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElSAMLAdditionalMetadataLocationElement::get__Namespace(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAdditionalMetadataLocationElement_get__Namespace(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(253120150, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLAdditionalMetadataLocationElement::set__Namespace(const std::string &Value)
{
	SBCheckError(TElSAMLAdditionalMetadataLocationElement_set__Namespace(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLAdditionalMetadataLocationElement::get_URI(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLAdditionalMetadataLocationElement_get_URI(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1810730174, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElSAMLAdditionalMetadataLocationElement::TElSAMLAdditionalMetadataLocationElement(TElSAMLAdditionalMetadataLocationElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
}

TElSAMLAdditionalMetadataLocationElement::TElSAMLAdditionalMetadataLocationElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLAdditionalMetadataLocationElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLADDITIONALMETADATALOCATIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLARTIFACTRESOLUTIONSERVICEELEMENT

TElSAMLArtifactResolutionServiceElement::TElSAMLArtifactResolutionServiceElement(TElSAMLArtifactResolutionServiceElementHandle handle, TElOwnHandle ownHandle) : TElSAMLIndexedEndpointType(handle, ownHandle)
{
}

TElSAMLArtifactResolutionServiceElement::TElSAMLArtifactResolutionServiceElement() : TElSAMLIndexedEndpointType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLArtifactResolutionServiceElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLARTIFACTRESOLUTIONSERVICEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSINGLELOGOUTSERVICEELEMENT

TElSAMLSingleLogoutServiceElement::TElSAMLSingleLogoutServiceElement(TElSAMLSingleLogoutServiceElementHandle handle, TElOwnHandle ownHandle) : TElSAMLEndpointType(handle, ownHandle)
{
}

TElSAMLSingleLogoutServiceElement::TElSAMLSingleLogoutServiceElement() : TElSAMLEndpointType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLSingleLogoutServiceElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLSINGLELOGOUTSERVICEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLMANAGENAMEIDSERVICEELEMENT

TElSAMLManageNameIDServiceElement::TElSAMLManageNameIDServiceElement(TElSAMLManageNameIDServiceElementHandle handle, TElOwnHandle ownHandle) : TElSAMLEndpointType(handle, ownHandle)
{
}

TElSAMLManageNameIDServiceElement::TElSAMLManageNameIDServiceElement() : TElSAMLEndpointType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLManageNameIDServiceElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLMANAGENAMEIDSERVICEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSINGLESIGNONSERVICEELEMENT

TElSAMLSingleSignOnServiceElement::TElSAMLSingleSignOnServiceElement(TElSAMLSingleSignOnServiceElementHandle handle, TElOwnHandle ownHandle) : TElSAMLEndpointType(handle, ownHandle)
{
}

TElSAMLSingleSignOnServiceElement::TElSAMLSingleSignOnServiceElement() : TElSAMLEndpointType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLSingleSignOnServiceElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLSINGLESIGNONSERVICEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLNAMEIDMAPPINGSERVICEELEMENT

TElSAMLNameIDMappingServiceElement::TElSAMLNameIDMappingServiceElement(TElSAMLNameIDMappingServiceElementHandle handle, TElOwnHandle ownHandle) : TElSAMLEndpointType(handle, ownHandle)
{
}

TElSAMLNameIDMappingServiceElement::TElSAMLNameIDMappingServiceElement() : TElSAMLEndpointType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLNameIDMappingServiceElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLNAMEIDMAPPINGSERVICEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSSODESCRIPTORTYPE

SB_INLINE void TElSAMLSSODescriptorType::Clear()
{
	SBCheckError(TElSAMLSSODescriptorType_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLSSODescriptorType::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLSSODescriptorType_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLSSODescriptorType::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLSSODescriptorType_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLSSODescriptorType::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLSSODescriptorType_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLSSODescriptorType::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLSSODescriptorType_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLSSODescriptorType::get_ArtifactResolutionServices()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLSSODescriptorType_get_ArtifactResolutionServices(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ArtifactResolutionServices)
		this->_Inst_ArtifactResolutionServices = new TList(hOutResult, ohFalse);
	else
		this->_Inst_ArtifactResolutionServices->updateHandle(hOutResult);
	return this->_Inst_ArtifactResolutionServices;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLSSODescriptorType::get_SingleLogoutServices()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLSSODescriptorType_get_SingleLogoutServices(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SingleLogoutServices)
		this->_Inst_SingleLogoutServices = new TList(hOutResult, ohFalse);
	else
		this->_Inst_SingleLogoutServices->updateHandle(hOutResult);
	return this->_Inst_SingleLogoutServices;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLSSODescriptorType::get_ManageNameIDService()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLSSODescriptorType_get_ManageNameIDService(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ManageNameIDService)
		this->_Inst_ManageNameIDService = new TList(hOutResult, ohFalse);
	else
		this->_Inst_ManageNameIDService->updateHandle(hOutResult);
	return this->_Inst_ManageNameIDService;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSAMLSSODescriptorType::get_NameIDFormats()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLSSODescriptorType_get_NameIDFormats(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NameIDFormats)
		this->_Inst_NameIDFormats = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_NameIDFormats->updateHandle(hOutResult);
	return this->_Inst_NameIDFormats;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSAMLSSODescriptorType::get_NameIDFormats()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLSSODescriptorType_get_NameIDFormats(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NameIDFormats)
		this->_Inst_NameIDFormats = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_NameIDFormats->updateHandle(hOutResult);
	return this->_Inst_NameIDFormats;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

bool TElSAMLSSODescriptorType::get_AutoAssignIndexes()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLSSODescriptorType_get_AutoAssignIndexes(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLSSODescriptorType::set_AutoAssignIndexes(bool Value)
{
	SBCheckError(TElSAMLSSODescriptorType_set_AutoAssignIndexes(_Handle, (int8_t)Value));
}

void TElSAMLSSODescriptorType::initInstances()
{
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_ArtifactResolutionServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_SingleLogoutServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_ManageNameIDService = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_NameIDFormats = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_NameIDFormats = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElSAMLSSODescriptorType::TElSAMLSSODescriptorType(TElSAMLSSODescriptorTypeHandle handle, TElOwnHandle ownHandle) : TElSAMLRoleDescriptorElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLSSODescriptorType::TElSAMLSSODescriptorType() : TElSAMLRoleDescriptorElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLSSODescriptorType_Create(&_Handle));
}

TElSAMLSSODescriptorType::~TElSAMLSSODescriptorType()
{
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_ArtifactResolutionServices;
	this->_Inst_ArtifactResolutionServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_SingleLogoutServices;
	this->_Inst_SingleLogoutServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_ManageNameIDService;
	this->_Inst_ManageNameIDService = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_NameIDFormats;
	this->_Inst_NameIDFormats = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_NameIDFormats;
	this->_Inst_NameIDFormats = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELSAMLSSODESCRIPTORTYPE */

#ifdef SB_USE_CLASS_TELSAMLIDPSSODESCRIPTORELEMENT

SB_INLINE void TElSAMLIDPSSODescriptorElement::Clear()
{
	SBCheckError(TElSAMLIDPSSODescriptorElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLIDPSSODescriptorElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLIDPSSODescriptorElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLIDPSSODescriptorElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLIDPSSODescriptorElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLIDPSSODescriptorElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLIDPSSODescriptorElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLIDPSSODescriptorElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLIDPSSODescriptorElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

bool TElSAMLIDPSSODescriptorElement::get_WantAuthnRequestsSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLIDPSSODescriptorElement_get_WantAuthnRequestsSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLIDPSSODescriptorElement::set_WantAuthnRequestsSigned(bool Value)
{
	SBCheckError(TElSAMLIDPSSODescriptorElement_set_WantAuthnRequestsSigned(_Handle, (int8_t)Value));
}

bool TElSAMLIDPSSODescriptorElement::get_UseWantAuthnRequestsSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLIDPSSODescriptorElement_get_UseWantAuthnRequestsSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLIDPSSODescriptorElement::set_UseWantAuthnRequestsSigned(bool Value)
{
	SBCheckError(TElSAMLIDPSSODescriptorElement_set_UseWantAuthnRequestsSigned(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLIDPSSODescriptorElement::get_SingleSignOnServices()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIDPSSODescriptorElement_get_SingleSignOnServices(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SingleSignOnServices)
		this->_Inst_SingleSignOnServices = new TList(hOutResult, ohFalse);
	else
		this->_Inst_SingleSignOnServices->updateHandle(hOutResult);
	return this->_Inst_SingleSignOnServices;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLIDPSSODescriptorElement::get_NameIDMappingServices()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIDPSSODescriptorElement_get_NameIDMappingServices(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NameIDMappingServices)
		this->_Inst_NameIDMappingServices = new TList(hOutResult, ohFalse);
	else
		this->_Inst_NameIDMappingServices->updateHandle(hOutResult);
	return this->_Inst_NameIDMappingServices;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLIDPSSODescriptorElement::get_AssertionIDRequestServices()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIDPSSODescriptorElement_get_AssertionIDRequestServices(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AssertionIDRequestServices)
		this->_Inst_AssertionIDRequestServices = new TList(hOutResult, ohFalse);
	else
		this->_Inst_AssertionIDRequestServices->updateHandle(hOutResult);
	return this->_Inst_AssertionIDRequestServices;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSAMLIDPSSODescriptorElement::get_AttributeProfiles()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIDPSSODescriptorElement_get_AttributeProfiles(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AttributeProfiles)
		this->_Inst_AttributeProfiles = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_AttributeProfiles->updateHandle(hOutResult);
	return this->_Inst_AttributeProfiles;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSAMLIDPSSODescriptorElement::get_AttributeProfiles()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIDPSSODescriptorElement_get_AttributeProfiles(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AttributeProfiles)
		this->_Inst_AttributeProfiles = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_AttributeProfiles->updateHandle(hOutResult);
	return this->_Inst_AttributeProfiles;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLIDPSSODescriptorElement::get_Attributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIDPSSODescriptorElement_get_Attributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Attributes)
		this->_Inst_Attributes = new TList(hOutResult, ohFalse);
	else
		this->_Inst_Attributes->updateHandle(hOutResult);
	return this->_Inst_Attributes;
}
#endif /* SB_USE_CLASS_TLIST */

void TElSAMLIDPSSODescriptorElement::initInstances()
{
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_SingleSignOnServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_NameIDMappingServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_AssertionIDRequestServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_AttributeProfiles = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_AttributeProfiles = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TLIST */
}

TElSAMLIDPSSODescriptorElement::TElSAMLIDPSSODescriptorElement(TElSAMLIDPSSODescriptorElementHandle handle, TElOwnHandle ownHandle) : TElSAMLSSODescriptorType(handle, ownHandle)
{
	initInstances();
}

TElSAMLIDPSSODescriptorElement::TElSAMLIDPSSODescriptorElement() : TElSAMLSSODescriptorType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLIDPSSODescriptorElement_Create(&_Handle));
}

TElSAMLIDPSSODescriptorElement::~TElSAMLIDPSSODescriptorElement()
{
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_SingleSignOnServices;
	this->_Inst_SingleSignOnServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_NameIDMappingServices;
	this->_Inst_NameIDMappingServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_AssertionIDRequestServices;
	this->_Inst_AssertionIDRequestServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_AttributeProfiles;
	this->_Inst_AttributeProfiles = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_AttributeProfiles;
	this->_Inst_AttributeProfiles = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_Attributes;
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TLIST */
}
#endif /* SB_USE_CLASS_TELSAMLIDPSSODESCRIPTORELEMENT */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONCONSUMERSERVICEELEMENT

TElSAMLAssertionConsumerServiceElement::TElSAMLAssertionConsumerServiceElement(TElSAMLAssertionConsumerServiceElementHandle handle, TElOwnHandle ownHandle) : TElSAMLIndexedEndpointType(handle, ownHandle)
{
}

TElSAMLAssertionConsumerServiceElement::TElSAMLAssertionConsumerServiceElement() : TElSAMLIndexedEndpointType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLAssertionConsumerServiceElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLASSERTIONCONSUMERSERVICEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLREQUESTEDATTRIBUTEELEMENT

SB_INLINE void TElSAMLRequestedAttributeElement::Clear()
{
	SBCheckError(TElSAMLRequestedAttributeElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLRequestedAttributeElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLRequestedAttributeElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLRequestedAttributeElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLRequestedAttributeElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLRequestedAttributeElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLRequestedAttributeElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLRequestedAttributeElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLRequestedAttributeElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

bool TElSAMLRequestedAttributeElement::get_IsRequired()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLRequestedAttributeElement_get_IsRequired(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLRequestedAttributeElement::set_IsRequired(bool Value)
{
	SBCheckError(TElSAMLRequestedAttributeElement_set_IsRequired(_Handle, (int8_t)Value));
}

bool TElSAMLRequestedAttributeElement::get_UseIsRequired()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLRequestedAttributeElement_get_UseIsRequired(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLRequestedAttributeElement::set_UseIsRequired(bool Value)
{
	SBCheckError(TElSAMLRequestedAttributeElement_set_UseIsRequired(_Handle, (int8_t)Value));
}

TElSAMLRequestedAttributeElement::TElSAMLRequestedAttributeElement(TElSAMLRequestedAttributeElementHandle handle, TElOwnHandle ownHandle) : TElSAMLAttributeType(handle, ownHandle)
{
}

TElSAMLRequestedAttributeElement::TElSAMLRequestedAttributeElement() : TElSAMLAttributeType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLRequestedAttributeElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLREQUESTEDATTRIBUTEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSERVICENAMEELEMENT

TElSAMLServiceNameElement::TElSAMLServiceNameElement(TElSAMLServiceNameElementHandle handle, TElOwnHandle ownHandle) : TElSAMLLocalizedNameType(handle, ownHandle)
{
}

TElSAMLServiceNameElement::TElSAMLServiceNameElement() : TElSAMLLocalizedNameType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLServiceNameElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLSERVICENAMEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSERVICEDESCRIPTIONELEMENT

TElSAMLServiceDescriptionElement::TElSAMLServiceDescriptionElement(TElSAMLServiceDescriptionElementHandle handle, TElOwnHandle ownHandle) : TElSAMLLocalizedNameType(handle, ownHandle)
{
}

TElSAMLServiceDescriptionElement::TElSAMLServiceDescriptionElement() : TElSAMLLocalizedNameType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLServiceDescriptionElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLSERVICEDESCRIPTIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTECONSUMINGSERVICEELEMENT

SB_INLINE void TElSAMLAttributeConsumingServiceElement::Clear()
{
	SBCheckError(TElSAMLAttributeConsumingServiceElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLAttributeConsumingServiceElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLAttributeConsumingServiceElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLAttributeConsumingServiceElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLAttributeConsumingServiceElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLAttributeConsumingServiceElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAttributeConsumingServiceElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLAttributeConsumingServiceElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLAttributeConsumingServiceElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int32_t TElSAMLAttributeConsumingServiceElement::get_Index()
{
	int32_t OutResult;
	SBCheckError(TElSAMLAttributeConsumingServiceElement_get_Index(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLAttributeConsumingServiceElement::set_Index(int32_t Value)
{
	SBCheckError(TElSAMLAttributeConsumingServiceElement_set_Index(_Handle, Value));
}

bool TElSAMLAttributeConsumingServiceElement::get_IsDefault()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLAttributeConsumingServiceElement_get_IsDefault(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLAttributeConsumingServiceElement::set_IsDefault(bool Value)
{
	SBCheckError(TElSAMLAttributeConsumingServiceElement_set_IsDefault(_Handle, (int8_t)Value));
}

bool TElSAMLAttributeConsumingServiceElement::get_UseIsDefault()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLAttributeConsumingServiceElement_get_UseIsDefault(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLAttributeConsumingServiceElement::set_UseIsDefault(bool Value)
{
	SBCheckError(TElSAMLAttributeConsumingServiceElement_set_UseIsDefault(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLAttributeConsumingServiceElement::get_ServiceNames()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAttributeConsumingServiceElement_get_ServiceNames(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ServiceNames)
		this->_Inst_ServiceNames = new TList(hOutResult, ohFalse);
	else
		this->_Inst_ServiceNames->updateHandle(hOutResult);
	return this->_Inst_ServiceNames;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLAttributeConsumingServiceElement::get_ServiceDescriptions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAttributeConsumingServiceElement_get_ServiceDescriptions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ServiceDescriptions)
		this->_Inst_ServiceDescriptions = new TList(hOutResult, ohFalse);
	else
		this->_Inst_ServiceDescriptions->updateHandle(hOutResult);
	return this->_Inst_ServiceDescriptions;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLAttributeConsumingServiceElement::get_RequestedAttributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAttributeConsumingServiceElement_get_RequestedAttributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RequestedAttributes)
		this->_Inst_RequestedAttributes = new TList(hOutResult, ohFalse);
	else
		this->_Inst_RequestedAttributes->updateHandle(hOutResult);
	return this->_Inst_RequestedAttributes;
}
#endif /* SB_USE_CLASS_TLIST */

void TElSAMLAttributeConsumingServiceElement::initInstances()
{
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_ServiceNames = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_ServiceDescriptions = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_RequestedAttributes = NULL;
#endif /* SB_USE_CLASS_TLIST */
}

TElSAMLAttributeConsumingServiceElement::TElSAMLAttributeConsumingServiceElement(TElSAMLAttributeConsumingServiceElementHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
	initInstances();
}

TElSAMLAttributeConsumingServiceElement::TElSAMLAttributeConsumingServiceElement() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLAttributeConsumingServiceElement_Create(&_Handle));
}

TElSAMLAttributeConsumingServiceElement::~TElSAMLAttributeConsumingServiceElement()
{
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_ServiceNames;
	this->_Inst_ServiceNames = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_ServiceDescriptions;
	this->_Inst_ServiceDescriptions = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_RequestedAttributes;
	this->_Inst_RequestedAttributes = NULL;
#endif /* SB_USE_CLASS_TLIST */
}
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTECONSUMINGSERVICEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSPSSODESCRIPTORELEMENT

SB_INLINE void TElSAMLSPSSODescriptorElement::Clear()
{
	SBCheckError(TElSAMLSPSSODescriptorElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLSPSSODescriptorElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLSPSSODescriptorElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLSPSSODescriptorElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLSPSSODescriptorElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLSPSSODescriptorElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLSPSSODescriptorElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLSPSSODescriptorElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLSPSSODescriptorElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

bool TElSAMLSPSSODescriptorElement::get_AuthnRequestsSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLSPSSODescriptorElement_get_AuthnRequestsSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLSPSSODescriptorElement::set_AuthnRequestsSigned(bool Value)
{
	SBCheckError(TElSAMLSPSSODescriptorElement_set_AuthnRequestsSigned(_Handle, (int8_t)Value));
}

bool TElSAMLSPSSODescriptorElement::get_UseAuthnRequestsSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLSPSSODescriptorElement_get_UseAuthnRequestsSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLSPSSODescriptorElement::set_UseAuthnRequestsSigned(bool Value)
{
	SBCheckError(TElSAMLSPSSODescriptorElement_set_UseAuthnRequestsSigned(_Handle, (int8_t)Value));
}

bool TElSAMLSPSSODescriptorElement::get_WantAssertionsSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLSPSSODescriptorElement_get_WantAssertionsSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLSPSSODescriptorElement::set_WantAssertionsSigned(bool Value)
{
	SBCheckError(TElSAMLSPSSODescriptorElement_set_WantAssertionsSigned(_Handle, (int8_t)Value));
}

bool TElSAMLSPSSODescriptorElement::get_UseWantAssertionsSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLSPSSODescriptorElement_get_UseWantAssertionsSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLSPSSODescriptorElement::set_UseWantAssertionsSigned(bool Value)
{
	SBCheckError(TElSAMLSPSSODescriptorElement_set_UseWantAssertionsSigned(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLSPSSODescriptorElement::get_AssertionConsumerServices()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLSPSSODescriptorElement_get_AssertionConsumerServices(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AssertionConsumerServices)
		this->_Inst_AssertionConsumerServices = new TList(hOutResult, ohFalse);
	else
		this->_Inst_AssertionConsumerServices->updateHandle(hOutResult);
	return this->_Inst_AssertionConsumerServices;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
TList* TElSAMLSPSSODescriptorElement::get_AttributeConsumingServices()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLSPSSODescriptorElement_get_AttributeConsumingServices(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AttributeConsumingServices)
		this->_Inst_AttributeConsumingServices = new TList(hOutResult, ohFalse);
	else
		this->_Inst_AttributeConsumingServices->updateHandle(hOutResult);
	return this->_Inst_AttributeConsumingServices;
}
#endif /* SB_USE_CLASS_TLIST */

void TElSAMLSPSSODescriptorElement::initInstances()
{
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_AssertionConsumerServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_AttributeConsumingServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
}

TElSAMLSPSSODescriptorElement::TElSAMLSPSSODescriptorElement(TElSAMLSPSSODescriptorElementHandle handle, TElOwnHandle ownHandle) : TElSAMLSSODescriptorType(handle, ownHandle)
{
	initInstances();
}

TElSAMLSPSSODescriptorElement::TElSAMLSPSSODescriptorElement() : TElSAMLSSODescriptorType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLSPSSODescriptorElement_Create(&_Handle));
}

TElSAMLSPSSODescriptorElement::~TElSAMLSPSSODescriptorElement()
{
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_AssertionConsumerServices;
	this->_Inst_AssertionConsumerServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_AttributeConsumingServices;
	this->_Inst_AttributeConsumingServices = NULL;
#endif /* SB_USE_CLASS_TLIST */
}
#endif /* SB_USE_CLASS_TELSAMLSPSSODESCRIPTORELEMENT */

#ifdef SB_USE_CLASS_TELSAMLENCRYPTIONMETHODTYPE

SB_INLINE void TElSAMLEncryptionMethodType::Clear()
{
	SBCheckError(TElSAMLEncryptionMethodType_Clear(_Handle));
}

bool TElSAMLEncryptionMethodType::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLEncryptionMethodType_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElSAMLEncryptionMethodType::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElSAMLEncryptionMethodType_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElSAMLEncryptionMethodType::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElSAMLEncryptionMethodType_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElSAMLEncryptionMethodType::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLEncryptionMethodType_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElSAMLEncryptionMethodType::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElSAMLEncryptionMethodType_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElSAMLEncryptionMethodType::get_Algorithm(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLEncryptionMethodType_get_Algorithm(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1147186348, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElSAMLEncryptionMethodType::get_Algorithm(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElSAMLEncryptionMethodType_get_Algorithm(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1147186348, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElSAMLEncryptionMethodType::set_Algorithm(const sb_u16string &Value)
{
	SBCheckError(TElSAMLEncryptionMethodType_set_Algorithm(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElSAMLEncryptionMethodType::set_Algorithm(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElSAMLEncryptionMethodType_set_Algorithm(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE int32_t TElSAMLEncryptionMethodType::get_KeySize()
{
	int32_t OutResult;
	SBCheckError(TElSAMLEncryptionMethodType_get_KeySize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLEncryptionMethodType::set_KeySize(int32_t Value)
{
	SBCheckError(TElSAMLEncryptionMethodType_set_KeySize(_Handle, Value));
}

void TElSAMLEncryptionMethodType::get_OAEPparams(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSAMLEncryptionMethodType_get_OAEPparams(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2059157878, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLEncryptionMethodType::set_OAEPparams(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSAMLEncryptionMethodType_set_OAEPparams(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElSAMLEncryptionMethodType::get_DigestMethod(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLEncryptionMethodType_get_DigestMethod(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(878733497, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElSAMLEncryptionMethodType::get_DigestMethod(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElSAMLEncryptionMethodType_get_DigestMethod(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(878733497, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElSAMLEncryptionMethodType::set_DigestMethod(const sb_u16string &Value)
{
	SBCheckError(TElSAMLEncryptionMethodType_set_DigestMethod(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElSAMLEncryptionMethodType::set_DigestMethod(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElSAMLEncryptionMethodType_set_DigestMethod(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElSAMLEncryptionMethodType::TElSAMLEncryptionMethodType(TElSAMLEncryptionMethodTypeHandle handle, TElOwnHandle ownHandle) : TElSAMLElement(handle, ownHandle)
{
}

TElSAMLEncryptionMethodType::TElSAMLEncryptionMethodType() : TElSAMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLEncryptionMethodType_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLENCRYPTIONMETHODTYPE */

#ifdef SB_USE_CLASS_TELSAMLMETADATA

SB_INLINE void TElSAMLMetadata::Clear()
{
	SBCheckError(TElSAMLMetadata_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSAMLMetadata::LoadFromStream(TStream &Strm)
{
	SBCheckError(TElSAMLMetadata_LoadFromStream(_Handle, Strm.getHandle()));
}

SB_INLINE void TElSAMLMetadata::LoadFromStream(TStream *Strm)
{
	SBCheckError(TElSAMLMetadata_LoadFromStream(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSAMLMetadata::SaveToStream(TStream &Strm)
{
	SBCheckError(TElSAMLMetadata_SaveToStream(_Handle, Strm.getHandle()));
}

SB_INLINE void TElSAMLMetadata::SaveToStream(TStream *Strm)
{
	SBCheckError(TElSAMLMetadata_SaveToStream(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELSAMLSECURITYHANDLER
TElSAMLSecurityHandler* TElSAMLMetadata::get_Handler()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLMetadata_get_Handler(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Handler)
		this->_Inst_Handler = new TElSAMLSecurityHandler(hOutResult, ohFalse);
	else
		this->_Inst_Handler->updateHandle(hOutResult);
	return this->_Inst_Handler;
}

SB_INLINE void TElSAMLMetadata::set_Handler(TElSAMLSecurityHandler &Value)
{
	SBCheckError(TElSAMLMetadata_set_Handler(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLMetadata::set_Handler(TElSAMLSecurityHandler *Value)
{
	SBCheckError(TElSAMLMetadata_set_Handler(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLSECURITYHANDLER */

bool TElSAMLMetadata::get_Loaded()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLMetadata_get_Loaded(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELSAMLMETADATAROOTELEMENT
TElSAMLMetadataRootElement* TElSAMLMetadata::get_RootElement()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLMetadata_get_RootElement(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RootElement)
		this->_Inst_RootElement = new TElSAMLMetadataRootElement(hOutResult, ohFalse);
	else
		this->_Inst_RootElement->updateHandle(hOutResult);
	return this->_Inst_RootElement;
}

SB_INLINE void TElSAMLMetadata::set_RootElement(TElSAMLMetadataRootElement &Value)
{
	SBCheckError(TElSAMLMetadata_set_RootElement(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLMetadata::set_RootElement(TElSAMLMetadataRootElement *Value)
{
	SBCheckError(TElSAMLMetadata_set_RootElement(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLMETADATAROOTELEMENT */

void TElSAMLMetadata::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLSECURITYHANDLER
	this->_Inst_Handler = NULL;
#endif /* SB_USE_CLASS_TELSAMLSECURITYHANDLER */
#ifdef SB_USE_CLASS_TELSAMLMETADATAROOTELEMENT
	this->_Inst_RootElement = NULL;
#endif /* SB_USE_CLASS_TELSAMLMETADATAROOTELEMENT */
}

TElSAMLMetadata::TElSAMLMetadata(TElSAMLMetadataHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElSAMLMetadata::TElSAMLMetadata() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLMetadata_Create(&_Handle));
}

TElSAMLMetadata::TElSAMLMetadata(bool OwnHandler) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLMetadata_Create_1((int8_t)OwnHandler, &_Handle));
}

TElSAMLMetadata::~TElSAMLMetadata()
{
#ifdef SB_USE_CLASS_TELSAMLSECURITYHANDLER
	delete this->_Inst_Handler;
	this->_Inst_Handler = NULL;
#endif /* SB_USE_CLASS_TELSAMLSECURITYHANDLER */
#ifdef SB_USE_CLASS_TELSAMLMETADATAROOTELEMENT
	delete this->_Inst_RootElement;
	this->_Inst_RootElement = NULL;
#endif /* SB_USE_CLASS_TELSAMLMETADATAROOTELEMENT */
}
#endif /* SB_USE_CLASS_TELSAMLMETADATA */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT

TSBSAMLBindingType TElSAMLEndpoint::get_Binding()
{
	TSBSAMLBindingTypeRaw OutResultRaw = 0;
	SBCheckError(TElSAMLEndpoint_get_Binding(_Handle, &OutResultRaw));
	return (TSBSAMLBindingType)OutResultRaw;
}

SB_INLINE void TElSAMLEndpoint::set_Binding(TSBSAMLBindingType Value)
{
	SBCheckError(TElSAMLEndpoint_set_Binding(_Handle, (TSBSAMLBindingTypeRaw)Value));
}

void TElSAMLEndpoint::get_Location(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLEndpoint_get_Location(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-679681551, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLEndpoint::set_Location(const std::string &Value)
{
	SBCheckError(TElSAMLEndpoint_set_Location(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSAMLEndpoint::get__Index()
{
	int32_t OutResult;
	SBCheckError(TElSAMLEndpoint_get__Index(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLEndpoint::set__Index(int32_t Value)
{
	SBCheckError(TElSAMLEndpoint_set__Index(_Handle, Value));
}

bool TElSAMLEndpoint::get_IsDefault()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLEndpoint_get_IsDefault(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLEndpoint::set_IsDefault(bool Value)
{
	SBCheckError(TElSAMLEndpoint_set_IsDefault(_Handle, (int8_t)Value));
}

TElSAMLEndpoint::TElSAMLEndpoint(TElSAMLEndpointHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSAMLEndpoint::TElSAMLEndpoint() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLEndpoint_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_GLOBAL_PROCS_XMLSAMLMETADATA

void ContactTypeToStr(TSBSAMLContactType T, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLSAMLMetadata_ContactTypeToStr((TSBSAMLContactTypeRaw)T, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1052130470, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBSAMLContactType StrToContactType(const std::string &S)
{
	TSBSAMLContactTypeRaw OutResultRaw = 0;
	SBCheckError(SBXMLSAMLMetadata_StrToContactType(S.data(), (int32_t)S.length(), &OutResultRaw));
	return (TSBSAMLContactType)OutResultRaw;
}

void KeyUsageToStr(TSBSAMLKeyUse U, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLSAMLMetadata_KeyUsageToStr((TSBSAMLKeyUseRaw)U, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1994162178, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBSAMLKeyUse StrToKeyUsage(const std::string &S)
{
	TSBSAMLKeyUseRaw OutResultRaw = 0;
	SBCheckError(SBXMLSAMLMetadata_StrToKeyUsage(S.data(), (int32_t)S.length(), &OutResultRaw));
	return (TSBSAMLKeyUse)OutResultRaw;
}

#endif /* SB_USE_GLOBAL_PROCS_XMLSAMLMETADATA */

};	/* namespace SecureBlackbox */
