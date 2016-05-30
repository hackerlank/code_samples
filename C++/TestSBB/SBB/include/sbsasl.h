#ifndef __INC_SBSASL
#define __INC_SBSASL

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstringlist.h"
#ifndef SB_WINCE_OR_NOT_WINDOWS
#include "sbhttpauth.h"
#endif
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbrandom.h"
#include "sbhashfunction.h"
#include "sbconstants.h"
#include "sbhttpsconstants.h"
#include "sbencoding.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SASL_MECHANISM_PLAIN 	"PLAIN"
#define SB_SASL_MECHANISM_LOGIN 	"LOGIN"
#define SB_SASL_MECHANISM_CRAM_MD5 	"CRAM-MD5"
#define SB_SASL_MECHANISM_EXTERNAL 	"EXTERNAL"
#define SB_SASL_MECHANISM_ANONYMOUS 	"ANONYMOUS"
#define SB_SASL_MECHANISM_DIGEST_MD5 	"DIGEST-MD5"
#define SB_SASL_MECHANISM_NTLM 	"NTLM"
#define SB_SASL_MECHANISM_GSSAPI 	"GSSAPI"
#define SB_SASL_MECHANISM_XOAUTH2 	"XOAUTH2"
#define SB_SASL_ERROR_BASE 	47696
#define SB_SASL_CRAM_ERROR_EMPTY_CHALLENGE 	47697
#define SB_SASL_CRAM_ERROR_INVALID_CHALLENGE 	47698
#define SB_SASL_DIGEST_ERROR_INVALID_CHALLENGE 	47699
#define SB_SASL_DIGEST_ERROR_INVALID_REALM 	47700
#define SB_SASL_DIGEST_ERROR_PARAMETER_NOT_SPECIFIED 	47701
#define SB_SASL_XOAUTH2_ERROR_UNKNOWN_RESPONSE 	47702
#define SB_SASL_XOAUTH2_ERROR_AUTHENTICATION_FAILED 	47703

typedef TElClassHandle TElSASLClientHandle;

typedef TElClassHandle TElSASLPlainClientHandle;

typedef TElClassHandle TElSASLLoginClientHandle;

typedef TElClassHandle TElSASLCRAMMD5ClientHandle;

typedef TElClassHandle TElSASLAnonymousClientHandle;

typedef TElClassHandle TElSASLExternalClientHandle;

typedef TElClassHandle TElSASLDigestMD5ClientHandle;

#ifndef SB_WINCE_OR_NOT_WINDOWS
typedef TElClassHandle TElSASLNTLMClientHandle;
#endif

typedef TElClassHandle TElSASLXOAuth2ClientHandle;

typedef uint8_t TSBSASLSecurityLevelRaw;

typedef enum
{
	saslAuthOnly = 0,
	saslAuthIntegrity = 1,
	saslAuthConfidentiality = 2
} TSBSASLSecurityLevel;

#ifdef SB_WINDOWS
typedef void (SB_CALLBACK *TSBSASLChallengeEvent)(void * _ObjectData, TStringListHandle Options);
#else
typedef void (SB_CALLBACK *TSBSASLChallengeEvent)(void * _ObjectData, TElStringListHandle Options);
#endif

typedef void (SB_CALLBACK *TSBSASLGetValueEvent)(void * _ObjectData, const char * pcName, int32_t szName, char * pcValue, int32_t * szValue);

