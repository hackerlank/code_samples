#ifndef __INC_SBHTTPAUTH
#define __INC_SBHTTPAUTH

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbencoding.h"
#include "sbhashfunction.h"
#include "sbconstants.h"
#include "sbhttpsconstants.h"
#include "sbrandom.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SEC_WINNT_AUTH_IDENTITY_ANSI 	1
#define SB_SEC_WINNT_AUTH_IDENTITY_UNICODE 	2
#define SB_SECPKG_CRED_OUTBOUND 	2
#define SB_SECBUFFER_TOKEN 	2
#define SB_SECURITY_NATIVE_DREP 	16
#define SB_SEC_I_CONTINUE_NEEDED 	590610
#define SB_SEC_I_COMPLETE_NEEDED 	590611
#define SB_SEC_I_COMPLETE_AND_CONTINUE 	590612

typedef int32_t * PInteger;

typedef uint32_t * SBHTTPAuth_PUInt32;

#pragma pack(4)
typedef struct 
{
#ifndef SB_WINCE_OR_NOT_WINDOWS
	uint32_t * dwLower;
	uint32_t * dwUpper;
} SBHTTPAuth_CredHandle, * SBHTTPAuth_PCredHandle, * SBHTTPAuth_PCtxtHandle;

typedef SBHTTPAuth_CredHandle SBHTTPAuth_CtxtHandle;

#pragma pack(4)
typedef struct 
{
	uint32_t cbBuffer;
	uint32_t BufferType;
	void * pvBuffer;
} SBHTTPAuth_SecBuffer, * SBHTTPAuth_PSecBuffer;

#pragma pack(4)
typedef struct 
{
	uint32_t ulVersion;
	uint32_t cBuffers;
	SBHTTPAuth_PSecBuffer pBuffers;
} SBHTTPAuth_SecBufferDesc, * SBHTTPAuth_PSecBufferDesc;

typedef int64_t * SBHTTPAuth_pint64;

#pragma pack(4)
typedef struct 
{
	uint32_t fCapabilities;
	uint16_t wVersion;
	uint16_t wRPCID;
	uint32_t cbMaxToken;
	char * Name;
	char * Comment;
} SecPkgInfo, * PSecPkgInfo;

#pragma pack(4)
typedef struct 
{
	char * User;
	uint32_t UserLength;
	char * Domain;
	uint32_t DomainLength;
	char * Password;
	uint32_t PasswordLength;
	uint32_t Flags;
} SBHTTPAuth_SEC_WINNT_AUTH_IDENTITY, * SBHTTPAuth_PSEC_WINNT_AUTH_IDENTITY;

#pragma pack(4)
typedef struct 
{
	int8_t NewConversation;
#else
	int8_t UUEncodeData;
#endif
	int8_t _dummy0;
	int16_t _dummy1;
#ifndef SB_WINCE_OR_NOT_WINDOWS
	SBHTTPAuth_CredHandle hcred;
	int8_t HaveCredHandle;
	int8_t _dummy2;
	int16_t _dummy3;
	uint32_t MaxToken;
	int8_t HaveCtxtHandle;
	int8_t _dummy4;
	int16_t _dummy5;
	SBHTTPAuth_CredHandle hctxt;
	SBHTTPAuth_SEC_WINNT_AUTH_IDENTITY AuthIdentity;
	int8_t UUEncodeData;
	int8_t _dummy6;
	int16_t _dummy7;
#endif
	void * RequestURI;
	int32_t RequestMethod;
	void * sNonce;
	void * cNonce;
	int32_t cNonceCount;
	void * cRequest;
} AUTH_SEQ, * PAUTH_SEQ;

#ifndef SB_WINCE_OR_NOT_WINDOWS
typedef void (SB_CALLBACK *SBHTTPAuth_SEC_GET_KEY_FN)(void * Arg, void * Principal, uint32_t KeyVer, void * (* Key), int32_t * Status);

typedef void (SB_CALLBACK *SBHTTPAuth_FREE_CREDENTIALS_HANDLE_FN)(SBHTTPAuth_PCredHandle cred, int32_t * OutResult);

typedef void (SB_CALLBACK *ACQUIRE_CREDENTIALS_HANDLE_FN)(char * p1, char * p2, uint32_t p3, void * p4, void * p5, SBHTTPAuth_SEC_GET_KEY_FN p6, void * p7, SBHTTPAuth_PCredHandle p8, int64_t * p9, int32_t * OutResult);

typedef void (SB_CALLBACK *QUERY_SECURITY_PACKAGE_INFO_FN)(char * p1, PSecPkgInfo p2, int32_t * OutResult);

typedef void (SB_CALLBACK *SBHTTPAuth_FREE_CONTEXT_BUFFER_FN)(void * buf, int32_t * OutResult);

typedef void (SB_CALLBACK *INITIALIZE_SECURITY_CONTEXT_FN)(SBHTTPAuth_PCredHandle p1, SBHTTPAuth_PCtxtHandle p2, char * p3, uint32_t p4, uint32_t p5, uint32_t p6, SBHTTPAuth_PSecBufferDesc p7, uint32_t p8, SBHTTPAuth_PCtxtHandle p9, SBHTTPAuth_PSecBufferDesc p10, uint32_t * p11, int64_t * p12, int32_t * OutResult);

typedef void (SB_CALLBACK *SBHTTPAuth_COMPLETE_AUTH_TOKEN_FN)(SBHTTPAuth_PCtxtHandle p1, SBHTTPAuth_PSecBufferDesc p2, int32_t * OutResult);

typedef void (SB_CALLBACK *ENUMERATE_SECURITY_PACKAGES_FN)(uint32_t * p1, PSecPkgInfo p2, int32_t * OutResult);

typedef void (SB_CALLBACK *SBHTTPAuth_DELETE_SECURITY_CONTEXT_FN)(SBHTTPAuth_PCtxtHandle ctx, int32_t * OutResult);

#pragma pack(4)
typedef struct 
{
	void * FreeCredentialsHandle;
	void * AcquireCredentialsHandleA;
	void * QuerySecurityPackageInfoA;
	void * FreeContextBuffer;
	void * InitializeSecurityContextA;
	void * CompleteAuthToken;
	void * EnumerateSecurityPackagesA;
	void * DeleteSecurityContext;
} secFuncs;
#endif

typedef void * (* SBHTTPAuth_PPointer);

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_HTTPAUTH

void AuthInit(PAUTH_SEQ pAS);

void AuthTerm(PAUTH_SEQ pAS);

bool AuthConverse(PAUTH_SEQ pAS, const std::vector<uint8_t> &BuffIn, std::vector<uint8_t> &BuffOut, bool &NeedMoreData, const std::string &Package, const std::string &User, const std::string &Password);

bool AddAuthorizationHeader(std::string &Str, const std::string &Scheme, const std::string &AuthData, const std::string &UserName, const std::string &Password, bool &NeedMoreData, bool ForProxy, PAUTH_SEQ aSeq);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
void ValidateSecPacks(TStringList &ls);
void ValidateSecPacks(TStringList *ls);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
void ValidateSecPacks(TElStringList &ls);
void ValidateSecPacks(TElStringList *ls);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void InitAuthLib();

#endif /* SB_USE_GLOBAL_PROCS_HTTPAUTH */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_HTTPAUTH
SB_IMPORT uint32_t SB_APIENTRY SBHTTPAuth_AuthInit(PAUTH_SEQ pAS);
SB_IMPORT uint32_t SB_APIENTRY SBHTTPAuth_AuthTerm(PAUTH_SEQ pAS);
SB_IMPORT uint32_t SB_APIENTRY SBHTTPAuth_AuthConverse(PAUTH_SEQ pAS, const uint8_t pBuffIn[], int32_t szBuffIn, uint8_t pBuffOut[], int32_t * szBuffOut, int8_t * NeedMoreData, const char * pcPackage, int32_t szPackage, const char * pcUser, int32_t szUser, const char * pcPassword, int32_t szPassword, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBHTTPAuth_AddAuthorizationHeader(char * pcStr, int32_t * szStr, const char * pcScheme, int32_t szScheme, const char * pcAuthData, int32_t szAuthData, const char * pcUserName, int32_t szUserName, const char * pcPassword, int32_t szPassword, int8_t * NeedMoreData, int8_t ForProxy, PAUTH_SEQ aSeq, int8_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY SBHTTPAuth_ValidateSecPacks(TStringListHandle ls);
#else
SB_IMPORT uint32_t SB_APIENTRY SBHTTPAuth_ValidateSecPacks(TElStringListHandle ls);
#endif
SB_IMPORT uint32_t SB_APIENTRY SBHTTPAuth_InitAuthLib(void);
#endif /* SB_USE_GLOBAL_PROCS_HTTPAUTH */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBHTTPAUTH */
