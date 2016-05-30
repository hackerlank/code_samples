#include "sbcryptoprovbuiltinpki.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELBUILTINRSACRYPTOKEY

SB_INLINE void TElBuiltInRSACryptoKey::Reset()
{
	SBCheckError(TElBuiltInRSACryptoKey_Reset(_Handle));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInRSACryptoKey::Generate(int32_t Bits, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInRSACryptoKey_Generate(_Handle, Bits, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElBuiltInRSACryptoKey::Generate(int32_t Bits, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInRSACryptoKey_Generate(_Handle, Bits, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInRSACryptoKey::ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInRSACryptoKey_ImportPublic(_Handle, Buffer, Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInRSACryptoKey::ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInRSACryptoKey_ImportPublic(_Handle, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInRSACryptoKey::ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInRSACryptoKey_ImportSecret(_Handle, Buffer, Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInRSACryptoKey::ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInRSACryptoKey_ImportSecret(_Handle, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInRSACryptoKey::ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInRSACryptoKey_ExportPublic(_Handle, Buffer, &Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInRSACryptoKey::ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInRSACryptoKey_ExportPublic(_Handle, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInRSACryptoKey::ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInRSACryptoKey_ExportSecret(_Handle, Buffer, &Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInRSACryptoKey::ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInRSACryptoKey_ExportSecret(_Handle, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElBuiltInRSACryptoKey::Clone(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInRSACryptoKey_Clone(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElBuiltInRSACryptoKey::Clone(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInRSACryptoKey_Clone(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElBuiltInRSACryptoKey::ClonePublic(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInRSACryptoKey_ClonePublic(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElBuiltInRSACryptoKey::ClonePublic(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInRSACryptoKey_ClonePublic(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElBuiltInRSACryptoKey::ClearPublic()
{
	SBCheckError(TElBuiltInRSACryptoKey_ClearPublic(_Handle));
}

SB_INLINE void TElBuiltInRSACryptoKey::ClearSecret()
{
	SBCheckError(TElBuiltInRSACryptoKey_ClearSecret(_Handle));
}

void TElBuiltInRSACryptoKey::GetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBuiltInRSACryptoKey_GetKeyProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Default), (int32_t)Default.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1628967646, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBuiltInRSACryptoKey::SetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBuiltInRSACryptoKey_SetKeyProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
bool TElBuiltInRSACryptoKey::Equals(TElCustomCryptoKey &Source, bool PublicOnly, TElRelativeDistinguishedName &Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInRSACryptoKey_Equals(_Handle, Source.getHandle(), (int8_t)PublicOnly, Params.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBuiltInRSACryptoKey::Equals(TElCustomCryptoKey *Source, bool PublicOnly, TElRelativeDistinguishedName *Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInRSACryptoKey_Equals(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (int8_t)PublicOnly, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

TElBuiltInRSACryptoKey::TElBuiltInRSACryptoKey(TElBuiltInRSACryptoKeyHandle handle, TElOwnHandle ownHandle) : TElBuiltInCryptoKey(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElBuiltInRSACryptoKey::TElBuiltInRSACryptoKey(TElCustomCryptoProvider &CryptoProvider) : TElBuiltInCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInRSACryptoKey_Create(CryptoProvider.getHandle(), &_Handle));
}

TElBuiltInRSACryptoKey::TElBuiltInRSACryptoKey(TElCustomCryptoProvider *CryptoProvider) : TElBuiltInCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInRSACryptoKey_Create((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#endif /* SB_USE_CLASS_TELBUILTINRSACRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINDSACRYPTOKEY

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInDSACryptoKey::Generate(int32_t Bits, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInDSACryptoKey_Generate(_Handle, Bits, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElBuiltInDSACryptoKey::Generate(int32_t Bits, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInDSACryptoKey_Generate(_Handle, Bits, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElBuiltInDSACryptoKey::Reset()
{
	SBCheckError(TElBuiltInDSACryptoKey_Reset(_Handle));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInDSACryptoKey::ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInDSACryptoKey_ImportPublic(_Handle, Buffer, Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInDSACryptoKey::ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInDSACryptoKey_ImportPublic(_Handle, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInDSACryptoKey::ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInDSACryptoKey_ImportSecret(_Handle, Buffer, Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInDSACryptoKey::ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInDSACryptoKey_ImportSecret(_Handle, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInDSACryptoKey::ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInDSACryptoKey_ExportPublic(_Handle, Buffer, &Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInDSACryptoKey::ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInDSACryptoKey_ExportPublic(_Handle, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInDSACryptoKey::ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInDSACryptoKey_ExportSecret(_Handle, Buffer, &Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInDSACryptoKey::ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInDSACryptoKey_ExportSecret(_Handle, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElBuiltInDSACryptoKey::Clone(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInDSACryptoKey_Clone(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElBuiltInDSACryptoKey::Clone(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInDSACryptoKey_Clone(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElBuiltInDSACryptoKey::ClonePublic(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInDSACryptoKey_ClonePublic(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElBuiltInDSACryptoKey::ClonePublic(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInDSACryptoKey_ClonePublic(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElBuiltInDSACryptoKey::ClearPublic()
{
	SBCheckError(TElBuiltInDSACryptoKey_ClearPublic(_Handle));
}

SB_INLINE void TElBuiltInDSACryptoKey::ClearSecret()
{
	SBCheckError(TElBuiltInDSACryptoKey_ClearSecret(_Handle));
}

void TElBuiltInDSACryptoKey::GetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBuiltInDSACryptoKey_GetKeyProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Default), (int32_t)Default.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(404945405, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBuiltInDSACryptoKey::SetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBuiltInDSACryptoKey_SetKeyProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE void TElBuiltInDSACryptoKey::PrepareForSigning(bool MultiUse)
{
	SBCheckError(TElBuiltInDSACryptoKey_PrepareForSigning(_Handle, (int8_t)MultiUse));
}

SB_INLINE void TElBuiltInDSACryptoKey::CancelPreparation()
{
	SBCheckError(TElBuiltInDSACryptoKey_CancelPreparation(_Handle));
}

bool TElBuiltInDSACryptoKey::AsyncOperationFinished()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInDSACryptoKey_AsyncOperationFinished(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
bool TElBuiltInDSACryptoKey::Equals(TElCustomCryptoKey &Source, bool PublicOnly, TElRelativeDistinguishedName &Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInDSACryptoKey_Equals(_Handle, Source.getHandle(), (int8_t)PublicOnly, Params.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBuiltInDSACryptoKey::Equals(TElCustomCryptoKey *Source, bool PublicOnly, TElRelativeDistinguishedName *Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInDSACryptoKey_Equals(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (int8_t)PublicOnly, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

TElBuiltInDSACryptoKey::TElBuiltInDSACryptoKey(TElBuiltInDSACryptoKeyHandle handle, TElOwnHandle ownHandle) : TElBuiltInCryptoKey(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElBuiltInDSACryptoKey::TElBuiltInDSACryptoKey(TElCustomCryptoProvider &CryptoProvider) : TElBuiltInCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInDSACryptoKey_Create(CryptoProvider.getHandle(), &_Handle));
}

TElBuiltInDSACryptoKey::TElBuiltInDSACryptoKey(TElCustomCryptoProvider *CryptoProvider) : TElBuiltInCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInDSACryptoKey_Create((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#endif /* SB_USE_CLASS_TELBUILTINDSACRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINELGAMALCRYPTOKEY

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInElgamalCryptoKey::Generate(int32_t Bits, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInElgamalCryptoKey_Generate(_Handle, Bits, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElBuiltInElgamalCryptoKey::Generate(int32_t Bits, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInElgamalCryptoKey_Generate(_Handle, Bits, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElBuiltInElgamalCryptoKey::Reset()
{
	SBCheckError(TElBuiltInElgamalCryptoKey_Reset(_Handle));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInElgamalCryptoKey::ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInElgamalCryptoKey_ImportPublic(_Handle, Buffer, Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInElgamalCryptoKey::ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInElgamalCryptoKey_ImportPublic(_Handle, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInElgamalCryptoKey::ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInElgamalCryptoKey_ImportSecret(_Handle, Buffer, Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInElgamalCryptoKey::ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInElgamalCryptoKey_ImportSecret(_Handle, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInElgamalCryptoKey::ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInElgamalCryptoKey_ExportPublic(_Handle, Buffer, &Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInElgamalCryptoKey::ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInElgamalCryptoKey_ExportPublic(_Handle, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInElgamalCryptoKey::ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInElgamalCryptoKey_ExportSecret(_Handle, Buffer, &Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInElgamalCryptoKey::ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInElgamalCryptoKey_ExportSecret(_Handle, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElBuiltInElgamalCryptoKey::Clone(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInElgamalCryptoKey_Clone(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElBuiltInElgamalCryptoKey::Clone(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInElgamalCryptoKey_Clone(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElBuiltInElgamalCryptoKey::ClonePublic(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInElgamalCryptoKey_ClonePublic(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElBuiltInElgamalCryptoKey::ClonePublic(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInElgamalCryptoKey_ClonePublic(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElBuiltInElgamalCryptoKey::ClearPublic()
{
	SBCheckError(TElBuiltInElgamalCryptoKey_ClearPublic(_Handle));
}

SB_INLINE void TElBuiltInElgamalCryptoKey::ClearSecret()
{
	SBCheckError(TElBuiltInElgamalCryptoKey_ClearSecret(_Handle));
}

void TElBuiltInElgamalCryptoKey::GetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBuiltInElgamalCryptoKey_GetKeyProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Default), (int32_t)Default.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-525961690, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBuiltInElgamalCryptoKey::SetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBuiltInElgamalCryptoKey_SetKeyProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE void TElBuiltInElgamalCryptoKey::PrepareForEncryption(bool MultiUse)
{
	SBCheckError(TElBuiltInElgamalCryptoKey_PrepareForEncryption(_Handle, (int8_t)MultiUse));
}

SB_INLINE void TElBuiltInElgamalCryptoKey::PrepareForSigning(bool MultiUse)
{
	SBCheckError(TElBuiltInElgamalCryptoKey_PrepareForSigning(_Handle, (int8_t)MultiUse));
}

SB_INLINE void TElBuiltInElgamalCryptoKey::CancelPreparation()
{
	SBCheckError(TElBuiltInElgamalCryptoKey_CancelPreparation(_Handle));
}

bool TElBuiltInElgamalCryptoKey::AsyncOperationFinished()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInElgamalCryptoKey_AsyncOperationFinished(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
bool TElBuiltInElgamalCryptoKey::Equals(TElCustomCryptoKey &Source, bool PublicOnly, TElRelativeDistinguishedName &Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInElgamalCryptoKey_Equals(_Handle, Source.getHandle(), (int8_t)PublicOnly, Params.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBuiltInElgamalCryptoKey::Equals(TElCustomCryptoKey *Source, bool PublicOnly, TElRelativeDistinguishedName *Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInElgamalCryptoKey_Equals(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (int8_t)PublicOnly, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

TElBuiltInElgamalCryptoKey::TElBuiltInElgamalCryptoKey(TElBuiltInElgamalCryptoKeyHandle handle, TElOwnHandle ownHandle) : TElBuiltInCryptoKey(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElBuiltInElgamalCryptoKey::TElBuiltInElgamalCryptoKey(TElCustomCryptoProvider &CryptoProvider) : TElBuiltInCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInElgamalCryptoKey_Create(CryptoProvider.getHandle(), &_Handle));
}

TElBuiltInElgamalCryptoKey::TElBuiltInElgamalCryptoKey(TElCustomCryptoProvider *CryptoProvider) : TElBuiltInCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInElgamalCryptoKey_Create((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#endif /* SB_USE_CLASS_TELBUILTINELGAMALCRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINDHCRYPTOKEY

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInDHCryptoKey::Generate(int32_t Bits, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInDHCryptoKey_Generate(_Handle, Bits, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElBuiltInDHCryptoKey::Generate(int32_t Bits, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInDHCryptoKey_Generate(_Handle, Bits, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElBuiltInDHCryptoKey::Reset()
{
	SBCheckError(TElBuiltInDHCryptoKey_Reset(_Handle));
}

SB_INLINE void TElBuiltInDHCryptoKey::ResetPartial()
{
	SBCheckError(TElBuiltInDHCryptoKey_ResetPartial(_Handle));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInDHCryptoKey::ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInDHCryptoKey_ImportPublic(_Handle, Buffer, Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInDHCryptoKey::ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInDHCryptoKey_ImportPublic(_Handle, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInDHCryptoKey::ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInDHCryptoKey_ImportSecret(_Handle, Buffer, Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInDHCryptoKey::ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInDHCryptoKey_ImportSecret(_Handle, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInDHCryptoKey::ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInDHCryptoKey_ExportPublic(_Handle, Buffer, &Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInDHCryptoKey::ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInDHCryptoKey_ExportPublic(_Handle, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInDHCryptoKey::ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInDHCryptoKey_ExportSecret(_Handle, Buffer, &Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInDHCryptoKey::ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInDHCryptoKey_ExportSecret(_Handle, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElBuiltInDHCryptoKey::Clone(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInDHCryptoKey_Clone(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElBuiltInDHCryptoKey::Clone(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInDHCryptoKey_Clone(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElBuiltInDHCryptoKey::ClonePublic(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInDHCryptoKey_ClonePublic(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElBuiltInDHCryptoKey::ClonePublic(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInDHCryptoKey_ClonePublic(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElBuiltInDHCryptoKey::ClearPublic()
{
	SBCheckError(TElBuiltInDHCryptoKey_ClearPublic(_Handle));
}

SB_INLINE void TElBuiltInDHCryptoKey::ClearSecret()
{
	SBCheckError(TElBuiltInDHCryptoKey_ClearSecret(_Handle));
}

void TElBuiltInDHCryptoKey::GetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBuiltInDHCryptoKey_GetKeyProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Default), (int32_t)Default.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1214199613, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBuiltInDHCryptoKey::SetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBuiltInDHCryptoKey_SetKeyProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
bool TElBuiltInDHCryptoKey::Equals(TElCustomCryptoKey &Source, bool PublicOnly, TElRelativeDistinguishedName &Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInDHCryptoKey_Equals(_Handle, Source.getHandle(), (int8_t)PublicOnly, Params.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBuiltInDHCryptoKey::Equals(TElCustomCryptoKey *Source, bool PublicOnly, TElRelativeDistinguishedName *Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInDHCryptoKey_Equals(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (int8_t)PublicOnly, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

TElBuiltInDHCryptoKey::TElBuiltInDHCryptoKey(TElBuiltInDHCryptoKeyHandle handle, TElOwnHandle ownHandle) : TElBuiltInCryptoKey(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElBuiltInDHCryptoKey::TElBuiltInDHCryptoKey(TElCustomCryptoProvider &CryptoProvider) : TElBuiltInCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInDHCryptoKey_Create(CryptoProvider.getHandle(), &_Handle));
}

TElBuiltInDHCryptoKey::TElBuiltInDHCryptoKey(TElCustomCryptoProvider *CryptoProvider) : TElBuiltInCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInDHCryptoKey_Create((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#endif /* SB_USE_CLASS_TELBUILTINDHCRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINECCRYPTOKEY

SB_INLINE void TElBuiltInECCryptoKey::Reset()
{
	SBCheckError(TElBuiltInECCryptoKey_Reset(_Handle));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInECCryptoKey::Generate(int32_t Bits, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInECCryptoKey_Generate(_Handle, Bits, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElBuiltInECCryptoKey::Generate(int32_t Bits, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInECCryptoKey_Generate(_Handle, Bits, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInECCryptoKey::ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInECCryptoKey_ImportPublic(_Handle, Buffer, Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInECCryptoKey::ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInECCryptoKey_ImportPublic(_Handle, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInECCryptoKey::ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInECCryptoKey_ImportSecret(_Handle, Buffer, Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInECCryptoKey::ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInECCryptoKey_ImportSecret(_Handle, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInECCryptoKey::ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInECCryptoKey_ExportPublic(_Handle, Buffer, &Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInECCryptoKey::ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInECCryptoKey_ExportPublic(_Handle, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInECCryptoKey::ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInECCryptoKey_ExportSecret(_Handle, Buffer, &Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInECCryptoKey::ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInECCryptoKey_ExportSecret(_Handle, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElBuiltInECCryptoKey::Clone(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInECCryptoKey_Clone(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElBuiltInECCryptoKey::Clone(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInECCryptoKey_Clone(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElBuiltInECCryptoKey::ClonePublic(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInECCryptoKey_ClonePublic(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElBuiltInECCryptoKey::ClonePublic(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInECCryptoKey_ClonePublic(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElBuiltInECCryptoKey::ClearPublic()
{
	SBCheckError(TElBuiltInECCryptoKey_ClearPublic(_Handle));
}

SB_INLINE void TElBuiltInECCryptoKey::ClearSecret()
{
	SBCheckError(TElBuiltInECCryptoKey_ClearSecret(_Handle));
}

void TElBuiltInECCryptoKey::GetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBuiltInECCryptoKey_GetKeyProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Default), (int32_t)Default.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(122383511, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBuiltInECCryptoKey::SetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBuiltInECCryptoKey_SetKeyProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElBuiltInECCryptoKey::AsyncOperationFinished()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInECCryptoKey_AsyncOperationFinished(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
bool TElBuiltInECCryptoKey::Equals(TElCustomCryptoKey &Source, bool PublicOnly, TElRelativeDistinguishedName &Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInECCryptoKey_Equals(_Handle, Source.getHandle(), (int8_t)PublicOnly, Params.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBuiltInECCryptoKey::Equals(TElCustomCryptoKey *Source, bool PublicOnly, TElRelativeDistinguishedName *Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInECCryptoKey_Equals(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (int8_t)PublicOnly, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

TElBuiltInECCryptoKey::TElBuiltInECCryptoKey(TElBuiltInECCryptoKeyHandle handle, TElOwnHandle ownHandle) : TElBuiltInCryptoKey(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElBuiltInECCryptoKey::TElBuiltInECCryptoKey(TElCustomCryptoProvider &CryptoProvider) : TElBuiltInCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInECCryptoKey_Create(CryptoProvider.getHandle(), &_Handle));
}

TElBuiltInECCryptoKey::TElBuiltInECCryptoKey(TElCustomCryptoProvider *CryptoProvider) : TElBuiltInCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInECCryptoKey_Create((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#endif /* SB_USE_CLASS_TELBUILTINECCRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINGOST341094CRYPTOKEY

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInGOST341094CryptoKey::Generate(int32_t Bits, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInGOST341094CryptoKey_Generate(_Handle, Bits, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElBuiltInGOST341094CryptoKey::Generate(int32_t Bits, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInGOST341094CryptoKey_Generate(_Handle, Bits, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElBuiltInGOST341094CryptoKey::Reset()
{
	SBCheckError(TElBuiltInGOST341094CryptoKey_Reset(_Handle));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInGOST341094CryptoKey::ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInGOST341094CryptoKey_ImportPublic(_Handle, Buffer, Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInGOST341094CryptoKey::ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInGOST341094CryptoKey_ImportPublic(_Handle, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInGOST341094CryptoKey::ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInGOST341094CryptoKey_ImportSecret(_Handle, Buffer, Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInGOST341094CryptoKey::ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInGOST341094CryptoKey_ImportSecret(_Handle, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInGOST341094CryptoKey::ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInGOST341094CryptoKey_ExportPublic(_Handle, Buffer, &Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInGOST341094CryptoKey::ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInGOST341094CryptoKey_ExportPublic(_Handle, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInGOST341094CryptoKey::ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInGOST341094CryptoKey_ExportSecret(_Handle, Buffer, &Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInGOST341094CryptoKey::ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInGOST341094CryptoKey_ExportSecret(_Handle, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElBuiltInGOST341094CryptoKey::Clone(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInGOST341094CryptoKey_Clone(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElBuiltInGOST341094CryptoKey::Clone(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInGOST341094CryptoKey_Clone(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElBuiltInGOST341094CryptoKey::ClonePublic(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInGOST341094CryptoKey_ClonePublic(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElBuiltInGOST341094CryptoKey::ClonePublic(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInGOST341094CryptoKey_ClonePublic(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElBuiltInGOST341094CryptoKey::ClearPublic()
{
	SBCheckError(TElBuiltInGOST341094CryptoKey_ClearPublic(_Handle));
}

SB_INLINE void TElBuiltInGOST341094CryptoKey::ClearSecret()
{
	SBCheckError(TElBuiltInGOST341094CryptoKey_ClearSecret(_Handle));
}

void TElBuiltInGOST341094CryptoKey::GetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBuiltInGOST341094CryptoKey_GetKeyProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Default), (int32_t)Default.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(827412210, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBuiltInGOST341094CryptoKey::SetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBuiltInGOST341094CryptoKey_SetKeyProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
bool TElBuiltInGOST341094CryptoKey::Equals(TElCustomCryptoKey &Source, bool PublicOnly, TElRelativeDistinguishedName &Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInGOST341094CryptoKey_Equals(_Handle, Source.getHandle(), (int8_t)PublicOnly, Params.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBuiltInGOST341094CryptoKey::Equals(TElCustomCryptoKey *Source, bool PublicOnly, TElRelativeDistinguishedName *Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInGOST341094CryptoKey_Equals(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (int8_t)PublicOnly, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

TElBuiltInGOST341094CryptoKey::TElBuiltInGOST341094CryptoKey(TElBuiltInGOST341094CryptoKeyHandle handle, TElOwnHandle ownHandle) : TElBuiltInCryptoKey(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElBuiltInGOST341094CryptoKey::TElBuiltInGOST341094CryptoKey(TElCustomCryptoProvider &CryptoProvider) : TElBuiltInCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInGOST341094CryptoKey_Create(CryptoProvider.getHandle(), &_Handle));
}

TElBuiltInGOST341094CryptoKey::TElBuiltInGOST341094CryptoKey(TElCustomCryptoProvider *CryptoProvider) : TElBuiltInCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInGOST341094CryptoKey_Create((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#endif /* SB_USE_CLASS_TELBUILTINGOST341094CRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINGOST34102001CRYPTOKEY

SB_INLINE void TElBuiltInGOST34102001CryptoKey::Reset()
{
	SBCheckError(TElBuiltInGOST34102001CryptoKey_Reset(_Handle));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInGOST34102001CryptoKey::Generate(int32_t Bits, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInGOST34102001CryptoKey_Generate(_Handle, Bits, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElBuiltInGOST34102001CryptoKey::Generate(int32_t Bits, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInGOST34102001CryptoKey_Generate(_Handle, Bits, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInGOST34102001CryptoKey::ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInGOST34102001CryptoKey_ImportPublic(_Handle, Buffer, Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInGOST34102001CryptoKey::ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInGOST34102001CryptoKey_ImportPublic(_Handle, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInGOST34102001CryptoKey::ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInGOST34102001CryptoKey_ImportSecret(_Handle, Buffer, Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInGOST34102001CryptoKey::ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInGOST34102001CryptoKey_ImportSecret(_Handle, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInGOST34102001CryptoKey::ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInGOST34102001CryptoKey_ExportPublic(_Handle, Buffer, &Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInGOST34102001CryptoKey::ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInGOST34102001CryptoKey_ExportPublic(_Handle, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInGOST34102001CryptoKey::ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInGOST34102001CryptoKey_ExportSecret(_Handle, Buffer, &Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInGOST34102001CryptoKey::ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInGOST34102001CryptoKey_ExportSecret(_Handle, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElBuiltInGOST34102001CryptoKey::Clone(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInGOST34102001CryptoKey_Clone(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElBuiltInGOST34102001CryptoKey::Clone(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInGOST34102001CryptoKey_Clone(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElBuiltInGOST34102001CryptoKey::ClonePublic(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInGOST34102001CryptoKey_ClonePublic(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElBuiltInGOST34102001CryptoKey::ClonePublic(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInGOST34102001CryptoKey_ClonePublic(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElBuiltInGOST34102001CryptoKey::ClearPublic()
{
	SBCheckError(TElBuiltInGOST34102001CryptoKey_ClearPublic(_Handle));
}

SB_INLINE void TElBuiltInGOST34102001CryptoKey::ClearSecret()
{
	SBCheckError(TElBuiltInGOST34102001CryptoKey_ClearSecret(_Handle));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
bool TElBuiltInGOST34102001CryptoKey::Equals(TElCustomCryptoKey &Source, bool PublicOnly, TElRelativeDistinguishedName &Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInGOST34102001CryptoKey_Equals(_Handle, Source.getHandle(), (int8_t)PublicOnly, Params.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBuiltInGOST34102001CryptoKey::Equals(TElCustomCryptoKey *Source, bool PublicOnly, TElRelativeDistinguishedName *Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInGOST34102001CryptoKey_Equals(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (int8_t)PublicOnly, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

void TElBuiltInGOST34102001CryptoKey::GetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBuiltInGOST34102001CryptoKey_GetKeyProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Default), (int32_t)Default.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1355356253, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBuiltInGOST34102001CryptoKey::SetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBuiltInGOST34102001CryptoKey_SetKeyProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElBuiltInGOST34102001CryptoKey::TElBuiltInGOST34102001CryptoKey(TElBuiltInGOST34102001CryptoKeyHandle handle, TElOwnHandle ownHandle) : TElBuiltInCryptoKey(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElBuiltInGOST34102001CryptoKey::TElBuiltInGOST34102001CryptoKey(TElCustomCryptoProvider &CryptoProvider) : TElBuiltInCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInGOST34102001CryptoKey_Create(CryptoProvider.getHandle(), &_Handle));
}

TElBuiltInGOST34102001CryptoKey::TElBuiltInGOST34102001CryptoKey(TElCustomCryptoProvider *CryptoProvider) : TElBuiltInCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInGOST34102001CryptoKey_Create((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#endif /* SB_USE_CLASS_TELBUILTINGOST34102001CRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINPUBLICKEYCRYPTO

SB_INLINE void TElBuiltInPublicKeyCrypto::SignInit(bool Detached)
{
	SBCheckError(TElBuiltInPublicKeyCrypto_SignInit(_Handle, (int8_t)Detached));
}

SB_INLINE void TElBuiltInPublicKeyCrypto::SignUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInPublicKeyCrypto_SignUpdate(_Handle, Buffer, Size));
}

SB_INLINE void TElBuiltInPublicKeyCrypto::SignFinal(void * Buffer, int32_t &Size)
{
	SBCheckError(TElBuiltInPublicKeyCrypto_SignFinal(_Handle, Buffer, &Size));
}

SB_INLINE void TElBuiltInPublicKeyCrypto::EncryptInit()
{
	SBCheckError(TElBuiltInPublicKeyCrypto_EncryptInit(_Handle));
}

SB_INLINE void TElBuiltInPublicKeyCrypto::EncryptUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInPublicKeyCrypto_EncryptUpdate(_Handle, Buffer, Size));
}

SB_INLINE void TElBuiltInPublicKeyCrypto::EncryptFinal()
{
	SBCheckError(TElBuiltInPublicKeyCrypto_EncryptFinal(_Handle));
}

SB_INLINE void TElBuiltInPublicKeyCrypto::DecryptInit()
{
	SBCheckError(TElBuiltInPublicKeyCrypto_DecryptInit(_Handle));
}

SB_INLINE void TElBuiltInPublicKeyCrypto::DecryptUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInPublicKeyCrypto_DecryptUpdate(_Handle, Buffer, Size));
}

SB_INLINE void TElBuiltInPublicKeyCrypto::DecryptFinal()
{
	SBCheckError(TElBuiltInPublicKeyCrypto_DecryptFinal(_Handle));
}

SB_INLINE void TElBuiltInPublicKeyCrypto::VerifyInit(bool Detached, void * Signature, int32_t SigSize)
{
	SBCheckError(TElBuiltInPublicKeyCrypto_VerifyInit(_Handle, (int8_t)Detached, Signature, SigSize));
}

SB_INLINE void TElBuiltInPublicKeyCrypto::VerifyUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInPublicKeyCrypto_VerifyUpdate(_Handle, Buffer, Size));
}

SB_INLINE int32_t TElBuiltInPublicKeyCrypto::VerifyFinal()
{
	int32_t OutResult;
	SBCheckError(TElBuiltInPublicKeyCrypto_VerifyFinal(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBuiltInPublicKeyCrypto::Encrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElBuiltInPublicKeyCrypto_Encrypt(_Handle, InBuffer, InSize, OutBuffer, &OutSize));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElBuiltInPublicKeyCrypto::Encrypt(TStream &InStream, TStream &OutStream, int32_t Count)
{
	SBCheckError(TElBuiltInPublicKeyCrypto_Encrypt_1(_Handle, InStream.getHandle(), OutStream.getHandle(), Count));
}

SB_INLINE void TElBuiltInPublicKeyCrypto::Encrypt(TStream *InStream, TStream *OutStream, int32_t Count)
{
	SBCheckError(TElBuiltInPublicKeyCrypto_Encrypt_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElBuiltInPublicKeyCrypto::Decrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElBuiltInPublicKeyCrypto_Decrypt(_Handle, InBuffer, InSize, OutBuffer, &OutSize));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElBuiltInPublicKeyCrypto::Decrypt(TStream &InStream, TStream &OutStream, int32_t Count)
{
	SBCheckError(TElBuiltInPublicKeyCrypto_Decrypt_1(_Handle, InStream.getHandle(), OutStream.getHandle(), Count));
}

SB_INLINE void TElBuiltInPublicKeyCrypto::Decrypt(TStream *InStream, TStream *OutStream, int32_t Count)
{
	SBCheckError(TElBuiltInPublicKeyCrypto_Decrypt_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElBuiltInPublicKeyCrypto::Sign(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElBuiltInPublicKeyCrypto_Sign(_Handle, InBuffer, InSize, OutBuffer, &OutSize));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElBuiltInPublicKeyCrypto::Sign(TStream &InStream, TStream &OutStream, int32_t Count)
{
	SBCheckError(TElBuiltInPublicKeyCrypto_Sign_1(_Handle, InStream.getHandle(), OutStream.getHandle(), Count));
}

SB_INLINE void TElBuiltInPublicKeyCrypto::Sign(TStream *InStream, TStream *OutStream, int32_t Count)
{
	SBCheckError(TElBuiltInPublicKeyCrypto_Sign_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElBuiltInPublicKeyCrypto::SignDetached(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElBuiltInPublicKeyCrypto_SignDetached(_Handle, InBuffer, InSize, OutBuffer, &OutSize));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElBuiltInPublicKeyCrypto::SignDetached(TStream &InStream, TStream &OutStream, int32_t Count)
{
	SBCheckError(TElBuiltInPublicKeyCrypto_SignDetached_1(_Handle, InStream.getHandle(), OutStream.getHandle(), Count));
}

SB_INLINE void TElBuiltInPublicKeyCrypto::SignDetached(TStream *InStream, TStream *OutStream, int32_t Count)
{
	SBCheckError(TElBuiltInPublicKeyCrypto_SignDetached_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElBuiltInPublicKeyCrypto::Verify(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	int32_t OutResult;
	SBCheckError(TElBuiltInPublicKeyCrypto_Verify(_Handle, InBuffer, InSize, OutBuffer, &OutSize, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElBuiltInPublicKeyCrypto::Verify(TStream &InStream, TStream &OutStream, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElBuiltInPublicKeyCrypto_Verify_1(_Handle, InStream.getHandle(), OutStream.getHandle(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElBuiltInPublicKeyCrypto::Verify(TStream *InStream, TStream *OutStream, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElBuiltInPublicKeyCrypto_Verify_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElBuiltInPublicKeyCrypto::VerifyDetached(void * InBuffer, int32_t InSize, void * SigBuffer, int32_t SigSize)
{
	int32_t OutResult;
	SBCheckError(TElBuiltInPublicKeyCrypto_VerifyDetached(_Handle, InBuffer, InSize, SigBuffer, SigSize, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElBuiltInPublicKeyCrypto::VerifyDetached(TStream &InStream, TStream &SigStream, int32_t InCount, int32_t SigCount)
{
	int32_t OutResult;
	SBCheckError(TElBuiltInPublicKeyCrypto_VerifyDetached_1(_Handle, InStream.getHandle(), SigStream.getHandle(), InCount, SigCount, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElBuiltInPublicKeyCrypto::VerifyDetached(TStream *InStream, TStream *SigStream, int32_t InCount, int32_t SigCount)
{
	int32_t OutResult;
	SBCheckError(TElBuiltInPublicKeyCrypto_VerifyDetached_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (SigStream != NULL) ? SigStream->getHandle() : SB_NULL_HANDLE, InCount, SigCount, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int64_t TElBuiltInPublicKeyCrypto::EstimateOutputSize(void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperation Operation)
{
	int64_t OutResult;
	SBCheckError(TElBuiltInPublicKeyCrypto_EstimateOutputSize(_Handle, InBuffer, InSize, (TSBBuiltInPublicKeyOperationRaw)Operation, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElBuiltInPublicKeyCrypto::EstimateOutputSize(int64_t InSize, TSBBuiltInPublicKeyOperation Operation)
{
	int64_t OutResult;
	SBCheckError(TElBuiltInPublicKeyCrypto_EstimateOutputSize_1(_Handle, InSize, (TSBBuiltInPublicKeyOperationRaw)Operation, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TElBuiltInPublicKeyCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBuiltInPublicKeyCrypto_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
TElCustomCryptoKey* TElBuiltInPublicKeyCrypto::get_KeyMaterial()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBuiltInPublicKeyCrypto_get_KeyMaterial(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyMaterial)
		this->_Inst_KeyMaterial = new TElCustomCryptoKey(hOutResult, ohFalse);
	else
		this->_Inst_KeyMaterial->updateHandle(hOutResult);
	return this->_Inst_KeyMaterial;
}

SB_INLINE void TElBuiltInPublicKeyCrypto::set_KeyMaterial(TElCustomCryptoKey &Value)
{
	SBCheckError(TElBuiltInPublicKeyCrypto_set_KeyMaterial(_Handle, Value.getHandle()));
}

SB_INLINE void TElBuiltInPublicKeyCrypto::set_KeyMaterial(TElCustomCryptoKey *Value)
{
	SBCheckError(TElBuiltInPublicKeyCrypto_set_KeyMaterial(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

bool TElBuiltInPublicKeyCrypto::get_SupportsEncryption()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInPublicKeyCrypto_get_SupportsEncryption(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBuiltInPublicKeyCrypto::get_SupportsSigning()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInPublicKeyCrypto_get_SupportsSigning(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBuiltInPublicKeyCrypto::get_InputIsHash()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInPublicKeyCrypto_get_InputIsHash(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBuiltInPublicKeyCrypto::set_InputIsHash(bool Value)
{
	SBCheckError(TElBuiltInPublicKeyCrypto_set_InputIsHash(_Handle, (int8_t)Value));
}

void TElBuiltInPublicKeyCrypto::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
	this->_Inst_KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */
}

TElBuiltInPublicKeyCrypto::TElBuiltInPublicKeyCrypto(TElBuiltInPublicKeyCryptoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElBuiltInPublicKeyCrypto::TElBuiltInPublicKeyCrypto(const std::vector<uint8_t> &OID) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBuiltInPublicKeyCrypto_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &_Handle));
}

TElBuiltInPublicKeyCrypto::TElBuiltInPublicKeyCrypto(int32_t Alg) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBuiltInPublicKeyCrypto_Create_1(Alg, &_Handle));
}

TElBuiltInPublicKeyCrypto::TElBuiltInPublicKeyCrypto() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBuiltInPublicKeyCrypto_Create_2(&_Handle));
}

TElBuiltInPublicKeyCrypto::~TElBuiltInPublicKeyCrypto()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
	delete this->_Inst_KeyMaterial;
	this->_Inst_KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */
}
#endif /* SB_USE_CLASS_TELBUILTINPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINRSAPUBLICKEYCRYPTO

SB_INLINE void TElBuiltInRSAPublicKeyCrypto::SignInit(bool Detached)
{
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_SignInit(_Handle, (int8_t)Detached));
}

SB_INLINE void TElBuiltInRSAPublicKeyCrypto::SignUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_SignUpdate(_Handle, Buffer, Size));
}

SB_INLINE void TElBuiltInRSAPublicKeyCrypto::SignFinal(void * Buffer, int32_t &Size)
{
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_SignFinal(_Handle, Buffer, &Size));
}

SB_INLINE void TElBuiltInRSAPublicKeyCrypto::EncryptInit()
{
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_EncryptInit(_Handle));
}

SB_INLINE void TElBuiltInRSAPublicKeyCrypto::EncryptUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_EncryptUpdate(_Handle, Buffer, Size));
}

SB_INLINE void TElBuiltInRSAPublicKeyCrypto::EncryptFinal()
{
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_EncryptFinal(_Handle));
}

SB_INLINE void TElBuiltInRSAPublicKeyCrypto::DecryptInit()
{
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_DecryptInit(_Handle));
}

SB_INLINE void TElBuiltInRSAPublicKeyCrypto::DecryptUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_DecryptUpdate(_Handle, Buffer, Size));
}

SB_INLINE void TElBuiltInRSAPublicKeyCrypto::DecryptFinal()
{
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_DecryptFinal(_Handle));
}

SB_INLINE void TElBuiltInRSAPublicKeyCrypto::VerifyInit(bool Detached, void * Signature, int32_t SigSize)
{
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_VerifyInit(_Handle, (int8_t)Detached, Signature, SigSize));
}

SB_INLINE void TElBuiltInRSAPublicKeyCrypto::VerifyUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_VerifyUpdate(_Handle, Buffer, Size));
}

SB_INLINE int32_t TElBuiltInRSAPublicKeyCrypto::VerifyFinal()
{
	int32_t OutResult;
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_VerifyFinal(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElBuiltInRSAPublicKeyCrypto::EstimateOutputSize(void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperation Operation)
{
	int64_t OutResult;
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_EstimateOutputSize(_Handle, InBuffer, InSize, (TSBBuiltInPublicKeyOperationRaw)Operation, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TElBuiltInRSAPublicKeyCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_ClassType(&OutResult));
	return OutResult;
}

TSBBuiltInRSAPublicKeyCryptoType TElBuiltInRSAPublicKeyCrypto::get_CryptoType()
{
	TSBBuiltInRSAPublicKeyCryptoTypeRaw OutResultRaw = 0;
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_get_CryptoType(_Handle, &OutResultRaw));
	return (TSBBuiltInRSAPublicKeyCryptoType)OutResultRaw;
}

SB_INLINE void TElBuiltInRSAPublicKeyCrypto::set_CryptoType(TSBBuiltInRSAPublicKeyCryptoType Value)
{
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_set_CryptoType(_Handle, (TSBBuiltInRSAPublicKeyCryptoTypeRaw)Value));
}

bool TElBuiltInRSAPublicKeyCrypto::get_UseAlgorithmPrefix()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_get_UseAlgorithmPrefix(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBuiltInRSAPublicKeyCrypto::set_UseAlgorithmPrefix(bool Value)
{
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_set_UseAlgorithmPrefix(_Handle, (int8_t)Value));
}

void TElBuiltInRSAPublicKeyCrypto::get_HashFuncOID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBuiltInRSAPublicKeyCrypto_get_HashFuncOID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(387440541, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBuiltInRSAPublicKeyCrypto::set_HashFuncOID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_set_HashFuncOID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElBuiltInRSAPublicKeyCrypto::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBuiltInRSAPublicKeyCrypto::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_set_HashAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElBuiltInRSAPublicKeyCrypto::get_SaltSize()
{
	int32_t OutResult;
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_get_SaltSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBuiltInRSAPublicKeyCrypto::set_SaltSize(int32_t Value)
{
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_set_SaltSize(_Handle, Value));
}

SB_INLINE int32_t TElBuiltInRSAPublicKeyCrypto::get_MGFAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_get_MGFAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBuiltInRSAPublicKeyCrypto::set_MGFAlgorithm(int32_t Value)
{
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_set_MGFAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElBuiltInRSAPublicKeyCrypto::get_TrailerField()
{
	int32_t OutResult;
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_get_TrailerField(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBuiltInRSAPublicKeyCrypto::set_TrailerField(int32_t Value)
{
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_set_TrailerField(_Handle, Value));
}

bool TElBuiltInRSAPublicKeyCrypto::get_AutoVerifyCreatedSignatures()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_get_AutoVerifyCreatedSignatures(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBuiltInRSAPublicKeyCrypto::set_AutoVerifyCreatedSignatures(bool Value)
{
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_set_AutoVerifyCreatedSignatures(_Handle, (int8_t)Value));
}

TElBuiltInRSAPublicKeyCrypto::TElBuiltInRSAPublicKeyCrypto(TElBuiltInRSAPublicKeyCryptoHandle handle, TElOwnHandle ownHandle) : TElBuiltInPublicKeyCrypto(handle, ownHandle)
{
}

TElBuiltInRSAPublicKeyCrypto::TElBuiltInRSAPublicKeyCrypto(const std::vector<uint8_t> &OID) : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &_Handle));
}

TElBuiltInRSAPublicKeyCrypto::TElBuiltInRSAPublicKeyCrypto(int32_t Alg) : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_Create_1(Alg, &_Handle));
}

TElBuiltInRSAPublicKeyCrypto::TElBuiltInRSAPublicKeyCrypto() : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInRSAPublicKeyCrypto_Create_2(&_Handle));
}

#endif /* SB_USE_CLASS_TELBUILTINRSAPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINDSAPUBLICKEYCRYPTO

SB_INLINE void TElBuiltInDSAPublicKeyCrypto::EncodeSignature(void * R, int32_t RSize, void * S, int32_t SSize, void * Sig, int32_t &SigSize)
{
	SBCheckError(TElBuiltInDSAPublicKeyCrypto_EncodeSignature(_Handle, R, RSize, S, SSize, Sig, &SigSize));
}

SB_INLINE void TElBuiltInDSAPublicKeyCrypto::DecodeSignature(void * Sig, int32_t SigSize, void * R, int32_t &RSize, void * S, int32_t &SSize)
{
	SBCheckError(TElBuiltInDSAPublicKeyCrypto_DecodeSignature(_Handle, Sig, SigSize, R, &RSize, S, &SSize));
}

SB_INLINE void TElBuiltInDSAPublicKeyCrypto::SignInit(bool Detached)
{
	SBCheckError(TElBuiltInDSAPublicKeyCrypto_SignInit(_Handle, (int8_t)Detached));
}

SB_INLINE void TElBuiltInDSAPublicKeyCrypto::SignUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInDSAPublicKeyCrypto_SignUpdate(_Handle, Buffer, Size));
}

SB_INLINE void TElBuiltInDSAPublicKeyCrypto::SignFinal(void * Buffer, int32_t &Size)
{
	SBCheckError(TElBuiltInDSAPublicKeyCrypto_SignFinal(_Handle, Buffer, &Size));
}

SB_INLINE void TElBuiltInDSAPublicKeyCrypto::VerifyInit(bool Detached, void * Signature, int32_t SigSize)
{
	SBCheckError(TElBuiltInDSAPublicKeyCrypto_VerifyInit(_Handle, (int8_t)Detached, Signature, SigSize));
}

SB_INLINE void TElBuiltInDSAPublicKeyCrypto::VerifyUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInDSAPublicKeyCrypto_VerifyUpdate(_Handle, Buffer, Size));
}

SB_INLINE int32_t TElBuiltInDSAPublicKeyCrypto::VerifyFinal()
{
	int32_t OutResult;
	SBCheckError(TElBuiltInDSAPublicKeyCrypto_VerifyFinal(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElBuiltInDSAPublicKeyCrypto::EstimateOutputSize(void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperation Operation)
{
	int64_t OutResult;
	SBCheckError(TElBuiltInDSAPublicKeyCrypto_EstimateOutputSize(_Handle, InBuffer, InSize, (TSBBuiltInPublicKeyOperationRaw)Operation, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TElBuiltInDSAPublicKeyCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBuiltInDSAPublicKeyCrypto_ClassType(&OutResult));
	return OutResult;
}

TElBuiltInDSAPublicKeyCrypto::TElBuiltInDSAPublicKeyCrypto(TElBuiltInDSAPublicKeyCryptoHandle handle, TElOwnHandle ownHandle) : TElBuiltInPublicKeyCrypto(handle, ownHandle)
{
}

TElBuiltInDSAPublicKeyCrypto::TElBuiltInDSAPublicKeyCrypto(const std::vector<uint8_t> &OID) : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInDSAPublicKeyCrypto_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &_Handle));
}

TElBuiltInDSAPublicKeyCrypto::TElBuiltInDSAPublicKeyCrypto(int32_t Alg) : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInDSAPublicKeyCrypto_Create_1(Alg, &_Handle));
}

TElBuiltInDSAPublicKeyCrypto::TElBuiltInDSAPublicKeyCrypto() : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInDSAPublicKeyCrypto_Create_2(&_Handle));
}

#endif /* SB_USE_CLASS_TELBUILTINDSAPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINELGAMALPUBLICKEYCRYPTO

SB_INLINE void TElBuiltInElgamalPublicKeyCrypto::SignInit(bool Detached)
{
	SBCheckError(TElBuiltInElgamalPublicKeyCrypto_SignInit(_Handle, (int8_t)Detached));
}

SB_INLINE void TElBuiltInElgamalPublicKeyCrypto::SignUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInElgamalPublicKeyCrypto_SignUpdate(_Handle, Buffer, Size));
}

SB_INLINE void TElBuiltInElgamalPublicKeyCrypto::SignFinal(void * Buffer, int32_t &Size)
{
	SBCheckError(TElBuiltInElgamalPublicKeyCrypto_SignFinal(_Handle, Buffer, &Size));
}

SB_INLINE void TElBuiltInElgamalPublicKeyCrypto::EncryptInit()
{
	SBCheckError(TElBuiltInElgamalPublicKeyCrypto_EncryptInit(_Handle));
}

SB_INLINE void TElBuiltInElgamalPublicKeyCrypto::EncryptUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInElgamalPublicKeyCrypto_EncryptUpdate(_Handle, Buffer, Size));
}

SB_INLINE void TElBuiltInElgamalPublicKeyCrypto::EncryptFinal()
{
	SBCheckError(TElBuiltInElgamalPublicKeyCrypto_EncryptFinal(_Handle));
}

SB_INLINE void TElBuiltInElgamalPublicKeyCrypto::DecryptInit()
{
	SBCheckError(TElBuiltInElgamalPublicKeyCrypto_DecryptInit(_Handle));
}

SB_INLINE void TElBuiltInElgamalPublicKeyCrypto::DecryptUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInElgamalPublicKeyCrypto_DecryptUpdate(_Handle, Buffer, Size));
}

SB_INLINE void TElBuiltInElgamalPublicKeyCrypto::DecryptFinal()
{
	SBCheckError(TElBuiltInElgamalPublicKeyCrypto_DecryptFinal(_Handle));
}

SB_INLINE void TElBuiltInElgamalPublicKeyCrypto::VerifyInit(bool Detached, void * Signature, int32_t SigSize)
{
	SBCheckError(TElBuiltInElgamalPublicKeyCrypto_VerifyInit(_Handle, (int8_t)Detached, Signature, SigSize));
}

SB_INLINE void TElBuiltInElgamalPublicKeyCrypto::VerifyUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInElgamalPublicKeyCrypto_VerifyUpdate(_Handle, Buffer, Size));
}

SB_INLINE int32_t TElBuiltInElgamalPublicKeyCrypto::VerifyFinal()
{
	int32_t OutResult;
	SBCheckError(TElBuiltInElgamalPublicKeyCrypto_VerifyFinal(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElBuiltInElgamalPublicKeyCrypto::EstimateOutputSize(void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperation Operation)
{
	int64_t OutResult;
	SBCheckError(TElBuiltInElgamalPublicKeyCrypto_EstimateOutputSize(_Handle, InBuffer, InSize, (TSBBuiltInPublicKeyOperationRaw)Operation, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TElBuiltInElgamalPublicKeyCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBuiltInElgamalPublicKeyCrypto_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElBuiltInElgamalPublicKeyCrypto::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElBuiltInElgamalPublicKeyCrypto_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBuiltInElgamalPublicKeyCrypto::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElBuiltInElgamalPublicKeyCrypto_set_HashAlgorithm(_Handle, Value));
}

TElBuiltInElgamalPublicKeyCrypto::TElBuiltInElgamalPublicKeyCrypto(TElBuiltInElgamalPublicKeyCryptoHandle handle, TElOwnHandle ownHandle) : TElBuiltInPublicKeyCrypto(handle, ownHandle)
{
}

TElBuiltInElgamalPublicKeyCrypto::TElBuiltInElgamalPublicKeyCrypto(const std::vector<uint8_t> &OID) : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInElgamalPublicKeyCrypto_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &_Handle));
}

TElBuiltInElgamalPublicKeyCrypto::TElBuiltInElgamalPublicKeyCrypto(int32_t Alg) : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInElgamalPublicKeyCrypto_Create_1(Alg, &_Handle));
}

TElBuiltInElgamalPublicKeyCrypto::TElBuiltInElgamalPublicKeyCrypto() : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInElgamalPublicKeyCrypto_Create_2(&_Handle));
}

#endif /* SB_USE_CLASS_TELBUILTINELGAMALPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINDHPUBLICKEYCRYPTO

SB_INLINE void TElBuiltInDHPublicKeyCrypto::EncryptInit()
{
	SBCheckError(TElBuiltInDHPublicKeyCrypto_EncryptInit(_Handle));
}

SB_INLINE void TElBuiltInDHPublicKeyCrypto::EncryptUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInDHPublicKeyCrypto_EncryptUpdate(_Handle, Buffer, Size));
}

SB_INLINE void TElBuiltInDHPublicKeyCrypto::EncryptFinal()
{
	SBCheckError(TElBuiltInDHPublicKeyCrypto_EncryptFinal(_Handle));
}

SB_INLINE void TElBuiltInDHPublicKeyCrypto::DecryptInit()
{
	SBCheckError(TElBuiltInDHPublicKeyCrypto_DecryptInit(_Handle));
}

SB_INLINE void TElBuiltInDHPublicKeyCrypto::DecryptUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInDHPublicKeyCrypto_DecryptUpdate(_Handle, Buffer, Size));
}

SB_INLINE void TElBuiltInDHPublicKeyCrypto::DecryptFinal()
{
	SBCheckError(TElBuiltInDHPublicKeyCrypto_DecryptFinal(_Handle));
}

SB_INLINE int64_t TElBuiltInDHPublicKeyCrypto::EstimateOutputSize(void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperation Operation)
{
	int64_t OutResult;
	SBCheckError(TElBuiltInDHPublicKeyCrypto_EstimateOutputSize(_Handle, InBuffer, InSize, (TSBBuiltInPublicKeyOperationRaw)Operation, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TElBuiltInDHPublicKeyCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBuiltInDHPublicKeyCrypto_ClassType(&OutResult));
	return OutResult;
}

TElBuiltInDHPublicKeyCrypto::TElBuiltInDHPublicKeyCrypto(TElBuiltInDHPublicKeyCryptoHandle handle, TElOwnHandle ownHandle) : TElBuiltInPublicKeyCrypto(handle, ownHandle)
{
}

TElBuiltInDHPublicKeyCrypto::TElBuiltInDHPublicKeyCrypto(const std::vector<uint8_t> &OID) : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInDHPublicKeyCrypto_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &_Handle));
}

TElBuiltInDHPublicKeyCrypto::TElBuiltInDHPublicKeyCrypto(int32_t Alg) : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInDHPublicKeyCrypto_Create_1(Alg, &_Handle));
}

TElBuiltInDHPublicKeyCrypto::TElBuiltInDHPublicKeyCrypto() : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInDHPublicKeyCrypto_Create_2(&_Handle));
}

#endif /* SB_USE_CLASS_TELBUILTINDHPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINECDSAPUBLICKEYCRYPTO

SB_INLINE void TElBuiltInECDSAPublicKeyCrypto::EncodeSignature(void * R, int32_t RSize, void * S, int32_t SSize, void * Sig, int32_t &SigSize)
{
	SBCheckError(TElBuiltInECDSAPublicKeyCrypto_EncodeSignature(_Handle, R, RSize, S, SSize, Sig, &SigSize));
}

SB_INLINE void TElBuiltInECDSAPublicKeyCrypto::DecodeSignature(void * Sig, int32_t SigSize, void * R, int32_t &RSize, void * S, int32_t &SSize)
{
	SBCheckError(TElBuiltInECDSAPublicKeyCrypto_DecodeSignature(_Handle, Sig, SigSize, R, &RSize, S, &SSize));
}

SB_INLINE void TElBuiltInECDSAPublicKeyCrypto::SignInit(bool Detached)
{
	SBCheckError(TElBuiltInECDSAPublicKeyCrypto_SignInit(_Handle, (int8_t)Detached));
}

SB_INLINE void TElBuiltInECDSAPublicKeyCrypto::SignUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInECDSAPublicKeyCrypto_SignUpdate(_Handle, Buffer, Size));
}

SB_INLINE void TElBuiltInECDSAPublicKeyCrypto::SignFinal(void * Buffer, int32_t &Size)
{
	SBCheckError(TElBuiltInECDSAPublicKeyCrypto_SignFinal(_Handle, Buffer, &Size));
}

SB_INLINE void TElBuiltInECDSAPublicKeyCrypto::VerifyInit(bool Detached, void * Signature, int32_t SigSize)
{
	SBCheckError(TElBuiltInECDSAPublicKeyCrypto_VerifyInit(_Handle, (int8_t)Detached, Signature, SigSize));
}

SB_INLINE void TElBuiltInECDSAPublicKeyCrypto::VerifyUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInECDSAPublicKeyCrypto_VerifyUpdate(_Handle, Buffer, Size));
}

SB_INLINE int32_t TElBuiltInECDSAPublicKeyCrypto::VerifyFinal()
{
	int32_t OutResult;
	SBCheckError(TElBuiltInECDSAPublicKeyCrypto_VerifyFinal(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElBuiltInECDSAPublicKeyCrypto::EstimateOutputSize(void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperation Operation)
{
	int64_t OutResult;
	SBCheckError(TElBuiltInECDSAPublicKeyCrypto_EstimateOutputSize(_Handle, InBuffer, InSize, (TSBBuiltInPublicKeyOperationRaw)Operation, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TElBuiltInECDSAPublicKeyCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBuiltInECDSAPublicKeyCrypto_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElBuiltInECDSAPublicKeyCrypto::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElBuiltInECDSAPublicKeyCrypto_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBuiltInECDSAPublicKeyCrypto::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElBuiltInECDSAPublicKeyCrypto_set_HashAlgorithm(_Handle, Value));
}

bool TElBuiltInECDSAPublicKeyCrypto::get_PlainECDSA()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInECDSAPublicKeyCrypto_get_PlainECDSA(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBuiltInECDSAPublicKeyCrypto::set_PlainECDSA(bool Value)
{
	SBCheckError(TElBuiltInECDSAPublicKeyCrypto_set_PlainECDSA(_Handle, (int8_t)Value));
}

TElBuiltInECDSAPublicKeyCrypto::TElBuiltInECDSAPublicKeyCrypto(TElBuiltInECDSAPublicKeyCryptoHandle handle, TElOwnHandle ownHandle) : TElBuiltInPublicKeyCrypto(handle, ownHandle)
{
}

TElBuiltInECDSAPublicKeyCrypto::TElBuiltInECDSAPublicKeyCrypto(const std::vector<uint8_t> &OID) : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInECDSAPublicKeyCrypto_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &_Handle));
}

TElBuiltInECDSAPublicKeyCrypto::TElBuiltInECDSAPublicKeyCrypto(int32_t Alg) : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInECDSAPublicKeyCrypto_Create_1(Alg, &_Handle));
}

TElBuiltInECDSAPublicKeyCrypto::TElBuiltInECDSAPublicKeyCrypto() : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInECDSAPublicKeyCrypto_Create_2(&_Handle));
}

#endif /* SB_USE_CLASS_TELBUILTINECDSAPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINECDHPUBLICKEYCRYPTO

SB_INLINE void TElBuiltInECDHPublicKeyCrypto::EncryptInit()
{
	SBCheckError(TElBuiltInECDHPublicKeyCrypto_EncryptInit(_Handle));
}

SB_INLINE void TElBuiltInECDHPublicKeyCrypto::EncryptUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInECDHPublicKeyCrypto_EncryptUpdate(_Handle, Buffer, Size));
}

SB_INLINE void TElBuiltInECDHPublicKeyCrypto::EncryptFinal()
{
	SBCheckError(TElBuiltInECDHPublicKeyCrypto_EncryptFinal(_Handle));
}

SB_INLINE void TElBuiltInECDHPublicKeyCrypto::DecryptInit()
{
	SBCheckError(TElBuiltInECDHPublicKeyCrypto_DecryptInit(_Handle));
}

SB_INLINE void TElBuiltInECDHPublicKeyCrypto::DecryptUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInECDHPublicKeyCrypto_DecryptUpdate(_Handle, Buffer, Size));
}

SB_INLINE void TElBuiltInECDHPublicKeyCrypto::DecryptFinal()
{
	SBCheckError(TElBuiltInECDHPublicKeyCrypto_DecryptFinal(_Handle));
}

SB_INLINE int64_t TElBuiltInECDHPublicKeyCrypto::EstimateOutputSize(void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperation Operation)
{
	int64_t OutResult;
	SBCheckError(TElBuiltInECDHPublicKeyCrypto_EstimateOutputSize(_Handle, InBuffer, InSize, (TSBBuiltInPublicKeyOperationRaw)Operation, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TElBuiltInECDHPublicKeyCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBuiltInECDHPublicKeyCrypto_ClassType(&OutResult));
	return OutResult;
}

TElBuiltInECDHPublicKeyCrypto::TElBuiltInECDHPublicKeyCrypto(TElBuiltInECDHPublicKeyCryptoHandle handle, TElOwnHandle ownHandle) : TElBuiltInPublicKeyCrypto(handle, ownHandle)
{
}

TElBuiltInECDHPublicKeyCrypto::TElBuiltInECDHPublicKeyCrypto(const std::vector<uint8_t> &OID) : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInECDHPublicKeyCrypto_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &_Handle));
}

TElBuiltInECDHPublicKeyCrypto::TElBuiltInECDHPublicKeyCrypto(int32_t Alg) : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInECDHPublicKeyCrypto_Create_1(Alg, &_Handle));
}

TElBuiltInECDHPublicKeyCrypto::TElBuiltInECDHPublicKeyCrypto() : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInECDHPublicKeyCrypto_Create_2(&_Handle));
}

#endif /* SB_USE_CLASS_TELBUILTINECDHPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINGOST94PUBLICKEYCRYPTO

SB_INLINE void TElBuiltInGOST94PublicKeyCrypto::SignInit(bool Detached)
{
	SBCheckError(TElBuiltInGOST94PublicKeyCrypto_SignInit(_Handle, (int8_t)Detached));
}

SB_INLINE void TElBuiltInGOST94PublicKeyCrypto::SignUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInGOST94PublicKeyCrypto_SignUpdate(_Handle, Buffer, Size));
}

SB_INLINE void TElBuiltInGOST94PublicKeyCrypto::SignFinal(void * Buffer, int32_t &Size)
{
	SBCheckError(TElBuiltInGOST94PublicKeyCrypto_SignFinal(_Handle, Buffer, &Size));
}

SB_INLINE void TElBuiltInGOST94PublicKeyCrypto::VerifyInit(bool Detached, void * Signature, int32_t SigSize)
{
	SBCheckError(TElBuiltInGOST94PublicKeyCrypto_VerifyInit(_Handle, (int8_t)Detached, Signature, SigSize));
}

SB_INLINE void TElBuiltInGOST94PublicKeyCrypto::VerifyUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInGOST94PublicKeyCrypto_VerifyUpdate(_Handle, Buffer, Size));
}

SB_INLINE int32_t TElBuiltInGOST94PublicKeyCrypto::VerifyFinal()
{
	int32_t OutResult;
	SBCheckError(TElBuiltInGOST94PublicKeyCrypto_VerifyFinal(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElBuiltInGOST94PublicKeyCrypto::EstimateOutputSize(void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperation Operation)
{
	int64_t OutResult;
	SBCheckError(TElBuiltInGOST94PublicKeyCrypto_EstimateOutputSize(_Handle, InBuffer, InSize, (TSBBuiltInPublicKeyOperationRaw)Operation, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TElBuiltInGOST94PublicKeyCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBuiltInGOST94PublicKeyCrypto_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElBuiltInGOST94PublicKeyCrypto::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElBuiltInGOST94PublicKeyCrypto_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBuiltInGOST94PublicKeyCrypto::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElBuiltInGOST94PublicKeyCrypto_set_HashAlgorithm(_Handle, Value));
}

TElBuiltInGOST94PublicKeyCrypto::TElBuiltInGOST94PublicKeyCrypto(TElBuiltInGOST94PublicKeyCryptoHandle handle, TElOwnHandle ownHandle) : TElBuiltInPublicKeyCrypto(handle, ownHandle)
{
}

TElBuiltInGOST94PublicKeyCrypto::TElBuiltInGOST94PublicKeyCrypto(const std::vector<uint8_t> &OID) : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInGOST94PublicKeyCrypto_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &_Handle));
}

TElBuiltInGOST94PublicKeyCrypto::TElBuiltInGOST94PublicKeyCrypto(int32_t Alg) : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInGOST94PublicKeyCrypto_Create_1(Alg, &_Handle));
}

TElBuiltInGOST94PublicKeyCrypto::TElBuiltInGOST94PublicKeyCrypto() : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInGOST94PublicKeyCrypto_Create_2(&_Handle));
}

#endif /* SB_USE_CLASS_TELBUILTINGOST94PUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINGOST2001PUBLICKEYCRYPTO

SB_INLINE void TElBuiltInGOST2001PublicKeyCrypto::EncryptInit()
{
	SBCheckError(TElBuiltInGOST2001PublicKeyCrypto_EncryptInit(_Handle));
}

SB_INLINE void TElBuiltInGOST2001PublicKeyCrypto::EncryptUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInGOST2001PublicKeyCrypto_EncryptUpdate(_Handle, Buffer, Size));
}

SB_INLINE void TElBuiltInGOST2001PublicKeyCrypto::EncryptFinal()
{
	SBCheckError(TElBuiltInGOST2001PublicKeyCrypto_EncryptFinal(_Handle));
}

SB_INLINE void TElBuiltInGOST2001PublicKeyCrypto::DecryptInit()
{
	SBCheckError(TElBuiltInGOST2001PublicKeyCrypto_DecryptInit(_Handle));
}

SB_INLINE void TElBuiltInGOST2001PublicKeyCrypto::DecryptUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInGOST2001PublicKeyCrypto_DecryptUpdate(_Handle, Buffer, Size));
}

SB_INLINE void TElBuiltInGOST2001PublicKeyCrypto::DecryptFinal()
{
	SBCheckError(TElBuiltInGOST2001PublicKeyCrypto_DecryptFinal(_Handle));
}

SB_INLINE void TElBuiltInGOST2001PublicKeyCrypto::SignInit(bool Detached)
{
	SBCheckError(TElBuiltInGOST2001PublicKeyCrypto_SignInit(_Handle, (int8_t)Detached));
}

SB_INLINE void TElBuiltInGOST2001PublicKeyCrypto::SignUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInGOST2001PublicKeyCrypto_SignUpdate(_Handle, Buffer, Size));
}

SB_INLINE void TElBuiltInGOST2001PublicKeyCrypto::SignFinal(void * Buffer, int32_t &Size)
{
	SBCheckError(TElBuiltInGOST2001PublicKeyCrypto_SignFinal(_Handle, Buffer, &Size));
}

SB_INLINE void TElBuiltInGOST2001PublicKeyCrypto::VerifyInit(bool Detached, void * Signature, int32_t SigSize)
{
	SBCheckError(TElBuiltInGOST2001PublicKeyCrypto_VerifyInit(_Handle, (int8_t)Detached, Signature, SigSize));
}

SB_INLINE void TElBuiltInGOST2001PublicKeyCrypto::VerifyUpdate(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInGOST2001PublicKeyCrypto_VerifyUpdate(_Handle, Buffer, Size));
}

SB_INLINE int32_t TElBuiltInGOST2001PublicKeyCrypto::VerifyFinal()
{
	int32_t OutResult;
	SBCheckError(TElBuiltInGOST2001PublicKeyCrypto_VerifyFinal(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElBuiltInGOST2001PublicKeyCrypto::EstimateOutputSize(void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperation Operation)
{
	int64_t OutResult;
	SBCheckError(TElBuiltInGOST2001PublicKeyCrypto_EstimateOutputSize(_Handle, InBuffer, InSize, (TSBBuiltInPublicKeyOperationRaw)Operation, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TElBuiltInGOST2001PublicKeyCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBuiltInGOST2001PublicKeyCrypto_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElBuiltInGOST2001PublicKeyCrypto::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElBuiltInGOST2001PublicKeyCrypto_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBuiltInGOST2001PublicKeyCrypto::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElBuiltInGOST2001PublicKeyCrypto_set_HashAlgorithm(_Handle, Value));
}

void TElBuiltInGOST2001PublicKeyCrypto::get_UKM(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBuiltInGOST2001PublicKeyCrypto_get_UKM(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1459025402, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBuiltInGOST2001PublicKeyCrypto::set_UKM(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBuiltInGOST2001PublicKeyCrypto_set_UKM(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElBuiltInGOST2001PublicKeyCrypto::get_CEKMAC(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBuiltInGOST2001PublicKeyCrypto_get_CEKMAC(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1231069965, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBuiltInGOST2001PublicKeyCrypto::set_CEKMAC(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBuiltInGOST2001PublicKeyCrypto_set_CEKMAC(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElBuiltInGOST2001PublicKeyCrypto::get_EphemeralKey(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBuiltInGOST2001PublicKeyCrypto_get_EphemeralKey(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1120529005, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBuiltInGOST2001PublicKeyCrypto::set_EphemeralKey(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBuiltInGOST2001PublicKeyCrypto_set_EphemeralKey(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElBuiltInGOST2001PublicKeyCrypto::TElBuiltInGOST2001PublicKeyCrypto(TElBuiltInGOST2001PublicKeyCryptoHandle handle, TElOwnHandle ownHandle) : TElBuiltInPublicKeyCrypto(handle, ownHandle)
{
}

TElBuiltInGOST2001PublicKeyCrypto::TElBuiltInGOST2001PublicKeyCrypto(const std::vector<uint8_t> &OID) : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInGOST2001PublicKeyCrypto_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &_Handle));
}

TElBuiltInGOST2001PublicKeyCrypto::TElBuiltInGOST2001PublicKeyCrypto(int32_t Alg) : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInGOST2001PublicKeyCrypto_Create_1(Alg, &_Handle));
}

TElBuiltInGOST2001PublicKeyCrypto::TElBuiltInGOST2001PublicKeyCrypto() : TElBuiltInPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInGOST2001PublicKeyCrypto_Create_2(&_Handle));
}

#endif /* SB_USE_CLASS_TELBUILTINGOST2001PUBLICKEYCRYPTO */

};	/* namespace SecureBlackbox */

