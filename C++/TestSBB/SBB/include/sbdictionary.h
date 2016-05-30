#ifndef __INC_SBDICTIONARY
#define __INC_SBDICTIONARY

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbtypes.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElDictionaryEntryHandle;

typedef TElClassHandle TElDictionaryHandle;

typedef void (SB_CALLBACK *TSBDictionaryDeleteValueEvent)(void * _ObjectData, TObjectHandle Sender, TObjectHandle Value);

#ifdef SB_USE_CLASS_TELDICTIONARYENTRY
SB_IMPORT uint32_t SB_APIENTRY TElDictionaryEntry_get_HashCode(TElDictionaryEntryHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionaryEntry_set_HashCode(TElDictionaryEntryHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDictionaryEntry_get_Next(TElDictionaryEntryHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionaryEntry_set_Next(TElDictionaryEntryHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDictionaryEntry_get_Value(TElDictionaryEntryHandle _Handle, TObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionaryEntry_set_Value(TElDictionaryEntryHandle _Handle, TObjectHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElDictionaryEntry_get_StrKey(TElDictionaryEntryHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionaryEntry_set_StrKey(TElDictionaryEntryHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDictionaryEntry_get_ByteKey(TElDictionaryEntryHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionaryEntry_set_ByteKey(TElDictionaryEntryHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDictionaryEntry_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELDICTIONARYENTRY */

#ifdef SB_USE_CLASS_TELDICTIONARY
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_Clear(TElDictionaryHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_Add(TElDictionaryHandle _Handle, const char * pcKey, int32_t szKey, TObjectHandle Value, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_Add_1(TElDictionaryHandle _Handle, const uint8_t pKey[], int32_t szKey, TObjectHandle Value, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_ContainsKey(TElDictionaryHandle _Handle, const char * pcKey, int32_t szKey, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_ContainsKey_1(TElDictionaryHandle _Handle, const uint8_t pKey[], int32_t szKey, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_ContainsValue(TElDictionaryHandle _Handle, TObjectHandle Value, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_Remove(TElDictionaryHandle _Handle, const char * pcKey, int32_t szKey, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_Remove_1(TElDictionaryHandle _Handle, const uint8_t pKey[], int32_t szKey, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_Remove_2(TElDictionaryHandle _Handle, TObjectHandle Value, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_TryGetValue(TElDictionaryHandle _Handle, const char * pcKey, int32_t szKey, TObjectHandle * Value, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_TryGetValue_1(TElDictionaryHandle _Handle, const uint8_t pKey[], int32_t szKey, TObjectHandle * Value, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_GetItem(TElDictionaryHandle _Handle, const uint8_t pKey[], int32_t szKey, TObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_GetItem_1(TElDictionaryHandle _Handle, const char * pcKey, int32_t szKey, TObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_SetItem(TElDictionaryHandle _Handle, const uint8_t pKey[], int32_t szKey, TObjectHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_SetItem_1(TElDictionaryHandle _Handle, const char * pcKey, int32_t szKey, TObjectHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_get_Count(TElDictionaryHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_get_FreeCount(TElDictionaryHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_get_Values(TElDictionaryHandle _Handle, int32_t Index, TObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_get_StringKeys(TElDictionaryHandle _Handle, int32_t Index, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_get_ByteKeys(TElDictionaryHandle _Handle, int32_t Index, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_get_OnDeleteValue(TElDictionaryHandle _Handle, TSBDictionaryDeleteValueEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_set_OnDeleteValue(TElDictionaryHandle _Handle, TSBDictionaryDeleteValueEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_Create(TElDictionaryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDictionary_Create_1(int32_t Capacity, TElDictionaryHandle * OutResult);
#endif /* SB_USE_CLASS_TELDICTIONARY */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElDictionaryEntry;
class TElDictionary;

#ifdef SB_USE_CLASS_TELDICTIONARYENTRY
class TElDictionaryEntry: public TObject
{
	private:
		SB_DISABLE_COPY(TElDictionaryEntry)
		TObject* _Inst_Value;

		void initInstances();

	public:
		virtual uint32_t get_HashCode();

		virtual void set_HashCode(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_HashCode, set_HashCode, TElDictionaryEntry, HashCode);

		virtual int32_t get_Next();

		virtual void set_Next(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Next, set_Next, TElDictionaryEntry, Next);

		virtual TObject* get_Value();

		virtual void set_Value(TObject &Value);

		virtual void set_Value(TObject *Value);

		SB_DECLARE_PROPERTY(TObject*, get_Value, set_Value, TElDictionaryEntry, Value);

		virtual void get_StrKey(std::string &OutResult);

		virtual void set_StrKey(const std::string &Value);

		virtual void get_ByteKey(std::vector<uint8_t> &OutResult);

		virtual void set_ByteKey(const std::vector<uint8_t> &Value);

		TElDictionaryEntry(TElDictionaryEntryHandle handle, TElOwnHandle ownHandle);

		TElDictionaryEntry();

		virtual ~TElDictionaryEntry();

};
#endif /* SB_USE_CLASS_TELDICTIONARYENTRY */

#ifdef SB_USE_CLASS_TELDICTIONARY
class TElDictionary: public TObject
{
	private:
		SB_DISABLE_COPY(TElDictionary)
		TObject* _Inst_Values;

		void initInstances();

	public:
		void Clear();

		bool Add(const std::string &Key, TObject &Value);

		bool Add(const std::string &Key, TObject *Value);

		bool Add(const std::vector<uint8_t> &Key, TObject &Value);

		bool Add(const std::vector<uint8_t> &Key, TObject *Value);

		bool ContainsKey(const std::string &Key);

		bool ContainsKey(const std::vector<uint8_t> &Key);

		bool ContainsValue(TObject &Value);

		bool ContainsValue(TObject *Value);

		bool Remove(const std::string &Key);

		bool Remove(const std::vector<uint8_t> &Key);

		bool Remove(TObject &Value);

		bool Remove(TObject *Value);

		bool TryGetValue(const std::string &Key, TObject &Value);

		bool TryGetValue(const std::vector<uint8_t> &Key, TObject &Value);

		TObjectHandle GetItem(const std::vector<uint8_t> &Key);

		TObjectHandle GetItem(const std::string &Key);

		void SetItem(const std::vector<uint8_t> &Key, TObject &Value);

		void SetItem(const std::vector<uint8_t> &Key, TObject *Value);

		void SetItem(const std::string &Key, TObject &Value);

		void SetItem(const std::string &Key, TObject *Value);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElDictionary, Count);

		virtual int32_t get_FreeCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_FreeCount, TElDictionary, FreeCount);

		virtual TObject* get_Values(int32_t Index);

		virtual void get_StringKeys(int32_t Index, std::string &OutResult);

		virtual void get_ByteKeys(int32_t Index, std::vector<uint8_t> &OutResult);

		virtual void get_OnDeleteValue(TSBDictionaryDeleteValueEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDeleteValue(TSBDictionaryDeleteValueEvent pMethodValue, void * pDataValue);

		TElDictionary(TElDictionaryHandle handle, TElOwnHandle ownHandle);

		TElDictionary();

		explicit TElDictionary(int32_t Capacity);

		virtual ~TElDictionary();

};
#endif /* SB_USE_CLASS_TELDICTIONARY */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBDICTIONARY */

