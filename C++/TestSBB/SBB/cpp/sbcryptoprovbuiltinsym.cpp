#include "sbcryptoprovbuiltinsym.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTOKEY

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInSymmetricCryptoKey::Generate(int32_t Bits, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInSymmetricCryptoKey_Generate(_Handle, Bits, Params.getHandle(), pMethodProgressFunc, pDataProgressFunc, ProgressData));
}

SB_INLINE void TElBuiltInSymmetricCryptoKey::Generate(int32_t Bits, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData)
{
	SBCheckError(TElBuiltInSymmetricCryptoKey_Generate(_Handle, Bits, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, pMethodProgressFunc, pDataProgressFunc, ProgressData));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElBuiltInSymmetricCryptoKey::GenerateIV(int32_t Bits)
{
	SBCheckError(TElBuiltInSymmetricCryptoKey_GenerateIV(_Handle, Bits));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInSymmetricCryptoKey::ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInSymmetricCryptoKey_ImportPublic(_Handle, Buffer, Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInSymmetricCryptoKey::ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInSymmetricCryptoKey_ImportPublic(_Handle, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInSymmetricCryptoKey::ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInSymmetricCryptoKey_ImportSecret(_Handle, Buffer, Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInSymmetricCryptoKey::ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInSymmetricCryptoKey_ImportSecret(_Handle, Buffer, Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInSymmetricCryptoKey::ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInSymmetricCryptoKey_ExportPublic(_Handle, Buffer, &Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInSymmetricCryptoKey::ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInSymmetricCryptoKey_ExportPublic(_Handle, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElBuiltInSymmetricCryptoKey::ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params)
{
	SBCheckError(TElBuiltInSymmetricCryptoKey_ExportSecret(_Handle, Buffer, &Size, Params.getHandle()));
}

SB_INLINE void TElBuiltInSymmetricCryptoKey::ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params)
{
	SBCheckError(TElBuiltInSymmetricCryptoKey_ExportSecret(_Handle, Buffer, &Size, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElBuiltInSymmetricCryptoKey::ChangeAlgorithm(int32_t Algorithm)
{
	SBCheckError(TElBuiltInSymmetricCryptoKey_ChangeAlgorithm(_Handle, Algorithm));
}

SB_INLINE void TElBuiltInSymmetricCryptoKey::Reset()
{
	SBCheckError(TElBuiltInSymmetricCryptoKey_Reset(_Handle));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElBuiltInSymmetricCryptoKey::Clone(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInSymmetricCryptoKey_Clone(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElBuiltInSymmetricCryptoKey::Clone(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInSymmetricCryptoKey_Clone(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElCustomCryptoKeyHandle TElBuiltInSymmetricCryptoKey::ClonePublic(TElRelativeDistinguishedName &Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInSymmetricCryptoKey_ClonePublic(_Handle, Params.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCryptoKeyHandle TElBuiltInSymmetricCryptoKey::ClonePublic(TElRelativeDistinguishedName *Params)
{
	TElCustomCryptoKeyHandle OutResult;
	SBCheckError(TElBuiltInSymmetricCryptoKey_ClonePublic(_Handle, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElBuiltInSymmetricCryptoKey::ClearPublic()
{
	SBCheckError(TElBuiltInSymmetricCryptoKey_ClearPublic(_Handle));
}

SB_INLINE void TElBuiltInSymmetricCryptoKey::ClearSecret()
{
	SBCheckError(TElBuiltInSymmetricCryptoKey_ClearSecret(_Handle));
}

void TElBuiltInSymmetricCryptoKey::GetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBuiltInSymmetricCryptoKey_GetKeyProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Default), (int32_t)Default.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(51928306, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBuiltInSymmetricCryptoKey::SetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBuiltInSymmetricCryptoKey_SetKeyProp(_Handle, SB_STD_VECTOR_FRONT_ADR(PropID), (int32_t)PropID.size(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
bool TElBuiltInSymmetricCryptoKey::Equals(TElCustomCryptoKey &Source, bool PublicOnly, TElRelativeDistinguishedName &Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInSymmetricCryptoKey_Equals(_Handle, Source.getHandle(), (int8_t)PublicOnly, Params.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBuiltInSymmetricCryptoKey::Equals(TElCustomCryptoKey *Source, bool PublicOnly, TElRelativeDistinguishedName *Params)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInSymmetricCryptoKey_Equals(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (int8_t)PublicOnly, (Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

TElBuiltInSymmetricCryptoKey::TElBuiltInSymmetricCryptoKey(TElBuiltInSymmetricCryptoKeyHandle handle, TElOwnHandle ownHandle) : TElBuiltInCryptoKey(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElBuiltInSymmetricCryptoKey::TElBuiltInSymmetricCryptoKey(TElCustomCryptoProvider &CryptoProvider) : TElBuiltInCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInSymmetricCryptoKey_Create(CryptoProvider.getHandle(), &_Handle));
}

TElBuiltInSymmetricCryptoKey::TElBuiltInSymmetricCryptoKey(TElCustomCryptoProvider *CryptoProvider) : TElBuiltInCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInSymmetricCryptoKey_Create((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElBuiltInSymmetricCryptoKey::TElBuiltInSymmetricCryptoKey(TElCustomCryptoProvider &CryptoProvider, const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams) : TElBuiltInCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInSymmetricCryptoKey_Create_1(CryptoProvider.getHandle(), SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), &_Handle));
}

TElBuiltInSymmetricCryptoKey::TElBuiltInSymmetricCryptoKey(TElCustomCryptoProvider *CryptoProvider, const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams) : TElBuiltInCryptoKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInSymmetricCryptoKey_Create_1((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#endif /* SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTO

SB_INLINE void TElBuiltInSymmetricCrypto::InitializeEncryption()
{
	SBCheckError(TElBuiltInSymmetricCrypto_InitializeEncryption(_Handle));
}

SB_INLINE void TElBuiltInSymmetricCrypto::InitializeDecryption()
{
	SBCheckError(TElBuiltInSymmetricCrypto_InitializeDecryption(_Handle));
}

SB_INLINE void TElBuiltInSymmetricCrypto::Encrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElBuiltInSymmetricCrypto_Encrypt(_Handle, InBuffer, InSize, OutBuffer, &OutSize));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElBuiltInSymmetricCrypto::Encrypt(TStream &InStream, TStream &OutStream)
{
	SBCheckError(TElBuiltInSymmetricCrypto_Encrypt_1(_Handle, InStream.getHandle(), OutStream.getHandle()));
}

SB_INLINE void TElBuiltInSymmetricCrypto::Encrypt(TStream *InStream, TStream *OutStream)
{
	SBCheckError(TElBuiltInSymmetricCrypto_Encrypt_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElBuiltInSymmetricCrypto::EncryptUpdate(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElBuiltInSymmetricCrypto_EncryptUpdate(_Handle, InBuffer, InSize, OutBuffer, &OutSize));
}

SB_INLINE void TElBuiltInSymmetricCrypto::FinalizeEncryption(void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElBuiltInSymmetricCrypto_FinalizeEncryption(_Handle, OutBuffer, &OutSize));
}

SB_INLINE void TElBuiltInSymmetricCrypto::Decrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElBuiltInSymmetricCrypto_Decrypt(_Handle, InBuffer, InSize, OutBuffer, &OutSize));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElBuiltInSymmetricCrypto::Decrypt(TStream &InStream, TStream &OutStream, int32_t InCount)
{
	SBCheckError(TElBuiltInSymmetricCrypto_Decrypt_1(_Handle, InStream.getHandle(), OutStream.getHandle(), InCount));
}

SB_INLINE void TElBuiltInSymmetricCrypto::Decrypt(TStream *InStream, TStream *OutStream, int32_t InCount)
{
	SBCheckError(TElBuiltInSymmetricCrypto_Decrypt_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, InCount));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElBuiltInSymmetricCrypto::DecryptUpdate(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElBuiltInSymmetricCrypto_DecryptUpdate(_Handle, InBuffer, InSize, OutBuffer, &OutSize));
}

SB_INLINE void TElBuiltInSymmetricCrypto::FinalizeDecryption(void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElBuiltInSymmetricCrypto_FinalizeDecryption(_Handle, OutBuffer, &OutSize));
}

SB_INLINE TClassHandle TElBuiltInSymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBuiltInSymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
TElCustomCryptoKey* TElBuiltInSymmetricCrypto::get_KeyMaterial()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBuiltInSymmetricCrypto_get_KeyMaterial(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyMaterial)
		this->_Inst_KeyMaterial = new TElCustomCryptoKey(hOutResult, ohFalse);
	else
		this->_Inst_KeyMaterial->updateHandle(hOutResult);
	return this->_Inst_KeyMaterial;
}

SB_INLINE void TElBuiltInSymmetricCrypto::set_KeyMaterial(TElCustomCryptoKey &Value)
{
	SBCheckError(TElBuiltInSymmetricCrypto_set_KeyMaterial(_Handle, Value.getHandle()));
}

SB_INLINE void TElBuiltInSymmetricCrypto::set_KeyMaterial(TElCustomCryptoKey *Value)
{
	SBCheckError(TElBuiltInSymmetricCrypto_set_KeyMaterial(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

bool TElBuiltInSymmetricCrypto::get_AssociatedData()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInSymmetricCrypto_get_AssociatedData(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBuiltInSymmetricCrypto::set_AssociatedData(bool Value)
{
	SBCheckError(TElBuiltInSymmetricCrypto_set_AssociatedData(_Handle, (int8_t)Value));
}

SB_INLINE int64_t TElBuiltInSymmetricCrypto::get_AssociatedDataSize()
{
	int64_t OutResult;
	SBCheckError(TElBuiltInSymmetricCrypto_get_AssociatedDataSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBuiltInSymmetricCrypto::set_AssociatedDataSize(int64_t Value)
{
	SBCheckError(TElBuiltInSymmetricCrypto_set_AssociatedDataSize(_Handle, Value));
}

SB_INLINE int64_t TElBuiltInSymmetricCrypto::get_PayloadSize()
{
	int64_t OutResult;
	SBCheckError(TElBuiltInSymmetricCrypto_get_PayloadSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBuiltInSymmetricCrypto::set_PayloadSize(int64_t Value)
{
	SBCheckError(TElBuiltInSymmetricCrypto_set_PayloadSize(_Handle, Value));
}

void TElBuiltInSymmetricCrypto::get_Nonce(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBuiltInSymmetricCrypto_get_Nonce(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-266579429, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBuiltInSymmetricCrypto::set_Nonce(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBuiltInSymmetricCrypto_set_Nonce(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElBuiltInSymmetricCrypto::get_TagSize()
{
	int32_t OutResult;
	SBCheckError(TElBuiltInSymmetricCrypto_get_TagSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBuiltInSymmetricCrypto::set_TagSize(int32_t Value)
{
	SBCheckError(TElBuiltInSymmetricCrypto_set_TagSize(_Handle, Value));
}

TSBBuiltInSymmetricCryptoMode TElBuiltInSymmetricCrypto::get_Mode()
{
	TSBBuiltInSymmetricCryptoModeRaw OutResultRaw = 0;
	SBCheckError(TElBuiltInSymmetricCrypto_get_Mode(_Handle, &OutResultRaw));
	return (TSBBuiltInSymmetricCryptoMode)OutResultRaw;
}

SB_INLINE int32_t TElBuiltInSymmetricCrypto::get_BlockSize()
{
	int32_t OutResult;
	SBCheckError(TElBuiltInSymmetricCrypto_get_BlockSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElBuiltInSymmetricCrypto::get_KeySize()
{
	int32_t OutResult;
	SBCheckError(TElBuiltInSymmetricCrypto_get_KeySize(_Handle, &OutResult));
	return OutResult;
}

TSBBuiltInSymmetricCipherPadding TElBuiltInSymmetricCrypto::get_Padding()
{
	TSBBuiltInSymmetricCipherPaddingRaw OutResultRaw = 0;
	SBCheckError(TElBuiltInSymmetricCrypto_get_Padding(_Handle, &OutResultRaw));
	return (TSBBuiltInSymmetricCipherPadding)OutResultRaw;
}

SB_INLINE void TElBuiltInSymmetricCrypto::set_Padding(TSBBuiltInSymmetricCipherPadding Value)
{
	SBCheckError(TElBuiltInSymmetricCrypto_set_Padding(_Handle, (TSBBuiltInSymmetricCipherPaddingRaw)Value));
}

bool TElBuiltInSymmetricCrypto::get_CTRLittleEndian()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInSymmetricCrypto_get_CTRLittleEndian(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBuiltInSymmetricCrypto::set_CTRLittleEndian(bool Value)
{
	SBCheckError(TElBuiltInSymmetricCrypto_set_CTRLittleEndian(_Handle, (int8_t)Value));
}

bool TElBuiltInSymmetricCrypto::get_IsStreamCipher()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInSymmetricCrypto_get_IsStreamCipher(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBuiltInSymmetricCrypto::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElBuiltInSymmetricCrypto_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElBuiltInSymmetricCrypto::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElBuiltInSymmetricCrypto_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

void TElBuiltInSymmetricCrypto::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
	this->_Inst_KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */
}

TElBuiltInSymmetricCrypto::TElBuiltInSymmetricCrypto(TElBuiltInSymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElBuiltInSymmetricCrypto::TElBuiltInSymmetricCrypto(int32_t AlgID, TSBBuiltInSymmetricCryptoMode Mode) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBuiltInSymmetricCrypto_Create(AlgID, (TSBBuiltInSymmetricCryptoModeRaw)Mode, &_Handle));
}

TElBuiltInSymmetricCrypto::TElBuiltInSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBBuiltInSymmetricCryptoMode Mode) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBuiltInSymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBBuiltInSymmetricCryptoModeRaw)Mode, &_Handle));
}

TElBuiltInSymmetricCrypto::TElBuiltInSymmetricCrypto(TSBBuiltInSymmetricCryptoMode Mode) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBuiltInSymmetricCrypto_Create_2((TSBBuiltInSymmetricCryptoModeRaw)Mode, &_Handle));
}

TElBuiltInSymmetricCrypto::~TElBuiltInSymmetricCrypto()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
	delete this->_Inst_KeyMaterial;
	this->_Inst_KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */
}
#endif /* SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTOFACTORY

SB_INLINE void TElBuiltInSymmetricCryptoFactory::RegisterClass(TElBuiltInSymmetricCryptoClassHandle Cls)
{
	SBCheckError(TElBuiltInSymmetricCryptoFactory_RegisterClass(_Handle, Cls));
}

#ifdef SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTO
SB_INLINE TElBuiltInSymmetricCryptoHandle TElBuiltInSymmetricCryptoFactory::CreateInstance(const std::vector<uint8_t> &OID, TSBBuiltInSymmetricCryptoMode Mode)
{
	TElBuiltInSymmetricCryptoHandle OutResult;
	SBCheckError(TElBuiltInSymmetricCryptoFactory_CreateInstance(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (TSBBuiltInSymmetricCryptoModeRaw)Mode, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTO
SB_INLINE TElBuiltInSymmetricCryptoHandle TElBuiltInSymmetricCryptoFactory::CreateInstance(int32_t Alg, TSBBuiltInSymmetricCryptoMode Mode)
{
	TElBuiltInSymmetricCryptoHandle OutResult;
	SBCheckError(TElBuiltInSymmetricCryptoFactory_CreateInstance_1(_Handle, Alg, (TSBBuiltInSymmetricCryptoModeRaw)Mode, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTO
SB_INLINE TElBuiltInSymmetricCryptoHandle TElBuiltInSymmetricCryptoFactory::CreateInstance(int32_t Alg, int32_t MacAlg, TSBBuiltInSymmetricCryptoMode Mode)
{
	TElBuiltInSymmetricCryptoHandle OutResult;
	SBCheckError(TElBuiltInSymmetricCryptoFactory_CreateInstance_2(_Handle, Alg, MacAlg, (TSBBuiltInSymmetricCryptoModeRaw)Mode, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTO */

bool TElBuiltInSymmetricCryptoFactory::IsAlgorithmSupported(const std::vector<uint8_t> &OID)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInSymmetricCryptoFactory_IsAlgorithmSupported(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBuiltInSymmetricCryptoFactory::IsAlgorithmSupported(int32_t Alg)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInSymmetricCryptoFactory_IsAlgorithmSupported_1(_Handle, Alg, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBuiltInSymmetricCryptoFactory::IsAlgorithmSupported(int32_t Alg, int32_t MacAlg)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInSymmetricCryptoFactory_IsAlgorithmSupported_2(_Handle, Alg, MacAlg, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBuiltInSymmetricCryptoFactory::GetDefaultKeyAndBlockLengths(int32_t Alg, int32_t &KeyLen, int32_t &BlockLen)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInSymmetricCryptoFactory_GetDefaultKeyAndBlockLengths(_Handle, Alg, &KeyLen, &BlockLen, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBuiltInSymmetricCryptoFactory::GetDefaultKeyAndBlockLengths(const std::vector<uint8_t> &OID, int32_t &KeyLen, int32_t &BlockLen)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInSymmetricCryptoFactory_GetDefaultKeyAndBlockLengths_1(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &KeyLen, &BlockLen, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TElBuiltInSymmetricCryptoClassHandle TElBuiltInSymmetricCryptoFactory::get_RegisteredClasses(int32_t Index)
{
	TElBuiltInSymmetricCryptoClassHandle OutResult;
	SBCheckError(TElBuiltInSymmetricCryptoFactory_get_RegisteredClasses(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElBuiltInSymmetricCryptoFactory::get_RegisteredClassCount()
{
	int32_t OutResult;
	SBCheckError(TElBuiltInSymmetricCryptoFactory_get_RegisteredClassCount(_Handle, &OutResult));
	return OutResult;
}

TElBuiltInSymmetricCryptoFactory::TElBuiltInSymmetricCryptoFactory(TElBuiltInSymmetricCryptoFactoryHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElBuiltInSymmetricCryptoFactory::TElBuiltInSymmetricCryptoFactory() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInSymmetricCryptoFactory_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELBUILTINSYMMETRICCRYPTOFACTORY */

#ifdef SB_USE_CLASS_TELBUILTINIDENTITYSYMMETRICCRYPTO

SB_INLINE TClassHandle TElBuiltInIdentitySymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBuiltInIdentitySymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

TElBuiltInIdentitySymmetricCrypto::TElBuiltInIdentitySymmetricCrypto(TElBuiltInIdentitySymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElBuiltInSymmetricCrypto(handle, ownHandle)
{
}

TElBuiltInIdentitySymmetricCrypto::TElBuiltInIdentitySymmetricCrypto(int32_t AlgID, TSBBuiltInSymmetricCryptoMode Mode) : TElBuiltInSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInIdentitySymmetricCrypto_Create(AlgID, (TSBBuiltInSymmetricCryptoModeRaw)Mode, &_Handle));
}

TElBuiltInIdentitySymmetricCrypto::TElBuiltInIdentitySymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBBuiltInSymmetricCryptoMode Mode) : TElBuiltInSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInIdentitySymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBBuiltInSymmetricCryptoModeRaw)Mode, &_Handle));
}

TElBuiltInIdentitySymmetricCrypto::TElBuiltInIdentitySymmetricCrypto(TSBBuiltInSymmetricCryptoMode Mode) : TElBuiltInSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInIdentitySymmetricCrypto_Create_2((TSBBuiltInSymmetricCryptoModeRaw)Mode, &_Handle));
}

#endif /* SB_USE_CLASS_TELBUILTINIDENTITYSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINRC4SYMMETRICCRYPTO

SB_INLINE void TElBuiltInRC4SymmetricCrypto::InitializeEncryption()
{
	SBCheckError(TElBuiltInRC4SymmetricCrypto_InitializeEncryption(_Handle));
}

SB_INLINE void TElBuiltInRC4SymmetricCrypto::InitializeDecryption()
{
	SBCheckError(TElBuiltInRC4SymmetricCrypto_InitializeDecryption(_Handle));
}

SB_INLINE TClassHandle TElBuiltInRC4SymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBuiltInRC4SymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElBuiltInRC4SymmetricCrypto::get_SkipKeystreamBytes()
{
	int32_t OutResult;
	SBCheckError(TElBuiltInRC4SymmetricCrypto_get_SkipKeystreamBytes(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBuiltInRC4SymmetricCrypto::set_SkipKeystreamBytes(int32_t Value)
{
	SBCheckError(TElBuiltInRC4SymmetricCrypto_set_SkipKeystreamBytes(_Handle, Value));
}

TElBuiltInRC4SymmetricCrypto::TElBuiltInRC4SymmetricCrypto(TElBuiltInRC4SymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElBuiltInSymmetricCrypto(handle, ownHandle)
{
}

TElBuiltInRC4SymmetricCrypto::TElBuiltInRC4SymmetricCrypto(int32_t AlgID, TSBBuiltInSymmetricCryptoMode Mode) : TElBuiltInSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInRC4SymmetricCrypto_Create(AlgID, (TSBBuiltInSymmetricCryptoModeRaw)Mode, &_Handle));
}

TElBuiltInRC4SymmetricCrypto::TElBuiltInRC4SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBBuiltInSymmetricCryptoMode Mode) : TElBuiltInSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInRC4SymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBBuiltInSymmetricCryptoModeRaw)Mode, &_Handle));
}

TElBuiltInRC4SymmetricCrypto::TElBuiltInRC4SymmetricCrypto(TSBBuiltInSymmetricCryptoMode Mode) : TElBuiltInSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInRC4SymmetricCrypto_Create_2((TSBBuiltInSymmetricCryptoModeRaw)Mode, &_Handle));
}

#endif /* SB_USE_CLASS_TELBUILTINRC4SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINGOST28147SYMMETRICCRYPTO

SB_INLINE TClassHandle TElBuiltInGOST28147SymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBuiltInGOST28147SymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE void TElBuiltInGOST28147SymmetricCrypto::set_ParamSet(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBuiltInGOST28147SymmetricCrypto_set_ParamSet(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE void TElBuiltInGOST28147SymmetricCrypto::set_SBoxes(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBuiltInGOST28147SymmetricCrypto_set_SBoxes(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElBuiltInGOST28147SymmetricCrypto::get_UseKeyMeshing()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBuiltInGOST28147SymmetricCrypto_get_UseKeyMeshing(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBuiltInGOST28147SymmetricCrypto::set_UseKeyMeshing(bool Value)
{
	SBCheckError(TElBuiltInGOST28147SymmetricCrypto_set_UseKeyMeshing(_Handle, (int8_t)Value));
}

TElBuiltInGOST28147SymmetricCrypto::TElBuiltInGOST28147SymmetricCrypto(TElBuiltInGOST28147SymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElBuiltInSymmetricCrypto(handle, ownHandle)
{
}

TElBuiltInGOST28147SymmetricCrypto::TElBuiltInGOST28147SymmetricCrypto(int32_t AlgID, TSBBuiltInSymmetricCryptoMode Mode) : TElBuiltInSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInGOST28147SymmetricCrypto_Create(AlgID, (TSBBuiltInSymmetricCryptoModeRaw)Mode, &_Handle));
}

TElBuiltInGOST28147SymmetricCrypto::TElBuiltInGOST28147SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBBuiltInSymmetricCryptoMode Mode) : TElBuiltInSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInGOST28147SymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBBuiltInSymmetricCryptoModeRaw)Mode, &_Handle));
}

TElBuiltInGOST28147SymmetricCrypto::TElBuiltInGOST28147SymmetricCrypto(TSBBuiltInSymmetricCryptoMode Mode) : TElBuiltInSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInGOST28147SymmetricCrypto_Create_2((TSBBuiltInSymmetricCryptoModeRaw)Mode, &_Handle));
}

#endif /* SB_USE_CLASS_TELBUILTINGOST28147SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINCHACHA20SYMMETRICCRYPTO

SB_INLINE TClassHandle TElBuiltInChaCha20SymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBuiltInChaCha20SymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE uint32_t TElBuiltInChaCha20SymmetricCrypto::get_Counter()
{
	uint32_t OutResult;
	SBCheckError(TElBuiltInChaCha20SymmetricCrypto_get_Counter(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBuiltInChaCha20SymmetricCrypto::set_Counter(uint32_t Value)
{
	SBCheckError(TElBuiltInChaCha20SymmetricCrypto_set_Counter(_Handle, Value));
}

TElBuiltInChaCha20SymmetricCrypto::TElBuiltInChaCha20SymmetricCrypto(TElBuiltInChaCha20SymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElBuiltInSymmetricCrypto(handle, ownHandle)
{
}

TElBuiltInChaCha20SymmetricCrypto::TElBuiltInChaCha20SymmetricCrypto(int32_t AlgID, TSBBuiltInSymmetricCryptoMode Mode) : TElBuiltInSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInChaCha20SymmetricCrypto_Create(AlgID, (TSBBuiltInSymmetricCryptoModeRaw)Mode, &_Handle));
}

TElBuiltInChaCha20SymmetricCrypto::TElBuiltInChaCha20SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBBuiltInSymmetricCryptoMode Mode) : TElBuiltInSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInChaCha20SymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBBuiltInSymmetricCryptoModeRaw)Mode, &_Handle));
}

TElBuiltInChaCha20SymmetricCrypto::TElBuiltInChaCha20SymmetricCrypto(TSBBuiltInSymmetricCryptoMode Mode) : TElBuiltInSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInChaCha20SymmetricCrypto_Create_2((TSBBuiltInSymmetricCryptoModeRaw)Mode, &_Handle));
}

#endif /* SB_USE_CLASS_TELBUILTINCHACHA20SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINAEADCHACHA20POLY1305SYMMETRICCRYPTO

SB_INLINE TClassHandle TElBuiltInAEADChaCha20Poly1305SymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBuiltInAEADChaCha20Poly1305SymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

void TElBuiltInAEADChaCha20Poly1305SymmetricCrypto::get_AAD(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBuiltInAEADChaCha20Poly1305SymmetricCrypto_get_AAD(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(596947906, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBuiltInAEADChaCha20Poly1305SymmetricCrypto::set_AAD(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBuiltInAEADChaCha20Poly1305SymmetricCrypto_set_AAD(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE void TElBuiltInAEADChaCha20Poly1305SymmetricCrypto::get_Tag(TSBPoly1305Tag &OutResult)
{
	SBCheckError(TElBuiltInAEADChaCha20Poly1305SymmetricCrypto_get_Tag(_Handle, &OutResult));
}

SB_INLINE void TElBuiltInAEADChaCha20Poly1305SymmetricCrypto::set_Tag(TSBPoly1305Tag &Value)
{
	SBCheckError(TElBuiltInAEADChaCha20Poly1305SymmetricCrypto_set_Tag(_Handle, &Value));
}

TSBPoly1305Mode TElBuiltInAEADChaCha20Poly1305SymmetricCrypto::get_Poly1305Mode()
{
	TSBPoly1305ModeRaw OutResultRaw = 0;
	SBCheckError(TElBuiltInAEADChaCha20Poly1305SymmetricCrypto_get_Poly1305Mode(_Handle, &OutResultRaw));
	return (TSBPoly1305Mode)OutResultRaw;
}

SB_INLINE void TElBuiltInAEADChaCha20Poly1305SymmetricCrypto::set_Poly1305Mode(TSBPoly1305Mode Value)
{
	SBCheckError(TElBuiltInAEADChaCha20Poly1305SymmetricCrypto_set_Poly1305Mode(_Handle, (TSBPoly1305ModeRaw)Value));
}

TElBuiltInAEADChaCha20Poly1305SymmetricCrypto::TElBuiltInAEADChaCha20Poly1305SymmetricCrypto(TElBuiltInAEADChaCha20Poly1305SymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElBuiltInSymmetricCrypto(handle, ownHandle)
{
}

TElBuiltInAEADChaCha20Poly1305SymmetricCrypto::TElBuiltInAEADChaCha20Poly1305SymmetricCrypto(int32_t AlgID, TSBBuiltInSymmetricCryptoMode Mode) : TElBuiltInSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInAEADChaCha20Poly1305SymmetricCrypto_Create(AlgID, (TSBBuiltInSymmetricCryptoModeRaw)Mode, &_Handle));
}

TElBuiltInAEADChaCha20Poly1305SymmetricCrypto::TElBuiltInAEADChaCha20Poly1305SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBBuiltInSymmetricCryptoMode Mode) : TElBuiltInSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInAEADChaCha20Poly1305SymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBBuiltInSymmetricCryptoModeRaw)Mode, &_Handle));
}

TElBuiltInAEADChaCha20Poly1305SymmetricCrypto::TElBuiltInAEADChaCha20Poly1305SymmetricCrypto(TSBBuiltInSymmetricCryptoMode Mode) : TElBuiltInSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInAEADChaCha20Poly1305SymmetricCrypto_Create_2((TSBBuiltInSymmetricCryptoModeRaw)Mode, &_Handle));
}

#endif /* SB_USE_CLASS_TELBUILTINAEADCHACHA20POLY1305SYMMETRICCRYPTO */

};	/* namespace SecureBlackbox */

