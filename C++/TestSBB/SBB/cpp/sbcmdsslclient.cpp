#include "sbcmdsslclient.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELCOMMANDSSLCLIENT

SB_INLINE int16_t TElCommandSSLClient::SendCmd(const std::string &Command, const std::vector<int16_t> &AcceptCodes)
{
	int16_t OutResult;
	SBCheckError(TElCommandSSLClient_SendCmd(_Handle, Command.data(), (int32_t)Command.length(), SB_STD_VECTOR_FRONT_ADR(AcceptCodes), (int32_t)AcceptCodes.size(), &OutResult));
	return OutResult;
}

void TElCommandSSLClient::get_LastReply(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCommandSSLClient_get_LastReply(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-62805901, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCommandSSLClient::get_OnSent(TSBTextDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCommandSSLClient_get_OnSent(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCommandSSLClient::set_OnSent(TSBTextDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCommandSSLClient_set_OnSent(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCommandSSLClient::get_OnReceived(TSBTextDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCommandSSLClient_get_OnReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCommandSSLClient::set_OnReceived(TSBTextDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCommandSSLClient_set_OnReceived(_Handle, pMethodValue, pDataValue));
}

TElCommandSSLClient::TElCommandSSLClient(TElCommandSSLClientHandle handle, TElOwnHandle ownHandle) : TElSimpleSSLClient(handle, ownHandle)
{
}

TElCommandSSLClient::TElCommandSSLClient(TComponent &AOwner) : TElSimpleSSLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCommandSSLClient_Create(AOwner.getHandle(), &_Handle));
}

TElCommandSSLClient::TElCommandSSLClient(TComponent *AOwner) : TElSimpleSSLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCommandSSLClient_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELCOMMANDSSLCLIENT */

};	/* namespace SecureBlackbox */

