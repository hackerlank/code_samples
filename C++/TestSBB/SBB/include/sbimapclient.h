#ifndef __INC_SBIMAPCLIENT
#define __INC_SBIMAPCLIENT

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
#include "sbsslcommon.h"
#include "sbsslconstants.h"
#include "sbsslclient.h"
#include "sbx509.h"
#include "sbsasl.h"
#include "sbstringlist.h"
#include "sbencoding.h"
#include "sbchsconv.h"
#include "sbimaputils.h"
#ifndef SB_WINCE_OR_NOT_WINDOWS
#include "sbdnssectypes.h"
#include "sbsocket.h"
#endif

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ERROR_FACILITY_IMAP 	106496
#define SB_ERROR_IMAP_PROTOCOL_ERROR_FLAG 	2048
#define SB_IMAP_ERROR_NOT_CONNECTED 	108545
#define SB_IMAP_ERROR_ALREADY_CONNECTED 	108546
#define SB_IMAP_ERROR_NO_ADDRESS 	108547
#define SB_IMAP_ERROR_FAILURE 	108548
#define SB_IMAP_ERROR_PROTOCOL 	108549
#define SB_IMAP_ERROR_NO_REPLY 	108550
#define SB_IMAP_ERROR_BAD_REPLY 	108551
#define SB_IMAP_ERROR_INVALID_LENGTH 	108552
#define SB_IMAP_ERROR_SMALL_LENGTH 	108553
#define SB_IMAP_ERROR_TOO_LONG_LINE 	108554
#define SB_IMAP_ERROR_TLSNOTSUPPORTED 	108555
#define SB_IMAP_ERROR_INVALID_STATE 	108556
#define SB_imapLastMessage 	2147483647

typedef TElClassHandle TElIMAPLiteralContextHandle;

typedef TElClassHandle TElIMAPMailBoxStateHandle;

typedef TElClassHandle TElIMAPMailBoxInfoHandle;

typedef TElClassHandle TElIMAPMailBoxesListHandle;

typedef TElClassHandle TElIMAPFetchResponseItemHandle;

typedef TElClassHandle TElIMAPFetchResponseLineHandle;

typedef TElClassHandle TElIMAPFetchResponseHandle;

typedef TElClassHandle TElIMAPIdleUpdateHandle;

typedef TElClassHandle TElIMAPIdleThreadHandle;

typedef TElClassHandle TElIMAPTimeoutThreadHandle;

typedef TElClassHandle TElIMAPClientHandle;

typedef TElIMAPClientHandle ElIMAPClientHandle;

typedef uint8_t TSBIMAPLogDirectionRaw;

typedef enum
{
	imapSent = 0,
	imapReceived = 1
} TSBIMAPLogDirection;

typedef void (SB_CALLBACK *TSBIMAPLogEvent)(void * _ObjectData, TObjectHandle Sender, TSBIMAPLogDirectionRaw Direction, const char * pcInfo, int32_t szInfo);

typedef uint8_t TSBIMAPAuthorizationRaw;

typedef enum
{
	imapLOGIN = 0,
	imapSASL = 1
} TSBIMAPAuthorization;

typedef uint32_t TSBIMAPAuthorizationsRaw;

typedef enum 
{
	f_imapLOGIN = 1,
	f_imapSASL = 2
} TSBIMAPAuthorizations;

typedef uint8_t TSBIMAPAutoCAPAModeRaw;

typedef enum
{
	_capaNone = 0,
	_capaOnConnect = 1,
	_capaOnLogin = 2,
	_capaBoth = 3
} TSBIMAPAutoCAPAMode;

typedef uint8_t TSBIMAPStateRaw;

typedef enum
{
	imapNotAuthenticated = 0,
	imapAuthenticated = 1,
	imapSelected = 2
} TSBIMAPState;

typedef uint8_t TSBIMAPTokenRaw;

typedef enum
{
	imapUnknownToken = 0,
	imapOkToken = 1,
	imapOkFinalToken = 2,
	imapBadToken = 3,
	imapBadFinalToken = 4,
	imapNoToken = 5,
	imapNoFinalToken = 6,
	imapPreAuthToken = 7,
	imapByeToken = 8,
	imapContinueToken = 9,
	imapCapabilityToken = 10,
	imapListToken = 11,
	imapLSubToken = 12,
	imapStatusToken = 13,
	imapSearchToken = 14,
	imapFlagsToken = 15,
	imapExistsToken = 16,
	imapRecentToken = 17,
	imapExpungeToken = 18,
	imapFetchToken = 19,
	imapUidNextToken = 20,
	imapUidValidToken = 21,
	imapUnseenToken = 22,
	imapReadOnlyToken = 23,
	imapReadWriteToken = 24,
	imapPermanentFlagsToken = 25,
	imapTrycreateToken = 26,
	imapAlertToken = 27,
	imapBadcharsetToken = 28,
	imapParseToken = 29
} TSBIMAPToken;

typedef uint8_t TElIMAPFetchResponseItemTypeRaw;

typedef enum
{
	imapFetchUunknown = 0,
	imapFetchUid = 1,
	imapFetchEnvelope = 2,
	imapFetchFlags = 3,
	imapFetchInternaldate = 4,
	imapFetchRfc822 = 5,
	imapFetchRfc822Header = 6,
	imapFetchRfc822Size = 7,
	imapFetchRfc822Text = 8
} TElIMAPFetchResponseItemType;

typedef uint8_t TSBIMAPStoreFlagsOperationRaw;

typedef enum
{
	imapReplaceFlags = 0,
	imapAddFlags = 1,
	imapRemoveFlags = 2
} TSBIMAPStoreFlagsOperation;

typedef uint8_t TElIMAPMailBoxAttributeRaw;

typedef enum
{
	imapNoSelect = 0,
	imapNoInferiors = 1,
	imapMarked = 2,
	imapUnmarked = 3,
	imapHasChildren = 4,
	imapHasNoChildren = 5
} TElIMAPMailBoxAttribute;

typedef uint32_t TElIMAPMailBoxAttributesRaw;

typedef enum 
{
	f_imapNoSelect = 1,
	f_imapNoInferiors = 2,
	f_imapMarked = 4,
	f_imapUnmarked = 8,
	f_imapHasChildren = 16,
	f_imapHasNoChildren = 32
} TElIMAPMailBoxAttributes;

typedef uint8_t TSBIMAPMessageFlagRaw;

typedef enum
{
	imapUnknownFlag = 0,
	imapAnsweredFlag = 1,
	imapFlaggedFlag = 2,
	imapDeletedFlag = 3,
	imapSeenFlag = 4,
	imapDraftFlag = 5,
	imapSpecialFlag = 6
} TSBIMAPMessageFlag;

typedef uint32_t TSBIMAPMessageFlagsRaw;

typedef enum 
{
	f_imapUnknownFlag = 1,
	f_imapAnsweredFlag = 2,
	f_imapFlaggedFlag = 4,
	f_imapDeletedFlag = 8,
	f_imapSeenFlag = 16,
	f_imapDraftFlag = 32,
	f_imapSpecialFlag = 64
} TSBIMAPMessageFlags;

typedef uint8_t TSBIMAPStatusItemRaw;

typedef enum
{
	imapStatusMessages = 0,
	imapStatusUnseen = 1,
	imapStatusRecent = 2,
	imapStatusUidNext = 3,
	imapStatusUidValidity = 4
} TSBIMAPStatusItem;

typedef uint32_t TSBIMAPStatusItemsRaw;

typedef enum 
{
	f_imapStatusMessages = 1,
	f_imapStatusUnseen = 2,
	f_imapStatusRecent = 4,
	f_imapStatusUidNext = 8,
	f_imapStatusUidValidity = 16
} TSBIMAPStatusItems;

typedef void (SB_CALLBACK *TSBIMAPTextLineEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcInfo, int32_t szInfo);

typedef void (SB_CALLBACK *TSBIMAPIdleEvent)(void * _ObjectData, TObjectHandle Sender, TElIMAPIdleUpdateHandle Update);

