#ifndef __INC_SBSMTPCLIENT
#define __INC_SBSMTPCLIENT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbrandom.h"
#include "sbsslcommon.h"
#include "sbsslclient.h"
#include "sbsimplessl.h"
#include "sbx509.h"
#include "sbcustomcertstorage.h"
#include "sbconstants.h"
#include "sbsslconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbencoding.h"
#include "sbsasl.h"
#include "sbzlib.h"
#include "sbzcommonunit.h"
#include "sbzuncompressunit.h"
#include "sbsocket.h"
#include "sbstreams.h"
#include "sbmime.h"
#include "sbsimplemime.h"
#include "sbcmdsslclient.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifndef WINCE
#define SB_DefaultChunkSize 	65536
#define SB_DefaultBufferSize 	1048576
#else
#define SB_DefaultChunkSize 	32768
#define SB_DefaultBufferSize 	65536
#endif

typedef TElClassHandle TElSMTPClientHandle;

typedef TElSMTPClientHandle ElSMTPClientHandle;

typedef uint8_t TSBSMTPStateRaw;

typedef enum
{
	ssPlain = 0,
	ssEncrypted = 1
} TSBSMTPState;

typedef uint8_t TSBSMTPDSNOptionRaw;

typedef enum
{
	sdnSuccess = 0,
	sdnFailure = 1,
	sdnDelay = 2
} TSBSMTPDSNOption;

typedef uint32_t TSBSMTPDSNOptionsRaw;

typedef enum 
{
	f_sdnSuccess = 1,
	f_sdnFailure = 2,
	f_sdnDelay = 4
} TSBSMTPDSNOptions;

typedef uint8_t TSBSMTPDSNReturnTypeRaw;

typedef enum
{
	srtFull = 0,
	srtHeaders = 1
} TSBSMTPDSNReturnType;

#ifdef SB_WINDOWS
typedef void (SB_CALLBACK *TSBSMTPDSNEnvIDGenerateEvent)(void * _ObjectData, TObjectHandle Sender, TStringListHandle RcptTo, char * pcEnvID, int32_t * szEnvID);
#else
typedef void (SB_CALLBACK *TSBSMTPDSNEnvIDGenerateEvent)(void * _ObjectData, TObjectHandle Sender, TElStringListHandle RcptTo, char * pcEnvID, int32_t * szEnvID);
#endif

typedef void (SB_CALLBACK *TSBSMTPDSNOptionsEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcRcptTo, int32_t szRcptTo, TSBSMTPDSNOptionsRaw * Options);

#ifdef SB_USE_CLASS_TELSMTPCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_Close(TElSMTPClientHandle _Handle, int8_t Silent);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_Open(TElSMTPClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_EstablishSSLSession(TElSMTPClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_Login(TElSMTPClientHandle _Handle, const char * pcDomain, int32_t szDomain);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_Send(TElSMTPClientHandle _Handle, TElMessageHandle Message);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_Send_1(TElSMTPClientHandle _Handle, TElSimpleMIMEMessageHandle Message);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_Send_2(TElSMTPClientHandle _Handle, const char * pcMailFrom, int32_t szMailFrom, TStringListHandle RcptTo, TStringListHandle Message);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_Send_3(TElSMTPClientHandle _Handle, const char * pcMailFrom, int32_t szMailFrom, TStringListHandle RcptTo, TStreamHandle Message);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_Send_2(TElSMTPClientHandle _Handle, const char * pcMailFrom, int32_t szMailFrom, TElStringListHandle RcptTo, TElStringListHandle Message);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_Send_3(TElSMTPClientHandle _Handle, const char * pcMailFrom, int32_t szMailFrom, TElStringListHandle RcptTo, TStreamHandle Message);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_Send_4(TElSMTPClientHandle _Handle, TStreamHandle Message);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_SASLMechanism(TElSMTPClientHandle _Handle, const char * pcName, int32_t szName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_set_SASLMechanism(TElSMTPClientHandle _Handle, const char * pcName, int32_t szName, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_SASLMechanismPriorities(TElSMTPClientHandle _Handle, const char * pcName, int32_t szName, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_set_SASLMechanismPriorities(TElSMTPClientHandle _Handle, const char * pcName, int32_t szName, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_ExtSASLMechanisms(TElSMTPClientHandle _Handle, TStringListHandle OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_ExtensionChunkingSupported(TElSMTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_ExtensionBinarySupported(TElSMTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_ExtensionAuthPlainSupported(TElSMTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_ExtensionAuthLoginSupported(TElSMTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_ExtensionSASLLoginSupported(TElSMTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_ExtensionSizeSupported(TElSMTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_ExtensionDSNSupported(TElSMTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_SSLActive(TElSMTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_Address(TElSMTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_set_Address(TElSMTPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_AllowAuthentication(TElSMTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_set_AllowAuthentication(TElSMTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_AllowBinaryMode(TElSMTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_set_AllowBinaryMode(TElSMTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_BinaryChunkSize(TElSMTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_set_BinaryChunkSize(TElSMTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_Password(TElSMTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_set_Password(TElSMTPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_Port(TElSMTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_set_Port(TElSMTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_RemoveBCC(TElSMTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_set_RemoveBCC(TElSMTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_SendBufferSize(TElSMTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_set_SendBufferSize(TElSMTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_SSLMode(TElSMTPClientHandle _Handle, TSBSSLModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_set_SSLMode(TElSMTPClientHandle _Handle, TSBSSLModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_UseSSL(TElSMTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_set_UseSSL(TElSMTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_Username(TElSMTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_set_Username(TElSMTPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_DSNOptions(TElSMTPClientHandle _Handle, TSBSMTPDSNOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_set_DSNOptions(TElSMTPClientHandle _Handle, TSBSMTPDSNOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_DSNReturnType(TElSMTPClientHandle _Handle, TSBSMTPDSNReturnTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_set_DSNReturnType(TElSMTPClientHandle _Handle, TSBSMTPDSNReturnTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_OnProgress(TElSMTPClientHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_set_OnProgress(TElSMTPClientHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_OnDSNEnvIDGenerate(TElSMTPClientHandle _Handle, TSBSMTPDSNEnvIDGenerateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_set_OnDSNEnvIDGenerate(TElSMTPClientHandle _Handle, TSBSMTPDSNEnvIDGenerateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_get_OnDSNOptions(TElSMTPClientHandle _Handle, TSBSMTPDSNOptionsEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_set_OnDSNOptions(TElSMTPClientHandle _Handle, TSBSMTPDSNOptionsEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSMTPClient_Create(TComponentHandle AOwner, TElSMTPClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELSMTPCLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSMTPClient;
typedef TElSMTPClient ElSMTPClient;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBSMTPDSNOptions)

#ifdef SB_USE_CLASS_TELSMTPCLIENT
class TElSMTPClient: public TElCommandSSLClient
{
	private:
		SB_DISABLE_COPY(TElSMTPClient)
	public:
		virtual void Close(bool Silent);

		virtual void Open();

		void EstablishSSLSession();

		void Login(const std::string &Domain);

#ifdef SB_USE_CLASS_TELMESSAGE
		void Send(TElMessage &Message);

		void Send(TElMessage *Message);
#endif /* SB_USE_CLASS_TELMESSAGE */

#ifdef SB_USE_CLASS_TELSIMPLEMIMEMESSAGE
		void Send(TElSimpleMIMEMessage &Message);

		void Send(TElSimpleMIMEMessage *Message);
#endif /* SB_USE_CLASS_TELSIMPLEMIMEMESSAGE */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void Send(const std::string &MailFrom, TStringList &RcptTo, TStringList &Message);

		void Send(const std::string &MailFrom, TStringList *RcptTo, TStringList *Message);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void Send(const std::string &MailFrom, TElStringList &RcptTo, TElStringList &Message);

		void Send(const std::string &MailFrom, TElStringList *RcptTo, TElStringList *Message);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void Send(const std::string &MailFrom, TStringList &RcptTo, TStream &Message);

		void Send(const std::string &MailFrom, TStringList *RcptTo, TStream *Message);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void Send(const std::string &MailFrom, TElStringList &RcptTo, TStream &Message);

		void Send(const std::string &MailFrom, TElStringList *RcptTo, TStream *Message);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
		void Send(TStream &Message);

		void Send(TStream *Message);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual bool get_SASLMechanism(const std::string &Name);

		virtual void set_SASLMechanism(const std::string &Name, bool Value);

