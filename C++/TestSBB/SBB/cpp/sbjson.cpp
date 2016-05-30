#include "sbjson.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELJSONENTITY

SB_INLINE void TElJsonEntity::Assign(TPersistent &Source)
{
	SBCheckError(TElJsonEntity_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElJsonEntity::Assign(TPersistent *Source)
{
	SBCheckError(TElJsonEntity_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElJsonEntityHandle TElJsonEntity::Clone()
{
	TElJsonEntityHandle OutResult;
	SBCheckError(TElJsonEntity_Clone(_Handle, &OutResult));
	return OutResult;
}

TElJsonEntity::TElJsonEntity(TElJsonEntityHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElJsonEntity::TElJsonEntity() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElJsonEntity_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELJSONENTITY */

#ifdef SB_USE_CLASS_TELJSONARRAY

SB_INLINE void TElJsonArray::Assign(TPersistent &Source)
{
	SBCheckError(TElJsonArray_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElJsonArray::Assign(TPersistent *Source)
{
	SBCheckError(TElJsonArray_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElJsonEntityHandle TElJsonArray::Clone()
{
	TElJsonEntityHandle OutResult;
	SBCheckError(TElJsonArray_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElJsonArray::Append(TElJsonEntity &Value)
{
	int32_t OutResult;
	SBCheckError(TElJsonArray_Append(_Handle, Value.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElJsonArray::Append(TElJsonEntity *Value)
{
	int32_t OutResult;
	SBCheckError(TElJsonArray_Append(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElJsonArray::Append(int32_t Value)
{
	int32_t OutResult;
	SBCheckError(TElJsonArray_Append_1(_Handle, Value, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElJsonArray::Append(double Value)
{
	int32_t OutResult;
	SBCheckError(TElJsonArray_Append_2(_Handle, Value, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElJsonArray::Append(bool Value)
{
	int32_t OutResult;
	SBCheckError(TElJsonArray_Append_3(_Handle, (int8_t)Value, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElJsonArray::Append(const std::string &Value)
{
	int32_t OutResult;
	SBCheckError(TElJsonArray_Append_4(_Handle, Value.data(), (int32_t)Value.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElJsonArray::Append()
{
	int32_t OutResult;
	SBCheckError(TElJsonArray_Append_5(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElJsonArray::Clear()
{
	SBCheckError(TElJsonArray_Clear(_Handle));
}

SB_INLINE void TElJsonArray::Delete(int32_t Index)
{
	SBCheckError(TElJsonArray_Delete(_Handle, Index));
}

SB_INLINE TElJsonArrayHandle TElJsonArray::GetArray(int32_t Index)
{
	TElJsonArrayHandle OutResult;
	SBCheckError(TElJsonArray_GetArray(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE TElJsonArrayHandle TElJsonArray::GetArrayIfExists(int32_t Index)
{
	TElJsonArrayHandle OutResult;
	SBCheckError(TElJsonArray_GetArrayIfExists(_Handle, Index, &OutResult));
	return OutResult;
}

bool TElJsonArray::GetBooleanValue(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElJsonArray_GetBooleanValue(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElJsonArray::GetBooleanValue(int32_t Index, bool Default)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElJsonArray_GetBooleanValue_1(_Handle, Index, (int8_t)Default, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE double TElJsonArray::GetDoubleValue(int32_t Index)
{
	double OutResult;
	SBCheckError(TElJsonArray_GetDoubleValue(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE double TElJsonArray::GetDoubleValue(int32_t Index, double Default)
{
	double OutResult;
	SBCheckError(TElJsonArray_GetDoubleValue_1(_Handle, Index, Default, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElJsonArray::GetIntegerValue(int32_t Index)
{
	int64_t OutResult;
	SBCheckError(TElJsonArray_GetIntegerValue(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElJsonArray::GetIntegerValue(int32_t Index, int64_t Default)
{
	int64_t OutResult;
	SBCheckError(TElJsonArray_GetIntegerValue_1(_Handle, Index, Default, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELJSONOBJECT
SB_INLINE TElJsonObjectHandle TElJsonArray::GetObject(int32_t Index)
{
	TElJsonObjectHandle OutResult;
	SBCheckError(TElJsonArray_GetObject(_Handle, Index, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELJSONOBJECT */

#ifdef SB_USE_CLASS_TELJSONOBJECT
SB_INLINE TElJsonObjectHandle TElJsonArray::GetObjectIfExists(int32_t Index)
{
	TElJsonObjectHandle OutResult;
	SBCheckError(TElJsonArray_GetObjectIfExists(_Handle, Index, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELJSONOBJECT */

void TElJsonArray::GetStringValue(int32_t Index, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElJsonArray_GetStringValue(_Handle, Index, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1166726195, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElJsonArray::GetStringValue(int32_t Index, const std::string &Default, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElJsonArray_GetStringValue_1(_Handle, Index, Default.data(), (int32_t)Default.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1190904774, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElJsonArray::Insert(int32_t Index, TElJsonEntity &Value)
{
	SBCheckError(TElJsonArray_Insert(_Handle, Index, Value.getHandle()));
}

SB_INLINE void TElJsonArray::Insert(int32_t Index, TElJsonEntity *Value)
{
	SBCheckError(TElJsonArray_Insert(_Handle, Index, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElJsonArray::Insert(int32_t Index, int32_t Value)
{
	SBCheckError(TElJsonArray_Insert_1(_Handle, Index, Value));
}

SB_INLINE void TElJsonArray::Insert(int32_t Index, double Value)
{
	SBCheckError(TElJsonArray_Insert_2(_Handle, Index, Value));
}

SB_INLINE void TElJsonArray::Insert(int32_t Index, bool Value)
{
	SBCheckError(TElJsonArray_Insert_3(_Handle, Index, (int8_t)Value));
}

SB_INLINE void TElJsonArray::Insert(int32_t Index, const std::string &Value)
{
	SBCheckError(TElJsonArray_Insert_4(_Handle, Index, Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElJsonArray::Insert(int32_t Index)
{
	SBCheckError(TElJsonArray_Insert_5(_Handle, Index));
}

bool TElJsonArray::IsNullValue(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElJsonArray_IsNullValue(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElJsonArray::SetBooleanValue(int32_t Index, bool Value)
{
	SBCheckError(TElJsonArray_SetBooleanValue(_Handle, Index, (int8_t)Value));
}

SB_INLINE void TElJsonArray::SetDoubleValue(int32_t Index, double Value)
{
	SBCheckError(TElJsonArray_SetDoubleValue(_Handle, Index, Value));
}

SB_INLINE void TElJsonArray::SetIntegerValue(int32_t Index, int64_t Value)
{
	SBCheckError(TElJsonArray_SetIntegerValue(_Handle, Index, Value));
}

SB_INLINE void TElJsonArray::SetNullValue(int32_t Index)
{
	SBCheckError(TElJsonArray_SetNullValue(_Handle, Index));
}

SB_INLINE void TElJsonArray::SetStringValue(int32_t Index, const std::string &Value)
{
	SBCheckError(TElJsonArray_SetStringValue(_Handle, Index, Value.data(), (int32_t)Value.length()));
}

TElJsonEntity* TElJsonArray::get_Item(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElJsonArray_get_Item(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Item)
		this->_Inst_Item = new TElJsonEntity(hOutResult, ohFalse);
	else
		this->_Inst_Item->updateHandle(hOutResult);
	return this->_Inst_Item;
}

SB_INLINE void TElJsonArray::set_Item(int32_t Index, const TElJsonEntity &Value)
{
	SBCheckError(TElJsonArray_set_Item(_Handle, Index, Value.getHandle()));
}

SB_INLINE void TElJsonArray::set_Item(int32_t Index, const TElJsonEntity *Value)
{
	SBCheckError(TElJsonArray_set_Item(_Handle, Index, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElJsonArray::get_Length()
{
	int32_t OutResult;
	SBCheckError(TElJsonArray_get_Length(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElJsonArray::set_Length(int32_t Value)
{
	SBCheckError(TElJsonArray_set_Length(_Handle, Value));
}

bool TElJsonArray::get_OwnsItems()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElJsonArray_get_OwnsItems(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElJsonArray::initInstances()
{
	this->_Inst_Item = NULL;
}

TElJsonArray::TElJsonArray(TElJsonArrayHandle handle, TElOwnHandle ownHandle) : TElJsonEntity(handle, ownHandle)
{
	initInstances();
}

TElJsonArray::TElJsonArray(bool OwnsItems) : TElJsonEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElJsonArray_Create((int8_t)OwnsItems, &_Handle));
}

TElJsonArray::TElJsonArray(TElJsonArray &Original) : TElJsonEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElJsonArray_Create_1(Original.getHandle(), &_Handle));
}

TElJsonArray::TElJsonArray(TElJsonArray *Original) : TElJsonEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElJsonArray_Create_1((Original != NULL) ? Original->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElJsonArray::~TElJsonArray()
{
	delete this->_Inst_Item;
	this->_Inst_Item = NULL;
}
#endif /* SB_USE_CLASS_TELJSONARRAY */

#ifdef SB_USE_CLASS_TELJSONOBJECT

SB_INLINE void TElJsonObject::Assign(TPersistent &Source)
{
	SBCheckError(TElJsonObject_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElJsonObject::Assign(TPersistent *Source)
{
	SBCheckError(TElJsonObject_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElJsonEntityHandle TElJsonObject::Clone()
{
	TElJsonEntityHandle OutResult;
	SBCheckError(TElJsonObject_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElJsonObject::Clear()
{
	SBCheckError(TElJsonObject_Clear(_Handle));
}

SB_INLINE void TElJsonObject::Delete(int32_t Index)
{
	SBCheckError(TElJsonObject_Delete(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELJSONARRAY
SB_INLINE TElJsonArrayHandle TElJsonObject::GetArray(const std::string &Name)
{
	TElJsonArrayHandle OutResult;
	SBCheckError(TElJsonObject_GetArray(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELJSONARRAY */

#ifdef SB_USE_CLASS_TELJSONARRAY
SB_INLINE TElJsonArrayHandle TElJsonObject::GetArrayIfExists(const std::string &Name)
{
	TElJsonArrayHandle OutResult;
	SBCheckError(TElJsonObject_GetArrayIfExists(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELJSONARRAY */

bool TElJsonObject::GetBooleanValue(const std::string &Name)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElJsonObject_GetBooleanValue(_Handle, Name.data(), (int32_t)Name.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElJsonObject::GetBooleanValue(const std::string &Name, bool Default)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElJsonObject_GetBooleanValue_1(_Handle, Name.data(), (int32_t)Name.length(), (int8_t)Default, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE double TElJsonObject::GetDoubleValue(const std::string &Name)
{
	double OutResult;
	SBCheckError(TElJsonObject_GetDoubleValue(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}

SB_INLINE double TElJsonObject::GetDoubleValue(const std::string &Name, double Default)
{
	double OutResult;
	SBCheckError(TElJsonObject_GetDoubleValue_1(_Handle, Name.data(), (int32_t)Name.length(), Default, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElJsonObject::GetIntegerValue(const std::string &Name)
{
	int64_t OutResult;
	SBCheckError(TElJsonObject_GetIntegerValue(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElJsonObject::GetIntegerValue(const std::string &Name, int64_t Default)
{
	int64_t OutResult;
	SBCheckError(TElJsonObject_GetIntegerValue_1(_Handle, Name.data(), (int32_t)Name.length(), Default, &OutResult));
	return OutResult;
}

SB_INLINE TElJsonObjectHandle TElJsonObject::GetObject(const std::string &Name)
{
	TElJsonObjectHandle OutResult;
	SBCheckError(TElJsonObject_GetObject(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElJsonObjectHandle TElJsonObject::GetObjectIfExists(const std::string &Name)
{
	TElJsonObjectHandle OutResult;
	SBCheckError(TElJsonObject_GetObjectIfExists(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}

void TElJsonObject::GetStringValue(const std::string &Name, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElJsonObject_GetStringValue(_Handle, Name.data(), (int32_t)Name.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1670015003, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElJsonObject::GetStringValue(const std::string &Name, const std::string &Default, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElJsonObject_GetStringValue_1(_Handle, Name.data(), (int32_t)Name.length(), Default.data(), (int32_t)Default.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-780686030, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TElJsonEntityHandle TElJsonObject::GetValueIfExists(const std::string &Name)
{
	TElJsonEntityHandle OutResult;
	SBCheckError(TElJsonObject_GetValueIfExists(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElJsonObject::IndexOf(const std::string &Name)
{
	int32_t OutResult;
	SBCheckError(TElJsonObject_IndexOf(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}

bool TElJsonObject::IsNullValue(const std::string &Name)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElJsonObject_IsNullValue(_Handle, Name.data(), (int32_t)Name.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElJsonObject::Remove(const std::string &Name)
{
	int32_t OutResult;
	SBCheckError(TElJsonObject_Remove(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}

void TElJsonObject::NameAtIndex(int32_t Index, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElJsonObject_NameAtIndex(_Handle, Index, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-929865159, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TElJsonEntityHandle TElJsonObject::ValueAtIndex(int32_t Index)
{
	TElJsonEntityHandle OutResult;
	SBCheckError(TElJsonObject_ValueAtIndex(_Handle, Index, &OutResult));
	return OutResult;
}

bool TElJsonObject::ValueExists(const std::string &Name)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElJsonObject_ValueExists(_Handle, Name.data(), (int32_t)Name.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElJsonObject::SetBooleanValue(const std::string &Name, bool Value)
{
	SBCheckError(TElJsonObject_SetBooleanValue(_Handle, Name.data(), (int32_t)Name.length(), (int8_t)Value));
}

SB_INLINE void TElJsonObject::SetDoubleValue(const std::string &Name, double Value)
{
	SBCheckError(TElJsonObject_SetDoubleValue(_Handle, Name.data(), (int32_t)Name.length(), Value));
}

SB_INLINE void TElJsonObject::SetNullValue(const std::string &Name)
{
	SBCheckError(TElJsonObject_SetNullValue(_Handle, Name.data(), (int32_t)Name.length()));
}

SB_INLINE void TElJsonObject::SetIntegerValue(const std::string &Name, int64_t Value)
{
	SBCheckError(TElJsonObject_SetIntegerValue(_Handle, Name.data(), (int32_t)Name.length(), Value));
}

SB_INLINE void TElJsonObject::SetStringValue(const std::string &Name, const std::string &Value)
{
	SBCheckError(TElJsonObject_SetStringValue(_Handle, Name.data(), (int32_t)Name.length(), Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElJsonObject::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElJsonObject_get_Count(_Handle, &OutResult));
	return OutResult;
}

bool TElJsonObject::get_OwnsValues()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElJsonObject_get_OwnsValues(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TElJsonEntity* TElJsonObject::get_Value(const std::string &Name)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElJsonObject_get_Value(_Handle, Name.data(), (int32_t)Name.length(), &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Value)
		this->_Inst_Value = new TElJsonEntity(hOutResult, ohFalse);
	else
		this->_Inst_Value->updateHandle(hOutResult);
	return this->_Inst_Value;
}

SB_INLINE void TElJsonObject::set_Value(const std::string &Name, TElJsonEntity &AValue)
{
	SBCheckError(TElJsonObject_set_Value(_Handle, Name.data(), (int32_t)Name.length(), AValue.getHandle()));
}

SB_INLINE void TElJsonObject::set_Value(const std::string &Name, TElJsonEntity *AValue)
{
	SBCheckError(TElJsonObject_set_Value(_Handle, Name.data(), (int32_t)Name.length(), (AValue != NULL) ? AValue->getHandle() : SB_NULL_HANDLE));
}

void TElJsonObject::initInstances()
{
	this->_Inst_Value = NULL;
}

TElJsonObject::TElJsonObject(TElJsonObjectHandle handle, TElOwnHandle ownHandle) : TElJsonEntity(handle, ownHandle)
{
	initInstances();
}

TElJsonObject::TElJsonObject(bool OwnsValues) : TElJsonEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElJsonObject_Create((int8_t)OwnsValues, &_Handle));
}

TElJsonObject::TElJsonObject(TElJsonObject &Original) : TElJsonEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElJsonObject_Create_1(Original.getHandle(), &_Handle));
}

TElJsonObject::TElJsonObject(TElJsonObject *Original) : TElJsonEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElJsonObject_Create_1((Original != NULL) ? Original->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElJsonObject::~TElJsonObject()
{
	delete this->_Inst_Value;
	this->_Inst_Value = NULL;
}
#endif /* SB_USE_CLASS_TELJSONOBJECT */

#ifdef SB_USE_CLASS_TELJSONVALUE

SB_INLINE void TElJsonValue::Assign(TPersistent &Source)
{
	SBCheckError(TElJsonValue_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElJsonValue::Assign(TPersistent *Source)
{
	SBCheckError(TElJsonValue_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElJsonEntityHandle TElJsonValue::Clone()
{
	TElJsonEntityHandle OutResult;
	SBCheckError(TElJsonValue_Clone(_Handle, &OutResult));
	return OutResult;
}

bool TElJsonValue::get_AsBoolean()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElJsonValue_get_AsBoolean(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElJsonValue::set_AsBoolean(bool Value)
{
	SBCheckError(TElJsonValue_set_AsBoolean(_Handle, (int8_t)Value));
}

SB_INLINE int64_t TElJsonValue::get_AsInteger()
{
	int64_t OutResult;
	SBCheckError(TElJsonValue_get_AsInteger(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElJsonValue::set_AsInteger(int64_t Value)
{
	SBCheckError(TElJsonValue_set_AsInteger(_Handle, Value));
}

SB_INLINE double TElJsonValue::get_AsNumber()
{
	double OutResult;
	SBCheckError(TElJsonValue_get_AsNumber(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElJsonValue::set_AsNumber(double Value)
{
	SBCheckError(TElJsonValue_set_AsNumber(_Handle, Value));
}

void TElJsonValue::get_AsString(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElJsonValue_get_AsString(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(722361528, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElJsonValue::set_AsString(const std::string &Value)
{
	SBCheckError(TElJsonValue_set_AsString(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElJsonValue::get_IsBoolean()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElJsonValue_get_IsBoolean(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElJsonValue::get_IsNull()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElJsonValue_get_IsNull(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElJsonValue::set_IsNull(bool Value)
{
	SBCheckError(TElJsonValue_set_IsNull(_Handle, (int8_t)Value));
}

bool TElJsonValue::get_IsNumber()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElJsonValue_get_IsNumber(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElJsonValue::get_IsString()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElJsonValue_get_IsString(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElJsonValue::get_Value(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElJsonValue_get_Value(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1465167972, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBJsonType TElJsonValue::get_ValueType()
{
	TSBJsonTypeRaw OutResultRaw = 0;
	SBCheckError(TElJsonValue_get_ValueType(_Handle, &OutResultRaw));
	return (TSBJsonType)OutResultRaw;
}

TElJsonValue::TElJsonValue(TElJsonValueHandle handle, TElOwnHandle ownHandle) : TElJsonEntity(handle, ownHandle)
{
}

TElJsonValue::TElJsonValue() : TElJsonEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElJsonValue_Create(&_Handle));
}

TElJsonValue::TElJsonValue(TElJsonValue &Original) : TElJsonEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElJsonValue_Create_1(Original.getHandle(), &_Handle));
}

TElJsonValue::TElJsonValue(TElJsonValue *Original) : TElJsonEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElJsonValue_Create_1((Original != NULL) ? Original->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElJsonValue::TElJsonValue(bool Value) : TElJsonEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElJsonValue_Create_2((int8_t)Value, &_Handle));
}

TElJsonValue::TElJsonValue(double Value) : TElJsonEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElJsonValue_Create_3(Value, &_Handle));
}

TElJsonValue::TElJsonValue(int64_t Value) : TElJsonEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElJsonValue_Create_4(Value, &_Handle));
}

TElJsonValue::TElJsonValue(const std::string &Value) : TElJsonEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElJsonValue_Create_5(Value.data(), (int32_t)Value.length(), &_Handle));
}

#endif /* SB_USE_CLASS_TELJSONVALUE */

#ifdef SB_USE_GLOBAL_PROCS_JSON

#ifdef SB_USE_CLASS_TELJSONARRAY
SB_INLINE TElJsonArrayHandle NewArray()
{
	TElJsonArrayHandle OutResult;
	SBCheckError(SBJSON_NewArray(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELJSONARRAY */

#ifdef SB_USE_CLASS_TELJSONVALUE
SB_INLINE TElJsonValueHandle NewNull()
{
	TElJsonValueHandle OutResult;
	SBCheckError(SBJSON_NewNull(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELJSONVALUE */

#ifdef SB_USE_CLASS_TELJSONOBJECT
SB_INLINE TElJsonObjectHandle NewObject(bool OwnsValues)
{
	TElJsonObjectHandle OutResult;
	SBCheckError(SBJSON_NewObject((int8_t)OwnsValues, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELJSONOBJECT */

#ifdef SB_USE_CLASS_TELJSONVALUE
SB_INLINE TElJsonValueHandle NewValue(bool B)
{
	TElJsonValueHandle OutResult;
	SBCheckError(SBJSON_NewValue((int8_t)B, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELJSONVALUE */

#ifdef SB_USE_CLASS_TELJSONVALUE
SB_INLINE TElJsonValueHandle NewValue(double E)
{
	TElJsonValueHandle OutResult;
	SBCheckError(SBJSON_NewValue_1(E, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELJSONVALUE */

#ifdef SB_USE_CLASS_TELJSONVALUE
SB_INLINE TElJsonValueHandle NewValue(int64_t I)
{
	TElJsonValueHandle OutResult;
	SBCheckError(SBJSON_NewValue_2(I, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELJSONVALUE */

#ifdef SB_USE_CLASS_TELJSONVALUE
SB_INLINE TElJsonValueHandle NewValue(const std::string &S)
{
	TElJsonValueHandle OutResult;
	SBCheckError(SBJSON_NewValue_3(S.data(), (int32_t)S.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELJSONVALUE */

#ifdef SB_USE_CLASS_TELJSONENTITY
SB_INLINE TElJsonEntityHandle Read(const std::string &Text)
{
	TElJsonEntityHandle OutResult;
	SBCheckError(SBJSON_Read(Text.data(), (int32_t)Text.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELJSONENTITY */

#ifdef SB_USE_CLASS_TELJSONENTITY
SB_INLINE TElJsonEntityHandle Read(const std::vector<uint8_t> &Buffer)
{
	TElJsonEntityHandle OutResult;
	SBCheckError(SBJSON_Read_1(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELJSONENTITY */

#ifdef SB_USE_CLASS_TELJSONENTITY
SB_INLINE TElJsonEntityHandle Read(const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Length)
{
	TElJsonEntityHandle OutResult;
	SBCheckError(SBJSON_Read_2(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), StartIndex, Length, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELJSONENTITY */

#ifdef SB_USE_CLASS_TELJSONENTITY
void Write(TElJsonEntity &Entity, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBJSON_Write(Entity.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1306413420, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void Write(TElJsonEntity *Entity, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBJSON_Write((Entity != NULL) ? Entity->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1306413420, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELJSONENTITY */

#ifdef SB_USE_CLASS_TELJSONENTITY
void Write(TElJsonEntity &Entity, char IndentChar, int32_t CharsPerIndentLevel, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBJSON_Write_1(Entity.getHandle(), IndentChar, CharsPerIndentLevel, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(951428880, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void Write(TElJsonEntity *Entity, char IndentChar, int32_t CharsPerIndentLevel, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBJSON_Write_1((Entity != NULL) ? Entity->getHandle() : SB_NULL_HANDLE, IndentChar, CharsPerIndentLevel, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(951428880, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELJSONENTITY */

#ifdef SB_USE_CLASS_TELJSONENTITY
int32_t Write(TElJsonEntity &Entity, std::vector<uint8_t> &Buffer, int32_t StartIndex)
{
	int32_t OutResult;
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBJSON_Write_2(Entity.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, StartIndex, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-1088547202, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
	return OutResult;
}
int32_t Write(TElJsonEntity *Entity, std::vector<uint8_t> &Buffer, int32_t StartIndex)
{
	int32_t OutResult;
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBJSON_Write_2((Entity != NULL) ? Entity->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, StartIndex, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-1088547202, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELJSONENTITY */

#ifdef SB_USE_CLASS_TELJSONENTITY
int32_t Write(TElJsonEntity &Entity, char IndentChar, int32_t CharsPerIndentLevel, std::vector<uint8_t> &Buffer, int32_t StartIndex)
{
	int32_t OutResult;
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBJSON_Write_3(Entity.getHandle(), IndentChar, CharsPerIndentLevel, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, StartIndex, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-562286490, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
	return OutResult;
}
int32_t Write(TElJsonEntity *Entity, char IndentChar, int32_t CharsPerIndentLevel, std::vector<uint8_t> &Buffer, int32_t StartIndex)
{
	int32_t OutResult;
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBJSON_Write_3((Entity != NULL) ? Entity->getHandle() : SB_NULL_HANDLE, IndentChar, CharsPerIndentLevel, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, StartIndex, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-562286490, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELJSONENTITY */

#ifdef SB_USE_CLASSES_TELJSONENTITY_AND_TSTREAM
SB_INLINE int32_t Write(TElJsonEntity &Entity, TStream &Stream)
{
	int32_t OutResult;
	SBCheckError(SBJSON_Write_4(Entity.getHandle(), Stream.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE int32_t Write(TElJsonEntity *Entity, TStream *Stream)
{
	int32_t OutResult;
	SBCheckError(SBJSON_Write_4((Entity != NULL) ? Entity->getHandle() : SB_NULL_HANDLE, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELJSONENTITY_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELJSONENTITY_AND_TSTREAM
SB_INLINE int32_t Write(TElJsonEntity &Entity, char IndentChar, int32_t CharsPerIndentLevel, TStream &Stream)
{
	int32_t OutResult;
	SBCheckError(SBJSON_Write_5(Entity.getHandle(), IndentChar, CharsPerIndentLevel, Stream.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE int32_t Write(TElJsonEntity *Entity, char IndentChar, int32_t CharsPerIndentLevel, TStream *Stream)
{
	int32_t OutResult;
	SBCheckError(SBJSON_Write_5((Entity != NULL) ? Entity->getHandle() : SB_NULL_HANDLE, IndentChar, CharsPerIndentLevel, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELJSONENTITY_AND_TSTREAM */

#endif /* SB_USE_GLOBAL_PROCS_JSON */

};	/* namespace SecureBlackbox */

