#ifndef __INC_SBSAMLSERVICEPROVIDER
#define __INC_SBSAMLSERVICEPROVIDER

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
#include "sbstringlist.h"
#include "sbx509.h"
#include "sbcustomcertstorage.h"
#include "sbsslcommon.h"
#include "sbsslserver.h"
#include "sbsessionpool.h"
#include "sbhttpscommon.h"
#include "sbencoding.h"
#include "sbhttpsconstants.h"
#include "sbhttpsserver.h"
#include "sbsharedresource.h"
#include "sbhashfunction.h"
#include "sbsslconstants.h"
#include "sbcookiemgr.h"
#include "sbhttpsclient.h"
#include "sbxmlcore.h"
#include "sbxmlsec.h"
#include "sbxmlsig.h"
#include "sbxmlutils.h"
#include "sbxmlsamlcommon.h"
#include "sbxmlsamlprotocol.h"
#include "sbxmlsamlbind.h"
#include "sbxmlsamlcore.h"
#include "sbxmlsamlmetadata.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElSAMLSPSessionHandle;

typedef TElClassHandle TElSAMLRequestResultHandle;

typedef TElClassHandle TElSAMLOneTimeUseRecordHandle;

typedef TElClassHandle TElSAMLCustomOneTimeUseCacheHandle;

typedef TElClassHandle TElSAMLMemoryOneTimeUseCacheHandle;

typedef TElClassHandle TElSAMLServiceProviderHandle;

typedef uint8_t TSBSAMLSPStageRaw;

typedef enum
{
	spsStart = 0,
	spsAuthnRequestSent = 1,
	spsResponseReceived = 2,
	spsResourceSupplied = 3,
	spsLogoutRequestSent = 4,
	spsLogoutResponseReceived = 5,
	spsLogoutRequestRecv = 6,
	spsLogoutResponseSent = 7,
	spsArtifactResolveRecv = 8,
	spsArtifactResponseSent = 9
} TSBSAMLSPStage;

typedef void (SB_CALLBACK *TSBSAMLChangeSPSessionStageEvent)(void * _ObjectData, TObjectHandle Sender, TElSAMLSPSessionHandle Session, TSBSAMLSPStageRaw Stage);

typedef void (SB_CALLBACK *SBSAMLServiceProvider_TSBSAMLSessionEvent)(void * _ObjectData, TObjectHandle Sender, TElSAMLSPSessionHandle Session);

typedef void (SB_CALLBACK *SBSAMLServiceProvider_TSBSAMLLogoutEvent)(void * _ObjectData, TObjectHandle Sender, TElSAMLSPSessionHandle Session, TElHTTPServerResponseParamsHandle ResponseParams);

typedef void (SB_CALLBACK *TSBSAMLChooseNameIDPolicyEvent)(void * _ObjectData, TObjectHandle Sender, TElSAMLSPSessionHandle Session, TElSAMLNameIDPolicyElementHandle NameIDPolicy);

typedef uint8_t SBSAMLServiceProvider_TSBSAMLAccessLevelRaw;

typedef enum
{
	_salDomain = 0,
	_salExactURL = 1
} SBSAMLServiceProvider_TSBSAMLAccessLevel;

