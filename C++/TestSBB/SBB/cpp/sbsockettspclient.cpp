#include "sbsockettspclient.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSOCKETTSPCLIENT

int32_t TElSocketTSPClient::Timestamp(const std::vector<uint8_t> &HashedData, TSBPKIStatus &ServerResult, int32_t &FailureInfo, std::vector<uint8_t> &ReplyCMS)
{
	int32_t OutResult;
	TSBPKIStatusRaw ServerResultRaw = (TSBPKIStatusRaw)ServerResult;
	int32_t szReplyCMS = (int32_t)ReplyCMS.size();
	uint32_t _err = TElSocketTSPClient_Timestamp(_Handle, SB_STD_VECTOR_FRONT_ADR(HashedData), (int32_t)HashedData.size(), &ServerResultRaw, &FailureInfo, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(ReplyCMS), &szReplyCMS, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ReplyCMS.resize(szReplyCMS);
		SBCheckError(SBGetLastReturnBuffer(-1644788189, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(ReplyCMS), &szReplyCMS));
	}
	else
		SBCheckError(_err);

	ServerResult = (TSBPKIStatus)ServerResultRaw;
	ReplyCMS.resize(szReplyCMS);
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSOCKET
TElSocket* TElSocketTSPClient::get_Socket()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSocketTSPClient_get_Socket(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Socket)
		this->_Inst_Socket = new TElSocket(hOutResult, ohFalse);
	else
		this->_Inst_Socket->updateHandle(hOutResult);
	return this->_Inst_Socket;
}
#endif /* SB_USE_CLASS_TELSOCKET */

void TElSocketTSPClient::get_ErrorMessage(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSocketTSPClient_get_ErrorMessage(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1652496563, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSocketTSPClient::get_Address(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSocketTSPClient_get_Address(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1790801784, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSocketTSPClient::set_Address(const std::string &Value)
{
	SBCheckError(TElSocketTSPClient_set_Address(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSocketTSPClient::get_Port()
{
	int32_t OutResult;
	SBCheckError(TElSocketTSPClient_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSocketTSPClient::set_Port(int32_t Value)
{
	SBCheckError(TElSocketTSPClient_set_Port(_Handle, Value));
}

SB_INLINE int32_t TElSocketTSPClient::get_SocketTimeout()
{
	int32_t OutResult;
	SBCheckError(TElSocketTSPClient_get_SocketTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSocketTSPClient::set_SocketTimeout(int32_t Value)
{
	SBCheckError(TElSocketTSPClient_set_SocketTimeout(_Handle, Value));
}

void TElSocketTSPClient::initInstances()
{
#ifdef SB_USE_CLASS_TELSOCKET
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
}

TElSocketTSPClient::TElSocketTSPClient(TElSocketTSPClientHandle handle, TElOwnHandle ownHandle) : TElCustomTSPClient(handle, ownHandle)
{
	initInstances();
}

TElSocketTSPClient::TElSocketTSPClient(TComponent &Owner) : TElCustomTSPClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSocketTSPClient_Create(Owner.getHandle(), &_Handle));
}

TElSocketTSPClient::TElSocketTSPClient(TComponent *Owner) : TElCustomTSPClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSocketTSPClient_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSocketTSPClient::~TElSocketTSPClient()
{
#ifdef SB_USE_CLASS_TELSOCKET
	delete this->_Inst_Socket;
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
}
#endif /* SB_USE_CLASS_TELSOCKETTSPCLIENT */

};	/* namespace SecureBlackbox */

