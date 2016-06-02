#ifndef __INC_SBPOP3CLIENT
#define __INC_SBPOP3CLIENT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbsimplessl.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbstreams.h"
#include "sbmime.h"
#include "sbsocket.h"
#include "sbsslcommon.h"
#include "sbsslconstants.h"
#include "sbsslclient.h"
#include "sbx509.h"
#include "sbsasl.h"
#include "sbstringlist.h"
#include "sbencoding.h"
#ifndef SB_WINCE_OR_NOT_WINDOWS
#include "sbdnssectypes.h"
#endif

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ERROR_FACILITY_POP3 	106496
#define SB_ERROR_POP3_PROTOCOL_ERROR_FLAG 	2048
#define SB_POP3_ERROR_NOT_CONNECTED 	108545
#define SB_POP3_ERROR_ALREADY_CONNECTED 	108546
#define SB_POP3_ERROR_INVALID_STATE 	108547
#define SB_POP3_ERROR_INVALID_LENGTH 	108548
#define SB_POP3_ERROR_SMALL_LENGTH 	108549
#define SB_POP3_ERROR_NO_ADDRESS 	108550
#define SB_POP3_ERROR_EMPTY_REPLY 	108551
#define SB_POP3_ERROR_INVALID_REPLY 	108552
#define SB_POP3_ERROR_INSUFFICIENT_BUFFER 	108553
#define SB_POP3_ERROR_TOO_LONG_LINE 	108554
#define SB_POP3_ERROR_AUTHORIZATION_FAILED 	108555
#define SB_POP3_ERROR_MESSAGE_FAILED 	108556
#define SB_POP3_ERROR_DELETE_FAILED 	108557
#define SB_POP3_ERROR_MAILBOX_INFO_FAILED 	108558
#define SB_POP3_ERROR_CAPABILITIES_FAILED 	108559
#define SB_POP3_ERROR_SSL_SESSION_FAILURE 	108560
#define SB_POP3_ERROR_ID_INFO_FAILED 	108561
#define SB_POP3_ERROR_ALLID_INFO_FAILED 	108562
#define SB_POP3_ERROR_TOP_INFO_FAILED 	108563
#define SB_POP3_ERROR_SIZE_INFO_FAILED 	108564

typedef TElClassHandle TElPOP3ClientHandle;

typedef TElPOP3ClientHandle ElPOP3ClientHandle;

typedef uint8_t TSBPOP3AuthorizationRaw;

typedef enum
{
	popUSER = 0,
	popAPOP = 1,
	popSASL = 2
} TSBPOP3Authorization;

typedef uint32_t TSBPOP3AuthorizationsRaw;

typedef enum 
{
	f_popUSER = 1,
	f_popAPOP = 2,
	f_popSASL = 4
} TSBPOP3Authorizations;

typedef uint8_t TSBPOP3AutoCAPAModeRaw;

typedef enum
{
	capaNone = 0,
	capaOnConnect = 1,
	capaOnLogin = 2,
	capaBoth = 3
} TSBPOP3AutoCAPAMode;

typedef uint8_t TSBPOP3LogDirectionRaw;

typedef enum
{
	popSent = 0,
	popReceived = 1
} TSBPOP3LogDirection;

typedef void (SB_CALLBACK *TSBPOP3LogEvent)(void * _ObjectData, TObjectHandle Sender, TSBPOP3LogDirectionRaw Direction, const char * pcInfo, int32_t szInfo);

typedef void (SB_CALLBACK *TSBPOP3TextLineEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcInfo, int32_t szInfo);

typedef void (SB_CALLBACK *TSBPOP3MessageIdEvent)(void * _ObjectData, TObjectHandle Sender, int32_t Index, const char * pcID, int32_t szID);

typedef void (SB_CALLBACK *TSBPOP3MessageSizeEvent)(void * _ObjectData, TObjectHandle Sender, int32_t Index, int64_t Size);

typedef uint8_t TSBPOP3StateRaw;

typedef enum
{
	popAuthorization = 0,
	popTransaction = 1,
	popUpdate = 2
} TSBPOP3State;

#pragma pack(4)
typedef struct 
{
	int32_t Index;
	void * ID;
} TSBPOP3MessageID;

#pragma pack(4)
typedef struct 
{
	int32_t Index;
	int64_t Size;
} TSBPOP3MessageSize;

#ifdef SB_USE_CLASS_TELPOP3CLIENT
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_Close(TElPOP3ClientHandle _Handle, int8_t Silent);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_DeleteMessage(TElPOP3ClientHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_GetCapabilities(TElPOP3ClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_GetMailboxInfo(TElPOP3ClientHandle _Handle, int32_t * Messages, int64_t * TotalSize);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_GetMailboxSize(TElPOP3ClientHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_GetMessageCount(TElPOP3ClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_GetMessageID(TElPOP3ClientHandle _Handle, int32_t Index, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_GetMessageIDList(TElPOP3ClientHandle _Handle, TSBPOP3MessageID pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_GetMessageList(TElPOP3ClientHandle _Handle, TSBPOP3MessageSize pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_GetMessageSize(TElPOP3ClientHandle _Handle, int32_t Index, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_Login(TElPOP3ClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_Open(TElPOP3ClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_Noop(TElPOP3ClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_Ping(TElPOP3ClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_ReceiveMessage(TElPOP3ClientHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_ReceiveMessage_1(TElPOP3ClientHandle _Handle, int32_t Index, const uint8_t pBuffer[], int32_t szBuffer, int32_t Offset, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_ReceiveMessage_2(TElPOP3ClientHandle _Handle, int32_t Index, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_ReceiveMessage_3(TElPOP3ClientHandle _Handle, int32_t Index, const char * pcHeaderCharset, int32_t szHeaderCharset, const char * pcBodyCharset, int32_t szBodyCharset, TElMessageParsingOptionsRaw Options, int8_t IgnoreHeaderNativeCharset, int8_t IgnoreBodyNativeCharset, int8_t ActivatePartHandlers, TElMessageHandle * Message, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_ReceiveMessageHeader(TElPOP3ClientHandle _Handle, int32_t Index, char * pcCharset, int32_t * szCharset, int8_t IgnoreNativeCharset, TElMessageHeaderHandle * Header, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_ReceiveMessageIDList(TElPOP3ClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_ReceiveMessageLines(TElPOP3ClientHandle _Handle, int32_t Index, int32_t LineCount);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_ReceiveMessageLines_1(TElPOP3ClientHandle _Handle, int32_t Index, int32_t LineCount, const uint8_t pBuffer[], int32_t szBuffer, int32_t Offset, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_ReceiveMessageLines_2(TElPOP3ClientHandle _Handle, int32_t Index, int32_t LineCount, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_ReceiveMessageList(TElPOP3ClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_Reset(TElPOP3ClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_Undelete(TElPOP3ClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_SASLMechanism(TElPOP3ClientHandle _Handle, const char * pcName, int32_t szName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_SASLMechanism(TElPOP3ClientHandle _Handle, const char * pcName, int32_t szName, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_SASLMechanismPriorities(TElPOP3ClientHandle _Handle, const char * pcName, int32_t szName, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_SASLMechanismPriorities(TElPOP3ClientHandle _Handle, const char * pcName, int32_t szName, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_AuthorizationPriorities(TElPOP3ClientHandle _Handle, TSBPOP3AuthorizationRaw Auth, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_AuthorizationPriorities(TElPOP3ClientHandle _Handle, TSBPOP3AuthorizationRaw Auth, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_Authorization(TElPOP3ClientHandle _Handle, TSBPOP3AuthorizationRaw Auth, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_Authorization(TElPOP3ClientHandle _Handle, TSBPOP3AuthorizationRaw Auth, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_ExtAPOPSupported(TElPOP3ClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_ExtUIDLSupported(TElPOP3ClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_ExtUSERSupported(TElPOP3ClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_ExtTOPSupported(TElPOP3ClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_ExtRESP_CODESSupported(TElPOP3ClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_ExtLOGIN_DELAYSupported(TElPOP3ClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_ExtEXPIRESupported(TElPOP3ClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_ExtIMPLEMENTATIONSupported(TElPOP3ClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_ExtSASLSupported(TElPOP3ClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_ExtSASLMechanisms(TElPOP3ClientHandle _Handle, TStringListHandle OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_ExtExpire(TElPOP3ClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_ExtExpireUserChangeable(TElPOP3ClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_ExtLoginDelay(TElPOP3ClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_ExtImplementation(TElPOP3ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_SSLActive(TElPOP3ClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_Address(TElPOP3ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_Address(TElPOP3ClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_AutoCAPA(TElPOP3ClientHandle _Handle, TSBPOP3AutoCAPAModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_AutoCAPA(TElPOP3ClientHandle _Handle, TSBPOP3AutoCAPAModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_MaxLineLength(TElPOP3ClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_MaxLineLength(TElPOP3ClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_Port(TElPOP3ClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_Port(TElPOP3ClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_SSLMode(TElPOP3ClientHandle _Handle, TSBSSLModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_SSLMode(TElPOP3ClientHandle _Handle, TSBSSLModeRaw Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_UseIPv6(TElPOP3ClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_UseIPv6(TElPOP3ClientHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_UseSSL(TElPOP3ClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_UseSSL(TElPOP3ClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_Username(TElPOP3ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_Username(TElPOP3ClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_Password(TElPOP3ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_Password(TElPOP3ClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_OnCapability(TElPOP3ClientHandle _Handle, TSBPOP3TextLineEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_OnCapability(TElPOP3ClientHandle _Handle, TSBPOP3TextLineEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_OnLog(TElPOP3ClientHandle _Handle, TSBPOP3LogEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_OnLog(TElPOP3ClientHandle _Handle, TSBPOP3LogEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_OnMessageLine(TElPOP3ClientHandle _Handle, TSBPOP3TextLineEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_OnMessageLine(TElPOP3ClientHandle _Handle, TSBPOP3TextLineEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_OnMessageID(TElPOP3ClientHandle _Handle, TSBPOP3MessageIdEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_OnMessageID(TElPOP3ClientHandle _Handle, TSBPOP3MessageIdEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_OnMessageSize(TElPOP3ClientHandle _Handle, TSBPOP3MessageSizeEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_OnMessageSize(TElPOP3ClientHandle _Handle, TSBPOP3MessageSizeEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_OnProgress(TElPOP3ClientHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_OnProgress(TElPOP3ClientHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_OnCertificateChoose(TElPOP3ClientHandle _Handle, TSBChooseCertificateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_OnCertificateChoose(TElPOP3ClientHandle _Handle, TSBChooseCertificateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_OnCertificateNeededEx(TElPOP3ClientHandle _Handle, TSBCertificateNeededExEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_OnCertificateNeededEx(TElPOP3ClientHandle _Handle, TSBCertificateNeededExEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_OnCertificateValidate(TElPOP3ClientHandle _Handle, TSBCertificateValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_OnCertificateValidate(TElPOP3ClientHandle _Handle, TSBCertificateValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_OnCiphersNegotiated(TElPOP3ClientHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_OnCiphersNegotiated(TElPOP3ClientHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_OnCloseConnection(TElPOP3ClientHandle _Handle, TSBCloseConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_OnCloseConnection(TElPOP3ClientHandle _Handle, TSBCloseConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_OnError(TElPOP3ClientHandle _Handle, TSBErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_OnError(TElPOP3ClientHandle _Handle, TSBErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_OnExtensionsReceived(TElPOP3ClientHandle _Handle, TSBExtensionsReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_OnExtensionsReceived(TElPOP3ClientHandle _Handle, TSBExtensionsReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_OnExtensionsPrepared(TElPOP3ClientHandle _Handle, TSBExtensionsPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_OnExtensionsPrepared(TElPOP3ClientHandle _Handle, TSBExtensionsPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_OnCertificateStatus(TElPOP3ClientHandle _Handle, TSBCertificateStatusEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_OnCertificateStatus(TElPOP3ClientHandle _Handle, TSBCertificateStatusEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_OnKeyNeeded(TElPOP3ClientHandle _Handle, TSBClientKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_OnKeyNeeded(TElPOP3ClientHandle _Handle, TSBClientKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_OnRenegotiationRequest(TElPOP3ClientHandle _Handle, TSBRenegotiationRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_OnRenegotiationRequest(TElPOP3ClientHandle _Handle, TSBRenegotiationRequestEvent pMethodValue, void * pDataValue);
#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_OnDNSKeyNeeded(TElPOP3ClientHandle _Handle, TSBDNSKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_OnDNSKeyNeeded(TElPOP3ClientHandle _Handle, TSBDNSKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_OnDNSKeyValidate(TElPOP3ClientHandle _Handle, TSBDNSKeyValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_OnDNSKeyValidate(TElPOP3ClientHandle _Handle, TSBDNSKeyValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_get_OnDNSResolve(TElPOP3ClientHandle _Handle, TSBDNSResolveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_set_OnDNSResolve(TElPOP3ClientHandle _Handle, TSBDNSResolveEvent pMethodValue, void * pDataValue);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPOP3Client_Create(TComponentHandle AOwner, TElPOP3ClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELPOP3CLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPOP3Client;
typedef TElPOP3Client ElPOP3Client;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBPOP3Authorizations)

#ifdef SB_USE_CLASS_TELPOP3CLIENT
class TElPOP3Client: public TElCustomSimpleSSLClient
{
	private:
		SB_DISABLE_COPY(TElPOP3Client)
	public:
		virtual void Close(bool Silent);

		void DeleteMessage(int32_t Index);

		void GetCapabilities();

		void GetMailboxInfo(int32_t &Messages, int64_t &TotalSize);

		int64_t GetMailboxSize();

		int32_t GetMessageCount();

		void GetMessageID(int32_t Index, std::string &OutResult);

		void GetMessageIDList(std::vector<TSBPOP3MessageID> &OutResult);

		void GetMessageList(std::vector<TSBPOP3MessageSize> &OutResult);

		int64_t GetMessageSize(int32_t Index);

		void Login();

		virtual void Open();

		void Noop();

		void Ping();

		void ReceiveMessage(int32_t Index);

		int32_t ReceiveMessage(int32_t Index, const std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Count);

#ifdef SB_USE_CLASS_TSTREAM
		void ReceiveMessage(int32_t Index, TStream &Stream);

		void ReceiveMessage(int32_t Index, TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELMESSAGE
		int32_t ReceiveMessage(int32_t Index, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions Options, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool ActivatePartHandlers, TElMessage &Message);
#endif /* SB_USE_CLASS_TELMESSAGE */

#ifdef SB_USE_CLASS_TELMESSAGEHEADER
		int32_t ReceiveMessageHeader(int32_t Index, std::string &Charset, bool IgnoreNativeCharset, TElMessageHeader &Header);
#endif /* SB_USE_CLASS_TELMESSAGEHEADER */

		void ReceiveMessageIDList();

		void ReceiveMessageLines(int32_t Index, int32_t LineCount);

		int32_t ReceiveMessageLines(int32_t Index, int32_t LineCount, const std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Count);

#ifdef SB_USE_CLASS_TSTREAM
		void ReceiveMessageLines(int32_t Index, int32_t LineCount, TStream &Stream);

		void ReceiveMessageLines(int32_t Index, int32_t LineCount, TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		void ReceiveMessageList();

		void Reset();

		void Undelete();

		virtual bool get_SASLMechanism(const std::string &Name);

		virtual void set_SASLMechanism(const std::string &Name, bool Value);

		virtual int32_t get_SASLMechanismPriorities(const std::string &Name);

		virtual void set_SASLMechanismPriorities(const std::string &Name, int32_t Value);

		virtual int32_t get_AuthorizationPriorities(TSBPOP3Authorization Auth);

		virtual void set_AuthorizationPriorities(TSBPOP3Authorization Auth, int32_t Value);

		virtual bool get_Authorization(TSBPOP3Authorization Auth);

		virtual void set_Authorization(TSBPOP3Authorization Auth, bool Value);

		virtual bool get_ExtAPOPSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtAPOPSupported, TElPOP3Client, ExtAPOPSupported);

		virtual bool get_ExtUIDLSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtUIDLSupported, TElPOP3Client, ExtUIDLSupported);

		virtual bool get_ExtUSERSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtUSERSupported, TElPOP3Client, ExtUSERSupported);

		virtual bool get_ExtTOPSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtTOPSupported, TElPOP3Client, ExtTOPSupported);

		virtual bool get_ExtRESP_CODESSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtRESP_CODESSupported, TElPOP3Client, ExtRESP_CODESSupported);

		virtual bool get_ExtLOGIN_DELAYSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtLOGIN_DELAYSupported, TElPOP3Client, ExtLOGIN_DELAYSupported);

		virtual bool get_ExtEXPIRESupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtEXPIRESupported, TElPOP3Client, ExtEXPIRESupported);

		virtual bool get_ExtIMPLEMENTATIONSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtIMPLEMENTATIONSupported, TElPOP3Client, ExtIMPLEMENTATIONSupported);

		virtual bool get_ExtSASLSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtSASLSupported, TElPOP3Client, ExtSASLSupported);

		virtual void get_ExtSASLMechanisms(TStringList &OutResult);

		virtual int32_t get_ExtExpire();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ExtExpire, TElPOP3Client, ExtExpire);

		virtual bool get_ExtExpireUserChangeable();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtExpireUserChangeable, TElPOP3Client, ExtExpireUserChangeable);

		virtual int32_t get_ExtLoginDelay();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ExtLoginDelay, TElPOP3Client, ExtLoginDelay);

		virtual void get_ExtImplementation(std::string &OutResult);

		virtual bool get_SSLActive();

		SB_DECLARE_PROPERTY_GET(bool, get_SSLActive, TElPOP3Client, SSLActive);

		virtual void get_Address(std::string &OutResult);

		virtual void set_Address(const std::string &Value);

		virtual TSBPOP3AutoCAPAMode get_AutoCAPA();

		virtual void set_AutoCAPA(TSBPOP3AutoCAPAMode Value);

		SB_DECLARE_PROPERTY(TSBPOP3AutoCAPAMode, get_AutoCAPA, set_AutoCAPA, TElPOP3Client, AutoCAPA);

		virtual int32_t get_MaxLineLength();

		virtual void set_MaxLineLength(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxLineLength, set_MaxLineLength, TElPOP3Client, MaxLineLength);

		virtual int32_t get_Port();

		virtual void set_Port(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Port, set_Port, TElPOP3Client, Port);

		virtual TSBSSLMode get_SSLMode();

		virtual void set_SSLMode(TSBSSLMode Value);

		SB_DECLARE_PROPERTY(TSBSSLMode, get_SSLMode, set_SSLMode, TElPOP3Client, SSLMode);

#ifdef SB_WINDOWS
		virtual bool get_UseIPv6();

		virtual void set_UseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseIPv6, set_UseIPv6, TElPOP3Client, UseIPv6);
#endif

		virtual bool get_UseSSL();

		virtual void set_UseSSL(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseSSL, set_UseSSL, TElPOP3Client, UseSSL);

		virtual void get_Username(std::string &OutResult);

		virtual void set_Username(const std::string &Value);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual void get_OnCapability(TSBPOP3TextLineEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCapability(TSBPOP3TextLineEvent pMethodValue, void * pDataValue);

		virtual void get_OnLog(TSBPOP3LogEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnLog(TSBPOP3LogEvent pMethodValue, void * pDataValue);

		virtual void get_OnMessageLine(TSBPOP3TextLineEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnMessageLine(TSBPOP3TextLineEvent pMethodValue, void * pDataValue);

		virtual void get_OnMessageID(TSBPOP3MessageIdEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnMessageID(TSBPOP3MessageIdEvent pMethodValue, void * pDataValue);

		virtual void get_OnMessageSize(TSBPOP3MessageSizeEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnMessageSize(TSBPOP3MessageSizeEvent pMethodValue, void * pDataValue);

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateChoose(TSBChooseCertificateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateChoose(TSBChooseCertificateEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateNeededEx(TSBCertificateNeededExEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateNeededEx(TSBCertificateNeededExEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateValidate(TSBCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateValidate(TSBCertificateValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnCloseConnection(TSBCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCloseConnection(TSBCloseConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnError(TSBErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnError(TSBErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtensionsReceived(TSBExtensionsReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtensionsReceived(TSBExtensionsReceivedEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtensionsPrepared(TSBExtensionsPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtensionsPrepared(TSBExtensionsPreparedEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateStatus(TSBCertificateStatusEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateStatus(TSBCertificateStatusEvent pMethodValue, void * pDataValue);

		virtual void get_OnKeyNeeded(TSBClientKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyNeeded(TSBClientKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnRenegotiationRequest(TSBRenegotiationRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRenegotiationRequest(TSBRenegotiationRequestEvent pMethodValue, void * pDataValue);

#ifndef SB_WINCE_OR_NOT_WINDOWS
		virtual void get_OnDNSKeyNeeded(TSBDNSKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSKeyNeeded(TSBDNSKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDNSKeyValidate(TSBDNSKeyValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSKeyValidate(TSBDNSKeyValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnDNSResolve(TSBDNSResolveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSResolve(TSBDNSResolveEvent pMethodValue, void * pDataValue);
#endif

		TElPOP3Client(TElPOP3ClientHandle handle, TElOwnHandle ownHandle);

		explicit TElPOP3Client(TComponent &AOwner);

		explicit TElPOP3Client(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELPOP3CLIENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPOP3CLIENT */
