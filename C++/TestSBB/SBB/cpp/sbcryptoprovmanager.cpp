#include "sbcryptoprovmanager.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELBUILTINCRYPTOPROVIDERMANAGER

SB_INLINE void TElBuiltInCryptoProviderManager::Init()
{
	SBCheckError(TElBuiltInCryptoProviderManager_Init(_Handle));
}

SB_INLINE void TElBuiltInCryptoProviderManager::Deinit()
{
	SBCheckError(TElBuiltInCryptoProviderManager_Deinit(_Handle));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
bool TElBuiltInCryptoProviderManager::IsProviderAllowed(TElCustomCryptoProvider &Prov)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInCryptoProviderManager_IsProviderAllowed(_Handle, Prov.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBuiltInCryptoProviderManager::IsProviderAllowed(TElCustomCryptoProvider *Prov)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInCryptoProviderManager_IsProviderAllowed(_Handle, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

TSBCryptoEngineType TElBuiltInCryptoProviderManager::get_EngineType()
{
	TSBCryptoEngineTypeRaw OutResultRaw = 0;
	SBCheckError(TElBuiltInCryptoProviderManager_get_EngineType(_Handle, &OutResultRaw));
	return (TSBCryptoEngineType)OutResultRaw;
}

SB_INLINE void TElBuiltInCryptoProviderManager::set_EngineType(TSBCryptoEngineType Value)
{
	SBCheckError(TElBuiltInCryptoProviderManager_set_EngineType(_Handle, (TSBCryptoEngineTypeRaw)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProvider* TElBuiltInCryptoProviderManager::get_BuiltInCryptoProvider()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBuiltInCryptoProviderManager_get_BuiltInCryptoProvider(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_BuiltInCryptoProvider)
		this->_Inst_BuiltInCryptoProvider = new TElCustomCryptoProvider(hOutResult, ohFalse);
	else
		this->_Inst_BuiltInCryptoProvider->updateHandle(hOutResult);
	return this->_Inst_BuiltInCryptoProvider;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProvider* TElBuiltInCryptoProviderManager::get_Win32CryptoProvider()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBuiltInCryptoProviderManager_get_Win32CryptoProvider(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Win32CryptoProvider)
		this->_Inst_Win32CryptoProvider = new TElCustomCryptoProvider(hOutResult, ohFalse);
	else
		this->_Inst_Win32CryptoProvider->updateHandle(hOutResult);
	return this->_Inst_Win32CryptoProvider;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

void TElBuiltInCryptoProviderManager::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	this->_Inst_BuiltInCryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	this->_Inst_Win32CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
}

TElBuiltInCryptoProviderManager::TElBuiltInCryptoProviderManager(TElBuiltInCryptoProviderManagerHandle handle, TElOwnHandle ownHandle) : TElCustomCryptoProviderManager(handle, ownHandle)
{
	initInstances();
}

TElBuiltInCryptoProviderManager::TElBuiltInCryptoProviderManager(TComponent &AOwner) : TElCustomCryptoProviderManager(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBuiltInCryptoProviderManager_Create(AOwner.getHandle(), &_Handle));
}

TElBuiltInCryptoProviderManager::TElBuiltInCryptoProviderManager(TComponent *AOwner) : TElCustomCryptoProviderManager(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBuiltInCryptoProviderManager_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElBuiltInCryptoProviderManager::~TElBuiltInCryptoProviderManager()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	delete this->_Inst_BuiltInCryptoProvider;
	this->_Inst_BuiltInCryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	delete this->_Inst_Win32CryptoProvider;
	this->_Inst_Win32CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
}
#endif /* SB_USE_CLASS_TELBUILTINCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELFIPSCOMPLIANTCRYPTOPROVIDERMANAGER

SB_INLINE void TElFIPSCompliantCryptoProviderManager::Init()
{
	SBCheckError(TElFIPSCompliantCryptoProviderManager_Init(_Handle));
}

SB_INLINE void TElFIPSCompliantCryptoProviderManager::Deinit()
{
	SBCheckError(TElFIPSCompliantCryptoProviderManager_Deinit(_Handle));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
bool TElFIPSCompliantCryptoProviderManager::IsProviderAllowed(TElCustomCryptoProvider &Prov)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFIPSCompliantCryptoProviderManager_IsProviderAllowed(_Handle, Prov.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElFIPSCompliantCryptoProviderManager::IsProviderAllowed(TElCustomCryptoProvider *Prov)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFIPSCompliantCryptoProviderManager_IsProviderAllowed(_Handle, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

TElFIPSCompliantCryptoProviderManager::TElFIPSCompliantCryptoProviderManager(TElFIPSCompliantCryptoProviderManagerHandle handle, TElOwnHandle ownHandle) : TElCustomCryptoProviderManager(handle, ownHandle)
{
}

TElFIPSCompliantCryptoProviderManager::TElFIPSCompliantCryptoProviderManager(TComponent &AOwner) : TElCustomCryptoProviderManager(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFIPSCompliantCryptoProviderManager_Create(AOwner.getHandle(), &_Handle));
}

TElFIPSCompliantCryptoProviderManager::TElFIPSCompliantCryptoProviderManager(TComponent *AOwner) : TElCustomCryptoProviderManager(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFIPSCompliantCryptoProviderManager_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELFIPSCOMPLIANTCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_GLOBAL_PROCS_CRYPTOPROVMANAGER

#ifdef SB_USE_CLASS_TELBUILTINCRYPTOPROVIDERMANAGER
SB_INLINE TElBuiltInCryptoProviderManagerHandle DefaultCryptoProviderManager()
{
	TElBuiltInCryptoProviderManagerHandle OutResult;
	SBCheckError(SBCryptoProvManager_DefaultCryptoProviderManager(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELBUILTINCRYPTOPROVIDERMANAGER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TELFIPSCOMPLIANTCRYPTOPROVIDERMANAGER
SB_INLINE TElFIPSCompliantCryptoProviderManagerHandle FIPSCompliantCryptoProviderManager()
{
	TElFIPSCompliantCryptoProviderManagerHandle OutResult;
	SBCheckError(SBCryptoProvManager_FIPSCompliantCryptoProviderManager(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELFIPSCOMPLIANTCRYPTOPROVIDERMANAGER */
#endif

#endif /* SB_USE_GLOBAL_PROCS_CRYPTOPROVMANAGER */

};	/* namespace SecureBlackbox */
