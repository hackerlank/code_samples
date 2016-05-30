#include "sbrestclient.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELRESTCLIENT

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE int32_t TElRESTClient::Post(const std::string &URL, TElXMLDOMDocument &Content)
{
	int32_t OutResult;
	SBCheckError(TElRESTClient_Post(_Handle, URL.data(), (int32_t)URL.length(), Content.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElRESTClient::Post(const std::string &URL, TElXMLDOMDocument *Content)
{
	int32_t OutResult;
	SBCheckError(TElRESTClient_Post(_Handle, URL.data(), (int32_t)URL.length(), (Content != NULL) ? Content->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELJSONENTITY
SB_INLINE int32_t TElRESTClient::Post(const std::string &URL, TElJsonEntity &Content)
{
	int32_t OutResult;
	SBCheckError(TElRESTClient_Post_1(_Handle, URL.data(), (int32_t)URL.length(), Content.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElRESTClient::Post(const std::string &URL, TElJsonEntity *Content)
{
	int32_t OutResult;
	SBCheckError(TElRESTClient_Post_1(_Handle, URL.data(), (int32_t)URL.length(), (Content != NULL) ? Content->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELJSONENTITY */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE int32_t TElRESTClient::Put(const std::string &URL, TElXMLDOMDocument &Content)
{
	int32_t OutResult;
	SBCheckError(TElRESTClient_Put(_Handle, URL.data(), (int32_t)URL.length(), Content.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElRESTClient::Put(const std::string &URL, TElXMLDOMDocument *Content)
{
	int32_t OutResult;
	SBCheckError(TElRESTClient_Put(_Handle, URL.data(), (int32_t)URL.length(), (Content != NULL) ? Content->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELJSONENTITY
SB_INLINE int32_t TElRESTClient::Put(const std::string &URL, TElJsonEntity &Content)
{
	int32_t OutResult;
	SBCheckError(TElRESTClient_Put_1(_Handle, URL.data(), (int32_t)URL.length(), Content.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElRESTClient::Put(const std::string &URL, TElJsonEntity *Content)
{
	int32_t OutResult;
	SBCheckError(TElRESTClient_Put_1(_Handle, URL.data(), (int32_t)URL.length(), (Content != NULL) ? Content->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELJSONENTITY */

TElXMLCanonicalizationMethod TElRESTClient::get_XMLCanonicalizationMethod()
{
	TElXMLCanonicalizationMethodRaw OutResultRaw = 0;
	SBCheckError(TElRESTClient_get_XMLCanonicalizationMethod(_Handle, &OutResultRaw));
	return (TElXMLCanonicalizationMethod)OutResultRaw;
}

SB_INLINE void TElRESTClient::set_XMLCanonicalizationMethod(TElXMLCanonicalizationMethod Value)
{
	SBCheckError(TElRESTClient_set_XMLCanonicalizationMethod(_Handle, (TElXMLCanonicalizationMethodRaw)Value));
}

void TElRESTClient::get_XMLCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElRESTClient_get_XMLCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-33353051, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElRESTClient::set_XMLCharset(const std::string &Value)
{
	SBCheckError(TElRESTClient_set_XMLCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE char TElRESTClient::get_JSONIndentChar()
{
	char OutResult;
	SBCheckError(TElRESTClient_get_JSONIndentChar(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRESTClient::set_JSONIndentChar(char Value)
{
	SBCheckError(TElRESTClient_set_JSONIndentChar(_Handle, Value));
}

SB_INLINE int32_t TElRESTClient::get_JSONCharsPerIndentLevel()
{
	int32_t OutResult;
	SBCheckError(TElRESTClient_get_JSONCharsPerIndentLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRESTClient::set_JSONCharsPerIndentLevel(int32_t Value)
{
	SBCheckError(TElRESTClient_set_JSONCharsPerIndentLevel(_Handle, Value));
}

TSBRESTResponseType TElRESTClient::get_ResponseType()
{
	TSBRESTResponseTypeRaw OutResultRaw = 0;
	SBCheckError(TElRESTClient_get_ResponseType(_Handle, &OutResultRaw));
	return (TSBRESTResponseType)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
TElXMLDOMDocument* TElRESTClient::get_ResponseXML()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElRESTClient_get_ResponseXML(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ResponseXML)
		this->_Inst_ResponseXML = new TElXMLDOMDocument(hOutResult, ohFalse);
	else
		this->_Inst_ResponseXML->updateHandle(hOutResult);
	return this->_Inst_ResponseXML;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELJSONENTITY
TElJsonEntity* TElRESTClient::get_ResponseJSON()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElRESTClient_get_ResponseJSON(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ResponseJSON)
		this->_Inst_ResponseJSON = new TElJsonEntity(hOutResult, ohFalse);
	else
		this->_Inst_ResponseJSON->updateHandle(hOutResult);
	return this->_Inst_ResponseJSON;
}
#endif /* SB_USE_CLASS_TELJSONENTITY */

void TElRESTClient::get_ResponseText(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElRESTClient_get_ResponseText(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1164557465, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElRESTClient::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
	this->_Inst_ResponseXML = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */
#ifdef SB_USE_CLASS_TELJSONENTITY
	this->_Inst_ResponseJSON = NULL;
#endif /* SB_USE_CLASS_TELJSONENTITY */
}

TElRESTClient::TElRESTClient(TElRESTClientHandle handle, TElOwnHandle ownHandle) : TElHTTPSClient(handle, ownHandle)
{
	initInstances();
}

TElRESTClient::TElRESTClient(TComponent &AOwner) : TElHTTPSClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElRESTClient_Create(AOwner.getHandle(), &_Handle));
}

TElRESTClient::TElRESTClient(TComponent *AOwner) : TElHTTPSClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElRESTClient_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElRESTClient::~TElRESTClient()
{
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
	delete this->_Inst_ResponseXML;
	this->_Inst_ResponseXML = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */
#ifdef SB_USE_CLASS_TELJSONENTITY
	delete this->_Inst_ResponseJSON;
	this->_Inst_ResponseJSON = NULL;
#endif /* SB_USE_CLASS_TELJSONENTITY */
}
#endif /* SB_USE_CLASS_TELRESTCLIENT */

};	/* namespace SecureBlackbox */

