#ifndef __INC_SBCRYPTOPROVPKCS11
#define __INC_SBCRYPTOPROVPKCS11

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbcryptoprov.h"
#include "sbcryptoprovutils.h"
#include "sbcryptoprovrs.h"
#include "sbpkcs11base.h"
#include "sbpkcs11common.h"
#include "sbpkcs11certstorage.h"
#include "sbsharedresource.h"
#include "sbrsa.h"
#include "sbdsa.h"
#include "sbasn1tree.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbrdn.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElPKCS11CryptoProviderOptionsHandle;

typedef TElClassHandle TElPKCS11CryptoProviderHandle;

typedef TElClassHandle TElPKCS11CryptoKeyHandle;

typedef TElClassHandle TElPKCS11CryptoContextHandle;

typedef TElClassHandle TElPKCS11ECParamsDirectoryHandle;

typedef uint8_t TSBPKCS11CryptoObjectOperationRaw;

typedef enum
{
	pcooGenerateKeyPair = 0,
	pcooGenerateKey = 1,
	pcooCreatePublicKey = 2,
	pcooCreatePrivateKey = 3,
	pcooCreateDomainParams = 4,
	pcooCreateSecretKey = 5
} TSBPKCS11CryptoObjectOperation;

typedef void (SB_CALLBACK *TSBPKCS11CryptoProviderAttributesPreparedEvent)(void * _ObjectData, TObjectHandle Sender, TElCustomCryptoKeyHandle CryptoKey, TSBPKCS11CryptoObjectOperationRaw Operation, TElPKCS11AttributeListHandle PubSet, TElPKCS11AttributeListHandle PrivSet);

typedef uint8_t TSBPKCS11CryptoContextTypeRaw;

typedef enum
{
	cctUndefined = 0,
	cctSymCrypto = 1,
	cctPKICrypto = 2,
	cctHash = 3,
	cctHMAC = 4
} TSBPKCS11CryptoContextType;

typedef uint8_t TSBPKCS11CryptoContextOperationRaw;

typedef enum
{
	ccoUndefined = 0,
	ccoEncrypt = 1,
	ccoDecrypt = 2,
	ccoSign = 3,
	ccoVerify = 4,
	ccoSignDetached = 5,
	ccoVerifyDetached = 6,
	ccoHash = 7
} TSBPKCS11CryptoContextOperation;

#ifdef SB_USE_CLASS_TELPKCS11CRYPTOPROVIDEROPTIONS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_Assign(TElPKCS11CryptoProviderOptionsHandle _Handle, TElCustomCryptoProviderOptionsHandle Options);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_get_UseForPublicKeyOperations(TElPKCS11CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_set_UseForPublicKeyOperations(TElPKCS11CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_get_UseForSymmetricKeyOperations(TElPKCS11CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_set_UseForSymmetricKeyOperations(TElPKCS11CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_get_UseForHashingOperations(TElPKCS11CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_set_UseForHashingOperations(TElPKCS11CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_get_UseForNonPrivateOperations(TElPKCS11CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_set_UseForNonPrivateOperations(TElPKCS11CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_get_ForceUseForIndirectHashingOperations(TElPKCS11CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_set_ForceUseForIndirectHashingOperations(TElPKCS11CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_get_DelayedPublicKeyImport(TElPKCS11CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_set_DelayedPublicKeyImport(TElPKCS11CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_get_ThreadSafe(TElPKCS11CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_set_ThreadSafe(TElPKCS11CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_get_IgnoreReportedSupportedAlgorithms(TElPKCS11CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_set_IgnoreReportedSupportedAlgorithms(TElPKCS11CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_get_NormalizeSourceLength(TElPKCS11CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_set_NormalizeSourceLength(TElPKCS11CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_get_OperationPIN(TElPKCS11CryptoProviderOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_set_OperationPIN(TElPKCS11CryptoProviderOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_get_DefaultRSAPublicExponent(TElPKCS11CryptoProviderOptionsHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_set_DefaultRSAPublicExponent(TElPKCS11CryptoProviderOptionsHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProviderOptions_Create(TElCustomCryptoProviderOptionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11CRYPTOPROVIDEROPTIONS */

