#include "sbsocket.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSOCKET

#ifdef SB_WINDOWS
bool TElSocket::LoadIPv6Proc(const std::string &ProcName, void * &Proc, int32_t &WinsockUsed, int32_t &Wship6Used)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSocket_LoadIPv6Proc(ProcName.data(), (int32_t)ProcName.length(), &Proc, &WinsockUsed, &Wship6Used, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSocket::LoadIPv6Proc_Inst(const std::string &ProcName, void * &Proc, int32_t &WinsockUsed, int32_t &Wship6Used)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSocket_LoadIPv6Proc_1(_Handle, ProcName.data(), (int32_t)ProcName.length(), &Proc, &WinsockUsed, &Wship6Used, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSocket::InitializeIPv6()
{
	SBCheckError(TElSocket_InitializeIPv6());
}

SB_INLINE void TElSocket::InitializeIPv6_Inst()
{
	SBCheckError(TElSocket_InitializeIPv6_1(_Handle));
}

SB_INLINE void TElSocket::FinalizeIPv6()
{
	SBCheckError(TElSocket_FinalizeIPv6());
}

SB_INLINE void TElSocket::FinalizeIPv6_Inst()
{
	SBCheckError(TElSocket_FinalizeIPv6_1(_Handle));
}
#endif

SB_INLINE void TElSocket::ShutdownSocket()
{
	SBCheckError(TElSocket_ShutdownSocket(_Handle));
}

SB_INLINE void TElSocket::ShutdownSocket(TElShutdownDirection Direction)
{
	SBCheckError(TElSocket_ShutdownSocket_1(_Handle, (TElShutdownDirectionRaw)Direction));
}

SB_INLINE void TElSocket::Close(bool Forced)
{
	SBCheckError(TElSocket_Close(_Handle, (int8_t)Forced));
}

SB_INLINE void TElSocket::Close(bool Forced, int32_t Timeout)
{
	SBCheckError(TElSocket_Close_1(_Handle, (int8_t)Forced, Timeout));
}

SB_INLINE void TElSocket::Close(bool Forced, int32_t Timeout, bool Gradually)
{
	SBCheckError(TElSocket_Close_2(_Handle, (int8_t)Forced, Timeout, (int8_t)Gradually));
}

SB_INLINE int32_t TElSocket::StartAsyncConnect()
{
	int32_t OutResult;
	SBCheckError(TElSocket_StartAsyncConnect(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSocket::AsyncConnect(int32_t Timeout)
{
	int32_t OutResult;
	SBCheckError(TElSocket_AsyncConnect(_Handle, Timeout, &OutResult));
	return OutResult;
}

SB_INLINE void TElSocket::FinalizeWinSock()
{
	SBCheckError(TElSocket_FinalizeWinSock());
}

SB_INLINE void TElSocket::FinalizeWinSock_Inst()
{
	SBCheckError(TElSocket_FinalizeWinSock_1(_Handle));
}

SB_INLINE void TElSocket::InitializeWinSock()
{
	SBCheckError(TElSocket_InitializeWinSock());
}

SB_INLINE void TElSocket::InitializeWinSock_Inst()
{
	SBCheckError(TElSocket_InitializeWinSock_1(_Handle));
}

SB_INLINE int32_t TElSocket::LastNetError()
{
	int32_t OutResult;
	SBCheckError(TElSocket_LastNetError(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_WINDOWS
void TElSocket::IPFromHost(const std::string &Host, bool UseIPv6, std::string &OutResult)
#else
void TElSocket::IPFromHost(const std::string &Host, std::string &OutResult)
#endif
{
	int32_t szOutResult = (int32_t)OutResult.length();
#ifdef SB_WINDOWS
	uint32_t _err = TElSocket_IPFromHost(_Handle, Host.data(), (int32_t)Host.length(), (int8_t)UseIPv6, (char *)OutResult.data(), &szOutResult);
#else
	uint32_t _err = TElSocket_IPFromHost(_Handle, Host.data(), (int32_t)Host.length(), (char *)OutResult.data(), &szOutResult);
#endif
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
#ifdef SB_WINDOWS
		SBCheckError(SBGetLastReturnStringA(-315278357, 3, (char *)OutResult.data(), &szOutResult));
#else
		SBCheckError(SBGetLastReturnStringA(-60845863, 2, (char *)OutResult.data(), &szOutResult));
#endif
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElSocket::Receive(void * Data, int32_t DataLen, int32_t &Received)
{
	int32_t OutResult;
	SBCheckError(TElSocket_Receive(_Handle, Data, DataLen, &Received, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSocket::Send(void * Data, int32_t DataLen, int32_t &Sent)
{
	int32_t OutResult;
	SBCheckError(TElSocket_Send(_Handle, Data, DataLen, &Sent, &OutResult));
	return OutResult;
}

int32_t TElSocket::ReceiveFrom(void * Data, int32_t DataLen, int32_t &Received, std::string &RemoteAddress, uint16_t &RemotePort)
{
	int32_t OutResult;
	int32_t szRemoteAddress = (int32_t)RemoteAddress.length();
	uint32_t _err = TElSocket_ReceiveFrom(_Handle, Data, DataLen, &Received, (char *)RemoteAddress.data(), &szRemoteAddress, &RemotePort, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		RemoteAddress.resize(szRemoteAddress);
		SBCheckError(SBGetLastReturnStringA(-1713200769, 4, (char *)RemoteAddress.data(), &szRemoteAddress));
	}
	else
		SBCheckError(_err);

	RemoteAddress.resize(szRemoteAddress);
	return OutResult;
}

SB_INLINE int32_t TElSocket::SendTo(void * Data, int32_t DataLen, int32_t &Sent, const std::string &RemoteAddress, uint16_t RemotePort)
{
	int32_t OutResult;
	SBCheckError(TElSocket_SendTo(_Handle, Data, DataLen, &Sent, RemoteAddress.data(), (int32_t)RemoteAddress.length(), RemotePort, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
SB_INLINE void TElSocket::ApplySettings(TElSocketSettings &Settings)
{
	SBCheckError(TElSocket_ApplySettings(_Handle, Settings.getHandle()));
}

SB_INLINE void TElSocket::ApplySettings(TElSocketSettings *Settings)
{
	SBCheckError(TElSocket_ApplySettings(_Handle, (Settings != NULL) ? Settings->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */

SB_INLINE int32_t TElSocket::Connect(int32_t Timeout)
{
	int32_t OutResult;
	SBCheckError(TElSocket_Connect(_Handle, Timeout, &OutResult));
	return OutResult;
}

bool TElSocket::CanReceive(int32_t WaitTime)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSocket_CanReceive(_Handle, WaitTime, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSocket::CanSend(int32_t WaitTime)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSocket_CanSend(_Handle, WaitTime, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSocket::CanAccept(int32_t WaitTime)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSocket_CanAccept(_Handle, WaitTime, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElSocket::Bind()
{
	int32_t OutResult;
	SBCheckError(TElSocket_Bind(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSocket::Bind(bool Outgoing)
{
	int32_t OutResult;
	SBCheckError(TElSocket_Bind_1(_Handle, (int8_t)Outgoing, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSocket::Bind(bool Outgoing, bool ReuseAddress)
{
	int32_t OutResult;
	SBCheckError(TElSocket_Bind_2(_Handle, (int8_t)Outgoing, (int8_t)ReuseAddress, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSocket::Listen()
{
	int32_t OutResult;
	SBCheckError(TElSocket_Listen(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSocket::Accept(int32_t Timeout)
{
	int32_t OutResult;
	SBCheckError(TElSocket_Accept(_Handle, Timeout, &OutResult));
	return OutResult;
}

void TElSocket::Accept(int32_t Timeout, TElSocket &Socket)
{
	TElClassHandle hSocket = Socket.getHandle();
	SBCheckError(TElSocket_Accept_1(_Handle, Timeout, &hSocket));
	Socket.updateHandle(hSocket);
}

SB_INLINE int32_t TElSocket::AsyncConnectEx(int32_t Timeout, TElSocket &SecondarySocket, bool SecSend, bool SecRecv, TElSocketSecondaryEvent pMethodSecEvent, void * pDataSecEvent)
{
	int32_t OutResult;
	SBCheckError(TElSocket_AsyncConnectEx(_Handle, Timeout, SecondarySocket.getHandle(), (int8_t)SecSend, (int8_t)SecRecv, pMethodSecEvent, pDataSecEvent, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSocket::AsyncConnectEx(int32_t Timeout, TElSocket *SecondarySocket, bool SecSend, bool SecRecv, TElSocketSecondaryEvent pMethodSecEvent, void * pDataSecEvent)
{
	int32_t OutResult;
	SBCheckError(TElSocket_AsyncConnectEx(_Handle, Timeout, (SecondarySocket != NULL) ? SecondarySocket->getHandle() : SB_NULL_HANDLE, (int8_t)SecSend, (int8_t)SecRecv, pMethodSecEvent, pDataSecEvent, &OutResult));
	return OutResult;
}

SB_INLINE void TElSocket::SocksAccept(int32_t Timeout, TSBSocksAuthMethodChooseEvent pMethodOnAuthMethodChoose, void * pDataOnAuthMethodChoose, TSBSocksAuthPasswordEvent pMethodOnAuthPassword, void * pDataOnAuthPassword, TSBSocksConnectEvent pMethodOnConnect, void * pDataOnConnect, bool CloseConnectionOnError, bool ResolveAddress)
{
	SBCheckError(TElSocket_SocksAccept(_Handle, Timeout, pMethodOnAuthMethodChoose, pDataOnAuthMethodChoose, pMethodOnAuthPassword, pDataOnAuthPassword, pMethodOnConnect, pDataOnConnect, (int8_t)CloseConnectionOnError, (int8_t)ResolveAddress));
}

void TElSocket::get_LocalHostName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSocket_get_LocalHostName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1492429101, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSocket::get_RemoteAddress(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSocket_get_RemoteAddress(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1188633256, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElSocket::get_ProxyResult()
{
	int32_t OutResult;
	SBCheckError(TElSocket_get_ProxyResult(_Handle, &OutResult));
	return OutResult;
}

TElSocketType TElSocket::get_SocketType()
{
	TElSocketTypeRaw OutResultRaw = 0;
	SBCheckError(TElSocket_get_SocketType(_Handle, &OutResultRaw));
	return (TElSocketType)OutResultRaw;
}

SB_INLINE void TElSocket::set_SocketType(TElSocketType Value)
{
	SBCheckError(TElSocket_set_SocketType(_Handle, (TElSocketTypeRaw)Value));
}

TElSocketState TElSocket::get_State()
{
	TElSocketStateRaw OutResultRaw = 0;
	SBCheckError(TElSocket_get_State(_Handle, &OutResultRaw));
	return (TElSocketState)OutResultRaw;
}

#ifdef SB_WINDOWS
bool TElSocket::get_UsingIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSocket_get_UsingIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif

SB_INLINE int32_t TElSocket::get_BoundPort()
{
	int32_t OutResult;
	SBCheckError(TElSocket_get_BoundPort(_Handle, &OutResult));
	return OutResult;
}

void TElSocket::get_BoundAddress(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSocket_get_BoundAddress(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(498729403, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElSocket::get_NativeSocket()
{
	int32_t OutResult;
	SBCheckError(TElSocket_get_NativeSocket(_Handle, &OutResult));
	return OutResult;
}

void TElSocket::get_Address(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSocket_get_Address(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-185937582, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSocket::set_Address(const std::string &Value)
{
	SBCheckError(TElSocket_set_Address(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSocket::get_Port()
{
	int32_t OutResult;
	SBCheckError(TElSocket_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSocket::set_Port(int32_t Value)
{
	SBCheckError(TElSocket_set_Port(_Handle, Value));
}

SB_INLINE int32_t TElSocket::get_ListenPort()
{
	int32_t OutResult;
	SBCheckError(TElSocket_get_ListenPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSocket::set_ListenPort(int32_t Value)
{
	SBCheckError(TElSocket_set_ListenPort(_Handle, Value));
}

SB_INLINE int32_t TElSocket::get_ListenPortRangeFrom()
{
	int32_t OutResult;
	SBCheckError(TElSocket_get_ListenPortRangeFrom(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSocket::set_ListenPortRangeFrom(int32_t Value)
{
	SBCheckError(TElSocket_set_ListenPortRangeFrom(_Handle, Value));
}

SB_INLINE int32_t TElSocket::get_ListenPortRangeTo()
{
	int32_t OutResult;
	SBCheckError(TElSocket_get_ListenPortRangeTo(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSocket::set_ListenPortRangeTo(int32_t Value)
{
	SBCheckError(TElSocket_set_ListenPortRangeTo(_Handle, Value));
}

void TElSocket::get_ListenAddress(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSocket_get_ListenAddress(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-936566027, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSocket::set_ListenAddress(const std::string &Value)
{
	SBCheckError(TElSocket_set_ListenAddress(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
TElClientSocketBinding* TElSocket::get_ListenBinding()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSocket_get_ListenBinding(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ListenBinding)
		this->_Inst_ListenBinding = new TElClientSocketBinding(hOutResult, ohFalse);
	else
		this->_Inst_ListenBinding->updateHandle(hOutResult);
	return this->_Inst_ListenBinding;
}

SB_INLINE void TElSocket::set_ListenBinding(TElClientSocketBinding &Value)
{
	SBCheckError(TElSocket_set_ListenBinding(_Handle, Value.getHandle()));
}

SB_INLINE void TElSocket::set_ListenBinding(TElClientSocketBinding *Value)
{
	SBCheckError(TElSocket_set_ListenBinding(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
TElClientSocketBinding* TElSocket::get_OutgoingLocalBinding()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSocket_get_OutgoingLocalBinding(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OutgoingLocalBinding)
		this->_Inst_OutgoingLocalBinding = new TElClientSocketBinding(hOutResult, ohFalse);
	else
		this->_Inst_OutgoingLocalBinding->updateHandle(hOutResult);
	return this->_Inst_OutgoingLocalBinding;
}

SB_INLINE void TElSocket::set_OutgoingLocalBinding(TElClientSocketBinding &Value)
{
	SBCheckError(TElSocket_set_OutgoingLocalBinding(_Handle, Value.getHandle()));
}

SB_INLINE void TElSocket::set_OutgoingLocalBinding(TElClientSocketBinding *Value)
{
	SBCheckError(TElSocket_set_OutgoingLocalBinding(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

SB_INLINE int32_t TElSocket::get_IncomingSpeedLimit()
{
	int32_t OutResult;
	SBCheckError(TElSocket_get_IncomingSpeedLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSocket::set_IncomingSpeedLimit(int32_t Value)
{
	SBCheckError(TElSocket_set_IncomingSpeedLimit(_Handle, Value));
}

SB_INLINE int32_t TElSocket::get_OutgoingSpeedLimit()
{
	int32_t OutResult;
	SBCheckError(TElSocket_get_OutgoingSpeedLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSocket::set_OutgoingSpeedLimit(int32_t Value)
{
	SBCheckError(TElSocket_set_OutgoingSpeedLimit(_Handle, Value));
}

TElSocksAuthentication TElSocket::get_SocksAuthentication()
{
	TElSocksAuthenticationRaw OutResultRaw = 0;
	SBCheckError(TElSocket_get_SocksAuthentication(_Handle, &OutResultRaw));
	return (TElSocksAuthentication)OutResultRaw;
}

SB_INLINE void TElSocket::set_SocksAuthentication(TElSocksAuthentication Value)
{
	SBCheckError(TElSocket_set_SocksAuthentication(_Handle, (TElSocksAuthenticationRaw)Value));
}

void TElSocket::get_SocksPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSocket_get_SocksPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(545657263, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSocket::set_SocksPassword(const std::string &Value)
{
	SBCheckError(TElSocket_set_SocksPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSocket::get_SocksPort()
{
	int32_t OutResult;
	SBCheckError(TElSocket_get_SocksPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSocket::set_SocksPort(int32_t Value)
{
	SBCheckError(TElSocket_set_SocksPort(_Handle, Value));
}

bool TElSocket::get_SocksResolveAddress()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSocket_get_SocksResolveAddress(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSocket::set_SocksResolveAddress(bool Value)
{
	SBCheckError(TElSocket_set_SocksResolveAddress(_Handle, (int8_t)Value));
}

void TElSocket::get_SocksServer(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSocket_get_SocksServer(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(556288414, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSocket::set_SocksServer(const std::string &Value)
{
	SBCheckError(TElSocket_set_SocksServer(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
bool TElSocket::get_SocksUseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSocket_get_SocksUseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSocket::set_SocksUseIPv6(bool Value)
{
	SBCheckError(TElSocket_set_SocksUseIPv6(_Handle, (int8_t)Value));
}
#endif

void TElSocket::get_SocksUserCode(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSocket_get_SocksUserCode(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1679732909, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSocket::set_SocksUserCode(const std::string &Value)
{
	SBCheckError(TElSocket_set_SocksUserCode(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSocksVersion TElSocket::get_SocksVersion()
{
	TElSocksVersionRaw OutResultRaw = 0;
	SBCheckError(TElSocket_get_SocksVersion(_Handle, &OutResultRaw));
	return (TElSocksVersion)OutResultRaw;
}

SB_INLINE void TElSocket::set_SocksVersion(TElSocksVersion Value)
{
	SBCheckError(TElSocket_set_SocksVersion(_Handle, (TElSocksVersionRaw)Value));
}

bool TElSocket::get_UseSocks()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSocket_get_UseSocks(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSocket::set_UseSocks(bool Value)
{
	SBCheckError(TElSocket_set_UseSocks(_Handle, (int8_t)Value));
}

#ifdef SB_WINDOWS
bool TElSocket::get_UseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSocket_get_UseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSocket::set_UseIPv6(bool Value)
{
	SBCheckError(TElSocket_set_UseIPv6(_Handle, (int8_t)Value));
}
#endif

bool TElSocket::get_UseNagle()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSocket_get_UseNagle(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSocket::set_UseNagle(bool Value)
{
	SBCheckError(TElSocket_set_UseNagle(_Handle, (int8_t)Value));
}

bool TElSocket::get_UseWebTunneling()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSocket_get_UseWebTunneling(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSocket::set_UseWebTunneling(bool Value)
{
	SBCheckError(TElSocket_set_UseWebTunneling(_Handle, (int8_t)Value));
}

void TElSocket::get_WebTunnelAddress(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSocket_get_WebTunnelAddress(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(768702524, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSocket::set_WebTunnelAddress(const std::string &Value)
{
	SBCheckError(TElSocket_set_WebTunnelAddress(_Handle, Value.data(), (int32_t)Value.length()));
}

TElWebTunnelAuthentication TElSocket::get_WebTunnelAuthentication()
{
	TElWebTunnelAuthenticationRaw OutResultRaw = 0;
	SBCheckError(TElSocket_get_WebTunnelAuthentication(_Handle, &OutResultRaw));
	return (TElWebTunnelAuthentication)OutResultRaw;
}

SB_INLINE void TElSocket::set_WebTunnelAuthentication(TElWebTunnelAuthentication Value)
{
	SBCheckError(TElSocket_set_WebTunnelAuthentication(_Handle, (TElWebTunnelAuthenticationRaw)Value));
}

void TElSocket::get_WebTunnelPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSocket_get_WebTunnelPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1378941310, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSocket::set_WebTunnelPassword(const std::string &Value)
{
	SBCheckError(TElSocket_set_WebTunnelPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSocket::get_WebTunnelPort()
{
	int32_t OutResult;
	SBCheckError(TElSocket_get_WebTunnelPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSocket::set_WebTunnelPort(int32_t Value)
{
	SBCheckError(TElSocket_set_WebTunnelPort(_Handle, Value));
}

void TElSocket::get_WebTunnelUserId(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSocket_get_WebTunnelUserId(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1689373793, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSocket::set_WebTunnelUserId(const std::string &Value)
{
	SBCheckError(TElSocket_set_WebTunnelUserId(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSocket::get_WebTunnelRequestHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSocket_get_WebTunnelRequestHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_WebTunnelRequestHeaders)
		this->_Inst_WebTunnelRequestHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_WebTunnelRequestHeaders->updateHandle(hOutResult);
	return this->_Inst_WebTunnelRequestHeaders;
}

SB_INLINE void TElSocket::set_WebTunnelRequestHeaders(TStringList &Value)
{
	SBCheckError(TElSocket_set_WebTunnelRequestHeaders(_Handle, Value.getHandle()));
}

SB_INLINE void TElSocket::set_WebTunnelRequestHeaders(TStringList *Value)
{
	SBCheckError(TElSocket_set_WebTunnelRequestHeaders(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSocket::get_WebTunnelRequestHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSocket_get_WebTunnelRequestHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_WebTunnelRequestHeaders)
		this->_Inst_WebTunnelRequestHeaders = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_WebTunnelRequestHeaders->updateHandle(hOutResult);
	return this->_Inst_WebTunnelRequestHeaders;
}

SB_INLINE void TElSocket::set_WebTunnelRequestHeaders(TElStringList &Value)
{
	SBCheckError(TElSocket_set_WebTunnelRequestHeaders(_Handle, Value.getHandle()));
}

SB_INLINE void TElSocket::set_WebTunnelRequestHeaders(TElStringList *Value)
{
	SBCheckError(TElSocket_set_WebTunnelRequestHeaders(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSocket::get_WebTunnelResponseHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSocket_get_WebTunnelResponseHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_WebTunnelResponseHeaders)
		this->_Inst_WebTunnelResponseHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_WebTunnelResponseHeaders->updateHandle(hOutResult);
	return this->_Inst_WebTunnelResponseHeaders;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSocket::get_WebTunnelResponseHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSocket_get_WebTunnelResponseHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_WebTunnelResponseHeaders)
		this->_Inst_WebTunnelResponseHeaders = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_WebTunnelResponseHeaders->updateHandle(hOutResult);
	return this->_Inst_WebTunnelResponseHeaders;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElSocket::get_WebTunnelResponseBody(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSocket_get_WebTunnelResponseBody(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1418532692, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElSocket::get_AutoAdjustBuffersSize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSocket_get_AutoAdjustBuffersSize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSocket::set_AutoAdjustBuffersSize(bool Value)
{
	SBCheckError(TElSocket_set_AutoAdjustBuffersSize(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElSocket::get_MinBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElSocket_get_MinBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSocket::set_MinBufferSize(int32_t Value)
{
	SBCheckError(TElSocket_set_MinBufferSize(_Handle, Value));
}

SB_INLINE int32_t TElSocket::get_MaxBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElSocket_get_MaxBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSocket::set_MaxBufferSize(int32_t Value)
{
	SBCheckError(TElSocket_set_MaxBufferSize(_Handle, Value));
}

SB_INLINE double TElSocket::get_BuffersAdjustStep()
{
	double OutResult;
	SBCheckError(TElSocket_get_BuffersAdjustStep(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSocket::set_BuffersAdjustStep(double Value)
{
	SBCheckError(TElSocket_set_BuffersAdjustStep(_Handle, Value));
}

SB_INLINE int32_t TElSocket::get_SendBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElSocket_get_SendBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSocket::set_SendBufferSize(int32_t Value)
{
	SBCheckError(TElSocket_set_SendBufferSize(_Handle, Value));
}

SB_INLINE int32_t TElSocket::get_RecvBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElSocket_get_RecvBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSocket::set_RecvBufferSize(int32_t Value)
{
	SBCheckError(TElSocket_set_RecvBufferSize(_Handle, Value));
}

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
TElDNSSettings* TElSocket::get_DNS()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSocket_get_DNS(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DNS)
		this->_Inst_DNS = new TElDNSSettings(hOutResult, ohFalse);
	else
		this->_Inst_DNS->updateHandle(hOutResult);
	return this->_Inst_DNS;
}

SB_INLINE void TElSocket::set_DNS(TElDNSSettings &Value)
{
	SBCheckError(TElSocket_set_DNS(_Handle, Value.getHandle()));
}

SB_INLINE void TElSocket::set_DNS(TElDNSSettings *Value)
{
	SBCheckError(TElSocket_set_DNS(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDNSSETTINGS */

SB_INLINE void TElSocket::get_OnDNSKeyNeeded(TSBDNSKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSocket_get_OnDNSKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSocket::set_OnDNSKeyNeeded(TSBDNSKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSocket_set_OnDNSKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSocket::get_OnDNSKeyValidate(TSBDNSKeyValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSocket_get_OnDNSKeyValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSocket::set_OnDNSKeyValidate(TSBDNSKeyValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSocket_set_OnDNSKeyValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSocket::get_OnDNSResolve(TSBDNSResolveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSocket_get_OnDNSResolve(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSocket::set_OnDNSResolve(TSBDNSResolveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSocket_set_OnDNSResolve(_Handle, pMethodValue, pDataValue));
}
#endif

void TElSocket::initInstances()
{
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	this->_Inst_ListenBinding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	this->_Inst_OutgoingLocalBinding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_WebTunnelRequestHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_WebTunnelRequestHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_WebTunnelResponseHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_WebTunnelResponseHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
	this->_Inst_DNS = NULL;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
}

TElSocket::TElSocket(TElSocketHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElSocket::TElSocket(TComponent &Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSocket_Create(Owner.getHandle(), &_Handle));
}

TElSocket::TElSocket(TComponent *Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSocket_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSocket::TElSocket() : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSocket_Create_1(&_Handle));
}

TElSocket::~TElSocket()
{
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	delete this->_Inst_ListenBinding;
	this->_Inst_ListenBinding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	delete this->_Inst_OutgoingLocalBinding;
	this->_Inst_OutgoingLocalBinding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
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
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_WebTunnelResponseHeaders;
	this->_Inst_WebTunnelResponseHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_WebTunnelResponseHeaders;
	this->_Inst_WebTunnelResponseHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
	delete this->_Inst_DNS;
	this->_Inst_DNS = NULL;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
}
#endif /* SB_USE_CLASS_TELSOCKET */

#ifdef SB_USE_CLASS_TELCUSTOMSOCKETBINDING

SB_INLINE void TElCustomSocketBinding::Assign(TElCustomSocketBinding &Source)
{
	SBCheckError(TElCustomSocketBinding_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElCustomSocketBinding::Assign(TElCustomSocketBinding *Source)
{
	SBCheckError(TElCustomSocketBinding_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

void TElCustomSocketBinding::get_LocalIntfAddress(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCustomSocketBinding_get_LocalIntfAddress(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1582509411, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomSocketBinding::set_LocalIntfAddress(const std::string &Value)
{
	SBCheckError(TElCustomSocketBinding_set_LocalIntfAddress(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElCustomSocketBinding::get_Port()
{
	int32_t OutResult;
	SBCheckError(TElCustomSocketBinding_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomSocketBinding::set_Port(int32_t Value)
{
	SBCheckError(TElCustomSocketBinding_set_Port(_Handle, Value));
}

bool TElCustomSocketBinding::get_ReuseAddress()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomSocketBinding_get_ReuseAddress(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomSocketBinding::set_ReuseAddress(bool Value)
{
	SBCheckError(TElCustomSocketBinding_set_ReuseAddress(_Handle, (int8_t)Value));
}

TElCustomSocketBinding::TElCustomSocketBinding(TElCustomSocketBindingHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElCustomSocketBinding::TElCustomSocketBinding() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomSocketBinding_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCUSTOMSOCKETBINDING */

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING

SB_INLINE void TElClientSocketBinding::Assign(TElCustomSocketBinding &Source)
{
	SBCheckError(TElClientSocketBinding_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElClientSocketBinding::Assign(TElCustomSocketBinding *Source)
{
	SBCheckError(TElClientSocketBinding_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElClientSocketBinding::get_PortRangeFrom()
{
	int32_t OutResult;
	SBCheckError(TElClientSocketBinding_get_PortRangeFrom(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElClientSocketBinding::set_PortRangeFrom(int32_t Value)
{
	SBCheckError(TElClientSocketBinding_set_PortRangeFrom(_Handle, Value));
}

SB_INLINE int32_t TElClientSocketBinding::get_PortRangeTo()
{
	int32_t OutResult;
	SBCheckError(TElClientSocketBinding_get_PortRangeTo(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElClientSocketBinding::set_PortRangeTo(int32_t Value)
{
	SBCheckError(TElClientSocketBinding_set_PortRangeTo(_Handle, Value));
}

TElClientSocketBinding::TElClientSocketBinding(TElClientSocketBindingHandle handle, TElOwnHandle ownHandle) : TElCustomSocketBinding(handle, ownHandle)
{
}

TElClientSocketBinding::TElClientSocketBinding() : TElCustomSocketBinding(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElClientSocketBinding_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS

SB_INLINE void TElDNSSettings::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSSettings_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSSettings::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSSettings_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

bool TElDNSSettings::ResolveHostName(const std::string &HostName, bool UseIPv6, sockaddr_storage &Addr)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSSettings_ResolveHostName(_Handle, HostName.data(), (int32_t)HostName.length(), (int8_t)UseIPv6, &Addr, &OutResultRaw));
	return (OutResultRaw != 0);
}

TSBDNSSecurityStatuses TElDNSSettings::get_AllowStatuses()
{
	TSBDNSSecurityStatusesRaw OutResultRaw = 0;
	SBCheckError(TElDNSSettings_get_AllowStatuses(_Handle, &OutResultRaw));
	return (TSBDNSSecurityStatuses)OutResultRaw;
}

SB_INLINE void TElDNSSettings::set_AllowStatuses(TSBDNSSecurityStatuses Value)
{
	SBCheckError(TElDNSSettings_set_AllowStatuses(_Handle, (TSBDNSSecurityStatusesRaw)Value));
}

bool TElDNSSettings::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSSettings_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSSettings::set_Enabled(bool Value)
{
	SBCheckError(TElDNSSettings_set_Enabled(_Handle, (int8_t)Value));
}

SB_INLINE uint16_t TElDNSSettings::get_Port()
{
	uint16_t OutResult;
	SBCheckError(TElDNSSettings_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSSettings::set_Port(uint16_t Value)
{
	SBCheckError(TElDNSSettings_set_Port(_Handle, Value));
}

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElDNSSettings::get_Servers()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDNSSettings_get_Servers(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Servers)
		this->_Inst_Servers = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Servers->updateHandle(hOutResult);
	return this->_Inst_Servers;
}

SB_INLINE void TElDNSSettings::set_Servers(TStringList &Value)
{
	SBCheckError(TElDNSSettings_set_Servers(_Handle, Value.getHandle()));
}

SB_INLINE void TElDNSSettings::set_Servers(TStringList *Value)
{
	SBCheckError(TElDNSSettings_set_Servers(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

SB_INLINE uint16_t TElDNSSettings::get_QueryTimeout()
{
	uint16_t OutResult;
	SBCheckError(TElDNSSettings_get_QueryTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSSettings::set_QueryTimeout(uint16_t Value)
{
	SBCheckError(TElDNSSettings_set_QueryTimeout(_Handle, Value));
}

SB_INLINE uint16_t TElDNSSettings::get_TotalTimeout()
{
	uint16_t OutResult;
	SBCheckError(TElDNSSettings_get_TotalTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSSettings::set_TotalTimeout(uint16_t Value)
{
	SBCheckError(TElDNSSettings_set_TotalTimeout(_Handle, Value));
}

bool TElDNSSettings::get_UseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSSettings_get_UseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSSettings::set_UseIPv6(bool Value)
{
	SBCheckError(TElDNSSettings_set_UseIPv6(_Handle, (int8_t)Value));
}

bool TElDNSSettings::get_UseSecurity()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSSettings_get_UseSecurity(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSSettings::set_UseSecurity(bool Value)
{
	SBCheckError(TElDNSSettings_set_UseSecurity(_Handle, (int8_t)Value));
}

void TElDNSSettings::initInstances()
{
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Servers = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}

TElDNSSettings::TElDNSSettings(TElDNSSettingsHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElDNSSettings::TElDNSSettings() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDNSSettings_Create(&_Handle));
}

TElDNSSettings::~TElDNSSettings()
{
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Servers;
	this->_Inst_Servers = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif

#ifdef SB_USE_CLASS_TELSOCKETSETTINGS

bool TElSocketSettings::get_AutoAdjustBuffersSize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSocketSettings_get_AutoAdjustBuffersSize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSocketSettings::set_AutoAdjustBuffersSize(bool Value)
{
	SBCheckError(TElSocketSettings_set_AutoAdjustBuffersSize(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElSocketSettings::get_MinBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElSocketSettings_get_MinBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSocketSettings::set_MinBufferSize(int32_t Value)
{
	SBCheckError(TElSocketSettings_set_MinBufferSize(_Handle, Value));
}

SB_INLINE int32_t TElSocketSettings::get_MaxBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElSocketSettings_get_MaxBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSocketSettings::set_MaxBufferSize(int32_t Value)
{
	SBCheckError(TElSocketSettings_set_MaxBufferSize(_Handle, Value));
}

SB_INLINE double TElSocketSettings::get_BuffersAdjustStep()
{
	double OutResult;
	SBCheckError(TElSocketSettings_get_BuffersAdjustStep(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSocketSettings::set_BuffersAdjustStep(double Value)
{
	SBCheckError(TElSocketSettings_set_BuffersAdjustStep(_Handle, Value));
}

SB_INLINE int32_t TElSocketSettings::get_SendBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElSocketSettings_get_SendBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSocketSettings::set_SendBufferSize(int32_t Value)
{
	SBCheckError(TElSocketSettings_set_SendBufferSize(_Handle, Value));
}

SB_INLINE int32_t TElSocketSettings::get_RecvBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElSocketSettings_get_RecvBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSocketSettings::set_RecvBufferSize(int32_t Value)
{
	SBCheckError(TElSocketSettings_set_RecvBufferSize(_Handle, Value));
}

bool TElSocketSettings::get_UseNagle()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSocketSettings_get_UseNagle(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSocketSettings::set_UseNagle(bool Value)
{
	SBCheckError(TElSocketSettings_set_UseNagle(_Handle, (int8_t)Value));
}

TElSocketSettings::TElSocketSettings(TElSocketSettingsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELSOCKET
TElSocketSettings::TElSocketSettings(TElSocket &Socket) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSocketSettings_Create(Socket.getHandle(), &_Handle));
}

TElSocketSettings::TElSocketSettings(TElSocket *Socket) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSocketSettings_Create((Socket != NULL) ? Socket->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSOCKET */

#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */

#ifdef SB_USE_GLOBAL_PROCS_SOCKET

bool AddressToString(const sockaddr_storage &Addr, std::string &S)
{
	int32_t szS = (int32_t)S.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBSocket_AddressToString(&Addr, (char *)S.data(), &szS, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		S.resize(szS);
		SBCheckError(SBGetLastReturnStringA(1620816918, 1, (char *)S.data(), &szS));
	}
	else
		SBCheckError(_err);

	S.resize(szS);
	return (OutResultRaw != 0);
}

bool StringToAddress(const std::string &S, sockaddr_storage &Addr)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBSocket_StringToAddress(S.data(), (int32_t)S.length(), &Addr, &OutResultRaw));
#ifdef SB_WINDOWS
	return (OutResultRaw != 0);
}

bool IsIPv6Address(const std::string &S)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBSocket_IsIPv6Address(S.data(), (int32_t)S.length(), &OutResultRaw));
#endif
	return (OutResultRaw != 0);
}

#endif /* SB_USE_GLOBAL_PROCS_SOCKET */

};	/* namespace SecureBlackbox */
