#ifndef __INC_SBDC
#define __INC_SBDC

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbdcenc.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbrdn.h"
#include "sbencoding.h"
#include "sbstreams.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ERROR_FACILITY_DC 	131072
#define SB_DC_ERROR_BAD_ASYNC_STATE 	131073
#define SB_DC_ERROR_BAD_ASYNC_DATA 	131074
#define SB_DC_ERROR_REMOTE_ERROR 	131075
#define SB_DC_ERROR_DC_MODULE_UNAVAILABLE 	131076
#define SB_AST_STANDARD 	"standard"
#define SB_ASST_PKCS1SIG 	"pkcs1sig"
#define SB_ASST_PKCS7SIG 	"pkcs7sig"

typedef TElClassHandle TElDCBaseMessageHandle;

typedef TElClassHandle TElDCUnsupportedMessageHandle;

typedef TElClassHandle TElDCErrorMessageHandle;

typedef TElClassHandle TElDCOperationRequestMessageHandle;

typedef TElClassHandle TElDCOperationResponseMessageHandle;

typedef TElClassHandle TElDCBatchMessageHandle;

typedef TElClassHandle TElDCMessageFactoryHandle;

typedef TElClassHandle TElDCAsyncStateHandle;

typedef TElClassHandle TElDCAsyncStateCollectionHandle;

typedef TElClassHandle TElDCMessageClassHandle;

typedef uint8_t TSBDCOperationRaw;

typedef enum
{
	dcUnknown = 0,
	dcRawSign = 1,
	dcPKCS7Sign = 2
} TSBDCOperation;

typedef uint8_t TSBDCAsyncSignMethodRaw;

typedef enum
{
	asmPKCS1 = 0,
	asmPKCS7 = 1
} TSBDCAsyncSignMethod;

#ifdef SB_USE_CLASS_TELDCBASEMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElDCBaseMessage_Assign(TElDCBaseMessageHandle _Handle, TElDCBaseMessageHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDCBaseMessage_InitializeMessage(TElDCBaseMessageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDCBaseMessage_Clone(TElDCBaseMessageHandle _Handle, TElDCBaseMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCBaseMessage_Clone_1(TElDCBaseMessageHandle _Handle, int8_t RenegerateID, TElDCBaseMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCBaseMessage_SaveToNode(TElDCBaseMessageHandle _Handle, TElDCNodeHandle Node);
SB_IMPORT uint32_t SB_APIENTRY TElDCBaseMessage_LoadFromNode(TElDCBaseMessageHandle _Handle, TElDCNodeHandle Node);
SB_IMPORT uint32_t SB_APIENTRY TElDCBaseMessage_SaveToStream(TElDCBaseMessageHandle _Handle, TStreamHandle Stream, TElDCEncodingHandle Encoding, const char * pcRootNodeName, int32_t szRootNodeName);
SB_IMPORT uint32_t SB_APIENTRY TElDCBaseMessage_LoadFromStream(TElDCBaseMessageHandle _Handle, TStreamHandle Stream, TElDCEncodingHandle Encoding, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElDCBaseMessage_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCBaseMessage_get_ID(TElDCBaseMessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCBaseMessage_set_ID(TElDCBaseMessageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDCBaseMessage_get_Name(TElDCBaseMessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCBaseMessage_set_Name(TElDCBaseMessageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDCBaseMessage_get_Pars(TElDCBaseMessageHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCBaseMessage_get_OriginalMessage(TElDCBaseMessageHandle _Handle, TElDCBaseMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCBaseMessage_Create(TElDCBaseMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCBaseMessage_Create_1(TElDCBaseMessageHandle OrigMessage, TElDCBaseMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELDCBASEMESSAGE */

#ifdef SB_USE_CLASS_TELDCUNSUPPORTEDMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElDCUnsupportedMessage_Assign(TElDCUnsupportedMessageHandle _Handle, TElDCBaseMessageHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDCUnsupportedMessage_Clone(TElDCUnsupportedMessageHandle _Handle, TElDCBaseMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCUnsupportedMessage_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCUnsupportedMessage_Create(TElDCUnsupportedMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELDCUNSUPPORTEDMESSAGE */

#ifdef SB_USE_CLASS_TELDCERRORMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElDCErrorMessage_Assign(TElDCErrorMessageHandle _Handle, TElDCBaseMessageHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDCErrorMessage_Clone(TElDCErrorMessageHandle _Handle, TElDCBaseMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCErrorMessage_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCErrorMessage_get_Code(TElDCErrorMessageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCErrorMessage_set_Code(TElDCErrorMessageHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDCErrorMessage_get_ErrorMessage(TElDCErrorMessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCErrorMessage_set_ErrorMessage(TElDCErrorMessageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDCErrorMessage_Create(TElDCErrorMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELDCERRORMESSAGE */

#ifdef SB_USE_CLASS_TELDCOPERATIONREQUESTMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationRequestMessage_Assign(TElDCOperationRequestMessageHandle _Handle, TElDCBaseMessageHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationRequestMessage_Clone(TElDCOperationRequestMessageHandle _Handle, TElDCBaseMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationRequestMessage_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationRequestMessage_get_Operation(TElDCOperationRequestMessageHandle _Handle, TSBDCOperationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationRequestMessage_set_Operation(TElDCOperationRequestMessageHandle _Handle, TSBDCOperationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationRequestMessage_get_OperationID(TElDCOperationRequestMessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationRequestMessage_set_OperationID(TElDCOperationRequestMessageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationRequestMessage_get_Source(TElDCOperationRequestMessageHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationRequestMessage_set_Source(TElDCOperationRequestMessageHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationRequestMessage_get_HashAlgorithm(TElDCOperationRequestMessageHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationRequestMessage_set_HashAlgorithm(TElDCOperationRequestMessageHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationRequestMessage_get_IncludeKeysInResponse(TElDCOperationRequestMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationRequestMessage_set_IncludeKeysInResponse(TElDCOperationRequestMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationRequestMessage_Create(TElDCOperationRequestMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELDCOPERATIONREQUESTMESSAGE */

#ifdef SB_USE_CLASS_TELDCOPERATIONRESPONSEMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationResponseMessage_InitializeMessage(TElDCOperationResponseMessageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationResponseMessage_Assign(TElDCOperationResponseMessageHandle _Handle, TElDCBaseMessageHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationResponseMessage_Clone(TElDCOperationResponseMessageHandle _Handle, TElDCBaseMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationResponseMessage_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationResponseMessage_get_Operation(TElDCOperationResponseMessageHandle _Handle, TSBDCOperationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationResponseMessage_set_Operation(TElDCOperationResponseMessageHandle _Handle, TSBDCOperationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationResponseMessage_get_OperationResult(TElDCOperationResponseMessageHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationResponseMessage_set_OperationResult(TElDCOperationResponseMessageHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationResponseMessage_get_KeysRDN(TElDCOperationResponseMessageHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationResponseMessage_Create(TElDCBaseMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationResponseMessage_Create_1(TElDCBaseMessageHandle OrigMessage, TElDCBaseMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELDCOPERATIONRESPONSEMESSAGE */

#ifdef SB_USE_CLASS_TELDCBATCHMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElDCBatchMessage_Assign(TElDCBatchMessageHandle _Handle, TElDCBaseMessageHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDCBatchMessage_Clone(TElDCBatchMessageHandle _Handle, TElDCBaseMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCBatchMessage_Add(TElDCBatchMessageHandle _Handle, TElDCBaseMessageHandle Message, int8_t CreateCopy, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCBatchMessage_Remove(TElDCBatchMessageHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElDCBatchMessage_Clear(TElDCBatchMessageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDCBatchMessage_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCBatchMessage_get_Messages(TElDCBatchMessageHandle _Handle, int32_t Index, TElDCBaseMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCBatchMessage_get_Count(TElDCBatchMessageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCBatchMessage_Create(TElDCBatchMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELDCBATCHMESSAGE */

#ifdef SB_USE_CLASS_TELDCMESSAGEFACTORY
SB_IMPORT uint32_t SB_APIENTRY TElDCMessageFactory_CreateInstance(TElDCMessageFactoryHandle _Handle, TStreamHandle Stream, TElDCEncodingHandle Encoding, TElDCBaseMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCMessageFactory_CreateInstance_1(TElDCMessageFactoryHandle _Handle, TElDCNodeHandle Node, TElDCBaseMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCMessageFactory_RegisterClass(TElDCMessageFactoryHandle _Handle, TElDCMessageClassHandle Cls);
SB_IMPORT uint32_t SB_APIENTRY TElDCMessageFactory_Create(TElDCMessageFactoryHandle * OutResult);
#endif /* SB_USE_CLASS_TELDCMESSAGEFACTORY */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncState_Clone(TElDCAsyncStateHandle _Handle, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncState_SaveToNode(TElDCAsyncStateHandle _Handle, TElDCNodeHandle Node);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncState_SaveToStream(TElDCAsyncStateHandle _Handle, TStreamHandle Stream, TElDCEncodingHandle Encoding);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncState_LoadFromNode(TElDCAsyncStateHandle _Handle, TElDCNodeHandle Node);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncState_LoadFromStream(TElDCAsyncStateHandle _Handle, TStreamHandle Stream, TElDCEncodingHandle Encoding);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncState_SubtypePresent(TElDCAsyncStateHandle _Handle, const char * pcSubtype, int32_t szSubtype, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncState_FindMessageByType(TElDCAsyncStateHandle _Handle, TElDCMessageClassHandle MsgType, TElDCBaseMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncState_FindMessageByName(TElDCAsyncStateHandle _Handle, const char * pcName, int32_t szName, TElDCBaseMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncState_get_Messages(TElDCAsyncStateHandle _Handle, TElDCBatchMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncState_get_StateType(TElDCAsyncStateHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncState_set_StateType(TElDCAsyncStateHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncState_get_StateSubtypes(TElDCAsyncStateHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncState_get_StateSubtypes(TElDCAsyncStateHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncState_get_UserData(TElDCAsyncStateHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncState_set_UserData(TElDCAsyncStateHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncState_get_Generator(TElDCAsyncStateHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncState_get_InnerState(TElDCAsyncStateHandle _Handle, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncState_Create(TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncState_Create_1(TElDCAsyncStateHandle InnerState, int8_t ReleaseOnDestruction, TElDCAsyncStateHandle * OutResult);
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASS_TELDCASYNCSTATECOLLECTION
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncStateCollection_Add(TElDCAsyncStateCollectionHandle _Handle, TElDCAsyncStateHandle State, int8_t Clone, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncStateCollection_Remove(TElDCAsyncStateCollectionHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncStateCollection_Clear(TElDCAsyncStateCollectionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncStateCollection_FindState(TElDCAsyncStateCollectionHandle _Handle, const uint8_t pUserData[], int32_t szUserData, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncStateCollection_SaveToNode(TElDCAsyncStateCollectionHandle _Handle, TElDCNodeHandle Node);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncStateCollection_SaveToStream(TElDCAsyncStateCollectionHandle _Handle, TStreamHandle Stream, TElDCEncodingHandle Encoding);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncStateCollection_LoadFromNode(TElDCAsyncStateCollectionHandle _Handle, TElDCNodeHandle Node);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncStateCollection_LoadFromStream(TElDCAsyncStateCollectionHandle _Handle, TStreamHandle Stream, TElDCEncodingHandle Encoding);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncStateCollection_get_UserData(TElDCAsyncStateCollectionHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncStateCollection_set_UserData(TElDCAsyncStateCollectionHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncStateCollection_get_States(TElDCAsyncStateCollectionHandle _Handle, int32_t Index, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncStateCollection_get_Count(TElDCAsyncStateCollectionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCAsyncStateCollection_Create(int8_t OwnsObjects, TElDCAsyncStateCollectionHandle * OutResult);
#endif /* SB_USE_CLASS_TELDCASYNCSTATECOLLECTION */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElDCBaseMessage;
class TElDCUnsupportedMessage;
class TElDCErrorMessage;
class TElDCOperationRequestMessage;
class TElDCOperationResponseMessage;
class TElDCBatchMessage;
class TElDCMessageFactory;
class TElDCAsyncState;
class TElDCAsyncStateCollection;

#ifdef SB_USE_CLASS_TELDCBASEMESSAGE
class TElDCBaseMessage: public TObject
{
	private:
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_Pars;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
		TElDCBaseMessage* _Inst_OriginalMessage;

		void initInstances();

	public:
		virtual void Assign(TElDCBaseMessage &Source);

		virtual void Assign(TElDCBaseMessage *Source);

		virtual void InitializeMessage();

		virtual TElDCBaseMessageHandle Clone();

		TElDCBaseMessageHandle Clone(bool RenegerateID);

#ifdef SB_USE_CLASS_TELDCNODE
		void SaveToNode(TElDCNode &Node);

		void SaveToNode(TElDCNode *Node);
#endif /* SB_USE_CLASS_TELDCNODE */

#ifdef SB_USE_CLASS_TELDCNODE
		void LoadFromNode(TElDCNode &Node);

		void LoadFromNode(TElDCNode *Node);
#endif /* SB_USE_CLASS_TELDCNODE */

#ifdef SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM
		void SaveToStream(TStream &Stream, TElDCEncoding &Encoding, const std::string &RootNodeName);

		void SaveToStream(TStream *Stream, TElDCEncoding *Encoding, const std::string &RootNodeName);
#endif /* SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM
		void LoadFromStream(TStream &Stream, TElDCEncoding &Encoding, int32_t Count);

		void LoadFromStream(TStream *Stream, TElDCEncoding *Encoding, int32_t Count);
#endif /* SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM */

		static TClassHandle ClassType();

		virtual void get_ID(std::string &OutResult);

		virtual void set_ID(const std::string &Value);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_Pars();

		SB_DECLARE_PROPERTY_GET(TElRelativeDistinguishedName*, get_Pars, TElDCBaseMessage, Pars);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual TElDCBaseMessage* get_OriginalMessage();

		SB_DECLARE_PROPERTY_GET(TElDCBaseMessage*, get_OriginalMessage, TElDCBaseMessage, OriginalMessage);

		TElDCBaseMessage(TElDCBaseMessageHandle handle, TElOwnHandle ownHandle);

		TElDCBaseMessage();

		explicit TElDCBaseMessage(TElDCBaseMessage &OrigMessage);

		explicit TElDCBaseMessage(TElDCBaseMessage *OrigMessage);

		virtual ~TElDCBaseMessage();

};
#endif /* SB_USE_CLASS_TELDCBASEMESSAGE */

#ifdef SB_USE_CLASS_TELDCUNSUPPORTEDMESSAGE
class TElDCUnsupportedMessage: public TElDCBaseMessage
{
	private:
		SB_DISABLE_COPY(TElDCUnsupportedMessage)
	public:
		virtual void Assign(TElDCBaseMessage &Source);

		virtual void Assign(TElDCBaseMessage *Source);

		virtual TElDCBaseMessageHandle Clone();

		static TClassHandle ClassType();

		TElDCUnsupportedMessage(TElDCUnsupportedMessageHandle handle, TElOwnHandle ownHandle);

		TElDCUnsupportedMessage();

};
#endif /* SB_USE_CLASS_TELDCUNSUPPORTEDMESSAGE */

#ifdef SB_USE_CLASS_TELDCERRORMESSAGE
class TElDCErrorMessage: public TElDCBaseMessage
{
	private:
		SB_DISABLE_COPY(TElDCErrorMessage)
	public:
		virtual void Assign(TElDCBaseMessage &Source);

		virtual void Assign(TElDCBaseMessage *Source);

		virtual TElDCBaseMessageHandle Clone();

		static TClassHandle ClassType();

		virtual int32_t get_Code();

		virtual void set_Code(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Code, set_Code, TElDCErrorMessage, Code);

		virtual void get_ErrorMessage(std::string &OutResult);

		virtual void set_ErrorMessage(const std::string &Value);

		TElDCErrorMessage(TElDCErrorMessageHandle handle, TElOwnHandle ownHandle);

		TElDCErrorMessage();

};
#endif /* SB_USE_CLASS_TELDCERRORMESSAGE */

#ifdef SB_USE_CLASS_TELDCOPERATIONREQUESTMESSAGE
class TElDCOperationRequestMessage: public TElDCBaseMessage
{
	private:
		SB_DISABLE_COPY(TElDCOperationRequestMessage)
	public:
		virtual void Assign(TElDCBaseMessage &Source);

		virtual void Assign(TElDCBaseMessage *Source);

		virtual TElDCBaseMessageHandle Clone();

		static TClassHandle ClassType();

		virtual TSBDCOperation get_Operation();

		virtual void set_Operation(TSBDCOperation Value);

		SB_DECLARE_PROPERTY(TSBDCOperation, get_Operation, set_Operation, TElDCOperationRequestMessage, Operation);

		virtual void get_OperationID(std::string &OutResult);

		virtual void set_OperationID(const std::string &Value);

		virtual void get_Source(std::vector<uint8_t> &OutResult);

		virtual void set_Source(const std::vector<uint8_t> &Value);

		virtual void get_HashAlgorithm(std::vector<uint8_t> &OutResult);

		virtual void set_HashAlgorithm(const std::vector<uint8_t> &Value);

		virtual bool get_IncludeKeysInResponse();

		virtual void set_IncludeKeysInResponse(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeKeysInResponse, set_IncludeKeysInResponse, TElDCOperationRequestMessage, IncludeKeysInResponse);

		TElDCOperationRequestMessage(TElDCOperationRequestMessageHandle handle, TElOwnHandle ownHandle);

		TElDCOperationRequestMessage();

};
#endif /* SB_USE_CLASS_TELDCOPERATIONREQUESTMESSAGE */

#ifdef SB_USE_CLASS_TELDCOPERATIONRESPONSEMESSAGE
class TElDCOperationResponseMessage: public TElDCBaseMessage
{
	private:
		SB_DISABLE_COPY(TElDCOperationResponseMessage)
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_KeysRDN;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		void initInstances();

	public:
		virtual void InitializeMessage();

		virtual void Assign(TElDCBaseMessage &Source);

		virtual void Assign(TElDCBaseMessage *Source);

		virtual TElDCBaseMessageHandle Clone();

		static TClassHandle ClassType();

		virtual TSBDCOperation get_Operation();

		virtual void set_Operation(TSBDCOperation Value);

		SB_DECLARE_PROPERTY(TSBDCOperation, get_Operation, set_Operation, TElDCOperationResponseMessage, Operation);

		virtual void get_OperationResult(std::vector<uint8_t> &OutResult);

		virtual void set_OperationResult(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_KeysRDN();

		SB_DECLARE_PROPERTY_GET(TElRelativeDistinguishedName*, get_KeysRDN, TElDCOperationResponseMessage, KeysRDN);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		TElDCOperationResponseMessage(TElDCOperationResponseMessageHandle handle, TElOwnHandle ownHandle);

		TElDCOperationResponseMessage();

		explicit TElDCOperationResponseMessage(TElDCBaseMessage &OrigMessage);

		explicit TElDCOperationResponseMessage(TElDCBaseMessage *OrigMessage);

		virtual ~TElDCOperationResponseMessage();

};
#endif /* SB_USE_CLASS_TELDCOPERATIONRESPONSEMESSAGE */

#ifdef SB_USE_CLASS_TELDCBATCHMESSAGE
class TElDCBatchMessage: public TElDCBaseMessage
{
	private:
		SB_DISABLE_COPY(TElDCBatchMessage)
		TElDCBaseMessage* _Inst_Messages;

		void initInstances();

	public:
		virtual void Assign(TElDCBaseMessage &Source);

		virtual void Assign(TElDCBaseMessage *Source);

		virtual TElDCBaseMessageHandle Clone();

		int32_t Add(TElDCBaseMessage &Message, bool CreateCopy);

		int32_t Add(TElDCBaseMessage *Message, bool CreateCopy);

		void Remove(int32_t Index);

		void Clear();

		static TClassHandle ClassType();

		virtual TElDCBaseMessage* get_Messages(int32_t Index);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElDCBatchMessage, Count);

		TElDCBatchMessage(TElDCBatchMessageHandle handle, TElOwnHandle ownHandle);

		TElDCBatchMessage();

		virtual ~TElDCBatchMessage();

};
#endif /* SB_USE_CLASS_TELDCBATCHMESSAGE */

#ifdef SB_USE_CLASS_TELDCMESSAGEFACTORY
class TElDCMessageFactory: public TObject
{
	private:
		SB_DISABLE_COPY(TElDCMessageFactory)
	public:
#ifdef SB_USE_CLASSES_TELDCBASEMESSAGE_AND_TELDCENCODING_AND_TSTREAM
		TElDCBaseMessageHandle CreateInstance(TStream &Stream, TElDCEncoding &Encoding);

		TElDCBaseMessageHandle CreateInstance(TStream *Stream, TElDCEncoding *Encoding);
#endif /* SB_USE_CLASSES_TELDCBASEMESSAGE_AND_TELDCENCODING_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELDCBASEMESSAGE_AND_TELDCNODE
		TElDCBaseMessageHandle CreateInstance(TElDCNode &Node);

		TElDCBaseMessageHandle CreateInstance(TElDCNode *Node);
#endif /* SB_USE_CLASSES_TELDCBASEMESSAGE_AND_TELDCNODE */

		void RegisterClass(TElDCMessageClassHandle Cls);

		TElDCMessageFactory(TElDCMessageFactoryHandle handle, TElOwnHandle ownHandle);

		TElDCMessageFactory();

};
#endif /* SB_USE_CLASS_TELDCMESSAGEFACTORY */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
class TElDCAsyncState: public TObject
{
	private:
		SB_DISABLE_COPY(TElDCAsyncState)
#ifdef SB_USE_CLASS_TELDCBATCHMESSAGE
		TElDCBatchMessage* _Inst_Messages;
#endif /* SB_USE_CLASS_TELDCBATCHMESSAGE */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_StateSubtypes;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_StateSubtypes;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
		TElDCAsyncState* _Inst_InnerState;

		void initInstances();

	public:
		TElDCAsyncStateHandle Clone();

#ifdef SB_USE_CLASS_TELDCNODE
		void SaveToNode(TElDCNode &Node);

		void SaveToNode(TElDCNode *Node);
#endif /* SB_USE_CLASS_TELDCNODE */

#ifdef SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM
		void SaveToStream(TStream &Stream, TElDCEncoding &Encoding);

		void SaveToStream(TStream *Stream, TElDCEncoding *Encoding);
#endif /* SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM */

#ifdef SB_USE_CLASS_TELDCNODE
		void LoadFromNode(TElDCNode &Node);

		void LoadFromNode(TElDCNode *Node);
#endif /* SB_USE_CLASS_TELDCNODE */

#ifdef SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM
		void LoadFromStream(TStream &Stream, TElDCEncoding &Encoding);

		void LoadFromStream(TStream *Stream, TElDCEncoding *Encoding);
#endif /* SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM */

		bool SubtypePresent(const std::string &Subtype);

#ifdef SB_USE_CLASS_TELDCBASEMESSAGE
		TElDCBaseMessageHandle FindMessageByType(TElDCMessageClassHandle MsgType);
#endif /* SB_USE_CLASS_TELDCBASEMESSAGE */

#ifdef SB_USE_CLASS_TELDCBASEMESSAGE
		TElDCBaseMessageHandle FindMessageByName(const std::string &Name);
#endif /* SB_USE_CLASS_TELDCBASEMESSAGE */

#ifdef SB_USE_CLASS_TELDCBATCHMESSAGE
		virtual TElDCBatchMessage* get_Messages();

		SB_DECLARE_PROPERTY_GET(TElDCBatchMessage*, get_Messages, TElDCAsyncState, Messages);
#endif /* SB_USE_CLASS_TELDCBATCHMESSAGE */

		virtual void get_StateType(std::string &OutResult);

		virtual void set_StateType(const std::string &Value);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_StateSubtypes();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_StateSubtypes, TElDCAsyncState, StateSubtypes);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_StateSubtypes();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_StateSubtypes, TElDCAsyncState, StateSubtypes);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual void get_UserData(std::vector<uint8_t> &OutResult);

		virtual void set_UserData(const std::vector<uint8_t> &Value);

		virtual void get_Generator(std::string &OutResult);

		virtual TElDCAsyncState* get_InnerState();

		SB_DECLARE_PROPERTY_GET(TElDCAsyncState*, get_InnerState, TElDCAsyncState, InnerState);

		TElDCAsyncState(TElDCAsyncStateHandle handle, TElOwnHandle ownHandle);

		TElDCAsyncState();

		TElDCAsyncState(TElDCAsyncState &InnerState, bool ReleaseOnDestruction);

		TElDCAsyncState(TElDCAsyncState *InnerState, bool ReleaseOnDestruction);

		virtual ~TElDCAsyncState();

};
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASS_TELDCASYNCSTATECOLLECTION
class TElDCAsyncStateCollection: public TObject
{
	private:
		SB_DISABLE_COPY(TElDCAsyncStateCollection)
#ifdef SB_USE_CLASS_TELDCASYNCSTATE
		TElDCAsyncState* _Inst_States;
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELDCASYNCSTATE
		int32_t Add(TElDCAsyncState &State, bool Clone);

		int32_t Add(TElDCAsyncState *State, bool Clone);
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

		void Remove(int32_t Index);

		void Clear();

		int32_t FindState(const std::vector<uint8_t> &UserData);

#ifdef SB_USE_CLASS_TELDCNODE
		void SaveToNode(TElDCNode &Node);

		void SaveToNode(TElDCNode *Node);
#endif /* SB_USE_CLASS_TELDCNODE */

#ifdef SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM
		void SaveToStream(TStream &Stream, TElDCEncoding &Encoding);

		void SaveToStream(TStream *Stream, TElDCEncoding *Encoding);
#endif /* SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM */

#ifdef SB_USE_CLASS_TELDCNODE
		void LoadFromNode(TElDCNode &Node);

		void LoadFromNode(TElDCNode *Node);
#endif /* SB_USE_CLASS_TELDCNODE */

#ifdef SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM
		void LoadFromStream(TStream &Stream, TElDCEncoding &Encoding);

		void LoadFromStream(TStream *Stream, TElDCEncoding *Encoding);
#endif /* SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM */

		virtual void get_UserData(std::vector<uint8_t> &OutResult);

		virtual void set_UserData(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
		virtual TElDCAsyncState* get_States(int32_t Index);
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElDCAsyncStateCollection, Count);

		TElDCAsyncStateCollection(TElDCAsyncStateCollectionHandle handle, TElOwnHandle ownHandle);

		explicit TElDCAsyncStateCollection(bool OwnsObjects);

		virtual ~TElDCAsyncStateCollection();

};
#endif /* SB_USE_CLASS_TELDCASYNCSTATECOLLECTION */

#ifdef SB_USE_GLOBAL_PROCS_DC

void DCBoolToStr(bool B, std::string &OutResult);

bool DCStrToBool(const std::string &S, bool Def);

void DCBoolToByteArray(bool B, std::vector<uint8_t> &OutResult);

bool DCByteArrayToBool(const std::vector<uint8_t> &S, bool Def);

#endif /* SB_USE_GLOBAL_PROCS_DC */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_DC
SB_IMPORT uint32_t SB_APIENTRY SBDC_DCBoolToStr(int8_t B, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDC_DCStrToBool(const char * pcS, int32_t szS, int8_t Def, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDC_DCBoolToByteArray(int8_t B, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDC_DCByteArrayToBool(const uint8_t pS[], int32_t szS, int8_t Def, int8_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_DC */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBDC */
