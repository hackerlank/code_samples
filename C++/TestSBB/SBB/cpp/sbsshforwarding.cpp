#include "sbsshforwarding.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSSHFORWARDEDCONNECTION

SB_INLINE void TElSSHForwardedConnection::Close()
{
	SBCheckError(TElSSHForwardedConnection_Close(_Handle));
}

bool TElSSHForwardedConnection::get_AutoAdjustPriority()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHForwardedConnection_get_AutoAdjustPriority(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHForwardedConnection::set_AutoAdjustPriority(bool Value)
{
	SBCheckError(TElSSHForwardedConnection_set_AutoAdjustPriority(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELSOCKET
TElSocket* TElSSHForwardedConnection::get_Socket()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHForwardedConnection_get_Socket(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Socket)
		this->_Inst_Socket = new TElSocket(hOutResult, ohFalse);
	else
		this->_Inst_Socket->updateHandle(hOutResult);
	return this->_Inst_Socket;
}

SB_INLINE void TElSSHForwardedConnection::set_Socket(TElSocket &Value)
{
	SBCheckError(TElSSHForwardedConnection_set_Socket(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSHForwardedConnection::set_Socket(TElSocket *Value)
{
	SBCheckError(TElSSHForwardedConnection_set_Socket(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSOCKET */

SB_INLINE int64_t TElSSHForwardedConnection::get_ReceivedFromSocket()
{
	int64_t OutResult;
	SBCheckError(TElSSHForwardedConnection_get_ReceivedFromSocket(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElSSHForwardedConnection::get_SentToSocket()
{
	int64_t OutResult;
	SBCheckError(TElSSHForwardedConnection_get_SentToSocket(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElSSHForwardedConnection::get_ReceivedFromChannel()
{
	int64_t OutResult;
	SBCheckError(TElSSHForwardedConnection_get_ReceivedFromChannel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElSSHForwardedConnection::get_SentToChannel()
{
	int64_t OutResult;
	SBCheckError(TElSSHForwardedConnection_get_SentToChannel(_Handle, &OutResult));
	return OutResult;
}

TSBSSHForwardingSocketState TElSSHForwardedConnection::get_SocketState()
{
	TSBSSHForwardingSocketStateRaw OutResultRaw = 0;
	SBCheckError(TElSSHForwardedConnection_get_SocketState(_Handle, &OutResultRaw));
	return (TSBSSHForwardingSocketState)OutResultRaw;
}

TSBSSHForwardingChannelState TElSSHForwardedConnection::get_ChannelState()
{
	TSBSSHForwardingChannelStateRaw OutResultRaw = 0;
	SBCheckError(TElSSHForwardedConnection_get_ChannelState(_Handle, &OutResultRaw));
	return (TSBSSHForwardingChannelState)OutResultRaw;
}

SB_INLINE void * TElSSHForwardedConnection::get_Data()
{
	void * OutResult;
	SBCheckError(TElSSHForwardedConnection_get_Data(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHForwardedConnection::set_Data(void * Value)
{
	SBCheckError(TElSSHForwardedConnection_set_Data(_Handle, Value));
}

void TElSSHForwardedConnection::get_ForwardedHost(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHForwardedConnection_get_ForwardedHost(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(704683458, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElSSHForwardedConnection::get_ForwardedPort()
{
	int32_t OutResult;
	SBCheckError(TElSSHForwardedConnection_get_ForwardedPort(_Handle, &OutResult));
	return OutResult;
}

void TElSSHForwardedConnection::get_DestHost(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHForwardedConnection_get_DestHost(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(431025629, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElSSHForwardedConnection::get_DestPort()
{
	int32_t OutResult;
	SBCheckError(TElSSHForwardedConnection_get_DestPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHForwardedConnection::get_BoundPort()
{
	int32_t OutResult;
	SBCheckError(TElSSHForwardedConnection_get_BoundPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHForwardedConnection::get_KeepAlivePeriod()
{
	int32_t OutResult;
	SBCheckError(TElSSHForwardedConnection_get_KeepAlivePeriod(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHForwardedConnection::set_KeepAlivePeriod(int32_t Value)
{
	SBCheckError(TElSSHForwardedConnection_set_KeepAlivePeriod(_Handle, Value));
}

#ifdef SB_WINDOWS
bool TElSSHForwardedConnection::get_DestUsingIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHForwardedConnection_get_DestUsingIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSSHForwardedConnection::get_ForwardedUsingIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHForwardedConnection_get_ForwardedUsingIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif

SB_INLINE int32_t TElSSHForwardedConnection::get_SocketReadBufSize()
{
	int32_t OutResult;
	SBCheckError(TElSSHForwardedConnection_get_SocketReadBufSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHForwardedConnection::set_SocketReadBufSize(int32_t Value)
{
	SBCheckError(TElSSHForwardedConnection_set_SocketReadBufSize(_Handle, Value));
}

SB_INLINE int32_t TElSSHForwardedConnection::get_SocketWriteBufSize()
{
	int32_t OutResult;
	SBCheckError(TElSSHForwardedConnection_get_SocketWriteBufSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHForwardedConnection::set_SocketWriteBufSize(int32_t Value)
{
	SBCheckError(TElSSHForwardedConnection_set_SocketWriteBufSize(_Handle, Value));
}

SB_INLINE int32_t TElSSHForwardedConnection::get_MaxCacheSize()
{
	int32_t OutResult;
	SBCheckError(TElSSHForwardedConnection_get_MaxCacheSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHForwardedConnection::set_MaxCacheSize(int32_t Value)
{
	SBCheckError(TElSSHForwardedConnection_set_MaxCacheSize(_Handle, Value));
}

SB_INLINE int32_t TElSSHForwardedConnection::get_ExitStatus()
{
	int32_t OutResult;
	SBCheckError(TElSSHForwardedConnection_get_ExitStatus(_Handle, &OutResult));
	return OutResult;
}

void TElSSHForwardedConnection::get_ExitSignal(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHForwardedConnection_get_ExitSignal(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1520285217, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSSHForwardedConnection::get_ExitMessage(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHForwardedConnection_get_ExitMessage(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1076528904, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSSHForwardedConnection::initInstances()
{
#ifdef SB_USE_CLASS_TELSOCKET
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
}

TElSSHForwardedConnection::TElSSHForwardedConnection(TElSSHForwardedConnectionHandle handle, TElOwnHandle ownHandle) : TThread(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELSSHFORWARDINGSESSION
TElSSHForwardedConnection::TElSSHForwardedConnection(TElSSHForwardingSession &Owner) : TThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHForwardedConnection_Create(Owner.getHandle(), &_Handle));
}

TElSSHForwardedConnection::TElSSHForwardedConnection(TElSSHForwardingSession *Owner) : TThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHForwardedConnection_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSHFORWARDINGSESSION */

TElSSHForwardedConnection::~TElSSHForwardedConnection()
{
#ifdef SB_USE_CLASS_TELSOCKET
	delete this->_Inst_Socket;
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
}
#endif /* SB_USE_CLASS_TELSSHFORWARDEDCONNECTION */

#ifdef SB_USE_CLASS_TELSSHFORWARDINGTUNNEL

SB_INLINE void TElSSHForwardingTunnel::Open()
{
	SBCheckError(TElSSHForwardingTunnel_Open(_Handle));
}

SB_INLINE void TElSSHForwardingTunnel::Close()
{
	SBCheckError(TElSSHForwardingTunnel_Close(_Handle));
}

bool TElSSHForwardingTunnel::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHForwardingTunnel_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElSSHForwardingTunnel::get_BoundPort()
{
	int32_t OutResult;
	SBCheckError(TElSSHForwardingTunnel_get_BoundPort(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_WINDOWS
bool TElSSHForwardingTunnel::get_UsingIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHForwardingTunnel_get_UsingIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif

void TElSSHForwardingTunnel::get_ForwardedHost(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHForwardingTunnel_get_ForwardedHost(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1956104846, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHForwardingTunnel::set_ForwardedHost(const std::string &Value)
{
	SBCheckError(TElSSHForwardingTunnel_set_ForwardedHost(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSSHForwardingTunnel::get_ForwardedPort()
{
	int32_t OutResult;
	SBCheckError(TElSSHForwardingTunnel_get_ForwardedPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHForwardingTunnel::set_ForwardedPort(int32_t Value)
{
	SBCheckError(TElSSHForwardingTunnel_set_ForwardedPort(_Handle, Value));
}

void TElSSHForwardingTunnel::get_DestHost(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHForwardingTunnel_get_DestHost(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(24189985, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHForwardingTunnel::set_DestHost(const std::string &Value)
{
	SBCheckError(TElSSHForwardingTunnel_set_DestHost(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSSHForwardingTunnel::get_DestPort()
{
	int32_t OutResult;
	SBCheckError(TElSSHForwardingTunnel_get_DestPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHForwardingTunnel::set_DestPort(int32_t Value)
{
	SBCheckError(TElSSHForwardingTunnel_set_DestPort(_Handle, Value));
}

#ifdef SB_WINDOWS
bool TElSSHForwardingTunnel::get_DestUseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHForwardingTunnel_get_DestUseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHForwardingTunnel::set_DestUseIPv6(bool Value)
{
	SBCheckError(TElSSHForwardingTunnel_set_DestUseIPv6(_Handle, (int8_t)Value));
}

bool TElSSHForwardingTunnel::get_ForwardedUseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHForwardingTunnel_get_ForwardedUseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHForwardingTunnel::set_ForwardedUseIPv6(bool Value)
{
	SBCheckError(TElSSHForwardingTunnel_set_ForwardedUseIPv6(_Handle, (int8_t)Value));
}
#endif

bool TElSSHForwardingTunnel::get_UseProxySettingsForForwardedConnections()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHForwardingTunnel_get_UseProxySettingsForForwardedConnections(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHForwardingTunnel::set_UseProxySettingsForForwardedConnections(bool Value)
{
	SBCheckError(TElSSHForwardingTunnel_set_UseProxySettingsForForwardedConnections(_Handle, (int8_t)Value));
}

bool TElSSHForwardingTunnel::get_AutoOpen()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHForwardingTunnel_get_AutoOpen(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHForwardingTunnel::set_AutoOpen(bool Value)
{
	SBCheckError(TElSSHForwardingTunnel_set_AutoOpen(_Handle, (int8_t)Value));
}

bool TElSSHForwardingTunnel::get_UseDefaultBindAddress()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHForwardingTunnel_get_UseDefaultBindAddress(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHForwardingTunnel::set_UseDefaultBindAddress(bool Value)
{
	SBCheckError(TElSSHForwardingTunnel_set_UseDefaultBindAddress(_Handle, (int8_t)Value));
}

bool TElSSHForwardingTunnel::get_UseDynamicForwarding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHForwardingTunnel_get_UseDynamicForwarding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHForwardingTunnel::set_UseDynamicForwarding(bool Value)
{
	SBCheckError(TElSSHForwardingTunnel_set_UseDynamicForwarding(_Handle, (int8_t)Value));
}

bool TElSSHForwardingTunnel::get_ResolveDynamicForwardingAddresses()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHForwardingTunnel_get_ResolveDynamicForwardingAddresses(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHForwardingTunnel::set_ResolveDynamicForwardingAddresses(bool Value)
{
	SBCheckError(TElSSHForwardingTunnel_set_ResolveDynamicForwardingAddresses(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElSSHForwardingTunnel::get_SocketReadBufSize()
{
	int32_t OutResult;
	SBCheckError(TElSSHForwardingTunnel_get_SocketReadBufSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHForwardingTunnel::set_SocketReadBufSize(int32_t Value)
{
	SBCheckError(TElSSHForwardingTunnel_set_SocketReadBufSize(_Handle, Value));
}

SB_INLINE int32_t TElSSHForwardingTunnel::get_SocketWriteBufSize()
{
	int32_t OutResult;
	SBCheckError(TElSSHForwardingTunnel_get_SocketWriteBufSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHForwardingTunnel::set_SocketWriteBufSize(int32_t Value)
{
	SBCheckError(TElSSHForwardingTunnel_set_SocketWriteBufSize(_Handle, Value));
}

SB_INLINE int32_t TElSSHForwardingTunnel::get_MaxCacheSize()
{
	int32_t OutResult;
	SBCheckError(TElSSHForwardingTunnel_get_MaxCacheSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHForwardingTunnel::set_MaxCacheSize(int32_t Value)
{
	SBCheckError(TElSSHForwardingTunnel_set_MaxCacheSize(_Handle, Value));
}

TElSSHForwardingTunnel::TElSSHForwardingTunnel(TElSSHForwardingTunnelHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELSSHCUSTOMFORWARDING
TElSSHForwardingTunnel::TElSSHForwardingTunnel(TElSSHCustomForwarding &Owner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHForwardingTunnel_Create(Owner.getHandle(), &_Handle));
}

TElSSHForwardingTunnel::TElSSHForwardingTunnel(TElSSHCustomForwarding *Owner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHForwardingTunnel_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSHCUSTOMFORWARDING */

#endif /* SB_USE_CLASS_TELSSHFORWARDINGTUNNEL */

#ifdef SB_USE_CLASS_TELSSHFORWARDINGSESSION

void TElSSHForwardingSession::get_Username(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHForwardingSession_get_Username(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(369897355, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHForwardingSession::set_Username(const std::string &Value)
{
	SBCheckError(TElSSHForwardingSession_set_Username(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSSHForwardingSession::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHForwardingSession_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-611291351, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHForwardingSession::set_Password(const std::string &Value)
{
	SBCheckError(TElSSHForwardingSession_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSSHForwardingSession::get_ForwardedPort()
{
	int32_t OutResult;
	SBCheckError(TElSSHForwardingSession_get_ForwardedPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHForwardingSession::set_ForwardedPort(int32_t Value)
{
	SBCheckError(TElSSHForwardingSession_set_ForwardedPort(_Handle, Value));
}

void TElSSHForwardingSession::get_DestHost(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHForwardingSession_get_DestHost(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-907386583, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHForwardingSession::set_DestHost(const std::string &Value)
{
	SBCheckError(TElSSHForwardingSession_set_DestHost(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSSHForwardingSession::get_DestPort()
{
	int32_t OutResult;
	SBCheckError(TElSSHForwardingSession_get_DestPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHForwardingSession::set_DestPort(int32_t Value)
{
	SBCheckError(TElSSHForwardingSession_set_DestPort(_Handle, Value));
}

SB_INLINE void TElSSHForwardingSession::get_OnConnectionOpen(TSBSSHConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHForwardingSession_get_OnConnectionOpen(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHForwardingSession::set_OnConnectionOpen(TSBSSHConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHForwardingSession_set_OnConnectionOpen(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHForwardingSession::get_OnConnectionChange(TSBSSHConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHForwardingSession_get_OnConnectionChange(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHForwardingSession::set_OnConnectionChange(TSBSSHConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHForwardingSession_set_OnConnectionChange(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHForwardingSession::get_OnConnectionRemove(TSBSSHConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHForwardingSession_get_OnConnectionRemove(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHForwardingSession::set_OnConnectionRemove(TSBSSHConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHForwardingSession_set_OnConnectionRemove(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHForwardingSession::get_OnReceive(TSSHReceiveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHForwardingSession_get_OnReceive(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHForwardingSession::set_OnReceive(TSSHReceiveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHForwardingSession_set_OnReceive(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHForwardingSession::get_OnSend(TSSHSendEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHForwardingSession_get_OnSend(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHForwardingSession::set_OnSend(TSSHSendEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHForwardingSession_set_OnSend(_Handle, pMethodValue, pDataValue));
}

TElSSHForwardingSession::TElSSHForwardingSession(TElSSHForwardingSessionHandle handle, TElOwnHandle ownHandle) : TThread(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELSSHCUSTOMFORWARDING
TElSSHForwardingSession::TElSSHForwardingSession(TElSSHCustomForwarding &Owner) : TThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHForwardingSession_Create(Owner.getHandle(), &_Handle));
}

TElSSHForwardingSession::TElSSHForwardingSession(TElSSHCustomForwarding *Owner) : TThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHForwardingSession_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSHCUSTOMFORWARDING */

#endif /* SB_USE_CLASS_TELSSHFORWARDINGSESSION */

#ifdef SB_USE_CLASS_TELSSHCUSTOMFORWARDING

SB_INLINE void TElSSHCustomForwarding::Open()
{
	SBCheckError(TElSSHCustomForwarding_Open(_Handle));
}

SB_INLINE void TElSSHCustomForwarding::Close()
{
	SBCheckError(TElSSHCustomForwarding_Close(_Handle));
}

SB_INLINE void TElSSHCustomForwarding::Close(bool Wait)
{
	SBCheckError(TElSSHCustomForwarding_Close_1(_Handle, (int8_t)Wait));
}

SB_INLINE void TElSSHCustomForwarding::RenegotiateCiphers()
{
	SBCheckError(TElSSHCustomForwarding_RenegotiateCiphers(_Handle));
}

SB_INLINE void TElSSHCustomForwarding::SendIgnore(const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Count)
{
	SBCheckError(TElSSHCustomForwarding_SendIgnore(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), StartIndex, Count));
}

SB_INLINE int32_t TElSSHCustomForwarding::AddTunnel()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_AddTunnel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::RemoveTunnel(int32_t Index)
{
	SBCheckError(TElSSHCustomForwarding_RemoveTunnel(_Handle, Index));
}

SB_INLINE void TElSSHCustomForwarding::ClearTunnels()
{
	SBCheckError(TElSSHCustomForwarding_ClearTunnels(_Handle));
}

SB_INLINE int8_t TElSSHCustomForwarding::get_KexAlgorithm()
{
	int8_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_KexAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSSHCustomForwarding::get_PublicKeyAlgorithm()
{
	uint8_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_PublicKeyAlgorithm(_Handle, &OutResult));
	return OutResult;
}

bool TElSSHCustomForwarding::get_CompressionAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_CompressionAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHCustomForwarding::set_CompressionAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElSSHCustomForwarding_set_CompressionAlgorithms(_Handle, Index, (int8_t)Value));
}

bool TElSSHCustomForwarding::get_EncryptionAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_EncryptionAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHCustomForwarding::set_EncryptionAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElSSHCustomForwarding_set_EncryptionAlgorithms(_Handle, Index, (int8_t)Value));
}

bool TElSSHCustomForwarding::get_KexAlgorithms(int8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_KexAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHCustomForwarding::set_KexAlgorithms(int8_t Index, bool Value)
{
	SBCheckError(TElSSHCustomForwarding_set_KexAlgorithms(_Handle, Index, (int8_t)Value));
}

bool TElSSHCustomForwarding::get_MacAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_MacAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHCustomForwarding::set_MacAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElSSHCustomForwarding_set_MacAlgorithms(_Handle, Index, (int8_t)Value));
}

bool TElSSHCustomForwarding::get_PublicKeyAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_PublicKeyAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHCustomForwarding::set_PublicKeyAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElSSHCustomForwarding_set_PublicKeyAlgorithms(_Handle, Index, (int8_t)Value));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_AuthTypePriorities(int32_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_AuthTypePriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_AuthTypePriorities(int32_t Index, int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_AuthTypePriorities(_Handle, Index, Value));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_PublicKeyAlgorithmPriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_PublicKeyAlgorithmPriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_PublicKeyAlgorithmPriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_PublicKeyAlgorithmPriorities(_Handle, Index, Value));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_EncryptionAlgorithmPriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_EncryptionAlgorithmPriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_EncryptionAlgorithmPriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_EncryptionAlgorithmPriorities(_Handle, Index, Value));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_CompressionAlgorithmPriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_CompressionAlgorithmPriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_CompressionAlgorithmPriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_CompressionAlgorithmPriorities(_Handle, Index, Value));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_MacAlgorithmPriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_MacAlgorithmPriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_MacAlgorithmPriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_MacAlgorithmPriorities(_Handle, Index, Value));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_KexAlgorithmPriorities(int8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_KexAlgorithmPriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_KexAlgorithmPriorities(int8_t Index, int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_KexAlgorithmPriorities(_Handle, Index, Value));
}

#ifdef SB_USE_CLASS_TELSSHFORWARDINGTUNNEL
TElSSHForwardingTunnel* TElSSHCustomForwarding::get_Tunnels(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHCustomForwarding_get_Tunnels(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Tunnels)
		this->_Inst_Tunnels = new TElSSHForwardingTunnel(hOutResult, ohFalse);
	else
		this->_Inst_Tunnels->updateHandle(hOutResult);
	return this->_Inst_Tunnels;
}
#endif /* SB_USE_CLASS_TELSSHFORWARDINGTUNNEL */

bool TElSSHCustomForwarding::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE uint8_t TElSSHCustomForwarding::get_CompressionAlgorithmServerToClient()
{
	uint8_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_CompressionAlgorithmServerToClient(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSSHCustomForwarding::get_CompressionAlgorithmClientToServer()
{
	uint8_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_CompressionAlgorithmClientToServer(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSSHCustomForwarding::get_EncryptionAlgorithmServerToClient()
{
	uint8_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_EncryptionAlgorithmServerToClient(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSSHCustomForwarding::get_EncryptionAlgorithmClientToServer()
{
	uint8_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_EncryptionAlgorithmClientToServer(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSSHCustomForwarding::get_MacAlgorithmServerToClient()
{
	uint8_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_MacAlgorithmServerToClient(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSSHCustomForwarding::get_MacAlgorithmClientToServer()
{
	uint8_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_MacAlgorithmClientToServer(_Handle, &OutResult));
	return OutResult;
}

void TElSSHCustomForwarding::get_ServerCloseReason(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHCustomForwarding_get_ServerCloseReason(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-202344055, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSSHCustomForwarding::get_ServerSoftwareName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHCustomForwarding_get_ServerSoftwareName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-881471461, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSSHVersion TElSSHCustomForwarding::get_Version()
{
	TSSHVersionRaw OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_Version(_Handle, &OutResultRaw));
	return (TSSHVersion)OutResultRaw;
}

SB_INLINE int32_t TElSSHCustomForwarding::get_TunnelCount()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_TunnelCount(_Handle, &OutResult));
	return OutResult;
}

void TElSSHCustomForwarding::get_KbdIntName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHCustomForwarding_get_KbdIntName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1198643245, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSSHCustomForwarding::get_KbdIntInstruction(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHCustomForwarding_get_KbdIntInstruction(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1947523837, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELSSHKEY
TElSSHKey* TElSSHCustomForwarding::get_ServerKey()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHCustomForwarding_get_ServerKey(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ServerKey)
		this->_Inst_ServerKey = new TElSSHKey(hOutResult, ohFalse);
	else
		this->_Inst_ServerKey->updateHandle(hOutResult);
	return this->_Inst_ServerKey;
}
#endif /* SB_USE_CLASS_TELSSHKEY */

SB_INLINE int32_t TElSSHCustomForwarding::get_BoundPort()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_BoundPort(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_WINDOWS
bool TElSSHCustomForwarding::get_UsingIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_UsingIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif

SB_INLINE int64_t TElSSHCustomForwarding::get_TotalBytesSent()
{
	int64_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_TotalBytesSent(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElSSHCustomForwarding::get_TotalBytesReceived()
{
	int64_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_TotalBytesReceived(_Handle, &OutResult));
	return OutResult;
}

void TElSSHCustomForwarding::get_Address(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHCustomForwarding_get_Address(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1812980240, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHCustomForwarding::set_Address(const std::string &Value)
{
	SBCheckError(TElSSHCustomForwarding_set_Address(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_AuthenticationTypes()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_AuthenticationTypes(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_AuthenticationTypes(int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_AuthenticationTypes(_Handle, Value));
}

bool TElSSHCustomForwarding::get_AutoAdjustCiphers()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_AutoAdjustCiphers(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHCustomForwarding::set_AutoAdjustCiphers(bool Value)
{
	SBCheckError(TElSSHCustomForwarding_set_AutoAdjustCiphers(_Handle, (int8_t)Value));
}

void TElSSHCustomForwarding::get_ClientHostname(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHCustomForwarding_get_ClientHostname(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1503891342, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHCustomForwarding::set_ClientHostname(const std::string &Value)
{
	SBCheckError(TElSSHCustomForwarding_set_ClientHostname(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSSHCustomForwarding::get_ClientUsername(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHCustomForwarding_get_ClientUsername(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1152141800, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHCustomForwarding::set_ClientUsername(const std::string &Value)
{
	SBCheckError(TElSSHCustomForwarding_set_ClientUsername(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_CompressionLevel()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_CompressionLevel(int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_CompressionLevel(_Handle, Value));
}

void TElSSHCustomForwarding::get_DestHost(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHCustomForwarding_get_DestHost(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-769238912, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHCustomForwarding::set_DestHost(const std::string &Value)
{
	SBCheckError(TElSSHCustomForwarding_set_DestHost(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_DestPort()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_DestPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_DestPort(int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_DestPort(_Handle, Value));
}

bool TElSSHCustomForwarding::get_ForceCompression()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_ForceCompression(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHCustomForwarding::set_ForceCompression(bool Value)
{
	SBCheckError(TElSSHCustomForwarding_set_ForceCompression(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_ForwardedPort()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_ForwardedPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_ForwardedPort(int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_ForwardedPort(_Handle, Value));
}

void TElSSHCustomForwarding::get_ForwardedHost(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHCustomForwarding_get_ForwardedHost(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(297788119, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHCustomForwarding::set_ForwardedHost(const std::string &Value)
{
	SBCheckError(TElSSHCustomForwarding_set_ForwardedHost(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_KeepAlivePeriod()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_KeepAlivePeriod(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_KeepAlivePeriod(int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_KeepAlivePeriod(_Handle, Value));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_GlobalKeepAlivePeriod()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_GlobalKeepAlivePeriod(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_GlobalKeepAlivePeriod(int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_GlobalKeepAlivePeriod(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
TElSSHCustomKeyStorage* TElSSHCustomForwarding::get_KeyStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHCustomForwarding_get_KeyStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyStorage)
		this->_Inst_KeyStorage = new TElSSHCustomKeyStorage(hOutResult, ohFalse);
	else
		this->_Inst_KeyStorage->updateHandle(hOutResult);
	return this->_Inst_KeyStorage;
}

SB_INLINE void TElSSHCustomForwarding::set_KeyStorage(TElSSHCustomKeyStorage &Value)
{
	SBCheckError(TElSSHCustomForwarding_set_KeyStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSHCustomForwarding::set_KeyStorage(TElSSHCustomKeyStorage *Value)
{
	SBCheckError(TElSSHCustomForwarding_set_KeyStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

void TElSSHCustomForwarding::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHCustomForwarding_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1067690368, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHCustomForwarding::set_Password(const std::string &Value)
{
	SBCheckError(TElSSHCustomForwarding_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_Port()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_Port(int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_Port(_Handle, Value));
}

void TElSSHCustomForwarding::get_SoftwareName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHCustomForwarding_get_SoftwareName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(973518475, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHCustomForwarding::set_SoftwareName(const std::string &Value)
{
	SBCheckError(TElSSHCustomForwarding_set_SoftwareName(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSSHCustomForwarding::get_SynchronizeGUI()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_SynchronizeGUI(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHCustomForwarding::set_SynchronizeGUI(bool Value)
{
	SBCheckError(TElSSHCustomForwarding_set_SynchronizeGUI(_Handle, (int8_t)Value));
}

void TElSSHCustomForwarding::get_Username(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHCustomForwarding_get_Username(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(230692386, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHCustomForwarding::set_Username(const std::string &Value)
{
	SBCheckError(TElSSHCustomForwarding_set_Username(_Handle, Value.data(), (int32_t)Value.length()));
}

TSSHVersions TElSSHCustomForwarding::get_Versions()
{
	TSSHVersionsRaw OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_Versions(_Handle, &OutResultRaw));
	return (TSSHVersions)OutResultRaw;
}

SB_INLINE void TElSSHCustomForwarding::set_Versions(TSSHVersions Value)
{
	SBCheckError(TElSSHCustomForwarding_set_Versions(_Handle, (TSSHVersionsRaw)Value));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_SocketTimeout()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_SocketTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_SocketTimeout(int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_SocketTimeout(_Handle, Value));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_SessionTimeout()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_SessionTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_SessionTimeout(int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_SessionTimeout(_Handle, Value));
}

#ifdef SB_WINDOWS
bool TElSSHCustomForwarding::get_UseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_UseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHCustomForwarding::set_UseIPv6(bool Value)
{
	SBCheckError(TElSSHCustomForwarding_set_UseIPv6(_Handle, (int8_t)Value));
}

#ifndef WINCE
#ifdef SB_USE_CLASS_TELDNSSETTINGS
TElDNSSettings* TElSSHCustomForwarding::get_DNS()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHCustomForwarding_get_DNS(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DNS)
		this->_Inst_DNS = new TElDNSSettings(hOutResult, ohFalse);
	else
		this->_Inst_DNS->updateHandle(hOutResult);
	return this->_Inst_DNS;
}

SB_INLINE void TElSSHCustomForwarding::set_DNS(TElDNSSettings &Value)
{
	SBCheckError(TElSSHCustomForwarding_set_DNS(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSHCustomForwarding::set_DNS(TElDNSSettings *Value)
{
	SBCheckError(TElSSHCustomForwarding_set_DNS(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
#endif

#ifdef SB_USE_CLASS_TELPORTKNOCK
TElPortKnock* TElSSHCustomForwarding::get_PortKnock()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHCustomForwarding_get_PortKnock(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PortKnock)
		this->_Inst_PortKnock = new TElPortKnock(hOutResult, ohFalse);
	else
		this->_Inst_PortKnock->updateHandle(hOutResult);
	return this->_Inst_PortKnock;
}

SB_INLINE void TElSSHCustomForwarding::set_PortKnock(TElPortKnock &Value)
{
	SBCheckError(TElSSHCustomForwarding_set_PortKnock(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSHCustomForwarding::set_PortKnock(TElPortKnock *Value)
{
	SBCheckError(TElSSHCustomForwarding_set_PortKnock(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPORTKNOCK */

TElSocksAuthentication TElSSHCustomForwarding::get_SocksAuthentication()
{
	TElSocksAuthenticationRaw OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_SocksAuthentication(_Handle, &OutResultRaw));
	return (TElSocksAuthentication)OutResultRaw;
}

SB_INLINE void TElSSHCustomForwarding::set_SocksAuthentication(TElSocksAuthentication Value)
{
	SBCheckError(TElSSHCustomForwarding_set_SocksAuthentication(_Handle, (TElSocksAuthenticationRaw)Value));
}

void TElSSHCustomForwarding::get_SocksPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHCustomForwarding_get_SocksPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(713805518, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHCustomForwarding::set_SocksPassword(const std::string &Value)
{
	SBCheckError(TElSSHCustomForwarding_set_SocksPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_SocksPort()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_SocksPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_SocksPort(int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_SocksPort(_Handle, Value));
}

bool TElSSHCustomForwarding::get_SocksResolveAddress()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_SocksResolveAddress(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHCustomForwarding::set_SocksResolveAddress(bool Value)
{
	SBCheckError(TElSSHCustomForwarding_set_SocksResolveAddress(_Handle, (int8_t)Value));
}

void TElSSHCustomForwarding::get_SocksServer(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHCustomForwarding_get_SocksServer(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1023736084, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHCustomForwarding::set_SocksServer(const std::string &Value)
{
	SBCheckError(TElSSHCustomForwarding_set_SocksServer(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
bool TElSSHCustomForwarding::get_SocksUseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_SocksUseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHCustomForwarding::set_SocksUseIPv6(bool Value)
{
	SBCheckError(TElSSHCustomForwarding_set_SocksUseIPv6(_Handle, (int8_t)Value));
}
#endif

void TElSSHCustomForwarding::get_SocksUserCode(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHCustomForwarding_get_SocksUserCode(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1846767564, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHCustomForwarding::set_SocksUserCode(const std::string &Value)
{
	SBCheckError(TElSSHCustomForwarding_set_SocksUserCode(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSocksVersion TElSSHCustomForwarding::get_SocksVersion()
{
	TElSocksVersionRaw OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_SocksVersion(_Handle, &OutResultRaw));
	return (TElSocksVersion)OutResultRaw;
}

SB_INLINE void TElSSHCustomForwarding::set_SocksVersion(TElSocksVersion Value)
{
	SBCheckError(TElSSHCustomForwarding_set_SocksVersion(_Handle, (TElSocksVersionRaw)Value));
}

bool TElSSHCustomForwarding::get_UseSocks()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_UseSocks(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHCustomForwarding::set_UseSocks(bool Value)
{
	SBCheckError(TElSSHCustomForwarding_set_UseSocks(_Handle, (int8_t)Value));
}

bool TElSSHCustomForwarding::get_UseWebTunneling()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_UseWebTunneling(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHCustomForwarding::set_UseWebTunneling(bool Value)
{
	SBCheckError(TElSSHCustomForwarding_set_UseWebTunneling(_Handle, (int8_t)Value));
}

void TElSSHCustomForwarding::get_WebTunnelAddress(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHCustomForwarding_get_WebTunnelAddress(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(483753036, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHCustomForwarding::set_WebTunnelAddress(const std::string &Value)
{
	SBCheckError(TElSSHCustomForwarding_set_WebTunnelAddress(_Handle, Value.data(), (int32_t)Value.length()));
}

TElWebTunnelAuthentication TElSSHCustomForwarding::get_WebTunnelAuthentication()
{
	TElWebTunnelAuthenticationRaw OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_WebTunnelAuthentication(_Handle, &OutResultRaw));
	return (TElWebTunnelAuthentication)OutResultRaw;
}

SB_INLINE void TElSSHCustomForwarding::set_WebTunnelAuthentication(TElWebTunnelAuthentication Value)
{
	SBCheckError(TElSSHCustomForwarding_set_WebTunnelAuthentication(_Handle, (TElWebTunnelAuthenticationRaw)Value));
}

void TElSSHCustomForwarding::get_WebTunnelPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHCustomForwarding_get_WebTunnelPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(33852486, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHCustomForwarding::set_WebTunnelPassword(const std::string &Value)
{
	SBCheckError(TElSSHCustomForwarding_set_WebTunnelPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_WebTunnelPort()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_WebTunnelPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_WebTunnelPort(int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_WebTunnelPort(_Handle, Value));
}

void TElSSHCustomForwarding::get_WebTunnelUserId(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHCustomForwarding_get_WebTunnelUserId(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-238769103, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHCustomForwarding::set_WebTunnelUserId(const std::string &Value)
{
	SBCheckError(TElSSHCustomForwarding_set_WebTunnelUserId(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSSHCustomForwarding::get_WebTunnelRequestHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHCustomForwarding_get_WebTunnelRequestHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_WebTunnelRequestHeaders)
		this->_Inst_WebTunnelRequestHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_WebTunnelRequestHeaders->updateHandle(hOutResult);
	return this->_Inst_WebTunnelRequestHeaders;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSSHCustomForwarding::get_WebTunnelRequestHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHCustomForwarding_get_WebTunnelRequestHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_WebTunnelRequestHeaders)
		this->_Inst_WebTunnelRequestHeaders = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_WebTunnelRequestHeaders->updateHandle(hOutResult);
	return this->_Inst_WebTunnelRequestHeaders;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
TElSocketSettings* TElSSHCustomForwarding::get_SocketSettings()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHCustomForwarding_get_SocketSettings(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SocketSettings)
		this->_Inst_SocketSettings = new TElSocketSettings(hOutResult, ohFalse);
	else
		this->_Inst_SocketSettings->updateHandle(hOutResult);
	return this->_Inst_SocketSettings;
}
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */

TSBSSHForwardingPriority TElSSHCustomForwarding::get_Priority()
{
	TSBSSHForwardingPriorityRaw OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_Priority(_Handle, &OutResultRaw));
	return (TSBSSHForwardingPriority)OutResultRaw;
}

SB_INLINE void TElSSHCustomForwarding::set_Priority(TSBSSHForwardingPriority Value)
{
	SBCheckError(TElSSHCustomForwarding_set_Priority(_Handle, (TSBSSHForwardingPriorityRaw)Value));
}

#ifdef SB_USE_CLASS_TELSSHFORWARDINGINTERCEPT
TElSSHForwardingIntercept* TElSSHCustomForwarding::get_Intercept()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHCustomForwarding_get_Intercept(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Intercept)
		this->_Inst_Intercept = new TElSSHForwardingIntercept(hOutResult, ohFalse);
	else
		this->_Inst_Intercept->updateHandle(hOutResult);
	return this->_Inst_Intercept;
}

SB_INLINE void TElSSHCustomForwarding::set_Intercept(TElSSHForwardingIntercept &Value)
{
	SBCheckError(TElSSHCustomForwarding_set_Intercept(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSHCustomForwarding::set_Intercept(TElSSHForwardingIntercept *Value)
{
	SBCheckError(TElSSHCustomForwarding_set_Intercept(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHFORWARDINGINTERCEPT */

bool TElSSHCustomForwarding::get_CloseIfNoActiveTunnels()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_CloseIfNoActiveTunnels(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHCustomForwarding::set_CloseIfNoActiveTunnels(bool Value)
{
	SBCheckError(TElSSHCustomForwarding_set_CloseIfNoActiveTunnels(_Handle, (int8_t)Value));
}

bool TElSSHCustomForwarding::get_UseUTF8()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_UseUTF8(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHCustomForwarding::set_UseUTF8(bool Value)
{
	SBCheckError(TElSSHCustomForwarding_set_UseUTF8(_Handle, (int8_t)Value));
}

bool TElSSHCustomForwarding::get_RequestPasswordChange()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_RequestPasswordChange(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHCustomForwarding::set_RequestPasswordChange(bool Value)
{
	SBCheckError(TElSSHCustomForwarding_set_RequestPasswordChange(_Handle, (int8_t)Value));
}

TSBSSHCertAuthMode TElSSHCustomForwarding::get_CertAuthMode()
{
	TSBSSHCertAuthModeRaw OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_CertAuthMode(_Handle, &OutResultRaw));
	return (TSBSSHCertAuthMode)OutResultRaw;
}

SB_INLINE void TElSSHCustomForwarding::set_CertAuthMode(TSBSSHCertAuthMode Value)
{
	SBCheckError(TElSSHCustomForwarding_set_CertAuthMode(_Handle, (TSBSSHCertAuthModeRaw)Value));
}

bool TElSSHCustomForwarding::get_AutoAdjustPriority()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_AutoAdjustPriority(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHCustomForwarding::set_AutoAdjustPriority(bool Value)
{
	SBCheckError(TElSSHCustomForwarding_set_AutoAdjustPriority(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_AuthAttempts()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_AuthAttempts(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_AuthAttempts(int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_AuthAttempts(_Handle, Value));
}

TSBSSHAuthOrder TElSSHCustomForwarding::get_SSHAuthOrder()
{
	TSBSSHAuthOrderRaw OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_SSHAuthOrder(_Handle, &OutResultRaw));
	return (TSBSSHAuthOrder)OutResultRaw;
}

SB_INLINE void TElSSHCustomForwarding::set_SSHAuthOrder(TSBSSHAuthOrder Value)
{
	SBCheckError(TElSSHCustomForwarding_set_SSHAuthOrder(_Handle, (TSBSSHAuthOrderRaw)Value));
}

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
TElSSHCustomKeyStorage* TElSSHCustomForwarding::get_TrustedKeys()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHCustomForwarding_get_TrustedKeys(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TrustedKeys)
		this->_Inst_TrustedKeys = new TElSSHCustomKeyStorage(hOutResult, ohFalse);
	else
		this->_Inst_TrustedKeys->updateHandle(hOutResult);
	return this->_Inst_TrustedKeys;
}

SB_INLINE void TElSSHCustomForwarding::set_TrustedKeys(TElSSHCustomKeyStorage &Value)
{
	SBCheckError(TElSSHCustomForwarding_set_TrustedKeys(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSHCustomForwarding::set_TrustedKeys(TElSSHCustomKeyStorage *Value)
{
	SBCheckError(TElSSHCustomForwarding_set_TrustedKeys(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElSSHCustomForwarding::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHCustomForwarding_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElSSHCustomForwarding::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElSSHCustomForwarding_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSHCustomForwarding::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElSSHCustomForwarding_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

SB_INLINE int32_t TElSSHCustomForwarding::get_DefaultWindowSize()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_DefaultWindowSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_DefaultWindowSize(int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_DefaultWindowSize(_Handle, Value));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_MinWindowSize()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_MinWindowSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_MinWindowSize(int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_MinWindowSize(_Handle, Value));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_MaxSSHPacketSize()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_MaxSSHPacketSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_MaxSSHPacketSize(int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_MaxSSHPacketSize(_Handle, Value));
}

bool TElSSHCustomForwarding::get_FlushCachedDataOnClose()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_FlushCachedDataOnClose(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHCustomForwarding::set_FlushCachedDataOnClose(bool Value)
{
	SBCheckError(TElSSHCustomForwarding_set_FlushCachedDataOnClose(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_IncomingSpeedLimit()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_IncomingSpeedLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_IncomingSpeedLimit(int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_IncomingSpeedLimit(_Handle, Value));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_OutgoingSpeedLimit()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_OutgoingSpeedLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_OutgoingSpeedLimit(int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_OutgoingSpeedLimit(_Handle, Value));
}

bool TElSSHCustomForwarding::get_EstablishShellChannel()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_EstablishShellChannel(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHCustomForwarding::set_EstablishShellChannel(bool Value)
{
	SBCheckError(TElSSHCustomForwarding_set_EstablishShellChannel(_Handle, (int8_t)Value));
}

bool TElSSHCustomForwarding::get_ObfuscateHandshake()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_ObfuscateHandshake(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHCustomForwarding::set_ObfuscateHandshake(bool Value)
{
	SBCheckError(TElSSHCustomForwarding_set_ObfuscateHandshake(_Handle, (int8_t)Value));
}

void TElSSHCustomForwarding::get_ObfuscationPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHCustomForwarding_get_ObfuscationPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1275011252, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHCustomForwarding::set_ObfuscationPassword(const std::string &Value)
{
	SBCheckError(TElSSHCustomForwarding_set_ObfuscationPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_SocketReadBufSize()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_SocketReadBufSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_SocketReadBufSize(int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_SocketReadBufSize(_Handle, Value));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_SocketWriteBufSize()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_SocketWriteBufSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_SocketWriteBufSize(int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_SocketWriteBufSize(_Handle, Value));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_MaxCacheSize()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_MaxCacheSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_MaxCacheSize(int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_MaxCacheSize(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELGSSBASEMECHANISM
TElGSSBaseMechanism* TElSSHCustomForwarding::get_GSSMechanism()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHCustomForwarding_get_GSSMechanism(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_GSSMechanism)
		this->_Inst_GSSMechanism = new TElGSSBaseMechanism(hOutResult, ohFalse);
	else
		this->_Inst_GSSMechanism->updateHandle(hOutResult);
	return this->_Inst_GSSMechanism;
}

SB_INLINE void TElSSHCustomForwarding::set_GSSMechanism(TElGSSBaseMechanism &Value)
{
	SBCheckError(TElSSHCustomForwarding_set_GSSMechanism(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSHCustomForwarding::set_GSSMechanism(TElGSSBaseMechanism *Value)
{
	SBCheckError(TElSSHCustomForwarding_set_GSSMechanism(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELGSSBASEMECHANISM */

void TElSSHCustomForwarding::get_GSSHostName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHCustomForwarding_get_GSSHostName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(450902289, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHCustomForwarding::set_GSSHostName(const std::string &Value)
{
	SBCheckError(TElSSHCustomForwarding_set_GSSHostName(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSSHCustomForwarding::get_GSSDelegateCredentials()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHCustomForwarding_get_GSSDelegateCredentials(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHCustomForwarding::set_GSSDelegateCredentials(bool Value)
{
	SBCheckError(TElSSHCustomForwarding_set_GSSDelegateCredentials(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElSSHCustomForwarding::get_InactivityPeriod()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomForwarding_get_InactivityPeriod(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHCustomForwarding::set_InactivityPeriod(int32_t Value)
{
	SBCheckError(TElSSHCustomForwarding_set_InactivityPeriod(_Handle, Value));
}

SB_INLINE void TElSSHCustomForwarding::get_OnAuthenticationKeyboard(TSSHAuthenticationKeyboardEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnAuthenticationKeyboard(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnAuthenticationKeyboard(TSSHAuthenticationKeyboardEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnAuthenticationKeyboard(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnAuthenticationFailed(TSSHAuthenticationFailedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnAuthenticationFailed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnAuthenticationFailed(TSSHAuthenticationFailedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnAuthenticationFailed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnAuthenticationSuccess(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnAuthenticationSuccess(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnAuthenticationSuccess(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnAuthenticationSuccess(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnAuthenticationStart(TSSHAuthenticationStartEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnAuthenticationStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnAuthenticationStart(TSSHAuthenticationStartEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnAuthenticationStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnAuthenticationAttempt(TSSHAuthenticationAttemptEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnAuthenticationAttempt(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnAuthenticationAttempt(TSSHAuthenticationAttemptEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnAuthenticationAttempt(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnBanner(TSSHBannerEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnBanner(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnBanner(TSSHBannerEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnBanner(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnError(TSSHErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnError(TSSHErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnKeyValidate(TSSHKeyValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnKeyValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnKeyValidate(TSSHKeyValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnKeyValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnDebugData(TSSHDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnDebugData(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnDebugData(TSSHDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnDebugData(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnPrivateKeyNeeded(TSSHPrivateKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnPrivateKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnPrivateKeyNeeded(TSSHPrivateKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnPrivateKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnCiphersNegotiated(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnCiphersNegotiated(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnOpen(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnOpen(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnOpen(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnOpen(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnClose(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnClose(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnClose(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnClose(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnConnectionOpen(TSBSSHConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnConnectionOpen(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnConnectionOpen(TSBSSHConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnConnectionOpen(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnConnectionClose(TSBSSHConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnConnectionClose(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnConnectionClose(TSBSSHConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnConnectionClose(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnConnectionChange(TSBSSHConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnConnectionChange(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnConnectionChange(TSBSSHConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnConnectionChange(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnConnectionError(TSBSSHConnectionErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnConnectionError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnConnectionError(TSBSSHConnectionErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnConnectionError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnConnectionWork(TSBSSHConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnConnectionWork(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnConnectionWork(TSBSSHConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnConnectionWork(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnTunnelOpen(TSBSSHTunnelEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnTunnelOpen(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnTunnelOpen(TSBSSHTunnelEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnTunnelOpen(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnTunnelClose(TSBSSHTunnelEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnTunnelClose(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnTunnelClose(TSBSSHTunnelEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnTunnelClose(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnPasswordChangeRequest(TSSHPasswordChangeRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnPasswordChangeRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnPasswordChangeRequest(TSSHPasswordChangeRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnPasswordChangeRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnBeforeConnecting(TSBSSHBeforeConnectingEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnBeforeConnecting(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnBeforeConnecting(TSBSSHBeforeConnectingEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnBeforeConnecting(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnKexInitReceived(TSSHKexInitReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnKexInitReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnKexInitReceived(TSSHKexInitReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnKexInitReceived(_Handle, pMethodValue, pDataValue));
}

#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_INLINE void TElSSHCustomForwarding::get_OnDNSError(TSSHErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnDNSError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnDNSError(TSSHErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnDNSError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnDNSKeyNeeded(TSBDNSKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnDNSKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnDNSKeyNeeded(TSBDNSKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnDNSKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnDNSKeyValidate(TSBDNSKeyValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnDNSKeyValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnDNSKeyValidate(TSBDNSKeyValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnDNSKeyValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHCustomForwarding::get_OnDNSResolve(TSBDNSResolveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHCustomForwarding_get_OnDNSResolve(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHCustomForwarding::set_OnDNSResolve(TSBDNSResolveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHCustomForwarding_set_OnDNSResolve(_Handle, pMethodValue, pDataValue));
}
#endif

void TElSSHCustomForwarding::initInstances()
{
#ifdef SB_USE_CLASS_TELSSHFORWARDINGTUNNEL
	this->_Inst_Tunnels = NULL;
#endif /* SB_USE_CLASS_TELSSHFORWARDINGTUNNEL */
#ifdef SB_USE_CLASS_TELSSHKEY
	this->_Inst_ServerKey = NULL;
#endif /* SB_USE_CLASS_TELSSHKEY */
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
	this->_Inst_KeyStorage = NULL;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
	this->_Inst_DNS = NULL;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
#ifdef SB_USE_CLASS_TELPORTKNOCK
	this->_Inst_PortKnock = NULL;
#endif /* SB_USE_CLASS_TELPORTKNOCK */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_WebTunnelRequestHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_WebTunnelRequestHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
	this->_Inst_SocketSettings = NULL;
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */
#ifdef SB_USE_CLASS_TELSSHFORWARDINGINTERCEPT
	this->_Inst_Intercept = NULL;
#endif /* SB_USE_CLASS_TELSSHFORWARDINGINTERCEPT */
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
	this->_Inst_TrustedKeys = NULL;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELGSSBASEMECHANISM
	this->_Inst_GSSMechanism = NULL;
#endif /* SB_USE_CLASS_TELGSSBASEMECHANISM */
}

TElSSHCustomForwarding::TElSSHCustomForwarding(TElSSHCustomForwardingHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElSSHCustomForwarding::TElSSHCustomForwarding(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHCustomForwarding_Create(AOwner.getHandle(), &_Handle));
}

TElSSHCustomForwarding::TElSSHCustomForwarding(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHCustomForwarding_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSSHCustomForwarding::~TElSSHCustomForwarding()
{
#ifdef SB_USE_CLASS_TELSSHFORWARDINGTUNNEL
	delete this->_Inst_Tunnels;
	this->_Inst_Tunnels = NULL;
#endif /* SB_USE_CLASS_TELSSHFORWARDINGTUNNEL */
#ifdef SB_USE_CLASS_TELSSHKEY
	delete this->_Inst_ServerKey;
	this->_Inst_ServerKey = NULL;
#endif /* SB_USE_CLASS_TELSSHKEY */
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
	delete this->_Inst_KeyStorage;
	this->_Inst_KeyStorage = NULL;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
	delete this->_Inst_DNS;
	this->_Inst_DNS = NULL;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
#ifdef SB_USE_CLASS_TELPORTKNOCK
	delete this->_Inst_PortKnock;
	this->_Inst_PortKnock = NULL;
#endif /* SB_USE_CLASS_TELPORTKNOCK */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_WebTunnelRequestHeaders;
	this->_Inst_WebTunnelRequestHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_WebTunnelRequestHeaders;
	this->_Inst_WebTunnelRequestHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
	delete this->_Inst_SocketSettings;
	this->_Inst_SocketSettings = NULL;
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */
#ifdef SB_USE_CLASS_TELSSHFORWARDINGINTERCEPT
	delete this->_Inst_Intercept;
	this->_Inst_Intercept = NULL;
#endif /* SB_USE_CLASS_TELSSHFORWARDINGINTERCEPT */
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
	delete this->_Inst_TrustedKeys;
	this->_Inst_TrustedKeys = NULL;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELGSSBASEMECHANISM
	delete this->_Inst_GSSMechanism;
	this->_Inst_GSSMechanism = NULL;
#endif /* SB_USE_CLASS_TELGSSBASEMECHANISM */
}
#endif /* SB_USE_CLASS_TELSSHCUSTOMFORWARDING */

#ifdef SB_USE_CLASS_TELSSHFORWARDINGINTERCEPT

TElSSHForwardingIntercept::TElSSHForwardingIntercept(TElSSHForwardingInterceptHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElSSHForwardingIntercept::TElSSHForwardingIntercept(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHForwardingIntercept_Create(AOwner.getHandle(), &_Handle));
}

TElSSHForwardingIntercept::TElSSHForwardingIntercept(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHForwardingIntercept_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELSSHFORWARDINGINTERCEPT */

#ifdef SB_USE_CLASS_TELSSHLOCALPORTFORWARDING

#ifdef SB_WINDOWS
bool TElSSHLocalPortForwarding::get_ForwardedUsingIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHLocalPortForwarding_get_ForwardedUsingIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSSHLocalPortForwarding::get_ForwardedUseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHLocalPortForwarding_get_ForwardedUseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHLocalPortForwarding::set_ForwardedUseIPv6(bool Value)
{
	SBCheckError(TElSSHLocalPortForwarding_set_ForwardedUseIPv6(_Handle, (int8_t)Value));
}
#endif

bool TElSSHLocalPortForwarding::get_ReportRealClientLocationToServer()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHLocalPortForwarding_get_ReportRealClientLocationToServer(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHLocalPortForwarding::set_ReportRealClientLocationToServer(bool Value)
{
	SBCheckError(TElSSHLocalPortForwarding_set_ReportRealClientLocationToServer(_Handle, (int8_t)Value));
}

bool TElSSHLocalPortForwarding::get_UseDynamicForwarding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHLocalPortForwarding_get_UseDynamicForwarding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHLocalPortForwarding::set_UseDynamicForwarding(bool Value)
{
	SBCheckError(TElSSHLocalPortForwarding_set_UseDynamicForwarding(_Handle, (int8_t)Value));
}

bool TElSSHLocalPortForwarding::get_ResolveDynamicForwardingAddresses()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHLocalPortForwarding_get_ResolveDynamicForwardingAddresses(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHLocalPortForwarding::set_ResolveDynamicForwardingAddresses(bool Value)
{
	SBCheckError(TElSSHLocalPortForwarding_set_ResolveDynamicForwardingAddresses(_Handle, (int8_t)Value));
}

SB_INLINE void TElSSHLocalPortForwarding::get_OnAccept(TSBSSHSocketAcceptEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHLocalPortForwarding_get_OnAccept(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHLocalPortForwarding::set_OnAccept(TSBSSHSocketAcceptEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHLocalPortForwarding_set_OnAccept(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHLocalPortForwarding::get_OnConnectionSocksAuthMethodChoose(TSBSSHSocksAuthMethodChooseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHLocalPortForwarding_get_OnConnectionSocksAuthMethodChoose(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHLocalPortForwarding::set_OnConnectionSocksAuthMethodChoose(TSBSSHSocksAuthMethodChooseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHLocalPortForwarding_set_OnConnectionSocksAuthMethodChoose(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHLocalPortForwarding::get_OnConnectionSocksAuthPassword(TSBSSHSocksAuthPasswordEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHLocalPortForwarding_get_OnConnectionSocksAuthPassword(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHLocalPortForwarding::set_OnConnectionSocksAuthPassword(TSBSSHSocksAuthPasswordEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHLocalPortForwarding_set_OnConnectionSocksAuthPassword(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHLocalPortForwarding::get_OnConnectionSocksConnect(TSBSSHSocksConnectEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHLocalPortForwarding_get_OnConnectionSocksConnect(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHLocalPortForwarding::set_OnConnectionSocksConnect(TSBSSHSocksConnectEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHLocalPortForwarding_set_OnConnectionSocksConnect(_Handle, pMethodValue, pDataValue));
}

TElSSHLocalPortForwarding::TElSSHLocalPortForwarding(TElSSHLocalPortForwardingHandle handle, TElOwnHandle ownHandle) : TElSSHCustomForwarding(handle, ownHandle)
{
}

TElSSHLocalPortForwarding::TElSSHLocalPortForwarding(TComponent &AOwner) : TElSSHCustomForwarding(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHLocalPortForwarding_Create(AOwner.getHandle(), &_Handle));
}

TElSSHLocalPortForwarding::TElSSHLocalPortForwarding(TComponent *AOwner) : TElSSHCustomForwarding(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHLocalPortForwarding_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELSSHLOCALPORTFORWARDING */

#ifdef SB_USE_CLASS_TELSSHREMOTEPORTFORWARDING

#ifdef SB_WINDOWS
bool TElSSHRemotePortForwarding::get_DestUsingIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHRemotePortForwarding_get_DestUsingIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
#ifndef WINCE
}

bool TElSSHRemotePortForwarding::get_DestUseDNS()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHRemotePortForwarding_get_DestUseDNS(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHRemotePortForwarding::set_DestUseDNS(bool Value)
{
	SBCheckError(TElSSHRemotePortForwarding_set_DestUseDNS(_Handle, (int8_t)Value));
#endif
}

bool TElSSHRemotePortForwarding::get_DestUseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHRemotePortForwarding_get_DestUseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHRemotePortForwarding::set_DestUseIPv6(bool Value)
{
	SBCheckError(TElSSHRemotePortForwarding_set_DestUseIPv6(_Handle, (int8_t)Value));
}
#endif

bool TElSSHRemotePortForwarding::get_UseDefaultBindAddress()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHRemotePortForwarding_get_UseDefaultBindAddress(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHRemotePortForwarding::set_UseDefaultBindAddress(bool Value)
{
	SBCheckError(TElSSHRemotePortForwarding_set_UseDefaultBindAddress(_Handle, (int8_t)Value));
}

bool TElSSHRemotePortForwarding::get_UseProxySettingsForForwardedConnections()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHRemotePortForwarding_get_UseProxySettingsForForwardedConnections(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHRemotePortForwarding::set_UseProxySettingsForForwardedConnections(bool Value)
{
	SBCheckError(TElSSHRemotePortForwarding_set_UseProxySettingsForForwardedConnections(_Handle, (int8_t)Value));
}

TElSSHRemotePortForwarding::TElSSHRemotePortForwarding(TElSSHRemotePortForwardingHandle handle, TElOwnHandle ownHandle) : TElSSHCustomForwarding(handle, ownHandle)
{
}

TElSSHRemotePortForwarding::TElSSHRemotePortForwarding(TComponent &Owner) : TElSSHCustomForwarding(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHRemotePortForwarding_Create(Owner.getHandle(), &_Handle));
}

TElSSHRemotePortForwarding::TElSSHRemotePortForwarding(TComponent *Owner) : TElSSHCustomForwarding(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHRemotePortForwarding_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELSSHREMOTEPORTFORWARDING */

#ifdef SB_USE_CLASS_TELSSHTUNNELSTATE

TElSSHTunnelState::TElSSHTunnelState(TElSSHTunnelStateHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELSSHFORWARDINGTUNNEL
TElSSHTunnelState::TElSSHTunnelState(TElSSHForwardingTunnel &Tunnel) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHTunnelState_Create(Tunnel.getHandle(), &_Handle));
}

TElSSHTunnelState::TElSSHTunnelState(TElSSHForwardingTunnel *Tunnel) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHTunnelState_Create((Tunnel != NULL) ? Tunnel->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSHFORWARDINGTUNNEL */

#endif /* SB_USE_CLASS_TELSSHTUNNELSTATE */

#ifdef SB_USE_CLASS_TELSSHLPFLISTENINGTHREAD

SB_INLINE void TElSSHLPFListeningThread::get_OnAccept(TSBSSHLPFAcceptEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHLPFListeningThread_get_OnAccept(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHLPFListeningThread::set_OnAccept(TSBSSHLPFAcceptEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHLPFListeningThread_set_OnAccept(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHLPFListeningThread::get_OnListeningStarted(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHLPFListeningThread_get_OnListeningStarted(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHLPFListeningThread::set_OnListeningStarted(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHLPFListeningThread_set_OnListeningStarted(_Handle, pMethodValue, pDataValue));
}

TElSSHLPFListeningThread::TElSSHLPFListeningThread(TElSSHLPFListeningThreadHandle handle, TElOwnHandle ownHandle) : TThread(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELSSHFORWARDINGSESSION
#ifdef SB_WINDOWS
TElSSHLPFListeningThread::TElSSHLPFListeningThread(TElSSHForwardingSession &Owner, const std::string &Address, int32_t Port, bool UseIPv6) : TThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElSSHLPFListeningThread::TElSSHLPFListeningThread(TElSSHForwardingSession &Owner, const std::string &Address, int32_t Port) : TThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
#ifdef SB_WINDOWS
	SBCheckError(TElSSHLPFListeningThread_Create(Owner.getHandle(), Address.data(), (int32_t)Address.length(), Port, (int8_t)UseIPv6, &_Handle));
#else
	SBCheckError(TElSSHLPFListeningThread_Create(Owner.getHandle(), Address.data(), (int32_t)Address.length(), Port, &_Handle));
#endif
}

#ifdef SB_WINDOWS
TElSSHLPFListeningThread::TElSSHLPFListeningThread(TElSSHForwardingSession *Owner, const std::string &Address, int32_t Port, bool UseIPv6) : TThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElSSHLPFListeningThread::TElSSHLPFListeningThread(TElSSHForwardingSession *Owner, const std::string &Address, int32_t Port) : TThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
#ifdef SB_WINDOWS
	SBCheckError(TElSSHLPFListeningThread_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, Address.data(), (int32_t)Address.length(), Port, (int8_t)UseIPv6, &_Handle));
#else
	SBCheckError(TElSSHLPFListeningThread_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, Address.data(), (int32_t)Address.length(), Port, &_Handle));
#endif
}
#endif /* SB_USE_CLASS_TELSSHFORWARDINGSESSION */

#endif /* SB_USE_CLASS_TELSSHLPFLISTENINGTHREAD */

#ifdef SB_USE_CLASS_TELSSHLOCALTUNNELSTATE

TElSSHLocalTunnelState::TElSSHLocalTunnelState(TElSSHLocalTunnelStateHandle handle, TElOwnHandle ownHandle) : TElSSHTunnelState(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELSSHFORWARDINGTUNNEL
TElSSHLocalTunnelState::TElSSHLocalTunnelState(TElSSHForwardingTunnel &Tunnel) : TElSSHTunnelState(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHLocalTunnelState_Create(Tunnel.getHandle(), &_Handle));
}

TElSSHLocalTunnelState::TElSSHLocalTunnelState(TElSSHForwardingTunnel *Tunnel) : TElSSHTunnelState(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHLocalTunnelState_Create((Tunnel != NULL) ? Tunnel->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSHFORWARDINGTUNNEL */

#endif /* SB_USE_CLASS_TELSSHLOCALTUNNELSTATE */

#ifdef SB_USE_CLASS_TELSSHREMOTETUNNELSTATE

TElSSHRemoteTunnelState::TElSSHRemoteTunnelState(TElSSHRemoteTunnelStateHandle handle, TElOwnHandle ownHandle) : TElSSHTunnelState(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELSSHFORWARDINGTUNNEL
TElSSHRemoteTunnelState::TElSSHRemoteTunnelState(TElSSHForwardingTunnel &Tunnel) : TElSSHTunnelState(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHRemoteTunnelState_Create(Tunnel.getHandle(), &_Handle));
}

TElSSHRemoteTunnelState::TElSSHRemoteTunnelState(TElSSHForwardingTunnel *Tunnel) : TElSSHTunnelState(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHRemoteTunnelState_Create((Tunnel != NULL) ? Tunnel->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSHFORWARDINGTUNNEL */

#endif /* SB_USE_CLASS_TELSSHREMOTETUNNELSTATE */

#ifdef SB_USE_CLASS_TELSSHLOCALPORTFORWARDINGSESSION

TElSSHLocalPortForwardingSession::TElSSHLocalPortForwardingSession(TElSSHLocalPortForwardingSessionHandle handle, TElOwnHandle ownHandle) : TElSSHForwardingSession(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELSSHCUSTOMFORWARDING
TElSSHLocalPortForwardingSession::TElSSHLocalPortForwardingSession(TElSSHCustomForwarding &Owner) : TElSSHForwardingSession(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHLocalPortForwardingSession_Create(Owner.getHandle(), &_Handle));
}

TElSSHLocalPortForwardingSession::TElSSHLocalPortForwardingSession(TElSSHCustomForwarding *Owner) : TElSSHForwardingSession(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHLocalPortForwardingSession_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSHCUSTOMFORWARDING */

#endif /* SB_USE_CLASS_TELSSHLOCALPORTFORWARDINGSESSION */

#ifdef SB_USE_CLASS_TELSSHREMOTEPORTFORWARDINGSESSION

TElSSHRemotePortForwardingSession::TElSSHRemotePortForwardingSession(TElSSHRemotePortForwardingSessionHandle handle, TElOwnHandle ownHandle) : TElSSHForwardingSession(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELSSHCUSTOMFORWARDING
TElSSHRemotePortForwardingSession::TElSSHRemotePortForwardingSession(TElSSHCustomForwarding &Owner) : TElSSHForwardingSession(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHRemotePortForwardingSession_Create(Owner.getHandle(), &_Handle));
}

TElSSHRemotePortForwardingSession::TElSSHRemotePortForwardingSession(TElSSHCustomForwarding *Owner) : TElSSHForwardingSession(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHRemotePortForwardingSession_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSHCUSTOMFORWARDING */

#endif /* SB_USE_CLASS_TELSSHREMOTEPORTFORWARDINGSESSION */

#ifdef SB_USE_CLASS_TELSSHSCHEDULEDSPECIALMESSAGE

TElSSHScheduledSpecialMessage::TElSSHScheduledSpecialMessage(TElSSHScheduledSpecialMessageHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSSHScheduledSpecialMessage::TElSSHScheduledSpecialMessage(int32_t Code, const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Count) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHScheduledSpecialMessage_Create(Code, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), StartIndex, Count, &_Handle));
}

#endif /* SB_USE_CLASS_TELSSHSCHEDULEDSPECIALMESSAGE */

};	/* namespace SecureBlackbox */
