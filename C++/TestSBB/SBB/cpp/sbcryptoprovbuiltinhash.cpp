#include "sbcryptoprovbuiltinhash.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELBUILTINHASHFUNCTION

SB_INLINE void TElBuiltInHashFunction::SetHashFunctionProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBuiltInHashFunction_SetHashFunctionProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElBuiltInHashFunction::GetHashFunctionProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBuiltInHashFunction_GetHashFunctionProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Default), (int32_t)Default.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1862334944, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBuiltInHashFunction::Reset()
{
	SBCheckError(TElBuiltInHashFunction_Reset(_Handle));
}

SB_INLINE void TElBuiltInHashFunction::Update(void * Buffer, int32_t Size)
{
	SBCheckError(TElBuiltInHashFunction_Update(_Handle, Buffer, Size));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElBuiltInHashFunction::Update(TStream &Stream, int64_t Count)
{
	SBCheckError(TElBuiltInHashFunction_Update_1(_Handle, Stream.getHandle(), Count));
}

SB_INLINE void TElBuiltInHashFunction::Update(TStream *Stream, int64_t Count)
{
	SBCheckError(TElBuiltInHashFunction_Update_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElBuiltInHashFunction::Finish(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBuiltInHashFunction_Finish(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1498020764, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TElBuiltInHashFunctionHandle TElBuiltInHashFunction::Clone()
{
	TElBuiltInHashFunctionHandle OutResult;
	SBCheckError(TElBuiltInHashFunction_Clone(_Handle, &OutResult));
	return OutResult;
}

bool TElBuiltInHashFunction::IsAlgorithmSupported(int32_t Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInHashFunction_IsAlgorithmSupported(Algorithm, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBuiltInHashFunction::IsAlgorithmSupported_Inst(int32_t Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInHashFunction_IsAlgorithmSupported_1(_Handle, Algorithm, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBuiltInHashFunction::IsAlgorithmSupported(const std::vector<uint8_t> &OID)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInHashFunction_IsAlgorithmSupported_2(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBuiltInHashFunction::IsAlgorithmSupported_Inst(const std::vector<uint8_t> &OID)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInHashFunction_IsAlgorithmSupported_3(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElBuiltInHashFunction::GetDigestSizeBits(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(TElBuiltInHashFunction_GetDigestSizeBits(Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElBuiltInHashFunction::GetDigestSizeBits_Inst(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(TElBuiltInHashFunction_GetDigestSizeBits_1(_Handle, Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElBuiltInHashFunction::GetDigestSizeBits(const std::vector<uint8_t> &OID)
{
	int32_t OutResult;
	SBCheckError(TElBuiltInHashFunction_GetDigestSizeBits_2(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElBuiltInHashFunction::GetDigestSizeBits_Inst(const std::vector<uint8_t> &OID)
{
	int32_t OutResult;
	SBCheckError(TElBuiltInHashFunction_GetDigestSizeBits_3(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElBuiltInHashFunction::get_Algorithm()
{
	int32_t OutResult;
	SBCheckError(TElBuiltInHashFunction_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
TElCustomCryptoKey* TElBuiltInHashFunction::get_KeyMaterial()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBuiltInHashFunction_get_KeyMaterial(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyMaterial)
		this->_Inst_KeyMaterial = new TElCustomCryptoKey(hOutResult, ohFalse);
	else
		this->_Inst_KeyMaterial->updateHandle(hOutResult);
	return this->_Inst_KeyMaterial;
}

SB_INLINE void TElBuiltInHashFunction::set_KeyMaterial(TElCustomCryptoKey &Value)
{
	SBCheckError(TElBuiltInHashFunction_set_KeyMaterial(_Handle, Value.getHandle()));
}

SB_INLINE void TElBuiltInHashFunction::set_KeyMaterial(TElCustomCryptoKey *Value)
{
	SBCheckError(TElBuiltInHashFunction_set_KeyMaterial(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

void TElBuiltInHashFunction::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
	this->_Inst_KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */
}

TElBuiltInHashFunction::TElBuiltInHashFunction(TElBuiltInHashFunctionHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
TElBuiltInHashFunction::TElBuiltInHashFunction(int32_t Algorithm, TElRelativeDistinguishedName &Parameters, TElCustomCryptoKey &Key) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBuiltInHashFunction_Create(Algorithm, Parameters.getHandle(), Key.getHandle(), &_Handle));
}

TElBuiltInHashFunction::TElBuiltInHashFunction(int32_t Algorithm, TElRelativeDistinguishedName *Parameters, TElCustomCryptoKey *Key) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBuiltInHashFunction_Create(Algorithm, (Parameters != NULL) ? Parameters->getHandle() : SB_NULL_HANDLE, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME
TElBuiltInHashFunction::TElBuiltInHashFunction(const std::vector<uint8_t> &OID, TElRelativeDistinguishedName &Parameters, TElCustomCryptoKey &Key) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBuiltInHashFunction_Create_1(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), Parameters.getHandle(), Key.getHandle(), &_Handle));
}

TElBuiltInHashFunction::TElBuiltInHashFunction(const std::vector<uint8_t> &OID, TElRelativeDistinguishedName *Parameters, TElCustomCryptoKey *Key) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBuiltInHashFunction_Create_1(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (Parameters != NULL) ? Parameters->getHandle() : SB_NULL_HANDLE, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELRELATIVEDISTINGUISHEDNAME */

TElBuiltInHashFunction::~TElBuiltInHashFunction()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
	delete this->_Inst_KeyMaterial;
	this->_Inst_KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */
}
#endif /* SB_USE_CLASS_TELBUILTINHASHFUNCTION */

#ifdef SB_USE_CLASS_TELBUILTINMACKEY

SB_INLINE void TElBuiltInMACKey::Reset()
{
	SBCheckError(TElBuiltInMACKey_Reset(_Handle));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInMACKey::Generate(int32_t Bits, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInMACKey_Generate(_Handle, Bits, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElBuiltInMACKey::Generate(int32_t Bits, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInMACKey_Generate(_Handle, Bits, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInMACKey::ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInMACKey_ImportPublic(_Handle, Buffer, Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInMACKey::ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInMACKey_ImportPublic(_Handle, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInMACKey::ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInMACKey_ImportSecret(_Handle, Buffer, Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInMACKey::ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInMACKey_ImportSecret(_Handle, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInMACKey::ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInMACKey_ExportPublic(_Handle, Buffer, &Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInMACKey::ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInMACKey_ExportPublic(_Handle, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInMACKey::ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInMACKey_ExportSecret(_Handle, Buffer, &Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInMACKey::ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInMACKey_ExportSecret(_Handle, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElBuiltInMACKey::Clone(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInMACKey_Clone(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElBuiltInMACKey::Clone(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInMACKey_Clone(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElBuiltInMACKey::ClonePublic(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInMACKey_ClonePublic(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElBuiltInMACKey::ClonePublic(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInMACKey_ClonePublic(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElBuiltInMACKey::ClearPublic()
{
	SBCheckError(TElBuiltInMACKey_ClearPublic(_Handle));
}

SB_INLINE void TElBuiltInMACKey::ClearSecret()
{
	SBCheckError(TElBuiltInMACKey_ClearSecret(_Handle));
}

void TElBuiltInMACKey::GetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBuiltInMACKey_GetKeyProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Default), (int32_t)Default.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(446231977, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBuiltInMACKey::SetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBuiltInMACKey_SetKeyProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE void TElBuiltInMACKey::ChangeAlgorithm(int32_t Algorithm)
{
	SBCheckError(TElBuiltInMACKey_ChangeAlgorithm(_Handle, Algorithm));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
bool TElBuiltInMACKey::Equals(TElCustomCryptoKey &Source, bool PublicOnly, TElRelativeDistinguishedName &Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInMACKey_Equals(_Handle, Source.getHandle(), (int8_t)PublicOnly, Params.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBuiltInMACKey::Equals(TElCustomCryptoKey *Source, bool PublicOnly, TElRelativeDistinguishedName *Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInMACKey_Equals(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (int8_t)PublicOnly, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

TElBuiltInMACKey::TElBuiltInMACKey(TElBuiltInMACKeyHandle handle, TElOwnHandle ownHandle) : TElBuiltInCryptoKey(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElBuiltInMACKey::TElBuiltInMACKey(TElCustomCryptoProvider &CryptoProvider) : TElBuiltInCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInMACKey_Create(CryptoProvider.getHandle(), &_Handle));
}

TElBuiltInMACKey::TElBuiltInMACKey(TElCustomCryptoProvider *CryptoProvider) : TElBuiltInCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInMACKey_Create((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#endif /* SB_USE_CLASS_TELBUILTINMACKEY */

};	/* namespace SecureBlackbox */

