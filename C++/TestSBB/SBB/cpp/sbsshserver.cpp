#include "sbsshserver.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSSHUSER

void TElSSHUser::GetData(std::vector<uint8_t> &Buffer, int32_t &Size)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = TElSSHUser_GetData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, &Size);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(2044160758, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}

SB_INLINE void TElSSHUser::SetData(const std::vector<uint8_t> &Value, int32_t Size)
{
	SBCheckError(TElSSHUser_SetData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), Size));
}

SB_INLINE void TElSSHUser::SetBasePath(const std::string &Value)
{
	SBCheckError(TElSSHUser_SetBasePath(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELSSHKEY
SB_INLINE void TElSSHUser::SetSSHKey(TElSSHKey &Value)
{
	SBCheckError(TElSSHUser_SetSSHKey(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSHUser::SetSSHKey(TElSSHKey *Value)
{
	SBCheckError(TElSSHUser_SetSSHKey(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASSES_TELSSHKEY_AND_TELUSERS
SB_INLINE void TElSSHUser::AddUser(TElUsers &Users, const std::string &UserName, const std::string &Password, TElSSHKey &Key)
{
	SBCheckError(TElSSHUser_AddUser(Users.getHandle(), UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), Key.getHandle()));
}

SB_INLINE void TElSSHUser::AddUser(TElUsers *Users, const std::string &UserName, const std::string &Password, TElSSHKey *Key)
{
	SBCheckError(TElSSHUser_AddUser((Users != NULL) ? Users->getHandle() : SB_NULL_HANDLE, UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELSSHKEY_AND_TELUSERS */

#ifdef SB_USE_CLASSES_TELSSHKEY_AND_TELUSERS
SB_INLINE void TElSSHUser::AddUser_Inst(TElUsers &Users, const std::string &UserName, const std::string &Password, TElSSHKey &Key)
{
	SBCheckError(TElSSHUser_AddUser_1(_Handle, Users.getHandle(), UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), Key.getHandle()));
}

SB_INLINE void TElSSHUser::AddUser_Inst(TElUsers *Users, const std::string &UserName, const std::string &Password, TElSSHKey *Key)
{
	SBCheckError(TElSSHUser_AddUser_1(_Handle, (Users != NULL) ? Users->getHandle() : SB_NULL_HANDLE, UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELSSHKEY_AND_TELUSERS */

#ifdef SB_USE_CLASSES_TELSSHKEY_AND_TELUSERS
SB_INLINE void TElSSHUser::AddUser(TElUsers &Users, const std::string &UserName, const std::string &Password, TElSSHKey &Key, const std::string &BasePath)
{
	SBCheckError(TElSSHUser_AddUser_2(Users.getHandle(), UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), Key.getHandle(), BasePath.data(), (int32_t)BasePath.length()));
}

SB_INLINE void TElSSHUser::AddUser(TElUsers *Users, const std::string &UserName, const std::string &Password, TElSSHKey *Key, const std::string &BasePath)
{
	SBCheckError(TElSSHUser_AddUser_2((Users != NULL) ? Users->getHandle() : SB_NULL_HANDLE, UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, BasePath.data(), (int32_t)BasePath.length()));
}
#endif /* SB_USE_CLASSES_TELSSHKEY_AND_TELUSERS */

#ifdef SB_USE_CLASSES_TELSSHKEY_AND_TELUSERS
SB_INLINE void TElSSHUser::AddUser_Inst(TElUsers &Users, const std::string &UserName, const std::string &Password, TElSSHKey &Key, const std::string &BasePath)
{
	SBCheckError(TElSSHUser_AddUser_3(_Handle, Users.getHandle(), UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), Key.getHandle(), BasePath.data(), (int32_t)BasePath.length()));
}

SB_INLINE void TElSSHUser::AddUser_Inst(TElUsers *Users, const std::string &UserName, const std::string &Password, TElSSHKey *Key, const std::string &BasePath)
{
	SBCheckError(TElSSHUser_AddUser_3(_Handle, (Users != NULL) ? Users->getHandle() : SB_NULL_HANDLE, UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, BasePath.data(), (int32_t)BasePath.length()));
}
#endif /* SB_USE_CLASSES_TELSSHKEY_AND_TELUSERS */

#ifdef SB_USE_CLASS_TELSSHKEY
bool TElSSHUser::IsValidSSHKey(TElSSHKey &Key)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHUser_IsValidSSHKey(_Handle, Key.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSSHUser::IsValidSSHKey(TElSSHKey *Key)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHUser_IsValidSSHKey(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSSHKEY */

SB_INLINE TClassHandle TElSSHUser::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElSSHUser_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSSHKEY
TElSSHKey* TElSSHUser::get_SSHKey()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHUser_get_SSHKey(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SSHKey)
		this->_Inst_SSHKey = new TElSSHKey(hOutResult, ohFalse);
	else
		this->_Inst_SSHKey->updateHandle(hOutResult);
	return this->_Inst_SSHKey;
}

SB_INLINE void TElSSHUser::set_SSHKey(TElSSHKey &Value)
{
	SBCheckError(TElSSHUser_set_SSHKey(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSHUser::set_SSHKey(TElSSHKey *Value)
{
	SBCheckError(TElSSHUser_set_SSHKey(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHKEY */

void TElSSHUser::get_BasePath(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHUser_get_BasePath(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(336649201, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHUser::set_BasePath(const std::string &Value)
{
	SBCheckError(TElSSHUser_set_BasePath(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSSHUser::initInstances()
{
#ifdef SB_USE_CLASS_TELSSHKEY
	this->_Inst_SSHKey = NULL;
#endif /* SB_USE_CLASS_TELSSHKEY */
}

TElSSHUser::TElSSHUser(TElSSHUserHandle handle, TElOwnHandle ownHandle) : TElCustomUser(handle, ownHandle)
{
	initInstances();
}

TElSSHUser::TElSSHUser(const std::string &UserName) : TElCustomUser(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHUser_Create(UserName.data(), (int32_t)UserName.length(), &_Handle));
}

TElSSHUser::~TElSSHUser()
{
#ifdef SB_USE_CLASS_TELSSHKEY
	delete this->_Inst_SSHKey;
	this->_Inst_SSHKey = NULL;
#endif /* SB_USE_CLASS_TELSSHKEY */
}
#endif /* SB_USE_CLASS_TELSSHUSER */

#ifdef SB_USE_CLASS_TELSSHSERVERTUNNELCONNECTION

SB_INLINE void TElSSHServerTunnelConnection::SendData(void * Buffer, int32_t Size)
{
	SBCheckError(TElSSHServerTunnelConnection_SendData(_Handle, Buffer, Size));
}

SB_INLINE void TElSSHServerTunnelConnection::SendExtendedData(void * Buffer, int32_t Size)
{
	SBCheckError(TElSSHServerTunnelConnection_SendExtendedData(_Handle, Buffer, Size));
}

bool TElSSHServerTunnelConnection::CanSend()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHServerTunnelConnection_CanSend(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElSSHServerTunnelConnection::GetWindowBufferLength()
{
	int32_t OutResult;
	SBCheckError(TElSSHServerTunnelConnection_GetWindowBufferLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHServerTunnelConnection::GetExtWindowBufferLength()
{
	int32_t OutResult;
	SBCheckError(TElSSHServerTunnelConnection_GetExtWindowBufferLength(_Handle, &OutResult));
	return OutResult;
}

TElSSHServerTunnelConnection::TElSSHServerTunnelConnection(TElSSHServerTunnelConnectionHandle handle, TElOwnHandle ownHandle) : TElSSHTunnelConnection(handle, ownHandle)
{
}

TElSSHServerTunnelConnection::TElSSHServerTunnelConnection() : TElSSHTunnelConnection(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHServerTunnelConnection_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSSHSERVERTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHSERVERADDITIONALSETTINGS

SB_INLINE int32_t TElSSHServerAdditionalSettings::get_OperationStatusCode()
{
	int32_t OutResult;
	SBCheckError(TElSSHServerAdditionalSettings_get_OperationStatusCode(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHServerAdditionalSettings::set_OperationStatusCode(int32_t Value)
{
	SBCheckError(TElSSHServerAdditionalSettings_set_OperationStatusCode(_Handle, Value));
}

void TElSSHServerAdditionalSettings::get_OperationStatusString(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHServerAdditionalSettings_get_OperationStatusString(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-174126538, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHServerAdditionalSettings::set_OperationStatusString(const std::string &Value)
{
	SBCheckError(TElSSHServerAdditionalSettings_set_OperationStatusString(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSSHServerAdditionalSettings::TElSSHServerAdditionalSettings(TElSSHServerAdditionalSettingsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSSHServerAdditionalSettings::TElSSHServerAdditionalSettings() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHServerAdditionalSettings_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSSHSERVERADDITIONALSETTINGS */

#ifdef SB_USE_CLASS_TELSSHSERVER

SB_INLINE void TElSSHServer::Close(bool Forced)
{
	SBCheckError(TElSSHServer_Close(_Handle, (int8_t)Forced));
}

SB_INLINE void TElSSHServer::Close(int32_t ErrorCode, const std::string &Reason)
{
	SBCheckError(TElSSHServer_Close_1(_Handle, ErrorCode, Reason.data(), (int32_t)Reason.length()));
}

SB_INLINE void TElSSHServer::DataAvailable()
{
	SBCheckError(TElSSHServer_DataAvailable(_Handle));
}

SB_INLINE void TElSSHServer::Open()
{
	SBCheckError(TElSSHServer_Open(_Handle));
}

SB_INLINE void TElSSHServer::OpenServerForwarding(const std::string &Address, int32_t Port, const std::string &SrcHost, int32_t SrcPort, void * Data)
{
	SBCheckError(TElSSHServer_OpenServerForwarding(_Handle, Address.data(), (int32_t)Address.length(), Port, SrcHost.data(), (int32_t)SrcHost.length(), SrcPort, Data));
}

SB_INLINE void TElSSHServer::RenegotiateCiphers()
{
	SBCheckError(TElSSHServer_RenegotiateCiphers(_Handle));
}

void TElSSHServer::get_ClientCloseReason(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHServer_get_ClientCloseReason(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1195811431, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSSHServer::get_Username(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHServer_get_Username(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1229872270, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSSHServer::get_ChangePwdPrompt(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSHServer_get_ChangePwdPrompt(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(473760028, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHServer::set_ChangePwdPrompt(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSSHServer_set_ChangePwdPrompt(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElSSHServer::get_AuthTypePriorities(int32_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSSHServer_get_AuthTypePriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHServer::set_AuthTypePriorities(int32_t Index, int32_t Value)
{
	SBCheckError(TElSSHServer_set_AuthTypePriorities(_Handle, Index, Value));
}

SB_INLINE int32_t TElSSHServer::get_DefaultWindowSize()
{
	int32_t OutResult;
	SBCheckError(TElSSHServer_get_DefaultWindowSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHServer::set_DefaultWindowSize(int32_t Value)
{
	SBCheckError(TElSSHServer_set_DefaultWindowSize(_Handle, Value));
}

SB_INLINE int32_t TElSSHServer::get_MinWindowSize()
{
	int32_t OutResult;
	SBCheckError(TElSSHServer_get_MinWindowSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHServer::set_MinWindowSize(int32_t Value)
{
	SBCheckError(TElSSHServer_set_MinWindowSize(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELSSHSERVERADDITIONALSETTINGS
TElSSHServerAdditionalSettings* TElSSHServer::get_AdditionalSettings()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHServer_get_AdditionalSettings(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AdditionalSettings)
		this->_Inst_AdditionalSettings = new TElSSHServerAdditionalSettings(hOutResult, ohFalse);
	else
		this->_Inst_AdditionalSettings->updateHandle(hOutResult);
	return this->_Inst_AdditionalSettings;
}
#endif /* SB_USE_CLASS_TELSSHSERVERADDITIONALSETTINGS */

void TElSSHServer::get_ClientSoftwareName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHServer_get_ClientSoftwareName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1938576961, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSSHServer::get_AllowedSubsystems()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHServer_get_AllowedSubsystems(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AllowedSubsystems)
		this->_Inst_AllowedSubsystems = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_AllowedSubsystems->updateHandle(hOutResult);
	return this->_Inst_AllowedSubsystems;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
TElSSHCustomKeyStorage* TElSSHServer::get_KexKeyStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHServer_get_KexKeyStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KexKeyStorage)
		this->_Inst_KexKeyStorage = new TElSSHCustomKeyStorage(hOutResult, ohFalse);
	else
		this->_Inst_KexKeyStorage->updateHandle(hOutResult);
	return this->_Inst_KexKeyStorage;
}

SB_INLINE void TElSSHServer::set_KexKeyStorage(TElSSHCustomKeyStorage &Value)
{
	SBCheckError(TElSSHServer_set_KexKeyStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSHServer::set_KexKeyStorage(TElSSHCustomKeyStorage *Value)
{
	SBCheckError(TElSSHServer_set_KexKeyStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

bool TElSSHServer::get_ThreadSafe()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHServer_get_ThreadSafe(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHServer::set_ThreadSafe(bool Value)
{
	SBCheckError(TElSSHServer_set_ThreadSafe(_Handle, (int8_t)Value));
}

TSBSSHBannerSendStage TElSSHServer::get_BannerSendStage()
{
	TSBSSHBannerSendStageRaw OutResultRaw = 0;
	SBCheckError(TElSSHServer_get_BannerSendStage(_Handle, &OutResultRaw));
	return (TSBSSHBannerSendStage)OutResultRaw;
}

SB_INLINE void TElSSHServer::set_BannerSendStage(TSBSSHBannerSendStage Value)
{
	SBCheckError(TElSSHServer_set_BannerSendStage(_Handle, (TSBSSHBannerSendStageRaw)Value));
}

TSBSSHAuthOrder TElSSHServer::get_SSHAuthOrder()
{
	TSBSSHAuthOrderRaw OutResultRaw = 0;
	SBCheckError(TElSSHServer_get_SSHAuthOrder(_Handle, &OutResultRaw));
	return (TSBSSHAuthOrder)OutResultRaw;
}

SB_INLINE void TElSSHServer::set_SSHAuthOrder(TSBSSHAuthOrder Value)
{
	SBCheckError(TElSSHServer_set_SSHAuthOrder(_Handle, (TSBSSHAuthOrderRaw)Value));
}

SB_INLINE void TElSSHServer::get_OnAuthAttempt(TSSHAuthAttemptEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnAuthAttempt(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnAuthAttempt(TSSHAuthAttemptEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnAuthAttempt(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnAuthFailed(TSSHAuthenticationFailedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnAuthFailed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnAuthFailed(TSSHAuthenticationFailedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnAuthFailed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnAuthBanner(TSSHAuthBannerEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnAuthBanner(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnAuthBanner(TSSHAuthBannerEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnAuthBanner(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnAuthPassword(TSSHAuthPasswordEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnAuthPassword(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnAuthPassword(TSSHAuthPasswordEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnAuthPassword(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnAuthPasswordChange(TSSHAuthPasswordChangeEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnAuthPasswordChange(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnAuthPasswordChange(TSSHAuthPasswordChangeEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnAuthPasswordChange(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnAuthPublicKey(TSSHAuthPublicKeyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnAuthPublicKey(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnAuthPublicKey(TSSHAuthPublicKeyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnAuthPublicKey(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnAuthHostbased(TSSHAuthHostbasedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnAuthHostbased(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnAuthHostbased(TSSHAuthHostbasedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnAuthHostbased(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnAuthKeyboard(TSSHAuthKeyboardEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnAuthKeyboard(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnAuthKeyboard(TSSHAuthKeyboardEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnAuthKeyboard(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnAuthKeyboardResponse(TSSHAuthKeyboardResponseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnAuthKeyboardResponse(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnAuthKeyboardResponse(TSSHAuthKeyboardResponseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnAuthKeyboardResponse(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnFurtherAuthNeeded(TSSHFurtherAuthNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnFurtherAuthNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnFurtherAuthNeeded(TSSHFurtherAuthNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnFurtherAuthNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnBeforeOpenSession(TSSHBeforeOpenSessionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnBeforeOpenSession(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnBeforeOpenSession(TSSHBeforeOpenSessionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnBeforeOpenSession(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnBeforeOpenShell(TSSHBeforeOpenShellEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnBeforeOpenShell(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnBeforeOpenShell(TSSHBeforeOpenShellEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnBeforeOpenShell(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnBeforeOpenCommand(TSSHBeforeOpenCommandEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnBeforeOpenCommand(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnBeforeOpenCommand(TSSHBeforeOpenCommandEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnBeforeOpenCommand(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnBeforeOpenSubsystem(TSSHBeforeOpenSubsystemEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnBeforeOpenSubsystem(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnBeforeOpenSubsystem(TSSHBeforeOpenSubsystemEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnBeforeOpenSubsystem(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnBeforeOpenClientForwarding(TSSHBeforeOpenClientForwardingEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnBeforeOpenClientForwarding(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnBeforeOpenClientForwarding(TSSHBeforeOpenClientForwardingEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnBeforeOpenClientForwarding(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnBeforeOpenX11Forwarding(TSSHBeforeOpenX11ForwardingEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnBeforeOpenX11Forwarding(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnBeforeOpenX11Forwarding(TSSHBeforeOpenX11ForwardingEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnBeforeOpenX11Forwarding(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnOpenSession(TSSHOpenSessionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnOpenSession(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnOpenSession(TSSHOpenSessionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnOpenSession(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnOpenShell(TSSHOpenShellEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnOpenShell(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnOpenShell(TSSHOpenShellEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnOpenShell(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnOpenCommand(TSSHOpenCommandEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnOpenCommand(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnOpenCommand(TSSHOpenCommandEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnOpenCommand(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnOpenSubsystem(TSSHOpenSubsystemEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnOpenSubsystem(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnOpenSubsystem(TSSHOpenSubsystemEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnOpenSubsystem(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnOpenClientForwarding(TSSHOpenClientForwardingEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnOpenClientForwarding(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnOpenClientForwarding(TSSHOpenClientForwardingEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnOpenClientForwarding(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnOpenServerForwarding(TSSHOpenServerForwardingEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnOpenServerForwarding(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnOpenServerForwarding(TSSHOpenServerForwardingEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnOpenServerForwarding(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnOpenX11Forwarding(TSSHOpenX11ForwardingEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnOpenX11Forwarding(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnOpenX11Forwarding(TSSHOpenX11ForwardingEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnOpenX11Forwarding(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnServerForwardingFailed(TSSHServerForwardingFailedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnServerForwardingFailed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnServerForwardingFailed(TSSHServerForwardingFailedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnServerForwardingFailed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnServerForwardingRequest(TSSHServerForwardingRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnServerForwardingRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnServerForwardingRequest(TSSHServerForwardingRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnServerForwardingRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnServerForwardingCancel(TSSHServerForwardingCancelEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnServerForwardingCancel(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnServerForwardingCancel(TSSHServerForwardingCancelEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnServerForwardingCancel(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnX11ForwardingRequest(TSSHX11ForwardingRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnX11ForwardingRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnX11ForwardingRequest(TSSHX11ForwardingRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnX11ForwardingRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnTerminalRequest(TSSHTerminalRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnTerminalRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnTerminalRequest(TSSHTerminalRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnTerminalRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHServer::get_OnSpecialMessageReceived(TSSHSpecialMessageEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHServer_get_OnSpecialMessageReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHServer::set_OnSpecialMessageReceived(TSSHSpecialMessageEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHServer_set_OnSpecialMessageReceived(_Handle, pMethodValue, pDataValue));
}

void TElSSHServer::initInstances()
{
#ifdef SB_USE_CLASS_TELSSHSERVERADDITIONALSETTINGS
	this->_Inst_AdditionalSettings = NULL;
#endif /* SB_USE_CLASS_TELSSHSERVERADDITIONALSETTINGS */
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_AllowedSubsystems = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
	this->_Inst_KexKeyStorage = NULL;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
}

TElSSHServer::TElSSHServer(TElSSHServerHandle handle, TElOwnHandle ownHandle) : TElSSHClass(handle, ownHandle)
{
	initInstances();
}

TElSSHServer::TElSSHServer(TComponent &AOwner) : TElSSHClass(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHServer_Create(AOwner.getHandle(), &_Handle));
}

TElSSHServer::TElSSHServer(TComponent *AOwner) : TElSSHClass(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHServer_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSSHServer::~TElSSHServer()
{
#ifdef SB_USE_CLASS_TELSSHSERVERADDITIONALSETTINGS
	delete this->_Inst_AdditionalSettings;
	this->_Inst_AdditionalSettings = NULL;
#endif /* SB_USE_CLASS_TELSSHSERVERADDITIONALSETTINGS */
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_AllowedSubsystems;
	this->_Inst_AllowedSubsystems = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
	delete this->_Inst_KexKeyStorage;
	this->_Inst_KexKeyStorage = NULL;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
}
#endif /* SB_USE_CLASS_TELSSHSERVER */

};	/* namespace SecureBlackbox */

