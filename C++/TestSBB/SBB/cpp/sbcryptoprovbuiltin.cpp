#include "sbcryptoprovbuiltin.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELBUILTINCRYPTOPROVIDEROPTIONS

SB_INLINE void TElBuiltInCryptoProviderOptions::Assign(TElCustomCryptoProviderOptions &Options)
{
	SBCheckError(TElBuiltInCryptoProviderOptions_Assign(_Handle, Options.getHandle()));
}

SB_INLINE void TElBuiltInCryptoProviderOptions::Assign(TElCustomCryptoProviderOptions *Options)
{
	SBCheckError(TElBuiltInCryptoProviderOptions_Assign(_Handle, (Options != NULL) ? Options->getHandle() : SB_NULL_HANDLE));
}

bool TElBuiltInCryptoProviderOptions::get_UsePlatformKeyGeneration()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInCryptoProviderOptions_get_UsePlatformKeyGeneration(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBuiltInCryptoProviderOptions::set_UsePlatformKeyGeneration(bool Value)
{
	SBCheckError(TElBuiltInCryptoProviderOptions_set_UsePlatformKeyGeneration(_Handle, (int8_t)Value));
}

bool TElBuiltInCryptoProviderOptions::get_RollbackToBuiltInKeyGeneration()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInCryptoProviderOptions_get_RollbackToBuiltInKeyGeneration(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBuiltInCryptoProviderOptions::set_RollbackToBuiltInKeyGeneration(bool Value)
{
	SBCheckError(TElBuiltInCryptoProviderOptions_set_RollbackToBuiltInKeyGeneration(_Handle, (int8_t)Value));
}

bool TElBuiltInCryptoProviderOptions::get_UseTimingAttackProtection()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInCryptoProviderOptions_get_UseTimingAttackProtection(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBuiltInCryptoProviderOptions::set_UseTimingAttackProtection(bool Value)
{
	SBCheckError(TElBuiltInCryptoProviderOptions_set_UseTimingAttackProtection(_Handle, (int8_t)Value));
}

bool TElBuiltInCryptoProviderOptions::get_AutoVerifyCreatedSignatures()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInCryptoProviderOptions_get_AutoVerifyCreatedSignatures(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBuiltInCryptoProviderOptions::set_AutoVerifyCreatedSignatures(bool Value)
{
	SBCheckError(TElBuiltInCryptoProviderOptions_set_AutoVerifyCreatedSignatures(_Handle, (int8_t)Value));
}

bool TElBuiltInCryptoProviderOptions::get_AlignEncryptedDataToKeyLength()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInCryptoProviderOptions_get_AlignEncryptedDataToKeyLength(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBuiltInCryptoProviderOptions::set_AlignEncryptedDataToKeyLength(bool Value)
{
	SBCheckError(TElBuiltInCryptoProviderOptions_set_AlignEncryptedDataToKeyLength(_Handle, (int8_t)Value));
}

TElBuiltInCryptoProviderOptions::TElBuiltInCryptoProviderOptions(TElBuiltInCryptoProviderOptionsHandle handle, TElOwnHandle ownHandle) : TElCustomCryptoProviderOptions(handle, ownHandle)
{
}

TElBuiltInCryptoProviderOptions::TElBuiltInCryptoProviderOptions() : TElCustomCryptoProviderOptions(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInCryptoProviderOptions_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELBUILTINCRYPTOPROVIDEROPTIONS */

#ifdef SB_USE_CLASS_TELBUILTINCRYPTOKEY

SB_INLINE void TElBuiltInCryptoKey::Reset()
{
	SBCheckError(TElBuiltInCryptoKey_Reset(_Handle));
}

SB_INLINE void TElBuiltInCryptoKey::ChangeAlgorithm(int32_t Algorithm)
{
	SBCheckError(TElBuiltInCryptoKey_ChangeAlgorithm(_Handle, Algorithm));
}

SB_INLINE void TElBuiltInCryptoKey::PrepareForEncryption(bool MultiUse)
{
	SBCheckError(TElBuiltInCryptoKey_PrepareForEncryption(_Handle, (int8_t)MultiUse));
}

SB_INLINE void TElBuiltInCryptoKey::PrepareForSigning(bool MultiUse)
{
	SBCheckError(TElBuiltInCryptoKey_PrepareForSigning(_Handle, (int8_t)MultiUse));
}

SB_INLINE void TElBuiltInCryptoKey::CancelPreparation()
{
	SBCheckError(TElBuiltInCryptoKey_CancelPreparation(_Handle));
}

bool TElBuiltInCryptoKey::AsyncOperationFinished()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInCryptoKey_AsyncOperationFinished(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
bool TElBuiltInCryptoKey::Equals(TElCustomCryptoKey &Source, bool PublicOnly, TElRelativeDistinguishedName &Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInCryptoKey_Equals(_Handle, Source.getHandle(), (int8_t)PublicOnly, Params.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBuiltInCryptoKey::Equals(TElCustomCryptoKey *Source, bool PublicOnly, TElRelativeDistinguishedName *Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInCryptoKey_Equals(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (int8_t)PublicOnly, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElBuiltInCryptoKey::Persistentiate()
{
	SBCheckError(TElBuiltInCryptoKey_Persistentiate(_Handle));
}

TElBuiltInCryptoKey::TElBuiltInCryptoKey(TElBuiltInCryptoKeyHandle handle, TElOwnHandle ownHandle) : TElCustomCryptoKey(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElBuiltInCryptoKey::TElBuiltInCryptoKey(TElCustomCryptoProvider &CryptoProvider) : TElCustomCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInCryptoKey_Create(CryptoProvider.getHandle(), &_Handle));
}

TElBuiltInCryptoKey::TElBuiltInCryptoKey(TElCustomCryptoProvider *CryptoProvider) : TElCustomCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInCryptoKey_Create((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#endif /* SB_USE_CLASS_TELBUILTINCRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINCRYPTOPROVIDER

SB_INLINE void TElBuiltInCryptoProvider::Init()
{
	SBCheckError(TElBuiltInCryptoProvider_Init(_Handle));
}

SB_INLINE void TElBuiltInCryptoProvider::Deinit()
{
	SBCheckError(TElBuiltInCryptoProvider_Deinit(_Handle));
}

SB_INLINE void TElBuiltInCryptoProvider::SetAsDefault()
{
	SBCheckError(TElBuiltInCryptoProvider_SetAsDefault());
}

SB_INLINE void TElBuiltInCryptoProvider::SetAsDefault_Inst()
{
	SBCheckError(TElBuiltInCryptoProvider_SetAsDefault_1(_Handle));
}

bool TElBuiltInCryptoProvider::IsAlgorithmSupported(int32_t Algorithm, int32_t Mode)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInCryptoProvider_IsAlgorithmSupported(_Handle, Algorithm, Mode, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBuiltInCryptoProvider::IsAlgorithmSupported(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInCryptoProvider_IsAlgorithmSupported_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
bool TElBuiltInCryptoProvider::IsOperationSupported(int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInCryptoProvider_IsOperationSupported(_Handle, Operation, Algorithm, Mode, Key.getHandle(), Params.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBuiltInCryptoProvider::IsOperationSupported(int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInCryptoProvider_IsOperationSupported(_Handle, Operation, Algorithm, Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
bool TElBuiltInCryptoProvider::IsOperationSupported(int32_t Operation, const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInCryptoProvider_IsOperationSupported_1(_Handle, Operation, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, Key.getHandle(), Params.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBuiltInCryptoProvider::IsOperationSupported(int32_t Operation, const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInCryptoProvider_IsOperationSupported_1(_Handle, Operation, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

void TElBuiltInCryptoProvider::GetAlgorithmProperty(int32_t Algorithm, int32_t Mode, const std::vector<uint8_t> &PropID, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBuiltInCryptoProvider_GetAlgorithmProperty(_Handle, Algorithm, Mode, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1528028610, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBuiltInCryptoProvider::GetAlgorithmProperty(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, const std::vector<uint8_t> &PropID, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBuiltInCryptoProvider_GetAlgorithmProperty_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(836240899, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElBuiltInCryptoProvider::GetAlgorithmClass(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(TElBuiltInCryptoProvider_GetAlgorithmClass(_Handle, Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElBuiltInCryptoProvider::GetAlgorithmClass(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams)
{
	int32_t OutResult;
	SBCheckError(TElBuiltInCryptoProvider_GetAlgorithmClass_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoProviderHandle TElBuiltInCryptoProvider::GetDefaultInstance()
{
	TElCustomCryptoProviderHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_GetDefaultInstance(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElBuiltInCryptoProvider::CreateKey(int32_t Algorithm, int32_t Mode, TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_CreateKey(_Handle, Algorithm, Mode, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElBuiltInCryptoProvider::CreateKey(int32_t Algorithm, int32_t Mode, TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_CreateKey(_Handle, Algorithm, Mode, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElBuiltInCryptoProvider::CreateKey(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_CreateKey_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElBuiltInCryptoProvider::CreateKey(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_CreateKey_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
SB_INLINE TElCustomCryptoKeyHandle TElBuiltInCryptoProvider::CloneKey(TElCustomCryptoKey &Key)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_CloneKey(_Handle, Key.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElBuiltInCryptoProvider::CloneKey(TElCustomCryptoKey *Key)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_CloneKey(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
void TElBuiltInCryptoProvider::ReleaseKey(TElCustomCryptoKey &Key)
{
	TElClassHandle hKey = Key.getHandle();
	SBCheckError(TElBuiltInCryptoProvider_ReleaseKey(_Handle, &hKey));
	Key.updateHandle(hKey);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
void TElBuiltInCryptoProvider::DeleteKey(TElCustomCryptoKey &Key)
{
	TElClassHandle hKey = Key.getHandle();
	SBCheckError(TElBuiltInCryptoProvider_DeleteKey(_Handle, &hKey));
	Key.updateHandle(hKey);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElBuiltInCryptoProvider::DecryptKey(void * EncKey, int32_t EncKeySize, const std::vector<uint8_t> &EncKeyAlgOID, const std::vector<uint8_t> &EncKeyAlgParams, TElCustomCryptoKey &Key, const std::vector<uint8_t> &KeyAlgOID, const std::vector<uint8_t> &KeyAlgParams, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_DecryptKey(_Handle, EncKey, EncKeySize, SB_STD_VECTOR_FRONT_ADR(EncKeyAlgOID), (int32_t)EncKeyAlgOID.size(), SB_STD_VECTOR_FRONT_ADR(EncKeyAlgParams), (int32_t)EncKeyAlgParams.size(), Key.getHandle(), SB_STD_VECTOR_FRONT_ADR(KeyAlgOID), (int32_t)KeyAlgOID.size(), SB_STD_VECTOR_FRONT_ADR(KeyAlgParams), (int32_t)KeyAlgParams.size(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElBuiltInCryptoProvider::DecryptKey(void * EncKey, int32_t EncKeySize, const std::vector<uint8_t> &EncKeyAlgOID, const std::vector<uint8_t> &EncKeyAlgParams, TElCustomCryptoKey *Key, const std::vector<uint8_t> &KeyAlgOID, const std::vector<uint8_t> &KeyAlgParams, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_DecryptKey(_Handle, EncKey, EncKeySize, SB_STD_VECTOR_FRONT_ADR(EncKeyAlgOID), (int32_t)EncKeyAlgOID.size(), SB_STD_VECTOR_FRONT_ADR(EncKeyAlgParams), (int32_t)EncKeyAlgParams.size(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(KeyAlgOID), (int32_t)KeyAlgOID.size(), SB_STD_VECTOR_FRONT_ADR(KeyAlgParams), (int32_t)KeyAlgParams.size(), (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElBuiltInCryptoProvider::EncryptInit(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_EncryptInit(_Handle, Algorithm, Mode, Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElBuiltInCryptoProvider::EncryptInit(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_EncryptInit(_Handle, Algorithm, Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElBuiltInCryptoProvider::EncryptInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_EncryptInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElBuiltInCryptoProvider::EncryptInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_EncryptInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElBuiltInCryptoProvider::DecryptInit(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_DecryptInit(_Handle, Algorithm, Mode, Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElBuiltInCryptoProvider::DecryptInit(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_DecryptInit(_Handle, Algorithm, Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElBuiltInCryptoProvider::DecryptInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_DecryptInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElBuiltInCryptoProvider::DecryptInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_DecryptInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElBuiltInCryptoProvider::SignInit(int32_t Algorithm, TElCustomCryptoKey &Key, bool Detached, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_SignInit(_Handle, Algorithm, Key.getHandle(), (int8_t)Detached, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElBuiltInCryptoProvider::SignInit(int32_t Algorithm, TElCustomCryptoKey *Key, bool Detached, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_SignInit(_Handle, Algorithm, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (int8_t)Detached, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElBuiltInCryptoProvider::SignInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, bool Detached, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_SignInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Key.getHandle(), (int8_t)Detached, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElBuiltInCryptoProvider::SignInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, bool Detached, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_SignInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (int8_t)Detached, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElBuiltInCryptoProvider::VerifyInit(int32_t Algorithm, TElCustomCryptoKey &Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_VerifyInit(_Handle, Algorithm, Key.getHandle(), SigBuffer, SigSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElBuiltInCryptoProvider::VerifyInit(int32_t Algorithm, TElCustomCryptoKey *Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_VerifyInit(_Handle, Algorithm, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, SigBuffer, SigSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElBuiltInCryptoProvider::VerifyInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_VerifyInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Key.getHandle(), SigBuffer, SigSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElBuiltInCryptoProvider::VerifyInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_VerifyInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, SigBuffer, SigSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInCryptoProvider::EncryptUpdate(TElCustomCryptoContext &Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInCryptoProvider_EncryptUpdate(_Handle, Context.getHandle(), InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElBuiltInCryptoProvider::EncryptUpdate(TElCustomCryptoContext *Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInCryptoProvider_EncryptUpdate(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInCryptoProvider::DecryptUpdate(TElCustomCryptoContext &Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInCryptoProvider_DecryptUpdate(_Handle, Context.getHandle(), InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElBuiltInCryptoProvider::DecryptUpdate(TElCustomCryptoContext *Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInCryptoProvider_DecryptUpdate(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInCryptoProvider::SignUpdate(TElCustomCryptoContext &Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInCryptoProvider_SignUpdate(_Handle, Context.getHandle(), InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElBuiltInCryptoProvider::SignUpdate(TElCustomCryptoContext *Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInCryptoProvider_SignUpdate(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInCryptoProvider::VerifyUpdate(TElCustomCryptoContext &Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInCryptoProvider_VerifyUpdate(_Handle, Context.getHandle(), InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElBuiltInCryptoProvider::VerifyUpdate(TElCustomCryptoContext *Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInCryptoProvider_VerifyUpdate(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInCryptoProvider::EncryptFinal(TElCustomCryptoContext &Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInCryptoProvider_EncryptFinal(_Handle, Context.getHandle(), Buffer, &Size, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElBuiltInCryptoProvider::EncryptFinal(TElCustomCryptoContext *Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInCryptoProvider_EncryptFinal(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInCryptoProvider::DecryptFinal(TElCustomCryptoContext &Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInCryptoProvider_DecryptFinal(_Handle, Context.getHandle(), Buffer, &Size, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElBuiltInCryptoProvider::DecryptFinal(TElCustomCryptoContext *Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInCryptoProvider_DecryptFinal(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInCryptoProvider::SignFinal(TElCustomCryptoContext &Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInCryptoProvider_SignFinal(_Handle, Context.getHandle(), Buffer, &Size, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElBuiltInCryptoProvider::SignFinal(TElCustomCryptoContext *Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInCryptoProvider_SignFinal(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE int32_t TElBuiltInCryptoProvider::VerifyFinal(TElCustomCryptoContext &Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	int32_t OutResult;
	SBCheckError(TElBuiltInCryptoProvider_VerifyFinal(_Handle, Context.getHandle(), Buffer, &Size, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElBuiltInCryptoProvider::VerifyFinal(TElCustomCryptoContext *Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	int32_t OutResult;
	SBCheckError(TElBuiltInCryptoProvider_VerifyFinal(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElBuiltInCryptoProvider::HashInit(int32_t Algorithm, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_HashInit(_Handle, Algorithm, Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElBuiltInCryptoProvider::HashInit(int32_t Algorithm, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_HashInit(_Handle, Algorithm, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElBuiltInCryptoProvider::HashInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_HashInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElBuiltInCryptoProvider::HashInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_HashInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInCryptoProvider::HashUpdate(TElCustomCryptoContext &Context, void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInCryptoProvider_HashUpdate(_Handle, Context.getHandle(), Buffer, Size, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElBuiltInCryptoProvider::HashUpdate(TElCustomCryptoContext *Context, void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInCryptoProvider_HashUpdate(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
void TElBuiltInCryptoProvider::HashFinal(TElCustomCryptoContext &Context, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBuiltInCryptoProvider_HashFinal(_Handle, Context.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1385673189, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBuiltInCryptoProvider::HashFinal(TElCustomCryptoContext *Context, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBuiltInCryptoProvider_HashFinal(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1385673189, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOCONTEXT
void TElBuiltInCryptoProvider::ReleaseCryptoContext(TElCustomCryptoContext &Context)
{
	TElClassHandle hContext = Context.getHandle();
	SBCheckError(TElBuiltInCryptoProvider_ReleaseCryptoContext(_Handle, &hContext));
	Context.updateHandle(hContext);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOCONTEXT */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEYSTORAGE_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyStorageHandle TElBuiltInCryptoProvider::CreateKeyStorage(bool Persistent, TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyStorageHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_CreateKeyStorage(_Handle, (int8_t)Persistent, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyStorageHandle TElBuiltInCryptoProvider::CreateKeyStorage(bool Persistent, TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyStorageHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_CreateKeyStorage(_Handle, (int8_t)Persistent, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEYSTORAGE_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE
void TElBuiltInCryptoProvider::ReleaseKeyStorage(TElCustomCryptoKeyStorage &KeyStorage)
{
	TElClassHandle hKeyStorage = KeyStorage.getHandle();
	SBCheckError(TElBuiltInCryptoProvider_ReleaseKeyStorage(_Handle, &hKeyStorage));
	KeyStorage.updateHandle(hKeyStorage);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE
void TElBuiltInCryptoProvider::DeleteKeyStorage(TElCustomCryptoKeyStorage &KeyStorage)
{
	TElClassHandle hKeyStorage = KeyStorage.getHandle();
	SBCheckError(TElBuiltInCryptoProvider_DeleteKeyStorage(_Handle, &hKeyStorage));
	KeyStorage.updateHandle(hKeyStorage);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInCryptoProvider::RandomInit(void * BaseData, int32_t BaseDataSize, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInCryptoProvider_RandomInit(_Handle, BaseData, BaseDataSize, Params.getHandle()));
}

SB_INLINE void TElBuiltInCryptoProvider::RandomInit(void * BaseData, int32_t BaseDataSize, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInCryptoProvider_RandomInit(_Handle, BaseData, BaseDataSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElBuiltInCryptoProvider::RandomSeed(void * Data, int32_t DataSize)
{
	SBCheckError(TElBuiltInCryptoProvider_RandomSeed(_Handle, Data, DataSize));
}

SB_INLINE void TElBuiltInCryptoProvider::RandomGenerate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInCryptoProvider_RandomGenerate(_Handle, Buffer, Size));
}

SB_INLINE int32_t TElBuiltInCryptoProvider::RandomGenerate(int32_t MaxValue)
{
	int32_t OutResult;
	SBCheckError(TElBuiltInCryptoProvider_RandomGenerate_1(_Handle, MaxValue, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TElBuiltInCryptoProvider::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBuiltInCryptoProvider_ClassType(&OutResult));
	return OutResult;
}

TElBuiltInCryptoProvider::TElBuiltInCryptoProvider(TElBuiltInCryptoProviderHandle handle, TElOwnHandle ownHandle) : TElBlackboxCryptoProvider(handle, ownHandle)
{
}

TElBuiltInCryptoProvider::TElBuiltInCryptoProvider(TComponent &AOwner) : TElBlackboxCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInCryptoProvider_Create(AOwner.getHandle(), &_Handle));
}

TElBuiltInCryptoProvider::TElBuiltInCryptoProvider(TComponent *AOwner) : TElBlackboxCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInCryptoProvider_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS
TElBuiltInCryptoProvider::TElBuiltInCryptoProvider(TElCustomCryptoProviderOptions &Options, TComponent &AOwner) : TElBlackboxCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInCryptoProvider_Create_1(Options.getHandle(), AOwner.getHandle(), &_Handle));
}

TElBuiltInCryptoProvider::TElBuiltInCryptoProvider(TElCustomCryptoProviderOptions *Options, TComponent *AOwner) : TElBlackboxCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInCryptoProvider_Create_1((Options != NULL) ? Options->getHandle() : SB_NULL_HANDLE, (AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS */

#endif /* SB_USE_CLASS_TELBUILTINCRYPTOPROVIDER */

#ifdef SB_USE_GLOBAL_PROCS_CRYPTOPROVBUILTIN

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
SB_INLINE TElCustomCryptoProviderHandle BuiltInCryptoProvider()
{
	TElCustomCryptoProviderHandle OutResult;
	SBCheckError(SBCryptoProvBuiltIn_BuiltInCryptoProvider(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#endif /* SB_USE_GLOBAL_PROCS_CRYPTOPROVBUILTIN */

};	/* namespace SecureBlackbox */

