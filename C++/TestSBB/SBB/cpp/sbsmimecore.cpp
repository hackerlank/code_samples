#include "sbsmimecore.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLERSMIME

void TElMessagePartHandlerSMime::GetDescription(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessagePartHandlerSMime_GetDescription((sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-2043064448, 0, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElMessagePartHandlerSMime::GetDescription(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessagePartHandlerSMime_GetDescription(NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-2043064448, 0, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElMessagePartHandlerSMime::GetDescription_Inst(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessagePartHandlerSMime_GetDescription_1(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-2043064448, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElMessagePartHandlerSMime::GetDescription_Inst(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessagePartHandlerSMime_GetDescription_1(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-2043064448, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

bool TElMessagePartHandlerSMime::DecoderIsSignedOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerSMime_DecoderIsSignedOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMessagePartHandlerSMime::DecoderIsSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerSMime_DecoderIsSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMessagePartHandlerSMime::DecoderIsCrypted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerSMime_DecoderIsCrypted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TClassHandle TElMessagePartHandlerSMime::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElMessagePartHandlerSMime_ClassType(&OutResult));
	return OutResult;
}

bool TElMessagePartHandlerSMime::get_UseSystemCertificates()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerSMime_get_UseSystemCertificates(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessagePartHandlerSMime::set_UseSystemCertificates(bool Value)
{
	SBCheckError(TElMessagePartHandlerSMime_set_UseSystemCertificates(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElMessagePartHandlerSMime::get_CertificatesStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePartHandlerSMime_get_CertificatesStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertificatesStorage)
		this->_Inst_CertificatesStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertificatesStorage->updateHandle(hOutResult);
	return this->_Inst_CertificatesStorage;
}

SB_INLINE void TElMessagePartHandlerSMime::set_CertificatesStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElMessagePartHandlerSMime_set_CertificatesStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessagePartHandlerSMime::set_CertificatesStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElMessagePartHandlerSMime_set_CertificatesStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElMessagePartHandlerSMime::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePartHandlerSMime_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElMessagePartHandlerSMime::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElMessagePartHandlerSMime_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessagePartHandlerSMime::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElMessagePartHandlerSMime_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

TElSMimeErrors TElMessagePartHandlerSMime::get_Errors()
{
	TElSMimeErrorsRaw OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerSMime_get_Errors(_Handle, &OutResultRaw));
	return (TElSMimeErrors)OutResultRaw;
}

bool TElMessagePartHandlerSMime::get_DecoderSignIsCorrectly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerSMime_get_DecoderSignIsCorrectly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElMessagePartHandlerSMime::get_DecoderSignCertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePartHandlerSMime_get_DecoderSignCertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DecoderSignCertStorage)
		this->_Inst_DecoderSignCertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_DecoderSignCertStorage->updateHandle(hOutResult);
	return this->_Inst_DecoderSignCertStorage;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElMessagePartHandlerSMime::get_DecoderCryptCertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePartHandlerSMime_get_DecoderCryptCertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DecoderCryptCertStorage)
		this->_Inst_DecoderCryptCertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_DecoderCryptCertStorage->updateHandle(hOutResult);
	return this->_Inst_DecoderCryptCertStorage;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

bool TElMessagePartHandlerSMime::get_DecoderIncludeIssuerCertificates()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerSMime_get_DecoderIncludeIssuerCertificates(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessagePartHandlerSMime::set_DecoderIncludeIssuerCertificates(bool Value)
{
	SBCheckError(TElMessagePartHandlerSMime_set_DecoderIncludeIssuerCertificates(_Handle, (int8_t)Value));
}

bool TElMessagePartHandlerSMime::get_EncoderCrypted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerSMime_get_EncoderCrypted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessagePartHandlerSMime::set_EncoderCrypted(bool Value)
{
	SBCheckError(TElMessagePartHandlerSMime_set_EncoderCrypted(_Handle, (int8_t)Value));
}

bool TElMessagePartHandlerSMime::get_EncoderSignBeforeCrypt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerSMime_get_EncoderSignBeforeCrypt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessagePartHandlerSMime::set_EncoderSignBeforeCrypt(bool Value)
{
	SBCheckError(TElMessagePartHandlerSMime_set_EncoderSignBeforeCrypt(_Handle, (int8_t)Value));
}

bool TElMessagePartHandlerSMime::get_EncoderSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerSMime_get_EncoderSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessagePartHandlerSMime::set_EncoderSigned(bool Value)
{
	SBCheckError(TElMessagePartHandlerSMime_set_EncoderSigned(_Handle, (int8_t)Value));
}

bool TElMessagePartHandlerSMime::get_EncoderSignOnlyClearFormat()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerSMime_get_EncoderSignOnlyClearFormat(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessagePartHandlerSMime::set_EncoderSignOnlyClearFormat(bool Value)
{
	SBCheckError(TElMessagePartHandlerSMime_set_EncoderSignOnlyClearFormat(_Handle, (int8_t)Value));
}

void TElMessagePartHandlerSMime::get_EncoderMicalg(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessagePartHandlerSMime_get_EncoderMicalg(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-724468063, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElMessagePartHandlerSMime::set_EncoderMicalg(const std::string &Value)
{
	SBCheckError(TElMessagePartHandlerSMime_set_EncoderMicalg(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElMessagePartHandlerSMime::get_EncoderCryptAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElMessagePartHandlerSMime_get_EncoderCryptAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElMessagePartHandlerSMime::set_EncoderCryptAlgorithm(int32_t Value)
{
	SBCheckError(TElMessagePartHandlerSMime_set_EncoderCryptAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElMessagePartHandlerSMime::get_EncoderCryptBitsInKey()
{
	int32_t OutResult;
	SBCheckError(TElMessagePartHandlerSMime_get_EncoderCryptBitsInKey(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElMessagePartHandlerSMime::set_EncoderCryptBitsInKey(int32_t Value)
{
	SBCheckError(TElMessagePartHandlerSMime_set_EncoderCryptBitsInKey(_Handle, Value));
}

bool TElMessagePartHandlerSMime::get_EncoderIncludeIssuerCertificates()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerSMime_get_EncoderIncludeIssuerCertificates(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessagePartHandlerSMime::set_EncoderIncludeIssuerCertificates(bool Value)
{
	SBCheckError(TElMessagePartHandlerSMime_set_EncoderIncludeIssuerCertificates(_Handle, (int8_t)Value));
}

bool TElMessagePartHandlerSMime::get_EncoderSignRootHeader()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerSMime_get_EncoderSignRootHeader(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessagePartHandlerSMime::set_EncoderSignRootHeader(bool Value)
{
	SBCheckError(TElMessagePartHandlerSMime_set_EncoderSignRootHeader(_Handle, (int8_t)Value));
}

SB_INLINE int64_t TElMessagePartHandlerSMime::get_EncoderSignTime()
{
	int64_t OutResult;
	SBCheckError(TElMessagePartHandlerSMime_get_EncoderSignTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElMessagePartHandlerSMime::set_EncoderSignTime(int64_t Value)
{
	SBCheckError(TElMessagePartHandlerSMime_set_EncoderSignTime(_Handle, Value));
}

SB_INLINE int64_t TElMessagePartHandlerSMime::get_DecoderSignTime()
{
	int64_t OutResult;
	SBCheckError(TElMessagePartHandlerSMime_get_DecoderSignTime(_Handle, &OutResult));
	return OutResult;
}

bool TElMessagePartHandlerSMime::get_EncoderAlignEncryptedKey()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerSMime_get_EncoderAlignEncryptedKey(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessagePartHandlerSMime::set_EncoderAlignEncryptedKey(bool Value)
{
	SBCheckError(TElMessagePartHandlerSMime_set_EncoderAlignEncryptedKey(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElMessagePartHandlerSMime::get_EncoderCryptCertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePartHandlerSMime_get_EncoderCryptCertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncoderCryptCertStorage)
		this->_Inst_EncoderCryptCertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_EncoderCryptCertStorage->updateHandle(hOutResult);
	return this->_Inst_EncoderCryptCertStorage;
}

SB_INLINE void TElMessagePartHandlerSMime::set_EncoderCryptCertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElMessagePartHandlerSMime_set_EncoderCryptCertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessagePartHandlerSMime::set_EncoderCryptCertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElMessagePartHandlerSMime_set_EncoderCryptCertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElMessagePartHandlerSMime::get_EncoderSignCertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePartHandlerSMime_get_EncoderSignCertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncoderSignCertStorage)
		this->_Inst_EncoderSignCertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_EncoderSignCertStorage->updateHandle(hOutResult);
	return this->_Inst_EncoderSignCertStorage;
}

SB_INLINE void TElMessagePartHandlerSMime::set_EncoderSignCertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElMessagePartHandlerSMime_set_EncoderSignCertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessagePartHandlerSMime::set_EncoderSignCertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElMessagePartHandlerSMime_set_EncoderSignCertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

bool TElMessagePartHandlerSMime::get_EncoderIgnoreCertAddress()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerSMime_get_EncoderIgnoreCertAddress(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessagePartHandlerSMime::set_EncoderIgnoreCertAddress(bool Value)
{
	SBCheckError(TElMessagePartHandlerSMime_set_EncoderIgnoreCertAddress(_Handle, (int8_t)Value));
}

void TElMessagePartHandlerSMime::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertificatesStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_DecoderSignCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_DecoderCryptCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_EncoderCryptCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_EncoderSignCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElMessagePartHandlerSMime::TElMessagePartHandlerSMime(TElMessagePartHandlerSMimeHandle handle, TElOwnHandle ownHandle) : TElMessagePartHandler(handle, ownHandle)
{
	initInstances();
}

TElMessagePartHandlerSMime::TElMessagePartHandlerSMime(TObject &aParams) : TElMessagePartHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessagePartHandlerSMime_Create(aParams.getHandle(), &_Handle));
}

TElMessagePartHandlerSMime::TElMessagePartHandlerSMime(TObject *aParams) : TElMessagePartHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessagePartHandlerSMime_Create((aParams != NULL) ? aParams->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElMessagePartHandlerSMime::~TElMessagePartHandlerSMime()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertificatesStorage;
	this->_Inst_CertificatesStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_DecoderSignCertStorage;
	this->_Inst_DecoderSignCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_DecoderCryptCertStorage;
	this->_Inst_DecoderCryptCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_EncoderCryptCertStorage;
	this->_Inst_EncoderCryptCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_EncoderSignCertStorage;
	this->_Inst_EncoderSignCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLERSMIME */

#ifdef SB_USE_CLASS_TELSIMPLESMIMEMESSAGE

#ifdef SB_USE_CLASS_TELSIMPLESMIMEOPTIONS
TElSimpleSMIMEOptions* TElSimpleSMIMEMessage::get_SMIMEOptions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSMIMEMessage_get_SMIMEOptions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SMIMEOptions)
		this->_Inst_SMIMEOptions = new TElSimpleSMIMEOptions(hOutResult, ohFalse);
	else
		this->_Inst_SMIMEOptions->updateHandle(hOutResult);
	return this->_Inst_SMIMEOptions;
}

SB_INLINE void TElSimpleSMIMEMessage::set_SMIMEOptions(TElSimpleSMIMEOptions &Value)
{
	SBCheckError(TElSimpleSMIMEMessage_set_SMIMEOptions(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSMIMEMessage::set_SMIMEOptions(TElSimpleSMIMEOptions *Value)
{
	SBCheckError(TElSimpleSMIMEMessage_set_SMIMEOptions(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSIMPLESMIMEOPTIONS */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElSimpleSMIMEMessage::get_EncryptCertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSMIMEMessage_get_EncryptCertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptCertStorage)
		this->_Inst_EncryptCertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_EncryptCertStorage->updateHandle(hOutResult);
	return this->_Inst_EncryptCertStorage;
}

SB_INLINE void TElSimpleSMIMEMessage::set_EncryptCertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElSimpleSMIMEMessage_set_EncryptCertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSMIMEMessage::set_EncryptCertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElSimpleSMIMEMessage_set_EncryptCertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElSimpleSMIMEMessage::get_SignCertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSMIMEMessage_get_SignCertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignCertStorage)
		this->_Inst_SignCertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_SignCertStorage->updateHandle(hOutResult);
	return this->_Inst_SignCertStorage;
}

SB_INLINE void TElSimpleSMIMEMessage::set_SignCertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElSimpleSMIMEMessage_set_SignCertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSMIMEMessage::set_SignCertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElSimpleSMIMEMessage_set_SignCertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

void TElSimpleSMIMEMessage::initInstances()
{
#ifdef SB_USE_CLASS_TELSIMPLESMIMEOPTIONS
	this->_Inst_SMIMEOptions = NULL;
#endif /* SB_USE_CLASS_TELSIMPLESMIMEOPTIONS */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_EncryptCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_SignCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElSimpleSMIMEMessage::TElSimpleSMIMEMessage(TElSimpleSMIMEMessageHandle handle, TElOwnHandle ownHandle) : TElSimpleMIMEMessage(handle, ownHandle)
{
	initInstances();
}

TElSimpleSMIMEMessage::TElSimpleSMIMEMessage(TComponent &AOwner) : TElSimpleMIMEMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleSMIMEMessage_Create(AOwner.getHandle(), &_Handle));
}

TElSimpleSMIMEMessage::TElSimpleSMIMEMessage(TComponent *AOwner) : TElSimpleMIMEMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleSMIMEMessage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSimpleSMIMEMessage::~TElSimpleSMIMEMessage()
{
#ifdef SB_USE_CLASS_TELSIMPLESMIMEOPTIONS
	delete this->_Inst_SMIMEOptions;
	this->_Inst_SMIMEOptions = NULL;
#endif /* SB_USE_CLASS_TELSIMPLESMIMEOPTIONS */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_EncryptCertStorage;
	this->_Inst_EncryptCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_SignCertStorage;
	this->_Inst_SignCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELSIMPLESMIMEMESSAGE */

#ifdef SB_USE_CLASS_TELSIMPLESMIMEOPTIONS

SB_INLINE void TElSimpleSMIMEOptions::Assign(TPersistent &Source)
{
	SBCheckError(TElSimpleSMIMEOptions_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSimpleSMIMEOptions::Assign(TPersistent *Source)
{
	SBCheckError(TElSimpleSMIMEOptions_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElSimpleSMIMEOptions::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSMIMEOptions_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElSimpleSMIMEOptions::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElSimpleSMIMEOptions_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSMIMEOptions::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElSimpleSMIMEOptions_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

bool TElSimpleSMIMEOptions::get_EncryptMessage()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSMIMEOptions_get_EncryptMessage(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSMIMEOptions::set_EncryptMessage(bool Value)
{
	SBCheckError(TElSimpleSMIMEOptions_set_EncryptMessage(_Handle, (int8_t)Value));
}

bool TElSimpleSMIMEOptions::get_SignMessage()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSMIMEOptions_get_SignMessage(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSMIMEOptions::set_SignMessage(bool Value)
{
	SBCheckError(TElSimpleSMIMEOptions_set_SignMessage(_Handle, (int8_t)Value));
}

bool TElSimpleSMIMEOptions::get_SignBeforeCrypt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSMIMEOptions_get_SignBeforeCrypt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSMIMEOptions::set_SignBeforeCrypt(bool Value)
{
	SBCheckError(TElSimpleSMIMEOptions_set_SignBeforeCrypt(_Handle, (int8_t)Value));
}

bool TElSimpleSMIMEOptions::get_SignOnlyClearFormat()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSMIMEOptions_get_SignOnlyClearFormat(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSMIMEOptions::set_SignOnlyClearFormat(bool Value)
{
	SBCheckError(TElSimpleSMIMEOptions_set_SignOnlyClearFormat(_Handle, (int8_t)Value));
}

void TElSimpleSMIMEOptions::get_MicAlg(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSMIMEOptions_get_MicAlg(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1339763739, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSMIMEOptions::set_MicAlg(const std::string &Value)
{
	SBCheckError(TElSimpleSMIMEOptions_set_MicAlg(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSimpleSMIMEOptions::get_EncryptAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSMIMEOptions_get_EncryptAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSMIMEOptions::set_EncryptAlgorithm(int32_t Value)
{
	SBCheckError(TElSimpleSMIMEOptions_set_EncryptAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElSimpleSMIMEOptions::get_EnryptBitsInKey()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSMIMEOptions_get_EnryptBitsInKey(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSMIMEOptions::set_EnryptBitsInKey(int32_t Value)
{
	SBCheckError(TElSimpleSMIMEOptions_set_EnryptBitsInKey(_Handle, Value));
}

bool TElSimpleSMIMEOptions::get_IncludeIssuerCertificates()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSMIMEOptions_get_IncludeIssuerCertificates(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSMIMEOptions::set_IncludeIssuerCertificates(bool Value)
{
	SBCheckError(TElSimpleSMIMEOptions_set_IncludeIssuerCertificates(_Handle, (int8_t)Value));
}

bool TElSimpleSMIMEOptions::get_SignRootHeader()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSMIMEOptions_get_SignRootHeader(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSMIMEOptions::set_SignRootHeader(bool Value)
{
	SBCheckError(TElSimpleSMIMEOptions_set_SignRootHeader(_Handle, (int8_t)Value));
}

SB_INLINE int64_t TElSimpleSMIMEOptions::get_SignTime()
{
	int64_t OutResult;
	SBCheckError(TElSimpleSMIMEOptions_get_SignTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSMIMEOptions::set_SignTime(int64_t Value)
{
	SBCheckError(TElSimpleSMIMEOptions_set_SignTime(_Handle, Value));
}

bool TElSimpleSMIMEOptions::get_AlignEncryptedKey()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSMIMEOptions_get_AlignEncryptedKey(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSMIMEOptions::set_AlignEncryptedKey(bool Value)
{
	SBCheckError(TElSimpleSMIMEOptions_set_AlignEncryptedKey(_Handle, (int8_t)Value));
}

bool TElSimpleSMIMEOptions::get_IgnoreCertAddress()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSMIMEOptions_get_IgnoreCertAddress(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSMIMEOptions::set_IgnoreCertAddress(bool Value)
{
	SBCheckError(TElSimpleSMIMEOptions_set_IgnoreCertAddress(_Handle, (int8_t)Value));
}

void TElSimpleSMIMEOptions::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}

TElSimpleSMIMEOptions::TElSimpleSMIMEOptions(TElSimpleSMIMEOptionsHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElSimpleSMIMEOptions::TElSimpleSMIMEOptions() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleSMIMEOptions_Create(&_Handle));
}

TElSimpleSMIMEOptions::~TElSimpleSMIMEOptions()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}
#endif /* SB_USE_CLASS_TELSIMPLESMIMEOPTIONS */

};	/* namespace SecureBlackbox */

