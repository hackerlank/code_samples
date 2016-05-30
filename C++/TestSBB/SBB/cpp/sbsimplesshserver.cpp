#include "sbsimplesshserver.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSIMPLESSHSERVER

#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
TElSocketSettings* TElSimpleSSHServer::get_SocketSettings()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHServer_get_SocketSettings(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SocketSettings)
		this->_Inst_SocketSettings = new TElSocketSettings(hOutResult, ohFalse);
	else
		this->_Inst_SocketSettings->updateHandle(hOutResult);
	return this->_Inst_SocketSettings;
}
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */

bool TElSimpleSSHServer::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHServer_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHServer::set_Active(bool Value)
{
	SBCheckError(TElSimpleSSHServer_set_Active(_Handle, (int8_t)Value));
}

bool TElSimpleSSHServer::get_AllowShell()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHServer_get_AllowShell(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHServer::set_AllowShell(bool Value)
{
	SBCheckError(TElSimpleSSHServer_set_AllowShell(_Handle, (int8_t)Value));
}

bool TElSimpleSSHServer::get_AllowCommand()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHServer_get_AllowCommand(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHServer::set_AllowCommand(bool Value)
{
	SBCheckError(TElSimpleSSHServer_set_AllowCommand(_Handle, (int8_t)Value));
}

bool TElSimpleSSHServer::get_AllowClientForwarding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHServer_get_AllowClientForwarding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHServer::set_AllowClientForwarding(bool Value)
{
	SBCheckError(TElSimpleSSHServer_set_AllowClientForwarding(_Handle, (int8_t)Value));
}

bool TElSimpleSSHServer::get_AllowServerForwarding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHServer_get_AllowServerForwarding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHServer::set_AllowServerForwarding(bool Value)
{
	SBCheckError(TElSimpleSSHServer_set_AllowServerForwarding(_Handle, (int8_t)Value));
}

bool TElSimpleSSHServer::get_ForceCompression()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHServer_get_ForceCompression(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHServer::set_ForceCompression(bool Value)
{
	SBCheckError(TElSimpleSSHServer_set_ForceCompression(_Handle, (int8_t)Value));
}

void TElSimpleSSHServer::get_Host(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHServer_get_Host(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1035364119, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSSHServer::set_Host(const std::string &Value)
{
	SBCheckError(TElSimpleSSHServer_set_Host(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSimpleSSHServer::get_Port()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHServer_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHServer::set_Port(int32_t Value)
{
	SBCheckError(TElSimpleSSHServer_set_Port(_Handle, Value));
}

SB_INLINE int32_t TElSimpleSSHServer::get_DataPortRangeFrom()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHServer_get_DataPortRangeFrom(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHServer::set_DataPortRangeFrom(int32_t Value)
{
	SBCheckError(TElSimpleSSHServer_set_DataPortRangeFrom(_Handle, Value));
}

SB_INLINE int32_t TElSimpleSSHServer::get_DataPortRangeTo()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHServer_get_DataPortRangeTo(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHServer::set_DataPortRangeTo(int32_t Value)
{
	SBCheckError(TElSimpleSSHServer_set_DataPortRangeTo(_Handle, Value));
}

#ifdef SB_WINDOWS
bool TElSimpleSSHServer::get_UseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHServer_get_UseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHServer::set_UseIPv6(bool Value)
{
	SBCheckError(TElSimpleSSHServer_set_UseIPv6(_Handle, (int8_t)Value));
}
#endif

SB_INLINE int32_t TElSimpleSSHServer::get_SessionTimeout()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHServer_get_SessionTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHServer::set_SessionTimeout(int32_t Value)
{
	SBCheckError(TElSimpleSSHServer_set_SessionTimeout(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
TElSSHCustomKeyStorage* TElSimpleSSHServer::get_KeyStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHServer_get_KeyStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyStorage)
		this->_Inst_KeyStorage = new TElSSHCustomKeyStorage(hOutResult, ohFalse);
	else
		this->_Inst_KeyStorage->updateHandle(hOutResult);
	return this->_Inst_KeyStorage;
}

SB_INLINE void TElSimpleSSHServer::set_KeyStorage(TElSSHCustomKeyStorage &Value)
{
	SBCheckError(TElSimpleSSHServer_set_KeyStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSSHServer::set_KeyStorage(TElSSHCustomKeyStorage *Value)
{
	SBCheckError(TElSimpleSSHServer_set_KeyStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

TSBSSHAuthOrder TElSimpleSSHServer::get_SSHAuthOrder()
{
	TSBSSHAuthOrderRaw OutResultRaw = 0;
	SBCheckError(TElSimpleSSHServer_get_SSHAuthOrder(_Handle, &OutResultRaw));
	return (TSBSSHAuthOrder)OutResultRaw;
}

SB_INLINE void TElSimpleSSHServer::set_SSHAuthOrder(TSBSSHAuthOrder Value)
{
	SBCheckError(TElSimpleSSHServer_set_SSHAuthOrder(_Handle, (TSBSSHAuthOrderRaw)Value));
}

void TElSimpleSSHServer::get_SoftwareName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHServer_get_SoftwareName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1383678035, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSSHServer::set_SoftwareName(const std::string &Value)
{
	SBCheckError(TElSimpleSSHServer_set_SoftwareName(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSimpleSSHServer::get_CompressionLevel()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHServer_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHServer::set_CompressionLevel(int32_t Value)
{
	SBCheckError(TElSimpleSSHServer_set_CompressionLevel(_Handle, Value));
}

SB_INLINE int32_t TElSimpleSSHServer::get_AuthenticationTypes()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHServer_get_AuthenticationTypes(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHServer::set_AuthenticationTypes(int32_t Value)
{
	SBCheckError(TElSimpleSSHServer_set_AuthenticationTypes(_Handle, Value));
}

bool TElSimpleSSHServer::get_CloseIfNoActiveTunnels()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHServer_get_CloseIfNoActiveTunnels(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHServer::set_CloseIfNoActiveTunnels(bool Value)
{
	SBCheckError(TElSimpleSSHServer_set_CloseIfNoActiveTunnels(_Handle, (int8_t)Value));
}

bool TElSimpleSSHServer::get_UseUTF8()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHServer_get_UseUTF8(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHServer::set_UseUTF8(bool Value)
{
	SBCheckError(TElSimpleSSHServer_set_UseUTF8(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElSimpleSSHServer::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHServer_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElSimpleSSHServer::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElSimpleSSHServer_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSSHServer::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElSimpleSSHServer_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

bool TElSimpleSSHServer::get_NoCharacterEncoding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHServer_get_NoCharacterEncoding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHServer::set_NoCharacterEncoding(bool Value)
{
	SBCheckError(TElSimpleSSHServer_set_NoCharacterEncoding(_Handle, (int8_t)Value));
}

void TElSimpleSSHServer::get_LocalCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHServer_get_LocalCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(92530348, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSSHServer::set_LocalCharset(const std::string &Value)
{
	SBCheckError(TElSimpleSSHServer_set_LocalCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSimpleSSHServer::get_RemoteCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHServer_get_RemoteCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1985888589, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSSHServer::set_RemoteCharset(const std::string &Value)
{
	SBCheckError(TElSimpleSSHServer_set_RemoteCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSimpleSSHServer::get_ObfuscateHandshake()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHServer_get_ObfuscateHandshake(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHServer::set_ObfuscateHandshake(bool Value)
{
	SBCheckError(TElSimpleSSHServer_set_ObfuscateHandshake(_Handle, (int8_t)Value));
}

void TElSimpleSSHServer::get_ObfuscationPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHServer_get_ObfuscationPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1794621592, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSSHServer::set_ObfuscationPassword(const std::string &Value)
{
	SBCheckError(TElSimpleSSHServer_set_ObfuscationPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELSSHUSERS
TElSSHUsers* TElSimpleSSHServer::get_Users()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHServer_get_Users(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Users)
		this->_Inst_Users = new TElSSHUsers(hOutResult, ohFalse);
	else
		this->_Inst_Users->updateHandle(hOutResult);
	return this->_Inst_Users;
}
#endif /* SB_USE_CLASS_TELSSHUSERS */

SB_INLINE void TElSimpleSSHServer::get_OnAuthAttempt(TSSHAuthAttemptEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnAuthAttempt(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnAuthAttempt(TSSHAuthAttemptEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnAuthAttempt(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnAuthFailed(TSSHAuthenticationFailedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnAuthFailed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnAuthFailed(TSSHAuthenticationFailedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnAuthFailed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnAuthBanner(TSSHAuthBannerEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnAuthBanner(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnAuthBanner(TSSHAuthBannerEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnAuthBanner(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnAuthPassword(TSSHAuthPasswordEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnAuthPassword(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnAuthPassword(TSSHAuthPasswordEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnAuthPassword(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnAuthPasswordChange(TSSHAuthPasswordChangeEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnAuthPasswordChange(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnAuthPasswordChange(TSSHAuthPasswordChangeEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnAuthPasswordChange(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnAuthPublicKey(TSSHAuthPublicKeyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnAuthPublicKey(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnAuthPublicKey(TSSHAuthPublicKeyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnAuthPublicKey(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnAuthHostbased(TSSHAuthHostbasedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnAuthHostbased(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnAuthHostbased(TSSHAuthHostbasedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnAuthHostbased(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnAuthKeyboard(TSSHAuthKeyboardEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnAuthKeyboard(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnAuthKeyboard(TSSHAuthKeyboardEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnAuthKeyboard(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnAuthKeyboardResponse(TSSHAuthKeyboardResponseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnAuthKeyboardResponse(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnAuthKeyboardResponse(TSSHAuthKeyboardResponseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnAuthKeyboardResponse(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnFurtherAuthNeeded(TSSHFurtherAuthNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnFurtherAuthNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnFurtherAuthNeeded(TSSHFurtherAuthNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnFurtherAuthNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnBeforeOpenSession(TSSHBeforeOpenSessionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnBeforeOpenSession(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnBeforeOpenSession(TSSHBeforeOpenSessionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnBeforeOpenSession(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnBeforeOpenShell(TSSHBeforeOpenShellEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnBeforeOpenShell(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnBeforeOpenShell(TSSHBeforeOpenShellEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnBeforeOpenShell(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnBeforeOpenCommand(TSSHBeforeOpenCommandEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnBeforeOpenCommand(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnBeforeOpenCommand(TSSHBeforeOpenCommandEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnBeforeOpenCommand(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnBeforeOpenSubsystem(TSSHBeforeOpenSubsystemEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnBeforeOpenSubsystem(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnBeforeOpenSubsystem(TSSHBeforeOpenSubsystemEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnBeforeOpenSubsystem(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnBeforeOpenClientForwarding(TSSHBeforeOpenClientForwardingEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnBeforeOpenClientForwarding(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnBeforeOpenClientForwarding(TSSHBeforeOpenClientForwardingEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnBeforeOpenClientForwarding(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnOpenSession(TSSHOpenSessionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnOpenSession(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnOpenSession(TSSHOpenSessionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnOpenSession(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnOpenShell(TSSHOpenShellEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnOpenShell(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnOpenShell(TSSHOpenShellEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnOpenShell(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnOpenCommand(TSSHOpenCommandEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnOpenCommand(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnOpenCommand(TSSHOpenCommandEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnOpenCommand(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnOpenSubsystem(TSSHOpenSubsystemEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnOpenSubsystem(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnOpenSubsystem(TSSHOpenSubsystemEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnOpenSubsystem(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnOpenClientForwarding(TSSHOpenClientForwardingEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnOpenClientForwarding(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnOpenClientForwarding(TSSHOpenClientForwardingEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnOpenClientForwarding(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnOpenServerForwarding(TSSHOpenServerForwardingEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnOpenServerForwarding(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnOpenServerForwarding(TSSHOpenServerForwardingEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnOpenServerForwarding(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnServerForwardingFailed(TSSHServerForwardingFailedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnServerForwardingFailed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnServerForwardingFailed(TSSHServerForwardingFailedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnServerForwardingFailed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnServerForwardingRequest(TSSHServerForwardingRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnServerForwardingRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnServerForwardingRequest(TSSHServerForwardingRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnServerForwardingRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnServerForwardingCancel(TSSHServerForwardingCancelEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnServerForwardingCancel(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnServerForwardingCancel(TSSHServerForwardingCancelEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnServerForwardingCancel(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnSpecialMessageReceived(TSSHSpecialMessageEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnSpecialMessageReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnSpecialMessageReceived(TSSHSpecialMessageEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnSpecialMessageReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnKexInitReceived(TSSHKexInitReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnKexInitReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnKexInitReceived(TSSHKexInitReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnKexInitReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnOpenConnection(TSSHOpenConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnOpenConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnOpenConnection(TSSHOpenConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnOpenConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnCloseConnection(TSSHCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnCloseConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnCloseConnection(TSSHCloseConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnCloseConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnError(TSSHErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnError(TSSHErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnPubKeyReceive(TSBSSHPublicKeyReceiveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnPubKeyReceive(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnPubKeyReceive(TSBSSHPublicKeyReceiveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnPubKeyReceive(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnPubKeySend(TSBSSHPublicKeySendEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnPubKeySend(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnPubKeySend(TSBSSHPublicKeySendEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnPubKeySend(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnPubKeyClose(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnPubKeyClose(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnPubKeyClose(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnPubKeyClose(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnPubKeyError(TSBSSHPublicKeyErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnPubKeyError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnPubKeyError(TSBSSHPublicKeyErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnPubKeyError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnPubKeyOpen(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnPubKeyOpen(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnPubKeyOpen(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnPubKeyOpen(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnPubKeyStatus(TSBSSHPublicKeyStatusEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnPubKeyStatus(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnPubKeyStatus(TSBSSHPublicKeyStatusEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnPubKeyStatus(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnPubKeyAdd(TSBSSHPublicKeyAddEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnPubKeyAdd(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnPubKeyAdd(TSBSSHPublicKeyAddEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnPubKeyAdd(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnPubKeyRemove(TSBSSHPublicKeyRemoveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnPubKeyRemove(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnPubKeyRemove(TSBSSHPublicKeyRemoveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnPubKeyRemove(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnPubKeyList(TSBSSHPublicKeyListEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnPubKeyList(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnPubKeyList(TSBSSHPublicKeyListEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnPubKeyList(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnPubKeyListAttributes(TSBSSHPublicKeyListAttributesEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnPubKeyListAttributes(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnPubKeyListAttributes(TSBSSHPublicKeyListAttributesEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnPubKeyListAttributes(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHServer::get_OnPubKeyAttributeSupported(TSBSSHPublicKeyAttrubuteSupportedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHServer_get_OnPubKeyAttributeSupported(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHServer::set_OnPubKeyAttributeSupported(TSBSSHPublicKeyAttrubuteSupportedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHServer_set_OnPubKeyAttributeSupported(_Handle, pMethodValue, pDataValue));
}

void TElSimpleSSHServer::initInstances()
{
#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
	this->_Inst_SocketSettings = NULL;
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
	this->_Inst_KeyStorage = NULL;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELSSHUSERS
	this->_Inst_Users = NULL;
#endif /* SB_USE_CLASS_TELSSHUSERS */
}

TElSimpleSSHServer::TElSimpleSSHServer(TElSimpleSSHServerHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElSimpleSSHServer::TElSimpleSSHServer(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleSSHServer_Create(AOwner.getHandle(), &_Handle));
}

TElSimpleSSHServer::TElSimpleSSHServer(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleSSHServer_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSimpleSSHServer::~TElSimpleSSHServer()
{
#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
	delete this->_Inst_SocketSettings;
	this->_Inst_SocketSettings = NULL;
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
	delete this->_Inst_KeyStorage;
	this->_Inst_KeyStorage = NULL;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELSSHUSERS
	delete this->_Inst_Users;
	this->_Inst_Users = NULL;
#endif /* SB_USE_CLASS_TELSSHUSERS */
}
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVER */

#ifdef SB_USE_CLASS_TELSSHUSERS

#ifdef SB_USE_CLASS_TELSSHKEY
SB_INLINE void TElSSHUsers::AddSSHUser(const std::string &UserName, const std::string &Password, TElSSHKey &Key)
{
	SBCheckError(TElSSHUsers_AddSSHUser(_Handle, UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), Key.getHandle()));
}

SB_INLINE void TElSSHUsers::AddSSHUser(const std::string &UserName, const std::string &Password, TElSSHKey *Key)
{
	SBCheckError(TElSSHUsers_AddSSHUser(_Handle, UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELSSHKEY
SB_INLINE void TElSSHUsers::AddSSHUser(const std::string &UserName, const std::string &Password, TElSSHKey &Key, const std::string &BasePath)
{
	SBCheckError(TElSSHUsers_AddSSHUser_1(_Handle, UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), Key.getHandle(), BasePath.data(), (int32_t)BasePath.length()));
}

SB_INLINE void TElSSHUsers::AddSSHUser(const std::string &UserName, const std::string &Password, TElSSHKey *Key, const std::string &BasePath)
{
	SBCheckError(TElSSHUsers_AddSSHUser_1(_Handle, UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, BasePath.data(), (int32_t)BasePath.length()));
}
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELSSHKEY
SB_INLINE void TElSSHUsers::UpdateSSHUser(const std::string &UserName, const std::string &Password, TElSSHKey &Key)
{
	SBCheckError(TElSSHUsers_UpdateSSHUser(_Handle, UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), Key.getHandle()));
}

SB_INLINE void TElSSHUsers::UpdateSSHUser(const std::string &UserName, const std::string &Password, TElSSHKey *Key)
{
	SBCheckError(TElSSHUsers_UpdateSSHUser(_Handle, UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELSSHUSER
SB_INLINE TElSSHUserHandle TElSSHUsers::FindSSHUser(const std::string &UserName)
{
	TElSSHUserHandle OutResult;
	SBCheckError(TElSSHUsers_FindSSHUser(_Handle, UserName.data(), (int32_t)UserName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSSHUSER */

#ifdef SB_USE_CLASS_TELSSHKEY
bool TElSSHUsers::IsValidSSHKey(const std::string &UserName, TElSSHKey &Key)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHUsers_IsValidSSHKey(_Handle, UserName.data(), (int32_t)UserName.length(), Key.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSSHUsers::IsValidSSHKey(const std::string &UserName, TElSSHKey *Key)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHUsers_IsValidSSHKey(_Handle, UserName.data(), (int32_t)UserName.length(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSSHKEY */

TElSSHUsers::TElSSHUsers(TElSSHUsersHandle handle, TElOwnHandle ownHandle) : TElUsers(handle, ownHandle)
{
}

TElSSHUsers::TElSSHUsers(TComponent &AOwner) : TElUsers(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHUsers_Create(AOwner.getHandle(), &_Handle));
}

TElSSHUsers::TElSSHUsers(TComponent *AOwner) : TElUsers(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHUsers_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELSSHUSERS */

#ifdef SB_USE_CLASS_TELCUSTOMSESSIONTHREAD

SB_INLINE void TElCustomSessionThread::get_OnSessionTerminate(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCustomSessionThread_get_OnSessionTerminate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCustomSessionThread::set_OnSessionTerminate(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCustomSessionThread_set_OnSessionTerminate(_Handle, pMethodValue, pDataValue));
}

TElCustomSessionThread::TElCustomSessionThread(TElCustomSessionThreadHandle handle, TElOwnHandle ownHandle) : TThread(handle, ownHandle)
{
}

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
TElCustomSessionThread::TElCustomSessionThread(bool CreateSuspended, uint32_t StackSize) : TThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomSessionThread_Create((int8_t)CreateSuspended, StackSize, &_Handle));
}
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

#endif /* SB_USE_CLASS_TELCUSTOMSESSIONTHREAD */

#ifdef SB_USE_CLASS_TELSIMPLESSHSERVERLISTENINGTHREAD

#ifdef SB_USE_CLASS_TELSIMPLESSHSERVER
TElSimpleSSHServer* TElSimpleSSHServerListeningThread::get_Owner()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHServerListeningThread_get_Owner(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Owner)
		this->_Inst_Owner = new TElSimpleSSHServer(hOutResult, ohFalse);
	else
		this->_Inst_Owner->updateHandle(hOutResult);
	return this->_Inst_Owner;
}

SB_INLINE void TElSimpleSSHServerListeningThread::set_Owner(TElSimpleSSHServer &Value)
{
	SBCheckError(TElSimpleSSHServerListeningThread_set_Owner(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSSHServerListeningThread::set_Owner(TElSimpleSSHServer *Value)
{
	SBCheckError(TElSimpleSSHServerListeningThread_set_Owner(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVER */

#ifdef SB_USE_CLASS_TELSOCKET
TElSocket* TElSimpleSSHServerListeningThread::get_Socket()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHServerListeningThread_get_Socket(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Socket)
		this->_Inst_Socket = new TElSocket(hOutResult, ohFalse);
	else
		this->_Inst_Socket->updateHandle(hOutResult);
	return this->_Inst_Socket;
}

SB_INLINE void TElSimpleSSHServerListeningThread::set_Socket(TElSocket &Value)
{
	SBCheckError(TElSimpleSSHServerListeningThread_set_Socket(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSSHServerListeningThread::set_Socket(TElSocket *Value)
{
	SBCheckError(TElSimpleSSHServerListeningThread_set_Socket(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSOCKET */

void TElSimpleSSHServerListeningThread::initInstances()
{
#ifdef SB_USE_CLASS_TELSIMPLESSHSERVER
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVER */
#ifdef SB_USE_CLASS_TELSOCKET
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
}

TElSimpleSSHServerListeningThread::TElSimpleSSHServerListeningThread(TElSimpleSSHServerListeningThreadHandle handle, TElOwnHandle ownHandle) : TElCustomSessionThread(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
TElSimpleSSHServerListeningThread::TElSimpleSSHServerListeningThread(bool CreateSuspended, uint32_t StackSize) : TElCustomSessionThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleSSHServerListeningThread_Create((int8_t)CreateSuspended, StackSize, &_Handle));
}
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

TElSimpleSSHServerListeningThread::~TElSimpleSSHServerListeningThread()
{
#ifdef SB_USE_CLASS_TELSIMPLESSHSERVER
	delete this->_Inst_Owner;
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVER */
#ifdef SB_USE_CLASS_TELSOCKET
	delete this->_Inst_Socket;
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
}
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVERLISTENINGTHREAD */

#ifdef SB_USE_CLASS_TELSIMPLESSHSERVERSESSIONTHREAD

#ifdef SB_USE_CLASS_TELSIMPLESSHSERVER
TElSimpleSSHServer* TElSimpleSSHServerSessionThread::get_Owner()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHServerSessionThread_get_Owner(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Owner)
		this->_Inst_Owner = new TElSimpleSSHServer(hOutResult, ohFalse);
	else
		this->_Inst_Owner->updateHandle(hOutResult);
	return this->_Inst_Owner;
}

SB_INLINE void TElSimpleSSHServerSessionThread::set_Owner(TElSimpleSSHServer &Value)
{
	SBCheckError(TElSimpleSSHServerSessionThread_set_Owner(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSSHServerSessionThread::set_Owner(TElSimpleSSHServer *Value)
{
	SBCheckError(TElSimpleSSHServerSessionThread_set_Owner(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVER */

#ifdef SB_USE_CLASS_TELSOCKET
TElSocket* TElSimpleSSHServerSessionThread::get_Socket()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHServerSessionThread_get_Socket(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Socket)
		this->_Inst_Socket = new TElSocket(hOutResult, ohFalse);
	else
		this->_Inst_Socket->updateHandle(hOutResult);
	return this->_Inst_Socket;
}

SB_INLINE void TElSimpleSSHServerSessionThread::set_Socket(TElSocket &Value)
{
	SBCheckError(TElSimpleSSHServerSessionThread_set_Socket(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSSHServerSessionThread::set_Socket(TElSocket *Value)
{
	SBCheckError(TElSimpleSSHServerSessionThread_set_Socket(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSOCKET */

#ifdef SB_USE_CLASS_TELSSHSERVER
TElSSHServer* TElSimpleSSHServerSessionThread::get_SSHServer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHServerSessionThread_get_SSHServer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SSHServer)
		this->_Inst_SSHServer = new TElSSHServer(hOutResult, ohFalse);
	else
		this->_Inst_SSHServer->updateHandle(hOutResult);
	return this->_Inst_SSHServer;
}
#endif /* SB_USE_CLASS_TELSSHSERVER */

void TElSimpleSSHServerSessionThread::initInstances()
{
#ifdef SB_USE_CLASS_TELSIMPLESSHSERVER
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVER */
#ifdef SB_USE_CLASS_TELSOCKET
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifdef SB_USE_CLASS_TELSSHSERVER
	this->_Inst_SSHServer = NULL;
#endif /* SB_USE_CLASS_TELSSHSERVER */
}

TElSimpleSSHServerSessionThread::TElSimpleSSHServerSessionThread(TElSimpleSSHServerSessionThreadHandle handle, TElOwnHandle ownHandle) : TElCustomSessionThread(handle, ownHandle)
{
	initInstances();
}

TElSimpleSSHServerSessionThread::TElSimpleSSHServerSessionThread() : TElCustomSessionThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleSSHServerSessionThread_Create(&_Handle));
}

TElSimpleSSHServerSessionThread::~TElSimpleSSHServerSessionThread()
{
#ifdef SB_USE_CLASS_TELSIMPLESSHSERVER
	delete this->_Inst_Owner;
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVER */
#ifdef SB_USE_CLASS_TELSOCKET
	delete this->_Inst_Socket;
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifdef SB_USE_CLASS_TELSSHSERVER
	delete this->_Inst_SSHServer;
	this->_Inst_SSHServer = NULL;
#endif /* SB_USE_CLASS_TELSSHSERVER */
}
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVERSESSIONTHREAD */

#ifdef SB_USE_CLASS_TELSIMPLESSHSERVERFORWARDINGLISTENINGTHREAD

#ifdef SB_USE_CLASS_TELSIMPLESSHSERVER
TElSimpleSSHServer* TElSimpleSSHServerForwardingListeningThread::get_Owner()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHServerForwardingListeningThread_get_Owner(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Owner)
		this->_Inst_Owner = new TElSimpleSSHServer(hOutResult, ohFalse);
	else
		this->_Inst_Owner->updateHandle(hOutResult);
	return this->_Inst_Owner;
}

SB_INLINE void TElSimpleSSHServerForwardingListeningThread::set_Owner(TElSimpleSSHServer &Value)
{
	SBCheckError(TElSimpleSSHServerForwardingListeningThread_set_Owner(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSSHServerForwardingListeningThread::set_Owner(TElSimpleSSHServer *Value)
{
	SBCheckError(TElSimpleSSHServerForwardingListeningThread_set_Owner(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVER */

#ifdef SB_USE_CLASS_TELSOCKET
TElSocket* TElSimpleSSHServerForwardingListeningThread::get_Socket()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHServerForwardingListeningThread_get_Socket(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Socket)
		this->_Inst_Socket = new TElSocket(hOutResult, ohFalse);
	else
		this->_Inst_Socket->updateHandle(hOutResult);
	return this->_Inst_Socket;
}
#endif /* SB_USE_CLASS_TELSOCKET */

#ifdef SB_USE_CLASS_TELSSHSERVER
TElSSHServer* TElSimpleSSHServerForwardingListeningThread::get_SSHServer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHServerForwardingListeningThread_get_SSHServer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SSHServer)
		this->_Inst_SSHServer = new TElSSHServer(hOutResult, ohFalse);
	else
		this->_Inst_SSHServer->updateHandle(hOutResult);
	return this->_Inst_SSHServer;
}

SB_INLINE void TElSimpleSSHServerForwardingListeningThread::set_SSHServer(TElSSHServer &Value)
{
	SBCheckError(TElSimpleSSHServerForwardingListeningThread_set_SSHServer(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSSHServerForwardingListeningThread::set_SSHServer(TElSSHServer *Value)
{
	SBCheckError(TElSimpleSSHServerForwardingListeningThread_set_SSHServer(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHSERVER */

void TElSimpleSSHServerForwardingListeningThread::initInstances()
{
#ifdef SB_USE_CLASS_TELSIMPLESSHSERVER
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVER */
#ifdef SB_USE_CLASS_TELSOCKET
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifdef SB_USE_CLASS_TELSSHSERVER
	this->_Inst_SSHServer = NULL;
#endif /* SB_USE_CLASS_TELSSHSERVER */
}

TElSimpleSSHServerForwardingListeningThread::TElSimpleSSHServerForwardingListeningThread(TElSimpleSSHServerForwardingListeningThreadHandle handle, TElOwnHandle ownHandle) : TElCustomSessionThread(handle, ownHandle)
{
	initInstances();
}

TElSimpleSSHServerForwardingListeningThread::TElSimpleSSHServerForwardingListeningThread() : TElCustomSessionThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleSSHServerForwardingListeningThread_Create(&_Handle));
}

TElSimpleSSHServerForwardingListeningThread::~TElSimpleSSHServerForwardingListeningThread()
{
#ifdef SB_USE_CLASS_TELSIMPLESSHSERVER
	delete this->_Inst_Owner;
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVER */
#ifdef SB_USE_CLASS_TELSOCKET
	delete this->_Inst_Socket;
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifdef SB_USE_CLASS_TELSSHSERVER
	delete this->_Inst_SSHServer;
	this->_Inst_SSHServer = NULL;
#endif /* SB_USE_CLASS_TELSSHSERVER */
}
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVERFORWARDINGLISTENINGTHREAD */

#ifdef SB_USE_CLASS_TELSIMPLESSHSERVERFORWARDINGSESSIONTHREAD

SB_INLINE void TElSimpleSSHServerForwardingSessionThread::InternalExecute()
{
	SBCheckError(TElSimpleSSHServerForwardingSessionThread_InternalExecute(_Handle));
}

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElSSHTunnelConnection* TElSimpleSSHServerForwardingSessionThread::get_Connection()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHServerForwardingSessionThread_get_Connection(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Connection)
		this->_Inst_Connection = new TElSSHTunnelConnection(hOutResult, ohFalse);
	else
		this->_Inst_Connection->updateHandle(hOutResult);
	return this->_Inst_Connection;
}

SB_INLINE void TElSimpleSSHServerForwardingSessionThread::set_Connection(TElSSHTunnelConnection &Value)
{
	SBCheckError(TElSimpleSSHServerForwardingSessionThread_set_Connection(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSSHServerForwardingSessionThread::set_Connection(TElSSHTunnelConnection *Value)
{
	SBCheckError(TElSimpleSSHServerForwardingSessionThread_set_Connection(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELBUILTINSERVERTCPFORWARDINGSSHSUBSYSTEMHANDLER
TElBuiltinServerTCPForwardingSSHSubsystemHandler* TElSimpleSSHServerForwardingSessionThread::get_Handler()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHServerForwardingSessionThread_get_Handler(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Handler)
		this->_Inst_Handler = new TElBuiltinServerTCPForwardingSSHSubsystemHandler(hOutResult, ohFalse);
	else
		this->_Inst_Handler->updateHandle(hOutResult);
	return this->_Inst_Handler;
}
#endif /* SB_USE_CLASS_TELBUILTINSERVERTCPFORWARDINGSSHSUBSYSTEMHANDLER */

#ifdef SB_USE_CLASS_TELSOCKET
TElSocket* TElSimpleSSHServerForwardingSessionThread::get_Socket()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHServerForwardingSessionThread_get_Socket(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Socket)
		this->_Inst_Socket = new TElSocket(hOutResult, ohFalse);
	else
		this->_Inst_Socket->updateHandle(hOutResult);
	return this->_Inst_Socket;
}
#endif /* SB_USE_CLASS_TELSOCKET */

void TElSimpleSSHServerForwardingSessionThread::initInstances()
{
#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
	this->_Inst_Connection = NULL;
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */
#ifdef SB_USE_CLASS_TELBUILTINSERVERTCPFORWARDINGSSHSUBSYSTEMHANDLER
	this->_Inst_Handler = NULL;
#endif /* SB_USE_CLASS_TELBUILTINSERVERTCPFORWARDINGSSHSUBSYSTEMHANDLER */
#ifdef SB_USE_CLASS_TELSOCKET
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
}

TElSimpleSSHServerForwardingSessionThread::TElSimpleSSHServerForwardingSessionThread(TElSimpleSSHServerForwardingSessionThreadHandle handle, TElOwnHandle ownHandle) : TElCustomSessionThread(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELSOCKET
TElSimpleSSHServerForwardingSessionThread::TElSimpleSSHServerForwardingSessionThread(TElSocket &Socket) : TElCustomSessionThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleSSHServerForwardingSessionThread_Create(Socket.getHandle(), &_Handle));
}

TElSimpleSSHServerForwardingSessionThread::TElSimpleSSHServerForwardingSessionThread(TElSocket *Socket) : TElCustomSessionThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleSSHServerForwardingSessionThread_Create((Socket != NULL) ? Socket->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSOCKET */

TElSimpleSSHServerForwardingSessionThread::~TElSimpleSSHServerForwardingSessionThread()
{
#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
	delete this->_Inst_Connection;
	this->_Inst_Connection = NULL;
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */
#ifdef SB_USE_CLASS_TELBUILTINSERVERTCPFORWARDINGSSHSUBSYSTEMHANDLER
	delete this->_Inst_Handler;
	this->_Inst_Handler = NULL;
#endif /* SB_USE_CLASS_TELBUILTINSERVERTCPFORWARDINGSSHSUBSYSTEMHANDLER */
#ifdef SB_USE_CLASS_TELSOCKET
	delete this->_Inst_Socket;
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
}
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVERFORWARDINGSESSIONTHREAD */

};	/* namespace SecureBlackbox */
