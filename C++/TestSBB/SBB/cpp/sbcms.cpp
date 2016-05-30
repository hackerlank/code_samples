#include "sbcms.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELASN1DIRECTORYSTRING

void TElASN1DirectoryString::get_Value(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElASN1DirectoryString_get_Value(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-56606743, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElASN1DirectoryString::set_Value(const std::string &Value)
{
	SBCheckError(TElASN1DirectoryString_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBASN1DirectoryStringEncoding TElASN1DirectoryString::get_Encoding()
{
	TSBASN1DirectoryStringEncodingRaw OutResultRaw = 0;
	SBCheckError(TElASN1DirectoryString_get_Encoding(_Handle, &OutResultRaw));
	return (TSBASN1DirectoryStringEncoding)OutResultRaw;
}

SB_INLINE void TElASN1DirectoryString::set_Encoding(TSBASN1DirectoryStringEncoding Value)
{
	SBCheckError(TElASN1DirectoryString_set_Encoding(_Handle, (TSBASN1DirectoryStringEncodingRaw)Value));
}

TElASN1DirectoryString::TElASN1DirectoryString(TElASN1DirectoryStringHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElASN1DirectoryString::TElASN1DirectoryString() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASN1DirectoryString_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELASN1DIRECTORYSTRING */

#ifdef SB_USE_CLASS_TELCMSPROPERTY

bool TElCMSProperty::get_Included()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSProperty_get_Included(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMSProperty::set_Included(bool Value)
{
	SBCheckError(TElCMSProperty_set_Included(_Handle, (int8_t)Value));
}

bool TElCMSProperty::get_Signed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSProperty_get_Signed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMSProperty::set_Signed(bool Value)
{
	SBCheckError(TElCMSProperty_set_Signed(_Handle, (int8_t)Value));
}

bool TElCMSProperty::get_RecalculateValue()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSProperty_get_RecalculateValue(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMSProperty::set_RecalculateValue(bool Value)
{
	SBCheckError(TElCMSProperty_set_RecalculateValue(_Handle, (int8_t)Value));
}

void TElCMSProperty::get_RawValue(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSProperty_get_RawValue(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1781252699, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElCMSProperty::TElCMSProperty(TElCMSPropertyHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElCMSProperty::TElCMSProperty() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCMSProperty_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCMSPROPERTY */

#ifdef SB_USE_CLASS_TELCMSHASH

SB_INLINE void TElCMSHash::Clear()
{
	SBCheckError(TElCMSHash_Clear(_Handle));
}

SB_INLINE int32_t TElCMSHash::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElCMSHash_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCMSHash::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElCMSHash_set_HashAlgorithm(_Handle, Value));
}

void TElCMSHash::get_HashAlgorithmParams(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSHash_get_HashAlgorithmParams(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1552069653, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSHash::set_HashAlgorithmParams(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCMSHash_set_HashAlgorithmParams(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElCMSHash::get_HashValue(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSHash_get_HashValue(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1272502510, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSHash::set_HashValue(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCMSHash_set_HashValue(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElCMSHash::TElCMSHash(TElCMSHashHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElCMSHash::TElCMSHash() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCMSHash_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCMSHASH */

#ifdef SB_USE_CLASS_TELCMSSIGNERIDENTIFIER

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElCMSSignerIdentifier::Import(TElX509Certificate &Cert, int32_t HashAlgorithm)
{
	SBCheckError(TElCMSSignerIdentifier_Import(_Handle, Cert.getHandle(), HashAlgorithm));
}

SB_INLINE void TElCMSSignerIdentifier::Import(TElX509Certificate *Cert, int32_t HashAlgorithm)
{
	SBCheckError(TElCMSSignerIdentifier_Import(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, HashAlgorithm));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE void TElCMSSignerIdentifier::Clear()
{
	SBCheckError(TElCMSSignerIdentifier_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
bool TElCMSSignerIdentifier::Corresponds(TElX509Certificate &Cert)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSSignerIdentifier_Corresponds(_Handle, Cert.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCMSSignerIdentifier::Corresponds(TElX509Certificate *Cert)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSSignerIdentifier_Corresponds(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELCMSHASH
TElCMSHash* TElCMSSignerIdentifier::get_Hash()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignerIdentifier_get_Hash(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Hash)
		this->_Inst_Hash = new TElCMSHash(hOutResult, ohFalse);
	else
		this->_Inst_Hash->updateHandle(hOutResult);
	return this->_Inst_Hash;
}
#endif /* SB_USE_CLASS_TELCMSHASH */

#ifdef SB_USE_CLASS_TELGENERALNAMES
TElGeneralNames* TElCMSSignerIdentifier::get_Issuer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignerIdentifier_get_Issuer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Issuer)
		this->_Inst_Issuer = new TElGeneralNames(hOutResult, ohFalse);
	else
		this->_Inst_Issuer->updateHandle(hOutResult);
	return this->_Inst_Issuer;
}
#endif /* SB_USE_CLASS_TELGENERALNAMES */

void TElCMSSignerIdentifier::get_SerialNumber(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSSignerIdentifier_get_SerialNumber(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2122149540, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBCMSSignerIdentifierType TElCMSSignerIdentifier::get_SignerIdentifierType()
{
	TSBCMSSignerIdentifierTypeRaw OutResultRaw = 0;
	SBCheckError(TElCMSSignerIdentifier_get_SignerIdentifierType(_Handle, &OutResultRaw));
	return (TSBCMSSignerIdentifierType)OutResultRaw;
}

SB_INLINE void TElCMSSignerIdentifier::set_SignerIdentifierType(TSBCMSSignerIdentifierType Value)
{
	SBCheckError(TElCMSSignerIdentifier_set_SignerIdentifierType(_Handle, (TSBCMSSignerIdentifierTypeRaw)Value));
}

void TElCMSSignerIdentifier::initInstances()
{
#ifdef SB_USE_CLASS_TELCMSHASH
	this->_Inst_Hash = NULL;
#endif /* SB_USE_CLASS_TELCMSHASH */
#ifdef SB_USE_CLASS_TELGENERALNAMES
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAMES */
}

TElCMSSignerIdentifier::TElCMSSignerIdentifier(TElCMSSignerIdentifierHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCMSSignerIdentifier::TElCMSSignerIdentifier() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSSignerIdentifier_Create(&_Handle));
}

TElCMSSignerIdentifier::~TElCMSSignerIdentifier()
{
#ifdef SB_USE_CLASS_TELCMSHASH
	delete this->_Inst_Hash;
	this->_Inst_Hash = NULL;
#endif /* SB_USE_CLASS_TELCMSHASH */
#ifdef SB_USE_CLASS_TELGENERALNAMES
	delete this->_Inst_Issuer;
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAMES */
}
#endif /* SB_USE_CLASS_TELCMSSIGNERIDENTIFIER */

#ifdef SB_USE_CLASS_TELCMSCERTIFICATEREFS

SB_INLINE int32_t TElCMSCertificateRefs::Add()
{
	int32_t OutResult;
	SBCheckError(TElCMSCertificateRefs_Add(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCMSCertificateRefs::Remove(int32_t Index)
{
	SBCheckError(TElCMSCertificateRefs_Remove(_Handle, Index));
}

SB_INLINE void TElCMSCertificateRefs::Clear()
{
	SBCheckError(TElCMSCertificateRefs_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELCMSSIGNERIDENTIFIER
TElCMSSignerIdentifier* TElCMSCertificateRefs::get_CertIDs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSCertificateRefs_get_CertIDs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertIDs)
		this->_Inst_CertIDs = new TElCMSSignerIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_CertIDs->updateHandle(hOutResult);
	return this->_Inst_CertIDs;
}
#endif /* SB_USE_CLASS_TELCMSSIGNERIDENTIFIER */

SB_INLINE int32_t TElCMSCertificateRefs::get_CertIDCount()
{
	int32_t OutResult;
	SBCheckError(TElCMSCertificateRefs_get_CertIDCount(_Handle, &OutResult));
	return OutResult;
}

void TElCMSCertificateRefs::initInstances()
{
#ifdef SB_USE_CLASS_TELCMSSIGNERIDENTIFIER
	this->_Inst_CertIDs = NULL;
#endif /* SB_USE_CLASS_TELCMSSIGNERIDENTIFIER */
}

TElCMSCertificateRefs::TElCMSCertificateRefs(TElCMSCertificateRefsHandle handle, TElOwnHandle ownHandle) : TElCMSProperty(handle, ownHandle)
{
	initInstances();
}

TElCMSCertificateRefs::TElCMSCertificateRefs() : TElCMSProperty(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSCertificateRefs_Create(&_Handle));
}

TElCMSCertificateRefs::~TElCMSCertificateRefs()
{
#ifdef SB_USE_CLASS_TELCMSSIGNERIDENTIFIER
	delete this->_Inst_CertIDs;
	this->_Inst_CertIDs = NULL;
#endif /* SB_USE_CLASS_TELCMSSIGNERIDENTIFIER */
}
#endif /* SB_USE_CLASS_TELCMSCERTIFICATEREFS */

#ifdef SB_USE_CLASS_TELCMSCRLIDENTIFIER

SB_INLINE void TElCMSCRLIdentifier::Clear()
{
	SBCheckError(TElCMSCRLIdentifier_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElCMSCRLIdentifier::get_Issuer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSCRLIdentifier_get_Issuer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Issuer)
		this->_Inst_Issuer = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_Issuer->updateHandle(hOutResult);
	return this->_Inst_Issuer;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE int64_t TElCMSCRLIdentifier::get_Time()
{
	int64_t OutResult;
	SBCheckError(TElCMSCRLIdentifier_get_Time(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCMSCRLIdentifier::set_Time(int64_t Value)
{
	SBCheckError(TElCMSCRLIdentifier_set_Time(_Handle, Value));
}

SB_INLINE int32_t TElCMSCRLIdentifier::get_Number()
{
	int32_t OutResult;
	SBCheckError(TElCMSCRLIdentifier_get_Number(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCMSCRLIdentifier::set_Number(int32_t Value)
{
	SBCheckError(TElCMSCRLIdentifier_set_Number(_Handle, Value));
}

void TElCMSCRLIdentifier::initInstances()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
}

TElCMSCRLIdentifier::TElCMSCRLIdentifier(TElCMSCRLIdentifierHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCMSCRLIdentifier::TElCMSCRLIdentifier() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSCRLIdentifier_Create(&_Handle));
}

TElCMSCRLIdentifier::~TElCMSCRLIdentifier()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_Issuer;
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
}
#endif /* SB_USE_CLASS_TELCMSCRLIDENTIFIER */

#ifdef SB_USE_CLASS_TELCMSCRLVALIDATEDID

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
SB_INLINE void TElCMSCRLValidatedID::Import(TElCertificateRevocationList &CRL, int32_t HashAlgorithm)
{
	SBCheckError(TElCMSCRLValidatedID_Import(_Handle, CRL.getHandle(), HashAlgorithm));
}

SB_INLINE void TElCMSCRLValidatedID::Import(TElCertificateRevocationList *CRL, int32_t HashAlgorithm)
{
	SBCheckError(TElCMSCRLValidatedID_Import(_Handle, (CRL != NULL) ? CRL->getHandle() : SB_NULL_HANDLE, HashAlgorithm));
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
bool TElCMSCRLValidatedID::CRLMatches(TElCertificateRevocationList &CRL)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSCRLValidatedID_CRLMatches(_Handle, CRL.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCMSCRLValidatedID::CRLMatches(TElCertificateRevocationList *CRL)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSCRLValidatedID_CRLMatches(_Handle, (CRL != NULL) ? CRL->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

#ifdef SB_USE_CLASS_TELCMSHASH
TElCMSHash* TElCMSCRLValidatedID::get_CRLHash()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSCRLValidatedID_get_CRLHash(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CRLHash)
		this->_Inst_CRLHash = new TElCMSHash(hOutResult, ohFalse);
	else
		this->_Inst_CRLHash->updateHandle(hOutResult);
	return this->_Inst_CRLHash;
}
#endif /* SB_USE_CLASS_TELCMSHASH */

#ifdef SB_USE_CLASS_TELCMSCRLIDENTIFIER
TElCMSCRLIdentifier* TElCMSCRLValidatedID::get_CRLIdentifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSCRLValidatedID_get_CRLIdentifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CRLIdentifier)
		this->_Inst_CRLIdentifier = new TElCMSCRLIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_CRLIdentifier->updateHandle(hOutResult);
	return this->_Inst_CRLIdentifier;
}
#endif /* SB_USE_CLASS_TELCMSCRLIDENTIFIER */

void TElCMSCRLValidatedID::initInstances()
{
#ifdef SB_USE_CLASS_TELCMSHASH
	this->_Inst_CRLHash = NULL;
#endif /* SB_USE_CLASS_TELCMSHASH */
#ifdef SB_USE_CLASS_TELCMSCRLIDENTIFIER
	this->_Inst_CRLIdentifier = NULL;
#endif /* SB_USE_CLASS_TELCMSCRLIDENTIFIER */
}

TElCMSCRLValidatedID::TElCMSCRLValidatedID(TElCMSCRLValidatedIDHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCMSCRLValidatedID::TElCMSCRLValidatedID() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSCRLValidatedID_Create(&_Handle));
}

TElCMSCRLValidatedID::~TElCMSCRLValidatedID()
{
#ifdef SB_USE_CLASS_TELCMSHASH
	delete this->_Inst_CRLHash;
	this->_Inst_CRLHash = NULL;
#endif /* SB_USE_CLASS_TELCMSHASH */
#ifdef SB_USE_CLASS_TELCMSCRLIDENTIFIER
	delete this->_Inst_CRLIdentifier;
	this->_Inst_CRLIdentifier = NULL;
#endif /* SB_USE_CLASS_TELCMSCRLIDENTIFIER */
}
#endif /* SB_USE_CLASS_TELCMSCRLVALIDATEDID */

#ifdef SB_USE_CLASS_TELCMSOCSPIDENTIFIER

SB_INLINE void TElCMSOCSPIdentifier::Assign(TElCMSOCSPIdentifier &Source)
{
	SBCheckError(TElCMSOCSPIdentifier_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElCMSOCSPIdentifier::Assign(TElCMSOCSPIdentifier *Source)
{
	SBCheckError(TElCMSOCSPIdentifier_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElCMSOCSPIdentifier::Clear()
{
	SBCheckError(TElCMSOCSPIdentifier_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELOCSPRESPONDERID
TElOCSPResponderID* TElCMSOCSPIdentifier::get_ResponderID()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSOCSPIdentifier_get_ResponderID(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ResponderID)
		this->_Inst_ResponderID = new TElOCSPResponderID(hOutResult, ohFalse);
	else
		this->_Inst_ResponderID->updateHandle(hOutResult);
	return this->_Inst_ResponderID;
}
#endif /* SB_USE_CLASS_TELOCSPRESPONDERID */

SB_INLINE int64_t TElCMSOCSPIdentifier::get_Time()
{
	int64_t OutResult;
	SBCheckError(TElCMSOCSPIdentifier_get_Time(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCMSOCSPIdentifier::set_Time(int64_t Value)
{
	SBCheckError(TElCMSOCSPIdentifier_set_Time(_Handle, Value));
}

void TElCMSOCSPIdentifier::initInstances()
{
#ifdef SB_USE_CLASS_TELOCSPRESPONDERID
	this->_Inst_ResponderID = NULL;
#endif /* SB_USE_CLASS_TELOCSPRESPONDERID */
}

TElCMSOCSPIdentifier::TElCMSOCSPIdentifier(TElCMSOCSPIdentifierHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCMSOCSPIdentifier::TElCMSOCSPIdentifier() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSOCSPIdentifier_Create(&_Handle));
}

TElCMSOCSPIdentifier::~TElCMSOCSPIdentifier()
{
#ifdef SB_USE_CLASS_TELOCSPRESPONDERID
	delete this->_Inst_ResponderID;
	this->_Inst_ResponderID = NULL;
#endif /* SB_USE_CLASS_TELOCSPRESPONDERID */
}
#endif /* SB_USE_CLASS_TELCMSOCSPIDENTIFIER */

#ifdef SB_USE_CLASS_TELCMSOCSPRESPONSESID

SB_INLINE void TElCMSOCSPResponsesID::Clear()
{
	SBCheckError(TElCMSOCSPResponsesID_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
SB_INLINE void TElCMSOCSPResponsesID::Import(TElOCSPResponse &Response, int32_t HashAlgorithm)
{
	SBCheckError(TElCMSOCSPResponsesID_Import(_Handle, Response.getHandle(), HashAlgorithm));
}

SB_INLINE void TElCMSOCSPResponsesID::Import(TElOCSPResponse *Response, int32_t HashAlgorithm)
{
	SBCheckError(TElCMSOCSPResponsesID_Import(_Handle, (Response != NULL) ? Response->getHandle() : SB_NULL_HANDLE, HashAlgorithm));
}
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
bool TElCMSOCSPResponsesID::OCSPResponseMatches(TElOCSPResponse &Response)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSOCSPResponsesID_OCSPResponseMatches(_Handle, Response.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCMSOCSPResponsesID::OCSPResponseMatches(TElOCSPResponse *Response)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSOCSPResponsesID_OCSPResponseMatches(_Handle, (Response != NULL) ? Response->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

#ifdef SB_USE_CLASS_TELCMSOCSPIDENTIFIER
TElCMSOCSPIdentifier* TElCMSOCSPResponsesID::get_OCSPIdentifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSOCSPResponsesID_get_OCSPIdentifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OCSPIdentifier)
		this->_Inst_OCSPIdentifier = new TElCMSOCSPIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_OCSPIdentifier->updateHandle(hOutResult);
	return this->_Inst_OCSPIdentifier;
}
#endif /* SB_USE_CLASS_TELCMSOCSPIDENTIFIER */

#ifdef SB_USE_CLASS_TELCMSHASH
TElCMSHash* TElCMSOCSPResponsesID::get_OCSPHash()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSOCSPResponsesID_get_OCSPHash(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OCSPHash)
		this->_Inst_OCSPHash = new TElCMSHash(hOutResult, ohFalse);
	else
		this->_Inst_OCSPHash->updateHandle(hOutResult);
	return this->_Inst_OCSPHash;
}
#endif /* SB_USE_CLASS_TELCMSHASH */

void TElCMSOCSPResponsesID::initInstances()
{
#ifdef SB_USE_CLASS_TELCMSOCSPIDENTIFIER
	this->_Inst_OCSPIdentifier = NULL;
#endif /* SB_USE_CLASS_TELCMSOCSPIDENTIFIER */
#ifdef SB_USE_CLASS_TELCMSHASH
	this->_Inst_OCSPHash = NULL;
#endif /* SB_USE_CLASS_TELCMSHASH */
}

TElCMSOCSPResponsesID::TElCMSOCSPResponsesID(TElCMSOCSPResponsesIDHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCMSOCSPResponsesID::TElCMSOCSPResponsesID() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSOCSPResponsesID_Create(&_Handle));
}

TElCMSOCSPResponsesID::~TElCMSOCSPResponsesID()
{
#ifdef SB_USE_CLASS_TELCMSOCSPIDENTIFIER
	delete this->_Inst_OCSPIdentifier;
	this->_Inst_OCSPIdentifier = NULL;
#endif /* SB_USE_CLASS_TELCMSOCSPIDENTIFIER */
#ifdef SB_USE_CLASS_TELCMSHASH
	delete this->_Inst_OCSPHash;
	this->_Inst_OCSPHash = NULL;
#endif /* SB_USE_CLASS_TELCMSHASH */
}
#endif /* SB_USE_CLASS_TELCMSOCSPRESPONSESID */

#ifdef SB_USE_CLASS_TELCMSREVOCATIONREF

SB_INLINE int32_t TElCMSRevocationRef::AddCRLID()
{
	int32_t OutResult;
	SBCheckError(TElCMSRevocationRef_AddCRLID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCMSRevocationRef::AddOCSPID()
{
	int32_t OutResult;
	SBCheckError(TElCMSRevocationRef_AddOCSPID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCMSRevocationRef::RemoveCRLID(int32_t Index)
{
	SBCheckError(TElCMSRevocationRef_RemoveCRLID(_Handle, Index));
}

SB_INLINE void TElCMSRevocationRef::RemoveOCSPID(int32_t Index)
{
	SBCheckError(TElCMSRevocationRef_RemoveOCSPID(_Handle, Index));
}

SB_INLINE void TElCMSRevocationRef::ClearCRLIDs()
{
	SBCheckError(TElCMSRevocationRef_ClearCRLIDs(_Handle));
}

SB_INLINE void TElCMSRevocationRef::ClearOCSPIDs()
{
	SBCheckError(TElCMSRevocationRef_ClearOCSPIDs(_Handle));
}

#ifdef SB_USE_CLASS_TLIST
SB_INLINE void TElCMSRevocationRef::Import(TList &CRLList, TList &OCSPList)
{
	SBCheckError(TElCMSRevocationRef_Import(_Handle, CRLList.getHandle(), OCSPList.getHandle()));
}

SB_INLINE void TElCMSRevocationRef::Import(TList *CRLList, TList *OCSPList)
{
	SBCheckError(TElCMSRevocationRef_Import(_Handle, (CRLList != NULL) ? CRLList->getHandle() : SB_NULL_HANDLE, (OCSPList != NULL) ? OCSPList->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASSES_TELMEMORYCRLSTORAGE_AND_TLIST
SB_INLINE void TElCMSRevocationRef::Import2(TElMemoryCRLStorage &CRLs, TList &OCSPList)
{
	SBCheckError(TElCMSRevocationRef_Import2(_Handle, CRLs.getHandle(), OCSPList.getHandle()));
}

SB_INLINE void TElCMSRevocationRef::Import2(TElMemoryCRLStorage *CRLs, TList *OCSPList)
{
	SBCheckError(TElCMSRevocationRef_Import2(_Handle, (CRLs != NULL) ? CRLs->getHandle() : SB_NULL_HANDLE, (OCSPList != NULL) ? OCSPList->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELMEMORYCRLSTORAGE_AND_TLIST */

#ifdef SB_USE_CLASS_TELCMSCRLVALIDATEDID
TElCMSCRLValidatedID* TElCMSRevocationRef::get_CRLIDs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSRevocationRef_get_CRLIDs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CRLIDs)
		this->_Inst_CRLIDs = new TElCMSCRLValidatedID(hOutResult, ohFalse);
	else
		this->_Inst_CRLIDs->updateHandle(hOutResult);
	return this->_Inst_CRLIDs;
}
#endif /* SB_USE_CLASS_TELCMSCRLVALIDATEDID */

#ifdef SB_USE_CLASS_TELCMSOCSPRESPONSESID
TElCMSOCSPResponsesID* TElCMSRevocationRef::get_OCSPIDs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSRevocationRef_get_OCSPIDs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OCSPIDs)
		this->_Inst_OCSPIDs = new TElCMSOCSPResponsesID(hOutResult, ohFalse);
	else
		this->_Inst_OCSPIDs->updateHandle(hOutResult);
	return this->_Inst_OCSPIDs;
}
#endif /* SB_USE_CLASS_TELCMSOCSPRESPONSESID */

SB_INLINE int32_t TElCMSRevocationRef::get_CRLIDCount()
{
	int32_t OutResult;
	SBCheckError(TElCMSRevocationRef_get_CRLIDCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCMSRevocationRef::get_OCSPIDCount()
{
	int32_t OutResult;
	SBCheckError(TElCMSRevocationRef_get_OCSPIDCount(_Handle, &OutResult));
	return OutResult;
}

void TElCMSRevocationRef::get_OtherRevType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSRevocationRef_get_OtherRevType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(841193973, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSRevocationRef::set_OtherRevType(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCMSRevocationRef_set_OtherRevType(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElCMSRevocationRef::get_OtherRevRefs(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSRevocationRef_get_OtherRevRefs(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-365388613, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSRevocationRef::set_OtherRevRefs(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCMSRevocationRef_set_OtherRevRefs(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElCMSRevocationRef::initInstances()
{
#ifdef SB_USE_CLASS_TELCMSCRLVALIDATEDID
	this->_Inst_CRLIDs = NULL;
#endif /* SB_USE_CLASS_TELCMSCRLVALIDATEDID */
#ifdef SB_USE_CLASS_TELCMSOCSPRESPONSESID
	this->_Inst_OCSPIDs = NULL;
#endif /* SB_USE_CLASS_TELCMSOCSPRESPONSESID */
}

TElCMSRevocationRef::TElCMSRevocationRef(TElCMSRevocationRefHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCMSRevocationRef::TElCMSRevocationRef() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSRevocationRef_Create(&_Handle));
}

TElCMSRevocationRef::~TElCMSRevocationRef()
{
#ifdef SB_USE_CLASS_TELCMSCRLVALIDATEDID
	delete this->_Inst_CRLIDs;
	this->_Inst_CRLIDs = NULL;
#endif /* SB_USE_CLASS_TELCMSCRLVALIDATEDID */
#ifdef SB_USE_CLASS_TELCMSOCSPRESPONSESID
	delete this->_Inst_OCSPIDs;
	this->_Inst_OCSPIDs = NULL;
#endif /* SB_USE_CLASS_TELCMSOCSPRESPONSESID */
}
#endif /* SB_USE_CLASS_TELCMSREVOCATIONREF */

#ifdef SB_USE_CLASS_TELCMSREVOCATIONREFS

SB_INLINE int32_t TElCMSRevocationRefs::Add()
{
	int32_t OutResult;
	SBCheckError(TElCMSRevocationRefs_Add(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCMSRevocationRefs::Remove(int32_t Index)
{
	SBCheckError(TElCMSRevocationRefs_Remove(_Handle, Index));
}

SB_INLINE void TElCMSRevocationRefs::Clear()
{
	SBCheckError(TElCMSRevocationRefs_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELCMSREVOCATIONREF
TElCMSRevocationRef* TElCMSRevocationRefs::get_Refs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSRevocationRefs_get_Refs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Refs)
		this->_Inst_Refs = new TElCMSRevocationRef(hOutResult, ohFalse);
	else
		this->_Inst_Refs->updateHandle(hOutResult);
	return this->_Inst_Refs;
}
#endif /* SB_USE_CLASS_TELCMSREVOCATIONREF */

SB_INLINE int32_t TElCMSRevocationRefs::get_RefCount()
{
	int32_t OutResult;
	SBCheckError(TElCMSRevocationRefs_get_RefCount(_Handle, &OutResult));
	return OutResult;
}

bool TElCMSRevocationRefs::get_AddASN1ExplicitTagsForEmptyRecords()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSRevocationRefs_get_AddASN1ExplicitTagsForEmptyRecords(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMSRevocationRefs::set_AddASN1ExplicitTagsForEmptyRecords(bool Value)
{
	SBCheckError(TElCMSRevocationRefs_set_AddASN1ExplicitTagsForEmptyRecords(_Handle, (int8_t)Value));
}

TSBCMSRevocationRefsWriteMode TElCMSRevocationRefs::get_WriteMode()
{
	TSBCMSRevocationRefsWriteModeRaw OutResultRaw = 0;
	SBCheckError(TElCMSRevocationRefs_get_WriteMode(_Handle, &OutResultRaw));
	return (TSBCMSRevocationRefsWriteMode)OutResultRaw;
}

SB_INLINE void TElCMSRevocationRefs::set_WriteMode(TSBCMSRevocationRefsWriteMode Value)
{
	SBCheckError(TElCMSRevocationRefs_set_WriteMode(_Handle, (TSBCMSRevocationRefsWriteModeRaw)Value));
}

void TElCMSRevocationRefs::initInstances()
{
#ifdef SB_USE_CLASS_TELCMSREVOCATIONREF
	this->_Inst_Refs = NULL;
#endif /* SB_USE_CLASS_TELCMSREVOCATIONREF */
}

TElCMSRevocationRefs::TElCMSRevocationRefs(TElCMSRevocationRefsHandle handle, TElOwnHandle ownHandle) : TElCMSProperty(handle, ownHandle)
{
	initInstances();
}

TElCMSRevocationRefs::TElCMSRevocationRefs() : TElCMSProperty(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSRevocationRefs_Create(&_Handle));
}

TElCMSRevocationRefs::~TElCMSRevocationRefs()
{
#ifdef SB_USE_CLASS_TELCMSREVOCATIONREF
	delete this->_Inst_Refs;
	this->_Inst_Refs = NULL;
#endif /* SB_USE_CLASS_TELCMSREVOCATIONREF */
}
#endif /* SB_USE_CLASS_TELCMSREVOCATIONREFS */

#ifdef SB_USE_CLASS_TELCMSREVOCATIONVALUES

SB_INLINE int32_t TElCMSRevocationValues::AddCRL()
{
	int32_t OutResult;
	SBCheckError(TElCMSRevocationValues_AddCRL(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCMSRevocationValues::AddOCSPResponse()
{
	int32_t OutResult;
	SBCheckError(TElCMSRevocationValues_AddOCSPResponse(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCMSRevocationValues::RemoveCRL(int32_t Index)
{
	SBCheckError(TElCMSRevocationValues_RemoveCRL(_Handle, Index));
}

SB_INLINE void TElCMSRevocationValues::RemoveOCSPResponse(int32_t Index)
{
	SBCheckError(TElCMSRevocationValues_RemoveOCSPResponse(_Handle, Index));
}

SB_INLINE void TElCMSRevocationValues::ClearCRLs()
{
	SBCheckError(TElCMSRevocationValues_ClearCRLs(_Handle));
}

SB_INLINE void TElCMSRevocationValues::ClearOCSPResponses()
{
	SBCheckError(TElCMSRevocationValues_ClearOCSPResponses(_Handle));
}

SB_INLINE void TElCMSRevocationValues::Clear()
{
	SBCheckError(TElCMSRevocationValues_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
TElCertificateRevocationList* TElCMSRevocationValues::get_CRLs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSRevocationValues_get_CRLs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CRLs)
		this->_Inst_CRLs = new TElCertificateRevocationList(hOutResult, ohFalse);
	else
		this->_Inst_CRLs->updateHandle(hOutResult);
	return this->_Inst_CRLs;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
TElOCSPResponse* TElCMSRevocationValues::get_OCSPResponses(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSRevocationValues_get_OCSPResponses(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OCSPResponses)
		this->_Inst_OCSPResponses = new TElOCSPResponse(hOutResult, ohFalse);
	else
		this->_Inst_OCSPResponses->updateHandle(hOutResult);
	return this->_Inst_OCSPResponses;
}
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

SB_INLINE int32_t TElCMSRevocationValues::get_CRLCount()
{
	int32_t OutResult;
	SBCheckError(TElCMSRevocationValues_get_CRLCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCMSRevocationValues::get_OCSPResponseCount()
{
	int32_t OutResult;
	SBCheckError(TElCMSRevocationValues_get_OCSPResponseCount(_Handle, &OutResult));
	return OutResult;
}

void TElCMSRevocationValues::get_OtherRevType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSRevocationValues_get_OtherRevType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2012533883, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSRevocationValues::set_OtherRevType(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCMSRevocationValues_set_OtherRevType(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElCMSRevocationValues::get_OtherRevValues(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSRevocationValues_get_OtherRevValues(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(545231934, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSRevocationValues::set_OtherRevValues(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCMSRevocationValues_set_OtherRevValues(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElCMSRevocationValues::initInstances()
{
#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
	this->_Inst_CRLs = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */
#ifdef SB_USE_CLASS_TELOCSPRESPONSE
	this->_Inst_OCSPResponses = NULL;
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */
}

TElCMSRevocationValues::TElCMSRevocationValues(TElCMSRevocationValuesHandle handle, TElOwnHandle ownHandle) : TElCMSProperty(handle, ownHandle)
{
	initInstances();
}

TElCMSRevocationValues::TElCMSRevocationValues() : TElCMSProperty(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSRevocationValues_Create(&_Handle));
}

TElCMSRevocationValues::~TElCMSRevocationValues()
{
#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
	delete this->_Inst_CRLs;
	this->_Inst_CRLs = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */
#ifdef SB_USE_CLASS_TELOCSPRESPONSE
	delete this->_Inst_OCSPResponses;
	this->_Inst_OCSPResponses = NULL;
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */
}
#endif /* SB_USE_CLASS_TELCMSREVOCATIONVALUES */

#ifdef SB_USE_CLASS_TELCMSCONTENT

SB_INLINE void TElCMSContent::Clear()
{
	SBCheckError(TElCMSContent_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElCMSContent::Init(TStream &Stream, int64_t Offset, int64_t Size)
{
	SBCheckError(TElCMSContent_Init(_Handle, Stream.getHandle(), Offset, Size));
}

SB_INLINE void TElCMSContent::Init(TStream *Stream, int64_t Offset, int64_t Size)
{
	SBCheckError(TElCMSContent_Init(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Offset, Size));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElCMSContent::Init(void * Buffer, int32_t Size)
{
	SBCheckError(TElCMSContent_Init_1(_Handle, Buffer, Size));
}

SB_INLINE int32_t TElCMSContent::Read(void * Buffer, int32_t Size, int64_t Offset)
{
	int32_t OutResult;
	SBCheckError(TElCMSContent_Read(_Handle, Buffer, Size, Offset, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCMSContent::AddKnownHash()
{
	int32_t OutResult;
	SBCheckError(TElCMSContent_AddKnownHash(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCMSContent::AddKnownHash(int32_t AlgID, const std::vector<uint8_t> &HashAlgParams, const std::vector<uint8_t> &Hash)
{
	int32_t OutResult;
	SBCheckError(TElCMSContent_AddKnownHash_1(_Handle, AlgID, SB_STD_VECTOR_FRONT_ADR(HashAlgParams), (int32_t)HashAlgParams.size(), SB_STD_VECTOR_FRONT_ADR(Hash), (int32_t)Hash.size(), &OutResult));
	return OutResult;
}

SB_INLINE void TElCMSContent::RemoveKnownHash(int32_t Index)
{
	SBCheckError(TElCMSContent_RemoveKnownHash(_Handle, Index));
}

SB_INLINE void TElCMSContent::ClearKnownHashes()
{
	SBCheckError(TElCMSContent_ClearKnownHashes(_Handle));
}

SB_INLINE int64_t TElCMSContent::get_Size()
{
	int64_t OutResult;
	SBCheckError(TElCMSContent_get_Size(_Handle, &OutResult));
	return OutResult;
}

bool TElCMSContent::get_ContentIsHash()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSContent_get_ContentIsHash(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMSContent::set_ContentIsHash(bool Value)
{
	SBCheckError(TElCMSContent_set_ContentIsHash(_Handle, (int8_t)Value));
}

void TElCMSContent::get_RawContent(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSContent_get_RawContent(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1316200630, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELCMSHASH
TElCMSHash* TElCMSContent::get_KnownHashes(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSContent_get_KnownHashes(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KnownHashes)
		this->_Inst_KnownHashes = new TElCMSHash(hOutResult, ohFalse);
	else
		this->_Inst_KnownHashes->updateHandle(hOutResult);
	return this->_Inst_KnownHashes;
}
#endif /* SB_USE_CLASS_TELCMSHASH */

SB_INLINE int32_t TElCMSContent::get_KnownHashCount()
{
	int32_t OutResult;
	SBCheckError(TElCMSContent_get_KnownHashCount(_Handle, &OutResult));
	return OutResult;
}

void TElCMSContent::initInstances()
{
#ifdef SB_USE_CLASS_TELCMSHASH
	this->_Inst_KnownHashes = NULL;
#endif /* SB_USE_CLASS_TELCMSHASH */
}

TElCMSContent::TElCMSContent(TElCMSContentHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCMSContent::TElCMSContent() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSContent_Create(&_Handle));
}

#ifdef SB_USE_CLASS_TELPKCS7SIGNEDDATA
TElCMSContent::TElCMSContent(TElPKCS7SignedData &Data) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSContent_Create_1(Data.getHandle(), &_Handle));
}

TElCMSContent::TElCMSContent(TElPKCS7SignedData *Data) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSContent_Create_1((Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPKCS7SIGNEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7SIGNEDANDENVELOPEDDATA
TElCMSContent::TElCMSContent(TElPKCS7SignedAndEnvelopedData &Data) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSContent_Create_2(Data.getHandle(), &_Handle));
}

TElCMSContent::TElCMSContent(TElPKCS7SignedAndEnvelopedData *Data) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSContent_Create_2((Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPKCS7SIGNEDANDENVELOPEDDATA */

TElCMSContent::~TElCMSContent()
{
#ifdef SB_USE_CLASS_TELCMSHASH
	delete this->_Inst_KnownHashes;
	this->_Inst_KnownHashes = NULL;
#endif /* SB_USE_CLASS_TELCMSHASH */
}
#endif /* SB_USE_CLASS_TELCMSCONTENT */

#ifdef SB_USE_CLASS_TELCMSSIGPOLICYQUALIFIER

SB_INLINE void TElCMSSigPolicyQualifier::Clear()
{
	SBCheckError(TElCMSSigPolicyQualifier_Clear(_Handle));
}

SB_INLINE int32_t TElCMSSigPolicyQualifier::AddNoticeNumber()
{
	int32_t OutResult;
	SBCheckError(TElCMSSigPolicyQualifier_AddNoticeNumber(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCMSSigPolicyQualifier::RemoveNoticeNumber(int32_t Index)
{
	SBCheckError(TElCMSSigPolicyQualifier_RemoveNoticeNumber(_Handle, Index));
}

SB_INLINE void TElCMSSigPolicyQualifier::ClearNoticeNumbers()
{
	SBCheckError(TElCMSSigPolicyQualifier_ClearNoticeNumbers(_Handle));
}

void TElCMSSigPolicyQualifier::get_ID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSSigPolicyQualifier_get_ID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(928652400, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSSigPolicyQualifier::set_ID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCMSSigPolicyQualifier_set_ID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TSBSigPolicyQualifierType TElCMSSigPolicyQualifier::get_QualifierType()
{
	TSBSigPolicyQualifierTypeRaw OutResultRaw = 0;
	SBCheckError(TElCMSSigPolicyQualifier_get_QualifierType(_Handle, &OutResultRaw));
	return (TSBSigPolicyQualifierType)OutResultRaw;
}

SB_INLINE void TElCMSSigPolicyQualifier::set_QualifierType(TSBSigPolicyQualifierType Value)
{
	SBCheckError(TElCMSSigPolicyQualifier_set_QualifierType(_Handle, (TSBSigPolicyQualifierTypeRaw)Value));
}

void TElCMSSigPolicyQualifier::get_URI(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCMSSigPolicyQualifier_get_URI(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1452686807, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSSigPolicyQualifier::set_URI(const std::string &Value)
{
	SBCheckError(TElCMSSigPolicyQualifier_set_URI(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElCMSSigPolicyQualifier::get_ExplicitText(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCMSSigPolicyQualifier_get_ExplicitText(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1839922739, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSSigPolicyQualifier::set_ExplicitText(const std::string &Value)
{
	SBCheckError(TElCMSSigPolicyQualifier_set_ExplicitText(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElCMSSigPolicyQualifier::get_Organization(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCMSSigPolicyQualifier_get_Organization(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2093930952, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSSigPolicyQualifier::set_Organization(const std::string &Value)
{
	SBCheckError(TElCMSSigPolicyQualifier_set_Organization(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElCMSSigPolicyQualifier::get_CustomData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSSigPolicyQualifier_get_CustomData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(305103628, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSSigPolicyQualifier::set_CustomData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCMSSigPolicyQualifier_set_CustomData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElCMSSigPolicyQualifier::get_NoticeNumbers(int32_t Index)
{
	int32_t OutResult;
	SBCheckError(TElCMSSigPolicyQualifier_get_NoticeNumbers(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElCMSSigPolicyQualifier::set_NoticeNumbers(int32_t Index, int32_t Value)
{
	SBCheckError(TElCMSSigPolicyQualifier_set_NoticeNumbers(_Handle, Index, Value));
}

SB_INLINE int32_t TElCMSSigPolicyQualifier::get_NoticeNumberCount()
{
	int32_t OutResult;
	SBCheckError(TElCMSSigPolicyQualifier_get_NoticeNumberCount(_Handle, &OutResult));
	return OutResult;
}

bool TElCMSSigPolicyQualifier::get_UseUTF8()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSSigPolicyQualifier_get_UseUTF8(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMSSigPolicyQualifier::set_UseUTF8(bool Value)
{
	SBCheckError(TElCMSSigPolicyQualifier_set_UseUTF8(_Handle, (int8_t)Value));
}

TElCMSSigPolicyQualifier::TElCMSSigPolicyQualifier(TElCMSSigPolicyQualifierHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElCMSSigPolicyQualifier::TElCMSSigPolicyQualifier() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCMSSigPolicyQualifier_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCMSSIGPOLICYQUALIFIER */

#ifdef SB_USE_CLASS_TELCMSSIGNATUREPOLICY

SB_INLINE int32_t TElCMSSignaturePolicy::AddQualifier()
{
	int32_t OutResult;
	SBCheckError(TElCMSSignaturePolicy_AddQualifier(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCMSSignaturePolicy::RemoveQualifier(int32_t Index)
{
	SBCheckError(TElCMSSignaturePolicy_RemoveQualifier(_Handle, Index));
}

SB_INLINE void TElCMSSignaturePolicy::ClearQualifiers()
{
	SBCheckError(TElCMSSignaturePolicy_ClearQualifiers(_Handle));
}

SB_INLINE void TElCMSSignaturePolicy::Clear()
{
	SBCheckError(TElCMSSignaturePolicy_Clear(_Handle));
}

void TElCMSSignaturePolicy::get_PolicyIdentifier(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSSignaturePolicy_get_PolicyIdentifier(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(703919943, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSSignaturePolicy::set_PolicyIdentifier(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCMSSignaturePolicy_set_PolicyIdentifier(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELCMSHASH
TElCMSHash* TElCMSSignaturePolicy::get_PolicyHash()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignaturePolicy_get_PolicyHash(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PolicyHash)
		this->_Inst_PolicyHash = new TElCMSHash(hOutResult, ohFalse);
	else
		this->_Inst_PolicyHash->updateHandle(hOutResult);
	return this->_Inst_PolicyHash;
}
#endif /* SB_USE_CLASS_TELCMSHASH */

#ifdef SB_USE_CLASS_TELCMSSIGPOLICYQUALIFIER
TElCMSSigPolicyQualifier* TElCMSSignaturePolicy::get_Qualifiers(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignaturePolicy_get_Qualifiers(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Qualifiers)
		this->_Inst_Qualifiers = new TElCMSSigPolicyQualifier(hOutResult, ohFalse);
	else
		this->_Inst_Qualifiers->updateHandle(hOutResult);
	return this->_Inst_Qualifiers;
}
#endif /* SB_USE_CLASS_TELCMSSIGPOLICYQUALIFIER */

SB_INLINE int32_t TElCMSSignaturePolicy::get_QualifierCount()
{
	int32_t OutResult;
	SBCheckError(TElCMSSignaturePolicy_get_QualifierCount(_Handle, &OutResult));
	return OutResult;
}

bool TElCMSSignaturePolicy::get_Implied()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSSignaturePolicy_get_Implied(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMSSignaturePolicy::set_Implied(bool Value)
{
	SBCheckError(TElCMSSignaturePolicy_set_Implied(_Handle, (int8_t)Value));
}

void TElCMSSignaturePolicy::initInstances()
{
#ifdef SB_USE_CLASS_TELCMSHASH
	this->_Inst_PolicyHash = NULL;
#endif /* SB_USE_CLASS_TELCMSHASH */
#ifdef SB_USE_CLASS_TELCMSSIGPOLICYQUALIFIER
	this->_Inst_Qualifiers = NULL;
#endif /* SB_USE_CLASS_TELCMSSIGPOLICYQUALIFIER */
}

TElCMSSignaturePolicy::TElCMSSignaturePolicy(TElCMSSignaturePolicyHandle handle, TElOwnHandle ownHandle) : TElCMSProperty(handle, ownHandle)
{
	initInstances();
}

TElCMSSignaturePolicy::TElCMSSignaturePolicy() : TElCMSProperty(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSSignaturePolicy_Create(&_Handle));
}

TElCMSSignaturePolicy::~TElCMSSignaturePolicy()
{
#ifdef SB_USE_CLASS_TELCMSHASH
	delete this->_Inst_PolicyHash;
	this->_Inst_PolicyHash = NULL;
#endif /* SB_USE_CLASS_TELCMSHASH */
#ifdef SB_USE_CLASS_TELCMSSIGPOLICYQUALIFIER
	delete this->_Inst_Qualifiers;
	this->_Inst_Qualifiers = NULL;
#endif /* SB_USE_CLASS_TELCMSSIGPOLICYQUALIFIER */
}
#endif /* SB_USE_CLASS_TELCMSSIGNATUREPOLICY */

#ifdef SB_USE_CLASS_TELCMSCONTENTHINTS

void TElCMSContentHints::get_ContentDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCMSContentHints_get_ContentDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1069309002, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSContentHints::set_ContentDescription(const std::string &Value)
{
	SBCheckError(TElCMSContentHints_set_ContentDescription(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElCMSContentHints::get_ContentType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSContentHints_get_ContentType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1454836111, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSContentHints::set_ContentType(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCMSContentHints_set_ContentType(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElCMSContentHints::TElCMSContentHints(TElCMSContentHintsHandle handle, TElOwnHandle ownHandle) : TElCMSProperty(handle, ownHandle)
{
}

TElCMSContentHints::TElCMSContentHints() : TElCMSProperty(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCMSContentHints_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCMSCONTENTHINTS */

#ifdef SB_USE_CLASS_TELCMSCONTENTREFERENCE

void TElCMSContentReference::get_ContentType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSContentReference_get_ContentType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1684689815, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSContentReference::set_ContentType(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCMSContentReference_set_ContentType(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElCMSContentReference::get_ContentIdentifier(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSContentReference_get_ContentIdentifier(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(642625241, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSContentReference::set_ContentIdentifier(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCMSContentReference_set_ContentIdentifier(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElCMSContentReference::get_OriginatorSignatureValue(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSContentReference_get_OriginatorSignatureValue(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-601461775, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSContentReference::set_OriginatorSignatureValue(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCMSContentReference_set_OriginatorSignatureValue(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElCMSContentReference::TElCMSContentReference(TElCMSContentReferenceHandle handle, TElOwnHandle ownHandle) : TElCMSProperty(handle, ownHandle)
{
}

TElCMSContentReference::TElCMSContentReference() : TElCMSProperty(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCMSContentReference_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCMSCONTENTREFERENCE */

#ifdef SB_USE_CLASS_TELCMSCOMMITMENTTYPEINDICATION

SB_INLINE void TElCMSCommitmentTypeIndication::Clear()
{
	SBCheckError(TElCMSCommitmentTypeIndication_Clear(_Handle));
}

bool TElCMSCommitmentTypeIndication::get_ProofOfOrigin()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSCommitmentTypeIndication_get_ProofOfOrigin(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMSCommitmentTypeIndication::set_ProofOfOrigin(bool Value)
{
	SBCheckError(TElCMSCommitmentTypeIndication_set_ProofOfOrigin(_Handle, (int8_t)Value));
}

bool TElCMSCommitmentTypeIndication::get_ProofOfReceipt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSCommitmentTypeIndication_get_ProofOfReceipt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMSCommitmentTypeIndication::set_ProofOfReceipt(bool Value)
{
	SBCheckError(TElCMSCommitmentTypeIndication_set_ProofOfReceipt(_Handle, (int8_t)Value));
}

bool TElCMSCommitmentTypeIndication::get_ProofOfDelivery()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSCommitmentTypeIndication_get_ProofOfDelivery(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMSCommitmentTypeIndication::set_ProofOfDelivery(bool Value)
{
	SBCheckError(TElCMSCommitmentTypeIndication_set_ProofOfDelivery(_Handle, (int8_t)Value));
}

bool TElCMSCommitmentTypeIndication::get_ProofOfSender()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSCommitmentTypeIndication_get_ProofOfSender(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMSCommitmentTypeIndication::set_ProofOfSender(bool Value)
{
	SBCheckError(TElCMSCommitmentTypeIndication_set_ProofOfSender(_Handle, (int8_t)Value));
}

bool TElCMSCommitmentTypeIndication::get_ProofOfApproval()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSCommitmentTypeIndication_get_ProofOfApproval(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMSCommitmentTypeIndication::set_ProofOfApproval(bool Value)
{
	SBCheckError(TElCMSCommitmentTypeIndication_set_ProofOfApproval(_Handle, (int8_t)Value));
}

bool TElCMSCommitmentTypeIndication::get_ProofOfCreation()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSCommitmentTypeIndication_get_ProofOfCreation(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMSCommitmentTypeIndication::set_ProofOfCreation(bool Value)
{
	SBCheckError(TElCMSCommitmentTypeIndication_set_ProofOfCreation(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
TElByteArrayList* TElCMSCommitmentTypeIndication::get_CustomIdentifiers()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSCommitmentTypeIndication_get_CustomIdentifiers(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CustomIdentifiers)
		this->_Inst_CustomIdentifiers = new TElByteArrayList(hOutResult, ohFalse);
	else
		this->_Inst_CustomIdentifiers->updateHandle(hOutResult);
	return this->_Inst_CustomIdentifiers;
}
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

void TElCMSCommitmentTypeIndication::initInstances()
{
#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
	this->_Inst_CustomIdentifiers = NULL;
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */
}

TElCMSCommitmentTypeIndication::TElCMSCommitmentTypeIndication(TElCMSCommitmentTypeIndicationHandle handle, TElOwnHandle ownHandle) : TElCMSProperty(handle, ownHandle)
{
	initInstances();
}

TElCMSCommitmentTypeIndication::TElCMSCommitmentTypeIndication() : TElCMSProperty(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSCommitmentTypeIndication_Create(&_Handle));
}

TElCMSCommitmentTypeIndication::~TElCMSCommitmentTypeIndication()
{
#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
	delete this->_Inst_CustomIdentifiers;
	this->_Inst_CustomIdentifiers = NULL;
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */
}
#endif /* SB_USE_CLASS_TELCMSCOMMITMENTTYPEINDICATION */

#ifdef SB_USE_CLASS_TELCMSSIGNERLOCATION

SB_INLINE void TElCMSSignerLocation::Clear()
{
	SBCheckError(TElCMSSignerLocation_Clear(_Handle));
}

SB_INLINE int32_t TElCMSSignerLocation::AddPostalAddressLine()
{
	int32_t OutResult;
	SBCheckError(TElCMSSignerLocation_AddPostalAddressLine(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCMSSignerLocation::RemovePostalAddressLine(int32_t Index)
{
	SBCheckError(TElCMSSignerLocation_RemovePostalAddressLine(_Handle, Index));
}

SB_INLINE void TElCMSSignerLocation::ClearPostalAddressLines()
{
	SBCheckError(TElCMSSignerLocation_ClearPostalAddressLines(_Handle));
}

#ifdef SB_USE_CLASS_TELASN1DIRECTORYSTRING
TElASN1DirectoryString* TElCMSSignerLocation::get_CountryName()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignerLocation_get_CountryName(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CountryName)
		this->_Inst_CountryName = new TElASN1DirectoryString(hOutResult, ohFalse);
	else
		this->_Inst_CountryName->updateHandle(hOutResult);
	return this->_Inst_CountryName;
}
#endif /* SB_USE_CLASS_TELASN1DIRECTORYSTRING */

#ifdef SB_USE_CLASS_TELASN1DIRECTORYSTRING
TElASN1DirectoryString* TElCMSSignerLocation::get_LocalityName()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignerLocation_get_LocalityName(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_LocalityName)
		this->_Inst_LocalityName = new TElASN1DirectoryString(hOutResult, ohFalse);
	else
		this->_Inst_LocalityName->updateHandle(hOutResult);
	return this->_Inst_LocalityName;
}
#endif /* SB_USE_CLASS_TELASN1DIRECTORYSTRING */

#ifdef SB_USE_CLASS_TELASN1DIRECTORYSTRING
TElASN1DirectoryString* TElCMSSignerLocation::get_PostalAddressLines(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignerLocation_get_PostalAddressLines(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PostalAddressLines)
		this->_Inst_PostalAddressLines = new TElASN1DirectoryString(hOutResult, ohFalse);
	else
		this->_Inst_PostalAddressLines->updateHandle(hOutResult);
	return this->_Inst_PostalAddressLines;
}
#endif /* SB_USE_CLASS_TELASN1DIRECTORYSTRING */

SB_INLINE int32_t TElCMSSignerLocation::get_PostalAddressLineCount()
{
	int32_t OutResult;
	SBCheckError(TElCMSSignerLocation_get_PostalAddressLineCount(_Handle, &OutResult));
	return OutResult;
}

void TElCMSSignerLocation::initInstances()
{
#ifdef SB_USE_CLASS_TELASN1DIRECTORYSTRING
	this->_Inst_CountryName = NULL;
#endif /* SB_USE_CLASS_TELASN1DIRECTORYSTRING */
#ifdef SB_USE_CLASS_TELASN1DIRECTORYSTRING
	this->_Inst_LocalityName = NULL;
#endif /* SB_USE_CLASS_TELASN1DIRECTORYSTRING */
#ifdef SB_USE_CLASS_TELASN1DIRECTORYSTRING
	this->_Inst_PostalAddressLines = NULL;
#endif /* SB_USE_CLASS_TELASN1DIRECTORYSTRING */
}

TElCMSSignerLocation::TElCMSSignerLocation(TElCMSSignerLocationHandle handle, TElOwnHandle ownHandle) : TElCMSProperty(handle, ownHandle)
{
	initInstances();
}

TElCMSSignerLocation::TElCMSSignerLocation() : TElCMSProperty(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSSignerLocation_Create(&_Handle));
}

TElCMSSignerLocation::~TElCMSSignerLocation()
{
#ifdef SB_USE_CLASS_TELASN1DIRECTORYSTRING
	delete this->_Inst_CountryName;
	this->_Inst_CountryName = NULL;
#endif /* SB_USE_CLASS_TELASN1DIRECTORYSTRING */
#ifdef SB_USE_CLASS_TELASN1DIRECTORYSTRING
	delete this->_Inst_LocalityName;
	this->_Inst_LocalityName = NULL;
#endif /* SB_USE_CLASS_TELASN1DIRECTORYSTRING */
#ifdef SB_USE_CLASS_TELASN1DIRECTORYSTRING
	delete this->_Inst_PostalAddressLines;
	this->_Inst_PostalAddressLines = NULL;
#endif /* SB_USE_CLASS_TELASN1DIRECTORYSTRING */
}
#endif /* SB_USE_CLASS_TELCMSSIGNERLOCATION */

#ifdef SB_USE_CLASS_TELCMSSIGNINGCERTIFICATE

SB_INLINE void TElCMSSigningCertificate::Clear()
{
	SBCheckError(TElCMSSigningCertificate_Clear(_Handle));
}

SB_INLINE int32_t TElCMSSigningCertificate::AddCertID()
{
	int32_t OutResult;
	SBCheckError(TElCMSSigningCertificate_AddCertID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCMSSigningCertificate::RemoveCertID(int32_t Index)
{
	SBCheckError(TElCMSSigningCertificate_RemoveCertID(_Handle, Index));
}

SB_INLINE void TElCMSSigningCertificate::ClearCertIDs()
{
	SBCheckError(TElCMSSigningCertificate_ClearCertIDs(_Handle));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
bool TElCMSSigningCertificate::Corresponds(TElX509Certificate &Cert)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSSigningCertificate_Corresponds(_Handle, Cert.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCMSSigningCertificate::Corresponds(TElX509Certificate *Cert)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSSigningCertificate_Corresponds(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELCMSSIGNERIDENTIFIER
TElCMSSignerIdentifier* TElCMSSigningCertificate::get_CertIDs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSigningCertificate_get_CertIDs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertIDs)
		this->_Inst_CertIDs = new TElCMSSignerIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_CertIDs->updateHandle(hOutResult);
	return this->_Inst_CertIDs;
}
#endif /* SB_USE_CLASS_TELCMSSIGNERIDENTIFIER */

SB_INLINE int32_t TElCMSSigningCertificate::get_CertIDCount()
{
	int32_t OutResult;
	SBCheckError(TElCMSSigningCertificate_get_CertIDCount(_Handle, &OutResult));
	return OutResult;
}

TSBCMSSigningCertificateType TElCMSSigningCertificate::get_SigningCertificateType()
{
	TSBCMSSigningCertificateTypeRaw OutResultRaw = 0;
	SBCheckError(TElCMSSigningCertificate_get_SigningCertificateType(_Handle, &OutResultRaw));
	return (TSBCMSSigningCertificateType)OutResultRaw;
}

SB_INLINE void TElCMSSigningCertificate::set_SigningCertificateType(TSBCMSSigningCertificateType Value)
{
	SBCheckError(TElCMSSigningCertificate_set_SigningCertificateType(_Handle, (TSBCMSSigningCertificateTypeRaw)Value));
}

void TElCMSSigningCertificate::initInstances()
{
#ifdef SB_USE_CLASS_TELCMSSIGNERIDENTIFIER
	this->_Inst_CertIDs = NULL;
#endif /* SB_USE_CLASS_TELCMSSIGNERIDENTIFIER */
}

TElCMSSigningCertificate::TElCMSSigningCertificate(TElCMSSigningCertificateHandle handle, TElOwnHandle ownHandle) : TElCMSProperty(handle, ownHandle)
{
	initInstances();
}

TElCMSSigningCertificate::TElCMSSigningCertificate() : TElCMSProperty(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSSigningCertificate_Create(&_Handle));
}

TElCMSSigningCertificate::~TElCMSSigningCertificate()
{
#ifdef SB_USE_CLASS_TELCMSSIGNERIDENTIFIER
	delete this->_Inst_CertIDs;
	this->_Inst_CertIDs = NULL;
#endif /* SB_USE_CLASS_TELCMSSIGNERIDENTIFIER */
}
#endif /* SB_USE_CLASS_TELCMSSIGNINGCERTIFICATE */

#ifdef SB_USE_CLASS_TELCMSSIGNERATTRIBUTES

SB_INLINE void TElCMSSignerAttributes::Clear()
{
	SBCheckError(TElCMSSignerAttributes_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
TElPKCS7Attributes* TElCMSSignerAttributes::get_ClaimedAttributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignerAttributes_get_ClaimedAttributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ClaimedAttributes)
		this->_Inst_ClaimedAttributes = new TElPKCS7Attributes(hOutResult, ohFalse);
	else
		this->_Inst_ClaimedAttributes->updateHandle(hOutResult);
	return this->_Inst_ClaimedAttributes;
}
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

void TElCMSSignerAttributes::get_CertifiedAttributesBinary(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSSignerAttributes_get_CertifiedAttributesBinary(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(112136034, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSSignerAttributes::set_CertifiedAttributesBinary(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCMSSignerAttributes_set_CertifiedAttributesBinary(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
TElPKCS7Attributes* TElCMSSignerAttributes::get_SignedAssertions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignerAttributes_get_SignedAssertions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignedAssertions)
		this->_Inst_SignedAssertions = new TElPKCS7Attributes(hOutResult, ohFalse);
	else
		this->_Inst_SignedAssertions->updateHandle(hOutResult);
	return this->_Inst_SignedAssertions;
}
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

TSBCMSSignerAttributesVersion TElCMSSignerAttributes::get_Version()
{
	TSBCMSSignerAttributesVersionRaw OutResultRaw = 0;
	SBCheckError(TElCMSSignerAttributes_get_Version(_Handle, &OutResultRaw));
	return (TSBCMSSignerAttributesVersion)OutResultRaw;
}

SB_INLINE void TElCMSSignerAttributes::set_Version(TSBCMSSignerAttributesVersion Value)
{
	SBCheckError(TElCMSSignerAttributes_set_Version(_Handle, (TSBCMSSignerAttributesVersionRaw)Value));
}

void TElCMSSignerAttributes::get_AttributeCertificateType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSSignerAttributes_get_AttributeCertificateType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1139442376, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSSignerAttributes::set_AttributeCertificateType(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCMSSignerAttributes_set_AttributeCertificateType(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElCMSSignerAttributes::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	this->_Inst_ClaimedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	this->_Inst_SignedAssertions = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
}

TElCMSSignerAttributes::TElCMSSignerAttributes(TElCMSSignerAttributesHandle handle, TElOwnHandle ownHandle) : TElCMSProperty(handle, ownHandle)
{
	initInstances();
}

TElCMSSignerAttributes::TElCMSSignerAttributes() : TElCMSProperty(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSSignerAttributes_Create(&_Handle));
}

TElCMSSignerAttributes::~TElCMSSignerAttributes()
{
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	delete this->_Inst_ClaimedAttributes;
	this->_Inst_ClaimedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	delete this->_Inst_SignedAssertions;
	this->_Inst_SignedAssertions = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
}
#endif /* SB_USE_CLASS_TELCMSSIGNERATTRIBUTES */

#ifdef SB_USE_CLASS_TELCMSSIGNATUREPOLICYSTORE

SB_INLINE void TElCMSSignaturePolicyStore::Clear()
{
	SBCheckError(TElCMSSignaturePolicyStore_Clear(_Handle));
}

void TElCMSSignaturePolicyStore::get_DocSpecOID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSSignaturePolicyStore_get_DocSpecOID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-209236411, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSSignaturePolicyStore::set_DocSpecOID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCMSSignaturePolicyStore_set_DocSpecOID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElCMSSignaturePolicyStore::get_DocSpecURI(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCMSSignaturePolicyStore_get_DocSpecURI(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(900849604, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSSignaturePolicyStore::set_DocSpecURI(const std::string &Value)
{
	SBCheckError(TElCMSSignaturePolicyStore_set_DocSpecURI(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElCMSSignaturePolicyStore::get_EncodedPolicyDocument(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSSignaturePolicyStore_get_EncodedPolicyDocument(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(179407998, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSSignaturePolicyStore::set_EncodedPolicyDocument(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCMSSignaturePolicyStore_set_EncodedPolicyDocument(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElCMSSignaturePolicyStore::get_PolicyLocalURI(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCMSSignaturePolicyStore_get_PolicyLocalURI(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(460176575, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSSignaturePolicyStore::set_PolicyLocalURI(const std::string &Value)
{
	SBCheckError(TElCMSSignaturePolicyStore_set_PolicyLocalURI(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBCMSSignaturePolicyStoreType TElCMSSignaturePolicyStore::get_PolicyStoreType()
{
	TSBCMSSignaturePolicyStoreTypeRaw OutResultRaw = 0;
	SBCheckError(TElCMSSignaturePolicyStore_get_PolicyStoreType(_Handle, &OutResultRaw));
	return (TSBCMSSignaturePolicyStoreType)OutResultRaw;
}

SB_INLINE void TElCMSSignaturePolicyStore::set_PolicyStoreType(TSBCMSSignaturePolicyStoreType Value)
{
	SBCheckError(TElCMSSignaturePolicyStore_set_PolicyStoreType(_Handle, (TSBCMSSignaturePolicyStoreTypeRaw)Value));
}

TElCMSSignaturePolicyStore::TElCMSSignaturePolicyStore(TElCMSSignaturePolicyStoreHandle handle, TElOwnHandle ownHandle) : TElCMSProperty(handle, ownHandle)
{
}

TElCMSSignaturePolicyStore::TElCMSSignaturePolicyStore() : TElCMSProperty(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCMSSignaturePolicyStore_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCMSSIGNATUREPOLICYSTORE */

#ifdef SB_USE_CLASS_TELCMSSIGNATURE

SB_INLINE void TElCMSSignature::Assign(TElCMSSignature &Source)
{
	SBCheckError(TElCMSSignature_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElCMSSignature::Assign(TElCMSSignature *Source)
{
	SBCheckError(TElCMSSignature_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElCMSSignature::AddCountersignature()
{
	int32_t OutResult;
	SBCheckError(TElCMSSignature_AddCountersignature(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCMSSignature::AddCountersignature(const std::vector<uint8_t> &Signature)
{
	int32_t OutResult;
	SBCheckError(TElCMSSignature_AddCountersignature_1(_Handle, SB_STD_VECTOR_FRONT_ADR(Signature), (int32_t)Signature.size(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE int32_t TElCMSSignature::AddTimestamp(TElCustomTSPClient &TSPClient)
{
	int32_t OutResult;
	SBCheckError(TElCMSSignature_AddTimestamp(_Handle, TSPClient.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCMSSignature::AddTimestamp(TElCustomTSPClient *TSPClient)
{
	int32_t OutResult;
	SBCheckError(TElCMSSignature_AddTimestamp(_Handle, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

SB_INLINE int32_t TElCMSSignature::AddTimestamp(const std::vector<uint8_t> &Timestamp)
{
	int32_t OutResult;
	SBCheckError(TElCMSSignature_AddTimestamp_1(_Handle, SB_STD_VECTOR_FRONT_ADR(Timestamp), (int32_t)Timestamp.size(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE int32_t TElCMSSignature::AddContentTimestamp(TElCustomTSPClient &TSPClient)
{
	int32_t OutResult;
	SBCheckError(TElCMSSignature_AddContentTimestamp(_Handle, TSPClient.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCMSSignature::AddContentTimestamp(TElCustomTSPClient *TSPClient)
{
	int32_t OutResult;
	SBCheckError(TElCMSSignature_AddContentTimestamp(_Handle, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

SB_INLINE int32_t TElCMSSignature::AddContentTimestamp(const std::vector<uint8_t> &Timestamp)
{
	int32_t OutResult;
	SBCheckError(TElCMSSignature_AddContentTimestamp_1(_Handle, SB_STD_VECTOR_FRONT_ADR(Timestamp), (int32_t)Timestamp.size(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE int32_t TElCMSSignature::AddValidationTimestamp(TElCustomTSPClient &TSPClient, TSBCMSTimestampType TimestampType)
{
	int32_t OutResult;
	SBCheckError(TElCMSSignature_AddValidationTimestamp(_Handle, TSPClient.getHandle(), (TSBCMSTimestampTypeRaw)TimestampType, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCMSSignature::AddValidationTimestamp(TElCustomTSPClient *TSPClient, TSBCMSTimestampType TimestampType)
{
	int32_t OutResult;
	SBCheckError(TElCMSSignature_AddValidationTimestamp(_Handle, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (TSBCMSTimestampTypeRaw)TimestampType, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELMEMORYCRLSTORAGE_AND_TLIST
SB_INLINE void TElCMSSignature::AddCompleteValidationData(TElCustomCertStorage &Chain, TElMemoryCRLStorage &CRLs, TList &OCSPResponses, bool ReferencesOnly)
{
	SBCheckError(TElCMSSignature_AddCompleteValidationData(_Handle, Chain.getHandle(), CRLs.getHandle(), OCSPResponses.getHandle(), (int8_t)ReferencesOnly));
}

SB_INLINE void TElCMSSignature::AddCompleteValidationData(TElCustomCertStorage *Chain, TElMemoryCRLStorage *CRLs, TList *OCSPResponses, bool ReferencesOnly)
{
	SBCheckError(TElCMSSignature_AddCompleteValidationData(_Handle, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, (CRLs != NULL) ? CRLs->getHandle() : SB_NULL_HANDLE, (OCSPResponses != NULL) ? OCSPResponses->getHandle() : SB_NULL_HANDLE, (int8_t)ReferencesOnly));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELMEMORYCRLSTORAGE_AND_TLIST */

#ifdef SB_USE_CLASSES_TELMEMORYCRLSTORAGE_AND_TELX509CERTIFICATE_AND_TLIST
SB_INLINE void TElCMSSignature::AddCompleteValidationDataItem(TElX509Certificate &Cert, TElMemoryCRLStorage &CRLs, TList &OCSPResponses, bool ReferencesOnly)
{
	SBCheckError(TElCMSSignature_AddCompleteValidationDataItem(_Handle, Cert.getHandle(), CRLs.getHandle(), OCSPResponses.getHandle(), (int8_t)ReferencesOnly));
}

SB_INLINE void TElCMSSignature::AddCompleteValidationDataItem(TElX509Certificate *Cert, TElMemoryCRLStorage *CRLs, TList *OCSPResponses, bool ReferencesOnly)
{
	SBCheckError(TElCMSSignature_AddCompleteValidationDataItem(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (CRLs != NULL) ? CRLs->getHandle() : SB_NULL_HANDLE, (OCSPResponses != NULL) ? OCSPResponses->getHandle() : SB_NULL_HANDLE, (int8_t)ReferencesOnly));
}
#endif /* SB_USE_CLASSES_TELMEMORYCRLSTORAGE_AND_TELX509CERTIFICATE_AND_TLIST */

SB_INLINE void TElCMSSignature::RemoveCountersignature(int32_t Index)
{
	SBCheckError(TElCMSSignature_RemoveCountersignature(_Handle, Index));
}

SB_INLINE void TElCMSSignature::RemoveTimestamp(int32_t Index)
{
	SBCheckError(TElCMSSignature_RemoveTimestamp(_Handle, Index));
}

SB_INLINE void TElCMSSignature::RemoveContentTimestamp(int32_t Index)
{
	SBCheckError(TElCMSSignature_RemoveContentTimestamp(_Handle, Index));
}

SB_INLINE void TElCMSSignature::RemoveValidationTimestamp(int32_t Index)
{
	SBCheckError(TElCMSSignature_RemoveValidationTimestamp(_Handle, Index));
}

SB_INLINE void TElCMSSignature::ClearCountersignatures()
{
	SBCheckError(TElCMSSignature_ClearCountersignatures(_Handle));
}

SB_INLINE void TElCMSSignature::ClearTimestamps()
{
	SBCheckError(TElCMSSignature_ClearTimestamps(_Handle));
}

SB_INLINE void TElCMSSignature::ClearContentTimestamps()
{
	SBCheckError(TElCMSSignature_ClearContentTimestamps(_Handle));
}

SB_INLINE void TElCMSSignature::ClearValidationTimestamps()
{
	SBCheckError(TElCMSSignature_ClearValidationTimestamps(_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE
SB_INLINE void TElCMSSignature::Sign(TElX509Certificate &Cert, TElCustomCertStorage &Chain)
{
	SBCheckError(TElCMSSignature_Sign(_Handle, Cert.getHandle(), Chain.getHandle()));
}

SB_INLINE void TElCMSSignature::Sign(TElX509Certificate *Cert, TElCustomCertStorage *Chain)
{
	SBCheckError(TElCMSSignature_Sign(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE
SB_INLINE void TElCMSSignature::SignRemote(TElX509Certificate &Cert, TSBCMSRemoteSignCallback pMethodSignCallback, void * pDataSignCallback, void * Param, TElCustomCertStorage &Chain)
{
	SBCheckError(TElCMSSignature_SignRemote(_Handle, Cert.getHandle(), pMethodSignCallback, pDataSignCallback, Param, Chain.getHandle()));
}

SB_INLINE void TElCMSSignature::SignRemote(TElX509Certificate *Cert, TSBCMSRemoteSignCallback pMethodSignCallback, void * pDataSignCallback, void * Param, TElCustomCertStorage *Chain)
{
	SBCheckError(TElCMSSignature_SignRemote(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, pMethodSignCallback, pDataSignCallback, Param, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE
SB_INLINE void TElCMSSignature::SignRemote(TElX509Certificate &Cert, TSBCMSRemoteSignCallback pMethodSignCallback, void * pDataSignCallback, bool ExternalHashCalculation, void * Param, TElCustomCertStorage &Chain)
{
	SBCheckError(TElCMSSignature_SignRemote_1(_Handle, Cert.getHandle(), pMethodSignCallback, pDataSignCallback, (int8_t)ExternalHashCalculation, Param, Chain.getHandle()));
}

SB_INLINE void TElCMSSignature::SignRemote(TElX509Certificate *Cert, TSBCMSRemoteSignCallback pMethodSignCallback, void * pDataSignCallback, bool ExternalHashCalculation, void * Param, TElCustomCertStorage *Chain)
{
	SBCheckError(TElCMSSignature_SignRemote_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, pMethodSignCallback, pDataSignCallback, (int8_t)ExternalHashCalculation, Param, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE */

TSBCMSSignatureValidity TElCMSSignature::Validate()
{
	TSBCMSSignatureValidityRaw OutResultRaw = 0;
	SBCheckError(TElCMSSignature_Validate(_Handle, &OutResultRaw));
	return (TSBCMSSignatureValidity)OutResultRaw;
}

TSBCMSAdvancedSignatureValidity TElCMSSignature::Validate(TSBCMSValidationOptions Options)
{
	TSBCMSAdvancedSignatureValidityRaw OutResultRaw = 0;
	SBCheckError(TElCMSSignature_Validate_1(_Handle, (TSBCMSValidationOptionsRaw)Options, &OutResultRaw));
	return (TSBCMSAdvancedSignatureValidity)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATOR
TSBCMSAdvancedSignatureValidity TElCMSSignature::Validate(TElX509CertificateValidator &Validator, TSBCMSValidationOptions Options)
{
	TSBCMSAdvancedSignatureValidityRaw OutResultRaw = 0;
	SBCheckError(TElCMSSignature_Validate_2(_Handle, Validator.getHandle(), (TSBCMSValidationOptionsRaw)Options, &OutResultRaw));
	return (TSBCMSAdvancedSignatureValidity)OutResultRaw;
}

TSBCMSAdvancedSignatureValidity TElCMSSignature::Validate(TElX509CertificateValidator *Validator, TSBCMSValidationOptions Options)
{
	TSBCMSAdvancedSignatureValidityRaw OutResultRaw = 0;
	SBCheckError(TElCMSSignature_Validate_2(_Handle, (Validator != NULL) ? Validator->getHandle() : SB_NULL_HANDLE, (TSBCMSValidationOptionsRaw)Options, &OutResultRaw));
	return (TSBCMSAdvancedSignatureValidity)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATOR */

#ifdef SB_USE_CLASS_TELSIGNEDCMSMESSAGE
SB_INLINE TElSignedCMSMessageHandle TElCMSSignature::GetSignedCMSMessage()
{
	TElSignedCMSMessageHandle OutResult;
	SBCheckError(TElCMSSignature_GetSignedCMSMessage(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSIGNEDCMSMESSAGE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
void TElCMSSignature::InitiateAsyncSign(TElX509Certificate &Cert, TElCustomCertStorage &Chain, TElDCAsyncState &State)
{
	TElClassHandle hState = State.getHandle();
	SBCheckError(TElCMSSignature_InitiateAsyncSign(_Handle, Cert.getHandle(), Chain.getHandle(), &hState));
	State.updateHandle(hState);
}

void TElCMSSignature::InitiateAsyncSign(TElX509Certificate *Cert, TElCustomCertStorage *Chain, TElDCAsyncState &State)
{
	TElClassHandle hState = State.getHandle();
	SBCheckError(TElCMSSignature_InitiateAsyncSign(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, &hState));
	State.updateHandle(hState);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
void TElCMSSignature::InitiateAsyncSign(TElDCAsyncState &State)
{
	TElClassHandle hState = State.getHandle();
	SBCheckError(TElCMSSignature_InitiateAsyncSign_1(_Handle, &hState));
	State.updateHandle(hState);
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
void TElCMSSignature::InitiateAsyncSign(TSBDCAsyncSignMethod AsyncSignMethod, TElDCAsyncState &State)
{
	TElClassHandle hState = State.getHandle();
	SBCheckError(TElCMSSignature_InitiateAsyncSign_2(_Handle, (TSBDCAsyncSignMethodRaw)AsyncSignMethod, &hState));
	State.updateHandle(hState);
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
SB_INLINE void TElCMSSignature::CompleteAsyncSign(TElDCAsyncState &AsyncState)
{
	SBCheckError(TElCMSSignature_CompleteAsyncSign(_Handle, AsyncState.getHandle()));
}

SB_INLINE void TElCMSSignature::CompleteAsyncSign(TElDCAsyncState *AsyncState)
{
	SBCheckError(TElCMSSignature_CompleteAsyncSign(_Handle, (AsyncState != NULL) ? AsyncState->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

SB_INLINE void TElCMSSignature::UpdateCMS()
{
	SBCheckError(TElCMSSignature_UpdateCMS(_Handle));
}

void TElCMSSignature::get_Content(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSSignature_get_Content(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1522358336, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELPKCS7ISSUER
TElPKCS7Issuer* TElCMSSignature::get_Signer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignature_get_Signer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signer)
		this->_Inst_Signer = new TElPKCS7Issuer(hOutResult, ohFalse);
	else
		this->_Inst_Signer->updateHandle(hOutResult);
	return this->_Inst_Signer;
}
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */

SB_INLINE int32_t TElCMSSignature::get_DigestAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElCMSSignature_get_DigestAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCMSSignature::set_DigestAlgorithm(int32_t Value)
{
	SBCheckError(TElCMSSignature_set_DigestAlgorithm(_Handle, Value));
}

void TElCMSSignature::get_EncryptedDigest(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSSignature_get_EncryptedDigest(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1001482175, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElCMSSignature::get_PublicKeyAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElCMSSignature_get_PublicKeyAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCMSSignature::set_PublicKeyAlgorithm(int32_t Value)
{
	SBCheckError(TElCMSSignature_set_PublicKeyAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElCMSSignature::get_FingerprintAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElCMSSignature_get_FingerprintAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCMSSignature::set_FingerprintAlgorithm(int32_t Value)
{
	SBCheckError(TElCMSSignature_set_FingerprintAlgorithm(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
TElPKCS7Attributes* TElCMSSignature::get_CustomSignedAttributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignature_get_CustomSignedAttributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CustomSignedAttributes)
		this->_Inst_CustomSignedAttributes = new TElPKCS7Attributes(hOutResult, ohFalse);
	else
		this->_Inst_CustomSignedAttributes->updateHandle(hOutResult);
	return this->_Inst_CustomSignedAttributes;
}
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
TElPKCS7Attributes* TElCMSSignature::get_CustomUnsignedAttributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignature_get_CustomUnsignedAttributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CustomUnsignedAttributes)
		this->_Inst_CustomUnsignedAttributes = new TElPKCS7Attributes(hOutResult, ohFalse);
	else
		this->_Inst_CustomUnsignedAttributes->updateHandle(hOutResult);
	return this->_Inst_CustomUnsignedAttributes;
}
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

bool TElCMSSignature::get_SignedAttributesPresent()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSSignature_get_SignedAttributesPresent(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElCMSSignature::get_SignatureAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElCMSSignature_get_SignatureAlgorithm(_Handle, &OutResult));
	return OutResult;
}

TElCMSSignature* TElCMSSignature::get_Countersignatures(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignature_get_Countersignatures(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Countersignatures)
		this->_Inst_Countersignatures = new TElCMSSignature(hOutResult, ohFalse);
	else
		this->_Inst_Countersignatures->updateHandle(hOutResult);
	return this->_Inst_Countersignatures;
}

#ifdef SB_USE_CLASS_TELCMSTIMESTAMP
TElCMSTimestamp* TElCMSSignature::get_Timestamps(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignature_get_Timestamps(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Timestamps)
		this->_Inst_Timestamps = new TElCMSTimestamp(hOutResult, ohFalse);
	else
		this->_Inst_Timestamps->updateHandle(hOutResult);
	return this->_Inst_Timestamps;
}
#endif /* SB_USE_CLASS_TELCMSTIMESTAMP */

#ifdef SB_USE_CLASS_TELCMSTIMESTAMP
TElCMSTimestamp* TElCMSSignature::get_ContentTimestamps(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignature_get_ContentTimestamps(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ContentTimestamps)
		this->_Inst_ContentTimestamps = new TElCMSTimestamp(hOutResult, ohFalse);
	else
		this->_Inst_ContentTimestamps->updateHandle(hOutResult);
	return this->_Inst_ContentTimestamps;
}
#endif /* SB_USE_CLASS_TELCMSTIMESTAMP */

#ifdef SB_USE_CLASS_TELCMSTIMESTAMP
TElCMSTimestamp* TElCMSSignature::get_ValidationTimestamps(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignature_get_ValidationTimestamps(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ValidationTimestamps)
		this->_Inst_ValidationTimestamps = new TElCMSTimestamp(hOutResult, ohFalse);
	else
		this->_Inst_ValidationTimestamps->updateHandle(hOutResult);
	return this->_Inst_ValidationTimestamps;
}
#endif /* SB_USE_CLASS_TELCMSTIMESTAMP */

SB_INLINE int32_t TElCMSSignature::get_CountersignatureCount()
{
	int32_t OutResult;
	SBCheckError(TElCMSSignature_get_CountersignatureCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCMSSignature::get_TimestampCount()
{
	int32_t OutResult;
	SBCheckError(TElCMSSignature_get_TimestampCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCMSSignature::get_ContentTimestampCount()
{
	int32_t OutResult;
	SBCheckError(TElCMSSignature_get_ContentTimestampCount(_Handle, &OutResult));
	return OutResult;
}

TSBCMSAdvancedSignatureValidity TElCMSSignature::get_LastValidationResult()
{
	TSBCMSAdvancedSignatureValidityRaw OutResultRaw = 0;
	SBCheckError(TElCMSSignature_get_LastValidationResult(_Handle, &OutResultRaw));
	return (TSBCMSAdvancedSignatureValidity)OutResultRaw;
}

TSBCertificateValidity TElCMSSignature::get_LastValidatorValidity()
{
	TSBCertificateValidityRaw OutResultRaw = 0;
	SBCheckError(TElCMSSignature_get_LastValidatorValidity(_Handle, &OutResultRaw));
	return (TSBCertificateValidity)OutResultRaw;
}

TSBCertificateValidityReason TElCMSSignature::get_LastValidatorReason()
{
	TSBCertificateValidityReasonRaw OutResultRaw = 0;
	SBCheckError(TElCMSSignature_get_LastValidatorReason(_Handle, &OutResultRaw));
	return (TSBCertificateValidityReason)OutResultRaw;
}

void TElCMSSignature::get_ContentType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSSignature_get_ContentType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(784754721, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSSignature::set_ContentType(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCMSSignature_set_ContentType(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int64_t TElCMSSignature::get_SigningTime()
{
	int64_t OutResult;
	SBCheckError(TElCMSSignature_get_SigningTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCMSSignature::set_SigningTime(int64_t Value)
{
	SBCheckError(TElCMSSignature_set_SigningTime(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELCMSSIGNATUREPOLICY
TElCMSSignaturePolicy* TElCMSSignature::get_SignaturePolicy()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignature_get_SignaturePolicy(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignaturePolicy)
		this->_Inst_SignaturePolicy = new TElCMSSignaturePolicy(hOutResult, ohFalse);
	else
		this->_Inst_SignaturePolicy->updateHandle(hOutResult);
	return this->_Inst_SignaturePolicy;
}
#endif /* SB_USE_CLASS_TELCMSSIGNATUREPOLICY */

#ifdef SB_USE_CLASS_TELCMSCONTENTHINTS
TElCMSContentHints* TElCMSSignature::get_ContentHints()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignature_get_ContentHints(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ContentHints)
		this->_Inst_ContentHints = new TElCMSContentHints(hOutResult, ohFalse);
	else
		this->_Inst_ContentHints->updateHandle(hOutResult);
	return this->_Inst_ContentHints;
}
#endif /* SB_USE_CLASS_TELCMSCONTENTHINTS */

void TElCMSSignature::get_ContentIdentifier(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSSignature_get_ContentIdentifier(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1184856461, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSSignature::set_ContentIdentifier(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCMSSignature_set_ContentIdentifier(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELCMSCONTENTREFERENCE
TElCMSContentReference* TElCMSSignature::get_ContentReference()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignature_get_ContentReference(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ContentReference)
		this->_Inst_ContentReference = new TElCMSContentReference(hOutResult, ohFalse);
	else
		this->_Inst_ContentReference->updateHandle(hOutResult);
	return this->_Inst_ContentReference;
}
#endif /* SB_USE_CLASS_TELCMSCONTENTREFERENCE */

#ifdef SB_USE_CLASS_TELCMSCOMMITMENTTYPEINDICATION
TElCMSCommitmentTypeIndication* TElCMSSignature::get_CommitmentTypeIndication()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignature_get_CommitmentTypeIndication(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CommitmentTypeIndication)
		this->_Inst_CommitmentTypeIndication = new TElCMSCommitmentTypeIndication(hOutResult, ohFalse);
	else
		this->_Inst_CommitmentTypeIndication->updateHandle(hOutResult);
	return this->_Inst_CommitmentTypeIndication;
}

SB_INLINE void TElCMSSignature::set_CommitmentTypeIndication(TElCMSCommitmentTypeIndication &Value)
{
	SBCheckError(TElCMSSignature_set_CommitmentTypeIndication(_Handle, Value.getHandle()));
}

SB_INLINE void TElCMSSignature::set_CommitmentTypeIndication(TElCMSCommitmentTypeIndication *Value)
{
	SBCheckError(TElCMSSignature_set_CommitmentTypeIndication(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCMSCOMMITMENTTYPEINDICATION */

#ifdef SB_USE_CLASS_TELCMSSIGNERLOCATION
TElCMSSignerLocation* TElCMSSignature::get_SignerLocation()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignature_get_SignerLocation(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignerLocation)
		this->_Inst_SignerLocation = new TElCMSSignerLocation(hOutResult, ohFalse);
	else
		this->_Inst_SignerLocation->updateHandle(hOutResult);
	return this->_Inst_SignerLocation;
}
#endif /* SB_USE_CLASS_TELCMSSIGNERLOCATION */

#ifdef SB_USE_CLASS_TELCMSSIGNINGCERTIFICATE
TElCMSSigningCertificate* TElCMSSignature::get_SigningCertificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignature_get_SigningCertificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SigningCertificate)
		this->_Inst_SigningCertificate = new TElCMSSigningCertificate(hOutResult, ohFalse);
	else
		this->_Inst_SigningCertificate->updateHandle(hOutResult);
	return this->_Inst_SigningCertificate;
}
#endif /* SB_USE_CLASS_TELCMSSIGNINGCERTIFICATE */

void TElCMSSignature::get_MessageDigest(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSSignature_get_MessageDigest(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(638655577, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElCMSSignature::get_MimeType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCMSSignature_get_MimeType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-746426946, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSSignature::set_MimeType(const std::string &Value)
{
	SBCheckError(TElCMSSignature_set_MimeType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELCMSCERTIFICATEREFS
TElCMSCertificateRefs* TElCMSSignature::get_CertificateRefs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignature_get_CertificateRefs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertificateRefs)
		this->_Inst_CertificateRefs = new TElCMSCertificateRefs(hOutResult, ohFalse);
	else
		this->_Inst_CertificateRefs->updateHandle(hOutResult);
	return this->_Inst_CertificateRefs;
}
#endif /* SB_USE_CLASS_TELCMSCERTIFICATEREFS */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElCMSSignature::get_CertificateValues()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignature_get_CertificateValues(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertificateValues)
		this->_Inst_CertificateValues = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertificateValues->updateHandle(hOutResult);
	return this->_Inst_CertificateValues;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCMSREVOCATIONREFS
TElCMSRevocationRefs* TElCMSSignature::get_RevocationRefs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignature_get_RevocationRefs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RevocationRefs)
		this->_Inst_RevocationRefs = new TElCMSRevocationRefs(hOutResult, ohFalse);
	else
		this->_Inst_RevocationRefs->updateHandle(hOutResult);
	return this->_Inst_RevocationRefs;
}
#endif /* SB_USE_CLASS_TELCMSREVOCATIONREFS */

#ifdef SB_USE_CLASS_TELCMSREVOCATIONVALUES
TElCMSRevocationValues* TElCMSSignature::get_RevocationValues()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignature_get_RevocationValues(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RevocationValues)
		this->_Inst_RevocationValues = new TElCMSRevocationValues(hOutResult, ohFalse);
	else
		this->_Inst_RevocationValues->updateHandle(hOutResult);
	return this->_Inst_RevocationValues;
}
#endif /* SB_USE_CLASS_TELCMSREVOCATIONVALUES */

#ifdef SB_USE_CLASS_TELCMSSIGNERATTRIBUTES
TElCMSSignerAttributes* TElCMSSignature::get_SignerAttributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignature_get_SignerAttributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignerAttributes)
		this->_Inst_SignerAttributes = new TElCMSSignerAttributes(hOutResult, ohFalse);
	else
		this->_Inst_SignerAttributes->updateHandle(hOutResult);
	return this->_Inst_SignerAttributes;
}
#endif /* SB_USE_CLASS_TELCMSSIGNERATTRIBUTES */

#ifdef SB_USE_CLASS_TELCMSSIGNATUREPOLICYSTORE
TElCMSSignaturePolicyStore* TElCMSSignature::get_SignaturePolicyStore()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSSignature_get_SignaturePolicyStore(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignaturePolicyStore)
		this->_Inst_SignaturePolicyStore = new TElCMSSignaturePolicyStore(hOutResult, ohFalse);
	else
		this->_Inst_SignaturePolicyStore->updateHandle(hOutResult);
	return this->_Inst_SignaturePolicyStore;
}
#endif /* SB_USE_CLASS_TELCMSSIGNATUREPOLICYSTORE */

SB_INLINE int32_t TElCMSSignature::get_ValidationTimestampCount()
{
	int32_t OutResult;
	SBCheckError(TElCMSSignature_get_ValidationTimestampCount(_Handle, &OutResult));
	return OutResult;
}

TSBCMSSignatureState TElCMSSignature::get_State()
{
	TSBCMSSignatureStateRaw OutResultRaw = 0;
	SBCheckError(TElCMSSignature_get_State(_Handle, &OutResultRaw));
	return (TSBCMSSignatureState)OutResultRaw;
}

TSBCMSSigningOptions TElCMSSignature::get_SigningOptions()
{
	TSBCMSSigningOptionsRaw OutResultRaw = 0;
	SBCheckError(TElCMSSignature_get_SigningOptions(_Handle, &OutResultRaw));
	return (TSBCMSSigningOptions)OutResultRaw;
}

SB_INLINE void TElCMSSignature::set_SigningOptions(TSBCMSSigningOptions Value)
{
	SBCheckError(TElCMSSignature_set_SigningOptions(_Handle, (TSBCMSSigningOptionsRaw)Value));
}

bool TElCMSSignature::get_UsePSS()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSSignature_get_UsePSS(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMSSignature::set_UsePSS(bool Value)
{
	SBCheckError(TElCMSSignature_set_UsePSS(_Handle, (int8_t)Value));
}

bool TElCMSSignature::get_UseCachedDigests()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSSignature_get_UseCachedDigests(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMSSignature::set_UseCachedDigests(bool Value)
{
	SBCheckError(TElCMSSignature_set_UseCachedDigests(_Handle, (int8_t)Value));
}

bool TElCMSSignature::get_LiberalMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSSignature_get_LiberalMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMSSignature::set_LiberalMode(bool Value)
{
	SBCheckError(TElCMSSignature_set_LiberalMode(_Handle, (int8_t)Value));
}

bool TElCMSSignature::get_AuthenticodeMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSSignature_get_AuthenticodeMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMSSignature::set_AuthenticodeMode(bool Value)
{
	SBCheckError(TElCMSSignature_set_AuthenticodeMode(_Handle, (int8_t)Value));
}

SB_INLINE void TElCMSSignature::get_OnBeforeSign(TSBCMSBeforeSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCMSSignature_get_OnBeforeSign(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCMSSignature::set_OnBeforeSign(TSBCMSBeforeSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCMSSignature_set_OnBeforeSign(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCMSSignature::get_OnBeforeVerify(TSBCMSBeforeVerifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCMSSignature_get_OnBeforeVerify(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCMSSignature::set_OnBeforeVerify(TSBCMSBeforeVerifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCMSSignature_set_OnBeforeVerify(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCMSSignature::get_OnCertificateNeeded(TSBCMSCertificateNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCMSSignature_get_OnCertificateNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCMSSignature::set_OnCertificateNeeded(TSBCMSCertificateNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCMSSignature_set_OnCertificateNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCMSSignature::get_OnIsCertificateTrusted(TSBCMSCertificateTrustedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCMSSignature_get_OnIsCertificateTrusted(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCMSSignature::set_OnIsCertificateTrusted(TSBCMSCertificateTrustedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCMSSignature_set_OnIsCertificateTrusted(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCMSSignature::get_OnCRLNeeded(TSBCMSCRLNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCMSSignature_get_OnCRLNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCMSSignature::set_OnCRLNeeded(TSBCMSCRLNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCMSSignature_set_OnCRLNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCMSSignature::get_OnOCSPResponseNeeded(TSBCMSOCSPResponseNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCMSSignature_get_OnOCSPResponseNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCMSSignature::set_OnOCSPResponseNeeded(TSBCMSOCSPResponseNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCMSSignature_set_OnOCSPResponseNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCMSSignature::get_OnItemValidated(TSBCMSItemValidatedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCMSSignature_get_OnItemValidated(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCMSSignature::set_OnItemValidated(TSBCMSItemValidatedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCMSSignature_set_OnItemValidated(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCMSSignature::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCMSSignature_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCMSSignature::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCMSSignature_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

void TElCMSSignature::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
	this->_Inst_Signer = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	this->_Inst_CustomSignedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	this->_Inst_CustomUnsignedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
	this->_Inst_Countersignatures = NULL;
#ifdef SB_USE_CLASS_TELCMSTIMESTAMP
	this->_Inst_Timestamps = NULL;
#endif /* SB_USE_CLASS_TELCMSTIMESTAMP */
#ifdef SB_USE_CLASS_TELCMSTIMESTAMP
	this->_Inst_ContentTimestamps = NULL;
#endif /* SB_USE_CLASS_TELCMSTIMESTAMP */
#ifdef SB_USE_CLASS_TELCMSTIMESTAMP
	this->_Inst_ValidationTimestamps = NULL;
#endif /* SB_USE_CLASS_TELCMSTIMESTAMP */
#ifdef SB_USE_CLASS_TELCMSSIGNATUREPOLICY
	this->_Inst_SignaturePolicy = NULL;
#endif /* SB_USE_CLASS_TELCMSSIGNATUREPOLICY */
#ifdef SB_USE_CLASS_TELCMSCONTENTHINTS
	this->_Inst_ContentHints = NULL;
#endif /* SB_USE_CLASS_TELCMSCONTENTHINTS */
#ifdef SB_USE_CLASS_TELCMSCONTENTREFERENCE
	this->_Inst_ContentReference = NULL;
#endif /* SB_USE_CLASS_TELCMSCONTENTREFERENCE */
#ifdef SB_USE_CLASS_TELCMSCOMMITMENTTYPEINDICATION
	this->_Inst_CommitmentTypeIndication = NULL;
#endif /* SB_USE_CLASS_TELCMSCOMMITMENTTYPEINDICATION */
#ifdef SB_USE_CLASS_TELCMSSIGNERLOCATION
	this->_Inst_SignerLocation = NULL;
#endif /* SB_USE_CLASS_TELCMSSIGNERLOCATION */
#ifdef SB_USE_CLASS_TELCMSSIGNINGCERTIFICATE
	this->_Inst_SigningCertificate = NULL;
#endif /* SB_USE_CLASS_TELCMSSIGNINGCERTIFICATE */
#ifdef SB_USE_CLASS_TELCMSCERTIFICATEREFS
	this->_Inst_CertificateRefs = NULL;
#endif /* SB_USE_CLASS_TELCMSCERTIFICATEREFS */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertificateValues = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCMSREVOCATIONREFS
	this->_Inst_RevocationRefs = NULL;
#endif /* SB_USE_CLASS_TELCMSREVOCATIONREFS */
#ifdef SB_USE_CLASS_TELCMSREVOCATIONVALUES
	this->_Inst_RevocationValues = NULL;
#endif /* SB_USE_CLASS_TELCMSREVOCATIONVALUES */
#ifdef SB_USE_CLASS_TELCMSSIGNERATTRIBUTES
	this->_Inst_SignerAttributes = NULL;
#endif /* SB_USE_CLASS_TELCMSSIGNERATTRIBUTES */
#ifdef SB_USE_CLASS_TELCMSSIGNATUREPOLICYSTORE
	this->_Inst_SignaturePolicyStore = NULL;
#endif /* SB_USE_CLASS_TELCMSSIGNATUREPOLICYSTORE */
}

TElCMSSignature::TElCMSSignature(TElCMSSignatureHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCMSSignature::TElCMSSignature(TObject &Subject) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSSignature_Create(Subject.getHandle(), &_Handle));
}

TElCMSSignature::TElCMSSignature(TObject *Subject) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSSignature_Create((Subject != NULL) ? Subject->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#ifdef SB_USE_CLASS_TELPKCS7SIGNER
TElCMSSignature::TElCMSSignature(TObject &Subject, TElPKCS7Signer &PKCS7Signer) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSSignature_Create_1(Subject.getHandle(), PKCS7Signer.getHandle(), &_Handle));
}

TElCMSSignature::TElCMSSignature(TObject *Subject, TElPKCS7Signer *PKCS7Signer) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSSignature_Create_1((Subject != NULL) ? Subject->getHandle() : SB_NULL_HANDLE, (PKCS7Signer != NULL) ? PKCS7Signer->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPKCS7SIGNER */

TElCMSSignature::TElCMSSignature(TObject &Subject, const std::vector<uint8_t> &Data) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSSignature_Create_2(Subject.getHandle(), SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), &_Handle));
}

TElCMSSignature::TElCMSSignature(TObject *Subject, const std::vector<uint8_t> &Data) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSSignature_Create_2((Subject != NULL) ? Subject->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), &_Handle));
}

TElCMSSignature::~TElCMSSignature()
{
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
	delete this->_Inst_Signer;
	this->_Inst_Signer = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	delete this->_Inst_CustomSignedAttributes;
	this->_Inst_CustomSignedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	delete this->_Inst_CustomUnsignedAttributes;
	this->_Inst_CustomUnsignedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
	delete this->_Inst_Countersignatures;
	this->_Inst_Countersignatures = NULL;
#ifdef SB_USE_CLASS_TELCMSTIMESTAMP
	delete this->_Inst_Timestamps;
	this->_Inst_Timestamps = NULL;
#endif /* SB_USE_CLASS_TELCMSTIMESTAMP */
#ifdef SB_USE_CLASS_TELCMSTIMESTAMP
	delete this->_Inst_ContentTimestamps;
	this->_Inst_ContentTimestamps = NULL;
#endif /* SB_USE_CLASS_TELCMSTIMESTAMP */
#ifdef SB_USE_CLASS_TELCMSTIMESTAMP
	delete this->_Inst_ValidationTimestamps;
	this->_Inst_ValidationTimestamps = NULL;
#endif /* SB_USE_CLASS_TELCMSTIMESTAMP */
#ifdef SB_USE_CLASS_TELCMSSIGNATUREPOLICY
	delete this->_Inst_SignaturePolicy;
	this->_Inst_SignaturePolicy = NULL;
#endif /* SB_USE_CLASS_TELCMSSIGNATUREPOLICY */
#ifdef SB_USE_CLASS_TELCMSCONTENTHINTS
	delete this->_Inst_ContentHints;
	this->_Inst_ContentHints = NULL;
#endif /* SB_USE_CLASS_TELCMSCONTENTHINTS */
#ifdef SB_USE_CLASS_TELCMSCONTENTREFERENCE
	delete this->_Inst_ContentReference;
	this->_Inst_ContentReference = NULL;
#endif /* SB_USE_CLASS_TELCMSCONTENTREFERENCE */
#ifdef SB_USE_CLASS_TELCMSCOMMITMENTTYPEINDICATION
	delete this->_Inst_CommitmentTypeIndication;
	this->_Inst_CommitmentTypeIndication = NULL;
#endif /* SB_USE_CLASS_TELCMSCOMMITMENTTYPEINDICATION */
#ifdef SB_USE_CLASS_TELCMSSIGNERLOCATION
	delete this->_Inst_SignerLocation;
	this->_Inst_SignerLocation = NULL;
#endif /* SB_USE_CLASS_TELCMSSIGNERLOCATION */
#ifdef SB_USE_CLASS_TELCMSSIGNINGCERTIFICATE
	delete this->_Inst_SigningCertificate;
	this->_Inst_SigningCertificate = NULL;
#endif /* SB_USE_CLASS_TELCMSSIGNINGCERTIFICATE */
#ifdef SB_USE_CLASS_TELCMSCERTIFICATEREFS
	delete this->_Inst_CertificateRefs;
	this->_Inst_CertificateRefs = NULL;
#endif /* SB_USE_CLASS_TELCMSCERTIFICATEREFS */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertificateValues;
	this->_Inst_CertificateValues = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCMSREVOCATIONREFS
	delete this->_Inst_RevocationRefs;
	this->_Inst_RevocationRefs = NULL;
#endif /* SB_USE_CLASS_TELCMSREVOCATIONREFS */
#ifdef SB_USE_CLASS_TELCMSREVOCATIONVALUES
	delete this->_Inst_RevocationValues;
	this->_Inst_RevocationValues = NULL;
#endif /* SB_USE_CLASS_TELCMSREVOCATIONVALUES */
#ifdef SB_USE_CLASS_TELCMSSIGNERATTRIBUTES
	delete this->_Inst_SignerAttributes;
	this->_Inst_SignerAttributes = NULL;
#endif /* SB_USE_CLASS_TELCMSSIGNERATTRIBUTES */
#ifdef SB_USE_CLASS_TELCMSSIGNATUREPOLICYSTORE
	delete this->_Inst_SignaturePolicyStore;
	this->_Inst_SignaturePolicyStore = NULL;
#endif /* SB_USE_CLASS_TELCMSSIGNATUREPOLICYSTORE */
}
#endif /* SB_USE_CLASS_TELCMSSIGNATURE */

#ifdef SB_USE_CLASS_TELCMSTIMESTAMP

bool TElCMSTimestamp::Validate()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSTimestamp_Validate(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMSTimestamp::UpdateCMS()
{
	SBCheckError(TElCMSTimestamp_UpdateCMS(_Handle));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElCMSTimestamp::get_Certificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSTimestamp_get_Certificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
TElMemoryCRLStorage* TElCMSTimestamp::get_CRLs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSTimestamp_get_CRLs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CRLs)
		this->_Inst_CRLs = new TElMemoryCRLStorage(hOutResult, ohFalse);
	else
		this->_Inst_CRLs->updateHandle(hOutResult);
	return this->_Inst_CRLs;
}
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */

#ifdef SB_USE_CLASS_TELOCSPRESPONSESTORAGE
TElOCSPResponseStorage* TElCMSTimestamp::get_OCSPResponses()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSTimestamp_get_OCSPResponses(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OCSPResponses)
		this->_Inst_OCSPResponses = new TElOCSPResponseStorage(hOutResult, ohFalse);
	else
		this->_Inst_OCSPResponses->updateHandle(hOutResult);
	return this->_Inst_OCSPResponses;
}
#endif /* SB_USE_CLASS_TELOCSPRESPONSESTORAGE */

#ifdef SB_USE_CLASS_TELCMSSIGNATURE
TElCMSSignature* TElCMSTimestamp::get_Signatures(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSTimestamp_get_Signatures(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signatures)
		this->_Inst_Signatures = new TElCMSSignature(hOutResult, ohFalse);
	else
		this->_Inst_Signatures->updateHandle(hOutResult);
	return this->_Inst_Signatures;
}
#endif /* SB_USE_CLASS_TELCMSSIGNATURE */

SB_INLINE int32_t TElCMSTimestamp::get_SignatureCount()
{
	int32_t OutResult;
	SBCheckError(TElCMSTimestamp_get_SignatureCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
TElClientTSPInfo* TElCMSTimestamp::get_Info()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSTimestamp_get_Info(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Info)
		this->_Inst_Info = new TElClientTSPInfo(hOutResult, ohFalse);
	else
		this->_Inst_Info->updateHandle(hOutResult);
	return this->_Inst_Info;
}
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

TSBCMSTimestampType TElCMSTimestamp::get_TimestampType()
{
	TSBCMSTimestampTypeRaw OutResultRaw = 0;
	SBCheckError(TElCMSTimestamp_get_TimestampType(_Handle, &OutResultRaw));
	return (TSBCMSTimestampType)OutResultRaw;
}

bool TElCMSTimestamp::get_UseCachedDigests()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSTimestamp_get_UseCachedDigests(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMSTimestamp::set_UseCachedDigests(bool Value)
{
	SBCheckError(TElCMSTimestamp_set_UseCachedDigests(_Handle, (int8_t)Value));
}

void TElCMSTimestamp::get_DigestCalcType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCMSTimestamp_get_DigestCalcType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(6583594, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElCMSTimestamp::get_CMS(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSTimestamp_get_CMS(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-575010221, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElCMSTimestamp::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
	this->_Inst_CRLs = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TELOCSPRESPONSESTORAGE
	this->_Inst_OCSPResponses = NULL;
#endif /* SB_USE_CLASS_TELOCSPRESPONSESTORAGE */
#ifdef SB_USE_CLASS_TELCMSSIGNATURE
	this->_Inst_Signatures = NULL;
#endif /* SB_USE_CLASS_TELCMSSIGNATURE */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	this->_Inst_Info = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
}

TElCMSTimestamp::TElCMSTimestamp(TElCMSTimestampHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCMSTimestamp::TElCMSTimestamp(TObject &Subject) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSTimestamp_Create(Subject.getHandle(), &_Handle));
}

TElCMSTimestamp::TElCMSTimestamp(TObject *Subject) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSTimestamp_Create((Subject != NULL) ? Subject->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElCMSTimestamp::TElCMSTimestamp(TObject &Subject, const std::vector<uint8_t> &Data) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSTimestamp_Create_1(Subject.getHandle(), SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), &_Handle));
}

TElCMSTimestamp::TElCMSTimestamp(TObject *Subject, const std::vector<uint8_t> &Data) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSTimestamp_Create_1((Subject != NULL) ? Subject->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), &_Handle));
}

TElCMSTimestamp::~TElCMSTimestamp()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
	delete this->_Inst_CRLs;
	this->_Inst_CRLs = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TELOCSPRESPONSESTORAGE
	delete this->_Inst_OCSPResponses;
	this->_Inst_OCSPResponses = NULL;
#endif /* SB_USE_CLASS_TELOCSPRESPONSESTORAGE */
#ifdef SB_USE_CLASS_TELCMSSIGNATURE
	delete this->_Inst_Signatures;
	this->_Inst_Signatures = NULL;
#endif /* SB_USE_CLASS_TELCMSSIGNATURE */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	delete this->_Inst_Info;
	this->_Inst_Info = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
}
#endif /* SB_USE_CLASS_TELCMSTIMESTAMP */

#ifdef SB_USE_CLASS_TELATSHASHINDEXPROCESSOR

SB_INLINE void TElATSHashIndexProcessor::Clear()
{
	SBCheckError(TElATSHashIndexProcessor_Clear(_Handle));
}

SB_INLINE void TElATSHashIndexProcessor::Load(const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Count)
{
	SBCheckError(TElATSHashIndexProcessor_Load(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), StartIndex, Count));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
bool TElATSHashIndexProcessor::CertPresent(TElX509Certificate &Cert)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElATSHashIndexProcessor_CertPresent(_Handle, Cert.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElATSHashIndexProcessor::CertPresent(TElX509Certificate *Cert)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElATSHashIndexProcessor_CertPresent(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
bool TElATSHashIndexProcessor::CRLPresent(TElCertificateRevocationList &Crl)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElATSHashIndexProcessor_CRLPresent(_Handle, Crl.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElATSHashIndexProcessor::CRLPresent(TElCertificateRevocationList *Crl)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElATSHashIndexProcessor_CRLPresent(_Handle, (Crl != NULL) ? Crl->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
bool TElATSHashIndexProcessor::OCSPResponsePresent(TElOCSPResponse &OcspResponse)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElATSHashIndexProcessor_OCSPResponsePresent(_Handle, OcspResponse.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElATSHashIndexProcessor::OCSPResponsePresent(TElOCSPResponse *OcspResponse)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElATSHashIndexProcessor_OCSPResponsePresent(_Handle, (OcspResponse != NULL) ? OcspResponse->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

void TElATSHashIndexProcessor::get_CertHashes(int32_t Index, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElATSHashIndexProcessor_get_CertHashes(_Handle, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1017755210, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElATSHashIndexProcessor::get_CertHashesCount()
{
	int32_t OutResult;
	SBCheckError(TElATSHashIndexProcessor_get_CertHashesCount(_Handle, &OutResult));
	return OutResult;
}

void TElATSHashIndexProcessor::get_RevInfoHashes(int32_t Index, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElATSHashIndexProcessor_get_RevInfoHashes(_Handle, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-815929982, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElATSHashIndexProcessor::get_RevInfoHashesCount()
{
	int32_t OutResult;
	SBCheckError(TElATSHashIndexProcessor_get_RevInfoHashesCount(_Handle, &OutResult));
	return OutResult;
}

void TElATSHashIndexProcessor::get_AttributeHashes(int32_t Index, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElATSHashIndexProcessor_get_AttributeHashes(_Handle, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2097616764, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElATSHashIndexProcessor::get_AttributeHashesCount()
{
	int32_t OutResult;
	SBCheckError(TElATSHashIndexProcessor_get_AttributeHashesCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElATSHashIndexProcessor::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElATSHashIndexProcessor_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

TElATSHashIndexProcessor::TElATSHashIndexProcessor(TElATSHashIndexProcessorHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElATSHashIndexProcessor::TElATSHashIndexProcessor() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElATSHashIndexProcessor_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELATSHASHINDEXPROCESSOR */

#ifdef SB_USE_CLASS_TELCMSMESSAGE

SB_INLINE void TElCMSMessage::Clear()
{
	SBCheckError(TElCMSMessage_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElCMSMessage::CreateNew(TStream &DataStream, int64_t Offset, int64_t Size)
{
	SBCheckError(TElCMSMessage_CreateNew(_Handle, DataStream.getHandle(), Offset, Size));
}

SB_INLINE void TElCMSMessage::CreateNew(TStream *DataStream, int64_t Offset, int64_t Size)
{
	SBCheckError(TElCMSMessage_CreateNew(_Handle, (DataStream != NULL) ? DataStream->getHandle() : SB_NULL_HANDLE, Offset, Size));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElCMSMessage::CreateNew(void * Buffer, int32_t Size)
{
	SBCheckError(TElCMSMessage_CreateNew_1(_Handle, Buffer, Size));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElCMSMessage::Open(TStream &CMSStream, TStream &DataStream, int64_t CMSCount, int64_t DataCount)
{
	SBCheckError(TElCMSMessage_Open(_Handle, CMSStream.getHandle(), DataStream.getHandle(), CMSCount, DataCount));
}

SB_INLINE void TElCMSMessage::Open(TStream *CMSStream, TStream *DataStream, int64_t CMSCount, int64_t DataCount)
{
	SBCheckError(TElCMSMessage_Open(_Handle, (CMSStream != NULL) ? CMSStream->getHandle() : SB_NULL_HANDLE, (DataStream != NULL) ? DataStream->getHandle() : SB_NULL_HANDLE, CMSCount, DataCount));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElCMSMessage::Save(TStream &DestStream)
{
	SBCheckError(TElCMSMessage_Save(_Handle, DestStream.getHandle()));
}

SB_INLINE void TElCMSMessage::Save(TStream *DestStream)
{
	SBCheckError(TElCMSMessage_Save(_Handle, (DestStream != NULL) ? DestStream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElCMSMessage::Close()
{
	SBCheckError(TElCMSMessage_Close(_Handle));
}

#ifdef SB_USE_CLASS_TELCMSCONTENT
TElCMSContent* TElCMSMessage::get_Content()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMSMessage_get_Content(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Content)
		this->_Inst_Content = new TElCMSContent(hOutResult, ohFalse);
	else
		this->_Inst_Content->updateHandle(hOutResult);
	return this->_Inst_Content;
}
#endif /* SB_USE_CLASS_TELCMSCONTENT */

bool TElCMSMessage::get_Detached()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSMessage_get_Detached(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMSMessage::set_Detached(bool Value)
{
	SBCheckError(TElCMSMessage_set_Detached(_Handle, (int8_t)Value));
}

bool TElCMSMessage::get_UseUndefSize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMSMessage_get_UseUndefSize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMSMessage::set_UseUndefSize(bool Value)
{
	SBCheckError(TElCMSMessage_set_UseUndefSize(_Handle, (int8_t)Value));
}

void TElCMSMessage::initInstances()
{
#ifdef SB_USE_CLASS_TELCMSCONTENT
	this->_Inst_Content = NULL;
#endif /* SB_USE_CLASS_TELCMSCONTENT */
}

TElCMSMessage::TElCMSMessage(TElCMSMessageHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElCMSMessage::TElCMSMessage(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSMessage_Create(AOwner.getHandle(), &_Handle));
}

TElCMSMessage::TElCMSMessage(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMSMessage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElCMSMessage::~TElCMSMessage()
{
#ifdef SB_USE_CLASS_TELCMSCONTENT
	delete this->_Inst_Content;
	this->_Inst_Content = NULL;
#endif /* SB_USE_CLASS_TELCMSCONTENT */
}
#endif /* SB_USE_CLASS_TELCMSMESSAGE */

#ifdef SB_USE_CLASS_TELCMSCONTENTHASH

SB_INLINE void TElCMSContentHash::Clear()
{
	SBCheckError(TElCMSContentHash_Clear(_Handle));
}

void TElCMSContentHash::GetHash(int32_t Alg, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMSContentHash_GetHash(_Handle, Alg, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(92069767, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMSContentHash::SetHash(int32_t Alg, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCMSContentHash_SetHash(_Handle, Alg, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElCMSContentHash::TElCMSContentHash(TElCMSContentHashHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElCMSContentHash::TElCMSContentHash() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCMSContentHash_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCMSCONTENTHASH */

#ifdef SB_USE_CLASS_TELSIGNEDCMSMESSAGE

SB_INLINE int32_t TElSignedCMSMessage::AddSignature()
{
	int32_t OutResult;
	SBCheckError(TElSignedCMSMessage_AddSignature(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSignedCMSMessage::RemoveSignature(int32_t Index)
{
	SBCheckError(TElSignedCMSMessage_RemoveSignature(_Handle, Index));
}

SB_INLINE void TElSignedCMSMessage::ClearSignatures()
{
	SBCheckError(TElSignedCMSMessage_ClearSignatures(_Handle));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElSignedCMSMessage::ExtractAllCertificates(TElCustomCertStorage &Storage)
{
	SBCheckError(TElSignedCMSMessage_ExtractAllCertificates(_Handle, Storage.getHandle()));
}

SB_INLINE void TElSignedCMSMessage::ExtractAllCertificates(TElCustomCertStorage *Storage)
{
	SBCheckError(TElSignedCMSMessage_ExtractAllCertificates(_Handle, (Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELMEMORYCRLSTORAGE_AND_TLIST
SB_INLINE void TElSignedCMSMessage::ExtractAllValidationElements(TElCustomCertStorage &Storage, TElMemoryCRLStorage &Crls, TList &Ocsps)
{
	SBCheckError(TElSignedCMSMessage_ExtractAllValidationElements(_Handle, Storage.getHandle(), Crls.getHandle(), Ocsps.getHandle()));
}

SB_INLINE void TElSignedCMSMessage::ExtractAllValidationElements(TElCustomCertStorage *Storage, TElMemoryCRLStorage *Crls, TList *Ocsps)
{
	SBCheckError(TElSignedCMSMessage_ExtractAllValidationElements(_Handle, (Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, (Crls != NULL) ? Crls->getHandle() : SB_NULL_HANDLE, (Ocsps != NULL) ? Ocsps->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELMEMORYCRLSTORAGE_AND_TLIST */

void TElSignedCMSMessage::get_ContentType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSignedCMSMessage_get_ContentType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1146624711, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSignedCMSMessage::set_ContentType(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSignedCMSMessage_set_ContentType(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElSignedCMSMessage::get_ContentVersion()
{
	int32_t OutResult;
	SBCheckError(TElSignedCMSMessage_get_ContentVersion(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSignedCMSMessage::set_ContentVersion(int32_t Value)
{
	SBCheckError(TElSignedCMSMessage_set_ContentVersion(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElSignedCMSMessage::get_Certificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSignedCMSMessage_get_Certificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
TElMemoryCRLStorage* TElSignedCMSMessage::get_CRLs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSignedCMSMessage_get_CRLs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CRLs)
		this->_Inst_CRLs = new TElMemoryCRLStorage(hOutResult, ohFalse);
	else
		this->_Inst_CRLs->updateHandle(hOutResult);
	return this->_Inst_CRLs;
}
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */

#ifdef SB_USE_CLASS_TELOCSPRESPONSESTORAGE
TElOCSPResponseStorage* TElSignedCMSMessage::get_OCSPResponses()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSignedCMSMessage_get_OCSPResponses(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OCSPResponses)
		this->_Inst_OCSPResponses = new TElOCSPResponseStorage(hOutResult, ohFalse);
	else
		this->_Inst_OCSPResponses->updateHandle(hOutResult);
	return this->_Inst_OCSPResponses;
}
#endif /* SB_USE_CLASS_TELOCSPRESPONSESTORAGE */

#ifdef SB_USE_CLASS_TELCMSSIGNATURE
TElCMSSignature* TElSignedCMSMessage::get_Signatures(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSignedCMSMessage_get_Signatures(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signatures)
		this->_Inst_Signatures = new TElCMSSignature(hOutResult, ohFalse);
	else
		this->_Inst_Signatures->updateHandle(hOutResult);
	return this->_Inst_Signatures;
}
#endif /* SB_USE_CLASS_TELCMSSIGNATURE */

SB_INLINE int32_t TElSignedCMSMessage::get_SignatureCount()
{
	int32_t OutResult;
	SBCheckError(TElSignedCMSMessage_get_SignatureCount(_Handle, &OutResult));
	return OutResult;
}

bool TElSignedCMSMessage::get_UseImplicitContent()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSignedCMSMessage_get_UseImplicitContent(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSignedCMSMessage::set_UseImplicitContent(bool Value)
{
	SBCheckError(TElSignedCMSMessage_set_UseImplicitContent(_Handle, (int8_t)Value));
}

bool TElSignedCMSMessage::get_SerializeContentOnUpdate()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSignedCMSMessage_get_SerializeContentOnUpdate(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSignedCMSMessage::set_SerializeContentOnUpdate(bool Value)
{
	SBCheckError(TElSignedCMSMessage_set_SerializeContentOnUpdate(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElSignedCMSMessage::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSignedCMSMessage_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElSignedCMSMessage::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElSignedCMSMessage_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSignedCMSMessage::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElSignedCMSMessage_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

void TElSignedCMSMessage::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
	this->_Inst_CRLs = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TELOCSPRESPONSESTORAGE
	this->_Inst_OCSPResponses = NULL;
#endif /* SB_USE_CLASS_TELOCSPRESPONSESTORAGE */
#ifdef SB_USE_CLASS_TELCMSSIGNATURE
	this->_Inst_Signatures = NULL;
#endif /* SB_USE_CLASS_TELCMSSIGNATURE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElSignedCMSMessage::TElSignedCMSMessage(TElSignedCMSMessageHandle handle, TElOwnHandle ownHandle) : TElCMSMessage(handle, ownHandle)
{
	initInstances();
}

TElSignedCMSMessage::TElSignedCMSMessage(TComponent &AOwner) : TElCMSMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSignedCMSMessage_Create(AOwner.getHandle(), &_Handle));
}

TElSignedCMSMessage::TElSignedCMSMessage(TComponent *AOwner) : TElCMSMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSignedCMSMessage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSignedCMSMessage::~TElSignedCMSMessage()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
	delete this->_Inst_CRLs;
	this->_Inst_CRLs = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TELOCSPRESPONSESTORAGE
	delete this->_Inst_OCSPResponses;
	this->_Inst_OCSPResponses = NULL;
#endif /* SB_USE_CLASS_TELOCSPRESPONSESTORAGE */
#ifdef SB_USE_CLASS_TELCMSSIGNATURE
	delete this->_Inst_Signatures;
	this->_Inst_Signatures = NULL;
#endif /* SB_USE_CLASS_TELCMSSIGNATURE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELSIGNEDCMSMESSAGE */

#ifdef SB_USE_CLASS_TELSIGNEDANDENVELOPEDCMSMESSAGE

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElSignedAndEnvelopedCMSMessage::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSignedAndEnvelopedCMSMessage_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElSignedAndEnvelopedCMSMessage::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElSignedAndEnvelopedCMSMessage_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElSignedAndEnvelopedCMSMessage::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElSignedAndEnvelopedCMSMessage_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElSignedAndEnvelopedCMSMessage::get_Recipients()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSignedAndEnvelopedCMSMessage_get_Recipients(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Recipients)
		this->_Inst_Recipients = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_Recipients->updateHandle(hOutResult);
	return this->_Inst_Recipients;
}

SB_INLINE void TElSignedAndEnvelopedCMSMessage::set_Recipients(TElCustomCertStorage &Value)
{
	SBCheckError(TElSignedAndEnvelopedCMSMessage_set_Recipients(_Handle, Value.getHandle()));
}

SB_INLINE void TElSignedAndEnvelopedCMSMessage::set_Recipients(TElCustomCertStorage *Value)
{
	SBCheckError(TElSignedAndEnvelopedCMSMessage_set_Recipients(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

SB_INLINE int32_t TElSignedAndEnvelopedCMSMessage::get_Algorithm()
{
	int32_t OutResult;
	SBCheckError(TElSignedAndEnvelopedCMSMessage_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSignedAndEnvelopedCMSMessage::set_Algorithm(int32_t Value)
{
	SBCheckError(TElSignedAndEnvelopedCMSMessage_set_Algorithm(_Handle, Value));
}

SB_INLINE int32_t TElSignedAndEnvelopedCMSMessage::get_BitsInKey()
{
	int32_t OutResult;
	SBCheckError(TElSignedAndEnvelopedCMSMessage_get_BitsInKey(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSignedAndEnvelopedCMSMessage::set_BitsInKey(int32_t Value)
{
	SBCheckError(TElSignedAndEnvelopedCMSMessage_set_BitsInKey(_Handle, Value));
}

bool TElSignedAndEnvelopedCMSMessage::get_UseImplicitContentEncoding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSignedAndEnvelopedCMSMessage_get_UseImplicitContentEncoding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSignedAndEnvelopedCMSMessage::set_UseImplicitContentEncoding(bool Value)
{
	SBCheckError(TElSignedAndEnvelopedCMSMessage_set_UseImplicitContentEncoding(_Handle, (int8_t)Value));
}

bool TElSignedAndEnvelopedCMSMessage::get_UseOAEP()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSignedAndEnvelopedCMSMessage_get_UseOAEP(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSignedAndEnvelopedCMSMessage::set_UseOAEP(bool Value)
{
	SBCheckError(TElSignedAndEnvelopedCMSMessage_set_UseOAEP(_Handle, (int8_t)Value));
}

bool TElSignedAndEnvelopedCMSMessage::get_AlignEncryptedKey()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSignedAndEnvelopedCMSMessage_get_AlignEncryptedKey(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSignedAndEnvelopedCMSMessage::set_AlignEncryptedKey(bool Value)
{
	SBCheckError(TElSignedAndEnvelopedCMSMessage_set_AlignEncryptedKey(_Handle, (int8_t)Value));
}

void TElSignedAndEnvelopedCMSMessage::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_Recipients = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElSignedAndEnvelopedCMSMessage::TElSignedAndEnvelopedCMSMessage(TElSignedAndEnvelopedCMSMessageHandle handle, TElOwnHandle ownHandle) : TElSignedCMSMessage(handle, ownHandle)
{
	initInstances();
}

TElSignedAndEnvelopedCMSMessage::TElSignedAndEnvelopedCMSMessage(TComponent &AOwner) : TElSignedCMSMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSignedAndEnvelopedCMSMessage_Create(AOwner.getHandle(), &_Handle));
}

TElSignedAndEnvelopedCMSMessage::TElSignedAndEnvelopedCMSMessage(TComponent *AOwner) : TElSignedCMSMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSignedAndEnvelopedCMSMessage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSignedAndEnvelopedCMSMessage::~TElSignedAndEnvelopedCMSMessage()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_Recipients;
	this->_Inst_Recipients = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELSIGNEDANDENVELOPEDCMSMESSAGE */

#ifdef SB_USE_GLOBAL_PROCS_CMS

void GetTimestampTypeOID(TSBCMSTimestampType TimestampType, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBCMS_GetTimestampTypeOID((TSBCMSTimestampTypeRaw)TimestampType, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(870254217, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#endif /* SB_USE_GLOBAL_PROCS_CMS */

};	/* namespace SecureBlackbox */

