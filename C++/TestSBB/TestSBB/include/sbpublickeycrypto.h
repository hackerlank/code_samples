#ifndef __INC_SBPUBLICKEYCRYPTO
#define __INC_SBPUBLICKEYCRYPTO

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbencoding.h"
#include "sbmath.h"
#include "sbconstants.h"
#include "sbrsa.h"
#include "sbdsa.h"
#include "sbecdsa.h"
#include "sbelgamal.h"
#include "sbpem.h"
#include "sbsrp.h"
#include "sbasn1tree.h"
#ifdef SB_WINDOWS
#include "sbwincrypt.h"
#endif
#include "sbcustomcrypto.h"
#include "sbcryptoprov.h"
#include "sbcryptoprovmanager.h"
#include "sbcryptoprovutils.h"
#include "sbasn1.h"
#include "sbalgorithmidentifier.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElPublicKeyMaterialHandle;

typedef TElPublicKeyMaterialHandle ElPublicKeyMaterialHandle;

typedef TElClassHandle TElPublicKeyCryptoHandle;

typedef TElPublicKeyCryptoHandle ElPublicKeyCryptoHandle;

typedef TElClassHandle TElRSAKeyMaterialHandle;

typedef TElRSAKeyMaterialHandle ElRSAKeyMaterialHandle;

typedef TElClassHandle TElRSAPublicKeyCryptoHandle;

typedef TElRSAPublicKeyCryptoHandle ElRSAPublicKeyCryptoHandle;

typedef TElClassHandle TElDSAKeyMaterialHandle;

typedef TElDSAKeyMaterialHandle ElDSAKeyMaterialHandle;

typedef TElClassHandle TElDSAPublicKeyCryptoHandle;

typedef TElDSAPublicKeyCryptoHandle ElDSAPublicKeyCryptoHandle;

typedef TElClassHandle TElECKeyMaterialHandle;

typedef TElClassHandle TElECDSAPublicKeyCryptoHandle;

typedef TElClassHandle TElECDHPublicKeyCryptoHandle;

typedef TElClassHandle TElDHKeyMaterialHandle;

typedef TElDHKeyMaterialHandle ElDHKeyMaterialHandle;

typedef TElClassHandle TElDHPublicKeyCryptoHandle;

typedef TElDHPublicKeyCryptoHandle ElDHPublicKeyCryptoHandle;

typedef TElClassHandle TElElGamalKeyMaterialHandle;

typedef TElElGamalKeyMaterialHandle ElElGamalKeyMaterialHandle;

typedef TElClassHandle TElElGamalPublicKeyCryptoHandle;

typedef TElElGamalPublicKeyCryptoHandle ElElGamalPublicKeyCryptoHandle;

typedef TElClassHandle TElSRPKeyMaterialHandle;

typedef TElClassHandle TElSRPPublicKeyCryptoHandle;

typedef TElClassHandle TElGOST94KeyMaterialHandle;

typedef TElGOST94KeyMaterialHandle ElGOST94KeyMaterialHandle;

typedef TElClassHandle TElGOST94PublicKeyCryptoHandle;

typedef TElGOST94PublicKeyCryptoHandle ElGOST94PublicKeyCryptoHandle;

typedef TElClassHandle TElGOST2001KeyMaterialHandle;

typedef TElGOST2001KeyMaterialHandle ElGOST2001KeyMaterialHandle;

typedef TElClassHandle TElGOST2001PublicKeyCryptoHandle;

typedef TElGOST2001PublicKeyCryptoHandle ElGOST2001PublicKeyCryptoHandle;

typedef TElClassHandle TElPublicKeyCryptoFactoryHandle;

typedef TElPublicKeyCryptoFactoryHandle ElPublicKeyCryptoFactoryHandle;

typedef TElClassHandle TElRemoteSigningParamsHandle;

typedef void (SB_CALLBACK *TSBAsyncOperationFinishedEvent)(void * _ObjectData, TObjectHandle Sender, int8_t Success);

typedef uint8_t TSBKeyStoreFormatRaw;

typedef enum
{
	ksfRaw = 0,
	ksfPKCS8 = 1
} TSBKeyStoreFormat;

typedef uint8_t TSBPublicKeyOperationRaw;

typedef enum
{
	_pkoEncrypt = 0,
	_pkoDecrypt = 1,
	_pkoSign = 2,
	_pkoSignDetached = 3,
	_pkoVerify = 4,
	_pkoVerifyDetached = 5,
	pkoDecryptKey = 6
} TSBPublicKeyOperation;

typedef uint8_t TSBPublicKeyVerificationResultRaw;

typedef enum
{
	pkvrSuccess = 0,
	pkvrInvalidSignature = 1,
	pkvrKeyNotFound = 2,
	pkvrFailure = 3
} TSBPublicKeyVerificationResult;

typedef uint8_t TSBPublicKeyCryptoEncodingRaw;

typedef enum
{
	pkeBinary = 0,
	pkeBase64 = 1
} TSBPublicKeyCryptoEncoding;

typedef TElClassHandle TElPublicKeyCryptoClassHandle;

typedef TElPublicKeyCryptoClassHandle ElPublicKeyCryptoClassHandle;

typedef uint8_t TSBRSAKeyFormatRaw;

typedef enum
{
	_rsaPKCS1 = 0,
	_rsaOAEP = 1,
	_rsaPSS = 2,
	rsaX509 = 3
} TSBRSAKeyFormat;

typedef uint8_t TSBRSAPublicKeyCryptoTypeRaw;

typedef enum
{
	_rsapktPKCS1 = 0,
	_rsapktOAEP = 1,
	_rsapktPSS = 2,
	_rsapktSSL3 = 3
} TSBRSAPublicKeyCryptoType;

typedef uint8_t TSBDSAKeyFormatRaw;

typedef enum
{
	dsaFIPS = 0,
	dsaX509 = 1
} TSBDSAKeyFormat;

typedef uint8_t TSBDHKeyFormatRaw;

typedef enum
{
	dhRaw = 0,
	dhX509 = 1
} TSBDHKeyFormat;

typedef uint8_t TSBDHPublicKeyCryptoTypeRaw;

typedef enum
{
	dhpktPKCS1 = 0,
	dhpktRaw = 1
} TSBDHPublicKeyCryptoType;

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_GetMaxPublicKeySize(TElCustomCryptoProviderHandle Prov, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_GetMaxPublicKeySize_1(TElPublicKeyMaterialHandle _Handle, TElCustomCryptoProviderHandle Prov, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_AssignCryptoKey(TElPublicKeyMaterialHandle _Handle, TElCustomCryptoKeyHandle Key);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_Generate(TElPublicKeyMaterialHandle _Handle, int32_t Bits);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_LoadPublic(TElPublicKeyMaterialHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_LoadPublic_1(TElPublicKeyMaterialHandle _Handle, TStreamHandle Stream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_LoadSecret(TElPublicKeyMaterialHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_LoadSecret_1(TElPublicKeyMaterialHandle _Handle, TStreamHandle Stream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_SavePublic(TElPublicKeyMaterialHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_SavePublic_1(TElPublicKeyMaterialHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_SaveSecret(TElPublicKeyMaterialHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_SaveSecret_1(TElPublicKeyMaterialHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_LoadParameters(TElPublicKeyMaterialHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_SaveParameters(TElPublicKeyMaterialHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_Save(TElPublicKeyMaterialHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_Load(TElPublicKeyMaterialHandle _Handle, TStreamHandle Stream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_LoadFromXML(TElPublicKeyMaterialHandle _Handle, const char * pcStr, int32_t szStr);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_SaveToXML(TElPublicKeyMaterialHandle _Handle, int8_t IncludePrivateKey, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_Clone(TElPublicKeyMaterialHandle _Handle, TElKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_Equals(TElPublicKeyMaterialHandle _Handle, TElKeyMaterialHandle Source, int8_t PublicOnly, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_ClearSecret(TElPublicKeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_ClearPublic(TElPublicKeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_Clear(TElPublicKeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_BeginGenerate(TElPublicKeyMaterialHandle _Handle, int32_t Bits);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_EndGenerate(TElPublicKeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_CancelAsyncOperation(TElPublicKeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_PrepareForEncryption(TElPublicKeyMaterialHandle _Handle, int8_t MultiUse);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_PrepareForSigning(TElPublicKeyMaterialHandle _Handle, int8_t MultiUse);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_get_PublicKey(TElPublicKeyMaterialHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_get_SecretKey(TElPublicKeyMaterialHandle _Handle, int8_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_get_CertHandle(TElPublicKeyMaterialHandle _Handle, PCCERT_CONTEXT * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_set_CertHandle(TElPublicKeyMaterialHandle _Handle, PCCERT_CONTEXT Value);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_get_KeyExchangePIN(TElPublicKeyMaterialHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_set_KeyExchangePIN(TElPublicKeyMaterialHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_get_SignaturePIN(TElPublicKeyMaterialHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_set_SignaturePIN(TElPublicKeyMaterialHandle _Handle, const char * pcValue, int32_t szValue);
#endif
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_get_KeyHandle(TElPublicKeyMaterialHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_set_KeyHandle(TElPublicKeyMaterialHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_get_SessionHandle(TElPublicKeyMaterialHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_set_SessionHandle(TElPublicKeyMaterialHandle _Handle, uint32_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_get_CNGKeyHandle(TElPublicKeyMaterialHandle _Handle, uint32_t * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_set_CNGKeyHandle(TElPublicKeyMaterialHandle _Handle, uint32_t * Value);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_get_CNGProvHandle(TElPublicKeyMaterialHandle _Handle, uint32_t * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_set_CNGProvHandle(TElPublicKeyMaterialHandle _Handle, uint32_t * Value);
#endif
#else
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_get_KeyHandle(TElPublicKeyMaterialHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_set_KeyHandle(TElPublicKeyMaterialHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_get_SessionHandle(TElPublicKeyMaterialHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_set_SessionHandle(TElPublicKeyMaterialHandle _Handle, int64_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_get_Busy(TElPublicKeyMaterialHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_get_StoreFormat(TElPublicKeyMaterialHandle _Handle, TSBKeyStoreFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_set_StoreFormat(TElPublicKeyMaterialHandle _Handle, TSBKeyStoreFormatRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_get_AsyncOperationFinished(TElPublicKeyMaterialHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_get_OnAsyncOperationFinished(TElPublicKeyMaterialHandle _Handle, TSBAsyncOperationFinishedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_set_OnAsyncOperationFinished(TElPublicKeyMaterialHandle _Handle, TSBAsyncOperationFinishedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_Create(TElCustomCryptoProviderHandle Prov, TElPublicKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyMaterial_Create_1(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElPublicKeyMaterialHandle * OutResult);
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

#ifdef SB_USE_CLASS_TELPUBLICKEYCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_LoadParameters(TElPublicKeyCryptoHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_SaveParameters(TElPublicKeyCryptoHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_Encrypt(TElPublicKeyCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_Encrypt_1(TElPublicKeyCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_Decrypt(TElPublicKeyCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_Decrypt_1(TElPublicKeyCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_Sign(TElPublicKeyCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_Sign_1(TElPublicKeyCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_SignDetached(TElPublicKeyCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_SignDetached_1(TElPublicKeyCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_Verify(TElPublicKeyCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TSBPublicKeyVerificationResultRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_Verify_1(TElPublicKeyCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int32_t Count, TSBPublicKeyVerificationResultRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_VerifyDetached(TElPublicKeyCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * SigBuffer, int32_t SigSize, TSBPublicKeyVerificationResultRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_VerifyDetached_1(TElPublicKeyCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle SigStream, int32_t InCount, int32_t SigCount, TSBPublicKeyVerificationResultRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_DecryptKey(TElPublicKeyCryptoHandle _Handle, void * EncKey, int32_t EncKeySize, const uint8_t pEncKeyAlgOID[], int32_t szEncKeyAlgOID, const uint8_t pEncKeyAlgParams[], int32_t szEncKeyAlgParams, TElKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_BeginEncrypt(TElPublicKeyCryptoHandle _Handle, void * InBuffer, int32_t InSize);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_BeginEncrypt_1(TElPublicKeyCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_EndEncrypt(TElPublicKeyCryptoHandle _Handle, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_EndEncrypt_1(TElPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_BeginDecrypt(TElPublicKeyCryptoHandle _Handle, void * InBuffer, int32_t InSize);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_BeginDecrypt_1(TElPublicKeyCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_EndDecrypt(TElPublicKeyCryptoHandle _Handle, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_EndDecrypt_1(TElPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_BeginSign(TElPublicKeyCryptoHandle _Handle, void * InBuffer, int32_t InSize);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_BeginSign_1(TElPublicKeyCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_EndSign(TElPublicKeyCryptoHandle _Handle, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_EndSign_1(TElPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_BeginSignDetached(TElPublicKeyCryptoHandle _Handle, void * InBuffer, int32_t InSize);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_BeginSignDetached_1(TElPublicKeyCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_EndSignDetached(TElPublicKeyCryptoHandle _Handle, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_EndSignDetached_1(TElPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_BeginVerify(TElPublicKeyCryptoHandle _Handle, void * InBuffer, int32_t InSize);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_BeginVerify_1(TElPublicKeyCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_EndVerify(TElPublicKeyCryptoHandle _Handle, void * OutBuffer, int32_t * OutSize, TSBPublicKeyVerificationResultRaw * VerificationResult, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_EndVerify_1(TElPublicKeyCryptoHandle _Handle, TSBPublicKeyVerificationResultRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_BeginVerifyDetached(TElPublicKeyCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * SigBuffer, int32_t SigSize);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_BeginVerifyDetached_1(TElPublicKeyCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle SigStream, int32_t InCount, int32_t SigCount);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_EndVerifyDetached(TElPublicKeyCryptoHandle _Handle, TSBPublicKeyVerificationResultRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_CancelAsyncOperation(TElPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_get_KeyMaterial(TElPublicKeyCryptoHandle _Handle, TElPublicKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_set_KeyMaterial(TElPublicKeyCryptoHandle _Handle, TElPublicKeyMaterialHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_get_SupportsEncryption(TElPublicKeyCryptoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_get_SupportsSigning(TElPublicKeyCryptoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_get_InputIsHash(TElPublicKeyCryptoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_set_InputIsHash(TElPublicKeyCryptoHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_get_InputEncoding(TElPublicKeyCryptoHandle _Handle, TSBPublicKeyCryptoEncodingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_set_InputEncoding(TElPublicKeyCryptoHandle _Handle, TSBPublicKeyCryptoEncodingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_get_OutputEncoding(TElPublicKeyCryptoHandle _Handle, TSBPublicKeyCryptoEncodingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_set_OutputEncoding(TElPublicKeyCryptoHandle _Handle, TSBPublicKeyCryptoEncodingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_get_Busy(TElPublicKeyCryptoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_get_HashAlgorithm(TElPublicKeyCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_set_HashAlgorithm(TElPublicKeyCryptoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_get_AsyncOperationFinished(TElPublicKeyCryptoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_get_OnAsyncOperationFinished(TElPublicKeyCryptoHandle _Handle, TSBAsyncOperationFinishedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_set_OnAsyncOperationFinished(TElPublicKeyCryptoHandle _Handle, TSBAsyncOperationFinishedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_Create(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderHandle CryptoProvider, TElPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_Create_1(int32_t Alg, TElCustomCryptoProviderHandle CryptoProvider, TElPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_Create_2(TElCustomCryptoProviderHandle CryptoProvider, TElPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_Create_3(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_Create_4(int32_t Alg, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCrypto_Create_5(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElPublicKeyCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELRSAKEYMATERIAL
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_Assign(TElRSAKeyMaterialHandle _Handle, TElKeyMaterialHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_LoadParameters(TElRSAKeyMaterialHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_SaveParameters(TElRSAKeyMaterialHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_LoadPublic(TElRSAKeyMaterialHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_LoadPublic_1(TElRSAKeyMaterialHandle _Handle, void * Modulus, int32_t ModulusSize, void * Exponent, int32_t ExponentSize);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_LoadSecret(TElRSAKeyMaterialHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_SavePublic(TElRSAKeyMaterialHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_SaveSecret(TElRSAKeyMaterialHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_LoadFromXML(TElRSAKeyMaterialHandle _Handle, const char * pcStr, int32_t szStr);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_SaveToXML(TElRSAKeyMaterialHandle _Handle, int8_t IncludePrivateKey, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_EncodePublicKey(TElRSAKeyMaterialHandle _Handle, void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, const uint8_t pAlgID[], int32_t szAlgID, void * OutBuffer, int32_t * OutSize, int8_t InnerValuesOnly, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_EncodePrivateKey(TElRSAKeyMaterialHandle _Handle, void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * PrivateExponent, int32_t PrivateExponentSize, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_EncodePrivateKey_1(TElRSAKeyMaterialHandle _Handle, void * N, int32_t NSize, void * E, int32_t ESize, void * D, int32_t DSize, void * P, int32_t PSize, void * Q, int32_t QSize, void * DP, int32_t DPSize, void * DQ, int32_t DQSize, void * QInv, int32_t QInvSize, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_EncodePrivateKey_2(TElRSAKeyMaterialHandle _Handle, void * N, int32_t NSize, void * E, int32_t ESize, void * D, int32_t DSize, void * P, int32_t PSize, void * Q, int32_t QSize, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_DecodePrivateKey(TElRSAKeyMaterialHandle _Handle, void * Blob, int32_t BlobSize, void * N, int32_t * NSize, void * E, int32_t * ESize, void * D, int32_t * DSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_DecodePrivateKey_1(TElRSAKeyMaterialHandle _Handle, void * Blob, int32_t BlobSize, void * N, int32_t * NSize, void * E, int32_t * ESize, void * D, int32_t * DSize, void * P, int32_t * PSize, void * Q, int32_t * QSize, void * DP, int32_t * DPSize, void * DQ, int32_t * DQSize, void * QInv, int32_t * QInvSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_WritePSSParams(int32_t HashAlgorithm, int32_t SaltSize, int32_t MGFAlgorithm, int32_t TrailerField, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_WritePSSParams_1(TElRSAKeyMaterialHandle _Handle, int32_t HashAlgorithm, int32_t SaltSize, int32_t MGFAlgorithm, int32_t TrailerField, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_ReadPSSParams(void * InBuffer, int32_t InBufferSize, int32_t * HashAlgorithm, int32_t * SaltSize, int32_t * MGF, int32_t * MGFHashAlgorithm, int32_t * TrailerField, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_ReadPSSParams_1(TElRSAKeyMaterialHandle _Handle, void * InBuffer, int32_t InBufferSize, int32_t * HashAlgorithm, int32_t * SaltSize, int32_t * MGF, int32_t * MGFHashAlgorithm, int32_t * TrailerField, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_WriteOAEPParams(int32_t HashAlgorithm, int32_t MGFHashAlgorithm, const char * pcStrLabel, int32_t szStrLabel, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_WriteOAEPParams_1(TElRSAKeyMaterialHandle _Handle, int32_t HashAlgorithm, int32_t MGFHashAlgorithm, const char * pcStrLabel, int32_t szStrLabel, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_ReadOAEPParams(void * InBuffer, int32_t InBufferSize, int32_t * HashAlgorithm, int32_t * MGFHashAlgorithm, char * pcStrLabel, int32_t * szStrLabel, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_ReadOAEPParams_1(TElRSAKeyMaterialHandle _Handle, void * InBuffer, int32_t InBufferSize, int32_t * HashAlgorithm, int32_t * MGFHashAlgorithm, char * pcStrLabel, int32_t * szStrLabel, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_Clone(TElRSAKeyMaterialHandle _Handle, TElKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_Equals(TElRSAKeyMaterialHandle _Handle, TElKeyMaterialHandle Source, int8_t PublicOnly, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_ClearSecret(TElRSAKeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_ClearPublic(TElRSAKeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_get_KeyFormat(TElRSAKeyMaterialHandle _Handle, TSBRSAKeyFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_set_KeyFormat(TElRSAKeyMaterialHandle _Handle, TSBRSAKeyFormatRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_get_Passphrase(TElRSAKeyMaterialHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_set_Passphrase(TElRSAKeyMaterialHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_get_PEMEncode(TElRSAKeyMaterialHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_set_PEMEncode(TElRSAKeyMaterialHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_get_StrLabel(TElRSAKeyMaterialHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_set_StrLabel(TElRSAKeyMaterialHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_get_SaltSize(TElRSAKeyMaterialHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_set_SaltSize(TElRSAKeyMaterialHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_get_MGFAlgorithm(TElRSAKeyMaterialHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_set_MGFAlgorithm(TElRSAKeyMaterialHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_get_TrailerField(TElRSAKeyMaterialHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_set_TrailerField(TElRSAKeyMaterialHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_get_HashAlgorithm(TElRSAKeyMaterialHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_set_HashAlgorithm(TElRSAKeyMaterialHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_get_RawPublicKey(TElRSAKeyMaterialHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_set_RawPublicKey(TElRSAKeyMaterialHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_get_PublicModulus(TElRSAKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_get_PublicExponent(TElRSAKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_get_PrivateExponent(TElRSAKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_Create(TElCustomCryptoProviderHandle Prov, TElRSAKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAKeyMaterial_Create_1(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElRSAKeyMaterialHandle * OutResult);
#endif /* SB_USE_CLASS_TELRSAKEYMATERIAL */

#ifdef SB_USE_CLASS_TELRSAPUBLICKEYCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_LoadParameters(TElRSAPublicKeyCryptoHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_SaveParameters(TElRSAPublicKeyCryptoHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_DecryptKey(TElRSAPublicKeyCryptoHandle _Handle, void * EncKey, int32_t EncKeySize, const uint8_t pEncKeyAlgOID[], int32_t szEncKeyAlgOID, const uint8_t pEncKeyAlgParams[], int32_t szEncKeyAlgParams, TElKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_get_CryptoType(TElRSAPublicKeyCryptoHandle _Handle, TSBRSAPublicKeyCryptoTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_set_CryptoType(TElRSAPublicKeyCryptoHandle _Handle, TSBRSAPublicKeyCryptoTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_get_UseAlgorithmPrefix(TElRSAPublicKeyCryptoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_set_UseAlgorithmPrefix(TElRSAPublicKeyCryptoHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_get_HashFuncOID(TElRSAPublicKeyCryptoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_set_HashFuncOID(TElRSAPublicKeyCryptoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_get_SaltSize(TElRSAPublicKeyCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_set_SaltSize(TElRSAPublicKeyCryptoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_get_StrLabel(TElRSAPublicKeyCryptoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_set_StrLabel(TElRSAPublicKeyCryptoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_get_TrailerField(TElRSAPublicKeyCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_set_TrailerField(TElRSAPublicKeyCryptoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_get_MGFAlgorithm(TElRSAPublicKeyCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_set_MGFAlgorithm(TElRSAPublicKeyCryptoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_Create(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderHandle CryptoProvider, TElRSAPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_Create_1(int32_t Alg, TElCustomCryptoProviderHandle CryptoProvider, TElRSAPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_Create_2(TElCustomCryptoProviderHandle CryptoProvider, TElRSAPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_Create_3(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElRSAPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_Create_4(int32_t Alg, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElRSAPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPublicKeyCrypto_Create_5(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElRSAPublicKeyCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELRSAPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELDSAKEYMATERIAL
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_Assign(TElDSAKeyMaterialHandle _Handle, TElKeyMaterialHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_LoadParameters(TElDSAKeyMaterialHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_SaveParameters(TElDSAKeyMaterialHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_Generate(TElDSAKeyMaterialHandle _Handle, int32_t Bits);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_Generate_1(TElDSAKeyMaterialHandle _Handle, int32_t PBits, int32_t QBits);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_BeginGenerate(TElDSAKeyMaterialHandle _Handle, int32_t PBits, int32_t QBits);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_LoadSecret(TElDSAKeyMaterialHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_SaveSecret(TElDSAKeyMaterialHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_LoadPublic(TElDSAKeyMaterialHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_SavePublic(TElDSAKeyMaterialHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_ImportPublicKey(TElDSAKeyMaterialHandle _Handle, void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * Y, int32_t YSize);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_ExportPublicKey(TElDSAKeyMaterialHandle _Handle, void * P, int32_t * PSize, void * Q, int32_t * QSize, void * G, int32_t * GSize, void * Y, int32_t * YSize);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_LoadFromXML(TElDSAKeyMaterialHandle _Handle, const char * pcStr, int32_t szStr);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_SaveToXML(TElDSAKeyMaterialHandle _Handle, int8_t IncludePrivateKey, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_EncodePrivateKey(TElDSAKeyMaterialHandle _Handle, void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * Y, int32_t YSize, void * X, int32_t XSize, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_DecodePrivateKey(TElDSAKeyMaterialHandle _Handle, void * Blob, int32_t BlobSize, void * P, int32_t * PSize, void * Q, int32_t * QSize, void * G, int32_t * GSize, void * Y, int32_t * YSize, void * X, int32_t * XSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_Clone(TElDSAKeyMaterialHandle _Handle, TElKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_Equals(TElDSAKeyMaterialHandle _Handle, TElKeyMaterialHandle Source, int8_t PublicOnly, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_ClearSecret(TElDSAKeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_ClearPublic(TElDSAKeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_get_KeyFormat(TElDSAKeyMaterialHandle _Handle, TSBDSAKeyFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_get_QBits(TElDSAKeyMaterialHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_get_HashAlgorithm(TElDSAKeyMaterialHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_set_HashAlgorithm(TElDSAKeyMaterialHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_get_Passphrase(TElDSAKeyMaterialHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_set_Passphrase(TElDSAKeyMaterialHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_get_PEMEncode(TElDSAKeyMaterialHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_set_PEMEncode(TElDSAKeyMaterialHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_get_StrictKeyValidation(TElDSAKeyMaterialHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_set_StrictKeyValidation(TElDSAKeyMaterialHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_get_P(TElDSAKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_set_P(TElDSAKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_get_Q(TElDSAKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_set_Q(TElDSAKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_get_G(TElDSAKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_set_G(TElDSAKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_get_Y(TElDSAKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_set_Y(TElDSAKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_get_X(TElDSAKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_set_X(TElDSAKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_Create(TElCustomCryptoProviderHandle Prov, TElDSAKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAKeyMaterial_Create_1(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElDSAKeyMaterialHandle * OutResult);
#endif /* SB_USE_CLASS_TELDSAKEYMATERIAL */

#ifdef SB_USE_CLASS_TELDSAPUBLICKEYCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElDSAPublicKeyCrypto_LoadParameters(TElDSAPublicKeyCryptoHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElDSAPublicKeyCrypto_SaveParameters(TElDSAPublicKeyCryptoHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElDSAPublicKeyCrypto_EncodeSignature(TElDSAPublicKeyCryptoHandle _Handle, void * R, int32_t RSize, void * S, int32_t SSize, void * Sig, int32_t * SigSize);
SB_IMPORT uint32_t SB_APIENTRY TElDSAPublicKeyCrypto_DecodeSignature(TElDSAPublicKeyCryptoHandle _Handle, void * Sig, int32_t SigSize, void * R, int32_t * RSize, void * S, int32_t * SSize);
SB_IMPORT uint32_t SB_APIENTRY TElDSAPublicKeyCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAPublicKeyCrypto_Create(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderHandle CryptoProvider, TElDSAPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAPublicKeyCrypto_Create_1(int32_t Alg, TElCustomCryptoProviderHandle CryptoProvider, TElDSAPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAPublicKeyCrypto_Create_2(TElCustomCryptoProviderHandle CryptoProvider, TElDSAPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAPublicKeyCrypto_Create_3(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElDSAPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAPublicKeyCrypto_Create_4(int32_t Alg, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElDSAPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAPublicKeyCrypto_Create_5(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElDSAPublicKeyCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELDSAPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELECKEYMATERIAL
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_Assign(TElECKeyMaterialHandle _Handle, TElKeyMaterialHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_Generate(TElECKeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_LoadParameters(TElECKeyMaterialHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_SaveParameters(TElECKeyMaterialHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_LoadSecret(TElECKeyMaterialHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_SaveSecret(TElECKeyMaterialHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_LoadPublic(TElECKeyMaterialHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_SavePublic(TElECKeyMaterialHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_ImportPublicKey(TElECKeyMaterialHandle _Handle, void * QX, int32_t QXSize, void * QY, int32_t QYSize);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_ExportPublicKey(TElECKeyMaterialHandle _Handle, void * QX, int32_t * QXSize, void * QY, int32_t * QYSize);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_Clone(TElECKeyMaterialHandle _Handle, TElKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_Equals(TElECKeyMaterialHandle _Handle, TElKeyMaterialHandle Source, int8_t PublicOnly, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_ClearSecret(TElECKeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_ClearPublic(TElECKeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_EncodePrivateKey(TElECKeyMaterialHandle _Handle, void * D, int32_t DSize, void * Qx, int32_t QxSize, void * Qy, int32_t QySize, int32_t Curve, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_DecodePrivateKey(TElECKeyMaterialHandle _Handle, void * Blob, int32_t BlobSize, void * D, int32_t * DSize, void * Qx, int32_t * QxSize, void * Qy, int32_t * QySize, int32_t * Curve, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_CompressPoints(TElECKeyMaterialHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_CompressPoints(TElECKeyMaterialHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_HybridPoints(TElECKeyMaterialHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_HybridPoints(TElECKeyMaterialHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_FieldType(TElECKeyMaterialHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_FieldType(TElECKeyMaterialHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_Field(TElECKeyMaterialHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_FieldBits(TElECKeyMaterialHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_M(TElECKeyMaterialHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_M(TElECKeyMaterialHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_K1(TElECKeyMaterialHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_K1(TElECKeyMaterialHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_K2(TElECKeyMaterialHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_K2(TElECKeyMaterialHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_K3(TElECKeyMaterialHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_K3(TElECKeyMaterialHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_HashAlgorithm(TElECKeyMaterialHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_HashAlgorithm(TElECKeyMaterialHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_RecommendedHashAlgorithm(TElECKeyMaterialHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_D(TElECKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_D(TElECKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_N(TElECKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_N(TElECKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_H(TElECKeyMaterialHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_H(TElECKeyMaterialHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_A(TElECKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_A(TElECKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_B(TElECKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_B(TElECKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_X(TElECKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_X(TElECKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_Y(TElECKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_Y(TElECKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_Q(TElECKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_Q(TElECKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_QX(TElECKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_QX(TElECKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_QY(TElECKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_QY(TElECKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_Base(TElECKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_Base(TElECKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_P(TElECKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_P(TElECKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_Curve(TElECKeyMaterialHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_Curve(TElECKeyMaterialHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_CurveOID(TElECKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_CurveOID(TElECKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_SpecifiedCurve(TElECKeyMaterialHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_SpecifiedCurve(TElECKeyMaterialHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_ImplicitCurve(TElECKeyMaterialHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_ImplicitCurve(TElECKeyMaterialHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_get_Seed(TElECKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_set_Seed(TElECKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_Create(TElCustomCryptoProviderHandle Prov, TElECKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECKeyMaterial_Create_1(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElECKeyMaterialHandle * OutResult);
#endif /* SB_USE_CLASS_TELECKEYMATERIAL */

#ifdef SB_USE_CLASS_TELECDSAPUBLICKEYCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElECDSAPublicKeyCrypto_LoadParameters(TElECDSAPublicKeyCryptoHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElECDSAPublicKeyCrypto_SaveParameters(TElECDSAPublicKeyCryptoHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElECDSAPublicKeyCrypto_EncodeSignature(TElECDSAPublicKeyCryptoHandle _Handle, void * R, int32_t RSize, void * S, int32_t SSize, void * Sig, int32_t * SigSize);
SB_IMPORT uint32_t SB_APIENTRY TElECDSAPublicKeyCrypto_DecodeSignature(TElECDSAPublicKeyCryptoHandle _Handle, void * Sig, int32_t SigSize, void * R, int32_t * RSize, void * S, int32_t * SSize);
SB_IMPORT uint32_t SB_APIENTRY TElECDSAPublicKeyCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDSAPublicKeyCrypto_Create(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderHandle CryptoProvider, TElECDSAPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDSAPublicKeyCrypto_Create_1(int32_t Alg, TElCustomCryptoProviderHandle CryptoProvider, TElECDSAPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDSAPublicKeyCrypto_Create_2(TElCustomCryptoProviderHandle CryptoProvider, TElECDSAPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDSAPublicKeyCrypto_Create_3(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElECDSAPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDSAPublicKeyCrypto_Create_4(int32_t Alg, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElECDSAPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDSAPublicKeyCrypto_Create_5(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElECDSAPublicKeyCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELECDSAPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELECDHPUBLICKEYCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElECDHPublicKeyCrypto_LoadParameters(TElECDHPublicKeyCryptoHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElECDHPublicKeyCrypto_SaveParameters(TElECDHPublicKeyCryptoHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElECDHPublicKeyCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDHPublicKeyCrypto_Create(TElCustomCryptoProviderHandle CryptoProvider, TElECDHPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDHPublicKeyCrypto_Create_1(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderHandle CryptoProvider, TElECDHPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDHPublicKeyCrypto_Create_2(int32_t Alg, TElCustomCryptoProviderHandle CryptoProvider, TElECDHPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDHPublicKeyCrypto_Create_3(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElECDHPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDHPublicKeyCrypto_Create_4(int32_t Alg, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElECDHPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDHPublicKeyCrypto_Create_5(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElECDHPublicKeyCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELECDHPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELDHKEYMATERIAL
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_LoadParameters(TElDHKeyMaterialHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_SaveParameters(TElDHKeyMaterialHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_LoadPublic(TElDHKeyMaterialHandle _Handle, void * P, int32_t PSize, void * G, int32_t GSize, void * Y, int32_t YSize);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_SavePublic(TElDHKeyMaterialHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_SaveSecret(TElDHKeyMaterialHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_LoadSecret(TElDHKeyMaterialHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_LoadPeerY(TElDHKeyMaterialHandle _Handle, void * Y, int32_t YSize);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_LoadFromXML(TElDHKeyMaterialHandle _Handle, const char * pcStr, int32_t szStr);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_SaveToXML(TElDHKeyMaterialHandle _Handle, int8_t IncludePrivateKey, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_Assign(TElDHKeyMaterialHandle _Handle, TElKeyMaterialHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_Clone(TElDHKeyMaterialHandle _Handle, TElKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_Equals(TElDHKeyMaterialHandle _Handle, TElKeyMaterialHandle Source, int8_t PublicOnly, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_ClearSecret(TElDHKeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_ClearPublic(TElDHKeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_get_KeyFormat(TElDHKeyMaterialHandle _Handle, TSBDHKeyFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_get_P(TElDHKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_set_P(TElDHKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_get_G(TElDHKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_set_G(TElDHKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_get_X(TElDHKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_set_X(TElDHKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_get_Y(TElDHKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_set_Y(TElDHKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_get_PeerY(TElDHKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_set_PeerY(TElDHKeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_get_PreserveGroupParameters(TElDHKeyMaterialHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_set_PreserveGroupParameters(TElDHKeyMaterialHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_Create(TElCustomCryptoProviderHandle Prov, TElDHKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDHKeyMaterial_Create_1(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElDHKeyMaterialHandle * OutResult);
#endif /* SB_USE_CLASS_TELDHKEYMATERIAL */

#ifdef SB_USE_CLASS_TELDHPUBLICKEYCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElDHPublicKeyCrypto_LoadParameters(TElDHPublicKeyCryptoHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElDHPublicKeyCrypto_SaveParameters(TElDHPublicKeyCryptoHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElDHPublicKeyCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDHPublicKeyCrypto_get_CryptoType(TElDHPublicKeyCryptoHandle _Handle, TSBDHPublicKeyCryptoTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDHPublicKeyCrypto_set_CryptoType(TElDHPublicKeyCryptoHandle _Handle, TSBDHPublicKeyCryptoTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElDHPublicKeyCrypto_Create(TElCustomCryptoProviderHandle CryptoProvider, TElDHPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDHPublicKeyCrypto_Create_1(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderHandle CryptoProvider, TElDHPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDHPublicKeyCrypto_Create_2(int32_t Alg, TElCustomCryptoProviderHandle CryptoProvider, TElDHPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDHPublicKeyCrypto_Create_3(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElDHPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDHPublicKeyCrypto_Create_4(int32_t Alg, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElDHPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDHPublicKeyCrypto_Create_5(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElDHPublicKeyCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELDHPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELELGAMALKEYMATERIAL
SB_IMPORT uint32_t SB_APIENTRY TElElGamalKeyMaterial_Assign(TElElGamalKeyMaterialHandle _Handle, TElKeyMaterialHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalKeyMaterial_Clone(TElElGamalKeyMaterialHandle _Handle, TElKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalKeyMaterial_LoadPublic(TElElGamalKeyMaterialHandle _Handle, void * P, int32_t PSize, void * G, int32_t GSize, void * Y, int32_t YSize);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalKeyMaterial_LoadSecret(TElElGamalKeyMaterialHandle _Handle, void * P, int32_t PSize, void * G, int32_t GSize, void * Y, int32_t YSize, void * X, int32_t XSize);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalKeyMaterial_SavePublic(TElElGamalKeyMaterialHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalKeyMaterial_SaveSecret(TElElGamalKeyMaterialHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalKeyMaterial_LoadFromXML(TElElGamalKeyMaterialHandle _Handle, const char * pcStr, int32_t szStr);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalKeyMaterial_SaveToXML(TElElGamalKeyMaterialHandle _Handle, int8_t IncludePrivateKey, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalKeyMaterial_Equals(TElElGamalKeyMaterialHandle _Handle, TElKeyMaterialHandle Source, int8_t PublicOnly, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalKeyMaterial_ClearSecret(TElElGamalKeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalKeyMaterial_ClearPublic(TElElGamalKeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalKeyMaterial_get_P(TElElGamalKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalKeyMaterial_get_G(TElElGamalKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalKeyMaterial_get_Y(TElElGamalKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalKeyMaterial_get_X(TElElGamalKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalKeyMaterial_Create(TElCustomCryptoProviderHandle Prov, TElElGamalKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalKeyMaterial_Create_1(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElElGamalKeyMaterialHandle * OutResult);
#endif /* SB_USE_CLASS_TELELGAMALKEYMATERIAL */

#ifdef SB_USE_CLASS_TELELGAMALPUBLICKEYCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElElGamalPublicKeyCrypto_EncodeResult(TElElGamalPublicKeyCryptoHandle _Handle, void * A, int32_t ASize, void * B, int32_t BSize, void * Blob, int32_t * BlobSize);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalPublicKeyCrypto_DecodeResult(TElElGamalPublicKeyCryptoHandle _Handle, void * Blob, int32_t BlobSize, void * A, int32_t * ASize, void * B, int32_t * BSize);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalPublicKeyCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalPublicKeyCrypto_Create(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderHandle CryptoProvider, TElElGamalPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalPublicKeyCrypto_Create_1(int32_t Alg, TElCustomCryptoProviderHandle CryptoProvider, TElElGamalPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalPublicKeyCrypto_Create_2(TElCustomCryptoProviderHandle CryptoProvider, TElElGamalPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalPublicKeyCrypto_Create_3(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElElGamalPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalPublicKeyCrypto_Create_4(int32_t Alg, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElElGamalPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElElGamalPublicKeyCrypto_Create_5(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElElGamalPublicKeyCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELELGAMALPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELSRPKEYMATERIAL
SB_IMPORT uint32_t SB_APIENTRY TElSRPKeyMaterial_Assign(TElSRPKeyMaterialHandle _Handle, TElKeyMaterialHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSRPKeyMaterial_LoadPublic(TElSRPKeyMaterialHandle _Handle, const uint8_t pN[], int32_t szN, const uint8_t pG[], int32_t szG, const uint8_t pSalt[], int32_t szSalt, const uint8_t pV[], int32_t szV, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPKeyMaterial_LoadPublic_1(TElSRPKeyMaterialHandle _Handle, void * Buffer, int32_t Len, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPKeyMaterial_LoadPublicValues(TElSRPKeyMaterialHandle _Handle, const uint8_t pN[], int32_t szN, const uint8_t pg[], int32_t szg, const uint8_t ps[], int32_t szs, const uint8_t pB[], int32_t szB);
SB_IMPORT uint32_t SB_APIENTRY TElSRPKeyMaterial_LoadVerifier(TElSRPKeyMaterialHandle _Handle, const uint8_t pN[], int32_t szN, const uint8_t pg[], int32_t szg, const uint8_t ps[], int32_t szs, const uint8_t pV[], int32_t szV);
SB_IMPORT uint32_t SB_APIENTRY TElSRPKeyMaterial_LoadClientPublicValue(TElSRPKeyMaterialHandle _Handle, const uint8_t pA[], int32_t szA);
SB_IMPORT uint32_t SB_APIENTRY TElSRPKeyMaterial_PrepareServerKeyParam(TElSRPKeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSRPKeyMaterial_Clone(TElSRPKeyMaterialHandle _Handle, TElKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPKeyMaterial_get_Salt(TElSRPKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPKeyMaterial_get_N(TElSRPKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPKeyMaterial_get_G(TElSRPKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPKeyMaterial_get_X(TElSRPKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPKeyMaterial_get_A(TElSRPKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPKeyMaterial_get_K(TElSRPKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPKeyMaterial_get_A_small(TElSRPKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPKeyMaterial_get_B(TElSRPKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPKeyMaterial_get_B_small(TElSRPKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPKeyMaterial_get_V(TElSRPKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPKeyMaterial_get_U(TElSRPKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPKeyMaterial_get_S(TElSRPKeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPKeyMaterial_Create(TElCustomCryptoProviderHandle Prov, TElSRPKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPKeyMaterial_Create_1(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElSRPKeyMaterialHandle * OutResult);
#endif /* SB_USE_CLASS_TELSRPKEYMATERIAL */

#ifdef SB_USE_CLASS_TELSRPPUBLICKEYCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElSRPPublicKeyCrypto_GetServerKey(TElSRPPublicKeyCryptoHandle _Handle, uint8_t pPMS[], int32_t * szPMS);
SB_IMPORT uint32_t SB_APIENTRY TElSRPPublicKeyCrypto_GetClientKeyParam(TElSRPPublicKeyCryptoHandle _Handle, const char * pcUserName, int32_t szUserName, const char * pcUserPassword, int32_t szUserPassword, uint8_t pEncPMS[], int32_t * szEncPMS);
SB_IMPORT uint32_t SB_APIENTRY TElSRPPublicKeyCrypto_GetServerKeyParam(TElSRPPublicKeyCryptoHandle _Handle, uint8_t pEncPMS[], int32_t * szEncPMS);
SB_IMPORT uint32_t SB_APIENTRY TElSRPPublicKeyCrypto_IsTrustedPrime(const uint8_t pN[], int32_t szN, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPPublicKeyCrypto_IsTrustedPrime_1(TElSRPPublicKeyCryptoHandle _Handle, const uint8_t pN[], int32_t szN, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPPublicKeyCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPPublicKeyCrypto_Create(TElCustomCryptoProviderHandle CryptoProvider, TElSRPPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPPublicKeyCrypto_Create_1(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderHandle CryptoProvider, TElSRPPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPPublicKeyCrypto_Create_2(int32_t Alg, TElCustomCryptoProviderHandle CryptoProvider, TElSRPPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPPublicKeyCrypto_Create_3(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElSRPPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPPublicKeyCrypto_Create_4(int32_t Alg, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElSRPPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPPublicKeyCrypto_Create_5(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElSRPPublicKeyCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELSRPPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELGOST94KEYMATERIAL
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_Assign(TElGOST94KeyMaterialHandle _Handle, TElKeyMaterialHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_Clone(TElGOST94KeyMaterialHandle _Handle, TElKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_LoadSecret(TElGOST94KeyMaterialHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_LoadSecret_1(TElGOST94KeyMaterialHandle _Handle, void * P, int32_t PSize, void * Q, int32_t QSize, void * A, int32_t ASize, void * Y, int32_t YSize, void * X, int32_t XSize);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_LoadSecret_2(TElGOST94KeyMaterialHandle _Handle, const uint8_t pP[], int32_t szP, int32_t PIndex, int32_t PSize, const uint8_t pQ[], int32_t szQ, int32_t QIndex, int32_t QSize, const uint8_t pA[], int32_t szA, int32_t AIndex, int32_t ASize, const uint8_t pY[], int32_t szY, int32_t YIndex, int32_t YSize, const uint8_t pX[], int32_t szX, int32_t XIndex, int32_t XSize);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_SaveSecret(TElGOST94KeyMaterialHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_LoadPublic(TElGOST94KeyMaterialHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_LoadPublic_1(TElGOST94KeyMaterialHandle _Handle, void * P, int32_t PSize, void * Q, int32_t QSize, void * A, int32_t ASize, void * Y, int32_t YSize);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_LoadPublic_2(TElGOST94KeyMaterialHandle _Handle, const uint8_t pP[], int32_t szP, int32_t PIndex, int32_t PSize, const uint8_t pQ[], int32_t szQ, int32_t QIndex, int32_t QSize, const uint8_t pA[], int32_t szA, int32_t AIndex, int32_t ASize, const uint8_t pY[], int32_t szY, int32_t YIndex, int32_t YSize);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_SavePublic(TElGOST94KeyMaterialHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_LoadFromXML(TElGOST94KeyMaterialHandle _Handle, const char * pcStr, int32_t szStr);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_SaveToXML(TElGOST94KeyMaterialHandle _Handle, int8_t IncludePrivateKey, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_Equals(TElGOST94KeyMaterialHandle _Handle, TElKeyMaterialHandle Source, int8_t PublicOnly, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_ClearSecret(TElGOST94KeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_ClearPublic(TElGOST94KeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_LoadParameters(TElGOST94KeyMaterialHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_SaveParameters(TElGOST94KeyMaterialHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_get_P(TElGOST94KeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_get_Q(TElGOST94KeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_get_A(TElGOST94KeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_get_Y(TElGOST94KeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_set_Y(TElGOST94KeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_get_X(TElGOST94KeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_set_X(TElGOST94KeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_get_ParamSet(TElGOST94KeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_set_ParamSet(TElGOST94KeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_get_DigestParamSet(TElGOST94KeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_set_DigestParamSet(TElGOST94KeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_get_EncryptionParamSet(TElGOST94KeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_set_EncryptionParamSet(TElGOST94KeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_Create(TElCustomCryptoProviderHandle Prov, TElGOST94KeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94KeyMaterial_Create_1(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElGOST94KeyMaterialHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOST94KEYMATERIAL */

#ifdef SB_USE_CLASS_TELGOST94PUBLICKEYCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElGOST94PublicKeyCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94PublicKeyCrypto_Create(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderHandle CryptoProvider, TElGOST94PublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94PublicKeyCrypto_Create_1(int32_t Alg, TElCustomCryptoProviderHandle CryptoProvider, TElGOST94PublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94PublicKeyCrypto_Create_2(TElCustomCryptoProviderHandle CryptoProvider, TElGOST94PublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94PublicKeyCrypto_Create_3(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElGOST94PublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94PublicKeyCrypto_Create_4(int32_t Alg, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElGOST94PublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST94PublicKeyCrypto_Create_5(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElGOST94PublicKeyCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOST94PUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELGOST2001KEYMATERIAL
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_Assign(TElGOST2001KeyMaterialHandle _Handle, TElKeyMaterialHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_Generate(TElGOST2001KeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_LoadParameters(TElGOST2001KeyMaterialHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_SaveParameters(TElGOST2001KeyMaterialHandle _Handle, TElAlgorithmIdentifierHandle AlgorithmIdentifier);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_LoadSecret(TElGOST2001KeyMaterialHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_SaveSecret(TElGOST2001KeyMaterialHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_LoadPublic(TElGOST2001KeyMaterialHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_SavePublic(TElGOST2001KeyMaterialHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_Clone(TElGOST2001KeyMaterialHandle _Handle, TElKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_Equals(TElGOST2001KeyMaterialHandle _Handle, TElKeyMaterialHandle Source, int8_t PublicOnly, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_ClearSecret(TElGOST2001KeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_ClearPublic(TElGOST2001KeyMaterialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_get_Q(TElGOST2001KeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_set_Q(TElGOST2001KeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_get_D(TElGOST2001KeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_set_D(TElGOST2001KeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_get_ParamSet(TElGOST2001KeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_set_ParamSet(TElGOST2001KeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_get_DigestParamSet(TElGOST2001KeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_set_DigestParamSet(TElGOST2001KeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_get_EncryptionParamSet(TElGOST2001KeyMaterialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_set_EncryptionParamSet(TElGOST2001KeyMaterialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_Create(TElCustomCryptoProviderHandle Prov, TElGOST2001KeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001KeyMaterial_Create_1(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElGOST2001KeyMaterialHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOST2001KEYMATERIAL */

#ifdef SB_USE_CLASS_TELGOST2001PUBLICKEYCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001PublicKeyCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001PublicKeyCrypto_get_UKM(TElGOST2001PublicKeyCryptoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001PublicKeyCrypto_set_UKM(TElGOST2001PublicKeyCryptoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001PublicKeyCrypto_get_CEKMAC(TElGOST2001PublicKeyCryptoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001PublicKeyCrypto_set_CEKMAC(TElGOST2001PublicKeyCryptoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001PublicKeyCrypto_get_EphemeralKey(TElGOST2001PublicKeyCryptoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001PublicKeyCrypto_set_EphemeralKey(TElGOST2001PublicKeyCryptoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001PublicKeyCrypto_Create(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderHandle CryptoProvider, TElGOST2001PublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001PublicKeyCrypto_Create_1(int32_t Alg, TElCustomCryptoProviderHandle CryptoProvider, TElGOST2001PublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001PublicKeyCrypto_Create_2(TElCustomCryptoProviderHandle CryptoProvider, TElGOST2001PublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001PublicKeyCrypto_Create_3(const uint8_t pOID[], int32_t szOID, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElGOST2001PublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001PublicKeyCrypto_Create_4(int32_t Alg, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElGOST2001PublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST2001PublicKeyCrypto_Create_5(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElGOST2001PublicKeyCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOST2001PUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELPUBLICKEYCRYPTOFACTORY
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCryptoFactory_CreateKeyInstance(TElPublicKeyCryptoFactoryHandle _Handle, void * Buffer, int32_t Size, const char * pcPassword, int32_t szPassword, TElPublicKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCryptoFactory_CreateKeyInstance_1(TElPublicKeyCryptoFactoryHandle _Handle, TStreamHandle Stream, const char * pcPassword, int32_t szPassword, int32_t Count, TElPublicKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCryptoFactory_CreateKeyInstance_2(TElPublicKeyCryptoFactoryHandle _Handle, int32_t Alg, TElPublicKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCryptoFactory_RegisterClass(TElPublicKeyCryptoFactoryHandle _Handle, TElPublicKeyCryptoClassHandle Cls);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCryptoFactory_CreateInstance(TElPublicKeyCryptoFactoryHandle _Handle, const uint8_t pOID[], int32_t szOID, TElPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCryptoFactory_CreateInstance_1(TElPublicKeyCryptoFactoryHandle _Handle, int32_t Alg, TElPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCryptoFactory_IsAlgorithmSupported(TElPublicKeyCryptoFactoryHandle _Handle, const uint8_t pOID[], int32_t szOID, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCryptoFactory_IsAlgorithmSupported_1(TElPublicKeyCryptoFactoryHandle _Handle, int32_t Alg, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCryptoFactory_get_RegisteredClasses(TElPublicKeyCryptoFactoryHandle _Handle, int32_t Index, TElPublicKeyCryptoClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCryptoFactory_get_RegisteredClassCount(TElPublicKeyCryptoFactoryHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCryptoFactory_Create(TElCustomCryptoProviderHandle CryptoProvider, TElPublicKeyCryptoFactoryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyCryptoFactory_Create_1(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElPublicKeyCryptoFactoryHandle * OutResult);
#endif /* SB_USE_CLASS_TELPUBLICKEYCRYPTOFACTORY */

#ifdef SB_USE_CLASS_TELREMOTESIGNINGPARAMS
SB_IMPORT uint32_t SB_APIENTRY TElRemoteSigningParams_get_CertificateIndex(TElRemoteSigningParamsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRemoteSigningParams_set_CertificateIndex(TElRemoteSigningParamsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRemoteSigningParams_get_ExternalHashCalculation(TElRemoteSigningParamsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRemoteSigningParams_set_ExternalHashCalculation(TElRemoteSigningParamsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRemoteSigningParams_get_ECDSACurve(TElRemoteSigningParamsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRemoteSigningParams_set_ECDSACurve(TElRemoteSigningParamsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRemoteSigningParams_get_ECDSACurveOID(TElRemoteSigningParamsHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRemoteSigningParams_set_ECDSACurveOID(TElRemoteSigningParamsHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElRemoteSigningParams_get_ECDSAFieldBits(TElRemoteSigningParamsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRemoteSigningParams_set_ECDSAFieldBits(TElRemoteSigningParamsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRemoteSigningParams_get_DSAQBits(TElRemoteSigningParamsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRemoteSigningParams_set_DSAQBits(TElRemoteSigningParamsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRemoteSigningParams_Create(TElRemoteSigningParamsHandle * OutResult);
#endif /* SB_USE_CLASS_TELREMOTESIGNINGPARAMS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPublicKeyMaterial;
typedef TElPublicKeyMaterial ElPublicKeyMaterial;
class TElPublicKeyCrypto;
typedef TElPublicKeyCrypto ElPublicKeyCrypto;
class TElRSAKeyMaterial;
typedef TElRSAKeyMaterial ElRSAKeyMaterial;
class TElRSAPublicKeyCrypto;
typedef TElRSAPublicKeyCrypto ElRSAPublicKeyCrypto;
class TElDSAKeyMaterial;
typedef TElDSAKeyMaterial ElDSAKeyMaterial;
class TElDSAPublicKeyCrypto;
typedef TElDSAPublicKeyCrypto ElDSAPublicKeyCrypto;
class TElECKeyMaterial;
class TElECDSAPublicKeyCrypto;
class TElECDHPublicKeyCrypto;
class TElDHKeyMaterial;
typedef TElDHKeyMaterial ElDHKeyMaterial;
class TElDHPublicKeyCrypto;
typedef TElDHPublicKeyCrypto ElDHPublicKeyCrypto;
class TElElGamalKeyMaterial;
typedef TElElGamalKeyMaterial ElElGamalKeyMaterial;
class TElElGamalPublicKeyCrypto;
typedef TElElGamalPublicKeyCrypto ElElGamalPublicKeyCrypto;
class TElSRPKeyMaterial;
class TElSRPPublicKeyCrypto;
class TElGOST94KeyMaterial;
typedef TElGOST94KeyMaterial ElGOST94KeyMaterial;
class TElGOST94PublicKeyCrypto;
typedef TElGOST94PublicKeyCrypto ElGOST94PublicKeyCrypto;
class TElGOST2001KeyMaterial;
typedef TElGOST2001KeyMaterial ElGOST2001KeyMaterial;
class TElGOST2001PublicKeyCrypto;
typedef TElGOST2001PublicKeyCrypto ElGOST2001PublicKeyCrypto;
class TElPublicKeyCryptoFactory;
typedef TElPublicKeyCryptoFactory ElPublicKeyCryptoFactory;
class TElRemoteSigningParams;

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
class TElPublicKeyMaterial: public TElKeyMaterial
{
	private:
		SB_DISABLE_COPY(TElPublicKeyMaterial)
	public:
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		static int32_t GetMaxPublicKeySize(TElCustomCryptoProvider &Prov);

		static int32_t GetMaxPublicKeySize(TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		int32_t GetMaxPublicKeySize_Inst(TElCustomCryptoProvider &Prov);

		int32_t GetMaxPublicKeySize_Inst(TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
		virtual void AssignCryptoKey(TElCustomCryptoKey &Key);

		virtual void AssignCryptoKey(TElCustomCryptoKey *Key);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

		virtual void Generate(int32_t Bits);

		virtual void LoadPublic(void * Buffer, int32_t Size);

#ifdef SB_USE_CLASS_TSTREAM
		void LoadPublic(TStream &Stream, int32_t Count);

		void LoadPublic(TStream *Stream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void LoadSecret(void * Buffer, int32_t Size);

#ifdef SB_USE_CLASS_TSTREAM
		void LoadSecret(TStream &Stream, int32_t Count);

		void LoadSecret(TStream *Stream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void SavePublic(void * Buffer, int32_t &Size);

#ifdef SB_USE_CLASS_TSTREAM
		virtual void SavePublic(TStream &Stream);

		virtual void SavePublic(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void SaveSecret(void * Buffer, int32_t &Size);

#ifdef SB_USE_CLASS_TSTREAM
		virtual void SaveSecret(TStream &Stream);

		virtual void SaveSecret(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TSTREAM
		virtual void Save(TStream &Stream);

		virtual void Save(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		virtual void Load(TStream &Stream, int32_t Count);

		virtual void Load(TStream *Stream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void LoadFromXML(const std::string &Str);

		virtual void SaveToXML(bool IncludePrivateKey, std::string &OutResult);

		virtual TElKeyMaterialHandle Clone();

		virtual bool Equals(TElKeyMaterial &Source, bool PublicOnly);

		virtual bool Equals(TElKeyMaterial *Source, bool PublicOnly);

		virtual void ClearSecret();

		virtual void ClearPublic();

		void Clear();

		void BeginGenerate(int32_t Bits);

		void EndGenerate();

		void CancelAsyncOperation();

		virtual void PrepareForEncryption(bool MultiUse);

		virtual void PrepareForSigning(bool MultiUse);

		virtual bool get_PublicKey();

		SB_DECLARE_PROPERTY_GET(bool, get_PublicKey, TElPublicKeyMaterial, PublicKey);

		virtual bool get_SecretKey();

		SB_DECLARE_PROPERTY_GET(bool, get_SecretKey, TElPublicKeyMaterial, SecretKey);

#ifdef SB_WINDOWS
		virtual PCCERT_CONTEXT get_CertHandle();

		virtual void set_CertHandle(PCCERT_CONTEXT Value);

		SB_DECLARE_PROPERTY(PCCERT_CONTEXT, get_CertHandle, set_CertHandle, TElPublicKeyMaterial, CertHandle);

		virtual void get_KeyExchangePIN(std::string &OutResult);

		virtual void set_KeyExchangePIN(const std::string &Value);

		virtual void get_SignaturePIN(std::string &OutResult);

		virtual void set_SignaturePIN(const std::string &Value);

#endif
#ifdef SB_NOT_CPU64_OR_WINDOWS
		virtual uint32_t get_KeyHandle();
#else
		virtual int64_t get_KeyHandle();
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		virtual void set_KeyHandle(uint32_t Value);
#else
		virtual void set_KeyHandle(int64_t Value);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		SB_DECLARE_PROPERTY(uint32_t, get_KeyHandle, set_KeyHandle, TElPublicKeyMaterial, KeyHandle);
#else
		SB_DECLARE_PROPERTY(int64_t, get_KeyHandle, set_KeyHandle, TElPublicKeyMaterial, KeyHandle);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		virtual uint32_t get_SessionHandle();
#else
		virtual int64_t get_SessionHandle();
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		virtual void set_SessionHandle(uint32_t Value);
#else
		virtual void set_SessionHandle(int64_t Value);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		SB_DECLARE_PROPERTY(uint32_t, get_SessionHandle, set_SessionHandle, TElPublicKeyMaterial, SessionHandle);
#ifdef SB_WINDOWS

		virtual uint32_t * get_CNGKeyHandle();

		virtual void set_CNGKeyHandle(uint32_t * Value);

		SB_DECLARE_PROPERTY(uint32_t *, get_CNGKeyHandle, set_CNGKeyHandle, TElPublicKeyMaterial, CNGKeyHandle);

		virtual uint32_t * get_CNGProvHandle();

		virtual void set_CNGProvHandle(uint32_t * Value);

		SB_DECLARE_PROPERTY(uint32_t *, get_CNGProvHandle, set_CNGProvHandle, TElPublicKeyMaterial, CNGProvHandle);
#endif
#else
		SB_DECLARE_PROPERTY(int64_t, get_SessionHandle, set_SessionHandle, TElPublicKeyMaterial, SessionHandle);
#endif

		virtual bool get_Busy();

		SB_DECLARE_PROPERTY_GET(bool, get_Busy, TElPublicKeyMaterial, Busy);

		virtual TSBKeyStoreFormat get_StoreFormat();

		virtual void set_StoreFormat(TSBKeyStoreFormat Value);

		SB_DECLARE_PROPERTY(TSBKeyStoreFormat, get_StoreFormat, set_StoreFormat, TElPublicKeyMaterial, StoreFormat);

		virtual bool get_AsyncOperationFinished();

		SB_DECLARE_PROPERTY_GET(bool, get_AsyncOperationFinished, TElPublicKeyMaterial, AsyncOperationFinished);

		virtual void get_OnAsyncOperationFinished(TSBAsyncOperationFinishedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAsyncOperationFinished(TSBAsyncOperationFinishedEvent pMethodValue, void * pDataValue);

		TElPublicKeyMaterial(TElPublicKeyMaterialHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElPublicKeyMaterial(TElCustomCryptoProvider &Prov);

		explicit TElPublicKeyMaterial(TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElPublicKeyMaterial(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElPublicKeyMaterial(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

#ifdef SB_USE_CLASS_TELPUBLICKEYCRYPTO
class TElPublicKeyCrypto: public TElCustomCrypto
{
	private:
		SB_DISABLE_COPY(TElPublicKeyCrypto)
#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		TElPublicKeyMaterial* _Inst_KeyMaterial;
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		void Encrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TSTREAM
		void Encrypt(TStream &InStream, TStream &OutStream, int32_t Count);

		void Encrypt(TStream *InStream, TStream *OutStream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		void Decrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TSTREAM
		void Decrypt(TStream &InStream, TStream &OutStream, int32_t Count);

		void Decrypt(TStream *InStream, TStream *OutStream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		void Sign(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TSTREAM
		void Sign(TStream &InStream, TStream &OutStream, int32_t Count);

		void Sign(TStream *InStream, TStream *OutStream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		void SignDetached(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TSTREAM
		void SignDetached(TStream &InStream, TStream &OutStream, int32_t Count);

		void SignDetached(TStream *InStream, TStream *OutStream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		TSBPublicKeyVerificationResult Verify(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TSTREAM
		TSBPublicKeyVerificationResult Verify(TStream &InStream, TStream &OutStream, int32_t Count);

		TSBPublicKeyVerificationResult Verify(TStream *InStream, TStream *OutStream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		TSBPublicKeyVerificationResult VerifyDetached(void * InBuffer, int32_t InSize, void * SigBuffer, int32_t SigSize);

#ifdef SB_USE_CLASS_TSTREAM
		TSBPublicKeyVerificationResult VerifyDetached(TStream &InStream, TStream &SigStream, int32_t InCount, int32_t SigCount);

		TSBPublicKeyVerificationResult VerifyDetached(TStream *InStream, TStream *SigStream, int32_t InCount, int32_t SigCount);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELKEYMATERIAL
		virtual TElKeyMaterialHandle DecryptKey(void * EncKey, int32_t EncKeySize, const std::vector<uint8_t> &EncKeyAlgOID, const std::vector<uint8_t> &EncKeyAlgParams);
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

		void BeginEncrypt(void * InBuffer, int32_t InSize);

#ifdef SB_USE_CLASS_TSTREAM
		void BeginEncrypt(TStream &InStream, TStream &OutStream, int32_t Count);

		void BeginEncrypt(TStream *InStream, TStream *OutStream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		bool EndEncrypt(void * OutBuffer, int32_t &OutSize);

		void EndEncrypt();

		void BeginDecrypt(void * InBuffer, int32_t InSize);

#ifdef SB_USE_CLASS_TSTREAM
		void BeginDecrypt(TStream &InStream, TStream &OutStream, int32_t Count);

		void BeginDecrypt(TStream *InStream, TStream *OutStream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		bool EndDecrypt(void * OutBuffer, int32_t &OutSize);

		void EndDecrypt();

		void BeginSign(void * InBuffer, int32_t InSize);

#ifdef SB_USE_CLASS_TSTREAM
		void BeginSign(TStream &InStream, TStream &OutStream, int32_t Count);

		void BeginSign(TStream *InStream, TStream *OutStream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		bool EndSign(void * OutBuffer, int32_t &OutSize);

		void EndSign();

		void BeginSignDetached(void * InBuffer, int32_t InSize);

#ifdef SB_USE_CLASS_TSTREAM
		void BeginSignDetached(TStream &InStream, TStream &OutStream, int32_t Count);

		void BeginSignDetached(TStream *InStream, TStream *OutStream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		bool EndSignDetached(void * OutBuffer, int32_t &OutSize);

		void EndSignDetached();

		void BeginVerify(void * InBuffer, int32_t InSize);

#ifdef SB_USE_CLASS_TSTREAM
		void BeginVerify(TStream &InStream, TStream &OutStream, int32_t Count);

		void BeginVerify(TStream *InStream, TStream *OutStream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		bool EndVerify(void * OutBuffer, int32_t &OutSize, TSBPublicKeyVerificationResult &VerificationResult);

		TSBPublicKeyVerificationResult EndVerify();

		void BeginVerifyDetached(void * InBuffer, int32_t InSize, void * SigBuffer, int32_t SigSize);

#ifdef SB_USE_CLASS_TSTREAM
		void BeginVerifyDetached(TStream &InStream, TStream &SigStream, int32_t InCount, int32_t SigCount);

		void BeginVerifyDetached(TStream *InStream, TStream *SigStream, int32_t InCount, int32_t SigCount);
#endif /* SB_USE_CLASS_TSTREAM */

		TSBPublicKeyVerificationResult EndVerifyDetached();

		void CancelAsyncOperation();

		static TClassHandle ClassType();

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		virtual TElPublicKeyMaterial* get_KeyMaterial();

		virtual void set_KeyMaterial(TElPublicKeyMaterial &Value);

		virtual void set_KeyMaterial(TElPublicKeyMaterial *Value);

		SB_DECLARE_PROPERTY(TElPublicKeyMaterial*, get_KeyMaterial, set_KeyMaterial, TElPublicKeyCrypto, KeyMaterial);
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

		virtual bool get_SupportsEncryption();

		SB_DECLARE_PROPERTY_GET(bool, get_SupportsEncryption, TElPublicKeyCrypto, SupportsEncryption);

		virtual bool get_SupportsSigning();

		SB_DECLARE_PROPERTY_GET(bool, get_SupportsSigning, TElPublicKeyCrypto, SupportsSigning);

		virtual bool get_InputIsHash();

		virtual void set_InputIsHash(bool Value);

		SB_DECLARE_PROPERTY(bool, get_InputIsHash, set_InputIsHash, TElPublicKeyCrypto, InputIsHash);

		virtual TSBPublicKeyCryptoEncoding get_InputEncoding();

		virtual void set_InputEncoding(TSBPublicKeyCryptoEncoding Value);

		SB_DECLARE_PROPERTY(TSBPublicKeyCryptoEncoding, get_InputEncoding, set_InputEncoding, TElPublicKeyCrypto, InputEncoding);

		virtual TSBPublicKeyCryptoEncoding get_OutputEncoding();

		virtual void set_OutputEncoding(TSBPublicKeyCryptoEncoding Value);

		SB_DECLARE_PROPERTY(TSBPublicKeyCryptoEncoding, get_OutputEncoding, set_OutputEncoding, TElPublicKeyCrypto, OutputEncoding);

		virtual bool get_Busy();

		SB_DECLARE_PROPERTY_GET(bool, get_Busy, TElPublicKeyCrypto, Busy);

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElPublicKeyCrypto, HashAlgorithm);

		virtual bool get_AsyncOperationFinished();

		SB_DECLARE_PROPERTY_GET(bool, get_AsyncOperationFinished, TElPublicKeyCrypto, AsyncOperationFinished);

		virtual void get_OnAsyncOperationFinished(TSBAsyncOperationFinishedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAsyncOperationFinished(TSBAsyncOperationFinishedEvent pMethodValue, void * pDataValue);

		TElPublicKeyCrypto(TElPublicKeyCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider);

		TElPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider &CryptoProvider);

		TElPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElPublicKeyCrypto(TElCustomCryptoProvider &CryptoProvider);

		explicit TElPublicKeyCrypto(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElPublicKeyCrypto(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElPublicKeyCrypto(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual ~TElPublicKeyCrypto();

};
#endif /* SB_USE_CLASS_TELPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELRSAKEYMATERIAL
class TElRSAKeyMaterial: public TElPublicKeyMaterial
{
	private:
		SB_DISABLE_COPY(TElRSAKeyMaterial)
	public:
		virtual void Assign(TElKeyMaterial &Source);

		virtual void Assign(TElKeyMaterial *Source);

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		virtual void LoadPublic(void * Buffer, int32_t Size);

		void LoadPublic(void * Modulus, int32_t ModulusSize, void * Exponent, int32_t ExponentSize);

		virtual void LoadSecret(void * Buffer, int32_t Size);

		virtual void SavePublic(void * Buffer, int32_t &Size);

		virtual void SaveSecret(void * Buffer, int32_t &Size);

		virtual void LoadFromXML(const std::string &Str);

		virtual void SaveToXML(bool IncludePrivateKey, std::string &OutResult);

		bool EncodePublicKey(void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, const std::vector<uint8_t> &AlgID, void * OutBuffer, int32_t &OutSize, bool InnerValuesOnly);

		bool EncodePrivateKey(void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * PrivateExponent, int32_t PrivateExponentSize, void * OutBuffer, int32_t &OutSize);

		bool EncodePrivateKey(void * N, int32_t NSize, void * E, int32_t ESize, void * D, int32_t DSize, void * P, int32_t PSize, void * Q, int32_t QSize, void * DP, int32_t DPSize, void * DQ, int32_t DQSize, void * QInv, int32_t QInvSize, void * OutBuffer, int32_t &OutSize);

		bool EncodePrivateKey(void * N, int32_t NSize, void * E, int32_t ESize, void * D, int32_t DSize, void * P, int32_t PSize, void * Q, int32_t QSize, void * OutBuffer, int32_t &OutSize);

		bool DecodePrivateKey(void * Blob, int32_t BlobSize, void * N, int32_t &NSize, void * E, int32_t &ESize, void * D, int32_t &DSize);

		bool DecodePrivateKey(void * Blob, int32_t BlobSize, void * N, int32_t &NSize, void * E, int32_t &ESize, void * D, int32_t &DSize, void * P, int32_t &PSize, void * Q, int32_t &QSize, void * DP, int32_t &DPSize, void * DQ, int32_t &DQSize, void * QInv, int32_t &QInvSize);

		static void WritePSSParams(int32_t HashAlgorithm, int32_t SaltSize, int32_t MGFAlgorithm, int32_t TrailerField, std::vector<uint8_t> &OutResult);

		void WritePSSParams_Inst(int32_t HashAlgorithm, int32_t SaltSize, int32_t MGFAlgorithm, int32_t TrailerField, std::vector<uint8_t> &OutResult);

		static bool ReadPSSParams(void * InBuffer, int32_t InBufferSize, int32_t &HashAlgorithm, int32_t &SaltSize, int32_t &MGF, int32_t &MGFHashAlgorithm, int32_t &TrailerField);

		bool ReadPSSParams_Inst(void * InBuffer, int32_t InBufferSize, int32_t &HashAlgorithm, int32_t &SaltSize, int32_t &MGF, int32_t &MGFHashAlgorithm, int32_t &TrailerField);

		static void WriteOAEPParams(int32_t HashAlgorithm, int32_t MGFHashAlgorithm, const std::string &StrLabel, std::vector<uint8_t> &OutResult);

		void WriteOAEPParams_Inst(int32_t HashAlgorithm, int32_t MGFHashAlgorithm, const std::string &StrLabel, std::vector<uint8_t> &OutResult);

		static bool ReadOAEPParams(void * InBuffer, int32_t InBufferSize, int32_t &HashAlgorithm, int32_t &MGFHashAlgorithm, std::string &StrLabel);

		bool ReadOAEPParams_Inst(void * InBuffer, int32_t InBufferSize, int32_t &HashAlgorithm, int32_t &MGFHashAlgorithm, std::string &StrLabel);

		virtual TElKeyMaterialHandle Clone();

		virtual bool Equals(TElKeyMaterial &Source, bool PublicOnly);

		virtual bool Equals(TElKeyMaterial *Source, bool PublicOnly);

		virtual void ClearSecret();

		virtual void ClearPublic();

		virtual TSBRSAKeyFormat get_KeyFormat();

		virtual void set_KeyFormat(TSBRSAKeyFormat Value);

		SB_DECLARE_PROPERTY(TSBRSAKeyFormat, get_KeyFormat, set_KeyFormat, TElRSAKeyMaterial, KeyFormat);

		virtual void get_Passphrase(std::string &OutResult);

		virtual void set_Passphrase(const std::string &Value);

		virtual bool get_PEMEncode();

		virtual void set_PEMEncode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PEMEncode, set_PEMEncode, TElRSAKeyMaterial, PEMEncode);

		virtual void get_StrLabel(std::string &OutResult);

		virtual void set_StrLabel(const std::string &Value);

		virtual int32_t get_SaltSize();

		virtual void set_SaltSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SaltSize, set_SaltSize, TElRSAKeyMaterial, SaltSize);

		virtual int32_t get_MGFAlgorithm();

		virtual void set_MGFAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MGFAlgorithm, set_MGFAlgorithm, TElRSAKeyMaterial, MGFAlgorithm);

		virtual int32_t get_TrailerField();

		virtual void set_TrailerField(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_TrailerField, set_TrailerField, TElRSAKeyMaterial, TrailerField);

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElRSAKeyMaterial, HashAlgorithm);

		virtual bool get_RawPublicKey();

		virtual void set_RawPublicKey(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RawPublicKey, set_RawPublicKey, TElRSAKeyMaterial, RawPublicKey);

		virtual void get_PublicModulus(std::vector<uint8_t> &OutResult);

		virtual void get_PublicExponent(std::vector<uint8_t> &OutResult);

		virtual void get_PrivateExponent(std::vector<uint8_t> &OutResult);

		TElRSAKeyMaterial(TElRSAKeyMaterialHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElRSAKeyMaterial(TElCustomCryptoProvider &Prov);

		explicit TElRSAKeyMaterial(TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElRSAKeyMaterial(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElRSAKeyMaterial(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELRSAKEYMATERIAL */

#ifdef SB_USE_CLASS_TELRSAPUBLICKEYCRYPTO
class TElRSAPublicKeyCrypto: public TElPublicKeyCrypto
{
	private:
		SB_DISABLE_COPY(TElRSAPublicKeyCrypto)
	public:
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELKEYMATERIAL
		virtual TElKeyMaterialHandle DecryptKey(void * EncKey, int32_t EncKeySize, const std::vector<uint8_t> &EncKeyAlgOID, const std::vector<uint8_t> &EncKeyAlgParams);
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

		static TClassHandle ClassType();

		virtual TSBRSAPublicKeyCryptoType get_CryptoType();

		virtual void set_CryptoType(TSBRSAPublicKeyCryptoType Value);

		SB_DECLARE_PROPERTY(TSBRSAPublicKeyCryptoType, get_CryptoType, set_CryptoType, TElRSAPublicKeyCrypto, CryptoType);

		virtual bool get_UseAlgorithmPrefix();

		virtual void set_UseAlgorithmPrefix(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseAlgorithmPrefix, set_UseAlgorithmPrefix, TElRSAPublicKeyCrypto, UseAlgorithmPrefix);

		virtual void get_HashFuncOID(std::vector<uint8_t> &OutResult);

		virtual void set_HashFuncOID(const std::vector<uint8_t> &Value);

		virtual int32_t get_SaltSize();

		virtual void set_SaltSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SaltSize, set_SaltSize, TElRSAPublicKeyCrypto, SaltSize);

		virtual void get_StrLabel(std::string &OutResult);

		virtual void set_StrLabel(const std::string &Value);

		virtual int32_t get_TrailerField();

		virtual void set_TrailerField(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_TrailerField, set_TrailerField, TElRSAPublicKeyCrypto, TrailerField);

		virtual int32_t get_MGFAlgorithm();

		virtual void set_MGFAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MGFAlgorithm, set_MGFAlgorithm, TElRSAPublicKeyCrypto, MGFAlgorithm);

		TElRSAPublicKeyCrypto(TElRSAPublicKeyCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElRSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider);

		TElRSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElRSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider &CryptoProvider);

		TElRSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElRSAPublicKeyCrypto(TElCustomCryptoProvider &CryptoProvider);

		explicit TElRSAPublicKeyCrypto(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElRSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElRSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElRSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElRSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElRSAPublicKeyCrypto(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElRSAPublicKeyCrypto(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELRSAPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELDSAKEYMATERIAL
class TElDSAKeyMaterial: public TElPublicKeyMaterial
{
	private:
		SB_DISABLE_COPY(TElDSAKeyMaterial)
	public:
		virtual void Assign(TElKeyMaterial &Source);

		virtual void Assign(TElKeyMaterial *Source);

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		virtual void Generate(int32_t Bits);

		virtual void Generate(int32_t PBits, int32_t QBits);

		virtual void BeginGenerate(int32_t PBits, int32_t QBits);

		virtual void LoadSecret(void * Buffer, int32_t Size);

		virtual void SaveSecret(void * Buffer, int32_t &Size);

		virtual void LoadPublic(void * Buffer, int32_t Size);

		virtual void SavePublic(void * Buffer, int32_t &Size);

		void ImportPublicKey(void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * Y, int32_t YSize);

		void ExportPublicKey(void * P, int32_t &PSize, void * Q, int32_t &QSize, void * G, int32_t &GSize, void * Y, int32_t &YSize);

		virtual void LoadFromXML(const std::string &Str);

		virtual void SaveToXML(bool IncludePrivateKey, std::string &OutResult);

		bool EncodePrivateKey(void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * Y, int32_t YSize, void * X, int32_t XSize, void * OutBuffer, int32_t &OutSize);

		bool DecodePrivateKey(void * Blob, int32_t BlobSize, void * P, int32_t &PSize, void * Q, int32_t &QSize, void * G, int32_t &GSize, void * Y, int32_t &YSize, void * X, int32_t &XSize);

		virtual TElKeyMaterialHandle Clone();

		virtual bool Equals(TElKeyMaterial &Source, bool PublicOnly);

		virtual bool Equals(TElKeyMaterial *Source, bool PublicOnly);

		virtual void ClearSecret();

		virtual void ClearPublic();

		virtual TSBDSAKeyFormat get_KeyFormat();

		SB_DECLARE_PROPERTY_GET(TSBDSAKeyFormat, get_KeyFormat, TElDSAKeyMaterial, KeyFormat);

		virtual int32_t get_QBits();

		SB_DECLARE_PROPERTY_GET(int32_t, get_QBits, TElDSAKeyMaterial, QBits);

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElDSAKeyMaterial, HashAlgorithm);

		virtual void get_Passphrase(std::string &OutResult);

		virtual void set_Passphrase(const std::string &Value);

		virtual bool get_PEMEncode();

		virtual void set_PEMEncode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PEMEncode, set_PEMEncode, TElDSAKeyMaterial, PEMEncode);

		virtual bool get_StrictKeyValidation();

		virtual void set_StrictKeyValidation(bool Value);

		SB_DECLARE_PROPERTY(bool, get_StrictKeyValidation, set_StrictKeyValidation, TElDSAKeyMaterial, StrictKeyValidation);

		virtual void get_P(std::vector<uint8_t> &OutResult);

		virtual void set_P(const std::vector<uint8_t> &Value);

		virtual void get_Q(std::vector<uint8_t> &OutResult);

		virtual void set_Q(const std::vector<uint8_t> &Value);

		virtual void get_G(std::vector<uint8_t> &OutResult);

		virtual void set_G(const std::vector<uint8_t> &Value);

		virtual void get_Y(std::vector<uint8_t> &OutResult);

		virtual void set_Y(const std::vector<uint8_t> &Value);

		virtual void get_X(std::vector<uint8_t> &OutResult);

		virtual void set_X(const std::vector<uint8_t> &Value);

		TElDSAKeyMaterial(TElDSAKeyMaterialHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElDSAKeyMaterial(TElCustomCryptoProvider &Prov);

		explicit TElDSAKeyMaterial(TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElDSAKeyMaterial(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElDSAKeyMaterial(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELDSAKEYMATERIAL */

#ifdef SB_USE_CLASS_TELDSAPUBLICKEYCRYPTO
class TElDSAPublicKeyCrypto: public TElPublicKeyCrypto
{
	private:
		SB_DISABLE_COPY(TElDSAPublicKeyCrypto)
	public:
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		void EncodeSignature(void * R, int32_t RSize, void * S, int32_t SSize, void * Sig, int32_t &SigSize);

		void DecodeSignature(void * Sig, int32_t SigSize, void * R, int32_t &RSize, void * S, int32_t &SSize);

		static TClassHandle ClassType();

		TElDSAPublicKeyCrypto(TElDSAPublicKeyCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElDSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider);

		TElDSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElDSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider &CryptoProvider);

		TElDSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElDSAPublicKeyCrypto(TElCustomCryptoProvider &CryptoProvider);

		explicit TElDSAPublicKeyCrypto(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElDSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElDSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElDSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElDSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElDSAPublicKeyCrypto(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElDSAPublicKeyCrypto(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELDSAPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELECKEYMATERIAL
class TElECKeyMaterial: public TElPublicKeyMaterial
{
	private:
		SB_DISABLE_COPY(TElECKeyMaterial)
	public:
		virtual void Assign(TElKeyMaterial &Source);

		virtual void Assign(TElKeyMaterial *Source);

		virtual void Generate();

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		virtual void LoadSecret(void * Buffer, int32_t Size);

		virtual void SaveSecret(void * Buffer, int32_t &Size);

		virtual void LoadPublic(void * Buffer, int32_t Size);

		virtual void SavePublic(void * Buffer, int32_t &Size);

		void ImportPublicKey(void * QX, int32_t QXSize, void * QY, int32_t QYSize);

		void ExportPublicKey(void * QX, int32_t &QXSize, void * QY, int32_t &QYSize);

		virtual TElKeyMaterialHandle Clone();

		virtual bool Equals(TElKeyMaterial &Source, bool PublicOnly);

		virtual bool Equals(TElKeyMaterial *Source, bool PublicOnly);

		virtual void ClearSecret();

		virtual void ClearPublic();

		bool EncodePrivateKey(void * D, int32_t DSize, void * Qx, int32_t QxSize, void * Qy, int32_t QySize, int32_t Curve, void * OutBuffer, int32_t &OutSize);

		bool DecodePrivateKey(void * Blob, int32_t BlobSize, void * D, int32_t &DSize, void * Qx, int32_t &QxSize, void * Qy, int32_t &QySize, int32_t &Curve);

		virtual bool get_CompressPoints();

		virtual void set_CompressPoints(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CompressPoints, set_CompressPoints, TElECKeyMaterial, CompressPoints);

		virtual bool get_HybridPoints();

		virtual void set_HybridPoints(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HybridPoints, set_HybridPoints, TElECKeyMaterial, HybridPoints);

		virtual int32_t get_FieldType();

		virtual void set_FieldType(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_FieldType, set_FieldType, TElECKeyMaterial, FieldType);

		virtual int32_t get_Field();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Field, TElECKeyMaterial, Field);

		virtual int32_t get_FieldBits();

		SB_DECLARE_PROPERTY_GET(int32_t, get_FieldBits, TElECKeyMaterial, FieldBits);

		virtual int32_t get_M();

		virtual void set_M(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_M, set_M, TElECKeyMaterial, M);

		virtual int32_t get_K1();

		virtual void set_K1(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_K1, set_K1, TElECKeyMaterial, K1);

		virtual int32_t get_K2();

		virtual void set_K2(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_K2, set_K2, TElECKeyMaterial, K2);

		virtual int32_t get_K3();

		virtual void set_K3(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_K3, set_K3, TElECKeyMaterial, K3);

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElECKeyMaterial, HashAlgorithm);

		virtual int32_t get_RecommendedHashAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_RecommendedHashAlgorithm, TElECKeyMaterial, RecommendedHashAlgorithm);

		virtual void get_D(std::vector<uint8_t> &OutResult);

		virtual void set_D(const std::vector<uint8_t> &Value);

		virtual void get_N(std::vector<uint8_t> &OutResult);

		virtual void set_N(const std::vector<uint8_t> &Value);

		virtual int32_t get_H();

		virtual void set_H(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_H, set_H, TElECKeyMaterial, H);

		virtual void get_A(std::vector<uint8_t> &OutResult);

		virtual void set_A(const std::vector<uint8_t> &Value);

		virtual void get_B(std::vector<uint8_t> &OutResult);

		virtual void set_B(const std::vector<uint8_t> &Value);

		virtual void get_X(std::vector<uint8_t> &OutResult);

		virtual void set_X(const std::vector<uint8_t> &Value);

		virtual void get_Y(std::vector<uint8_t> &OutResult);

		virtual void set_Y(const std::vector<uint8_t> &Value);

		virtual void get_Q(std::vector<uint8_t> &OutResult);

		virtual void set_Q(const std::vector<uint8_t> &Value);

		virtual void get_QX(std::vector<uint8_t> &OutResult);

		virtual void set_QX(const std::vector<uint8_t> &Value);

		virtual void get_QY(std::vector<uint8_t> &OutResult);

		virtual void set_QY(const std::vector<uint8_t> &Value);

		virtual void get_Base(std::vector<uint8_t> &OutResult);

		virtual void set_Base(const std::vector<uint8_t> &Value);

		virtual void get_P(std::vector<uint8_t> &OutResult);

		virtual void set_P(const std::vector<uint8_t> &Value);

		virtual int32_t get_Curve();

		virtual void set_Curve(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Curve, set_Curve, TElECKeyMaterial, Curve);

		virtual void get_CurveOID(std::vector<uint8_t> &OutResult);

		virtual void set_CurveOID(const std::vector<uint8_t> &Value);

		virtual bool get_SpecifiedCurve();

		virtual void set_SpecifiedCurve(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SpecifiedCurve, set_SpecifiedCurve, TElECKeyMaterial, SpecifiedCurve);

		virtual bool get_ImplicitCurve();

		virtual void set_ImplicitCurve(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ImplicitCurve, set_ImplicitCurve, TElECKeyMaterial, ImplicitCurve);

		virtual void get_Seed(std::vector<uint8_t> &OutResult);

		virtual void set_Seed(const std::vector<uint8_t> &Value);

		TElECKeyMaterial(TElECKeyMaterialHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElECKeyMaterial(TElCustomCryptoProvider &Prov);

		explicit TElECKeyMaterial(TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElECKeyMaterial(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElECKeyMaterial(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELECKEYMATERIAL */

#ifdef SB_USE_CLASS_TELECDSAPUBLICKEYCRYPTO
class TElECDSAPublicKeyCrypto: public TElPublicKeyCrypto
{
	private:
		SB_DISABLE_COPY(TElECDSAPublicKeyCrypto)
	public:
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		void EncodeSignature(void * R, int32_t RSize, void * S, int32_t SSize, void * Sig, int32_t &SigSize);

		void DecodeSignature(void * Sig, int32_t SigSize, void * R, int32_t &RSize, void * S, int32_t &SSize);

		static TClassHandle ClassType();

		TElECDSAPublicKeyCrypto(TElECDSAPublicKeyCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElECDSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider);

		TElECDSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElECDSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider &CryptoProvider);

		TElECDSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElECDSAPublicKeyCrypto(TElCustomCryptoProvider &CryptoProvider);

		explicit TElECDSAPublicKeyCrypto(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElECDSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElECDSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElECDSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElECDSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElECDSAPublicKeyCrypto(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElECDSAPublicKeyCrypto(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELECDSAPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELECDHPUBLICKEYCRYPTO
class TElECDHPublicKeyCrypto: public TElPublicKeyCrypto
{
	private:
		SB_DISABLE_COPY(TElECDHPublicKeyCrypto)
	public:
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		static TClassHandle ClassType();

		TElECDHPublicKeyCrypto(TElECDHPublicKeyCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElECDHPublicKeyCrypto(TElCustomCryptoProvider &CryptoProvider);

		explicit TElECDHPublicKeyCrypto(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElECDHPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider);

		TElECDHPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElECDHPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider &CryptoProvider);

		TElECDHPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElECDHPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElECDHPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElECDHPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElECDHPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElECDHPublicKeyCrypto(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElECDHPublicKeyCrypto(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELECDHPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELDHKEYMATERIAL
class TElDHKeyMaterial: public TElPublicKeyMaterial
{
	private:
		SB_DISABLE_COPY(TElDHKeyMaterial)
	public:
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		void LoadPublic(void * P, int32_t PSize, void * G, int32_t GSize, void * Y, int32_t YSize);

		virtual void SavePublic(void * Buffer, int32_t &Size);

		virtual void SaveSecret(void * Buffer, int32_t &Size);

		virtual void LoadSecret(void * Buffer, int32_t Size);

		void LoadPeerY(void * Y, int32_t YSize);

		virtual void LoadFromXML(const std::string &Str);

		virtual void SaveToXML(bool IncludePrivateKey, std::string &OutResult);

		virtual void Assign(TElKeyMaterial &Source);

		virtual void Assign(TElKeyMaterial *Source);

		virtual TElKeyMaterialHandle Clone();

		virtual bool Equals(TElKeyMaterial &Source, bool PublicOnly);

		virtual bool Equals(TElKeyMaterial *Source, bool PublicOnly);

		virtual void ClearSecret();

		virtual void ClearPublic();

		virtual TSBDHKeyFormat get_KeyFormat();

		SB_DECLARE_PROPERTY_GET(TSBDHKeyFormat, get_KeyFormat, TElDHKeyMaterial, KeyFormat);

		virtual void get_P(std::vector<uint8_t> &OutResult);

		virtual void set_P(const std::vector<uint8_t> &Value);

		virtual void get_G(std::vector<uint8_t> &OutResult);

		virtual void set_G(const std::vector<uint8_t> &Value);

		virtual void get_X(std::vector<uint8_t> &OutResult);

		virtual void set_X(const std::vector<uint8_t> &Value);

		virtual void get_Y(std::vector<uint8_t> &OutResult);

		virtual void set_Y(const std::vector<uint8_t> &Value);

		virtual void get_PeerY(std::vector<uint8_t> &OutResult);

		virtual void set_PeerY(const std::vector<uint8_t> &Value);

		virtual bool get_PreserveGroupParameters();

		virtual void set_PreserveGroupParameters(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PreserveGroupParameters, set_PreserveGroupParameters, TElDHKeyMaterial, PreserveGroupParameters);

		TElDHKeyMaterial(TElDHKeyMaterialHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElDHKeyMaterial(TElCustomCryptoProvider &Prov);

		explicit TElDHKeyMaterial(TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElDHKeyMaterial(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElDHKeyMaterial(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELDHKEYMATERIAL */

#ifdef SB_USE_CLASS_TELDHPUBLICKEYCRYPTO
class TElDHPublicKeyCrypto: public TElPublicKeyCrypto
{
	private:
		SB_DISABLE_COPY(TElDHPublicKeyCrypto)
	public:
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		static TClassHandle ClassType();

		virtual TSBDHPublicKeyCryptoType get_CryptoType();

		virtual void set_CryptoType(TSBDHPublicKeyCryptoType Value);

		SB_DECLARE_PROPERTY(TSBDHPublicKeyCryptoType, get_CryptoType, set_CryptoType, TElDHPublicKeyCrypto, CryptoType);

		TElDHPublicKeyCrypto(TElDHPublicKeyCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElDHPublicKeyCrypto(TElCustomCryptoProvider &CryptoProvider);

		explicit TElDHPublicKeyCrypto(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElDHPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider);

		TElDHPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElDHPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider &CryptoProvider);

		TElDHPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElDHPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElDHPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElDHPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElDHPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElDHPublicKeyCrypto(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElDHPublicKeyCrypto(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELDHPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELELGAMALKEYMATERIAL
class TElElGamalKeyMaterial: public TElPublicKeyMaterial
{
	private:
		SB_DISABLE_COPY(TElElGamalKeyMaterial)
	public:
		virtual void Assign(TElKeyMaterial &Source);

		virtual void Assign(TElKeyMaterial *Source);

		virtual TElKeyMaterialHandle Clone();

		void LoadPublic(void * P, int32_t PSize, void * G, int32_t GSize, void * Y, int32_t YSize);

		void LoadSecret(void * P, int32_t PSize, void * G, int32_t GSize, void * Y, int32_t YSize, void * X, int32_t XSize);

		virtual void SavePublic(void * Buffer, int32_t &Size);

		virtual void SaveSecret(void * Buffer, int32_t &Size);

		virtual void LoadFromXML(const std::string &Str);

		virtual void SaveToXML(bool IncludePrivateKey, std::string &OutResult);

		virtual bool Equals(TElKeyMaterial &Source, bool PublicOnly);

		virtual bool Equals(TElKeyMaterial *Source, bool PublicOnly);

		virtual void ClearSecret();

		virtual void ClearPublic();

		virtual void get_P(std::vector<uint8_t> &OutResult);

		virtual void get_G(std::vector<uint8_t> &OutResult);

		virtual void get_Y(std::vector<uint8_t> &OutResult);

		virtual void get_X(std::vector<uint8_t> &OutResult);

		TElElGamalKeyMaterial(TElElGamalKeyMaterialHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElElGamalKeyMaterial(TElCustomCryptoProvider &Prov);

		explicit TElElGamalKeyMaterial(TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElElGamalKeyMaterial(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElElGamalKeyMaterial(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELELGAMALKEYMATERIAL */

#ifdef SB_USE_CLASS_TELELGAMALPUBLICKEYCRYPTO
class TElElGamalPublicKeyCrypto: public TElPublicKeyCrypto
{
	private:
		SB_DISABLE_COPY(TElElGamalPublicKeyCrypto)
	public:
		void EncodeResult(void * A, int32_t ASize, void * B, int32_t BSize, void * Blob, int32_t &BlobSize);

		void DecodeResult(void * Blob, int32_t BlobSize, void * A, int32_t &ASize, void * B, int32_t &BSize);

		static TClassHandle ClassType();

		TElElGamalPublicKeyCrypto(TElElGamalPublicKeyCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElElGamalPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider);

		TElElGamalPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElElGamalPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider &CryptoProvider);

		TElElGamalPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElElGamalPublicKeyCrypto(TElCustomCryptoProvider &CryptoProvider);

		explicit TElElGamalPublicKeyCrypto(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElElGamalPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElElGamalPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElElGamalPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElElGamalPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElElGamalPublicKeyCrypto(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElElGamalPublicKeyCrypto(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELELGAMALPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELSRPKEYMATERIAL
class TElSRPKeyMaterial: public TElPublicKeyMaterial
{
	private:
		SB_DISABLE_COPY(TElSRPKeyMaterial)
	public:
		virtual void Assign(TElKeyMaterial &Source);

		virtual void Assign(TElKeyMaterial *Source);

		bool LoadPublic(const std::vector<uint8_t> &N, const std::vector<uint8_t> &G, const std::vector<uint8_t> &Salt, const std::vector<uint8_t> &V);

		void LoadPublic(void * Buffer, int32_t Len, bool &OutResult);

		void LoadPublicValues(const std::vector<uint8_t> &N, const std::vector<uint8_t> &g, const std::vector<uint8_t> &s, const std::vector<uint8_t> &B);

		void LoadVerifier(const std::vector<uint8_t> &N, const std::vector<uint8_t> &g, const std::vector<uint8_t> &s, const std::vector<uint8_t> &V);

		void LoadClientPublicValue(const std::vector<uint8_t> &A);

		void PrepareServerKeyParam();

		virtual TElKeyMaterialHandle Clone();

		virtual void get_Salt(std::vector<uint8_t> &OutResult);

		virtual void get_N(std::vector<uint8_t> &OutResult);

		virtual void get_G(std::vector<uint8_t> &OutResult);

		virtual void get_X(std::vector<uint8_t> &OutResult);

		virtual void get_A(std::vector<uint8_t> &OutResult);

		virtual void get_K(std::vector<uint8_t> &OutResult);

		virtual void get_A_small(std::vector<uint8_t> &OutResult);

		virtual void get_B(std::vector<uint8_t> &OutResult);

		virtual void get_B_small(std::vector<uint8_t> &OutResult);

		virtual void get_V(std::vector<uint8_t> &OutResult);

		virtual void get_U(std::vector<uint8_t> &OutResult);

		virtual void get_S(std::vector<uint8_t> &OutResult);

		TElSRPKeyMaterial(TElSRPKeyMaterialHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElSRPKeyMaterial(TElCustomCryptoProvider &Prov);

		explicit TElSRPKeyMaterial(TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElSRPKeyMaterial(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElSRPKeyMaterial(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELSRPKEYMATERIAL */

#ifdef SB_USE_CLASS_TELSRPPUBLICKEYCRYPTO
class TElSRPPublicKeyCrypto: public TElPublicKeyCrypto
{
	private:
		SB_DISABLE_COPY(TElSRPPublicKeyCrypto)
	public:
		void GetServerKey(std::vector<uint8_t> &PMS);

		void GetClientKeyParam(const std::string &UserName, const std::string &UserPassword, std::vector<uint8_t> &EncPMS);

		void GetServerKeyParam(std::vector<uint8_t> &EncPMS);

		static bool IsTrustedPrime(const std::vector<uint8_t> &N);

		bool IsTrustedPrime_Inst(const std::vector<uint8_t> &N);

		static TClassHandle ClassType();

		TElSRPPublicKeyCrypto(TElSRPPublicKeyCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElSRPPublicKeyCrypto(TElCustomCryptoProvider &CryptoProvider);

		explicit TElSRPPublicKeyCrypto(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElSRPPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider);

		TElSRPPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElSRPPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider &CryptoProvider);

		TElSRPPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElSRPPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElSRPPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElSRPPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElSRPPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElSRPPublicKeyCrypto(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElSRPPublicKeyCrypto(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELSRPPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELGOST94KEYMATERIAL
class TElGOST94KeyMaterial: public TElPublicKeyMaterial
{
	private:
		SB_DISABLE_COPY(TElGOST94KeyMaterial)
	public:
		virtual void Assign(TElKeyMaterial &Source);

		virtual void Assign(TElKeyMaterial *Source);

		virtual TElKeyMaterialHandle Clone();

		virtual void LoadSecret(void * Buffer, int32_t Size);

		void LoadSecret(void * P, int32_t PSize, void * Q, int32_t QSize, void * A, int32_t ASize, void * Y, int32_t YSize, void * X, int32_t XSize);

		void LoadSecret(const std::vector<uint8_t> &P, int32_t PIndex, int32_t PSize, const std::vector<uint8_t> &Q, int32_t QIndex, int32_t QSize, const std::vector<uint8_t> &A, int32_t AIndex, int32_t ASize, const std::vector<uint8_t> &Y, int32_t YIndex, int32_t YSize, const std::vector<uint8_t> &X, int32_t XIndex, int32_t XSize);

		virtual void SaveSecret(void * Buffer, int32_t &Size);

		virtual void LoadPublic(void * Buffer, int32_t Size);

		void LoadPublic(void * P, int32_t PSize, void * Q, int32_t QSize, void * A, int32_t ASize, void * Y, int32_t YSize);

		void LoadPublic(const std::vector<uint8_t> &P, int32_t PIndex, int32_t PSize, const std::vector<uint8_t> &Q, int32_t QIndex, int32_t QSize, const std::vector<uint8_t> &A, int32_t AIndex, int32_t ASize, const std::vector<uint8_t> &Y, int32_t YIndex, int32_t YSize);

		virtual void SavePublic(void * Buffer, int32_t &Size);

		virtual void LoadFromXML(const std::string &Str);

		virtual void SaveToXML(bool IncludePrivateKey, std::string &OutResult);

		virtual bool Equals(TElKeyMaterial &Source, bool PublicOnly);

		virtual bool Equals(TElKeyMaterial *Source, bool PublicOnly);

		virtual void ClearSecret();

		virtual void ClearPublic();

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		virtual void get_P(std::vector<uint8_t> &OutResult);

		virtual void get_Q(std::vector<uint8_t> &OutResult);

		virtual void get_A(std::vector<uint8_t> &OutResult);

		virtual void get_Y(std::vector<uint8_t> &OutResult);

		virtual void set_Y(const std::vector<uint8_t> &Value);

		virtual void get_X(std::vector<uint8_t> &OutResult);

		virtual void set_X(const std::vector<uint8_t> &Value);

		virtual void get_ParamSet(std::vector<uint8_t> &OutResult);

		virtual void set_ParamSet(const std::vector<uint8_t> &Value);

		virtual void get_DigestParamSet(std::vector<uint8_t> &OutResult);

		virtual void set_DigestParamSet(const std::vector<uint8_t> &Value);

		virtual void get_EncryptionParamSet(std::vector<uint8_t> &OutResult);

		virtual void set_EncryptionParamSet(const std::vector<uint8_t> &Value);

		TElGOST94KeyMaterial(TElGOST94KeyMaterialHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElGOST94KeyMaterial(TElCustomCryptoProvider &Prov);

		explicit TElGOST94KeyMaterial(TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElGOST94KeyMaterial(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElGOST94KeyMaterial(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELGOST94KEYMATERIAL */

#ifdef SB_USE_CLASS_TELGOST94PUBLICKEYCRYPTO
class TElGOST94PublicKeyCrypto: public TElPublicKeyCrypto
{
	private:
		SB_DISABLE_COPY(TElGOST94PublicKeyCrypto)
	public:
		static TClassHandle ClassType();

		TElGOST94PublicKeyCrypto(TElGOST94PublicKeyCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElGOST94PublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider);

		TElGOST94PublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElGOST94PublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider &CryptoProvider);

		TElGOST94PublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElGOST94PublicKeyCrypto(TElCustomCryptoProvider &CryptoProvider);

		explicit TElGOST94PublicKeyCrypto(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElGOST94PublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElGOST94PublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElGOST94PublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElGOST94PublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElGOST94PublicKeyCrypto(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElGOST94PublicKeyCrypto(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELGOST94PUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELGOST2001KEYMATERIAL
class TElGOST2001KeyMaterial: public TElPublicKeyMaterial
{
	private:
		SB_DISABLE_COPY(TElGOST2001KeyMaterial)
	public:
		virtual void Assign(TElKeyMaterial &Source);

		virtual void Assign(TElKeyMaterial *Source);

		virtual void Generate();

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual void SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier);

		virtual void SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		virtual void LoadSecret(void * Buffer, int32_t Size);

		virtual void SaveSecret(void * Buffer, int32_t &Size);

		virtual void LoadPublic(void * Buffer, int32_t Size);

		virtual void SavePublic(void * Buffer, int32_t &Size);

		virtual TElKeyMaterialHandle Clone();

		virtual bool Equals(TElKeyMaterial &Source, bool PublicOnly);

		virtual bool Equals(TElKeyMaterial *Source, bool PublicOnly);

		virtual void ClearSecret();

		virtual void ClearPublic();

		virtual void get_Q(std::vector<uint8_t> &OutResult);

		virtual void set_Q(const std::vector<uint8_t> &Value);

		virtual void get_D(std::vector<uint8_t> &OutResult);

		virtual void set_D(const std::vector<uint8_t> &Value);

		virtual void get_ParamSet(std::vector<uint8_t> &OutResult);

		virtual void set_ParamSet(const std::vector<uint8_t> &Value);

		virtual void get_DigestParamSet(std::vector<uint8_t> &OutResult);

		virtual void set_DigestParamSet(const std::vector<uint8_t> &Value);

		virtual void get_EncryptionParamSet(std::vector<uint8_t> &OutResult);

		virtual void set_EncryptionParamSet(const std::vector<uint8_t> &Value);

		TElGOST2001KeyMaterial(TElGOST2001KeyMaterialHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElGOST2001KeyMaterial(TElCustomCryptoProvider &Prov);

		explicit TElGOST2001KeyMaterial(TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElGOST2001KeyMaterial(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElGOST2001KeyMaterial(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELGOST2001KEYMATERIAL */

#ifdef SB_USE_CLASS_TELGOST2001PUBLICKEYCRYPTO
class TElGOST2001PublicKeyCrypto: public TElPublicKeyCrypto
{
	private:
		SB_DISABLE_COPY(TElGOST2001PublicKeyCrypto)
	public:
		static TClassHandle ClassType();

		virtual void get_UKM(std::vector<uint8_t> &OutResult);

		virtual void set_UKM(const std::vector<uint8_t> &Value);

		virtual void get_CEKMAC(std::vector<uint8_t> &OutResult);

		virtual void set_CEKMAC(const std::vector<uint8_t> &Value);

		virtual void get_EphemeralKey(std::vector<uint8_t> &OutResult);

		virtual void set_EphemeralKey(const std::vector<uint8_t> &Value);

		TElGOST2001PublicKeyCrypto(TElGOST2001PublicKeyCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElGOST2001PublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider);

		TElGOST2001PublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElGOST2001PublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider &CryptoProvider);

		TElGOST2001PublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElGOST2001PublicKeyCrypto(TElCustomCryptoProvider &CryptoProvider);

		explicit TElGOST2001PublicKeyCrypto(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElGOST2001PublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElGOST2001PublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElGOST2001PublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElGOST2001PublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElGOST2001PublicKeyCrypto(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElGOST2001PublicKeyCrypto(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELGOST2001PUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELPUBLICKEYCRYPTOFACTORY
class TElPublicKeyCryptoFactory: public TObject
{
	private:
		SB_DISABLE_COPY(TElPublicKeyCryptoFactory)
	public:
#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		TElPublicKeyMaterialHandle CreateKeyInstance(void * Buffer, int32_t Size, const std::string &Password);
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

#ifdef SB_USE_CLASSES_TELPUBLICKEYMATERIAL_AND_TSTREAM
		TElPublicKeyMaterialHandle CreateKeyInstance(TStream &Stream, const std::string &Password, int32_t Count);

		TElPublicKeyMaterialHandle CreateKeyInstance(TStream *Stream, const std::string &Password, int32_t Count);
#endif /* SB_USE_CLASSES_TELPUBLICKEYMATERIAL_AND_TSTREAM */

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		TElPublicKeyMaterialHandle CreateKeyInstance(int32_t Alg);
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

		void RegisterClass(TElPublicKeyCryptoClassHandle Cls);

#ifdef SB_USE_CLASS_TELPUBLICKEYCRYPTO
		TElPublicKeyCryptoHandle CreateInstance(const std::vector<uint8_t> &OID);
#endif /* SB_USE_CLASS_TELPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELPUBLICKEYCRYPTO
		TElPublicKeyCryptoHandle CreateInstance(int32_t Alg);
#endif /* SB_USE_CLASS_TELPUBLICKEYCRYPTO */

		bool IsAlgorithmSupported(const std::vector<uint8_t> &OID);

		bool IsAlgorithmSupported(int32_t Alg);

		virtual TElPublicKeyCryptoClassHandle get_RegisteredClasses(int32_t Index);

		virtual int32_t get_RegisteredClassCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_RegisteredClassCount, TElPublicKeyCryptoFactory, RegisteredClassCount);

		TElPublicKeyCryptoFactory(TElPublicKeyCryptoFactoryHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElPublicKeyCryptoFactory(TElCustomCryptoProvider &CryptoProvider);

		explicit TElPublicKeyCryptoFactory(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElPublicKeyCryptoFactory(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElPublicKeyCryptoFactory(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELPUBLICKEYCRYPTOFACTORY */

#ifdef SB_USE_CLASS_TELREMOTESIGNINGPARAMS
class TElRemoteSigningParams: public TObject
{
	private:
		SB_DISABLE_COPY(TElRemoteSigningParams)
	public:
		virtual int32_t get_CertificateIndex();

		virtual void set_CertificateIndex(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CertificateIndex, set_CertificateIndex, TElRemoteSigningParams, CertificateIndex);

		virtual bool get_ExternalHashCalculation();

		virtual void set_ExternalHashCalculation(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ExternalHashCalculation, set_ExternalHashCalculation, TElRemoteSigningParams, ExternalHashCalculation);

		virtual int32_t get_ECDSACurve();

		virtual void set_ECDSACurve(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ECDSACurve, set_ECDSACurve, TElRemoteSigningParams, ECDSACurve);

		virtual void get_ECDSACurveOID(std::vector<uint8_t> &OutResult);

		virtual void set_ECDSACurveOID(const std::vector<uint8_t> &Value);

		virtual int32_t get_ECDSAFieldBits();

		virtual void set_ECDSAFieldBits(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ECDSAFieldBits, set_ECDSAFieldBits, TElRemoteSigningParams, ECDSAFieldBits);

		virtual int32_t get_DSAQBits();

		virtual void set_DSAQBits(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DSAQBits, set_DSAQBits, TElRemoteSigningParams, DSAQBits);

		TElRemoteSigningParams(TElRemoteSigningParamsHandle handle, TElOwnHandle ownHandle);

		TElRemoteSigningParams();

};
#endif /* SB_USE_CLASS_TELREMOTESIGNINGPARAMS */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPUBLICKEYCRYPTO */
