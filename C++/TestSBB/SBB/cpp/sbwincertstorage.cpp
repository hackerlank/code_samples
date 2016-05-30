#include "sbdefs.h"
#ifdef SB_WINDOWS
#include "sbwincertstorage.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELWINCERTSTORAGE

#ifdef SB_USE_CLASS_TSTRINGS
SB_INLINE void TElWinCertStorage::GetAvailableStores(TStrings &Stores, TSBStorageAccessType AccessType)
{
	SBCheckError(TElWinCertStorage_GetAvailableStores(Stores.getHandle(), (TSBStorageAccessTypeRaw)AccessType));
}

SB_INLINE void TElWinCertStorage::GetAvailableStores(TStrings *Stores, TSBStorageAccessType AccessType)
{
	SBCheckError(TElWinCertStorage_GetAvailableStores((Stores != NULL) ? Stores->getHandle() : SB_NULL_HANDLE, (TSBStorageAccessTypeRaw)AccessType));
}
#endif /* SB_USE_CLASS_TSTRINGS */

#ifdef SB_USE_CLASS_TSTRINGS
SB_INLINE void TElWinCertStorage::GetAvailableStores_Inst(TStrings &Stores, TSBStorageAccessType AccessType)
{
	SBCheckError(TElWinCertStorage_GetAvailableStores_1(_Handle, Stores.getHandle(), (TSBStorageAccessTypeRaw)AccessType));
}

SB_INLINE void TElWinCertStorage::GetAvailableStores_Inst(TStrings *Stores, TSBStorageAccessType AccessType)
{
	SBCheckError(TElWinCertStorage_GetAvailableStores_1(_Handle, (Stores != NULL) ? Stores->getHandle() : SB_NULL_HANDLE, (TSBStorageAccessTypeRaw)AccessType));
}
#endif /* SB_USE_CLASS_TSTRINGS */

#ifdef SB_USE_CLASS_TSTRINGS
SB_INLINE void TElWinCertStorage::GetAvailablePhysicalStores(const std::string &SystemStore, TStrings &Stores, TSBStorageAccessType AccessType)
{
	SBCheckError(TElWinCertStorage_GetAvailablePhysicalStores(SystemStore.data(), (int32_t)SystemStore.length(), Stores.getHandle(), (TSBStorageAccessTypeRaw)AccessType));
}

SB_INLINE void TElWinCertStorage::GetAvailablePhysicalStores(const std::string &SystemStore, TStrings *Stores, TSBStorageAccessType AccessType)
{
	SBCheckError(TElWinCertStorage_GetAvailablePhysicalStores(SystemStore.data(), (int32_t)SystemStore.length(), (Stores != NULL) ? Stores->getHandle() : SB_NULL_HANDLE, (TSBStorageAccessTypeRaw)AccessType));
}
#endif /* SB_USE_CLASS_TSTRINGS */

#ifdef SB_USE_CLASS_TSTRINGS
SB_INLINE void TElWinCertStorage::GetAvailablePhysicalStores_Inst(const std::string &SystemStore, TStrings &Stores, TSBStorageAccessType AccessType)
{
	SBCheckError(TElWinCertStorage_GetAvailablePhysicalStores_1(_Handle, SystemStore.data(), (int32_t)SystemStore.length(), Stores.getHandle(), (TSBStorageAccessTypeRaw)AccessType));
}

SB_INLINE void TElWinCertStorage::GetAvailablePhysicalStores_Inst(const std::string &SystemStore, TStrings *Stores, TSBStorageAccessType AccessType)
{
	SBCheckError(TElWinCertStorage_GetAvailablePhysicalStores_1(_Handle, SystemStore.data(), (int32_t)SystemStore.length(), (Stores != NULL) ? Stores->getHandle() : SB_NULL_HANDLE, (TSBStorageAccessTypeRaw)AccessType));
}
#endif /* SB_USE_CLASS_TSTRINGS */

