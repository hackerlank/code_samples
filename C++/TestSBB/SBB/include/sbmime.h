#ifndef __INC_SBMIME
#define __INC_SBMIME

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbstrutils.h"
#include "sbstreams.h"
#include "sbchsconv.h"
#include "sbchsconvcharsets.h"
#include "sbchscjk.h"
#include "sbmimestream.h"
#include "sbmimeenc.h"
#include "sbchsconvbase.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_cXMailerPrefix 	"EldoS MIMEBlackbox"
#define SB_cXMailerDefaultFieldValue 	"EldoS MIMEBlackbox, version: 14.0.292.0"
#define SB_EL_OK 	0
#define SB_EL_WARNING 	1
#define SB_EL_BUFFER_TOO_SMALL 	2
#define SB_EL_NULL_POINTER_ERROR 	3
#define SB_EL_FILE_ERROR 	4
#define SB_EL_ALLOC_MEM_ERROR 	5
#define SB_EL_NEXT 	5
#define SB_EL_END 	6
#define SB_EL_BREAK 	7
#define SB_EL_ERROR 	8
#define SB_EL_HANDLERR_ERROR 	9

typedef TElClassHandle TElMessageHandle;

typedef TElMessageHandle ElMessageHandle;

typedef TElClassHandle TElMessageHeaderHandle;

typedef TElMessageHeaderHandle ElMessageHeaderHandle;

typedef TElClassHandle TElMessageHeaderFieldHandle;

typedef TElMessageHeaderFieldHandle ElMessageHeaderFieldHandle;

typedef TElClassHandle TElMailAddressGroupHandle;

typedef TElMailAddressGroupHandle ElMailAddressGroupHandle;

typedef TElClassHandle TElMailAddressListHandle;

typedef TElMailAddressListHandle ElMailAddressListHandle;

typedef TElClassHandle TElMailAddressHandle;

typedef TElMailAddressHandle ElMailAddressHandle;

typedef TElClassHandle TElMessagePartHandle;

typedef TElMessagePartHandle ElMessagePartHandle;

typedef TElClassHandle TElMultiPartListHandle;

typedef TElMultiPartListHandle ElMultiParTElListHandle;

typedef TElClassHandle TElPlainTextPartHandle;

typedef TElPlainTextPartHandle ElPlainTextPartHandle;

typedef TElClassHandle TElMessagePartHandlerHandle;

typedef TElMessagePartHandlerHandle ElMessagePartHandlerHandle;

typedef TElClassHandle TElConverterHandle;

typedef TElConverterHandle ElConverterHandle;

typedef TElClassHandle TElRegisteredMessagePartHandlersHandle;

typedef TElClassHandle TElXmlPartHandle;

typedef uint8_t TElMIMEMessagePriorityRaw;

typedef enum
{
	mpLowest = 0,
	mpLow = 1,
	mpNormal = 2,
	mpHigh = 3,
	mpHighest = 4
} TElMIMEMessagePriority;

typedef TElMIMEMessagePriority ElMIMEMessagePriority;

typedef uint8_t TElHeaderEncodingRaw;

typedef enum
{
	heAutoDetect = 0,
	he8bit = 1,
	heBase64 = 2,
	heQuotedPrintable = 3
} TElHeaderEncoding;

typedef TElHeaderEncoding ElHeaderEncoding;

typedef uint8_t TElMessageParsingOptionRaw;

typedef enum
{
	mpoStoreStream = 0,
	mpoLoadData = 1,
	mpoCalcDataSize = 2,
	mpoRaiseError = 3,
	mpoDelayDataDecode = 4
} TElMessageParsingOption;

typedef uint32_t TElMessageParsingOptionsRaw;

typedef enum 
{
	f_mpoStoreStream = 1,
	f_mpoLoadData = 2,
	f_mpoCalcDataSize = 4,
	f_mpoRaiseError = 8,
	f_mpoDelayDataDecode = 16
} TElMessageParsingOptions;

typedef uint8_t TElMessageExtendedOptionRaw;

typedef enum
{
	meoIgnore7bit = 0,
	meoAllowLongHeaderLines = 1,
	meoCombineHeaderParameters = 2
} TElMessageExtendedOption;

typedef uint32_t TElMessageExtendedOptionsRaw;

typedef enum 
{
	f_meoIgnore7bit = 1,
	f_meoAllowLongHeaderLines = 2,
	f_meoCombineHeaderParameters = 4
} TElMessageExtendedOptions;

typedef TElMessageParsingOption ElMessageParsingOption;

typedef TElMessageParsingOptions ElMessageParsingOptions;

typedef TElMessageExtendedOption ElMessageExtendedOption;

typedef TElMessageExtendedOptions ElMessageExtendedOptions;

typedef uint8_t TElBodyPosRaw;

typedef enum
{
	bpBegin = 0,
	bpEnd = 1
} TElBodyPos;

typedef TElBodyPos ElBodyPos;

typedef uint8_t TElLexTokenRaw;

typedef enum
{
	ltChar = 0,
	ltCRLF = 1,
	ltTabOrSpace = 2,
	ltSpecials = 3,
	ltEos = 4
} TElLexToken;

typedef TElLexToken ElLexToken;

typedef uint8_t TElParseStateRaw;

typedef enum
{
	psMain = 0,
	psFieldValue = 1,
	psComment = 2,
	psQuotedString = 3,
	psParamName = 4,
	psParamValue = 5,
	psGroup = 6,
	psNameAddr = 7,
	psEncodedWord = 8,
	psEnd = 9
} TElParseState;

typedef TElParseState ElParseState;

#pragma pack(4)
typedef struct 
{
	TElParseStateRaw State;
	int8_t _dummy0;
	int16_t _dummy1;
	void * Source;
	int32_t SouceOffset;
	int32_t Offset;
	int32_t Length;
	void * tmpStr;
	int32_t FirstBodyIndex;
} TElParseContext;

typedef TElParseContext ElParseContext;

#pragma pack(4)
typedef struct 
{
	void * Name;
	void * Value;
} TElFieldParam, * PElFieldParam;

typedef TElFieldParam ElFieldParam;

typedef TElClassHandle TElMessagePartClassHandle;

typedef TElClassHandle TElMessagePartHandlerClassHandle;

typedef uint8_t TElOnAssembleStateRaw;

typedef enum
{
	astBefore = 0,
	astAfter = 1,
	astHeaderBefore = 2,
	astHeaderAfter = 3,
	astAddressFieldBefore = 4,
	astAddressFieldItem = 5,
	astAddressFieldAfter = 6,
	astHeaderFieldsBefore = 7,
	astHeaderFieldItem = 8,
	astHeaderFieldsAfter = 9,
	astBodyBefore = 10,
	astBodyAfter = 11,
	astBodyAfterFirstBoundary = 12,
	astBodyPartBefore = 13,
	astBodyPartAfter = 14
} TElOnAssembleState;

typedef TElOnAssembleState ElOnAssembleState;

typedef uint8_t TElOnParseStateRaw;

typedef enum
{
	pstBefore = 0,
	pstAfter = 1,
	pstHeaderBefore = 2,
	pstHeaderAfter = 3,
	pstAddressFieldBefore = 4,
	pstAddressFieldItem = 5,
	pstAddressFieldAfter = 6,
	pstHeaderFieldsBefore = 7,
	pstHeaderFieldItem = 8,
	pstHeaderFieldsAfter = 9,
	pstBodyBefore = 10,
	pstBodyAfter = 11,
	pstBodyAfterFirstBoundary = 12,
	pstBodyPartBefore = 13,
	pstBodyPartAfter = 14,
	pstDecode = 15
} TElOnParseState;

typedef TElOnParseState ElOnParseState;

#ifdef SB_USE_CLASS_TELMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElMessage_GenerateMessageID(sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_GenerateMessageID_1(TElMessageHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_Clear(TElMessageHandle _Handle, int8_t bClearMainPart);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_Assign(TElMessageHandle _Handle, TElMessageHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_ParseMessage(TElMessageHandle _Handle, TStreamHandle Source, const char * pcHeaderCharset, int32_t szHeaderCharset, const char * pcBodyCharset, int32_t szBodyCharset, TElMessageParsingOptionsRaw AOptions, int8_t IgnoreHeaderNativeCharset, int8_t IgnoreBodyNativeCharset, int8_t bActivatePartHandlers, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_AssembleMessage(TElMessageHandle _Handle, TStreamHandle Destination, int8_t bAssembleSource, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_AssembleMessage_1(TElMessageHandle _Handle, TStreamHandle Destination, const char * pcACharset, int32_t szACharset, TElHeaderEncodingRaw HeaderEncoding, const char * pcBodyEncoding, int32_t szBodyEncoding, const char * pcAttachEncoding, int32_t szAttachEncoding, int8_t bAssembleSource, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_GetMessageSentTime(TElMessageHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_GetMessageReceivedTime(TElMessageHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_GetReplyToMailAddress(TElMessageHandle _Handle, TElMailAddressHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_SetCustomHeader(TElMessageHandle _Handle, const sb_char16_t * pcHeaderName, int32_t szHeaderName, const sb_char16_t * pcHeaderValue, int32_t szHeaderValue, TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_SetMessageID(TElMessageHandle _Handle, const sb_char16_t * pcAMessageID, int32_t szAMessageID, TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_SetResentMessageID(TElMessageHandle _Handle, const sb_char16_t * pcAMessageID, int32_t szAMessageID, TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_SetInReplyTo(TElMessageHandle _Handle, const sb_char16_t * pcAInReplyTo, int32_t szAInReplyTo, TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_SetReferences(TElMessageHandle _Handle, const sb_char16_t * pcAReferences, int32_t szAReferences, TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_SetKeywords(TElMessageHandle _Handle, const sb_char16_t * pcAKeywords, int32_t szAKeywords, TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_SetSubject(TElMessageHandle _Handle, const sb_char16_t * pcASubject, int32_t szASubject, TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_SetComments(TElMessageHandle _Handle, const sb_char16_t * pcAComments, int32_t szAComments, TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_GetDate(TElMessageHandle _Handle, int64_t * DateTime, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_SetDate(TElMessageHandle _Handle, int64_t ADateTime, TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_GetResentDate(TElMessageHandle _Handle, int64_t * DateTime, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_SetResentDate(TElMessageHandle _Handle, int64_t DateTime, TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_SetReturnPath(TElMessageHandle _Handle, const sb_char16_t * pcAReturnPath, int32_t szAReturnPath, TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_SetMainPart(TElMessageHandle _Handle, const TElMessagePartHandle AMainPart, int8_t bMakeCopy, TElMessagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_AttachData(TElMessageHandle _Handle, const sb_char16_t * pcContentType, int32_t szContentType, const sb_char16_t * pcFileName, int32_t szFileName, TStreamHandle Stream, int32_t DataSize, int8_t bMakeCopy, TElMessagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_AttachData_1(TElMessageHandle _Handle, const sb_char16_t * pcContentType, int32_t szContentType, const sb_char16_t * pcFileName, int32_t szFileName, const sb_char16_t * pcwsData, int32_t szwsData, TElMessagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_AttachData_2(TElMessageHandle _Handle, const sb_char16_t * pcContentType, int32_t szContentType, const sb_char16_t * pcFileName, int32_t szFileName, const uint8_t pBuffer[], int32_t szBuffer, int32_t Offset, int32_t Count, TElMessagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_AttachFile(TElMessageHandle _Handle, const sb_char16_t * pcContentType, int32_t szContentType, const sb_char16_t * pcFileName, int32_t szFileName, TElMessagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_CustomHeaders(TElMessageHandle _Handle, const sb_char16_t * pcHeaderName, int32_t szHeaderName, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_CustomHeaders(TElMessageHandle _Handle, const sb_char16_t * pcHeaderName, int32_t szHeaderName, const sb_char16_t * pcHeaderValue, int32_t szHeaderValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_MessageID(TElMessageHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_MessageID(TElMessageHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_ResentMessageID(TElMessageHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_InReplyTo(TElMessageHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_References(TElMessageHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_Keywords(TElMessageHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_Subject(TElMessageHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_Comments(TElMessageHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_ReturnPath(TElMessageHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_ReplyTo(TElMessageHandle _Handle, TElMailAddressListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_ReplyTo(TElMessageHandle _Handle, TElMailAddressListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_ResentReplyTo(TElMessageHandle _Handle, TElMailAddressListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_ResentReplyTo(TElMessageHandle _Handle, TElMailAddressListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_From(TElMessageHandle _Handle, TElMailAddressListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_From(TElMessageHandle _Handle, TElMailAddressListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_ResentFrom(TElMessageHandle _Handle, TElMailAddressListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_ResentFrom(TElMessageHandle _Handle, TElMailAddressListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_Sender(TElMessageHandle _Handle, TElMailAddressListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_Sender(TElMessageHandle _Handle, TElMailAddressListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_ResentSender(TElMessageHandle _Handle, TElMailAddressListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_ResentSender(TElMessageHandle _Handle, TElMailAddressListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_To_(TElMessageHandle _Handle, TElMailAddressListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_To_(TElMessageHandle _Handle, TElMailAddressListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_ResentTo(TElMessageHandle _Handle, TElMailAddressListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_ResentTo(TElMessageHandle _Handle, TElMailAddressListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_CC(TElMessageHandle _Handle, TElMailAddressListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_CC(TElMessageHandle _Handle, TElMailAddressListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_ResentCC(TElMessageHandle _Handle, TElMailAddressListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_ResentCC(TElMessageHandle _Handle, TElMailAddressListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_BCC(TElMessageHandle _Handle, TElMailAddressListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_BCC(TElMessageHandle _Handle, TElMailAddressListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_ResentBCC(TElMessageHandle _Handle, TElMailAddressListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_ResentBCC(TElMessageHandle _Handle, TElMailAddressListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_MainPart(TElMessageHandle _Handle, TElMessagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_AttachmentsCount(TElMessageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_Attachments(TElMessageHandle _Handle, int32_t Index, TElMessagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_RequestReadReceipt(TElMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_RequestReadReceipt(TElMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_RequestDeliveryReceipt(TElMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_RequestDeliveryReceipt(TElMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_Priority(TElMessageHandle _Handle, TElMIMEMessagePriorityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_Priority(TElMessageHandle _Handle, TElMIMEMessagePriorityRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_HeaderFieldValues(TElMessageHandle _Handle, const sb_char16_t * pcName, int32_t szName, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_HeaderFields(TElMessageHandle _Handle, const sb_char16_t * pcAName, int32_t szAName, TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_AttachEncoding(TElMessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_AttachEncoding(TElMessageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_BodyEncoding(TElMessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_BodyEncoding(TElMessageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_Charset(TElMessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_Charset(TElMessageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_HeaderEncoding(TElMessageHandle _Handle, TElHeaderEncodingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_HeaderEncoding(TElMessageHandle _Handle, TElHeaderEncodingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_ExtendedOptions(TElMessageHandle _Handle, TElMessageExtendedOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_ExtendedOptions(TElMessageHandle _Handle, TElMessageExtendedOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_MIMEPrefix(TElMessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_MIMEPrefix(TElMessageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_get_DefaultContentType(TElMessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_set_DefaultContentType(TElMessageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_Create(int8_t bCreateMainPart, const sb_char16_t * pcXMailer, int32_t szXMailer, TElMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_Create_1(TElMessagePartClassHandle AMainPartClass, int32_t Fake, const sb_char16_t * pcXMailer, int32_t szXMailer, TElMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_Create_2(TElMessagePartHandle AMainPart, const sb_char16_t * pcXMailer, int32_t szXMailer, TElMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessage_Create_3(const sb_char16_t * pcXMailer, int32_t szXMailer, TElMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELMESSAGE */

#ifdef SB_USE_CLASS_TELMESSAGEHEADER
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_SetField(TElMessageHeaderHandle _Handle, const sb_char16_t * pcName, int32_t szName, const sb_char16_t * pcValue, int32_t szValue, int32_t Index, int8_t ClearParams, TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_Assign(TElMessageHeaderHandle _Handle, const TElMessageHeaderHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_Clear(TElMessageHeaderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_Clone(TElMessageHeaderHandle _Handle, TElMessageHeaderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_AddField(TElMessageHeaderHandle _Handle, const sb_char16_t * pcName, int32_t szName, const sb_char16_t * pcValue, int32_t szValue, int8_t bOverride, TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_DeleteField(TElMessageHeaderHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_DeleteField_1(TElMessageHeaderHandle _Handle, const sb_char16_t * pcName, int32_t szName, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_GetField(TElMessageHeaderHandle _Handle, int32_t Index, TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_GetField_1(TElMessageHeaderHandle _Handle, const sb_char16_t * pcName, int32_t szName, int32_t Index, TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_FieldExists(TElMessageHeaderHandle _Handle, const sb_char16_t * pcName, int32_t szName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_AddMailAddressList(TElMessageHeaderHandle _Handle, const TElMailAddressListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_DeleteMailAddressList(TElMessageHeaderHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_DeleteMailAddressList_1(TElMessageHeaderHandle _Handle, const sb_char16_t * pcName, int32_t szName, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_GetMailAddressList(TElMessageHeaderHandle _Handle, int32_t Index, TElMailAddressListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_GetMailAddressList_1(TElMessageHeaderHandle _Handle, const sb_char16_t * pcName, int32_t szName, int32_t Index, TElMailAddressListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_Assemble(TElMessageHeaderHandle _Handle, char * pcsResult, int32_t * szsResult, const char * pcCharset, int32_t szCharset, TElHeaderEncodingRaw Encoding, TElMessagePartHandlerHandle MessagePartHandler, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_Parse(TElMessageHeaderHandle _Handle, const char * pcASource, int32_t szASource, char * pcCharset, int32_t * szCharset, int8_t IgnoreNativeCharset, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_get_AddressList(TElMessageHeaderHandle _Handle, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_get_AllowLongLines(TElMessageHeaderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_set_AllowLongLines(TElMessageHeaderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_get_BodyLen(TElMessageHeaderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_set_BodyLen(TElMessageHeaderHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_get_FieldsCount(TElMessageHeaderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_get_HeaderFields(TElMessageHeaderHandle _Handle, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_get_MailAddressListCount(TElMessageHeaderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_get_StreamPosBegin(TElMessageHeaderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_set_StreamPosBegin(TElMessageHeaderHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_get_ParseAddresses(TElMessageHeaderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_set_ParseAddresses(TElMessageHeaderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_get_CombineParameters(TElMessageHeaderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_set_CombineParameters(TElMessageHeaderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeader_Create(TElMessageHeaderHandle * OutResult);
#endif /* SB_USE_CLASS_TELMESSAGEHEADER */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_Clear(TElMessageHeaderFieldHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_Clone(TElMessageHeaderFieldHandle _Handle, TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_AddParam(TElMessageHeaderFieldHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcParamValue, int32_t szParamValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_ClearParams(TElMessageHeaderFieldHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_DeleteParam(TElMessageHeaderFieldHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_DeleteParam_1(TElMessageHeaderFieldHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_GetParamIndexByName(TElMessageHeaderFieldHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_GetParamName(TElMessageHeaderFieldHandle _Handle, int32_t Index, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_GetParamValue(TElMessageHeaderFieldHandle _Handle, int32_t Index, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_GetParamValue_1(TElMessageHeaderFieldHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_ParamExists(TElMessageHeaderFieldHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_SetParamValue(TElMessageHeaderFieldHandle _Handle, int32_t Index, const sb_char16_t * pcwsValue, int32_t szwsValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_SetParamValue_1(TElMessageHeaderFieldHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcwsValue, int32_t szwsValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_get_Body(TElMessageHeaderFieldHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_set_Body(TElMessageHeaderFieldHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_get_Comments(TElMessageHeaderFieldHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_set_Comments(TElMessageHeaderFieldHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_get_EncodedWords(TElMessageHeaderFieldHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_set_EncodedWords(TElMessageHeaderFieldHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_get_QuotedParams(TElMessageHeaderFieldHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_set_QuotedParams(TElMessageHeaderFieldHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_get_Name(TElMessageHeaderFieldHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_set_Name(TElMessageHeaderFieldHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_get_ParamsCount(TElMessageHeaderFieldHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_get_Value(TElMessageHeaderFieldHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_set_Value(TElMessageHeaderFieldHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_Create(TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_Create_1(const sb_char16_t * pcAName, int32_t szAName, const sb_char16_t * pcAValue, int32_t szAValue, TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageHeaderField_Create_2(const char * pcSource, int32_t szSource, int32_t * Offset, const char * pcCharset, int32_t szCharset, int8_t IgnoreNativeCharset, TElMessageHeaderFieldHandle * OutResult);
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMAILADDRESSGROUP
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressGroup_AddAddress(TElMailAddressGroupHandle _Handle, const sb_char16_t * pcAAlias, int32_t szAAlias, const sb_char16_t * pcAAddress, int32_t szAAddress, TElMailAddressHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressGroup_Clear(TElMailAddressGroupHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressGroup_Clone(TElMailAddressGroupHandle _Handle, TElMailAddressGroupHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressGroup_DeleteAddress(TElMailAddressGroupHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressGroup_IndexOfAddress(TElMailAddressGroupHandle _Handle, TElMailAddressHandle AAddress, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressGroup_get_Name(TElMailAddressGroupHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressGroup_set_Name(TElMailAddressGroupHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressGroup_get_AddressesCount(TElMailAddressGroupHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressGroup_get_Address(TElMailAddressGroupHandle _Handle, int32_t Index, TElMailAddressHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressGroup_Create(TElMailAddressGroupHandle * OutResult);
#endif /* SB_USE_CLASS_TELMAILADDRESSGROUP */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressList_Clear(TElMailAddressListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressList_Clone(TElMailAddressListHandle _Handle, TElMailAddressListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressList_Assemble(TElMailAddressListHandle _Handle, const sb_char16_t * pcFieldName, int32_t szFieldName, char * pcsResult, int32_t * szsResult, const char * pcCharset, int32_t szCharset, TElHeaderEncodingRaw Encoding, int8_t AllowLongHeaderLines, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressList_Parse(TElMailAddressListHandle _Handle, const sb_char16_t * pcwsSource, int32_t szwsSource, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressList_Parse_1(TElMailAddressListHandle _Handle, const sb_char16_t * pcwsSource, int32_t szwsSource, const char * pcCharset, int32_t szCharset, int8_t IgnoreNativeCharset, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressList_AddAddress(TElMailAddressListHandle _Handle, const sb_char16_t * pcAlias, int32_t szAlias, const sb_char16_t * pcAddress, int32_t szAddress, TElMailAddressHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressList_DeleteAddress(TElMailAddressListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressList_GetAddress(TElMailAddressListHandle _Handle, int32_t Index, TElMailAddressHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressList_IndexOfAddress(TElMailAddressListHandle _Handle, TElMailAddressHandle Address, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressList_AddGroup(TElMailAddressListHandle _Handle, TElMailAddressGroupHandle Group, int8_t bMakeCopy, TElMailAddressGroupHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressList_DeleteGroup(TElMailAddressListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressList_DeleteGroup_1(TElMailAddressListHandle _Handle, const sb_char16_t * pcGroupName, int32_t szGroupName);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressList_GetGroup(TElMailAddressListHandle _Handle, int32_t Index, TElMailAddressGroupHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressList_GetGroupName(TElMailAddressListHandle _Handle, int32_t Index, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressList_GetAddressFromAll(TElMailAddressListHandle _Handle, int32_t Index, TElMailAddressHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressList_get_Count(TElMailAddressListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressList_get_FieldName(TElMailAddressListHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressList_set_FieldName(TElMailAddressListHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressList_get_GroupsCount(TElMailAddressListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressList_get_TotalCount(TElMailAddressListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressList_Create(TElMailAddressListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddressList_Create_1(const sb_char16_t * pcSource, int32_t szSource, TElMailAddressListHandle * OutResult);
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESS
SB_IMPORT uint32_t SB_APIENTRY TElMailAddress_Clear(TElMailAddressHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddress_Clone(TElMailAddressHandle _Handle, TElMailAddressHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddress_IsAddress(TElMailAddressHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddress_IsAlias(TElMailAddressHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddress_get_Alias(TElMailAddressHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddress_set_Alias(TElMailAddressHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddress_get_Address(TElMailAddressHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddress_set_Address(TElMailAddressHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddress_get_Comments(TElMailAddressHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddress_set_Comments(TElMailAddressHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddress_Create(TElMailAddressHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMailAddress_Create_1(const sb_char16_t * pcAAlias, int32_t szAAlias, const sb_char16_t * pcAAddress, int32_t szAAddress, TElMailAddressHandle * OutResult);
#endif /* SB_USE_CLASS_TELMAILADDRESS */

#ifdef SB_USE_CLASS_TELMESSAGEPART
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_CreatePartForHeader(TElMessageHeaderHandle Header, TElMessageHandle AMessage, TElMessagePartHandle AParent, TElMessagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_CreatePartForHeader_1(TElMessagePartHandle _Handle, TElMessageHeaderHandle Header, TElMessageHandle AMessage, TElMessagePartHandle AParent, TElMessagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_Assign(TElMessagePartHandle _Handle, TElMessagePartHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_Clear(TElMessagePartHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_Clone(TElMessagePartHandle _Handle, TElMessagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_Parse(TElMessagePartHandle _Handle, TElMessageHeaderHandle Header, TStreamHandle Source, const char * pcBoundary, int32_t szBoundary, const char * pcHeaderCharset, int32_t szHeaderCharset, const char * pcBodyCharset, int32_t szBodyCharset, TElMessageParsingOptionsRaw AOptions, int8_t IgnoreHeaderNativeCharset, int8_t IgnoreBodyNativeCharset, int8_t bActivatePartHandlers, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_Assemble(TElMessagePartHandle _Handle, TStreamHandle Destination, const char * pcCharset, int32_t szCharset, TElHeaderEncodingRaw HeaderEncoding, const char * pcBodyEncoding, int32_t szBodyEncoding, const char * pcAttachEncoding, int32_t szAttachEncoding, int8_t bAssembleSource, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_IsText(TElMessagePartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_IsTextPlain(TElMessagePartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_IsTextHtml(TElMessagePartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_IsMessage(TElMessagePartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_IsImage(TElMessagePartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_IsAudio(TElMessagePartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_IsVideo(TElMessagePartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_IsMultipart(TElMessagePartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_IsAttachment(TElMessagePartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_IsInline(TElMessagePartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_IsApplication(TElMessagePartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_SetFieldValue(TElMessagePartHandle _Handle, const sb_char16_t * pcName, int32_t szName, const sb_char16_t * pcValue, int32_t szValue, int8_t ClearParams);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_SetContentType(TElMessagePartHandle _Handle, const sb_char16_t * pcAValue, int32_t szAValue, int8_t ClearParams);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_SetContentSubtype(TElMessagePartHandle _Handle, const sb_char16_t * pcAValue, int32_t szAValue, int8_t ClearParams);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_SetContentTransferEncoding(TElMessagePartHandle _Handle, const sb_char16_t * pcAValue, int32_t szAValue, int8_t ClearParams);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_SetContentID(TElMessagePartHandle _Handle, const sb_char16_t * pcAValue, int32_t szAValue, int8_t ClearParams);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_SetContentDisposition(TElMessagePartHandle _Handle, const sb_char16_t * pcAValue, int32_t szAValue, int8_t ClearParams);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_SetContentDescription(TElMessagePartHandle _Handle, const sb_char16_t * pcAValue, int32_t szAValue, int8_t ClearParams);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_GetDataSize(TElMessagePartHandle _Handle, int32_t * Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_GetData(TElMessagePartHandle _Handle, sb_char16_t * pcwsData, int32_t * szwsData, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_GetData_1(TElMessagePartHandle _Handle, uint8_t pBuffer[], int32_t * szBuffer, int32_t * BufferSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_SaveDataToStream(TElMessagePartHandle _Handle, TStreamHandle Stream, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_SaveDataToFile(TElMessagePartHandle _Handle, const sb_char16_t * pcwsFileName, int32_t szwsFileName, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_SetData(TElMessagePartHandle _Handle, TStreamHandle Stream, int32_t DataSize, int8_t bMakeCopy);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_SetData_1(TElMessagePartHandle _Handle, const sb_char16_t * pcwsData, int32_t szwsData);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_SetData_2(TElMessagePartHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Offset, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_GetText(TElMessagePartHandle _Handle, sb_char16_t * pcAText, int32_t * szAText, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_SetText(TElMessagePartHandle _Handle, const sb_char16_t * pcAText, int32_t szAText);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_GetPart(TElMessagePartHandle _Handle, int32_t Index, TElMessagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_AddPart(TElMessagePartHandle _Handle, TElMessagePartHandle Part, int8_t bMakeCopy, int32_t PartIndex, TElMessagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_AddPart_1(TElMessagePartHandle _Handle, TElMessagePartHandle Part);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_DeletePart(TElMessagePartHandle _Handle, int32_t Index, int8_t bDestroy);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_DeletePart_1(TElMessagePartHandle _Handle, TElMessagePartHandle Part, int8_t bDestroy);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_BodyLen(TElMessagePartHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_Stream(TElMessagePartHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_StreamPosBegin(TElMessagePartHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_Data(TElMessagePartHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_set_Data(TElMessagePartHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_DataStream(TElMessagePartHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_set_DataStream(TElMessagePartHandle _Handle, TStreamHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_DataSize(TElMessagePartHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_set_DataSize(TElMessagePartHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_Options(TElMessagePartHandle _Handle, TElMessageParsingOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_set_Options(TElMessagePartHandle _Handle, TElMessageParsingOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_DisposeStream(TElMessagePartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_set_DisposeStream(TElMessagePartHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_DisposeDataStream(TElMessagePartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_set_DisposeDataStream(TElMessagePartHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_Header(TElMessagePartHandle _Handle, TElMessageHeaderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_Parent(TElMessagePartHandle _Handle, TElMessagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_ParentMessage(TElMessagePartHandle _Handle, TElMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_HeaderFields(TElMessagePartHandle _Handle, const sb_char16_t * pcwsFieldName, int32_t szwsFieldName, TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_HeaderContentTypeField(TElMessagePartHandle _Handle, TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_HeaderContentDispositionField(TElMessagePartHandle _Handle, TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_HeaderContentTransferEncodingField(TElMessagePartHandle _Handle, TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_HeaderContentLocationField(TElMessagePartHandle _Handle, TElMessageHeaderFieldHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_ContentType(TElMessagePartHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_ContentSubtype(TElMessagePartHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_ContentTransferEncoding(TElMessagePartHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_ContentID(TElMessagePartHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_ContentDisposition(TElMessagePartHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_ContentDescription(TElMessagePartHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_FileName(TElMessagePartHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_set_FileName(TElMessagePartHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_CharSet(TElMessagePartHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_set_CharSet(TElMessagePartHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_HeaderCharSet(TElMessagePartHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_BodyCharSet(TElMessagePartHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_PartsCount(TElMessagePartHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_AttachmentsCount(TElMessagePartHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_Attachments(TElMessagePartHandle _Handle, int32_t Index, TElMessagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_MessagePartHandler(TElMessagePartHandle _Handle, TElMessagePartHandlerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_set_MessagePartHandler(TElMessagePartHandle _Handle, TElMessagePartHandlerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_MessageBodyPartHandler(TElMessagePartHandle _Handle, TElMessagePartHandlerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_set_MessageBodyPartHandler(TElMessagePartHandle _Handle, TElMessagePartHandlerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_get_IsActivatedMessagePartHandler(TElMessagePartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_Create(TElMessagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePart_Create_1(TElMessageHandle AMessage, TElMessagePartHandle AParent, TElMessagePartHandle * OutResult);
#endif /* SB_USE_CLASS_TELMESSAGEPART */

#ifdef SB_USE_CLASS_TELMULTIPARTLIST
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_Assign(TElMultiPartListHandle _Handle, TElMessagePartHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_Clear(TElMultiPartListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_Clone(TElMultiPartListHandle _Handle, TElMessagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_Parse(TElMultiPartListHandle _Handle, TElMessageHeaderHandle AHeader, TStreamHandle Source, const char * pcBoundary, int32_t szBoundary, const char * pcHeaderCharset, int32_t szHeaderCharset, const char * pcBodyCharset, int32_t szBodyCharset, TElMessageParsingOptionsRaw AOptions, int8_t IgnoreHeaderNativeCharset, int8_t IgnoreBodyNativeCharset, int8_t bActivatePartHandlers, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_Assemble(TElMultiPartListHandle _Handle, TStreamHandle Destination, const char * pcCharset, int32_t szCharset, TElHeaderEncodingRaw HeaderEncoding, const char * pcBodyEncoding, int32_t szBodyEncoding, const char * pcAttachEncoding, int32_t szAttachEncoding, int8_t bAssembleSource, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_GetPart(TElMultiPartListHandle _Handle, int32_t Index, TElMessagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_AddPart(TElMultiPartListHandle _Handle, TElMessagePartHandle Part, int8_t bMakeCopy, int32_t PartIndex, TElMessagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_DeletePart(TElMultiPartListHandle _Handle, int32_t Index, int8_t bDestroy);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_DeletePart_1(TElMultiPartListHandle _Handle, TElMessagePartHandle Part, int8_t bDestroy);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_IsText(TElMultiPartListHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_IsTextPlain(TElMultiPartListHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_IsMessage(TElMultiPartListHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_IsImage(TElMultiPartListHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_IsAudio(TElMultiPartListHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_IsVideo(TElMultiPartListHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_IsMultipart(TElMultiPartListHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_GetDataSize(TElMultiPartListHandle _Handle, int32_t * Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_GetData(TElMultiPartListHandle _Handle, sb_char16_t * pcwsData, int32_t * szwsData, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_GetData_1(TElMultiPartListHandle _Handle, uint8_t pBuffer[], int32_t * szBuffer, int32_t * BufferSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_SetData(TElMultiPartListHandle _Handle, TStreamHandle Stream, int32_t DataSize, int8_t bMakeCopy);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_SetData_1(TElMultiPartListHandle _Handle, const sb_char16_t * pcwsData, int32_t szwsData);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_SetData_2(TElMultiPartListHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Offset, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_GenerateBoundary(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_GenerateBoundary_1(TElMultiPartListHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_get_Boundary(TElMultiPartListHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_set_Boundary(TElMultiPartListHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_Create(TElMultiPartListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiPartList_Create_1(TElMessageHandle AMessage, TElMessagePartHandle AParent, TElMultiPartListHandle * OutResult);
#endif /* SB_USE_CLASS_TELMULTIPARTLIST */

#ifdef SB_USE_CLASS_TELPLAINTEXTPART
SB_IMPORT uint32_t SB_APIENTRY TElPlainTextPart_Clone(TElPlainTextPartHandle _Handle, TElMessagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlainTextPart_Assign(TElPlainTextPartHandle _Handle, TElMessagePartHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElPlainTextPart_Parse(TElPlainTextPartHandle _Handle, TElMessageHeaderHandle Header, TStreamHandle Source, const char * pcBoundary, int32_t szBoundary, const char * pcHeaderCharset, int32_t szHeaderCharset, const char * pcBodyCharset, int32_t szBodyCharset, TElMessageParsingOptionsRaw AOptions, int8_t IgnoreHeaderNativeCharset, int8_t IgnoreBodyNativeCharset, int8_t bActivatePartHandlers, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlainTextPart_Assemble(TElPlainTextPartHandle _Handle, TStreamHandle Destination, const char * pcCharset, int32_t szCharset, TElHeaderEncodingRaw HeaderEncoding, const char * pcBodyEncoding, int32_t szBodyEncoding, const char * pcAttachEncoding, int32_t szAttachEncoding, int8_t bAssembleSource, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlainTextPart_GetText(TElPlainTextPartHandle _Handle, sb_char16_t * pcAText, int32_t * szAText, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlainTextPart_SetText(TElPlainTextPartHandle _Handle, const sb_char16_t * pcAText, int32_t szAText);
SB_IMPORT uint32_t SB_APIENTRY TElPlainTextPart_IsText(TElPlainTextPartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlainTextPart_IsTextPlain(TElPlainTextPartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlainTextPart_IsMessage(TElPlainTextPartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlainTextPart_IsImage(TElPlainTextPartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlainTextPart_IsAudio(TElPlainTextPartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlainTextPart_IsVideo(TElPlainTextPartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlainTextPart_IsMultipart(TElPlainTextPartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlainTextPart_IsAttachment(TElPlainTextPartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlainTextPart_GetDataSize(TElPlainTextPartHandle _Handle, int32_t * Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlainTextPart_GetData(TElPlainTextPartHandle _Handle, sb_char16_t * pcwsData, int32_t * szwsData, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlainTextPart_GetData_1(TElPlainTextPartHandle _Handle, uint8_t pBuffer[], int32_t * szBuffer, int32_t * BufferSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlainTextPart_SetData(TElPlainTextPartHandle _Handle, TStreamHandle Stream, int32_t DataSize, int8_t bMakeCopy);
SB_IMPORT uint32_t SB_APIENTRY TElPlainTextPart_SetData_1(TElPlainTextPartHandle _Handle, const sb_char16_t * pcwsData, int32_t szwsData);
SB_IMPORT uint32_t SB_APIENTRY TElPlainTextPart_SetData_2(TElPlainTextPartHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Offset, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElPlainTextPart_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlainTextPart_Create(TElPlainTextPartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlainTextPart_Create_1(TElMessageHandle AMessage, TElMessagePartHandle AParent, TElPlainTextPartHandle * OutResult);
#endif /* SB_USE_CLASS_TELPLAINTEXTPART */

#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandler_Decode(TElMessagePartHandlerHandle _Handle, int8_t bActivatePartHandlers, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandler_GetDescription(sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandler_GetDescription_1(TElMessagePartHandlerHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandler_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandler_get_DecodedPart(TElMessagePartHandlerHandle _Handle, TElMessagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandler_set_DecodedPart(TElMessagePartHandlerHandle _Handle, TElMessagePartHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandler_get_IsDecoderActivated(TElMessagePartHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandler_get_IsError(TElMessagePartHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandler_get_ErrorText(TElMessagePartHandlerHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandler_get_ResultCode(TElMessagePartHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandler_Create(TObjectHandle aParams, TElMessagePartHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLER */

#ifdef SB_USE_CLASS_TELCONVERTER
SB_IMPORT uint32_t SB_APIENTRY TElConverter_Convert(TElConverterHandle _Handle, TStreamHandle Source, TStreamHandle Dest, TPlConvertOptionsRaw Options, int32_t MaxChars, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElConverter_Convert_1(TElConverterHandle _Handle, const char * pcSource, int32_t szSource, sb_char16_t * pcDest, int32_t * szDest, TPlConvertOptionsRaw Options, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElConverter_Create(TPlConverterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElConverter_Create_1(const char * pcSrcCharset, int32_t szSrcCharset, const char * pcDstCharset, int32_t szDstCharset, TPlConverterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElConverter_Create_2(IPlCharsetHandle SrcCharset, IPlCharsetHandle DstCharset, TPlConverterHandle * OutResult);
#endif /* SB_USE_CLASS_TELCONVERTER */

#ifdef SB_USE_CLASS_TELREGISTEREDMESSAGEPARTHANDLERS
SB_IMPORT uint32_t SB_APIENTRY TElRegisteredMessagePartHandlers_AddHandler(TElRegisteredMessagePartHandlersHandle _Handle, TElMessagePartHandlerClassHandle hc);
SB_IMPORT uint32_t SB_APIENTRY TElRegisteredMessagePartHandlers_GetHandlersCount(TElRegisteredMessagePartHandlersHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRegisteredMessagePartHandlers_GetHandlerClass(TElRegisteredMessagePartHandlersHandle _Handle, int32_t Index, TElMessagePartHandlerClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRegisteredMessagePartHandlers_RemoveHandler(TElRegisteredMessagePartHandlersHandle _Handle, TElMessagePartHandlerClassHandle hc);
SB_IMPORT uint32_t SB_APIENTRY TElRegisteredMessagePartHandlers_Create(TElRegisteredMessagePartHandlersHandle * OutResult);
#endif /* SB_USE_CLASS_TELREGISTEREDMESSAGEPARTHANDLERS */

#ifdef SB_USE_CLASS_TELXMLPART
SB_IMPORT uint32_t SB_APIENTRY TElXmlPart_Assemble(TElXmlPartHandle _Handle, TStreamHandle Destination, const char * pcCharset, int32_t szCharset, TElHeaderEncodingRaw HeaderEncoding, const char * pcBodyEncoding, int32_t szBodyEncoding, const char * pcAttachEncoding, int32_t szAttachEncoding, int8_t bAssembleSource, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXmlPart_Clone(TElXmlPartHandle _Handle, TElMessagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXmlPart_IsText(TElXmlPartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXmlPart_IsTextPlain(TElXmlPartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXmlPart_IsTextHtml(TElXmlPartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXmlPart_IsMessage(TElXmlPartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXmlPart_IsImage(TElXmlPartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXmlPart_IsAudio(TElXmlPartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXmlPart_IsVideo(TElXmlPartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXmlPart_IsMultipart(TElXmlPartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXmlPart_Parse(TElXmlPartHandle _Handle, TElMessageHeaderHandle Header, TStreamHandle Source, const char * pcBoundary, int32_t szBoundary, const char * pcHeaderCharset, int32_t szHeaderCharset, const char * pcBodyCharset, int32_t szBodyCharset, TElMessageParsingOptionsRaw AOptions, int8_t IgnoreHeaderNativeCharset, int8_t IgnoreBodyNativeCharset, int8_t bActivatePartHandlers, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXmlPart_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXmlPart_Create(TElXmlPartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXmlPart_Create_1(TElMessageHandle AMessage, TElMessagePartHandle AParent, TElXmlPartHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLPART */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElMessage;
typedef TElMessage ElMessage;
class TElMessageHeader;
typedef TElMessageHeader ElMessageHeader;
class TElMessageHeaderField;
typedef TElMessageHeaderField ElMessageHeaderField;
class TElMailAddressGroup;
typedef TElMailAddressGroup ElMailAddressGroup;
class TElMailAddressList;
typedef TElMailAddressList ElMailAddressList;
class TElMailAddress;
typedef TElMailAddress ElMailAddress;
class TElMessagePart;
typedef TElMessagePart ElMessagePart;
class TElMultiPartList;
typedef TElMultiPartList ElMultiParTElList;
class TElPlainTextPart;
typedef TElPlainTextPart ElPlainTextPart;
class TElMessagePartHandler;
typedef TElMessagePartHandler ElMessagePartHandler;
class TElConverter;
typedef TElConverter ElConverter;
class TElRegisteredMessagePartHandlers;
class TElXmlPart;

SB_DEFINE_ENUM_FLAG_OPERATORS(TElMessageParsingOptions)

SB_DEFINE_ENUM_FLAG_OPERATORS(TElMessageExtendedOptions)

#ifdef SB_USE_CLASS_TELMESSAGE
class TElMessage: public TObject
{
	private:
		SB_DISABLE_COPY(TElMessage)
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		TElMailAddressList* _Inst_ReplyTo;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		TElMailAddressList* _Inst_ResentReplyTo;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		TElMailAddressList* _Inst_From;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		TElMailAddressList* _Inst_ResentFrom;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		TElMailAddressList* _Inst_Sender;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		TElMailAddressList* _Inst_ResentSender;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		TElMailAddressList* _Inst_To_;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		TElMailAddressList* _Inst_ResentTo;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		TElMailAddressList* _Inst_CC;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		TElMailAddressList* _Inst_ResentCC;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		TElMailAddressList* _Inst_BCC;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		TElMailAddressList* _Inst_ResentBCC;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMESSAGEPART
		TElMessagePart* _Inst_MainPart;
#endif /* SB_USE_CLASS_TELMESSAGEPART */
#ifdef SB_USE_CLASS_TELMESSAGEPART
		TElMessagePart* _Inst_Attachments;
#endif /* SB_USE_CLASS_TELMESSAGEPART */
#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		TElMessageHeaderField* _Inst_HeaderFields;
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

		void initInstances();

	public:
		static void GenerateMessageID(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		static void GenerateMessageID(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		void GenerateMessageID_Inst(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		void GenerateMessageID_Inst(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		virtual void Clear(bool bClearMainPart);

		void Assign(TElMessage &Source);

		void Assign(TElMessage *Source);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t ParseMessage(TStream &Source, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions AOptions, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool bActivatePartHandlers);

		int32_t ParseMessage(TStream *Source, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions AOptions, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool bActivatePartHandlers);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t AssembleMessage(TStream &Destination, bool bAssembleSource);

		virtual int32_t AssembleMessage(TStream *Destination, bool bAssembleSource);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t AssembleMessage(TStream &Destination, const std::string &ACharset, TElHeaderEncoding HeaderEncoding, const std::string &BodyEncoding, const std::string &AttachEncoding, bool bAssembleSource);

		virtual int32_t AssembleMessage(TStream *Destination, const std::string &ACharset, TElHeaderEncoding HeaderEncoding, const std::string &BodyEncoding, const std::string &AttachEncoding, bool bAssembleSource);
#endif /* SB_USE_CLASS_TSTREAM */

		int64_t GetMessageSentTime();

		int64_t GetMessageReceivedTime();

#ifdef SB_USE_CLASS_TELMAILADDRESS
		TElMailAddressHandle GetReplyToMailAddress();
#endif /* SB_USE_CLASS_TELMAILADDRESS */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		TElMessageHeaderFieldHandle SetCustomHeader(const sb_u16string &HeaderName, const sb_u16string &HeaderValue);
#ifdef SB_U16STRING_USED
		TElMessageHeaderFieldHandle SetCustomHeader(const std::wstring &HeaderName, const std::wstring &HeaderValue);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		TElMessageHeaderFieldHandle SetMessageID(const sb_u16string &AMessageID);
#ifdef SB_U16STRING_USED
		TElMessageHeaderFieldHandle SetMessageID(const std::wstring &AMessageID);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		TElMessageHeaderFieldHandle SetResentMessageID(const sb_u16string &AMessageID);
#ifdef SB_U16STRING_USED
		TElMessageHeaderFieldHandle SetResentMessageID(const std::wstring &AMessageID);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		TElMessageHeaderFieldHandle SetInReplyTo(const sb_u16string &AInReplyTo);
#ifdef SB_U16STRING_USED
		TElMessageHeaderFieldHandle SetInReplyTo(const std::wstring &AInReplyTo);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		TElMessageHeaderFieldHandle SetReferences(const sb_u16string &AReferences);
#ifdef SB_U16STRING_USED
		TElMessageHeaderFieldHandle SetReferences(const std::wstring &AReferences);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		TElMessageHeaderFieldHandle SetKeywords(const sb_u16string &AKeywords);
#ifdef SB_U16STRING_USED
		TElMessageHeaderFieldHandle SetKeywords(const std::wstring &AKeywords);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		TElMessageHeaderFieldHandle SetSubject(const sb_u16string &ASubject);
#ifdef SB_U16STRING_USED
		TElMessageHeaderFieldHandle SetSubject(const std::wstring &ASubject);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		TElMessageHeaderFieldHandle SetComments(const sb_u16string &AComments);
#ifdef SB_U16STRING_USED
		TElMessageHeaderFieldHandle SetComments(const std::wstring &AComments);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

		bool GetDate(int64_t &DateTime);

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		TElMessageHeaderFieldHandle SetDate(int64_t ADateTime);
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

		bool GetResentDate(int64_t &DateTime);

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		TElMessageHeaderFieldHandle SetResentDate(int64_t DateTime);
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		TElMessageHeaderFieldHandle SetReturnPath(const sb_u16string &AReturnPath);
#ifdef SB_U16STRING_USED
		TElMessageHeaderFieldHandle SetReturnPath(const std::wstring &AReturnPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEPART
		TElMessagePartHandle SetMainPart(const TElMessagePart &AMainPart, bool bMakeCopy);

		TElMessagePartHandle SetMainPart(const TElMessagePart *AMainPart, bool bMakeCopy);
#endif /* SB_USE_CLASS_TELMESSAGEPART */

#ifdef SB_USE_CLASSES_TELMESSAGEPART_AND_TSTREAM
		TElMessagePartHandle AttachData(const sb_u16string &ContentType, const sb_u16string &FileName, TStream &Stream, int32_t DataSize, bool bMakeCopy);

		TElMessagePartHandle AttachData(const sb_u16string &ContentType, const sb_u16string &FileName, TStream *Stream, int32_t DataSize, bool bMakeCopy);
#ifdef SB_U16STRING_USED
		TElMessagePartHandle AttachData(const std::wstring &ContentType, const std::wstring &FileName, TStream &Stream, int32_t DataSize, bool bMakeCopy);

		TElMessagePartHandle AttachData(const std::wstring &ContentType, const std::wstring &FileName, TStream *Stream, int32_t DataSize, bool bMakeCopy);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELMESSAGEPART_AND_TSTREAM */

#ifdef SB_USE_CLASS_TELMESSAGEPART
		TElMessagePartHandle AttachData(const sb_u16string &ContentType, const sb_u16string &FileName, const sb_u16string &wsData);
#ifdef SB_U16STRING_USED
		TElMessagePartHandle AttachData(const std::wstring &ContentType, const std::wstring &FileName, const std::wstring &wsData);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEPART */

#ifdef SB_USE_CLASS_TELMESSAGEPART
		TElMessagePartHandle AttachData(const sb_u16string &ContentType, const sb_u16string &FileName, const std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Count);
#ifdef SB_U16STRING_USED
		TElMessagePartHandle AttachData(const std::wstring &ContentType, const std::wstring &FileName, const std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Count);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEPART */

#ifdef SB_USE_CLASS_TELMESSAGEPART
		TElMessagePartHandle AttachFile(const sb_u16string &ContentType, const sb_u16string &FileName);
#ifdef SB_U16STRING_USED
		TElMessagePartHandle AttachFile(const std::wstring &ContentType, const std::wstring &FileName);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEPART */

		virtual void get_CustomHeaders(const sb_u16string &HeaderName, sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_CustomHeaders(const std::wstring &HeaderName, std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_CustomHeaders(const sb_u16string &HeaderName, const sb_u16string &HeaderValue);

#ifdef SB_U16STRING_USED
		virtual void set_CustomHeaders(const std::wstring &HeaderName, const std::wstring &HeaderValue);

#endif /* SB_U16STRING_USED */
		virtual void get_MessageID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_MessageID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_MessageID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_MessageID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_ResentMessageID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ResentMessageID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_InReplyTo(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_InReplyTo(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_References(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_References(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_Keywords(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Keywords(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_Subject(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Subject(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_Comments(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Comments(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_ReturnPath(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ReturnPath(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		virtual TElMailAddressList* get_ReplyTo();

		virtual void set_ReplyTo(TElMailAddressList &Value);

		virtual void set_ReplyTo(TElMailAddressList *Value);

		SB_DECLARE_PROPERTY(TElMailAddressList*, get_ReplyTo, set_ReplyTo, TElMessage, ReplyTo);
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		virtual TElMailAddressList* get_ResentReplyTo();

		virtual void set_ResentReplyTo(TElMailAddressList &Value);

		virtual void set_ResentReplyTo(TElMailAddressList *Value);

		SB_DECLARE_PROPERTY(TElMailAddressList*, get_ResentReplyTo, set_ResentReplyTo, TElMessage, ResentReplyTo);
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		virtual TElMailAddressList* get_From();

		virtual void set_From(TElMailAddressList &Value);

		virtual void set_From(TElMailAddressList *Value);

		SB_DECLARE_PROPERTY(TElMailAddressList*, get_From, set_From, TElMessage, From);
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		virtual TElMailAddressList* get_ResentFrom();

		virtual void set_ResentFrom(TElMailAddressList &Value);

		virtual void set_ResentFrom(TElMailAddressList *Value);

		SB_DECLARE_PROPERTY(TElMailAddressList*, get_ResentFrom, set_ResentFrom, TElMessage, ResentFrom);
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		virtual TElMailAddressList* get_Sender();

		virtual void set_Sender(TElMailAddressList &Value);

		virtual void set_Sender(TElMailAddressList *Value);

		SB_DECLARE_PROPERTY(TElMailAddressList*, get_Sender, set_Sender, TElMessage, Sender);
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		virtual TElMailAddressList* get_ResentSender();

		virtual void set_ResentSender(TElMailAddressList &Value);

		virtual void set_ResentSender(TElMailAddressList *Value);

		SB_DECLARE_PROPERTY(TElMailAddressList*, get_ResentSender, set_ResentSender, TElMessage, ResentSender);
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		virtual TElMailAddressList* get_To_();

		virtual void set_To_(TElMailAddressList &Value);

		virtual void set_To_(TElMailAddressList *Value);

		SB_DECLARE_PROPERTY(TElMailAddressList*, get_To_, set_To_, TElMessage, To_);
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		virtual TElMailAddressList* get_ResentTo();

		virtual void set_ResentTo(TElMailAddressList &Value);

		virtual void set_ResentTo(TElMailAddressList *Value);

		SB_DECLARE_PROPERTY(TElMailAddressList*, get_ResentTo, set_ResentTo, TElMessage, ResentTo);
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		virtual TElMailAddressList* get_CC();

		virtual void set_CC(TElMailAddressList &Value);

		virtual void set_CC(TElMailAddressList *Value);

		SB_DECLARE_PROPERTY(TElMailAddressList*, get_CC, set_CC, TElMessage, CC);
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		virtual TElMailAddressList* get_ResentCC();

		virtual void set_ResentCC(TElMailAddressList &Value);

		virtual void set_ResentCC(TElMailAddressList *Value);

		SB_DECLARE_PROPERTY(TElMailAddressList*, get_ResentCC, set_ResentCC, TElMessage, ResentCC);
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		virtual TElMailAddressList* get_BCC();

		virtual void set_BCC(TElMailAddressList &Value);

		virtual void set_BCC(TElMailAddressList *Value);

		SB_DECLARE_PROPERTY(TElMailAddressList*, get_BCC, set_BCC, TElMessage, BCC);
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		virtual TElMailAddressList* get_ResentBCC();

		virtual void set_ResentBCC(TElMailAddressList &Value);

		virtual void set_ResentBCC(TElMailAddressList *Value);

		SB_DECLARE_PROPERTY(TElMailAddressList*, get_ResentBCC, set_ResentBCC, TElMessage, ResentBCC);
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMESSAGEPART
		virtual TElMessagePart* get_MainPart();

		SB_DECLARE_PROPERTY_GET(TElMessagePart*, get_MainPart, TElMessage, MainPart);
#endif /* SB_USE_CLASS_TELMESSAGEPART */

		virtual int32_t get_AttachmentsCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_AttachmentsCount, TElMessage, AttachmentsCount);

#ifdef SB_USE_CLASS_TELMESSAGEPART
		virtual TElMessagePart* get_Attachments(int32_t Index);
#endif /* SB_USE_CLASS_TELMESSAGEPART */

		virtual bool get_RequestReadReceipt();

		virtual void set_RequestReadReceipt(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RequestReadReceipt, set_RequestReadReceipt, TElMessage, RequestReadReceipt);

		virtual bool get_RequestDeliveryReceipt();

		virtual void set_RequestDeliveryReceipt(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RequestDeliveryReceipt, set_RequestDeliveryReceipt, TElMessage, RequestDeliveryReceipt);

		virtual TElMIMEMessagePriority get_Priority();

		virtual void set_Priority(TElMIMEMessagePriority Value);

		SB_DECLARE_PROPERTY(TElMIMEMessagePriority, get_Priority, set_Priority, TElMessage, Priority);

		virtual void get_HeaderFieldValues(const sb_u16string &Name, sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_HeaderFieldValues(const std::wstring &Name, std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		virtual TElMessageHeaderField* get_HeaderFields(const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		virtual TElMessageHeaderField* get_HeaderFields(const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */
		virtual void get_AttachEncoding(std::string &OutResult);

		virtual void set_AttachEncoding(const std::string &Value);

		virtual void get_BodyEncoding(std::string &OutResult);

		virtual void set_BodyEncoding(const std::string &Value);

		virtual void get_Charset(std::string &OutResult);

		virtual void set_Charset(const std::string &Value);

		virtual TElHeaderEncoding get_HeaderEncoding();

		virtual void set_HeaderEncoding(TElHeaderEncoding Value);

		SB_DECLARE_PROPERTY(TElHeaderEncoding, get_HeaderEncoding, set_HeaderEncoding, TElMessage, HeaderEncoding);

		virtual TElMessageExtendedOptions get_ExtendedOptions();

		virtual void set_ExtendedOptions(TElMessageExtendedOptions Value);

		SB_DECLARE_PROPERTY(TElMessageExtendedOptions, get_ExtendedOptions, set_ExtendedOptions, TElMessage, ExtendedOptions);

		virtual void get_MIMEPrefix(std::string &OutResult);

		virtual void set_MIMEPrefix(const std::string &Value);

		virtual void get_DefaultContentType(std::string &OutResult);

		virtual void set_DefaultContentType(const std::string &Value);

		TElMessage(TElMessageHandle handle, TElOwnHandle ownHandle);

		TElMessage(bool bCreateMainPart, const sb_u16string &XMailer);

#ifdef SB_U16STRING_USED
		TElMessage(bool bCreateMainPart, const std::wstring &XMailer);

#endif /* SB_U16STRING_USED */
		TElMessage(TElMessagePartClassHandle AMainPartClass, int32_t Fake, const sb_u16string &XMailer);

#ifdef SB_U16STRING_USED
		TElMessage(TElMessagePartClassHandle AMainPartClass, int32_t Fake, const std::wstring &XMailer);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELMESSAGEPART
		TElMessage(TElMessagePart &AMainPart, const sb_u16string &XMailer);

		TElMessage(TElMessagePart *AMainPart, const sb_u16string &XMailer);

#ifdef SB_U16STRING_USED
		TElMessage(TElMessagePart &AMainPart, const std::wstring &XMailer);

		TElMessage(TElMessagePart *AMainPart, const std::wstring &XMailer);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEPART */
		explicit TElMessage(const sb_u16string &XMailer);

#ifdef SB_U16STRING_USED
		explicit TElMessage(const std::wstring &XMailer);

#endif /* SB_U16STRING_USED */
		virtual ~TElMessage();

};
#endif /* SB_USE_CLASS_TELMESSAGE */

#ifdef SB_USE_CLASS_TELMESSAGEHEADER
class TElMessageHeader: public TObject
{
	private:
		SB_DISABLE_COPY(TElMessageHeader)
#ifdef SB_USE_CLASS_TLIST
		TList* _Inst_AddressList;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
		TList* _Inst_HeaderFields;
#endif /* SB_USE_CLASS_TLIST */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		TElMessageHeaderFieldHandle SetField(const sb_u16string &Name, const sb_u16string &Value, int32_t Index, bool ClearParams);
#ifdef SB_U16STRING_USED
		TElMessageHeaderFieldHandle SetField(const std::wstring &Name, const std::wstring &Value, int32_t Index, bool ClearParams);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

		void Assign(const TElMessageHeader &Source);

		void Assign(const TElMessageHeader *Source);

		void Clear();

		TElMessageHeaderHandle Clone();

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		TElMessageHeaderFieldHandle AddField(const sb_u16string &Name, const sb_u16string &Value, bool bOverride);
#ifdef SB_U16STRING_USED
		TElMessageHeaderFieldHandle AddField(const std::wstring &Name, const std::wstring &Value, bool bOverride);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

		void DeleteField(int32_t Index);

		void DeleteField(const sb_u16string &Name, int32_t Index);
#ifdef SB_U16STRING_USED
		void DeleteField(const std::wstring &Name, int32_t Index);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		TElMessageHeaderFieldHandle GetField(int32_t Index);
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		TElMessageHeaderFieldHandle GetField(const sb_u16string &Name, int32_t Index);
#ifdef SB_U16STRING_USED
		TElMessageHeaderFieldHandle GetField(const std::wstring &Name, int32_t Index);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

		bool FieldExists(const sb_u16string &Name);
#ifdef SB_U16STRING_USED
		bool FieldExists(const std::wstring &Name);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		void AddMailAddressList(const TElMailAddressList &Value);

		void AddMailAddressList(const TElMailAddressList *Value);
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

		void DeleteMailAddressList(int32_t Index);

		void DeleteMailAddressList(const sb_u16string &Name, int32_t Index);
#ifdef SB_U16STRING_USED
		void DeleteMailAddressList(const std::wstring &Name, int32_t Index);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		TElMailAddressListHandle GetMailAddressList(int32_t Index);
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
		TElMailAddressListHandle GetMailAddressList(const sb_u16string &Name, int32_t Index);
#ifdef SB_U16STRING_USED
		TElMailAddressListHandle GetMailAddressList(const std::wstring &Name, int32_t Index);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLER
		int32_t Assemble(std::string &sResult, const std::string &Charset, TElHeaderEncoding Encoding, TElMessagePartHandler &MessagePartHandler);

		int32_t Assemble(std::string &sResult, const std::string &Charset, TElHeaderEncoding Encoding, TElMessagePartHandler *MessagePartHandler);
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLER */

		int32_t Parse(const std::string &ASource, std::string &Charset, bool IgnoreNativeCharset);

#ifdef SB_USE_CLASS_TLIST
		virtual TList* get_AddressList();

		SB_DECLARE_PROPERTY_GET(TList*, get_AddressList, TElMessageHeader, AddressList);
#endif /* SB_USE_CLASS_TLIST */

		virtual bool get_AllowLongLines();

		virtual void set_AllowLongLines(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AllowLongLines, set_AllowLongLines, TElMessageHeader, AllowLongLines);

		virtual int32_t get_BodyLen();

		virtual void set_BodyLen(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_BodyLen, set_BodyLen, TElMessageHeader, BodyLen);

		virtual int32_t get_FieldsCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_FieldsCount, TElMessageHeader, FieldsCount);

#ifdef SB_USE_CLASS_TLIST
		virtual TList* get_HeaderFields();

		SB_DECLARE_PROPERTY_GET(TList*, get_HeaderFields, TElMessageHeader, HeaderFields);
#endif /* SB_USE_CLASS_TLIST */

		virtual int32_t get_MailAddressListCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_MailAddressListCount, TElMessageHeader, MailAddressListCount);

		virtual int32_t get_StreamPosBegin();

		virtual void set_StreamPosBegin(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_StreamPosBegin, set_StreamPosBegin, TElMessageHeader, StreamPosBegin);

		virtual bool get_ParseAddresses();

		virtual void set_ParseAddresses(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ParseAddresses, set_ParseAddresses, TElMessageHeader, ParseAddresses);

		virtual bool get_CombineParameters();

		virtual void set_CombineParameters(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CombineParameters, set_CombineParameters, TElMessageHeader, CombineParameters);

		TElMessageHeader(TElMessageHeaderHandle handle, TElOwnHandle ownHandle);

		TElMessageHeader();

		virtual ~TElMessageHeader();

};
#endif /* SB_USE_CLASS_TELMESSAGEHEADER */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
class TElMessageHeaderField: public TObject
{
	private:
		SB_DISABLE_COPY(TElMessageHeaderField)
	public:
		void Clear();

		TElMessageHeaderFieldHandle Clone();

		void AddParam(const sb_u16string &ParamName, const sb_u16string &ParamValue);
#ifdef SB_U16STRING_USED
		void AddParam(const std::wstring &ParamName, const std::wstring &ParamValue);
#endif /* SB_U16STRING_USED */

		void ClearParams();

		void DeleteParam(int32_t Index);

		void DeleteParam(const sb_u16string &ParamName);
#ifdef SB_U16STRING_USED
		void DeleteParam(const std::wstring &ParamName);
#endif /* SB_U16STRING_USED */

		int32_t GetParamIndexByName(const sb_u16string &ParamName);
#ifdef SB_U16STRING_USED
		int32_t GetParamIndexByName(const std::wstring &ParamName);
#endif /* SB_U16STRING_USED */

		void GetParamName(int32_t Index, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		void GetParamName(int32_t Index, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		void GetParamValue(int32_t Index, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		void GetParamValue(int32_t Index, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		void GetParamValue(const sb_u16string &ParamName, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		void GetParamValue(const std::wstring &ParamName, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		bool ParamExists(const sb_u16string &ParamName);
#ifdef SB_U16STRING_USED
		bool ParamExists(const std::wstring &ParamName);
#endif /* SB_U16STRING_USED */

		void SetParamValue(int32_t Index, const sb_u16string &wsValue);
#ifdef SB_U16STRING_USED
		void SetParamValue(int32_t Index, const std::wstring &wsValue);
#endif /* SB_U16STRING_USED */

		void SetParamValue(const sb_u16string &ParamName, const sb_u16string &wsValue);
#ifdef SB_U16STRING_USED
		void SetParamValue(const std::wstring &ParamName, const std::wstring &wsValue);
#endif /* SB_U16STRING_USED */

		virtual void get_Body(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Body(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Body(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Body(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_Comments(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Comments(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Comments(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Comments(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual bool get_EncodedWords();

		virtual void set_EncodedWords(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EncodedWords, set_EncodedWords, TElMessageHeaderField, EncodedWords);

		virtual bool get_QuotedParams();

		virtual void set_QuotedParams(bool Value);

		SB_DECLARE_PROPERTY(bool, get_QuotedParams, set_QuotedParams, TElMessageHeaderField, QuotedParams);

		virtual void get_Name(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Name(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Name(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Name(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual int32_t get_ParamsCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ParamsCount, TElMessageHeaderField, ParamsCount);

		virtual void get_Value(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Value(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Value(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Value(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElMessageHeaderField(TElMessageHeaderFieldHandle handle, TElOwnHandle ownHandle);

		TElMessageHeaderField();

		TElMessageHeaderField(const sb_u16string &AName, const sb_u16string &AValue);

#ifdef SB_U16STRING_USED
		TElMessageHeaderField(const std::wstring &AName, const std::wstring &AValue);

#endif /* SB_U16STRING_USED */
		TElMessageHeaderField(const std::string &Source, int32_t &Offset, const std::string &Charset, bool IgnoreNativeCharset);

};
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMAILADDRESSGROUP
class TElMailAddressGroup: public TObject
{
	private:
		SB_DISABLE_COPY(TElMailAddressGroup)
#ifdef SB_USE_CLASS_TELMAILADDRESS
		TElMailAddress* _Inst_Address;
#endif /* SB_USE_CLASS_TELMAILADDRESS */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELMAILADDRESS
		TElMailAddressHandle AddAddress(const sb_u16string &AAlias, const sb_u16string &AAddress);
#ifdef SB_U16STRING_USED
		TElMailAddressHandle AddAddress(const std::wstring &AAlias, const std::wstring &AAddress);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMAILADDRESS */

		void Clear();

		TElMailAddressGroupHandle Clone();

		void DeleteAddress(int32_t Index);

#ifdef SB_USE_CLASS_TELMAILADDRESS
		int32_t IndexOfAddress(TElMailAddress &AAddress);

		int32_t IndexOfAddress(TElMailAddress *AAddress);
#endif /* SB_USE_CLASS_TELMAILADDRESS */

		virtual void get_Name(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Name(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Name(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Name(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual int32_t get_AddressesCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_AddressesCount, TElMailAddressGroup, AddressesCount);

#ifdef SB_USE_CLASS_TELMAILADDRESS
		virtual TElMailAddress* get_Address(int32_t Index);
#endif /* SB_USE_CLASS_TELMAILADDRESS */

		TElMailAddressGroup(TElMailAddressGroupHandle handle, TElOwnHandle ownHandle);

		TElMailAddressGroup();

		virtual ~TElMailAddressGroup();

};
#endif /* SB_USE_CLASS_TELMAILADDRESSGROUP */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
class TElMailAddressList: public TObject
{
	private:
		SB_DISABLE_COPY(TElMailAddressList)
	public:
		void Clear();

		TElMailAddressListHandle Clone();

		int32_t Assemble(const sb_u16string &FieldName, std::string &sResult, const std::string &Charset, TElHeaderEncoding Encoding, bool AllowLongHeaderLines);
#ifdef SB_U16STRING_USED
		int32_t Assemble(const std::wstring &FieldName, std::string &sResult, const std::string &Charset, TElHeaderEncoding Encoding, bool AllowLongHeaderLines);
#endif /* SB_U16STRING_USED */

		int32_t Parse(const sb_u16string &wsSource);
#ifdef SB_U16STRING_USED
		int32_t Parse(const std::wstring &wsSource);
#endif /* SB_U16STRING_USED */

		int32_t Parse(const sb_u16string &wsSource, const std::string &Charset, bool IgnoreNativeCharset);
#ifdef SB_U16STRING_USED
		int32_t Parse(const std::wstring &wsSource, const std::string &Charset, bool IgnoreNativeCharset);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELMAILADDRESS
		TElMailAddressHandle AddAddress(const sb_u16string &Alias, const sb_u16string &Address);
#ifdef SB_U16STRING_USED
		TElMailAddressHandle AddAddress(const std::wstring &Alias, const std::wstring &Address);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMAILADDRESS */

		void DeleteAddress(int32_t Index);

#ifdef SB_USE_CLASS_TELMAILADDRESS
		TElMailAddressHandle GetAddress(int32_t Index);
#endif /* SB_USE_CLASS_TELMAILADDRESS */

#ifdef SB_USE_CLASS_TELMAILADDRESS
		int32_t IndexOfAddress(TElMailAddress &Address);

		int32_t IndexOfAddress(TElMailAddress *Address);
#endif /* SB_USE_CLASS_TELMAILADDRESS */

#ifdef SB_USE_CLASS_TELMAILADDRESSGROUP
		TElMailAddressGroupHandle AddGroup(TElMailAddressGroup &Group, bool bMakeCopy);

		TElMailAddressGroupHandle AddGroup(TElMailAddressGroup *Group, bool bMakeCopy);
#endif /* SB_USE_CLASS_TELMAILADDRESSGROUP */

		void DeleteGroup(int32_t Index);

		void DeleteGroup(const sb_u16string &GroupName);
#ifdef SB_U16STRING_USED
		void DeleteGroup(const std::wstring &GroupName);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELMAILADDRESSGROUP
		TElMailAddressGroupHandle GetGroup(int32_t Index);
#endif /* SB_USE_CLASS_TELMAILADDRESSGROUP */

		void GetGroupName(int32_t Index, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		void GetGroupName(int32_t Index, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELMAILADDRESS
		TElMailAddressHandle GetAddressFromAll(int32_t Index);
#endif /* SB_USE_CLASS_TELMAILADDRESS */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElMailAddressList, Count);

		virtual void get_FieldName(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_FieldName(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_FieldName(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_FieldName(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual int32_t get_GroupsCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_GroupsCount, TElMailAddressList, GroupsCount);

		virtual int32_t get_TotalCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_TotalCount, TElMailAddressList, TotalCount);

		TElMailAddressList(TElMailAddressListHandle handle, TElOwnHandle ownHandle);

		TElMailAddressList();

		explicit TElMailAddressList(const sb_u16string &Source);

#ifdef SB_U16STRING_USED
		explicit TElMailAddressList(const std::wstring &Source);

#endif /* SB_U16STRING_USED */
};
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESS
class TElMailAddress: public TObject
{
	private:
		SB_DISABLE_COPY(TElMailAddress)
	public:
		void Clear();

		TElMailAddressHandle Clone();

		bool IsAddress();

		bool IsAlias();

		virtual void get_Alias(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Alias(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Alias(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Alias(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_Address(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Address(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Address(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Address(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_Comments(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Comments(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Comments(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Comments(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElMailAddress(TElMailAddressHandle handle, TElOwnHandle ownHandle);

		TElMailAddress();

		TElMailAddress(const sb_u16string &AAlias, const sb_u16string &AAddress);

#ifdef SB_U16STRING_USED
		TElMailAddress(const std::wstring &AAlias, const std::wstring &AAddress);

#endif /* SB_U16STRING_USED */
};
#endif /* SB_USE_CLASS_TELMAILADDRESS */

#ifdef SB_USE_CLASS_TELMESSAGEPART
class TElMessagePart: public TObject
{
	private:
		SB_DISABLE_COPY(TElMessagePart)
#ifdef SB_USE_CLASS_TSTREAM
		TStream* _Inst_Stream;
#endif /* SB_USE_CLASS_TSTREAM */
#ifdef SB_USE_CLASS_TSTREAM
		TStream* _Inst_DataStream;
#endif /* SB_USE_CLASS_TSTREAM */
#ifdef SB_USE_CLASS_TELMESSAGEHEADER
		TElMessageHeader* _Inst_Header;
#endif /* SB_USE_CLASS_TELMESSAGEHEADER */
		TElMessagePart* _Inst_Parent;
#ifdef SB_USE_CLASS_TELMESSAGE
		TElMessage* _Inst_ParentMessage;
#endif /* SB_USE_CLASS_TELMESSAGE */
#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		TElMessageHeaderField* _Inst_HeaderFields;
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */
#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		TElMessageHeaderField* _Inst_HeaderContentTypeField;
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */
#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		TElMessageHeaderField* _Inst_HeaderContentDispositionField;
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */
#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		TElMessageHeaderField* _Inst_HeaderContentTransferEncodingField;
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */
#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		TElMessageHeaderField* _Inst_HeaderContentLocationField;
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */
		TElMessagePart* _Inst_Attachments;
#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLER
		TElMessagePartHandler* _Inst_MessagePartHandler;
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLER */
#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLER
		TElMessagePartHandler* _Inst_MessageBodyPartHandler;
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLER */

		void initInstances();

	public:
#ifdef SB_USE_CLASSES_TELMESSAGE_AND_TELMESSAGEHEADER
		static TElMessagePartHandle CreatePartForHeader(TElMessageHeader &Header, TElMessage &AMessage, TElMessagePart &AParent);

		static TElMessagePartHandle CreatePartForHeader(TElMessageHeader *Header, TElMessage *AMessage, TElMessagePart *AParent);
#endif /* SB_USE_CLASSES_TELMESSAGE_AND_TELMESSAGEHEADER */

#ifdef SB_USE_CLASSES_TELMESSAGE_AND_TELMESSAGEHEADER
		TElMessagePartHandle CreatePartForHeader_Inst(TElMessageHeader &Header, TElMessage &AMessage, TElMessagePart &AParent);

		TElMessagePartHandle CreatePartForHeader_Inst(TElMessageHeader *Header, TElMessage *AMessage, TElMessagePart *AParent);
#endif /* SB_USE_CLASSES_TELMESSAGE_AND_TELMESSAGEHEADER */

		virtual void Assign(TElMessagePart &Source);

		virtual void Assign(TElMessagePart *Source);

		virtual void Clear();

		virtual TElMessagePartHandle Clone();

#ifdef SB_USE_CLASSES_TELMESSAGEHEADER_AND_TSTREAM
		virtual int32_t Parse(TElMessageHeader &Header, TStream &Source, const std::string &Boundary, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions AOptions, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool bActivatePartHandlers);

		virtual int32_t Parse(TElMessageHeader *Header, TStream *Source, const std::string &Boundary, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions AOptions, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool bActivatePartHandlers);
#endif /* SB_USE_CLASSES_TELMESSAGEHEADER_AND_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t Assemble(TStream &Destination, const std::string &Charset, TElHeaderEncoding HeaderEncoding, const std::string &BodyEncoding, const std::string &AttachEncoding, bool bAssembleSource);

		virtual int32_t Assemble(TStream *Destination, const std::string &Charset, TElHeaderEncoding HeaderEncoding, const std::string &BodyEncoding, const std::string &AttachEncoding, bool bAssembleSource);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual bool IsText();

		virtual bool IsTextPlain();

		virtual bool IsTextHtml();

		virtual bool IsMessage();

		virtual bool IsImage();

		virtual bool IsAudio();

		virtual bool IsVideo();

		virtual bool IsMultipart();

		virtual bool IsAttachment();

		virtual bool IsInline();

		virtual bool IsApplication();

		void SetFieldValue(const sb_u16string &Name, const sb_u16string &Value, bool ClearParams);
#ifdef SB_U16STRING_USED
		void SetFieldValue(const std::wstring &Name, const std::wstring &Value, bool ClearParams);
#endif /* SB_U16STRING_USED */

		void SetContentType(const sb_u16string &AValue, bool ClearParams);
#ifdef SB_U16STRING_USED
		void SetContentType(const std::wstring &AValue, bool ClearParams);
#endif /* SB_U16STRING_USED */

		void SetContentSubtype(const sb_u16string &AValue, bool ClearParams);
#ifdef SB_U16STRING_USED
		void SetContentSubtype(const std::wstring &AValue, bool ClearParams);
#endif /* SB_U16STRING_USED */

		void SetContentTransferEncoding(const sb_u16string &AValue, bool ClearParams);
#ifdef SB_U16STRING_USED
		void SetContentTransferEncoding(const std::wstring &AValue, bool ClearParams);
#endif /* SB_U16STRING_USED */

		void SetContentID(const sb_u16string &AValue, bool ClearParams);
#ifdef SB_U16STRING_USED
		void SetContentID(const std::wstring &AValue, bool ClearParams);
#endif /* SB_U16STRING_USED */

		void SetContentDisposition(const sb_u16string &AValue, bool ClearParams);
#ifdef SB_U16STRING_USED
		void SetContentDisposition(const std::wstring &AValue, bool ClearParams);
#endif /* SB_U16STRING_USED */

		void SetContentDescription(const sb_u16string &AValue, bool ClearParams);
#ifdef SB_U16STRING_USED
		void SetContentDescription(const std::wstring &AValue, bool ClearParams);
#endif /* SB_U16STRING_USED */

		virtual int32_t GetDataSize(int32_t &Size);

		virtual int32_t GetData(sb_u16string &wsData);
#ifdef SB_U16STRING_USED
		virtual int32_t GetData(std::wstring &wsData);
#endif /* SB_U16STRING_USED */

		virtual int32_t GetData(std::vector<uint8_t> &Buffer, int32_t &BufferSize);

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t SaveDataToStream(TStream &Stream);

		virtual int32_t SaveDataToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t SaveDataToFile(const sb_u16string &wsFileName);
#ifdef SB_U16STRING_USED
		virtual int32_t SaveDataToFile(const std::wstring &wsFileName);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TSTREAM
		virtual void SetData(TStream &Stream, int32_t DataSize, bool bMakeCopy);

		virtual void SetData(TStream *Stream, int32_t DataSize, bool bMakeCopy);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void SetData(const sb_u16string &wsData);
#ifdef SB_U16STRING_USED
		virtual void SetData(const std::wstring &wsData);
#endif /* SB_U16STRING_USED */

		virtual void SetData(const std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Count);

		virtual int32_t GetText(sb_u16string &AText);
#ifdef SB_U16STRING_USED
		virtual int32_t GetText(std::wstring &AText);
#endif /* SB_U16STRING_USED */

		virtual void SetText(const sb_u16string &AText);
#ifdef SB_U16STRING_USED
		virtual void SetText(const std::wstring &AText);
#endif /* SB_U16STRING_USED */

		virtual TElMessagePartHandle GetPart(int32_t Index);

		virtual TElMessagePartHandle AddPart(TElMessagePart &Part, bool bMakeCopy, int32_t PartIndex);

		virtual TElMessagePartHandle AddPart(TElMessagePart *Part, bool bMakeCopy, int32_t PartIndex);

		void AddPart(TElMessagePart &Part);

		void AddPart(TElMessagePart *Part);

		virtual void DeletePart(int32_t Index, bool bDestroy);

		virtual void DeletePart(TElMessagePart &Part, bool bDestroy);

		virtual void DeletePart(TElMessagePart *Part, bool bDestroy);

		static TClassHandle ClassType();

		virtual int32_t get_BodyLen();

		SB_DECLARE_PROPERTY_GET(int32_t, get_BodyLen, TElMessagePart, BodyLen);

#ifdef SB_USE_CLASS_TSTREAM
		virtual TStream* get_Stream();

		SB_DECLARE_PROPERTY_GET(TStream*, get_Stream, TElMessagePart, Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t get_StreamPosBegin();

		SB_DECLARE_PROPERTY_GET(int32_t, get_StreamPosBegin, TElMessagePart, StreamPosBegin);

		virtual void get_Data(std::vector<uint8_t> &OutResult);

		virtual void set_Data(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TSTREAM
		virtual TStream* get_DataStream();

		virtual void set_DataStream(TStream &Value);

		virtual void set_DataStream(TStream *Value);

		SB_DECLARE_PROPERTY(TStream*, get_DataStream, set_DataStream, TElMessagePart, DataStream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t get_DataSize();

		virtual void set_DataSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DataSize, set_DataSize, TElMessagePart, DataSize);

		virtual TElMessageParsingOptions get_Options();

		virtual void set_Options(TElMessageParsingOptions Value);

		SB_DECLARE_PROPERTY(TElMessageParsingOptions, get_Options, set_Options, TElMessagePart, Options);

		virtual bool get_DisposeStream();

		virtual void set_DisposeStream(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DisposeStream, set_DisposeStream, TElMessagePart, DisposeStream);

		virtual bool get_DisposeDataStream();

		virtual void set_DisposeDataStream(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DisposeDataStream, set_DisposeDataStream, TElMessagePart, DisposeDataStream);

#ifdef SB_USE_CLASS_TELMESSAGEHEADER
		virtual TElMessageHeader* get_Header();

		SB_DECLARE_PROPERTY_GET(TElMessageHeader*, get_Header, TElMessagePart, Header);
#endif /* SB_USE_CLASS_TELMESSAGEHEADER */

		virtual TElMessagePart* get_Parent();

		SB_DECLARE_PROPERTY_GET(TElMessagePart*, get_Parent, TElMessagePart, Parent);

#ifdef SB_USE_CLASS_TELMESSAGE
		virtual TElMessage* get_ParentMessage();

		SB_DECLARE_PROPERTY_GET(TElMessage*, get_ParentMessage, TElMessagePart, ParentMessage);
#endif /* SB_USE_CLASS_TELMESSAGE */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		virtual TElMessageHeaderField* get_HeaderFields(const sb_u16string &wsFieldName);

#ifdef SB_U16STRING_USED
		virtual TElMessageHeaderField* get_HeaderFields(const std::wstring &wsFieldName);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */
#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		virtual TElMessageHeaderField* get_HeaderContentTypeField();

		SB_DECLARE_PROPERTY_GET(TElMessageHeaderField*, get_HeaderContentTypeField, TElMessagePart, HeaderContentTypeField);
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		virtual TElMessageHeaderField* get_HeaderContentDispositionField();

		SB_DECLARE_PROPERTY_GET(TElMessageHeaderField*, get_HeaderContentDispositionField, TElMessagePart, HeaderContentDispositionField);
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		virtual TElMessageHeaderField* get_HeaderContentTransferEncodingField();

		SB_DECLARE_PROPERTY_GET(TElMessageHeaderField*, get_HeaderContentTransferEncodingField, TElMessagePart, HeaderContentTransferEncodingField);
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
		virtual TElMessageHeaderField* get_HeaderContentLocationField();

		SB_DECLARE_PROPERTY_GET(TElMessageHeaderField*, get_HeaderContentLocationField, TElMessagePart, HeaderContentLocationField);
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

		virtual void get_ContentType(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ContentType(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_ContentSubtype(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ContentSubtype(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_ContentTransferEncoding(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ContentTransferEncoding(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_ContentID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ContentID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_ContentDisposition(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ContentDisposition(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_ContentDescription(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ContentDescription(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_FileName(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_FileName(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_FileName(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_FileName(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_CharSet(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_CharSet(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_CharSet(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_CharSet(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_HeaderCharSet(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_HeaderCharSet(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_BodyCharSet(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_BodyCharSet(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual int32_t get_PartsCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_PartsCount, TElMessagePart, PartsCount);

		virtual int32_t get_AttachmentsCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_AttachmentsCount, TElMessagePart, AttachmentsCount);

		virtual TElMessagePart* get_Attachments(int32_t Index);

#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLER
		virtual TElMessagePartHandler* get_MessagePartHandler();

		virtual void set_MessagePartHandler(TElMessagePartHandler &Value);

		virtual void set_MessagePartHandler(TElMessagePartHandler *Value);

		SB_DECLARE_PROPERTY(TElMessagePartHandler*, get_MessagePartHandler, set_MessagePartHandler, TElMessagePart, MessagePartHandler);
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLER */

#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLER
		virtual TElMessagePartHandler* get_MessageBodyPartHandler();

		virtual void set_MessageBodyPartHandler(TElMessagePartHandler &Value);

		virtual void set_MessageBodyPartHandler(TElMessagePartHandler *Value);

		SB_DECLARE_PROPERTY(TElMessagePartHandler*, get_MessageBodyPartHandler, set_MessageBodyPartHandler, TElMessagePart, MessageBodyPartHandler);
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLER */

		virtual bool get_IsActivatedMessagePartHandler();

		SB_DECLARE_PROPERTY_GET(bool, get_IsActivatedMessagePartHandler, TElMessagePart, IsActivatedMessagePartHandler);

		TElMessagePart(TElMessagePartHandle handle, TElOwnHandle ownHandle);

		TElMessagePart();

#ifdef SB_USE_CLASS_TELMESSAGE
		TElMessagePart(TElMessage &AMessage, TElMessagePart &AParent);

		TElMessagePart(TElMessage *AMessage, TElMessagePart *AParent);
#endif /* SB_USE_CLASS_TELMESSAGE */

		virtual ~TElMessagePart();

};
#endif /* SB_USE_CLASS_TELMESSAGEPART */

#ifdef SB_USE_CLASS_TELMULTIPARTLIST
class TElMultiPartList: public TElMessagePart
{
	private:
		SB_DISABLE_COPY(TElMultiPartList)
	public:
		virtual void Assign(TElMessagePart &Source);

		virtual void Assign(TElMessagePart *Source);

		virtual void Clear();

		virtual TElMessagePartHandle Clone();

#ifdef SB_USE_CLASSES_TELMESSAGEHEADER_AND_TSTREAM
		virtual int32_t Parse(TElMessageHeader &AHeader, TStream &Source, const std::string &Boundary, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions AOptions, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool bActivatePartHandlers);

		virtual int32_t Parse(TElMessageHeader *AHeader, TStream *Source, const std::string &Boundary, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions AOptions, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool bActivatePartHandlers);
#endif /* SB_USE_CLASSES_TELMESSAGEHEADER_AND_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t Assemble(TStream &Destination, const std::string &Charset, TElHeaderEncoding HeaderEncoding, const std::string &BodyEncoding, const std::string &AttachEncoding, bool bAssembleSource);

		virtual int32_t Assemble(TStream *Destination, const std::string &Charset, TElHeaderEncoding HeaderEncoding, const std::string &BodyEncoding, const std::string &AttachEncoding, bool bAssembleSource);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual TElMessagePartHandle GetPart(int32_t Index);

		virtual TElMessagePartHandle AddPart(TElMessagePart &Part, bool bMakeCopy, int32_t PartIndex);

		virtual TElMessagePartHandle AddPart(TElMessagePart *Part, bool bMakeCopy, int32_t PartIndex);

		virtual void DeletePart(int32_t Index, bool bDestroy);

		virtual void DeletePart(TElMessagePart &Part, bool bDestroy);

		virtual void DeletePart(TElMessagePart *Part, bool bDestroy);

		virtual bool IsText();

		virtual bool IsTextPlain();

		virtual bool IsMessage();

		virtual bool IsImage();

		virtual bool IsAudio();

		virtual bool IsVideo();

		virtual bool IsMultipart();

		virtual int32_t GetDataSize(int32_t &Size);

		virtual int32_t GetData(sb_u16string &wsData);
#ifdef SB_U16STRING_USED
		virtual int32_t GetData(std::wstring &wsData);
#endif /* SB_U16STRING_USED */

		virtual int32_t GetData(std::vector<uint8_t> &Buffer, int32_t &BufferSize);

#ifdef SB_USE_CLASS_TSTREAM
		virtual void SetData(TStream &Stream, int32_t DataSize, bool bMakeCopy);

		virtual void SetData(TStream *Stream, int32_t DataSize, bool bMakeCopy);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void SetData(const sb_u16string &wsData);
#ifdef SB_U16STRING_USED
		virtual void SetData(const std::wstring &wsData);
#endif /* SB_U16STRING_USED */

		virtual void SetData(const std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Count);

		static void GenerateBoundary(std::string &OutResult);

		void GenerateBoundary_Inst(std::string &OutResult);

		static TClassHandle ClassType();

		virtual void get_Boundary(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Boundary(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Boundary(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Boundary(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElMultiPartList(TElMultiPartListHandle handle, TElOwnHandle ownHandle);

		TElMultiPartList();

#ifdef SB_USE_CLASS_TELMESSAGE
		TElMultiPartList(TElMessage &AMessage, TElMessagePart &AParent);

		TElMultiPartList(TElMessage *AMessage, TElMessagePart *AParent);
#endif /* SB_USE_CLASS_TELMESSAGE */

};
#endif /* SB_USE_CLASS_TELMULTIPARTLIST */

#ifdef SB_USE_CLASS_TELPLAINTEXTPART
class TElPlainTextPart: public TElMultiPartList
{
	private:
		SB_DISABLE_COPY(TElPlainTextPart)
	public:
		virtual TElMessagePartHandle Clone();

		virtual void Assign(TElMessagePart &Source);

		virtual void Assign(TElMessagePart *Source);

#ifdef SB_USE_CLASSES_TELMESSAGEHEADER_AND_TSTREAM
		virtual int32_t Parse(TElMessageHeader &Header, TStream &Source, const std::string &Boundary, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions AOptions, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool bActivatePartHandlers);

		virtual int32_t Parse(TElMessageHeader *Header, TStream *Source, const std::string &Boundary, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions AOptions, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool bActivatePartHandlers);
#endif /* SB_USE_CLASSES_TELMESSAGEHEADER_AND_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t Assemble(TStream &Destination, const std::string &Charset, TElHeaderEncoding HeaderEncoding, const std::string &BodyEncoding, const std::string &AttachEncoding, bool bAssembleSource);

		virtual int32_t Assemble(TStream *Destination, const std::string &Charset, TElHeaderEncoding HeaderEncoding, const std::string &BodyEncoding, const std::string &AttachEncoding, bool bAssembleSource);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t GetText(sb_u16string &AText);
#ifdef SB_U16STRING_USED
		virtual int32_t GetText(std::wstring &AText);
#endif /* SB_U16STRING_USED */

		virtual void SetText(const sb_u16string &AText);
#ifdef SB_U16STRING_USED
		virtual void SetText(const std::wstring &AText);
#endif /* SB_U16STRING_USED */

		virtual bool IsText();

		virtual bool IsTextPlain();

		virtual bool IsMessage();

		virtual bool IsImage();

		virtual bool IsAudio();

		virtual bool IsVideo();

		virtual bool IsMultipart();

		virtual bool IsAttachment();

		virtual int32_t GetDataSize(int32_t &Size);

		virtual int32_t GetData(sb_u16string &wsData);
#ifdef SB_U16STRING_USED
		virtual int32_t GetData(std::wstring &wsData);
#endif /* SB_U16STRING_USED */

		virtual int32_t GetData(std::vector<uint8_t> &Buffer, int32_t &BufferSize);

#ifdef SB_USE_CLASS_TSTREAM
		virtual void SetData(TStream &Stream, int32_t DataSize, bool bMakeCopy);

		virtual void SetData(TStream *Stream, int32_t DataSize, bool bMakeCopy);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void SetData(const sb_u16string &wsData);
#ifdef SB_U16STRING_USED
		virtual void SetData(const std::wstring &wsData);
#endif /* SB_U16STRING_USED */

		virtual void SetData(const std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Count);

		static TClassHandle ClassType();

		TElPlainTextPart(TElPlainTextPartHandle handle, TElOwnHandle ownHandle);

		TElPlainTextPart();

#ifdef SB_USE_CLASS_TELMESSAGE
		TElPlainTextPart(TElMessage &AMessage, TElMessagePart &AParent);

		TElPlainTextPart(TElMessage *AMessage, TElMessagePart *AParent);
#endif /* SB_USE_CLASS_TELMESSAGE */

};
#endif /* SB_USE_CLASS_TELPLAINTEXTPART */

#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLER
class TElMessagePartHandler: public TObject
{
	private:
		SB_DISABLE_COPY(TElMessagePartHandler)
#ifdef SB_USE_CLASS_TELMESSAGEPART
		TElMessagePart* _Inst_DecodedPart;
#endif /* SB_USE_CLASS_TELMESSAGEPART */

		void initInstances();

	public:
		int32_t Decode(bool bActivatePartHandlers);

		static void GetDescription(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		static void GetDescription(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		virtual void GetDescription_Inst(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		virtual void GetDescription_Inst(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		static TClassHandle ClassType();

#ifdef SB_USE_CLASS_TELMESSAGEPART
		virtual TElMessagePart* get_DecodedPart();

		virtual void set_DecodedPart(TElMessagePart &Value);

		virtual void set_DecodedPart(TElMessagePart *Value);

		SB_DECLARE_PROPERTY(TElMessagePart*, get_DecodedPart, set_DecodedPart, TElMessagePartHandler, DecodedPart);
#endif /* SB_USE_CLASS_TELMESSAGEPART */

		virtual bool get_IsDecoderActivated();

		SB_DECLARE_PROPERTY_GET(bool, get_IsDecoderActivated, TElMessagePartHandler, IsDecoderActivated);

		virtual bool get_IsError();

		SB_DECLARE_PROPERTY_GET(bool, get_IsError, TElMessagePartHandler, IsError);

		virtual void get_ErrorText(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ErrorText(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual int32_t get_ResultCode();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ResultCode, TElMessagePartHandler, ResultCode);

		TElMessagePartHandler(TElMessagePartHandlerHandle handle, TElOwnHandle ownHandle);

		explicit TElMessagePartHandler(TObject &aParams);

		explicit TElMessagePartHandler(TObject *aParams);

		virtual ~TElMessagePartHandler();

};
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLER */

#ifdef SB_USE_CLASS_TELCONVERTER
class TElConverter: public TPlConverter
{
	private:
		SB_DISABLE_COPY(TElConverter)
	public:
#ifdef SB_USE_CLASS_TSTREAM
		void Convert(TStream &Source, TStream &Dest, TPlConvertOptions Options, int32_t MaxChars, bool &OutResult);

		void Convert(TStream *Source, TStream *Dest, TPlConvertOptions Options, int32_t MaxChars, bool &OutResult);
#endif /* SB_USE_CLASS_TSTREAM */

		bool Convert(const std::string &Source, sb_u16string &Dest, TPlConvertOptions Options);
#ifdef SB_U16STRING_USED
		bool Convert(const std::string &Source, std::wstring &Dest, TPlConvertOptions Options);
#endif /* SB_U16STRING_USED */

		TElConverter(TElConverterHandle handle, TElOwnHandle ownHandle);

		TElConverter();

		TElConverter(const std::string &SrcCharset, const std::string &DstCharset);

#ifdef SB_USE_CLASS_IPLCHARSET
		TElConverter(IPlCharsetHandle SrcCharset, IPlCharsetHandle DstCharset);
#endif /* SB_USE_CLASS_IPLCHARSET */

};
#endif /* SB_USE_CLASS_TELCONVERTER */

#ifdef SB_USE_CLASS_TELREGISTEREDMESSAGEPARTHANDLERS
class TElRegisteredMessagePartHandlers: public TObject
{
	private:
		SB_DISABLE_COPY(TElRegisteredMessagePartHandlers)
	public:
		virtual void AddHandler(TElMessagePartHandlerClassHandle hc);

		virtual int32_t GetHandlersCount();

		virtual TElMessagePartHandlerClassHandle GetHandlerClass(int32_t Index);

		virtual void RemoveHandler(TElMessagePartHandlerClassHandle hc);

		TElRegisteredMessagePartHandlers(TElRegisteredMessagePartHandlersHandle handle, TElOwnHandle ownHandle);

		TElRegisteredMessagePartHandlers();

};
#endif /* SB_USE_CLASS_TELREGISTEREDMESSAGEPARTHANDLERS */

#ifdef SB_USE_CLASS_TELXMLPART
class TElXmlPart: public TElMessagePart
{
	private:
		SB_DISABLE_COPY(TElXmlPart)
	public:
#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t Assemble(TStream &Destination, const std::string &Charset, TElHeaderEncoding HeaderEncoding, const std::string &BodyEncoding, const std::string &AttachEncoding, bool bAssembleSource);

		virtual int32_t Assemble(TStream *Destination, const std::string &Charset, TElHeaderEncoding HeaderEncoding, const std::string &BodyEncoding, const std::string &AttachEncoding, bool bAssembleSource);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual TElMessagePartHandle Clone();

		virtual bool IsText();

		virtual bool IsTextPlain();

		virtual bool IsTextHtml();

		virtual bool IsMessage();

		virtual bool IsImage();

		virtual bool IsAudio();

		virtual bool IsVideo();

		virtual bool IsMultipart();

#ifdef SB_USE_CLASSES_TELMESSAGEHEADER_AND_TSTREAM
		virtual int32_t Parse(TElMessageHeader &Header, TStream &Source, const std::string &Boundary, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions AOptions, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool bActivatePartHandlers);

		virtual int32_t Parse(TElMessageHeader *Header, TStream *Source, const std::string &Boundary, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions AOptions, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool bActivatePartHandlers);
#endif /* SB_USE_CLASSES_TELMESSAGEHEADER_AND_TSTREAM */

		static TClassHandle ClassType();

		TElXmlPart(TElXmlPartHandle handle, TElOwnHandle ownHandle);

		TElXmlPart();

#ifdef SB_USE_CLASS_TELMESSAGE
		TElXmlPart(TElMessage &AMessage, TElMessagePart &AParent);

		TElXmlPart(TElMessage *AMessage, TElMessagePart *AParent);
#endif /* SB_USE_CLASS_TELMESSAGE */

};
#endif /* SB_USE_CLASS_TELXMLPART */

#ifdef SB_USE_GLOBAL_PROCS_MIME

bool WideSameText(const sb_u16string &S1, const sb_u16string &S2);
#ifdef SB_U16STRING_USED
bool WideSameText(const std::wstring &S1, const std::wstring &S2);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TSTREAM
void GetHeaderFromStream(const TStream &Source, std::string &OutResult);
void GetHeaderFromStream(const TStream *Source, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTREAM */

void DeleteQuotationMarks(sb_u16string &Str);
#ifdef SB_U16STRING_USED
void DeleteQuotationMarks(std::wstring &Str);
#endif /* SB_U16STRING_USED */

void SetInQuotationMarks(sb_u16string &Str);
#ifdef SB_U16STRING_USED
void SetInQuotationMarks(std::wstring &Str);
#endif /* SB_U16STRING_USED */

bool IsAddressListField(const sb_u16string &FieldName, bool CheckPartial);
#ifdef SB_U16STRING_USED
bool IsAddressListField(const std::wstring &FieldName, bool CheckPartial);
#endif /* SB_U16STRING_USED */

bool IsMessageScopeField(const sb_u16string &FieldName);
#ifdef SB_U16STRING_USED
bool IsMessageScopeField(const std::wstring &FieldName);
#endif /* SB_U16STRING_USED */

bool IsUnstructuredField(const sb_u16string &FieldName);
#ifdef SB_U16STRING_USED
bool IsUnstructuredField(const std::wstring &FieldName);
#endif /* SB_U16STRING_USED */

void RegisterUnstructuredField(const sb_u16string &FieldName);
#ifdef SB_U16STRING_USED
void RegisterUnstructuredField(const std::wstring &FieldName);
#endif /* SB_U16STRING_USED */

void AddRegisteredMIMEMessagePartHandler(TElMessagePartHandlerClassHandle Handler);

void RemoveRegisteredMIMEMessagePartHandler(TElMessagePartHandlerClassHandle Handler);

#endif /* SB_USE_GLOBAL_PROCS_MIME */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_MIME
SB_IMPORT uint32_t SB_APIENTRY SBMIME_WideSameText(const sb_char16_t * pcS1, int32_t szS1, const sb_char16_t * pcS2, int32_t szS2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMIME_GetHeaderFromStream(const TStreamHandle Source, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMIME_DeleteQuotationMarks(sb_char16_t * pcStr, int32_t * szStr);
SB_IMPORT uint32_t SB_APIENTRY SBMIME_SetInQuotationMarks(sb_char16_t * pcStr, int32_t * szStr);
SB_IMPORT uint32_t SB_APIENTRY SBMIME_IsAddressListField(const sb_char16_t * pcFieldName, int32_t szFieldName, int8_t CheckPartial, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMIME_IsMessageScopeField(const sb_char16_t * pcFieldName, int32_t szFieldName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMIME_IsUnstructuredField(const sb_char16_t * pcFieldName, int32_t szFieldName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMIME_RegisterUnstructuredField(const sb_char16_t * pcFieldName, int32_t szFieldName);
SB_IMPORT uint32_t SB_APIENTRY SBMIME_AddRegisteredMIMEMessagePartHandler(TElMessagePartHandlerClassHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY SBMIME_RemoveRegisteredMIMEMessagePartHandler(TElMessagePartHandlerClassHandle Handler);
#endif /* SB_USE_GLOBAL_PROCS_MIME */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBMIME */

