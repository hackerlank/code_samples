#include "sbsshpkcs11keystorage.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSSHPKCS11KEYSTORAGE

SB_INLINE void TElSSHPKCS11KeyStorage::Open()
{
	SBCheckError(TElSSHPKCS11KeyStorage_Open(_Handle));
}

SB_INLINE void TElSSHPKCS11KeyStorage::Close()
{
	SBCheckError(TElSSHPKCS11KeyStorage_Close(_Handle));
}

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
SB_INLINE TElPKCS11SessionInfoHandle TElSSHPKCS11KeyStorage::OpenSession(int32_t SlotIndex, bool ReadOnly)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElSSHPKCS11KeyStorage_OpenSession(_Handle, SlotIndex, (int8_t)ReadOnly, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

SB_INLINE void TElSSHPKCS11KeyStorage::CloseSession(int32_t SessionIndex)
{
	SBCheckError(TElSSHPKCS11KeyStorage_CloseSession(_Handle, SessionIndex));
}

#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
SB_INLINE void TElSSHPKCS11KeyStorage::CloseAllSessions(TElPKCS11SlotInfo &Slot)
{
	SBCheckError(TElSSHPKCS11KeyStorage_CloseAllSessions(_Handle, Slot.getHandle()));
}

SB_INLINE void TElSSHPKCS11KeyStorage::CloseAllSessions(TElPKCS11SlotInfo *Slot)
{
	SBCheckError(TElSSHPKCS11KeyStorage_CloseAllSessions(_Handle, (Slot != NULL) ? Slot->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */

#ifdef SB_USE_CLASS_TELSSHKEY
SB_INLINE void TElSSHPKCS11KeyStorage::Add(TElSSHKey &Key)
{
	SBCheckError(TElSSHPKCS11KeyStorage_Add(_Handle, Key.getHandle()));
}

SB_INLINE void TElSSHPKCS11KeyStorage::Add(TElSSHKey *Key)
{
	SBCheckError(TElSSHPKCS11KeyStorage_Add(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELSSHKEY
SB_INLINE void TElSSHPKCS11KeyStorage::Add(int32_t SessionIndex, TElSSHKey &Key, bool CopyPrivateKey, bool Exportable, const std::vector<uint8_t> &ID, const std::vector<uint8_t> &KeyLabel)
{
	SBCheckError(TElSSHPKCS11KeyStorage_Add_1(_Handle, SessionIndex, Key.getHandle(), (int8_t)CopyPrivateKey, (int8_t)Exportable, SB_STD_VECTOR_FRONT_ADR(ID), (int32_t)ID.size(), SB_STD_VECTOR_FRONT_ADR(KeyLabel), (int32_t)KeyLabel.size()));
}

SB_INLINE void TElSSHPKCS11KeyStorage::Add(int32_t SessionIndex, TElSSHKey *Key, bool CopyPrivateKey, bool Exportable, const std::vector<uint8_t> &ID, const std::vector<uint8_t> &KeyLabel)
{
	SBCheckError(TElSSHPKCS11KeyStorage_Add_1(_Handle, SessionIndex, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (int8_t)CopyPrivateKey, (int8_t)Exportable, SB_STD_VECTOR_FRONT_ADR(ID), (int32_t)ID.size(), SB_STD_VECTOR_FRONT_ADR(KeyLabel), (int32_t)KeyLabel.size()));
}
#endif /* SB_USE_CLASS_TELSSHKEY */

SB_INLINE void TElSSHPKCS11KeyStorage::Remove(int32_t Index)
{
	SBCheckError(TElSSHPKCS11KeyStorage_Remove(_Handle, Index));
}

SB_INLINE void TElSSHPKCS11KeyStorage::Clear()
{
	SBCheckError(TElSSHPKCS11KeyStorage_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELSSHKEY
SB_INLINE int32_t TElSSHPKCS11KeyStorage::IndexOf(TElSSHKey &Key)
{
	int32_t OutResult;
	SBCheckError(TElSSHPKCS11KeyStorage_IndexOf(_Handle, Key.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHPKCS11KeyStorage::IndexOf(TElSSHKey *Key)
{
	int32_t OutResult;
	SBCheckError(TElSSHPKCS11KeyStorage_IndexOf(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElSSHPKCS11KeyStorage::LoadPublic(TStream &F, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElSSHPKCS11KeyStorage_LoadPublic(_Handle, F.getHandle(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHPKCS11KeyStorage::LoadPublic(TStream *F, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElSSHPKCS11KeyStorage_LoadPublic(_Handle, (F != NULL) ? F->getHandle() : SB_NULL_HANDLE, Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElSSHPKCS11KeyStorage::LoadPublic(const std::string &Filename)
{
	int32_t OutResult;
	SBCheckError(TElSSHPKCS11KeyStorage_LoadPublic_1(_Handle, Filename.data(), (int32_t)Filename.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElSSHPKCS11KeyStorage::SavePublic(TStream &F)
{
	int32_t OutResult;
	SBCheckError(TElSSHPKCS11KeyStorage_SavePublic(_Handle, F.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHPKCS11KeyStorage::SavePublic(TStream *F)
{
	int32_t OutResult;
	SBCheckError(TElSSHPKCS11KeyStorage_SavePublic(_Handle, (F != NULL) ? F->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElSSHPKCS11KeyStorage::SavePublic(const std::string &Filename)
{
	int32_t OutResult;
	SBCheckError(TElSSHPKCS11KeyStorage_SavePublic_1(_Handle, Filename.data(), (int32_t)Filename.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPKCS11MODULE
TElPKCS11Module* TElSSHPKCS11KeyStorage::get_Module()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHPKCS11KeyStorage_get_Module(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Module)
		this->_Inst_Module = new TElPKCS11Module(hOutResult, ohFalse);
	else
		this->_Inst_Module->updateHandle(hOutResult);
	return this->_Inst_Module;
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

bool TElSSHPKCS11KeyStorage::get_Opened()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHPKCS11KeyStorage_get_Opened(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElSSHPKCS11KeyStorage::get_UniqueID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSHPKCS11KeyStorage_get_UniqueID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-220529685, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifndef SB_IOS
void TElSSHPKCS11KeyStorage::get_DLLName(std::string &OutResult)
#else
#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER
TElPKCS11FunctionsManager* TElSSHPKCS11KeyStorage::get_FunctionsManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHPKCS11KeyStorage_get_FunctionsManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FunctionsManager)
		this->_Inst_FunctionsManager = new TElPKCS11FunctionsManager(hOutResult, ohFalse);
	else
		this->_Inst_FunctionsManager->updateHandle(hOutResult);
	return this->_Inst_FunctionsManager;
}

SB_INLINE void TElSSHPKCS11KeyStorage::set_FunctionsManager(TElPKCS11FunctionsManager &Value)
{
	SBCheckError(TElSSHPKCS11KeyStorage_set_FunctionsManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSHPKCS11KeyStorage::set_FunctionsManager(TElPKCS11FunctionsManager *Value)
{
	SBCheckError(TElSSHPKCS11KeyStorage_set_FunctionsManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */
#endif
#ifndef SB_IOS
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHPKCS11KeyStorage_get_DLLName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1936798612, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHPKCS11KeyStorage::set_DLLName(const std::string &Value)
{
	SBCheckError(TElSSHPKCS11KeyStorage_set_DLLName(_Handle, Value.data(), (int32_t)Value.length()));
}
#endif

bool TElSSHPKCS11KeyStorage::get_TrySingleThreadedMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHPKCS11KeyStorage_get_TrySingleThreadedMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHPKCS11KeyStorage::set_TrySingleThreadedMode(bool Value)
{
	SBCheckError(TElSSHPKCS11KeyStorage_set_TrySingleThreadedMode(_Handle, (int8_t)Value));
}

bool TElSSHPKCS11KeyStorage::get_MonitorSlotEvents()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHPKCS11KeyStorage_get_MonitorSlotEvents(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHPKCS11KeyStorage::set_MonitorSlotEvents(bool Value)
{
	SBCheckError(TElSSHPKCS11KeyStorage_set_MonitorSlotEvents(_Handle, (int8_t)Value));
}

TSBPKCS11SlotEventMonitoringMode TElSSHPKCS11KeyStorage::get_SlotEventMonitoringMode()
{
	TSBPKCS11SlotEventMonitoringModeRaw OutResultRaw = 0;
	SBCheckError(TElSSHPKCS11KeyStorage_get_SlotEventMonitoringMode(_Handle, &OutResultRaw));
	return (TSBPKCS11SlotEventMonitoringMode)OutResultRaw;
}

SB_INLINE void TElSSHPKCS11KeyStorage::set_SlotEventMonitoringMode(TSBPKCS11SlotEventMonitoringMode Value)
{
	SBCheckError(TElSSHPKCS11KeyStorage_set_SlotEventMonitoringMode(_Handle, (TSBPKCS11SlotEventMonitoringModeRaw)Value));
}

SB_INLINE int32_t TElSSHPKCS11KeyStorage::get_SlotEventMonitoringDelay()
{
	int32_t OutResult;
	SBCheckError(TElSSHPKCS11KeyStorage_get_SlotEventMonitoringDelay(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHPKCS11KeyStorage::set_SlotEventMonitoringDelay(int32_t Value)
{
	SBCheckError(TElSSHPKCS11KeyStorage_set_SlotEventMonitoringDelay(_Handle, Value));
}

bool TElSSHPKCS11KeyStorage::get_SynchronizeGUI()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHPKCS11KeyStorage_get_SynchronizeGUI(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHPKCS11KeyStorage::set_SynchronizeGUI(bool Value)
{
	SBCheckError(TElSSHPKCS11KeyStorage_set_SynchronizeGUI(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProvider* TElSSHPKCS11KeyStorage::get_CryptoProvider()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHPKCS11KeyStorage_get_CryptoProvider(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProvider)
		this->_Inst_CryptoProvider = new TElCustomCryptoProvider(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProvider->updateHandle(hOutResult);
	return this->_Inst_CryptoProvider;
}

SB_INLINE void TElSSHPKCS11KeyStorage::set_CryptoProvider(TElCustomCryptoProvider &Value)
{
	SBCheckError(TElSSHPKCS11KeyStorage_set_CryptoProvider(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSHPKCS11KeyStorage::set_CryptoProvider(TElCustomCryptoProvider *Value)
{
	SBCheckError(TElSSHPKCS11KeyStorage_set_CryptoProvider(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

TSBPKCS11StorageOptions TElSSHPKCS11KeyStorage::get_PKCS11Options()
{
	TSBPKCS11StorageOptionsRaw OutResultRaw = 0;
	SBCheckError(TElSSHPKCS11KeyStorage_get_PKCS11Options(_Handle, &OutResultRaw));
	return (TSBPKCS11StorageOptions)OutResultRaw;
}

SB_INLINE void TElSSHPKCS11KeyStorage::set_PKCS11Options(TSBPKCS11StorageOptions Value)
{
	SBCheckError(TElSSHPKCS11KeyStorage_set_PKCS11Options(_Handle, (TSBPKCS11StorageOptionsRaw)Value));
}

TSBPKCS11TokenAccessMode TElSSHPKCS11KeyStorage::get_TokenAccessMode()
{
	TSBPKCS11TokenAccessModeRaw OutResultRaw = 0;
	SBCheckError(TElSSHPKCS11KeyStorage_get_TokenAccessMode(_Handle, &OutResultRaw));
	return (TSBPKCS11TokenAccessMode)OutResultRaw;
}

SB_INLINE void TElSSHPKCS11KeyStorage::set_TokenAccessMode(TSBPKCS11TokenAccessMode Value)
{
	SBCheckError(TElSSHPKCS11KeyStorage_set_TokenAccessMode(_Handle, (TSBPKCS11TokenAccessModeRaw)Value));
}

#ifdef SB_USE_CLASS_TELPKCS11NSSPARAMS
TElPKCS11NSSParams* TElSSHPKCS11KeyStorage::get_NSSParams()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHPKCS11KeyStorage_get_NSSParams(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NSSParams)
		this->_Inst_NSSParams = new TElPKCS11NSSParams(hOutResult, ohFalse);
	else
		this->_Inst_NSSParams->updateHandle(hOutResult);
	return this->_Inst_NSSParams;
}
#endif /* SB_USE_CLASS_TELPKCS11NSSPARAMS */

SB_INLINE void TElSSHPKCS11KeyStorage::get_OnSlotEvent(TElPKCSSlotEventEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHPKCS11KeyStorage_get_OnSlotEvent(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHPKCS11KeyStorage::set_OnSlotEvent(TElPKCSSlotEventEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHPKCS11KeyStorage_set_OnSlotEvent(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHPKCS11KeyStorage::get_OnNotification(TElPKCSNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHPKCS11KeyStorage_get_OnNotification(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHPKCS11KeyStorage::set_OnNotification(TElPKCSNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHPKCS11KeyStorage_set_OnNotification(_Handle, pMethodValue, pDataValue));
}

void TElSSHPKCS11KeyStorage::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS11MODULE
	this->_Inst_Module = NULL;
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#ifdef SB_IOS
#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER
	this->_Inst_FunctionsManager = NULL;
#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */
#endif
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELPKCS11NSSPARAMS
	this->_Inst_NSSParams = NULL;
#endif /* SB_USE_CLASS_TELPKCS11NSSPARAMS */
}

TElSSHPKCS11KeyStorage::TElSSHPKCS11KeyStorage(TElSSHPKCS11KeyStorageHandle handle, TElOwnHandle ownHandle) : TElSSHCustomKeyStorage(handle, ownHandle)
{
	initInstances();
}

TElSSHPKCS11KeyStorage::TElSSHPKCS11KeyStorage(TComponent &AOwner) : TElSSHCustomKeyStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHPKCS11KeyStorage_Create(AOwner.getHandle(), &_Handle));
}

TElSSHPKCS11KeyStorage::TElSSHPKCS11KeyStorage(TComponent *AOwner) : TElSSHCustomKeyStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHPKCS11KeyStorage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSSHPKCS11KeyStorage::~TElSSHPKCS11KeyStorage()
{
#ifdef SB_USE_CLASS_TELPKCS11MODULE
	delete this->_Inst_Module;
	this->_Inst_Module = NULL;
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#ifdef SB_IOS
#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER
	delete this->_Inst_FunctionsManager;
	this->_Inst_FunctionsManager = NULL;
#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */
#endif
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	delete this->_Inst_CryptoProvider;
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELPKCS11NSSPARAMS
	delete this->_Inst_NSSParams;
	this->_Inst_NSSParams = NULL;
#endif /* SB_USE_CLASS_TELPKCS11NSSPARAMS */
}
#endif /* SB_USE_CLASS_TELSSHPKCS11KEYSTORAGE */

#ifdef SB_USE_CLASS_TELSSHPKCS11CONSUMERKEYSTORAGE

TElSSHPKCS11ConsumerKeyStorage::TElSSHPKCS11ConsumerKeyStorage(TElSSHPKCS11ConsumerKeyStorageHandle handle, TElOwnHandle ownHandle) : TElPKCS11Consumer(handle, ownHandle)
{
}

TElSSHPKCS11ConsumerKeyStorage::TElSSHPKCS11ConsumerKeyStorage() : TElPKCS11Consumer(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHPKCS11ConsumerKeyStorage_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSSHPKCS11CONSUMERKEYSTORAGE */

#ifdef SB_USE_CLASS_TELPKCS11SSHKEY

void TElPKCS11SSHKey::Copy(TElSSHKey &Dest)
{
	TElClassHandle hDest = Dest.getHandle();
	SBCheckError(TElPKCS11SSHKey_Copy(_Handle, &hDest));
	Dest.updateHandle(hDest);
}

SB_INLINE TElSSHKeyHandle TElPKCS11SSHKey::Clone()
{
	TElSSHKeyHandle OutResult;
	SBCheckError(TElPKCS11SSHKey_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE TElSSHKeyHandle TElPKCS11SSHKey::CreateObjectInstance()
{
	TElSSHKeyHandle OutResult;
	SBCheckError(TElPKCS11SSHKey_CreateObjectInstance(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS11SSHKey::Clear()
{
	SBCheckError(TElPKCS11SSHKey_Clear(_Handle));
}

void TElPKCS11SSHKey::get_KeyID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11SSHKey_get_KeyID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-372121237, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElPKCS11SSHKey::TElPKCS11SSHKey(TElPKCS11SSHKeyHandle handle, TElOwnHandle ownHandle) : TElSSHKey(handle, ownHandle)
{
}

TElPKCS11SSHKey::TElPKCS11SSHKey() : TElSSHKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11SSHKey_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPKCS11SSHKEY */

};	/* namespace SecureBlackbox */