void TElWinCertStorage::GetStoreFriendlyName(const std::string &StoreName, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinCertStorage_GetStoreFriendlyName(StoreName.data(), (int32_t)StoreName.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(53182698, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWinCertStorage::GetStoreFriendlyName_Inst(const std::string &StoreName, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinCertStorage_GetStoreFriendlyName_1(_Handle, StoreName.data(), (int32_t)StoreName.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(53182698, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElWinCertStorage::Add(TElX509Certificate &Certificate, bool CopyPrivateKey)
{
	SBCheckError(TElWinCertStorage_Add(_Handle, Certificate.getHandle(), (int8_t)CopyPrivateKey));
}

SB_INLINE void TElWinCertStorage::Add(TElX509Certificate *Certificate, bool CopyPrivateKey)
{
	SBCheckError(TElWinCertStorage_Add(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)CopyPrivateKey));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElWinCertStorage::Add(TElX509Certificate &Certificate, const std::string &StoreName, bool CopyPrivateKey, bool Exportable, bool Protected)
{
	SBCheckError(TElWinCertStorage_Add_1(_Handle, Certificate.getHandle(), StoreName.data(), (int32_t)StoreName.length(), (int8_t)CopyPrivateKey, (int8_t)Exportable, (int8_t)Protected));
}

SB_INLINE void TElWinCertStorage::Add(TElX509Certificate *Certificate, const std::string &StoreName, bool CopyPrivateKey, bool Exportable, bool Protected)
{
	SBCheckError(TElWinCertStorage_Add_1(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, StoreName.data(), (int32_t)StoreName.length(), (int8_t)CopyPrivateKey, (int8_t)Exportable, (int8_t)Protected));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElWinCertStorage::Add(TElX509Certificate &Certificate, bool BindToExistingPrivateKey, const std::string &StoreName, const std::string &PrivateKeyContainerName)
{
	SBCheckError(TElWinCertStorage_Add_2(_Handle, Certificate.getHandle(), (int8_t)BindToExistingPrivateKey, StoreName.data(), (int32_t)StoreName.length(), PrivateKeyContainerName.data(), (int32_t)PrivateKeyContainerName.length()));
}

SB_INLINE void TElWinCertStorage::Add(TElX509Certificate *Certificate, bool BindToExistingPrivateKey, const std::string &StoreName, const std::string &PrivateKeyContainerName)
{
	SBCheckError(TElWinCertStorage_Add_2(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)BindToExistingPrivateKey, StoreName.data(), (int32_t)StoreName.length(), PrivateKeyContainerName.data(), (int32_t)PrivateKeyContainerName.length()));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE void TElWinCertStorage::Remove(int32_t Index)
{
	SBCheckError(TElWinCertStorage_Remove(_Handle, Index));
}

SB_INLINE void TElWinCertStorage::Refresh()
{
	SBCheckError(TElWinCertStorage_Refresh(_Handle));
}

SB_INLINE void TElWinCertStorage::PreloadCertificates()
{
	SBCheckError(TElWinCertStorage_PreloadCertificates(_Handle));
}

SB_INLINE void TElWinCertStorage::CreateStore(const std::string &StoreName)
{
	SBCheckError(TElWinCertStorage_CreateStore(_Handle, StoreName.data(), (int32_t)StoreName.length()));
}

SB_INLINE void TElWinCertStorage::DeleteStore(const std::string &StoreName)
{
	SBCheckError(TElWinCertStorage_DeleteStore(_Handle, StoreName.data(), (int32_t)StoreName.length()));
}

#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElWinCertStorage::ListKeyContainers(TStringList &List)
{
	SBCheckError(TElWinCertStorage_ListKeyContainers(_Handle, List.getHandle()));
}

SB_INLINE void TElWinCertStorage::ListKeyContainers(TStringList *List)
{
	SBCheckError(TElWinCertStorage_ListKeyContainers(_Handle, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElWinCertStorage::ListKeyContainers(TStringList &List, TSBStorageProviderType ProvType)
{
	SBCheckError(TElWinCertStorage_ListKeyContainers_1(_Handle, List.getHandle(), (TSBStorageProviderTypeRaw)ProvType));
}

SB_INLINE void TElWinCertStorage::ListKeyContainers(TStringList *List, TSBStorageProviderType ProvType)
{
	SBCheckError(TElWinCertStorage_ListKeyContainers_1(_Handle, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, (TSBStorageProviderTypeRaw)ProvType));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

SB_INLINE void TElWinCertStorage::DeleteKeyContainer(const std::string &ContainerName)
{
	SBCheckError(TElWinCertStorage_DeleteKeyContainer(_Handle, ContainerName.data(), (int32_t)ContainerName.length()));
}

bool TElWinCertStorage::Select(uint32_t Owner, TElCustomCertStorage &SelectedList)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinCertStorage_Select(_Handle, Owner, SelectedList.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWinCertStorage::Select(uint32_t Owner, TElCustomCertStorage *SelectedList)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinCertStorage_Select(_Handle, Owner, (SelectedList != NULL) ? SelectedList->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWinCertStorage::ImportWizard(uint32_t Owner)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinCertStorage_ImportWizard(Owner, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWinCertStorage::ImportWizard_Inst(uint32_t Owner)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinCertStorage_ImportWizard_1(_Handle, Owner, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElWinCertStorage::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElWinCertStorage_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElWinCertStorage::get_Certificates(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWinCertStorage_get_Certificates(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

bool TElWinCertStorage::get_TryCurrentUser()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinCertStorage_get_TryCurrentUser(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWinCertStorage::set_TryCurrentUser(bool Value)
{
	SBCheckError(TElWinCertStorage_set_TryCurrentUser(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElWinCertStorage::get_SystemStores()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWinCertStorage_get_SystemStores(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SystemStores)
		this->_Inst_SystemStores = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_SystemStores->updateHandle(hOutResult);
	return this->_Inst_SystemStores;
}

SB_INLINE void TElWinCertStorage::set_SystemStores(TStringList &Value)
{
	SBCheckError(TElWinCertStorage_set_SystemStores(_Handle, Value.getHandle()));
}

SB_INLINE void TElWinCertStorage::set_SystemStores(TStringList *Value)
{
	SBCheckError(TElWinCertStorage_set_SystemStores(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElWinCertStorage::get_PhysicalStores()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWinCertStorage_get_PhysicalStores(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PhysicalStores)
		this->_Inst_PhysicalStores = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_PhysicalStores->updateHandle(hOutResult);
	return this->_Inst_PhysicalStores;
}

SB_INLINE void TElWinCertStorage::set_PhysicalStores(TStringList &Value)
{
	SBCheckError(TElWinCertStorage_set_PhysicalStores(_Handle, Value.getHandle()));
}

SB_INLINE void TElWinCertStorage::set_PhysicalStores(TStringList *Value)
{
	SBCheckError(TElWinCertStorage_set_PhysicalStores(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

TSBStorageType TElWinCertStorage::get_StorageType()
{
	TSBStorageTypeRaw OutResultRaw = 0;
	SBCheckError(TElWinCertStorage_get_StorageType(_Handle, &OutResultRaw));
	return (TSBStorageType)OutResultRaw;
}

SB_INLINE void TElWinCertStorage::set_StorageType(TSBStorageType Value)
{
	SBCheckError(TElWinCertStorage_set_StorageType(_Handle, (TSBStorageTypeRaw)Value));
}

TSBStorageAccessType TElWinCertStorage::get_AccessType()
{
	TSBStorageAccessTypeRaw OutResultRaw = 0;
	SBCheckError(TElWinCertStorage_get_AccessType(_Handle, &OutResultRaw));
	return (TSBStorageAccessType)OutResultRaw;
}

SB_INLINE void TElWinCertStorage::set_AccessType(TSBStorageAccessType Value)
{
	SBCheckError(TElWinCertStorage_set_AccessType(_Handle, (TSBStorageAccessTypeRaw)Value));
}

TSBStorageProviderType TElWinCertStorage::get_Provider()
{
	TSBStorageProviderTypeRaw OutResultRaw = 0;
	SBCheckError(TElWinCertStorage_get_Provider(_Handle, &OutResultRaw));
	return (TSBStorageProviderType)OutResultRaw;
}

SB_INLINE void TElWinCertStorage::set_Provider(TSBStorageProviderType Value)
{
	SBCheckError(TElWinCertStorage_set_Provider(_Handle, (TSBStorageProviderTypeRaw)Value));
}

bool TElWinCertStorage::get_ReadOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinCertStorage_get_ReadOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWinCertStorage::set_ReadOnly(bool Value)
{
	SBCheckError(TElWinCertStorage_set_ReadOnly(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProvider* TElWinCertStorage::get_CryptoProvider()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWinCertStorage_get_CryptoProvider(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProvider)
		this->_Inst_CryptoProvider = new TElCustomCryptoProvider(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProvider->updateHandle(hOutResult);
	return this->_Inst_CryptoProvider;
}

SB_INLINE void TElWinCertStorage::set_CryptoProvider(TElCustomCryptoProvider &Value)
{
	SBCheckError(TElWinCertStorage_set_CryptoProvider(_Handle, Value.getHandle()));
}

SB_INLINE void TElWinCertStorage::set_CryptoProvider(TElCustomCryptoProvider *Value)
{
	SBCheckError(TElWinCertStorage_set_CryptoProvider(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

bool TElWinCertStorage::get_AllowDuplicates()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinCertStorage_get_AllowDuplicates(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWinCertStorage::set_AllowDuplicates(bool Value)
{
	SBCheckError(TElWinCertStorage_set_AllowDuplicates(_Handle, (int8_t)Value));
}

void TElWinCertStorage::initInstances()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_SystemStores = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_PhysicalStores = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
}

TElWinCertStorage::TElWinCertStorage(TElWinCertStorageHandle handle, TElOwnHandle ownHandle) : TElCustomCertStorage(handle, ownHandle)
{
	initInstances();
}

TElWinCertStorage::TElWinCertStorage(TComponent &Owner) : TElCustomCertStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWinCertStorage_Create(Owner.getHandle(), &_Handle));
}

TElWinCertStorage::TElWinCertStorage(TComponent *Owner) : TElCustomCertStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWinCertStorage_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElWinCertStorage::~TElWinCertStorage()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_SystemStores;
	this->_Inst_SystemStores = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_PhysicalStores;
	this->_Inst_PhysicalStores = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	delete this->_Inst_CryptoProvider;
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
}
#endif /* SB_USE_CLASS_TELWINCERTSTORAGE */

};	/* namespace SecureBlackbox */
#endif
