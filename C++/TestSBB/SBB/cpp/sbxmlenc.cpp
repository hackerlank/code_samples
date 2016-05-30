#include "sbxmlenc.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELXMLENCRYPTEDTYPE

SB_INLINE void TElXMLEncryptedType::Clear()
{
	SBCheckError(TElXMLEncryptedType_Clear(_Handle));
}

bool TElXMLEncryptedType::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLEncryptedType_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLEncryptedType::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLEncryptedType_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLEncryptedType::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLEncryptedType_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLEncryptedType::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLEncryptedType_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLEncryptedType::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLEncryptedType_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLENCRYPTIONMETHODTYPE
TElXMLEncryptionMethodType* TElXMLEncryptedType::get_EncryptionMethod()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLEncryptedType_get_EncryptionMethod(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptionMethod)
		this->_Inst_EncryptionMethod = new TElXMLEncryptionMethodType(hOutResult, ohFalse);
	else
		this->_Inst_EncryptionMethod->updateHandle(hOutResult);
	return this->_Inst_EncryptionMethod;
}

SB_INLINE void TElXMLEncryptedType::set_EncryptionMethod(TElXMLEncryptionMethodType &Value)
{
	SBCheckError(TElXMLEncryptedType_set_EncryptionMethod(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLEncryptedType::set_EncryptionMethod(TElXMLEncryptionMethodType *Value)
{
	SBCheckError(TElXMLEncryptedType_set_EncryptionMethod(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLENCRYPTIONMETHODTYPE */

#ifdef SB_USE_CLASS_TELXMLCIPHERDATA
TElXMLCipherData* TElXMLEncryptedType::get_CipherData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLEncryptedType_get_CipherData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CipherData)
		this->_Inst_CipherData = new TElXMLCipherData(hOutResult, ohFalse);
	else
		this->_Inst_CipherData->updateHandle(hOutResult);
	return this->_Inst_CipherData;
}

SB_INLINE void TElXMLEncryptedType::set_CipherData(TElXMLCipherData &Value)
{
	SBCheckError(TElXMLEncryptedType_set_CipherData(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLEncryptedType::set_CipherData(TElXMLCipherData *Value)
{
	SBCheckError(TElXMLEncryptedType_set_CipherData(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLCIPHERDATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFO
TElXMLKeyInfo* TElXMLEncryptedType::get_KeyInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLEncryptedType_get_KeyInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyInfo)
		this->_Inst_KeyInfo = new TElXMLKeyInfo(hOutResult, ohFalse);
	else
		this->_Inst_KeyInfo->updateHandle(hOutResult);
	return this->_Inst_KeyInfo;
}

SB_INLINE void TElXMLEncryptedType::set_KeyInfo(TElXMLKeyInfo &Value)
{
	SBCheckError(TElXMLEncryptedType_set_KeyInfo(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLEncryptedType::set_KeyInfo(TElXMLKeyInfo *Value)
{
	SBCheckError(TElXMLEncryptedType_set_KeyInfo(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLKEYINFO */

#ifdef SB_USE_CLASS_TELXMLENCRYPTIONPROPERTIES
TElXMLEncryptionProperties* TElXMLEncryptedType::get_EncryptionProperties()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLEncryptedType_get_EncryptionProperties(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptionProperties)
		this->_Inst_EncryptionProperties = new TElXMLEncryptionProperties(hOutResult, ohFalse);
	else
		this->_Inst_EncryptionProperties->updateHandle(hOutResult);
	return this->_Inst_EncryptionProperties;
}

SB_INLINE void TElXMLEncryptedType::set_EncryptionProperties(TElXMLEncryptionProperties &Value)
{
	SBCheckError(TElXMLEncryptedType_set_EncryptionProperties(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLEncryptedType::set_EncryptionProperties(TElXMLEncryptionProperties *Value)
{
	SBCheckError(TElXMLEncryptedType_set_EncryptionProperties(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLENCRYPTIONPROPERTIES */

void TElXMLEncryptedType::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLEncryptedType_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(324453097, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLEncryptedType::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLEncryptedType_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(324453097, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLEncryptedType::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLEncryptedType_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLEncryptedType::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLEncryptedType_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLEncryptedType::get_DataType(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLEncryptedType_get_DataType(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1834060141, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLEncryptedType::get_DataType(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLEncryptedType_get_DataType(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1834060141, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLEncryptedType::set_DataType(const sb_u16string &Value)
{
	SBCheckError(TElXMLEncryptedType_set_DataType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLEncryptedType::set_DataType(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLEncryptedType_set_DataType(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLEncryptedType::get_MimeType(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLEncryptedType_get_MimeType(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1868027470, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLEncryptedType::get_MimeType(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLEncryptedType_get_MimeType(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1868027470, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLEncryptedType::set_MimeType(const sb_u16string &Value)
{
	SBCheckError(TElXMLEncryptedType_set_MimeType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLEncryptedType::set_MimeType(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLEncryptedType_set_MimeType(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLEncryptedType::get_Encoding(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLEncryptedType_get_Encoding(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(538079354, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLEncryptedType::get_Encoding(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLEncryptedType_get_Encoding(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(538079354, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLEncryptedType::set_Encoding(const sb_u16string &Value)
{
	SBCheckError(TElXMLEncryptedType_set_Encoding(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLEncryptedType::set_Encoding(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLEncryptedType_set_Encoding(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElXMLEncryptedType::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLEncryptedType_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElXMLEncryptedType::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElXMLEncryptedType_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLEncryptedType::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElXMLEncryptedType_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

void TElXMLEncryptedType::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLENCRYPTIONMETHODTYPE
	this->_Inst_EncryptionMethod = NULL;
#endif /* SB_USE_CLASS_TELXMLENCRYPTIONMETHODTYPE */
#ifdef SB_USE_CLASS_TELXMLCIPHERDATA
	this->_Inst_CipherData = NULL;
#endif /* SB_USE_CLASS_TELXMLCIPHERDATA */
#ifdef SB_USE_CLASS_TELXMLKEYINFO
	this->_Inst_KeyInfo = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFO */
#ifdef SB_USE_CLASS_TELXMLENCRYPTIONPROPERTIES
	this->_Inst_EncryptionProperties = NULL;
#endif /* SB_USE_CLASS_TELXMLENCRYPTIONPROPERTIES */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}

TElXMLEncryptedType::TElXMLEncryptedType(TElXMLEncryptedTypeHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
	initInstances();
}

TElXMLEncryptedType::TElXMLEncryptedType() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLEncryptedType_Create(&_Handle));
}

TElXMLEncryptedType::~TElXMLEncryptedType()
{
#ifdef SB_USE_CLASS_TELXMLENCRYPTIONMETHODTYPE
	delete this->_Inst_EncryptionMethod;
	this->_Inst_EncryptionMethod = NULL;
#endif /* SB_USE_CLASS_TELXMLENCRYPTIONMETHODTYPE */
#ifdef SB_USE_CLASS_TELXMLCIPHERDATA
	delete this->_Inst_CipherData;
	this->_Inst_CipherData = NULL;
#endif /* SB_USE_CLASS_TELXMLCIPHERDATA */
#ifdef SB_USE_CLASS_TELXMLKEYINFO
	delete this->_Inst_KeyInfo;
	this->_Inst_KeyInfo = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFO */
#ifdef SB_USE_CLASS_TELXMLENCRYPTIONPROPERTIES
	delete this->_Inst_EncryptionProperties;
	this->_Inst_EncryptionProperties = NULL;
#endif /* SB_USE_CLASS_TELXMLENCRYPTIONPROPERTIES */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}
#endif /* SB_USE_CLASS_TELXMLENCRYPTEDTYPE */

#ifdef SB_USE_CLASS_TELXMLENCPROCESSOR

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
TElXMLKeyInfoData* TElXMLEncProcessor::get_KeyEncryptionKeyData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLEncProcessor_get_KeyEncryptionKeyData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyEncryptionKeyData)
		this->_Inst_KeyEncryptionKeyData = new TElXMLKeyInfoData(hOutResult, ohFalse);
	else
		this->_Inst_KeyEncryptionKeyData->updateHandle(hOutResult);
	return this->_Inst_KeyEncryptionKeyData;
}

SB_INLINE void TElXMLEncProcessor::set_KeyEncryptionKeyData(TElXMLKeyInfoData &Value)
{
	SBCheckError(TElXMLEncProcessor_set_KeyEncryptionKeyData(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLEncProcessor::set_KeyEncryptionKeyData(TElXMLKeyInfoData *Value)
{
	SBCheckError(TElXMLEncProcessor_set_KeyEncryptionKeyData(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELXMLENCRYPTEDDATA
TElXMLEncryptedData* TElXMLEncProcessor::get_EncryptedData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLEncProcessor_get_EncryptedData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptedData)
		this->_Inst_EncryptedData = new TElXMLEncryptedData(hOutResult, ohFalse);
	else
		this->_Inst_EncryptedData->updateHandle(hOutResult);
	return this->_Inst_EncryptedData;
}

SB_INLINE void TElXMLEncProcessor::set_EncryptedData(TElXMLEncryptedData &Value)
{
	SBCheckError(TElXMLEncProcessor_set_EncryptedData(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLEncProcessor::set_EncryptedData(TElXMLEncryptedData *Value)
{
	SBCheckError(TElXMLEncProcessor_set_EncryptedData(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLENCRYPTEDDATA */

void TElXMLEncProcessor::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
	this->_Inst_KeyEncryptionKeyData = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
#ifdef SB_USE_CLASS_TELXMLENCRYPTEDDATA
	this->_Inst_EncryptedData = NULL;
#endif /* SB_USE_CLASS_TELXMLENCRYPTEDDATA */
}

TElXMLEncProcessor::TElXMLEncProcessor(TElXMLEncProcessorHandle handle, TElOwnHandle ownHandle) : TElXMLProcessor(handle, ownHandle)
{
	initInstances();
}

TElXMLEncProcessor::TElXMLEncProcessor(TComponent &AOwner) : TElXMLProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLEncProcessor_Create(AOwner.getHandle(), &_Handle));
}

TElXMLEncProcessor::TElXMLEncProcessor(TComponent *AOwner) : TElXMLProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLEncProcessor_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElXMLEncProcessor::~TElXMLEncProcessor()
{
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
	delete this->_Inst_KeyEncryptionKeyData;
	this->_Inst_KeyEncryptionKeyData = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
#ifdef SB_USE_CLASS_TELXMLENCRYPTEDDATA
	delete this->_Inst_EncryptedData;
	this->_Inst_EncryptedData = NULL;
#endif /* SB_USE_CLASS_TELXMLENCRYPTEDDATA */
}
#endif /* SB_USE_CLASS_TELXMLENCPROCESSOR */

#ifdef SB_USE_CLASS_TELXMLENCRYPTOR

#ifdef SB_USE_CLASS_TELXMLDOMNODE
SB_INLINE void TElXMLEncryptor::Encrypt(const TElXMLDOMNode &Data)
{
	SBCheckError(TElXMLEncryptor_Encrypt(_Handle, Data.getHandle()));
}

SB_INLINE void TElXMLEncryptor::Encrypt(const TElXMLDOMNode *Data)
{
	SBCheckError(TElXMLEncryptor_Encrypt(_Handle, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
SB_INLINE void TElXMLEncryptor::Encrypt(const TElXMLDOMNodeList &Data)
{
	SBCheckError(TElXMLEncryptor_Encrypt_1(_Handle, Data.getHandle()));
}

SB_INLINE void TElXMLEncryptor::Encrypt(const TElXMLDOMNodeList *Data)
{
	SBCheckError(TElXMLEncryptor_Encrypt_1(_Handle, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */

SB_INLINE void TElXMLEncryptor::Encrypt(const std::vector<uint8_t> &Data)
{
	SBCheckError(TElXMLEncryptor_Encrypt_2(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size()));
}

#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLEncryptor::Save(const TElXMLDOMDocument &Document)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLEncryptor_Save(_Handle, Document.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLEncryptor::Save(const TElXMLDOMDocument *Document)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLEncryptor_Save(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE TElXMLDOMDocumentHandle TElXMLEncryptor::SaveToDocument()
{
	TElXMLDOMDocumentHandle OutResult;
	SBCheckError(TElXMLEncryptor_SaveToDocument(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
TElXMLKeyInfoData* TElXMLEncryptor::get_KeyData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLEncryptor_get_KeyData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyData)
		this->_Inst_KeyData = new TElXMLKeyInfoData(hOutResult, ohFalse);
	else
		this->_Inst_KeyData->updateHandle(hOutResult);
	return this->_Inst_KeyData;
}

SB_INLINE void TElXMLEncryptor::set_KeyData(TElXMLKeyInfoData &Value)
{
	SBCheckError(TElXMLEncryptor_set_KeyData(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLEncryptor::set_KeyData(TElXMLKeyInfoData *Value)
{
	SBCheckError(TElXMLEncryptor_set_KeyData(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

bool TElXMLEncryptor::get_EncryptKey()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLEncryptor_get_EncryptKey(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLEncryptor::set_EncryptKey(bool Value)
{
	SBCheckError(TElXMLEncryptor_set_EncryptKey(_Handle, (int8_t)Value));
}

void TElXMLEncryptor::get_KeyName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLEncryptor_get_KeyName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1623400077, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLEncryptor::get_KeyName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLEncryptor_get_KeyName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1623400077, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLEncryptor::set_KeyName(const sb_u16string &Value)
{
	SBCheckError(TElXMLEncryptor_set_KeyName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLEncryptor::set_KeyName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLEncryptor_set_KeyName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLEncryptedDataType TElXMLEncryptor::get_EncryptedDataType()
{
	TElXMLEncryptedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLEncryptor_get_EncryptedDataType(_Handle, &OutResultRaw));
	return (TElXMLEncryptedDataType)OutResultRaw;
}

SB_INLINE void TElXMLEncryptor::set_EncryptedDataType(TElXMLEncryptedDataType Value)
{
	SBCheckError(TElXMLEncryptor_set_EncryptedDataType(_Handle, (TElXMLEncryptedDataTypeRaw)Value));
}

TElXMLEncryptionMethod TElXMLEncryptor::get_EncryptionMethod()
{
	TElXMLEncryptionMethodRaw OutResultRaw = 0;
	SBCheckError(TElXMLEncryptor_get_EncryptionMethod(_Handle, &OutResultRaw));
	return (TElXMLEncryptionMethod)OutResultRaw;
}

SB_INLINE void TElXMLEncryptor::set_EncryptionMethod(TElXMLEncryptionMethod Value)
{
	SBCheckError(TElXMLEncryptor_set_EncryptionMethod(_Handle, (TElXMLEncryptionMethodRaw)Value));
}

TElXMLKeyEncryptionType TElXMLEncryptor::get_KeyEncryptionType()
{
	TElXMLKeyEncryptionTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLEncryptor_get_KeyEncryptionType(_Handle, &OutResultRaw));
	return (TElXMLKeyEncryptionType)OutResultRaw;
}

SB_INLINE void TElXMLEncryptor::set_KeyEncryptionType(TElXMLKeyEncryptionType Value)
{
	SBCheckError(TElXMLEncryptor_set_KeyEncryptionType(_Handle, (TElXMLKeyEncryptionTypeRaw)Value));
}

TElXMLKeyTransportMethod TElXMLEncryptor::get_KeyTransportMethod()
{
	TElXMLKeyTransportMethodRaw OutResultRaw = 0;
	SBCheckError(TElXMLEncryptor_get_KeyTransportMethod(_Handle, &OutResultRaw));
	return (TElXMLKeyTransportMethod)OutResultRaw;
}

SB_INLINE void TElXMLEncryptor::set_KeyTransportMethod(TElXMLKeyTransportMethod Value)
{
	SBCheckError(TElXMLEncryptor_set_KeyTransportMethod(_Handle, (TElXMLKeyTransportMethodRaw)Value));
}

TElXMLKeyWrapMethod TElXMLEncryptor::get_KeyWrapMethod()
{
	TElXMLKeyWrapMethodRaw OutResultRaw = 0;
	SBCheckError(TElXMLEncryptor_get_KeyWrapMethod(_Handle, &OutResultRaw));
	return (TElXMLKeyWrapMethod)OutResultRaw;
}

SB_INLINE void TElXMLEncryptor::set_KeyWrapMethod(TElXMLKeyWrapMethod Value)
{
	SBCheckError(TElXMLEncryptor_set_KeyWrapMethod(_Handle, (TElXMLKeyWrapMethodRaw)Value));
}

bool TElXMLEncryptor::get_IncludeKeyEncryptionKey()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLEncryptor_get_IncludeKeyEncryptionKey(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLEncryptor::set_IncludeKeyEncryptionKey(bool Value)
{
	SBCheckError(TElXMLEncryptor_set_IncludeKeyEncryptionKey(_Handle, (int8_t)Value));
}

void TElXMLEncryptor::get_MimeType(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLEncryptor_get_MimeType(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1783066900, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLEncryptor::get_MimeType(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLEncryptor_get_MimeType(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1783066900, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLEncryptor::set_MimeType(const sb_u16string &Value)
{
	SBCheckError(TElXMLEncryptor_set_MimeType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLEncryptor::set_MimeType(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLEncryptor_set_MimeType(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLEncryptor::get_OnFormatElement(TSBXMLFormatElementEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXMLEncryptor_get_OnFormatElement(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXMLEncryptor::set_OnFormatElement(TSBXMLFormatElementEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXMLEncryptor_set_OnFormatElement(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElXMLEncryptor::get_OnFormatText(TSBXMLFormatTextEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXMLEncryptor_get_OnFormatText(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXMLEncryptor::set_OnFormatText(TSBXMLFormatTextEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXMLEncryptor_set_OnFormatText(_Handle, pMethodValue, pDataValue));
}

void TElXMLEncryptor::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
	this->_Inst_KeyData = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
}

TElXMLEncryptor::TElXMLEncryptor(TElXMLEncryptorHandle handle, TElOwnHandle ownHandle) : TElXMLEncProcessor(handle, ownHandle)
{
	initInstances();
}

TElXMLEncryptor::TElXMLEncryptor(TComponent &AOwner) : TElXMLEncProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLEncryptor_Create(AOwner.getHandle(), &_Handle));
}

TElXMLEncryptor::TElXMLEncryptor(TComponent *AOwner) : TElXMLEncProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLEncryptor_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElXMLEncryptor::~TElXMLEncryptor()
{
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
	delete this->_Inst_KeyData;
	this->_Inst_KeyData = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
}
#endif /* SB_USE_CLASS_TELXMLENCRYPTOR */

#ifdef SB_USE_CLASS_TELXMLDECRYPTOR

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE int32_t TElXMLDecryptor::Decrypt(const TElXMLDOMDocument &OwnerDocument)
{
	int32_t OutResult;
	SBCheckError(TElXMLDecryptor_Decrypt(_Handle, OwnerDocument.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLDecryptor::Decrypt(const TElXMLDOMDocument *OwnerDocument)
{
	int32_t OutResult;
	SBCheckError(TElXMLDecryptor_Decrypt(_Handle, (OwnerDocument != NULL) ? OwnerDocument->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLDecryptor::Load(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLDecryptor_Load(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLDecryptor::Load(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLDecryptor_Load(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE void TElXMLDecryptor::Load(TElXMLDOMDocument &Document)
{
	SBCheckError(TElXMLDecryptor_Load_1(_Handle, Document.getHandle()));
}

SB_INLINE void TElXMLDecryptor::Load(TElXMLDOMDocument *Document)
{
	SBCheckError(TElXMLDecryptor_Load_1(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TElXMLDOMNode* TElXMLDecryptor::get_DecryptedNode()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLDecryptor_get_DecryptedNode(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DecryptedNode)
		this->_Inst_DecryptedNode = new TElXMLDOMNode(hOutResult, ohFalse);
	else
		this->_Inst_DecryptedNode->updateHandle(hOutResult);
	return this->_Inst_DecryptedNode;
}

SB_INLINE void TElXMLDecryptor::set_DecryptedNode(TElXMLDOMNode &Value)
{
	SBCheckError(TElXMLDecryptor_set_DecryptedNode(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLDecryptor::set_DecryptedNode(TElXMLDOMNode *Value)
{
	SBCheckError(TElXMLDecryptor_set_DecryptedNode(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
TElXMLDOMNodeList* TElXMLDecryptor::get_DecryptedNodeList()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLDecryptor_get_DecryptedNodeList(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DecryptedNodeList)
		this->_Inst_DecryptedNodeList = new TElXMLDOMNodeList(hOutResult, ohFalse);
	else
		this->_Inst_DecryptedNodeList->updateHandle(hOutResult);
	return this->_Inst_DecryptedNodeList;
}

SB_INLINE void TElXMLDecryptor::set_DecryptedNodeList(TElXMLDOMNodeList &Value)
{
	SBCheckError(TElXMLDecryptor_set_DecryptedNodeList(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLDecryptor::set_DecryptedNodeList(TElXMLDOMNodeList *Value)
{
	SBCheckError(TElXMLDecryptor_set_DecryptedNodeList(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */

void TElXMLDecryptor::get_DecryptedData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLDecryptor_get_DecryptedData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1463497944, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElXMLDecryptor::set_DecryptedData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElXMLDecryptor_set_DecryptedData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElXMLEncryptedDataType TElXMLDecryptor::get_EncryptedDataType()
{
	TElXMLEncryptedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLDecryptor_get_EncryptedDataType(_Handle, &OutResultRaw));
	return (TElXMLEncryptedDataType)OutResultRaw;
}

TElXMLEncryptionMethod TElXMLDecryptor::get_EncryptionMethod()
{
	TElXMLEncryptionMethodRaw OutResultRaw = 0;
	SBCheckError(TElXMLDecryptor_get_EncryptionMethod(_Handle, &OutResultRaw));
	return (TElXMLEncryptionMethod)OutResultRaw;
}

bool TElXMLDecryptor::get_EncryptKey()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLDecryptor_get_EncryptKey(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElXMLDecryptor::get_KeyName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDecryptor_get_KeyName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-848624021, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDecryptor::get_KeyName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDecryptor_get_KeyName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-848624021, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
TElXMLKeyEncryptionType TElXMLDecryptor::get_KeyEncryptionType()
{
	TElXMLKeyEncryptionTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLDecryptor_get_KeyEncryptionType(_Handle, &OutResultRaw));
	return (TElXMLKeyEncryptionType)OutResultRaw;
}

TElXMLKeyTransportMethod TElXMLDecryptor::get_KeyTransportMethod()
{
	TElXMLKeyTransportMethodRaw OutResultRaw = 0;
	SBCheckError(TElXMLDecryptor_get_KeyTransportMethod(_Handle, &OutResultRaw));
	return (TElXMLKeyTransportMethod)OutResultRaw;
}

TElXMLKeyWrapMethod TElXMLDecryptor::get_KeyWrapMethod()
{
	TElXMLKeyWrapMethodRaw OutResultRaw = 0;
	SBCheckError(TElXMLDecryptor_get_KeyWrapMethod(_Handle, &OutResultRaw));
	return (TElXMLKeyWrapMethod)OutResultRaw;
}

void TElXMLDecryptor::get_MimeType(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDecryptor_get_MimeType(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(595828289, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDecryptor::get_MimeType(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDecryptor_get_MimeType(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(595828289, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
TElXMLKeyInfoData* TElXMLDecryptor::get_KeyData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLDecryptor_get_KeyData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyData)
		this->_Inst_KeyData = new TElXMLKeyInfoData(hOutResult, ohFalse);
	else
		this->_Inst_KeyData->updateHandle(hOutResult);
	return this->_Inst_KeyData;
}

SB_INLINE void TElXMLDecryptor::set_KeyData(TElXMLKeyInfoData &Value)
{
	SBCheckError(TElXMLDecryptor_set_KeyData(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLDecryptor::set_KeyData(TElXMLKeyInfoData *Value)
{
	SBCheckError(TElXMLDecryptor_set_KeyData(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

void TElXMLDecryptor::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	this->_Inst_DecryptedNode = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
	this->_Inst_DecryptedNodeList = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
	this->_Inst_KeyData = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
}

TElXMLDecryptor::TElXMLDecryptor(TElXMLDecryptorHandle handle, TElOwnHandle ownHandle) : TElXMLEncProcessor(handle, ownHandle)
{
	initInstances();
}

TElXMLDecryptor::TElXMLDecryptor(TComponent &AOwner) : TElXMLEncProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLDecryptor_Create(AOwner.getHandle(), &_Handle));
}

TElXMLDecryptor::TElXMLDecryptor(TComponent *AOwner) : TElXMLEncProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLDecryptor_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElXMLDecryptor::~TElXMLDecryptor()
{
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	delete this->_Inst_DecryptedNode;
	this->_Inst_DecryptedNode = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
	delete this->_Inst_DecryptedNodeList;
	this->_Inst_DecryptedNodeList = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
	delete this->_Inst_KeyData;
	this->_Inst_KeyData = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
}
#endif /* SB_USE_CLASS_TELXMLDECRYPTOR */

#ifdef SB_USE_CLASS_TELXMLCIPHERREFERENCE

SB_INLINE void TElXMLCipherReference::Clear()
{
	SBCheckError(TElXMLCipherReference_Clear(_Handle));
}

bool TElXMLCipherReference::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLCipherReference_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLCipherReference::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLCipherReference_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLCipherReference::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLCipherReference_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLCipherReference::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCipherReference_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLCipherReference::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCipherReference_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLCipherReference::get_CipherValue(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLCipherReference_get_CipherValue(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1299575299, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElXMLCipherReference::set_CipherValue(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElXMLCipherReference_set_CipherValue(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
TElXMLTransformChain* TElXMLCipherReference::get_TransformChain()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCipherReference_get_TransformChain(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TransformChain)
		this->_Inst_TransformChain = new TElXMLTransformChain(hOutResult, ohFalse);
	else
		this->_Inst_TransformChain->updateHandle(hOutResult);
	return this->_Inst_TransformChain;
}

SB_INLINE void TElXMLCipherReference::set_TransformChain(TElXMLTransformChain &Value)
{
	SBCheckError(TElXMLCipherReference_set_TransformChain(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLCipherReference::set_TransformChain(TElXMLTransformChain *Value)
{
	SBCheckError(TElXMLCipherReference_set_TransformChain(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */

void TElXMLCipherReference::get_URI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLCipherReference_get_URI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1832365826, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLCipherReference::get_URI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLCipherReference_get_URI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1832365826, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLCipherReference::set_URI(const sb_u16string &Value)
{
	SBCheckError(TElXMLCipherReference_set_URI(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLCipherReference::set_URI(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLCipherReference_set_URI(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLCipherReference::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
	this->_Inst_TransformChain = NULL;
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */
}

TElXMLCipherReference::TElXMLCipherReference(TElXMLCipherReferenceHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
	initInstances();
}

TElXMLCipherReference::TElXMLCipherReference() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCipherReference_Create(&_Handle));
}

TElXMLCipherReference::~TElXMLCipherReference()
{
#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
	delete this->_Inst_TransformChain;
	this->_Inst_TransformChain = NULL;
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */
}
#endif /* SB_USE_CLASS_TELXMLCIPHERREFERENCE */

#ifdef SB_USE_CLASS_TELXMLCIPHERDATA

SB_INLINE void TElXMLCipherData::Clear()
{
	SBCheckError(TElXMLCipherData_Clear(_Handle));
}

bool TElXMLCipherData::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLCipherData_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLCipherData::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLCipherData_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLCipherData::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLCipherData_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLCipherData::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCipherData_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLCipherData::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCipherData_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLCipherData::get_CipherValue(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLCipherData_get_CipherValue(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(438862234, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElXMLCipherData::set_CipherValue(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElXMLCipherData_set_CipherValue(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELXMLCIPHERREFERENCE
TElXMLCipherReference* TElXMLCipherData::get_CipherReference()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCipherData_get_CipherReference(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CipherReference)
		this->_Inst_CipherReference = new TElXMLCipherReference(hOutResult, ohFalse);
	else
		this->_Inst_CipherReference->updateHandle(hOutResult);
	return this->_Inst_CipherReference;
}

SB_INLINE void TElXMLCipherData::set_CipherReference(TElXMLCipherReference &Value)
{
	SBCheckError(TElXMLCipherData_set_CipherReference(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLCipherData::set_CipherReference(TElXMLCipherReference *Value)
{
	SBCheckError(TElXMLCipherData_set_CipherReference(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLCIPHERREFERENCE */

void TElXMLCipherData::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLCIPHERREFERENCE
	this->_Inst_CipherReference = NULL;
#endif /* SB_USE_CLASS_TELXMLCIPHERREFERENCE */
}

TElXMLCipherData::TElXMLCipherData(TElXMLCipherDataHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
	initInstances();
}

TElXMLCipherData::TElXMLCipherData() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCipherData_Create(&_Handle));
}

TElXMLCipherData::~TElXMLCipherData()
{
#ifdef SB_USE_CLASS_TELXMLCIPHERREFERENCE
	delete this->_Inst_CipherReference;
	this->_Inst_CipherReference = NULL;
#endif /* SB_USE_CLASS_TELXMLCIPHERREFERENCE */
}
#endif /* SB_USE_CLASS_TELXMLCIPHERDATA */

#ifdef SB_USE_CLASS_TELXMLENCRYPTIONMETHODTYPE

SB_INLINE void TElXMLEncryptionMethodType::Clear()
{
	SBCheckError(TElXMLEncryptionMethodType_Clear(_Handle));
}

bool TElXMLEncryptionMethodType::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLEncryptionMethodType_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLEncryptionMethodType::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLEncryptionMethodType_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLEncryptionMethodType::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLEncryptionMethodType_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLEncryptionMethodType::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLEncryptionMethodType_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLEncryptionMethodType::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLEncryptionMethodType_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLEncryptionMethodType::get_Algorithm(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLEncryptionMethodType_get_Algorithm(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(390029065, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLEncryptionMethodType::get_Algorithm(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLEncryptionMethodType_get_Algorithm(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(390029065, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLEncryptionMethodType::set_Algorithm(const sb_u16string &Value)
{
	SBCheckError(TElXMLEncryptionMethodType_set_Algorithm(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLEncryptionMethodType::set_Algorithm(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLEncryptionMethodType_set_Algorithm(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE int32_t TElXMLEncryptionMethodType::get_KeySize()
{
	int32_t OutResult;
	SBCheckError(TElXMLEncryptionMethodType_get_KeySize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLEncryptionMethodType::set_KeySize(int32_t Value)
{
	SBCheckError(TElXMLEncryptionMethodType_set_KeySize(_Handle, Value));
}

void TElXMLEncryptionMethodType::get_OAEPparams(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLEncryptionMethodType_get_OAEPparams(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1875561523, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElXMLEncryptionMethodType::set_OAEPparams(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElXMLEncryptionMethodType_set_OAEPparams(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElXMLEncryptionMethodType::get_DigestMethod(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLEncryptionMethodType_get_DigestMethod(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(711407890, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLEncryptionMethodType::get_DigestMethod(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLEncryptionMethodType_get_DigestMethod(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(711407890, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLEncryptionMethodType::set_DigestMethod(const sb_u16string &Value)
{
	SBCheckError(TElXMLEncryptionMethodType_set_DigestMethod(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLEncryptionMethodType::set_DigestMethod(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLEncryptionMethodType_set_DigestMethod(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLEncryptionMethodType::TElXMLEncryptionMethodType(TElXMLEncryptionMethodTypeHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
}

TElXMLEncryptionMethodType::TElXMLEncryptionMethodType() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLEncryptionMethodType_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLENCRYPTIONMETHODTYPE */

#ifdef SB_USE_CLASS_TELXMLENCRYPTIONPROPERTIES

TElXMLEncryptionProperties::TElXMLEncryptionProperties(TElXMLEncryptionPropertiesHandle handle, TElOwnHandle ownHandle) : TElXMLProperties(handle, ownHandle)
{
}

TElXMLEncryptionProperties::TElXMLEncryptionProperties() : TElXMLProperties(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLEncryptionProperties_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLENCRYPTIONPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLENCRYPTEDDATA

SB_INLINE void TElXMLEncryptedData::Clear()
{
	SBCheckError(TElXMLEncryptedData_Clear(_Handle));
}

bool TElXMLEncryptedData::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLEncryptedData_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLEncryptedData::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLEncryptedData_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLEncryptedData::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLEncryptedData_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLEncryptedData::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLEncryptedData_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLEncryptedData::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLEncryptedData_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLEncryptedData::get_EncryptionPrefix(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLEncryptedData_get_EncryptionPrefix(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1281309286, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLEncryptedData::get_EncryptionPrefix(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLEncryptedData_get_EncryptionPrefix(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1281309286, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLEncryptedData::set_EncryptionPrefix(const sb_u16string &Value)
{
	SBCheckError(TElXMLEncryptedData_set_EncryptionPrefix(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLEncryptedData::set_EncryptionPrefix(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLEncryptedData_set_EncryptionPrefix(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLEncryptedData::get_SignaturePrefix(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLEncryptedData_get_SignaturePrefix(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-738130000, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLEncryptedData::get_SignaturePrefix(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLEncryptedData_get_SignaturePrefix(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-738130000, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLEncryptedData::set_SignaturePrefix(const sb_u16string &Value)
{
	SBCheckError(TElXMLEncryptedData_set_SignaturePrefix(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLEncryptedData::set_SignaturePrefix(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLEncryptedData_set_SignaturePrefix(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLENCRYPTEDKEY
TElXMLEncryptedKey* TElXMLEncryptedData::get_EncryptedKey()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLEncryptedData_get_EncryptedKey(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptedKey)
		this->_Inst_EncryptedKey = new TElXMLEncryptedKey(hOutResult, ohFalse);
	else
		this->_Inst_EncryptedKey->updateHandle(hOutResult);
	return this->_Inst_EncryptedKey;
}

SB_INLINE void TElXMLEncryptedData::set_EncryptedKey(TElXMLEncryptedKey &Value)
{
	SBCheckError(TElXMLEncryptedData_set_EncryptedKey(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLEncryptedData::set_EncryptedKey(TElXMLEncryptedKey *Value)
{
	SBCheckError(TElXMLEncryptedData_set_EncryptedKey(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLENCRYPTEDKEY */

void TElXMLEncryptedData::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLENCRYPTEDKEY
	this->_Inst_EncryptedKey = NULL;
#endif /* SB_USE_CLASS_TELXMLENCRYPTEDKEY */
}

TElXMLEncryptedData::TElXMLEncryptedData(TElXMLEncryptedDataHandle handle, TElOwnHandle ownHandle) : TElXMLEncryptedType(handle, ownHandle)
{
	initInstances();
}

TElXMLEncryptedData::TElXMLEncryptedData() : TElXMLEncryptedType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLEncryptedData_Create(&_Handle));
}

TElXMLEncryptedData::~TElXMLEncryptedData()
{
#ifdef SB_USE_CLASS_TELXMLENCRYPTEDKEY
	delete this->_Inst_EncryptedKey;
	this->_Inst_EncryptedKey = NULL;
#endif /* SB_USE_CLASS_TELXMLENCRYPTEDKEY */
}
#endif /* SB_USE_CLASS_TELXMLENCRYPTEDDATA */

#ifdef SB_USE_CLASS_TELXMLENCRYPTEDKEY

SB_INLINE void TElXMLEncryptedKey::Clear()
{
	SBCheckError(TElXMLEncryptedKey_Clear(_Handle));
}

bool TElXMLEncryptedKey::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLEncryptedKey_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLEncryptedKey::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLEncryptedKey_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLEncryptedKey::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLEncryptedKey_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLEncryptedKey::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLEncryptedKey_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLEncryptedKey::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLEncryptedKey_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLEncryptedKey::get_CarriedKeyName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLEncryptedKey_get_CarriedKeyName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-282694000, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLEncryptedKey::get_CarriedKeyName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLEncryptedKey_get_CarriedKeyName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-282694000, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLEncryptedKey::set_CarriedKeyName(const sb_u16string &Value)
{
	SBCheckError(TElXMLEncryptedKey_set_CarriedKeyName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLEncryptedKey::set_CarriedKeyName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLEncryptedKey_set_CarriedKeyName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLEncryptedKey::get_Recipient(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLEncryptedKey_get_Recipient(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1814385260, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLEncryptedKey::get_Recipient(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLEncryptedKey_get_Recipient(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1814385260, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLEncryptedKey::set_Recipient(const sb_u16string &Value)
{
	SBCheckError(TElXMLEncryptedKey_set_Recipient(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLEncryptedKey::set_Recipient(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLEncryptedKey_set_Recipient(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLEncryptedKey::TElXMLEncryptedKey(TElXMLEncryptedKeyHandle handle, TElOwnHandle ownHandle) : TElXMLEncryptedType(handle, ownHandle)
{
}

TElXMLEncryptedKey::TElXMLEncryptedKey() : TElXMLEncryptedType(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLEncryptedKey_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLENCRYPTEDKEY */

#ifdef SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT

SB_INLINE TElXMLDecryptionExceptHandle TElXMLDecryptionExcept::Clone()
{
	TElXMLDecryptionExceptHandle OutResult;
	SBCheckError(TElXMLDecryptionExcept_Clone(_Handle, &OutResult));
	return OutResult;
}

void TElXMLDecryptionExcept::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDecryptionExcept_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(124009306, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDecryptionExcept::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDecryptionExcept_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(124009306, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLDecryptionExcept::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLDecryptionExcept_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLDecryptionExcept::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLDecryptionExcept_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLDecryptionExcept::get_URI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDecryptionExcept_get_URI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1927427546, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDecryptionExcept::get_URI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDecryptionExcept_get_URI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1927427546, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLDecryptionExcept::set_URI(const sb_u16string &Value)
{
	SBCheckError(TElXMLDecryptionExcept_set_URI(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLDecryptionExcept::set_URI(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLDecryptionExcept_set_URI(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLDecryptionExcept::TElXMLDecryptionExcept(TElXMLDecryptionExceptHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElXMLDecryptionExcept::TElXMLDecryptionExcept() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLDecryptionExcept_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT */

#ifdef SB_USE_CLASS_TELXMLCUSTOMDECRYPTIONTRANSFORM

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLCustomDecryptionTransform::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLCustomDecryptionTransform_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLCustomDecryptionTransform::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLCustomDecryptionTransform_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLCustomDecryptionTransform::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCustomDecryptionTransform_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLCustomDecryptionTransform::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCustomDecryptionTransform_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT
SB_INLINE int32_t TElXMLCustomDecryptionTransform::Add(TElXMLDecryptionExcept &AExcept)
{
	int32_t OutResult;
	SBCheckError(TElXMLCustomDecryptionTransform_Add(_Handle, AExcept.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLCustomDecryptionTransform::Add(TElXMLDecryptionExcept *AExcept)
{
	int32_t OutResult;
	SBCheckError(TElXMLCustomDecryptionTransform_Add(_Handle, (AExcept != NULL) ? AExcept->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT */

SB_INLINE int32_t TElXMLCustomDecryptionTransform::Add(const sb_u16string &ExceptID, const sb_u16string &ExceptURI)
{
	int32_t OutResult;
	SBCheckError(TElXMLCustomDecryptionTransform_Add_1(_Handle, ExceptID.data(), (int32_t)ExceptID.length(), ExceptURI.data(), (int32_t)ExceptURI.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLCustomDecryptionTransform::Add(const std::wstring &ExceptID, const std::wstring &ExceptURI)
{
	int32_t OutResult;
	std::string u16ExceptID;
	sb_to_u16string(ExceptID, u16ExceptID);
	std::string u16ExceptURI;
	sb_to_u16string(ExceptURI, u16ExceptURI);
	SBCheckError(TElXMLCustomDecryptionTransform_Add_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16ExceptID.data()), (int32_t)u16ExceptID.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16ExceptURI.data()), (int32_t)u16ExceptURI.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT
SB_INLINE void TElXMLCustomDecryptionTransform::Insert(int32_t Index, TElXMLDecryptionExcept &AExcept)
{
	SBCheckError(TElXMLCustomDecryptionTransform_Insert(_Handle, Index, AExcept.getHandle()));
}

SB_INLINE void TElXMLCustomDecryptionTransform::Insert(int32_t Index, TElXMLDecryptionExcept *AExcept)
{
	SBCheckError(TElXMLCustomDecryptionTransform_Insert(_Handle, Index, (AExcept != NULL) ? AExcept->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT */

SB_INLINE void TElXMLCustomDecryptionTransform::Delete(int32_t Index)
{
	SBCheckError(TElXMLCustomDecryptionTransform_Delete(_Handle, Index));
}

SB_INLINE void TElXMLCustomDecryptionTransform::Clear()
{
	SBCheckError(TElXMLCustomDecryptionTransform_Clear(_Handle));
}

SB_INLINE TClassHandle TElXMLCustomDecryptionTransform::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLCustomDecryptionTransform_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLCustomDecryptionTransform::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLCustomDecryptionTransform_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT
TElXMLDecryptionExcept* TElXMLCustomDecryptionTransform::get_Excepts(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCustomDecryptionTransform_get_Excepts(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Excepts)
		this->_Inst_Excepts = new TElXMLDecryptionExcept(hOutResult, ohFalse);
	else
		this->_Inst_Excepts->updateHandle(hOutResult);
	return this->_Inst_Excepts;
}
#endif /* SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
TElXMLKeyInfoData* TElXMLCustomDecryptionTransform::get_KeyData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCustomDecryptionTransform_get_KeyData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyData)
		this->_Inst_KeyData = new TElXMLKeyInfoData(hOutResult, ohFalse);
	else
		this->_Inst_KeyData->updateHandle(hOutResult);
	return this->_Inst_KeyData;
}

SB_INLINE void TElXMLCustomDecryptionTransform::set_KeyData(TElXMLKeyInfoData &Value)
{
	SBCheckError(TElXMLCustomDecryptionTransform_set_KeyData(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLCustomDecryptionTransform::set_KeyData(TElXMLKeyInfoData *Value)
{
	SBCheckError(TElXMLCustomDecryptionTransform_set_KeyData(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

SB_INLINE void TElXMLCustomDecryptionTransform::get_OnKeyData(TSBXMLDecryptKeyDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXMLCustomDecryptionTransform_get_OnKeyData(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXMLCustomDecryptionTransform::set_OnKeyData(TSBXMLDecryptKeyDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXMLCustomDecryptionTransform_set_OnKeyData(_Handle, pMethodValue, pDataValue));
}

void TElXMLCustomDecryptionTransform::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT
	this->_Inst_Excepts = NULL;
#endif /* SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT */
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
	this->_Inst_KeyData = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
}

TElXMLCustomDecryptionTransform::TElXMLCustomDecryptionTransform(TElXMLCustomDecryptionTransformHandle handle, TElOwnHandle ownHandle) : TElXMLTransform(handle, ownHandle)
{
	initInstances();
}

TElXMLCustomDecryptionTransform::TElXMLCustomDecryptionTransform() : TElXMLTransform(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCustomDecryptionTransform_Create(&_Handle));
}

TElXMLCustomDecryptionTransform::~TElXMLCustomDecryptionTransform()
{
#ifdef SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT
	delete this->_Inst_Excepts;
	this->_Inst_Excepts = NULL;
#endif /* SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT */
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
	delete this->_Inst_KeyData;
	this->_Inst_KeyData = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
}
#endif /* SB_USE_CLASS_TELXMLCUSTOMDECRYPTIONTRANSFORM */

#ifdef SB_USE_CLASS_TELXMLDECRYPTIONTRANSFORM

void TElXMLDecryptionTransform::GetDefaultTransformAlgorithmURI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDecryptionTransform_GetDefaultTransformAlgorithmURI((sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1005829047, 0, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLDecryptionTransform::GetDefaultTransformAlgorithmURI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDecryptionTransform_GetDefaultTransformAlgorithmURI(NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1005829047, 0, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElXMLDecryptionTransform::GetDefaultTransformAlgorithmURI_Inst(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDecryptionTransform_GetDefaultTransformAlgorithmURI_1(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1005829047, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLDecryptionTransform::GetDefaultTransformAlgorithmURI_Inst(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDecryptionTransform_GetDefaultTransformAlgorithmURI_1(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1005829047, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

bool TElXMLDecryptionTransform::IsTransformAlgorithmSupported(const sb_u16string &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLDecryptionTransform_IsTransformAlgorithmSupported(Algorithm.data(), (int32_t)Algorithm.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLDecryptionTransform::IsTransformAlgorithmSupported(const std::wstring &Algorithm)
{
	std::string u16Algorithm;
	sb_to_u16string(Algorithm, u16Algorithm);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLDecryptionTransform_IsTransformAlgorithmSupported(reinterpret_cast<const sb_char16_t*>(u16Algorithm.data()), (int32_t)u16Algorithm.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

bool TElXMLDecryptionTransform::IsTransformAlgorithmSupported_Inst(const sb_u16string &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLDecryptionTransform_IsTransformAlgorithmSupported_1(_Handle, Algorithm.data(), (int32_t)Algorithm.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLDecryptionTransform::IsTransformAlgorithmSupported_Inst(const std::wstring &Algorithm)
{
	std::string u16Algorithm;
	sb_to_u16string(Algorithm, u16Algorithm);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLDecryptionTransform_IsTransformAlgorithmSupported_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16Algorithm.data()), (int32_t)u16Algorithm.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

TSBTransformedDataType TElXMLDecryptionTransform::TransformData(const std::vector<uint8_t> &Data)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLDecryptionTransform_TransformData(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TSBTransformedDataType TElXMLDecryptionTransform::TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLDecryptionTransform_TransformData_1(_Handle, Node.getHandle(), Reference.getHandle(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

TSBTransformedDataType TElXMLDecryptionTransform::TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLDecryptionTransform_TransformData_1(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, (Reference != NULL) ? Reference->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
TSBTransformedDataType TElXMLDecryptionTransform::TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLDecryptionTransform_TransformData_2(_Handle, Nodes.getHandle(), SB_STD_VECTOR_FRONT_ADR(Reference), (int32_t)Reference.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

TSBTransformedDataType TElXMLDecryptionTransform::TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLDecryptionTransform_TransformData_2(_Handle, (Nodes != NULL) ? Nodes->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Reference), (int32_t)Reference.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

SB_INLINE TClassHandle TElXMLDecryptionTransform::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLDecryptionTransform_ClassType(&OutResult));
	return OutResult;
}

TElXMLDecryptionTransform::TElXMLDecryptionTransform(TElXMLDecryptionTransformHandle handle, TElOwnHandle ownHandle) : TElXMLCustomDecryptionTransform(handle, ownHandle)
{
}

TElXMLDecryptionTransform::TElXMLDecryptionTransform() : TElXMLCustomDecryptionTransform(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLDecryptionTransform_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLDECRYPTIONTRANSFORM */

#ifdef SB_USE_CLASS_TELXMLBINARYDECRYPTIONTRANSFORM

void TElXMLBinaryDecryptionTransform::GetDefaultTransformAlgorithmURI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLBinaryDecryptionTransform_GetDefaultTransformAlgorithmURI((sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-214616692, 0, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLBinaryDecryptionTransform::GetDefaultTransformAlgorithmURI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLBinaryDecryptionTransform_GetDefaultTransformAlgorithmURI(NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-214616692, 0, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElXMLBinaryDecryptionTransform::GetDefaultTransformAlgorithmURI_Inst(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLBinaryDecryptionTransform_GetDefaultTransformAlgorithmURI_1(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-214616692, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLBinaryDecryptionTransform::GetDefaultTransformAlgorithmURI_Inst(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLBinaryDecryptionTransform_GetDefaultTransformAlgorithmURI_1(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-214616692, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

bool TElXMLBinaryDecryptionTransform::IsTransformAlgorithmSupported(const sb_u16string &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLBinaryDecryptionTransform_IsTransformAlgorithmSupported(Algorithm.data(), (int32_t)Algorithm.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLBinaryDecryptionTransform::IsTransformAlgorithmSupported(const std::wstring &Algorithm)
{
	std::string u16Algorithm;
	sb_to_u16string(Algorithm, u16Algorithm);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLBinaryDecryptionTransform_IsTransformAlgorithmSupported(reinterpret_cast<const sb_char16_t*>(u16Algorithm.data()), (int32_t)u16Algorithm.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

bool TElXMLBinaryDecryptionTransform::IsTransformAlgorithmSupported_Inst(const sb_u16string &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLBinaryDecryptionTransform_IsTransformAlgorithmSupported_1(_Handle, Algorithm.data(), (int32_t)Algorithm.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLBinaryDecryptionTransform::IsTransformAlgorithmSupported_Inst(const std::wstring &Algorithm)
{
	std::string u16Algorithm;
	sb_to_u16string(Algorithm, u16Algorithm);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLBinaryDecryptionTransform_IsTransformAlgorithmSupported_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16Algorithm.data()), (int32_t)u16Algorithm.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

TSBTransformedDataType TElXMLBinaryDecryptionTransform::TransformData(const std::vector<uint8_t> &Data)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLBinaryDecryptionTransform_TransformData(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TSBTransformedDataType TElXMLBinaryDecryptionTransform::TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLBinaryDecryptionTransform_TransformData_1(_Handle, Node.getHandle(), Reference.getHandle(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

TSBTransformedDataType TElXMLBinaryDecryptionTransform::TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLBinaryDecryptionTransform_TransformData_1(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, (Reference != NULL) ? Reference->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
TSBTransformedDataType TElXMLBinaryDecryptionTransform::TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLBinaryDecryptionTransform_TransformData_2(_Handle, Nodes.getHandle(), SB_STD_VECTOR_FRONT_ADR(Reference), (int32_t)Reference.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

TSBTransformedDataType TElXMLBinaryDecryptionTransform::TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLBinaryDecryptionTransform_TransformData_2(_Handle, (Nodes != NULL) ? Nodes->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Reference), (int32_t)Reference.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

SB_INLINE TClassHandle TElXMLBinaryDecryptionTransform::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLBinaryDecryptionTransform_ClassType(&OutResult));
	return OutResult;
}

TElXMLBinaryDecryptionTransform::TElXMLBinaryDecryptionTransform(TElXMLBinaryDecryptionTransformHandle handle, TElOwnHandle ownHandle) : TElXMLCustomDecryptionTransform(handle, ownHandle)
{
}

TElXMLBinaryDecryptionTransform::TElXMLBinaryDecryptionTransform() : TElXMLCustomDecryptionTransform(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLBinaryDecryptionTransform_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLBINARYDECRYPTIONTRANSFORM */

};	/* namespace SecureBlackbox */

