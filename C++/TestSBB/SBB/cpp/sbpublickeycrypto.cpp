#include "sbpublickeycrypto.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
SB_INLINE int32_t TElPublicKeyMaterial::GetMaxPublicKeySize(TElCustomCryptoProvider &Prov)
{
	int32_t OutResult;
	SBCheckError(TElPublicKeyMaterial_GetMaxPublicKeySize(Prov.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPublicKeyMaterial::GetMaxPublicKeySize(TElCustomCryptoProvider *Prov)
{
	int32_t OutResult;
	SBCheckError(TElPublicKeyMaterial_GetMaxPublicKeySize((Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
SB_INLINE int32_t TElPublicKeyMaterial::GetMaxPublicKeySize_Inst(TElCustomCryptoProvider &Prov)
{
	int32_t OutResult;
	SBCheckError(TElPublicKeyMaterial_GetMaxPublicKeySize_1(_Handle, Prov.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPublicKeyMaterial::GetMaxPublicKeySize_Inst(TElCustomCryptoProvider *Prov)
{
	int32_t OutResult;
	SBCheckError(TElPublicKeyMaterial_GetMaxPublicKeySize_1(_Handle, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
SB_INLINE void TElPublicKeyMaterial::AssignCryptoKey(TElCustomCryptoKey &Key)
{
	SBCheckError(TElPublicKeyMaterial_AssignCryptoKey(_Handle, Key.getHandle()));
}

SB_INLINE void TElPublicKeyMaterial::AssignCryptoKey(TElCustomCryptoKey *Key)
{
	SBCheckError(TElPublicKeyMaterial_AssignCryptoKey(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

SB_INLINE void TElPublicKeyMaterial::Generate(int32_t Bits)
{
	SBCheckError(TElPublicKeyMaterial_Generate(_Handle, Bits));
}

SB_INLINE void TElPublicKeyMaterial::LoadPublic(void * Buffer, int32_t Size)
{
	SBCheckError(TElPublicKeyMaterial_LoadPublic(_Handle, Buffer, Size));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPublicKeyMaterial::LoadPublic(TStream &Stream, int32_t Count)
{
	SBCheckError(TElPublicKeyMaterial_LoadPublic_1(_Handle, Stream.getHandle(), Count));
}

SB_INLINE void TElPublicKeyMaterial::LoadPublic(TStream *Stream, int32_t Count)
{
	SBCheckError(TElPublicKeyMaterial_LoadPublic_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElPublicKeyMaterial::LoadSecret(void * Buffer, int32_t Size)
{
	SBCheckError(TElPublicKeyMaterial_LoadSecret(_Handle, Buffer, Size));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPublicKeyMaterial::LoadSecret(TStream &Stream, int32_t Count)
{
	SBCheckError(TElPublicKeyMaterial_LoadSecret_1(_Handle, Stream.getHandle(), Count));
}

SB_INLINE void TElPublicKeyMaterial::LoadSecret(TStream *Stream, int32_t Count)
{
	SBCheckError(TElPublicKeyMaterial_LoadSecret_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElPublicKeyMaterial::SavePublic(void * Buffer, int32_t &Size)
{
	SBCheckError(TElPublicKeyMaterial_SavePublic(_Handle, Buffer, &Size));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPublicKeyMaterial::SavePublic(TStream &Stream)
{
	SBCheckError(TElPublicKeyMaterial_SavePublic_1(_Handle, Stream.getHandle()));
}

SB_INLINE void TElPublicKeyMaterial::SavePublic(TStream *Stream)
{
	SBCheckError(TElPublicKeyMaterial_SavePublic_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElPublicKeyMaterial::SaveSecret(void * Buffer, int32_t &Size)
{
	SBCheckError(TElPublicKeyMaterial_SaveSecret(_Handle, Buffer, &Size));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPublicKeyMaterial::SaveSecret(TStream &Stream)
{
	SBCheckError(TElPublicKeyMaterial_SaveSecret_1(_Handle, Stream.getHandle()));
}

SB_INLINE void TElPublicKeyMaterial::SaveSecret(TStream *Stream)
{
	SBCheckError(TElPublicKeyMaterial_SaveSecret_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElPublicKeyMaterial::LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElPublicKeyMaterial_LoadParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElPublicKeyMaterial::LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElPublicKeyMaterial_LoadParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElPublicKeyMaterial::SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElPublicKeyMaterial_SaveParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElPublicKeyMaterial::SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElPublicKeyMaterial_SaveParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPublicKeyMaterial::Save(TStream &Stream)
{
	SBCheckError(TElPublicKeyMaterial_Save(_Handle, Stream.getHandle()));
}

SB_INLINE void TElPublicKeyMaterial::Save(TStream *Stream)
{
	SBCheckError(TElPublicKeyMaterial_Save(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPublicKeyMaterial::Load(TStream &Stream, int32_t Count)
{
	SBCheckError(TElPublicKeyMaterial_Load(_Handle, Stream.getHandle(), Count));
}

SB_INLINE void TElPublicKeyMaterial::Load(TStream *Stream, int32_t Count)
{
	SBCheckError(TElPublicKeyMaterial_Load(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElPublicKeyMaterial::LoadFromXML(const std::string &Str)
{
	SBCheckError(TElPublicKeyMaterial_LoadFromXML(_Handle, Str.data(), (int32_t)Str.length()));
}

void TElPublicKeyMaterial::SaveToXML(bool IncludePrivateKey, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPublicKeyMaterial_SaveToXML(_Handle, (int8_t)IncludePrivateKey, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-980248540, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TElKeyMaterialHandle TElPublicKeyMaterial::Clone()
{
	TElKeyMaterialHandle OutResult;
	SBCheckError(TElPublicKeyMaterial_Clone(_Handle, &OutResult));
	return OutResult;
}

bool TElPublicKeyMaterial::Equals(TElKeyMaterial &Source, bool PublicOnly)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicKeyMaterial_Equals(_Handle, Source.getHandle(), (int8_t)PublicOnly, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPublicKeyMaterial::Equals(TElKeyMaterial *Source, bool PublicOnly)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicKeyMaterial_Equals(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (int8_t)PublicOnly, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPublicKeyMaterial::ClearSecret()
{
	SBCheckError(TElPublicKeyMaterial_ClearSecret(_Handle));
}

SB_INLINE void TElPublicKeyMaterial::ClearPublic()
{
	SBCheckError(TElPublicKeyMaterial_ClearPublic(_Handle));
}

SB_INLINE void TElPublicKeyMaterial::Clear()
{
	SBCheckError(TElPublicKeyMaterial_Clear(_Handle));
}

SB_INLINE void TElPublicKeyMaterial::BeginGenerate(int32_t Bits)
{
	SBCheckError(TElPublicKeyMaterial_BeginGenerate(_Handle, Bits));
}

SB_INLINE void TElPublicKeyMaterial::EndGenerate()
{
	SBCheckError(TElPublicKeyMaterial_EndGenerate(_Handle));
}

SB_INLINE void TElPublicKeyMaterial::CancelAsyncOperation()
{
	SBCheckError(TElPublicKeyMaterial_CancelAsyncOperation(_Handle));
}

SB_INLINE void TElPublicKeyMaterial::PrepareForEncryption(bool MultiUse)
{
	SBCheckError(TElPublicKeyMaterial_PrepareForEncryption(_Handle, (int8_t)MultiUse));
}

SB_INLINE void TElPublicKeyMaterial::PrepareForSigning(bool MultiUse)
{
	SBCheckError(TElPublicKeyMaterial_PrepareForSigning(_Handle, (int8_t)MultiUse));
}

bool TElPublicKeyMaterial::get_PublicKey()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicKeyMaterial_get_PublicKey(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPublicKeyMaterial::get_SecretKey()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicKeyMaterial_get_SecretKey(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_WINDOWS
SB_INLINE PCCERT_CONTEXT TElPublicKeyMaterial::get_CertHandle()
{
	PCCERT_CONTEXT OutResult;
	SBCheckError(TElPublicKeyMaterial_get_CertHandle(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPublicKeyMaterial::set_CertHandle(PCCERT_CONTEXT Value)
{
	SBCheckError(TElPublicKeyMaterial_set_CertHandle(_Handle, Value));
}

void TElPublicKeyMaterial::get_KeyExchangePIN(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPublicKeyMaterial_get_KeyExchangePIN(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-881848744, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPublicKeyMaterial::set_KeyExchangePIN(const std::string &Value)
{
	SBCheckError(TElPublicKeyMaterial_set_KeyExchangePIN(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPublicKeyMaterial::get_SignaturePIN(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPublicKeyMaterial_get_SignaturePIN(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-376680196, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPublicKeyMaterial::set_SignaturePIN(const std::string &Value)
{
	SBCheckError(TElPublicKeyMaterial_set_SignaturePIN(_Handle, Value.data(), (int32_t)Value.length()));
}

#endif
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE uint32_t TElPublicKeyMaterial::get_KeyHandle()
#else
SB_INLINE int64_t TElPublicKeyMaterial::get_KeyHandle()
#endif
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPublicKeyMaterial_get_KeyHandle(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPublicKeyMaterial::set_KeyHandle(uint32_t Value)
#else
SB_INLINE void TElPublicKeyMaterial::set_KeyHandle(int64_t Value)
#endif
{
	SBCheckError(TElPublicKeyMaterial_set_KeyHandle(_Handle, Value));
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE uint32_t TElPublicKeyMaterial::get_SessionHandle()
#else
SB_INLINE int64_t TElPublicKeyMaterial::get_SessionHandle()
#endif
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t OutResult;
#else
	int64_t OutResult;
#endif
	SBCheckError(TElPublicKeyMaterial_get_SessionHandle(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_INLINE void TElPublicKeyMaterial::set_SessionHandle(uint32_t Value)
#else
SB_INLINE void TElPublicKeyMaterial::set_SessionHandle(int64_t Value)
#endif
{
	SBCheckError(TElPublicKeyMaterial_set_SessionHandle(_Handle, Value));
#ifdef SB_WINDOWS
}

SB_INLINE uint32_t * TElPublicKeyMaterial::get_CNGKeyHandle()
{
	uint32_t * OutResult;
	SBCheckError(TElPublicKeyMaterial_get_CNGKeyHandle(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPublicKeyMaterial::set_CNGKeyHandle(uint32_t * Value)
{
	SBCheckError(TElPublicKeyMaterial_set_CNGKeyHandle(_Handle, Value));
}

SB_INLINE uint32_t * TElPublicKeyMaterial::get_CNGProvHandle()
{
	uint32_t * OutResult;
	SBCheckError(TElPublicKeyMaterial_get_CNGProvHandle(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPublicKeyMaterial::set_CNGProvHandle(uint32_t * Value)
{
	SBCheckError(TElPublicKeyMaterial_set_CNGProvHandle(_Handle, Value));
#endif
}

bool TElPublicKeyMaterial::get_Busy()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicKeyMaterial_get_Busy(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TSBKeyStoreFormat TElPublicKeyMaterial::get_StoreFormat()
{
	TSBKeyStoreFormatRaw OutResultRaw = 0;
	SBCheckError(TElPublicKeyMaterial_get_StoreFormat(_Handle, &OutResultRaw));
	return (TSBKeyStoreFormat)OutResultRaw;
}

SB_INLINE void TElPublicKeyMaterial::set_StoreFormat(TSBKeyStoreFormat Value)
{
	SBCheckError(TElPublicKeyMaterial_set_StoreFormat(_Handle, (TSBKeyStoreFormatRaw)Value));
}

bool TElPublicKeyMaterial::get_AsyncOperationFinished()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicKeyMaterial_get_AsyncOperationFinished(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPublicKeyMaterial::get_OnAsyncOperationFinished(TSBAsyncOperationFinishedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPublicKeyMaterial_get_OnAsyncOperationFinished(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPublicKeyMaterial::set_OnAsyncOperationFinished(TSBAsyncOperationFinishedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPublicKeyMaterial_set_OnAsyncOperationFinished(_Handle, pMethodValue, pDataValue));
}

TElPublicKeyMaterial::TElPublicKeyMaterial(TElPublicKeyMaterialHandle handle, TElOwnHandle ownHandle) : TElKeyMaterial(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElPublicKeyMaterial::TElPublicKeyMaterial(TElCustomCryptoProvider &Prov) : TElKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPublicKeyMaterial_Create(Prov.getHandle(), &_Handle));
}

TElPublicKeyMaterial::TElPublicKeyMaterial(TElCustomCryptoProvider *Prov) : TElKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPublicKeyMaterial_Create((Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElPublicKeyMaterial::TElPublicKeyMaterial(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPublicKeyMaterial_Create_1(Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElPublicKeyMaterial::TElPublicKeyMaterial(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPublicKeyMaterial_Create_1((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

#ifdef SB_USE_CLASS_TELPUBLICKEYCRYPTO

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElPublicKeyCrypto::LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElPublicKeyCrypto_LoadParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElPublicKeyCrypto::LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElPublicKeyCrypto_LoadParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElPublicKeyCrypto::SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElPublicKeyCrypto_SaveParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElPublicKeyCrypto::SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElPublicKeyCrypto_SaveParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

SB_INLINE void TElPublicKeyCrypto::Encrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElPublicKeyCrypto_Encrypt(_Handle, InBuffer, InSize, OutBuffer, &OutSize));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPublicKeyCrypto::Encrypt(TStream &InStream, TStream &OutStream, int32_t Count)
{
	SBCheckError(TElPublicKeyCrypto_Encrypt_1(_Handle, InStream.getHandle(), OutStream.getHandle(), Count));
}

SB_INLINE void TElPublicKeyCrypto::Encrypt(TStream *InStream, TStream *OutStream, int32_t Count)
{
	SBCheckError(TElPublicKeyCrypto_Encrypt_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElPublicKeyCrypto::Decrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElPublicKeyCrypto_Decrypt(_Handle, InBuffer, InSize, OutBuffer, &OutSize));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPublicKeyCrypto::Decrypt(TStream &InStream, TStream &OutStream, int32_t Count)
{
	SBCheckError(TElPublicKeyCrypto_Decrypt_1(_Handle, InStream.getHandle(), OutStream.getHandle(), Count));
}

SB_INLINE void TElPublicKeyCrypto::Decrypt(TStream *InStream, TStream *OutStream, int32_t Count)
{
	SBCheckError(TElPublicKeyCrypto_Decrypt_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElPublicKeyCrypto::Sign(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElPublicKeyCrypto_Sign(_Handle, InBuffer, InSize, OutBuffer, &OutSize));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPublicKeyCrypto::Sign(TStream &InStream, TStream &OutStream, int32_t Count)
{
	SBCheckError(TElPublicKeyCrypto_Sign_1(_Handle, InStream.getHandle(), OutStream.getHandle(), Count));
}

SB_INLINE void TElPublicKeyCrypto::Sign(TStream *InStream, TStream *OutStream, int32_t Count)
{
	SBCheckError(TElPublicKeyCrypto_Sign_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElPublicKeyCrypto::SignDetached(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElPublicKeyCrypto_SignDetached(_Handle, InBuffer, InSize, OutBuffer, &OutSize));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPublicKeyCrypto::SignDetached(TStream &InStream, TStream &OutStream, int32_t Count)
{
	SBCheckError(TElPublicKeyCrypto_SignDetached_1(_Handle, InStream.getHandle(), OutStream.getHandle(), Count));
}

SB_INLINE void TElPublicKeyCrypto::SignDetached(TStream *InStream, TStream *OutStream, int32_t Count)
{
	SBCheckError(TElPublicKeyCrypto_SignDetached_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

TSBPublicKeyVerificationResult TElPublicKeyCrypto::Verify(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	TSBPublicKeyVerificationResultRaw OutResultRaw = 0;
	SBCheckError(TElPublicKeyCrypto_Verify(_Handle, InBuffer, InSize, OutBuffer, &OutSize, &OutResultRaw));
	return (TSBPublicKeyVerificationResult)OutResultRaw;
}

#ifdef SB_USE_CLASS_TSTREAM
TSBPublicKeyVerificationResult TElPublicKeyCrypto::Verify(TStream &InStream, TStream &OutStream, int32_t Count)
{
	TSBPublicKeyVerificationResultRaw OutResultRaw = 0;
	SBCheckError(TElPublicKeyCrypto_Verify_1(_Handle, InStream.getHandle(), OutStream.getHandle(), Count, &OutResultRaw));
	return (TSBPublicKeyVerificationResult)OutResultRaw;
}

TSBPublicKeyVerificationResult TElPublicKeyCrypto::Verify(TStream *InStream, TStream *OutStream, int32_t Count)
{
	TSBPublicKeyVerificationResultRaw OutResultRaw = 0;
	SBCheckError(TElPublicKeyCrypto_Verify_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, Count, &OutResultRaw));
	return (TSBPublicKeyVerificationResult)OutResultRaw;
}
#endif /* SB_USE_CLASS_TSTREAM */

TSBPublicKeyVerificationResult TElPublicKeyCrypto::VerifyDetached(void * InBuffer, int32_t InSize, void * SigBuffer, int32_t SigSize)
{
	TSBPublicKeyVerificationResultRaw OutResultRaw = 0;
	SBCheckError(TElPublicKeyCrypto_VerifyDetached(_Handle, InBuffer, InSize, SigBuffer, SigSize, &OutResultRaw));
	return (TSBPublicKeyVerificationResult)OutResultRaw;
}

#ifdef SB_USE_CLASS_TSTREAM
TSBPublicKeyVerificationResult TElPublicKeyCrypto::VerifyDetached(TStream &InStream, TStream &SigStream, int32_t InCount, int32_t SigCount)
{
	TSBPublicKeyVerificationResultRaw OutResultRaw = 0;
	SBCheckError(TElPublicKeyCrypto_VerifyDetached_1(_Handle, InStream.getHandle(), SigStream.getHandle(), InCount, SigCount, &OutResultRaw));
	return (TSBPublicKeyVerificationResult)OutResultRaw;
}

TSBPublicKeyVerificationResult TElPublicKeyCrypto::VerifyDetached(TStream *InStream, TStream *SigStream, int32_t InCount, int32_t SigCount)
{
	TSBPublicKeyVerificationResultRaw OutResultRaw = 0;
	SBCheckError(TElPublicKeyCrypto_VerifyDetached_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (SigStream != NULL) ? SigStream->getHandle() : SB_NULL_HANDLE, InCount, SigCount, &OutResultRaw));
	return (TSBPublicKeyVerificationResult)OutResultRaw;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELKEYMATERIAL
SB_INLINE TElKeyMaterialHandle TElPublicKeyCrypto::DecryptKey(void * EncKey, int32_t EncKeySize, const std::vector<uint8_t> &EncKeyAlgOID, const std::vector<uint8_t> &EncKeyAlgParams)
{
	TElKeyMaterialHandle OutResult;
	SBCheckError(TElPublicKeyCrypto_DecryptKey(_Handle, EncKey, EncKeySize, SB_STD_VECTOR_FRONT_ADR(EncKeyAlgOID), (int32_t)EncKeyAlgOID.size(), SB_STD_VECTOR_FRONT_ADR(EncKeyAlgParams), (int32_t)EncKeyAlgParams.size(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

SB_INLINE void TElPublicKeyCrypto::BeginEncrypt(void * InBuffer, int32_t InSize)
{
	SBCheckError(TElPublicKeyCrypto_BeginEncrypt(_Handle, InBuffer, InSize));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPublicKeyCrypto::BeginEncrypt(TStream &InStream, TStream &OutStream, int32_t Count)
{
	SBCheckError(TElPublicKeyCrypto_BeginEncrypt_1(_Handle, InStream.getHandle(), OutStream.getHandle(), Count));
}

SB_INLINE void TElPublicKeyCrypto::BeginEncrypt(TStream *InStream, TStream *OutStream, int32_t Count)
{
	SBCheckError(TElPublicKeyCrypto_BeginEncrypt_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElPublicKeyCrypto::EndEncrypt(void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicKeyCrypto_EndEncrypt(_Handle, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPublicKeyCrypto::EndEncrypt()
{
	SBCheckError(TElPublicKeyCrypto_EndEncrypt_1(_Handle));
}

SB_INLINE void TElPublicKeyCrypto::BeginDecrypt(void * InBuffer, int32_t InSize)
{
	SBCheckError(TElPublicKeyCrypto_BeginDecrypt(_Handle, InBuffer, InSize));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPublicKeyCrypto::BeginDecrypt(TStream &InStream, TStream &OutStream, int32_t Count)
{
	SBCheckError(TElPublicKeyCrypto_BeginDecrypt_1(_Handle, InStream.getHandle(), OutStream.getHandle(), Count));
}

SB_INLINE void TElPublicKeyCrypto::BeginDecrypt(TStream *InStream, TStream *OutStream, int32_t Count)
{
	SBCheckError(TElPublicKeyCrypto_BeginDecrypt_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElPublicKeyCrypto::EndDecrypt(void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicKeyCrypto_EndDecrypt(_Handle, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPublicKeyCrypto::EndDecrypt()
{
	SBCheckError(TElPublicKeyCrypto_EndDecrypt_1(_Handle));
}

SB_INLINE void TElPublicKeyCrypto::BeginSign(void * InBuffer, int32_t InSize)
{
	SBCheckError(TElPublicKeyCrypto_BeginSign(_Handle, InBuffer, InSize));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPublicKeyCrypto::BeginSign(TStream &InStream, TStream &OutStream, int32_t Count)
{
	SBCheckError(TElPublicKeyCrypto_BeginSign_1(_Handle, InStream.getHandle(), OutStream.getHandle(), Count));
}

SB_INLINE void TElPublicKeyCrypto::BeginSign(TStream *InStream, TStream *OutStream, int32_t Count)
{
	SBCheckError(TElPublicKeyCrypto_BeginSign_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElPublicKeyCrypto::EndSign(void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicKeyCrypto_EndSign(_Handle, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPublicKeyCrypto::EndSign()
{
	SBCheckError(TElPublicKeyCrypto_EndSign_1(_Handle));
}

SB_INLINE void TElPublicKeyCrypto::BeginSignDetached(void * InBuffer, int32_t InSize)
{
	SBCheckError(TElPublicKeyCrypto_BeginSignDetached(_Handle, InBuffer, InSize));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPublicKeyCrypto::BeginSignDetached(TStream &InStream, TStream &OutStream, int32_t Count)
{
	SBCheckError(TElPublicKeyCrypto_BeginSignDetached_1(_Handle, InStream.getHandle(), OutStream.getHandle(), Count));
}

SB_INLINE void TElPublicKeyCrypto::BeginSignDetached(TStream *InStream, TStream *OutStream, int32_t Count)
{
	SBCheckError(TElPublicKeyCrypto_BeginSignDetached_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElPublicKeyCrypto::EndSignDetached(void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicKeyCrypto_EndSignDetached(_Handle, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPublicKeyCrypto::EndSignDetached()
{
	SBCheckError(TElPublicKeyCrypto_EndSignDetached_1(_Handle));
}

SB_INLINE void TElPublicKeyCrypto::BeginVerify(void * InBuffer, int32_t InSize)
{
	SBCheckError(TElPublicKeyCrypto_BeginVerify(_Handle, InBuffer, InSize));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPublicKeyCrypto::BeginVerify(TStream &InStream, TStream &OutStream, int32_t Count)
{
	SBCheckError(TElPublicKeyCrypto_BeginVerify_1(_Handle, InStream.getHandle(), OutStream.getHandle(), Count));
}

SB_INLINE void TElPublicKeyCrypto::BeginVerify(TStream *InStream, TStream *OutStream, int32_t Count)
{
	SBCheckError(TElPublicKeyCrypto_BeginVerify_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElPublicKeyCrypto::EndVerify(void * OutBuffer, int32_t &OutSize, TSBPublicKeyVerificationResult &VerificationResult)
{
	TSBPublicKeyVerificationResultRaw VerificationResultRaw = (TSBPublicKeyVerificationResultRaw)VerificationResult;
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicKeyCrypto_EndVerify(_Handle, OutBuffer, &OutSize, &VerificationResultRaw, &OutResultRaw));
	VerificationResult = (TSBPublicKeyVerificationResult)VerificationResultRaw;
	return (OutResultRaw != 0);
}

TSBPublicKeyVerificationResult TElPublicKeyCrypto::EndVerify()
{
	TSBPublicKeyVerificationResultRaw OutResultRaw = 0;
	SBCheckError(TElPublicKeyCrypto_EndVerify_1(_Handle, &OutResultRaw));
	return (TSBPublicKeyVerificationResult)OutResultRaw;
}

SB_INLINE void TElPublicKeyCrypto::BeginVerifyDetached(void * InBuffer, int32_t InSize, void * SigBuffer, int32_t SigSize)
{
	SBCheckError(TElPublicKeyCrypto_BeginVerifyDetached(_Handle, InBuffer, InSize, SigBuffer, SigSize));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPublicKeyCrypto::BeginVerifyDetached(TStream &InStream, TStream &SigStream, int32_t InCount, int32_t SigCount)
{
	SBCheckError(TElPublicKeyCrypto_BeginVerifyDetached_1(_Handle, InStream.getHandle(), SigStream.getHandle(), InCount, SigCount));
}

SB_INLINE void TElPublicKeyCrypto::BeginVerifyDetached(TStream *InStream, TStream *SigStream, int32_t InCount, int32_t SigCount)
{
	SBCheckError(TElPublicKeyCrypto_BeginVerifyDetached_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (SigStream != NULL) ? SigStream->getHandle() : SB_NULL_HANDLE, InCount, SigCount));
}
#endif /* SB_USE_CLASS_TSTREAM */

TSBPublicKeyVerificationResult TElPublicKeyCrypto::EndVerifyDetached()
{
	TSBPublicKeyVerificationResultRaw OutResultRaw = 0;
	SBCheckError(TElPublicKeyCrypto_EndVerifyDetached(_Handle, &OutResultRaw));
	return (TSBPublicKeyVerificationResult)OutResultRaw;
}

SB_INLINE void TElPublicKeyCrypto::CancelAsyncOperation()
{
	SBCheckError(TElPublicKeyCrypto_CancelAsyncOperation(_Handle));
}

SB_INLINE TClassHandle TElPublicKeyCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPublicKeyCrypto_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
TElPublicKeyMaterial* TElPublicKeyCrypto::get_KeyMaterial()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPublicKeyCrypto_get_KeyMaterial(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyMaterial)
		this->_Inst_KeyMaterial = new TElPublicKeyMaterial(hOutResult, ohFalse);
	else
		this->_Inst_KeyMaterial->updateHandle(hOutResult);
	return this->_Inst_KeyMaterial;
}

SB_INLINE void TElPublicKeyCrypto::set_KeyMaterial(TElPublicKeyMaterial &Value)
{
	SBCheckError(TElPublicKeyCrypto_set_KeyMaterial(_Handle, Value.getHandle()));
}

SB_INLINE void TElPublicKeyCrypto::set_KeyMaterial(TElPublicKeyMaterial *Value)
{
	SBCheckError(TElPublicKeyCrypto_set_KeyMaterial(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

bool TElPublicKeyCrypto::get_SupportsEncryption()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicKeyCrypto_get_SupportsEncryption(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPublicKeyCrypto::get_SupportsSigning()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicKeyCrypto_get_SupportsSigning(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPublicKeyCrypto::get_InputIsHash()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicKeyCrypto_get_InputIsHash(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPublicKeyCrypto::set_InputIsHash(bool Value)
{
	SBCheckError(TElPublicKeyCrypto_set_InputIsHash(_Handle, (int8_t)Value));
}

TSBPublicKeyCryptoEncoding TElPublicKeyCrypto::get_InputEncoding()
{
	TSBPublicKeyCryptoEncodingRaw OutResultRaw = 0;
	SBCheckError(TElPublicKeyCrypto_get_InputEncoding(_Handle, &OutResultRaw));
	return (TSBPublicKeyCryptoEncoding)OutResultRaw;
}

SB_INLINE void TElPublicKeyCrypto::set_InputEncoding(TSBPublicKeyCryptoEncoding Value)
{
	SBCheckError(TElPublicKeyCrypto_set_InputEncoding(_Handle, (TSBPublicKeyCryptoEncodingRaw)Value));
}

TSBPublicKeyCryptoEncoding TElPublicKeyCrypto::get_OutputEncoding()
{
	TSBPublicKeyCryptoEncodingRaw OutResultRaw = 0;
	SBCheckError(TElPublicKeyCrypto_get_OutputEncoding(_Handle, &OutResultRaw));
	return (TSBPublicKeyCryptoEncoding)OutResultRaw;
}

SB_INLINE void TElPublicKeyCrypto::set_OutputEncoding(TSBPublicKeyCryptoEncoding Value)
{
	SBCheckError(TElPublicKeyCrypto_set_OutputEncoding(_Handle, (TSBPublicKeyCryptoEncodingRaw)Value));
}

bool TElPublicKeyCrypto::get_Busy()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicKeyCrypto_get_Busy(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElPublicKeyCrypto::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPublicKeyCrypto_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPublicKeyCrypto::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElPublicKeyCrypto_set_HashAlgorithm(_Handle, Value));
}

bool TElPublicKeyCrypto::get_AsyncOperationFinished()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicKeyCrypto_get_AsyncOperationFinished(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPublicKeyCrypto::get_OnAsyncOperationFinished(TSBAsyncOperationFinishedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPublicKeyCrypto_get_OnAsyncOperationFinished(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPublicKeyCrypto::set_OnAsyncOperationFinished(TSBAsyncOperationFinishedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPublicKeyCrypto_set_OnAsyncOperationFinished(_Handle, pMethodValue, pDataValue));
}

void TElPublicKeyCrypto::initInstances()
{
#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
	this->_Inst_KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */
}

TElPublicKeyCrypto::TElPublicKeyCrypto(TElPublicKeyCryptoHandle handle, TElOwnHandle ownHandle) : TElCustomCrypto(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElPublicKeyCrypto::TElPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPublicKeyCrypto_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), CryptoProvider.getHandle(), &_Handle));
}

TElPublicKeyCrypto::TElPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPublicKeyCrypto_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElPublicKeyCrypto::TElPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider &CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPublicKeyCrypto_Create_1(Alg, CryptoProvider.getHandle(), &_Handle));
}

TElPublicKeyCrypto::TElPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider *CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPublicKeyCrypto_Create_1(Alg, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElPublicKeyCrypto::TElPublicKeyCrypto(TElCustomCryptoProvider &CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPublicKeyCrypto_Create_2(CryptoProvider.getHandle(), &_Handle));
}

TElPublicKeyCrypto::TElPublicKeyCrypto(TElCustomCryptoProvider *CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPublicKeyCrypto_Create_2((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElPublicKeyCrypto::TElPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPublicKeyCrypto_Create_3(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElPublicKeyCrypto::TElPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPublicKeyCrypto_Create_3(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElPublicKeyCrypto::TElPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPublicKeyCrypto_Create_4(Alg, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElPublicKeyCrypto::TElPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPublicKeyCrypto_Create_4(Alg, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElPublicKeyCrypto::TElPublicKeyCrypto(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPublicKeyCrypto_Create_5(Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElPublicKeyCrypto::TElPublicKeyCrypto(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPublicKeyCrypto_Create_5((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

TElPublicKeyCrypto::~TElPublicKeyCrypto()
{
#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
	delete this->_Inst_KeyMaterial;
	this->_Inst_KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */
}
#endif /* SB_USE_CLASS_TELPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELRSAKEYMATERIAL

SB_INLINE void TElRSAKeyMaterial::Assign(TElKeyMaterial &Source)
{
	SBCheckError(TElRSAKeyMaterial_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElRSAKeyMaterial::Assign(TElKeyMaterial *Source)
{
	SBCheckError(TElRSAKeyMaterial_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElRSAKeyMaterial::LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElRSAKeyMaterial_LoadParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElRSAKeyMaterial::LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElRSAKeyMaterial_LoadParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElRSAKeyMaterial::SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElRSAKeyMaterial_SaveParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElRSAKeyMaterial::SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElRSAKeyMaterial_SaveParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

SB_INLINE void TElRSAKeyMaterial::LoadPublic(void * Buffer, int32_t Size)
{
	SBCheckError(TElRSAKeyMaterial_LoadPublic(_Handle, Buffer, Size));
}

SB_INLINE void TElRSAKeyMaterial::LoadPublic(void * Modulus, int32_t ModulusSize, void * Exponent, int32_t ExponentSize)
{
	SBCheckError(TElRSAKeyMaterial_LoadPublic_1(_Handle, Modulus, ModulusSize, Exponent, ExponentSize));
}

SB_INLINE void TElRSAKeyMaterial::LoadSecret(void * Buffer, int32_t Size)
{
	SBCheckError(TElRSAKeyMaterial_LoadSecret(_Handle, Buffer, Size));
}

SB_INLINE void TElRSAKeyMaterial::SavePublic(void * Buffer, int32_t &Size)
{
	SBCheckError(TElRSAKeyMaterial_SavePublic(_Handle, Buffer, &Size));
}

SB_INLINE void TElRSAKeyMaterial::SaveSecret(void * Buffer, int32_t &Size)
{
	SBCheckError(TElRSAKeyMaterial_SaveSecret(_Handle, Buffer, &Size));
}

SB_INLINE void TElRSAKeyMaterial::LoadFromXML(const std::string &Str)
{
	SBCheckError(TElRSAKeyMaterial_LoadFromXML(_Handle, Str.data(), (int32_t)Str.length()));
}

void TElRSAKeyMaterial::SaveToXML(bool IncludePrivateKey, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElRSAKeyMaterial_SaveToXML(_Handle, (int8_t)IncludePrivateKey, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-988686633, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElRSAKeyMaterial::EncodePublicKey(void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, const std::vector<uint8_t> &AlgID, void * OutBuffer, int32_t &OutSize, bool InnerValuesOnly)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRSAKeyMaterial_EncodePublicKey(_Handle, PublicModulus, PublicModulusSize, PublicExponent, PublicExponentSize, SB_STD_VECTOR_FRONT_ADR(AlgID), (int32_t)AlgID.size(), OutBuffer, &OutSize, (int8_t)InnerValuesOnly, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElRSAKeyMaterial::EncodePrivateKey(void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * PrivateExponent, int32_t PrivateExponentSize, void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRSAKeyMaterial_EncodePrivateKey(_Handle, PublicModulus, PublicModulusSize, PublicExponent, PublicExponentSize, PrivateExponent, PrivateExponentSize, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElRSAKeyMaterial::EncodePrivateKey(void * N, int32_t NSize, void * E, int32_t ESize, void * D, int32_t DSize, void * P, int32_t PSize, void * Q, int32_t QSize, void * DP, int32_t DPSize, void * DQ, int32_t DQSize, void * QInv, int32_t QInvSize, void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRSAKeyMaterial_EncodePrivateKey_1(_Handle, N, NSize, E, ESize, D, DSize, P, PSize, Q, QSize, DP, DPSize, DQ, DQSize, QInv, QInvSize, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElRSAKeyMaterial::EncodePrivateKey(void * N, int32_t NSize, void * E, int32_t ESize, void * D, int32_t DSize, void * P, int32_t PSize, void * Q, int32_t QSize, void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRSAKeyMaterial_EncodePrivateKey_2(_Handle, N, NSize, E, ESize, D, DSize, P, PSize, Q, QSize, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElRSAKeyMaterial::DecodePrivateKey(void * Blob, int32_t BlobSize, void * N, int32_t &NSize, void * E, int32_t &ESize, void * D, int32_t &DSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRSAKeyMaterial_DecodePrivateKey(_Handle, Blob, BlobSize, N, &NSize, E, &ESize, D, &DSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElRSAKeyMaterial::DecodePrivateKey(void * Blob, int32_t BlobSize, void * N, int32_t &NSize, void * E, int32_t &ESize, void * D, int32_t &DSize, void * P, int32_t &PSize, void * Q, int32_t &QSize, void * DP, int32_t &DPSize, void * DQ, int32_t &DQSize, void * QInv, int32_t &QInvSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRSAKeyMaterial_DecodePrivateKey_1(_Handle, Blob, BlobSize, N, &NSize, E, &ESize, D, &DSize, P, &PSize, Q, &QSize, DP, &DPSize, DQ, &DQSize, QInv, &QInvSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElRSAKeyMaterial::WritePSSParams(int32_t HashAlgorithm, int32_t SaltSize, int32_t MGFAlgorithm, int32_t TrailerField, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElRSAKeyMaterial_WritePSSParams(HashAlgorithm, SaltSize, MGFAlgorithm, TrailerField, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1545272018, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElRSAKeyMaterial::WritePSSParams_Inst(int32_t HashAlgorithm, int32_t SaltSize, int32_t MGFAlgorithm, int32_t TrailerField, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElRSAKeyMaterial_WritePSSParams_1(_Handle, HashAlgorithm, SaltSize, MGFAlgorithm, TrailerField, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1545272018, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElRSAKeyMaterial::ReadPSSParams(void * InBuffer, int32_t InBufferSize, int32_t &HashAlgorithm, int32_t &SaltSize, int32_t &MGF, int32_t &MGFHashAlgorithm, int32_t &TrailerField)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRSAKeyMaterial_ReadPSSParams(InBuffer, InBufferSize, &HashAlgorithm, &SaltSize, &MGF, &MGFHashAlgorithm, &TrailerField, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElRSAKeyMaterial::ReadPSSParams_Inst(void * InBuffer, int32_t InBufferSize, int32_t &HashAlgorithm, int32_t &SaltSize, int32_t &MGF, int32_t &MGFHashAlgorithm, int32_t &TrailerField)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRSAKeyMaterial_ReadPSSParams_1(_Handle, InBuffer, InBufferSize, &HashAlgorithm, &SaltSize, &MGF, &MGFHashAlgorithm, &TrailerField, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElRSAKeyMaterial::WriteOAEPParams(int32_t HashAlgorithm, int32_t MGFHashAlgorithm, const std::string &StrLabel, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElRSAKeyMaterial_WriteOAEPParams(HashAlgorithm, MGFHashAlgorithm, StrLabel.data(), (int32_t)StrLabel.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-907720355, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElRSAKeyMaterial::WriteOAEPParams_Inst(int32_t HashAlgorithm, int32_t MGFHashAlgorithm, const std::string &StrLabel, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElRSAKeyMaterial_WriteOAEPParams_1(_Handle, HashAlgorithm, MGFHashAlgorithm, StrLabel.data(), (int32_t)StrLabel.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-907720355, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElRSAKeyMaterial::ReadOAEPParams(void * InBuffer, int32_t InBufferSize, int32_t &HashAlgorithm, int32_t &MGFHashAlgorithm, std::string &StrLabel)
{
	int32_t szStrLabel = (int32_t)StrLabel.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElRSAKeyMaterial_ReadOAEPParams(InBuffer, InBufferSize, &HashAlgorithm, &MGFHashAlgorithm, (char *)StrLabel.data(), &szStrLabel, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		StrLabel.resize(szStrLabel);
		SBCheckError(SBGetLastReturnStringA(513475573, 4, (char *)StrLabel.data(), &szStrLabel));
	}
	else
		SBCheckError(_err);

	StrLabel.resize(szStrLabel);
	return (OutResultRaw != 0);
}

bool TElRSAKeyMaterial::ReadOAEPParams_Inst(void * InBuffer, int32_t InBufferSize, int32_t &HashAlgorithm, int32_t &MGFHashAlgorithm, std::string &StrLabel)
{
	int32_t szStrLabel = (int32_t)StrLabel.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElRSAKeyMaterial_ReadOAEPParams_1(_Handle, InBuffer, InBufferSize, &HashAlgorithm, &MGFHashAlgorithm, (char *)StrLabel.data(), &szStrLabel, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		StrLabel.resize(szStrLabel);
		SBCheckError(SBGetLastReturnStringA(513475573, 5, (char *)StrLabel.data(), &szStrLabel));
	}
	else
		SBCheckError(_err);

	StrLabel.resize(szStrLabel);
	return (OutResultRaw != 0);
}

SB_INLINE TElKeyMaterialHandle TElRSAKeyMaterial::Clone()
{
	TElKeyMaterialHandle OutResult;
	SBCheckError(TElRSAKeyMaterial_Clone(_Handle, &OutResult));
	return OutResult;
}

bool TElRSAKeyMaterial::Equals(TElKeyMaterial &Source, bool PublicOnly)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRSAKeyMaterial_Equals(_Handle, Source.getHandle(), (int8_t)PublicOnly, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElRSAKeyMaterial::Equals(TElKeyMaterial *Source, bool PublicOnly)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRSAKeyMaterial_Equals(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (int8_t)PublicOnly, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElRSAKeyMaterial::ClearSecret()
{
	SBCheckError(TElRSAKeyMaterial_ClearSecret(_Handle));
}

SB_INLINE void TElRSAKeyMaterial::ClearPublic()
{
	SBCheckError(TElRSAKeyMaterial_ClearPublic(_Handle));
}

TSBRSAKeyFormat TElRSAKeyMaterial::get_KeyFormat()
{
	TSBRSAKeyFormatRaw OutResultRaw = 0;
	SBCheckError(TElRSAKeyMaterial_get_KeyFormat(_Handle, &OutResultRaw));
	return (TSBRSAKeyFormat)OutResultRaw;
}

SB_INLINE void TElRSAKeyMaterial::set_KeyFormat(TSBRSAKeyFormat Value)
{
	SBCheckError(TElRSAKeyMaterial_set_KeyFormat(_Handle, (TSBRSAKeyFormatRaw)Value));
}

void TElRSAKeyMaterial::get_Passphrase(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElRSAKeyMaterial_get_Passphrase(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-272645688, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElRSAKeyMaterial::set_Passphrase(const std::string &Value)
{
	SBCheckError(TElRSAKeyMaterial_set_Passphrase(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElRSAKeyMaterial::get_PEMEncode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRSAKeyMaterial_get_PEMEncode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElRSAKeyMaterial::set_PEMEncode(bool Value)
{
	SBCheckError(TElRSAKeyMaterial_set_PEMEncode(_Handle, (int8_t)Value));
}

void TElRSAKeyMaterial::get_StrLabel(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElRSAKeyMaterial_get_StrLabel(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1400450787, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElRSAKeyMaterial::set_StrLabel(const std::string &Value)
{
	SBCheckError(TElRSAKeyMaterial_set_StrLabel(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElRSAKeyMaterial::get_SaltSize()
{
	int32_t OutResult;
	SBCheckError(TElRSAKeyMaterial_get_SaltSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRSAKeyMaterial::set_SaltSize(int32_t Value)
{
	SBCheckError(TElRSAKeyMaterial_set_SaltSize(_Handle, Value));
}

SB_INLINE int32_t TElRSAKeyMaterial::get_MGFAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElRSAKeyMaterial_get_MGFAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRSAKeyMaterial::set_MGFAlgorithm(int32_t Value)
{
	SBCheckError(TElRSAKeyMaterial_set_MGFAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElRSAKeyMaterial::get_TrailerField()
{
	int32_t OutResult;
	SBCheckError(TElRSAKeyMaterial_get_TrailerField(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRSAKeyMaterial::set_TrailerField(int32_t Value)
{
	SBCheckError(TElRSAKeyMaterial_set_TrailerField(_Handle, Value));
}

SB_INLINE int32_t TElRSAKeyMaterial::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElRSAKeyMaterial_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRSAKeyMaterial::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElRSAKeyMaterial_set_HashAlgorithm(_Handle, Value));
}

bool TElRSAKeyMaterial::get_RawPublicKey()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRSAKeyMaterial_get_RawPublicKey(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElRSAKeyMaterial::set_RawPublicKey(bool Value)
{
	SBCheckError(TElRSAKeyMaterial_set_RawPublicKey(_Handle, (int8_t)Value));
}

void TElRSAKeyMaterial::get_PublicModulus(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElRSAKeyMaterial_get_PublicModulus(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1053276381, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElRSAKeyMaterial::get_PublicExponent(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElRSAKeyMaterial_get_PublicExponent(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2131135916, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElRSAKeyMaterial::get_PrivateExponent(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElRSAKeyMaterial_get_PrivateExponent(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1734166804, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElRSAKeyMaterial::TElRSAKeyMaterial(TElRSAKeyMaterialHandle handle, TElOwnHandle ownHandle) : TElPublicKeyMaterial(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElRSAKeyMaterial::TElRSAKeyMaterial(TElCustomCryptoProvider &Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRSAKeyMaterial_Create(Prov.getHandle(), &_Handle));
}

TElRSAKeyMaterial::TElRSAKeyMaterial(TElCustomCryptoProvider *Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRSAKeyMaterial_Create((Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElRSAKeyMaterial::TElRSAKeyMaterial(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRSAKeyMaterial_Create_1(Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElRSAKeyMaterial::TElRSAKeyMaterial(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRSAKeyMaterial_Create_1((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELRSAKEYMATERIAL */

#ifdef SB_USE_CLASS_TELRSAPUBLICKEYCRYPTO

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElRSAPublicKeyCrypto::LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElRSAPublicKeyCrypto_LoadParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElRSAPublicKeyCrypto::LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElRSAPublicKeyCrypto_LoadParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElRSAPublicKeyCrypto::SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElRSAPublicKeyCrypto_SaveParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElRSAPublicKeyCrypto::SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElRSAPublicKeyCrypto_SaveParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELKEYMATERIAL
SB_INLINE TElKeyMaterialHandle TElRSAPublicKeyCrypto::DecryptKey(void * EncKey, int32_t EncKeySize, const std::vector<uint8_t> &EncKeyAlgOID, const std::vector<uint8_t> &EncKeyAlgParams)
{
	TElKeyMaterialHandle OutResult;
	SBCheckError(TElRSAPublicKeyCrypto_DecryptKey(_Handle, EncKey, EncKeySize, SB_STD_VECTOR_FRONT_ADR(EncKeyAlgOID), (int32_t)EncKeyAlgOID.size(), SB_STD_VECTOR_FRONT_ADR(EncKeyAlgParams), (int32_t)EncKeyAlgParams.size(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

SB_INLINE TClassHandle TElRSAPublicKeyCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElRSAPublicKeyCrypto_ClassType(&OutResult));
	return OutResult;
}

TSBRSAPublicKeyCryptoType TElRSAPublicKeyCrypto::get_CryptoType()
{
	TSBRSAPublicKeyCryptoTypeRaw OutResultRaw = 0;
	SBCheckError(TElRSAPublicKeyCrypto_get_CryptoType(_Handle, &OutResultRaw));
	return (TSBRSAPublicKeyCryptoType)OutResultRaw;
}

SB_INLINE void TElRSAPublicKeyCrypto::set_CryptoType(TSBRSAPublicKeyCryptoType Value)
{
	SBCheckError(TElRSAPublicKeyCrypto_set_CryptoType(_Handle, (TSBRSAPublicKeyCryptoTypeRaw)Value));
}

bool TElRSAPublicKeyCrypto::get_UseAlgorithmPrefix()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRSAPublicKeyCrypto_get_UseAlgorithmPrefix(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElRSAPublicKeyCrypto::set_UseAlgorithmPrefix(bool Value)
{
	SBCheckError(TElRSAPublicKeyCrypto_set_UseAlgorithmPrefix(_Handle, (int8_t)Value));
}

void TElRSAPublicKeyCrypto::get_HashFuncOID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElRSAPublicKeyCrypto_get_HashFuncOID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1663842686, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElRSAPublicKeyCrypto::set_HashFuncOID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElRSAPublicKeyCrypto_set_HashFuncOID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElRSAPublicKeyCrypto::get_SaltSize()
{
	int32_t OutResult;
	SBCheckError(TElRSAPublicKeyCrypto_get_SaltSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRSAPublicKeyCrypto::set_SaltSize(int32_t Value)
{
	SBCheckError(TElRSAPublicKeyCrypto_set_SaltSize(_Handle, Value));
}

void TElRSAPublicKeyCrypto::get_StrLabel(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElRSAPublicKeyCrypto_get_StrLabel(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(627013874, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElRSAPublicKeyCrypto::set_StrLabel(const std::string &Value)
{
	SBCheckError(TElRSAPublicKeyCrypto_set_StrLabel(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElRSAPublicKeyCrypto::get_TrailerField()
{
	int32_t OutResult;
	SBCheckError(TElRSAPublicKeyCrypto_get_TrailerField(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRSAPublicKeyCrypto::set_TrailerField(int32_t Value)
{
	SBCheckError(TElRSAPublicKeyCrypto_set_TrailerField(_Handle, Value));
}

SB_INLINE int32_t TElRSAPublicKeyCrypto::get_MGFAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElRSAPublicKeyCrypto_get_MGFAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRSAPublicKeyCrypto::set_MGFAlgorithm(int32_t Value)
{
	SBCheckError(TElRSAPublicKeyCrypto_set_MGFAlgorithm(_Handle, Value));
}

TElRSAPublicKeyCrypto::TElRSAPublicKeyCrypto(TElRSAPublicKeyCryptoHandle handle, TElOwnHandle ownHandle) : TElPublicKeyCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElRSAPublicKeyCrypto::TElRSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRSAPublicKeyCrypto_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), CryptoProvider.getHandle(), &_Handle));
}

TElRSAPublicKeyCrypto::TElRSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRSAPublicKeyCrypto_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElRSAPublicKeyCrypto::TElRSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRSAPublicKeyCrypto_Create_1(Alg, CryptoProvider.getHandle(), &_Handle));
}

TElRSAPublicKeyCrypto::TElRSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRSAPublicKeyCrypto_Create_1(Alg, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElRSAPublicKeyCrypto::TElRSAPublicKeyCrypto(TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRSAPublicKeyCrypto_Create_2(CryptoProvider.getHandle(), &_Handle));
}

TElRSAPublicKeyCrypto::TElRSAPublicKeyCrypto(TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRSAPublicKeyCrypto_Create_2((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElRSAPublicKeyCrypto::TElRSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRSAPublicKeyCrypto_Create_3(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElRSAPublicKeyCrypto::TElRSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRSAPublicKeyCrypto_Create_3(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElRSAPublicKeyCrypto::TElRSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRSAPublicKeyCrypto_Create_4(Alg, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElRSAPublicKeyCrypto::TElRSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRSAPublicKeyCrypto_Create_4(Alg, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElRSAPublicKeyCrypto::TElRSAPublicKeyCrypto(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRSAPublicKeyCrypto_Create_5(Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElRSAPublicKeyCrypto::TElRSAPublicKeyCrypto(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRSAPublicKeyCrypto_Create_5((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELRSAPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELDSAKEYMATERIAL

SB_INLINE void TElDSAKeyMaterial::Assign(TElKeyMaterial &Source)
{
	SBCheckError(TElDSAKeyMaterial_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDSAKeyMaterial::Assign(TElKeyMaterial *Source)
{
	SBCheckError(TElDSAKeyMaterial_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElDSAKeyMaterial::LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElDSAKeyMaterial_LoadParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElDSAKeyMaterial::LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElDSAKeyMaterial_LoadParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElDSAKeyMaterial::SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElDSAKeyMaterial_SaveParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElDSAKeyMaterial::SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElDSAKeyMaterial_SaveParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

SB_INLINE void TElDSAKeyMaterial::Generate(int32_t Bits)
{
	SBCheckError(TElDSAKeyMaterial_Generate(_Handle, Bits));
}

SB_INLINE void TElDSAKeyMaterial::Generate(int32_t PBits, int32_t QBits)
{
	SBCheckError(TElDSAKeyMaterial_Generate_1(_Handle, PBits, QBits));
}

SB_INLINE void TElDSAKeyMaterial::BeginGenerate(int32_t PBits, int32_t QBits)
{
	SBCheckError(TElDSAKeyMaterial_BeginGenerate(_Handle, PBits, QBits));
}

SB_INLINE void TElDSAKeyMaterial::LoadSecret(void * Buffer, int32_t Size)
{
	SBCheckError(TElDSAKeyMaterial_LoadSecret(_Handle, Buffer, Size));
}

SB_INLINE void TElDSAKeyMaterial::SaveSecret(void * Buffer, int32_t &Size)
{
	SBCheckError(TElDSAKeyMaterial_SaveSecret(_Handle, Buffer, &Size));
}

SB_INLINE void TElDSAKeyMaterial::LoadPublic(void * Buffer, int32_t Size)
{
	SBCheckError(TElDSAKeyMaterial_LoadPublic(_Handle, Buffer, Size));
}

SB_INLINE void TElDSAKeyMaterial::SavePublic(void * Buffer, int32_t &Size)
{
	SBCheckError(TElDSAKeyMaterial_SavePublic(_Handle, Buffer, &Size));
}

SB_INLINE void TElDSAKeyMaterial::ImportPublicKey(void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * Y, int32_t YSize)
{
	SBCheckError(TElDSAKeyMaterial_ImportPublicKey(_Handle, P, PSize, Q, QSize, G, GSize, Y, YSize));
}

SB_INLINE void TElDSAKeyMaterial::ExportPublicKey(void * P, int32_t &PSize, void * Q, int32_t &QSize, void * G, int32_t &GSize, void * Y, int32_t &YSize)
{
	SBCheckError(TElDSAKeyMaterial_ExportPublicKey(_Handle, P, &PSize, Q, &QSize, G, &GSize, Y, &YSize));
}

SB_INLINE void TElDSAKeyMaterial::LoadFromXML(const std::string &Str)
{
	SBCheckError(TElDSAKeyMaterial_LoadFromXML(_Handle, Str.data(), (int32_t)Str.length()));
}

void TElDSAKeyMaterial::SaveToXML(bool IncludePrivateKey, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDSAKeyMaterial_SaveToXML(_Handle, (int8_t)IncludePrivateKey, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-868493960, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElDSAKeyMaterial::EncodePrivateKey(void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * Y, int32_t YSize, void * X, int32_t XSize, void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDSAKeyMaterial_EncodePrivateKey(_Handle, P, PSize, Q, QSize, G, GSize, Y, YSize, X, XSize, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDSAKeyMaterial::DecodePrivateKey(void * Blob, int32_t BlobSize, void * P, int32_t &PSize, void * Q, int32_t &QSize, void * G, int32_t &GSize, void * Y, int32_t &YSize, void * X, int32_t &XSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDSAKeyMaterial_DecodePrivateKey(_Handle, Blob, BlobSize, P, &PSize, Q, &QSize, G, &GSize, Y, &YSize, X, &XSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TElKeyMaterialHandle TElDSAKeyMaterial::Clone()
{
	TElKeyMaterialHandle OutResult;
	SBCheckError(TElDSAKeyMaterial_Clone(_Handle, &OutResult));
	return OutResult;
}

bool TElDSAKeyMaterial::Equals(TElKeyMaterial &Source, bool PublicOnly)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDSAKeyMaterial_Equals(_Handle, Source.getHandle(), (int8_t)PublicOnly, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDSAKeyMaterial::Equals(TElKeyMaterial *Source, bool PublicOnly)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDSAKeyMaterial_Equals(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (int8_t)PublicOnly, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDSAKeyMaterial::ClearSecret()
{
	SBCheckError(TElDSAKeyMaterial_ClearSecret(_Handle));
}

SB_INLINE void TElDSAKeyMaterial::ClearPublic()
{
	SBCheckError(TElDSAKeyMaterial_ClearPublic(_Handle));
}

TSBDSAKeyFormat TElDSAKeyMaterial::get_KeyFormat()
{
	TSBDSAKeyFormatRaw OutResultRaw = 0;
	SBCheckError(TElDSAKeyMaterial_get_KeyFormat(_Handle, &OutResultRaw));
	return (TSBDSAKeyFormat)OutResultRaw;
}

SB_INLINE int32_t TElDSAKeyMaterial::get_QBits()
{
	int32_t OutResult;
	SBCheckError(TElDSAKeyMaterial_get_QBits(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDSAKeyMaterial::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElDSAKeyMaterial_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDSAKeyMaterial::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElDSAKeyMaterial_set_HashAlgorithm(_Handle, Value));
}

void TElDSAKeyMaterial::get_Passphrase(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDSAKeyMaterial_get_Passphrase(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-132735916, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDSAKeyMaterial::set_Passphrase(const std::string &Value)
{
	SBCheckError(TElDSAKeyMaterial_set_Passphrase(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElDSAKeyMaterial::get_PEMEncode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDSAKeyMaterial_get_PEMEncode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDSAKeyMaterial::set_PEMEncode(bool Value)
{
	SBCheckError(TElDSAKeyMaterial_set_PEMEncode(_Handle, (int8_t)Value));
}

bool TElDSAKeyMaterial::get_StrictKeyValidation()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDSAKeyMaterial_get_StrictKeyValidation(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDSAKeyMaterial::set_StrictKeyValidation(bool Value)
{
	SBCheckError(TElDSAKeyMaterial_set_StrictKeyValidation(_Handle, (int8_t)Value));
}

void TElDSAKeyMaterial::get_P(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDSAKeyMaterial_get_P(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1836464111, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDSAKeyMaterial::set_P(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDSAKeyMaterial_set_P(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElDSAKeyMaterial::get_Q(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDSAKeyMaterial_get_Q(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-443615097, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDSAKeyMaterial::set_Q(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDSAKeyMaterial_set_Q(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElDSAKeyMaterial::get_G(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDSAKeyMaterial_get_G(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(291130838, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDSAKeyMaterial::set_G(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDSAKeyMaterial_set_G(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElDSAKeyMaterial::get_Y(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDSAKeyMaterial_get_Y(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-346722123, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDSAKeyMaterial::set_Y(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDSAKeyMaterial_set_Y(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElDSAKeyMaterial::get_X(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDSAKeyMaterial_get_X(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1672331229, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDSAKeyMaterial::set_X(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDSAKeyMaterial_set_X(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElDSAKeyMaterial::TElDSAKeyMaterial(TElDSAKeyMaterialHandle handle, TElOwnHandle ownHandle) : TElPublicKeyMaterial(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElDSAKeyMaterial::TElDSAKeyMaterial(TElCustomCryptoProvider &Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDSAKeyMaterial_Create(Prov.getHandle(), &_Handle));
}

TElDSAKeyMaterial::TElDSAKeyMaterial(TElCustomCryptoProvider *Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDSAKeyMaterial_Create((Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElDSAKeyMaterial::TElDSAKeyMaterial(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDSAKeyMaterial_Create_1(Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElDSAKeyMaterial::TElDSAKeyMaterial(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDSAKeyMaterial_Create_1((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELDSAKEYMATERIAL */

#ifdef SB_USE_CLASS_TELDSAPUBLICKEYCRYPTO

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElDSAPublicKeyCrypto::LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElDSAPublicKeyCrypto_LoadParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElDSAPublicKeyCrypto::LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElDSAPublicKeyCrypto_LoadParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElDSAPublicKeyCrypto::SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElDSAPublicKeyCrypto_SaveParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElDSAPublicKeyCrypto::SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElDSAPublicKeyCrypto_SaveParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

SB_INLINE void TElDSAPublicKeyCrypto::EncodeSignature(void * R, int32_t RSize, void * S, int32_t SSize, void * Sig, int32_t &SigSize)
{
	SBCheckError(TElDSAPublicKeyCrypto_EncodeSignature(_Handle, R, RSize, S, SSize, Sig, &SigSize));
}

SB_INLINE void TElDSAPublicKeyCrypto::DecodeSignature(void * Sig, int32_t SigSize, void * R, int32_t &RSize, void * S, int32_t &SSize)
{
	SBCheckError(TElDSAPublicKeyCrypto_DecodeSignature(_Handle, Sig, SigSize, R, &RSize, S, &SSize));
}

SB_INLINE TClassHandle TElDSAPublicKeyCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElDSAPublicKeyCrypto_ClassType(&OutResult));
	return OutResult;
}

TElDSAPublicKeyCrypto::TElDSAPublicKeyCrypto(TElDSAPublicKeyCryptoHandle handle, TElOwnHandle ownHandle) : TElPublicKeyCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElDSAPublicKeyCrypto::TElDSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDSAPublicKeyCrypto_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), CryptoProvider.getHandle(), &_Handle));
}

TElDSAPublicKeyCrypto::TElDSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDSAPublicKeyCrypto_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElDSAPublicKeyCrypto::TElDSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDSAPublicKeyCrypto_Create_1(Alg, CryptoProvider.getHandle(), &_Handle));
}

TElDSAPublicKeyCrypto::TElDSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDSAPublicKeyCrypto_Create_1(Alg, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElDSAPublicKeyCrypto::TElDSAPublicKeyCrypto(TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDSAPublicKeyCrypto_Create_2(CryptoProvider.getHandle(), &_Handle));
}

TElDSAPublicKeyCrypto::TElDSAPublicKeyCrypto(TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDSAPublicKeyCrypto_Create_2((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElDSAPublicKeyCrypto::TElDSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDSAPublicKeyCrypto_Create_3(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElDSAPublicKeyCrypto::TElDSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDSAPublicKeyCrypto_Create_3(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElDSAPublicKeyCrypto::TElDSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDSAPublicKeyCrypto_Create_4(Alg, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElDSAPublicKeyCrypto::TElDSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDSAPublicKeyCrypto_Create_4(Alg, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElDSAPublicKeyCrypto::TElDSAPublicKeyCrypto(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDSAPublicKeyCrypto_Create_5(Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElDSAPublicKeyCrypto::TElDSAPublicKeyCrypto(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDSAPublicKeyCrypto_Create_5((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELDSAPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELECKEYMATERIAL

SB_INLINE void TElECKeyMaterial::Assign(TElKeyMaterial &Source)
{
	SBCheckError(TElECKeyMaterial_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElECKeyMaterial::Assign(TElKeyMaterial *Source)
{
	SBCheckError(TElECKeyMaterial_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElECKeyMaterial::Generate()
{
	SBCheckError(TElECKeyMaterial_Generate(_Handle));
}

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElECKeyMaterial::LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElECKeyMaterial_LoadParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElECKeyMaterial::LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElECKeyMaterial_LoadParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElECKeyMaterial::SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElECKeyMaterial_SaveParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElECKeyMaterial::SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElECKeyMaterial_SaveParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

SB_INLINE void TElECKeyMaterial::LoadSecret(void * Buffer, int32_t Size)
{
	SBCheckError(TElECKeyMaterial_LoadSecret(_Handle, Buffer, Size));
}

SB_INLINE void TElECKeyMaterial::SaveSecret(void * Buffer, int32_t &Size)
{
	SBCheckError(TElECKeyMaterial_SaveSecret(_Handle, Buffer, &Size));
}

SB_INLINE void TElECKeyMaterial::LoadPublic(void * Buffer, int32_t Size)
{
	SBCheckError(TElECKeyMaterial_LoadPublic(_Handle, Buffer, Size));
}

SB_INLINE void TElECKeyMaterial::SavePublic(void * Buffer, int32_t &Size)
{
	SBCheckError(TElECKeyMaterial_SavePublic(_Handle, Buffer, &Size));
}

SB_INLINE void TElECKeyMaterial::ImportPublicKey(void * QX, int32_t QXSize, void * QY, int32_t QYSize)
{
	SBCheckError(TElECKeyMaterial_ImportPublicKey(_Handle, QX, QXSize, QY, QYSize));
}

SB_INLINE void TElECKeyMaterial::ExportPublicKey(void * QX, int32_t &QXSize, void * QY, int32_t &QYSize)
{
	SBCheckError(TElECKeyMaterial_ExportPublicKey(_Handle, QX, &QXSize, QY, &QYSize));
}

SB_INLINE TElKeyMaterialHandle TElECKeyMaterial::Clone()
{
	TElKeyMaterialHandle OutResult;
	SBCheckError(TElECKeyMaterial_Clone(_Handle, &OutResult));
	return OutResult;
}

bool TElECKeyMaterial::Equals(TElKeyMaterial &Source, bool PublicOnly)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECKeyMaterial_Equals(_Handle, Source.getHandle(), (int8_t)PublicOnly, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElECKeyMaterial::Equals(TElKeyMaterial *Source, bool PublicOnly)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECKeyMaterial_Equals(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (int8_t)PublicOnly, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElECKeyMaterial::ClearSecret()
{
	SBCheckError(TElECKeyMaterial_ClearSecret(_Handle));
}

SB_INLINE void TElECKeyMaterial::ClearPublic()
{
	SBCheckError(TElECKeyMaterial_ClearPublic(_Handle));
}

bool TElECKeyMaterial::EncodePrivateKey(void * D, int32_t DSize, void * Qx, int32_t QxSize, void * Qy, int32_t QySize, int32_t Curve, void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECKeyMaterial_EncodePrivateKey(_Handle, D, DSize, Qx, QxSize, Qy, QySize, Curve, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElECKeyMaterial::DecodePrivateKey(void * Blob, int32_t BlobSize, void * D, int32_t &DSize, void * Qx, int32_t &QxSize, void * Qy, int32_t &QySize, int32_t &Curve)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECKeyMaterial_DecodePrivateKey(_Handle, Blob, BlobSize, D, &DSize, Qx, &QxSize, Qy, &QySize, &Curve, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElECKeyMaterial::get_CompressPoints()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECKeyMaterial_get_CompressPoints(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElECKeyMaterial::set_CompressPoints(bool Value)
{
	SBCheckError(TElECKeyMaterial_set_CompressPoints(_Handle, (int8_t)Value));
}

bool TElECKeyMaterial::get_HybridPoints()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECKeyMaterial_get_HybridPoints(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElECKeyMaterial::set_HybridPoints(bool Value)
{
	SBCheckError(TElECKeyMaterial_set_HybridPoints(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElECKeyMaterial::get_FieldType()
{
	int32_t OutResult;
	SBCheckError(TElECKeyMaterial_get_FieldType(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECKeyMaterial::set_FieldType(int32_t Value)
{
	SBCheckError(TElECKeyMaterial_set_FieldType(_Handle, Value));
}

SB_INLINE int32_t TElECKeyMaterial::get_Field()
{
	int32_t OutResult;
	SBCheckError(TElECKeyMaterial_get_Field(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElECKeyMaterial::get_FieldBits()
{
	int32_t OutResult;
	SBCheckError(TElECKeyMaterial_get_FieldBits(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElECKeyMaterial::get_M()
{
	int32_t OutResult;
	SBCheckError(TElECKeyMaterial_get_M(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECKeyMaterial::set_M(int32_t Value)
{
	SBCheckError(TElECKeyMaterial_set_M(_Handle, Value));
}

SB_INLINE int32_t TElECKeyMaterial::get_K1()
{
	int32_t OutResult;
	SBCheckError(TElECKeyMaterial_get_K1(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECKeyMaterial::set_K1(int32_t Value)
{
	SBCheckError(TElECKeyMaterial_set_K1(_Handle, Value));
}

SB_INLINE int32_t TElECKeyMaterial::get_K2()
{
	int32_t OutResult;
	SBCheckError(TElECKeyMaterial_get_K2(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECKeyMaterial::set_K2(int32_t Value)
{
	SBCheckError(TElECKeyMaterial_set_K2(_Handle, Value));
}

SB_INLINE int32_t TElECKeyMaterial::get_K3()
{
	int32_t OutResult;
	SBCheckError(TElECKeyMaterial_get_K3(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECKeyMaterial::set_K3(int32_t Value)
{
	SBCheckError(TElECKeyMaterial_set_K3(_Handle, Value));
}

SB_INLINE int32_t TElECKeyMaterial::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElECKeyMaterial_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECKeyMaterial::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElECKeyMaterial_set_HashAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElECKeyMaterial::get_RecommendedHashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElECKeyMaterial_get_RecommendedHashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

void TElECKeyMaterial::get_D(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECKeyMaterial_get_D(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1021177120, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECKeyMaterial::set_D(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECKeyMaterial_set_D(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElECKeyMaterial::get_N(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECKeyMaterial_get_N(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(603454462, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECKeyMaterial::set_N(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECKeyMaterial_set_N(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElECKeyMaterial::get_H()
{
	int32_t OutResult;
	SBCheckError(TElECKeyMaterial_get_H(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECKeyMaterial::set_H(int32_t Value)
{
	SBCheckError(TElECKeyMaterial_set_H(_Handle, Value));
}

void TElECKeyMaterial::get_A(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECKeyMaterial_get_A(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1287068049, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECKeyMaterial::set_A(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECKeyMaterial_set_A(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElECKeyMaterial::get_B(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECKeyMaterial_get_B(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(708949973, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECKeyMaterial::set_B(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECKeyMaterial_set_B(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElECKeyMaterial::get_X(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECKeyMaterial_get_X(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-685551953, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECKeyMaterial::set_X(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECKeyMaterial_set_X(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElECKeyMaterial::get_Y(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECKeyMaterial_get_Y(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1608221127, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECKeyMaterial::set_Y(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECKeyMaterial_set_Y(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElECKeyMaterial::get_Q(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECKeyMaterial_get_Q(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1358957045, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECKeyMaterial::set_Q(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECKeyMaterial_set_Q(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElECKeyMaterial::get_QX(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECKeyMaterial_get_QX(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-221446216, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECKeyMaterial::set_QX(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECKeyMaterial_set_QX(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElECKeyMaterial::get_QY(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECKeyMaterial_get_QY(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2050240722, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECKeyMaterial::set_QY(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECKeyMaterial_set_QY(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElECKeyMaterial::get_Base(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECKeyMaterial_get_Base(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1371709565, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECKeyMaterial::set_Base(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECKeyMaterial_set_Base(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElECKeyMaterial::get_P(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECKeyMaterial_get_P(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-638007651, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECKeyMaterial::set_P(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECKeyMaterial_set_P(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElECKeyMaterial::get_Curve()
{
	int32_t OutResult;
	SBCheckError(TElECKeyMaterial_get_Curve(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECKeyMaterial::set_Curve(int32_t Value)
{
	SBCheckError(TElECKeyMaterial_set_Curve(_Handle, Value));
}

void TElECKeyMaterial::get_CurveOID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECKeyMaterial_get_CurveOID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(832490290, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECKeyMaterial::set_CurveOID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECKeyMaterial_set_CurveOID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElECKeyMaterial::get_SpecifiedCurve()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECKeyMaterial_get_SpecifiedCurve(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElECKeyMaterial::set_SpecifiedCurve(bool Value)
{
	SBCheckError(TElECKeyMaterial_set_SpecifiedCurve(_Handle, (int8_t)Value));
}

bool TElECKeyMaterial::get_ImplicitCurve()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECKeyMaterial_get_ImplicitCurve(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElECKeyMaterial::set_ImplicitCurve(bool Value)
{
	SBCheckError(TElECKeyMaterial_set_ImplicitCurve(_Handle, (int8_t)Value));
}

void TElECKeyMaterial::get_Seed(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECKeyMaterial_get_Seed(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-705577702, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECKeyMaterial::set_Seed(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECKeyMaterial_set_Seed(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElECKeyMaterial::TElECKeyMaterial(TElECKeyMaterialHandle handle, TElOwnHandle ownHandle) : TElPublicKeyMaterial(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElECKeyMaterial::TElECKeyMaterial(TElCustomCryptoProvider &Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECKeyMaterial_Create(Prov.getHandle(), &_Handle));
}

TElECKeyMaterial::TElECKeyMaterial(TElCustomCryptoProvider *Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECKeyMaterial_Create((Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElECKeyMaterial::TElECKeyMaterial(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECKeyMaterial_Create_1(Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElECKeyMaterial::TElECKeyMaterial(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECKeyMaterial_Create_1((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELECKEYMATERIAL */

#ifdef SB_USE_CLASS_TELECDSAPUBLICKEYCRYPTO

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElECDSAPublicKeyCrypto::LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElECDSAPublicKeyCrypto_LoadParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElECDSAPublicKeyCrypto::LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElECDSAPublicKeyCrypto_LoadParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElECDSAPublicKeyCrypto::SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElECDSAPublicKeyCrypto_SaveParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElECDSAPublicKeyCrypto::SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElECDSAPublicKeyCrypto_SaveParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

SB_INLINE void TElECDSAPublicKeyCrypto::EncodeSignature(void * R, int32_t RSize, void * S, int32_t SSize, void * Sig, int32_t &SigSize)
{
	SBCheckError(TElECDSAPublicKeyCrypto_EncodeSignature(_Handle, R, RSize, S, SSize, Sig, &SigSize));
}

SB_INLINE void TElECDSAPublicKeyCrypto::DecodeSignature(void * Sig, int32_t SigSize, void * R, int32_t &RSize, void * S, int32_t &SSize)
{
	SBCheckError(TElECDSAPublicKeyCrypto_DecodeSignature(_Handle, Sig, SigSize, R, &RSize, S, &SSize));
}

SB_INLINE TClassHandle TElECDSAPublicKeyCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElECDSAPublicKeyCrypto_ClassType(&OutResult));
	return OutResult;
}

TElECDSAPublicKeyCrypto::TElECDSAPublicKeyCrypto(TElECDSAPublicKeyCryptoHandle handle, TElOwnHandle ownHandle) : TElPublicKeyCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElECDSAPublicKeyCrypto::TElECDSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDSAPublicKeyCrypto_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), CryptoProvider.getHandle(), &_Handle));
}

TElECDSAPublicKeyCrypto::TElECDSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDSAPublicKeyCrypto_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElECDSAPublicKeyCrypto::TElECDSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDSAPublicKeyCrypto_Create_1(Alg, CryptoProvider.getHandle(), &_Handle));
}

TElECDSAPublicKeyCrypto::TElECDSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDSAPublicKeyCrypto_Create_1(Alg, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElECDSAPublicKeyCrypto::TElECDSAPublicKeyCrypto(TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDSAPublicKeyCrypto_Create_2(CryptoProvider.getHandle(), &_Handle));
}

TElECDSAPublicKeyCrypto::TElECDSAPublicKeyCrypto(TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDSAPublicKeyCrypto_Create_2((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElECDSAPublicKeyCrypto::TElECDSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDSAPublicKeyCrypto_Create_3(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElECDSAPublicKeyCrypto::TElECDSAPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDSAPublicKeyCrypto_Create_3(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElECDSAPublicKeyCrypto::TElECDSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDSAPublicKeyCrypto_Create_4(Alg, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElECDSAPublicKeyCrypto::TElECDSAPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDSAPublicKeyCrypto_Create_4(Alg, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElECDSAPublicKeyCrypto::TElECDSAPublicKeyCrypto(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDSAPublicKeyCrypto_Create_5(Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElECDSAPublicKeyCrypto::TElECDSAPublicKeyCrypto(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDSAPublicKeyCrypto_Create_5((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELECDSAPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELECDHPUBLICKEYCRYPTO

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElECDHPublicKeyCrypto::LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElECDHPublicKeyCrypto_LoadParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElECDHPublicKeyCrypto::LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElECDHPublicKeyCrypto_LoadParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElECDHPublicKeyCrypto::SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElECDHPublicKeyCrypto_SaveParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElECDHPublicKeyCrypto::SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElECDHPublicKeyCrypto_SaveParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

SB_INLINE TClassHandle TElECDHPublicKeyCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElECDHPublicKeyCrypto_ClassType(&OutResult));
	return OutResult;
}

TElECDHPublicKeyCrypto::TElECDHPublicKeyCrypto(TElECDHPublicKeyCryptoHandle handle, TElOwnHandle ownHandle) : TElPublicKeyCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElECDHPublicKeyCrypto::TElECDHPublicKeyCrypto(TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDHPublicKeyCrypto_Create(CryptoProvider.getHandle(), &_Handle));
}

TElECDHPublicKeyCrypto::TElECDHPublicKeyCrypto(TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDHPublicKeyCrypto_Create((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElECDHPublicKeyCrypto::TElECDHPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDHPublicKeyCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), CryptoProvider.getHandle(), &_Handle));
}

TElECDHPublicKeyCrypto::TElECDHPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDHPublicKeyCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElECDHPublicKeyCrypto::TElECDHPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDHPublicKeyCrypto_Create_2(Alg, CryptoProvider.getHandle(), &_Handle));
}

TElECDHPublicKeyCrypto::TElECDHPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDHPublicKeyCrypto_Create_2(Alg, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElECDHPublicKeyCrypto::TElECDHPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDHPublicKeyCrypto_Create_3(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElECDHPublicKeyCrypto::TElECDHPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDHPublicKeyCrypto_Create_3(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElECDHPublicKeyCrypto::TElECDHPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDHPublicKeyCrypto_Create_4(Alg, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElECDHPublicKeyCrypto::TElECDHPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDHPublicKeyCrypto_Create_4(Alg, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElECDHPublicKeyCrypto::TElECDHPublicKeyCrypto(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDHPublicKeyCrypto_Create_5(Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElECDHPublicKeyCrypto::TElECDHPublicKeyCrypto(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDHPublicKeyCrypto_Create_5((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELECDHPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELDHKEYMATERIAL

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElDHKeyMaterial::LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElDHKeyMaterial_LoadParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElDHKeyMaterial::LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElDHKeyMaterial_LoadParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElDHKeyMaterial::SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElDHKeyMaterial_SaveParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElDHKeyMaterial::SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElDHKeyMaterial_SaveParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

SB_INLINE void TElDHKeyMaterial::LoadPublic(void * P, int32_t PSize, void * G, int32_t GSize, void * Y, int32_t YSize)
{
	SBCheckError(TElDHKeyMaterial_LoadPublic(_Handle, P, PSize, G, GSize, Y, YSize));
}

SB_INLINE void TElDHKeyMaterial::SavePublic(void * Buffer, int32_t &Size)
{
	SBCheckError(TElDHKeyMaterial_SavePublic(_Handle, Buffer, &Size));
}

SB_INLINE void TElDHKeyMaterial::SaveSecret(void * Buffer, int32_t &Size)
{
	SBCheckError(TElDHKeyMaterial_SaveSecret(_Handle, Buffer, &Size));
}

SB_INLINE void TElDHKeyMaterial::LoadSecret(void * Buffer, int32_t Size)
{
	SBCheckError(TElDHKeyMaterial_LoadSecret(_Handle, Buffer, Size));
}

SB_INLINE void TElDHKeyMaterial::LoadPeerY(void * Y, int32_t YSize)
{
	SBCheckError(TElDHKeyMaterial_LoadPeerY(_Handle, Y, YSize));
}

SB_INLINE void TElDHKeyMaterial::LoadFromXML(const std::string &Str)
{
	SBCheckError(TElDHKeyMaterial_LoadFromXML(_Handle, Str.data(), (int32_t)Str.length()));
}

void TElDHKeyMaterial::SaveToXML(bool IncludePrivateKey, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDHKeyMaterial_SaveToXML(_Handle, (int8_t)IncludePrivateKey, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1774934598, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDHKeyMaterial::Assign(TElKeyMaterial &Source)
{
	SBCheckError(TElDHKeyMaterial_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDHKeyMaterial::Assign(TElKeyMaterial *Source)
{
	SBCheckError(TElDHKeyMaterial_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElKeyMaterialHandle TElDHKeyMaterial::Clone()
{
	TElKeyMaterialHandle OutResult;
	SBCheckError(TElDHKeyMaterial_Clone(_Handle, &OutResult));
	return OutResult;
}

bool TElDHKeyMaterial::Equals(TElKeyMaterial &Source, bool PublicOnly)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDHKeyMaterial_Equals(_Handle, Source.getHandle(), (int8_t)PublicOnly, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDHKeyMaterial::Equals(TElKeyMaterial *Source, bool PublicOnly)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDHKeyMaterial_Equals(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (int8_t)PublicOnly, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDHKeyMaterial::ClearSecret()
{
	SBCheckError(TElDHKeyMaterial_ClearSecret(_Handle));
}

SB_INLINE void TElDHKeyMaterial::ClearPublic()
{
	SBCheckError(TElDHKeyMaterial_ClearPublic(_Handle));
}

TSBDHKeyFormat TElDHKeyMaterial::get_KeyFormat()
{
	TSBDHKeyFormatRaw OutResultRaw = 0;
	SBCheckError(TElDHKeyMaterial_get_KeyFormat(_Handle, &OutResultRaw));
	return (TSBDHKeyFormat)OutResultRaw;
}

void TElDHKeyMaterial::get_P(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDHKeyMaterial_get_P(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-204655189, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDHKeyMaterial::set_P(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDHKeyMaterial_set_P(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElDHKeyMaterial::get_G(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDHKeyMaterial_get_G(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1881059436, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDHKeyMaterial::set_G(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDHKeyMaterial_set_G(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElDHKeyMaterial::get_X(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDHKeyMaterial_get_X(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-48841319, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDHKeyMaterial::set_X(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDHKeyMaterial_set_X(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElDHKeyMaterial::get_Y(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDHKeyMaterial_get_Y(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1978561265, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDHKeyMaterial::set_Y(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDHKeyMaterial_set_Y(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElDHKeyMaterial::get_PeerY(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDHKeyMaterial_get_PeerY(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1351594236, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDHKeyMaterial::set_PeerY(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDHKeyMaterial_set_PeerY(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElDHKeyMaterial::get_PreserveGroupParameters()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDHKeyMaterial_get_PreserveGroupParameters(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDHKeyMaterial::set_PreserveGroupParameters(bool Value)
{
	SBCheckError(TElDHKeyMaterial_set_PreserveGroupParameters(_Handle, (int8_t)Value));
}

TElDHKeyMaterial::TElDHKeyMaterial(TElDHKeyMaterialHandle handle, TElOwnHandle ownHandle) : TElPublicKeyMaterial(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElDHKeyMaterial::TElDHKeyMaterial(TElCustomCryptoProvider &Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDHKeyMaterial_Create(Prov.getHandle(), &_Handle));
}

TElDHKeyMaterial::TElDHKeyMaterial(TElCustomCryptoProvider *Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDHKeyMaterial_Create((Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElDHKeyMaterial::TElDHKeyMaterial(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDHKeyMaterial_Create_1(Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElDHKeyMaterial::TElDHKeyMaterial(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDHKeyMaterial_Create_1((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELDHKEYMATERIAL */

#ifdef SB_USE_CLASS_TELDHPUBLICKEYCRYPTO

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElDHPublicKeyCrypto::LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElDHPublicKeyCrypto_LoadParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElDHPublicKeyCrypto::LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElDHPublicKeyCrypto_LoadParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElDHPublicKeyCrypto::SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElDHPublicKeyCrypto_SaveParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElDHPublicKeyCrypto::SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElDHPublicKeyCrypto_SaveParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

SB_INLINE TClassHandle TElDHPublicKeyCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElDHPublicKeyCrypto_ClassType(&OutResult));
	return OutResult;
}

TSBDHPublicKeyCryptoType TElDHPublicKeyCrypto::get_CryptoType()
{
	TSBDHPublicKeyCryptoTypeRaw OutResultRaw = 0;
	SBCheckError(TElDHPublicKeyCrypto_get_CryptoType(_Handle, &OutResultRaw));
	return (TSBDHPublicKeyCryptoType)OutResultRaw;
}

SB_INLINE void TElDHPublicKeyCrypto::set_CryptoType(TSBDHPublicKeyCryptoType Value)
{
	SBCheckError(TElDHPublicKeyCrypto_set_CryptoType(_Handle, (TSBDHPublicKeyCryptoTypeRaw)Value));
}

TElDHPublicKeyCrypto::TElDHPublicKeyCrypto(TElDHPublicKeyCryptoHandle handle, TElOwnHandle ownHandle) : TElPublicKeyCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElDHPublicKeyCrypto::TElDHPublicKeyCrypto(TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDHPublicKeyCrypto_Create(CryptoProvider.getHandle(), &_Handle));
}

TElDHPublicKeyCrypto::TElDHPublicKeyCrypto(TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDHPublicKeyCrypto_Create((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElDHPublicKeyCrypto::TElDHPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDHPublicKeyCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), CryptoProvider.getHandle(), &_Handle));
}

TElDHPublicKeyCrypto::TElDHPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDHPublicKeyCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElDHPublicKeyCrypto::TElDHPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDHPublicKeyCrypto_Create_2(Alg, CryptoProvider.getHandle(), &_Handle));
}

TElDHPublicKeyCrypto::TElDHPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDHPublicKeyCrypto_Create_2(Alg, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElDHPublicKeyCrypto::TElDHPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDHPublicKeyCrypto_Create_3(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElDHPublicKeyCrypto::TElDHPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDHPublicKeyCrypto_Create_3(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElDHPublicKeyCrypto::TElDHPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDHPublicKeyCrypto_Create_4(Alg, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElDHPublicKeyCrypto::TElDHPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDHPublicKeyCrypto_Create_4(Alg, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElDHPublicKeyCrypto::TElDHPublicKeyCrypto(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDHPublicKeyCrypto_Create_5(Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElDHPublicKeyCrypto::TElDHPublicKeyCrypto(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDHPublicKeyCrypto_Create_5((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELDHPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELELGAMALKEYMATERIAL

SB_INLINE void TElElGamalKeyMaterial::Assign(TElKeyMaterial &Source)
{
	SBCheckError(TElElGamalKeyMaterial_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElElGamalKeyMaterial::Assign(TElKeyMaterial *Source)
{
	SBCheckError(TElElGamalKeyMaterial_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElKeyMaterialHandle TElElGamalKeyMaterial::Clone()
{
	TElKeyMaterialHandle OutResult;
	SBCheckError(TElElGamalKeyMaterial_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElElGamalKeyMaterial::LoadPublic(void * P, int32_t PSize, void * G, int32_t GSize, void * Y, int32_t YSize)
{
	SBCheckError(TElElGamalKeyMaterial_LoadPublic(_Handle, P, PSize, G, GSize, Y, YSize));
}

SB_INLINE void TElElGamalKeyMaterial::LoadSecret(void * P, int32_t PSize, void * G, int32_t GSize, void * Y, int32_t YSize, void * X, int32_t XSize)
{
	SBCheckError(TElElGamalKeyMaterial_LoadSecret(_Handle, P, PSize, G, GSize, Y, YSize, X, XSize));
}

SB_INLINE void TElElGamalKeyMaterial::SavePublic(void * Buffer, int32_t &Size)
{
	SBCheckError(TElElGamalKeyMaterial_SavePublic(_Handle, Buffer, &Size));
}

SB_INLINE void TElElGamalKeyMaterial::SaveSecret(void * Buffer, int32_t &Size)
{
	SBCheckError(TElElGamalKeyMaterial_SaveSecret(_Handle, Buffer, &Size));
}

SB_INLINE void TElElGamalKeyMaterial::LoadFromXML(const std::string &Str)
{
	SBCheckError(TElElGamalKeyMaterial_LoadFromXML(_Handle, Str.data(), (int32_t)Str.length()));
}

void TElElGamalKeyMaterial::SaveToXML(bool IncludePrivateKey, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElElGamalKeyMaterial_SaveToXML(_Handle, (int8_t)IncludePrivateKey, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1839728447, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElElGamalKeyMaterial::Equals(TElKeyMaterial &Source, bool PublicOnly)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElElGamalKeyMaterial_Equals(_Handle, Source.getHandle(), (int8_t)PublicOnly, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElElGamalKeyMaterial::Equals(TElKeyMaterial *Source, bool PublicOnly)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElElGamalKeyMaterial_Equals(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (int8_t)PublicOnly, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElElGamalKeyMaterial::ClearSecret()
{
	SBCheckError(TElElGamalKeyMaterial_ClearSecret(_Handle));
}

SB_INLINE void TElElGamalKeyMaterial::ClearPublic()
{
	SBCheckError(TElElGamalKeyMaterial_ClearPublic(_Handle));
}

void TElElGamalKeyMaterial::get_P(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElElGamalKeyMaterial_get_P(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(445539530, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElElGamalKeyMaterial::get_G(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElElGamalKeyMaterial_get_G(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1721900787, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElElGamalKeyMaterial::get_Y(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElElGamalKeyMaterial_get_Y(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1666374766, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElElGamalKeyMaterial::get_X(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElElGamalKeyMaterial_get_X(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(341175544, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElElGamalKeyMaterial::TElElGamalKeyMaterial(TElElGamalKeyMaterialHandle handle, TElOwnHandle ownHandle) : TElPublicKeyMaterial(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElElGamalKeyMaterial::TElElGamalKeyMaterial(TElCustomCryptoProvider &Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElElGamalKeyMaterial_Create(Prov.getHandle(), &_Handle));
}

TElElGamalKeyMaterial::TElElGamalKeyMaterial(TElCustomCryptoProvider *Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElElGamalKeyMaterial_Create((Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElElGamalKeyMaterial::TElElGamalKeyMaterial(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElElGamalKeyMaterial_Create_1(Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElElGamalKeyMaterial::TElElGamalKeyMaterial(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElElGamalKeyMaterial_Create_1((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELELGAMALKEYMATERIAL */

#ifdef SB_USE_CLASS_TELELGAMALPUBLICKEYCRYPTO

SB_INLINE void TElElGamalPublicKeyCrypto::EncodeResult(void * A, int32_t ASize, void * B, int32_t BSize, void * Blob, int32_t &BlobSize)
{
	SBCheckError(TElElGamalPublicKeyCrypto_EncodeResult(_Handle, A, ASize, B, BSize, Blob, &BlobSize));
}

SB_INLINE void TElElGamalPublicKeyCrypto::DecodeResult(void * Blob, int32_t BlobSize, void * A, int32_t &ASize, void * B, int32_t &BSize)
{
	SBCheckError(TElElGamalPublicKeyCrypto_DecodeResult(_Handle, Blob, BlobSize, A, &ASize, B, &BSize));
}

SB_INLINE TClassHandle TElElGamalPublicKeyCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElElGamalPublicKeyCrypto_ClassType(&OutResult));
	return OutResult;
}

TElElGamalPublicKeyCrypto::TElElGamalPublicKeyCrypto(TElElGamalPublicKeyCryptoHandle handle, TElOwnHandle ownHandle) : TElPublicKeyCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElElGamalPublicKeyCrypto::TElElGamalPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElElGamalPublicKeyCrypto_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), CryptoProvider.getHandle(), &_Handle));
}

TElElGamalPublicKeyCrypto::TElElGamalPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElElGamalPublicKeyCrypto_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElElGamalPublicKeyCrypto::TElElGamalPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElElGamalPublicKeyCrypto_Create_1(Alg, CryptoProvider.getHandle(), &_Handle));
}

TElElGamalPublicKeyCrypto::TElElGamalPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElElGamalPublicKeyCrypto_Create_1(Alg, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElElGamalPublicKeyCrypto::TElElGamalPublicKeyCrypto(TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElElGamalPublicKeyCrypto_Create_2(CryptoProvider.getHandle(), &_Handle));
}

TElElGamalPublicKeyCrypto::TElElGamalPublicKeyCrypto(TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElElGamalPublicKeyCrypto_Create_2((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElElGamalPublicKeyCrypto::TElElGamalPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElElGamalPublicKeyCrypto_Create_3(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElElGamalPublicKeyCrypto::TElElGamalPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElElGamalPublicKeyCrypto_Create_3(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElElGamalPublicKeyCrypto::TElElGamalPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElElGamalPublicKeyCrypto_Create_4(Alg, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElElGamalPublicKeyCrypto::TElElGamalPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElElGamalPublicKeyCrypto_Create_4(Alg, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElElGamalPublicKeyCrypto::TElElGamalPublicKeyCrypto(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElElGamalPublicKeyCrypto_Create_5(Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElElGamalPublicKeyCrypto::TElElGamalPublicKeyCrypto(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElElGamalPublicKeyCrypto_Create_5((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELELGAMALPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELSRPKEYMATERIAL

SB_INLINE void TElSRPKeyMaterial::Assign(TElKeyMaterial &Source)
{
	SBCheckError(TElSRPKeyMaterial_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSRPKeyMaterial::Assign(TElKeyMaterial *Source)
{
	SBCheckError(TElSRPKeyMaterial_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

bool TElSRPKeyMaterial::LoadPublic(const std::vector<uint8_t> &N, const std::vector<uint8_t> &G, const std::vector<uint8_t> &Salt, const std::vector<uint8_t> &V)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSRPKeyMaterial_LoadPublic(_Handle, SB_STD_VECTOR_FRONT_ADR(N), (int32_t)N.size(), SB_STD_VECTOR_FRONT_ADR(G), (int32_t)G.size(), SB_STD_VECTOR_FRONT_ADR(Salt), (int32_t)Salt.size(), SB_STD_VECTOR_FRONT_ADR(V), (int32_t)V.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElSRPKeyMaterial::LoadPublic(void * Buffer, int32_t Len, bool &OutResult)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSRPKeyMaterial_LoadPublic_1(_Handle, Buffer, Len, &OutResultRaw));
	OutResult = (OutResultRaw != 0);
}

SB_INLINE void TElSRPKeyMaterial::LoadPublicValues(const std::vector<uint8_t> &N, const std::vector<uint8_t> &g, const std::vector<uint8_t> &s, const std::vector<uint8_t> &B)
{
	SBCheckError(TElSRPKeyMaterial_LoadPublicValues(_Handle, SB_STD_VECTOR_FRONT_ADR(N), (int32_t)N.size(), SB_STD_VECTOR_FRONT_ADR(g), (int32_t)g.size(), SB_STD_VECTOR_FRONT_ADR(s), (int32_t)s.size(), SB_STD_VECTOR_FRONT_ADR(B), (int32_t)B.size()));
}

SB_INLINE void TElSRPKeyMaterial::LoadVerifier(const std::vector<uint8_t> &N, const std::vector<uint8_t> &g, const std::vector<uint8_t> &s, const std::vector<uint8_t> &V)
{
	SBCheckError(TElSRPKeyMaterial_LoadVerifier(_Handle, SB_STD_VECTOR_FRONT_ADR(N), (int32_t)N.size(), SB_STD_VECTOR_FRONT_ADR(g), (int32_t)g.size(), SB_STD_VECTOR_FRONT_ADR(s), (int32_t)s.size(), SB_STD_VECTOR_FRONT_ADR(V), (int32_t)V.size()));
}

SB_INLINE void TElSRPKeyMaterial::LoadClientPublicValue(const std::vector<uint8_t> &A)
{
	SBCheckError(TElSRPKeyMaterial_LoadClientPublicValue(_Handle, SB_STD_VECTOR_FRONT_ADR(A), (int32_t)A.size()));
}

SB_INLINE void TElSRPKeyMaterial::PrepareServerKeyParam()
{
	SBCheckError(TElSRPKeyMaterial_PrepareServerKeyParam(_Handle));
}

SB_INLINE TElKeyMaterialHandle TElSRPKeyMaterial::Clone()
{
	TElKeyMaterialHandle OutResult;
	SBCheckError(TElSRPKeyMaterial_Clone(_Handle, &OutResult));
	return OutResult;
}

void TElSRPKeyMaterial::get_Salt(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSRPKeyMaterial_get_Salt(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-67183824, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSRPKeyMaterial::get_N(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSRPKeyMaterial_get_N(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2132251237, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSRPKeyMaterial::get_G(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSRPKeyMaterial_get_G(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(113978049, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSRPKeyMaterial::get_X(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSRPKeyMaterial_get_X(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1950144716, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSRPKeyMaterial::get_A(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSRPKeyMaterial_get_A(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-274165772, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSRPKeyMaterial::get_K(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSRPKeyMaterial_get_K(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(259876586, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSRPKeyMaterial::get_A_small(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSRPKeyMaterial_get_A_small(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-647267049, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSRPKeyMaterial::get_B(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSRPKeyMaterial_get_B(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1990319694, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSRPKeyMaterial::get_B_small(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSRPKeyMaterial_get_B_small(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-394041462, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSRPKeyMaterial::get_V(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSRPKeyMaterial_get_V(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1820002867, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSRPKeyMaterial::get_U(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSRPKeyMaterial_get_U(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-177054839, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSRPKeyMaterial::get_S(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSRPKeyMaterial_get_S(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(470941372, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElSRPKeyMaterial::TElSRPKeyMaterial(TElSRPKeyMaterialHandle handle, TElOwnHandle ownHandle) : TElPublicKeyMaterial(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElSRPKeyMaterial::TElSRPKeyMaterial(TElCustomCryptoProvider &Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSRPKeyMaterial_Create(Prov.getHandle(), &_Handle));
}

TElSRPKeyMaterial::TElSRPKeyMaterial(TElCustomCryptoProvider *Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSRPKeyMaterial_Create((Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElSRPKeyMaterial::TElSRPKeyMaterial(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSRPKeyMaterial_Create_1(Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElSRPKeyMaterial::TElSRPKeyMaterial(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSRPKeyMaterial_Create_1((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELSRPKEYMATERIAL */

#ifdef SB_USE_CLASS_TELSRPPUBLICKEYCRYPTO

void TElSRPPublicKeyCrypto::GetServerKey(std::vector<uint8_t> &PMS)
{
	int32_t szPMS = (int32_t)PMS.size();
	uint32_t _err = TElSRPPublicKeyCrypto_GetServerKey(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(PMS), &szPMS);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		PMS.resize(szPMS);
		SBCheckError(SBGetLastReturnBuffer(-219639999, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(PMS), &szPMS));
	}
	else
		SBCheckError(_err);

	PMS.resize(szPMS);
}

void TElSRPPublicKeyCrypto::GetClientKeyParam(const std::string &UserName, const std::string &UserPassword, std::vector<uint8_t> &EncPMS)
{
	int32_t szEncPMS = (int32_t)EncPMS.size();
	uint32_t _err = TElSRPPublicKeyCrypto_GetClientKeyParam(_Handle, UserName.data(), (int32_t)UserName.length(), UserPassword.data(), (int32_t)UserPassword.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(EncPMS), &szEncPMS);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		EncPMS.resize(szEncPMS);
		SBCheckError(SBGetLastReturnBuffer(-141466582, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(EncPMS), &szEncPMS));
	}
	else
		SBCheckError(_err);

	EncPMS.resize(szEncPMS);
}

void TElSRPPublicKeyCrypto::GetServerKeyParam(std::vector<uint8_t> &EncPMS)
{
	int32_t szEncPMS = (int32_t)EncPMS.size();
	uint32_t _err = TElSRPPublicKeyCrypto_GetServerKeyParam(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(EncPMS), &szEncPMS);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		EncPMS.resize(szEncPMS);
		SBCheckError(SBGetLastReturnBuffer(-77170774, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(EncPMS), &szEncPMS));
	}
	else
		SBCheckError(_err);

	EncPMS.resize(szEncPMS);
}

bool TElSRPPublicKeyCrypto::IsTrustedPrime(const std::vector<uint8_t> &N)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSRPPublicKeyCrypto_IsTrustedPrime(SB_STD_VECTOR_FRONT_ADR(N), (int32_t)N.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSRPPublicKeyCrypto::IsTrustedPrime_Inst(const std::vector<uint8_t> &N)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSRPPublicKeyCrypto_IsTrustedPrime_1(_Handle, SB_STD_VECTOR_FRONT_ADR(N), (int32_t)N.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TClassHandle TElSRPPublicKeyCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElSRPPublicKeyCrypto_ClassType(&OutResult));
	return OutResult;
}

TElSRPPublicKeyCrypto::TElSRPPublicKeyCrypto(TElSRPPublicKeyCryptoHandle handle, TElOwnHandle ownHandle) : TElPublicKeyCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElSRPPublicKeyCrypto::TElSRPPublicKeyCrypto(TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSRPPublicKeyCrypto_Create(CryptoProvider.getHandle(), &_Handle));
}

TElSRPPublicKeyCrypto::TElSRPPublicKeyCrypto(TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSRPPublicKeyCrypto_Create((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElSRPPublicKeyCrypto::TElSRPPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSRPPublicKeyCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), CryptoProvider.getHandle(), &_Handle));
}

TElSRPPublicKeyCrypto::TElSRPPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSRPPublicKeyCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElSRPPublicKeyCrypto::TElSRPPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSRPPublicKeyCrypto_Create_2(Alg, CryptoProvider.getHandle(), &_Handle));
}

TElSRPPublicKeyCrypto::TElSRPPublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSRPPublicKeyCrypto_Create_2(Alg, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElSRPPublicKeyCrypto::TElSRPPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSRPPublicKeyCrypto_Create_3(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElSRPPublicKeyCrypto::TElSRPPublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSRPPublicKeyCrypto_Create_3(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElSRPPublicKeyCrypto::TElSRPPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSRPPublicKeyCrypto_Create_4(Alg, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElSRPPublicKeyCrypto::TElSRPPublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSRPPublicKeyCrypto_Create_4(Alg, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElSRPPublicKeyCrypto::TElSRPPublicKeyCrypto(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSRPPublicKeyCrypto_Create_5(Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElSRPPublicKeyCrypto::TElSRPPublicKeyCrypto(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSRPPublicKeyCrypto_Create_5((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELSRPPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELGOST94KEYMATERIAL

SB_INLINE void TElGOST94KeyMaterial::Assign(TElKeyMaterial &Source)
{
	SBCheckError(TElGOST94KeyMaterial_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElGOST94KeyMaterial::Assign(TElKeyMaterial *Source)
{
	SBCheckError(TElGOST94KeyMaterial_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElKeyMaterialHandle TElGOST94KeyMaterial::Clone()
{
	TElKeyMaterialHandle OutResult;
	SBCheckError(TElGOST94KeyMaterial_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGOST94KeyMaterial::LoadSecret(void * Buffer, int32_t Size)
{
	SBCheckError(TElGOST94KeyMaterial_LoadSecret(_Handle, Buffer, Size));
}

SB_INLINE void TElGOST94KeyMaterial::LoadSecret(void * P, int32_t PSize, void * Q, int32_t QSize, void * A, int32_t ASize, void * Y, int32_t YSize, void * X, int32_t XSize)
{
	SBCheckError(TElGOST94KeyMaterial_LoadSecret_1(_Handle, P, PSize, Q, QSize, A, ASize, Y, YSize, X, XSize));
}

SB_INLINE void TElGOST94KeyMaterial::LoadSecret(const std::vector<uint8_t> &P, int32_t PIndex, int32_t PSize, const std::vector<uint8_t> &Q, int32_t QIndex, int32_t QSize, const std::vector<uint8_t> &A, int32_t AIndex, int32_t ASize, const std::vector<uint8_t> &Y, int32_t YIndex, int32_t YSize, const std::vector<uint8_t> &X, int32_t XIndex, int32_t XSize)
{
	SBCheckError(TElGOST94KeyMaterial_LoadSecret_2(_Handle, SB_STD_VECTOR_FRONT_ADR(P), (int32_t)P.size(), PIndex, PSize, SB_STD_VECTOR_FRONT_ADR(Q), (int32_t)Q.size(), QIndex, QSize, SB_STD_VECTOR_FRONT_ADR(A), (int32_t)A.size(), AIndex, ASize, SB_STD_VECTOR_FRONT_ADR(Y), (int32_t)Y.size(), YIndex, YSize, SB_STD_VECTOR_FRONT_ADR(X), (int32_t)X.size(), XIndex, XSize));
}

SB_INLINE void TElGOST94KeyMaterial::SaveSecret(void * Buffer, int32_t &Size)
{
	SBCheckError(TElGOST94KeyMaterial_SaveSecret(_Handle, Buffer, &Size));
}

SB_INLINE void TElGOST94KeyMaterial::LoadPublic(void * Buffer, int32_t Size)
{
	SBCheckError(TElGOST94KeyMaterial_LoadPublic(_Handle, Buffer, Size));
}

SB_INLINE void TElGOST94KeyMaterial::LoadPublic(void * P, int32_t PSize, void * Q, int32_t QSize, void * A, int32_t ASize, void * Y, int32_t YSize)
{
	SBCheckError(TElGOST94KeyMaterial_LoadPublic_1(_Handle, P, PSize, Q, QSize, A, ASize, Y, YSize));
}

SB_INLINE void TElGOST94KeyMaterial::LoadPublic(const std::vector<uint8_t> &P, int32_t PIndex, int32_t PSize, const std::vector<uint8_t> &Q, int32_t QIndex, int32_t QSize, const std::vector<uint8_t> &A, int32_t AIndex, int32_t ASize, const std::vector<uint8_t> &Y, int32_t YIndex, int32_t YSize)
{
	SBCheckError(TElGOST94KeyMaterial_LoadPublic_2(_Handle, SB_STD_VECTOR_FRONT_ADR(P), (int32_t)P.size(), PIndex, PSize, SB_STD_VECTOR_FRONT_ADR(Q), (int32_t)Q.size(), QIndex, QSize, SB_STD_VECTOR_FRONT_ADR(A), (int32_t)A.size(), AIndex, ASize, SB_STD_VECTOR_FRONT_ADR(Y), (int32_t)Y.size(), YIndex, YSize));
}

SB_INLINE void TElGOST94KeyMaterial::SavePublic(void * Buffer, int32_t &Size)
{
	SBCheckError(TElGOST94KeyMaterial_SavePublic(_Handle, Buffer, &Size));
}

SB_INLINE void TElGOST94KeyMaterial::LoadFromXML(const std::string &Str)
{
	SBCheckError(TElGOST94KeyMaterial_LoadFromXML(_Handle, Str.data(), (int32_t)Str.length()));
}

void TElGOST94KeyMaterial::SaveToXML(bool IncludePrivateKey, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGOST94KeyMaterial_SaveToXML(_Handle, (int8_t)IncludePrivateKey, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1846977963, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElGOST94KeyMaterial::Equals(TElKeyMaterial &Source, bool PublicOnly)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGOST94KeyMaterial_Equals(_Handle, Source.getHandle(), (int8_t)PublicOnly, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGOST94KeyMaterial::Equals(TElKeyMaterial *Source, bool PublicOnly)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGOST94KeyMaterial_Equals(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (int8_t)PublicOnly, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGOST94KeyMaterial::ClearSecret()
{
	SBCheckError(TElGOST94KeyMaterial_ClearSecret(_Handle));
}

SB_INLINE void TElGOST94KeyMaterial::ClearPublic()
{
	SBCheckError(TElGOST94KeyMaterial_ClearPublic(_Handle));
}

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElGOST94KeyMaterial::LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElGOST94KeyMaterial_LoadParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElGOST94KeyMaterial::LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElGOST94KeyMaterial_LoadParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElGOST94KeyMaterial::SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElGOST94KeyMaterial_SaveParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElGOST94KeyMaterial::SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElGOST94KeyMaterial_SaveParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

void TElGOST94KeyMaterial::get_P(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOST94KeyMaterial_get_P(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(7925950, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGOST94KeyMaterial::get_Q(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOST94KeyMaterial_get_Q(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2004860968, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGOST94KeyMaterial::get_A(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOST94KeyMaterial_get_A(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1791545420, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGOST94KeyMaterial::get_Y(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOST94KeyMaterial_get_Y(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2040809498, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGOST94KeyMaterial::set_Y(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElGOST94KeyMaterial_set_Y(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElGOST94KeyMaterial::get_X(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOST94KeyMaterial_get_X(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(245594252, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGOST94KeyMaterial::set_X(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElGOST94KeyMaterial_set_X(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElGOST94KeyMaterial::get_ParamSet(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOST94KeyMaterial_get_ParamSet(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1957190020, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGOST94KeyMaterial::set_ParamSet(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElGOST94KeyMaterial_set_ParamSet(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElGOST94KeyMaterial::get_DigestParamSet(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOST94KeyMaterial_get_DigestParamSet(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(345127428, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGOST94KeyMaterial::set_DigestParamSet(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElGOST94KeyMaterial_set_DigestParamSet(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElGOST94KeyMaterial::get_EncryptionParamSet(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOST94KeyMaterial_get_EncryptionParamSet(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-92150724, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGOST94KeyMaterial::set_EncryptionParamSet(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElGOST94KeyMaterial_set_EncryptionParamSet(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElGOST94KeyMaterial::TElGOST94KeyMaterial(TElGOST94KeyMaterialHandle handle, TElOwnHandle ownHandle) : TElPublicKeyMaterial(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElGOST94KeyMaterial::TElGOST94KeyMaterial(TElCustomCryptoProvider &Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST94KeyMaterial_Create(Prov.getHandle(), &_Handle));
}

TElGOST94KeyMaterial::TElGOST94KeyMaterial(TElCustomCryptoProvider *Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST94KeyMaterial_Create((Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElGOST94KeyMaterial::TElGOST94KeyMaterial(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST94KeyMaterial_Create_1(Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElGOST94KeyMaterial::TElGOST94KeyMaterial(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST94KeyMaterial_Create_1((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELGOST94KEYMATERIAL */

#ifdef SB_USE_CLASS_TELGOST94PUBLICKEYCRYPTO

SB_INLINE TClassHandle TElGOST94PublicKeyCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElGOST94PublicKeyCrypto_ClassType(&OutResult));
	return OutResult;
}

TElGOST94PublicKeyCrypto::TElGOST94PublicKeyCrypto(TElGOST94PublicKeyCryptoHandle handle, TElOwnHandle ownHandle) : TElPublicKeyCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElGOST94PublicKeyCrypto::TElGOST94PublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST94PublicKeyCrypto_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), CryptoProvider.getHandle(), &_Handle));
}

TElGOST94PublicKeyCrypto::TElGOST94PublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST94PublicKeyCrypto_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElGOST94PublicKeyCrypto::TElGOST94PublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST94PublicKeyCrypto_Create_1(Alg, CryptoProvider.getHandle(), &_Handle));
}

TElGOST94PublicKeyCrypto::TElGOST94PublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST94PublicKeyCrypto_Create_1(Alg, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElGOST94PublicKeyCrypto::TElGOST94PublicKeyCrypto(TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST94PublicKeyCrypto_Create_2(CryptoProvider.getHandle(), &_Handle));
}

TElGOST94PublicKeyCrypto::TElGOST94PublicKeyCrypto(TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST94PublicKeyCrypto_Create_2((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElGOST94PublicKeyCrypto::TElGOST94PublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST94PublicKeyCrypto_Create_3(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElGOST94PublicKeyCrypto::TElGOST94PublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST94PublicKeyCrypto_Create_3(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElGOST94PublicKeyCrypto::TElGOST94PublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST94PublicKeyCrypto_Create_4(Alg, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElGOST94PublicKeyCrypto::TElGOST94PublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST94PublicKeyCrypto_Create_4(Alg, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElGOST94PublicKeyCrypto::TElGOST94PublicKeyCrypto(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST94PublicKeyCrypto_Create_5(Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElGOST94PublicKeyCrypto::TElGOST94PublicKeyCrypto(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST94PublicKeyCrypto_Create_5((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELGOST94PUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELGOST2001KEYMATERIAL

SB_INLINE void TElGOST2001KeyMaterial::Assign(TElKeyMaterial &Source)
{
	SBCheckError(TElGOST2001KeyMaterial_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElGOST2001KeyMaterial::Assign(TElKeyMaterial *Source)
{
	SBCheckError(TElGOST2001KeyMaterial_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElGOST2001KeyMaterial::Generate()
{
	SBCheckError(TElGOST2001KeyMaterial_Generate(_Handle));
}

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElGOST2001KeyMaterial::LoadParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElGOST2001KeyMaterial_LoadParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElGOST2001KeyMaterial::LoadParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElGOST2001KeyMaterial_LoadParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElGOST2001KeyMaterial::SaveParameters(TElAlgorithmIdentifier &AlgorithmIdentifier)
{
	SBCheckError(TElGOST2001KeyMaterial_SaveParameters(_Handle, AlgorithmIdentifier.getHandle()));
}

SB_INLINE void TElGOST2001KeyMaterial::SaveParameters(TElAlgorithmIdentifier *AlgorithmIdentifier)
{
	SBCheckError(TElGOST2001KeyMaterial_SaveParameters(_Handle, (AlgorithmIdentifier != NULL) ? AlgorithmIdentifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

SB_INLINE void TElGOST2001KeyMaterial::LoadSecret(void * Buffer, int32_t Size)
{
	SBCheckError(TElGOST2001KeyMaterial_LoadSecret(_Handle, Buffer, Size));
}

SB_INLINE void TElGOST2001KeyMaterial::SaveSecret(void * Buffer, int32_t &Size)
{
	SBCheckError(TElGOST2001KeyMaterial_SaveSecret(_Handle, Buffer, &Size));
}

SB_INLINE void TElGOST2001KeyMaterial::LoadPublic(void * Buffer, int32_t Size)
{
	SBCheckError(TElGOST2001KeyMaterial_LoadPublic(_Handle, Buffer, Size));
}

SB_INLINE void TElGOST2001KeyMaterial::SavePublic(void * Buffer, int32_t &Size)
{
	SBCheckError(TElGOST2001KeyMaterial_SavePublic(_Handle, Buffer, &Size));
}

SB_INLINE TElKeyMaterialHandle TElGOST2001KeyMaterial::Clone()
{
	TElKeyMaterialHandle OutResult;
	SBCheckError(TElGOST2001KeyMaterial_Clone(_Handle, &OutResult));
	return OutResult;
}

bool TElGOST2001KeyMaterial::Equals(TElKeyMaterial &Source, bool PublicOnly)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGOST2001KeyMaterial_Equals(_Handle, Source.getHandle(), (int8_t)PublicOnly, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGOST2001KeyMaterial::Equals(TElKeyMaterial *Source, bool PublicOnly)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGOST2001KeyMaterial_Equals(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (int8_t)PublicOnly, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGOST2001KeyMaterial::ClearSecret()
{
	SBCheckError(TElGOST2001KeyMaterial_ClearSecret(_Handle));
}

SB_INLINE void TElGOST2001KeyMaterial::ClearPublic()
{
	SBCheckError(TElGOST2001KeyMaterial_ClearPublic(_Handle));
}

void TElGOST2001KeyMaterial::get_Q(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOST2001KeyMaterial_get_Q(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(262439143, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGOST2001KeyMaterial::set_Q(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElGOST2001KeyMaterial_set_Q(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElGOST2001KeyMaterial::get_D(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOST2001KeyMaterial_get_D(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1652122636, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGOST2001KeyMaterial::set_D(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElGOST2001KeyMaterial_set_D(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElGOST2001KeyMaterial::get_ParamSet(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOST2001KeyMaterial_get_ParamSet(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-285964983, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGOST2001KeyMaterial::set_ParamSet(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElGOST2001KeyMaterial_set_ParamSet(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElGOST2001KeyMaterial::get_DigestParamSet(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOST2001KeyMaterial_get_DigestParamSet(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-679065874, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGOST2001KeyMaterial::set_DigestParamSet(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElGOST2001KeyMaterial_set_DigestParamSet(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElGOST2001KeyMaterial::get_EncryptionParamSet(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOST2001KeyMaterial_get_EncryptionParamSet(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(845910027, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGOST2001KeyMaterial::set_EncryptionParamSet(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElGOST2001KeyMaterial_set_EncryptionParamSet(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElGOST2001KeyMaterial::TElGOST2001KeyMaterial(TElGOST2001KeyMaterialHandle handle, TElOwnHandle ownHandle) : TElPublicKeyMaterial(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElGOST2001KeyMaterial::TElGOST2001KeyMaterial(TElCustomCryptoProvider &Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST2001KeyMaterial_Create(Prov.getHandle(), &_Handle));
}

TElGOST2001KeyMaterial::TElGOST2001KeyMaterial(TElCustomCryptoProvider *Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST2001KeyMaterial_Create((Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElGOST2001KeyMaterial::TElGOST2001KeyMaterial(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST2001KeyMaterial_Create_1(Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElGOST2001KeyMaterial::TElGOST2001KeyMaterial(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElPublicKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST2001KeyMaterial_Create_1((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELGOST2001KEYMATERIAL */

#ifdef SB_USE_CLASS_TELGOST2001PUBLICKEYCRYPTO

SB_INLINE TClassHandle TElGOST2001PublicKeyCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElGOST2001PublicKeyCrypto_ClassType(&OutResult));
	return OutResult;
}

void TElGOST2001PublicKeyCrypto::get_UKM(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOST2001PublicKeyCrypto_get_UKM(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1732775350, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGOST2001PublicKeyCrypto::set_UKM(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElGOST2001PublicKeyCrypto_set_UKM(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElGOST2001PublicKeyCrypto::get_CEKMAC(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOST2001PublicKeyCrypto_get_CEKMAC(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1029391852, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGOST2001PublicKeyCrypto::set_CEKMAC(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElGOST2001PublicKeyCrypto_set_CEKMAC(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElGOST2001PublicKeyCrypto::get_EphemeralKey(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOST2001PublicKeyCrypto_get_EphemeralKey(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(906616094, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGOST2001PublicKeyCrypto::set_EphemeralKey(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElGOST2001PublicKeyCrypto_set_EphemeralKey(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElGOST2001PublicKeyCrypto::TElGOST2001PublicKeyCrypto(TElGOST2001PublicKeyCryptoHandle handle, TElOwnHandle ownHandle) : TElPublicKeyCrypto(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElGOST2001PublicKeyCrypto::TElGOST2001PublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST2001PublicKeyCrypto_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), CryptoProvider.getHandle(), &_Handle));
}

TElGOST2001PublicKeyCrypto::TElGOST2001PublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST2001PublicKeyCrypto_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElGOST2001PublicKeyCrypto::TElGOST2001PublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST2001PublicKeyCrypto_Create_1(Alg, CryptoProvider.getHandle(), &_Handle));
}

TElGOST2001PublicKeyCrypto::TElGOST2001PublicKeyCrypto(int32_t Alg, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST2001PublicKeyCrypto_Create_1(Alg, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElGOST2001PublicKeyCrypto::TElGOST2001PublicKeyCrypto(TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST2001PublicKeyCrypto_Create_2(CryptoProvider.getHandle(), &_Handle));
}

TElGOST2001PublicKeyCrypto::TElGOST2001PublicKeyCrypto(TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST2001PublicKeyCrypto_Create_2((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElGOST2001PublicKeyCrypto::TElGOST2001PublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST2001PublicKeyCrypto_Create_3(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElGOST2001PublicKeyCrypto::TElGOST2001PublicKeyCrypto(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST2001PublicKeyCrypto_Create_3(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElGOST2001PublicKeyCrypto::TElGOST2001PublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST2001PublicKeyCrypto_Create_4(Alg, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElGOST2001PublicKeyCrypto::TElGOST2001PublicKeyCrypto(int32_t Alg, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST2001PublicKeyCrypto_Create_4(Alg, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElGOST2001PublicKeyCrypto::TElGOST2001PublicKeyCrypto(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST2001PublicKeyCrypto_Create_5(Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElGOST2001PublicKeyCrypto::TElGOST2001PublicKeyCrypto(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElPublicKeyCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST2001PublicKeyCrypto_Create_5((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELGOST2001PUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELPUBLICKEYCRYPTOFACTORY

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
SB_INLINE TElPublicKeyMaterialHandle TElPublicKeyCryptoFactory::CreateKeyInstance(void * Buffer, int32_t Size, const std::string &Password)
{
	TElPublicKeyMaterialHandle OutResult;
	SBCheckError(TElPublicKeyCryptoFactory_CreateKeyInstance(_Handle, Buffer, Size, Password.data(), (int32_t)Password.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

#ifdef SB_USE_CLASSES_TELPUBLICKEYMATERIAL_AND_TSTREAM
SB_INLINE TElPublicKeyMaterialHandle TElPublicKeyCryptoFactory::CreateKeyInstance(TStream &Stream, const std::string &Password, int32_t Count)
{
	TElPublicKeyMaterialHandle OutResult;
	SBCheckError(TElPublicKeyCryptoFactory_CreateKeyInstance_1(_Handle, Stream.getHandle(), Password.data(), (int32_t)Password.length(), Count, &OutResult));
	return OutResult;
}

SB_INLINE TElPublicKeyMaterialHandle TElPublicKeyCryptoFactory::CreateKeyInstance(TStream *Stream, const std::string &Password, int32_t Count)
{
	TElPublicKeyMaterialHandle OutResult;
	SBCheckError(TElPublicKeyCryptoFactory_CreateKeyInstance_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPUBLICKEYMATERIAL_AND_TSTREAM */

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
SB_INLINE TElPublicKeyMaterialHandle TElPublicKeyCryptoFactory::CreateKeyInstance(int32_t Alg)
{
	TElPublicKeyMaterialHandle OutResult;
	SBCheckError(TElPublicKeyCryptoFactory_CreateKeyInstance_2(_Handle, Alg, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

SB_INLINE void TElPublicKeyCryptoFactory::RegisterClass(TElPublicKeyCryptoClassHandle Cls)
{
	SBCheckError(TElPublicKeyCryptoFactory_RegisterClass(_Handle, Cls));
}

#ifdef SB_USE_CLASS_TELPUBLICKEYCRYPTO
SB_INLINE TElPublicKeyCryptoHandle TElPublicKeyCryptoFactory::CreateInstance(const std::vector<uint8_t> &OID)
{
	TElPublicKeyCryptoHandle OutResult;
	SBCheckError(TElPublicKeyCryptoFactory_CreateInstance(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELPUBLICKEYCRYPTO
SB_INLINE TElPublicKeyCryptoHandle TElPublicKeyCryptoFactory::CreateInstance(int32_t Alg)
{
	TElPublicKeyCryptoHandle OutResult;
	SBCheckError(TElPublicKeyCryptoFactory_CreateInstance_1(_Handle, Alg, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPUBLICKEYCRYPTO */

bool TElPublicKeyCryptoFactory::IsAlgorithmSupported(const std::vector<uint8_t> &OID)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicKeyCryptoFactory_IsAlgorithmSupported(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPublicKeyCryptoFactory::IsAlgorithmSupported(int32_t Alg)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicKeyCryptoFactory_IsAlgorithmSupported_1(_Handle, Alg, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TElPublicKeyCryptoClassHandle TElPublicKeyCryptoFactory::get_RegisteredClasses(int32_t Index)
{
	TElPublicKeyCryptoClassHandle OutResult;
	SBCheckError(TElPublicKeyCryptoFactory_get_RegisteredClasses(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPublicKeyCryptoFactory::get_RegisteredClassCount()
{
	int32_t OutResult;
	SBCheckError(TElPublicKeyCryptoFactory_get_RegisteredClassCount(_Handle, &OutResult));
	return OutResult;
}

TElPublicKeyCryptoFactory::TElPublicKeyCryptoFactory(TElPublicKeyCryptoFactoryHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElPublicKeyCryptoFactory::TElPublicKeyCryptoFactory(TElCustomCryptoProvider &CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPublicKeyCryptoFactory_Create(CryptoProvider.getHandle(), &_Handle));
}

TElPublicKeyCryptoFactory::TElPublicKeyCryptoFactory(TElCustomCryptoProvider *CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPublicKeyCryptoFactory_Create((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElPublicKeyCryptoFactory::TElPublicKeyCryptoFactory(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPublicKeyCryptoFactory_Create_1(Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElPublicKeyCryptoFactory::TElPublicKeyCryptoFactory(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPublicKeyCryptoFactory_Create_1((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#endif /* SB_USE_CLASS_TELPUBLICKEYCRYPTOFACTORY */

#ifdef SB_USE_CLASS_TELREMOTESIGNINGPARAMS

SB_INLINE int32_t TElRemoteSigningParams::get_CertificateIndex()
{
	int32_t OutResult;
	SBCheckError(TElRemoteSigningParams_get_CertificateIndex(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRemoteSigningParams::set_CertificateIndex(int32_t Value)
{
	SBCheckError(TElRemoteSigningParams_set_CertificateIndex(_Handle, Value));
}

bool TElRemoteSigningParams::get_ExternalHashCalculation()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRemoteSigningParams_get_ExternalHashCalculation(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElRemoteSigningParams::set_ExternalHashCalculation(bool Value)
{
	SBCheckError(TElRemoteSigningParams_set_ExternalHashCalculation(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElRemoteSigningParams::get_ECDSACurve()
{
	int32_t OutResult;
	SBCheckError(TElRemoteSigningParams_get_ECDSACurve(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRemoteSigningParams::set_ECDSACurve(int32_t Value)
{
	SBCheckError(TElRemoteSigningParams_set_ECDSACurve(_Handle, Value));
}

void TElRemoteSigningParams::get_ECDSACurveOID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElRemoteSigningParams_get_ECDSACurveOID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1476270419, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElRemoteSigningParams::set_ECDSACurveOID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElRemoteSigningParams_set_ECDSACurveOID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElRemoteSigningParams::get_ECDSAFieldBits()
{
	int32_t OutResult;
	SBCheckError(TElRemoteSigningParams_get_ECDSAFieldBits(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRemoteSigningParams::set_ECDSAFieldBits(int32_t Value)
{
	SBCheckError(TElRemoteSigningParams_set_ECDSAFieldBits(_Handle, Value));
}

SB_INLINE int32_t TElRemoteSigningParams::get_DSAQBits()
{
	int32_t OutResult;
	SBCheckError(TElRemoteSigningParams_get_DSAQBits(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRemoteSigningParams::set_DSAQBits(int32_t Value)
{
	SBCheckError(TElRemoteSigningParams_set_DSAQBits(_Handle, Value));
}

TElRemoteSigningParams::TElRemoteSigningParams(TElRemoteSigningParamsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElRemoteSigningParams::TElRemoteSigningParams() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRemoteSigningParams_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELREMOTESIGNINGPARAMS */

};	/* namespace SecureBlackbox */
