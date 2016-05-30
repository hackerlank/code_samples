#include "sbxmlsoap.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELXMLSOAPMESSAGE

SB_INLINE void TElXMLSOAPMessage::Clear()
{
	SBCheckError(TElXMLSOAPMessage_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE void TElXMLSOAPMessage::CreateEnvelope(TElXMLDOMDocument &Document, TSBXMLSOAPVersion Version)
{
	SBCheckError(TElXMLSOAPMessage_CreateEnvelope(_Handle, Document.getHandle(), (TSBXMLSOAPVersionRaw)Version));
}

SB_INLINE void TElXMLSOAPMessage::CreateEnvelope(TElXMLDOMDocument *Document, TSBXMLSOAPVersion Version)
{
	SBCheckError(TElXMLSOAPMessage_CreateEnvelope(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)Version));
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE void TElXMLSOAPMessage::CreateEnvelope(TElXMLDOMDocument &Document, TSBXMLSOAPVersion Version, const sb_u16string &SOAPPrefix)
{
	SBCheckError(TElXMLSOAPMessage_CreateEnvelope_1(_Handle, Document.getHandle(), (TSBXMLSOAPVersionRaw)Version, SOAPPrefix.data(), (int32_t)SOAPPrefix.length()));
}

SB_INLINE void TElXMLSOAPMessage::CreateEnvelope(TElXMLDOMDocument *Document, TSBXMLSOAPVersion Version, const sb_u16string &SOAPPrefix)
{
	SBCheckError(TElXMLSOAPMessage_CreateEnvelope_1(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)Version, SOAPPrefix.data(), (int32_t)SOAPPrefix.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPMessage::CreateEnvelope(TElXMLDOMDocument &Document, TSBXMLSOAPVersion Version, const std::wstring &SOAPPrefix)
{
	std::string u16SOAPPrefix;
	sb_to_u16string(SOAPPrefix, u16SOAPPrefix);
	SBCheckError(TElXMLSOAPMessage_CreateEnvelope_1(_Handle, Document.getHandle(), (TSBXMLSOAPVersionRaw)Version, reinterpret_cast<const sb_char16_t*>(u16SOAPPrefix.data()), (int32_t)u16SOAPPrefix.length() >> 1));
}

SB_INLINE void TElXMLSOAPMessage::CreateEnvelope(TElXMLDOMDocument *Document, TSBXMLSOAPVersion Version, const std::wstring &SOAPPrefix)
{
	std::string u16SOAPPrefix;
	sb_to_u16string(SOAPPrefix, u16SOAPPrefix);
	SBCheckError(TElXMLSOAPMessage_CreateEnvelope_1(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)Version, reinterpret_cast<const sb_char16_t*>(u16SOAPPrefix.data()), (int32_t)u16SOAPPrefix.length() >> 1));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPMessage::CreateEnvelope(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion Version)
{
	SBCheckError(TElXMLSOAPMessage_CreateEnvelope_2(_Handle, ParentElement.getHandle(), (TSBXMLSOAPVersionRaw)Version));
}

SB_INLINE void TElXMLSOAPMessage::CreateEnvelope(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion Version)
{
	SBCheckError(TElXMLSOAPMessage_CreateEnvelope_2(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)Version));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPMessage::CreateEnvelope(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion Version, const sb_u16string &SOAPPrefix)
{
	SBCheckError(TElXMLSOAPMessage_CreateEnvelope_3(_Handle, ParentElement.getHandle(), (TSBXMLSOAPVersionRaw)Version, SOAPPrefix.data(), (int32_t)SOAPPrefix.length()));
}

SB_INLINE void TElXMLSOAPMessage::CreateEnvelope(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion Version, const sb_u16string &SOAPPrefix)
{
	SBCheckError(TElXMLSOAPMessage_CreateEnvelope_3(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)Version, SOAPPrefix.data(), (int32_t)SOAPPrefix.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPMessage::CreateEnvelope(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion Version, const std::wstring &SOAPPrefix)
{
	std::string u16SOAPPrefix;
	sb_to_u16string(SOAPPrefix, u16SOAPPrefix);
	SBCheckError(TElXMLSOAPMessage_CreateEnvelope_3(_Handle, ParentElement.getHandle(), (TSBXMLSOAPVersionRaw)Version, reinterpret_cast<const sb_char16_t*>(u16SOAPPrefix.data()), (int32_t)u16SOAPPrefix.length() >> 1));
}

SB_INLINE void TElXMLSOAPMessage::CreateEnvelope(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion Version, const std::wstring &SOAPPrefix)
{
	std::string u16SOAPPrefix;
	sb_to_u16string(SOAPPrefix, u16SOAPPrefix);
	SBCheckError(TElXMLSOAPMessage_CreateEnvelope_3(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)Version, reinterpret_cast<const sb_char16_t*>(u16SOAPPrefix.data()), (int32_t)u16SOAPPrefix.length() >> 1));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPMessage::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSOAPMessage_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSOAPMessage::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSOAPMessage_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE void TElXMLSOAPMessage::LoadFromXML(TElXMLDOMDocument &Document)
{
	SBCheckError(TElXMLSOAPMessage_LoadFromXML_1(_Handle, Document.getHandle()));
}

SB_INLINE void TElXMLSOAPMessage::LoadFromXML(TElXMLDOMDocument *Document)
{
	SBCheckError(TElXMLSOAPMessage_LoadFromXML_1(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLSOAPCUSTOMSIGNATUREHANDLER
SB_INLINE void TElXMLSOAPMessage::CompleteAsyncSign(TElXMLSOAPCustomSignatureHandler &Handler, TElDCAsyncState &State)
{
	SBCheckError(TElXMLSOAPMessage_CompleteAsyncSign(_Handle, Handler.getHandle(), State.getHandle()));
}

SB_INLINE void TElXMLSOAPMessage::CompleteAsyncSign(TElXMLSOAPCustomSignatureHandler *Handler, TElDCAsyncState *State)
{
	SBCheckError(TElXMLSOAPMessage_CompleteAsyncSign(_Handle, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLSOAPCUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER
SB_INLINE int32_t TElXMLSOAPMessage::AddSignature(TElXMLSOAPCustomSignatureHandler &Handler)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPMessage_AddSignature(_Handle, Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLSOAPMessage::AddSignature(TElXMLSOAPCustomSignatureHandler *Handler)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPMessage_AddSignature(_Handle, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER
SB_INLINE int32_t TElXMLSOAPMessage::AddSignature(TElXMLSOAPCustomSignatureHandler &Handler, bool OwnHandler)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPMessage_AddSignature_1(_Handle, Handler.getHandle(), (int8_t)OwnHandler, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLSOAPMessage::AddSignature(TElXMLSOAPCustomSignatureHandler *Handler, bool OwnHandler)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPMessage_AddSignature_1(_Handle, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, (int8_t)OwnHandler, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER */

SB_INLINE void TElXMLSOAPMessage::RemoveSignature(int32_t Index)
{
	SBCheckError(TElXMLSOAPMessage_RemoveSignature(_Handle, Index));
}

SB_INLINE int32_t TElXMLSOAPMessage::AddSecurityHeader()
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPMessage_AddSecurityHeader(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLSOAPMessage::RemoveSecurityHeader(int32_t Index)
{
	SBCheckError(TElXMLSOAPMessage_RemoveSecurityHeader(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELXMLSOAPENVELOPE
TElXMLSOAPEnvelope* TElXMLSOAPMessage::get_Envelope()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPMessage_get_Envelope(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Envelope)
		this->_Inst_Envelope = new TElXMLSOAPEnvelope(hOutResult, ohFalse);
	else
		this->_Inst_Envelope->updateHandle(hOutResult);
	return this->_Inst_Envelope;
}
#endif /* SB_USE_CLASS_TELXMLSOAPENVELOPE */

TSBXMLSOAPVersion TElXMLSOAPMessage::get_SOAPVersion()
{
	TSBXMLSOAPVersionRaw OutResultRaw = 0;
	SBCheckError(TElXMLSOAPMessage_get_SOAPVersion(_Handle, &OutResultRaw));
	return (TSBXMLSOAPVersion)OutResultRaw;
}

bool TElXMLSOAPMessage::get_IsSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLSOAPMessage_get_IsSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElXMLSOAPMessage::get_SignatureHandlerCount()
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPMessage_get_SignatureHandlerCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLSOAPMessage::get_SecurityHeaderCount()
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPMessage_get_SecurityHeaderCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER
TElXMLSOAPCustomSignatureHandler* TElXMLSOAPMessage::get_SignatureHandlers(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPMessage_get_SignatureHandlers(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureHandlers)
		this->_Inst_SignatureHandlers = new TElXMLSOAPCustomSignatureHandler(hOutResult, ohFalse);
	else
		this->_Inst_SignatureHandlers->updateHandle(hOutResult);
	return this->_Inst_SignatureHandlers;
}
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELXMLWSSESECURITY
TElXMLWSSESecurity* TElXMLSOAPMessage::get_SecurityHeaders(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPMessage_get_SecurityHeaders(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SecurityHeaders)
		this->_Inst_SecurityHeaders = new TElXMLWSSESecurity(hOutResult, ohFalse);
	else
		this->_Inst_SecurityHeaders->updateHandle(hOutResult);
	return this->_Inst_SecurityHeaders;
}
#endif /* SB_USE_CLASS_TELXMLWSSESECURITY */

void TElXMLSOAPMessage::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLSOAPENVELOPE
	this->_Inst_Envelope = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPENVELOPE */
#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER
	this->_Inst_SignatureHandlers = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER */
#ifdef SB_USE_CLASS_TELXMLWSSESECURITY
	this->_Inst_SecurityHeaders = NULL;
#endif /* SB_USE_CLASS_TELXMLWSSESECURITY */
}

TElXMLSOAPMessage::TElXMLSOAPMessage(TElXMLSOAPMessageHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElXMLSOAPMessage::TElXMLSOAPMessage(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPMessage_Create(AOwner.getHandle(), &_Handle));
}

TElXMLSOAPMessage::TElXMLSOAPMessage(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPMessage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElXMLSOAPMessage::~TElXMLSOAPMessage()
{
#ifdef SB_USE_CLASS_TELXMLSOAPENVELOPE
	delete this->_Inst_Envelope;
	this->_Inst_Envelope = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPENVELOPE */
#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER
	delete this->_Inst_SignatureHandlers;
	this->_Inst_SignatureHandlers = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER */
#ifdef SB_USE_CLASS_TELXMLWSSESECURITY
	delete this->_Inst_SecurityHeaders;
	this->_Inst_SecurityHeaders = NULL;
#endif /* SB_USE_CLASS_TELXMLWSSESECURITY */
}
#endif /* SB_USE_CLASS_TELXMLSOAPMESSAGE */

#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER

void TElXMLSOAPCustomSignatureHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPCustomSignatureHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(823898468, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLSOAPCustomSignatureHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPCustomSignatureHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(823898468, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLSOAPMESSAGE
SB_INLINE void TElXMLSOAPCustomSignatureHandler::LoadFromXML(TElXMLDOMElement &SignatureElement, TElXMLSOAPMessage &Msg)
{
	SBCheckError(TElXMLSOAPCustomSignatureHandler_LoadFromXML(_Handle, SignatureElement.getHandle(), Msg.getHandle()));
}

SB_INLINE void TElXMLSOAPCustomSignatureHandler::LoadFromXML(TElXMLDOMElement *SignatureElement, TElXMLSOAPMessage *Msg)
{
	SBCheckError(TElXMLSOAPCustomSignatureHandler_LoadFromXML(_Handle, (SignatureElement != NULL) ? SignatureElement->getHandle() : SB_NULL_HANDLE, (Msg != NULL) ? Msg->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLSOAPMESSAGE */

SB_INLINE void TElXMLSOAPCustomSignatureHandler::Reset()
{
	SBCheckError(TElXMLSOAPCustomSignatureHandler_Reset(_Handle));
}

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
SB_INLINE void TElXMLSOAPCustomSignatureHandler::CompleteAsyncSign(TElDCAsyncState &State)
{
	SBCheckError(TElXMLSOAPCustomSignatureHandler_CompleteAsyncSign(_Handle, State.getHandle()));
}

SB_INLINE void TElXMLSOAPCustomSignatureHandler::CompleteAsyncSign(TElDCAsyncState *State)
{
	SBCheckError(TElXMLSOAPCustomSignatureHandler_CompleteAsyncSign(_Handle, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

SB_INLINE TClassHandle TElXMLSOAPCustomSignatureHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLSOAPCustomSignatureHandler_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLSOAPMESSAGE
TElXMLSOAPMessage* TElXMLSOAPCustomSignatureHandler::get_SOAPMessage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPCustomSignatureHandler_get_SOAPMessage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SOAPMessage)
		this->_Inst_SOAPMessage = new TElXMLSOAPMessage(hOutResult, ohFalse);
	else
		this->_Inst_SOAPMessage->updateHandle(hOutResult);
	return this->_Inst_SOAPMessage;
}
#endif /* SB_USE_CLASS_TELXMLSOAPMESSAGE */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLDOMElement* TElXMLSOAPCustomSignatureHandler::get_XMLElement()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPCustomSignatureHandler_get_XMLElement(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_XMLElement)
		this->_Inst_XMLElement = new TElXMLDOMElement(hOutResult, ohFalse);
	else
		this->_Inst_XMLElement->updateHandle(hOutResult);
	return this->_Inst_XMLElement;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElXMLSOAPCustomSignatureHandler::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPCustomSignatureHandler_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElXMLSOAPCustomSignatureHandler::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElXMLSOAPCustomSignatureHandler_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLSOAPCustomSignatureHandler::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElXMLSOAPCustomSignatureHandler_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

bool TElXMLSOAPCustomSignatureHandler::get_IsCalculated()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLSOAPCustomSignatureHandler_get_IsCalculated(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElXMLSOAPCustomSignatureHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLSOAPMESSAGE
	this->_Inst_SOAPMessage = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPMESSAGE */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	this->_Inst_XMLElement = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}

TElXMLSOAPCustomSignatureHandler::TElXMLSOAPCustomSignatureHandler(TElXMLSOAPCustomSignatureHandlerHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElXMLSOAPCustomSignatureHandler::TElXMLSOAPCustomSignatureHandler(TComponent &Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPCustomSignatureHandler_Create(Owner.getHandle(), &_Handle));
}

TElXMLSOAPCustomSignatureHandler::TElXMLSOAPCustomSignatureHandler(TComponent *Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPCustomSignatureHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElXMLSOAPCustomSignatureHandler::~TElXMLSOAPCustomSignatureHandler()
{
#ifdef SB_USE_CLASS_TELXMLSOAPMESSAGE
	delete this->_Inst_SOAPMessage;
	this->_Inst_SOAPMessage = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPMESSAGE */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	delete this->_Inst_XMLElement;
	this->_Inst_XMLElement = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELXMLSOAPBASESIGNATUREHANDLER

void TElXMLSOAPBaseSignatureHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPBaseSignatureHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1770850445, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLSOAPBaseSignatureHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPBaseSignatureHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1770850445, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLSOAPMESSAGE
SB_INLINE void TElXMLSOAPBaseSignatureHandler::LoadFromXML(TElXMLDOMElement &SignatureElement, TElXMLSOAPMessage &Msg)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_LoadFromXML(_Handle, SignatureElement.getHandle(), Msg.getHandle()));
}

SB_INLINE void TElXMLSOAPBaseSignatureHandler::LoadFromXML(TElXMLDOMElement *SignatureElement, TElXMLSOAPMessage *Msg)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_LoadFromXML(_Handle, (SignatureElement != NULL) ? SignatureElement->getHandle() : SB_NULL_HANDLE, (Msg != NULL) ? Msg->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLSOAPMESSAGE */

SB_INLINE void TElXMLSOAPBaseSignatureHandler::Reset()
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_Reset(_Handle));
}

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT
SB_INLINE TElDCAsyncStateHandle TElXMLSOAPBaseSignatureHandler::InitiateAsyncSign(TElXMLDOMElement &ParentElement)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign(_Handle, ParentElement.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLSOAPBaseSignatureHandler::InitiateAsyncSign(TElXMLDOMElement *ParentElement)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT
SB_INLINE TElDCAsyncStateHandle TElXMLSOAPBaseSignatureHandler::InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElX509Certificate &Certificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign_1(_Handle, ParentElement.getHandle(), Certificate.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLSOAPBaseSignatureHandler::InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElX509Certificate *Certificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign_1(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT
SB_INLINE TElDCAsyncStateHandle TElXMLSOAPBaseSignatureHandler::InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElX509Certificate &Certificate, bool IncludeKey)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign_2(_Handle, ParentElement.getHandle(), Certificate.getHandle(), (int8_t)IncludeKey, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLSOAPBaseSignatureHandler::InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElX509Certificate *Certificate, bool IncludeKey)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign_2(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT
SB_INLINE TElDCAsyncStateHandle TElXMLSOAPBaseSignatureHandler::InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElX509Certificate &Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign_3(_Handle, ParentElement.getHandle(), Certificate.getHandle(), (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLSOAPBaseSignatureHandler::InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElX509Certificate *Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign_3(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT
SB_INLINE TElDCAsyncStateHandle TElXMLSOAPBaseSignatureHandler::InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElCustomCertStorage &CertStorage)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign_4(_Handle, ParentElement.getHandle(), CertStorage.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLSOAPBaseSignatureHandler::InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElCustomCertStorage *CertStorage)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign_4(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT
SB_INLINE TElDCAsyncStateHandle TElXMLSOAPBaseSignatureHandler::InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElCustomCertStorage &CertStorage, bool IncludeKey)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign_5(_Handle, ParentElement.getHandle(), CertStorage.getHandle(), (int8_t)IncludeKey, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLSOAPBaseSignatureHandler::InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElCustomCertStorage *CertStorage, bool IncludeKey)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign_5(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT
SB_INLINE TElDCAsyncStateHandle TElXMLSOAPBaseSignatureHandler::InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElCustomCertStorage &CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign_6(_Handle, ParentElement.getHandle(), CertStorage.getHandle(), (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLSOAPBaseSignatureHandler::InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElCustomCertStorage *CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign_6(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA
SB_INLINE TElDCAsyncStateHandle TElXMLSOAPBaseSignatureHandler::InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign_7(_Handle, ParentElement.getHandle(), KeyData.getHandle(), (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)IncludeKey, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLSOAPBaseSignatureHandler::InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign_7(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (KeyData != NULL) ? KeyData->getHandle() : SB_NULL_HANDLE, (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)IncludeKey, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
SB_INLINE void TElXMLSOAPBaseSignatureHandler::CompleteAsyncSign(TElDCAsyncState &State)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_CompleteAsyncSign(_Handle, State.getHandle()));
}

SB_INLINE void TElXMLSOAPBaseSignatureHandler::CompleteAsyncSign(TElDCAsyncState *State)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_CompleteAsyncSign(_Handle, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPBaseSignatureHandler::Sign(TElXMLDOMElement &ParentElement, TElX509Certificate &Certificate)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_Sign(_Handle, ParentElement.getHandle(), Certificate.getHandle()));
}

SB_INLINE void TElXMLSOAPBaseSignatureHandler::Sign(TElXMLDOMElement *ParentElement, TElX509Certificate *Certificate)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_Sign(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPBaseSignatureHandler::Sign(TElXMLDOMElement &ParentElement, TElX509Certificate &Certificate, bool IncludeKey)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_Sign_1(_Handle, ParentElement.getHandle(), Certificate.getHandle(), (int8_t)IncludeKey));
}

SB_INLINE void TElXMLSOAPBaseSignatureHandler::Sign(TElXMLDOMElement *ParentElement, TElX509Certificate *Certificate, bool IncludeKey)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_Sign_1(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey));
}
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPBaseSignatureHandler::Sign(TElXMLDOMElement &ParentElement, TElX509Certificate &Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_Sign_2(_Handle, ParentElement.getHandle(), Certificate.getHandle(), (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams));
}

SB_INLINE void TElXMLSOAPBaseSignatureHandler::Sign(TElXMLDOMElement *ParentElement, TElX509Certificate *Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_Sign_2(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams));
}
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPBaseSignatureHandler::Sign(TElXMLDOMElement &ParentElement, TElCustomCertStorage &CertStorage)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_Sign_3(_Handle, ParentElement.getHandle(), CertStorage.getHandle()));
}

SB_INLINE void TElXMLSOAPBaseSignatureHandler::Sign(TElXMLDOMElement *ParentElement, TElCustomCertStorage *CertStorage)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_Sign_3(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPBaseSignatureHandler::Sign(TElXMLDOMElement &ParentElement, TElCustomCertStorage &CertStorage, bool IncludeKey)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_Sign_4(_Handle, ParentElement.getHandle(), CertStorage.getHandle(), (int8_t)IncludeKey));
}

SB_INLINE void TElXMLSOAPBaseSignatureHandler::Sign(TElXMLDOMElement *ParentElement, TElCustomCertStorage *CertStorage, bool IncludeKey)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_Sign_4(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPBaseSignatureHandler::Sign(TElXMLDOMElement &ParentElement, TElCustomCertStorage &CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_Sign_5(_Handle, ParentElement.getHandle(), CertStorage.getHandle(), (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams));
}

SB_INLINE void TElXMLSOAPBaseSignatureHandler::Sign(TElXMLDOMElement *ParentElement, TElCustomCertStorage *CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_Sign_5(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA
SB_INLINE void TElXMLSOAPBaseSignatureHandler::Sign(TElXMLDOMElement &ParentElement, TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_Sign_6(_Handle, ParentElement.getHandle(), KeyData.getHandle(), (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)IncludeKey));
}

SB_INLINE void TElXMLSOAPBaseSignatureHandler::Sign(TElXMLDOMElement *ParentElement, TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_Sign_6(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (KeyData != NULL) ? KeyData->getHandle() : SB_NULL_HANDLE, (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)IncludeKey));
}
#endif /* SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA */

TSBXMLSOAPSignatureValidationStatus TElXMLSOAPBaseSignatureHandler::Validate()
{
	TSBXMLSOAPSignatureValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_Validate(_Handle, &OutResultRaw));
	return (TSBXMLSOAPSignatureValidationStatus)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TSBXMLSOAPSignatureValidationStatus TElXMLSOAPBaseSignatureHandler::Validate(TElX509Certificate &Certificate)
{
	TSBXMLSOAPSignatureValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_Validate_1(_Handle, Certificate.getHandle(), &OutResultRaw));
	return (TSBXMLSOAPSignatureValidationStatus)OutResultRaw;
}

TSBXMLSOAPSignatureValidationStatus TElXMLSOAPBaseSignatureHandler::Validate(TElX509Certificate *Certificate)
{
	TSBXMLSOAPSignatureValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_Validate_1(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBXMLSOAPSignatureValidationStatus)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
TSBXMLSOAPSignatureValidationStatus TElXMLSOAPBaseSignatureHandler::Validate(TElXMLKeyInfoData &KeyData)
{
	TSBXMLSOAPSignatureValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_Validate_2(_Handle, KeyData.getHandle(), &OutResultRaw));
	return (TSBXMLSOAPSignatureValidationStatus)OutResultRaw;
}

TSBXMLSOAPSignatureValidationStatus TElXMLSOAPBaseSignatureHandler::Validate(TElXMLKeyInfoData *KeyData)
{
	TSBXMLSOAPSignatureValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_Validate_2(_Handle, (KeyData != NULL) ? KeyData->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBXMLSOAPSignatureValidationStatus)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE int32_t TElXMLSOAPBaseSignatureHandler::AddReference(TElXMLDOMElement &Element)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_AddReference(_Handle, Element.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLSOAPBaseSignatureHandler::AddReference(TElXMLDOMElement *Element)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_AddReference(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE int32_t TElXMLSOAPBaseSignatureHandler::AddReference(TElXMLDOMElement &Element, bool AutoGenerateId)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_AddReference_1(_Handle, Element.getHandle(), (int8_t)AutoGenerateId, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLSOAPBaseSignatureHandler::AddReference(TElXMLDOMElement *Element, bool AutoGenerateId)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_AddReference_1(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, (int8_t)AutoGenerateId, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE int32_t TElXMLSOAPBaseSignatureHandler::AddReference(TElXMLDOMElement &Element, const sb_u16string &CustomId)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_AddReference_2(_Handle, Element.getHandle(), CustomId.data(), (int32_t)CustomId.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLSOAPBaseSignatureHandler::AddReference(TElXMLDOMElement *Element, const sb_u16string &CustomId)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_AddReference_2(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, CustomId.data(), (int32_t)CustomId.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPBaseSignatureHandler::AddReference(TElXMLDOMElement &Element, const std::wstring &CustomId)
{
	int32_t OutResult;
	std::string u16CustomId;
	sb_to_u16string(CustomId, u16CustomId);
	SBCheckError(TElXMLSOAPBaseSignatureHandler_AddReference_2(_Handle, Element.getHandle(), reinterpret_cast<const sb_char16_t*>(u16CustomId.data()), (int32_t)u16CustomId.length() >> 1, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLSOAPBaseSignatureHandler::AddReference(TElXMLDOMElement *Element, const std::wstring &CustomId)
{
	int32_t OutResult;
	std::string u16CustomId;
	sb_to_u16string(CustomId, u16CustomId);
	SBCheckError(TElXMLSOAPBaseSignatureHandler_AddReference_2(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16CustomId.data()), (int32_t)u16CustomId.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLCUSTOMELEMENT
SB_INLINE int32_t TElXMLSOAPBaseSignatureHandler::AddReference(TElXMLCustomElement &Element)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_AddReference_3(_Handle, Element.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLSOAPBaseSignatureHandler::AddReference(TElXMLCustomElement *Element)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_AddReference_3(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLCUSTOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLCUSTOMELEMENT
SB_INLINE int32_t TElXMLSOAPBaseSignatureHandler::AddReference(TElXMLCustomElement &Element, bool AutoGenerateId)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_AddReference_4(_Handle, Element.getHandle(), (int8_t)AutoGenerateId, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLSOAPBaseSignatureHandler::AddReference(TElXMLCustomElement *Element, bool AutoGenerateId)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_AddReference_4(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, (int8_t)AutoGenerateId, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLCUSTOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLCUSTOMELEMENT
SB_INLINE int32_t TElXMLSOAPBaseSignatureHandler::AddReference(TElXMLCustomElement &Element, const sb_u16string &CustomId)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_AddReference_5(_Handle, Element.getHandle(), CustomId.data(), (int32_t)CustomId.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLSOAPBaseSignatureHandler::AddReference(TElXMLCustomElement *Element, const sb_u16string &CustomId)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_AddReference_5(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, CustomId.data(), (int32_t)CustomId.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPBaseSignatureHandler::AddReference(TElXMLCustomElement &Element, const std::wstring &CustomId)
{
	int32_t OutResult;
	std::string u16CustomId;
	sb_to_u16string(CustomId, u16CustomId);
	SBCheckError(TElXMLSOAPBaseSignatureHandler_AddReference_5(_Handle, Element.getHandle(), reinterpret_cast<const sb_char16_t*>(u16CustomId.data()), (int32_t)u16CustomId.length() >> 1, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLSOAPBaseSignatureHandler::AddReference(TElXMLCustomElement *Element, const std::wstring &CustomId)
{
	int32_t OutResult;
	std::string u16CustomId;
	sb_to_u16string(CustomId, u16CustomId);
	SBCheckError(TElXMLSOAPBaseSignatureHandler_AddReference_5(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16CustomId.data()), (int32_t)u16CustomId.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLCUSTOMELEMENT */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElXMLSOAPBaseSignatureHandler::AddReference(TStream &Stream, const sb_u16string &FileNameURI)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_AddReference_6(_Handle, Stream.getHandle(), FileNameURI.data(), (int32_t)FileNameURI.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLSOAPBaseSignatureHandler::AddReference(TStream *Stream, const sb_u16string &FileNameURI)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_AddReference_6(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, FileNameURI.data(), (int32_t)FileNameURI.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPBaseSignatureHandler::AddReference(TStream &Stream, const std::wstring &FileNameURI)
{
	int32_t OutResult;
	std::string u16FileNameURI;
	sb_to_u16string(FileNameURI, u16FileNameURI);
	SBCheckError(TElXMLSOAPBaseSignatureHandler_AddReference_6(_Handle, Stream.getHandle(), reinterpret_cast<const sb_char16_t*>(u16FileNameURI.data()), (int32_t)u16FileNameURI.length() >> 1, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLSOAPBaseSignatureHandler::AddReference(TStream *Stream, const std::wstring &FileNameURI)
{
	int32_t OutResult;
	std::string u16FileNameURI;
	sb_to_u16string(FileNameURI, u16FileNameURI);
	SBCheckError(TElXMLSOAPBaseSignatureHandler_AddReference_6(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16FileNameURI.data()), (int32_t)u16FileNameURI.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE TClassHandle TElXMLSOAPBaseSignatureHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLVERIFIER
TElXMLVerifier* TElXMLSOAPBaseSignatureHandler::get_Verifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_get_Verifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Verifier)
		this->_Inst_Verifier = new TElXMLVerifier(hOutResult, ohFalse);
	else
		this->_Inst_Verifier->updateHandle(hOutResult);
	return this->_Inst_Verifier;
}
#endif /* SB_USE_CLASS_TELXMLVERIFIER */

#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
TElXMLReferenceList* TElXMLSOAPBaseSignatureHandler::get_References()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_get_References(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_References)
		this->_Inst_References = new TElXMLReferenceList(hOutResult, ohFalse);
	else
		this->_Inst_References->updateHandle(hOutResult);
	return this->_Inst_References;
}
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElXMLSOAPBaseSignatureHandler::get_Certificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_get_Certificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

void TElXMLSOAPBaseSignatureHandler::get_KeyName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPBaseSignatureHandler_get_KeyName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-230914508, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPBaseSignatureHandler::get_KeyName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPBaseSignatureHandler_get_KeyName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-230914508, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSOAPBaseSignatureHandler::set_KeyName(const sb_u16string &Value)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_set_KeyName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPBaseSignatureHandler::set_KeyName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPBaseSignatureHandler_set_KeyName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElXMLSOAPBaseSignatureHandler::get_SignerCertificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_get_SignerCertificate(_Handle, &hOutResult));
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
TElXMLKeyInfoData* TElXMLSOAPBaseSignatureHandler::get_SignerKeyData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_get_SignerKeyData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignerKeyData)
		this->_Inst_SignerKeyData = new TElXMLKeyInfoData(hOutResult, ohFalse);
	else
		this->_Inst_SignerKeyData->updateHandle(hOutResult);
	return this->_Inst_SignerKeyData;
}
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

TElXMLDigestMethod TElXMLSOAPBaseSignatureHandler::get_ReferencesDigestMethod()
{
	TElXMLDigestMethodRaw OutResultRaw = 0;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_get_ReferencesDigestMethod(_Handle, &OutResultRaw));
	return (TElXMLDigestMethod)OutResultRaw;
}

SB_INLINE void TElXMLSOAPBaseSignatureHandler::set_ReferencesDigestMethod(TElXMLDigestMethod Value)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_set_ReferencesDigestMethod(_Handle, (TElXMLDigestMethodRaw)Value));
}

#ifdef SB_USE_CLASS_TELXADESPROCESSOR
TElXAdESProcessor* TElXMLSOAPBaseSignatureHandler::get_XAdESProcessor()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_get_XAdESProcessor(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_XAdESProcessor)
		this->_Inst_XAdESProcessor = new TElXAdESProcessor(hOutResult, ohFalse);
	else
		this->_Inst_XAdESProcessor->updateHandle(hOutResult);
	return this->_Inst_XAdESProcessor;
}

SB_INLINE void TElXMLSOAPBaseSignatureHandler::set_XAdESProcessor(TElXAdESProcessor &Value)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_set_XAdESProcessor(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLSOAPBaseSignatureHandler::set_XAdESProcessor(TElXAdESProcessor *Value)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_set_XAdESProcessor(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXADESPROCESSOR */

bool TElXMLSOAPBaseSignatureHandler::get_OwnXAdESProcessor()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLSOAPBaseSignatureHandler_get_OwnXAdESProcessor(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLSOAPBaseSignatureHandler::set_OwnXAdESProcessor(bool Value)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_set_OwnXAdESProcessor(_Handle, (int8_t)Value));
}

SB_INLINE void TElXMLSOAPBaseSignatureHandler::get_OnPrepareSignature(TSBXMLSOAPSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_get_OnPrepareSignature(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXMLSOAPBaseSignatureHandler::set_OnPrepareSignature(TSBXMLSOAPSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_set_OnPrepareSignature(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElXMLSOAPBaseSignatureHandler::get_OnBeforeSign(TSBXMLSOAPSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_get_OnBeforeSign(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXMLSOAPBaseSignatureHandler::set_OnBeforeSign(TSBXMLSOAPSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_set_OnBeforeSign(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElXMLSOAPBaseSignatureHandler::get_OnAfterSign(TSBXMLSOAPSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_get_OnAfterSign(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXMLSOAPBaseSignatureHandler::set_OnAfterSign(TSBXMLSOAPSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXMLSOAPBaseSignatureHandler_set_OnAfterSign(_Handle, pMethodValue, pDataValue));
}

void TElXMLSOAPBaseSignatureHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLVERIFIER
	this->_Inst_Verifier = NULL;
#endif /* SB_USE_CLASS_TELXMLVERIFIER */
#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
	this->_Inst_References = NULL;
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_SignerCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
	this->_Inst_SignerKeyData = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
#ifdef SB_USE_CLASS_TELXADESPROCESSOR
	this->_Inst_XAdESProcessor = NULL;
#endif /* SB_USE_CLASS_TELXADESPROCESSOR */
}

TElXMLSOAPBaseSignatureHandler::TElXMLSOAPBaseSignatureHandler(TElXMLSOAPBaseSignatureHandlerHandle handle, TElOwnHandle ownHandle) : TElXMLSOAPCustomSignatureHandler(handle, ownHandle)
{
	initInstances();
}

TElXMLSOAPBaseSignatureHandler::TElXMLSOAPBaseSignatureHandler(TComponent &Owner) : TElXMLSOAPCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPBaseSignatureHandler_Create(Owner.getHandle(), &_Handle));
}

TElXMLSOAPBaseSignatureHandler::TElXMLSOAPBaseSignatureHandler(TComponent *Owner) : TElXMLSOAPCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPBaseSignatureHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElXMLSOAPBaseSignatureHandler::~TElXMLSOAPBaseSignatureHandler()
{
#ifdef SB_USE_CLASS_TELXMLVERIFIER
	delete this->_Inst_Verifier;
	this->_Inst_Verifier = NULL;
#endif /* SB_USE_CLASS_TELXMLVERIFIER */
#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
	delete this->_Inst_References;
	this->_Inst_References = NULL;
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_SignerCertificate;
	this->_Inst_SignerCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
	delete this->_Inst_SignerKeyData;
	this->_Inst_SignerKeyData = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
#ifdef SB_USE_CLASS_TELXADESPROCESSOR
	delete this->_Inst_XAdESProcessor;
	this->_Inst_XAdESProcessor = NULL;
#endif /* SB_USE_CLASS_TELXADESPROCESSOR */
}
#endif /* SB_USE_CLASS_TELXMLSOAPBASESIGNATUREHANDLER */

};	/* namespace SecureBlackbox */

