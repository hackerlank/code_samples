#include "sbsymmetriccrypto.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSYMMETRICKEYMATERIAL

SB_INLINE void TElSymmetricKeyMaterial::Generate(int32_t Bits)
{
	SBCheckError(TElSymmetricKeyMaterial_Generate(_Handle, Bits));
}

SB_INLINE void TElSymmetricKeyMaterial::GenerateIV(int32_t Bits)
{
	SBCheckError(TElSymmetricKeyMaterial_GenerateIV(_Handle, Bits));
}

SB_INLINE void TElSymmetricKeyMaterial::DeriveKey(int32_t Bits, const std::string &Password)
{
	SBCheckError(TElSymmetricKeyMaterial_DeriveKey(_Handle, Bits, Password.data(), (int32_t)Password.length()));
}

SB_INLINE void TElSymmetricKeyMaterial::DeriveKey(int32_t Bits, const std::string &Password, const std::string &Salt)
{
	SBCheckError(TElSymmetricKeyMaterial_DeriveKey_1(_Handle, Bits, Password.data(), (int32_t)Password.length(), Salt.data(), (int32_t)Salt.length()));
}

SB_INLINE void TElSymmetricKeyMaterial::DeriveKey(int32_t Bits, const std::string &Password, const std::vector<uint8_t> &Salt)
{
	SBCheckError(TElSymmetricKeyMaterial_DeriveKey_2(_Handle, Bits, Password.data(), (int32_t)Password.length(), SB_STD_VECTOR_FRONT_ADR(Salt), (int32_t)Salt.size()));
}

SB_INLINE void TElSymmetricKeyMaterial::DeriveKey(int32_t Bits, const std::string &Password, const std::vector<uint8_t> &Salt, int32_t Iterations)
{
	SBCheckError(TElSymmetricKeyMaterial_DeriveKey_3(_Handle, Bits, Password.data(), (int32_t)Password.length(), SB_STD_VECTOR_FRONT_ADR(Salt), (int32_t)Salt.size(), Iterations));
}

SB_INLINE void TElSymmetricKeyMaterial::Load(void * Buffer, int32_t Size)
{
	SBCheckError(TElSymmetricKeyMaterial_Load(_Handle, Buffer, Size));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSymmetricKeyMaterial::Load(TStream &Stream, int32_t Count)
{
	SBCheckError(TElSymmetricKeyMaterial_Load_1(_Handle, Stream.getHandle(), Count));
}

SB_INLINE void TElSymmetricKeyMaterial::Load(TStream *Stream, int32_t Count)
{
	SBCheckError(TElSymmetricKeyMaterial_Load_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElSymmetricKeyMaterial::Save(void * Buffer, int32_t &Size)
{
	SBCheckError(TElSymmetricKeyMaterial_Save(_Handle, Buffer, &Size));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSymmetricKeyMaterial::Save(TStream &Stream)
{
	SBCheckError(TElSymmetricKeyMaterial_Save_1(_Handle, Stream.getHandle()));
}

SB_INLINE void TElSymmetricKeyMaterial::Save(TStream *Stream)
{
	SBCheckError(TElSymmetricKeyMaterial_Save_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifndef SB_CPU64_OR_NOT_WINDOWS
bool TElSymmetricKeyMaterial::ImportEncryptedSymmetricKeyWin32(const std::vector<uint8_t> &EncryptedKey, int32_t SymAlgorithm, int32_t PKAlgorithm, const std::vector<uint8_t> &SymAlgParams, uint32_t hProv, uint32_t hUserKey)
#endif
#ifndef SB_NOT_CPU64_OR_NOT_WINDOWS
bool TElSymmetricKeyMaterial::ImportEncryptedSymmetricKeyWin32(const std::vector<uint8_t> &EncryptedKey, int32_t SymAlgorithm, int32_t PKAlgorithm, const std::vector<uint8_t> &SymAlgParams, int64_t hProv, int64_t hUserKey)
#endif
#ifdef SB_WINDOWS
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSymmetricKeyMaterial_ImportEncryptedSymmetricKeyWin32(_Handle, SB_STD_VECTOR_FRONT_ADR(EncryptedKey), (int32_t)EncryptedKey.size(), SymAlgorithm, PKAlgorithm, SB_STD_VECTOR_FRONT_ADR(SymAlgParams), (int32_t)SymAlgParams.size(), hProv, hUserKey, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif

SB_INLINE void TElSymmetricKeyMaterial::Persistentiate()
{
	SBCheckError(TElSymmetricKeyMaterial_Persistentiate(_Handle));
}

void TElSymmetricKeyMaterial::get_Key_ByteArray(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSymmetricKeyMaterial_get_Key_ByteArray(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(462094714, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSymmetricKeyMaterial::set_Key_ByteArray(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSymmetricKeyMaterial_set_Key_ByteArray(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElSymmetricKeyMaterial::get_IV(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSymmetricKeyMaterial_get_IV(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-207535620, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSymmetricKeyMaterial::set_IV(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSymmetricKeyMaterial_set_IV(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElSymmetricKeyMaterial::get_Algorithm()
{
	int32_t OutResult;
	SBCheckError(TElSymmetricKeyMaterial_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSymmetricKeyMaterial::set_Algorithm(int32_t Value)
{
	SBCheckError(TElSymmetricKeyMaterial_set_Algorithm(_Handle, Value));
}

TElSymmetricKeyMaterial::TElSymmetricKeyMaterial(TElSymmetricKeyMaterialHandle handle, TElOwnHandle ownHandle) : TElKeyMaterial(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElSymmetricKeyMaterial::TElSymmetricKeyMaterial(TElCustomCryptoProvider &Prov) : TElKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSymmetricKeyMaterial_Create(Prov.getHandle(), &_Handle));
}

TElSymmetricKeyMaterial::TElSymmetricKeyMaterial(TElCustomCryptoProvider *Prov) : TElKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSymmetricKeyMaterial_Create((Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER
TElSymmetricKeyMaterial::TElSymmetricKeyMaterial(TElCustomCryptoKey &Key, TElCustomCryptoProvider &Prov) : TElKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSymmetricKeyMaterial_Create_1(Key.getHandle(), Prov.getHandle(), &_Handle));
}

TElSymmetricKeyMaterial::TElSymmetricKeyMaterial(TElCustomCryptoKey *Key, TElCustomCryptoProvider *Prov) : TElKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSymmetricKeyMaterial_Create_1((Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElSymmetricKeyMaterial::TElSymmetricKeyMaterial(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSymmetricKeyMaterial_Create_2(Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElSymmetricKeyMaterial::TElSymmetricKeyMaterial(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSymmetricKeyMaterial_Create_2((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElSymmetricKeyMaterial::TElSymmetricKeyMaterial(TElCustomCryptoKey &Key, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSymmetricKeyMaterial_Create_3(Key.getHandle(), Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElSymmetricKeyMaterial::TElSymmetricKeyMaterial(TElCustomCryptoKey *Key, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSymmetricKeyMaterial_Create_3((Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELSYMMETRICKEYMATERIAL */

#ifdef SB_USE_CLASS_TELSYMMETRICCRYPTO

SB_INLINE void TElSymmetricCrypto::InitializeEncryption()
{
	SBCheckError(TElSymmetricCrypto_InitializeEncryption(_Handle));
}

SB_INLINE void TElSymmetricCrypto::InitializeDecryption()
{
	SBCheckError(TElSymmetricCrypto_InitializeDecryption(_Handle));
}

SB_INLINE void TElSymmetricCrypto::Encrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElSymmetricCrypto_Encrypt(_Handle, InBuffer, InSize, OutBuffer, &OutSize));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSymmetricCrypto::Encrypt(TStream &InStream, TStream &OutStream)
{
	SBCheckError(TElSymmetricCrypto_Encrypt_1(_Handle, InStream.getHandle(), OutStream.getHandle()));
}

SB_INLINE void TElSymmetricCrypto::Encrypt(TStream *InStream, TStream *OutStream)
{
	SBCheckError(TElSymmetricCrypto_Encrypt_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElSymmetricCrypto::Encrypt(int32_t AlgID, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, TSBSymmetricCryptoMode Mode, void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSymmetricCrypto_Encrypt_2(AlgID, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(IV), (int32_t)IV.size(), (TSBSymmetricCryptoModeRaw)Mode, Buffer, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2085357991, 6, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSymmetricCrypto::Encrypt_Inst(int32_t AlgID, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, TSBSymmetricCryptoMode Mode, void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSymmetricCrypto_Encrypt_3(_Handle, AlgID, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(IV), (int32_t)IV.size(), (TSBSymmetricCryptoModeRaw)Mode, Buffer, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2085357991, 7, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSymmetricCrypto::EncryptUpdate(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElSymmetricCrypto_EncryptUpdate(_Handle, InBuffer, InSize, OutBuffer, &OutSize));
}

SB_INLINE void TElSymmetricCrypto::FinalizeEncryption(void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElSymmetricCrypto_FinalizeEncryption(_Handle, OutBuffer, &OutSize));
}

SB_INLINE void TElSymmetricCrypto::EncryptAEAD(void * AssociatedData, int32_t ADataSize, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElSymmetricCrypto_EncryptAEAD(_Handle, AssociatedData, ADataSize, InBuffer, InSize, OutBuffer, &OutSize));
}

SB_INLINE void TElSymmetricCrypto::Decrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElSymmetricCrypto_Decrypt(_Handle, InBuffer, InSize, OutBuffer, &OutSize));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSymmetricCrypto::Decrypt(TStream &InStream, TStream &OutStream, int32_t InCount)
{
	SBCheckError(TElSymmetricCrypto_Decrypt_1(_Handle, InStream.getHandle(), OutStream.getHandle(), InCount));
}

SB_INLINE void TElSymmetricCrypto::Decrypt(TStream *InStream, TStream *OutStream, int32_t InCount)
{
	SBCheckError(TElSymmetricCrypto_Decrypt_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, InCount));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElSymmetricCrypto::Decrypt(int32_t AlgID, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, TSBSymmetricCryptoMode Mode, void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSymmetricCrypto_Decrypt_2(AlgID, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(IV), (int32_t)IV.size(), (TSBSymmetricCryptoModeRaw)Mode, Buffer, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-523334556, 6, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSymmetricCrypto::Decrypt_Inst(int32_t AlgID, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, TSBSymmetricCryptoMode Mode, void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSymmetricCrypto_Decrypt_3(_Handle, AlgID, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(IV), (int32_t)IV.size(), (TSBSymmetricCryptoModeRaw)Mode, Buffer, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-523334556, 7, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSymmetricCrypto::DecryptAEAD(void * AssociatedData, int32_t ADataSize, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElSymmetricCrypto_DecryptAEAD(_Handle, AssociatedData, ADataSize, InBuffer, InSize, OutBuffer, &OutSize));
}

SB_INLINE void TElSymmetricCrypto::DecryptUpdate(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElSymmetricCrypto_DecryptUpdate(_Handle, InBuffer, InSize, OutBuffer, &OutSize));
#ifdef SB_WINDOWS
}

SB_INLINE void TElSymmetricCrypto::DecryptUpdateWin32(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElSymmetricCrypto_DecryptUpdateWin32(_Handle, InBuffer, InSize, OutBuffer, &OutSize));
#endif
}

SB_INLINE void TElSymmetricCrypto::FinalizeDecryption(void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElSymmetricCrypto_FinalizeDecryption(_Handle, OutBuffer, &OutSize));
}

SB_INLINE TClassHandle TElSymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElSymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSymmetricCrypto::get_AlgID()
{
	int32_t OutResult;
	SBCheckError(TElSymmetricCrypto_get_AlgID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSymmetricCrypto::get_MACAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElSymmetricCrypto_get_MACAlgorithm(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSYMMETRICKEYMATERIAL
TElSymmetricKeyMaterial* TElSymmetricCrypto::get_KeyMaterial()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSymmetricCrypto_get_KeyMaterial(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyMaterial)
		this->_Inst_KeyMaterial = new TElSymmetricKeyMaterial(hOutResult, ohFalse);
	else
		this->_Inst_KeyMaterial->updateHandle(hOutResult);
	return this->_Inst_KeyMaterial;
}

SB_INLINE void TElSymmetricCrypto::set_KeyMaterial(TElSymmetricKeyMaterial &Value)
{
	SBCheckError(TElSymmetricCrypto_set_KeyMaterial(_Handle, Value.getHandle()));
}

SB_INLINE void TElSymmetricCrypto::set_KeyMaterial(TElSymmetricKeyMaterial *Value)
{
	SBCheckError(TElSymmetricCrypto_set_KeyMaterial(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSYMMETRICKEYMATERIAL */

TSBSymmetricCryptoMode TElSymmetricCrypto::get_Mode()
{
	TSBSymmetricCryptoModeRaw OutResultRaw = 0;
	SBCheckError(TElSymmetricCrypto_get_Mode(_Handle, &OutResultRaw));
	return (TSBSymmetricCryptoMode)OutResultRaw;
}

SB_INLINE int32_t TElSymmetricCrypto::get_BlockSize()
{
	int32_t OutResult;
	SBCheckError(TElSymmetricCrypto_get_BlockSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSymmetricCrypto::get_KeySize()
{
	int32_t OutResult;
	SBCheckError(TElSymmetricCrypto_get_KeySize(_Handle, &OutResult));
	return OutResult;
}

TSBSymmetricCipherPadding TElSymmetricCrypto::get_Padding()
{
	TSBSymmetricCipherPaddingRaw OutResultRaw = 0;
	SBCheckError(TElSymmetricCrypto_get_Padding(_Handle, &OutResultRaw));
	return (TSBSymmetricCipherPadding)OutResultRaw;
}

SB_INLINE void TElSymmetricCrypto::set_Padding(TSBSymmetricCipherPadding Value)
{
	SBCheckError(TElSymmetricCrypto_set_Padding(_Handle, (TSBSymmetricCipherPaddingRaw)Value));
}

bool TElSymmetricCrypto::get_CTRLittleEndian()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSymmetricCrypto_get_CTRLittleEndian(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSymmetricCrypto::set_CTRLittleEndian(bool Value)
{
	SBCheckError(TElSymmetricCrypto_set_CTRLittleEndian(_Handle, (int8_t)Value));
}

void TElSymmetricCrypto::get_Nonce(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSymmetricCrypto_get_Nonce(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2125681251, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSymmetricCrypto::set_Nonce(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSymmetricCrypto_set_Nonce(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElSymmetricCrypto::get_TagSize()
{
	int32_t OutResult;
	SBCheckError(TElSymmetricCrypto_get_TagSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSymmetricCrypto::set_TagSize(int32_t Value)
{
	SBCheckError(TElSymmetricCrypto_set_TagSize(_Handle, Value));
}

SB_INLINE int32_t TElSymmetricCrypto::get_AssociatedDataSize()
{
	int32_t OutResult;
	SBCheckError(TElSymmetricCrypto_get_AssociatedDataSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSymmetricCrypto::set_AssociatedDataSize(int32_t Value)
{
	SBCheckError(TElSymmetricCrypto_set_AssociatedDataSize(_Handle, Value));
}

SB_INLINE int32_t TElSymmetricCrypto::get_PayloadSize()
{
	int32_t OutResult;
	SBCheckError(TElSymmetricCrypto_get_PayloadSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSymmetricCrypto::set_PayloadSize(int32_t Value)
{
	SBCheckError(TElSymmetricCrypto_set_PayloadSize(_Handle, Value));
}

bool TElSymmetricCrypto::get_AssociatedData()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSymmetricCrypto_get_AssociatedData(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSymmetricCrypto::set_AssociatedData(bool Value)
{
	SBCheckError(TElSymmetricCrypto_set_AssociatedData(_Handle, (int8_t)Value));
}

bool TElSymmetricCrypto::get_IsStreamCipher()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSymmetricCrypto_get_IsStreamCipher(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProvider* TElSymmetricCrypto::get_CryptoProvider()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSymmetricCrypto_get_CryptoProvider(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProvider)
		this->_Inst_CryptoProvider = new TElCustomCryptoProvider(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProvider->updateHandle(hOutResult);
	return this->_Inst_CryptoProvider;
}

SB_INLINE void TElSymmetricCrypto::set_CryptoProvider(TElCustomCryptoProvider &Value)
{
	SBCheckError(TElSymmetricCrypto_set_CryptoProvider(_Handle, Value.getHandle()));
}

SB_INLINE void TElSymmetricCrypto::set_CryptoProvider(TElCustomCryptoProvider *Value)
{
	SBCheckError(TElSymmetricCrypto_set_CryptoProvider(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElSymmetricCrypto::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSymmetricCrypto_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElSymmetricCrypto::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElSymmetricCrypto_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElSymmetricCrypto::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElSymmetricCrypto_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

SB_INLINE void TElSymmetricCrypto::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSymmetricCrypto_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSymmetricCrypto::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSymmetricCrypto_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

void TElSymmetricCrypto::initInstances()
{
#ifdef SB_USE_CLASS_TELSYMMETRICKEYMATERIAL
	this->_Inst_KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELSYMMETRICKEYMATERIAL */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}

TElSymmetricCrypto::TElSymmetricCrypto(TElSymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElCustomCrypto(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElSymmetricCrypto::TElSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElSymmetricCrypto::TElSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElSymmetricCrypto::TElSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElSymmetricCrypto::TElSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElSymmetricCrypto::TElSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElSymmetricCrypto::TElSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElSymmetricCrypto::TElSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElSymmetricCrypto::TElSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElSymmetricCrypto::TElSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElSymmetricCrypto::TElSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElSymmetricCrypto::TElSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElSymmetricCrypto::TElSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElSymmetricCrypto::TElSymmetricCrypto(int32_t AlgID, int32_t MacAlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSymmetricCrypto_Create_6(AlgID, MacAlgID, (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElSymmetricCrypto::TElSymmetricCrypto(int32_t AlgID, int32_t MacAlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSymmetricCrypto_Create_6(AlgID, MacAlgID, (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElSymmetricCrypto::TElSymmetricCrypto(int32_t AlgID, int32_t MacAlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSymmetricCrypto_Create_7(AlgID, MacAlgID, (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElSymmetricCrypto::TElSymmetricCrypto(int32_t AlgID, int32_t MacAlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSymmetricCrypto_Create_7(AlgID, MacAlgID, (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

TElSymmetricCrypto::~TElSymmetricCrypto()
{
#ifdef SB_USE_CLASS_TELSYMMETRICKEYMATERIAL
	delete this->_Inst_KeyMaterial;
	this->_Inst_KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELSYMMETRICKEYMATERIAL */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	delete this->_Inst_CryptoProvider;
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}
#endif /* SB_USE_CLASS_TELSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELSYMMETRICCRYPTOFACTORY

#ifdef SB_USE_CLASS_TELSYMMETRICCRYPTO
SB_INLINE TElSymmetricCryptoHandle TElSymmetricCryptoFactory::CreateInstance(const std::vector<uint8_t> &OID, TSBSymmetricCryptoMode Mode)
{
	TElSymmetricCryptoHandle OutResult;
	SBCheckError(TElSymmetricCryptoFactory_CreateInstance(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (TSBSymmetricCryptoModeRaw)Mode, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELSYMMETRICCRYPTO
SB_INLINE TElSymmetricCryptoHandle TElSymmetricCryptoFactory::CreateInstance(int32_t Alg, TSBSymmetricCryptoMode Mode)
{
	TElSymmetricCryptoHandle OutResult;
	SBCheckError(TElSymmetricCryptoFactory_CreateInstance_1(_Handle, Alg, (TSBSymmetricCryptoModeRaw)Mode, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELSYMMETRICCRYPTO
SB_INLINE TElSymmetricCryptoHandle TElSymmetricCryptoFactory::CreateInstance(int32_t Alg, int32_t Mac, TSBSymmetricCryptoMode Mode)
{
	TElSymmetricCryptoHandle OutResult;
	SBCheckError(TElSymmetricCryptoFactory_CreateInstance_2(_Handle, Alg, Mac, (TSBSymmetricCryptoModeRaw)Mode, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSYMMETRICCRYPTO */

bool TElSymmetricCryptoFactory::IsAlgorithmSupported(const std::vector<uint8_t> &OID)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSymmetricCryptoFactory_IsAlgorithmSupported(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSymmetricCryptoFactory::IsAlgorithmSupported(int32_t Alg)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSymmetricCryptoFactory_IsAlgorithmSupported_1(_Handle, Alg, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSymmetricCryptoFactory::GetDefaultKeyAndBlockLengths(int32_t Alg, int32_t &KeyLen, int32_t &BlockLen)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSymmetricCryptoFactory_GetDefaultKeyAndBlockLengths(_Handle, Alg, &KeyLen, &BlockLen, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSymmetricCryptoFactory::GetDefaultKeyAndBlockLengths(const std::vector<uint8_t> &OID, int32_t &KeyLen, int32_t &BlockLen)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSymmetricCryptoFactory_GetDefaultKeyAndBlockLengths_1(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &KeyLen, &BlockLen, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProvider* TElSymmetricCryptoFactory::get_CryptoProvider()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSymmetricCryptoFactory_get_CryptoProvider(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProvider)
		this->_Inst_CryptoProvider = new TElCustomCryptoProvider(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProvider->updateHandle(hOutResult);
	return this->_Inst_CryptoProvider;
}

SB_INLINE void TElSymmetricCryptoFactory::set_CryptoProvider(TElCustomCryptoProvider &Value)
{
	SBCheckError(TElSymmetricCryptoFactory_set_CryptoProvider(_Handle, Value.getHandle()));
}

SB_INLINE void TElSymmetricCryptoFactory::set_CryptoProvider(TElCustomCryptoProvider *Value)
{
	SBCheckError(TElSymmetricCryptoFactory_set_CryptoProvider(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElSymmetricCryptoFactory::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSymmetricCryptoFactory_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElSymmetricCryptoFactory::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElSymmetricCryptoFactory_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElSymmetricCryptoFactory::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElSymmetricCryptoFactory_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

void TElSymmetricCryptoFactory::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}

TElSymmetricCryptoFactory::TElSymmetricCryptoFactory(TElSymmetricCryptoFactoryHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElSymmetricCryptoFactory::TElSymmetricCryptoFactory() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSymmetricCryptoFactory_Create(&_Handle));
}

TElSymmetricCryptoFactory::~TElSymmetricCryptoFactory()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	delete this->_Inst_CryptoProvider;
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}
#endif /* SB_USE_CLASS_TELSYMMETRICCRYPTOFACTORY */

#ifdef SB_USE_CLASS_TELAESSYMMETRICCRYPTO

SB_INLINE TClassHandle TElAESSymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElAESSymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

TElAESSymmetricCrypto::TElAESSymmetricCrypto(TElAESSymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElSymmetricCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElAESSymmetricCrypto::TElAESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAESSymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElAESSymmetricCrypto::TElAESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAESSymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElAESSymmetricCrypto::TElAESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAESSymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElAESSymmetricCrypto::TElAESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAESSymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElAESSymmetricCrypto::TElAESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAESSymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElAESSymmetricCrypto::TElAESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAESSymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElAESSymmetricCrypto::TElAESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAESSymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElAESSymmetricCrypto::TElAESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAESSymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElAESSymmetricCrypto::TElAESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAESSymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElAESSymmetricCrypto::TElAESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAESSymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElAESSymmetricCrypto::TElAESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAESSymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElAESSymmetricCrypto::TElAESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAESSymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELAESSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELBLOWFISHSYMMETRICCRYPTO

SB_INLINE TClassHandle TElBlowfishSymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBlowfishSymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

TElBlowfishSymmetricCrypto::TElBlowfishSymmetricCrypto(TElBlowfishSymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElSymmetricCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElBlowfishSymmetricCrypto::TElBlowfishSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBlowfishSymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElBlowfishSymmetricCrypto::TElBlowfishSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBlowfishSymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElBlowfishSymmetricCrypto::TElBlowfishSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBlowfishSymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElBlowfishSymmetricCrypto::TElBlowfishSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBlowfishSymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElBlowfishSymmetricCrypto::TElBlowfishSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBlowfishSymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElBlowfishSymmetricCrypto::TElBlowfishSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBlowfishSymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElBlowfishSymmetricCrypto::TElBlowfishSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBlowfishSymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElBlowfishSymmetricCrypto::TElBlowfishSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBlowfishSymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElBlowfishSymmetricCrypto::TElBlowfishSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBlowfishSymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElBlowfishSymmetricCrypto::TElBlowfishSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBlowfishSymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElBlowfishSymmetricCrypto::TElBlowfishSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBlowfishSymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElBlowfishSymmetricCrypto::TElBlowfishSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBlowfishSymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELBLOWFISHSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELTWOFISHSYMMETRICCRYPTO

SB_INLINE TClassHandle TElTwofishSymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElTwofishSymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

TElTwofishSymmetricCrypto::TElTwofishSymmetricCrypto(TElTwofishSymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElSymmetricCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElTwofishSymmetricCrypto::TElTwofishSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTwofishSymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElTwofishSymmetricCrypto::TElTwofishSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTwofishSymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElTwofishSymmetricCrypto::TElTwofishSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTwofishSymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElTwofishSymmetricCrypto::TElTwofishSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTwofishSymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElTwofishSymmetricCrypto::TElTwofishSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTwofishSymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElTwofishSymmetricCrypto::TElTwofishSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTwofishSymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElTwofishSymmetricCrypto::TElTwofishSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTwofishSymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElTwofishSymmetricCrypto::TElTwofishSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTwofishSymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElTwofishSymmetricCrypto::TElTwofishSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTwofishSymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElTwofishSymmetricCrypto::TElTwofishSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTwofishSymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElTwofishSymmetricCrypto::TElTwofishSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTwofishSymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElTwofishSymmetricCrypto::TElTwofishSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTwofishSymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELTWOFISHSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELIDEASYMMETRICCRYPTO

SB_INLINE TClassHandle TElIDEASymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElIDEASymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

TElIDEASymmetricCrypto::TElIDEASymmetricCrypto(TElIDEASymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElSymmetricCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElIDEASymmetricCrypto::TElIDEASymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIDEASymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElIDEASymmetricCrypto::TElIDEASymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIDEASymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElIDEASymmetricCrypto::TElIDEASymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIDEASymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElIDEASymmetricCrypto::TElIDEASymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIDEASymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElIDEASymmetricCrypto::TElIDEASymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIDEASymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElIDEASymmetricCrypto::TElIDEASymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIDEASymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElIDEASymmetricCrypto::TElIDEASymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIDEASymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElIDEASymmetricCrypto::TElIDEASymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIDEASymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElIDEASymmetricCrypto::TElIDEASymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIDEASymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElIDEASymmetricCrypto::TElIDEASymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIDEASymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElIDEASymmetricCrypto::TElIDEASymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIDEASymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElIDEASymmetricCrypto::TElIDEASymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIDEASymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELIDEASYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELCAST128SYMMETRICCRYPTO

SB_INLINE TClassHandle TElCAST128SymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElCAST128SymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

TElCAST128SymmetricCrypto::TElCAST128SymmetricCrypto(TElCAST128SymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElSymmetricCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCAST128SymmetricCrypto::TElCAST128SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCAST128SymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElCAST128SymmetricCrypto::TElCAST128SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCAST128SymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCAST128SymmetricCrypto::TElCAST128SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCAST128SymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElCAST128SymmetricCrypto::TElCAST128SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCAST128SymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCAST128SymmetricCrypto::TElCAST128SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCAST128SymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElCAST128SymmetricCrypto::TElCAST128SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCAST128SymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCAST128SymmetricCrypto::TElCAST128SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCAST128SymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElCAST128SymmetricCrypto::TElCAST128SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCAST128SymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCAST128SymmetricCrypto::TElCAST128SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCAST128SymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElCAST128SymmetricCrypto::TElCAST128SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCAST128SymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCAST128SymmetricCrypto::TElCAST128SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCAST128SymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElCAST128SymmetricCrypto::TElCAST128SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCAST128SymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELCAST128SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELRC2SYMMETRICCRYPTO

SB_INLINE TClassHandle TElRC2SymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElRC2SymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

TElRC2SymmetricCrypto::TElRC2SymmetricCrypto(TElRC2SymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElSymmetricCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElRC2SymmetricCrypto::TElRC2SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC2SymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElRC2SymmetricCrypto::TElRC2SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC2SymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElRC2SymmetricCrypto::TElRC2SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC2SymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElRC2SymmetricCrypto::TElRC2SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC2SymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElRC2SymmetricCrypto::TElRC2SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC2SymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElRC2SymmetricCrypto::TElRC2SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC2SymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElRC2SymmetricCrypto::TElRC2SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC2SymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElRC2SymmetricCrypto::TElRC2SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC2SymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElRC2SymmetricCrypto::TElRC2SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC2SymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElRC2SymmetricCrypto::TElRC2SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC2SymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElRC2SymmetricCrypto::TElRC2SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC2SymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElRC2SymmetricCrypto::TElRC2SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC2SymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELRC2SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELRC4SYMMETRICCRYPTO

SB_INLINE void TElRC4SymmetricCrypto::InitializeEncryption()
{
	SBCheckError(TElRC4SymmetricCrypto_InitializeEncryption(_Handle));
}

SB_INLINE void TElRC4SymmetricCrypto::InitializeDecryption()
{
	SBCheckError(TElRC4SymmetricCrypto_InitializeDecryption(_Handle));
}

SB_INLINE TClassHandle TElRC4SymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElRC4SymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElRC4SymmetricCrypto::get_SkipKeystreamBytes()
{
	int32_t OutResult;
	SBCheckError(TElRC4SymmetricCrypto_get_SkipKeystreamBytes(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRC4SymmetricCrypto::set_SkipKeystreamBytes(int32_t Value)
{
	SBCheckError(TElRC4SymmetricCrypto_set_SkipKeystreamBytes(_Handle, Value));
}

TElRC4SymmetricCrypto::TElRC4SymmetricCrypto(TElRC4SymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElSymmetricCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElRC4SymmetricCrypto::TElRC4SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC4SymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElRC4SymmetricCrypto::TElRC4SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC4SymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElRC4SymmetricCrypto::TElRC4SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC4SymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElRC4SymmetricCrypto::TElRC4SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC4SymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElRC4SymmetricCrypto::TElRC4SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC4SymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElRC4SymmetricCrypto::TElRC4SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC4SymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElRC4SymmetricCrypto::TElRC4SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC4SymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElRC4SymmetricCrypto::TElRC4SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC4SymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElRC4SymmetricCrypto::TElRC4SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC4SymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElRC4SymmetricCrypto::TElRC4SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC4SymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElRC4SymmetricCrypto::TElRC4SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC4SymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElRC4SymmetricCrypto::TElRC4SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRC4SymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELRC4SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELDESSYMMETRICCRYPTO

SB_INLINE TClassHandle TElDESSymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElDESSymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

TElDESSymmetricCrypto::TElDESSymmetricCrypto(TElDESSymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElSymmetricCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElDESSymmetricCrypto::TElDESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDESSymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElDESSymmetricCrypto::TElDESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDESSymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElDESSymmetricCrypto::TElDESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDESSymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElDESSymmetricCrypto::TElDESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDESSymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElDESSymmetricCrypto::TElDESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDESSymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElDESSymmetricCrypto::TElDESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDESSymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElDESSymmetricCrypto::TElDESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDESSymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElDESSymmetricCrypto::TElDESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDESSymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElDESSymmetricCrypto::TElDESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDESSymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElDESSymmetricCrypto::TElDESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDESSymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElDESSymmetricCrypto::TElDESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDESSymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElDESSymmetricCrypto::TElDESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDESSymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELDESSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TEL3DESSYMMETRICCRYPTO

SB_INLINE TClassHandle TEl3DESSymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TEl3DESSymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

TEl3DESSymmetricCrypto::TEl3DESSymmetricCrypto(TEl3DESSymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElSymmetricCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TEl3DESSymmetricCrypto::TEl3DESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TEl3DESSymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TEl3DESSymmetricCrypto::TEl3DESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TEl3DESSymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TEl3DESSymmetricCrypto::TEl3DESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TEl3DESSymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TEl3DESSymmetricCrypto::TEl3DESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TEl3DESSymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TEl3DESSymmetricCrypto::TEl3DESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TEl3DESSymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TEl3DESSymmetricCrypto::TEl3DESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TEl3DESSymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TEl3DESSymmetricCrypto::TEl3DESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TEl3DESSymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TEl3DESSymmetricCrypto::TEl3DESSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TEl3DESSymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TEl3DESSymmetricCrypto::TEl3DESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TEl3DESSymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TEl3DESSymmetricCrypto::TEl3DESSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TEl3DESSymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TEl3DESSymmetricCrypto::TEl3DESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TEl3DESSymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TEl3DESSymmetricCrypto::TEl3DESSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TEl3DESSymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TEL3DESSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELCAMELLIASYMMETRICCRYPTO

SB_INLINE TClassHandle TElCamelliaSymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElCamelliaSymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

TElCamelliaSymmetricCrypto::TElCamelliaSymmetricCrypto(TElCamelliaSymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElSymmetricCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCamelliaSymmetricCrypto::TElCamelliaSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCamelliaSymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElCamelliaSymmetricCrypto::TElCamelliaSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCamelliaSymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCamelliaSymmetricCrypto::TElCamelliaSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCamelliaSymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElCamelliaSymmetricCrypto::TElCamelliaSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCamelliaSymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCamelliaSymmetricCrypto::TElCamelliaSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCamelliaSymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElCamelliaSymmetricCrypto::TElCamelliaSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCamelliaSymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCamelliaSymmetricCrypto::TElCamelliaSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCamelliaSymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElCamelliaSymmetricCrypto::TElCamelliaSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCamelliaSymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCamelliaSymmetricCrypto::TElCamelliaSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCamelliaSymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElCamelliaSymmetricCrypto::TElCamelliaSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCamelliaSymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCamelliaSymmetricCrypto::TElCamelliaSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCamelliaSymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElCamelliaSymmetricCrypto::TElCamelliaSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCamelliaSymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELCAMELLIASYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELSERPENTSYMMETRICCRYPTO

SB_INLINE TClassHandle TElSerpentSymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElSerpentSymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

TElSerpentSymmetricCrypto::TElSerpentSymmetricCrypto(TElSerpentSymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElSymmetricCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElSerpentSymmetricCrypto::TElSerpentSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSerpentSymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElSerpentSymmetricCrypto::TElSerpentSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSerpentSymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElSerpentSymmetricCrypto::TElSerpentSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSerpentSymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElSerpentSymmetricCrypto::TElSerpentSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSerpentSymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElSerpentSymmetricCrypto::TElSerpentSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSerpentSymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElSerpentSymmetricCrypto::TElSerpentSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSerpentSymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElSerpentSymmetricCrypto::TElSerpentSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSerpentSymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElSerpentSymmetricCrypto::TElSerpentSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSerpentSymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElSerpentSymmetricCrypto::TElSerpentSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSerpentSymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElSerpentSymmetricCrypto::TElSerpentSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSerpentSymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElSerpentSymmetricCrypto::TElSerpentSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSerpentSymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElSerpentSymmetricCrypto::TElSerpentSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSerpentSymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELSERPENTSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELSEEDSYMMETRICCRYPTO

SB_INLINE TClassHandle TElSEEDSymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElSEEDSymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

TElSEEDSymmetricCrypto::TElSEEDSymmetricCrypto(TElSEEDSymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElSymmetricCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElSEEDSymmetricCrypto::TElSEEDSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSEEDSymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElSEEDSymmetricCrypto::TElSEEDSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSEEDSymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElSEEDSymmetricCrypto::TElSEEDSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSEEDSymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElSEEDSymmetricCrypto::TElSEEDSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSEEDSymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElSEEDSymmetricCrypto::TElSEEDSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSEEDSymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElSEEDSymmetricCrypto::TElSEEDSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSEEDSymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElSEEDSymmetricCrypto::TElSEEDSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSEEDSymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElSEEDSymmetricCrypto::TElSEEDSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSEEDSymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElSEEDSymmetricCrypto::TElSEEDSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSEEDSymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElSEEDSymmetricCrypto::TElSEEDSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSEEDSymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElSEEDSymmetricCrypto::TElSEEDSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSEEDSymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElSEEDSymmetricCrypto::TElSEEDSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSEEDSymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELSEEDSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELRABBITSYMMETRICCRYPTO

SB_INLINE TClassHandle TElRabbitSymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElRabbitSymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

TElRabbitSymmetricCrypto::TElRabbitSymmetricCrypto(TElRabbitSymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElSymmetricCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElRabbitSymmetricCrypto::TElRabbitSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRabbitSymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElRabbitSymmetricCrypto::TElRabbitSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRabbitSymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElRabbitSymmetricCrypto::TElRabbitSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRabbitSymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElRabbitSymmetricCrypto::TElRabbitSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRabbitSymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElRabbitSymmetricCrypto::TElRabbitSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRabbitSymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElRabbitSymmetricCrypto::TElRabbitSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRabbitSymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElRabbitSymmetricCrypto::TElRabbitSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRabbitSymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElRabbitSymmetricCrypto::TElRabbitSymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRabbitSymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElRabbitSymmetricCrypto::TElRabbitSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRabbitSymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElRabbitSymmetricCrypto::TElRabbitSymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRabbitSymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElRabbitSymmetricCrypto::TElRabbitSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRabbitSymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElRabbitSymmetricCrypto::TElRabbitSymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRabbitSymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELRABBITSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELGOST28147SYMMETRICCRYPTO

SB_INLINE void TElGOST28147SymmetricCrypto::InitializeEncryption()
{
	SBCheckError(TElGOST28147SymmetricCrypto_InitializeEncryption(_Handle));
}

SB_INLINE void TElGOST28147SymmetricCrypto::InitializeDecryption()
{
	SBCheckError(TElGOST28147SymmetricCrypto_InitializeDecryption(_Handle));
}

SB_INLINE TClassHandle TElGOST28147SymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElGOST28147SymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

void TElGOST28147SymmetricCrypto::get_ParamSet(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOST28147SymmetricCrypto_get_ParamSet(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(472560553, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGOST28147SymmetricCrypto::set_ParamSet(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElGOST28147SymmetricCrypto_set_ParamSet(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElGOST28147SymmetricCrypto::get_SBoxes(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOST28147SymmetricCrypto_get_SBoxes(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-105658675, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGOST28147SymmetricCrypto::set_SBoxes(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElGOST28147SymmetricCrypto_set_SBoxes(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElGOST28147SymmetricCrypto::get_UseKeyMeshing()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGOST28147SymmetricCrypto_get_UseKeyMeshing(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGOST28147SymmetricCrypto::set_UseKeyMeshing(bool Value)
{
	SBCheckError(TElGOST28147SymmetricCrypto_set_UseKeyMeshing(_Handle, (int8_t)Value));
}

TElGOST28147SymmetricCrypto::TElGOST28147SymmetricCrypto(TElGOST28147SymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElSymmetricCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElGOST28147SymmetricCrypto::TElGOST28147SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST28147SymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElGOST28147SymmetricCrypto::TElGOST28147SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST28147SymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElGOST28147SymmetricCrypto::TElGOST28147SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST28147SymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElGOST28147SymmetricCrypto::TElGOST28147SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST28147SymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElGOST28147SymmetricCrypto::TElGOST28147SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST28147SymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElGOST28147SymmetricCrypto::TElGOST28147SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST28147SymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElGOST28147SymmetricCrypto::TElGOST28147SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST28147SymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElGOST28147SymmetricCrypto::TElGOST28147SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST28147SymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElGOST28147SymmetricCrypto::TElGOST28147SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST28147SymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElGOST28147SymmetricCrypto::TElGOST28147SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST28147SymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElGOST28147SymmetricCrypto::TElGOST28147SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST28147SymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElGOST28147SymmetricCrypto::TElGOST28147SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST28147SymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELGOST28147SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELIDENTITYSYMMETRICCRYPTO

SB_INLINE TClassHandle TElIdentitySymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElIdentitySymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

TElIdentitySymmetricCrypto::TElIdentitySymmetricCrypto(TElIdentitySymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElSymmetricCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElIdentitySymmetricCrypto::TElIdentitySymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIdentitySymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElIdentitySymmetricCrypto::TElIdentitySymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIdentitySymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElIdentitySymmetricCrypto::TElIdentitySymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIdentitySymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElIdentitySymmetricCrypto::TElIdentitySymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIdentitySymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElIdentitySymmetricCrypto::TElIdentitySymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIdentitySymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElIdentitySymmetricCrypto::TElIdentitySymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIdentitySymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElIdentitySymmetricCrypto::TElIdentitySymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIdentitySymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElIdentitySymmetricCrypto::TElIdentitySymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIdentitySymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElIdentitySymmetricCrypto::TElIdentitySymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIdentitySymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElIdentitySymmetricCrypto::TElIdentitySymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIdentitySymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElIdentitySymmetricCrypto::TElIdentitySymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIdentitySymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElIdentitySymmetricCrypto::TElIdentitySymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIdentitySymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELIDENTITYSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELCHACHA20SYMMETRICCRYPTO

SB_INLINE TClassHandle TElChaCha20SymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElChaCha20SymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE uint32_t TElChaCha20SymmetricCrypto::get_Counter()
{
	uint32_t OutResult;
	SBCheckError(TElChaCha20SymmetricCrypto_get_Counter(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElChaCha20SymmetricCrypto::set_Counter(uint32_t Value)
{
	SBCheckError(TElChaCha20SymmetricCrypto_set_Counter(_Handle, Value));
}

TElChaCha20SymmetricCrypto::TElChaCha20SymmetricCrypto(TElChaCha20SymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElSymmetricCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElChaCha20SymmetricCrypto::TElChaCha20SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElChaCha20SymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElChaCha20SymmetricCrypto::TElChaCha20SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElChaCha20SymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElChaCha20SymmetricCrypto::TElChaCha20SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElChaCha20SymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElChaCha20SymmetricCrypto::TElChaCha20SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElChaCha20SymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElChaCha20SymmetricCrypto::TElChaCha20SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElChaCha20SymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElChaCha20SymmetricCrypto::TElChaCha20SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElChaCha20SymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElChaCha20SymmetricCrypto::TElChaCha20SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElChaCha20SymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElChaCha20SymmetricCrypto::TElChaCha20SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElChaCha20SymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElChaCha20SymmetricCrypto::TElChaCha20SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElChaCha20SymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElChaCha20SymmetricCrypto::TElChaCha20SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElChaCha20SymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElChaCha20SymmetricCrypto::TElChaCha20SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElChaCha20SymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElChaCha20SymmetricCrypto::TElChaCha20SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElChaCha20SymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELCHACHA20SYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELAEADCHACHA20POLY1305SYMMETRICCRYPTO

SB_INLINE TClassHandle TElAEADChaCha20Poly1305SymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElAEADChaCha20Poly1305SymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

void TElAEADChaCha20Poly1305SymmetricCrypto::get_AAD(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElAEADChaCha20Poly1305SymmetricCrypto_get_AAD(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-322496856, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAEADChaCha20Poly1305SymmetricCrypto::set_AAD(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElAEADChaCha20Poly1305SymmetricCrypto_set_AAD(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE void TElAEADChaCha20Poly1305SymmetricCrypto::get_Tag(TSBPoly1305Tag &OutResult)
{
	SBCheckError(TElAEADChaCha20Poly1305SymmetricCrypto_get_Tag(_Handle, &OutResult));
}

SB_INLINE void TElAEADChaCha20Poly1305SymmetricCrypto::set_Tag(TSBPoly1305Tag &Value)
{
	SBCheckError(TElAEADChaCha20Poly1305SymmetricCrypto_set_Tag(_Handle, &Value));
}

TSBPoly1305Mode TElAEADChaCha20Poly1305SymmetricCrypto::get_Poly1305Mode()
{
	TSBPoly1305ModeRaw OutResultRaw = 0;
	SBCheckError(TElAEADChaCha20Poly1305SymmetricCrypto_get_Poly1305Mode(_Handle, &OutResultRaw));
	return (TSBPoly1305Mode)OutResultRaw;
}

SB_INLINE void TElAEADChaCha20Poly1305SymmetricCrypto::set_Poly1305Mode(TSBPoly1305Mode Value)
{
	SBCheckError(TElAEADChaCha20Poly1305SymmetricCrypto_set_Poly1305Mode(_Handle, (TSBPoly1305ModeRaw)Value));
}

TElAEADChaCha20Poly1305SymmetricCrypto::TElAEADChaCha20Poly1305SymmetricCrypto(TElAEADChaCha20Poly1305SymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElSymmetricCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElAEADChaCha20Poly1305SymmetricCrypto::TElAEADChaCha20Poly1305SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAEADChaCha20Poly1305SymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElAEADChaCha20Poly1305SymmetricCrypto::TElAEADChaCha20Poly1305SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAEADChaCha20Poly1305SymmetricCrypto_Create(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElAEADChaCha20Poly1305SymmetricCrypto::TElAEADChaCha20Poly1305SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAEADChaCha20Poly1305SymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElAEADChaCha20Poly1305SymmetricCrypto::TElAEADChaCha20Poly1305SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAEADChaCha20Poly1305SymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElAEADChaCha20Poly1305SymmetricCrypto::TElAEADChaCha20Poly1305SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAEADChaCha20Poly1305SymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, CryptoProvider.getHandle(), &_Handle));
}

TElAEADChaCha20Poly1305SymmetricCrypto::TElAEADChaCha20Poly1305SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAEADChaCha20Poly1305SymmetricCrypto_Create_2((TSBSymmetricCryptoModeRaw)Mode, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElAEADChaCha20Poly1305SymmetricCrypto::TElAEADChaCha20Poly1305SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAEADChaCha20Poly1305SymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElAEADChaCha20Poly1305SymmetricCrypto::TElAEADChaCha20Poly1305SymmetricCrypto(int32_t AlgID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAEADChaCha20Poly1305SymmetricCrypto_Create_3(AlgID, (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElAEADChaCha20Poly1305SymmetricCrypto::TElAEADChaCha20Poly1305SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAEADChaCha20Poly1305SymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElAEADChaCha20Poly1305SymmetricCrypto::TElAEADChaCha20Poly1305SymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAEADChaCha20Poly1305SymmetricCrypto_Create_4(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElAEADChaCha20Poly1305SymmetricCrypto::TElAEADChaCha20Poly1305SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAEADChaCha20Poly1305SymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElAEADChaCha20Poly1305SymmetricCrypto::TElAEADChaCha20Poly1305SymmetricCrypto(TSBSymmetricCryptoMode Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAEADChaCha20Poly1305SymmetricCrypto_Create_5((TSBSymmetricCryptoModeRaw)Mode, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELAEADCHACHA20POLY1305SYMMETRICCRYPTO */

};	/* namespace SecureBlackbox */
