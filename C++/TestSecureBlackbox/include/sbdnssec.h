#ifndef __INC_SBDNSSEC
#define __INC_SBDNSSEC

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbsocket.h"
#include "sbstreams.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbdnssectypes.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElDNSQuestionHandle;

typedef TElClassHandle TElDNSQuestionListHandle;

typedef TElClassHandle TElDNSCacheHandle;

typedef TElClassHandle TElDNSMessageExtensionsHandle;

typedef TElClassHandle TElDNSMessageHandle;

typedef TElClassHandle TElDNSClientHandle;

typedef TElClassHandle TElDNSResolverHandle;

typedef void (SB_CALLBACK *TSBDNSClientSendingEvent)(void * _ObjectData, TObjectHandle Sender, TElDNSMessageHandle Request);

typedef void (SB_CALLBACK *TSBDNSClientTimeoutEvent)(void * _ObjectData, TObjectHandle Sender, int8_t * Wait);

typedef void (SB_CALLBACK *TSBDNSResolverPrepareEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcServerName, int32_t szServerName, const char * pcServerAddress, int32_t szServerAddress, uint16_t ServerPort, const char * pcCriteria, int32_t szCriteria, TSBDNSResourceTypeRaw InfoType);

typedef void (SB_CALLBACK *TSBDNSResolverRequestEvent)(void * _ObjectData, TObjectHandle Sender, TElDNSMessageHandle Request);

typedef void (SB_CALLBACK *TSBDNSResolverResponseEvent)(void * _ObjectData, TObjectHandle Sender, TElDNSMessageHandle Response);

typedef void (SB_CALLBACK *TSBDNSResolverErrorEvent)(void * _ObjectData, TObjectHandle Sender, int32_t ErrorCode, const char * pcErrorMessage, int32_t szErrorMessage);

#ifdef SB_USE_CLASS_TELDNSQUESTION
SB_IMPORT uint32_t SB_APIENTRY TElDNSQuestion_Assign(TElDNSQuestionHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSQuestion_Read(TElDNSQuestionHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, uint16_t * Offset);
SB_IMPORT uint32_t SB_APIENTRY TElDNSQuestion_Write(TElDNSQuestionHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElDNSQuestion_get_Name(TElDNSQuestionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSQuestion_set_Name(TElDNSQuestionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSQuestion_get_ResourceCode(TElDNSQuestionHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSQuestion_set_ResourceCode(TElDNSQuestionHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSQuestion_get_ResourceType(TElDNSQuestionHandle _Handle, TSBDNSResourceTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSQuestion_set_ResourceType(TElDNSQuestionHandle _Handle, TSBDNSResourceTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSQuestion_Create(TElDNSQuestionHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSQUESTION */

#ifdef SB_USE_CLASS_TELDNSQUESTIONLIST
SB_IMPORT uint32_t SB_APIENTRY TElDNSQuestionList_Add(TElDNSQuestionListHandle _Handle, TElDNSQuestionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSQuestionList_Assign(TElDNSQuestionListHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSQuestionList_Clear(TElDNSQuestionListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDNSQuestionList_Delete(TElDNSQuestionListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElDNSQuestionList_IndexOf(TElDNSQuestionListHandle _Handle, TElDNSQuestionHandle Question, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSQuestionList_Insert(TElDNSQuestionListHandle _Handle, int32_t Index, TElDNSQuestionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSQuestionList_Remove(TElDNSQuestionListHandle _Handle, TElDNSQuestionHandle Question, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSQuestionList_get_Count(TElDNSQuestionListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSQuestionList_get_Items(TElDNSQuestionListHandle _Handle, int32_t Index, TElDNSQuestionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSQuestionList_Create(TElDNSQuestionListHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSQUESTIONLIST */

#ifdef SB_USE_CLASS_TELDNSCACHE
SB_IMPORT uint32_t SB_APIENTRY TElDNSCache_Add(TElDNSCacheHandle _Handle, TElDNSResourceRecordSetHandle Records);
SB_IMPORT uint32_t SB_APIENTRY TElDNSCache_Create(TElDNSResourceRecordSetHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSCACHE */

#ifdef SB_USE_CLASS_TELDNSMESSAGEEXTENSIONS
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessageExtensions_Assign(TElDNSMessageExtensionsHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessageExtensions_Clear(TElDNSMessageExtensionsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessageExtensions_get_Enabled(TElDNSMessageExtensionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessageExtensions_set_Enabled(TElDNSMessageExtensionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessageExtensions_get_DNSSECOK(TElDNSMessageExtensionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessageExtensions_set_DNSSECOK(TElDNSMessageExtensionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessageExtensions_get_Flags(TElDNSMessageExtensionsHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessageExtensions_set_Flags(TElDNSMessageExtensionsHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessageExtensions_get_PayloadSize(TElDNSMessageExtensionsHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessageExtensions_set_PayloadSize(TElDNSMessageExtensionsHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessageExtensions_get_ResponseCode(TElDNSMessageExtensionsHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessageExtensions_set_ResponseCode(TElDNSMessageExtensionsHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessageExtensions_get_Version(TElDNSMessageExtensionsHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessageExtensions_set_Version(TElDNSMessageExtensionsHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessageExtensions_Create(TElDNSMessageExtensionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSMESSAGEEXTENSIONS */

#ifdef SB_USE_CLASS_TELDNSMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_Assign(TElDNSMessageHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_Clear(TElDNSMessageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_Read(TElDNSMessageHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_Write(TElDNSMessageHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_get_Authenticated(TElDNSMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_set_Authenticated(TElDNSMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_get_Authoritative(TElDNSMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_set_Authoritative(TElDNSMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_get_CheckingDisabled(TElDNSMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_set_CheckingDisabled(TElDNSMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_get_Extensions(TElDNSMessageHandle _Handle, TElDNSMessageExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_set_Extensions(TElDNSMessageHandle _Handle, TElDNSMessageExtensionsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_get_ID(TElDNSMessageHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_set_ID(TElDNSMessageHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_get_MessageType(TElDNSMessageHandle _Handle, TSBDNSMessageTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_set_MessageType(TElDNSMessageHandle _Handle, TSBDNSMessageTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_get_OpCode(TElDNSMessageHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_set_OpCode(TElDNSMessageHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_get_Operation(TElDNSMessageHandle _Handle, TSBDNSOperationCodeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_set_Operation(TElDNSMessageHandle _Handle, TSBDNSOperationCodeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_get_RCode(TElDNSMessageHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_set_RCode(TElDNSMessageHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_get_RecursionAvailable(TElDNSMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_set_RecursionAvailable(TElDNSMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_get_RecursionDesired(TElDNSMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_set_RecursionDesired(TElDNSMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_get_ResponseCode(TElDNSMessageHandle _Handle, TSBDNSResponseCodeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_set_ResponseCode(TElDNSMessageHandle _Handle, TSBDNSResponseCodeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_get_Truncated(TElDNSMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_set_Truncated(TElDNSMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_get_Z(TElDNSMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_set_Z(TElDNSMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_get_Questions(TElDNSMessageHandle _Handle, TElDNSQuestionListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_set_Questions(TElDNSMessageHandle _Handle, TElDNSQuestionListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_get_Answers(TElDNSMessageHandle _Handle, TElDNSResourceRecordSetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_set_Answers(TElDNSMessageHandle _Handle, TElDNSResourceRecordSetHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_get_Authorities(TElDNSMessageHandle _Handle, TElDNSResourceRecordSetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_set_Authorities(TElDNSMessageHandle _Handle, TElDNSResourceRecordSetHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_get_Additionals(TElDNSMessageHandle _Handle, TElDNSResourceRecordSetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_set_Additionals(TElDNSMessageHandle _Handle, TElDNSResourceRecordSetHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMessage_Create(TElDNSMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSMESSAGE */

#ifdef SB_USE_CLASS_TELDNSCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_Activate(TElDNSClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_Deactivate(TElDNSClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_Lookup(TElDNSClientHandle _Handle, const char * pcName, int32_t szName, TSBDNSResourceTypeRaw ResourceType, TElDNSMessageHandle * Response);
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_Lookup_1(TElDNSClientHandle _Handle, const char * pcName, int32_t szName, uint8_t ResourceCode, TElDNSMessageHandle * Response);
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_get_Active(TElDNSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_get_BoundAddress(TElDNSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_get_BoundPort(TElDNSClientHandle _Handle, uint16_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_get_UsingIPv6(TElDNSClientHandle _Handle, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_get_Address(TElDNSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_set_Address(TElDNSClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_get_Binding(TElDNSClientHandle _Handle, TElClientSocketBindingHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_set_Binding(TElDNSClientHandle _Handle, TElClientSocketBindingHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_get_Port(TElDNSClientHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_set_Port(TElDNSClientHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_get_Timeout(TElDNSClientHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_set_Timeout(TElDNSClientHandle _Handle, uint16_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_get_UseIPv6(TElDNSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_set_UseIPv6(TElDNSClientHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_get_UseRecursion(TElDNSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_set_UseRecursion(TElDNSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_get_UseSecurity(TElDNSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_set_UseSecurity(TElDNSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_get_OnSending(TElDNSClientHandle _Handle, TSBDNSClientSendingEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_set_OnSending(TElDNSClientHandle _Handle, TSBDNSClientSendingEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_get_OnTimeout(TElDNSClientHandle _Handle, TSBDNSClientTimeoutEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_set_OnTimeout(TElDNSClientHandle _Handle, TSBDNSClientTimeoutEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSClient_Create(TComponentHandle AOwner, TElDNSClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSCLIENT */

#ifdef SB_USE_CLASS_TELDNSRESOLVER
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_Assign(TElDNSResolverHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_Lookup(TElDNSResolverHandle _Handle, const char * pcCriteria, int32_t szCriteria, TSBDNSResourceTypeRaw InfoType, TElDNSResourceRecordSetHandle FoundInfo, TSBDNSSecurityStatusRaw * SecurityStatus, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_get_Port(TElDNSResolverHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_set_Port(TElDNSResolverHandle _Handle, uint16_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_get_Servers(TElDNSResolverHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_set_Servers(TElDNSResolverHandle _Handle, TStringListHandle Value);
#else
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_get_Servers(TElDNSResolverHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_set_Servers(TElDNSResolverHandle _Handle, TElStringListHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_get_QueryTimeout(TElDNSResolverHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_set_QueryTimeout(TElDNSResolverHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_get_TotalTimeout(TElDNSResolverHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_set_TotalTimeout(TElDNSResolverHandle _Handle, uint16_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_get_UseIPv6(TElDNSResolverHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_set_UseIPv6(TElDNSResolverHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_get_UseSecurity(TElDNSResolverHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_set_UseSecurity(TElDNSResolverHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_get_OnError(TElDNSResolverHandle _Handle, TSBDNSResolverErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_set_OnError(TElDNSResolverHandle _Handle, TSBDNSResolverErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_get_OnKeyNeeded(TElDNSResolverHandle _Handle, TSBDNSKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_set_OnKeyNeeded(TElDNSResolverHandle _Handle, TSBDNSKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_get_OnKeyValidate(TElDNSResolverHandle _Handle, TSBDNSKeyValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_set_OnKeyValidate(TElDNSResolverHandle _Handle, TSBDNSKeyValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_get_OnPrepare(TElDNSResolverHandle _Handle, TSBDNSResolverPrepareEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_set_OnPrepare(TElDNSResolverHandle _Handle, TSBDNSResolverPrepareEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_get_OnRequest(TElDNSResolverHandle _Handle, TSBDNSResolverRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_set_OnRequest(TElDNSResolverHandle _Handle, TSBDNSResolverRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_get_OnResponse(TElDNSResolverHandle _Handle, TSBDNSResolverResponseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_set_OnResponse(TElDNSResolverHandle _Handle, TSBDNSResolverResponseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResolver_Create(TComponentHandle AOwner, TElDNSResolverHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSRESOLVER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElDNSQuestion;
class TElDNSQuestionList;
class TElDNSCache;
class TElDNSMessageExtensions;
class TElDNSMessage;
class TElDNSClient;
class TElDNSResolver;

#ifdef SB_USE_CLASS_TELDNSQUESTION
class TElDNSQuestion: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElDNSQuestion)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset);

#ifdef SB_USE_CLASS_TSTREAM
		virtual void Write(TStream &Stream);

		virtual void Write(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		virtual uint16_t get_ResourceCode();

		virtual void set_ResourceCode(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_ResourceCode, set_ResourceCode, TElDNSQuestion, ResourceCode);

		virtual TSBDNSResourceType get_ResourceType();

		virtual void set_ResourceType(TSBDNSResourceType Value);

		SB_DECLARE_PROPERTY(TSBDNSResourceType, get_ResourceType, set_ResourceType, TElDNSQuestion, ResourceType);

		TElDNSQuestion(TElDNSQuestionHandle handle, TElOwnHandle ownHandle);

		TElDNSQuestion();

};
#endif /* SB_USE_CLASS_TELDNSQUESTION */

#ifdef SB_USE_CLASS_TELDNSQUESTIONLIST
class TElDNSQuestionList: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElDNSQuestionList)
#ifdef SB_USE_CLASS_TELDNSQUESTION
		TElDNSQuestion* _Inst_Items;
#endif /* SB_USE_CLASS_TELDNSQUESTION */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELDNSQUESTION
		TElDNSQuestionHandle Add();
#endif /* SB_USE_CLASS_TELDNSQUESTION */

		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		void Clear();

		void Delete(int32_t Index);

#ifdef SB_USE_CLASS_TELDNSQUESTION
		int32_t IndexOf(TElDNSQuestion &Question);

		int32_t IndexOf(TElDNSQuestion *Question);
#endif /* SB_USE_CLASS_TELDNSQUESTION */

#ifdef SB_USE_CLASS_TELDNSQUESTION
		TElDNSQuestionHandle Insert(int32_t Index);
#endif /* SB_USE_CLASS_TELDNSQUESTION */

#ifdef SB_USE_CLASS_TELDNSQUESTION
		int32_t Remove(TElDNSQuestion &Question);

		int32_t Remove(TElDNSQuestion *Question);
#endif /* SB_USE_CLASS_TELDNSQUESTION */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElDNSQuestionList, Count);

#ifdef SB_USE_CLASS_TELDNSQUESTION
		virtual TElDNSQuestion* get_Items(int32_t Index);
#endif /* SB_USE_CLASS_TELDNSQUESTION */

		TElDNSQuestionList(TElDNSQuestionListHandle handle, TElOwnHandle ownHandle);

		TElDNSQuestionList();

		virtual ~TElDNSQuestionList();

};
#endif /* SB_USE_CLASS_TELDNSQUESTIONLIST */

#ifdef SB_USE_CLASS_TELDNSCACHE
class TElDNSCache: public TElDNSResourceRecordSet
{
	private:
		SB_DISABLE_COPY(TElDNSCache)
	public:
		void Add(TElDNSResourceRecordSet &Records);

		void Add(TElDNSResourceRecordSet *Records);

		TElDNSCache(TElDNSCacheHandle handle, TElOwnHandle ownHandle);

		TElDNSCache();

};
#endif /* SB_USE_CLASS_TELDNSCACHE */

#ifdef SB_USE_CLASS_TELDNSMESSAGEEXTENSIONS
class TElDNSMessageExtensions: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElDNSMessageExtensions)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Clear();

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElDNSMessageExtensions, Enabled);

		virtual bool get_DNSSECOK();

		virtual void set_DNSSECOK(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DNSSECOK, set_DNSSECOK, TElDNSMessageExtensions, DNSSECOK);

		virtual uint16_t get_Flags();

		virtual void set_Flags(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_Flags, set_Flags, TElDNSMessageExtensions, Flags);

		virtual uint16_t get_PayloadSize();

		virtual void set_PayloadSize(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_PayloadSize, set_PayloadSize, TElDNSMessageExtensions, PayloadSize);

		virtual uint16_t get_ResponseCode();

		virtual void set_ResponseCode(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_ResponseCode, set_ResponseCode, TElDNSMessageExtensions, ResponseCode);

		virtual uint8_t get_Version();

		virtual void set_Version(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_Version, set_Version, TElDNSMessageExtensions, Version);

		TElDNSMessageExtensions(TElDNSMessageExtensionsHandle handle, TElOwnHandle ownHandle);

		TElDNSMessageExtensions();

};
#endif /* SB_USE_CLASS_TELDNSMESSAGEEXTENSIONS */

#ifdef SB_USE_CLASS_TELDNSMESSAGE
class TElDNSMessage: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElDNSMessage)
#ifdef SB_USE_CLASS_TELDNSMESSAGEEXTENSIONS
		TElDNSMessageExtensions* _Inst_Extensions;
#endif /* SB_USE_CLASS_TELDNSMESSAGEEXTENSIONS */
#ifdef SB_USE_CLASS_TELDNSQUESTIONLIST
		TElDNSQuestionList* _Inst_Questions;
#endif /* SB_USE_CLASS_TELDNSQUESTIONLIST */
#ifdef SB_USE_CLASS_TELDNSRESOURCERECORDSET
		TElDNSResourceRecordSet* _Inst_Answers;
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORDSET */
#ifdef SB_USE_CLASS_TELDNSRESOURCERECORDSET
		TElDNSResourceRecordSet* _Inst_Authorities;
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORDSET */
#ifdef SB_USE_CLASS_TELDNSRESOURCERECORDSET
		TElDNSResourceRecordSet* _Inst_Additionals;
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORDSET */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Clear();

		virtual void Read(const std::vector<uint8_t> &Buffer);

#ifdef SB_USE_CLASS_TSTREAM
		virtual void Write(TStream &Stream);

		virtual void Write(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual bool get_Authenticated();

		virtual void set_Authenticated(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Authenticated, set_Authenticated, TElDNSMessage, Authenticated);

		virtual bool get_Authoritative();

		virtual void set_Authoritative(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Authoritative, set_Authoritative, TElDNSMessage, Authoritative);

		virtual bool get_CheckingDisabled();

		virtual void set_CheckingDisabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CheckingDisabled, set_CheckingDisabled, TElDNSMessage, CheckingDisabled);

#ifdef SB_USE_CLASS_TELDNSMESSAGEEXTENSIONS
		virtual TElDNSMessageExtensions* get_Extensions();

		virtual void set_Extensions(TElDNSMessageExtensions &Value);

		virtual void set_Extensions(TElDNSMessageExtensions *Value);

		SB_DECLARE_PROPERTY(TElDNSMessageExtensions*, get_Extensions, set_Extensions, TElDNSMessage, Extensions);
#endif /* SB_USE_CLASS_TELDNSMESSAGEEXTENSIONS */

		virtual uint16_t get_ID();

		virtual void set_ID(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_ID, set_ID, TElDNSMessage, ID);

		virtual TSBDNSMessageType get_MessageType();

		virtual void set_MessageType(TSBDNSMessageType Value);

		SB_DECLARE_PROPERTY(TSBDNSMessageType, get_MessageType, set_MessageType, TElDNSMessage, MessageType);

		virtual uint8_t get_OpCode();

		virtual void set_OpCode(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_OpCode, set_OpCode, TElDNSMessage, OpCode);

		virtual TSBDNSOperationCode get_Operation();

		virtual void set_Operation(TSBDNSOperationCode Value);

		SB_DECLARE_PROPERTY(TSBDNSOperationCode, get_Operation, set_Operation, TElDNSMessage, Operation);

		virtual uint16_t get_RCode();

		virtual void set_RCode(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_RCode, set_RCode, TElDNSMessage, RCode);

		virtual bool get_RecursionAvailable();

		virtual void set_RecursionAvailable(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RecursionAvailable, set_RecursionAvailable, TElDNSMessage, RecursionAvailable);

		virtual bool get_RecursionDesired();

		virtual void set_RecursionDesired(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RecursionDesired, set_RecursionDesired, TElDNSMessage, RecursionDesired);

		virtual TSBDNSResponseCode get_ResponseCode();

		virtual void set_ResponseCode(TSBDNSResponseCode Value);

		SB_DECLARE_PROPERTY(TSBDNSResponseCode, get_ResponseCode, set_ResponseCode, TElDNSMessage, ResponseCode);

		virtual bool get_Truncated();

		virtual void set_Truncated(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Truncated, set_Truncated, TElDNSMessage, Truncated);

		virtual bool get_Z();

		virtual void set_Z(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Z, set_Z, TElDNSMessage, Z);

#ifdef SB_USE_CLASS_TELDNSQUESTIONLIST
		virtual TElDNSQuestionList* get_Questions();

		virtual void set_Questions(TElDNSQuestionList &Value);

		virtual void set_Questions(TElDNSQuestionList *Value);

		SB_DECLARE_PROPERTY(TElDNSQuestionList*, get_Questions, set_Questions, TElDNSMessage, Questions);
#endif /* SB_USE_CLASS_TELDNSQUESTIONLIST */

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORDSET
		virtual TElDNSResourceRecordSet* get_Answers();

		virtual void set_Answers(TElDNSResourceRecordSet &Value);

		virtual void set_Answers(TElDNSResourceRecordSet *Value);

		SB_DECLARE_PROPERTY(TElDNSResourceRecordSet*, get_Answers, set_Answers, TElDNSMessage, Answers);
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORDSET */

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORDSET
		virtual TElDNSResourceRecordSet* get_Authorities();

		virtual void set_Authorities(TElDNSResourceRecordSet &Value);

		virtual void set_Authorities(TElDNSResourceRecordSet *Value);

		SB_DECLARE_PROPERTY(TElDNSResourceRecordSet*, get_Authorities, set_Authorities, TElDNSMessage, Authorities);
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORDSET */

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORDSET
		virtual TElDNSResourceRecordSet* get_Additionals();

		virtual void set_Additionals(TElDNSResourceRecordSet &Value);

		virtual void set_Additionals(TElDNSResourceRecordSet *Value);

		SB_DECLARE_PROPERTY(TElDNSResourceRecordSet*, get_Additionals, set_Additionals, TElDNSMessage, Additionals);
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORDSET */

		TElDNSMessage(TElDNSMessageHandle handle, TElOwnHandle ownHandle);

		TElDNSMessage();

		virtual ~TElDNSMessage();

};
#endif /* SB_USE_CLASS_TELDNSMESSAGE */

#ifdef SB_USE_CLASS_TELDNSCLIENT
class TElDNSClient: public TComponent
{
	private:
		SB_DISABLE_COPY(TElDNSClient)
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		TElClientSocketBinding* _Inst_Binding;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

		void initInstances();

	public:
		void Activate();

		void Deactivate();

#ifdef SB_USE_CLASS_TELDNSMESSAGE
		void Lookup(const std::string &Name, TSBDNSResourceType ResourceType, TElDNSMessage &Response);
#endif /* SB_USE_CLASS_TELDNSMESSAGE */

#ifdef SB_USE_CLASS_TELDNSMESSAGE
		void Lookup(const std::string &Name, uint8_t ResourceCode, TElDNSMessage &Response);
#endif /* SB_USE_CLASS_TELDNSMESSAGE */

		virtual bool get_Active();

		SB_DECLARE_PROPERTY_GET(bool, get_Active, TElDNSClient, Active);

		virtual void get_BoundAddress(std::string &OutResult);

		virtual uint16_t get_BoundPort();

		SB_DECLARE_PROPERTY_GET(uint16_t, get_BoundPort, TElDNSClient, BoundPort);

#ifdef SB_WINDOWS
		virtual bool get_UsingIPv6();

		SB_DECLARE_PROPERTY_GET(bool, get_UsingIPv6, TElDNSClient, UsingIPv6);
#endif

		virtual void get_Address(std::string &OutResult);

		virtual void set_Address(const std::string &Value);

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		virtual TElClientSocketBinding* get_Binding();

		virtual void set_Binding(TElClientSocketBinding &Value);

		virtual void set_Binding(TElClientSocketBinding *Value);

		SB_DECLARE_PROPERTY(TElClientSocketBinding*, get_Binding, set_Binding, TElDNSClient, Binding);
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

		virtual uint16_t get_Port();

		virtual void set_Port(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_Port, set_Port, TElDNSClient, Port);

		virtual uint16_t get_Timeout();

		virtual void set_Timeout(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_Timeout, set_Timeout, TElDNSClient, Timeout);

#ifdef SB_WINDOWS
		virtual bool get_UseIPv6();

		virtual void set_UseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseIPv6, set_UseIPv6, TElDNSClient, UseIPv6);
#endif

		virtual bool get_UseRecursion();

		virtual void set_UseRecursion(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseRecursion, set_UseRecursion, TElDNSClient, UseRecursion);

		virtual bool get_UseSecurity();

		virtual void set_UseSecurity(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseSecurity, set_UseSecurity, TElDNSClient, UseSecurity);

		virtual void get_OnSending(TSBDNSClientSendingEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSending(TSBDNSClientSendingEvent pMethodValue, void * pDataValue);

		virtual void get_OnTimeout(TSBDNSClientTimeoutEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTimeout(TSBDNSClientTimeoutEvent pMethodValue, void * pDataValue);

		TElDNSClient(TElDNSClientHandle handle, TElOwnHandle ownHandle);

		explicit TElDNSClient(TComponent &AOwner);

		explicit TElDNSClient(TComponent *AOwner);

		virtual ~TElDNSClient();

};
#endif /* SB_USE_CLASS_TELDNSCLIENT */

#ifdef SB_USE_CLASS_TELDNSRESOLVER
class TElDNSResolver: public TComponent
{
	private:
		SB_DISABLE_COPY(TElDNSResolver)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Servers;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Servers;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORDSET
		int32_t Lookup(const std::string &Criteria, TSBDNSResourceType InfoType, TElDNSResourceRecordSet &FoundInfo, TSBDNSSecurityStatus &SecurityStatus);

		int32_t Lookup(const std::string &Criteria, TSBDNSResourceType InfoType, TElDNSResourceRecordSet *FoundInfo, TSBDNSSecurityStatus &SecurityStatus);
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORDSET */

		virtual uint16_t get_Port();

		virtual void set_Port(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_Port, set_Port, TElDNSResolver, Port);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Servers();

		virtual void set_Servers(TStringList &Value);

		virtual void set_Servers(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_Servers, set_Servers, TElDNSResolver, Servers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Servers();

		virtual void set_Servers(TElStringList &Value);

		virtual void set_Servers(TElStringList *Value);

		SB_DECLARE_PROPERTY(TElStringList*, get_Servers, set_Servers, TElDNSResolver, Servers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual uint16_t get_QueryTimeout();

		virtual void set_QueryTimeout(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_QueryTimeout, set_QueryTimeout, TElDNSResolver, QueryTimeout);

		virtual uint16_t get_TotalTimeout();

		virtual void set_TotalTimeout(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_TotalTimeout, set_TotalTimeout, TElDNSResolver, TotalTimeout);

#ifdef SB_WINDOWS
		virtual bool get_UseIPv6();

		virtual void set_UseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseIPv6, set_UseIPv6, TElDNSResolver, UseIPv6);
#endif

		virtual bool get_UseSecurity();

		virtual void set_UseSecurity(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseSecurity, set_UseSecurity, TElDNSResolver, UseSecurity);

		virtual void get_OnError(TSBDNSResolverErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnError(TSBDNSResolverErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnKeyNeeded(TSBDNSKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyNeeded(TSBDNSKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnKeyValidate(TSBDNSKeyValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyValidate(TSBDNSKeyValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnPrepare(TSBDNSResolverPrepareEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPrepare(TSBDNSResolverPrepareEvent pMethodValue, void * pDataValue);

		virtual void get_OnRequest(TSBDNSResolverRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRequest(TSBDNSResolverRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnResponse(TSBDNSResolverResponseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnResponse(TSBDNSResolverResponseEvent pMethodValue, void * pDataValue);

		TElDNSResolver(TElDNSResolverHandle handle, TElOwnHandle ownHandle);

		explicit TElDNSResolver(TComponent &AOwner);

		explicit TElDNSResolver(TComponent *AOwner);

		virtual ~TElDNSResolver();

};
#endif /* SB_USE_CLASS_TELDNSRESOLVER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBDNSSEC */
