#ifndef __INC_SBWINCERTSTORAGE
#define __INC_SBWINCERTSTORAGE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#ifdef SB_WINDOWS
#include "sbtypes.h"
#include "sbcustomcertstorage.h"
#include "sbx509.h"
#include "sbwincrypt.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbalgorithmidentifier.h"
#include "sbconstants.h"
#include "sbsharedresource.h"
#include "sbcryptoprov.h"
#include "sbrsa.h"
#include "sbmskeyblob.h"
#endif

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifdef SB_WINDOWS
typedef TElClassHandle TElWinCertStorageHandle;

typedef TElWinCertStorageHandle ElWinCertStorageHandle;

typedef uint8_t TSBStorageTypeRaw;

typedef enum
{
	stSystem = 0,
	stRegistry = 1,
	stLDAP = 2,
	stMemory = 3
} TSBStorageType;

typedef uint8_t TSBStorageAccessTypeRaw;

typedef enum
{
	atCurrentService = 0,
	atCurrentUser = 1,
	atCurrentUserGroupPolicy = 2,
	atLocalMachine = 3,
	atLocalMachineEnterprise = 4,
	atLocalMachineGroupPolicy = 5,
	atServices = 6,
	atUsers = 7
} TSBStorageAccessType;

typedef uint8_t TSBStorageProviderTypeRaw;

typedef enum
{
	ptDefault = 0,
	ptBaseDSSDH = 1,
	ptBaseDSS = 2,
	ptBase = 3,
	ptRSASchannel = 4,
	ptRSASignature = 5,
	ptEnhancedDSSDH = 6,
	ptEnhancedRSAAES = 7,
	ptEnhanced = 8,
	ptBaseSmartCard = 9,
	ptStrong = 10,
	ptCryptoProGOST94 = 11,
	ptCryptoProGOST2001 = 12
} TSBStorageProviderType;

#ifdef SB_USE_CLASS_TELWINCERTSTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_GetAvailableStores(TStringsHandle Stores, TSBStorageAccessTypeRaw AccessType);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_GetAvailableStores_1(TElWinCertStorageHandle _Handle, TStringsHandle Stores, TSBStorageAccessTypeRaw AccessType);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_GetAvailablePhysicalStores(const char * pcSystemStore, int32_t szSystemStore, TStringsHandle Stores, TSBStorageAccessTypeRaw AccessType);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_GetAvailablePhysicalStores_1(TElWinCertStorageHandle _Handle, const char * pcSystemStore, int32_t szSystemStore, TStringsHandle Stores, TSBStorageAccessTypeRaw AccessType);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_GetStoreFriendlyName(const char * pcStoreName, int32_t szStoreName, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_GetStoreFriendlyName_1(TElWinCertStorageHandle _Handle, const char * pcStoreName, int32_t szStoreName, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_Add(TElWinCertStorageHandle _Handle, TElX509CertificateHandle Certificate, int8_t CopyPrivateKey);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_Add_1(TElWinCertStorageHandle _Handle, TElX509CertificateHandle Certificate, const char * pcStoreName, int32_t szStoreName, int8_t CopyPrivateKey, int8_t Exportable, int8_t Protected);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_Add_2(TElWinCertStorageHandle _Handle, TElX509CertificateHandle Certificate, int8_t BindToExistingPrivateKey, const char * pcStoreName, int32_t szStoreName, const char * pcPrivateKeyContainerName, int32_t szPrivateKeyContainerName);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_Remove(TElWinCertStorageHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_Refresh(TElWinCertStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_PreloadCertificates(TElWinCertStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_CreateStore(TElWinCertStorageHandle _Handle, const char * pcStoreName, int32_t szStoreName);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_DeleteStore(TElWinCertStorageHandle _Handle, const char * pcStoreName, int32_t szStoreName);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_ListKeyContainers(TElWinCertStorageHandle _Handle, TStringListHandle List);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_ListKeyContainers_1(TElWinCertStorageHandle _Handle, TStringListHandle List, TSBStorageProviderTypeRaw ProvType);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_DeleteKeyContainer(TElWinCertStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_Select(TElWinCertStorageHandle _Handle, uint32_t Owner, TElCustomCertStorageHandle SelectedList, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_ImportWizard(uint32_t Owner, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_ImportWizard_1(TElWinCertStorageHandle _Handle, uint32_t Owner, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_get_Count(TElWinCertStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_get_Certificates(TElWinCertStorageHandle _Handle, int32_t Index, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_get_TryCurrentUser(TElWinCertStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_set_TryCurrentUser(TElWinCertStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_get_SystemStores(TElWinCertStorageHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_set_SystemStores(TElWinCertStorageHandle _Handle, TStringListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_get_PhysicalStores(TElWinCertStorageHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_set_PhysicalStores(TElWinCertStorageHandle _Handle, TStringListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_get_StorageType(TElWinCertStorageHandle _Handle, TSBStorageTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_set_StorageType(TElWinCertStorageHandle _Handle, TSBStorageTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_get_AccessType(TElWinCertStorageHandle _Handle, TSBStorageAccessTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_set_AccessType(TElWinCertStorageHandle _Handle, TSBStorageAccessTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_get_Provider(TElWinCertStorageHandle _Handle, TSBStorageProviderTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_set_Provider(TElWinCertStorageHandle _Handle, TSBStorageProviderTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_get_ReadOnly(TElWinCertStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_set_ReadOnly(TElWinCertStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_get_CryptoProvider(TElWinCertStorageHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_set_CryptoProvider(TElWinCertStorageHandle _Handle, TElCustomCryptoProviderHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_get_AllowDuplicates(TElWinCertStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_set_AllowDuplicates(TElWinCertStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinCertStorage_Create(TComponentHandle Owner, TElWinCertStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELWINCERTSTORAGE */
#endif

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef SB_WINDOWS
#ifdef __cplusplus

// Class forward declaration
class TElWinCertStorage;
typedef TElWinCertStorage ElWinCertStorage;

#ifdef SB_USE_CLASS_TELWINCERTSTORAGE
class TElWinCertStorage: public TElCustomCertStorage
{
	private:
		SB_DISABLE_COPY(TElWinCertStorage)
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_Certificates;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_SystemStores;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_PhysicalStores;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCustomCryptoProvider* _Inst_CryptoProvider;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TSTRINGS
		static void GetAvailableStores(TStrings &Stores, TSBStorageAccessType AccessType);

		static void GetAvailableStores(TStrings *Stores, TSBStorageAccessType AccessType);
#endif /* SB_USE_CLASS_TSTRINGS */

#ifdef SB_USE_CLASS_TSTRINGS
		void GetAvailableStores_Inst(TStrings &Stores, TSBStorageAccessType AccessType);

		void GetAvailableStores_Inst(TStrings *Stores, TSBStorageAccessType AccessType);
#endif /* SB_USE_CLASS_TSTRINGS */

#ifdef SB_USE_CLASS_TSTRINGS
		static void GetAvailablePhysicalStores(const std::string &SystemStore, TStrings &Stores, TSBStorageAccessType AccessType);

		static void GetAvailablePhysicalStores(const std::string &SystemStore, TStrings *Stores, TSBStorageAccessType AccessType);
#endif /* SB_USE_CLASS_TSTRINGS */

#ifdef SB_USE_CLASS_TSTRINGS
		void GetAvailablePhysicalStores_Inst(const std::string &SystemStore, TStrings &Stores, TSBStorageAccessType AccessType);

		void GetAvailablePhysicalStores_Inst(const std::string &SystemStore, TStrings *Stores, TSBStorageAccessType AccessType);
#endif /* SB_USE_CLASS_TSTRINGS */

		static void GetStoreFriendlyName(const std::string &StoreName, std::string &OutResult);

		void GetStoreFriendlyName_Inst(const std::string &StoreName, std::string &OutResult);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual void Add(TElX509Certificate &Certificate, bool CopyPrivateKey);

		virtual void Add(TElX509Certificate *Certificate, bool CopyPrivateKey);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		void Add(TElX509Certificate &Certificate, const std::string &StoreName, bool CopyPrivateKey, bool Exportable, bool Protected);

		void Add(TElX509Certificate *Certificate, const std::string &StoreName, bool CopyPrivateKey, bool Exportable, bool Protected);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		void Add(TElX509Certificate &Certificate, bool BindToExistingPrivateKey, const std::string &StoreName, const std::string &PrivateKeyContainerName);

		void Add(TElX509Certificate *Certificate, bool BindToExistingPrivateKey, const std::string &StoreName, const std::string &PrivateKeyContainerName);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual void Remove(int32_t Index);

		void Refresh();

		void PreloadCertificates();

		void CreateStore(const std::string &StoreName);

		void DeleteStore(const std::string &StoreName);

#ifdef SB_USE_CLASS_TSTRINGLIST
		void ListKeyContainers(TStringList &List);

		void ListKeyContainers(TStringList *List);
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TSTRINGLIST
		void ListKeyContainers(TStringList &List, TSBStorageProviderType ProvType);

		void ListKeyContainers(TStringList *List, TSBStorageProviderType ProvType);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		void DeleteKeyContainer(const std::string &ContainerName);

		bool Select(uint32_t Owner, TElCustomCertStorage &SelectedList);

		bool Select(uint32_t Owner, TElCustomCertStorage *SelectedList);

		static bool ImportWizard(uint32_t Owner);

		bool ImportWizard_Inst(uint32_t Owner);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElWinCertStorage, Count);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_Certificates(int32_t Index);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual bool get_TryCurrentUser();

		virtual void set_TryCurrentUser(bool Value);

		SB_DECLARE_PROPERTY(bool, get_TryCurrentUser, set_TryCurrentUser, TElWinCertStorage, TryCurrentUser);

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_SystemStores();

		virtual void set_SystemStores(TStringList &Value);

		virtual void set_SystemStores(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_SystemStores, set_SystemStores, TElWinCertStorage, SystemStores);
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_PhysicalStores();

		virtual void set_PhysicalStores(TStringList &Value);

		virtual void set_PhysicalStores(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_PhysicalStores, set_PhysicalStores, TElWinCertStorage, PhysicalStores);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		virtual TSBStorageType get_StorageType();

		virtual void set_StorageType(TSBStorageType Value);

		SB_DECLARE_PROPERTY(TSBStorageType, get_StorageType, set_StorageType, TElWinCertStorage, StorageType);

		virtual TSBStorageAccessType get_AccessType();

		virtual void set_AccessType(TSBStorageAccessType Value);

		SB_DECLARE_PROPERTY(TSBStorageAccessType, get_AccessType, set_AccessType, TElWinCertStorage, AccessType);

		virtual TSBStorageProviderType get_Provider();

		virtual void set_Provider(TSBStorageProviderType Value);

		SB_DECLARE_PROPERTY(TSBStorageProviderType, get_Provider, set_Provider, TElWinCertStorage, Provider);

		virtual bool get_ReadOnly();

		virtual void set_ReadOnly(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ReadOnly, set_ReadOnly, TElWinCertStorage, ReadOnly);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		virtual TElCustomCryptoProvider* get_CryptoProvider();

		virtual void set_CryptoProvider(TElCustomCryptoProvider &Value);

		virtual void set_CryptoProvider(TElCustomCryptoProvider *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProvider*, get_CryptoProvider, set_CryptoProvider, TElWinCertStorage, CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		virtual bool get_AllowDuplicates();

		virtual void set_AllowDuplicates(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AllowDuplicates, set_AllowDuplicates, TElWinCertStorage, AllowDuplicates);

		TElWinCertStorage(TElWinCertStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElWinCertStorage(TComponent &Owner);

		explicit TElWinCertStorage(TComponent *Owner);

		virtual ~TElWinCertStorage();

};
#endif /* SB_USE_CLASS_TELWINCERTSTORAGE */

#endif  /* __cplusplus */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBWINCERTSTORAGE */
