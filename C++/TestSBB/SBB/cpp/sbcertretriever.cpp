#include "sbcertretriever.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVER

bool TElCustomCertificateRetriever::SupportsLocation(TSBGeneralName NameType, const std::string &URI)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertificateRetriever_SupportsLocation(_Handle, (TSBGeneralNameRaw)NameType, URI.data(), (int32_t)URI.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE TElX509CertificateHandle TElCustomCertificateRetriever::RetrieveCertificate(TElX509Certificate &Certificate, TSBGeneralName NameType, const std::string &URL)
{
	TElX509CertificateHandle OutResult;
	SBCheckError(TElCustomCertificateRetriever_RetrieveCertificate(_Handle, Certificate.getHandle(), (TSBGeneralNameRaw)NameType, URL.data(), (int32_t)URL.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElX509CertificateHandle TElCustomCertificateRetriever::RetrieveCertificate(TElX509Certificate *Certificate, TSBGeneralName NameType, const std::string &URL)
{
	TElX509CertificateHandle OutResult;
	SBCheckError(TElCustomCertificateRetriever_RetrieveCertificate(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (TSBGeneralNameRaw)NameType, URL.data(), (int32_t)URL.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

TElCustomCertificateRetriever::TElCustomCertificateRetriever(TElCustomCertificateRetrieverHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElCustomCertificateRetriever::TElCustomCertificateRetriever(TComponent &Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomCertificateRetriever_Create(Owner.getHandle(), &_Handle));
}

TElCustomCertificateRetriever::TElCustomCertificateRetriever(TComponent *Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomCertificateRetriever_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVER */

#ifdef SB_USE_CLASS_TELFILECERTIFICATERETRIEVER

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE TElX509CertificateHandle TElFileCertificateRetriever::RetrieveCertificate(TElX509Certificate &Certificate, TSBGeneralName NameType, const std::string &URL)
{
	TElX509CertificateHandle OutResult;
	SBCheckError(TElFileCertificateRetriever_RetrieveCertificate(_Handle, Certificate.getHandle(), (TSBGeneralNameRaw)NameType, URL.data(), (int32_t)URL.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElX509CertificateHandle TElFileCertificateRetriever::RetrieveCertificate(TElX509Certificate *Certificate, TSBGeneralName NameType, const std::string &URL)
{
	TElX509CertificateHandle OutResult;
	SBCheckError(TElFileCertificateRetriever_RetrieveCertificate(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (TSBGeneralNameRaw)NameType, URL.data(), (int32_t)URL.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

bool TElFileCertificateRetriever::SupportsLocation(TSBGeneralName NameType, const std::string &URI)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFileCertificateRetriever_SupportsLocation(_Handle, (TSBGeneralNameRaw)NameType, URI.data(), (int32_t)URI.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElFileCertificateRetriever::get_OnCertificateNeeded(TSBCertificateRetrievalEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFileCertificateRetriever_get_OnCertificateNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFileCertificateRetriever::set_OnCertificateNeeded(TSBCertificateRetrievalEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFileCertificateRetriever_set_OnCertificateNeeded(_Handle, pMethodValue, pDataValue));
}

TElFileCertificateRetriever::TElFileCertificateRetriever(TElFileCertificateRetrieverHandle handle, TElOwnHandle ownHandle) : TElCustomCertificateRetriever(handle, ownHandle)
{
}

TElFileCertificateRetriever::TElFileCertificateRetriever(TComponent &Owner) : TElCustomCertificateRetriever(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFileCertificateRetriever_Create(Owner.getHandle(), &_Handle));
}

TElFileCertificateRetriever::TElFileCertificateRetriever(TComponent *Owner) : TElCustomCertificateRetriever(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFileCertificateRetriever_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELFILECERTIFICATERETRIEVER */

#ifdef SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVERFACTORY

bool TElCustomCertificateRetrieverFactory::SupportsLocation(TSBGeneralName NameType, const std::string &URI)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertificateRetrieverFactory_SupportsLocation(_Handle, (TSBGeneralNameRaw)NameType, URI.data(), (int32_t)URI.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVER
SB_INLINE TElCustomCertificateRetrieverHandle TElCustomCertificateRetrieverFactory::GetClientInstance(TObject &Validator)
{
	TElCustomCertificateRetrieverHandle OutResult;
	SBCheckError(TElCustomCertificateRetrieverFactory_GetClientInstance(_Handle, Validator.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCertificateRetrieverHandle TElCustomCertificateRetrieverFactory::GetClientInstance(TObject *Validator)
{
	TElCustomCertificateRetrieverHandle OutResult;
	SBCheckError(TElCustomCertificateRetrieverFactory_GetClientInstance(_Handle, (Validator != NULL) ? Validator->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVER */

TElCustomCertificateRetrieverFactory::TElCustomCertificateRetrieverFactory(TElCustomCertificateRetrieverFactoryHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElCustomCertificateRetrieverFactory::TElCustomCertificateRetrieverFactory() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomCertificateRetrieverFactory_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVERFACTORY */

#ifdef SB_USE_CLASS_TELCERTIFICATERETRIEVERMANAGER

#ifdef SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVER
SB_INLINE TElCustomCertificateRetrieverHandle TElCertificateRetrieverManager::FindCertificateRetrieverByLocation(TSBGeneralName NameType, const std::string &Location, TObject &Validator)
{
	TElCustomCertificateRetrieverHandle OutResult;
	SBCheckError(TElCertificateRetrieverManager_FindCertificateRetrieverByLocation(_Handle, (TSBGeneralNameRaw)NameType, Location.data(), (int32_t)Location.length(), Validator.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCertificateRetrieverHandle TElCertificateRetrieverManager::FindCertificateRetrieverByLocation(TSBGeneralName NameType, const std::string &Location, TObject *Validator)
{
	TElCustomCertificateRetrieverHandle OutResult;
	SBCheckError(TElCertificateRetrieverManager_FindCertificateRetrieverByLocation(_Handle, (TSBGeneralNameRaw)NameType, Location.data(), (int32_t)Location.length(), (Validator != NULL) ? Validator->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVER */

#ifdef SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVERFACTORY
SB_INLINE void TElCertificateRetrieverManager::RegisterCertificateRetrieverFactory(TElCustomCertificateRetrieverFactory &Factory)
{
	SBCheckError(TElCertificateRetrieverManager_RegisterCertificateRetrieverFactory(_Handle, Factory.getHandle()));
}

SB_INLINE void TElCertificateRetrieverManager::RegisterCertificateRetrieverFactory(TElCustomCertificateRetrieverFactory *Factory)
{
	SBCheckError(TElCertificateRetrieverManager_RegisterCertificateRetrieverFactory(_Handle, (Factory != NULL) ? Factory->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVERFACTORY */

#ifdef SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVERFACTORY
SB_INLINE void TElCertificateRetrieverManager::UnregisterCertificateRetrieverFactory(TElCustomCertificateRetrieverFactory &Factory)
{
	SBCheckError(TElCertificateRetrieverManager_UnregisterCertificateRetrieverFactory(_Handle, Factory.getHandle()));
}

SB_INLINE void TElCertificateRetrieverManager::UnregisterCertificateRetrieverFactory(TElCustomCertificateRetrieverFactory *Factory)
{
	SBCheckError(TElCertificateRetrieverManager_UnregisterCertificateRetrieverFactory(_Handle, (Factory != NULL) ? Factory->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVERFACTORY */

TElCertificateRetrieverManager::TElCertificateRetrieverManager(TElCertificateRetrieverManagerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElCertificateRetrieverManager::TElCertificateRetrieverManager() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCertificateRetrieverManager_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCERTIFICATERETRIEVERMANAGER */

#ifdef SB_USE_GLOBAL_PROCS_CERTRETRIEVER

#ifdef SB_USE_CLASS_TELCERTIFICATERETRIEVERMANAGER
SB_INLINE TElCertificateRetrieverManagerHandle CertificateRetrieverManagerAddRef()
{
	TElCertificateRetrieverManagerHandle OutResult;
	SBCheckError(SBCertRetriever_CertificateRetrieverManagerAddRef(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCERTIFICATERETRIEVERMANAGER */

SB_INLINE void CertificateRetrieverManagerRelease()
{
	SBCheckError(SBCertRetriever_CertificateRetrieverManagerRelease());
}

#endif /* SB_USE_GLOBAL_PROCS_CERTRETRIEVER */

};	/* namespace SecureBlackbox */

