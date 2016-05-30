#include "sbas3.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELAS3RECEIPTREQUEST

SB_INLINE void TElAS3ReceiptRequest::Assign(TPersistent &Source)
{
	SBCheckError(TElAS3ReceiptRequest_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElAS3ReceiptRequest::Assign(TPersistent *Source)
{
	SBCheckError(TElAS3ReceiptRequest_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

TSBASSignatureDigestAlgorithm TElAS3ReceiptRequest::get_DigestAlgorithm()
{
	TSBASSignatureDigestAlgorithmRaw OutResultRaw = 0;
	SBCheckError(TElAS3ReceiptRequest_get_DigestAlgorithm(_Handle, &OutResultRaw));
	return (TSBASSignatureDigestAlgorithm)OutResultRaw;
}

SB_INLINE void TElAS3ReceiptRequest::set_DigestAlgorithm(TSBASSignatureDigestAlgorithm Value)
{
	SBCheckError(TElAS3ReceiptRequest_set_DigestAlgorithm(_Handle, (TSBASSignatureDigestAlgorithmRaw)Value));
}

bool TElAS3ReceiptRequest::get_DigestAlgorithmOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3ReceiptRequest_get_DigestAlgorithmOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3ReceiptRequest::set_DigestAlgorithmOnly(bool Value)
{
	SBCheckError(TElAS3ReceiptRequest_set_DigestAlgorithmOnly(_Handle, (int8_t)Value));
}

bool TElAS3ReceiptRequest::get_DigestAlgorithmRequired()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3ReceiptRequest_get_DigestAlgorithmRequired(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3ReceiptRequest::set_DigestAlgorithmRequired(bool Value)
{
	SBCheckError(TElAS3ReceiptRequest_set_DigestAlgorithmRequired(_Handle, (int8_t)Value));
}

bool TElAS3ReceiptRequest::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3ReceiptRequest_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3ReceiptRequest::set_Enabled(bool Value)
{
	SBCheckError(TElAS3ReceiptRequest_set_Enabled(_Handle, (int8_t)Value));
}

bool TElAS3ReceiptRequest::get_SignatureProtocolRequired()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3ReceiptRequest_get_SignatureProtocolRequired(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3ReceiptRequest::set_SignatureProtocolRequired(bool Value)
{
	SBCheckError(TElAS3ReceiptRequest_set_SignatureProtocolRequired(_Handle, (int8_t)Value));
}

bool TElAS3ReceiptRequest::get_Signed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3ReceiptRequest_get_Signed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3ReceiptRequest::set_Signed(bool Value)
{
	SBCheckError(TElAS3ReceiptRequest_set_Signed(_Handle, (int8_t)Value));
}

void TElAS3ReceiptRequest::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3ReceiptRequest_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(837802681, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3ReceiptRequest::set_URL(const std::string &Value)
{
	SBCheckError(TElAS3ReceiptRequest_set_URL(_Handle, Value.data(), (int32_t)Value.length()));
}

TElAS3ReceiptRequest::TElAS3ReceiptRequest(TElAS3ReceiptRequestHandle handle, TElOwnHandle ownHandle) : TElASReceiptRequest(handle, ownHandle)
{
}

TElAS3ReceiptRequest::TElAS3ReceiptRequest() : TElASReceiptRequest(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAS3ReceiptRequest_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELAS3RECEIPTREQUEST */

#ifdef SB_USE_CLASS_TELAS3ENCRYPTION

SB_INLINE int32_t TElAS3Encryption::get_Algorithm()
{
	int32_t OutResult;
	SBCheckError(TElAS3Encryption_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3Encryption::set_Algorithm(int32_t Value)
{
	SBCheckError(TElAS3Encryption_set_Algorithm(_Handle, Value));
}

bool TElAS3Encryption::get_AlignEncryptedKey()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3Encryption_get_AlignEncryptedKey(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3Encryption::set_AlignEncryptedKey(bool Value)
{
	SBCheckError(TElAS3Encryption_set_AlignEncryptedKey(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElAS3Encryption::get_BitsInKey()
{
	int32_t OutResult;
	SBCheckError(TElAS3Encryption_get_BitsInKey(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3Encryption::set_BitsInKey(int32_t Value)
{
	SBCheckError(TElAS3Encryption_set_BitsInKey(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElAS3Encryption::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3Encryption_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElAS3Encryption::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElAS3Encryption_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS3Encryption::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElAS3Encryption_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

bool TElAS3Encryption::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3Encryption_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3Encryption::set_Enabled(bool Value)
{
	SBCheckError(TElAS3Encryption_set_Enabled(_Handle, (int8_t)Value));
}

TSBASEncryptionTransferEncoding TElAS3Encryption::get_Encoding()
{
	TSBASEncryptionTransferEncodingRaw OutResultRaw = 0;
	SBCheckError(TElAS3Encryption_get_Encoding(_Handle, &OutResultRaw));
	return (TSBASEncryptionTransferEncoding)OutResultRaw;
}

SB_INLINE void TElAS3Encryption::set_Encoding(TSBASEncryptionTransferEncoding Value)
{
	SBCheckError(TElAS3Encryption_set_Encoding(_Handle, (TSBASEncryptionTransferEncodingRaw)Value));
}

bool TElAS3Encryption::get_UseUndefSize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3Encryption_get_UseUndefSize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3Encryption::set_UseUndefSize(bool Value)
{
	SBCheckError(TElAS3Encryption_set_UseUndefSize(_Handle, (int8_t)Value));
}

void TElAS3Encryption::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElAS3Encryption::TElAS3Encryption(TElAS3EncryptionHandle handle, TElOwnHandle ownHandle) : TElASSMIMEEncryption(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TCOMPONENT
TElAS3Encryption::TElAS3Encryption(TComponent &AOwner) : TElASSMIMEEncryption(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS3Encryption_Create(AOwner.getHandle(), &_Handle));
}

TElAS3Encryption::TElAS3Encryption(TComponent *AOwner) : TElASSMIMEEncryption(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS3Encryption_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TCOMPONENT */

TElAS3Encryption::~TElAS3Encryption()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELAS3ENCRYPTION */

#ifdef SB_USE_CLASS_TELAS3SIGNATURE

SB_INLINE int32_t TElAS3Signature::get_VerificationResult()
{
	int32_t OutResult;
	SBCheckError(TElAS3Signature_get_VerificationResult(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElAS3Signature::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3Signature_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElAS3Signature::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElAS3Signature_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS3Signature::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElAS3Signature_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

bool TElAS3Signature::get_Compressed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3Signature_get_Compressed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3Signature::set_Compressed(bool Value)
{
	SBCheckError(TElAS3Signature_set_Compressed(_Handle, (int8_t)Value));
}

TSBASSignatureDigestAlgorithm TElAS3Signature::get_DigestAlgorithm()
{
	TSBASSignatureDigestAlgorithmRaw OutResultRaw = 0;
	SBCheckError(TElAS3Signature_get_DigestAlgorithm(_Handle, &OutResultRaw));
	return (TSBASSignatureDigestAlgorithm)OutResultRaw;
}

SB_INLINE void TElAS3Signature::set_DigestAlgorithm(TSBASSignatureDigestAlgorithm Value)
{
	SBCheckError(TElAS3Signature_set_DigestAlgorithm(_Handle, (TSBASSignatureDigestAlgorithmRaw)Value));
}

bool TElAS3Signature::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3Signature_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3Signature::set_Enabled(bool Value)
{
	SBCheckError(TElAS3Signature_set_Enabled(_Handle, (int8_t)Value));
}

TSBASSignatureTransferEncoding TElAS3Signature::get_Encoding()
{
	TSBASSignatureTransferEncodingRaw OutResultRaw = 0;
	SBCheckError(TElAS3Signature_get_Encoding(_Handle, &OutResultRaw));
	return (TSBASSignatureTransferEncoding)OutResultRaw;
}

SB_INLINE void TElAS3Signature::set_Encoding(TSBASSignatureTransferEncoding Value)
{
	SBCheckError(TElAS3Signature_set_Encoding(_Handle, (TSBASSignatureTransferEncodingRaw)Value));
}

bool TElAS3Signature::get_IncludeChain()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3Signature_get_IncludeChain(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3Signature::set_IncludeChain(bool Value)
{
	SBCheckError(TElAS3Signature_set_IncludeChain(_Handle, (int8_t)Value));
}

SB_INLINE int64_t TElAS3Signature::get_Time()
{
	int64_t OutResult;
	SBCheckError(TElAS3Signature_get_Time(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3Signature::set_Time(int64_t Value)
{
	SBCheckError(TElAS3Signature_set_Time(_Handle, Value));
}

bool TElAS3Signature::get_UseUndefSize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3Signature_get_UseUndefSize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3Signature::set_UseUndefSize(bool Value)
{
	SBCheckError(TElAS3Signature_set_UseUndefSize(_Handle, (int8_t)Value));
}

TSBASSMIMEVerificationOptions TElAS3Signature::get_VerificationOptions()
{
	TSBASSMIMEVerificationOptionsRaw OutResultRaw = 0;
	SBCheckError(TElAS3Signature_get_VerificationOptions(_Handle, &OutResultRaw));
	return (TSBASSMIMEVerificationOptions)OutResultRaw;
}

SB_INLINE void TElAS3Signature::set_VerificationOptions(TSBASSMIMEVerificationOptions Value)
{
	SBCheckError(TElAS3Signature_set_VerificationOptions(_Handle, (TSBASSMIMEVerificationOptionsRaw)Value));
}

void TElAS3Signature::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElAS3Signature::TElAS3Signature(TElAS3SignatureHandle handle, TElOwnHandle ownHandle) : TElASSMIMESignature(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TCOMPONENT
TElAS3Signature::TElAS3Signature(TComponent &AOwner) : TElASSMIMESignature(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS3Signature_Create(AOwner.getHandle(), &_Handle));
}

TElAS3Signature::TElAS3Signature(TComponent *AOwner) : TElASSMIMESignature(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS3Signature_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TCOMPONENT */

TElAS3Signature::~TElAS3Signature()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELAS3SIGNATURE */

#ifdef SB_USE_CLASS_TELAS3COMPRESSION

bool TElAS3Compression::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3Compression_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3Compression::set_Enabled(bool Value)
{
	SBCheckError(TElAS3Compression_set_Enabled(_Handle, (int8_t)Value));
}

TSBASCompressionTransferEncoding TElAS3Compression::get_Encoding()
{
	TSBASCompressionTransferEncodingRaw OutResultRaw = 0;
	SBCheckError(TElAS3Compression_get_Encoding(_Handle, &OutResultRaw));
	return (TSBASCompressionTransferEncoding)OutResultRaw;
}

SB_INLINE void TElAS3Compression::set_Encoding(TSBASCompressionTransferEncoding Value)
{
	SBCheckError(TElAS3Compression_set_Encoding(_Handle, (TSBASCompressionTransferEncodingRaw)Value));
}

SB_INLINE int32_t TElAS3Compression::get_Level()
{
	int32_t OutResult;
	SBCheckError(TElAS3Compression_get_Level(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3Compression::set_Level(int32_t Value)
{
	SBCheckError(TElAS3Compression_set_Level(_Handle, Value));
}

TElAS3Compression::TElAS3Compression(TElAS3CompressionHandle handle, TElOwnHandle ownHandle) : TElASSMIMECompression(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TCOMPONENT
TElAS3Compression::TElAS3Compression(TComponent &AOwner) : TElASSMIMECompression(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAS3Compression_Create(AOwner.getHandle(), &_Handle));
}

TElAS3Compression::TElAS3Compression(TComponent *AOwner) : TElASSMIMECompression(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAS3Compression_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TCOMPONENT */

#endif /* SB_USE_CLASS_TELAS3COMPRESSION */

#ifdef SB_USE_CLASS_TELAS3RECEIPT

SB_INLINE void TElAS3Receipt::Assign(TPersistent &Source)
{
	SBCheckError(TElAS3Receipt_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElAS3Receipt::Assign(TPersistent *Source)
{
	SBCheckError(TElAS3Receipt_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELASMESSAGEERRORLIST
TElASMessageErrorList* TElAS3Receipt::get_Errors()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3Receipt_get_Errors(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Errors)
		this->_Inst_Errors = new TElASMessageErrorList(hOutResult, ohFalse);
	else
		this->_Inst_Errors->updateHandle(hOutResult);
	return this->_Inst_Errors;
}
#endif /* SB_USE_CLASS_TELASMESSAGEERRORLIST */

void TElAS3Receipt::get_ReceivedContentDigest(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElAS3Receipt_get_ReceivedContentDigest(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(58921550, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3Receipt::set_ReceivedContentDigest(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElAS3Receipt_set_ReceivedContentDigest(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TSBASSignatureDigestAlgorithm TElAS3Receipt::get_ReceivedContentDigestAlgorithm()
{
	TSBASSignatureDigestAlgorithmRaw OutResultRaw = 0;
	SBCheckError(TElAS3Receipt_get_ReceivedContentDigestAlgorithm(_Handle, &OutResultRaw));
	return (TSBASSignatureDigestAlgorithm)OutResultRaw;
}

SB_INLINE void TElAS3Receipt::set_ReceivedContentDigestAlgorithm(TSBASSignatureDigestAlgorithm Value)
{
	SBCheckError(TElAS3Receipt_set_ReceivedContentDigestAlgorithm(_Handle, (TSBASSignatureDigestAlgorithmRaw)Value));
}

TSBASDispositionActionMode TElAS3Receipt::get_ActionMode()
{
	TSBASDispositionActionModeRaw OutResultRaw = 0;
	SBCheckError(TElAS3Receipt_get_ActionMode(_Handle, &OutResultRaw));
	return (TSBASDispositionActionMode)OutResultRaw;
}

SB_INLINE void TElAS3Receipt::set_ActionMode(TSBASDispositionActionMode Value)
{
	SBCheckError(TElAS3Receipt_set_ActionMode(_Handle, (TSBASDispositionActionModeRaw)Value));
}

void TElAS3Receipt::get_AS3From(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Receipt_get_AS3From(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(475301235, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3Receipt::set_AS3From(const std::string &Value)
{
	SBCheckError(TElAS3Receipt_set_AS3From(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS3Receipt::get_AS3To(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Receipt_get_AS3To(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(656532679, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3Receipt::set_AS3To(const std::string &Value)
{
	SBCheckError(TElAS3Receipt_set_AS3To(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElAS3Receipt::get_Date()
{
	int64_t OutResult;
	SBCheckError(TElAS3Receipt_get_Date(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3Receipt::set_Date(int64_t Value)
{
	SBCheckError(TElAS3Receipt_set_Date(_Handle, Value));
}

bool TElAS3Receipt::get_DetailedErrors()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3Receipt_get_DetailedErrors(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3Receipt::set_DetailedErrors(bool Value)
{
	SBCheckError(TElAS3Receipt_set_DetailedErrors(_Handle, (int8_t)Value));
}

void TElAS3Receipt::get_FinalRecipient(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Receipt_get_FinalRecipient(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-325711474, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3Receipt::set_FinalRecipient(const std::string &Value)
{
	SBCheckError(TElAS3Receipt_set_FinalRecipient(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS3Receipt::get_MDNGateway(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Receipt_get_MDNGateway(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1824357591, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3Receipt::set_MDNGateway(const std::string &Value)
{
	SBCheckError(TElAS3Receipt_set_MDNGateway(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS3Receipt::get_MessageID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Receipt_get_MessageID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1878528377, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3Receipt::set_MessageID(const std::string &Value)
{
	SBCheckError(TElAS3Receipt_set_MessageID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS3Receipt::get_OriginalMessageID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Receipt_get_OriginalMessageID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-203466787, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3Receipt::set_OriginalMessageID(const std::string &Value)
{
	SBCheckError(TElAS3Receipt_set_OriginalMessageID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS3Receipt::get_OriginalRecipient(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Receipt_get_OriginalRecipient(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(74853510, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3Receipt::set_OriginalRecipient(const std::string &Value)
{
	SBCheckError(TElAS3Receipt_set_OriginalRecipient(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS3Receipt::get_ReportCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Receipt_get_ReportCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1927437113, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3Receipt::set_ReportCharset(const std::string &Value)
{
	SBCheckError(TElAS3Receipt_set_ReportCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBASCharsetMode TElAS3Receipt::get_ReportCharsetMode()
{
	TSBASCharsetModeRaw OutResultRaw = 0;
	SBCheckError(TElAS3Receipt_get_ReportCharsetMode(_Handle, &OutResultRaw));
	return (TSBASCharsetMode)OutResultRaw;
}

SB_INLINE void TElAS3Receipt::set_ReportCharsetMode(TSBASCharsetMode Value)
{
	SBCheckError(TElAS3Receipt_set_ReportCharsetMode(_Handle, (TSBASCharsetModeRaw)Value));
}

TSBASHeaderTransferEncoding TElAS3Receipt::get_ReportEncoding()
{
	TSBASHeaderTransferEncodingRaw OutResultRaw = 0;
	SBCheckError(TElAS3Receipt_get_ReportEncoding(_Handle, &OutResultRaw));
	return (TSBASHeaderTransferEncoding)OutResultRaw;
}

SB_INLINE void TElAS3Receipt::set_ReportEncoding(TSBASHeaderTransferEncoding Value)
{
	SBCheckError(TElAS3Receipt_set_ReportEncoding(_Handle, (TSBASHeaderTransferEncodingRaw)Value));
}

void TElAS3Receipt::get_ReportingUA(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Receipt_get_ReportingUA(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-879045354, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3Receipt::set_ReportingUA(const std::string &Value)
{
	SBCheckError(TElAS3Receipt_set_ReportingUA(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBASDispositionSendingMode TElAS3Receipt::get_SendingMode()
{
	TSBASDispositionSendingModeRaw OutResultRaw = 0;
	SBCheckError(TElAS3Receipt_get_SendingMode(_Handle, &OutResultRaw));
	return (TSBASDispositionSendingMode)OutResultRaw;
}

SB_INLINE void TElAS3Receipt::set_SendingMode(TSBASDispositionSendingMode Value)
{
	SBCheckError(TElAS3Receipt_set_SendingMode(_Handle, (TSBASDispositionSendingModeRaw)Value));
}

#ifdef SB_USE_CLASS_TELAS3SIGNATURE
TElAS3Signature* TElAS3Receipt::get_Signature()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3Receipt_get_Signature(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signature)
		this->_Inst_Signature = new TElAS3Signature(hOutResult, ohFalse);
	else
		this->_Inst_Signature->updateHandle(hOutResult);
	return this->_Inst_Signature;
}

SB_INLINE void TElAS3Receipt::set_Signature(TElAS3Signature &Value)
{
	SBCheckError(TElAS3Receipt_set_Signature(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS3Receipt::set_Signature(TElAS3Signature *Value)
{
	SBCheckError(TElAS3Receipt_set_Signature(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAS3SIGNATURE */

bool TElAS3Receipt::get_SortErrors()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3Receipt_get_SortErrors(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3Receipt::set_SortErrors(bool Value)
{
	SBCheckError(TElAS3Receipt_set_SortErrors(_Handle, (int8_t)Value));
}

void TElAS3Receipt::get_Subject(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Receipt_get_Subject(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(62933627, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElAS3Receipt::get_Subject(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElAS3Receipt_get_Subject(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(62933627, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElAS3Receipt::set_Subject(const sb_u16string &Value)
{
	SBCheckError(TElAS3Receipt_set_Subject(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElAS3Receipt::set_Subject(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElAS3Receipt_set_Subject(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElAS3Receipt::get_Text(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Receipt_get_Text(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1281877399, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElAS3Receipt::get_Text(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElAS3Receipt_get_Text(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1281877399, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElAS3Receipt::set_Text(const sb_u16string &Value)
{
	SBCheckError(TElAS3Receipt_set_Text(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElAS3Receipt::set_Text(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElAS3Receipt_set_Text(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElAS3Receipt::get_TextCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Receipt_get_TextCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2068031148, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3Receipt::set_TextCharset(const std::string &Value)
{
	SBCheckError(TElAS3Receipt_set_TextCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBASCharsetMode TElAS3Receipt::get_TextCharsetMode()
{
	TSBASCharsetModeRaw OutResultRaw = 0;
	SBCheckError(TElAS3Receipt_get_TextCharsetMode(_Handle, &OutResultRaw));
	return (TSBASCharsetMode)OutResultRaw;
}

SB_INLINE void TElAS3Receipt::set_TextCharsetMode(TSBASCharsetMode Value)
{
	SBCheckError(TElAS3Receipt_set_TextCharsetMode(_Handle, (TSBASCharsetModeRaw)Value));
}

void TElAS3Receipt::get_TextContentType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Receipt_get_TextContentType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1587580942, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3Receipt::set_TextContentType(const std::string &Value)
{
	SBCheckError(TElAS3Receipt_set_TextContentType(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBASHeaderTransferEncoding TElAS3Receipt::get_TextEncoding()
{
	TSBASHeaderTransferEncodingRaw OutResultRaw = 0;
	SBCheckError(TElAS3Receipt_get_TextEncoding(_Handle, &OutResultRaw));
	return (TSBASHeaderTransferEncoding)OutResultRaw;
}

SB_INLINE void TElAS3Receipt::set_TextEncoding(TSBASHeaderTransferEncoding Value)
{
	SBCheckError(TElAS3Receipt_set_TextEncoding(_Handle, (TSBASHeaderTransferEncodingRaw)Value));
}

TSBAS3Version TElAS3Receipt::get_Version()
{
	TSBAS3VersionRaw OutResultRaw = 0;
	SBCheckError(TElAS3Receipt_get_Version(_Handle, &OutResultRaw));
	return (TSBAS3Version)OutResultRaw;
}

SB_INLINE void TElAS3Receipt::set_Version(TSBAS3Version Value)
{
	SBCheckError(TElAS3Receipt_set_Version(_Handle, (TSBAS3VersionRaw)Value));
}

SB_INLINE void TElAS3Receipt::get_OnError(TSBASReceiptErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Receipt_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Receipt::set_OnError(TSBASReceiptErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Receipt_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Receipt::get_OnHeaderAssembled(TSBASHeaderEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Receipt_get_OnHeaderAssembled(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Receipt::set_OnHeaderAssembled(TSBASHeaderEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Receipt_set_OnHeaderAssembled(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Receipt::get_OnHeaderParsed(TSBASHeaderEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Receipt_get_OnHeaderParsed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Receipt::set_OnHeaderParsed(TSBASHeaderEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Receipt_set_OnHeaderParsed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Receipt::get_OnSign(TSBASMessageSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Receipt_get_OnSign(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Receipt::set_OnSign(TSBASMessageSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Receipt_set_OnSign(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Receipt::get_OnSigning(TSBASMessageSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Receipt_get_OnSigning(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Receipt::set_OnSigning(TSBASMessageSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Receipt_set_OnSigning(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Receipt::get_OnStepStart(TSBASProcessingStepStart &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Receipt_get_OnStepStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Receipt::set_OnStepStart(TSBASProcessingStepStart pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Receipt_set_OnStepStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Receipt::get_OnVerify(TSBASMessageVerifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Receipt_get_OnVerify(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Receipt::set_OnVerify(TSBASMessageVerifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Receipt_set_OnVerify(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Receipt::get_OnVerifyIDs(TSBASMessageVerifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Receipt_get_OnVerifyIDs(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Receipt::set_OnVerifyIDs(TSBASMessageVerifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Receipt_set_OnVerifyIDs(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Receipt::get_OnVerifying(TSBASMessageVerifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Receipt_get_OnVerifying(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Receipt::set_OnVerifying(TSBASMessageVerifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Receipt_set_OnVerifying(_Handle, pMethodValue, pDataValue));
}

void TElAS3Receipt::initInstances()
{
#ifdef SB_USE_CLASS_TELASMESSAGEERRORLIST
	this->_Inst_Errors = NULL;
#endif /* SB_USE_CLASS_TELASMESSAGEERRORLIST */
#ifdef SB_USE_CLASS_TELAS3SIGNATURE
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELAS3SIGNATURE */
}

TElAS3Receipt::TElAS3Receipt(TElAS3ReceiptHandle handle, TElOwnHandle ownHandle) : TElASReceipt(handle, ownHandle)
{
	initInstances();
}

TElAS3Receipt::TElAS3Receipt(TComponent &AOwner) : TElASReceipt(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS3Receipt_Create(AOwner.getHandle(), &_Handle));
}

TElAS3Receipt::TElAS3Receipt(TComponent *AOwner) : TElASReceipt(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS3Receipt_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElAS3Receipt::~TElAS3Receipt()
{
#ifdef SB_USE_CLASS_TELASMESSAGEERRORLIST
	delete this->_Inst_Errors;
	this->_Inst_Errors = NULL;
#endif /* SB_USE_CLASS_TELASMESSAGEERRORLIST */
#ifdef SB_USE_CLASS_TELAS3SIGNATURE
	delete this->_Inst_Signature;
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELAS3SIGNATURE */
}
#endif /* SB_USE_CLASS_TELAS3RECEIPT */

#ifdef SB_USE_CLASS_TELAS3MESSAGE

SB_INLINE void TElAS3Message::Assign(TPersistent &Source)
{
	SBCheckError(TElAS3Message_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElAS3Message::Assign(TPersistent *Source)
{
	SBCheckError(TElAS3Message_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

bool TElAS3Message::get_Cancelled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3Message_get_Cancelled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElAS3Message::get_ContentDigest(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElAS3Message_get_ContentDigest(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-966189578, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBASSignatureDigestAlgorithm TElAS3Message::get_ContentDigestAlgorithm()
{
	TSBASSignatureDigestAlgorithmRaw OutResultRaw = 0;
	SBCheckError(TElAS3Message_get_ContentDigestAlgorithm(_Handle, &OutResultRaw));
	return (TSBASSignatureDigestAlgorithm)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELASMESSAGEERRORLIST
TElASMessageErrorList* TElAS3Message::get_Errors()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3Message_get_Errors(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Errors)
		this->_Inst_Errors = new TElASMessageErrorList(hOutResult, ohFalse);
	else
		this->_Inst_Errors->updateHandle(hOutResult);
	return this->_Inst_Errors;
}
#endif /* SB_USE_CLASS_TELASMESSAGEERRORLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElAS3Message::get_Features()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3Message_get_Features(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Features)
		this->_Inst_Features = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Features->updateHandle(hOutResult);
	return this->_Inst_Features;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElAS3Message::get_Features()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3Message_get_Features(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Features)
		this->_Inst_Features = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Features->updateHandle(hOutResult);
	return this->_Inst_Features;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElAS3Message::get_AS3From(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Message_get_AS3From(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1258931140, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3Message::set_AS3From(const std::string &Value)
{
	SBCheckError(TElAS3Message_set_AS3From(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS3Message::get_AS3To(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Message_get_AS3To(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1629186799, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3Message::set_AS3To(const std::string &Value)
{
	SBCheckError(TElAS3Message_set_AS3To(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS3Message::get_Charset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Message_get_Charset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(284687523, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3Message::set_Charset(const std::string &Value)
{
	SBCheckError(TElAS3Message_set_Charset(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBASCharsetMode TElAS3Message::get_CharsetMode()
{
	TSBASCharsetModeRaw OutResultRaw = 0;
	SBCheckError(TElAS3Message_get_CharsetMode(_Handle, &OutResultRaw));
	return (TSBASCharsetMode)OutResultRaw;
}

SB_INLINE void TElAS3Message::set_CharsetMode(TSBASCharsetMode Value)
{
	SBCheckError(TElAS3Message_set_CharsetMode(_Handle, (TSBASCharsetModeRaw)Value));
}

void TElAS3Message::get_ContentType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Message_get_ContentType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1025636434, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3Message::set_ContentType(const std::string &Value)
{
	SBCheckError(TElAS3Message_set_ContentType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELAS3COMPRESSION
TElAS3Compression* TElAS3Message::get_Compression()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3Message_get_Compression(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Compression)
		this->_Inst_Compression = new TElAS3Compression(hOutResult, ohFalse);
	else
		this->_Inst_Compression->updateHandle(hOutResult);
	return this->_Inst_Compression;
}

SB_INLINE void TElAS3Message::set_Compression(TElAS3Compression &Value)
{
	SBCheckError(TElAS3Message_set_Compression(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS3Message::set_Compression(TElAS3Compression *Value)
{
	SBCheckError(TElAS3Message_set_Compression(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAS3COMPRESSION */

TSBASDataTransferEncoding TElAS3Message::get_DataEncoding()
{
	TSBASDataTransferEncodingRaw OutResultRaw = 0;
	SBCheckError(TElAS3Message_get_DataEncoding(_Handle, &OutResultRaw));
	return (TSBASDataTransferEncoding)OutResultRaw;
}

SB_INLINE void TElAS3Message::set_DataEncoding(TSBASDataTransferEncoding Value)
{
	SBCheckError(TElAS3Message_set_DataEncoding(_Handle, (TSBASDataTransferEncodingRaw)Value));
}

SB_INLINE int64_t TElAS3Message::get_Date()
{
	int64_t OutResult;
	SBCheckError(TElAS3Message_get_Date(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3Message::set_Date(int64_t Value)
{
	SBCheckError(TElAS3Message_set_Date(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELAS3ENCRYPTION
TElAS3Encryption* TElAS3Message::get_Encryption()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3Message_get_Encryption(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Encryption)
		this->_Inst_Encryption = new TElAS3Encryption(hOutResult, ohFalse);
	else
		this->_Inst_Encryption->updateHandle(hOutResult);
	return this->_Inst_Encryption;
}

SB_INLINE void TElAS3Message::set_Encryption(TElAS3Encryption &Value)
{
	SBCheckError(TElAS3Message_set_Encryption(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS3Message::set_Encryption(TElAS3Encryption *Value)
{
	SBCheckError(TElAS3Message_set_Encryption(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAS3ENCRYPTION */

SB_INLINE int64_t TElAS3Message::get_FileCreated()
{
	int64_t OutResult;
	SBCheckError(TElAS3Message_get_FileCreated(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3Message::set_FileCreated(int64_t Value)
{
	SBCheckError(TElAS3Message_set_FileCreated(_Handle, Value));
}

SB_INLINE int64_t TElAS3Message::get_FileModified()
{
	int64_t OutResult;
	SBCheckError(TElAS3Message_get_FileModified(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3Message::set_FileModified(int64_t Value)
{
	SBCheckError(TElAS3Message_set_FileModified(_Handle, Value));
}

void TElAS3Message::get_FileName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Message_get_FileName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1821830237, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElAS3Message::get_FileName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElAS3Message_get_FileName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1821830237, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElAS3Message::set_FileName(const sb_u16string &Value)
{
	SBCheckError(TElAS3Message_set_FileName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElAS3Message::set_FileName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElAS3Message_set_FileName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TSBASHeaderTransferEncoding TElAS3Message::get_HeaderEncoding()
{
	TSBASHeaderTransferEncodingRaw OutResultRaw = 0;
	SBCheckError(TElAS3Message_get_HeaderEncoding(_Handle, &OutResultRaw));
	return (TSBASHeaderTransferEncoding)OutResultRaw;
}

SB_INLINE void TElAS3Message::set_HeaderEncoding(TSBASHeaderTransferEncoding Value)
{
	SBCheckError(TElAS3Message_set_HeaderEncoding(_Handle, (TSBASHeaderTransferEncodingRaw)Value));
}

bool TElAS3Message::get_IgnoreFileWarnings()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3Message_get_IgnoreFileWarnings(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3Message::set_IgnoreFileWarnings(bool Value)
{
	SBCheckError(TElAS3Message_set_IgnoreFileWarnings(_Handle, (int8_t)Value));
}

void TElAS3Message::get_MessageID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Message_get_MessageID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1539545856, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3Message::set_MessageID(const std::string &Value)
{
	SBCheckError(TElAS3Message_set_MessageID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELAS3RECEIPTREQUEST
TElAS3ReceiptRequest* TElAS3Message::get_ReceiptRequest()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3Message_get_ReceiptRequest(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ReceiptRequest)
		this->_Inst_ReceiptRequest = new TElAS3ReceiptRequest(hOutResult, ohFalse);
	else
		this->_Inst_ReceiptRequest->updateHandle(hOutResult);
	return this->_Inst_ReceiptRequest;
}

SB_INLINE void TElAS3Message::set_ReceiptRequest(TElAS3ReceiptRequest &Value)
{
	SBCheckError(TElAS3Message_set_ReceiptRequest(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS3Message::set_ReceiptRequest(TElAS3ReceiptRequest *Value)
{
	SBCheckError(TElAS3Message_set_ReceiptRequest(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAS3RECEIPTREQUEST */

#ifdef SB_USE_CLASS_TELAS3SIGNATURE
TElAS3Signature* TElAS3Message::get_Signature()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3Message_get_Signature(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signature)
		this->_Inst_Signature = new TElAS3Signature(hOutResult, ohFalse);
	else
		this->_Inst_Signature->updateHandle(hOutResult);
	return this->_Inst_Signature;
}

SB_INLINE void TElAS3Message::set_Signature(TElAS3Signature &Value)
{
	SBCheckError(TElAS3Message_set_Signature(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS3Message::set_Signature(TElAS3Signature *Value)
{
	SBCheckError(TElAS3Message_set_Signature(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAS3SIGNATURE */

void TElAS3Message::get_Subject(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Message_get_Subject(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1419578572, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElAS3Message::get_Subject(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElAS3Message_get_Subject(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1419578572, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElAS3Message::set_Subject(const sb_u16string &Value)
{
	SBCheckError(TElAS3Message_set_Subject(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElAS3Message::set_Subject(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElAS3Message_set_Subject(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TSBAS3Version TElAS3Message::get_Version()
{
	TSBAS3VersionRaw OutResultRaw = 0;
	SBCheckError(TElAS3Message_get_Version(_Handle, &OutResultRaw));
	return (TSBAS3Version)OutResultRaw;
}

SB_INLINE void TElAS3Message::set_Version(TSBAS3Version Value)
{
	SBCheckError(TElAS3Message_set_Version(_Handle, (TSBAS3VersionRaw)Value));
}

SB_INLINE void TElAS3Message::get_OnDecrypt(TSBASMessageDecryptEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Message_get_OnDecrypt(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Message::set_OnDecrypt(TSBASMessageDecryptEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Message_set_OnDecrypt(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Message::get_OnDecryptIDs(TSBASMessageDecryptEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Message_get_OnDecryptIDs(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Message::set_OnDecryptIDs(TSBASMessageDecryptEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Message_set_OnDecryptIDs(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Message::get_OnDecrypting(TSBASMessageDecryptEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Message_get_OnDecrypting(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Message::set_OnDecrypting(TSBASMessageDecryptEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Message_set_OnDecrypting(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Message::get_OnError(TSBASMessageErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Message_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Message::set_OnError(TSBASMessageErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Message_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Message::get_OnHeaderAssembled(TSBASHeaderEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Message_get_OnHeaderAssembled(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Message::set_OnHeaderAssembled(TSBASHeaderEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Message_set_OnHeaderAssembled(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Message::get_OnHeaderParsed(TSBASHeaderEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Message_get_OnHeaderParsed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Message::set_OnHeaderParsed(TSBASHeaderEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Message_set_OnHeaderParsed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Message::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Message_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Message::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Message_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Message::get_OnSign(TSBASMessageSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Message_get_OnSign(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Message::set_OnSign(TSBASMessageSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Message_set_OnSign(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Message::get_OnSigning(TSBASMessageSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Message_get_OnSigning(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Message::set_OnSigning(TSBASMessageSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Message_set_OnSigning(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Message::get_OnStepStart(TSBASProcessingStepStart &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Message_get_OnStepStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Message::set_OnStepStart(TSBASProcessingStepStart pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Message_set_OnStepStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Message::get_OnTempRelease(TSBASStreamReleaseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Message_get_OnTempRelease(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Message::set_OnTempRelease(TSBASStreamReleaseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Message_set_OnTempRelease(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Message::get_OnTempRequest(TSBASStreamRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Message_get_OnTempRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Message::set_OnTempRequest(TSBASStreamRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Message_set_OnTempRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Message::get_OnVerify(TSBASMessageVerifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Message_get_OnVerify(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Message::set_OnVerify(TSBASMessageVerifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Message_set_OnVerify(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Message::get_OnVerifyIDs(TSBASMessageVerifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Message_get_OnVerifyIDs(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Message::set_OnVerifyIDs(TSBASMessageVerifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Message_set_OnVerifyIDs(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Message::get_OnVerifying(TSBASMessageVerifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Message_get_OnVerifying(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Message::set_OnVerifying(TSBASMessageVerifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Message_set_OnVerifying(_Handle, pMethodValue, pDataValue));
}

void TElAS3Message::initInstances()
{
#ifdef SB_USE_CLASS_TELASMESSAGEERRORLIST
	this->_Inst_Errors = NULL;
#endif /* SB_USE_CLASS_TELASMESSAGEERRORLIST */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Features = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Features = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELAS3COMPRESSION
	this->_Inst_Compression = NULL;
#endif /* SB_USE_CLASS_TELAS3COMPRESSION */
#ifdef SB_USE_CLASS_TELAS3ENCRYPTION
	this->_Inst_Encryption = NULL;
#endif /* SB_USE_CLASS_TELAS3ENCRYPTION */
#ifdef SB_USE_CLASS_TELAS3RECEIPTREQUEST
	this->_Inst_ReceiptRequest = NULL;
#endif /* SB_USE_CLASS_TELAS3RECEIPTREQUEST */
#ifdef SB_USE_CLASS_TELAS3SIGNATURE
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELAS3SIGNATURE */
}

TElAS3Message::TElAS3Message(TElAS3MessageHandle handle, TElOwnHandle ownHandle) : TElASMessage(handle, ownHandle)
{
	initInstances();
}

TElAS3Message::TElAS3Message(TComponent &AOwner) : TElASMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS3Message_Create(AOwner.getHandle(), &_Handle));
}

TElAS3Message::TElAS3Message(TComponent *AOwner) : TElASMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS3Message_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElAS3Message::~TElAS3Message()
{
#ifdef SB_USE_CLASS_TELASMESSAGEERRORLIST
	delete this->_Inst_Errors;
	this->_Inst_Errors = NULL;
#endif /* SB_USE_CLASS_TELASMESSAGEERRORLIST */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Features;
	this->_Inst_Features = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Features;
	this->_Inst_Features = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELAS3COMPRESSION
	delete this->_Inst_Compression;
	this->_Inst_Compression = NULL;
#endif /* SB_USE_CLASS_TELAS3COMPRESSION */
#ifdef SB_USE_CLASS_TELAS3ENCRYPTION
	delete this->_Inst_Encryption;
	this->_Inst_Encryption = NULL;
#endif /* SB_USE_CLASS_TELAS3ENCRYPTION */
#ifdef SB_USE_CLASS_TELAS3RECEIPTREQUEST
	delete this->_Inst_ReceiptRequest;
	this->_Inst_ReceiptRequest = NULL;
#endif /* SB_USE_CLASS_TELAS3RECEIPTREQUEST */
#ifdef SB_USE_CLASS_TELAS3SIGNATURE
	delete this->_Inst_Signature;
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELAS3SIGNATURE */
}
#endif /* SB_USE_CLASS_TELAS3MESSAGE */

#ifdef SB_USE_CLASS_TELAS3SOCKSOPTIONS

SB_INLINE void TElAS3SocksOptions::Assign(TPersistent &Source)
{
	SBCheckError(TElAS3SocksOptions_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElAS3SocksOptions::Assign(TPersistent *Source)
{
	SBCheckError(TElAS3SocksOptions_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

TElSocksAuthentication TElAS3SocksOptions::get_Authentication()
{
	TElSocksAuthenticationRaw OutResultRaw = 0;
	SBCheckError(TElAS3SocksOptions_get_Authentication(_Handle, &OutResultRaw));
	return (TElSocksAuthentication)OutResultRaw;
}

SB_INLINE void TElAS3SocksOptions::set_Authentication(TElSocksAuthentication Value)
{
	SBCheckError(TElAS3SocksOptions_set_Authentication(_Handle, (TElSocksAuthenticationRaw)Value));
}

bool TElAS3SocksOptions::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3SocksOptions_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3SocksOptions::set_Enabled(bool Value)
{
	SBCheckError(TElAS3SocksOptions_set_Enabled(_Handle, (int8_t)Value));
}

void TElAS3SocksOptions::get_Host(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3SocksOptions_get_Host(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1146837718, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3SocksOptions::set_Host(const std::string &Value)
{
	SBCheckError(TElAS3SocksOptions_set_Host(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS3SocksOptions::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3SocksOptions_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(688973030, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3SocksOptions::set_Password(const std::string &Value)
{
	SBCheckError(TElAS3SocksOptions_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElAS3SocksOptions::get_Port()
{
	int32_t OutResult;
	SBCheckError(TElAS3SocksOptions_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3SocksOptions::set_Port(int32_t Value)
{
	SBCheckError(TElAS3SocksOptions_set_Port(_Handle, Value));
}

bool TElAS3SocksOptions::get_ResolveAddress()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3SocksOptions_get_ResolveAddress(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3SocksOptions::set_ResolveAddress(bool Value)
{
	SBCheckError(TElAS3SocksOptions_set_ResolveAddress(_Handle, (int8_t)Value));
}

#ifdef SB_WINDOWS
bool TElAS3SocksOptions::get_UseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3SocksOptions_get_UseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3SocksOptions::set_UseIPv6(bool Value)
{
	SBCheckError(TElAS3SocksOptions_set_UseIPv6(_Handle, (int8_t)Value));
}
#endif

void TElAS3SocksOptions::get_UserCode(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3SocksOptions_get_UserCode(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1837647332, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3SocksOptions::set_UserCode(const std::string &Value)
{
	SBCheckError(TElAS3SocksOptions_set_UserCode(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSocksVersion TElAS3SocksOptions::get_Version()
{
	TElSocksVersionRaw OutResultRaw = 0;
	SBCheckError(TElAS3SocksOptions_get_Version(_Handle, &OutResultRaw));
	return (TElSocksVersion)OutResultRaw;
}

SB_INLINE void TElAS3SocksOptions::set_Version(TElSocksVersion Value)
{
	SBCheckError(TElAS3SocksOptions_set_Version(_Handle, (TElSocksVersionRaw)Value));
}

TElAS3SocksOptions::TElAS3SocksOptions(TElAS3SocksOptionsHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELSIMPLEFTPSCLIENT
TElAS3SocksOptions::TElAS3SocksOptions(TElSimpleFTPSClient &AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAS3SocksOptions_Create(AClient.getHandle(), &_Handle));
}

TElAS3SocksOptions::TElAS3SocksOptions(TElSimpleFTPSClient *AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAS3SocksOptions_Create((AClient != NULL) ? AClient->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSIMPLEFTPSCLIENT */

#endif /* SB_USE_CLASS_TELAS3SOCKSOPTIONS */

#ifdef SB_USE_CLASS_TELAS3SSLOPTIONS

SB_INLINE void TElAS3SSLOptions::Assign(TPersistent &Source)
{
	SBCheckError(TElAS3SSLOptions_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElAS3SSLOptions::Assign(TPersistent *Source)
{
	SBCheckError(TElAS3SSLOptions_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

void TElAS3SSLOptions::InternalValidate(TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason)
{
	TSBCertificateValidityRaw ValidityRaw = (TSBCertificateValidityRaw)Validity;
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	SBCheckError(TElAS3SSLOptions_InternalValidate(_Handle, &ValidityRaw, &ReasonRaw));
	Validity = (TSBCertificateValidity)ValidityRaw;
	Reason = (TSBCertificateValidityReason)ReasonRaw;
}

SB_INLINE void TElAS3SSLOptions::RenegotiateCiphers()
{
	SBCheckError(TElAS3SSLOptions_RenegotiateCiphers(_Handle));
}

bool TElAS3SSLOptions::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3SSLOptions_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE uint8_t TElAS3SSLOptions::get_CurrentCipherSuite()
{
	uint8_t OutResult;
	SBCheckError(TElAS3SSLOptions_get_CurrentCipherSuite(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElAS3SSLOptions::get_CurrentCompression()
{
	uint8_t OutResult;
	SBCheckError(TElAS3SSLOptions_get_CurrentCompression(_Handle, &OutResult));
	return OutResult;
}

TSBVersion TElAS3SSLOptions::get_CurrentVersion()
{
	TSBVersionRaw OutResultRaw = 0;
	SBCheckError(TElAS3SSLOptions_get_CurrentVersion(_Handle, &OutResultRaw));
	return (TSBVersion)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
TElClientSSLExtensions* TElAS3SSLOptions::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3SSLOptions_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TElClientSSLExtensions(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
TElCustomSSLExtensions* TElAS3SSLOptions::get_ServerExtensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3SSLOptions_get_ServerExtensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ServerExtensions)
		this->_Inst_ServerExtensions = new TElCustomSSLExtensions(hOutResult, ohFalse);
	else
		this->_Inst_ServerExtensions->updateHandle(hOutResult);
	return this->_Inst_ServerExtensions;
}
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */

SB_INLINE int32_t TElAS3SSLOptions::get_CipherSuitePriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElAS3SSLOptions_get_CipherSuitePriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3SSLOptions::set_CipherSuitePriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElAS3SSLOptions_set_CipherSuitePriorities(_Handle, Index, Value));
}

bool TElAS3SSLOptions::get_CipherSuites(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3SSLOptions_get_CipherSuites(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3SSLOptions::set_CipherSuites(uint8_t Index, bool Value)
{
	SBCheckError(TElAS3SSLOptions_set_CipherSuites(_Handle, Index, (int8_t)Value));
}

bool TElAS3SSLOptions::get_CompressionAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3SSLOptions_get_CompressionAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3SSLOptions::set_CompressionAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElAS3SSLOptions_set_CompressionAlgorithms(_Handle, Index, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElAS3SSLOptions::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3SSLOptions_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElAS3SSLOptions::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElAS3SSLOptions_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS3SSLOptions::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElAS3SSLOptions_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElAS3SSLOptions::get_ClientCertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3SSLOptions_get_ClientCertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ClientCertStorage)
		this->_Inst_ClientCertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_ClientCertStorage->updateHandle(hOutResult);
	return this->_Inst_ClientCertStorage;
}

SB_INLINE void TElAS3SSLOptions::set_ClientCertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElAS3SSLOptions_set_ClientCertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS3SSLOptions::set_ClientCertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElAS3SSLOptions_set_ClientCertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

bool TElAS3SSLOptions::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3SSLOptions_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3SSLOptions::set_Enabled(bool Value)
{
	SBCheckError(TElAS3SSLOptions_set_Enabled(_Handle, (int8_t)Value));
}

bool TElAS3SSLOptions::get_EncryptData()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3SSLOptions_get_EncryptData(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3SSLOptions::set_EncryptData(bool Value)
{
	SBCheckError(TElAS3SSLOptions_set_EncryptData(_Handle, (int8_t)Value));
}

TSBSSLMode TElAS3SSLOptions::get_Mode()
{
	TSBSSLModeRaw OutResultRaw = 0;
	SBCheckError(TElAS3SSLOptions_get_Mode(_Handle, &OutResultRaw));
	return (TSBSSLMode)OutResultRaw;
}

SB_INLINE void TElAS3SSLOptions::set_Mode(TSBSSLMode Value)
{
	SBCheckError(TElAS3SSLOptions_set_Mode(_Handle, (TSBSSLModeRaw)Value));
}

bool TElAS3SSLOptions::get_ResumeSessions()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3SSLOptions_get_ResumeSessions(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3SSLOptions::set_ResumeSessions(bool Value)
{
	SBCheckError(TElAS3SSLOptions_set_ResumeSessions(_Handle, (int8_t)Value));
}

TSBVersions TElAS3SSLOptions::get_Versions()
{
	TSBVersionsRaw OutResultRaw = 0;
	SBCheckError(TElAS3SSLOptions_get_Versions(_Handle, &OutResultRaw));
	return (TSBVersions)OutResultRaw;
}

SB_INLINE void TElAS3SSLOptions::set_Versions(TSBVersions Value)
{
	SBCheckError(TElAS3SSLOptions_set_Versions(_Handle, (TSBVersionsRaw)Value));
}

void TElAS3SSLOptions::initInstances()
{
#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
	this->_Inst_ServerExtensions = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_ClientCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElAS3SSLOptions::TElAS3SSLOptions(TElAS3SSLOptionsHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELSIMPLEFTPSCLIENT
TElAS3SSLOptions::TElAS3SSLOptions(TElSimpleFTPSClient &AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS3SSLOptions_Create(AClient.getHandle(), &_Handle));
}

TElAS3SSLOptions::TElAS3SSLOptions(TElSimpleFTPSClient *AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS3SSLOptions_Create((AClient != NULL) ? AClient->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSIMPLEFTPSCLIENT */

TElAS3SSLOptions::~TElAS3SSLOptions()
{
#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
	delete this->_Inst_ServerExtensions;
	this->_Inst_ServerExtensions = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_ClientCertStorage;
	this->_Inst_ClientCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELAS3SSLOPTIONS */

#ifdef SB_USE_CLASS_TELAS3WEBTUNNELOPTIONS

SB_INLINE void TElAS3WebTunnelOptions::Assign(TPersistent &Source)
{
	SBCheckError(TElAS3WebTunnelOptions_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElAS3WebTunnelOptions::Assign(TPersistent *Source)
{
	SBCheckError(TElAS3WebTunnelOptions_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElAS3WebTunnelOptions::get_ServerResult()
{
	int32_t OutResult;
	SBCheckError(TElAS3WebTunnelOptions_get_ServerResult(_Handle, &OutResult));
	return OutResult;
}

TElWebTunnelAuthentication TElAS3WebTunnelOptions::get_Authentication()
{
	TElWebTunnelAuthenticationRaw OutResultRaw = 0;
	SBCheckError(TElAS3WebTunnelOptions_get_Authentication(_Handle, &OutResultRaw));
	return (TElWebTunnelAuthentication)OutResultRaw;
}

SB_INLINE void TElAS3WebTunnelOptions::set_Authentication(TElWebTunnelAuthentication Value)
{
	SBCheckError(TElAS3WebTunnelOptions_set_Authentication(_Handle, (TElWebTunnelAuthenticationRaw)Value));
}

bool TElAS3WebTunnelOptions::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3WebTunnelOptions_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3WebTunnelOptions::set_Enabled(bool Value)
{
	SBCheckError(TElAS3WebTunnelOptions_set_Enabled(_Handle, (int8_t)Value));
}

void TElAS3WebTunnelOptions::get_Host(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3WebTunnelOptions_get_Host(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1904183521, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3WebTunnelOptions::set_Host(const std::string &Value)
{
	SBCheckError(TElAS3WebTunnelOptions_set_Host(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS3WebTunnelOptions::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3WebTunnelOptions_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1582010584, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3WebTunnelOptions::set_Password(const std::string &Value)
{
	SBCheckError(TElAS3WebTunnelOptions_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElAS3WebTunnelOptions::get_Port()
{
	int32_t OutResult;
	SBCheckError(TElAS3WebTunnelOptions_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3WebTunnelOptions::set_Port(int32_t Value)
{
	SBCheckError(TElAS3WebTunnelOptions_set_Port(_Handle, Value));
}

void TElAS3WebTunnelOptions::get_UserID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3WebTunnelOptions_get_UserID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1616128462, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3WebTunnelOptions::set_UserID(const std::string &Value)
{
	SBCheckError(TElAS3WebTunnelOptions_set_UserID(_Handle, Value.data(), (int32_t)Value.length()));
}

TElAS3WebTunnelOptions::TElAS3WebTunnelOptions(TElAS3WebTunnelOptionsHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELSIMPLEFTPSCLIENT
TElAS3WebTunnelOptions::TElAS3WebTunnelOptions(TElSimpleFTPSClient &AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAS3WebTunnelOptions_Create(AClient.getHandle(), &_Handle));
}

TElAS3WebTunnelOptions::TElAS3WebTunnelOptions(TElSimpleFTPSClient *AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAS3WebTunnelOptions_Create((AClient != NULL) ? AClient->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSIMPLEFTPSCLIENT */

#endif /* SB_USE_CLASS_TELAS3WEBTUNNELOPTIONS */

#ifdef SB_USE_CLASS_TELAS3FTPOPTIONS

SB_INLINE void TElAS3FTPOptions::Assign(TPersistent &Source)
{
	SBCheckError(TElAS3FTPOptions_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElAS3FTPOptions::Assign(TPersistent *Source)
{
	SBCheckError(TElAS3FTPOptions_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

bool TElAS3FTPOptions::get_ExtMDTMSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3FTPOptions_get_ExtMDTMSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElAS3FTPOptions::get_ExtMLSTSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3FTPOptions_get_ExtMLSTSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElAS3FTPOptions::get_ExtRESTSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3FTPOptions_get_ExtRESTSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElAS3FTPOptions::get_ExtSIZESupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3FTPOptions_get_ExtSIZESupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElAS3FTPOptions::get_ExtXCRCSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3FTPOptions_get_ExtXCRCSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElAS3FTPOptions::get_ExtXMD5Supported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3FTPOptions_get_ExtXMD5Supported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElAS3FTPOptions::get_ExtXSHA1Supported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3FTPOptions_get_ExtXSHA1Supported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElAS3FTPOptions::get_LastReply(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3FTPOptions_get_LastReply(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1431151761, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElAS3FTPOptions::get_ModeZSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3FTPOptions_get_ModeZSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElAS3FTPOptions::get_AccountInfo(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3FTPOptions_get_AccountInfo(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1445024624, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3FTPOptions::set_AccountInfo(const std::string &Value)
{
	SBCheckError(TElAS3FTPOptions_set_AccountInfo(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElAS3FTPOptions::get_AdjustPasvAddress()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3FTPOptions_get_AdjustPasvAddress(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3FTPOptions::set_AdjustPasvAddress(bool Value)
{
	SBCheckError(TElAS3FTPOptions_set_AdjustPasvAddress(_Handle, (int8_t)Value));
}

TSBFTPAuthCmd TElAS3FTPOptions::get_AuthCmd()
{
	TSBFTPAuthCmdRaw OutResultRaw = 0;
	SBCheckError(TElAS3FTPOptions_get_AuthCmd(_Handle, &OutResultRaw));
	return (TSBFTPAuthCmd)OutResultRaw;
}

SB_INLINE void TElAS3FTPOptions::set_AuthCmd(TSBFTPAuthCmd Value)
{
	SBCheckError(TElAS3FTPOptions_set_AuthCmd(_Handle, (TSBFTPAuthCmdRaw)Value));
}

void TElAS3FTPOptions::get_LocalCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3FTPOptions_get_LocalCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1229915449, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3FTPOptions::set_LocalCharset(const std::string &Value)
{
	SBCheckError(TElAS3FTPOptions_set_LocalCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElAS3FTPOptions::get_ModeZ()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3FTPOptions_get_ModeZ(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3FTPOptions::set_ModeZ(bool Value)
{
	SBCheckError(TElAS3FTPOptions_set_ModeZ(_Handle, (int8_t)Value));
}

SB_INLINE uint8_t TElAS3FTPOptions::get_ModeZLevel()
{
	uint8_t OutResult;
	SBCheckError(TElAS3FTPOptions_get_ModeZLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3FTPOptions::set_ModeZLevel(uint8_t Value)
{
	SBCheckError(TElAS3FTPOptions_set_ModeZLevel(_Handle, Value));
}

TSBFTPOptions TElAS3FTPOptions::get_Options()
{
	TSBFTPOptionsRaw OutResultRaw = 0;
	SBCheckError(TElAS3FTPOptions_get_Options(_Handle, &OutResultRaw));
	return (TSBFTPOptions)OutResultRaw;
}

SB_INLINE void TElAS3FTPOptions::set_Options(TSBFTPOptions Value)
{
	SBCheckError(TElAS3FTPOptions_set_Options(_Handle, (TSBFTPOptionsRaw)Value));
}

bool TElAS3FTPOptions::get_PassiveMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3FTPOptions_get_PassiveMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3FTPOptions::set_PassiveMode(bool Value)
{
	SBCheckError(TElAS3FTPOptions_set_PassiveMode(_Handle, (int8_t)Value));
}

void TElAS3FTPOptions::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3FTPOptions_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2018117623, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3FTPOptions::set_Password(const std::string &Value)
{
	SBCheckError(TElAS3FTPOptions_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS3FTPOptions::get_RemoteCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3FTPOptions_get_RemoteCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-159913371, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3FTPOptions::set_RemoteCharset(const std::string &Value)
{
	SBCheckError(TElAS3FTPOptions_set_RemoteCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBFTPTransferType TElAS3FTPOptions::get_TransferType()
{
	TSBFTPTransferTypeRaw OutResultRaw = 0;
	SBCheckError(TElAS3FTPOptions_get_TransferType(_Handle, &OutResultRaw));
	return (TSBFTPTransferType)OutResultRaw;
}

SB_INLINE void TElAS3FTPOptions::set_TransferType(TSBFTPTransferType Value)
{
	SBCheckError(TElAS3FTPOptions_set_TransferType(_Handle, (TSBFTPTransferTypeRaw)Value));
}

bool TElAS3FTPOptions::get_UseFEATCmd()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3FTPOptions_get_UseFEATCmd(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3FTPOptions::set_UseFEATCmd(bool Value)
{
	SBCheckError(TElAS3FTPOptions_set_UseFEATCmd(_Handle, (int8_t)Value));
}

void TElAS3FTPOptions::get_UserName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3FTPOptions_get_UserName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-367323243, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3FTPOptions::set_UserName(const std::string &Value)
{
	SBCheckError(TElAS3FTPOptions_set_UserName(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElAS3FTPOptions::get_UseSIZECmd()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3FTPOptions_get_UseSIZECmd(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3FTPOptions::set_UseSIZECmd(bool Value)
{
	SBCheckError(TElAS3FTPOptions_set_UseSIZECmd(_Handle, (int8_t)Value));
}

TElAS3FTPOptions::TElAS3FTPOptions(TElAS3FTPOptionsHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELSIMPLEFTPSCLIENT
TElAS3FTPOptions::TElAS3FTPOptions(TElSimpleFTPSClient &AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAS3FTPOptions_Create(AClient.getHandle(), &_Handle));
}

TElAS3FTPOptions::TElAS3FTPOptions(TElSimpleFTPSClient *AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAS3FTPOptions_Create((AClient != NULL) ? AClient->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSIMPLEFTPSCLIENT */

#endif /* SB_USE_CLASS_TELAS3FTPOPTIONS */

#ifdef SB_USE_CLASS_TELAS3PROXYOPTIONS

SB_INLINE void TElAS3ProxyOptions::Assign(TPersistent &Source)
{
	SBCheckError(TElAS3ProxyOptions_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElAS3ProxyOptions::Assign(TPersistent *Source)
{
	SBCheckError(TElAS3ProxyOptions_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

void TElAS3ProxyOptions::get_Host(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3ProxyOptions_get_Host(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2131901435, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3ProxyOptions::set_Host(const std::string &Value)
{
	SBCheckError(TElAS3ProxyOptions_set_Host(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS3ProxyOptions::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3ProxyOptions_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(149219313, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3ProxyOptions::set_Password(const std::string &Value)
{
	SBCheckError(TElAS3ProxyOptions_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE uint16_t TElAS3ProxyOptions::get_Port()
{
	uint16_t OutResult;
	SBCheckError(TElAS3ProxyOptions_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3ProxyOptions::set_Port(uint16_t Value)
{
	SBCheckError(TElAS3ProxyOptions_set_Port(_Handle, Value));
}

TSBFTPProxyType TElAS3ProxyOptions::get_ProxyType()
{
	TSBFTPProxyTypeRaw OutResultRaw = 0;
	SBCheckError(TElAS3ProxyOptions_get_ProxyType(_Handle, &OutResultRaw));
	return (TSBFTPProxyType)OutResultRaw;
}

SB_INLINE void TElAS3ProxyOptions::set_ProxyType(TSBFTPProxyType Value)
{
	SBCheckError(TElAS3ProxyOptions_set_ProxyType(_Handle, (TSBFTPProxyTypeRaw)Value));
}

void TElAS3ProxyOptions::get_UserName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3ProxyOptions_get_UserName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1699350637, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3ProxyOptions::set_UserName(const std::string &Value)
{
	SBCheckError(TElAS3ProxyOptions_set_UserName(_Handle, Value.data(), (int32_t)Value.length()));
}

TElAS3ProxyOptions::TElAS3ProxyOptions(TElAS3ProxyOptionsHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELSIMPLEFTPSCLIENT
TElAS3ProxyOptions::TElAS3ProxyOptions(TElSimpleFTPSClient &AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAS3ProxyOptions_Create(AClient.getHandle(), &_Handle));
}

TElAS3ProxyOptions::TElAS3ProxyOptions(TElSimpleFTPSClient *AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAS3ProxyOptions_Create((AClient != NULL) ? AClient->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSIMPLEFTPSCLIENT */

#endif /* SB_USE_CLASS_TELAS3PROXYOPTIONS */

#ifdef SB_USE_CLASS_TELAS3SOCKETOPTIONS

SB_INLINE void TElAS3SocketOptions::Assign(TPersistent &Source)
{
	SBCheckError(TElAS3SocketOptions_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElAS3SocketOptions::Assign(TPersistent *Source)
{
	SBCheckError(TElAS3SocketOptions_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_WINDOWS
bool TElAS3SocketOptions::get_UsingIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3SocketOptions_get_UsingIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif

void TElAS3SocketOptions::get_Address(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3SocketOptions_get_Address(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(377118204, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3SocketOptions::set_Address(const std::string &Value)
{
	SBCheckError(TElAS3SocketOptions_set_Address(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElAS3SocketOptions::get_BufferSize()
{
	int32_t OutResult;
	SBCheckError(TElAS3SocketOptions_get_BufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3SocketOptions::set_BufferSize(int32_t Value)
{
	SBCheckError(TElAS3SocketOptions_set_BufferSize(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
TElClientSocketBinding* TElAS3SocketOptions::get_CommandBinding()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3SocketOptions_get_CommandBinding(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CommandBinding)
		this->_Inst_CommandBinding = new TElClientSocketBinding(hOutResult, ohFalse);
	else
		this->_Inst_CommandBinding->updateHandle(hOutResult);
	return this->_Inst_CommandBinding;
}

SB_INLINE void TElAS3SocketOptions::set_CommandBinding(TElClientSocketBinding &Value)
{
	SBCheckError(TElAS3SocketOptions_set_CommandBinding(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS3SocketOptions::set_CommandBinding(TElClientSocketBinding *Value)
{
	SBCheckError(TElAS3SocketOptions_set_CommandBinding(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

SB_INLINE int32_t TElAS3SocketOptions::get_ConcurrentConnections()
{
	int32_t OutResult;
	SBCheckError(TElAS3SocketOptions_get_ConcurrentConnections(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3SocketOptions::set_ConcurrentConnections(int32_t Value)
{
	SBCheckError(TElAS3SocketOptions_set_ConcurrentConnections(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
TElClientSocketBinding* TElAS3SocketOptions::get_DataBinding()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3SocketOptions_get_DataBinding(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DataBinding)
		this->_Inst_DataBinding = new TElClientSocketBinding(hOutResult, ohFalse);
	else
		this->_Inst_DataBinding->updateHandle(hOutResult);
	return this->_Inst_DataBinding;
}

SB_INLINE void TElAS3SocketOptions::set_DataBinding(TElClientSocketBinding &Value)
{
	SBCheckError(TElAS3SocketOptions_set_DataBinding(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS3SocketOptions::set_DataBinding(TElClientSocketBinding *Value)
{
	SBCheckError(TElAS3SocketOptions_set_DataBinding(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
TElDNSSettings* TElAS3SocketOptions::get_DNS()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3SocketOptions_get_DNS(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DNS)
		this->_Inst_DNS = new TElDNSSettings(hOutResult, ohFalse);
	else
		this->_Inst_DNS->updateHandle(hOutResult);
	return this->_Inst_DNS;
}

SB_INLINE void TElAS3SocketOptions::set_DNS(TElDNSSettings &Value)
{
	SBCheckError(TElAS3SocketOptions_set_DNS(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS3SocketOptions::set_DNS(TElDNSSettings *Value)
{
	SBCheckError(TElAS3SocketOptions_set_DNS(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif

SB_INLINE int32_t TElAS3SocketOptions::get_IncomingSpeedLimit()
{
	int32_t OutResult;
	SBCheckError(TElAS3SocketOptions_get_IncomingSpeedLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3SocketOptions::set_IncomingSpeedLimit(int32_t Value)
{
	SBCheckError(TElAS3SocketOptions_set_IncomingSpeedLimit(_Handle, Value));
}

SB_INLINE int32_t TElAS3SocketOptions::get_ListenTimeout()
{
	int32_t OutResult;
	SBCheckError(TElAS3SocketOptions_get_ListenTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3SocketOptions::set_ListenTimeout(int32_t Value)
{
	SBCheckError(TElAS3SocketOptions_set_ListenTimeout(_Handle, Value));
}

SB_INLINE int64_t TElAS3SocketOptions::get_MinSizeForConcurrentDownload()
{
	int64_t OutResult;
	SBCheckError(TElAS3SocketOptions_get_MinSizeForConcurrentDownload(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3SocketOptions::set_MinSizeForConcurrentDownload(int64_t Value)
{
	SBCheckError(TElAS3SocketOptions_set_MinSizeForConcurrentDownload(_Handle, Value));
}

SB_INLINE int32_t TElAS3SocketOptions::get_OutgoingSpeedLimit()
{
	int32_t OutResult;
	SBCheckError(TElAS3SocketOptions_get_OutgoingSpeedLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3SocketOptions::set_OutgoingSpeedLimit(int32_t Value)
{
	SBCheckError(TElAS3SocketOptions_set_OutgoingSpeedLimit(_Handle, Value));
}

SB_INLINE uint16_t TElAS3SocketOptions::get_Port()
{
	uint16_t OutResult;
	SBCheckError(TElAS3SocketOptions_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3SocketOptions::set_Port(uint16_t Value)
{
	SBCheckError(TElAS3SocketOptions_set_Port(_Handle, Value));
}

SB_INLINE int32_t TElAS3SocketOptions::get_Timeout()
{
	int32_t OutResult;
	SBCheckError(TElAS3SocketOptions_get_Timeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3SocketOptions::set_Timeout(int32_t Value)
{
	SBCheckError(TElAS3SocketOptions_set_Timeout(_Handle, Value));
}

SB_INLINE int32_t TElAS3SocketOptions::get_TransferTimeout()
{
	int32_t OutResult;
	SBCheckError(TElAS3SocketOptions_get_TransferTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3SocketOptions::set_TransferTimeout(int32_t Value)
{
	SBCheckError(TElAS3SocketOptions_set_TransferTimeout(_Handle, Value));
#ifdef SB_WINDOWS
}

bool TElAS3SocketOptions::get_UseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3SocketOptions_get_UseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3SocketOptions::set_UseIPv6(bool Value)
{
	SBCheckError(TElAS3SocketOptions_set_UseIPv6(_Handle, (int8_t)Value));
#endif
}

bool TElAS3SocketOptions::get_UseProxyForData()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3SocketOptions_get_UseProxyForData(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3SocketOptions::set_UseProxyForData(bool Value)
{
	SBCheckError(TElAS3SocketOptions_set_UseProxyForData(_Handle, (int8_t)Value));
}

bool TElAS3SocketOptions::get_AutoAdjustBuffersSize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS3SocketOptions_get_AutoAdjustBuffersSize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS3SocketOptions::set_AutoAdjustBuffersSize(bool Value)
{
	SBCheckError(TElAS3SocketOptions_set_AutoAdjustBuffersSize(_Handle, (int8_t)Value));
}

SB_INLINE double TElAS3SocketOptions::get_BuffersAdjustStep()
{
	double OutResult;
	SBCheckError(TElAS3SocketOptions_get_BuffersAdjustStep(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3SocketOptions::set_BuffersAdjustStep(double Value)
{
	SBCheckError(TElAS3SocketOptions_set_BuffersAdjustStep(_Handle, Value));
}

SB_INLINE int32_t TElAS3SocketOptions::get_MaxBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElAS3SocketOptions_get_MaxBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3SocketOptions::set_MaxBufferSize(int32_t Value)
{
	SBCheckError(TElAS3SocketOptions_set_MaxBufferSize(_Handle, Value));
}

SB_INLINE int32_t TElAS3SocketOptions::get_MinBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElAS3SocketOptions_get_MinBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3SocketOptions::set_MinBufferSize(int32_t Value)
{
	SBCheckError(TElAS3SocketOptions_set_MinBufferSize(_Handle, Value));
}

SB_INLINE int32_t TElAS3SocketOptions::get_RecvBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElAS3SocketOptions_get_RecvBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3SocketOptions::set_RecvBufferSize(int32_t Value)
{
	SBCheckError(TElAS3SocketOptions_set_RecvBufferSize(_Handle, Value));
}

SB_INLINE int32_t TElAS3SocketOptions::get_SendBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElAS3SocketOptions_get_SendBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS3SocketOptions::set_SendBufferSize(int32_t Value)
{
	SBCheckError(TElAS3SocketOptions_set_SendBufferSize(_Handle, Value));
}

void TElAS3SocketOptions::initInstances()
{
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	this->_Inst_CommandBinding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	this->_Inst_DataBinding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
	this->_Inst_DNS = NULL;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
}

TElAS3SocketOptions::TElAS3SocketOptions(TElAS3SocketOptionsHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELSIMPLEFTPSCLIENT
TElAS3SocketOptions::TElAS3SocketOptions(TElSimpleFTPSClient &AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS3SocketOptions_Create(AClient.getHandle(), &_Handle));
}

TElAS3SocketOptions::TElAS3SocketOptions(TElSimpleFTPSClient *AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS3SocketOptions_Create((AClient != NULL) ? AClient->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSIMPLEFTPSCLIENT */

TElAS3SocketOptions::~TElAS3SocketOptions()
{
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	delete this->_Inst_CommandBinding;
	this->_Inst_CommandBinding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	delete this->_Inst_DataBinding;
	this->_Inst_DataBinding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
	delete this->_Inst_DNS;
	this->_Inst_DNS = NULL;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
}
#endif /* SB_USE_CLASS_TELAS3SOCKETOPTIONS */

#ifdef SB_USE_CLASS_TELAS3CLIENT

SB_INLINE void TElAS3Client::Abort()
{
	SBCheckError(TElAS3Client_Abort(_Handle));
}

SB_INLINE void TElAS3Client::Acct(const std::string &AcctInfo)
{
	SBCheckError(TElAS3Client_Acct(_Handle, AcctInfo.data(), (int32_t)AcctInfo.length()));
}

SB_INLINE void TElAS3Client::Allocate(int32_t Size)
{
	SBCheckError(TElAS3Client_Allocate(_Handle, Size));
}

SB_INLINE void TElAS3Client::CDUp()
{
	SBCheckError(TElAS3Client_CDUp(_Handle));
}

SB_INLINE void TElAS3Client::ClearCommandChannel()
{
	SBCheckError(TElAS3Client_ClearCommandChannel(_Handle));
}

SB_INLINE void TElAS3Client::ClearCommandChannel(bool GracefulSSLClosure)
{
	SBCheckError(TElAS3Client_ClearCommandChannel_1(_Handle, (int8_t)GracefulSSLClosure));
}

SB_INLINE void TElAS3Client::Close(bool Silent)
{
	SBCheckError(TElAS3Client_Close(_Handle, (int8_t)Silent));
}

SB_INLINE void TElAS3Client::Cwd(const std::string &APath)
{
	SBCheckError(TElAS3Client_Cwd(_Handle, APath.data(), (int32_t)APath.length()));
}

SB_INLINE void TElAS3Client::Delete(const std::string &AFileName)
{
	SBCheckError(TElAS3Client_Delete(_Handle, AFileName.data(), (int32_t)AFileName.length()));
}

void TElAS3Client::GetCurrentDir(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Client_GetCurrentDir(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(280068693, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3Client::GetFileList()
{
	SBCheckError(TElAS3Client_GetFileList(_Handle));
}

SB_INLINE int64_t TElAS3Client::GetFileSize(const std::string &AFileName)
{
	int64_t OutResult;
	SBCheckError(TElAS3Client_GetFileSize(_Handle, AFileName.data(), (int32_t)AFileName.length(), &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElAS3Client::GetFileTime(const std::string &AFileName)
{
	int64_t OutResult;
	SBCheckError(TElAS3Client_GetFileTime(_Handle, AFileName.data(), (int32_t)AFileName.length(), &OutResult));
	return OutResult;
}

void TElAS3Client::GetLocalChecksum(const std::string &AFileName, TSBFTPCheckMethod CheckMethod, int64_t StartPoint, int64_t EndPoint, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Client_GetLocalChecksum(_Handle, AFileName.data(), (int32_t)AFileName.length(), (TSBFTPCheckMethodRaw)CheckMethod, StartPoint, EndPoint, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-193700060, 5, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS3Client::GetNameList()
{
	SBCheckError(TElAS3Client_GetNameList(_Handle));
}

SB_INLINE void TElAS3Client::GetNameList(const std::string &Parameters)
{
	SBCheckError(TElAS3Client_GetNameList_1(_Handle, Parameters.data(), (int32_t)Parameters.length()));
}

void TElAS3Client::GetRemoteChecksum(const std::string &AFileName, TSBFTPCheckMethod CheckMethod, int64_t StartPoint, int64_t EndPoint, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Client_GetRemoteChecksum(_Handle, AFileName.data(), (int32_t)AFileName.length(), (TSBFTPCheckMethodRaw)CheckMethod, StartPoint, EndPoint, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1967914525, 5, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAS3Client::GetServerSystem(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS3Client_GetServerSystem(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1594776398, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAS3Client::InternalValidate(TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason)
{
	TSBCertificateValidityRaw ValidityRaw = (TSBCertificateValidityRaw)Validity;
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	SBCheckError(TElAS3Client_InternalValidate(_Handle, &ValidityRaw, &ReasonRaw));
	Validity = (TSBCertificateValidity)ValidityRaw;
	Reason = (TSBCertificateValidityReason)ReasonRaw;
}

SB_INLINE void TElAS3Client::Login()
{
	SBCheckError(TElAS3Client_Login(_Handle));
}

SB_INLINE void TElAS3Client::MakeDir(const std::string &Path)
{
	SBCheckError(TElAS3Client_MakeDir(_Handle, Path.data(), (int32_t)Path.length()));
}

SB_INLINE void TElAS3Client::MLSD()
{
	SBCheckError(TElAS3Client_MLSD(_Handle));
}

SB_INLINE void TElAS3Client::MountStruct(const std::string &Path)
{
	SBCheckError(TElAS3Client_MountStruct(_Handle, Path.data(), (int32_t)Path.length()));
}

SB_INLINE void TElAS3Client::NoOp()
{
	SBCheckError(TElAS3Client_NoOp(_Handle));
}

SB_INLINE void TElAS3Client::Open()
{
	SBCheckError(TElAS3Client_Open(_Handle));
}

SB_INLINE void TElAS3Client::Receive(const std::string &FileName, int64_t StartPos, int64_t EndPos)
{
	SBCheckError(TElAS3Client_Receive(_Handle, FileName.data(), (int32_t)FileName.length(), StartPos, EndPos));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElAS3Client::Receive(const std::string &FileName, TStream &Stream, int64_t StartPos, int64_t EndPos)
{
	SBCheckError(TElAS3Client_Receive_1(_Handle, FileName.data(), (int32_t)FileName.length(), Stream.getHandle(), StartPos, EndPos));
}

SB_INLINE void TElAS3Client::Receive(const std::string &FileName, TStream *Stream, int64_t StartPos, int64_t EndPos)
{
	SBCheckError(TElAS3Client_Receive_1(_Handle, FileName.data(), (int32_t)FileName.length(), (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, StartPos, EndPos));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElAS3Client::Reinitialize()
{
	SBCheckError(TElAS3Client_Reinitialize(_Handle));
}

SB_INLINE void TElAS3Client::RemoveDir(const std::string &Path)
{
	SBCheckError(TElAS3Client_RemoveDir(_Handle, Path.data(), (int32_t)Path.length()));
}

SB_INLINE void TElAS3Client::Rename(const std::string &SourceFile, const std::string &DestFile)
{
	SBCheckError(TElAS3Client_Rename(_Handle, SourceFile.data(), (int32_t)SourceFile.length(), DestFile.data(), (int32_t)DestFile.length()));
}

SB_INLINE void TElAS3Client::RenegotiateCiphers()
{
	SBCheckError(TElAS3Client_RenegotiateCiphers(_Handle));
}

SB_INLINE int16_t TElAS3Client::SendCmd(const std::string &Command, const std::vector<int16_t> &AcceptCodes)
{
	int16_t OutResult;
	SBCheckError(TElAS3Client_SendCmd(_Handle, Command.data(), (int32_t)Command.length(), SB_STD_VECTOR_FRONT_ADR(AcceptCodes), (int32_t)AcceptCodes.size(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElAS3Client::Send(TStream &Stream, const std::string &FileName, int64_t StartPos, int64_t EndPos, bool Append, int64_t RestartFrom)
{
	SBCheckError(TElAS3Client_Send(_Handle, Stream.getHandle(), FileName.data(), (int32_t)FileName.length(), StartPos, EndPos, (int8_t)Append, RestartFrom));
}

SB_INLINE void TElAS3Client::Send(TStream *Stream, const std::string &FileName, int64_t StartPos, int64_t EndPos, bool Append, int64_t RestartFrom)
{
	SBCheckError(TElAS3Client_Send(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, FileName.data(), (int32_t)FileName.length(), StartPos, EndPos, (int8_t)Append, RestartFrom));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElAS3Client::Send(TStream &Stream, const std::string &FileName, int64_t RestartFrom)
{
	SBCheckError(TElAS3Client_Send_1(_Handle, Stream.getHandle(), FileName.data(), (int32_t)FileName.length(), RestartFrom));
}

SB_INLINE void TElAS3Client::Send(TStream *Stream, const std::string &FileName, int64_t RestartFrom)
{
	SBCheckError(TElAS3Client_Send_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, FileName.data(), (int32_t)FileName.length(), RestartFrom));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElAS3Client::Send(TStream &Stream, const std::string &FileName)
{
	SBCheckError(TElAS3Client_Send_2(_Handle, Stream.getHandle(), FileName.data(), (int32_t)FileName.length()));
}

SB_INLINE void TElAS3Client::Send(TStream *Stream, const std::string &FileName)
{
	SBCheckError(TElAS3Client_Send_2(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, FileName.data(), (int32_t)FileName.length()));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELAS3FTPOPTIONS
TElAS3FTPOptions* TElAS3Client::get_FTP()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3Client_get_FTP(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FTP)
		this->_Inst_FTP = new TElAS3FTPOptions(hOutResult, ohFalse);
	else
		this->_Inst_FTP->updateHandle(hOutResult);
	return this->_Inst_FTP;
}

SB_INLINE void TElAS3Client::set_FTP(TElAS3FTPOptions &Value)
{
	SBCheckError(TElAS3Client_set_FTP(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS3Client::set_FTP(TElAS3FTPOptions *Value)
{
	SBCheckError(TElAS3Client_set_FTP(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAS3FTPOPTIONS */

#ifdef SB_USE_CLASS_TELAS3PROXYOPTIONS
TElAS3ProxyOptions* TElAS3Client::get_Proxy()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3Client_get_Proxy(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Proxy)
		this->_Inst_Proxy = new TElAS3ProxyOptions(hOutResult, ohFalse);
	else
		this->_Inst_Proxy->updateHandle(hOutResult);
	return this->_Inst_Proxy;
}

SB_INLINE void TElAS3Client::set_Proxy(TElAS3ProxyOptions &Value)
{
	SBCheckError(TElAS3Client_set_Proxy(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS3Client::set_Proxy(TElAS3ProxyOptions *Value)
{
	SBCheckError(TElAS3Client_set_Proxy(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAS3PROXYOPTIONS */

#ifdef SB_USE_CLASS_TELAS3SOCKETOPTIONS
TElAS3SocketOptions* TElAS3Client::get_Sockets()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3Client_get_Sockets(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Sockets)
		this->_Inst_Sockets = new TElAS3SocketOptions(hOutResult, ohFalse);
	else
		this->_Inst_Sockets->updateHandle(hOutResult);
	return this->_Inst_Sockets;
}

SB_INLINE void TElAS3Client::set_Sockets(TElAS3SocketOptions &Value)
{
	SBCheckError(TElAS3Client_set_Sockets(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS3Client::set_Sockets(TElAS3SocketOptions *Value)
{
	SBCheckError(TElAS3Client_set_Sockets(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAS3SOCKETOPTIONS */

#ifdef SB_USE_CLASS_TELAS3SOCKSOPTIONS
TElAS3SocksOptions* TElAS3Client::get_Socks()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3Client_get_Socks(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Socks)
		this->_Inst_Socks = new TElAS3SocksOptions(hOutResult, ohFalse);
	else
		this->_Inst_Socks->updateHandle(hOutResult);
	return this->_Inst_Socks;
}

SB_INLINE void TElAS3Client::set_Socks(TElAS3SocksOptions &Value)
{
	SBCheckError(TElAS3Client_set_Socks(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS3Client::set_Socks(TElAS3SocksOptions *Value)
{
	SBCheckError(TElAS3Client_set_Socks(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAS3SOCKSOPTIONS */

#ifdef SB_USE_CLASS_TELAS3SSLOPTIONS
TElAS3SSLOptions* TElAS3Client::get_SSL()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3Client_get_SSL(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SSL)
		this->_Inst_SSL = new TElAS3SSLOptions(hOutResult, ohFalse);
	else
		this->_Inst_SSL->updateHandle(hOutResult);
	return this->_Inst_SSL;
}

SB_INLINE void TElAS3Client::set_SSL(TElAS3SSLOptions &Value)
{
	SBCheckError(TElAS3Client_set_SSL(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS3Client::set_SSL(TElAS3SSLOptions *Value)
{
	SBCheckError(TElAS3Client_set_SSL(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAS3SSLOPTIONS */

#ifdef SB_USE_CLASS_TELAS3WEBTUNNELOPTIONS
TElAS3WebTunnelOptions* TElAS3Client::get_WebTunnel()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS3Client_get_WebTunnel(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_WebTunnel)
		this->_Inst_WebTunnel = new TElAS3WebTunnelOptions(hOutResult, ohFalse);
	else
		this->_Inst_WebTunnel->updateHandle(hOutResult);
	return this->_Inst_WebTunnel;
}

SB_INLINE void TElAS3Client::set_WebTunnel(TElAS3WebTunnelOptions &Value)
{
	SBCheckError(TElAS3Client_set_WebTunnel(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS3Client::set_WebTunnel(TElAS3WebTunnelOptions *Value)
{
	SBCheckError(TElAS3Client_set_WebTunnel(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAS3WEBTUNNELOPTIONS */

SB_INLINE void TElAS3Client::get_OnBinaryData(TSBFTPSBinaryDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Client_get_OnBinaryData(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Client::set_OnBinaryData(TSBFTPSBinaryDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Client_set_OnBinaryData(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Client::get_OnCertificateNeededEx(TSBCertificateNeededExEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Client_get_OnCertificateNeededEx(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Client::set_OnCertificateNeededEx(TSBCertificateNeededExEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Client_set_OnCertificateNeededEx(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Client::get_OnCertificateStatus(TSBCertificateStatusEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Client_get_OnCertificateStatus(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Client::set_OnCertificateStatus(TSBCertificateStatusEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Client_set_OnCertificateStatus(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Client::get_OnCertificateValidate(TSBCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Client_get_OnCertificateValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Client::set_OnCertificateValidate(TSBCertificateValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Client_set_OnCertificateValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Client::get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Client_get_OnCiphersNegotiated(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Client::set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Client_set_OnCiphersNegotiated(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Client::get_OnControlSend(TSBFTPSTextDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Client_get_OnControlSend(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Client::set_OnControlSend(TSBFTPSTextDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Client_set_OnControlSend(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Client::get_OnControlReceive(TSBFTPSTextDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Client_get_OnControlReceive(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Client::set_OnControlReceive(TSBFTPSTextDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Client_set_OnControlReceive(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Client::get_OnError(TSBErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Client_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Client::set_OnError(TSBErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Client_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Client::get_OnExtensionsReceived(TSBExtensionsReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Client_get_OnExtensionsReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Client::set_OnExtensionsReceived(TSBExtensionsReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Client_set_OnExtensionsReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Client::get_OnExtensionsPrepared(TSBExtensionsPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Client_get_OnExtensionsPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Client::set_OnExtensionsPrepared(TSBExtensionsPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Client_set_OnExtensionsPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Client::get_OnInnerClientCreated(TSBFTPSInnerClientEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Client_get_OnInnerClientCreated(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Client::set_OnInnerClientCreated(TSBFTPSInnerClientEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Client_set_OnInnerClientCreated(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Client::get_OnInnerClientDestroyed(TSBFTPSInnerClientEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Client_get_OnInnerClientDestroyed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Client::set_OnInnerClientDestroyed(TSBFTPSInnerClientEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Client_set_OnInnerClientDestroyed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Client::get_OnInnerClientLoggedIn(TSBFTPSInnerClientEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Client_get_OnInnerClientLoggedIn(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Client::set_OnInnerClientLoggedIn(TSBFTPSInnerClientEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Client_set_OnInnerClientLoggedIn(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Client::get_OnKeyNeeded(TSBClientKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Client_get_OnKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Client::set_OnKeyNeeded(TSBClientKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Client_set_OnKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Client::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Client_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Client::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Client_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Client::get_OnTextDataLine(TSBFTPSTextDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Client_get_OnTextDataLine(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Client::set_OnTextDataLine(TSBFTPSTextDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Client_set_OnTextDataLine(_Handle, pMethodValue, pDataValue));
#ifndef SB_WINCE_OR_NOT_WINDOWS
}

SB_INLINE void TElAS3Client::get_OnDNSKeyNeded(TSBDNSKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Client_get_OnDNSKeyNeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Client::set_OnDNSKeyNeded(TSBDNSKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Client_set_OnDNSKeyNeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Client::get_OnDNSKeyValidate(TSBDNSKeyValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Client_get_OnDNSKeyValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Client::set_OnDNSKeyValidate(TSBDNSKeyValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Client_set_OnDNSKeyValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS3Client::get_OnDNSResolve(TSBDNSResolveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS3Client_get_OnDNSResolve(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS3Client::set_OnDNSResolve(TSBDNSResolveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS3Client_set_OnDNSResolve(_Handle, pMethodValue, pDataValue));
#endif
}

void TElAS3Client::initInstances()
{
#ifdef SB_USE_CLASS_TELAS3FTPOPTIONS
	this->_Inst_FTP = NULL;
#endif /* SB_USE_CLASS_TELAS3FTPOPTIONS */
#ifdef SB_USE_CLASS_TELAS3PROXYOPTIONS
	this->_Inst_Proxy = NULL;
#endif /* SB_USE_CLASS_TELAS3PROXYOPTIONS */
#ifdef SB_USE_CLASS_TELAS3SOCKETOPTIONS
	this->_Inst_Sockets = NULL;
#endif /* SB_USE_CLASS_TELAS3SOCKETOPTIONS */
#ifdef SB_USE_CLASS_TELAS3SOCKSOPTIONS
	this->_Inst_Socks = NULL;
#endif /* SB_USE_CLASS_TELAS3SOCKSOPTIONS */
#ifdef SB_USE_CLASS_TELAS3SSLOPTIONS
	this->_Inst_SSL = NULL;
#endif /* SB_USE_CLASS_TELAS3SSLOPTIONS */
#ifdef SB_USE_CLASS_TELAS3WEBTUNNELOPTIONS
	this->_Inst_WebTunnel = NULL;
#endif /* SB_USE_CLASS_TELAS3WEBTUNNELOPTIONS */
}

TElAS3Client::TElAS3Client(TElAS3ClientHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElAS3Client::TElAS3Client(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS3Client_Create(AOwner.getHandle(), &_Handle));
}

TElAS3Client::TElAS3Client(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS3Client_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElAS3Client::~TElAS3Client()
{
#ifdef SB_USE_CLASS_TELAS3FTPOPTIONS
	delete this->_Inst_FTP;
	this->_Inst_FTP = NULL;
#endif /* SB_USE_CLASS_TELAS3FTPOPTIONS */
#ifdef SB_USE_CLASS_TELAS3PROXYOPTIONS
	delete this->_Inst_Proxy;
	this->_Inst_Proxy = NULL;
#endif /* SB_USE_CLASS_TELAS3PROXYOPTIONS */
#ifdef SB_USE_CLASS_TELAS3SOCKETOPTIONS
	delete this->_Inst_Sockets;
	this->_Inst_Sockets = NULL;
#endif /* SB_USE_CLASS_TELAS3SOCKETOPTIONS */
#ifdef SB_USE_CLASS_TELAS3SOCKSOPTIONS
	delete this->_Inst_Socks;
	this->_Inst_Socks = NULL;
#endif /* SB_USE_CLASS_TELAS3SOCKSOPTIONS */
#ifdef SB_USE_CLASS_TELAS3SSLOPTIONS
	delete this->_Inst_SSL;
	this->_Inst_SSL = NULL;
#endif /* SB_USE_CLASS_TELAS3SSLOPTIONS */
#ifdef SB_USE_CLASS_TELAS3WEBTUNNELOPTIONS
	delete this->_Inst_WebTunnel;
	this->_Inst_WebTunnel = NULL;
#endif /* SB_USE_CLASS_TELAS3WEBTUNNELOPTIONS */
}
#endif /* SB_USE_CLASS_TELAS3CLIENT */

#ifdef SB_USE_GLOBAL_PROCS_AS3

bool AS3NameNeedsQuoting(const std::string &AS3Name)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBAS3_AS3NameNeedsQuoting(AS3Name.data(), (int32_t)AS3Name.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void DequoteAS3Name(const std::string &Value, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBAS3_DequoteAS3Name(Value.data(), (int32_t)Value.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1376040812, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void QuoteAS3Name(const std::string &AS3Name, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBAS3_QuoteAS3Name(AS3Name.data(), (int32_t)AS3Name.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1120099780, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool ValidAS3Name(const std::string &Name)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBAS3_ValidAS3Name(Name.data(), (int32_t)Name.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#endif /* SB_USE_GLOBAL_PROCS_AS3 */

};	/* namespace SecureBlackbox */
