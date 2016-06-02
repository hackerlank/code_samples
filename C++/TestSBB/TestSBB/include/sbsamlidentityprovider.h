#ifndef __INC_SBSAMLIDENTITYPROVIDER
#define __INC_SBSAMLIDENTITYPROVIDER

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
#include "sbdictionary.h"
#include "sbhttpsconstants.h"
#include "sbhttpsserver.h"
#include "sbsharedresource.h"
#include "sbhashfunction.h"
#include "sbsslconstants.h"
#include "sbcookiemgr.h"
#include "sbxmlcore.h"
#include "sbxmlsec.h"
#include "sbxmlsig.h"
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
typedef TElClassHandle TElSAMLIDPSessionHandle;

typedef TElClassHandle TElSAMLServiceProviderInfoHandle;

typedef TElClassHandle TElSAMLSPDataHandle;

typedef TElClassHandle TElSAMLIDPCustomAuthSourceHandle;

typedef TElClassHandle TElSAMLIDRecordHandle;

typedef TElClassHandle TElSAMLIDPPasswordMemoryAuthSourceHandle;

typedef TElClassHandle TElSAMLIdPSSOLinkHandle;

typedef TElClassHandle TElSAMLIdentityProviderHandle;

typedef uint8_t TSBSAMLIDPStageRaw;

typedef enum
{
	idpsStart = 0,
	idpsIdPSSORecv = 1,
	idpsAuthnRequestRecv = 2,
	idpsChallengeSent = 3,
	idpsCredentialsRecv = 4,
	idpsResponseSent = 5,
	idpsLoggedIn = 6,
	idpsLogoutRequestRecv = 7,
	idpsLogoutResponseSent = 8,
	idpsArtifactResolveRecv = 9,
	idpsArtifactResponseSent = 10,
	idpsAttributeQueryRecv = 11,
	idpsAttributeResponseSent = 12
} TSBSAMLIDPStage;

typedef void (SB_CALLBACK *SBSAMLIdentityProvider_TSBSAMLBeforeHTTPSServerUseEvent)(void * _ObjectData, TObjectHandle Sender, TElHTTPSServerHandle HTTPSServer);

typedef void (SB_CALLBACK *TSBSAMLPageContentEvent)(void * _ObjectData, TObjectHandle Sender, TElHTTPServerRequestParamsHandle Request, TElHTTPServerResponseParamsHandle Response, uint8_t pContent[], int32_t * szContent, int32_t * Size);

typedef void (SB_CALLBACK *TSBSAMLChangeIDPSessionStageEvent)(void * _ObjectData, TObjectHandle Sender, TElSAMLIDPSessionHandle Session, TSBSAMLIDPStageRaw Stage);

typedef void (SB_CALLBACK *SBSAMLIdentityProvider_TSBSAMLSessionEvent)(void * _ObjectData, TObjectHandle Sender, TElSAMLIDPSessionHandle Session);

typedef void (SB_CALLBACK *SBSAMLIdentityProvider_TSBSAMLLogoutEvent)(void * _ObjectData, TObjectHandle Sender, TElSAMLIDPSessionHandle Session, TElHTTPServerResponseParamsHandle ResponseParams);

typedef void (SB_CALLBACK *TSBSAMLChooseAuthnContext)(void * _ObjectData, TObjectHandle Sender, TElSAMLAuthnRequestElementHandle Request, char * pcAuthnContextClassRef, int32_t * szAuthnContextClassRef);

typedef void (SB_CALLBACK *TSBSAMLChooseNameIDPolicyFormatEvent)(void * _ObjectData, TObjectHandle Sender, TElSAMLIDPSessionHandle Session, char * pcNameIDPolicy, int32_t * szNameIDPolicy);

typedef uint8_t SBSAMLIdentityProvider_TSBSAMLAccessLevelRaw;

typedef enum
{
	salDomain = 0,
	salExactURL = 1
} SBSAMLIdentityProvider_TSBSAMLAccessLevel;

typedef void (SB_CALLBACK *TSBSAMLIDPGetAttributeEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcID, int32_t szID, const char * pcFormat, int32_t szFormat, TElSAMLAttributeElementHandle Attribute, TElSAMLAttributeElementHandle Res);

typedef void (SB_CALLBACK *TSBSAMLIDPSetAttributeEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcID, int32_t szID, const char * pcFormat, int32_t szFormat, TElSAMLAttributeElementHandle Attribute, int8_t * Res);

#ifdef SB_USE_CLASS_TELSAMLIDPSESSION
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_AddServiceProvider(TElSAMLIDPSessionHandle _Handle, const char * pcSessionIndex, int32_t szSessionIndex, TElSAMLServiceProviderInfoHandle SPInfo);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_RemoveServiceProvider(TElSAMLIDPSessionHandle _Handle, const char * pcSessionIndex, int32_t szSessionIndex);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_get_LoggedIn(TElSAMLIDPSessionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_get_Stage(TElSAMLIDPSessionHandle _Handle, TSBSAMLIDPStageRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_set_Stage(TElSAMLIDPSessionHandle _Handle, TSBSAMLIDPStageRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_get_Login(TElSAMLIDPSessionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_set_Login(TElSAMLIDPSessionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_get_Certificate(TElSAMLIDPSessionHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_set_Certificate(TElSAMLIDPSessionHandle _Handle, TElX509CertificateHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_get_SAMLCookieSet(TElSAMLIDPSessionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_set_SAMLCookieSet(TElSAMLIDPSessionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_get_NameID(TElSAMLIDPSessionHandle _Handle, TElSAMLIDHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_set_NameID(TElSAMLIDPSessionHandle _Handle, TElSAMLIDHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_get_LoginAttempts(TElSAMLIDPSessionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_set_LoginAttempts(TElSAMLIDPSessionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_get_ServiceProviders(TElSAMLIDPSessionHandle _Handle, TElDictionaryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_get_LastSP(TElSAMLIDPSessionHandle _Handle, TElSAMLServiceProviderInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_set_LastSP(TElSAMLIDPSessionHandle _Handle, TElSAMLServiceProviderInfoHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_get_Binding(TElSAMLIDPSessionHandle _Handle, TSBSAMLBindingTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_set_Binding(TElSAMLIDPSessionHandle _Handle, TSBSAMLBindingTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_get_ResponseLocation(TElSAMLIDPSessionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_set_ResponseLocation(TElSAMLIDPSessionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_get_AuthnContextClassRef(TElSAMLIDPSessionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_set_AuthnContextClassRef(TElSAMLIDPSessionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_get_NameIDPolicyFormat(TElSAMLIDPSessionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_set_NameIDPolicyFormat(TElSAMLIDPSessionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_get_SessionIndex(TElSAMLIDPSessionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_set_SessionIndex(TElSAMLIDPSessionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_get_IdPSSO(TElSAMLIDPSessionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_set_IdPSSO(TElSAMLIDPSessionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPSession_Create(TElSAMLIDPSessionHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLIDPSESSION */

#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_CreateForGoogleAppEngine(const char * pcDomain, int32_t szDomain, TElSAMLServiceProviderInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_CreateForGoogleAppEngine_1(TElSAMLServiceProviderInfoHandle _Handle, const char * pcDomain, int32_t szDomain, TElSAMLServiceProviderInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_AddAssertionConsumerService(TElSAMLServiceProviderInfoHandle _Handle, TElSAMLEndpointHandle Endpoint, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_AddSingleLogoutService(TElSAMLServiceProviderInfoHandle _Handle, TElSAMLEndpointHandle Endpoint, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_AddArtifactResolutionService(TElSAMLServiceProviderInfoHandle _Handle, TElSAMLEndpointHandle Endpoint, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_RemoveAssertionConsumerService(TElSAMLServiceProviderInfoHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_RemoveSingleLogoutService(TElSAMLServiceProviderInfoHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_RemoveArtifactResolutionService(TElSAMLServiceProviderInfoHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_FindDefaultAssertionConsumerServiceEP(TElSAMLServiceProviderInfoHandle _Handle, TElSAMLEndpointHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_FindAssertionConsumerServiceEP(TElSAMLServiceProviderInfoHandle _Handle, TSBSAMLBindingTypeRaw Binding, TElSAMLEndpointHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_FindAssertionConsumerServiceEP_1(TElSAMLServiceProviderInfoHandle _Handle, const char * pcLocation, int32_t szLocation, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_FindAssertionConsumerServiceEP_2(TElSAMLServiceProviderInfoHandle _Handle, int32_t Idx, TElSAMLEndpointHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_FindSingleLogoutServiceEP(TElSAMLServiceProviderInfoHandle _Handle, TSBSAMLBindingTypeRaw Binding, TElSAMLEndpointHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_FindArtifactResolutionServiceEP(TElSAMLServiceProviderInfoHandle _Handle, TSBSAMLBindingTypeRaw Binding, TElSAMLEndpointHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_ChooseNameIDFormat(TElSAMLServiceProviderInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_LoadMetadata(TElSAMLServiceProviderInfoHandle _Handle, const char * pcURI, int32_t szURI);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_GetUniqueID(TElSAMLServiceProviderInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_get_EntityID(TElSAMLServiceProviderInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_set_EntityID(TElSAMLServiceProviderInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_get_SPNameQualifier(TElSAMLServiceProviderInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_set_SPNameQualifier(TElSAMLServiceProviderInfoHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_get_IDPNameIDFormats(TElSAMLServiceProviderInfoHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_get_IDPNameIDFormats(TElSAMLServiceProviderInfoHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_get_AssertionConsumerServices(TElSAMLServiceProviderInfoHandle _Handle, int32_t Index, TElSAMLEndpointHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_get_SingleLogoutServices(TElSAMLServiceProviderInfoHandle _Handle, int32_t Index, TElSAMLEndpointHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_get_ArtifactResolutionServices(TElSAMLServiceProviderInfoHandle _Handle, int32_t Index, TElSAMLEndpointHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_get_AssertionConsumerServiceCount(TElSAMLServiceProviderInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_get_SingleLogoutServiceCount(TElSAMLServiceProviderInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_get_ArtifactResolutionServiceCount(TElSAMLServiceProviderInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_get_SigningCertificate(TElSAMLServiceProviderInfoHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_set_SigningCertificate(TElSAMLServiceProviderInfoHandle _Handle, TElX509CertificateHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_get_EncryptionCertificate(TElSAMLServiceProviderInfoHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_set_EncryptionCertificate(TElSAMLServiceProviderInfoHandle _Handle, TElX509CertificateHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_get_MetaSigningCertificate(TElSAMLServiceProviderInfoHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_set_MetaSigningCertificate(TElSAMLServiceProviderInfoHandle _Handle, TElX509CertificateHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_get_SourceID(TElSAMLServiceProviderInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_set_SourceID(TElSAMLServiceProviderInfoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_get_OnBeforeHTTPSClientUse(TElSAMLServiceProviderInfoHandle _Handle, TSBSAMLBeforeHTTPSClientUseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_set_OnBeforeHTTPSClientUse(TElSAMLServiceProviderInfoHandle _Handle, TSBSAMLBeforeHTTPSClientUseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_get_OnChooseMetadataSPDescriptor(TElSAMLServiceProviderInfoHandle _Handle, TSBSAMLChooseMetadataDescriptorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_set_OnChooseMetadataSPDescriptor(TElSAMLServiceProviderInfoHandle _Handle, TSBSAMLChooseMetadataDescriptorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLServiceProviderInfo_Create(TElSAMLServiceProviderInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO */

#ifdef SB_USE_CLASS_TELSAMLSPDATA
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSPData_get_SessionIndex(TElSAMLSPDataHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSPData_set_SessionIndex(TElSAMLSPDataHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSPData_Create(TElSAMLSPDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLSPDATA */

#ifdef SB_USE_CLASS_TELSAMLIDPCUSTOMAUTHSOURCE
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPCustomAuthSource_Add(TElSAMLIDPCustomAuthSourceHandle _Handle, const char * pcID, int32_t szID, const char * pcAuthToken, int32_t szAuthToken);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPCustomAuthSource_Remove(TElSAMLIDPCustomAuthSourceHandle _Handle, const char * pcID, int32_t szID);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPCustomAuthSource_Check(TElSAMLIDPCustomAuthSourceHandle _Handle, const char * pcID, int32_t szID, const char * pcAuthToken, int32_t szAuthToken, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPCustomAuthSource_GetSupportedIdentifierTypes(TElSAMLIDPCustomAuthSourceHandle _Handle, TStringListHandle OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPCustomAuthSource_GetIdentifier(TElSAMLIDPCustomAuthSourceHandle _Handle, const char * pcID, int32_t szID, const char * pcFormat, int32_t szFormat, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPCustomAuthSource_SetIdentifier(TElSAMLIDPCustomAuthSourceHandle _Handle, const char * pcID, int32_t szID, const char * pcFormat, int32_t szFormat, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPCustomAuthSource_GetAttribute(TElSAMLIDPCustomAuthSourceHandle _Handle, const char * pcID, int32_t szID, const char * pcFormat, int32_t szFormat, TElSAMLAttributeElementHandle Attribute, TElSAMLAttributeElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPCustomAuthSource_SetAttribute(TElSAMLIDPCustomAuthSourceHandle _Handle, const char * pcID, int32_t szID, const char * pcFormat, int32_t szFormat, TElSAMLAttributeElementHandle Attribute, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPCustomAuthSource_Create(TComponentHandle AOwner, TComponentHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLIDPCUSTOMAUTHSOURCE */

#ifdef SB_USE_CLASS_TELSAMLIDRECORD
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDRecord_get_Identifiers(TElSAMLIDRecordHandle _Handle, TElDictionaryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDRecord_get_AuthToken(TElSAMLIDRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDRecord_set_AuthToken(TElSAMLIDRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDRecord_Create(TElSAMLIDRecordHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLIDRECORD */

#ifdef SB_USE_CLASS_TELSAMLIDPPASSWORDMEMORYAUTHSOURCE
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPPasswordMemoryAuthSource_GetSupportedIdentifierTypes(TElSAMLIDPPasswordMemoryAuthSourceHandle _Handle, TStringListHandle OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPPasswordMemoryAuthSource_GetIdentifier(TElSAMLIDPPasswordMemoryAuthSourceHandle _Handle, const char * pcID, int32_t szID, const char * pcFormat, int32_t szFormat, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPPasswordMemoryAuthSource_SetIdentifier(TElSAMLIDPPasswordMemoryAuthSourceHandle _Handle, const char * pcID, int32_t szID, const char * pcFormat, int32_t szFormat, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPPasswordMemoryAuthSource_GetAttribute(TElSAMLIDPPasswordMemoryAuthSourceHandle _Handle, const char * pcID, int32_t szID, const char * pcFormat, int32_t szFormat, TElSAMLAttributeElementHandle Attribute, TElSAMLAttributeElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPPasswordMemoryAuthSource_SetAttribute(TElSAMLIDPPasswordMemoryAuthSourceHandle _Handle, const char * pcID, int32_t szID, const char * pcFormat, int32_t szFormat, TElSAMLAttributeElementHandle Attribute, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPPasswordMemoryAuthSource_Add(TElSAMLIDPPasswordMemoryAuthSourceHandle _Handle, const char * pcID, int32_t szID, const char * pcAuthToken, int32_t szAuthToken);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPPasswordMemoryAuthSource_Remove(TElSAMLIDPPasswordMemoryAuthSourceHandle _Handle, const char * pcID, int32_t szID);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPPasswordMemoryAuthSource_Check(TElSAMLIDPPasswordMemoryAuthSourceHandle _Handle, const char * pcID, int32_t szID, const char * pcAuthToken, int32_t szAuthToken, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPPasswordMemoryAuthSource_get_OnGetAttribute(TElSAMLIDPPasswordMemoryAuthSourceHandle _Handle, TSBSAMLIDPGetAttributeEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPPasswordMemoryAuthSource_set_OnGetAttribute(TElSAMLIDPPasswordMemoryAuthSourceHandle _Handle, TSBSAMLIDPGetAttributeEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPPasswordMemoryAuthSource_get_OnSetAttribute(TElSAMLIDPPasswordMemoryAuthSourceHandle _Handle, TSBSAMLIDPSetAttributeEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPPasswordMemoryAuthSource_set_OnSetAttribute(TElSAMLIDPPasswordMemoryAuthSourceHandle _Handle, TSBSAMLIDPSetAttributeEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPPasswordMemoryAuthSource_Create(TElSAMLIDPPasswordMemoryAuthSourceHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLIDPPASSWORDMEMORYAUTHSOURCE */

#ifdef SB_USE_CLASS_TELSAMLIDPSSOLINK
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdPSSOLink_get_URL(TElSAMLIdPSSOLinkHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdPSSOLink_set_URL(TElSAMLIdPSSOLinkHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdPSSOLink_get_RelayState(TElSAMLIdPSSOLinkHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdPSSOLink_set_RelayState(TElSAMLIdPSSOLinkHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdPSSOLink_get_SPIndex(TElSAMLIdPSSOLinkHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdPSSOLink_set_SPIndex(TElSAMLIdPSSOLinkHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdPSSOLink_Create(TElSAMLIdPSSOLinkHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLIDPSSOLINK */

#ifdef SB_USE_CLASS_TELSAMLIDENTITYPROVIDER
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_Open(TElSAMLIdentityProviderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_DataAvailable(TElSAMLIdentityProviderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_Close(TElSAMLIdentityProviderHandle _Handle, int8_t Silent);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_SaveMetadata(TElSAMLIdentityProviderHandle _Handle, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_AddServiceProvider(TElSAMLIdentityProviderHandle _Handle, TElSAMLServiceProviderInfoHandle SPInfo, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_RemoveServiceProvider(TElSAMLIdentityProviderHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_AddIdPSSOLink(TElSAMLIdentityProviderHandle _Handle, TElSAMLIdPSSOLinkHandle Link, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_RemoveIdPSSOLink(TElSAMLIdentityProviderHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_ServiceProviders(TElSAMLIdentityProviderHandle _Handle, int32_t Index, TElSAMLServiceProviderInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_ServiceProviderCount(TElSAMLIdentityProviderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_IdPSSOLinks(TElSAMLIdentityProviderHandle _Handle, int32_t Index, TElSAMLIdPSSOLinkHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_IdPSSOLinkCount(TElSAMLIdentityProviderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_Control(TElSAMLIdentityProviderHandle _Handle, TElHTTPSServerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_Active(TElSAMLIdentityProviderHandle _Handle, int8_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_SupportedAuthnContextClasses(TElSAMLIdentityProviderHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_SupportedAuthnContextClasses(TElSAMLIdentityProviderHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_SourceID(TElSAMLIdentityProviderHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_SourceID(TElSAMLIdentityProviderHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_SendBufferSize(TElSAMLIdentityProviderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_SendBufferSize(TElSAMLIdentityProviderHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_ServerName(TElSAMLIdentityProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_ServerName(TElSAMLIdentityProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_URL(TElSAMLIdentityProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_URL(TElSAMLIdentityProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_SingleSignOnService(TElSAMLIdentityProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_SingleSignOnService(TElSAMLIdentityProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_SingleLogoutService(TElSAMLIdentityProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_SingleLogoutService(TElSAMLIdentityProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_ArtifactResolutionService(TElSAMLIdentityProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_ArtifactResolutionService(TElSAMLIdentityProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_AttributeQueryService(TElSAMLIdentityProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_AttributeQueryService(TElSAMLIdentityProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_SessionCookieName(TElSAMLIdentityProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_SessionCookieName(TElSAMLIdentityProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_CertStorage(TElSAMLIdentityProviderHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_CertStorage(TElSAMLIdentityProviderHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_AccessLevel(TElSAMLIdentityProviderHandle _Handle, SBSAMLIdentityProvider_TSBSAMLAccessLevelRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_AccessLevel(TElSAMLIdentityProviderHandle _Handle, SBSAMLIdentityProvider_TSBSAMLAccessLevelRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_SessionTTL(TElSAMLIdentityProviderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_SessionTTL(TElSAMLIdentityProviderHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_SAMLSessionTTL(TElSAMLIdentityProviderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_SAMLSessionTTL(TElSAMLIdentityProviderHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_MaxIssueInstantTimeDiff(TElSAMLIdentityProviderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_MaxIssueInstantTimeDiff(TElSAMLIdentityProviderHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_SessionManager(TElSAMLIdentityProviderHandle _Handle, TElCustomSessionManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_SessionManager(TElSAMLIdentityProviderHandle _Handle, TElCustomSessionManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_AuthSource(TElSAMLIdentityProviderHandle _Handle, TElSAMLIDPCustomAuthSourceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_AuthSource(TElSAMLIdentityProviderHandle _Handle, TElSAMLIDPCustomAuthSourceHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_WantAuthnRequestsSigned(TElSAMLIdentityProviderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_WantAuthnRequestsSigned(TElSAMLIdentityProviderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_SigningCertificate(TElSAMLIdentityProviderHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_SigningCertificate(TElSAMLIdentityProviderHandle _Handle, TElX509CertificateHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_EncryptionCertificate(TElSAMLIdentityProviderHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_EncryptionCertificate(TElSAMLIdentityProviderHandle _Handle, TElX509CertificateHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_MetaSigningCertificate(TElSAMLIdentityProviderHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_MetaSigningCertificate(TElSAMLIdentityProviderHandle _Handle, TElX509CertificateHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_ConfirmationCertificate(TElSAMLIdentityProviderHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_ConfirmationCertificate(TElSAMLIdentityProviderHandle _Handle, TElX509CertificateHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_SingleLogoutServiceBindings(TElSAMLIdentityProviderHandle _Handle, TSBSAMLBindingTypesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_SingleLogoutServiceBindings(TElSAMLIdentityProviderHandle _Handle, TSBSAMLBindingTypesRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_SingleSignOnServiceBindings(TElSAMLIdentityProviderHandle _Handle, TSBSAMLBindingTypesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_SingleSignOnServiceBindings(TElSAMLIdentityProviderHandle _Handle, TSBSAMLBindingTypesRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_ArtifactResolutionServiceBindings(TElSAMLIdentityProviderHandle _Handle, TSBSAMLBindingTypesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_MetadataURL(TElSAMLIdentityProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_MetadataURL(TElSAMLIdentityProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_AuthFormTemplate(TElSAMLIdentityProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_AuthFormTemplate(TElSAMLIdentityProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_LoginAttemptsLimitL(TElSAMLIdentityProviderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_LoginAttemptsLimitL(TElSAMLIdentityProviderHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_CurrentSP(TElSAMLIdentityProviderHandle _Handle, TElSAMLServiceProviderInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_AssertionsTTL(TElSAMLIdentityProviderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_AssertionsTTL(TElSAMLIdentityProviderHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_AssertionsOneTimeUse(TElSAMLIdentityProviderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_AssertionsOneTimeUse(TElSAMLIdentityProviderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_SignResponse(TElSAMLIdentityProviderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_SignResponse(TElSAMLIdentityProviderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_SignAssertions(TElSAMLIdentityProviderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_SignAssertions(TElSAMLIdentityProviderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_PrefferedSingleSignOnResponseBinding(TElSAMLIdentityProviderHandle _Handle, TSBSAMLBindingTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_PrefferedSingleSignOnResponseBinding(TElSAMLIdentityProviderHandle _Handle, TSBSAMLBindingTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_PrefferedSingleLogoutResponseBinding(TElSAMLIdentityProviderHandle _Handle, TSBSAMLBindingTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_PrefferedSingleLogoutResponseBinding(TElSAMLIdentityProviderHandle _Handle, TSBSAMLBindingTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_BlockedClientIP(TElSAMLIdentityProviderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_BlockedClientIP(TElSAMLIdentityProviderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_ArtifactStorage(TElSAMLIdentityProviderHandle _Handle, TElCustomArtifactStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_ArtifactStorage(TElSAMLIdentityProviderHandle _Handle, TElCustomArtifactStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_SignMetadata(TElSAMLIdentityProviderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_SignMetadata(TElSAMLIdentityProviderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_EncryptAssertions(TElSAMLIdentityProviderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_EncryptAssertions(TElSAMLIdentityProviderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_DefaultPassiveAuthnContextClassRef(TElSAMLIdentityProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_DefaultPassiveAuthnContextClassRef(TElSAMLIdentityProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_SubjectConfirmationMethod(TElSAMLIdentityProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_SubjectConfirmationMethod(TElSAMLIdentityProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_DefaultNameIDPolicyFormat(TElSAMLIdentityProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_DefaultNameIDPolicyFormat(TElSAMLIdentityProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_NotBeforeTimeout(TElSAMLIdentityProviderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_NotBeforeTimeout(TElSAMLIdentityProviderHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_AllowIDPSSO(TElSAMLIdentityProviderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_AllowIDPSSO(TElSAMLIdentityProviderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_IDPSSOPage(TElSAMLIdentityProviderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_IDPSSOPage(TElSAMLIdentityProviderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_OnSessionCreate(TElSAMLIdentityProviderHandle _Handle, SBSAMLIdentityProvider_TSBSAMLSessionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_OnSessionCreate(TElSAMLIdentityProviderHandle _Handle, SBSAMLIdentityProvider_TSBSAMLSessionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_OnSessionDestroy(TElSAMLIdentityProviderHandle _Handle, SBSAMLIdentityProvider_TSBSAMLSessionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_OnSessionDestroy(TElSAMLIdentityProviderHandle _Handle, SBSAMLIdentityProvider_TSBSAMLSessionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_OnSessionChanged(TElSAMLIdentityProviderHandle _Handle, SBSAMLIdentityProvider_TSBSAMLSessionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_OnSessionChanged(TElSAMLIdentityProviderHandle _Handle, SBSAMLIdentityProvider_TSBSAMLSessionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_OnLogout(TElSAMLIdentityProviderHandle _Handle, SBSAMLIdentityProvider_TSBSAMLLogoutEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_OnLogout(TElSAMLIdentityProviderHandle _Handle, SBSAMLIdentityProvider_TSBSAMLLogoutEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_OnBeforeHTTPSServerUse(TElSAMLIdentityProviderHandle _Handle, SBSAMLIdentityProvider_TSBSAMLBeforeHTTPSServerUseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_OnBeforeHTTPSServerUse(TElSAMLIdentityProviderHandle _Handle, SBSAMLIdentityProvider_TSBSAMLBeforeHTTPSServerUseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_OnRequestPrepared(TElSAMLIdentityProviderHandle _Handle, TSBSAMLRequestPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_OnRequestPrepared(TElSAMLIdentityProviderHandle _Handle, TSBSAMLRequestPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_OnResponseReceived(TElSAMLIdentityProviderHandle _Handle, TSBSAMLResponseReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_OnResponseReceived(TElSAMLIdentityProviderHandle _Handle, TSBSAMLResponseReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_OnResponsePrepared(TElSAMLIdentityProviderHandle _Handle, TSBSAMLResponsePreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_OnResponsePrepared(TElSAMLIdentityProviderHandle _Handle, TSBSAMLResponsePreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_OnMetadataPrepared(TElSAMLIdentityProviderHandle _Handle, TSBSAMLMetadataPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_OnMetadataPrepared(TElSAMLIdentityProviderHandle _Handle, TSBSAMLMetadataPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_OnChangeSessionStage(TElSAMLIdentityProviderHandle _Handle, TSBSAMLChangeIDPSessionStageEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_OnChangeSessionStage(TElSAMLIdentityProviderHandle _Handle, TSBSAMLChangeIDPSessionStageEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_OnSend(TElSAMLIdentityProviderHandle _Handle, TSBSendEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_OnSend(TElSAMLIdentityProviderHandle _Handle, TSBSendEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_OnReceive(TElSAMLIdentityProviderHandle _Handle, TSBReceiveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_OnReceive(TElSAMLIdentityProviderHandle _Handle, TSBReceiveEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_OnOpenConnection(TElSAMLIdentityProviderHandle _Handle, TSBOpenConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_OnOpenConnection(TElSAMLIdentityProviderHandle _Handle, TSBOpenConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_OnSSLError(TElSAMLIdentityProviderHandle _Handle, TSBErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_OnSSLError(TElSAMLIdentityProviderHandle _Handle, TSBErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_OnCloseConnection(TElSAMLIdentityProviderHandle _Handle, TSBCloseConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_OnCloseConnection(TElSAMLIdentityProviderHandle _Handle, TSBCloseConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_OnCertificateValidate(TElSAMLIdentityProviderHandle _Handle, TSBCertificateValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_OnCertificateValidate(TElSAMLIdentityProviderHandle _Handle, TSBCertificateValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_OnChooseAuthnContext(TElSAMLIdentityProviderHandle _Handle, TSBSAMLChooseAuthnContext * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_OnChooseAuthnContext(TElSAMLIdentityProviderHandle _Handle, TSBSAMLChooseAuthnContext pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_OnBeforeHTTPSClientUse(TElSAMLIdentityProviderHandle _Handle, TSBSAMLBeforeHTTPSClientUseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_OnBeforeHTTPSClientUse(TElSAMLIdentityProviderHandle _Handle, TSBSAMLBeforeHTTPSClientUseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_OnBindingXMLPrepared(TElSAMLIdentityProviderHandle _Handle, TSBSAMLBindingXMLPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_OnBindingXMLPrepared(TElSAMLIdentityProviderHandle _Handle, TSBSAMLBindingXMLPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_OnBeforeBindingUse(TElSAMLIdentityProviderHandle _Handle, TSBSAMLBeforeBindingUseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_OnBeforeBindingUse(TElSAMLIdentityProviderHandle _Handle, TSBSAMLBeforeBindingUseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_OnChooseNameIDPolicyFormat(TElSAMLIdentityProviderHandle _Handle, TSBSAMLChooseNameIDPolicyFormatEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_OnChooseNameIDPolicyFormat(TElSAMLIdentityProviderHandle _Handle, TSBSAMLChooseNameIDPolicyFormatEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_OnResponseStatusCode(TElSAMLIdentityProviderHandle _Handle, TSBSAMLResponseStatusCodeEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_OnResponseStatusCode(TElSAMLIdentityProviderHandle _Handle, TSBSAMLResponseStatusCodeEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_get_OnPageContent(TElSAMLIdentityProviderHandle _Handle, TSBSAMLPageContentEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_set_OnPageContent(TElSAMLIdentityProviderHandle _Handle, TSBSAMLPageContentEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIdentityProvider_Create(TComponentHandle AOwner, TElSAMLIdentityProviderHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLIDENTITYPROVIDER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSAMLIDPSession;
class TElSAMLServiceProviderInfo;
class TElSAMLSPData;
class TElSAMLIDPCustomAuthSource;
class TElSAMLIDRecord;
class TElSAMLIDPPasswordMemoryAuthSource;
class TElSAMLIdPSSOLink;
class TElSAMLIdentityProvider;

#ifdef SB_USE_CLASS_TELSAMLIDPSESSION
class TElSAMLIDPSession: public TElSAMLSession
{
	private:
		SB_DISABLE_COPY(TElSAMLIDPSession)
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_Certificate;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELSAMLID
		TElSAMLID* _Inst_NameID;
#endif /* SB_USE_CLASS_TELSAMLID */
#ifdef SB_USE_CLASS_TELDICTIONARY
		TElDictionary* _Inst_ServiceProviders;
#endif /* SB_USE_CLASS_TELDICTIONARY */
#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO
		TElSAMLServiceProviderInfo* _Inst_LastSP;
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO
		void AddServiceProvider(const std::string &SessionIndex, TElSAMLServiceProviderInfo &SPInfo);

		void AddServiceProvider(const std::string &SessionIndex, TElSAMLServiceProviderInfo *SPInfo);
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO */

		void RemoveServiceProvider(const std::string &SessionIndex);

		virtual bool get_LoggedIn();

		SB_DECLARE_PROPERTY_GET(bool, get_LoggedIn, TElSAMLIDPSession, LoggedIn);

		virtual TSBSAMLIDPStage get_Stage();

		virtual void set_Stage(TSBSAMLIDPStage Value);

		SB_DECLARE_PROPERTY(TSBSAMLIDPStage, get_Stage, set_Stage, TElSAMLIDPSession, Stage);

		virtual void get_Login(std::string &OutResult);

		virtual void set_Login(const std::string &Value);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_Certificate();

		virtual void set_Certificate(TElX509Certificate &Value);

		virtual void set_Certificate(TElX509Certificate *Value);

		SB_DECLARE_PROPERTY(TElX509Certificate*, get_Certificate, set_Certificate, TElSAMLIDPSession, Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual bool get_SAMLCookieSet();

		virtual void set_SAMLCookieSet(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SAMLCookieSet, set_SAMLCookieSet, TElSAMLIDPSession, SAMLCookieSet);

#ifdef SB_USE_CLASS_TELSAMLID
		virtual TElSAMLID* get_NameID();

		virtual void set_NameID(TElSAMLID &Value);

		virtual void set_NameID(TElSAMLID *Value);

		SB_DECLARE_PROPERTY(TElSAMLID*, get_NameID, set_NameID, TElSAMLIDPSession, NameID);
#endif /* SB_USE_CLASS_TELSAMLID */

		virtual int32_t get_LoginAttempts();

		virtual void set_LoginAttempts(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_LoginAttempts, set_LoginAttempts, TElSAMLIDPSession, LoginAttempts);

#ifdef SB_USE_CLASS_TELDICTIONARY
		virtual TElDictionary* get_ServiceProviders();

		SB_DECLARE_PROPERTY_GET(TElDictionary*, get_ServiceProviders, TElSAMLIDPSession, ServiceProviders);
#endif /* SB_USE_CLASS_TELDICTIONARY */

#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO
		virtual TElSAMLServiceProviderInfo* get_LastSP();

		virtual void set_LastSP(TElSAMLServiceProviderInfo &Value);

		virtual void set_LastSP(TElSAMLServiceProviderInfo *Value);

		SB_DECLARE_PROPERTY(TElSAMLServiceProviderInfo*, get_LastSP, set_LastSP, TElSAMLIDPSession, LastSP);
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO */

		virtual TSBSAMLBindingType get_Binding();

		virtual void set_Binding(TSBSAMLBindingType Value);

		SB_DECLARE_PROPERTY(TSBSAMLBindingType, get_Binding, set_Binding, TElSAMLIDPSession, Binding);

		virtual void get_ResponseLocation(std::string &OutResult);

		virtual void set_ResponseLocation(const std::string &Value);

		virtual void get_AuthnContextClassRef(std::string &OutResult);

		virtual void set_AuthnContextClassRef(const std::string &Value);

		virtual void get_NameIDPolicyFormat(std::string &OutResult);

		virtual void set_NameIDPolicyFormat(const std::string &Value);

		virtual void get_SessionIndex(std::string &OutResult);

		virtual void set_SessionIndex(const std::string &Value);

		virtual bool get_IdPSSO();

		virtual void set_IdPSSO(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IdPSSO, set_IdPSSO, TElSAMLIDPSession, IdPSSO);

		TElSAMLIDPSession(TElSAMLIDPSessionHandle handle, TElOwnHandle ownHandle);

		TElSAMLIDPSession();

		virtual ~TElSAMLIDPSession();

};
#endif /* SB_USE_CLASS_TELSAMLIDPSESSION */

#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO
class TElSAMLServiceProviderInfo: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSAMLServiceProviderInfo)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_IDPNameIDFormats;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_IDPNameIDFormats;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		TElSAMLEndpoint* _Inst_AssertionConsumerServices;
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */
#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		TElSAMLEndpoint* _Inst_SingleLogoutServices;
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */
#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		TElSAMLEndpoint* _Inst_ArtifactResolutionServices;
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_SigningCertificate;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_EncryptionCertificate;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_MetaSigningCertificate;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		void initInstances();

	public:
		static TElSAMLServiceProviderInfoHandle CreateForGoogleAppEngine(const std::string &Domain);

		TElSAMLServiceProviderInfoHandle CreateForGoogleAppEngine_Inst(const std::string &Domain);

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		int32_t AddAssertionConsumerService(TElSAMLEndpoint &Endpoint);

		int32_t AddAssertionConsumerService(TElSAMLEndpoint *Endpoint);
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		int32_t AddSingleLogoutService(TElSAMLEndpoint &Endpoint);

		int32_t AddSingleLogoutService(TElSAMLEndpoint *Endpoint);
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		int32_t AddArtifactResolutionService(TElSAMLEndpoint &Endpoint);

		int32_t AddArtifactResolutionService(TElSAMLEndpoint *Endpoint);
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

		void RemoveAssertionConsumerService(int32_t Index);

		void RemoveSingleLogoutService(int32_t Index);

		void RemoveArtifactResolutionService(int32_t Index);

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		TElSAMLEndpointHandle FindDefaultAssertionConsumerServiceEP();
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		TElSAMLEndpointHandle FindAssertionConsumerServiceEP(TSBSAMLBindingType Binding);
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TLIST
		TListHandle FindAssertionConsumerServiceEP(const std::string &Location);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		TElSAMLEndpointHandle FindAssertionConsumerServiceEP(int32_t Idx);
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		TElSAMLEndpointHandle FindSingleLogoutServiceEP(TSBSAMLBindingType Binding);
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		TElSAMLEndpointHandle FindArtifactResolutionServiceEP(TSBSAMLBindingType Binding);
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

		void ChooseNameIDFormat(std::string &OutResult);

		void LoadMetadata(const std::string &URI);

		void GetUniqueID(std::string &OutResult);

		virtual void get_EntityID(std::string &OutResult);

		virtual void set_EntityID(const std::string &Value);

		virtual void get_SPNameQualifier(std::string &OutResult);

		virtual void set_SPNameQualifier(const std::string &Value);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_IDPNameIDFormats();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_IDPNameIDFormats, TElSAMLServiceProviderInfo, IDPNameIDFormats);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_IDPNameIDFormats();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_IDPNameIDFormats, TElSAMLServiceProviderInfo, IDPNameIDFormats);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		virtual TElSAMLEndpoint* get_AssertionConsumerServices(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		virtual TElSAMLEndpoint* get_SingleLogoutServices(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
		virtual TElSAMLEndpoint* get_ArtifactResolutionServices(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

		virtual int32_t get_AssertionConsumerServiceCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_AssertionConsumerServiceCount, TElSAMLServiceProviderInfo, AssertionConsumerServiceCount);

		virtual int32_t get_SingleLogoutServiceCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SingleLogoutServiceCount, TElSAMLServiceProviderInfo, SingleLogoutServiceCount);

		virtual int32_t get_ArtifactResolutionServiceCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ArtifactResolutionServiceCount, TElSAMLServiceProviderInfo, ArtifactResolutionServiceCount);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_SigningCertificate();

		virtual void set_SigningCertificate(TElX509Certificate &Value);

		virtual void set_SigningCertificate(TElX509Certificate *Value);

		SB_DECLARE_PROPERTY(TElX509Certificate*, get_SigningCertificate, set_SigningCertificate, TElSAMLServiceProviderInfo, SigningCertificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_EncryptionCertificate();

		virtual void set_EncryptionCertificate(TElX509Certificate &Value);

		virtual void set_EncryptionCertificate(TElX509Certificate *Value);

		SB_DECLARE_PROPERTY(TElX509Certificate*, get_EncryptionCertificate, set_EncryptionCertificate, TElSAMLServiceProviderInfo, EncryptionCertificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_MetaSigningCertificate();

		virtual void set_MetaSigningCertificate(TElX509Certificate &Value);

		virtual void set_MetaSigningCertificate(TElX509Certificate *Value);

		SB_DECLARE_PROPERTY(TElX509Certificate*, get_MetaSigningCertificate, set_MetaSigningCertificate, TElSAMLServiceProviderInfo, MetaSigningCertificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual void get_SourceID(std::vector<uint8_t> &OutResult);

		virtual void set_SourceID(const std::vector<uint8_t> &Value);

		virtual void get_OnBeforeHTTPSClientUse(TSBSAMLBeforeHTTPSClientUseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeHTTPSClientUse(TSBSAMLBeforeHTTPSClientUseEvent pMethodValue, void * pDataValue);

		virtual void get_OnChooseMetadataSPDescriptor(TSBSAMLChooseMetadataDescriptorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnChooseMetadataSPDescriptor(TSBSAMLChooseMetadataDescriptorEvent pMethodValue, void * pDataValue);

		TElSAMLServiceProviderInfo(TElSAMLServiceProviderInfoHandle handle, TElOwnHandle ownHandle);

		TElSAMLServiceProviderInfo();

		virtual ~TElSAMLServiceProviderInfo();

};
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO */

#ifdef SB_USE_CLASS_TELSAMLSPDATA
class TElSAMLSPData: public TObject
{
	private:
		SB_DISABLE_COPY(TElSAMLSPData)
	public:
		virtual void get_SessionIndex(std::string &OutResult);

		virtual void set_SessionIndex(const std::string &Value);

		TElSAMLSPData(TElSAMLSPDataHandle handle, TElOwnHandle ownHandle);

		TElSAMLSPData();

};
#endif /* SB_USE_CLASS_TELSAMLSPDATA */

#ifdef SB_USE_CLASS_TELSAMLIDPCUSTOMAUTHSOURCE
class TElSAMLIDPCustomAuthSource: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSAMLIDPCustomAuthSource)
	public:
		virtual void Add(const std::string &ID, const std::string &AuthToken);

		virtual void Remove(const std::string &ID);

		virtual bool Check(const std::string &ID, const std::string &AuthToken);

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual void GetSupportedIdentifierTypes(TStringList &OutResult);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		virtual void GetIdentifier(const std::string &ID, const std::string &Format, std::string &OutResult);

		virtual void SetIdentifier(const std::string &ID, const std::string &Format, const std::string &Value);

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT
		virtual TElSAMLAttributeElementHandle GetAttribute(const std::string &ID, const std::string &Format, TElSAMLAttributeElement &Attribute);

		virtual TElSAMLAttributeElementHandle GetAttribute(const std::string &ID, const std::string &Format, TElSAMLAttributeElement *Attribute);
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT
		virtual bool SetAttribute(const std::string &ID, const std::string &Format, TElSAMLAttributeElement &Attribute);

		virtual bool SetAttribute(const std::string &ID, const std::string &Format, TElSAMLAttributeElement *Attribute);
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT */

		TElSAMLIDPCustomAuthSource(TElSAMLIDPCustomAuthSourceHandle handle, TElOwnHandle ownHandle);

		explicit TElSAMLIDPCustomAuthSource(TComponent &AOwner);

		explicit TElSAMLIDPCustomAuthSource(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELSAMLIDPCUSTOMAUTHSOURCE */

#ifdef SB_USE_CLASS_TELSAMLIDRECORD
class TElSAMLIDRecord: public TObject
{
	private:
		SB_DISABLE_COPY(TElSAMLIDRecord)
#ifdef SB_USE_CLASS_TELDICTIONARY
		TElDictionary* _Inst_Identifiers;
#endif /* SB_USE_CLASS_TELDICTIONARY */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELDICTIONARY
		virtual TElDictionary* get_Identifiers();

		SB_DECLARE_PROPERTY_GET(TElDictionary*, get_Identifiers, TElSAMLIDRecord, Identifiers);
#endif /* SB_USE_CLASS_TELDICTIONARY */

		virtual void get_AuthToken(std::string &OutResult);

		virtual void set_AuthToken(const std::string &Value);

		TElSAMLIDRecord(TElSAMLIDRecordHandle handle, TElOwnHandle ownHandle);

		TElSAMLIDRecord();

		virtual ~TElSAMLIDRecord();

};
#endif /* SB_USE_CLASS_TELSAMLIDRECORD */

#ifdef SB_USE_CLASS_TELSAMLIDPPASSWORDMEMORYAUTHSOURCE
class TElSAMLIDPPasswordMemoryAuthSource: public TElSAMLIDPCustomAuthSource
{
	private:
		SB_DISABLE_COPY(TElSAMLIDPPasswordMemoryAuthSource)
	public:
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual void GetSupportedIdentifierTypes(TStringList &OutResult);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		virtual void GetIdentifier(const std::string &ID, const std::string &Format, std::string &OutResult);

		virtual void SetIdentifier(const std::string &ID, const std::string &Format, const std::string &Value);

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT
		virtual TElSAMLAttributeElementHandle GetAttribute(const std::string &ID, const std::string &Format, TElSAMLAttributeElement &Attribute);

		virtual TElSAMLAttributeElementHandle GetAttribute(const std::string &ID, const std::string &Format, TElSAMLAttributeElement *Attribute);
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT
		virtual bool SetAttribute(const std::string &ID, const std::string &Format, TElSAMLAttributeElement &Attribute);

		virtual bool SetAttribute(const std::string &ID, const std::string &Format, TElSAMLAttributeElement *Attribute);
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT */

		virtual void Add(const std::string &ID, const std::string &AuthToken);

		virtual void Remove(const std::string &ID);

		virtual bool Check(const std::string &ID, const std::string &AuthToken);

		virtual void get_OnGetAttribute(TSBSAMLIDPGetAttributeEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetAttribute(TSBSAMLIDPGetAttributeEvent pMethodValue, void * pDataValue);

		virtual void get_OnSetAttribute(TSBSAMLIDPSetAttributeEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSetAttribute(TSBSAMLIDPSetAttributeEvent pMethodValue, void * pDataValue);

		TElSAMLIDPPasswordMemoryAuthSource(TElSAMLIDPPasswordMemoryAuthSourceHandle handle, TElOwnHandle ownHandle);

		TElSAMLIDPPasswordMemoryAuthSource();

};
#endif /* SB_USE_CLASS_TELSAMLIDPPASSWORDMEMORYAUTHSOURCE */

#ifdef SB_USE_CLASS_TELSAMLIDPSSOLINK
class TElSAMLIdPSSOLink: public TObject
{
	private:
		SB_DISABLE_COPY(TElSAMLIdPSSOLink)
	public:
		virtual void get_URL(std::string &OutResult);

		virtual void set_URL(const std::string &Value);

		virtual void get_RelayState(std::string &OutResult);

		virtual void set_RelayState(const std::string &Value);

		virtual int32_t get_SPIndex();

		virtual void set_SPIndex(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SPIndex, set_SPIndex, TElSAMLIdPSSOLink, SPIndex);

		TElSAMLIdPSSOLink(TElSAMLIdPSSOLinkHandle handle, TElOwnHandle ownHandle);

		TElSAMLIdPSSOLink();

};
#endif /* SB_USE_CLASS_TELSAMLIDPSSOLINK */

#ifdef SB_USE_CLASS_TELSAMLIDENTITYPROVIDER
class TElSAMLIdentityProvider: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSAMLIdentityProvider)
#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO
		TElSAMLServiceProviderInfo* _Inst_ServiceProviders;
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO */
#ifdef SB_USE_CLASS_TELSAMLIDPSSOLINK
		TElSAMLIdPSSOLink* _Inst_IdPSSOLinks;
#endif /* SB_USE_CLASS_TELSAMLIDPSSOLINK */
#ifdef SB_USE_CLASS_TELHTTPSSERVER
		TElHTTPSServer* _Inst_Control;
#endif /* SB_USE_CLASS_TELHTTPSSERVER */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_SupportedAuthnContextClasses;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_SupportedAuthnContextClasses;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMSESSIONMANAGER
		TElCustomSessionManager* _Inst_SessionManager;
#endif /* SB_USE_CLASS_TELCUSTOMSESSIONMANAGER */
#ifdef SB_USE_CLASS_TELSAMLIDPCUSTOMAUTHSOURCE
		TElSAMLIDPCustomAuthSource* _Inst_AuthSource;
#endif /* SB_USE_CLASS_TELSAMLIDPCUSTOMAUTHSOURCE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_SigningCertificate;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_EncryptionCertificate;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_MetaSigningCertificate;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_ConfirmationCertificate;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO
		TElSAMLServiceProviderInfo* _Inst_CurrentSP;
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO */
#ifdef SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE
		TElCustomArtifactStorage* _Inst_ArtifactStorage;
#endif /* SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE */

		void initInstances();

	public:
		void Open();

		void DataAvailable();

		void Close(bool Silent);

#ifdef SB_USE_CLASS_TSTREAM
		void SaveMetadata(TStream &Strm);

		void SaveMetadata(TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO
		int32_t AddServiceProvider(TElSAMLServiceProviderInfo &SPInfo);

		int32_t AddServiceProvider(TElSAMLServiceProviderInfo *SPInfo);
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO */

		void RemoveServiceProvider(int32_t Index);

#ifdef SB_USE_CLASS_TELSAMLIDPSSOLINK
		int32_t AddIdPSSOLink(TElSAMLIdPSSOLink &Link);

		int32_t AddIdPSSOLink(TElSAMLIdPSSOLink *Link);
#endif /* SB_USE_CLASS_TELSAMLIDPSSOLINK */

		void RemoveIdPSSOLink(int32_t Index);

#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO
		virtual TElSAMLServiceProviderInfo* get_ServiceProviders(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO */

		virtual int32_t get_ServiceProviderCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ServiceProviderCount, TElSAMLIdentityProvider, ServiceProviderCount);

#ifdef SB_USE_CLASS_TELSAMLIDPSSOLINK
		virtual TElSAMLIdPSSOLink* get_IdPSSOLinks(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLIDPSSOLINK */

		virtual int32_t get_IdPSSOLinkCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_IdPSSOLinkCount, TElSAMLIdentityProvider, IdPSSOLinkCount);

#ifdef SB_USE_CLASS_TELHTTPSSERVER
		virtual TElHTTPSServer* get_Control();

		SB_DECLARE_PROPERTY_GET(TElHTTPSServer*, get_Control, TElSAMLIdentityProvider, Control);
#endif /* SB_USE_CLASS_TELHTTPSSERVER */

		virtual bool get_Active();

		SB_DECLARE_PROPERTY_GET(bool, get_Active, TElSAMLIdentityProvider, Active);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_SupportedAuthnContextClasses();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_SupportedAuthnContextClasses, TElSAMLIdentityProvider, SupportedAuthnContextClasses);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_SupportedAuthnContextClasses();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_SupportedAuthnContextClasses, TElSAMLIdentityProvider, SupportedAuthnContextClasses);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual void get_SourceID(std::vector<uint8_t> &OutResult);

		virtual void set_SourceID(const std::vector<uint8_t> &Value);

		virtual int32_t get_SendBufferSize();

		virtual void set_SendBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SendBufferSize, set_SendBufferSize, TElSAMLIdentityProvider, SendBufferSize);

		virtual void get_ServerName(std::string &OutResult);

		virtual void set_ServerName(const std::string &Value);

		virtual void get_URL(std::string &OutResult);

		virtual void set_URL(const std::string &Value);

		virtual void get_SingleSignOnService(std::string &OutResult);

		virtual void set_SingleSignOnService(const std::string &Value);

		virtual void get_SingleLogoutService(std::string &OutResult);

		virtual void set_SingleLogoutService(const std::string &Value);

		virtual void get_ArtifactResolutionService(std::string &OutResult);

		virtual void set_ArtifactResolutionService(const std::string &Value);

		virtual void get_AttributeQueryService(std::string &OutResult);

		virtual void set_AttributeQueryService(const std::string &Value);

		virtual void get_SessionCookieName(std::string &OutResult);

		virtual void set_SessionCookieName(const std::string &Value);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElSAMLIdentityProvider, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual SBSAMLIdentityProvider_TSBSAMLAccessLevel get_AccessLevel();

		virtual void set_AccessLevel(SBSAMLIdentityProvider_TSBSAMLAccessLevel Value);

		SB_DECLARE_PROPERTY(SBSAMLIdentityProvider_TSBSAMLAccessLevel, get_AccessLevel, set_AccessLevel, TElSAMLIdentityProvider, AccessLevel);

		virtual int32_t get_SessionTTL();

		virtual void set_SessionTTL(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SessionTTL, set_SessionTTL, TElSAMLIdentityProvider, SessionTTL);

		virtual int32_t get_SAMLSessionTTL();

		virtual void set_SAMLSessionTTL(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SAMLSessionTTL, set_SAMLSessionTTL, TElSAMLIdentityProvider, SAMLSessionTTL);

		virtual int32_t get_MaxIssueInstantTimeDiff();

		virtual void set_MaxIssueInstantTimeDiff(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxIssueInstantTimeDiff, set_MaxIssueInstantTimeDiff, TElSAMLIdentityProvider, MaxIssueInstantTimeDiff);

#ifdef SB_USE_CLASS_TELCUSTOMSESSIONMANAGER
		virtual TElCustomSessionManager* get_SessionManager();

		virtual void set_SessionManager(TElCustomSessionManager &Value);

		virtual void set_SessionManager(TElCustomSessionManager *Value);

		SB_DECLARE_PROPERTY(TElCustomSessionManager*, get_SessionManager, set_SessionManager, TElSAMLIdentityProvider, SessionManager);
#endif /* SB_USE_CLASS_TELCUSTOMSESSIONMANAGER */

#ifdef SB_USE_CLASS_TELSAMLIDPCUSTOMAUTHSOURCE
		virtual TElSAMLIDPCustomAuthSource* get_AuthSource();

		virtual void set_AuthSource(TElSAMLIDPCustomAuthSource &Value);

		virtual void set_AuthSource(TElSAMLIDPCustomAuthSource *Value);

		SB_DECLARE_PROPERTY(TElSAMLIDPCustomAuthSource*, get_AuthSource, set_AuthSource, TElSAMLIdentityProvider, AuthSource);
#endif /* SB_USE_CLASS_TELSAMLIDPCUSTOMAUTHSOURCE */

		virtual bool get_WantAuthnRequestsSigned();

		virtual void set_WantAuthnRequestsSigned(bool Value);

		SB_DECLARE_PROPERTY(bool, get_WantAuthnRequestsSigned, set_WantAuthnRequestsSigned, TElSAMLIdentityProvider, WantAuthnRequestsSigned);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_SigningCertificate();

		virtual void set_SigningCertificate(TElX509Certificate &Value);

		virtual void set_SigningCertificate(TElX509Certificate *Value);

		SB_DECLARE_PROPERTY(TElX509Certificate*, get_SigningCertificate, set_SigningCertificate, TElSAMLIdentityProvider, SigningCertificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_EncryptionCertificate();

		virtual void set_EncryptionCertificate(TElX509Certificate &Value);

		virtual void set_EncryptionCertificate(TElX509Certificate *Value);

		SB_DECLARE_PROPERTY(TElX509Certificate*, get_EncryptionCertificate, set_EncryptionCertificate, TElSAMLIdentityProvider, EncryptionCertificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_MetaSigningCertificate();

		virtual void set_MetaSigningCertificate(TElX509Certificate &Value);

		virtual void set_MetaSigningCertificate(TElX509Certificate *Value);

		SB_DECLARE_PROPERTY(TElX509Certificate*, get_MetaSigningCertificate, set_MetaSigningCertificate, TElSAMLIdentityProvider, MetaSigningCertificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_ConfirmationCertificate();

		virtual void set_ConfirmationCertificate(TElX509Certificate &Value);

		virtual void set_ConfirmationCertificate(TElX509Certificate *Value);

		SB_DECLARE_PROPERTY(TElX509Certificate*, get_ConfirmationCertificate, set_ConfirmationCertificate, TElSAMLIdentityProvider, ConfirmationCertificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual TSBSAMLBindingTypes get_SingleLogoutServiceBindings();

		virtual void set_SingleLogoutServiceBindings(TSBSAMLBindingTypes Value);

		SB_DECLARE_PROPERTY(TSBSAMLBindingTypes, get_SingleLogoutServiceBindings, set_SingleLogoutServiceBindings, TElSAMLIdentityProvider, SingleLogoutServiceBindings);

		virtual TSBSAMLBindingTypes get_SingleSignOnServiceBindings();

		virtual void set_SingleSignOnServiceBindings(TSBSAMLBindingTypes Value);

		SB_DECLARE_PROPERTY(TSBSAMLBindingTypes, get_SingleSignOnServiceBindings, set_SingleSignOnServiceBindings, TElSAMLIdentityProvider, SingleSignOnServiceBindings);

		virtual TSBSAMLBindingTypes get_ArtifactResolutionServiceBindings();

		SB_DECLARE_PROPERTY_GET(TSBSAMLBindingTypes, get_ArtifactResolutionServiceBindings, TElSAMLIdentityProvider, ArtifactResolutionServiceBindings);

		virtual void get_MetadataURL(std::string &OutResult);

		virtual void set_MetadataURL(const std::string &Value);

		virtual void get_AuthFormTemplate(std::string &OutResult);

		virtual void set_AuthFormTemplate(const std::string &Value);

		virtual int32_t get_LoginAttemptsLimitL();

		virtual void set_LoginAttemptsLimitL(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_LoginAttemptsLimitL, set_LoginAttemptsLimitL, TElSAMLIdentityProvider, LoginAttemptsLimitL);

#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO
		virtual TElSAMLServiceProviderInfo* get_CurrentSP();

		SB_DECLARE_PROPERTY_GET(TElSAMLServiceProviderInfo*, get_CurrentSP, TElSAMLIdentityProvider, CurrentSP);
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDERINFO */

		virtual int32_t get_AssertionsTTL();

		virtual void set_AssertionsTTL(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AssertionsTTL, set_AssertionsTTL, TElSAMLIdentityProvider, AssertionsTTL);

		virtual bool get_AssertionsOneTimeUse();

		virtual void set_AssertionsOneTimeUse(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AssertionsOneTimeUse, set_AssertionsOneTimeUse, TElSAMLIdentityProvider, AssertionsOneTimeUse);

		virtual bool get_SignResponse();

		virtual void set_SignResponse(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SignResponse, set_SignResponse, TElSAMLIdentityProvider, SignResponse);

		virtual bool get_SignAssertions();

		virtual void set_SignAssertions(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SignAssertions, set_SignAssertions, TElSAMLIdentityProvider, SignAssertions);

		virtual TSBSAMLBindingType get_PrefferedSingleSignOnResponseBinding();

		virtual void set_PrefferedSingleSignOnResponseBinding(TSBSAMLBindingType Value);

		SB_DECLARE_PROPERTY(TSBSAMLBindingType, get_PrefferedSingleSignOnResponseBinding, set_PrefferedSingleSignOnResponseBinding, TElSAMLIdentityProvider, PrefferedSingleSignOnResponseBinding);

		virtual TSBSAMLBindingType get_PrefferedSingleLogoutResponseBinding();

		virtual void set_PrefferedSingleLogoutResponseBinding(TSBSAMLBindingType Value);

		SB_DECLARE_PROPERTY(TSBSAMLBindingType, get_PrefferedSingleLogoutResponseBinding, set_PrefferedSingleLogoutResponseBinding, TElSAMLIdentityProvider, PrefferedSingleLogoutResponseBinding);

		virtual bool get_BlockedClientIP();

		virtual void set_BlockedClientIP(bool Value);

		SB_DECLARE_PROPERTY(bool, get_BlockedClientIP, set_BlockedClientIP, TElSAMLIdentityProvider, BlockedClientIP);

#ifdef SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE
		virtual TElCustomArtifactStorage* get_ArtifactStorage();

		virtual void set_ArtifactStorage(TElCustomArtifactStorage &Value);

		virtual void set_ArtifactStorage(TElCustomArtifactStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomArtifactStorage*, get_ArtifactStorage, set_ArtifactStorage, TElSAMLIdentityProvider, ArtifactStorage);
#endif /* SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE */

		virtual bool get_SignMetadata();

		virtual void set_SignMetadata(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SignMetadata, set_SignMetadata, TElSAMLIdentityProvider, SignMetadata);

		virtual bool get_EncryptAssertions();

		virtual void set_EncryptAssertions(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EncryptAssertions, set_EncryptAssertions, TElSAMLIdentityProvider, EncryptAssertions);

		virtual void get_DefaultPassiveAuthnContextClassRef(std::string &OutResult);

		virtual void set_DefaultPassiveAuthnContextClassRef(const std::string &Value);

		virtual void get_SubjectConfirmationMethod(std::string &OutResult);

		virtual void set_SubjectConfirmationMethod(const std::string &Value);

		virtual void get_DefaultNameIDPolicyFormat(std::string &OutResult);

		virtual void set_DefaultNameIDPolicyFormat(const std::string &Value);

		virtual int32_t get_NotBeforeTimeout();

		virtual void set_NotBeforeTimeout(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_NotBeforeTimeout, set_NotBeforeTimeout, TElSAMLIdentityProvider, NotBeforeTimeout);

		virtual bool get_AllowIDPSSO();

		virtual void set_AllowIDPSSO(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AllowIDPSSO, set_AllowIDPSSO, TElSAMLIdentityProvider, AllowIDPSSO);

		virtual void get_IDPSSOPage(std::string &OutResult);

		virtual void set_IDPSSOPage(const std::string &Value);

		virtual void get_OnSessionCreate(SBSAMLIdentityProvider_TSBSAMLSessionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSessionCreate(SBSAMLIdentityProvider_TSBSAMLSessionEvent pMethodValue, void * pDataValue);

		virtual void get_OnSessionDestroy(SBSAMLIdentityProvider_TSBSAMLSessionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSessionDestroy(SBSAMLIdentityProvider_TSBSAMLSessionEvent pMethodValue, void * pDataValue);

		virtual void get_OnSessionChanged(SBSAMLIdentityProvider_TSBSAMLSessionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSessionChanged(SBSAMLIdentityProvider_TSBSAMLSessionEvent pMethodValue, void * pDataValue);

		virtual void get_OnLogout(SBSAMLIdentityProvider_TSBSAMLLogoutEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnLogout(SBSAMLIdentityProvider_TSBSAMLLogoutEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeHTTPSServerUse(SBSAMLIdentityProvider_TSBSAMLBeforeHTTPSServerUseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeHTTPSServerUse(SBSAMLIdentityProvider_TSBSAMLBeforeHTTPSServerUseEvent pMethodValue, void * pDataValue);

		virtual void get_OnRequestPrepared(TSBSAMLRequestPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRequestPrepared(TSBSAMLRequestPreparedEvent pMethodValue, void * pDataValue);

		virtual void get_OnResponseReceived(TSBSAMLResponseReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnResponseReceived(TSBSAMLResponseReceivedEvent pMethodValue, void * pDataValue);

		virtual void get_OnResponsePrepared(TSBSAMLResponsePreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnResponsePrepared(TSBSAMLResponsePreparedEvent pMethodValue, void * pDataValue);

		virtual void get_OnMetadataPrepared(TSBSAMLMetadataPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnMetadataPrepared(TSBSAMLMetadataPreparedEvent pMethodValue, void * pDataValue);

		virtual void get_OnChangeSessionStage(TSBSAMLChangeIDPSessionStageEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnChangeSessionStage(TSBSAMLChangeIDPSessionStageEvent pMethodValue, void * pDataValue);

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

		virtual void get_OnCertificateValidate(TSBCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateValidate(TSBCertificateValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnChooseAuthnContext(TSBSAMLChooseAuthnContext &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnChooseAuthnContext(TSBSAMLChooseAuthnContext pMethodValue, void * pDataValue);

		virtual void get_OnBeforeHTTPSClientUse(TSBSAMLBeforeHTTPSClientUseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeHTTPSClientUse(TSBSAMLBeforeHTTPSClientUseEvent pMethodValue, void * pDataValue);

		virtual void get_OnBindingXMLPrepared(TSBSAMLBindingXMLPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBindingXMLPrepared(TSBSAMLBindingXMLPreparedEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeBindingUse(TSBSAMLBeforeBindingUseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeBindingUse(TSBSAMLBeforeBindingUseEvent pMethodValue, void * pDataValue);

		virtual void get_OnChooseNameIDPolicyFormat(TSBSAMLChooseNameIDPolicyFormatEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnChooseNameIDPolicyFormat(TSBSAMLChooseNameIDPolicyFormatEvent pMethodValue, void * pDataValue);

		virtual void get_OnResponseStatusCode(TSBSAMLResponseStatusCodeEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnResponseStatusCode(TSBSAMLResponseStatusCodeEvent pMethodValue, void * pDataValue);

		virtual void get_OnPageContent(TSBSAMLPageContentEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPageContent(TSBSAMLPageContentEvent pMethodValue, void * pDataValue);

		TElSAMLIdentityProvider(TElSAMLIdentityProviderHandle handle, TElOwnHandle ownHandle);

		explicit TElSAMLIdentityProvider(TComponent &AOwner);

		explicit TElSAMLIdentityProvider(TComponent *AOwner);

		virtual ~TElSAMLIdentityProvider();

};
#endif /* SB_USE_CLASS_TELSAMLIDENTITYPROVIDER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSAMLIDENTITYPROVIDER */
