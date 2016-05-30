#include "sbcrlstorage.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELCUSTOMCRLSTORAGE

SB_INLINE void TElCustomCRLStorage::BeginRead()
{
	SBCheckError(TElCustomCRLStorage_BeginRead(_Handle));
}

SB_INLINE void TElCustomCRLStorage::EndRead()
{
	SBCheckError(TElCustomCRLStorage_EndRead(_Handle));
}

SB_INLINE void TElCustomCRLStorage::BeginWrite()
{
	SBCheckError(TElCustomCRLStorage_BeginWrite(_Handle));
}

SB_INLINE void TElCustomCRLStorage::EndWrite()
{
	SBCheckError(TElCustomCRLStorage_EndWrite(_Handle));
}

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
SB_INLINE int32_t TElCustomCRLStorage::Add(TElCertificateRevocationList &CRL)
{
	int32_t OutResult;
	SBCheckError(TElCustomCRLStorage_Add(_Handle, CRL.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCRLStorage::Add(TElCertificateRevocationList *CRL)
{
	int32_t OutResult;
	SBCheckError(TElCustomCRLStorage_Add(_Handle, (CRL != NULL) ? CRL->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

#ifdef SB_USE_CLASSES_TELDISTRIBUTIONPOINT_AND_TELX509CERTIFICATE_AND_TLIST
SB_INLINE void TElCustomCRLStorage::FindMatchingCRLs(TElX509Certificate &Certificate, TElDistributionPoint &DistributionPoint, TList &List)
{
	SBCheckError(TElCustomCRLStorage_FindMatchingCRLs(_Handle, Certificate.getHandle(), DistributionPoint.getHandle(), List.getHandle()));
}

SB_INLINE void TElCustomCRLStorage::FindMatchingCRLs(TElX509Certificate *Certificate, TElDistributionPoint *DistributionPoint, TList *List)
{
	SBCheckError(TElCustomCRLStorage_FindMatchingCRLs(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (DistributionPoint != NULL) ? DistributionPoint->getHandle() : SB_NULL_HANDLE, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDISTRIBUTIONPOINT_AND_TELX509CERTIFICATE_AND_TLIST */

SB_INLINE void TElCustomCRLStorage::Remove(int32_t Index)
{
	SBCheckError(TElCustomCRLStorage_Remove(_Handle, Index));
}

SB_INLINE void TElCustomCRLStorage::Clear()
{
	SBCheckError(TElCustomCRLStorage_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELCRLLOOKUP
SB_INLINE int32_t TElCustomCRLStorage::FindFirst(TElCRLLookup &Lookup)
{
	int32_t OutResult;
	SBCheckError(TElCustomCRLStorage_FindFirst(_Handle, Lookup.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCRLStorage::FindFirst(TElCRLLookup *Lookup)
{
	int32_t OutResult;
	SBCheckError(TElCustomCRLStorage_FindFirst(_Handle, (Lookup != NULL) ? Lookup->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCRLLOOKUP */

#ifdef SB_USE_CLASS_TELCRLLOOKUP
SB_INLINE int32_t TElCustomCRLStorage::FindNext(TElCRLLookup &Lookup)
{
	int32_t OutResult;
	SBCheckError(TElCustomCRLStorage_FindNext(_Handle, Lookup.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCRLStorage::FindNext(TElCRLLookup *Lookup)
{
	int32_t OutResult;
	SBCheckError(TElCustomCRLStorage_FindNext(_Handle, (Lookup != NULL) ? Lookup->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCRLLOOKUP */

SB_INLINE void TElCustomCRLStorage::ExportTo(TElCustomCRLStorage &Storage)
{
	SBCheckError(TElCustomCRLStorage_ExportTo(_Handle, Storage.getHandle()));
}

SB_INLINE void TElCustomCRLStorage::ExportTo(TElCustomCRLStorage *Storage)
{
	SBCheckError(TElCustomCRLStorage_ExportTo(_Handle, (Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
SB_INLINE int32_t TElCustomCRLStorage::IndexOf(TElCertificateRevocationList &Crl)
{
	int32_t OutResult;
	SBCheckError(TElCustomCRLStorage_IndexOf(_Handle, Crl.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCRLStorage::IndexOf(TElCertificateRevocationList *Crl)
{
	int32_t OutResult;
	SBCheckError(TElCustomCRLStorage_IndexOf(_Handle, (Crl != NULL) ? Crl->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
TElCertificateRevocationList* TElCustomCRLStorage::get_CRLs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomCRLStorage_get_CRLs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CRLs)
		this->_Inst_CRLs = new TElCertificateRevocationList(hOutResult, ohFalse);
	else
		this->_Inst_CRLs->updateHandle(hOutResult);
	return this->_Inst_CRLs;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

SB_INLINE int32_t TElCustomCRLStorage::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElCustomCRLStorage_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElCustomCRLStorage::initInstances()
{
#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
	this->_Inst_CRLs = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */
}

TElCustomCRLStorage::TElCustomCRLStorage(TElCustomCRLStorageHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElCustomCRLStorage::TElCustomCRLStorage(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomCRLStorage_Create(AOwner.getHandle(), &_Handle));
}

TElCustomCRLStorage::TElCustomCRLStorage(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomCRLStorage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElCustomCRLStorage::~TElCustomCRLStorage()
{
#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
	delete this->_Inst_CRLs;
	this->_Inst_CRLs = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */
}
#endif /* SB_USE_CLASS_TELCUSTOMCRLSTORAGE */

#ifdef SB_USE_CLASS_TELCRLLOOKUP

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElCRLLookup::get_IssuerRDN()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCRLLookup_get_IssuerRDN(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IssuerRDN)
		this->_Inst_IssuerRDN = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_IssuerRDN->updateHandle(hOutResult);
	return this->_Inst_IssuerRDN;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELGENERALNAME
TElGeneralName* TElCRLLookup::get_DistributionPoint()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCRLLookup_get_DistributionPoint(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DistributionPoint)
		this->_Inst_DistributionPoint = new TElGeneralName(hOutResult, ohFalse);
	else
		this->_Inst_DistributionPoint->updateHandle(hOutResult);
	return this->_Inst_DistributionPoint;
}
#endif /* SB_USE_CLASS_TELGENERALNAME */

void TElCRLLookup::get_Number(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCRLLookup_get_Number(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1298585639, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCRLLookup::set_Number(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCRLLookup_set_Number(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TSBCRLReasonFlags TElCRLLookup::get_Reasons()
{
	TSBCRLReasonFlagsRaw OutResultRaw = 0;
	SBCheckError(TElCRLLookup_get_Reasons(_Handle, &OutResultRaw));
	return (TSBCRLReasonFlags)OutResultRaw;
}

SB_INLINE void TElCRLLookup::set_Reasons(TSBCRLReasonFlags Value)
{
	SBCheckError(TElCRLLookup_set_Reasons(_Handle, (TSBCRLReasonFlagsRaw)Value));
}

void TElCRLLookup::get_AuthorityKeyIdentifier(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCRLLookup_get_AuthorityKeyIdentifier(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-441251292, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCRLLookup::set_AuthorityKeyIdentifier(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCRLLookup_set_AuthorityKeyIdentifier(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElCRLLookup::get_BaseCRLNumber(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCRLLookup_get_BaseCRLNumber(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1873745431, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCRLLookup::set_BaseCRLNumber(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCRLLookup_set_BaseCRLNumber(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TSBCRLLookupCriteria TElCRLLookup::get_Criteria()
{
	TSBCRLLookupCriteriaRaw OutResultRaw = 0;
	SBCheckError(TElCRLLookup_get_Criteria(_Handle, &OutResultRaw));
	return (TSBCRLLookupCriteria)OutResultRaw;
}

SB_INLINE void TElCRLLookup::set_Criteria(TSBCRLLookupCriteria Value)
{
	SBCheckError(TElCRLLookup_set_Criteria(_Handle, (TSBCRLLookupCriteriaRaw)Value));
}

TSBCRLLookupOptions TElCRLLookup::get_Options()
{
	TSBCRLLookupOptionsRaw OutResultRaw = 0;
	SBCheckError(TElCRLLookup_get_Options(_Handle, &OutResultRaw));
	return (TSBCRLLookupOptions)OutResultRaw;
}

SB_INLINE void TElCRLLookup::set_Options(TSBCRLLookupOptions Value)
{
	SBCheckError(TElCRLLookup_set_Options(_Handle, (TSBCRLLookupOptionsRaw)Value));
}

void TElCRLLookup::initInstances()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_IssuerRDN = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELGENERALNAME
	this->_Inst_DistributionPoint = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAME */
}

TElCRLLookup::TElCRLLookup(TElCRLLookupHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElCRLLookup::TElCRLLookup(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCRLLookup_Create(AOwner.getHandle(), &_Handle));
}

TElCRLLookup::TElCRLLookup(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCRLLookup_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElCRLLookup::~TElCRLLookup()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_IssuerRDN;
	this->_Inst_IssuerRDN = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELGENERALNAME
	delete this->_Inst_DistributionPoint;
	this->_Inst_DistributionPoint = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAME */
}
#endif /* SB_USE_CLASS_TELCRLLOOKUP */

#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE

SB_INLINE void TElMemoryCRLStorage::BeginRead()
{
	SBCheckError(TElMemoryCRLStorage_BeginRead(_Handle));
}

SB_INLINE void TElMemoryCRLStorage::EndRead()
{
	SBCheckError(TElMemoryCRLStorage_EndRead(_Handle));
}

SB_INLINE void TElMemoryCRLStorage::BeginWrite()
{
	SBCheckError(TElMemoryCRLStorage_BeginWrite(_Handle));
}

SB_INLINE void TElMemoryCRLStorage::EndWrite()
{
	SBCheckError(TElMemoryCRLStorage_EndWrite(_Handle));
}

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
SB_INLINE int32_t TElMemoryCRLStorage::Add(TElCertificateRevocationList &CRL)
{
	int32_t OutResult;
	SBCheckError(TElMemoryCRLStorage_Add(_Handle, CRL.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMemoryCRLStorage::Add(TElCertificateRevocationList *CRL)
{
	int32_t OutResult;
	SBCheckError(TElMemoryCRLStorage_Add(_Handle, (CRL != NULL) ? CRL->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

SB_INLINE void TElMemoryCRLStorage::Remove(int32_t Index)
{
	SBCheckError(TElMemoryCRLStorage_Remove(_Handle, Index));
}

SB_INLINE void TElMemoryCRLStorage::Clear()
{
	SBCheckError(TElMemoryCRLStorage_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
SB_INLINE int32_t TElMemoryCRLStorage::IndexOf(TElCertificateRevocationList &Crl)
{
	int32_t OutResult;
	SBCheckError(TElMemoryCRLStorage_IndexOf(_Handle, Crl.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMemoryCRLStorage::IndexOf(TElCertificateRevocationList *Crl)
{
	int32_t OutResult;
	SBCheckError(TElMemoryCRLStorage_IndexOf(_Handle, (Crl != NULL) ? Crl->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

TElMemoryCRLStorage::TElMemoryCRLStorage(TElMemoryCRLStorageHandle handle, TElOwnHandle ownHandle) : TElCustomCRLStorage(handle, ownHandle)
{
}

TElMemoryCRLStorage::TElMemoryCRLStorage(TComponent &AOwner) : TElCustomCRLStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMemoryCRLStorage_Create(AOwner.getHandle(), &_Handle));
}

TElMemoryCRLStorage::TElMemoryCRLStorage(TComponent *AOwner) : TElCustomCRLStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMemoryCRLStorage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */

#ifdef SB_USE_CLASS_TELCRLCACHESTORAGE

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
SB_INLINE int32_t TElCRLCacheStorage::Add(TElCertificateRevocationList &CRL)
{
	int32_t OutResult;
	SBCheckError(TElCRLCacheStorage_Add(_Handle, CRL.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCRLCacheStorage::Add(TElCertificateRevocationList *CRL)
{
	int32_t OutResult;
	SBCheckError(TElCRLCacheStorage_Add(_Handle, (CRL != NULL) ? CRL->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

bool TElCRLCacheStorage::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCRLCacheStorage_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCRLCacheStorage::set_Enabled(bool Value)
{
	SBCheckError(TElCRLCacheStorage_set_Enabled(_Handle, (int8_t)Value));
}

TElCRLCacheStorage::TElCRLCacheStorage(TElCRLCacheStorageHandle handle, TElOwnHandle ownHandle) : TElMemoryCRLStorage(handle, ownHandle)
{
}

TElCRLCacheStorage::TElCRLCacheStorage(TComponent &AOwner) : TElMemoryCRLStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCRLCacheStorage_Create(AOwner.getHandle(), &_Handle));
}

TElCRLCacheStorage::TElCRLCacheStorage(TComponent *AOwner) : TElMemoryCRLStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCRLCacheStorage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELCRLCACHESTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRLRETRIEVER

bool TElCustomCRLRetriever::Supports(TSBGeneralName NameType, const std::string &Location)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCRLRetriever_Supports(_Handle, (TSBGeneralNameRaw)NameType, Location.data(), (int32_t)Location.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASSES_TELCERTIFICATEREVOCATIONLIST_AND_TELX509CERTIFICATE
SB_INLINE TElCertificateRevocationListHandle TElCustomCRLRetriever::GetCRL(TElX509Certificate &ACertificate, TElX509Certificate &CACertificate, TSBGeneralName NameType, const std::string &Location)
{
	TElCertificateRevocationListHandle OutResult;
	SBCheckError(TElCustomCRLRetriever_GetCRL(_Handle, ACertificate.getHandle(), CACertificate.getHandle(), (TSBGeneralNameRaw)NameType, Location.data(), (int32_t)Location.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElCertificateRevocationListHandle TElCustomCRLRetriever::GetCRL(TElX509Certificate *ACertificate, TElX509Certificate *CACertificate, TSBGeneralName NameType, const std::string &Location)
{
	TElCertificateRevocationListHandle OutResult;
	SBCheckError(TElCustomCRLRetriever_GetCRL(_Handle, (ACertificate != NULL) ? ACertificate->getHandle() : SB_NULL_HANDLE, (CACertificate != NULL) ? CACertificate->getHandle() : SB_NULL_HANDLE, (TSBGeneralNameRaw)NameType, Location.data(), (int32_t)Location.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCERTIFICATEREVOCATIONLIST_AND_TELX509CERTIFICATE */

TElCustomCRLRetriever::TElCustomCRLRetriever(TElCustomCRLRetrieverHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElCustomCRLRetriever::TElCustomCRLRetriever(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomCRLRetriever_Create(AOwner.getHandle(), &_Handle));
}

TElCustomCRLRetriever::TElCustomCRLRetriever(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomCRLRetriever_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELCUSTOMCRLRETRIEVER */

#ifdef SB_USE_CLASS_TELCUSTOMCRLRETRIEVERFACTORY

bool TElCustomCRLRetrieverFactory::Supports(TSBGeneralName NameType, const std::string &Location)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCRLRetrieverFactory_Supports(_Handle, (TSBGeneralNameRaw)NameType, Location.data(), (int32_t)Location.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELCUSTOMCRLRETRIEVER
SB_INLINE TElCustomCRLRetrieverHandle TElCustomCRLRetrieverFactory::GetRetrieverInstance(TObject &Validator)
{
	TElCustomCRLRetrieverHandle OutResult;
	SBCheckError(TElCustomCRLRetrieverFactory_GetRetrieverInstance(_Handle, Validator.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCRLRetrieverHandle TElCustomCRLRetrieverFactory::GetRetrieverInstance(TObject *Validator)
{
	TElCustomCRLRetrieverHandle OutResult;
	SBCheckError(TElCustomCRLRetrieverFactory_GetRetrieverInstance(_Handle, (Validator != NULL) ? Validator->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRLRETRIEVER */

TElCustomCRLRetrieverFactory::TElCustomCRLRetrieverFactory(TElCustomCRLRetrieverFactoryHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElCustomCRLRetrieverFactory::TElCustomCRLRetrieverFactory() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomCRLRetrieverFactory_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCUSTOMCRLRETRIEVERFACTORY */

#ifdef SB_USE_CLASS_TELCRLMANAGER

SB_INLINE void TElCRLManager::PurgeExpiredCRLs()
{
	SBCheckError(TElCRLManager_PurgeExpiredCRLs(_Handle));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRLRETRIEVERFACTORY
SB_INLINE void TElCRLManager::RegisterCRLRetrieverFactory(TElCustomCRLRetrieverFactory &Factory)
{
	SBCheckError(TElCRLManager_RegisterCRLRetrieverFactory(_Handle, Factory.getHandle()));
}

SB_INLINE void TElCRLManager::RegisterCRLRetrieverFactory(TElCustomCRLRetrieverFactory *Factory)
{
	SBCheckError(TElCRLManager_RegisterCRLRetrieverFactory(_Handle, (Factory != NULL) ? Factory->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRLRETRIEVERFACTORY */

#ifdef SB_USE_CLASS_TELCUSTOMCRLRETRIEVERFACTORY
SB_INLINE void TElCRLManager::UnregisterCRLRetrieverFactory(TElCustomCRLRetrieverFactory &Factory)
{
	SBCheckError(TElCRLManager_UnregisterCRLRetrieverFactory(_Handle, Factory.getHandle()));
}

SB_INLINE void TElCRLManager::UnregisterCRLRetrieverFactory(TElCustomCRLRetrieverFactory *Factory)
{
	SBCheckError(TElCRLManager_UnregisterCRLRetrieverFactory(_Handle, (Factory != NULL) ? Factory->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRLRETRIEVERFACTORY */

#ifdef SB_USE_CLASS_TELCUSTOMCRLRETRIEVER
SB_INLINE TElCustomCRLRetrieverHandle TElCRLManager::FindCRLRetriever(TSBGeneralName NameType, const std::string &Location, TObject &Validator)
{
	TElCustomCRLRetrieverHandle OutResult;
	SBCheckError(TElCRLManager_FindCRLRetriever(_Handle, (TSBGeneralNameRaw)NameType, Location.data(), (int32_t)Location.length(), Validator.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCRLRetrieverHandle TElCRLManager::FindCRLRetriever(TSBGeneralName NameType, const std::string &Location, TObject *Validator)
{
	TElCustomCRLRetrieverHandle OutResult;
	SBCheckError(TElCRLManager_FindCRLRetriever(_Handle, (TSBGeneralNameRaw)NameType, Location.data(), (int32_t)Location.length(), (Validator != NULL) ? Validator->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRLRETRIEVER */

#ifdef SB_USE_CLASS_TELCRLCACHESTORAGE
TElCRLCacheStorage* TElCRLManager::get_CRLCache()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCRLManager_get_CRLCache(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CRLCache)
		this->_Inst_CRLCache = new TElCRLCacheStorage(hOutResult, ohFalse);
	else
		this->_Inst_CRLCache->updateHandle(hOutResult);
	return this->_Inst_CRLCache;
}
#endif /* SB_USE_CLASS_TELCRLCACHESTORAGE */

bool TElCRLManager::get_UseCache()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCRLManager_get_UseCache(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCRLManager::set_UseCache(bool Value)
{
	SBCheckError(TElCRLManager_set_UseCache(_Handle, (int8_t)Value));
}

void TElCRLManager::initInstances()
{
#ifdef SB_USE_CLASS_TELCRLCACHESTORAGE
	this->_Inst_CRLCache = NULL;
#endif /* SB_USE_CLASS_TELCRLCACHESTORAGE */
}

TElCRLManager::TElCRLManager(TElCRLManagerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCRLManager::TElCRLManager() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCRLManager_Create(&_Handle));
}

TElCRLManager::~TElCRLManager()
{
#ifdef SB_USE_CLASS_TELCRLCACHESTORAGE
	delete this->_Inst_CRLCache;
	this->_Inst_CRLCache = NULL;
#endif /* SB_USE_CLASS_TELCRLCACHESTORAGE */
}
#endif /* SB_USE_CLASS_TELCRLMANAGER */

#ifdef SB_USE_GLOBAL_PROCS_CRLSTORAGE

#ifdef SB_USE_CLASS_TELCRLMANAGER
SB_INLINE TElCRLManagerHandle CRLManagerAddRef()
{
	TElCRLManagerHandle OutResult;
	SBCheckError(SBCRLStorage_CRLManagerAddRef(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCRLMANAGER */

SB_INLINE void CRLManagerRelease()
{
	SBCheckError(SBCRLStorage_CRLManagerRelease());
}

#endif /* SB_USE_GLOBAL_PROCS_CRLSTORAGE */

};	/* namespace SecureBlackbox */

