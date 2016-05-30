#include "sbdictionary.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELDICTIONARYENTRY

SB_INLINE uint32_t TElDictionaryEntry::get_HashCode()
{
	uint32_t OutResult;
	SBCheckError(TElDictionaryEntry_get_HashCode(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDictionaryEntry::set_HashCode(uint32_t Value)
{
	SBCheckError(TElDictionaryEntry_set_HashCode(_Handle, Value));
}

SB_INLINE int32_t TElDictionaryEntry::get_Next()
{
	int32_t OutResult;
	SBCheckError(TElDictionaryEntry_get_Next(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDictionaryEntry::set_Next(int32_t Value)
{
	SBCheckError(TElDictionaryEntry_set_Next(_Handle, Value));
}

TObject* TElDictionaryEntry::get_Value()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDictionaryEntry_get_Value(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Value)
		this->_Inst_Value = new TObject(hOutResult, ohFalse);
	else
		this->_Inst_Value->updateHandle(hOutResult);
	return this->_Inst_Value;
}

SB_INLINE void TElDictionaryEntry::set_Value(TObject &Value)
{
	SBCheckError(TElDictionaryEntry_set_Value(_Handle, Value.getHandle()));
}

SB_INLINE void TElDictionaryEntry::set_Value(TObject *Value)
{
	SBCheckError(TElDictionaryEntry_set_Value(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

void TElDictionaryEntry::get_StrKey(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDictionaryEntry_get_StrKey(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1821037055, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDictionaryEntry::set_StrKey(const std::string &Value)
{
	SBCheckError(TElDictionaryEntry_set_StrKey(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDictionaryEntry::get_ByteKey(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDictionaryEntry_get_ByteKey(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(947065758, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDictionaryEntry::set_ByteKey(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDictionaryEntry_set_ByteKey(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElDictionaryEntry::initInstances()
{
	this->_Inst_Value = NULL;
}

TElDictionaryEntry::TElDictionaryEntry(TElDictionaryEntryHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElDictionaryEntry::TElDictionaryEntry() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDictionaryEntry_Create(&_Handle));
}

TElDictionaryEntry::~TElDictionaryEntry()
{
	delete this->_Inst_Value;
	this->_Inst_Value = NULL;
}
#endif /* SB_USE_CLASS_TELDICTIONARYENTRY */

#ifdef SB_USE_CLASS_TELDICTIONARY

SB_INLINE void TElDictionary::Clear()
{
	SBCheckError(TElDictionary_Clear(_Handle));
}

bool TElDictionary::Add(const std::string &Key, TObject &Value)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDictionary_Add(_Handle, Key.data(), (int32_t)Key.length(), Value.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDictionary::Add(const std::string &Key, TObject *Value)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDictionary_Add(_Handle, Key.data(), (int32_t)Key.length(), (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDictionary::Add(const std::vector<uint8_t> &Key, TObject &Value)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDictionary_Add_1(_Handle, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), Value.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDictionary::Add(const std::vector<uint8_t> &Key, TObject *Value)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDictionary_Add_1(_Handle, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDictionary::ContainsKey(const std::string &Key)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDictionary_ContainsKey(_Handle, Key.data(), (int32_t)Key.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDictionary::ContainsKey(const std::vector<uint8_t> &Key)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDictionary_ContainsKey_1(_Handle, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDictionary::ContainsValue(TObject &Value)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDictionary_ContainsValue(_Handle, Value.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDictionary::ContainsValue(TObject *Value)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDictionary_ContainsValue(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDictionary::Remove(const std::string &Key)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDictionary_Remove(_Handle, Key.data(), (int32_t)Key.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDictionary::Remove(const std::vector<uint8_t> &Key)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDictionary_Remove_1(_Handle, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDictionary::Remove(TObject &Value)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDictionary_Remove_2(_Handle, Value.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDictionary::Remove(TObject *Value)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDictionary_Remove_2(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDictionary::TryGetValue(const std::string &Key, TObject &Value)
{
	TElClassHandle hValue = Value.getHandle();
	int8_t OutResultRaw = 0;
	SBCheckError(TElDictionary_TryGetValue(_Handle, Key.data(), (int32_t)Key.length(), &hValue, &OutResultRaw));
	Value.updateHandle(hValue);
	return (OutResultRaw != 0);
}

bool TElDictionary::TryGetValue(const std::vector<uint8_t> &Key, TObject &Value)
{
	TElClassHandle hValue = Value.getHandle();
	int8_t OutResultRaw = 0;
	SBCheckError(TElDictionary_TryGetValue_1(_Handle, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), &hValue, &OutResultRaw));
	Value.updateHandle(hValue);
	return (OutResultRaw != 0);
}

SB_INLINE TObjectHandle TElDictionary::GetItem(const std::vector<uint8_t> &Key)
{
	TObjectHandle OutResult;
	SBCheckError(TElDictionary_GetItem(_Handle, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), &OutResult));
	return OutResult;
}

SB_INLINE TObjectHandle TElDictionary::GetItem(const std::string &Key)
{
	TObjectHandle OutResult;
	SBCheckError(TElDictionary_GetItem_1(_Handle, Key.data(), (int32_t)Key.length(), &OutResult));
	return OutResult;
}

SB_INLINE void TElDictionary::SetItem(const std::vector<uint8_t> &Key, TObject &Value)
{
	SBCheckError(TElDictionary_SetItem(_Handle, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), Value.getHandle()));
}

SB_INLINE void TElDictionary::SetItem(const std::vector<uint8_t> &Key, TObject *Value)
{
	SBCheckError(TElDictionary_SetItem(_Handle, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDictionary::SetItem(const std::string &Key, TObject &Value)
{
	SBCheckError(TElDictionary_SetItem_1(_Handle, Key.data(), (int32_t)Key.length(), Value.getHandle()));
}

SB_INLINE void TElDictionary::SetItem(const std::string &Key, TObject *Value)
{
	SBCheckError(TElDictionary_SetItem_1(_Handle, Key.data(), (int32_t)Key.length(), (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElDictionary::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElDictionary_get_Count(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDictionary::get_FreeCount()
{
	int32_t OutResult;
	SBCheckError(TElDictionary_get_FreeCount(_Handle, &OutResult));
	return OutResult;
}

TObject* TElDictionary::get_Values(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDictionary_get_Values(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Values)
		this->_Inst_Values = new TObject(hOutResult, ohFalse);
	else
		this->_Inst_Values->updateHandle(hOutResult);
	return this->_Inst_Values;
}

void TElDictionary::get_StringKeys(int32_t Index, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDictionary_get_StringKeys(_Handle, Index, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-186017449, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDictionary::get_ByteKeys(int32_t Index, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDictionary_get_ByteKeys(_Handle, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-395937803, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDictionary::get_OnDeleteValue(TSBDictionaryDeleteValueEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElDictionary_get_OnDeleteValue(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElDictionary::set_OnDeleteValue(TSBDictionaryDeleteValueEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElDictionary_set_OnDeleteValue(_Handle, pMethodValue, pDataValue));
}

void TElDictionary::initInstances()
{
	this->_Inst_Values = NULL;
}

TElDictionary::TElDictionary(TElDictionaryHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElDictionary::TElDictionary() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDictionary_Create(&_Handle));
}

TElDictionary::TElDictionary(int32_t Capacity) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDictionary_Create_1(Capacity, &_Handle));
}

TElDictionary::~TElDictionary()
{
	delete this->_Inst_Values;
	this->_Inst_Values = NULL;
}
#endif /* SB_USE_CLASS_TELDICTIONARY */

};	/* namespace SecureBlackbox */

