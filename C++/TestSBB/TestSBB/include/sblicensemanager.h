#ifndef __INC_SBLICENSEMANAGER
#define __INC_SBLICENSEMANAGER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbconstants.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElSBLicenseManagerHandle;

typedef TElSBLicenseManagerHandle ElSBLicenseManagerHandle;

typedef uint8_t TSBLicenseKeyRegKeyRaw;

typedef enum
{
	rkHK = 0
} TSBLicenseKeyRegKey;

#ifdef SB_USE_CLASS_TELSBLICENSEMANAGER
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSBLicenseManager_get_RegistryKey(TElSBLicenseManagerHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSBLicenseManager_set_RegistryKey(TElSBLicenseManagerHandle _Handle, uint32_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSBLicenseManager_get_LicenseKey(TElSBLicenseManagerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSBLicenseManager_set_LicenseKey(TElSBLicenseManagerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSBLicenseManager_get_LicenseKeyFile(TElSBLicenseManagerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSBLicenseManager_set_LicenseKeyFile(TElSBLicenseManagerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSBLicenseManager_Create(TComponentHandle AOwner, TElSBLicenseManagerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSBLICENSEMANAGER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSBLicenseManager;
typedef TElSBLicenseManager ElSBLicenseManager;

#ifdef SB_USE_CLASS_TELSBLICENSEMANAGER
class TElSBLicenseManager: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSBLicenseManager)
	public:
#ifdef SB_WINDOWS
		virtual uint32_t get_RegistryKey();

		virtual void set_RegistryKey(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_RegistryKey, set_RegistryKey, TElSBLicenseManager, RegistryKey);
#endif

		virtual void get_LicenseKey(std::string &OutResult);

		virtual void set_LicenseKey(const std::string &Value);

		virtual void get_LicenseKeyFile(std::string &OutResult);

		virtual void set_LicenseKeyFile(const std::string &Value);

		TElSBLicenseManager(TElSBLicenseManagerHandle handle, TElOwnHandle ownHandle);

		explicit TElSBLicenseManager(TComponent &AOwner);

		explicit TElSBLicenseManager(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELSBLICENSEMANAGER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBLICENSEMANAGER */
