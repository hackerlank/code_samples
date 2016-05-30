#include "sbxmlsig.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELXMLSIGNATURE

SB_INLINE void TElXMLSignature::Clear()
{
	SBCheckError(TElXMLSignature_Clear(_Handle));
}

bool TElXMLSignature::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLSignature_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSignature::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSignature_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSignature::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSignature_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLSignature::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSignature_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLSignature::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSignature_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLSignature::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSignature_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1251570885, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSignature::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSignature_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1251570885, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSignature::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLSignature_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSignature::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSignature_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLSIGNEDINFO
TElXMLSignedInfo* TElXMLSignature::get_SignedInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignature_get_SignedInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignedInfo)
		this->_Inst_SignedInfo = new TElXMLSignedInfo(hOutResult, ohFalse);
	else
		this->_Inst_SignedInfo->updateHandle(hOutResult);
	return this->_Inst_SignedInfo;
}

SB_INLINE void TElXMLSignature::set_SignedInfo(TElXMLSignedInfo &Value)
{
	SBCheckError(TElXMLSignature_set_SignedInfo(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLSignature::set_SignedInfo(TElXMLSignedInfo *Value)
{
	SBCheckError(TElXMLSignature_set_SignedInfo(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLSIGNEDINFO */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREVALUE
TElXMLSignatureValue* TElXMLSignature::get_SignatureValue()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignature_get_SignatureValue(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureValue)
		this->_Inst_SignatureValue = new TElXMLSignatureValue(hOutResult, ohFalse);
	else
		this->_Inst_SignatureValue->updateHandle(hOutResult);
	return this->_Inst_SignatureValue;
}

SB_INLINE void TElXMLSignature::set_SignatureValue(TElXMLSignatureValue &Value)
{
	SBCheckError(TElXMLSignature_set_SignatureValue(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLSignature::set_SignatureValue(TElXMLSignatureValue *Value)
{
	SBCheckError(TElXMLSignature_set_SignatureValue(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLSIGNATUREVALUE */

#ifdef SB_USE_CLASS_TELXMLKEYINFO
TElXMLKeyInfo* TElXMLSignature::get_KeyInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignature_get_KeyInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyInfo)
		this->_Inst_KeyInfo = new TElXMLKeyInfo(hOutResult, ohFalse);
	else
		this->_Inst_KeyInfo->updateHandle(hOutResult);
	return this->_Inst_KeyInfo;
}

SB_INLINE void TElXMLSignature::set_KeyInfo(TElXMLKeyInfo &Value)
{
	SBCheckError(TElXMLSignature_set_KeyInfo(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLSignature::set_KeyInfo(TElXMLKeyInfo *Value)
{
	SBCheckError(TElXMLSignature_set_KeyInfo(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLKEYINFO */

#ifdef SB_USE_CLASS_TELXMLOBJECTLIST
TElXMLObjectList* TElXMLSignature::get_Objects()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignature_get_Objects(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Objects)
		this->_Inst_Objects = new TElXMLObjectList(hOutResult, ohFalse);
	else
		this->_Inst_Objects->updateHandle(hOutResult);
	return this->_Inst_Objects;
}

SB_INLINE void TElXMLSignature::set_Objects(TElXMLObjectList &Value)
{
	SBCheckError(TElXMLSignature_set_Objects(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLSignature::set_Objects(TElXMLObjectList *Value)
{
	SBCheckError(TElXMLSignature_set_Objects(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLOBJECTLIST */

void TElXMLSignature::get_SignaturePrefix(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSignature_get_SignaturePrefix(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(212021658, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSignature::get_SignaturePrefix(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSignature_get_SignaturePrefix(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(212021658, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSignature::set_SignaturePrefix(const sb_u16string &Value)
{
	SBCheckError(TElXMLSignature_set_SignaturePrefix(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSignature::set_SignaturePrefix(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSignature_set_SignaturePrefix(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLSignatureCompliance TElXMLSignature::get_SignatureCompliance()
{
	TElXMLSignatureComplianceRaw OutResultRaw = 0;
	SBCheckError(TElXMLSignature_get_SignatureCompliance(_Handle, &OutResultRaw));
	return (TElXMLSignatureCompliance)OutResultRaw;
}

SB_INLINE void TElXMLSignature::set_SignatureCompliance(TElXMLSignatureCompliance Value)
{
	SBCheckError(TElXMLSignature_set_SignatureCompliance(_Handle, (TElXMLSignatureComplianceRaw)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElXMLSignature::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignature_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElXMLSignature::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElXMLSignature_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLSignature::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElXMLSignature_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES
TElXMLQualifyingProperties* TElXMLSignature::get_QualifyingProperties()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignature_get_QualifyingProperties(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_QualifyingProperties)
		this->_Inst_QualifyingProperties = new TElXMLQualifyingProperties(hOutResult, ohFalse);
	else
		this->_Inst_QualifyingProperties->updateHandle(hOutResult);
	return this->_Inst_QualifyingProperties;
}

SB_INLINE void TElXMLSignature::set_QualifyingProperties(TElXMLQualifyingProperties &Value)
{
	SBCheckError(TElXMLSignature_set_QualifyingProperties(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLSignature::set_QualifyingProperties(TElXMLQualifyingProperties *Value)
{
	SBCheckError(TElXMLSignature_set_QualifyingProperties(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST
TElXMLQualifyingPropertiesReferenceList* TElXMLSignature::get_QualifyingPropertiesReferences()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignature_get_QualifyingPropertiesReferences(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_QualifyingPropertiesReferences)
		this->_Inst_QualifyingPropertiesReferences = new TElXMLQualifyingPropertiesReferenceList(hOutResult, ohFalse);
	else
		this->_Inst_QualifyingPropertiesReferences->updateHandle(hOutResult);
	return this->_Inst_QualifyingPropertiesReferences;
}
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST */

void TElXMLSignature::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLSIGNEDINFO
	this->_Inst_SignedInfo = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNEDINFO */
#ifdef SB_USE_CLASS_TELXMLSIGNATUREVALUE
	this->_Inst_SignatureValue = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREVALUE */
#ifdef SB_USE_CLASS_TELXMLKEYINFO
	this->_Inst_KeyInfo = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFO */
#ifdef SB_USE_CLASS_TELXMLOBJECTLIST
	this->_Inst_Objects = NULL;
#endif /* SB_USE_CLASS_TELXMLOBJECTLIST */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES
	this->_Inst_QualifyingProperties = NULL;
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES */
#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST
	this->_Inst_QualifyingPropertiesReferences = NULL;
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST */
}

TElXMLSignature::TElXMLSignature(TElXMLSignatureHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
	initInstances();
}

TElXMLSignature::TElXMLSignature() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSignature_Create(&_Handle));
}

TElXMLSignature::~TElXMLSignature()
{
#ifdef SB_USE_CLASS_TELXMLSIGNEDINFO
	delete this->_Inst_SignedInfo;
	this->_Inst_SignedInfo = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNEDINFO */
#ifdef SB_USE_CLASS_TELXMLSIGNATUREVALUE
	delete this->_Inst_SignatureValue;
	this->_Inst_SignatureValue = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREVALUE */
#ifdef SB_USE_CLASS_TELXMLKEYINFO
	delete this->_Inst_KeyInfo;
	this->_Inst_KeyInfo = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFO */
#ifdef SB_USE_CLASS_TELXMLOBJECTLIST
	delete this->_Inst_Objects;
	this->_Inst_Objects = NULL;
#endif /* SB_USE_CLASS_TELXMLOBJECTLIST */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES
	delete this->_Inst_QualifyingProperties;
	this->_Inst_QualifyingProperties = NULL;
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES */
#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST
	delete this->_Inst_QualifyingPropertiesReferences;
	this->_Inst_QualifyingPropertiesReferences = NULL;
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST */
}
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */

#ifdef SB_USE_CLASS_TELXMLSIGPROCESSOR

SB_INLINE void TElXMLSigProcessor::ClearSignatureMethodParameters()
{
	SBCheckError(TElXMLSigProcessor_ClearSignatureMethodParameters(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
TElXMLKeyInfoData* TElXMLSigProcessor::get_KeyData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSigProcessor_get_KeyData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyData)
		this->_Inst_KeyData = new TElXMLKeyInfoData(hOutResult, ohFalse);
	else
		this->_Inst_KeyData->updateHandle(hOutResult);
	return this->_Inst_KeyData;
}

SB_INLINE void TElXMLSigProcessor::set_KeyData(TElXMLKeyInfoData &Value)
{
	SBCheckError(TElXMLSigProcessor_set_KeyData(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLSigProcessor::set_KeyData(TElXMLKeyInfoData *Value)
{
	SBCheckError(TElXMLSigProcessor_set_KeyData(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELXMLSIGNATURE
TElXMLSignature* TElXMLSigProcessor::get_Signature()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSigProcessor_get_Signature(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signature)
		this->_Inst_Signature = new TElXMLSignature(hOutResult, ohFalse);
	else
		this->_Inst_Signature->updateHandle(hOutResult);
	return this->_Inst_Signature;
}

SB_INLINE void TElXMLSigProcessor::set_Signature(TElXMLSignature &Value)
{
	SBCheckError(TElXMLSigProcessor_set_Signature(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLSigProcessor::set_Signature(TElXMLSignature *Value)
{
	SBCheckError(TElXMLSigProcessor_set_Signature(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */

#ifdef SB_USE_CLASS_TELXMLALGORITHMPARAMETERS
TElXMLAlgorithmParameters* TElXMLSigProcessor::get_SignatureMethodParameters()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSigProcessor_get_SignatureMethodParameters(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureMethodParameters)
		this->_Inst_SignatureMethodParameters = new TElXMLAlgorithmParameters(hOutResult, ohFalse);
	else
		this->_Inst_SignatureMethodParameters->updateHandle(hOutResult);
	return this->_Inst_SignatureMethodParameters;
}

SB_INLINE void TElXMLSigProcessor::set_SignatureMethodParameters(TElXMLAlgorithmParameters &Value)
{
	SBCheckError(TElXMLSigProcessor_set_SignatureMethodParameters(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLSigProcessor::set_SignatureMethodParameters(TElXMLAlgorithmParameters *Value)
{
	SBCheckError(TElXMLSigProcessor_set_SignatureMethodParameters(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLALGORITHMPARAMETERS */

void TElXMLSigProcessor::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
	this->_Inst_KeyData = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
#ifdef SB_USE_CLASS_TELXMLSIGNATURE
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */
#ifdef SB_USE_CLASS_TELXMLALGORITHMPARAMETERS
	this->_Inst_SignatureMethodParameters = NULL;
#endif /* SB_USE_CLASS_TELXMLALGORITHMPARAMETERS */
}

TElXMLSigProcessor::TElXMLSigProcessor(TElXMLSigProcessorHandle handle, TElOwnHandle ownHandle) : TElXMLProcessor(handle, ownHandle)
{
	initInstances();
}

TElXMLSigProcessor::TElXMLSigProcessor(TComponent &AOwner) : TElXMLProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSigProcessor_Create(AOwner.getHandle(), &_Handle));
}

TElXMLSigProcessor::TElXMLSigProcessor(TComponent *AOwner) : TElXMLProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSigProcessor_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElXMLSigProcessor::~TElXMLSigProcessor()
{
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
	delete this->_Inst_KeyData;
	this->_Inst_KeyData = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
#ifdef SB_USE_CLASS_TELXMLSIGNATURE
	delete this->_Inst_Signature;
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */
#ifdef SB_USE_CLASS_TELXMLALGORITHMPARAMETERS
	delete this->_Inst_SignatureMethodParameters;
	this->_Inst_SignatureMethodParameters = NULL;
#endif /* SB_USE_CLASS_TELXMLALGORITHMPARAMETERS */
}
#endif /* SB_USE_CLASS_TELXMLSIGPROCESSOR */

#ifdef SB_USE_CLASS_TELXMLSIGNER

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMDOCUMENT
SB_INLINE void TElXMLSigner::CompleteAsyncSign(TElXMLDOMDocument &Document, TElDCAsyncState &State)
{
	SBCheckError(TElXMLSigner_CompleteAsyncSign(_Handle, Document.getHandle(), State.getHandle()));
}

SB_INLINE void TElXMLSigner::CompleteAsyncSign(TElXMLDOMDocument *Document, TElDCAsyncState *State)
{
	SBCheckError(TElXMLSigner_CompleteAsyncSign(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMNODE
TElDCAsyncStateHandle TElXMLSigner::InitiateAsyncSign(TElXMLDOMNode &Node)
{
	TElDCAsyncStateHandle OutResult;
	TElClassHandle hNode = Node.getHandle();
	SBCheckError(TElXMLSigner_InitiateAsyncSign(_Handle, &hNode, &OutResult));
	Node.updateHandle(hNode);
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMNODE */

SB_INLINE void TElXMLSigner::GenerateSignature()
{
	SBCheckError(TElXMLSigner_GenerateSignature(_Handle));
}

SB_INLINE void TElXMLSigner::GenerateSignatureAsync()
{
	SBCheckError(TElXMLSigner_GenerateSignatureAsync(_Handle));
}

SB_INLINE void TElXMLSigner::Sign()
{
	SBCheckError(TElXMLSigner_Sign(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
void TElXMLSigner::Save(TElXMLDOMNode &Node)
{
	TElClassHandle hNode = Node.getHandle();
	SBCheckError(TElXMLSigner_Save(_Handle, &hNode));
	Node.updateHandle(hNode);
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE TElXMLDOMDocumentHandle TElXMLSigner::SaveDetached()
{
	TElXMLDOMDocumentHandle OutResult;
	SBCheckError(TElXMLSigner_SaveDetached(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLSigner::SaveEnveloped(TElXMLDOMElement &ParentElement)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSigner_SaveEnveloped(_Handle, ParentElement.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLSigner::SaveEnveloped(TElXMLDOMElement *ParentElement)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSigner_SaveEnveloped(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLDOMNODE
SB_INLINE TElXMLDOMElementHandle TElXMLSigner::SaveEnveloping(TElXMLDOMNode &EnvelopingNode)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSigner_SaveEnveloping(_Handle, EnvelopingNode.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLSigner::SaveEnveloping(TElXMLDOMNode *EnvelopingNode)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSigner_SaveEnveloping(_Handle, (EnvelopingNode != NULL) ? EnvelopingNode->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLDOMNODE */

SB_INLINE void TElXMLSigner::UpdateReferencesDigest()
{
	SBCheckError(TElXMLSigner_UpdateReferencesDigest(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
TElXMLReferenceList* TElXMLSigner::get_References()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSigner_get_References(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_References)
		this->_Inst_References = new TElXMLReferenceList(hOutResult, ohFalse);
	else
		this->_Inst_References->updateHandle(hOutResult);
	return this->_Inst_References;
}

SB_INLINE void TElXMLSigner::set_References(TElXMLReferenceList &Value)
{
	SBCheckError(TElXMLSigner_set_References(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLSigner::set_References(TElXMLReferenceList *Value)
{
	SBCheckError(TElXMLSigner_set_References(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */

#ifdef SB_USE_CLASS_TELREMOTESIGNINGPARAMS
TElRemoteSigningParams* TElXMLSigner::get_RemoteSigningParams()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSigner_get_RemoteSigningParams(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RemoteSigningParams)
		this->_Inst_RemoteSigningParams = new TElRemoteSigningParams(hOutResult, ohFalse);
	else
		this->_Inst_RemoteSigningParams->updateHandle(hOutResult);
	return this->_Inst_RemoteSigningParams;
}
#endif /* SB_USE_CLASS_TELREMOTESIGNINGPARAMS */

#ifdef SB_USE_CLASS_TELXADESSIGNER
TElXAdESSigner* TElXMLSigner::get_XAdESProcessor()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSigner_get_XAdESProcessor(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_XAdESProcessor)
		this->_Inst_XAdESProcessor = new TElXAdESSigner(hOutResult, ohFalse);
	else
		this->_Inst_XAdESProcessor->updateHandle(hOutResult);
	return this->_Inst_XAdESProcessor;
}

SB_INLINE void TElXMLSigner::set_XAdESProcessor(TElXAdESSigner &Value)
{
	SBCheckError(TElXMLSigner_set_XAdESProcessor(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLSigner::set_XAdESProcessor(TElXAdESSigner *Value)
{
	SBCheckError(TElXMLSigner_set_XAdESProcessor(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXADESSIGNER */

TElXMLCanonicalizationMethod TElXMLSigner::get_CanonicalizationMethod()
{
	TElXMLCanonicalizationMethodRaw OutResultRaw = 0;
	SBCheckError(TElXMLSigner_get_CanonicalizationMethod(_Handle, &OutResultRaw));
	return (TElXMLCanonicalizationMethod)OutResultRaw;
}

SB_INLINE void TElXMLSigner::set_CanonicalizationMethod(TElXMLCanonicalizationMethod Value)
{
	SBCheckError(TElXMLSigner_set_CanonicalizationMethod(_Handle, (TElXMLCanonicalizationMethodRaw)Value));
}

void TElXMLSigner::get_InclusiveNamespacesPrefixList(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSigner_get_InclusiveNamespacesPrefixList(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(877253242, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSigner::get_InclusiveNamespacesPrefixList(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSigner_get_InclusiveNamespacesPrefixList(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(877253242, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSigner::set_InclusiveNamespacesPrefixList(const sb_u16string &Value)
{
	SBCheckError(TElXMLSigner_set_InclusiveNamespacesPrefixList(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSigner::set_InclusiveNamespacesPrefixList(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSigner_set_InclusiveNamespacesPrefixList(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLSignatureType TElXMLSigner::get_SignatureType()
{
	TElXMLSignatureTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLSigner_get_SignatureType(_Handle, &OutResultRaw));
	return (TElXMLSignatureType)OutResultRaw;
}

SB_INLINE void TElXMLSigner::set_SignatureType(TElXMLSignatureType Value)
{
	SBCheckError(TElXMLSigner_set_SignatureType(_Handle, (TElXMLSignatureTypeRaw)Value));
}

TElXMLSignatureCompliance TElXMLSigner::get_SignatureCompliance()
{
	TElXMLSignatureComplianceRaw OutResultRaw = 0;
	SBCheckError(TElXMLSigner_get_SignatureCompliance(_Handle, &OutResultRaw));
	return (TElXMLSignatureCompliance)OutResultRaw;
}

SB_INLINE void TElXMLSigner::set_SignatureCompliance(TElXMLSignatureCompliance Value)
{
	SBCheckError(TElXMLSigner_set_SignatureCompliance(_Handle, (TElXMLSignatureComplianceRaw)Value));
}

TElXMLSigMethodType TElXMLSigner::get_SignatureMethodType()
{
	TElXMLSigMethodTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLSigner_get_SignatureMethodType(_Handle, &OutResultRaw));
	return (TElXMLSigMethodType)OutResultRaw;
}

SB_INLINE void TElXMLSigner::set_SignatureMethodType(TElXMLSigMethodType Value)
{
	SBCheckError(TElXMLSigner_set_SignatureMethodType(_Handle, (TElXMLSigMethodTypeRaw)Value));
}

TElXMLMACMethod TElXMLSigner::get_MACMethod()
{
	TElXMLMACMethodRaw OutResultRaw = 0;
	SBCheckError(TElXMLSigner_get_MACMethod(_Handle, &OutResultRaw));
	return (TElXMLMACMethod)OutResultRaw;
}

SB_INLINE void TElXMLSigner::set_MACMethod(TElXMLMACMethod Value)
{
	SBCheckError(TElXMLSigner_set_MACMethod(_Handle, (TElXMLMACMethodRaw)Value));
}

TElXMLSignatureMethod TElXMLSigner::get_SignatureMethod()
{
	TElXMLSignatureMethodRaw OutResultRaw = 0;
	SBCheckError(TElXMLSigner_get_SignatureMethod(_Handle, &OutResultRaw));
	return (TElXMLSignatureMethod)OutResultRaw;
}

SB_INLINE void TElXMLSigner::set_SignatureMethod(TElXMLSignatureMethod Value)
{
	SBCheckError(TElXMLSigner_set_SignatureMethod(_Handle, (TElXMLSignatureMethodRaw)Value));
}

bool TElXMLSigner::get_IncludeKey()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLSigner_get_IncludeKey(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLSigner::set_IncludeKey(bool Value)
{
	SBCheckError(TElXMLSigner_set_IncludeKey(_Handle, (int8_t)Value));
}

void TElXMLSigner::get_KeyName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSigner_get_KeyName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1948372913, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSigner::get_KeyName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSigner_get_KeyName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1948372913, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSigner::set_KeyName(const sb_u16string &Value)
{
	SBCheckError(TElXMLSigner_set_KeyName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSigner::set_KeyName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSigner_set_KeyName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSigner::get_EnvelopingObjectID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSigner_get_EnvelopingObjectID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(709560888, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSigner::get_EnvelopingObjectID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSigner_get_EnvelopingObjectID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(709560888, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSigner::set_EnvelopingObjectID(const sb_u16string &Value)
{
	SBCheckError(TElXMLSigner_set_EnvelopingObjectID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSigner::set_EnvelopingObjectID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSigner_set_EnvelopingObjectID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSigner::get_OnFormatElement(TSBXMLFormatElementEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXMLSigner_get_OnFormatElement(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXMLSigner::set_OnFormatElement(TSBXMLFormatElementEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXMLSigner_set_OnFormatElement(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElXMLSigner::get_OnFormatText(TSBXMLFormatTextEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXMLSigner_get_OnFormatText(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXMLSigner::set_OnFormatText(TSBXMLFormatTextEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXMLSigner_set_OnFormatText(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElXMLSigner::get_OnRemoteSign(TSBXMLRemoteSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXMLSigner_get_OnRemoteSign(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXMLSigner::set_OnRemoteSign(TSBXMLRemoteSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXMLSigner_set_OnRemoteSign(_Handle, pMethodValue, pDataValue));
}

void TElXMLSigner::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
	this->_Inst_References = NULL;
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */
#ifdef SB_USE_CLASS_TELREMOTESIGNINGPARAMS
	this->_Inst_RemoteSigningParams = NULL;
#endif /* SB_USE_CLASS_TELREMOTESIGNINGPARAMS */
#ifdef SB_USE_CLASS_TELXADESSIGNER
	this->_Inst_XAdESProcessor = NULL;
#endif /* SB_USE_CLASS_TELXADESSIGNER */
}

TElXMLSigner::TElXMLSigner(TElXMLSignerHandle handle, TElOwnHandle ownHandle) : TElXMLSigProcessor(handle, ownHandle)
{
	initInstances();
}

TElXMLSigner::TElXMLSigner(TComponent &AOwner) : TElXMLSigProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSigner_Create(AOwner.getHandle(), &_Handle));
}

TElXMLSigner::TElXMLSigner(TComponent *AOwner) : TElXMLSigProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSigner_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElXMLSigner::~TElXMLSigner()
{
#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
	delete this->_Inst_References;
	this->_Inst_References = NULL;
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */
#ifdef SB_USE_CLASS_TELREMOTESIGNINGPARAMS
	delete this->_Inst_RemoteSigningParams;
	this->_Inst_RemoteSigningParams = NULL;
#endif /* SB_USE_CLASS_TELREMOTESIGNINGPARAMS */
#ifdef SB_USE_CLASS_TELXADESSIGNER
	delete this->_Inst_XAdESProcessor;
	this->_Inst_XAdESProcessor = NULL;
#endif /* SB_USE_CLASS_TELXADESSIGNER */
}
#endif /* SB_USE_CLASS_TELXMLSIGNER */

#ifdef SB_USE_CLASS_TELXMLVERIFIER

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLVerifier::Load(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLVerifier_Load(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLVerifier::Load(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLVerifier_Load(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

bool TElXMLVerifier::ValidateSignature()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLVerifier_ValidateSignature(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLREFERENCE
bool TElXMLVerifier::ValidateReference(TElXMLReference &Reference)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLVerifier_ValidateReference(_Handle, Reference.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElXMLVerifier::ValidateReference(TElXMLReference *Reference)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLVerifier_ValidateReference(_Handle, (Reference != NULL) ? Reference->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELXMLREFERENCE */

bool TElXMLVerifier::ValidateReferences()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLVerifier_ValidateReferences(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLVerifier::RemoveSignature()
{
	SBCheckError(TElXMLVerifier_RemoveSignature(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLKEYINFOHMACDATA
TElXMLKeyInfoHMACData* TElXMLVerifier::get_HMACKey()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLVerifier_get_HMACKey(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HMACKey)
		this->_Inst_HMACKey = new TElXMLKeyInfoHMACData(hOutResult, ohFalse);
	else
		this->_Inst_HMACKey->updateHandle(hOutResult);
	return this->_Inst_HMACKey;
}

SB_INLINE void TElXMLVerifier::set_HMACKey(TElXMLKeyInfoHMACData &Value)
{
	SBCheckError(TElXMLVerifier_set_HMACKey(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLVerifier::set_HMACKey(TElXMLKeyInfoHMACData *Value)
{
	SBCheckError(TElXMLVerifier_set_HMACKey(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLKEYINFOHMACDATA */

#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
TElXMLReferenceList* TElXMLVerifier::get_References()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLVerifier_get_References(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_References)
		this->_Inst_References = new TElXMLReferenceList(hOutResult, ohFalse);
	else
		this->_Inst_References->updateHandle(hOutResult);
	return this->_Inst_References;
}
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */

TElXMLCanonicalizationMethod TElXMLVerifier::get_CanonicalizationMethod()
{
	TElXMLCanonicalizationMethodRaw OutResultRaw = 0;
	SBCheckError(TElXMLVerifier_get_CanonicalizationMethod(_Handle, &OutResultRaw));
	return (TElXMLCanonicalizationMethod)OutResultRaw;
}

void TElXMLVerifier::get_InclusiveNamespacesPrefixList(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLVerifier_get_InclusiveNamespacesPrefixList(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1097865349, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLVerifier::get_InclusiveNamespacesPrefixList(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLVerifier_get_InclusiveNamespacesPrefixList(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1097865349, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
TElXMLSignatureTypes TElXMLVerifier::get_SignatureType()
{
	TElXMLSignatureTypesRaw OutResultRaw = 0;
	SBCheckError(TElXMLVerifier_get_SignatureType(_Handle, &OutResultRaw));
	return (TElXMLSignatureTypes)OutResultRaw;
}

TElXMLSignatureCompliance TElXMLVerifier::get_SignatureCompliance()
{
	TElXMLSignatureComplianceRaw OutResultRaw = 0;
	SBCheckError(TElXMLVerifier_get_SignatureCompliance(_Handle, &OutResultRaw));
	return (TElXMLSignatureCompliance)OutResultRaw;
}

TElXMLSigMethodType TElXMLVerifier::get_SignatureMethodType()
{
	TElXMLSigMethodTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLVerifier_get_SignatureMethodType(_Handle, &OutResultRaw));
	return (TElXMLSigMethodType)OutResultRaw;
}

TElXMLMACMethod TElXMLVerifier::get_MACMethod()
{
	TElXMLMACMethodRaw OutResultRaw = 0;
	SBCheckError(TElXMLVerifier_get_MACMethod(_Handle, &OutResultRaw));
	return (TElXMLMACMethod)OutResultRaw;
}

TElXMLSignatureMethod TElXMLVerifier::get_SignatureMethod()
{
	TElXMLSignatureMethodRaw OutResultRaw = 0;
	SBCheckError(TElXMLVerifier_get_SignatureMethod(_Handle, &OutResultRaw));
	return (TElXMLSignatureMethod)OutResultRaw;
}

bool TElXMLVerifier::get_KeyDataNeeded()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLVerifier_get_KeyDataNeeded(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElXMLVerifier::get_KeyName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLVerifier_get_KeyName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-755733651, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLVerifier::get_KeyName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLVerifier_get_KeyName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-755733651, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElXMLVerifier::get_SignerCertificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLVerifier_get_SignerCertificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignerCertificate)
		this->_Inst_SignerCertificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_SignerCertificate->updateHandle(hOutResult);
	return this->_Inst_SignerCertificate;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
TElXMLKeyInfoData* TElXMLVerifier::get_SignerKeyData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLVerifier_get_SignerKeyData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignerKeyData)
		this->_Inst_SignerKeyData = new TElXMLKeyInfoData(hOutResult, ohFalse);
	else
		this->_Inst_SignerKeyData->updateHandle(hOutResult);
	return this->_Inst_SignerKeyData;
}
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELXADESVERIFIER
TElXAdESVerifier* TElXMLVerifier::get_XAdESProcessor()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLVerifier_get_XAdESProcessor(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_XAdESProcessor)
		this->_Inst_XAdESProcessor = new TElXAdESVerifier(hOutResult, ohFalse);
	else
		this->_Inst_XAdESProcessor->updateHandle(hOutResult);
	return this->_Inst_XAdESProcessor;
}

SB_INLINE void TElXMLVerifier::set_XAdESProcessor(TElXAdESVerifier &Value)
{
	SBCheckError(TElXMLVerifier_set_XAdESProcessor(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLVerifier::set_XAdESProcessor(TElXAdESVerifier *Value)
{
	SBCheckError(TElXMLVerifier_set_XAdESProcessor(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXADESVERIFIER */

void TElXMLVerifier::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLKEYINFOHMACDATA
	this->_Inst_HMACKey = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFOHMACDATA */
#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
	this->_Inst_References = NULL;
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_SignerCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
	this->_Inst_SignerKeyData = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
#ifdef SB_USE_CLASS_TELXADESVERIFIER
	this->_Inst_XAdESProcessor = NULL;
#endif /* SB_USE_CLASS_TELXADESVERIFIER */
}

TElXMLVerifier::TElXMLVerifier(TElXMLVerifierHandle handle, TElOwnHandle ownHandle) : TElXMLSigProcessor(handle, ownHandle)
{
	initInstances();
}

TElXMLVerifier::TElXMLVerifier(TComponent &AOwner) : TElXMLSigProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLVerifier_Create(AOwner.getHandle(), &_Handle));
}

TElXMLVerifier::TElXMLVerifier(TComponent *AOwner) : TElXMLSigProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLVerifier_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElXMLVerifier::~TElXMLVerifier()
{
#ifdef SB_USE_CLASS_TELXMLKEYINFOHMACDATA
	delete this->_Inst_HMACKey;
	this->_Inst_HMACKey = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFOHMACDATA */
#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
	delete this->_Inst_References;
	this->_Inst_References = NULL;
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_SignerCertificate;
	this->_Inst_SignerCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
	delete this->_Inst_SignerKeyData;
	this->_Inst_SignerKeyData = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
#ifdef SB_USE_CLASS_TELXADESVERIFIER
	delete this->_Inst_XAdESProcessor;
	this->_Inst_XAdESProcessor = NULL;
#endif /* SB_USE_CLASS_TELXADESVERIFIER */
}
#endif /* SB_USE_CLASS_TELXMLVERIFIER */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREMETHODTYPE

SB_INLINE void TElXMLSignatureMethodType::Clear()
{
	SBCheckError(TElXMLSignatureMethodType_Clear(_Handle));
}

bool TElXMLSignatureMethodType::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLSignatureMethodType_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSignatureMethodType::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSignatureMethodType_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSignatureMethodType::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSignatureMethodType_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLSignatureMethodType::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSignatureMethodType_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLSignatureMethodType::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSignatureMethodType_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLSignatureMethodType::get_Algorithm(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSignatureMethodType_get_Algorithm(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1252889132, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSignatureMethodType::get_Algorithm(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSignatureMethodType_get_Algorithm(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1252889132, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSignatureMethodType::set_Algorithm(const sb_u16string &Value)
{
	SBCheckError(TElXMLSignatureMethodType_set_Algorithm(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSignatureMethodType::set_Algorithm(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSignatureMethodType_set_Algorithm(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE int32_t TElXMLSignatureMethodType::get_HMACOutputLength()
{
	int32_t OutResult;
	SBCheckError(TElXMLSignatureMethodType_get_HMACOutputLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLSignatureMethodType::set_HMACOutputLength(int32_t Value)
{
	SBCheckError(TElXMLSignatureMethodType_set_HMACOutputLength(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELXMLALGORITHMPARAMETERS
TElXMLAlgorithmParameters* TElXMLSignatureMethodType::get_Parameters()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignatureMethodType_get_Parameters(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Parameters)
		this->_Inst_Parameters = new TElXMLAlgorithmParameters(hOutResult, ohFalse);
	else
		this->_Inst_Parameters->updateHandle(hOutResult);
	return this->_Inst_Parameters;
}

SB_INLINE void TElXMLSignatureMethodType::set_Parameters(TElXMLAlgorithmParameters &Value)
{
	SBCheckError(TElXMLSignatureMethodType_set_Parameters(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLSignatureMethodType::set_Parameters(TElXMLAlgorithmParameters *Value)
{
	SBCheckError(TElXMLSignatureMethodType_set_Parameters(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLALGORITHMPARAMETERS */

void TElXMLSignatureMethodType::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLALGORITHMPARAMETERS
	this->_Inst_Parameters = NULL;
#endif /* SB_USE_CLASS_TELXMLALGORITHMPARAMETERS */
}

TElXMLSignatureMethodType::TElXMLSignatureMethodType(TElXMLSignatureMethodTypeHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
	initInstances();
}

TElXMLSignatureMethodType::TElXMLSignatureMethodType() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSignatureMethodType_Create(&_Handle));
}

TElXMLSignatureMethodType::~TElXMLSignatureMethodType()
{
#ifdef SB_USE_CLASS_TELXMLALGORITHMPARAMETERS
	delete this->_Inst_Parameters;
	this->_Inst_Parameters = NULL;
#endif /* SB_USE_CLASS_TELXMLALGORITHMPARAMETERS */
}
#endif /* SB_USE_CLASS_TELXMLSIGNATUREMETHODTYPE */

#ifdef SB_USE_CLASS_TELXMLSIGNEDINFO

SB_INLINE void TElXMLSignedInfo::Clear()
{
	SBCheckError(TElXMLSignedInfo_Clear(_Handle));
}

bool TElXMLSignedInfo::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLSignedInfo_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSignedInfo::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSignedInfo_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSignedInfo::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSignedInfo_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLSignedInfo::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSignedInfo_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLSignedInfo::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSignedInfo_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLSignedInfo::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSignedInfo_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-736400028, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSignedInfo::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSignedInfo_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-736400028, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSignedInfo::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLSignedInfo_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSignedInfo::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSignedInfo_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSignedInfo::get_CanonicalizationMethod(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSignedInfo_get_CanonicalizationMethod(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1137074810, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSignedInfo::get_CanonicalizationMethod(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSignedInfo_get_CanonicalizationMethod(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1137074810, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSignedInfo::set_CanonicalizationMethod(const sb_u16string &Value)
{
	SBCheckError(TElXMLSignedInfo_set_CanonicalizationMethod(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSignedInfo::set_CanonicalizationMethod(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSignedInfo_set_CanonicalizationMethod(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSignedInfo::get_ExclusiveCanonicalizationPrefix(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSignedInfo_get_ExclusiveCanonicalizationPrefix(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(359281730, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSignedInfo::get_ExclusiveCanonicalizationPrefix(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSignedInfo_get_ExclusiveCanonicalizationPrefix(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(359281730, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSignedInfo::set_ExclusiveCanonicalizationPrefix(const sb_u16string &Value)
{
	SBCheckError(TElXMLSignedInfo_set_ExclusiveCanonicalizationPrefix(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSignedInfo::set_ExclusiveCanonicalizationPrefix(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSignedInfo_set_ExclusiveCanonicalizationPrefix(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSignedInfo::get_InclusiveNamespacesPrefixList(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSignedInfo_get_InclusiveNamespacesPrefixList(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1702292144, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSignedInfo::get_InclusiveNamespacesPrefixList(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSignedInfo_get_InclusiveNamespacesPrefixList(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1702292144, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSignedInfo::set_InclusiveNamespacesPrefixList(const sb_u16string &Value)
{
	SBCheckError(TElXMLSignedInfo_set_InclusiveNamespacesPrefixList(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSignedInfo::set_InclusiveNamespacesPrefixList(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSignedInfo_set_InclusiveNamespacesPrefixList(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLSIGNATUREMETHODTYPE
TElXMLSignatureMethodType* TElXMLSignedInfo::get_SignatureMethod()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignedInfo_get_SignatureMethod(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureMethod)
		this->_Inst_SignatureMethod = new TElXMLSignatureMethodType(hOutResult, ohFalse);
	else
		this->_Inst_SignatureMethod->updateHandle(hOutResult);
	return this->_Inst_SignatureMethod;
}

SB_INLINE void TElXMLSignedInfo::set_SignatureMethod(TElXMLSignatureMethodType &Value)
{
	SBCheckError(TElXMLSignedInfo_set_SignatureMethod(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLSignedInfo::set_SignatureMethod(TElXMLSignatureMethodType *Value)
{
	SBCheckError(TElXMLSignedInfo_set_SignatureMethod(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLSIGNATUREMETHODTYPE */

#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
TElXMLReferenceList* TElXMLSignedInfo::get_References()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignedInfo_get_References(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_References)
		this->_Inst_References = new TElXMLReferenceList(hOutResult, ohFalse);
	else
		this->_Inst_References->updateHandle(hOutResult);
	return this->_Inst_References;
}

SB_INLINE void TElXMLSignedInfo::set_References(TElXMLReferenceList &Value)
{
	SBCheckError(TElXMLSignedInfo_set_References(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLSignedInfo::set_References(TElXMLReferenceList *Value)
{
	SBCheckError(TElXMLSignedInfo_set_References(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */

#ifdef SB_USE_CLASS_TELXMLREFERENCE
TElXMLReference* TElXMLSignedInfo::get_SigPropRef()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSignedInfo_get_SigPropRef(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SigPropRef)
		this->_Inst_SigPropRef = new TElXMLReference(hOutResult, ohFalse);
	else
		this->_Inst_SigPropRef->updateHandle(hOutResult);
	return this->_Inst_SigPropRef;
}
#endif /* SB_USE_CLASS_TELXMLREFERENCE */

void TElXMLSignedInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLSIGNATUREMETHODTYPE
	this->_Inst_SignatureMethod = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREMETHODTYPE */
#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
	this->_Inst_References = NULL;
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */
#ifdef SB_USE_CLASS_TELXMLREFERENCE
	this->_Inst_SigPropRef = NULL;
#endif /* SB_USE_CLASS_TELXMLREFERENCE */
}

TElXMLSignedInfo::TElXMLSignedInfo(TElXMLSignedInfoHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
	initInstances();
}

TElXMLSignedInfo::TElXMLSignedInfo() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSignedInfo_Create(&_Handle));
}

TElXMLSignedInfo::~TElXMLSignedInfo()
{
#ifdef SB_USE_CLASS_TELXMLSIGNATUREMETHODTYPE
	delete this->_Inst_SignatureMethod;
	this->_Inst_SignatureMethod = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREMETHODTYPE */
#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
	delete this->_Inst_References;
	this->_Inst_References = NULL;
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */
#ifdef SB_USE_CLASS_TELXMLREFERENCE
	delete this->_Inst_SigPropRef;
	this->_Inst_SigPropRef = NULL;
#endif /* SB_USE_CLASS_TELXMLREFERENCE */
}
#endif /* SB_USE_CLASS_TELXMLSIGNEDINFO */

#ifdef SB_USE_CLASS_TELXMLMANIFEST

SB_INLINE void TElXMLManifest::Clear()
{
	SBCheckError(TElXMLManifest_Clear(_Handle));
}

bool TElXMLManifest::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLManifest_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLManifest::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLManifest_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLManifest::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLManifest_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLManifest::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLManifest_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLManifest::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLManifest_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLDOMElement* TElXMLManifest::get_XMLElement()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLManifest_get_XMLElement(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_XMLElement)
		this->_Inst_XMLElement = new TElXMLDOMElement(hOutResult, ohFalse);
	else
		this->_Inst_XMLElement->updateHandle(hOutResult);
	return this->_Inst_XMLElement;
}

SB_INLINE void TElXMLManifest::set_XMLElement(TElXMLDOMElement &Value)
{
	SBCheckError(TElXMLManifest_set_XMLElement(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLManifest::set_XMLElement(TElXMLDOMElement *Value)
{
	SBCheckError(TElXMLManifest_set_XMLElement(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

void TElXMLManifest::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLManifest_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(556566044, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLManifest::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLManifest_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(556566044, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLManifest::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLManifest_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLManifest::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLManifest_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLManifest::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	this->_Inst_XMLElement = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
}

TElXMLManifest::TElXMLManifest(TElXMLManifestHandle handle, TElOwnHandle ownHandle) : TElXMLReferenceList(handle, ownHandle)
{
	initInstances();
}

TElXMLManifest::TElXMLManifest() : TElXMLReferenceList(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLManifest_Create(&_Handle));
}

TElXMLManifest::~TElXMLManifest()
{
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	delete this->_Inst_XMLElement;
	this->_Inst_XMLElement = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
}
#endif /* SB_USE_CLASS_TELXMLMANIFEST */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPROPERTIES

TElXMLSignatureProperties::TElXMLSignatureProperties(TElXMLSignaturePropertiesHandle handle, TElOwnHandle ownHandle) : TElXMLProperties(handle, ownHandle)
{
}

TElXMLSignatureProperties::TElXMLSignatureProperties() : TElXMLProperties(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSignatureProperties_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLSIGNATUREPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLOBJECT

SB_INLINE void TElXMLObject::Clear()
{
	SBCheckError(TElXMLObject_Clear(_Handle));
}

bool TElXMLObject::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLObject_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLObject::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLObject_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLObject::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLObject_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLObject::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLObject_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLObject::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLObject_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLObject::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLObject_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-2070494151, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLObject::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLObject_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-2070494151, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLObject::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLObject_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLObject::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLObject_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLObject::get_MimeType(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLObject_get_MimeType(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-2084077490, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLObject::get_MimeType(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLObject_get_MimeType(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-2084077490, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLObject::set_MimeType(const sb_u16string &Value)
{
	SBCheckError(TElXMLObject_set_MimeType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLObject::set_MimeType(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLObject_set_MimeType(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLObject::get_Encoding(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLObject_get_Encoding(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(863885702, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLObject::get_Encoding(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLObject_get_Encoding(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(863885702, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLObject::set_Encoding(const sb_u16string &Value)
{
	SBCheckError(TElXMLObject_set_Encoding(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLObject::set_Encoding(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLObject_set_Encoding(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TLIST
TList* TElXMLObject::get_DataList()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLObject_get_DataList(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DataList)
		this->_Inst_DataList = new TList(hOutResult, ohFalse);
	else
		this->_Inst_DataList->updateHandle(hOutResult);
	return this->_Inst_DataList;
}
#endif /* SB_USE_CLASS_TLIST */

void TElXMLObject::initInstances()
{
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_DataList = NULL;
#endif /* SB_USE_CLASS_TLIST */
}

TElXMLObject::TElXMLObject(TElXMLObjectHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
	initInstances();
}

TElXMLObject::TElXMLObject() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLObject_Create(&_Handle));
}

TElXMLObject::~TElXMLObject()
{
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_DataList;
	this->_Inst_DataList = NULL;
#endif /* SB_USE_CLASS_TLIST */
}
#endif /* SB_USE_CLASS_TELXMLOBJECT */

#ifdef SB_USE_CLASS_TELXMLOBJECTLIST

#ifdef SB_USE_CLASS_TELXMLOBJECT
SB_INLINE int32_t TElXMLObjectList::Add(TElXMLObject &AObject)
{
	int32_t OutResult;
	SBCheckError(TElXMLObjectList_Add(_Handle, AObject.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLObjectList::Add(TElXMLObject *AObject)
{
	int32_t OutResult;
	SBCheckError(TElXMLObjectList_Add(_Handle, (AObject != NULL) ? AObject->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLOBJECT */

SB_INLINE void TElXMLObjectList::Clear()
{
	SBCheckError(TElXMLObjectList_Clear(_Handle));
}

SB_INLINE void TElXMLObjectList::Delete(int32_t Index)
{
	SBCheckError(TElXMLObjectList_Delete(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELXMLOBJECT
SB_INLINE void TElXMLObjectList::Insert(int32_t Index, TElXMLObject &AObject)
{
	SBCheckError(TElXMLObjectList_Insert(_Handle, Index, AObject.getHandle()));
}

SB_INLINE void TElXMLObjectList::Insert(int32_t Index, TElXMLObject *AObject)
{
	SBCheckError(TElXMLObjectList_Insert(_Handle, Index, (AObject != NULL) ? AObject->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLOBJECT */

SB_INLINE int32_t TElXMLObjectList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLObjectList_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLOBJECT
TElXMLObject* TElXMLObjectList::get_Objects(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLObjectList_get_Objects(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Objects)
		this->_Inst_Objects = new TElXMLObject(hOutResult, ohFalse);
	else
		this->_Inst_Objects->updateHandle(hOutResult);
	return this->_Inst_Objects;
}
#endif /* SB_USE_CLASS_TELXMLOBJECT */

void TElXMLObjectList::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLOBJECT
	this->_Inst_Objects = NULL;
#endif /* SB_USE_CLASS_TELXMLOBJECT */
}

TElXMLObjectList::TElXMLObjectList(TElXMLObjectListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElXMLObjectList::TElXMLObjectList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLObjectList_Create(&_Handle));
}

TElXMLObjectList::~TElXMLObjectList()
{
#ifdef SB_USE_CLASS_TELXMLOBJECT
	delete this->_Inst_Objects;
	this->_Inst_Objects = NULL;
#endif /* SB_USE_CLASS_TELXMLOBJECT */
}
#endif /* SB_USE_CLASS_TELXMLOBJECTLIST */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREVALUE

SB_INLINE void TElXMLSignatureValue::Clear()
{
	SBCheckError(TElXMLSignatureValue_Clear(_Handle));
}

bool TElXMLSignatureValue::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLSignatureValue_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSignatureValue::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSignatureValue_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSignatureValue::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSignatureValue_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLSignatureValue::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSignatureValue_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLSignatureValue::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSignatureValue_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLSignatureValue::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSignatureValue_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1100860154, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSignatureValue::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSignatureValue_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1100860154, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSignatureValue::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLSignatureValue_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSignatureValue::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSignatureValue_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSignatureValue::get_Value(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLSignatureValue_get_Value(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1559843589, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElXMLSignatureValue::set_Value(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElXMLSignatureValue_set_Value(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElXMLSignatureValue::TElXMLSignatureValue(TElXMLSignatureValueHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
}

TElXMLSignatureValue::TElXMLSignatureValue() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSignatureValue_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLSIGNATUREVALUE */

};	/* namespace SecureBlackbox */

