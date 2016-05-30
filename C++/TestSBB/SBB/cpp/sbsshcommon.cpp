#include "sbsshcommon.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSSHCLASS

SB_INLINE void TElSSHClass::Close(bool Forced)
{
	SBCheckError(TElSSHClass_Close(_Handle, (int8_t)Forced));
}

SB_INLINE void TElSSHClass::RenegotiateCiphers()
{
	SBCheckError(TElSSHClass_RenegotiateCiphers(_Handle));
}

SB_INLINE void TElSSHClass::AdjustAlgorithmPriorities(TSSHStandardAlgorithmPriorityTemplate Priorities)
{
	SBCheckError(TElSSHClass_AdjustAlgorithmPriorities(_Handle, (TSSHStandardAlgorithmPriorityTemplateRaw)Priorities));
}

bool TElSSHClass::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHClass_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSSHClass::get_EncryptionAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHClass_get_EncryptionAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHClass::set_EncryptionAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElSSHClass_set_EncryptionAlgorithms(_Handle, Index, (int8_t)Value));
}

bool TElSSHClass::get_CompressionAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHClass_get_CompressionAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHClass::set_CompressionAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElSSHClass_set_CompressionAlgorithms(_Handle, Index, (int8_t)Value));
}

bool TElSSHClass::get_MacAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHClass_get_MacAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHClass::set_MacAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElSSHClass_set_MacAlgorithms(_Handle, Index, (int8_t)Value));
}

bool TElSSHClass::get_KexAlgorithms(int8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHClass_get_KexAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHClass::set_KexAlgorithms(int8_t Index, bool Value)
{
	SBCheckError(TElSSHClass_set_KexAlgorithms(_Handle, Index, (int8_t)Value));
}

bool TElSSHClass::get_PublicKeyAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHClass_get_PublicKeyAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHClass::set_PublicKeyAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElSSHClass_set_PublicKeyAlgorithms(_Handle, Index, (int8_t)Value));
}

SB_INLINE int32_t TElSSHClass::get_EncryptionAlgorithmPriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSSHClass_get_EncryptionAlgorithmPriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHClass::set_EncryptionAlgorithmPriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElSSHClass_set_EncryptionAlgorithmPriorities(_Handle, Index, Value));
}

SB_INLINE int32_t TElSSHClass::get_CompressionAlgorithmPriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSSHClass_get_CompressionAlgorithmPriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHClass::set_CompressionAlgorithmPriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElSSHClass_set_CompressionAlgorithmPriorities(_Handle, Index, Value));
}

SB_INLINE int32_t TElSSHClass::get_MacAlgorithmPriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSSHClass_get_MacAlgorithmPriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHClass::set_MacAlgorithmPriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElSSHClass_set_MacAlgorithmPriorities(_Handle, Index, Value));
}

SB_INLINE int32_t TElSSHClass::get_KexAlgorithmPriorities(int8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSSHClass_get_KexAlgorithmPriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHClass::set_KexAlgorithmPriorities(int8_t Index, int32_t Value)
{
	SBCheckError(TElSSHClass_set_KexAlgorithmPriorities(_Handle, Index, Value));
}

SB_INLINE int32_t TElSSHClass::get_PublicKeyAlgorithmPriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSSHClass_get_PublicKeyAlgorithmPriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHClass::set_PublicKeyAlgorithmPriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElSSHClass_set_PublicKeyAlgorithmPriorities(_Handle, Index, Value));
}

SB_INLINE uint8_t TElSSHClass::get_EncryptionAlgorithmServerToClient()
{
	uint8_t OutResult;
	SBCheckError(TElSSHClass_get_EncryptionAlgorithmServerToClient(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSSHClass::get_EncryptionAlgorithmClientToServer()
{
	uint8_t OutResult;
	SBCheckError(TElSSHClass_get_EncryptionAlgorithmClientToServer(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSSHClass::get_CompressionAlgorithmServerToClient()
{
	uint8_t OutResult;
	SBCheckError(TElSSHClass_get_CompressionAlgorithmServerToClient(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSSHClass::get_CompressionAlgorithmClientToServer()
{
	uint8_t OutResult;
	SBCheckError(TElSSHClass_get_CompressionAlgorithmClientToServer(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSSHClass::get_MacAlgorithmServerToClient()
{
	uint8_t OutResult;
	SBCheckError(TElSSHClass_get_MacAlgorithmServerToClient(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSSHClass::get_MacAlgorithmClientToServer()
{
	uint8_t OutResult;
	SBCheckError(TElSSHClass_get_MacAlgorithmClientToServer(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int8_t TElSSHClass::get_KexAlgorithm()
{
	int8_t OutResult;
	SBCheckError(TElSSHClass_get_KexAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSSHClass::get_PublicKeyAlgorithm()
{
	uint8_t OutResult;
	SBCheckError(TElSSHClass_get_PublicKeyAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElSSHClass::get_TotalBytesSent()
{
	int64_t OutResult;
	SBCheckError(TElSSHClass_get_TotalBytesSent(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElSSHClass::get_TotalBytesReceived()
{
	int64_t OutResult;
	SBCheckError(TElSSHClass_get_TotalBytesReceived(_Handle, &OutResult));
	return OutResult;
}

void TElSSHClass::get_SoftwareName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHClass_get_SoftwareName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1085508552, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHClass::set_SoftwareName(const std::string &Value)
{
	SBCheckError(TElSSHClass_set_SoftwareName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
TElSSHCustomKeyStorage* TElSSHClass::get_KeyStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHClass_get_KeyStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyStorage)
		this->_Inst_KeyStorage = new TElSSHCustomKeyStorage(hOutResult, ohFalse);
	else
		this->_Inst_KeyStorage->updateHandle(hOutResult);
	return this->_Inst_KeyStorage;
}

SB_INLINE void TElSSHClass::set_KeyStorage(TElSSHCustomKeyStorage &Value)
{
	SBCheckError(TElSSHClass_set_KeyStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSHClass::set_KeyStorage(TElSSHCustomKeyStorage *Value)
{
	SBCheckError(TElSSHClass_set_KeyStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

bool TElSSHClass::get_ForceCompression()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHClass_get_ForceCompression(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHClass::set_ForceCompression(bool Value)
{
	SBCheckError(TElSSHClass_set_ForceCompression(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElSSHClass::get_CompressionLevel()
{
	int32_t OutResult;
	SBCheckError(TElSSHClass_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHClass::set_CompressionLevel(int32_t Value)
{
	SBCheckError(TElSSHClass_set_CompressionLevel(_Handle, Value));
}

SB_INLINE int32_t TElSSHClass::get_AuthenticationTypes()
{
	int32_t OutResult;
	SBCheckError(TElSSHClass_get_AuthenticationTypes(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHClass::set_AuthenticationTypes(int32_t Value)
{
	SBCheckError(TElSSHClass_set_AuthenticationTypes(_Handle, Value));
}

bool TElSSHClass::get_CloseIfNoActiveTunnels()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHClass_get_CloseIfNoActiveTunnels(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHClass::set_CloseIfNoActiveTunnels(bool Value)
{
	SBCheckError(TElSSHClass_set_CloseIfNoActiveTunnels(_Handle, (int8_t)Value));
}

bool TElSSHClass::get_UseUTF8()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHClass_get_UseUTF8(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHClass::set_UseUTF8(bool Value)
{
	SBCheckError(TElSSHClass_set_UseUTF8(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElSSHClass::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHClass_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElSSHClass::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElSSHClass_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSHClass::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElSSHClass_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

bool TElSSHClass::get_NoCharacterEncoding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHClass_get_NoCharacterEncoding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHClass::set_NoCharacterEncoding(bool Value)
{
	SBCheckError(TElSSHClass_set_NoCharacterEncoding(_Handle, (int8_t)Value));
}

void TElSSHClass::get_LocalCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHClass_get_LocalCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(390671671, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHClass::set_LocalCharset(const std::string &Value)
{
	SBCheckError(TElSSHClass_set_LocalCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSSHClass::get_RemoteCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHClass_get_RemoteCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(294764874, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHClass::set_RemoteCharset(const std::string &Value)
{
	SBCheckError(TElSSHClass_set_RemoteCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSSHClass::get_ObfuscateHandshake()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHClass_get_ObfuscateHandshake(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHClass::set_ObfuscateHandshake(bool Value)
{
	SBCheckError(TElSSHClass_set_ObfuscateHandshake(_Handle, (int8_t)Value));
}

void TElSSHClass::get_ObfuscationPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHClass_get_ObfuscationPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1516084409, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHClass::set_ObfuscationPassword(const std::string &Value)
{
	SBCheckError(TElSSHClass_set_ObfuscationPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElSSHClass::get_OnSend(TSSHSendEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHClass_get_OnSend(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHClass::set_OnSend(TSSHSendEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHClass_set_OnSend(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHClass::get_OnReceive(TSSHReceiveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHClass_get_OnReceive(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHClass::set_OnReceive(TSSHReceiveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHClass_set_OnReceive(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHClass::get_OnOpenConnection(TSSHOpenConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHClass_get_OnOpenConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHClass::set_OnOpenConnection(TSSHOpenConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHClass_set_OnOpenConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHClass::get_OnCloseConnection(TSSHCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHClass_get_OnCloseConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHClass::set_OnCloseConnection(TSSHCloseConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHClass_set_OnCloseConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHClass::get_OnDebugData(TSSHDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHClass_get_OnDebugData(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHClass::set_OnDebugData(TSSHDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHClass_set_OnDebugData(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHClass::get_OnError(TSSHErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHClass_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHClass::set_OnError(TSSHErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHClass_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHClass::get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHClass_get_OnCiphersNegotiated(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHClass::set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHClass_set_OnCiphersNegotiated(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHClass::get_OnKexInitReceived(TSSHKexInitReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHClass_get_OnKexInitReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHClass::set_OnKexInitReceived(TSSHKexInitReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHClass_set_OnKexInitReceived(_Handle, pMethodValue, pDataValue));
}

void TElSSHClass::initInstances()
{
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
	this->_Inst_KeyStorage = NULL;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}

TElSSHClass::TElSSHClass(TElSSHClassHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElSSHClass::TElSSHClass(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHClass_Create(AOwner.getHandle(), &_Handle));
}

TElSSHClass::TElSSHClass(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHClass_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSSHClass::~TElSSHClass()
{
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
	delete this->_Inst_KeyStorage;
	this->_Inst_KeyStorage = NULL;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}
#endif /* SB_USE_CLASS_TELSSHCLASS */

#ifdef SB_USE_CLASS_TELSSHTUNNELLIST

#ifdef SB_USE_CLASS_TELCUSTOMSSHTUNNEL
SB_INLINE TElCustomSSHTunnelHandle TElSSHTunnelList::FindTunnel(const std::string &SubSystemType, const std::string &SubSystemName)
{
	TElCustomSSHTunnelHandle OutResult;
	SBCheckError(TElSSHTunnelList_FindTunnel(_Handle, SubSystemType.data(), (int32_t)SubSystemType.length(), SubSystemName.data(), (int32_t)SubSystemName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMSSHTUNNEL */

#ifdef SB_USE_CLASS_TELSSHCLASS
TElSSHClass* TElSSHTunnelList::get_SSHClass()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHTunnelList_get_SSHClass(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SSHClass)
		this->_Inst_SSHClass = new TElSSHClass(hOutResult, ohFalse);
	else
		this->_Inst_SSHClass->updateHandle(hOutResult);
	return this->_Inst_SSHClass;
}
#endif /* SB_USE_CLASS_TELSSHCLASS */

#ifdef SB_USE_CLASS_TELCUSTOMSSHTUNNEL
TElCustomSSHTunnel* TElSSHTunnelList::get_Tunnels(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHTunnelList_get_Tunnels(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Tunnels)
		this->_Inst_Tunnels = new TElCustomSSHTunnel(hOutResult, ohFalse);
	else
		this->_Inst_Tunnels->updateHandle(hOutResult);
	return this->_Inst_Tunnels;
}
#endif /* SB_USE_CLASS_TELCUSTOMSSHTUNNEL */

SB_INLINE int32_t TElSSHTunnelList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElSSHTunnelList_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElSSHTunnelList::initInstances()
{
#ifdef SB_USE_CLASS_TELSSHCLASS
	this->_Inst_SSHClass = NULL;
#endif /* SB_USE_CLASS_TELSSHCLASS */
#ifdef SB_USE_CLASS_TELCUSTOMSSHTUNNEL
	this->_Inst_Tunnels = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSSHTUNNEL */
}

TElSSHTunnelList::TElSSHTunnelList(TElSSHTunnelListHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElSSHTunnelList::TElSSHTunnelList(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHTunnelList_Create(AOwner.getHandle(), &_Handle));
}

TElSSHTunnelList::TElSSHTunnelList(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHTunnelList_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSSHTunnelList::~TElSSHTunnelList()
{
#ifdef SB_USE_CLASS_TELSSHCLASS
	delete this->_Inst_SSHClass;
	this->_Inst_SSHClass = NULL;
#endif /* SB_USE_CLASS_TELSSHCLASS */
#ifdef SB_USE_CLASS_TELCUSTOMSSHTUNNEL
	delete this->_Inst_Tunnels;
	this->_Inst_Tunnels = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSSHTUNNEL */
}
#endif /* SB_USE_CLASS_TELSSHTUNNELLIST */

#ifdef SB_USE_CLASS_TELCUSTOMSSHTUNNEL

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
SB_INLINE void TElCustomSSHTunnel::DoOpen(TElSSHTunnelConnection &Connection)
{
	SBCheckError(TElCustomSSHTunnel_DoOpen(_Handle, Connection.getHandle()));
}

SB_INLINE void TElCustomSSHTunnel::DoOpen(TElSSHTunnelConnection *Connection)
{
	SBCheckError(TElCustomSSHTunnel_DoOpen(_Handle, (Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
SB_INLINE void TElCustomSSHTunnel::DoClose(TElSSHTunnelConnection &Connection)
{
	SBCheckError(TElCustomSSHTunnel_DoClose(_Handle, Connection.getHandle()));
}

SB_INLINE void TElCustomSSHTunnel::DoClose(TElSSHTunnelConnection *Connection)
{
	SBCheckError(TElCustomSSHTunnel_DoClose(_Handle, (Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

SB_INLINE void TElCustomSSHTunnel::DoError(int32_t Error, void * Data)
{
	SBCheckError(TElCustomSSHTunnel_DoError(_Handle, Error, Data));
}

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
SB_INLINE void TElCustomSSHTunnel::AddConnection(TElSSHTunnelConnection &Conn)
{
	SBCheckError(TElCustomSSHTunnel_AddConnection(_Handle, Conn.getHandle()));
}

SB_INLINE void TElCustomSSHTunnel::AddConnection(TElSSHTunnelConnection *Conn)
{
	SBCheckError(TElCustomSSHTunnel_AddConnection(_Handle, (Conn != NULL) ? Conn->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
SB_INLINE void TElCustomSSHTunnel::RemoveConnection(TElSSHTunnelConnection &Conn)
{
	SBCheckError(TElCustomSSHTunnel_RemoveConnection(_Handle, Conn.getHandle()));
}

SB_INLINE void TElCustomSSHTunnel::RemoveConnection(TElSSHTunnelConnection *Conn)
{
	SBCheckError(TElCustomSSHTunnel_RemoveConnection(_Handle, (Conn != NULL) ? Conn->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

SB_INLINE void TElCustomSSHTunnel::Open(void * Data)
{
	SBCheckError(TElCustomSSHTunnel_Open(_Handle, Data));
}

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElSSHTunnelConnection* TElCustomSSHTunnel::get_Connections(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSSHTunnel_get_Connections(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Connections)
		this->_Inst_Connections = new TElSSHTunnelConnection(hOutResult, ohFalse);
	else
		this->_Inst_Connections->updateHandle(hOutResult);
	return this->_Inst_Connections;
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

SB_INLINE int32_t TElCustomSSHTunnel::get_ConnectionCount()
{
	int32_t OutResult;
	SBCheckError(TElCustomSSHTunnel_get_ConnectionCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TLIST
TList* TElCustomSSHTunnel::get_ConnectionsList()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSSHTunnel_get_ConnectionsList(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ConnectionsList)
		this->_Inst_ConnectionsList = new TList(hOutResult, ohFalse);
	else
		this->_Inst_ConnectionsList->updateHandle(hOutResult);
	return this->_Inst_ConnectionsList;
}
#endif /* SB_USE_CLASS_TLIST */

bool TElCustomSSHTunnel::get_AutoOpen()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomSSHTunnel_get_AutoOpen(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomSSHTunnel::set_AutoOpen(bool Value)
{
	SBCheckError(TElCustomSSHTunnel_set_AutoOpen(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELSSHTUNNELLIST
TElSSHTunnelList* TElCustomSSHTunnel::get_TunnelList()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSSHTunnel_get_TunnelList(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TunnelList)
		this->_Inst_TunnelList = new TElSSHTunnelList(hOutResult, ohFalse);
	else
		this->_Inst_TunnelList->updateHandle(hOutResult);
	return this->_Inst_TunnelList;
}

SB_INLINE void TElCustomSSHTunnel::set_TunnelList(TElSSHTunnelList &Value)
{
	SBCheckError(TElCustomSSHTunnel_set_TunnelList(_Handle, Value.getHandle()));
}

SB_INLINE void TElCustomSSHTunnel::set_TunnelList(TElSSHTunnelList *Value)
{
	SBCheckError(TElCustomSSHTunnel_set_TunnelList(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHTUNNELLIST */

SB_INLINE void TElCustomSSHTunnel::get_OnOpen(TTunnelEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCustomSSHTunnel_get_OnOpen(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCustomSSHTunnel::set_OnOpen(TTunnelEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCustomSSHTunnel_set_OnOpen(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCustomSSHTunnel::get_OnClose(TTunnelEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCustomSSHTunnel_get_OnClose(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCustomSSHTunnel::set_OnClose(TTunnelEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCustomSSHTunnel_set_OnClose(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCustomSSHTunnel::get_OnError(TTunnelErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCustomSSHTunnel_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCustomSSHTunnel::set_OnError(TTunnelErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCustomSSHTunnel_set_OnError(_Handle, pMethodValue, pDataValue));
}

void TElCustomSSHTunnel::initInstances()
{
#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
	this->_Inst_Connections = NULL;
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_ConnectionsList = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TELSSHTUNNELLIST
	this->_Inst_TunnelList = NULL;
#endif /* SB_USE_CLASS_TELSSHTUNNELLIST */
}

TElCustomSSHTunnel::TElCustomSSHTunnel(TElCustomSSHTunnelHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElCustomSSHTunnel::TElCustomSSHTunnel(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomSSHTunnel_Create(AOwner.getHandle(), &_Handle));
}

TElCustomSSHTunnel::TElCustomSSHTunnel(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomSSHTunnel_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElCustomSSHTunnel::~TElCustomSSHTunnel()
{
#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
	delete this->_Inst_Connections;
	this->_Inst_Connections = NULL;
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_ConnectionsList;
	this->_Inst_ConnectionsList = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TELSSHTUNNELLIST
	delete this->_Inst_TunnelList;
	this->_Inst_TunnelList = NULL;
#endif /* SB_USE_CLASS_TELSSHTUNNELLIST */
}
#endif /* SB_USE_CLASS_TELCUSTOMSSHTUNNEL */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION

SB_INLINE void TElSSHTunnelConnection::SendData(void * Buffer, int32_t Size)
{
	SBCheckError(TElSSHTunnelConnection_SendData(_Handle, Buffer, Size));
}

SB_INLINE void TElSSHTunnelConnection::SendExtendedData(void * Buffer, int32_t Size)
{
	SBCheckError(TElSSHTunnelConnection_SendExtendedData(_Handle, Buffer, Size));
}

SB_INLINE void TElSSHTunnelConnection::SendSignal(const std::vector<uint8_t> &Signal)
{
	SBCheckError(TElSSHTunnelConnection_SendSignal(_Handle, SB_STD_VECTOR_FRONT_ADR(Signal), (int32_t)Signal.size()));
}

SB_INLINE void TElSSHTunnelConnection::SendText(const std::string &S)
{
	SBCheckError(TElSSHTunnelConnection_SendText(_Handle, S.data(), (int32_t)S.length()));
}

SB_INLINE void TElSSHTunnelConnection::SendExtendedText(const std::string &S)
{
	SBCheckError(TElSSHTunnelConnection_SendExtendedText(_Handle, S.data(), (int32_t)S.length()));
}

SB_INLINE void TElSSHTunnelConnection::Close(bool FlushCachedData)
{
	SBCheckError(TElSSHTunnelConnection_Close(_Handle, (int8_t)FlushCachedData));
}

SB_INLINE void TElSSHTunnelConnection::Close(int32_t ExitStatus, bool FlushCachedData)
{
	SBCheckError(TElSSHTunnelConnection_Close_1(_Handle, ExitStatus, (int8_t)FlushCachedData));
}

SB_INLINE void TElSSHTunnelConnection::Close(const std::string &ExitSignal, const std::string &ExitMessage, bool FlushCachedData)
{
	SBCheckError(TElSSHTunnelConnection_Close_2(_Handle, ExitSignal.data(), (int32_t)ExitSignal.length(), ExitMessage.data(), (int32_t)ExitMessage.length(), (int8_t)FlushCachedData));
}

SB_INLINE void TElSSHTunnelConnection::CloseLocal(bool FlushCachedData)
{
	SBCheckError(TElSSHTunnelConnection_CloseLocal(_Handle, (int8_t)FlushCachedData));
}

bool TElSSHTunnelConnection::CanSend()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHTunnelConnection_CanSend(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELCUSTOMSSHTUNNEL
TElCustomSSHTunnel* TElSSHTunnelConnection::get_Tunnel()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHTunnelConnection_get_Tunnel(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Tunnel)
		this->_Inst_Tunnel = new TElCustomSSHTunnel(hOutResult, ohFalse);
	else
		this->_Inst_Tunnel->updateHandle(hOutResult);
	return this->_Inst_Tunnel;
}

SB_INLINE void TElSSHTunnelConnection::set_Tunnel(TElCustomSSHTunnel &Value)
{
	SBCheckError(TElSSHTunnelConnection_set_Tunnel(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSHTunnelConnection::set_Tunnel(TElCustomSSHTunnel *Value)
{
	SBCheckError(TElSSHTunnelConnection_set_Tunnel(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMSSHTUNNEL */

SB_INLINE void * TElSSHTunnelConnection::get_Data()
{
	void * OutResult;
	SBCheckError(TElSSHTunnelConnection_get_Data(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHTunnelConnection::set_Data(void * Value)
{
	SBCheckError(TElSSHTunnelConnection_set_Data(_Handle, Value));
}

bool TElSSHTunnelConnection::get_UseUTF8()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHTunnelConnection_get_UseUTF8(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHTunnelConnection::set_UseUTF8(bool Value)
{
	SBCheckError(TElSSHTunnelConnection_set_UseUTF8(_Handle, (int8_t)Value));
}

bool TElSSHTunnelConnection::get_HasUnsentData()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHTunnelConnection_get_HasUnsentData(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSSHTunnelConnection::get_EOFSent()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHTunnelConnection_get_EOFSent(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElSSHTunnelConnection::get_ExitStatus()
{
	int32_t OutResult;
	SBCheckError(TElSSHTunnelConnection_get_ExitStatus(_Handle, &OutResult));
	return OutResult;
}

void TElSSHTunnelConnection::get_ExitSignal(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHTunnelConnection_get_ExitSignal(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-232206233, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSSHTunnelConnection::get_ExitMessage(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHTunnelConnection_get_ExitMessage(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2050492895, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElSSHTunnelConnection::get_ReturnExitStatus()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHTunnelConnection_get_ReturnExitStatus(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHTunnelConnection::set_ReturnExitStatus(bool Value)
{
	SBCheckError(TElSSHTunnelConnection_set_ReturnExitStatus(_Handle, (int8_t)Value));
}

bool TElSSHTunnelConnection::get_ReturnExitSignal()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHTunnelConnection_get_ReturnExitSignal(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHTunnelConnection::set_ReturnExitSignal(bool Value)
{
	SBCheckError(TElSSHTunnelConnection_set_ReturnExitSignal(_Handle, (int8_t)Value));
}

SB_INLINE void TElSSHTunnelConnection::get_OnData(TSSHDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHTunnelConnection_get_OnData(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHTunnelConnection::set_OnData(TSSHDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHTunnelConnection_set_OnData(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHTunnelConnection::get_OnExtendedData(TSSHDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHTunnelConnection_get_OnExtendedData(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHTunnelConnection::set_OnExtendedData(TSSHDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHTunnelConnection_set_OnExtendedData(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHTunnelConnection::get_OnError(TSSHErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHTunnelConnection_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHTunnelConnection::set_OnError(TSSHErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHTunnelConnection_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHTunnelConnection::get_OnClose(TSSHChannelCloseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHTunnelConnection_get_OnClose(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHTunnelConnection::set_OnClose(TSSHChannelCloseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHTunnelConnection_set_OnClose(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHTunnelConnection::get_OnWindowChanged(TSSHWindowChangedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHTunnelConnection_get_OnWindowChanged(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHTunnelConnection::set_OnWindowChanged(TSSHWindowChangedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHTunnelConnection_set_OnWindowChanged(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHTunnelConnection::get_OnEOF(TSSHEOFEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHTunnelConnection_get_OnEOF(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHTunnelConnection::set_OnEOF(TSSHEOFEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHTunnelConnection_set_OnEOF(_Handle, pMethodValue, pDataValue));
}

void TElSSHTunnelConnection::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMSSHTUNNEL
	this->_Inst_Tunnel = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSSHTUNNEL */
}

TElSSHTunnelConnection::TElSSHTunnelConnection(TElSSHTunnelConnectionHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElSSHTunnelConnection::TElSSHTunnelConnection() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHTunnelConnection_Create(&_Handle));
}

TElSSHTunnelConnection::~TElSSHTunnelConnection()
{
#ifdef SB_USE_CLASS_TELCUSTOMSSHTUNNEL
	delete this->_Inst_Tunnel;
	this->_Inst_Tunnel = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSSHTUNNEL */
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELCUSTOMSSHTUNNELPARAMS

TElCustomSSHTunnelParams::TElCustomSSHTunnelParams(TElCustomSSHTunnelParamsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElCustomSSHTunnelParams::TElCustomSSHTunnelParams() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomSSHTunnelParams_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCUSTOMSSHTUNNELPARAMS */

#ifdef SB_USE_CLASS_TELSHELLSSHTUNNEL

#ifdef SB_USE_CLASS_TELTERMINALINFO
TElTerminalInfo* TElShellSSHTunnel::get_TerminalInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElShellSSHTunnel_get_TerminalInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TerminalInfo)
		this->_Inst_TerminalInfo = new TElTerminalInfo(hOutResult, ohFalse);
	else
		this->_Inst_TerminalInfo->updateHandle(hOutResult);
	return this->_Inst_TerminalInfo;
}

SB_INLINE void TElShellSSHTunnel::set_TerminalInfo(TElTerminalInfo &Value)
{
	SBCheckError(TElShellSSHTunnel_set_TerminalInfo(_Handle, Value.getHandle()));
}

SB_INLINE void TElShellSSHTunnel::set_TerminalInfo(TElTerminalInfo *Value)
{
	SBCheckError(TElShellSSHTunnel_set_TerminalInfo(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELTERMINALINFO */

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElShellSSHTunnel::get_Environment()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElShellSSHTunnel_get_Environment(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Environment)
		this->_Inst_Environment = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Environment->updateHandle(hOutResult);
	return this->_Inst_Environment;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

bool TElShellSSHTunnel::get_RequestTerminal()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElShellSSHTunnel_get_RequestTerminal(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElShellSSHTunnel::set_RequestTerminal(bool Value)
{
	SBCheckError(TElShellSSHTunnel_set_RequestTerminal(_Handle, (int8_t)Value));
}

void TElShellSSHTunnel::initInstances()
{
#ifdef SB_USE_CLASS_TELTERMINALINFO
	this->_Inst_TerminalInfo = NULL;
#endif /* SB_USE_CLASS_TELTERMINALINFO */
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Environment = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}

TElShellSSHTunnel::TElShellSSHTunnel(TElShellSSHTunnelHandle handle, TElOwnHandle ownHandle) : TElCustomSSHTunnel(handle, ownHandle)
{
	initInstances();
}

TElShellSSHTunnel::TElShellSSHTunnel(TComponent &AOwner) : TElCustomSSHTunnel(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElShellSSHTunnel_Create(AOwner.getHandle(), &_Handle));
}

TElShellSSHTunnel::TElShellSSHTunnel(TComponent *AOwner) : TElCustomSSHTunnel(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElShellSSHTunnel_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElShellSSHTunnel::~TElShellSSHTunnel()
{
#ifdef SB_USE_CLASS_TELTERMINALINFO
	delete this->_Inst_TerminalInfo;
	this->_Inst_TerminalInfo = NULL;
#endif /* SB_USE_CLASS_TELTERMINALINFO */
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Environment;
	this->_Inst_Environment = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}
#endif /* SB_USE_CLASS_TELSHELLSSHTUNNEL */

#ifdef SB_USE_CLASS_TELCOMMANDSSHTUNNEL

void TElCommandSSHTunnel::get_Command(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCommandSSHTunnel_get_Command(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(494640216, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCommandSSHTunnel::set_Command(const std::string &Value)
{
	SBCheckError(TElCommandSSHTunnel_set_Command(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElCommandSSHTunnel::get_Commands()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCommandSSHTunnel_get_Commands(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Commands)
		this->_Inst_Commands = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Commands->updateHandle(hOutResult);
	return this->_Inst_Commands;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElCommandSSHTunnel::get_Commands()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCommandSSHTunnel_get_Commands(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Commands)
		this->_Inst_Commands = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Commands->updateHandle(hOutResult);
	return this->_Inst_Commands;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

SB_INLINE int32_t TElCommandSSHTunnel::get_ActiveCommand()
{
	int32_t OutResult;
	SBCheckError(TElCommandSSHTunnel_get_ActiveCommand(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCommandSSHTunnel::set_ActiveCommand(int32_t Value)
{
	SBCheckError(TElCommandSSHTunnel_set_ActiveCommand(_Handle, Value));
}

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElCommandSSHTunnel::get_Environment()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCommandSSHTunnel_get_Environment(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Environment)
		this->_Inst_Environment = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Environment->updateHandle(hOutResult);
	return this->_Inst_Environment;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TELTERMINALINFO
TElTerminalInfo* TElCommandSSHTunnel::get_TerminalInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCommandSSHTunnel_get_TerminalInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TerminalInfo)
		this->_Inst_TerminalInfo = new TElTerminalInfo(hOutResult, ohFalse);
	else
		this->_Inst_TerminalInfo->updateHandle(hOutResult);
	return this->_Inst_TerminalInfo;
}

SB_INLINE void TElCommandSSHTunnel::set_TerminalInfo(TElTerminalInfo &Value)
{
	SBCheckError(TElCommandSSHTunnel_set_TerminalInfo(_Handle, Value.getHandle()));
}

SB_INLINE void TElCommandSSHTunnel::set_TerminalInfo(TElTerminalInfo *Value)
{
	SBCheckError(TElCommandSSHTunnel_set_TerminalInfo(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELTERMINALINFO */

bool TElCommandSSHTunnel::get_RequestTerminal()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCommandSSHTunnel_get_RequestTerminal(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCommandSSHTunnel::set_RequestTerminal(bool Value)
{
	SBCheckError(TElCommandSSHTunnel_set_RequestTerminal(_Handle, (int8_t)Value));
}

void TElCommandSSHTunnel::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Commands = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Commands = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Environment = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELTERMINALINFO
	this->_Inst_TerminalInfo = NULL;
#endif /* SB_USE_CLASS_TELTERMINALINFO */
}

TElCommandSSHTunnel::TElCommandSSHTunnel(TElCommandSSHTunnelHandle handle, TElOwnHandle ownHandle) : TElCustomSSHTunnel(handle, ownHandle)
{
	initInstances();
}

TElCommandSSHTunnel::TElCommandSSHTunnel(TComponent &AOwner) : TElCustomSSHTunnel(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCommandSSHTunnel_Create(AOwner.getHandle(), &_Handle));
}

TElCommandSSHTunnel::TElCommandSSHTunnel(TComponent *AOwner) : TElCustomSSHTunnel(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCommandSSHTunnel_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElCommandSSHTunnel::~TElCommandSSHTunnel()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Commands;
	this->_Inst_Commands = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Commands;
	this->_Inst_Commands = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Environment;
	this->_Inst_Environment = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELTERMINALINFO
	delete this->_Inst_TerminalInfo;
	this->_Inst_TerminalInfo = NULL;
#endif /* SB_USE_CLASS_TELTERMINALINFO */
}
#endif /* SB_USE_CLASS_TELCOMMANDSSHTUNNEL */

#ifdef SB_USE_CLASS_TELSUBSYSTEMSSHTUNNEL

void TElSubsystemSSHTunnel::get_Subsystem(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSubsystemSSHTunnel_get_Subsystem(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2011083617, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSubsystemSSHTunnel::set_Subsystem(const std::string &Value)
{
	SBCheckError(TElSubsystemSSHTunnel_set_Subsystem(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSubsystemSSHTunnel::get_Environment()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSubsystemSSHTunnel_get_Environment(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Environment)
		this->_Inst_Environment = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Environment->updateHandle(hOutResult);
	return this->_Inst_Environment;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

void TElSubsystemSSHTunnel::initInstances()
{
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Environment = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}

TElSubsystemSSHTunnel::TElSubsystemSSHTunnel(TElSubsystemSSHTunnelHandle handle, TElOwnHandle ownHandle) : TElCustomSSHTunnel(handle, ownHandle)
{
	initInstances();
}

TElSubsystemSSHTunnel::TElSubsystemSSHTunnel(TComponent &AOwner) : TElCustomSSHTunnel(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSubsystemSSHTunnel_Create(AOwner.getHandle(), &_Handle));
}

TElSubsystemSSHTunnel::TElSubsystemSSHTunnel(TComponent *AOwner) : TElCustomSSHTunnel(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSubsystemSSHTunnel_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSubsystemSSHTunnel::~TElSubsystemSSHTunnel()
{
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Environment;
	this->_Inst_Environment = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}
#endif /* SB_USE_CLASS_TELSUBSYSTEMSSHTUNNEL */

#ifdef SB_USE_CLASS_TELREMOTEPORTFORWARDSSHTUNNEL

SB_INLINE void TElRemotePortForwardSSHTunnel::DoSetupSucceeded()
{
	SBCheckError(TElRemotePortForwardSSHTunnel_DoSetupSucceeded(_Handle));
}

SB_INLINE void TElRemotePortForwardSSHTunnel::DoSetupFailed()
{
	SBCheckError(TElRemotePortForwardSSHTunnel_DoSetupFailed(_Handle));
}

void TElRemotePortForwardSSHTunnel::GetToHost(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElRemotePortForwardSSHTunnel_GetToHost(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(87236945, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElRemotePortForwardSSHTunnel::SetToHost(const std::string &AValue)
{
	SBCheckError(TElRemotePortForwardSSHTunnel_SetToHost(_Handle, AValue.data(), (int32_t)AValue.length()));
}

SB_INLINE void TElRemotePortForwardSSHTunnel::Close()
{
	SBCheckError(TElRemotePortForwardSSHTunnel_Close(_Handle));
}

void TElRemotePortForwardSSHTunnel::get_Host(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElRemotePortForwardSSHTunnel_get_Host(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(47362800, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElRemotePortForwardSSHTunnel::set_Host(const std::string &Value)
{
	SBCheckError(TElRemotePortForwardSSHTunnel_set_Host(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElRemotePortForwardSSHTunnel::get_Port()
{
	int32_t OutResult;
	SBCheckError(TElRemotePortForwardSSHTunnel_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRemotePortForwardSSHTunnel::set_Port(int32_t Value)
{
	SBCheckError(TElRemotePortForwardSSHTunnel_set_Port(_Handle, Value));
}

void TElRemotePortForwardSSHTunnel::get_ToHost(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElRemotePortForwardSSHTunnel_get_ToHost(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(568614670, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElRemotePortForwardSSHTunnel::set_ToHost(const std::string &Value)
{
	SBCheckError(TElRemotePortForwardSSHTunnel_set_ToHost(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElRemotePortForwardSSHTunnel::get_ToPort()
{
	int32_t OutResult;
	SBCheckError(TElRemotePortForwardSSHTunnel_get_ToPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRemotePortForwardSSHTunnel::set_ToPort(int32_t Value)
{
	SBCheckError(TElRemotePortForwardSSHTunnel_set_ToPort(_Handle, Value));
}

SB_INLINE int32_t TElRemotePortForwardSSHTunnel::get_BoundPort()
{
	int32_t OutResult;
	SBCheckError(TElRemotePortForwardSSHTunnel_get_BoundPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRemotePortForwardSSHTunnel::set_BoundPort(int32_t Value)
{
	SBCheckError(TElRemotePortForwardSSHTunnel_set_BoundPort(_Handle, Value));
}

bool TElRemotePortForwardSSHTunnel::get_UseDefaultBindAddress()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRemotePortForwardSSHTunnel_get_UseDefaultBindAddress(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElRemotePortForwardSSHTunnel::set_UseDefaultBindAddress(bool Value)
{
	SBCheckError(TElRemotePortForwardSSHTunnel_set_UseDefaultBindAddress(_Handle, (int8_t)Value));
}

SB_INLINE void TElRemotePortForwardSSHTunnel::get_OnSetupSucceeded(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElRemotePortForwardSSHTunnel_get_OnSetupSucceeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElRemotePortForwardSSHTunnel::set_OnSetupSucceeded(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElRemotePortForwardSSHTunnel_set_OnSetupSucceeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElRemotePortForwardSSHTunnel::get_OnSetupFailed(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElRemotePortForwardSSHTunnel_get_OnSetupFailed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElRemotePortForwardSSHTunnel::set_OnSetupFailed(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElRemotePortForwardSSHTunnel_set_OnSetupFailed(_Handle, pMethodValue, pDataValue));
}

TElRemotePortForwardSSHTunnel::TElRemotePortForwardSSHTunnel(TElRemotePortForwardSSHTunnelHandle handle, TElOwnHandle ownHandle) : TElCustomSSHTunnel(handle, ownHandle)
{
}

TElRemotePortForwardSSHTunnel::TElRemotePortForwardSSHTunnel(TComponent &AOwner) : TElCustomSSHTunnel(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRemotePortForwardSSHTunnel_Create(AOwner.getHandle(), &_Handle));
}

TElRemotePortForwardSSHTunnel::TElRemotePortForwardSSHTunnel(TComponent *AOwner) : TElCustomSSHTunnel(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRemotePortForwardSSHTunnel_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELREMOTEPORTFORWARDSSHTUNNEL */

#ifdef SB_USE_CLASS_TELLOCALPORTFORWARDSSHTUNNEL

void TElLocalPortForwardSSHTunnel::GetToHost(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLocalPortForwardSSHTunnel_GetToHost(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(741246062, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElLocalPortForwardSSHTunnel::SetToHost(const std::string &AValue)
{
	SBCheckError(TElLocalPortForwardSSHTunnel_SetToHost(_Handle, AValue.data(), (int32_t)AValue.length()));
}

SB_INLINE void TElLocalPortForwardSSHTunnel::Open(void * Data, const std::string &OrigHost, int32_t OrigPort)
{
	SBCheckError(TElLocalPortForwardSSHTunnel_Open(_Handle, Data, OrigHost.data(), (int32_t)OrigHost.length(), OrigPort));
}

SB_INLINE int32_t TElLocalPortForwardSSHTunnel::get_Port()
{
	int32_t OutResult;
	SBCheckError(TElLocalPortForwardSSHTunnel_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElLocalPortForwardSSHTunnel::set_Port(int32_t Value)
{
	SBCheckError(TElLocalPortForwardSSHTunnel_set_Port(_Handle, Value));
}

void TElLocalPortForwardSSHTunnel::get_Host(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLocalPortForwardSSHTunnel_get_Host(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-871504342, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElLocalPortForwardSSHTunnel::set_Host(const std::string &Value)
{
	SBCheckError(TElLocalPortForwardSSHTunnel_set_Host(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElLocalPortForwardSSHTunnel::get_ToHost(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLocalPortForwardSSHTunnel_get_ToHost(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(909453737, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElLocalPortForwardSSHTunnel::set_ToHost(const std::string &Value)
{
	SBCheckError(TElLocalPortForwardSSHTunnel_set_ToHost(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElLocalPortForwardSSHTunnel::get_ToPort()
{
	int32_t OutResult;
	SBCheckError(TElLocalPortForwardSSHTunnel_get_ToPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElLocalPortForwardSSHTunnel::set_ToPort(int32_t Value)
{
	SBCheckError(TElLocalPortForwardSSHTunnel_set_ToPort(_Handle, Value));
}

TElLocalPortForwardSSHTunnel::TElLocalPortForwardSSHTunnel(TElLocalPortForwardSSHTunnelHandle handle, TElOwnHandle ownHandle) : TElCustomSSHTunnel(handle, ownHandle)
{
}

TElLocalPortForwardSSHTunnel::TElLocalPortForwardSSHTunnel(TComponent &AOwner) : TElCustomSSHTunnel(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLocalPortForwardSSHTunnel_Create(AOwner.getHandle(), &_Handle));
}

TElLocalPortForwardSSHTunnel::TElLocalPortForwardSSHTunnel(TComponent *AOwner) : TElCustomSSHTunnel(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLocalPortForwardSSHTunnel_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELLOCALPORTFORWARDSSHTUNNEL */

#ifdef SB_USE_CLASS_TELLOCALPORTFORWARDSSHTUNNELPARAMS

void TElLocalPortForwardSSHTunnelParams::get_OrigHost(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLocalPortForwardSSHTunnelParams_get_OrigHost(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-611303324, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElLocalPortForwardSSHTunnelParams::get_OrigPort()
{
	int32_t OutResult;
	SBCheckError(TElLocalPortForwardSSHTunnelParams_get_OrigPort(_Handle, &OutResult));
	return OutResult;
}

TElLocalPortForwardSSHTunnelParams::TElLocalPortForwardSSHTunnelParams(TElLocalPortForwardSSHTunnelParamsHandle handle, TElOwnHandle ownHandle) : TElCustomSSHTunnelParams(handle, ownHandle)
{
}

TElLocalPortForwardSSHTunnelParams::TElLocalPortForwardSSHTunnelParams(const std::string &OrigHost, int32_t OrigPort) : TElCustomSSHTunnelParams(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLocalPortForwardSSHTunnelParams_Create(OrigHost.data(), (int32_t)OrigHost.length(), OrigPort, &_Handle));
}

#endif /* SB_USE_CLASS_TELLOCALPORTFORWARDSSHTUNNELPARAMS */

#ifdef SB_USE_CLASS_TELX11FORWARDSSHTUNNEL

void TElX11ForwardSSHTunnel::get_AuthenticationProtocol(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElX11ForwardSSHTunnel_get_AuthenticationProtocol(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1593463661, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElX11ForwardSSHTunnel::set_AuthenticationProtocol(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElX11ForwardSSHTunnel_set_AuthenticationProtocol(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElX11ForwardSSHTunnel::get_ScreenNumber()
{
	int32_t OutResult;
	SBCheckError(TElX11ForwardSSHTunnel_get_ScreenNumber(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElX11ForwardSSHTunnel::set_ScreenNumber(int32_t Value)
{
	SBCheckError(TElX11ForwardSSHTunnel_set_ScreenNumber(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELTERMINALINFO
TElTerminalInfo* TElX11ForwardSSHTunnel::get_TerminalInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX11ForwardSSHTunnel_get_TerminalInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TerminalInfo)
		this->_Inst_TerminalInfo = new TElTerminalInfo(hOutResult, ohFalse);
	else
		this->_Inst_TerminalInfo->updateHandle(hOutResult);
	return this->_Inst_TerminalInfo;
}

SB_INLINE void TElX11ForwardSSHTunnel::set_TerminalInfo(TElTerminalInfo &Value)
{
	SBCheckError(TElX11ForwardSSHTunnel_set_TerminalInfo(_Handle, Value.getHandle()));
}

SB_INLINE void TElX11ForwardSSHTunnel::set_TerminalInfo(TElTerminalInfo *Value)
{
	SBCheckError(TElX11ForwardSSHTunnel_set_TerminalInfo(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELTERMINALINFO */

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElX11ForwardSSHTunnel::get_Environment()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX11ForwardSSHTunnel_get_Environment(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Environment)
		this->_Inst_Environment = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Environment->updateHandle(hOutResult);
	return this->_Inst_Environment;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

bool TElX11ForwardSSHTunnel::get_RequestTerminal()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX11ForwardSSHTunnel_get_RequestTerminal(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX11ForwardSSHTunnel::set_RequestTerminal(bool Value)
{
	SBCheckError(TElX11ForwardSSHTunnel_set_RequestTerminal(_Handle, (int8_t)Value));
}

TElCustomSSHTunnel* TElX11ForwardSSHTunnel::get_Target()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX11ForwardSSHTunnel_get_Target(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Target)
		this->_Inst_Target = new TElCustomSSHTunnel(hOutResult, ohFalse);
	else
		this->_Inst_Target->updateHandle(hOutResult);
	return this->_Inst_Target;
}

SB_INLINE void TElX11ForwardSSHTunnel::set_Target(TElCustomSSHTunnel &Value)
{
	SBCheckError(TElX11ForwardSSHTunnel_set_Target(_Handle, Value.getHandle()));
}

SB_INLINE void TElX11ForwardSSHTunnel::set_Target(TElCustomSSHTunnel *Value)
{
	SBCheckError(TElX11ForwardSSHTunnel_set_Target(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

void TElX11ForwardSSHTunnel::initInstances()
{
#ifdef SB_USE_CLASS_TELTERMINALINFO
	this->_Inst_TerminalInfo = NULL;
#endif /* SB_USE_CLASS_TELTERMINALINFO */
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Environment = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
	this->_Inst_Target = NULL;
}

TElX11ForwardSSHTunnel::TElX11ForwardSSHTunnel(TElX11ForwardSSHTunnelHandle handle, TElOwnHandle ownHandle) : TElCustomSSHTunnel(handle, ownHandle)
{
	initInstances();
}

TElX11ForwardSSHTunnel::TElX11ForwardSSHTunnel(TComponent &AOwner) : TElCustomSSHTunnel(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElX11ForwardSSHTunnel_Create(AOwner.getHandle(), &_Handle));
}

TElX11ForwardSSHTunnel::TElX11ForwardSSHTunnel(TComponent *AOwner) : TElCustomSSHTunnel(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElX11ForwardSSHTunnel_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElX11ForwardSSHTunnel::~TElX11ForwardSSHTunnel()
{
#ifdef SB_USE_CLASS_TELTERMINALINFO
	delete this->_Inst_TerminalInfo;
	this->_Inst_TerminalInfo = NULL;
#endif /* SB_USE_CLASS_TELTERMINALINFO */
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Environment;
	this->_Inst_Environment = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
	delete this->_Inst_Target;
	this->_Inst_Target = NULL;
}
#endif /* SB_USE_CLASS_TELX11FORWARDSSHTUNNEL */

#ifdef SB_USE_CLASS_TELAUTHENTICATIONAGENTSSHTUNNEL

TElAuthenticationAgentSSHTunnel::TElAuthenticationAgentSSHTunnel(TElAuthenticationAgentSSHTunnelHandle handle, TElOwnHandle ownHandle) : TElCustomSSHTunnel(handle, ownHandle)
{
}

TElAuthenticationAgentSSHTunnel::TElAuthenticationAgentSSHTunnel(TComponent &AOwner) : TElCustomSSHTunnel(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAuthenticationAgentSSHTunnel_Create(AOwner.getHandle(), &_Handle));
}

TElAuthenticationAgentSSHTunnel::TElAuthenticationAgentSSHTunnel(TComponent *AOwner) : TElCustomSSHTunnel(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAuthenticationAgentSSHTunnel_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELAUTHENTICATIONAGENTSSHTUNNEL */

#ifdef SB_USE_CLASS_TELSSHAUTHHANDLER

SB_INLINE int32_t TElSSHAuthHandler::GetAlgorithmFromClientKexDHReply(const std::vector<uint8_t> &HostAlg)
{
	int32_t OutResult;
	SBCheckError(TElSSHAuthHandler_GetAlgorithmFromClientKexDHReply(_Handle, SB_STD_VECTOR_FRONT_ADR(HostAlg), (int32_t)HostAlg.size(), &OutResult));
	return OutResult;
}

bool TElSSHAuthHandler::ValidateServerSignature(int32_t Algorithm, const std::vector<uint8_t> &PubKeyStr, const std::vector<uint8_t> &Signature, const std::vector<uint8_t> &Hash, int32_t HashAlg, int32_t &ErrCode, std::string &ErrMessage)
{
	int32_t szErrMessage = (int32_t)ErrMessage.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElSSHAuthHandler_ValidateServerSignature(_Handle, Algorithm, SB_STD_VECTOR_FRONT_ADR(PubKeyStr), (int32_t)PubKeyStr.size(), SB_STD_VECTOR_FRONT_ADR(Signature), (int32_t)Signature.size(), SB_STD_VECTOR_FRONT_ADR(Hash), (int32_t)Hash.size(), HashAlg, &ErrCode, (char *)ErrMessage.data(), &szErrMessage, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ErrMessage.resize(szErrMessage);
		SBCheckError(SBGetLastReturnStringA(2114041456, 7, (char *)ErrMessage.data(), &szErrMessage));
	}
	else
		SBCheckError(_err);

	ErrMessage.resize(szErrMessage);
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
SB_INLINE int32_t TElSSHAuthHandler::FindKeyByAlgorithm(TElSSHCustomKeyStorage &Storage, int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(TElSSHAuthHandler_FindKeyByAlgorithm(_Handle, Storage.getHandle(), Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHAuthHandler::FindKeyByAlgorithm(TElSSHCustomKeyStorage *Storage, int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(TElSSHAuthHandler_FindKeyByAlgorithm(_Handle, (Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, Algorithm, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

#ifdef SB_USE_CLASS_TELSSHKEY
void TElSSHAuthHandler::GetKeyBlob(TElSSHKey &Key, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSHAuthHandler_GetKeyBlob(_Handle, Key.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-925816539, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSSHAuthHandler::GetKeyBlob(TElSSHKey *Key, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSHAuthHandler_GetKeyBlob(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-925816539, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELSSHKEY
SB_INLINE TElSSHKeyHandle TElSSHAuthHandler::KeyBlobToKey(const std::string &AlgName, const std::vector<uint8_t> &Blob)
{
	TElSSHKeyHandle OutResult;
	SBCheckError(TElSSHAuthHandler_KeyBlobToKey(_Handle, AlgName.data(), (int32_t)AlgName.length(), SB_STD_VECTOR_FRONT_ADR(Blob), (int32_t)Blob.size(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELSSHKEY
SB_INLINE int32_t TElSSHAuthHandler::HashAlgFromKey(TElSSHKey &Key)
{
	int32_t OutResult;
	SBCheckError(TElSSHAuthHandler_HashAlgFromKey(_Handle, Key.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHAuthHandler::HashAlgFromKey(TElSSHKey *Key)
{
	int32_t OutResult;
	SBCheckError(TElSSHAuthHandler_HashAlgFromKey(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELSSHKEY
void TElSSHAuthHandler::CalculateServerSignature(TElSSHKey &Key, const std::vector<uint8_t> &aHash, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSHAuthHandler_CalculateServerSignature(_Handle, Key.getHandle(), SB_STD_VECTOR_FRONT_ADR(aHash), (int32_t)aHash.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1969632151, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSSHAuthHandler::CalculateServerSignature(TElSSHKey *Key, const std::vector<uint8_t> &aHash, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSHAuthHandler_CalculateServerSignature(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(aHash), (int32_t)aHash.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1969632151, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELSSHKEY */

bool TElSSHAuthHandler::ServerValidateClientSignature(const std::vector<uint8_t> &AlgName, const std::vector<uint8_t> &KeyBlob, const std::vector<uint8_t> &Signature, const std::vector<uint8_t> &Hash, bool &Valid)
{
	int8_t ValidRaw = (int8_t)Valid;
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHAuthHandler_ServerValidateClientSignature(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgName), (int32_t)AlgName.size(), SB_STD_VECTOR_FRONT_ADR(KeyBlob), (int32_t)KeyBlob.size(), SB_STD_VECTOR_FRONT_ADR(Signature), (int32_t)Signature.size(), SB_STD_VECTOR_FRONT_ADR(Hash), (int32_t)Hash.size(), &ValidRaw, &OutResultRaw));
	Valid = (ValidRaw != 0);
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_IELSSHAUTHHANDLERCONTAINER
SB_INLINE IElSSHAuthHandlerContainerHandle TElSSHAuthHandler::get_SSHClass()
{
	IElSSHAuthHandlerContainerHandle OutResult;
	SBCheckError(TElSSHAuthHandler_get_SSHClass(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHAuthHandler::set_SSHClass(IElSSHAuthHandlerContainerHandle Value)
{
	SBCheckError(TElSSHAuthHandler_set_SSHClass(_Handle, Value));
}
#endif /* SB_USE_CLASS_IELSSHAUTHHANDLERCONTAINER */

TElSSHAuthHandler::TElSSHAuthHandler(TElSSHAuthHandlerHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElSSHAuthHandler::TElSSHAuthHandler(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHAuthHandler_Create(AOwner.getHandle(), &_Handle));
}

TElSSHAuthHandler::TElSSHAuthHandler(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHAuthHandler_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELSSHAUTHHANDLER */

#ifdef SB_USE_GLOBAL_PROCS_SSHCOMMON

#ifdef SB_USE_CLASS_TPLCONVERTER
void SSHEncodeString(const std::string &S, bool UseUTF8, bool NoTranslation, TPlConverter &Converter, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBSSHCommon_SSHEncodeString(S.data(), (int32_t)S.length(), (int8_t)UseUTF8, (int8_t)NoTranslation, Converter.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(856102630, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void SSHEncodeString(const std::string &S, bool UseUTF8, bool NoTranslation, TPlConverter *Converter, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBSSHCommon_SSHEncodeString(S.data(), (int32_t)S.length(), (int8_t)UseUTF8, (int8_t)NoTranslation, (Converter != NULL) ? Converter->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(856102630, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TPLCONVERTER */

#ifdef SB_USE_CLASS_TPLCONVERTER
void SSHDecodeString(const std::vector<uint8_t> &Buf, bool UseUTF8, bool NoTranslation, TPlConverter &Converter, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBSSHCommon_SSHDecodeString(SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size(), (int8_t)UseUTF8, (int8_t)NoTranslation, Converter.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(686350521, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void SSHDecodeString(const std::vector<uint8_t> &Buf, bool UseUTF8, bool NoTranslation, TPlConverter *Converter, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBSSHCommon_SSHDecodeString(SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size(), (int8_t)UseUTF8, (int8_t)NoTranslation, (Converter != NULL) ? Converter->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(686350521, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TPLCONVERTER */

#endif /* SB_USE_GLOBAL_PROCS_SSHCOMMON */

};	/* namespace SecureBlackbox */
