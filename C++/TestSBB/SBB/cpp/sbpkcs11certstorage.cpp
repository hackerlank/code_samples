#include "sbpkcs11certstorage.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPKCS11CERTSTORAGE

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElPKCS11CertStorage::Add(TElX509Certificate &X509Certificate, bool CopyPrivateKey)
{
	SBCheckError(TElPKCS11CertStorage_Add(_Handle, X509Certificate.getHandle(), (int8_t)CopyPrivateKey));
}

SB_INLINE void TElPKCS11CertStorage::Add(TElX509Certificate *X509Certificate, bool CopyPrivateKey)
{
	SBCheckError(TElPKCS11CertStorage_Add(_Handle, (X509Certificate != NULL) ? X509Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)CopyPrivateKey));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElPKCS11CertStorage::Add(int32_t SessionIndex, TElX509Certificate &X509Certificate, bool CopyPrivateKey, bool Exportable)
{
	SBCheckError(TElPKCS11CertStorage_Add_1(_Handle, SessionIndex, X509Certificate.getHandle(), (int8_t)CopyPrivateKey, (int8_t)Exportable));
}

SB_INLINE void TElPKCS11CertStorage::Add(int32_t SessionIndex, TElX509Certificate *X509Certificate, bool CopyPrivateKey, bool Exportable)
{
	SBCheckError(TElPKCS11CertStorage_Add_1(_Handle, SessionIndex, (X509Certificate != NULL) ? X509Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)CopyPrivateKey, (int8_t)Exportable));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElPKCS11CertStorage::Add(int32_t SessionIndex, TElX509Certificate &X509Certificate, bool CopyPrivateKey, bool Exportable, const std::vector<uint8_t> &ID, const std::vector<uint8_t> &KeyLabel)
{
	SBCheckError(TElPKCS11CertStorage_Add_2(_Handle, SessionIndex, X509Certificate.getHandle(), (int8_t)CopyPrivateKey, (int8_t)Exportable, SB_STD_VECTOR_FRONT_ADR(ID), (int32_t)ID.size(), SB_STD_VECTOR_FRONT_ADR(KeyLabel), (int32_t)KeyLabel.size()));
}

SB_INLINE void TElPKCS11CertStorage::Add(int32_t SessionIndex, TElX509Certificate *X509Certificate, bool CopyPrivateKey, bool Exportable, const std::vector<uint8_t> &ID, const std::vector<uint8_t> &KeyLabel)
{
	SBCheckError(TElPKCS11CertStorage_Add_2(_Handle, SessionIndex, (X509Certificate != NULL) ? X509Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)CopyPrivateKey, (int8_t)Exportable, SB_STD_VECTOR_FRONT_ADR(ID), (int32_t)ID.size(), SB_STD_VECTOR_FRONT_ADR(KeyLabel), (int32_t)KeyLabel.size()));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELKEYMATERIAL
SB_INLINE int32_t TElPKCS11CertStorage::AddKey(int32_t SessionIndex, TElKeyMaterial &KeyMaterial, bool CopyPrivateKey, bool Exportable, const std::vector<uint8_t> &ID, const std::vector<uint8_t> &KeyLabel)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11CertStorage_AddKey(_Handle, SessionIndex, KeyMaterial.getHandle(), (int8_t)CopyPrivateKey, (int8_t)Exportable, SB_STD_VECTOR_FRONT_ADR(ID), (int32_t)ID.size(), SB_STD_VECTOR_FRONT_ADR(KeyLabel), (int32_t)KeyLabel.size(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11CertStorage::AddKey(int32_t SessionIndex, TElKeyMaterial *KeyMaterial, bool CopyPrivateKey, bool Exportable, const std::vector<uint8_t> &ID, const std::vector<uint8_t> &KeyLabel)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11CertStorage_AddKey(_Handle, SessionIndex, (KeyMaterial != NULL) ? KeyMaterial->getHandle() : SB_NULL_HANDLE, (int8_t)CopyPrivateKey, (int8_t)Exportable, SB_STD_VECTOR_FRONT_ADR(ID), (int32_t)ID.size(), SB_STD_VECTOR_FRONT_ADR(KeyLabel), (int32_t)KeyLabel.size(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

#ifdef SB_USE_CLASS_TELKEYMATERIAL
SB_INLINE int32_t TElPKCS11CertStorage::AddKey(TElKeyMaterial &KeyMaterial, bool CopyPrivateKey, bool Exportable, const std::vector<uint8_t> &ID, const std::vector<uint8_t> &KeyLabel)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11CertStorage_AddKey_1(_Handle, KeyMaterial.getHandle(), (int8_t)CopyPrivateKey, (int8_t)Exportable, SB_STD_VECTOR_FRONT_ADR(ID), (int32_t)ID.size(), SB_STD_VECTOR_FRONT_ADR(KeyLabel), (int32_t)KeyLabel.size(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11CertStorage::AddKey(TElKeyMaterial *KeyMaterial, bool CopyPrivateKey, bool Exportable, const std::vector<uint8_t> &ID, const std::vector<uint8_t> &KeyLabel)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11CertStorage_AddKey_1(_Handle, (KeyMaterial != NULL) ? KeyMaterial->getHandle() : SB_NULL_HANDLE, (int8_t)CopyPrivateKey, (int8_t)Exportable, SB_STD_VECTOR_FRONT_ADR(ID), (int32_t)ID.size(), SB_STD_VECTOR_FRONT_ADR(KeyLabel), (int32_t)KeyLabel.size(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

SB_INLINE void TElPKCS11CertStorage::Close()
{
	SBCheckError(TElPKCS11CertStorage_Close(_Handle));
}

#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
SB_INLINE void TElPKCS11CertStorage::CloseAllSessions(TElPKCS11SlotInfo &SlotInfo)
{
	SBCheckError(TElPKCS11CertStorage_CloseAllSessions(_Handle, SlotInfo.getHandle()));
}

SB_INLINE void TElPKCS11CertStorage::CloseAllSessions(TElPKCS11SlotInfo *SlotInfo)
{
	SBCheckError(TElPKCS11CertStorage_CloseAllSessions(_Handle, (SlotInfo != NULL) ? SlotInfo->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */

SB_INLINE void TElPKCS11CertStorage::Open()
{
	SBCheckError(TElPKCS11CertStorage_Open(_Handle));
}

SB_INLINE void TElPKCS11CertStorage::CloseSession(int32_t SessionIndex)
{
	SBCheckError(TElPKCS11CertStorage_CloseSession(_Handle, SessionIndex));
}

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
SB_INLINE void TElPKCS11CertStorage::CloseSession(TElPKCS11SessionInfo &Session)
{
	SBCheckError(TElPKCS11CertStorage_CloseSession_1(_Handle, Session.getHandle()));
}

SB_INLINE void TElPKCS11CertStorage::CloseSession(TElPKCS11SessionInfo *Session)
{
	SBCheckError(TElPKCS11CertStorage_CloseSession_1(_Handle, (Session != NULL) ? Session->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11CertStorage::OpenSession(int32_t SlotIndex, bool ReadOnly)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11CertStorage_OpenSession(_Handle, SlotIndex, (int8_t)ReadOnly, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

SB_INLINE void TElPKCS11CertStorage::RefreshObjectList(int32_t SessionIndex)
{
	SBCheckError(TElPKCS11CertStorage_RefreshObjectList(_Handle, SessionIndex));
}

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
SB_INLINE void TElPKCS11CertStorage::RefreshCertificateContexts(TElPKCS11SessionInfo &SessionInfo)
{
	SBCheckError(TElPKCS11CertStorage_RefreshCertificateContexts(_Handle, SessionInfo.getHandle()));
}

SB_INLINE void TElPKCS11CertStorage::RefreshCertificateContexts(TElPKCS11SessionInfo *SessionInfo)
{
	SBCheckError(TElPKCS11CertStorage_RefreshCertificateContexts(_Handle, (SessionInfo != NULL) ? SessionInfo->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
SB_INLINE void TElPKCS11CertStorage::UpdateCertificateContexts(TElPKCS11SessionInfo &SessionInfo)
{
	SBCheckError(TElPKCS11CertStorage_UpdateCertificateContexts(_Handle, SessionInfo.getHandle()));
}

SB_INLINE void TElPKCS11CertStorage::UpdateCertificateContexts(TElPKCS11SessionInfo *SessionInfo)
{
	SBCheckError(TElPKCS11CertStorage_UpdateCertificateContexts(_Handle, (SessionInfo != NULL) ? SessionInfo->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

SB_INLINE void TElPKCS11CertStorage::Remove(int32_t Index)
{
	SBCheckError(TElPKCS11CertStorage_Remove(_Handle, Index));
}

SB_INLINE void TElPKCS11CertStorage::RemoveKey(int32_t Index)
{
	SBCheckError(TElPKCS11CertStorage_RemoveKey(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELPKCS11ATTRIBUTELIST
SB_INLINE int32_t TElPKCS11CertStorage::AddObject(TSBPKCS11ObjectType ObjectType, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList &Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11CertStorage_AddObject(_Handle, (TSBPKCS11ObjectTypeRaw)ObjectType, (int8_t)Token, (int8_t)Private, (int8_t)Modifiable, Attributes.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11CertStorage::AddObject(TSBPKCS11ObjectType ObjectType, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList *Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11CertStorage_AddObject(_Handle, (TSBPKCS11ObjectTypeRaw)ObjectType, (int8_t)Token, (int8_t)Private, (int8_t)Modifiable, (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11ATTRIBUTELIST */

#ifdef SB_USE_CLASS_TELPKCS11ATTRIBUTELIST
SB_INLINE int32_t TElPKCS11CertStorage::AddObject(int32_t SessionIndex, TSBPKCS11ObjectType ObjectType, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList &Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11CertStorage_AddObject_1(_Handle, SessionIndex, (TSBPKCS11ObjectTypeRaw)ObjectType, (int8_t)Token, (int8_t)Private, (int8_t)Modifiable, Attributes.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11CertStorage::AddObject(int32_t SessionIndex, TSBPKCS11ObjectType ObjectType, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList *Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11CertStorage_AddObject_1(_Handle, SessionIndex, (TSBPKCS11ObjectTypeRaw)ObjectType, (int8_t)Token, (int8_t)Private, (int8_t)Modifiable, (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11ATTRIBUTELIST */

SB_INLINE void TElPKCS11CertStorage::RemoveObject(int32_t Index)
{
	SBCheckError(TElPKCS11CertStorage_RemoveObject(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
SB_INLINE void TElPKCS11CertStorage::RemoveObject(TElPKCS11Object &Obj)
{
	SBCheckError(TElPKCS11CertStorage_RemoveObject_1(_Handle, Obj.getHandle()));
}

SB_INLINE void TElPKCS11CertStorage::RemoveObject(TElPKCS11Object *Obj)
{
	SBCheckError(TElPKCS11CertStorage_RemoveObject_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

SB_INLINE void TElPKCS11CertStorage::ClearObjects()
{
	SBCheckError(TElPKCS11CertStorage_ClearObjects(_Handle));
}

#ifdef SB_USE_CLASS_TELPKCS11ATTRIBUTELIST
SB_INLINE int32_t TElPKCS11CertStorage::CopyObject(int32_t Index, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList &Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11CertStorage_CopyObject(_Handle, Index, (int8_t)Token, (int8_t)Private, (int8_t)Modifiable, Attributes.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11CertStorage::CopyObject(int32_t Index, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList *Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11CertStorage_CopyObject(_Handle, Index, (int8_t)Token, (int8_t)Private, (int8_t)Modifiable, (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11ATTRIBUTELIST */

#ifdef SB_USE_CLASSES_TELPKCS11ATTRIBUTELIST_AND_TELPKCS11OBJECT
SB_INLINE int32_t TElPKCS11CertStorage::CopyObject(TElPKCS11Object &Obj, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList &Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11CertStorage_CopyObject_1(_Handle, Obj.getHandle(), (int8_t)Token, (int8_t)Private, (int8_t)Modifiable, Attributes.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11CertStorage::CopyObject(TElPKCS11Object *Obj, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList *Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11CertStorage_CopyObject_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (int8_t)Token, (int8_t)Private, (int8_t)Modifiable, (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPKCS11ATTRIBUTELIST_AND_TELPKCS11OBJECT */

#ifdef SB_USE_CLASSES_TELPKCS11PRIVATEKEYOBJECT_AND_TELPKCS11PUBLICKEYOBJECT_AND_TELPKCS11X509CERTIFICATEOBJECT
void TElPKCS11CertStorage::GetObjects(int32_t CertIndex, TElPKCS11X509CertificateObject &CertObject, TElPKCS11PrivateKeyObject &PrivKeyObject, TElPKCS11PublicKeyObject &PubKeyObject)
{
	TElClassHandle hCertObject = CertObject.getHandle();
	TElClassHandle hPrivKeyObject = PrivKeyObject.getHandle();
	TElClassHandle hPubKeyObject = PubKeyObject.getHandle();
	SBCheckError(TElPKCS11CertStorage_GetObjects(_Handle, CertIndex, &hCertObject, &hPrivKeyObject, &hPubKeyObject));
	CertObject.updateHandle(hCertObject);
	PrivKeyObject.updateHandle(hPrivKeyObject);
	PubKeyObject.updateHandle(hPubKeyObject);
}
#endif /* SB_USE_CLASSES_TELPKCS11PRIVATEKEYOBJECT_AND_TELPKCS11PUBLICKEYOBJECT_AND_TELPKCS11X509CERTIFICATEOBJECT */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElPKCS11CertStorage::get_Certificates(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11CertStorage_get_Certificates(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELKEYMATERIAL
TElKeyMaterial* TElPKCS11CertStorage::get_Keys(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11CertStorage_get_Keys(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Keys)
		this->_Inst_Keys = new TElKeyMaterial(hOutResult, ohFalse);
	else
		this->_Inst_Keys->updateHandle(hOutResult);
	return this->_Inst_Keys;
}
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

void TElPKCS11CertStorage::get_KeyIDs(int32_t Index, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11CertStorage_get_KeyIDs(_Handle, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2000849451, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11CertStorage::set_KeyIDs(int32_t Index, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11CertStorage_set_KeyIDs(_Handle, Index, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
TElPKCS11SessionInfo* TElPKCS11CertStorage::get_Session(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11CertStorage_get_Session(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Session)
		this->_Inst_Session = new TElPKCS11SessionInfo(hOutResult, ohFalse);
	else
		this->_Inst_Session->updateHandle(hOutResult);
	return this->_Inst_Session;
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
TElPKCS11Object* TElPKCS11CertStorage::get_Objects(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11CertStorage_get_Objects(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Objects)
		this->_Inst_Objects = new TElPKCS11Object(hOutResult, ohFalse);
	else
		this->_Inst_Objects->updateHandle(hOutResult);
	return this->_Inst_Objects;
}
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

SB_INLINE int32_t TElPKCS11CertStorage::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11CertStorage_get_Count(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11CertStorage::get_KeyCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11CertStorage_get_KeyCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11CertStorage::get_ObjectCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11CertStorage_get_ObjectCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11CertStorage::get_SessionCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11CertStorage_get_SessionCount(_Handle, &OutResult));
	return OutResult;
}

void TElPKCS11CertStorage::get_UniqueID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11CertStorage_get_UniqueID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1117642878, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELPKCS11MODULE
TElPKCS11Module* TElPKCS11CertStorage::get_Module()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11CertStorage_get_Module(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Module)
		this->_Inst_Module = new TElPKCS11Module(hOutResult, ohFalse);
	else
		this->_Inst_Module->updateHandle(hOutResult);
	return this->_Inst_Module;
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

bool TElPKCS11CertStorage::get_Opened()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11CertStorage_get_Opened(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11CertStorage::get_TrySingleThreadedMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11CertStorage_get_TrySingleThreadedMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11CertStorage::set_TrySingleThreadedMode(bool Value)
{
	SBCheckError(TElPKCS11CertStorage_set_TrySingleThreadedMode(_Handle, (int8_t)Value));
}

bool TElPKCS11CertStorage::get_MonitorSlotEvents()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11CertStorage_get_MonitorSlotEvents(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11CertStorage::set_MonitorSlotEvents(bool Value)
{
	SBCheckError(TElPKCS11CertStorage_set_MonitorSlotEvents(_Handle, (int8_t)Value));
}

TSBPKCS11SlotEventMonitoringMode TElPKCS11CertStorage::get_SlotEventMonitoringMode()
{
	TSBPKCS11SlotEventMonitoringModeRaw OutResultRaw = 0;
	SBCheckError(TElPKCS11CertStorage_get_SlotEventMonitoringMode(_Handle, &OutResultRaw));
	return (TSBPKCS11SlotEventMonitoringMode)OutResultRaw;
}

SB_INLINE void TElPKCS11CertStorage::set_SlotEventMonitoringMode(TSBPKCS11SlotEventMonitoringMode Value)
{
	SBCheckError(TElPKCS11CertStorage_set_SlotEventMonitoringMode(_Handle, (TSBPKCS11SlotEventMonitoringModeRaw)Value));
}

SB_INLINE int32_t TElPKCS11CertStorage::get_SlotEventMonitoringDelay()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11CertStorage_get_SlotEventMonitoringDelay(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS11CertStorage::set_SlotEventMonitoringDelay(int32_t Value)
{
	SBCheckError(TElPKCS11CertStorage_set_SlotEventMonitoringDelay(_Handle, Value));
}

bool TElPKCS11CertStorage::get_SynchronizeGUI()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11CertStorage_get_SynchronizeGUI(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11CertStorage::set_SynchronizeGUI(bool Value)
{
	SBCheckError(TElPKCS11CertStorage_set_SynchronizeGUI(_Handle, (int8_t)Value));
}

#ifndef SB_IOS
void TElPKCS11CertStorage::get_DLLName(std::string &OutResult)
#else
#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER
TElPKCS11FunctionsManager* TElPKCS11CertStorage::get_FunctionsManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11CertStorage_get_FunctionsManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FunctionsManager)
		this->_Inst_FunctionsManager = new TElPKCS11FunctionsManager(hOutResult, ohFalse);
	else
		this->_Inst_FunctionsManager->updateHandle(hOutResult);
	return this->_Inst_FunctionsManager;
}

SB_INLINE void TElPKCS11CertStorage::set_FunctionsManager(TElPKCS11FunctionsManager &Value)
{
	SBCheckError(TElPKCS11CertStorage_set_FunctionsManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElPKCS11CertStorage::set_FunctionsManager(TElPKCS11FunctionsManager *Value)
{
	SBCheckError(TElPKCS11CertStorage_set_FunctionsManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */
#endif
#ifndef SB_IOS
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11CertStorage_get_DLLName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-453868306, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11CertStorage::set_DLLName(const std::string &Value)
{
	SBCheckError(TElPKCS11CertStorage_set_DLLName(_Handle, Value.data(), (int32_t)Value.length()));
}
#endif

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProvider* TElPKCS11CertStorage::get_CryptoProvider()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11CertStorage_get_CryptoProvider(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProvider)
		this->_Inst_CryptoProvider = new TElCustomCryptoProvider(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProvider->updateHandle(hOutResult);
	return this->_Inst_CryptoProvider;
}

SB_INLINE void TElPKCS11CertStorage::set_CryptoProvider(TElCustomCryptoProvider &Value)
{
	SBCheckError(TElPKCS11CertStorage_set_CryptoProvider(_Handle, Value.getHandle()));
}

SB_INLINE void TElPKCS11CertStorage::set_CryptoProvider(TElCustomCryptoProvider *Value)
{
	SBCheckError(TElPKCS11CertStorage_set_CryptoProvider(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

TSBPKCS11StorageOptions TElPKCS11CertStorage::get_PKCS11Options()
{
	TSBPKCS11StorageOptionsRaw OutResultRaw = 0;
	SBCheckError(TElPKCS11CertStorage_get_PKCS11Options(_Handle, &OutResultRaw));
	return (TSBPKCS11StorageOptions)OutResultRaw;
}

SB_INLINE void TElPKCS11CertStorage::set_PKCS11Options(TSBPKCS11StorageOptions Value)
{
	SBCheckError(TElPKCS11CertStorage_set_PKCS11Options(_Handle, (TSBPKCS11StorageOptionsRaw)Value));
}

TSBPKCS11TokenAccessMode TElPKCS11CertStorage::get_TokenAccessMode()
{
	TSBPKCS11TokenAccessModeRaw OutResultRaw = 0;
	SBCheckError(TElPKCS11CertStorage_get_TokenAccessMode(_Handle, &OutResultRaw));
	return (TSBPKCS11TokenAccessMode)OutResultRaw;
}

SB_INLINE void TElPKCS11CertStorage::set_TokenAccessMode(TSBPKCS11TokenAccessMode Value)
{
	SBCheckError(TElPKCS11CertStorage_set_TokenAccessMode(_Handle, (TSBPKCS11TokenAccessModeRaw)Value));
}

TSBPKCS11CertStorageImportOrder TElPKCS11CertStorage::get_ImportOrder()
{
	TSBPKCS11CertStorageImportOrderRaw OutResultRaw = 0;
	SBCheckError(TElPKCS11CertStorage_get_ImportOrder(_Handle, &OutResultRaw));
	return (TSBPKCS11CertStorageImportOrder)OutResultRaw;
}

SB_INLINE void TElPKCS11CertStorage::set_ImportOrder(TSBPKCS11CertStorageImportOrder Value)
{
	SBCheckError(TElPKCS11CertStorage_set_ImportOrder(_Handle, (TSBPKCS11CertStorageImportOrderRaw)Value));
}

#ifdef SB_USE_CLASS_TELPKCS11NSSPARAMS
TElPKCS11NSSParams* TElPKCS11CertStorage::get_NSSParams()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11CertStorage_get_NSSParams(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NSSParams)
		this->_Inst_NSSParams = new TElPKCS11NSSParams(hOutResult, ohFalse);
	else
		this->_Inst_NSSParams->updateHandle(hOutResult);
	return this->_Inst_NSSParams;
}
#endif /* SB_USE_CLASS_TELPKCS11NSSPARAMS */

SB_INLINE void TElPKCS11CertStorage::get_OnNotification(TElPKCSNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11CertStorage_get_OnNotification(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11CertStorage::set_OnNotification(TElPKCSNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11CertStorage_set_OnNotification(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11CertStorage::get_OnSlotEvent(TElPKCSSlotEventEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11CertStorage_get_OnSlotEvent(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11CertStorage::set_OnSlotEvent(TElPKCSSlotEventEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11CertStorage_set_OnSlotEvent(_Handle, pMethodValue, pDataValue));
}

void TElPKCS11CertStorage::initInstances()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELKEYMATERIAL
	this->_Inst_Keys = NULL;
#endif /* SB_USE_CLASS_TELKEYMATERIAL */
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
	this->_Inst_Session = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */
#ifdef SB_USE_CLASS_TELPKCS11OBJECT
	this->_Inst_Objects = NULL;
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */
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

TElPKCS11CertStorage::TElPKCS11CertStorage(TElPKCS11CertStorageHandle handle, TElOwnHandle ownHandle) : TElCustomCertStorage(handle, ownHandle)
{
	initInstances();
}

TElPKCS11CertStorage::TElPKCS11CertStorage(TComponent &Owner) : TElCustomCertStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS11CertStorage_Create(Owner.getHandle(), &_Handle));
}

TElPKCS11CertStorage::TElPKCS11CertStorage(TComponent *Owner) : TElCustomCertStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS11CertStorage_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElPKCS11CertStorage::~TElPKCS11CertStorage()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELKEYMATERIAL
	delete this->_Inst_Keys;
	this->_Inst_Keys = NULL;
#endif /* SB_USE_CLASS_TELKEYMATERIAL */
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
	delete this->_Inst_Session;
	this->_Inst_Session = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */
#ifdef SB_USE_CLASS_TELPKCS11OBJECT
	delete this->_Inst_Objects;
	this->_Inst_Objects = NULL;
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */
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
#endif /* SB_USE_CLASS_TELPKCS11CERTSTORAGE */

#ifdef SB_USE_CLASS_TELPKCS11STGCTX

SB_INLINE void TElPKCS11StgCtx::SetCertStorageName()
{
	SBCheckError(TElPKCS11StgCtx_SetCertStorageName(_Handle));
}

TElPKCS11StgCtx::TElPKCS11StgCtx(TElPKCS11StgCtxHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPKCS11StgCtx::TElPKCS11StgCtx() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11StgCtx_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPKCS11STGCTX */

#ifdef SB_USE_CLASS_TELPKCS11CONSUMERCERTSTORAGE

TElPKCS11ConsumerCertStorage::TElPKCS11ConsumerCertStorage(TElPKCS11ConsumerCertStorageHandle handle, TElOwnHandle ownHandle) : TElPKCS11Consumer(handle, ownHandle)
{
}

TElPKCS11ConsumerCertStorage::TElPKCS11ConsumerCertStorage() : TElPKCS11Consumer(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11ConsumerCertStorage_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPKCS11CONSUMERCERTSTORAGE */

#ifdef SB_USE_GLOBAL_PROCS_PKCS11CERTSTORAGE

#ifdef SB_USE_CLASSES_TELPKCS11STGCTX_AND_TELX509CERTIFICATE
SB_INLINE TElPKCS11StgCtxHandle GetContextByCertificate(TElX509Certificate &Cert)
{
	TElPKCS11StgCtxHandle OutResult;
	SBCheckError(SBPKCS11CertStorage_GetContextByCertificate(Cert.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE TElPKCS11StgCtxHandle GetContextByCertificate(TElX509Certificate *Cert)
{
	TElPKCS11StgCtxHandle OutResult;
	SBCheckError(SBPKCS11CertStorage_GetContextByCertificate((Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPKCS11STGCTX_AND_TELX509CERTIFICATE */

#endif /* SB_USE_GLOBAL_PROCS_PKCS11CERTSTORAGE */

};	/* namespace SecureBlackbox */
