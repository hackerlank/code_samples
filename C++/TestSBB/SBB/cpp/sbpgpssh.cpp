#include "sbpgpssh.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSSHPGPKEY

void TElSSHPGPKey::Copy(TElSSHKey &Dest)
{
	TElClassHandle hDest = Dest.getHandle();
	SBCheckError(TElSSHPGPKey_Copy(_Handle, &hDest));
	Dest.updateHandle(hDest);
}

SB_INLINE void TElSSHPGPKey::Clear()
{
	SBCheckError(TElSSHPGPKey_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
SB_INLINE void TElSSHPGPKey::Import(TElPGPPublicKey &PubKey)
{
	SBCheckError(TElSSHPGPKey_Import(_Handle, PubKey.getHandle()));
}

SB_INLINE void TElSSHPGPKey::Import(TElPGPPublicKey *PubKey)
{
	SBCheckError(TElSSHPGPKey_Import(_Handle, (PubKey != NULL) ? PubKey->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPSECRETKEY
SB_INLINE void TElSSHPGPKey::Import(TElPGPSecretKey &SecKey)
{
	SBCheckError(TElSSHPGPKey_Import_1(_Handle, SecKey.getHandle()));
}

SB_INLINE void TElSSHPGPKey::Import(TElPGPSecretKey *SecKey)
{
	SBCheckError(TElSSHPGPKey_Import_1(_Handle, (SecKey != NULL) ? SecKey->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */

#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
TElPGPPublicKey* TElSSHPGPKey::get_PGPPublicKey()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHPGPKey_get_PGPPublicKey(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PGPPublicKey)
		this->_Inst_PGPPublicKey = new TElPGPPublicKey(hOutResult, ohFalse);
	else
		this->_Inst_PGPPublicKey->updateHandle(hOutResult);
	return this->_Inst_PGPPublicKey;
}
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPSECRETKEY
TElPGPSecretKey* TElSSHPGPKey::get_PGPSecretKey()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHPGPKey_get_PGPSecretKey(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PGPSecretKey)
		this->_Inst_PGPSecretKey = new TElPGPSecretKey(hOutResult, ohFalse);
	else
		this->_Inst_PGPSecretKey->updateHandle(hOutResult);
	return this->_Inst_PGPSecretKey;
}
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */

void TElSSHPGPKey::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
	this->_Inst_PGPPublicKey = NULL;
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */
#ifdef SB_USE_CLASS_TELPGPSECRETKEY
	this->_Inst_PGPSecretKey = NULL;
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */
}

TElSSHPGPKey::TElSSHPGPKey(TElSSHPGPKeyHandle handle, TElOwnHandle ownHandle) : TElSSHKey(handle, ownHandle)
{
	initInstances();
}

TElSSHPGPKey::TElSSHPGPKey() : TElSSHKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHPGPKey_Create(&_Handle));
}

TElSSHPGPKey::~TElSSHPGPKey()
{
#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
	delete this->_Inst_PGPPublicKey;
	this->_Inst_PGPPublicKey = NULL;
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */
#ifdef SB_USE_CLASS_TELPGPSECRETKEY
	delete this->_Inst_PGPSecretKey;
	this->_Inst_PGPSecretKey = NULL;
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */
}
#endif /* SB_USE_CLASS_TELSSHPGPKEY */

#ifdef SB_USE_CLASS_TELSSHPGPAUTHHANDLER

SB_INLINE int32_t TElSSHPGPAuthHandler::GetAlgorithmFromClientKexDHReply(const std::vector<uint8_t> &HostAlg)
{
	int32_t OutResult;
	SBCheckError(TElSSHPGPAuthHandler_GetAlgorithmFromClientKexDHReply(_Handle, SB_STD_VECTOR_FRONT_ADR(HostAlg), (int32_t)HostAlg.size(), &OutResult));
	return OutResult;
}

bool TElSSHPGPAuthHandler::ValidateServerSignature(int32_t Algorithm, const std::vector<uint8_t> &PubKeyStr, const std::vector<uint8_t> &Signature, const std::vector<uint8_t> &Hash, int32_t HashAlg, int32_t &ErrCode, std::string &ErrMessage)
{
	int32_t szErrMessage = (int32_t)ErrMessage.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElSSHPGPAuthHandler_ValidateServerSignature(_Handle, Algorithm, SB_STD_VECTOR_FRONT_ADR(PubKeyStr), (int32_t)PubKeyStr.size(), SB_STD_VECTOR_FRONT_ADR(Signature), (int32_t)Signature.size(), SB_STD_VECTOR_FRONT_ADR(Hash), (int32_t)Hash.size(), HashAlg, &ErrCode, (char *)ErrMessage.data(), &szErrMessage, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ErrMessage.resize(szErrMessage);
		SBCheckError(SBGetLastReturnStringA(-914459643, 7, (char *)ErrMessage.data(), &szErrMessage));
	}
	else
		SBCheckError(_err);

	ErrMessage.resize(szErrMessage);
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
SB_INLINE int32_t TElSSHPGPAuthHandler::FindKeyByAlgorithm(TElSSHCustomKeyStorage &Storage, int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(TElSSHPGPAuthHandler_FindKeyByAlgorithm(_Handle, Storage.getHandle(), Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHPGPAuthHandler::FindKeyByAlgorithm(TElSSHCustomKeyStorage *Storage, int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(TElSSHPGPAuthHandler_FindKeyByAlgorithm(_Handle, (Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, Algorithm, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

#ifdef SB_USE_CLASS_TELSSHKEY
void TElSSHPGPAuthHandler::GetKeyBlob(TElSSHKey &Key, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSHPGPAuthHandler_GetKeyBlob(_Handle, Key.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1518270032, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSSHPGPAuthHandler::GetKeyBlob(TElSSHKey *Key, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSHPGPAuthHandler_GetKeyBlob(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1518270032, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELSSHKEY
SB_INLINE TElSSHKeyHandle TElSSHPGPAuthHandler::KeyBlobToKey(const std::string &AlgName, const std::vector<uint8_t> &Blob)
{
	TElSSHKeyHandle OutResult;
	SBCheckError(TElSSHPGPAuthHandler_KeyBlobToKey(_Handle, AlgName.data(), (int32_t)AlgName.length(), SB_STD_VECTOR_FRONT_ADR(Blob), (int32_t)Blob.size(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELSSHKEY
SB_INLINE int32_t TElSSHPGPAuthHandler::HashAlgFromKey(TElSSHKey &Key)
{
	int32_t OutResult;
	SBCheckError(TElSSHPGPAuthHandler_HashAlgFromKey(_Handle, Key.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHPGPAuthHandler::HashAlgFromKey(TElSSHKey *Key)
{
	int32_t OutResult;
	SBCheckError(TElSSHPGPAuthHandler_HashAlgFromKey(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELSSHKEY
void TElSSHPGPAuthHandler::CalculateServerSignature(TElSSHKey &Key, const std::vector<uint8_t> &aHash, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSHPGPAuthHandler_CalculateServerSignature(_Handle, Key.getHandle(), SB_STD_VECTOR_FRONT_ADR(aHash), (int32_t)aHash.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1820050846, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSSHPGPAuthHandler::CalculateServerSignature(TElSSHKey *Key, const std::vector<uint8_t> &aHash, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSHPGPAuthHandler_CalculateServerSignature(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(aHash), (int32_t)aHash.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1820050846, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELSSHKEY */

bool TElSSHPGPAuthHandler::ServerValidateClientSignature(const std::vector<uint8_t> &AlgName, const std::vector<uint8_t> &KeyBlob, const std::vector<uint8_t> &Signature, const std::vector<uint8_t> &Hash, bool &Valid)
{
	int8_t ValidRaw = (int8_t)Valid;
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHPGPAuthHandler_ServerValidateClientSignature(_Handle, SB_STD_VECTOR_FRONT_ADR(AlgName), (int32_t)AlgName.size(), SB_STD_VECTOR_FRONT_ADR(KeyBlob), (int32_t)KeyBlob.size(), SB_STD_VECTOR_FRONT_ADR(Signature), (int32_t)Signature.size(), SB_STD_VECTOR_FRONT_ADR(Hash), (int32_t)Hash.size(), &ValidRaw, &OutResultRaw));
	Valid = (ValidRaw != 0);
	return (OutResultRaw != 0);
}

TElSSHPGPAuthHandler::TElSSHPGPAuthHandler(TElSSHPGPAuthHandlerHandle handle, TElOwnHandle ownHandle) : TElSSHAuthHandler(handle, ownHandle)
{
}

TElSSHPGPAuthHandler::TElSSHPGPAuthHandler(TComponent &AOwner) : TElSSHAuthHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHPGPAuthHandler_Create(AOwner.getHandle(), &_Handle));
}

TElSSHPGPAuthHandler::TElSSHPGPAuthHandler(TComponent *AOwner) : TElSSHAuthHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHPGPAuthHandler_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELSSHPGPAUTHHANDLER */

};	/* namespace SecureBlackbox */

