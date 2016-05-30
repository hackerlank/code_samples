#include "sbdcdef.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELDCPKCS7SIGNPARAMETERS

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElDCPKCS7SignParameters::SaveToRDN(TElRelativeDistinguishedName &Rdn)
{
	SBCheckError(TElDCPKCS7SignParameters_SaveToRDN(_Handle, Rdn.getHandle()));
}

SB_INLINE void TElDCPKCS7SignParameters::SaveToRDN(TElRelativeDistinguishedName *Rdn)
{
	SBCheckError(TElDCPKCS7SignParameters_SaveToRDN(_Handle, (Rdn != NULL) ? Rdn->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElDCPKCS7SignParameters::LoadFromRDN(TElRelativeDistinguishedName &Rdn)
{
	SBCheckError(TElDCPKCS7SignParameters_LoadFromRDN(_Handle, Rdn.getHandle()));
}

SB_INLINE void TElDCPKCS7SignParameters::LoadFromRDN(TElRelativeDistinguishedName *Rdn)
{
	SBCheckError(TElDCPKCS7SignParameters_LoadFromRDN(_Handle, (Rdn != NULL) ? Rdn->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

void TElDCPKCS7SignParameters::get_ContentType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDCPKCS7SignParameters_get_ContentType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1664227776, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDCPKCS7SignParameters::set_ContentType(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDCPKCS7SignParameters_set_ContentType(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElDCPKCS7SignParameters::get_SgnDataVersion()
{
	int32_t OutResult;
	SBCheckError(TElDCPKCS7SignParameters_get_SgnDataVersion(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDCPKCS7SignParameters::set_SgnDataVersion(int32_t Value)
{
	SBCheckError(TElDCPKCS7SignParameters_set_SgnDataVersion(_Handle, Value));
}

SB_INLINE int64_t TElDCPKCS7SignParameters::get_SigningTime()
{
	int64_t OutResult;
	SBCheckError(TElDCPKCS7SignParameters_get_SigningTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDCPKCS7SignParameters::set_SigningTime(int64_t Value)
{
	SBCheckError(TElDCPKCS7SignParameters_set_SigningTime(_Handle, Value));
}

bool TElDCPKCS7SignParameters::get_Timestamp()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDCPKCS7SignParameters_get_Timestamp(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDCPKCS7SignParameters::set_Timestamp(bool Value)
{
	SBCheckError(TElDCPKCS7SignParameters_set_Timestamp(_Handle, (int8_t)Value));
}

void TElDCPKCS7SignParameters::get_TimestampServiceID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDCPKCS7SignParameters_get_TimestampServiceID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1260075343, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDCPKCS7SignParameters::set_TimestampServiceID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDCPKCS7SignParameters_set_TimestampServiceID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElDCPKCS7SignParameters::get_TimestampHashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElDCPKCS7SignParameters_get_TimestampHashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDCPKCS7SignParameters::set_TimestampHashAlgorithm(int32_t Value)
{
	SBCheckError(TElDCPKCS7SignParameters_set_TimestampHashAlgorithm(_Handle, Value));
}

bool TElDCPKCS7SignParameters::get_IncludeCertsToSgnData()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDCPKCS7SignParameters_get_IncludeCertsToSgnData(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDCPKCS7SignParameters::set_IncludeCertsToSgnData(bool Value)
{
	SBCheckError(TElDCPKCS7SignParameters_set_IncludeCertsToSgnData(_Handle, (int8_t)Value));
}

bool TElDCPKCS7SignParameters::get_IncludeCRLsToSgnData()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDCPKCS7SignParameters_get_IncludeCRLsToSgnData(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDCPKCS7SignParameters::set_IncludeCRLsToSgnData(bool Value)
{
	SBCheckError(TElDCPKCS7SignParameters_set_IncludeCRLsToSgnData(_Handle, (int8_t)Value));
}

bool TElDCPKCS7SignParameters::get_IncludeRevInfoToAttributes()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDCPKCS7SignParameters_get_IncludeRevInfoToAttributes(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDCPKCS7SignParameters::set_IncludeRevInfoToAttributes(bool Value)
{
	SBCheckError(TElDCPKCS7SignParameters_set_IncludeRevInfoToAttributes(_Handle, (int8_t)Value));
}

bool TElDCPKCS7SignParameters::get_IncludeCertChain()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDCPKCS7SignParameters_get_IncludeCertChain(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDCPKCS7SignParameters::set_IncludeCertChain(bool Value)
{
	SBCheckError(TElDCPKCS7SignParameters_set_IncludeCertChain(_Handle, (int8_t)Value));
}

bool TElDCPKCS7SignParameters::get_InsertMessageDigests()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDCPKCS7SignParameters_get_InsertMessageDigests(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDCPKCS7SignParameters::set_InsertMessageDigests(bool Value)
{
	SBCheckError(TElDCPKCS7SignParameters_set_InsertMessageDigests(_Handle, (int8_t)Value));
}

bool TElDCPKCS7SignParameters::get_InsertSigningTime()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDCPKCS7SignParameters_get_InsertSigningTime(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDCPKCS7SignParameters::set_InsertSigningTime(bool Value)
{
	SBCheckError(TElDCPKCS7SignParameters_set_InsertSigningTime(_Handle, (int8_t)Value));
}

bool TElDCPKCS7SignParameters::get_InsertContentType()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDCPKCS7SignParameters_get_InsertContentType(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDCPKCS7SignParameters::set_InsertContentType(bool Value)
{
	SBCheckError(TElDCPKCS7SignParameters_set_InsertContentType(_Handle, (int8_t)Value));
}

bool TElDCPKCS7SignParameters::get_InsertSigningCertificateAttr()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDCPKCS7SignParameters_get_InsertSigningCertificateAttr(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDCPKCS7SignParameters::set_InsertSigningCertificateAttr(bool Value)
{
	SBCheckError(TElDCPKCS7SignParameters_set_InsertSigningCertificateAttr(_Handle, (int8_t)Value));
}

bool TElDCPKCS7SignParameters::get_IgnoreTimestampFailure()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDCPKCS7SignParameters_get_IgnoreTimestampFailure(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDCPKCS7SignParameters::set_IgnoreTimestampFailure(bool Value)
{
	SBCheckError(TElDCPKCS7SignParameters_set_IgnoreTimestampFailure(_Handle, (int8_t)Value));
}

bool TElDCPKCS7SignParameters::get_UseGeneralizedTimeFormat()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDCPKCS7SignParameters_get_UseGeneralizedTimeFormat(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDCPKCS7SignParameters::set_UseGeneralizedTimeFormat(bool Value)
{
	SBCheckError(TElDCPKCS7SignParameters_set_UseGeneralizedTimeFormat(_Handle, (int8_t)Value));
}

bool TElDCPKCS7SignParameters::get_ForceSigningCertificateV2Usage()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDCPKCS7SignParameters_get_ForceSigningCertificateV2Usage(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDCPKCS7SignParameters::set_ForceSigningCertificateV2Usage(bool Value)
{
	SBCheckError(TElDCPKCS7SignParameters_set_ForceSigningCertificateV2Usage(_Handle, (int8_t)Value));
}

bool TElDCPKCS7SignParameters::get_UseUndefSize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDCPKCS7SignParameters_get_UseUndefSize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDCPKCS7SignParameters::set_UseUndefSize(bool Value)
{
	SBCheckError(TElDCPKCS7SignParameters_set_UseUndefSize(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
TElPKCS7Attributes* TElDCPKCS7SignParameters::get_CustomSignedAttributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDCPKCS7SignParameters_get_CustomSignedAttributes(_Handle, &hOutResult));
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
TElPKCS7Attributes* TElDCPKCS7SignParameters::get_CustomUnsignedAttributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDCPKCS7SignParameters_get_CustomUnsignedAttributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CustomUnsignedAttributes)
		this->_Inst_CustomUnsignedAttributes = new TElPKCS7Attributes(hOutResult, ohFalse);
	else
		this->_Inst_CustomUnsignedAttributes->updateHandle(hOutResult);
	return this->_Inst_CustomUnsignedAttributes;
}
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElDCPKCS7SignParameters::get_CustomOptions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDCPKCS7SignParameters_get_CustomOptions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CustomOptions)
		this->_Inst_CustomOptions = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_CustomOptions->updateHandle(hOutResult);
	return this->_Inst_CustomOptions;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

void TElDCPKCS7SignParameters::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	this->_Inst_CustomSignedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	this->_Inst_CustomUnsignedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_CustomOptions = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
}

TElDCPKCS7SignParameters::TElDCPKCS7SignParameters(TElDCPKCS7SignParametersHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElDCPKCS7SignParameters::TElDCPKCS7SignParameters() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDCPKCS7SignParameters_Create(&_Handle));
}

TElDCPKCS7SignParameters::~TElDCPKCS7SignParameters()
{
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	delete this->_Inst_CustomSignedAttributes;
	this->_Inst_CustomSignedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	delete this->_Inst_CustomUnsignedAttributes;
	this->_Inst_CustomUnsignedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_CustomOptions;
	this->_Inst_CustomOptions = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
}
#endif /* SB_USE_CLASS_TELDCPKCS7SIGNPARAMETERS */

#ifdef SB_USE_CLASS_TELDCDEFAULTREQUESTFACTORY

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
SB_INLINE TElDCAsyncStateHandle TElDCDefaultRequestFactory::CreatePKCS1SignRequest(const std::string &OpName, const std::vector<uint8_t> &Source, int32_t HashAlgorithm, bool IncludeKeysInResponse)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElDCDefaultRequestFactory_CreatePKCS1SignRequest(_Handle, OpName.data(), (int32_t)OpName.length(), SB_STD_VECTOR_FRONT_ADR(Source), (int32_t)Source.size(), HashAlgorithm, (int8_t)IncludeKeysInResponse, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELDCPKCS7SIGNPARAMETERS
SB_INLINE TElDCAsyncStateHandle TElDCDefaultRequestFactory::CreatePKCS7SignRequest(const std::string &OpName, const std::vector<uint8_t> &Source, int32_t HashAlgorithm, TElDCPKCS7SignParameters &Pars)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElDCDefaultRequestFactory_CreatePKCS7SignRequest(_Handle, OpName.data(), (int32_t)OpName.length(), SB_STD_VECTOR_FRONT_ADR(Source), (int32_t)Source.size(), HashAlgorithm, Pars.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElDCDefaultRequestFactory::CreatePKCS7SignRequest(const std::string &OpName, const std::vector<uint8_t> &Source, int32_t HashAlgorithm, TElDCPKCS7SignParameters *Pars)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElDCDefaultRequestFactory_CreatePKCS7SignRequest(_Handle, OpName.data(), (int32_t)OpName.length(), SB_STD_VECTOR_FRONT_ADR(Source), (int32_t)Source.size(), HashAlgorithm, (Pars != NULL) ? Pars->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELDCPKCS7SIGNPARAMETERS */

TElDCDefaultRequestFactory::TElDCDefaultRequestFactory(TElDCDefaultRequestFactoryHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElDCDefaultRequestFactory::TElDCDefaultRequestFactory() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDCDefaultRequestFactory_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDCDEFAULTREQUESTFACTORY */

#ifdef SB_USE_GLOBAL_PROCS_DCDEF

#ifdef SB_USE_CLASS_TELDCDEFAULTREQUESTFACTORY
SB_INLINE TElDCDefaultRequestFactoryHandle DefaultDCRequestFactory()
{
	TElDCDefaultRequestFactoryHandle OutResult;
	SBCheckError(SBDCDef_DefaultDCRequestFactory(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDCDEFAULTREQUESTFACTORY */

#endif /* SB_USE_GLOBAL_PROCS_DCDEF */

};	/* namespace SecureBlackbox */

