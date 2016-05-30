#include "sbhttpocspclient.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELHTTPOCSPCLIENT

bool TElHTTPOCSPClient::SupportsLocation(const std::string &URI)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPOCSPClient_SupportsLocation(_Handle, URI.data(), (int32_t)URI.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

int32_t TElHTTPOCSPClient::PerformRequest(TElOCSPServerError &ServerResult, std::vector<uint8_t> &Reply)
{
	int32_t OutResult;
	TElOCSPServerErrorRaw ServerResultRaw = (TElOCSPServerErrorRaw)ServerResult;
	int32_t szReply = (int32_t)Reply.size();
	uint32_t _err = TElHTTPOCSPClient_PerformRequest(_Handle, &ServerResultRaw, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Reply), &szReply, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Reply.resize(szReply);
		SBCheckError(SBGetLastReturnBuffer(227724039, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Reply), &szReply));
	}
	else
		SBCheckError(_err);

	ServerResult = (TElOCSPServerError)ServerResultRaw;
	Reply.resize(szReply);
	return OutResult;
}

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
TElHTTPSClient* TElHTTPOCSPClient::get_HTTPClient()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPOCSPClient_get_HTTPClient(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HTTPClient)
		this->_Inst_HTTPClient = new TElHTTPSClient(hOutResult, ohFalse);
	else
		this->_Inst_HTTPClient->updateHandle(hOutResult);
	return this->_Inst_HTTPClient;
}

SB_INLINE void TElHTTPOCSPClient::set_HTTPClient(TElHTTPSClient &Value)
{
	SBCheckError(TElHTTPOCSPClient_set_HTTPClient(_Handle, Value.getHandle()));
}

SB_INLINE void TElHTTPOCSPClient::set_HTTPClient(TElHTTPSClient *Value)
{
	SBCheckError(TElHTTPOCSPClient_set_HTTPClient(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

void TElHTTPOCSPClient::initInstances()
{
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
}

TElHTTPOCSPClient::TElHTTPOCSPClient(TElHTTPOCSPClientHandle handle, TElOwnHandle ownHandle) : TElOCSPClient(handle, ownHandle)
{
	initInstances();
}

TElHTTPOCSPClient::TElHTTPOCSPClient(TComponent &Owner) : TElOCSPClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHTTPOCSPClient_Create(Owner.getHandle(), &_Handle));
}

TElHTTPOCSPClient::TElHTTPOCSPClient(TComponent *Owner) : TElOCSPClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHTTPOCSPClient_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElHTTPOCSPClient::~TElHTTPOCSPClient()
{
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	delete this->_Inst_HTTPClient;
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
}
#endif /* SB_USE_CLASS_TELHTTPOCSPCLIENT */

#ifdef SB_USE_CLASS_TELHTTPOCSPCLIENTFACTORY

bool TElHTTPOCSPClientFactory::SupportsLocation(const std::string &URI)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPOCSPClientFactory_SupportsLocation(_Handle, URI.data(), (int32_t)URI.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELOCSPCLIENT
SB_INLINE TElOCSPClientHandle TElHTTPOCSPClientFactory::GetClientInstance(TObject &Validator)
{
	TElOCSPClientHandle OutResult;
	SBCheckError(TElHTTPOCSPClientFactory_GetClientInstance(_Handle, Validator.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElOCSPClientHandle TElHTTPOCSPClientFactory::GetClientInstance(TObject *Validator)
{
	TElOCSPClientHandle OutResult;
	SBCheckError(TElHTTPOCSPClientFactory_GetClientInstance(_Handle, (Validator != NULL) ? Validator->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOCSPCLIENT */

TElHTTPOCSPClientFactory::TElHTTPOCSPClientFactory(TElHTTPOCSPClientFactoryHandle handle, TElOwnHandle ownHandle) : TElCustomOCSPClientFactory(handle, ownHandle)
{
}

TElHTTPOCSPClientFactory::TElHTTPOCSPClientFactory() : TElCustomOCSPClientFactory(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElHTTPOCSPClientFactory_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELHTTPOCSPCLIENTFACTORY */

#ifdef SB_USE_GLOBAL_PROCS_HTTPOCSPCLIENT

SB_INLINE void RegisterHTTPOCSPClientFactory()
{
	SBCheckError(SBHTTPOCSPClient_RegisterHTTPOCSPClientFactory());
}

#endif /* SB_USE_GLOBAL_PROCS_HTTPOCSPCLIENT */

};	/* namespace SecureBlackbox */