#ifdef SB_USE_CLASS_TELSASLCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElSASLClient_ProcessChallenge(TElSASLClientHandle _Handle, const uint8_t pChallenge[], int32_t szChallenge, uint8_t pResponse[], int32_t * szResponse);
SB_IMPORT uint32_t SB_APIENTRY TElSASLClient_ValueExists(TElSASLClientHandle _Handle, const char * pcName, int32_t szName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLClient_WrapData(TElSASLClientHandle _Handle, void * InData, int32_t InSize, void * OutData, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLClient_WrapData_1(TElSASLClientHandle _Handle, const uint8_t pInData[], int32_t szInData, int32_t InStartIndex, int32_t InSize, uint8_t pOutData[], int32_t * szOutData, int32_t OutStartIndex, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLClient_UnwrapData(TElSASLClientHandle _Handle, void * InData, int32_t InSize, void * OutData, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLClient_UnwrapData_1(TElSASLClientHandle _Handle, const uint8_t pInData[], int32_t szInData, int32_t InStartIndex, int32_t InSize, uint8_t pOutData[], int32_t * szOutData, int32_t OutStartIndex, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLClient_get_Complete(TElSASLClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLClient_get_MechanismName(TElSASLClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLClient_get_SecurityLevel(TElSASLClientHandle _Handle, TSBSASLSecurityLevelRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLClient_get_Value(TElSASLClientHandle _Handle, const char * pcName, int32_t szName, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLClient_set_Value(TElSASLClientHandle _Handle, const char * pcName, int32_t szName, const char * pcNewValue, int32_t szNewValue);
SB_IMPORT uint32_t SB_APIENTRY TElSASLClient_get_OnChallenge(TElSASLClientHandle _Handle, TSBSASLChallengeEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLClient_set_OnChallenge(TElSASLClientHandle _Handle, TSBSASLChallengeEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSASLClient_get_OnGetValue(TElSASLClientHandle _Handle, TSBSASLGetValueEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLClient_set_OnGetValue(TElSASLClientHandle _Handle, TSBSASLGetValueEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSASLClient_Create(TElSASLClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELSASLCLIENT */

#ifdef SB_USE_CLASS_TELSASLPLAINCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElSASLPlainClient_ProcessChallenge(TElSASLPlainClientHandle _Handle, const uint8_t pChallenge[], int32_t szChallenge, uint8_t pResponse[], int32_t * szResponse);
SB_IMPORT uint32_t SB_APIENTRY TElSASLPlainClient_get_Password(TElSASLPlainClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLPlainClient_set_Password(TElSASLPlainClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSASLPlainClient_get_UserName(TElSASLPlainClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLPlainClient_set_UserName(TElSASLPlainClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSASLPlainClient_Create(TElSASLPlainClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELSASLPLAINCLIENT */

#ifdef SB_USE_CLASS_TELSASLLOGINCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElSASLLoginClient_ProcessChallenge(TElSASLLoginClientHandle _Handle, const uint8_t pChallenge[], int32_t szChallenge, uint8_t pResponse[], int32_t * szResponse);
SB_IMPORT uint32_t SB_APIENTRY TElSASLLoginClient_get_Password(TElSASLLoginClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLLoginClient_set_Password(TElSASLLoginClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSASLLoginClient_get_UserName(TElSASLLoginClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLLoginClient_set_UserName(TElSASLLoginClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSASLLoginClient_Create(TElSASLLoginClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELSASLLOGINCLIENT */

#ifdef SB_USE_CLASS_TELSASLCRAMMD5CLIENT
SB_IMPORT uint32_t SB_APIENTRY TElSASLCRAMMD5Client_ProcessChallenge(TElSASLCRAMMD5ClientHandle _Handle, const uint8_t pChallenge[], int32_t szChallenge, uint8_t pResponse[], int32_t * szResponse);
SB_IMPORT uint32_t SB_APIENTRY TElSASLCRAMMD5Client_get_Password(TElSASLCRAMMD5ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLCRAMMD5Client_set_Password(TElSASLCRAMMD5ClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSASLCRAMMD5Client_get_UserName(TElSASLCRAMMD5ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLCRAMMD5Client_set_UserName(TElSASLCRAMMD5ClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSASLCRAMMD5Client_Create(TElSASLCRAMMD5ClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELSASLCRAMMD5CLIENT */

#ifdef SB_USE_CLASS_TELSASLANONYMOUSCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElSASLAnonymousClient_ProcessChallenge(TElSASLAnonymousClientHandle _Handle, const uint8_t pChallenge[], int32_t szChallenge, uint8_t pResponse[], int32_t * szResponse);
SB_IMPORT uint32_t SB_APIENTRY TElSASLAnonymousClient_get_AuthID(TElSASLAnonymousClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLAnonymousClient_set_AuthID(TElSASLAnonymousClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSASLAnonymousClient_Create(TElSASLAnonymousClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELSASLANONYMOUSCLIENT */

#ifdef SB_USE_CLASS_TELSASLEXTERNALCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElSASLExternalClient_ProcessChallenge(TElSASLExternalClientHandle _Handle, const uint8_t pChallenge[], int32_t szChallenge, uint8_t pResponse[], int32_t * szResponse);
SB_IMPORT uint32_t SB_APIENTRY TElSASLExternalClient_get_AuthID(TElSASLExternalClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLExternalClient_set_AuthID(TElSASLExternalClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSASLExternalClient_Create(TElSASLExternalClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELSASLEXTERNALCLIENT */

#ifdef SB_USE_CLASS_TELSASLDIGESTMD5CLIENT
SB_IMPORT uint32_t SB_APIENTRY TElSASLDigestMD5Client_ProcessChallenge(TElSASLDigestMD5ClientHandle _Handle, const uint8_t pChallenge[], int32_t szChallenge, uint8_t pResponse[], int32_t * szResponse);
SB_IMPORT uint32_t SB_APIENTRY TElSASLDigestMD5Client_get_Password(TElSASLDigestMD5ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLDigestMD5Client_set_Password(TElSASLDigestMD5ClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSASLDigestMD5Client_get_UserName(TElSASLDigestMD5ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLDigestMD5Client_set_UserName(TElSASLDigestMD5ClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSASLDigestMD5Client_get_RequestURI(TElSASLDigestMD5ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLDigestMD5Client_set_RequestURI(TElSASLDigestMD5ClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSASLDigestMD5Client_get_RequestMethod(TElSASLDigestMD5ClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLDigestMD5Client_set_RequestMethod(TElSASLDigestMD5ClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSASLDigestMD5Client_get_CustomRequestMethod(TElSASLDigestMD5ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLDigestMD5Client_set_CustomRequestMethod(TElSASLDigestMD5ClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSASLDigestMD5Client_get_HTTPAuth(TElSASLDigestMD5ClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLDigestMD5Client_set_HTTPAuth(TElSASLDigestMD5ClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSASLDigestMD5Client_Create(TElSASLDigestMD5ClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELSASLDIGESTMD5CLIENT */

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELSASLNTLMCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElSASLNTLMClient_ProcessChallenge(TElSASLNTLMClientHandle _Handle, const uint8_t pChallenge[], int32_t szChallenge, uint8_t pResponse[], int32_t * szResponse);
SB_IMPORT uint32_t SB_APIENTRY TElSASLNTLMClient_get_Password(TElSASLNTLMClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLNTLMClient_set_Password(TElSASLNTLMClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSASLNTLMClient_get_UserName(TElSASLNTLMClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLNTLMClient_set_UserName(TElSASLNTLMClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSASLNTLMClient_Create(TElSASLNTLMClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELSASLNTLMCLIENT */
#endif

#ifdef SB_USE_CLASS_TELSASLXOAUTH2CLIENT
SB_IMPORT uint32_t SB_APIENTRY TElSASLXOAuth2Client_ProcessChallenge(TElSASLXOAuth2ClientHandle _Handle, const uint8_t pChallenge[], int32_t szChallenge, uint8_t pResponse[], int32_t * szResponse);
SB_IMPORT uint32_t SB_APIENTRY TElSASLXOAuth2Client_get_AccessToken(TElSASLXOAuth2ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLXOAuth2Client_set_AccessToken(TElSASLXOAuth2ClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSASLXOAuth2Client_get_UserName(TElSASLXOAuth2ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSASLXOAuth2Client_set_UserName(TElSASLXOAuth2ClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSASLXOAuth2Client_Create(TElSASLXOAuth2ClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELSASLXOAUTH2CLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSASLClient;
class TElSASLPlainClient;
class TElSASLLoginClient;
class TElSASLCRAMMD5Client;
class TElSASLAnonymousClient;
class TElSASLExternalClient;
class TElSASLDigestMD5Client;
#ifndef SB_WINCE_OR_NOT_WINDOWS
class TElSASLNTLMClient;
#endif
class TElSASLXOAuth2Client;

#ifdef SB_USE_CLASS_TELSASLCLIENT
class TElSASLClient: public TObject
{
	private:
		SB_DISABLE_COPY(TElSASLClient)
	public:
		virtual void ProcessChallenge(const std::vector<uint8_t> &Challenge, std::vector<uint8_t> &Response);

		virtual bool ValueExists(const std::string &Name);

		virtual bool WrapData(void * InData, int32_t InSize, void * OutData, int32_t &OutSize);

		virtual bool WrapData(const std::vector<uint8_t> &InData, int32_t InStartIndex, int32_t InSize, std::vector<uint8_t> &OutData, int32_t OutStartIndex, int32_t &OutSize);

		virtual bool UnwrapData(void * InData, int32_t InSize, void * OutData, int32_t &OutSize);

		virtual bool UnwrapData(const std::vector<uint8_t> &InData, int32_t InStartIndex, int32_t InSize, std::vector<uint8_t> &OutData, int32_t OutStartIndex, int32_t &OutSize);

		virtual bool get_Complete();

		SB_DECLARE_PROPERTY_GET(bool, get_Complete, TElSASLClient, Complete);

		virtual void get_MechanismName(std::string &OutResult);

		virtual TSBSASLSecurityLevel get_SecurityLevel();

		SB_DECLARE_PROPERTY_GET(TSBSASLSecurityLevel, get_SecurityLevel, TElSASLClient, SecurityLevel);

		virtual void get_Value(const std::string &Name, std::string &OutResult);

		virtual void set_Value(const std::string &Name, const std::string &NewValue);

		virtual void get_OnChallenge(TSBSASLChallengeEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnChallenge(TSBSASLChallengeEvent pMethodValue, void * pDataValue);

		virtual void get_OnGetValue(TSBSASLGetValueEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetValue(TSBSASLGetValueEvent pMethodValue, void * pDataValue);

		TElSASLClient(TElSASLClientHandle handle, TElOwnHandle ownHandle);

		TElSASLClient();

};
#endif /* SB_USE_CLASS_TELSASLCLIENT */

#ifdef SB_USE_CLASS_TELSASLPLAINCLIENT
class TElSASLPlainClient: public TElSASLClient
{
	private:
		SB_DISABLE_COPY(TElSASLPlainClient)
	public:
		virtual void ProcessChallenge(const std::vector<uint8_t> &Challenge, std::vector<uint8_t> &Response);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual void get_UserName(std::string &OutResult);

		virtual void set_UserName(const std::string &Value);

		TElSASLPlainClient(TElSASLPlainClientHandle handle, TElOwnHandle ownHandle);

		TElSASLPlainClient();

};
#endif /* SB_USE_CLASS_TELSASLPLAINCLIENT */

#ifdef SB_USE_CLASS_TELSASLLOGINCLIENT
class TElSASLLoginClient: public TElSASLClient
{
	private:
		SB_DISABLE_COPY(TElSASLLoginClient)
	public:
		virtual void ProcessChallenge(const std::vector<uint8_t> &Challenge, std::vector<uint8_t> &Response);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual void get_UserName(std::string &OutResult);

		virtual void set_UserName(const std::string &Value);

		TElSASLLoginClient(TElSASLLoginClientHandle handle, TElOwnHandle ownHandle);

		TElSASLLoginClient();

};
#endif /* SB_USE_CLASS_TELSASLLOGINCLIENT */

#ifdef SB_USE_CLASS_TELSASLCRAMMD5CLIENT
class TElSASLCRAMMD5Client: public TElSASLClient
{
	private:
		SB_DISABLE_COPY(TElSASLCRAMMD5Client)
	public:
		virtual void ProcessChallenge(const std::vector<uint8_t> &Challenge, std::vector<uint8_t> &Response);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual void get_UserName(std::string &OutResult);

		virtual void set_UserName(const std::string &Value);

		TElSASLCRAMMD5Client(TElSASLCRAMMD5ClientHandle handle, TElOwnHandle ownHandle);

		TElSASLCRAMMD5Client();

};
#endif /* SB_USE_CLASS_TELSASLCRAMMD5CLIENT */

#ifdef SB_USE_CLASS_TELSASLANONYMOUSCLIENT
class TElSASLAnonymousClient: public TElSASLClient
{
	private:
		SB_DISABLE_COPY(TElSASLAnonymousClient)
	public:
		virtual void ProcessChallenge(const std::vector<uint8_t> &Challenge, std::vector<uint8_t> &Response);

		virtual void get_AuthID(std::string &OutResult);

		virtual void set_AuthID(const std::string &Value);

		TElSASLAnonymousClient(TElSASLAnonymousClientHandle handle, TElOwnHandle ownHandle);

		TElSASLAnonymousClient();

};
#endif /* SB_USE_CLASS_TELSASLANONYMOUSCLIENT */

#ifdef SB_USE_CLASS_TELSASLEXTERNALCLIENT
class TElSASLExternalClient: public TElSASLClient
{
	private:
		SB_DISABLE_COPY(TElSASLExternalClient)
	public:
		virtual void ProcessChallenge(const std::vector<uint8_t> &Challenge, std::vector<uint8_t> &Response);

		virtual void get_AuthID(std::string &OutResult);

		virtual void set_AuthID(const std::string &Value);

		TElSASLExternalClient(TElSASLExternalClientHandle handle, TElOwnHandle ownHandle);

		TElSASLExternalClient();

};
#endif /* SB_USE_CLASS_TELSASLEXTERNALCLIENT */

#ifdef SB_USE_CLASS_TELSASLDIGESTMD5CLIENT
class TElSASLDigestMD5Client: public TElSASLClient
{
	private:
		SB_DISABLE_COPY(TElSASLDigestMD5Client)
	public:
		virtual void ProcessChallenge(const std::vector<uint8_t> &Challenge, std::vector<uint8_t> &Response);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual void get_UserName(std::string &OutResult);

		virtual void set_UserName(const std::string &Value);

		virtual void get_RequestURI(std::string &OutResult);

		virtual void set_RequestURI(const std::string &Value);

		virtual int32_t get_RequestMethod();

		virtual void set_RequestMethod(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_RequestMethod, set_RequestMethod, TElSASLDigestMD5Client, RequestMethod);

		virtual void get_CustomRequestMethod(std::string &OutResult);

		virtual void set_CustomRequestMethod(const std::string &Value);

		virtual bool get_HTTPAuth();

		virtual void set_HTTPAuth(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HTTPAuth, set_HTTPAuth, TElSASLDigestMD5Client, HTTPAuth);

		TElSASLDigestMD5Client(TElSASLDigestMD5ClientHandle handle, TElOwnHandle ownHandle);

		TElSASLDigestMD5Client();

};
#endif /* SB_USE_CLASS_TELSASLDIGESTMD5CLIENT */

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELSASLNTLMCLIENT
class TElSASLNTLMClient: public TElSASLClient
{
	private:
		SB_DISABLE_COPY(TElSASLNTLMClient)
	public:
		virtual void ProcessChallenge(const std::vector<uint8_t> &Challenge, std::vector<uint8_t> &Response);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual void get_UserName(std::string &OutResult);

		virtual void set_UserName(const std::string &Value);

		TElSASLNTLMClient(TElSASLNTLMClientHandle handle, TElOwnHandle ownHandle);

		TElSASLNTLMClient();

};
#endif /* SB_USE_CLASS_TELSASLNTLMCLIENT */
#endif

#ifdef SB_USE_CLASS_TELSASLXOAUTH2CLIENT
class TElSASLXOAuth2Client: public TElSASLClient
{
	private:
		SB_DISABLE_COPY(TElSASLXOAuth2Client)
	public:
		virtual void ProcessChallenge(const std::vector<uint8_t> &Challenge, std::vector<uint8_t> &Response);

		virtual void get_AccessToken(std::string &OutResult);

		virtual void set_AccessToken(const std::string &Value);

		virtual void get_UserName(std::string &OutResult);

		virtual void set_UserName(const std::string &Value);

		TElSASLXOAuth2Client(TElSASLXOAuth2ClientHandle handle, TElOwnHandle ownHandle);

		TElSASLXOAuth2Client();

};
#endif /* SB_USE_CLASS_TELSASLXOAUTH2CLIENT */

#ifdef SB_USE_GLOBAL_PROCS_SASL

#ifdef SB_USE_CLASS_TELSASLCLIENT
TElSASLClientHandle CreateSASLClient(const std::string &Mechanism);
#endif /* SB_USE_CLASS_TELSASLCLIENT */

#ifdef SB_USE_CLASSES_TELSASLCLIENT_AND_TSTRINGLIST
TElSASLClientHandle CreateSASLClient(const TStringList &Mechanisms);
#endif /* SB_USE_CLASSES_TELSASLCLIENT_AND_TSTRINGLIST */

#endif /* SB_USE_GLOBAL_PROCS_SASL */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_SASL
SB_IMPORT uint32_t SB_APIENTRY SBSASL_CreateSASLClient(const char * pcMechanism, int32_t szMechanism, TElSASLClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSASL_CreateSASLClient_1(const TStringListHandle Mechanisms, TElSASLClientHandle * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_SASL */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSASL */
