#include "sbas2.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELAS2RECEIPTREQUEST

SB_INLINE void TElAS2ReceiptRequest::Assign(TPersistent &Source)
{
	SBCheckError(TElAS2ReceiptRequest_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElAS2ReceiptRequest::Assign(TPersistent *Source)
{
	SBCheckError(TElAS2ReceiptRequest_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

bool TElAS2ReceiptRequest::get_AsyncReceipt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2ReceiptRequest_get_AsyncReceipt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2ReceiptRequest::set_AsyncReceipt(bool Value)
{
	SBCheckError(TElAS2ReceiptRequest_set_AsyncReceipt(_Handle, (int8_t)Value));
}

TSBASSignatureDigestAlgorithm TElAS2ReceiptRequest::get_DigestAlgorithm()
{
	TSBASSignatureDigestAlgorithmRaw OutResultRaw = 0;
	SBCheckError(TElAS2ReceiptRequest_get_DigestAlgorithm(_Handle, &OutResultRaw));
	return (TSBASSignatureDigestAlgorithm)OutResultRaw;
}

SB_INLINE void TElAS2ReceiptRequest::set_DigestAlgorithm(TSBASSignatureDigestAlgorithm Value)
{
	SBCheckError(TElAS2ReceiptRequest_set_DigestAlgorithm(_Handle, (TSBASSignatureDigestAlgorithmRaw)Value));
}

bool TElAS2ReceiptRequest::get_DigestAlgorithmOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2ReceiptRequest_get_DigestAlgorithmOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2ReceiptRequest::set_DigestAlgorithmOnly(bool Value)
{
	SBCheckError(TElAS2ReceiptRequest_set_DigestAlgorithmOnly(_Handle, (int8_t)Value));
}

bool TElAS2ReceiptRequest::get_DigestAlgorithmRequired()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2ReceiptRequest_get_DigestAlgorithmRequired(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2ReceiptRequest::set_DigestAlgorithmRequired(bool Value)
{
	SBCheckError(TElAS2ReceiptRequest_set_DigestAlgorithmRequired(_Handle, (int8_t)Value));
}

bool TElAS2ReceiptRequest::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2ReceiptRequest_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2ReceiptRequest::set_Enabled(bool Value)
{
	SBCheckError(TElAS2ReceiptRequest_set_Enabled(_Handle, (int8_t)Value));
}

bool TElAS2ReceiptRequest::get_SignatureProtocolRequired()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2ReceiptRequest_get_SignatureProtocolRequired(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2ReceiptRequest::set_SignatureProtocolRequired(bool Value)
{
	SBCheckError(TElAS2ReceiptRequest_set_SignatureProtocolRequired(_Handle, (int8_t)Value));
}

bool TElAS2ReceiptRequest::get_Signed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2ReceiptRequest_get_Signed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2ReceiptRequest::set_Signed(bool Value)
{
	SBCheckError(TElAS2ReceiptRequest_set_Signed(_Handle, (int8_t)Value));
}

void TElAS2ReceiptRequest::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2ReceiptRequest_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1761815707, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2ReceiptRequest::set_URL(const std::string &Value)
{
	SBCheckError(TElAS2ReceiptRequest_set_URL(_Handle, Value.data(), (int32_t)Value.length()));
}

TElAS2ReceiptRequest::TElAS2ReceiptRequest(TElAS2ReceiptRequestHandle handle, TElOwnHandle ownHandle) : TElASReceiptRequest(handle, ownHandle)
{
}

TElAS2ReceiptRequest::TElAS2ReceiptRequest() : TElASReceiptRequest(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAS2ReceiptRequest_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELAS2RECEIPTREQUEST */

#ifdef SB_USE_CLASS_TELAS2ENCRYPTION

SB_INLINE int32_t TElAS2Encryption::get_Algorithm()
{
	int32_t OutResult;
	SBCheckError(TElAS2Encryption_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS2Encryption::set_Algorithm(int32_t Value)
{
	SBCheckError(TElAS2Encryption_set_Algorithm(_Handle, Value));
}

bool TElAS2Encryption::get_AlignEncryptedKey()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2Encryption_get_AlignEncryptedKey(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2Encryption::set_AlignEncryptedKey(bool Value)
{
	SBCheckError(TElAS2Encryption_set_AlignEncryptedKey(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElAS2Encryption::get_BitsInKey()
{
	int32_t OutResult;
	SBCheckError(TElAS2Encryption_get_BitsInKey(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS2Encryption::set_BitsInKey(int32_t Value)
{
	SBCheckError(TElAS2Encryption_set_BitsInKey(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElAS2Encryption::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS2Encryption_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElAS2Encryption::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElAS2Encryption_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS2Encryption::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElAS2Encryption_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

bool TElAS2Encryption::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2Encryption_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2Encryption::set_Enabled(bool Value)
{
	SBCheckError(TElAS2Encryption_set_Enabled(_Handle, (int8_t)Value));
}

TSBASEncryptionTransferEncoding TElAS2Encryption::get_Encoding()
{
	TSBASEncryptionTransferEncodingRaw OutResultRaw = 0;
	SBCheckError(TElAS2Encryption_get_Encoding(_Handle, &OutResultRaw));
	return (TSBASEncryptionTransferEncoding)OutResultRaw;
}

SB_INLINE void TElAS2Encryption::set_Encoding(TSBASEncryptionTransferEncoding Value)
{
	SBCheckError(TElAS2Encryption_set_Encoding(_Handle, (TSBASEncryptionTransferEncodingRaw)Value));
}

bool TElAS2Encryption::get_UseUndefSize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2Encryption_get_UseUndefSize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2Encryption::set_UseUndefSize(bool Value)
{
	SBCheckError(TElAS2Encryption_set_UseUndefSize(_Handle, (int8_t)Value));
}

void TElAS2Encryption::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElAS2Encryption::TElAS2Encryption(TElAS2EncryptionHandle handle, TElOwnHandle ownHandle) : TElASSMIMEEncryption(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TCOMPONENT
TElAS2Encryption::TElAS2Encryption(TComponent &AOwner) : TElASSMIMEEncryption(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS2Encryption_Create(AOwner.getHandle(), &_Handle));
}

TElAS2Encryption::TElAS2Encryption(TComponent *AOwner) : TElASSMIMEEncryption(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS2Encryption_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TCOMPONENT */

TElAS2Encryption::~TElAS2Encryption()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELAS2ENCRYPTION */

#ifdef SB_USE_CLASS_TELAS2SIGNATURE

SB_INLINE int32_t TElAS2Signature::get_VerificationResult()
{
	int32_t OutResult;
	SBCheckError(TElAS2Signature_get_VerificationResult(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElAS2Signature::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS2Signature_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElAS2Signature::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElAS2Signature_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS2Signature::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElAS2Signature_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

bool TElAS2Signature::get_Compressed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2Signature_get_Compressed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2Signature::set_Compressed(bool Value)
{
	SBCheckError(TElAS2Signature_set_Compressed(_Handle, (int8_t)Value));
}

TSBASSignatureDigestAlgorithm TElAS2Signature::get_DigestAlgorithm()
{
	TSBASSignatureDigestAlgorithmRaw OutResultRaw = 0;
	SBCheckError(TElAS2Signature_get_DigestAlgorithm(_Handle, &OutResultRaw));
	return (TSBASSignatureDigestAlgorithm)OutResultRaw;
}

SB_INLINE void TElAS2Signature::set_DigestAlgorithm(TSBASSignatureDigestAlgorithm Value)
{
	SBCheckError(TElAS2Signature_set_DigestAlgorithm(_Handle, (TSBASSignatureDigestAlgorithmRaw)Value));
}

bool TElAS2Signature::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2Signature_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2Signature::set_Enabled(bool Value)
{
	SBCheckError(TElAS2Signature_set_Enabled(_Handle, (int8_t)Value));
}

TSBASSignatureTransferEncoding TElAS2Signature::get_Encoding()
{
	TSBASSignatureTransferEncodingRaw OutResultRaw = 0;
	SBCheckError(TElAS2Signature_get_Encoding(_Handle, &OutResultRaw));
	return (TSBASSignatureTransferEncoding)OutResultRaw;
}

SB_INLINE void TElAS2Signature::set_Encoding(TSBASSignatureTransferEncoding Value)
{
	SBCheckError(TElAS2Signature_set_Encoding(_Handle, (TSBASSignatureTransferEncodingRaw)Value));
}

bool TElAS2Signature::get_IncludeChain()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2Signature_get_IncludeChain(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2Signature::set_IncludeChain(bool Value)
{
	SBCheckError(TElAS2Signature_set_IncludeChain(_Handle, (int8_t)Value));
}

SB_INLINE int64_t TElAS2Signature::get_Time()
{
	int64_t OutResult;
	SBCheckError(TElAS2Signature_get_Time(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS2Signature::set_Time(int64_t Value)
{
	SBCheckError(TElAS2Signature_set_Time(_Handle, Value));
}

bool TElAS2Signature::get_UseUndefSize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2Signature_get_UseUndefSize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2Signature::set_UseUndefSize(bool Value)
{
	SBCheckError(TElAS2Signature_set_UseUndefSize(_Handle, (int8_t)Value));
}

TSBASSMIMEVerificationOptions TElAS2Signature::get_VerificationOptions()
{
	TSBASSMIMEVerificationOptionsRaw OutResultRaw = 0;
	SBCheckError(TElAS2Signature_get_VerificationOptions(_Handle, &OutResultRaw));
	return (TSBASSMIMEVerificationOptions)OutResultRaw;
}

SB_INLINE void TElAS2Signature::set_VerificationOptions(TSBASSMIMEVerificationOptions Value)
{
	SBCheckError(TElAS2Signature_set_VerificationOptions(_Handle, (TSBASSMIMEVerificationOptionsRaw)Value));
}

void TElAS2Signature::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElAS2Signature::TElAS2Signature(TElAS2SignatureHandle handle, TElOwnHandle ownHandle) : TElASSMIMESignature(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TCOMPONENT
TElAS2Signature::TElAS2Signature(TComponent &AOwner) : TElASSMIMESignature(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS2Signature_Create(AOwner.getHandle(), &_Handle));
}

TElAS2Signature::TElAS2Signature(TComponent *AOwner) : TElASSMIMESignature(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS2Signature_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TCOMPONENT */

TElAS2Signature::~TElAS2Signature()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELAS2SIGNATURE */

#ifdef SB_USE_CLASS_TELAS2COMPRESSION

bool TElAS2Compression::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2Compression_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2Compression::set_Enabled(bool Value)
{
	SBCheckError(TElAS2Compression_set_Enabled(_Handle, (int8_t)Value));
}

TSBASCompressionTransferEncoding TElAS2Compression::get_Encoding()
{
	TSBASCompressionTransferEncodingRaw OutResultRaw = 0;
	SBCheckError(TElAS2Compression_get_Encoding(_Handle, &OutResultRaw));
	return (TSBASCompressionTransferEncoding)OutResultRaw;
}

SB_INLINE void TElAS2Compression::set_Encoding(TSBASCompressionTransferEncoding Value)
{
	SBCheckError(TElAS2Compression_set_Encoding(_Handle, (TSBASCompressionTransferEncodingRaw)Value));
}

SB_INLINE int32_t TElAS2Compression::get_Level()
{
	int32_t OutResult;
	SBCheckError(TElAS2Compression_get_Level(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS2Compression::set_Level(int32_t Value)
{
	SBCheckError(TElAS2Compression_set_Level(_Handle, Value));
}

TElAS2Compression::TElAS2Compression(TElAS2CompressionHandle handle, TElOwnHandle ownHandle) : TElASSMIMECompression(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TCOMPONENT
TElAS2Compression::TElAS2Compression(TComponent &AOwner) : TElASSMIMECompression(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAS2Compression_Create(AOwner.getHandle(), &_Handle));
}

TElAS2Compression::TElAS2Compression(TComponent *AOwner) : TElASSMIMECompression(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAS2Compression_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TCOMPONENT */

#endif /* SB_USE_CLASS_TELAS2COMPRESSION */

#ifdef SB_USE_CLASS_TELAS2RECEIPT

SB_INLINE void TElAS2Receipt::Assign(TPersistent &Source)
{
	SBCheckError(TElAS2Receipt_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElAS2Receipt::Assign(TPersistent *Source)
{
	SBCheckError(TElAS2Receipt_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELASMESSAGEERRORLIST
TElASMessageErrorList* TElAS2Receipt::get_Errors()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS2Receipt_get_Errors(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Errors)
		this->_Inst_Errors = new TElASMessageErrorList(hOutResult, ohFalse);
	else
		this->_Inst_Errors->updateHandle(hOutResult);
	return this->_Inst_Errors;
}
#endif /* SB_USE_CLASS_TELASMESSAGEERRORLIST */

void TElAS2Receipt::get_ReceivedContentDigest(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElAS2Receipt_get_ReceivedContentDigest(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-820587559, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2Receipt::set_ReceivedContentDigest(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElAS2Receipt_set_ReceivedContentDigest(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TSBASSignatureDigestAlgorithm TElAS2Receipt::get_ReceivedContentDigestAlgorithm()
{
	TSBASSignatureDigestAlgorithmRaw OutResultRaw = 0;
	SBCheckError(TElAS2Receipt_get_ReceivedContentDigestAlgorithm(_Handle, &OutResultRaw));
	return (TSBASSignatureDigestAlgorithm)OutResultRaw;
}

SB_INLINE void TElAS2Receipt::set_ReceivedContentDigestAlgorithm(TSBASSignatureDigestAlgorithm Value)
{
	SBCheckError(TElAS2Receipt_set_ReceivedContentDigestAlgorithm(_Handle, (TSBASSignatureDigestAlgorithmRaw)Value));
}

TSBASDispositionActionMode TElAS2Receipt::get_ActionMode()
{
	TSBASDispositionActionModeRaw OutResultRaw = 0;
	SBCheckError(TElAS2Receipt_get_ActionMode(_Handle, &OutResultRaw));
	return (TSBASDispositionActionMode)OutResultRaw;
}

SB_INLINE void TElAS2Receipt::set_ActionMode(TSBASDispositionActionMode Value)
{
	SBCheckError(TElAS2Receipt_set_ActionMode(_Handle, (TSBASDispositionActionModeRaw)Value));
}

void TElAS2Receipt::get_AS2From(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2Receipt_get_AS2From(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(719293636, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2Receipt::set_AS2From(const std::string &Value)
{
	SBCheckError(TElAS2Receipt_set_AS2From(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS2Receipt::get_AS2To(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2Receipt_get_AS2To(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1815783455, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2Receipt::set_AS2To(const std::string &Value)
{
	SBCheckError(TElAS2Receipt_set_AS2To(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElAS2Receipt::get_Date()
{
	int64_t OutResult;
	SBCheckError(TElAS2Receipt_get_Date(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS2Receipt::set_Date(int64_t Value)
{
	SBCheckError(TElAS2Receipt_set_Date(_Handle, Value));
}

bool TElAS2Receipt::get_DetailedErrors()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2Receipt_get_DetailedErrors(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2Receipt::set_DetailedErrors(bool Value)
{
	SBCheckError(TElAS2Receipt_set_DetailedErrors(_Handle, (int8_t)Value));
}

void TElAS2Receipt::get_FinalRecipient(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2Receipt_get_FinalRecipient(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1499970567, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2Receipt::set_FinalRecipient(const std::string &Value)
{
	SBCheckError(TElAS2Receipt_set_FinalRecipient(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS2Receipt::get_MDNGateway(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2Receipt_get_MDNGateway(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-877759221, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2Receipt::set_MDNGateway(const std::string &Value)
{
	SBCheckError(TElAS2Receipt_set_MDNGateway(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS2Receipt::get_MessageID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2Receipt_get_MessageID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-467119261, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2Receipt::set_MessageID(const std::string &Value)
{
	SBCheckError(TElAS2Receipt_set_MessageID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS2Receipt::get_OriginalMessageID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2Receipt_get_OriginalMessageID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1330619338, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2Receipt::set_OriginalMessageID(const std::string &Value)
{
	SBCheckError(TElAS2Receipt_set_OriginalMessageID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS2Receipt::get_OriginalRecipient(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2Receipt_get_OriginalRecipient(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1192830831, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2Receipt::set_OriginalRecipient(const std::string &Value)
{
	SBCheckError(TElAS2Receipt_set_OriginalRecipient(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS2Receipt::get_ReportCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2Receipt_get_ReportCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1559401123, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2Receipt::set_ReportCharset(const std::string &Value)
{
	SBCheckError(TElAS2Receipt_set_ReportCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBASCharsetMode TElAS2Receipt::get_ReportCharsetMode()
{
	TSBASCharsetModeRaw OutResultRaw = 0;
	SBCheckError(TElAS2Receipt_get_ReportCharsetMode(_Handle, &OutResultRaw));
	return (TSBASCharsetMode)OutResultRaw;
}

SB_INLINE void TElAS2Receipt::set_ReportCharsetMode(TSBASCharsetMode Value)
{
	SBCheckError(TElAS2Receipt_set_ReportCharsetMode(_Handle, (TSBASCharsetModeRaw)Value));
}

TSBASHeaderTransferEncoding TElAS2Receipt::get_ReportEncoding()
{
	TSBASHeaderTransferEncodingRaw OutResultRaw = 0;
	SBCheckError(TElAS2Receipt_get_ReportEncoding(_Handle, &OutResultRaw));
	return (TSBASHeaderTransferEncoding)OutResultRaw;
}

SB_INLINE void TElAS2Receipt::set_ReportEncoding(TSBASHeaderTransferEncoding Value)
{
	SBCheckError(TElAS2Receipt_set_ReportEncoding(_Handle, (TSBASHeaderTransferEncodingRaw)Value));
}

void TElAS2Receipt::get_ReportingUA(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2Receipt_get_ReportingUA(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1146640608, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2Receipt::set_ReportingUA(const std::string &Value)
{
	SBCheckError(TElAS2Receipt_set_ReportingUA(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBASDispositionSendingMode TElAS2Receipt::get_SendingMode()
{
	TSBASDispositionSendingModeRaw OutResultRaw = 0;
	SBCheckError(TElAS2Receipt_get_SendingMode(_Handle, &OutResultRaw));
	return (TSBASDispositionSendingMode)OutResultRaw;
}

SB_INLINE void TElAS2Receipt::set_SendingMode(TSBASDispositionSendingMode Value)
{
	SBCheckError(TElAS2Receipt_set_SendingMode(_Handle, (TSBASDispositionSendingModeRaw)Value));
}

#ifdef SB_USE_CLASS_TELAS2SIGNATURE
TElAS2Signature* TElAS2Receipt::get_Signature()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS2Receipt_get_Signature(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signature)
		this->_Inst_Signature = new TElAS2Signature(hOutResult, ohFalse);
	else
		this->_Inst_Signature->updateHandle(hOutResult);
	return this->_Inst_Signature;
}

SB_INLINE void TElAS2Receipt::set_Signature(TElAS2Signature &Value)
{
	SBCheckError(TElAS2Receipt_set_Signature(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS2Receipt::set_Signature(TElAS2Signature *Value)
{
	SBCheckError(TElAS2Receipt_set_Signature(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAS2SIGNATURE */

bool TElAS2Receipt::get_SortErrors()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2Receipt_get_SortErrors(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2Receipt::set_SortErrors(bool Value)
{
	SBCheckError(TElAS2Receipt_set_SortErrors(_Handle, (int8_t)Value));
}

void TElAS2Receipt::get_Subject(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2Receipt_get_Subject(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(137063036, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElAS2Receipt::get_Subject(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElAS2Receipt_get_Subject(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(137063036, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElAS2Receipt::set_Subject(const sb_u16string &Value)
{
	SBCheckError(TElAS2Receipt_set_Subject(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElAS2Receipt::set_Subject(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElAS2Receipt_set_Subject(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElAS2Receipt::get_Text(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2Receipt_get_Text(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1256475635, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElAS2Receipt::get_Text(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElAS2Receipt_get_Text(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1256475635, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElAS2Receipt::set_Text(const sb_u16string &Value)
{
	SBCheckError(TElAS2Receipt_set_Text(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElAS2Receipt::set_Text(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElAS2Receipt_set_Text(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElAS2Receipt::get_TextCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2Receipt_get_TextCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-192861350, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2Receipt::set_TextCharset(const std::string &Value)
{
	SBCheckError(TElAS2Receipt_set_TextCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBASCharsetMode TElAS2Receipt::get_TextCharsetMode()
{
	TSBASCharsetModeRaw OutResultRaw = 0;
	SBCheckError(TElAS2Receipt_get_TextCharsetMode(_Handle, &OutResultRaw));
	return (TSBASCharsetMode)OutResultRaw;
}

SB_INLINE void TElAS2Receipt::set_TextCharsetMode(TSBASCharsetMode Value)
{
	SBCheckError(TElAS2Receipt_set_TextCharsetMode(_Handle, (TSBASCharsetModeRaw)Value));
}

void TElAS2Receipt::get_TextContentType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2Receipt_get_TextContentType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1869907237, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2Receipt::set_TextContentType(const std::string &Value)
{
	SBCheckError(TElAS2Receipt_set_TextContentType(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBASHeaderTransferEncoding TElAS2Receipt::get_TextEncoding()
{
	TSBASHeaderTransferEncodingRaw OutResultRaw = 0;
	SBCheckError(TElAS2Receipt_get_TextEncoding(_Handle, &OutResultRaw));
	return (TSBASHeaderTransferEncoding)OutResultRaw;
}

SB_INLINE void TElAS2Receipt::set_TextEncoding(TSBASHeaderTransferEncoding Value)
{
	SBCheckError(TElAS2Receipt_set_TextEncoding(_Handle, (TSBASHeaderTransferEncodingRaw)Value));
}

bool TElAS2Receipt::get_UseFolding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2Receipt_get_UseFolding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2Receipt::set_UseFolding(bool Value)
{
	SBCheckError(TElAS2Receipt_set_UseFolding(_Handle, (int8_t)Value));
}

TSBAS2Version TElAS2Receipt::get_Version()
{
	TSBAS2VersionRaw OutResultRaw = 0;
	SBCheckError(TElAS2Receipt_get_Version(_Handle, &OutResultRaw));
	return (TSBAS2Version)OutResultRaw;
}

SB_INLINE void TElAS2Receipt::set_Version(TSBAS2Version Value)
{
	SBCheckError(TElAS2Receipt_set_Version(_Handle, (TSBAS2VersionRaw)Value));
}

SB_INLINE void TElAS2Receipt::get_OnError(TSBASReceiptErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Receipt_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Receipt::set_OnError(TSBASReceiptErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Receipt_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Receipt::get_OnHeaderAssembled(TSBASHeaderEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Receipt_get_OnHeaderAssembled(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Receipt::set_OnHeaderAssembled(TSBASHeaderEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Receipt_set_OnHeaderAssembled(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Receipt::get_OnHeaderParsed(TSBASHeaderEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Receipt_get_OnHeaderParsed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Receipt::set_OnHeaderParsed(TSBASHeaderEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Receipt_set_OnHeaderParsed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Receipt::get_OnSign(TSBASMessageSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Receipt_get_OnSign(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Receipt::set_OnSign(TSBASMessageSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Receipt_set_OnSign(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Receipt::get_OnSigning(TSBASMessageSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Receipt_get_OnSigning(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Receipt::set_OnSigning(TSBASMessageSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Receipt_set_OnSigning(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Receipt::get_OnStepStart(TSBASProcessingStepStart &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Receipt_get_OnStepStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Receipt::set_OnStepStart(TSBASProcessingStepStart pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Receipt_set_OnStepStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Receipt::get_OnVerify(TSBASMessageVerifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Receipt_get_OnVerify(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Receipt::set_OnVerify(TSBASMessageVerifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Receipt_set_OnVerify(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Receipt::get_OnVerifyIDs(TSBASMessageVerifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Receipt_get_OnVerifyIDs(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Receipt::set_OnVerifyIDs(TSBASMessageVerifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Receipt_set_OnVerifyIDs(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Receipt::get_OnVerifying(TSBASMessageVerifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Receipt_get_OnVerifying(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Receipt::set_OnVerifying(TSBASMessageVerifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Receipt_set_OnVerifying(_Handle, pMethodValue, pDataValue));
}

void TElAS2Receipt::initInstances()
{
#ifdef SB_USE_CLASS_TELASMESSAGEERRORLIST
	this->_Inst_Errors = NULL;
#endif /* SB_USE_CLASS_TELASMESSAGEERRORLIST */
#ifdef SB_USE_CLASS_TELAS2SIGNATURE
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELAS2SIGNATURE */
}

TElAS2Receipt::TElAS2Receipt(TElAS2ReceiptHandle handle, TElOwnHandle ownHandle) : TElASReceipt(handle, ownHandle)
{
	initInstances();
}

TElAS2Receipt::TElAS2Receipt(TComponent &AOwner) : TElASReceipt(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS2Receipt_Create(AOwner.getHandle(), &_Handle));
}

TElAS2Receipt::TElAS2Receipt(TComponent *AOwner) : TElASReceipt(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS2Receipt_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElAS2Receipt::~TElAS2Receipt()
{
#ifdef SB_USE_CLASS_TELASMESSAGEERRORLIST
	delete this->_Inst_Errors;
	this->_Inst_Errors = NULL;
#endif /* SB_USE_CLASS_TELASMESSAGEERRORLIST */
#ifdef SB_USE_CLASS_TELAS2SIGNATURE
	delete this->_Inst_Signature;
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELAS2SIGNATURE */
}
#endif /* SB_USE_CLASS_TELAS2RECEIPT */

#ifdef SB_USE_CLASS_TELAS2MESSAGE

SB_INLINE void TElAS2Message::Assign(TPersistent &Source)
{
	SBCheckError(TElAS2Message_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElAS2Message::Assign(TPersistent *Source)
{
	SBCheckError(TElAS2Message_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

bool TElAS2Message::get_Cancelled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2Message_get_Cancelled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElAS2Message::get_ContentDigest(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElAS2Message_get_ContentDigest(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(394668946, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBASSignatureDigestAlgorithm TElAS2Message::get_ContentDigestAlgorithm()
{
	TSBASSignatureDigestAlgorithmRaw OutResultRaw = 0;
	SBCheckError(TElAS2Message_get_ContentDigestAlgorithm(_Handle, &OutResultRaw));
	return (TSBASSignatureDigestAlgorithm)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELASMESSAGEERRORLIST
TElASMessageErrorList* TElAS2Message::get_Errors()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS2Message_get_Errors(_Handle, &hOutResult));
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
TStringList* TElAS2Message::get_Features()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS2Message_get_Features(_Handle, &hOutResult));
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
TElStringList* TElAS2Message::get_Features()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS2Message_get_Features(_Handle, &hOutResult));
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

void TElAS2Message::get_AS2From(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2Message_get_AS2From(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2105723507, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2Message::set_AS2From(const std::string &Value)
{
	SBCheckError(TElAS2Message_set_AS2From(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS2Message::get_AS2To(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2Message_get_AS2To(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(704652855, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2Message::set_AS2To(const std::string &Value)
{
	SBCheckError(TElAS2Message_set_AS2To(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS2Message::get_Charset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2Message_get_Charset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(454876324, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2Message::set_Charset(const std::string &Value)
{
	SBCheckError(TElAS2Message_set_Charset(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBASCharsetMode TElAS2Message::get_CharsetMode()
{
	TSBASCharsetModeRaw OutResultRaw = 0;
	SBCheckError(TElAS2Message_get_CharsetMode(_Handle, &OutResultRaw));
	return (TSBASCharsetMode)OutResultRaw;
}

SB_INLINE void TElAS2Message::set_CharsetMode(TSBASCharsetMode Value)
{
	SBCheckError(TElAS2Message_set_CharsetMode(_Handle, (TSBASCharsetModeRaw)Value));
}

#ifdef SB_USE_CLASS_TELAS2COMPRESSION
TElAS2Compression* TElAS2Message::get_Compression()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS2Message_get_Compression(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Compression)
		this->_Inst_Compression = new TElAS2Compression(hOutResult, ohFalse);
	else
		this->_Inst_Compression->updateHandle(hOutResult);
	return this->_Inst_Compression;
}

SB_INLINE void TElAS2Message::set_Compression(TElAS2Compression &Value)
{
	SBCheckError(TElAS2Message_set_Compression(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS2Message::set_Compression(TElAS2Compression *Value)
{
	SBCheckError(TElAS2Message_set_Compression(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAS2COMPRESSION */

void TElAS2Message::get_ContentType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2Message_get_ContentType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1293716060, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2Message::set_ContentType(const std::string &Value)
{
	SBCheckError(TElAS2Message_set_ContentType(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBASDataTransferEncoding TElAS2Message::get_DataEncoding()
{
	TSBASDataTransferEncodingRaw OutResultRaw = 0;
	SBCheckError(TElAS2Message_get_DataEncoding(_Handle, &OutResultRaw));
	return (TSBASDataTransferEncoding)OutResultRaw;
}

SB_INLINE void TElAS2Message::set_DataEncoding(TSBASDataTransferEncoding Value)
{
	SBCheckError(TElAS2Message_set_DataEncoding(_Handle, (TSBASDataTransferEncodingRaw)Value));
}

SB_INLINE int64_t TElAS2Message::get_Date()
{
	int64_t OutResult;
	SBCheckError(TElAS2Message_get_Date(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS2Message::set_Date(int64_t Value)
{
	SBCheckError(TElAS2Message_set_Date(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELAS2ENCRYPTION
TElAS2Encryption* TElAS2Message::get_Encryption()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS2Message_get_Encryption(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Encryption)
		this->_Inst_Encryption = new TElAS2Encryption(hOutResult, ohFalse);
	else
		this->_Inst_Encryption->updateHandle(hOutResult);
	return this->_Inst_Encryption;
}

SB_INLINE void TElAS2Message::set_Encryption(TElAS2Encryption &Value)
{
	SBCheckError(TElAS2Message_set_Encryption(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS2Message::set_Encryption(TElAS2Encryption *Value)
{
	SBCheckError(TElAS2Message_set_Encryption(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAS2ENCRYPTION */

SB_INLINE int64_t TElAS2Message::get_FileCreated()
{
	int64_t OutResult;
	SBCheckError(TElAS2Message_get_FileCreated(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS2Message::set_FileCreated(int64_t Value)
{
	SBCheckError(TElAS2Message_set_FileCreated(_Handle, Value));
}

SB_INLINE int64_t TElAS2Message::get_FileModified()
{
	int64_t OutResult;
	SBCheckError(TElAS2Message_get_FileModified(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS2Message::set_FileModified(int64_t Value)
{
	SBCheckError(TElAS2Message_set_FileModified(_Handle, Value));
}

void TElAS2Message::get_FileName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2Message_get_FileName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-218524962, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElAS2Message::get_FileName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElAS2Message_get_FileName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-218524962, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElAS2Message::set_FileName(const sb_u16string &Value)
{
	SBCheckError(TElAS2Message_set_FileName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElAS2Message::set_FileName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElAS2Message_set_FileName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TSBASHeaderTransferEncoding TElAS2Message::get_HeaderEncoding()
{
	TSBASHeaderTransferEncodingRaw OutResultRaw = 0;
	SBCheckError(TElAS2Message_get_HeaderEncoding(_Handle, &OutResultRaw));
	return (TSBASHeaderTransferEncoding)OutResultRaw;
}

SB_INLINE void TElAS2Message::set_HeaderEncoding(TSBASHeaderTransferEncoding Value)
{
	SBCheckError(TElAS2Message_set_HeaderEncoding(_Handle, (TSBASHeaderTransferEncodingRaw)Value));
}

bool TElAS2Message::get_IgnoreFileWarnings()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2Message_get_IgnoreFileWarnings(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2Message::set_IgnoreFileWarnings(bool Value)
{
	SBCheckError(TElAS2Message_set_IgnoreFileWarnings(_Handle, (int8_t)Value));
}

void TElAS2Message::get_MessageID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2Message_get_MessageID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-804005660, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2Message::set_MessageID(const std::string &Value)
{
	SBCheckError(TElAS2Message_set_MessageID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELAS2RECEIPTREQUEST
TElAS2ReceiptRequest* TElAS2Message::get_ReceiptRequest()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS2Message_get_ReceiptRequest(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ReceiptRequest)
		this->_Inst_ReceiptRequest = new TElAS2ReceiptRequest(hOutResult, ohFalse);
	else
		this->_Inst_ReceiptRequest->updateHandle(hOutResult);
	return this->_Inst_ReceiptRequest;
}

SB_INLINE void TElAS2Message::set_ReceiptRequest(TElAS2ReceiptRequest &Value)
{
	SBCheckError(TElAS2Message_set_ReceiptRequest(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS2Message::set_ReceiptRequest(TElAS2ReceiptRequest *Value)
{
	SBCheckError(TElAS2Message_set_ReceiptRequest(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAS2RECEIPTREQUEST */

#ifdef SB_USE_CLASS_TELAS2SIGNATURE
TElAS2Signature* TElAS2Message::get_Signature()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS2Message_get_Signature(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signature)
		this->_Inst_Signature = new TElAS2Signature(hOutResult, ohFalse);
	else
		this->_Inst_Signature->updateHandle(hOutResult);
	return this->_Inst_Signature;
}

SB_INLINE void TElAS2Message::set_Signature(TElAS2Signature &Value)
{
	SBCheckError(TElAS2Message_set_Signature(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS2Message::set_Signature(TElAS2Signature *Value)
{
	SBCheckError(TElAS2Message_set_Signature(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAS2SIGNATURE */

void TElAS2Message::get_Subject(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2Message_get_Subject(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1601580235, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElAS2Message::get_Subject(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElAS2Message_get_Subject(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1601580235, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElAS2Message::set_Subject(const sb_u16string &Value)
{
	SBCheckError(TElAS2Message_set_Subject(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElAS2Message::set_Subject(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElAS2Message_set_Subject(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
bool TElAS2Message::get_UseFolding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2Message_get_UseFolding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2Message::set_UseFolding(bool Value)
{
	SBCheckError(TElAS2Message_set_UseFolding(_Handle, (int8_t)Value));
}

TSBAS2Version TElAS2Message::get_Version()
{
	TSBAS2VersionRaw OutResultRaw = 0;
	SBCheckError(TElAS2Message_get_Version(_Handle, &OutResultRaw));
	return (TSBAS2Version)OutResultRaw;
}

SB_INLINE void TElAS2Message::set_Version(TSBAS2Version Value)
{
	SBCheckError(TElAS2Message_set_Version(_Handle, (TSBAS2VersionRaw)Value));
}

SB_INLINE void TElAS2Message::get_OnDecrypt(TSBASMessageDecryptEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Message_get_OnDecrypt(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Message::set_OnDecrypt(TSBASMessageDecryptEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Message_set_OnDecrypt(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Message::get_OnDecryptIDs(TSBASMessageDecryptEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Message_get_OnDecryptIDs(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Message::set_OnDecryptIDs(TSBASMessageDecryptEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Message_set_OnDecryptIDs(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Message::get_OnDecrypting(TSBASMessageDecryptEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Message_get_OnDecrypting(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Message::set_OnDecrypting(TSBASMessageDecryptEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Message_set_OnDecrypting(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Message::get_OnEncrypt(TSBASMessageEncryptEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Message_get_OnEncrypt(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Message::set_OnEncrypt(TSBASMessageEncryptEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Message_set_OnEncrypt(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Message::get_OnEncrypting(TSBASMessageEncryptEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Message_get_OnEncrypting(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Message::set_OnEncrypting(TSBASMessageEncryptEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Message_set_OnEncrypting(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Message::get_OnError(TSBASMessageErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Message_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Message::set_OnError(TSBASMessageErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Message_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Message::get_OnHeaderAssembled(TSBASHeaderEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Message_get_OnHeaderAssembled(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Message::set_OnHeaderAssembled(TSBASHeaderEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Message_set_OnHeaderAssembled(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Message::get_OnHeaderParsed(TSBASHeaderEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Message_get_OnHeaderParsed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Message::set_OnHeaderParsed(TSBASHeaderEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Message_set_OnHeaderParsed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Message::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Message_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Message::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Message_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Message::get_OnSign(TSBASMessageSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Message_get_OnSign(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Message::set_OnSign(TSBASMessageSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Message_set_OnSign(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Message::get_OnSigning(TSBASMessageSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Message_get_OnSigning(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Message::set_OnSigning(TSBASMessageSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Message_set_OnSigning(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Message::get_OnStepStart(TSBASProcessingStepStart &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Message_get_OnStepStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Message::set_OnStepStart(TSBASProcessingStepStart pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Message_set_OnStepStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Message::get_OnTempRelease(TSBASStreamReleaseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Message_get_OnTempRelease(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Message::set_OnTempRelease(TSBASStreamReleaseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Message_set_OnTempRelease(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Message::get_OnTempRequest(TSBASStreamRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Message_get_OnTempRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Message::set_OnTempRequest(TSBASStreamRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Message_set_OnTempRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Message::get_OnVerify(TSBASMessageVerifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Message_get_OnVerify(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Message::set_OnVerify(TSBASMessageVerifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Message_set_OnVerify(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Message::get_OnVerifyIDs(TSBASMessageVerifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Message_get_OnVerifyIDs(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Message::set_OnVerifyIDs(TSBASMessageVerifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Message_set_OnVerifyIDs(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Message::get_OnVerifying(TSBASMessageVerifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Message_get_OnVerifying(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Message::set_OnVerifying(TSBASMessageVerifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Message_set_OnVerifying(_Handle, pMethodValue, pDataValue));
}

void TElAS2Message::initInstances()
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
#ifdef SB_USE_CLASS_TELAS2COMPRESSION
	this->_Inst_Compression = NULL;
#endif /* SB_USE_CLASS_TELAS2COMPRESSION */
#ifdef SB_USE_CLASS_TELAS2ENCRYPTION
	this->_Inst_Encryption = NULL;
#endif /* SB_USE_CLASS_TELAS2ENCRYPTION */
#ifdef SB_USE_CLASS_TELAS2RECEIPTREQUEST
	this->_Inst_ReceiptRequest = NULL;
#endif /* SB_USE_CLASS_TELAS2RECEIPTREQUEST */
#ifdef SB_USE_CLASS_TELAS2SIGNATURE
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELAS2SIGNATURE */
}

TElAS2Message::TElAS2Message(TElAS2MessageHandle handle, TElOwnHandle ownHandle) : TElASMessage(handle, ownHandle)
{
	initInstances();
}

TElAS2Message::TElAS2Message(TComponent &AOwner) : TElASMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS2Message_Create(AOwner.getHandle(), &_Handle));
}

TElAS2Message::TElAS2Message(TComponent *AOwner) : TElASMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS2Message_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElAS2Message::~TElAS2Message()
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
#ifdef SB_USE_CLASS_TELAS2COMPRESSION
	delete this->_Inst_Compression;
	this->_Inst_Compression = NULL;
#endif /* SB_USE_CLASS_TELAS2COMPRESSION */
#ifdef SB_USE_CLASS_TELAS2ENCRYPTION
	delete this->_Inst_Encryption;
	this->_Inst_Encryption = NULL;
#endif /* SB_USE_CLASS_TELAS2ENCRYPTION */
#ifdef SB_USE_CLASS_TELAS2RECEIPTREQUEST
	delete this->_Inst_ReceiptRequest;
	this->_Inst_ReceiptRequest = NULL;
#endif /* SB_USE_CLASS_TELAS2RECEIPTREQUEST */
#ifdef SB_USE_CLASS_TELAS2SIGNATURE
	delete this->_Inst_Signature;
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELAS2SIGNATURE */
}
#endif /* SB_USE_CLASS_TELAS2MESSAGE */

#ifdef SB_USE_CLASS_TELAS2HTTPOPTIONS

SB_INLINE void TElAS2HTTPOptions::Assign(TPersistent &Source)
{
	SBCheckError(TElAS2HTTPOptions_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElAS2HTTPOptions::Assign(TPersistent *Source)
{
	SBCheckError(TElAS2HTTPOptions_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

TSBHTTPKeepAlivePolicy TElAS2HTTPOptions::get_KeepAlivePolicy()
{
	TSBHTTPKeepAlivePolicyRaw OutResultRaw = 0;
	SBCheckError(TElAS2HTTPOptions_get_KeepAlivePolicy(_Handle, &OutResultRaw));
	return (TSBHTTPKeepAlivePolicy)OutResultRaw;
}

SB_INLINE void TElAS2HTTPOptions::set_KeepAlivePolicy(TSBHTTPKeepAlivePolicy Value)
{
	SBCheckError(TElAS2HTTPOptions_set_KeepAlivePolicy(_Handle, (TSBHTTPKeepAlivePolicyRaw)Value));
}

SB_INLINE int32_t TElAS2HTTPOptions::get_MaxRedirections()
{
	int32_t OutResult;
	SBCheckError(TElAS2HTTPOptions_get_MaxRedirections(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS2HTTPOptions::set_MaxRedirections(int32_t Value)
{
	SBCheckError(TElAS2HTTPOptions_set_MaxRedirections(_Handle, Value));
}

void TElAS2HTTPOptions::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2HTTPOptions_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-847014922, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2HTTPOptions::set_Password(const std::string &Value)
{
	SBCheckError(TElAS2HTTPOptions_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElAS2HTTPOptions::get_UseCompression()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2HTTPOptions_get_UseCompression(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2HTTPOptions::set_UseCompression(bool Value)
{
	SBCheckError(TElAS2HTTPOptions_set_UseCompression(_Handle, (int8_t)Value));
}

bool TElAS2HTTPOptions::get_UseDigestAuth()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2HTTPOptions_get_UseDigestAuth(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2HTTPOptions::set_UseDigestAuth(bool Value)
{
	SBCheckError(TElAS2HTTPOptions_set_UseDigestAuth(_Handle, (int8_t)Value));
}

#ifndef SB_WINCE_OR_NOT_WINDOWS
bool TElAS2HTTPOptions::get_UseNTLMAuth()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2HTTPOptions_get_UseNTLMAuth(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2HTTPOptions::set_UseNTLMAuth(bool Value)
{
	SBCheckError(TElAS2HTTPOptions_set_UseNTLMAuth(_Handle, (int8_t)Value));
}
#endif

void TElAS2HTTPOptions::get_UserAgent(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2HTTPOptions_get_UserAgent(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1334620063, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2HTTPOptions::set_UserAgent(const std::string &Value)
{
	SBCheckError(TElAS2HTTPOptions_set_UserAgent(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS2HTTPOptions::get_UserName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2HTTPOptions_get_UserName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1607631766, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2HTTPOptions::set_UserName(const std::string &Value)
{
	SBCheckError(TElAS2HTTPOptions_set_UserName(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBHTTPVersion TElAS2HTTPOptions::get_Version()
{
	TSBHTTPVersionRaw OutResultRaw = 0;
	SBCheckError(TElAS2HTTPOptions_get_Version(_Handle, &OutResultRaw));
	return (TSBHTTPVersion)OutResultRaw;
}

SB_INLINE void TElAS2HTTPOptions::set_Version(TSBHTTPVersion Value)
{
	SBCheckError(TElAS2HTTPOptions_set_Version(_Handle, (TSBHTTPVersionRaw)Value));
}

TElAS2HTTPOptions::TElAS2HTTPOptions(TElAS2HTTPOptionsHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
TElAS2HTTPOptions::TElAS2HTTPOptions(TElHTTPSClient &AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAS2HTTPOptions_Create(AClient.getHandle(), &_Handle));
}

TElAS2HTTPOptions::TElAS2HTTPOptions(TElHTTPSClient *AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAS2HTTPOptions_Create((AClient != NULL) ? AClient->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

#endif /* SB_USE_CLASS_TELAS2HTTPOPTIONS */

#ifdef SB_USE_CLASS_TELAS2PROXYOPTIONS

SB_INLINE void TElAS2ProxyOptions::Assign(TPersistent &Source)
{
	SBCheckError(TElAS2ProxyOptions_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElAS2ProxyOptions::Assign(TPersistent *Source)
{
	SBCheckError(TElAS2ProxyOptions_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

bool TElAS2ProxyOptions::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2ProxyOptions_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2ProxyOptions::set_Enabled(bool Value)
{
	SBCheckError(TElAS2ProxyOptions_set_Enabled(_Handle, (int8_t)Value));
}

void TElAS2ProxyOptions::get_Host(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2ProxyOptions_get_Host(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-188581407, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2ProxyOptions::set_Host(const std::string &Value)
{
	SBCheckError(TElAS2ProxyOptions_set_Host(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS2ProxyOptions::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2ProxyOptions_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-653536875, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2ProxyOptions::set_Password(const std::string &Value)
{
	SBCheckError(TElAS2ProxyOptions_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElAS2ProxyOptions::get_Port()
{
	int32_t OutResult;
	SBCheckError(TElAS2ProxyOptions_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS2ProxyOptions::set_Port(int32_t Value)
{
	SBCheckError(TElAS2ProxyOptions_set_Port(_Handle, Value));
}

void TElAS2ProxyOptions::get_UserName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2ProxyOptions_get_UserName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1264239095, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2ProxyOptions::set_UserName(const std::string &Value)
{
	SBCheckError(TElAS2ProxyOptions_set_UserName(_Handle, Value.data(), (int32_t)Value.length()));
}

TElAS2ProxyOptions::TElAS2ProxyOptions(TElAS2ProxyOptionsHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
TElAS2ProxyOptions::TElAS2ProxyOptions(TElHTTPSClient &AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAS2ProxyOptions_Create(AClient.getHandle(), &_Handle));
}

TElAS2ProxyOptions::TElAS2ProxyOptions(TElHTTPSClient *AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAS2ProxyOptions_Create((AClient != NULL) ? AClient->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

#endif /* SB_USE_CLASS_TELAS2PROXYOPTIONS */

#ifdef SB_USE_CLASS_TELAS2SOCKETOPTIONS

SB_INLINE void TElAS2SocketOptions::Assign(TPersistent &Source)
{
	SBCheckError(TElAS2SocketOptions_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElAS2SocketOptions::Assign(TPersistent *Source)
{
	SBCheckError(TElAS2SocketOptions_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_WINDOWS
bool TElAS2SocketOptions::get_UsingIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2SocketOptions_get_UsingIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
TElClientSocketBinding* TElAS2SocketOptions::get_Binding()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS2SocketOptions_get_Binding(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Binding)
		this->_Inst_Binding = new TElClientSocketBinding(hOutResult, ohFalse);
	else
		this->_Inst_Binding->updateHandle(hOutResult);
	return this->_Inst_Binding;
}

SB_INLINE void TElAS2SocketOptions::set_Binding(TElClientSocketBinding &Value)
{
	SBCheckError(TElAS2SocketOptions_set_Binding(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS2SocketOptions::set_Binding(TElClientSocketBinding *Value)
{
	SBCheckError(TElAS2SocketOptions_set_Binding(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
TElDNSSettings* TElAS2SocketOptions::get_DNS()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS2SocketOptions_get_DNS(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DNS)
		this->_Inst_DNS = new TElDNSSettings(hOutResult, ohFalse);
	else
		this->_Inst_DNS->updateHandle(hOutResult);
	return this->_Inst_DNS;
}

SB_INLINE void TElAS2SocketOptions::set_DNS(TElDNSSettings &Value)
{
	SBCheckError(TElAS2SocketOptions_set_DNS(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS2SocketOptions::set_DNS(TElDNSSettings *Value)
{
	SBCheckError(TElAS2SocketOptions_set_DNS(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif

SB_INLINE int32_t TElAS2SocketOptions::get_IncomingSpeedLimit()
{
	int32_t OutResult;
	SBCheckError(TElAS2SocketOptions_get_IncomingSpeedLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS2SocketOptions::set_IncomingSpeedLimit(int32_t Value)
{
	SBCheckError(TElAS2SocketOptions_set_IncomingSpeedLimit(_Handle, Value));
}

SB_INLINE int32_t TElAS2SocketOptions::get_OutgoingSpeedLimit()
{
	int32_t OutResult;
	SBCheckError(TElAS2SocketOptions_get_OutgoingSpeedLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS2SocketOptions::set_OutgoingSpeedLimit(int32_t Value)
{
	SBCheckError(TElAS2SocketOptions_set_OutgoingSpeedLimit(_Handle, Value));
}

SB_INLINE int32_t TElAS2SocketOptions::get_Timeout()
{
	int32_t OutResult;
	SBCheckError(TElAS2SocketOptions_get_Timeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS2SocketOptions::set_Timeout(int32_t Value)
{
	SBCheckError(TElAS2SocketOptions_set_Timeout(_Handle, Value));
}

#ifdef SB_WINDOWS
bool TElAS2SocketOptions::get_UseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2SocketOptions_get_UseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2SocketOptions::set_UseIPv6(bool Value)
{
	SBCheckError(TElAS2SocketOptions_set_UseIPv6(_Handle, (int8_t)Value));
}
#endif

bool TElAS2SocketOptions::get_AutoAdjustBuffersSize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2SocketOptions_get_AutoAdjustBuffersSize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2SocketOptions::set_AutoAdjustBuffersSize(bool Value)
{
	SBCheckError(TElAS2SocketOptions_set_AutoAdjustBuffersSize(_Handle, (int8_t)Value));
}

SB_INLINE double TElAS2SocketOptions::get_BuffersAdjustStep()
{
	double OutResult;
	SBCheckError(TElAS2SocketOptions_get_BuffersAdjustStep(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS2SocketOptions::set_BuffersAdjustStep(double Value)
{
	SBCheckError(TElAS2SocketOptions_set_BuffersAdjustStep(_Handle, Value));
}

SB_INLINE int32_t TElAS2SocketOptions::get_MaxBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElAS2SocketOptions_get_MaxBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS2SocketOptions::set_MaxBufferSize(int32_t Value)
{
	SBCheckError(TElAS2SocketOptions_set_MaxBufferSize(_Handle, Value));
}

SB_INLINE int32_t TElAS2SocketOptions::get_MinBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElAS2SocketOptions_get_MinBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS2SocketOptions::set_MinBufferSize(int32_t Value)
{
	SBCheckError(TElAS2SocketOptions_set_MinBufferSize(_Handle, Value));
}

SB_INLINE int32_t TElAS2SocketOptions::get_RecvBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElAS2SocketOptions_get_RecvBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS2SocketOptions::set_RecvBufferSize(int32_t Value)
{
	SBCheckError(TElAS2SocketOptions_set_RecvBufferSize(_Handle, Value));
}

SB_INLINE int32_t TElAS2SocketOptions::get_SendBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElAS2SocketOptions_get_SendBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS2SocketOptions::set_SendBufferSize(int32_t Value)
{
	SBCheckError(TElAS2SocketOptions_set_SendBufferSize(_Handle, Value));
}

void TElAS2SocketOptions::initInstances()
{
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	this->_Inst_Binding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
	this->_Inst_DNS = NULL;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
}

TElAS2SocketOptions::TElAS2SocketOptions(TElAS2SocketOptionsHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
TElAS2SocketOptions::TElAS2SocketOptions(TElHTTPSClient &AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS2SocketOptions_Create(AClient.getHandle(), &_Handle));
}

TElAS2SocketOptions::TElAS2SocketOptions(TElHTTPSClient *AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS2SocketOptions_Create((AClient != NULL) ? AClient->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

TElAS2SocketOptions::~TElAS2SocketOptions()
{
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	delete this->_Inst_Binding;
	this->_Inst_Binding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
	delete this->_Inst_DNS;
	this->_Inst_DNS = NULL;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
}
#endif /* SB_USE_CLASS_TELAS2SOCKETOPTIONS */

#ifdef SB_USE_CLASS_TELAS2SOCKSOPTIONS

SB_INLINE void TElAS2SocksOptions::Assign(TPersistent &Source)
{
	SBCheckError(TElAS2SocksOptions_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElAS2SocksOptions::Assign(TPersistent *Source)
{
	SBCheckError(TElAS2SocksOptions_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

TElSocksAuthentication TElAS2SocksOptions::get_Authentication()
{
	TElSocksAuthenticationRaw OutResultRaw = 0;
	SBCheckError(TElAS2SocksOptions_get_Authentication(_Handle, &OutResultRaw));
	return (TElSocksAuthentication)OutResultRaw;
}

SB_INLINE void TElAS2SocksOptions::set_Authentication(TElSocksAuthentication Value)
{
	SBCheckError(TElAS2SocksOptions_set_Authentication(_Handle, (TElSocksAuthenticationRaw)Value));
}

bool TElAS2SocksOptions::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2SocksOptions_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2SocksOptions::set_Enabled(bool Value)
{
	SBCheckError(TElAS2SocksOptions_set_Enabled(_Handle, (int8_t)Value));
}

void TElAS2SocksOptions::get_Host(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2SocksOptions_get_Host(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-812967730, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2SocksOptions::set_Host(const std::string &Value)
{
	SBCheckError(TElAS2SocksOptions_set_Host(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS2SocksOptions::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2SocksOptions_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-117452158, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2SocksOptions::set_Password(const std::string &Value)
{
	SBCheckError(TElAS2SocksOptions_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElAS2SocksOptions::get_Port()
{
	int32_t OutResult;
	SBCheckError(TElAS2SocksOptions_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS2SocksOptions::set_Port(int32_t Value)
{
	SBCheckError(TElAS2SocksOptions_set_Port(_Handle, Value));
}

bool TElAS2SocksOptions::get_ResolveAddress()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2SocksOptions_get_ResolveAddress(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2SocksOptions::set_ResolveAddress(bool Value)
{
	SBCheckError(TElAS2SocksOptions_set_ResolveAddress(_Handle, (int8_t)Value));
#ifdef SB_WINDOWS
}

bool TElAS2SocksOptions::get_UseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2SocksOptions_get_UseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2SocksOptions::set_UseIPv6(bool Value)
{
	SBCheckError(TElAS2SocksOptions_set_UseIPv6(_Handle, (int8_t)Value));
#endif
}

void TElAS2SocksOptions::get_UserCode(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2SocksOptions_get_UserCode(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1134070912, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2SocksOptions::set_UserCode(const std::string &Value)
{
	SBCheckError(TElAS2SocksOptions_set_UserCode(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSocksVersion TElAS2SocksOptions::get_Version()
{
	TElSocksVersionRaw OutResultRaw = 0;
	SBCheckError(TElAS2SocksOptions_get_Version(_Handle, &OutResultRaw));
	return (TElSocksVersion)OutResultRaw;
}

SB_INLINE void TElAS2SocksOptions::set_Version(TElSocksVersion Value)
{
	SBCheckError(TElAS2SocksOptions_set_Version(_Handle, (TElSocksVersionRaw)Value));
}

TElAS2SocksOptions::TElAS2SocksOptions(TElAS2SocksOptionsHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
TElAS2SocksOptions::TElAS2SocksOptions(TElHTTPSClient &AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAS2SocksOptions_Create(AClient.getHandle(), &_Handle));
}

TElAS2SocksOptions::TElAS2SocksOptions(TElHTTPSClient *AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAS2SocksOptions_Create((AClient != NULL) ? AClient->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

#endif /* SB_USE_CLASS_TELAS2SOCKSOPTIONS */

#ifdef SB_USE_CLASS_TELAS2SSLOPTIONS

SB_INLINE void TElAS2SSLOptions::Assign(TPersistent &Source)
{
	SBCheckError(TElAS2SSLOptions_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElAS2SSLOptions::Assign(TPersistent *Source)
{
	SBCheckError(TElAS2SSLOptions_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

void TElAS2SSLOptions::InternalValidate(TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason)
{
	TSBCertificateValidityRaw ValidityRaw = (TSBCertificateValidityRaw)Validity;
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	SBCheckError(TElAS2SSLOptions_InternalValidate(_Handle, &ValidityRaw, &ReasonRaw));
	Validity = (TSBCertificateValidity)ValidityRaw;
	Reason = (TSBCertificateValidityReason)ReasonRaw;
}

SB_INLINE void TElAS2SSLOptions::RenegotiateCiphers()
{
	SBCheckError(TElAS2SSLOptions_RenegotiateCiphers(_Handle));
}

bool TElAS2SSLOptions::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2SSLOptions_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE uint8_t TElAS2SSLOptions::get_CurrentCipherSuite()
{
	uint8_t OutResult;
	SBCheckError(TElAS2SSLOptions_get_CurrentCipherSuite(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElAS2SSLOptions::get_CurrentCompression()
{
	uint8_t OutResult;
	SBCheckError(TElAS2SSLOptions_get_CurrentCompression(_Handle, &OutResult));
	return OutResult;
}

TSBVersion TElAS2SSLOptions::get_CurrentVersion()
{
	TSBVersionRaw OutResultRaw = 0;
	SBCheckError(TElAS2SSLOptions_get_CurrentVersion(_Handle, &OutResultRaw));
	return (TSBVersion)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
TElCustomSSLExtensions* TElAS2SSLOptions::get_ServerExtensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS2SSLOptions_get_ServerExtensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ServerExtensions)
		this->_Inst_ServerExtensions = new TElCustomSSLExtensions(hOutResult, ohFalse);
	else
		this->_Inst_ServerExtensions->updateHandle(hOutResult);
	return this->_Inst_ServerExtensions;
}

SB_INLINE void TElAS2SSLOptions::set_ServerExtensions(TElCustomSSLExtensions &Value)
{
	SBCheckError(TElAS2SSLOptions_set_ServerExtensions(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS2SSLOptions::set_ServerExtensions(TElCustomSSLExtensions *Value)
{
	SBCheckError(TElAS2SSLOptions_set_ServerExtensions(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
TElClientSSLExtensions* TElAS2SSLOptions::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS2SSLOptions_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TElClientSSLExtensions(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}

SB_INLINE void TElAS2SSLOptions::set_Extensions(TElClientSSLExtensions &Value)
{
	SBCheckError(TElAS2SSLOptions_set_Extensions(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS2SSLOptions::set_Extensions(TElClientSSLExtensions *Value)
{
	SBCheckError(TElAS2SSLOptions_set_Extensions(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */

TSBSSLOptions TElAS2SSLOptions::get_Options()
{
	TSBSSLOptionsRaw OutResultRaw = 0;
	SBCheckError(TElAS2SSLOptions_get_Options(_Handle, &OutResultRaw));
	return (TSBSSLOptions)OutResultRaw;
}

SB_INLINE void TElAS2SSLOptions::set_Options(TSBSSLOptions Value)
{
	SBCheckError(TElAS2SSLOptions_set_Options(_Handle, (TSBSSLOptionsRaw)Value));
}

SB_INLINE int32_t TElAS2SSLOptions::get_CipherSuitePriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElAS2SSLOptions_get_CipherSuitePriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS2SSLOptions::set_CipherSuitePriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElAS2SSLOptions_set_CipherSuitePriorities(_Handle, Index, Value));
}

bool TElAS2SSLOptions::get_CipherSuites(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2SSLOptions_get_CipherSuites(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2SSLOptions::set_CipherSuites(uint8_t Index, bool Value)
{
	SBCheckError(TElAS2SSLOptions_set_CipherSuites(_Handle, Index, (int8_t)Value));
}

bool TElAS2SSLOptions::get_CompressionAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2SSLOptions_get_CompressionAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2SSLOptions::set_CompressionAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElAS2SSLOptions_set_CompressionAlgorithms(_Handle, Index, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElAS2SSLOptions::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS2SSLOptions_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElAS2SSLOptions::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElAS2SSLOptions_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS2SSLOptions::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElAS2SSLOptions_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElAS2SSLOptions::get_ClientCertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS2SSLOptions_get_ClientCertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ClientCertStorage)
		this->_Inst_ClientCertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_ClientCertStorage->updateHandle(hOutResult);
	return this->_Inst_ClientCertStorage;
}

SB_INLINE void TElAS2SSLOptions::set_ClientCertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElAS2SSLOptions_set_ClientCertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS2SSLOptions::set_ClientCertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElAS2SSLOptions_set_ClientCertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

void TElAS2SSLOptions::get_SRPPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2SSLOptions_get_SRPPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2106451048, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2SSLOptions::set_SRPPassword(const std::string &Value)
{
	SBCheckError(TElAS2SSLOptions_set_SRPPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS2SSLOptions::get_SRPUserName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2SSLOptions_get_SRPUserName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-270732284, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2SSLOptions::set_SRPUserName(const std::string &Value)
{
	SBCheckError(TElAS2SSLOptions_set_SRPUserName(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBVersions TElAS2SSLOptions::get_Versions()
{
	TSBVersionsRaw OutResultRaw = 0;
	SBCheckError(TElAS2SSLOptions_get_Versions(_Handle, &OutResultRaw));
	return (TSBVersions)OutResultRaw;
}

SB_INLINE void TElAS2SSLOptions::set_Versions(TSBVersions Value)
{
	SBCheckError(TElAS2SSLOptions_set_Versions(_Handle, (TSBVersionsRaw)Value));
}

TSBRenegotiationAttackPreventionMode TElAS2SSLOptions::get_RenegotiationAttackPreventionMode()
{
	TSBRenegotiationAttackPreventionModeRaw OutResultRaw = 0;
	SBCheckError(TElAS2SSLOptions_get_RenegotiationAttackPreventionMode(_Handle, &OutResultRaw));
	return (TSBRenegotiationAttackPreventionMode)OutResultRaw;
}

SB_INLINE void TElAS2SSLOptions::set_RenegotiationAttackPreventionMode(TSBRenegotiationAttackPreventionMode Value)
{
	SBCheckError(TElAS2SSLOptions_set_RenegotiationAttackPreventionMode(_Handle, (TSBRenegotiationAttackPreventionModeRaw)Value));
}

void TElAS2SSLOptions::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
	this->_Inst_ServerExtensions = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_ClientCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElAS2SSLOptions::TElAS2SSLOptions(TElAS2SSLOptionsHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
TElAS2SSLOptions::TElAS2SSLOptions(TElHTTPSClient &AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS2SSLOptions_Create(AClient.getHandle(), &_Handle));
}

TElAS2SSLOptions::TElAS2SSLOptions(TElHTTPSClient *AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS2SSLOptions_Create((AClient != NULL) ? AClient->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

TElAS2SSLOptions::~TElAS2SSLOptions()
{
#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
	delete this->_Inst_ServerExtensions;
	this->_Inst_ServerExtensions = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_ClientCertStorage;
	this->_Inst_ClientCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELAS2SSLOPTIONS */

#ifdef SB_USE_CLASS_TELAS2WEBTUNNELOPTIONS

SB_INLINE void TElAS2WebTunnelOptions::Assign(TPersistent &Source)
{
	SBCheckError(TElAS2WebTunnelOptions_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElAS2WebTunnelOptions::Assign(TPersistent *Source)
{
	SBCheckError(TElAS2WebTunnelOptions_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElAS2WebTunnelOptions::get_ServerResult()
{
	int32_t OutResult;
	SBCheckError(TElAS2WebTunnelOptions_get_ServerResult(_Handle, &OutResult));
	return OutResult;
}

TElWebTunnelAuthentication TElAS2WebTunnelOptions::get_Authentication()
{
	TElWebTunnelAuthenticationRaw OutResultRaw = 0;
	SBCheckError(TElAS2WebTunnelOptions_get_Authentication(_Handle, &OutResultRaw));
	return (TElWebTunnelAuthentication)OutResultRaw;
}

SB_INLINE void TElAS2WebTunnelOptions::set_Authentication(TElWebTunnelAuthentication Value)
{
	SBCheckError(TElAS2WebTunnelOptions_set_Authentication(_Handle, (TElWebTunnelAuthenticationRaw)Value));
}

bool TElAS2WebTunnelOptions::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAS2WebTunnelOptions_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAS2WebTunnelOptions::set_Enabled(bool Value)
{
	SBCheckError(TElAS2WebTunnelOptions_set_Enabled(_Handle, (int8_t)Value));
}

void TElAS2WebTunnelOptions::get_Host(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2WebTunnelOptions_get_Host(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1601126779, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2WebTunnelOptions::set_Host(const std::string &Value)
{
	SBCheckError(TElAS2WebTunnelOptions_set_Host(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAS2WebTunnelOptions::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2WebTunnelOptions_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(488938303, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2WebTunnelOptions::set_Password(const std::string &Value)
{
	SBCheckError(TElAS2WebTunnelOptions_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElAS2WebTunnelOptions::get_Port()
{
	int32_t OutResult;
	SBCheckError(TElAS2WebTunnelOptions_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAS2WebTunnelOptions::set_Port(int32_t Value)
{
	SBCheckError(TElAS2WebTunnelOptions_set_Port(_Handle, Value));
}

void TElAS2WebTunnelOptions::get_UserID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAS2WebTunnelOptions_get_UserID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1367358695, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAS2WebTunnelOptions::set_UserID(const std::string &Value)
{
	SBCheckError(TElAS2WebTunnelOptions_set_UserID(_Handle, Value.data(), (int32_t)Value.length()));
}

TElAS2WebTunnelOptions::TElAS2WebTunnelOptions(TElAS2WebTunnelOptionsHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
TElAS2WebTunnelOptions::TElAS2WebTunnelOptions(TElHTTPSClient &AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAS2WebTunnelOptions_Create(AClient.getHandle(), &_Handle));
}

TElAS2WebTunnelOptions::TElAS2WebTunnelOptions(TElHTTPSClient *AClient) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAS2WebTunnelOptions_Create((AClient != NULL) ? AClient->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

#endif /* SB_USE_CLASS_TELAS2WEBTUNNELOPTIONS */

#ifdef SB_USE_CLASS_TELAS2CLIENT

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElAS2Client::Send(const std::string &URL, TStream &Message, TStream &Receipt)
{
	int32_t OutResult;
	SBCheckError(TElAS2Client_Send(_Handle, URL.data(), (int32_t)URL.length(), Message.getHandle(), Receipt.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElAS2Client::Send(const std::string &URL, TStream *Message, TStream *Receipt)
{
	int32_t OutResult;
	SBCheckError(TElAS2Client_Send(_Handle, URL.data(), (int32_t)URL.length(), (Message != NULL) ? Message->getHandle() : SB_NULL_HANDLE, (Receipt != NULL) ? Receipt->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElAS2Client::Send(const std::string &URL, const std::string &MessageFile, const std::string &ReceiptFile)
{
	int32_t OutResult;
	SBCheckError(TElAS2Client_Send_1(_Handle, URL.data(), (int32_t)URL.length(), MessageFile.data(), (int32_t)MessageFile.length(), ReceiptFile.data(), (int32_t)ReceiptFile.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElAS2Client::SendReceipt(const std::string &URL, TStream &Receipt)
{
	int32_t OutResult;
	SBCheckError(TElAS2Client_SendReceipt(_Handle, URL.data(), (int32_t)URL.length(), Receipt.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElAS2Client::SendReceipt(const std::string &URL, TStream *Receipt)
{
	int32_t OutResult;
	SBCheckError(TElAS2Client_SendReceipt(_Handle, URL.data(), (int32_t)URL.length(), (Receipt != NULL) ? Receipt->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElAS2Client::SendReceipt(const std::string &URL, const std::string &ReceiptFile)
{
	int32_t OutResult;
	SBCheckError(TElAS2Client_SendReceipt_1(_Handle, URL.data(), (int32_t)URL.length(), ReceiptFile.data(), (int32_t)ReceiptFile.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELAS2HTTPOPTIONS
TElAS2HTTPOptions* TElAS2Client::get_HTTP()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS2Client_get_HTTP(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HTTP)
		this->_Inst_HTTP = new TElAS2HTTPOptions(hOutResult, ohFalse);
	else
		this->_Inst_HTTP->updateHandle(hOutResult);
	return this->_Inst_HTTP;
}

SB_INLINE void TElAS2Client::set_HTTP(TElAS2HTTPOptions &Value)
{
	SBCheckError(TElAS2Client_set_HTTP(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS2Client::set_HTTP(TElAS2HTTPOptions *Value)
{
	SBCheckError(TElAS2Client_set_HTTP(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAS2HTTPOPTIONS */

#ifdef SB_USE_CLASS_TELAS2PROXYOPTIONS
TElAS2ProxyOptions* TElAS2Client::get_Proxy()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS2Client_get_Proxy(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Proxy)
		this->_Inst_Proxy = new TElAS2ProxyOptions(hOutResult, ohFalse);
	else
		this->_Inst_Proxy->updateHandle(hOutResult);
	return this->_Inst_Proxy;
}

SB_INLINE void TElAS2Client::set_Proxy(TElAS2ProxyOptions &Value)
{
	SBCheckError(TElAS2Client_set_Proxy(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS2Client::set_Proxy(TElAS2ProxyOptions *Value)
{
	SBCheckError(TElAS2Client_set_Proxy(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAS2PROXYOPTIONS */

#ifdef SB_USE_CLASS_TELAS2SOCKETOPTIONS
TElAS2SocketOptions* TElAS2Client::get_Socket()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS2Client_get_Socket(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Socket)
		this->_Inst_Socket = new TElAS2SocketOptions(hOutResult, ohFalse);
	else
		this->_Inst_Socket->updateHandle(hOutResult);
	return this->_Inst_Socket;
}

SB_INLINE void TElAS2Client::set_Socket(TElAS2SocketOptions &Value)
{
	SBCheckError(TElAS2Client_set_Socket(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS2Client::set_Socket(TElAS2SocketOptions *Value)
{
	SBCheckError(TElAS2Client_set_Socket(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAS2SOCKETOPTIONS */

#ifdef SB_USE_CLASS_TELAS2SOCKSOPTIONS
TElAS2SocksOptions* TElAS2Client::get_Socks()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS2Client_get_Socks(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Socks)
		this->_Inst_Socks = new TElAS2SocksOptions(hOutResult, ohFalse);
	else
		this->_Inst_Socks->updateHandle(hOutResult);
	return this->_Inst_Socks;
}

SB_INLINE void TElAS2Client::set_Socks(TElAS2SocksOptions &Value)
{
	SBCheckError(TElAS2Client_set_Socks(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS2Client::set_Socks(TElAS2SocksOptions *Value)
{
	SBCheckError(TElAS2Client_set_Socks(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAS2SOCKSOPTIONS */

#ifdef SB_USE_CLASS_TELAS2SSLOPTIONS
TElAS2SSLOptions* TElAS2Client::get_SSL()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS2Client_get_SSL(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SSL)
		this->_Inst_SSL = new TElAS2SSLOptions(hOutResult, ohFalse);
	else
		this->_Inst_SSL->updateHandle(hOutResult);
	return this->_Inst_SSL;
}

SB_INLINE void TElAS2Client::set_SSL(TElAS2SSLOptions &Value)
{
	SBCheckError(TElAS2Client_set_SSL(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS2Client::set_SSL(TElAS2SSLOptions *Value)
{
	SBCheckError(TElAS2Client_set_SSL(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAS2SSLOPTIONS */

#ifdef SB_USE_CLASS_TELAS2WEBTUNNELOPTIONS
TElAS2WebTunnelOptions* TElAS2Client::get_WebTunnel()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAS2Client_get_WebTunnel(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_WebTunnel)
		this->_Inst_WebTunnel = new TElAS2WebTunnelOptions(hOutResult, ohFalse);
	else
		this->_Inst_WebTunnel->updateHandle(hOutResult);
	return this->_Inst_WebTunnel;
}

SB_INLINE void TElAS2Client::set_WebTunnel(TElAS2WebTunnelOptions &Value)
{
	SBCheckError(TElAS2Client_set_WebTunnel(_Handle, Value.getHandle()));
}

SB_INLINE void TElAS2Client::set_WebTunnel(TElAS2WebTunnelOptions *Value)
{
	SBCheckError(TElAS2Client_set_WebTunnel(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAS2WEBTUNNELOPTIONS */

SB_INLINE void TElAS2Client::get_OnCertificateChoose(TSBChooseCertificateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Client_get_OnCertificateChoose(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Client::set_OnCertificateChoose(TSBChooseCertificateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Client_set_OnCertificateChoose(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Client::get_OnCertificateNeededEx(TSBCertificateNeededExEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Client_get_OnCertificateNeededEx(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Client::set_OnCertificateNeededEx(TSBCertificateNeededExEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Client_set_OnCertificateNeededEx(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Client::get_OnCertificateStatus(TSBCertificateStatusEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Client_get_OnCertificateStatus(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Client::set_OnCertificateStatus(TSBCertificateStatusEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Client_set_OnCertificateStatus(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Client::get_OnCertificateValidate(TSBCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Client_get_OnCertificateValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Client::set_OnCertificateValidate(TSBCertificateValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Client_set_OnCertificateValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Client::get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Client_get_OnCiphersNegotiated(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Client::set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Client_set_OnCiphersNegotiated(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Client::get_OnCloseConnection(TSBCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Client_get_OnCloseConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Client::set_OnCloseConnection(TSBCloseConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Client_set_OnCloseConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Client::get_OnCookie(TSBHTTPCookieEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Client_get_OnCookie(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Client::set_OnCookie(TSBHTTPCookieEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Client_set_OnCookie(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Client::get_OnData(TSBDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Client_get_OnData(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Client::set_OnData(TSBDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Client_set_OnData(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Client::get_OnDocumentBegin(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Client_get_OnDocumentBegin(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Client::set_OnDocumentBegin(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Client_set_OnDocumentBegin(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Client::get_OnDocumentEnd(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Client_get_OnDocumentEnd(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Client::set_OnDocumentEnd(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Client_set_OnDocumentEnd(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Client::get_OnError(TSBErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Client_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Client::set_OnError(TSBErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Client_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Client::get_OnExtensionsReceived(TSBExtensionsReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Client_get_OnExtensionsReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Client::set_OnExtensionsReceived(TSBExtensionsReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Client_set_OnExtensionsReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Client::get_OnExtensionsPrepared(TSBExtensionsPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Client_get_OnExtensionsPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Client::set_OnExtensionsPrepared(TSBExtensionsPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Client_set_OnExtensionsPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Client::get_OnKeyNeeded(TSBClientKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Client_get_OnKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Client::set_OnKeyNeeded(TSBClientKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Client_set_OnKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Client::get_OnPreparedHeaders(TSBHTTPHeadersEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Client_get_OnPreparedHeaders(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Client::set_OnPreparedHeaders(TSBHTTPHeadersEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Client_set_OnPreparedHeaders(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Client::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Client_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Client::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Client_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Client::get_OnReceivingHeaders(TSBHTTPHeadersEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Client_get_OnReceivingHeaders(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Client::set_OnReceivingHeaders(TSBHTTPHeadersEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Client_set_OnReceivingHeaders(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Client::get_OnRedirection(TSBHTTPRedirectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Client_get_OnRedirection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Client::set_OnRedirection(TSBHTTPRedirectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Client_set_OnRedirection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Client::get_OnRenegotiationRequest(TSBRenegotiationRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Client_get_OnRenegotiationRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Client::set_OnRenegotiationRequest(TSBRenegotiationRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Client_set_OnRenegotiationRequest(_Handle, pMethodValue, pDataValue));
#ifndef SB_WINCE_OR_NOT_WINDOWS
}

SB_INLINE void TElAS2Client::get_OnDNSKeyNeded(TSBDNSKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Client_get_OnDNSKeyNeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Client::set_OnDNSKeyNeded(TSBDNSKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Client_set_OnDNSKeyNeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Client::get_OnDNSKeyValidate(TSBDNSKeyValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Client_get_OnDNSKeyValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Client::set_OnDNSKeyValidate(TSBDNSKeyValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Client_set_OnDNSKeyValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElAS2Client::get_OnDNSResolve(TSBDNSResolveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAS2Client_get_OnDNSResolve(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAS2Client::set_OnDNSResolve(TSBDNSResolveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAS2Client_set_OnDNSResolve(_Handle, pMethodValue, pDataValue));
#endif
}

void TElAS2Client::initInstances()
{
#ifdef SB_USE_CLASS_TELAS2HTTPOPTIONS
	this->_Inst_HTTP = NULL;
#endif /* SB_USE_CLASS_TELAS2HTTPOPTIONS */
#ifdef SB_USE_CLASS_TELAS2PROXYOPTIONS
	this->_Inst_Proxy = NULL;
#endif /* SB_USE_CLASS_TELAS2PROXYOPTIONS */
#ifdef SB_USE_CLASS_TELAS2SOCKETOPTIONS
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELAS2SOCKETOPTIONS */
#ifdef SB_USE_CLASS_TELAS2SOCKSOPTIONS
	this->_Inst_Socks = NULL;
#endif /* SB_USE_CLASS_TELAS2SOCKSOPTIONS */
#ifdef SB_USE_CLASS_TELAS2SSLOPTIONS
	this->_Inst_SSL = NULL;
#endif /* SB_USE_CLASS_TELAS2SSLOPTIONS */
#ifdef SB_USE_CLASS_TELAS2WEBTUNNELOPTIONS
	this->_Inst_WebTunnel = NULL;
#endif /* SB_USE_CLASS_TELAS2WEBTUNNELOPTIONS */
}

TElAS2Client::TElAS2Client(TElAS2ClientHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElAS2Client::TElAS2Client(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS2Client_Create(AOwner.getHandle(), &_Handle));
}

TElAS2Client::TElAS2Client(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAS2Client_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElAS2Client::~TElAS2Client()
{
#ifdef SB_USE_CLASS_TELAS2HTTPOPTIONS
	delete this->_Inst_HTTP;
	this->_Inst_HTTP = NULL;
#endif /* SB_USE_CLASS_TELAS2HTTPOPTIONS */
#ifdef SB_USE_CLASS_TELAS2PROXYOPTIONS
	delete this->_Inst_Proxy;
	this->_Inst_Proxy = NULL;
#endif /* SB_USE_CLASS_TELAS2PROXYOPTIONS */
#ifdef SB_USE_CLASS_TELAS2SOCKETOPTIONS
	delete this->_Inst_Socket;
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELAS2SOCKETOPTIONS */
#ifdef SB_USE_CLASS_TELAS2SOCKSOPTIONS
	delete this->_Inst_Socks;
	this->_Inst_Socks = NULL;
#endif /* SB_USE_CLASS_TELAS2SOCKSOPTIONS */
#ifdef SB_USE_CLASS_TELAS2SSLOPTIONS
	delete this->_Inst_SSL;
	this->_Inst_SSL = NULL;
#endif /* SB_USE_CLASS_TELAS2SSLOPTIONS */
#ifdef SB_USE_CLASS_TELAS2WEBTUNNELOPTIONS
	delete this->_Inst_WebTunnel;
	this->_Inst_WebTunnel = NULL;
#endif /* SB_USE_CLASS_TELAS2WEBTUNNELOPTIONS */
}
#endif /* SB_USE_CLASS_TELAS2CLIENT */

#ifdef SB_USE_GLOBAL_PROCS_AS2

bool AS2NameNeedsQuoting(const std::string &AS2Name)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBAS2_AS2NameNeedsQuoting(AS2Name.data(), (int32_t)AS2Name.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void DequoteAS2Name(const std::string &Value, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBAS2_DequoteAS2Name(Value.data(), (int32_t)Value.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1325379127, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void QuoteAS2Name(const std::string &AS2Name, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBAS2_QuoteAS2Name(AS2Name.data(), (int32_t)AS2Name.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1187016168, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool ValidAS2Name(const std::string &Name)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBAS2_ValidAS2Name(Name.data(), (int32_t)Name.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#endif /* SB_USE_GLOBAL_PROCS_AS2 */

};	/* namespace SecureBlackbox */
