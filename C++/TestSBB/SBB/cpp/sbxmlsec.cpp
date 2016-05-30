#include "sbxmlsec.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELXMLKEYINFO

#ifdef SB_USE_CLASS_TELXMLKEYINFOITEM
SB_INLINE int32_t TElXMLKeyInfo::Add(TElXMLKeyInfoItem &Item)
{
	int32_t OutResult;
	SBCheckError(TElXMLKeyInfo_Add(_Handle, Item.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLKeyInfo::Add(TElXMLKeyInfoItem *Item)
{
	int32_t OutResult;
	SBCheckError(TElXMLKeyInfo_Add(_Handle, (Item != NULL) ? Item->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLKEYINFOITEM */

#ifdef SB_USE_CLASS_TELXMLKEYINFOITEM
SB_INLINE void TElXMLKeyInfo::Insert(int32_t Index, TElXMLKeyInfoItem &Item)
{
	SBCheckError(TElXMLKeyInfo_Insert(_Handle, Index, Item.getHandle()));
}

SB_INLINE void TElXMLKeyInfo::Insert(int32_t Index, TElXMLKeyInfoItem *Item)
{
	SBCheckError(TElXMLKeyInfo_Insert(_Handle, Index, (Item != NULL) ? Item->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLKEYINFOITEM */

SB_INLINE void TElXMLKeyInfo::Delete(int32_t Index)
{
	SBCheckError(TElXMLKeyInfo_Delete(_Handle, Index));
}

SB_INLINE void TElXMLKeyInfo::Clear()
{
	SBCheckError(TElXMLKeyInfo_Clear(_Handle));
}

bool TElXMLKeyInfo::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLKeyInfo_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLKeyInfo::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLKeyInfo_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLKeyInfo::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLKeyInfo_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLKeyInfo::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLKeyInfo_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLKeyInfo::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLKeyInfo_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElXMLKeyInfo::ExtractAllCertificates(TElCustomCertStorage &Storage)
{
	SBCheckError(TElXMLKeyInfo_ExtractAllCertificates(_Handle, Storage.getHandle()));
}

SB_INLINE void TElXMLKeyInfo::ExtractAllCertificates(TElCustomCertStorage *Storage)
{
	SBCheckError(TElXMLKeyInfo_ExtractAllCertificates(_Handle, (Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
SB_INLINE void TElXMLKeyInfo::SetKeyData(const TElXMLKeyInfoData &KeyData)
{
	SBCheckError(TElXMLKeyInfo_SetKeyData(_Handle, KeyData.getHandle()));
}

SB_INLINE void TElXMLKeyInfo::SetKeyData(const TElXMLKeyInfoData *KeyData)
{
	SBCheckError(TElXMLKeyInfo_SetKeyData(_Handle, (KeyData != NULL) ? KeyData->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

SB_INLINE int32_t TElXMLKeyInfo::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLKeyInfo_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLKEYINFOITEM
TElXMLKeyInfoItem* TElXMLKeyInfo::get_Items(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLKeyInfo_get_Items(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Items)
		this->_Inst_Items = new TElXMLKeyInfoItem(hOutResult, ohFalse);
	else
		this->_Inst_Items->updateHandle(hOutResult);
	return this->_Inst_Items;
}
#endif /* SB_USE_CLASS_TELXMLKEYINFOITEM */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElXMLKeyInfo::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLKeyInfo_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElXMLKeyInfo::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElXMLKeyInfo_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLKeyInfo::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElXMLKeyInfo_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

void TElXMLKeyInfo::get_KeyName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLKeyInfo_get_KeyName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-825535084, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLKeyInfo::get_KeyName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLKeyInfo_get_KeyName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-825535084, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLKeyInfo::set_KeyName(const sb_u16string &Value)
{
	SBCheckError(TElXMLKeyInfo_set_KeyName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLKeyInfo::set_KeyName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLKeyInfo_set_KeyName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLKeyInfo::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLKeyInfo_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1757004984, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLKeyInfo::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLKeyInfo_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1757004984, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLKeyInfo::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLKeyInfo_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLKeyInfo::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLKeyInfo_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLKeyInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLKEYINFOITEM
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFOITEM */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}

TElXMLKeyInfo::TElXMLKeyInfo(TElXMLKeyInfoHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
	initInstances();
}

TElXMLKeyInfo::TElXMLKeyInfo() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfo_Create(&_Handle));
}

TElXMLKeyInfo::TElXMLKeyInfo(const sb_u16string &AKeyName) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfo_Create_1(AKeyName.data(), (int32_t)AKeyName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLKeyInfo::TElXMLKeyInfo(const std::wstring &AKeyName) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AKeyName;
	sb_to_u16string(AKeyName, u16AKeyName);
	SBCheckError(TElXMLKeyInfo_Create_1(reinterpret_cast<const sb_char16_t*>(u16AKeyName.data()), (int32_t)u16AKeyName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLKeyInfo::~TElXMLKeyInfo()
{
#ifdef SB_USE_CLASS_TELXMLKEYINFOITEM
	delete this->_Inst_Items;
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFOITEM */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}
#endif /* SB_USE_CLASS_TELXMLKEYINFO */

#ifdef SB_USE_CLASS_TELXMLALGORITHMPARAMETERS

SB_INLINE TElXMLAlgorithmParametersHandle TElXMLAlgorithmParameters::Clone()
{
	TElXMLAlgorithmParametersHandle OutResult;
	SBCheckError(TElXMLAlgorithmParameters_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElRelativeDistinguishedNameHandle TElXMLAlgorithmParameters::GetCryptoProviderParameters()
{
	TElRelativeDistinguishedNameHandle OutResult;
	SBCheckError(TElXMLAlgorithmParameters_GetCryptoProviderParameters(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

TElXMLAlgorithmParameters::TElXMLAlgorithmParameters(TElXMLAlgorithmParametersHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
}

TElXMLAlgorithmParameters::TElXMLAlgorithmParameters() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLAlgorithmParameters_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLALGORITHMPARAMETERS */

#ifdef SB_USE_CLASS_TELXMLREFERENCE

SB_INLINE void TElXMLReference::UpdateDigestValue(int32_t Mode)
{
	SBCheckError(TElXMLReference_UpdateDigestValue(_Handle, Mode));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
SB_INLINE void TElXMLReference::UpdateDigestValue(int32_t Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov)
{
	SBCheckError(TElXMLReference_UpdateDigestValue_1(_Handle, Mode, Manager.getHandle(), Prov.getHandle()));
}

SB_INLINE void TElXMLReference::UpdateDigestValue(int32_t Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov)
{
	SBCheckError(TElXMLReference_UpdateDigestValue_1(_Handle, Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

SB_INLINE void TElXMLReference::UpdateDigestValue()
{
	SBCheckError(TElXMLReference_UpdateDigestValue_2(_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
SB_INLINE void TElXMLReference::UpdateDigestValue(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov)
{
	SBCheckError(TElXMLReference_UpdateDigestValue_3(_Handle, Manager.getHandle(), Prov.getHandle()));
}

SB_INLINE void TElXMLReference::UpdateDigestValue(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov)
{
	SBCheckError(TElXMLReference_UpdateDigestValue_3(_Handle, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

SB_INLINE TElXMLReferenceHandle TElXMLReference::Clone()
{
	TElXMLReferenceHandle OutResult;
	SBCheckError(TElXMLReference_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLReference::Clear()
{
	SBCheckError(TElXMLReference_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLReference::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLReference_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLReference::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLReference_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLReference::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLReference_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLReference::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLReference_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

bool TElXMLReference::IsURIResolved()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLReference_IsURIResolved(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELHASHFUNCTION
SB_INLINE void TElXMLReference::ProcessData(TElHashFunction &HashFunc)
{
	SBCheckError(TElXMLReference_ProcessData(_Handle, HashFunc.getHandle()));
}

SB_INLINE void TElXMLReference::ProcessData(TElHashFunction *HashFunc)
{
	SBCheckError(TElXMLReference_ProcessData(_Handle, (HashFunc != NULL) ? HashFunc->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHASHFUNCTION */

#ifdef SB_USE_CLASS_TELHASHFUNCTION
SB_INLINE void TElXMLReference::ProcessData(TElHashFunction &HashFunc, TElXMLCanonicalizationMethod CanonicalizationMethod)
{
	SBCheckError(TElXMLReference_ProcessData_1(_Handle, HashFunc.getHandle(), (TElXMLCanonicalizationMethodRaw)CanonicalizationMethod));
}

SB_INLINE void TElXMLReference::ProcessData(TElHashFunction *HashFunc, TElXMLCanonicalizationMethod CanonicalizationMethod)
{
	SBCheckError(TElXMLReference_ProcessData_1(_Handle, (HashFunc != NULL) ? HashFunc->getHandle() : SB_NULL_HANDLE, (TElXMLCanonicalizationMethodRaw)CanonicalizationMethod));
}
#endif /* SB_USE_CLASS_TELHASHFUNCTION */

#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
TElXMLTransformChain* TElXMLReference::get_TransformChain()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLReference_get_TransformChain(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TransformChain)
		this->_Inst_TransformChain = new TElXMLTransformChain(hOutResult, ohFalse);
	else
		this->_Inst_TransformChain->updateHandle(hOutResult);
	return this->_Inst_TransformChain;
}
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */

TElXMLDigestMethod TElXMLReference::get_DigestMethod()
{
	TElXMLDigestMethodRaw OutResultRaw = 0;
	SBCheckError(TElXMLReference_get_DigestMethod(_Handle, &OutResultRaw));
	return (TElXMLDigestMethod)OutResultRaw;
}

SB_INLINE void TElXMLReference::set_DigestMethod(TElXMLDigestMethod Value)
{
	SBCheckError(TElXMLReference_set_DigestMethod(_Handle, (TElXMLDigestMethodRaw)Value));
}

void TElXMLReference::get_DigestValue(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLReference_get_DigestValue(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-122015954, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElXMLReference::set_DigestValue(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElXMLReference_set_DigestValue(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELXMLALGORITHMPARAMETERS
TElXMLAlgorithmParameters* TElXMLReference::get_DigestMethodParameters()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLReference_get_DigestMethodParameters(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DigestMethodParameters)
		this->_Inst_DigestMethodParameters = new TElXMLAlgorithmParameters(hOutResult, ohFalse);
	else
		this->_Inst_DigestMethodParameters->updateHandle(hOutResult);
	return this->_Inst_DigestMethodParameters;
}
#endif /* SB_USE_CLASS_TELXMLALGORITHMPARAMETERS */

void TElXMLReference::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLReference_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-360275294, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLReference::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLReference_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-360275294, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLReference::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLReference_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLReference::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLReference_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLReference::get_URI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLReference_get_URI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1050038929, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLReference::get_URI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLReference_get_URI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1050038929, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLReference::set_URI(const sb_u16string &Value)
{
	SBCheckError(TElXMLReference_set_URI(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLReference::set_URI(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLReference_set_URI(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLReference::get_RefType(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLReference_get_RefType(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(509598317, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLReference::get_RefType(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLReference_get_RefType(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(509598317, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLReference::set_RefType(const sb_u16string &Value)
{
	SBCheckError(TElXMLReference_set_RefType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLReference::set_RefType(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLReference_set_RefType(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
bool TElXMLReference::get_HasURI()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLReference_get_HasURI(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLReference::set_HasURI(bool Value)
{
	SBCheckError(TElXMLReference_set_HasURI(_Handle, (int8_t)Value));
}

void TElXMLReference::get_URIData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLReference_get_URIData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1606693015, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElXMLReference::set_URIData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElXMLReference_set_URIData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TElXMLDOMNode* TElXMLReference::get_URINode()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLReference_get_URINode(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_URINode)
		this->_Inst_URINode = new TElXMLDOMNode(hOutResult, ohFalse);
	else
		this->_Inst_URINode->updateHandle(hOutResult);
	return this->_Inst_URINode;
}

SB_INLINE void TElXMLReference::set_URINode(TElXMLDOMNode &Value)
{
	SBCheckError(TElXMLReference_set_URINode(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLReference::set_URINode(TElXMLDOMNode *Value)
{
	SBCheckError(TElXMLReference_set_URINode(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLNODESET
TElXMLNodeSet* TElXMLReference::get_URINodes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLReference_get_URINodes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_URINodes)
		this->_Inst_URINodes = new TElXMLNodeSet(hOutResult, ohFalse);
	else
		this->_Inst_URINodes->updateHandle(hOutResult);
	return this->_Inst_URINodes;
}

SB_INLINE void TElXMLReference::set_URINodes(TElXMLNodeSet &Value)
{
	SBCheckError(TElXMLReference_set_URINodes(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLReference::set_URINodes(TElXMLNodeSet *Value)
{
	SBCheckError(TElXMLReference_set_URINodes(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLNODESET */

#ifdef SB_USE_CLASS_TSTREAM
TStream* TElXMLReference::get_URIStream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLReference_get_URIStream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_URIStream)
		this->_Inst_URIStream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_URIStream->updateHandle(hOutResult);
	return this->_Inst_URIStream;
}

SB_INLINE void TElXMLReference::set_URIStream(TStream &Value)
{
	SBCheckError(TElXMLReference_set_URIStream(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLReference::set_URIStream(TStream *Value)
{
	SBCheckError(TElXMLReference_set_URIStream(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int64_t TElXMLReference::get_URIStreamOffset()
{
	int64_t OutResult;
	SBCheckError(TElXMLReference_get_URIStreamOffset(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLReference::set_URIStreamOffset(int64_t Value)
{
	SBCheckError(TElXMLReference_set_URIStreamOffset(_Handle, Value));
}

SB_INLINE int64_t TElXMLReference::get_URIStreamCount()
{
	int64_t OutResult;
	SBCheckError(TElXMLReference_get_URIStreamCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLReference::set_URIStreamCount(int64_t Value)
{
	SBCheckError(TElXMLReference_set_URIStreamCount(_Handle, Value));
}

void TElXMLReference::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
	this->_Inst_TransformChain = NULL;
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */
#ifdef SB_USE_CLASS_TELXMLALGORITHMPARAMETERS
	this->_Inst_DigestMethodParameters = NULL;
#endif /* SB_USE_CLASS_TELXMLALGORITHMPARAMETERS */
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	this->_Inst_URINode = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
#ifdef SB_USE_CLASS_TELXMLNODESET
	this->_Inst_URINodes = NULL;
#endif /* SB_USE_CLASS_TELXMLNODESET */
#ifdef SB_USE_CLASS_TSTREAM
	this->_Inst_URIStream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
}

TElXMLReference::TElXMLReference(TElXMLReferenceHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
	initInstances();
}

TElXMLReference::TElXMLReference() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLReference_Create(&_Handle));
}

TElXMLReference::~TElXMLReference()
{
#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
	delete this->_Inst_TransformChain;
	this->_Inst_TransformChain = NULL;
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */
#ifdef SB_USE_CLASS_TELXMLALGORITHMPARAMETERS
	delete this->_Inst_DigestMethodParameters;
	this->_Inst_DigestMethodParameters = NULL;
#endif /* SB_USE_CLASS_TELXMLALGORITHMPARAMETERS */
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	delete this->_Inst_URINode;
	this->_Inst_URINode = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
#ifdef SB_USE_CLASS_TELXMLNODESET
	delete this->_Inst_URINodes;
	this->_Inst_URINodes = NULL;
#endif /* SB_USE_CLASS_TELXMLNODESET */
#ifdef SB_USE_CLASS_TSTREAM
	delete this->_Inst_URIStream;
	this->_Inst_URIStream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
}
#endif /* SB_USE_CLASS_TELXMLREFERENCE */

#ifdef SB_USE_CLASS_TELXMLREFERENCELIST

SB_INLINE int32_t TElXMLReferenceList::Add()
{
	int32_t OutResult;
	SBCheckError(TElXMLReferenceList_Add(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLREFERENCE
SB_INLINE int32_t TElXMLReferenceList::Add(TElXMLReference &AReference)
{
	int32_t OutResult;
	SBCheckError(TElXMLReferenceList_Add_1(_Handle, AReference.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLReferenceList::Add(TElXMLReference *AReference)
{
	int32_t OutResult;
	SBCheckError(TElXMLReferenceList_Add_1(_Handle, (AReference != NULL) ? AReference->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLREFERENCE */

#ifdef SB_USE_CLASS_TELXMLREFERENCE
SB_INLINE void TElXMLReferenceList::Insert(int32_t Index, TElXMLReference &AReference)
{
	SBCheckError(TElXMLReferenceList_Insert(_Handle, Index, AReference.getHandle()));
}

SB_INLINE void TElXMLReferenceList::Insert(int32_t Index, TElXMLReference *AReference)
{
	SBCheckError(TElXMLReferenceList_Insert(_Handle, Index, (AReference != NULL) ? AReference->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLREFERENCE */

SB_INLINE void TElXMLReferenceList::Delete(int32_t Index)
{
	SBCheckError(TElXMLReferenceList_Delete(_Handle, Index));
}

SB_INLINE void TElXMLReferenceList::Clear()
{
	SBCheckError(TElXMLReferenceList_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLREFERENCE
SB_INLINE int32_t TElXMLReferenceList::IndexOf(TElXMLReference &AReference)
{
	int32_t OutResult;
	SBCheckError(TElXMLReferenceList_IndexOf(_Handle, AReference.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLReferenceList::IndexOf(TElXMLReference *AReference)
{
	int32_t OutResult;
	SBCheckError(TElXMLReferenceList_IndexOf(_Handle, (AReference != NULL) ? AReference->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLREFERENCE */

SB_INLINE int32_t TElXMLReferenceList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLReferenceList_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLREFERENCE
TElXMLReference* TElXMLReferenceList::get_Reference(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLReferenceList_get_Reference(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Reference)
		this->_Inst_Reference = new TElXMLReference(hOutResult, ohFalse);
	else
		this->_Inst_Reference->updateHandle(hOutResult);
	return this->_Inst_Reference;
}
#endif /* SB_USE_CLASS_TELXMLREFERENCE */

void TElXMLReferenceList::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLREFERENCE
	this->_Inst_Reference = NULL;
#endif /* SB_USE_CLASS_TELXMLREFERENCE */
}

TElXMLReferenceList::TElXMLReferenceList(TElXMLReferenceListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElXMLReferenceList::TElXMLReferenceList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLReferenceList_Create(&_Handle));
}

TElXMLReferenceList::~TElXMLReferenceList()
{
#ifdef SB_USE_CLASS_TELXMLREFERENCE
	delete this->_Inst_Reference;
	this->_Inst_Reference = NULL;
#endif /* SB_USE_CLASS_TELXMLREFERENCE */
}
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */

#ifdef SB_USE_CLASS_TELXMLGOSTR3411PARAMETERS

SB_INLINE void TElXMLGOSTR3411Parameters::Clear()
{
	SBCheckError(TElXMLGOSTR3411Parameters_Clear(_Handle));
}

SB_INLINE TElXMLAlgorithmParametersHandle TElXMLGOSTR3411Parameters::Clone()
{
	TElXMLAlgorithmParametersHandle OutResult;
	SBCheckError(TElXMLGOSTR3411Parameters_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLGOSTR3411Parameters::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLGOSTR3411Parameters_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLGOSTR3411Parameters::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLGOSTR3411Parameters_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLGOSTR3411Parameters::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLGOSTR3411Parameters_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLGOSTR3411Parameters::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLGOSTR3411Parameters_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElRelativeDistinguishedNameHandle TElXMLGOSTR3411Parameters::GetCryptoProviderParameters()
{
	TElRelativeDistinguishedNameHandle OutResult;
	SBCheckError(TElXMLGOSTR3411Parameters_GetCryptoProviderParameters(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

void TElXMLGOSTR3411Parameters::get_DigestParameter(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLGOSTR3411Parameters_get_DigestParameter(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-325513964, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLGOSTR3411Parameters::get_DigestParameter(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLGOSTR3411Parameters_get_DigestParameter(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-325513964, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLGOSTR3411Parameters::set_DigestParameter(const sb_u16string &Value)
{
	SBCheckError(TElXMLGOSTR3411Parameters_set_DigestParameter(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLGOSTR3411Parameters::set_DigestParameter(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLGOSTR3411Parameters_set_DigestParameter(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLGOSTR3411Parameters::TElXMLGOSTR3411Parameters(TElXMLGOSTR3411ParametersHandle handle, TElOwnHandle ownHandle) : TElXMLAlgorithmParameters(handle, ownHandle)
{
}

TElXMLGOSTR3411Parameters::TElXMLGOSTR3411Parameters() : TElXMLAlgorithmParameters(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLGOSTR3411Parameters_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLGOSTR3411PARAMETERS */

#ifdef SB_USE_CLASS_TELXMLRSAPSSPARAMETERS

SB_INLINE void TElXMLRSAPSSParameters::Clear()
{
	SBCheckError(TElXMLRSAPSSParameters_Clear(_Handle));
}

SB_INLINE TElXMLAlgorithmParametersHandle TElXMLRSAPSSParameters::Clone()
{
	TElXMLAlgorithmParametersHandle OutResult;
	SBCheckError(TElXMLRSAPSSParameters_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLRSAPSSParameters::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLRSAPSSParameters_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLRSAPSSParameters::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLRSAPSSParameters_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLRSAPSSParameters::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLRSAPSSParameters_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLRSAPSSParameters::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLRSAPSSParameters_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElRelativeDistinguishedNameHandle TElXMLRSAPSSParameters::GetCryptoProviderParameters()
{
	TElRelativeDistinguishedNameHandle OutResult;
	SBCheckError(TElXMLRSAPSSParameters_GetCryptoProviderParameters(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

TElXMLDigestMethod TElXMLRSAPSSParameters::get_DigestMethod()
{
	TElXMLDigestMethodRaw OutResultRaw = 0;
	SBCheckError(TElXMLRSAPSSParameters_get_DigestMethod(_Handle, &OutResultRaw));
	return (TElXMLDigestMethod)OutResultRaw;
}

SB_INLINE void TElXMLRSAPSSParameters::set_DigestMethod(TElXMLDigestMethod Value)
{
	SBCheckError(TElXMLRSAPSSParameters_set_DigestMethod(_Handle, (TElXMLDigestMethodRaw)Value));
}

SB_INLINE int32_t TElXMLRSAPSSParameters::get_MaskGenerationFunction()
{
	int32_t OutResult;
	SBCheckError(TElXMLRSAPSSParameters_get_MaskGenerationFunction(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLRSAPSSParameters::set_MaskGenerationFunction(int32_t Value)
{
	SBCheckError(TElXMLRSAPSSParameters_set_MaskGenerationFunction(_Handle, Value));
}

SB_INLINE int32_t TElXMLRSAPSSParameters::get_SaltLength()
{
	int32_t OutResult;
	SBCheckError(TElXMLRSAPSSParameters_get_SaltLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLRSAPSSParameters::set_SaltLength(int32_t Value)
{
	SBCheckError(TElXMLRSAPSSParameters_set_SaltLength(_Handle, Value));
}

SB_INLINE int32_t TElXMLRSAPSSParameters::get_TrailerField()
{
	int32_t OutResult;
	SBCheckError(TElXMLRSAPSSParameters_get_TrailerField(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLRSAPSSParameters::set_TrailerField(int32_t Value)
{
	SBCheckError(TElXMLRSAPSSParameters_set_TrailerField(_Handle, Value));
}

TElXMLRSAPSSParameters::TElXMLRSAPSSParameters(TElXMLRSAPSSParametersHandle handle, TElOwnHandle ownHandle) : TElXMLAlgorithmParameters(handle, ownHandle)
{
}

TElXMLRSAPSSParameters::TElXMLRSAPSSParameters() : TElXMLAlgorithmParameters(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLRSAPSSParameters_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLRSAPSSPARAMETERS */

#ifdef SB_USE_CLASS_TELXMLKEYINFOITEM

TElXMLKeyInfoItem::TElXMLKeyInfoItem(TElXMLKeyInfoItemHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElXMLKeyInfoItem::TElXMLKeyInfoItem() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLKeyInfoItem_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLKEYINFOITEM */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA

bool TElXMLKeyInfoData::get_OwnResources()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLKeyInfoData_get_OwnResources(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLKeyInfoData::set_OwnResources(bool Value)
{
	SBCheckError(TElXMLKeyInfoData_set_OwnResources(_Handle, (int8_t)Value));
}

TElXMLKeyInfoData::TElXMLKeyInfoData(TElXMLKeyInfoDataHandle handle, TElOwnHandle ownHandle) : TElXMLKeyInfoItem(handle, ownHandle)
{
}

TElXMLKeyInfoData::TElXMLKeyInfoData() : TElXMLKeyInfoItem(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLKeyInfoData_Create(&_Handle));
}

TElXMLKeyInfoData::TElXMLKeyInfoData(bool AOwnResources) : TElXMLKeyInfoItem(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLKeyInfoData_Create_1((int8_t)AOwnResources, &_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElXMLKeyInfoData::TElXMLKeyInfoData(bool AOwnResources, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElXMLKeyInfoItem(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLKeyInfoData_Create_2((int8_t)AOwnResources, Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElXMLKeyInfoData::TElXMLKeyInfoData(bool AOwnResources, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElXMLKeyInfoItem(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLKeyInfoData_Create_2((int8_t)AOwnResources, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFOHMACDATA

#ifdef SB_USE_CLASS_TELHMACKEYMATERIAL
TElHMACKeyMaterial* TElXMLKeyInfoHMACData::get_Key()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLKeyInfoHMACData_get_Key(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Key)
		this->_Inst_Key = new TElHMACKeyMaterial(hOutResult, ohFalse);
	else
		this->_Inst_Key->updateHandle(hOutResult);
	return this->_Inst_Key;
}

SB_INLINE void TElXMLKeyInfoHMACData::set_Key(TElHMACKeyMaterial &Value)
{
	SBCheckError(TElXMLKeyInfoHMACData_set_Key(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLKeyInfoHMACData::set_Key(TElHMACKeyMaterial *Value)
{
	SBCheckError(TElXMLKeyInfoHMACData_set_Key(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHMACKEYMATERIAL */

void TElXMLKeyInfoHMACData::initInstances()
{
#ifdef SB_USE_CLASS_TELHMACKEYMATERIAL
	this->_Inst_Key = NULL;
#endif /* SB_USE_CLASS_TELHMACKEYMATERIAL */
}

TElXMLKeyInfoHMACData::TElXMLKeyInfoHMACData(TElXMLKeyInfoHMACDataHandle handle, TElOwnHandle ownHandle) : TElXMLKeyInfoData(handle, ownHandle)
{
	initInstances();
}

TElXMLKeyInfoHMACData::TElXMLKeyInfoHMACData(bool OwnResources) : TElXMLKeyInfoData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoHMACData_Create((int8_t)OwnResources, &_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElXMLKeyInfoHMACData::TElXMLKeyInfoHMACData(bool AOwnResources, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElXMLKeyInfoData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoHMACData_Create_1((int8_t)AOwnResources, Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElXMLKeyInfoHMACData::TElXMLKeyInfoHMACData(bool AOwnResources, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElXMLKeyInfoData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoHMACData_Create_1((int8_t)AOwnResources, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

TElXMLKeyInfoHMACData::~TElXMLKeyInfoHMACData()
{
#ifdef SB_USE_CLASS_TELHMACKEYMATERIAL
	delete this->_Inst_Key;
	this->_Inst_Key = NULL;
#endif /* SB_USE_CLASS_TELHMACKEYMATERIAL */
}
#endif /* SB_USE_CLASS_TELXMLKEYINFOHMACDATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFOSYMMETRICDATA

#ifdef SB_USE_CLASS_TELSYMMETRICKEYMATERIAL
TElSymmetricKeyMaterial* TElXMLKeyInfoSymmetricData::get_Key()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLKeyInfoSymmetricData_get_Key(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Key)
		this->_Inst_Key = new TElSymmetricKeyMaterial(hOutResult, ohFalse);
	else
		this->_Inst_Key->updateHandle(hOutResult);
	return this->_Inst_Key;
}

SB_INLINE void TElXMLKeyInfoSymmetricData::set_Key(TElSymmetricKeyMaterial &Value)
{
	SBCheckError(TElXMLKeyInfoSymmetricData_set_Key(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLKeyInfoSymmetricData::set_Key(TElSymmetricKeyMaterial *Value)
{
	SBCheckError(TElXMLKeyInfoSymmetricData_set_Key(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSYMMETRICKEYMATERIAL */

void TElXMLKeyInfoSymmetricData::initInstances()
{
#ifdef SB_USE_CLASS_TELSYMMETRICKEYMATERIAL
	this->_Inst_Key = NULL;
#endif /* SB_USE_CLASS_TELSYMMETRICKEYMATERIAL */
}

TElXMLKeyInfoSymmetricData::TElXMLKeyInfoSymmetricData(TElXMLKeyInfoSymmetricDataHandle handle, TElOwnHandle ownHandle) : TElXMLKeyInfoData(handle, ownHandle)
{
	initInstances();
}

TElXMLKeyInfoSymmetricData::TElXMLKeyInfoSymmetricData(bool OwnResources) : TElXMLKeyInfoData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoSymmetricData_Create((int8_t)OwnResources, &_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElXMLKeyInfoSymmetricData::TElXMLKeyInfoSymmetricData(bool AOwnResources, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElXMLKeyInfoData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoSymmetricData_Create_1((int8_t)AOwnResources, Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElXMLKeyInfoSymmetricData::TElXMLKeyInfoSymmetricData(bool AOwnResources, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElXMLKeyInfoData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoSymmetricData_Create_1((int8_t)AOwnResources, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

TElXMLKeyInfoSymmetricData::~TElXMLKeyInfoSymmetricData()
{
#ifdef SB_USE_CLASS_TELSYMMETRICKEYMATERIAL
	delete this->_Inst_Key;
	this->_Inst_Key = NULL;
#endif /* SB_USE_CLASS_TELSYMMETRICKEYMATERIAL */
}
#endif /* SB_USE_CLASS_TELXMLKEYINFOSYMMETRICDATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFOASYMMETRICDATA

TElXMLKeyInfoAsymmetricData::TElXMLKeyInfoAsymmetricData(TElXMLKeyInfoAsymmetricDataHandle handle, TElOwnHandle ownHandle) : TElXMLKeyInfoData(handle, ownHandle)
{
}

TElXMLKeyInfoAsymmetricData::TElXMLKeyInfoAsymmetricData() : TElXMLKeyInfoData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLKeyInfoAsymmetricData_Create(&_Handle));
}

TElXMLKeyInfoAsymmetricData::TElXMLKeyInfoAsymmetricData(bool AOwnResources) : TElXMLKeyInfoData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLKeyInfoAsymmetricData_Create_1((int8_t)AOwnResources, &_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElXMLKeyInfoAsymmetricData::TElXMLKeyInfoAsymmetricData(bool AOwnResources, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElXMLKeyInfoData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLKeyInfoAsymmetricData_Create_2((int8_t)AOwnResources, Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElXMLKeyInfoAsymmetricData::TElXMLKeyInfoAsymmetricData(bool AOwnResources, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElXMLKeyInfoData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLKeyInfoAsymmetricData_Create_2((int8_t)AOwnResources, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELXMLKEYINFOASYMMETRICDATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFORSADATA

SB_INLINE void TElXMLKeyInfoRSAData::Update()
{
	SBCheckError(TElXMLKeyInfoRSAData_Update(_Handle));
}

#ifdef SB_USE_CLASS_TELRSAKEYMATERIAL
TElRSAKeyMaterial* TElXMLKeyInfoRSAData::get_RSAKeyMaterial()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLKeyInfoRSAData_get_RSAKeyMaterial(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RSAKeyMaterial)
		this->_Inst_RSAKeyMaterial = new TElRSAKeyMaterial(hOutResult, ohFalse);
	else
		this->_Inst_RSAKeyMaterial->updateHandle(hOutResult);
	return this->_Inst_RSAKeyMaterial;
}
#endif /* SB_USE_CLASS_TELRSAKEYMATERIAL */

void TElXMLKeyInfoRSAData::get_Exponent(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLKeyInfoRSAData_get_Exponent(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1104675180, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLKeyInfoRSAData::get_Modulus(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLKeyInfoRSAData_get_Modulus(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2125016035, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLKeyInfoRSAData::initInstances()
{
#ifdef SB_USE_CLASS_TELRSAKEYMATERIAL
	this->_Inst_RSAKeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELRSAKEYMATERIAL */
}

TElXMLKeyInfoRSAData::TElXMLKeyInfoRSAData(TElXMLKeyInfoRSADataHandle handle, TElOwnHandle ownHandle) : TElXMLKeyInfoAsymmetricData(handle, ownHandle)
{
	initInstances();
}

TElXMLKeyInfoRSAData::TElXMLKeyInfoRSAData(bool OwnResources) : TElXMLKeyInfoAsymmetricData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoRSAData_Create((int8_t)OwnResources, &_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElXMLKeyInfoRSAData::TElXMLKeyInfoRSAData(bool AOwnResources, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElXMLKeyInfoAsymmetricData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoRSAData_Create_1((int8_t)AOwnResources, Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElXMLKeyInfoRSAData::TElXMLKeyInfoRSAData(bool AOwnResources, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElXMLKeyInfoAsymmetricData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoRSAData_Create_1((int8_t)AOwnResources, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

TElXMLKeyInfoRSAData::~TElXMLKeyInfoRSAData()
{
#ifdef SB_USE_CLASS_TELRSAKEYMATERIAL
	delete this->_Inst_RSAKeyMaterial;
	this->_Inst_RSAKeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELRSAKEYMATERIAL */
}
#endif /* SB_USE_CLASS_TELXMLKEYINFORSADATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFODSADATA

SB_INLINE void TElXMLKeyInfoDSAData::Update()
{
	SBCheckError(TElXMLKeyInfoDSAData_Update(_Handle));
}

#ifdef SB_USE_CLASS_TELDSAKEYMATERIAL
TElDSAKeyMaterial* TElXMLKeyInfoDSAData::get_DSAKeyMaterial()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLKeyInfoDSAData_get_DSAKeyMaterial(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DSAKeyMaterial)
		this->_Inst_DSAKeyMaterial = new TElDSAKeyMaterial(hOutResult, ohFalse);
	else
		this->_Inst_DSAKeyMaterial->updateHandle(hOutResult);
	return this->_Inst_DSAKeyMaterial;
}
#endif /* SB_USE_CLASS_TELDSAKEYMATERIAL */

void TElXMLKeyInfoDSAData::get_P(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLKeyInfoDSAData_get_P(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-876226309, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLKeyInfoDSAData::get_Q(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLKeyInfoDSAData_get_Q(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1128077203, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLKeyInfoDSAData::get_G(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLKeyInfoDSAData_get_G(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1209425212, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLKeyInfoDSAData::get_Y(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLKeyInfoDSAData_get_Y(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1306959777, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLKeyInfoDSAData::get_J(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLKeyInfoDSAData_get_J(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(916922753, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLKeyInfoDSAData::get_Seed(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLKeyInfoDSAData_get_Seed(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(360872276, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLKeyInfoDSAData::get_PgenCounter(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLKeyInfoDSAData_get_PgenCounter(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-932049508, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLKeyInfoDSAData::initInstances()
{
#ifdef SB_USE_CLASS_TELDSAKEYMATERIAL
	this->_Inst_DSAKeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELDSAKEYMATERIAL */
}

TElXMLKeyInfoDSAData::TElXMLKeyInfoDSAData(TElXMLKeyInfoDSADataHandle handle, TElOwnHandle ownHandle) : TElXMLKeyInfoAsymmetricData(handle, ownHandle)
{
	initInstances();
}

TElXMLKeyInfoDSAData::TElXMLKeyInfoDSAData(bool OwnResources) : TElXMLKeyInfoAsymmetricData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoDSAData_Create((int8_t)OwnResources, &_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElXMLKeyInfoDSAData::TElXMLKeyInfoDSAData(bool AOwnResources, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElXMLKeyInfoAsymmetricData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoDSAData_Create_1((int8_t)AOwnResources, Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElXMLKeyInfoDSAData::TElXMLKeyInfoDSAData(bool AOwnResources, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElXMLKeyInfoAsymmetricData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoDSAData_Create_1((int8_t)AOwnResources, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

TElXMLKeyInfoDSAData::~TElXMLKeyInfoDSAData()
{
#ifdef SB_USE_CLASS_TELDSAKEYMATERIAL
	delete this->_Inst_DSAKeyMaterial;
	this->_Inst_DSAKeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELDSAKEYMATERIAL */
}
#endif /* SB_USE_CLASS_TELXMLKEYINFODSADATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFODHDATA

void TElXMLKeyInfoDHData::get_P(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLKeyInfoDHData_get_P(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-58599596, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLKeyInfoDHData::get_Q(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLKeyInfoDHData_get_Q(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1954093118, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLKeyInfoDHData::get_Generator(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLKeyInfoDHData_get_Generator(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(992220893, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLKeyInfoDHData::get_PublicKey(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLKeyInfoDHData_get_PublicKey(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1868378555, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLKeyInfoDHData::get_Seed(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLKeyInfoDHData_get_Seed(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(831519352, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLKeyInfoDHData::get_PgenCounter(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLKeyInfoDHData_get_PgenCounter(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1886665510, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElXMLKeyInfoDHData::TElXMLKeyInfoDHData(TElXMLKeyInfoDHDataHandle handle, TElOwnHandle ownHandle) : TElXMLKeyInfoAsymmetricData(handle, ownHandle)
{
}

TElXMLKeyInfoDHData::TElXMLKeyInfoDHData(bool OwnResources) : TElXMLKeyInfoAsymmetricData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLKeyInfoDHData_Create((int8_t)OwnResources, &_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElXMLKeyInfoDHData::TElXMLKeyInfoDHData(bool AOwnResources, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElXMLKeyInfoAsymmetricData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLKeyInfoDHData_Create_1((int8_t)AOwnResources, Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElXMLKeyInfoDHData::TElXMLKeyInfoDHData(bool AOwnResources, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElXMLKeyInfoAsymmetricData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLKeyInfoDHData_Create_1((int8_t)AOwnResources, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELXMLKEYINFODHDATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFOGOST2001DATA

SB_INLINE void TElXMLKeyInfoGOST2001Data::Update()
{
	SBCheckError(TElXMLKeyInfoGOST2001Data_Update(_Handle));
}

#ifdef SB_USE_CLASS_TELGOST2001KEYMATERIAL
TElGOST2001KeyMaterial* TElXMLKeyInfoGOST2001Data::get_GOST2001KeyMaterial()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLKeyInfoGOST2001Data_get_GOST2001KeyMaterial(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_GOST2001KeyMaterial)
		this->_Inst_GOST2001KeyMaterial = new TElGOST2001KeyMaterial(hOutResult, ohFalse);
	else
		this->_Inst_GOST2001KeyMaterial->updateHandle(hOutResult);
	return this->_Inst_GOST2001KeyMaterial;
}
#endif /* SB_USE_CLASS_TELGOST2001KEYMATERIAL */

void TElXMLKeyInfoGOST2001Data::get_PublicKey(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLKeyInfoGOST2001Data_get_PublicKey(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1969419628, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLKeyInfoGOST2001Data::get_PublicKeyParamSet(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLKeyInfoGOST2001Data_get_PublicKeyParamSet(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1224232396, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLKeyInfoGOST2001Data::get_PublicKeyParamSet(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLKeyInfoGOST2001Data_get_PublicKeyParamSet(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1224232396, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElXMLKeyInfoGOST2001Data::get_DigestParamSet(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLKeyInfoGOST2001Data_get_DigestParamSet(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1298008030, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLKeyInfoGOST2001Data::get_DigestParamSet(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLKeyInfoGOST2001Data_get_DigestParamSet(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1298008030, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElXMLKeyInfoGOST2001Data::get_EncryptionParamSet(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLKeyInfoGOST2001Data_get_EncryptionParamSet(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-366757360, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLKeyInfoGOST2001Data::get_EncryptionParamSet(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLKeyInfoGOST2001Data_get_EncryptionParamSet(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-366757360, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElXMLKeyInfoGOST2001Data::initInstances()
{
#ifdef SB_USE_CLASS_TELGOST2001KEYMATERIAL
	this->_Inst_GOST2001KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELGOST2001KEYMATERIAL */
}

TElXMLKeyInfoGOST2001Data::TElXMLKeyInfoGOST2001Data(TElXMLKeyInfoGOST2001DataHandle handle, TElOwnHandle ownHandle) : TElXMLKeyInfoAsymmetricData(handle, ownHandle)
{
	initInstances();
}

TElXMLKeyInfoGOST2001Data::TElXMLKeyInfoGOST2001Data(bool OwnResources) : TElXMLKeyInfoAsymmetricData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoGOST2001Data_Create((int8_t)OwnResources, &_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElXMLKeyInfoGOST2001Data::TElXMLKeyInfoGOST2001Data(bool AOwnResources, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElXMLKeyInfoAsymmetricData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoGOST2001Data_Create_1((int8_t)AOwnResources, Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElXMLKeyInfoGOST2001Data::TElXMLKeyInfoGOST2001Data(bool AOwnResources, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElXMLKeyInfoAsymmetricData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoGOST2001Data_Create_1((int8_t)AOwnResources, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

TElXMLKeyInfoGOST2001Data::~TElXMLKeyInfoGOST2001Data()
{
#ifdef SB_USE_CLASS_TELGOST2001KEYMATERIAL
	delete this->_Inst_GOST2001KeyMaterial;
	this->_Inst_GOST2001KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELGOST2001KEYMATERIAL */
}
#endif /* SB_USE_CLASS_TELXMLKEYINFOGOST2001DATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFOPGPDATA

SB_INLINE void TElXMLKeyInfoPGPData::Update()
{
	SBCheckError(TElXMLKeyInfoPGPData_Update(_Handle));
}

TElXMLKeyInfoPGPDataParam TElXMLKeyInfoPGPData::get_IncludeDataParam()
{
	TElXMLKeyInfoPGPDataParamRaw OutResultRaw = 0;
	SBCheckError(TElXMLKeyInfoPGPData_get_IncludeDataParam(_Handle, &OutResultRaw));
	return (TElXMLKeyInfoPGPDataParam)OutResultRaw;
}

SB_INLINE void TElXMLKeyInfoPGPData::set_IncludeDataParam(TElXMLKeyInfoPGPDataParam Value)
{
	SBCheckError(TElXMLKeyInfoPGPData_set_IncludeDataParam(_Handle, (TElXMLKeyInfoPGPDataParamRaw)Value));
}

bool TElXMLKeyInfoPGPData::get_IncludeKeyValue()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLKeyInfoPGPData_get_IncludeKeyValue(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLKeyInfoPGPData::set_IncludeKeyValue(bool Value)
{
	SBCheckError(TElXMLKeyInfoPGPData_set_IncludeKeyValue(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY
TElPGPCustomPublicKey* TElXMLKeyInfoPGPData::get_PublicKey()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLKeyInfoPGPData_get_PublicKey(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PublicKey)
		this->_Inst_PublicKey = new TElPGPCustomPublicKey(hOutResult, ohFalse);
	else
		this->_Inst_PublicKey->updateHandle(hOutResult);
	return this->_Inst_PublicKey;
}

SB_INLINE void TElXMLKeyInfoPGPData::set_PublicKey(TElPGPCustomPublicKey &Value)
{
	SBCheckError(TElXMLKeyInfoPGPData_set_PublicKey(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLKeyInfoPGPData::set_PublicKey(TElPGPCustomPublicKey *Value)
{
	SBCheckError(TElXMLKeyInfoPGPData_set_PublicKey(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPCUSTOMSECRETKEY
TElPGPCustomSecretKey* TElXMLKeyInfoPGPData::get_SecretKey()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLKeyInfoPGPData_get_SecretKey(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SecretKey)
		this->_Inst_SecretKey = new TElPGPCustomSecretKey(hOutResult, ohFalse);
	else
		this->_Inst_SecretKey->updateHandle(hOutResult);
	return this->_Inst_SecretKey;
}

SB_INLINE void TElXMLKeyInfoPGPData::set_SecretKey(TElPGPCustomSecretKey &Value)
{
	SBCheckError(TElXMLKeyInfoPGPData_set_SecretKey(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLKeyInfoPGPData::set_SecretKey(TElPGPCustomSecretKey *Value)
{
	SBCheckError(TElXMLKeyInfoPGPData_set_SecretKey(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPCUSTOMSECRETKEY */

void TElXMLKeyInfoPGPData::get_Passphrase(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLKeyInfoPGPData_get_Passphrase(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1435123891, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElXMLKeyInfoPGPData::set_Passphrase(const std::string &Value)
{
	SBCheckError(TElXMLKeyInfoPGPData_set_Passphrase(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElXMLKeyInfoPGPData::get_KeyID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLKeyInfoPGPData_get_KeyID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-739064151, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElXMLKeyInfoPGPData::get_KeyPacketCount()
{
	int32_t OutResult;
	SBCheckError(TElXMLKeyInfoPGPData_get_KeyPacketCount(_Handle, &OutResult));
	return OutResult;
}

void TElXMLKeyInfoPGPData::get_KeyPackets(int32_t Index, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLKeyInfoPGPData_get_KeyPackets(_Handle, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1561652292, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLKeyInfoPGPData::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY
	this->_Inst_PublicKey = NULL;
#endif /* SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY */
#ifdef SB_USE_CLASS_TELPGPCUSTOMSECRETKEY
	this->_Inst_SecretKey = NULL;
#endif /* SB_USE_CLASS_TELPGPCUSTOMSECRETKEY */
}

TElXMLKeyInfoPGPData::TElXMLKeyInfoPGPData(TElXMLKeyInfoPGPDataHandle handle, TElOwnHandle ownHandle) : TElXMLKeyInfoAsymmetricData(handle, ownHandle)
{
	initInstances();
}

TElXMLKeyInfoPGPData::TElXMLKeyInfoPGPData(bool OwnResources) : TElXMLKeyInfoAsymmetricData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoPGPData_Create((int8_t)OwnResources, &_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElXMLKeyInfoPGPData::TElXMLKeyInfoPGPData(bool AOwnResources, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElXMLKeyInfoAsymmetricData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoPGPData_Create_1((int8_t)AOwnResources, Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElXMLKeyInfoPGPData::TElXMLKeyInfoPGPData(bool AOwnResources, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElXMLKeyInfoAsymmetricData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoPGPData_Create_1((int8_t)AOwnResources, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

TElXMLKeyInfoPGPData::~TElXMLKeyInfoPGPData()
{
#ifdef SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY
	delete this->_Inst_PublicKey;
	this->_Inst_PublicKey = NULL;
#endif /* SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY */
#ifdef SB_USE_CLASS_TELPGPCUSTOMSECRETKEY
	delete this->_Inst_SecretKey;
	this->_Inst_SecretKey = NULL;
#endif /* SB_USE_CLASS_TELPGPCUSTOMSECRETKEY */
}
#endif /* SB_USE_CLASS_TELXMLKEYINFOPGPDATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFOECDATA

#ifdef SB_USE_CLASS_TELECKEYMATERIAL
TElECKeyMaterial* TElXMLKeyInfoECData::get_ECKeyMaterial()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLKeyInfoECData_get_ECKeyMaterial(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ECKeyMaterial)
		this->_Inst_ECKeyMaterial = new TElECKeyMaterial(hOutResult, ohFalse);
	else
		this->_Inst_ECKeyMaterial->updateHandle(hOutResult);
	return this->_Inst_ECKeyMaterial;
}
#endif /* SB_USE_CLASS_TELECKEYMATERIAL */

TSBXMLECKeyValueFormat TElXMLKeyInfoECData::get_KeyValueFormat()
{
	TSBXMLECKeyValueFormatRaw OutResultRaw = 0;
	SBCheckError(TElXMLKeyInfoECData_get_KeyValueFormat(_Handle, &OutResultRaw));
	return (TSBXMLECKeyValueFormat)OutResultRaw;
}

SB_INLINE void TElXMLKeyInfoECData::set_KeyValueFormat(TSBXMLECKeyValueFormat Value)
{
	SBCheckError(TElXMLKeyInfoECData_set_KeyValueFormat(_Handle, (TSBXMLECKeyValueFormatRaw)Value));
}

TSBXMLECPrimeNumberType TElXMLKeyInfoECData::get_PrimeNumberType()
{
	TSBXMLECPrimeNumberTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLKeyInfoECData_get_PrimeNumberType(_Handle, &OutResultRaw));
	return (TSBXMLECPrimeNumberType)OutResultRaw;
}

SB_INLINE void TElXMLKeyInfoECData::set_PrimeNumberType(TSBXMLECPrimeNumberType Value)
{
	SBCheckError(TElXMLKeyInfoECData_set_PrimeNumberType(_Handle, (TSBXMLECPrimeNumberTypeRaw)Value));
}

bool TElXMLKeyInfoECData::get_IncludeDomainParameters()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLKeyInfoECData_get_IncludeDomainParameters(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLKeyInfoECData::set_IncludeDomainParameters(bool Value)
{
	SBCheckError(TElXMLKeyInfoECData_set_IncludeDomainParameters(_Handle, (int8_t)Value));
}

bool TElXMLKeyInfoECData::get_UseExplicitParameters()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLKeyInfoECData_get_UseExplicitParameters(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLKeyInfoECData::set_UseExplicitParameters(bool Value)
{
	SBCheckError(TElXMLKeyInfoECData_set_UseExplicitParameters(_Handle, (int8_t)Value));
}

void TElXMLKeyInfoECData::get_ECDSAPrefix(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLKeyInfoECData_get_ECDSAPrefix(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-2142626132, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLKeyInfoECData::get_ECDSAPrefix(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLKeyInfoECData_get_ECDSAPrefix(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-2142626132, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLKeyInfoECData::set_ECDSAPrefix(const sb_u16string &Value)
{
	SBCheckError(TElXMLKeyInfoECData_set_ECDSAPrefix(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLKeyInfoECData::set_ECDSAPrefix(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLKeyInfoECData_set_ECDSAPrefix(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLKeyInfoECData::get_DSIG11Prefix(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLKeyInfoECData_get_DSIG11Prefix(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-474300905, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLKeyInfoECData::get_DSIG11Prefix(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLKeyInfoECData_get_DSIG11Prefix(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-474300905, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLKeyInfoECData::set_DSIG11Prefix(const sb_u16string &Value)
{
	SBCheckError(TElXMLKeyInfoECData_set_DSIG11Prefix(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLKeyInfoECData::set_DSIG11Prefix(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLKeyInfoECData_set_DSIG11Prefix(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLKeyInfoECData::initInstances()
{
#ifdef SB_USE_CLASS_TELECKEYMATERIAL
	this->_Inst_ECKeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELECKEYMATERIAL */
}

TElXMLKeyInfoECData::TElXMLKeyInfoECData(TElXMLKeyInfoECDataHandle handle, TElOwnHandle ownHandle) : TElXMLKeyInfoAsymmetricData(handle, ownHandle)
{
	initInstances();
}

TElXMLKeyInfoECData::TElXMLKeyInfoECData(bool AOwnResources) : TElXMLKeyInfoAsymmetricData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoECData_Create((int8_t)AOwnResources, &_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElXMLKeyInfoECData::TElXMLKeyInfoECData(bool AOwnResources, TElCustomCryptoProviderManager &AManager, TElCustomCryptoProvider &AProvider) : TElXMLKeyInfoAsymmetricData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoECData_Create_1((int8_t)AOwnResources, AManager.getHandle(), AProvider.getHandle(), &_Handle));
}

TElXMLKeyInfoECData::TElXMLKeyInfoECData(bool AOwnResources, TElCustomCryptoProviderManager *AManager, TElCustomCryptoProvider *AProvider) : TElXMLKeyInfoAsymmetricData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoECData_Create_1((int8_t)AOwnResources, (AManager != NULL) ? AManager->getHandle() : SB_NULL_HANDLE, (AProvider != NULL) ? AProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

TElXMLKeyInfoECData::~TElXMLKeyInfoECData()
{
#ifdef SB_USE_CLASS_TELECKEYMATERIAL
	delete this->_Inst_ECKeyMaterial;
	this->_Inst_ECKeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELECKEYMATERIAL */
}
#endif /* SB_USE_CLASS_TELXMLKEYINFOECDATA */

#ifdef SB_USE_CLASS_TELXMLISSUERSERIAL

SB_INLINE void TElXMLIssuerSerial::Clear()
{
	SBCheckError(TElXMLIssuerSerial_Clear(_Handle));
}

bool TElXMLIssuerSerial::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLIssuerSerial_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLIssuerSerial::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLIssuerSerial_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLIssuerSerial::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLIssuerSerial_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLIssuerSerial::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLIssuerSerial_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLIssuerSerial::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLIssuerSerial_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElXMLIssuerSerial::get_IssuerRDN()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLIssuerSerial_get_IssuerRDN(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IssuerRDN)
		this->_Inst_IssuerRDN = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_IssuerRDN->updateHandle(hOutResult);
	return this->_Inst_IssuerRDN;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

void TElXMLIssuerSerial::get_SerialNumber(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLIssuerSerial_get_SerialNumber(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(993919007, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElXMLIssuerSerial::set_SerialNumber(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElXMLIssuerSerial_set_SerialNumber(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElXMLIssuerSerial::get_HexSerialNumber()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLIssuerSerial_get_HexSerialNumber(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLIssuerSerial::set_HexSerialNumber(bool Value)
{
	SBCheckError(TElXMLIssuerSerial_set_HexSerialNumber(_Handle, (int8_t)Value));
}

void TElXMLIssuerSerial::initInstances()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_IssuerRDN = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
}

TElXMLIssuerSerial::TElXMLIssuerSerial(TElXMLIssuerSerialHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
	initInstances();
}

TElXMLIssuerSerial::TElXMLIssuerSerial() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLIssuerSerial_Create(&_Handle));
}

TElXMLIssuerSerial::TElXMLIssuerSerial(const sb_u16string &AName, const sb_u16string &ANamespaceURI, const sb_u16string &APrefix) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLIssuerSerial_Create_1(AName.data(), (int32_t)AName.length(), ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), APrefix.data(), (int32_t)APrefix.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLIssuerSerial::TElXMLIssuerSerial(const std::wstring &AName, const std::wstring &ANamespaceURI, const std::wstring &APrefix) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	std::string u16APrefix;
	sb_to_u16string(APrefix, u16APrefix);
	SBCheckError(TElXMLIssuerSerial_Create_1(reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16APrefix.data()), (int32_t)u16APrefix.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLIssuerSerial::~TElXMLIssuerSerial()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_IssuerRDN;
	this->_Inst_IssuerRDN = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
}
#endif /* SB_USE_CLASS_TELXMLISSUERSERIAL */

#ifdef SB_USE_CLASS_TELXMLKEYINFOX509DATA

SB_INLINE void TElXMLKeyInfoX509Data::Update()
{
	SBCheckError(TElXMLKeyInfoX509Data_Update(_Handle));
}

TElXMLKeyInfoX509DataParams TElXMLKeyInfoX509Data::get_IncludeDataParams()
{
	TElXMLKeyInfoX509DataParamsRaw OutResultRaw = 0;
	SBCheckError(TElXMLKeyInfoX509Data_get_IncludeDataParams(_Handle, &OutResultRaw));
	return (TElXMLKeyInfoX509DataParams)OutResultRaw;
}

SB_INLINE void TElXMLKeyInfoX509Data::set_IncludeDataParams(TElXMLKeyInfoX509DataParams Value)
{
	SBCheckError(TElXMLKeyInfoX509Data_set_IncludeDataParams(_Handle, (TElXMLKeyInfoX509DataParamsRaw)Value));
}

bool TElXMLKeyInfoX509Data::get_IncludeKeyValue()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLKeyInfoX509Data_get_IncludeKeyValue(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLKeyInfoX509Data::set_IncludeKeyValue(bool Value)
{
	SBCheckError(TElXMLKeyInfoX509Data_set_IncludeKeyValue(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElXMLKeyInfoX509Data::get_Certificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLKeyInfoX509Data_get_Certificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificate)
		this->_Inst_Certificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_Certificate->updateHandle(hOutResult);
	return this->_Inst_Certificate;
}

SB_INLINE void TElXMLKeyInfoX509Data::set_Certificate(TElX509Certificate &Value)
{
	SBCheckError(TElXMLKeyInfoX509Data_set_Certificate(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLKeyInfoX509Data::set_Certificate(TElX509Certificate *Value)
{
	SBCheckError(TElXMLKeyInfoX509Data_set_Certificate(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElXMLKeyInfoX509Data::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLKeyInfoX509Data_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElXMLKeyInfoX509Data::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElXMLKeyInfoX509Data_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLKeyInfoX509Data::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElXMLKeyInfoX509Data_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

bool TElXMLKeyInfoX509Data::get_HexSerialNumber()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLKeyInfoX509Data_get_HexSerialNumber(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLKeyInfoX509Data::set_HexSerialNumber(bool Value)
{
	SBCheckError(TElXMLKeyInfoX509Data_set_HexSerialNumber(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElXMLKeyInfoX509Data::get_IssuerSerialCount()
{
	int32_t OutResult;
	SBCheckError(TElXMLKeyInfoX509Data_get_IssuerSerialCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLKeyInfoX509Data::get_SubjectRDNCount()
{
	int32_t OutResult;
	SBCheckError(TElXMLKeyInfoX509Data_get_SubjectRDNCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLKeyInfoX509Data::get_SKICount()
{
	int32_t OutResult;
	SBCheckError(TElXMLKeyInfoX509Data_get_SKICount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElXMLKeyInfoX509Data::get_IssuerRDNs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLKeyInfoX509Data_get_IssuerRDNs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IssuerRDNs)
		this->_Inst_IssuerRDNs = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_IssuerRDNs->updateHandle(hOutResult);
	return this->_Inst_IssuerRDNs;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

void TElXMLKeyInfoX509Data::get_SerialNumbers(int32_t Index, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLKeyInfoX509Data_get_SerialNumbers(_Handle, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(928540558, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElXMLKeyInfoX509Data::get_SubjectRDNs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLKeyInfoX509Data_get_SubjectRDNs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SubjectRDNs)
		this->_Inst_SubjectRDNs = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_SubjectRDNs->updateHandle(hOutResult);
	return this->_Inst_SubjectRDNs;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

void TElXMLKeyInfoX509Data::get_SKIs(int32_t Index, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLKeyInfoX509Data_get_SKIs(_Handle, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-268885928, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLKeyInfoX509Data::get_CRLData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLKeyInfoX509Data_get_CRLData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1908471967, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElXMLKeyInfoData* TElXMLKeyInfoX509Data::get_GeneratedKeyValue()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLKeyInfoX509Data_get_GeneratedKeyValue(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_GeneratedKeyValue)
		this->_Inst_GeneratedKeyValue = new TElXMLKeyInfoData(hOutResult, ohFalse);
	else
		this->_Inst_GeneratedKeyValue->updateHandle(hOutResult);
	return this->_Inst_GeneratedKeyValue;
}

void TElXMLKeyInfoX509Data::initInstances()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_Certificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_IssuerRDNs = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_SubjectRDNs = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
	this->_Inst_GeneratedKeyValue = NULL;
}

TElXMLKeyInfoX509Data::TElXMLKeyInfoX509Data(TElXMLKeyInfoX509DataHandle handle, TElOwnHandle ownHandle) : TElXMLKeyInfoAsymmetricData(handle, ownHandle)
{
	initInstances();
}

TElXMLKeyInfoX509Data::TElXMLKeyInfoX509Data(bool OwnResources) : TElXMLKeyInfoAsymmetricData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoX509Data_Create((int8_t)OwnResources, &_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElXMLKeyInfoX509Data::TElXMLKeyInfoX509Data(bool AOwnResources, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElXMLKeyInfoAsymmetricData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoX509Data_Create_1((int8_t)AOwnResources, Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElXMLKeyInfoX509Data::TElXMLKeyInfoX509Data(bool AOwnResources, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElXMLKeyInfoAsymmetricData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoX509Data_Create_1((int8_t)AOwnResources, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

TElXMLKeyInfoX509Data::~TElXMLKeyInfoX509Data()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_Certificate;
	this->_Inst_Certificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_IssuerRDNs;
	this->_Inst_IssuerRDNs = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_SubjectRDNs;
	this->_Inst_SubjectRDNs = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
	delete this->_Inst_GeneratedKeyValue;
	this->_Inst_GeneratedKeyValue = NULL;
}
#endif /* SB_USE_CLASS_TELXMLKEYINFOX509DATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFONODE

bool TElXMLKeyInfoNode::get_OwnNode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLKeyInfoNode_get_OwnNode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLKeyInfoNode::set_OwnNode(bool Value)
{
	SBCheckError(TElXMLKeyInfoNode_set_OwnNode(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TElXMLDOMNode* TElXMLKeyInfoNode::get_Value()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLKeyInfoNode_get_Value(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Value)
		this->_Inst_Value = new TElXMLDOMNode(hOutResult, ohFalse);
	else
		this->_Inst_Value->updateHandle(hOutResult);
	return this->_Inst_Value;
}

SB_INLINE void TElXMLKeyInfoNode::set_Value(TElXMLDOMNode &Value)
{
	SBCheckError(TElXMLKeyInfoNode_set_Value(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLKeyInfoNode::set_Value(TElXMLDOMNode *Value)
{
	SBCheckError(TElXMLKeyInfoNode_set_Value(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

void TElXMLKeyInfoNode::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	this->_Inst_Value = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
}

TElXMLKeyInfoNode::TElXMLKeyInfoNode(TElXMLKeyInfoNodeHandle handle, TElOwnHandle ownHandle) : TElXMLKeyInfoItem(handle, ownHandle)
{
	initInstances();
}

TElXMLKeyInfoNode::TElXMLKeyInfoNode() : TElXMLKeyInfoItem(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoNode_Create(&_Handle));
}

TElXMLKeyInfoNode::TElXMLKeyInfoNode(bool AOwnNode) : TElXMLKeyInfoItem(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoNode_Create_1((int8_t)AOwnNode, &_Handle));
}

TElXMLKeyInfoNode::~TElXMLKeyInfoNode()
{
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	delete this->_Inst_Value;
	this->_Inst_Value = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
}
#endif /* SB_USE_CLASS_TELXMLKEYINFONODE */

#ifdef SB_USE_CLASS_TELXMLKEYINFORETRIEVALMETHOD

void TElXMLKeyInfoRetrievalMethod::get_DataType(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLKeyInfoRetrievalMethod_get_DataType(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1368849327, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLKeyInfoRetrievalMethod::get_DataType(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLKeyInfoRetrievalMethod_get_DataType(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1368849327, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLKeyInfoRetrievalMethod::set_DataType(const sb_u16string &Value)
{
	SBCheckError(TElXMLKeyInfoRetrievalMethod_set_DataType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLKeyInfoRetrievalMethod::set_DataType(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLKeyInfoRetrievalMethod_set_DataType(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLKeyInfoRetrievalMethod::get_URI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLKeyInfoRetrievalMethod_get_URI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1866219304, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLKeyInfoRetrievalMethod::get_URI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLKeyInfoRetrievalMethod_get_URI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1866219304, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLKeyInfoRetrievalMethod::set_URI(const sb_u16string &Value)
{
	SBCheckError(TElXMLKeyInfoRetrievalMethod_set_URI(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLKeyInfoRetrievalMethod::set_URI(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLKeyInfoRetrievalMethod_set_URI(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLKeyInfoRetrievalMethod::TElXMLKeyInfoRetrievalMethod(TElXMLKeyInfoRetrievalMethodHandle handle, TElOwnHandle ownHandle) : TElXMLKeyInfoItem(handle, ownHandle)
{
}

TElXMLKeyInfoRetrievalMethod::TElXMLKeyInfoRetrievalMethod() : TElXMLKeyInfoItem(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLKeyInfoRetrievalMethod_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLKEYINFORETRIEVALMETHOD */

#ifdef SB_USE_CLASS_TELXMLKEYINFOAGREEMENTMETHOD

void TElXMLKeyInfoAgreementMethod::get_Algorithm(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLKeyInfoAgreementMethod_get_Algorithm(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(278118663, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLKeyInfoAgreementMethod::get_Algorithm(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLKeyInfoAgreementMethod_get_Algorithm(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(278118663, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLKeyInfoAgreementMethod::set_Algorithm(const sb_u16string &Value)
{
	SBCheckError(TElXMLKeyInfoAgreementMethod_set_Algorithm(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLKeyInfoAgreementMethod::set_Algorithm(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLKeyInfoAgreementMethod_set_Algorithm(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLKeyInfoAgreementMethod::get_DigestMethod(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLKeyInfoAgreementMethod_get_DigestMethod(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(274422856, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLKeyInfoAgreementMethod::get_DigestMethod(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLKeyInfoAgreementMethod_get_DigestMethod(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(274422856, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLKeyInfoAgreementMethod::set_DigestMethod(const sb_u16string &Value)
{
	SBCheckError(TElXMLKeyInfoAgreementMethod_set_DigestMethod(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLKeyInfoAgreementMethod::set_DigestMethod(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLKeyInfoAgreementMethod_set_DigestMethod(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLKeyInfoAgreementMethod::get_KANonce(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLKeyInfoAgreementMethod_get_KANonce(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2065028047, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElXMLKeyInfoAgreementMethod::set_KANonce(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElXMLKeyInfoAgreementMethod_set_KANonce(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElXMLKeyInfoAgreementMethod::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLKeyInfoAgreementMethod_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElXMLKeyInfoAgreementMethod::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElXMLKeyInfoAgreementMethod_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLKeyInfoAgreementMethod::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElXMLKeyInfoAgreementMethod_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELXMLKEYINFO
TElXMLKeyInfo* TElXMLKeyInfoAgreementMethod::get_OriginatorKeyInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLKeyInfoAgreementMethod_get_OriginatorKeyInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OriginatorKeyInfo)
		this->_Inst_OriginatorKeyInfo = new TElXMLKeyInfo(hOutResult, ohFalse);
	else
		this->_Inst_OriginatorKeyInfo->updateHandle(hOutResult);
	return this->_Inst_OriginatorKeyInfo;
}

SB_INLINE void TElXMLKeyInfoAgreementMethod::set_OriginatorKeyInfo(TElXMLKeyInfo &Value)
{
	SBCheckError(TElXMLKeyInfoAgreementMethod_set_OriginatorKeyInfo(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLKeyInfoAgreementMethod::set_OriginatorKeyInfo(TElXMLKeyInfo *Value)
{
	SBCheckError(TElXMLKeyInfoAgreementMethod_set_OriginatorKeyInfo(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLKEYINFO */

#ifdef SB_USE_CLASS_TELXMLKEYINFO
TElXMLKeyInfo* TElXMLKeyInfoAgreementMethod::get_RecipientKeyInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLKeyInfoAgreementMethod_get_RecipientKeyInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RecipientKeyInfo)
		this->_Inst_RecipientKeyInfo = new TElXMLKeyInfo(hOutResult, ohFalse);
	else
		this->_Inst_RecipientKeyInfo->updateHandle(hOutResult);
	return this->_Inst_RecipientKeyInfo;
}

SB_INLINE void TElXMLKeyInfoAgreementMethod::set_RecipientKeyInfo(TElXMLKeyInfo &Value)
{
	SBCheckError(TElXMLKeyInfoAgreementMethod_set_RecipientKeyInfo(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLKeyInfoAgreementMethod::set_RecipientKeyInfo(TElXMLKeyInfo *Value)
{
	SBCheckError(TElXMLKeyInfoAgreementMethod_set_RecipientKeyInfo(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLKEYINFO */

void TElXMLKeyInfoAgreementMethod::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELXMLKEYINFO
	this->_Inst_OriginatorKeyInfo = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFO */
#ifdef SB_USE_CLASS_TELXMLKEYINFO
	this->_Inst_RecipientKeyInfo = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFO */
}

TElXMLKeyInfoAgreementMethod::TElXMLKeyInfoAgreementMethod(TElXMLKeyInfoAgreementMethodHandle handle, TElOwnHandle ownHandle) : TElXMLKeyInfoItem(handle, ownHandle)
{
	initInstances();
}

TElXMLKeyInfoAgreementMethod::TElXMLKeyInfoAgreementMethod() : TElXMLKeyInfoItem(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLKeyInfoAgreementMethod_Create(&_Handle));
}

TElXMLKeyInfoAgreementMethod::~TElXMLKeyInfoAgreementMethod()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELXMLKEYINFO
	delete this->_Inst_OriginatorKeyInfo;
	this->_Inst_OriginatorKeyInfo = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFO */
#ifdef SB_USE_CLASS_TELXMLKEYINFO
	delete this->_Inst_RecipientKeyInfo;
	this->_Inst_RecipientKeyInfo = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFO */
}
#endif /* SB_USE_CLASS_TELXMLKEYINFOAGREEMENTMETHOD */

#ifdef SB_USE_CLASS_TELXMLPROPERTY

void TElXMLProperty::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLProperty_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-686294022, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLProperty::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLProperty_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-686294022, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLProperty::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLProperty_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLProperty::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLProperty_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLProperty::get_Target(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLProperty_get_Target(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(945522519, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLProperty::get_Target(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLProperty_get_Target(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(945522519, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLProperty::set_Target(const sb_u16string &Value)
{
	SBCheckError(TElXMLProperty_set_Target(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLProperty::set_Target(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLProperty_set_Target(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLDOMElement* TElXMLProperty::get_PropertyNode()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLProperty_get_PropertyNode(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PropertyNode)
		this->_Inst_PropertyNode = new TElXMLDOMElement(hOutResult, ohFalse);
	else
		this->_Inst_PropertyNode->updateHandle(hOutResult);
	return this->_Inst_PropertyNode;
}

SB_INLINE void TElXMLProperty::set_PropertyNode(TElXMLDOMElement &Value)
{
	SBCheckError(TElXMLProperty_set_PropertyNode(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLProperty::set_PropertyNode(TElXMLDOMElement *Value)
{
	SBCheckError(TElXMLProperty_set_PropertyNode(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

bool TElXMLProperty::get_OwnPropertyNode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLProperty_get_OwnPropertyNode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLProperty::set_OwnPropertyNode(bool Value)
{
	SBCheckError(TElXMLProperty_set_OwnPropertyNode(_Handle, (int8_t)Value));
}

void TElXMLProperty::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	this->_Inst_PropertyNode = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
}

TElXMLProperty::TElXMLProperty(TElXMLPropertyHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElXMLProperty::TElXMLProperty() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLProperty_Create(&_Handle));
}

TElXMLProperty::~TElXMLProperty()
{
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	delete this->_Inst_PropertyNode;
	this->_Inst_PropertyNode = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
}
#endif /* SB_USE_CLASS_TELXMLPROPERTY */

#ifdef SB_USE_CLASS_TELXMLPROPERTIES

bool TElXMLProperties::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLProperties_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLProperties::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLProperties_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLProperties::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLProperties_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLProperties::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLProperties_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLProperties::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLProperties_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLPROPERTY
SB_INLINE int32_t TElXMLProperties::Add(TElXMLProperty &AProperty)
{
	int32_t OutResult;
	SBCheckError(TElXMLProperties_Add(_Handle, AProperty.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLProperties::Add(TElXMLProperty *AProperty)
{
	int32_t OutResult;
	SBCheckError(TElXMLProperties_Add(_Handle, (AProperty != NULL) ? AProperty->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLPROPERTY */

#ifdef SB_USE_CLASS_TELXMLPROPERTY
SB_INLINE void TElXMLProperties::Insert(int32_t Index, TElXMLProperty &AProperty)
{
	SBCheckError(TElXMLProperties_Insert(_Handle, Index, AProperty.getHandle()));
}

SB_INLINE void TElXMLProperties::Insert(int32_t Index, TElXMLProperty *AProperty)
{
	SBCheckError(TElXMLProperties_Insert(_Handle, Index, (AProperty != NULL) ? AProperty->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLPROPERTY */

SB_INLINE void TElXMLProperties::Delete(int32_t Index)
{
	SBCheckError(TElXMLProperties_Delete(_Handle, Index));
}

SB_INLINE void TElXMLProperties::Clear()
{
	SBCheckError(TElXMLProperties_Clear(_Handle));
}

SB_INLINE int32_t TElXMLProperties::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLProperties_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElXMLProperties::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLProperties_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(759380718, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLProperties::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLProperties_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(759380718, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLProperties::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLProperties_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLProperties::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLProperties_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLPROPERTY
TElXMLProperty* TElXMLProperties::get_Properties(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLProperties_get_Properties(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Properties)
		this->_Inst_Properties = new TElXMLProperty(hOutResult, ohFalse);
	else
		this->_Inst_Properties->updateHandle(hOutResult);
	return this->_Inst_Properties;
}
#endif /* SB_USE_CLASS_TELXMLPROPERTY */

void TElXMLProperties::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLPROPERTY
	this->_Inst_Properties = NULL;
#endif /* SB_USE_CLASS_TELXMLPROPERTY */
}

TElXMLProperties::TElXMLProperties(TElXMLPropertiesHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
	initInstances();
}

TElXMLProperties::TElXMLProperties() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLProperties_Create(&_Handle));
}

TElXMLProperties::~TElXMLProperties()
{
#ifdef SB_USE_CLASS_TELXMLPROPERTY
	delete this->_Inst_Properties;
	this->_Inst_Properties = NULL;
#endif /* SB_USE_CLASS_TELXMLPROPERTY */
}
#endif /* SB_USE_CLASS_TELXMLPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLPROCESSOR

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElXMLProcessor::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLProcessor_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElXMLProcessor::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElXMLProcessor_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLProcessor::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElXMLProcessor_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

void TElXMLProcessor::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}

TElXMLProcessor::TElXMLProcessor(TElXMLProcessorHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElXMLProcessor::TElXMLProcessor(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLProcessor_Create(AOwner.getHandle(), &_Handle));
}

TElXMLProcessor::TElXMLProcessor(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLProcessor_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElXMLProcessor::~TElXMLProcessor()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}
#endif /* SB_USE_CLASS_TELXMLPROCESSOR */

#ifdef SB_USE_CLASS_TELXMLFORMATTER

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLFormatter::AppendElement(TElXMLDOMElement &Parent, TElXMLDOMElement &Child)
{
	SBCheckError(TElXMLFormatter_AppendElement(_Handle, Parent.getHandle(), Child.getHandle()));
}

SB_INLINE void TElXMLFormatter::AppendElement(TElXMLDOMElement *Parent, TElXMLDOMElement *Child)
{
	SBCheckError(TElXMLFormatter_AppendElement(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, (Child != NULL) ? Child->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMELEMENT_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLFormatter::AppendElement(TElXMLDOMElement &Parent, TElXMLCustomElement &Child, TElXMLDOMDocument &Document)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLFormatter_AppendElement_1(_Handle, Parent.getHandle(), Child.getHandle(), Document.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLFormatter::AppendElement(TElXMLDOMElement *Parent, TElXMLCustomElement *Child, TElXMLDOMDocument *Document)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLFormatter_AppendElement_1(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, (Child != NULL) ? Child->getHandle() : SB_NULL_HANDLE, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMELEMENT_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLFormatter::AppendElementWithText(TElXMLDOMElement &Parent, TElXMLDOMElement &Child, const sb_u16string &ChildText, TElXMLTextType ChildTextType)
{
	SBCheckError(TElXMLFormatter_AppendElementWithText(_Handle, Parent.getHandle(), Child.getHandle(), ChildText.data(), (int32_t)ChildText.length(), (TElXMLTextTypeRaw)ChildTextType));
}

SB_INLINE void TElXMLFormatter::AppendElementWithText(TElXMLDOMElement *Parent, TElXMLDOMElement *Child, const sb_u16string &ChildText, TElXMLTextType ChildTextType)
{
	SBCheckError(TElXMLFormatter_AppendElementWithText(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, (Child != NULL) ? Child->getHandle() : SB_NULL_HANDLE, ChildText.data(), (int32_t)ChildText.length(), (TElXMLTextTypeRaw)ChildTextType));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLFormatter::AppendElementWithText(TElXMLDOMElement &Parent, TElXMLDOMElement &Child, const std::wstring &ChildText, TElXMLTextType ChildTextType)
{
	std::string u16ChildText;
	sb_to_u16string(ChildText, u16ChildText);
	SBCheckError(TElXMLFormatter_AppendElementWithText(_Handle, Parent.getHandle(), Child.getHandle(), reinterpret_cast<const sb_char16_t*>(u16ChildText.data()), (int32_t)u16ChildText.length() >> 1, (TElXMLTextTypeRaw)ChildTextType));
}

SB_INLINE void TElXMLFormatter::AppendElementWithText(TElXMLDOMElement *Parent, TElXMLDOMElement *Child, const std::wstring &ChildText, TElXMLTextType ChildTextType)
{
	std::string u16ChildText;
	sb_to_u16string(ChildText, u16ChildText);
	SBCheckError(TElXMLFormatter_AppendElementWithText(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, (Child != NULL) ? Child->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16ChildText.data()), (int32_t)u16ChildText.length() >> 1, (TElXMLTextTypeRaw)ChildTextType));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLFormatter::AppendText(TElXMLDOMElement &Parent, const sb_u16string &Text, TElXMLTextType TextType)
{
	SBCheckError(TElXMLFormatter_AppendText(_Handle, Parent.getHandle(), Text.data(), (int32_t)Text.length(), (TElXMLTextTypeRaw)TextType));
}

SB_INLINE void TElXMLFormatter::AppendText(TElXMLDOMElement *Parent, const sb_u16string &Text, TElXMLTextType TextType)
{
	SBCheckError(TElXMLFormatter_AppendText(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, Text.data(), (int32_t)Text.length(), (TElXMLTextTypeRaw)TextType));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLFormatter::AppendText(TElXMLDOMElement &Parent, const std::wstring &Text, TElXMLTextType TextType)
{
	std::string u16Text;
	sb_to_u16string(Text, u16Text);
	SBCheckError(TElXMLFormatter_AppendText(_Handle, Parent.getHandle(), reinterpret_cast<const sb_char16_t*>(u16Text.data()), (int32_t)u16Text.length() >> 1, (TElXMLTextTypeRaw)TextType));
}

SB_INLINE void TElXMLFormatter::AppendText(TElXMLDOMElement *Parent, const std::wstring &Text, TElXMLTextType TextType)
{
	std::string u16Text;
	sb_to_u16string(Text, u16Text);
	SBCheckError(TElXMLFormatter_AppendText(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16Text.data()), (int32_t)u16Text.length() >> 1, (TElXMLTextTypeRaw)TextType));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMELEMENT_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT_AND_TELXMLDOMNODE
SB_INLINE void TElXMLFormatter::InsertBefore(TElXMLDOMElement &Parent, TElXMLDOMNode &ChildRef, TElXMLCustomElement &Child, TElXMLDOMDocument &Document)
{
	SBCheckError(TElXMLFormatter_InsertBefore(_Handle, Parent.getHandle(), ChildRef.getHandle(), Child.getHandle(), Document.getHandle()));
}

SB_INLINE void TElXMLFormatter::InsertBefore(TElXMLDOMElement *Parent, TElXMLDOMNode *ChildRef, TElXMLCustomElement *Child, TElXMLDOMDocument *Document)
{
	SBCheckError(TElXMLFormatter_InsertBefore(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, (ChildRef != NULL) ? ChildRef->getHandle() : SB_NULL_HANDLE, (Child != NULL) ? Child->getHandle() : SB_NULL_HANDLE, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMELEMENT_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT_AND_TELXMLDOMNODE */

SB_INLINE void TElXMLFormatter::Clear()
{
	SBCheckError(TElXMLFormatter_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLFormatter::Push(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLFormatter_Push(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLFormatter::Push(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLFormatter_Push(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE void TElXMLFormatter::Pop()
{
	SBCheckError(TElXMLFormatter_Pop(_Handle));
}

SB_INLINE int32_t TElXMLFormatter::get_Level()
{
	int32_t OutResult;
	SBCheckError(TElXMLFormatter_get_Level(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLFormatter::set_Level(int32_t Value)
{
	SBCheckError(TElXMLFormatter_set_Level(_Handle, Value));
}

void TElXMLFormatter::get_Path(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLFormatter_get_Path(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-313071919, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLFormatter::get_Path(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLFormatter_get_Path(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-313071919, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLFormatter::set_Path(const sb_u16string &Value)
{
	SBCheckError(TElXMLFormatter_set_Path(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLFormatter::set_Path(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLFormatter_set_Path(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLFormatter::get_OnFormatElement(TSBXMLFormatElementEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXMLFormatter_get_OnFormatElement(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXMLFormatter::set_OnFormatElement(TSBXMLFormatElementEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXMLFormatter_set_OnFormatElement(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElXMLFormatter::get_OnFormatText(TSBXMLFormatTextEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXMLFormatter_get_OnFormatText(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXMLFormatter::set_OnFormatText(TSBXMLFormatTextEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXMLFormatter_set_OnFormatText(_Handle, pMethodValue, pDataValue));
}

TElXMLFormatter::TElXMLFormatter(TElXMLFormatterHandle handle, TElOwnHandle ownHandle) : TElXMLCustomFormatter(handle, ownHandle)
{
}

TElXMLFormatter::TElXMLFormatter() : TElXMLCustomFormatter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLFormatter_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLFORMATTER */

#ifdef SB_USE_CLASS_TELXMLDESCRIPTORMAP

SB_INLINE void TElXMLDescriptorMap::Add(const std::vector<uint8_t> &OID, const sb_u16string &Descriptor)
{
	SBCheckError(TElXMLDescriptorMap_Add(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), Descriptor.data(), (int32_t)Descriptor.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLDescriptorMap::Add(const std::vector<uint8_t> &OID, const std::wstring &Descriptor)
{
	std::string u16Descriptor;
	sb_to_u16string(Descriptor, u16Descriptor);
	SBCheckError(TElXMLDescriptorMap_Add(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), reinterpret_cast<const sb_char16_t*>(u16Descriptor.data()), (int32_t)u16Descriptor.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElXMLDescriptorMap::ClearOID(const std::vector<uint8_t> &OID)
{
	SBCheckError(TElXMLDescriptorMap_ClearOID(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size()));
}

SB_INLINE void TElXMLDescriptorMap::RemoveAt(int32_t Index)
{
	SBCheckError(TElXMLDescriptorMap_RemoveAt(_Handle, Index));
}

void TElXMLDescriptorMap::FindDescriptor(const std::vector<uint8_t> &OID, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDescriptorMap_FindDescriptor(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-384415760, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLDescriptorMap::FindDescriptor(const std::vector<uint8_t> &OID, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDescriptorMap_FindDescriptor(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-384415760, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElXMLDescriptorMap::FindOID(const sb_u16string &Descriptor, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLDescriptorMap_FindOID(_Handle, Descriptor.data(), (int32_t)Descriptor.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-484118159, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLDescriptorMap::FindOID(const std::wstring &Descriptor, std::vector<uint8_t> &OutResult)
{
	std::string u16Descriptor;
	sb_to_u16string(Descriptor, u16Descriptor);
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLDescriptorMap_FindOID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Descriptor.data()), (int32_t)u16Descriptor.length() >> 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-484118159, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElXMLDescriptorMap::ClearOIDs()
{
	SBCheckError(TElXMLDescriptorMap_ClearOIDs(_Handle));
}

SB_INLINE void TElXMLDescriptorMap::ClearOrders()
{
	SBCheckError(TElXMLDescriptorMap_ClearOrders(_Handle));
}

SB_INLINE int32_t TElXMLDescriptorMap::GetOrder(const std::vector<uint8_t> &OID)
{
	int32_t OutResult;
	SBCheckError(TElXMLDescriptorMap_GetOrder(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLDescriptorMap::SetOrder(int32_t Index, const std::vector<uint8_t> &OID)
{
	SBCheckError(TElXMLDescriptorMap_SetOrder(_Handle, Index, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size()));
}

TElXMLRDNCompatibilityMode TElXMLDescriptorMap::get_CompatibilityMode()
{
	TElXMLRDNCompatibilityModeRaw OutResultRaw = 0;
	SBCheckError(TElXMLDescriptorMap_get_CompatibilityMode(_Handle, &OutResultRaw));
	return (TElXMLRDNCompatibilityMode)OutResultRaw;
}

SB_INLINE void TElXMLDescriptorMap::set_CompatibilityMode(TElXMLRDNCompatibilityMode Value)
{
	SBCheckError(TElXMLDescriptorMap_set_CompatibilityMode(_Handle, (TElXMLRDNCompatibilityModeRaw)Value));
}

bool TElXMLDescriptorMap::get_ReverseOrder()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLDescriptorMap_get_ReverseOrder(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLDescriptorMap::set_ReverseOrder(bool Value)
{
	SBCheckError(TElXMLDescriptorMap_set_ReverseOrder(_Handle, (int8_t)Value));
}

void TElXMLDescriptorMap::get_Separator(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDescriptorMap_get_Separator(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-736376533, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElXMLDescriptorMap::set_Separator(const std::string &Value)
{
	SBCheckError(TElXMLDescriptorMap_set_Separator(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElXMLDescriptorMap::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLDescriptorMap_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElXMLDescriptorMap::get_OID(int32_t Index, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLDescriptorMap_get_OID(_Handle, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(607548868, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLDescriptorMap::get_Descriptor(int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDescriptorMap_get_Descriptor(_Handle, Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(2102724535, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDescriptorMap::get_Descriptor(int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDescriptorMap_get_Descriptor(_Handle, Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(2102724535, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
TElXMLDescriptorMap::TElXMLDescriptorMap(TElXMLDescriptorMapHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElXMLDescriptorMap::TElXMLDescriptorMap() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLDescriptorMap_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLDESCRIPTORMAP */

#ifdef SB_USE_GLOBAL_PROCS_XMLSEC

void ToCryptoBinary(const std::vector<uint8_t> &Buf, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBXMLSec_ToCryptoBinary(SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1623342769, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void ToCryptoBinary(const std::vector<uint8_t> &Buf, bool KeepTrailingZero, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBXMLSec_ToCryptoBinary_1(SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size(), (int8_t)KeepTrailingZero, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1254246457, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle FindChildElementEnc(const TElXMLDOMElement &Element, const sb_u16string &Name)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBXMLSec_FindChildElementEnc(Element.getHandle(), Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMElementHandle FindChildElementEnc(const TElXMLDOMElement *Element, const sb_u16string &Name)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBXMLSec_FindChildElementEnc((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMElementHandle FindChildElementEnc(const TElXMLDOMElement &Element, const std::wstring &Name)
{
	TElXMLDOMElementHandle OutResult;
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	SBCheckError(SBXMLSec_FindChildElementEnc(Element.getHandle(), reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMElementHandle FindChildElementEnc(const TElXMLDOMElement *Element, const std::wstring &Name)
{
	TElXMLDOMElementHandle OutResult;
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	SBCheckError(SBXMLSec_FindChildElementEnc((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle FindChildElementSig(const TElXMLDOMElement &Element, const sb_u16string &Name)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBXMLSec_FindChildElementSig(Element.getHandle(), Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMElementHandle FindChildElementSig(const TElXMLDOMElement *Element, const sb_u16string &Name)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBXMLSec_FindChildElementSig((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMElementHandle FindChildElementSig(const TElXMLDOMElement &Element, const std::wstring &Name)
{
	TElXMLDOMElementHandle OutResult;
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	SBCheckError(SBXMLSec_FindChildElementSig(Element.getHandle(), reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMElementHandle FindChildElementSig(const TElXMLDOMElement *Element, const std::wstring &Name)
{
	TElXMLDOMElementHandle OutResult;
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	SBCheckError(SBXMLSec_FindChildElementSig((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle FindChildElementXAdES(const TElXMLDOMElement &Element, const sb_u16string &Name, const sb_u16string &NamespaceURI)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBXMLSec_FindChildElementXAdES(Element.getHandle(), Name.data(), (int32_t)Name.length(), NamespaceURI.data(), (int32_t)NamespaceURI.length(), &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMElementHandle FindChildElementXAdES(const TElXMLDOMElement *Element, const sb_u16string &Name, const sb_u16string &NamespaceURI)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBXMLSec_FindChildElementXAdES((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), NamespaceURI.data(), (int32_t)NamespaceURI.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMElementHandle FindChildElementXAdES(const TElXMLDOMElement &Element, const std::wstring &Name, const std::wstring &NamespaceURI)
{
	TElXMLDOMElementHandle OutResult;
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	std::string u16NamespaceURI;
	sb_to_u16string(NamespaceURI, u16NamespaceURI);
	SBCheckError(SBXMLSec_FindChildElementXAdES(Element.getHandle(), reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16NamespaceURI.data()), (int32_t)u16NamespaceURI.length() >> 1, &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMElementHandle FindChildElementXAdES(const TElXMLDOMElement *Element, const std::wstring &Name, const std::wstring &NamespaceURI)
{
	TElXMLDOMElementHandle OutResult;
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	std::string u16NamespaceURI;
	sb_to_u16string(NamespaceURI, u16NamespaceURI);
	SBCheckError(SBXMLSec_FindChildElementXAdES((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16NamespaceURI.data()), (int32_t)u16NamespaceURI.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

void CalculateDigest(void * Buf, int32_t Size, TElXMLDigestMethod aMethod, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBXMLSec_CalculateDigest(Buf, Size, (TElXMLDigestMethodRaw)aMethod, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-979580673, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
void CalculateDigest(void * Buf, int32_t Size, TElXMLDigestMethod aMethod, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBXMLSec_CalculateDigest_1(Buf, Size, (TElXMLDigestMethodRaw)aMethod, Manager.getHandle(), Prov.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(771892710, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void CalculateDigest(void * Buf, int32_t Size, TElXMLDigestMethod aMethod, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBXMLSec_CalculateDigest_1(Buf, Size, (TElXMLDigestMethodRaw)aMethod, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(771892710, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELXMLALGORITHMPARAMETERS
void CalculateDigest(void * Buf, int32_t Size, TElXMLDigestMethod aMethod, TElXMLAlgorithmParameters &Parameters, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBXMLSec_CalculateDigest_2(Buf, Size, (TElXMLDigestMethodRaw)aMethod, Parameters.getHandle(), Manager.getHandle(), Prov.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(569048271, 6, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void CalculateDigest(void * Buf, int32_t Size, TElXMLDigestMethod aMethod, TElXMLAlgorithmParameters *Parameters, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBXMLSec_CalculateDigest_2(Buf, Size, (TElXMLDigestMethodRaw)aMethod, (Parameters != NULL) ? Parameters->getHandle() : SB_NULL_HANDLE, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(569048271, 6, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELXMLALGORITHMPARAMETERS */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TSTREAM
void CalculateDigestStream(TStream &Stream, int64_t Count, TElXMLDigestMethod aMethod, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBXMLSec_CalculateDigestStream(Stream.getHandle(), Count, (TElXMLDigestMethodRaw)aMethod, Manager.getHandle(), Prov.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1056304977, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void CalculateDigestStream(TStream *Stream, int64_t Count, TElXMLDigestMethod aMethod, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBXMLSec_CalculateDigestStream((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count, (TElXMLDigestMethodRaw)aMethod, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1056304977, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TSTREAM */

SB_INLINE int32_t DigestMethodToHashAlgorithm(TElXMLDigestMethod DigestMethod)
{
	int32_t OutResult;
	SBCheckError(SBXMLSec_DigestMethodToHashAlgorithm((TElXMLDigestMethodRaw)DigestMethod, &OutResult));
	return OutResult;
}

void DigestMethodToURI(TElXMLDigestMethod DigestMethod, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLSec_DigestMethodToURI((TElXMLDigestMethodRaw)DigestMethod, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1416321502, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void DigestMethodToURI(TElXMLDigestMethod DigestMethod, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLSec_DigestMethodToURI((TElXMLDigestMethodRaw)DigestMethod, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1416321502, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

TElXMLDigestMethod URIToDigestMethod(const sb_u16string &DigestMethod)
{
	TElXMLDigestMethodRaw OutResultRaw = 0;
	SBCheckError(SBXMLSec_URIToDigestMethod(DigestMethod.data(), (int32_t)DigestMethod.length(), &OutResultRaw));
	return (TElXMLDigestMethod)OutResultRaw;
}
#ifdef SB_U16STRING_USED
TElXMLDigestMethod URIToDigestMethod(const std::wstring &DigestMethod)
{
	std::string u16DigestMethod;
	sb_to_u16string(DigestMethod, u16DigestMethod);
	TElXMLDigestMethodRaw OutResultRaw = 0;
	SBCheckError(SBXMLSec_URIToDigestMethod(reinterpret_cast<const sb_char16_t*>(u16DigestMethod.data()), (int32_t)u16DigestMethod.length() >> 1, &OutResultRaw));
	return (TElXMLDigestMethod)OutResultRaw;
}
#endif /* SB_U16STRING_USED */

TElXMLDigestMethod GetDigestMethodFromSignatureMethod(TElXMLSignatureMethod SignatureMethod)
{
	TElXMLDigestMethodRaw OutResultRaw = 0;
	SBCheckError(SBXMLSec_GetDigestMethodFromSignatureMethod((TElXMLSignatureMethodRaw)SignatureMethod, &OutResultRaw));
	return (TElXMLDigestMethod)OutResultRaw;
}

TElXMLDigestMethod HashAlgorithmToDigestMethod(int32_t HashAlgorithm)
{
	TElXMLDigestMethodRaw OutResultRaw = 0;
	SBCheckError(SBXMLSec_HashAlgorithmToDigestMethod(HashAlgorithm, &OutResultRaw));
	return (TElXMLDigestMethod)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
void FormatRDN(const TElRelativeDistinguishedName &RDN, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLSec_FormatRDN(RDN.getHandle(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-474742362, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void FormatRDN(const TElRelativeDistinguishedName *RDN, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLSec_FormatRDN((RDN != NULL) ? RDN->getHandle() : SB_NULL_HANDLE, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-474742362, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void FormatRDN(const TElRelativeDistinguishedName &RDN, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLSec_FormatRDN(RDN.getHandle(), NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-474742362, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
void FormatRDN(const TElRelativeDistinguishedName *RDN, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLSec_FormatRDN((RDN != NULL) ? RDN->getHandle() : SB_NULL_HANDLE, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-474742362, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void ExtractRDN(const sb_u16string &Data, TElRelativeDistinguishedName &RDN)
{
	SBCheckError(SBXMLSec_ExtractRDN(Data.data(), (int32_t)Data.length(), RDN.getHandle()));
}
SB_INLINE void ExtractRDN(const sb_u16string &Data, TElRelativeDistinguishedName *RDN)
{
	SBCheckError(SBXMLSec_ExtractRDN(Data.data(), (int32_t)Data.length(), (RDN != NULL) ? RDN->getHandle() : SB_NULL_HANDLE));
}
#ifdef SB_U16STRING_USED
SB_INLINE void ExtractRDN(const std::wstring &Data, TElRelativeDistinguishedName &RDN)
{
	std::string u16Data;
	sb_to_u16string(Data, u16Data);
	SBCheckError(SBXMLSec_ExtractRDN(reinterpret_cast<const sb_char16_t*>(u16Data.data()), (int32_t)u16Data.length() >> 1, RDN.getHandle()));
}
SB_INLINE void ExtractRDN(const std::wstring &Data, TElRelativeDistinguishedName *RDN)
{
	std::string u16Data;
	sb_to_u16string(Data, u16Data);
	SBCheckError(SBXMLSec_ExtractRDN(reinterpret_cast<const sb_char16_t*>(u16Data.data()), (int32_t)u16Data.length() >> 1, (RDN != NULL) ? RDN->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELXMLDESCRIPTORMAP
SB_INLINE TElXMLDescriptorMapHandle RDNDescriptorMap()
{
	TElXMLDescriptorMapHandle OutResult;
	SBCheckError(SBXMLSec_RDNDescriptorMap(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDESCRIPTORMAP */

#endif /* SB_USE_GLOBAL_PROCS_XMLSEC */

};	/* namespace SecureBlackbox */

