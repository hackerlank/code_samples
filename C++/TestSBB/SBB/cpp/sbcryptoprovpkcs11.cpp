#include "sbcryptoprovpkcs11.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPKCS11CRYPTOPROVIDEROPTIONS

SB_INLINE void TElPKCS11CryptoProviderOptions::Assign(TElCustomCryptoProviderOptions &Options)
{
	SBCheckError(TElPKCS11CryptoProviderOptions_Assign(_Handle, Options.getHandle()));
}

SB_INLINE void TElPKCS11CryptoProviderOptions::Assign(TElCustomCryptoProviderOptions *Options)
{
	SBCheckError(TElPKCS11CryptoProviderOptions_Assign(_Handle, (Options != NULL) ? Options->getHandle() : SB_NULL_HANDLE));
}

bool TElPKCS11CryptoProviderOptions::get_UseForPublicKeyOperations()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11CryptoProviderOptions_get_UseForPublicKeyOperations(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11CryptoProviderOptions::set_UseForPublicKeyOperations(bool Value)
{
	SBCheckError(TElPKCS11CryptoProviderOptions_set_UseForPublicKeyOperations(_Handle, (int8_t)Value));
}

bool TElPKCS11CryptoProviderOptions::get_UseForSymmetricKeyOperations()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11CryptoProviderOptions_get_UseForSymmetricKeyOperations(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11CryptoProviderOptions::set_UseForSymmetricKeyOperations(bool Value)
{
	SBCheckError(TElPKCS11CryptoProviderOptions_set_UseForSymmetricKeyOperations(_Handle, (int8_t)Value));
}

bool TElPKCS11CryptoProviderOptions::get_UseForHashingOperations()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11CryptoProviderOptions_get_UseForHashingOperations(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11CryptoProviderOptions::set_UseForHashingOperations(bool Value)
{
	SBCheckError(TElPKCS11CryptoProviderOptions_set_UseForHashingOperations(_Handle, (int8_t)Value));
}

bool TElPKCS11CryptoProviderOptions::get_UseForNonPrivateOperations()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11CryptoProviderOptions_get_UseForNonPrivateOperations(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11CryptoProviderOptions::set_UseForNonPrivateOperations(bool Value)
{
	SBCheckError(TElPKCS11CryptoProviderOptions_set_UseForNonPrivateOperations(_Handle, (int8_t)Value));
}

bool TElPKCS11CryptoProviderOptions::get_ForceUseForIndirectHashingOperations()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11CryptoProviderOptions_get_ForceUseForIndirectHashingOperations(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11CryptoProviderOptions::set_ForceUseForIndirectHashingOperations(bool Value)
{
	SBCheckError(TElPKCS11CryptoProviderOptions_set_ForceUseForIndirectHashingOperations(_Handle, (int8_t)Value));
}

bool TElPKCS11CryptoProviderOptions::get_DelayedPublicKeyImport()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11CryptoProviderOptions_get_DelayedPublicKeyImport(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11CryptoProviderOptions::set_DelayedPublicKeyImport(bool Value)
{
	SBCheckError(TElPKCS11CryptoProviderOptions_set_DelayedPublicKeyImport(_Handle, (int8_t)Value));
}

bool TElPKCS11CryptoProviderOptions::get_ThreadSafe()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11CryptoProviderOptions_get_ThreadSafe(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11CryptoProviderOptions::set_ThreadSafe(bool Value)
{
	SBCheckError(TElPKCS11CryptoProviderOptions_set_ThreadSafe(_Handle, (int8_t)Value));
}

bool TElPKCS11CryptoProviderOptions::get_IgnoreReportedSupportedAlgorithms()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11CryptoProviderOptions_get_IgnoreReportedSupportedAlgorithms(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11CryptoProviderOptions::set_IgnoreReportedSupportedAlgorithms(bool Value)
{
	SBCheckError(TElPKCS11CryptoProviderOptions_set_IgnoreReportedSupportedAlgorithms(_Handle, (int8_t)Value));
}

bool TElPKCS11CryptoProviderOptions::get_NormalizeSourceLength()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11CryptoProviderOptions_get_NormalizeSourceLength(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS11CryptoProviderOptions::set_NormalizeSourceLength(bool Value)
{
	SBCheckError(TElPKCS11CryptoProviderOptions_set_NormalizeSourceLength(_Handle, (int8_t)Value));
}

void TElPKCS11CryptoProviderOptions::get_OperationPIN(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS11CryptoProviderOptions_get_OperationPIN(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1369636021, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11CryptoProviderOptions::set_OperationPIN(const std::string &Value)
{
	SBCheckError(TElPKCS11CryptoProviderOptions_set_OperationPIN(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPKCS11CryptoProviderOptions::get_DefaultRSAPublicExponent(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11CryptoProviderOptions_get_DefaultRSAPublicExponent(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1875001440, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11CryptoProviderOptions::set_DefaultRSAPublicExponent(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11CryptoProviderOptions_set_DefaultRSAPublicExponent(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElPKCS11CryptoProviderOptions::TElPKCS11CryptoProviderOptions(TElPKCS11CryptoProviderOptionsHandle handle, TElOwnHandle ownHandle) : TElCustomCryptoProviderOptions(handle, ownHandle)
{
}

TElPKCS11CryptoProviderOptions::TElPKCS11CryptoProviderOptions() : TElCustomCryptoProviderOptions(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11CryptoProviderOptions_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPKCS11CRYPTOPROVIDEROPTIONS */

#ifdef SB_USE_CLASS_TELPKCS11CRYPTOPROVIDER

SB_INLINE void TElPKCS11CryptoProvider::Init()
{
	SBCheckError(TElPKCS11CryptoProvider_Init(_Handle));
}

SB_INLINE void TElPKCS11CryptoProvider::Deinit()
{
	SBCheckError(TElPKCS11CryptoProvider_Deinit(_Handle));
}

SB_INLINE void TElPKCS11CryptoProvider::SetAsDefault()
{
	SBCheckError(TElPKCS11CryptoProvider_SetAsDefault());
}

SB_INLINE void TElPKCS11CryptoProvider::SetAsDefault_Inst()
{
	SBCheckError(TElPKCS11CryptoProvider_SetAsDefault_1(_Handle));
}

SB_INLINE TElCustomCryptoProviderHandle TElPKCS11CryptoProvider::Clone()
{
	TElCustomCryptoProviderHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_Clone(_Handle, &OutResult));
	return OutResult;
}

bool TElPKCS11CryptoProvider::IsAlgorithmSupported(int32_t Algorithm, int32_t Mode)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11CryptoProvider_IsAlgorithmSupported(_Handle, Algorithm, Mode, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11CryptoProvider::IsAlgorithmSupported(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11CryptoProvider_IsAlgorithmSupported_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
bool TElPKCS11CryptoProvider::IsOperationSupported(int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11CryptoProvider_IsOperationSupported(_Handle, Operation, Algorithm, Mode, Key.getHandle(), Params.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11CryptoProvider::IsOperationSupported(int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11CryptoProvider_IsOperationSupported(_Handle, Operation, Algorithm, Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
bool TElPKCS11CryptoProvider::IsOperationSupported(int32_t Operation, const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11CryptoProvider_IsOperationSupported_1(_Handle, Operation, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, Key.getHandle(), Params.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11CryptoProvider::IsOperationSupported(int32_t Operation, const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11CryptoProvider_IsOperationSupported_1(_Handle, Operation, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

void TElPKCS11CryptoProvider::GetAlgorithmProperty(int32_t Algorithm, int32_t Mode, const std::vector<uint8_t> &PropID, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11CryptoProvider_GetAlgorithmProperty(_Handle, Algorithm, Mode, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1508929938, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11CryptoProvider::GetAlgorithmProperty(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, const std::vector<uint8_t> &PropID, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11CryptoProvider_GetAlgorithmProperty_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-145555180, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElPKCS11CryptoProvider::GetAlgorithmClass(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11CryptoProvider_GetAlgorithmClass(_Handle, Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11CryptoProvider::GetAlgorithmClass(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11CryptoProvider_GetAlgorithmClass_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), &OutResult));
	return OutResult;
}

void TElPKCS11CryptoProvider::GetProviderProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11CryptoProvider_GetProviderProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Default), (int32_t)Default.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1941861931, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_IOS
SB_INLINE TObjectHandle TElPKCS11CryptoProvider::GetProviderProp(const std::vector<uint8_t> &PropID, TObject &Default)
{
	TObjectHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_GetProviderProp_1(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), Default.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TObjectHandle TElPKCS11CryptoProvider::GetProviderProp(const std::vector<uint8_t> &PropID, TObject *Default)
{
	TObjectHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_GetProviderProp_1(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), (Default != NULL) ? Default->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif

SB_INLINE void TElPKCS11CryptoProvider::SetProviderProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11CryptoProvider_SetProviderProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
#ifdef SB_IOS
}

SB_INLINE void TElPKCS11CryptoProvider::SetProviderProp(const std::vector<uint8_t> &PropID, TObject &Value)
{
	SBCheckError(TElPKCS11CryptoProvider_SetProviderProp_1(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), Value.getHandle()));
}

SB_INLINE void TElPKCS11CryptoProvider::SetProviderProp(const std::vector<uint8_t> &PropID, TObject *Value)
{
	SBCheckError(TElPKCS11CryptoProvider_SetProviderProp_1(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
#endif
}

SB_INLINE TElCustomCryptoProviderHandle TElPKCS11CryptoProvider::GetDefaultInstance()
{
	TElCustomCryptoProviderHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_GetDefaultInstance(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElPKCS11CryptoProvider::CreateKey(int32_t Algorithm, int32_t Mode, TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_CreateKey(_Handle, Algorithm, Mode, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElPKCS11CryptoProvider::CreateKey(int32_t Algorithm, int32_t Mode, TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_CreateKey(_Handle, Algorithm, Mode, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElPKCS11CryptoProvider::CreateKey(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_CreateKey_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElPKCS11CryptoProvider::CreateKey(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_CreateKey_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
SB_INLINE TElCustomCryptoKeyHandle TElPKCS11CryptoProvider::CloneKey(TElCustomCryptoKey &Key)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_CloneKey(_Handle, Key.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElPKCS11CryptoProvider::CloneKey(TElCustomCryptoKey *Key)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_CloneKey(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
void TElPKCS11CryptoProvider::ReleaseKey(TElCustomCryptoKey &Key)
{
	TElClassHandle hKey = Key.getHandle();
	SBCheckError(TElPKCS11CryptoProvider_ReleaseKey(_Handle, &hKey));
	Key.updateHandle(hKey);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
void TElPKCS11CryptoProvider::DeleteKey(TElCustomCryptoKey &Key)
{
	TElClassHandle hKey = Key.getHandle();
	SBCheckError(TElPKCS11CryptoProvider_DeleteKey(_Handle, &hKey));
	Key.updateHandle(hKey);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElPKCS11CryptoProvider::DecryptKey(void * EncKey, int32_t EncKeySize, const std::vector<uint8_t> &EncKeyAlgOID, const std::vector<uint8_t> &EncKeyAlgParams, TElCustomCryptoKey &Key, const std::vector<uint8_t> &KeyAlgOID, const std::vector<uint8_t> &KeyAlgParams, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_DecryptKey(_Handle, EncKey, EncKeySize, SB_STD_VECTOR_FRONT_ADR(EncKeyAlgOID), (int32_t)EncKeyAlgOID.size(), SB_STD_VECTOR_FRONT_ADR(EncKeyAlgParams), (int32_t)EncKeyAlgParams.size(), Key.getHandle(), SB_STD_VECTOR_FRONT_ADR(KeyAlgOID), (int32_t)KeyAlgOID.size(), SB_STD_VECTOR_FRONT_ADR(KeyAlgParams), (int32_t)KeyAlgParams.size(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElPKCS11CryptoProvider::DecryptKey(void * EncKey, int32_t EncKeySize, const std::vector<uint8_t> &EncKeyAlgOID, const std::vector<uint8_t> &EncKeyAlgParams, TElCustomCryptoKey *Key, const std::vector<uint8_t> &KeyAlgOID, const std::vector<uint8_t> &KeyAlgParams, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_DecryptKey(_Handle, EncKey, EncKeySize, SB_STD_VECTOR_FRONT_ADR(EncKeyAlgOID), (int32_t)EncKeyAlgOID.size(), SB_STD_VECTOR_FRONT_ADR(EncKeyAlgParams), (int32_t)EncKeyAlgParams.size(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(KeyAlgOID), (int32_t)KeyAlgOID.size(), SB_STD_VECTOR_FRONT_ADR(KeyAlgParams), (int32_t)KeyAlgParams.size(), (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElPKCS11CryptoProvider::EncryptInit(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_EncryptInit(_Handle, Algorithm, Mode, Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElPKCS11CryptoProvider::EncryptInit(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_EncryptInit(_Handle, Algorithm, Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElPKCS11CryptoProvider::EncryptInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_EncryptInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElPKCS11CryptoProvider::EncryptInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_EncryptInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElPKCS11CryptoProvider::DecryptInit(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_DecryptInit(_Handle, Algorithm, Mode, Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElPKCS11CryptoProvider::DecryptInit(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_DecryptInit(_Handle, Algorithm, Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElPKCS11CryptoProvider::DecryptInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_DecryptInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElPKCS11CryptoProvider::DecryptInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_DecryptInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElPKCS11CryptoProvider::SignInit(int32_t Algorithm, TElCustomCryptoKey &Key, bool Detached, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_SignInit(_Handle, Algorithm, Key.getHandle(), (int8_t)Detached, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElPKCS11CryptoProvider::SignInit(int32_t Algorithm, TElCustomCryptoKey *Key, bool Detached, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_SignInit(_Handle, Algorithm, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (int8_t)Detached, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElPKCS11CryptoProvider::SignInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, bool Detached, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_SignInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Key.getHandle(), (int8_t)Detached, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElPKCS11CryptoProvider::SignInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, bool Detached, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_SignInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (int8_t)Detached, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElPKCS11CryptoProvider::VerifyInit(int32_t Algorithm, TElCustomCryptoKey &Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_VerifyInit(_Handle, Algorithm, Key.getHandle(), SigBuffer, SigSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElPKCS11CryptoProvider::VerifyInit(int32_t Algorithm, TElCustomCryptoKey *Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_VerifyInit(_Handle, Algorithm, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, SigBuffer, SigSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElPKCS11CryptoProvider::VerifyInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_VerifyInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Key.getHandle(), SigBuffer, SigSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElPKCS11CryptoProvider::VerifyInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_VerifyInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, SigBuffer, SigSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElPKCS11CryptoProvider::EncryptUpdate(TElCustomCryptoContext &Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElPKCS11CryptoProvider_EncryptUpdate(_Handle, Context.getHandle(), InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElPKCS11CryptoProvider::EncryptUpdate(TElCustomCryptoContext *Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElPKCS11CryptoProvider_EncryptUpdate(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElPKCS11CryptoProvider::DecryptUpdate(TElCustomCryptoContext &Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElPKCS11CryptoProvider_DecryptUpdate(_Handle, Context.getHandle(), InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElPKCS11CryptoProvider::DecryptUpdate(TElCustomCryptoContext *Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElPKCS11CryptoProvider_DecryptUpdate(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElPKCS11CryptoProvider::SignUpdate(TElCustomCryptoContext &Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElPKCS11CryptoProvider_SignUpdate(_Handle, Context.getHandle(), InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElPKCS11CryptoProvider::SignUpdate(TElCustomCryptoContext *Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElPKCS11CryptoProvider_SignUpdate(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElPKCS11CryptoProvider::VerifyUpdate(TElCustomCryptoContext &Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElPKCS11CryptoProvider_VerifyUpdate(_Handle, Context.getHandle(), InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElPKCS11CryptoProvider::VerifyUpdate(TElCustomCryptoContext *Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElPKCS11CryptoProvider_VerifyUpdate(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElPKCS11CryptoProvider::EncryptFinal(TElCustomCryptoContext &Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElPKCS11CryptoProvider_EncryptFinal(_Handle, Context.getHandle(), Buffer, &Size, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElPKCS11CryptoProvider::EncryptFinal(TElCustomCryptoContext *Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElPKCS11CryptoProvider_EncryptFinal(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElPKCS11CryptoProvider::DecryptFinal(TElCustomCryptoContext &Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElPKCS11CryptoProvider_DecryptFinal(_Handle, Context.getHandle(), Buffer, &Size, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElPKCS11CryptoProvider::DecryptFinal(TElCustomCryptoContext *Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElPKCS11CryptoProvider_DecryptFinal(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElPKCS11CryptoProvider::SignFinal(TElCustomCryptoContext &Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElPKCS11CryptoProvider_SignFinal(_Handle, Context.getHandle(), Buffer, &Size, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElPKCS11CryptoProvider::SignFinal(TElCustomCryptoContext *Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElPKCS11CryptoProvider_SignFinal(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE int32_t TElPKCS11CryptoProvider::VerifyFinal(TElCustomCryptoContext &Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11CryptoProvider_VerifyFinal(_Handle, Context.getHandle(), Buffer, &Size, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS11CryptoProvider::VerifyFinal(TElCustomCryptoContext *Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11CryptoProvider_VerifyFinal(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElPKCS11CryptoProvider::HashInit(int32_t Algorithm, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_HashInit(_Handle, Algorithm, Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElPKCS11CryptoProvider::HashInit(int32_t Algorithm, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_HashInit(_Handle, Algorithm, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElPKCS11CryptoProvider::HashInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_HashInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElPKCS11CryptoProvider::HashInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_HashInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElPKCS11CryptoProvider::HashUpdate(TElCustomCryptoContext &Context, void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElPKCS11CryptoProvider_HashUpdate(_Handle, Context.getHandle(), Buffer, Size, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElPKCS11CryptoProvider::HashUpdate(TElCustomCryptoContext *Context, void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElPKCS11CryptoProvider_HashUpdate(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
void TElPKCS11CryptoProvider::HashFinal(TElCustomCryptoContext &Context, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11CryptoProvider_HashFinal(_Handle, Context.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1583357807, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS11CryptoProvider::HashFinal(TElCustomCryptoContext *Context, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11CryptoProvider_HashFinal(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1583357807, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOCONTEXT
void TElPKCS11CryptoProvider::ReleaseCryptoContext(TElCustomCryptoContext &Context)
{
	TElClassHandle hContext = Context.getHandle();
	SBCheckError(TElPKCS11CryptoProvider_ReleaseCryptoContext(_Handle, &hContext));
	Context.updateHandle(hContext);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOCONTEXT */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEYSTORAGE_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyStorageHandle TElPKCS11CryptoProvider::CreateKeyStorage(bool Persistent, TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyStorageHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_CreateKeyStorage(_Handle, (int8_t)Persistent, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyStorageHandle TElPKCS11CryptoProvider::CreateKeyStorage(bool Persistent, TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyStorageHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_CreateKeyStorage(_Handle, (int8_t)Persistent, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEYSTORAGE_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE
void TElPKCS11CryptoProvider::ReleaseKeyStorage(TElCustomCryptoKeyStorage &KeyStorage)
{
	TElClassHandle hKeyStorage = KeyStorage.getHandle();
	SBCheckError(TElPKCS11CryptoProvider_ReleaseKeyStorage(_Handle, &hKeyStorage));
	KeyStorage.updateHandle(hKeyStorage);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE
void TElPKCS11CryptoProvider::DeleteKeyStorage(TElCustomCryptoKeyStorage &KeyStorage)
{
	TElClassHandle hKeyStorage = KeyStorage.getHandle();
	SBCheckError(TElPKCS11CryptoProvider_DeleteKeyStorage(_Handle, &hKeyStorage));
	KeyStorage.updateHandle(hKeyStorage);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElPKCS11CryptoProvider::RandomInit(void * BaseData, int32_t BaseDataSize, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElPKCS11CryptoProvider_RandomInit(_Handle, BaseData, BaseDataSize, Params.getHandle()));
}

SB_INLINE void TElPKCS11CryptoProvider::RandomInit(void * BaseData, int32_t BaseDataSize, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElPKCS11CryptoProvider_RandomInit(_Handle, BaseData, BaseDataSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElPKCS11CryptoProvider::RandomSeed(void * Data, int32_t DataSize)
{
	SBCheckError(TElPKCS11CryptoProvider_RandomSeed(_Handle, Data, DataSize));
}

SB_INLINE void TElPKCS11CryptoProvider::RandomGenerate(void * Buffer, int32_t Size)
{
	SBCheckError(TElPKCS11CryptoProvider_RandomGenerate(_Handle, Buffer, Size));
}

SB_INLINE int32_t TElPKCS11CryptoProvider::RandomGenerate(int32_t MaxValue)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11CryptoProvider_RandomGenerate_1(_Handle, MaxValue, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TElPKCS11CryptoProvider::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPKCS11CryptoProvider_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS11CryptoProvider::get_OnAttributesPrepared(TSBPKCS11CryptoProviderAttributesPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPKCS11CryptoProvider_get_OnAttributesPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPKCS11CryptoProvider::set_OnAttributesPrepared(TSBPKCS11CryptoProviderAttributesPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPKCS11CryptoProvider_set_OnAttributesPrepared(_Handle, pMethodValue, pDataValue));
}

TElPKCS11CryptoProvider::TElPKCS11CryptoProvider(TElPKCS11CryptoProviderHandle handle, TElOwnHandle ownHandle) : TElExternalCryptoProvider(handle, ownHandle)
{
}

TElPKCS11CryptoProvider::TElPKCS11CryptoProvider(TComponent &AOwner) : TElExternalCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11CryptoProvider_Create(AOwner.getHandle(), &_Handle));
}

TElPKCS11CryptoProvider::TElPKCS11CryptoProvider(TComponent *AOwner) : TElExternalCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11CryptoProvider_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS
TElPKCS11CryptoProvider::TElPKCS11CryptoProvider(TElCustomCryptoProviderOptions &Options, TComponent &AOwner) : TElExternalCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11CryptoProvider_Create_1(Options.getHandle(), AOwner.getHandle(), &_Handle));
}

TElPKCS11CryptoProvider::TElPKCS11CryptoProvider(TElCustomCryptoProviderOptions *Options, TComponent *AOwner) : TElExternalCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11CryptoProvider_Create_1((Options != NULL) ? Options->getHandle() : SB_NULL_HANDLE, (AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS */

#endif /* SB_USE_CLASS_TELPKCS11CRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELPKCS11CRYPTOKEY

SB_INLINE void TElPKCS11CryptoKey::Reset()
{
	SBCheckError(TElPKCS11CryptoKey_Reset(_Handle));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElPKCS11CryptoKey::Generate(int32_t Bits, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElPKCS11CryptoKey_Generate(_Handle, Bits, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElPKCS11CryptoKey::Generate(int32_t Bits, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElPKCS11CryptoKey_Generate(_Handle, Bits, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElPKCS11CryptoKey::ChangeAlgorithm(int32_t Algorithm)
{
	SBCheckError(TElPKCS11CryptoKey_ChangeAlgorithm(_Handle, Algorithm));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElPKCS11CryptoKey::ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElPKCS11CryptoKey_ImportPublic(_Handle, Buffer, Size, Params.getHandle()));
}

SB_INLINE void TElPKCS11CryptoKey::ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElPKCS11CryptoKey_ImportPublic(_Handle, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElPKCS11CryptoKey::ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElPKCS11CryptoKey_ImportSecret(_Handle, Buffer, Size, Params.getHandle()));
}

SB_INLINE void TElPKCS11CryptoKey::ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElPKCS11CryptoKey_ImportSecret(_Handle, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElPKCS11CryptoKey::ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElPKCS11CryptoKey_ExportPublic(_Handle, Buffer, &Size, Params.getHandle()));
}

SB_INLINE void TElPKCS11CryptoKey::ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElPKCS11CryptoKey_ExportPublic(_Handle, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElPKCS11CryptoKey::ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElPKCS11CryptoKey_ExportSecret(_Handle, Buffer, &Size, Params.getHandle()));
}

SB_INLINE void TElPKCS11CryptoKey::ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElPKCS11CryptoKey_ExportSecret(_Handle, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElPKCS11CryptoKey::Clone(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElPKCS11CryptoKey_Clone(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElPKCS11CryptoKey::Clone(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElPKCS11CryptoKey_Clone(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElPKCS11CryptoKey::ClonePublic(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElPKCS11CryptoKey_ClonePublic(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElPKCS11CryptoKey::ClonePublic(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElPKCS11CryptoKey_ClonePublic(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElPKCS11CryptoKey::ClearPublic()
{
	SBCheckError(TElPKCS11CryptoKey_ClearPublic(_Handle));
}

SB_INLINE void TElPKCS11CryptoKey::ClearSecret()
{
	SBCheckError(TElPKCS11CryptoKey_ClearSecret(_Handle));
}

void TElPKCS11CryptoKey::GetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11CryptoKey_GetKeyProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Default), (int32_t)Default.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1917289127, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11CryptoKey::SetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11CryptoKey_SetKeyProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE void TElPKCS11CryptoKey::PrepareForEncryption(bool MultiUse)
{
	SBCheckError(TElPKCS11CryptoKey_PrepareForEncryption(_Handle, (int8_t)MultiUse));
}

SB_INLINE void TElPKCS11CryptoKey::PrepareForSigning(bool MultiUse)
{
	SBCheckError(TElPKCS11CryptoKey_PrepareForSigning(_Handle, (int8_t)MultiUse));
}

SB_INLINE void TElPKCS11CryptoKey::CancelPreparation()
{
	SBCheckError(TElPKCS11CryptoKey_CancelPreparation(_Handle));
}

bool TElPKCS11CryptoKey::AsyncOperationFinished()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11CryptoKey_AsyncOperationFinished(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
bool TElPKCS11CryptoKey::Equals(TElCustomCryptoKey &Source, bool PublicOnly, TElRelativeDistinguishedName &Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11CryptoKey_Equals(_Handle, Source.getHandle(), (int8_t)PublicOnly, Params.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS11CryptoKey::Equals(TElCustomCryptoKey *Source, bool PublicOnly, TElRelativeDistinguishedName *Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11CryptoKey_Equals(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (int8_t)PublicOnly, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElPKCS11CryptoKey::Persistentiate()
{
	SBCheckError(TElPKCS11CryptoKey_Persistentiate(_Handle));
}

TElPKCS11CryptoKey::TElPKCS11CryptoKey(TElPKCS11CryptoKeyHandle handle, TElOwnHandle ownHandle) : TElCustomCryptoKey(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElPKCS11CryptoKey::TElPKCS11CryptoKey(TElCustomCryptoProvider &CryptoProvider) : TElCustomCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11CryptoKey_Create(CryptoProvider.getHandle(), &_Handle));
}

TElPKCS11CryptoKey::TElPKCS11CryptoKey(TElCustomCryptoProvider *CryptoProvider) : TElCustomCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11CryptoKey_Create((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#endif /* SB_USE_CLASS_TELPKCS11CRYPTOKEY */

#ifdef SB_USE_CLASS_TELPKCS11CRYPTOCONTEXT

SB_INLINE int64_t TElPKCS11CryptoContext::EstimateOutputSize(int64_t InSize)
{
	int64_t OutResult;
	SBCheckError(TElPKCS11CryptoContext_EstimateOutputSize(_Handle, InSize, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElPKCS11CryptoContext::Clone(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElPKCS11CryptoContext_Clone(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElPKCS11CryptoContext::Clone(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElPKCS11CryptoContext_Clone(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

void TElPKCS11CryptoContext::GetContextProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS11CryptoContext_GetContextProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Default), (int32_t)Default.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(123350853, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS11CryptoContext::SetContextProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS11CryptoContext_SetContextProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElPKCS11CryptoContext::TElPKCS11CryptoContext(TElPKCS11CryptoContextHandle handle, TElOwnHandle ownHandle) : TElCustomCryptoContext(handle, ownHandle)
{
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME
TElPKCS11CryptoContext::TElPKCS11CryptoContext(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, TSBPKCS11CryptoContextOperation Operation, TElCustomCryptoProvider &Prov, TElRelativeDistinguishedName &Params) : TElCustomCryptoContext(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11CryptoContext_Create(Algorithm, Mode, Key.getHandle(), (TSBPKCS11CryptoContextOperationRaw)Operation, Prov.getHandle(), Params.getHandle(), &_Handle));
}

TElPKCS11CryptoContext::TElPKCS11CryptoContext(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, TSBPKCS11CryptoContextOperation Operation, TElCustomCryptoProvider *Prov, TElRelativeDistinguishedName *Params) : TElCustomCryptoContext(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11CryptoContext_Create(Algorithm, Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (TSBPKCS11CryptoContextOperationRaw)Operation, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME
TElPKCS11CryptoContext::TElPKCS11CryptoContext(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, TSBPKCS11CryptoContextOperation Operation, TElCustomCryptoProvider &Prov, TElRelativeDistinguishedName &Params) : TElCustomCryptoContext(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11CryptoContext_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, Key.getHandle(), (TSBPKCS11CryptoContextOperationRaw)Operation, Prov.getHandle(), Params.getHandle(), &_Handle));
}

TElPKCS11CryptoContext::TElPKCS11CryptoContext(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, TSBPKCS11CryptoContextOperation Operation, TElCustomCryptoProvider *Prov, TElRelativeDistinguishedName *Params) : TElCustomCryptoContext(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11CryptoContext_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (TSBPKCS11CryptoContextOperationRaw)Operation, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME */

#endif /* SB_USE_CLASS_TELPKCS11CRYPTOCONTEXT */

#ifdef SB_USE_CLASS_TELPKCS11ECPARAMSDIRECTORY

SB_INLINE void TElPKCS11ECParamsDirectory::AddKnownCurve(const std::string &Name, const std::vector<uint8_t> &CurveOID, int32_t KeyBits)
{
	SBCheckError(TElPKCS11ECParamsDirectory_AddKnownCurve(_Handle, Name.data(), (int32_t)Name.length(), SB_STD_VECTOR_FRONT_ADR(CurveOID), (int32_t)CurveOID.size(), KeyBits));
}

SB_INLINE int32_t TElPKCS11ECParamsDirectory::GetKeyBits(const std::vector<uint8_t> &CurveOID)
{
	int32_t OutResult;
	SBCheckError(TElPKCS11ECParamsDirectory_GetKeyBits(_Handle, SB_STD_VECTOR_FRONT_ADR(CurveOID), (int32_t)CurveOID.size(), &OutResult));
	return OutResult;
}

bool TElPKCS11ECParamsDirectory::IsKnownCurve(const std::vector<uint8_t> &CurveOID)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS11ECParamsDirectory_IsKnownCurve(_Handle, SB_STD_VECTOR_FRONT_ADR(CurveOID), (int32_t)CurveOID.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

TElPKCS11ECParamsDirectory::TElPKCS11ECParamsDirectory(TElPKCS11ECParamsDirectoryHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPKCS11ECParamsDirectory::TElPKCS11ECParamsDirectory() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS11ECParamsDirectory_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPKCS11ECPARAMSDIRECTORY */

#ifdef SB_USE_GLOBAL_PROCS_CRYPTOPROVPKCS11

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
SB_INLINE TElCustomCryptoProviderHandle PKCS11CryptoProvider()
{
	TElCustomCryptoProviderHandle OutResult;
	SBCheckError(SBCryptoProvPKCS11_PKCS11CryptoProvider(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#endif /* SB_USE_GLOBAL_PROCS_CRYPTOPROVPKCS11 */

};	/* namespace SecureBlackbox */
