#ifndef __INC_SBSSHPKCS11KEYSTORAGE
#define __INC_SBSSHPKCS11KEYSTORAGE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbcustomcrypto.h"
#include "sbpublickeycrypto.h"
#include "sbcryptoprov.h"
#include "sbcryptoprovutils.h"
#include "sbcryptoprovpkcs11.h"
#include "sbpkcs11base.h"
#include "sbpkcs11common.h"
#include "sbsshkeystorage.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElSSHPKCS11KeyStorageHandle;

typedef TElClassHandle TElSSHPKCS11ConsumerKeyStorageHandle;

typedef TElClassHandle TElPKCS11SSHKeyHandle;

#ifdef SB_USE_CLASS_TELSSHPKCS11KEYSTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_Open(TElSSHPKCS11KeyStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_Close(TElSSHPKCS11KeyStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_OpenSession(TElSSHPKCS11KeyStorageHandle _Handle, int32_t SlotIndex, int8_t ReadOnly, TElPKCS11SessionInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_CloseSession(TElSSHPKCS11KeyStorageHandle _Handle, int32_t SessionIndex);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_CloseAllSessions(TElSSHPKCS11KeyStorageHandle _Handle, TElPKCS11SlotInfoHandle Slot);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_Add(TElSSHPKCS11KeyStorageHandle _Handle, TElSSHKeyHandle Key);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_Add_1(TElSSHPKCS11KeyStorageHandle _Handle, int32_t SessionIndex, TElSSHKeyHandle Key, int8_t CopyPrivateKey, int8_t Exportable, const uint8_t pID[], int32_t szID, const uint8_t pKeyLabel[], int32_t szKeyLabel);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_Remove(TElSSHPKCS11KeyStorageHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_Clear(TElSSHPKCS11KeyStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_IndexOf(TElSSHPKCS11KeyStorageHandle _Handle, TElSSHKeyHandle Key, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_LoadPublic(TElSSHPKCS11KeyStorageHandle _Handle, TStreamHandle F, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_LoadPublic_1(TElSSHPKCS11KeyStorageHandle _Handle, const char * pcFilename, int32_t szFilename, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_SavePublic(TElSSHPKCS11KeyStorageHandle _Handle, TStreamHandle F, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_SavePublic_1(TElSSHPKCS11KeyStorageHandle _Handle, const char * pcFilename, int32_t szFilename, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_get_Module(TElSSHPKCS11KeyStorageHandle _Handle, TElPKCS11ModuleHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_get_Opened(TElSSHPKCS11KeyStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_get_UniqueID(TElSSHPKCS11KeyStorageHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
#ifndef SB_IOS
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_get_DLLName(TElSSHPKCS11KeyStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_set_DLLName(TElSSHPKCS11KeyStorageHandle _Handle, const char * pcValue, int32_t szValue);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_get_FunctionsManager(TElSSHPKCS11KeyStorageHandle _Handle, TElPKCS11FunctionsManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_set_FunctionsManager(TElSSHPKCS11KeyStorageHandle _Handle, TElPKCS11FunctionsManagerHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_get_TrySingleThreadedMode(TElSSHPKCS11KeyStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_set_TrySingleThreadedMode(TElSSHPKCS11KeyStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_get_MonitorSlotEvents(TElSSHPKCS11KeyStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_set_MonitorSlotEvents(TElSSHPKCS11KeyStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_get_SlotEventMonitoringMode(TElSSHPKCS11KeyStorageHandle _Handle, TSBPKCS11SlotEventMonitoringModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_set_SlotEventMonitoringMode(TElSSHPKCS11KeyStorageHandle _Handle, TSBPKCS11SlotEventMonitoringModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_get_SlotEventMonitoringDelay(TElSSHPKCS11KeyStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_set_SlotEventMonitoringDelay(TElSSHPKCS11KeyStorageHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_get_SynchronizeGUI(TElSSHPKCS11KeyStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_set_SynchronizeGUI(TElSSHPKCS11KeyStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_get_CryptoProvider(TElSSHPKCS11KeyStorageHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_set_CryptoProvider(TElSSHPKCS11KeyStorageHandle _Handle, TElCustomCryptoProviderHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_get_PKCS11Options(TElSSHPKCS11KeyStorageHandle _Handle, TSBPKCS11StorageOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_set_PKCS11Options(TElSSHPKCS11KeyStorageHandle _Handle, TSBPKCS11StorageOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_get_TokenAccessMode(TElSSHPKCS11KeyStorageHandle _Handle, TSBPKCS11TokenAccessModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_set_TokenAccessMode(TElSSHPKCS11KeyStorageHandle _Handle, TSBPKCS11TokenAccessModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_get_NSSParams(TElSSHPKCS11KeyStorageHandle _Handle, TElPKCS11NSSParamsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_get_OnSlotEvent(TElSSHPKCS11KeyStorageHandle _Handle, TElPKCSSlotEventEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_set_OnSlotEvent(TElSSHPKCS11KeyStorageHandle _Handle, TElPKCSSlotEventEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_get_OnNotification(TElSSHPKCS11KeyStorageHandle _Handle, TElPKCSNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_set_OnNotification(TElSSHPKCS11KeyStorageHandle _Handle, TElPKCSNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11KeyStorage_Create(TComponentHandle AOwner, TElSSHPKCS11KeyStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHPKCS11KEYSTORAGE */

#ifdef SB_USE_CLASS_TELSSHPKCS11CONSUMERKEYSTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElSSHPKCS11ConsumerKeyStorage_Create(TElPKCS11ConsumerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHPKCS11CONSUMERKEYSTORAGE */

#ifdef SB_USE_CLASS_TELPKCS11SSHKEY
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SSHKey_Copy(TElPKCS11SSHKeyHandle _Handle, TElSSHKeyHandle * Dest);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SSHKey_Clone(TElPKCS11SSHKeyHandle _Handle, TElSSHKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SSHKey_CreateObjectInstance(TElPKCS11SSHKeyHandle _Handle, TElSSHKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SSHKey_Clear(TElPKCS11SSHKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SSHKey_get_KeyID(TElPKCS11SSHKeyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SSHKey_Create(TElPKCS11SSHKeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11SSHKEY */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSSHPKCS11KeyStorage;
class TElSSHPKCS11ConsumerKeyStorage;
class TElPKCS11SSHKey;

#ifdef SB_USE_CLASS_TELSSHPKCS11KEYSTORAGE
class TElSSHPKCS11KeyStorage: public TElSSHCustomKeyStorage
{
	private:
		SB_DISABLE_COPY(TElSSHPKCS11KeyStorage)
#ifdef SB_USE_CLASS_TELPKCS11MODULE
		TElPKCS11Module* _Inst_Module;
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#ifdef SB_IOS
#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER
		TElPKCS11FunctionsManager* _Inst_FunctionsManager;
#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */
#endif
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCustomCryptoProvider* _Inst_CryptoProvider;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELPKCS11NSSPARAMS
		TElPKCS11NSSParams* _Inst_NSSParams;
#endif /* SB_USE_CLASS_TELPKCS11NSSPARAMS */

		void initInstances();

	public:
		void Open();

		void Close();

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfoHandle OpenSession(int32_t SlotIndex, bool ReadOnly);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

		void CloseSession(int32_t SessionIndex);

#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
		void CloseAllSessions(TElPKCS11SlotInfo &Slot);

		void CloseAllSessions(TElPKCS11SlotInfo *Slot);
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */

#ifdef SB_USE_CLASS_TELSSHKEY
		virtual void Add(TElSSHKey &Key);

		virtual void Add(TElSSHKey *Key);
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELSSHKEY
		void Add(int32_t SessionIndex, TElSSHKey &Key, bool CopyPrivateKey, bool Exportable, const std::vector<uint8_t> &ID, const std::vector<uint8_t> &KeyLabel);

		void Add(int32_t SessionIndex, TElSSHKey *Key, bool CopyPrivateKey, bool Exportable, const std::vector<uint8_t> &ID, const std::vector<uint8_t> &KeyLabel);
#endif /* SB_USE_CLASS_TELSSHKEY */

		virtual void Remove(int32_t Index);

		virtual void Clear();

#ifdef SB_USE_CLASS_TELSSHKEY
		virtual int32_t IndexOf(TElSSHKey &Key);

		virtual int32_t IndexOf(TElSSHKey *Key);
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t LoadPublic(TStream &F, int32_t Count);

		virtual int32_t LoadPublic(TStream *F, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t LoadPublic(const std::string &Filename);

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t SavePublic(TStream &F);

		virtual int32_t SavePublic(TStream *F);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t SavePublic(const std::string &Filename);

#ifdef SB_USE_CLASS_TELPKCS11MODULE
		virtual TElPKCS11Module* get_Module();

		SB_DECLARE_PROPERTY_GET(TElPKCS11Module*, get_Module, TElSSHPKCS11KeyStorage, Module);
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

		virtual bool get_Opened();

		SB_DECLARE_PROPERTY_GET(bool, get_Opened, TElSSHPKCS11KeyStorage, Opened);

		virtual void get_UniqueID(std::vector<uint8_t> &OutResult);

#ifndef SB_IOS
		virtual void get_DLLName(std::string &OutResult);
#else
#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER
		virtual TElPKCS11FunctionsManager* get_FunctionsManager();

		virtual void set_FunctionsManager(TElPKCS11FunctionsManager &Value);

		virtual void set_FunctionsManager(TElPKCS11FunctionsManager *Value);

		SB_DECLARE_PROPERTY(TElPKCS11FunctionsManager*, get_FunctionsManager, set_FunctionsManager, TElSSHPKCS11KeyStorage, FunctionsManager);
#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */
#endif

#ifndef SB_IOS
		virtual void set_DLLName(const std::string &Value);
#endif

		virtual bool get_TrySingleThreadedMode();

		virtual void set_TrySingleThreadedMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_TrySingleThreadedMode, set_TrySingleThreadedMode, TElSSHPKCS11KeyStorage, TrySingleThreadedMode);

		virtual bool get_MonitorSlotEvents();

		virtual void set_MonitorSlotEvents(bool Value);

		SB_DECLARE_PROPERTY(bool, get_MonitorSlotEvents, set_MonitorSlotEvents, TElSSHPKCS11KeyStorage, MonitorSlotEvents);

		virtual TSBPKCS11SlotEventMonitoringMode get_SlotEventMonitoringMode();

		virtual void set_SlotEventMonitoringMode(TSBPKCS11SlotEventMonitoringMode Value);

		SB_DECLARE_PROPERTY(TSBPKCS11SlotEventMonitoringMode, get_SlotEventMonitoringMode, set_SlotEventMonitoringMode, TElSSHPKCS11KeyStorage, SlotEventMonitoringMode);

		virtual int32_t get_SlotEventMonitoringDelay();

		virtual void set_SlotEventMonitoringDelay(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SlotEventMonitoringDelay, set_SlotEventMonitoringDelay, TElSSHPKCS11KeyStorage, SlotEventMonitoringDelay);

		virtual bool get_SynchronizeGUI();

		virtual void set_SynchronizeGUI(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SynchronizeGUI, set_SynchronizeGUI, TElSSHPKCS11KeyStorage, SynchronizeGUI);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		virtual TElCustomCryptoProvider* get_CryptoProvider();

		virtual void set_CryptoProvider(TElCustomCryptoProvider &Value);

		virtual void set_CryptoProvider(TElCustomCryptoProvider *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProvider*, get_CryptoProvider, set_CryptoProvider, TElSSHPKCS11KeyStorage, CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		virtual TSBPKCS11StorageOptions get_PKCS11Options();

		virtual void set_PKCS11Options(TSBPKCS11StorageOptions Value);

		SB_DECLARE_PROPERTY(TSBPKCS11StorageOptions, get_PKCS11Options, set_PKCS11Options, TElSSHPKCS11KeyStorage, PKCS11Options);

		virtual TSBPKCS11TokenAccessMode get_TokenAccessMode();

		virtual void set_TokenAccessMode(TSBPKCS11TokenAccessMode Value);

		SB_DECLARE_PROPERTY(TSBPKCS11TokenAccessMode, get_TokenAccessMode, set_TokenAccessMode, TElSSHPKCS11KeyStorage, TokenAccessMode);

#ifdef SB_USE_CLASS_TELPKCS11NSSPARAMS
		virtual TElPKCS11NSSParams* get_NSSParams();

		SB_DECLARE_PROPERTY_GET(TElPKCS11NSSParams*, get_NSSParams, TElSSHPKCS11KeyStorage, NSSParams);
#endif /* SB_USE_CLASS_TELPKCS11NSSPARAMS */

		virtual void get_OnSlotEvent(TElPKCSSlotEventEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSlotEvent(TElPKCSSlotEventEvent pMethodValue, void * pDataValue);

		virtual void get_OnNotification(TElPKCSNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnNotification(TElPKCSNotifyEvent pMethodValue, void * pDataValue);

		TElSSHPKCS11KeyStorage(TElSSHPKCS11KeyStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElSSHPKCS11KeyStorage(TComponent &AOwner);

		explicit TElSSHPKCS11KeyStorage(TComponent *AOwner);

		virtual ~TElSSHPKCS11KeyStorage();

};
#endif /* SB_USE_CLASS_TELSSHPKCS11KEYSTORAGE */

#ifdef SB_USE_CLASS_TELSSHPKCS11CONSUMERKEYSTORAGE
class TElSSHPKCS11ConsumerKeyStorage: public TElPKCS11Consumer
{
	private:
		SB_DISABLE_COPY(TElSSHPKCS11ConsumerKeyStorage)
	public:
		TElSSHPKCS11ConsumerKeyStorage(TElSSHPKCS11ConsumerKeyStorageHandle handle, TElOwnHandle ownHandle);

		TElSSHPKCS11ConsumerKeyStorage();

};
#endif /* SB_USE_CLASS_TELSSHPKCS11CONSUMERKEYSTORAGE */

#ifdef SB_USE_CLASS_TELPKCS11SSHKEY
class TElPKCS11SSHKey: public TElSSHKey
{
	private:
		SB_DISABLE_COPY(TElPKCS11SSHKey)
	public:
		virtual void Copy(TElSSHKey &Dest);

		virtual TElSSHKeyHandle Clone();

		virtual TElSSHKeyHandle CreateObjectInstance();

		virtual void Clear();

		virtual void get_KeyID(std::vector<uint8_t> &OutResult);

		TElPKCS11SSHKey(TElPKCS11SSHKeyHandle handle, TElOwnHandle ownHandle);

		TElPKCS11SSHKey();

};
#endif /* SB_USE_CLASS_TELPKCS11SSHKEY */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSSHPKCS11KEYSTORAGE */
