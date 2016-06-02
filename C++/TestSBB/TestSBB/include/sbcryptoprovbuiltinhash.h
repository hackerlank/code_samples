#ifndef __INC_SBCRYPTOPROVBUILTINHASH
#define __INC_SBCRYPTOPROVBUILTINHASH

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbcrc.h"
#include "sbmd.h"
#include "sbsha.h"
#include "sbsha2.h"
#include "sbripemd.h"
#include "sbwhirlpool.h"
#include "sbgostcommon.h"
#include "sbgost341194.h"
#include "sbgost2814789.h"
#include "sbumac.h"
#include "sbpoly1305.h"
#include "sbcryptoprov.h"
#include "sbcryptoprovrs.h"
#include "sbcryptoprovbuiltin.h"
#include "sbrdn.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElBuiltInHashFunctionHandle;

typedef TElClassHandle TElBuiltInMACKeyHandle;

#ifdef SB_USE_CLASS_TELBUILTINHASHFUNCTION
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInHashFunction_SetHashFunctionProp(TElBuiltInHashFunctionHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInHashFunction_GetHashFunctionProp(TElBuiltInHashFunctionHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pDefault[], int32_t szDefault, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInHashFunction_Reset(TElBuiltInHashFunctionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInHashFunction_Update(TElBuiltInHashFunctionHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInHashFunction_Update_1(TElBuiltInHashFunctionHandle _Handle, TStreamHandle Stream, int64_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInHashFunction_Finish(TElBuiltInHashFunctionHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInHashFunction_Clone(TElBuiltInHashFunctionHandle _Handle, TElBuiltInHashFunctionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInHashFunction_IsAlgorithmSupported(int32_t Algorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInHashFunction_IsAlgorithmSupported_1(TElBuiltInHashFunctionHandle _Handle, int32_t Algorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInHashFunction_IsAlgorithmSupported_2(const uint8_t pOID[], int32_t szOID, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInHashFunction_IsAlgorithmSupported_3(TElBuiltInHashFunctionHandle _Handle, const uint8_t pOID[], int32_t szOID, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInHashFunction_GetDigestSizeBits(int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInHashFunction_GetDigestSizeBits_1(TElBuiltInHashFunctionHandle _Handle, int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInHashFunction_GetDigestSizeBits_2(const uint8_t pOID[], int32_t szOID, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInHashFunction_GetDigestSizeBits_3(TElBuiltInHashFunctionHandle _Handle, const uint8_t pOID[], int32_t szOID, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInHashFunction_get_Algorithm(TElBuiltInHashFunctionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInHashFunction_get_KeyMaterial(TElBuiltInHashFunctionHandle _Handle, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInHashFunction_set_KeyMaterial(TElBuiltInHashFunctionHandle _Handle, TElCustomCryptoKeyHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInHashFunction_Create(int32_t Algorithm, TElRelativeDistinguishedNameHandle Parameters, TElCustomCryptoKeyHandle Key, TElBuiltInHashFunctionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInHashFunction_Create_1(const uint8_t pOID[], int32_t szOID, TElRelativeDistinguishedNameHandle Parameters, TElCustomCryptoKeyHandle Key, TElBuiltInHashFunctionHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINHASHFUNCTION */

#ifdef SB_USE_CLASS_TELBUILTINMACKEY
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInMACKey_Reset(TElBuiltInMACKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInMACKey_Generate(TElBuiltInMACKeyHandle _Handle, int32_t Bits, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInMACKey_ImportPublic(TElBuiltInMACKeyHandle _Handle, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInMACKey_ImportSecret(TElBuiltInMACKeyHandle _Handle, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInMACKey_ExportPublic(TElBuiltInMACKeyHandle _Handle, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInMACKey_ExportSecret(TElBuiltInMACKeyHandle _Handle, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInMACKey_Clone(TElBuiltInMACKeyHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInMACKey_ClonePublic(TElBuiltInMACKeyHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInMACKey_ClearPublic(TElBuiltInMACKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInMACKey_ClearSecret(TElBuiltInMACKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInMACKey_GetKeyProp(TElBuiltInMACKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pDefault[], int32_t szDefault, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInMACKey_SetKeyProp(TElBuiltInMACKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInMACKey_ChangeAlgorithm(TElBuiltInMACKeyHandle _Handle, int32_t Algorithm);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInMACKey_Equals(TElBuiltInMACKeyHandle _Handle, TElCustomCryptoKeyHandle Source, int8_t PublicOnly, TElRelativeDistinguishedNameHandle Params, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInMACKey_Create(TElCustomCryptoProviderHandle CryptoProvider, TElCustomCryptoKeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINMACKEY */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElBuiltInHashFunction;
class TElBuiltInMACKey;

#ifdef SB_USE_CLASS_TELBUILTINHASHFUNCTION
class TElBuiltInHashFunction: public TObject
{
	private:
		SB_DISABLE_COPY(TElBuiltInHashFunction)
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
		TElCustomCryptoKey* _Inst_KeyMaterial;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

		void initInstances();

	public:
		void SetHashFunctionProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value);

		void GetHashFunctionProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult);

		void Reset();

		void Update(void * Buffer, int32_t Size);

#ifdef SB_USE_CLASS_TSTREAM
		void Update(TStream &Stream, int64_t Count);

		void Update(TStream *Stream, int64_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		void Finish(std::vector<uint8_t> &OutResult);

		TElBuiltInHashFunctionHandle Clone();

		static bool IsAlgorithmSupported(int32_t Algorithm);

		bool IsAlgorithmSupported_Inst(int32_t Algorithm);

		static bool IsAlgorithmSupported(const std::vector<uint8_t> &OID);

		bool IsAlgorithmSupported_Inst(const std::vector<uint8_t> &OID);

		static int32_t GetDigestSizeBits(int32_t Algorithm);

		int32_t GetDigestSizeBits_Inst(int32_t Algorithm);

		static int32_t GetDigestSizeBits(const std::vector<uint8_t> &OID);

		int32_t GetDigestSizeBits_Inst(const std::vector<uint8_t> &OID);

		virtual int32_t get_Algorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Algorithm, TElBuiltInHashFunction, Algorithm);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
		virtual TElCustomCryptoKey* get_KeyMaterial();

		virtual void set_KeyMaterial(TElCustomCryptoKey &Value);

		virtual void set_KeyMaterial(TElCustomCryptoKey *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoKey*, get_KeyMaterial, set_KeyMaterial, TElBuiltInHashFunction, KeyMaterial);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

		TElBuiltInHashFunction(TElBuiltInHashFunctionHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		TElBuiltInHashFunction(int32_t Algorithm, TElRelativeDistinguishedName &Parameters, TElCustomCryptoKey &Key);

		TElBuiltInHashFunction(int32_t Algorithm, TElRelativeDistinguishedName *Parameters, TElCustomCryptoKey *Key);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		TElBuiltInHashFunction(const std::vector<uint8_t> &OID, TElRelativeDistinguishedName &Parameters, TElCustomCryptoKey &Key);

		TElBuiltInHashFunction(const std::vector<uint8_t> &OID, TElRelativeDistinguishedName *Parameters, TElCustomCryptoKey *Key);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

		virtual ~TElBuiltInHashFunction();

};
#endif /* SB_USE_CLASS_TELBUILTINHASHFUNCTION */

#ifdef SB_USE_CLASS_TELBUILTINMACKEY
class TElBuiltInMACKey: public TElBuiltInCryptoKey
{
	private:
		SB_DISABLE_COPY(TElBuiltInMACKey)
	public:
		virtual void Reset();

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void Generate(int32_t Bits, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void Generate(int32_t Bits, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params);

		virtual void ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params);

		virtual void ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params);

		virtual void ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params);

		virtual void ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoKeyHandle Clone(TElRelativeDistinguishedName &Params);

		virtual TElCustomCryptoKeyHandle Clone(TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoKeyHandle ClonePublic(TElRelativeDistinguishedName &Params);

		virtual TElCustomCryptoKeyHandle ClonePublic(TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void ClearPublic();

		virtual void ClearSecret();

		virtual void GetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult);

		virtual void SetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value);

		virtual void ChangeAlgorithm(int32_t Algorithm);

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual bool Equals(TElCustomCryptoKey &Source, bool PublicOnly, TElRelativeDistinguishedName &Params);

		virtual bool Equals(TElCustomCryptoKey *Source, bool PublicOnly, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		TElBuiltInMACKey(TElBuiltInMACKeyHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElBuiltInMACKey(TElCustomCryptoProvider &CryptoProvider);

		explicit TElBuiltInMACKey(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

};
#endif /* SB_USE_CLASS_TELBUILTINMACKEY */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCRYPTOPROVBUILTINHASH */

