#ifndef __INC_SBCRYPTOPROVWIN32
#define __INC_SBCRYPTOPROVWIN32

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbcryptoprov.h"
#include "sbcryptoprovutils.h"
#include "sbcryptoprovrs.h"
#include "sbsharedresource.h"
#include "sbmskeyblob.h"
#include "sbasn1tree.h"
#include "sbrsa.h"
#include "sbdsa.h"
#include "sbeccommon.h"
#ifdef SB_WINDOWS
#include "sbwincrypt.h"
#endif
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbrandom.h"
#include "sbstrutils.h"
#ifdef SB_WINDOWS
#include "sbrdn.h"
#endif

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifdef SB_WINDOWS
typedef TElClassHandle TElWin32CryptoProviderOptionsHandle;

typedef TElClassHandle TElWin32CryptoProviderHandle;

typedef TElClassHandle TElCNGCryptoProviderHandleInfoHandle;

typedef TElClassHandle TElCNGCryptoProviderHandleManagerHandle;

#ifdef SB_USE_CLASS_TELWIN32CRYPTOPROVIDEROPTIONS
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_Assign(TElWin32CryptoProviderOptionsHandle _Handle, TElCustomCryptoProviderOptionsHandle Options);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_UseForPublicKeyOperations(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_UseForPublicKeyOperations(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_UseForSymmetricKeyOperations(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_UseForSymmetricKeyOperations(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_UseForHashingOperations(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_UseForHashingOperations(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_UseForNonPrivateOperations(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_UseForNonPrivateOperations(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_ThreadSafe(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_ThreadSafe(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_UseBaseCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_UseBaseCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_UseStrongCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_UseStrongCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_UseEnhancedCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_UseEnhancedCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_UseAESCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_UseAESCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_UseDSSCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_UseDSSCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_UseBaseDSSDHCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_UseBaseDSSDHCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_UseEnhancedDSSDHCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_UseEnhancedDSSDHCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_UseRSASchannelCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_UseRSASchannelCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_UseRSASignatureCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_UseRSASignatureCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_UseECDSASigCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_UseECDSASigCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_UseECNRASigCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_UseECNRASigCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_UseECDSAFullCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_UseECDSAFullCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_UseECNRAFullCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_UseECNRAFullCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_UseDHSchannelCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_UseDHSchannelCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_UseCPGOST(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_UseCPGOST(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_UseCNGProvider(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_UseCNGProvider(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_FIPSMode(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_FIPSMode(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_CacheKeyContexts(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_CacheKeyContexts(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_StorePublicKeysInMemoryContainers(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_StorePublicKeysInMemoryContainers(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_ForceEnhancedCSPForLongKeys(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_ForceEnhancedCSPForLongKeys(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_AutoSelectEnhancedCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_AutoSelectEnhancedCSP(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_TryAlternativeKeySpecOnFailure(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_TryAlternativeKeySpecOnFailure(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_GenerateExportablePrivateKeys(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_GenerateExportablePrivateKeys(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_get_UseLocalMachineAccount(TElWin32CryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_set_UseLocalMachineAccount(TElWin32CryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProviderOptions_Create(TElCustomCryptoProviderOptionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELWIN32CRYPTOPROVIDEROPTIONS */

#ifdef SB_USE_CLASS_TELWIN32CRYPTOPROVIDER
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_Init(TElWin32CryptoProviderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_Deinit(TElWin32CryptoProviderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_SetAsDefault();
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_SetAsDefault_1(TElWin32CryptoProviderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_IsAlgorithmSupported(TElWin32CryptoProviderHandle _Handle, int32_t Algorithm, int32_t Mode, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_IsAlgorithmSupported_1(TElWin32CryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_IsOperationSupported(TElWin32CryptoProviderHandle _Handle, int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_IsOperationSupported_1(TElWin32CryptoProviderHandle _Handle, int32_t Operation, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_GetAlgorithmProperty(TElWin32CryptoProviderHandle _Handle, int32_t Algorithm, int32_t Mode, const uint8_t pPropID[], int32_t szPropID, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_GetAlgorithmProperty_1(TElWin32CryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, const uint8_t pPropID[], int32_t szPropID, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_GetAlgorithmClass(TElWin32CryptoProviderHandle _Handle, int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_GetAlgorithmClass_1(TElWin32CryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_GetDefaultInstance(TElWin32CryptoProviderHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_CreateKey(TElWin32CryptoProviderHandle _Handle, int32_t Algorithm, int32_t Mode, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_CreateKey_1(TElWin32CryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_CloneKey(TElWin32CryptoProviderHandle _Handle, TElCustomCryptoKeyHandle Key, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_ReleaseKey(TElWin32CryptoProviderHandle _Handle, TElCustomCryptoKeyHandle * Key);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_DeleteKey(TElWin32CryptoProviderHandle _Handle, TElCustomCryptoKeyHandle * Key);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_DecryptKey(TElWin32CryptoProviderHandle _Handle, void * EncKey, int32_t EncKeySize, const uint8_t pEncKeyAlgOID[], int32_t szEncKeyAlgOID, const uint8_t pEncKeyAlgParams[], int32_t szEncKeyAlgParams, TElCustomCryptoKeyHandle Key, const uint8_t pKeyAlgOID[], int32_t szKeyAlgOID, const uint8_t pKeyAlgParams[], int32_t szKeyAlgParams, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_EncryptInit(TElWin32CryptoProviderHandle _Handle, int32_t Algorithm, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_EncryptInit_1(TElWin32CryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_DecryptInit(TElWin32CryptoProviderHandle _Handle, int32_t Algorithm, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_DecryptInit_1(TElWin32CryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_SignInit(TElWin32CryptoProviderHandle _Handle, int32_t Algorithm, TElCustomCryptoKeyHandle Key, int8_t Detached, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_SignInit_1(TElWin32CryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, TElCustomCryptoKeyHandle Key, int8_t Detached, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_VerifyInit(TElWin32CryptoProviderHandle _Handle, int32_t Algorithm, TElCustomCryptoKeyHandle Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_VerifyInit_1(TElWin32CryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, TElCustomCryptoKeyHandle Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_EncryptUpdate(TElWin32CryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_DecryptUpdate(TElWin32CryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_SignUpdate(TElWin32CryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_VerifyUpdate(TElWin32CryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_EncryptFinal(TElWin32CryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_DecryptFinal(TElWin32CryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_SignFinal(TElWin32CryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_VerifyFinal(TElWin32CryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_HashInit(TElWin32CryptoProviderHandle _Handle, int32_t Algorithm, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_HashInit_1(TElWin32CryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_HashUpdate(TElWin32CryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_HashFinal(TElWin32CryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_ReleaseCryptoContext(TElWin32CryptoProviderHandle _Handle, TElCustomCryptoContextHandle * Context);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_CreateKeyStorage(TElWin32CryptoProviderHandle _Handle, int8_t Persistent, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_ReleaseKeyStorage(TElWin32CryptoProviderHandle _Handle, TElCustomCryptoKeyStorageHandle * KeyStorage);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_DeleteKeyStorage(TElWin32CryptoProviderHandle _Handle, TElCustomCryptoKeyStorageHandle * KeyStorage);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_RandomInit(TElWin32CryptoProviderHandle _Handle, void * BaseData, int32_t BaseDataSize, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_RandomSeed(TElWin32CryptoProviderHandle _Handle, void * Data, int32_t DataSize);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_RandomGenerate(TElWin32CryptoProviderHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_RandomGenerate_1(TElWin32CryptoProviderHandle _Handle, int32_t MaxValue, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_GetProviderProp(TElWin32CryptoProviderHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pDefault[], int32_t szDefault, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_SetProviderProp(TElWin32CryptoProviderHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_get_TryEnhancedCryptoProvider(TElWin32CryptoProviderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_set_TryEnhancedCryptoProvider(TElWin32CryptoProviderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_get_NativeSizeCalculation(TElWin32CryptoProviderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_set_NativeSizeCalculation(TElWin32CryptoProviderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_Create(TComponentHandle AOwner, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWin32CryptoProvider_Create_1(TElCustomCryptoProviderOptionsHandle Options, TComponentHandle AOwner, TElCustomCryptoProviderHandle * OutResult);
#endif /* SB_USE_CLASS_TELWIN32CRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCNGCRYPTOPROVIDERHANDLEINFO
SB_IMPORT uint32_t SB_APIENTRY TElCNGCryptoProviderHandleInfo_Create(uint32_t * Handle, TElCNGCryptoProviderHandleInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELCNGCRYPTOPROVIDERHANDLEINFO */

#ifdef SB_USE_CLASS_TELCNGCRYPTOPROVIDERHANDLEMANAGER
#ifndef CPU64
SB_IMPORT uint32_t SB_APIENTRY TElCNGCryptoProviderHandleManager_OpenCNGStorageProvider(TElCNGCryptoProviderHandleManagerHandle _Handle, uint32_t * phProvider, sb_char16_t * pszProviderName, uint32_t dwFlags, uint32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElCNGCryptoProviderHandleManager_OpenCNGStorageProvider(TElCNGCryptoProviderHandleManagerHandle _Handle, int64_t * phProvider, sb_char16_t * pszProviderName, uint32_t dwFlags, uint32_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElCNGCryptoProviderHandleManager_OpenCNGStorageProvider_1(TElCNGCryptoProviderHandleManagerHandle _Handle, uint32_t * * phProvider, sb_char16_t * pszProviderName, uint32_t dwFlags, uint32_t * OutResult);
#ifndef CPU64
SB_IMPORT uint32_t SB_APIENTRY TElCNGCryptoProviderHandleManager_FreeCNGStorageProvider(TElCNGCryptoProviderHandleManagerHandle _Handle, uint32_t hProvider);
SB_IMPORT uint32_t SB_APIENTRY TElCNGCryptoProviderHandleManager_CNGStorageProviderAddRef(TElCNGCryptoProviderHandleManagerHandle _Handle, uint32_t hProvider);
#else
SB_IMPORT uint32_t SB_APIENTRY TElCNGCryptoProviderHandleManager_FreeCNGStorageProvider(TElCNGCryptoProviderHandleManagerHandle _Handle, int64_t hProvider);
SB_IMPORT uint32_t SB_APIENTRY TElCNGCryptoProviderHandleManager_CNGStorageProviderAddRef(TElCNGCryptoProviderHandleManagerHandle _Handle, int64_t hProvider);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElCNGCryptoProviderHandleManager_Create(TElCNGCryptoProviderHandleManagerHandle * OutResult);
#endif /* SB_USE_CLASS_TELCNGCRYPTOPROVIDERHANDLEMANAGER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElWin32CryptoProviderOptions;
class TElWin32CryptoProvider;
class TElCNGCryptoProviderHandleInfo;
class TElCNGCryptoProviderHandleManager;

#ifdef SB_USE_CLASS_TELWIN32CRYPTOPROVIDEROPTIONS
class TElWin32CryptoProviderOptions: public TElCustomCryptoProviderOptions
{
	private:
		SB_DISABLE_COPY(TElWin32CryptoProviderOptions)
	public:
		virtual void Assign(TElCustomCryptoProviderOptions &Options);

		virtual void Assign(TElCustomCryptoProviderOptions *Options);

		virtual bool get_UseForPublicKeyOperations();

		virtual void set_UseForPublicKeyOperations(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseForPublicKeyOperations, set_UseForPublicKeyOperations, TElWin32CryptoProviderOptions, UseForPublicKeyOperations);

		virtual bool get_UseForSymmetricKeyOperations();

		virtual void set_UseForSymmetricKeyOperations(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseForSymmetricKeyOperations, set_UseForSymmetricKeyOperations, TElWin32CryptoProviderOptions, UseForSymmetricKeyOperations);

		virtual bool get_UseForHashingOperations();

		virtual void set_UseForHashingOperations(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseForHashingOperations, set_UseForHashingOperations, TElWin32CryptoProviderOptions, UseForHashingOperations);

		virtual bool get_UseForNonPrivateOperations();

		virtual void set_UseForNonPrivateOperations(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseForNonPrivateOperations, set_UseForNonPrivateOperations, TElWin32CryptoProviderOptions, UseForNonPrivateOperations);

		virtual bool get_ThreadSafe();

		virtual void set_ThreadSafe(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ThreadSafe, set_ThreadSafe, TElWin32CryptoProviderOptions, ThreadSafe);

		virtual bool get_UseBaseCSP();

		virtual void set_UseBaseCSP(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseBaseCSP, set_UseBaseCSP, TElWin32CryptoProviderOptions, UseBaseCSP);

		virtual bool get_UseStrongCSP();

		virtual void set_UseStrongCSP(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseStrongCSP, set_UseStrongCSP, TElWin32CryptoProviderOptions, UseStrongCSP);

		virtual bool get_UseEnhancedCSP();

		virtual void set_UseEnhancedCSP(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseEnhancedCSP, set_UseEnhancedCSP, TElWin32CryptoProviderOptions, UseEnhancedCSP);

		virtual bool get_UseAESCSP();

		virtual void set_UseAESCSP(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseAESCSP, set_UseAESCSP, TElWin32CryptoProviderOptions, UseAESCSP);

		virtual bool get_UseDSSCSP();

		virtual void set_UseDSSCSP(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseDSSCSP, set_UseDSSCSP, TElWin32CryptoProviderOptions, UseDSSCSP);

		virtual bool get_UseBaseDSSDHCSP();

		virtual void set_UseBaseDSSDHCSP(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseBaseDSSDHCSP, set_UseBaseDSSDHCSP, TElWin32CryptoProviderOptions, UseBaseDSSDHCSP);

		virtual bool get_UseEnhancedDSSDHCSP();

		virtual void set_UseEnhancedDSSDHCSP(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseEnhancedDSSDHCSP, set_UseEnhancedDSSDHCSP, TElWin32CryptoProviderOptions, UseEnhancedDSSDHCSP);

		virtual bool get_UseRSASchannelCSP();

		virtual void set_UseRSASchannelCSP(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseRSASchannelCSP, set_UseRSASchannelCSP, TElWin32CryptoProviderOptions, UseRSASchannelCSP);

		virtual bool get_UseRSASignatureCSP();

		virtual void set_UseRSASignatureCSP(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseRSASignatureCSP, set_UseRSASignatureCSP, TElWin32CryptoProviderOptions, UseRSASignatureCSP);

		virtual bool get_UseECDSASigCSP();

		virtual void set_UseECDSASigCSP(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseECDSASigCSP, set_UseECDSASigCSP, TElWin32CryptoProviderOptions, UseECDSASigCSP);

		virtual bool get_UseECNRASigCSP();

		virtual void set_UseECNRASigCSP(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseECNRASigCSP, set_UseECNRASigCSP, TElWin32CryptoProviderOptions, UseECNRASigCSP);

		virtual bool get_UseECDSAFullCSP();

		virtual void set_UseECDSAFullCSP(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseECDSAFullCSP, set_UseECDSAFullCSP, TElWin32CryptoProviderOptions, UseECDSAFullCSP);

		virtual bool get_UseECNRAFullCSP();

		virtual void set_UseECNRAFullCSP(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseECNRAFullCSP, set_UseECNRAFullCSP, TElWin32CryptoProviderOptions, UseECNRAFullCSP);

		virtual bool get_UseDHSchannelCSP();

		virtual void set_UseDHSchannelCSP(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseDHSchannelCSP, set_UseDHSchannelCSP, TElWin32CryptoProviderOptions, UseDHSchannelCSP);

		virtual bool get_UseCPGOST();

		virtual void set_UseCPGOST(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseCPGOST, set_UseCPGOST, TElWin32CryptoProviderOptions, UseCPGOST);

		virtual bool get_UseCNGProvider();

		virtual void set_UseCNGProvider(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseCNGProvider, set_UseCNGProvider, TElWin32CryptoProviderOptions, UseCNGProvider);

		virtual bool get_FIPSMode();

		virtual void set_FIPSMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_FIPSMode, set_FIPSMode, TElWin32CryptoProviderOptions, FIPSMode);

		virtual bool get_CacheKeyContexts();

		virtual void set_CacheKeyContexts(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CacheKeyContexts, set_CacheKeyContexts, TElWin32CryptoProviderOptions, CacheKeyContexts);

		virtual bool get_StorePublicKeysInMemoryContainers();

		virtual void set_StorePublicKeysInMemoryContainers(bool Value);

		SB_DECLARE_PROPERTY(bool, get_StorePublicKeysInMemoryContainers, set_StorePublicKeysInMemoryContainers, TElWin32CryptoProviderOptions, StorePublicKeysInMemoryContainers);

		virtual bool get_ForceEnhancedCSPForLongKeys();

		virtual void set_ForceEnhancedCSPForLongKeys(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ForceEnhancedCSPForLongKeys, set_ForceEnhancedCSPForLongKeys, TElWin32CryptoProviderOptions, ForceEnhancedCSPForLongKeys);

		virtual bool get_AutoSelectEnhancedCSP();

		virtual void set_AutoSelectEnhancedCSP(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoSelectEnhancedCSP, set_AutoSelectEnhancedCSP, TElWin32CryptoProviderOptions, AutoSelectEnhancedCSP);

		virtual bool get_TryAlternativeKeySpecOnFailure();

		virtual void set_TryAlternativeKeySpecOnFailure(bool Value);

		SB_DECLARE_PROPERTY(bool, get_TryAlternativeKeySpecOnFailure, set_TryAlternativeKeySpecOnFailure, TElWin32CryptoProviderOptions, TryAlternativeKeySpecOnFailure);

		virtual bool get_GenerateExportablePrivateKeys();

		virtual void set_GenerateExportablePrivateKeys(bool Value);

		SB_DECLARE_PROPERTY(bool, get_GenerateExportablePrivateKeys, set_GenerateExportablePrivateKeys, TElWin32CryptoProviderOptions, GenerateExportablePrivateKeys);

		virtual bool get_UseLocalMachineAccount();

		virtual void set_UseLocalMachineAccount(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseLocalMachineAccount, set_UseLocalMachineAccount, TElWin32CryptoProviderOptions, UseLocalMachineAccount);

		TElWin32CryptoProviderOptions(TElWin32CryptoProviderOptionsHandle handle, TElOwnHandle ownHandle);

		TElWin32CryptoProviderOptions();

};
#endif /* SB_USE_CLASS_TELWIN32CRYPTOPROVIDEROPTIONS */

#ifdef SB_USE_CLASS_TELWIN32CRYPTOPROVIDER
class TElWin32CryptoProvider: public TElExternalCryptoProvider
{
	private:
		SB_DISABLE_COPY(TElWin32CryptoProvider)
	public:
		virtual void Init();

		virtual void Deinit();

		static void SetAsDefault();

		virtual void SetAsDefault_Inst();

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

		virtual void GetProviderProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult);

		virtual void SetProviderProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value);

		static TClassHandle ClassType();

		virtual bool get_TryEnhancedCryptoProvider();

		virtual void set_TryEnhancedCryptoProvider(bool Value);

		SB_DECLARE_PROPERTY(bool, get_TryEnhancedCryptoProvider, set_TryEnhancedCryptoProvider, TElWin32CryptoProvider, TryEnhancedCryptoProvider);

		virtual bool get_NativeSizeCalculation();

		virtual void set_NativeSizeCalculation(bool Value);

		SB_DECLARE_PROPERTY(bool, get_NativeSizeCalculation, set_NativeSizeCalculation, TElWin32CryptoProvider, NativeSizeCalculation);

		TElWin32CryptoProvider(TElWin32CryptoProviderHandle handle, TElOwnHandle ownHandle);

		explicit TElWin32CryptoProvider(TComponent &AOwner);

		explicit TElWin32CryptoProvider(TComponent *AOwner);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS
		TElWin32CryptoProvider(TElCustomCryptoProviderOptions &Options, TComponent &AOwner);

		TElWin32CryptoProvider(TElCustomCryptoProviderOptions *Options, TComponent *AOwner);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS */

};
#endif /* SB_USE_CLASS_TELWIN32CRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCNGCRYPTOPROVIDERHANDLEINFO
class TElCNGCryptoProviderHandleInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElCNGCryptoProviderHandleInfo)
	public:
		TElCNGCryptoProviderHandleInfo(TElCNGCryptoProviderHandleInfoHandle handle, TElOwnHandle ownHandle);

		explicit TElCNGCryptoProviderHandleInfo(uint32_t * Handle);

};
#endif /* SB_USE_CLASS_TELCNGCRYPTOPROVIDERHANDLEINFO */

#ifdef SB_USE_CLASS_TELCNGCRYPTOPROVIDERHANDLEMANAGER
class TElCNGCryptoProviderHandleManager: public TObject
{
	private:
		SB_DISABLE_COPY(TElCNGCryptoProviderHandleManager)
	public:
#ifndef CPU64
		uint32_t OpenCNGStorageProvider(uint32_t &phProvider, sb_char16_t * pszProviderName, uint32_t dwFlags);
#else
		uint32_t OpenCNGStorageProvider(int64_t &phProvider, sb_char16_t * pszProviderName, uint32_t dwFlags);
#endif

		uint32_t OpenCNGStorageProvider(uint32_t * &phProvider, sb_char16_t * pszProviderName, uint32_t dwFlags);

#ifndef CPU64
		void FreeCNGStorageProvider(uint32_t hProvider);
#else
		void FreeCNGStorageProvider(int64_t hProvider);
#endif

#ifndef CPU64
		void CNGStorageProviderAddRef(uint32_t hProvider);
#else
		void CNGStorageProviderAddRef(int64_t hProvider);
#endif

		TElCNGCryptoProviderHandleManager(TElCNGCryptoProviderHandleManagerHandle handle, TElOwnHandle ownHandle);

		TElCNGCryptoProviderHandleManager();

};
#endif /* SB_USE_CLASS_TELCNGCRYPTOPROVIDERHANDLEMANAGER */

#ifdef SB_USE_GLOBAL_PROCS_CRYPTOPROVWIN32

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProviderHandle Win32CryptoProvider();
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELWIN32CRYPTOPROVIDEROPTIONS
TElCustomCryptoProviderHandle Win32CryptoProvider(TElWin32CryptoProviderOptions &OptionsTemplate);
TElCustomCryptoProviderHandle Win32CryptoProvider(TElWin32CryptoProviderOptions *OptionsTemplate);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELWIN32CRYPTOPROVIDEROPTIONS */

#endif /* SB_USE_GLOBAL_PROCS_CRYPTOPROVWIN32 */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_CRYPTOPROVWIN32
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvWin32_Win32CryptoProvider(TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvWin32_Win32CryptoProvider_1(TElWin32CryptoProviderOptionsHandle OptionsTemplate, TElCustomCryptoProviderHandle * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_CRYPTOPROVWIN32 */
#endif

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCRYPTOPROVWIN32 */
