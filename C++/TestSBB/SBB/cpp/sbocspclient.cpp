#include "sbocspclient.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELOCSPCLIENT

int32_t TElOCSPClient::CreateRequest(std::vector<uint8_t> &Request)
{
	int32_t OutResult;
	int32_t szRequest = (int32_t)Request.size();
	uint32_t _err = TElOCSPClient_CreateRequest(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Request), &szRequest, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Request.resize(szRequest);
		SBCheckError(SBGetLastReturnBuffer(571009497, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Request), &szRequest));
	}
	else
		SBCheckError(_err);

	Request.resize(szRequest);
	return OutResult;
}

int32_t TElOCSPClient::ProcessReply(const std::vector<uint8_t> &Reply, TElOCSPServerError &ServerResult)
{
	int32_t OutResult;
	TElOCSPServerErrorRaw ServerResultRaw = (TElOCSPServerErrorRaw)ServerResult;
	SBCheckError(TElOCSPClient_ProcessReply(_Handle, SB_STD_VECTOR_FRONT_ADR(Reply), (int32_t)Reply.size(), &ServerResultRaw, &OutResult));
	ServerResult = (TElOCSPServerError)ServerResultRaw;
	return OutResult;
}

int32_t TElOCSPClient::PerformRequest(TElOCSPServerError &ServerResult, std::vector<uint8_t> &Reply)
{
	int32_t OutResult;
	TElOCSPServerErrorRaw ServerResultRaw = (TElOCSPServerErrorRaw)ServerResult;
	int32_t szReply = (int32_t)Reply.size();
	uint32_t _err = TElOCSPClient_PerformRequest(_Handle, &ServerResultRaw, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Reply), &szReply, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Reply.resize(szReply);
		SBCheckError(SBGetLastReturnBuffer(-1674482338, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Reply), &szReply));
	}
	else
		SBCheckError(_err);

	ServerResult = (TElOCSPServerError)ServerResultRaw;
	Reply.resize(szReply);
	return OutResult;
}

bool TElOCSPClient::SupportsLocation(const std::string &URI)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOCSPClient_SupportsLocation(_Handle, URI.data(), (int32_t)URI.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int64_t TElOCSPClient::get_ReplyProducedAt()
{
	int64_t OutResult;
	SBCheckError(TElOCSPClient_get_ReplyProducedAt(_Handle, &OutResult));
	return OutResult;
}

void TElOCSPClient::get_ReplyNonce(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOCSPClient_get_ReplyNonce(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-630927206, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElOCSPClient::get_ReplyCertificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOCSPClient_get_ReplyCertificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ReplyCertificates)
		this->_Inst_ReplyCertificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_ReplyCertificates->updateHandle(hOutResult);
	return this->_Inst_ReplyCertificates;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElOCSPClient::get_ServerName()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOCSPClient_get_ServerName(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ServerName)
		this->_Inst_ServerName = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_ServerName->updateHandle(hOutResult);
	return this->_Inst_ServerName;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

void TElOCSPClient::get_ServerCertKeyHash(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOCSPClient_get_ServerCertKeyHash(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(487844738, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOCSPClient::set_ServerCertKeyHash(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOCSPClient_set_ServerCertKeyHash(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElOCSPCertificateStatus TElOCSPClient::get_CertStatus(int32_t Index)
{
	TElOCSPCertificateStatusRaw OutResultRaw = 0;
	SBCheckError(TElOCSPClient_get_CertStatus(_Handle, Index, &OutResultRaw));
	return (TElOCSPCertificateStatus)OutResultRaw;
}

SB_INLINE int64_t TElOCSPClient::get_RevocationTime(int32_t Index)
{
	int64_t OutResult;
	SBCheckError(TElOCSPClient_get_RevocationTime(_Handle, Index, &OutResult));
	return OutResult;
}

TSBCRLReasonFlag TElOCSPClient::get_RevocationReason(int32_t Index)
{
	TSBCRLReasonFlagRaw OutResultRaw = 0;
	SBCheckError(TElOCSPClient_get_RevocationReason(_Handle, Index, &OutResultRaw));
	return (TSBCRLReasonFlag)OutResultRaw;
}

SB_INLINE int64_t TElOCSPClient::get_ThisUpdate(int32_t Index)
{
	int64_t OutResult;
	SBCheckError(TElOCSPClient_get_ThisUpdate(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElOCSPClient::get_NextUpdate(int32_t Index)
{
	int64_t OutResult;
	SBCheckError(TElOCSPClient_get_NextUpdate(_Handle, Index, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
TElOCSPResponse* TElOCSPClient::get_Response()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOCSPClient_get_Response(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Response)
		this->_Inst_Response = new TElOCSPResponse(hOutResult, ohFalse);
	else
		this->_Inst_Response->updateHandle(hOutResult);
	return this->_Inst_Response;
}
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

void TElOCSPClient::get_Nonce(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOCSPClient_get_Nonce(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1103259277, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOCSPClient::set_Nonce(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOCSPClient_set_Nonce(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElOCSPClient::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOCSPClient_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElOCSPClient::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElOCSPClient_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElOCSPClient::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElOCSPClient_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElOCSPClient::get_IssuerCertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOCSPClient_get_IssuerCertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IssuerCertStorage)
		this->_Inst_IssuerCertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_IssuerCertStorage->updateHandle(hOutResult);
	return this->_Inst_IssuerCertStorage;
}

SB_INLINE void TElOCSPClient::set_IssuerCertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElOCSPClient_set_IssuerCertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElOCSPClient::set_IssuerCertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElOCSPClient_set_IssuerCertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

bool TElOCSPClient::get_IncludeSignature()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOCSPClient_get_IncludeSignature(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElOCSPClient::set_IncludeSignature(bool Value)
{
	SBCheckError(TElOCSPClient_set_IncludeSignature(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElOCSPClient::get_SignatureAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElOCSPClient_get_SignatureAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOCSPClient::set_SignatureAlgorithm(int32_t Value)
{
	SBCheckError(TElOCSPClient_set_SignatureAlgorithm(_Handle, Value));
}

TSBOCSPClientOptions TElOCSPClient::get_Options()
{
	TSBOCSPClientOptionsRaw OutResultRaw = 0;
	SBCheckError(TElOCSPClient_get_Options(_Handle, &OutResultRaw));
	return (TSBOCSPClientOptions)OutResultRaw;
}

SB_INLINE void TElOCSPClient::set_Options(TSBOCSPClientOptions Value)
{
	SBCheckError(TElOCSPClient_set_Options(_Handle, (TSBOCSPClientOptionsRaw)Value));
}

void TElOCSPClient::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOCSPClient_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1076938350, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOCSPClient::set_URL(const std::string &Value)
{
	SBCheckError(TElOCSPClient_set_URL(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOCSPClient::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_ReplyCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_ServerName = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELOCSPRESPONSE
	this->_Inst_Response = NULL;
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_IssuerCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElOCSPClient::TElOCSPClient(TElOCSPClientHandle handle, TElOwnHandle ownHandle) : TElOCSPClass(handle, ownHandle)
{
	initInstances();
}

TElOCSPClient::TElOCSPClient(TComponent &Owner) : TElOCSPClass(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOCSPClient_Create(Owner.getHandle(), &_Handle));
}

TElOCSPClient::TElOCSPClient(TComponent *Owner) : TElOCSPClass(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOCSPClient_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElOCSPClient::~TElOCSPClient()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_ReplyCertificates;
	this->_Inst_ReplyCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_ServerName;
	this->_Inst_ServerName = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELOCSPRESPONSE
	delete this->_Inst_Response;
	this->_Inst_Response = NULL;
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_IssuerCertStorage;
	this->_Inst_IssuerCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELOCSPCLIENT */

#ifdef SB_USE_CLASS_TELOCSPRESPONDERID

SB_INLINE void TElOCSPResponderID::Clear()
{
	SBCheckError(TElOCSPResponderID_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElOCSPResponderID::get_Name()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOCSPResponderID_get_Name(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Name)
		this->_Inst_Name = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_Name->updateHandle(hOutResult);
	return this->_Inst_Name;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

void TElOCSPResponderID::get_SHA1KeyHash(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOCSPResponderID_get_SHA1KeyHash(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(453980664, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOCSPResponderID::set_SHA1KeyHash(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOCSPResponderID_set_SHA1KeyHash(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElOCSPResponderID::initInstances()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_Name = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
}

TElOCSPResponderID::TElOCSPResponderID(TElOCSPResponderIDHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElOCSPResponderID::TElOCSPResponderID() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOCSPResponderID_Create(&_Handle));
}

TElOCSPResponderID::~TElOCSPResponderID()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_Name;
	this->_Inst_Name = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
}
#endif /* SB_USE_CLASS_TELOCSPRESPONDERID */

#ifdef SB_USE_CLASS_TELOCSPSINGLERESPONSE

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
SB_INLINE void TElOCSPSingleResponse::LoadFromTag(TElASN1ConstrainedTag &Tag)
{
	SBCheckError(TElOCSPSingleResponse_LoadFromTag(_Handle, Tag.getHandle()));
}

SB_INLINE void TElOCSPSingleResponse::LoadFromTag(TElASN1ConstrainedTag *Tag)
{
	SBCheckError(TElOCSPSingleResponse_LoadFromTag(_Handle, (Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
bool TElOCSPSingleResponse::CertMatches(TElX509Certificate &Cert, TElX509Certificate &Issuer)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOCSPSingleResponse_CertMatches(_Handle, Cert.getHandle(), Issuer.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOCSPSingleResponse::CertMatches(TElX509Certificate *Cert, TElX509Certificate *Issuer)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOCSPSingleResponse_CertMatches(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Issuer != NULL) ? Issuer->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELPKCS7ISSUER_AND_TELX509CERTIFICATE
bool TElOCSPSingleResponse::SignerMatches(TElPKCS7Issuer &Signer, TElX509Certificate &Issuer)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOCSPSingleResponse_SignerMatches(_Handle, Signer.getHandle(), Issuer.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOCSPSingleResponse::SignerMatches(TElPKCS7Issuer *Signer, TElX509Certificate *Issuer)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOCSPSingleResponse_SignerMatches(_Handle, (Signer != NULL) ? Signer->getHandle() : SB_NULL_HANDLE, (Issuer != NULL) ? Issuer->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELPKCS7ISSUER_AND_TELX509CERTIFICATE */

SB_INLINE int32_t TElOCSPSingleResponse::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElOCSPSingleResponse_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

void TElOCSPSingleResponse::get_IssuerNameHash(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOCSPSingleResponse_get_IssuerNameHash(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-553708567, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOCSPSingleResponse::get_IssuerKeyHash(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOCSPSingleResponse_get_IssuerKeyHash(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1894661179, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOCSPSingleResponse::get_SerialNumber(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOCSPSingleResponse_get_SerialNumber(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(189526734, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElOCSPCertificateStatus TElOCSPSingleResponse::get_CertStatus()
{
	TElOCSPCertificateStatusRaw OutResultRaw = 0;
	SBCheckError(TElOCSPSingleResponse_get_CertStatus(_Handle, &OutResultRaw));
	return (TElOCSPCertificateStatus)OutResultRaw;
}

SB_INLINE int64_t TElOCSPSingleResponse::get_ThisUpdate()
{
	int64_t OutResult;
	SBCheckError(TElOCSPSingleResponse_get_ThisUpdate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElOCSPSingleResponse::get_NextUpdate()
{
	int64_t OutResult;
	SBCheckError(TElOCSPSingleResponse_get_NextUpdate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElOCSPSingleResponse::get_RevocationTime()
{
	int64_t OutResult;
	SBCheckError(TElOCSPSingleResponse_get_RevocationTime(_Handle, &OutResult));
	return OutResult;
}

TSBCRLReasonFlags TElOCSPSingleResponse::get_RevocationReasons()
{
	TSBCRLReasonFlagsRaw OutResultRaw = 0;
	SBCheckError(TElOCSPSingleResponse_get_RevocationReasons(_Handle, &OutResultRaw));
	return (TSBCRLReasonFlags)OutResultRaw;
}

TElOCSPSingleResponse::TElOCSPSingleResponse(TElOCSPSingleResponseHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElOCSPSingleResponse::TElOCSPSingleResponse() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOCSPSingleResponse_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOCSPSINGLERESPONSE */

#ifdef SB_USE_CLASS_TELOCSPRESPONSE

SB_INLINE void TElOCSPResponse::Clear()
{
	SBCheckError(TElOCSPResponse_Clear(_Handle));
}

SB_INLINE void TElOCSPResponse::Assign(TPersistent &Source)
{
	SBCheckError(TElOCSPResponse_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElOCSPResponse::Assign(TPersistent *Source)
{
	SBCheckError(TElOCSPResponse_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElOCSPResponse::Load(void * Buffer, int32_t Size)
{
	SBCheckError(TElOCSPResponse_Load(_Handle, Buffer, Size));
}

bool TElOCSPResponse::Save(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOCSPResponse_Save(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOCSPResponse::SaveBasic(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOCSPResponse_SaveBasic(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOCSPResponse::SaveFull(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOCSPResponse_SaveFull(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOCSPResponse::EqualsTo(TElOCSPResponse &OtherResponse)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOCSPResponse_EqualsTo(_Handle, OtherResponse.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOCSPResponse::EqualsTo(TElOCSPResponse *OtherResponse)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOCSPResponse_EqualsTo(_Handle, (OtherResponse != NULL) ? OtherResponse->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE int32_t TElOCSPResponse::FindResponse(TElX509Certificate &Cert, TElX509Certificate &Issuer)
{
	int32_t OutResult;
	SBCheckError(TElOCSPResponse_FindResponse(_Handle, Cert.getHandle(), Issuer.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOCSPResponse::FindResponse(TElX509Certificate *Cert, TElX509Certificate *Issuer)
{
	int32_t OutResult;
	SBCheckError(TElOCSPResponse_FindResponse(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Issuer != NULL) ? Issuer->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELPKCS7ISSUER_AND_TELX509CERTIFICATE
SB_INLINE int32_t TElOCSPResponse::FindResponse(TElPKCS7Issuer &Signer, TElX509Certificate &Issuer)
{
	int32_t OutResult;
	SBCheckError(TElOCSPResponse_FindResponse_1(_Handle, Signer.getHandle(), Issuer.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOCSPResponse::FindResponse(TElPKCS7Issuer *Signer, TElX509Certificate *Issuer)
{
	int32_t OutResult;
	SBCheckError(TElOCSPResponse_FindResponse_1(_Handle, (Signer != NULL) ? Signer->getHandle() : SB_NULL_HANDLE, (Issuer != NULL) ? Issuer->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPKCS7ISSUER_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE TElX509CertificateHandle TElOCSPResponse::GetSignerCertificate()
{
	TElX509CertificateHandle OutResult;
	SBCheckError(TElOCSPResponse_GetSignerCertificate(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
bool TElOCSPResponse::IsSignerCertificate(TElX509Certificate &Certificate)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOCSPResponse_IsSignerCertificate(_Handle, Certificate.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOCSPResponse::IsSignerCertificate(TElX509Certificate *Certificate)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOCSPResponse_IsSignerCertificate(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

TSBCMSSignatureValidity TElOCSPResponse::Validate()
{
	TSBCMSSignatureValidityRaw OutResultRaw = 0;
	SBCheckError(TElOCSPResponse_Validate(_Handle, &OutResultRaw));
	return (TSBCMSSignatureValidity)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TSBCMSSignatureValidity TElOCSPResponse::Validate(TElX509Certificate &CACertificate)
{
	TSBCMSSignatureValidityRaw OutResultRaw = 0;
	SBCheckError(TElOCSPResponse_Validate_1(_Handle, CACertificate.getHandle(), &OutResultRaw));
	return (TSBCMSSignatureValidity)OutResultRaw;
}

TSBCMSSignatureValidity TElOCSPResponse::Validate(TElX509Certificate *CACertificate)
{
	TSBCMSSignatureValidityRaw OutResultRaw = 0;
	SBCheckError(TElOCSPResponse_Validate_1(_Handle, (CACertificate != NULL) ? CACertificate->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBCMSSignatureValidity)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

void TElOCSPResponse::GetOCSPResponseHash(int32_t Alg, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOCSPResponse_GetOCSPResponseHash(_Handle, Alg, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1286318205, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElOCSPResponse::get_SignatureAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElOCSPResponse_get_SignatureAlgorithm(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
TElMemoryCertStorage* TElOCSPResponse::get_Certificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOCSPResponse_get_Certificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElMemoryCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

#ifdef SB_USE_CLASS_TELOCSPRESPONDERID
TElOCSPResponderID* TElOCSPResponse::get_ResponderID()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOCSPResponse_get_ResponderID(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ResponderID)
		this->_Inst_ResponderID = new TElOCSPResponderID(hOutResult, ohFalse);
	else
		this->_Inst_ResponderID->updateHandle(hOutResult);
	return this->_Inst_ResponderID;
}
#endif /* SB_USE_CLASS_TELOCSPRESPONDERID */

SB_INLINE int64_t TElOCSPResponse::get_ProducedAt()
{
	int64_t OutResult;
	SBCheckError(TElOCSPResponse_get_ProducedAt(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOCSPSINGLERESPONSE
TElOCSPSingleResponse* TElOCSPResponse::get_Responses(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOCSPResponse_get_Responses(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Responses)
		this->_Inst_Responses = new TElOCSPSingleResponse(hOutResult, ohFalse);
	else
		this->_Inst_Responses->updateHandle(hOutResult);
	return this->_Inst_Responses;
}
#endif /* SB_USE_CLASS_TELOCSPSINGLERESPONSE */

SB_INLINE int32_t TElOCSPResponse::get_ResponseCount()
{
	int32_t OutResult;
	SBCheckError(TElOCSPResponse_get_ResponseCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOCSPResponse::get_OnCertificateNeeded(TSBCMSCertificateNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOCSPResponse_get_OnCertificateNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOCSPResponse::set_OnCertificateNeeded(TSBCMSCertificateNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOCSPResponse_set_OnCertificateNeeded(_Handle, pMethodValue, pDataValue));
}

void TElOCSPResponse::initInstances()
{
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELOCSPRESPONDERID
	this->_Inst_ResponderID = NULL;
#endif /* SB_USE_CLASS_TELOCSPRESPONDERID */
#ifdef SB_USE_CLASS_TELOCSPSINGLERESPONSE
	this->_Inst_Responses = NULL;
#endif /* SB_USE_CLASS_TELOCSPSINGLERESPONSE */
}

TElOCSPResponse::TElOCSPResponse(TElOCSPResponseHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElOCSPResponse::TElOCSPResponse() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOCSPResponse_Create(&_Handle));
}

TElOCSPResponse::~TElOCSPResponse()
{
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELOCSPRESPONDERID
	delete this->_Inst_ResponderID;
	this->_Inst_ResponderID = NULL;
#endif /* SB_USE_CLASS_TELOCSPRESPONDERID */
#ifdef SB_USE_CLASS_TELOCSPSINGLERESPONSE
	delete this->_Inst_Responses;
	this->_Inst_Responses = NULL;
#endif /* SB_USE_CLASS_TELOCSPSINGLERESPONSE */
}
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

#ifdef SB_USE_CLASS_TELFILEOCSPCLIENT

bool TElFileOCSPClient::SupportsLocation(const std::string &URI)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFileOCSPClient_SupportsLocation(_Handle, URI.data(), (int32_t)URI.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

int32_t TElFileOCSPClient::PerformRequest(TElOCSPServerError &ServerResult, std::vector<uint8_t> &Reply)
{
	int32_t OutResult;
	TElOCSPServerErrorRaw ServerResultRaw = (TElOCSPServerErrorRaw)ServerResult;
	int32_t szReply = (int32_t)Reply.size();
	uint32_t _err = TElFileOCSPClient_PerformRequest(_Handle, &ServerResultRaw, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Reply), &szReply, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Reply.resize(szReply);
		SBCheckError(SBGetLastReturnBuffer(-1284353318, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Reply), &szReply));
	}
	else
		SBCheckError(_err);

	ServerResult = (TElOCSPServerError)ServerResultRaw;
	Reply.resize(szReply);
	return OutResult;
}

SB_INLINE void TElFileOCSPClient::get_OnOCSPValidationNeeded(TSBOCSPValidationNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFileOCSPClient_get_OnOCSPValidationNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFileOCSPClient::set_OnOCSPValidationNeeded(TSBOCSPValidationNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFileOCSPClient_set_OnOCSPValidationNeeded(_Handle, pMethodValue, pDataValue));
}

TElFileOCSPClient::TElFileOCSPClient(TElFileOCSPClientHandle handle, TElOwnHandle ownHandle) : TElOCSPClient(handle, ownHandle)
{
}

TElFileOCSPClient::TElFileOCSPClient(TComponent &Owner) : TElOCSPClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFileOCSPClient_Create(Owner.getHandle(), &_Handle));
}

TElFileOCSPClient::TElFileOCSPClient(TComponent *Owner) : TElOCSPClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFileOCSPClient_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELFILEOCSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMOCSPCLIENTFACTORY

bool TElCustomOCSPClientFactory::SupportsLocation(const std::string &URI)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomOCSPClientFactory_SupportsLocation(_Handle, URI.data(), (int32_t)URI.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELOCSPCLIENT
SB_INLINE TElOCSPClientHandle TElCustomOCSPClientFactory::GetClientInstance(TObject &Validator)
{
	TElOCSPClientHandle OutResult;
	SBCheckError(TElCustomOCSPClientFactory_GetClientInstance(_Handle, Validator.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElOCSPClientHandle TElCustomOCSPClientFactory::GetClientInstance(TObject *Validator)
{
	TElOCSPClientHandle OutResult;
	SBCheckError(TElCustomOCSPClientFactory_GetClientInstance(_Handle, (Validator != NULL) ? Validator->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOCSPCLIENT */

TElCustomOCSPClientFactory::TElCustomOCSPClientFactory(TElCustomOCSPClientFactoryHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElCustomOCSPClientFactory::TElCustomOCSPClientFactory() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomOCSPClientFactory_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCUSTOMOCSPCLIENTFACTORY */

#ifdef SB_USE_CLASS_TELOCSPCLIENTMANAGER

#ifdef SB_USE_CLASS_TELOCSPCLIENT
SB_INLINE TElOCSPClientHandle TElOCSPClientManager::FindOCSPClientByLocation(const std::string &Location, TObject &Validator)
{
	TElOCSPClientHandle OutResult;
	SBCheckError(TElOCSPClientManager_FindOCSPClientByLocation(_Handle, Location.data(), (int32_t)Location.length(), Validator.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElOCSPClientHandle TElOCSPClientManager::FindOCSPClientByLocation(const std::string &Location, TObject *Validator)
{
	TElOCSPClientHandle OutResult;
	SBCheckError(TElOCSPClientManager_FindOCSPClientByLocation(_Handle, Location.data(), (int32_t)Location.length(), (Validator != NULL) ? Validator->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOCSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMOCSPCLIENTFACTORY
SB_INLINE void TElOCSPClientManager::RegisterOCSPClientFactory(TElCustomOCSPClientFactory &Factory)
{
	SBCheckError(TElOCSPClientManager_RegisterOCSPClientFactory(_Handle, Factory.getHandle()));
}

SB_INLINE void TElOCSPClientManager::RegisterOCSPClientFactory(TElCustomOCSPClientFactory *Factory)
{
	SBCheckError(TElOCSPClientManager_RegisterOCSPClientFactory(_Handle, (Factory != NULL) ? Factory->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMOCSPCLIENTFACTORY */

#ifdef SB_USE_CLASS_TELCUSTOMOCSPCLIENTFACTORY
SB_INLINE void TElOCSPClientManager::UnregisterOCSPClientFactory(TElCustomOCSPClientFactory &Factory)
{
	SBCheckError(TElOCSPClientManager_UnregisterOCSPClientFactory(_Handle, Factory.getHandle()));
}

SB_INLINE void TElOCSPClientManager::UnregisterOCSPClientFactory(TElCustomOCSPClientFactory *Factory)
{
	SBCheckError(TElOCSPClientManager_UnregisterOCSPClientFactory(_Handle, (Factory != NULL) ? Factory->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMOCSPCLIENTFACTORY */

TElOCSPClientManager::TElOCSPClientManager(TElOCSPClientManagerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElOCSPClientManager::TElOCSPClientManager() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOCSPClientManager_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOCSPCLIENTMANAGER */

#ifdef SB_USE_GLOBAL_PROCS_OCSPCLIENT

#ifdef SB_USE_CLASS_TELOCSPCLIENTMANAGER
SB_INLINE TElOCSPClientManagerHandle OCSPClientManagerAddRef()
{
	TElOCSPClientManagerHandle OutResult;
	SBCheckError(SBOCSPClient_OCSPClientManagerAddRef(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOCSPCLIENTMANAGER */

SB_INLINE void OCSPClientManagerRelease()
{
	SBCheckError(SBOCSPClient_OCSPClientManagerRelease());
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
void GetOCSPCertID(TElX509Certificate &Cert, TElX509Certificate &Issuer, int32_t DigestAlg, std::vector<uint8_t> &aIssuerNameHash, std::vector<uint8_t> &IssuerKeyHash)
{
	int32_t szaIssuerNameHash = (int32_t)aIssuerNameHash.size();
	int32_t szIssuerKeyHash = (int32_t)IssuerKeyHash.size();
	uint32_t _err = SBOCSPClient_GetOCSPCertID(Cert.getHandle(), Issuer.getHandle(), DigestAlg, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(aIssuerNameHash), &szaIssuerNameHash, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(IssuerKeyHash), &szIssuerKeyHash);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		aIssuerNameHash.resize(szaIssuerNameHash);
		SBCheckError(SBGetLastReturnBuffer(-691874869, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(aIssuerNameHash), &szaIssuerNameHash));
		IssuerKeyHash.resize(szIssuerKeyHash);
		SBCheckError(SBGetLastReturnBuffer(-691874869, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(IssuerKeyHash), &szIssuerKeyHash));
	}
	else
		SBCheckError(_err);

	aIssuerNameHash.resize(szaIssuerNameHash);
	IssuerKeyHash.resize(szIssuerKeyHash);
}
void GetOCSPCertID(TElX509Certificate *Cert, TElX509Certificate *Issuer, int32_t DigestAlg, std::vector<uint8_t> &aIssuerNameHash, std::vector<uint8_t> &IssuerKeyHash)
{
	int32_t szaIssuerNameHash = (int32_t)aIssuerNameHash.size();
	int32_t szIssuerKeyHash = (int32_t)IssuerKeyHash.size();
	uint32_t _err = SBOCSPClient_GetOCSPCertID((Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Issuer != NULL) ? Issuer->getHandle() : SB_NULL_HANDLE, DigestAlg, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(aIssuerNameHash), &szaIssuerNameHash, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(IssuerKeyHash), &szIssuerKeyHash);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		aIssuerNameHash.resize(szaIssuerNameHash);
		SBCheckError(SBGetLastReturnBuffer(-691874869, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(aIssuerNameHash), &szaIssuerNameHash));
		IssuerKeyHash.resize(szIssuerKeyHash);
		SBCheckError(SBGetLastReturnBuffer(-691874869, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(IssuerKeyHash), &szIssuerKeyHash));
	}
	else
		SBCheckError(_err);

	aIssuerNameHash.resize(szaIssuerNameHash);
	IssuerKeyHash.resize(szIssuerKeyHash);
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELPKCS7ISSUER_AND_TELX509CERTIFICATE
void GetOCSPCertID(TElPKCS7Issuer &Signer, TElX509Certificate &Issuer, int32_t DigestAlg, std::vector<uint8_t> &aIssuerNameHash, std::vector<uint8_t> &IssuerKeyHash)
{
	int32_t szaIssuerNameHash = (int32_t)aIssuerNameHash.size();
	int32_t szIssuerKeyHash = (int32_t)IssuerKeyHash.size();
	uint32_t _err = SBOCSPClient_GetOCSPCertID_1(Signer.getHandle(), Issuer.getHandle(), DigestAlg, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(aIssuerNameHash), &szaIssuerNameHash, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(IssuerKeyHash), &szIssuerKeyHash);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		aIssuerNameHash.resize(szaIssuerNameHash);
		SBCheckError(SBGetLastReturnBuffer(-1339082539, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(aIssuerNameHash), &szaIssuerNameHash));
		IssuerKeyHash.resize(szIssuerKeyHash);
		SBCheckError(SBGetLastReturnBuffer(-1339082539, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(IssuerKeyHash), &szIssuerKeyHash));
	}
	else
		SBCheckError(_err);

	aIssuerNameHash.resize(szaIssuerNameHash);
	IssuerKeyHash.resize(szIssuerKeyHash);
}
void GetOCSPCertID(TElPKCS7Issuer *Signer, TElX509Certificate *Issuer, int32_t DigestAlg, std::vector<uint8_t> &aIssuerNameHash, std::vector<uint8_t> &IssuerKeyHash)
{
	int32_t szaIssuerNameHash = (int32_t)aIssuerNameHash.size();
	int32_t szIssuerKeyHash = (int32_t)IssuerKeyHash.size();
	uint32_t _err = SBOCSPClient_GetOCSPCertID_1((Signer != NULL) ? Signer->getHandle() : SB_NULL_HANDLE, (Issuer != NULL) ? Issuer->getHandle() : SB_NULL_HANDLE, DigestAlg, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(aIssuerNameHash), &szaIssuerNameHash, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(IssuerKeyHash), &szIssuerKeyHash);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		aIssuerNameHash.resize(szaIssuerNameHash);
		SBCheckError(SBGetLastReturnBuffer(-1339082539, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(aIssuerNameHash), &szaIssuerNameHash));
		IssuerKeyHash.resize(szIssuerKeyHash);
		SBCheckError(SBGetLastReturnBuffer(-1339082539, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(IssuerKeyHash), &szIssuerKeyHash));
	}
	else
		SBCheckError(_err);

	aIssuerNameHash.resize(szaIssuerNameHash);
	IssuerKeyHash.resize(szIssuerKeyHash);
}
#endif /* SB_USE_CLASSES_TELPKCS7ISSUER_AND_TELX509CERTIFICATE */

#endif /* SB_USE_GLOBAL_PROCS_OCSPCLIENT */

};	/* namespace SecureBlackbox */

