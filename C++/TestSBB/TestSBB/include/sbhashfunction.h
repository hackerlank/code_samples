#ifndef __INC_SBHASHFUNCTION
#define __INC_SBHASHFUNCTION

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbcryptoprov.h"
#include "sbcustomcrypto.h"
#include "sbmd.h"
#include "sbrdn.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElHMACKeyMaterialHandle;

typedef TElHMACKeyMaterialHandle ElHMACKeyMaterialHandle;

typedef TElClassHandle TElHashFunctionHandle;

typedef TElHashFunctionHandle ElHashFunctionHandle;

#ifdef SB_USE_CLASS_TELHMACKEYMATERIAL
SB_IMPORT uint32_t SB_APIENTRY TElHMACKeyMaterial_get_Key_ByteArray(TElHMACKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHMACKeyMaterial_set_Key_ByteArray(TElHMACKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHMACKeyMaterial_get_Nonce(TElHMACKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHMACKeyMaterial_set_Nonce(TElHMACKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHMACKeyMaterial_get_CryptoProvider(TElHMACKeyMaterialHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHMACKeyMaterial_Create(TElCustomCryptoProviderHandle Prov, TElHMACKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHMACKeyMaterial_Create_1(TElCustomCryptoKeyHandle Key, TElCustomCryptoProviderHandle Prov, TElHMACKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHMACKeyMaterial_Create_2(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElHMACKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHMACKeyMaterial_Create_3(TElCustomCryptoKeyHandle Key, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElHMACKeyMaterialHandle * OutResult);
#endif /* SB_USE_CLASS_TELHMACKEYMATERIAL */

#ifdef SB_USE_CLASS_TELHASHFUNCTION
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Reset(TElHashFunctionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Update(TElHashFunctionHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Update_1(TElHashFunctionHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t StartIndex, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Update_2(TElHashFunctionHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_UpdateStream(TElHashFunctionHandle _Handle, TStreamHandle Stream, int64_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Finish(TElHashFunctionHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Clone(TElHashFunctionHandle _Handle, TElHashFunctionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_IsAlgorithmSupported(int32_t Algorithm, TElCustomCryptoProviderHandle CryptoProvider, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_IsAlgorithmSupported_1(TElHashFunctionHandle _Handle, int32_t Algorithm, TElCustomCryptoProviderHandle CryptoProvider, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_IsAlgorithmSupported_2(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderHandle CryptoProvider, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_IsAlgorithmSupported_3(TElHashFunctionHandle _Handle, const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderHandle CryptoProvider, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_IsAlgorithmSupported_4(int32_t Algorithm, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_IsAlgorithmSupported_5(TElHashFunctionHandle _Handle, int32_t Algorithm, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_IsAlgorithmSupported_6(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_IsAlgorithmSupported_7(TElHashFunctionHandle _Handle, const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_GetDigestSizeBits(int32_t Algorithm, TElCustomCryptoProviderHandle CryptoProvider, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_GetDigestSizeBits_1(TElHashFunctionHandle _Handle, int32_t Algorithm, TElCustomCryptoProviderHandle CryptoProvider, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_GetDigestSizeBits_2(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderHandle CryptoProvider, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_GetDigestSizeBits_3(TElHashFunctionHandle _Handle, const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderHandle CryptoProvider, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_GetDigestSizeBits_4(int32_t Algorithm, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_GetDigestSizeBits_5(TElHashFunctionHandle _Handle, int32_t Algorithm, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_GetDigestSizeBits_6(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_GetDigestSizeBits_7(TElHashFunctionHandle _Handle, const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Hash(int32_t Algorithm, void * Buffer, int32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Hash_1(TElHashFunctionHandle _Handle, int32_t Algorithm, void * Buffer, int32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Hash_2(int32_t Algorithm, TElHMACKeyMaterialHandle Key, void * Buffer, int32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Hash_3(TElHashFunctionHandle _Handle, int32_t Algorithm, TElHMACKeyMaterialHandle Key, void * Buffer, int32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_get_Algorithm(TElHashFunctionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_get_CryptoProvider(TElHashFunctionHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_set_CryptoProvider(TElHashFunctionHandle _Handle, TElCustomCryptoProviderHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_get_Key(TElHashFunctionHandle _Handle, TElHMACKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_set_Key(TElHashFunctionHandle _Handle, TElHMACKeyMaterialHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Create(int32_t Algorithm, TElCustomCryptoProviderHandle CryptoProvider, TElHashFunctionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Create_1(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderHandle CryptoProvider, TElHashFunctionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Create_2(int32_t Algorithm, TElRelativeDistinguishedNameHandle Parameters, TElCustomCryptoProviderHandle CryptoProvider, TElHashFunctionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Create_3(const uint8_t pOID[], int32_t szOID, TElRelativeDistinguishedNameHandle Parameters, TElCustomCryptoProviderHandle CryptoProvider, TElHashFunctionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Create_4(TElCustomCryptoProviderHandle CryptoProvider, TElHashFunctionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Create_5(int32_t Algorithm, TElHMACKeyMaterialHandle Key, TElHashFunctionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Create_6(const uint8_t pOID[], int32_t szOID, TElHMACKeyMaterialHandle Key, TElHashFunctionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Create_7(int32_t Algorithm, TElHMACKeyMaterialHandle Key, TElCustomCryptoProviderHandle CryptoProvider, TElHashFunctionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Create_8(const uint8_t pOID[], int32_t szOID, TElHMACKeyMaterialHandle Key, TElCustomCryptoProviderHandle CryptoProvider, TElHashFunctionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Create_9(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElHashFunctionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Create_10(int32_t Algorithm, TElRelativeDistinguishedNameHandle Parameters, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElHashFunctionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Create_11(const uint8_t pOID[], int32_t szOID, TElRelativeDistinguishedNameHandle Parameters, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElHashFunctionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Create_12(int32_t Algorithm, TElHMACKeyMaterialHandle Key, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElHashFunctionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHashFunction_Create_13(const uint8_t pOID[], int32_t szOID, TElHMACKeyMaterialHandle Key, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElHashFunctionHandle * OutResult);
#endif /* SB_USE_CLASS_TELHASHFUNCTION */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElHMACKeyMaterial;
typedef TElHMACKeyMaterial ElHMACKeyMaterial;
class TElHashFunction;
typedef TElHashFunction ElHashFunction;

#ifdef SB_USE_CLASS_TELHMACKEYMATERIAL
class TElHMACKeyMaterial: public TElKeyMaterial
{
	private:
		SB_DISABLE_COPY(TElHMACKeyMaterial)
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCustomCryptoProvider* _Inst_CryptoProvider;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		void initInstances();

	public:
		virtual void get_Key_ByteArray(std::vector<uint8_t> &OutResult);

		virtual void set_Key_ByteArray(const std::vector<uint8_t> &Value);

		virtual void get_Nonce(std::vector<uint8_t> &OutResult);

		virtual void set_Nonce(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		virtual TElCustomCryptoProvider* get_CryptoProvider();

		SB_DECLARE_PROPERTY_GET(TElCustomCryptoProvider*, get_CryptoProvider, TElHMACKeyMaterial, CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		TElHMACKeyMaterial(TElHMACKeyMaterialHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElHMACKeyMaterial(TElCustomCryptoProvider &Prov);

		explicit TElHMACKeyMaterial(TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER
		TElHMACKeyMaterial(TElCustomCryptoKey &Key, TElCustomCryptoProvider &Prov);

		TElHMACKeyMaterial(TElCustomCryptoKey *Key, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElHMACKeyMaterial(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElHMACKeyMaterial(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElHMACKeyMaterial(TElCustomCryptoKey &Key, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElHMACKeyMaterial(TElCustomCryptoKey *Key, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual ~TElHMACKeyMaterial();

};
#endif /* SB_USE_CLASS_TELHMACKEYMATERIAL */

#ifdef SB_USE_CLASS_TELHASHFUNCTION
class TElHashFunction: public TObject
{
	private:
		SB_DISABLE_COPY(TElHashFunction)
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCustomCryptoProvider* _Inst_CryptoProvider;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELHMACKEYMATERIAL
		TElHMACKeyMaterial* _Inst_Key;
#endif /* SB_USE_CLASS_TELHMACKEYMATERIAL */

		void initInstances();

	public:
		void Reset();

		void Update(void * Buffer, int32_t Size);

		void Update(const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Count);

		void Update(const std::vector<uint8_t> &Buffer);

#ifdef SB_USE_CLASS_TSTREAM
		void UpdateStream(TStream &Stream, int64_t Count);

		void UpdateStream(TStream *Stream, int64_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		void Finish(std::vector<uint8_t> &OutResult);

		TElHashFunctionHandle Clone();

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		static bool IsAlgorithmSupported(int32_t Algorithm, TElCustomCryptoProvider &CryptoProvider);

		static bool IsAlgorithmSupported(int32_t Algorithm, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		bool IsAlgorithmSupported_Inst(int32_t Algorithm, TElCustomCryptoProvider &CryptoProvider);

		bool IsAlgorithmSupported_Inst(int32_t Algorithm, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		static bool IsAlgorithmSupported(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider);

		static bool IsAlgorithmSupported(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		bool IsAlgorithmSupported_Inst(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider);

		bool IsAlgorithmSupported_Inst(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		static bool IsAlgorithmSupported(int32_t Algorithm, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		static bool IsAlgorithmSupported(int32_t Algorithm, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		bool IsAlgorithmSupported_Inst(int32_t Algorithm, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		bool IsAlgorithmSupported_Inst(int32_t Algorithm, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		static bool IsAlgorithmSupported(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		static bool IsAlgorithmSupported(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		bool IsAlgorithmSupported_Inst(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		bool IsAlgorithmSupported_Inst(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		static int32_t GetDigestSizeBits(int32_t Algorithm, TElCustomCryptoProvider &CryptoProvider);

		static int32_t GetDigestSizeBits(int32_t Algorithm, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		int32_t GetDigestSizeBits_Inst(int32_t Algorithm, TElCustomCryptoProvider &CryptoProvider);

		int32_t GetDigestSizeBits_Inst(int32_t Algorithm, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		static int32_t GetDigestSizeBits(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider);

		static int32_t GetDigestSizeBits(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		int32_t GetDigestSizeBits_Inst(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider);

		int32_t GetDigestSizeBits_Inst(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		static int32_t GetDigestSizeBits(int32_t Algorithm, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		static int32_t GetDigestSizeBits(int32_t Algorithm, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		int32_t GetDigestSizeBits_Inst(int32_t Algorithm, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		int32_t GetDigestSizeBits_Inst(int32_t Algorithm, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		static int32_t GetDigestSizeBits(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		static int32_t GetDigestSizeBits(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		int32_t GetDigestSizeBits_Inst(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		int32_t GetDigestSizeBits_Inst(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

		static void Hash(int32_t Algorithm, void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult);

		void Hash_Inst(int32_t Algorithm, void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELHMACKEYMATERIAL
		static void Hash(int32_t Algorithm, TElHMACKeyMaterial &Key, void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult);

		static void Hash(int32_t Algorithm, TElHMACKeyMaterial *Key, void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELHMACKEYMATERIAL */

#ifdef SB_USE_CLASS_TELHMACKEYMATERIAL
		void Hash_Inst(int32_t Algorithm, TElHMACKeyMaterial &Key, void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult);

		void Hash_Inst(int32_t Algorithm, TElHMACKeyMaterial *Key, void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELHMACKEYMATERIAL */

		virtual int32_t get_Algorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Algorithm, TElHashFunction, Algorithm);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		virtual TElCustomCryptoProvider* get_CryptoProvider();

		virtual void set_CryptoProvider(TElCustomCryptoProvider &Value);

		virtual void set_CryptoProvider(TElCustomCryptoProvider *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProvider*, get_CryptoProvider, set_CryptoProvider, TElHashFunction, CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELHMACKEYMATERIAL
		virtual TElHMACKeyMaterial* get_Key();

		virtual void set_Key(TElHMACKeyMaterial &Value);

		virtual void set_Key(TElHMACKeyMaterial *Value);

		SB_DECLARE_PROPERTY(TElHMACKeyMaterial*, get_Key, set_Key, TElHashFunction, Key);
#endif /* SB_USE_CLASS_TELHMACKEYMATERIAL */

		TElHashFunction(TElHashFunctionHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElHashFunction(int32_t Algorithm, TElCustomCryptoProvider &CryptoProvider);

		TElHashFunction(int32_t Algorithm, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElHashFunction(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider);

		TElHashFunction(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME
		TElHashFunction(int32_t Algorithm, TElRelativeDistinguishedName &Parameters, TElCustomCryptoProvider &CryptoProvider);

		TElHashFunction(int32_t Algorithm, TElRelativeDistinguishedName *Parameters, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME
		TElHashFunction(const std::vector<uint8_t> &OID, TElRelativeDistinguishedName &Parameters, TElCustomCryptoProvider &CryptoProvider);

		TElHashFunction(const std::vector<uint8_t> &OID, TElRelativeDistinguishedName *Parameters, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElHashFunction(TElCustomCryptoProvider &CryptoProvider);

		explicit TElHashFunction(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELHMACKEYMATERIAL
		TElHashFunction(int32_t Algorithm, TElHMACKeyMaterial &Key);

		TElHashFunction(int32_t Algorithm, TElHMACKeyMaterial *Key);
#endif /* SB_USE_CLASS_TELHMACKEYMATERIAL */

#ifdef SB_USE_CLASS_TELHMACKEYMATERIAL
		TElHashFunction(const std::vector<uint8_t> &OID, TElHMACKeyMaterial &Key);

		TElHashFunction(const std::vector<uint8_t> &OID, TElHMACKeyMaterial *Key);
#endif /* SB_USE_CLASS_TELHMACKEYMATERIAL */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELHMACKEYMATERIAL
		TElHashFunction(int32_t Algorithm, TElHMACKeyMaterial &Key, TElCustomCryptoProvider &CryptoProvider);

		TElHashFunction(int32_t Algorithm, TElHMACKeyMaterial *Key, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELHMACKEYMATERIAL */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELHMACKEYMATERIAL
		TElHashFunction(const std::vector<uint8_t> &OID, TElHMACKeyMaterial &Key, TElCustomCryptoProvider &CryptoProvider);

		TElHashFunction(const std::vector<uint8_t> &OID, TElHMACKeyMaterial *Key, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELHMACKEYMATERIAL */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElHashFunction(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElHashFunction(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELRELATIVEDISTINGUISHEDNAME
		TElHashFunction(int32_t Algorithm, TElRelativeDistinguishedName &Parameters, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElHashFunction(int32_t Algorithm, TElRelativeDistinguishedName *Parameters, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELRELATIVEDISTINGUISHEDNAME
		TElHashFunction(const std::vector<uint8_t> &OID, TElRelativeDistinguishedName &Parameters, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElHashFunction(const std::vector<uint8_t> &OID, TElRelativeDistinguishedName *Parameters, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELHMACKEYMATERIAL
		TElHashFunction(int32_t Algorithm, TElHMACKeyMaterial &Key, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElHashFunction(int32_t Algorithm, TElHMACKeyMaterial *Key, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELHMACKEYMATERIAL */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELHMACKEYMATERIAL
		TElHashFunction(const std::vector<uint8_t> &OID, TElHMACKeyMaterial &Key, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElHashFunction(const std::vector<uint8_t> &OID, TElHMACKeyMaterial *Key, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELHMACKEYMATERIAL */

		virtual ~TElHashFunction();

};
#endif /* SB_USE_CLASS_TELHASHFUNCTION */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBHASHFUNCTION */

