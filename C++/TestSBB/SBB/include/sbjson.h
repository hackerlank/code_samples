#ifndef __INC_SBJSON
#define __INC_SBJSON

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstreams.h"
#include "sbstringlist.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElJsonValueHandle;

typedef TElClassHandle TElJsonArrayHandle;

typedef TElClassHandle TElJsonObjectHandle;

typedef TElClassHandle TElJsonEntityHandle;

typedef uint8_t TSBJsonTypeRaw;

typedef enum
{
	jsonNull = 0,
	jsonBoolean = 1,
	jsonString = 2,
	jsonNumber = 3
} TSBJsonType;

#ifdef SB_USE_CLASS_TELJSONENTITY
SB_IMPORT uint32_t SB_APIENTRY TElJsonEntity_Assign(TElJsonEntityHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElJsonEntity_Clone(TElJsonEntityHandle _Handle, TElJsonEntityHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonEntity_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELJSONENTITY */

#ifdef SB_USE_CLASS_TELJSONARRAY
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_Assign(TElJsonArrayHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_Clone(TElJsonArrayHandle _Handle, TElJsonEntityHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_Append(TElJsonArrayHandle _Handle, TElJsonEntityHandle Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_Append_1(TElJsonArrayHandle _Handle, int32_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_Append_2(TElJsonArrayHandle _Handle, double Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_Append_3(TElJsonArrayHandle _Handle, int8_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_Append_4(TElJsonArrayHandle _Handle, const char * pcValue, int32_t szValue, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_Append_5(TElJsonArrayHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_Clear(TElJsonArrayHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_Delete(TElJsonArrayHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_GetArray(TElJsonArrayHandle _Handle, int32_t Index, TElJsonArrayHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_GetArrayIfExists(TElJsonArrayHandle _Handle, int32_t Index, TElJsonArrayHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_GetBooleanValue(TElJsonArrayHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_GetBooleanValue_1(TElJsonArrayHandle _Handle, int32_t Index, int8_t Default, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_GetDoubleValue(TElJsonArrayHandle _Handle, int32_t Index, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_GetDoubleValue_1(TElJsonArrayHandle _Handle, int32_t Index, double Default, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_GetIntegerValue(TElJsonArrayHandle _Handle, int32_t Index, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_GetIntegerValue_1(TElJsonArrayHandle _Handle, int32_t Index, int64_t Default, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_GetObject(TElJsonArrayHandle _Handle, int32_t Index, TElJsonObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_GetObjectIfExists(TElJsonArrayHandle _Handle, int32_t Index, TElJsonObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_GetStringValue(TElJsonArrayHandle _Handle, int32_t Index, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_GetStringValue_1(TElJsonArrayHandle _Handle, int32_t Index, const char * pcDefault, int32_t szDefault, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_Insert(TElJsonArrayHandle _Handle, int32_t Index, TElJsonEntityHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_Insert_1(TElJsonArrayHandle _Handle, int32_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_Insert_2(TElJsonArrayHandle _Handle, int32_t Index, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_Insert_3(TElJsonArrayHandle _Handle, int32_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_Insert_4(TElJsonArrayHandle _Handle, int32_t Index, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_Insert_5(TElJsonArrayHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_IsNullValue(TElJsonArrayHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_SetBooleanValue(TElJsonArrayHandle _Handle, int32_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_SetDoubleValue(TElJsonArrayHandle _Handle, int32_t Index, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_SetIntegerValue(TElJsonArrayHandle _Handle, int32_t Index, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_SetNullValue(TElJsonArrayHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_SetStringValue(TElJsonArrayHandle _Handle, int32_t Index, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_get_Item(TElJsonArrayHandle _Handle, int32_t Index, TElJsonEntityHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_set_Item(TElJsonArrayHandle _Handle, int32_t Index, const TElJsonEntityHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_get_Length(TElJsonArrayHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_set_Length(TElJsonArrayHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_get_OwnsItems(TElJsonArrayHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_Create(int8_t OwnsItems, TElJsonArrayHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonArray_Create_1(TElJsonArrayHandle Original, TElJsonArrayHandle * OutResult);
#endif /* SB_USE_CLASS_TELJSONARRAY */

#ifdef SB_USE_CLASS_TELJSONOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_Assign(TElJsonObjectHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_Clone(TElJsonObjectHandle _Handle, TElJsonEntityHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_Clear(TElJsonObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_Delete(TElJsonObjectHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_GetArray(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName, TElJsonArrayHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_GetArrayIfExists(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName, TElJsonArrayHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_GetBooleanValue(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_GetBooleanValue_1(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName, int8_t Default, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_GetDoubleValue(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_GetDoubleValue_1(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName, double Default, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_GetIntegerValue(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_GetIntegerValue_1(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName, int64_t Default, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_GetObject(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName, TElJsonObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_GetObjectIfExists(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName, TElJsonObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_GetStringValue(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_GetStringValue_1(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName, const char * pcDefault, int32_t szDefault, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_GetValueIfExists(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName, TElJsonEntityHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_IndexOf(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_IsNullValue(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_Remove(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_NameAtIndex(TElJsonObjectHandle _Handle, int32_t Index, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_ValueAtIndex(TElJsonObjectHandle _Handle, int32_t Index, TElJsonEntityHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_ValueExists(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_SetBooleanValue(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_SetDoubleValue(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_SetNullValue(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_SetIntegerValue(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_SetStringValue(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_get_Count(TElJsonObjectHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_get_OwnsValues(TElJsonObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_get_Value(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName, TElJsonEntityHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_set_Value(TElJsonObjectHandle _Handle, const char * pcName, int32_t szName, TElJsonEntityHandle AValue);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_Create(int8_t OwnsValues, TElJsonObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonObject_Create_1(TElJsonObjectHandle Original, TElJsonObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELJSONOBJECT */

#ifdef SB_USE_CLASS_TELJSONVALUE
SB_IMPORT uint32_t SB_APIENTRY TElJsonValue_Assign(TElJsonValueHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElJsonValue_Clone(TElJsonValueHandle _Handle, TElJsonEntityHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonValue_get_AsBoolean(TElJsonValueHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonValue_set_AsBoolean(TElJsonValueHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElJsonValue_get_AsInteger(TElJsonValueHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonValue_set_AsInteger(TElJsonValueHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElJsonValue_get_AsNumber(TElJsonValueHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonValue_set_AsNumber(TElJsonValueHandle _Handle, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElJsonValue_get_AsString(TElJsonValueHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonValue_set_AsString(TElJsonValueHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElJsonValue_get_IsBoolean(TElJsonValueHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonValue_get_IsNull(TElJsonValueHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonValue_set_IsNull(TElJsonValueHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElJsonValue_get_IsNumber(TElJsonValueHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonValue_get_IsString(TElJsonValueHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonValue_get_Value(TElJsonValueHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonValue_get_ValueType(TElJsonValueHandle _Handle, TSBJsonTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonValue_Create(TElJsonValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonValue_Create_1(TElJsonValueHandle Original, TElJsonValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonValue_Create_2(int8_t Value, TElJsonValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonValue_Create_3(double Value, TElJsonValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonValue_Create_4(int64_t Value, TElJsonValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJsonValue_Create_5(const char * pcValue, int32_t szValue, TElJsonValueHandle * OutResult);
#endif /* SB_USE_CLASS_TELJSONVALUE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElJsonValue;
class TElJsonArray;
class TElJsonObject;
class TElJsonEntity;

#ifdef SB_USE_CLASS_TELJSONENTITY
class TElJsonEntity: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElJsonEntity)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual TElJsonEntityHandle Clone();

		TElJsonEntity(TElJsonEntityHandle handle, TElOwnHandle ownHandle);

		TElJsonEntity();

};
#endif /* SB_USE_CLASS_TELJSONENTITY */

#ifdef SB_USE_CLASS_TELJSONARRAY
class TElJsonArray: public TElJsonEntity
{
	private:
		TElJsonEntity* _Inst_Item;

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual TElJsonEntityHandle Clone();

		int32_t Append(TElJsonEntity &Value);

		int32_t Append(TElJsonEntity *Value);

		int32_t Append(int32_t Value);

		int32_t Append(double Value);

		int32_t Append(bool Value);

		int32_t Append(const std::string &Value);

		int32_t Append();

		void Clear();

		void Delete(int32_t Index);

		TElJsonArrayHandle GetArray(int32_t Index);

		TElJsonArrayHandle GetArrayIfExists(int32_t Index);

		bool GetBooleanValue(int32_t Index);

		bool GetBooleanValue(int32_t Index, bool Default);

		double GetDoubleValue(int32_t Index);

		double GetDoubleValue(int32_t Index, double Default);

		int64_t GetIntegerValue(int32_t Index);

		int64_t GetIntegerValue(int32_t Index, int64_t Default);

#ifdef SB_USE_CLASS_TELJSONOBJECT
		TElJsonObjectHandle GetObject(int32_t Index);
#endif /* SB_USE_CLASS_TELJSONOBJECT */

#ifdef SB_USE_CLASS_TELJSONOBJECT
		TElJsonObjectHandle GetObjectIfExists(int32_t Index);
#endif /* SB_USE_CLASS_TELJSONOBJECT */

		void GetStringValue(int32_t Index, std::string &OutResult);

		void GetStringValue(int32_t Index, const std::string &Default, std::string &OutResult);

		void Insert(int32_t Index, TElJsonEntity &Value);

		void Insert(int32_t Index, TElJsonEntity *Value);

		void Insert(int32_t Index, int32_t Value);

		void Insert(int32_t Index, double Value);

		void Insert(int32_t Index, bool Value);

		void Insert(int32_t Index, const std::string &Value);

		void Insert(int32_t Index);

		bool IsNullValue(int32_t Index);

		void SetBooleanValue(int32_t Index, bool Value);

		void SetDoubleValue(int32_t Index, double Value);

		void SetIntegerValue(int32_t Index, int64_t Value);

		void SetNullValue(int32_t Index);

		void SetStringValue(int32_t Index, const std::string &Value);

		virtual TElJsonEntity* get_Item(int32_t Index);

		virtual void set_Item(int32_t Index, const TElJsonEntity &Value);

		virtual void set_Item(int32_t Index, const TElJsonEntity *Value);

		virtual int32_t get_Length();

		virtual void set_Length(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Length, set_Length, TElJsonArray, Length);

		virtual bool get_OwnsItems();

		SB_DECLARE_PROPERTY_GET(bool, get_OwnsItems, TElJsonArray, OwnsItems);

		TElJsonArray(TElJsonArrayHandle handle, TElOwnHandle ownHandle);

		explicit TElJsonArray(bool OwnsItems);

		explicit TElJsonArray(TElJsonArray &Original);

		explicit TElJsonArray(TElJsonArray *Original);

		virtual ~TElJsonArray();

};
#endif /* SB_USE_CLASS_TELJSONARRAY */

#ifdef SB_USE_CLASS_TELJSONOBJECT
class TElJsonObject: public TElJsonEntity
{
	private:
		TElJsonEntity* _Inst_Value;

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual TElJsonEntityHandle Clone();

		void Clear();

		void Delete(int32_t Index);

#ifdef SB_USE_CLASS_TELJSONARRAY
		TElJsonArrayHandle GetArray(const std::string &Name);
#endif /* SB_USE_CLASS_TELJSONARRAY */

#ifdef SB_USE_CLASS_TELJSONARRAY
		TElJsonArrayHandle GetArrayIfExists(const std::string &Name);
#endif /* SB_USE_CLASS_TELJSONARRAY */

		bool GetBooleanValue(const std::string &Name);

		bool GetBooleanValue(const std::string &Name, bool Default);

		double GetDoubleValue(const std::string &Name);

		double GetDoubleValue(const std::string &Name, double Default);

		int64_t GetIntegerValue(const std::string &Name);

		int64_t GetIntegerValue(const std::string &Name, int64_t Default);

		TElJsonObjectHandle GetObject(const std::string &Name);

		TElJsonObjectHandle GetObjectIfExists(const std::string &Name);

		void GetStringValue(const std::string &Name, std::string &OutResult);

		void GetStringValue(const std::string &Name, const std::string &Default, std::string &OutResult);

		TElJsonEntityHandle GetValueIfExists(const std::string &Name);

		int32_t IndexOf(const std::string &Name);

		bool IsNullValue(const std::string &Name);

		int32_t Remove(const std::string &Name);

		void NameAtIndex(int32_t Index, std::string &OutResult);

		TElJsonEntityHandle ValueAtIndex(int32_t Index);

		bool ValueExists(const std::string &Name);

		void SetBooleanValue(const std::string &Name, bool Value);

		void SetDoubleValue(const std::string &Name, double Value);

		void SetNullValue(const std::string &Name);

		void SetIntegerValue(const std::string &Name, int64_t Value);

		void SetStringValue(const std::string &Name, const std::string &Value);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElJsonObject, Count);

		virtual bool get_OwnsValues();

		SB_DECLARE_PROPERTY_GET(bool, get_OwnsValues, TElJsonObject, OwnsValues);

		virtual TElJsonEntity* get_Value(const std::string &Name);

		virtual void set_Value(const std::string &Name, TElJsonEntity &AValue);

		virtual void set_Value(const std::string &Name, TElJsonEntity *AValue);

		TElJsonObject(TElJsonObjectHandle handle, TElOwnHandle ownHandle);

		explicit TElJsonObject(bool OwnsValues);

		explicit TElJsonObject(TElJsonObject &Original);

		explicit TElJsonObject(TElJsonObject *Original);

		virtual ~TElJsonObject();

};
#endif /* SB_USE_CLASS_TELJSONOBJECT */

#ifdef SB_USE_CLASS_TELJSONVALUE
class TElJsonValue: public TElJsonEntity
{
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual TElJsonEntityHandle Clone();

		virtual bool get_AsBoolean();

		virtual void set_AsBoolean(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AsBoolean, set_AsBoolean, TElJsonValue, AsBoolean);

		virtual int64_t get_AsInteger();

		virtual void set_AsInteger(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_AsInteger, set_AsInteger, TElJsonValue, AsInteger);

		virtual double get_AsNumber();

		virtual void set_AsNumber(double Value);

		SB_DECLARE_PROPERTY(double, get_AsNumber, set_AsNumber, TElJsonValue, AsNumber);

		virtual void get_AsString(std::string &OutResult);

		virtual void set_AsString(const std::string &Value);

		virtual bool get_IsBoolean();

		SB_DECLARE_PROPERTY_GET(bool, get_IsBoolean, TElJsonValue, IsBoolean);

		virtual bool get_IsNull();

		virtual void set_IsNull(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IsNull, set_IsNull, TElJsonValue, IsNull);

		virtual bool get_IsNumber();

		SB_DECLARE_PROPERTY_GET(bool, get_IsNumber, TElJsonValue, IsNumber);

		virtual bool get_IsString();

		SB_DECLARE_PROPERTY_GET(bool, get_IsString, TElJsonValue, IsString);

		virtual void get_Value(std::string &OutResult);

		virtual TSBJsonType get_ValueType();

		SB_DECLARE_PROPERTY_GET(TSBJsonType, get_ValueType, TElJsonValue, ValueType);

		TElJsonValue(TElJsonValueHandle handle, TElOwnHandle ownHandle);

		TElJsonValue();

		explicit TElJsonValue(TElJsonValue &Original);

		explicit TElJsonValue(TElJsonValue *Original);

		explicit TElJsonValue(bool Value);

		explicit TElJsonValue(double Value);

		explicit TElJsonValue(int64_t Value);

		explicit TElJsonValue(const std::string &Value);

};
#endif /* SB_USE_CLASS_TELJSONVALUE */

#ifdef SB_USE_GLOBAL_PROCS_JSON

#ifdef SB_USE_CLASS_TELJSONARRAY
TElJsonArrayHandle NewArray();
#endif /* SB_USE_CLASS_TELJSONARRAY */

#ifdef SB_USE_CLASS_TELJSONVALUE
TElJsonValueHandle NewNull();
#endif /* SB_USE_CLASS_TELJSONVALUE */

#ifdef SB_USE_CLASS_TELJSONOBJECT
TElJsonObjectHandle NewObject(bool OwnsValues);
#endif /* SB_USE_CLASS_TELJSONOBJECT */

#ifdef SB_USE_CLASS_TELJSONVALUE
TElJsonValueHandle NewValue(bool B);
#endif /* SB_USE_CLASS_TELJSONVALUE */

#ifdef SB_USE_CLASS_TELJSONVALUE
TElJsonValueHandle NewValue(double E);
#endif /* SB_USE_CLASS_TELJSONVALUE */

#ifdef SB_USE_CLASS_TELJSONVALUE
TElJsonValueHandle NewValue(int64_t I);
#endif /* SB_USE_CLASS_TELJSONVALUE */

#ifdef SB_USE_CLASS_TELJSONVALUE
TElJsonValueHandle NewValue(const std::string &S);
#endif /* SB_USE_CLASS_TELJSONVALUE */

#ifdef SB_USE_CLASS_TELJSONENTITY
TElJsonEntityHandle Read(const std::string &Text);
#endif /* SB_USE_CLASS_TELJSONENTITY */

#ifdef SB_USE_CLASS_TELJSONENTITY
TElJsonEntityHandle Read(const std::vector<uint8_t> &Buffer);
#endif /* SB_USE_CLASS_TELJSONENTITY */

#ifdef SB_USE_CLASS_TELJSONENTITY
TElJsonEntityHandle Read(const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Length);
#endif /* SB_USE_CLASS_TELJSONENTITY */

#ifdef SB_USE_CLASS_TELJSONENTITY
void Write(TElJsonEntity &Entity, std::string &OutResult);
void Write(TElJsonEntity *Entity, std::string &OutResult);
#endif /* SB_USE_CLASS_TELJSONENTITY */

#ifdef SB_USE_CLASS_TELJSONENTITY
void Write(TElJsonEntity &Entity, char IndentChar, int32_t CharsPerIndentLevel, std::string &OutResult);
void Write(TElJsonEntity *Entity, char IndentChar, int32_t CharsPerIndentLevel, std::string &OutResult);
#endif /* SB_USE_CLASS_TELJSONENTITY */

#ifdef SB_USE_CLASS_TELJSONENTITY
int32_t Write(TElJsonEntity &Entity, std::vector<uint8_t> &Buffer, int32_t StartIndex);
int32_t Write(TElJsonEntity *Entity, std::vector<uint8_t> &Buffer, int32_t StartIndex);
#endif /* SB_USE_CLASS_TELJSONENTITY */

#ifdef SB_USE_CLASS_TELJSONENTITY
int32_t Write(TElJsonEntity &Entity, char IndentChar, int32_t CharsPerIndentLevel, std::vector<uint8_t> &Buffer, int32_t StartIndex);
int32_t Write(TElJsonEntity *Entity, char IndentChar, int32_t CharsPerIndentLevel, std::vector<uint8_t> &Buffer, int32_t StartIndex);
#endif /* SB_USE_CLASS_TELJSONENTITY */

#ifdef SB_USE_CLASSES_TELJSONENTITY_AND_TSTREAM
int32_t Write(TElJsonEntity &Entity, TStream &Stream);
int32_t Write(TElJsonEntity *Entity, TStream *Stream);
#endif /* SB_USE_CLASSES_TELJSONENTITY_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELJSONENTITY_AND_TSTREAM
int32_t Write(TElJsonEntity &Entity, char IndentChar, int32_t CharsPerIndentLevel, TStream &Stream);
int32_t Write(TElJsonEntity *Entity, char IndentChar, int32_t CharsPerIndentLevel, TStream *Stream);
#endif /* SB_USE_CLASSES_TELJSONENTITY_AND_TSTREAM */

#endif /* SB_USE_GLOBAL_PROCS_JSON */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_JSON
SB_IMPORT uint32_t SB_APIENTRY SBJSON_NewArray(TElJsonArrayHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBJSON_NewNull(TElJsonValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBJSON_NewObject(int8_t OwnsValues, TElJsonObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBJSON_NewValue(int8_t B, TElJsonValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBJSON_NewValue_1(double E, TElJsonValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBJSON_NewValue_2(int64_t I, TElJsonValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBJSON_NewValue_3(const char * pcS, int32_t szS, TElJsonValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBJSON_Read(const char * pcText, int32_t szText, TElJsonEntityHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBJSON_Read_1(const uint8_t pBuffer[], int32_t szBuffer, TElJsonEntityHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBJSON_Read_2(const uint8_t pBuffer[], int32_t szBuffer, int32_t StartIndex, int32_t Length, TElJsonEntityHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBJSON_Write(TElJsonEntityHandle Entity, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBJSON_Write_1(TElJsonEntityHandle Entity, char IndentChar, int32_t CharsPerIndentLevel, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBJSON_Write_2(TElJsonEntityHandle Entity, uint8_t pBuffer[], int32_t * szBuffer, int32_t StartIndex, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBJSON_Write_3(TElJsonEntityHandle Entity, char IndentChar, int32_t CharsPerIndentLevel, uint8_t pBuffer[], int32_t * szBuffer, int32_t StartIndex, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBJSON_Write_4(TElJsonEntityHandle Entity, TStreamHandle Stream, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBJSON_Write_5(TElJsonEntityHandle Entity, char IndentChar, int32_t CharsPerIndentLevel, TStreamHandle Stream, int32_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_JSON */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBJSON */

