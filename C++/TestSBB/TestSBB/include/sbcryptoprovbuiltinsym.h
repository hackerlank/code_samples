#ifndef __INC_SBCRYPTOPROVBUILTINSYM
#define __INC_SBCRYPTOPROVBUILTINSYM

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbcryptoprov.h"
#include "sbcryptoprovbuiltin.h"
#include "sbcryptoprovutils.h"
#include "sbcryptoprovrs.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbaes.h"
#include "sbblowfish.h"
#include "sbtwofish.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbcast128.h"
#include "sbrc2.h"
#include "sbrc4.h"
#include "sbseed.h"
#include "sbrabbit.h"
#include "sbdes.h"
#include "sbcamellia.h"
#include "sbgostcommon.h"
#include "sbgost2814789.h"
#include "sbserpent.h"
#include "sbsha2.h"
#include "sbconstants.h"
#include "sbchacha20.h"
#include "sbpoly1305.h"
#include "sbrdn.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SYMMETRIC_BLOCK_SIZE 	16384
#define SB_SYMMETRIC_DEFAULT_MODE 	

typedef TElClassHandle TElBuiltInSymmetricCryptoKeyHandle;

typedef TElClassHandle TElBuiltInSymmetricCryptoHandle;

typedef TElClassHandle TElBuiltInSymmetricCryptoFactoryHandle;

typedef TElClassHandle TElBuiltInIdentitySymmetricCryptoHandle;

typedef TElClassHandle TElBuiltInRC4SymmetricCryptoHandle;

typedef TElClassHandle TElBuiltInGOST28147SymmetricCryptoHandle;

typedef TElClassHandle TElBuiltInChaCha20SymmetricCryptoHandle;

typedef TElClassHandle TElBuiltInAEADChaCha20Poly1305SymmetricCryptoHandle;

typedef uint8_t TSBBuiltInSymmetricCryptoModeRaw;

typedef enum
{
	cmDefault = 0,
	cmECB = 1,
	cmCBC = 2,
	cmCTR = 3,
	cmCFB8 = 4,
	cmCCM = 5,
	cmGCM = 6,
	cmAEADChaCha20Poly1305 = 7
} TSBBuiltInSymmetricCryptoMode;

typedef uint8_t TSBBuiltInSymmetricCipherPaddingRaw;

typedef enum
{
	cpNone = 0,
	cpPKCS5 = 1,
	cpANSIX923 = 2
} TSBBuiltInSymmetricCipherPadding;

typedef uint8_t TSBBuiltInSymmetricCryptoOperationRaw;

typedef enum
{
	coNone = 0,
	coEncryption = 1,
	coDecryption = 2
} TSBBuiltInSymmetricCryptoOperation;

typedef void (SB_CALLBACK *TSBSymmetricCryptoProcessingFunction)(void * _ObjectData, void * Buffer, void * OutBuffer, int32_t Size);

#pragma pack(4)
typedef struct 
{
	uint32_t IV0;
	uint32_t IV1;
	uint32_t IV2;
	uint32_t IV3;
	int64_t H0;
	int64_t H1;
	int64_t Y0;
	int64_t Y1;
	int64_t Ctr0;
	int64_t Ctr1;
	int64_t ASize;
	int64_t PSize;
	int64_t HTable[32];
} TSBGCMContext;

typedef TElClassHandle TElBuiltInSymmetricCryptoClassHandle;

#ifdef SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTOKEY
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoKey_Generate(TElBuiltInSymmetricCryptoKeyHandle _Handle, int32_t Bits, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoKey_GenerateIV(TElBuiltInSymmetricCryptoKeyHandle _Handle, int32_t Bits);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoKey_ImportPublic(TElBuiltInSymmetricCryptoKeyHandle _Handle, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoKey_ImportSecret(TElBuiltInSymmetricCryptoKeyHandle _Handle, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoKey_ExportPublic(TElBuiltInSymmetricCryptoKeyHandle _Handle, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoKey_ExportSecret(TElBuiltInSymmetricCryptoKeyHandle _Handle, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoKey_ChangeAlgorithm(TElBuiltInSymmetricCryptoKeyHandle _Handle, int32_t Algorithm);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoKey_Reset(TElBuiltInSymmetricCryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoKey_Clone(TElBuiltInSymmetricCryptoKeyHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoKey_ClonePublic(TElBuiltInSymmetricCryptoKeyHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoKey_ClearPublic(TElBuiltInSymmetricCryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoKey_ClearSecret(TElBuiltInSymmetricCryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoKey_GetKeyProp(TElBuiltInSymmetricCryptoKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pDefault[], int32_t szDefault, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoKey_SetKeyProp(TElBuiltInSymmetricCryptoKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoKey_Equals(TElBuiltInSymmetricCryptoKeyHandle _Handle, TElCustomCryptoKeyHandle Source, int8_t PublicOnly, TElRelativeDistinguishedNameHandle Params, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoKey_Create(TElCustomCryptoProviderHandle CryptoProvider, TElBuiltInSymmetricCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoKey_Create_1(TElCustomCryptoProviderHandle CryptoProvider, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, TElBuiltInSymmetricCryptoKeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_InitializeEncryption(TElBuiltInSymmetricCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_InitializeDecryption(TElBuiltInSymmetricCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_Encrypt(TElBuiltInSymmetricCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_Encrypt_1(TElBuiltInSymmetricCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_EncryptUpdate(TElBuiltInSymmetricCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_FinalizeEncryption(TElBuiltInSymmetricCryptoHandle _Handle, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_Decrypt(TElBuiltInSymmetricCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_Decrypt_1(TElBuiltInSymmetricCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int32_t InCount);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_DecryptUpdate(TElBuiltInSymmetricCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_FinalizeDecryption(TElBuiltInSymmetricCryptoHandle _Handle, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_get_KeyMaterial(TElBuiltInSymmetricCryptoHandle _Handle, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_set_KeyMaterial(TElBuiltInSymmetricCryptoHandle _Handle, TElCustomCryptoKeyHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_get_AssociatedData(TElBuiltInSymmetricCryptoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_set_AssociatedData(TElBuiltInSymmetricCryptoHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_get_AssociatedDataSize(TElBuiltInSymmetricCryptoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_set_AssociatedDataSize(TElBuiltInSymmetricCryptoHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_get_PayloadSize(TElBuiltInSymmetricCryptoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_set_PayloadSize(TElBuiltInSymmetricCryptoHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_get_Nonce(TElBuiltInSymmetricCryptoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_set_Nonce(TElBuiltInSymmetricCryptoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_get_TagSize(TElBuiltInSymmetricCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_set_TagSize(TElBuiltInSymmetricCryptoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_get_Mode(TElBuiltInSymmetricCryptoHandle _Handle, TSBBuiltInSymmetricCryptoModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_get_BlockSize(TElBuiltInSymmetricCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_get_KeySize(TElBuiltInSymmetricCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_get_Padding(TElBuiltInSymmetricCryptoHandle _Handle, TSBBuiltInSymmetricCipherPaddingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_set_Padding(TElBuiltInSymmetricCryptoHandle _Handle, TSBBuiltInSymmetricCipherPaddingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_get_CTRLittleEndian(TElBuiltInSymmetricCryptoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_set_CTRLittleEndian(TElBuiltInSymmetricCryptoHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_get_IsStreamCipher(TElBuiltInSymmetricCryptoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_get_OnProgress(TElBuiltInSymmetricCryptoHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_set_OnProgress(TElBuiltInSymmetricCryptoHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_Create(int32_t AlgID, TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCrypto_Create_2(TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInSymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTOFACTORY
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoFactory_RegisterClass(TElBuiltInSymmetricCryptoFactoryHandle _Handle, TElBuiltInSymmetricCryptoClassHandle Cls);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoFactory_CreateInstance(TElBuiltInSymmetricCryptoFactoryHandle _Handle, const uint8_t pOID[], int32_t szOID, TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoFactory_CreateInstance_1(TElBuiltInSymmetricCryptoFactoryHandle _Handle, int32_t Alg, TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoFactory_CreateInstance_2(TElBuiltInSymmetricCryptoFactoryHandle _Handle, int32_t Alg, int32_t MacAlg, TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoFactory_IsAlgorithmSupported(TElBuiltInSymmetricCryptoFactoryHandle _Handle, const uint8_t pOID[], int32_t szOID, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoFactory_IsAlgorithmSupported_1(TElBuiltInSymmetricCryptoFactoryHandle _Handle, int32_t Alg, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoFactory_IsAlgorithmSupported_2(TElBuiltInSymmetricCryptoFactoryHandle _Handle, int32_t Alg, int32_t MacAlg, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoFactory_GetDefaultKeyAndBlockLengths(TElBuiltInSymmetricCryptoFactoryHandle _Handle, int32_t Alg, int32_t * KeyLen, int32_t * BlockLen, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoFactory_GetDefaultKeyAndBlockLengths_1(TElBuiltInSymmetricCryptoFactoryHandle _Handle, const uint8_t pOID[], int32_t szOID, int32_t * KeyLen, int32_t * BlockLen, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoFactory_get_RegisteredClasses(TElBuiltInSymmetricCryptoFactoryHandle _Handle, int32_t Index, TElBuiltInSymmetricCryptoClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoFactory_get_RegisteredClassCount(TElBuiltInSymmetricCryptoFactoryHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInSymmetricCryptoFactory_Create(TElBuiltInSymmetricCryptoFactoryHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTOFACTORY */

#ifdef SB_USE_CLASS_TELBUILTINIDENTITYSYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInIdentitySymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInIdentitySymmetricCrypto_Create(int32_t AlgID, TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInIdentitySymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInIdentitySymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInIdentitySymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInIdentitySymmetricCrypto_Create_2(TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInIdentitySymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINIDENTITYSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINRC4SYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRC4SymmetricCrypto_InitializeEncryption(TElBuiltInRC4SymmetricCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRC4SymmetricCrypto_InitializeDecryption(TElBuiltInRC4SymmetricCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRC4SymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRC4SymmetricCrypto_get_SkipKeystreamBytes(TElBuiltInRC4SymmetricCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRC4SymmetricCrypto_set_SkipKeystreamBytes(TElBuiltInRC4SymmetricCryptoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRC4SymmetricCrypto_Create(int32_t AlgID, TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInRC4SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRC4SymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInRC4SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRC4SymmetricCrypto_Create_2(TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInRC4SymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINRC4SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINGOST28147SYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST28147SymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST28147SymmetricCrypto_set_ParamSet(TElBuiltInGOST28147SymmetricCryptoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST28147SymmetricCrypto_set_SBoxes(TElBuiltInGOST28147SymmetricCryptoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST28147SymmetricCrypto_get_UseKeyMeshing(TElBuiltInGOST28147SymmetricCryptoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST28147SymmetricCrypto_set_UseKeyMeshing(TElBuiltInGOST28147SymmetricCryptoHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST28147SymmetricCrypto_Create(int32_t AlgID, TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInGOST28147SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST28147SymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInGOST28147SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST28147SymmetricCrypto_Create_2(TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInGOST28147SymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINGOST28147SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINCHACHA20SYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInChaCha20SymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInChaCha20SymmetricCrypto_get_Counter(TElBuiltInChaCha20SymmetricCryptoHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInChaCha20SymmetricCrypto_set_Counter(TElBuiltInChaCha20SymmetricCryptoHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInChaCha20SymmetricCrypto_Create(int32_t AlgID, TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInChaCha20SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInChaCha20SymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInChaCha20SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInChaCha20SymmetricCrypto_Create_2(TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInChaCha20SymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINCHACHA20SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINAEADCHACHA20POLY1305SYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInAEADChaCha20Poly1305SymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInAEADChaCha20Poly1305SymmetricCrypto_get_AAD(TElBuiltInAEADChaCha20Poly1305SymmetricCryptoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInAEADChaCha20Poly1305SymmetricCrypto_set_AAD(TElBuiltInAEADChaCha20Poly1305SymmetricCryptoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInAEADChaCha20Poly1305SymmetricCrypto_get_Tag(TElBuiltInAEADChaCha20Poly1305SymmetricCryptoHandle _Handle, TSBPoly1305Tag * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInAEADChaCha20Poly1305SymmetricCrypto_set_Tag(TElBuiltInAEADChaCha20Poly1305SymmetricCryptoHandle _Handle, TSBPoly1305Tag * Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInAEADChaCha20Poly1305SymmetricCrypto_get_Poly1305Mode(TElBuiltInAEADChaCha20Poly1305SymmetricCryptoHandle _Handle, TSBPoly1305ModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInAEADChaCha20Poly1305SymmetricCrypto_set_Poly1305Mode(TElBuiltInAEADChaCha20Poly1305SymmetricCryptoHandle _Handle, TSBPoly1305ModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInAEADChaCha20Poly1305SymmetricCrypto_Create(int32_t AlgID, TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInAEADChaCha20Poly1305SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInAEADChaCha20Poly1305SymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInAEADChaCha20Poly1305SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInAEADChaCha20Poly1305SymmetricCrypto_Create_2(TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInAEADChaCha20Poly1305SymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINAEADCHACHA20POLY1305SYMMETRICCRYPTO */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElBuiltInSymmetricCryptoKey;
class TElBuiltInSymmetricCrypto;
class TElBuiltInSymmetricCryptoFactory;
class TElBuiltInIdentitySymmetricCrypto;
class TElBuiltInRC4SymmetricCrypto;
class TElBuiltInGOST28147SymmetricCrypto;
class TElBuiltInChaCha20SymmetricCrypto;
class TElBuiltInAEADChaCha20Poly1305SymmetricCrypto;

#ifdef SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTOKEY
class TElBuiltInSymmetricCryptoKey: public TElBuiltInCryptoKey
{
	private:
		SB_DISABLE_COPY(TElBuiltInSymmetricCryptoKey)
	public:
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void Generate(int32_t Bits, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void Generate(int32_t Bits, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void GenerateIV(int32_t Bits);

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

		virtual void ChangeAlgorithm(int32_t Algorithm);

		virtual void Reset();

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

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual bool Equals(TElCustomCryptoKey &Source, bool PublicOnly, TElRelativeDistinguishedName &Params);

		virtual bool Equals(TElCustomCryptoKey *Source, bool PublicOnly, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		TElBuiltInSymmetricCryptoKey(TElBuiltInSymmetricCryptoKeyHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElBuiltInSymmetricCryptoKey(TElCustomCryptoProvider &CryptoProvider);

		explicit TElBuiltInSymmetricCryptoKey(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElBuiltInSymmetricCryptoKey(TElCustomCryptoProvider &CryptoProvider, const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams);

		TElBuiltInSymmetricCryptoKey(TElCustomCryptoProvider *CryptoProvider, const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

};
#endif /* SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTO
class TElBuiltInSymmetricCrypto: public TObject
{
	private:
		SB_DISABLE_COPY(TElBuiltInSymmetricCrypto)
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
		TElCustomCryptoKey* _Inst_KeyMaterial;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

		void initInstances();

	public:
		virtual void InitializeEncryption();

		virtual void InitializeDecryption();

		void Encrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TSTREAM
		void Encrypt(TStream &InStream, TStream &OutStream);

		void Encrypt(TStream *InStream, TStream *OutStream);
#endif /* SB_USE_CLASS_TSTREAM */

		void EncryptUpdate(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

		virtual void FinalizeEncryption(void * OutBuffer, int32_t &OutSize);

		void Decrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TSTREAM
		void Decrypt(TStream &InStream, TStream &OutStream, int32_t InCount);

		void Decrypt(TStream *InStream, TStream *OutStream, int32_t InCount);
#endif /* SB_USE_CLASS_TSTREAM */

		void DecryptUpdate(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

		virtual void FinalizeDecryption(void * OutBuffer, int32_t &OutSize);

		static TClassHandle ClassType();

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
		virtual TElCustomCryptoKey* get_KeyMaterial();

		virtual void set_KeyMaterial(TElCustomCryptoKey &Value);

		virtual void set_KeyMaterial(TElCustomCryptoKey *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoKey*, get_KeyMaterial, set_KeyMaterial, TElBuiltInSymmetricCrypto, KeyMaterial);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

		virtual bool get_AssociatedData();

		virtual void set_AssociatedData(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AssociatedData, set_AssociatedData, TElBuiltInSymmetricCrypto, AssociatedData);

		virtual int64_t get_AssociatedDataSize();

		virtual void set_AssociatedDataSize(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_AssociatedDataSize, set_AssociatedDataSize, TElBuiltInSymmetricCrypto, AssociatedDataSize);

		virtual int64_t get_PayloadSize();

		virtual void set_PayloadSize(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_PayloadSize, set_PayloadSize, TElBuiltInSymmetricCrypto, PayloadSize);

		virtual void get_Nonce(std::vector<uint8_t> &OutResult);

		virtual void set_Nonce(const std::vector<uint8_t> &Value);

		virtual int32_t get_TagSize();

		virtual void set_TagSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_TagSize, set_TagSize, TElBuiltInSymmetricCrypto, TagSize);

		virtual TSBBuiltInSymmetricCryptoMode get_Mode();

		SB_DECLARE_PROPERTY_GET(TSBBuiltInSymmetricCryptoMode, get_Mode, TElBuiltInSymmetricCrypto, Mode);

		virtual int32_t get_BlockSize();

		SB_DECLARE_PROPERTY_GET(int32_t, get_BlockSize, TElBuiltInSymmetricCrypto, BlockSize);

		virtual int32_t get_KeySize();

		SB_DECLARE_PROPERTY_GET(int32_t, get_KeySize, TElBuiltInSymmetricCrypto, KeySize);

		virtual TSBBuiltInSymmetricCipherPadding get_Padding();

		virtual void set_Padding(TSBBuiltInSymmetricCipherPadding Value);

		SB_DECLARE_PROPERTY(TSBBuiltInSymmetricCipherPadding, get_Padding, set_Padding, TElBuiltInSymmetricCrypto, Padding);

		virtual bool get_CTRLittleEndian();

		virtual void set_CTRLittleEndian(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CTRLittleEndian, set_CTRLittleEndian, TElBuiltInSymmetricCrypto, CTRLittleEndian);

		virtual bool get_IsStreamCipher();

		SB_DECLARE_PROPERTY_GET(bool, get_IsStreamCipher, TElBuiltInSymmetricCrypto, IsStreamCipher);

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		TElBuiltInSymmetricCrypto(TElBuiltInSymmetricCryptoHandle handle, TElOwnHandle ownHandle);

		TElBuiltInSymmetricCrypto(int32_t AlgID, TSBBuiltInSymmetricCryptoMode Mode);

		TElBuiltInSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBBuiltInSymmetricCryptoMode Mode);

		explicit TElBuiltInSymmetricCrypto(TSBBuiltInSymmetricCryptoMode Mode);

		virtual ~TElBuiltInSymmetricCrypto();

};
#endif /* SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTOFACTORY
class TElBuiltInSymmetricCryptoFactory: public TObject
{
	private:
		SB_DISABLE_COPY(TElBuiltInSymmetricCryptoFactory)
	public:
		void RegisterClass(TElBuiltInSymmetricCryptoClassHandle Cls);

#ifdef SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTO
		TElBuiltInSymmetricCryptoHandle CreateInstance(const std::vector<uint8_t> &OID, TSBBuiltInSymmetricCryptoMode Mode);
#endif /* SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTO
		TElBuiltInSymmetricCryptoHandle CreateInstance(int32_t Alg, TSBBuiltInSymmetricCryptoMode Mode);
#endif /* SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTO
		TElBuiltInSymmetricCryptoHandle CreateInstance(int32_t Alg, int32_t MacAlg, TSBBuiltInSymmetricCryptoMode Mode);
#endif /* SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTO */

		bool IsAlgorithmSupported(const std::vector<uint8_t> &OID);

		bool IsAlgorithmSupported(int32_t Alg);

		bool IsAlgorithmSupported(int32_t Alg, int32_t MacAlg);

		bool GetDefaultKeyAndBlockLengths(int32_t Alg, int32_t &KeyLen, int32_t &BlockLen);

		bool GetDefaultKeyAndBlockLengths(const std::vector<uint8_t> &OID, int32_t &KeyLen, int32_t &BlockLen);

		virtual TElBuiltInSymmetricCryptoClassHandle get_RegisteredClasses(int32_t Index);

		virtual int32_t get_RegisteredClassCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_RegisteredClassCount, TElBuiltInSymmetricCryptoFactory, RegisteredClassCount);

		TElBuiltInSymmetricCryptoFactory(TElBuiltInSymmetricCryptoFactoryHandle handle, TElOwnHandle ownHandle);

		TElBuiltInSymmetricCryptoFactory();

};
#endif /* SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTOFACTORY */

#ifdef SB_USE_CLASS_TELBUILTINIDENTITYSYMMETRICCRYPTO
class TElBuiltInIdentitySymmetricCrypto: public TElBuiltInSymmetricCrypto
{
	private:
		SB_DISABLE_COPY(TElBuiltInIdentitySymmetricCrypto)
	public:
		static TClassHandle ClassType();

		TElBuiltInIdentitySymmetricCrypto(TElBuiltInIdentitySymmetricCryptoHandle handle, TElOwnHandle ownHandle);

		TElBuiltInIdentitySymmetricCrypto(int32_t AlgID, TSBBuiltInSymmetricCryptoMode Mode);

		TElBuiltInIdentitySymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBBuiltInSymmetricCryptoMode Mode);

		explicit TElBuiltInIdentitySymmetricCrypto(TSBBuiltInSymmetricCryptoMode Mode);

};
#endif /* SB_USE_CLASS_TELBUILTINIDENTITYSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINRC4SYMMETRICCRYPTO
class TElBuiltInRC4SymmetricCrypto: public TElBuiltInSymmetricCrypto
{
	private:
		SB_DISABLE_COPY(TElBuiltInRC4SymmetricCrypto)
	public:
		virtual void InitializeEncryption();

		virtual void InitializeDecryption();

		static TClassHandle ClassType();

		virtual int32_t get_SkipKeystreamBytes();

		virtual void set_SkipKeystreamBytes(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SkipKeystreamBytes, set_SkipKeystreamBytes, TElBuiltInRC4SymmetricCrypto, SkipKeystreamBytes);

		TElBuiltInRC4SymmetricCrypto(TElBuiltInRC4SymmetricCryptoHandle handle, TElOwnHandle ownHandle);

		TElBuiltInRC4SymmetricCrypto(int32_t AlgID, TSBBuiltInSymmetricCryptoMode Mode);

		TElBuiltInRC4SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBBuiltInSymmetricCryptoMode Mode);

		explicit TElBuiltInRC4SymmetricCrypto(TSBBuiltInSymmetricCryptoMode Mode);

};
#endif /* SB_USE_CLASS_TELBUILTINRC4SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINGOST28147SYMMETRICCRYPTO
class TElBuiltInGOST28147SymmetricCrypto: public TElBuiltInSymmetricCrypto
{
	private:
		SB_DISABLE_COPY(TElBuiltInGOST28147SymmetricCrypto)
	public:
		static TClassHandle ClassType();

		virtual void set_ParamSet(const std::vector<uint8_t> &Value);

		virtual void set_SBoxes(const std::vector<uint8_t> &Value);

		virtual bool get_UseKeyMeshing();

		virtual void set_UseKeyMeshing(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseKeyMeshing, set_UseKeyMeshing, TElBuiltInGOST28147SymmetricCrypto, UseKeyMeshing);

		TElBuiltInGOST28147SymmetricCrypto(TElBuiltInGOST28147SymmetricCryptoHandle handle, TElOwnHandle ownHandle);

		TElBuiltInGOST28147SymmetricCrypto(int32_t AlgID, TSBBuiltInSymmetricCryptoMode Mode);

		TElBuiltInGOST28147SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBBuiltInSymmetricCryptoMode Mode);

		explicit TElBuiltInGOST28147SymmetricCrypto(TSBBuiltInSymmetricCryptoMode Mode);

};
#endif /* SB_USE_CLASS_TELBUILTINGOST28147SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINCHACHA20SYMMETRICCRYPTO
class TElBuiltInChaCha20SymmetricCrypto: public TElBuiltInSymmetricCrypto
{
	private:
		SB_DISABLE_COPY(TElBuiltInChaCha20SymmetricCrypto)
	public:
		static TClassHandle ClassType();

		virtual uint32_t get_Counter();

		virtual void set_Counter(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_Counter, set_Counter, TElBuiltInChaCha20SymmetricCrypto, Counter);

		TElBuiltInChaCha20SymmetricCrypto(TElBuiltInChaCha20SymmetricCryptoHandle handle, TElOwnHandle ownHandle);

		TElBuiltInChaCha20SymmetricCrypto(int32_t AlgID, TSBBuiltInSymmetricCryptoMode Mode);

		TElBuiltInChaCha20SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBBuiltInSymmetricCryptoMode Mode);

		explicit TElBuiltInChaCha20SymmetricCrypto(TSBBuiltInSymmetricCryptoMode Mode);

};
#endif /* SB_USE_CLASS_TELBUILTINCHACHA20SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINAEADCHACHA20POLY1305SYMMETRICCRYPTO
class TElBuiltInAEADChaCha20Poly1305SymmetricCrypto: public TElBuiltInSymmetricCrypto
{
	private:
		SB_DISABLE_COPY(TElBuiltInAEADChaCha20Poly1305SymmetricCrypto)
	public:
		static TClassHandle ClassType();

		virtual void get_AAD(std::vector<uint8_t> &OutResult);

		virtual void set_AAD(const std::vector<uint8_t> &Value);

		virtual void get_Tag(TSBPoly1305Tag &OutResult);

		virtual void set_Tag(TSBPoly1305Tag &Value);

		virtual TSBPoly1305Mode get_Poly1305Mode();

		virtual void set_Poly1305Mode(TSBPoly1305Mode Value);

		SB_DECLARE_PROPERTY(TSBPoly1305Mode, get_Poly1305Mode, set_Poly1305Mode, TElBuiltInAEADChaCha20Poly1305SymmetricCrypto, Poly1305Mode);

		TElBuiltInAEADChaCha20Poly1305SymmetricCrypto(TElBuiltInAEADChaCha20Poly1305SymmetricCryptoHandle handle, TElOwnHandle ownHandle);

		TElBuiltInAEADChaCha20Poly1305SymmetricCrypto(int32_t AlgID, TSBBuiltInSymmetricCryptoMode Mode);

		TElBuiltInAEADChaCha20Poly1305SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBBuiltInSymmetricCryptoMode Mode);

		explicit TElBuiltInAEADChaCha20Poly1305SymmetricCrypto(TSBBuiltInSymmetricCryptoMode Mode);

};
#endif /* SB_USE_CLASS_TELBUILTINAEADCHACHA20POLY1305SYMMETRICCRYPTO */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCRYPTOPROVBUILTINSYM */

