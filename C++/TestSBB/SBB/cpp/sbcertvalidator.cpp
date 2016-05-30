#include "sbcertvalidator.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATOR

#ifdef SB_WINDOWS
SB_INLINE void TElX509CertificateValidator::InitializeWinStorages()
#endif
#ifndef SB_NOT_MACOS_OR_IOS
SB_INLINE void TElX509CertificateValidator::InitializeAppleStorages()
#endif
#ifndef SB_LINUX_OR_IOS
{
#ifndef MACOS
	SBCheckError(TElX509CertificateValidator_InitializeWinStorages(_Handle));
#else
	SBCheckError(TElX509CertificateValidator_InitializeAppleStorages(_Handle));
#endif
}
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE
void TElX509CertificateValidator::Validate(TElX509Certificate &Certificate, TElCustomCertStorage &AdditionalCertificates, bool CompleteChainValidation, int64_t ValidityMoment, TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason)
{
	TSBCertificateValidityRaw ValidityRaw = (TSBCertificateValidityRaw)Validity;
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	SBCheckError(TElX509CertificateValidator_Validate(_Handle, Certificate.getHandle(), AdditionalCertificates.getHandle(), (int8_t)CompleteChainValidation, ValidityMoment, &ValidityRaw, &ReasonRaw));
	Validity = (TSBCertificateValidity)ValidityRaw;
	Reason = (TSBCertificateValidityReason)ReasonRaw;
}

void TElX509CertificateValidator::Validate(TElX509Certificate *Certificate, TElCustomCertStorage *AdditionalCertificates, bool CompleteChainValidation, int64_t ValidityMoment, TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason)
{
	TSBCertificateValidityRaw ValidityRaw = (TSBCertificateValidityRaw)Validity;
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	SBCheckError(TElX509CertificateValidator_Validate(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (AdditionalCertificates != NULL) ? AdditionalCertificates->getHandle() : SB_NULL_HANDLE, (int8_t)CompleteChainValidation, ValidityMoment, &ValidityRaw, &ReasonRaw));
	Validity = (TSBCertificateValidity)ValidityRaw;
	Reason = (TSBCertificateValidityReason)ReasonRaw;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
void TElX509CertificateValidator::Validate(TElX509Certificate &Certificate, TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason)
{
	TSBCertificateValidityRaw ValidityRaw = (TSBCertificateValidityRaw)Validity;
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	SBCheckError(TElX509CertificateValidator_Validate_1(_Handle, Certificate.getHandle(), &ValidityRaw, &ReasonRaw));
	Validity = (TSBCertificateValidity)ValidityRaw;
	Reason = (TSBCertificateValidityReason)ReasonRaw;
}

void TElX509CertificateValidator::Validate(TElX509Certificate *Certificate, TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason)
{
	TSBCertificateValidityRaw ValidityRaw = (TSBCertificateValidityRaw)Validity;
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	SBCheckError(TElX509CertificateValidator_Validate_1(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &ValidityRaw, &ReasonRaw));
	Validity = (TSBCertificateValidity)ValidityRaw;
	Reason = (TSBCertificateValidityReason)ReasonRaw;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE
void TElX509CertificateValidator::ValidateForSMIME(TElX509Certificate &Certificate, const std::string &EMailAddress, TElCustomCertStorage &AdditionalCertificates, bool CompleteChainValidation, int64_t ValidityMoment, TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason)
{
	TSBCertificateValidityRaw ValidityRaw = (TSBCertificateValidityRaw)Validity;
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	SBCheckError(TElX509CertificateValidator_ValidateForSMIME(_Handle, Certificate.getHandle(), EMailAddress.data(), (int32_t)EMailAddress.length(), AdditionalCertificates.getHandle(), (int8_t)CompleteChainValidation, ValidityMoment, &ValidityRaw, &ReasonRaw));
	Validity = (TSBCertificateValidity)ValidityRaw;
	Reason = (TSBCertificateValidityReason)ReasonRaw;
}

void TElX509CertificateValidator::ValidateForSMIME(TElX509Certificate *Certificate, const std::string &EMailAddress, TElCustomCertStorage *AdditionalCertificates, bool CompleteChainValidation, int64_t ValidityMoment, TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason)
{
	TSBCertificateValidityRaw ValidityRaw = (TSBCertificateValidityRaw)Validity;
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	SBCheckError(TElX509CertificateValidator_ValidateForSMIME(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, EMailAddress.data(), (int32_t)EMailAddress.length(), (AdditionalCertificates != NULL) ? AdditionalCertificates->getHandle() : SB_NULL_HANDLE, (int8_t)CompleteChainValidation, ValidityMoment, &ValidityRaw, &ReasonRaw));
	Validity = (TSBCertificateValidity)ValidityRaw;
	Reason = (TSBCertificateValidityReason)ReasonRaw;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE
void TElX509CertificateValidator::ValidateForSSL(TElX509Certificate &Certificate, const std::string &DomainName, const std::string &IPAddress, TSBHostRole HostRole, TElCustomCertStorage &AdditionalCertificates, bool CompleteChainValidation, int64_t ValidityMoment, TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason)
{
	TSBCertificateValidityRaw ValidityRaw = (TSBCertificateValidityRaw)Validity;
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	SBCheckError(TElX509CertificateValidator_ValidateForSSL(_Handle, Certificate.getHandle(), DomainName.data(), (int32_t)DomainName.length(), IPAddress.data(), (int32_t)IPAddress.length(), (TSBHostRoleRaw)HostRole, AdditionalCertificates.getHandle(), (int8_t)CompleteChainValidation, ValidityMoment, &ValidityRaw, &ReasonRaw));
	Validity = (TSBCertificateValidity)ValidityRaw;
	Reason = (TSBCertificateValidityReason)ReasonRaw;
}

void TElX509CertificateValidator::ValidateForSSL(TElX509Certificate *Certificate, const std::string &DomainName, const std::string &IPAddress, TSBHostRole HostRole, TElCustomCertStorage *AdditionalCertificates, bool CompleteChainValidation, int64_t ValidityMoment, TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason)
{
	TSBCertificateValidityRaw ValidityRaw = (TSBCertificateValidityRaw)Validity;
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	SBCheckError(TElX509CertificateValidator_ValidateForSSL(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, DomainName.data(), (int32_t)DomainName.length(), IPAddress.data(), (int32_t)IPAddress.length(), (TSBHostRoleRaw)HostRole, (AdditionalCertificates != NULL) ? AdditionalCertificates->getHandle() : SB_NULL_HANDLE, (int8_t)CompleteChainValidation, ValidityMoment, &ValidityRaw, &ReasonRaw));
	Validity = (TSBCertificateValidity)ValidityRaw;
	Reason = (TSBCertificateValidityReason)ReasonRaw;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE
void TElX509CertificateValidator::ValidateForSSL(TElX509Certificate &Certificate, const std::string &DomainName, const std::string &IPAddress, TSBHostRole HostRole, TElCustomCertStorage &AdditionalCertificates, bool CompleteChainValidation, int64_t ValidityMoment, bool InternalValidation, TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason)
{
	TSBCertificateValidityRaw ValidityRaw = (TSBCertificateValidityRaw)Validity;
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	SBCheckError(TElX509CertificateValidator_ValidateForSSL_1(_Handle, Certificate.getHandle(), DomainName.data(), (int32_t)DomainName.length(), IPAddress.data(), (int32_t)IPAddress.length(), (TSBHostRoleRaw)HostRole, AdditionalCertificates.getHandle(), (int8_t)CompleteChainValidation, ValidityMoment, (int8_t)InternalValidation, &ValidityRaw, &ReasonRaw));
	Validity = (TSBCertificateValidity)ValidityRaw;
	Reason = (TSBCertificateValidityReason)ReasonRaw;
}

void TElX509CertificateValidator::ValidateForSSL(TElX509Certificate *Certificate, const std::string &DomainName, const std::string &IPAddress, TSBHostRole HostRole, TElCustomCertStorage *AdditionalCertificates, bool CompleteChainValidation, int64_t ValidityMoment, bool InternalValidation, TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason)
{
	TSBCertificateValidityRaw ValidityRaw = (TSBCertificateValidityRaw)Validity;
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	SBCheckError(TElX509CertificateValidator_ValidateForSSL_1(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, DomainName.data(), (int32_t)DomainName.length(), IPAddress.data(), (int32_t)IPAddress.length(), (TSBHostRoleRaw)HostRole, (AdditionalCertificates != NULL) ? AdditionalCertificates->getHandle() : SB_NULL_HANDLE, (int8_t)CompleteChainValidation, ValidityMoment, (int8_t)InternalValidation, &ValidityRaw, &ReasonRaw));
	Validity = (TSBCertificateValidity)ValidityRaw;
	Reason = (TSBCertificateValidityReason)ReasonRaw;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE
void TElX509CertificateValidator::ValidateForTimestamping(TElX509Certificate &Certificate, TElCustomCertStorage &AdditionalCertificates, bool CompleteChainValidation, int64_t ValidityMoment, TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason)
{
	TSBCertificateValidityRaw ValidityRaw = (TSBCertificateValidityRaw)Validity;
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	SBCheckError(TElX509CertificateValidator_ValidateForTimestamping(_Handle, Certificate.getHandle(), AdditionalCertificates.getHandle(), (int8_t)CompleteChainValidation, ValidityMoment, &ValidityRaw, &ReasonRaw));
	Validity = (TSBCertificateValidity)ValidityRaw;
	Reason = (TSBCertificateValidityReason)ReasonRaw;
}

void TElX509CertificateValidator::ValidateForTimestamping(TElX509Certificate *Certificate, TElCustomCertStorage *AdditionalCertificates, bool CompleteChainValidation, int64_t ValidityMoment, TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason)
{
	TSBCertificateValidityRaw ValidityRaw = (TSBCertificateValidityRaw)Validity;
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	SBCheckError(TElX509CertificateValidator_ValidateForTimestamping(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (AdditionalCertificates != NULL) ? AdditionalCertificates->getHandle() : SB_NULL_HANDLE, (int8_t)CompleteChainValidation, ValidityMoment, &ValidityRaw, &ReasonRaw));
	Validity = (TSBCertificateValidity)ValidityRaw;
	Reason = (TSBCertificateValidityReason)ReasonRaw;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElX509CertificateValidator::AddTrustedCertificates(TElCustomCertStorage &Storage)
{
	SBCheckError(TElX509CertificateValidator_AddTrustedCertificates(_Handle, Storage.getHandle()));
}

SB_INLINE void TElX509CertificateValidator::AddTrustedCertificates(TElCustomCertStorage *Storage)
{
	SBCheckError(TElX509CertificateValidator_AddTrustedCertificates(_Handle, (Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

SB_INLINE void TElX509CertificateValidator::ClearTrustedCertificates()
{
	SBCheckError(TElX509CertificateValidator_ClearTrustedCertificates(_Handle));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElX509CertificateValidator::AddBlockedCertificates(TElCustomCertStorage &Storage)
{
	SBCheckError(TElX509CertificateValidator_AddBlockedCertificates(_Handle, Storage.getHandle()));
}

SB_INLINE void TElX509CertificateValidator::AddBlockedCertificates(TElCustomCertStorage *Storage)
{
	SBCheckError(TElX509CertificateValidator_AddBlockedCertificates(_Handle, (Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

SB_INLINE void TElX509CertificateValidator::ClearBlockedCertificates()
{
	SBCheckError(TElX509CertificateValidator_ClearBlockedCertificates(_Handle));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElX509CertificateValidator::AddKnownCertificates(TElCustomCertStorage &Storage)
{
	SBCheckError(TElX509CertificateValidator_AddKnownCertificates(_Handle, Storage.getHandle()));
}

SB_INLINE void TElX509CertificateValidator::AddKnownCertificates(TElCustomCertStorage *Storage)
{
	SBCheckError(TElX509CertificateValidator_AddKnownCertificates(_Handle, (Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

SB_INLINE void TElX509CertificateValidator::ClearKnownCertificates()
{
	SBCheckError(TElX509CertificateValidator_ClearKnownCertificates(_Handle));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRLSTORAGE
SB_INLINE void TElX509CertificateValidator::AddKnownCRLs(TElCustomCRLStorage &Storage)
{
	SBCheckError(TElX509CertificateValidator_AddKnownCRLs(_Handle, Storage.getHandle()));
}

SB_INLINE void TElX509CertificateValidator::AddKnownCRLs(TElCustomCRLStorage *Storage)
{
	SBCheckError(TElX509CertificateValidator_AddKnownCRLs(_Handle, (Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRLSTORAGE */

SB_INLINE void TElX509CertificateValidator::ClearKnownCRLs()
{
	SBCheckError(TElX509CertificateValidator_ClearKnownCRLs(_Handle));
}

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
SB_INLINE void TElX509CertificateValidator::AddKnownOCSPResponses(TElOCSPResponse &Response)
{
	SBCheckError(TElX509CertificateValidator_AddKnownOCSPResponses(_Handle, Response.getHandle()));
}

SB_INLINE void TElX509CertificateValidator::AddKnownOCSPResponses(TElOCSPResponse *Response)
{
	SBCheckError(TElX509CertificateValidator_AddKnownOCSPResponses(_Handle, (Response != NULL) ? Response->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

SB_INLINE void TElX509CertificateValidator::ClearKnownOCSPResponses()
{
	SBCheckError(TElX509CertificateValidator_ClearKnownOCSPResponses(_Handle));
}

SB_INLINE void TElX509CertificateValidator::ResetCertificateCache()
{
	SBCheckError(TElX509CertificateValidator_ResetCertificateCache());
}

SB_INLINE void TElX509CertificateValidator::ResetCertificateCache_Inst()
{
	SBCheckError(TElX509CertificateValidator_ResetCertificateCache_1(_Handle));
}

SB_INLINE void TElX509CertificateValidator::ClearOutdatedCacheRecords(int64_t ClearMoment, int32_t CacheValidityTime)
{
	SBCheckError(TElX509CertificateValidator_ClearOutdatedCacheRecords(ClearMoment, CacheValidityTime));
}

SB_INLINE void TElX509CertificateValidator::ClearOutdatedCacheRecords_Inst(int64_t ClearMoment, int32_t CacheValidityTime)
{
	SBCheckError(TElX509CertificateValidator_ClearOutdatedCacheRecords_1(_Handle, ClearMoment, CacheValidityTime));
}

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
TElMemoryCertStorage* TElX509CertificateValidator::get_UsedCertificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509CertificateValidator_get_UsedCertificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_UsedCertificates)
		this->_Inst_UsedCertificates = new TElMemoryCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_UsedCertificates->updateHandle(hOutResult);
	return this->_Inst_UsedCertificates;
}
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
TElMemoryCRLStorage* TElX509CertificateValidator::get_UsedCRLs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509CertificateValidator_get_UsedCRLs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_UsedCRLs)
		this->_Inst_UsedCRLs = new TElMemoryCRLStorage(hOutResult, ohFalse);
	else
		this->_Inst_UsedCRLs->updateHandle(hOutResult);
	return this->_Inst_UsedCRLs;
}
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */

#ifdef SB_USE_CLASS_TLIST
TList* TElX509CertificateValidator::get_UsedOCSPResponses()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509CertificateValidator_get_UsedOCSPResponses(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_UsedOCSPResponses)
		this->_Inst_UsedOCSPResponses = new TList(hOutResult, ohFalse);
	else
		this->_Inst_UsedOCSPResponses->updateHandle(hOutResult);
	return this->_Inst_UsedOCSPResponses;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TELWINCERTSTORAGE
TElWinCertStorage* TElX509CertificateValidator::get_WinStorageTrust()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509CertificateValidator_get_WinStorageTrust(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_WinStorageTrust)
		this->_Inst_WinStorageTrust = new TElWinCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_WinStorageTrust->updateHandle(hOutResult);
	return this->_Inst_WinStorageTrust;
}
#endif /* SB_USE_CLASS_TELWINCERTSTORAGE */
#else
#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATORLOGGER
TElX509CertificateValidatorLogger* TElX509CertificateValidator::get_Logger()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509CertificateValidator_get_Logger(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Logger)
		this->_Inst_Logger = new TElX509CertificateValidatorLogger(hOutResult, ohFalse);
	else
		this->_Inst_Logger->updateHandle(hOutResult);
	return this->_Inst_Logger;
}

SB_INLINE void TElX509CertificateValidator::set_Logger(TElX509CertificateValidatorLogger &Value)
{
	SBCheckError(TElX509CertificateValidator_set_Logger(_Handle, Value.getHandle()));
}

SB_INLINE void TElX509CertificateValidator::set_Logger(TElX509CertificateValidatorLogger *Value)
{
	SBCheckError(TElX509CertificateValidator_set_Logger(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATORLOGGER */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TELWINCERTSTORAGE
TElWinCertStorage* TElX509CertificateValidator::get_WinStorageCA()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509CertificateValidator_get_WinStorageCA(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_WinStorageCA)
		this->_Inst_WinStorageCA = new TElWinCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_WinStorageCA->updateHandle(hOutResult);
	return this->_Inst_WinStorageCA;
}
#endif /* SB_USE_CLASS_TELWINCERTSTORAGE */
#else

#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATORLOGGER
TElX509CertificateValidatorLogger* TElX509CertificateValidator::get_InternalLogger()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509CertificateValidator_get_InternalLogger(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_InternalLogger)
		this->_Inst_InternalLogger = new TElX509CertificateValidatorLogger(hOutResult, ohFalse);
	else
		this->_Inst_InternalLogger->updateHandle(hOutResult);
	return this->_Inst_InternalLogger;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATORLOGGER */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TELWINCERTSTORAGE
TElWinCertStorage* TElX509CertificateValidator::get_WinStorageBlocked()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509CertificateValidator_get_WinStorageBlocked(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_WinStorageBlocked)
		this->_Inst_WinStorageBlocked = new TElWinCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_WinStorageBlocked->updateHandle(hOutResult);
	return this->_Inst_WinStorageBlocked;
}
#endif /* SB_USE_CLASS_TELWINCERTSTORAGE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATORLOGGER
TElX509CertificateValidatorLogger* TElX509CertificateValidator::get_Logger()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509CertificateValidator_get_Logger(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Logger)
		this->_Inst_Logger = new TElX509CertificateValidatorLogger(hOutResult, ohFalse);
	else
		this->_Inst_Logger->updateHandle(hOutResult);
	return this->_Inst_Logger;
}

SB_INLINE void TElX509CertificateValidator::set_Logger(TElX509CertificateValidatorLogger &Value)
{
	SBCheckError(TElX509CertificateValidator_set_Logger(_Handle, Value.getHandle()));
}

SB_INLINE void TElX509CertificateValidator::set_Logger(TElX509CertificateValidatorLogger *Value)
{
	SBCheckError(TElX509CertificateValidator_set_Logger(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATORLOGGER */

#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATORLOGGER
TElX509CertificateValidatorLogger* TElX509CertificateValidator::get_InternalLogger()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509CertificateValidator_get_InternalLogger(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_InternalLogger)
		this->_Inst_InternalLogger = new TElX509CertificateValidatorLogger(hOutResult, ohFalse);
	else
		this->_Inst_InternalLogger->updateHandle(hOutResult);
	return this->_Inst_InternalLogger;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATORLOGGER */

#endif
#ifndef SB_NOT_MACOS_OR_IOS
#ifdef SB_USE_CLASS_TELAPPLECERTSTORAGE
TElAppleCertStorage* TElX509CertificateValidator::get_AppleStorageCA()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509CertificateValidator_get_AppleStorageCA(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AppleStorageCA)
		this->_Inst_AppleStorageCA = new TElAppleCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_AppleStorageCA->updateHandle(hOutResult);
	return this->_Inst_AppleStorageCA;
}
#endif /* SB_USE_CLASS_TELAPPLECERTSTORAGE */

#ifdef SB_USE_CLASS_TELAPPLECERTSTORAGE
TElAppleCertStorage* TElX509CertificateValidator::get_AppleStorageTrust()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509CertificateValidator_get_AppleStorageTrust(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AppleStorageTrust)
		this->_Inst_AppleStorageTrust = new TElAppleCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_AppleStorageTrust->updateHandle(hOutResult);
	return this->_Inst_AppleStorageTrust;
}
#endif /* SB_USE_CLASS_TELAPPLECERTSTORAGE */

#endif
#ifndef SB_LINUX_OR_IOS
bool TElX509CertificateValidator::get_IgnoreSystemTrust()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_IgnoreSystemTrust(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidator::set_IgnoreSystemTrust(bool Value)
{
	SBCheckError(TElX509CertificateValidator_set_IgnoreSystemTrust(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidator::get_UseSystemStorages()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_UseSystemStorages(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidator::set_UseSystemStorages(bool Value)
{
	SBCheckError(TElX509CertificateValidator_set_UseSystemStorages(_Handle, (int8_t)Value));
}
#endif

bool TElX509CertificateValidator::get_CheckCRL()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_CheckCRL(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidator::set_CheckCRL(bool Value)
{
	SBCheckError(TElX509CertificateValidator_set_CheckCRL(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidator::get_CheckOCSP()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_CheckOCSP(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidator::set_CheckOCSP(bool Value)
{
	SBCheckError(TElX509CertificateValidator_set_CheckOCSP(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidator::get_CheckValidityPeriodForTrusted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_CheckValidityPeriodForTrusted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidator::set_CheckValidityPeriodForTrusted(bool Value)
{
	SBCheckError(TElX509CertificateValidator_set_CheckValidityPeriodForTrusted(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidator::get_IgnoreCAKeyUsage()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_IgnoreCAKeyUsage(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidator::set_IgnoreCAKeyUsage(bool Value)
{
	SBCheckError(TElX509CertificateValidator_set_IgnoreCAKeyUsage(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidator::get_IgnoreRevocationKeyUsage()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_IgnoreRevocationKeyUsage(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidator::set_IgnoreRevocationKeyUsage(bool Value)
{
	SBCheckError(TElX509CertificateValidator_set_IgnoreRevocationKeyUsage(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidator::get_IgnoreSSLKeyUsage()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_IgnoreSSLKeyUsage(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidator::set_IgnoreSSLKeyUsage(bool Value)
{
	SBCheckError(TElX509CertificateValidator_set_IgnoreSSLKeyUsage(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidator::get_IgnoreBadOCSPChains()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_IgnoreBadOCSPChains(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidator::set_IgnoreBadOCSPChains(bool Value)
{
	SBCheckError(TElX509CertificateValidator_set_IgnoreBadOCSPChains(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidator::get_IgnoreCABasicConstraints()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_IgnoreCABasicConstraints(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidator::set_IgnoreCABasicConstraints(bool Value)
{
	SBCheckError(TElX509CertificateValidator_set_IgnoreCABasicConstraints(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidator::get_IgnoreCANameConstraints()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_IgnoreCANameConstraints(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidator::set_IgnoreCANameConstraints(bool Value)
{
	SBCheckError(TElX509CertificateValidator_set_IgnoreCANameConstraints(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidator::get_MandatoryCRLCheck()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_MandatoryCRLCheck(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidator::set_MandatoryCRLCheck(bool Value)
{
	SBCheckError(TElX509CertificateValidator_set_MandatoryCRLCheck(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidator::get_MandatoryOCSPCheck()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_MandatoryOCSPCheck(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidator::set_MandatoryOCSPCheck(bool Value)
{
	SBCheckError(TElX509CertificateValidator_set_MandatoryOCSPCheck(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidator::get_MandatoryRevocationCheck()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_MandatoryRevocationCheck(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidator::set_MandatoryRevocationCheck(bool Value)
{
	SBCheckError(TElX509CertificateValidator_set_MandatoryRevocationCheck(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidator::get_ValidateInvalidCertificates()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_ValidateInvalidCertificates(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidator::set_ValidateInvalidCertificates(bool Value)
{
	SBCheckError(TElX509CertificateValidator_set_ValidateInvalidCertificates(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidator::get_ForceCompleteChainValidationForTrusted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_ForceCompleteChainValidationForTrusted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidator::set_ForceCompleteChainValidationForTrusted(bool Value)
{
	SBCheckError(TElX509CertificateValidator_set_ForceCompleteChainValidationForTrusted(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidator::get_ForceRevocationCheckForRoot()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_ForceRevocationCheckForRoot(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidator::set_ForceRevocationCheckForRoot(bool Value)
{
	SBCheckError(TElX509CertificateValidator_set_ForceRevocationCheckForRoot(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidator::get_OfflineMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_OfflineMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidator::set_OfflineMode(bool Value)
{
	SBCheckError(TElX509CertificateValidator_set_OfflineMode(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElX509CertificateValidator::get_RevocationMomentGracePeriod()
{
	int32_t OutResult;
	SBCheckError(TElX509CertificateValidator_get_RevocationMomentGracePeriod(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElX509CertificateValidator::set_RevocationMomentGracePeriod(int32_t Value)
{
	SBCheckError(TElX509CertificateValidator_set_RevocationMomentGracePeriod(_Handle, Value));
}

bool TElX509CertificateValidator::get_ImplicitlyTrustSelfSignedCertificates()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_ImplicitlyTrustSelfSignedCertificates(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidator::set_ImplicitlyTrustSelfSignedCertificates(bool Value)
{
	SBCheckError(TElX509CertificateValidator_set_ImplicitlyTrustSelfSignedCertificates(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidator::get_PromoteLongOCSPResponses()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_PromoteLongOCSPResponses(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidator::set_PromoteLongOCSPResponses(bool Value)
{
	SBCheckError(TElX509CertificateValidator_set_PromoteLongOCSPResponses(_Handle, (int8_t)Value));
}

TSBX509RevocationCheckPreference TElX509CertificateValidator::get_RevocationCheckPreference()
{
	TSBX509RevocationCheckPreferenceRaw OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_RevocationCheckPreference(_Handle, &OutResultRaw));
	return (TSBX509RevocationCheckPreference)OutResultRaw;
}

SB_INLINE void TElX509CertificateValidator::set_RevocationCheckPreference(TSBX509RevocationCheckPreference Value)
{
	SBCheckError(TElX509CertificateValidator_set_RevocationCheckPreference(_Handle, (TSBX509RevocationCheckPreferenceRaw)Value));
}

bool TElX509CertificateValidator::get_LookupCRLByNameIfDPNotPresent()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_LookupCRLByNameIfDPNotPresent(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidator::set_LookupCRLByNameIfDPNotPresent(bool Value)
{
	SBCheckError(TElX509CertificateValidator_set_LookupCRLByNameIfDPNotPresent(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidator::get_SkipSubjectNameIfAltNameExists()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_SkipSubjectNameIfAltNameExists(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidator::set_SkipSubjectNameIfAltNameExists(bool Value)
{
	SBCheckError(TElX509CertificateValidator_set_SkipSubjectNameIfAltNameExists(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElX509CertificateValidator::get_CacheValidityTime()
{
	int32_t OutResult;
	SBCheckError(TElX509CertificateValidator_get_CacheValidityTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElX509CertificateValidator::set_CacheValidityTime(int32_t Value)
{
	SBCheckError(TElX509CertificateValidator_set_CacheValidityTime(_Handle, Value));
}

bool TElX509CertificateValidator::get_CacheValidationResults()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidator_get_CacheValidationResults(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidator::set_CacheValidationResults(bool Value)
{
	SBCheckError(TElX509CertificateValidator_set_CacheValidationResults(_Handle, (int8_t)Value));
}

SB_INLINE void TElX509CertificateValidator::get_OnCRLNeeded(TSBCRLNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElX509CertificateValidator_get_OnCRLNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElX509CertificateValidator::set_OnCRLNeeded(TSBCRLNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElX509CertificateValidator_set_OnCRLNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElX509CertificateValidator::get_OnCRLRetrieved(TSBCRLRetrievedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElX509CertificateValidator_get_OnCRLRetrieved(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElX509CertificateValidator::set_OnCRLRetrieved(TSBCRLRetrievedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElX509CertificateValidator_set_OnCRLRetrieved(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElX509CertificateValidator::get_OnBeforeCRLRetrieverUse(TSBBeforeCRLRetrieverUseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElX509CertificateValidator_get_OnBeforeCRLRetrieverUse(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElX509CertificateValidator::set_OnBeforeCRLRetrieverUse(TSBBeforeCRLRetrieverUseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElX509CertificateValidator_set_OnBeforeCRLRetrieverUse(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElX509CertificateValidator::get_OnBeforeCertificateRetrieverUse(TSBBeforeCertificateRetrieverUseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElX509CertificateValidator_get_OnBeforeCertificateRetrieverUse(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElX509CertificateValidator::set_OnBeforeCertificateRetrieverUse(TSBBeforeCertificateRetrieverUseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElX509CertificateValidator_set_OnBeforeCertificateRetrieverUse(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElX509CertificateValidator::get_OnCACertificateRetrieved(TSBCACertificateRetrievedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElX509CertificateValidator_get_OnCACertificateRetrieved(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElX509CertificateValidator::set_OnCACertificateRetrieved(TSBCACertificateRetrievedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElX509CertificateValidator_set_OnCACertificateRetrieved(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElX509CertificateValidator::get_OnBeforeOCSPClientUse(TSBBeforeOCSPClientUseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElX509CertificateValidator_get_OnBeforeOCSPClientUse(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElX509CertificateValidator::set_OnBeforeOCSPClientUse(TSBBeforeOCSPClientUseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElX509CertificateValidator_set_OnBeforeOCSPClientUse(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElX509CertificateValidator::get_OnBeforeCertificateValidation(TSBBeforeCertificateValidationEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElX509CertificateValidator_get_OnBeforeCertificateValidation(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElX509CertificateValidator::set_OnBeforeCertificateValidation(TSBBeforeCertificateValidationEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElX509CertificateValidator_set_OnBeforeCertificateValidation(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElX509CertificateValidator::get_OnAfterCertificateValidation(TSBAfterCertificateValidationEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElX509CertificateValidator_get_OnAfterCertificateValidation(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElX509CertificateValidator::set_OnAfterCertificateValidation(TSBAfterCertificateValidationEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElX509CertificateValidator_set_OnAfterCertificateValidation(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElX509CertificateValidator::get_OnCACertificateNeeded(TSBCACertificateNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElX509CertificateValidator_get_OnCACertificateNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElX509CertificateValidator::set_OnCACertificateNeeded(TSBCACertificateNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElX509CertificateValidator_set_OnCACertificateNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElX509CertificateValidator::get_OnAfterCRLUse(TSBAfterCRLUseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElX509CertificateValidator_get_OnAfterCRLUse(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElX509CertificateValidator::set_OnAfterCRLUse(TSBAfterCRLUseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElX509CertificateValidator_set_OnAfterCRLUse(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElX509CertificateValidator::get_OnAfterOCSPResponseUse(TSBAfterOCSPResponseUseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElX509CertificateValidator_get_OnAfterOCSPResponseUse(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElX509CertificateValidator::set_OnAfterOCSPResponseUse(TSBAfterOCSPResponseUseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElX509CertificateValidator_set_OnAfterOCSPResponseUse(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElX509CertificateValidator::get_OnOCSPResponseSignerValid(TSBOCSPResponseSignerValidEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElX509CertificateValidator_get_OnOCSPResponseSignerValid(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElX509CertificateValidator::set_OnOCSPResponseSignerValid(TSBOCSPResponseSignerValidEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElX509CertificateValidator_set_OnOCSPResponseSignerValid(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElX509CertificateValidator::get_OnCRLError(TSBCertificateValidatorCRLErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElX509CertificateValidator_get_OnCRLError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElX509CertificateValidator::set_OnCRLError(TSBCertificateValidatorCRLErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElX509CertificateValidator_set_OnCRLError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElX509CertificateValidator::get_OnOCSPError(TSBCertificateValidatorOCSPErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElX509CertificateValidator_get_OnOCSPError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElX509CertificateValidator::set_OnOCSPError(TSBCertificateValidatorOCSPErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElX509CertificateValidator_set_OnOCSPError(_Handle, pMethodValue, pDataValue));
}

void TElX509CertificateValidator::initInstances()
{
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	this->_Inst_UsedCertificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
	this->_Inst_UsedCRLs = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_UsedOCSPResponses = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TELWINCERTSTORAGE
	this->_Inst_WinStorageTrust = NULL;
#endif /* SB_USE_CLASS_TELWINCERTSTORAGE */
#ifdef SB_USE_CLASS_TELWINCERTSTORAGE
	this->_Inst_WinStorageCA = NULL;
#endif /* SB_USE_CLASS_TELWINCERTSTORAGE */
#ifdef SB_USE_CLASS_TELWINCERTSTORAGE
	this->_Inst_WinStorageBlocked = NULL;
#endif /* SB_USE_CLASS_TELWINCERTSTORAGE */
#endif
#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATORLOGGER
	this->_Inst_Logger = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATORLOGGER */
#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATORLOGGER
	this->_Inst_InternalLogger = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATORLOGGER */
#ifndef SB_NOT_MACOS_OR_IOS
#ifdef SB_USE_CLASS_TELAPPLECERTSTORAGE
	this->_Inst_AppleStorageCA = NULL;
#endif /* SB_USE_CLASS_TELAPPLECERTSTORAGE */
#ifdef SB_USE_CLASS_TELAPPLECERTSTORAGE
	this->_Inst_AppleStorageTrust = NULL;
#endif /* SB_USE_CLASS_TELAPPLECERTSTORAGE */
#endif
}

TElX509CertificateValidator::TElX509CertificateValidator(TElX509CertificateValidatorHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElX509CertificateValidator::TElX509CertificateValidator(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElX509CertificateValidator_Create(AOwner.getHandle(), &_Handle));
}

TElX509CertificateValidator::TElX509CertificateValidator(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElX509CertificateValidator_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElX509CertificateValidator::~TElX509CertificateValidator()
{
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	delete this->_Inst_UsedCertificates;
	this->_Inst_UsedCertificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
	delete this->_Inst_UsedCRLs;
	this->_Inst_UsedCRLs = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_UsedOCSPResponses;
	this->_Inst_UsedOCSPResponses = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TELWINCERTSTORAGE
	delete this->_Inst_WinStorageTrust;
	this->_Inst_WinStorageTrust = NULL;
#endif /* SB_USE_CLASS_TELWINCERTSTORAGE */
#ifdef SB_USE_CLASS_TELWINCERTSTORAGE
	delete this->_Inst_WinStorageCA;
	this->_Inst_WinStorageCA = NULL;
#endif /* SB_USE_CLASS_TELWINCERTSTORAGE */
#ifdef SB_USE_CLASS_TELWINCERTSTORAGE
	delete this->_Inst_WinStorageBlocked;
	this->_Inst_WinStorageBlocked = NULL;
#endif /* SB_USE_CLASS_TELWINCERTSTORAGE */
#endif
#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATORLOGGER
	delete this->_Inst_Logger;
	this->_Inst_Logger = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATORLOGGER */
#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATORLOGGER
	delete this->_Inst_InternalLogger;
	this->_Inst_InternalLogger = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATORLOGGER */
#ifndef SB_NOT_MACOS_OR_IOS
#ifdef SB_USE_CLASS_TELAPPLECERTSTORAGE
	delete this->_Inst_AppleStorageCA;
	this->_Inst_AppleStorageCA = NULL;
#endif /* SB_USE_CLASS_TELAPPLECERTSTORAGE */
#ifdef SB_USE_CLASS_TELAPPLECERTSTORAGE
	delete this->_Inst_AppleStorageTrust;
	this->_Inst_AppleStorageTrust = NULL;
#endif /* SB_USE_CLASS_TELAPPLECERTSTORAGE */
#endif
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATOR */

#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATORLOGGER

SB_INLINE void TElX509CertificateValidatorLogger::Reset()
{
	SBCheckError(TElX509CertificateValidatorLogger_Reset(_Handle));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElX509CertificateValidatorLogger::get_Log()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509CertificateValidatorLogger_get_Log(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Log)
		this->_Inst_Log = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Log->updateHandle(hOutResult);
	return this->_Inst_Log;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElX509CertificateValidatorLogger::get_Log()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509CertificateValidatorLogger_get_Log(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Log)
		this->_Inst_Log = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Log->updateHandle(hOutResult);
	return this->_Inst_Log;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElX509CertificateValidatorLogger::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Log = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Log = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElX509CertificateValidatorLogger::TElX509CertificateValidatorLogger(TElX509CertificateValidatorLoggerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElX509CertificateValidatorLogger::TElX509CertificateValidatorLogger() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElX509CertificateValidatorLogger_Create(&_Handle));
}

TElX509CertificateValidatorLogger::~TElX509CertificateValidatorLogger()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Log;
	this->_Inst_Log = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Log;
	this->_Inst_Log = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATORLOGGER */

#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATIONRESULT

bool TElX509CertificateValidationResult::EqualParams(TElX509CertificateValidationResult &Value)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_EqualParams(_Handle, Value.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElX509CertificateValidationResult::EqualParams(TElX509CertificateValidationResult *Value)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_EqualParams(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int64_t TElX509CertificateValidationResult::get_LastValidatedTime()
{
	int64_t OutResult;
	SBCheckError(TElX509CertificateValidationResult_get_LastValidatedTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElX509CertificateValidationResult::set_LastValidatedTime(int64_t Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_LastValidatedTime(_Handle, Value));
}

TSBCertificateValidity TElX509CertificateValidationResult::get_Validity()
{
	TSBCertificateValidityRaw OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_Validity(_Handle, &OutResultRaw));
	return (TSBCertificateValidity)OutResultRaw;
}

SB_INLINE void TElX509CertificateValidationResult::set_Validity(TSBCertificateValidity Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_Validity(_Handle, (TSBCertificateValidityRaw)Value));
}

TSBCertificateValidityReason TElX509CertificateValidationResult::get_Reason()
{
	TSBCertificateValidityReasonRaw OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_Reason(_Handle, &OutResultRaw));
	return (TSBCertificateValidityReason)OutResultRaw;
}

SB_INLINE void TElX509CertificateValidationResult::set_Reason(TSBCertificateValidityReason Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_Reason(_Handle, (TSBCertificateValidityReasonRaw)Value));
#ifndef SB_LINUX_OR_IOS
}

bool TElX509CertificateValidationResult::get_IgnoreSystemTrust()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_IgnoreSystemTrust(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidationResult::set_IgnoreSystemTrust(bool Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_IgnoreSystemTrust(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidationResult::get_UseSystemStorages()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_UseSystemStorages(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidationResult::set_UseSystemStorages(bool Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_UseSystemStorages(_Handle, (int8_t)Value));
#endif
}

bool TElX509CertificateValidationResult::get_CheckCRL()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_CheckCRL(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidationResult::set_CheckCRL(bool Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_CheckCRL(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidationResult::get_CheckOCSP()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_CheckOCSP(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidationResult::set_CheckOCSP(bool Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_CheckOCSP(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidationResult::get_CheckValidityPeriodForTrusted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_CheckValidityPeriodForTrusted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidationResult::set_CheckValidityPeriodForTrusted(bool Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_CheckValidityPeriodForTrusted(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidationResult::get_IgnoreCAKeyUsage()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_IgnoreCAKeyUsage(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidationResult::set_IgnoreCAKeyUsage(bool Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_IgnoreCAKeyUsage(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidationResult::get_IgnoreRevocationKeyUsage()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_IgnoreRevocationKeyUsage(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidationResult::set_IgnoreRevocationKeyUsage(bool Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_IgnoreRevocationKeyUsage(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidationResult::get_IgnoreSSLKeyUsage()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_IgnoreSSLKeyUsage(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidationResult::set_IgnoreSSLKeyUsage(bool Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_IgnoreSSLKeyUsage(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidationResult::get_IgnoreBadOCSPChains()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_IgnoreBadOCSPChains(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidationResult::set_IgnoreBadOCSPChains(bool Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_IgnoreBadOCSPChains(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidationResult::get_IgnoreCABasicConstraints()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_IgnoreCABasicConstraints(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidationResult::set_IgnoreCABasicConstraints(bool Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_IgnoreCABasicConstraints(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidationResult::get_IgnoreCANameConstraints()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_IgnoreCANameConstraints(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidationResult::set_IgnoreCANameConstraints(bool Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_IgnoreCANameConstraints(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidationResult::get_MandatoryCRLCheck()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_MandatoryCRLCheck(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidationResult::set_MandatoryCRLCheck(bool Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_MandatoryCRLCheck(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidationResult::get_MandatoryOCSPCheck()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_MandatoryOCSPCheck(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidationResult::set_MandatoryOCSPCheck(bool Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_MandatoryOCSPCheck(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidationResult::get_MandatoryRevocationCheck()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_MandatoryRevocationCheck(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidationResult::set_MandatoryRevocationCheck(bool Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_MandatoryRevocationCheck(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidationResult::get_ValidateInvalidCertificates()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_ValidateInvalidCertificates(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidationResult::set_ValidateInvalidCertificates(bool Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_ValidateInvalidCertificates(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidationResult::get_ForceCompleteChainValidationForTrusted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_ForceCompleteChainValidationForTrusted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidationResult::set_ForceCompleteChainValidationForTrusted(bool Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_ForceCompleteChainValidationForTrusted(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidationResult::get_ForceRevocationCheckForRoot()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_ForceRevocationCheckForRoot(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidationResult::set_ForceRevocationCheckForRoot(bool Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_ForceRevocationCheckForRoot(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidationResult::get_OfflineMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_OfflineMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidationResult::set_OfflineMode(bool Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_OfflineMode(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElX509CertificateValidationResult::get_RevocationMomentGracePeriod()
{
	int32_t OutResult;
	SBCheckError(TElX509CertificateValidationResult_get_RevocationMomentGracePeriod(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElX509CertificateValidationResult::set_RevocationMomentGracePeriod(int32_t Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_RevocationMomentGracePeriod(_Handle, Value));
}

bool TElX509CertificateValidationResult::get_ImplicitlyTrustSelfSignedCertificates()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_ImplicitlyTrustSelfSignedCertificates(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidationResult::set_ImplicitlyTrustSelfSignedCertificates(bool Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_ImplicitlyTrustSelfSignedCertificates(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidationResult::get_PromoteLongOCSPResponses()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_PromoteLongOCSPResponses(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidationResult::set_PromoteLongOCSPResponses(bool Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_PromoteLongOCSPResponses(_Handle, (int8_t)Value));
}

TSBX509RevocationCheckPreference TElX509CertificateValidationResult::get_RevocationCheckPreference()
{
	TSBX509RevocationCheckPreferenceRaw OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_RevocationCheckPreference(_Handle, &OutResultRaw));
	return (TSBX509RevocationCheckPreference)OutResultRaw;
}

SB_INLINE void TElX509CertificateValidationResult::set_RevocationCheckPreference(TSBX509RevocationCheckPreference Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_RevocationCheckPreference(_Handle, (TSBX509RevocationCheckPreferenceRaw)Value));
}

bool TElX509CertificateValidationResult::get_LookupCRLByNameIfDPNotPresent()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_LookupCRLByNameIfDPNotPresent(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidationResult::set_LookupCRLByNameIfDPNotPresent(bool Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_LookupCRLByNameIfDPNotPresent(_Handle, (int8_t)Value));
}

bool TElX509CertificateValidationResult::get_SkipSubjectNameIfAltNameExists()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateValidationResult_get_SkipSubjectNameIfAltNameExists(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateValidationResult::set_SkipSubjectNameIfAltNameExists(bool Value)
{
	SBCheckError(TElX509CertificateValidationResult_set_SkipSubjectNameIfAltNameExists(_Handle, (int8_t)Value));
}

TElX509CertificateValidationResult::TElX509CertificateValidationResult(TElX509CertificateValidationResultHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATOR
TElX509CertificateValidationResult::TElX509CertificateValidationResult(TElX509CertificateValidator &Validator) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElX509CertificateValidationResult_Create(Validator.getHandle(), &_Handle));
}

TElX509CertificateValidationResult::TElX509CertificateValidationResult(TElX509CertificateValidator *Validator) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElX509CertificateValidationResult_Create((Validator != NULL) ? Validator->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATOR */

#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATIONRESULT */

#ifdef SB_USE_CLASS_TELX509CACHEDCERTIFICATE

#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATIONRESULT
SB_INLINE int32_t TElX509CachedCertificate::AddValidationResult(TElX509CertificateValidationResult &Res)
{
	int32_t OutResult;
	SBCheckError(TElX509CachedCertificate_AddValidationResult(_Handle, Res.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElX509CachedCertificate::AddValidationResult(TElX509CertificateValidationResult *Res)
{
	int32_t OutResult;
	SBCheckError(TElX509CachedCertificate_AddValidationResult(_Handle, (Res != NULL) ? Res->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATIONRESULT */

SB_INLINE void TElX509CachedCertificate::RemoveValidationResult(int32_t Index)
{
	SBCheckError(TElX509CachedCertificate_RemoveValidationResult(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATIONRESULT
SB_INLINE TElX509CertificateValidationResultHandle TElX509CachedCertificate::FindResultByValidityMoment(int64_t ValidityMoment, int32_t CacheValidityTime)
{
	TElX509CertificateValidationResultHandle OutResult;
	SBCheckError(TElX509CachedCertificate_FindResultByValidityMoment(_Handle, ValidityMoment, CacheValidityTime, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATIONRESULT */

bool TElX509CachedCertificate::IsRevoked(int64_t ValidityMoment)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CachedCertificate_IsRevoked(_Handle, ValidityMoment, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElX509CachedCertificate::IsPermanentlyInvalid()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CachedCertificate_IsPermanentlyInvalid(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TClassHandle TElX509CachedCertificate::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElX509CachedCertificate_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATIONRESULT
TElX509CertificateValidationResult* TElX509CachedCertificate::get_ValidationResults(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElX509CachedCertificate_get_ValidationResults(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ValidationResults)
		this->_Inst_ValidationResults = new TElX509CertificateValidationResult(hOutResult, ohFalse);
	else
		this->_Inst_ValidationResults->updateHandle(hOutResult);
	return this->_Inst_ValidationResults;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATIONRESULT */

SB_INLINE int32_t TElX509CachedCertificate::get_ValidationResultCount()
{
	int32_t OutResult;
	SBCheckError(TElX509CachedCertificate_get_ValidationResultCount(_Handle, &OutResult));
	return OutResult;
}

void TElX509CachedCertificate::initInstances()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATIONRESULT
	this->_Inst_ValidationResults = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATIONRESULT */
}

TElX509CachedCertificate::TElX509CachedCertificate(TElX509CachedCertificateHandle handle, TElOwnHandle ownHandle) : TElX509Certificate(handle, ownHandle)
{
	initInstances();
}

TElX509CachedCertificate::TElX509CachedCertificate(TComponent &AOwner) : TElX509Certificate(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElX509CachedCertificate_Create(AOwner.getHandle(), &_Handle));
}

TElX509CachedCertificate::TElX509CachedCertificate(TComponent *AOwner) : TElX509Certificate(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElX509CachedCertificate_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElX509CachedCertificate::~TElX509CachedCertificate()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATIONRESULT
	delete this->_Inst_ValidationResults;
	this->_Inst_ValidationResults = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATIONRESULT */
}
#endif /* SB_USE_CLASS_TELX509CACHEDCERTIFICATE */

#ifdef SB_USE_CLASS_TELCACHECERTSTORAGE

SB_INLINE void TElCacheCertStorage::BeginWrite()
{
	SBCheckError(TElCacheCertStorage_BeginWrite(_Handle));
}

SB_INLINE void TElCacheCertStorage::EndWrite()
{
	SBCheckError(TElCacheCertStorage_EndWrite(_Handle));
}

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELX509CERTIFICATEVALIDATOR
SB_INLINE void TElCacheCertStorage::Add(TElX509Certificate &X509Certificate, int64_t ValidityMoment, TSBCertificateValidity Validity, TSBCertificateValidityReason Reason, TElX509CertificateValidator &Validator)
{
	SBCheckError(TElCacheCertStorage_Add(_Handle, X509Certificate.getHandle(), ValidityMoment, (TSBCertificateValidityRaw)Validity, (TSBCertificateValidityReasonRaw)Reason, Validator.getHandle()));
}

SB_INLINE void TElCacheCertStorage::Add(TElX509Certificate *X509Certificate, int64_t ValidityMoment, TSBCertificateValidity Validity, TSBCertificateValidityReason Reason, TElX509CertificateValidator *Validator)
{
	SBCheckError(TElCacheCertStorage_Add(_Handle, (X509Certificate != NULL) ? X509Certificate->getHandle() : SB_NULL_HANDLE, ValidityMoment, (TSBCertificateValidityRaw)Validity, (TSBCertificateValidityReasonRaw)Reason, (Validator != NULL) ? Validator->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELX509CERTIFICATEVALIDATOR */

TElCacheCertStorage::TElCacheCertStorage(TElCacheCertStorageHandle handle, TElOwnHandle ownHandle) : TElMemoryCertStorage(handle, ownHandle)
{
}

TElCacheCertStorage::TElCacheCertStorage(TComponent &Owner) : TElMemoryCertStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCacheCertStorage_Create(Owner.getHandle(), &_Handle));
}

TElCacheCertStorage::TElCacheCertStorage(TComponent *Owner) : TElMemoryCertStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCacheCertStorage_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELCACHECERTSTORAGE */

#ifdef SB_USE_GLOBAL_PROCS_CERTVALIDATOR

#ifdef SB_USE_CLASS_TELCACHECERTSTORAGE
SB_INLINE TElCacheCertStorageHandle GetCertificateCache()
{
	TElCacheCertStorageHandle OutResult;
	SBCheckError(SBCertValidator_GetCertificateCache(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCACHECERTSTORAGE */

#endif /* SB_USE_GLOBAL_PROCS_CERTVALIDATOR */

};	/* namespace SecureBlackbox */
