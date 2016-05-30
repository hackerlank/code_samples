#ifndef __INC_SBCRYPTOPROV
#define __INC_SBCRYPTOPROV

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbrdn.h"
#include "sbasn1.h"
#include "sbmath.h"
#include "sbsharedresource.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbasn1tree.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ALGCLASS_NONE 	0
#define SB_ALGCLASS_BLOCK 	1
#define SB_ALGCLASS_STREAM 	2
#define SB_ALGCLASS_PUBLICKEY 	3
#define SB_ALGCLASS_HASH 	4
#define SB_SYMENC_MODE_DEFAULT 	0
#define SB_SYMENC_MODE_BLOCK 	1
#define SB_SYMENC_MODE_CBC 	2
#define SB_SYMENC_MODE_CFB8 	3
#define SB_SYMENC_MODE_CTR 	4
#define SB_SYMENC_MODE_ECB 	5
#define SB_SYMENC_MODE_CCM 	6
#define SB_SYMENC_MODE_GCM 	7
#define SB_SYMENC_MODE_AEADCHACHA20POLY1305 	8
#define SB_SYMENC_PADDING_NONE 	0
#define SB_SYMENC_PADDING_PKCS5 	1
#define SB_SYMENC_PADDING_ANSIX923 	2
#define SB_VR_SUCCESS 	0
#define SB_VR_INVALID_SIGNATURE 	1
#define SB_VR_KEY_NOT_FOUND 	2
#define SB_VR_FAILURE 	3
#define SB_OPTYPE_NONE 	0
#define SB_OPTYPE_ENCRYPT 	1
#define SB_OPTYPE_DECRYPT 	2
#define SB_OPTYPE_SIGN 	3
#define SB_OPTYPE_SIGN_DETACHED 	4
#define SB_OPTYPE_VERIFY 	5
#define SB_OPTYPE_VERIFY_DETACHED 	6
#define SB_OPTYPE_HASH 	7
#define SB_OPTYPE_KEY_GENERATE 	8
#define SB_OPTYPE_KEY_DECRYPT 	9
#define SB_OPTYPE_RANDOM 	10
#define SB_OPTYPE_KEY_CREATE 	11
#define SB_OPTYPE_KEYSTORAGE_CREATE 	12
#define SB_ERROR_FACILITY_CRYPTOPROV 	86016
#define SB_ERROR_CRYPTOPROV_ERROR_FLAG 	2048
#define SB_ERROR_CP_NOT_INITIALIZED 	88065
#define SB_ERROR_CP_FEATURE_NOT_SUPPORTED 	88066
#define SB_ERROR_CP_OPERATION_NOT_SUPPORTED 	88067
#define SB_ERROR_CP_METHOD_NOT_IMPLEMENTED 	88068
#define SB_ERROR_CP_INVALID_KEY_PROP 	88069
#define SB_ERROR_CP_INVALID_KEY_MATERIAL 	88070
#define SB_ERROR_CP_INVALID_KEY_SIZE 	88071
#define SB_ERROR_CP_INVALID_IV_SIZE 	88072
#define SB_ERROR_CP_INVALID_ALG 	88073
#define SB_ERROR_CP_INVALID_CONTEXT 	88074
#define SB_ERROR_CP_INVALID_CRYPTOPROV 	88075
#define SB_ERROR_CP_INVALID_MODE 	88076
#define SB_ERROR_CP_INVALID_PROP_VALUE 	88077
#define SB_ERROR_CP_INVALID_PADDING 	88078
#define SB_ERROR_CP_INVALID_OPERATION 	88079
#define SB_ERROR_CP_BUFFER_TOO_SMALL 	88080
#define SB_ERROR_CP_UNSUPPORTED_ALGORITHM 	88081
#define SB_ERROR_CP_UNSUPPORTED_PROPERTY 	88082
#define SB_ERROR_CP_UNSUPPORTED_PROP_VALUE 	88083
#define SB_ERROR_CP_UNSUPPORTED_PROVIDER 	88084
#define SB_ERROR_CP_UNSUPPORTED_KEY_FORMAT 	88085
#define SB_ERROR_CP_INSTANTIATION_FAILED 	88086
#define SB_ERROR_CP_CANT_UNREG_DEFAULT 	88087
#define SB_ERROR_CP_NO_SUITABLE_PROV 	88088
#define SB_ERROR_CP_CANT_CHANGE_ALG 	88089
#define SB_ERROR_CP_UNKNOWN_ALG_PROP 	88090
#define SB_ERROR_CP_CANT_CHANGE_RO_PROP 	88091
#define SB_ERROR_CP_WRONG_CONTEXT_TYPE 	88092
#define SB_ERROR_CP_CANT_CLONE_CONTEXT 	88093
#define SB_ERROR_CP_PRIMITIVE_OP_FAILED 	88094
#define SB_ERROR_CP_KEY_GENERATION_FAILED 	88095
#define SB_ERROR_CP_KEY_ALREADY_PREPARED 	88096
#define SB_ERROR_CP_KEY_NOT_PREPARED 	88097
#define SB_ERROR_CP_KEY_NOT_FOUND 	88098
#define SB_ERROR_CP_IV_NOT_FOUND 	88099
#define SB_ERROR_CP_WRONG_INPUT_SIZE 	88100
#define SB_ERROR_CP_INTERRUPTED_BY_USER 	88101
#define SB_ERROR_CP_WRONG_OBJECT_TYPE 	88102
#define SB_ERROR_CP_WRONG_KEY_TYPE 	88103
#define SB_ERROR_CP_NO_SESSION 	88104
#define SB_ERROR_CP_NO_MODULE 	88105
#define SB_ERROR_CP_NO_DRIVER 	88106
#define SB_ERROR_CP_KEY_NOT_EXPORTABLE 	88107
#define SB_ERROR_CP_OBJECT_ACQUIRED 	88108
#define SB_ERROR_CP_OBJECT_PERSISTENT 	88109
#define SB_ERROR_CP_BAD_DATA_FORMAT 	88110
#define SB_ERROR_CP_DATA_TOO_LARGE 	88111
#define SB_ERROR_CP_DECRYPTION_FAILED 	88112
#define SB_ERROR_CP_SIGNING_FAILED 	88113
#define SB_ERROR_CP_ELEVATION_NEEDED 	88165
#define SB_ERROR_CP_BACKEND_ERROR 	88265
#define SB_ERROR_CP_CONTEXT_NOT_ACQUIRED 	88266
#define SB_CRYPTOPROV_GENERAL_ERROR 	1

typedef TElRelativeDistinguishedNameHandle TElCPParametersHandle;

typedef TElClassHandle TElCustomCryptoProviderHandle;

typedef TElClassHandle TElCustomCryptoProviderManagerHandle;

typedef TElClassHandle TElCustomCryptoKeyStorageHandle;

typedef TElClassHandle TElCustomCryptoKeyHandle;

typedef TElClassHandle TElCustomCryptoContextHandle;

typedef TElClassHandle TElCustomCryptoProviderOptionsHandle;

typedef TElClassHandle TElBlackboxCryptoProviderHandle;

typedef TElClassHandle TElExternalCryptoProviderHandle;

typedef Pointer TElCPKeyHandle;

typedef void (SB_CALLBACK *TSBCryptoProviderObjectEvent)(void * _ObjectData, TObjectHandle Sender, TObjectHandle Obj);

typedef TElClassHandle TElCustomCryptoProviderClassHandle;

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_Init(TElCustomCryptoProviderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_Deinit(TElCustomCryptoProviderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_SetAsDefault();
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_SetAsDefault_1(TElCustomCryptoProviderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_GetDefaultInstance(TElCustomCryptoProviderHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_Clone(TElCustomCryptoProviderHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_IsAlgorithmSupported(TElCustomCryptoProviderHandle _Handle, int32_t Algorithm, int32_t Mode, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_IsAlgorithmSupported_1(TElCustomCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_IsOperationSupported(TElCustomCryptoProviderHandle _Handle, int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_IsOperationSupported_1(TElCustomCryptoProviderHandle _Handle, int32_t Operation, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_GetAlgorithmProperty(TElCustomCryptoProviderHandle _Handle, int32_t Algorithm, int32_t Mode, const uint8_t pPropID[], int32_t szPropID, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_GetAlgorithmProperty_1(TElCustomCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, const uint8_t pPropID[], int32_t szPropID, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_GetAlgorithmClass(TElCustomCryptoProviderHandle _Handle, int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_GetAlgorithmClass_1(TElCustomCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_GetProviderProp(TElCustomCryptoProviderHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pDefault[], int32_t szDefault, uint8_t pOutResult[], int32_t * szOutResult);
#ifdef SB_IOS
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_GetProviderProp_1(TElCustomCryptoProviderHandle _Handle, const uint8_t pPropID[], int32_t szPropID, TObjectHandle Default, TObjectHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_SetProviderProp(TElCustomCryptoProviderHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pValue[], int32_t szValue);
#ifdef SB_IOS
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_SetProviderProp_1(TElCustomCryptoProviderHandle _Handle, const uint8_t pPropID[], int32_t szPropID, TObjectHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_CreateKey(TElCustomCryptoProviderHandle _Handle, int32_t Algorithm, int32_t Mode, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_CreateKey_1(TElCustomCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_CloneKey(TElCustomCryptoProviderHandle _Handle, TElCustomCryptoKeyHandle Key, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_ReleaseKey(TElCustomCryptoProviderHandle _Handle, TElCustomCryptoKeyHandle * Key);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_DeleteKey(TElCustomCryptoProviderHandle _Handle, TElCustomCryptoKeyHandle * Key);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_DecryptKey(TElCustomCryptoProviderHandle _Handle, void * EncKey, int32_t EncKeySize, const uint8_t pEncKeyAlgOID[], int32_t szEncKeyAlgOID, const uint8_t pEncKeyAlgParams[], int32_t szEncKeyAlgParams, TElCustomCryptoKeyHandle Key, const uint8_t pKeyAlgOID[], int32_t szKeyAlgOID, const uint8_t pKeyAlgParams[], int32_t szKeyAlgParams, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_CreateKeyStorage(TElCustomCryptoProviderHandle _Handle, int8_t Persistent, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_ReleaseKeyStorage(TElCustomCryptoProviderHandle _Handle, TElCustomCryptoKeyStorageHandle * KeyStorage);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_DeleteKeyStorage(TElCustomCryptoProviderHandle _Handle, TElCustomCryptoKeyStorageHandle * KeyStorage);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_EncryptInit(TElCustomCryptoProviderHandle _Handle, int32_t Algorithm, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_EncryptInit_1(TElCustomCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_DecryptInit(TElCustomCryptoProviderHandle _Handle, int32_t Algorithm, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_DecryptInit_1(TElCustomCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_SignInit(TElCustomCryptoProviderHandle _Handle, int32_t Algorithm, TElCustomCryptoKeyHandle Key, int8_t Detached, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_SignInit_1(TElCustomCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, TElCustomCryptoKeyHandle Key, int8_t Detached, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_VerifyInit(TElCustomCryptoProviderHandle _Handle, int32_t Algorithm, TElCustomCryptoKeyHandle Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_VerifyInit_1(TElCustomCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, TElCustomCryptoKeyHandle Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_EncryptUpdate(TElCustomCryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_DecryptUpdate(TElCustomCryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_SignUpdate(TElCustomCryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_VerifyUpdate(TElCustomCryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_EncryptFinal(TElCustomCryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_DecryptFinal(TElCustomCryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_SignFinal(TElCustomCryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_VerifyFinal(TElCustomCryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_Encrypt(TElCustomCryptoProviderHandle _Handle, int32_t Algorithm, int32_t Mode, TElCustomCryptoKeyHandle Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_Encrypt_1(TElCustomCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, TElCustomCryptoKeyHandle Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_Decrypt(TElCustomCryptoProviderHandle _Handle, int32_t Algorithm, int32_t Mode, TElCustomCryptoKeyHandle Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_Decrypt_1(TElCustomCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, TElCustomCryptoKeyHandle Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_Sign(TElCustomCryptoProviderHandle _Handle, int32_t Algorithm, TElCustomCryptoKeyHandle Key, int8_t Detached, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_Sign_1(TElCustomCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, TElCustomCryptoKeyHandle Key, int8_t Detached, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_Verify(TElCustomCryptoProviderHandle _Handle, int32_t Algorithm, TElCustomCryptoKeyHandle Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_Verify_1(TElCustomCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, TElCustomCryptoKeyHandle Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_VerifyDetached(TElCustomCryptoProviderHandle _Handle, int32_t Algorithm, TElCustomCryptoKeyHandle Key, void * InBuffer, int32_t InSize, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_VerifyDetached_1(TElCustomCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, TElCustomCryptoKeyHandle Key, void * InBuffer, int32_t InSize, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_HashInit(TElCustomCryptoProviderHandle _Handle, int32_t Algorithm, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_HashInit_1(TElCustomCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_HashFinal(TElCustomCryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_HashUpdate(TElCustomCryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_Hash(TElCustomCryptoProviderHandle _Handle, int32_t Algorithm, TElCustomCryptoKeyHandle Key, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_Hash_1(TElCustomCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, TElCustomCryptoKeyHandle Key, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_ReleaseCryptoContext(TElCustomCryptoProviderHandle _Handle, TElCustomCryptoContextHandle * Context);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_RandomInit(TElCustomCryptoProviderHandle _Handle, void * BaseData, int32_t BaseDataSize, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_RandomSeed(TElCustomCryptoProviderHandle _Handle, void * Data, int32_t DataSize);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_RandomGenerate(TElCustomCryptoProviderHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_RandomGenerate_1(TElCustomCryptoProviderHandle _Handle, int32_t MaxValue, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_OwnsObject(TElCustomCryptoProviderHandle _Handle, TObjectHandle Obj, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_get_Options(TElCustomCryptoProviderHandle _Handle, TElCustomCryptoProviderOptionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_get_Enabled(TElCustomCryptoProviderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_set_Enabled(TElCustomCryptoProviderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_get_CryptoProviderManager(TElCustomCryptoProviderHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_set_CryptoProviderManager(TElCustomCryptoProviderHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_get_OnCreateObject(TElCustomCryptoProviderHandle _Handle, TSBCryptoProviderObjectEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_set_OnCreateObject(TElCustomCryptoProviderHandle _Handle, TSBCryptoProviderObjectEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_get_OnDestroyObject(TElCustomCryptoProviderHandle _Handle, TSBCryptoProviderObjectEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_set_OnDestroyObject(TElCustomCryptoProviderHandle _Handle, TSBCryptoProviderObjectEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_Create(TComponentHandle AOwner, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProvider_Create_1(TElCustomCryptoProviderOptionsHandle Options, TComponentHandle AOwner, TElCustomCryptoProviderHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_Init(TElCustomCryptoProviderManagerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_Deinit(TElCustomCryptoProviderManagerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_RegisterCryptoProvider(TElCustomCryptoProviderManagerHandle _Handle, TElCustomCryptoProviderHandle Prov, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_UnregisterCryptoProvider(TElCustomCryptoProviderManagerHandle _Handle, TElCustomCryptoProviderHandle Prov);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_UnregisterCryptoProvider_1(TElCustomCryptoProviderManagerHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_SetDefaultCryptoProvider(TElCustomCryptoProviderManagerHandle _Handle, TElCustomCryptoProviderHandle Prov);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_SetDefaultCryptoProvider_1(TElCustomCryptoProviderManagerHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_SetDefaultCryptoProviderType(TElCustomCryptoProviderManagerHandle _Handle, TElCustomCryptoProviderClassHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_GetSuitableProvider(TElCustomCryptoProviderManagerHandle _Handle, int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_GetSuitableProvider_1(TElCustomCryptoProviderManagerHandle _Handle, int32_t Operation, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_GetSuitableProvider_2(TElCustomCryptoProviderManagerHandle _Handle, int32_t Algorithm, int32_t Mode, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_GetSuitableProvider_3(TElCustomCryptoProviderManagerHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_IsOperationSupported(TElCustomCryptoProviderManagerHandle _Handle, int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_IsOperationSupported_1(TElCustomCryptoProviderManagerHandle _Handle, int32_t Operation, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_IsAlgorithmSupported(TElCustomCryptoProviderManagerHandle _Handle, int32_t Algorithm, int32_t Mode, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_IsAlgorithmSupported_1(TElCustomCryptoProviderManagerHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_IsProviderAllowed(TElCustomCryptoProviderManagerHandle _Handle, TElCustomCryptoProviderHandle Prov, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_GetAlgorithmProperty(TElCustomCryptoProviderManagerHandle _Handle, int32_t Algorithm, int32_t Mode, const uint8_t pPropID[], int32_t szPropID, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_GetAlgorithmProperty_1(TElCustomCryptoProviderManagerHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, const uint8_t pPropID[], int32_t szPropID, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_GetAlgorithmClass(TElCustomCryptoProviderManagerHandle _Handle, int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_GetAlgorithmClass_1(TElCustomCryptoProviderManagerHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_get_CryptoProviders(TElCustomCryptoProviderManagerHandle _Handle, int32_t Index, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_get_Count(TElCustomCryptoProviderManagerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_get_DefaultCryptoProvider(TElCustomCryptoProviderManagerHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderManager_Create(TComponentHandle AOwner, TElCustomCryptoProviderManagerHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKeyStorage_AddKey(TElCustomCryptoKeyStorageHandle _Handle, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKeyStorage_RemoveKey(TElCustomCryptoKeyStorageHandle _Handle, int32_t Index, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKeyStorage_RemoveKey_1(TElCustomCryptoKeyStorageHandle _Handle, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKeyStorage_Clear(TElCustomCryptoKeyStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKeyStorage_Clone(TElCustomCryptoKeyStorageHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKeyStorage_Lock(TElCustomCryptoKeyStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKeyStorage_Unlock(TElCustomCryptoKeyStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKeyStorage_GetStorageProp(TElCustomCryptoKeyStorageHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pDefault[], int32_t szDefault, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKeyStorage_SetStorageProp(TElCustomCryptoKeyStorageHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKeyStorage_get_Keys(TElCustomCryptoKeyStorageHandle _Handle, int32_t Index, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKeyStorage_get_Count(TElCustomCryptoKeyStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKeyStorage_get_IsPersistent(TElCustomCryptoKeyStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKeyStorage_get_CryptoProvider(TElCustomCryptoKeyStorageHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKeyStorage_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_Reset(TElCustomCryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_Generate(TElCustomCryptoKeyHandle _Handle, int32_t Bits, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_ImportPublic(TElCustomCryptoKeyHandle _Handle, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_ImportSecret(TElCustomCryptoKeyHandle _Handle, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_ExportPublic(TElCustomCryptoKeyHandle _Handle, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_ExportSecret(TElCustomCryptoKeyHandle _Handle, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_Clone(TElCustomCryptoKeyHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_ClonePublic(TElCustomCryptoKeyHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_ClearPublic(TElCustomCryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_ClearSecret(TElCustomCryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_GetKeyProp(TElCustomCryptoKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pDefault[], int32_t szDefault, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_SetKeyProp(TElCustomCryptoKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_GetKeyObjectProp(TElCustomCryptoKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const TObjectHandle Default, TObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_SetKeyObjectProp(TElCustomCryptoKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const TObjectHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_ChangeAlgorithm(TElCustomCryptoKeyHandle _Handle, int32_t Algorithm);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_PrepareForEncryption(TElCustomCryptoKeyHandle _Handle, int8_t MultiUse);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_PrepareForSigning(TElCustomCryptoKeyHandle _Handle, int8_t MultiUse);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_CancelPreparation(TElCustomCryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_AsyncOperationFinished(TElCustomCryptoKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_Equals(TElCustomCryptoKeyHandle _Handle, TElCustomCryptoKeyHandle Key, int8_t PublicOnly, TElRelativeDistinguishedNameHandle Params, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_Persistentiate(TElCustomCryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_get_IsPublic(TElCustomCryptoKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_get_IsSecret(TElCustomCryptoKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_get_IsExportable(TElCustomCryptoKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_get_IsPersistent(TElCustomCryptoKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_get_IsValid(TElCustomCryptoKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_get_Bits(TElCustomCryptoKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_get_Algorithm(TElCustomCryptoKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_get_Value(TElCustomCryptoKeyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_set_Value(TElCustomCryptoKeyHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_get_IV(TElCustomCryptoKeyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_set_IV(TElCustomCryptoKeyHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_get_Mode(TElCustomCryptoKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_set_Mode(TElCustomCryptoKeyHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_get_CryptoProvider(TElCustomCryptoKeyHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_get_KeyStorage(TElCustomCryptoKeyHandle _Handle, TElCustomCryptoKeyStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoKey_Create(TElCustomCryptoProviderHandle CryptoProvider, TElCustomCryptoKeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOCONTEXT
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoContext_GetContextProp(TElCustomCryptoContextHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pDefault[], int32_t szDefault, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoContext_SetContextProp(TElCustomCryptoContextHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoContext_Clone(TElCustomCryptoContextHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoContext_EstimateOutputSize(TElCustomCryptoContextHandle _Handle, int64_t InSize, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoContext_get_Algorithm(TElCustomCryptoContextHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoContext_get_CryptoProvider(TElCustomCryptoContextHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoContext_get_KeySize(TElCustomCryptoContextHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoContext_set_KeySize(TElCustomCryptoContextHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoContext_get_BlockSize(TElCustomCryptoContextHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoContext_set_BlockSize(TElCustomCryptoContextHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoContext_get_DigestSize(TElCustomCryptoContextHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoContext_set_DigestSize(TElCustomCryptoContextHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoContext_get_Mode(TElCustomCryptoContextHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoContext_set_Mode(TElCustomCryptoContextHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoContext_get_Padding(TElCustomCryptoContextHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoContext_set_Padding(TElCustomCryptoContextHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoContext_get_AlgorithmClass(TElCustomCryptoContextHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoContext_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOCONTEXT */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderOptions_Assign(TElCustomCryptoProviderOptionsHandle _Handle, TElCustomCryptoProviderOptionsHandle Options);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderOptions_get_MaxPublicKeySize(TElCustomCryptoProviderOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderOptions_set_MaxPublicKeySize(TElCustomCryptoProviderOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderOptions_get_StoreKeys(TElCustomCryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderOptions_set_StoreKeys(TElCustomCryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCryptoProviderOptions_Create(TElCustomCryptoProviderOptionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS */

#ifdef SB_USE_CLASS_TELBLACKBOXCRYPTOPROVIDER
SB_IMPORT uint32_t SB_APIENTRY TElBlackboxCryptoProvider_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBlackboxCryptoProvider_Create(TComponentHandle AOwner, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBlackboxCryptoProvider_Create_1(TElCustomCryptoProviderOptionsHandle Options, TComponentHandle AOwner, TElCustomCryptoProviderHandle * OutResult);
#endif /* SB_USE_CLASS_TELBLACKBOXCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELEXTERNALCRYPTOPROVIDER
SB_IMPORT uint32_t SB_APIENTRY TElExternalCryptoProvider_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExternalCryptoProvider_Create(TComponentHandle AOwner, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExternalCryptoProvider_Create_1(TElCustomCryptoProviderOptionsHandle Options, TComponentHandle AOwner, TElCustomCryptoProviderHandle * OutResult);
#endif /* SB_USE_CLASS_TELEXTERNALCRYPTOPROVIDER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
typedef TElRelativeDistinguishedName TElCPParameters;
class TElCustomCryptoProvider;
class TElCustomCryptoProviderManager;
class TElCustomCryptoKeyStorage;
class TElCustomCryptoKey;
class TElCustomCryptoContext;
class TElCustomCryptoProviderOptions;
class TElBlackboxCryptoProvider;
class TElExternalCryptoProvider;

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
class TElCustomCryptoProvider: public TComponent
{
	private:
		SB_DISABLE_COPY(TElCustomCryptoProvider)
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS
		TElCustomCryptoProviderOptions* _Inst_Options;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		void initInstances();

	public:
		virtual void Init();

		virtual void Deinit();

		static void SetAsDefault();

		virtual void SetAsDefault_Inst();

		virtual TElCustomCryptoProviderHandle GetDefaultInstance();

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

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual void Encrypt(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void Encrypt(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual void Encrypt(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void Encrypt(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual void Decrypt(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void Decrypt(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual void Decrypt(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void Decrypt(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual void Sign(int32_t Algorithm, TElCustomCryptoKey &Key, bool Detached, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void Sign(int32_t Algorithm, TElCustomCryptoKey *Key, bool Detached, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual void Sign(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, bool Detached, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void Sign(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, bool Detached, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual int32_t Verify(int32_t Algorithm, TElCustomCryptoKey &Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual int32_t Verify(int32_t Algorithm, TElCustomCryptoKey *Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual int32_t Verify(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual int32_t Verify(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual int32_t VerifyDetached(int32_t Algorithm, TElCustomCryptoKey &Key, void * InBuffer, int32_t InSize, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual int32_t VerifyDetached(int32_t Algorithm, TElCustomCryptoKey *Key, void * InBuffer, int32_t InSize, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual int32_t VerifyDetached(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, void * InBuffer, int32_t InSize, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual int32_t VerifyDetached(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, void * InBuffer, int32_t InSize, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoContextHandle HashInit(int32_t Algorithm, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual TElCustomCryptoContextHandle HashInit(int32_t Algorithm, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoContextHandle HashInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual TElCustomCryptoContextHandle HashInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual void HashFinal(TElCustomCryptoContext &Context, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, std::vector<uint8_t> &OutResult);

		virtual void HashFinal(TElCustomCryptoContext *Context, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual void HashUpdate(TElCustomCryptoContext &Context, void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void HashUpdate(TElCustomCryptoContext *Context, void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual void Hash(int32_t Algorithm, TElCustomCryptoKey &Key, void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, std::vector<uint8_t> &OutResult);

		virtual void Hash(int32_t Algorithm, TElCustomCryptoKey *Key, void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual void Hash(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, std::vector<uint8_t> &OutResult);

		virtual void Hash(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOCONTEXT
		virtual void ReleaseCryptoContext(TElCustomCryptoContext &Context);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOCONTEXT */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void RandomInit(void * BaseData, int32_t BaseDataSize, TElRelativeDistinguishedName &Params);

		virtual void RandomInit(void * BaseData, int32_t BaseDataSize, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void RandomSeed(void * Data, int32_t DataSize);

		virtual void RandomGenerate(void * Buffer, int32_t Size);

		virtual int32_t RandomGenerate(int32_t MaxValue);

		virtual bool OwnsObject(TObject &Obj);

		virtual bool OwnsObject(TObject *Obj);

		static TClassHandle ClassType();

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS
		virtual TElCustomCryptoProviderOptions* get_Options();

		SB_DECLARE_PROPERTY_GET(TElCustomCryptoProviderOptions*, get_Options, TElCustomCryptoProvider, Options);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS */

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElCustomCryptoProvider, Enabled);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElCustomCryptoProvider, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual void get_OnCreateObject(TSBCryptoProviderObjectEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCreateObject(TSBCryptoProviderObjectEvent pMethodValue, void * pDataValue);

		virtual void get_OnDestroyObject(TSBCryptoProviderObjectEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDestroyObject(TSBCryptoProviderObjectEvent pMethodValue, void * pDataValue);

		TElCustomCryptoProvider(TElCustomCryptoProviderHandle handle, TElOwnHandle ownHandle);

		explicit TElCustomCryptoProvider(TComponent &AOwner);

		explicit TElCustomCryptoProvider(TComponent *AOwner);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS
		TElCustomCryptoProvider(TElCustomCryptoProviderOptions &Options, TComponent &AOwner);

		TElCustomCryptoProvider(TElCustomCryptoProviderOptions *Options, TComponent *AOwner);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS */

		virtual ~TElCustomCryptoProvider();

};
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
class TElCustomCryptoProviderManager: public TComponent
{
	private:
		SB_DISABLE_COPY(TElCustomCryptoProviderManager)
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCustomCryptoProvider* _Inst_CryptoProviders;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCustomCryptoProvider* _Inst_DefaultCryptoProvider;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		void initInstances();

	public:
		virtual void Init();

		virtual void Deinit();

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		int32_t RegisterCryptoProvider(TElCustomCryptoProvider &Prov);

		int32_t RegisterCryptoProvider(TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		void UnregisterCryptoProvider(TElCustomCryptoProvider &Prov);

		void UnregisterCryptoProvider(TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		void UnregisterCryptoProvider(int32_t Index);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		void SetDefaultCryptoProvider(TElCustomCryptoProvider &Prov);

		void SetDefaultCryptoProvider(TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		void SetDefaultCryptoProvider(int32_t Index);

		void SetDefaultCryptoProviderType(TElCustomCryptoProviderClassHandle Value);

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME
		TElCustomCryptoProviderHandle GetSuitableProvider(int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params);

		TElCustomCryptoProviderHandle GetSuitableProvider(int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME
		TElCustomCryptoProviderHandle GetSuitableProvider(int32_t Operation, const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params);

		TElCustomCryptoProviderHandle GetSuitableProvider(int32_t Operation, const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCustomCryptoProviderHandle GetSuitableProvider(int32_t Algorithm, int32_t Mode);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCustomCryptoProviderHandle GetSuitableProvider(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		bool IsOperationSupported(int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params);

		bool IsOperationSupported(int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		bool IsOperationSupported(int32_t Operation, const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params);

		bool IsOperationSupported(int32_t Operation, const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

		bool IsAlgorithmSupported(int32_t Algorithm, int32_t Mode);

		bool IsAlgorithmSupported(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		virtual bool IsProviderAllowed(TElCustomCryptoProvider &Prov);

		virtual bool IsProviderAllowed(TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		void GetAlgorithmProperty(int32_t Algorithm, int32_t Mode, const std::vector<uint8_t> &PropID, std::vector<uint8_t> &OutResult);

		void GetAlgorithmProperty(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, const std::vector<uint8_t> &PropID, std::vector<uint8_t> &OutResult);

		int32_t GetAlgorithmClass(int32_t Algorithm);

		int32_t GetAlgorithmClass(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		virtual TElCustomCryptoProvider* get_CryptoProviders(int32_t Index);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElCustomCryptoProviderManager, Count);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		virtual TElCustomCryptoProvider* get_DefaultCryptoProvider();

		SB_DECLARE_PROPERTY_GET(TElCustomCryptoProvider*, get_DefaultCryptoProvider, TElCustomCryptoProviderManager, DefaultCryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		TElCustomCryptoProviderManager(TElCustomCryptoProviderManagerHandle handle, TElOwnHandle ownHandle);

		explicit TElCustomCryptoProviderManager(TComponent &AOwner);

		explicit TElCustomCryptoProviderManager(TComponent *AOwner);

		virtual ~TElCustomCryptoProviderManager();

};
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE
class TElCustomCryptoKeyStorage: public TObject
{
	private:
		SB_DISABLE_COPY(TElCustomCryptoKeyStorage)
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
		TElCustomCryptoKey* _Inst_Keys;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCustomCryptoProvider* _Inst_CryptoProvider;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		void initInstances();

	public:
#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual int32_t AddKey(TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params);

		virtual int32_t AddKey(TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void RemoveKey(int32_t Index, TElRelativeDistinguishedName &Params);

		virtual void RemoveKey(int32_t Index, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
		virtual void RemoveKey(TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params);

		virtual void RemoveKey(TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

		virtual void Clear();

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoKeyStorageHandle Clone(TElRelativeDistinguishedName &Params);

		virtual TElCustomCryptoKeyStorageHandle Clone(TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void Lock();

		virtual void Unlock();

		virtual void GetStorageProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult);

		virtual void SetStorageProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
		virtual TElCustomCryptoKey* get_Keys(int32_t Index);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElCustomCryptoKeyStorage, Count);

		virtual bool get_IsPersistent();

		SB_DECLARE_PROPERTY_GET(bool, get_IsPersistent, TElCustomCryptoKeyStorage, IsPersistent);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		virtual TElCustomCryptoProvider* get_CryptoProvider();

		SB_DECLARE_PROPERTY_GET(TElCustomCryptoProvider*, get_CryptoProvider, TElCustomCryptoKeyStorage, CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		TElCustomCryptoKeyStorage(TElCustomCryptoKeyStorageHandle handle, TElOwnHandle ownHandle);

		TElCustomCryptoKeyStorage();

		virtual ~TElCustomCryptoKeyStorage();

};
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
class TElCustomCryptoKey: public TObject
{
	private:
		SB_DISABLE_COPY(TElCustomCryptoKey)
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCustomCryptoProvider* _Inst_CryptoProvider;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE
		TElCustomCryptoKeyStorage* _Inst_KeyStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE */

		void initInstances();

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

		virtual TObjectHandle GetKeyObjectProp(const std::vector<uint8_t> &PropID, const TObject &Default);

		virtual TObjectHandle GetKeyObjectProp(const std::vector<uint8_t> &PropID, const TObject *Default);

		virtual void SetKeyObjectProp(const std::vector<uint8_t> &PropID, const TObject &Value);

		virtual void SetKeyObjectProp(const std::vector<uint8_t> &PropID, const TObject *Value);

		virtual void ChangeAlgorithm(int32_t Algorithm);

		virtual void PrepareForEncryption(bool MultiUse);

		virtual void PrepareForSigning(bool MultiUse);

		virtual void CancelPreparation();

		virtual bool AsyncOperationFinished();

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual bool Equals(TElCustomCryptoKey &Key, bool PublicOnly, TElRelativeDistinguishedName &Params);

		virtual bool Equals(TElCustomCryptoKey *Key, bool PublicOnly, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void Persistentiate();

		virtual bool get_IsPublic();

		SB_DECLARE_PROPERTY_GET(bool, get_IsPublic, TElCustomCryptoKey, IsPublic);

		virtual bool get_IsSecret();

		SB_DECLARE_PROPERTY_GET(bool, get_IsSecret, TElCustomCryptoKey, IsSecret);

		virtual bool get_IsExportable();

		SB_DECLARE_PROPERTY_GET(bool, get_IsExportable, TElCustomCryptoKey, IsExportable);

		virtual bool get_IsPersistent();

		SB_DECLARE_PROPERTY_GET(bool, get_IsPersistent, TElCustomCryptoKey, IsPersistent);

		virtual bool get_IsValid();

		SB_DECLARE_PROPERTY_GET(bool, get_IsValid, TElCustomCryptoKey, IsValid);

		virtual int32_t get_Bits();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Bits, TElCustomCryptoKey, Bits);

		virtual int32_t get_Algorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Algorithm, TElCustomCryptoKey, Algorithm);

		virtual void get_Value(std::vector<uint8_t> &OutResult);

		virtual void set_Value(const std::vector<uint8_t> &Value);

		virtual void get_IV(std::vector<uint8_t> &OutResult);

		virtual void set_IV(const std::vector<uint8_t> &Value);

		virtual int32_t get_Mode();

		virtual void set_Mode(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Mode, set_Mode, TElCustomCryptoKey, Mode);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		virtual TElCustomCryptoProvider* get_CryptoProvider();

		SB_DECLARE_PROPERTY_GET(TElCustomCryptoProvider*, get_CryptoProvider, TElCustomCryptoKey, CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE
		virtual TElCustomCryptoKeyStorage* get_KeyStorage();

		SB_DECLARE_PROPERTY_GET(TElCustomCryptoKeyStorage*, get_KeyStorage, TElCustomCryptoKey, KeyStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE */

		TElCustomCryptoKey(TElCustomCryptoKeyHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElCustomCryptoKey(TElCustomCryptoProvider &CryptoProvider);

		explicit TElCustomCryptoKey(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		virtual ~TElCustomCryptoKey();

};
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOCONTEXT
class TElCustomCryptoContext: public TObject
{
	private:
		SB_DISABLE_COPY(TElCustomCryptoContext)
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCustomCryptoProvider* _Inst_CryptoProvider;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		void initInstances();

	public:
		virtual void GetContextProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult);

		virtual void SetContextProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoContextHandle Clone(TElRelativeDistinguishedName &Params);

		virtual TElCustomCryptoContextHandle Clone(TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual int64_t EstimateOutputSize(int64_t InSize);

		virtual int32_t get_Algorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Algorithm, TElCustomCryptoContext, Algorithm);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		virtual TElCustomCryptoProvider* get_CryptoProvider();

		SB_DECLARE_PROPERTY_GET(TElCustomCryptoProvider*, get_CryptoProvider, TElCustomCryptoContext, CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		virtual int32_t get_KeySize();

		virtual void set_KeySize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_KeySize, set_KeySize, TElCustomCryptoContext, KeySize);

		virtual int32_t get_BlockSize();

		virtual void set_BlockSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_BlockSize, set_BlockSize, TElCustomCryptoContext, BlockSize);

		virtual int32_t get_DigestSize();

		virtual void set_DigestSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DigestSize, set_DigestSize, TElCustomCryptoContext, DigestSize);

		virtual int32_t get_Mode();

		virtual void set_Mode(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Mode, set_Mode, TElCustomCryptoContext, Mode);

		virtual int32_t get_Padding();

		virtual void set_Padding(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Padding, set_Padding, TElCustomCryptoContext, Padding);

		virtual int32_t get_AlgorithmClass();

		SB_DECLARE_PROPERTY_GET(int32_t, get_AlgorithmClass, TElCustomCryptoContext, AlgorithmClass);

		TElCustomCryptoContext(TElCustomCryptoContextHandle handle, TElOwnHandle ownHandle);

		TElCustomCryptoContext();

		virtual ~TElCustomCryptoContext();

};
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOCONTEXT */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS
class TElCustomCryptoProviderOptions: public TObject
{
	private:
		SB_DISABLE_COPY(TElCustomCryptoProviderOptions)
	public:
		virtual void Assign(TElCustomCryptoProviderOptions &Options);

		virtual void Assign(TElCustomCryptoProviderOptions *Options);

		virtual int32_t get_MaxPublicKeySize();

		virtual void set_MaxPublicKeySize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxPublicKeySize, set_MaxPublicKeySize, TElCustomCryptoProviderOptions, MaxPublicKeySize);

		virtual bool get_StoreKeys();

		virtual void set_StoreKeys(bool Value);

		SB_DECLARE_PROPERTY(bool, get_StoreKeys, set_StoreKeys, TElCustomCryptoProviderOptions, StoreKeys);

		TElCustomCryptoProviderOptions(TElCustomCryptoProviderOptionsHandle handle, TElOwnHandle ownHandle);

		TElCustomCryptoProviderOptions();

};
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS */

#ifdef SB_USE_CLASS_TELBLACKBOXCRYPTOPROVIDER
class TElBlackboxCryptoProvider: public TElCustomCryptoProvider
{
	private:
		SB_DISABLE_COPY(TElBlackboxCryptoProvider)
	public:
		static TClassHandle ClassType();

		TElBlackboxCryptoProvider(TElBlackboxCryptoProviderHandle handle, TElOwnHandle ownHandle);

		explicit TElBlackboxCryptoProvider(TComponent &AOwner);

		explicit TElBlackboxCryptoProvider(TComponent *AOwner);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS
		TElBlackboxCryptoProvider(TElCustomCryptoProviderOptions &Options, TComponent &AOwner);

		TElBlackboxCryptoProvider(TElCustomCryptoProviderOptions *Options, TComponent *AOwner);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS */

};
#endif /* SB_USE_CLASS_TELBLACKBOXCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELEXTERNALCRYPTOPROVIDER
class TElExternalCryptoProvider: public TElBlackboxCryptoProvider
{
	private:
		SB_DISABLE_COPY(TElExternalCryptoProvider)
	public:
		static TClassHandle ClassType();

		TElExternalCryptoProvider(TElExternalCryptoProviderHandle handle, TElOwnHandle ownHandle);

		explicit TElExternalCryptoProvider(TComponent &AOwner);

		explicit TElExternalCryptoProvider(TComponent *AOwner);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS
		TElExternalCryptoProvider(TElCustomCryptoProviderOptions &Options, TComponent &AOwner);

		TElExternalCryptoProvider(TElCustomCryptoProviderOptions *Options, TComponent *AOwner);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS */

};
#endif /* SB_USE_CLASS_TELEXTERNALCRYPTOPROVIDER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCRYPTOPROV */
