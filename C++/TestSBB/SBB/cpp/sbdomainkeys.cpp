#include "sbdomainkeys.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELDKPUBLICKEY

SB_INLINE void TElDKPublicKey::Assign(TPersistent &Source)
{
	SBCheckError(TElDKPublicKey_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDKPublicKey::Assign(TPersistent *Source)
{
	SBCheckError(TElDKPublicKey_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDKPublicKey::Clear()
{
	SBCheckError(TElDKPublicKey_Clear(_Handle));
}

SB_INLINE TElDKPublicKeyHandle TElDKPublicKey::Clone()
{
	TElDKPublicKeyHandle OutResult;
	SBCheckError(TElDKPublicKey_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDKPublicKey::Revoke()
{
	SBCheckError(TElDKPublicKey_Revoke(_Handle));
}

bool TElDKPublicKey::Load(const std::string &Data)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDKPublicKey_Load(_Handle, Data.data(), (int32_t)Data.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDKPublicKey::Save(std::string &Data)
{
	int32_t szData = (int32_t)Data.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElDKPublicKey_Save(_Handle, (char *)Data.data(), &szData, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Data.resize(szData);
		SBCheckError(SBGetLastReturnStringA(1391538933, 1, (char *)Data.data(), &szData));
	}
	else
		SBCheckError(_err);

	Data.resize(szData);
	return (OutResultRaw != 0);
}

bool TElDKPublicKey::get_Available()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDKPublicKey_get_Available(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TSBDKPublicKeyType TElDKPublicKey::get_KeyType()
{
	TSBDKPublicKeyTypeRaw OutResultRaw = 0;
	SBCheckError(TElDKPublicKey_get_KeyType(_Handle, &OutResultRaw));
	return (TSBDKPublicKeyType)OutResultRaw;
}

bool TElDKPublicKey::get_Revoked()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDKPublicKey_get_Revoked(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TElDKPublicKey::TElDKPublicKey(TElDKPublicKeyHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElDKPublicKey::TElDKPublicKey() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDKPublicKey_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDKPUBLICKEY */

#ifdef SB_USE_CLASS_TELDKRSAPUBLICKEY

SB_INLINE void TElDKRSAPublicKey::Assign(TPersistent &Source)
{
	SBCheckError(TElDKRSAPublicKey_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDKRSAPublicKey::Assign(TPersistent *Source)
{
	SBCheckError(TElDKRSAPublicKey_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDKRSAPublicKey::Clear()
{
	SBCheckError(TElDKRSAPublicKey_Clear(_Handle));
}

SB_INLINE TElDKPublicKeyHandle TElDKRSAPublicKey::Clone()
{
	TElDKPublicKeyHandle OutResult;
	SBCheckError(TElDKRSAPublicKey_Clone(_Handle, &OutResult));
	return OutResult;
}

void TElDKRSAPublicKey::Generate(int32_t Bits, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDKRSAPublicKey_Generate(_Handle, Bits, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1402597984, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElDKRSAPublicKey::Load(const std::string &Data)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDKRSAPublicKey_Load(_Handle, Data.data(), (int32_t)Data.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDKRSAPublicKey::Save(std::string &Data)
{
	int32_t szData = (int32_t)Data.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElDKRSAPublicKey_Save(_Handle, (char *)Data.data(), &szData, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Data.resize(szData);
		SBCheckError(SBGetLastReturnStringA(1412850845, 1, (char *)Data.data(), &szData));
	}
	else
		SBCheckError(_err);

	Data.resize(szData);
	return (OutResultRaw != 0);
}

void TElDKRSAPublicKey::get_Exponent(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDKRSAPublicKey_get_Exponent(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(448895909, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDKRSAPublicKey::get_Modulus(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDKRSAPublicKey_get_Modulus(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1225291653, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElDKRSAPublicKey::TElDKRSAPublicKey(TElDKRSAPublicKeyHandle handle, TElOwnHandle ownHandle) : TElDKPublicKey(handle, ownHandle)
{
}

TElDKRSAPublicKey::TElDKRSAPublicKey() : TElDKPublicKey(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDKRSAPublicKey_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDKRSAPUBLICKEY */

#ifdef SB_USE_CLASS_TELDKDNSRECORD

SB_INLINE void TElDKDNSRecord::Assign(TPersistent &Source)
{
	SBCheckError(TElDKDNSRecord_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDKDNSRecord::Assign(TPersistent *Source)
{
	SBCheckError(TElDKDNSRecord_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDKDNSRecord::Clear()
{
	SBCheckError(TElDKDNSRecord_Clear(_Handle));
}

SB_INLINE void TElDKDNSRecord::CreatePublicKey(TSBDKPublicKeyType KeyType)
{
	SBCheckError(TElDKDNSRecord_CreatePublicKey(_Handle, (TSBDKPublicKeyTypeRaw)KeyType));
}

SB_INLINE int32_t TElDKDNSRecord::Load(const std::string &Data)
{
	int32_t OutResult;
	SBCheckError(TElDKDNSRecord_Load(_Handle, Data.data(), (int32_t)Data.length(), &OutResult));
	return OutResult;
}

int32_t TElDKDNSRecord::Save(std::string &Data)
{
	int32_t OutResult;
	int32_t szData = (int32_t)Data.length();
	uint32_t _err = TElDKDNSRecord_Save(_Handle, (char *)Data.data(), &szData, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Data.resize(szData);
		SBCheckError(SBGetLastReturnStringA(1753240923, 1, (char *)Data.data(), &szData));
	}
	else
		SBCheckError(_err);

	Data.resize(szData);
	return OutResult;
}

void TElDKDNSRecord::get_KeyGranularity(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDKDNSRecord_get_KeyGranularity(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1477654382, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDKDNSRecord::set_KeyGranularity(const std::string &Value)
{
	SBCheckError(TElDKDNSRecord_set_KeyGranularity(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDKDNSRecord::get_Notes(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDKDNSRecord_get_Notes(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1521855507, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDKDNSRecord::set_Notes(const std::string &Value)
{
	SBCheckError(TElDKDNSRecord_set_Notes(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELDKPUBLICKEY
TElDKPublicKey* TElDKDNSRecord::get_PublicKey()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDKDNSRecord_get_PublicKey(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PublicKey)
		this->_Inst_PublicKey = new TElDKPublicKey(hOutResult, ohFalse);
	else
		this->_Inst_PublicKey->updateHandle(hOutResult);
	return this->_Inst_PublicKey;
}
#endif /* SB_USE_CLASS_TELDKPUBLICKEY */

bool TElDKDNSRecord::get_TestMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDKDNSRecord_get_TestMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDKDNSRecord::set_TestMode(bool Value)
{
	SBCheckError(TElDKDNSRecord_set_TestMode(_Handle, (int8_t)Value));
}

bool TElDKDNSRecord::get_ExactMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDKDNSRecord_get_ExactMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDKDNSRecord::set_ExactMode(bool Value)
{
	SBCheckError(TElDKDNSRecord_set_ExactMode(_Handle, (int8_t)Value));
}

void TElDKDNSRecord::get_ServiceType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDKDNSRecord_get_ServiceType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(480882064, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDKDNSRecord::set_ServiceType(const std::string &Value)
{
	SBCheckError(TElDKDNSRecord_set_ServiceType(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDKDNSRecord::get_Version(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDKDNSRecord_get_Version(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1341405464, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDKDNSRecord::set_Version(const std::string &Value)
{
	SBCheckError(TElDKDNSRecord_set_Version(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDKDNSRecord::get_Algorithms(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDKDNSRecord_get_Algorithms(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-570706960, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDKDNSRecord::set_Algorithms(const std::string &Value)
{
	SBCheckError(TElDKDNSRecord_set_Algorithms(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDKDNSRecord::initInstances()
{
#ifdef SB_USE_CLASS_TELDKPUBLICKEY
	this->_Inst_PublicKey = NULL;
#endif /* SB_USE_CLASS_TELDKPUBLICKEY */
}

TElDKDNSRecord::TElDKDNSRecord(TElDKDNSRecordHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElDKDNSRecord::TElDKDNSRecord() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDKDNSRecord_Create(&_Handle));
}

TElDKDNSRecord::~TElDKDNSRecord()
{
#ifdef SB_USE_CLASS_TELDKPUBLICKEY
	delete this->_Inst_PublicKey;
	this->_Inst_PublicKey = NULL;
#endif /* SB_USE_CLASS_TELDKPUBLICKEY */
}
#endif /* SB_USE_CLASS_TELDKDNSRECORD */

#ifdef SB_USE_CLASS_TELDOMAINKEYSCLASS

TElDomainKeysClass::TElDomainKeysClass(TElDomainKeysClassHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElDomainKeysClass::TElDomainKeysClass(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDomainKeysClass_Create(AOwner.getHandle(), &_Handle));
}

TElDomainKeysClass::TElDomainKeysClass(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDomainKeysClass_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELDOMAINKEYSCLASS */

#ifdef SB_USE_CLASS_TELDOMAINKEYSSIGNER

SB_INLINE void TElDomainKeysSigner::AddHash(void * Data, int32_t DataSize, bool BodyHash)
{
	SBCheckError(TElDomainKeysSigner_AddHash(_Handle, Data, DataSize, (int8_t)BodyHash));
}

#ifdef SB_USE_CLASS_TSTRINGS
void TElDomainKeysSigner::CanonicalizeBody(TStrings &Body, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDomainKeysSigner_CanonicalizeBody(_Handle, Body.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1164578877, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDomainKeysSigner::CanonicalizeBody(TStrings *Body, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDomainKeysSigner_CanonicalizeBody(_Handle, (Body != NULL) ? Body->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1164578877, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTRINGS */

#ifdef SB_USE_CLASS_TSTRINGS
void TElDomainKeysSigner::CanonicalizeHeader(TStrings &Header, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDomainKeysSigner_CanonicalizeHeader(_Handle, Header.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-950625784, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDomainKeysSigner::CanonicalizeHeader(TStrings *Header, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDomainKeysSigner_CanonicalizeHeader(_Handle, (Header != NULL) ? Header->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-950625784, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTRINGS */

SB_INLINE void TElDomainKeysSigner::ClearPrivateKey()
{
	SBCheckError(TElDomainKeysSigner_ClearPrivateKey(_Handle));
}

int32_t TElDomainKeysSigner::GetHash(TSBDKDigestAlgorithm HashAlgorithm, bool BodyHash, std::vector<uint8_t> &Hash)
{
	int32_t OutResult;
	int32_t szHash = (int32_t)Hash.size();
	uint32_t _err = TElDomainKeysSigner_GetHash(_Handle, (TSBDKDigestAlgorithmRaw)HashAlgorithm, (int8_t)BodyHash, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Hash), &szHash, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Hash.resize(szHash);
		SBCheckError(SBGetLastReturnBuffer(-555009920, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Hash), &szHash));
	}
	else
		SBCheckError(_err);

	Hash.resize(szHash);
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTRINGS
SB_INLINE int32_t TElDomainKeysSigner::ProcessHeader(TStrings &Header)
{
	int32_t OutResult;
	SBCheckError(TElDomainKeysSigner_ProcessHeader(_Handle, Header.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDomainKeysSigner::ProcessHeader(TStrings *Header)
{
	int32_t OutResult;
	SBCheckError(TElDomainKeysSigner_ProcessHeader(_Handle, (Header != NULL) ? Header->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTRINGS */

SB_INLINE int32_t TElDomainKeysSigner::ProcessBodyLine(const std::string &S)
{
	int32_t OutResult;
	SBCheckError(TElDomainKeysSigner_ProcessBodyLine(_Handle, S.data(), (int32_t)S.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDomainKeysSigner::ProcessMessage(const std::string &MessageText)
{
	int32_t OutResult;
	SBCheckError(TElDomainKeysSigner_ProcessMessage(_Handle, MessageText.data(), (int32_t)MessageText.length(), &OutResult));
	return OutResult;
}

SB_INLINE void TElDomainKeysSigner::Reset()
{
	SBCheckError(TElDomainKeysSigner_Reset(_Handle));
}

bool TElDomainKeysSigner::SetPrivateKey(void * Modulus, int32_t ModulusSize, void * Exponent, int32_t ExponentSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDomainKeysSigner_SetPrivateKey(_Handle, Modulus, ModulusSize, Exponent, ExponentSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDomainKeysSigner::SetPrivateKey(void * Buffer, int32_t BufferSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDomainKeysSigner_SetPrivateKey_1(_Handle, Buffer, BufferSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTRINGS
SB_INLINE int32_t TElDomainKeysSigner::Sign(TStrings &Signature)
{
	int32_t OutResult;
	SBCheckError(TElDomainKeysSigner_Sign(_Handle, Signature.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDomainKeysSigner::Sign(TStrings *Signature)
{
	int32_t OutResult;
	SBCheckError(TElDomainKeysSigner_Sign(_Handle, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTRINGS */

TSBDKCanonicalizationAlgorithm TElDomainKeysSigner::get_BodyCanonicalization()
{
	TSBDKCanonicalizationAlgorithmRaw OutResultRaw = 0;
	SBCheckError(TElDomainKeysSigner_get_BodyCanonicalization(_Handle, &OutResultRaw));
	return (TSBDKCanonicalizationAlgorithm)OutResultRaw;
}

SB_INLINE void TElDomainKeysSigner::set_BodyCanonicalization(TSBDKCanonicalizationAlgorithm Value)
{
	SBCheckError(TElDomainKeysSigner_set_BodyCanonicalization(_Handle, (TSBDKCanonicalizationAlgorithmRaw)Value));
}

TSBDKCanonicalizationAlgorithm TElDomainKeysSigner::get_HeaderCanonicalization()
{
	TSBDKCanonicalizationAlgorithmRaw OutResultRaw = 0;
	SBCheckError(TElDomainKeysSigner_get_HeaderCanonicalization(_Handle, &OutResultRaw));
	return (TSBDKCanonicalizationAlgorithm)OutResultRaw;
}

SB_INLINE void TElDomainKeysSigner::set_HeaderCanonicalization(TSBDKCanonicalizationAlgorithm Value)
{
	SBCheckError(TElDomainKeysSigner_set_HeaderCanonicalization(_Handle, (TSBDKCanonicalizationAlgorithmRaw)Value));
}

TSBDKDigestAlgorithm TElDomainKeysSigner::get_DigestAlgorithm()
{
	TSBDKDigestAlgorithmRaw OutResultRaw = 0;
	SBCheckError(TElDomainKeysSigner_get_DigestAlgorithm(_Handle, &OutResultRaw));
	return (TSBDKDigestAlgorithm)OutResultRaw;
}

SB_INLINE void TElDomainKeysSigner::set_DigestAlgorithm(TSBDKDigestAlgorithm Value)
{
	SBCheckError(TElDomainKeysSigner_set_DigestAlgorithm(_Handle, (TSBDKDigestAlgorithmRaw)Value));
}

void TElDomainKeysSigner::get_Domain(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDomainKeysSigner_get_Domain(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-819569110, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDomainKeysSigner::get_BodyHashLimit(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDomainKeysSigner_get_BodyHashLimit(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-540018607, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDomainKeysSigner::set_BodyHashLimit(const std::string &Value)
{
	SBCheckError(TElDomainKeysSigner_set_BodyHashLimit(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElDomainKeysSigner::get_HeaderFields()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDomainKeysSigner_get_HeaderFields(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HeaderFields)
		this->_Inst_HeaderFields = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_HeaderFields->updateHandle(hOutResult);
	return this->_Inst_HeaderFields;
}

SB_INLINE void TElDomainKeysSigner::set_HeaderFields(TStringList &Value)
{
	SBCheckError(TElDomainKeysSigner_set_HeaderFields(_Handle, Value.getHandle()));
}

SB_INLINE void TElDomainKeysSigner::set_HeaderFields(TStringList *Value)
{
	SBCheckError(TElDomainKeysSigner_set_HeaderFields(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElDomainKeysSigner::get_HeaderFields()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDomainKeysSigner_get_HeaderFields(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HeaderFields)
		this->_Inst_HeaderFields = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_HeaderFields->updateHandle(hOutResult);
	return this->_Inst_HeaderFields;
}

SB_INLINE void TElDomainKeysSigner::set_HeaderFields(TElStringList &Value)
{
	SBCheckError(TElDomainKeysSigner_set_HeaderFields(_Handle, Value.getHandle()));
}

SB_INLINE void TElDomainKeysSigner::set_HeaderFields(TElStringList *Value)
{
	SBCheckError(TElDomainKeysSigner_set_HeaderFields(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

TSBDKQueryType TElDomainKeysSigner::get_QueryType()
{
	TSBDKQueryTypeRaw OutResultRaw = 0;
	SBCheckError(TElDomainKeysSigner_get_QueryType(_Handle, &OutResultRaw));
	return (TSBDKQueryType)OutResultRaw;
}

SB_INLINE void TElDomainKeysSigner::set_QueryType(TSBDKQueryType Value)
{
	SBCheckError(TElDomainKeysSigner_set_QueryType(_Handle, (TSBDKQueryTypeRaw)Value));
}

void TElDomainKeysSigner::get_Selector(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDomainKeysSigner_get_Selector(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(755551326, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDomainKeysSigner::set_Selector(const std::string &Value)
{
	SBCheckError(TElDomainKeysSigner_set_Selector(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBDKPublicKeyType TElDomainKeysSigner::get_SignatureAlgorithm()
{
	TSBDKPublicKeyTypeRaw OutResultRaw = 0;
	SBCheckError(TElDomainKeysSigner_get_SignatureAlgorithm(_Handle, &OutResultRaw));
	return (TSBDKPublicKeyType)OutResultRaw;
}

SB_INLINE void TElDomainKeysSigner::set_SignatureAlgorithm(TSBDKPublicKeyType Value)
{
	SBCheckError(TElDomainKeysSigner_set_SignatureAlgorithm(_Handle, (TSBDKPublicKeyTypeRaw)Value));
}

SB_INLINE int64_t TElDomainKeysSigner::get_SignatureExpiration()
{
	int64_t OutResult;
	SBCheckError(TElDomainKeysSigner_get_SignatureExpiration(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDomainKeysSigner::set_SignatureExpiration(int64_t Value)
{
	SBCheckError(TElDomainKeysSigner_set_SignatureExpiration(_Handle, Value));
}

bool TElDomainKeysSigner::get_UseCopiedFields()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDomainKeysSigner_get_UseCopiedFields(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDomainKeysSigner::set_UseCopiedFields(bool Value)
{
	SBCheckError(TElDomainKeysSigner_set_UseCopiedFields(_Handle, (int8_t)Value));
}

void TElDomainKeysSigner::get_UserIdentity(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDomainKeysSigner_get_UserIdentity(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1771661161, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDomainKeysSigner::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_HeaderFields = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_HeaderFields = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElDomainKeysSigner::TElDomainKeysSigner(TElDomainKeysSignerHandle handle, TElOwnHandle ownHandle) : TElDomainKeysClass(handle, ownHandle)
{
	initInstances();
}

TElDomainKeysSigner::TElDomainKeysSigner(TComponent &AOwner) : TElDomainKeysClass(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDomainKeysSigner_Create(AOwner.getHandle(), &_Handle));
}

TElDomainKeysSigner::TElDomainKeysSigner(TComponent *AOwner) : TElDomainKeysClass(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDomainKeysSigner_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElDomainKeysSigner::~TElDomainKeysSigner()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_HeaderFields;
	this->_Inst_HeaderFields = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_HeaderFields;
	this->_Inst_HeaderFields = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELDOMAINKEYSSIGNER */

#ifdef SB_USE_CLASS_TELDOMAINKEYSVERIFIER

#ifdef SB_USE_CLASS_TSTRINGS
SB_INLINE int32_t TElDomainKeysVerifier::ProcessHeader(TStrings &Header)
{
	int32_t OutResult;
	SBCheckError(TElDomainKeysVerifier_ProcessHeader(_Handle, Header.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDomainKeysVerifier::ProcessHeader(TStrings *Header)
{
	int32_t OutResult;
	SBCheckError(TElDomainKeysVerifier_ProcessHeader(_Handle, (Header != NULL) ? Header->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTRINGS */

SB_INLINE int32_t TElDomainKeysVerifier::ProcessHeader(const std::string &Source)
{
	int32_t OutResult;
	SBCheckError(TElDomainKeysVerifier_ProcessHeader_1(_Handle, Source.data(), (int32_t)Source.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDomainKeysVerifier::ProcessBodyLine(const std::string &S, int32_t SignatureIndex)
{
	int32_t OutResult;
	SBCheckError(TElDomainKeysVerifier_ProcessBodyLine(_Handle, S.data(), (int32_t)S.length(), SignatureIndex, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElDomainKeysVerifier::ProcessMessage(TStream &Stream)
{
	int32_t OutResult;
	SBCheckError(TElDomainKeysVerifier_ProcessMessage(_Handle, Stream.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDomainKeysVerifier::ProcessMessage(TStream *Stream)
{
	int32_t OutResult;
	SBCheckError(TElDomainKeysVerifier_ProcessMessage(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELDKDNSRECORD
TSBDKStatus TElDomainKeysVerifier::Verify(int32_t SigIndex, TElDKDNSRecord &DNSRec)
{
	TSBDKStatusRaw OutResultRaw = 0;
	SBCheckError(TElDomainKeysVerifier_Verify(_Handle, SigIndex, DNSRec.getHandle(), &OutResultRaw));
	return (TSBDKStatus)OutResultRaw;
}

TSBDKStatus TElDomainKeysVerifier::Verify(int32_t SigIndex, TElDKDNSRecord *DNSRec)
{
	TSBDKStatusRaw OutResultRaw = 0;
	SBCheckError(TElDomainKeysVerifier_Verify(_Handle, SigIndex, (DNSRec != NULL) ? DNSRec->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBDKStatus)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELDKDNSRECORD */

SB_INLINE void TElDomainKeysVerifier::Reset()
{
	SBCheckError(TElDomainKeysVerifier_Reset(_Handle));
}

#ifdef SB_USE_CLASS_TELDKSIGNATURE
TElDKSignature* TElDomainKeysVerifier::get_Signatures(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDomainKeysVerifier_get_Signatures(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signatures)
		this->_Inst_Signatures = new TElDKSignature(hOutResult, ohFalse);
	else
		this->_Inst_Signatures->updateHandle(hOutResult);
	return this->_Inst_Signatures;
}
#endif /* SB_USE_CLASS_TELDKSIGNATURE */

SB_INLINE int32_t TElDomainKeysVerifier::get_SignaturesCount()
{
	int32_t OutResult;
	SBCheckError(TElDomainKeysVerifier_get_SignaturesCount(_Handle, &OutResult));
	return OutResult;
}

void TElDomainKeysVerifier::initInstances()
{
#ifdef SB_USE_CLASS_TELDKSIGNATURE
	this->_Inst_Signatures = NULL;
#endif /* SB_USE_CLASS_TELDKSIGNATURE */
}

TElDomainKeysVerifier::TElDomainKeysVerifier(TElDomainKeysVerifierHandle handle, TElOwnHandle ownHandle) : TElDomainKeysClass(handle, ownHandle)
{
	initInstances();
}

TElDomainKeysVerifier::TElDomainKeysVerifier(TComponent &AOwner) : TElDomainKeysClass(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDomainKeysVerifier_Create(AOwner.getHandle(), &_Handle));
}

TElDomainKeysVerifier::TElDomainKeysVerifier(TComponent *AOwner) : TElDomainKeysClass(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDomainKeysVerifier_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElDomainKeysVerifier::~TElDomainKeysVerifier()
{
#ifdef SB_USE_CLASS_TELDKSIGNATURE
	delete this->_Inst_Signatures;
	this->_Inst_Signatures = NULL;
#endif /* SB_USE_CLASS_TELDKSIGNATURE */
}
#endif /* SB_USE_CLASS_TELDOMAINKEYSVERIFIER */

#ifdef SB_USE_CLASS_TELDKSIGNATURE

SB_INLINE void TElDKSignature::Clear()
{
	SBCheckError(TElDKSignature_Clear(_Handle));
}

SB_INLINE void TElDKSignature::HashClear()
{
	SBCheckError(TElDKSignature_HashClear(_Handle));
}

#ifdef SB_USE_CLASS_TELDKDNSRECORD
TSBDKStatus TElDKSignature::Verify(TElDKDNSRecord &DNS)
{
	TSBDKStatusRaw OutResultRaw = 0;
	SBCheckError(TElDKSignature_Verify(_Handle, DNS.getHandle(), &OutResultRaw));
	return (TSBDKStatus)OutResultRaw;
}

TSBDKStatus TElDKSignature::Verify(TElDKDNSRecord *DNS)
{
	TSBDKStatusRaw OutResultRaw = 0;
	SBCheckError(TElDKSignature_Verify(_Handle, (DNS != NULL) ? DNS->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBDKStatus)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELDKDNSRECORD */

bool TElDKSignature::get_Available()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDKSignature_get_Available(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TSBDKCanonicalizationAlgorithm TElDKSignature::get_HeaderCanonicalization()
{
	TSBDKCanonicalizationAlgorithmRaw OutResultRaw = 0;
	SBCheckError(TElDKSignature_get_HeaderCanonicalization(_Handle, &OutResultRaw));
	return (TSBDKCanonicalizationAlgorithm)OutResultRaw;
}

TSBDKCanonicalizationAlgorithm TElDKSignature::get_BodyCanonicalization()
{
	TSBDKCanonicalizationAlgorithmRaw OutResultRaw = 0;
	SBCheckError(TElDKSignature_get_BodyCanonicalization(_Handle, &OutResultRaw));
	return (TSBDKCanonicalizationAlgorithm)OutResultRaw;
}

TSBDKDigestAlgorithm TElDKSignature::get_DigestAlgorithm()
{
	TSBDKDigestAlgorithmRaw OutResultRaw = 0;
	SBCheckError(TElDKSignature_get_DigestAlgorithm(_Handle, &OutResultRaw));
	return (TSBDKDigestAlgorithm)OutResultRaw;
}

void TElDKSignature::get_Domain(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDKSignature_get_Domain(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-766015514, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDKSignature::set_Domain(const std::string &Value)
{
	SBCheckError(TElDKSignature_set_Domain(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDKSignature::get_Address(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDKSignature_get_Address(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(25354320, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBDKQueryType TElDKSignature::get_QueryType()
{
	TSBDKQueryTypeRaw OutResultRaw = 0;
	SBCheckError(TElDKSignature_get_QueryType(_Handle, &OutResultRaw));
	return (TSBDKQueryType)OutResultRaw;
}

void TElDKSignature::get_Selector(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDKSignature_get_Selector(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1253563619, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBDKPublicKeyType TElDKSignature::get_SignatureAlgorithm()
{
	TSBDKPublicKeyTypeRaw OutResultRaw = 0;
	SBCheckError(TElDKSignature_get_SignatureAlgorithm(_Handle, &OutResultRaw));
	return (TSBDKPublicKeyType)OutResultRaw;
}

void TElDKSignature::get_BodyHashLimit(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDKSignature_get_BodyHashLimit(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2021521804, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDKSignature::set_BodyHashLimit(const std::string &Value)
{
	SBCheckError(TElDKSignature_set_BodyHashLimit(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDKSignature::get_VerifierBodyHashLimit(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDKSignature_get_VerifierBodyHashLimit(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1478057178, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDKSignature::set_VerifierBodyHashLimit(const std::string &Value)
{
	SBCheckError(TElDKSignature_set_VerifierBodyHashLimit(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElDKSignature::get_SignatureTime()
{
	int64_t OutResult;
	SBCheckError(TElDKSignature_get_SignatureTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDKSignature::set_SignatureTime(int64_t Value)
{
	SBCheckError(TElDKSignature_set_SignatureTime(_Handle, Value));
}

SB_INLINE int64_t TElDKSignature::get_SignatureExpired()
{
	int64_t OutResult;
	SBCheckError(TElDKSignature_get_SignatureExpired(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDKSignature::set_SignatureExpired(int64_t Value)
{
	SBCheckError(TElDKSignature_set_SignatureExpired(_Handle, Value));
}

bool TElDKSignature::get_Hashed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDKSignature_get_Hashed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDKSignature::set_Hashed(bool Value)
{
	SBCheckError(TElDKSignature_set_Hashed(_Handle, (int8_t)Value));
}

TElDKSignature::TElDKSignature(TElDKSignatureHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElDKSignature::TElDKSignature() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDKSignature_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDKSIGNATURE */

};	/* namespace SecureBlackbox */
