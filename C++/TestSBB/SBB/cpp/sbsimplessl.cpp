#include "sbsimplessl.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELCUSTOMSIMPLESSLCLIENT

SB_INLINE void TElCustomSimpleSSLClient::Interrupt()
{
	SBCheckError(TElCustomSimpleSSLClient_Interrupt(_Handle));
}

SB_INLINE void TElCustomSimpleSSLClient::Close(bool Silent)
{
	SBCheckError(TElCustomSimpleSSLClient_Close(_Handle, (int8_t)Silent));
}

SB_INLINE void TElCustomSimpleSSLClient::Open()
{
	SBCheckError(TElCustomSimpleSSLClient_Open(_Handle));
}

SB_INLINE void TElCustomSimpleSSLClient::SendText(const std::string &S)
{
	SBCheckError(TElCustomSimpleSSLClient_SendText(_Handle, S.data(), (int32_t)S.length()));
}

SB_INLINE void TElCustomSimpleSSLClient::Join(TElCustomSimpleSSLClient &Client)
{
	SBCheckError(TElCustomSimpleSSLClient_Join(_Handle, Client.getHandle()));
}

SB_INLINE void TElCustomSimpleSSLClient::Join(TElCustomSimpleSSLClient *Client)
{
	SBCheckError(TElCustomSimpleSSLClient_Join(_Handle, (Client != NULL) ? Client->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElCustomSimpleSSLClient::SendData(void * Buffer, int32_t Size)
{
	SBCheckError(TElCustomSimpleSSLClient_SendData(_Handle, Buffer, Size));
}

SB_INLINE void TElCustomSimpleSSLClient::ReceiveData(void * Buffer, int32_t &Size, bool ReadAll)
{
	SBCheckError(TElCustomSimpleSSLClient_ReceiveData(_Handle, Buffer, &Size, (int8_t)ReadAll));
}

bool TElCustomSimpleSSLClient::SendKeepAlive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomSimpleSSLClient_SendKeepAlive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElCustomSimpleSSLClient::InternalValidate(TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason)
{
	TSBCertificateValidityRaw ValidityRaw = (TSBCertificateValidityRaw)Validity;
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	SBCheckError(TElCustomSimpleSSLClient_InternalValidate(_Handle, &ValidityRaw, &ReasonRaw));
	Validity = (TSBCertificateValidity)ValidityRaw;
	Reason = (TSBCertificateValidityReason)ReasonRaw;
}

bool TElCustomSimpleSSLClient::CanReceive(int32_t Timeout)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomSimpleSSLClient_CanReceive(_Handle, Timeout, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomSimpleSSLClient::RenegotiateCiphers()
{
	SBCheckError(TElCustomSimpleSSLClient_RenegotiateCiphers(_Handle));
}

void TElCustomSimpleSSLClient::get_RemoteHost(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCustomSimpleSSLClient_get_RemoteHost(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(7800994, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElCustomSimpleSSLClient::get_RemoteIP(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCustomSimpleSSLClient_get_RemoteIP(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1594884594, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElCustomSimpleSSLClient::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomSimpleSSLClient_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE uint8_t TElCustomSimpleSSLClient::get_CipherSuite()
{
	uint8_t OutResult;
	SBCheckError(TElCustomSimpleSSLClient_get_CipherSuite(_Handle, &OutResult));
	return OutResult;
}

bool TElCustomSimpleSSLClient::get_CipherSuites(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomSimpleSSLClient_get_CipherSuites(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomSimpleSSLClient::set_CipherSuites(uint8_t Index, bool Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_CipherSuites(_Handle, Index, (int8_t)Value));
}

SB_INLINE int32_t TElCustomSimpleSSLClient::get_CipherSuitePriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElCustomSimpleSSLClient_get_CipherSuitePriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomSimpleSSLClient::set_CipherSuitePriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_CipherSuitePriorities(_Handle, Index, Value));
}

SB_INLINE uint8_t TElCustomSimpleSSLClient::get_CompressionAlgorithm()
{
	uint8_t OutResult;
	SBCheckError(TElCustomSimpleSSLClient_get_CompressionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

bool TElCustomSimpleSSLClient::get_CompressionAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomSimpleSSLClient_get_CompressionAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomSimpleSSLClient::set_CompressionAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_CompressionAlgorithms(_Handle, Index, (int8_t)Value));
}

TSBVersion TElCustomSimpleSSLClient::get_CurrentVersion()
{
	TSBVersionRaw OutResultRaw = 0;
	SBCheckError(TElCustomSimpleSSLClient_get_CurrentVersion(_Handle, &OutResultRaw));
	return (TSBVersion)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
TElClientSSLExtensions* TElCustomSimpleSSLClient::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSimpleSSLClient_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TElClientSSLExtensions(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
TElCustomSSLExtensions* TElCustomSimpleSSLClient::get_PeerExtensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSimpleSSLClient_get_PeerExtensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PeerExtensions)
		this->_Inst_PeerExtensions = new TElCustomSSLExtensions(hOutResult, ohFalse);
	else
		this->_Inst_PeerExtensions->updateHandle(hOutResult);
	return this->_Inst_PeerExtensions;
}
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */

SB_INLINE int64_t TElCustomSimpleSSLClient::get_TotalBytesSent()
{
	int64_t OutResult;
	SBCheckError(TElCustomSimpleSSLClient_get_TotalBytesSent(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElCustomSimpleSSLClient::get_TotalBytesReceived()
{
	int64_t OutResult;
	SBCheckError(TElCustomSimpleSSLClient_get_TotalBytesReceived(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomSimpleSSLClient::get_ProxyResult()
{
	int32_t OutResult;
	SBCheckError(TElCustomSimpleSSLClient_get_ProxyResult(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_WINDOWS
bool TElCustomSimpleSSLClient::get_UsingIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomSimpleSSLClient_get_UsingIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif

#ifdef SB_USE_CLASS_TELSOCKET
TElSocket* TElCustomSimpleSSLClient::get_InternalSocket()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSimpleSSLClient_get_InternalSocket(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_InternalSocket)
		this->_Inst_InternalSocket = new TElSocket(hOutResult, ohFalse);
	else
		this->_Inst_InternalSocket->updateHandle(hOutResult);
	return this->_Inst_InternalSocket;
}
#endif /* SB_USE_CLASS_TELSOCKET */

#ifdef SB_USE_CLASS_TELSSLCLASS
TElSSLClass* TElCustomSimpleSSLClient::get_Control()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSimpleSSLClient_get_Control(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Control)
		this->_Inst_Control = new TElSSLClass(hOutResult, ohFalse);
	else
		this->_Inst_Control->updateHandle(hOutResult);
	return this->_Inst_Control;
}
#endif /* SB_USE_CLASS_TELSSLCLASS */

#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
TElSocketSettings* TElCustomSimpleSSLClient::get_SocketSettings()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSimpleSSLClient_get_SocketSettings(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SocketSettings)
		this->_Inst_SocketSettings = new TElSocketSettings(hOutResult, ohFalse);
	else
		this->_Inst_SocketSettings->updateHandle(hOutResult);
	return this->_Inst_SocketSettings;
}
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */

#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
TElSSLConnectionInfo* TElCustomSimpleSSLClient::get_ConnectionInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSimpleSSLClient_get_ConnectionInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ConnectionInfo)
		this->_Inst_ConnectionInfo = new TElSSLConnectionInfo(hOutResult, ohFalse);
	else
		this->_Inst_ConnectionInfo->updateHandle(hOutResult);
	return this->_Inst_ConnectionInfo;
}
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElCustomSimpleSSLClient::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSimpleSSLClient_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElCustomSimpleSSLClient::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElCustomSimpleSSLClient::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElCustomSimpleSSLClient::get_ClientCertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSimpleSSLClient_get_ClientCertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ClientCertStorage)
		this->_Inst_ClientCertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_ClientCertStorage->updateHandle(hOutResult);
	return this->_Inst_ClientCertStorage;
}

SB_INLINE void TElCustomSimpleSSLClient::set_ClientCertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_ClientCertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElCustomSimpleSSLClient::set_ClientCertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_ClientCertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELSSLCLIENT
TElSSLClient* TElCustomSimpleSSLClient::get_Client()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSimpleSSLClient_get_Client(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Client)
		this->_Inst_Client = new TElSSLClient(hOutResult, ohFalse);
	else
		this->_Inst_Client->updateHandle(hOutResult);
	return this->_Inst_Client;
}
#endif /* SB_USE_CLASS_TELSSLCLIENT */

SB_INLINE int32_t TElCustomSimpleSSLClient::get_SocketTimeout()
{
	int32_t OutResult;
	SBCheckError(TElCustomSimpleSSLClient_get_SocketTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomSimpleSSLClient::set_SocketTimeout(int32_t Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_SocketTimeout(_Handle, Value));
}

TSBVersions TElCustomSimpleSSLClient::get_Versions()
{
	TSBVersionsRaw OutResultRaw = 0;
	SBCheckError(TElCustomSimpleSSLClient_get_Versions(_Handle, &OutResultRaw));
	return (TSBVersions)OutResultRaw;
}

SB_INLINE void TElCustomSimpleSSLClient::set_Versions(TSBVersions Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_Versions(_Handle, (TSBVersionsRaw)Value));
}

TSBSSLOptions TElCustomSimpleSSLClient::get_SSLOptions()
{
	TSBSSLOptionsRaw OutResultRaw = 0;
	SBCheckError(TElCustomSimpleSSLClient_get_SSLOptions(_Handle, &OutResultRaw));
	return (TSBSSLOptions)OutResultRaw;
}

SB_INLINE void TElCustomSimpleSSLClient::set_SSLOptions(TSBSSLOptions Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_SSLOptions(_Handle, (TSBSSLOptionsRaw)Value));
}

void TElCustomSimpleSSLClient::get_LocalAddress(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCustomSimpleSSLClient_get_LocalAddress(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1204568907, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomSimpleSSLClient::set_LocalAddress(const std::string &Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_LocalAddress(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElCustomSimpleSSLClient::get_LocalPort()
{
	int32_t OutResult;
	SBCheckError(TElCustomSimpleSSLClient_get_LocalPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomSimpleSSLClient::set_LocalPort(int32_t Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_LocalPort(_Handle, Value));
}

SB_INLINE int32_t TElCustomSimpleSSLClient::get_IncomingSpeedLimit()
{
	int32_t OutResult;
	SBCheckError(TElCustomSimpleSSLClient_get_IncomingSpeedLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomSimpleSSLClient::set_IncomingSpeedLimit(int32_t Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_IncomingSpeedLimit(_Handle, Value));
}

SB_INLINE int32_t TElCustomSimpleSSLClient::get_OutgoingSpeedLimit()
{
	int32_t OutResult;
	SBCheckError(TElCustomSimpleSSLClient_get_OutgoingSpeedLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomSimpleSSLClient::set_OutgoingSpeedLimit(int32_t Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_OutgoingSpeedLimit(_Handle, Value));
}

bool TElCustomSimpleSSLClient::get_UseSSLSessionResumption()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomSimpleSSLClient_get_UseSSLSessionResumption(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomSimpleSSLClient::set_UseSSLSessionResumption(bool Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_UseSSLSessionResumption(_Handle, (int8_t)Value));
}

bool TElCustomSimpleSSLClient::get_ForceResumeIfDestinationChanges()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomSimpleSSLClient_get_ForceResumeIfDestinationChanges(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomSimpleSSLClient::set_ForceResumeIfDestinationChanges(bool Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_ForceResumeIfDestinationChanges(_Handle, (int8_t)Value));
}

TElSocksAuthentication TElCustomSimpleSSLClient::get_SocksAuthentication()
{
	TElSocksAuthenticationRaw OutResultRaw = 0;
	SBCheckError(TElCustomSimpleSSLClient_get_SocksAuthentication(_Handle, &OutResultRaw));
	return (TElSocksAuthentication)OutResultRaw;
}

SB_INLINE void TElCustomSimpleSSLClient::set_SocksAuthentication(TElSocksAuthentication Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_SocksAuthentication(_Handle, (TElSocksAuthenticationRaw)Value));
}

void TElCustomSimpleSSLClient::get_SocksPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCustomSimpleSSLClient_get_SocksPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(837635768, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomSimpleSSLClient::set_SocksPassword(const std::string &Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_SocksPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElCustomSimpleSSLClient::get_SocksPort()
{
	int32_t OutResult;
	SBCheckError(TElCustomSimpleSSLClient_get_SocksPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomSimpleSSLClient::set_SocksPort(int32_t Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_SocksPort(_Handle, Value));
}

bool TElCustomSimpleSSLClient::get_SocksResolveAddress()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomSimpleSSLClient_get_SocksResolveAddress(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomSimpleSSLClient::set_SocksResolveAddress(bool Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_SocksResolveAddress(_Handle, (int8_t)Value));
}

void TElCustomSimpleSSLClient::get_SocksServer(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCustomSimpleSSLClient_get_SocksServer(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-985440113, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomSimpleSSLClient::set_SocksServer(const std::string &Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_SocksServer(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElCustomSimpleSSLClient::get_SocksUserCode(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCustomSimpleSSLClient_get_SocksUserCode(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1970663354, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomSimpleSSLClient::set_SocksUserCode(const std::string &Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_SocksUserCode(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSocksVersion TElCustomSimpleSSLClient::get_SocksVersion()
{
	TElSocksVersionRaw OutResultRaw = 0;
	SBCheckError(TElCustomSimpleSSLClient_get_SocksVersion(_Handle, &OutResultRaw));
	return (TElSocksVersion)OutResultRaw;
}

SB_INLINE void TElCustomSimpleSSLClient::set_SocksVersion(TElSocksVersion Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_SocksVersion(_Handle, (TElSocksVersionRaw)Value));
}

#ifdef SB_WINDOWS
bool TElCustomSimpleSSLClient::get_SocksUseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomSimpleSSLClient_get_SocksUseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomSimpleSSLClient::set_SocksUseIPv6(bool Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_SocksUseIPv6(_Handle, (int8_t)Value));
}
#endif

bool TElCustomSimpleSSLClient::get_UseSocks()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomSimpleSSLClient_get_UseSocks(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomSimpleSSLClient::set_UseSocks(bool Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_UseSocks(_Handle, (int8_t)Value));
}

bool TElCustomSimpleSSLClient::get_UseWebTunneling()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomSimpleSSLClient_get_UseWebTunneling(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomSimpleSSLClient::set_UseWebTunneling(bool Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_UseWebTunneling(_Handle, (int8_t)Value));
}

void TElCustomSimpleSSLClient::get_WebTunnelAddress(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCustomSimpleSSLClient_get_WebTunnelAddress(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-738511725, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomSimpleSSLClient::set_WebTunnelAddress(const std::string &Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_WebTunnelAddress(_Handle, Value.data(), (int32_t)Value.length()));
}

TElWebTunnelAuthentication TElCustomSimpleSSLClient::get_WebTunnelAuthentication()
{
	TElWebTunnelAuthenticationRaw OutResultRaw = 0;
	SBCheckError(TElCustomSimpleSSLClient_get_WebTunnelAuthentication(_Handle, &OutResultRaw));
	return (TElWebTunnelAuthentication)OutResultRaw;
}

SB_INLINE void TElCustomSimpleSSLClient::set_WebTunnelAuthentication(TElWebTunnelAuthentication Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_WebTunnelAuthentication(_Handle, (TElWebTunnelAuthenticationRaw)Value));
}

void TElCustomSimpleSSLClient::get_WebTunnelPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCustomSimpleSSLClient_get_WebTunnelPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(346516811, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomSimpleSSLClient::set_WebTunnelPassword(const std::string &Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_WebTunnelPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElCustomSimpleSSLClient::get_WebTunnelPort()
{
	int32_t OutResult;
	SBCheckError(TElCustomSimpleSSLClient_get_WebTunnelPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomSimpleSSLClient::set_WebTunnelPort(int32_t Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_WebTunnelPort(_Handle, Value));
}

void TElCustomSimpleSSLClient::get_WebTunnelUserId(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCustomSimpleSSLClient_get_WebTunnelUserId(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1696197127, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomSimpleSSLClient::set_WebTunnelUserId(const std::string &Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_WebTunnelUserId(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElCustomSimpleSSLClient::get_WebTunnelRequestHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSimpleSSLClient_get_WebTunnelRequestHeaders(_Handle, &hOutResult));
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
TElStringList* TElCustomSimpleSSLClient::get_WebTunnelRequestHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSimpleSSLClient_get_WebTunnelRequestHeaders(_Handle, &hOutResult));
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

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElCustomSimpleSSLClient::get_WebTunnelResponseHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSimpleSSLClient_get_WebTunnelResponseHeaders(_Handle, &hOutResult));
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
TElStringList* TElCustomSimpleSSLClient::get_WebTunnelResponseHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSimpleSSLClient_get_WebTunnelResponseHeaders(_Handle, &hOutResult));
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

void TElCustomSimpleSSLClient::get_WebTunnelResponseBody(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCustomSimpleSSLClient_get_WebTunnelResponseBody(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(924977259, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
TElClientSocketBinding* TElCustomSimpleSSLClient::get_SocketBinding()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSimpleSSLClient_get_SocketBinding(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SocketBinding)
		this->_Inst_SocketBinding = new TElClientSocketBinding(hOutResult, ohFalse);
	else
		this->_Inst_SocketBinding->updateHandle(hOutResult);
	return this->_Inst_SocketBinding;
}

SB_INLINE void TElCustomSimpleSSLClient::set_SocketBinding(TElClientSocketBinding &Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_SocketBinding(_Handle, Value.getHandle()));
}

SB_INLINE void TElCustomSimpleSSLClient::set_SocketBinding(TElClientSocketBinding *Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_SocketBinding(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

void TElCustomSimpleSSLClient::get_SRPUserName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCustomSimpleSSLClient_get_SRPUserName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(935888478, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomSimpleSSLClient::set_SRPUserName(const std::string &Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_SRPUserName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElCustomSimpleSSLClient::get_SRPPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCustomSimpleSSLClient_get_SRPPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1516661186, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomSimpleSSLClient::set_SRPPassword(const std::string &Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_SRPPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBRenegotiationAttackPreventionMode TElCustomSimpleSSLClient::get_RenegotiationAttackPreventionMode()
{
	TSBRenegotiationAttackPreventionModeRaw OutResultRaw = 0;
	SBCheckError(TElCustomSimpleSSLClient_get_RenegotiationAttackPreventionMode(_Handle, &OutResultRaw));
	return (TSBRenegotiationAttackPreventionMode)OutResultRaw;
}

SB_INLINE void TElCustomSimpleSSLClient::set_RenegotiationAttackPreventionMode(TSBRenegotiationAttackPreventionMode Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_RenegotiationAttackPreventionMode(_Handle, (TSBRenegotiationAttackPreventionModeRaw)Value));
}

#ifdef SB_USE_CLASS_TELPORTKNOCK
TElPortKnock* TElCustomSimpleSSLClient::get_PortKnock()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSimpleSSLClient_get_PortKnock(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PortKnock)
		this->_Inst_PortKnock = new TElPortKnock(hOutResult, ohFalse);
	else
		this->_Inst_PortKnock->updateHandle(hOutResult);
	return this->_Inst_PortKnock;
}

SB_INLINE void TElCustomSimpleSSLClient::set_PortKnock(TElPortKnock &Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_PortKnock(_Handle, Value.getHandle()));
}

SB_INLINE void TElCustomSimpleSSLClient::set_PortKnock(TElPortKnock *Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_PortKnock(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPORTKNOCK */

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
TElDNSSettings* TElCustomSimpleSSLClient::get_DNS()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSimpleSSLClient_get_DNS(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DNS)
		this->_Inst_DNS = new TElDNSSettings(hOutResult, ohFalse);
	else
		this->_Inst_DNS->updateHandle(hOutResult);
	return this->_Inst_DNS;
}

SB_INLINE void TElCustomSimpleSSLClient::set_DNS(TElDNSSettings &Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_DNS(_Handle, Value.getHandle()));
}

SB_INLINE void TElCustomSimpleSSLClient::set_DNS(TElDNSSettings *Value)
{
	SBCheckError(TElCustomSimpleSSLClient_set_DNS(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif

SB_INLINE void TElCustomSimpleSSLClient::get_MessageLoop(TElMessageLoopEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCustomSimpleSSLClient_get_MessageLoop(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCustomSimpleSSLClient::set_MessageLoop(TElMessageLoopEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCustomSimpleSSLClient_set_MessageLoop(_Handle, pMethodValue, pDataValue));
}

#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_INLINE void TElCustomSimpleSSLClient::get_OnDNSKeyNeeded(TSBDNSKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCustomSimpleSSLClient_get_OnDNSKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCustomSimpleSSLClient::set_OnDNSKeyNeeded(TSBDNSKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCustomSimpleSSLClient_set_OnDNSKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCustomSimpleSSLClient::get_OnDNSKeyValidate(TSBDNSKeyValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCustomSimpleSSLClient_get_OnDNSKeyValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCustomSimpleSSLClient::set_OnDNSKeyValidate(TSBDNSKeyValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCustomSimpleSSLClient_set_OnDNSKeyValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCustomSimpleSSLClient::get_OnDNSResolve(TSBDNSResolveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCustomSimpleSSLClient_get_OnDNSResolve(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCustomSimpleSSLClient::set_OnDNSResolve(TSBDNSResolveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCustomSimpleSSLClient_set_OnDNSResolve(_Handle, pMethodValue, pDataValue));
}
#endif

void TElCustomSimpleSSLClient::initInstances()
{
#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
	this->_Inst_PeerExtensions = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELSOCKET
	this->_Inst_InternalSocket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifdef SB_USE_CLASS_TELSSLCLASS
	this->_Inst_Control = NULL;
#endif /* SB_USE_CLASS_TELSSLCLASS */
#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
	this->_Inst_SocketSettings = NULL;
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */
#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
	this->_Inst_ConnectionInfo = NULL;
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_ClientCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELSSLCLIENT
	this->_Inst_Client = NULL;
#endif /* SB_USE_CLASS_TELSSLCLIENT */
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
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	this->_Inst_SocketBinding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifdef SB_USE_CLASS_TELPORTKNOCK
	this->_Inst_PortKnock = NULL;
#endif /* SB_USE_CLASS_TELPORTKNOCK */
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
	this->_Inst_DNS = NULL;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
}

TElCustomSimpleSSLClient::TElCustomSimpleSSLClient(TElCustomSimpleSSLClientHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElCustomSimpleSSLClient::TElCustomSimpleSSLClient(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomSimpleSSLClient_Create(AOwner.getHandle(), &_Handle));
}

TElCustomSimpleSSLClient::TElCustomSimpleSSLClient(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomSimpleSSLClient_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElCustomSimpleSSLClient::~TElCustomSimpleSSLClient()
{
#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
	delete this->_Inst_PeerExtensions;
	this->_Inst_PeerExtensions = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELSOCKET
	delete this->_Inst_InternalSocket;
	this->_Inst_InternalSocket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifdef SB_USE_CLASS_TELSSLCLASS
	delete this->_Inst_Control;
	this->_Inst_Control = NULL;
#endif /* SB_USE_CLASS_TELSSLCLASS */
#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
	delete this->_Inst_SocketSettings;
	this->_Inst_SocketSettings = NULL;
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */
#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
	delete this->_Inst_ConnectionInfo;
	this->_Inst_ConnectionInfo = NULL;
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_ClientCertStorage;
	this->_Inst_ClientCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELSSLCLIENT
	delete this->_Inst_Client;
	this->_Inst_Client = NULL;
#endif /* SB_USE_CLASS_TELSSLCLIENT */
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
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	delete this->_Inst_SocketBinding;
	this->_Inst_SocketBinding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifdef SB_USE_CLASS_TELPORTKNOCK
	delete this->_Inst_PortKnock;
	this->_Inst_PortKnock = NULL;
#endif /* SB_USE_CLASS_TELPORTKNOCK */
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
	delete this->_Inst_DNS;
	this->_Inst_DNS = NULL;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
}
#endif /* SB_USE_CLASS_TELCUSTOMSIMPLESSLCLIENT */

#ifdef SB_USE_CLASS_TELSIMPLESSLCLIENT

SB_INLINE void TElSimpleSSLClient::StartTLS()
{
	SBCheckError(TElSimpleSSLClient_StartTLS(_Handle));
}

SB_INLINE void TElSimpleSSLClient::StopTLS(bool Silent)
{
	SBCheckError(TElSimpleSSLClient_StopTLS(_Handle, (int8_t)Silent));
}

void TElSimpleSSLClient::get_Address(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSLClient_get_Address(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1174393719, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSSLClient::set_Address(const std::string &Value)
{
	SBCheckError(TElSimpleSSLClient_set_Address(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSimpleSSLClient::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSLClient_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSLClient::set_Enabled(bool Value)
{
	SBCheckError(TElSimpleSSLClient_set_Enabled(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElSimpleSSLClient::get_Port()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSLClient_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSLClient::set_Port(int32_t Value)
{
	SBCheckError(TElSimpleSSLClient_set_Port(_Handle, Value));
#ifdef SB_WINDOWS
}

bool TElSimpleSSLClient::get_UseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSLClient_get_UseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSLClient::set_UseIPv6(bool Value)
{
	SBCheckError(TElSimpleSSLClient_set_UseIPv6(_Handle, (int8_t)Value));
#endif
}

bool TElSimpleSSLClient::get_UseInternalSocket()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSLClient_get_UseInternalSocket(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSLClient::set_UseInternalSocket(bool Value)
{
	SBCheckError(TElSimpleSSLClient_set_UseInternalSocket(_Handle, (int8_t)Value));
}

SB_INLINE void TElSimpleSSLClient::get_OnCertificateChoose(TSBChooseCertificateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSLClient_get_OnCertificateChoose(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSLClient::set_OnCertificateChoose(TSBChooseCertificateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSLClient_set_OnCertificateChoose(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSLClient::get_OnCertificateNeededEx(TSBCertificateNeededExEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSLClient_get_OnCertificateNeededEx(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSLClient::set_OnCertificateNeededEx(TSBCertificateNeededExEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSLClient_set_OnCertificateNeededEx(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSLClient::get_OnCertificateValidate(TSBCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSLClient_get_OnCertificateValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSLClient::set_OnCertificateValidate(TSBCertificateValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSLClient_set_OnCertificateValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSLClient::get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSLClient_get_OnCiphersNegotiated(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSLClient::set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSLClient_set_OnCiphersNegotiated(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSLClient::get_OnCloseConnection(TSBCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSLClient_get_OnCloseConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSLClient::set_OnCloseConnection(TSBCloseConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSLClient_set_OnCloseConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSLClient::get_OnError(TSBErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSLClient_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSLClient::set_OnError(TSBErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSLClient_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSLClient::get_OnReceive(TSBReceiveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSLClient_get_OnReceive(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSLClient::set_OnReceive(TSBReceiveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSLClient_set_OnReceive(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSLClient::get_OnSend(TSBSendEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSLClient_get_OnSend(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSLClient::set_OnSend(TSBSendEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSLClient_set_OnSend(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSLClient::get_OnExtensionsReceived(TSBExtensionsReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSLClient_get_OnExtensionsReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSLClient::set_OnExtensionsReceived(TSBExtensionsReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSLClient_set_OnExtensionsReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSLClient::get_OnExtensionsPrepared(TSBExtensionsPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSLClient_get_OnExtensionsPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSLClient::set_OnExtensionsPrepared(TSBExtensionsPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSLClient_set_OnExtensionsPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSLClient::get_OnCertificateStatus(TSBCertificateStatusEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSLClient_get_OnCertificateStatus(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSLClient::set_OnCertificateStatus(TSBCertificateStatusEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSLClient_set_OnCertificateStatus(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSLClient::get_OnKeyNeeded(TSBClientKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSLClient_get_OnKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSLClient::set_OnKeyNeeded(TSBClientKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSLClient_set_OnKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSLClient::get_OnRenegotiationRequest(TSBRenegotiationRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSLClient_get_OnRenegotiationRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSLClient::set_OnRenegotiationRequest(TSBRenegotiationRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSLClient_set_OnRenegotiationRequest(_Handle, pMethodValue, pDataValue));
}

TElSimpleSSLClient::TElSimpleSSLClient(TElSimpleSSLClientHandle handle, TElOwnHandle ownHandle) : TElCustomSimpleSSLClient(handle, ownHandle)
{
}

TElSimpleSSLClient::TElSimpleSSLClient(TComponent &AOwner) : TElCustomSimpleSSLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSimpleSSLClient_Create(AOwner.getHandle(), &_Handle));
}

TElSimpleSSLClient::TElSimpleSSLClient(TComponent *AOwner) : TElCustomSimpleSSLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSimpleSSLClient_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELSIMPLESSLCLIENT */

};	/* namespace SecureBlackbox */
