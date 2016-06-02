#ifndef __INC_SBWEBSOCKETCOMMON
#define __INC_SBWEBSOCKETCOMMON

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbstreams.h"
#include "sbrandom.h"
#include "sbsslcommon.h"
#include "sbtypes.h"
#include "sbsharedresource.h"
#include "sbstrutils.h"
#include "sbhashfunction.h"
#include "sbencoding.h"
#include "sbstringlist.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_WS_VERSION 	13
#define SB_WS_VERSION_STR 	"13"
#define SB_DEFAULT_FRAME_LEN 	1024
#define SB_WS_MODE_CLIENT 	0
#define SB_WS_MODE_SERVER 	1
#define SB_WS_NO_CLOSE_DESC 	-1
#define SB_WS_STATUS_OK 	1000
#define SB_WS_STATUS_GOING_AWAY 	1001
#define SB_WS_STATUS_PROTOCOL_ERROR 	1002
#define SB_WS_STATUS_CANT_ACCEPT_DATA 	1003
#define SB_WS_STATUS_RESERVED 	1004
#define SB_WS_STATUS_NO_STATUS_CODE 	1005
#define SB_WS_STATUS_CONN_CLOSED_ABNORMALLY 	1006
#define SB_WS_STATUS_NOT_CONSISTENT_DATA 	1007
#define SB_WS_STATUS_POLICY_VIOLATION 	1008
#define SB_WS_STATUS_TOO_BIG_MESSAGE 	1009
#define SB_WS_STATUS_CLIENT_EXTENSIONS_EXPECTED 	1010
#define SB_WS_STATUS_UNEXPECTED 	1011
#define SB_WS_STATUS_TLS_HANDSHAKE_FAILURE 	1015
#define SB_WS_OP_CONTINUATION 	0
#define SB_WS_OP_TEXT 	1
#define SB_WS_OP_BINARY 	2
#define SB_WS_OP_CLOSE 	8
#define SB_WS_OP_PING 	9
#define SB_WS_OP_PONG 	10

typedef TElClassHandle TElWebSocketMessageHandle;

typedef TElClassHandle TElWebSocketOptionHandle;

typedef TElClassHandle TElWebSocketExtensionHandle;

typedef TElClassHandle TElWebSocketBaseHandle;

typedef TElClassHandle TElWebSocketSubProtocolHandle;

typedef TElClassHandle TElWebSocketExtensionsHandle;

typedef TElClassHandle TElWebSocketSubProtocolsHandle;

typedef uint8_t TSBMsgTypeRaw;

typedef enum
{
	wmtNone = 0,
	wmtBinary = 1,
	wmtText = 2
} TSBMsgType;

typedef void (SB_CALLBACK *TSBWSBeforeMsgSendEvent)(void * _ObjectData, TObjectHandle Sender, TElWebSocketMessageHandle Msg);

typedef void (SB_CALLBACK *TSBWSMsgReceivedEvent)(void * _ObjectData, TObjectHandle Sender, TElWebSocketMessageHandle Msg);

typedef void (SB_CALLBACK *TSBWSPongEvent)(void * _ObjectData, TObjectHandle Sender);

typedef void (SB_CALLBACK *TSBWSTextDataEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcText, int32_t szText, int8_t Last);

typedef void (SB_CALLBACK *TSBWSCloseConnectionEvent)(void * _ObjectData, TObjectHandle Sender, int8_t Remote, int32_t CloseDescription);

typedef void (SB_CALLBACK *TSBWSBinaryDataEvent)(void * _ObjectData, TObjectHandle Sender, void * Buffer, int32_t Size, int8_t Last);

#ifdef SB_USE_CLASS_TELWEBSOCKETMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_Clone(TElWebSocketMessageHandle _Handle, TElWebSocketMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_Clear(TElWebSocketMessageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_SaveToBuffer(TElWebSocketMessageHandle _Handle, uint8_t pBuffer[], int32_t * szBuffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_LoadFromBuffer(TElWebSocketMessageHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Offset, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_get_IsFinal(TElWebSocketMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_set_IsFinal(TElWebSocketMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_get_RSV1(TElWebSocketMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_set_RSV1(TElWebSocketMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_get_RSV2(TElWebSocketMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_set_RSV2(TElWebSocketMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_get_RSV3(TElWebSocketMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_set_RSV3(TElWebSocketMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_get_OpCode(TElWebSocketMessageHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_set_OpCode(TElWebSocketMessageHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_get_Mask(TElWebSocketMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_set_Mask(TElWebSocketMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_get_PayloadLen(TElWebSocketMessageHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_get_Fragmented(TElWebSocketMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_get_MaskKey(TElWebSocketMessageHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_set_MaskKey(TElWebSocketMessageHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_get_PayloadData(TElWebSocketMessageHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_set_PayloadData(TElWebSocketMessageHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_get_FullSize(TElWebSocketMessageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketMessage_Create(TElWebSocketMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBSOCKETMESSAGE */

