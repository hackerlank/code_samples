#include "sbx509.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSUBJECTPUBLICKEYINFO

SB_INLINE void TElSubjectPublicKeyInfo::Clear()
{
	SBCheckError(TElSubjectPublicKeyInfo_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
TElAlgorithmIdentifier* TElSubjectPublicKeyInfo::get_PublicKeyAlgorithmIdentifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSubjectPublicKeyInfo_get_PublicKeyAlgorithmIdentifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PublicKeyAlgorithmIdentifier)
		this->_Inst_PublicKeyAlgorithmIdentifier = new TElAlgorithmIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_PublicKeyAlgorithmIdentifier->updateHandle(hOutResult);
	return this->_Inst_PublicKeyAlgorithmIdentifier;
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

SB_INLINE int32_t TElSubjectPublicKeyInfo::get_PublicKeyAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElSubjectPublicKeyInfo_get_PublicKeyAlgorithm(_Handle, &OutResult));
	return OutResult;
}

void TElSubjectPublicKeyInfo::get_RawData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSubjectPublicKeyInfo_get_RawData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1237146979, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSubjectPublicKeyInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	this->_Inst_PublicKeyAlgorithmIdentifier = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
}

TElSubjectPublicKeyInfo::TElSubjectPublicKeyInfo(TElSubjectPublicKeyInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElSubjectPublicKeyInfo::TElSubjectPublicKeyInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSubjectPublicKeyInfo_Create(&_Handle));
}

TElSubjectPublicKeyInfo::~TElSubjectPublicKeyInfo()
{
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	delete this->_Inst_PublicKeyAlgorithmIdentifier;
	this->_Inst_PublicKeyAlgorithmIdentifier = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
}
#endif /* SB_USE_CLASS_TELSUBJECTPUBLICKEYINFO */

#ifdef SB_USE_CLASS_TELTBSCERTIFICATE

SB_INLINE void TElTBSCertificate::Clear()
{
	SBCheckError(TElTBSCertificate_Clear(_Handle));
}

SB_INLINE uint8_t TElTBSCertificate::get_Version()
{
	uint8_t OutResult;
	SBCheckError(TElTBSCertificate_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTBSCertificate::set_Version(uint8_t Value)
{
	SBCheckError(TElTBSCertificate_set_Version(_Handle, Value));
}

void TElTBSCertificate::get_SerialNumber(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElTBSCertificate_get_SerialNumber(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1550313368, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElTBSCertificate::set_SerialNumber(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElTBSCertificate_set_SerialNumber(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
TElAlgorithmIdentifier* TElTBSCertificate::get_SignatureIdentifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElTBSCertificate_get_SignatureIdentifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureIdentifier)
		this->_Inst_SignatureIdentifier = new TElAlgorithmIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_SignatureIdentifier->updateHandle(hOutResult);
	return this->_Inst_SignatureIdentifier;
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElTBSCertificate::get_Issuer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElTBSCertificate_get_Issuer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Issuer)
		this->_Inst_Issuer = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Issuer->updateHandle(hOutResult);
	return this->_Inst_Issuer;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElTBSCertificate::get_Subject()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElTBSCertificate_get_Subject(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Subject)
		this->_Inst_Subject = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Subject->updateHandle(hOutResult);
	return this->_Inst_Subject;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TELSUBJECTPUBLICKEYINFO
TElSubjectPublicKeyInfo* TElTBSCertificate::get_SubjectPublicKeyInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElTBSCertificate_get_SubjectPublicKeyInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SubjectPublicKeyInfo)
		this->_Inst_SubjectPublicKeyInfo = new TElSubjectPublicKeyInfo(hOutResult, ohFalse);
	else
		this->_Inst_SubjectPublicKeyInfo->updateHandle(hOutResult);
	return this->_Inst_SubjectPublicKeyInfo;
}
#endif /* SB_USE_CLASS_TELSUBJECTPUBLICKEYINFO */

void TElTBSCertificate::get_IssuerUniqueID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElTBSCertificate_get_IssuerUniqueID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1389576247, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElTBSCertificate::set_IssuerUniqueID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElTBSCertificate_set_IssuerUniqueID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElTBSCertificate::get_SubjectUniqueID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElTBSCertificate_get_SubjectUniqueID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-787100948, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElTBSCertificate::set_SubjectUniqueID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElTBSCertificate_set_SubjectUniqueID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE void TElTBSCertificate::get_Validity(TValidity &OutResult)
{
	SBCheckError(TElTBSCertificate_get_Validity(_Handle, &OutResult));
}

SB_INLINE void TElTBSCertificate::set_Validity(TValidity &Value)
{
	SBCheckError(TElTBSCertificate_set_Validity(_Handle, &Value));
}

void TElTBSCertificate::initInstances()
{
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	this->_Inst_SignatureIdentifier = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Subject = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELSUBJECTPUBLICKEYINFO
	this->_Inst_SubjectPublicKeyInfo = NULL;
#endif /* SB_USE_CLASS_TELSUBJECTPUBLICKEYINFO */
}

TElTBSCertificate::TElTBSCertificate(TElTBSCertificateHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElTBSCertificate::TElTBSCertificate() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElTBSCertificate_Create(&_Handle));
}

TElTBSCertificate::~TElTBSCertificate()
{
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	delete this->_Inst_SignatureIdentifier;
	this->_Inst_SignatureIdentifier = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Issuer;
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Subject;
	this->_Inst_Subject = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELSUBJECTPUBLICKEYINFO
	delete this->_Inst_SubjectPublicKeyInfo;
	this->_Inst_SubjectPublicKeyInfo = NULL;
#endif /* SB_USE_CLASS_TELSUBJECTPUBLICKEYINFO */
}
#endif /* SB_USE_CLASS_TELTBSCERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATECHAIN

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
bool TElX509CertificateChain::Add(TElX509Certificate &Certificate)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateChain_Add(_Handle, Certificate.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElX509CertificateChain::Add(TElX509Certificate *Certificate)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateChain_Add(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

TSBCertificateValidity TElX509CertificateChain::Validate(TSBCertificateValidityReason &Reason, int64_t ValidityMoment)
{
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	TSBCertificateValidityRaw OutResultRaw = 0;
	SBCheckError(TElX509CertificateChain_Validate(_Handle, &ReasonRaw, ValidityMoment, &OutResultRaw));
	Reason = (TSBCertificateValidityReason)ReasonRaw;
	return (TSBCertificateValidity)OutResultRaw;
}

TSBCertificateValidity TElX509CertificateChain::Validate(TSBCertificateValidityReason &Reason, bool CheckCACertDates, int64_t ValidityMoment)
{
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	TSBCertificateValidityRaw OutResultRaw = 0;
	SBCheckError(TElX509CertificateChain_Validate_1(_Handle, &ReasonRaw, (int8_t)CheckCACertDates, ValidityMoment, &OutResultRaw));
	Reason = (TSBCertificateValidityReason)ReasonRaw;
	return (TSBCertificateValidity)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElX509CertificateChain::get_Certificates(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509CertificateChain_get_Certificates(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

bool TElX509CertificateChain::get_Complete()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateChain_get_Complete(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElX509CertificateChain::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElX509CertificateChain_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElX509CertificateChain::initInstances()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
}

TElX509CertificateChain::TElX509CertificateChain(TElX509CertificateChainHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElX509CertificateChain::TElX509CertificateChain(TComponent &Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElX509CertificateChain_Create(Owner.getHandle(), &_Handle));
}

TElX509CertificateChain::TElX509CertificateChain(TComponent *Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElX509CertificateChain_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElX509CertificateChain::~TElX509CertificateChain()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATECHAIN */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE

TSBCertFileFormat TElX509Certificate::DetectCertFileFormat(const std::string &FileName)
{
	TSBCertFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElX509Certificate_DetectCertFileFormat(FileName.data(), (int32_t)FileName.length(), &OutResultRaw));
	return (TSBCertFileFormat)OutResultRaw;
}

TSBCertFileFormat TElX509Certificate::DetectCertFileFormat_Inst(const std::string &FileName)
{
	TSBCertFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElX509Certificate_DetectCertFileFormat_1(_Handle, FileName.data(), (int32_t)FileName.length(), &OutResultRaw));
	return (TSBCertFileFormat)OutResultRaw;
}

#ifdef SB_USE_CLASS_TSTREAM
TSBCertFileFormat TElX509Certificate::DetectCertFileFormat(TStream &Stream)
{
	TSBCertFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElX509Certificate_DetectCertFileFormat_2(Stream.getHandle(), &OutResultRaw));
	return (TSBCertFileFormat)OutResultRaw;
}

TSBCertFileFormat TElX509Certificate::DetectCertFileFormat(TStream *Stream)
{
	TSBCertFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElX509Certificate_DetectCertFileFormat_2((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBCertFileFormat)OutResultRaw;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
TSBCertFileFormat TElX509Certificate::DetectCertFileFormat_Inst(TStream &Stream)
{
	TSBCertFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElX509Certificate_DetectCertFileFormat_3(_Handle, Stream.getHandle(), &OutResultRaw));
	return (TSBCertFileFormat)OutResultRaw;
}

TSBCertFileFormat TElX509Certificate::DetectCertFileFormat_Inst(TStream *Stream)
{
	TSBCertFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElX509Certificate_DetectCertFileFormat_3(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBCertFileFormat)OutResultRaw;
}
#endif /* SB_USE_CLASS_TSTREAM */

TSBCertFileFormat TElX509Certificate::DetectCertFileFormat(void * Buffer, int32_t Size)
{
	TSBCertFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElX509Certificate_DetectCertFileFormat_4(Buffer, Size, &OutResultRaw));
	return (TSBCertFileFormat)OutResultRaw;
}

TSBCertFileFormat TElX509Certificate::DetectCertFileFormat_Inst(void * Buffer, int32_t Size)
{
	TSBCertFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElX509Certificate_DetectCertFileFormat_5(_Handle, Buffer, Size, &OutResultRaw));
	return (TSBCertFileFormat)OutResultRaw;
}

#ifdef SB_USE_CLASS_TSTREAM
TSBX509KeyFileFormat TElX509Certificate::DetectKeyFileFormat(TStream &Stream, const std::string &Password)
{
	TSBX509KeyFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElX509Certificate_DetectKeyFileFormat(Stream.getHandle(), Password.data(), (int32_t)Password.length(), &OutResultRaw));
	return (TSBX509KeyFileFormat)OutResultRaw;
}

TSBX509KeyFileFormat TElX509Certificate::DetectKeyFileFormat(TStream *Stream, const std::string &Password)
{
	TSBX509KeyFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElX509Certificate_DetectKeyFileFormat((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), &OutResultRaw));
	return (TSBX509KeyFileFormat)OutResultRaw;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
TSBX509KeyFileFormat TElX509Certificate::DetectKeyFileFormat_Inst(TStream &Stream, const std::string &Password)
{
	TSBX509KeyFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElX509Certificate_DetectKeyFileFormat_1(_Handle, Stream.getHandle(), Password.data(), (int32_t)Password.length(), &OutResultRaw));
	return (TSBX509KeyFileFormat)OutResultRaw;
}

TSBX509KeyFileFormat TElX509Certificate::DetectKeyFileFormat_Inst(TStream *Stream, const std::string &Password)
{
	TSBX509KeyFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElX509Certificate_DetectKeyFileFormat_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), &OutResultRaw));
	return (TSBX509KeyFileFormat)OutResultRaw;
}
#endif /* SB_USE_CLASS_TSTREAM */

TSBX509KeyFileFormat TElX509Certificate::DetectKeyFileFormat(const std::string &FileName, const std::string &Password)
{
	TSBX509KeyFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElX509Certificate_DetectKeyFileFormat_2(FileName.data(), (int32_t)FileName.length(), Password.data(), (int32_t)Password.length(), &OutResultRaw));
	return (TSBX509KeyFileFormat)OutResultRaw;
}

TSBX509KeyFileFormat TElX509Certificate::DetectKeyFileFormat_Inst(const std::string &FileName, const std::string &Password)
{
	TSBX509KeyFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElX509Certificate_DetectKeyFileFormat_3(_Handle, FileName.data(), (int32_t)FileName.length(), Password.data(), (int32_t)Password.length(), &OutResultRaw));
	return (TSBX509KeyFileFormat)OutResultRaw;
}

TSBX509KeyFileFormat TElX509Certificate::DetectKeyFileFormat(void * Buffer, int32_t Size, const std::string &Password)
{
	TSBX509KeyFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElX509Certificate_DetectKeyFileFormat_4(Buffer, Size, Password.data(), (int32_t)Password.length(), &OutResultRaw));
	return (TSBX509KeyFileFormat)OutResultRaw;
}

TSBX509KeyFileFormat TElX509Certificate::DetectKeyFileFormat_Inst(void * Buffer, int32_t Size, const std::string &Password)
{
	TSBX509KeyFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElX509Certificate_DetectKeyFileFormat_5(_Handle, Buffer, Size, Password.data(), (int32_t)Password.length(), &OutResultRaw));
	return (TSBX509KeyFileFormat)OutResultRaw;
}

bool TElX509Certificate::Equals(TElX509Certificate &Other)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_Equals(_Handle, Other.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElX509Certificate::Equals(TElX509Certificate *Other)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_Equals(_Handle, (Other != NULL) ? Other->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElX509Certificate::SameCertificate(TElX509Certificate &Other)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_SameCertificate(_Handle, Other.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElX509Certificate::SameCertificate(TElX509Certificate *Other)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_SameCertificate(_Handle, (Other != NULL) ? Other->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509Certificate::Clone(TElX509Certificate &Dest, bool CopyPrivateKey)
{
	SBCheckError(TElX509Certificate_Clone(_Handle, Dest.getHandle(), (int8_t)CopyPrivateKey));
}

SB_INLINE void TElX509Certificate::Clone(TElX509Certificate *Dest, bool CopyPrivateKey)
{
	SBCheckError(TElX509Certificate_Clone(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE, (int8_t)CopyPrivateKey));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
SB_INLINE void TElX509Certificate::Clone(TElX509Certificate &Dest, TElCustomCryptoProvider &CryptoProvider)
{
	SBCheckError(TElX509Certificate_Clone_1(_Handle, Dest.getHandle(), CryptoProvider.getHandle()));
}

SB_INLINE void TElX509Certificate::Clone(TElX509Certificate *Dest, TElCustomCryptoProvider *CryptoProvider)
{
	SBCheckError(TElX509Certificate_Clone_1(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_WINDOWS
SB_INLINE void TElX509Certificate::ChangeSecurityLevel(TSBCertSecurityLevel Level, const std::string &Password)
{
	SBCheckError(TElX509Certificate_ChangeSecurityLevel(_Handle, (TSBCertSecurityLevelRaw)Level, Password.data(), (int32_t)Password.length()));
}
#endif

bool TElX509Certificate::KeyCorresponds(void * KeyBuffer, int32_t KeySize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_KeyCorresponds(_Handle, KeyBuffer, KeySize, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509Certificate::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElX509Certificate_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE int32_t TElX509Certificate::LoadFromBufferPEM(void * Buffer, int32_t Size, const std::string &PassPhrase)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadFromBufferPEM(_Handle, Buffer, Size, PassPhrase.data(), (int32_t)PassPhrase.length(), &OutResult));
	return OutResult;
}

SB_INLINE void TElX509Certificate::LoadKeyFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElX509Certificate_LoadKeyFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE int32_t TElX509Certificate::LoadKeyFromBufferPEM(void * Buffer, int32_t Size, const std::string &PassPhrase)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadKeyFromBufferPEM(_Handle, Buffer, Size, PassPhrase.data(), (int32_t)PassPhrase.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::LoadFromBufferPFX(void * Buffer, int32_t Size, const std::string &Password)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadFromBufferPFX(_Handle, Buffer, Size, Password.data(), (int32_t)Password.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::LoadFromBufferSPC(void * Buffer, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadFromBufferSPC(_Handle, Buffer, Size, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::LoadKeyFromBufferMS(void * Buffer, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadKeyFromBufferMS(_Handle, Buffer, Size, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::LoadKeyFromBufferPKCS8(void * Buffer, int32_t Size, const std::string &Password)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadKeyFromBufferPKCS8(_Handle, Buffer, Size, Password.data(), (int32_t)Password.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::LoadFromBufferAuto(void * Buffer, int32_t Size, const std::string &Password)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadFromBufferAuto(_Handle, Buffer, Size, Password.data(), (int32_t)Password.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::LoadKeyFromBufferAuto(void * Buffer, int32_t Size, const std::string &Password)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadKeyFromBufferAuto(_Handle, Buffer, Size, Password.data(), (int32_t)Password.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::LoadKeyFromBufferNET(void * Buffer, int32_t Size, const std::string &Password)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadKeyFromBufferNET(_Handle, Buffer, Size, Password.data(), (int32_t)Password.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::LoadKeyFromBufferPVK(void * Buffer, int32_t Size, const std::string &Password)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadKeyFromBufferPVK(_Handle, Buffer, Size, Password.data(), (int32_t)Password.length(), &OutResult));
	return OutResult;
}

SB_INLINE void TElX509Certificate::LoadKeyFromBufferPKCS15(void * Buffer, int32_t Size, const std::string &Password)
{
	SBCheckError(TElX509Certificate_LoadKeyFromBufferPKCS15(_Handle, Buffer, Size, Password.data(), (int32_t)Password.length()));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElX509Certificate::LoadKeyFromStreamPKCS15(TStream &Stream, const std::string &Password, int32_t Count)
{
	SBCheckError(TElX509Certificate_LoadKeyFromStreamPKCS15(_Handle, Stream.getHandle(), Password.data(), (int32_t)Password.length(), Count));
}

SB_INLINE void TElX509Certificate::LoadKeyFromStreamPKCS15(TStream *Stream, const std::string &Password, int32_t Count)
{
	SBCheckError(TElX509Certificate_LoadKeyFromStreamPKCS15(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElX509Certificate::LoadFromStream(TStream &Stream, int32_t Count)
{
	SBCheckError(TElX509Certificate_LoadFromStream(_Handle, Stream.getHandle(), Count));
}

SB_INLINE void TElX509Certificate::LoadFromStream(TStream *Stream, int32_t Count)
{
	SBCheckError(TElX509Certificate_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElX509Certificate::LoadKeyFromStream(TStream &Stream, int32_t Count)
{
	SBCheckError(TElX509Certificate_LoadKeyFromStream(_Handle, Stream.getHandle(), Count));
}

SB_INLINE void TElX509Certificate::LoadKeyFromStream(TStream *Stream, int32_t Count)
{
	SBCheckError(TElX509Certificate_LoadKeyFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElX509Certificate::LoadKeyFromStreamPEM(TStream &Stream, const std::string &PassPhrase, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadKeyFromStreamPEM(_Handle, Stream.getHandle(), PassPhrase.data(), (int32_t)PassPhrase.length(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::LoadKeyFromStreamPEM(TStream *Stream, const std::string &PassPhrase, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadKeyFromStreamPEM(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, PassPhrase.data(), (int32_t)PassPhrase.length(), Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElX509Certificate::LoadFromStreamPEM(TStream &Stream, const std::string &PassPhrase, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadFromStreamPEM(_Handle, Stream.getHandle(), PassPhrase.data(), (int32_t)PassPhrase.length(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::LoadFromStreamPEM(TStream *Stream, const std::string &PassPhrase, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadFromStreamPEM(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, PassPhrase.data(), (int32_t)PassPhrase.length(), Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElX509Certificate::LoadFromStreamPFX(TStream &Stream, const std::string &Password, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadFromStreamPFX(_Handle, Stream.getHandle(), Password.data(), (int32_t)Password.length(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::LoadFromStreamPFX(TStream *Stream, const std::string &Password, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadFromStreamPFX(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElX509Certificate::LoadFromStreamSPC(TStream &Stream, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadFromStreamSPC(_Handle, Stream.getHandle(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::LoadFromStreamSPC(TStream *Stream, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadFromStreamSPC(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElX509Certificate::LoadKeyFromStreamMS(TStream &Stream, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadKeyFromStreamMS(_Handle, Stream.getHandle(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::LoadKeyFromStreamMS(TStream *Stream, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadKeyFromStreamMS(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElX509Certificate::LoadKeyFromStreamPKCS8(TStream &Stream, const std::string &Password, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadKeyFromStreamPKCS8(_Handle, Stream.getHandle(), Password.data(), (int32_t)Password.length(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::LoadKeyFromStreamPKCS8(TStream *Stream, const std::string &Password, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadKeyFromStreamPKCS8(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElX509Certificate::LoadKeyFromStreamPVK(TStream &Stream, const std::string &Password, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadKeyFromStreamPVK(_Handle, Stream.getHandle(), Password.data(), (int32_t)Password.length(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::LoadKeyFromStreamPVK(TStream *Stream, const std::string &Password, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadKeyFromStreamPVK(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElX509Certificate::LoadFromStreamAuto(TStream &Stream, const std::string &Password, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadFromStreamAuto(_Handle, Stream.getHandle(), Password.data(), (int32_t)Password.length(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::LoadFromStreamAuto(TStream *Stream, const std::string &Password, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadFromStreamAuto(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElX509Certificate::LoadKeyFromStreamAuto(TStream &Stream, const std::string &Password, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadKeyFromStreamAuto(_Handle, Stream.getHandle(), Password.data(), (int32_t)Password.length(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::LoadKeyFromStreamAuto(TStream *Stream, const std::string &Password, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadKeyFromStreamAuto(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElX509Certificate::LoadKeyFromStreamNET(TStream &Stream, const std::string &Password, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadKeyFromStreamNET(_Handle, Stream.getHandle(), Password.data(), (int32_t)Password.length(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::LoadKeyFromStreamNET(TStream *Stream, const std::string &Password, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadKeyFromStreamNET(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElX509Certificate::LoadFromFileAuto(const std::string &Filename, const std::string &Password)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadFromFileAuto(_Handle, Filename.data(), (int32_t)Filename.length(), Password.data(), (int32_t)Password.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::LoadKeyFromFileAuto(const std::string &Filename, const std::string &Password)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_LoadKeyFromFileAuto(_Handle, Filename.data(), (int32_t)Filename.length(), Password.data(), (int32_t)Password.length(), &OutResult));
	return OutResult;
}

bool TElX509Certificate::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElX509Certificate::SaveKeyToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_SaveKeyToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElX509Certificate::SaveToBufferPEM(void * Buffer, int32_t &Size, const std::string &PassPhrase)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_SaveToBufferPEM(_Handle, Buffer, &Size, PassPhrase.data(), (int32_t)PassPhrase.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElX509Certificate::SaveKeyToBufferPEM(void * Buffer, int32_t &Size, const std::string &PassPhrase)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_SaveKeyToBufferPEM(_Handle, Buffer, &Size, PassPhrase.data(), (int32_t)PassPhrase.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElX509Certificate::SaveKeyToBufferPEM(void * Buffer, int32_t &Size, int32_t EncryptionAlgorithm, TSBSymmetricCryptoMode EncryptionMode, const std::string &PassPhrase)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_SaveKeyToBufferPEM_1(_Handle, Buffer, &Size, EncryptionAlgorithm, (TSBSymmetricCryptoModeRaw)EncryptionMode, PassPhrase.data(), (int32_t)PassPhrase.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElX509Certificate::SaveToBufferPFX(void * Buffer, int32_t &Size, const std::string &Password, int32_t KeyEncryptionAlgorithm, int32_t CertEncryptionAlgorithm)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_SaveToBufferPFX(_Handle, Buffer, &Size, Password.data(), (int32_t)Password.length(), KeyEncryptionAlgorithm, CertEncryptionAlgorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::SaveToBufferPFX(void * Buffer, int32_t &Size, const std::string &Password)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_SaveToBufferPFX_1(_Handle, Buffer, &Size, Password.data(), (int32_t)Password.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::SaveToBufferSPC(void * Buffer, int32_t &Size)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_SaveToBufferSPC(_Handle, Buffer, &Size, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::SaveKeyToBufferMS(void * Buffer, int32_t &Size)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_SaveKeyToBufferMS(_Handle, Buffer, &Size, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::SaveKeyToBufferNET(void * Buffer, int32_t &Size)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_SaveKeyToBufferNET(_Handle, Buffer, &Size, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::SaveKeyToBufferPVK(void * Buffer, int32_t &Size, const std::string &Password, bool UseStrongEncryption)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_SaveKeyToBufferPVK(_Handle, Buffer, &Size, Password.data(), (int32_t)Password.length(), (int8_t)UseStrongEncryption, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::SaveKeyToBufferPKCS8(void * Buffer, int32_t &Size, const std::string &Password)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_SaveKeyToBufferPKCS8(_Handle, Buffer, &Size, Password.data(), (int32_t)Password.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElX509Certificate::SaveToStream(TStream &Stream)
{
	SBCheckError(TElX509Certificate_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElX509Certificate::SaveToStream(TStream *Stream)
{
	SBCheckError(TElX509Certificate_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElX509Certificate::SaveKeyToStream(TStream &Stream)
{
	SBCheckError(TElX509Certificate_SaveKeyToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElX509Certificate::SaveKeyToStream(TStream *Stream)
{
	SBCheckError(TElX509Certificate_SaveKeyToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElX509Certificate::SaveToStreamPEM(TStream &Stream, const std::string &PassPhrase)
{
	SBCheckError(TElX509Certificate_SaveToStreamPEM(_Handle, Stream.getHandle(), PassPhrase.data(), (int32_t)PassPhrase.length()));
}

SB_INLINE void TElX509Certificate::SaveToStreamPEM(TStream *Stream, const std::string &PassPhrase)
{
	SBCheckError(TElX509Certificate_SaveToStreamPEM(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, PassPhrase.data(), (int32_t)PassPhrase.length()));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElX509Certificate::SaveKeyToStreamPEM(TStream &Stream, const std::string &PassPhrase)
{
	SBCheckError(TElX509Certificate_SaveKeyToStreamPEM(_Handle, Stream.getHandle(), PassPhrase.data(), (int32_t)PassPhrase.length()));
}

SB_INLINE void TElX509Certificate::SaveKeyToStreamPEM(TStream *Stream, const std::string &PassPhrase)
{
	SBCheckError(TElX509Certificate_SaveKeyToStreamPEM(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, PassPhrase.data(), (int32_t)PassPhrase.length()));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElX509Certificate::SaveKeyToStreamPEM(TStream &Stream, int32_t EncryptionAlgorithm, TSBSymmetricCryptoMode EncryptionMode, const std::string &PassPhrase)
{
	SBCheckError(TElX509Certificate_SaveKeyToStreamPEM_1(_Handle, Stream.getHandle(), EncryptionAlgorithm, (TSBSymmetricCryptoModeRaw)EncryptionMode, PassPhrase.data(), (int32_t)PassPhrase.length()));
}

SB_INLINE void TElX509Certificate::SaveKeyToStreamPEM(TStream *Stream, int32_t EncryptionAlgorithm, TSBSymmetricCryptoMode EncryptionMode, const std::string &PassPhrase)
{
	SBCheckError(TElX509Certificate_SaveKeyToStreamPEM_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, EncryptionAlgorithm, (TSBSymmetricCryptoModeRaw)EncryptionMode, PassPhrase.data(), (int32_t)PassPhrase.length()));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElX509Certificate::SaveToStreamPFX(TStream &Stream, const std::string &Password, int32_t KeyEncryptionAlgorithm, int32_t CertEncryptionAlgorithm)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_SaveToStreamPFX(_Handle, Stream.getHandle(), Password.data(), (int32_t)Password.length(), KeyEncryptionAlgorithm, CertEncryptionAlgorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::SaveToStreamPFX(TStream *Stream, const std::string &Password, int32_t KeyEncryptionAlgorithm, int32_t CertEncryptionAlgorithm)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_SaveToStreamPFX(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), KeyEncryptionAlgorithm, CertEncryptionAlgorithm, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElX509Certificate::SaveToStreamPFX(TStream &Stream, const std::string &Password)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_SaveToStreamPFX_1(_Handle, Stream.getHandle(), Password.data(), (int32_t)Password.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::SaveToStreamPFX(TStream *Stream, const std::string &Password)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_SaveToStreamPFX_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElX509Certificate::SaveToStreamSPC(TStream &Stream)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_SaveToStreamSPC(_Handle, Stream.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::SaveToStreamSPC(TStream *Stream)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_SaveToStreamSPC(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElX509Certificate::SaveKeyValueToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_SaveKeyValueToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElX509Certificate::SaveKeyToStreamMS(TStream &Stream)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_SaveKeyToStreamMS(_Handle, Stream.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::SaveKeyToStreamMS(TStream *Stream)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_SaveKeyToStreamMS(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElX509Certificate::SaveKeyToStreamNET(TStream &Stream, const std::string &Password)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_SaveKeyToStreamNET(_Handle, Stream.getHandle(), Password.data(), (int32_t)Password.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::SaveKeyToStreamNET(TStream *Stream, const std::string &Password)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_SaveKeyToStreamNET(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElX509Certificate::SaveKeyToStreamPVK(TStream &Stream, const std::string &Password, bool UseStrongEncryption)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_SaveKeyToStreamPVK(_Handle, Stream.getHandle(), Password.data(), (int32_t)Password.length(), (int8_t)UseStrongEncryption, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::SaveKeyToStreamPVK(TStream *Stream, const std::string &Password, bool UseStrongEncryption)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_SaveKeyToStreamPVK(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), (int8_t)UseStrongEncryption, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElX509Certificate::SaveKeyToStreamPKCS8(TStream &Stream, const std::string &Password)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_SaveKeyToStreamPKCS8(_Handle, Stream.getHandle(), Password.data(), (int32_t)Password.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::SaveKeyToStreamPKCS8(TStream *Stream, const std::string &Password)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_SaveKeyToStreamPKCS8(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElX509Certificate::SaveToFile(const std::string &Filename, const std::string &Password, TSBCertFileFormat Format)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_SaveToFile(_Handle, Filename.data(), (int32_t)Filename.length(), Password.data(), (int32_t)Password.length(), (TSBCertFileFormatRaw)Format, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::SaveKeyToFile(const std::string &Filename, const std::string &Password, TSBX509KeyFileFormat Format)
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_SaveKeyToFile(_Handle, Filename.data(), (int32_t)Filename.length(), Password.data(), (int32_t)Password.length(), (TSBX509KeyFileFormatRaw)Format, &OutResult));
	return OutResult;
}

bool TElX509Certificate::Validate()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_Validate(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElX509Certificate::ValidateWithCA(TElX509Certificate &CACertificate)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_ValidateWithCA(_Handle, CACertificate.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElX509Certificate::ValidateWithCA(TElX509Certificate *CACertificate)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_ValidateWithCA(_Handle, (CACertificate != NULL) ? CACertificate->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElX509Certificate::GetRSAParams(void * RSAModulus, int32_t &RSAModulusSize, void * RSAPublicKey, int32_t &RSAPublicKeySize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_GetRSAParams(_Handle, RSAModulus, &RSAModulusSize, RSAPublicKey, &RSAPublicKeySize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElX509Certificate::GetDSSParams(void * DSSP, int32_t &DSSPSize, void * DSSQ, int32_t &DSSQSize, void * DSSG, int32_t &DSSGSize, void * DSSY, int32_t &DSSYSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_GetDSSParams(_Handle, DSSP, &DSSPSize, DSSQ, &DSSQSize, DSSG, &DSSGSize, DSSY, &DSSYSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElX509Certificate::GetDHParams(void * DHP, int32_t &DHPSize, void * DHG, int32_t &DHGSize, void * DHY, int32_t &DHYSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_GetDHParams(_Handle, DHP, &DHPSize, DHG, &DHGSize, DHY, &DHYSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElX509Certificate::GetPublicKeyBlob(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_GetPublicKeyBlob(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElX509Certificate::GetPublicKeyBlob(std::vector<uint8_t> &Buffer)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = TElX509Certificate_GetPublicKeyBlob_1(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(1895636891, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}

void TElX509Certificate::GetFullPublicKeyInfo(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElX509Certificate_GetFullPublicKeyInfo(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-391546948, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElX509Certificate::GetHashMD5(TMessageDigest128 &OutResult)
{
	SBCheckError(TElX509Certificate_GetHashMD5(_Handle, &OutResult));
}

SB_INLINE void TElX509Certificate::GetHashSHA1(TMessageDigest160 &OutResult)
{
	SBCheckError(TElX509Certificate_GetHashSHA1(_Handle, &OutResult));
}

SB_INLINE void TElX509Certificate::GetKeyHashSHA1(TMessageDigest160 &OutResult)
{
	SBCheckError(TElX509Certificate_GetKeyHashSHA1(_Handle, &OutResult));
}

void TElX509Certificate::GetCertificateHash(int32_t Alg, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElX509Certificate_GetCertificateHash(_Handle, Alg, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(49747905, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElX509Certificate::GetZIPCertIdentifier(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElX509Certificate_GetZIPCertIdentifier(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1403853555, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElX509Certificate::GetPublicKeySize()
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_GetPublicKeySize(_Handle, &OutResult));
	return OutResult;
}

bool TElX509Certificate::IsKeyValid()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_IsKeyValid(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElX509Certificate::WriteSerialNumber(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElX509Certificate_WriteSerialNumber(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1135946298, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElX509Certificate::WriteExtensionSubjectKeyIdentifier(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElX509Certificate_WriteExtensionSubjectKeyIdentifier(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1366780379, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElX509Certificate::WriteSubject(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElX509Certificate_WriteSubject(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1735691447, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElX509Certificate::WriteIssuer(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElX509Certificate_WriteIssuer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1541423869, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
SB_INLINE void TElX509Certificate::SetKeyMaterial(TElPublicKeyMaterial &Value)
{
	SBCheckError(TElX509Certificate_SetKeyMaterial(_Handle, Value.getHandle()));
}

SB_INLINE void TElX509Certificate::SetKeyMaterial(TElPublicKeyMaterial *Value)
{
	SBCheckError(TElX509Certificate_SetKeyMaterial(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

#ifdef SB_WINDOWS
bool TElX509Certificate::View(uint32_t Owner)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_View(_Handle, Owner, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif

SB_INLINE TClassHandle TElX509Certificate::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElX509Certificate_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE PByteArray TElX509Certificate::get_CertificateBinary()
{
	PByteArray OutResult;
	SBCheckError(TElX509Certificate_get_CertificateBinary(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::get_CertificateSize()
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_get_CertificateSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509Certificate::get_SignatureAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_get_SignatureAlgorithm(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
TElAlgorithmIdentifier* TElX509Certificate::get_SignatureAlgorithmIdentifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509Certificate_get_SignatureAlgorithmIdentifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureAlgorithmIdentifier)
		this->_Inst_SignatureAlgorithmIdentifier = new TElAlgorithmIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_SignatureAlgorithmIdentifier->updateHandle(hOutResult);
	return this->_Inst_SignatureAlgorithmIdentifier;
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

void TElX509Certificate::get_Signature(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElX509Certificate_get_Signature(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2015754211, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE uint8_t TElX509Certificate::get_Version()
{
	uint8_t OutResult;
	SBCheckError(TElX509Certificate_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElX509Certificate::set_Version(uint8_t Value)
{
	SBCheckError(TElX509Certificate_set_Version(_Handle, Value));
}

void TElX509Certificate::get_SerialNumber(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElX509Certificate_get_SerialNumber(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1256753856, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElX509Certificate::set_SerialNumber(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElX509Certificate_set_SerialNumber(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int64_t TElX509Certificate::get_ValidFrom()
{
	int64_t OutResult;
	SBCheckError(TElX509Certificate_get_ValidFrom(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElX509Certificate::set_ValidFrom(int64_t Value)
{
	SBCheckError(TElX509Certificate_set_ValidFrom(_Handle, Value));
}

SB_INLINE int64_t TElX509Certificate::get_ValidTo()
{
	int64_t OutResult;
	SBCheckError(TElX509Certificate_get_ValidTo(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElX509Certificate::set_ValidTo(int64_t Value)
{
	SBCheckError(TElX509Certificate_set_ValidTo(_Handle, Value));
}

SB_INLINE int32_t TElX509Certificate::get_BelongsTo()
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_get_BelongsTo(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElX509Certificate::set_BelongsTo(int32_t Value)
{
	SBCheckError(TElX509Certificate_set_BelongsTo(_Handle, Value));
#ifdef SB_WINDOWS
}

SB_INLINE PCCERT_CONTEXT TElX509Certificate::get_CertHandle()
{
	PCCERT_CONTEXT OutResult;
	SBCheckError(TElX509Certificate_get_CertHandle(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElX509Certificate::set_CertHandle(PCCERT_CONTEXT Value)
{
	SBCheckError(TElX509Certificate_set_CertHandle(_Handle, Value));
}

void TElX509Certificate::get_FriendlyName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElX509Certificate_get_FriendlyName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(25891678, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElX509Certificate::set_FriendlyName(const std::string &Value)
{
	SBCheckError(TElX509Certificate_set_FriendlyName(_Handle, Value.data(), (int32_t)Value.length()));
#endif
}

void TElX509Certificate::get_IssuerUniqueID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElX509Certificate_get_IssuerUniqueID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1015932407, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElX509Certificate::get_SubjectUniqueID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElX509Certificate_get_SubjectUniqueID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1243567865, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElX509Certificate::get_PublicKeyAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElX509Certificate_get_PublicKeyAlgorithm(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
TElAlgorithmIdentifier* TElX509Certificate::get_PublicKeyAlgorithmIdentifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509Certificate_get_PublicKeyAlgorithmIdentifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PublicKeyAlgorithmIdentifier)
		this->_Inst_PublicKeyAlgorithmIdentifier = new TElAlgorithmIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_PublicKeyAlgorithmIdentifier->updateHandle(hOutResult);
	return this->_Inst_PublicKeyAlgorithmIdentifier;
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

bool TElX509Certificate::get_PrivateKeyExists()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_get_PrivateKeyExists(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElX509Certificate::get_PrivateKeyExtractable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_get_PrivateKeyExtractable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElX509Certificate::get_CAAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_get_CAAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509Certificate::set_CAAvailable(bool Value)
{
	SBCheckError(TElX509Certificate_set_CAAvailable(_Handle, (int8_t)Value));
}

bool TElX509Certificate::get_SelfSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_get_SelfSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509Certificate::get_IssuerName(TName &OutResult)
{
	SBCheckError(TElX509Certificate_get_IssuerName(_Handle, &OutResult));
}

SB_INLINE void TElX509Certificate::get_SubjectName(TName &OutResult)
{
	SBCheckError(TElX509Certificate_get_SubjectName(_Handle, &OutResult));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElX509Certificate::get_IssuerRDN()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509Certificate_get_IssuerRDN(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IssuerRDN)
		this->_Inst_IssuerRDN = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_IssuerRDN->updateHandle(hOutResult);
	return this->_Inst_IssuerRDN;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElX509Certificate::get_SubjectRDN()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509Certificate_get_SubjectRDN(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SubjectRDN)
		this->_Inst_SubjectRDN = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_SubjectRDN->updateHandle(hOutResult);
	return this->_Inst_SubjectRDN;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
TElCertificateExtensions* TElX509Certificate::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509Certificate_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TElCertificateExtensions(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */

#ifdef SB_USE_CLASS_TELBASECERTSTORAGE
TElBaseCertStorage* TElX509Certificate::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509Certificate_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElBaseCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElX509Certificate::set_CertStorage(TElBaseCertStorage &Value)
{
	SBCheckError(TElX509Certificate_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElX509Certificate::set_CertStorage(TElBaseCertStorage *Value)
{
	SBCheckError(TElX509Certificate_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELBASECERTSTORAGE */

void TElX509Certificate::get_StorageName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElX509Certificate_get_StorageName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(116811679, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElX509Certificate::set_StorageName(const std::string &Value)
{
	SBCheckError(TElX509Certificate_set_StorageName(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElX509Certificate::get_CanEncrypt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_get_CanEncrypt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElX509Certificate::get_CanSign()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_get_CanSign(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElX509Certificate::get_StrictMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_get_StrictMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509Certificate::set_StrictMode(bool Value)
{
	SBCheckError(TElX509Certificate_set_StrictMode(_Handle, (int8_t)Value));
}

bool TElX509Certificate::get_UseUTF8()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_get_UseUTF8(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509Certificate::set_UseUTF8(bool Value)
{
	SBCheckError(TElX509Certificate_set_UseUTF8(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATECHAIN
TElX509CertificateChain* TElX509Certificate::get_Chain()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509Certificate_get_Chain(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Chain)
		this->_Inst_Chain = new TElX509CertificateChain(hOutResult, ohFalse);
	else
		this->_Inst_Chain->updateHandle(hOutResult);
	return this->_Inst_Chain;
}

SB_INLINE void TElX509Certificate::set_Chain(TElX509CertificateChain &Value)
{
	SBCheckError(TElX509Certificate_set_Chain(_Handle, Value.getHandle()));
}

SB_INLINE void TElX509Certificate::set_Chain(TElX509CertificateChain *Value)
{
	SBCheckError(TElX509Certificate_set_Chain(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATECHAIN */

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
TElPublicKeyMaterial* TElX509Certificate::get_KeyMaterial()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509Certificate_get_KeyMaterial(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyMaterial)
		this->_Inst_KeyMaterial = new TElPublicKeyMaterial(hOutResult, ohFalse);
	else
		this->_Inst_KeyMaterial->updateHandle(hOutResult);
	return this->_Inst_KeyMaterial;
}
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

bool TElX509Certificate::get_NegativeSerial()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_get_NegativeSerial(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElX509Certificate::get_ReportErrorOnPartialLoad()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_get_ReportErrorOnPartialLoad(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509Certificate::set_ReportErrorOnPartialLoad(bool Value)
{
	SBCheckError(TElX509Certificate_set_ReportErrorOnPartialLoad(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProvider* TElX509Certificate::get_CryptoProvider()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509Certificate_get_CryptoProvider(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProvider)
		this->_Inst_CryptoProvider = new TElCustomCryptoProvider(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProvider->updateHandle(hOutResult);
	return this->_Inst_CryptoProvider;
}

SB_INLINE void TElX509Certificate::set_CryptoProvider(TElCustomCryptoProvider &Value)
{
	SBCheckError(TElX509Certificate_set_CryptoProvider(_Handle, Value.getHandle()));
}

SB_INLINE void TElX509Certificate::set_CryptoProvider(TElCustomCryptoProvider *Value)
{
	SBCheckError(TElX509Certificate_set_CryptoProvider(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElX509Certificate::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509Certificate_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElX509Certificate::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElX509Certificate_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElX509Certificate::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElX509Certificate_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

bool TElX509Certificate::get_IgnoreVersion()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509Certificate_get_IgnoreVersion(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509Certificate::set_IgnoreVersion(bool Value)
{
	SBCheckError(TElX509Certificate_set_IgnoreVersion(_Handle, (int8_t)Value));
}

void TElX509Certificate::initInstances()
{
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	this->_Inst_SignatureAlgorithmIdentifier = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	this->_Inst_PublicKeyAlgorithmIdentifier = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_IssuerRDN = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_SubjectRDN = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */
#ifdef SB_USE_CLASS_TELBASECERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELBASECERTSTORAGE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATECHAIN
	this->_Inst_Chain = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATECHAIN */
#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
	this->_Inst_KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}

TElX509Certificate::TElX509Certificate(TElX509CertificateHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElX509Certificate::TElX509Certificate(TComponent &Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElX509Certificate_Create(Owner.getHandle(), &_Handle));
}

TElX509Certificate::TElX509Certificate(TComponent *Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElX509Certificate_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElX509Certificate::~TElX509Certificate()
{
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	delete this->_Inst_SignatureAlgorithmIdentifier;
	this->_Inst_SignatureAlgorithmIdentifier = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	delete this->_Inst_PublicKeyAlgorithmIdentifier;
	this->_Inst_PublicKeyAlgorithmIdentifier = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_IssuerRDN;
	this->_Inst_IssuerRDN = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_SubjectRDN;
	this->_Inst_SubjectRDN = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */
#ifdef SB_USE_CLASS_TELBASECERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELBASECERTSTORAGE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATECHAIN
	delete this->_Inst_Chain;
	this->_Inst_Chain = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATECHAIN */
#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
	delete this->_Inst_KeyMaterial;
	this->_Inst_KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	delete this->_Inst_CryptoProvider;
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELBASECERTSTORAGE

TElBaseCertStorage::TElBaseCertStorage(TElBaseCertStorageHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElBaseCertStorage::TElBaseCertStorage(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBaseCertStorage_Create(AOwner.getHandle(), &_Handle));
}

TElBaseCertStorage::TElBaseCertStorage(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBaseCertStorage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELBASECERTSTORAGE */

#ifdef SB_USE_GLOBAL_PROCS_X509

void PVKHeaderToByteArray(const TPVKHeader &Header, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBX509_PVKHeaderToByteArray(&Header, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1397676188, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void PVK_DeriveKey(const std::vector<uint8_t> &Password, const std::vector<uint8_t> &Salt, bool AWeakMethod, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBX509_PVK_DeriveKey(SB_STD_VECTOR_FRONT_ADR(Password), (int32_t)Password.size(), SB_STD_VECTOR_FRONT_ADR(Salt), (int32_t)Salt.size(), (int8_t)AWeakMethod, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1524318432, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void RaiseX509Error(int32_t ErrorCode)
{
	SBCheckError(SBX509_RaiseX509Error(ErrorCode));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
bool SerialNumberCorresponds(TElX509Certificate &Cert, const std::vector<uint8_t> &Serial)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBX509_SerialNumberCorresponds(Cert.getHandle(), SB_STD_VECTOR_FRONT_ADR(Serial), (int32_t)Serial.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}
bool SerialNumberCorresponds(TElX509Certificate *Cert, const std::vector<uint8_t> &Serial)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBX509_SerialNumberCorresponds((Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Serial), (int32_t)Serial.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
void GetOriginalSerialNumber(TElX509Certificate &Cert, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBX509_GetOriginalSerialNumber(Cert.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1208235518, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void GetOriginalSerialNumber(TElX509Certificate *Cert, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBX509_GetOriginalSerialNumber((Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1208235518, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

bool GetX509NegativeSerialWorkaround()
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBX509_GetX509NegativeSerialWorkaround(&OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void SetX509NegativeSerialWorkaround(bool Value)
{
	SBCheckError(SBX509_SetX509NegativeSerialWorkaround((int8_t)Value));
}

#endif /* SB_USE_GLOBAL_PROCS_X509 */

};	/* namespace SecureBlackbox */