#ifdef SB_USE_CLASS_TELSAMLSPSESSION
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSPSession_Generate(TElSAMLSPSessionHandle _Handle, int32_t TTL);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSPSession_get_Stage(TElSAMLSPSessionHandle _Handle, TSBSAMLSPStageRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSPSession_set_Stage(TElSAMLSPSessionHandle _Handle, TSBSAMLSPStageRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSPSession_get_SAMLSession(TElSAMLSPSessionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSPSession_set_SAMLSession(TElSAMLSPSessionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSPSession_get_AuthnRequestID(TElSAMLSPSessionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSPSession_set_AuthnRequestID(TElSAMLSPSessionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSPSession_get_LogoutRequestID(TElSAMLSPSessionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSPSession_set_LogoutRequestID(TElSAMLSPSessionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSPSession_get_SAMLCookieSet(TElSAMLSPSessionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSPSession_set_SAMLCookieSet(TElSAMLSPSessionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSPSession_get_NameID(TElSAMLSPSessionHandle _Handle, TElSAMLIDHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSPSession_set_NameID(TElSAMLSPSessionHandle _Handle, TElSAMLIDHandle Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSPSession_get_SessionIndexes(TElSAMLSPSessionHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSPSession_get_SessionIndexes(TElSAMLSPSessionHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSPSession_get_Redirected(TElSAMLSPSessionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSPSession_set_Redirected(TElSAMLSPSessionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSPSession_Create(TElSAMLSPSessionHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLSPSESSION */

#ifdef SB_USE_CLASS_TELSAMLREQUESTRESULT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestResult_get_Doc(TElSAMLRequestResultHandle _Handle, TElXMLDOMDocumentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestResult_get_Response(TElSAMLRequestResultHandle _Handle, TElSAMLStatusResponseTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestResult_Create(TElXMLDOMDocumentHandle Doc, TElSAMLStatusResponseTypeHandle Response, TElSAMLRequestResultHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLREQUESTRESULT */

#ifdef SB_USE_CLASS_TELSAMLONETIMEUSERECORD
SB_IMPORT uint32_t SB_APIENTRY TElSAMLOneTimeUseRecord_get_ID(TElSAMLOneTimeUseRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLOneTimeUseRecord_set_ID(TElSAMLOneTimeUseRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLOneTimeUseRecord_get_IssueInstant(TElSAMLOneTimeUseRecordHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLOneTimeUseRecord_set_IssueInstant(TElSAMLOneTimeUseRecordHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLOneTimeUseRecord_Create(TElSAMLOneTimeUseRecordHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLONETIMEUSERECORD */

#ifdef SB_USE_CLASS_TELSAMLCUSTOMONETIMEUSECACHE
SB_IMPORT uint32_t SB_APIENTRY TElSAMLCustomOneTimeUseCache_Lock(TElSAMLCustomOneTimeUseCacheHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLCustomOneTimeUseCache_Unlock(TElSAMLCustomOneTimeUseCacheHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLCustomOneTimeUseCache_Clear(TElSAMLCustomOneTimeUseCacheHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLCustomOneTimeUseCache_Add(TElSAMLCustomOneTimeUseCacheHandle _Handle, TElSAMLAssertionElementHandle Assertion, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLCustomOneTimeUseCache_Find(TElSAMLCustomOneTimeUseCacheHandle _Handle, TElSAMLAssertionElementHandle Assertion, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLCustomOneTimeUseCache_Create(TElSAMLCustomOneTimeUseCacheHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLCUSTOMONETIMEUSECACHE */

#ifdef SB_USE_CLASS_TELSAMLMEMORYONETIMEUSECACHE
SB_IMPORT uint32_t SB_APIENTRY TElSAMLMemoryOneTimeUseCache_Lock(TElSAMLMemoryOneTimeUseCacheHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLMemoryOneTimeUseCache_Unlock(TElSAMLMemoryOneTimeUseCacheHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLMemoryOneTimeUseCache_Clear(TElSAMLMemoryOneTimeUseCacheHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLMemoryOneTimeUseCache_Add(TElSAMLMemoryOneTimeUseCacheHandle _Handle, TElSAMLAssertionElementHandle Assertion, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLMemoryOneTimeUseCache_Find(TElSAMLMemoryOneTimeUseCacheHandle _Handle, TElSAMLAssertionElementHandle Assertion, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLMemoryOneTimeUseCache_Create(TElSAMLMemoryOneTimeUseCacheHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLMEMORYONETIMEUSECACHE */

#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDER
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_LoadMetadata(TElSAMLServiceProviderHandle _Handle, const char * pcURI, int32_t szURI);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_SaveMetadata(TElSAMLServiceProviderHandle _Handle, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_Open(TElSAMLServiceProviderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_DataAvailable(TElSAMLServiceProviderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_Close(TElSAMLServiceProviderHandle _Handle, int8_t Silent);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_SendRequest(TElSAMLServiceProviderHandle _Handle, TElSAMLRequestAbstractTypeHandle Request, TElSAMLRequestResultHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_AddIDPSingleSignOnService(TElSAMLServiceProviderHandle _Handle, TElSAMLEndpointHandle Endpoint, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_AddIDPSingleLogoutService(TElSAMLServiceProviderHandle _Handle, TElSAMLEndpointHandle Endpoint, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_AddIDPArtifactResolutionService(TElSAMLServiceProviderHandle _Handle, TElSAMLEndpointHandle Endpoint, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_AddIDPAttributeQueryService(TElSAMLServiceProviderHandle _Handle, TElSAMLEndpointHandle Endpoint, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_RemoveIDPSingleSignOnService(TElSAMLServiceProviderHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_RemoveIDPSingleLogoutService(TElSAMLServiceProviderHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_RemoveIDPArtifactResolutionService(TElSAMLServiceProviderHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_RemoveIDPAttributeQueryService(TElSAMLServiceProviderHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_Control(TElSAMLServiceProviderHandle _Handle, TElHTTPSServerHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_ProtectedResources(TElSAMLServiceProviderHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_ProtectedResources(TElSAMLServiceProviderHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_IDPSingleSignOnServices(TElSAMLServiceProviderHandle _Handle, int32_t Index, TElSAMLEndpointHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_IDPSingleLogoutServices(TElSAMLServiceProviderHandle _Handle, int32_t Index, TElSAMLEndpointHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_IDPArtifactResolutionServices(TElSAMLServiceProviderHandle _Handle, int32_t Index, TElSAMLEndpointHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_IDPAttributeQueryServices(TElSAMLServiceProviderHandle _Handle, int32_t Index, TElSAMLEndpointHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_IDPSignleSignOnServiceCount(TElSAMLServiceProviderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_IDPSingleLogoutServiceCount(TElSAMLServiceProviderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_IDPArtifactResolutionServiceCount(TElSAMLServiceProviderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_IDPAttributeQueryServiceCount(TElSAMLServiceProviderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_SourceID(TElSAMLServiceProviderHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_SourceID(TElSAMLServiceProviderHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_IDPSourceID(TElSAMLServiceProviderHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_IDPSourceID(TElSAMLServiceProviderHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_AutoIDPSourceID(TElSAMLServiceProviderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_AutoIDPSourceID(TElSAMLServiceProviderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_Active(TElSAMLServiceProviderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_SendBufferSize(TElSAMLServiceProviderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_SendBufferSize(TElSAMLServiceProviderHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_ServerName(TElSAMLServiceProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_ServerName(TElSAMLServiceProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_SessionManager(TElSAMLServiceProviderHandle _Handle, TElCustomSessionManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_SessionManager(TElSAMLServiceProviderHandle _Handle, TElCustomSessionManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_AssertionsOneTimeUseCache(TElSAMLServiceProviderHandle _Handle, TElSAMLCustomOneTimeUseCacheHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_AssertionsOneTimeUseCache(TElSAMLServiceProviderHandle _Handle, TElSAMLCustomOneTimeUseCacheHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_URL(TElSAMLServiceProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_URL(TElSAMLServiceProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_SPToIDPBinding(TElSAMLServiceProviderHandle _Handle, TSBSAMLBindingTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_SPToIDPBinding(TElSAMLServiceProviderHandle _Handle, TSBSAMLBindingTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_PrefferedIDPToSPBinding(TElSAMLServiceProviderHandle _Handle, TSBSAMLBindingTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_PrefferedIDPToSPBinding(TElSAMLServiceProviderHandle _Handle, TSBSAMLBindingTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_SingleLogoutServiceBindings(TElSAMLServiceProviderHandle _Handle, TSBSAMLBindingTypesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_SingleLogoutServiceBindings(TElSAMLServiceProviderHandle _Handle, TSBSAMLBindingTypesRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_AssertionConsumerServiceBindings(TElSAMLServiceProviderHandle _Handle, TSBSAMLBindingTypesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_AssertionConsumerServiceBindings(TElSAMLServiceProviderHandle _Handle, TSBSAMLBindingTypesRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_ArtifactResolutionServiceBindings(TElSAMLServiceProviderHandle _Handle, TSBSAMLBindingTypesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_MetadataURL(TElSAMLServiceProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_MetadataURL(TElSAMLServiceProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_AssertionConsumerService(TElSAMLServiceProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_AssertionConsumerService(TElSAMLServiceProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_SingleLogoutService(TElSAMLServiceProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_SingleLogoutService(TElSAMLServiceProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_ArtifactResolutionService(TElSAMLServiceProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_ArtifactResolutionService(TElSAMLServiceProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_LogoutPage(TElSAMLServiceProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_LogoutPage(TElSAMLServiceProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_Issuer(TElSAMLServiceProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_Issuer(TElSAMLServiceProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_SessionCookieName(TElSAMLServiceProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_SessionCookieName(TElSAMLServiceProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_SAMLSessionCookieName(TElSAMLServiceProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_SAMLSessionCookieName(TElSAMLServiceProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_IDPSigningCertificate(TElSAMLServiceProviderHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_IDPSigningCertificate(TElSAMLServiceProviderHandle _Handle, TElX509CertificateHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_IDPEncryptionCertificate(TElSAMLServiceProviderHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_IDPEncryptionCertificate(TElSAMLServiceProviderHandle _Handle, TElX509CertificateHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_IDPMetaSigningCertificate(TElSAMLServiceProviderHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_IDPMetaSigningCertificate(TElSAMLServiceProviderHandle _Handle, TElX509CertificateHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_IDPAllowCreateIdentifier(TElSAMLServiceProviderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_IDPAllowCreateIdentifier(TElSAMLServiceProviderHandle _Handle, int8_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_IDPNameIDFormats(TElSAMLServiceProviderHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_IDPNameIDFormats(TElSAMLServiceProviderHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_IDPNameIDFormatIndex(TElSAMLServiceProviderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_IDPNameIDFormatIndex(TElSAMLServiceProviderHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_IDPPrefferedNameIDFormat(TElSAMLServiceProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_IDPPrefferedNameIDFormat(TElSAMLServiceProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_AccessLevel(TElSAMLServiceProviderHandle _Handle, SBSAMLServiceProvider_TSBSAMLAccessLevelRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_AccessLevel(TElSAMLServiceProviderHandle _Handle, SBSAMLServiceProvider_TSBSAMLAccessLevelRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_SessionTTL(TElSAMLServiceProviderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_SessionTTL(TElSAMLServiceProviderHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_MaxIssueInstantTimeDiff(TElSAMLServiceProviderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_MaxIssueInstantTimeDiff(TElSAMLServiceProviderHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_SignAuthnRequests(TElSAMLServiceProviderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_SignAuthnRequests(TElSAMLServiceProviderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_SignLogoutRequests(TElSAMLServiceProviderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_SignLogoutRequests(TElSAMLServiceProviderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_SignArtifactResolveRequests(TElSAMLServiceProviderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_SignArtifactResolveRequests(TElSAMLServiceProviderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_CertStorage(TElSAMLServiceProviderHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_CertStorage(TElSAMLServiceProviderHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_SigningCertificate(TElSAMLServiceProviderHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_SigningCertificate(TElSAMLServiceProviderHandle _Handle, TElX509CertificateHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_EncryptionCertificate(TElSAMLServiceProviderHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_EncryptionCertificate(TElSAMLServiceProviderHandle _Handle, TElX509CertificateHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_MetaSigningCertificate(TElSAMLServiceProviderHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_MetaSigningCertificate(TElSAMLServiceProviderHandle _Handle, TElX509CertificateHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_RedirectOnLogoutPage(TElSAMLServiceProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_RedirectOnLogoutPage(TElSAMLServiceProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_ArtifactStorage(TElSAMLServiceProviderHandle _Handle, TElCustomArtifactStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_ArtifactStorage(TElSAMLServiceProviderHandle _Handle, TElCustomArtifactStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_RedirectToSuppliedResource(TElSAMLServiceProviderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_RedirectToSuppliedResource(TElSAMLServiceProviderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_SignMetadata(TElSAMLServiceProviderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_SignMetadata(TElSAMLServiceProviderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_IDPEntityID(TElSAMLServiceProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_IDPEntityID(TElSAMLServiceProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnSessionCreate(TElSAMLServiceProviderHandle _Handle, SBSAMLServiceProvider_TSBSAMLSessionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnSessionCreate(TElSAMLServiceProviderHandle _Handle, SBSAMLServiceProvider_TSBSAMLSessionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnSessionDestroy(TElSAMLServiceProviderHandle _Handle, SBSAMLServiceProvider_TSBSAMLSessionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnSessionDestroy(TElSAMLServiceProviderHandle _Handle, SBSAMLServiceProvider_TSBSAMLSessionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnLogout(TElSAMLServiceProviderHandle _Handle, SBSAMLServiceProvider_TSBSAMLLogoutEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnLogout(TElSAMLServiceProviderHandle _Handle, SBSAMLServiceProvider_TSBSAMLLogoutEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnBeforeHTTPSServerUse(TElSAMLServiceProviderHandle _Handle, SBXMLSAMLCommon_TSBSAMLBeforeHTTPSServerUseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnBeforeHTTPSServerUse(TElSAMLServiceProviderHandle _Handle, SBXMLSAMLCommon_TSBSAMLBeforeHTTPSServerUseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnBeforeHTTPSClientUse(TElSAMLServiceProviderHandle _Handle, TSBSAMLBeforeHTTPSClientUseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnBeforeHTTPSClientUse(TElSAMLServiceProviderHandle _Handle, TSBSAMLBeforeHTTPSClientUseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnRequestPrepared(TElSAMLServiceProviderHandle _Handle, TSBSAMLRequestPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnRequestPrepared(TElSAMLServiceProviderHandle _Handle, TSBSAMLRequestPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnResponsePrepared(TElSAMLServiceProviderHandle _Handle, TSBSAMLResponsePreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnResponsePrepared(TElSAMLServiceProviderHandle _Handle, TSBSAMLResponsePreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnResponseReceived(TElSAMLServiceProviderHandle _Handle, TSBSAMLResponseReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnResponseReceived(TElSAMLServiceProviderHandle _Handle, TSBSAMLResponseReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnRequestReceived(TElSAMLServiceProviderHandle _Handle, TSBSAMLRequestReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnRequestReceived(TElSAMLServiceProviderHandle _Handle, TSBSAMLRequestReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnChangeSessionStage(TElSAMLServiceProviderHandle _Handle, TSBSAMLChangeSPSessionStageEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnChangeSessionStage(TElSAMLServiceProviderHandle _Handle, TSBSAMLChangeSPSessionStageEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnMetadataPrepared(TElSAMLServiceProviderHandle _Handle, TSBSAMLMetadataPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnMetadataPrepared(TElSAMLServiceProviderHandle _Handle, TSBSAMLMetadataPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnResourceOpen(TElSAMLServiceProviderHandle _Handle, TSBSAMLResourceOpenEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnResourceOpen(TElSAMLServiceProviderHandle _Handle, TSBSAMLResourceOpenEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnResourceRead(TElSAMLServiceProviderHandle _Handle, TSBSAMLResourceReadEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnResourceRead(TElSAMLServiceProviderHandle _Handle, TSBSAMLResourceReadEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnResourceClose(TElSAMLServiceProviderHandle _Handle, TSBSAMLResourceCloseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnResourceClose(TElSAMLServiceProviderHandle _Handle, TSBSAMLResourceCloseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnSend(TElSAMLServiceProviderHandle _Handle, TSBSendEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnSend(TElSAMLServiceProviderHandle _Handle, TSBSendEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnReceive(TElSAMLServiceProviderHandle _Handle, TSBReceiveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnReceive(TElSAMLServiceProviderHandle _Handle, TSBReceiveEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnOpenConnection(TElSAMLServiceProviderHandle _Handle, TSBOpenConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnOpenConnection(TElSAMLServiceProviderHandle _Handle, TSBOpenConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnSSLError(TElSAMLServiceProviderHandle _Handle, TSBErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnSSLError(TElSAMLServiceProviderHandle _Handle, TSBErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnCloseConnection(TElSAMLServiceProviderHandle _Handle, TSBCloseConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnCloseConnection(TElSAMLServiceProviderHandle _Handle, TSBCloseConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnBindingXMLPrepared(TElSAMLServiceProviderHandle _Handle, TSBSAMLBindingXMLPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnBindingXMLPrepared(TElSAMLServiceProviderHandle _Handle, TSBSAMLBindingXMLPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnBeforeBindingUse(TElSAMLServiceProviderHandle _Handle, TSBSAMLBeforeBindingUseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnBeforeBindingUse(TElSAMLServiceProviderHandle _Handle, TSBSAMLBeforeBindingUseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnChooseMetadataIDPDescriptor(TElSAMLServiceProviderHandle _Handle, TSBSAMLChooseMetadataDescriptorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnChooseMetadataIDPDescriptor(TElSAMLServiceProviderHandle _Handle, TSBSAMLChooseMetadataDescriptorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnChooseNameIDPolicy(TElSAMLServiceProviderHandle _Handle, TSBSAMLChooseNameIDPolicyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnChooseNameIDPolicy(TElSAMLServiceProviderHandle _Handle, TSBSAMLChooseNameIDPolicyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnResponderError(TElSAMLServiceProviderHandle _Handle, TSBSAMLResponderErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnResponderError(TElSAMLServiceProviderHandle _Handle, TSBSAMLResponderErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_get_OnResponseStatusCode(TElSAMLServiceProviderHandle _Handle, TSBSAMLResponseStatusCodeEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_set_OnResponseStatusCode(TElSAMLServiceProviderHandle _Handle, TSBSAMLResponseStatusCodeEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProvider_Create(TComponentHandle AOwner, TElSAMLServiceProviderHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSAMLSPSession;
class TElSAMLRequestResult;
class TElSAMLOneTimeUseRecord;
class TElSAMLCustomOneTimeUseCache;
class TElSAMLMemoryOneTimeUseCache;
class TElSAMLServiceProvider;

#ifdef SB_USE_CLASS_TELSAMLSPSESSION
class TElSAMLSPSession: public TElSAMLSession
{
	private:
		SB_DISABLE_COPY(TElSAMLSPSession)
#ifdef SB_USE_CLASS_TELSAMLID
		TElSAMLID* _Inst_NameID;
#endif /* SB_USE_CLASS_TELSAMLID */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_SessionIndexes;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_SessionIndexes;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
		virtual void Generate(int32_t TTL);

		virtual TSBSAMLSPStage get_Stage();

		virtual void set_Stage(TSBSAMLSPStage Value);

		SB_DECLARE_PROPERTY(TSBSAMLSPStage, get_Stage, set_Stage, TElSAMLSPSession, Stage);

		virtual void get_SAMLSession(std::string &OutResult);

		virtual void set_SAMLSession(const std::string &Value);

		virtual void get_AuthnRequestID(std::string &OutResult);

		virtual void set_AuthnRequestID(const std::string &Value);

		virtual void get_LogoutRequestID(std::string &OutResult);

		virtual void set_LogoutRequestID(const std::string &Value);

		virtual bool get_SAMLCookieSet();

		virtual void set_SAMLCookieSet(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SAMLCookieSet, set_SAMLCookieSet, TElSAMLSPSession, SAMLCookieSet);

#ifdef SB_USE_CLASS_TELSAMLID
		virtual TElSAMLID* get_NameID();

		virtual void set_NameID(TElSAMLID &Value);

		virtual void set_NameID(TElSAMLID *Value);

		SB_DECLARE_PROPERTY(TElSAMLID*, get_NameID, set_NameID, TElSAMLSPSession, NameID);
#endif /* SB_USE_CLASS_TELSAMLID */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_SessionIndexes();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_SessionIndexes, TElSAMLSPSession, SessionIndexes);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_SessionIndexes();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_SessionIndexes, TElSAMLSPSession, SessionIndexes);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual bool get_Redirected();

		virtual void set_Redirected(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Redirected, set_Redirected, TElSAMLSPSession, Redirected);

		TElSAMLSPSession(TElSAMLSPSessionHandle handle, TElOwnHandle ownHandle);

		TElSAMLSPSession();

		virtual ~TElSAMLSPSession();

};
#endif /* SB_USE_CLASS_TELSAMLSPSESSION */

#ifdef SB_USE_CLASS_TELSAMLREQUESTRESULT
class TElSAMLRequestResult: public TObject
{
	private:
		SB_DISABLE_COPY(TElSAMLRequestResult)
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		TElXMLDOMDocument* _Inst_Doc;
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */
#ifdef SB_USE_CLASS_TELSAMLSTATUSRESPONSETYPE
		TElSAMLStatusResponseType* _Inst_Response;
#endif /* SB_USE_CLASS_TELSAMLSTATUSRESPONSETYPE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual TElXMLDOMDocument* get_Doc();

		SB_DECLARE_PROPERTY_GET(TElXMLDOMDocument*, get_Doc, TElSAMLRequestResult, Doc);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATUSRESPONSETYPE
		virtual TElSAMLStatusResponseType* get_Response();

		SB_DECLARE_PROPERTY_GET(TElSAMLStatusResponseType*, get_Response, TElSAMLRequestResult, Response);
#endif /* SB_USE_CLASS_TELSAMLSTATUSRESPONSETYPE */

		TElSAMLRequestResult(TElSAMLRequestResultHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASSES_TELSAMLSTATUSRESPONSETYPE_AND_TELXMLDOMDOCUMENT
		TElSAMLRequestResult(TElXMLDOMDocument &Doc, TElSAMLStatusResponseType &Response);

		TElSAMLRequestResult(TElXMLDOMDocument *Doc, TElSAMLStatusResponseType *Response);
#endif /* SB_USE_CLASSES_TELSAMLSTATUSRESPONSETYPE_AND_TELXMLDOMDOCUMENT */

		virtual ~TElSAMLRequestResult();

};
#endif /* SB_USE_CLASS_TELSAMLREQUESTRESULT */

#ifdef SB_USE_CLASS_TELSAMLONETIMEUSERECORD
class TElSAMLOneTimeUseRecord: public TObject
{
	private:
		SB_DISABLE_COPY(TElSAMLOneTimeUseRecord)
	public:
		virtual void get_ID(std::string &OutResult);

		virtual void set_ID(const std::string &Value);

		virtual int64_t get_IssueInstant();

		virtual void set_IssueInstant(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_IssueInstant, set_IssueInstant, TElSAMLOneTimeUseRecord, IssueInstant);

		TElSAMLOneTimeUseRecord(TElSAMLOneTimeUseRecordHandle handle, TElOwnHandle ownHandle);

		TElSAMLOneTimeUseRecord();

};
#endif /* SB_USE_CLASS_TELSAMLONETIMEUSERECORD */

#ifdef SB_USE_CLASS_TELSAMLCUSTOMONETIMEUSECACHE
class TElSAMLCustomOneTimeUseCache: public TObject
{
	private:
		SB_DISABLE_COPY(TElSAMLCustomOneTimeUseCache)
	public:
		virtual void Lock();

		virtual void Unlock();

		virtual void Clear();

#ifdef SB_USE_CLASS_TELSAMLASSERTIONELEMENT
		virtual int32_t Add(TElSAMLAssertionElement &Assertion);

		virtual int32_t Add(TElSAMLAssertionElement *Assertion);
#endif /* SB_USE_CLASS_TELSAMLASSERTIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONELEMENT
		virtual bool Find(TElSAMLAssertionElement &Assertion);

		virtual bool Find(TElSAMLAssertionElement *Assertion);
#endif /* SB_USE_CLASS_TELSAMLASSERTIONELEMENT */

		TElSAMLCustomOneTimeUseCache(TElSAMLCustomOneTimeUseCacheHandle handle, TElOwnHandle ownHandle);

		TElSAMLCustomOneTimeUseCache();

};
#endif /* SB_USE_CLASS_TELSAMLCUSTOMONETIMEUSECACHE */

#ifdef SB_USE_CLASS_TELSAMLMEMORYONETIMEUSECACHE
class TElSAMLMemoryOneTimeUseCache: public TElSAMLCustomOneTimeUseCache
{
	private:
		SB_DISABLE_COPY(TElSAMLMemoryOneTimeUseCache)
	public:
		virtual void Lock();

		virtual void Unlock();

		virtual void Clear();

#ifdef SB_USE_CLASS_TELSAMLASSERTIONELEMENT
		virtual int32_t Add(TElSAMLAssertionElement &Assertion);

		virtual int32_t Add(TElSAMLAssertionElement *Assertion);
#endif /* SB_USE_CLASS_TELSAMLASSERTIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONELEMENT
		virtual bool Find(TElSAMLAssertionElement &Assertion);

		virtual bool Find(TElSAMLAssertionElement *Assertion);
#endif /* SB_USE_CLASS_TELSAMLASSERTIONELEMENT */

		TElSAMLMemoryOneTimeUseCache(TElSAMLMemoryOneTimeUseCacheHandle handle, TElOwnHandle ownHandle);

		TElSAMLMemoryOneTimeUseCache();

};
#endif /* SB_USE_CLASS_TELSAMLMEMORYONETIMEUSECACHE */

#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDER
class TElSAMLServiceProvider: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSAMLServiceProvider)
#ifdef SB_USE_CLASS_TELHTTPSSERVER
		TElHTTPSServer* _Inst_Control;
#endif /* SB_USE_CLASS_TELHTTPSSERVER */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_ProtectedResources;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_ProtectedResources;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		TElSAMLEndpoint* _Inst_IDPSingleSignOnServices;
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */
#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		TElSAMLEndpoint* _Inst_IDPSingleLogoutServices;
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */
#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		TElSAMLEndpoint* _Inst_IDPArtifactResolutionServices;
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */
#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		TElSAMLEndpoint* _Inst_IDPAttributeQueryServices;
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */
#ifdef SB_USE_CLASS_TELCUSTOMSESSIONMANAGER
		TElCustomSessionManager* _Inst_SessionManager;
#endif /* SB_USE_CLASS_TELCUSTOMSESSIONMANAGER */
#ifdef SB_USE_CLASS_TELSAMLCUSTOMONETIMEUSECACHE
		TElSAMLCustomOneTimeUseCache* _Inst_AssertionsOneTimeUseCache;
#endif /* SB_USE_CLASS_TELSAMLCUSTOMONETIMEUSECACHE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_IDPSigningCertificate;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_IDPEncryptionCertificate;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_IDPMetaSigningCertificate;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_IDPNameIDFormats;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_IDPNameIDFormats;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_SigningCertificate;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_EncryptionCertificate;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_MetaSigningCertificate;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE
		TElCustomArtifactStorage* _Inst_ArtifactStorage;
#endif /* SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE */

		void initInstances();

	public:
		void LoadMetadata(const std::string &URI);

#ifdef SB_USE_CLASS_TSTREAM
		void SaveMetadata(TStream &Strm);

		void SaveMetadata(TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

		void Open();

		void DataAvailable();

		void Close(bool Silent);

#ifdef SB_USE_CLASSES_TELSAMLREQUESTABSTRACTTYPE_AND_TELSAMLREQUESTRESULT
		TElSAMLRequestResultHandle SendRequest(TElSAMLRequestAbstractType &Request);

		TElSAMLRequestResultHandle SendRequest(TElSAMLRequestAbstractType *Request);
#endif /* SB_USE_CLASSES_TELSAMLREQUESTABSTRACTTYPE_AND_TELSAMLREQUESTRESULT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		int32_t AddIDPSingleSignOnService(TElSAMLEndpoint &Endpoint);

		int32_t AddIDPSingleSignOnService(TElSAMLEndpoint *Endpoint);
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		int32_t AddIDPSingleLogoutService(TElSAMLEndpoint &Endpoint);

		int32_t AddIDPSingleLogoutService(TElSAMLEndpoint *Endpoint);
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		int32_t AddIDPArtifactResolutionService(TElSAMLEndpoint &Endpoint);

		int32_t AddIDPArtifactResolutionService(TElSAMLEndpoint *Endpoint);
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		int32_t AddIDPAttributeQueryService(TElSAMLEndpoint &Endpoint);

		int32_t AddIDPAttributeQueryService(TElSAMLEndpoint *Endpoint);
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

		void RemoveIDPSingleSignOnService(int32_t Index);

		void RemoveIDPSingleLogoutService(int32_t Index);

		void RemoveIDPArtifactResolutionService(int32_t Index);

		void RemoveIDPAttributeQueryService(int32_t Index);

#ifdef SB_USE_CLASS_TELHTTPSSERVER
		virtual TElHTTPSServer* get_Control();

		SB_DECLARE_PROPERTY_GET(TElHTTPSServer*, get_Control, TElSAMLServiceProvider, Control);
#endif /* SB_USE_CLASS_TELHTTPSSERVER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_ProtectedResources();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_ProtectedResources, TElSAMLServiceProvider, ProtectedResources);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_ProtectedResources();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_ProtectedResources, TElSAMLServiceProvider, ProtectedResources);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		virtual TElSAMLEndpoint* get_IDPSingleSignOnServices(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		virtual TElSAMLEndpoint* get_IDPSingleLogoutServices(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		virtual TElSAMLEndpoint* get_IDPArtifactResolutionServices(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		virtual TElSAMLEndpoint* get_IDPAttributeQueryServices(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

		virtual int32_t get_IDPSignleSignOnServiceCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_IDPSignleSignOnServiceCount, TElSAMLServiceProvider, IDPSignleSignOnServiceCount);

		virtual int32_t get_IDPSingleLogoutServiceCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_IDPSingleLogoutServiceCount, TElSAMLServiceProvider, IDPSingleLogoutServiceCount);

		virtual int32_t get_IDPArtifactResolutionServiceCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_IDPArtifactResolutionServiceCount, TElSAMLServiceProvider, IDPArtifactResolutionServiceCount);

		virtual int32_t get_IDPAttributeQueryServiceCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_IDPAttributeQueryServiceCount, TElSAMLServiceProvider, IDPAttributeQueryServiceCount);

		virtual void get_SourceID(std::vector<uint8_t> &OutResult);

		virtual void set_SourceID(const std::vector<uint8_t> &Value);

		virtual void get_IDPSourceID(std::vector<uint8_t> &OutResult);

		virtual void set_IDPSourceID(const std::vector<uint8_t> &Value);

		virtual bool get_AutoIDPSourceID();

		virtual void set_AutoIDPSourceID(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoIDPSourceID, set_AutoIDPSourceID, TElSAMLServiceProvider, AutoIDPSourceID);

		virtual bool get_Active();

		SB_DECLARE_PROPERTY_GET(bool, get_Active, TElSAMLServiceProvider, Active);

		virtual int32_t get_SendBufferSize();

		virtual void set_SendBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SendBufferSize, set_SendBufferSize, TElSAMLServiceProvider, SendBufferSize);

		virtual void get_ServerName(std::string &OutResult);

		virtual void set_ServerName(const std::string &Value);

#ifdef SB_USE_CLASS_TELCUSTOMSESSIONMANAGER
		virtual TElCustomSessionManager* get_SessionManager();

		virtual void set_SessionManager(TElCustomSessionManager &Value);

		virtual void set_SessionManager(TElCustomSessionManager *Value);

		SB_DECLARE_PROPERTY(TElCustomSessionManager*, get_SessionManager, set_SessionManager, TElSAMLServiceProvider, SessionManager);
#endif /* SB_USE_CLASS_TELCUSTOMSESSIONMANAGER */

#ifdef SB_USE_CLASS_TELSAMLCUSTOMONETIMEUSECACHE
		virtual TElSAMLCustomOneTimeUseCache* get_AssertionsOneTimeUseCache();

		virtual void set_AssertionsOneTimeUseCache(TElSAMLCustomOneTimeUseCache &Value);

		virtual void set_AssertionsOneTimeUseCache(TElSAMLCustomOneTimeUseCache *Value);

		SB_DECLARE_PROPERTY(TElSAMLCustomOneTimeUseCache*, get_AssertionsOneTimeUseCache, set_AssertionsOneTimeUseCache, TElSAMLServiceProvider, AssertionsOneTimeUseCache);
#endif /* SB_USE_CLASS_TELSAMLCUSTOMONETIMEUSECACHE */

		virtual void get_URL(std::string &OutResult);

		virtual void set_URL(const std::string &Value);

		virtual TSBSAMLBindingType get_SPToIDPBinding();

		virtual void set_SPToIDPBinding(TSBSAMLBindingType Value);

		SB_DECLARE_PROPERTY(TSBSAMLBindingType, get_SPToIDPBinding, set_SPToIDPBinding, TElSAMLServiceProvider, SPToIDPBinding);

		virtual TSBSAMLBindingType get_PrefferedIDPToSPBinding();

		virtual void set_PrefferedIDPToSPBinding(TSBSAMLBindingType Value);

		SB_DECLARE_PROPERTY(TSBSAMLBindingType, get_PrefferedIDPToSPBinding, set_PrefferedIDPToSPBinding, TElSAMLServiceProvider, PrefferedIDPToSPBinding);

		virtual TSBSAMLBindingTypes get_SingleLogoutServiceBindings();

		virtual void set_SingleLogoutServiceBindings(TSBSAMLBindingTypes Value);

		SB_DECLARE_PROPERTY(TSBSAMLBindingTypes, get_SingleLogoutServiceBindings, set_SingleLogoutServiceBindings, TElSAMLServiceProvider, SingleLogoutServiceBindings);

		virtual TSBSAMLBindingTypes get_AssertionConsumerServiceBindings();

		virtual void set_AssertionConsumerServiceBindings(TSBSAMLBindingTypes Value);

		SB_DECLARE_PROPERTY(TSBSAMLBindingTypes, get_AssertionConsumerServiceBindings, set_AssertionConsumerServiceBindings, TElSAMLServiceProvider, AssertionConsumerServiceBindings);

		virtual TSBSAMLBindingTypes get_ArtifactResolutionServiceBindings();

		SB_DECLARE_PROPERTY_GET(TSBSAMLBindingTypes, get_ArtifactResolutionServiceBindings, TElSAMLServiceProvider, ArtifactResolutionServiceBindings);

		virtual void get_MetadataURL(std::string &OutResult);

		virtual void set_MetadataURL(const std::string &Value);

		virtual void get_AssertionConsumerService(std::string &OutResult);

		virtual void set_AssertionConsumerService(const std::string &Value);

		virtual void get_SingleLogoutService(std::string &OutResult);

		virtual void set_SingleLogoutService(const std::string &Value);

		virtual void get_ArtifactResolutionService(std::string &OutResult);

		virtual void set_ArtifactResolutionService(const std::string &Value);

		virtual void get_LogoutPage(std::string &OutResult);

		virtual void set_LogoutPage(const std::string &Value);

		virtual void get_Issuer(std::string &OutResult);

		virtual void set_Issuer(const std::string &Value);

		virtual void get_SessionCookieName(std::string &OutResult);

		virtual void set_SessionCookieName(const std::string &Value);

		virtual void get_SAMLSessionCookieName(std::string &OutResult);

		virtual void set_SAMLSessionCookieName(const std::string &Value);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_IDPSigningCertificate();

		virtual void set_IDPSigningCertificate(TElX509Certificate &Value);

		virtual void set_IDPSigningCertificate(TElX509Certificate *Value);

		SB_DECLARE_PROPERTY(TElX509Certificate*, get_IDPSigningCertificate, set_IDPSigningCertificate, TElSAMLServiceProvider, IDPSigningCertificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_IDPEncryptionCertificate();

		virtual void set_IDPEncryptionCertificate(TElX509Certificate &Value);

		virtual void set_IDPEncryptionCertificate(TElX509Certificate *Value);

		SB_DECLARE_PROPERTY(TElX509Certificate*, get_IDPEncryptionCertificate, set_IDPEncryptionCertificate, TElSAMLServiceProvider, IDPEncryptionCertificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_IDPMetaSigningCertificate();

		virtual void set_IDPMetaSigningCertificate(TElX509Certificate &Value);

		virtual void set_IDPMetaSigningCertificate(TElX509Certificate *Value);

		SB_DECLARE_PROPERTY(TElX509Certificate*, get_IDPMetaSigningCertificate, set_IDPMetaSigningCertificate, TElSAMLServiceProvider, IDPMetaSigningCertificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual bool get_IDPAllowCreateIdentifier();

		virtual void set_IDPAllowCreateIdentifier(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IDPAllowCreateIdentifier, set_IDPAllowCreateIdentifier, TElSAMLServiceProvider, IDPAllowCreateIdentifier);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_IDPNameIDFormats();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_IDPNameIDFormats, TElSAMLServiceProvider, IDPNameIDFormats);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_IDPNameIDFormats();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_IDPNameIDFormats, TElSAMLServiceProvider, IDPNameIDFormats);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual int32_t get_IDPNameIDFormatIndex();

		virtual void set_IDPNameIDFormatIndex(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_IDPNameIDFormatIndex, set_IDPNameIDFormatIndex, TElSAMLServiceProvider, IDPNameIDFormatIndex);

		virtual void get_IDPPrefferedNameIDFormat(std::string &OutResult);

		virtual void set_IDPPrefferedNameIDFormat(const std::string &Value);

		virtual SBSAMLServiceProvider_TSBSAMLAccessLevel get_AccessLevel();

		virtual void set_AccessLevel(SBSAMLServiceProvider_TSBSAMLAccessLevel Value);

		SB_DECLARE_PROPERTY(SBSAMLServiceProvider_TSBSAMLAccessLevel, get_AccessLevel, set_AccessLevel, TElSAMLServiceProvider, AccessLevel);

		virtual int32_t get_SessionTTL();

		virtual void set_SessionTTL(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SessionTTL, set_SessionTTL, TElSAMLServiceProvider, SessionTTL);

		virtual int32_t get_MaxIssueInstantTimeDiff();

		virtual void set_MaxIssueInstantTimeDiff(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxIssueInstantTimeDiff, set_MaxIssueInstantTimeDiff, TElSAMLServiceProvider, MaxIssueInstantTimeDiff);

		virtual bool get_SignAuthnRequests();

		virtual void set_SignAuthnRequests(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SignAuthnRequests, set_SignAuthnRequests, TElSAMLServiceProvider, SignAuthnRequests);

		virtual bool get_SignLogoutRequests();

		virtual void set_SignLogoutRequests(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SignLogoutRequests, set_SignLogoutRequests, TElSAMLServiceProvider, SignLogoutRequests);

		virtual bool get_SignArtifactResolveRequests();

		virtual void set_SignArtifactResolveRequests(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SignArtifactResolveRequests, set_SignArtifactResolveRequests, TElSAMLServiceProvider, SignArtifactResolveRequests);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElSAMLServiceProvider, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_SigningCertificate();

		virtual void set_SigningCertificate(TElX509Certificate &Value);

		virtual void set_SigningCertificate(TElX509Certificate *Value);

		SB_DECLARE_PROPERTY(TElX509Certificate*, get_SigningCertificate, set_SigningCertificate, TElSAMLServiceProvider, SigningCertificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_EncryptionCertificate();

		virtual void set_EncryptionCertificate(TElX509Certificate &Value);

		virtual void set_EncryptionCertificate(TElX509Certificate *Value);

		SB_DECLARE_PROPERTY(TElX509Certificate*, get_EncryptionCertificate, set_EncryptionCertificate, TElSAMLServiceProvider, EncryptionCertificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_MetaSigningCertificate();

		virtual void set_MetaSigningCertificate(TElX509Certificate &Value);

		virtual void set_MetaSigningCertificate(TElX509Certificate *Value);

		SB_DECLARE_PROPERTY(TElX509Certificate*, get_MetaSigningCertificate, set_MetaSigningCertificate, TElSAMLServiceProvider, MetaSigningCertificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual void get_RedirectOnLogoutPage(std::string &OutResult);

		virtual void set_RedirectOnLogoutPage(const std::string &Value);

#ifdef SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE
		virtual TElCustomArtifactStorage* get_ArtifactStorage();

		virtual void set_ArtifactStorage(TElCustomArtifactStorage &Value);

		virtual void set_ArtifactStorage(TElCustomArtifactStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomArtifactStorage*, get_ArtifactStorage, set_ArtifactStorage, TElSAMLServiceProvider, ArtifactStorage);
#endif /* SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE */

		virtual bool get_RedirectToSuppliedResource();

		virtual void set_RedirectToSuppliedResource(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RedirectToSuppliedResource, set_RedirectToSuppliedResource, TElSAMLServiceProvider, RedirectToSuppliedResource);

		virtual bool get_SignMetadata();

		virtual void set_SignMetadata(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SignMetadata, set_SignMetadata, TElSAMLServiceProvider, SignMetadata);

		virtual void get_IDPEntityID(std::string &OutResult);

		virtual void set_IDPEntityID(const std::string &Value);

		virtual void get_OnSessionCreate(SBSAMLServiceProvider_TSBSAMLSessionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSessionCreate(SBSAMLServiceProvider_TSBSAMLSessionEvent pMethodValue, void * pDataValue);

		virtual void get_OnSessionDestroy(SBSAMLServiceProvider_TSBSAMLSessionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSessionDestroy(SBSAMLServiceProvider_TSBSAMLSessionEvent pMethodValue, void * pDataValue);

		virtual void get_OnLogout(SBSAMLServiceProvider_TSBSAMLLogoutEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnLogout(SBSAMLServiceProvider_TSBSAMLLogoutEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeHTTPSServerUse(SBXMLSAMLCommon_TSBSAMLBeforeHTTPSServerUseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeHTTPSServerUse(SBXMLSAMLCommon_TSBSAMLBeforeHTTPSServerUseEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeHTTPSClientUse(TSBSAMLBeforeHTTPSClientUseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeHTTPSClientUse(TSBSAMLBeforeHTTPSClientUseEvent pMethodValue, void * pDataValue);

		virtual void get_OnRequestPrepared(TSBSAMLRequestPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRequestPrepared(TSBSAMLRequestPreparedEvent pMethodValue, void * pDataValue);

		virtual void get_OnResponsePrepared(TSBSAMLResponsePreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnResponsePrepared(TSBSAMLResponsePreparedEvent pMethodValue, void * pDataValue);

		virtual void get_OnResponseReceived(TSBSAMLResponseReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnResponseReceived(TSBSAMLResponseReceivedEvent pMethodValue, void * pDataValue);

		virtual void get_OnRequestReceived(TSBSAMLRequestReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRequestReceived(TSBSAMLRequestReceivedEvent pMethodValue, void * pDataValue);

		virtual void get_OnChangeSessionStage(TSBSAMLChangeSPSessionStageEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnChangeSessionStage(TSBSAMLChangeSPSessionStageEvent pMethodValue, void * pDataValue);

		virtual void get_OnMetadataPrepared(TSBSAMLMetadataPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnMetadataPrepared(TSBSAMLMetadataPreparedEvent pMethodValue, void * pDataValue);

		virtual void get_OnResourceOpen(TSBSAMLResourceOpenEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnResourceOpen(TSBSAMLResourceOpenEvent pMethodValue, void * pDataValue);

		virtual void get_OnResourceRead(TSBSAMLResourceReadEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnResourceRead(TSBSAMLResourceReadEvent pMethodValue, void * pDataValue);

		virtual void get_OnResourceClose(TSBSAMLResourceCloseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnResourceClose(TSBSAMLResourceCloseEvent pMethodValue, void * pDataValue);

		virtual void get_OnSend(TSBSendEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSend(TSBSendEvent pMethodValue, void * pDataValue);

		virtual void get_OnReceive(TSBReceiveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReceive(TSBReceiveEvent pMethodValue, void * pDataValue);

		virtual void get_OnOpenConnection(TSBOpenConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOpenConnection(TSBOpenConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnSSLError(TSBErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSSLError(TSBErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnCloseConnection(TSBCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCloseConnection(TSBCloseConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnBindingXMLPrepared(TSBSAMLBindingXMLPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBindingXMLPrepared(TSBSAMLBindingXMLPreparedEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeBindingUse(TSBSAMLBeforeBindingUseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeBindingUse(TSBSAMLBeforeBindingUseEvent pMethodValue, void * pDataValue);

		virtual void get_OnChooseMetadataIDPDescriptor(TSBSAMLChooseMetadataDescriptorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnChooseMetadataIDPDescriptor(TSBSAMLChooseMetadataDescriptorEvent pMethodValue, void * pDataValue);

		virtual void get_OnChooseNameIDPolicy(TSBSAMLChooseNameIDPolicyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnChooseNameIDPolicy(TSBSAMLChooseNameIDPolicyEvent pMethodValue, void * pDataValue);

		virtual void get_OnResponderError(TSBSAMLResponderErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnResponderError(TSBSAMLResponderErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnResponseStatusCode(TSBSAMLResponseStatusCodeEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnResponseStatusCode(TSBSAMLResponseStatusCodeEvent pMethodValue, void * pDataValue);

		TElSAMLServiceProvider(TElSAMLServiceProviderHandle handle, TElOwnHandle ownHandle);

		explicit TElSAMLServiceProvider(TComponent &AOwner);

		explicit TElSAMLServiceProvider(TComponent *AOwner);

		virtual ~TElSAMLServiceProvider();

};
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSAMLSERVICEPROVIDER */
