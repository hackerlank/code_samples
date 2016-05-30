#include "sbldapcertstorage.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELLDAPCERTSTORAGE

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TSBCertificateValidity TElLDAPCertStorage::Validate(TElX509Certificate &Certificate, TSBCertificateValidityReason &Reason, bool CheckCACertDates, int64_t ValidityMoment)
{
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	TSBCertificateValidityRaw OutResultRaw = 0;
	SBCheckError(TElLDAPCertStorage_Validate(_Handle, Certificate.getHandle(), &ReasonRaw, (int8_t)CheckCACertDates, ValidityMoment, &OutResultRaw));
	Reason = (TSBCertificateValidityReason)ReasonRaw;
	return (TSBCertificateValidity)OutResultRaw;
}

TSBCertificateValidity TElLDAPCertStorage::Validate(TElX509Certificate *Certificate, TSBCertificateValidityReason &Reason, bool CheckCACertDates, int64_t ValidityMoment)
{
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	TSBCertificateValidityRaw OutResultRaw = 0;
	SBCheckError(TElLDAPCertStorage_Validate(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &ReasonRaw, (int8_t)CheckCACertDates, ValidityMoment, &OutResultRaw));
	Reason = (TSBCertificateValidityReason)ReasonRaw;
	return (TSBCertificateValidity)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElLDAPCertStorage::Add(TElX509Certificate &X509Certificate, bool CopyPrivateKey)
{
	SBCheckError(TElLDAPCertStorage_Add(_Handle, X509Certificate.getHandle(), (int8_t)CopyPrivateKey));
}

SB_INLINE void TElLDAPCertStorage::Add(TElX509Certificate *X509Certificate, bool CopyPrivateKey)
{
	SBCheckError(TElLDAPCertStorage_Add(_Handle, (X509Certificate != NULL) ? X509Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)CopyPrivateKey));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE void TElLDAPCertStorage::Remove(int32_t Index)
{
	SBCheckError(TElLDAPCertStorage_Remove(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELLDAPSCLIENT
TElLDAPSClient* TElLDAPCertStorage::get_LDAPSClient()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElLDAPCertStorage_get_LDAPSClient(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_LDAPSClient)
		this->_Inst_LDAPSClient = new TElLDAPSClient(hOutResult, ohFalse);
	else
		this->_Inst_LDAPSClient->updateHandle(hOutResult);
	return this->_Inst_LDAPSClient;
}

SB_INLINE void TElLDAPCertStorage::set_LDAPSClient(TElLDAPSClient &Value)
{
	SBCheckError(TElLDAPCertStorage_set_LDAPSClient(_Handle, Value.getHandle()));
}

SB_INLINE void TElLDAPCertStorage::set_LDAPSClient(TElLDAPSClient *Value)
{
	SBCheckError(TElLDAPCertStorage_set_LDAPSClient(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELLDAPSCLIENT */

void TElLDAPCertStorage::initInstances()
{
#ifdef SB_USE_CLASS_TELLDAPSCLIENT
	this->_Inst_LDAPSClient = NULL;
#endif /* SB_USE_CLASS_TELLDAPSCLIENT */
}

TElLDAPCertStorage::TElLDAPCertStorage(TElLDAPCertStorageHandle handle, TElOwnHandle ownHandle) : TElCustomCertStorage(handle, ownHandle)
{
	initInstances();
}

TElLDAPCertStorage::TElLDAPCertStorage(TComponent &Owner) : TElCustomCertStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElLDAPCertStorage_Create(Owner.getHandle(), &_Handle));
}

TElLDAPCertStorage::TElLDAPCertStorage(TComponent *Owner) : TElCustomCertStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElLDAPCertStorage_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElLDAPCertStorage::~TElLDAPCertStorage()
{
#ifdef SB_USE_CLASS_TELLDAPSCLIENT
	delete this->_Inst_LDAPSClient;
	this->_Inst_LDAPSClient = NULL;
#endif /* SB_USE_CLASS_TELLDAPSCLIENT */
}
#endif /* SB_USE_CLASS_TELLDAPCERTSTORAGE */

};	/* namespace SecureBlackbox */