#ifdef SB_USE_CLASS_TELWEBSOCKETOPTION
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketOption_Assign(TElWebSocketOptionHandle _Handle, TElWebSocketOptionHandle Option);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketOption_Clone(TElWebSocketOptionHandle _Handle, TElWebSocketOptionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketOption_get_Name(TElWebSocketOptionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketOption_get_Active(TElWebSocketOptionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketOption_set_Active(TElWebSocketOptionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketOption_get_Priority(TElWebSocketOptionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketOption_set_Priority(TElWebSocketOptionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketOption_get_ParamStr(TElWebSocketOptionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketOption_set_ParamStr(TElWebSocketOptionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketOption_Create(TElWebSocketOptionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketOption_Create_1(int32_t APriority, TElWebSocketOptionHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBSOCKETOPTION */

#ifdef SB_USE_CLASS_TELWEBSOCKETEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketExtension_Clone(TElWebSocketExtensionHandle _Handle, TElWebSocketExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketExtension_Encode(TElWebSocketExtensionHandle _Handle, TElWebSocketMessageHandle Msg, TElWebSocketMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketExtension_Decode(TElWebSocketExtensionHandle _Handle, TElWebSocketMessageHandle Msg, TElWebSocketMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketExtension_Create(TElWebSocketOptionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketExtension_Create_1(int32_t APriority, TElWebSocketOptionHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBSOCKETEXTENSION */

#ifdef SB_USE_CLASS_TELWEBSOCKETBASE
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_SetControl(TElWebSocketBaseHandle _Handle, TElSSLClassHandle Control);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_CreateWebSocketAccept(const char * pcKey, int32_t szKey, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_CreateWebSocketAccept_1(TElWebSocketBaseHandle _Handle, const char * pcKey, int32_t szKey, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_Close(TElWebSocketBaseHandle _Handle, int8_t Silent);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_Close_1(TElWebSocketBaseHandle _Handle, int8_t Silent, int32_t CloseDescription);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_SendData(TElWebSocketBaseHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_SendData_1(TElWebSocketBaseHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t StartIndex, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_SendData_2(TElWebSocketBaseHandle _Handle, const TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_SendData_3(TElWebSocketBaseHandle _Handle, const TStreamHandle Strm, int32_t OpCode);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_SendText(TElWebSocketBaseHandle _Handle, const char * pcText, int32_t szText);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_Ping(TElWebSocketBaseHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_get_SubProtocols(TElWebSocketBaseHandle _Handle, TElWebSocketSubProtocolsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_get_SubProtocol(TElWebSocketBaseHandle _Handle, TElWebSocketSubProtocolHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_get_Extensions(TElWebSocketBaseHandle _Handle, TElWebSocketExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_get_Tag(TElWebSocketBaseHandle _Handle, TObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_set_Tag(TElWebSocketBaseHandle _Handle, TObjectHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_get_OwnTag(TElWebSocketBaseHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_set_OwnTag(TElWebSocketBaseHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_get_Active(TElWebSocketBaseHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_get_ProtocolStr(TElWebSocketBaseHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_get_PeerSubProtocolStr(TElWebSocketBaseHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_set_PeerSubProtocolStr(TElWebSocketBaseHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_get_ExtensionsStr(TElWebSocketBaseHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_get_PeerExtensionsStr(TElWebSocketBaseHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_set_PeerExtensionsStr(TElWebSocketBaseHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_get_FrameLength(TElWebSocketBaseHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_set_FrameLength(TElWebSocketBaseHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_get_OnBeforeMessageSend(TElWebSocketBaseHandle _Handle, TSBWSBeforeMsgSendEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_set_OnBeforeMessageSend(TElWebSocketBaseHandle _Handle, TSBWSBeforeMsgSendEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_get_OnMessageReceived(TElWebSocketBaseHandle _Handle, TSBWSMsgReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_set_OnMessageReceived(TElWebSocketBaseHandle _Handle, TSBWSMsgReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_get_OnBinaryData(TElWebSocketBaseHandle _Handle, TSBWSBinaryDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_set_OnBinaryData(TElWebSocketBaseHandle _Handle, TSBWSBinaryDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_get_OnTextData(TElWebSocketBaseHandle _Handle, TSBWSTextDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_set_OnTextData(TElWebSocketBaseHandle _Handle, TSBWSTextDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_get_OnPong(TElWebSocketBaseHandle _Handle, TSBWSPongEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_set_OnPong(TElWebSocketBaseHandle _Handle, TSBWSPongEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_get_OnCloseConnection(TElWebSocketBaseHandle _Handle, TSBWSCloseConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_set_OnCloseConnection(TElWebSocketBaseHandle _Handle, TSBWSCloseConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_Create(TElWebSocketBaseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketBase_Create_1(TElSSLClassHandle Control, TElWebSocketBaseHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBSOCKETBASE */

#ifdef SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketSubProtocol_Clone(TElWebSocketSubProtocolHandle _Handle, TElWebSocketSubProtocolHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketSubProtocol_get_Owner(TElWebSocketSubProtocolHandle _Handle, TElWebSocketBaseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketSubProtocol_get_OnMessageReceived(TElWebSocketSubProtocolHandle _Handle, TSBWSMsgReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketSubProtocol_set_OnMessageReceived(TElWebSocketSubProtocolHandle _Handle, TSBWSMsgReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketSubProtocol_Create(TElWebSocketOptionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketSubProtocol_Create_1(int32_t APriority, TElWebSocketOptionHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL */

#ifdef SB_USE_CLASS_TELWEBSOCKETEXTENSIONS
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketExtensions_CopyTo(TElWebSocketExtensionsHandle _Handle, TElWebSocketExtensionsHandle Exts);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketExtensions_Encode(TElWebSocketExtensionsHandle _Handle, TElWebSocketMessageHandle Msg, TElWebSocketMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketExtensions_Decode(TElWebSocketExtensionsHandle _Handle, TElWebSocketMessageHandle Msg, TElWebSocketMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketExtensions_Add(TElWebSocketExtensionsHandle _Handle, TElWebSocketExtensionHandle Ext, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketExtensions_Remove(TElWebSocketExtensionsHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketExtensions_Sort(TElWebSocketExtensionsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketExtensions_get_Items(TElWebSocketExtensionsHandle _Handle, int32_t Index, TElWebSocketExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketExtensions_get_Count(TElWebSocketExtensionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketExtensions_Create(TElWebSocketExtensionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBSOCKETEXTENSIONS */

#ifdef SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOLS
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketSubProtocols_CopyTo(TElWebSocketSubProtocolsHandle _Handle, TElWebSocketSubProtocolsHandle Protos);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketSubProtocols_Add(TElWebSocketSubProtocolsHandle _Handle, TElWebSocketSubProtocolHandle Proto, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketSubProtocols_Remove(TElWebSocketSubProtocolsHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketSubProtocols_Sort(TElWebSocketSubProtocolsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketSubProtocols_get_Items(TElWebSocketSubProtocolsHandle _Handle, int32_t Index, TElWebSocketSubProtocolHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketSubProtocols_get_Count(TElWebSocketSubProtocolsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketSubProtocols_get_Owner(TElWebSocketSubProtocolsHandle _Handle, TElWebSocketBaseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketSubProtocols_Create(TElWebSocketSubProtocolsHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOLS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElWebSocketMessage;
class TElWebSocketOption;
class TElWebSocketExtension;
class TElWebSocketBase;
class TElWebSocketSubProtocol;
class TElWebSocketExtensions;
class TElWebSocketSubProtocols;

#ifdef SB_USE_CLASS_TELWEBSOCKETMESSAGE
class TElWebSocketMessage: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebSocketMessage)
	public:
		virtual TElWebSocketMessageHandle Clone();

		void Clear();

		virtual bool SaveToBuffer(std::vector<uint8_t> &Buffer, int32_t &Size);

		virtual bool LoadFromBuffer(const std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Size);

		virtual bool get_IsFinal();

		virtual void set_IsFinal(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IsFinal, set_IsFinal, TElWebSocketMessage, IsFinal);

		virtual bool get_RSV1();

		virtual void set_RSV1(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RSV1, set_RSV1, TElWebSocketMessage, RSV1);

		virtual bool get_RSV2();

		virtual void set_RSV2(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RSV2, set_RSV2, TElWebSocketMessage, RSV2);

		virtual bool get_RSV3();

		virtual void set_RSV3(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RSV3, set_RSV3, TElWebSocketMessage, RSV3);

		virtual uint8_t get_OpCode();

		virtual void set_OpCode(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_OpCode, set_OpCode, TElWebSocketMessage, OpCode);

		virtual bool get_Mask();

		virtual void set_Mask(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Mask, set_Mask, TElWebSocketMessage, Mask);

		virtual int64_t get_PayloadLen();

		SB_DECLARE_PROPERTY_GET(int64_t, get_PayloadLen, TElWebSocketMessage, PayloadLen);

		virtual bool get_Fragmented();

		SB_DECLARE_PROPERTY_GET(bool, get_Fragmented, TElWebSocketMessage, Fragmented);

		virtual void get_MaskKey(std::vector<uint8_t> &OutResult);

		virtual void set_MaskKey(const std::vector<uint8_t> &Value);

		virtual void get_PayloadData(std::vector<uint8_t> &OutResult);

		virtual void set_PayloadData(const std::vector<uint8_t> &Value);

		virtual int32_t get_FullSize();

		SB_DECLARE_PROPERTY_GET(int32_t, get_FullSize, TElWebSocketMessage, FullSize);

		TElWebSocketMessage(TElWebSocketMessageHandle handle, TElOwnHandle ownHandle);

		TElWebSocketMessage();

};
#endif /* SB_USE_CLASS_TELWEBSOCKETMESSAGE */

#ifdef SB_USE_CLASS_TELWEBSOCKETOPTION
class TElWebSocketOption: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebSocketOption)
	public:
		virtual void Assign(TElWebSocketOption &Option);

		virtual void Assign(TElWebSocketOption *Option);

		virtual TElWebSocketOptionHandle Clone();

		virtual void get_Name(std::string &OutResult);

		virtual bool get_Active();

		virtual void set_Active(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Active, set_Active, TElWebSocketOption, Active);

		virtual int32_t get_Priority();

		virtual void set_Priority(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Priority, set_Priority, TElWebSocketOption, Priority);

		virtual void get_ParamStr(std::string &OutResult);

		virtual void set_ParamStr(const std::string &Value);

		TElWebSocketOption(TElWebSocketOptionHandle handle, TElOwnHandle ownHandle);

		TElWebSocketOption();

		explicit TElWebSocketOption(int32_t APriority);

};
#endif /* SB_USE_CLASS_TELWEBSOCKETOPTION */

#ifdef SB_USE_CLASS_TELWEBSOCKETEXTENSION
class TElWebSocketExtension: public TElWebSocketOption
{
	private:
		SB_DISABLE_COPY(TElWebSocketExtension)
	public:
		void Clone(TElWebSocketExtensionHandle &OutResult);

#ifdef SB_USE_CLASS_TELWEBSOCKETMESSAGE
		virtual TElWebSocketMessageHandle Encode(TElWebSocketMessage &Msg);

		virtual TElWebSocketMessageHandle Encode(TElWebSocketMessage *Msg);
#endif /* SB_USE_CLASS_TELWEBSOCKETMESSAGE */

#ifdef SB_USE_CLASS_TELWEBSOCKETMESSAGE
		virtual TElWebSocketMessageHandle Decode(TElWebSocketMessage &Msg);

		virtual TElWebSocketMessageHandle Decode(TElWebSocketMessage *Msg);
#endif /* SB_USE_CLASS_TELWEBSOCKETMESSAGE */

		TElWebSocketExtension(TElWebSocketExtensionHandle handle, TElOwnHandle ownHandle);

		TElWebSocketExtension();

		explicit TElWebSocketExtension(int32_t APriority);

};
#endif /* SB_USE_CLASS_TELWEBSOCKETEXTENSION */

#ifdef SB_USE_CLASS_TELWEBSOCKETBASE
class TElWebSocketBase: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebSocketBase)
#ifdef SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOLS
		TElWebSocketSubProtocols* _Inst_SubProtocols;
#endif /* SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOLS */
#ifdef SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL
		TElWebSocketSubProtocol* _Inst_SubProtocol;
#endif /* SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL */
#ifdef SB_USE_CLASS_TELWEBSOCKETEXTENSIONS
		TElWebSocketExtensions* _Inst_Extensions;
#endif /* SB_USE_CLASS_TELWEBSOCKETEXTENSIONS */
		TObject* _Inst_Tag;

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELSSLCLASS
		void SetControl(TElSSLClass &Control);

		void SetControl(TElSSLClass *Control);
#endif /* SB_USE_CLASS_TELSSLCLASS */

		static void CreateWebSocketAccept(const std::string &Key, std::string &OutResult);

		void CreateWebSocketAccept_Inst(const std::string &Key, std::string &OutResult);

		void Close(bool Silent);

		void Close(bool Silent, int32_t CloseDescription);

		void SendData(const std::vector<uint8_t> &Buffer);

		void SendData(const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Count);

#ifdef SB_USE_CLASS_TSTREAM
		void SendData(const TStream &Strm);

		void SendData(const TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void SendData(const TStream &Strm, int32_t OpCode);

		void SendData(const TStream *Strm, int32_t OpCode);
#endif /* SB_USE_CLASS_TSTREAM */

		void SendText(const std::string &Text);

		void Ping();

#ifdef SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOLS
		virtual TElWebSocketSubProtocols* get_SubProtocols();

		SB_DECLARE_PROPERTY_GET(TElWebSocketSubProtocols*, get_SubProtocols, TElWebSocketBase, SubProtocols);
#endif /* SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOLS */

#ifdef SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL
		virtual TElWebSocketSubProtocol* get_SubProtocol();

		SB_DECLARE_PROPERTY_GET(TElWebSocketSubProtocol*, get_SubProtocol, TElWebSocketBase, SubProtocol);
#endif /* SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL */

#ifdef SB_USE_CLASS_TELWEBSOCKETEXTENSIONS
		virtual TElWebSocketExtensions* get_Extensions();

		SB_DECLARE_PROPERTY_GET(TElWebSocketExtensions*, get_Extensions, TElWebSocketBase, Extensions);
#endif /* SB_USE_CLASS_TELWEBSOCKETEXTENSIONS */

		virtual TObject* get_Tag();

		virtual void set_Tag(TObject &Value);

		virtual void set_Tag(TObject *Value);

		SB_DECLARE_PROPERTY(TObject*, get_Tag, set_Tag, TElWebSocketBase, Tag);

		virtual bool get_OwnTag();

		virtual void set_OwnTag(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OwnTag, set_OwnTag, TElWebSocketBase, OwnTag);

		virtual bool get_Active();

		SB_DECLARE_PROPERTY_GET(bool, get_Active, TElWebSocketBase, Active);

		virtual void get_ProtocolStr(std::string &OutResult);

		virtual void get_PeerSubProtocolStr(std::string &OutResult);

		virtual void set_PeerSubProtocolStr(const std::string &Value);

		virtual void get_ExtensionsStr(std::string &OutResult);

		virtual void get_PeerExtensionsStr(std::string &OutResult);

		virtual void set_PeerExtensionsStr(const std::string &Value);

		virtual int32_t get_FrameLength();

		virtual void set_FrameLength(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_FrameLength, set_FrameLength, TElWebSocketBase, FrameLength);

		virtual void get_OnBeforeMessageSend(TSBWSBeforeMsgSendEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeMessageSend(TSBWSBeforeMsgSendEvent pMethodValue, void * pDataValue);

		virtual void get_OnMessageReceived(TSBWSMsgReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnMessageReceived(TSBWSMsgReceivedEvent pMethodValue, void * pDataValue);

		virtual void get_OnBinaryData(TSBWSBinaryDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBinaryData(TSBWSBinaryDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnTextData(TSBWSTextDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTextData(TSBWSTextDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnPong(TSBWSPongEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPong(TSBWSPongEvent pMethodValue, void * pDataValue);

		virtual void get_OnCloseConnection(TSBWSCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCloseConnection(TSBWSCloseConnectionEvent pMethodValue, void * pDataValue);

		TElWebSocketBase(TElWebSocketBaseHandle handle, TElOwnHandle ownHandle);

		TElWebSocketBase();

#ifdef SB_USE_CLASS_TELSSLCLASS
		explicit TElWebSocketBase(TElSSLClass &Control);

		explicit TElWebSocketBase(TElSSLClass *Control);
#endif /* SB_USE_CLASS_TELSSLCLASS */

		virtual ~TElWebSocketBase();

};
#endif /* SB_USE_CLASS_TELWEBSOCKETBASE */

#ifdef SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL
class TElWebSocketSubProtocol: public TElWebSocketOption
{
	private:
		SB_DISABLE_COPY(TElWebSocketSubProtocol)
#ifdef SB_USE_CLASS_TELWEBSOCKETBASE
		TElWebSocketBase* _Inst_Owner;
#endif /* SB_USE_CLASS_TELWEBSOCKETBASE */

		void initInstances();

	public:
		void Clone(TElWebSocketSubProtocolHandle &OutResult);

#ifdef SB_USE_CLASS_TELWEBSOCKETBASE
		virtual TElWebSocketBase* get_Owner();

		SB_DECLARE_PROPERTY_GET(TElWebSocketBase*, get_Owner, TElWebSocketSubProtocol, Owner);
#endif /* SB_USE_CLASS_TELWEBSOCKETBASE */

		virtual void get_OnMessageReceived(TSBWSMsgReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnMessageReceived(TSBWSMsgReceivedEvent pMethodValue, void * pDataValue);

		TElWebSocketSubProtocol(TElWebSocketSubProtocolHandle handle, TElOwnHandle ownHandle);

		TElWebSocketSubProtocol();

		explicit TElWebSocketSubProtocol(int32_t APriority);

		virtual ~TElWebSocketSubProtocol();

};
#endif /* SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL */

#ifdef SB_USE_CLASS_TELWEBSOCKETEXTENSIONS
class TElWebSocketExtensions: public TElWebSocketExtension
{
	private:
		SB_DISABLE_COPY(TElWebSocketExtensions)
		TElWebSocketExtension* _Inst_Items;

		void initInstances();

	public:
		void CopyTo(TElWebSocketExtensions &Exts);

		void CopyTo(TElWebSocketExtensions *Exts);

#ifdef SB_USE_CLASS_TELWEBSOCKETMESSAGE
		virtual TElWebSocketMessageHandle Encode(TElWebSocketMessage &Msg);

		virtual TElWebSocketMessageHandle Encode(TElWebSocketMessage *Msg);
#endif /* SB_USE_CLASS_TELWEBSOCKETMESSAGE */

#ifdef SB_USE_CLASS_TELWEBSOCKETMESSAGE
		virtual TElWebSocketMessageHandle Decode(TElWebSocketMessage &Msg);

		virtual TElWebSocketMessageHandle Decode(TElWebSocketMessage *Msg);
#endif /* SB_USE_CLASS_TELWEBSOCKETMESSAGE */

		int32_t Add(TElWebSocketExtension &Ext);

		int32_t Add(TElWebSocketExtension *Ext);

		void Remove(int32_t Index);

		void Sort();

		virtual TElWebSocketExtension* get_Items(int32_t Index);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElWebSocketExtensions, Count);

		TElWebSocketExtensions(TElWebSocketExtensionsHandle handle, TElOwnHandle ownHandle);

		TElWebSocketExtensions();

		virtual ~TElWebSocketExtensions();

};
#endif /* SB_USE_CLASS_TELWEBSOCKETEXTENSIONS */

#ifdef SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOLS
class TElWebSocketSubProtocols: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebSocketSubProtocols)
#ifdef SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL
		TElWebSocketSubProtocol* _Inst_Items;
#endif /* SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL */
#ifdef SB_USE_CLASS_TELWEBSOCKETBASE
		TElWebSocketBase* _Inst_Owner;
#endif /* SB_USE_CLASS_TELWEBSOCKETBASE */

		void initInstances();

	public:
		void CopyTo(TElWebSocketSubProtocols &Protos);

		void CopyTo(TElWebSocketSubProtocols *Protos);

#ifdef SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL
		int32_t Add(TElWebSocketSubProtocol &Proto);

		int32_t Add(TElWebSocketSubProtocol *Proto);
#endif /* SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL */

		void Remove(int32_t Index);

		void Sort();

#ifdef SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL
		virtual TElWebSocketSubProtocol* get_Items(int32_t Index);
#endif /* SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElWebSocketSubProtocols, Count);

#ifdef SB_USE_CLASS_TELWEBSOCKETBASE
		virtual TElWebSocketBase* get_Owner();

		SB_DECLARE_PROPERTY_GET(TElWebSocketBase*, get_Owner, TElWebSocketSubProtocols, Owner);
#endif /* SB_USE_CLASS_TELWEBSOCKETBASE */

		TElWebSocketSubProtocols(TElWebSocketSubProtocolsHandle handle, TElOwnHandle ownHandle);

		TElWebSocketSubProtocols();

		virtual ~TElWebSocketSubProtocols();

};
#endif /* SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOLS */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBWEBSOCKETCOMMON */

