#include "sbhttptspclient.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELHTTPTSPCLIENT

int32_t TElHTTPTSPClient::Timestamp(const std::vector<uint8_t> &HashedData, TSBPKIStatus &ServerResult, int32_t &FailureInfo, std::vector<uint8_t> &ReplyCMS)
{
	int32_t OutResult;
	TSBPKIStatusRaw ServerResultRaw = (TSBPKIStatusRaw)ServerResult;
	int32_t szReplyCMS = (int32_t)ReplyCMS.size();
	uint32_t _err = TElHTTPTSPClient_Timestamp(_Handle, SB_STD_VECTOR_FRONT_ADR(HashedData), (int32_t)HashedData.size(), &ServerResultRaw, &FailureInfo, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(ReplyCMS), &szReplyCMS, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ReplyCMS.resize(szReplyCMS);
		SBCheckError(SBGetLastReturnBuffer(1617160327, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(ReplyCMS), &szReplyCMS));
	}
	else
		SBCheckError(_err);

	ServerResult = (TSBPKIStatus)ServerResultRaw;
	ReplyCMS.resize(szReplyCMS);
	return OutResult;
}

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
TElHTTPSClient* TElHTTPTSPClient::get_HTTPClient()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPTSPClient_get_HTTPClient(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HTTPClient)
		this->_Inst_HTTPClient = new TElHTTPSClient(hOutResult, ohFalse);
	else
		this->_Inst_HTTPClient->updateHandle(hOutResult);
	return this->_Inst_HTTPClient;
}

SB_INLINE void TElHTTPTSPClient::set_HTTPClient(TElHTTPSClient &Value)
{
	SBCheckError(TElHTTPTSPClient_set_HTTPClient(_Handle, Value.getHandle()));
}

SB_INLINE void TElHTTPTSPClient::set_HTTPClient(TElHTTPSClient *Value)
{
	SBCheckError(TElHTTPTSPClient_set_HTTPClient(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

void TElHTTPTSPClient::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPTSPClient_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(821609747, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPTSPClient::set_URL(const std::string &Value)
{
	SBCheckError(TElHTTPTSPClient_set_URL(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElHTTPTSPClient::get_OnHTTPError(TSBHTTPTSPErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPTSPClient_get_OnHTTPError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPTSPClient::set_OnHTTPError(TSBHTTPTSPErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPTSPClient_set_OnHTTPError(_Handle, pMethodValue, pDataValue));
}

void TElHTTPTSPClient::initInstances()
{
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
}

TElHTTPTSPClient::TElHTTPTSPClient(TElHTTPTSPClientHandle handle, TElOwnHandle ownHandle) : TElCustomTSPClient(handle, ownHandle)
{
	initInstances();
}

TElHTTPTSPClient::TElHTTPTSPClient(TComponent &AOwner) : TElCustomTSPClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHTTPTSPClient_Create(AOwner.getHandle(), &_Handle));
}

TElHTTPTSPClient::TElHTTPTSPClient(TComponent *AOwner) : TElCustomTSPClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHTTPTSPClient_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElHTTPTSPClient::~TElHTTPTSPClient()
{
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	delete this->_Inst_HTTPClient;
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
}
#endif /* SB_USE_CLASS_TELHTTPTSPCLIENT */

};	/* namespace SecureBlackbox */