		virtual int32_t get_SASLMechanismPriorities(const std::string &Name);

		virtual void set_SASLMechanismPriorities(const std::string &Name, int32_t Value);

		virtual void get_ExtSASLMechanisms(TStringList &OutResult);

		virtual bool get_ExtensionChunkingSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtensionChunkingSupported, TElSMTPClient, ExtensionChunkingSupported);

		virtual bool get_ExtensionBinarySupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtensionBinarySupported, TElSMTPClient, ExtensionBinarySupported);

		virtual bool get_ExtensionAuthPlainSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtensionAuthPlainSupported, TElSMTPClient, ExtensionAuthPlainSupported);

		virtual bool get_ExtensionAuthLoginSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtensionAuthLoginSupported, TElSMTPClient, ExtensionAuthLoginSupported);

		virtual bool get_ExtensionSASLLoginSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtensionSASLLoginSupported, TElSMTPClient, ExtensionSASLLoginSupported);

		virtual bool get_ExtensionSizeSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtensionSizeSupported, TElSMTPClient, ExtensionSizeSupported);

		virtual bool get_ExtensionDSNSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtensionDSNSupported, TElSMTPClient, ExtensionDSNSupported);

		virtual bool get_SSLActive();

		SB_DECLARE_PROPERTY_GET(bool, get_SSLActive, TElSMTPClient, SSLActive);

		virtual void get_Address(std::string &OutResult);

		virtual void set_Address(const std::string &Value);

		virtual bool get_AllowAuthentication();

		virtual void set_AllowAuthentication(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AllowAuthentication, set_AllowAuthentication, TElSMTPClient, AllowAuthentication);

		virtual bool get_AllowBinaryMode();

		virtual void set_AllowBinaryMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AllowBinaryMode, set_AllowBinaryMode, TElSMTPClient, AllowBinaryMode);

		virtual int32_t get_BinaryChunkSize();

		virtual void set_BinaryChunkSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_BinaryChunkSize, set_BinaryChunkSize, TElSMTPClient, BinaryChunkSize);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual int32_t get_Port();

		virtual void set_Port(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Port, set_Port, TElSMTPClient, Port);

		virtual bool get_RemoveBCC();

		virtual void set_RemoveBCC(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RemoveBCC, set_RemoveBCC, TElSMTPClient, RemoveBCC);

		virtual int32_t get_SendBufferSize();

		virtual void set_SendBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SendBufferSize, set_SendBufferSize, TElSMTPClient, SendBufferSize);

		virtual TSBSSLMode get_SSLMode();

		virtual void set_SSLMode(TSBSSLMode Value);

		SB_DECLARE_PROPERTY(TSBSSLMode, get_SSLMode, set_SSLMode, TElSMTPClient, SSLMode);

		virtual bool get_UseSSL();

		virtual void set_UseSSL(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseSSL, set_UseSSL, TElSMTPClient, UseSSL);

		virtual void get_Username(std::string &OutResult);

		virtual void set_Username(const std::string &Value);

		virtual TSBSMTPDSNOptions get_DSNOptions();

		virtual void set_DSNOptions(TSBSMTPDSNOptions Value);

		SB_DECLARE_PROPERTY(TSBSMTPDSNOptions, get_DSNOptions, set_DSNOptions, TElSMTPClient, DSNOptions);

		virtual TSBSMTPDSNReturnType get_DSNReturnType();

		virtual void set_DSNReturnType(TSBSMTPDSNReturnType Value);

		SB_DECLARE_PROPERTY(TSBSMTPDSNReturnType, get_DSNReturnType, set_DSNReturnType, TElSMTPClient, DSNReturnType);

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnDSNEnvIDGenerate(TSBSMTPDSNEnvIDGenerateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDSNEnvIDGenerate(TSBSMTPDSNEnvIDGenerateEvent pMethodValue, void * pDataValue);

		virtual void get_OnDSNOptions(TSBSMTPDSNOptionsEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDSNOptions(TSBSMTPDSNOptionsEvent pMethodValue, void * pDataValue);

		TElSMTPClient(TElSMTPClientHandle handle, TElOwnHandle ownHandle);

		explicit TElSMTPClient(TComponent &AOwner);

		explicit TElSMTPClient(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELSMTPCLIENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSMTPCLIENT */
