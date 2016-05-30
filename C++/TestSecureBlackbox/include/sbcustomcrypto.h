#ifndef __INC_SBCUSTOMCRYPTO
#define __INC_SBCUSTOMCRYPTO

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbcryptoprov.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbstrutils.h"
#include "sbsharedresource.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElKeyMaterialHandle;

typedef TElKeyMaterialHandle ElKeyMaterialHandle;

typedef TElClassHandle TElCustomCryptoHandle;

typedef TElCustomCryptoHandle ElCustomCryptoHandle;

typedef TElClassHandle TElKeyMaterialStorageHandle;

typedef TElKeyMaterialStorageHandle ElKeyMaterialStorageHandle;

#ifdef SB_USE_CLASS_TELKEYMATERIAL
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterial_Generate(TElKeyMaterialHandle _Handle, int32_t Bits);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterial_Save(TElKeyMaterialHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterial_Load(TElKeyMaterialHandle _Handle, TStreamHandle Stream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterial_Assign(TElKeyMaterialHandle _Handle, TElKeyMaterialHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterial_Equals(TElKeyMaterialHandle _Handle, TElKeyMaterialHandle Source, int8_t PublicOnly, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterial_Clone(TElKeyMaterialHandle _Handle, TElKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterial_AssignCryptoKey(TElKeyMaterialHandle _Handle, TElCustomCryptoKeyHandle Key);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterial_Persistentiate(TElKeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterial_get_Exportable(TElKeyMaterialHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterial_get_Valid(TElKeyMaterialHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterial_get_Bits(TElKeyMaterialHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterial_get_Key(TElKeyMaterialHandle _Handle, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterial_get_Algorithm(TElKeyMaterialHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterial_get_KeyID(TElKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterial_set_KeyID(TElKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterial_get_KeySubject(TElKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterial_set_KeySubject(TElKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterial_get_ProviderName(TElKeyMaterialHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterial_set_ProviderName(TElKeyMaterialHandle _Handle, const char * pcValue, int32_t szValue);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterial_Create(TElKeyMaterialHandle * OutResult);
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElCustomCrypto_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTO */

#ifdef SB_USE_CLASS_TELKEYMATERIALSTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterialStorage_Clear(TElKeyMaterialStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterialStorage_ImportFrom(TElKeyMaterialStorageHandle _Handle, TElKeyMaterialStorageHandle KeyStorage);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterialStorage_Add(TElKeyMaterialStorageHandle _Handle, TElKeyMaterialHandle Key);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterialStorage_Remove(TElKeyMaterialStorageHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterialStorage_get_KeyList(TElKeyMaterialStorageHandle _Handle, TSBObjectListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterialStorage_get_Count(TElKeyMaterialStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterialStorage_get_Keys(TElKeyMaterialStorageHandle _Handle, int32_t Index, TElKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElKeyMaterialStorage_Create(TComponentHandle Owner, TElKeyMaterialStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELKEYMATERIALSTORAGE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElKeyMaterial;
typedef TElKeyMaterial ElKeyMaterial;
class TElCustomCrypto;
typedef TElCustomCrypto ElCustomCrypto;
class TElKeyMaterialStorage;
typedef TElKeyMaterialStorage ElKeyMaterialStorage;

#ifdef SB_USE_CLASS_TELKEYMATERIAL
class TElKeyMaterial: public TObject
{
	private:
		SB_DISABLE_COPY(TElKeyMaterial)
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
		TElCustomCryptoKey* _Inst_Key;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

		void initInstances();

	public:
		virtual void Generate(int32_t Bits);

#ifdef SB_USE_CLASS_TSTREAM
		virtual void Save(TStream &Stream);

		virtual void Save(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		virtual void Load(TStream &Stream, int32_t Count);

		virtual void Load(TStream *Stream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void Assign(TElKeyMaterial &Source);

		virtual void Assign(TElKeyMaterial *Source);

		virtual bool Equals(TElKeyMaterial &Source, bool PublicOnly);

		virtual bool Equals(TElKeyMaterial *Source, bool PublicOnly);

		virtual TElKeyMaterialHandle Clone();

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
		virtual void AssignCryptoKey(TElCustomCryptoKey &Key);

		virtual void AssignCryptoKey(TElCustomCryptoKey *Key);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

		virtual void Persistentiate();

		virtual bool get_Exportable();

		SB_DECLARE_PROPERTY_GET(bool, get_Exportable, TElKeyMaterial, Exportable);

		virtual bool get_Valid();

		SB_DECLARE_PROPERTY_GET(bool, get_Valid, TElKeyMaterial, Valid);

		virtual int32_t get_Bits();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Bits, TElKeyMaterial, Bits);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
		virtual TElCustomCryptoKey* get_Key();

		SB_DECLARE_PROPERTY_GET(TElCustomCryptoKey*, get_Key, TElKeyMaterial, Key);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

		virtual int32_t get_Algorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Algorithm, TElKeyMaterial, Algorithm);

		virtual void get_KeyID(std::vector<uint8_t> &OutResult);

		virtual void set_KeyID(const std::vector<uint8_t> &Value);

		virtual void get_KeySubject(std::vector<uint8_t> &OutResult);

		virtual void set_KeySubject(const std::vector<uint8_t> &Value);

#ifdef SB_WINDOWS
		virtual void get_ProviderName(std::string &OutResult);

		virtual void set_ProviderName(const std::string &Value);
#endif

		TElKeyMaterial(TElKeyMaterialHandle handle, TElOwnHandle ownHandle);

		TElKeyMaterial();

		virtual ~TElKeyMaterial();

};
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTO
class TElCustomCrypto: public TObject
{
	private:
		SB_DISABLE_COPY(TElCustomCrypto)
	public:
		TElCustomCrypto(TElCustomCryptoHandle handle, TElOwnHandle ownHandle);

		TElCustomCrypto();

};
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTO */

#ifdef SB_USE_CLASS_TELKEYMATERIALSTORAGE
class TElKeyMaterialStorage: public TComponent
{
	private:
		SB_DISABLE_COPY(TElKeyMaterialStorage)
#ifdef SB_USE_CLASS_TSBOBJECTLIST
		TSBObjectList* _Inst_KeyList;
#endif /* SB_USE_CLASS_TSBOBJECTLIST */
#ifdef SB_USE_CLASS_TELKEYMATERIAL
		TElKeyMaterial* _Inst_Keys;
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

		void initInstances();

	public:
		void Clear();

		void ImportFrom(TElKeyMaterialStorage &KeyStorage);

		void ImportFrom(TElKeyMaterialStorage *KeyStorage);

#ifdef SB_USE_CLASS_TELKEYMATERIAL
		void Add(TElKeyMaterial &Key);

		void Add(TElKeyMaterial *Key);
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

		void Remove(int32_t Index);

#ifdef SB_USE_CLASS_TSBOBJECTLIST
		virtual TSBObjectList* get_KeyList();

		SB_DECLARE_PROPERTY_GET(TSBObjectList*, get_KeyList, TElKeyMaterialStorage, KeyList);
#endif /* SB_USE_CLASS_TSBOBJECTLIST */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElKeyMaterialStorage, Count);

#ifdef SB_USE_CLASS_TELKEYMATERIAL
		virtual TElKeyMaterial* get_Keys(int32_t Index);
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

		TElKeyMaterialStorage(TElKeyMaterialStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElKeyMaterialStorage(TComponent &Owner);

		explicit TElKeyMaterialStorage(TComponent *Owner);

		virtual ~TElKeyMaterialStorage();

};
#endif /* SB_USE_CLASS_TELKEYMATERIALSTORAGE */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCUSTOMCRYPTO */
