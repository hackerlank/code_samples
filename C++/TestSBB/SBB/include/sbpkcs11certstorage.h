#ifndef __INC_SBPKCS11CERTSTORAGE
#define __INC_SBPKCS11CERTSTORAGE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbrsa.h"
#include "sbdsa.h"
#include "sbasn1.h"
#include "sbpkcs11common.h"
#include "sbpkcs11base.h"
#include "sbpkcs8.h"
#include "sbcustomcertstorage.h"
#include "sbcustomcrypto.h"
#include "sbcryptoprov.h"
#include "sbcryptoprovutils.h"
#include "sbrdn.h"
#include "sbx509.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbrandom.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbsharedresource.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElPKCS11CertStorageHandle;

typedef TElPKCS11CertStorageHandle ElPKCS11CertStorageHandle;

typedef TElClassHandle TElPKCS11StgCtxHandle;

typedef TElPKCS11StgCtxHandle ElPKCS11StgCtxHandle;

typedef TElClassHandle TElPKCS11ConsumerCertStorageHandle;

typedef TElPKCS11ConsumerCertStorageHandle ElPKCS11ConsumerCertStorageHandle;

typedef uint8_t TSBPKCS11StgCtxTypeRaw;

typedef enum
{
	sctCertificate = 0,
	sctKey = 1
} TSBPKCS11StgCtxType;

typedef uint8_t TSBPKCS11CertStorageImportOrderRaw;

typedef enum
{
	csioAuto = 0,
	csioCertificateFirst = 1,
	csioKeyFirst = 2
} TSBPKCS11CertStorageImportOrder;

#ifdef SB_USE_CLASS_TELPKCS11CERTSTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_Add(TElPKCS11CertStorageHandle _Handle, TElX509CertificateHandle X509Certificate, int8_t CopyPrivateKey);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_Add_1(TElPKCS11CertStorageHandle _Handle, int32_t SessionIndex, TElX509CertificateHandle X509Certificate, int8_t CopyPrivateKey, int8_t Exportable);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_Add_2(TElPKCS11CertStorageHandle _Handle, int32_t SessionIndex, TElX509CertificateHandle X509Certificate, int8_t CopyPrivateKey, int8_t Exportable, const uint8_t pID[], int32_t szID, const uint8_t pKeyLabel[], int32_t szKeyLabel);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_AddKey(TElPKCS11CertStorageHandle _Handle, int32_t SessionIndex, TElKeyMaterialHandle KeyMaterial, int8_t CopyPrivateKey, int8_t Exportable, const uint8_t pID[], int32_t szID, const uint8_t pKeyLabel[], int32_t szKeyLabel, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_AddKey_1(TElPKCS11CertStorageHandle _Handle, TElKeyMaterialHandle KeyMaterial, int8_t CopyPrivateKey, int8_t Exportable, const uint8_t pID[], int32_t szID, const uint8_t pKeyLabel[], int32_t szKeyLabel, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_Close(TElPKCS11CertStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_CloseAllSessions(TElPKCS11CertStorageHandle _Handle, TElPKCS11SlotInfoHandle SlotInfo);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_Open(TElPKCS11CertStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_CloseSession(TElPKCS11CertStorageHandle _Handle, int32_t SessionIndex);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_CloseSession_1(TElPKCS11CertStorageHandle _Handle, TElPKCS11SessionInfoHandle Session);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_OpenSession(TElPKCS11CertStorageHandle _Handle, int32_t SlotIndex, int8_t ReadOnly, TElPKCS11SessionInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_RefreshObjectList(TElPKCS11CertStorageHandle _Handle, int32_t SessionIndex);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_RefreshCertificateContexts(TElPKCS11CertStorageHandle _Handle, TElPKCS11SessionInfoHandle SessionInfo);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_UpdateCertificateContexts(TElPKCS11CertStorageHandle _Handle, TElPKCS11SessionInfoHandle SessionInfo);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_Remove(TElPKCS11CertStorageHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_RemoveKey(TElPKCS11CertStorageHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_AddObject(TElPKCS11CertStorageHandle _Handle, TSBPKCS11ObjectTypeRaw ObjectType, int8_t Token, int8_t Private, int8_t Modifiable, TElPKCS11AttributeListHandle Attributes, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_AddObject_1(TElPKCS11CertStorageHandle _Handle, int32_t SessionIndex, TSBPKCS11ObjectTypeRaw ObjectType, int8_t Token, int8_t Private, int8_t Modifiable, TElPKCS11AttributeListHandle Attributes, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_RemoveObject(TElPKCS11CertStorageHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_RemoveObject_1(TElPKCS11CertStorageHandle _Handle, TElPKCS11ObjectHandle Obj);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_ClearObjects(TElPKCS11CertStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_CopyObject(TElPKCS11CertStorageHandle _Handle, int32_t Index, int8_t Token, int8_t Private, int8_t Modifiable, TElPKCS11AttributeListHandle Attributes, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_CopyObject_1(TElPKCS11CertStorageHandle _Handle, TElPKCS11ObjectHandle Obj, int8_t Token, int8_t Private, int8_t Modifiable, TElPKCS11AttributeListHandle Attributes, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_GetObjects(TElPKCS11CertStorageHandle _Handle, int32_t CertIndex, TElPKCS11X509CertificateObjectHandle * CertObject, TElPKCS11PrivateKeyObjectHandle * PrivKeyObject, TElPKCS11PublicKeyObjectHandle * PubKeyObject);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_Certificates(TElPKCS11CertStorageHandle _Handle, int32_t Index, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_Keys(TElPKCS11CertStorageHandle _Handle, int32_t Index, TElKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_KeyIDs(TElPKCS11CertStorageHandle _Handle, int32_t Index, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_set_KeyIDs(TElPKCS11CertStorageHandle _Handle, int32_t Index, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_Session(TElPKCS11CertStorageHandle _Handle, int32_t Index, TElPKCS11SessionInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_Objects(TElPKCS11CertStorageHandle _Handle, int32_t Index, TElPKCS11ObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_Count(TElPKCS11CertStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_KeyCount(TElPKCS11CertStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_ObjectCount(TElPKCS11CertStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_SessionCount(TElPKCS11CertStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_UniqueID(TElPKCS11CertStorageHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_Module(TElPKCS11CertStorageHandle _Handle, TElPKCS11ModuleHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_Opened(TElPKCS11CertStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_TrySingleThreadedMode(TElPKCS11CertStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_set_TrySingleThreadedMode(TElPKCS11CertStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_MonitorSlotEvents(TElPKCS11CertStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_set_MonitorSlotEvents(TElPKCS11CertStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_SlotEventMonitoringMode(TElPKCS11CertStorageHandle _Handle, TSBPKCS11SlotEventMonitoringModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_set_SlotEventMonitoringMode(TElPKCS11CertStorageHandle _Handle, TSBPKCS11SlotEventMonitoringModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_SlotEventMonitoringDelay(TElPKCS11CertStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_set_SlotEventMonitoringDelay(TElPKCS11CertStorageHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_SynchronizeGUI(TElPKCS11CertStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_set_SynchronizeGUI(TElPKCS11CertStorageHandle _Handle, int8_t Value);
#ifndef SB_IOS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_DLLName(TElPKCS11CertStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_set_DLLName(TElPKCS11CertStorageHandle _Handle, const char * pcValue, int32_t szValue);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_FunctionsManager(TElPKCS11CertStorageHandle _Handle, TElPKCS11FunctionsManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_set_FunctionsManager(TElPKCS11CertStorageHandle _Handle, TElPKCS11FunctionsManagerHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_CryptoProvider(TElPKCS11CertStorageHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_set_CryptoProvider(TElPKCS11CertStorageHandle _Handle, TElCustomCryptoProviderHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_PKCS11Options(TElPKCS11CertStorageHandle _Handle, TSBPKCS11StorageOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_set_PKCS11Options(TElPKCS11CertStorageHandle _Handle, TSBPKCS11StorageOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_TokenAccessMode(TElPKCS11CertStorageHandle _Handle, TSBPKCS11TokenAccessModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_set_TokenAccessMode(TElPKCS11CertStorageHandle _Handle, TSBPKCS11TokenAccessModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_ImportOrder(TElPKCS11CertStorageHandle _Handle, TSBPKCS11CertStorageImportOrderRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_set_ImportOrder(TElPKCS11CertStorageHandle _Handle, TSBPKCS11CertStorageImportOrderRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_NSSParams(TElPKCS11CertStorageHandle _Handle, TElPKCS11NSSParamsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_OnNotification(TElPKCS11CertStorageHandle _Handle, TElPKCSNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_set_OnNotification(TElPKCS11CertStorageHandle _Handle, TElPKCSNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_get_OnSlotEvent(TElPKCS11CertStorageHandle _Handle, TElPKCSSlotEventEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_set_OnSlotEvent(TElPKCS11CertStorageHandle _Handle, TElPKCSSlotEventEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertStorage_Create(TComponentHandle Owner, TElPKCS11CertStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11CERTSTORAGE */

#ifdef SB_USE_CLASS_TELPKCS11STGCTX
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11StgCtx_SetCertStorageName(TElPKCS11StgCtxHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11StgCtx_Create(TElPKCS11StgCtxHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11STGCTX */

#ifdef SB_USE_CLASS_TELPKCS11CONSUMERCERTSTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ConsumerCertStorage_Create(TElPKCS11ConsumerHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11CONSUMERCERTSTORAGE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPKCS11CertStorage;
typedef TElPKCS11CertStorage ElPKCS11CertStorage;
class TElPKCS11StgCtx;
typedef TElPKCS11StgCtx ElPKCS11StgCtx;
class TElPKCS11ConsumerCertStorage;
typedef TElPKCS11ConsumerCertStorage ElPKCS11ConsumerCertStorage;

#ifdef SB_USE_CLASS_TELPKCS11CERTSTORAGE
class TElPKCS11CertStorage: public TElCustomCertStorage
{
	private:
		SB_DISABLE_COPY(TElPKCS11CertStorage)
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_Certificates;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELKEYMATERIAL
		TElKeyMaterial* _Inst_Keys;
#endif /* SB_USE_CLASS_TELKEYMATERIAL */
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfo* _Inst_Session;
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */
#ifdef SB_USE_CLASS_TELPKCS11OBJECT
		TElPKCS11Object* _Inst_Objects;
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */
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
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual void Add(TElX509Certificate &X509Certificate, bool CopyPrivateKey);

		virtual void Add(TElX509Certificate *X509Certificate, bool CopyPrivateKey);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		void Add(int32_t SessionIndex, TElX509Certificate &X509Certificate, bool CopyPrivateKey, bool Exportable);

		void Add(int32_t SessionIndex, TElX509Certificate *X509Certificate, bool CopyPrivateKey, bool Exportable);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		void Add(int32_t SessionIndex, TElX509Certificate &X509Certificate, bool CopyPrivateKey, bool Exportable, const std::vector<uint8_t> &ID, const std::vector<uint8_t> &KeyLabel);

		void Add(int32_t SessionIndex, TElX509Certificate *X509Certificate, bool CopyPrivateKey, bool Exportable, const std::vector<uint8_t> &ID, const std::vector<uint8_t> &KeyLabel);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELKEYMATERIAL
		int32_t AddKey(int32_t SessionIndex, TElKeyMaterial &KeyMaterial, bool CopyPrivateKey, bool Exportable, const std::vector<uint8_t> &ID, const std::vector<uint8_t> &KeyLabel);

		int32_t AddKey(int32_t SessionIndex, TElKeyMaterial *KeyMaterial, bool CopyPrivateKey, bool Exportable, const std::vector<uint8_t> &ID, const std::vector<uint8_t> &KeyLabel);
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

#ifdef SB_USE_CLASS_TELKEYMATERIAL
		int32_t AddKey(TElKeyMaterial &KeyMaterial, bool CopyPrivateKey, bool Exportable, const std::vector<uint8_t> &ID, const std::vector<uint8_t> &KeyLabel);

		int32_t AddKey(TElKeyMaterial *KeyMaterial, bool CopyPrivateKey, bool Exportable, const std::vector<uint8_t> &ID, const std::vector<uint8_t> &KeyLabel);
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

		void Close();

#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
		void CloseAllSessions(TElPKCS11SlotInfo &SlotInfo);

		void CloseAllSessions(TElPKCS11SlotInfo *SlotInfo);
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */

		void Open();

		void CloseSession(int32_t SessionIndex);

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		void CloseSession(TElPKCS11SessionInfo &Session);

		void CloseSession(TElPKCS11SessionInfo *Session);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfoHandle OpenSession(int32_t SlotIndex, bool ReadOnly);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

		void RefreshObjectList(int32_t SessionIndex);

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		void RefreshCertificateContexts(TElPKCS11SessionInfo &SessionInfo);

		void RefreshCertificateContexts(TElPKCS11SessionInfo *SessionInfo);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		void UpdateCertificateContexts(TElPKCS11SessionInfo &SessionInfo);

		void UpdateCertificateContexts(TElPKCS11SessionInfo *SessionInfo);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

		virtual void Remove(int32_t Index);

		void RemoveKey(int32_t Index);

#ifdef SB_USE_CLASS_TELPKCS11ATTRIBUTELIST
		int32_t AddObject(TSBPKCS11ObjectType ObjectType, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList &Attributes);

		int32_t AddObject(TSBPKCS11ObjectType ObjectType, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList *Attributes);
#endif /* SB_USE_CLASS_TELPKCS11ATTRIBUTELIST */

#ifdef SB_USE_CLASS_TELPKCS11ATTRIBUTELIST
		int32_t AddObject(int32_t SessionIndex, TSBPKCS11ObjectType ObjectType, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList &Attributes);

		int32_t AddObject(int32_t SessionIndex, TSBPKCS11ObjectType ObjectType, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList *Attributes);
#endif /* SB_USE_CLASS_TELPKCS11ATTRIBUTELIST */

		void RemoveObject(int32_t Index);

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
		void RemoveObject(TElPKCS11Object &Obj);

		void RemoveObject(TElPKCS11Object *Obj);
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

		void ClearObjects();

#ifdef SB_USE_CLASS_TELPKCS11ATTRIBUTELIST
		int32_t CopyObject(int32_t Index, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList &Attributes);

		int32_t CopyObject(int32_t Index, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList *Attributes);
#endif /* SB_USE_CLASS_TELPKCS11ATTRIBUTELIST */

#ifdef SB_USE_CLASSES_TELPKCS11ATTRIBUTELIST_AND_TELPKCS11OBJECT
		int32_t CopyObject(TElPKCS11Object &Obj, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList &Attributes);

		int32_t CopyObject(TElPKCS11Object *Obj, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList *Attributes);
#endif /* SB_USE_CLASSES_TELPKCS11ATTRIBUTELIST_AND_TELPKCS11OBJECT */

#ifdef SB_USE_CLASSES_TELPKCS11PRIVATEKEYOBJECT_AND_TELPKCS11PUBLICKEYOBJECT_AND_TELPKCS11X509CERTIFICATEOBJECT
		void GetObjects(int32_t CertIndex, TElPKCS11X509CertificateObject &CertObject, TElPKCS11PrivateKeyObject &PrivKeyObject, TElPKCS11PublicKeyObject &PubKeyObject);
#endif /* SB_USE_CLASSES_TELPKCS11PRIVATEKEYOBJECT_AND_TELPKCS11PUBLICKEYOBJECT_AND_TELPKCS11X509CERTIFICATEOBJECT */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_Certificates(int32_t Index);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELKEYMATERIAL
		virtual TElKeyMaterial* get_Keys(int32_t Index);
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

		virtual void get_KeyIDs(int32_t Index, std::vector<uint8_t> &OutResult);

		virtual void set_KeyIDs(int32_t Index, const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		virtual TElPKCS11SessionInfo* get_Session(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
		virtual TElPKCS11Object* get_Objects(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElPKCS11CertStorage, Count);

		virtual int32_t get_KeyCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_KeyCount, TElPKCS11CertStorage, KeyCount);

		virtual int32_t get_ObjectCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ObjectCount, TElPKCS11CertStorage, ObjectCount);

		virtual int32_t get_SessionCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SessionCount, TElPKCS11CertStorage, SessionCount);

		virtual void get_UniqueID(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELPKCS11MODULE
		virtual TElPKCS11Module* get_Module();

		SB_DECLARE_PROPERTY_GET(TElPKCS11Module*, get_Module, TElPKCS11CertStorage, Module);
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

		virtual bool get_Opened();

		SB_DECLARE_PROPERTY_GET(bool, get_Opened, TElPKCS11CertStorage, Opened);

		virtual bool get_TrySingleThreadedMode();

		virtual void set_TrySingleThreadedMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_TrySingleThreadedMode, set_TrySingleThreadedMode, TElPKCS11CertStorage, TrySingleThreadedMode);

		virtual bool get_MonitorSlotEvents();

		virtual void set_MonitorSlotEvents(bool Value);

		SB_DECLARE_PROPERTY(bool, get_MonitorSlotEvents, set_MonitorSlotEvents, TElPKCS11CertStorage, MonitorSlotEvents);

		virtual TSBPKCS11SlotEventMonitoringMode get_SlotEventMonitoringMode();

		virtual void set_SlotEventMonitoringMode(TSBPKCS11SlotEventMonitoringMode Value);

		SB_DECLARE_PROPERTY(TSBPKCS11SlotEventMonitoringMode, get_SlotEventMonitoringMode, set_SlotEventMonitoringMode, TElPKCS11CertStorage, SlotEventMonitoringMode);

		virtual int32_t get_SlotEventMonitoringDelay();

		virtual void set_SlotEventMonitoringDelay(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SlotEventMonitoringDelay, set_SlotEventMonitoringDelay, TElPKCS11CertStorage, SlotEventMonitoringDelay);

		virtual bool get_SynchronizeGUI();

		virtual void set_SynchronizeGUI(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SynchronizeGUI, set_SynchronizeGUI, TElPKCS11CertStorage, SynchronizeGUI);

#ifndef SB_IOS
		virtual void get_DLLName(std::string &OutResult);
#else
#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER
		virtual TElPKCS11FunctionsManager* get_FunctionsManager();

		virtual void set_FunctionsManager(TElPKCS11FunctionsManager &Value);

		virtual void set_FunctionsManager(TElPKCS11FunctionsManager *Value);

		SB_DECLARE_PROPERTY(TElPKCS11FunctionsManager*, get_FunctionsManager, set_FunctionsManager, TElPKCS11CertStorage, FunctionsManager);
#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */
#endif

#ifndef SB_IOS
		virtual void set_DLLName(const std::string &Value);
#endif

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		virtual TElCustomCryptoProvider* get_CryptoProvider();

		virtual void set_CryptoProvider(TElCustomCryptoProvider &Value);

		virtual void set_CryptoProvider(TElCustomCryptoProvider *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProvider*, get_CryptoProvider, set_CryptoProvider, TElPKCS11CertStorage, CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		virtual TSBPKCS11StorageOptions get_PKCS11Options();

		virtual void set_PKCS11Options(TSBPKCS11StorageOptions Value);

		SB_DECLARE_PROPERTY(TSBPKCS11StorageOptions, get_PKCS11Options, set_PKCS11Options, TElPKCS11CertStorage, PKCS11Options);

		virtual TSBPKCS11TokenAccessMode get_TokenAccessMode();

		virtual void set_TokenAccessMode(TSBPKCS11TokenAccessMode Value);

		SB_DECLARE_PROPERTY(TSBPKCS11TokenAccessMode, get_TokenAccessMode, set_TokenAccessMode, TElPKCS11CertStorage, TokenAccessMode);

		virtual TSBPKCS11CertStorageImportOrder get_ImportOrder();

		virtual void set_ImportOrder(TSBPKCS11CertStorageImportOrder Value);

		SB_DECLARE_PROPERTY(TSBPKCS11CertStorageImportOrder, get_ImportOrder, set_ImportOrder, TElPKCS11CertStorage, ImportOrder);

#ifdef SB_USE_CLASS_TELPKCS11NSSPARAMS
		virtual TElPKCS11NSSParams* get_NSSParams();

		SB_DECLARE_PROPERTY_GET(TElPKCS11NSSParams*, get_NSSParams, TElPKCS11CertStorage, NSSParams);
#endif /* SB_USE_CLASS_TELPKCS11NSSPARAMS */

		virtual void get_OnNotification(TElPKCSNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnNotification(TElPKCSNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnSlotEvent(TElPKCSSlotEventEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSlotEvent(TElPKCSSlotEventEvent pMethodValue, void * pDataValue);

		TElPKCS11CertStorage(TElPKCS11CertStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElPKCS11CertStorage(TComponent &Owner);

		explicit TElPKCS11CertStorage(TComponent *Owner);

		virtual ~TElPKCS11CertStorage();

};
#endif /* SB_USE_CLASS_TELPKCS11CERTSTORAGE */

#ifdef SB_USE_CLASS_TELPKCS11STGCTX
class TElPKCS11StgCtx: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11StgCtx)
	public:
		void SetCertStorageName();

		TElPKCS11StgCtx(TElPKCS11StgCtxHandle handle, TElOwnHandle ownHandle);

		TElPKCS11StgCtx();

};
#endif /* SB_USE_CLASS_TELPKCS11STGCTX */

#ifdef SB_USE_CLASS_TELPKCS11CONSUMERCERTSTORAGE
class TElPKCS11ConsumerCertStorage: public TElPKCS11Consumer
{
	private:
		SB_DISABLE_COPY(TElPKCS11ConsumerCertStorage)
	public:
		TElPKCS11ConsumerCertStorage(TElPKCS11ConsumerCertStorageHandle handle, TElOwnHandle ownHandle);

		TElPKCS11ConsumerCertStorage();

};
#endif /* SB_USE_CLASS_TELPKCS11CONSUMERCERTSTORAGE */

#ifdef SB_USE_GLOBAL_PROCS_PKCS11CERTSTORAGE

#ifdef SB_USE_CLASSES_TELPKCS11STGCTX_AND_TELX509CERTIFICATE
TElPKCS11StgCtxHandle GetContextByCertificate(TElX509Certificate &Cert);
TElPKCS11StgCtxHandle GetContextByCertificate(TElX509Certificate *Cert);
#endif /* SB_USE_CLASSES_TELPKCS11STGCTX_AND_TELX509CERTIFICATE */

#endif /* SB_USE_GLOBAL_PROCS_PKCS11CERTSTORAGE */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_PKCS11CERTSTORAGE
SB_IMPORT uint32_t SB_APIENTRY SBPKCS11CertStorage_GetContextByCertificate(TElX509CertificateHandle Cert, TElPKCS11StgCtxHandle * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_PKCS11CERTSTORAGE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPKCS11CERTSTORAGE */
