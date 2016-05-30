#include "sbauthenticode.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELAUTHENTICODEPROCESSOR

TElAuthenticodeProcessor::TElAuthenticodeProcessor(TElAuthenticodeProcessorHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElAuthenticodeProcessor::TElAuthenticodeProcessor(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAuthenticodeProcessor_Create(AOwner.getHandle(), &_Handle));
}

TElAuthenticodeProcessor::TElAuthenticodeProcessor(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAuthenticodeProcessor_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELAUTHENTICODEPROCESSOR */

#ifdef SB_USE_CLASS_TELAUTHENTICODESIGNER

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
bool TElAuthenticodeSigner::AddCertificate(TElX509Certificate &Certificate)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAuthenticodeSigner_AddCertificate(_Handle, Certificate.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElAuthenticodeSigner::AddCertificate(TElX509Certificate *Certificate)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAuthenticodeSigner_AddCertificate(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

bool TElAuthenticodeSigner::AddAuthenticode(TSBAuthenticodeDigestAlgorithm DigestAlgorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAuthenticodeSigner_AddAuthenticode(_Handle, (TSBAuthenticodeDigestAlgorithmRaw)DigestAlgorithm, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE int32_t TElAuthenticodeSigner::AddSignature(const sb_u16string &Description, const std::string &URL, TSBAuthenticodeDigestAlgorithm Algorithm, TElX509Certificate &Signer, bool AddSigner, bool AddTimestamp, bool TrustedTimestamp)
{
	int32_t OutResult;
	SBCheckError(TElAuthenticodeSigner_AddSignature(_Handle, Description.data(), (int32_t)Description.length(), URL.data(), (int32_t)URL.length(), (TSBAuthenticodeDigestAlgorithmRaw)Algorithm, Signer.getHandle(), (int8_t)AddSigner, (int8_t)AddTimestamp, (int8_t)TrustedTimestamp, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElAuthenticodeSigner::AddSignature(const sb_u16string &Description, const std::string &URL, TSBAuthenticodeDigestAlgorithm Algorithm, TElX509Certificate *Signer, bool AddSigner, bool AddTimestamp, bool TrustedTimestamp)
{
	int32_t OutResult;
	SBCheckError(TElAuthenticodeSigner_AddSignature(_Handle, Description.data(), (int32_t)Description.length(), URL.data(), (int32_t)URL.length(), (TSBAuthenticodeDigestAlgorithmRaw)Algorithm, (Signer != NULL) ? Signer->getHandle() : SB_NULL_HANDLE, (int8_t)AddSigner, (int8_t)AddTimestamp, (int8_t)TrustedTimestamp, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElAuthenticodeSigner::AddSignature(const std::wstring &Description, const std::string &URL, TSBAuthenticodeDigestAlgorithm Algorithm, TElX509Certificate &Signer, bool AddSigner, bool AddTimestamp, bool TrustedTimestamp)
{
	int32_t OutResult;
	std::string u16Description;
	sb_to_u16string(Description, u16Description);
	SBCheckError(TElAuthenticodeSigner_AddSignature(_Handle, reinterpret_cast<const sb_char16_t*>(u16Description.data()), (int32_t)u16Description.length() >> 1, URL.data(), (int32_t)URL.length(), (TSBAuthenticodeDigestAlgorithmRaw)Algorithm, Signer.getHandle(), (int8_t)AddSigner, (int8_t)AddTimestamp, (int8_t)TrustedTimestamp, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElAuthenticodeSigner::AddSignature(const std::wstring &Description, const std::string &URL, TSBAuthenticodeDigestAlgorithm Algorithm, TElX509Certificate *Signer, bool AddSigner, bool AddTimestamp, bool TrustedTimestamp)
{
	int32_t OutResult;
	std::string u16Description;
	sb_to_u16string(Description, u16Description);
	SBCheckError(TElAuthenticodeSigner_AddSignature(_Handle, reinterpret_cast<const sb_char16_t*>(u16Description.data()), (int32_t)u16Description.length() >> 1, URL.data(), (int32_t)URL.length(), (TSBAuthenticodeDigestAlgorithmRaw)Algorithm, (Signer != NULL) ? Signer->getHandle() : SB_NULL_HANDLE, (int8_t)AddSigner, (int8_t)AddTimestamp, (int8_t)TrustedTimestamp, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE void TElAuthenticodeSigner::Clear()
{
	SBCheckError(TElAuthenticodeSigner_Clear(_Handle));
}

SB_INLINE int32_t TElAuthenticodeSigner::CloseFile(bool Apply)
{
	int32_t OutResult;
	SBCheckError(TElAuthenticodeSigner_CloseFile(_Handle, (int8_t)Apply, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElAuthenticodeSigner::OpenFile(const std::string &FileName)
{
	int32_t OutResult;
	SBCheckError(TElAuthenticodeSigner_OpenFile(_Handle, FileName.data(), (int32_t)FileName.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElAuthenticodeSigner::OpenStream(TStream &Stream)
{
	int32_t OutResult;
	SBCheckError(TElAuthenticodeSigner_OpenStream(_Handle, Stream.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElAuthenticodeSigner::OpenStream(TStream *Stream)
{
	int32_t OutResult;
	SBCheckError(TElAuthenticodeSigner_OpenStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

TSBAuthenticodeStatementType TElAuthenticodeSigner::get_StatementType()
{
	TSBAuthenticodeStatementTypeRaw OutResultRaw = 0;
	SBCheckError(TElAuthenticodeSigner_get_StatementType(_Handle, &OutResultRaw));
	return (TSBAuthenticodeStatementType)OutResultRaw;
}

SB_INLINE void TElAuthenticodeSigner::set_StatementType(TSBAuthenticodeStatementType Value)
{
	SBCheckError(TElAuthenticodeSigner_set_StatementType(_Handle, (TSBAuthenticodeStatementTypeRaw)Value));
}

SB_INLINE void TElAuthenticodeSigner::get_OnTimestampNeeded(TSBAuthenticodeTimestampNeeded &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAuthenticodeSigner_get_OnTimestampNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAuthenticodeSigner::set_OnTimestampNeeded(TSBAuthenticodeTimestampNeeded pMethodValue, void * pDataValue)
{
	SBCheckError(TElAuthenticodeSigner_set_OnTimestampNeeded(_Handle, pMethodValue, pDataValue));
}

TElAuthenticodeSigner::TElAuthenticodeSigner(TElAuthenticodeSignerHandle handle, TElOwnHandle ownHandle) : TElAuthenticodeProcessor(handle, ownHandle)
{
}

TElAuthenticodeSigner::TElAuthenticodeSigner(TComponent &AOwner) : TElAuthenticodeProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAuthenticodeSigner_Create(AOwner.getHandle(), &_Handle));
}

TElAuthenticodeSigner::TElAuthenticodeSigner(TComponent *AOwner) : TElAuthenticodeProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAuthenticodeSigner_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELAUTHENTICODESIGNER */

#ifdef SB_USE_CLASS_TELAUTHENTICODEVERIFIER

SB_INLINE void TElAuthenticodeVerifier::CloseFile()
{
	SBCheckError(TElAuthenticodeVerifier_CloseFile(_Handle));
}

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
bool TElAuthenticodeVerifier::GetSignatureInfo(int32_t Index, sb_u16string &Description, std::string &URL, int64_t &TimeStamp, TElClientTSPInfo &TrustedTimeStamp)
{
	int32_t szDescription = (int32_t)Description.length();
	int32_t szURL = (int32_t)URL.length();
	TElClassHandle hTrustedTimeStamp = SB_NULL_HANDLE;
	int8_t OutResultRaw = 0;
	uint32_t _err = TElAuthenticodeVerifier_GetSignatureInfo(_Handle, Index, (sb_char16_t *)Description.data(), &szDescription, (char *)URL.data(), &szURL, &TimeStamp, &hTrustedTimeStamp, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Description.resize(szDescription);
		SBCheckError(SBGetLastReturnStringW(-186150365, 2, (sb_char16_t *)Description.data(), &szDescription));
		URL.resize(szURL);
		SBCheckError(SBGetLastReturnStringA(-186150365, 3, (char *)URL.data(), &szURL));
	}
	else
		SBCheckError(_err);

	Description.resize(szDescription);
	URL.resize(szURL);
	TrustedTimeStamp.updateHandle(hTrustedTimeStamp);
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElAuthenticodeVerifier::GetSignatureInfo(int32_t Index, std::wstring &Description, std::string &URL, int64_t &TimeStamp, TElClientTSPInfo &TrustedTimeStamp)
{
	std::string u16Description;
	int32_t szDescription = 0;
	int32_t szURL = (int32_t)URL.length();
	TElClassHandle hTrustedTimeStamp = SB_NULL_HANDLE;
	int8_t OutResultRaw = 0;
	uint32_t _err = TElAuthenticodeVerifier_GetSignatureInfo(_Handle, Index, NULL, &szDescription, (char *)URL.data(), &szURL, &TimeStamp, &hTrustedTimeStamp, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16Description.resize(szDescription << 1);
		SBCheckError(SBGetLastReturnStringW(-186150365, 2, reinterpret_cast<sb_char16_t*>((char*)u16Description.data()), &szDescription));
		URL.resize(szURL);
		SBCheckError(SBGetLastReturnStringA(-186150365, 3, (char *)URL.data(), &szURL));
	}
	else
		SBCheckError(_err);

	u16Description.resize(szDescription << 1);
	sb_u16_to_wstring(u16Description, Description);
	URL.resize(szURL);
	TrustedTimeStamp.updateHandle(hTrustedTimeStamp);
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

SB_INLINE int32_t TElAuthenticodeVerifier::OpenFile(const std::string &FileName, bool OpenReadOnly)
{
	int32_t OutResult;
	SBCheckError(TElAuthenticodeVerifier_OpenFile(_Handle, FileName.data(), (int32_t)FileName.length(), (int8_t)OpenReadOnly, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElAuthenticodeVerifier::OpenStream(TStream &Stream, bool OpenReadOnly)
{
	int32_t OutResult;
	SBCheckError(TElAuthenticodeVerifier_OpenStream(_Handle, Stream.getHandle(), (int8_t)OpenReadOnly, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElAuthenticodeVerifier::OpenStream(TStream *Stream, bool OpenReadOnly)
{
	int32_t OutResult;
	SBCheckError(TElAuthenticodeVerifier_OpenStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (int8_t)OpenReadOnly, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElAuthenticodeVerifier::RemoveAuthenticode()
{
	int32_t OutResult;
	SBCheckError(TElAuthenticodeVerifier_RemoveAuthenticode(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElAuthenticodeVerifier::VerifySignature(int32_t Index)
{
	int32_t OutResult;
	SBCheckError(TElAuthenticodeVerifier_VerifySignature(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t TElAuthenticodeVerifier::get_ActualChecksum()
{
	uint32_t OutResult;
	SBCheckError(TElAuthenticodeVerifier_get_ActualChecksum(_Handle, &OutResult));
	return OutResult;
}

void TElAuthenticodeVerifier::get_ActualDigest(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElAuthenticodeVerifier_get_ActualDigest(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1296312408, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElAuthenticodeVerifier::get_Certificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAuthenticodeVerifier_get_Certificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

SB_INLINE uint32_t TElAuthenticodeVerifier::get_Checksum()
{
	uint32_t OutResult;
	SBCheckError(TElAuthenticodeVerifier_get_Checksum(_Handle, &OutResult));
	return OutResult;
}

void TElAuthenticodeVerifier::get_Digest(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElAuthenticodeVerifier_get_Digest(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2082278174, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBAuthenticodeDigestAlgorithm TElAuthenticodeVerifier::get_DigestAlgorithm()
{
	TSBAuthenticodeDigestAlgorithmRaw OutResultRaw = 0;
	SBCheckError(TElAuthenticodeVerifier_get_DigestAlgorithm(_Handle, &OutResultRaw));
	return (TSBAuthenticodeDigestAlgorithm)OutResultRaw;
}

SB_INLINE int32_t TElAuthenticodeVerifier::get_SignatureCount()
{
	int32_t OutResult;
	SBCheckError(TElAuthenticodeVerifier_get_SignatureCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPKCS7SIGNER
TElPKCS7Signer* TElAuthenticodeVerifier::get_Signatures(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAuthenticodeVerifier_get_Signatures(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signatures)
		this->_Inst_Signatures = new TElPKCS7Signer(hOutResult, ohFalse);
	else
		this->_Inst_Signatures->updateHandle(hOutResult);
	return this->_Inst_Signatures;
}
#endif /* SB_USE_CLASS_TELPKCS7SIGNER */

SB_INLINE int64_t TElAuthenticodeVerifier::get_Timestamps(int32_t Index)
{
	int64_t OutResult;
	SBCheckError(TElAuthenticodeVerifier_get_Timestamps(_Handle, Index, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
TElClientTSPInfo* TElAuthenticodeVerifier::get_TrustedTimestamps(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAuthenticodeVerifier_get_TrustedTimestamps(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TrustedTimestamps)
		this->_Inst_TrustedTimestamps = new TElClientTSPInfo(hOutResult, ohFalse);
	else
		this->_Inst_TrustedTimestamps->updateHandle(hOutResult);
	return this->_Inst_TrustedTimestamps;
}
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElAuthenticodeVerifier::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAuthenticodeVerifier_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElAuthenticodeVerifier::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElAuthenticodeVerifier_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElAuthenticodeVerifier::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElAuthenticodeVerifier_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

void TElAuthenticodeVerifier::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELPKCS7SIGNER
	this->_Inst_Signatures = NULL;
#endif /* SB_USE_CLASS_TELPKCS7SIGNER */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	this->_Inst_TrustedTimestamps = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElAuthenticodeVerifier::TElAuthenticodeVerifier(TElAuthenticodeVerifierHandle handle, TElOwnHandle ownHandle) : TElAuthenticodeProcessor(handle, ownHandle)
{
	initInstances();
}

TElAuthenticodeVerifier::TElAuthenticodeVerifier(TComponent &AOwner) : TElAuthenticodeProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAuthenticodeVerifier_Create(AOwner.getHandle(), &_Handle));
}

TElAuthenticodeVerifier::TElAuthenticodeVerifier(TComponent *AOwner) : TElAuthenticodeProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAuthenticodeVerifier_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElAuthenticodeVerifier::~TElAuthenticodeVerifier()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELPKCS7SIGNER
	delete this->_Inst_Signatures;
	this->_Inst_Signatures = NULL;
#endif /* SB_USE_CLASS_TELPKCS7SIGNER */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	delete this->_Inst_TrustedTimestamps;
	this->_Inst_TrustedTimestamps = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELAUTHENTICODEVERIFIER */

};	/* namespace SecureBlackbox */

