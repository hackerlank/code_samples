#include "sbpgpmime.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLERPGPMIME

void TElMessagePartHandlerPGPMime::GetDescription(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessagePartHandlerPGPMime_GetDescription((sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1909824976, 0, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElMessagePartHandlerPGPMime::GetDescription(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessagePartHandlerPGPMime_GetDescription(NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1909824976, 0, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElMessagePartHandlerPGPMime::GetDescription_Inst(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessagePartHandlerPGPMime_GetDescription_1(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1909824976, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElMessagePartHandlerPGPMime::GetDescription_Inst(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessagePartHandlerPGPMime_GetDescription_1(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1909824976, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

bool TElMessagePartHandlerPGPMime::IsSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerPGPMime_IsSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMessagePartHandlerPGPMime::IsEncrypted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerPGPMime_IsEncrypted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TClassHandle TElMessagePartHandlerPGPMime::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElMessagePartHandlerPGPMime_ClassType(&OutResult));
	return OutResult;
}

TSBPGPMIMEErrors TElMessagePartHandlerPGPMime::get_Errors()
{
	TSBPGPMIMEErrorsRaw OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerPGPMime_get_Errors(_Handle, &OutResultRaw));
	return (TSBPGPMIMEErrors)OutResultRaw;
}

bool TElMessagePartHandlerPGPMime::get_Encrypt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerPGPMime_get_Encrypt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_Encrypt(bool Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_Encrypt(_Handle, (int8_t)Value));
}

bool TElMessagePartHandlerPGPMime::get_Sign()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerPGPMime_get_Sign(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_Sign(bool Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_Sign(_Handle, (int8_t)Value));
}

bool TElMessagePartHandlerPGPMime::get_Compress()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerPGPMime_get_Compress(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_Compress(bool Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_Compress(_Handle, (int8_t)Value));
}

bool TElMessagePartHandlerPGPMime::get_IgnoreHeaderRecipients()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerPGPMime_get_IgnoreHeaderRecipients(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_IgnoreHeaderRecipients(bool Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_IgnoreHeaderRecipients(_Handle, (int8_t)Value));
}

bool TElMessagePartHandlerPGPMime::get_IgnoreHeaderSigners()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerPGPMime_get_IgnoreHeaderSigners(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_IgnoreHeaderSigners(bool Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_IgnoreHeaderSigners(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELPGPKEYRING
TElPGPKeyring* TElMessagePartHandlerPGPMime::get_DecryptingKeys()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePartHandlerPGPMime_get_DecryptingKeys(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DecryptingKeys)
		this->_Inst_DecryptingKeys = new TElPGPKeyring(hOutResult, ohFalse);
	else
		this->_Inst_DecryptingKeys->updateHandle(hOutResult);
	return this->_Inst_DecryptingKeys;
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_DecryptingKeys(TElPGPKeyring &Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_DecryptingKeys(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_DecryptingKeys(TElPGPKeyring *Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_DecryptingKeys(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPKEYRING */

#ifdef SB_USE_CLASS_TELPGPKEYRING
TElPGPKeyring* TElMessagePartHandlerPGPMime::get_VerifyingKeys()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePartHandlerPGPMime_get_VerifyingKeys(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_VerifyingKeys)
		this->_Inst_VerifyingKeys = new TElPGPKeyring(hOutResult, ohFalse);
	else
		this->_Inst_VerifyingKeys->updateHandle(hOutResult);
	return this->_Inst_VerifyingKeys;
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_VerifyingKeys(TElPGPKeyring &Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_VerifyingKeys(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_VerifyingKeys(TElPGPKeyring *Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_VerifyingKeys(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPKEYRING */

#ifdef SB_USE_CLASS_TELPGPKEYRING
TElPGPKeyring* TElMessagePartHandlerPGPMime::get_EncryptingKeys()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePartHandlerPGPMime_get_EncryptingKeys(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptingKeys)
		this->_Inst_EncryptingKeys = new TElPGPKeyring(hOutResult, ohFalse);
	else
		this->_Inst_EncryptingKeys->updateHandle(hOutResult);
	return this->_Inst_EncryptingKeys;
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_EncryptingKeys(TElPGPKeyring &Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_EncryptingKeys(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_EncryptingKeys(TElPGPKeyring *Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_EncryptingKeys(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPKEYRING */

#ifdef SB_USE_CLASS_TELPGPKEYRING
TElPGPKeyring* TElMessagePartHandlerPGPMime::get_SigningKeys()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePartHandlerPGPMime_get_SigningKeys(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SigningKeys)
		this->_Inst_SigningKeys = new TElPGPKeyring(hOutResult, ohFalse);
	else
		this->_Inst_SigningKeys->updateHandle(hOutResult);
	return this->_Inst_SigningKeys;
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_SigningKeys(TElPGPKeyring &Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_SigningKeys(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_SigningKeys(TElPGPKeyring *Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_SigningKeys(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPKEYRING */

TSBPGPEncryptionType TElMessagePartHandlerPGPMime::get_EncryptionType()
{
	TSBPGPEncryptionTypeRaw OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerPGPMime_get_EncryptionType(_Handle, &OutResultRaw));
	return (TSBPGPEncryptionType)OutResultRaw;
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_EncryptionType(TSBPGPEncryptionType Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_EncryptionType(_Handle, (TSBPGPEncryptionTypeRaw)Value));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElMessagePartHandlerPGPMime::get_Passphrases()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePartHandlerPGPMime_get_Passphrases(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Passphrases)
		this->_Inst_Passphrases = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Passphrases->updateHandle(hOutResult);
	return this->_Inst_Passphrases;
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_Passphrases(TStringList &Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_Passphrases(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_Passphrases(TStringList *Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_Passphrases(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElMessagePartHandlerPGPMime::get_Passphrases()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePartHandlerPGPMime_get_Passphrases(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Passphrases)
		this->_Inst_Passphrases = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Passphrases->updateHandle(hOutResult);
	return this->_Inst_Passphrases;
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_Passphrases(TElStringList &Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_Passphrases(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_Passphrases(TElStringList *Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_Passphrases(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

TSBPGPProtectionType TElMessagePartHandlerPGPMime::get_Protection()
{
	TSBPGPProtectionTypeRaw OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerPGPMime_get_Protection(_Handle, &OutResultRaw));
	return (TSBPGPProtectionType)OutResultRaw;
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_Protection(TSBPGPProtectionType Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_Protection(_Handle, (TSBPGPProtectionTypeRaw)Value));
}

SB_INLINE int32_t TElMessagePartHandlerPGPMime::get_CompressionAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElMessagePartHandlerPGPMime_get_CompressionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_CompressionAlgorithm(int32_t Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_CompressionAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElMessagePartHandlerPGPMime::get_CompressionLevel()
{
	int32_t OutResult;
	SBCheckError(TElMessagePartHandlerPGPMime_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_CompressionLevel(int32_t Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_CompressionLevel(_Handle, Value));
}

SB_INLINE int32_t TElMessagePartHandlerPGPMime::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElMessagePartHandlerPGPMime_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_HashAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElMessagePartHandlerPGPMime::get_SymmetricKeyAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElMessagePartHandlerPGPMime_get_SymmetricKeyAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_SymmetricKeyAlgorithm(int32_t Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_SymmetricKeyAlgorithm(_Handle, Value));
}

bool TElMessagePartHandlerPGPMime::get_UseNewFeatures()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerPGPMime_get_UseNewFeatures(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_UseNewFeatures(bool Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_UseNewFeatures(_Handle, (int8_t)Value));
}

bool TElMessagePartHandlerPGPMime::get_UseOldPackets()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerPGPMime_get_UseOldPackets(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_UseOldPackets(bool Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_UseOldPackets(_Handle, (int8_t)Value));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElMessagePartHandlerPGPMime::get_ArmorHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePartHandlerPGPMime_get_ArmorHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ArmorHeaders)
		this->_Inst_ArmorHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_ArmorHeaders->updateHandle(hOutResult);
	return this->_Inst_ArmorHeaders;
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_ArmorHeaders(TStringList &Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_ArmorHeaders(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_ArmorHeaders(TStringList *Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_ArmorHeaders(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElMessagePartHandlerPGPMime::get_ArmorHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePartHandlerPGPMime_get_ArmorHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ArmorHeaders)
		this->_Inst_ArmorHeaders = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_ArmorHeaders->updateHandle(hOutResult);
	return this->_Inst_ArmorHeaders;
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_ArmorHeaders(TElStringList &Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_ArmorHeaders(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_ArmorHeaders(TElStringList *Value)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_ArmorHeaders(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

SB_INLINE void TElMessagePartHandlerPGPMime::get_OnEncrypted(TSBPGPEncryptedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElMessagePartHandlerPGPMime_get_OnEncrypted(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_OnEncrypted(TSBPGPEncryptedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_OnEncrypted(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElMessagePartHandlerPGPMime::get_OnSigned(TSBPGPSignedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElMessagePartHandlerPGPMime_get_OnSigned(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_OnSigned(TSBPGPSignedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_OnSigned(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElMessagePartHandlerPGPMime::get_OnKeyPassphrase(TSBPGPKeyPassphraseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElMessagePartHandlerPGPMime_get_OnKeyPassphrase(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_OnKeyPassphrase(TSBPGPKeyPassphraseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_OnKeyPassphrase(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElMessagePartHandlerPGPMime::get_OnPassphrase(TSBPGPPassphraseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElMessagePartHandlerPGPMime_get_OnPassphrase(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_OnPassphrase(TSBPGPPassphraseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_OnPassphrase(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElMessagePartHandlerPGPMime::get_OnSignatures(TSBPGPSignaturesEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElMessagePartHandlerPGPMime_get_OnSignatures(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_OnSignatures(TSBPGPSignaturesEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_OnSignatures(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElMessagePartHandlerPGPMime::get_OnEncryptingKeyNotFound(TSBPGPKeyNotFoundEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElMessagePartHandlerPGPMime_get_OnEncryptingKeyNotFound(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_OnEncryptingKeyNotFound(TSBPGPKeyNotFoundEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_OnEncryptingKeyNotFound(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElMessagePartHandlerPGPMime::get_OnSigningKeyNotFound(TSBPGPKeyNotFoundEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElMessagePartHandlerPGPMime_get_OnSigningKeyNotFound(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElMessagePartHandlerPGPMime::set_OnSigningKeyNotFound(TSBPGPKeyNotFoundEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElMessagePartHandlerPGPMime_set_OnSigningKeyNotFound(_Handle, pMethodValue, pDataValue));
}

void TElMessagePartHandlerPGPMime::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPKEYRING
	this->_Inst_DecryptingKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TELPGPKEYRING
	this->_Inst_VerifyingKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TELPGPKEYRING
	this->_Inst_EncryptingKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TELPGPKEYRING
	this->_Inst_SigningKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Passphrases = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Passphrases = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_ArmorHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_ArmorHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElMessagePartHandlerPGPMime::TElMessagePartHandlerPGPMime(TElMessagePartHandlerPGPMimeHandle handle, TElOwnHandle ownHandle) : TElMessagePartHandler(handle, ownHandle)
{
	initInstances();
}

TElMessagePartHandlerPGPMime::TElMessagePartHandlerPGPMime(TObject &aParams) : TElMessagePartHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessagePartHandlerPGPMime_Create(aParams.getHandle(), &_Handle));
}

TElMessagePartHandlerPGPMime::TElMessagePartHandlerPGPMime(TObject *aParams) : TElMessagePartHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessagePartHandlerPGPMime_Create((aParams != NULL) ? aParams->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElMessagePartHandlerPGPMime::~TElMessagePartHandlerPGPMime()
{
#ifdef SB_USE_CLASS_TELPGPKEYRING
	delete this->_Inst_DecryptingKeys;
	this->_Inst_DecryptingKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TELPGPKEYRING
	delete this->_Inst_VerifyingKeys;
	this->_Inst_VerifyingKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TELPGPKEYRING
	delete this->_Inst_EncryptingKeys;
	this->_Inst_EncryptingKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TELPGPKEYRING
	delete this->_Inst_SigningKeys;
	this->_Inst_SigningKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Passphrases;
	this->_Inst_Passphrases = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Passphrases;
	this->_Inst_Passphrases = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_ArmorHeaders;
	this->_Inst_ArmorHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_ArmorHeaders;
	this->_Inst_ArmorHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLERPGPMIME */

#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLERPGPKEYS

void TElMessagePartHandlerPGPKeys::GetDescription(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessagePartHandlerPGPKeys_GetDescription((sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1362447709, 0, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElMessagePartHandlerPGPKeys::GetDescription(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessagePartHandlerPGPKeys_GetDescription(NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1362447709, 0, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElMessagePartHandlerPGPKeys::GetDescription_Inst(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessagePartHandlerPGPKeys_GetDescription_1(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1362447709, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElMessagePartHandlerPGPKeys::GetDescription_Inst(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessagePartHandlerPGPKeys_GetDescription_1(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1362447709, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

SB_INLINE TClassHandle TElMessagePartHandlerPGPKeys::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElMessagePartHandlerPGPKeys_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPGPKEYRING
TElPGPKeyring* TElMessagePartHandlerPGPKeys::get_Keys()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePartHandlerPGPKeys_get_Keys(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Keys)
		this->_Inst_Keys = new TElPGPKeyring(hOutResult, ohFalse);
	else
		this->_Inst_Keys->updateHandle(hOutResult);
	return this->_Inst_Keys;
}
#endif /* SB_USE_CLASS_TELPGPKEYRING */

void TElMessagePartHandlerPGPKeys::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPKEYRING
	this->_Inst_Keys = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
}

TElMessagePartHandlerPGPKeys::TElMessagePartHandlerPGPKeys(TElMessagePartHandlerPGPKeysHandle handle, TElOwnHandle ownHandle) : TElMessagePartHandler(handle, ownHandle)
{
	initInstances();
}

TElMessagePartHandlerPGPKeys::TElMessagePartHandlerPGPKeys(TObject &aParams) : TElMessagePartHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessagePartHandlerPGPKeys_Create(aParams.getHandle(), &_Handle));
}

TElMessagePartHandlerPGPKeys::TElMessagePartHandlerPGPKeys(TObject *aParams) : TElMessagePartHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessagePartHandlerPGPKeys_Create((aParams != NULL) ? aParams->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElMessagePartHandlerPGPKeys::~TElMessagePartHandlerPGPKeys()
{
#ifdef SB_USE_CLASS_TELPGPKEYRING
	delete this->_Inst_Keys;
	this->_Inst_Keys = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
}
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLERPGPKEYS */

#ifdef SB_USE_CLASS_TELSIMPLEPGPMIMEOPTIONS

SB_INLINE void TElSimplePGPMIMEOptions::Assign(TPersistent &Source)
{
	SBCheckError(TElSimplePGPMIMEOptions_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSimplePGPMIMEOptions::Assign(TPersistent *Source)
{
	SBCheckError(TElSimplePGPMIMEOptions_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

TSBPGPEncryptionType TElSimplePGPMIMEOptions::get_EncryptionType()
{
	TSBPGPEncryptionTypeRaw OutResultRaw = 0;
	SBCheckError(TElSimplePGPMIMEOptions_get_EncryptionType(_Handle, &OutResultRaw));
	return (TSBPGPEncryptionType)OutResultRaw;
}

SB_INLINE void TElSimplePGPMIMEOptions::set_EncryptionType(TSBPGPEncryptionType Value)
{
	SBCheckError(TElSimplePGPMIMEOptions_set_EncryptionType(_Handle, (TSBPGPEncryptionTypeRaw)Value));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSimplePGPMIMEOptions::get_Passphrases()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimplePGPMIMEOptions_get_Passphrases(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Passphrases)
		this->_Inst_Passphrases = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Passphrases->updateHandle(hOutResult);
	return this->_Inst_Passphrases;
}

SB_INLINE void TElSimplePGPMIMEOptions::set_Passphrases(TStringList &Value)
{
	SBCheckError(TElSimplePGPMIMEOptions_set_Passphrases(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimplePGPMIMEOptions::set_Passphrases(TStringList *Value)
{
	SBCheckError(TElSimplePGPMIMEOptions_set_Passphrases(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSimplePGPMIMEOptions::get_Passphrases()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimplePGPMIMEOptions_get_Passphrases(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Passphrases)
		this->_Inst_Passphrases = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Passphrases->updateHandle(hOutResult);
	return this->_Inst_Passphrases;
}

SB_INLINE void TElSimplePGPMIMEOptions::set_Passphrases(TElStringList &Value)
{
	SBCheckError(TElSimplePGPMIMEOptions_set_Passphrases(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimplePGPMIMEOptions::set_Passphrases(TElStringList *Value)
{
	SBCheckError(TElSimplePGPMIMEOptions_set_Passphrases(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

TSBPGPProtectionType TElSimplePGPMIMEOptions::get_Protection()
{
	TSBPGPProtectionTypeRaw OutResultRaw = 0;
	SBCheckError(TElSimplePGPMIMEOptions_get_Protection(_Handle, &OutResultRaw));
	return (TSBPGPProtectionType)OutResultRaw;
}

SB_INLINE void TElSimplePGPMIMEOptions::set_Protection(TSBPGPProtectionType Value)
{
	SBCheckError(TElSimplePGPMIMEOptions_set_Protection(_Handle, (TSBPGPProtectionTypeRaw)Value));
}

SB_INLINE int32_t TElSimplePGPMIMEOptions::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElSimplePGPMIMEOptions_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimplePGPMIMEOptions::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElSimplePGPMIMEOptions_set_HashAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElSimplePGPMIMEOptions::get_CompressionAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElSimplePGPMIMEOptions_get_CompressionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimplePGPMIMEOptions::set_CompressionAlgorithm(int32_t Value)
{
	SBCheckError(TElSimplePGPMIMEOptions_set_CompressionAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElSimplePGPMIMEOptions::get_CompressionLevel()
{
	int32_t OutResult;
	SBCheckError(TElSimplePGPMIMEOptions_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimplePGPMIMEOptions::set_CompressionLevel(int32_t Value)
{
	SBCheckError(TElSimplePGPMIMEOptions_set_CompressionLevel(_Handle, Value));
}

SB_INLINE int32_t TElSimplePGPMIMEOptions::get_SymmetricKeyAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElSimplePGPMIMEOptions_get_SymmetricKeyAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimplePGPMIMEOptions::set_SymmetricKeyAlgorithm(int32_t Value)
{
	SBCheckError(TElSimplePGPMIMEOptions_set_SymmetricKeyAlgorithm(_Handle, Value));
}

bool TElSimplePGPMIMEOptions::get_UseOldPackets()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimplePGPMIMEOptions_get_UseOldPackets(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimplePGPMIMEOptions::set_UseOldPackets(bool Value)
{
	SBCheckError(TElSimplePGPMIMEOptions_set_UseOldPackets(_Handle, (int8_t)Value));
}

bool TElSimplePGPMIMEOptions::get_UseNewFeatures()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimplePGPMIMEOptions_get_UseNewFeatures(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimplePGPMIMEOptions::set_UseNewFeatures(bool Value)
{
	SBCheckError(TElSimplePGPMIMEOptions_set_UseNewFeatures(_Handle, (int8_t)Value));
}

bool TElSimplePGPMIMEOptions::get_CompressMessage()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimplePGPMIMEOptions_get_CompressMessage(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimplePGPMIMEOptions::set_CompressMessage(bool Value)
{
	SBCheckError(TElSimplePGPMIMEOptions_set_CompressMessage(_Handle, (int8_t)Value));
}

bool TElSimplePGPMIMEOptions::get_EncryptMessage()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimplePGPMIMEOptions_get_EncryptMessage(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimplePGPMIMEOptions::set_EncryptMessage(bool Value)
{
	SBCheckError(TElSimplePGPMIMEOptions_set_EncryptMessage(_Handle, (int8_t)Value));
}

bool TElSimplePGPMIMEOptions::get_IgnoreHeaderRecipients()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimplePGPMIMEOptions_get_IgnoreHeaderRecipients(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimplePGPMIMEOptions::set_IgnoreHeaderRecipients(bool Value)
{
	SBCheckError(TElSimplePGPMIMEOptions_set_IgnoreHeaderRecipients(_Handle, (int8_t)Value));
}

bool TElSimplePGPMIMEOptions::get_IgnoreHeaderSigners()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimplePGPMIMEOptions_get_IgnoreHeaderSigners(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimplePGPMIMEOptions::set_IgnoreHeaderSigners(bool Value)
{
	SBCheckError(TElSimplePGPMIMEOptions_set_IgnoreHeaderSigners(_Handle, (int8_t)Value));
}

bool TElSimplePGPMIMEOptions::get_SignMessage()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimplePGPMIMEOptions_get_SignMessage(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimplePGPMIMEOptions::set_SignMessage(bool Value)
{
	SBCheckError(TElSimplePGPMIMEOptions_set_SignMessage(_Handle, (int8_t)Value));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSimplePGPMIMEOptions::get_ArmorHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimplePGPMIMEOptions_get_ArmorHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ArmorHeaders)
		this->_Inst_ArmorHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_ArmorHeaders->updateHandle(hOutResult);
	return this->_Inst_ArmorHeaders;
}

SB_INLINE void TElSimplePGPMIMEOptions::set_ArmorHeaders(TStringList &Value)
{
	SBCheckError(TElSimplePGPMIMEOptions_set_ArmorHeaders(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimplePGPMIMEOptions::set_ArmorHeaders(TStringList *Value)
{
	SBCheckError(TElSimplePGPMIMEOptions_set_ArmorHeaders(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSimplePGPMIMEOptions::get_ArmorHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimplePGPMIMEOptions_get_ArmorHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ArmorHeaders)
		this->_Inst_ArmorHeaders = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_ArmorHeaders->updateHandle(hOutResult);
	return this->_Inst_ArmorHeaders;
}

SB_INLINE void TElSimplePGPMIMEOptions::set_ArmorHeaders(TElStringList &Value)
{
	SBCheckError(TElSimplePGPMIMEOptions_set_ArmorHeaders(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimplePGPMIMEOptions::set_ArmorHeaders(TElStringList *Value)
{
	SBCheckError(TElSimplePGPMIMEOptions_set_ArmorHeaders(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElSimplePGPMIMEOptions::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Passphrases = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Passphrases = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_ArmorHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_ArmorHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElSimplePGPMIMEOptions::TElSimplePGPMIMEOptions(TElSimplePGPMIMEOptionsHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElSimplePGPMIMEOptions::TElSimplePGPMIMEOptions() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimplePGPMIMEOptions_Create(&_Handle));
}

TElSimplePGPMIMEOptions::~TElSimplePGPMIMEOptions()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Passphrases;
	this->_Inst_Passphrases = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Passphrases;
	this->_Inst_Passphrases = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_ArmorHeaders;
	this->_Inst_ArmorHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_ArmorHeaders;
	this->_Inst_ArmorHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELSIMPLEPGPMIMEOPTIONS */

#ifdef SB_USE_CLASS_TELSIMPLEPGPMIMEMESSAGE

#ifdef SB_USE_CLASS_TELPGPKEYRING
TElPGPKeyring* TElSimplePGPMIMEMessage::get_EncryptingKeys()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimplePGPMIMEMessage_get_EncryptingKeys(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptingKeys)
		this->_Inst_EncryptingKeys = new TElPGPKeyring(hOutResult, ohFalse);
	else
		this->_Inst_EncryptingKeys->updateHandle(hOutResult);
	return this->_Inst_EncryptingKeys;
}

SB_INLINE void TElSimplePGPMIMEMessage::set_EncryptingKeys(TElPGPKeyring &Value)
{
	SBCheckError(TElSimplePGPMIMEMessage_set_EncryptingKeys(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimplePGPMIMEMessage::set_EncryptingKeys(TElPGPKeyring *Value)
{
	SBCheckError(TElSimplePGPMIMEMessage_set_EncryptingKeys(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPKEYRING */

#ifdef SB_USE_CLASS_TELSIMPLEPGPMIMEOPTIONS
TElSimplePGPMIMEOptions* TElSimplePGPMIMEMessage::get_PGPMIMEOptions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimplePGPMIMEMessage_get_PGPMIMEOptions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PGPMIMEOptions)
		this->_Inst_PGPMIMEOptions = new TElSimplePGPMIMEOptions(hOutResult, ohFalse);
	else
		this->_Inst_PGPMIMEOptions->updateHandle(hOutResult);
	return this->_Inst_PGPMIMEOptions;
}

SB_INLINE void TElSimplePGPMIMEMessage::set_PGPMIMEOptions(TElSimplePGPMIMEOptions &Value)
{
	SBCheckError(TElSimplePGPMIMEMessage_set_PGPMIMEOptions(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimplePGPMIMEMessage::set_PGPMIMEOptions(TElSimplePGPMIMEOptions *Value)
{
	SBCheckError(TElSimplePGPMIMEMessage_set_PGPMIMEOptions(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSIMPLEPGPMIMEOPTIONS */

#ifdef SB_USE_CLASS_TELPGPKEYRING
TElPGPKeyring* TElSimplePGPMIMEMessage::get_SigningKeys()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimplePGPMIMEMessage_get_SigningKeys(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SigningKeys)
		this->_Inst_SigningKeys = new TElPGPKeyring(hOutResult, ohFalse);
	else
		this->_Inst_SigningKeys->updateHandle(hOutResult);
	return this->_Inst_SigningKeys;
}

SB_INLINE void TElSimplePGPMIMEMessage::set_SigningKeys(TElPGPKeyring &Value)
{
	SBCheckError(TElSimplePGPMIMEMessage_set_SigningKeys(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimplePGPMIMEMessage::set_SigningKeys(TElPGPKeyring *Value)
{
	SBCheckError(TElSimplePGPMIMEMessage_set_SigningKeys(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPKEYRING */

SB_INLINE void TElSimplePGPMIMEMessage::get_OnEncryptingKeyNotFound(TSBPGPKeyNotFoundEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimplePGPMIMEMessage_get_OnEncryptingKeyNotFound(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimplePGPMIMEMessage::set_OnEncryptingKeyNotFound(TSBPGPKeyNotFoundEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimplePGPMIMEMessage_set_OnEncryptingKeyNotFound(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimplePGPMIMEMessage::get_OnKeyPassphrase(TSBPGPKeyPassphraseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimplePGPMIMEMessage_get_OnKeyPassphrase(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimplePGPMIMEMessage::set_OnKeyPassphrase(TSBPGPKeyPassphraseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimplePGPMIMEMessage_set_OnKeyPassphrase(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimplePGPMIMEMessage::get_OnSigningKeyNotFound(TSBPGPKeyNotFoundEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimplePGPMIMEMessage_get_OnSigningKeyNotFound(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimplePGPMIMEMessage::set_OnSigningKeyNotFound(TSBPGPKeyNotFoundEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimplePGPMIMEMessage_set_OnSigningKeyNotFound(_Handle, pMethodValue, pDataValue));
}

void TElSimplePGPMIMEMessage::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPKEYRING
	this->_Inst_EncryptingKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TELSIMPLEPGPMIMEOPTIONS
	this->_Inst_PGPMIMEOptions = NULL;
#endif /* SB_USE_CLASS_TELSIMPLEPGPMIMEOPTIONS */
#ifdef SB_USE_CLASS_TELPGPKEYRING
	this->_Inst_SigningKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
}

TElSimplePGPMIMEMessage::TElSimplePGPMIMEMessage(TElSimplePGPMIMEMessageHandle handle, TElOwnHandle ownHandle) : TElSimpleMIMEMessage(handle, ownHandle)
{
	initInstances();
}

TElSimplePGPMIMEMessage::TElSimplePGPMIMEMessage(TComponent &AOwner) : TElSimpleMIMEMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimplePGPMIMEMessage_Create(AOwner.getHandle(), &_Handle));
}

TElSimplePGPMIMEMessage::TElSimplePGPMIMEMessage(TComponent *AOwner) : TElSimpleMIMEMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimplePGPMIMEMessage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSimplePGPMIMEMessage::~TElSimplePGPMIMEMessage()
{
#ifdef SB_USE_CLASS_TELPGPKEYRING
	delete this->_Inst_EncryptingKeys;
	this->_Inst_EncryptingKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TELSIMPLEPGPMIMEOPTIONS
	delete this->_Inst_PGPMIMEOptions;
	this->_Inst_PGPMIMEOptions = NULL;
#endif /* SB_USE_CLASS_TELSIMPLEPGPMIMEOPTIONS */
#ifdef SB_USE_CLASS_TELPGPKEYRING
	delete this->_Inst_SigningKeys;
	this->_Inst_SigningKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
}
#endif /* SB_USE_CLASS_TELSIMPLEPGPMIMEMESSAGE */

};	/* namespace SecureBlackbox */
