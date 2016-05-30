#include "sbcryptoprov.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER

SB_INLINE void TElCustomCryptoProvider::Init()
{
	SBCheckError(TElCustomCryptoProvider_Init(_Handle));
}

SB_INLINE void TElCustomCryptoProvider::Deinit()
{
	SBCheckError(TElCustomCryptoProvider_Deinit(_Handle));
}

SB_INLINE void TElCustomCryptoProvider::SetAsDefault()
{
	SBCheckError(TElCustomCryptoProvider_SetAsDefault());
}

SB_INLINE void TElCustomCryptoProvider::SetAsDefault_Inst()
{
	SBCheckError(TElCustomCryptoProvider_SetAsDefault_1(_Handle));
}

SB_INLINE TElCustomCryptoProviderHandle TElCustomCryptoProvider::GetDefaultInstance()
{
	TElCustomCryptoProviderHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_GetDefaultInstance(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoProviderHandle TElCustomCryptoProvider::Clone()
{
	TElCustomCryptoProviderHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_Clone(_Handle, &OutResult));
	return OutResult;
}

bool TElCustomCryptoProvider::IsAlgorithmSupported(int32_t Algorithm, int32_t Mode)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoProvider_IsAlgorithmSupported(_Handle, Algorithm, Mode, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCryptoProvider::IsAlgorithmSupported(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoProvider_IsAlgorithmSupported_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
bool TElCustomCryptoProvider::IsOperationSupported(int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoProvider_IsOperationSupported(_Handle, Operation, Algorithm, Mode, Key.getHandle(), Params.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCryptoProvider::IsOperationSupported(int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoProvider_IsOperationSupported(_Handle, Operation, Algorithm, Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
bool TElCustomCryptoProvider::IsOperationSupported(int32_t Operation, const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoProvider_IsOperationSupported_1(_Handle, Operation, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, Key.getHandle(), Params.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCryptoProvider::IsOperationSupported(int32_t Operation, const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoProvider_IsOperationSupported_1(_Handle, Operation, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

void TElCustomCryptoProvider::GetAlgorithmProperty(int32_t Algorithm, int32_t Mode, const std::vector<uint8_t> &PropID, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomCryptoProvider_GetAlgorithmProperty(_Handle, Algorithm, Mode, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1810233091, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElCustomCryptoProvider::GetAlgorithmProperty(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, const std::vector<uint8_t> &PropID, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomCryptoProvider_GetAlgorithmProperty_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1581093443, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElCustomCryptoProvider::GetAlgorithmClass(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoProvider_GetAlgorithmClass(_Handle, Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCryptoProvider::GetAlgorithmClass(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams)
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoProvider_GetAlgorithmClass_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), &OutResult));
	return OutResult;
}

void TElCustomCryptoProvider::GetProviderProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomCryptoProvider_GetProviderProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Default), (int32_t)Default.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-129298666, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_IOS
SB_INLINE TObjectHandle TElCustomCryptoProvider::GetProviderProp(const std::vector<uint8_t> &PropID, TObject &Default)
{
	TObjectHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_GetProviderProp_1(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), Default.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TObjectHandle TElCustomCryptoProvider::GetProviderProp(const std::vector<uint8_t> &PropID, TObject *Default)
{
	TObjectHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_GetProviderProp_1(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), (Default != NULL) ? Default->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif

SB_INLINE void TElCustomCryptoProvider::SetProviderProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCustomCryptoProvider_SetProviderProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
#ifdef SB_IOS
}

SB_INLINE void TElCustomCryptoProvider::SetProviderProp(const std::vector<uint8_t> &PropID, TObject &Value)
{
	SBCheckError(TElCustomCryptoProvider_SetProviderProp_1(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), Value.getHandle()));
}

SB_INLINE void TElCustomCryptoProvider::SetProviderProp(const std::vector<uint8_t> &PropID, TObject *Value)
{
	SBCheckError(TElCustomCryptoProvider_SetProviderProp_1(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
#endif
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElCustomCryptoProvider::CreateKey(int32_t Algorithm, int32_t Mode, TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_CreateKey(_Handle, Algorithm, Mode, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElCustomCryptoProvider::CreateKey(int32_t Algorithm, int32_t Mode, TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_CreateKey(_Handle, Algorithm, Mode, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElCustomCryptoProvider::CreateKey(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_CreateKey_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElCustomCryptoProvider::CreateKey(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_CreateKey_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
SB_INLINE TElCustomCryptoKeyHandle TElCustomCryptoProvider::CloneKey(TElCustomCryptoKey &Key)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_CloneKey(_Handle, Key.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElCustomCryptoProvider::CloneKey(TElCustomCryptoKey *Key)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_CloneKey(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
void TElCustomCryptoProvider::ReleaseKey(TElCustomCryptoKey &Key)
{
	TElClassHandle hKey = Key.getHandle();
	SBCheckError(TElCustomCryptoProvider_ReleaseKey(_Handle, &hKey));
	Key.updateHandle(hKey);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
void TElCustomCryptoProvider::DeleteKey(TElCustomCryptoKey &Key)
{
	TElClassHandle hKey = Key.getHandle();
	SBCheckError(TElCustomCryptoProvider_DeleteKey(_Handle, &hKey));
	Key.updateHandle(hKey);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElCustomCryptoProvider::DecryptKey(void * EncKey, int32_t EncKeySize, const std::vector<uint8_t> &EncKeyAlgOID, const std::vector<uint8_t> &EncKeyAlgParams, TElCustomCryptoKey &Key, const std::vector<uint8_t> &KeyAlgOID, const std::vector<uint8_t> &KeyAlgParams, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_DecryptKey(_Handle, EncKey, EncKeySize, SB_STD_VECTOR_FRONT_ADR(EncKeyAlgOID), (int32_t)EncKeyAlgOID.size(), SB_STD_VECTOR_FRONT_ADR(EncKeyAlgParams), (int32_t)EncKeyAlgParams.size(), Key.getHandle(), SB_STD_VECTOR_FRONT_ADR(KeyAlgOID), (int32_t)KeyAlgOID.size(), SB_STD_VECTOR_FRONT_ADR(KeyAlgParams), (int32_t)KeyAlgParams.size(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElCustomCryptoProvider::DecryptKey(void * EncKey, int32_t EncKeySize, const std::vector<uint8_t> &EncKeyAlgOID, const std::vector<uint8_t> &EncKeyAlgParams, TElCustomCryptoKey *Key, const std::vector<uint8_t> &KeyAlgOID, const std::vector<uint8_t> &KeyAlgParams, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_DecryptKey(_Handle, EncKey, EncKeySize, SB_STD_VECTOR_FRONT_ADR(EncKeyAlgOID), (int32_t)EncKeyAlgOID.size(), SB_STD_VECTOR_FRONT_ADR(EncKeyAlgParams), (int32_t)EncKeyAlgParams.size(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(KeyAlgOID), (int32_t)KeyAlgOID.size(), SB_STD_VECTOR_FRONT_ADR(KeyAlgParams), (int32_t)KeyAlgParams.size(), (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEYSTORAGE_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyStorageHandle TElCustomCryptoProvider::CreateKeyStorage(bool Persistent, TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyStorageHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_CreateKeyStorage(_Handle, (int8_t)Persistent, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyStorageHandle TElCustomCryptoProvider::CreateKeyStorage(bool Persistent, TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyStorageHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_CreateKeyStorage(_Handle, (int8_t)Persistent, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEYSTORAGE_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE
void TElCustomCryptoProvider::ReleaseKeyStorage(TElCustomCryptoKeyStorage &KeyStorage)
{
	TElClassHandle hKeyStorage = KeyStorage.getHandle();
	SBCheckError(TElCustomCryptoProvider_ReleaseKeyStorage(_Handle, &hKeyStorage));
	KeyStorage.updateHandle(hKeyStorage);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE
void TElCustomCryptoProvider::DeleteKeyStorage(TElCustomCryptoKeyStorage &KeyStorage)
{
	TElClassHandle hKeyStorage = KeyStorage.getHandle();
	SBCheckError(TElCustomCryptoProvider_DeleteKeyStorage(_Handle, &hKeyStorage));
	KeyStorage.updateHandle(hKeyStorage);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElCustomCryptoProvider::EncryptInit(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_EncryptInit(_Handle, Algorithm, Mode, Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElCustomCryptoProvider::EncryptInit(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_EncryptInit(_Handle, Algorithm, Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElCustomCryptoProvider::EncryptInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_EncryptInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElCustomCryptoProvider::EncryptInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_EncryptInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElCustomCryptoProvider::DecryptInit(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_DecryptInit(_Handle, Algorithm, Mode, Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElCustomCryptoProvider::DecryptInit(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_DecryptInit(_Handle, Algorithm, Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElCustomCryptoProvider::DecryptInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_DecryptInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElCustomCryptoProvider::DecryptInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_DecryptInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElCustomCryptoProvider::SignInit(int32_t Algorithm, TElCustomCryptoKey &Key, bool Detached, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_SignInit(_Handle, Algorithm, Key.getHandle(), (int8_t)Detached, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElCustomCryptoProvider::SignInit(int32_t Algorithm, TElCustomCryptoKey *Key, bool Detached, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_SignInit(_Handle, Algorithm, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (int8_t)Detached, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElCustomCryptoProvider::SignInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, bool Detached, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_SignInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Key.getHandle(), (int8_t)Detached, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElCustomCryptoProvider::SignInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, bool Detached, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_SignInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (int8_t)Detached, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElCustomCryptoProvider::VerifyInit(int32_t Algorithm, TElCustomCryptoKey &Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_VerifyInit(_Handle, Algorithm, Key.getHandle(), SigBuffer, SigSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElCustomCryptoProvider::VerifyInit(int32_t Algorithm, TElCustomCryptoKey *Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_VerifyInit(_Handle, Algorithm, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, SigBuffer, SigSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElCustomCryptoProvider::VerifyInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_VerifyInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Key.getHandle(), SigBuffer, SigSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElCustomCryptoProvider::VerifyInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_VerifyInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, SigBuffer, SigSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElCustomCryptoProvider::EncryptUpdate(TElCustomCryptoContext &Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_EncryptUpdate(_Handle, Context.getHandle(), InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElCustomCryptoProvider::EncryptUpdate(TElCustomCryptoContext *Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_EncryptUpdate(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElCustomCryptoProvider::DecryptUpdate(TElCustomCryptoContext &Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_DecryptUpdate(_Handle, Context.getHandle(), InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElCustomCryptoProvider::DecryptUpdate(TElCustomCryptoContext *Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_DecryptUpdate(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElCustomCryptoProvider::SignUpdate(TElCustomCryptoContext &Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_SignUpdate(_Handle, Context.getHandle(), InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElCustomCryptoProvider::SignUpdate(TElCustomCryptoContext *Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_SignUpdate(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElCustomCryptoProvider::VerifyUpdate(TElCustomCryptoContext &Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_VerifyUpdate(_Handle, Context.getHandle(), InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElCustomCryptoProvider::VerifyUpdate(TElCustomCryptoContext *Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_VerifyUpdate(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElCustomCryptoProvider::EncryptFinal(TElCustomCryptoContext &Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_EncryptFinal(_Handle, Context.getHandle(), Buffer, &Size, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElCustomCryptoProvider::EncryptFinal(TElCustomCryptoContext *Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_EncryptFinal(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElCustomCryptoProvider::DecryptFinal(TElCustomCryptoContext &Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_DecryptFinal(_Handle, Context.getHandle(), Buffer, &Size, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElCustomCryptoProvider::DecryptFinal(TElCustomCryptoContext *Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_DecryptFinal(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElCustomCryptoProvider::SignFinal(TElCustomCryptoContext &Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_SignFinal(_Handle, Context.getHandle(), Buffer, &Size, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElCustomCryptoProvider::SignFinal(TElCustomCryptoContext *Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_SignFinal(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE int32_t TElCustomCryptoProvider::VerifyFinal(TElCustomCryptoContext &Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoProvider_VerifyFinal(_Handle, Context.getHandle(), Buffer, &Size, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCryptoProvider::VerifyFinal(TElCustomCryptoContext *Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoProvider_VerifyFinal(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElCustomCryptoProvider::Encrypt(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_Encrypt(_Handle, Algorithm, Mode, Key.getHandle(), InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElCustomCryptoProvider::Encrypt(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_Encrypt(_Handle, Algorithm, Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElCustomCryptoProvider::Encrypt(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_Encrypt_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, Key.getHandle(), InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElCustomCryptoProvider::Encrypt(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_Encrypt_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElCustomCryptoProvider::Decrypt(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_Decrypt(_Handle, Algorithm, Mode, Key.getHandle(), InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElCustomCryptoProvider::Decrypt(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_Decrypt(_Handle, Algorithm, Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElCustomCryptoProvider::Decrypt(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_Decrypt_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, Key.getHandle(), InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElCustomCryptoProvider::Decrypt(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_Decrypt_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElCustomCryptoProvider::Sign(int32_t Algorithm, TElCustomCryptoKey &Key, bool Detached, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_Sign(_Handle, Algorithm, Key.getHandle(), (int8_t)Detached, InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElCustomCryptoProvider::Sign(int32_t Algorithm, TElCustomCryptoKey *Key, bool Detached, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_Sign(_Handle, Algorithm, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (int8_t)Detached, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElCustomCryptoProvider::Sign(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, bool Detached, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_Sign_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Key.getHandle(), (int8_t)Detached, InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElCustomCryptoProvider::Sign(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, bool Detached, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_Sign_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (int8_t)Detached, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE int32_t TElCustomCryptoProvider::Verify(int32_t Algorithm, TElCustomCryptoKey &Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoProvider_Verify(_Handle, Algorithm, Key.getHandle(), InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCryptoProvider::Verify(int32_t Algorithm, TElCustomCryptoKey *Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoProvider_Verify(_Handle, Algorithm, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE int32_t TElCustomCryptoProvider::Verify(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoProvider_Verify_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Key.getHandle(), InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCryptoProvider::Verify(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoProvider_Verify_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE int32_t TElCustomCryptoProvider::VerifyDetached(int32_t Algorithm, TElCustomCryptoKey &Key, void * InBuffer, int32_t InSize, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoProvider_VerifyDetached(_Handle, Algorithm, Key.getHandle(), InBuffer, InSize, SigBuffer, SigSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCryptoProvider::VerifyDetached(int32_t Algorithm, TElCustomCryptoKey *Key, void * InBuffer, int32_t InSize, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoProvider_VerifyDetached(_Handle, Algorithm, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, SigBuffer, SigSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE int32_t TElCustomCryptoProvider::VerifyDetached(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, void * InBuffer, int32_t InSize, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoProvider_VerifyDetached_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Key.getHandle(), InBuffer, InSize, SigBuffer, SigSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCryptoProvider::VerifyDetached(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, void * InBuffer, int32_t InSize, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoProvider_VerifyDetached_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, SigBuffer, SigSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElCustomCryptoProvider::HashInit(int32_t Algorithm, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_HashInit(_Handle, Algorithm, Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElCustomCryptoProvider::HashInit(int32_t Algorithm, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_HashInit(_Handle, Algorithm, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElCustomCryptoProvider::HashInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_HashInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElCustomCryptoProvider::HashInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_HashInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
void TElCustomCryptoProvider::HashFinal(TElCustomCryptoContext &Context, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomCryptoProvider_HashFinal(_Handle, Context.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(732132555, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElCustomCryptoProvider::HashFinal(TElCustomCryptoContext *Context, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomCryptoProvider_HashFinal(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(732132555, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElCustomCryptoProvider::HashUpdate(TElCustomCryptoContext &Context, void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_HashUpdate(_Handle, Context.getHandle(), Buffer, Size, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElCustomCryptoProvider::HashUpdate(TElCustomCryptoContext *Context, void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoProvider_HashUpdate(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
void TElCustomCryptoProvider::Hash(int32_t Algorithm, TElCustomCryptoKey &Key, void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomCryptoProvider_Hash(_Handle, Algorithm, Key.getHandle(), Buffer, Size, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1837494766, 8, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElCustomCryptoProvider::Hash(int32_t Algorithm, TElCustomCryptoKey *Key, void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomCryptoProvider_Hash(_Handle, Algorithm, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1837494766, 8, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
void TElCustomCryptoProvider::Hash(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomCryptoProvider_Hash_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Key.getHandle(), Buffer, Size, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(842125541, 9, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElCustomCryptoProvider::Hash(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomCryptoProvider_Hash_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(842125541, 9, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOCONTEXT
void TElCustomCryptoProvider::ReleaseCryptoContext(TElCustomCryptoContext &Context)
{
	TElClassHandle hContext = Context.getHandle();
	SBCheckError(TElCustomCryptoProvider_ReleaseCryptoContext(_Handle, &hContext));
	Context.updateHandle(hContext);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOCONTEXT */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElCustomCryptoProvider::RandomInit(void * BaseData, int32_t BaseDataSize, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElCustomCryptoProvider_RandomInit(_Handle, BaseData, BaseDataSize, Params.getHandle()));
}

SB_INLINE void TElCustomCryptoProvider::RandomInit(void * BaseData, int32_t BaseDataSize, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElCustomCryptoProvider_RandomInit(_Handle, BaseData, BaseDataSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElCustomCryptoProvider::RandomSeed(void * Data, int32_t DataSize)
{
	SBCheckError(TElCustomCryptoProvider_RandomSeed(_Handle, Data, DataSize));
}

SB_INLINE void TElCustomCryptoProvider::RandomGenerate(void * Buffer, int32_t Size)
{
	SBCheckError(TElCustomCryptoProvider_RandomGenerate(_Handle, Buffer, Size));
}

SB_INLINE int32_t TElCustomCryptoProvider::RandomGenerate(int32_t MaxValue)
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoProvider_RandomGenerate_1(_Handle, MaxValue, &OutResult));
	return OutResult;
}

bool TElCustomCryptoProvider::OwnsObject(TObject &Obj)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoProvider_OwnsObject(_Handle, Obj.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCryptoProvider::OwnsObject(TObject *Obj)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoProvider_OwnsObject(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TClassHandle TElCustomCryptoProvider::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElCustomCryptoProvider_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS
TElCustomCryptoProviderOptions* TElCustomCryptoProvider::get_Options()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomCryptoProvider_get_Options(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Options)
		this->_Inst_Options = new TElCustomCryptoProviderOptions(hOutResult, ohFalse);
	else
		this->_Inst_Options->updateHandle(hOutResult);
	return this->_Inst_Options;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS */

bool TElCustomCryptoProvider::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoProvider_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomCryptoProvider::set_Enabled(bool Value)
{
	SBCheckError(TElCustomCryptoProvider_set_Enabled(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElCustomCryptoProvider::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomCryptoProvider_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElCustomCryptoProvider::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElCustomCryptoProvider_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElCustomCryptoProvider::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElCustomCryptoProvider_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

SB_INLINE void TElCustomCryptoProvider::get_OnCreateObject(TSBCryptoProviderObjectEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCustomCryptoProvider_get_OnCreateObject(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCustomCryptoProvider::set_OnCreateObject(TSBCryptoProviderObjectEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCustomCryptoProvider_set_OnCreateObject(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCustomCryptoProvider::get_OnDestroyObject(TSBCryptoProviderObjectEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCustomCryptoProvider_get_OnDestroyObject(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCustomCryptoProvider::set_OnDestroyObject(TSBCryptoProviderObjectEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCustomCryptoProvider_set_OnDestroyObject(_Handle, pMethodValue, pDataValue));
}

void TElCustomCryptoProvider::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS
	this->_Inst_Options = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}

TElCustomCryptoProvider::TElCustomCryptoProvider(TElCustomCryptoProviderHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElCustomCryptoProvider::TElCustomCryptoProvider(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomCryptoProvider_Create(AOwner.getHandle(), &_Handle));
}

TElCustomCryptoProvider::TElCustomCryptoProvider(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomCryptoProvider_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS
TElCustomCryptoProvider::TElCustomCryptoProvider(TElCustomCryptoProviderOptions &Options, TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomCryptoProvider_Create_1(Options.getHandle(), AOwner.getHandle(), &_Handle));
}

TElCustomCryptoProvider::TElCustomCryptoProvider(TElCustomCryptoProviderOptions *Options, TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomCryptoProvider_Create_1((Options != NULL) ? Options->getHandle() : SB_NULL_HANDLE, (AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS */

TElCustomCryptoProvider::~TElCustomCryptoProvider()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS
	delete this->_Inst_Options;
	this->_Inst_Options = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER

SB_INLINE void TElCustomCryptoProviderManager::Init()
{
	SBCheckError(TElCustomCryptoProviderManager_Init(_Handle));
}

SB_INLINE void TElCustomCryptoProviderManager::Deinit()
{
	SBCheckError(TElCustomCryptoProviderManager_Deinit(_Handle));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
SB_INLINE int32_t TElCustomCryptoProviderManager::RegisterCryptoProvider(TElCustomCryptoProvider &Prov)
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoProviderManager_RegisterCryptoProvider(_Handle, Prov.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCryptoProviderManager::RegisterCryptoProvider(TElCustomCryptoProvider *Prov)
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoProviderManager_RegisterCryptoProvider(_Handle, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
SB_INLINE void TElCustomCryptoProviderManager::UnregisterCryptoProvider(TElCustomCryptoProvider &Prov)
{
	SBCheckError(TElCustomCryptoProviderManager_UnregisterCryptoProvider(_Handle, Prov.getHandle()));
}

SB_INLINE void TElCustomCryptoProviderManager::UnregisterCryptoProvider(TElCustomCryptoProvider *Prov)
{
	SBCheckError(TElCustomCryptoProviderManager_UnregisterCryptoProvider(_Handle, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

SB_INLINE void TElCustomCryptoProviderManager::UnregisterCryptoProvider(int32_t Index)
{
	SBCheckError(TElCustomCryptoProviderManager_UnregisterCryptoProvider_1(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
SB_INLINE void TElCustomCryptoProviderManager::SetDefaultCryptoProvider(TElCustomCryptoProvider &Prov)
{
	SBCheckError(TElCustomCryptoProviderManager_SetDefaultCryptoProvider(_Handle, Prov.getHandle()));
}

SB_INLINE void TElCustomCryptoProviderManager::SetDefaultCryptoProvider(TElCustomCryptoProvider *Prov)
{
	SBCheckError(TElCustomCryptoProviderManager_SetDefaultCryptoProvider(_Handle, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

SB_INLINE void TElCustomCryptoProviderManager::SetDefaultCryptoProvider(int32_t Index)
{
	SBCheckError(TElCustomCryptoProviderManager_SetDefaultCryptoProvider_1(_Handle, Index));
}

SB_INLINE void TElCustomCryptoProviderManager::SetDefaultCryptoProviderType(TElCustomCryptoProviderClassHandle Value)
{
	SBCheckError(TElCustomCryptoProviderManager_SetDefaultCryptoProviderType(_Handle, Value));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoProviderHandle TElCustomCryptoProviderManager::GetSuitableProvider(int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoProviderHandle OutResult;
	SBCheckError(TElCustomCryptoProviderManager_GetSuitableProvider(_Handle, Operation, Algorithm, Mode, Key.getHandle(), Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoProviderHandle TElCustomCryptoProviderManager::GetSuitableProvider(int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoProviderHandle OutResult;
	SBCheckError(TElCustomCryptoProviderManager_GetSuitableProvider(_Handle, Operation, Algorithm, Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoProviderHandle TElCustomCryptoProviderManager::GetSuitableProvider(int32_t Operation, const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoProviderHandle OutResult;
	SBCheckError(TElCustomCryptoProviderManager_GetSuitableProvider_1(_Handle, Operation, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, Key.getHandle(), Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoProviderHandle TElCustomCryptoProviderManager::GetSuitableProvider(int32_t Operation, const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoProviderHandle OutResult;
	SBCheckError(TElCustomCryptoProviderManager_GetSuitableProvider_1(_Handle, Operation, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
SB_INLINE TElCustomCryptoProviderHandle TElCustomCryptoProviderManager::GetSuitableProvider(int32_t Algorithm, int32_t Mode)
{
	TElCustomCryptoProviderHandle OutResult;
	SBCheckError(TElCustomCryptoProviderManager_GetSuitableProvider_2(_Handle, Algorithm, Mode, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
SB_INLINE TElCustomCryptoProviderHandle TElCustomCryptoProviderManager::GetSuitableProvider(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode)
{
	TElCustomCryptoProviderHandle OutResult;
	SBCheckError(TElCustomCryptoProviderManager_GetSuitableProvider_3(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
bool TElCustomCryptoProviderManager::IsOperationSupported(int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoProviderManager_IsOperationSupported(_Handle, Operation, Algorithm, Mode, Key.getHandle(), Params.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCryptoProviderManager::IsOperationSupported(int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoProviderManager_IsOperationSupported(_Handle, Operation, Algorithm, Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
bool TElCustomCryptoProviderManager::IsOperationSupported(int32_t Operation, const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoProviderManager_IsOperationSupported_1(_Handle, Operation, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, Key.getHandle(), Params.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCryptoProviderManager::IsOperationSupported(int32_t Operation, const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoProviderManager_IsOperationSupported_1(_Handle, Operation, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

bool TElCustomCryptoProviderManager::IsAlgorithmSupported(int32_t Algorithm, int32_t Mode)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoProviderManager_IsAlgorithmSupported(_Handle, Algorithm, Mode, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCryptoProviderManager::IsAlgorithmSupported(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoProviderManager_IsAlgorithmSupported_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
bool TElCustomCryptoProviderManager::IsProviderAllowed(TElCustomCryptoProvider &Prov)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoProviderManager_IsProviderAllowed(_Handle, Prov.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCryptoProviderManager::IsProviderAllowed(TElCustomCryptoProvider *Prov)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoProviderManager_IsProviderAllowed(_Handle, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

void TElCustomCryptoProviderManager::GetAlgorithmProperty(int32_t Algorithm, int32_t Mode, const std::vector<uint8_t> &PropID, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomCryptoProviderManager_GetAlgorithmProperty(_Handle, Algorithm, Mode, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-419240698, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElCustomCryptoProviderManager::GetAlgorithmProperty(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, const std::vector<uint8_t> &PropID, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomCryptoProviderManager_GetAlgorithmProperty_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1700494602, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElCustomCryptoProviderManager::GetAlgorithmClass(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoProviderManager_GetAlgorithmClass(_Handle, Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCryptoProviderManager::GetAlgorithmClass(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams)
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoProviderManager_GetAlgorithmClass_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProvider* TElCustomCryptoProviderManager::get_CryptoProviders(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomCryptoProviderManager_get_CryptoProviders(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviders)
		this->_Inst_CryptoProviders = new TElCustomCryptoProvider(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviders->updateHandle(hOutResult);
	return this->_Inst_CryptoProviders;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

SB_INLINE int32_t TElCustomCryptoProviderManager::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoProviderManager_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProvider* TElCustomCryptoProviderManager::get_DefaultCryptoProvider()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomCryptoProviderManager_get_DefaultCryptoProvider(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DefaultCryptoProvider)
		this->_Inst_DefaultCryptoProvider = new TElCustomCryptoProvider(hOutResult, ohFalse);
	else
		this->_Inst_DefaultCryptoProvider->updateHandle(hOutResult);
	return this->_Inst_DefaultCryptoProvider;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

void TElCustomCryptoProviderManager::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	this->_Inst_CryptoProviders = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	this->_Inst_DefaultCryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
}

TElCustomCryptoProviderManager::TElCustomCryptoProviderManager(TElCustomCryptoProviderManagerHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElCustomCryptoProviderManager::TElCustomCryptoProviderManager(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomCryptoProviderManager_Create(AOwner.getHandle(), &_Handle));
}

TElCustomCryptoProviderManager::TElCustomCryptoProviderManager(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomCryptoProviderManager_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElCustomCryptoProviderManager::~TElCustomCryptoProviderManager()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	delete this->_Inst_CryptoProviders;
	this->_Inst_CryptoProviders = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	delete this->_Inst_DefaultCryptoProvider;
	this->_Inst_DefaultCryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE int32_t TElCustomCryptoKeyStorage::AddKey(TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params)
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoKeyStorage_AddKey(_Handle, Key.getHandle(), Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCryptoKeyStorage::AddKey(TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params)
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoKeyStorage_AddKey(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElCustomCryptoKeyStorage::RemoveKey(int32_t Index, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElCustomCryptoKeyStorage_RemoveKey(_Handle, Index, Params.getHandle()));
}

SB_INLINE void TElCustomCryptoKeyStorage::RemoveKey(int32_t Index, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElCustomCryptoKeyStorage_RemoveKey(_Handle, Index, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElCustomCryptoKeyStorage::RemoveKey(TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElCustomCryptoKeyStorage_RemoveKey_1(_Handle, Key.getHandle(), Params.getHandle()));
}

SB_INLINE void TElCustomCryptoKeyStorage::RemoveKey(TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElCustomCryptoKeyStorage_RemoveKey_1(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElCustomCryptoKeyStorage::Clear()
{
	SBCheckError(TElCustomCryptoKeyStorage_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyStorageHandle TElCustomCryptoKeyStorage::Clone(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyStorageHandle OutResult;
	SBCheckError(TElCustomCryptoKeyStorage_Clone(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyStorageHandle TElCustomCryptoKeyStorage::Clone(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyStorageHandle OutResult;
	SBCheckError(TElCustomCryptoKeyStorage_Clone(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElCustomCryptoKeyStorage::Lock()
{
	SBCheckError(TElCustomCryptoKeyStorage_Lock(_Handle));
}

SB_INLINE void TElCustomCryptoKeyStorage::Unlock()
{
	SBCheckError(TElCustomCryptoKeyStorage_Unlock(_Handle));
}

void TElCustomCryptoKeyStorage::GetStorageProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomCryptoKeyStorage_GetStorageProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Default), (int32_t)Default.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-731852618, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomCryptoKeyStorage::SetStorageProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCustomCryptoKeyStorage_SetStorageProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
TElCustomCryptoKey* TElCustomCryptoKeyStorage::get_Keys(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomCryptoKeyStorage_get_Keys(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Keys)
		this->_Inst_Keys = new TElCustomCryptoKey(hOutResult, ohFalse);
	else
		this->_Inst_Keys->updateHandle(hOutResult);
	return this->_Inst_Keys;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

SB_INLINE int32_t TElCustomCryptoKeyStorage::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoKeyStorage_get_Count(_Handle, &OutResult));
	return OutResult;
}

bool TElCustomCryptoKeyStorage::get_IsPersistent()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoKeyStorage_get_IsPersistent(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProvider* TElCustomCryptoKeyStorage::get_CryptoProvider()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomCryptoKeyStorage_get_CryptoProvider(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProvider)
		this->_Inst_CryptoProvider = new TElCustomCryptoProvider(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProvider->updateHandle(hOutResult);
	return this->_Inst_CryptoProvider;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

void TElCustomCryptoKeyStorage::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
	this->_Inst_Keys = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
}

TElCustomCryptoKeyStorage::TElCustomCryptoKeyStorage(TElCustomCryptoKeyStorageHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCustomCryptoKeyStorage::TElCustomCryptoKeyStorage() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomCryptoKeyStorage_Create(&_Handle));
}

TElCustomCryptoKeyStorage::~TElCustomCryptoKeyStorage()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
	delete this->_Inst_Keys;
	this->_Inst_Keys = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	delete this->_Inst_CryptoProvider;
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY

SB_INLINE void TElCustomCryptoKey::Reset()
{
	SBCheckError(TElCustomCryptoKey_Reset(_Handle));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElCustomCryptoKey::Generate(int32_t Bits, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoKey_Generate(_Handle, Bits, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElCustomCryptoKey::Generate(int32_t Bits, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElCustomCryptoKey_Generate(_Handle, Bits, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElCustomCryptoKey::ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElCustomCryptoKey_ImportPublic(_Handle, Buffer, Size, Params.getHandle()));
}

SB_INLINE void TElCustomCryptoKey::ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElCustomCryptoKey_ImportPublic(_Handle, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElCustomCryptoKey::ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElCustomCryptoKey_ImportSecret(_Handle, Buffer, Size, Params.getHandle()));
}

SB_INLINE void TElCustomCryptoKey::ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElCustomCryptoKey_ImportSecret(_Handle, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElCustomCryptoKey::ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElCustomCryptoKey_ExportPublic(_Handle, Buffer, &Size, Params.getHandle()));
}

SB_INLINE void TElCustomCryptoKey::ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElCustomCryptoKey_ExportPublic(_Handle, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElCustomCryptoKey::ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElCustomCryptoKey_ExportSecret(_Handle, Buffer, &Size, Params.getHandle()));
}

SB_INLINE void TElCustomCryptoKey::ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElCustomCryptoKey_ExportSecret(_Handle, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElCustomCryptoKey::Clone(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElCustomCryptoKey_Clone(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElCustomCryptoKey::Clone(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElCustomCryptoKey_Clone(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElCustomCryptoKey::ClonePublic(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElCustomCryptoKey_ClonePublic(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElCustomCryptoKey::ClonePublic(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElCustomCryptoKey_ClonePublic(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElCustomCryptoKey::ClearPublic()
{
	SBCheckError(TElCustomCryptoKey_ClearPublic(_Handle));
}

SB_INLINE void TElCustomCryptoKey::ClearSecret()
{
	SBCheckError(TElCustomCryptoKey_ClearSecret(_Handle));
}

void TElCustomCryptoKey::GetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomCryptoKey_GetKeyProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Default), (int32_t)Default.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(357823112, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomCryptoKey::SetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCustomCryptoKey_SetKeyProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE TObjectHandle TElCustomCryptoKey::GetKeyObjectProp(const std::vector<uint8_t> &PropID, const TObject &Default)
{
	TObjectHandle OutResult;
	SBCheckError(TElCustomCryptoKey_GetKeyObjectProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), Default.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TObjectHandle TElCustomCryptoKey::GetKeyObjectProp(const std::vector<uint8_t> &PropID, const TObject *Default)
{
	TObjectHandle OutResult;
	SBCheckError(TElCustomCryptoKey_GetKeyObjectProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), (Default != NULL) ? Default->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomCryptoKey::SetKeyObjectProp(const std::vector<uint8_t> &PropID, const TObject &Value)
{
	SBCheckError(TElCustomCryptoKey_SetKeyObjectProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), Value.getHandle()));
}

SB_INLINE void TElCustomCryptoKey::SetKeyObjectProp(const std::vector<uint8_t> &PropID, const TObject *Value)
{
	SBCheckError(TElCustomCryptoKey_SetKeyObjectProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElCustomCryptoKey::ChangeAlgorithm(int32_t Algorithm)
{
	SBCheckError(TElCustomCryptoKey_ChangeAlgorithm(_Handle, Algorithm));
}

SB_INLINE void TElCustomCryptoKey::PrepareForEncryption(bool MultiUse)
{
	SBCheckError(TElCustomCryptoKey_PrepareForEncryption(_Handle, (int8_t)MultiUse));
}

SB_INLINE void TElCustomCryptoKey::PrepareForSigning(bool MultiUse)
{
	SBCheckError(TElCustomCryptoKey_PrepareForSigning(_Handle, (int8_t)MultiUse));
}

SB_INLINE void TElCustomCryptoKey::CancelPreparation()
{
	SBCheckError(TElCustomCryptoKey_CancelPreparation(_Handle));
}

bool TElCustomCryptoKey::AsyncOperationFinished()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoKey_AsyncOperationFinished(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
bool TElCustomCryptoKey::Equals(TElCustomCryptoKey &Key, bool PublicOnly, TElRelativeDistinguishedName &Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoKey_Equals(_Handle, Key.getHandle(), (int8_t)PublicOnly, Params.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCryptoKey::Equals(TElCustomCryptoKey *Key, bool PublicOnly, TElRelativeDistinguishedName *Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoKey_Equals(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (int8_t)PublicOnly, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElCustomCryptoKey::Persistentiate()
{
	SBCheckError(TElCustomCryptoKey_Persistentiate(_Handle));
}

bool TElCustomCryptoKey::get_IsPublic()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoKey_get_IsPublic(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCryptoKey::get_IsSecret()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoKey_get_IsSecret(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCryptoKey::get_IsExportable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoKey_get_IsExportable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCryptoKey::get_IsPersistent()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoKey_get_IsPersistent(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCryptoKey::get_IsValid()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoKey_get_IsValid(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElCustomCryptoKey::get_Bits()
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoKey_get_Bits(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCryptoKey::get_Algorithm()
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoKey_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

void TElCustomCryptoKey::get_Value(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomCryptoKey_get_Value(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1018985884, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomCryptoKey::set_Value(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCustomCryptoKey_set_Value(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElCustomCryptoKey::get_IV(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomCryptoKey_get_IV(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1797683558, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomCryptoKey::set_IV(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCustomCryptoKey_set_IV(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElCustomCryptoKey::get_Mode()
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoKey_get_Mode(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomCryptoKey::set_Mode(int32_t Value)
{
	SBCheckError(TElCustomCryptoKey_set_Mode(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProvider* TElCustomCryptoKey::get_CryptoProvider()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomCryptoKey_get_CryptoProvider(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProvider)
		this->_Inst_CryptoProvider = new TElCustomCryptoProvider(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProvider->updateHandle(hOutResult);
	return this->_Inst_CryptoProvider;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE
TElCustomCryptoKeyStorage* TElCustomCryptoKey::get_KeyStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomCryptoKey_get_KeyStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyStorage)
		this->_Inst_KeyStorage = new TElCustomCryptoKeyStorage(hOutResult, ohFalse);
	else
		this->_Inst_KeyStorage->updateHandle(hOutResult);
	return this->_Inst_KeyStorage;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE */

void TElCustomCryptoKey::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE
	this->_Inst_KeyStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE */
}

TElCustomCryptoKey::TElCustomCryptoKey(TElCustomCryptoKeyHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoKey::TElCustomCryptoKey(TElCustomCryptoProvider &CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomCryptoKey_Create(CryptoProvider.getHandle(), &_Handle));
}

TElCustomCryptoKey::TElCustomCryptoKey(TElCustomCryptoProvider *CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomCryptoKey_Create((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

TElCustomCryptoKey::~TElCustomCryptoKey()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	delete this->_Inst_CryptoProvider;
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE
	delete this->_Inst_KeyStorage;
	this->_Inst_KeyStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE */
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOCONTEXT

void TElCustomCryptoContext::GetContextProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomCryptoContext_GetContextProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Default), (int32_t)Default.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-243842912, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomCryptoContext::SetContextProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCustomCryptoContext_SetContextProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElCustomCryptoContext::Clone(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElCustomCryptoContext_Clone(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElCustomCryptoContext::Clone(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElCustomCryptoContext_Clone(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE int64_t TElCustomCryptoContext::EstimateOutputSize(int64_t InSize)
{
	int64_t OutResult;
	SBCheckError(TElCustomCryptoContext_EstimateOutputSize(_Handle, InSize, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCryptoContext::get_Algorithm()
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoContext_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProvider* TElCustomCryptoContext::get_CryptoProvider()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomCryptoContext_get_CryptoProvider(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProvider)
		this->_Inst_CryptoProvider = new TElCustomCryptoProvider(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProvider->updateHandle(hOutResult);
	return this->_Inst_CryptoProvider;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

SB_INLINE int32_t TElCustomCryptoContext::get_KeySize()
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoContext_get_KeySize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomCryptoContext::set_KeySize(int32_t Value)
{
	SBCheckError(TElCustomCryptoContext_set_KeySize(_Handle, Value));
}

SB_INLINE int32_t TElCustomCryptoContext::get_BlockSize()
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoContext_get_BlockSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomCryptoContext::set_BlockSize(int32_t Value)
{
	SBCheckError(TElCustomCryptoContext_set_BlockSize(_Handle, Value));
}

SB_INLINE int32_t TElCustomCryptoContext::get_DigestSize()
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoContext_get_DigestSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomCryptoContext::set_DigestSize(int32_t Value)
{
	SBCheckError(TElCustomCryptoContext_set_DigestSize(_Handle, Value));
}

SB_INLINE int32_t TElCustomCryptoContext::get_Mode()
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoContext_get_Mode(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomCryptoContext::set_Mode(int32_t Value)
{
	SBCheckError(TElCustomCryptoContext_set_Mode(_Handle, Value));
}

SB_INLINE int32_t TElCustomCryptoContext::get_Padding()
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoContext_get_Padding(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomCryptoContext::set_Padding(int32_t Value)
{
	SBCheckError(TElCustomCryptoContext_set_Padding(_Handle, Value));
}

SB_INLINE int32_t TElCustomCryptoContext::get_AlgorithmClass()
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoContext_get_AlgorithmClass(_Handle, &OutResult));
	return OutResult;
}

void TElCustomCryptoContext::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
}

TElCustomCryptoContext::TElCustomCryptoContext(TElCustomCryptoContextHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCustomCryptoContext::TElCustomCryptoContext() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomCryptoContext_Create(&_Handle));
}

TElCustomCryptoContext::~TElCustomCryptoContext()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	delete this->_Inst_CryptoProvider;
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOCONTEXT */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS

SB_INLINE void TElCustomCryptoProviderOptions::Assign(TElCustomCryptoProviderOptions &Options)
{
	SBCheckError(TElCustomCryptoProviderOptions_Assign(_Handle, Options.getHandle()));
}

SB_INLINE void TElCustomCryptoProviderOptions::Assign(TElCustomCryptoProviderOptions *Options)
{
	SBCheckError(TElCustomCryptoProviderOptions_Assign(_Handle, (Options != NULL) ? Options->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElCustomCryptoProviderOptions::get_MaxPublicKeySize()
{
	int32_t OutResult;
	SBCheckError(TElCustomCryptoProviderOptions_get_MaxPublicKeySize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomCryptoProviderOptions::set_MaxPublicKeySize(int32_t Value)
{
	SBCheckError(TElCustomCryptoProviderOptions_set_MaxPublicKeySize(_Handle, Value));
}

bool TElCustomCryptoProviderOptions::get_StoreKeys()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCryptoProviderOptions_get_StoreKeys(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomCryptoProviderOptions::set_StoreKeys(bool Value)
{
	SBCheckError(TElCustomCryptoProviderOptions_set_StoreKeys(_Handle, (int8_t)Value));
}

TElCustomCryptoProviderOptions::TElCustomCryptoProviderOptions(TElCustomCryptoProviderOptionsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElCustomCryptoProviderOptions::TElCustomCryptoProviderOptions() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomCryptoProviderOptions_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS */

#ifdef SB_USE_CLASS_TELBLACKBOXCRYPTOPROVIDER

SB_INLINE TClassHandle TElBlackboxCryptoProvider::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBlackboxCryptoProvider_ClassType(&OutResult));
	return OutResult;
}

TElBlackboxCryptoProvider::TElBlackboxCryptoProvider(TElBlackboxCryptoProviderHandle handle, TElOwnHandle ownHandle) : TElCustomCryptoProvider(handle, ownHandle)
{
}

TElBlackboxCryptoProvider::TElBlackboxCryptoProvider(TComponent &AOwner) : TElCustomCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBlackboxCryptoProvider_Create(AOwner.getHandle(), &_Handle));
}

TElBlackboxCryptoProvider::TElBlackboxCryptoProvider(TComponent *AOwner) : TElCustomCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBlackboxCryptoProvider_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS
TElBlackboxCryptoProvider::TElBlackboxCryptoProvider(TElCustomCryptoProviderOptions &Options, TComponent &AOwner) : TElCustomCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBlackboxCryptoProvider_Create_1(Options.getHandle(), AOwner.getHandle(), &_Handle));
}

TElBlackboxCryptoProvider::TElBlackboxCryptoProvider(TElCustomCryptoProviderOptions *Options, TComponent *AOwner) : TElCustomCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBlackboxCryptoProvider_Create_1((Options != NULL) ? Options->getHandle() : SB_NULL_HANDLE, (AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS */

#endif /* SB_USE_CLASS_TELBLACKBOXCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELEXTERNALCRYPTOPROVIDER

SB_INLINE TClassHandle TElExternalCryptoProvider::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElExternalCryptoProvider_ClassType(&OutResult));
	return OutResult;
}

TElExternalCryptoProvider::TElExternalCryptoProvider(TElExternalCryptoProviderHandle handle, TElOwnHandle ownHandle) : TElBlackboxCryptoProvider(handle, ownHandle)
{
}

TElExternalCryptoProvider::TElExternalCryptoProvider(TComponent &AOwner) : TElBlackboxCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElExternalCryptoProvider_Create(AOwner.getHandle(), &_Handle));
}

TElExternalCryptoProvider::TElExternalCryptoProvider(TComponent *AOwner) : TElBlackboxCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElExternalCryptoProvider_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS
TElExternalCryptoProvider::TElExternalCryptoProvider(TElCustomCryptoProviderOptions &Options, TComponent &AOwner) : TElBlackboxCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElExternalCryptoProvider_Create_1(Options.getHandle(), AOwner.getHandle(), &_Handle));
}

TElExternalCryptoProvider::TElExternalCryptoProvider(TElCustomCryptoProviderOptions *Options, TComponent *AOwner) : TElBlackboxCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElExternalCryptoProvider_Create_1((Options != NULL) ? Options->getHandle() : SB_NULL_HANDLE, (AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS */

#endif /* SB_USE_CLASS_TELEXTERNALCRYPTOPROVIDER */

};	/* namespace SecureBlackbox */
