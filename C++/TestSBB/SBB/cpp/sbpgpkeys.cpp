#include "sbpgpkeys.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY

SB_INLINE void TElPGPCustomPublicKey::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPCustomPublicKey_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPCustomPublicKey::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPCustomPublicKey_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPCustomPublicKey::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPCustomPublicKey_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPCustomPublicKey::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPCustomPublicKey_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
SB_INLINE int32_t TElPGPCustomPublicKey::AddSignature(TElPGPSignature &Signature)
{
	int32_t OutResult;
	SBCheckError(TElPGPCustomPublicKey_AddSignature(_Handle, Signature.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPCustomPublicKey::AddSignature(TElPGPSignature *Signature)
{
	int32_t OutResult;
	SBCheckError(TElPGPCustomPublicKey_AddSignature(_Handle, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

bool TElPGPCustomPublicKey::RemoveSignature(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_RemoveSignature(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
bool TElPGPCustomPublicKey::RemoveSignature(TElPGPSignature &Signature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_RemoveSignature_1(_Handle, Signature.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPCustomPublicKey::RemoveSignature(TElPGPSignature *Signature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_RemoveSignature_1(_Handle, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

SB_INLINE void TElPGPCustomPublicKey::ClearSignatures()
{
	SBCheckError(TElPGPCustomPublicKey_ClearSignatures(_Handle));
}

#ifdef SB_USE_CLASSES_TELPGPCUSTOMUSER_AND_TELPGPSIGNATURE
bool TElPGPCustomPublicKey::Verify(TElPGPCustomPublicKey &PublicKey, TElPGPCustomUser &User, TElPGPSignature &Signature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_Verify(_Handle, PublicKey.getHandle(), User.getHandle(), Signature.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPCustomPublicKey::Verify(TElPGPCustomPublicKey *PublicKey, TElPGPCustomUser *User, TElPGPSignature *Signature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_Verify(_Handle, (PublicKey != NULL) ? PublicKey->getHandle() : SB_NULL_HANDLE, (User != NULL) ? User->getHandle() : SB_NULL_HANDLE, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELPGPCUSTOMUSER_AND_TELPGPSIGNATURE */

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
bool TElPGPCustomPublicKey::Verify(TElPGPCustomPublicKey &Key, TElPGPSignature &Signature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_Verify_1(_Handle, Key.getHandle(), Signature.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPCustomPublicKey::Verify(TElPGPCustomPublicKey *Key, TElPGPSignature *Signature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_Verify_1(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

#ifdef SB_USE_CLASSES_TELHASHFUNCTION_AND_TELPGPSIGNATURE
bool TElPGPCustomPublicKey::Verify(TElHashFunction &HashFunction, TElPGPSignature &Signature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_Verify_2(_Handle, HashFunction.getHandle(), Signature.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPCustomPublicKey::Verify(TElHashFunction *HashFunction, TElPGPSignature *Signature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_Verify_2(_Handle, (HashFunction != NULL) ? HashFunction->getHandle() : SB_NULL_HANDLE, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELHASHFUNCTION_AND_TELPGPSIGNATURE */

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
bool TElPGPCustomPublicKey::Verify(TElPGPSignature &Signature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_Verify_3(_Handle, Signature.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPCustomPublicKey::Verify(TElPGPSignature *Signature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_Verify_3(_Handle, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
bool TElPGPCustomPublicKey::Verify(TElPGPSignature &SubjectSignature, TElPGPSignature &Signature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_Verify_4(_Handle, SubjectSignature.getHandle(), Signature.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPCustomPublicKey::Verify(TElPGPSignature *SubjectSignature, TElPGPSignature *Signature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_Verify_4(_Handle, (SubjectSignature != NULL) ? SubjectSignature->getHandle() : SB_NULL_HANDLE, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
bool TElPGPCustomPublicKey::DirectVerify(TElPGPCustomPublicKey &Key, TElPGPSignature &Signature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_DirectVerify(_Handle, Key.getHandle(), Signature.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPCustomPublicKey::DirectVerify(TElPGPCustomPublicKey *Key, TElPGPSignature *Signature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_DirectVerify(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
bool TElPGPCustomPublicKey::RevocationVerify(TElPGPCustomPublicKey &Key, TElPGPSignature &Signature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_RevocationVerify(_Handle, Key.getHandle(), Signature.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPCustomPublicKey::RevocationVerify(TElPGPCustomPublicKey *Key, TElPGPSignature *Signature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_RevocationVerify(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

#ifdef SB_USE_CLASSES_TELPGPCUSTOMUSER_AND_TELPGPSIGNATURE
bool TElPGPCustomPublicKey::RevocationVerify(TElPGPCustomPublicKey &Key, TElPGPCustomUser &User, TElPGPSignature &Signature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_RevocationVerify_1(_Handle, Key.getHandle(), User.getHandle(), Signature.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPCustomPublicKey::RevocationVerify(TElPGPCustomPublicKey *Key, TElPGPCustomUser *User, TElPGPSignature *Signature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_RevocationVerify_1(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (User != NULL) ? User->getHandle() : SB_NULL_HANDLE, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELPGPCUSTOMUSER_AND_TELPGPSIGNATURE */

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
bool TElPGPCustomPublicKey::DirectRevocationVerify(TElPGPCustomPublicKey &Key, TElPGPSignature &Signature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_DirectRevocationVerify(_Handle, Key.getHandle(), Signature.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPCustomPublicKey::DirectRevocationVerify(TElPGPCustomPublicKey *Key, TElPGPSignature *Signature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_DirectRevocationVerify(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
SB_INLINE TElPublicKeyMaterialHandle TElPGPCustomPublicKey::ExportKeyMaterial()
{
	TElPublicKeyMaterialHandle OutResult;
	SBCheckError(TElPGPCustomPublicKey_ExportKeyMaterial(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
SB_INLINE void TElPGPCustomPublicKey::ImportKeyMaterial(TElPublicKeyMaterial &KeyMaterial)
{
	SBCheckError(TElPGPCustomPublicKey_ImportKeyMaterial(_Handle, KeyMaterial.getHandle()));
}

SB_INLINE void TElPGPCustomPublicKey::ImportKeyMaterial(TElPublicKeyMaterial *KeyMaterial)
{
	SBCheckError(TElPGPCustomPublicKey_ImportKeyMaterial(_Handle, (KeyMaterial != NULL) ? KeyMaterial->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
SB_INLINE void TElPGPCustomPublicKey::ImportKeyMaterial(TElPublicKeyMaterial &KeyMaterial, int64_t Timestamp, int32_t KeyVersion, int32_t Expires)
{
	SBCheckError(TElPGPCustomPublicKey_ImportKeyMaterial_1(_Handle, KeyMaterial.getHandle(), Timestamp, KeyVersion, Expires));
}

SB_INLINE void TElPGPCustomPublicKey::ImportKeyMaterial(TElPublicKeyMaterial *KeyMaterial, int64_t Timestamp, int32_t KeyVersion, int32_t Expires)
{
	SBCheckError(TElPGPCustomPublicKey_ImportKeyMaterial_1(_Handle, (KeyMaterial != NULL) ? KeyMaterial->getHandle() : SB_NULL_HANDLE, Timestamp, KeyVersion, Expires));
}
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

SB_INLINE void TElPGPCustomPublicKey::Encrypt(const std::vector<uint8_t> &Data, TSBPGPEncryptedSymmetricKey &OutResult)
{
	SBCheckError(TElPGPCustomPublicKey_Encrypt(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), &OutResult));
}

bool TElPGPCustomPublicKey::IsSigningKey(bool WithSubkeys)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_IsSigningKey(_Handle, (int8_t)WithSubkeys, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPCustomPublicKey::IsEncryptingKey(bool WithSubkeys)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_IsEncryptingKey(_Handle, (int8_t)WithSubkeys, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPCustomPublicKey::PrepareForEncryption(bool MultiUse)
{
	SBCheckError(TElPGPCustomPublicKey_PrepareForEncryption(_Handle, (int8_t)MultiUse));
}

SB_INLINE void TElPGPCustomPublicKey::CancelPreparation()
{
	SBCheckError(TElPGPCustomPublicKey_CancelPreparation(_Handle));
}

bool TElPGPCustomPublicKey::AsyncOperationFinished()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_AsyncOperationFinished(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPCustomPublicKey::AcquireLock()
{
	SBCheckError(TElPGPCustomPublicKey_AcquireLock(_Handle));
}

SB_INLINE void TElPGPCustomPublicKey::ReleaseLock()
{
	SBCheckError(TElPGPCustomPublicKey_ReleaseLock(_Handle));
}

SB_INLINE void TElPGPCustomPublicKey::KeyID(TSBKeyID &OutResult)
{
	SBCheckError(TElPGPCustomPublicKey_KeyID(_Handle, &OutResult));
}

void TElPGPCustomPublicKey::KeyFP(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPCustomPublicKey_KeyFP(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(97719037, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElPGPCustomPublicKey::get_Timestamp()
{
	int64_t OutResult;
	SBCheckError(TElPGPCustomPublicKey_get_Timestamp(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPCustomPublicKey::set_Timestamp(int64_t Value)
{
	SBCheckError(TElPGPCustomPublicKey_set_Timestamp(_Handle, Value));
}

SB_INLINE int32_t TElPGPCustomPublicKey::get_Expires()
{
	int32_t OutResult;
	SBCheckError(TElPGPCustomPublicKey_get_Expires(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPCustomPublicKey::set_Expires(int32_t Value)
{
	SBCheckError(TElPGPCustomPublicKey_set_Expires(_Handle, Value));
}

SB_INLINE int32_t TElPGPCustomPublicKey::get_PublicKeyAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPCustomPublicKey_get_PublicKeyAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPCustomPublicKey::get_BitsInKey()
{
	int32_t OutResult;
	SBCheckError(TElPGPCustomPublicKey_get_BitsInKey(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPCustomPublicKey::get_KeyHashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPCustomPublicKey_get_KeyHashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPCustomPublicKey::set_KeyHashAlgorithm(int32_t Value)
{
	SBCheckError(TElPGPCustomPublicKey_set_KeyHashAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElPGPCustomPublicKey::get_QBits()
{
	int32_t OutResult;
	SBCheckError(TElPGPCustomPublicKey_get_QBits(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPCustomPublicKey::get_Curve()
{
	int32_t OutResult;
	SBCheckError(TElPGPCustomPublicKey_get_Curve(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPCustomPublicKey::get_Version()
{
	int32_t OutResult;
	SBCheckError(TElPGPCustomPublicKey_get_Version(_Handle, &OutResult));
	return OutResult;
}

bool TElPGPCustomPublicKey::get_UseOldPackets()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_get_UseOldPackets(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPCustomPublicKey::set_UseOldPackets(bool Value)
{
	SBCheckError(TElPGPCustomPublicKey_set_UseOldPackets(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
TElPGPSignature* TElPGPCustomPublicKey::get_Signatures(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPCustomPublicKey_get_Signatures(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signatures)
		this->_Inst_Signatures = new TElPGPSignature(hOutResult, ohFalse);
	else
		this->_Inst_Signatures->updateHandle(hOutResult);
	return this->_Inst_Signatures;
}
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

SB_INLINE int32_t TElPGPCustomPublicKey::get_SignatureCount()
{
	int32_t OutResult;
	SBCheckError(TElPGPCustomPublicKey_get_SignatureCount(_Handle, &OutResult));
	return OutResult;
}

bool TElPGPCustomPublicKey::get_Revoked()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_get_Revoked(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPCustomPublicKey::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomPublicKey_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPCustomPublicKey::set_Enabled(bool Value)
{
	SBCheckError(TElPGPCustomPublicKey_set_Enabled(_Handle, (int8_t)Value));
}

void TElPGPCustomPublicKey::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPSIGNATURE
	this->_Inst_Signatures = NULL;
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */
}

TElPGPCustomPublicKey::TElPGPCustomPublicKey(TElPGPCustomPublicKeyHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElPGPCustomPublicKey::TElPGPCustomPublicKey() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPCustomPublicKey_Create(&_Handle));
}

TElPGPCustomPublicKey::~TElPGPCustomPublicKey()
{
#ifdef SB_USE_CLASS_TELPGPSIGNATURE
	delete this->_Inst_Signatures;
	this->_Inst_Signatures = NULL;
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */
}
#endif /* SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPPUBLICSUBKEY

SB_INLINE void TElPGPPublicSubkey::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPPublicSubkey_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPPublicSubkey::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPPublicSubkey_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPPublicSubkey::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPPublicSubkey_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPPublicSubkey::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPPublicSubkey_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELPGPSECRETSUBKEY
TElPGPSecretSubkey* TElPGPPublicSubkey::get_SecretKey()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPPublicSubkey_get_SecretKey(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SecretKey)
		this->_Inst_SecretKey = new TElPGPSecretSubkey(hOutResult, ohFalse);
	else
		this->_Inst_SecretKey->updateHandle(hOutResult);
	return this->_Inst_SecretKey;
}
#endif /* SB_USE_CLASS_TELPGPSECRETSUBKEY */

#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
TElPGPPublicKey* TElPGPPublicSubkey::get_Supkey()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPPublicSubkey_get_Supkey(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Supkey)
		this->_Inst_Supkey = new TElPGPPublicKey(hOutResult, ohFalse);
	else
		this->_Inst_Supkey->updateHandle(hOutResult);
	return this->_Inst_Supkey;
}
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPTRUST
TElPGPTrust* TElPGPPublicSubkey::get_Trust()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPPublicSubkey_get_Trust(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Trust)
		this->_Inst_Trust = new TElPGPTrust(hOutResult, ohFalse);
	else
		this->_Inst_Trust->updateHandle(hOutResult);
	return this->_Inst_Trust;
}
#endif /* SB_USE_CLASS_TELPGPTRUST */

void TElPGPPublicSubkey::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPSECRETSUBKEY
	this->_Inst_SecretKey = NULL;
#endif /* SB_USE_CLASS_TELPGPSECRETSUBKEY */
#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
	this->_Inst_Supkey = NULL;
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */
#ifdef SB_USE_CLASS_TELPGPTRUST
	this->_Inst_Trust = NULL;
#endif /* SB_USE_CLASS_TELPGPTRUST */
}

TElPGPPublicSubkey::TElPGPPublicSubkey(TElPGPPublicSubkeyHandle handle, TElOwnHandle ownHandle) : TElPGPCustomPublicKey(handle, ownHandle)
{
	initInstances();
}

TElPGPPublicSubkey::TElPGPPublicSubkey() : TElPGPCustomPublicKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPPublicSubkey_Create(&_Handle));
}

TElPGPPublicSubkey::~TElPGPPublicSubkey()
{
#ifdef SB_USE_CLASS_TELPGPSECRETSUBKEY
	delete this->_Inst_SecretKey;
	this->_Inst_SecretKey = NULL;
#endif /* SB_USE_CLASS_TELPGPSECRETSUBKEY */
#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
	delete this->_Inst_Supkey;
	this->_Inst_Supkey = NULL;
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */
#ifdef SB_USE_CLASS_TELPGPTRUST
	delete this->_Inst_Trust;
	this->_Inst_Trust = NULL;
#endif /* SB_USE_CLASS_TELPGPTRUST */
}
#endif /* SB_USE_CLASS_TELPGPPUBLICSUBKEY */

#ifdef SB_USE_CLASS_TELPGPPUBLICKEY

bool TElPGPPublicKey::RemoveSubkey(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPPublicKey_RemoveSubkey(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELPGPPUBLICSUBKEY
bool TElPGPPublicKey::RemoveSubkey(TElPGPPublicSubkey &Subkey)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPPublicKey_RemoveSubkey_1(_Handle, Subkey.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPPublicKey::RemoveSubkey(TElPGPPublicSubkey *Subkey)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPPublicKey_RemoveSubkey_1(_Handle, (Subkey != NULL) ? Subkey->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPGPPUBLICSUBKEY */

SB_INLINE void TElPGPPublicKey::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPPublicKey_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPPublicKey::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPPublicKey_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPPublicKey::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPPublicKey_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPPublicKey::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPPublicKey_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElPGPPublicKey::AssignFromX509(TElX509Certificate &Certificate)
{
	SBCheckError(TElPGPPublicKey_AssignFromX509(_Handle, Certificate.getHandle()));
}

SB_INLINE void TElPGPPublicKey::AssignFromX509(TElX509Certificate *Certificate)
{
	SBCheckError(TElPGPPublicKey_AssignFromX509(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPPublicKey::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElPGPPublicKey_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElPGPPublicKey::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElPGPPublicKey_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElPGPPublicKey::LoadFromFile(const std::string &Filename)
{
	SBCheckError(TElPGPPublicKey_LoadFromFile(_Handle, Filename.data(), (int32_t)Filename.length()));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPPublicKey::SaveToStream(TStream &Stream, bool Armor)
{
	SBCheckError(TElPGPPublicKey_SaveToStream(_Handle, Stream.getHandle(), (int8_t)Armor));
}

SB_INLINE void TElPGPPublicKey::SaveToStream(TStream *Stream, bool Armor)
{
	SBCheckError(TElPGPPublicKey_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (int8_t)Armor));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElPGPPublicKey::SaveToFile(const std::string &Filename, bool Armor)
{
	SBCheckError(TElPGPPublicKey_SaveToFile(_Handle, Filename.data(), (int32_t)Filename.length(), (int8_t)Armor));
}

#ifdef SB_USE_CLASS_TELPGPPUBLICSUBKEY
SB_INLINE int32_t TElPGPPublicKey::AddSubkey(TElPGPPublicSubkey &Subkey)
{
	int32_t OutResult;
	SBCheckError(TElPGPPublicKey_AddSubkey(_Handle, Subkey.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPPublicKey::AddSubkey(TElPGPPublicSubkey *Subkey)
{
	int32_t OutResult;
	SBCheckError(TElPGPPublicKey_AddSubkey(_Handle, (Subkey != NULL) ? Subkey->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPPUBLICSUBKEY */

SB_INLINE void TElPGPPublicKey::ClearSubkeys()
{
	SBCheckError(TElPGPPublicKey_ClearSubkeys(_Handle));
}

#ifdef SB_USE_CLASS_TELPGPUSERID
SB_INLINE int32_t TElPGPPublicKey::AddUserID(TElPGPUserID &User)
{
	int32_t OutResult;
	SBCheckError(TElPGPPublicKey_AddUserID(_Handle, User.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPPublicKey::AddUserID(TElPGPUserID *User)
{
	int32_t OutResult;
	SBCheckError(TElPGPPublicKey_AddUserID(_Handle, (User != NULL) ? User->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPUSERID */

#ifdef SB_USE_CLASS_TELPGPUSERATTR
SB_INLINE int32_t TElPGPPublicKey::AddUserAttr(TElPGPUserAttr &User)
{
	int32_t OutResult;
	SBCheckError(TElPGPPublicKey_AddUserAttr(_Handle, User.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPPublicKey::AddUserAttr(TElPGPUserAttr *User)
{
	int32_t OutResult;
	SBCheckError(TElPGPPublicKey_AddUserAttr(_Handle, (User != NULL) ? User->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPUSERATTR */

bool TElPGPPublicKey::RemoveUserID(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPPublicKey_RemoveUserID(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELPGPUSERID
bool TElPGPPublicKey::RemoveUserID(TElPGPUserID &User)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPPublicKey_RemoveUserID_1(_Handle, User.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPPublicKey::RemoveUserID(TElPGPUserID *User)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPPublicKey_RemoveUserID_1(_Handle, (User != NULL) ? User->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPGPUSERID */

bool TElPGPPublicKey::RemoveUserAttr(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPPublicKey_RemoveUserAttr(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELPGPUSERATTR
bool TElPGPPublicKey::RemoveUserAttr(TElPGPUserAttr &UserAttr)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPPublicKey_RemoveUserAttr_1(_Handle, UserAttr.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPPublicKey::RemoveUserAttr(TElPGPUserAttr *UserAttr)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPPublicKey_RemoveUserAttr_1(_Handle, (UserAttr != NULL) ? UserAttr->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPGPUSERATTR */

SB_INLINE void TElPGPPublicKey::ClearUserIDs()
{
	SBCheckError(TElPGPPublicKey_ClearUserIDs(_Handle));
}

SB_INLINE void TElPGPPublicKey::ClearUserAttrs()
{
	SBCheckError(TElPGPPublicKey_ClearUserAttrs(_Handle));
}

SB_INLINE void TElPGPPublicKey::PrepareForEncryption(bool MultiUse)
{
	SBCheckError(TElPGPPublicKey_PrepareForEncryption(_Handle, (int8_t)MultiUse));
}

SB_INLINE void TElPGPPublicKey::CancelPreparation()
{
	SBCheckError(TElPGPPublicKey_CancelPreparation(_Handle));
}

bool TElPGPPublicKey::AsyncOperationFinished()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPPublicKey_AsyncOperationFinished(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElPGPPublicKey::get_ArmorBoundary(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPPublicKey_get_ArmorBoundary(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1005579416, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPPublicKey::set_ArmorBoundary(const std::string &Value)
{
	SBCheckError(TElPGPPublicKey_set_ArmorBoundary(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElPGPPublicKey::get_ArmorHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPPublicKey_get_ArmorHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ArmorHeaders)
		this->_Inst_ArmorHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_ArmorHeaders->updateHandle(hOutResult);
	return this->_Inst_ArmorHeaders;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TELPGPPUBLICSUBKEY
TElPGPPublicSubkey* TElPGPPublicKey::get_Subkeys(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPPublicKey_get_Subkeys(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Subkeys)
		this->_Inst_Subkeys = new TElPGPPublicSubkey(hOutResult, ohFalse);
	else
		this->_Inst_Subkeys->updateHandle(hOutResult);
	return this->_Inst_Subkeys;
}
#endif /* SB_USE_CLASS_TELPGPPUBLICSUBKEY */

#ifdef SB_USE_CLASS_TELPGPUSERID
TElPGPUserID* TElPGPPublicKey::get_UserIDs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPPublicKey_get_UserIDs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_UserIDs)
		this->_Inst_UserIDs = new TElPGPUserID(hOutResult, ohFalse);
	else
		this->_Inst_UserIDs->updateHandle(hOutResult);
	return this->_Inst_UserIDs;
}
#endif /* SB_USE_CLASS_TELPGPUSERID */

#ifdef SB_USE_CLASS_TELPGPUSERATTR
TElPGPUserAttr* TElPGPPublicKey::get_UserAttrs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPPublicKey_get_UserAttrs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_UserAttrs)
		this->_Inst_UserAttrs = new TElPGPUserAttr(hOutResult, ohFalse);
	else
		this->_Inst_UserAttrs->updateHandle(hOutResult);
	return this->_Inst_UserAttrs;
}
#endif /* SB_USE_CLASS_TELPGPUSERATTR */

SB_INLINE int32_t TElPGPPublicKey::get_PreferredSymAlgs(int32_t Index)
{
	int32_t OutResult;
	SBCheckError(TElPGPPublicKey_get_PreferredSymAlgs(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPPublicKey::get_PreferredHashAlgs(int32_t Index)
{
	int32_t OutResult;
	SBCheckError(TElPGPPublicKey_get_PreferredHashAlgs(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPPublicKey::get_PreferredComprAlgs(int32_t Index)
{
	int32_t OutResult;
	SBCheckError(TElPGPPublicKey_get_PreferredComprAlgs(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPPublicKey::get_SubkeyCount()
{
	int32_t OutResult;
	SBCheckError(TElPGPPublicKey_get_SubkeyCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPPublicKey::get_UserIDCount()
{
	int32_t OutResult;
	SBCheckError(TElPGPPublicKey_get_UserIDCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPPublicKey::get_UserAttrCount()
{
	int32_t OutResult;
	SBCheckError(TElPGPPublicKey_get_UserAttrCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPGPTRUST
TElPGPTrust* TElPGPPublicKey::get_Trust()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPPublicKey_get_Trust(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Trust)
		this->_Inst_Trust = new TElPGPTrust(hOutResult, ohFalse);
	else
		this->_Inst_Trust->updateHandle(hOutResult);
	return this->_Inst_Trust;
}
#endif /* SB_USE_CLASS_TELPGPTRUST */

TSBPGPKeyTrust TElPGPPublicKey::get_KeyTrust()
{
	TSBPGPKeyTrustRaw OutResultRaw = 0;
	SBCheckError(TElPGPPublicKey_get_KeyTrust(_Handle, &OutResultRaw));
	return (TSBPGPKeyTrust)OutResultRaw;
}

SB_INLINE void TElPGPPublicKey::set_KeyTrust(TSBPGPKeyTrust Value)
{
	SBCheckError(TElPGPPublicKey_set_KeyTrust(_Handle, (TSBPGPKeyTrustRaw)Value));
}

#ifdef SB_USE_CLASS_TELPGPSECRETKEY
TElPGPSecretKey* TElPGPPublicKey::get_SecretKey()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPPublicKey_get_SecretKey(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SecretKey)
		this->_Inst_SecretKey = new TElPGPSecretKey(hOutResult, ohFalse);
	else
		this->_Inst_SecretKey->updateHandle(hOutResult);
	return this->_Inst_SecretKey;
}
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */

bool TElPGPPublicKey::get_WriteOldPrefix()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPPublicKey_get_WriteOldPrefix(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPPublicKey::set_WriteOldPrefix(bool Value)
{
	SBCheckError(TElPGPPublicKey_set_WriteOldPrefix(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElPGPPublicKey::get_PreferredSymAlgCount()
{
	int32_t OutResult;
	SBCheckError(TElPGPPublicKey_get_PreferredSymAlgCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPPublicKey::get_PreferredHashAlgCount()
{
	int32_t OutResult;
	SBCheckError(TElPGPPublicKey_get_PreferredHashAlgCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPPublicKey::get_PreferredComprAlgCount()
{
	int32_t OutResult;
	SBCheckError(TElPGPPublicKey_get_PreferredComprAlgCount(_Handle, &OutResult));
	return OutResult;
}

void TElPGPPublicKey::initInstances()
{
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_ArmorHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELPGPPUBLICSUBKEY
	this->_Inst_Subkeys = NULL;
#endif /* SB_USE_CLASS_TELPGPPUBLICSUBKEY */
#ifdef SB_USE_CLASS_TELPGPUSERID
	this->_Inst_UserIDs = NULL;
#endif /* SB_USE_CLASS_TELPGPUSERID */
#ifdef SB_USE_CLASS_TELPGPUSERATTR
	this->_Inst_UserAttrs = NULL;
#endif /* SB_USE_CLASS_TELPGPUSERATTR */
#ifdef SB_USE_CLASS_TELPGPTRUST
	this->_Inst_Trust = NULL;
#endif /* SB_USE_CLASS_TELPGPTRUST */
#ifdef SB_USE_CLASS_TELPGPSECRETKEY
	this->_Inst_SecretKey = NULL;
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */
}

TElPGPPublicKey::TElPGPPublicKey(TElPGPPublicKeyHandle handle, TElOwnHandle ownHandle) : TElPGPCustomPublicKey(handle, ownHandle)
{
	initInstances();
}

TElPGPPublicKey::TElPGPPublicKey() : TElPGPCustomPublicKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPPublicKey_Create(&_Handle));
}

TElPGPPublicKey::~TElPGPPublicKey()
{
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_ArmorHeaders;
	this->_Inst_ArmorHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELPGPPUBLICSUBKEY
	delete this->_Inst_Subkeys;
	this->_Inst_Subkeys = NULL;
#endif /* SB_USE_CLASS_TELPGPPUBLICSUBKEY */
#ifdef SB_USE_CLASS_TELPGPUSERID
	delete this->_Inst_UserIDs;
	this->_Inst_UserIDs = NULL;
#endif /* SB_USE_CLASS_TELPGPUSERID */
#ifdef SB_USE_CLASS_TELPGPUSERATTR
	delete this->_Inst_UserAttrs;
	this->_Inst_UserAttrs = NULL;
#endif /* SB_USE_CLASS_TELPGPUSERATTR */
#ifdef SB_USE_CLASS_TELPGPTRUST
	delete this->_Inst_Trust;
	this->_Inst_Trust = NULL;
#endif /* SB_USE_CLASS_TELPGPTRUST */
#ifdef SB_USE_CLASS_TELPGPSECRETKEY
	delete this->_Inst_SecretKey;
	this->_Inst_SecretKey = NULL;
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */
}
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPCUSTOMSECRETKEY

SB_INLINE void TElPGPCustomSecretKey::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPCustomSecretKey_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPCustomSecretKey::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPCustomSecretKey_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPCustomSecretKey::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPCustomSecretKey_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPCustomSecretKey::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPCustomSecretKey_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPCustomSecretKey::Generate(const std::string &Password, int32_t Bits, int32_t Algorithm, bool UseOldFormat, int32_t Expires)
{
	SBCheckError(TElPGPCustomSecretKey_Generate(_Handle, Password.data(), (int32_t)Password.length(), Bits, Algorithm, (int8_t)UseOldFormat, Expires));
}

SB_INLINE void TElPGPCustomSecretKey::BeginGenerate(int32_t Bits, int32_t Algorithm)
{
	SBCheckError(TElPGPCustomSecretKey_BeginGenerate(_Handle, Bits, Algorithm));
}

SB_INLINE void TElPGPCustomSecretKey::EndGenerate(const std::string &Password, bool UseOldFormat, int32_t Expires)
{
	SBCheckError(TElPGPCustomSecretKey_EndGenerate(_Handle, Password.data(), (int32_t)Password.length(), (int8_t)UseOldFormat, Expires));
}

SB_INLINE void TElPGPCustomSecretKey::CancelGeneration()
{
	SBCheckError(TElPGPCustomSecretKey_CancelGeneration(_Handle));
}

SB_INLINE void TElPGPCustomSecretKey::ChangePassphrase(const std::string &NewPassphrase, TSBPGPProtectionType ProtectionType)
{
	SBCheckError(TElPGPCustomSecretKey_ChangePassphrase(_Handle, NewPassphrase.data(), (int32_t)NewPassphrase.length(), (TSBPGPProtectionTypeRaw)ProtectionType));
}

SB_INLINE void TElPGPCustomSecretKey::ChangeProtection(const std::string &NewPassphrase, TSBPGPProtectionType PrType, int32_t EncAlgorithm, int32_t HshAlgorithm)
{
	SBCheckError(TElPGPCustomSecretKey_ChangeProtection(_Handle, NewPassphrase.data(), (int32_t)NewPassphrase.length(), (TSBPGPProtectionTypeRaw)PrType, EncAlgorithm, HshAlgorithm));
}

#ifdef SB_USE_CLASSES_TELPGPCUSTOMUSER_AND_TELPGPPUBLICKEY_AND_TELPGPSIGNATURE
SB_INLINE void TElPGPCustomSecretKey::Sign(TElPGPPublicKey &PublicKey, TElPGPCustomUser &User, TElPGPSignature &Signature, TSBPGPUserCertificationType CertType)
{
	SBCheckError(TElPGPCustomSecretKey_Sign(_Handle, PublicKey.getHandle(), User.getHandle(), Signature.getHandle(), (TSBPGPUserCertificationTypeRaw)CertType));
}

SB_INLINE void TElPGPCustomSecretKey::Sign(TElPGPPublicKey *PublicKey, TElPGPCustomUser *User, TElPGPSignature *Signature, TSBPGPUserCertificationType CertType)
{
	SBCheckError(TElPGPCustomSecretKey_Sign(_Handle, (PublicKey != NULL) ? PublicKey->getHandle() : SB_NULL_HANDLE, (User != NULL) ? User->getHandle() : SB_NULL_HANDLE, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE, (TSBPGPUserCertificationTypeRaw)CertType));
}
#endif /* SB_USE_CLASSES_TELPGPCUSTOMUSER_AND_TELPGPPUBLICKEY_AND_TELPGPSIGNATURE */

#ifdef SB_USE_CLASSES_TELPGPCUSTOMPUBLICKEY_AND_TELPGPSIGNATURE
SB_INLINE void TElPGPCustomSecretKey::Sign(TElPGPCustomPublicKey &Key, TElPGPSignature &Signature, TElPGPSignature &EmbeddedSignature)
{
	SBCheckError(TElPGPCustomSecretKey_Sign_1(_Handle, Key.getHandle(), Signature.getHandle(), EmbeddedSignature.getHandle()));
}

SB_INLINE void TElPGPCustomSecretKey::Sign(TElPGPCustomPublicKey *Key, TElPGPSignature *Signature, TElPGPSignature *EmbeddedSignature)
{
	SBCheckError(TElPGPCustomSecretKey_Sign_1(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE, (EmbeddedSignature != NULL) ? EmbeddedSignature->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELPGPCUSTOMPUBLICKEY_AND_TELPGPSIGNATURE */

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
SB_INLINE void TElPGPCustomSecretKey::Sign(int64_t TimeStamp, TElPGPSignature &Signature)
{
	SBCheckError(TElPGPCustomSecretKey_Sign_2(_Handle, TimeStamp, Signature.getHandle()));
}

SB_INLINE void TElPGPCustomSecretKey::Sign(int64_t TimeStamp, TElPGPSignature *Signature)
{
	SBCheckError(TElPGPCustomSecretKey_Sign_2(_Handle, TimeStamp, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
SB_INLINE void TElPGPCustomSecretKey::Sign(TElPGPSignature &SubjectSignature, TElPGPSignature &Signature)
{
	SBCheckError(TElPGPCustomSecretKey_Sign_3(_Handle, SubjectSignature.getHandle(), Signature.getHandle()));
}

SB_INLINE void TElPGPCustomSecretKey::Sign(TElPGPSignature *SubjectSignature, TElPGPSignature *Signature)
{
	SBCheckError(TElPGPCustomSecretKey_Sign_3(_Handle, (SubjectSignature != NULL) ? SubjectSignature->getHandle() : SB_NULL_HANDLE, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

#ifdef SB_USE_CLASSES_TELHASHFUNCTION_AND_TELPGPSIGNATURE
SB_INLINE void TElPGPCustomSecretKey::Sign(TElHashFunction &HashFunction, TElPGPSignature &Signature, int32_t SignatureClass)
{
	SBCheckError(TElPGPCustomSecretKey_Sign_4(_Handle, HashFunction.getHandle(), Signature.getHandle(), SignatureClass));
}

SB_INLINE void TElPGPCustomSecretKey::Sign(TElHashFunction *HashFunction, TElPGPSignature *Signature, int32_t SignatureClass)
{
	SBCheckError(TElPGPCustomSecretKey_Sign_4(_Handle, (HashFunction != NULL) ? HashFunction->getHandle() : SB_NULL_HANDLE, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE, SignatureClass));
}
#endif /* SB_USE_CLASSES_TELHASHFUNCTION_AND_TELPGPSIGNATURE */

#ifdef SB_USE_CLASSES_TELPGPCUSTOMPUBLICKEY_AND_TELPGPSIGNATURE
SB_INLINE void TElPGPCustomSecretKey::DirectSign(TElPGPCustomPublicKey &Key, TElPGPSignature &Signature)
{
	SBCheckError(TElPGPCustomSecretKey_DirectSign(_Handle, Key.getHandle(), Signature.getHandle()));
}

SB_INLINE void TElPGPCustomSecretKey::DirectSign(TElPGPCustomPublicKey *Key, TElPGPSignature *Signature)
{
	SBCheckError(TElPGPCustomSecretKey_DirectSign(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELPGPCUSTOMPUBLICKEY_AND_TELPGPSIGNATURE */

#ifdef SB_USE_CLASSES_TELPGPCUSTOMPUBLICKEY_AND_TELPGPSIGNATURE
SB_INLINE void TElPGPCustomSecretKey::Revoke(TElPGPCustomPublicKey &Key, TElPGPSignature &Signature)
{
	SBCheckError(TElPGPCustomSecretKey_Revoke(_Handle, Key.getHandle(), Signature.getHandle()));
}

SB_INLINE void TElPGPCustomSecretKey::Revoke(TElPGPCustomPublicKey *Key, TElPGPSignature *Signature)
{
	SBCheckError(TElPGPCustomSecretKey_Revoke(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELPGPCUSTOMPUBLICKEY_AND_TELPGPSIGNATURE */

#ifdef SB_USE_CLASSES_TELPGPCUSTOMUSER_AND_TELPGPPUBLICKEY_AND_TELPGPSIGNATURE
SB_INLINE void TElPGPCustomSecretKey::Revoke(TElPGPPublicKey &Key, TElPGPCustomUser &User, TElPGPSignature &Signature, TElPGPSignature &RevokedSignature)
{
	SBCheckError(TElPGPCustomSecretKey_Revoke_1(_Handle, Key.getHandle(), User.getHandle(), Signature.getHandle(), RevokedSignature.getHandle()));
}

SB_INLINE void TElPGPCustomSecretKey::Revoke(TElPGPPublicKey *Key, TElPGPCustomUser *User, TElPGPSignature *Signature, TElPGPSignature *RevokedSignature)
{
	SBCheckError(TElPGPCustomSecretKey_Revoke_1(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (User != NULL) ? User->getHandle() : SB_NULL_HANDLE, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE, (RevokedSignature != NULL) ? RevokedSignature->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELPGPCUSTOMUSER_AND_TELPGPPUBLICKEY_AND_TELPGPSIGNATURE */

#ifdef SB_USE_CLASSES_TELPGPCUSTOMPUBLICKEY_AND_TELPGPSIGNATURE
SB_INLINE void TElPGPCustomSecretKey::DirectRevoke(TElPGPCustomPublicKey &Key, TElPGPSignature &Signature, TElPGPSignature &RevokedSignature)
{
	SBCheckError(TElPGPCustomSecretKey_DirectRevoke(_Handle, Key.getHandle(), Signature.getHandle(), RevokedSignature.getHandle()));
}

SB_INLINE void TElPGPCustomSecretKey::DirectRevoke(TElPGPCustomPublicKey *Key, TElPGPSignature *Signature, TElPGPSignature *RevokedSignature)
{
	SBCheckError(TElPGPCustomSecretKey_DirectRevoke(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE, (RevokedSignature != NULL) ? RevokedSignature->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELPGPCUSTOMPUBLICKEY_AND_TELPGPSIGNATURE */

void TElPGPCustomSecretKey::Decrypt(const TSBPGPEncryptedSymmetricKey &EncrData, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPCustomSecretKey_Decrypt(_Handle, &EncrData, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1238330986, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElPGPCustomSecretKey::PassphraseValid()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomSecretKey_PassphraseValid(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPCustomSecretKey::IsSigningKey(bool WithSubkeys)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomSecretKey_IsSigningKey(_Handle, (int8_t)WithSubkeys, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPCustomSecretKey::IsEncryptingKey(bool WithSubkeys)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomSecretKey_IsEncryptingKey(_Handle, (int8_t)WithSubkeys, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
SB_INLINE TElPublicKeyMaterialHandle TElPGPCustomSecretKey::ExportKeyMaterial(bool PublicOnly)
{
	TElPublicKeyMaterialHandle OutResult;
	SBCheckError(TElPGPCustomSecretKey_ExportKeyMaterial(_Handle, (int8_t)PublicOnly, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
SB_INLINE void TElPGPCustomSecretKey::ExportSecretKeyMaterial(TElPublicKeyMaterial &KeyMaterial)
{
	SBCheckError(TElPGPCustomSecretKey_ExportSecretKeyMaterial(_Handle, KeyMaterial.getHandle()));
}

SB_INLINE void TElPGPCustomSecretKey::ExportSecretKeyMaterial(TElPublicKeyMaterial *KeyMaterial)
{
	SBCheckError(TElPGPCustomSecretKey_ExportSecretKeyMaterial(_Handle, (KeyMaterial != NULL) ? KeyMaterial->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
SB_INLINE void TElPGPCustomSecretKey::ImportKeyMaterial(TElPublicKeyMaterial &KeyMaterial)
{
	SBCheckError(TElPGPCustomSecretKey_ImportKeyMaterial(_Handle, KeyMaterial.getHandle()));
}

SB_INLINE void TElPGPCustomSecretKey::ImportKeyMaterial(TElPublicKeyMaterial *KeyMaterial)
{
	SBCheckError(TElPGPCustomSecretKey_ImportKeyMaterial(_Handle, (KeyMaterial != NULL) ? KeyMaterial->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
SB_INLINE void TElPGPCustomSecretKey::ImportKeyMaterial(TElPublicKeyMaterial &SecKeyMaterial, TElPublicKeyMaterial &PubKeyMaterial)
{
	SBCheckError(TElPGPCustomSecretKey_ImportKeyMaterial_1(_Handle, SecKeyMaterial.getHandle(), PubKeyMaterial.getHandle()));
}

SB_INLINE void TElPGPCustomSecretKey::ImportKeyMaterial(TElPublicKeyMaterial *SecKeyMaterial, TElPublicKeyMaterial *PubKeyMaterial)
{
	SBCheckError(TElPGPCustomSecretKey_ImportKeyMaterial_1(_Handle, (SecKeyMaterial != NULL) ? SecKeyMaterial->getHandle() : SB_NULL_HANDLE, (PubKeyMaterial != NULL) ? PubKeyMaterial->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
SB_INLINE void TElPGPCustomSecretKey::ImportKeyMaterial(TElPublicKeyMaterial &KeyMaterial, int64_t Timestamp, int32_t KeyVersion, int32_t Expires)
{
	SBCheckError(TElPGPCustomSecretKey_ImportKeyMaterial_2(_Handle, KeyMaterial.getHandle(), Timestamp, KeyVersion, Expires));
}

SB_INLINE void TElPGPCustomSecretKey::ImportKeyMaterial(TElPublicKeyMaterial *KeyMaterial, int64_t Timestamp, int32_t KeyVersion, int32_t Expires)
{
	SBCheckError(TElPGPCustomSecretKey_ImportKeyMaterial_2(_Handle, (KeyMaterial != NULL) ? KeyMaterial->getHandle() : SB_NULL_HANDLE, Timestamp, KeyVersion, Expires));
}
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
SB_INLINE void TElPGPCustomSecretKey::ImportKeyMaterial(TElPublicKeyMaterial &SecKeyMaterial, TElPublicKeyMaterial &PubKeyMaterial, int64_t Timestamp, int32_t KeyVersion, int32_t Expires)
{
	SBCheckError(TElPGPCustomSecretKey_ImportKeyMaterial_3(_Handle, SecKeyMaterial.getHandle(), PubKeyMaterial.getHandle(), Timestamp, KeyVersion, Expires));
}

SB_INLINE void TElPGPCustomSecretKey::ImportKeyMaterial(TElPublicKeyMaterial *SecKeyMaterial, TElPublicKeyMaterial *PubKeyMaterial, int64_t Timestamp, int32_t KeyVersion, int32_t Expires)
{
	SBCheckError(TElPGPCustomSecretKey_ImportKeyMaterial_3(_Handle, (SecKeyMaterial != NULL) ? SecKeyMaterial->getHandle() : SB_NULL_HANDLE, (PubKeyMaterial != NULL) ? PubKeyMaterial->getHandle() : SB_NULL_HANDLE, Timestamp, KeyVersion, Expires));
}
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

SB_INLINE void TElPGPCustomSecretKey::KeyID(TSBKeyID &OutResult)
{
	SBCheckError(TElPGPCustomSecretKey_KeyID(_Handle, &OutResult));
}

void TElPGPCustomSecretKey::KeyFP(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPCustomSecretKey_KeyFP(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1990483321, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPCustomSecretKey::PrepareForSigning(bool MultiUse)
{
	SBCheckError(TElPGPCustomSecretKey_PrepareForSigning(_Handle, (int8_t)MultiUse));
}

SB_INLINE void TElPGPCustomSecretKey::CancelPreparation()
{
	SBCheckError(TElPGPCustomSecretKey_CancelPreparation(_Handle));
}

bool TElPGPCustomSecretKey::AsyncOperationFinished()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomSecretKey_AsyncOperationFinished(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPCustomSecretKey::AcquireLock()
{
	SBCheckError(TElPGPCustomSecretKey_AcquireLock(_Handle));
}

SB_INLINE void TElPGPCustomSecretKey::ReleaseLock()
{
	SBCheckError(TElPGPCustomSecretKey_ReleaseLock(_Handle));
}

bool TElPGPCustomSecretKey::get_UseOldPackets()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomSecretKey_get_UseOldPackets(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPCustomSecretKey::set_UseOldPackets(bool Value)
{
	SBCheckError(TElPGPCustomSecretKey_set_UseOldPackets(_Handle, (int8_t)Value));
}

SB_INLINE int64_t TElPGPCustomSecretKey::get_Timestamp()
{
	int64_t OutResult;
	SBCheckError(TElPGPCustomSecretKey_get_Timestamp(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPCustomSecretKey::set_Timestamp(int64_t Value)
{
	SBCheckError(TElPGPCustomSecretKey_set_Timestamp(_Handle, Value));
}

SB_INLINE int32_t TElPGPCustomSecretKey::get_Version()
{
	int32_t OutResult;
	SBCheckError(TElPGPCustomSecretKey_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPCustomSecretKey::get_Expires()
{
	int32_t OutResult;
	SBCheckError(TElPGPCustomSecretKey_get_Expires(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPCustomSecretKey::set_Expires(int32_t Value)
{
	SBCheckError(TElPGPCustomSecretKey_set_Expires(_Handle, Value));
}

SB_INLINE int32_t TElPGPCustomSecretKey::get_BitsInKey()
{
	int32_t OutResult;
	SBCheckError(TElPGPCustomSecretKey_get_BitsInKey(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPCustomSecretKey::get_PublicKeyAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPCustomSecretKey_get_PublicKeyAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPCustomSecretKey::get_EncryptionAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPCustomSecretKey_get_EncryptionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPCustomSecretKey::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPCustomSecretKey_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPCustomSecretKey::get_KeyHashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPCustomSecretKey_get_KeyHashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPCustomSecretKey::set_KeyHashAlgorithm(int32_t Value)
{
	SBCheckError(TElPGPCustomSecretKey_set_KeyHashAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElPGPCustomSecretKey::get_QBits()
{
	int32_t OutResult;
	SBCheckError(TElPGPCustomSecretKey_get_QBits(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPCustomSecretKey::set_QBits(int32_t Value)
{
	SBCheckError(TElPGPCustomSecretKey_set_QBits(_Handle, Value));
}

SB_INLINE int32_t TElPGPCustomSecretKey::get_Curve()
{
	int32_t OutResult;
	SBCheckError(TElPGPCustomSecretKey_get_Curve(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPCustomSecretKey::set_Curve(int32_t Value)
{
	SBCheckError(TElPGPCustomSecretKey_set_Curve(_Handle, Value));
}

TSBPGPProtectionType TElPGPCustomSecretKey::get_Protection()
{
	TSBPGPProtectionTypeRaw OutResultRaw = 0;
	SBCheckError(TElPGPCustomSecretKey_get_Protection(_Handle, &OutResultRaw));
	return (TSBPGPProtectionType)OutResultRaw;
}

void TElPGPCustomSecretKey::get_Passphrase(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPCustomSecretKey_get_Passphrase(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(673341600, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPCustomSecretKey::set_Passphrase(const std::string &Value)
{
	SBCheckError(TElPGPCustomSecretKey_set_Passphrase(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELPGPTRUST
TElPGPTrust* TElPGPCustomSecretKey::get_Trust()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPCustomSecretKey_get_Trust(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Trust)
		this->_Inst_Trust = new TElPGPTrust(hOutResult, ohFalse);
	else
		this->_Inst_Trust->updateHandle(hOutResult);
	return this->_Inst_Trust;
}
#endif /* SB_USE_CLASS_TELPGPTRUST */

bool TElPGPCustomSecretKey::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomSecretKey_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPCustomSecretKey::set_Enabled(bool Value)
{
	SBCheckError(TElPGPCustomSecretKey_set_Enabled(_Handle, (int8_t)Value));
}

void TElPGPCustomSecretKey::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPTRUST
	this->_Inst_Trust = NULL;
#endif /* SB_USE_CLASS_TELPGPTRUST */
}

TElPGPCustomSecretKey::TElPGPCustomSecretKey(TElPGPCustomSecretKeyHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElPGPCustomSecretKey::TElPGPCustomSecretKey() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPCustomSecretKey_Create(&_Handle));
}

TElPGPCustomSecretKey::~TElPGPCustomSecretKey()
{
#ifdef SB_USE_CLASS_TELPGPTRUST
	delete this->_Inst_Trust;
	this->_Inst_Trust = NULL;
#endif /* SB_USE_CLASS_TELPGPTRUST */
}
#endif /* SB_USE_CLASS_TELPGPCUSTOMSECRETKEY */

#ifdef SB_USE_CLASS_TELPGPSECRETSUBKEY

SB_INLINE void TElPGPSecretSubkey::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPSecretSubkey_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPSecretSubkey::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPSecretSubkey_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPSecretSubkey::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPSecretSubkey_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPSecretSubkey::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPSecretSubkey_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELPGPSECRETKEY
TElPGPSecretKey* TElPGPSecretSubkey::get_Supkey()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPSecretSubkey_get_Supkey(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Supkey)
		this->_Inst_Supkey = new TElPGPSecretKey(hOutResult, ohFalse);
	else
		this->_Inst_Supkey->updateHandle(hOutResult);
	return this->_Inst_Supkey;
}
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */

#ifdef SB_USE_CLASS_TELPGPPUBLICSUBKEY
TElPGPPublicSubkey* TElPGPSecretSubkey::get_PublicKey()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPSecretSubkey_get_PublicKey(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PublicKey)
		this->_Inst_PublicKey = new TElPGPPublicSubkey(hOutResult, ohFalse);
	else
		this->_Inst_PublicKey->updateHandle(hOutResult);
	return this->_Inst_PublicKey;
}
#endif /* SB_USE_CLASS_TELPGPPUBLICSUBKEY */

void TElPGPSecretSubkey::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPSECRETKEY
	this->_Inst_Supkey = NULL;
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */
#ifdef SB_USE_CLASS_TELPGPPUBLICSUBKEY
	this->_Inst_PublicKey = NULL;
#endif /* SB_USE_CLASS_TELPGPPUBLICSUBKEY */
}

TElPGPSecretSubkey::TElPGPSecretSubkey(TElPGPSecretSubkeyHandle handle, TElOwnHandle ownHandle) : TElPGPCustomSecretKey(handle, ownHandle)
{
	initInstances();
}

TElPGPSecretSubkey::TElPGPSecretSubkey() : TElPGPCustomSecretKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPSecretSubkey_Create(&_Handle));
}

TElPGPSecretSubkey::~TElPGPSecretSubkey()
{
#ifdef SB_USE_CLASS_TELPGPSECRETKEY
	delete this->_Inst_Supkey;
	this->_Inst_Supkey = NULL;
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */
#ifdef SB_USE_CLASS_TELPGPPUBLICSUBKEY
	delete this->_Inst_PublicKey;
	this->_Inst_PublicKey = NULL;
#endif /* SB_USE_CLASS_TELPGPPUBLICSUBKEY */
}
#endif /* SB_USE_CLASS_TELPGPSECRETSUBKEY */

#ifdef SB_USE_CLASS_TELPGPSECRETKEY

bool TElPGPSecretKey::RemoveSubkey(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSecretKey_RemoveSubkey(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELPGPSECRETSUBKEY
bool TElPGPSecretKey::RemoveSubkey(TElPGPSecretSubkey &Subkey)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSecretKey_RemoveSubkey_1(_Handle, Subkey.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPSecretKey::RemoveSubkey(TElPGPSecretSubkey *Subkey)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSecretKey_RemoveSubkey_1(_Handle, (Subkey != NULL) ? Subkey->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPGPSECRETSUBKEY */

SB_INLINE void TElPGPSecretKey::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPSecretKey_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPSecretKey::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPSecretKey_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPSecretKey::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPSecretKey_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPSecretKey::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPSecretKey_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElPGPSecretKey::AssignFromX509(TElX509Certificate &Certificate)
{
	SBCheckError(TElPGPSecretKey_AssignFromX509(_Handle, Certificate.getHandle()));
}

SB_INLINE void TElPGPSecretKey::AssignFromX509(TElX509Certificate *Certificate)
{
	SBCheckError(TElPGPSecretKey_AssignFromX509(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPSecretKey::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElPGPSecretKey_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElPGPSecretKey::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElPGPSecretKey_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElPGPSecretKey::LoadFromFile(const std::string &Filename)
{
	SBCheckError(TElPGPSecretKey_LoadFromFile(_Handle, Filename.data(), (int32_t)Filename.length()));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPSecretKey::SaveToStream(TStream &Stream, bool Armor)
{
	SBCheckError(TElPGPSecretKey_SaveToStream(_Handle, Stream.getHandle(), (int8_t)Armor));
}

SB_INLINE void TElPGPSecretKey::SaveToStream(TStream *Stream, bool Armor)
{
	SBCheckError(TElPGPSecretKey_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (int8_t)Armor));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElPGPSecretKey::SaveToFile(const std::string &Filename, bool Armor)
{
	SBCheckError(TElPGPSecretKey_SaveToFile(_Handle, Filename.data(), (int32_t)Filename.length(), (int8_t)Armor));
}

#ifdef SB_USE_CLASS_TELPGPCUSTOMUSER
SB_INLINE void TElPGPSecretKey::BindUser(TElPGPCustomUser &User)
{
	SBCheckError(TElPGPSecretKey_BindUser(_Handle, User.getHandle()));
}

SB_INLINE void TElPGPSecretKey::BindUser(TElPGPCustomUser *User)
{
	SBCheckError(TElPGPSecretKey_BindUser(_Handle, (User != NULL) ? User->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPCUSTOMUSER */

SB_INLINE void TElPGPSecretKey::Generate(const std::string &Password, int32_t KeyBits, int32_t KeyAlgorithm, int32_t SubkeyBits, int32_t SubkeyAlgorithm, const std::string &UserName, int32_t Expires)
{
	SBCheckError(TElPGPSecretKey_Generate(_Handle, Password.data(), (int32_t)Password.length(), KeyBits, KeyAlgorithm, SubkeyBits, SubkeyAlgorithm, UserName.data(), (int32_t)UserName.length(), Expires));
}

SB_INLINE void TElPGPSecretKey::Generate(const std::string &Password, int32_t KeyBits, int32_t KeyAlgorithm, const std::string &UserName, bool UseOldStyle, int32_t Expires)
{
	SBCheckError(TElPGPSecretKey_Generate_1(_Handle, Password.data(), (int32_t)Password.length(), KeyBits, KeyAlgorithm, UserName.data(), (int32_t)UserName.length(), (int8_t)UseOldStyle, Expires));
}

SB_INLINE void TElPGPSecretKey::BeginGenerate(int32_t KeyBits, int32_t KeyAlgorithm, int32_t SubkeyBits, int32_t SubkeyAlgorithm)
{
	SBCheckError(TElPGPSecretKey_BeginGenerate(_Handle, KeyBits, KeyAlgorithm, SubkeyBits, SubkeyAlgorithm));
}

SB_INLINE void TElPGPSecretKey::EndGenerate(const std::string &Password, const std::string &UserName, int32_t Expires, bool UseOldFormat)
{
	SBCheckError(TElPGPSecretKey_EndGenerate(_Handle, Password.data(), (int32_t)Password.length(), UserName.data(), (int32_t)UserName.length(), Expires, (int8_t)UseOldFormat));
}

#ifdef SB_USE_CLASS_TELPGPSECRETSUBKEY
SB_INLINE int32_t TElPGPSecretKey::AddSubkey(TElPGPSecretSubkey &Subkey)
{
	int32_t OutResult;
	SBCheckError(TElPGPSecretKey_AddSubkey(_Handle, Subkey.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPSecretKey::AddSubkey(TElPGPSecretSubkey *Subkey)
{
	int32_t OutResult;
	SBCheckError(TElPGPSecretKey_AddSubkey(_Handle, (Subkey != NULL) ? Subkey->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPSECRETSUBKEY */

SB_INLINE void TElPGPSecretKey::PrepareForSigning(bool MultiUse)
{
	SBCheckError(TElPGPSecretKey_PrepareForSigning(_Handle, (int8_t)MultiUse));
}

SB_INLINE void TElPGPSecretKey::CancelPreparation()
{
	SBCheckError(TElPGPSecretKey_CancelPreparation(_Handle));
}

bool TElPGPSecretKey::AsyncOperationFinished()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSecretKey_AsyncOperationFinished(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElPGPSecretKey::get_ArmorBoundary(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPSecretKey_get_ArmorBoundary(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1446153542, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPSecretKey::set_ArmorBoundary(const std::string &Value)
{
	SBCheckError(TElPGPSecretKey_set_ArmorBoundary(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElPGPSecretKey::get_ArmorHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPSecretKey_get_ArmorHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ArmorHeaders)
		this->_Inst_ArmorHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_ArmorHeaders->updateHandle(hOutResult);
	return this->_Inst_ArmorHeaders;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TELPGPSECRETSUBKEY
TElPGPSecretSubkey* TElPGPSecretKey::get_Subkeys(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPSecretKey_get_Subkeys(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Subkeys)
		this->_Inst_Subkeys = new TElPGPSecretSubkey(hOutResult, ohFalse);
	else
		this->_Inst_Subkeys->updateHandle(hOutResult);
	return this->_Inst_Subkeys;
}
#endif /* SB_USE_CLASS_TELPGPSECRETSUBKEY */

SB_INLINE int32_t TElPGPSecretKey::get_SubkeyCount()
{
	int32_t OutResult;
	SBCheckError(TElPGPSecretKey_get_SubkeyCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
TElPGPPublicKey* TElPGPSecretKey::get_PublicKey()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPSecretKey_get_PublicKey(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PublicKey)
		this->_Inst_PublicKey = new TElPGPPublicKey(hOutResult, ohFalse);
	else
		this->_Inst_PublicKey->updateHandle(hOutResult);
	return this->_Inst_PublicKey;
}
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */

SB_INLINE uint8_t TElPGPSecretKey::get_WriteFlags()
{
	uint8_t OutResult;
	SBCheckError(TElPGPSecretKey_get_WriteFlags(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPSecretKey::set_WriteFlags(uint8_t Value)
{
	SBCheckError(TElPGPSecretKey_set_WriteFlags(_Handle, Value));
}

bool TElPGPSecretKey::get_WriteOldPrefix()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSecretKey_get_WriteOldPrefix(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPSecretKey::set_WriteOldPrefix(bool Value)
{
	SBCheckError(TElPGPSecretKey_set_WriteOldPrefix(_Handle, (int8_t)Value));
}

SB_INLINE void TElPGPSecretKey::get_OnBeforeSign(TSBPGPBeforeSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPSecretKey_get_OnBeforeSign(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPSecretKey::set_OnBeforeSign(TSBPGPBeforeSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPSecretKey_set_OnBeforeSign(_Handle, pMethodValue, pDataValue));
}

void TElPGPSecretKey::initInstances()
{
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_ArmorHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELPGPSECRETSUBKEY
	this->_Inst_Subkeys = NULL;
#endif /* SB_USE_CLASS_TELPGPSECRETSUBKEY */
#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
	this->_Inst_PublicKey = NULL;
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */
}

TElPGPSecretKey::TElPGPSecretKey(TElPGPSecretKeyHandle handle, TElOwnHandle ownHandle) : TElPGPCustomSecretKey(handle, ownHandle)
{
	initInstances();
}

TElPGPSecretKey::TElPGPSecretKey() : TElPGPCustomSecretKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPSecretKey_Create(&_Handle));
}

TElPGPSecretKey::~TElPGPSecretKey()
{
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_ArmorHeaders;
	this->_Inst_ArmorHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELPGPSECRETSUBKEY
	delete this->_Inst_Subkeys;
	this->_Inst_Subkeys = NULL;
#endif /* SB_USE_CLASS_TELPGPSECRETSUBKEY */
#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
	delete this->_Inst_PublicKey;
	this->_Inst_PublicKey = NULL;
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */
}
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */

#ifdef SB_USE_CLASS_TELPGPTRUST

SB_INLINE void TElPGPTrust::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPTrust_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPTrust::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPTrust_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPTrust::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPTrust_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPTrust::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPTrust_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE uint8_t TElPGPTrust::get_OwnerTrust()
{
	uint8_t OutResult;
	SBCheckError(TElPGPTrust_get_OwnerTrust(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPTrust::set_OwnerTrust(uint8_t Value)
{
	SBCheckError(TElPGPTrust_set_OwnerTrust(_Handle, Value));
}

bool TElPGPTrust::get_Disabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPTrust_get_Disabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPTrust::set_Disabled(bool Value)
{
	SBCheckError(TElPGPTrust_set_Disabled(_Handle, (int8_t)Value));
}

bool TElPGPTrust::get_BuckStop()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPTrust_get_BuckStop(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPTrust::set_BuckStop(bool Value)
{
	SBCheckError(TElPGPTrust_set_BuckStop(_Handle, (int8_t)Value));
}

SB_INLINE uint8_t TElPGPTrust::get_KeyLegit()
{
	uint8_t OutResult;
	SBCheckError(TElPGPTrust_get_KeyLegit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPTrust::set_KeyLegit(uint8_t Value)
{
	SBCheckError(TElPGPTrust_set_KeyLegit(_Handle, Value));
}

bool TElPGPTrust::get_WarnOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPTrust_get_WarnOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPTrust::set_WarnOnly(bool Value)
{
	SBCheckError(TElPGPTrust_set_WarnOnly(_Handle, (int8_t)Value));
}

SB_INLINE uint8_t TElPGPTrust::get_SigTrust()
{
	uint8_t OutResult;
	SBCheckError(TElPGPTrust_get_SigTrust(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPTrust::set_SigTrust(uint8_t Value)
{
	SBCheckError(TElPGPTrust_set_SigTrust(_Handle, Value));
}

bool TElPGPTrust::get_Checked()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPTrust_get_Checked(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPTrust::set_Checked(bool Value)
{
	SBCheckError(TElPGPTrust_set_Checked(_Handle, (int8_t)Value));
}

bool TElPGPTrust::get_Contiguous()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPTrust_get_Contiguous(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPTrust::set_Contiguous(bool Value)
{
	SBCheckError(TElPGPTrust_set_Contiguous(_Handle, (int8_t)Value));
}

SB_INLINE uint8_t TElPGPTrust::get_Flags()
{
	uint8_t OutResult;
	SBCheckError(TElPGPTrust_get_Flags(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPTrust::set_Flags(uint8_t Value)
{
	SBCheckError(TElPGPTrust_set_Flags(_Handle, Value));
}

TElPGPTrust::TElPGPTrust(TElPGPTrustHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElPGPTrust::TElPGPTrust() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPTrust_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPTRUST */

#ifdef SB_USE_CLASS_TELPGPSIGNATURE

SB_INLINE void TElPGPSignature::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPSignature_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPSignature::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPSignature_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPSignature::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPSignature_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPSignature::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPSignature_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPSignature::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElPGPSignature_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElPGPSignature::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElPGPSignature_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPSignature::SaveToStream(TStream &Stream)
{
	SBCheckError(TElPGPSignature_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElPGPSignature::SaveToStream(TStream *Stream)
{
	SBCheckError(TElPGPSignature_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElPGPSignature::SaveOnePass(bool Nested)
{
	SBCheckError(TElPGPSignature_SaveOnePass(_Handle, (int8_t)Nested));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPSignature::SaveOnePassToStream(TStream &Stream, bool Nested)
{
	SBCheckError(TElPGPSignature_SaveOnePassToStream(_Handle, Stream.getHandle(), (int8_t)Nested));
}

SB_INLINE void TElPGPSignature::SaveOnePassToStream(TStream *Stream, bool Nested)
{
	SBCheckError(TElPGPSignature_SaveOnePassToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (int8_t)Nested));
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElPGPSignature::IsKeyRevocation()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignature_IsKeyRevocation(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPSignature::IsSubkeyRevocation()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignature_IsSubkeyRevocation(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPSignature::IsUserRevocation()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignature_IsUserRevocation(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPSignature::IsDocumentSignature()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignature_IsDocumentSignature(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPSignature::IsStandalone()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignature_IsStandalone(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPSignature::IsUserCertification()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignature_IsUserCertification(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPSignature::IsSubkeyBinding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignature_IsSubkeyBinding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPSignature::IsDirectKeySignature()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignature_IsDirectKeySignature(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPSignature::IsTimestampSignature()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignature_IsTimestampSignature(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPSignature::SignerKeyID(TSBKeyID &OutResult)
{
	SBCheckError(TElPGPSignature_SignerKeyID(_Handle, &OutResult));
}

SB_INLINE int32_t TElPGPSignature::AddExtension(TSBPGPSignatureExtension ExtType, bool Hashed, bool Critical)
{
	int32_t OutResult;
	SBCheckError(TElPGPSignature_AddExtension(_Handle, (TSBPGPSignatureExtensionRaw)ExtType, (int8_t)Hashed, (int8_t)Critical, &OutResult));
	return OutResult;
}

bool TElPGPSignature::RemoveExtension(TSBPGPSignatureExtension ExtType, int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignature_RemoveExtension(_Handle, (TSBPGPSignatureExtensionRaw)ExtType, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPSignature::RemoveExtension(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignature_RemoveExtension_1(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELPGPSIGNATURESUBPACKET
SB_INLINE TElPGPSignatureSubpacketHandle TElPGPSignature::GetExtensionByType(TSBPGPSignatureExtension ExtType, int32_t Index)
{
	TElPGPSignatureSubpacketHandle OutResult;
	SBCheckError(TElPGPSignature_GetExtensionByType(_Handle, (TSBPGPSignatureExtensionRaw)ExtType, Index, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPSIGNATURESUBPACKET */

SB_INLINE int32_t TElPGPSignature::GetExtensionCount(TSBPGPSignatureExtension ExtType)
{
	int32_t OutResult;
	SBCheckError(TElPGPSignature_GetExtensionCount(_Handle, (TSBPGPSignatureExtensionRaw)ExtType, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPSignature::ClearExtensions()
{
	SBCheckError(TElPGPSignature_ClearExtensions(_Handle));
}

bool TElPGPSignature::get_IsX509Certificate()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignature_get_IsX509Certificate(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELPGPSIGNATURESUBPACKET
TElPGPSignatureSubpacket* TElPGPSignature::get_Extensions(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPSignature_get_Extensions(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TElPGPSignatureSubpacket(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TELPGPSIGNATURESUBPACKET */

void TElPGPSignature::get_RegularExpression(int32_t Index, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPSignature_get_RegularExpression(_Handle, Index, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-910936461, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPSignature::set_RegularExpression(int32_t Index, const std::string &Value)
{
	SBCheckError(TElPGPSignature_set_RegularExpression(_Handle, Index, Value.data(), (int32_t)Value.length()));
}

SB_INLINE uint8_t TElPGPSignature::get_Version()
{
	uint8_t OutResult;
	SBCheckError(TElPGPSignature_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPSignature::set_Version(uint8_t Value)
{
	SBCheckError(TElPGPSignature_set_Version(_Handle, Value));
}

SB_INLINE int32_t TElPGPSignature::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPSignature_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPSignature::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElPGPSignature_set_HashAlgorithm(_Handle, Value));
}

bool TElPGPSignature::get_UseOldPackets()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignature_get_UseOldPackets(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPSignature::set_UseOldPackets(bool Value)
{
	SBCheckError(TElPGPSignature_set_UseOldPackets(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElPGPSignature::get_X509Certificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPSignature_get_X509Certificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_X509Certificate)
		this->_Inst_X509Certificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_X509Certificate->updateHandle(hOutResult);
	return this->_Inst_X509Certificate;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

bool TElPGPSignature::get_Validated()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignature_get_Validated(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPSignature::set_Validated(bool Value)
{
	SBCheckError(TElPGPSignature_set_Validated(_Handle, (int8_t)Value));
}

bool TElPGPSignature::get_StrictlyValid()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignature_get_StrictlyValid(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPSignature::set_StrictlyValid(bool Value)
{
	SBCheckError(TElPGPSignature_set_StrictlyValid(_Handle, (int8_t)Value));
}

SB_INLINE int64_t TElPGPSignature::get_CreationTime()
{
	int64_t OutResult;
	SBCheckError(TElPGPSignature_get_CreationTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPSignature::set_CreationTime(int64_t Value)
{
	SBCheckError(TElPGPSignature_set_CreationTime(_Handle, Value));
}

SB_INLINE int32_t TElPGPSignature::get_KeyExpirationTime()
{
	int32_t OutResult;
	SBCheckError(TElPGPSignature_get_KeyExpirationTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPSignature::set_KeyExpirationTime(int32_t Value)
{
	SBCheckError(TElPGPSignature_set_KeyExpirationTime(_Handle, Value));
}

SB_INLINE int32_t TElPGPSignature::get_ExpirationTime()
{
	int32_t OutResult;
	SBCheckError(TElPGPSignature_get_ExpirationTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPSignature::set_ExpirationTime(int32_t Value)
{
	SBCheckError(TElPGPSignature_set_ExpirationTime(_Handle, Value));
}

bool TElPGPSignature::get_Exportable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignature_get_Exportable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPSignature::set_Exportable(bool Value)
{
	SBCheckError(TElPGPSignature_set_Exportable(_Handle, (int8_t)Value));
}

bool TElPGPSignature::get_Revocable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignature_get_Revocable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPSignature::set_Revocable(bool Value)
{
	SBCheckError(TElPGPSignature_set_Revocable(_Handle, (int8_t)Value));
}

SB_INLINE uint8_t TElPGPSignature::get_TrustLevel()
{
	uint8_t OutResult;
	SBCheckError(TElPGPSignature_get_TrustLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPSignature::set_TrustLevel(uint8_t Value)
{
	SBCheckError(TElPGPSignature_set_TrustLevel(_Handle, Value));
}

SB_INLINE uint8_t TElPGPSignature::get_TrustAmount()
{
	uint8_t OutResult;
	SBCheckError(TElPGPSignature_get_TrustAmount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPSignature::set_TrustAmount(uint8_t Value)
{
	SBCheckError(TElPGPSignature_set_TrustAmount(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELPGPTRUST
TElPGPTrust* TElPGPSignature::get_Trust()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPSignature_get_Trust(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Trust)
		this->_Inst_Trust = new TElPGPTrust(hOutResult, ohFalse);
	else
		this->_Inst_Trust->updateHandle(hOutResult);
	return this->_Inst_Trust;
}
#endif /* SB_USE_CLASS_TELPGPTRUST */

SB_INLINE int32_t TElPGPSignature::get_RegularExpressionCount()
{
	int32_t OutResult;
	SBCheckError(TElPGPSignature_get_RegularExpressionCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPSignature::set_RegularExpressionCount(int32_t Value)
{
	SBCheckError(TElPGPSignature_set_RegularExpressionCount(_Handle, Value));
}

bool TElPGPSignature::get_PrimaryUserID()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignature_get_PrimaryUserID(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPSignature::set_PrimaryUserID(bool Value)
{
	SBCheckError(TElPGPSignature_set_PrimaryUserID(_Handle, (int8_t)Value));
}

void TElPGPSignature::get_PolicyURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPSignature_get_PolicyURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-856682067, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPSignature::set_PolicyURL(const std::string &Value)
{
	SBCheckError(TElPGPSignature_set_PolicyURL(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPGPSignature::get_SignerUserID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPSignature_get_SignerUserID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-555554824, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPSignature::set_SignerUserID(const std::string &Value)
{
	SBCheckError(TElPGPSignature_set_SignerUserID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPGPSignature::get_ReasonForRevocation(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPSignature_get_ReasonForRevocation(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1210082997, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPSignature::set_ReasonForRevocation(const std::string &Value)
{
	SBCheckError(TElPGPSignature_set_ReasonForRevocation(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElPGPSignature::get_SignatureClass()
{
	int32_t OutResult;
	SBCheckError(TElPGPSignature_get_SignatureClass(_Handle, &OutResult));
	return OutResult;
}

TSBPGPUserCertificationType TElPGPSignature::get_CertificationType()
{
	TSBPGPUserCertificationTypeRaw OutResultRaw = 0;
	SBCheckError(TElPGPSignature_get_CertificationType(_Handle, &OutResultRaw));
	return (TSBPGPUserCertificationType)OutResultRaw;
}

SB_INLINE void TElPGPSignature::set_CertificationType(TSBPGPUserCertificationType Value)
{
	SBCheckError(TElPGPSignature_set_CertificationType(_Handle, (TSBPGPUserCertificationTypeRaw)Value));
}

bool TElPGPSignature::get_Revocation()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignature_get_Revocation(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPSignature::get_IsTextSignature()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignature_get_IsTextSignature(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElPGPSignature::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPSIGNATURESUBPACKET
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELPGPSIGNATURESUBPACKET */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_X509Certificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELPGPTRUST
	this->_Inst_Trust = NULL;
#endif /* SB_USE_CLASS_TELPGPTRUST */
}

TElPGPSignature::TElPGPSignature(TElPGPSignatureHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElPGPSignature::TElPGPSignature() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPSignature_Create(&_Handle));
}

#ifdef SB_USE_CLASS_TELPGPSIGNATUREENTITY
TElPGPSignature::TElPGPSignature(TElPGPSignatureEntity &Entity) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPSignature_Create_1(Entity.getHandle(), &_Handle));
}

TElPGPSignature::TElPGPSignature(TElPGPSignatureEntity *Entity) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPSignature_Create_1((Entity != NULL) ? Entity->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPGPSIGNATUREENTITY */

TElPGPSignature::TElPGPSignature(TElPGPSignature &Source, bool CopySigMaterial) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPSignature_Create_2(Source.getHandle(), (int8_t)CopySigMaterial, &_Handle));
}

TElPGPSignature::TElPGPSignature(TElPGPSignature *Source, bool CopySigMaterial) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPSignature_Create_2((Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (int8_t)CopySigMaterial, &_Handle));
}

TElPGPSignature::~TElPGPSignature()
{
#ifdef SB_USE_CLASS_TELPGPSIGNATURESUBPACKET
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELPGPSIGNATURESUBPACKET */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_X509Certificate;
	this->_Inst_X509Certificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELPGPTRUST
	delete this->_Inst_Trust;
	this->_Inst_Trust = NULL;
#endif /* SB_USE_CLASS_TELPGPTRUST */
}
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

#ifdef SB_USE_CLASS_TELPGPCUSTOMUSER

SB_INLINE void TElPGPCustomUser::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPCustomUser_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPCustomUser::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPCustomUser_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPCustomUser::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPCustomUser_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPCustomUser::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPCustomUser_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
SB_INLINE int32_t TElPGPCustomUser::AddSignature(TElPGPSignature &Signature)
{
	int32_t OutResult;
	SBCheckError(TElPGPCustomUser_AddSignature(_Handle, Signature.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPCustomUser::AddSignature(TElPGPSignature *Signature)
{
	int32_t OutResult;
	SBCheckError(TElPGPCustomUser_AddSignature(_Handle, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

SB_INLINE void TElPGPCustomUser::ClearSignatures()
{
	SBCheckError(TElPGPCustomUser_ClearSignatures(_Handle));
}

bool TElPGPCustomUser::RemoveSignature(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomUser_RemoveSignature(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
bool TElPGPCustomUser::RemoveSignature(TElPGPSignature &Signature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomUser_RemoveSignature_1(_Handle, Signature.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPCustomUser::RemoveSignature(TElPGPSignature *Signature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomUser_RemoveSignature_1(_Handle, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
TElPGPSignature* TElPGPCustomUser::get_Signatures(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPCustomUser_get_Signatures(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signatures)
		this->_Inst_Signatures = new TElPGPSignature(hOutResult, ohFalse);
	else
		this->_Inst_Signatures->updateHandle(hOutResult);
	return this->_Inst_Signatures;
}
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

SB_INLINE int32_t TElPGPCustomUser::get_SignatureCount()
{
	int32_t OutResult;
	SBCheckError(TElPGPCustomUser_get_SignatureCount(_Handle, &OutResult));
	return OutResult;
}

bool TElPGPCustomUser::get_Revoked()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPCustomUser_get_Revoked(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElPGPCustomUser::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPSIGNATURE
	this->_Inst_Signatures = NULL;
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */
}

TElPGPCustomUser::TElPGPCustomUser(TElPGPCustomUserHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElPGPCustomUser::TElPGPCustomUser() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPCustomUser_Create(&_Handle));
}

TElPGPCustomUser::~TElPGPCustomUser()
{
#ifdef SB_USE_CLASS_TELPGPSIGNATURE
	delete this->_Inst_Signatures;
	this->_Inst_Signatures = NULL;
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */
}
#endif /* SB_USE_CLASS_TELPGPCUSTOMUSER */

#ifdef SB_USE_CLASS_TELPGPUSERID

SB_INLINE void TElPGPUserID::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPUserID_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPUserID::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPUserID_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPUserID::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPUserID_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPUserID::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPUserID_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

void TElPGPUserID::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPUserID_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1768724961, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPUserID::set_Name(const std::string &Value)
{
	SBCheckError(TElPGPUserID_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELPGPTRUST
TElPGPTrust* TElPGPUserID::get_Trust()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPUserID_get_Trust(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Trust)
		this->_Inst_Trust = new TElPGPTrust(hOutResult, ohFalse);
	else
		this->_Inst_Trust->updateHandle(hOutResult);
	return this->_Inst_Trust;
}
#endif /* SB_USE_CLASS_TELPGPTRUST */

void TElPGPUserID::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPTRUST
	this->_Inst_Trust = NULL;
#endif /* SB_USE_CLASS_TELPGPTRUST */
}

TElPGPUserID::TElPGPUserID(TElPGPUserIDHandle handle, TElOwnHandle ownHandle) : TElPGPCustomUser(handle, ownHandle)
{
	initInstances();
}

TElPGPUserID::TElPGPUserID() : TElPGPCustomUser(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPUserID_Create(&_Handle));
}

TElPGPUserID::~TElPGPUserID()
{
#ifdef SB_USE_CLASS_TELPGPTRUST
	delete this->_Inst_Trust;
	this->_Inst_Trust = NULL;
#endif /* SB_USE_CLASS_TELPGPTRUST */
}
#endif /* SB_USE_CLASS_TELPGPUSERID */

#ifdef SB_USE_CLASS_TELPGPUSERATTR

SB_INLINE void TElPGPUserAttr::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPUserAttr_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPUserAttr::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPUserAttr_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPUserAttr::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPUserAttr_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPUserAttr::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPUserAttr_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELPGPJPEGIMAGE
SB_INLINE int32_t TElPGPUserAttr::AddImage(TElPGPJpegImage &Image)
{
	int32_t OutResult;
	SBCheckError(TElPGPUserAttr_AddImage(_Handle, Image.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPUserAttr::AddImage(TElPGPJpegImage *Image)
{
	int32_t OutResult;
	SBCheckError(TElPGPUserAttr_AddImage(_Handle, (Image != NULL) ? Image->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPJPEGIMAGE */

bool TElPGPUserAttr::RemoveImage(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPUserAttr_RemoveImage(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPUserAttr::ClearImages()
{
	SBCheckError(TElPGPUserAttr_ClearImages(_Handle));
}

SB_INLINE int32_t TElPGPUserAttr::ImageCount()
{
	int32_t OutResult;
	SBCheckError(TElPGPUserAttr_ImageCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPGPTRUST
TElPGPTrust* TElPGPUserAttr::get_Trust()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPUserAttr_get_Trust(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Trust)
		this->_Inst_Trust = new TElPGPTrust(hOutResult, ohFalse);
	else
		this->_Inst_Trust->updateHandle(hOutResult);
	return this->_Inst_Trust;
}
#endif /* SB_USE_CLASS_TELPGPTRUST */

#ifdef SB_USE_CLASS_TELPGPJPEGIMAGE
TElPGPJpegImage* TElPGPUserAttr::get_Images(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPUserAttr_get_Images(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Images)
		this->_Inst_Images = new TElPGPJpegImage(hOutResult, ohFalse);
	else
		this->_Inst_Images->updateHandle(hOutResult);
	return this->_Inst_Images;
}

SB_INLINE void TElPGPUserAttr::set_Images(int32_t Index, TElPGPJpegImage &Value)
{
	SBCheckError(TElPGPUserAttr_set_Images(_Handle, Index, Value.getHandle()));
}

SB_INLINE void TElPGPUserAttr::set_Images(int32_t Index, TElPGPJpegImage *Value)
{
	SBCheckError(TElPGPUserAttr_set_Images(_Handle, Index, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPJPEGIMAGE */

void TElPGPUserAttr::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPTRUST
	this->_Inst_Trust = NULL;
#endif /* SB_USE_CLASS_TELPGPTRUST */
#ifdef SB_USE_CLASS_TELPGPJPEGIMAGE
	this->_Inst_Images = NULL;
#endif /* SB_USE_CLASS_TELPGPJPEGIMAGE */
}

TElPGPUserAttr::TElPGPUserAttr(TElPGPUserAttrHandle handle, TElOwnHandle ownHandle) : TElPGPCustomUser(handle, ownHandle)
{
	initInstances();
}

TElPGPUserAttr::TElPGPUserAttr() : TElPGPCustomUser(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPUserAttr_Create(&_Handle));
}

TElPGPUserAttr::~TElPGPUserAttr()
{
#ifdef SB_USE_CLASS_TELPGPTRUST
	delete this->_Inst_Trust;
	this->_Inst_Trust = NULL;
#endif /* SB_USE_CLASS_TELPGPTRUST */
#ifdef SB_USE_CLASS_TELPGPJPEGIMAGE
	delete this->_Inst_Images;
	this->_Inst_Images = NULL;
#endif /* SB_USE_CLASS_TELPGPJPEGIMAGE */
}
#endif /* SB_USE_CLASS_TELPGPUSERATTR */

#ifdef SB_USE_CLASS_TELPGPKEYRING

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPKeyring::Load(TStream &APublic, TStream &ASecret, bool Clear)
{
	SBCheckError(TElPGPKeyring_Load(_Handle, APublic.getHandle(), ASecret.getHandle(), (int8_t)Clear));
}

SB_INLINE void TElPGPKeyring::Load(TStream *APublic, TStream *ASecret, bool Clear)
{
	SBCheckError(TElPGPKeyring_Load(_Handle, (APublic != NULL) ? APublic->getHandle() : SB_NULL_HANDLE, (ASecret != NULL) ? ASecret->getHandle() : SB_NULL_HANDLE, (int8_t)Clear));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElPGPKeyring::Load(const std::string &PublicKeysFile, const std::string &SecretKeysFile, bool Clear)
{
	SBCheckError(TElPGPKeyring_Load_1(_Handle, PublicKeysFile.data(), (int32_t)PublicKeysFile.length(), SecretKeysFile.data(), (int32_t)SecretKeysFile.length(), (int8_t)Clear));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE int32_t TElPGPKeyring::AddX509Certificate(TElX509Certificate &Certificate)
{
	int32_t OutResult;
	SBCheckError(TElPGPKeyring_AddX509Certificate(_Handle, Certificate.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPKeyring::AddX509Certificate(TElX509Certificate *Certificate)
{
	int32_t OutResult;
	SBCheckError(TElPGPKeyring_AddX509Certificate(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
SB_INLINE int32_t TElPGPKeyring::AddPublicKey(TElPGPPublicKey &Key)
{
	int32_t OutResult;
	SBCheckError(TElPGPKeyring_AddPublicKey(_Handle, Key.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPKeyring::AddPublicKey(TElPGPPublicKey *Key)
{
	int32_t OutResult;
	SBCheckError(TElPGPKeyring_AddPublicKey(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPSECRETKEY
SB_INLINE int32_t TElPGPKeyring::AddSecretKey(TElPGPSecretKey &Key)
{
	int32_t OutResult;
	SBCheckError(TElPGPKeyring_AddSecretKey(_Handle, Key.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPKeyring::AddSecretKey(TElPGPSecretKey *Key)
{
	int32_t OutResult;
	SBCheckError(TElPGPKeyring_AddSecretKey(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */

#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
bool TElPGPKeyring::RemovePublicKey(TElPGPPublicKey &Key, bool RemoveSecretKeyIfExists)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPKeyring_RemovePublicKey(_Handle, Key.getHandle(), (int8_t)RemoveSecretKeyIfExists, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPKeyring::RemovePublicKey(TElPGPPublicKey *Key, bool RemoveSecretKeyIfExists)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPKeyring_RemovePublicKey(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (int8_t)RemoveSecretKeyIfExists, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */

bool TElPGPKeyring::RemovePublicKey(int32_t Index, bool RemoveSecretKeyIfExists)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPKeyring_RemovePublicKey_1(_Handle, Index, (int8_t)RemoveSecretKeyIfExists, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELPGPSECRETKEY
bool TElPGPKeyring::RemoveSecretKey(TElPGPSecretKey &Key)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPKeyring_RemoveSecretKey(_Handle, Key.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPKeyring::RemoveSecretKey(TElPGPSecretKey *Key)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPKeyring_RemoveSecretKey(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */

bool TElPGPKeyring::RemoveSecretKey(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPKeyring_RemoveSecretKey_1(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPKeyring::Clear()
{
	SBCheckError(TElPGPKeyring_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPKeyring::Save(TStream &APublic, TStream &ASecret, bool Armor)
{
	SBCheckError(TElPGPKeyring_Save(_Handle, APublic.getHandle(), ASecret.getHandle(), (int8_t)Armor));
}

SB_INLINE void TElPGPKeyring::Save(TStream *APublic, TStream *ASecret, bool Armor)
{
	SBCheckError(TElPGPKeyring_Save(_Handle, (APublic != NULL) ? APublic->getHandle() : SB_NULL_HANDLE, (ASecret != NULL) ? ASecret->getHandle() : SB_NULL_HANDLE, (int8_t)Armor));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElPGPKeyring::Save(const std::string &PublicKeysFile, const std::string &SecretKeysFile, bool Armor)
{
	SBCheckError(TElPGPKeyring_Save_1(_Handle, PublicKeysFile.data(), (int32_t)PublicKeysFile.length(), SecretKeysFile.data(), (int32_t)SecretKeysFile.length(), (int8_t)Armor));
}

SB_INLINE void TElPGPKeyring::ExportTo(TElPGPKeyring &Dest)
{
	SBCheckError(TElPGPKeyring_ExportTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPKeyring::ExportTo(TElPGPKeyring *Dest)
{
	SBCheckError(TElPGPKeyring_ExportTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY
int32_t TElPGPKeyring::FindPublicKeyByID(const TSBKeyID &KeyID, TElPGPCustomPublicKey &Res, int32_t StartIndex)
{
	int32_t OutResult;
	TElClassHandle hRes = Res.getHandle();
	SBCheckError(TElPGPKeyring_FindPublicKeyByID(_Handle, &KeyID, &hRes, StartIndex, &OutResult));
	Res.updateHandle(hRes);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY
int32_t TElPGPKeyring::FindPublicKeyByID(const std::string &KeyID, TElPGPCustomPublicKey &Res, int32_t StartIndex)
{
	int32_t OutResult;
	TElClassHandle hRes = Res.getHandle();
	SBCheckError(TElPGPKeyring_FindPublicKeyByID_1(_Handle, KeyID.data(), (int32_t)KeyID.length(), &hRes, StartIndex, &OutResult));
	Res.updateHandle(hRes);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPCUSTOMSECRETKEY
int32_t TElPGPKeyring::FindSecretKeyByID(const TSBKeyID &KeyID, TElPGPCustomSecretKey &Res, int32_t StartIndex)
{
	int32_t OutResult;
	TElClassHandle hRes = Res.getHandle();
	SBCheckError(TElPGPKeyring_FindSecretKeyByID(_Handle, &KeyID, &hRes, StartIndex, &OutResult));
	Res.updateHandle(hRes);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPCUSTOMSECRETKEY */

#ifdef SB_USE_CLASS_TELPGPCUSTOMSECRETKEY
int32_t TElPGPKeyring::FindSecretKeyByID(const std::string &KeyID, TElPGPCustomSecretKey &Res, int32_t StartIndex)
{
	int32_t OutResult;
	TElClassHandle hRes = Res.getHandle();
	SBCheckError(TElPGPKeyring_FindSecretKeyByID_1(_Handle, KeyID.data(), (int32_t)KeyID.length(), &hRes, StartIndex, &OutResult));
	Res.updateHandle(hRes);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPCUSTOMSECRETKEY */

#ifdef SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY
int32_t TElPGPKeyring::InternalFindPublicKeyByID(const std::vector<uint8_t> &KeyID, TElPGPCustomPublicKey &Res, int32_t StartIndex)
{
	int32_t OutResult;
	TElClassHandle hRes = Res.getHandle();
	SBCheckError(TElPGPKeyring_InternalFindPublicKeyByID(_Handle, SB_STD_VECTOR_FRONT_ADR(KeyID), (int32_t)KeyID.size(), &hRes, StartIndex, &OutResult));
	Res.updateHandle(hRes);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPCUSTOMSECRETKEY
int32_t TElPGPKeyring::InternalFindSecretKeyByID(const std::vector<uint8_t> &KeyID, TElPGPCustomSecretKey &Res, int32_t StartIndex)
{
	int32_t OutResult;
	TElClassHandle hRes = Res.getHandle();
	SBCheckError(TElPGPKeyring_InternalFindSecretKeyByID(_Handle, SB_STD_VECTOR_FRONT_ADR(KeyID), (int32_t)KeyID.size(), &hRes, StartIndex, &OutResult));
	Res.updateHandle(hRes);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPCUSTOMSECRETKEY */

#ifdef SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY
SB_INLINE TElPGPCustomPublicKeyHandle TElPGPKeyring::FindPublicKeyByFP(const std::vector<uint8_t> &FP)
{
	TElPGPCustomPublicKeyHandle OutResult;
	SBCheckError(TElPGPKeyring_FindPublicKeyByFP(_Handle, SB_STD_VECTOR_FRONT_ADR(FP), (int32_t)FP.size(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPCUSTOMSECRETKEY
SB_INLINE TElPGPCustomSecretKeyHandle TElPGPKeyring::FindSecretKeyByFP(const std::vector<uint8_t> &FP)
{
	TElPGPCustomSecretKeyHandle OutResult;
	SBCheckError(TElPGPKeyring_FindSecretKeyByFP(_Handle, SB_STD_VECTOR_FRONT_ADR(FP), (int32_t)FP.size(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPCUSTOMSECRETKEY */

SB_INLINE int32_t TElPGPKeyring::FindPublicKeyByEmailAddress(const std::string &Address, int32_t StartIndex)
{
	int32_t OutResult;
	SBCheckError(TElPGPKeyring_FindPublicKeyByEmailAddress(_Handle, Address.data(), (int32_t)Address.length(), StartIndex, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPKeyring::FindSecretKeyByEmailAddress(const std::string &Address, int32_t StartIndex)
{
	int32_t OutResult;
	SBCheckError(TElPGPKeyring_FindSecretKeyByEmailAddress(_Handle, Address.data(), (int32_t)Address.length(), StartIndex, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TLIST
void TElPGPKeyring::ListKeys(bool PublicOnly, const std::string &Template, TList &ListOfKeys)
{
	TElClassHandle hListOfKeys = ListOfKeys.getHandle();
	SBCheckError(TElPGPKeyring_ListKeys(_Handle, (int8_t)PublicOnly, Template.data(), (int32_t)Template.length(), &hListOfKeys));
	ListOfKeys.updateHandle(hListOfKeys);
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
void TElPGPKeyring::ListKeys(bool PublicOnly, const std::string &Template, bool IncludeSubkeysMatchingUserIDTemplateInResult, TList &ListOfKeys)
{
	TElClassHandle hListOfKeys = ListOfKeys.getHandle();
	SBCheckError(TElPGPKeyring_ListKeys_1(_Handle, (int8_t)PublicOnly, Template.data(), (int32_t)Template.length(), (int8_t)IncludeSubkeysMatchingUserIDTemplateInResult, &hListOfKeys));
	ListOfKeys.updateHandle(hListOfKeys);
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASSES_TLIST_AND_TSTRINGLIST
void TElPGPKeyring::ListKeys(bool PublicOnly, const TStringList &Templates, bool IsAndCondition, TList &ListOfKeys)
{
	TElClassHandle hListOfKeys = ListOfKeys.getHandle();
	SBCheckError(TElPGPKeyring_ListKeys_2(_Handle, (int8_t)PublicOnly, Templates.getHandle(), (int8_t)IsAndCondition, &hListOfKeys));
	ListOfKeys.updateHandle(hListOfKeys);
}
#endif /* SB_USE_CLASSES_TLIST_AND_TSTRINGLIST */

#ifdef SB_USE_CLASSES_TLIST_AND_TSTRINGLIST
void TElPGPKeyring::ListKeys(bool PublicOnly, const TStringList &Templates, bool IsAndCondition, bool IncludeSubkeysMatchingUserIDTemplateInResult, TList &ListOfKeys)
{
	TElClassHandle hListOfKeys = ListOfKeys.getHandle();
	SBCheckError(TElPGPKeyring_ListKeys_3(_Handle, (int8_t)PublicOnly, Templates.getHandle(), (int8_t)IsAndCondition, (int8_t)IncludeSubkeysMatchingUserIDTemplateInResult, &hListOfKeys));
	ListOfKeys.updateHandle(hListOfKeys);
}
#endif /* SB_USE_CLASSES_TLIST_AND_TSTRINGLIST */

SB_INLINE void TElPGPKeyring::PrepareForEncryption(bool MultiUse)
{
	SBCheckError(TElPGPKeyring_PrepareForEncryption(_Handle, (int8_t)MultiUse));
}

SB_INLINE void TElPGPKeyring::PrepareForSigning(bool MultiUse)
{
	SBCheckError(TElPGPKeyring_PrepareForSigning(_Handle, (int8_t)MultiUse));
}

SB_INLINE void TElPGPKeyring::CancelPreparation()
{
	SBCheckError(TElPGPKeyring_CancelPreparation(_Handle));
}

bool TElPGPKeyring::AsyncOperationFinished()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPKeyring_AsyncOperationFinished(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElPGPKeyring::get_ArmorBoundary(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPKeyring_get_ArmorBoundary(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-406594854, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPKeyring::set_ArmorBoundary(const std::string &Value)
{
	SBCheckError(TElPGPKeyring_set_ArmorBoundary(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElPGPKeyring::get_ArmorHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPKeyring_get_ArmorHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ArmorHeaders)
		this->_Inst_ArmorHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_ArmorHeaders->updateHandle(hOutResult);
	return this->_Inst_ArmorHeaders;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
TElPGPPublicKey* TElPGPKeyring::get_PublicKeys(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPKeyring_get_PublicKeys(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PublicKeys)
		this->_Inst_PublicKeys = new TElPGPPublicKey(hOutResult, ohFalse);
	else
		this->_Inst_PublicKeys->updateHandle(hOutResult);
	return this->_Inst_PublicKeys;
}
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPSECRETKEY
TElPGPSecretKey* TElPGPKeyring::get_SecretKeys(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPKeyring_get_SecretKeys(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SecretKeys)
		this->_Inst_SecretKeys = new TElPGPSecretKey(hOutResult, ohFalse);
	else
		this->_Inst_SecretKeys->updateHandle(hOutResult);
	return this->_Inst_SecretKeys;
}
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */

SB_INLINE int32_t TElPGPKeyring::get_PublicCount()
{
	int32_t OutResult;
	SBCheckError(TElPGPKeyring_get_PublicCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPKeyring::get_SecretCount()
{
	int32_t OutResult;
	SBCheckError(TElPGPKeyring_get_SecretCount(_Handle, &OutResult));
	return OutResult;
}

bool TElPGPKeyring::get_SaveSecretKeySignatures()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPKeyring_get_SaveSecretKeySignatures(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPKeyring::set_SaveSecretKeySignatures(bool Value)
{
	SBCheckError(TElPGPKeyring_set_SaveSecretKeySignatures(_Handle, (int8_t)Value));
}

bool TElPGPKeyring::get_WriteTrust()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPKeyring_get_WriteTrust(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPKeyring::set_WriteTrust(bool Value)
{
	SBCheckError(TElPGPKeyring_set_WriteTrust(_Handle, (int8_t)Value));
}

void TElPGPKeyring::initInstances()
{
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_ArmorHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
	this->_Inst_PublicKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */
#ifdef SB_USE_CLASS_TELPGPSECRETKEY
	this->_Inst_SecretKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */
}

TElPGPKeyring::TElPGPKeyring(TElPGPKeyringHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElPGPKeyring::TElPGPKeyring(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPKeyring_Create(AOwner.getHandle(), &_Handle));
}

TElPGPKeyring::TElPGPKeyring(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPKeyring_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElPGPKeyring::~TElPGPKeyring()
{
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_ArmorHeaders;
	this->_Inst_ArmorHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
	delete this->_Inst_PublicKeys;
	this->_Inst_PublicKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */
#ifdef SB_USE_CLASS_TELPGPSECRETKEY
	delete this->_Inst_SecretKeys;
	this->_Inst_SecretKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */
}
#endif /* SB_USE_CLASS_TELPGPKEYRING */

#ifdef SB_USE_CLASS_TELPGPJPEGIMAGE

SB_INLINE void TElPGPJpegImage::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPJpegImage_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPJpegImage::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPJpegImage_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPJpegImage::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPJpegImage_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPJpegImage::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPJpegImage_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPJpegImage::Save()
{
	SBCheckError(TElPGPJpegImage_Save(_Handle));
}

SB_INLINE void TElPGPJpegImage::Load()
{
	SBCheckError(TElPGPJpegImage_Load(_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPJpegImage::SaveToStream(TStream &Stream)
{
	SBCheckError(TElPGPJpegImage_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElPGPJpegImage::SaveToStream(TStream *Stream)
{
	SBCheckError(TElPGPJpegImage_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPJpegImage::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElPGPJpegImage_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElPGPJpegImage::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElPGPJpegImage_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElPGPJpegImage::SaveToFile(const std::string &FileName)
{
	SBCheckError(TElPGPJpegImage_SaveToFile(_Handle, FileName.data(), (int32_t)FileName.length()));
}

SB_INLINE void TElPGPJpegImage::LoadFromFile(const std::string &FileName)
{
	SBCheckError(TElPGPJpegImage_LoadFromFile(_Handle, FileName.data(), (int32_t)FileName.length()));
}

void TElPGPJpegImage::get_JpegData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPJpegImage_get_JpegData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1611324230, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPJpegImage::set_JpegData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPGPJpegImage_set_JpegData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE void TElPGPJpegImage::get_OnRead(TSBPGPReadEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPJpegImage_get_OnRead(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPJpegImage::set_OnRead(TSBPGPReadEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPJpegImage_set_OnRead(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPJpegImage::get_OnWrite(TSBPGPWriteEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPJpegImage_get_OnWrite(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPJpegImage::set_OnWrite(TSBPGPWriteEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPJpegImage_set_OnWrite(_Handle, pMethodValue, pDataValue));
}

TElPGPJpegImage::TElPGPJpegImage(TElPGPJpegImageHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElPGPJpegImage::TElPGPJpegImage() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPJpegImage_Create(&_Handle));
}

#ifdef SB_USE_CLASS_TELPGPUSERATTRIMAGESUBPACKET
TElPGPJpegImage::TElPGPJpegImage(TElPGPUserAttrImageSubpacket &Source) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPJpegImage_Create_1(Source.getHandle(), &_Handle));
}

TElPGPJpegImage::TElPGPJpegImage(TElPGPUserAttrImageSubpacket *Source) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPJpegImage_Create_1((Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPGPUSERATTRIMAGESUBPACKET */

#endif /* SB_USE_CLASS_TELPGPJPEGIMAGE */

};	/* namespace SecureBlackbox */

