#ifndef __INC_SBOAUTH2
#define __INC_SBOAUTH2

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstringlist.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbjson.h"
#include "sbsocket.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_OAUTH2_ERROR_BASE 	14592
#define SB_OAUTH2_ERROR_INVALID_HTTP_CODE 	14592
#define SB_OAUTH2_ERROR_INVALID_RESPONSE_FORMAT 	14593
#define SB_OAUTH2_ERROR_INVALID_STATE_PARAMETER 	14594
#define SB_OAUTH2_ERROR_NO_CODE_RECEIVED 	14595
#define SB_OAUTH2_ERROR_NO_REFRESH_TOKEN 	14596
#define SB_OAUTH2_SERVER_ERROR_BASE 	14576
#define SB_OAUTH2_SERVER_ERROR_UNKNOWN 	14576
#define SB_OAUTH2_SERVER_ERROR_ACCESS_DENIED 	14577
#define SB_OAUTH2_SERVER_ERROR_INVALID_CLIENT 	14578
#define SB_OAUTH2_SERVER_ERROR_INVALID_GRANT 	14579
#define SB_OAUTH2_SERVER_ERROR_INVALID_REQUEST 	14580
#define SB_OAUTH2_SERVER_ERROR_INVALID_SCOPE 	14581
#define SB_OAUTH2_SERVER_ERROR_SERVER_FAILURE 	14582
#define SB_OAUTH2_SERVER_ERROR_TEMPORARILY 	14583
#define SB_OAUTH2_SERVER_ERROR_UNAUTH_CLIENT 	14584
#define SB_OAUTH2_SERVER_ERROR_UNSUPPORTED_GRANT 	14585
#define SB_OAUTH2_SERVER_ERROR_UNSUPPORTED_RESPONSE 	14586

typedef TElClassHandle TElOAuth2SettingsHandle;

typedef TElClassHandle TElOAuth2RequestHandle;

typedef TElClassHandle TElOAuth2ClientHandle;

typedef TElClassHandle TElOAuth2RedirectReceiverHandle;

typedef uint8_t TSBOAuth2GrantTypeRaw;

typedef enum
{
	oauthAuthorizationCode = 0,
	oauthImplicit = 1,
	oauthResourceOwnerPassword = 2,
	oauthClientCredentials = 3
} TSBOAuth2GrantType;

