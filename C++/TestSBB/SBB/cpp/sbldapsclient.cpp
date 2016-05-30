#include "sbldapsclient.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELLDAPSSEARCHFILTER

void TElLDAPSSearchFilter::ToString(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPSSearchFilter_ToString(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(63601799, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElLDAPSSearchFilter::AddCondition(TSBLDAPSLogicalOperator LogicalOperator, const std::string &Attribute, TSBLDAPSEquality Equality, const std::string &Value)
{
	SBCheckError(TElLDAPSSearchFilter_AddCondition(_Handle, (TSBLDAPSLogicalOperatorRaw)LogicalOperator, Attribute.data(), (int32_t)Attribute.length(), (TSBLDAPSEqualityRaw)Equality, Value.data(), (int32_t)Value.length()));
}

bool TElLDAPSSearchFilter::get_IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElLDAPSSearchFilter_get_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TElLDAPSSearchFilter::TElLDAPSSearchFilter(TElLDAPSSearchFilterHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElLDAPSSearchFilter::TElLDAPSSearchFilter() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLDAPSSearchFilter_Create(&_Handle));
}

TElLDAPSSearchFilter::TElLDAPSSearchFilter(TSBLDAPSLogicalOperator LogicalOperator, const std::string &Attribute, TSBLDAPSEquality Equality, const std::string &Value) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLDAPSSearchFilter_Create_1((TSBLDAPSLogicalOperatorRaw)LogicalOperator, Attribute.data(), (int32_t)Attribute.length(), (TSBLDAPSEqualityRaw)Equality, Value.data(), (int32_t)Value.length(), &_Handle));
}

#endif /* SB_USE_CLASS_TELLDAPSSEARCHFILTER */

#ifdef SB_USE_CLASS_TELLDAPRESPONSE

#ifdef SB_USE_CLASS_TELLDAPMESSAGE
void TElLDAPResponse::Add(TElLDAPMessage &Msg)
{
	TElClassHandle hMsg = Msg.getHandle();
	SBCheckError(TElLDAPResponse_Add(_Handle, &hMsg));
	Msg.updateHandle(hMsg);
}
#endif /* SB_USE_CLASS_TELLDAPMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPMESSAGE
void TElLDAPResponse::Remove(TElLDAPMessage &Msg)
{
	TElClassHandle hMsg = Msg.getHandle();
	SBCheckError(TElLDAPResponse_Remove(_Handle, &hMsg));
	Msg.updateHandle(hMsg);
}
#endif /* SB_USE_CLASS_TELLDAPMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPMESSAGE
TElLDAPMessage* TElLDAPResponse::get_Messages(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElLDAPResponse_get_Messages(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Messages)
		this->_Inst_Messages = new TElLDAPMessage(hOutResult, ohFalse);
	else
		this->_Inst_Messages->updateHandle(hOutResult);
	return this->_Inst_Messages;
}
#endif /* SB_USE_CLASS_TELLDAPMESSAGE */

SB_INLINE int32_t TElLDAPResponse::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElLDAPResponse_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElLDAPResponse::initInstances()
{
#ifdef SB_USE_CLASS_TELLDAPMESSAGE
	this->_Inst_Messages = NULL;
#endif /* SB_USE_CLASS_TELLDAPMESSAGE */
}

TElLDAPResponse::TElLDAPResponse(TElLDAPResponseHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElLDAPResponse::TElLDAPResponse() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElLDAPResponse_Create(&_Handle));
}

TElLDAPResponse::~TElLDAPResponse()
{
#ifdef SB_USE_CLASS_TELLDAPMESSAGE
	delete this->_Inst_Messages;
	this->_Inst_Messages = NULL;
#endif /* SB_USE_CLASS_TELLDAPMESSAGE */
}
#endif /* SB_USE_CLASS_TELLDAPRESPONSE */

#ifdef SB_USE_CLASS_TELLDAPURL

void TElLDAPURL::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPURL_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-483263983, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElLDAPURL::get_Host(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPURL_get_Host(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-349866096, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE uint16_t TElLDAPURL::get_Port()
{
	uint16_t OutResult;
	SBCheckError(TElLDAPURL_get_Port(_Handle, &OutResult));
	return OutResult;
}

void TElLDAPURL::get_DN(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPURL_get_DN(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(355040411, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElLDAPURL::get_Attributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElLDAPURL_get_Attributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Attributes)
		this->_Inst_Attributes = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Attributes->updateHandle(hOutResult);
	return this->_Inst_Attributes;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElLDAPURL::get_Attributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElLDAPURL_get_Attributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Attributes)
		this->_Inst_Attributes = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Attributes->updateHandle(hOutResult);
	return this->_Inst_Attributes;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

TSBLDAPScope TElLDAPURL::get_Scope()
{
	TSBLDAPScopeRaw OutResultRaw = 0;
	SBCheckError(TElLDAPURL_get_Scope(_Handle, &OutResultRaw));
	return (TSBLDAPScope)OutResultRaw;
}

void TElLDAPURL::get_Filter(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPURL_get_Filter(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1533945525, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElLDAPURL::get_Extensions(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPURL_get_Extensions(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(698865332, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElLDAPURL::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElLDAPURL::TElLDAPURL(TElLDAPURLHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElLDAPURL::TElLDAPURL(const std::string &URL) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElLDAPURL_Create(URL.data(), (int32_t)URL.length(), &_Handle));
}

TElLDAPURL::~TElLDAPURL()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Attributes;
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Attributes;
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELLDAPURL */

#ifdef SB_USE_CLASS_TELLDAPSCLIENT

SB_INLINE void TElLDAPSClient::Bind()
{
	SBCheckError(TElLDAPSClient_Bind(_Handle));
}

SB_INLINE void TElLDAPSClient::Unbind()
{
	SBCheckError(TElLDAPSClient_Unbind(_Handle));
}

#ifdef SB_USE_CLASSES_TELLDAPRESPONSE_AND_TSTRINGLIST
SB_INLINE TElLDAPResponseHandle TElLDAPSClient::Search(const std::string &BaseDN, TSBLDAPScope Scope, const std::string &Filter, const TStringList &Attrs, bool AttrsOnly)
{
	TElLDAPResponseHandle OutResult;
	SBCheckError(TElLDAPSClient_Search(_Handle, BaseDN.data(), (int32_t)BaseDN.length(), (TSBLDAPScopeRaw)Scope, Filter.data(), (int32_t)Filter.length(), Attrs.getHandle(), (int8_t)AttrsOnly, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELLDAPRESPONSE_AND_TSTRINGLIST */

#ifdef SB_USE_CLASSES_TELLDAPRESPONSE_AND_TELLDAPSSEARCHFILTER_AND_TSTRINGLIST
SB_INLINE TElLDAPResponseHandle TElLDAPSClient::Search(const std::string &BaseDN, TSBLDAPScope Scope, const TElLDAPSSearchFilter &Filter, const TStringList &Attrs, bool AttrsOnly)
{
	TElLDAPResponseHandle OutResult;
	SBCheckError(TElLDAPSClient_Search_1(_Handle, BaseDN.data(), (int32_t)BaseDN.length(), (TSBLDAPScopeRaw)Scope, Filter.getHandle(), Attrs.getHandle(), (int8_t)AttrsOnly, &OutResult));
	return OutResult;
}

SB_INLINE TElLDAPResponseHandle TElLDAPSClient::Search(const std::string &BaseDN, TSBLDAPScope Scope, const TElLDAPSSearchFilter *Filter, const TStringList &Attrs, bool AttrsOnly)
{
	TElLDAPResponseHandle OutResult;
	SBCheckError(TElLDAPSClient_Search_1(_Handle, BaseDN.data(), (int32_t)BaseDN.length(), (TSBLDAPScopeRaw)Scope, (Filter != NULL) ? Filter->getHandle() : SB_NULL_HANDLE, Attrs.getHandle(), (int8_t)AttrsOnly, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELLDAPRESPONSE_AND_TELLDAPSSEARCHFILTER_AND_TSTRINGLIST */

#ifdef SB_USE_CLASS_TELLDAPRESPONSE
SB_INLINE TElLDAPResponseHandle TElLDAPSClient::Search()
{
	TElLDAPResponseHandle OutResult;
	SBCheckError(TElLDAPSClient_Search_2(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELLDAPRESPONSE */

#ifdef SB_USE_CLASS_TELLDAPRESPONSE
SB_INLINE TElLDAPResponseHandle TElLDAPSClient::SearchURL(const std::string &URL)
{
	TElLDAPResponseHandle OutResult;
	SBCheckError(TElLDAPSClient_SearchURL(URL.data(), (int32_t)URL.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELLDAPRESPONSE */

#ifdef SB_USE_CLASS_TELLDAPRESPONSE
SB_INLINE TElLDAPResponseHandle TElLDAPSClient::SearchURL_Inst(const std::string &URL)
{
	TElLDAPResponseHandle OutResult;
	SBCheckError(TElLDAPSClient_SearchURL_1(_Handle, URL.data(), (int32_t)URL.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELLDAPRESPONSE */

SB_INLINE void TElLDAPSClient::Remove(const std::string &DN)
{
	SBCheckError(TElLDAPSClient_Remove(_Handle, DN.data(), (int32_t)DN.length()));
}

#ifdef SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE
SB_INLINE void TElLDAPSClient::Add(const std::string &DN, const std::vector<TElLDAPPartialAttributeHandle> &Attrs)
{
	SBCheckError(TElLDAPSClient_Add(_Handle, DN.data(), (int32_t)DN.length(), SB_STD_VECTOR_FRONT_ADR(Attrs), (int32_t)Attrs.size()));
}
#endif /* SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE */

#ifdef SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE
SB_INLINE void TElLDAPSClient::Modify(const std::string &DN, const std::vector<TElLDAPPartialAttributeHandle> &Attrs)
{
	SBCheckError(TElLDAPSClient_Modify(_Handle, DN.data(), (int32_t)DN.length(), SB_STD_VECTOR_FRONT_ADR(Attrs), (int32_t)Attrs.size()));
}
#endif /* SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE */

SB_INLINE int32_t TElLDAPSClient::get_ReceiveTimeout()
{
	int32_t OutResult;
	SBCheckError(TElLDAPSClient_get_ReceiveTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElLDAPSClient::set_ReceiveTimeout(int32_t Value)
{
	SBCheckError(TElLDAPSClient_set_ReceiveTimeout(_Handle, Value));
}

void TElLDAPSClient::get_LDAPDN(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPSClient_get_LDAPDN(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-167696367, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElLDAPSClient::set_LDAPDN(const std::string &Value)
{
	SBCheckError(TElLDAPSClient_set_LDAPDN(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElLDAPSClient::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPSClient_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1813415573, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElLDAPSClient::set_Password(const std::string &Value)
{
	SBCheckError(TElLDAPSClient_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBLDAPAuthenticationType TElLDAPSClient::get_AuthType()
{
	TSBLDAPAuthenticationTypeRaw OutResultRaw = 0;
	SBCheckError(TElLDAPSClient_get_AuthType(_Handle, &OutResultRaw));
	return (TSBLDAPAuthenticationType)OutResultRaw;
}

SB_INLINE void TElLDAPSClient::set_AuthType(TSBLDAPAuthenticationType Value)
{
	SBCheckError(TElLDAPSClient_set_AuthType(_Handle, (TSBLDAPAuthenticationTypeRaw)Value));
}

void TElLDAPSClient::get_SASLMechanism(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPSClient_get_SASLMechanism(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(756900575, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElLDAPSClient::set_SASLMechanism(const std::string &Value)
{
	SBCheckError(TElLDAPSClient_set_SASLMechanism(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElLDAPSClient::get_BaseDN(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPSClient_get_BaseDN(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1112998332, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElLDAPSClient::set_BaseDN(const std::string &Value)
{
	SBCheckError(TElLDAPSClient_set_BaseDN(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBLDAPScope TElLDAPSClient::get_Scope()
{
	TSBLDAPScopeRaw OutResultRaw = 0;
	SBCheckError(TElLDAPSClient_get_Scope(_Handle, &OutResultRaw));
	return (TSBLDAPScope)OutResultRaw;
}

SB_INLINE void TElLDAPSClient::set_Scope(TSBLDAPScope Value)
{
	SBCheckError(TElLDAPSClient_set_Scope(_Handle, (TSBLDAPScopeRaw)Value));
}

void TElLDAPSClient::get_Filter(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPSClient_get_Filter(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1608052615, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElLDAPSClient::set_Filter(const std::string &Value)
{
	SBCheckError(TElLDAPSClient_set_Filter(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElLDAPSClient::get_Attributes(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPSClient_get_Attributes(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1134394193, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElLDAPSClient::set_Attributes(const std::string &Value)
{
	SBCheckError(TElLDAPSClient_set_Attributes(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElLDAPSClient::get_AttributesOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElLDAPSClient_get_AttributesOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElLDAPSClient::set_AttributesOnly(bool Value)
{
	SBCheckError(TElLDAPSClient_set_AttributesOnly(_Handle, (int8_t)Value));
}

TElLDAPSClient::TElLDAPSClient(TElLDAPSClientHandle handle, TElOwnHandle ownHandle) : TElSimpleSSLClient(handle, ownHandle)
{
}

TElLDAPSClient::TElLDAPSClient(TComponent &AOwner) : TElSimpleSSLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLDAPSClient_Create(AOwner.getHandle(), &_Handle));
}

TElLDAPSClient::TElLDAPSClient(TComponent *AOwner) : TElSimpleSSLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLDAPSClient_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELLDAPSCLIENT */

};	/* namespace SecureBlackbox */
