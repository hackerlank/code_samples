#include "sbpkcs11manager.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPKCS11MANAGER

SB_INLINE void TElPKCS11Manager::Close()
{
	SBCheckError(TElPKCS11Manager_Close(_Handle));
}

SB_INLINE void TElPKCS11Manager::Open()
{
	SBCheckError(TElPKCS11Manager_Open(_Handle));
}

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Manager::OpenSession(int32_t SlotIndex, bool ReadOnly)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Manager_OpenSession(_Handle, SlotIndex, (int8_t)ReadOnly, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

SB_INLINE void TElPKCS11Manager::CloseSession()
{
	SBCheckError(TElPKCS11Manager_CloseSession(_Handle));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE int32_t TElPKCS11Manager::IndexOfObject(uint32_t Handle)
#else
SB_INLINE int32_t TElPKCS11Manager::IndexOfObject(int64_t Handle)
#endif
{
	int32_t OutResult;
	SBCheckError(TElPKCS11Manager_IndexOfObject(_Handle, Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPKCS11MANAGEROBJECT
SB_INLINE int32_t TElPKCS11Manager::IndexOfObject(TElPKCS11ManagerObject &AnObject)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11Manager_IndexOfObject_1(_Handle, AnObject.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11Manager::IndexOfObject(TElPKCS11ManagerObject *AnObject)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11Manager_IndexOfObject_1(_Handle, (AnObject != NULL) ? AnObject->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11MANAGEROBJECT */

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Manager::RemoveObject(uint32_t Handle)
#else
SB_INLINE void TElPKCS11Manager::RemoveObject(int64_t Handle)
#endif
{
	SBCheckError(TElPKCS11Manager_RemoveObject(_Handle, Handle));
}

#ifdef SB_USE_CLASS_TELPKCS11MANAGEROBJECT
SB_INLINE void TElPKCS11Manager::RemoveObject(TElPKCS11ManagerObject &AnObject)
{
	SBCheckError(TElPKCS11Manager_RemoveObject_1(_Handle, AnObject.getHandle()));
}

SB_INLINE void TElPKCS11Manager::RemoveObject(TElPKCS11ManagerObject *AnObject)
{
	SBCheckError(TElPKCS11Manager_RemoveObject_1(_Handle, (AnObject != NULL) ? AnObject->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPKCS11MANAGEROBJECT */

SB_INLINE void TElPKCS11Manager::RemoveObject(int32_t Index)
{
	SBCheckError(TElPKCS11Manager_RemoveObject_2(_Handle, Index));
}

SB_INLINE void TElPKCS11Manager::RefreshObjects()
{
	SBCheckError(TElPKCS11Manager_RefreshObjects(_Handle));
}

#ifdef SB_USE_CLASS_TELPKCS11MANAGEROBJECT
bool TElPKCS11Manager::AddObject(TElPKCS11ManagerObject &AnObject)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11Manager_AddObject(_Handle, AnObject.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11Manager::AddObject(TElPKCS11ManagerObject *AnObject)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11Manager_AddObject(_Handle, (AnObject != NULL) ? AnObject->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPKCS11MANAGEROBJECT */

#ifdef SB_USE_CLASS_TELPKCS11MANAGEROBJECT
TElPKCS11ManagerObject* TElPKCS11Manager::get_Objects(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11Manager_get_Objects(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Objects)
		this->_Inst_Objects = new TElPKCS11ManagerObject(hOutResult, ohFalse);
	else
		this->_Inst_Objects->updateHandle(hOutResult);
	return this->_Inst_Objects;
}
#endif /* SB_USE_CLASS_TELPKCS11MANAGEROBJECT */

SB_INLINE int32_t TElPKCS11Manager::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11Manager_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPKCS11MODULE
TElPKCS11Module* TElPKCS11Manager::get_Module()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11Manager_get_Module(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Module)
		this->_Inst_Module = new TElPKCS11Module(hOutResult, ohFalse);
	else
		this->_Inst_Module->updateHandle(hOutResult);
	return this->_Inst_Module;
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifndef SB_IOS
void TElPKCS11Manager::get_DLLName(std::string &OutResult)
#else
#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER
TElPKCS11FunctionsManager* TElPKCS11Manager::get_FunctionsManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11Manager_get_FunctionsManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FunctionsManager)
		this->_Inst_FunctionsManager = new TElPKCS11FunctionsManager(hOutResult, ohFalse);
	else
		this->_Inst_FunctionsManager->updateHandle(hOutResult);
	return this->_Inst_FunctionsManager;
}

SB_INLINE void TElPKCS11Manager::set_FunctionsManager(TElPKCS11FunctionsManager &Value)
{
	SBCheckError(TElPKCS11Manager_set_FunctionsManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElPKCS11Manager::set_FunctionsManager(TElPKCS11FunctionsManager *Value)
{
	SBCheckError(TElPKCS11Manager_set_FunctionsManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */
#endif
#ifndef SB_IOS
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11Manager_get_DLLName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-78709159, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11Manager::set_DLLName(const std::string &Value)
{
	SBCheckError(TElPKCS11Manager_set_DLLName(_Handle, Value.data(), (int32_t)Value.length()));
}
#endif

TSBPKCS11StorageOptions TElPKCS11Manager::get_PKCS11Options()
{
	TSBPKCS11StorageOptionsRaw OutResultRaw = 0;
	SBCheckError(TElPKCS11Manager_get_PKCS11Options(_Handle, &OutResultRaw));
	return (TSBPKCS11StorageOptions)OutResultRaw;
}

SB_INLINE void TElPKCS11Manager::set_PKCS11Options(TSBPKCS11StorageOptions Value)
{
	SBCheckError(TElPKCS11Manager_set_PKCS11Options(_Handle, (TSBPKCS11StorageOptionsRaw)Value));
}

SB_INLINE void TElPKCS11Manager::get_OnNotification(TElPKCSNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11Manager_get_OnNotification(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11Manager::set_OnNotification(TElPKCSNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11Manager_set_OnNotification(_Handle, pMethodValue, pDataValue));
}

void TElPKCS11Manager::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS11MANAGEROBJECT
	this->_Inst_Objects = NULL;
#endif /* SB_USE_CLASS_TELPKCS11MANAGEROBJECT */
#ifdef SB_USE_CLASS_TELPKCS11MODULE
	this->_Inst_Module = NULL;
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#ifdef SB_IOS
#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER
	this->_Inst_FunctionsManager = NULL;
#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */
#endif
}

TElPKCS11Manager::TElPKCS11Manager(TElPKCS11ManagerHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElPKCS11Manager::TElPKCS11Manager(TComponent &Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS11Manager_Create(Owner.getHandle(), &_Handle));
}

TElPKCS11Manager::TElPKCS11Manager(TComponent *Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS11Manager_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElPKCS11Manager::~TElPKCS11Manager()
{
#ifdef SB_USE_CLASS_TELPKCS11MANAGEROBJECT
	delete this->_Inst_Objects;
	this->_Inst_Objects = NULL;
#endif /* SB_USE_CLASS_TELPKCS11MANAGEROBJECT */
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
}
#endif /* SB_USE_CLASS_TELPKCS11MANAGER */

#ifdef SB_USE_CLASS_TELPKCS11MANAGEROBJECT

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE uint32_t TElPKCS11ManagerObject::get_Handle()
#else
SB_INLINE int64_t TElPKCS11ManagerObject::get_Handle()
#endif
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11ManagerObject_get_Handle(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE uint32_t TElPKCS11ManagerObject::get_HWSize()
#else
SB_INLINE int64_t TElPKCS11ManagerObject::get_HWSize()
#endif
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11ManagerObject_get_HWSize(_Handle, &OutResult));
	return OutResult;
}

void TElPKCS11ManagerObject::get_ID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11ManagerObject_get_ID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2144509034, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11ManagerObject::get_Label_(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11ManagerObject_get_Label_(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1419018876, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11ManagerObject::set_Label_(const std::string &Value)
{
	SBCheckError(TElPKCS11ManagerObject_set_Label_(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElPKCS11ManagerObject::get_Modifiable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerObject_get_Modifiable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerObject::set_Modifiable(bool Value)
{
	SBCheckError(TElPKCS11ManagerObject_set_Modifiable(_Handle, (int8_t)Value));
}

bool TElPKCS11ManagerObject::get_Private_()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerObject_get_Private_(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerObject::set_Private_(bool Value)
{
	SBCheckError(TElPKCS11ManagerObject_set_Private_(_Handle, (int8_t)Value));
}

bool TElPKCS11ManagerObject::get_Token()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerObject_get_Token(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerObject::set_Token(bool Value)
{
	SBCheckError(TElPKCS11ManagerObject_set_Token(_Handle, (int8_t)Value));
}

TElPKCS11ManagerObject::TElPKCS11ManagerObject(TElPKCS11ManagerObjectHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELPKCS11MANAGER
TElPKCS11ManagerObject::TElPKCS11ManagerObject(TElPKCS11Manager &Owner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11ManagerObject_Create(Owner.getHandle(), &_Handle));
}

TElPKCS11ManagerObject::TElPKCS11ManagerObject(TElPKCS11Manager *Owner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11ManagerObject_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPKCS11MANAGER */

#endif /* SB_USE_CLASS_TELPKCS11MANAGEROBJECT */

#ifdef SB_USE_CLASS_TELPKCS11MANAGERDATAOBJECT

void TElPKCS11ManagerDataObject::get_Application(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11ManagerDataObject_get_Application(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(664110052, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11ManagerDataObject::set_Application(const std::string &Value)
{
	SBCheckError(TElPKCS11ManagerDataObject_set_Application(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPKCS11ManagerDataObject::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11ManagerDataObject_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1941213059, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11ManagerDataObject::set_OID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11ManagerDataObject_set_OID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS11ManagerDataObject::get_Value(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11ManagerDataObject_get_Value(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1691580462, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11ManagerDataObject::set_Value(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11ManagerDataObject_set_Value(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElPKCS11ManagerDataObject::TElPKCS11ManagerDataObject(TElPKCS11ManagerDataObjectHandle handle, TElOwnHandle ownHandle) : TElPKCS11ManagerObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELPKCS11MANAGER
TElPKCS11ManagerDataObject::TElPKCS11ManagerDataObject(TElPKCS11Manager &Owner) : TElPKCS11ManagerObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11ManagerDataObject_Create(Owner.getHandle(), &_Handle));
}

TElPKCS11ManagerDataObject::TElPKCS11ManagerDataObject(TElPKCS11Manager *Owner) : TElPKCS11ManagerObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11ManagerDataObject_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPKCS11MANAGER */

#endif /* SB_USE_CLASS_TELPKCS11MANAGERDATAOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11MANAGERCERTIFICATEOBJECT

void TElPKCS11ManagerCertificateObject::get_ACAttrTypes(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11ManagerCertificateObject_get_ACAttrTypes(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1136830989, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11ManagerCertificateObject::set_ACAttrTypes(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11ManagerCertificateObject_set_ACAttrTypes(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS11ManagerCertificateObject::get_ACIssuer(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11ManagerCertificateObject_get_ACIssuer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(531136455, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11ManagerCertificateObject::set_ACIssuer(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11ManagerCertificateObject_set_ACIssuer(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS11ManagerCertificateObject::get_ACOwner(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11ManagerCertificateObject_get_ACOwner(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1355715357, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11ManagerCertificateObject::set_ACOwner(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11ManagerCertificateObject_set_ACOwner(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElPKCS11CertificateCategory TElPKCS11ManagerCertificateObject::get_Category()
{
	TElPKCS11CertificateCategoryRaw OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerCertificateObject_get_Category(_Handle, &OutResultRaw));
	return (TElPKCS11CertificateCategory)OutResultRaw;
}

SB_INLINE void TElPKCS11ManagerCertificateObject::set_Category(TElPKCS11CertificateCategory Value)
{
	SBCheckError(TElPKCS11ManagerCertificateObject_set_Category(_Handle, (TElPKCS11CertificateCategoryRaw)Value));
}

TElPKCS11CertificateType TElPKCS11ManagerCertificateObject::get_CertificateType()
{
	TElPKCS11CertificateTypeRaw OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerCertificateObject_get_CertificateType(_Handle, &OutResultRaw));
	return (TElPKCS11CertificateType)OutResultRaw;
}

SB_INLINE void TElPKCS11ManagerCertificateObject::set_CertificateType(TElPKCS11CertificateType Value)
{
	SBCheckError(TElPKCS11ManagerCertificateObject_set_CertificateType(_Handle, (TElPKCS11CertificateTypeRaw)Value));
}

void TElPKCS11ManagerCertificateObject::get_Issuer(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11ManagerCertificateObject_get_Issuer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1352967605, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11ManagerCertificateObject::set_Issuer(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11ManagerCertificateObject_set_Issuer(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS11ManagerCertificateObject::get_SerialNumber(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11ManagerCertificateObject_get_SerialNumber(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1327185117, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11ManagerCertificateObject::set_SerialNumber(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11ManagerCertificateObject_set_SerialNumber(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS11ManagerCertificateObject::get_Subject(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11ManagerCertificateObject_get_Subject(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1524790255, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11ManagerCertificateObject::set_Subject(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11ManagerCertificateObject_set_Subject(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElPKCS11ManagerCertificateObject::get_Trusted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerCertificateObject_get_Trusted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerCertificateObject::set_Trusted(bool Value)
{
	SBCheckError(TElPKCS11ManagerCertificateObject_set_Trusted(_Handle, (int8_t)Value));
}

SB_INLINE int64_t TElPKCS11ManagerCertificateObject::get_ValidFrom()
{
	int64_t OutResult;
	SBCheckError(TElPKCS11ManagerCertificateObject_get_ValidFrom(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS11ManagerCertificateObject::set_ValidFrom(int64_t Value)
{
	SBCheckError(TElPKCS11ManagerCertificateObject_set_ValidFrom(_Handle, Value));
}

SB_INLINE int64_t TElPKCS11ManagerCertificateObject::get_ValidTo()
{
	int64_t OutResult;
	SBCheckError(TElPKCS11ManagerCertificateObject_get_ValidTo(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS11ManagerCertificateObject::set_ValidTo(int64_t Value)
{
	SBCheckError(TElPKCS11ManagerCertificateObject_set_ValidTo(_Handle, Value));
}

void TElPKCS11ManagerCertificateObject::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11ManagerCertificateObject_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1748986887, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11ManagerCertificateObject::set_URL(const std::string &Value)
{
	SBCheckError(TElPKCS11ManagerCertificateObject_set_URL(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPKCS11ManagerCertificateObject::get_Value(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11ManagerCertificateObject_get_Value(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1587248337, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11ManagerCertificateObject::set_Value(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11ManagerCertificateObject_set_Value(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElPKCS11ManagerCertificateObject::TElPKCS11ManagerCertificateObject(TElPKCS11ManagerCertificateObjectHandle handle, TElOwnHandle ownHandle) : TElPKCS11ManagerObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELPKCS11MANAGER
TElPKCS11ManagerCertificateObject::TElPKCS11ManagerCertificateObject(TElPKCS11Manager &Owner) : TElPKCS11ManagerObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11ManagerCertificateObject_Create(Owner.getHandle(), &_Handle));
}

TElPKCS11ManagerCertificateObject::TElPKCS11ManagerCertificateObject(TElPKCS11Manager *Owner) : TElPKCS11ManagerObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11ManagerCertificateObject_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPKCS11MANAGER */

#endif /* SB_USE_CLASS_TELPKCS11MANAGERCERTIFICATEOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11MANAGERKEYOBJECT

SB_INLINE int64_t TElPKCS11ManagerKeyObject::get_ValidFrom()
{
	int64_t OutResult;
	SBCheckError(TElPKCS11ManagerKeyObject_get_ValidFrom(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS11ManagerKeyObject::set_ValidFrom(int64_t Value)
{
	SBCheckError(TElPKCS11ManagerKeyObject_set_ValidFrom(_Handle, Value));
}

SB_INLINE int64_t TElPKCS11ManagerKeyObject::get_ValidTo()
{
	int64_t OutResult;
	SBCheckError(TElPKCS11ManagerKeyObject_get_ValidTo(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS11ManagerKeyObject::set_ValidTo(int64_t Value)
{
	SBCheckError(TElPKCS11ManagerKeyObject_set_ValidTo(_Handle, Value));
}

TElPKCS11ManagerKeyObject::TElPKCS11ManagerKeyObject(TElPKCS11ManagerKeyObjectHandle handle, TElOwnHandle ownHandle) : TElPKCS11ManagerObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELPKCS11MANAGER
TElPKCS11ManagerKeyObject::TElPKCS11ManagerKeyObject(TElPKCS11Manager &Owner) : TElPKCS11ManagerObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11ManagerKeyObject_Create(Owner.getHandle(), &_Handle));
}

TElPKCS11ManagerKeyObject::TElPKCS11ManagerKeyObject(TElPKCS11Manager *Owner) : TElPKCS11ManagerObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11ManagerKeyObject_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPKCS11MANAGER */

#endif /* SB_USE_CLASS_TELPKCS11MANAGERKEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11MANAGERPUBLICKEYOBJECT

bool TElPKCS11ManagerPublicKeyObject::get_Encrypt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerPublicKeyObject_get_Encrypt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerPublicKeyObject::set_Encrypt(bool Value)
{
	SBCheckError(TElPKCS11ManagerPublicKeyObject_set_Encrypt(_Handle, (int8_t)Value));
}

void TElPKCS11ManagerPublicKeyObject::get_Subject(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11ManagerPublicKeyObject_get_Subject(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-39083869, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11ManagerPublicKeyObject::set_Subject(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11ManagerPublicKeyObject_set_Subject(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElPKCS11ManagerPublicKeyObject::get_Trusted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerPublicKeyObject_get_Trusted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerPublicKeyObject::set_Trusted(bool Value)
{
	SBCheckError(TElPKCS11ManagerPublicKeyObject_set_Trusted(_Handle, (int8_t)Value));
}

bool TElPKCS11ManagerPublicKeyObject::get_Verify()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerPublicKeyObject_get_Verify(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerPublicKeyObject::set_Verify(bool Value)
{
	SBCheckError(TElPKCS11ManagerPublicKeyObject_set_Verify(_Handle, (int8_t)Value));
}

bool TElPKCS11ManagerPublicKeyObject::get_VerifyRecover()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerPublicKeyObject_get_VerifyRecover(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerPublicKeyObject::set_VerifyRecover(bool Value)
{
	SBCheckError(TElPKCS11ManagerPublicKeyObject_set_VerifyRecover(_Handle, (int8_t)Value));
}

bool TElPKCS11ManagerPublicKeyObject::get_Wrap()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerPublicKeyObject_get_Wrap(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerPublicKeyObject::set_Wrap(bool Value)
{
	SBCheckError(TElPKCS11ManagerPublicKeyObject_set_Wrap(_Handle, (int8_t)Value));
}

TElPKCS11ManagerPublicKeyObject::TElPKCS11ManagerPublicKeyObject(TElPKCS11ManagerPublicKeyObjectHandle handle, TElOwnHandle ownHandle) : TElPKCS11ManagerKeyObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELPKCS11MANAGER
TElPKCS11ManagerPublicKeyObject::TElPKCS11ManagerPublicKeyObject(TElPKCS11Manager &Owner) : TElPKCS11ManagerKeyObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11ManagerPublicKeyObject_Create(Owner.getHandle(), &_Handle));
}

TElPKCS11ManagerPublicKeyObject::TElPKCS11ManagerPublicKeyObject(TElPKCS11Manager *Owner) : TElPKCS11ManagerKeyObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11ManagerPublicKeyObject_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPKCS11MANAGER */

#endif /* SB_USE_CLASS_TELPKCS11MANAGERPUBLICKEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11MANAGERPRIVATEKEYOBJECT

bool TElPKCS11ManagerPrivateKeyObject::get_AlwaysAuthenticate()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerPrivateKeyObject_get_AlwaysAuthenticate(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerPrivateKeyObject::set_AlwaysAuthenticate(bool Value)
{
	SBCheckError(TElPKCS11ManagerPrivateKeyObject_set_AlwaysAuthenticate(_Handle, (int8_t)Value));
}

bool TElPKCS11ManagerPrivateKeyObject::get_Decrypt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerPrivateKeyObject_get_Decrypt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerPrivateKeyObject::set_Decrypt(bool Value)
{
	SBCheckError(TElPKCS11ManagerPrivateKeyObject_set_Decrypt(_Handle, (int8_t)Value));
}

bool TElPKCS11ManagerPrivateKeyObject::get_Extractable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerPrivateKeyObject_get_Extractable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerPrivateKeyObject::set_Extractable(bool Value)
{
	SBCheckError(TElPKCS11ManagerPrivateKeyObject_set_Extractable(_Handle, (int8_t)Value));
}

bool TElPKCS11ManagerPrivateKeyObject::get_Sensitive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerPrivateKeyObject_get_Sensitive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerPrivateKeyObject::set_Sensitive(bool Value)
{
	SBCheckError(TElPKCS11ManagerPrivateKeyObject_set_Sensitive(_Handle, (int8_t)Value));
}

bool TElPKCS11ManagerPrivateKeyObject::get_Sign()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerPrivateKeyObject_get_Sign(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerPrivateKeyObject::set_Sign(bool Value)
{
	SBCheckError(TElPKCS11ManagerPrivateKeyObject_set_Sign(_Handle, (int8_t)Value));
}

bool TElPKCS11ManagerPrivateKeyObject::get_SignRecover()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerPrivateKeyObject_get_SignRecover(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerPrivateKeyObject::set_SignRecover(bool Value)
{
	SBCheckError(TElPKCS11ManagerPrivateKeyObject_set_SignRecover(_Handle, (int8_t)Value));
}

void TElPKCS11ManagerPrivateKeyObject::get_Subject(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11ManagerPrivateKeyObject_get_Subject(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-709309662, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11ManagerPrivateKeyObject::set_Subject(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11ManagerPrivateKeyObject_set_Subject(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElPKCS11ManagerPrivateKeyObject::get_Unwrap()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerPrivateKeyObject_get_Unwrap(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerPrivateKeyObject::set_Unwrap(bool Value)
{
	SBCheckError(TElPKCS11ManagerPrivateKeyObject_set_Unwrap(_Handle, (int8_t)Value));
}

TElPKCS11ManagerPrivateKeyObject::TElPKCS11ManagerPrivateKeyObject(TElPKCS11ManagerPrivateKeyObjectHandle handle, TElOwnHandle ownHandle) : TElPKCS11ManagerKeyObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELPKCS11MANAGER
TElPKCS11ManagerPrivateKeyObject::TElPKCS11ManagerPrivateKeyObject(TElPKCS11Manager &Owner) : TElPKCS11ManagerKeyObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11ManagerPrivateKeyObject_Create(Owner.getHandle(), &_Handle));
}

TElPKCS11ManagerPrivateKeyObject::TElPKCS11ManagerPrivateKeyObject(TElPKCS11Manager *Owner) : TElPKCS11ManagerKeyObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11ManagerPrivateKeyObject_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPKCS11MANAGER */

#endif /* SB_USE_CLASS_TELPKCS11MANAGERPRIVATEKEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11MANAGERSECRETKEYOBJECT

bool TElPKCS11ManagerSecretKeyObject::get_Decrypt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerSecretKeyObject_get_Decrypt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerSecretKeyObject::set_Decrypt(bool Value)
{
	SBCheckError(TElPKCS11ManagerSecretKeyObject_set_Decrypt(_Handle, (int8_t)Value));
}

bool TElPKCS11ManagerSecretKeyObject::get_Encrypt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerSecretKeyObject_get_Encrypt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerSecretKeyObject::set_Encrypt(bool Value)
{
	SBCheckError(TElPKCS11ManagerSecretKeyObject_set_Encrypt(_Handle, (int8_t)Value));
}

bool TElPKCS11ManagerSecretKeyObject::get_Extractable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerSecretKeyObject_get_Extractable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerSecretKeyObject::set_Extractable(bool Value)
{
	SBCheckError(TElPKCS11ManagerSecretKeyObject_set_Extractable(_Handle, (int8_t)Value));
}

bool TElPKCS11ManagerSecretKeyObject::get_Sensitive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerSecretKeyObject_get_Sensitive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerSecretKeyObject::set_Sensitive(bool Value)
{
	SBCheckError(TElPKCS11ManagerSecretKeyObject_set_Sensitive(_Handle, (int8_t)Value));
}

bool TElPKCS11ManagerSecretKeyObject::get_Sign()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerSecretKeyObject_get_Sign(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerSecretKeyObject::set_Sign(bool Value)
{
	SBCheckError(TElPKCS11ManagerSecretKeyObject_set_Sign(_Handle, (int8_t)Value));
}

bool TElPKCS11ManagerSecretKeyObject::get_Unwrap()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerSecretKeyObject_get_Unwrap(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerSecretKeyObject::set_Unwrap(bool Value)
{
	SBCheckError(TElPKCS11ManagerSecretKeyObject_set_Unwrap(_Handle, (int8_t)Value));
}

bool TElPKCS11ManagerSecretKeyObject::get_Verify()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerSecretKeyObject_get_Verify(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerSecretKeyObject::set_Verify(bool Value)
{
	SBCheckError(TElPKCS11ManagerSecretKeyObject_set_Verify(_Handle, (int8_t)Value));
}

bool TElPKCS11ManagerSecretKeyObject::get_Wrap()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ManagerSecretKeyObject_get_Wrap(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11ManagerSecretKeyObject::set_Wrap(bool Value)
{
	SBCheckError(TElPKCS11ManagerSecretKeyObject_set_Wrap(_Handle, (int8_t)Value));
}

TElPKCS11ManagerSecretKeyObject::TElPKCS11ManagerSecretKeyObject(TElPKCS11ManagerSecretKeyObjectHandle handle, TElOwnHandle ownHandle) : TElPKCS11ManagerKeyObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELPKCS11MANAGER
TElPKCS11ManagerSecretKeyObject::TElPKCS11ManagerSecretKeyObject(TElPKCS11Manager &Owner) : TElPKCS11ManagerKeyObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11ManagerSecretKeyObject_Create(Owner.getHandle(), &_Handle));
}

TElPKCS11ManagerSecretKeyObject::TElPKCS11ManagerSecretKeyObject(TElPKCS11Manager *Owner) : TElPKCS11ManagerKeyObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11ManagerSecretKeyObject_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPKCS11MANAGER */

#endif /* SB_USE_CLASS_TELPKCS11MANAGERSECRETKEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11CONSUMERMANAGER

TElPKCS11ConsumerManager::TElPKCS11ConsumerManager(TElPKCS11ConsumerManagerHandle handle, TElOwnHandle ownHandle) : TElPKCS11Consumer(handle, ownHandle)
{
}

TElPKCS11ConsumerManager::TElPKCS11ConsumerManager() : TElPKCS11Consumer(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11ConsumerManager_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPKCS11CONSUMERMANAGER */

};	/* namespace SecureBlackbox */
