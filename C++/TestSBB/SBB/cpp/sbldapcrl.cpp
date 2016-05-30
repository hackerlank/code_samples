#include "sbldapcrl.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELLDAPCRLRETRIEVER

bool TElLDAPCRLRetriever::Supports(TSBGeneralName NameType, const std::string &Location)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElLDAPCRLRetriever_Supports(_Handle, (TSBGeneralNameRaw)NameType, Location.data(), (int32_t)Location.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASSES_TELCERTIFICATEREVOCATIONLIST_AND_TELX509CERTIFICATE
SB_INLINE TElCertificateRevocationListHandle TElLDAPCRLRetriever::GetCRL(TElX509Certificate &Certificate, TElX509Certificate &CACertificate, TSBGeneralName NameType, const std::string &Location)
{
	TElCertificateRevocationListHandle OutResult;
	SBCheckError(TElLDAPCRLRetriever_GetCRL(_Handle, Certificate.getHandle(), CACertificate.getHandle(), (TSBGeneralNameRaw)NameType, Location.data(), (int32_t)Location.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElCertificateRevocationListHandle TElLDAPCRLRetriever::GetCRL(TElX509Certificate *Certificate, TElX509Certificate *CACertificate, TSBGeneralName NameType, const std::string &Location)
{
	TElCertificateRevocationListHandle OutResult;
	SBCheckError(TElLDAPCRLRetriever_GetCRL(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (CACertificate != NULL) ? CACertificate->getHandle() : SB_NULL_HANDLE, (TSBGeneralNameRaw)NameType, Location.data(), (int32_t)Location.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCERTIFICATEREVOCATIONLIST_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELLDAPSCLIENT
TElLDAPSClient* TElLDAPCRLRetriever::get_LDAPSClient()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElLDAPCRLRetriever_get_LDAPSClient(_Handle, &hOutResult));
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
TStringList* TElLDAPCRLRetriever::get_ServerList()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElLDAPCRLRetriever_get_ServerList(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ServerList)
		this->_Inst_ServerList = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_ServerList->updateHandle(hOutResult);
	return this->_Inst_ServerList;
}

SB_INLINE void TElLDAPCRLRetriever::set_ServerList(TStringList &Value)
{
	SBCheckError(TElLDAPCRLRetriever_set_ServerList(_Handle, Value.getHandle()));
}

SB_INLINE void TElLDAPCRLRetriever::set_ServerList(TStringList *Value)
{
	SBCheckError(TElLDAPCRLRetriever_set_ServerList(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElLDAPCRLRetriever::get_ServerList()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElLDAPCRLRetriever_get_ServerList(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ServerList)
		this->_Inst_ServerList = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_ServerList->updateHandle(hOutResult);
	return this->_Inst_ServerList;
}

SB_INLINE void TElLDAPCRLRetriever::set_ServerList(TElStringList &Value)
{
	SBCheckError(TElLDAPCRLRetriever_set_ServerList(_Handle, Value.getHandle()));
}

SB_INLINE void TElLDAPCRLRetriever::set_ServerList(TElStringList *Value)
{
	SBCheckError(TElLDAPCRLRetriever_set_ServerList(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElLDAPCRLRetriever::initInstances()
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

TElLDAPCRLRetriever::TElLDAPCRLRetriever(TElLDAPCRLRetrieverHandle handle, TElOwnHandle ownHandle) : TElCustomCRLRetriever(handle, ownHandle)
{
	initInstances();
}

TElLDAPCRLRetriever::TElLDAPCRLRetriever(TComponent &AOwner) : TElCustomCRLRetriever(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElLDAPCRLRetriever_Create(AOwner.getHandle(), &_Handle));
}

TElLDAPCRLRetriever::TElLDAPCRLRetriever(TComponent *AOwner) : TElCustomCRLRetriever(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElLDAPCRLRetriever_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElLDAPCRLRetriever::~TElLDAPCRLRetriever()
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
#endif /* SB_USE_CLASS_TELLDAPCRLRETRIEVER */

#ifdef SB_USE_CLASS_TELLDAPCRLRETRIEVERFACTORY

bool TElLDAPCRLRetrieverFactory::Supports(TSBGeneralName NameType, const std::string &Location)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElLDAPCRLRetrieverFactory_Supports(_Handle, (TSBGeneralNameRaw)NameType, Location.data(), (int32_t)Location.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELCUSTOMCRLRETRIEVER
SB_INLINE TElCustomCRLRetrieverHandle TElLDAPCRLRetrieverFactory::GetRetrieverInstance(TObject &Validator)
{
	TElCustomCRLRetrieverHandle OutResult;
	SBCheckError(TElLDAPCRLRetrieverFactory_GetRetrieverInstance(_Handle, Validator.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomCRLRetrieverHandle TElLDAPCRLRetrieverFactory::GetRetrieverInstance(TObject *Validator)
{
	TElCustomCRLRetrieverHandle OutResult;
	SBCheckError(TElLDAPCRLRetrieverFactory_GetRetrieverInstance(_Handle, (Validator != NULL) ? Validator->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRLRETRIEVER */

TElLDAPCRLRetrieverFactory::TElLDAPCRLRetrieverFactory(TElLDAPCRLRetrieverFactoryHandle handle, TElOwnHandle ownHandle) : TElCustomCRLRetrieverFactory(handle, ownHandle)
{
}

TElLDAPCRLRetrieverFactory::TElLDAPCRLRetrieverFactory() : TElCustomCRLRetrieverFactory(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLDAPCRLRetrieverFactory_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELLDAPCRLRETRIEVERFACTORY */

#ifdef SB_USE_GLOBAL_PROCS_LDAPCRL

SB_INLINE void RegisterLDAPCRLRetrieverFactory()
{
	SBCheckError(SBLDAPCRL_RegisterLDAPCRLRetrieverFactory());
}

#endif /* SB_USE_GLOBAL_PROCS_LDAPCRL */

};	/* namespace SecureBlackbox */
