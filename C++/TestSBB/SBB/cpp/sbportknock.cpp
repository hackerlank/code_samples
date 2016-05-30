#include "sbportknock.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPORTKNOCKENTRY

TElPortKnockEntry::TElPortKnockEntry(TElPortKnockEntryHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPortKnockEntry::TElPortKnockEntry() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPortKnockEntry_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPORTKNOCKENTRY */

#ifdef SB_USE_CLASS_TELPORTKNOCK

SB_INLINE void TElPortKnock::Knock(const std::string &ConnectionAddress, bool KnockToClose)
{
	SBCheckError(TElPortKnock_Knock(_Handle, ConnectionAddress.data(), (int32_t)ConnectionAddress.length(), (int8_t)KnockToClose));
}

#ifdef SB_WINDOWS
bool TElPortKnock::get_UsingIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPortKnock_get_UsingIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif

#ifdef SB_USE_CLASS_TELSOCKET
TElSocket* TElPortKnock::get_InternalSocket()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPortKnock_get_InternalSocket(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_InternalSocket)
		this->_Inst_InternalSocket = new TElSocket(hOutResult, ohFalse);
	else
		this->_Inst_InternalSocket->updateHandle(hOutResult);
	return this->_Inst_InternalSocket;
}
#endif /* SB_USE_CLASS_TELSOCKET */

void TElPortKnock::get_Address(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPortKnock_get_Address(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1284790812, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPortKnock::set_Address(const std::string &Value)
{
	SBCheckError(TElPortKnock_set_Address(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPortKnock::get_BeforeConnectRules(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPortKnock_get_BeforeConnectRules(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(385186285, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPortKnock::set_BeforeConnectRules(const std::string &Value)
{
	SBCheckError(TElPortKnock_set_BeforeConnectRules(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPortKnock::get_AfterDisconnectRules(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPortKnock_get_AfterDisconnectRules(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2086579536, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPortKnock::set_AfterDisconnectRules(const std::string &Value)
{
	SBCheckError(TElPortKnock_set_AfterDisconnectRules(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElPortKnock::get_ProxyResult()
{
	int32_t OutResult;
	SBCheckError(TElPortKnock_get_ProxyResult(_Handle, &OutResult));
	return OutResult;
}

TElSocksAuthentication TElPortKnock::get_SocksAuthentication()
{
	TElSocksAuthenticationRaw OutResultRaw = 0;
	SBCheckError(TElPortKnock_get_SocksAuthentication(_Handle, &OutResultRaw));
	return (TElSocksAuthentication)OutResultRaw;
}

SB_INLINE void TElPortKnock::set_SocksAuthentication(TElSocksAuthentication Value)
{
	SBCheckError(TElPortKnock_set_SocksAuthentication(_Handle, (TElSocksAuthenticationRaw)Value));
}

void TElPortKnock::get_SocksPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPortKnock_get_SocksPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1823505609, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPortKnock::set_SocksPassword(const std::string &Value)
{
	SBCheckError(TElPortKnock_set_SocksPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElPortKnock::get_SocksPort()
{
	int32_t OutResult;
	SBCheckError(TElPortKnock_get_SocksPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPortKnock::set_SocksPort(int32_t Value)
{
	SBCheckError(TElPortKnock_set_SocksPort(_Handle, Value));
}

bool TElPortKnock::get_SocksResolveAddress()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPortKnock_get_SocksResolveAddress(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPortKnock::set_SocksResolveAddress(bool Value)
{
	SBCheckError(TElPortKnock_set_SocksResolveAddress(_Handle, (int8_t)Value));
}

void TElPortKnock::get_SocksServer(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPortKnock_get_SocksServer(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1014629065, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPortKnock::set_SocksServer(const std::string &Value)
{
	SBCheckError(TElPortKnock_set_SocksServer(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPortKnock::get_SocksUserCode(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPortKnock_get_SocksUserCode(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-673766859, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPortKnock::set_SocksUserCode(const std::string &Value)
{
	SBCheckError(TElPortKnock_set_SocksUserCode(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSocksVersion TElPortKnock::get_SocksVersion()
{
	TElSocksVersionRaw OutResultRaw = 0;
	SBCheckError(TElPortKnock_get_SocksVersion(_Handle, &OutResultRaw));
	return (TElSocksVersion)OutResultRaw;
}

SB_INLINE void TElPortKnock::set_SocksVersion(TElSocksVersion Value)
{
	SBCheckError(TElPortKnock_set_SocksVersion(_Handle, (TElSocksVersionRaw)Value));
}

#ifdef SB_WINDOWS
bool TElPortKnock::get_SocksUseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPortKnock_get_SocksUseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPortKnock::set_SocksUseIPv6(bool Value)
{
	SBCheckError(TElPortKnock_set_SocksUseIPv6(_Handle, (int8_t)Value));
}

bool TElPortKnock::get_UseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPortKnock_get_UseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPortKnock::set_UseIPv6(bool Value)
{
	SBCheckError(TElPortKnock_set_UseIPv6(_Handle, (int8_t)Value));
}
#endif

bool TElPortKnock::get_UseSocks()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPortKnock_get_UseSocks(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPortKnock::set_UseSocks(bool Value)
{
	SBCheckError(TElPortKnock_set_UseSocks(_Handle, (int8_t)Value));
}

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
TElDNSSettings* TElPortKnock::get_DNS()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPortKnock_get_DNS(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DNS)
		this->_Inst_DNS = new TElDNSSettings(hOutResult, ohFalse);
	else
		this->_Inst_DNS->updateHandle(hOutResult);
	return this->_Inst_DNS;
}

SB_INLINE void TElPortKnock::set_DNS(TElDNSSettings &Value)
{
	SBCheckError(TElPortKnock_set_DNS(_Handle, Value.getHandle()));
}

SB_INLINE void TElPortKnock::set_DNS(TElDNSSettings *Value)
{
	SBCheckError(TElPortKnock_set_DNS(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif

bool TElPortKnock::get_UseWebTunneling()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPortKnock_get_UseWebTunneling(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPortKnock::set_UseWebTunneling(bool Value)
{
	SBCheckError(TElPortKnock_set_UseWebTunneling(_Handle, (int8_t)Value));
}

void TElPortKnock::get_WebTunnelAddress(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPortKnock_get_WebTunnelAddress(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2132673355, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPortKnock::set_WebTunnelAddress(const std::string &Value)
{
	SBCheckError(TElPortKnock_set_WebTunnelAddress(_Handle, Value.data(), (int32_t)Value.length()));
}

TElWebTunnelAuthentication TElPortKnock::get_WebTunnelAuthentication()
{
	TElWebTunnelAuthenticationRaw OutResultRaw = 0;
	SBCheckError(TElPortKnock_get_WebTunnelAuthentication(_Handle, &OutResultRaw));
	return (TElWebTunnelAuthentication)OutResultRaw;
}

SB_INLINE void TElPortKnock::set_WebTunnelAuthentication(TElWebTunnelAuthentication Value)
{
	SBCheckError(TElPortKnock_set_WebTunnelAuthentication(_Handle, (TElWebTunnelAuthenticationRaw)Value));
}

void TElPortKnock::get_WebTunnelPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPortKnock_get_WebTunnelPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1677471078, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPortKnock::set_WebTunnelPassword(const std::string &Value)
{
	SBCheckError(TElPortKnock_set_WebTunnelPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElPortKnock::get_WebTunnelPort()
{
	int32_t OutResult;
	SBCheckError(TElPortKnock_get_WebTunnelPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPortKnock::set_WebTunnelPort(int32_t Value)
{
	SBCheckError(TElPortKnock_set_WebTunnelPort(_Handle, Value));
}

void TElPortKnock::get_WebTunnelUserId(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPortKnock_get_WebTunnelUserId(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1020752428, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPortKnock::set_WebTunnelUserId(const std::string &Value)
{
	SBCheckError(TElPortKnock_set_WebTunnelUserId(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElPortKnock::get_WebTunnelRequestHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPortKnock_get_WebTunnelRequestHeaders(_Handle, &hOutResult));
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
TElStringList* TElPortKnock::get_WebTunnelRequestHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPortKnock_get_WebTunnelRequestHeaders(_Handle, &hOutResult));
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
TStringList* TElPortKnock::get_WebTunnelResponseHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPortKnock_get_WebTunnelResponseHeaders(_Handle, &hOutResult));
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
TElStringList* TElPortKnock::get_WebTunnelResponseHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPortKnock_get_WebTunnelResponseHeaders(_Handle, &hOutResult));
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

void TElPortKnock::get_WebTunnelResponseBody(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPortKnock_get_WebTunnelResponseBody(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1321213253, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
TElClientSocketBinding* TElPortKnock::get_SocketBinding()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPortKnock_get_SocketBinding(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SocketBinding)
		this->_Inst_SocketBinding = new TElClientSocketBinding(hOutResult, ohFalse);
	else
		this->_Inst_SocketBinding->updateHandle(hOutResult);
	return this->_Inst_SocketBinding;
}

SB_INLINE void TElPortKnock::set_SocketBinding(TElClientSocketBinding &Value)
{
	SBCheckError(TElPortKnock_set_SocketBinding(_Handle, Value.getHandle()));
}

SB_INLINE void TElPortKnock::set_SocketBinding(TElClientSocketBinding *Value)
{
	SBCheckError(TElPortKnock_set_SocketBinding(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_INLINE void TElPortKnock::get_OnDNSKeyNeeded(TSBDNSKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPortKnock_get_OnDNSKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPortKnock::set_OnDNSKeyNeeded(TSBDNSKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPortKnock_set_OnDNSKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPortKnock::get_OnDNSKeyValidate(TSBDNSKeyValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPortKnock_get_OnDNSKeyValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPortKnock::set_OnDNSKeyValidate(TSBDNSKeyValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPortKnock_set_OnDNSKeyValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPortKnock::get_OnDNSResolve(TSBDNSResolveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPortKnock_get_OnDNSResolve(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPortKnock::set_OnDNSResolve(TSBDNSResolveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPortKnock_set_OnDNSResolve(_Handle, pMethodValue, pDataValue));
}
#endif

void TElPortKnock::initInstances()
{
#ifdef SB_USE_CLASS_TELSOCKET
	this->_Inst_InternalSocket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
	this->_Inst_DNS = NULL;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
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
}

TElPortKnock::TElPortKnock(TElPortKnockHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElPortKnock::TElPortKnock(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPortKnock_Create(AOwner.getHandle(), &_Handle));
}

TElPortKnock::TElPortKnock(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPortKnock_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElPortKnock::~TElPortKnock()
{
#ifdef SB_USE_CLASS_TELSOCKET
	delete this->_Inst_InternalSocket;
	this->_Inst_InternalSocket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
	delete this->_Inst_DNS;
	this->_Inst_DNS = NULL;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
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
}
#endif /* SB_USE_CLASS_TELPORTKNOCK */

};	/* namespace SecureBlackbox */