#ifdef SB_USE_CLASS_TELOAUTH2SETTINGS
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_Assign(TElOAuth2SettingsHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_Clear(TElOAuth2SettingsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_CopyParams(TElOAuth2SettingsHandle _Handle, TElOAuth2ClientHandle Client);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_SetParams(TElOAuth2SettingsHandle _Handle, const char * pcARefreshToken, int32_t szARefreshToken, const char * pcAAccessToken, int32_t szAAccessToken, const char * pcATokenType, int32_t szATokenType, int64_t AExpiresAt);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_get_AccessToken(TElOAuth2SettingsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_set_AccessToken(TElOAuth2SettingsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_get_Complete(TElOAuth2SettingsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_get_ExpiresAt(TElOAuth2SettingsHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_get_RefreshToken(TElOAuth2SettingsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_set_RefreshToken(TElOAuth2SettingsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_get_TargetHost(TElOAuth2SettingsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_set_TargetHost(TElOAuth2SettingsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_get_TokenType(TElOAuth2SettingsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_set_TokenType(TElOAuth2SettingsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_get_AuthURL(TElOAuth2SettingsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_set_AuthURL(TElOAuth2SettingsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_get_CheckTargetHost(TElOAuth2SettingsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_set_CheckTargetHost(TElOAuth2SettingsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_get_ClientID(TElOAuth2SettingsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_set_ClientID(TElOAuth2SettingsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_get_ClientSecret(TElOAuth2SettingsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_set_ClientSecret(TElOAuth2SettingsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_get_Enabled(TElOAuth2SettingsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_set_Enabled(TElOAuth2SettingsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_get_GrantType(TElOAuth2SettingsHandle _Handle, TSBOAuth2GrantTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_set_GrantType(TElOAuth2SettingsHandle _Handle, TSBOAuth2GrantTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_get_RedirectURL(TElOAuth2SettingsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_set_RedirectURL(TElOAuth2SettingsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_get_Scope(TElOAuth2SettingsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_set_Scope(TElOAuth2SettingsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_get_State(TElOAuth2SettingsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_set_State(TElOAuth2SettingsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_get_TokenURL(TElOAuth2SettingsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_set_TokenURL(TElOAuth2SettingsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_get_UseURLParams(TElOAuth2SettingsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_set_UseURLParams(TElOAuth2SettingsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Settings_Create(TElOAuth2SettingsHandle * OutResult);
#endif /* SB_USE_CLASS_TELOAUTH2SETTINGS */

#ifdef SB_USE_CLASS_TELOAUTH2REQUEST
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Request_Assign(TElOAuth2RequestHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Request_Clear(TElOAuth2RequestHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Request_get_Body(TElOAuth2RequestHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Request_get_Header(TElOAuth2RequestHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Request_get_Header(TElOAuth2RequestHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Request_get_Method(TElOAuth2RequestHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Request_get_URL(TElOAuth2RequestHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Request_Create(TElOAuth2RequestHandle * OutResult);
#endif /* SB_USE_CLASS_TELOAUTH2REQUEST */

#ifdef SB_USE_CLASS_TELOAUTH2CLIENT
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_Process(TElOAuth2ClientHandle _Handle, TStringListHandle ResponseHeader, const uint8_t pResponseBody[], int32_t szResponseBody, int32_t * Method, char * pcURL, int32_t * szURL, TStringListHandle RequestHeader, uint8_t pRequestBody[], int32_t * szRequestBody, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_Process_1(TElOAuth2ClientHandle _Handle, TStringListHandle ResponseHeader, const uint8_t pResponseBody[], int32_t szResponseBody, TElOAuth2RequestHandle NewRequest, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_Refresh(TElOAuth2ClientHandle _Handle, int32_t * Method, char * pcURL, int32_t * szURL, TStringListHandle RequestHeader, uint8_t pRequestBody[], int32_t * szRequestBody);
#else
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_Process(TElOAuth2ClientHandle _Handle, TElStringListHandle ResponseHeader, const uint8_t pResponseBody[], int32_t szResponseBody, int32_t * Method, char * pcURL, int32_t * szURL, TElStringListHandle RequestHeader, uint8_t pRequestBody[], int32_t * szRequestBody, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_Process_1(TElOAuth2ClientHandle _Handle, TElStringListHandle ResponseHeader, const uint8_t pResponseBody[], int32_t szResponseBody, TElOAuth2RequestHandle NewRequest, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_Refresh(TElOAuth2ClientHandle _Handle, int32_t * Method, char * pcURL, int32_t * szURL, TElStringListHandle RequestHeader, uint8_t pRequestBody[], int32_t * szRequestBody);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_Refresh_1(TElOAuth2ClientHandle _Handle, TElOAuth2RequestHandle Request);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_Start(TElOAuth2ClientHandle _Handle, int32_t * Method, char * pcURL, int32_t * szURL, TStringListHandle RequestHeader, uint8_t pRequestBody[], int32_t * szRequestBody);
#else
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_Start(TElOAuth2ClientHandle _Handle, int32_t * Method, char * pcURL, int32_t * szURL, TElStringListHandle RequestHeader, uint8_t pRequestBody[], int32_t * szRequestBody);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_Start_1(TElOAuth2ClientHandle _Handle, TElOAuth2RequestHandle Request);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_Apply(TElOAuth2ClientHandle _Handle, TElOAuth2SettingsHandle Settings);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_get_AccessToken(TElOAuth2ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_get_AuthURL(TElOAuth2ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_set_AuthURL(TElOAuth2ClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_get_ClientID(TElOAuth2ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_set_ClientID(TElOAuth2ClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_get_ClientSecret(TElOAuth2ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_set_ClientSecret(TElOAuth2ClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_get_Complete(TElOAuth2ClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_get_ExpiresAt(TElOAuth2ClientHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_get_ExpiresIn(TElOAuth2ClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_get_GrantType(TElOAuth2ClientHandle _Handle, TSBOAuth2GrantTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_set_GrantType(TElOAuth2ClientHandle _Handle, TSBOAuth2GrantTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_get_Password(TElOAuth2ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_set_Password(TElOAuth2ClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_get_RedirectURL(TElOAuth2ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_set_RedirectURL(TElOAuth2ClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_get_RefreshToken(TElOAuth2ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_set_RefreshToken(TElOAuth2ClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_get_Scope(TElOAuth2ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_set_Scope(TElOAuth2ClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_get_State(TElOAuth2ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_set_State(TElOAuth2ClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_get_TokenType(TElOAuth2ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_get_TokenURL(TElOAuth2ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_set_TokenURL(TElOAuth2ClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_get_UseURLParams(TElOAuth2ClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_set_UseURLParams(TElOAuth2ClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_get_UserName(TElOAuth2ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_set_UserName(TElOAuth2ClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2Client_Create(TElOAuth2ClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELOAUTH2CLIENT */

#ifdef SB_USE_CLASS_TELOAUTH2REDIRECTRECEIVER
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2RedirectReceiver_Activate(TElOAuth2RedirectReceiverHandle _Handle, const char * pcURL, int32_t szURL);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2RedirectReceiver_Activate_1(TElOAuth2RedirectReceiverHandle _Handle, const char * pcLocalAddress, int32_t szLocalAddress, uint16_t LocalPort);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2RedirectReceiver_Deactivate(TElOAuth2RedirectReceiverHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2RedirectReceiver_Receive(TElOAuth2RedirectReceiverHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2RedirectReceiver_Reset(TElOAuth2RedirectReceiverHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2RedirectReceiver_get_Active(TElOAuth2RedirectReceiverHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2RedirectReceiver_get_AuthorizationCode(TElOAuth2RedirectReceiverHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2RedirectReceiver_get_Done(TElOAuth2RedirectReceiverHandle _Handle, int8_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2RedirectReceiver_get_ReceivedHeaders(TElOAuth2RedirectReceiverHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2RedirectReceiver_get_ReceivedHeaders(TElOAuth2RedirectReceiverHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2RedirectReceiver_get_BufferSize(TElOAuth2RedirectReceiverHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2RedirectReceiver_set_BufferSize(TElOAuth2RedirectReceiverHandle _Handle, int32_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2RedirectReceiver_get_ResponsePage(TElOAuth2RedirectReceiverHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2RedirectReceiver_set_ResponsePage(TElOAuth2RedirectReceiverHandle _Handle, TStringListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2RedirectReceiver_get_UseIPv6(TElOAuth2RedirectReceiverHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2RedirectReceiver_set_UseIPv6(TElOAuth2RedirectReceiverHandle _Handle, int8_t Value);
#else
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2RedirectReceiver_get_ResponsePage(TElOAuth2RedirectReceiverHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2RedirectReceiver_set_ResponsePage(TElOAuth2RedirectReceiverHandle _Handle, TElStringListHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2RedirectReceiver_get_OnComplete(TElOAuth2RedirectReceiverHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2RedirectReceiver_set_OnComplete(TElOAuth2RedirectReceiverHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElOAuth2RedirectReceiver_Create(TComponentHandle AOwner, TElOAuth2RedirectReceiverHandle * OutResult);
#endif /* SB_USE_CLASS_TELOAUTH2REDIRECTRECEIVER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElOAuth2Settings;
class TElOAuth2Request;
class TElOAuth2Client;
class TElOAuth2RedirectReceiver;

#ifdef SB_USE_CLASS_TELOAUTH2SETTINGS
class TElOAuth2Settings: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElOAuth2Settings)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		void Clear();

#ifdef SB_USE_CLASS_TELOAUTH2CLIENT
		void CopyParams(TElOAuth2Client &Client);

		void CopyParams(TElOAuth2Client *Client);
#endif /* SB_USE_CLASS_TELOAUTH2CLIENT */

		void SetParams(const std::string &ARefreshToken, const std::string &AAccessToken, const std::string &ATokenType, int64_t AExpiresAt);

		virtual void get_AccessToken(std::string &OutResult);

		virtual void set_AccessToken(const std::string &Value);

		virtual bool get_Complete();

		SB_DECLARE_PROPERTY_GET(bool, get_Complete, TElOAuth2Settings, Complete);

		virtual int64_t get_ExpiresAt();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ExpiresAt, TElOAuth2Settings, ExpiresAt);

		virtual void get_RefreshToken(std::string &OutResult);

		virtual void set_RefreshToken(const std::string &Value);

		virtual void get_TargetHost(std::string &OutResult);

		virtual void set_TargetHost(const std::string &Value);

		virtual void get_TokenType(std::string &OutResult);

		virtual void set_TokenType(const std::string &Value);

		virtual void get_AuthURL(std::string &OutResult);

		virtual void set_AuthURL(const std::string &Value);

		virtual bool get_CheckTargetHost();

		virtual void set_CheckTargetHost(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CheckTargetHost, set_CheckTargetHost, TElOAuth2Settings, CheckTargetHost);

		virtual void get_ClientID(std::string &OutResult);

		virtual void set_ClientID(const std::string &Value);

		virtual void get_ClientSecret(std::string &OutResult);

		virtual void set_ClientSecret(const std::string &Value);

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElOAuth2Settings, Enabled);

		virtual TSBOAuth2GrantType get_GrantType();

		virtual void set_GrantType(TSBOAuth2GrantType Value);

		SB_DECLARE_PROPERTY(TSBOAuth2GrantType, get_GrantType, set_GrantType, TElOAuth2Settings, GrantType);

		virtual void get_RedirectURL(std::string &OutResult);

		virtual void set_RedirectURL(const std::string &Value);

		virtual void get_Scope(std::string &OutResult);

		virtual void set_Scope(const std::string &Value);

		virtual void get_State(std::string &OutResult);

		virtual void set_State(const std::string &Value);

		virtual void get_TokenURL(std::string &OutResult);

		virtual void set_TokenURL(const std::string &Value);

		virtual bool get_UseURLParams();

		virtual void set_UseURLParams(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseURLParams, set_UseURLParams, TElOAuth2Settings, UseURLParams);

		TElOAuth2Settings(TElOAuth2SettingsHandle handle, TElOwnHandle ownHandle);

		TElOAuth2Settings();

};
#endif /* SB_USE_CLASS_TELOAUTH2SETTINGS */

#ifdef SB_USE_CLASS_TELOAUTH2REQUEST
class TElOAuth2Request: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElOAuth2Request)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Header;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Header;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		void Clear();

		virtual void get_Body(std::vector<uint8_t> &OutResult);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Header();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Header, TElOAuth2Request, Header);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Header();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Header, TElOAuth2Request, Header);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual int32_t get_Method();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Method, TElOAuth2Request, Method);

		virtual void get_URL(std::string &OutResult);

		TElOAuth2Request(TElOAuth2RequestHandle handle, TElOwnHandle ownHandle);

		TElOAuth2Request();

		virtual ~TElOAuth2Request();

};
#endif /* SB_USE_CLASS_TELOAUTH2REQUEST */

#ifdef SB_USE_CLASS_TELOAUTH2CLIENT
class TElOAuth2Client: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElOAuth2Client)
	public:
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		bool Process(TStringList &ResponseHeader, const std::vector<uint8_t> &ResponseBody, int32_t &Method, std::string &URL, TStringList &RequestHeader, std::vector<uint8_t> &RequestBody);

		bool Process(TStringList *ResponseHeader, const std::vector<uint8_t> &ResponseBody, int32_t &Method, std::string &URL, TStringList *RequestHeader, std::vector<uint8_t> &RequestBody);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		bool Process(TElStringList &ResponseHeader, const std::vector<uint8_t> &ResponseBody, int32_t &Method, std::string &URL, TElStringList &RequestHeader, std::vector<uint8_t> &RequestBody);

		bool Process(TElStringList *ResponseHeader, const std::vector<uint8_t> &ResponseBody, int32_t &Method, std::string &URL, TElStringList *RequestHeader, std::vector<uint8_t> &RequestBody);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELOAUTH2REQUEST_AND_TSTRINGLIST
		bool Process(TStringList &ResponseHeader, const std::vector<uint8_t> &ResponseBody, TElOAuth2Request &NewRequest);

		bool Process(TStringList *ResponseHeader, const std::vector<uint8_t> &ResponseBody, TElOAuth2Request *NewRequest);
#endif /* SB_USE_CLASSES_TELOAUTH2REQUEST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELOAUTH2REQUEST_AND_TELSTRINGLIST
		bool Process(TElStringList &ResponseHeader, const std::vector<uint8_t> &ResponseBody, TElOAuth2Request &NewRequest);

		bool Process(TElStringList *ResponseHeader, const std::vector<uint8_t> &ResponseBody, TElOAuth2Request *NewRequest);
#endif /* SB_USE_CLASSES_TELOAUTH2REQUEST_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void Refresh(int32_t &Method, std::string &URL, TStringList &RequestHeader, std::vector<uint8_t> &RequestBody);

		void Refresh(int32_t &Method, std::string &URL, TStringList *RequestHeader, std::vector<uint8_t> &RequestBody);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void Refresh(int32_t &Method, std::string &URL, TElStringList &RequestHeader, std::vector<uint8_t> &RequestBody);

		void Refresh(int32_t &Method, std::string &URL, TElStringList *RequestHeader, std::vector<uint8_t> &RequestBody);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELOAUTH2REQUEST
		void Refresh(TElOAuth2Request &Request);

		void Refresh(TElOAuth2Request *Request);
#endif /* SB_USE_CLASS_TELOAUTH2REQUEST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void Start(int32_t &Method, std::string &URL, TStringList &RequestHeader, std::vector<uint8_t> &RequestBody);

		void Start(int32_t &Method, std::string &URL, TStringList *RequestHeader, std::vector<uint8_t> &RequestBody);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void Start(int32_t &Method, std::string &URL, TElStringList &RequestHeader, std::vector<uint8_t> &RequestBody);

		void Start(int32_t &Method, std::string &URL, TElStringList *RequestHeader, std::vector<uint8_t> &RequestBody);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELOAUTH2REQUEST
		void Start(TElOAuth2Request &Request);

		void Start(TElOAuth2Request *Request);
#endif /* SB_USE_CLASS_TELOAUTH2REQUEST */

#ifdef SB_USE_CLASS_TELOAUTH2SETTINGS
		void Apply(TElOAuth2Settings &Settings);

		void Apply(TElOAuth2Settings *Settings);
#endif /* SB_USE_CLASS_TELOAUTH2SETTINGS */

		virtual void get_AccessToken(std::string &OutResult);

		virtual void get_AuthURL(std::string &OutResult);

		virtual void set_AuthURL(const std::string &Value);

		virtual void get_ClientID(std::string &OutResult);

		virtual void set_ClientID(const std::string &Value);

		virtual void get_ClientSecret(std::string &OutResult);

		virtual void set_ClientSecret(const std::string &Value);

		virtual bool get_Complete();

		SB_DECLARE_PROPERTY_GET(bool, get_Complete, TElOAuth2Client, Complete);

		virtual int64_t get_ExpiresAt();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ExpiresAt, TElOAuth2Client, ExpiresAt);

		virtual int32_t get_ExpiresIn();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ExpiresIn, TElOAuth2Client, ExpiresIn);

		virtual TSBOAuth2GrantType get_GrantType();

		virtual void set_GrantType(TSBOAuth2GrantType Value);

		SB_DECLARE_PROPERTY(TSBOAuth2GrantType, get_GrantType, set_GrantType, TElOAuth2Client, GrantType);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual void get_RedirectURL(std::string &OutResult);

		virtual void set_RedirectURL(const std::string &Value);

		virtual void get_RefreshToken(std::string &OutResult);

		virtual void set_RefreshToken(const std::string &Value);

		virtual void get_Scope(std::string &OutResult);

		virtual void set_Scope(const std::string &Value);

		virtual void get_State(std::string &OutResult);

		virtual void set_State(const std::string &Value);

		virtual void get_TokenType(std::string &OutResult);

		virtual void get_TokenURL(std::string &OutResult);

		virtual void set_TokenURL(const std::string &Value);

		virtual bool get_UseURLParams();

		virtual void set_UseURLParams(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseURLParams, set_UseURLParams, TElOAuth2Client, UseURLParams);

		virtual void get_UserName(std::string &OutResult);

		virtual void set_UserName(const std::string &Value);

		TElOAuth2Client(TElOAuth2ClientHandle handle, TElOwnHandle ownHandle);

		TElOAuth2Client();

};
#endif /* SB_USE_CLASS_TELOAUTH2CLIENT */

#ifdef SB_USE_CLASS_TELOAUTH2REDIRECTRECEIVER
class TElOAuth2RedirectReceiver: public TComponent
{
	private:
		SB_DISABLE_COPY(TElOAuth2RedirectReceiver)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_ReceivedHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_ResponsePage;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_ReceivedHeaders;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_ResponsePage;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
		void Activate(const std::string &URL);

		void Activate(const std::string &LocalAddress, uint16_t LocalPort);

		void Deactivate();

		bool Receive();

		void Reset();

		virtual bool get_Active();

		SB_DECLARE_PROPERTY_GET(bool, get_Active, TElOAuth2RedirectReceiver, Active);

		virtual void get_AuthorizationCode(std::string &OutResult);

		virtual bool get_Done();

		SB_DECLARE_PROPERTY_GET(bool, get_Done, TElOAuth2RedirectReceiver, Done);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_ReceivedHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_ReceivedHeaders, TElOAuth2RedirectReceiver, ReceivedHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_ReceivedHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_ReceivedHeaders, TElOAuth2RedirectReceiver, ReceivedHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual int32_t get_BufferSize();

		virtual void set_BufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_BufferSize, set_BufferSize, TElOAuth2RedirectReceiver, BufferSize);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_ResponsePage();

		virtual void set_ResponsePage(TStringList &Value);

		virtual void set_ResponsePage(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_ResponsePage, set_ResponsePage, TElOAuth2RedirectReceiver, ResponsePage);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_ResponsePage();

		virtual void set_ResponsePage(TElStringList &Value);

		virtual void set_ResponsePage(TElStringList *Value);

		SB_DECLARE_PROPERTY(TElStringList*, get_ResponsePage, set_ResponsePage, TElOAuth2RedirectReceiver, ResponsePage);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
		virtual bool get_UseIPv6();

		virtual void set_UseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseIPv6, set_UseIPv6, TElOAuth2RedirectReceiver, UseIPv6);
#endif

		virtual void get_OnComplete(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnComplete(TNotifyEvent pMethodValue, void * pDataValue);

		TElOAuth2RedirectReceiver(TElOAuth2RedirectReceiverHandle handle, TElOwnHandle ownHandle);

		explicit TElOAuth2RedirectReceiver(TComponent &AOwner);

		explicit TElOAuth2RedirectReceiver(TComponent *AOwner);

		virtual ~TElOAuth2RedirectReceiver();

};
#endif /* SB_USE_CLASS_TELOAUTH2REDIRECTRECEIVER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBOAUTH2 */
