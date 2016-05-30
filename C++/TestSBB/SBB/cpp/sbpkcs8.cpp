#include "sbpkcs8.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPKCS8ENCRYPTEDPRIVATEKEYINFO

SB_INLINE int32_t TElPKCS8EncryptedPrivateKeyInfo::LoadFromBuffer(void * Buffer, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElPKCS8EncryptedPrivateKeyInfo_LoadFromBuffer(_Handle, Buffer, Size, &OutResult));
	return OutResult;
}

bool TElPKCS8EncryptedPrivateKeyInfo::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS8EncryptedPrivateKeyInfo_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElPKCS8EncryptedPrivateKeyInfo::LoadFromStream(TStream &Stream, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElPKCS8EncryptedPrivateKeyInfo_LoadFromStream(_Handle, Stream.getHandle(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS8EncryptedPrivateKeyInfo::LoadFromStream(TStream *Stream, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElPKCS8EncryptedPrivateKeyInfo_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
bool TElPKCS8EncryptedPrivateKeyInfo::SaveToStream(TStream &Stream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS8EncryptedPrivateKeyInfo_SaveToStream(_Handle, Stream.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS8EncryptedPrivateKeyInfo::SaveToStream(TStream *Stream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS8EncryptedPrivateKeyInfo_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
SB_INLINE int32_t TElPKCS8EncryptedPrivateKeyInfo::LoadFromTag(TElASN1ConstrainedTag &Tag)
{
	int32_t OutResult;
	SBCheckError(TElPKCS8EncryptedPrivateKeyInfo_LoadFromTag(_Handle, Tag.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS8EncryptedPrivateKeyInfo::LoadFromTag(TElASN1ConstrainedTag *Tag)
{
	int32_t OutResult;
	SBCheckError(TElPKCS8EncryptedPrivateKeyInfo_LoadFromTag(_Handle, (Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
bool TElPKCS8EncryptedPrivateKeyInfo::SaveToTag(TElASN1ConstrainedTag &Tag)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS8EncryptedPrivateKeyInfo_SaveToTag(_Handle, Tag.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS8EncryptedPrivateKeyInfo::SaveToTag(TElASN1ConstrainedTag *Tag)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS8EncryptedPrivateKeyInfo_SaveToTag(_Handle, (Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

void TElPKCS8EncryptedPrivateKeyInfo::get_EncryptionAlgorithm(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS8EncryptedPrivateKeyInfo_get_EncryptionAlgorithm(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2063076675, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS8EncryptedPrivateKeyInfo::set_EncryptionAlgorithm(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS8EncryptedPrivateKeyInfo_set_EncryptionAlgorithm(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS8EncryptedPrivateKeyInfo::get_EncryptionAlgorithmParams(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS8EncryptedPrivateKeyInfo_get_EncryptionAlgorithmParams(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1380500955, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS8EncryptedPrivateKeyInfo::set_EncryptionAlgorithmParams(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS8EncryptedPrivateKeyInfo_set_EncryptionAlgorithmParams(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS8EncryptedPrivateKeyInfo::get_EncryptedData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS8EncryptedPrivateKeyInfo_get_EncryptedData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1166194524, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS8EncryptedPrivateKeyInfo::set_EncryptedData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS8EncryptedPrivateKeyInfo_set_EncryptedData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElPKCS8EncryptedPrivateKeyInfo::TElPKCS8EncryptedPrivateKeyInfo(TElPKCS8EncryptedPrivateKeyInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPKCS8EncryptedPrivateKeyInfo::TElPKCS8EncryptedPrivateKeyInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS8EncryptedPrivateKeyInfo_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPKCS8ENCRYPTEDPRIVATEKEYINFO */

#ifdef SB_USE_CLASS_TELPKCS8PRIVATEKEYINFO

SB_INLINE int32_t TElPKCS8PrivateKeyInfo::LoadFromBuffer(void * Buffer, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElPKCS8PrivateKeyInfo_LoadFromBuffer(_Handle, Buffer, Size, &OutResult));
	return OutResult;
}

bool TElPKCS8PrivateKeyInfo::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS8PrivateKeyInfo_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElPKCS8PrivateKeyInfo::LoadFromStream(TStream &Stream, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElPKCS8PrivateKeyInfo_LoadFromStream(_Handle, Stream.getHandle(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS8PrivateKeyInfo::LoadFromStream(TStream *Stream, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElPKCS8PrivateKeyInfo_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
bool TElPKCS8PrivateKeyInfo::SaveToStream(TStream &Stream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS8PrivateKeyInfo_SaveToStream(_Handle, Stream.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS8PrivateKeyInfo::SaveToStream(TStream *Stream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS8PrivateKeyInfo_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElPKCS8PrivateKeyInfo::get_PrivateKeyAlgorithm(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS8PrivateKeyInfo_get_PrivateKeyAlgorithm(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-537502024, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS8PrivateKeyInfo::set_PrivateKeyAlgorithm(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS8PrivateKeyInfo_set_PrivateKeyAlgorithm(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS8PrivateKeyInfo::get_PrivateKeyAlgorithmParams(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS8PrivateKeyInfo_get_PrivateKeyAlgorithmParams(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1841459618, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS8PrivateKeyInfo::set_PrivateKeyAlgorithmParams(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS8PrivateKeyInfo_set_PrivateKeyAlgorithmParams(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS8PrivateKeyInfo::get_PrivateKey(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS8PrivateKeyInfo_get_PrivateKey(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(441459426, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS8PrivateKeyInfo::set_PrivateKey(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS8PrivateKeyInfo_set_PrivateKey(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElPKCS8PrivateKeyInfo::TElPKCS8PrivateKeyInfo(TElPKCS8PrivateKeyInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPKCS8PrivateKeyInfo::TElPKCS8PrivateKeyInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS8PrivateKeyInfo_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPKCS8PRIVATEKEYINFO */

#ifdef SB_USE_CLASS_TELPKCS8PRIVATEKEY

SB_INLINE int32_t TElPKCS8PrivateKey::LoadFromBuffer(void * Buffer, int32_t Size, const std::string &Passphrase)
{
	int32_t OutResult;
	SBCheckError(TElPKCS8PrivateKey_LoadFromBuffer(_Handle, Buffer, Size, Passphrase.data(), (int32_t)Passphrase.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS8PrivateKey::SaveToBuffer(void * Buffer, int32_t &Size, const std::string &Passphrase, bool UsePEMEnvelope)
{
	int32_t OutResult;
	SBCheckError(TElPKCS8PrivateKey_SaveToBuffer(_Handle, Buffer, &Size, Passphrase.data(), (int32_t)Passphrase.length(), (int8_t)UsePEMEnvelope, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElPKCS8PrivateKey::LoadFromStream(TStream &Stream, const std::string &Passphrase, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElPKCS8PrivateKey_LoadFromStream(_Handle, Stream.getHandle(), Passphrase.data(), (int32_t)Passphrase.length(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS8PrivateKey::LoadFromStream(TStream *Stream, const std::string &Passphrase, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElPKCS8PrivateKey_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Passphrase.data(), (int32_t)Passphrase.length(), Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElPKCS8PrivateKey::SaveToStream(TStream &Stream, const std::string &Passphrase, bool UsePEMEnvelope)
{
	int32_t OutResult;
	SBCheckError(TElPKCS8PrivateKey_SaveToStream(_Handle, Stream.getHandle(), Passphrase.data(), (int32_t)Passphrase.length(), (int8_t)UsePEMEnvelope, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS8PrivateKey::SaveToStream(TStream *Stream, const std::string &Passphrase, bool UsePEMEnvelope)
{
	int32_t OutResult;
	SBCheckError(TElPKCS8PrivateKey_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Passphrase.data(), (int32_t)Passphrase.length(), (int8_t)UsePEMEnvelope, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElPKCS8PrivateKey::get_SymmetricAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPKCS8PrivateKey_get_SymmetricAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS8PrivateKey::set_SymmetricAlgorithm(int32_t Value)
{
	SBCheckError(TElPKCS8PrivateKey_set_SymmetricAlgorithm(_Handle, Value));
}

bool TElPKCS8PrivateKey::get_UseNewFeatures()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS8PrivateKey_get_UseNewFeatures(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS8PrivateKey::set_UseNewFeatures(bool Value)
{
	SBCheckError(TElPKCS8PrivateKey_set_UseNewFeatures(_Handle, (int8_t)Value));
}

void TElPKCS8PrivateKey::get_KeyMaterial(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS8PrivateKey_get_KeyMaterial(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-335117098, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS8PrivateKey::set_KeyMaterial(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS8PrivateKey_set_KeyMaterial(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS8PrivateKey::get_KeyAlgorithm(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS8PrivateKey_get_KeyAlgorithm(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1472033809, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS8PrivateKey::set_KeyAlgorithm(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS8PrivateKey_set_KeyAlgorithm(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS8PrivateKey::get_KeyAlgorithmParams(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS8PrivateKey_get_KeyAlgorithmParams(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-17686820, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS8PrivateKey::set_KeyAlgorithmParams(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS8PrivateKey_set_KeyAlgorithmParams(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElPKCS8PrivateKey::TElPKCS8PrivateKey(TElPKCS8PrivateKeyHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPKCS8PrivateKey::TElPKCS8PrivateKey() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS8PrivateKey_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPKCS8PRIVATEKEY */

#ifdef SB_USE_GLOBAL_PROCS_PKCS8

SB_INLINE void RaisePKCS8Error(int32_t ErrorCode)
{
	SBCheckError(SBPKCS8_RaisePKCS8Error(ErrorCode));
}

#endif /* SB_USE_GLOBAL_PROCS_PKCS8 */

};	/* namespace SecureBlackbox */

