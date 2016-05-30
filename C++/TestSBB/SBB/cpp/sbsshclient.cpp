#include "sbsshclient.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSSHCLIENT

SB_INLINE void TElSSHClient::Open()
{
	SBCheckError(TElSSHClient_Open(_Handle));
}

SB_INLINE void TElSSHClient::Close(bool Forced)
{
	SBCheckError(TElSSHClient_Close(_Handle, (int8_t)Forced));
}

SB_INLINE void TElSSHClient::DataAvailable()
{
	SBCheckError(TElSSHClient_DataAvailable(_Handle));
}

SB_INLINE void TElSSHClient::RenegotiateCiphers()
{
	SBCheckError(TElSSHClient_RenegotiateCiphers(_Handle));
}

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
SB_INLINE void TElSSHClient::SendKeepAlive(TElSSHTunnelConnection &Connection)
{
	SBCheckError(TElSSHClient_SendKeepAlive(_Handle, Connection.getHandle()));
}

SB_INLINE void TElSSHClient::SendKeepAlive(TElSSHTunnelConnection *Connection)
{
	SBCheckError(TElSSHClient_SendKeepAlive(_Handle, (Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

SB_INLINE void TElSSHClient::SendIgnore()
{
	SBCheckError(TElSSHClient_SendIgnore(_Handle));
}

SB_INLINE void TElSSHClient::SendIgnore(const std::vector<uint8_t> &Data, int32_t StartIndex, int32_t Count)
{
	SBCheckError(TElSSHClient_SendIgnore_1(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), StartIndex, Count));
}

TSSHVersion TElSSHClient::get_Version()
{
	TSSHVersionRaw OutResultRaw = 0;
	SBCheckError(TElSSHClient_get_Version(_Handle, &OutResultRaw));
	return (TSSHVersion)OutResultRaw;
}

void TElSSHClient::get_ServerCloseReason(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHClient_get_ServerCloseReason(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1961797465, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSSHClient::get_ServerSoftwareName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHClient_get_ServerSoftwareName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1294015505, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSSHClient::get_ErrorString(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHClient_get_ErrorString(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1276843857, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSSHClient::get_KbdIntName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHClient_get_KbdIntName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1559600870, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSSHClient::get_KbdIntInstruction(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHClient_get_KbdIntInstruction(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(217447379, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElSSHClient::get_AuthTypePriorities(int32_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSSHClient_get_AuthTypePriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHClient::set_AuthTypePriorities(int32_t Index, int32_t Value)
{
	SBCheckError(TElSSHClient_set_AuthTypePriorities(_Handle, Index, Value));
}

#ifdef SB_USE_CLASS_TELSSHKEY
TElSSHKey* TElSSHClient::get_ServerKey()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHClient_get_ServerKey(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ServerKey)
		this->_Inst_ServerKey = new TElSSHKey(hOutResult, ohFalse);
	else
		this->_Inst_ServerKey->updateHandle(hOutResult);
	return this->_Inst_ServerKey;
}
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELGSSBASEMECHANISM
TElGSSBaseMechanism* TElSSHClient::get_GSSMechanism()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHClient_get_GSSMechanism(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_GSSMechanism)
		this->_Inst_GSSMechanism = new TElGSSBaseMechanism(hOutResult, ohFalse);
	else
		this->_Inst_GSSMechanism->updateHandle(hOutResult);
	return this->_Inst_GSSMechanism;
}

SB_INLINE void TElSSHClient::set_GSSMechanism(TElGSSBaseMechanism &Value)
{
	SBCheckError(TElSSHClient_set_GSSMechanism(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSHClient::set_GSSMechanism(TElGSSBaseMechanism *Value)
{
	SBCheckError(TElSSHClient_set_GSSMechanism(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELGSSBASEMECHANISM */

void TElSSHClient::get_GSSHostName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHClient_get_GSSHostName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1564874841, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHClient::set_GSSHostName(const std::string &Value)
{
	SBCheckError(TElSSHClient_set_GSSHostName(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSSHClient::get_GSSDelegateCredentials()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHClient_get_GSSDelegateCredentials(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHClient::set_GSSDelegateCredentials(bool Value)
{
	SBCheckError(TElSSHClient_set_GSSDelegateCredentials(_Handle, (int8_t)Value));
}

TSBSSHAuthOrder TElSSHClient::get_SSHAuthOrder()
{
	TSBSSHAuthOrderRaw OutResultRaw = 0;
	SBCheckError(TElSSHClient_get_SSHAuthOrder(_Handle, &OutResultRaw));
	return (TSBSSHAuthOrder)OutResultRaw;
}

SB_INLINE void TElSSHClient::set_SSHAuthOrder(TSBSSHAuthOrder Value)
{
	SBCheckError(TElSSHClient_set_SSHAuthOrder(_Handle, (TSBSSHAuthOrderRaw)Value));
}

TSSHVersions TElSSHClient::get_Versions()
{
	TSSHVersionsRaw OutResultRaw = 0;
	SBCheckError(TElSSHClient_get_Versions(_Handle, &OutResultRaw));
	return (TSSHVersions)OutResultRaw;
}

SB_INLINE void TElSSHClient::set_Versions(TSSHVersions Value)
{
	SBCheckError(TElSSHClient_set_Versions(_Handle, (TSSHVersionsRaw)Value));
}

void TElSSHClient::get_ClientUserName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHClient_get_ClientUserName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(675374349, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHClient::set_ClientUserName(const std::string &Value)
{
	SBCheckError(TElSSHClient_set_ClientUserName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSSHClient::get_ClientHostName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHClient_get_ClientHostName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(894346091, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHClient::set_ClientHostName(const std::string &Value)
{
	SBCheckError(TElSSHClient_set_ClientHostName(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSSHClient::get_DefaultWindowSize()
{
	int32_t OutResult;
	SBCheckError(TElSSHClient_get_DefaultWindowSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHClient::set_DefaultWindowSize(int32_t Value)
{
	SBCheckError(TElSSHClient_set_DefaultWindowSize(_Handle, Value));
}

SB_INLINE int32_t TElSSHClient::get_MinWindowSize()
{
	int32_t OutResult;
	SBCheckError(TElSSHClient_get_MinWindowSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHClient::set_MinWindowSize(int32_t Value)
{
	SBCheckError(TElSSHClient_set_MinWindowSize(_Handle, Value));
}

SB_INLINE int32_t TElSSHClient::get_MaxSSHPacketSize()
{
	int32_t OutResult;
	SBCheckError(TElSSHClient_get_MaxSSHPacketSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHClient::set_MaxSSHPacketSize(int32_t Value)
{
	SBCheckError(TElSSHClient_set_MaxSSHPacketSize(_Handle, Value));
}

void TElSSHClient::get_UserName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHClient_get_UserName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1318213154, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHClient::set_UserName(const std::string &Value)
{
	SBCheckError(TElSSHClient_set_UserName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSSHClient::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHClient_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-591182270, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHClient::set_Password(const std::string &Value)
{
	SBCheckError(TElSSHClient_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELSSHTUNNELLIST
TElSSHTunnelList* TElSSHClient::get_TunnelList()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHClient_get_TunnelList(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TunnelList)
		this->_Inst_TunnelList = new TElSSHTunnelList(hOutResult, ohFalse);
	else
		this->_Inst_TunnelList->updateHandle(hOutResult);
	return this->_Inst_TunnelList;
}

SB_INLINE void TElSSHClient::set_TunnelList(TElSSHTunnelList &Value)
{
	SBCheckError(TElSSHClient_set_TunnelList(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSHClient::set_TunnelList(TElSSHTunnelList *Value)
{
	SBCheckError(TElSSHClient_set_TunnelList(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHTUNNELLIST */

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
TElSSHCustomKeyStorage* TElSSHClient::get_TrustedKeys()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHClient_get_TrustedKeys(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TrustedKeys)
		this->_Inst_TrustedKeys = new TElSSHCustomKeyStorage(hOutResult, ohFalse);
	else
		this->_Inst_TrustedKeys->updateHandle(hOutResult);
	return this->_Inst_TrustedKeys;
}

SB_INLINE void TElSSHClient::set_TrustedKeys(TElSSHCustomKeyStorage &Value)
{
	SBCheckError(TElSSHClient_set_TrustedKeys(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSHClient::set_TrustedKeys(TElSSHCustomKeyStorage *Value)
{
	SBCheckError(TElSSHClient_set_TrustedKeys(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

bool TElSSHClient::get_ThreadSafe()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHClient_get_ThreadSafe(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHClient::set_ThreadSafe(bool Value)
{
	SBCheckError(TElSSHClient_set_ThreadSafe(_Handle, (int8_t)Value));
}

TSBSSHCertAuthMode TElSSHClient::get_CertAuthMode()
{
	TSBSSHCertAuthModeRaw OutResultRaw = 0;
	SBCheckError(TElSSHClient_get_CertAuthMode(_Handle, &OutResultRaw));
	return (TSBSSHCertAuthMode)OutResultRaw;
}

SB_INLINE void TElSSHClient::set_CertAuthMode(TSBSSHCertAuthMode Value)
{
	SBCheckError(TElSSHClient_set_CertAuthMode(_Handle, (TSBSSHCertAuthModeRaw)Value));
}

bool TElSSHClient::get_AutoAdjustCiphers()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHClient_get_AutoAdjustCiphers(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHClient::set_AutoAdjustCiphers(bool Value)
{
	SBCheckError(TElSSHClient_set_AutoAdjustCiphers(_Handle, (int8_t)Value));
}

bool TElSSHClient::get_RequestPasswordChange()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHClient_get_RequestPasswordChange(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHClient::set_RequestPasswordChange(bool Value)
{
	SBCheckError(TElSSHClient_set_RequestPasswordChange(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElSSHClient::get_AuthAttempts()
{
	int32_t OutResult;
	SBCheckError(TElSSHClient_get_AuthAttempts(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHClient::set_AuthAttempts(int32_t Value)
{
	SBCheckError(TElSSHClient_set_AuthAttempts(_Handle, Value));
}

SB_INLINE void TElSSHClient::get_OnKeyValidate(TSSHKeyValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHClient_get_OnKeyValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHClient::set_OnKeyValidate(TSSHKeyValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHClient_set_OnKeyValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHClient::get_OnAuthenticationSuccess(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHClient_get_OnAuthenticationSuccess(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHClient::set_OnAuthenticationSuccess(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHClient_set_OnAuthenticationSuccess(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHClient::get_OnAuthenticationFailed(TSSHAuthenticationFailedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHClient_get_OnAuthenticationFailed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHClient::set_OnAuthenticationFailed(TSSHAuthenticationFailedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHClient_set_OnAuthenticationFailed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHClient::get_OnAuthenticationKeyboard(TSSHAuthenticationKeyboardEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHClient_get_OnAuthenticationKeyboard(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHClient::set_OnAuthenticationKeyboard(TSSHAuthenticationKeyboardEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHClient_set_OnAuthenticationKeyboard(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHClient::get_OnAuthenticationStart(TSSHAuthenticationStartEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHClient_get_OnAuthenticationStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHClient::set_OnAuthenticationStart(TSSHAuthenticationStartEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHClient_set_OnAuthenticationStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHClient::get_OnAuthenticationAttempt(TSSHAuthenticationAttemptEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHClient_get_OnAuthenticationAttempt(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHClient::set_OnAuthenticationAttempt(TSSHAuthenticationAttemptEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHClient_set_OnAuthenticationAttempt(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHClient::get_OnBanner(TSSHBannerEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHClient_get_OnBanner(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHClient::set_OnBanner(TSSHBannerEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHClient_set_OnBanner(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHClient::get_OnPrivateKeyNeeded(TSSHPrivateKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHClient_get_OnPrivateKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHClient::set_OnPrivateKeyNeeded(TSSHPrivateKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHClient_set_OnPrivateKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHClient::get_OnSendCommandRequest(TSSHCommandExecutionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHClient_get_OnSendCommandRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHClient::set_OnSendCommandRequest(TSSHCommandExecutionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHClient_set_OnSendCommandRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHClient::get_OnPasswordChangeRequest(TSSHPasswordChangeRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHClient_get_OnPasswordChangeRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHClient::set_OnPasswordChangeRequest(TSSHPasswordChangeRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHClient_set_OnPasswordChangeRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHClient::get_OnTunnelRequest(TSSHTunnelRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHClient_get_OnTunnelRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHClient::set_OnTunnelRequest(TSSHTunnelRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHClient_set_OnTunnelRequest(_Handle, pMethodValue, pDataValue));
}

void TElSSHClient::initInstances()
{
#ifdef SB_USE_CLASS_TELSSHKEY
	this->_Inst_ServerKey = NULL;
#endif /* SB_USE_CLASS_TELSSHKEY */
#ifdef SB_USE_CLASS_TELGSSBASEMECHANISM
	this->_Inst_GSSMechanism = NULL;
#endif /* SB_USE_CLASS_TELGSSBASEMECHANISM */
#ifdef SB_USE_CLASS_TELSSHTUNNELLIST
	this->_Inst_TunnelList = NULL;
#endif /* SB_USE_CLASS_TELSSHTUNNELLIST */
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
	this->_Inst_TrustedKeys = NULL;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
}

TElSSHClient::TElSSHClient(TElSSHClientHandle handle, TElOwnHandle ownHandle) : TElSSHClass(handle, ownHandle)
{
	initInstances();
}

TElSSHClient::TElSSHClient(TComponent &AOwner) : TElSSHClass(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHClient_Create(AOwner.getHandle(), &_Handle));
}

TElSSHClient::TElSSHClient(TComponent *AOwner) : TElSSHClass(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHClient_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSSHClient::~TElSSHClient()
{
#ifdef SB_USE_CLASS_TELSSHKEY
	delete this->_Inst_ServerKey;
	this->_Inst_ServerKey = NULL;
#endif /* SB_USE_CLASS_TELSSHKEY */
#ifdef SB_USE_CLASS_TELGSSBASEMECHANISM
	delete this->_Inst_GSSMechanism;
	this->_Inst_GSSMechanism = NULL;
#endif /* SB_USE_CLASS_TELGSSBASEMECHANISM */
#ifdef SB_USE_CLASS_TELSSHTUNNELLIST
	delete this->_Inst_TunnelList;
	this->_Inst_TunnelList = NULL;
#endif /* SB_USE_CLASS_TELSSHTUNNELLIST */
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
	delete this->_Inst_TrustedKeys;
	this->_Inst_TrustedKeys = NULL;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
}
#endif /* SB_USE_CLASS_TELSSHCLIENT */

#ifdef SB_USE_CLASS_TELSSHCLIENTTUNNELLIST

TElSSHClientTunnelList::TElSSHClientTunnelList(TElSSHClientTunnelListHandle handle, TElOwnHandle ownHandle) : TElSSHTunnelList(handle, ownHandle)
{
}

TElSSHClientTunnelList::TElSSHClientTunnelList(TComponent &AOwner) : TElSSHTunnelList(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHClientTunnelList_Create(AOwner.getHandle(), &_Handle));
}

TElSSHClientTunnelList::TElSSHClientTunnelList(TComponent *AOwner) : TElSSHTunnelList(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHClientTunnelList_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELSSHCLIENTTUNNELLIST */

#ifdef SB_USE_CLASS_TELSSHCLIENTTUNNELCONNECTION

SB_INLINE void TElSSHClientTunnelConnection::SendData(void * Buffer, int32_t Size)
{
	SBCheckError(TElSSHClientTunnelConnection_SendData(_Handle, Buffer, Size));
}

SB_INLINE void TElSSHClientTunnelConnection::SendExtendedData(void * Buffer, int32_t Size)
{
	SBCheckError(TElSSHClientTunnelConnection_SendExtendedData(_Handle, Buffer, Size));
}

bool TElSSHClientTunnelConnection::CanSend()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHClientTunnelConnection_CanSend(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElSSHClientTunnelConnection::get_ExtendedDataType()
{
	int32_t OutResult;
	SBCheckError(TElSSHClientTunnelConnection_get_ExtendedDataType(_Handle, &OutResult));
	return OutResult;
}

TElSSHClientTunnelConnection::TElSSHClientTunnelConnection(TElSSHClientTunnelConnectionHandle handle, TElOwnHandle ownHandle) : TElSSHTunnelConnection(handle, ownHandle)
{
}

TElSSHClientTunnelConnection::TElSSHClientTunnelConnection() : TElSSHTunnelConnection(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHClientTunnelConnection_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSSHCLIENTTUNNELCONNECTION */

};	/* namespace SecureBlackbox */

