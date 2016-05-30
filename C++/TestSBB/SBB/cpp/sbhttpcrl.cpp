#include "sbhttpcrl.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELHTTPCRLRETRIEVER

bool TElHTTPCRLRetriever::Supports(TSBGeneralName NameType, const std::string &Location)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPCRLRetriever_Supports(_Handle, (TSBGeneralNameRaw)NameType, Location.data(), (int32_t)Location.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASSES_TELCERTIFICATEREVOCATIONLIST_AND_TELX509CERTIFICATE
SB_INLINE TElCertificateRevocationListHandle TElHTTPCRLRetriever::GetCRL(TElX509Certificate &Certificate, TElX509Certificate &CACertificate, TSBGeneralName NameType, const std::string &Location)
{
	TElCertificateRevocationListHandle OutResult;
	SBCheckError(TElHTTPCRLRetriever_GetCRL(_Handle, Certificate.getHandle(), CACertificate.getHandle(), (TSBGeneralNameRaw)NameType, Location.data(), (int32_t)Location.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElCertificateRevocationListHandle TElHTTPCRLRetriever::GetCRL(TElX509Certificate *Certificate, TElX509Certificate *CACertificate, TSBGeneralName NameType, const std::string &Location)
{
	TElCertificateRevocationListHandle OutResult;
	SBCheckError(TElHTTPCRLRetriever_GetCRL(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (CACertificate != NULL) ? CACertificate->getHandle() : SB_NULL_HANDLE, (TSBGeneralNameRaw)NameType, Location.data(), (int32_t)Location.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCERTIFICATEREVOCATIONLIST_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
TElHTTPSClient* TElHTTPCRLRetriever::get_HTTPClient()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPCRLRetriever_get_HTTPClient(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HTTPClient)
		this->_Inst_HTTPClient = new TElHTTPSClient(hOutResult, ohFalse);
	else
		this->_Inst_HTTPClient->updateHandle(hOutResult);
	return this->_Inst_HTTPClient;
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

void TElHTTPCRLRetriever::initInstances()
{
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
}

TElHTTPCRLRetriever::TElHTTPCRLRetriever(TElHTTPCRLRetrieverHandle handle, TElOwnHandle ownHandle) : TElCustomCRLRetriever(handle, ownHandle)
{
	initInstances();
}

TElHTTPCRLRetriever::TElHTTPCRLRetriever(TComponent &AOwner) : TElCustomCRLRetriever(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHTTPCRLRetriever_Create(AOwner.getHandle(), &_Handle));
}

TElHTTPCRLRetriever::TElHTTPCRLRetriever(TComponent *AOwner) : TElCustomCRLRetriever(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHTTPCRLRetriever_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElHTTPCRLRetriever::~TElHTTPCRLRetriever()
{
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	delete this->_Inst_HTTPClient;
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
}
#endif /* SB_USE_CLASS_TELHTTPCRLRETRIEVER */

#ifdef SB_USE_CLASS_TELHTTPCRLRETRIEVERFACTORY

bool TElHTTPCRLRetrieverFactory::Supports(TSBGeneralName NameType, const std::string &Location)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPCRLRetrieverFactory_Supports(_Handle, (TSBGeneralNameRaw)NameType, Location.data(), (int32_t)Location.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELCUSTOMCRLRETRIEVER
SB_INLINE TElCustomCRLRetrieverHandle TElHTTPCRLRetrieverFactory::GetRetrieverInstance(TObject &Validator)
{
	TElCustomCRLRetrieverHandle OutResult;
	SBCheckError(TElHTTPCRLRetrieverFactory_GetRetrieverInstance(_Handle, Validator.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCRLRetrieverHandle TElHTTPCRLRetrieverFactory::GetRetrieverInstance(TObject *Validator)
{
	TElCustomCRLRetrieverHandle OutResult;
	SBCheckError(TElHTTPCRLRetrieverFactory_GetRetrieverInstance(_Handle, (Validator != NULL) ? Validator->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRLRETRIEVER */

TElHTTPCRLRetrieverFactory::TElHTTPCRLRetrieverFactory(TElHTTPCRLRetrieverFactoryHandle handle, TElOwnHandle ownHandle) : TElCustomCRLRetrieverFactory(handle, ownHandle)
{
}

TElHTTPCRLRetrieverFactory::TElHTTPCRLRetrieverFactory() : TElCustomCRLRetrieverFactory(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElHTTPCRLRetrieverFactory_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELHTTPCRLRETRIEVERFACTORY */

#ifdef SB_USE_GLOBAL_PROCS_HTTPCRL

SB_INLINE void RegisterHTTPCRLRetrieverFactory()
{
	SBCheckError(SBHTTPCRL_RegisterHTTPCRLRetrieverFactory());
}

#endif /* SB_USE_GLOBAL_PROCS_HTTPCRL */

};	/* namespace SecureBlackbox */

