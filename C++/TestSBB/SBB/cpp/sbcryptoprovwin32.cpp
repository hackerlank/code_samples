#include "sbdefs.h"
#ifdef SB_WINDOWS
#include "sbcryptoprovwin32.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELWIN32CRYPTOPROVIDEROPTIONS

SB_INLINE void TElWin32CryptoProviderOptions::Assign(TElCustomCryptoProviderOptions &Options)
{
	SBCheckError(TElWin32CryptoProviderOptions_Assign(_Handle, Options.getHandle()));
}

SB_INLINE void TElWin32CryptoProviderOptions::Assign(TElCustomCryptoProviderOptions *Options)
{
	SBCheckError(TElWin32CryptoProviderOptions_Assign(_Handle, (Options != NULL) ? Options->getHandle() : SB_NULL_HANDLE));
}

bool TElWin32CryptoProviderOptions::get_UseForPublicKeyOperations()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_UseForPublicKeyOperations(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_UseForPublicKeyOperations(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_UseForPublicKeyOperations(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_UseForSymmetricKeyOperations()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_UseForSymmetricKeyOperations(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_UseForSymmetricKeyOperations(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_UseForSymmetricKeyOperations(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_UseForHashingOperations()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_UseForHashingOperations(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_UseForHashingOperations(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_UseForHashingOperations(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_UseForNonPrivateOperations()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_UseForNonPrivateOperations(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_UseForNonPrivateOperations(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_UseForNonPrivateOperations(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_ThreadSafe()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_ThreadSafe(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_ThreadSafe(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_ThreadSafe(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_UseBaseCSP()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_UseBaseCSP(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_UseBaseCSP(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_UseBaseCSP(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_UseStrongCSP()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_UseStrongCSP(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_UseStrongCSP(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_UseStrongCSP(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_UseEnhancedCSP()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_UseEnhancedCSP(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_UseEnhancedCSP(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_UseEnhancedCSP(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_UseAESCSP()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_UseAESCSP(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_UseAESCSP(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_UseAESCSP(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_UseDSSCSP()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_UseDSSCSP(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_UseDSSCSP(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_UseDSSCSP(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_UseBaseDSSDHCSP()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_UseBaseDSSDHCSP(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_UseBaseDSSDHCSP(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_UseBaseDSSDHCSP(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_UseEnhancedDSSDHCSP()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_UseEnhancedDSSDHCSP(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_UseEnhancedDSSDHCSP(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_UseEnhancedDSSDHCSP(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_UseRSASchannelCSP()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_UseRSASchannelCSP(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_UseRSASchannelCSP(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_UseRSASchannelCSP(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_UseRSASignatureCSP()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_UseRSASignatureCSP(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_UseRSASignatureCSP(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_UseRSASignatureCSP(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_UseECDSASigCSP()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_UseECDSASigCSP(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_UseECDSASigCSP(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_UseECDSASigCSP(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_UseECNRASigCSP()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_UseECNRASigCSP(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_UseECNRASigCSP(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_UseECNRASigCSP(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_UseECDSAFullCSP()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_UseECDSAFullCSP(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_UseECDSAFullCSP(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_UseECDSAFullCSP(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_UseECNRAFullCSP()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_UseECNRAFullCSP(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_UseECNRAFullCSP(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_UseECNRAFullCSP(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_UseDHSchannelCSP()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_UseDHSchannelCSP(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_UseDHSchannelCSP(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_UseDHSchannelCSP(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_UseCPGOST()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_UseCPGOST(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_UseCPGOST(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_UseCPGOST(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_UseCNGProvider()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_UseCNGProvider(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_UseCNGProvider(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_UseCNGProvider(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_FIPSMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_FIPSMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_FIPSMode(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_FIPSMode(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_CacheKeyContexts()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_CacheKeyContexts(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_CacheKeyContexts(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_CacheKeyContexts(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_StorePublicKeysInMemoryContainers()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_StorePublicKeysInMemoryContainers(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_StorePublicKeysInMemoryContainers(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_StorePublicKeysInMemoryContainers(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_ForceEnhancedCSPForLongKeys()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_ForceEnhancedCSPForLongKeys(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_ForceEnhancedCSPForLongKeys(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_ForceEnhancedCSPForLongKeys(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_AutoSelectEnhancedCSP()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_AutoSelectEnhancedCSP(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_AutoSelectEnhancedCSP(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_AutoSelectEnhancedCSP(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_TryAlternativeKeySpecOnFailure()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_TryAlternativeKeySpecOnFailure(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_TryAlternativeKeySpecOnFailure(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_TryAlternativeKeySpecOnFailure(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_GenerateExportablePrivateKeys()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_GenerateExportablePrivateKeys(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_GenerateExportablePrivateKeys(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_GenerateExportablePrivateKeys(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProviderOptions::get_UseLocalMachineAccount()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProviderOptions_get_UseLocalMachineAccount(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProviderOptions::set_UseLocalMachineAccount(bool Value)
{
	SBCheckError(TElWin32CryptoProviderOptions_set_UseLocalMachineAccount(_Handle, (int8_t)Value));
}

TElWin32CryptoProviderOptions::TElWin32CryptoProviderOptions(TElWin32CryptoProviderOptionsHandle handle, TElOwnHandle ownHandle) : TElCustomCryptoProviderOptions(handle, ownHandle)
{
}

TElWin32CryptoProviderOptions::TElWin32CryptoProviderOptions() : TElCustomCryptoProviderOptions(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWin32CryptoProviderOptions_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELWIN32CRYPTOPROVIDEROPTIONS */

#ifdef SB_USE_CLASS_TELWIN32CRYPTOPROVIDER

SB_INLINE void TElWin32CryptoProvider::Init()
{
	SBCheckError(TElWin32CryptoProvider_Init(_Handle));
}

SB_INLINE void TElWin32CryptoProvider::Deinit()
{
	SBCheckError(TElWin32CryptoProvider_Deinit(_Handle));
}

SB_INLINE void TElWin32CryptoProvider::SetAsDefault()
{
	SBCheckError(TElWin32CryptoProvider_SetAsDefault());
}

SB_INLINE void TElWin32CryptoProvider::SetAsDefault_Inst()
{
	SBCheckError(TElWin32CryptoProvider_SetAsDefault_1(_Handle));
}

bool TElWin32CryptoProvider::IsAlgorithmSupported(int32_t Algorithm, int32_t Mode)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProvider_IsAlgorithmSupported(_Handle, Algorithm, Mode, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWin32CryptoProvider::IsAlgorithmSupported(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProvider_IsAlgorithmSupported_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
bool TElWin32CryptoProvider::IsOperationSupported(int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProvider_IsOperationSupported(_Handle, Operation, Algorithm, Mode, Key.getHandle(), Params.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWin32CryptoProvider::IsOperationSupported(int32_t Operation, int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProvider_IsOperationSupported(_Handle, Operation, Algorithm, Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
bool TElWin32CryptoProvider::IsOperationSupported(int32_t Operation, const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProvider_IsOperationSupported_1(_Handle, Operation, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, Key.getHandle(), Params.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWin32CryptoProvider::IsOperationSupported(int32_t Operation, const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProvider_IsOperationSupported_1(_Handle, Operation, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

void TElWin32CryptoProvider::GetAlgorithmProperty(int32_t Algorithm, int32_t Mode, const std::vector<uint8_t> &PropID, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElWin32CryptoProvider_GetAlgorithmProperty(_Handle, Algorithm, Mode, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1786601234, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWin32CryptoProvider::GetAlgorithmProperty(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, const std::vector<uint8_t> &PropID, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElWin32CryptoProvider_GetAlgorithmProperty_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1265803293, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElWin32CryptoProvider::GetAlgorithmClass(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(TElWin32CryptoProvider_GetAlgorithmClass(_Handle, Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElWin32CryptoProvider::GetAlgorithmClass(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams)
{
	int32_t OutResult;
	SBCheckError(TElWin32CryptoProvider_GetAlgorithmClass_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoProviderHandle TElWin32CryptoProvider::GetDefaultInstance()
{
	TElCustomCryptoProviderHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_GetDefaultInstance(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElWin32CryptoProvider::CreateKey(int32_t Algorithm, int32_t Mode, TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_CreateKey(_Handle, Algorithm, Mode, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElWin32CryptoProvider::CreateKey(int32_t Algorithm, int32_t Mode, TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_CreateKey(_Handle, Algorithm, Mode, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElWin32CryptoProvider::CreateKey(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_CreateKey_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElWin32CryptoProvider::CreateKey(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_CreateKey_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
SB_INLINE TElCustomCryptoKeyHandle TElWin32CryptoProvider::CloneKey(TElCustomCryptoKey &Key)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_CloneKey(_Handle, Key.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElWin32CryptoProvider::CloneKey(TElCustomCryptoKey *Key)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_CloneKey(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
void TElWin32CryptoProvider::ReleaseKey(TElCustomCryptoKey &Key)
{
	TElClassHandle hKey = Key.getHandle();
	SBCheckError(TElWin32CryptoProvider_ReleaseKey(_Handle, &hKey));
	Key.updateHandle(hKey);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
void TElWin32CryptoProvider::DeleteKey(TElCustomCryptoKey &Key)
{
	TElClassHandle hKey = Key.getHandle();
	SBCheckError(TElWin32CryptoProvider_DeleteKey(_Handle, &hKey));
	Key.updateHandle(hKey);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElWin32CryptoProvider::DecryptKey(void * EncKey, int32_t EncKeySize, const std::vector<uint8_t> &EncKeyAlgOID, const std::vector<uint8_t> &EncKeyAlgParams, TElCustomCryptoKey &Key, const std::vector<uint8_t> &KeyAlgOID, const std::vector<uint8_t> &KeyAlgParams, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_DecryptKey(_Handle, EncKey, EncKeySize, SB_STD_VECTOR_FRONT_ADR(EncKeyAlgOID), (int32_t)EncKeyAlgOID.size(), SB_STD_VECTOR_FRONT_ADR(EncKeyAlgParams), (int32_t)EncKeyAlgParams.size(), Key.getHandle(), SB_STD_VECTOR_FRONT_ADR(KeyAlgOID), (int32_t)KeyAlgOID.size(), SB_STD_VECTOR_FRONT_ADR(KeyAlgParams), (int32_t)KeyAlgParams.size(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElWin32CryptoProvider::DecryptKey(void * EncKey, int32_t EncKeySize, const std::vector<uint8_t> &EncKeyAlgOID, const std::vector<uint8_t> &EncKeyAlgParams, TElCustomCryptoKey *Key, const std::vector<uint8_t> &KeyAlgOID, const std::vector<uint8_t> &KeyAlgParams, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_DecryptKey(_Handle, EncKey, EncKeySize, SB_STD_VECTOR_FRONT_ADR(EncKeyAlgOID), (int32_t)EncKeyAlgOID.size(), SB_STD_VECTOR_FRONT_ADR(EncKeyAlgParams), (int32_t)EncKeyAlgParams.size(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(KeyAlgOID), (int32_t)KeyAlgOID.size(), SB_STD_VECTOR_FRONT_ADR(KeyAlgParams), (int32_t)KeyAlgParams.size(), (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElWin32CryptoProvider::EncryptInit(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_EncryptInit(_Handle, Algorithm, Mode, Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElWin32CryptoProvider::EncryptInit(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_EncryptInit(_Handle, Algorithm, Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElWin32CryptoProvider::EncryptInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_EncryptInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElWin32CryptoProvider::EncryptInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_EncryptInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElWin32CryptoProvider::DecryptInit(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_DecryptInit(_Handle, Algorithm, Mode, Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElWin32CryptoProvider::DecryptInit(int32_t Algorithm, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_DecryptInit(_Handle, Algorithm, Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElWin32CryptoProvider::DecryptInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_DecryptInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElWin32CryptoProvider::DecryptInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t Mode, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_DecryptInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Mode, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElWin32CryptoProvider::SignInit(int32_t Algorithm, TElCustomCryptoKey &Key, bool Detached, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_SignInit(_Handle, Algorithm, Key.getHandle(), (int8_t)Detached, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElWin32CryptoProvider::SignInit(int32_t Algorithm, TElCustomCryptoKey *Key, bool Detached, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_SignInit(_Handle, Algorithm, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (int8_t)Detached, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElWin32CryptoProvider::SignInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, bool Detached, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_SignInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Key.getHandle(), (int8_t)Detached, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElWin32CryptoProvider::SignInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, bool Detached, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_SignInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (int8_t)Detached, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElWin32CryptoProvider::VerifyInit(int32_t Algorithm, TElCustomCryptoKey &Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_VerifyInit(_Handle, Algorithm, Key.getHandle(), SigBuffer, SigSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElWin32CryptoProvider::VerifyInit(int32_t Algorithm, TElCustomCryptoKey *Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_VerifyInit(_Handle, Algorithm, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, SigBuffer, SigSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElWin32CryptoProvider::VerifyInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_VerifyInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Key.getHandle(), SigBuffer, SigSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElWin32CryptoProvider::VerifyInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, void * SigBuffer, int32_t SigSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_VerifyInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, SigBuffer, SigSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElWin32CryptoProvider::EncryptUpdate(TElCustomCryptoContext &Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElWin32CryptoProvider_EncryptUpdate(_Handle, Context.getHandle(), InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElWin32CryptoProvider::EncryptUpdate(TElCustomCryptoContext *Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElWin32CryptoProvider_EncryptUpdate(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElWin32CryptoProvider::DecryptUpdate(TElCustomCryptoContext &Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElWin32CryptoProvider_DecryptUpdate(_Handle, Context.getHandle(), InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElWin32CryptoProvider::DecryptUpdate(TElCustomCryptoContext *Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElWin32CryptoProvider_DecryptUpdate(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElWin32CryptoProvider::SignUpdate(TElCustomCryptoContext &Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElWin32CryptoProvider_SignUpdate(_Handle, Context.getHandle(), InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElWin32CryptoProvider::SignUpdate(TElCustomCryptoContext *Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElWin32CryptoProvider_SignUpdate(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElWin32CryptoProvider::VerifyUpdate(TElCustomCryptoContext &Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElWin32CryptoProvider_VerifyUpdate(_Handle, Context.getHandle(), InBuffer, InSize, OutBuffer, &OutSize, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElWin32CryptoProvider::VerifyUpdate(TElCustomCryptoContext *Context, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElWin32CryptoProvider_VerifyUpdate(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, InBuffer, InSize, OutBuffer, &OutSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElWin32CryptoProvider::EncryptFinal(TElCustomCryptoContext &Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElWin32CryptoProvider_EncryptFinal(_Handle, Context.getHandle(), Buffer, &Size, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElWin32CryptoProvider::EncryptFinal(TElCustomCryptoContext *Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElWin32CryptoProvider_EncryptFinal(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElWin32CryptoProvider::DecryptFinal(TElCustomCryptoContext &Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElWin32CryptoProvider_DecryptFinal(_Handle, Context.getHandle(), Buffer, &Size, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElWin32CryptoProvider::DecryptFinal(TElCustomCryptoContext *Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElWin32CryptoProvider_DecryptFinal(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElWin32CryptoProvider::SignFinal(TElCustomCryptoContext &Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElWin32CryptoProvider_SignFinal(_Handle, Context.getHandle(), Buffer, &Size, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElWin32CryptoProvider::SignFinal(TElCustomCryptoContext *Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElWin32CryptoProvider_SignFinal(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE int32_t TElWin32CryptoProvider::VerifyFinal(TElCustomCryptoContext &Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	int32_t OutResult;
	SBCheckError(TElWin32CryptoProvider_VerifyFinal(_Handle, Context.getHandle(), Buffer, &Size, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElWin32CryptoProvider::VerifyFinal(TElCustomCryptoContext *Context, void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	int32_t OutResult;
	SBCheckError(TElWin32CryptoProvider_VerifyFinal(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElWin32CryptoProvider::HashInit(int32_t Algorithm, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_HashInit(_Handle, Algorithm, Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElWin32CryptoProvider::HashInit(int32_t Algorithm, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_HashInit(_Handle, Algorithm, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoContextHandle TElWin32CryptoProvider::HashInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey &Key, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_HashInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), Key.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoContextHandle TElWin32CryptoProvider::HashInit(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, TElCustomCryptoKey *Key, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	TElCustomCryptoContextHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_HashInit_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElWin32CryptoProvider::HashUpdate(TElCustomCryptoContext &Context, void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElWin32CryptoProvider_HashUpdate(_Handle, Context.getHandle(), Buffer, Size, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElWin32CryptoProvider::HashUpdate(TElCustomCryptoContext *Context, void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElWin32CryptoProvider_HashUpdate(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME
void TElWin32CryptoProvider::HashFinal(TElCustomCryptoContext &Context, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElWin32CryptoProvider_HashFinal(_Handle, Context.getHandle(), Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-615541526, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWin32CryptoProvider::HashFinal(TElCustomCryptoContext *Context, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElWin32CryptoProvider_HashFinal(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-615541526, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOCONTEXT_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOCONTEXT
void TElWin32CryptoProvider::ReleaseCryptoContext(TElCustomCryptoContext &Context)
{
	TElClassHandle hContext = Context.getHandle();
	SBCheckError(TElWin32CryptoProvider_ReleaseCryptoContext(_Handle, &hContext));
	Context.updateHandle(hContext);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOCONTEXT */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEYSTORAGE_AND_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyStorageHandle TElWin32CryptoProvider::CreateKeyStorage(bool Persistent, TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyStorageHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_CreateKeyStorage(_Handle, (int8_t)Persistent, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyStorageHandle TElWin32CryptoProvider::CreateKeyStorage(bool Persistent, TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyStorageHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_CreateKeyStorage(_Handle, (int8_t)Persistent, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEYSTORAGE_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE
void TElWin32CryptoProvider::ReleaseKeyStorage(TElCustomCryptoKeyStorage &KeyStorage)
{
	TElClassHandle hKeyStorage = KeyStorage.getHandle();
	SBCheckError(TElWin32CryptoProvider_ReleaseKeyStorage(_Handle, &hKeyStorage));
	KeyStorage.updateHandle(hKeyStorage);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE
void TElWin32CryptoProvider::DeleteKeyStorage(TElCustomCryptoKeyStorage &KeyStorage)
{
	TElClassHandle hKeyStorage = KeyStorage.getHandle();
	SBCheckError(TElWin32CryptoProvider_DeleteKeyStorage(_Handle, &hKeyStorage));
	KeyStorage.updateHandle(hKeyStorage);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEYSTORAGE */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElWin32CryptoProvider::RandomInit(void * BaseData, int32_t BaseDataSize, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElWin32CryptoProvider_RandomInit(_Handle, BaseData, BaseDataSize, Params.getHandle()));
}

SB_INLINE void TElWin32CryptoProvider::RandomInit(void * BaseData, int32_t BaseDataSize, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElWin32CryptoProvider_RandomInit(_Handle, BaseData, BaseDataSize, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElWin32CryptoProvider::RandomSeed(void * Data, int32_t DataSize)
{
	SBCheckError(TElWin32CryptoProvider_RandomSeed(_Handle, Data, DataSize));
}

SB_INLINE void TElWin32CryptoProvider::RandomGenerate(void * Buffer, int32_t Size)
{
	SBCheckError(TElWin32CryptoProvider_RandomGenerate(_Handle, Buffer, Size));
}

SB_INLINE int32_t TElWin32CryptoProvider::RandomGenerate(int32_t MaxValue)
{
	int32_t OutResult;
	SBCheckError(TElWin32CryptoProvider_RandomGenerate_1(_Handle, MaxValue, &OutResult));
	return OutResult;
}

void TElWin32CryptoProvider::GetProviderProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElWin32CryptoProvider_GetProviderProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Default), (int32_t)Default.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1365357043, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWin32CryptoProvider::SetProviderProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElWin32CryptoProvider_SetProviderProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE TClassHandle TElWin32CryptoProvider::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElWin32CryptoProvider_ClassType(&OutResult));
	return OutResult;
}

bool TElWin32CryptoProvider::get_TryEnhancedCryptoProvider()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProvider_get_TryEnhancedCryptoProvider(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProvider::set_TryEnhancedCryptoProvider(bool Value)
{
	SBCheckError(TElWin32CryptoProvider_set_TryEnhancedCryptoProvider(_Handle, (int8_t)Value));
}

bool TElWin32CryptoProvider::get_NativeSizeCalculation()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWin32CryptoProvider_get_NativeSizeCalculation(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWin32CryptoProvider::set_NativeSizeCalculation(bool Value)
{
	SBCheckError(TElWin32CryptoProvider_set_NativeSizeCalculation(_Handle, (int8_t)Value));
}

TElWin32CryptoProvider::TElWin32CryptoProvider(TElWin32CryptoProviderHandle handle, TElOwnHandle ownHandle) : TElExternalCryptoProvider(handle, ownHandle)
{
}

TElWin32CryptoProvider::TElWin32CryptoProvider(TComponent &AOwner) : TElExternalCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWin32CryptoProvider_Create(AOwner.getHandle(), &_Handle));
}

TElWin32CryptoProvider::TElWin32CryptoProvider(TComponent *AOwner) : TElExternalCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWin32CryptoProvider_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS
TElWin32CryptoProvider::TElWin32CryptoProvider(TElCustomCryptoProviderOptions &Options, TComponent &AOwner) : TElExternalCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWin32CryptoProvider_Create_1(Options.getHandle(), AOwner.getHandle(), &_Handle));
}

TElWin32CryptoProvider::TElWin32CryptoProvider(TElCustomCryptoProviderOptions *Options, TComponent *AOwner) : TElExternalCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWin32CryptoProvider_Create_1((Options != NULL) ? Options->getHandle() : SB_NULL_HANDLE, (AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS */

#endif /* SB_USE_CLASS_TELWIN32CRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCNGCRYPTOPROVIDERHANDLEINFO

TElCNGCryptoProviderHandleInfo::TElCNGCryptoProviderHandleInfo(TElCNGCryptoProviderHandleInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElCNGCryptoProviderHandleInfo::TElCNGCryptoProviderHandleInfo(uint32_t * Handle) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCNGCryptoProviderHandleInfo_Create(Handle, &_Handle));
}

#endif /* SB_USE_CLASS_TELCNGCRYPTOPROVIDERHANDLEINFO */

#ifdef SB_USE_CLASS_TELCNGCRYPTOPROVIDERHANDLEMANAGER

#ifndef CPU64
SB_INLINE uint32_t TElCNGCryptoProviderHandleManager::OpenCNGStorageProvider(uint32_t &phProvider, sb_char16_t * pszProviderName, uint32_t dwFlags)
#else
SB_INLINE uint32_t TElCNGCryptoProviderHandleManager::OpenCNGStorageProvider(int64_t &phProvider, sb_char16_t * pszProviderName, uint32_t dwFlags)
#endif
{
	uint32_t OutResult;
	SBCheckError(TElCNGCryptoProviderHandleManager_OpenCNGStorageProvider(_Handle, &phProvider, pszProviderName, dwFlags, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t TElCNGCryptoProviderHandleManager::OpenCNGStorageProvider(uint32_t * &phProvider, sb_char16_t * pszProviderName, uint32_t dwFlags)
{
	uint32_t OutResult;
	SBCheckError(TElCNGCryptoProviderHandleManager_OpenCNGStorageProvider_1(_Handle, &phProvider, pszProviderName, dwFlags, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE void TElCNGCryptoProviderHandleManager::FreeCNGStorageProvider(uint32_t hProvider)
#else
SB_INLINE void TElCNGCryptoProviderHandleManager::FreeCNGStorageProvider(int64_t hProvider)
#endif
{
	SBCheckError(TElCNGCryptoProviderHandleManager_FreeCNGStorageProvider(_Handle, hProvider));
}

#ifndef CPU64
SB_INLINE void TElCNGCryptoProviderHandleManager::CNGStorageProviderAddRef(uint32_t hProvider)
#else
SB_INLINE void TElCNGCryptoProviderHandleManager::CNGStorageProviderAddRef(int64_t hProvider)
#endif
{
	SBCheckError(TElCNGCryptoProviderHandleManager_CNGStorageProviderAddRef(_Handle, hProvider));
}

TElCNGCryptoProviderHandleManager::TElCNGCryptoProviderHandleManager(TElCNGCryptoProviderHandleManagerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElCNGCryptoProviderHandleManager::TElCNGCryptoProviderHandleManager() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCNGCryptoProviderHandleManager_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCNGCRYPTOPROVIDERHANDLEMANAGER */

#ifdef SB_USE_GLOBAL_PROCS_CRYPTOPROVWIN32

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
SB_INLINE TElCustomCryptoProviderHandle Win32CryptoProvider()
{
	TElCustomCryptoProviderHandle OutResult;
	SBCheckError(SBCryptoProvWin32_Win32CryptoProvider(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELWIN32CRYPTOPROVIDEROPTIONS
SB_INLINE TElCustomCryptoProviderHandle Win32CryptoProvider(TElWin32CryptoProviderOptions &OptionsTemplate)
{
	TElCustomCryptoProviderHandle OutResult;
	SBCheckError(SBCryptoProvWin32_Win32CryptoProvider_1(OptionsTemplate.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE TElCustomCryptoProviderHandle Win32CryptoProvider(TElWin32CryptoProviderOptions *OptionsTemplate)
{
	TElCustomCryptoProviderHandle OutResult;
	SBCheckError(SBCryptoProvWin32_Win32CryptoProvider_1((OptionsTemplate != NULL) ? OptionsTemplate->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELWIN32CRYPTOPROVIDEROPTIONS */

#endif /* SB_USE_GLOBAL_PROCS_CRYPTOPROVWIN32 */

};	/* namespace SecureBlackbox */
#endif
