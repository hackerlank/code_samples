#include "sbpkcs11base.h"

namespace SecureBlackbox {

#ifndef SB_CPU64_OR_NOT_IOS
#ifdef SB_USE_CLASS_TELPKCS11MODULE

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
bool TElPKCS11Module::CloseSession(TElPKCS11SessionInfo &SessionInfo)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11Module_CloseSession(_Handle, SessionInfo.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11Module::CloseSession(TElPKCS11SessionInfo *SessionInfo)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11Module_CloseSession(_Handle, (SessionInfo != NULL) ? SessionInfo->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

SB_INLINE int32_t TElPKCS11Module::GetFunctionList()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11Module_GetFunctionList(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO
SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::OpenSession(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer &Consumer)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_OpenSession(_Handle, SlotIndex, (int8_t)ReadOnly, Consumer.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::OpenSession(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer *Consumer)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_OpenSession(_Handle, SlotIndex, (int8_t)ReadOnly, (Consumer != NULL) ? Consumer->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO
SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::OpenSessionEx(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer &Consumer, bool RequestNotifications)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_OpenSessionEx(_Handle, SlotIndex, (int8_t)ReadOnly, Consumer.getHandle(), (int8_t)RequestNotifications, &OutResult));
	return OutResult;
}

SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::OpenSessionEx(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer *Consumer, bool RequestNotifications)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_OpenSessionEx(_Handle, SlotIndex, (int8_t)ReadOnly, (Consumer != NULL) ? Consumer->getHandle() : SB_NULL_HANDLE, (int8_t)RequestNotifications, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::GetSessionByHandle(uint32_t Handle)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_GetSessionByHandle(_Handle, Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

SB_INLINE void TElPKCS11Module::InitToken(int32_t SlotIndex, const std::string &Pin, const std::string &TokenLabel)
{
	SBCheckError(TElPKCS11Module_InitToken(_Handle, SlotIndex, Pin.data(), (int32_t)Pin.length(), TokenLabel.data(), (int32_t)TokenLabel.length()));
}

void TElPKCS11Module::get_ProviderDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11Module_get_ProviderDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(322616071, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11Module::set_ProviderDescription(const std::string &Value)
{
	SBCheckError(TElPKCS11Module_set_ProviderDescription(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
TElPKCS11SessionInfo* TElPKCS11Module::get_Session(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11Module_get_Session(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Session)
		this->_Inst_Session = new TElPKCS11SessionInfo(hOutResult, ohFalse);
	else
		this->_Inst_Session->updateHandle(hOutResult);
	return this->_Inst_Session;
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

SB_INLINE int32_t TElPKCS11Module::get_SessionCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11Module_get_SessionCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
TElPKCS11SlotInfo* TElPKCS11Module::get_Slot(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11Module_get_Slot(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Slot)
		this->_Inst_Slot = new TElPKCS11SlotInfo(hOutResult, ohFalse);
	else
		this->_Inst_Slot->updateHandle(hOutResult);
	return this->_Inst_Slot;
}
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */

SB_INLINE int32_t TElPKCS11Module::get_SlotCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11Module_get_SlotCount(_Handle, &OutResult));
	return OutResult;
}

void TElPKCS11Module::get_UniqueID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11Module_get_UniqueID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(236493488, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER
TElPKCS11FunctionsManager* TElPKCS11Module::get_HLib()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11Module_get_HLib(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HLib)
		this->_Inst_HLib = new TElPKCS11FunctionsManager(hOutResult, ohFalse);
	else
		this->_Inst_HLib->updateHandle(hOutResult);
	return this->_Inst_HLib;
}
#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */

void TElPKCS11Module::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
	this->_Inst_Session = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
	this->_Inst_Slot = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER
	this->_Inst_HLib = NULL;
#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */
}

TElPKCS11Module::TElPKCS11Module(TElPKCS11ModuleHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS11Module::TElPKCS11Module() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS11Module_Create(&_Handle));
}

TElPKCS11Module::~TElPKCS11Module()
{
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
	delete this->_Inst_Session;
	this->_Inst_Session = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
	delete this->_Inst_Slot;
	this->_Inst_Slot = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER
	delete this->_Inst_HLib;
	this->_Inst_HLib = NULL;
#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
#ifdef SB_USE_CLASS_TELPKCS11MODULE

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
bool TElPKCS11Module::CloseSession(TElPKCS11SessionInfo &SessionInfo)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11Module_CloseSession(_Handle, SessionInfo.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11Module::CloseSession(TElPKCS11SessionInfo *SessionInfo)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11Module_CloseSession(_Handle, (SessionInfo != NULL) ? SessionInfo->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

SB_INLINE int32_t TElPKCS11Module::GetFunctionList()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11Module_GetFunctionList(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO
SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::OpenSession(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer &Consumer)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_OpenSession(_Handle, SlotIndex, (int8_t)ReadOnly, Consumer.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::OpenSession(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer *Consumer)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_OpenSession(_Handle, SlotIndex, (int8_t)ReadOnly, (Consumer != NULL) ? Consumer->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO
SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::OpenSessionEx(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer &Consumer, bool RequestNotifications)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_OpenSessionEx(_Handle, SlotIndex, (int8_t)ReadOnly, Consumer.getHandle(), (int8_t)RequestNotifications, &OutResult));
	return OutResult;
}

SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::OpenSessionEx(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer *Consumer, bool RequestNotifications)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_OpenSessionEx(_Handle, SlotIndex, (int8_t)ReadOnly, (Consumer != NULL) ? Consumer->getHandle() : SB_NULL_HANDLE, (int8_t)RequestNotifications, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::GetSessionByHandle(int64_t Handle)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_GetSessionByHandle(_Handle, Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

SB_INLINE void TElPKCS11Module::InitToken(int32_t SlotIndex, const std::string &Pin, const std::string &TokenLabel)
{
	SBCheckError(TElPKCS11Module_InitToken(_Handle, SlotIndex, Pin.data(), (int32_t)Pin.length(), TokenLabel.data(), (int32_t)TokenLabel.length()));
}

void TElPKCS11Module::get_ProviderDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11Module_get_ProviderDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(322616071, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11Module::set_ProviderDescription(const std::string &Value)
{
	SBCheckError(TElPKCS11Module_set_ProviderDescription(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
TElPKCS11SessionInfo* TElPKCS11Module::get_Session(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11Module_get_Session(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Session)
		this->_Inst_Session = new TElPKCS11SessionInfo(hOutResult, ohFalse);
	else
		this->_Inst_Session->updateHandle(hOutResult);
	return this->_Inst_Session;
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

SB_INLINE int32_t TElPKCS11Module::get_SessionCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11Module_get_SessionCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
TElPKCS11SlotInfo* TElPKCS11Module::get_Slot(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11Module_get_Slot(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Slot)
		this->_Inst_Slot = new TElPKCS11SlotInfo(hOutResult, ohFalse);
	else
		this->_Inst_Slot->updateHandle(hOutResult);
	return this->_Inst_Slot;
}
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */

SB_INLINE int32_t TElPKCS11Module::get_SlotCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11Module_get_SlotCount(_Handle, &OutResult));
	return OutResult;
}

void TElPKCS11Module::get_UniqueID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11Module_get_UniqueID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(236493488, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER
TElPKCS11FunctionsManager* TElPKCS11Module::get_HLib()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11Module_get_HLib(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HLib)
		this->_Inst_HLib = new TElPKCS11FunctionsManager(hOutResult, ohFalse);
	else
		this->_Inst_HLib->updateHandle(hOutResult);
	return this->_Inst_HLib;
}
#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */

void TElPKCS11Module::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
	this->_Inst_Session = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
	this->_Inst_Slot = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER
	this->_Inst_HLib = NULL;
#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */
}

TElPKCS11Module::TElPKCS11Module(TElPKCS11ModuleHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS11Module::TElPKCS11Module() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS11Module_Create(&_Handle));
}

TElPKCS11Module::~TElPKCS11Module()
{
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
	delete this->_Inst_Session;
	this->_Inst_Session = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
	delete this->_Inst_Slot;
	this->_Inst_Slot = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER
	delete this->_Inst_HLib;
	this->_Inst_HLib = NULL;
#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
#ifdef SB_USE_CLASS_TELPKCS11MODULE

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
bool TElPKCS11Module::CloseSession(TElPKCS11SessionInfo &SessionInfo)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11Module_CloseSession(_Handle, SessionInfo.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11Module::CloseSession(TElPKCS11SessionInfo *SessionInfo)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11Module_CloseSession(_Handle, (SessionInfo != NULL) ? SessionInfo->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

SB_INLINE int32_t TElPKCS11Module::GetFunctionList()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11Module_GetFunctionList(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO
SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::OpenSession(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer &Consumer)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_OpenSession(_Handle, SlotIndex, (int8_t)ReadOnly, Consumer.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::OpenSession(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer *Consumer)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_OpenSession(_Handle, SlotIndex, (int8_t)ReadOnly, (Consumer != NULL) ? Consumer->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO
SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::OpenSessionEx(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer &Consumer, bool RequestNotifications)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_OpenSessionEx(_Handle, SlotIndex, (int8_t)ReadOnly, Consumer.getHandle(), (int8_t)RequestNotifications, &OutResult));
	return OutResult;
}

SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::OpenSessionEx(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer *Consumer, bool RequestNotifications)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_OpenSessionEx(_Handle, SlotIndex, (int8_t)ReadOnly, (Consumer != NULL) ? Consumer->getHandle() : SB_NULL_HANDLE, (int8_t)RequestNotifications, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::GetSessionByHandle(int64_t Handle)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_GetSessionByHandle(_Handle, Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

SB_INLINE void TElPKCS11Module::InitToken(int32_t SlotIndex, const std::string &Pin, const std::string &TokenLabel)
{
	SBCheckError(TElPKCS11Module_InitToken(_Handle, SlotIndex, Pin.data(), (int32_t)Pin.length(), TokenLabel.data(), (int32_t)TokenLabel.length()));
}

void TElPKCS11Module::get_ProviderDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11Module_get_ProviderDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(322616071, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11Module::set_ProviderDescription(const std::string &Value)
{
	SBCheckError(TElPKCS11Module_set_ProviderDescription(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
TElPKCS11SessionInfo* TElPKCS11Module::get_Session(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11Module_get_Session(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Session)
		this->_Inst_Session = new TElPKCS11SessionInfo(hOutResult, ohFalse);
	else
		this->_Inst_Session->updateHandle(hOutResult);
	return this->_Inst_Session;
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

SB_INLINE int32_t TElPKCS11Module::get_SessionCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11Module_get_SessionCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
TElPKCS11SlotInfo* TElPKCS11Module::get_Slot(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11Module_get_Slot(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Slot)
		this->_Inst_Slot = new TElPKCS11SlotInfo(hOutResult, ohFalse);
	else
		this->_Inst_Slot->updateHandle(hOutResult);
	return this->_Inst_Slot;
}
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */

SB_INLINE int32_t TElPKCS11Module::get_SlotCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11Module_get_SlotCount(_Handle, &OutResult));
	return OutResult;
}

void TElPKCS11Module::get_UniqueID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11Module_get_UniqueID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(236493488, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElPKCS11Module::get_HLib()
{
	int64_t OutResult;
	SBCheckError(TElPKCS11Module_get_HLib(_Handle, &OutResult));
	return OutResult;
}

bool TElPKCS11Module::get_UseGetFunctionList()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11Module_get_UseGetFunctionList(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11Module::set_UseGetFunctionList(bool Value)
{
	SBCheckError(TElPKCS11Module_set_UseGetFunctionList(_Handle, (int8_t)Value));
}

void TElPKCS11Module::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
	this->_Inst_Session = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
	this->_Inst_Slot = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
}

TElPKCS11Module::TElPKCS11Module(TElPKCS11ModuleHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS11Module::TElPKCS11Module() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS11Module_Create(&_Handle));
}

TElPKCS11Module::~TElPKCS11Module()
{
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
	delete this->_Inst_Session;
	this->_Inst_Session = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
	delete this->_Inst_Slot;
	this->_Inst_Slot = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#endif
#ifndef SB_CPU64_OR_IOS
#ifdef SB_USE_CLASS_TELPKCS11MODULE

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
bool TElPKCS11Module::CloseSession(TElPKCS11SessionInfo &SessionInfo)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11Module_CloseSession(_Handle, SessionInfo.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11Module::CloseSession(TElPKCS11SessionInfo *SessionInfo)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11Module_CloseSession(_Handle, (SessionInfo != NULL) ? SessionInfo->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

SB_INLINE int32_t TElPKCS11Module::GetFunctionList()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11Module_GetFunctionList(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO
SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::OpenSession(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer &Consumer)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_OpenSession(_Handle, SlotIndex, (int8_t)ReadOnly, Consumer.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::OpenSession(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer *Consumer)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_OpenSession(_Handle, SlotIndex, (int8_t)ReadOnly, (Consumer != NULL) ? Consumer->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO
SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::OpenSessionEx(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer &Consumer, bool RequestNotifications)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_OpenSessionEx(_Handle, SlotIndex, (int8_t)ReadOnly, Consumer.getHandle(), (int8_t)RequestNotifications, &OutResult));
	return OutResult;
}

SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::OpenSessionEx(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer *Consumer, bool RequestNotifications)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_OpenSessionEx(_Handle, SlotIndex, (int8_t)ReadOnly, (Consumer != NULL) ? Consumer->getHandle() : SB_NULL_HANDLE, (int8_t)RequestNotifications, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::GetSessionByHandle(uint32_t Handle)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_GetSessionByHandle(_Handle, Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

SB_INLINE void TElPKCS11Module::InitToken(int32_t SlotIndex, const std::string &Pin, const std::string &TokenLabel)
{
	SBCheckError(TElPKCS11Module_InitToken(_Handle, SlotIndex, Pin.data(), (int32_t)Pin.length(), TokenLabel.data(), (int32_t)TokenLabel.length()));
}

void TElPKCS11Module::get_ProviderDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11Module_get_ProviderDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(322616071, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11Module::set_ProviderDescription(const std::string &Value)
{
	SBCheckError(TElPKCS11Module_set_ProviderDescription(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
TElPKCS11SessionInfo* TElPKCS11Module::get_Session(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11Module_get_Session(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Session)
		this->_Inst_Session = new TElPKCS11SessionInfo(hOutResult, ohFalse);
	else
		this->_Inst_Session->updateHandle(hOutResult);
	return this->_Inst_Session;
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

SB_INLINE int32_t TElPKCS11Module::get_SessionCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11Module_get_SessionCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
TElPKCS11SlotInfo* TElPKCS11Module::get_Slot(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11Module_get_Slot(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Slot)
		this->_Inst_Slot = new TElPKCS11SlotInfo(hOutResult, ohFalse);
	else
		this->_Inst_Slot->updateHandle(hOutResult);
	return this->_Inst_Slot;
}
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */

SB_INLINE int32_t TElPKCS11Module::get_SlotCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11Module_get_SlotCount(_Handle, &OutResult));
	return OutResult;
}

void TElPKCS11Module::get_UniqueID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11Module_get_UniqueID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(236493488, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE uint32_t TElPKCS11Module::get_HLib()
{
	uint32_t OutResult;
	SBCheckError(TElPKCS11Module_get_HLib(_Handle, &OutResult));
	return OutResult;
}

bool TElPKCS11Module::get_UseGetFunctionList()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11Module_get_UseGetFunctionList(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11Module::set_UseGetFunctionList(bool Value)
{
	SBCheckError(TElPKCS11Module_set_UseGetFunctionList(_Handle, (int8_t)Value));
}

void TElPKCS11Module::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
	this->_Inst_Session = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
	this->_Inst_Slot = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
}

TElPKCS11Module::TElPKCS11Module(TElPKCS11ModuleHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS11Module::TElPKCS11Module() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS11Module_Create(&_Handle));
}

TElPKCS11Module::~TElPKCS11Module()
{
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
	delete this->_Inst_Session;
	this->_Inst_Session = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
	delete this->_Inst_Slot;
	this->_Inst_Slot = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#endif
#ifndef SB_NOT_CPU64_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELPKCS11MODULE

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
bool TElPKCS11Module::CloseSession(TElPKCS11SessionInfo &SessionInfo)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11Module_CloseSession(_Handle, SessionInfo.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11Module::CloseSession(TElPKCS11SessionInfo *SessionInfo)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11Module_CloseSession(_Handle, (SessionInfo != NULL) ? SessionInfo->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

SB_INLINE int32_t TElPKCS11Module::GetFunctionList()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11Module_GetFunctionList(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO
SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::OpenSession(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer &Consumer)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_OpenSession(_Handle, SlotIndex, (int8_t)ReadOnly, Consumer.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::OpenSession(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer *Consumer)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_OpenSession(_Handle, SlotIndex, (int8_t)ReadOnly, (Consumer != NULL) ? Consumer->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO
SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::OpenSessionEx(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer &Consumer, bool RequestNotifications)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_OpenSessionEx(_Handle, SlotIndex, (int8_t)ReadOnly, Consumer.getHandle(), (int8_t)RequestNotifications, &OutResult));
	return OutResult;
}

SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::OpenSessionEx(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer *Consumer, bool RequestNotifications)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_OpenSessionEx(_Handle, SlotIndex, (int8_t)ReadOnly, (Consumer != NULL) ? Consumer->getHandle() : SB_NULL_HANDLE, (int8_t)RequestNotifications, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
SB_INLINE TElPKCS11SessionInfoHandle TElPKCS11Module::GetSessionByHandle(uint32_t Handle)
{
	TElPKCS11SessionInfoHandle OutResult;
	SBCheckError(TElPKCS11Module_GetSessionByHandle(_Handle, Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

SB_INLINE void TElPKCS11Module::InitToken(int32_t SlotIndex, const std::string &Pin, const std::string &TokenLabel)
{
	SBCheckError(TElPKCS11Module_InitToken(_Handle, SlotIndex, Pin.data(), (int32_t)Pin.length(), TokenLabel.data(), (int32_t)TokenLabel.length()));
}

void TElPKCS11Module::get_ProviderDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11Module_get_ProviderDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(322616071, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11Module::set_ProviderDescription(const std::string &Value)
{
	SBCheckError(TElPKCS11Module_set_ProviderDescription(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
TElPKCS11SessionInfo* TElPKCS11Module::get_Session(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11Module_get_Session(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Session)
		this->_Inst_Session = new TElPKCS11SessionInfo(hOutResult, ohFalse);
	else
		this->_Inst_Session->updateHandle(hOutResult);
	return this->_Inst_Session;
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

SB_INLINE int32_t TElPKCS11Module::get_SessionCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11Module_get_SessionCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
TElPKCS11SlotInfo* TElPKCS11Module::get_Slot(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11Module_get_Slot(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Slot)
		this->_Inst_Slot = new TElPKCS11SlotInfo(hOutResult, ohFalse);
	else
		this->_Inst_Slot->updateHandle(hOutResult);
	return this->_Inst_Slot;
}
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */

SB_INLINE int32_t TElPKCS11Module::get_SlotCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11Module_get_SlotCount(_Handle, &OutResult));
	return OutResult;
}

void TElPKCS11Module::get_UniqueID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11Module_get_UniqueID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(236493488, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElPKCS11Module::get_HLib()
{
	int64_t OutResult;
	SBCheckError(TElPKCS11Module_get_HLib(_Handle, &OutResult));
	return OutResult;
}

bool TElPKCS11Module::get_UseGetFunctionList()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11Module_get_UseGetFunctionList(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11Module::set_UseGetFunctionList(bool Value)
{
	SBCheckError(TElPKCS11Module_set_UseGetFunctionList(_Handle, (int8_t)Value));
}

void TElPKCS11Module::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
	this->_Inst_Session = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
	this->_Inst_Slot = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
}

TElPKCS11Module::TElPKCS11Module(TElPKCS11ModuleHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS11Module::TElPKCS11Module() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS11Module_Create(&_Handle));
}

TElPKCS11Module::~TElPKCS11Module()
{
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
	delete this->_Inst_Session;
	this->_Inst_Session = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
	delete this->_Inst_Slot;
	this->_Inst_Slot = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#endif

#ifndef SB_CPU64_OR_NOT_IOS
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
SB_INLINE void TElPKCS11SlotInfo::AddConsumer(TElPKCS11Consumer &Consumer)
{
	SBCheckError(TElPKCS11SlotInfo_AddConsumer(_Handle, Consumer.getHandle()));
}

SB_INLINE void TElPKCS11SlotInfo::AddConsumer(TElPKCS11Consumer *Consumer)
{
	SBCheckError(TElPKCS11SlotInfo_AddConsumer(_Handle, (Consumer != NULL) ? Consumer->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

bool TElPKCS11SlotInfo::PinNeeded()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SlotInfo_PinNeeded(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11SlotInfo::Refresh()
{
	SBCheckError(TElPKCS11SlotInfo_Refresh(_Handle));
}

SB_INLINE void TElPKCS11SlotInfo::RefreshSlot()
{
	SBCheckError(TElPKCS11SlotInfo_RefreshSlot(_Handle));
}

SB_INLINE void TElPKCS11SlotInfo::RefreshSupportedAlgorithms()
{
	SBCheckError(TElPKCS11SlotInfo_RefreshSupportedAlgorithms(_Handle));
}

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
SB_INLINE void TElPKCS11SlotInfo::RemoveConsumer(TElPKCS11Consumer &Consumer)
{
	SBCheckError(TElPKCS11SlotInfo_RemoveConsumer(_Handle, Consumer.getHandle()));
}

SB_INLINE void TElPKCS11SlotInfo::RemoveConsumer(TElPKCS11Consumer *Consumer)
{
	SBCheckError(TElPKCS11SlotInfo_RemoveConsumer(_Handle, (Consumer != NULL) ? Consumer->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

SB_INLINE int32_t TElPKCS11SlotInfo::get_ConsumerCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_ConsumerCount(_Handle, &OutResult));
	return OutResult;
}

bool TElPKCS11SlotInfo::get_LoggedIn()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SlotInfo_get_LoggedIn(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11SlotInfo::get_ReadOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SlotInfo_get_ReadOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElPKCS11SlotInfo::get_SlotManufacturerID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11SlotInfo_get_SlotManufacturerID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(4214827, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11SlotInfo::get_SlotDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11SlotInfo_get_SlotDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-180262983, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_SlotHardwareVersionHi()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_SlotHardwareVersionHi(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_SlotFirmwareVersionHi()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_SlotFirmwareVersionHi(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_SlotHardwareVersionLo()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_SlotHardwareVersionLo(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_SlotFirmwareVersionLo()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_SlotFirmwareVersionLo(_Handle, &OutResult));
	return OutResult;
}

bool TElPKCS11SlotInfo::get_TokenPresent()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SlotInfo_get_TokenPresent(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_TokenHardwareVersionHi()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_TokenHardwareVersionHi(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_TokenFirmwareVersionHi()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_TokenFirmwareVersionHi(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_TokenHardwareVersionLo()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_TokenHardwareVersionLo(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_TokenFirmwareVersionLo()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_TokenFirmwareVersionLo(_Handle, &OutResult));
	return OutResult;
}

void TElPKCS11SlotInfo::get_TokenManufacturerID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11SlotInfo_get_TokenManufacturerID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-695402202, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11SlotInfo::get_TokenLabel(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11SlotInfo_get_TokenLabel(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1007807862, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11SlotInfo::get_TokenModel(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11SlotInfo_get_TokenModel(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-450638009, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11SlotInfo::get_TokenSerial(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11SlotInfo_get_TokenSerial(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(385035951, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE uint32_t TElPKCS11SlotInfo::get_TokenFlags()
{
	uint32_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_TokenFlags(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPKCS11MODULE
TElPKCS11Module* TElPKCS11SlotInfo::get_Module()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11SlotInfo_get_Module(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Module)
		this->_Inst_Module = new TElPKCS11Module(hOutResult, ohFalse);
	else
		this->_Inst_Module->updateHandle(hOutResult);
	return this->_Inst_Module;
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
TElPKCS11Consumer* TElPKCS11SlotInfo::get_Consumers(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11SlotInfo_get_Consumers(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Consumers)
		this->_Inst_Consumers = new TElPKCS11Consumer(hOutResult, ohFalse);
	else
		this->_Inst_Consumers->updateHandle(hOutResult);
	return this->_Inst_Consumers;
}
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

SB_INLINE uint32_t TElPKCS11SlotInfo::get_SupportedPKCS11Mechanisms(int32_t Index)
{
	uint32_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_SupportedPKCS11Mechanisms(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t TElPKCS11SlotInfo::get_SlotID()
{
	uint32_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_SlotID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11SlotInfo::get_SupportedPKCS11MechanismCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_SupportedPKCS11MechanismCount(_Handle, &OutResult));
	return OutResult;
}

void TElPKCS11SlotInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS11MODULE
	this->_Inst_Module = NULL;
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
	this->_Inst_Consumers = NULL;
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */
}

TElPKCS11SlotInfo::TElPKCS11SlotInfo(TElPKCS11SlotInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS11SlotInfo::TElPKCS11SlotInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS11SlotInfo_Create(&_Handle));
}

TElPKCS11SlotInfo::~TElPKCS11SlotInfo()
{
#ifdef SB_USE_CLASS_TELPKCS11MODULE
	delete this->_Inst_Module;
	this->_Inst_Module = NULL;
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
	delete this->_Inst_Consumers;
	this->_Inst_Consumers = NULL;
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */
}
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
SB_INLINE void TElPKCS11SlotInfo::AddConsumer(TElPKCS11Consumer &Consumer)
{
	SBCheckError(TElPKCS11SlotInfo_AddConsumer(_Handle, Consumer.getHandle()));
}

SB_INLINE void TElPKCS11SlotInfo::AddConsumer(TElPKCS11Consumer *Consumer)
{
	SBCheckError(TElPKCS11SlotInfo_AddConsumer(_Handle, (Consumer != NULL) ? Consumer->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

bool TElPKCS11SlotInfo::PinNeeded()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SlotInfo_PinNeeded(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11SlotInfo::Refresh()
{
	SBCheckError(TElPKCS11SlotInfo_Refresh(_Handle));
}

SB_INLINE void TElPKCS11SlotInfo::RefreshSlot()
{
	SBCheckError(TElPKCS11SlotInfo_RefreshSlot(_Handle));
}

SB_INLINE void TElPKCS11SlotInfo::RefreshSupportedAlgorithms()
{
	SBCheckError(TElPKCS11SlotInfo_RefreshSupportedAlgorithms(_Handle));
}

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
SB_INLINE void TElPKCS11SlotInfo::RemoveConsumer(TElPKCS11Consumer &Consumer)
{
	SBCheckError(TElPKCS11SlotInfo_RemoveConsumer(_Handle, Consumer.getHandle()));
}

SB_INLINE void TElPKCS11SlotInfo::RemoveConsumer(TElPKCS11Consumer *Consumer)
{
	SBCheckError(TElPKCS11SlotInfo_RemoveConsumer(_Handle, (Consumer != NULL) ? Consumer->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

SB_INLINE int32_t TElPKCS11SlotInfo::get_ConsumerCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_ConsumerCount(_Handle, &OutResult));
	return OutResult;
}

bool TElPKCS11SlotInfo::get_LoggedIn()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SlotInfo_get_LoggedIn(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11SlotInfo::get_ReadOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SlotInfo_get_ReadOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElPKCS11SlotInfo::get_SlotManufacturerID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11SlotInfo_get_SlotManufacturerID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(4214827, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11SlotInfo::get_SlotDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11SlotInfo_get_SlotDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-180262983, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_SlotHardwareVersionHi()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_SlotHardwareVersionHi(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_SlotFirmwareVersionHi()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_SlotFirmwareVersionHi(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_SlotHardwareVersionLo()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_SlotHardwareVersionLo(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_SlotFirmwareVersionLo()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_SlotFirmwareVersionLo(_Handle, &OutResult));
	return OutResult;
}

bool TElPKCS11SlotInfo::get_TokenPresent()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SlotInfo_get_TokenPresent(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_TokenHardwareVersionHi()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_TokenHardwareVersionHi(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_TokenFirmwareVersionHi()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_TokenFirmwareVersionHi(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_TokenHardwareVersionLo()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_TokenHardwareVersionLo(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_TokenFirmwareVersionLo()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_TokenFirmwareVersionLo(_Handle, &OutResult));
	return OutResult;
}

void TElPKCS11SlotInfo::get_TokenManufacturerID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11SlotInfo_get_TokenManufacturerID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-695402202, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11SlotInfo::get_TokenLabel(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11SlotInfo_get_TokenLabel(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1007807862, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11SlotInfo::get_TokenModel(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11SlotInfo_get_TokenModel(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-450638009, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11SlotInfo::get_TokenSerial(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11SlotInfo_get_TokenSerial(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(385035951, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE uint32_t TElPKCS11SlotInfo::get_TokenFlags()
{
	uint32_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_TokenFlags(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPKCS11MODULE
TElPKCS11Module* TElPKCS11SlotInfo::get_Module()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11SlotInfo_get_Module(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Module)
		this->_Inst_Module = new TElPKCS11Module(hOutResult, ohFalse);
	else
		this->_Inst_Module->updateHandle(hOutResult);
	return this->_Inst_Module;
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
TElPKCS11Consumer* TElPKCS11SlotInfo::get_Consumers(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11SlotInfo_get_Consumers(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Consumers)
		this->_Inst_Consumers = new TElPKCS11Consumer(hOutResult, ohFalse);
	else
		this->_Inst_Consumers->updateHandle(hOutResult);
	return this->_Inst_Consumers;
}
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

SB_INLINE int64_t TElPKCS11SlotInfo::get_SupportedPKCS11Mechanisms(int32_t Index)
{
	int64_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_SupportedPKCS11Mechanisms(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElPKCS11SlotInfo::get_SlotID()
{
	int64_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_SlotID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11SlotInfo::get_SupportedPKCS11MechanismCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_SupportedPKCS11MechanismCount(_Handle, &OutResult));
	return OutResult;
}

void TElPKCS11SlotInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS11MODULE
	this->_Inst_Module = NULL;
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
	this->_Inst_Consumers = NULL;
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */
}

TElPKCS11SlotInfo::TElPKCS11SlotInfo(TElPKCS11SlotInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS11SlotInfo::TElPKCS11SlotInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS11SlotInfo_Create(&_Handle));
}

TElPKCS11SlotInfo::~TElPKCS11SlotInfo()
{
#ifdef SB_USE_CLASS_TELPKCS11MODULE
	delete this->_Inst_Module;
	this->_Inst_Module = NULL;
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
	delete this->_Inst_Consumers;
	this->_Inst_Consumers = NULL;
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */
}
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
#endif

#ifndef SB_IOS
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
SB_INLINE void TElPKCS11SlotInfo::AddConsumer(TElPKCS11Consumer &Consumer)
{
	SBCheckError(TElPKCS11SlotInfo_AddConsumer(_Handle, Consumer.getHandle()));
}

SB_INLINE void TElPKCS11SlotInfo::AddConsumer(TElPKCS11Consumer *Consumer)
{
	SBCheckError(TElPKCS11SlotInfo_AddConsumer(_Handle, (Consumer != NULL) ? Consumer->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

bool TElPKCS11SlotInfo::PinNeeded()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SlotInfo_PinNeeded(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11SlotInfo::Refresh()
{
	SBCheckError(TElPKCS11SlotInfo_Refresh(_Handle));
}

SB_INLINE void TElPKCS11SlotInfo::RefreshSlot()
{
	SBCheckError(TElPKCS11SlotInfo_RefreshSlot(_Handle));
}

SB_INLINE void TElPKCS11SlotInfo::RefreshSupportedAlgorithms()
{
	SBCheckError(TElPKCS11SlotInfo_RefreshSupportedAlgorithms(_Handle));
}

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
SB_INLINE void TElPKCS11SlotInfo::RemoveConsumer(TElPKCS11Consumer &Consumer)
{
	SBCheckError(TElPKCS11SlotInfo_RemoveConsumer(_Handle, Consumer.getHandle()));
}

SB_INLINE void TElPKCS11SlotInfo::RemoveConsumer(TElPKCS11Consumer *Consumer)
{
	SBCheckError(TElPKCS11SlotInfo_RemoveConsumer(_Handle, (Consumer != NULL) ? Consumer->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

SB_INLINE int32_t TElPKCS11SlotInfo::get_ConsumerCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_ConsumerCount(_Handle, &OutResult));
	return OutResult;
}

bool TElPKCS11SlotInfo::get_LoggedIn()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SlotInfo_get_LoggedIn(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11SlotInfo::get_ReadOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SlotInfo_get_ReadOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElPKCS11SlotInfo::get_SlotManufacturerID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11SlotInfo_get_SlotManufacturerID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(4214827, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11SlotInfo::get_SlotDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11SlotInfo_get_SlotDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-180262983, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_SlotHardwareVersionHi()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_SlotHardwareVersionHi(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_SlotFirmwareVersionHi()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_SlotFirmwareVersionHi(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_SlotHardwareVersionLo()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_SlotHardwareVersionLo(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_SlotFirmwareVersionLo()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_SlotFirmwareVersionLo(_Handle, &OutResult));
	return OutResult;
}

bool TElPKCS11SlotInfo::get_TokenPresent()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SlotInfo_get_TokenPresent(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_TokenHardwareVersionHi()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_TokenHardwareVersionHi(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_TokenFirmwareVersionHi()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_TokenFirmwareVersionHi(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_TokenHardwareVersionLo()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_TokenHardwareVersionLo(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElPKCS11SlotInfo::get_TokenFirmwareVersionLo()
{
	uint8_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_TokenFirmwareVersionLo(_Handle, &OutResult));
	return OutResult;
}

void TElPKCS11SlotInfo::get_TokenManufacturerID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11SlotInfo_get_TokenManufacturerID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-695402202, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11SlotInfo::get_TokenLabel(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11SlotInfo_get_TokenLabel(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1007807862, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11SlotInfo::get_TokenModel(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11SlotInfo_get_TokenModel(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-450638009, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11SlotInfo::get_TokenSerial(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11SlotInfo_get_TokenSerial(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(385035951, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE uint32_t TElPKCS11SlotInfo::get_TokenFlags()
{
	uint32_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_TokenFlags(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPKCS11MODULE
TElPKCS11Module* TElPKCS11SlotInfo::get_Module()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11SlotInfo_get_Module(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Module)
		this->_Inst_Module = new TElPKCS11Module(hOutResult, ohFalse);
	else
		this->_Inst_Module->updateHandle(hOutResult);
	return this->_Inst_Module;
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
TElPKCS11Consumer* TElPKCS11SlotInfo::get_Consumers(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11SlotInfo_get_Consumers(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Consumers)
		this->_Inst_Consumers = new TElPKCS11Consumer(hOutResult, ohFalse);
	else
		this->_Inst_Consumers->updateHandle(hOutResult);
	return this->_Inst_Consumers;
}
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE uint32_t TElPKCS11SlotInfo::get_SupportedPKCS11Mechanisms(int32_t Index)
#else
SB_INLINE int64_t TElPKCS11SlotInfo::get_SupportedPKCS11Mechanisms(int32_t Index)
#endif
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11SlotInfo_get_SupportedPKCS11Mechanisms(_Handle, Index, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE uint32_t TElPKCS11SlotInfo::get_SlotID()
#else
SB_INLINE int64_t TElPKCS11SlotInfo::get_SlotID()
#endif
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11SlotInfo_get_SlotID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11SlotInfo::get_SupportedPKCS11MechanismCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SlotInfo_get_SupportedPKCS11MechanismCount(_Handle, &OutResult));
	return OutResult;
}

void TElPKCS11SlotInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS11MODULE
	this->_Inst_Module = NULL;
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
	this->_Inst_Consumers = NULL;
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */
}

TElPKCS11SlotInfo::TElPKCS11SlotInfo(TElPKCS11SlotInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS11SlotInfo::TElPKCS11SlotInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS11SlotInfo_Create(&_Handle));
}

TElPKCS11SlotInfo::~TElPKCS11SlotInfo()
{
#ifdef SB_USE_CLASS_TELPKCS11MODULE
	delete this->_Inst_Module;
	this->_Inst_Module = NULL;
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
	delete this->_Inst_Consumers;
	this->_Inst_Consumers = NULL;
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */
}
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO

#ifdef SB_USE_CLASS_TELPKCS11ATTRIBUTELIST
SB_INLINE int32_t TElPKCS11SessionInfo::AddObject(TSBPKCS11ObjectType ObjectType, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList &Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SessionInfo_AddObject(_Handle, (TSBPKCS11ObjectTypeRaw)ObjectType, (int8_t)Token, (int8_t)Private, (int8_t)Modifiable, Attributes.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11SessionInfo::AddObject(TSBPKCS11ObjectType ObjectType, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList *Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SessionInfo_AddObject(_Handle, (TSBPKCS11ObjectTypeRaw)ObjectType, (int8_t)Token, (int8_t)Private, (int8_t)Modifiable, (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11ATTRIBUTELIST */

#ifdef SB_USE_CLASS_TELPKCS11ATTRIBUTELIST
SB_INLINE int32_t TElPKCS11SessionInfo::AddObject(TSBPKCS11ObjectType ObjectType, bool Token, TElPKCS11AttributeList &Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SessionInfo_AddObject_1(_Handle, (TSBPKCS11ObjectTypeRaw)ObjectType, (int8_t)Token, Attributes.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11SessionInfo::AddObject(TSBPKCS11ObjectType ObjectType, bool Token, TElPKCS11AttributeList *Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SessionInfo_AddObject_1(_Handle, (TSBPKCS11ObjectTypeRaw)ObjectType, (int8_t)Token, (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11ATTRIBUTELIST */

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE int32_t TElPKCS11SessionInfo::AddGeneratedObject(uint32_t Handle)
#else
SB_INLINE int32_t TElPKCS11SessionInfo::AddGeneratedObject(int64_t Handle)
#endif
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SessionInfo_AddGeneratedObject(_Handle, Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS11SessionInfo::RemoveObject(int32_t Index)
{
	SBCheckError(TElPKCS11SessionInfo_RemoveObject(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
SB_INLINE void TElPKCS11SessionInfo::RemoveObject(TElPKCS11Object &Obj)
{
	SBCheckError(TElPKCS11SessionInfo_RemoveObject_1(_Handle, Obj.getHandle()));
}

SB_INLINE void TElPKCS11SessionInfo::RemoveObject(TElPKCS11Object *Obj)
{
	SBCheckError(TElPKCS11SessionInfo_RemoveObject_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11SessionInfo::RemoveObjectByHandle(uint32_t Handle)
#else
SB_INLINE void TElPKCS11SessionInfo::RemoveObjectByHandle(int64_t Handle)
#endif
{
	SBCheckError(TElPKCS11SessionInfo_RemoveObjectByHandle(_Handle, Handle));
}

SB_INLINE void TElPKCS11SessionInfo::ClearObjects()
{
	SBCheckError(TElPKCS11SessionInfo_ClearObjects(_Handle));
}

#ifdef SB_USE_CLASS_TELPKCS11ATTRIBUTELIST
SB_INLINE int32_t TElPKCS11SessionInfo::CopyObject(int32_t Index, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList &Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SessionInfo_CopyObject(_Handle, Index, (int8_t)Token, (int8_t)Private, (int8_t)Modifiable, Attributes.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11SessionInfo::CopyObject(int32_t Index, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList *Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SessionInfo_CopyObject(_Handle, Index, (int8_t)Token, (int8_t)Private, (int8_t)Modifiable, (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11ATTRIBUTELIST */

#ifdef SB_USE_CLASSES_TELPKCS11ATTRIBUTELIST_AND_TELPKCS11OBJECT
SB_INLINE int32_t TElPKCS11SessionInfo::CopyObject(TElPKCS11Object &Obj, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList &Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SessionInfo_CopyObject_1(_Handle, Obj.getHandle(), (int8_t)Token, (int8_t)Private, (int8_t)Modifiable, Attributes.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11SessionInfo::CopyObject(TElPKCS11Object *Obj, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList *Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SessionInfo_CopyObject_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (int8_t)Token, (int8_t)Private, (int8_t)Modifiable, (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPKCS11ATTRIBUTELIST_AND_TELPKCS11OBJECT */

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE TElPKCS11ObjectHandle TElPKCS11SessionInfo::GetObjectByHandle(uint32_t Handle)
#else
SB_INLINE TElPKCS11ObjectHandle TElPKCS11SessionInfo::GetObjectByHandle(int64_t Handle)
#endif
{
	TElPKCS11ObjectHandle OutResult;
	SBCheckError(TElPKCS11SessionInfo_GetObjectByHandle(_Handle, Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
SB_INLINE TElPKCS11ObjectHandle TElPKCS11SessionInfo::GetObjectBySubjectOrID(TSBPKCS11ObjectType ObjectType, const std::vector<uint8_t> &Subject, const std::vector<uint8_t> &ID)
{
	TElPKCS11ObjectHandle OutResult;
	SBCheckError(TElPKCS11SessionInfo_GetObjectBySubjectOrID(_Handle, (TSBPKCS11ObjectTypeRaw)ObjectType, SB_STD_VECTOR_FRONT_ADR(Subject), (int32_t)Subject.size(), SB_STD_VECTOR_FRONT_ADR(ID), (int32_t)ID.size(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
SB_INLINE TElPKCS11ObjectHandle TElPKCS11SessionInfo::GetObjectBySubjectOrID(TSBPKCS11ObjectType ObjectType, const std::vector<uint8_t> &Subject, const std::vector<uint8_t> &ID, bool SubjectMustMatch, bool IDMustMatch)
{
	TElPKCS11ObjectHandle OutResult;
	SBCheckError(TElPKCS11SessionInfo_GetObjectBySubjectOrID_1(_Handle, (TSBPKCS11ObjectTypeRaw)ObjectType, SB_STD_VECTOR_FRONT_ADR(Subject), (int32_t)Subject.size(), SB_STD_VECTOR_FRONT_ADR(ID), (int32_t)ID.size(), (int8_t)SubjectMustMatch, (int8_t)IDMustMatch, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

bool TElPKCS11SessionInfo::Close()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SessionInfo_Close(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11SessionInfo::Login(TElPKCS11UserType UserType, const std::string &PIN)
{
	SBCheckError(TElPKCS11SessionInfo_Login(_Handle, (TElPKCS11UserTypeRaw)UserType, PIN.data(), (int32_t)PIN.length()));
}

SB_INLINE void TElPKCS11SessionInfo::Logout()
{
	SBCheckError(TElPKCS11SessionInfo_Logout(_Handle));
}

SB_INLINE void TElPKCS11SessionInfo::ClearObjectInstances()
{
	SBCheckError(TElPKCS11SessionInfo_ClearObjectInstances(_Handle));
}

SB_INLINE void TElPKCS11SessionInfo::RefreshObjectList()
{
	SBCheckError(TElPKCS11SessionInfo_RefreshObjectList(_Handle));
}

SB_INLINE void TElPKCS11SessionInfo::UpdateObjectList()
{
	SBCheckError(TElPKCS11SessionInfo_UpdateObjectList(_Handle));
}

SB_INLINE void TElPKCS11SessionInfo::AcquireSession()
{
	SBCheckError(TElPKCS11SessionInfo_AcquireSession(_Handle));
}

SB_INLINE void TElPKCS11SessionInfo::ReleaseSession()
{
	SBCheckError(TElPKCS11SessionInfo_ReleaseSession(_Handle));
}

SB_INLINE void TElPKCS11SessionInfo::InitPIN(const std::string &Pin)
{
	SBCheckError(TElPKCS11SessionInfo_InitPIN(_Handle, Pin.data(), (int32_t)Pin.length()));
}

SB_INLINE void TElPKCS11SessionInfo::SetPIN(const std::string &OldPin, const std::string &NewPin)
{
	SBCheckError(TElPKCS11SessionInfo_SetPIN(_Handle, OldPin.data(), (int32_t)OldPin.length(), NewPin.data(), (int32_t)NewPin.length()));
}

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
TElPKCS11Consumer* TElPKCS11SessionInfo::get_Consumer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11SessionInfo_get_Consumer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Consumer)
		this->_Inst_Consumer = new TElPKCS11Consumer(hOutResult, ohFalse);
	else
		this->_Inst_Consumer->updateHandle(hOutResult);
	return this->_Inst_Consumer;
}
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
TElPKCS11SlotInfo* TElPKCS11SessionInfo::get_Slot()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11SessionInfo_get_Slot(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Slot)
		this->_Inst_Slot = new TElPKCS11SlotInfo(hOutResult, ohFalse);
	else
		this->_Inst_Slot->updateHandle(hOutResult);
	return this->_Inst_Slot;
}
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE uint32_t TElPKCS11SessionInfo::get_Handle()
#else
SB_INLINE int64_t TElPKCS11SessionInfo::get_Handle()
#endif
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11SessionInfo_get_Handle(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProvider* TElPKCS11SessionInfo::get_CryptoProvider()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11SessionInfo_get_CryptoProvider(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProvider)
		this->_Inst_CryptoProvider = new TElCustomCryptoProvider(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProvider->updateHandle(hOutResult);
	return this->_Inst_CryptoProvider;
}

SB_INLINE void TElPKCS11SessionInfo::set_CryptoProvider(TElCustomCryptoProvider &Value)
{
	SBCheckError(TElPKCS11SessionInfo_set_CryptoProvider(_Handle, Value.getHandle()));
}

SB_INLINE void TElPKCS11SessionInfo::set_CryptoProvider(TElCustomCryptoProvider *Value)
{
	SBCheckError(TElPKCS11SessionInfo_set_CryptoProvider(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

SB_INLINE int32_t TElPKCS11SessionInfo::get_ObjectCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SessionInfo_get_ObjectCount(_Handle, &OutResult));
	return OutResult;
}

TSBPKCS11TokenAccessMode TElPKCS11SessionInfo::get_TokenAccessMode()
{
	TSBPKCS11TokenAccessModeRaw OutResultRaw = 0;
	SBCheckError(TElPKCS11SessionInfo_get_TokenAccessMode(_Handle, &OutResultRaw));
	return (TSBPKCS11TokenAccessMode)OutResultRaw;
}

SB_INLINE void TElPKCS11SessionInfo::set_TokenAccessMode(TSBPKCS11TokenAccessMode Value)
{
	SBCheckError(TElPKCS11SessionInfo_set_TokenAccessMode(_Handle, (TSBPKCS11TokenAccessModeRaw)Value));
}

bool TElPKCS11SessionInfo::get_IsOnDemandSession()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SessionInfo_get_IsOnDemandSession(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
TElPKCS11Object* TElPKCS11SessionInfo::get_Objects(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11SessionInfo_get_Objects(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Objects)
		this->_Inst_Objects = new TElPKCS11Object(hOutResult, ohFalse);
	else
		this->_Inst_Objects->updateHandle(hOutResult);
	return this->_Inst_Objects;
}
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

bool TElPKCS11SessionInfo::get_TokenProps(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SessionInfo_get_TokenProps(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElPKCS11SessionInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
	this->_Inst_Consumer = NULL;
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
	this->_Inst_Slot = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELPKCS11OBJECT
	this->_Inst_Objects = NULL;
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */
}

TElPKCS11SessionInfo::TElPKCS11SessionInfo(TElPKCS11SessionInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS11SessionInfo::TElPKCS11SessionInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS11SessionInfo_Create(&_Handle));
}

TElPKCS11SessionInfo::~TElPKCS11SessionInfo()
{
#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
	delete this->_Inst_Consumer;
	this->_Inst_Consumer = NULL;
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
	delete this->_Inst_Slot;
	this->_Inst_Slot = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	delete this->_Inst_CryptoProvider;
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELPKCS11OBJECT
	delete this->_Inst_Objects;
	this->_Inst_Objects = NULL;
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER

void TElPKCS11Consumer::get_UniqueID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11Consumer_get_UniqueID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1535540855, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElPKCS11Consumer::TElPKCS11Consumer(TElPKCS11ConsumerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPKCS11Consumer::TElPKCS11Consumer() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11Consumer_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */
#else

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO

#ifdef SB_USE_CLASS_TELPKCS11ATTRIBUTELIST
SB_INLINE int32_t TElPKCS11SessionInfo::AddObject(TSBPKCS11ObjectType ObjectType, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList &Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SessionInfo_AddObject(_Handle, (TSBPKCS11ObjectTypeRaw)ObjectType, (int8_t)Token, (int8_t)Private, (int8_t)Modifiable, Attributes.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11SessionInfo::AddObject(TSBPKCS11ObjectType ObjectType, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList *Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SessionInfo_AddObject(_Handle, (TSBPKCS11ObjectTypeRaw)ObjectType, (int8_t)Token, (int8_t)Private, (int8_t)Modifiable, (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11ATTRIBUTELIST */

#ifdef SB_USE_CLASS_TELPKCS11ATTRIBUTELIST
SB_INLINE int32_t TElPKCS11SessionInfo::AddObject(TSBPKCS11ObjectType ObjectType, bool Token, TElPKCS11AttributeList &Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SessionInfo_AddObject_1(_Handle, (TSBPKCS11ObjectTypeRaw)ObjectType, (int8_t)Token, Attributes.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11SessionInfo::AddObject(TSBPKCS11ObjectType ObjectType, bool Token, TElPKCS11AttributeList *Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SessionInfo_AddObject_1(_Handle, (TSBPKCS11ObjectTypeRaw)ObjectType, (int8_t)Token, (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11ATTRIBUTELIST */

#ifndef CPU64
SB_INLINE int32_t TElPKCS11SessionInfo::AddGeneratedObject(uint32_t Handle)
#else
SB_INLINE int32_t TElPKCS11SessionInfo::AddGeneratedObject(int64_t Handle)
#endif
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SessionInfo_AddGeneratedObject(_Handle, Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS11SessionInfo::RemoveObject(int32_t Index)
{
	SBCheckError(TElPKCS11SessionInfo_RemoveObject(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
SB_INLINE void TElPKCS11SessionInfo::RemoveObject(TElPKCS11Object &Obj)
{
	SBCheckError(TElPKCS11SessionInfo_RemoveObject_1(_Handle, Obj.getHandle()));
}

SB_INLINE void TElPKCS11SessionInfo::RemoveObject(TElPKCS11Object *Obj)
{
	SBCheckError(TElPKCS11SessionInfo_RemoveObject_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

#ifndef CPU64
SB_INLINE void TElPKCS11SessionInfo::RemoveObjectByHandle(uint32_t Handle)
#else
SB_INLINE void TElPKCS11SessionInfo::RemoveObjectByHandle(int64_t Handle)
#endif
{
	SBCheckError(TElPKCS11SessionInfo_RemoveObjectByHandle(_Handle, Handle));
}

SB_INLINE void TElPKCS11SessionInfo::ClearObjects()
{
	SBCheckError(TElPKCS11SessionInfo_ClearObjects(_Handle));
}

#ifdef SB_USE_CLASS_TELPKCS11ATTRIBUTELIST
SB_INLINE int32_t TElPKCS11SessionInfo::CopyObject(int32_t Index, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList &Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SessionInfo_CopyObject(_Handle, Index, (int8_t)Token, (int8_t)Private, (int8_t)Modifiable, Attributes.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11SessionInfo::CopyObject(int32_t Index, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList *Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SessionInfo_CopyObject(_Handle, Index, (int8_t)Token, (int8_t)Private, (int8_t)Modifiable, (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11ATTRIBUTELIST */

#ifdef SB_USE_CLASSES_TELPKCS11ATTRIBUTELIST_AND_TELPKCS11OBJECT
SB_INLINE int32_t TElPKCS11SessionInfo::CopyObject(TElPKCS11Object &Obj, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList &Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SessionInfo_CopyObject_1(_Handle, Obj.getHandle(), (int8_t)Token, (int8_t)Private, (int8_t)Modifiable, Attributes.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11SessionInfo::CopyObject(TElPKCS11Object *Obj, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList *Attributes)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SessionInfo_CopyObject_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (int8_t)Token, (int8_t)Private, (int8_t)Modifiable, (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPKCS11ATTRIBUTELIST_AND_TELPKCS11OBJECT */

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
#ifndef CPU64
SB_INLINE TElPKCS11ObjectHandle TElPKCS11SessionInfo::GetObjectByHandle(uint32_t Handle)
#else
SB_INLINE TElPKCS11ObjectHandle TElPKCS11SessionInfo::GetObjectByHandle(int64_t Handle)
#endif
{
	TElPKCS11ObjectHandle OutResult;
	SBCheckError(TElPKCS11SessionInfo_GetObjectByHandle(_Handle, Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
SB_INLINE TElPKCS11ObjectHandle TElPKCS11SessionInfo::GetObjectBySubjectOrID(TSBPKCS11ObjectType ObjectType, const std::vector<uint8_t> &Subject, const std::vector<uint8_t> &ID)
{
	TElPKCS11ObjectHandle OutResult;
	SBCheckError(TElPKCS11SessionInfo_GetObjectBySubjectOrID(_Handle, (TSBPKCS11ObjectTypeRaw)ObjectType, SB_STD_VECTOR_FRONT_ADR(Subject), (int32_t)Subject.size(), SB_STD_VECTOR_FRONT_ADR(ID), (int32_t)ID.size(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
SB_INLINE TElPKCS11ObjectHandle TElPKCS11SessionInfo::GetObjectBySubjectOrID(TSBPKCS11ObjectType ObjectType, const std::vector<uint8_t> &Subject, const std::vector<uint8_t> &ID, bool SubjectMustMatch, bool IDMustMatch)
{
	TElPKCS11ObjectHandle OutResult;
	SBCheckError(TElPKCS11SessionInfo_GetObjectBySubjectOrID_1(_Handle, (TSBPKCS11ObjectTypeRaw)ObjectType, SB_STD_VECTOR_FRONT_ADR(Subject), (int32_t)Subject.size(), SB_STD_VECTOR_FRONT_ADR(ID), (int32_t)ID.size(), (int8_t)SubjectMustMatch, (int8_t)IDMustMatch, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

bool TElPKCS11SessionInfo::Close()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SessionInfo_Close(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11SessionInfo::Login(TElPKCS11UserType UserType, const std::string &PIN)
{
	SBCheckError(TElPKCS11SessionInfo_Login(_Handle, (TElPKCS11UserTypeRaw)UserType, PIN.data(), (int32_t)PIN.length()));
}

SB_INLINE void TElPKCS11SessionInfo::Logout()
{
	SBCheckError(TElPKCS11SessionInfo_Logout(_Handle));
}

SB_INLINE void TElPKCS11SessionInfo::ClearObjectInstances()
{
	SBCheckError(TElPKCS11SessionInfo_ClearObjectInstances(_Handle));
}

SB_INLINE void TElPKCS11SessionInfo::RefreshObjectList()
{
	SBCheckError(TElPKCS11SessionInfo_RefreshObjectList(_Handle));
}

SB_INLINE void TElPKCS11SessionInfo::UpdateObjectList()
{
	SBCheckError(TElPKCS11SessionInfo_UpdateObjectList(_Handle));
}

SB_INLINE void TElPKCS11SessionInfo::AcquireSession()
{
	SBCheckError(TElPKCS11SessionInfo_AcquireSession(_Handle));
}

SB_INLINE void TElPKCS11SessionInfo::ReleaseSession()
{
	SBCheckError(TElPKCS11SessionInfo_ReleaseSession(_Handle));
}

SB_INLINE void TElPKCS11SessionInfo::InitPIN(const std::string &Pin)
{
	SBCheckError(TElPKCS11SessionInfo_InitPIN(_Handle, Pin.data(), (int32_t)Pin.length()));
}

SB_INLINE void TElPKCS11SessionInfo::SetPIN(const std::string &OldPin, const std::string &NewPin)
{
	SBCheckError(TElPKCS11SessionInfo_SetPIN(_Handle, OldPin.data(), (int32_t)OldPin.length(), NewPin.data(), (int32_t)NewPin.length()));
}

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
TElPKCS11Consumer* TElPKCS11SessionInfo::get_Consumer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11SessionInfo_get_Consumer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Consumer)
		this->_Inst_Consumer = new TElPKCS11Consumer(hOutResult, ohFalse);
	else
		this->_Inst_Consumer->updateHandle(hOutResult);
	return this->_Inst_Consumer;
}
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
TElPKCS11SlotInfo* TElPKCS11SessionInfo::get_Slot()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11SessionInfo_get_Slot(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Slot)
		this->_Inst_Slot = new TElPKCS11SlotInfo(hOutResult, ohFalse);
	else
		this->_Inst_Slot->updateHandle(hOutResult);
	return this->_Inst_Slot;
}
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11SessionInfo::get_Handle()
#else
SB_INLINE int64_t TElPKCS11SessionInfo::get_Handle()
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11SessionInfo_get_Handle(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProvider* TElPKCS11SessionInfo::get_CryptoProvider()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11SessionInfo_get_CryptoProvider(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProvider)
		this->_Inst_CryptoProvider = new TElCustomCryptoProvider(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProvider->updateHandle(hOutResult);
	return this->_Inst_CryptoProvider;
}

SB_INLINE void TElPKCS11SessionInfo::set_CryptoProvider(TElCustomCryptoProvider &Value)
{
	SBCheckError(TElPKCS11SessionInfo_set_CryptoProvider(_Handle, Value.getHandle()));
}

SB_INLINE void TElPKCS11SessionInfo::set_CryptoProvider(TElCustomCryptoProvider *Value)
{
	SBCheckError(TElPKCS11SessionInfo_set_CryptoProvider(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

SB_INLINE int32_t TElPKCS11SessionInfo::get_ObjectCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11SessionInfo_get_ObjectCount(_Handle, &OutResult));
	return OutResult;
}

TSBPKCS11TokenAccessMode TElPKCS11SessionInfo::get_TokenAccessMode()
{
	TSBPKCS11TokenAccessModeRaw OutResultRaw = 0;
	SBCheckError(TElPKCS11SessionInfo_get_TokenAccessMode(_Handle, &OutResultRaw));
	return (TSBPKCS11TokenAccessMode)OutResultRaw;
}

SB_INLINE void TElPKCS11SessionInfo::set_TokenAccessMode(TSBPKCS11TokenAccessMode Value)
{
	SBCheckError(TElPKCS11SessionInfo_set_TokenAccessMode(_Handle, (TSBPKCS11TokenAccessModeRaw)Value));
}

bool TElPKCS11SessionInfo::get_IsOnDemandSession()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SessionInfo_get_IsOnDemandSession(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
TElPKCS11Object* TElPKCS11SessionInfo::get_Objects(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11SessionInfo_get_Objects(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Objects)
		this->_Inst_Objects = new TElPKCS11Object(hOutResult, ohFalse);
	else
		this->_Inst_Objects->updateHandle(hOutResult);
	return this->_Inst_Objects;
}
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

bool TElPKCS11SessionInfo::get_TokenProps(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SessionInfo_get_TokenProps(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElPKCS11SessionInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
	this->_Inst_Consumer = NULL;
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
	this->_Inst_Slot = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELPKCS11OBJECT
	this->_Inst_Objects = NULL;
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */
}

TElPKCS11SessionInfo::TElPKCS11SessionInfo(TElPKCS11SessionInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS11SessionInfo::TElPKCS11SessionInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS11SessionInfo_Create(&_Handle));
}

TElPKCS11SessionInfo::~TElPKCS11SessionInfo()
{
#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
	delete this->_Inst_Consumer;
	this->_Inst_Consumer = NULL;
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
	delete this->_Inst_Slot;
	this->_Inst_Slot = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	delete this->_Inst_CryptoProvider;
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELPKCS11OBJECT
	delete this->_Inst_Objects;
	this->_Inst_Objects = NULL;
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::GetFunctionList(PPKCS11FunctionList &FunctionList)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::GetFunctionList(PPKCS11FunctionList &FunctionList)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_GetFunctionList(_Handle, &FunctionList, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::Initialize(PPKCS11InitializeArgs pArgs)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::Initialize(PPKCS11InitializeArgs pArgs)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_Initialize(_Handle, pArgs, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::Finalize(void * pReserved)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::Finalize(void * pReserved)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_Finalize(_Handle, pReserved, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::GetInfo(TPKCS11Info &pInfo)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::GetInfo(TPKCS11Info &pInfo)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_GetInfo(_Handle, &pInfo, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::GetSlotList(uint8_t tokenPresent, uint32_t &pSlotList, uint32_t &pulCount)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::GetSlotList(uint8_t tokenPresent, int64_t &pSlotList, int64_t &pulCount)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_GetSlotList(_Handle, tokenPresent, &pSlotList, &pulCount, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::GetSlotInfo(uint32_t slotID, TPKCS11SlotInfo &pInfo)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::GetSlotInfo(int64_t slotID, TPKCS11SlotInfo &pInfo)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_GetSlotInfo(_Handle, slotID, &pInfo, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::GetTokenInfo(uint32_t slotID, TPKCS11TokenInfo &pInfo)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::GetTokenInfo(int64_t slotID, TPKCS11TokenInfo &pInfo)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_GetTokenInfo(_Handle, slotID, &pInfo, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::OpenSession(uint32_t slotID, uint32_t flags, void * CallbackData, void * NotifyProc, uint32_t &SessionHandle)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::OpenSession(int64_t slotID, int64_t flags, void * CallbackData, void * NotifyProc, int64_t &SessionHandle)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_OpenSession(_Handle, slotID, flags, CallbackData, NotifyProc, &SessionHandle, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::GetSessionInfo(uint32_t hSession, TPKCS11SessionInfo &pInfo)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::GetSessionInfo(int64_t hSession, TPKCS11SessionInfo &pInfo)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_GetSessionInfo(_Handle, hSession, &pInfo, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::CloseSession(uint32_t hSession)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::CloseSession(int64_t hSession)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_CloseSession(_Handle, hSession, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::Login(uint32_t hSession, uint32_t userType, char * pPin, uint32_t ulPinLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::Login(int64_t hSession, int64_t userType, char * pPin, int64_t ulPinLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_Login(_Handle, hSession, userType, pPin, ulPinLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::Logout(uint32_t hSession)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::Logout(int64_t hSession)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_Logout(_Handle, hSession, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::FindObjectsInit(uint32_t hSession, SB_CK_ATTRIBUTE_PTR pAttributes, uint32_t ulCount)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::FindObjectsInit(int64_t hSession, SB_CK_ATTRIBUTE_PTR pAttributes, int64_t ulCount)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_FindObjectsInit(_Handle, hSession, pAttributes, ulCount, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::FindObjects(uint32_t hSession, uint32_t &phObject, uint32_t ulMaxObjectCount, uint32_t &pulObjectCount)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::FindObjects(int64_t hSession, int64_t &phObject, int64_t ulMaxObjectCount, int64_t &pulObjectCount)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_FindObjects(_Handle, hSession, &phObject, ulMaxObjectCount, &pulObjectCount, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::FindObjectsFinal(uint32_t hSession)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::FindObjectsFinal(int64_t hSession)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_FindObjectsFinal(_Handle, hSession, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::GetAttributeValue(uint32_t hSession, uint32_t hObject, void * pTemplate, uint32_t ulCount)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::GetAttributeValue(int64_t hSession, int64_t hObject, void * pTemplate, int64_t ulCount)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_GetAttributeValue(_Handle, hSession, hObject, pTemplate, ulCount, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::DestroyObject(uint32_t hSession, uint32_t hObject)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::DestroyObject(int64_t hSession, int64_t hObject)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_DestroyObject(_Handle, hSession, hObject, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::CreateObject(uint32_t hSession, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount, uint32_t &hObject)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::CreateObject(int64_t hSession, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount, int64_t &hObject)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_CreateObject(_Handle, hSession, pTemplate, ulCount, &hObject, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::SignInit(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::SignInit(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_SignInit(_Handle, hSession, pMechanism, hKey, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::Sign(uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pSignature, uint32_t * pulSignatureLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::Sign(int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pSignature, int64_t * pulSignatureLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_Sign(_Handle, hSession, pData, ulDataLen, pSignature, pulSignatureLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::DecryptInit(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::DecryptInit(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_DecryptInit(_Handle, hSession, pMechanism, hKey, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::Decrypt(uint32_t hSession, uint8_t * pEncryptedData, uint32_t ulEncryptedDataLen, uint8_t * pData, uint32_t * pulDataLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::Decrypt(int64_t hSession, uint8_t * pEncryptedData, int64_t ulEncryptedDataLen, uint8_t * pData, int64_t * pulDataLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_Decrypt(_Handle, hSession, pEncryptedData, ulEncryptedDataLen, pData, pulDataLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::WaitForSlotEvent(uint32_t flags, uint32_t &pSlot, void * pReserved)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::WaitForSlotEvent(int64_t flags, int64_t &pSlot, void * pReserved)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_WaitForSlotEvent(_Handle, flags, &pSlot, pReserved, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::GetMechanismList(uint32_t slotID, uint32_t * pMechanismList, uint32_t &pulCount)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::GetMechanismList(int64_t slotID, int64_t * pMechanismList, int64_t &pulCount)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_GetMechanismList(_Handle, slotID, pMechanismList, &pulCount, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::GetMechanismInfo(uint32_t slotID, uint32_t mechanism_type, TPKCS11MechanismInfo &pInfo)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::GetMechanismInfo(int64_t slotID, int64_t mechanism_type, TPKCS11MechanismInfo &pInfo)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_GetMechanismInfo(_Handle, slotID, mechanism_type, &pInfo, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::InitToken(uint32_t slotID, char * pPin, uint32_t ulPinLen, char * pLabel)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::InitToken(int64_t slotID, char * pPin, int64_t ulPinLen, char * pLabel)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_InitToken(_Handle, slotID, pPin, ulPinLen, pLabel, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::InitPIN(uint32_t hSession, char * pPin, uint32_t ulPinLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::InitPIN(int64_t hSession, char * pPin, int64_t ulPinLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_InitPIN(_Handle, hSession, pPin, ulPinLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::SetPIN(uint32_t hSession, char * pOldPin, uint32_t ulOldLen, char * pNewPin, uint32_t ulNewLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::SetPIN(int64_t hSession, char * pOldPin, int64_t ulOldLen, char * pNewPin, int64_t ulNewLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_SetPIN(_Handle, hSession, pOldPin, ulOldLen, pNewPin, ulNewLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::CloseAllSessions(uint32_t slotID)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::CloseAllSessions(int64_t slotID)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_CloseAllSessions(_Handle, slotID, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::GetOperationState(uint32_t hSession, uint8_t &pOperationState, uint32_t &pulOperationStateLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::GetOperationState(int64_t hSession, uint8_t &pOperationState, int64_t &pulOperationStateLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_GetOperationState(_Handle, hSession, &pOperationState, &pulOperationStateLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::SetOperationState(uint32_t hSession, uint8_t * pOperationState, uint32_t ulOperationStateLen, uint32_t hEncryptionKey, uint32_t hAuthenticationKey)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::SetOperationState(int64_t hSession, uint8_t * pOperationState, int64_t ulOperationStateLen, int64_t hEncryptionKey, int64_t hAuthenticationKey)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_SetOperationState(_Handle, hSession, pOperationState, ulOperationStateLen, hEncryptionKey, hAuthenticationKey, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::CopyObject(uint32_t hSession, uint32_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount, uint32_t &phNewObject)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::CopyObject(int64_t hSession, int64_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount, int64_t &phNewObject)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_CopyObject(_Handle, hSession, hObject, pTemplate, ulCount, &phNewObject, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::GetObjectSize(uint32_t hSession, uint32_t hObject, uint32_t &pulSize)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::GetObjectSize(int64_t hSession, int64_t hObject, int64_t &pulSize)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_GetObjectSize(_Handle, hSession, hObject, &pulSize, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::SetAttributeValue(uint32_t hSession, uint32_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::SetAttributeValue(int64_t hSession, int64_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_SetAttributeValue(_Handle, hSession, hObject, pTemplate, ulCount, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::EncryptInit(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::EncryptInit(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_EncryptInit(_Handle, hSession, pMechanism, hKey, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::Encrypt(uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pEncryptedData, uint32_t &pulEncryptedDataLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::Encrypt(int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pEncryptedData, int64_t &pulEncryptedDataLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_Encrypt(_Handle, hSession, pData, ulDataLen, pEncryptedData, &pulEncryptedDataLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::EncryptUpdate(uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint8_t * pEncryptedPart, uint32_t &pulEncryptedPartLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::EncryptUpdate(int64_t hSession, uint8_t * pPart, int64_t ulPartLen, uint8_t * pEncryptedPart, int64_t &pulEncryptedPartLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_EncryptUpdate(_Handle, hSession, pPart, ulPartLen, pEncryptedPart, &pulEncryptedPartLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::EncryptFinal(uint32_t hSession, uint8_t * pLastEncryptedPart, uint32_t &pulLastEncryptedPartLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::EncryptFinal(int64_t hSession, uint8_t * pLastEncryptedPart, int64_t &pulLastEncryptedPartLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_EncryptFinal(_Handle, hSession, pLastEncryptedPart, &pulLastEncryptedPartLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::DecryptUpdate(uint32_t hSession, uint8_t * pEncryptedPart, uint32_t ulEncryptedPartLen, uint8_t * pPart, uint32_t &pulPartLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::DecryptUpdate(int64_t hSession, uint8_t * pEncryptedPart, int64_t ulEncryptedPartLen, uint8_t * pPart, int64_t &pulPartLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_DecryptUpdate(_Handle, hSession, pEncryptedPart, ulEncryptedPartLen, pPart, &pulPartLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::DecryptFinal(uint32_t hSession, uint8_t * pLastPart, uint32_t &pulLastPartLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::DecryptFinal(int64_t hSession, uint8_t * pLastPart, int64_t &pulLastPartLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_DecryptFinal(_Handle, hSession, pLastPart, &pulLastPartLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::DigestInit(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::DigestInit(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_DigestInit(_Handle, hSession, pMechanism, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::Digest(uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t &pDigest, uint32_t &pulDigestLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::Digest(int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t &pDigest, int64_t &pulDigestLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_Digest(_Handle, hSession, pData, ulDataLen, &pDigest, &pulDigestLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::DigestUpdate(uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::DigestUpdate(int64_t hSession, uint8_t * pPart, int64_t ulPartLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_DigestUpdate(_Handle, hSession, pPart, ulPartLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::DigestKey(uint32_t hSession, uint32_t hKey)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::DigestKey(int64_t hSession, int64_t hKey)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_DigestKey(_Handle, hSession, hKey, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::DigestFinal(uint32_t hSession, uint8_t * pDigest, uint32_t &pulDigestLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::DigestFinal(int64_t hSession, uint8_t * pDigest, int64_t &pulDigestLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_DigestFinal(_Handle, hSession, pDigest, &pulDigestLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::SignUpdate(uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::SignUpdate(int64_t hSession, uint8_t * pPart, int64_t ulPartLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_SignUpdate(_Handle, hSession, pPart, ulPartLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::SignFinal(uint32_t hSession, uint8_t * pSignature, uint32_t &pulSignatureLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::SignFinal(int64_t hSession, uint8_t * pSignature, int64_t &pulSignatureLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_SignFinal(_Handle, hSession, pSignature, &pulSignatureLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::SignRecoverInit(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::SignRecoverInit(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_SignRecoverInit(_Handle, hSession, pMechanism, hKey, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::SignRecover(uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t &pSignature, uint32_t &pulSignatureLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::SignRecover(int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t &pSignature, int64_t &pulSignatureLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_SignRecover(_Handle, hSession, pData, ulDataLen, &pSignature, &pulSignatureLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::VerifyInit(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::VerifyInit(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_VerifyInit(_Handle, hSession, pMechanism, hKey, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::Verify(uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pSignature, uint32_t ulSignatureLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::Verify(int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pSignature, int64_t ulSignatureLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_Verify(_Handle, hSession, pData, ulDataLen, pSignature, ulSignatureLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::VerifyUpdate(uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::VerifyUpdate(int64_t hSession, uint8_t * pPart, int64_t ulPartLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_VerifyUpdate(_Handle, hSession, pPart, ulPartLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::VerifyFinal(uint32_t hSession, uint8_t * pSignature, uint32_t ulSignatureLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::VerifyFinal(int64_t hSession, uint8_t * pSignature, int64_t ulSignatureLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_VerifyFinal(_Handle, hSession, pSignature, ulSignatureLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::VerifyRecoverInit(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::VerifyRecoverInit(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_VerifyRecoverInit(_Handle, hSession, pMechanism, hKey, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::VerifyRecover(uint32_t hSession, uint8_t * pSignature, uint32_t ulSignatureLen, uint8_t &pData, uint32_t &pulDataLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::VerifyRecover(int64_t hSession, uint8_t * pSignature, int64_t ulSignatureLen, uint8_t &pData, int64_t &pulDataLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_VerifyRecover(_Handle, hSession, pSignature, ulSignatureLen, &pData, &pulDataLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::DigestEncryptUpdate(uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint8_t &pEncryptedPart, uint32_t &pulEncryptedPartLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::DigestEncryptUpdate(int64_t hSession, uint8_t * pPart, int64_t ulPartLen, uint8_t &pEncryptedPart, int64_t &pulEncryptedPartLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_DigestEncryptUpdate(_Handle, hSession, pPart, ulPartLen, &pEncryptedPart, &pulEncryptedPartLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::DecryptDigestUpdate(uint32_t hSession, uint8_t * pEncryptedPart, uint32_t ulEncryptedPartLen, uint8_t &pPart, uint32_t &pulPartLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::DecryptDigestUpdate(int64_t hSession, uint8_t * pEncryptedPart, int64_t ulEncryptedPartLen, uint8_t &pPart, int64_t &pulPartLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_DecryptDigestUpdate(_Handle, hSession, pEncryptedPart, ulEncryptedPartLen, &pPart, &pulPartLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::SignEncryptUpdate(uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint8_t &pEncryptedPart, uint32_t &pulEncryptedPartLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::SignEncryptUpdate(int64_t hSession, uint8_t * pPart, int64_t ulPartLen, uint8_t &pEncryptedPart, int64_t &pulEncryptedPartLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_SignEncryptUpdate(_Handle, hSession, pPart, ulPartLen, &pEncryptedPart, &pulEncryptedPartLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::DecryptVerifyUpdate(uint32_t hSession, uint8_t * pEncryptedPart, uint32_t ulEncryptedPartLen, uint8_t &pPart, uint32_t &pulPartLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::DecryptVerifyUpdate(int64_t hSession, uint8_t * pEncryptedPart, int64_t ulEncryptedPartLen, uint8_t &pPart, int64_t &pulPartLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_DecryptVerifyUpdate(_Handle, hSession, pEncryptedPart, ulEncryptedPartLen, &pPart, &pulPartLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::GenerateKey(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount, uint32_t &phKey)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::GenerateKey(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount, int64_t &phKey)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_GenerateKey(_Handle, hSession, pMechanism, pTemplate, ulCount, &phKey, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::GenerateKeyPair(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pPublicKeyTemplate, uint32_t ulPublicKeyAttributeCount, SB_CK_ATTRIBUTE_PTR pPrivateKeyTemplate, uint32_t ulPrivateKeyAttributeCount, uint32_t &phPublicKey, uint32_t &phPrivateKey)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::GenerateKeyPair(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pPublicKeyTemplate, int64_t ulPublicKeyAttributeCount, SB_CK_ATTRIBUTE_PTR pPrivateKeyTemplate, int64_t ulPrivateKeyAttributeCount, int64_t &phPublicKey, int64_t &phPrivateKey)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_GenerateKeyPair(_Handle, hSession, pMechanism, pPublicKeyTemplate, ulPublicKeyAttributeCount, pPrivateKeyTemplate, ulPrivateKeyAttributeCount, &phPublicKey, &phPrivateKey, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::WrapKey(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hWrappingKey, uint32_t hKey, uint8_t * pWrappedKey, uint32_t &pulWrappedKeyLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::WrapKey(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hWrappingKey, int64_t hKey, uint8_t * pWrappedKey, int64_t &pulWrappedKeyLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_WrapKey(_Handle, hSession, pMechanism, hWrappingKey, hKey, pWrappedKey, &pulWrappedKeyLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::UnwrapKey(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hUnwrappingKey, uint8_t * pWrappedKey, uint32_t ulWrappedKeyLen, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulAttributeCount, uint32_t &phKey)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::UnwrapKey(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hUnwrappingKey, uint8_t * pWrappedKey, int64_t ulWrappedKeyLen, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulAttributeCount, int64_t &phKey)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_UnwrapKey(_Handle, hSession, pMechanism, hUnwrappingKey, pWrappedKey, ulWrappedKeyLen, pTemplate, ulAttributeCount, &phKey, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::DeriveKey(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hBaseKey, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulAttributeCount, uint32_t &phKey)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::DeriveKey(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hBaseKey, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulAttributeCount, int64_t &phKey)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_DeriveKey(_Handle, hSession, pMechanism, hBaseKey, pTemplate, ulAttributeCount, &phKey, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::SeedRandom(uint32_t hSession, uint8_t * pSeed, uint32_t ulSeedLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::SeedRandom(int64_t hSession, uint8_t * pSeed, int64_t ulSeedLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_SeedRandom(_Handle, hSession, pSeed, ulSeedLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::GenerateRandom(uint32_t hSession, uint8_t * pRandomData, uint32_t ulRandomLen)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::GenerateRandom(int64_t hSession, uint8_t * pRandomData, int64_t ulRandomLen)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_GenerateRandom(_Handle, hSession, pRandomData, ulRandomLen, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::GetFunctionStatus(uint32_t hSession)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::GetFunctionStatus(int64_t hSession)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_GetFunctionStatus(_Handle, hSession, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t TElPKCS11FunctionsManager::CancelFunction(uint32_t hSession)
#else
SB_INLINE int64_t TElPKCS11FunctionsManager::CancelFunction(int64_t hSession)
#endif
{
#ifndef CPU64
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11FunctionsManager_CancelFunction(_Handle, hSession, &OutResult));
	return OutResult;
}

void TElPKCS11FunctionsManager::get_UniqueID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11FunctionsManager_get_UniqueID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1230720524, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnUniqueIDNeeded(TSBUniqueIDNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnUniqueIDNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnUniqueIDNeeded(TSBUniqueIDNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnUniqueIDNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnGetFunctionListNeeded(TSBGetFunctionListNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnGetFunctionListNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnGetFunctionListNeeded(TSBGetFunctionListNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnGetFunctionListNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnInitializeNeeded(TSBInitializeNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnInitializeNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnInitializeNeeded(TSBInitializeNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnInitializeNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnFinalizeNeeded(TSBFinalizeNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnFinalizeNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnFinalizeNeeded(TSBFinalizeNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnFinalizeNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnGetInfoNeeded(TSBGetInfoNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnGetInfoNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnGetInfoNeeded(TSBGetInfoNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnGetInfoNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnGetSlotListNeeded(TSBGetSlotListNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnGetSlotListNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnGetSlotListNeeded(TSBGetSlotListNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnGetSlotListNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnGetSlotInfoNeeded(TSBGetSlotInfoNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnGetSlotInfoNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnGetSlotInfoNeeded(TSBGetSlotInfoNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnGetSlotInfoNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnGetTokenInfoNeeded(TSBGetTokenInfoNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnGetTokenInfoNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnGetTokenInfoNeeded(TSBGetTokenInfoNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnGetTokenInfoNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnOpenSessionNeeded(TSBOpenSessionNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnOpenSessionNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnOpenSessionNeeded(TSBOpenSessionNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnOpenSessionNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnGetSessionInfoNeeded(TSBGetSessionInfoNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnGetSessionInfoNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnGetSessionInfoNeeded(TSBGetSessionInfoNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnGetSessionInfoNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnCloseSessionNeeded(TSBCloseSessionNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnCloseSessionNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnCloseSessionNeeded(TSBCloseSessionNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnCloseSessionNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnLoginNeeded(TSBLoginNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnLoginNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnLoginNeeded(TSBLoginNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnLoginNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnLogoutNeeded(TSBLogoutNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnLogoutNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnLogoutNeeded(TSBLogoutNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnLogoutNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnFindObjectsInitNeeded(TSBFindObjectsInitNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnFindObjectsInitNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnFindObjectsInitNeeded(TSBFindObjectsInitNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnFindObjectsInitNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnFindObjectsNeeded(TSBFindObjectsNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnFindObjectsNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnFindObjectsNeeded(TSBFindObjectsNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnFindObjectsNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnFindObjectsFinalNeeded(TSBFindObjectsFinalNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnFindObjectsFinalNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnFindObjectsFinalNeeded(TSBFindObjectsFinalNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnFindObjectsFinalNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnGetAttributeValueNeeded(TSBGetAttributeValueNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnGetAttributeValueNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnGetAttributeValueNeeded(TSBGetAttributeValueNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnGetAttributeValueNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnDestroyObjectNeeded(TSBDestroyObjectNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnDestroyObjectNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnDestroyObjectNeeded(TSBDestroyObjectNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnDestroyObjectNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnCreateObjectNeeded(TSBCreateObjectNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnCreateObjectNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnCreateObjectNeeded(TSBCreateObjectNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnCreateObjectNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnSignInitNeeded(TSBSignInitNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnSignInitNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnSignInitNeeded(TSBSignInitNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnSignInitNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnSignNeeded(TSBSignNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnSignNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnSignNeeded(TSBSignNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnSignNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnDecryptInitNeeded(TSBDecryptInitNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnDecryptInitNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnDecryptInitNeeded(TSBDecryptInitNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnDecryptInitNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnDecryptNeeded(TSBDecryptNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnDecryptNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnDecryptNeeded(TSBDecryptNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnDecryptNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnWaitForSlotEventNeeded(TSBWaitForSlotEventNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnWaitForSlotEventNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnWaitForSlotEventNeeded(TSBWaitForSlotEventNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnWaitForSlotEventNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnGetMechanismListNeeded(TSBGetMechanismListNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnGetMechanismListNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnGetMechanismListNeeded(TSBGetMechanismListNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnGetMechanismListNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnGetMechanismInfoNeeded(TSBGetMechanismInfoNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnGetMechanismInfoNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnGetMechanismInfoNeeded(TSBGetMechanismInfoNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnGetMechanismInfoNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnInitTokenNeeded(TSBInitTokenNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnInitTokenNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnInitTokenNeeded(TSBInitTokenNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnInitTokenNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnInitPINNeeded(TSBInitPINNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnInitPINNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnInitPINNeeded(TSBInitPINNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnInitPINNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnSetPINNeeded(TSBSetPINNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnSetPINNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnSetPINNeeded(TSBSetPINNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnSetPINNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnCloseAllSessionsNeeded(TSBCloseAllSessionsNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnCloseAllSessionsNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnCloseAllSessionsNeeded(TSBCloseAllSessionsNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnCloseAllSessionsNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnGetOperationStateNeeded(TSBGetOperationStateNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnGetOperationStateNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnGetOperationStateNeeded(TSBGetOperationStateNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnGetOperationStateNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnSetOperationStateNeeded(TSBSetOperationStateNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnSetOperationStateNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnSetOperationStateNeeded(TSBSetOperationStateNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnSetOperationStateNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnCopyObjectNeeded(TSBCopyObjectNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnCopyObjectNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnCopyObjectNeeded(TSBCopyObjectNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnCopyObjectNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnGetObjectSizeNeeded(TSBGetObjectSizeNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnGetObjectSizeNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnGetObjectSizeNeeded(TSBGetObjectSizeNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnGetObjectSizeNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnSetAttributeValueNeeded(TSBSetAttributeValueNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnSetAttributeValueNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnSetAttributeValueNeeded(TSBSetAttributeValueNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnSetAttributeValueNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnEncryptInitNeeded(TSBEncryptInitNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnEncryptInitNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnEncryptInitNeeded(TSBEncryptInitNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnEncryptInitNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnEncryptNeeded(TSBEncryptNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnEncryptNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnEncryptNeeded(TSBEncryptNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnEncryptNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnEncryptUpdateNeeded(TSBEncryptUpdateNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnEncryptUpdateNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnEncryptUpdateNeeded(TSBEncryptUpdateNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnEncryptUpdateNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnEncryptFinalNeeded(TSBEncryptFinalNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnEncryptFinalNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnEncryptFinalNeeded(TSBEncryptFinalNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnEncryptFinalNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnDecryptUpdateNeeded(TSBDecryptUpdateNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnDecryptUpdateNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnDecryptUpdateNeeded(TSBDecryptUpdateNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnDecryptUpdateNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnDecryptFinalNeeded(TSBDecryptFinalNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnDecryptFinalNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnDecryptFinalNeeded(TSBDecryptFinalNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnDecryptFinalNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnDigestInitNeeded(TSBDigestInitNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnDigestInitNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnDigestInitNeeded(TSBDigestInitNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnDigestInitNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnDigestNeeded(TSBDigestNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnDigestNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnDigestNeeded(TSBDigestNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnDigestNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnDigestUpdateNeeded(TSBDigestUpdateNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnDigestUpdateNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnDigestUpdateNeeded(TSBDigestUpdateNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnDigestUpdateNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnDigestKeyNeeded(TSBDigestKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnDigestKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnDigestKeyNeeded(TSBDigestKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnDigestKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnDigestFinalNeeded(TSBDigestFinalNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnDigestFinalNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnDigestFinalNeeded(TSBDigestFinalNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnDigestFinalNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnSignUpdateNeeded(TSBSignUpdateNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnSignUpdateNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnSignUpdateNeeded(TSBSignUpdateNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnSignUpdateNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnSignFinalNeeded(TSBSignFinalNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnSignFinalNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnSignFinalNeeded(TSBSignFinalNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnSignFinalNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnSignRecoverInitNeeded(TSBSignRecoverInitNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnSignRecoverInitNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnSignRecoverInitNeeded(TSBSignRecoverInitNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnSignRecoverInitNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnSignRecoverNeeded(TSBSignRecoverNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnSignRecoverNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnSignRecoverNeeded(TSBSignRecoverNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnSignRecoverNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnVerifyInitNeeded(TSBVerifyInitNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnVerifyInitNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnVerifyInitNeeded(TSBVerifyInitNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnVerifyInitNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnVerifyNeeded(TSBVerifyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnVerifyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnVerifyNeeded(TSBVerifyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnVerifyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnVerifyUpdateNeeded(TSBVerifyUpdateNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnVerifyUpdateNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnVerifyUpdateNeeded(TSBVerifyUpdateNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnVerifyUpdateNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnVerifyFinalNeeded(TSBVerifyFinalNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnVerifyFinalNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnVerifyFinalNeeded(TSBVerifyFinalNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnVerifyFinalNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnVerifyRecoverInitNeeded(TSBVerifyRecoverInitNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnVerifyRecoverInitNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnVerifyRecoverInitNeeded(TSBVerifyRecoverInitNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnVerifyRecoverInitNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnVerifyRecoverNeeded(TSBVerifyRecoverNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnVerifyRecoverNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnVerifyRecoverNeeded(TSBVerifyRecoverNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnVerifyRecoverNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnDigestEncryptUpdateNeeded(TSBDigestEncryptUpdateNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnDigestEncryptUpdateNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnDigestEncryptUpdateNeeded(TSBDigestEncryptUpdateNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnDigestEncryptUpdateNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnDecryptDigestUpdateNeeded(TSBDecryptDigestUpdateNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnDecryptDigestUpdateNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnDecryptDigestUpdateNeeded(TSBDecryptDigestUpdateNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnDecryptDigestUpdateNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnSignEncryptUpdateNeeded(TSBSignEncryptUpdateNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnSignEncryptUpdateNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnSignEncryptUpdateNeeded(TSBSignEncryptUpdateNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnSignEncryptUpdateNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnDecryptVerifyUpdateNeeded(TSBDecryptVerifyUpdateNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnDecryptVerifyUpdateNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnDecryptVerifyUpdateNeeded(TSBDecryptVerifyUpdateNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnDecryptVerifyUpdateNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnGenerateKeyNeeded(TSBGenerateKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnGenerateKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnGenerateKeyNeeded(TSBGenerateKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnGenerateKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnGenerateKeyPairNeeded(TSBGenerateKeyPairNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnGenerateKeyPairNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnGenerateKeyPairNeeded(TSBGenerateKeyPairNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnGenerateKeyPairNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnWrapKeyNeeded(TSBWrapKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnWrapKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnWrapKeyNeeded(TSBWrapKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnWrapKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnUnwrapKeyNeeded(TSBUnwrapKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnUnwrapKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnUnwrapKeyNeeded(TSBUnwrapKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnUnwrapKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnDeriveKeyNeeded(TSBDeriveKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnDeriveKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnDeriveKeyNeeded(TSBDeriveKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnDeriveKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnSeedRandomNeeded(TSBSeedRandomNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnSeedRandomNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnSeedRandomNeeded(TSBSeedRandomNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnSeedRandomNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnGenerateRandomNeeded(TSBGenerateRandomNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnGenerateRandomNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnGenerateRandomNeeded(TSBGenerateRandomNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnGenerateRandomNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnGetFunctionStatusNeeded(TSBGetFunctionStatusNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnGetFunctionStatusNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnGetFunctionStatusNeeded(TSBGetFunctionStatusNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnGetFunctionStatusNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPKCS11FunctionsManager::get_OnCancelFunctionNeeded(TSBCancelFunctionNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11FunctionsManager_get_OnCancelFunctionNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11FunctionsManager::set_OnCancelFunctionNeeded(TSBCancelFunctionNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11FunctionsManager_set_OnCancelFunctionNeeded(_Handle, pMethodValue, pDataValue));
}

TElPKCS11FunctionsManager::TElPKCS11FunctionsManager(TElPKCS11FunctionsManagerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPKCS11FunctionsManager::TElPKCS11FunctionsManager() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11FunctionsManager_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER

void TElPKCS11Consumer::get_UniqueID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11Consumer_get_UniqueID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1535540855, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElPKCS11Consumer::TElPKCS11Consumer(TElPKCS11ConsumerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPKCS11Consumer::TElPKCS11Consumer() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11Consumer_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */
#endif

#ifdef SB_USE_CLASS_TELPKCS11ATTRIBUTELIST

SB_INLINE void TElPKCS11AttributeList::Assign(TElPKCS11AttributeList &Source)
{
	SBCheckError(TElPKCS11AttributeList_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPKCS11AttributeList::Assign(TElPKCS11AttributeList *Source)
{
	SBCheckError(TElPKCS11AttributeList_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElPKCS11AttributeList::Add()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11AttributeList_Add(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE int32_t TElPKCS11AttributeList::Add(uint32_t Attribute, const std::vector<uint8_t> &Value)
#else
SB_INLINE int32_t TElPKCS11AttributeList::Add(int64_t Attribute, const std::vector<uint8_t> &Value)
#endif
{
	int32_t OutResult;
	SBCheckError(TElPKCS11AttributeList_Add_1(_Handle, Attribute, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE int32_t TElPKCS11AttributeList::Add(uint32_t Attribute, uint32_t Value)
#else
SB_INLINE int32_t TElPKCS11AttributeList::Add(int64_t Attribute, int64_t Value)
#endif
{
	int32_t OutResult;
	SBCheckError(TElPKCS11AttributeList_Add_2(_Handle, Attribute, Value, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE int32_t TElPKCS11AttributeList::Add(uint32_t Attribute, bool Value)
#else
SB_INLINE int32_t TElPKCS11AttributeList::Add(int64_t Attribute, bool Value)
#endif
{
	int32_t OutResult;
	SBCheckError(TElPKCS11AttributeList_Add_3(_Handle, Attribute, (int8_t)Value, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE int32_t TElPKCS11AttributeList::AddByte(uint32_t Attribute, uint8_t Value)
#else
SB_INLINE int32_t TElPKCS11AttributeList::AddByte(int64_t Attribute, uint8_t Value)
#endif
{
	int32_t OutResult;
	SBCheckError(TElPKCS11AttributeList_AddByte(_Handle, Attribute, Value, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE int32_t TElPKCS11AttributeList::AddWord(uint32_t Attribute, uint16_t Value)
#else
SB_INLINE int32_t TElPKCS11AttributeList::AddWord(int64_t Attribute, uint16_t Value)
#endif
{
	int32_t OutResult;
	SBCheckError(TElPKCS11AttributeList_AddWord(_Handle, Attribute, Value, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE int32_t TElPKCS11AttributeList::AddThreeByteInteger(uint32_t Attribute, uint32_t Value)
#else
SB_INLINE int32_t TElPKCS11AttributeList::AddThreeByteInteger(int64_t Attribute, int64_t Value)
#endif
{
	int32_t OutResult;
	SBCheckError(TElPKCS11AttributeList_AddThreeByteInteger(_Handle, Attribute, Value, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE int32_t TElPKCS11AttributeList::AddIntegerOptEnc(uint32_t Attribute, uint32_t Value)
#else
SB_INLINE int32_t TElPKCS11AttributeList::AddIntegerOptEnc(int64_t Attribute, int64_t Value)
#endif
{
	int32_t OutResult;
	SBCheckError(TElPKCS11AttributeList_AddIntegerOptEnc(_Handle, Attribute, Value, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS11AttributeList::Insert(int32_t Index)
{
	SBCheckError(TElPKCS11AttributeList_Insert(_Handle, Index));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11AttributeList::Insert(int32_t Index, uint32_t Attribute, const std::vector<uint8_t> &Value)
#else
SB_INLINE void TElPKCS11AttributeList::Insert(int32_t Index, int64_t Attribute, const std::vector<uint8_t> &Value)
#endif
{
	SBCheckError(TElPKCS11AttributeList_Insert_1(_Handle, Index, Attribute, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11AttributeList::Insert(int32_t Index, uint32_t Attribute, uint32_t Value)
#else
SB_INLINE void TElPKCS11AttributeList::Insert(int32_t Index, int64_t Attribute, int64_t Value)
#endif
{
	SBCheckError(TElPKCS11AttributeList_Insert_2(_Handle, Index, Attribute, Value));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11AttributeList::Insert(int32_t Index, uint32_t Attribute, bool Value)
#else
SB_INLINE void TElPKCS11AttributeList::Insert(int32_t Index, int64_t Attribute, bool Value)
#endif
{
	SBCheckError(TElPKCS11AttributeList_Insert_3(_Handle, Index, Attribute, (int8_t)Value));
}

SB_INLINE void TElPKCS11AttributeList::Remove(int32_t Index)
{
	SBCheckError(TElPKCS11AttributeList_Remove(_Handle, Index));
}

SB_INLINE void TElPKCS11AttributeList::Clear()
{
	SBCheckError(TElPKCS11AttributeList_Clear(_Handle));
}

SB_INLINE void TElPKCS11AttributeList::Serialize(void * Buffer, int32_t &Size)
{
	SBCheckError(TElPKCS11AttributeList_Serialize(_Handle, Buffer, &Size));
}

void TElPKCS11AttributeList::ToString(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11AttributeList_ToString(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(190975859, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE uint32_t TElPKCS11AttributeList::get_Attributes(int32_t Index)
#else
SB_INLINE int64_t TElPKCS11AttributeList::get_Attributes(int32_t Index)
#endif
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11AttributeList_get_Attributes(_Handle, Index, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11AttributeList::set_Attributes(int32_t Index, uint32_t Value)
#else
SB_INLINE void TElPKCS11AttributeList::set_Attributes(int32_t Index, int64_t Value)
#endif
{
	SBCheckError(TElPKCS11AttributeList_set_Attributes(_Handle, Index, Value));
}

void TElPKCS11AttributeList::get_Values(int32_t Index, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11AttributeList_get_Values(_Handle, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(604640332, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11AttributeList::set_Values(int32_t Index, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11AttributeList_set_Values(_Handle, Index, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElPKCS11AttributeList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11AttributeList_get_Count(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS11AttributeList::set_Count(int32_t Value)
{
	SBCheckError(TElPKCS11AttributeList_set_Count(_Handle, Value));
}

TElPKCS11AttributeList::TElPKCS11AttributeList(TElPKCS11AttributeListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPKCS11AttributeList::TElPKCS11AttributeList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11AttributeList_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPKCS11ATTRIBUTELIST */

#ifdef SB_USE_CLASS_TELPKCS11OBJECT

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Object::SetAttribute(uint32_t Attribute, const std::vector<uint8_t> &Value)
#else
SB_INLINE void TElPKCS11Object::SetAttribute(int64_t Attribute, const std::vector<uint8_t> &Value)
#endif
{
	SBCheckError(TElPKCS11Object_SetAttribute(_Handle, Attribute, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Object::SetAttribute(uint32_t Attribute, uint32_t Value)
#else
SB_INLINE void TElPKCS11Object::SetAttribute(int64_t Attribute, int64_t Value)
#endif
{
	SBCheckError(TElPKCS11Object_SetAttribute_1(_Handle, Attribute, Value));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Object::SetAttribute(uint32_t Attribute, bool Value)
#else
SB_INLINE void TElPKCS11Object::SetAttribute(int64_t Attribute, bool Value)
#endif
{
	SBCheckError(TElPKCS11Object_SetAttribute_2(_Handle, Attribute, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELPKCS11ATTRIBUTELIST
SB_INLINE void TElPKCS11Object::SetAttributes(TElPKCS11AttributeList &Attributes)
{
	SBCheckError(TElPKCS11Object_SetAttributes(_Handle, Attributes.getHandle()));
}

SB_INLINE void TElPKCS11Object::SetAttributes(TElPKCS11AttributeList *Attributes)
{
	SBCheckError(TElPKCS11Object_SetAttributes(_Handle, (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPKCS11ATTRIBUTELIST */

#ifdef SB_NOT_CPU64_OR_WINDOWS
void TElPKCS11Object::GetAttribute(uint32_t Attribute, std::vector<uint8_t> &OutResult)
#else
void TElPKCS11Object::GetAttribute(int64_t Attribute, std::vector<uint8_t> &OutResult)
#endif
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11Object_GetAttribute(_Handle, Attribute, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
		SBCheckError(SBGetLastReturnBuffer(-1049776617, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
#else
		SBCheckError(SBGetLastReturnBuffer(1782940032, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
#endif
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11Object::ReadProperties()
{
	SBCheckError(TElPKCS11Object_ReadProperties(_Handle));
}

SB_INLINE TClassHandle TElPKCS11Object::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPKCS11Object_ClassType(&OutResult));
	return OutResult;
}

TSBPKCS11ObjectType TElPKCS11Object::get_ObjectType()
{
	TSBPKCS11ObjectTypeRaw OutResultRaw = 0;
	SBCheckError(TElPKCS11Object_get_ObjectType(_Handle, &OutResultRaw));
	return (TSBPKCS11ObjectType)OutResultRaw;
}

bool TElPKCS11Object::get_Token()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11Object_get_Token(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11Object::get_Private()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11Object_get_Private(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11Object::get_Modifiable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11Object_get_Modifiable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElPKCS11Object::get_ObjectLabel(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11Object_get_ObjectLabel(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1536966772, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11Object::set_ObjectLabel(const std::string &Value)
{
	SBCheckError(TElPKCS11Object_set_ObjectLabel(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElPKCS11Object::get_ObjectSize()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11Object_get_ObjectSize(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE uint32_t TElPKCS11Object::get_Handle()
#else
SB_INLINE int64_t TElPKCS11Object::get_Handle()
#endif
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11Object_get_Handle(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
TElPKCS11SessionInfo* TElPKCS11Object::get_Session()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11Object_get_Session(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Session)
		this->_Inst_Session = new TElPKCS11SessionInfo(hOutResult, ohFalse);
	else
		this->_Inst_Session->updateHandle(hOutResult);
	return this->_Inst_Session;
}
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProvider* TElPKCS11Object::get_CryptoProvider()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11Object_get_CryptoProvider(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProvider)
		this->_Inst_CryptoProvider = new TElCustomCryptoProvider(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProvider->updateHandle(hOutResult);
	return this->_Inst_CryptoProvider;
}

SB_INLINE void TElPKCS11Object::set_CryptoProvider(TElCustomCryptoProvider &Value)
{
	SBCheckError(TElPKCS11Object_set_CryptoProvider(_Handle, Value.getHandle()));
}

SB_INLINE void TElPKCS11Object::set_CryptoProvider(TElCustomCryptoProvider *Value)
{
	SBCheckError(TElPKCS11Object_set_CryptoProvider(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

void TElPKCS11Object::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
	this->_Inst_Session = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
}

TElPKCS11Object::TElPKCS11Object(TElPKCS11ObjectHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS11Object::TElPKCS11Object() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS11Object_Create(&_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO
#ifdef SB_NOT_CPU64_OR_WINDOWS
TElPKCS11Object::TElPKCS11Object(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElPKCS11Object::TElPKCS11Object(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
	initInstances();
	SBCheckError(TElPKCS11Object_Create_1(Module.getHandle(), Session.getHandle(), Slot.getHandle(), Handle, (int8_t)CompatibleMode, CryptoProvider.getHandle(), &_Handle));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
TElPKCS11Object::TElPKCS11Object(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElPKCS11Object::TElPKCS11Object(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
	initInstances();
	SBCheckError(TElPKCS11Object_Create_1((Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, (Session != NULL) ? Session->getHandle() : SB_NULL_HANDLE, (Slot != NULL) ? Slot->getHandle() : SB_NULL_HANDLE, Handle, (int8_t)CompatibleMode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO */

TElPKCS11Object::~TElPKCS11Object()
{
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
	delete this->_Inst_Session;
	this->_Inst_Session = NULL;
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	delete this->_Inst_CryptoProvider;
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
}
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

#ifdef SB_USE_CLASS_TELPKCS11DATAOBJECT

SB_INLINE void TElPKCS11DataObject::ReadProperties()
{
	SBCheckError(TElPKCS11DataObject_ReadProperties(_Handle));
}

SB_INLINE TClassHandle TElPKCS11DataObject::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPKCS11DataObject_ClassType(&OutResult));
	return OutResult;
}

void TElPKCS11DataObject::get_Application(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11DataObject_get_Application(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(144365982, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11DataObject::set_Application(const std::string &Value)
{
	SBCheckError(TElPKCS11DataObject_set_Application(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPKCS11DataObject::get_ObjectID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11DataObject_get_ObjectID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1886009463, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11DataObject::set_ObjectID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11DataObject_set_ObjectID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS11DataObject::get_Value(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11DataObject_get_Value(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(744443147, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11DataObject::set_Value(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11DataObject_set_Value(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElPKCS11DataObject::TElPKCS11DataObject(TElPKCS11DataObjectHandle handle, TElOwnHandle ownHandle) : TElPKCS11Object(handle, ownHandle)
{
}

TElPKCS11DataObject::TElPKCS11DataObject() : TElPKCS11Object(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11DataObject_Create(&_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO
#ifdef SB_NOT_CPU64_OR_WINDOWS
TElPKCS11DataObject::TElPKCS11DataObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider) : TElPKCS11Object(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElPKCS11DataObject::TElPKCS11DataObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider) : TElPKCS11Object(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
	SBCheckError(TElPKCS11DataObject_Create_1(Module.getHandle(), Session.getHandle(), Slot.getHandle(), Handle, (int8_t)CompatibleMode, CryptoProvider.getHandle(), &_Handle));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
TElPKCS11DataObject::TElPKCS11DataObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider) : TElPKCS11Object(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElPKCS11DataObject::TElPKCS11DataObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider) : TElPKCS11Object(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
	SBCheckError(TElPKCS11DataObject_Create_1((Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, (Session != NULL) ? Session->getHandle() : SB_NULL_HANDLE, (Slot != NULL) ? Slot->getHandle() : SB_NULL_HANDLE, Handle, (int8_t)CompatibleMode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO */

#endif /* SB_USE_CLASS_TELPKCS11DATAOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11CERTIFICATEOBJECT

SB_INLINE void TElPKCS11CertificateObject::ReadProperties()
{
	SBCheckError(TElPKCS11CertificateObject_ReadProperties(_Handle));
}

SB_INLINE TClassHandle TElPKCS11CertificateObject::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPKCS11CertificateObject_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11CertificateObject::get_CertType()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11CertificateObject_get_CertType(_Handle, &OutResult));
	return OutResult;
}

bool TElPKCS11CertificateObject::get_Trusted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11CertificateObject_get_Trusted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11CertificateObject::set_Trusted(bool Value)
{
	SBCheckError(TElPKCS11CertificateObject_set_Trusted(_Handle, (int8_t)Value));
}

TSBPKCS11CertCategory TElPKCS11CertificateObject::get_CertCategory()
{
	TSBPKCS11CertCategoryRaw OutResultRaw = 0;
	SBCheckError(TElPKCS11CertificateObject_get_CertCategory(_Handle, &OutResultRaw));
	return (TSBPKCS11CertCategory)OutResultRaw;
}

void TElPKCS11CertificateObject::get_Checksum(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11CertificateObject_get_Checksum(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1615621763, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElPKCS11CertificateObject::get_StartDate()
{
	int64_t OutResult;
	SBCheckError(TElPKCS11CertificateObject_get_StartDate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS11CertificateObject::set_StartDate(int64_t Value)
{
	SBCheckError(TElPKCS11CertificateObject_set_StartDate(_Handle, Value));
}

SB_INLINE int64_t TElPKCS11CertificateObject::get_EndDate()
{
	int64_t OutResult;
	SBCheckError(TElPKCS11CertificateObject_get_EndDate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS11CertificateObject::set_EndDate(int64_t Value)
{
	SBCheckError(TElPKCS11CertificateObject_set_EndDate(_Handle, Value));
}

TElPKCS11CertificateObject::TElPKCS11CertificateObject(TElPKCS11CertificateObjectHandle handle, TElOwnHandle ownHandle) : TElPKCS11Object(handle, ownHandle)
{
}

TElPKCS11CertificateObject::TElPKCS11CertificateObject() : TElPKCS11Object(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11CertificateObject_Create(&_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO
#ifdef SB_NOT_CPU64_OR_WINDOWS
TElPKCS11CertificateObject::TElPKCS11CertificateObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider) : TElPKCS11Object(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElPKCS11CertificateObject::TElPKCS11CertificateObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider) : TElPKCS11Object(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
	SBCheckError(TElPKCS11CertificateObject_Create_1(Module.getHandle(), Session.getHandle(), Slot.getHandle(), Handle, (int8_t)CompatibleMode, CryptoProvider.getHandle(), &_Handle));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
TElPKCS11CertificateObject::TElPKCS11CertificateObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider) : TElPKCS11Object(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElPKCS11CertificateObject::TElPKCS11CertificateObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider) : TElPKCS11Object(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
	SBCheckError(TElPKCS11CertificateObject_Create_1((Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, (Session != NULL) ? Session->getHandle() : SB_NULL_HANDLE, (Slot != NULL) ? Slot->getHandle() : SB_NULL_HANDLE, Handle, (int8_t)CompatibleMode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO */

#endif /* SB_USE_CLASS_TELPKCS11CERTIFICATEOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11X509CERTIFICATEOBJECT

SB_INLINE void TElPKCS11X509CertificateObject::ReadProperties()
{
	SBCheckError(TElPKCS11X509CertificateObject_ReadProperties(_Handle));
}

SB_INLINE TClassHandle TElPKCS11X509CertificateObject::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPKCS11X509CertificateObject_ClassType(&OutResult));
	return OutResult;
}

void TElPKCS11X509CertificateObject::get_Subject(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11X509CertificateObject_get_Subject(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2141566026, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11X509CertificateObject::get_KeyID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11X509CertificateObject_get_KeyID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2067897527, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11X509CertificateObject::set_KeyID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11X509CertificateObject_set_KeyID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS11X509CertificateObject::get_Issuer(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11X509CertificateObject_get_Issuer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2024907271, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11X509CertificateObject::set_Issuer(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11X509CertificateObject_set_Issuer(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS11X509CertificateObject::get_SerialNumber(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11X509CertificateObject_get_SerialNumber(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-73342394, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11X509CertificateObject::set_SerialNumber(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11X509CertificateObject_set_SerialNumber(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS11X509CertificateObject::get_Value(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11X509CertificateObject_get_Value(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1227116777, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11X509CertificateObject::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11X509CertificateObject_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1753620660, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11X509CertificateObject::get_SubjectPublicKeyHash(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11X509CertificateObject_get_SubjectPublicKeyHash(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1485716929, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11X509CertificateObject::get_IssuerPublicKeyHash(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11X509CertificateObject_get_IssuerPublicKeyHash(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-576348813, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBPKCS11MIDPSecurityDomain TElPKCS11X509CertificateObject::get_MIDPSecurityDomain()
{
	TSBPKCS11MIDPSecurityDomainRaw OutResultRaw = 0;
	SBCheckError(TElPKCS11X509CertificateObject_get_MIDPSecurityDomain(_Handle, &OutResultRaw));
	return (TSBPKCS11MIDPSecurityDomain)OutResultRaw;
}

TElPKCS11X509CertificateObject::TElPKCS11X509CertificateObject(TElPKCS11X509CertificateObjectHandle handle, TElOwnHandle ownHandle) : TElPKCS11CertificateObject(handle, ownHandle)
{
}

TElPKCS11X509CertificateObject::TElPKCS11X509CertificateObject() : TElPKCS11CertificateObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11X509CertificateObject_Create(&_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO
#ifdef SB_NOT_CPU64_OR_WINDOWS
TElPKCS11X509CertificateObject::TElPKCS11X509CertificateObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider) : TElPKCS11CertificateObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElPKCS11X509CertificateObject::TElPKCS11X509CertificateObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider) : TElPKCS11CertificateObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
	SBCheckError(TElPKCS11X509CertificateObject_Create_1(Module.getHandle(), Session.getHandle(), Slot.getHandle(), Handle, (int8_t)CompatibleMode, CryptoProvider.getHandle(), &_Handle));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
TElPKCS11X509CertificateObject::TElPKCS11X509CertificateObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider) : TElPKCS11CertificateObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElPKCS11X509CertificateObject::TElPKCS11X509CertificateObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider) : TElPKCS11CertificateObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
	SBCheckError(TElPKCS11X509CertificateObject_Create_1((Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, (Session != NULL) ? Session->getHandle() : SB_NULL_HANDLE, (Slot != NULL) ? Slot->getHandle() : SB_NULL_HANDLE, Handle, (int8_t)CompatibleMode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO */

#endif /* SB_USE_CLASS_TELPKCS11X509CERTIFICATEOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11WTLSCERTIFICATEOBJECT

SB_INLINE void TElPKCS11WTLSCertificateObject::ReadProperties()
{
	SBCheckError(TElPKCS11WTLSCertificateObject_ReadProperties(_Handle));
}

SB_INLINE TClassHandle TElPKCS11WTLSCertificateObject::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPKCS11WTLSCertificateObject_ClassType(&OutResult));
	return OutResult;
}

void TElPKCS11WTLSCertificateObject::get_Subject(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11WTLSCertificateObject_get_Subject(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1047838391, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11WTLSCertificateObject::get_Issuer(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11WTLSCertificateObject_get_Issuer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1379844690, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11WTLSCertificateObject::set_Issuer(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11WTLSCertificateObject_set_Issuer(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS11WTLSCertificateObject::get_Value(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11WTLSCertificateObject_get_Value(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1509564363, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11WTLSCertificateObject::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11WTLSCertificateObject_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2032619726, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11WTLSCertificateObject::get_SubjectPublicKeyHash(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11WTLSCertificateObject_get_SubjectPublicKeyHash(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(821953251, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11WTLSCertificateObject::get_IssuerPublicKeyHash(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11WTLSCertificateObject_get_IssuerPublicKeyHash(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1881753505, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElPKCS11WTLSCertificateObject::TElPKCS11WTLSCertificateObject(TElPKCS11WTLSCertificateObjectHandle handle, TElOwnHandle ownHandle) : TElPKCS11CertificateObject(handle, ownHandle)
{
}

TElPKCS11WTLSCertificateObject::TElPKCS11WTLSCertificateObject() : TElPKCS11CertificateObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11WTLSCertificateObject_Create(&_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO
#ifdef SB_NOT_CPU64_OR_WINDOWS
TElPKCS11WTLSCertificateObject::TElPKCS11WTLSCertificateObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider) : TElPKCS11CertificateObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElPKCS11WTLSCertificateObject::TElPKCS11WTLSCertificateObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider) : TElPKCS11CertificateObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
	SBCheckError(TElPKCS11WTLSCertificateObject_Create_1(Module.getHandle(), Session.getHandle(), Slot.getHandle(), Handle, (int8_t)CompatibleMode, CryptoProvider.getHandle(), &_Handle));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
TElPKCS11WTLSCertificateObject::TElPKCS11WTLSCertificateObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider) : TElPKCS11CertificateObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElPKCS11WTLSCertificateObject::TElPKCS11WTLSCertificateObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider) : TElPKCS11CertificateObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
	SBCheckError(TElPKCS11WTLSCertificateObject_Create_1((Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, (Session != NULL) ? Session->getHandle() : SB_NULL_HANDLE, (Slot != NULL) ? Slot->getHandle() : SB_NULL_HANDLE, Handle, (int8_t)CompatibleMode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO */

#endif /* SB_USE_CLASS_TELPKCS11WTLSCERTIFICATEOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11X509ATTRIBUTECERTIFICATEOBJECT

SB_INLINE void TElPKCS11X509AttributeCertificateObject::ReadProperties()
{
	SBCheckError(TElPKCS11X509AttributeCertificateObject_ReadProperties(_Handle));
}

SB_INLINE TClassHandle TElPKCS11X509AttributeCertificateObject::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPKCS11X509AttributeCertificateObject_ClassType(&OutResult));
	return OutResult;
}

void TElPKCS11X509AttributeCertificateObject::get_Owner(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11X509AttributeCertificateObject_get_Owner(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1636051041, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11X509AttributeCertificateObject::get_ACIssuer(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11X509AttributeCertificateObject_get_ACIssuer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(256475852, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11X509AttributeCertificateObject::set_ACIssuer(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11X509AttributeCertificateObject_set_ACIssuer(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS11X509AttributeCertificateObject::get_SerialNumber(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11X509AttributeCertificateObject_get_SerialNumber(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2144635286, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11X509AttributeCertificateObject::set_SerialNumber(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11X509AttributeCertificateObject_set_SerialNumber(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS11X509AttributeCertificateObject::get_AttrTypes(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11X509AttributeCertificateObject_get_AttrTypes(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-261618835, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11X509AttributeCertificateObject::set_AttrTypes(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11X509AttributeCertificateObject_set_AttrTypes(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS11X509AttributeCertificateObject::get_Value(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11X509AttributeCertificateObject_get_Value(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1282173399, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElPKCS11X509AttributeCertificateObject::TElPKCS11X509AttributeCertificateObject(TElPKCS11X509AttributeCertificateObjectHandle handle, TElOwnHandle ownHandle) : TElPKCS11CertificateObject(handle, ownHandle)
{
}

TElPKCS11X509AttributeCertificateObject::TElPKCS11X509AttributeCertificateObject() : TElPKCS11CertificateObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11X509AttributeCertificateObject_Create(&_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO
#ifdef SB_NOT_CPU64_OR_WINDOWS
TElPKCS11X509AttributeCertificateObject::TElPKCS11X509AttributeCertificateObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider) : TElPKCS11CertificateObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElPKCS11X509AttributeCertificateObject::TElPKCS11X509AttributeCertificateObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider) : TElPKCS11CertificateObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
	SBCheckError(TElPKCS11X509AttributeCertificateObject_Create_1(Module.getHandle(), Session.getHandle(), Slot.getHandle(), Handle, (int8_t)CompatibleMode, CryptoProvider.getHandle(), &_Handle));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
TElPKCS11X509AttributeCertificateObject::TElPKCS11X509AttributeCertificateObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider) : TElPKCS11CertificateObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElPKCS11X509AttributeCertificateObject::TElPKCS11X509AttributeCertificateObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider) : TElPKCS11CertificateObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
	SBCheckError(TElPKCS11X509AttributeCertificateObject_Create_1((Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, (Session != NULL) ? Session->getHandle() : SB_NULL_HANDLE, (Slot != NULL) ? Slot->getHandle() : SB_NULL_HANDLE, Handle, (int8_t)CompatibleMode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO */

#endif /* SB_USE_CLASS_TELPKCS11X509ATTRIBUTECERTIFICATEOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11KEYOBJECT

SB_INLINE void TElPKCS11KeyObject::ReadProperties()
{
	SBCheckError(TElPKCS11KeyObject_ReadProperties(_Handle));
}

SB_INLINE TClassHandle TElPKCS11KeyObject::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPKCS11KeyObject_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11KeyObject::get_KeyType()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11KeyObject_get_KeyType(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE uint32_t TElPKCS11KeyObject::get_PKCS11KeyType()
#else
SB_INLINE int64_t TElPKCS11KeyObject::get_PKCS11KeyType()
#endif
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11KeyObject_get_PKCS11KeyType(_Handle, &OutResult));
	return OutResult;
}

void TElPKCS11KeyObject::get_KeyID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11KeyObject_get_KeyID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(234069721, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11KeyObject::set_KeyID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11KeyObject_set_KeyID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int64_t TElPKCS11KeyObject::get_StartDate()
{
	int64_t OutResult;
	SBCheckError(TElPKCS11KeyObject_get_StartDate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS11KeyObject::set_StartDate(int64_t Value)
{
	SBCheckError(TElPKCS11KeyObject_set_StartDate(_Handle, Value));
}

SB_INLINE int64_t TElPKCS11KeyObject::get_EndDate()
{
	int64_t OutResult;
	SBCheckError(TElPKCS11KeyObject_get_EndDate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS11KeyObject::set_EndDate(int64_t Value)
{
	SBCheckError(TElPKCS11KeyObject_set_EndDate(_Handle, Value));
}

bool TElPKCS11KeyObject::get_Derive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11KeyObject_get_Derive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11KeyObject::set_Derive(bool Value)
{
	SBCheckError(TElPKCS11KeyObject_set_Derive(_Handle, (int8_t)Value));
}

bool TElPKCS11KeyObject::get_Local()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11KeyObject_get_Local(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELKEYMATERIAL
TElKeyMaterial* TElPKCS11KeyObject::get_KeyMaterial()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11KeyObject_get_KeyMaterial(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyMaterial)
		this->_Inst_KeyMaterial = new TElKeyMaterial(hOutResult, ohFalse);
	else
		this->_Inst_KeyMaterial->updateHandle(hOutResult);
	return this->_Inst_KeyMaterial;
}
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

void TElPKCS11KeyObject::initInstances()
{
#ifdef SB_USE_CLASS_TELKEYMATERIAL
	this->_Inst_KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELKEYMATERIAL */
}

TElPKCS11KeyObject::TElPKCS11KeyObject(TElPKCS11KeyObjectHandle handle, TElOwnHandle ownHandle) : TElPKCS11Object(handle, ownHandle)
{
	initInstances();
}

TElPKCS11KeyObject::TElPKCS11KeyObject() : TElPKCS11Object(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS11KeyObject_Create(&_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO
#ifdef SB_NOT_CPU64_OR_WINDOWS
TElPKCS11KeyObject::TElPKCS11KeyObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider) : TElPKCS11Object(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElPKCS11KeyObject::TElPKCS11KeyObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider) : TElPKCS11Object(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
	initInstances();
	SBCheckError(TElPKCS11KeyObject_Create_1(Module.getHandle(), Session.getHandle(), Slot.getHandle(), Handle, (int8_t)CompatibleMode, CryptoProvider.getHandle(), &_Handle));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
TElPKCS11KeyObject::TElPKCS11KeyObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider) : TElPKCS11Object(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElPKCS11KeyObject::TElPKCS11KeyObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider) : TElPKCS11Object(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
	initInstances();
	SBCheckError(TElPKCS11KeyObject_Create_1((Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, (Session != NULL) ? Session->getHandle() : SB_NULL_HANDLE, (Slot != NULL) ? Slot->getHandle() : SB_NULL_HANDLE, Handle, (int8_t)CompatibleMode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO */

TElPKCS11KeyObject::~TElPKCS11KeyObject()
{
#ifdef SB_USE_CLASS_TELKEYMATERIAL
	delete this->_Inst_KeyMaterial;
	this->_Inst_KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELKEYMATERIAL */
}
#endif /* SB_USE_CLASS_TELPKCS11KEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11PUBLICKEYOBJECT

SB_INLINE void TElPKCS11PublicKeyObject::ReadProperties()
{
	SBCheckError(TElPKCS11PublicKeyObject_ReadProperties(_Handle));
}

SB_INLINE TClassHandle TElPKCS11PublicKeyObject::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPKCS11PublicKeyObject_ClassType(&OutResult));
	return OutResult;
}

void TElPKCS11PublicKeyObject::get_Subject(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11PublicKeyObject_get_Subject(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1297364955, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11PublicKeyObject::set_Subject(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11PublicKeyObject_set_Subject(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElPKCS11PublicKeyObject::get_CanEncrypt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11PublicKeyObject_get_CanEncrypt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11PublicKeyObject::set_CanEncrypt(bool Value)
{
	SBCheckError(TElPKCS11PublicKeyObject_set_CanEncrypt(_Handle, (int8_t)Value));
}

bool TElPKCS11PublicKeyObject::get_CanVerify()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11PublicKeyObject_get_CanVerify(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11PublicKeyObject::set_CanVerify(bool Value)
{
	SBCheckError(TElPKCS11PublicKeyObject_set_CanVerify(_Handle, (int8_t)Value));
}

bool TElPKCS11PublicKeyObject::get_CanVerifyDetached()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11PublicKeyObject_get_CanVerifyDetached(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11PublicKeyObject::set_CanVerifyDetached(bool Value)
{
	SBCheckError(TElPKCS11PublicKeyObject_set_CanVerifyDetached(_Handle, (int8_t)Value));
}

bool TElPKCS11PublicKeyObject::get_CanWrap()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11PublicKeyObject_get_CanWrap(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11PublicKeyObject::set_CanWrap(bool Value)
{
	SBCheckError(TElPKCS11PublicKeyObject_set_CanWrap(_Handle, (int8_t)Value));
}

bool TElPKCS11PublicKeyObject::get_Trusted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11PublicKeyObject_get_Trusted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11PublicKeyObject::set_Trusted(bool Value)
{
	SBCheckError(TElPKCS11PublicKeyObject_set_Trusted(_Handle, (int8_t)Value));
}

TElPKCS11PublicKeyObject::TElPKCS11PublicKeyObject(TElPKCS11PublicKeyObjectHandle handle, TElOwnHandle ownHandle) : TElPKCS11KeyObject(handle, ownHandle)
{
}

TElPKCS11PublicKeyObject::TElPKCS11PublicKeyObject() : TElPKCS11KeyObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11PublicKeyObject_Create(&_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO
#ifdef SB_NOT_CPU64_OR_WINDOWS
TElPKCS11PublicKeyObject::TElPKCS11PublicKeyObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider) : TElPKCS11KeyObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElPKCS11PublicKeyObject::TElPKCS11PublicKeyObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider) : TElPKCS11KeyObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
	SBCheckError(TElPKCS11PublicKeyObject_Create_1(Module.getHandle(), Session.getHandle(), Slot.getHandle(), Handle, (int8_t)CompatibleMode, CryptoProvider.getHandle(), &_Handle));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
TElPKCS11PublicKeyObject::TElPKCS11PublicKeyObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider) : TElPKCS11KeyObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElPKCS11PublicKeyObject::TElPKCS11PublicKeyObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider) : TElPKCS11KeyObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
	SBCheckError(TElPKCS11PublicKeyObject_Create_1((Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, (Session != NULL) ? Session->getHandle() : SB_NULL_HANDLE, (Slot != NULL) ? Slot->getHandle() : SB_NULL_HANDLE, Handle, (int8_t)CompatibleMode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO */

#endif /* SB_USE_CLASS_TELPKCS11PUBLICKEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11PRIVATEKEYOBJECT

SB_INLINE void TElPKCS11PrivateKeyObject::ReadProperties()
{
	SBCheckError(TElPKCS11PrivateKeyObject_ReadProperties(_Handle));
}

SB_INLINE TClassHandle TElPKCS11PrivateKeyObject::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPKCS11PrivateKeyObject_ClassType(&OutResult));
	return OutResult;
}

void TElPKCS11PrivateKeyObject::get_Subject(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11PrivateKeyObject_get_Subject(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1948856901, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11PrivateKeyObject::set_Subject(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11PrivateKeyObject_set_Subject(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElPKCS11PrivateKeyObject::get_Sensitive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11PrivateKeyObject_get_Sensitive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11PrivateKeyObject::set_Sensitive(bool Value)
{
	SBCheckError(TElPKCS11PrivateKeyObject_set_Sensitive(_Handle, (int8_t)Value));
}

bool TElPKCS11PrivateKeyObject::get_CanDecrypt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11PrivateKeyObject_get_CanDecrypt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11PrivateKeyObject::set_CanDecrypt(bool Value)
{
	SBCheckError(TElPKCS11PrivateKeyObject_set_CanDecrypt(_Handle, (int8_t)Value));
}

bool TElPKCS11PrivateKeyObject::get_CanSign()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11PrivateKeyObject_get_CanSign(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11PrivateKeyObject::set_CanSign(bool Value)
{
	SBCheckError(TElPKCS11PrivateKeyObject_set_CanSign(_Handle, (int8_t)Value));
}

bool TElPKCS11PrivateKeyObject::get_CanSignDetached()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11PrivateKeyObject_get_CanSignDetached(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11PrivateKeyObject::set_CanSignDetached(bool Value)
{
	SBCheckError(TElPKCS11PrivateKeyObject_set_CanSignDetached(_Handle, (int8_t)Value));
}

bool TElPKCS11PrivateKeyObject::get_CanUnwrap()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11PrivateKeyObject_get_CanUnwrap(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11PrivateKeyObject::set_CanUnwrap(bool Value)
{
	SBCheckError(TElPKCS11PrivateKeyObject_set_CanUnwrap(_Handle, (int8_t)Value));
}

bool TElPKCS11PrivateKeyObject::get_Extractable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11PrivateKeyObject_get_Extractable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11PrivateKeyObject::set_Extractable(bool Value)
{
	SBCheckError(TElPKCS11PrivateKeyObject_set_Extractable(_Handle, (int8_t)Value));
}

bool TElPKCS11PrivateKeyObject::get_AlwaysSensitive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11PrivateKeyObject_get_AlwaysSensitive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11PrivateKeyObject::get_NeverExtractable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11PrivateKeyObject_get_NeverExtractable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11PrivateKeyObject::get_WrapWithTrusted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11PrivateKeyObject_get_WrapWithTrusted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11PrivateKeyObject::set_WrapWithTrusted(bool Value)
{
	SBCheckError(TElPKCS11PrivateKeyObject_set_WrapWithTrusted(_Handle, (int8_t)Value));
}

bool TElPKCS11PrivateKeyObject::get_AlwaysAuthenticate()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11PrivateKeyObject_get_AlwaysAuthenticate(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11PrivateKeyObject::set_AlwaysAuthenticate(bool Value)
{
	SBCheckError(TElPKCS11PrivateKeyObject_set_AlwaysAuthenticate(_Handle, (int8_t)Value));
}

TElPKCS11PrivateKeyObject::TElPKCS11PrivateKeyObject(TElPKCS11PrivateKeyObjectHandle handle, TElOwnHandle ownHandle) : TElPKCS11KeyObject(handle, ownHandle)
{
}

TElPKCS11PrivateKeyObject::TElPKCS11PrivateKeyObject() : TElPKCS11KeyObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11PrivateKeyObject_Create(&_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO
#ifdef SB_NOT_CPU64_OR_WINDOWS
TElPKCS11PrivateKeyObject::TElPKCS11PrivateKeyObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider) : TElPKCS11KeyObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElPKCS11PrivateKeyObject::TElPKCS11PrivateKeyObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider) : TElPKCS11KeyObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
	SBCheckError(TElPKCS11PrivateKeyObject_Create_1(Module.getHandle(), Session.getHandle(), Slot.getHandle(), Handle, (int8_t)CompatibleMode, CryptoProvider.getHandle(), &_Handle));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
TElPKCS11PrivateKeyObject::TElPKCS11PrivateKeyObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider) : TElPKCS11KeyObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElPKCS11PrivateKeyObject::TElPKCS11PrivateKeyObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider) : TElPKCS11KeyObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
	SBCheckError(TElPKCS11PrivateKeyObject_Create_1((Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, (Session != NULL) ? Session->getHandle() : SB_NULL_HANDLE, (Slot != NULL) ? Slot->getHandle() : SB_NULL_HANDLE, Handle, (int8_t)CompatibleMode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO */

#endif /* SB_USE_CLASS_TELPKCS11PRIVATEKEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11SECRETKEYOBJECT

SB_INLINE void TElPKCS11SecretKeyObject::ReadProperties()
{
	SBCheckError(TElPKCS11SecretKeyObject_ReadProperties(_Handle));
}

SB_INLINE TClassHandle TElPKCS11SecretKeyObject::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPKCS11SecretKeyObject_ClassType(&OutResult));
	return OutResult;
}

bool TElPKCS11SecretKeyObject::get_Sensitive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SecretKeyObject_get_Sensitive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11SecretKeyObject::set_Sensitive(bool Value)
{
	SBCheckError(TElPKCS11SecretKeyObject_set_Sensitive(_Handle, (int8_t)Value));
}

bool TElPKCS11SecretKeyObject::get_CanEncrypt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SecretKeyObject_get_CanEncrypt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11SecretKeyObject::set_CanEncrypt(bool Value)
{
	SBCheckError(TElPKCS11SecretKeyObject_set_CanEncrypt(_Handle, (int8_t)Value));
}

bool TElPKCS11SecretKeyObject::get_CanDecrypt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SecretKeyObject_get_CanDecrypt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11SecretKeyObject::set_CanDecrypt(bool Value)
{
	SBCheckError(TElPKCS11SecretKeyObject_set_CanDecrypt(_Handle, (int8_t)Value));
}

bool TElPKCS11SecretKeyObject::get_CanSign()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SecretKeyObject_get_CanSign(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11SecretKeyObject::set_CanSign(bool Value)
{
	SBCheckError(TElPKCS11SecretKeyObject_set_CanSign(_Handle, (int8_t)Value));
}

bool TElPKCS11SecretKeyObject::get_CanVerify()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SecretKeyObject_get_CanVerify(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11SecretKeyObject::set_CanVerify(bool Value)
{
	SBCheckError(TElPKCS11SecretKeyObject_set_CanVerify(_Handle, (int8_t)Value));
}

bool TElPKCS11SecretKeyObject::get_CanWrap()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SecretKeyObject_get_CanWrap(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11SecretKeyObject::set_CanWrap(bool Value)
{
	SBCheckError(TElPKCS11SecretKeyObject_set_CanWrap(_Handle, (int8_t)Value));
}

bool TElPKCS11SecretKeyObject::get_CanUnwrap()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SecretKeyObject_get_CanUnwrap(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11SecretKeyObject::set_CanUnwrap(bool Value)
{
	SBCheckError(TElPKCS11SecretKeyObject_set_CanUnwrap(_Handle, (int8_t)Value));
}

bool TElPKCS11SecretKeyObject::get_Extractable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SecretKeyObject_get_Extractable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11SecretKeyObject::set_Extractable(bool Value)
{
	SBCheckError(TElPKCS11SecretKeyObject_set_Extractable(_Handle, (int8_t)Value));
}

bool TElPKCS11SecretKeyObject::get_AlwaysSensitive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SecretKeyObject_get_AlwaysSensitive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11SecretKeyObject::get_NeverExtractable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SecretKeyObject_get_NeverExtractable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElPKCS11SecretKeyObject::get_Checksum(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11SecretKeyObject_get_Checksum(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-977643527, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElPKCS11SecretKeyObject::get_WrapWithTrusted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SecretKeyObject_get_WrapWithTrusted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11SecretKeyObject::set_WrapWithTrusted(bool Value)
{
	SBCheckError(TElPKCS11SecretKeyObject_set_WrapWithTrusted(_Handle, (int8_t)Value));
}

bool TElPKCS11SecretKeyObject::get_Trusted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11SecretKeyObject_get_Trusted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11SecretKeyObject::set_Trusted(bool Value)
{
	SBCheckError(TElPKCS11SecretKeyObject_set_Trusted(_Handle, (int8_t)Value));
}

TElPKCS11SecretKeyObject::TElPKCS11SecretKeyObject(TElPKCS11SecretKeyObjectHandle handle, TElOwnHandle ownHandle) : TElPKCS11KeyObject(handle, ownHandle)
{
}

TElPKCS11SecretKeyObject::TElPKCS11SecretKeyObject() : TElPKCS11KeyObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11SecretKeyObject_Create(&_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO
#ifdef SB_NOT_CPU64_OR_WINDOWS
TElPKCS11SecretKeyObject::TElPKCS11SecretKeyObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider) : TElPKCS11KeyObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElPKCS11SecretKeyObject::TElPKCS11SecretKeyObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider) : TElPKCS11KeyObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
	SBCheckError(TElPKCS11SecretKeyObject_Create_1(Module.getHandle(), Session.getHandle(), Slot.getHandle(), Handle, (int8_t)CompatibleMode, CryptoProvider.getHandle(), &_Handle));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
TElPKCS11SecretKeyObject::TElPKCS11SecretKeyObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider) : TElPKCS11KeyObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElPKCS11SecretKeyObject::TElPKCS11SecretKeyObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider) : TElPKCS11KeyObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
	SBCheckError(TElPKCS11SecretKeyObject_Create_1((Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, (Session != NULL) ? Session->getHandle() : SB_NULL_HANDLE, (Slot != NULL) ? Slot->getHandle() : SB_NULL_HANDLE, Handle, (int8_t)CompatibleMode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO */

#endif /* SB_USE_CLASS_TELPKCS11SECRETKEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11DOMAINPARAMETERSOBJECT

SB_INLINE void TElPKCS11DomainParametersObject::ReadProperties()
{
	SBCheckError(TElPKCS11DomainParametersObject_ReadProperties(_Handle));
}

SB_INLINE TClassHandle TElPKCS11DomainParametersObject::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPKCS11DomainParametersObject_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11DomainParametersObject::get_KeyType()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11DomainParametersObject_get_KeyType(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE uint32_t TElPKCS11DomainParametersObject::get_PKCS11KeyType()
#else
SB_INLINE int64_t TElPKCS11DomainParametersObject::get_PKCS11KeyType()
#endif
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11DomainParametersObject_get_PKCS11KeyType(_Handle, &OutResult));
	return OutResult;
}

TElPKCS11DomainParametersObject::TElPKCS11DomainParametersObject(TElPKCS11DomainParametersObjectHandle handle, TElOwnHandle ownHandle) : TElPKCS11Object(handle, ownHandle)
{
}

TElPKCS11DomainParametersObject::TElPKCS11DomainParametersObject() : TElPKCS11Object(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11DomainParametersObject_Create(&_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO
#ifdef SB_NOT_CPU64_OR_WINDOWS
TElPKCS11DomainParametersObject::TElPKCS11DomainParametersObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider) : TElPKCS11Object(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElPKCS11DomainParametersObject::TElPKCS11DomainParametersObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider) : TElPKCS11Object(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
	SBCheckError(TElPKCS11DomainParametersObject_Create_1(Module.getHandle(), Session.getHandle(), Slot.getHandle(), Handle, (int8_t)CompatibleMode, CryptoProvider.getHandle(), &_Handle));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
TElPKCS11DomainParametersObject::TElPKCS11DomainParametersObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider) : TElPKCS11Object(SB_NULL_HANDLE, SB_OWN_HANDLE)
#else
TElPKCS11DomainParametersObject::TElPKCS11DomainParametersObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider) : TElPKCS11Object(SB_NULL_HANDLE, SB_OWN_HANDLE)
#endif
{
	SBCheckError(TElPKCS11DomainParametersObject_Create_1((Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, (Session != NULL) ? Session->getHandle() : SB_NULL_HANDLE, (Slot != NULL) ? Slot->getHandle() : SB_NULL_HANDLE, Handle, (int8_t)CompatibleMode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO */

#endif /* SB_USE_CLASS_TELPKCS11DOMAINPARAMETERSOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11UTILS

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
void TElPKCS11Utils::GetObjectAttribute(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, std::vector<uint8_t> &OutResult)
#else
void TElPKCS11Utils::GetObjectAttribute(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, std::vector<uint8_t> &OutResult)
#endif
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11Utils_GetObjectAttribute(Module.getHandle(), hSession, hObject, Attribute, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
		SBCheckError(SBGetLastReturnBuffer(1209326187, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
#else
		SBCheckError(SBGetLastReturnBuffer(1477817149, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
#endif
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
void TElPKCS11Utils::GetObjectAttribute(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, std::vector<uint8_t> &OutResult)
#else
void TElPKCS11Utils::GetObjectAttribute(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, std::vector<uint8_t> &OutResult)
#endif
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11Utils_GetObjectAttribute((Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, hSession, hObject, Attribute, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
		SBCheckError(SBGetLastReturnBuffer(1209326187, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
#else
		SBCheckError(SBGetLastReturnBuffer(1477817149, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
#endif
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
void TElPKCS11Utils::GetObjectAttribute_Inst(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, std::vector<uint8_t> &OutResult)
#else
void TElPKCS11Utils::GetObjectAttribute_Inst(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, std::vector<uint8_t> &OutResult)
#endif
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11Utils_GetObjectAttribute_1(_Handle, Module.getHandle(), hSession, hObject, Attribute, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
		SBCheckError(SBGetLastReturnBuffer(1209326187, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
#else
		SBCheckError(SBGetLastReturnBuffer(1477817149, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
#endif
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
void TElPKCS11Utils::GetObjectAttribute_Inst(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, std::vector<uint8_t> &OutResult)
#else
void TElPKCS11Utils::GetObjectAttribute_Inst(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, std::vector<uint8_t> &OutResult)
#endif
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11Utils_GetObjectAttribute_1(_Handle, (Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, hSession, hObject, Attribute, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
		SBCheckError(SBGetLastReturnBuffer(1209326187, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
#else
		SBCheckError(SBGetLastReturnBuffer(1477817149, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
#endif
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
void TElPKCS11Utils::GetBufferTypeAttribute(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Def, std::vector<uint8_t> &OutResult)
#else
void TElPKCS11Utils::GetBufferTypeAttribute(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Def, std::vector<uint8_t> &OutResult)
#endif
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11Utils_GetBufferTypeAttribute(Module.getHandle(), hSession, hObject, Attribute, SB_STD_VECTOR_FRONT_ADR(Def), (int32_t)Def.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
		SBCheckError(SBGetLastReturnBuffer(-1119466412, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
#else
		SBCheckError(SBGetLastReturnBuffer(1306852311, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
#endif
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
void TElPKCS11Utils::GetBufferTypeAttribute(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Def, std::vector<uint8_t> &OutResult)
#else
void TElPKCS11Utils::GetBufferTypeAttribute(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Def, std::vector<uint8_t> &OutResult)
#endif
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11Utils_GetBufferTypeAttribute((Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, hSession, hObject, Attribute, SB_STD_VECTOR_FRONT_ADR(Def), (int32_t)Def.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
		SBCheckError(SBGetLastReturnBuffer(-1119466412, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
#else
		SBCheckError(SBGetLastReturnBuffer(1306852311, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
#endif
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
void TElPKCS11Utils::GetBufferTypeAttribute_Inst(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Def, std::vector<uint8_t> &OutResult)
#else
void TElPKCS11Utils::GetBufferTypeAttribute_Inst(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Def, std::vector<uint8_t> &OutResult)
#endif
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11Utils_GetBufferTypeAttribute_1(_Handle, Module.getHandle(), hSession, hObject, Attribute, SB_STD_VECTOR_FRONT_ADR(Def), (int32_t)Def.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
		SBCheckError(SBGetLastReturnBuffer(-1119466412, 6, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
#else
		SBCheckError(SBGetLastReturnBuffer(1306852311, 6, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
#endif
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
void TElPKCS11Utils::GetBufferTypeAttribute_Inst(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Def, std::vector<uint8_t> &OutResult)
#else
void TElPKCS11Utils::GetBufferTypeAttribute_Inst(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Def, std::vector<uint8_t> &OutResult)
#endif
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11Utils_GetBufferTypeAttribute_1(_Handle, (Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, hSession, hObject, Attribute, SB_STD_VECTOR_FRONT_ADR(Def), (int32_t)Def.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
		SBCheckError(SBGetLastReturnBuffer(-1119466412, 6, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
#else
		SBCheckError(SBGetLastReturnBuffer(1306852311, 6, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
#endif
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
bool TElPKCS11Utils::GetBooleanAttribute(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, bool Def)
#else
bool TElPKCS11Utils::GetBooleanAttribute(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, bool Def)
#endif
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11Utils_GetBooleanAttribute(Module.getHandle(), hSession, hObject, Attribute, (int8_t)Def, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
bool TElPKCS11Utils::GetBooleanAttribute(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, bool Def)
#else
bool TElPKCS11Utils::GetBooleanAttribute(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, bool Def)
#endif
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11Utils_GetBooleanAttribute((Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, hSession, hObject, Attribute, (int8_t)Def, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
bool TElPKCS11Utils::GetBooleanAttribute_Inst(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, bool Def)
#else
bool TElPKCS11Utils::GetBooleanAttribute_Inst(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, bool Def)
#endif
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11Utils_GetBooleanAttribute_1(_Handle, Module.getHandle(), hSession, hObject, Attribute, (int8_t)Def, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
bool TElPKCS11Utils::GetBooleanAttribute_Inst(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, bool Def)
#else
bool TElPKCS11Utils::GetBooleanAttribute_Inst(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, bool Def)
#endif
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11Utils_GetBooleanAttribute_1(_Handle, (Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, hSession, hObject, Attribute, (int8_t)Def, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE uint32_t TElPKCS11Utils::GetULongAttribute(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, uint32_t Def)
#else
SB_INLINE int64_t TElPKCS11Utils::GetULongAttribute(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Def)
#endif
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11Utils_GetULongAttribute(Module.getHandle(), hSession, hObject, Attribute, Def, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE uint32_t TElPKCS11Utils::GetULongAttribute(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, uint32_t Def)
#else
SB_INLINE int64_t TElPKCS11Utils::GetULongAttribute(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Def)
#endif
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11Utils_GetULongAttribute((Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, hSession, hObject, Attribute, Def, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE uint32_t TElPKCS11Utils::GetULongAttribute_Inst(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, uint32_t Def)
#else
SB_INLINE int64_t TElPKCS11Utils::GetULongAttribute_Inst(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Def)
#endif
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11Utils_GetULongAttribute_1(_Handle, Module.getHandle(), hSession, hObject, Attribute, Def, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE uint32_t TElPKCS11Utils::GetULongAttribute_Inst(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, uint32_t Def)
#else
SB_INLINE int64_t TElPKCS11Utils::GetULongAttribute_Inst(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Def)
#endif
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11Utils_GetULongAttribute_1(_Handle, (Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, hSession, hObject, Attribute, Def, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE int64_t TElPKCS11Utils::GetDateAttribute(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int64_t Def)
#else
SB_INLINE int64_t TElPKCS11Utils::GetDateAttribute(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Def)
#endif
{
	int64_t OutResult;
	SBCheckError(TElPKCS11Utils_GetDateAttribute(Module.getHandle(), hSession, hObject, Attribute, Def, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE int64_t TElPKCS11Utils::GetDateAttribute(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int64_t Def)
#else
SB_INLINE int64_t TElPKCS11Utils::GetDateAttribute(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Def)
#endif
{
	int64_t OutResult;
	SBCheckError(TElPKCS11Utils_GetDateAttribute((Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, hSession, hObject, Attribute, Def, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE int64_t TElPKCS11Utils::GetDateAttribute_Inst(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int64_t Def)
#else
SB_INLINE int64_t TElPKCS11Utils::GetDateAttribute_Inst(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Def)
#endif
{
	int64_t OutResult;
	SBCheckError(TElPKCS11Utils_GetDateAttribute_1(_Handle, Module.getHandle(), hSession, hObject, Attribute, Def, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE int64_t TElPKCS11Utils::GetDateAttribute_Inst(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int64_t Def)
#else
SB_INLINE int64_t TElPKCS11Utils::GetDateAttribute_Inst(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Def)
#endif
{
	int64_t OutResult;
	SBCheckError(TElPKCS11Utils_GetDateAttribute_1(_Handle, (Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, hSession, hObject, Attribute, Def, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Utils::SetObjectAttribute(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Value)
#else
SB_INLINE void TElPKCS11Utils::SetObjectAttribute(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Value)
#endif
{
	SBCheckError(TElPKCS11Utils_SetObjectAttribute(Module.getHandle(), hSession, hObject, Attribute, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Utils::SetObjectAttribute(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Value)
#else
SB_INLINE void TElPKCS11Utils::SetObjectAttribute(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Value)
#endif
{
	SBCheckError(TElPKCS11Utils_SetObjectAttribute((Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, hSession, hObject, Attribute, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Utils::SetObjectAttribute_Inst(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Value)
#else
SB_INLINE void TElPKCS11Utils::SetObjectAttribute_Inst(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Value)
#endif
{
	SBCheckError(TElPKCS11Utils_SetObjectAttribute_1(_Handle, Module.getHandle(), hSession, hObject, Attribute, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Utils::SetObjectAttribute_Inst(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Value)
#else
SB_INLINE void TElPKCS11Utils::SetObjectAttribute_Inst(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Value)
#endif
{
	SBCheckError(TElPKCS11Utils_SetObjectAttribute_1(_Handle, (Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, hSession, hObject, Attribute, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Utils::SetBufferTypeAttribute(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Value)
#else
SB_INLINE void TElPKCS11Utils::SetBufferTypeAttribute(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Value)
#endif
{
	SBCheckError(TElPKCS11Utils_SetBufferTypeAttribute(Module.getHandle(), hSession, hObject, Attribute, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Utils::SetBufferTypeAttribute(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Value)
#else
SB_INLINE void TElPKCS11Utils::SetBufferTypeAttribute(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Value)
#endif
{
	SBCheckError(TElPKCS11Utils_SetBufferTypeAttribute((Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, hSession, hObject, Attribute, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Utils::SetBufferTypeAttribute_Inst(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Value)
#else
SB_INLINE void TElPKCS11Utils::SetBufferTypeAttribute_Inst(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Value)
#endif
{
	SBCheckError(TElPKCS11Utils_SetBufferTypeAttribute_1(_Handle, Module.getHandle(), hSession, hObject, Attribute, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Utils::SetBufferTypeAttribute_Inst(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Value)
#else
SB_INLINE void TElPKCS11Utils::SetBufferTypeAttribute_Inst(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Value)
#endif
{
	SBCheckError(TElPKCS11Utils_SetBufferTypeAttribute_1(_Handle, (Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, hSession, hObject, Attribute, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Utils::SetBooleanAttribute(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, bool Value)
#else
SB_INLINE void TElPKCS11Utils::SetBooleanAttribute(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, bool Value)
#endif
{
	SBCheckError(TElPKCS11Utils_SetBooleanAttribute(Module.getHandle(), hSession, hObject, Attribute, (int8_t)Value));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Utils::SetBooleanAttribute(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, bool Value)
#else
SB_INLINE void TElPKCS11Utils::SetBooleanAttribute(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, bool Value)
#endif
{
	SBCheckError(TElPKCS11Utils_SetBooleanAttribute((Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, hSession, hObject, Attribute, (int8_t)Value));
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Utils::SetBooleanAttribute_Inst(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, bool Value)
#else
SB_INLINE void TElPKCS11Utils::SetBooleanAttribute_Inst(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, bool Value)
#endif
{
	SBCheckError(TElPKCS11Utils_SetBooleanAttribute_1(_Handle, Module.getHandle(), hSession, hObject, Attribute, (int8_t)Value));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Utils::SetBooleanAttribute_Inst(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, bool Value)
#else
SB_INLINE void TElPKCS11Utils::SetBooleanAttribute_Inst(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, bool Value)
#endif
{
	SBCheckError(TElPKCS11Utils_SetBooleanAttribute_1(_Handle, (Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, hSession, hObject, Attribute, (int8_t)Value));
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Utils::SetULongAttribute(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, uint32_t Value)
#else
SB_INLINE void TElPKCS11Utils::SetULongAttribute(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Value)
#endif
{
	SBCheckError(TElPKCS11Utils_SetULongAttribute(Module.getHandle(), hSession, hObject, Attribute, Value));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Utils::SetULongAttribute(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, uint32_t Value)
#else
SB_INLINE void TElPKCS11Utils::SetULongAttribute(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Value)
#endif
{
	SBCheckError(TElPKCS11Utils_SetULongAttribute((Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, hSession, hObject, Attribute, Value));
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Utils::SetULongAttribute_Inst(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, uint32_t Value)
#else
SB_INLINE void TElPKCS11Utils::SetULongAttribute_Inst(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Value)
#endif
{
	SBCheckError(TElPKCS11Utils_SetULongAttribute_1(_Handle, Module.getHandle(), hSession, hObject, Attribute, Value));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Utils::SetULongAttribute_Inst(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, uint32_t Value)
#else
SB_INLINE void TElPKCS11Utils::SetULongAttribute_Inst(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Value)
#endif
{
	SBCheckError(TElPKCS11Utils_SetULongAttribute_1(_Handle, (Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, hSession, hObject, Attribute, Value));
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Utils::SetDateAttribute(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int64_t Value)
#else
SB_INLINE void TElPKCS11Utils::SetDateAttribute(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Value)
#endif
{
	SBCheckError(TElPKCS11Utils_SetDateAttribute(Module.getHandle(), hSession, hObject, Attribute, Value));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Utils::SetDateAttribute(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int64_t Value)
#else
SB_INLINE void TElPKCS11Utils::SetDateAttribute(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Value)
#endif
{
	SBCheckError(TElPKCS11Utils_SetDateAttribute((Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, hSession, hObject, Attribute, Value));
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Utils::SetDateAttribute_Inst(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int64_t Value)
#else
SB_INLINE void TElPKCS11Utils::SetDateAttribute_Inst(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Value)
#endif
{
	SBCheckError(TElPKCS11Utils_SetDateAttribute_1(_Handle, Module.getHandle(), hSession, hObject, Attribute, Value));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPKCS11Utils::SetDateAttribute_Inst(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int64_t Value)
#else
SB_INLINE void TElPKCS11Utils::SetDateAttribute_Inst(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Value)
#endif
{
	SBCheckError(TElPKCS11Utils_SetDateAttribute_1(_Handle, (Module != NULL) ? Module->getHandle() : SB_NULL_HANDLE, hSession, hObject, Attribute, Value));
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

SB_INLINE int32_t TElPKCS11Utils::ConvertPKCS11KeyTypeToSBBKeyType(int32_t KeyType)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11Utils_ConvertPKCS11KeyTypeToSBBKeyType(KeyType, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11Utils::ConvertPKCS11KeyTypeToSBBKeyType_Inst(int32_t KeyType)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11Utils_ConvertPKCS11KeyTypeToSBBKeyType_1(_Handle, KeyType, &OutResult));
	return OutResult;
}

TElPKCS11Utils::TElPKCS11Utils(TElPKCS11UtilsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPKCS11Utils::TElPKCS11Utils() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11Utils_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPKCS11UTILS */

#ifdef SB_USE_CLASS_TELPKCS11NSSPARAMS

bool TElPKCS11NSSParams::Load(const std::vector<uint8_t> &Data)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11NSSParams_Load(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElPKCS11NSSParams::Save(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11NSSParams_Save(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-537035344, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11NSSParams::get_ConfigDir(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11NSSParams_get_ConfigDir(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(559108837, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11NSSParams::set_ConfigDir(const std::string &Value)
{
	SBCheckError(TElPKCS11NSSParams_set_ConfigDir(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPKCS11NSSParams::get_CertPrefix(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11NSSParams_get_CertPrefix(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-243952163, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11NSSParams::set_CertPrefix(const std::string &Value)
{
	SBCheckError(TElPKCS11NSSParams_set_CertPrefix(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPKCS11NSSParams::get_KeyPrefix(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11NSSParams_get_KeyPrefix(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(489996109, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11NSSParams::set_KeyPrefix(const std::string &Value)
{
	SBCheckError(TElPKCS11NSSParams_set_KeyPrefix(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPKCS11NSSParams::get_SecMod(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11NSSParams_get_SecMod(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1022661132, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11NSSParams::set_SecMod(const std::string &Value)
{
	SBCheckError(TElPKCS11NSSParams_set_SecMod(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPKCS11NSSParams::get_Flags(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11NSSParams_get_Flags(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1519439409, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11NSSParams::set_Flags(const std::string &Value)
{
	SBCheckError(TElPKCS11NSSParams_set_Flags(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElPKCS11NSSParams::get_UseNSSMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11NSSParams_get_UseNSSMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11NSSParams::set_UseNSSMode(bool Value)
{
	SBCheckError(TElPKCS11NSSParams_set_UseNSSMode(_Handle, (int8_t)Value));
}

void TElPKCS11NSSParams::get_RawParamsStr(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11NSSParams_get_RawParamsStr(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-245271062, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11NSSParams::set_RawParamsStr(const std::string &Value)
{
	SBCheckError(TElPKCS11NSSParams_set_RawParamsStr(_Handle, Value.data(), (int32_t)Value.length()));
}

TElPKCS11NSSParams::TElPKCS11NSSParams(TElPKCS11NSSParamsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPKCS11NSSParams::TElPKCS11NSSParams() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11NSSParams_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPKCS11NSSPARAMS */

#ifdef SB_USE_CLASS_TELPKCS11MODULELIST

#ifndef SB_IOS
#ifdef SB_USE_CLASS_TELPKCS11MODULE
SB_INLINE TElPKCS11ModuleHandle TElPKCS11ModuleList::LoadModule(const std::string &ModuleName, bool UseSystemProcAddresses, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo)
{
	TElPKCS11ModuleHandle OutResult;
	SBCheckError(TElPKCS11ModuleList_LoadModule(_Handle, ModuleName.data(), (int32_t)ModuleName.length(), (int8_t)UseSystemProcAddresses, (int8_t)TrySingleThreadedMode, (int8_t)AutoRefreshSlotInfo, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#else
#ifdef SB_USE_CLASSES_TELPKCS11FUNCTIONSMANAGER_AND_TELPKCS11MODULE
SB_INLINE TElPKCS11ModuleHandle TElPKCS11ModuleList::LoadModule(TElPKCS11FunctionsManager &FuncMng, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo)
{
	TElPKCS11ModuleHandle OutResult;
	SBCheckError(TElPKCS11ModuleList_LoadModule(_Handle, FuncMng.getHandle(), (int8_t)TrySingleThreadedMode, (int8_t)AutoRefreshSlotInfo, &OutResult));
	return OutResult;
}

SB_INLINE TElPKCS11ModuleHandle TElPKCS11ModuleList::LoadModule(TElPKCS11FunctionsManager *FuncMng, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo)
{
	TElPKCS11ModuleHandle OutResult;
	SBCheckError(TElPKCS11ModuleList_LoadModule(_Handle, (FuncMng != NULL) ? FuncMng->getHandle() : SB_NULL_HANDLE, (int8_t)TrySingleThreadedMode, (int8_t)AutoRefreshSlotInfo, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPKCS11FUNCTIONSMANAGER_AND_TELPKCS11MODULE */
#endif

#ifndef SB_IOS
#ifdef SB_USE_CLASS_TELPKCS11MODULE
SB_INLINE TElPKCS11ModuleHandle TElPKCS11ModuleList::LoadModule(const std::string &ModuleName, bool UseSystemProcAddresses, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo, bool PreserveSettingsIfExists)
{
	TElPKCS11ModuleHandle OutResult;
	SBCheckError(TElPKCS11ModuleList_LoadModule_1(_Handle, ModuleName.data(), (int32_t)ModuleName.length(), (int8_t)UseSystemProcAddresses, (int8_t)TrySingleThreadedMode, (int8_t)AutoRefreshSlotInfo, (int8_t)PreserveSettingsIfExists, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#endif

#ifndef SB_IOS
#ifdef SB_USE_CLASS_TELPKCS11MODULE
SB_INLINE TElPKCS11ModuleHandle TElPKCS11ModuleList::LoadModule(const std::string &ModuleName, bool UseSystemProcAddresses, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo, bool PreserveSettingsIfExists, bool OnDemandMode)
{
	TElPKCS11ModuleHandle OutResult;
	SBCheckError(TElPKCS11ModuleList_LoadModule_2(_Handle, ModuleName.data(), (int32_t)ModuleName.length(), (int8_t)UseSystemProcAddresses, (int8_t)TrySingleThreadedMode, (int8_t)AutoRefreshSlotInfo, (int8_t)PreserveSettingsIfExists, (int8_t)OnDemandMode, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#else
#ifdef SB_USE_CLASSES_TELPKCS11FUNCTIONSMANAGER_AND_TELPKCS11MODULE
SB_INLINE TElPKCS11ModuleHandle TElPKCS11ModuleList::LoadModule(TElPKCS11FunctionsManager &FuncMng, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo, bool PreserveSettingsIfExists)
{
	TElPKCS11ModuleHandle OutResult;
	SBCheckError(TElPKCS11ModuleList_LoadModule_1(_Handle, FuncMng.getHandle(), (int8_t)TrySingleThreadedMode, (int8_t)AutoRefreshSlotInfo, (int8_t)PreserveSettingsIfExists, &OutResult));
	return OutResult;
}

SB_INLINE TElPKCS11ModuleHandle TElPKCS11ModuleList::LoadModule(TElPKCS11FunctionsManager *FuncMng, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo, bool PreserveSettingsIfExists)
{
	TElPKCS11ModuleHandle OutResult;
	SBCheckError(TElPKCS11ModuleList_LoadModule_1(_Handle, (FuncMng != NULL) ? FuncMng->getHandle() : SB_NULL_HANDLE, (int8_t)TrySingleThreadedMode, (int8_t)AutoRefreshSlotInfo, (int8_t)PreserveSettingsIfExists, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPKCS11FUNCTIONSMANAGER_AND_TELPKCS11MODULE */
#endif

#ifndef SB_IOS
#ifdef SB_USE_CLASSES_TELPKCS11MODULE_AND_TELPKCS11NSSPARAMS
SB_INLINE TElPKCS11ModuleHandle TElPKCS11ModuleList::LoadModule(const std::string &ModuleName, bool UseSystemProcAddresses, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo, bool PreserveSettingsIfExists, bool OnDemandMode, TElPKCS11NSSParams &NSSParams, bool NoImplicitSlotInfoUpdates)
{
	TElPKCS11ModuleHandle OutResult;
	SBCheckError(TElPKCS11ModuleList_LoadModule_3(_Handle, ModuleName.data(), (int32_t)ModuleName.length(), (int8_t)UseSystemProcAddresses, (int8_t)TrySingleThreadedMode, (int8_t)AutoRefreshSlotInfo, (int8_t)PreserveSettingsIfExists, (int8_t)OnDemandMode, NSSParams.getHandle(), (int8_t)NoImplicitSlotInfoUpdates, &OutResult));
	return OutResult;
}

SB_INLINE TElPKCS11ModuleHandle TElPKCS11ModuleList::LoadModule(const std::string &ModuleName, bool UseSystemProcAddresses, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo, bool PreserveSettingsIfExists, bool OnDemandMode, TElPKCS11NSSParams *NSSParams, bool NoImplicitSlotInfoUpdates)
{
	TElPKCS11ModuleHandle OutResult;
	SBCheckError(TElPKCS11ModuleList_LoadModule_3(_Handle, ModuleName.data(), (int32_t)ModuleName.length(), (int8_t)UseSystemProcAddresses, (int8_t)TrySingleThreadedMode, (int8_t)AutoRefreshSlotInfo, (int8_t)PreserveSettingsIfExists, (int8_t)OnDemandMode, (NSSParams != NULL) ? NSSParams->getHandle() : SB_NULL_HANDLE, (int8_t)NoImplicitSlotInfoUpdates, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPKCS11MODULE_AND_TELPKCS11NSSPARAMS */
#else

#ifdef SB_USE_CLASSES_TELPKCS11FUNCTIONSMANAGER_AND_TELPKCS11MODULE
SB_INLINE TElPKCS11ModuleHandle TElPKCS11ModuleList::LoadModule(TElPKCS11FunctionsManager &FuncMng, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo, bool PreserveSettingsIfExists, bool OnDemandMode)
{
	TElPKCS11ModuleHandle OutResult;
	SBCheckError(TElPKCS11ModuleList_LoadModule_2(_Handle, FuncMng.getHandle(), (int8_t)TrySingleThreadedMode, (int8_t)AutoRefreshSlotInfo, (int8_t)PreserveSettingsIfExists, (int8_t)OnDemandMode, &OutResult));
	return OutResult;
}

SB_INLINE TElPKCS11ModuleHandle TElPKCS11ModuleList::LoadModule(TElPKCS11FunctionsManager *FuncMng, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo, bool PreserveSettingsIfExists, bool OnDemandMode)
{
	TElPKCS11ModuleHandle OutResult;
	SBCheckError(TElPKCS11ModuleList_LoadModule_2(_Handle, (FuncMng != NULL) ? FuncMng->getHandle() : SB_NULL_HANDLE, (int8_t)TrySingleThreadedMode, (int8_t)AutoRefreshSlotInfo, (int8_t)PreserveSettingsIfExists, (int8_t)OnDemandMode, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPKCS11FUNCTIONSMANAGER_AND_TELPKCS11MODULE */

#ifdef SB_USE_CLASSES_TELPKCS11FUNCTIONSMANAGER_AND_TELPKCS11MODULE_AND_TELPKCS11NSSPARAMS
SB_INLINE TElPKCS11ModuleHandle TElPKCS11ModuleList::LoadModule(TElPKCS11FunctionsManager &FuncMng, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo, bool PreserveSettingsIfExists, bool OnDemandMode, TElPKCS11NSSParams &NSSParams, bool NoImplicitSlotInfoUpdates)
{
	TElPKCS11ModuleHandle OutResult;
	SBCheckError(TElPKCS11ModuleList_LoadModule_3(_Handle, FuncMng.getHandle(), (int8_t)TrySingleThreadedMode, (int8_t)AutoRefreshSlotInfo, (int8_t)PreserveSettingsIfExists, (int8_t)OnDemandMode, NSSParams.getHandle(), (int8_t)NoImplicitSlotInfoUpdates, &OutResult));
	return OutResult;
}

SB_INLINE TElPKCS11ModuleHandle TElPKCS11ModuleList::LoadModule(TElPKCS11FunctionsManager *FuncMng, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo, bool PreserveSettingsIfExists, bool OnDemandMode, TElPKCS11NSSParams *NSSParams, bool NoImplicitSlotInfoUpdates)
{
	TElPKCS11ModuleHandle OutResult;
	SBCheckError(TElPKCS11ModuleList_LoadModule_3(_Handle, (FuncMng != NULL) ? FuncMng->getHandle() : SB_NULL_HANDLE, (int8_t)TrySingleThreadedMode, (int8_t)AutoRefreshSlotInfo, (int8_t)PreserveSettingsIfExists, (int8_t)OnDemandMode, (NSSParams != NULL) ? NSSParams->getHandle() : SB_NULL_HANDLE, (int8_t)NoImplicitSlotInfoUpdates, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPKCS11FUNCTIONSMANAGER_AND_TELPKCS11MODULE_AND_TELPKCS11NSSPARAMS */
#endif

#ifdef SB_USE_CLASS_TELPKCS11MODULE
SB_INLINE void TElPKCS11ModuleList::UnloadModule(TElPKCS11Module &aModule)
{
	SBCheckError(TElPKCS11ModuleList_UnloadModule(_Handle, aModule.getHandle()));
}

SB_INLINE void TElPKCS11ModuleList::UnloadModule(TElPKCS11Module *aModule)
{
	SBCheckError(TElPKCS11ModuleList_UnloadModule(_Handle, (aModule != NULL) ? aModule->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

SB_INLINE int32_t TElPKCS11ModuleList::get_ModuleCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11ModuleList_get_ModuleCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPKCS11MODULE
TElPKCS11Module* TElPKCS11ModuleList::get_Modules(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11ModuleList_get_Modules(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Modules)
		this->_Inst_Modules = new TElPKCS11Module(hOutResult, ohFalse);
	else
		this->_Inst_Modules->updateHandle(hOutResult);
	return this->_Inst_Modules;
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

void TElPKCS11ModuleList::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS11MODULE
	this->_Inst_Modules = NULL;
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
}

TElPKCS11ModuleList::TElPKCS11ModuleList(TElPKCS11ModuleListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS11ModuleList::TElPKCS11ModuleList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS11ModuleList_Create(&_Handle));
}

TElPKCS11ModuleList::~TElPKCS11ModuleList()
{
#ifdef SB_USE_CLASS_TELPKCS11MODULE
	delete this->_Inst_Modules;
	this->_Inst_Modules = NULL;
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
}
#endif /* SB_USE_CLASS_TELPKCS11MODULELIST */

#ifdef SB_USE_CLASS_TELPKCS11ALGORITHMINFO

SB_INLINE int32_t TElPKCS11AlgorithmInfo::get_Algorithm()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11AlgorithmInfo_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11AlgorithmInfo::get_Mode()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11AlgorithmInfo_get_Mode(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE uint32_t TElPKCS11AlgorithmInfo::get_Mechanism()
#else
SB_INLINE int64_t TElPKCS11AlgorithmInfo::get_Mechanism()
#endif
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11AlgorithmInfo_get_Mechanism(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE uint32_t TElPKCS11AlgorithmInfo::get_KeyMechanism()
#else
SB_INLINE int64_t TElPKCS11AlgorithmInfo::get_KeyMechanism()
#endif
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPKCS11AlgorithmInfo_get_KeyMechanism(_Handle, &OutResult));
	return OutResult;
}

bool TElPKCS11AlgorithmInfo::get_PaddingUsed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11AlgorithmInfo_get_PaddingUsed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11AlgorithmInfo::get_CanGenerate()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11AlgorithmInfo_get_CanGenerate(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11AlgorithmInfo::get_CanEncrypt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11AlgorithmInfo_get_CanEncrypt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11AlgorithmInfo::get_CanSign()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11AlgorithmInfo_get_CanSign(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11AlgorithmInfo::get_CanSignRecover()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11AlgorithmInfo_get_CanSignRecover(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11AlgorithmInfo::get_CanDigest()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11AlgorithmInfo_get_CanDigest(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11AlgorithmInfo::get_CanWrap()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11AlgorithmInfo_get_CanWrap(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11AlgorithmInfo::get_CanDerive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11AlgorithmInfo_get_CanDerive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElPKCS11AlgorithmInfo::get_SignHashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11AlgorithmInfo_get_SignHashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

TElPKCS11AlgorithmInfo::TElPKCS11AlgorithmInfo(TElPKCS11AlgorithmInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPKCS11AlgorithmInfo::TElPKCS11AlgorithmInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11AlgorithmInfo_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPKCS11ALGORITHMINFO */

#ifdef SB_USE_CLASS_TELPKCS11ALGORITHMCONVERTER

SB_INLINE int32_t TElPKCS11AlgorithmConverter::Find(int32_t Algorithm, int32_t Mode, int32_t Operation, bool PaddingUsed)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11AlgorithmConverter_Find(_Handle, Algorithm, Mode, Operation, (int8_t)PaddingUsed, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TLIST
SB_INLINE void TElPKCS11AlgorithmConverter::Find(int32_t Algorithm, int32_t Mode, TList &Infos)
{
	SBCheckError(TElPKCS11AlgorithmConverter_Find_1(_Handle, Algorithm, Mode, Infos.getHandle()));
}

SB_INLINE void TElPKCS11AlgorithmConverter::Find(int32_t Algorithm, int32_t Mode, TList *Infos)
{
	SBCheckError(TElPKCS11AlgorithmConverter_Find_1(_Handle, Algorithm, Mode, (Infos != NULL) ? Infos->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TLIST */

SB_INLINE int32_t TElPKCS11AlgorithmConverter::FindSignatureAlgorithmInfo(int32_t Algorithm, int32_t HashAlgorithm)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11AlgorithmConverter_FindSignatureAlgorithmInfo(_Handle, Algorithm, HashAlgorithm, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
int32_t TElPKCS11AlgorithmConverter::GetAlgorithmByPKCS11Mechanism(uint32_t Mech, int32_t &Mode, bool &Gen)
#else
int32_t TElPKCS11AlgorithmConverter::GetAlgorithmByPKCS11Mechanism(int64_t Mech, int32_t &Mode, bool &Gen)
#endif
{
	int32_t OutResult;
	int8_t GenRaw = (int8_t)Gen;
	SBCheckError(TElPKCS11AlgorithmConverter_GetAlgorithmByPKCS11Mechanism(_Handle, Mech, &Mode, &GenRaw, &OutResult));
	Gen = (GenRaw != 0);
	return OutResult;
}

bool TElPKCS11AlgorithmConverter::GetPKCS11MechanismByAlgorithm(int32_t Algorithm, int32_t Mode, SB_CK_MECHANISM &Mech)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11AlgorithmConverter_GetPKCS11MechanismByAlgorithm(_Handle, Algorithm, Mode, &Mech, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELPKCS11ALGORITHMINFO
TElPKCS11AlgorithmInfo* TElPKCS11AlgorithmConverter::get_AlgorithmInfos(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS11AlgorithmConverter_get_AlgorithmInfos(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AlgorithmInfos)
		this->_Inst_AlgorithmInfos = new TElPKCS11AlgorithmInfo(hOutResult, ohFalse);
	else
		this->_Inst_AlgorithmInfos->updateHandle(hOutResult);
	return this->_Inst_AlgorithmInfos;
}
#endif /* SB_USE_CLASS_TELPKCS11ALGORITHMINFO */

SB_INLINE int32_t TElPKCS11AlgorithmConverter::get_AlgorithmInfoCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS11AlgorithmConverter_get_AlgorithmInfoCount(_Handle, &OutResult));
	return OutResult;
}

void TElPKCS11AlgorithmConverter::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS11ALGORITHMINFO
	this->_Inst_AlgorithmInfos = NULL;
#endif /* SB_USE_CLASS_TELPKCS11ALGORITHMINFO */
}

TElPKCS11AlgorithmConverter::TElPKCS11AlgorithmConverter(TElPKCS11AlgorithmConverterHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS11AlgorithmConverter::TElPKCS11AlgorithmConverter() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS11AlgorithmConverter_Create(&_Handle));
}

TElPKCS11AlgorithmConverter::~TElPKCS11AlgorithmConverter()
{
#ifdef SB_USE_CLASS_TELPKCS11ALGORITHMINFO
	delete this->_Inst_AlgorithmInfos;
	this->_Inst_AlgorithmInfos = NULL;
#endif /* SB_USE_CLASS_TELPKCS11ALGORITHMINFO */
}
#endif /* SB_USE_CLASS_TELPKCS11ALGORITHMCONVERTER */

#ifdef SB_USE_CLASS_TELSLOTEVENTMONITORINGTHREAD

SB_INLINE void TElSlotEventMonitoringThread::get_OnSlotEvent(TElSlotEventMonitoringThreadEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSlotEventMonitoringThread_get_OnSlotEvent(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSlotEventMonitoringThread::set_OnSlotEvent(TElSlotEventMonitoringThreadEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSlotEventMonitoringThread_set_OnSlotEvent(_Handle, pMethodValue, pDataValue));
}

TElSlotEventMonitoringThread::TElSlotEventMonitoringThread(TElSlotEventMonitoringThreadHandle handle, TElOwnHandle ownHandle) : TThread(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELPKCS11MODULE
TElSlotEventMonitoringThread::TElSlotEventMonitoringThread(TElPKCS11Module &PKCS11Module, bool SynchronizeGUI, bool UseGetSlotInfo, int32_t Delay) : TThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSlotEventMonitoringThread_Create(PKCS11Module.getHandle(), (int8_t)SynchronizeGUI, (int8_t)UseGetSlotInfo, Delay, &_Handle));
}

TElSlotEventMonitoringThread::TElSlotEventMonitoringThread(TElPKCS11Module *PKCS11Module, bool SynchronizeGUI, bool UseGetSlotInfo, int32_t Delay) : TThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSlotEventMonitoringThread_Create((PKCS11Module != NULL) ? PKCS11Module->getHandle() : SB_NULL_HANDLE, (int8_t)SynchronizeGUI, (int8_t)UseGetSlotInfo, Delay, &_Handle));
}
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#endif /* SB_USE_CLASS_TELSLOTEVENTMONITORINGTHREAD */

#ifdef SB_USE_GLOBAL_PROCS_PKCS11BASE

#ifdef SB_USE_CLASS_TELPKCS11ALGORITHMCONVERTER
SB_INLINE TElPKCS11AlgorithmConverterHandle PKCS11AlgorithmConverter()
{
	TElPKCS11AlgorithmConverterHandle OutResult;
	SBCheckError(SBPKCS11Base_PKCS11AlgorithmConverter(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11ALGORITHMCONVERTER */

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE uint32_t CreateMutexCallback(void * &MutexPtr)
#else
SB_INLINE int64_t CreateMutexCallback(void * &MutexPtr)
#endif
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(SBPKCS11Base_CreateMutexCallback(&MutexPtr, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE uint32_t DestroyMutexCallback(void * MutexPtr)
#else
SB_INLINE int64_t DestroyMutexCallback(void * MutexPtr)
#endif
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(SBPKCS11Base_DestroyMutexCallback(MutexPtr, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE uint32_t LockMutexCallback(void * MutexPtr)
#else
SB_INLINE int64_t LockMutexCallback(void * MutexPtr)
#endif
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(SBPKCS11Base_LockMutexCallback(MutexPtr, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE uint32_t UnlockMutexCallback(void * MutexPtr)
#else
SB_INLINE int64_t UnlockMutexCallback(void * MutexPtr)
#endif
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(SBPKCS11Base_UnlockMutexCallback(MutexPtr, &OutResult));
	return OutResult;
}

void GetPKCS11String(const std::vector<uint8_t> &Buffer, int32_t MaxLength, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBPKCS11Base_GetPKCS11String(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), MaxLength, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(757867836, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void PKCS11CheckError(int32_t FunctionCode, uint32_t ResultCode)
#else
SB_INLINE void PKCS11CheckError(int32_t FunctionCode, int64_t ResultCode)
#endif
{
	SBCheckError(SBPKCS11Base_PKCS11CheckError(FunctionCode, ResultCode));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
void GetPKCS11ErrorNameByCode(uint32_t Code, std::string &OutResult)
#else
void GetPKCS11ErrorNameByCode(int64_t Code, std::string &OutResult)
#endif
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBPKCS11Base_GetPKCS11ErrorNameByCode(Code, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
		SBCheckError(SBGetLastReturnStringA(-857256447, 1, (char *)OutResult.data(), &szOutResult));
#else
		SBCheckError(SBGetLastReturnStringA(-75695820, 1, (char *)OutResult.data(), &szOutResult));
#endif
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
void PKCS11AddAttribute(std::vector<TPKCS11Attribute> &Attributes, uint32_t _type, void * pValue, uint32_t ulValueLen)
#else
void PKCS11AddAttribute(std::vector<TPKCS11Attribute> &Attributes, int64_t _type, void * pValue, int64_t ulValueLen)
#endif
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	int32_t szAttributes = (int32_t)Attributes.size() * 12;
#else
	int32_t szAttributes = (int32_t)Attributes.size() * 20;
#endif
	uint32_t _err = SBPKCS11Base_PKCS11AddAttribute((TPKCS11Attribute *)SB_STD_VECTOR_FRONT_ADR(Attributes), &szAttributes, _type, pValue, ulValueLen);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
#ifdef SB_NOT_CPU64_OR_WINDOWS
		Attributes.resize(szAttributes / 12);
		SBCheckError(SBGetLastReturnBuffer(1159521623, 0, (TPKCS11Attribute *)SB_STD_VECTOR_FRONT_ADR(Attributes), &szAttributes));
#else
		Attributes.resize(szAttributes / 20);
		SBCheckError(SBGetLastReturnBuffer(-1342726791, 0, (TPKCS11Attribute *)SB_STD_VECTOR_FRONT_ADR(Attributes), &szAttributes));
#endif
	}
	else
		SBCheckError(_err);

#ifdef SB_NOT_CPU64_OR_WINDOWS
	Attributes.resize(szAttributes / 12);
#else
	Attributes.resize(szAttributes / 20);
#endif
}

bool EncodeErrorInfo(const std::string &MethodName, const std::string &ErrorStr, const std::string &ErrorClassName, void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBPKCS11Base_EncodeErrorInfo(MethodName.data(), (int32_t)MethodName.length(), ErrorStr.data(), (int32_t)ErrorStr.length(), ErrorClassName.data(), (int32_t)ErrorClassName.length(), Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELPKCS11MODULELIST
SB_INLINE TElPKCS11ModuleListHandle GetPKCS11ModuleList()
{
	TElPKCS11ModuleListHandle OutResult;
	SBCheckError(SBPKCS11Base_GetPKCS11ModuleList(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS11MODULELIST */

#endif /* SB_USE_GLOBAL_PROCS_PKCS11BASE */

};	/* namespace SecureBlackbox */