#ifdef SB_USE_CLASS_TELIMAPLITERALCONTEXT
SB_IMPORT uint32_t SB_APIENTRY TElIMAPLiteralContext_get_Line(TElIMAPLiteralContextHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPLiteralContext_set_Line(TElIMAPLiteralContextHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPLiteralContext_get_IsLiteral(TElIMAPLiteralContextHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPLiteralContext_set_IsLiteral(TElIMAPLiteralContextHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPLiteralContext_Create(const char * pcLine, int32_t szLine, TElIMAPLiteralContextHandle * OutResult);
#endif /* SB_USE_CLASS_TELIMAPLITERALCONTEXT */

#ifdef SB_USE_CLASS_TELIMAPMAILBOXSTATE
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxState_Clear(TElIMAPMailBoxStateHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxState_CopyFrom(TElIMAPMailBoxStateHandle _Handle, TElIMAPMailBoxStateHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxState_get_ReadWrite(TElIMAPMailBoxStateHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxState_set_ReadWrite(TElIMAPMailBoxStateHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxState_get_TotalMessages(TElIMAPMailBoxStateHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxState_set_TotalMessages(TElIMAPMailBoxStateHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxState_get_RecentMessages(TElIMAPMailBoxStateHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxState_set_RecentMessages(TElIMAPMailBoxStateHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxState_get_UnseenMessages(TElIMAPMailBoxStateHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxState_set_UnseenMessages(TElIMAPMailBoxStateHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxState_get_Flags(TElIMAPMailBoxStateHandle _Handle, TSBIMAPMessageFlagsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxState_set_Flags(TElIMAPMailBoxStateHandle _Handle, TSBIMAPMessageFlagsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxState_get_PermanentFlags(TElIMAPMailBoxStateHandle _Handle, TSBIMAPMessageFlagsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxState_set_PermanentFlags(TElIMAPMailBoxStateHandle _Handle, TSBIMAPMessageFlagsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxState_get_NextUID(TElIMAPMailBoxStateHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxState_set_NextUID(TElIMAPMailBoxStateHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxState_get_UIDValidity(TElIMAPMailBoxStateHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxState_set_UIDValidity(TElIMAPMailBoxStateHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxState_Create(TElIMAPMailBoxStateHandle * OutResult);
#endif /* SB_USE_CLASS_TELIMAPMAILBOXSTATE */

#ifdef SB_USE_CLASS_TELIMAPMAILBOXINFO
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxInfo_get_Attributes(TElIMAPMailBoxInfoHandle _Handle, TElIMAPMailBoxAttributesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxInfo_get_Delimiter(TElIMAPMailBoxInfoHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxInfo_get_Name(TElIMAPMailBoxInfoHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxInfo_Create(TElIMAPMailBoxAttributesRaw AAttributes, const sb_char16_t * pcADelimiter, int32_t szADelimiter, const sb_char16_t * pcAName, int32_t szAName, TElIMAPMailBoxInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELIMAPMAILBOXINFO */

#ifdef SB_USE_CLASS_TELIMAPMAILBOXESLIST
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxesList_Add(TElIMAPMailBoxesListHandle _Handle, TElIMAPMailBoxInfoHandle Item);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxesList_Get(TElIMAPMailBoxesListHandle _Handle, int32_t Index, TElIMAPMailBoxInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxesList_Clear(TElIMAPMailBoxesListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxesList_get_Count(TElIMAPMailBoxesListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPMailBoxesList_Create(TElIMAPMailBoxesListHandle * OutResult);
#endif /* SB_USE_CLASS_TELIMAPMAILBOXESLIST */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponseItem_SetData(TElIMAPFetchResponseItemHandle _Handle, const char * pcAName, int32_t szAName, const char * pcAValue, int32_t szAValue);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponseItem_get_ItemType(TElIMAPFetchResponseItemHandle _Handle, TElIMAPFetchResponseItemTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponseItem_get_Name(TElIMAPFetchResponseItemHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponseItem_get_RawValue(TElIMAPFetchResponseItemHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponseItem_get_Value(TElIMAPFetchResponseItemHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponseItem_get_DateTime(TElIMAPFetchResponseItemHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponseItem_get_Flags(TElIMAPFetchResponseItemHandle _Handle, TSBIMAPMessageFlagsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponseItem_get_Number(TElIMAPFetchResponseItemHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponseItem_get_Streamed(TElIMAPFetchResponseItemHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponseItem_Create(const char * pcAName, int32_t szAName, const char * pcAValue, int32_t szAValue, TElIMAPFetchResponseItemHandle * OutResult);
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSELINE
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponseLine_Add(TElIMAPFetchResponseLineHandle _Handle, TElIMAPFetchResponseItemHandle Item);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponseLine_Get(TElIMAPFetchResponseLineHandle _Handle, int32_t Index, TElIMAPFetchResponseItemHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponseLine_GetByName(TElIMAPFetchResponseLineHandle _Handle, const char * pcName, int32_t szName, TElIMAPFetchResponseItemHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponseLine_CopyFrom(TElIMAPFetchResponseLineHandle _Handle, TElIMAPFetchResponseLineHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponseLine_Clear(TElIMAPFetchResponseLineHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponseLine_get_Count(TElIMAPFetchResponseLineHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponseLine_get_ID(TElIMAPFetchResponseLineHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponseLine_get_Items(TElIMAPFetchResponseLineHandle _Handle, const char * pcName, int32_t szName, TElIMAPFetchResponseItemHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponseLine_Create(int32_t ID, TElIMAPFetchResponseLineHandle * OutResult);
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSELINE */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponse_Add(TElIMAPFetchResponseHandle _Handle, TElIMAPFetchResponseLineHandle Line);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponse_Get(TElIMAPFetchResponseHandle _Handle, int32_t Index, TElIMAPFetchResponseLineHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponse_GetByID(TElIMAPFetchResponseHandle _Handle, int32_t ID, TElIMAPFetchResponseLineHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponse_Append(TElIMAPFetchResponseHandle _Handle, TElIMAPFetchResponseHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponse_Clear(TElIMAPFetchResponseHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponse_get_Count(TElIMAPFetchResponseHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponse_get_UID(TElIMAPFetchResponseHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponse_get_Lines(TElIMAPFetchResponseHandle _Handle, int32_t Index, TElIMAPFetchResponseLineHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPFetchResponse_Create(int8_t UID, TElIMAPFetchResponseHandle * OutResult);
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

#ifdef SB_USE_CLASS_TELIMAPIDLEUPDATE
SB_IMPORT uint32_t SB_APIENTRY TElIMAPIdleUpdate_Add(TElIMAPIdleUpdateHandle _Handle, TElIMAPIdleUpdateHandle Update);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPIdleUpdate_Clear(TElIMAPIdleUpdateHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPIdleUpdate_get_Token(TElIMAPIdleUpdateHandle _Handle, TSBIMAPTokenRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPIdleUpdate_set_Token(TElIMAPIdleUpdateHandle _Handle, TSBIMAPTokenRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPIdleUpdate_get_MailBoxState(TElIMAPIdleUpdateHandle _Handle, TElIMAPMailBoxStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPIdleUpdate_get_ChangedMessages(TElIMAPIdleUpdateHandle _Handle, TElIMAPFetchResponseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPIdleUpdate_get_ExpungedMessages(TElIMAPIdleUpdateHandle _Handle, TElIMAPFetchResponseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPIdleUpdate_Create(TElIMAPIdleUpdateHandle * OutResult);
#endif /* SB_USE_CLASS_TELIMAPIDLEUPDATE */

#ifdef SB_USE_CLASS_TELIMAPIDLETHREAD
SB_IMPORT uint32_t SB_APIENTRY TElIMAPIdleThread_Execute(TElIMAPIdleThreadHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPIdleThread_Start(TElIMAPIdleThreadHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPIdleThread_WaitStop(TElIMAPIdleThreadHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPIdleThread_TryCallEvents(TElIMAPIdleThreadHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPIdleThread_Create(TElIMAPClientHandle Client, TElIMAPIdleThreadHandle * OutResult);
#endif /* SB_USE_CLASS_TELIMAPIDLETHREAD */

#ifdef SB_USE_CLASS_TELIMAPTIMEOUTTHREAD
SB_IMPORT uint32_t SB_APIENTRY TElIMAPTimeoutThread_Execute(TElIMAPTimeoutThreadHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPTimeoutThread_Start(TElIMAPTimeoutThreadHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPTimeoutThread_Stop(TElIMAPTimeoutThreadHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPTimeoutThread_Create(TElIMAPClientHandle Client, TElIMAPTimeoutThreadHandle * OutResult);
#endif /* SB_USE_CLASS_TELIMAPTIMEOUTTHREAD */

#ifdef SB_USE_CLASS_TELIMAPCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_Open(TElIMAPClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_ObtainCapabilities(TElIMAPClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_Login(TElIMAPClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_Close(TElIMAPClientHandle _Handle, int8_t Silent);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_Noop(TElIMAPClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_List(TElIMAPClientHandle _Handle, const sb_char16_t * pcRefName, int32_t szRefName, const sb_char16_t * pcMailBox, int32_t szMailBox, TElIMAPMailBoxesListHandle List);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_LSub(TElIMAPClientHandle _Handle, const sb_char16_t * pcRefName, int32_t szRefName, const sb_char16_t * pcMailBox, int32_t szMailBox, TElIMAPMailBoxesListHandle List);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_SelectBox(TElIMAPClientHandle _Handle, const sb_char16_t * pcMailBox, int32_t szMailBox, TElIMAPMailBoxStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_ExamineBox(TElIMAPClientHandle _Handle, const sb_char16_t * pcMailBox, int32_t szMailBox, TElIMAPMailBoxStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_StatusBox(TElIMAPClientHandle _Handle, const sb_char16_t * pcMailBox, int32_t szMailBox, TSBIMAPStatusItemsRaw Items, TElIMAPMailBoxStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_CloseBox(TElIMAPClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_Fetch(TElIMAPClientHandle _Handle, int32_t First, int32_t Last, int8_t UID, const char * pcDataItemNames, int32_t szDataItemNames, TElIMAPFetchResponseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_Fetch_1(TElIMAPClientHandle _Handle, TElIMAPFetchResponseHandle Sequence, const char * pcDataItemNames, int32_t szDataItemNames, TElIMAPFetchResponseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_Store(TElIMAPClientHandle _Handle, int32_t First, int32_t Last, int8_t UID, TSBIMAPStoreFlagsOperationRaw Operation, TSBIMAPMessageFlagsRaw Flags, int8_t Silent, TElIMAPFetchResponseHandle Response);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_Store_1(TElIMAPClientHandle _Handle, TElIMAPFetchResponseHandle Sequence, TSBIMAPStoreFlagsOperationRaw Operation, TSBIMAPMessageFlagsRaw Flags, int8_t Silent, TElIMAPFetchResponseHandle Response);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_Expunge(TElIMAPClientHandle _Handle, TElIMAPFetchResponseHandle Response);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_Copy(TElIMAPClientHandle _Handle, int32_t First, int32_t Last, int8_t UID, const sb_char16_t * pcMailBox, int32_t szMailBox);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_Copy_1(TElIMAPClientHandle _Handle, TElIMAPFetchResponseHandle Sequence, const sb_char16_t * pcMailBox, int32_t szMailBox);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_FetchMessage(TElIMAPClientHandle _Handle, int32_t ID, int8_t UID, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_FetchMessage_1(TElIMAPClientHandle _Handle, int32_t ID, int8_t UID, const char * pcHeaderCharset, int32_t szHeaderCharset, const char * pcBodyCharset, int32_t szBodyCharset, TElMessageParsingOptionsRaw Options, int8_t IgnoreHeaderNativeCharset, int8_t IgnoreBodyNativeCharset, int8_t ActivatePartHandlers, TElMessageHandle * Message, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_CreateBox(TElIMAPClientHandle _Handle, const sb_char16_t * pcMailBox, int32_t szMailBox);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_RenameBox(TElIMAPClientHandle _Handle, const sb_char16_t * pcMailBox, int32_t szMailBox, const sb_char16_t * pcNewName, int32_t szNewName);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_DeleteBox(TElIMAPClientHandle _Handle, const sb_char16_t * pcMailBox, int32_t szMailBox);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_Check(TElIMAPClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_SubscribeBox(TElIMAPClientHandle _Handle, const sb_char16_t * pcMailBox, int32_t szMailBox);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_UnsubscribeBox(TElIMAPClientHandle _Handle, const sb_char16_t * pcMailBox, int32_t szMailBox);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_Search(TElIMAPClientHandle _Handle, int8_t UID, const sb_char16_t * pcCriteria, int32_t szCriteria, TElIMAPFetchResponseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_Search_1(TElIMAPClientHandle _Handle, int8_t UID, const char * pcCriteria, int32_t szCriteria, const char * pcCharset, int32_t szCharset, TElIMAPFetchResponseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_Idle(TElIMAPClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_IdleDone(TElIMAPClientHandle _Handle);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_Capabilities(TElIMAPClientHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_Capabilities(TElIMAPClientHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_LoginDisabled(TElIMAPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_MailBox(TElIMAPClientHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_MailBoxState(TElIMAPClientHandle _Handle, TElIMAPMailBoxStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_IdleSupported(TElIMAPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_IdleActive(TElIMAPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_Address(TElIMAPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_Address(TElIMAPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_MaxLineLength(TElIMAPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_MaxLineLength(TElIMAPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_Port(TElIMAPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_Port(TElIMAPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_SSLMode(TElIMAPClientHandle _Handle, TSBSSLModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_SSLMode(TElIMAPClientHandle _Handle, TSBSSLModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_AutoCAPA(TElIMAPClientHandle _Handle, TSBIMAPAutoCAPAModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_AutoCAPA(TElIMAPClientHandle _Handle, TSBIMAPAutoCAPAModeRaw Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_UseIPv6(TElIMAPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_UseIPv6(TElIMAPClientHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_UseSSL(TElIMAPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_UseSSL(TElIMAPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_Username(TElIMAPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_Username(TElIMAPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_Password(TElIMAPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_Password(TElIMAPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_IdleAuto(TElIMAPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_IdleAuto(TElIMAPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_IdleTimeout(TElIMAPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_IdleTimeout(TElIMAPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_OnCapability(TElIMAPClientHandle _Handle, TSBIMAPTextLineEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_OnCapability(TElIMAPClientHandle _Handle, TSBIMAPTextLineEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_OnLog(TElIMAPClientHandle _Handle, TSBIMAPLogEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_OnLog(TElIMAPClientHandle _Handle, TSBIMAPLogEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_OnProgress(TElIMAPClientHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_OnProgress(TElIMAPClientHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_OnIdle(TElIMAPClientHandle _Handle, TSBIMAPIdleEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_OnIdle(TElIMAPClientHandle _Handle, TSBIMAPIdleEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_OnCertificateChoose(TElIMAPClientHandle _Handle, TSBChooseCertificateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_OnCertificateChoose(TElIMAPClientHandle _Handle, TSBChooseCertificateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_OnCertificateNeededEx(TElIMAPClientHandle _Handle, TSBCertificateNeededExEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_OnCertificateNeededEx(TElIMAPClientHandle _Handle, TSBCertificateNeededExEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_OnCertificateValidate(TElIMAPClientHandle _Handle, TSBCertificateValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_OnCertificateValidate(TElIMAPClientHandle _Handle, TSBCertificateValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_OnCiphersNegotiated(TElIMAPClientHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_OnCiphersNegotiated(TElIMAPClientHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_OnCloseConnection(TElIMAPClientHandle _Handle, TSBCloseConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_OnCloseConnection(TElIMAPClientHandle _Handle, TSBCloseConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_OnError(TElIMAPClientHandle _Handle, TSBErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_OnError(TElIMAPClientHandle _Handle, TSBErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_OnExtensionsReceived(TElIMAPClientHandle _Handle, TSBExtensionsReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_OnExtensionsReceived(TElIMAPClientHandle _Handle, TSBExtensionsReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_OnCertificateStatus(TElIMAPClientHandle _Handle, TSBCertificateStatusEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_OnCertificateStatus(TElIMAPClientHandle _Handle, TSBCertificateStatusEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_OnKeyNeeded(TElIMAPClientHandle _Handle, TSBClientKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_OnKeyNeeded(TElIMAPClientHandle _Handle, TSBClientKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_OnRenegotiationRequest(TElIMAPClientHandle _Handle, TSBRenegotiationRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_OnRenegotiationRequest(TElIMAPClientHandle _Handle, TSBRenegotiationRequestEvent pMethodValue, void * pDataValue);
#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_OnDNSKeyNeeded(TElIMAPClientHandle _Handle, TSBDNSKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_OnDNSKeyNeeded(TElIMAPClientHandle _Handle, TSBDNSKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_OnDNSKeyValidate(TElIMAPClientHandle _Handle, TSBDNSKeyValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_OnDNSKeyValidate(TElIMAPClientHandle _Handle, TSBDNSKeyValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_get_OnDNSResolve(TElIMAPClientHandle _Handle, TSBDNSResolveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_set_OnDNSResolve(TElIMAPClientHandle _Handle, TSBDNSResolveEvent pMethodValue, void * pDataValue);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElIMAPClient_Create(TComponentHandle AOwner, TElIMAPClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELIMAPCLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElIMAPLiteralContext;
class TElIMAPMailBoxState;
class TElIMAPMailBoxInfo;
class TElIMAPMailBoxesList;
class TElIMAPFetchResponseItem;
class TElIMAPFetchResponseLine;
class TElIMAPFetchResponse;
class TElIMAPIdleUpdate;
class TElIMAPIdleThread;
class TElIMAPTimeoutThread;
class TElIMAPClient;
typedef TElIMAPClient ElIMAPClient;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBIMAPAuthorizations)

SB_DEFINE_ENUM_FLAG_OPERATORS(TElIMAPMailBoxAttributes)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBIMAPMessageFlags)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBIMAPStatusItems)

#ifdef SB_USE_CLASS_TELIMAPLITERALCONTEXT
class TElIMAPLiteralContext: public TObject
{
	private:
		SB_DISABLE_COPY(TElIMAPLiteralContext)
	public:
		virtual void get_Line(std::string &OutResult);

		virtual void set_Line(const std::string &Value);

		virtual bool get_IsLiteral();

		virtual void set_IsLiteral(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IsLiteral, set_IsLiteral, TElIMAPLiteralContext, IsLiteral);

		TElIMAPLiteralContext(TElIMAPLiteralContextHandle handle, TElOwnHandle ownHandle);

		explicit TElIMAPLiteralContext(const std::string &Line);

};
#endif /* SB_USE_CLASS_TELIMAPLITERALCONTEXT */

#ifdef SB_USE_CLASS_TELIMAPMAILBOXSTATE
class TElIMAPMailBoxState: public TObject
{
	private:
		SB_DISABLE_COPY(TElIMAPMailBoxState)
	public:
		void Clear();

		void CopyFrom(TElIMAPMailBoxState &Source);

		void CopyFrom(TElIMAPMailBoxState *Source);

		virtual bool get_ReadWrite();

		virtual void set_ReadWrite(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ReadWrite, set_ReadWrite, TElIMAPMailBoxState, ReadWrite);

		virtual int32_t get_TotalMessages();

		virtual void set_TotalMessages(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_TotalMessages, set_TotalMessages, TElIMAPMailBoxState, TotalMessages);

		virtual int32_t get_RecentMessages();

		virtual void set_RecentMessages(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_RecentMessages, set_RecentMessages, TElIMAPMailBoxState, RecentMessages);

		virtual int32_t get_UnseenMessages();

		virtual void set_UnseenMessages(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_UnseenMessages, set_UnseenMessages, TElIMAPMailBoxState, UnseenMessages);

		virtual TSBIMAPMessageFlags get_Flags();

		virtual void set_Flags(TSBIMAPMessageFlags Value);

		SB_DECLARE_PROPERTY(TSBIMAPMessageFlags, get_Flags, set_Flags, TElIMAPMailBoxState, Flags);

		virtual TSBIMAPMessageFlags get_PermanentFlags();

		virtual void set_PermanentFlags(TSBIMAPMessageFlags Value);

		SB_DECLARE_PROPERTY(TSBIMAPMessageFlags, get_PermanentFlags, set_PermanentFlags, TElIMAPMailBoxState, PermanentFlags);

		virtual int32_t get_NextUID();

		virtual void set_NextUID(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_NextUID, set_NextUID, TElIMAPMailBoxState, NextUID);

		virtual int32_t get_UIDValidity();

		virtual void set_UIDValidity(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_UIDValidity, set_UIDValidity, TElIMAPMailBoxState, UIDValidity);

		TElIMAPMailBoxState(TElIMAPMailBoxStateHandle handle, TElOwnHandle ownHandle);

		TElIMAPMailBoxState();

};
#endif /* SB_USE_CLASS_TELIMAPMAILBOXSTATE */

#ifdef SB_USE_CLASS_TELIMAPMAILBOXINFO
class TElIMAPMailBoxInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElIMAPMailBoxInfo)
	public:
		virtual TElIMAPMailBoxAttributes get_Attributes();

		SB_DECLARE_PROPERTY_GET(TElIMAPMailBoxAttributes, get_Attributes, TElIMAPMailBoxInfo, Attributes);

		virtual void get_Delimiter(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Delimiter(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_Name(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Name(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		TElIMAPMailBoxInfo(TElIMAPMailBoxInfoHandle handle, TElOwnHandle ownHandle);

		TElIMAPMailBoxInfo(TElIMAPMailBoxAttributes AAttributes, const sb_u16string &ADelimiter, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElIMAPMailBoxInfo(TElIMAPMailBoxAttributes AAttributes, const std::wstring &ADelimiter, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
};
#endif /* SB_USE_CLASS_TELIMAPMAILBOXINFO */

#ifdef SB_USE_CLASS_TELIMAPMAILBOXESLIST
class TElIMAPMailBoxesList: public TObject
{
	private:
		SB_DISABLE_COPY(TElIMAPMailBoxesList)
	public:
#ifdef SB_USE_CLASS_TELIMAPMAILBOXINFO
		void Add(TElIMAPMailBoxInfo &Item);

		void Add(TElIMAPMailBoxInfo *Item);
#endif /* SB_USE_CLASS_TELIMAPMAILBOXINFO */

#ifdef SB_USE_CLASS_TELIMAPMAILBOXINFO
		TElIMAPMailBoxInfoHandle Get(int32_t Index);
#endif /* SB_USE_CLASS_TELIMAPMAILBOXINFO */

		void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElIMAPMailBoxesList, Count);

		TElIMAPMailBoxesList(TElIMAPMailBoxesListHandle handle, TElOwnHandle ownHandle);

		TElIMAPMailBoxesList();

};
#endif /* SB_USE_CLASS_TELIMAPMAILBOXESLIST */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM
class TElIMAPFetchResponseItem: public TObject
{
	private:
		SB_DISABLE_COPY(TElIMAPFetchResponseItem)
	public:
		void SetData(const std::string &AName, const std::string &AValue);

		virtual TElIMAPFetchResponseItemType get_ItemType();

		SB_DECLARE_PROPERTY_GET(TElIMAPFetchResponseItemType, get_ItemType, TElIMAPFetchResponseItem, ItemType);

		virtual void get_Name(std::string &OutResult);

		virtual void get_RawValue(std::string &OutResult);

		virtual void get_Value(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Value(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual int64_t get_DateTime();

		SB_DECLARE_PROPERTY_GET(int64_t, get_DateTime, TElIMAPFetchResponseItem, DateTime);

		virtual TSBIMAPMessageFlags get_Flags();

		SB_DECLARE_PROPERTY_GET(TSBIMAPMessageFlags, get_Flags, TElIMAPFetchResponseItem, Flags);

		virtual int64_t get_Number();

		SB_DECLARE_PROPERTY_GET(int64_t, get_Number, TElIMAPFetchResponseItem, Number);

		virtual bool get_Streamed();

		SB_DECLARE_PROPERTY_GET(bool, get_Streamed, TElIMAPFetchResponseItem, Streamed);

		TElIMAPFetchResponseItem(TElIMAPFetchResponseItemHandle handle, TElOwnHandle ownHandle);

		TElIMAPFetchResponseItem(const std::string &AName, const std::string &AValue);

};
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSELINE
class TElIMAPFetchResponseLine: public TObject
{
	private:
		SB_DISABLE_COPY(TElIMAPFetchResponseLine)
#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM
		TElIMAPFetchResponseItem* _Inst_Items;
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM
		void Add(TElIMAPFetchResponseItem &Item);

		void Add(TElIMAPFetchResponseItem *Item);
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM
		TElIMAPFetchResponseItemHandle Get(int32_t Index);
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM
		TElIMAPFetchResponseItemHandle GetByName(const std::string &Name);
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM */

		void CopyFrom(TElIMAPFetchResponseLine &Source);

		void CopyFrom(TElIMAPFetchResponseLine *Source);

		void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElIMAPFetchResponseLine, Count);

		virtual int32_t get_ID();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ID, TElIMAPFetchResponseLine, ID);

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM
		virtual TElIMAPFetchResponseItem* get_Items(const std::string &Name);
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM */

		TElIMAPFetchResponseLine(TElIMAPFetchResponseLineHandle handle, TElOwnHandle ownHandle);

		explicit TElIMAPFetchResponseLine(int32_t ID);

		virtual ~TElIMAPFetchResponseLine();

};
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSELINE */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
class TElIMAPFetchResponse: public TObject
{
	private:
		SB_DISABLE_COPY(TElIMAPFetchResponse)
#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSELINE
		TElIMAPFetchResponseLine* _Inst_Lines;
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSELINE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSELINE
		void Add(TElIMAPFetchResponseLine &Line);

		void Add(TElIMAPFetchResponseLine *Line);
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSELINE */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSELINE
		TElIMAPFetchResponseLineHandle Get(int32_t Index);
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSELINE */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSELINE
		TElIMAPFetchResponseLineHandle GetByID(int32_t ID);
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSELINE */

		void Append(TElIMAPFetchResponse &Source);

		void Append(TElIMAPFetchResponse *Source);

		void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElIMAPFetchResponse, Count);

		virtual bool get_UID();

		SB_DECLARE_PROPERTY_GET(bool, get_UID, TElIMAPFetchResponse, UID);

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSELINE
		virtual TElIMAPFetchResponseLine* get_Lines(int32_t Index);
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSELINE */

		TElIMAPFetchResponse(TElIMAPFetchResponseHandle handle, TElOwnHandle ownHandle);

		explicit TElIMAPFetchResponse(bool UID);

		virtual ~TElIMAPFetchResponse();

};
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

#ifdef SB_USE_CLASS_TELIMAPIDLEUPDATE
class TElIMAPIdleUpdate: public TObject
{
	private:
		SB_DISABLE_COPY(TElIMAPIdleUpdate)
#ifdef SB_USE_CLASS_TELIMAPMAILBOXSTATE
		TElIMAPMailBoxState* _Inst_MailBoxState;
#endif /* SB_USE_CLASS_TELIMAPMAILBOXSTATE */
#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
		TElIMAPFetchResponse* _Inst_ChangedMessages;
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */
#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
		TElIMAPFetchResponse* _Inst_ExpungedMessages;
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

		void initInstances();

	public:
		void Add(TElIMAPIdleUpdate &Update);

		void Add(TElIMAPIdleUpdate *Update);

		void Clear();

		virtual TSBIMAPToken get_Token();

		virtual void set_Token(TSBIMAPToken Value);

		SB_DECLARE_PROPERTY(TSBIMAPToken, get_Token, set_Token, TElIMAPIdleUpdate, Token);

#ifdef SB_USE_CLASS_TELIMAPMAILBOXSTATE
		virtual TElIMAPMailBoxState* get_MailBoxState();

		SB_DECLARE_PROPERTY_GET(TElIMAPMailBoxState*, get_MailBoxState, TElIMAPIdleUpdate, MailBoxState);
#endif /* SB_USE_CLASS_TELIMAPMAILBOXSTATE */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
		virtual TElIMAPFetchResponse* get_ChangedMessages();

		SB_DECLARE_PROPERTY_GET(TElIMAPFetchResponse*, get_ChangedMessages, TElIMAPIdleUpdate, ChangedMessages);
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
		virtual TElIMAPFetchResponse* get_ExpungedMessages();

		SB_DECLARE_PROPERTY_GET(TElIMAPFetchResponse*, get_ExpungedMessages, TElIMAPIdleUpdate, ExpungedMessages);
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

		TElIMAPIdleUpdate(TElIMAPIdleUpdateHandle handle, TElOwnHandle ownHandle);

		TElIMAPIdleUpdate();

		virtual ~TElIMAPIdleUpdate();

};
#endif /* SB_USE_CLASS_TELIMAPIDLEUPDATE */

#ifdef SB_USE_CLASS_TELIMAPIDLETHREAD
class TElIMAPIdleThread: public TThread
{
	private:
		SB_DISABLE_COPY(TElIMAPIdleThread)
	public:
		virtual void Execute();

		void Start();

		void WaitStop();

		void TryCallEvents();

		TElIMAPIdleThread(TElIMAPIdleThreadHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELIMAPCLIENT
		explicit TElIMAPIdleThread(TElIMAPClient &Client);

		explicit TElIMAPIdleThread(TElIMAPClient *Client);
#endif /* SB_USE_CLASS_TELIMAPCLIENT */

};
#endif /* SB_USE_CLASS_TELIMAPIDLETHREAD */

#ifdef SB_USE_CLASS_TELIMAPTIMEOUTTHREAD
class TElIMAPTimeoutThread: public TThread
{
	private:
		SB_DISABLE_COPY(TElIMAPTimeoutThread)
	public:
		virtual void Execute();

		void Start();

		void Stop();

		TElIMAPTimeoutThread(TElIMAPTimeoutThreadHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELIMAPCLIENT
		explicit TElIMAPTimeoutThread(TElIMAPClient &Client);

		explicit TElIMAPTimeoutThread(TElIMAPClient *Client);
#endif /* SB_USE_CLASS_TELIMAPCLIENT */

};
#endif /* SB_USE_CLASS_TELIMAPTIMEOUTTHREAD */

#ifdef SB_USE_CLASS_TELIMAPCLIENT
class TElIMAPClient: public TElCustomSimpleSSLClient
{
	private:
		SB_DISABLE_COPY(TElIMAPClient)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Capabilities;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Capabilities;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELIMAPMAILBOXSTATE
		TElIMAPMailBoxState* _Inst_MailBoxState;
#endif /* SB_USE_CLASS_TELIMAPMAILBOXSTATE */

		void initInstances();

	public:
		virtual void Open();

		void ObtainCapabilities();

		void Login();

		virtual void Close(bool Silent);

		void Noop();

#ifdef SB_USE_CLASS_TELIMAPMAILBOXESLIST
		void List(const sb_u16string &RefName, const sb_u16string &MailBox, TElIMAPMailBoxesList &List);

		void List(const sb_u16string &RefName, const sb_u16string &MailBox, TElIMAPMailBoxesList *List);
#ifdef SB_U16STRING_USED
		void List(const std::wstring &RefName, const std::wstring &MailBox, TElIMAPMailBoxesList &List);

		void List(const std::wstring &RefName, const std::wstring &MailBox, TElIMAPMailBoxesList *List);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELIMAPMAILBOXESLIST */

#ifdef SB_USE_CLASS_TELIMAPMAILBOXESLIST
		void LSub(const sb_u16string &RefName, const sb_u16string &MailBox, TElIMAPMailBoxesList &List);

		void LSub(const sb_u16string &RefName, const sb_u16string &MailBox, TElIMAPMailBoxesList *List);
#ifdef SB_U16STRING_USED
		void LSub(const std::wstring &RefName, const std::wstring &MailBox, TElIMAPMailBoxesList &List);

		void LSub(const std::wstring &RefName, const std::wstring &MailBox, TElIMAPMailBoxesList *List);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELIMAPMAILBOXESLIST */

#ifdef SB_USE_CLASS_TELIMAPMAILBOXSTATE
		TElIMAPMailBoxStateHandle SelectBox(const sb_u16string &MailBox);
#ifdef SB_U16STRING_USED
		TElIMAPMailBoxStateHandle SelectBox(const std::wstring &MailBox);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELIMAPMAILBOXSTATE */

#ifdef SB_USE_CLASS_TELIMAPMAILBOXSTATE
		TElIMAPMailBoxStateHandle ExamineBox(const sb_u16string &MailBox);
#ifdef SB_U16STRING_USED
		TElIMAPMailBoxStateHandle ExamineBox(const std::wstring &MailBox);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELIMAPMAILBOXSTATE */

#ifdef SB_USE_CLASS_TELIMAPMAILBOXSTATE
		TElIMAPMailBoxStateHandle StatusBox(const sb_u16string &MailBox, TSBIMAPStatusItems Items);
#ifdef SB_U16STRING_USED
		TElIMAPMailBoxStateHandle StatusBox(const std::wstring &MailBox, TSBIMAPStatusItems Items);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELIMAPMAILBOXSTATE */

		void CloseBox();

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
		TElIMAPFetchResponseHandle Fetch(int32_t First, int32_t Last, bool UID, const std::string &DataItemNames);
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
		TElIMAPFetchResponseHandle Fetch(TElIMAPFetchResponse &Sequence, const std::string &DataItemNames);

		TElIMAPFetchResponseHandle Fetch(TElIMAPFetchResponse *Sequence, const std::string &DataItemNames);
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
		void Store(int32_t First, int32_t Last, bool UID, TSBIMAPStoreFlagsOperation Operation, TSBIMAPMessageFlags Flags, bool Silent, TElIMAPFetchResponse &Response);

		void Store(int32_t First, int32_t Last, bool UID, TSBIMAPStoreFlagsOperation Operation, TSBIMAPMessageFlags Flags, bool Silent, TElIMAPFetchResponse *Response);
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
		void Store(TElIMAPFetchResponse &Sequence, TSBIMAPStoreFlagsOperation Operation, TSBIMAPMessageFlags Flags, bool Silent, TElIMAPFetchResponse &Response);

		void Store(TElIMAPFetchResponse *Sequence, TSBIMAPStoreFlagsOperation Operation, TSBIMAPMessageFlags Flags, bool Silent, TElIMAPFetchResponse *Response);
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
		void Expunge(TElIMAPFetchResponse &Response);

		void Expunge(TElIMAPFetchResponse *Response);
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

		void Copy(int32_t First, int32_t Last, bool UID, const sb_u16string &MailBox);
#ifdef SB_U16STRING_USED
		void Copy(int32_t First, int32_t Last, bool UID, const std::wstring &MailBox);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
		void Copy(TElIMAPFetchResponse &Sequence, const sb_u16string &MailBox);

		void Copy(TElIMAPFetchResponse *Sequence, const sb_u16string &MailBox);
#ifdef SB_U16STRING_USED
		void Copy(TElIMAPFetchResponse &Sequence, const std::wstring &MailBox);

		void Copy(TElIMAPFetchResponse *Sequence, const std::wstring &MailBox);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

#ifdef SB_USE_CLASS_TSTREAM
		void FetchMessage(int32_t ID, bool UID, TStream &Stream);

		void FetchMessage(int32_t ID, bool UID, TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELMESSAGE
		int32_t FetchMessage(int32_t ID, bool UID, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions Options, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool ActivatePartHandlers, TElMessage &Message);
#endif /* SB_USE_CLASS_TELMESSAGE */

		void CreateBox(const sb_u16string &MailBox);
#ifdef SB_U16STRING_USED
		void CreateBox(const std::wstring &MailBox);
#endif /* SB_U16STRING_USED */

		void RenameBox(const sb_u16string &MailBox, const sb_u16string &NewName);
#ifdef SB_U16STRING_USED
		void RenameBox(const std::wstring &MailBox, const std::wstring &NewName);
#endif /* SB_U16STRING_USED */

		void DeleteBox(const sb_u16string &MailBox);
#ifdef SB_U16STRING_USED
		void DeleteBox(const std::wstring &MailBox);
#endif /* SB_U16STRING_USED */

		void Check();

		void SubscribeBox(const sb_u16string &MailBox);
#ifdef SB_U16STRING_USED
		void SubscribeBox(const std::wstring &MailBox);
#endif /* SB_U16STRING_USED */

		void UnsubscribeBox(const sb_u16string &MailBox);
#ifdef SB_U16STRING_USED
		void UnsubscribeBox(const std::wstring &MailBox);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
		TElIMAPFetchResponseHandle Search(bool UID, const sb_u16string &Criteria);
#ifdef SB_U16STRING_USED
		TElIMAPFetchResponseHandle Search(bool UID, const std::wstring &Criteria);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
		TElIMAPFetchResponseHandle Search(bool UID, const std::string &Criteria, const std::string &Charset);
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

		void Idle();

		void IdleDone();

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Capabilities();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Capabilities, TElIMAPClient, Capabilities);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Capabilities();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Capabilities, TElIMAPClient, Capabilities);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual bool get_LoginDisabled();

		SB_DECLARE_PROPERTY_GET(bool, get_LoginDisabled, TElIMAPClient, LoginDisabled);

		virtual void get_MailBox(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_MailBox(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELIMAPMAILBOXSTATE
		virtual TElIMAPMailBoxState* get_MailBoxState();

		SB_DECLARE_PROPERTY_GET(TElIMAPMailBoxState*, get_MailBoxState, TElIMAPClient, MailBoxState);
#endif /* SB_USE_CLASS_TELIMAPMAILBOXSTATE */

		virtual bool get_IdleSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_IdleSupported, TElIMAPClient, IdleSupported);

		virtual bool get_IdleActive();

		SB_DECLARE_PROPERTY_GET(bool, get_IdleActive, TElIMAPClient, IdleActive);

		virtual void get_Address(std::string &OutResult);

		virtual void set_Address(const std::string &Value);

		virtual int32_t get_MaxLineLength();

		virtual void set_MaxLineLength(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxLineLength, set_MaxLineLength, TElIMAPClient, MaxLineLength);

		virtual int32_t get_Port();

		virtual void set_Port(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Port, set_Port, TElIMAPClient, Port);

		virtual TSBSSLMode get_SSLMode();

		virtual void set_SSLMode(TSBSSLMode Value);

		SB_DECLARE_PROPERTY(TSBSSLMode, get_SSLMode, set_SSLMode, TElIMAPClient, SSLMode);

		virtual TSBIMAPAutoCAPAMode get_AutoCAPA();

		virtual void set_AutoCAPA(TSBIMAPAutoCAPAMode Value);

		SB_DECLARE_PROPERTY(TSBIMAPAutoCAPAMode, get_AutoCAPA, set_AutoCAPA, TElIMAPClient, AutoCAPA);

#ifdef SB_WINDOWS
		virtual bool get_UseIPv6();

		virtual void set_UseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseIPv6, set_UseIPv6, TElIMAPClient, UseIPv6);
#endif

		virtual bool get_UseSSL();

		virtual void set_UseSSL(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseSSL, set_UseSSL, TElIMAPClient, UseSSL);

		virtual void get_Username(std::string &OutResult);

		virtual void set_Username(const std::string &Value);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual bool get_IdleAuto();

		virtual void set_IdleAuto(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IdleAuto, set_IdleAuto, TElIMAPClient, IdleAuto);

		virtual int32_t get_IdleTimeout();

		virtual void set_IdleTimeout(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_IdleTimeout, set_IdleTimeout, TElIMAPClient, IdleTimeout);

		virtual void get_OnCapability(TSBIMAPTextLineEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCapability(TSBIMAPTextLineEvent pMethodValue, void * pDataValue);

		virtual void get_OnLog(TSBIMAPLogEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnLog(TSBIMAPLogEvent pMethodValue, void * pDataValue);

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnIdle(TSBIMAPIdleEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnIdle(TSBIMAPIdleEvent pMethodValue, void * pDataValue);

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

		TElIMAPClient(TElIMAPClientHandle handle, TElOwnHandle ownHandle);

		explicit TElIMAPClient(TComponent &AOwner);

		explicit TElIMAPClient(TComponent *AOwner);

		virtual ~TElIMAPClient();

};
#endif /* SB_USE_CLASS_TELIMAPCLIENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBIMAPCLIENT */
