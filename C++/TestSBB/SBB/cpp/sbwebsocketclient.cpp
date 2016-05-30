#include "sbwebsocketclient.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELWEBSOCKETCLIENT

SB_INLINE void TElWebSocketClient::DataAvailable()
{
	SBCheckError(TElWebSocketClient_DataAvailable(_Handle));
}

void TElWebSocketClient::CreateWebSocketKey(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebSocketClient_CreateWebSocketKey((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-445041530, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWebSocketClient::CreateWebSocketKey_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebSocketClient_CreateWebSocketKey_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-445041530, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElWebSocketClient::TElWebSocketClient(TElWebSocketClientHandle handle, TElOwnHandle ownHandle) : TElWebSocketBase(handle, ownHandle)
{
}

TElWebSocketClient::TElWebSocketClient() : TElWebSocketBase(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebSocketClient_Create(&_Handle));
}

#ifdef SB_USE_CLASS_TELSSLCLASS
TElWebSocketClient::TElWebSocketClient(TElSSLClass &Control) : TElWebSocketBase(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebSocketClient_Create_1(Control.getHandle(), &_Handle));
}

TElWebSocketClient::TElWebSocketClient(TElSSLClass *Control) : TElWebSocketBase(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebSocketClient_Create_1((Control != NULL) ? Control->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSLCLASS */

#endif /* SB_USE_CLASS_TELWEBSOCKETCLIENT */

};	/* namespace SecureBlackbox */

