#include "sbldapcertretriever.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELLDAPCERTIFICATERETRIEVER

bool TElLDAPCertificateRetriever::SupportsLocation(TSBGeneralName NameType, const std::string &URI)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElLDAPCertificateRetriever_SupportsLocation(_Handle, (TSBGeneralNameRaw)NameType, URI.data(), (int32_t)URI.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE TElX509CertificateHandle TElLDAPCertificateRetriever::RetrieveCertificate(TElX509Certificate &Certificate, TSBGeneralName NameType, const std::string &URL)
{
	TElX509CertificateHandle OutResult;
	SBCheckError(TElLDAPCertificateRetriever_RetrieveCertificate(_Handle, Certificate.getHandle(), (TSBGeneralNameRaw)NameType, URL.data(), (int32_t)URL.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElX509CertificateHandle TElLDAPCertificateRetriever::RetrieveCertificate(TElX509Certificate *Certificate, TSBGeneralName NameType, const std::string &URL)
{
	TElX509CertificateHandle OutResult;
	SBCheckError(TElLDAPCertificateRetriever_RetrieveCertificate(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (TSBGeneralNameRaw)NameType, URL.data(), (int32_t)URL.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELLDAPSCLIENT
TElLDAPSClient* TElLDAPCertificateRetriever::get_LDAPSClient()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElLDAPCertificateRetriever_get_LDAPSClient(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_LDAPSClient)
		this->_Inst_LDAPSClient = new TElLDAPSClient(hOutResult, ohFalse);
	else
		this->_Inst_LDAPSClient->updateHandle(hOutResult);
	return this->_Inst_LDAPSClient;
}
#endif /* SB_USE_CLASS_TELLDAPSCLIENT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElLDAPCertificateRetriever::get_ServerList()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElLDAPCertificateRetriever_get_ServerList(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ServerList)
		this->_Inst_ServerList = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_ServerList->updateHandle(hOutResult);
	return this->_Inst_ServerList;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElLDAPCertificateRetriever::get_ServerList()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElLDAPCertificateRetriever_get_ServerList(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ServerList)
		this->_Inst_ServerList = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_ServerList->updateHandle(hOutResult);
	return this->_Inst_ServerList;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElLDAPCertificateRetriever::initInstances()
{
#ifdef SB_USE_CLASS_TELLDAPSCLIENT
	this->_Inst_LDAPSClient = NULL;
#endif /* SB_USE_CLASS_TELLDAPSCLIENT */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_ServerList = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_ServerList = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElLDAPCertificateRetriever::TElLDAPCertificateRetriever(TElLDAPCertificateRetrieverHandle handle, TElOwnHandle ownHandle) : TElCustomCertificateRetriever(handle, ownHandle)
{
	initInstances();
}

TElLDAPCertificateRetriever::TElLDAPCertificateRetriever(TComponent &AOwner) : TElCustomCertificateRetriever(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElLDAPCertificateRetriever_Create(AOwner.getHandle(), &_Handle));
}

TElLDAPCertificateRetriever::TElLDAPCertificateRetriever(TComponent *AOwner) : TElCustomCertificateRetriever(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElLDAPCertificateRetriever_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElLDAPCertificateRetriever::~TElLDAPCertificateRetriever()
{
#ifdef SB_USE_CLASS_TELLDAPSCLIENT
	delete this->_Inst_LDAPSClient;
	this->_Inst_LDAPSClient = NULL;
#endif /* SB_USE_CLASS_TELLDAPSCLIENT */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_ServerList;
	this->_Inst_ServerList = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_ServerList;
	this->_Inst_ServerList = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELLDAPCERTIFICATERETRIEVER */

#ifdef SB_USE_CLASS_TELLDAPCERTIFICATERETRIEVERFACTORY

bool TElLDAPCertificateRetrieverFactory::SupportsLocation(TSBGeneralName NameType, const std::string &URI)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElLDAPCertificateRetrieverFactory_SupportsLocation(_Handle, (TSBGeneralNameRaw)NameType, URI.data(), (int32_t)URI.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVER
SB_INLINE TElCustomCertificateRetrieverHandle TElLDAPCertificateRetrieverFactory::GetClientInstance(TObject &Validator)
{
	TElCustomCertificateRetrieverHandle OutResult;
	SBCheckError(TElLDAPCertificateRetrieverFactory_GetClientInstance(_Handle, Validator.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCertificateRetrieverHandle TElLDAPCertificateRetrieverFactory::GetClientInstance(TObject *Validator)
{
	TElCustomCertificateRetrieverHandle OutResult;
	SBCheckError(TElLDAPCertificateRetrieverFactory_GetClientInstance(_Handle, (Validator != NULL) ? Validator->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVER */

TElLDAPCertificateRetrieverFactory::TElLDAPCertificateRetrieverFactory(TElLDAPCertificateRetrieverFactoryHandle handle, TElOwnHandle ownHandle) : TElCustomCertificateRetrieverFactory(handle, ownHandle)
{
}

TElLDAPCertificateRetrieverFactory::TElLDAPCertificateRetrieverFactory() : TElCustomCertificateRetrieverFactory(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLDAPCertificateRetrieverFactory_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELLDAPCERTIFICATERETRIEVERFACTORY */

#ifdef SB_USE_GLOBAL_PROCS_LDAPCERTRETRIEVER

SB_INLINE void RegisterLDAPCertificateRetrieverFactory()
{
	SBCheckError(SBLDAPCertRetriever_RegisterLDAPCertificateRetrieverFactory());
}

#endif /* SB_USE_GLOBAL_PROCS_LDAPCERTRETRIEVER */

};	/* namespace SecureBlackbox */
