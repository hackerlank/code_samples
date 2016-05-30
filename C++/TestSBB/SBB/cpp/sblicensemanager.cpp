#include "sblicensemanager.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSBLICENSEMANAGER

#ifdef SB_WINDOWS
SB_INLINE uint32_t TElSBLicenseManager::get_RegistryKey()
{
	uint32_t OutResult;
	SBCheckError(TElSBLicenseManager_get_RegistryKey(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSBLicenseManager::set_RegistryKey(uint32_t Value)
{
	SBCheckError(TElSBLicenseManager_set_RegistryKey(_Handle, Value));
}
#endif

void TElSBLicenseManager::get_LicenseKey(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSBLicenseManager_get_LicenseKey(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1768800821, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSBLicenseManager::set_LicenseKey(const std::string &Value)
{
	SBCheckError(TElSBLicenseManager_set_LicenseKey(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSBLicenseManager::get_LicenseKeyFile(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSBLicenseManager_get_LicenseKeyFile(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-636647649, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSBLicenseManager::set_LicenseKeyFile(const std::string &Value)
{
	SBCheckError(TElSBLicenseManager_set_LicenseKeyFile(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSBLicenseManager::TElSBLicenseManager(TElSBLicenseManagerHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElSBLicenseManager::TElSBLicenseManager(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSBLicenseManager_Create(AOwner.getHandle(), &_Handle));
}

TElSBLicenseManager::TElSBLicenseManager(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSBLicenseManager_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELSBLICENSEMANAGER */

};	/* namespace SecureBlackbox */
