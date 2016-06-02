#ifndef __INC_SBSYMMETRICCRYPTO
#define __INC_SBSYMMETRICCRYPTO

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbcustomcrypto.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#ifdef SB_WINDOWS
#include "sbwincrypt.h"
#endif
#include "sbsha2.h"
#include "sbcryptoprov.h"
#include "sbcryptoprovmanager.h"
#include "sbcryptoprovutils.h"
#include "sbcryptoprovrs.h"
#include "sbconstants.h"
#include "sbrandom.h"
#include "sbpoly1305.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElSymmetricKeyMaterialHandle;

typedef TElSymmetricKeyMaterialHandle ElSymmetricKeyMaterialHandle;

typedef TElClassHandle TElSymmetricCryptoHandle;

typedef TElSymmetricCryptoHandle ElSymmetricCryptoHandle;

typedef TElClassHandle TElSymmetricCryptoFactoryHandle;

typedef TElSymmetricCryptoFactoryHandle ElSymmetricCryptoFactoryHandle;

typedef TElClassHandle TElAESSymmetricCryptoHandle;

typedef TElAESSymmetricCryptoHandle ElAESSymmetricCryptoHandle;

typedef TElClassHandle TElBlowfishSymmetricCryptoHandle;

typedef TElBlowfishSymmetricCryptoHandle ElBlowfishSymmetricCryptoHandle;

typedef TElClassHandle TElTwofishSymmetricCryptoHandle;

typedef TElTwofishSymmetricCryptoHandle ElTwofishSymmetricCryptoHandle;

typedef TElClassHandle TElIDEASymmetricCryptoHandle;

typedef TElIDEASymmetricCryptoHandle ElIDEASymmetricCryptoHandle;

typedef TElClassHandle TElCAST128SymmetricCryptoHandle;

typedef TElCAST128SymmetricCryptoHandle ElCAST128SymmetricCryptoHandle;

typedef TElClassHandle TElRC2SymmetricCryptoHandle;

typedef TElRC2SymmetricCryptoHandle ElRC2SymmetricCryptoHandle;

typedef TElClassHandle TElRC4SymmetricCryptoHandle;

typedef TElRC4SymmetricCryptoHandle ElRC4SymmetricCryptoHandle;

typedef TElClassHandle TElDESSymmetricCryptoHandle;

typedef TElDESSymmetricCryptoHandle ElDESSymmetricCryptoHandle;

typedef TElClassHandle TEl3DESSymmetricCryptoHandle;

typedef TEl3DESSymmetricCryptoHandle El3DESSymmetricCryptoHandle;

typedef TElClassHandle TElCamelliaSymmetricCryptoHandle;

typedef TElCamelliaSymmetricCryptoHandle ElCamelliaSymmetricCryptoHandle;

typedef TElClassHandle TElSerpentSymmetricCryptoHandle;

typedef TElSerpentSymmetricCryptoHandle ElSerpentSymmetricCryptoHandle;

typedef TElClassHandle TElSEEDSymmetricCryptoHandle;

typedef TElSEEDSymmetricCryptoHandle ElSEEDSymmetricCryptoHandle;

typedef TElClassHandle TElRabbitSymmetricCryptoHandle;

typedef TElRabbitSymmetricCryptoHandle ElRabbitSymmetricCryptoHandle;

typedef TElClassHandle TElGOST28147SymmetricCryptoHandle;

typedef TElGOST28147SymmetricCryptoHandle ElGOST28147SymmetricCryptoHandle;

typedef TElClassHandle TElIdentitySymmetricCryptoHandle;

typedef TElIdentitySymmetricCryptoHandle ElIdentitySymmetricCryptoHandle;

typedef TElClassHandle TElChaCha20SymmetricCryptoHandle;

typedef TElChaCha20SymmetricCryptoHandle ElChaCha20SymmetricCryptoHandle;

typedef TElClassHandle TElAEADChaCha20Poly1305SymmetricCryptoHandle;

typedef TElAEADChaCha20Poly1305SymmetricCryptoHandle ElAEADChaCha20Poly1305SymmetricCryptoHandle;

typedef uint8_t TSBSymmetricCryptoModeRaw;

typedef enum
{
	_cmDefault = 0,
	_cmECB = 1,
	_cmCBC = 2,
	_cmCTR = 3,
	_cmCFB8 = 4,
	_cmGCM = 5,
	_cmCCM = 6,
	_cmAEADChaCha20Poly1305 = 7
} TSBSymmetricCryptoMode;

typedef uint8_t TSBSymmetricCipherPaddingRaw;

typedef enum
{
	_cpNone = 0,
	_cpPKCS5 = 1,
	_cpANSIX923 = 2
} TSBSymmetricCipherPadding;

typedef TElClassHandle TElSymmetricCryptoClassHandle;

typedef TElSymmetricCryptoClassHandle ElSymmetricCryptoClassHandle;