#ifdef SB_USE_CLASS_TELPKCS11CRYPTOPROVIDER
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_Init(TElPKCS11CryptoProviderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_Deinit(TElPKCS11CryptoProviderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_SetAsDefault();
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_SetAsDefault_1(TElPKCS11CryptoProviderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_Clone(TElPKCS11CryptoProviderHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_IsAlgorithmSupported(TElPKCS11CryptoProviderHandle _Handle, int32_t Algorithm, int32_t Mode, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_IsAlgorithmSupported_1(TElPKCS11CryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_IsOperationSupported(TElPKCS11CryptoProviderHandle _Handle, int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_IsOperationSupported_1(TElPKCS11CryptoProviderHandle _Handle, int32_t Operation, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_GetAlgorithmProperty(TElPKCS11CryptoProviderHandle _Handle, int32_t Algorithm, int32_t Mode, const uint8_t pPropID[], int32_t szPropID, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_GetAlgorithmProperty_1(TElPKCS11CryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, const uint8_t pPropID[], int32_t szPropID, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_GetAlgorithmClass(TElPKCS11CryptoProviderHandle _Handle, int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_GetAlgorithmClass_1(TElPKCS11CryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_GetProviderProp(TElPKCS11CryptoProviderHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pDefault[], int32_t szDefault, uint8_t pOutResult[], int32_t * szOutResult);
#ifdef SB_IOS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_GetProviderProp_1(TElPKCS11CryptoProviderHandle _Handle, const uint8_t pPropID[], int32_t szPropID, TObjectHandle Default, TObjectHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_SetProviderProp(TElPKCS11CryptoProviderHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pValue[], int32_t szValue);
#ifdef SB_IOS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_SetProviderProp_1(TElPKCS11CryptoProviderHandle _Handle, const uint8_t pPropID[], int32_t szPropID, TObjectHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_GetDefaultInstance(TElPKCS11CryptoProviderHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_CreateKey(TElPKCS11CryptoProviderHandle _Handle, int32_t Algorithm, int32_t Mode, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_CreateKey_1(TElPKCS11CryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_CloneKey(TElPKCS11CryptoProviderHandle _Handle, TElCustomCryptoKeyHandle Key, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_ReleaseKey(TElPKCS11CryptoProviderHandle _Handle, TElCustomCryptoKeyHandle * Key);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_DeleteKey(TElPKCS11CryptoProviderHandle _Handle, TElCustomCryptoKeyHandle * Key);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_DecryptKey(TElPKCS11CryptoProviderHandle _Handle, void * EncKey, int32_t EncKeySize, const uint8_t pEncKeyAlgOID[], int32_t szEncKeyAlgOID, const uint8_t pEncKeyAlgParams[], int32_t szEncKeyAlgParams, TElCustomCryptoKeyHandle Key, const uint8_t pKeyAlgOID[], int32_t szKeyAlgOID, const uint8_t pKeyAlgParams[], int32_t szKeyAlgParams, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_EncryptInit(TElPKCS11CryptoProviderHandle _Handle, int32_t Algorithm, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_EncryptInit_1(TElPKCS11CryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_DecryptInit(TElPKCS11CryptoProviderHandle _Handle, int32_t Algorithm, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_DecryptInit_1(TElPKCS11CryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_SignInit(TElPKCS11CryptoProviderHandle _Handle, int32_t Algorithm, TElCustomCryptoKeyHandle Key, int8_t Detached, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_SignInit_1(TElPKCS11CryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, TElCustomCryptoKeyHandle Key, int8_t Detached, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_VerifyInit(TElPKCS11CryptoProviderHandle _Handle, int32_t Algorithm, TElCustomCryptoKeyHandle Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_VerifyInit_1(TElPKCS11CryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, TElCustomCryptoKeyHandle Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_EncryptUpdate(TElPKCS11CryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_DecryptUpdate(TElPKCS11CryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_SignUpdate(TElPKCS11CryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_VerifyUpdate(TElPKCS11CryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_EncryptFinal(TElPKCS11CryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_DecryptFinal(TElPKCS11CryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_SignFinal(TElPKCS11CryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_VerifyFinal(TElPKCS11CryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_HashInit(TElPKCS11CryptoProviderHandle _Handle, int32_t Algorithm, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_HashInit_1(TElPKCS11CryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_HashUpdate(TElPKCS11CryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_HashFinal(TElPKCS11CryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_ReleaseCryptoContext(TElPKCS11CryptoProviderHandle _Handle, TElCustomCryptoContextHandle * Context);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_CreateKeyStorage(TElPKCS11CryptoProviderHandle _Handle, int8_t Persistent, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_ReleaseKeyStorage(TElPKCS11CryptoProviderHandle _Handle, TElCustomCryptoKeyStorageHandle * KeyStorage);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_DeleteKeyStorage(TElPKCS11CryptoProviderHandle _Handle, TElCustomCryptoKeyStorageHandle * KeyStorage);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_RandomInit(TElPKCS11CryptoProviderHandle _Handle, void * BaseData, int32_t BaseDataSize, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_RandomSeed(TElPKCS11CryptoProviderHandle _Handle, void * Data, int32_t DataSize);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_RandomGenerate(TElPKCS11CryptoProviderHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_RandomGenerate_1(TElPKCS11CryptoProviderHandle _Handle, int32_t MaxValue, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_get_OnAttributesPrepared(TElPKCS11CryptoProviderHandle _Handle, TSBPKCS11CryptoProviderAttributesPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_set_OnAttributesPrepared(TElPKCS11CryptoProviderHandle _Handle, TSBPKCS11CryptoProviderAttributesPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_Create(TComponentHandle AOwner, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoProvider_Create_1(TElCustomCryptoProviderOptionsHandle Options, TComponentHandle AOwner, TElCustomCryptoProviderHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11CRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELPKCS11CRYPTOKEY
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoKey_Reset(TElPKCS11CryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoKey_Generate(TElPKCS11CryptoKeyHandle _Handle, int32_t Bits, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoKey_ChangeAlgorithm(TElPKCS11CryptoKeyHandle _Handle, int32_t Algorithm);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoKey_ImportPublic(TElPKCS11CryptoKeyHandle _Handle, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoKey_ImportSecret(TElPKCS11CryptoKeyHandle _Handle, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoKey_ExportPublic(TElPKCS11CryptoKeyHandle _Handle, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoKey_ExportSecret(TElPKCS11CryptoKeyHandle _Handle, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoKey_Clone(TElPKCS11CryptoKeyHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoKey_ClonePublic(TElPKCS11CryptoKeyHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoKey_ClearPublic(TElPKCS11CryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoKey_ClearSecret(TElPKCS11CryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoKey_GetKeyProp(TElPKCS11CryptoKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pDefault[], int32_t szDefault, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoKey_SetKeyProp(TElPKCS11CryptoKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoKey_PrepareForEncryption(TElPKCS11CryptoKeyHandle _Handle, int8_t MultiUse);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoKey_PrepareForSigning(TElPKCS11CryptoKeyHandle _Handle, int8_t MultiUse);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoKey_CancelPreparation(TElPKCS11CryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoKey_AsyncOperationFinished(TElPKCS11CryptoKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoKey_Equals(TElPKCS11CryptoKeyHandle _Handle, TElCustomCryptoKeyHandle Source, int8_t PublicOnly, TElRelativeDistinguishedNameHandle Params, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoKey_Persistentiate(TElPKCS11CryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoKey_Create(TElCustomCryptoProviderHandle CryptoProvider, TElPKCS11CryptoKeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11CRYPTOKEY */

#ifdef SB_USE_CLASS_TELPKCS11CRYPTOCONTEXT
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoContext_EstimateOutputSize(TElPKCS11CryptoContextHandle _Handle, int64_t InSize, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoContext_Clone(TElPKCS11CryptoContextHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoContext_GetContextProp(TElPKCS11CryptoContextHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pDefault[], int32_t szDefault, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoContext_SetContextProp(TElPKCS11CryptoContextHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoContext_Create(int32_t Algorithm, int32_t Mode, TElCustomCryptoKeyHandle Key, TSBPKCS11CryptoContextOperationRaw Operation, TElCustomCryptoProviderHandle Prov, TElRelativeDistinguishedNameHandle Params, TElPKCS11CryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CryptoContext_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, TElCustomCryptoKeyHandle Key, TSBPKCS11CryptoContextOperationRaw Operation, TElCustomCryptoProviderHandle Prov, TElRelativeDistinguishedNameHandle Params, TElPKCS11CryptoContextHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11CRYPTOCONTEXT */

#ifdef SB_USE_CLASS_TELPKCS11ECPARAMSDIRECTORY
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ECParamsDirectory_AddKnownCurve(TElPKCS11ECParamsDirectoryHandle _Handle, const char * pcName, int32_t szName, const uint8_t pCurveOID[], int32_t szCurveOID, int32_t KeyBits);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ECParamsDirectory_GetKeyBits(TElPKCS11ECParamsDirectoryHandle _Handle, const uint8_t pCurveOID[], int32_t szCurveOID, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ECParamsDirectory_IsKnownCurve(TElPKCS11ECParamsDirectoryHandle _Handle, const uint8_t pCurveOID[], int32_t szCurveOID, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ECParamsDirectory_Create(TElPKCS11ECParamsDirectoryHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11ECPARAMSDIRECTORY */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPKCS11CryptoProviderOptions;
class TElPKCS11CryptoProvider;
class TElPKCS11CryptoKey;
class TElPKCS11CryptoContext;
class TElPKCS11ECParamsDirectory;

#ifdef SB_USE_CLASS_TELPKCS11CRYPTOPROVIDEROPTIONS
class TElPKCS11CryptoProviderOptions: public TElCustomCryptoProviderOptions
{
	private:
		SB_DISABLE_COPY(TElPKCS11CryptoProviderOptions)
	public:
		virtual void Assign(TElCustomCryptoProviderOptions &Options);

		virtual void Assign(TElCustomCryptoProviderOptions *Options);

		virtual bool get_UseForPublicKeyOperations();

		virtual void set_UseForPublicKeyOperations(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseForPublicKeyOperations, set_UseForPublicKeyOperations, TElPKCS11CryptoProviderOptions, UseForPublicKeyOperations);

		virtual bool get_UseForSymmetricKeyOperations();

		virtual void set_UseForSymmetricKeyOperations(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseForSymmetricKeyOperations, set_UseForSymmetricKeyOperations, TElPKCS11CryptoProviderOptions, UseForSymmetricKeyOperations);

		virtual bool get_UseForHashingOperations();

		virtual void set_UseForHashingOperations(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseForHashingOperations, set_UseForHashingOperations, TElPKCS11CryptoProviderOptions, UseForHashingOperations);

		virtual bool get_UseForNonPrivateOperations();

		virtual void set_UseForNonPrivateOperations(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseForNonPrivateOperations, set_UseForNonPrivateOperations, TElPKCS11CryptoProviderOptions, UseForNonPrivateOperations);

		virtual bool get_ForceUseForIndirectHashingOperations();

		virtual void set_ForceUseForIndirectHashingOperations(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ForceUseForIndirectHashingOperations, set_ForceUseForIndirectHashingOperations, TElPKCS11CryptoProviderOptions, ForceUseForIndirectHashingOperations);

		virtual bool get_DelayedPublicKeyImport();

		virtual void set_DelayedPublicKeyImport(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DelayedPublicKeyImport, set_DelayedPublicKeyImport, TElPKCS11CryptoProviderOptions, DelayedPublicKeyImport);

		virtual bool get_ThreadSafe();

		virtual void set_ThreadSafe(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ThreadSafe, set_ThreadSafe, TElPKCS11CryptoProviderOptions, ThreadSafe);

		virtual bool get_IgnoreReportedSupportedAlgorithms();

		virtual void set_IgnoreReportedSupportedAlgorithms(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreReportedSupportedAlgorithms, set_IgnoreReportedSupportedAlgorithms, TElPKCS11CryptoProviderOptions, IgnoreReportedSupportedAlgorithms);

		virtual bool get_NormalizeSourceLength();

		virtual void set_NormalizeSourceLength(bool Value);

		SB_DECLARE_PROPERTY(bool, get_NormalizeSourceLength, set_NormalizeSourceLength, TElPKCS11CryptoProviderOptions, NormalizeSourceLength);

		virtual void get_OperationPIN(std::string &OutResult);

		virtual void set_OperationPIN(const std::string &Value);

		virtual void get_DefaultRSAPublicExponent(std::vector<uint8_t> &OutResult);

		virtual void set_DefaultRSAPublicExponent(const std::vector<uint8_t> &Value);

		TElPKCS11CryptoProviderOptions(TElPKCS11CryptoProviderOptionsHandle handle, TElOwnHandle ownHandle);

		TElPKCS11CryptoProviderOptions();

};
#endif /* SB_USE_CLASS_TELPKCS11CRYPTOPROVIDEROPTIONS */

#ifdef SB_USE_CLASS_TELPKCS11CRYPTOPROVIDER
class TElPKCS11CryptoProvider: public TElExternalCryptoProvider
{
	private:
		SB_DISABLE_COPY(TElPKCS11CryptoProvider)
	public:
		virtual void Init();

		virtual void Deinit();

		static void SetAsDefault();

		virtual void SetAsDefault_Inst();

		virtual TElCustomCryptoProviderHandle Clone();

		virtual bool IsAlgorithmSupported(int32_t Algorithm, int32_t Mode);

		virtual bool IsAlgorithmSupported(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode);

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual bool IsOperationSupported(int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params);

		virtual bool IsOperationSupported(int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual bool IsOperationSupported(int32_t Operation, const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params);

		virtual bool IsOperationSupported(int32_t Operation, const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

		virtual void GetAlgorithmProperty(int32_t Algorithm, int32_t Mode, const std::vector<uint8_t> &PropID, std::vector<uint8_t> &OutResult);

		virtual void GetAlgorithmProperty(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, const std::vector<uint8_t> &PropID, std::vector<uint8_t> &OutResult);

		virtual int32_t GetAlgorithmClass(int32_t Algorithm);

		virtual int32_t GetAlgorithmClass(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams);

		virtual void GetProviderProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult);

#ifdef SB_IOS
		virtual TObjectHandle GetProviderProp(const std::vector<uint8_t> &PropID, TObject &Default);

		virtual TObjectHandle GetProviderProp(const std::vector<uint8_t> &PropID, TObject *Default);
#endif

		virtual void SetProviderProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value);

#ifdef SB_IOS
		virtual void SetProviderProp(const std::vector<uint8_t> &PropID, TObject &Value);

		virtual void SetProviderProp(const std::vector<uint8_t> &PropID, TObject *Value);
#endif

		virtual TElCustomCryptoProviderHandle GetDefaultInstance();

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoKeyHandle CreateKey(int32_t Algorithm, int32_t Mode, TElRelativeDistinguishedName &Params);

		virtual TElCustomCryptoKeyHandle CreateKey(int32_t Algorithm, int32_t Mode, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoKeyHandle CreateKey(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElRelativeDistinguishedName &Params);

		virtual TElCustomCryptoKeyHandle CreateKey(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
		virtual TElCustomCryptoKeyHandle CloneKey(TElCustomCryptoKey &Key);

		virtual TElCustomCryptoKeyHandle CloneKey(TElCustomCryptoKey *Key);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
		virtual void ReleaseKey(TElCustomCryptoKey &Key);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
		virtual void DeleteKey(TElCustomCryptoKey &Key);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoKeyHandle DecryptKey(void * EncKey, int32_t EncKeySize, const std::vector<uint8_t> &EncKeyAlgOID, const std::vector<uint8_t> &EncKeyAlgParams, TElCustomCryptoKey &Key, const std::vector<uint8_t> &KeyAlgOID, const std::vector<uint8_t> &KeyAlgParams, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual TElCustomCryptoKeyHandle DecryptKey(void * EncKey, int32_t EncKeySize, const std::vector<uint8_t> &EncKeyAlgOID, const std::vector<uint8_t> &EncKeyAlgParams, TElCustomCryptoKey *Key, const std::vector<uint8_t> &KeyAlgOID, const std::vector<uint8_t> &KeyAlgParams, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoContextHandle EncryptInit(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual TElCustomCryptoContextHandle EncryptInit(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoContextHandle EncryptInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual TElCustomCryptoContextHandle EncryptInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoContextHandle DecryptInit(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual TElCustomCryptoContextHandle DecryptInit(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoContextHandle DecryptInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual TElCustomCryptoContextHandle DecryptInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoContextHandle SignInit(int32_t Algorithm, TElCustomCryptoKey &Key, bool Detached, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual TElCustomCryptoContextHandle SignInit(int32_t Algorithm, TElCustomCryptoKey *Key, bool Detached, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoContextHandle SignInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, bool Detached, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual TElCustomCryptoContextHandle SignInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, bool Detached, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoContextHandle VerifyInit(int32_t Algorithm, TElCustomCryptoKey &Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual TElCustomCryptoContextHandle VerifyInit(int32_t Algorithm, TElCustomCryptoKey *Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoContextHandle VerifyInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual TElCustomCryptoContextHandle VerifyInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual void EncryptUpdate(TElCustomCryptoContext &Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void EncryptUpdate(TElCustomCryptoContext *Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual void DecryptUpdate(TElCustomCryptoContext &Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void DecryptUpdate(TElCustomCryptoContext *Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual void SignUpdate(TElCustomCryptoContext &Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void SignUpdate(TElCustomCryptoContext *Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual void VerifyUpdate(TElCustomCryptoContext &Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void VerifyUpdate(TElCustomCryptoContext *Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual void EncryptFinal(TElCustomCryptoContext &Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void EncryptFinal(TElCustomCryptoContext *Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual void DecryptFinal(TElCustomCryptoContext &Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void DecryptFinal(TElCustomCryptoContext *Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual void SignFinal(TElCustomCryptoContext &Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void SignFinal(TElCustomCryptoContext *Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual int32_t VerifyFinal(TElCustomCryptoContext &Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual int32_t VerifyFinal(TElCustomCryptoContext *Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoContextHandle HashInit(int32_t Algorithm, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual TElCustomCryptoContextHandle HashInit(int32_t Algorithm, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoContextHandle HashInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual TElCustomCryptoContextHandle HashInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual void HashUpdate(TElCustomCryptoContext &Context, void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void HashUpdate(TElCustomCryptoContext *Context, void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual void HashFinal(TElCustomCryptoContext &Context, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, std::vector<uint8_t> &OutResult);

		virtual void HashFinal(TElCustomCryptoContext *Context, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOCONTEXT
		virtual void ReleaseCryptoContext(TElCustomCryptoContext &Context);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOCONTEXT */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEYSTORAGE_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoKeyStorageHandle CreateKeyStorage(bool Persistent, TElRelativeDistinguishedName &Params);

		virtual TElCustomCryptoKeyStorageHandle CreateKeyStorage(bool Persistent, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEYSTORAGE_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE
		virtual void ReleaseKeyStorage(TElCustomCryptoKeyStorage &KeyStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE
		virtual void DeleteKeyStorage(TElCustomCryptoKeyStorage &KeyStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void RandomInit(void * BaseData, int32_t BaseDataSize, TElRelativeDistinguishedName &Params);

		virtual void RandomInit(void * BaseData, int32_t BaseDataSize, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void RandomSeed(void * Data, int32_t DataSize);

		virtual void RandomGenerate(void * Buffer, int32_t Size);

		virtual int32_t RandomGenerate(int32_t MaxValue);

		static TClassHandle ClassType();

		virtual void get_OnAttributesPrepared(TSBPKCS11CryptoProviderAttributesPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAttributesPrepared(TSBPKCS11CryptoProviderAttributesPreparedEvent pMethodValue, void * pDataValue);

		TElPKCS11CryptoProvider(TElPKCS11CryptoProviderHandle handle, TElOwnHandle ownHandle);

		explicit TElPKCS11CryptoProvider(TComponent &AOwner);

		explicit TElPKCS11CryptoProvider(TComponent *AOwner);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS
		TElPKCS11CryptoProvider(TElCustomCryptoProviderOptions &Options, TComponent &AOwner);

		TElPKCS11CryptoProvider(TElCustomCryptoProviderOptions *Options, TComponent *AOwner);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS */

};
#endif /* SB_USE_CLASS_TELPKCS11CRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELPKCS11CRYPTOKEY
class TElPKCS11CryptoKey: public TElCustomCryptoKey
{
	private:
		SB_DISABLE_COPY(TElPKCS11CryptoKey)
	public:
		virtual void Reset();

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void Generate(int32_t Bits, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void Generate(int32_t Bits, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void ChangeAlgorithm(int32_t Algorithm);

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

		virtual void PrepareForEncryption(bool MultiUse);

		virtual void PrepareForSigning(bool MultiUse);

		virtual void CancelPreparation();

		virtual bool AsyncOperationFinished();

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual bool Equals(TElCustomCryptoKey &Source, bool PublicOnly, TElRelativeDistinguishedName &Params);

		virtual bool Equals(TElCustomCryptoKey *Source, bool PublicOnly, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void Persistentiate();

		TElPKCS11CryptoKey(TElPKCS11CryptoKeyHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElPKCS11CryptoKey(TElCustomCryptoProvider &CryptoProvider);

		explicit TElPKCS11CryptoKey(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

};
#endif /* SB_USE_CLASS_TELPKCS11CRYPTOKEY */

#ifdef SB_USE_CLASS_TELPKCS11CRYPTOCONTEXT
class TElPKCS11CryptoContext: public TElCustomCryptoContext
{
	private:
		SB_DISABLE_COPY(TElPKCS11CryptoContext)
	public:
		virtual int64_t EstimateOutputSize(int64_t InSize);

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoContextHandle Clone(TElRelativeDistinguishedName &Params);

		virtual TElCustomCryptoContextHandle Clone(TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void GetContextProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult);

		virtual void SetContextProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value);

		TElPKCS11CryptoContext(TElPKCS11CryptoContextHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME
		TElPKCS11CryptoContext(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, TSBPKCS11CryptoContextOperation Operation, TElCustomCryptoProvider &Prov, TElRelativeDistinguishedName &Params);

		TElPKCS11CryptoContext(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, TSBPKCS11CryptoContextOperation Operation, TElCustomCryptoProvider *Prov, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME
		TElPKCS11CryptoContext(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, TSBPKCS11CryptoContextOperation Operation, TElCustomCryptoProvider &Prov, TElRelativeDistinguishedName &Params);

		TElPKCS11CryptoContext(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, TSBPKCS11CryptoContextOperation Operation, TElCustomCryptoProvider *Prov, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME */

};
#endif /* SB_USE_CLASS_TELPKCS11CRYPTOCONTEXT */

#ifdef SB_USE_CLASS_TELPKCS11ECPARAMSDIRECTORY
class TElPKCS11ECParamsDirectory: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11ECParamsDirectory)
	public:
		void AddKnownCurve(const std::string &Name, const std::vector<uint8_t> &CurveOID, int32_t KeyBits);

		int32_t GetKeyBits(const std::vector<uint8_t> &CurveOID);

		bool IsKnownCurve(const std::vector<uint8_t> &CurveOID);

		TElPKCS11ECParamsDirectory(TElPKCS11ECParamsDirectoryHandle handle, TElOwnHandle ownHandle);

		TElPKCS11ECParamsDirectory();

};
#endif /* SB_USE_CLASS_TELPKCS11ECPARAMSDIRECTORY */

#ifdef SB_USE_GLOBAL_PROCS_CRYPTOPROVPKCS11

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProviderHandle PKCS11CryptoProvider();
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#endif /* SB_USE_GLOBAL_PROCS_CRYPTOPROVPKCS11 */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_CRYPTOPROVPKCS11
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvPKCS11_PKCS11CryptoProvider(TElCustomCryptoProviderHandle * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_CRYPTOPROVPKCS11 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCRYPTOPROVPKCS11 */
