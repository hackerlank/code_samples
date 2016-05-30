#include "sbsamlidentityprovider.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSAMLIDPSESSION

#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO
SB_INLINE void TElSAMLIDPSession::AddServiceProvider(const std::string &SessionIndex, TElSAMLServiceProviderInfo &SPInfo)
{
	SBCheckError(TElSAMLIDPSession_AddServiceProvider(_Handle, SessionIndex.data(), (int32_t)SessionIndex.length(), SPInfo.getHandle()));
}

SB_INLINE void TElSAMLIDPSession::AddServiceProvider(const std::string &SessionIndex, TElSAMLServiceProviderInfo *SPInfo)
{
	SBCheckError(TElSAMLIDPSession_AddServiceProvider(_Handle, SessionIndex.data(), (int32_t)SessionIndex.length(), (SPInfo != NULL) ? SPInfo->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO */

SB_INLINE void TElSAMLIDPSession::RemoveServiceProvider(const std::string &SessionIndex)
{
	SBCheckError(TElSAMLIDPSession_RemoveServiceProvider(_Handle, SessionIndex.data(), (int32_t)SessionIndex.length()));
}

bool TElSAMLIDPSession::get_LoggedIn()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLIDPSession_get_LoggedIn(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TSBSAMLIDPStage TElSAMLIDPSession::get_Stage()
{
	TSBSAMLIDPStageRaw OutResultRaw = 0;
	SBCheckError(TElSAMLIDPSession_get_Stage(_Handle, &OutResultRaw));
	return (TSBSAMLIDPStage)OutResultRaw;
}

SB_INLINE void TElSAMLIDPSession::set_Stage(TSBSAMLIDPStage Value)
{
	SBCheckError(TElSAMLIDPSession_set_Stage(_Handle, (TSBSAMLIDPStageRaw)Value));
}

void TElSAMLIDPSession::get_Login(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIDPSession_get_Login(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1139914951, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIDPSession::set_Login(const std::string &Value)
{
	SBCheckError(TElSAMLIDPSession_set_Login(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElSAMLIDPSession::get_Certificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIDPSession_get_Certificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificate)
		this->_Inst_Certificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_Certificate->updateHandle(hOutResult);
	return this->_Inst_Certificate;
}

SB_INLINE void TElSAMLIDPSession::set_Certificate(TElX509Certificate &Value)
{
	SBCheckError(TElSAMLIDPSession_set_Certificate(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLIDPSession::set_Certificate(TElX509Certificate *Value)
{
	SBCheckError(TElSAMLIDPSession_set_Certificate(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

bool TElSAMLIDPSession::get_SAMLCookieSet()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLIDPSession_get_SAMLCookieSet(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLIDPSession::set_SAMLCookieSet(bool Value)
{
	SBCheckError(TElSAMLIDPSession_set_SAMLCookieSet(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELSAMLID
TElSAMLID* TElSAMLIDPSession::get_NameID()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIDPSession_get_NameID(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NameID)
		this->_Inst_NameID = new TElSAMLID(hOutResult, ohFalse);
	else
		this->_Inst_NameID->updateHandle(hOutResult);
	return this->_Inst_NameID;
}

SB_INLINE void TElSAMLIDPSession::set_NameID(TElSAMLID &Value)
{
	SBCheckError(TElSAMLIDPSession_set_NameID(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLIDPSession::set_NameID(TElSAMLID *Value)
{
	SBCheckError(TElSAMLIDPSession_set_NameID(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLID */

SB_INLINE int32_t TElSAMLIDPSession::get_LoginAttempts()
{
	int32_t OutResult;
	SBCheckError(TElSAMLIDPSession_get_LoginAttempts(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLIDPSession::set_LoginAttempts(int32_t Value)
{
	SBCheckError(TElSAMLIDPSession_set_LoginAttempts(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELDICTIONARY
TElDictionary* TElSAMLIDPSession::get_ServiceProviders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIDPSession_get_ServiceProviders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ServiceProviders)
		this->_Inst_ServiceProviders = new TElDictionary(hOutResult, ohFalse);
	else
		this->_Inst_ServiceProviders->updateHandle(hOutResult);
	return this->_Inst_ServiceProviders;
}
#endif /* SB_USE_CLASS_TELDICTIONARY */

#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO
TElSAMLServiceProviderInfo* TElSAMLIDPSession::get_LastSP()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIDPSession_get_LastSP(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_LastSP)
		this->_Inst_LastSP = new TElSAMLServiceProviderInfo(hOutResult, ohFalse);
	else
		this->_Inst_LastSP->updateHandle(hOutResult);
	return this->_Inst_LastSP;
}

SB_INLINE void TElSAMLIDPSession::set_LastSP(TElSAMLServiceProviderInfo &Value)
{
	SBCheckError(TElSAMLIDPSession_set_LastSP(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLIDPSession::set_LastSP(TElSAMLServiceProviderInfo *Value)
{
	SBCheckError(TElSAMLIDPSession_set_LastSP(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO */

TSBSAMLBindingType TElSAMLIDPSession::get_Binding()
{
	TSBSAMLBindingTypeRaw OutResultRaw = 0;
	SBCheckError(TElSAMLIDPSession_get_Binding(_Handle, &OutResultRaw));
	return (TSBSAMLBindingType)OutResultRaw;
}

SB_INLINE void TElSAMLIDPSession::set_Binding(TSBSAMLBindingType Value)
{
	SBCheckError(TElSAMLIDPSession_set_Binding(_Handle, (TSBSAMLBindingTypeRaw)Value));
}

void TElSAMLIDPSession::get_ResponseLocation(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIDPSession_get_ResponseLocation(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-608443255, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIDPSession::set_ResponseLocation(const std::string &Value)
{
	SBCheckError(TElSAMLIDPSession_set_ResponseLocation(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLIDPSession::get_AuthnContextClassRef(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIDPSession_get_AuthnContextClassRef(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(165003165, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIDPSession::set_AuthnContextClassRef(const std::string &Value)
{
	SBCheckError(TElSAMLIDPSession_set_AuthnContextClassRef(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLIDPSession::get_NameIDPolicyFormat(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIDPSession_get_NameIDPolicyFormat(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1450418200, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIDPSession::set_NameIDPolicyFormat(const std::string &Value)
{
	SBCheckError(TElSAMLIDPSession_set_NameIDPolicyFormat(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLIDPSession::get_SessionIndex(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIDPSession_get_SessionIndex(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1896893883, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIDPSession::set_SessionIndex(const std::string &Value)
{
	SBCheckError(TElSAMLIDPSession_set_SessionIndex(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSAMLIDPSession::get_IdPSSO()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLIDPSession_get_IdPSSO(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLIDPSession::set_IdPSSO(bool Value)
{
	SBCheckError(TElSAMLIDPSession_set_IdPSSO(_Handle, (int8_t)Value));
}

void TElSAMLIDPSession::initInstances()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_Certificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELSAMLID
	this->_Inst_NameID = NULL;
#endif /* SB_USE_CLASS_TELSAMLID */
#ifdef SB_USE_CLASS_TELDICTIONARY
	this->_Inst_ServiceProviders = NULL;
#endif /* SB_USE_CLASS_TELDICTIONARY */
#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO
	this->_Inst_LastSP = NULL;
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO */
}

TElSAMLIDPSession::TElSAMLIDPSession(TElSAMLIDPSessionHandle handle, TElOwnHandle ownHandle) : TElSAMLSession(handle, ownHandle)
{
	initInstances();
}

TElSAMLIDPSession::TElSAMLIDPSession() : TElSAMLSession(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLIDPSession_Create(&_Handle));
}

TElSAMLIDPSession::~TElSAMLIDPSession()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_Certificate;
	this->_Inst_Certificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELSAMLID
	delete this->_Inst_NameID;
	this->_Inst_NameID = NULL;
#endif /* SB_USE_CLASS_TELSAMLID */
#ifdef SB_USE_CLASS_TELDICTIONARY
	delete this->_Inst_ServiceProviders;
	this->_Inst_ServiceProviders = NULL;
#endif /* SB_USE_CLASS_TELDICTIONARY */
#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO
	delete this->_Inst_LastSP;
	this->_Inst_LastSP = NULL;
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO */
}
#endif /* SB_USE_CLASS_TELSAMLIDPSESSION */

#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO

SB_INLINE TElSAMLServiceProviderInfoHandle TElSAMLServiceProviderInfo::CreateForGoogleAppEngine(const std::string &Domain)
{
	TElSAMLServiceProviderInfoHandle OutResult;
	SBCheckError(TElSAMLServiceProviderInfo_CreateForGoogleAppEngine(Domain.data(), (int32_t)Domain.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElSAMLServiceProviderInfoHandle TElSAMLServiceProviderInfo::CreateForGoogleAppEngine_Inst(const std::string &Domain)
{
	TElSAMLServiceProviderInfoHandle OutResult;
	SBCheckError(TElSAMLServiceProviderInfo_CreateForGoogleAppEngine_1(_Handle, Domain.data(), (int32_t)Domain.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
SB_INLINE int32_t TElSAMLServiceProviderInfo::AddAssertionConsumerService(TElSAMLEndpoint &Endpoint)
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProviderInfo_AddAssertionConsumerService(_Handle, Endpoint.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLServiceProviderInfo::AddAssertionConsumerService(TElSAMLEndpoint *Endpoint)
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProviderInfo_AddAssertionConsumerService(_Handle, (Endpoint != NULL) ? Endpoint->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
SB_INLINE int32_t TElSAMLServiceProviderInfo::AddSingleLogoutService(TElSAMLEndpoint &Endpoint)
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProviderInfo_AddSingleLogoutService(_Handle, Endpoint.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLServiceProviderInfo::AddSingleLogoutService(TElSAMLEndpoint *Endpoint)
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProviderInfo_AddSingleLogoutService(_Handle, (Endpoint != NULL) ? Endpoint->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
SB_INLINE int32_t TElSAMLServiceProviderInfo::AddArtifactResolutionService(TElSAMLEndpoint &Endpoint)
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProviderInfo_AddArtifactResolutionService(_Handle, Endpoint.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLServiceProviderInfo::AddArtifactResolutionService(TElSAMLEndpoint *Endpoint)
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProviderInfo_AddArtifactResolutionService(_Handle, (Endpoint != NULL) ? Endpoint->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

SB_INLINE void TElSAMLServiceProviderInfo::RemoveAssertionConsumerService(int32_t Index)
{
	SBCheckError(TElSAMLServiceProviderInfo_RemoveAssertionConsumerService(_Handle, Index));
}

SB_INLINE void TElSAMLServiceProviderInfo::RemoveSingleLogoutService(int32_t Index)
{
	SBCheckError(TElSAMLServiceProviderInfo_RemoveSingleLogoutService(_Handle, Index));
}

SB_INLINE void TElSAMLServiceProviderInfo::RemoveArtifactResolutionService(int32_t Index)
{
	SBCheckError(TElSAMLServiceProviderInfo_RemoveArtifactResolutionService(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
SB_INLINE TElSAMLEndpointHandle TElSAMLServiceProviderInfo::FindDefaultAssertionConsumerServiceEP()
{
	TElSAMLEndpointHandle OutResult;
	SBCheckError(TElSAMLServiceProviderInfo_FindDefaultAssertionConsumerServiceEP(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
SB_INLINE TElSAMLEndpointHandle TElSAMLServiceProviderInfo::FindAssertionConsumerServiceEP(TSBSAMLBindingType Binding)
{
	TElSAMLEndpointHandle OutResult;
	SBCheckError(TElSAMLServiceProviderInfo_FindAssertionConsumerServiceEP(_Handle, (TSBSAMLBindingTypeRaw)Binding, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE TListHandle TElSAMLServiceProviderInfo::FindAssertionConsumerServiceEP(const std::string &Location)
{
	TListHandle OutResult;
	SBCheckError(TElSAMLServiceProviderInfo_FindAssertionConsumerServiceEP_1(_Handle, Location.data(), (int32_t)Location.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
SB_INLINE TElSAMLEndpointHandle TElSAMLServiceProviderInfo::FindAssertionConsumerServiceEP(int32_t Idx)
{
	TElSAMLEndpointHandle OutResult;
	SBCheckError(TElSAMLServiceProviderInfo_FindAssertionConsumerServiceEP_2(_Handle, Idx, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
SB_INLINE TElSAMLEndpointHandle TElSAMLServiceProviderInfo::FindSingleLogoutServiceEP(TSBSAMLBindingType Binding)
{
	TElSAMLEndpointHandle OutResult;
	SBCheckError(TElSAMLServiceProviderInfo_FindSingleLogoutServiceEP(_Handle, (TSBSAMLBindingTypeRaw)Binding, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
SB_INLINE TElSAMLEndpointHandle TElSAMLServiceProviderInfo::FindArtifactResolutionServiceEP(TSBSAMLBindingType Binding)
{
	TElSAMLEndpointHandle OutResult;
	SBCheckError(TElSAMLServiceProviderInfo_FindArtifactResolutionServiceEP(_Handle, (TSBSAMLBindingTypeRaw)Binding, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

void TElSAMLServiceProviderInfo::ChooseNameIDFormat(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLServiceProviderInfo_ChooseNameIDFormat(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(518030096, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLServiceProviderInfo::LoadMetadata(const std::string &URI)
{
	SBCheckError(TElSAMLServiceProviderInfo_LoadMetadata(_Handle, URI.data(), (int32_t)URI.length()));
}

void TElSAMLServiceProviderInfo::GetUniqueID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLServiceProviderInfo_GetUniqueID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1620401763, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSAMLServiceProviderInfo::get_EntityID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLServiceProviderInfo_get_EntityID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-748037897, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLServiceProviderInfo::set_EntityID(const std::string &Value)
{
	SBCheckError(TElSAMLServiceProviderInfo_set_EntityID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLServiceProviderInfo::get_SPNameQualifier(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLServiceProviderInfo_get_SPNameQualifier(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1304517708, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLServiceProviderInfo::set_SPNameQualifier(const std::string &Value)
{
	SBCheckError(TElSAMLServiceProviderInfo_set_SPNameQualifier(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSAMLServiceProviderInfo::get_IDPNameIDFormats()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProviderInfo_get_IDPNameIDFormats(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IDPNameIDFormats)
		this->_Inst_IDPNameIDFormats = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_IDPNameIDFormats->updateHandle(hOutResult);
	return this->_Inst_IDPNameIDFormats;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSAMLServiceProviderInfo::get_IDPNameIDFormats()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProviderInfo_get_IDPNameIDFormats(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IDPNameIDFormats)
		this->_Inst_IDPNameIDFormats = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_IDPNameIDFormats->updateHandle(hOutResult);
	return this->_Inst_IDPNameIDFormats;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
TElSAMLEndpoint* TElSAMLServiceProviderInfo::get_AssertionConsumerServices(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProviderInfo_get_AssertionConsumerServices(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AssertionConsumerServices)
		this->_Inst_AssertionConsumerServices = new TElSAMLEndpoint(hOutResult, ohFalse);
	else
		this->_Inst_AssertionConsumerServices->updateHandle(hOutResult);
	return this->_Inst_AssertionConsumerServices;
}
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
TElSAMLEndpoint* TElSAMLServiceProviderInfo::get_SingleLogoutServices(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProviderInfo_get_SingleLogoutServices(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SingleLogoutServices)
		this->_Inst_SingleLogoutServices = new TElSAMLEndpoint(hOutResult, ohFalse);
	else
		this->_Inst_SingleLogoutServices->updateHandle(hOutResult);
	return this->_Inst_SingleLogoutServices;
}
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
TElSAMLEndpoint* TElSAMLServiceProviderInfo::get_ArtifactResolutionServices(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProviderInfo_get_ArtifactResolutionServices(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ArtifactResolutionServices)
		this->_Inst_ArtifactResolutionServices = new TElSAMLEndpoint(hOutResult, ohFalse);
	else
		this->_Inst_ArtifactResolutionServices->updateHandle(hOutResult);
	return this->_Inst_ArtifactResolutionServices;
}
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

SB_INLINE int32_t TElSAMLServiceProviderInfo::get_AssertionConsumerServiceCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProviderInfo_get_AssertionConsumerServiceCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLServiceProviderInfo::get_SingleLogoutServiceCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProviderInfo_get_SingleLogoutServiceCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLServiceProviderInfo::get_ArtifactResolutionServiceCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProviderInfo_get_ArtifactResolutionServiceCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElSAMLServiceProviderInfo::get_SigningCertificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProviderInfo_get_SigningCertificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SigningCertificate)
		this->_Inst_SigningCertificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_SigningCertificate->updateHandle(hOutResult);
	return this->_Inst_SigningCertificate;
}

SB_INLINE void TElSAMLServiceProviderInfo::set_SigningCertificate(TElX509Certificate &Value)
{
	SBCheckError(TElSAMLServiceProviderInfo_set_SigningCertificate(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLServiceProviderInfo::set_SigningCertificate(TElX509Certificate *Value)
{
	SBCheckError(TElSAMLServiceProviderInfo_set_SigningCertificate(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElSAMLServiceProviderInfo::get_EncryptionCertificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProviderInfo_get_EncryptionCertificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptionCertificate)
		this->_Inst_EncryptionCertificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_EncryptionCertificate->updateHandle(hOutResult);
	return this->_Inst_EncryptionCertificate;
}

SB_INLINE void TElSAMLServiceProviderInfo::set_EncryptionCertificate(TElX509Certificate &Value)
{
	SBCheckError(TElSAMLServiceProviderInfo_set_EncryptionCertificate(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLServiceProviderInfo::set_EncryptionCertificate(TElX509Certificate *Value)
{
	SBCheckError(TElSAMLServiceProviderInfo_set_EncryptionCertificate(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElSAMLServiceProviderInfo::get_MetaSigningCertificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProviderInfo_get_MetaSigningCertificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_MetaSigningCertificate)
		this->_Inst_MetaSigningCertificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_MetaSigningCertificate->updateHandle(hOutResult);
	return this->_Inst_MetaSigningCertificate;
}

SB_INLINE void TElSAMLServiceProviderInfo::set_MetaSigningCertificate(TElX509Certificate &Value)
{
	SBCheckError(TElSAMLServiceProviderInfo_set_MetaSigningCertificate(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLServiceProviderInfo::set_MetaSigningCertificate(TElX509Certificate *Value)
{
	SBCheckError(TElSAMLServiceProviderInfo_set_MetaSigningCertificate(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

void TElSAMLServiceProviderInfo::get_SourceID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSAMLServiceProviderInfo_get_SourceID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-883643413, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLServiceProviderInfo::set_SourceID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSAMLServiceProviderInfo_set_SourceID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE void TElSAMLServiceProviderInfo::get_OnBeforeHTTPSClientUse(TSBSAMLBeforeHTTPSClientUseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProviderInfo_get_OnBeforeHTTPSClientUse(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProviderInfo::set_OnBeforeHTTPSClientUse(TSBSAMLBeforeHTTPSClientUseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProviderInfo_set_OnBeforeHTTPSClientUse(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProviderInfo::get_OnChooseMetadataSPDescriptor(TSBSAMLChooseMetadataDescriptorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProviderInfo_get_OnChooseMetadataSPDescriptor(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProviderInfo::set_OnChooseMetadataSPDescriptor(TSBSAMLChooseMetadataDescriptorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProviderInfo_set_OnChooseMetadataSPDescriptor(_Handle, pMethodValue, pDataValue));
}

void TElSAMLServiceProviderInfo::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_IDPNameIDFormats = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_IDPNameIDFormats = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELSAMLENDPOINT
	this->_Inst_AssertionConsumerServices = NULL;
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */
#ifdef SB_USE_CLASS_TELSAMLENDPOINT
	this->_Inst_SingleLogoutServices = NULL;
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */
#ifdef SB_USE_CLASS_TELSAMLENDPOINT
	this->_Inst_ArtifactResolutionServices = NULL;
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_SigningCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_EncryptionCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_MetaSigningCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
}

TElSAMLServiceProviderInfo::TElSAMLServiceProviderInfo(TElSAMLServiceProviderInfoHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElSAMLServiceProviderInfo::TElSAMLServiceProviderInfo() : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLServiceProviderInfo_Create(&_Handle));
}

TElSAMLServiceProviderInfo::~TElSAMLServiceProviderInfo()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_IDPNameIDFormats;
	this->_Inst_IDPNameIDFormats = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_IDPNameIDFormats;
	this->_Inst_IDPNameIDFormats = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELSAMLENDPOINT
	delete this->_Inst_AssertionConsumerServices;
	this->_Inst_AssertionConsumerServices = NULL;
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */
#ifdef SB_USE_CLASS_TELSAMLENDPOINT
	delete this->_Inst_SingleLogoutServices;
	this->_Inst_SingleLogoutServices = NULL;
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */
#ifdef SB_USE_CLASS_TELSAMLENDPOINT
	delete this->_Inst_ArtifactResolutionServices;
	this->_Inst_ArtifactResolutionServices = NULL;
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_SigningCertificate;
	this->_Inst_SigningCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_EncryptionCertificate;
	this->_Inst_EncryptionCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_MetaSigningCertificate;
	this->_Inst_MetaSigningCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
}
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO */

#ifdef SB_USE_CLASS_TELSAMLSPDATA

void TElSAMLSPData::get_SessionIndex(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLSPData_get_SessionIndex(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-282585837, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLSPData::set_SessionIndex(const std::string &Value)
{
	SBCheckError(TElSAMLSPData_set_SessionIndex(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSAMLSPData::TElSAMLSPData(TElSAMLSPDataHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSAMLSPData::TElSAMLSPData() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLSPData_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLSPDATA */

#ifdef SB_USE_CLASS_TELSAMLIDPCUSTOMAUTHSOURCE

SB_INLINE void TElSAMLIDPCustomAuthSource::Add(const std::string &ID, const std::string &AuthToken)
{
	SBCheckError(TElSAMLIDPCustomAuthSource_Add(_Handle, ID.data(), (int32_t)ID.length(), AuthToken.data(), (int32_t)AuthToken.length()));
}

SB_INLINE void TElSAMLIDPCustomAuthSource::Remove(const std::string &ID)
{
	SBCheckError(TElSAMLIDPCustomAuthSource_Remove(_Handle, ID.data(), (int32_t)ID.length()));
}

bool TElSAMLIDPCustomAuthSource::Check(const std::string &ID, const std::string &AuthToken)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLIDPCustomAuthSource_Check(_Handle, ID.data(), (int32_t)ID.length(), AuthToken.data(), (int32_t)AuthToken.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElSAMLIDPCustomAuthSource::GetSupportedIdentifierTypes(TStringList &OutResult)
{
	SBCheckError(TElSAMLIDPCustomAuthSource_GetSupportedIdentifierTypes(_Handle, OutResult.getHandle()));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

void TElSAMLIDPCustomAuthSource::GetIdentifier(const std::string &ID, const std::string &Format, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIDPCustomAuthSource_GetIdentifier(_Handle, ID.data(), (int32_t)ID.length(), Format.data(), (int32_t)Format.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(801983416, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIDPCustomAuthSource::SetIdentifier(const std::string &ID, const std::string &Format, const std::string &Value)
{
	SBCheckError(TElSAMLIDPCustomAuthSource_SetIdentifier(_Handle, ID.data(), (int32_t)ID.length(), Format.data(), (int32_t)Format.length(), Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT
SB_INLINE TElSAMLAttributeElementHandle TElSAMLIDPCustomAuthSource::GetAttribute(const std::string &ID, const std::string &Format, TElSAMLAttributeElement &Attribute)
{
	TElSAMLAttributeElementHandle OutResult;
	SBCheckError(TElSAMLIDPCustomAuthSource_GetAttribute(_Handle, ID.data(), (int32_t)ID.length(), Format.data(), (int32_t)Format.length(), Attribute.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElSAMLAttributeElementHandle TElSAMLIDPCustomAuthSource::GetAttribute(const std::string &ID, const std::string &Format, TElSAMLAttributeElement *Attribute)
{
	TElSAMLAttributeElementHandle OutResult;
	SBCheckError(TElSAMLIDPCustomAuthSource_GetAttribute(_Handle, ID.data(), (int32_t)ID.length(), Format.data(), (int32_t)Format.length(), (Attribute != NULL) ? Attribute->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT
bool TElSAMLIDPCustomAuthSource::SetAttribute(const std::string &ID, const std::string &Format, TElSAMLAttributeElement &Attribute)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLIDPCustomAuthSource_SetAttribute(_Handle, ID.data(), (int32_t)ID.length(), Format.data(), (int32_t)Format.length(), Attribute.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSAMLIDPCustomAuthSource::SetAttribute(const std::string &ID, const std::string &Format, TElSAMLAttributeElement *Attribute)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLIDPCustomAuthSource_SetAttribute(_Handle, ID.data(), (int32_t)ID.length(), Format.data(), (int32_t)Format.length(), (Attribute != NULL) ? Attribute->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT */

TElSAMLIDPCustomAuthSource::TElSAMLIDPCustomAuthSource(TElSAMLIDPCustomAuthSourceHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElSAMLIDPCustomAuthSource::TElSAMLIDPCustomAuthSource(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLIDPCustomAuthSource_Create(AOwner.getHandle(), &_Handle));
}

TElSAMLIDPCustomAuthSource::TElSAMLIDPCustomAuthSource(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLIDPCustomAuthSource_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLIDPCUSTOMAUTHSOURCE */

#ifdef SB_USE_CLASS_TELSAMLIDRECORD

#ifdef SB_USE_CLASS_TELDICTIONARY
TElDictionary* TElSAMLIDRecord::get_Identifiers()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIDRecord_get_Identifiers(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Identifiers)
		this->_Inst_Identifiers = new TElDictionary(hOutResult, ohFalse);
	else
		this->_Inst_Identifiers->updateHandle(hOutResult);
	return this->_Inst_Identifiers;
}
#endif /* SB_USE_CLASS_TELDICTIONARY */

void TElSAMLIDRecord::get_AuthToken(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIDRecord_get_AuthToken(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-174823222, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIDRecord::set_AuthToken(const std::string &Value)
{
	SBCheckError(TElSAMLIDRecord_set_AuthToken(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLIDRecord::initInstances()
{
#ifdef SB_USE_CLASS_TELDICTIONARY
	this->_Inst_Identifiers = NULL;
#endif /* SB_USE_CLASS_TELDICTIONARY */
}

TElSAMLIDRecord::TElSAMLIDRecord(TElSAMLIDRecordHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElSAMLIDRecord::TElSAMLIDRecord() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLIDRecord_Create(&_Handle));
}

TElSAMLIDRecord::~TElSAMLIDRecord()
{
#ifdef SB_USE_CLASS_TELDICTIONARY
	delete this->_Inst_Identifiers;
	this->_Inst_Identifiers = NULL;
#endif /* SB_USE_CLASS_TELDICTIONARY */
}
#endif /* SB_USE_CLASS_TELSAMLIDRECORD */

#ifdef SB_USE_CLASS_TELSAMLIDPPASSWORDMEMORYAUTHSOURCE

#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElSAMLIDPPasswordMemoryAuthSource::GetSupportedIdentifierTypes(TStringList &OutResult)
{
	SBCheckError(TElSAMLIDPPasswordMemoryAuthSource_GetSupportedIdentifierTypes(_Handle, OutResult.getHandle()));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

void TElSAMLIDPPasswordMemoryAuthSource::GetIdentifier(const std::string &ID, const std::string &Format, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIDPPasswordMemoryAuthSource_GetIdentifier(_Handle, ID.data(), (int32_t)ID.length(), Format.data(), (int32_t)Format.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1141190337, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIDPPasswordMemoryAuthSource::SetIdentifier(const std::string &ID, const std::string &Format, const std::string &Value)
{
	SBCheckError(TElSAMLIDPPasswordMemoryAuthSource_SetIdentifier(_Handle, ID.data(), (int32_t)ID.length(), Format.data(), (int32_t)Format.length(), Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT
SB_INLINE TElSAMLAttributeElementHandle TElSAMLIDPPasswordMemoryAuthSource::GetAttribute(const std::string &ID, const std::string &Format, TElSAMLAttributeElement &Attribute)
{
	TElSAMLAttributeElementHandle OutResult;
	SBCheckError(TElSAMLIDPPasswordMemoryAuthSource_GetAttribute(_Handle, ID.data(), (int32_t)ID.length(), Format.data(), (int32_t)Format.length(), Attribute.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElSAMLAttributeElementHandle TElSAMLIDPPasswordMemoryAuthSource::GetAttribute(const std::string &ID, const std::string &Format, TElSAMLAttributeElement *Attribute)
{
	TElSAMLAttributeElementHandle OutResult;
	SBCheckError(TElSAMLIDPPasswordMemoryAuthSource_GetAttribute(_Handle, ID.data(), (int32_t)ID.length(), Format.data(), (int32_t)Format.length(), (Attribute != NULL) ? Attribute->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT
bool TElSAMLIDPPasswordMemoryAuthSource::SetAttribute(const std::string &ID, const std::string &Format, TElSAMLAttributeElement &Attribute)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLIDPPasswordMemoryAuthSource_SetAttribute(_Handle, ID.data(), (int32_t)ID.length(), Format.data(), (int32_t)Format.length(), Attribute.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSAMLIDPPasswordMemoryAuthSource::SetAttribute(const std::string &ID, const std::string &Format, TElSAMLAttributeElement *Attribute)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLIDPPasswordMemoryAuthSource_SetAttribute(_Handle, ID.data(), (int32_t)ID.length(), Format.data(), (int32_t)Format.length(), (Attribute != NULL) ? Attribute->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT */

SB_INLINE void TElSAMLIDPPasswordMemoryAuthSource::Add(const std::string &ID, const std::string &AuthToken)
{
	SBCheckError(TElSAMLIDPPasswordMemoryAuthSource_Add(_Handle, ID.data(), (int32_t)ID.length(), AuthToken.data(), (int32_t)AuthToken.length()));
}

SB_INLINE void TElSAMLIDPPasswordMemoryAuthSource::Remove(const std::string &ID)
{
	SBCheckError(TElSAMLIDPPasswordMemoryAuthSource_Remove(_Handle, ID.data(), (int32_t)ID.length()));
}

bool TElSAMLIDPPasswordMemoryAuthSource::Check(const std::string &ID, const std::string &AuthToken)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLIDPPasswordMemoryAuthSource_Check(_Handle, ID.data(), (int32_t)ID.length(), AuthToken.data(), (int32_t)AuthToken.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLIDPPasswordMemoryAuthSource::get_OnGetAttribute(TSBSAMLIDPGetAttributeEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIDPPasswordMemoryAuthSource_get_OnGetAttribute(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIDPPasswordMemoryAuthSource::set_OnGetAttribute(TSBSAMLIDPGetAttributeEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIDPPasswordMemoryAuthSource_set_OnGetAttribute(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLIDPPasswordMemoryAuthSource::get_OnSetAttribute(TSBSAMLIDPSetAttributeEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIDPPasswordMemoryAuthSource_get_OnSetAttribute(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIDPPasswordMemoryAuthSource::set_OnSetAttribute(TSBSAMLIDPSetAttributeEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIDPPasswordMemoryAuthSource_set_OnSetAttribute(_Handle, pMethodValue, pDataValue));
}

TElSAMLIDPPasswordMemoryAuthSource::TElSAMLIDPPasswordMemoryAuthSource(TElSAMLIDPPasswordMemoryAuthSourceHandle handle, TElOwnHandle ownHandle) : TElSAMLIDPCustomAuthSource(handle, ownHandle)
{
}

TElSAMLIDPPasswordMemoryAuthSource::TElSAMLIDPPasswordMemoryAuthSource() : TElSAMLIDPCustomAuthSource(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLIDPPasswordMemoryAuthSource_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLIDPPASSWORDMEMORYAUTHSOURCE */

#ifdef SB_USE_CLASS_TELSAMLIDPSSOLINK

void TElSAMLIdPSSOLink::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIdPSSOLink_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-273686382, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIdPSSOLink::set_URL(const std::string &Value)
{
	SBCheckError(TElSAMLIdPSSOLink_set_URL(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLIdPSSOLink::get_RelayState(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIdPSSOLink_get_RelayState(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-434184144, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIdPSSOLink::set_RelayState(const std::string &Value)
{
	SBCheckError(TElSAMLIdPSSOLink_set_RelayState(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSAMLIdPSSOLink::get_SPIndex()
{
	int32_t OutResult;
	SBCheckError(TElSAMLIdPSSOLink_get_SPIndex(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLIdPSSOLink::set_SPIndex(int32_t Value)
{
	SBCheckError(TElSAMLIdPSSOLink_set_SPIndex(_Handle, Value));
}

TElSAMLIdPSSOLink::TElSAMLIdPSSOLink(TElSAMLIdPSSOLinkHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSAMLIdPSSOLink::TElSAMLIdPSSOLink() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLIdPSSOLink_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLIDPSSOLINK */

#ifdef SB_USE_CLASS_TELSAMLIDENTITYPROVIDER

SB_INLINE void TElSAMLIdentityProvider::Open()
{
	SBCheckError(TElSAMLIdentityProvider_Open(_Handle));
}

SB_INLINE void TElSAMLIdentityProvider::DataAvailable()
{
	SBCheckError(TElSAMLIdentityProvider_DataAvailable(_Handle));
}

SB_INLINE void TElSAMLIdentityProvider::Close(bool Silent)
{
	SBCheckError(TElSAMLIdentityProvider_Close(_Handle, (int8_t)Silent));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSAMLIdentityProvider::SaveMetadata(TStream &Strm)
{
	SBCheckError(TElSAMLIdentityProvider_SaveMetadata(_Handle, Strm.getHandle()));
}

SB_INLINE void TElSAMLIdentityProvider::SaveMetadata(TStream *Strm)
{
	SBCheckError(TElSAMLIdentityProvider_SaveMetadata(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO
SB_INLINE int32_t TElSAMLIdentityProvider::AddServiceProvider(TElSAMLServiceProviderInfo &SPInfo)
{
	int32_t OutResult;
	SBCheckError(TElSAMLIdentityProvider_AddServiceProvider(_Handle, SPInfo.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLIdentityProvider::AddServiceProvider(TElSAMLServiceProviderInfo *SPInfo)
{
	int32_t OutResult;
	SBCheckError(TElSAMLIdentityProvider_AddServiceProvider(_Handle, (SPInfo != NULL) ? SPInfo->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO */

SB_INLINE void TElSAMLIdentityProvider::RemoveServiceProvider(int32_t Index)
{
	SBCheckError(TElSAMLIdentityProvider_RemoveServiceProvider(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELSAMLIDPSSOLINK
SB_INLINE int32_t TElSAMLIdentityProvider::AddIdPSSOLink(TElSAMLIdPSSOLink &Link)
{
	int32_t OutResult;
	SBCheckError(TElSAMLIdentityProvider_AddIdPSSOLink(_Handle, Link.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLIdentityProvider::AddIdPSSOLink(TElSAMLIdPSSOLink *Link)
{
	int32_t OutResult;
	SBCheckError(TElSAMLIdentityProvider_AddIdPSSOLink(_Handle, (Link != NULL) ? Link->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLIDPSSOLINK */

SB_INLINE void TElSAMLIdentityProvider::RemoveIdPSSOLink(int32_t Index)
{
	SBCheckError(TElSAMLIdentityProvider_RemoveIdPSSOLink(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO
TElSAMLServiceProviderInfo* TElSAMLIdentityProvider::get_ServiceProviders(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIdentityProvider_get_ServiceProviders(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ServiceProviders)
		this->_Inst_ServiceProviders = new TElSAMLServiceProviderInfo(hOutResult, ohFalse);
	else
		this->_Inst_ServiceProviders->updateHandle(hOutResult);
	return this->_Inst_ServiceProviders;
}
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO */

SB_INLINE int32_t TElSAMLIdentityProvider::get_ServiceProviderCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLIdentityProvider_get_ServiceProviderCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSAMLIDPSSOLINK
TElSAMLIdPSSOLink* TElSAMLIdentityProvider::get_IdPSSOLinks(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIdentityProvider_get_IdPSSOLinks(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IdPSSOLinks)
		this->_Inst_IdPSSOLinks = new TElSAMLIdPSSOLink(hOutResult, ohFalse);
	else
		this->_Inst_IdPSSOLinks->updateHandle(hOutResult);
	return this->_Inst_IdPSSOLinks;
}
#endif /* SB_USE_CLASS_TELSAMLIDPSSOLINK */

SB_INLINE int32_t TElSAMLIdentityProvider::get_IdPSSOLinkCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLIdentityProvider_get_IdPSSOLinkCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELHTTPSSERVER
TElHTTPSServer* TElSAMLIdentityProvider::get_Control()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIdentityProvider_get_Control(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Control)
		this->_Inst_Control = new TElHTTPSServer(hOutResult, ohFalse);
	else
		this->_Inst_Control->updateHandle(hOutResult);
	return this->_Inst_Control;
}
#endif /* SB_USE_CLASS_TELHTTPSSERVER */

bool TElSAMLIdentityProvider::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLIdentityProvider_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSAMLIdentityProvider::get_SupportedAuthnContextClasses()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIdentityProvider_get_SupportedAuthnContextClasses(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SupportedAuthnContextClasses)
		this->_Inst_SupportedAuthnContextClasses = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_SupportedAuthnContextClasses->updateHandle(hOutResult);
	return this->_Inst_SupportedAuthnContextClasses;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSAMLIdentityProvider::get_SupportedAuthnContextClasses()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIdentityProvider_get_SupportedAuthnContextClasses(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SupportedAuthnContextClasses)
		this->_Inst_SupportedAuthnContextClasses = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_SupportedAuthnContextClasses->updateHandle(hOutResult);
	return this->_Inst_SupportedAuthnContextClasses;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElSAMLIdentityProvider::get_SourceID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSAMLIdentityProvider_get_SourceID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1392219731, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIdentityProvider::set_SourceID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_SourceID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElSAMLIdentityProvider::get_SendBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElSAMLIdentityProvider_get_SendBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLIdentityProvider::set_SendBufferSize(int32_t Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_SendBufferSize(_Handle, Value));
}

void TElSAMLIdentityProvider::get_ServerName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIdentityProvider_get_ServerName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1457694327, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIdentityProvider::set_ServerName(const std::string &Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_ServerName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLIdentityProvider::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIdentityProvider_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-367659450, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIdentityProvider::set_URL(const std::string &Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_URL(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLIdentityProvider::get_SingleSignOnService(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIdentityProvider_get_SingleSignOnService(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2095491971, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIdentityProvider::set_SingleSignOnService(const std::string &Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_SingleSignOnService(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLIdentityProvider::get_SingleLogoutService(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIdentityProvider_get_SingleLogoutService(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1190498019, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIdentityProvider::set_SingleLogoutService(const std::string &Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_SingleLogoutService(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLIdentityProvider::get_ArtifactResolutionService(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIdentityProvider_get_ArtifactResolutionService(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-625457696, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIdentityProvider::set_ArtifactResolutionService(const std::string &Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_ArtifactResolutionService(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLIdentityProvider::get_AttributeQueryService(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIdentityProvider_get_AttributeQueryService(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1254534828, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIdentityProvider::set_AttributeQueryService(const std::string &Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_AttributeQueryService(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLIdentityProvider::get_SessionCookieName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIdentityProvider_get_SessionCookieName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-242824402, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIdentityProvider::set_SessionCookieName(const std::string &Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_SessionCookieName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElSAMLIdentityProvider::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIdentityProvider_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElSAMLIdentityProvider::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLIdentityProvider::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

SBSAMLIdentityProvider_TSBSAMLAccessLevel TElSAMLIdentityProvider::get_AccessLevel()
{
	SBSAMLIdentityProvider_TSBSAMLAccessLevelRaw OutResultRaw = 0;
	SBCheckError(TElSAMLIdentityProvider_get_AccessLevel(_Handle, &OutResultRaw));
	return (SBSAMLIdentityProvider_TSBSAMLAccessLevel)OutResultRaw;
}

SB_INLINE void TElSAMLIdentityProvider::set_AccessLevel(SBSAMLIdentityProvider_TSBSAMLAccessLevel Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_AccessLevel(_Handle, (SBSAMLIdentityProvider_TSBSAMLAccessLevelRaw)Value));
}

SB_INLINE int32_t TElSAMLIdentityProvider::get_SessionTTL()
{
	int32_t OutResult;
	SBCheckError(TElSAMLIdentityProvider_get_SessionTTL(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLIdentityProvider::set_SessionTTL(int32_t Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_SessionTTL(_Handle, Value));
}

SB_INLINE int32_t TElSAMLIdentityProvider::get_SAMLSessionTTL()
{
	int32_t OutResult;
	SBCheckError(TElSAMLIdentityProvider_get_SAMLSessionTTL(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLIdentityProvider::set_SAMLSessionTTL(int32_t Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_SAMLSessionTTL(_Handle, Value));
}

SB_INLINE int32_t TElSAMLIdentityProvider::get_MaxIssueInstantTimeDiff()
{
	int32_t OutResult;
	SBCheckError(TElSAMLIdentityProvider_get_MaxIssueInstantTimeDiff(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLIdentityProvider::set_MaxIssueInstantTimeDiff(int32_t Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_MaxIssueInstantTimeDiff(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMSESSIONMANAGER
TElCustomSessionManager* TElSAMLIdentityProvider::get_SessionManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIdentityProvider_get_SessionManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SessionManager)
		this->_Inst_SessionManager = new TElCustomSessionManager(hOutResult, ohFalse);
	else
		this->_Inst_SessionManager->updateHandle(hOutResult);
	return this->_Inst_SessionManager;
}

SB_INLINE void TElSAMLIdentityProvider::set_SessionManager(TElCustomSessionManager &Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_SessionManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLIdentityProvider::set_SessionManager(TElCustomSessionManager *Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_SessionManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMSESSIONMANAGER */

#ifdef SB_USE_CLASS_TELSAMLIDPCUSTOMAUTHSOURCE
TElSAMLIDPCustomAuthSource* TElSAMLIdentityProvider::get_AuthSource()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIdentityProvider_get_AuthSource(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AuthSource)
		this->_Inst_AuthSource = new TElSAMLIDPCustomAuthSource(hOutResult, ohFalse);
	else
		this->_Inst_AuthSource->updateHandle(hOutResult);
	return this->_Inst_AuthSource;
}

SB_INLINE void TElSAMLIdentityProvider::set_AuthSource(TElSAMLIDPCustomAuthSource &Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_AuthSource(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLIdentityProvider::set_AuthSource(TElSAMLIDPCustomAuthSource *Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_AuthSource(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLIDPCUSTOMAUTHSOURCE */

bool TElSAMLIdentityProvider::get_WantAuthnRequestsSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLIdentityProvider_get_WantAuthnRequestsSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLIdentityProvider::set_WantAuthnRequestsSigned(bool Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_WantAuthnRequestsSigned(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElSAMLIdentityProvider::get_SigningCertificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIdentityProvider_get_SigningCertificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SigningCertificate)
		this->_Inst_SigningCertificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_SigningCertificate->updateHandle(hOutResult);
	return this->_Inst_SigningCertificate;
}

SB_INLINE void TElSAMLIdentityProvider::set_SigningCertificate(TElX509Certificate &Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_SigningCertificate(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLIdentityProvider::set_SigningCertificate(TElX509Certificate *Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_SigningCertificate(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElSAMLIdentityProvider::get_EncryptionCertificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIdentityProvider_get_EncryptionCertificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptionCertificate)
		this->_Inst_EncryptionCertificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_EncryptionCertificate->updateHandle(hOutResult);
	return this->_Inst_EncryptionCertificate;
}

SB_INLINE void TElSAMLIdentityProvider::set_EncryptionCertificate(TElX509Certificate &Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_EncryptionCertificate(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLIdentityProvider::set_EncryptionCertificate(TElX509Certificate *Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_EncryptionCertificate(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElSAMLIdentityProvider::get_MetaSigningCertificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIdentityProvider_get_MetaSigningCertificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_MetaSigningCertificate)
		this->_Inst_MetaSigningCertificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_MetaSigningCertificate->updateHandle(hOutResult);
	return this->_Inst_MetaSigningCertificate;
}

SB_INLINE void TElSAMLIdentityProvider::set_MetaSigningCertificate(TElX509Certificate &Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_MetaSigningCertificate(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLIdentityProvider::set_MetaSigningCertificate(TElX509Certificate *Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_MetaSigningCertificate(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElSAMLIdentityProvider::get_ConfirmationCertificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIdentityProvider_get_ConfirmationCertificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ConfirmationCertificate)
		this->_Inst_ConfirmationCertificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_ConfirmationCertificate->updateHandle(hOutResult);
	return this->_Inst_ConfirmationCertificate;
}

SB_INLINE void TElSAMLIdentityProvider::set_ConfirmationCertificate(TElX509Certificate &Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_ConfirmationCertificate(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLIdentityProvider::set_ConfirmationCertificate(TElX509Certificate *Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_ConfirmationCertificate(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

TSBSAMLBindingTypes TElSAMLIdentityProvider::get_SingleLogoutServiceBindings()
{
	TSBSAMLBindingTypesRaw OutResultRaw = 0;
	SBCheckError(TElSAMLIdentityProvider_get_SingleLogoutServiceBindings(_Handle, &OutResultRaw));
	return (TSBSAMLBindingTypes)OutResultRaw;
}

SB_INLINE void TElSAMLIdentityProvider::set_SingleLogoutServiceBindings(TSBSAMLBindingTypes Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_SingleLogoutServiceBindings(_Handle, (TSBSAMLBindingTypesRaw)Value));
}

TSBSAMLBindingTypes TElSAMLIdentityProvider::get_SingleSignOnServiceBindings()
{
	TSBSAMLBindingTypesRaw OutResultRaw = 0;
	SBCheckError(TElSAMLIdentityProvider_get_SingleSignOnServiceBindings(_Handle, &OutResultRaw));
	return (TSBSAMLBindingTypes)OutResultRaw;
}

SB_INLINE void TElSAMLIdentityProvider::set_SingleSignOnServiceBindings(TSBSAMLBindingTypes Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_SingleSignOnServiceBindings(_Handle, (TSBSAMLBindingTypesRaw)Value));
}

TSBSAMLBindingTypes TElSAMLIdentityProvider::get_ArtifactResolutionServiceBindings()
{
	TSBSAMLBindingTypesRaw OutResultRaw = 0;
	SBCheckError(TElSAMLIdentityProvider_get_ArtifactResolutionServiceBindings(_Handle, &OutResultRaw));
	return (TSBSAMLBindingTypes)OutResultRaw;
}

void TElSAMLIdentityProvider::get_MetadataURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIdentityProvider_get_MetadataURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1620593321, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIdentityProvider::set_MetadataURL(const std::string &Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_MetadataURL(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLIdentityProvider::get_AuthFormTemplate(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIdentityProvider_get_AuthFormTemplate(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-322829925, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIdentityProvider::set_AuthFormTemplate(const std::string &Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_AuthFormTemplate(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSAMLIdentityProvider::get_LoginAttemptsLimitL()
{
	int32_t OutResult;
	SBCheckError(TElSAMLIdentityProvider_get_LoginAttemptsLimitL(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLIdentityProvider::set_LoginAttemptsLimitL(int32_t Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_LoginAttemptsLimitL(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO
TElSAMLServiceProviderInfo* TElSAMLIdentityProvider::get_CurrentSP()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIdentityProvider_get_CurrentSP(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CurrentSP)
		this->_Inst_CurrentSP = new TElSAMLServiceProviderInfo(hOutResult, ohFalse);
	else
		this->_Inst_CurrentSP->updateHandle(hOutResult);
	return this->_Inst_CurrentSP;
}
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO */

SB_INLINE int32_t TElSAMLIdentityProvider::get_AssertionsTTL()
{
	int32_t OutResult;
	SBCheckError(TElSAMLIdentityProvider_get_AssertionsTTL(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLIdentityProvider::set_AssertionsTTL(int32_t Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_AssertionsTTL(_Handle, Value));
}

bool TElSAMLIdentityProvider::get_AssertionsOneTimeUse()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLIdentityProvider_get_AssertionsOneTimeUse(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLIdentityProvider::set_AssertionsOneTimeUse(bool Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_AssertionsOneTimeUse(_Handle, (int8_t)Value));
}

bool TElSAMLIdentityProvider::get_SignResponse()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLIdentityProvider_get_SignResponse(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLIdentityProvider::set_SignResponse(bool Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_SignResponse(_Handle, (int8_t)Value));
}

bool TElSAMLIdentityProvider::get_SignAssertions()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLIdentityProvider_get_SignAssertions(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLIdentityProvider::set_SignAssertions(bool Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_SignAssertions(_Handle, (int8_t)Value));
}

TSBSAMLBindingType TElSAMLIdentityProvider::get_PrefferedSingleSignOnResponseBinding()
{
	TSBSAMLBindingTypeRaw OutResultRaw = 0;
	SBCheckError(TElSAMLIdentityProvider_get_PrefferedSingleSignOnResponseBinding(_Handle, &OutResultRaw));
	return (TSBSAMLBindingType)OutResultRaw;
}

SB_INLINE void TElSAMLIdentityProvider::set_PrefferedSingleSignOnResponseBinding(TSBSAMLBindingType Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_PrefferedSingleSignOnResponseBinding(_Handle, (TSBSAMLBindingTypeRaw)Value));
}

TSBSAMLBindingType TElSAMLIdentityProvider::get_PrefferedSingleLogoutResponseBinding()
{
	TSBSAMLBindingTypeRaw OutResultRaw = 0;
	SBCheckError(TElSAMLIdentityProvider_get_PrefferedSingleLogoutResponseBinding(_Handle, &OutResultRaw));
	return (TSBSAMLBindingType)OutResultRaw;
}

SB_INLINE void TElSAMLIdentityProvider::set_PrefferedSingleLogoutResponseBinding(TSBSAMLBindingType Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_PrefferedSingleLogoutResponseBinding(_Handle, (TSBSAMLBindingTypeRaw)Value));
}

bool TElSAMLIdentityProvider::get_BlockedClientIP()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLIdentityProvider_get_BlockedClientIP(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLIdentityProvider::set_BlockedClientIP(bool Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_BlockedClientIP(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE
TElCustomArtifactStorage* TElSAMLIdentityProvider::get_ArtifactStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLIdentityProvider_get_ArtifactStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ArtifactStorage)
		this->_Inst_ArtifactStorage = new TElCustomArtifactStorage(hOutResult, ohFalse);
	else
		this->_Inst_ArtifactStorage->updateHandle(hOutResult);
	return this->_Inst_ArtifactStorage;
}

SB_INLINE void TElSAMLIdentityProvider::set_ArtifactStorage(TElCustomArtifactStorage &Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_ArtifactStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLIdentityProvider::set_ArtifactStorage(TElCustomArtifactStorage *Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_ArtifactStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE */

bool TElSAMLIdentityProvider::get_SignMetadata()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLIdentityProvider_get_SignMetadata(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLIdentityProvider::set_SignMetadata(bool Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_SignMetadata(_Handle, (int8_t)Value));
}

bool TElSAMLIdentityProvider::get_EncryptAssertions()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLIdentityProvider_get_EncryptAssertions(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLIdentityProvider::set_EncryptAssertions(bool Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_EncryptAssertions(_Handle, (int8_t)Value));
}

void TElSAMLIdentityProvider::get_DefaultPassiveAuthnContextClassRef(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIdentityProvider_get_DefaultPassiveAuthnContextClassRef(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1424669546, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIdentityProvider::set_DefaultPassiveAuthnContextClassRef(const std::string &Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_DefaultPassiveAuthnContextClassRef(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLIdentityProvider::get_SubjectConfirmationMethod(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIdentityProvider_get_SubjectConfirmationMethod(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(75511354, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIdentityProvider::set_SubjectConfirmationMethod(const std::string &Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_SubjectConfirmationMethod(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLIdentityProvider::get_DefaultNameIDPolicyFormat(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIdentityProvider_get_DefaultNameIDPolicyFormat(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(600726339, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIdentityProvider::set_DefaultNameIDPolicyFormat(const std::string &Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_DefaultNameIDPolicyFormat(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSAMLIdentityProvider::get_NotBeforeTimeout()
{
	int32_t OutResult;
	SBCheckError(TElSAMLIdentityProvider_get_NotBeforeTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLIdentityProvider::set_NotBeforeTimeout(int32_t Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_NotBeforeTimeout(_Handle, Value));
}

bool TElSAMLIdentityProvider::get_AllowIDPSSO()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLIdentityProvider_get_AllowIDPSSO(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLIdentityProvider::set_AllowIDPSSO(bool Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_AllowIDPSSO(_Handle, (int8_t)Value));
}

void TElSAMLIdentityProvider::get_IDPSSOPage(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLIdentityProvider_get_IDPSSOPage(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-344523271, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLIdentityProvider::set_IDPSSOPage(const std::string &Value)
{
	SBCheckError(TElSAMLIdentityProvider_set_IDPSSOPage(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElSAMLIdentityProvider::get_OnSessionCreate(SBSAMLIdentityProvider_TSBSAMLSessionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIdentityProvider_get_OnSessionCreate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIdentityProvider::set_OnSessionCreate(SBSAMLIdentityProvider_TSBSAMLSessionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIdentityProvider_set_OnSessionCreate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLIdentityProvider::get_OnSessionDestroy(SBSAMLIdentityProvider_TSBSAMLSessionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIdentityProvider_get_OnSessionDestroy(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIdentityProvider::set_OnSessionDestroy(SBSAMLIdentityProvider_TSBSAMLSessionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIdentityProvider_set_OnSessionDestroy(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLIdentityProvider::get_OnSessionChanged(SBSAMLIdentityProvider_TSBSAMLSessionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIdentityProvider_get_OnSessionChanged(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIdentityProvider::set_OnSessionChanged(SBSAMLIdentityProvider_TSBSAMLSessionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIdentityProvider_set_OnSessionChanged(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLIdentityProvider::get_OnLogout(SBSAMLIdentityProvider_TSBSAMLLogoutEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIdentityProvider_get_OnLogout(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIdentityProvider::set_OnLogout(SBSAMLIdentityProvider_TSBSAMLLogoutEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIdentityProvider_set_OnLogout(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLIdentityProvider::get_OnBeforeHTTPSServerUse(SBSAMLIdentityProvider_TSBSAMLBeforeHTTPSServerUseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIdentityProvider_get_OnBeforeHTTPSServerUse(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIdentityProvider::set_OnBeforeHTTPSServerUse(SBSAMLIdentityProvider_TSBSAMLBeforeHTTPSServerUseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIdentityProvider_set_OnBeforeHTTPSServerUse(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLIdentityProvider::get_OnRequestPrepared(TSBSAMLRequestPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIdentityProvider_get_OnRequestPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIdentityProvider::set_OnRequestPrepared(TSBSAMLRequestPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIdentityProvider_set_OnRequestPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLIdentityProvider::get_OnResponseReceived(TSBSAMLResponseReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIdentityProvider_get_OnResponseReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIdentityProvider::set_OnResponseReceived(TSBSAMLResponseReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIdentityProvider_set_OnResponseReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLIdentityProvider::get_OnResponsePrepared(TSBSAMLResponsePreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIdentityProvider_get_OnResponsePrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIdentityProvider::set_OnResponsePrepared(TSBSAMLResponsePreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIdentityProvider_set_OnResponsePrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLIdentityProvider::get_OnMetadataPrepared(TSBSAMLMetadataPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIdentityProvider_get_OnMetadataPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIdentityProvider::set_OnMetadataPrepared(TSBSAMLMetadataPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIdentityProvider_set_OnMetadataPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLIdentityProvider::get_OnChangeSessionStage(TSBSAMLChangeIDPSessionStageEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIdentityProvider_get_OnChangeSessionStage(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIdentityProvider::set_OnChangeSessionStage(TSBSAMLChangeIDPSessionStageEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIdentityProvider_set_OnChangeSessionStage(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLIdentityProvider::get_OnSend(TSBSendEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIdentityProvider_get_OnSend(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIdentityProvider::set_OnSend(TSBSendEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIdentityProvider_set_OnSend(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLIdentityProvider::get_OnReceive(TSBReceiveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIdentityProvider_get_OnReceive(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIdentityProvider::set_OnReceive(TSBReceiveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIdentityProvider_set_OnReceive(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLIdentityProvider::get_OnOpenConnection(TSBOpenConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIdentityProvider_get_OnOpenConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIdentityProvider::set_OnOpenConnection(TSBOpenConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIdentityProvider_set_OnOpenConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLIdentityProvider::get_OnSSLError(TSBErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIdentityProvider_get_OnSSLError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIdentityProvider::set_OnSSLError(TSBErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIdentityProvider_set_OnSSLError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLIdentityProvider::get_OnCloseConnection(TSBCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIdentityProvider_get_OnCloseConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIdentityProvider::set_OnCloseConnection(TSBCloseConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIdentityProvider_set_OnCloseConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLIdentityProvider::get_OnCertificateValidate(TSBCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIdentityProvider_get_OnCertificateValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIdentityProvider::set_OnCertificateValidate(TSBCertificateValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIdentityProvider_set_OnCertificateValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLIdentityProvider::get_OnChooseAuthnContext(TSBSAMLChooseAuthnContext &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIdentityProvider_get_OnChooseAuthnContext(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIdentityProvider::set_OnChooseAuthnContext(TSBSAMLChooseAuthnContext pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIdentityProvider_set_OnChooseAuthnContext(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLIdentityProvider::get_OnBeforeHTTPSClientUse(TSBSAMLBeforeHTTPSClientUseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIdentityProvider_get_OnBeforeHTTPSClientUse(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIdentityProvider::set_OnBeforeHTTPSClientUse(TSBSAMLBeforeHTTPSClientUseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIdentityProvider_set_OnBeforeHTTPSClientUse(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLIdentityProvider::get_OnBindingXMLPrepared(TSBSAMLBindingXMLPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIdentityProvider_get_OnBindingXMLPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIdentityProvider::set_OnBindingXMLPrepared(TSBSAMLBindingXMLPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIdentityProvider_set_OnBindingXMLPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLIdentityProvider::get_OnBeforeBindingUse(TSBSAMLBeforeBindingUseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIdentityProvider_get_OnBeforeBindingUse(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIdentityProvider::set_OnBeforeBindingUse(TSBSAMLBeforeBindingUseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIdentityProvider_set_OnBeforeBindingUse(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLIdentityProvider::get_OnChooseNameIDPolicyFormat(TSBSAMLChooseNameIDPolicyFormatEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIdentityProvider_get_OnChooseNameIDPolicyFormat(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIdentityProvider::set_OnChooseNameIDPolicyFormat(TSBSAMLChooseNameIDPolicyFormatEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIdentityProvider_set_OnChooseNameIDPolicyFormat(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLIdentityProvider::get_OnResponseStatusCode(TSBSAMLResponseStatusCodeEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIdentityProvider_get_OnResponseStatusCode(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIdentityProvider::set_OnResponseStatusCode(TSBSAMLResponseStatusCodeEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIdentityProvider_set_OnResponseStatusCode(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLIdentityProvider::get_OnPageContent(TSBSAMLPageContentEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLIdentityProvider_get_OnPageContent(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLIdentityProvider::set_OnPageContent(TSBSAMLPageContentEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLIdentityProvider_set_OnPageContent(_Handle, pMethodValue, pDataValue));
}

void TElSAMLIdentityProvider::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO
	this->_Inst_ServiceProviders = NULL;
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO */
#ifdef SB_USE_CLASS_TELSAMLIDPSSOLINK
	this->_Inst_IdPSSOLinks = NULL;
#endif /* SB_USE_CLASS_TELSAMLIDPSSOLINK */
#ifdef SB_USE_CLASS_TELHTTPSSERVER
	this->_Inst_Control = NULL;
#endif /* SB_USE_CLASS_TELHTTPSSERVER */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_SupportedAuthnContextClasses = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_SupportedAuthnContextClasses = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMSESSIONMANAGER
	this->_Inst_SessionManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSESSIONMANAGER */
#ifdef SB_USE_CLASS_TELSAMLIDPCUSTOMAUTHSOURCE
	this->_Inst_AuthSource = NULL;
#endif /* SB_USE_CLASS_TELSAMLIDPCUSTOMAUTHSOURCE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_SigningCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_EncryptionCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_MetaSigningCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_ConfirmationCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO
	this->_Inst_CurrentSP = NULL;
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO */
#ifdef SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE
	this->_Inst_ArtifactStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE */
}

TElSAMLIdentityProvider::TElSAMLIdentityProvider(TElSAMLIdentityProviderHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElSAMLIdentityProvider::TElSAMLIdentityProvider(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLIdentityProvider_Create(AOwner.getHandle(), &_Handle));
}

TElSAMLIdentityProvider::TElSAMLIdentityProvider(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLIdentityProvider_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSAMLIdentityProvider::~TElSAMLIdentityProvider()
{
#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO
	delete this->_Inst_ServiceProviders;
	this->_Inst_ServiceProviders = NULL;
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO */
#ifdef SB_USE_CLASS_TELSAMLIDPSSOLINK
	delete this->_Inst_IdPSSOLinks;
	this->_Inst_IdPSSOLinks = NULL;
#endif /* SB_USE_CLASS_TELSAMLIDPSSOLINK */
#ifdef SB_USE_CLASS_TELHTTPSSERVER
	delete this->_Inst_Control;
	this->_Inst_Control = NULL;
#endif /* SB_USE_CLASS_TELHTTPSSERVER */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_SupportedAuthnContextClasses;
	this->_Inst_SupportedAuthnContextClasses = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_SupportedAuthnContextClasses;
	this->_Inst_SupportedAuthnContextClasses = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMSESSIONMANAGER
	delete this->_Inst_SessionManager;
	this->_Inst_SessionManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSESSIONMANAGER */
#ifdef SB_USE_CLASS_TELSAMLIDPCUSTOMAUTHSOURCE
	delete this->_Inst_AuthSource;
	this->_Inst_AuthSource = NULL;
#endif /* SB_USE_CLASS_TELSAMLIDPCUSTOMAUTHSOURCE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_SigningCertificate;
	this->_Inst_SigningCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_EncryptionCertificate;
	this->_Inst_EncryptionCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_MetaSigningCertificate;
	this->_Inst_MetaSigningCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_ConfirmationCertificate;
	this->_Inst_ConfirmationCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO
	delete this->_Inst_CurrentSP;
	this->_Inst_CurrentSP = NULL;
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO */
#ifdef SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE
	delete this->_Inst_ArtifactStorage;
	this->_Inst_ArtifactStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE */
}
#endif /* SB_USE_CLASS_TELSAMLIDENTITYPROVIDER */

};	/* namespace SecureBlackbox */