#ifdef SB_USE_CLASS_TELSYMMETRICKEYMATERIAL
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricKeyMaterial_Generate(TElSymmetricKeyMaterialHandle _Handle, int32_t Bits);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricKeyMaterial_GenerateIV(TElSymmetricKeyMaterialHandle _Handle, int32_t Bits);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricKeyMaterial_DeriveKey(TElSymmetricKeyMaterialHandle _Handle, int32_t Bits, const char * pcPassword, int32_t szPassword);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricKeyMaterial_DeriveKey_1(TElSymmetricKeyMaterialHandle _Handle, int32_t Bits, const char * pcPassword, int32_t szPassword, const char * pcSalt, int32_t szSalt);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricKeyMaterial_DeriveKey_2(TElSymmetricKeyMaterialHandle _Handle, int32_t Bits, const char * pcPassword, int32_t szPassword, const uint8_t pSalt[], int32_t szSalt);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricKeyMaterial_DeriveKey_3(TElSymmetricKeyMaterialHandle _Handle, int32_t Bits, const char * pcPassword, int32_t szPassword, const uint8_t pSalt[], int32_t szSalt, int32_t Iterations);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricKeyMaterial_Load(TElSymmetricKeyMaterialHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricKeyMaterial_Load_1(TElSymmetricKeyMaterialHandle _Handle, TStreamHandle Stream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricKeyMaterial_Save(TElSymmetricKeyMaterialHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricKeyMaterial_Save_1(TElSymmetricKeyMaterialHandle _Handle, TStreamHandle Stream);
#ifndef SB_CPU64_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricKeyMaterial_ImportEncryptedSymmetricKeyWin32(TElSymmetricKeyMaterialHandle _Handle, const uint8_t pEncryptedKey[], int32_t szEncryptedKey, int32_t SymAlgorithm, int32_t PKAlgorithm, const uint8_t pSymAlgParams[], int32_t szSymAlgParams, uint32_t hProv, uint32_t hUserKey, int8_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricKeyMaterial_ImportEncryptedSymmetricKeyWin32(TElSymmetricKeyMaterialHandle _Handle, const uint8_t pEncryptedKey[], int32_t szEncryptedKey, int32_t SymAlgorithm, int32_t PKAlgorithm, const uint8_t pSymAlgParams[], int32_t szSymAlgParams, int64_t hProv, int64_t hUserKey, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricKeyMaterial_Persistentiate(TElSymmetricKeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricKeyMaterial_get_Key_ByteArray(TElSymmetricKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricKeyMaterial_set_Key_ByteArray(TElSymmetricKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricKeyMaterial_get_IV(TElSymmetricKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricKeyMaterial_set_IV(TElSymmetricKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricKeyMaterial_get_Algorithm(TElSymmetricKeyMaterialHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricKeyMaterial_set_Algorithm(TElSymmetricKeyMaterialHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricKeyMaterial_Create(TElCustomCryptoProviderHandle Prov, TElSymmetricKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricKeyMaterial_Create_1(TElCustomCryptoKeyHandle Key, TElCustomCryptoProviderHandle Prov, TElSymmetricKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricKeyMaterial_Create_2(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElSymmetricKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricKeyMaterial_Create_3(TElCustomCryptoKeyHandle Key, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElSymmetricKeyMaterialHandle * OutResult);
#endif /* SB_USE_CLASS_TELSYMMETRICKEYMATERIAL */

#ifdef SB_USE_CLASS_TELSYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_InitializeEncryption(TElSymmetricCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_InitializeDecryption(TElSymmetricCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_Encrypt(TElSymmetricCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_Encrypt_1(TElSymmetricCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_Encrypt_2(int32_t AlgID, const uint8_t pKey[], int32_t szKey, const uint8_t pIV[], int32_t szIV, TSBSymmetricCryptoModeRaw Mode, void * Buffer, int32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_Encrypt_3(TElSymmetricCryptoHandle _Handle, int32_t AlgID, const uint8_t pKey[], int32_t szKey, const uint8_t pIV[], int32_t szIV, TSBSymmetricCryptoModeRaw Mode, void * Buffer, int32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_EncryptUpdate(TElSymmetricCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_FinalizeEncryption(TElSymmetricCryptoHandle _Handle, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_EncryptAEAD(TElSymmetricCryptoHandle _Handle, void * AssociatedData, int32_t ADataSize, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_Decrypt(TElSymmetricCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_Decrypt_1(TElSymmetricCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int32_t InCount);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_Decrypt_2(int32_t AlgID, const uint8_t pKey[], int32_t szKey, const uint8_t pIV[], int32_t szIV, TSBSymmetricCryptoModeRaw Mode, void * Buffer, int32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_Decrypt_3(TElSymmetricCryptoHandle _Handle, int32_t AlgID, const uint8_t pKey[], int32_t szKey, const uint8_t pIV[], int32_t szIV, TSBSymmetricCryptoModeRaw Mode, void * Buffer, int32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_DecryptAEAD(TElSymmetricCryptoHandle _Handle, void * AssociatedData, int32_t ADataSize, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_DecryptUpdate(TElSymmetricCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_DecryptUpdateWin32(TElSymmetricCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_FinalizeDecryption(TElSymmetricCryptoHandle _Handle, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_get_AlgID(TElSymmetricCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_get_MACAlgorithm(TElSymmetricCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_get_KeyMaterial(TElSymmetricCryptoHandle _Handle, TElSymmetricKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_set_KeyMaterial(TElSymmetricCryptoHandle _Handle, TElSymmetricKeyMaterialHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_get_Mode(TElSymmetricCryptoHandle _Handle, TSBSymmetricCryptoModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_get_BlockSize(TElSymmetricCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_get_KeySize(TElSymmetricCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_get_Padding(TElSymmetricCryptoHandle _Handle, TSBSymmetricCipherPaddingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_set_Padding(TElSymmetricCryptoHandle _Handle, TSBSymmetricCipherPaddingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_get_CTRLittleEndian(TElSymmetricCryptoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_set_CTRLittleEndian(TElSymmetricCryptoHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_get_Nonce(TElSymmetricCryptoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_set_Nonce(TElSymmetricCryptoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_get_TagSize(TElSymmetricCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_set_TagSize(TElSymmetricCryptoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_get_AssociatedDataSize(TElSymmetricCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_set_AssociatedDataSize(TElSymmetricCryptoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_get_PayloadSize(TElSymmetricCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_set_PayloadSize(TElSymmetricCryptoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_get_AssociatedData(TElSymmetricCryptoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_set_AssociatedData(TElSymmetricCryptoHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_get_IsStreamCipher(TElSymmetricCryptoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_get_CryptoProvider(TElSymmetricCryptoHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_set_CryptoProvider(TElSymmetricCryptoHandle _Handle, TElCustomCryptoProviderHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_get_CryptoProviderManager(TElSymmetricCryptoHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_set_CryptoProviderManager(TElSymmetricCryptoHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_get_OnProgress(TElSymmetricCryptoHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_set_OnProgress(TElSymmetricCryptoHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_Create(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_Create_2(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_Create_3(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_Create_4(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_Create_5(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_Create_6(int32_t AlgID, int32_t MacAlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCrypto_Create_7(int32_t AlgID, int32_t MacAlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElSymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELSYMMETRICCRYPTOFACTORY
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCryptoFactory_CreateInstance(TElSymmetricCryptoFactoryHandle _Handle, const uint8_t pOID[], int32_t szOID, TSBSymmetricCryptoModeRaw Mode, TElSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCryptoFactory_CreateInstance_1(TElSymmetricCryptoFactoryHandle _Handle, int32_t Alg, TSBSymmetricCryptoModeRaw Mode, TElSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCryptoFactory_CreateInstance_2(TElSymmetricCryptoFactoryHandle _Handle, int32_t Alg, int32_t Mac, TSBSymmetricCryptoModeRaw Mode, TElSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCryptoFactory_IsAlgorithmSupported(TElSymmetricCryptoFactoryHandle _Handle, const uint8_t pOID[], int32_t szOID, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCryptoFactory_IsAlgorithmSupported_1(TElSymmetricCryptoFactoryHandle _Handle, int32_t Alg, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCryptoFactory_GetDefaultKeyAndBlockLengths(TElSymmetricCryptoFactoryHandle _Handle, int32_t Alg, int32_t * KeyLen, int32_t * BlockLen, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCryptoFactory_GetDefaultKeyAndBlockLengths_1(TElSymmetricCryptoFactoryHandle _Handle, const uint8_t pOID[], int32_t szOID, int32_t * KeyLen, int32_t * BlockLen, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCryptoFactory_get_CryptoProvider(TElSymmetricCryptoFactoryHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCryptoFactory_set_CryptoProvider(TElSymmetricCryptoFactoryHandle _Handle, TElCustomCryptoProviderHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCryptoFactory_get_CryptoProviderManager(TElSymmetricCryptoFactoryHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCryptoFactory_set_CryptoProviderManager(TElSymmetricCryptoFactoryHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSymmetricCryptoFactory_Create(TElSymmetricCryptoFactoryHandle * OutResult);
#endif /* SB_USE_CLASS_TELSYMMETRICCRYPTOFACTORY */

#ifdef SB_USE_CLASS_TELAESSYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElAESSymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAESSymmetricCrypto_Create(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElAESSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAESSymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElAESSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAESSymmetricCrypto_Create_2(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElAESSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAESSymmetricCrypto_Create_3(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElAESSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAESSymmetricCrypto_Create_4(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElAESSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAESSymmetricCrypto_Create_5(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElAESSymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELAESSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELBLOWFISHSYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElBlowfishSymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBlowfishSymmetricCrypto_Create(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElBlowfishSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBlowfishSymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElBlowfishSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBlowfishSymmetricCrypto_Create_2(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElBlowfishSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBlowfishSymmetricCrypto_Create_3(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElBlowfishSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBlowfishSymmetricCrypto_Create_4(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElBlowfishSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBlowfishSymmetricCrypto_Create_5(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElBlowfishSymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELBLOWFISHSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELTWOFISHSYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElTwofishSymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTwofishSymmetricCrypto_Create(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElTwofishSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTwofishSymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElTwofishSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTwofishSymmetricCrypto_Create_2(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElTwofishSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTwofishSymmetricCrypto_Create_3(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElTwofishSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTwofishSymmetricCrypto_Create_4(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElTwofishSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTwofishSymmetricCrypto_Create_5(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElTwofishSymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELTWOFISHSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELIDEASYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElIDEASymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIDEASymmetricCrypto_Create(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElIDEASymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIDEASymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElIDEASymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIDEASymmetricCrypto_Create_2(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElIDEASymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIDEASymmetricCrypto_Create_3(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElIDEASymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIDEASymmetricCrypto_Create_4(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElIDEASymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIDEASymmetricCrypto_Create_5(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElIDEASymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELIDEASYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELCAST128SYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElCAST128SymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCAST128SymmetricCrypto_Create(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElCAST128SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCAST128SymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElCAST128SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCAST128SymmetricCrypto_Create_2(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElCAST128SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCAST128SymmetricCrypto_Create_3(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElCAST128SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCAST128SymmetricCrypto_Create_4(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElCAST128SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCAST128SymmetricCrypto_Create_5(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElCAST128SymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELCAST128SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELRC2SYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElRC2SymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRC2SymmetricCrypto_Create(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElRC2SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRC2SymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElRC2SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRC2SymmetricCrypto_Create_2(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElRC2SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRC2SymmetricCrypto_Create_3(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElRC2SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRC2SymmetricCrypto_Create_4(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElRC2SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRC2SymmetricCrypto_Create_5(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElRC2SymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELRC2SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELRC4SYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElRC4SymmetricCrypto_InitializeEncryption(TElRC4SymmetricCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElRC4SymmetricCrypto_InitializeDecryption(TElRC4SymmetricCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElRC4SymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRC4SymmetricCrypto_get_SkipKeystreamBytes(TElRC4SymmetricCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRC4SymmetricCrypto_set_SkipKeystreamBytes(TElRC4SymmetricCryptoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRC4SymmetricCrypto_Create(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElRC4SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRC4SymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElRC4SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRC4SymmetricCrypto_Create_2(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElRC4SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRC4SymmetricCrypto_Create_3(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElRC4SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRC4SymmetricCrypto_Create_4(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElRC4SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRC4SymmetricCrypto_Create_5(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElRC4SymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELRC4SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELDESSYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElDESSymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDESSymmetricCrypto_Create(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElDESSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDESSymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElDESSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDESSymmetricCrypto_Create_2(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElDESSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDESSymmetricCrypto_Create_3(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElDESSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDESSymmetricCrypto_Create_4(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElDESSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDESSymmetricCrypto_Create_5(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElDESSymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELDESSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TEL3DESSYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TEl3DESSymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TEl3DESSymmetricCrypto_Create(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TEl3DESSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TEl3DESSymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TEl3DESSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TEl3DESSymmetricCrypto_Create_2(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TEl3DESSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TEl3DESSymmetricCrypto_Create_3(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TEl3DESSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TEl3DESSymmetricCrypto_Create_4(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TEl3DESSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TEl3DESSymmetricCrypto_Create_5(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TEl3DESSymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TEL3DESSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELCAMELLIASYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElCamelliaSymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCamelliaSymmetricCrypto_Create(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElCamelliaSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCamelliaSymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElCamelliaSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCamelliaSymmetricCrypto_Create_2(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElCamelliaSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCamelliaSymmetricCrypto_Create_3(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElCamelliaSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCamelliaSymmetricCrypto_Create_4(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElCamelliaSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCamelliaSymmetricCrypto_Create_5(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElCamelliaSymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELCAMELLIASYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELSERPENTSYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElSerpentSymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSerpentSymmetricCrypto_Create(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElSerpentSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSerpentSymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElSerpentSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSerpentSymmetricCrypto_Create_2(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElSerpentSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSerpentSymmetricCrypto_Create_3(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElSerpentSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSerpentSymmetricCrypto_Create_4(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElSerpentSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSerpentSymmetricCrypto_Create_5(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElSerpentSymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELSERPENTSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELSEEDSYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElSEEDSymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSEEDSymmetricCrypto_Create(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElSEEDSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSEEDSymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElSEEDSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSEEDSymmetricCrypto_Create_2(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElSEEDSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSEEDSymmetricCrypto_Create_3(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElSEEDSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSEEDSymmetricCrypto_Create_4(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElSEEDSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSEEDSymmetricCrypto_Create_5(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElSEEDSymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELSEEDSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELRABBITSYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElRabbitSymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRabbitSymmetricCrypto_Create(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElRabbitSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRabbitSymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElRabbitSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRabbitSymmetricCrypto_Create_2(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElRabbitSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRabbitSymmetricCrypto_Create_3(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElRabbitSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRabbitSymmetricCrypto_Create_4(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElRabbitSymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRabbitSymmetricCrypto_Create_5(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElRabbitSymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELRABBITSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELGOST28147SYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElGOST28147SymmetricCrypto_InitializeEncryption(TElGOST28147SymmetricCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGOST28147SymmetricCrypto_InitializeDecryption(TElGOST28147SymmetricCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGOST28147SymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST28147SymmetricCrypto_get_ParamSet(TElGOST28147SymmetricCryptoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST28147SymmetricCrypto_set_ParamSet(TElGOST28147SymmetricCryptoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGOST28147SymmetricCrypto_get_SBoxes(TElGOST28147SymmetricCryptoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST28147SymmetricCrypto_set_SBoxes(TElGOST28147SymmetricCryptoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGOST28147SymmetricCrypto_get_UseKeyMeshing(TElGOST28147SymmetricCryptoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST28147SymmetricCrypto_set_UseKeyMeshing(TElGOST28147SymmetricCryptoHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGOST28147SymmetricCrypto_Create(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElGOST28147SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST28147SymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElGOST28147SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST28147SymmetricCrypto_Create_2(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElGOST28147SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST28147SymmetricCrypto_Create_3(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElGOST28147SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST28147SymmetricCrypto_Create_4(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElGOST28147SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST28147SymmetricCrypto_Create_5(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElGOST28147SymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOST28147SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELIDENTITYSYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElIdentitySymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIdentitySymmetricCrypto_Create(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElIdentitySymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIdentitySymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElIdentitySymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIdentitySymmetricCrypto_Create_2(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElIdentitySymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIdentitySymmetricCrypto_Create_3(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElIdentitySymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIdentitySymmetricCrypto_Create_4(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElIdentitySymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIdentitySymmetricCrypto_Create_5(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElIdentitySymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELIDENTITYSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELCHACHA20SYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElChaCha20SymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChaCha20SymmetricCrypto_get_Counter(TElChaCha20SymmetricCryptoHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChaCha20SymmetricCrypto_set_Counter(TElChaCha20SymmetricCryptoHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElChaCha20SymmetricCrypto_Create(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElChaCha20SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChaCha20SymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElChaCha20SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChaCha20SymmetricCrypto_Create_2(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElChaCha20SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChaCha20SymmetricCrypto_Create_3(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElChaCha20SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChaCha20SymmetricCrypto_Create_4(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElChaCha20SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChaCha20SymmetricCrypto_Create_5(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElChaCha20SymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELCHACHA20SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELAEADCHACHA20POLY1305SYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElAEADChaCha20Poly1305SymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAEADChaCha20Poly1305SymmetricCrypto_get_AAD(TElAEADChaCha20Poly1305SymmetricCryptoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAEADChaCha20Poly1305SymmetricCrypto_set_AAD(TElAEADChaCha20Poly1305SymmetricCryptoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAEADChaCha20Poly1305SymmetricCrypto_get_Tag(TElAEADChaCha20Poly1305SymmetricCryptoHandle _Handle, TSBPoly1305Tag * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAEADChaCha20Poly1305SymmetricCrypto_set_Tag(TElAEADChaCha20Poly1305SymmetricCryptoHandle _Handle, TSBPoly1305Tag * Value);
SB_IMPORT uint32_t SB_APIENTRY TElAEADChaCha20Poly1305SymmetricCrypto_get_Poly1305Mode(TElAEADChaCha20Poly1305SymmetricCryptoHandle _Handle, TSBPoly1305ModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAEADChaCha20Poly1305SymmetricCrypto_set_Poly1305Mode(TElAEADChaCha20Poly1305SymmetricCryptoHandle _Handle, TSBPoly1305ModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAEADChaCha20Poly1305SymmetricCrypto_Create(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElAEADChaCha20Poly1305SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAEADChaCha20Poly1305SymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElAEADChaCha20Poly1305SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAEADChaCha20Poly1305SymmetricCrypto_Create_2(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderHandle CryptoProvider, TElAEADChaCha20Poly1305SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAEADChaCha20Poly1305SymmetricCrypto_Create_3(int32_t AlgID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElAEADChaCha20Poly1305SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAEADChaCha20Poly1305SymmetricCrypto_Create_4(const uint8_t pAlgOID[], int32_t szAlgOID, TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElAEADChaCha20Poly1305SymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAEADChaCha20Poly1305SymmetricCrypto_Create_5(TSBSymmetricCryptoModeRaw Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElAEADChaCha20Poly1305SymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELAEADCHACHA20POLY1305SYMMETRICCRYPTO */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSymmetricKeyMaterial;
typedef TElSymmetricKeyMaterial ElSymmetricKeyMaterial;
class TElSymmetricCrypto;
typedef TElSymmetricCrypto ElSymmetricCrypto;
class TElSymmetricCryptoFactory;
typedef TElSymmetricCryptoFactory ElSymmetricCryptoFactory;
class TElAESSymmetricCrypto;
typedef TElAESSymmetricCrypto ElAESSymmetricCrypto;
class TElBlowfishSymmetricCrypto;
typedef TElBlowfishSymmetricCrypto ElBlowfishSymmetricCrypto;
class TElTwofishSymmetricCrypto;
typedef TElTwofishSymmetricCrypto ElTwofishSymmetricCrypto;
class TElIDEASymmetricCrypto;
typedef TElIDEASymmetricCrypto ElIDEASymmetricCrypto;
class TElCAST128SymmetricCrypto;
typedef TElCAST128SymmetricCrypto ElCAST128SymmetricCrypto;
class TElRC2SymmetricCrypto;
typedef TElRC2SymmetricCrypto ElRC2SymmetricCrypto;
class TElRC4SymmetricCrypto;
typedef TElRC4SymmetricCrypto ElRC4SymmetricCrypto;
class TElDESSymmetricCrypto;
typedef TElDESSymmetricCrypto ElDESSymmetricCrypto;
class TEl3DESSymmetricCrypto;
typedef TEl3DESSymmetricCrypto El3DESSymmetricCrypto;
class TElCamelliaSymmetricCrypto;
typedef TElCamelliaSymmetricCrypto ElCamelliaSymmetricCrypto;
class TElSerpentSymmetricCrypto;
typedef TElSerpentSymmetricCrypto ElSerpentSymmetricCrypto;
class TElSEEDSymmetricCrypto;
typedef TElSEEDSymmetricCrypto ElSEEDSymmetricCrypto;
class TElRabbitSymmetricCrypto;
typedef TElRabbitSymmetricCrypto ElRabbitSymmetricCrypto;
class TElGOST28147SymmetricCrypto;
typedef TElGOST28147SymmetricCrypto ElGOST28147SymmetricCrypto;
class TElIdentitySymmetricCrypto;
typedef TElIdentitySymmetricCrypto ElIdentitySymmetricCrypto;
class TElChaCha20SymmetricCrypto;
typedef TElChaCha20SymmetricCrypto ElChaCha20SymmetricCrypto;
class TElAEADChaCha20Poly1305SymmetricCrypto;
typedef TElAEADChaCha20Poly1305SymmetricCrypto ElAEADChaCha20Poly1305SymmetricCrypto;

#ifdef SB_USE_CLASS_TELSYMMETRICKEYMATERIAL
class TElSymmetricKeyMaterial: public TElKeyMaterial
{
	private:
		SB_DISABLE_COPY(TElSymmetricKeyMaterial)
	public:
		virtual void Generate(int32_t Bits);

		virtual void GenerateIV(int32_t Bits);

		void DeriveKey(int32_t Bits, const std::string &Password);

		void DeriveKey(int32_t Bits, const std::string &Password, const std::string &Salt);

		void DeriveKey(int32_t Bits, const std::string &Password, const std::vector<uint8_t> &Salt);

		void DeriveKey(int32_t Bits, const std::string &Password, const std::vector<uint8_t> &Salt, int32_t Iterations);

		virtual void Load(void * Buffer, int32_t Size);

#ifdef SB_USE_CLASS_TSTREAM
		virtual void Load(TStream &Stream, int32_t Count);

		virtual void Load(TStream *Stream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void Save(void * Buffer, int32_t &Size);

#ifdef SB_USE_CLASS_TSTREAM
		virtual void Save(TStream &Stream);

		virtual void Save(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifndef SB_CPU64_OR_NOT_WINDOWS
		bool ImportEncryptedSymmetricKeyWin32(const std::vector<uint8_t> &EncryptedKey, int32_t SymAlgorithm, int32_t PKAlgorithm, const std::vector<uint8_t> &SymAlgParams, uint32_t hProv, uint32_t hUserKey);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_WINDOWS
		bool ImportEncryptedSymmetricKeyWin32(const std::vector<uint8_t> &EncryptedKey, int32_t SymAlgorithm, int32_t PKAlgorithm, const std::vector<uint8_t> &SymAlgParams, int64_t hProv, int64_t hUserKey);
#endif

		virtual void Persistentiate();

		virtual void get_Key_ByteArray(std::vector<uint8_t> &OutResult);

		virtual void set_Key_ByteArray(const std::vector<uint8_t> &Value);

		virtual void get_IV(std::vector<uint8_t> &OutResult);

		virtual void set_IV(const std::vector<uint8_t> &Value);

		virtual int32_t get_Algorithm();

		virtual void set_Algorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Algorithm, set_Algorithm, TElSymmetricKeyMaterial, Algorithm);

		TElSymmetricKeyMaterial(TElSymmetricKeyMaterialHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElSymmetricKeyMaterial(TElCustomCryptoProvider &Prov);

		explicit TElSymmetricKeyMaterial(TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER
		TElSymmetricKeyMaterial(TElCustomCryptoKey &Key, TElCustomCryptoProvider &Prov);

		TElSymmetricKeyMaterial(TElCustomCryptoKey *Key, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElSymmetricKeyMaterial(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElSymmetricKeyMaterial(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElSymmetricKeyMaterial(TElCustomCryptoKey &Key, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElSymmetricKeyMaterial(TElCustomCryptoKey *Key, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELSYMMETRICKEYMATERIAL */

#ifdef SB_USE_CLASS_TELSYMMETRICCRYPTO
class TElSymmetricCrypto: public TElCustomCrypto
{
	private:
		SB_DISABLE_COPY(TElSymmetricCrypto)
#ifdef SB_USE_CLASS_TELSYMMETRICKEYMATERIAL
		TElSymmetricKeyMaterial* _Inst_KeyMaterial;
#endif /* SB_USE_CLASS_TELSYMMETRICKEYMATERIAL */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCustomCryptoProvider* _Inst_CryptoProvider;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		void initInstances();

	public:
		virtual void InitializeEncryption();

		virtual void InitializeDecryption();

		void Encrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TSTREAM
		void Encrypt(TStream &InStream, TStream &OutStream);

		void Encrypt(TStream *InStream, TStream *OutStream);
#endif /* SB_USE_CLASS_TSTREAM */

		static void Encrypt(int32_t AlgID, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, TSBSymmetricCryptoMode Mode, void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult);

		void Encrypt_Inst(int32_t AlgID, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, TSBSymmetricCryptoMode Mode, void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult);

		void EncryptUpdate(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

		virtual void FinalizeEncryption(void * OutBuffer, int32_t &OutSize);

		virtual void EncryptAEAD(void * AssociatedData, int32_t ADataSize, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

		void Decrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TSTREAM
		void Decrypt(TStream &InStream, TStream &OutStream, int32_t InCount);

		void Decrypt(TStream *InStream, TStream *OutStream, int32_t InCount);
#endif /* SB_USE_CLASS_TSTREAM */

		static void Decrypt(int32_t AlgID, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, TSBSymmetricCryptoMode Mode, void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult);

		void Decrypt_Inst(int32_t AlgID, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, TSBSymmetricCryptoMode Mode, void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult);

		virtual void DecryptAEAD(void * AssociatedData, int32_t ADataSize, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

		void DecryptUpdate(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_WINDOWS
		void DecryptUpdateWin32(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);
#endif

		virtual void FinalizeDecryption(void * OutBuffer, int32_t &OutSize);

		static TClassHandle ClassType();

		virtual int32_t get_AlgID();

		SB_DECLARE_PROPERTY_GET(int32_t, get_AlgID, TElSymmetricCrypto, AlgID);

		virtual int32_t get_MACAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_MACAlgorithm, TElSymmetricCrypto, MACAlgorithm);

#ifdef SB_USE_CLASS_TELSYMMETRICKEYMATERIAL
		virtual TElSymmetricKeyMaterial* get_KeyMaterial();

		virtual void set_KeyMaterial(TElSymmetricKeyMaterial &Value);

		virtual void set_KeyMaterial(TElSymmetricKeyMaterial *Value);

		SB_DECLARE_PROPERTY(TElSymmetricKeyMaterial*, get_KeyMaterial, set_KeyMaterial, TElSymmetricCrypto, KeyMaterial);
#endif /* SB_USE_CLASS_TELSYMMETRICKEYMATERIAL */

		virtual TSBSymmetricCryptoMode get_Mode();

		SB_DECLARE_PROPERTY_GET(TSBSymmetricCryptoMode, get_Mode, TElSymmetricCrypto, Mode);

		virtual int32_t get_BlockSize();

		SB_DECLARE_PROPERTY_GET(int32_t, get_BlockSize, TElSymmetricCrypto, BlockSize);

		virtual int32_t get_KeySize();

		SB_DECLARE_PROPERTY_GET(int32_t, get_KeySize, TElSymmetricCrypto, KeySize);

		virtual TSBSymmetricCipherPadding get_Padding();

		virtual void set_Padding(TSBSymmetricCipherPadding Value);

		SB_DECLARE_PROPERTY(TSBSymmetricCipherPadding, get_Padding, set_Padding, TElSymmetricCrypto, Padding);

		virtual bool get_CTRLittleEndian();

		virtual void set_CTRLittleEndian(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CTRLittleEndian, set_CTRLittleEndian, TElSymmetricCrypto, CTRLittleEndian);

		virtual void get_Nonce(std::vector<uint8_t> &OutResult);

		virtual void set_Nonce(const std::vector<uint8_t> &Value);

		virtual int32_t get_TagSize();

		virtual void set_TagSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_TagSize, set_TagSize, TElSymmetricCrypto, TagSize);

		virtual int32_t get_AssociatedDataSize();

		virtual void set_AssociatedDataSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AssociatedDataSize, set_AssociatedDataSize, TElSymmetricCrypto, AssociatedDataSize);

		virtual int32_t get_PayloadSize();

		virtual void set_PayloadSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_PayloadSize, set_PayloadSize, TElSymmetricCrypto, PayloadSize);

		virtual bool get_AssociatedData();

		virtual void set_AssociatedData(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AssociatedData, set_AssociatedData, TElSymmetricCrypto, AssociatedData);

		virtual bool get_IsStreamCipher();

		SB_DECLARE_PROPERTY_GET(bool, get_IsStreamCipher, TElSymmetricCrypto, IsStreamCipher);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		virtual TElCustomCryptoProvider* get_CryptoProvider();

		virtual void set_CryptoProvider(TElCustomCryptoProvider &Value);

		virtual void set_CryptoProvider(TElCustomCryptoProvider *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProvider*, get_CryptoProvider, set_CryptoProvider, TElSymmetricCrypto, CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElSymmetricCrypto, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		TElSymmetricCrypto(TElSymmetricCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElSymmetricCrypto(int32_t AlgID, int32_t MacAlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElSymmetricCrypto(int32_t AlgID, int32_t MacAlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElSymmetricCrypto(int32_t AlgID, int32_t MacAlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElSymmetricCrypto(int32_t AlgID, int32_t MacAlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual ~TElSymmetricCrypto();

};
#endif /* SB_USE_CLASS_TELSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELSYMMETRICCRYPTOFACTORY
class TElSymmetricCryptoFactory: public TObject
{
	private:
		SB_DISABLE_COPY(TElSymmetricCryptoFactory)
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCustomCryptoProvider* _Inst_CryptoProvider;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELSYMMETRICCRYPTO
		TElSymmetricCryptoHandle CreateInstance(const std::vector<uint8_t> &OID, TSBSymmetricCryptoMode Mode);
#endif /* SB_USE_CLASS_TELSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELSYMMETRICCRYPTO
		TElSymmetricCryptoHandle CreateInstance(int32_t Alg, TSBSymmetricCryptoMode Mode);
#endif /* SB_USE_CLASS_TELSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELSYMMETRICCRYPTO
		TElSymmetricCryptoHandle CreateInstance(int32_t Alg, int32_t Mac, TSBSymmetricCryptoMode Mode);
#endif /* SB_USE_CLASS_TELSYMMETRICCRYPTO */

		bool IsAlgorithmSupported(const std::vector<uint8_t> &OID);

		bool IsAlgorithmSupported(int32_t Alg);

		bool GetDefaultKeyAndBlockLengths(int32_t Alg, int32_t &KeyLen, int32_t &BlockLen);

		bool GetDefaultKeyAndBlockLengths(const std::vector<uint8_t> &OID, int32_t &KeyLen, int32_t &BlockLen);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		virtual TElCustomCryptoProvider* get_CryptoProvider();

		virtual void set_CryptoProvider(TElCustomCryptoProvider &Value);

		virtual void set_CryptoProvider(TElCustomCryptoProvider *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProvider*, get_CryptoProvider, set_CryptoProvider, TElSymmetricCryptoFactory, CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElSymmetricCryptoFactory, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		TElSymmetricCryptoFactory(TElSymmetricCryptoFactoryHandle handle, TElOwnHandle ownHandle);

		TElSymmetricCryptoFactory();

		virtual ~TElSymmetricCryptoFactory();

};
#endif /* SB_USE_CLASS_TELSYMMETRICCRYPTOFACTORY */

#ifdef SB_USE_CLASS_TELAESSYMMETRICCRYPTO
class TElAESSymmetricCrypto: public TElSymmetricCrypto
{
	private:
		SB_DISABLE_COPY(TElAESSymmetricCrypto)
	public:
		static TClassHandle ClassType();

		TElAESSymmetricCrypto(TElAESSymmetricCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElAESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElAESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElAESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElAESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElAESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElAESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElAESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElAESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElAESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElAESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElAESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElAESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELAESSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELBLOWFISHSYMMETRICCRYPTO
class TElBlowfishSymmetricCrypto: public TElSymmetricCrypto
{
	private:
		SB_DISABLE_COPY(TElBlowfishSymmetricCrypto)
	public:
		static TClassHandle ClassType();

		TElBlowfishSymmetricCrypto(TElBlowfishSymmetricCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElBlowfishSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElBlowfishSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElBlowfishSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElBlowfishSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElBlowfishSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElBlowfishSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElBlowfishSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElBlowfishSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElBlowfishSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElBlowfishSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElBlowfishSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElBlowfishSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELBLOWFISHSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELTWOFISHSYMMETRICCRYPTO
class TElTwofishSymmetricCrypto: public TElSymmetricCrypto
{
	private:
		SB_DISABLE_COPY(TElTwofishSymmetricCrypto)
	public:
		static TClassHandle ClassType();

		TElTwofishSymmetricCrypto(TElTwofishSymmetricCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElTwofishSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElTwofishSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElTwofishSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElTwofishSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElTwofishSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElTwofishSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElTwofishSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElTwofishSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElTwofishSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElTwofishSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElTwofishSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElTwofishSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELTWOFISHSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELIDEASYMMETRICCRYPTO
class TElIDEASymmetricCrypto: public TElSymmetricCrypto
{
	private:
		SB_DISABLE_COPY(TElIDEASymmetricCrypto)
	public:
		static TClassHandle ClassType();

		TElIDEASymmetricCrypto(TElIDEASymmetricCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElIDEASymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElIDEASymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElIDEASymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElIDEASymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElIDEASymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElIDEASymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElIDEASymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElIDEASymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElIDEASymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElIDEASymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElIDEASymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElIDEASymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELIDEASYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELCAST128SYMMETRICCRYPTO
class TElCAST128SymmetricCrypto: public TElSymmetricCrypto
{
	private:
		SB_DISABLE_COPY(TElCAST128SymmetricCrypto)
	public:
		static TClassHandle ClassType();

		TElCAST128SymmetricCrypto(TElCAST128SymmetricCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCAST128SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElCAST128SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCAST128SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElCAST128SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCAST128SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElCAST128SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCAST128SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElCAST128SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCAST128SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElCAST128SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCAST128SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElCAST128SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELCAST128SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELRC2SYMMETRICCRYPTO
class TElRC2SymmetricCrypto: public TElSymmetricCrypto
{
	private:
		SB_DISABLE_COPY(TElRC2SymmetricCrypto)
	public:
		static TClassHandle ClassType();

		TElRC2SymmetricCrypto(TElRC2SymmetricCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElRC2SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElRC2SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElRC2SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElRC2SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElRC2SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElRC2SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElRC2SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElRC2SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElRC2SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElRC2SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElRC2SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElRC2SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELRC2SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELRC4SYMMETRICCRYPTO
class TElRC4SymmetricCrypto: public TElSymmetricCrypto
{
	private:
		SB_DISABLE_COPY(TElRC4SymmetricCrypto)
	public:
		virtual void InitializeEncryption();

		virtual void InitializeDecryption();

		static TClassHandle ClassType();

		virtual int32_t get_SkipKeystreamBytes();

		virtual void set_SkipKeystreamBytes(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SkipKeystreamBytes, set_SkipKeystreamBytes, TElRC4SymmetricCrypto, SkipKeystreamBytes);

		TElRC4SymmetricCrypto(TElRC4SymmetricCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElRC4SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElRC4SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElRC4SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElRC4SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElRC4SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElRC4SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElRC4SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElRC4SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElRC4SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElRC4SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElRC4SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElRC4SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELRC4SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELDESSYMMETRICCRYPTO
class TElDESSymmetricCrypto: public TElSymmetricCrypto
{
	private:
		SB_DISABLE_COPY(TElDESSymmetricCrypto)
	public:
		static TClassHandle ClassType();

		TElDESSymmetricCrypto(TElDESSymmetricCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElDESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElDESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElDESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElDESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElDESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElDESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElDESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElDESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElDESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElDESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElDESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElDESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELDESSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TEL3DESSYMMETRICCRYPTO
class TEl3DESSymmetricCrypto: public TElSymmetricCrypto
{
	private:
		SB_DISABLE_COPY(TEl3DESSymmetricCrypto)
	public:
		static TClassHandle ClassType();

		TEl3DESSymmetricCrypto(TEl3DESSymmetricCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TEl3DESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TEl3DESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TEl3DESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TEl3DESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TEl3DESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TEl3DESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TEl3DESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TEl3DESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TEl3DESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TEl3DESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TEl3DESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TEl3DESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TEL3DESSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELCAMELLIASYMMETRICCRYPTO
class TElCamelliaSymmetricCrypto: public TElSymmetricCrypto
{
	private:
		SB_DISABLE_COPY(TElCamelliaSymmetricCrypto)
	public:
		static TClassHandle ClassType();

		TElCamelliaSymmetricCrypto(TElCamelliaSymmetricCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCamelliaSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElCamelliaSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCamelliaSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElCamelliaSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCamelliaSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElCamelliaSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCamelliaSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElCamelliaSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCamelliaSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElCamelliaSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCamelliaSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElCamelliaSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELCAMELLIASYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELSERPENTSYMMETRICCRYPTO
class TElSerpentSymmetricCrypto: public TElSymmetricCrypto
{
	private:
		SB_DISABLE_COPY(TElSerpentSymmetricCrypto)
	public:
		static TClassHandle ClassType();

		TElSerpentSymmetricCrypto(TElSerpentSymmetricCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElSerpentSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElSerpentSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElSerpentSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElSerpentSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElSerpentSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElSerpentSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElSerpentSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElSerpentSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElSerpentSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElSerpentSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElSerpentSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElSerpentSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELSERPENTSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELSEEDSYMMETRICCRYPTO
class TElSEEDSymmetricCrypto: public TElSymmetricCrypto
{
	private:
		SB_DISABLE_COPY(TElSEEDSymmetricCrypto)
	public:
		static TClassHandle ClassType();

		TElSEEDSymmetricCrypto(TElSEEDSymmetricCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElSEEDSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElSEEDSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElSEEDSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElSEEDSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElSEEDSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElSEEDSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElSEEDSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElSEEDSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElSEEDSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElSEEDSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElSEEDSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElSEEDSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELSEEDSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELRABBITSYMMETRICCRYPTO
class TElRabbitSymmetricCrypto: public TElSymmetricCrypto
{
	private:
		SB_DISABLE_COPY(TElRabbitSymmetricCrypto)
	public:
		static TClassHandle ClassType();

		TElRabbitSymmetricCrypto(TElRabbitSymmetricCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElRabbitSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElRabbitSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElRabbitSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElRabbitSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElRabbitSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElRabbitSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElRabbitSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElRabbitSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElRabbitSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElRabbitSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElRabbitSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElRabbitSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELRABBITSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELGOST28147SYMMETRICCRYPTO
class TElGOST28147SymmetricCrypto: public TElSymmetricCrypto
{
	private:
		SB_DISABLE_COPY(TElGOST28147SymmetricCrypto)
	public:
		virtual void InitializeEncryption();

		virtual void InitializeDecryption();

		static TClassHandle ClassType();

		virtual void get_ParamSet(std::vector<uint8_t> &OutResult);

		virtual void set_ParamSet(const std::vector<uint8_t> &Value);

		virtual void get_SBoxes(std::vector<uint8_t> &OutResult);

		virtual void set_SBoxes(const std::vector<uint8_t> &Value);

		virtual bool get_UseKeyMeshing();

		virtual void set_UseKeyMeshing(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseKeyMeshing, set_UseKeyMeshing, TElGOST28147SymmetricCrypto, UseKeyMeshing);

		TElGOST28147SymmetricCrypto(TElGOST28147SymmetricCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElGOST28147SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElGOST28147SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElGOST28147SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElGOST28147SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElGOST28147SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElGOST28147SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElGOST28147SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElGOST28147SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElGOST28147SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElGOST28147SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElGOST28147SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElGOST28147SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELGOST28147SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELIDENTITYSYMMETRICCRYPTO
class TElIdentitySymmetricCrypto: public TElSymmetricCrypto
{
	private:
		SB_DISABLE_COPY(TElIdentitySymmetricCrypto)
	public:
		static TClassHandle ClassType();

		TElIdentitySymmetricCrypto(TElIdentitySymmetricCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElIdentitySymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElIdentitySymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElIdentitySymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElIdentitySymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElIdentitySymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElIdentitySymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElIdentitySymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElIdentitySymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElIdentitySymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElIdentitySymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElIdentitySymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElIdentitySymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELIDENTITYSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELCHACHA20SYMMETRICCRYPTO
class TElChaCha20SymmetricCrypto: public TElSymmetricCrypto
{
	private:
		SB_DISABLE_COPY(TElChaCha20SymmetricCrypto)
	public:
		static TClassHandle ClassType();

		virtual uint32_t get_Counter();

		virtual void set_Counter(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_Counter, set_Counter, TElChaCha20SymmetricCrypto, Counter);

		TElChaCha20SymmetricCrypto(TElChaCha20SymmetricCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElChaCha20SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElChaCha20SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElChaCha20SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElChaCha20SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElChaCha20SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElChaCha20SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElChaCha20SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElChaCha20SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElChaCha20SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElChaCha20SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElChaCha20SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElChaCha20SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELCHACHA20SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELAEADCHACHA20POLY1305SYMMETRICCRYPTO
class TElAEADChaCha20Poly1305SymmetricCrypto: public TElSymmetricCrypto
{
	private:
		SB_DISABLE_COPY(TElAEADChaCha20Poly1305SymmetricCrypto)
	public:
		static TClassHandle ClassType();

		virtual void get_AAD(std::vector<uint8_t> &OutResult);

		virtual void set_AAD(const std::vector<uint8_t> &Value);

		virtual void get_Tag(TSBPoly1305Tag &OutResult);

		virtual void set_Tag(TSBPoly1305Tag &Value);

		virtual TSBPoly1305Mode get_Poly1305Mode();

		virtual void set_Poly1305Mode(TSBPoly1305Mode Value);

		SB_DECLARE_PROPERTY(TSBPoly1305Mode, get_Poly1305Mode, set_Poly1305Mode, TElAEADChaCha20Poly1305SymmetricCrypto, Poly1305Mode);

		TElAEADChaCha20Poly1305SymmetricCrypto(TElAEADChaCha20Poly1305SymmetricCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElAEADChaCha20Poly1305SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElAEADChaCha20Poly1305SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElAEADChaCha20Poly1305SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElAEADChaCha20Poly1305SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElAEADChaCha20Poly1305SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider);

		TElAEADChaCha20Poly1305SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElAEADChaCha20Poly1305SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElAEADChaCha20Poly1305SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElAEADChaCha20Poly1305SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElAEADChaCha20Poly1305SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElAEADChaCha20Poly1305SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElAEADChaCha20Poly1305SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELAEADCHACHA20POLY1305SYMMETRICCRYPTO */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSYMMETRICCRYPTO */
