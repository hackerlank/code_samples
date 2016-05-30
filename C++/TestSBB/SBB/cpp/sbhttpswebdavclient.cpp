#include "sbhttpswebdavclient.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELHTTPSWEBDAVCLIENT

SB_INLINE int32_t TElHTTPSWebDAVClient::PropFind(const std::string &URL, TSBWebDavDepth Depth)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_PropFind(_Handle, URL.data(), (int32_t)URL.length(), (TSBWebDavDepthRaw)Depth, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
SB_INLINE int32_t TElHTTPSWebDAVClient::PropFind(const std::string &URL, TElWebDavPropertyInfoList &Properties, bool All, TSBWebDavDepth Depth)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_PropFind_1(_Handle, URL.data(), (int32_t)URL.length(), Properties.getHandle(), (int8_t)All, (TSBWebDavDepthRaw)Depth, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSWebDAVClient::PropFind(const std::string &URL, TElWebDavPropertyInfoList *Properties, bool All, TSBWebDavDepth Depth)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_PropFind_1(_Handle, URL.data(), (int32_t)URL.length(), (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE, (int8_t)All, (TSBWebDavDepthRaw)Depth, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCARDDAVFILTER_AND_TELWEBDAVPROPERTYINFOLIST_AND_TSTRINGLIST
SB_INLINE int32_t TElHTTPSWebDAVClient::AddressBookReport(const std::string &URL, TElWebDavPropertyInfoList &Properties, TStringList &AddressDataProps, TElCardDavFilter &Filter, int32_t Limit, TStringList &Hrefs, bool All, TSBWebDavDepth Depth)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_AddressBookReport(_Handle, URL.data(), (int32_t)URL.length(), Properties.getHandle(), AddressDataProps.getHandle(), Filter.getHandle(), Limit, Hrefs.getHandle(), (int8_t)All, (TSBWebDavDepthRaw)Depth, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSWebDAVClient::AddressBookReport(const std::string &URL, TElWebDavPropertyInfoList *Properties, TStringList *AddressDataProps, TElCardDavFilter *Filter, int32_t Limit, TStringList *Hrefs, bool All, TSBWebDavDepth Depth)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_AddressBookReport(_Handle, URL.data(), (int32_t)URL.length(), (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE, (AddressDataProps != NULL) ? AddressDataProps->getHandle() : SB_NULL_HANDLE, (Filter != NULL) ? Filter->getHandle() : SB_NULL_HANDLE, Limit, (Hrefs != NULL) ? Hrefs->getHandle() : SB_NULL_HANDLE, (int8_t)All, (TSBWebDavDepthRaw)Depth, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCARDDAVFILTER_AND_TELWEBDAVPROPERTYINFOLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCARDDAVFILTER_AND_TELSTRINGLIST_AND_TELWEBDAVPROPERTYINFOLIST
SB_INLINE int32_t TElHTTPSWebDAVClient::AddressBookReport(const std::string &URL, TElWebDavPropertyInfoList &Properties, TElStringList &AddressDataProps, TElCardDavFilter &Filter, int32_t Limit, TElStringList &Hrefs, bool All, TSBWebDavDepth Depth)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_AddressBookReport(_Handle, URL.data(), (int32_t)URL.length(), Properties.getHandle(), AddressDataProps.getHandle(), Filter.getHandle(), Limit, Hrefs.getHandle(), (int8_t)All, (TSBWebDavDepthRaw)Depth, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSWebDAVClient::AddressBookReport(const std::string &URL, TElWebDavPropertyInfoList *Properties, TElStringList *AddressDataProps, TElCardDavFilter *Filter, int32_t Limit, TElStringList *Hrefs, bool All, TSBWebDavDepth Depth)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_AddressBookReport(_Handle, URL.data(), (int32_t)URL.length(), (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE, (AddressDataProps != NULL) ? AddressDataProps->getHandle() : SB_NULL_HANDLE, (Filter != NULL) ? Filter->getHandle() : SB_NULL_HANDLE, Limit, (Hrefs != NULL) ? Hrefs->getHandle() : SB_NULL_HANDLE, (int8_t)All, (TSBWebDavDepthRaw)Depth, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCARDDAVFILTER_AND_TELSTRINGLIST_AND_TELWEBDAVPROPERTYINFOLIST */
#endif

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
SB_INLINE int32_t TElHTTPSWebDAVClient::AclPrincipalPropSetReport(const std::string &URL, TElWebDavPropertyInfoList &Properties)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_AclPrincipalPropSetReport(_Handle, URL.data(), (int32_t)URL.length(), Properties.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSWebDAVClient::AclPrincipalPropSetReport(const std::string &URL, TElWebDavPropertyInfoList *Properties)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_AclPrincipalPropSetReport(_Handle, URL.data(), (int32_t)URL.length(), (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFO_AND_TELWEBDAVPROPERTYINFOLIST
SB_INLINE int32_t TElHTTPSWebDAVClient::AclPrincipalMatchReport(const std::string &URL, TElWebDavPropertyInfo &PrincipalProperty, TElWebDavPropertyInfoList &Properties)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_AclPrincipalMatchReport(_Handle, URL.data(), (int32_t)URL.length(), PrincipalProperty.getHandle(), Properties.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSWebDAVClient::AclPrincipalMatchReport(const std::string &URL, TElWebDavPropertyInfo *PrincipalProperty, TElWebDavPropertyInfoList *Properties)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_AclPrincipalMatchReport(_Handle, URL.data(), (int32_t)URL.length(), (PrincipalProperty != NULL) ? PrincipalProperty->getHandle() : SB_NULL_HANDLE, (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFO_AND_TELWEBDAVPROPERTYINFOLIST */

SB_INLINE int32_t TElHTTPSWebDAVClient::PrincipalSearchPropertySetReport(const std::string &URL)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_PrincipalSearchPropertySetReport(_Handle, URL.data(), (int32_t)URL.length(), &OutResult));
	return OutResult;
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TSTRINGLIST
SB_INLINE int32_t TElHTTPSWebDAVClient::PrincipalPropertySearchReport(const std::string &URL, TElWebDavPropertyInfoList &MatchProperties, TStringList &Matches, TElWebDavPropertyInfoList &Properties, bool ApplyToPrincipalCollectionSet)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_PrincipalPropertySearchReport(_Handle, URL.data(), (int32_t)URL.length(), MatchProperties.getHandle(), Matches.getHandle(), Properties.getHandle(), (int8_t)ApplyToPrincipalCollectionSet, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSWebDAVClient::PrincipalPropertySearchReport(const std::string &URL, TElWebDavPropertyInfoList *MatchProperties, TStringList *Matches, TElWebDavPropertyInfoList *Properties, bool ApplyToPrincipalCollectionSet)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_PrincipalPropertySearchReport(_Handle, URL.data(), (int32_t)URL.length(), (MatchProperties != NULL) ? MatchProperties->getHandle() : SB_NULL_HANDLE, (Matches != NULL) ? Matches->getHandle() : SB_NULL_HANDLE, (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE, (int8_t)ApplyToPrincipalCollectionSet, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWEBDAVPROPERTYINFOLIST
SB_INLINE int32_t TElHTTPSWebDAVClient::PrincipalPropertySearchReport(const std::string &URL, TElWebDavPropertyInfoList &MatchProperties, TElStringList &Matches, TElWebDavPropertyInfoList &Properties, bool ApplyToPrincipalCollectionSet)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_PrincipalPropertySearchReport(_Handle, URL.data(), (int32_t)URL.length(), MatchProperties.getHandle(), Matches.getHandle(), Properties.getHandle(), (int8_t)ApplyToPrincipalCollectionSet, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSWebDAVClient::PrincipalPropertySearchReport(const std::string &URL, TElWebDavPropertyInfoList *MatchProperties, TElStringList *Matches, TElWebDavPropertyInfoList *Properties, bool ApplyToPrincipalCollectionSet)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_PrincipalPropertySearchReport(_Handle, URL.data(), (int32_t)URL.length(), (MatchProperties != NULL) ? MatchProperties->getHandle() : SB_NULL_HANDLE, (Matches != NULL) ? Matches->getHandle() : SB_NULL_HANDLE, (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE, (int8_t)ApplyToPrincipalCollectionSet, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWEBDAVPROPERTYINFOLIST */
#endif

#ifdef SB_USE_CLASS_TELWEBDAVACL
SB_INLINE int32_t TElHTTPSWebDAVClient::Acl(const std::string &URL, TElWebDavACL &NewAcl)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_Acl(_Handle, URL.data(), (int32_t)URL.length(), NewAcl.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSWebDAVClient::Acl(const std::string &URL, TElWebDavACL *NewAcl)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_Acl(_Handle, URL.data(), (int32_t)URL.length(), (NewAcl != NULL) ? NewAcl->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWEBDAVACL */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
SB_INLINE int32_t TElHTTPSWebDAVClient::PropPatch(const std::string &URL, TElWebDavPropertyInfoList &SetProperties, TElWebDavPropertyInfoList &RemoveProperties, const std::string &IfHeader)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_PropPatch(_Handle, URL.data(), (int32_t)URL.length(), SetProperties.getHandle(), RemoveProperties.getHandle(), IfHeader.data(), (int32_t)IfHeader.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSWebDAVClient::PropPatch(const std::string &URL, TElWebDavPropertyInfoList *SetProperties, TElWebDavPropertyInfoList *RemoveProperties, const std::string &IfHeader)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_PropPatch(_Handle, URL.data(), (int32_t)URL.length(), (SetProperties != NULL) ? SetProperties->getHandle() : SB_NULL_HANDLE, (RemoveProperties != NULL) ? RemoveProperties->getHandle() : SB_NULL_HANDLE, IfHeader.data(), (int32_t)IfHeader.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

SB_INLINE int32_t TElHTTPSWebDAVClient::MkCol(const std::string &URL, const std::string &IfHeader)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_MkCol(_Handle, URL.data(), (int32_t)URL.length(), IfHeader.data(), (int32_t)IfHeader.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSWebDAVClient::MkColEx(const std::string &URL, const std::string &DisplayName, const std::string &Description, const std::string &Lang, const std::string &IfHeader)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_MkColEx(_Handle, URL.data(), (int32_t)URL.length(), DisplayName.data(), (int32_t)DisplayName.length(), Description.data(), (int32_t)Description.length(), Lang.data(), (int32_t)Lang.length(), IfHeader.data(), (int32_t)IfHeader.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSWebDAVClient::Copy(const std::string &SrcURL, const std::string &DestURL, TSBWebDavDepth Depth, bool Overwrite, const std::string &IfHeader)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_Copy(_Handle, SrcURL.data(), (int32_t)SrcURL.length(), DestURL.data(), (int32_t)DestURL.length(), (TSBWebDavDepthRaw)Depth, (int8_t)Overwrite, IfHeader.data(), (int32_t)IfHeader.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSWebDAVClient::Move(const std::string &SrcURL, const std::string &DestURL, TSBWebDavDepth Depth, bool Overwrite, const std::string &IfHeader)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_Move(_Handle, SrcURL.data(), (int32_t)SrcURL.length(), DestURL.data(), (int32_t)DestURL.length(), (TSBWebDavDepthRaw)Depth, (int8_t)Overwrite, IfHeader.data(), (int32_t)IfHeader.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSWebDAVClient::Lock(const std::string &URL, const std::string &IfHeader, const std::string &Owner, TSBWebDavLockScope Scope, TSBWebDavDepth Depth, int32_t Timeout)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_Lock(_Handle, URL.data(), (int32_t)URL.length(), IfHeader.data(), (int32_t)IfHeader.length(), Owner.data(), (int32_t)Owner.length(), (TSBWebDavLockScopeRaw)Scope, (TSBWebDavDepthRaw)Depth, Timeout, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSWebDAVClient::Unlock(const std::string &URL, const std::string &Token)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_Unlock(_Handle, URL.data(), (int32_t)URL.length(), Token.data(), (int32_t)Token.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSWebDAVClient::Delete(const std::string &URL, const std::string &IfHeader)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_Delete(_Handle, URL.data(), (int32_t)URL.length(), IfHeader.data(), (int32_t)IfHeader.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSWebDAVClient::Put(const std::string &URL, const std::string &Content, const std::string &IfHeader)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_Put(_Handle, URL.data(), (int32_t)URL.length(), Content.data(), (int32_t)Content.length(), IfHeader.data(), (int32_t)IfHeader.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSWebDAVClient::Put(const std::string &URL, const std::vector<uint8_t> &Content, const std::string &IfHeader)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_Put_1(_Handle, URL.data(), (int32_t)URL.length(), SB_STD_VECTOR_FRONT_ADR(Content), (int32_t)Content.size(), IfHeader.data(), (int32_t)IfHeader.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSWebDAVClient::Put(const std::string &URL, const std::vector<uint8_t> &Content, int32_t StartIndex, int32_t Count, const std::string &IfHeader)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_Put_2(_Handle, URL.data(), (int32_t)URL.length(), SB_STD_VECTOR_FRONT_ADR(Content), (int32_t)Content.size(), StartIndex, Count, IfHeader.data(), (int32_t)IfHeader.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElHTTPSWebDAVClient::Put(const std::string &URL, TStream &Content, bool CloseStream, const std::string &IfHeader)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_Put_3(_Handle, URL.data(), (int32_t)URL.length(), Content.getHandle(), (int8_t)CloseStream, IfHeader.data(), (int32_t)IfHeader.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSWebDAVClient::Put(const std::string &URL, TStream *Content, bool CloseStream, const std::string &IfHeader)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSWebDAVClient_Put_3(_Handle, URL.data(), (int32_t)URL.length(), (Content != NULL) ? Content->getHandle() : SB_NULL_HANDLE, (int8_t)CloseStream, IfHeader.data(), (int32_t)IfHeader.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

TElHTTPSWebDAVClient::TElHTTPSWebDAVClient(TElHTTPSWebDAVClientHandle handle, TElOwnHandle ownHandle) : TElHTTPSClient(handle, ownHandle)
{
}

TElHTTPSWebDAVClient::TElHTTPSWebDAVClient(TComponent &AOwner) : TElHTTPSClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElHTTPSWebDAVClient_Create(AOwner.getHandle(), &_Handle));
}

TElHTTPSWebDAVClient::TElHTTPSWebDAVClient(TComponent *AOwner) : TElHTTPSClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElHTTPSWebDAVClient_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELHTTPSWEBDAVCLIENT */

};	/* namespace SecureBlackbox */
