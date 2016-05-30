#include "sbhttpcertretriever.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELHTTPCERTIFICATERETRIEVER

bool TElHTTPCertificateRetriever::SupportsLocation(TSBGeneralName NameType, const std::string &URI)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPCertificateRetriever_SupportsLocation(_Handle, (TSBGeneralNameRaw)NameType, URI.data(), (int32_t)URI.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE TElX509CertificateHandle TElHTTPCertificateRetriever::RetrieveCertificate(TElX509Certificate &Certificate, TSBGeneralName NameType, const std::string &URL)
{
	TElX509CertificateHandle OutResult;
	SBCheckError(TElHTTPCertificateRetriever_RetrieveCertificate(_Handle, Certificate.getHandle(), (TSBGeneralNameRaw)NameType, URL.data(), (int32_t)URL.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElX509CertificateHandle TElHTTPCertificateRetriever::RetrieveCertificate(TElX509Certificate *Certificate, TSBGeneralName NameType, const std::string &URL)
{
	TElX509CertificateHandle OutResult;
	SBCheckError(TElHTTPCertificateRetriever_RetrieveCertificate(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (TSBGeneralNameRaw)NameType, URL.data(), (int32_t)URL.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
TElHTTPSClient* TElHTTPCertificateRetriever::get_HTTPClient()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPCertificateRetriever_get_HTTPClient(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HTTPClient)
		this->_Inst_HTTPClient = new TElHTTPSClient(hOutResult, ohFalse);
	else
		this->_Inst_HTTPClient->updateHandle(hOutResult);
	return this->_Inst_HTTPClient;
}

SB_INLINE void TElHTTPCertificateRetriever::set_HTTPClient(TElHTTPSClient &Value)
{
	SBCheckError(TElHTTPCertificateRetriever_set_HTTPClient(_Handle, Value.getHandle()));
}

SB_INLINE void TElHTTPCertificateRetriever::set_HTTPClient(TElHTTPSClient *Value)
{
	SBCheckError(TElHTTPCertificateRetriever_set_HTTPClient(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

void TElHTTPCertificateRetriever::initInstances()
{
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
}

TElHTTPCertificateRetriever::TElHTTPCertificateRetriever(TElHTTPCertificateRetrieverHandle handle, TElOwnHandle ownHandle) : TElCustomCertificateRetriever(handle, ownHandle)
{
	initInstances();
}

TElHTTPCertificateRetriever::TElHTTPCertificateRetriever(TComponent &Owner) : TElCustomCertificateRetriever(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHTTPCertificateRetriever_Create(Owner.getHandle(), &_Handle));
}

TElHTTPCertificateRetriever::TElHTTPCertificateRetriever(TComponent *Owner) : TElCustomCertificateRetriever(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHTTPCertificateRetriever_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElHTTPCertificateRetriever::~TElHTTPCertificateRetriever()
{
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	delete this->_Inst_HTTPClient;
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
}
#endif /* SB_USE_CLASS_TELHTTPCERTIFICATERETRIEVER */

#ifdef SB_USE_CLASS_TELHTTPCERTIFICATERETRIEVERFACTORY

bool TElHTTPCertificateRetrieverFactory::SupportsLocation(TSBGeneralName NameType, const std::string &URI)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPCertificateRetrieverFactory_SupportsLocation(_Handle, (TSBGeneralNameRaw)NameType, URI.data(), (int32_t)URI.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVER
SB_INLINE TElCustomCertificateRetrieverHandle TElHTTPCertificateRetrieverFactory::GetClientInstance(TObject &Validator)
{
	TElCustomCertificateRetrieverHandle OutResult;
	SBCheckError(TElHTTPCertificateRetrieverFactory_GetClientInstance(_Handle, Validator.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCertificateRetrieverHandle TElHTTPCertificateRetrieverFactory::GetClientInstance(TObject *Validator)
{
	TElCustomCertificateRetrieverHandle OutResult;
	SBCheckError(TElHTTPCertificateRetrieverFactory_GetClientInstance(_Handle, (Validator != NULL) ? Validator->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVER */

TElHTTPCertificateRetrieverFactory::TElHTTPCertificateRetrieverFactory(TElHTTPCertificateRetrieverFactoryHandle handle, TElOwnHandle ownHandle) : TElCustomCertificateRetrieverFactory(handle, ownHandle)
{
}

TElHTTPCertificateRetrieverFactory::TElHTTPCertificateRetrieverFactory() : TElCustomCertificateRetrieverFactory(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElHTTPCertificateRetrieverFactory_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELHTTPCERTIFICATERETRIEVERFACTORY */

#ifdef SB_USE_GLOBAL_PROCS_HTTPCERTRETRIEVER

SB_INLINE void RegisterHTTPCertificateRetrieverFactory()
{
	SBCheckError(SBHTTPCertRetriever_RegisterHTTPCertificateRetrieverFactory());
}

#endif /* SB_USE_GLOBAL_PROCS_HTTPCERTRETRIEVER */

};	/* namespace SecureBlackbox */

