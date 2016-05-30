#ifndef __INC_SBHTTPSWEBDAVCLIENT
#define __INC_SBHTTPSWEBDAVCLIENT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbstreams.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbxmldefs.h"
#include "sbxmlutils.h"
#include "sbxmlcore.h"
#include "sbxmlcharsets.h"
#include "sbstringlist.h"
#include "sbhttpscommon.h"
#include "sbhttpsconstants.h"
#include "sbhttpsclient.h"
#include "sbwebdavcommon.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElHTTPSWebDAVClientHandle;

typedef TElHTTPSWebDAVClientHandle ElHTTPSWebDAVClientHandle;

#ifdef SB_USE_CLASS_TELHTTPSWEBDAVCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSWebDAVClient_PropFind(TElHTTPSWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TSBWebDavDepthRaw Depth, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSWebDAVClient_PropFind_1(TElHTTPSWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoListHandle Properties, int8_t All, TSBWebDavDepthRaw Depth, int32_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSWebDAVClient_AddressBookReport(TElHTTPSWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoListHandle Properties, TStringListHandle AddressDataProps, TElCardDavFilterHandle Filter, int32_t Limit, TStringListHandle Hrefs, int8_t All, TSBWebDavDepthRaw Depth, int32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSWebDAVClient_AddressBookReport(TElHTTPSWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoListHandle Properties, TElStringListHandle AddressDataProps, TElCardDavFilterHandle Filter, int32_t Limit, TElStringListHandle Hrefs, int8_t All, TSBWebDavDepthRaw Depth, int32_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSWebDAVClient_AclPrincipalPropSetReport(TElHTTPSWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoListHandle Properties, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSWebDAVClient_AclPrincipalMatchReport(TElHTTPSWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoHandle PrincipalProperty, TElWebDavPropertyInfoListHandle Properties, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSWebDAVClient_PrincipalSearchPropertySetReport(TElHTTPSWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, int32_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSWebDAVClient_PrincipalPropertySearchReport(TElHTTPSWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoListHandle MatchProperties, TStringListHandle Matches, TElWebDavPropertyInfoListHandle Properties, int8_t ApplyToPrincipalCollectionSet, int32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSWebDAVClient_PrincipalPropertySearchReport(TElHTTPSWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoListHandle MatchProperties, TElStringListHandle Matches, TElWebDavPropertyInfoListHandle Properties, int8_t ApplyToPrincipalCollectionSet, int32_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSWebDAVClient_Acl(TElHTTPSWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavACLHandle NewAcl, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSWebDAVClient_PropPatch(TElHTTPSWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoListHandle SetProperties, TElWebDavPropertyInfoListHandle RemoveProperties, const char * pcIfHeader, int32_t szIfHeader, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSWebDAVClient_MkCol(TElHTTPSWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, const char * pcIfHeader, int32_t szIfHeader, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSWebDAVClient_MkColEx(TElHTTPSWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, const char * pcDisplayName, int32_t szDisplayName, const char * pcDescription, int32_t szDescription, const char * pcLang, int32_t szLang, const char * pcIfHeader, int32_t szIfHeader, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSWebDAVClient_Copy(TElHTTPSWebDAVClientHandle _Handle, const char * pcSrcURL, int32_t szSrcURL, const char * pcDestURL, int32_t szDestURL, TSBWebDavDepthRaw Depth, int8_t Overwrite, const char * pcIfHeader, int32_t szIfHeader, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSWebDAVClient_Move(TElHTTPSWebDAVClientHandle _Handle, const char * pcSrcURL, int32_t szSrcURL, const char * pcDestURL, int32_t szDestURL, TSBWebDavDepthRaw Depth, int8_t Overwrite, const char * pcIfHeader, int32_t szIfHeader, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSWebDAVClient_Lock(TElHTTPSWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, const char * pcIfHeader, int32_t szIfHeader, const char * pcOwner, int32_t szOwner, TSBWebDavLockScopeRaw Scope, TSBWebDavDepthRaw Depth, int32_t Timeout, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSWebDAVClient_Unlock(TElHTTPSWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, const char * pcToken, int32_t szToken, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSWebDAVClient_Delete(TElHTTPSWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, const char * pcIfHeader, int32_t szIfHeader, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSWebDAVClient_Put(TElHTTPSWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, const char * pcContent, int32_t szContent, const char * pcIfHeader, int32_t szIfHeader, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSWebDAVClient_Put_1(TElHTTPSWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, const uint8_t pContent[], int32_t szContent, const char * pcIfHeader, int32_t szIfHeader, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSWebDAVClient_Put_2(TElHTTPSWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, const uint8_t pContent[], int32_t szContent, int32_t StartIndex, int32_t Count, const char * pcIfHeader, int32_t szIfHeader, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSWebDAVClient_Put_3(TElHTTPSWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TStreamHandle Content, int8_t CloseStream, const char * pcIfHeader, int32_t szIfHeader, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSWebDAVClient_Create(TComponentHandle AOwner, TElHTTPSWebDAVClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELHTTPSWEBDAVCLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElHTTPSWebDAVClient;
typedef TElHTTPSWebDAVClient ElHTTPSWebDAVClient;

#ifdef SB_USE_CLASS_TELHTTPSWEBDAVCLIENT
class TElHTTPSWebDAVClient: public TElHTTPSClient
{
	private:
		SB_DISABLE_COPY(TElHTTPSWebDAVClient)
	public:
		int32_t PropFind(const std::string &URL, TSBWebDavDepth Depth);

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
		int32_t PropFind(const std::string &URL, TElWebDavPropertyInfoList &Properties, bool All, TSBWebDavDepth Depth);

		int32_t PropFind(const std::string &URL, TElWebDavPropertyInfoList *Properties, bool All, TSBWebDavDepth Depth);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCARDDAVFILTER_AND_TELWEBDAVPROPERTYINFOLIST_AND_TSTRINGLIST
		int32_t AddressBookReport(const std::string &URL, TElWebDavPropertyInfoList &Properties, TStringList &AddressDataProps, TElCardDavFilter &Filter, int32_t Limit, TStringList &Hrefs, bool All, TSBWebDavDepth Depth);

		int32_t AddressBookReport(const std::string &URL, TElWebDavPropertyInfoList *Properties, TStringList *AddressDataProps, TElCardDavFilter *Filter, int32_t Limit, TStringList *Hrefs, bool All, TSBWebDavDepth Depth);
#endif /* SB_USE_CLASSES_TELCARDDAVFILTER_AND_TELWEBDAVPROPERTYINFOLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCARDDAVFILTER_AND_TELSTRINGLIST_AND_TELWEBDAVPROPERTYINFOLIST
		int32_t AddressBookReport(const std::string &URL, TElWebDavPropertyInfoList &Properties, TElStringList &AddressDataProps, TElCardDavFilter &Filter, int32_t Limit, TElStringList &Hrefs, bool All, TSBWebDavDepth Depth);

		int32_t AddressBookReport(const std::string &URL, TElWebDavPropertyInfoList *Properties, TElStringList *AddressDataProps, TElCardDavFilter *Filter, int32_t Limit, TElStringList *Hrefs, bool All, TSBWebDavDepth Depth);
#endif /* SB_USE_CLASSES_TELCARDDAVFILTER_AND_TELSTRINGLIST_AND_TELWEBDAVPROPERTYINFOLIST */
#endif

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
		int32_t AclPrincipalPropSetReport(const std::string &URL, TElWebDavPropertyInfoList &Properties);

		int32_t AclPrincipalPropSetReport(const std::string &URL, TElWebDavPropertyInfoList *Properties);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFO_AND_TELWEBDAVPROPERTYINFOLIST
		int32_t AclPrincipalMatchReport(const std::string &URL, TElWebDavPropertyInfo &PrincipalProperty, TElWebDavPropertyInfoList &Properties);

		int32_t AclPrincipalMatchReport(const std::string &URL, TElWebDavPropertyInfo *PrincipalProperty, TElWebDavPropertyInfoList *Properties);
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFO_AND_TELWEBDAVPROPERTYINFOLIST */

		int32_t PrincipalSearchPropertySetReport(const std::string &URL);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TSTRINGLIST
		int32_t PrincipalPropertySearchReport(const std::string &URL, TElWebDavPropertyInfoList &MatchProperties, TStringList &Matches, TElWebDavPropertyInfoList &Properties, bool ApplyToPrincipalCollectionSet);

		int32_t PrincipalPropertySearchReport(const std::string &URL, TElWebDavPropertyInfoList *MatchProperties, TStringList *Matches, TElWebDavPropertyInfoList *Properties, bool ApplyToPrincipalCollectionSet);
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWEBDAVPROPERTYINFOLIST
		int32_t PrincipalPropertySearchReport(const std::string &URL, TElWebDavPropertyInfoList &MatchProperties, TElStringList &Matches, TElWebDavPropertyInfoList &Properties, bool ApplyToPrincipalCollectionSet);

		int32_t PrincipalPropertySearchReport(const std::string &URL, TElWebDavPropertyInfoList *MatchProperties, TElStringList *Matches, TElWebDavPropertyInfoList *Properties, bool ApplyToPrincipalCollectionSet);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWEBDAVPROPERTYINFOLIST */
#endif

#ifdef SB_USE_CLASS_TELWEBDAVACL
		int32_t Acl(const std::string &URL, TElWebDavACL &NewAcl);

		int32_t Acl(const std::string &URL, TElWebDavACL *NewAcl);
#endif /* SB_USE_CLASS_TELWEBDAVACL */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
		int32_t PropPatch(const std::string &URL, TElWebDavPropertyInfoList &SetProperties, TElWebDavPropertyInfoList &RemoveProperties, const std::string &IfHeader);

		int32_t PropPatch(const std::string &URL, TElWebDavPropertyInfoList *SetProperties, TElWebDavPropertyInfoList *RemoveProperties, const std::string &IfHeader);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

		int32_t MkCol(const std::string &URL, const std::string &IfHeader);

		int32_t MkColEx(const std::string &URL, const std::string &DisplayName, const std::string &Description, const std::string &Lang, const std::string &IfHeader);

		int32_t Copy(const std::string &SrcURL, const std::string &DestURL, TSBWebDavDepth Depth, bool Overwrite, const std::string &IfHeader);

		int32_t Move(const std::string &SrcURL, const std::string &DestURL, TSBWebDavDepth Depth, bool Overwrite, const std::string &IfHeader);

		int32_t Lock(const std::string &URL, const std::string &IfHeader, const std::string &Owner, TSBWebDavLockScope Scope, TSBWebDavDepth Depth, int32_t Timeout);

		int32_t Unlock(const std::string &URL, const std::string &Token);

		int32_t Delete(const std::string &URL, const std::string &IfHeader);

		int32_t Put(const std::string &URL, const std::string &Content, const std::string &IfHeader);

		int32_t Put(const std::string &URL, const std::vector<uint8_t> &Content, const std::string &IfHeader);

		int32_t Put(const std::string &URL, const std::vector<uint8_t> &Content, int32_t StartIndex, int32_t Count, const std::string &IfHeader);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t Put(const std::string &URL, TStream &Content, bool CloseStream, const std::string &IfHeader);

		int32_t Put(const std::string &URL, TStream *Content, bool CloseStream, const std::string &IfHeader);
#endif /* SB_USE_CLASS_TSTREAM */

		TElHTTPSWebDAVClient(TElHTTPSWebDAVClientHandle handle, TElOwnHandle ownHandle);

		explicit TElHTTPSWebDAVClient(TComponent &AOwner);

		explicit TElHTTPSWebDAVClient(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELHTTPSWEBDAVCLIENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBHTTPSWEBDAVCLIENT */
