#ifndef __INC_SBCRYPTOPROVBUILTIN
#define __INC_SBCRYPTOPROVBUILTIN

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbcryptoprov.h"
#include "sbcryptoprovrs.h"
#include "sbconstants.h"
#include "sbrandom.h"
#include "sbsharedresource.h"
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
typedef TElClassHandle TElBuiltInCryptoProviderOptionsHandle;

typedef TElClassHandle TElBuiltInCryptoKeyHandle;

typedef TElClassHandle TElBuiltInCryptoProviderHandle;

#ifdef SB_USE_CLASS_TELBUILTINCRYPTOPROVIDEROPTIONS
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProviderOptions_Assign(TElBuiltInCryptoProviderOptionsHandle _Handle, TElCustomCryptoProviderOptionsHandle Options);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProviderOptions_get_UsePlatformKeyGeneration(TElBuiltInCryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProviderOptions_set_UsePlatformKeyGeneration(TElBuiltInCryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProviderOptions_get_RollbackToBuiltInKeyGeneration(TElBuiltInCryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProviderOptions_set_RollbackToBuiltInKeyGeneration(TElBuiltInCryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProviderOptions_get_UseTimingAttackProtection(TElBuiltInCryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProviderOptions_set_UseTimingAttackProtection(TElBuiltInCryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProviderOptions_get_AutoVerifyCreatedSignatures(TElBuiltInCryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProviderOptions_set_AutoVerifyCreatedSignatures(TElBuiltInCryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProviderOptions_get_AlignEncryptedDataToKeyLength(TElBuiltInCryptoProviderOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProviderOptions_set_AlignEncryptedDataToKeyLength(TElBuiltInCryptoProviderOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProviderOptions_Create(TElCustomCryptoProviderOptionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINCRYPTOPROVIDEROPTIONS */

#ifdef SB_USE_CLASS_TELBUILTINCRYPTOKEY
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoKey_Reset(TElBuiltInCryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoKey_ChangeAlgorithm(TElBuiltInCryptoKeyHandle _Handle, int32_t Algorithm);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoKey_PrepareForEncryption(TElBuiltInCryptoKeyHandle _Handle, int8_t MultiUse);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoKey_PrepareForSigning(TElBuiltInCryptoKeyHandle _Handle, int8_t MultiUse);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoKey_CancelPreparation(TElBuiltInCryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoKey_AsyncOperationFinished(TElBuiltInCryptoKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoKey_Equals(TElBuiltInCryptoKeyHandle _Handle, TElCustomCryptoKeyHandle Source, int8_t PublicOnly, TElRelativeDistinguishedNameHandle Params, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoKey_Persistentiate(TElBuiltInCryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoKey_Create(TElCustomCryptoProviderHandle CryptoProvider, TElCustomCryptoKeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINCRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINCRYPTOPROVIDER
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_Init(TElBuiltInCryptoProviderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_Deinit(TElBuiltInCryptoProviderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_SetAsDefault();
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_SetAsDefault_1(TElBuiltInCryptoProviderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_IsAlgorithmSupported(TElBuiltInCryptoProviderHandle _Handle, int32_t Algorithm, int32_t Mode, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_IsAlgorithmSupported_1(TElBuiltInCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_IsOperationSupported(TElBuiltInCryptoProviderHandle _Handle, int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_IsOperationSupported_1(TElBuiltInCryptoProviderHandle _Handle, int32_t Operation, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_GetAlgorithmProperty(TElBuiltInCryptoProviderHandle _Handle, int32_t Algorithm, int32_t Mode, const uint8_t pPropID[], int32_t szPropID, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_GetAlgorithmProperty_1(TElBuiltInCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, const uint8_t pPropID[], int32_t szPropID, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_GetAlgorithmClass(TElBuiltInCryptoProviderHandle _Handle, int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_GetAlgorithmClass_1(TElBuiltInCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_GetDefaultInstance(TElBuiltInCryptoProviderHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_CreateKey(TElBuiltInCryptoProviderHandle _Handle, int32_t Algorithm, int32_t Mode, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_CreateKey_1(TElBuiltInCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_CloneKey(TElBuiltInCryptoProviderHandle _Handle, TElCustomCryptoKeyHandle Key, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_ReleaseKey(TElBuiltInCryptoProviderHandle _Handle, TElCustomCryptoKeyHandle * Key);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_DeleteKey(TElBuiltInCryptoProviderHandle _Handle, TElCustomCryptoKeyHandle * Key);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_DecryptKey(TElBuiltInCryptoProviderHandle _Handle, void * EncKey, int32_t EncKeySize, const uint8_t pEncKeyAlgOID[], int32_t szEncKeyAlgOID, const uint8_t pEncKeyAlgParams[], int32_t szEncKeyAlgParams, TElCustomCryptoKeyHandle Key, const uint8_t pKeyAlgOID[], int32_t szKeyAlgOID, const uint8_t pKeyAlgParams[], int32_t szKeyAlgParams, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_EncryptInit(TElBuiltInCryptoProviderHandle _Handle, int32_t Algorithm, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_EncryptInit_1(TElBuiltInCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_DecryptInit(TElBuiltInCryptoProviderHandle _Handle, int32_t Algorithm, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_DecryptInit_1(TElBuiltInCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t Mode, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_SignInit(TElBuiltInCryptoProviderHandle _Handle, int32_t Algorithm, TElCustomCryptoKeyHandle Key, int8_t Detached, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_SignInit_1(TElBuiltInCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, TElCustomCryptoKeyHandle Key, int8_t Detached, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_VerifyInit(TElBuiltInCryptoProviderHandle _Handle, int32_t Algorithm, TElCustomCryptoKeyHandle Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_VerifyInit_1(TElBuiltInCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, TElCustomCryptoKeyHandle Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_EncryptUpdate(TElBuiltInCryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_DecryptUpdate(TElBuiltInCryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_SignUpdate(TElBuiltInCryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_VerifyUpdate(TElBuiltInCryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_EncryptFinal(TElBuiltInCryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_DecryptFinal(TElBuiltInCryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_SignFinal(TElBuiltInCryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_VerifyFinal(TElBuiltInCryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_HashInit(TElBuiltInCryptoProviderHandle _Handle, int32_t Algorithm, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_HashInit_1(TElBuiltInCryptoProviderHandle _Handle, const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, TElCustomCryptoKeyHandle Key, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, TElCustomCryptoContextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_HashUpdate(TElBuiltInCryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_HashFinal(TElBuiltInCryptoProviderHandle _Handle, TElCustomCryptoContextHandle Context, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_ReleaseCryptoContext(TElBuiltInCryptoProviderHandle _Handle, TElCustomCryptoContextHandle * Context);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_CreateKeyStorage(TElBuiltInCryptoProviderHandle _Handle, int8_t Persistent, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_ReleaseKeyStorage(TElBuiltInCryptoProviderHandle _Handle, TElCustomCryptoKeyStorageHandle * KeyStorage);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_DeleteKeyStorage(TElBuiltInCryptoProviderHandle _Handle, TElCustomCryptoKeyStorageHandle * KeyStorage);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_RandomInit(TElBuiltInCryptoProviderHandle _Handle, void * BaseData, int32_t BaseDataSize, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_RandomSeed(TElBuiltInCryptoProviderHandle _Handle, void * Data, int32_t DataSize);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_RandomGenerate(TElBuiltInCryptoProviderHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_RandomGenerate_1(TElBuiltInCryptoProviderHandle _Handle, int32_t MaxValue, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_Create(TComponentHandle AOwner, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProvider_Create_1(TElCustomCryptoProviderOptionsHandle Options, TComponentHandle AOwner, TElCustomCryptoProviderHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINCRYPTOPROVIDER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElBuiltInCryptoProviderOptions;
class TElBuiltInCryptoKey;
class TElBuiltInCryptoProvider;

#ifdef SB_USE_CLASS_TELBUILTINCRYPTOPROVIDEROPTIONS
class TElBuiltInCryptoProviderOptions: public TElCustomCryptoProviderOptions
{
	private:
		SB_DISABLE_COPY(TElBuiltInCryptoProviderOptions)
	public:
		virtual void Assign(TElCustomCryptoProviderOptions &Options);

		virtual void Assign(TElCustomCryptoProviderOptions *Options);

		virtual bool get_UsePlatformKeyGeneration();

		virtual void set_UsePlatformKeyGeneration(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UsePlatformKeyGeneration, set_UsePlatformKeyGeneration, TElBuiltInCryptoProviderOptions, UsePlatformKeyGeneration);

		virtual bool get_RollbackToBuiltInKeyGeneration();

		virtual void set_RollbackToBuiltInKeyGeneration(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RollbackToBuiltInKeyGeneration, set_RollbackToBuiltInKeyGeneration, TElBuiltInCryptoProviderOptions, RollbackToBuiltInKeyGeneration);

		virtual bool get_UseTimingAttackProtection();

		virtual void set_UseTimingAttackProtection(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseTimingAttackProtection, set_UseTimingAttackProtection, TElBuiltInCryptoProviderOptions, UseTimingAttackProtection);

		virtual bool get_AutoVerifyCreatedSignatures();

		virtual void set_AutoVerifyCreatedSignatures(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoVerifyCreatedSignatures, set_AutoVerifyCreatedSignatures, TElBuiltInCryptoProviderOptions, AutoVerifyCreatedSignatures);

		virtual bool get_AlignEncryptedDataToKeyLength();

		virtual void set_AlignEncryptedDataToKeyLength(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AlignEncryptedDataToKeyLength, set_AlignEncryptedDataToKeyLength, TElBuiltInCryptoProviderOptions, AlignEncryptedDataToKeyLength);

		TElBuiltInCryptoProviderOptions(TElBuiltInCryptoProviderOptionsHandle handle, TElOwnHandle ownHandle);

		TElBuiltInCryptoProviderOptions();

};
#endif /* SB_USE_CLASS_TELBUILTINCRYPTOPROVIDEROPTIONS */

#ifdef SB_USE_CLASS_TELBUILTINCRYPTOKEY
class TElBuiltInCryptoKey: public TElCustomCryptoKey
{
	private:
		SB_DISABLE_COPY(TElBuiltInCryptoKey)
	public:
		virtual void Reset();

		virtual void ChangeAlgorithm(int32_t Algorithm);

		virtual void PrepareForEncryption(bool MultiUse);

		virtual void PrepareForSigning(bool MultiUse);

		virtual void CancelPreparation();

		virtual bool AsyncOperationFinished();

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual bool Equals(TElCustomCryptoKey &Source, bool PublicOnly, TElRelativeDistinguishedName &Params);

		virtual bool Equals(TElCustomCryptoKey *Source, bool PublicOnly, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void Persistentiate();

		TElBuiltInCryptoKey(TElBuiltInCryptoKeyHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElBuiltInCryptoKey(TElCustomCryptoProvider &CryptoProvider);

		explicit TElBuiltInCryptoKey(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

};
#endif /* SB_USE_CLASS_TELBUILTINCRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINCRYPTOPROVIDER
class TElBuiltInCryptoProvider: public TElBlackboxCryptoProvider
{
	private:
		SB_DISABLE_COPY(TElBuiltInCryptoProvider)
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

		static TClassHandle ClassType();

		TElBuiltInCryptoProvider(TElBuiltInCryptoProviderHandle handle, TElOwnHandle ownHandle);

		explicit TElBuiltInCryptoProvider(TComponent &AOwner);

		explicit TElBuiltInCryptoProvider(TComponent *AOwner);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS
		TElBuiltInCryptoProvider(TElCustomCryptoProviderOptions &Options, TComponent &AOwner);

		TElBuiltInCryptoProvider(TElCustomCryptoProviderOptions *Options, TComponent *AOwner);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS */

};
#endif /* SB_USE_CLASS_TELBUILTINCRYPTOPROVIDER */

#ifdef SB_USE_GLOBAL_PROCS_CRYPTOPROVBUILTIN

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProviderHandle BuiltInCryptoProvider();
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#endif /* SB_USE_GLOBAL_PROCS_CRYPTOPROVBUILTIN */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_CRYPTOPROVBUILTIN
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvBuiltIn_BuiltInCryptoProvider(TElCustomCryptoProviderHandle * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_CRYPTOPROVBUILTIN */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCRYPTOPROVBUILTIN */

