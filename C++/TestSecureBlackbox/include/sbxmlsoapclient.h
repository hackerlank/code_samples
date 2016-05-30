#ifndef __INC_SBXMLSOAPCLIENT
#define __INC_SBXMLSOAPCLIENT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbconstants.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbstreams.h"
#include "sbstringlist.h"
#include "sbhttpscommon.h"
#include "sbhttpsclient.h"
#include "sbxmldefs.h"
#include "sbxmlcore.h"
#include "sbxmlsec.h"
#include "sbxmlutils.h"
#include "sbxmlsoapcore.h"
#include "sbxmlsoap.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElXMLSOAPClientHandle;

typedef TElXMLSOAPClientHandle ElXMLSOAPClientHandle;

typedef TElClassHandle TElXMLSOAPCustomParameterHandle;

typedef TElClassHandle TElXMLSOAPBaseParameterHandle;

typedef TElClassHandle TElXMLSOAPStringParameterHandle;

typedef TElClassHandle TElXMLSOAPBooleanParameterHandle;

typedef TElClassHandle TElXMLSOAPIntegerParameterHandle;

typedef TElClassHandle TElXMLSOAPInt64ParameterHandle;

typedef TElClassHandle TElXMLSOAPDoubleParameterHandle;

typedef TElClassHandle TElXMLSOAPDateTimeParameterHandle;

typedef TElClassHandle TElXMLSOAPBase64BinaryParameterHandle;

typedef TElClassHandle TElXMLSOAPCompoundParameterHandle;

typedef TElClassHandle TElXMLSOAPParametersManagerHandle;

typedef TElClassHandle TElXMLSOAPFaultHandle;

typedef TElClassHandle TElXMLSOAPParameterClassHandle;

typedef uint8_t TSBXMLSOAPResponseTypeRaw;

typedef enum
{
	srtNone = 0,
	srtStream = 1,
	srtXMLDocument = 2,
	srtSOAPMessage = 3
} TSBXMLSOAPResponseType;

#ifdef SB_USE_CLASS_TELXMLSOAPCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_ProcessReply(TElXMLSOAPClientHandle _Handle, int32_t AHTTPStatusCode, TStreamHandle AResponseStream);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_Clear(TElXMLSOAPClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_ClearResponse(TElXMLSOAPClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_GenerateMessage(TElXMLSOAPClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_LoadMessage(TElXMLSOAPClientHandle _Handle, TElXMLDOMDocumentHandle ADocument);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_LoadMessage_1(TElXMLSOAPClientHandle _Handle, TStreamHandle AStream);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_LoadMessage_2(TElXMLSOAPClientHandle _Handle, const char * pcAFileName, int32_t szAFileName);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_SendMessage(TElXMLSOAPClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_SendMessageWithAttachment(TElXMLSOAPClientHandle _Handle, const char * pcPrimaryMessageID, int32_t szPrimaryMessageID, const char * pcContentID, int32_t szContentID, const char * pcContentType, int32_t szContentType, TStreamHandle ContentStream, int8_t CloseStream);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_SendMessageWithAttachments(TElXMLSOAPClientHandle _Handle, const char * pcPrimaryMessageID, int32_t szPrimaryMessageID, TElHTTPMultipartListHandle PartsList);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_SendMessageWithAttachments_1(TElXMLSOAPClientHandle _Handle, const char * pcPrimaryMessageID, int32_t szPrimaryMessageID, const char * pcRelatedStartInfo, int32_t szRelatedStartInfo, const char * pcRelatedType, int32_t szRelatedType, TElHTTPMultipartListHandle PartsList);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_AddParameter(TElXMLSOAPClientHandle _Handle, TElXMLSOAPBaseParameterHandle Param, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_AddStringParameter(TElXMLSOAPClientHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcValue, int32_t szValue, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_AddStringParameter_1(TElXMLSOAPClientHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcValue, int32_t szValue, int8_t NormalizeNEL, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_AddStringParameter_2(TElXMLSOAPClientHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcParamNamespaceURI, int32_t szParamNamespaceURI, const sb_char16_t * pcValue, int32_t szValue, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_AddStringParameter_3(TElXMLSOAPClientHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcParamNamespaceURI, int32_t szParamNamespaceURI, const sb_char16_t * pcValue, int32_t szValue, int8_t NormalizeNEL, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_AddBooleanParameter(TElXMLSOAPClientHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, int8_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_AddBooleanParameter_1(TElXMLSOAPClientHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcParamNamespaceURI, int32_t szParamNamespaceURI, int8_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_AddIntegerParameter(TElXMLSOAPClientHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, int32_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_AddIntegerParameter_1(TElXMLSOAPClientHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcParamNamespaceURI, int32_t szParamNamespaceURI, int32_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_AddInt64Parameter(TElXMLSOAPClientHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, int64_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_AddInt64Parameter_1(TElXMLSOAPClientHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcParamNamespaceURI, int32_t szParamNamespaceURI, int64_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_AddDoubleParameter(TElXMLSOAPClientHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, double Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_AddDoubleParameter_1(TElXMLSOAPClientHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcParamNamespaceURI, int32_t szParamNamespaceURI, double Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_AddDateTimeParameter(TElXMLSOAPClientHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, int64_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_AddDateTimeParameter_1(TElXMLSOAPClientHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcParamNamespaceURI, int32_t szParamNamespaceURI, int64_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_AddBase64BinaryParameter(TElXMLSOAPClientHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const uint8_t pValue[], int32_t szValue, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_AddBase64BinaryParameter_1(TElXMLSOAPClientHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcParamNamespaceURI, int32_t szParamNamespaceURI, const uint8_t pValue[], int32_t szValue, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_AddCompoundParameter(TElXMLSOAPClientHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_AddCompoundParameter_1(TElXMLSOAPClientHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcParamNamespaceURI, int32_t szParamNamespaceURI, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_DeleteParameter(TElXMLSOAPClientHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_XMLDocument(TElXMLSOAPClientHandle _Handle, TElXMLDOMDocumentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_SOAPMessage(TElXMLSOAPClientHandle _Handle, TElXMLSOAPMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_SOAPVersion(TElXMLSOAPClientHandle _Handle, TSBXMLSOAPVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_set_SOAPVersion(TElXMLSOAPClientHandle _Handle, TSBXMLSOAPVersionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_SOAPPrefix(TElXMLSOAPClientHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_set_SOAPPrefix(TElXMLSOAPClientHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_MessageNamespaces(TElXMLSOAPClientHandle _Handle, TElXMLNamespaceMapHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_OperationName(TElXMLSOAPClientHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_set_OperationName(TElXMLSOAPClientHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_OperationNamespaceURI(TElXMLSOAPClientHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_set_OperationNamespaceURI(TElXMLSOAPClientHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_OperationResponseName(TElXMLSOAPClientHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_set_OperationResponseName(TElXMLSOAPClientHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_OperationResponseNamespaceURI(TElXMLSOAPClientHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_set_OperationResponseNamespaceURI(TElXMLSOAPClientHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_Encoding(TElXMLSOAPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_set_Encoding(TElXMLSOAPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_SOAPAction(TElXMLSOAPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_set_SOAPAction(TElXMLSOAPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_RootParameter(TElXMLSOAPClientHandle _Handle, TElXMLSOAPCompoundParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_ParameterCount(TElXMLSOAPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_Parameters(TElXMLSOAPClientHandle _Handle, int32_t Index, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_ParameterNames(TElXMLSOAPClientHandle _Handle, int32_t Index, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_ParameterValues(TElXMLSOAPClientHandle _Handle, int32_t Index, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_HTTPStatusCode(TElXMLSOAPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_ResponseType(TElXMLSOAPClientHandle _Handle, TSBXMLSOAPResponseTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_ResponseStream(TElXMLSOAPClientHandle _Handle, TMemoryStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_ResponseXMLDocument(TElXMLSOAPClientHandle _Handle, TElXMLDOMDocumentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_ResponseSOAPMessage(TElXMLSOAPClientHandle _Handle, TElXMLSOAPMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_OperationResponseXMLElement(TElXMLSOAPClientHandle _Handle, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_ResponseRootParameter(TElXMLSOAPClientHandle _Handle, TElXMLSOAPCompoundParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_ResponseParameterCount(TElXMLSOAPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_ResponseParameters(TElXMLSOAPClientHandle _Handle, int32_t Index, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_ResponseParameterNames(TElXMLSOAPClientHandle _Handle, int32_t Index, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_ResponseParameterValues(TElXMLSOAPClientHandle _Handle, int32_t Index, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_FaultCount(TElXMLSOAPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_Faults(TElXMLSOAPClientHandle _Handle, int32_t Index, TElXMLSOAPFaultHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_FaultActor(TElXMLSOAPClientHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_FaultCode(TElXMLSOAPClientHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_FaultString(TElXMLSOAPClientHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_HTTPClient(TElXMLSOAPClientHandle _Handle, TElHTTPSClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_set_HTTPClient(TElXMLSOAPClientHandle _Handle, TElHTTPSClientHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_URL(TElXMLSOAPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_set_URL(TElXMLSOAPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_OnFormatElement(TElXMLSOAPClientHandle _Handle, TSBXMLFormatElementEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_set_OnFormatElement(TElXMLSOAPClientHandle _Handle, TSBXMLFormatElementEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_get_OnFormatText(TElXMLSOAPClientHandle _Handle, TSBXMLFormatTextEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_set_OnFormatText(TElXMLSOAPClientHandle _Handle, TSBXMLFormatTextEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPClient_Create(TComponentHandle AOwner, TElXMLSOAPClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSOAPCLIENT */

#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomParameter_CreateFromXML(TElXMLDOMElementHandle Element, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomParameter_CreateFromXML_1(TElXMLSOAPCustomParameterHandle _Handle, TElXMLDOMElementHandle Element, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomParameter_Clone(TElXMLSOAPCustomParameterHandle _Handle, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomParameter_Clear(TElXMLSOAPCustomParameterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomParameter_LoadFromXML(TElXMLSOAPCustomParameterHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomParameter_SaveToXML(TElXMLSOAPCustomParameterHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomParameter_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomParameter_get_ParameterName(TElXMLSOAPCustomParameterHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomParameter_set_ParameterName(TElXMLSOAPCustomParameterHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomParameter_get_ParameterNamespaceURI(TElXMLSOAPCustomParameterHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomParameter_set_ParameterNamespaceURI(TElXMLSOAPCustomParameterHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomParameter_Create(TElXMLSOAPCustomParameterHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPBASEPARAMETER
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseParameter_CreateFromXML(TElXMLDOMElementHandle Element, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseParameter_CreateFromXML_1(TElXMLSOAPBaseParameterHandle _Handle, TElXMLDOMElementHandle Element, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseParameter_Clone(TElXMLSOAPBaseParameterHandle _Handle, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseParameter_Clear(TElXMLSOAPBaseParameterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseParameter_LoadFromXML(TElXMLSOAPBaseParameterHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseParameter_SaveToXML(TElXMLSOAPBaseParameterHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseParameter_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseParameter_get_StringValue(TElXMLSOAPBaseParameterHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseParameter_set_StringValue(TElXMLSOAPBaseParameterHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseParameter_Create(TElXMLSOAPBaseParameterHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSOAPBASEPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPSTRINGPARAMETER
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPStringParameter_CreateFromXML(TElXMLDOMElementHandle Element, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPStringParameter_CreateFromXML_1(TElXMLSOAPStringParameterHandle _Handle, TElXMLDOMElementHandle Element, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPStringParameter_Clone(TElXMLSOAPStringParameterHandle _Handle, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPStringParameter_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPStringParameter_get_Value(TElXMLSOAPStringParameterHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPStringParameter_set_Value(TElXMLSOAPStringParameterHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPStringParameter_Create(TElXMLSOAPBaseParameterHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSOAPSTRINGPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPBOOLEANPARAMETER
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBooleanParameter_CreateFromXML(TElXMLDOMElementHandle Element, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBooleanParameter_CreateFromXML_1(TElXMLSOAPBooleanParameterHandle _Handle, TElXMLDOMElementHandle Element, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBooleanParameter_Clone(TElXMLSOAPBooleanParameterHandle _Handle, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBooleanParameter_LoadFromXML(TElXMLSOAPBooleanParameterHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBooleanParameter_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBooleanParameter_get_Value(TElXMLSOAPBooleanParameterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBooleanParameter_set_Value(TElXMLSOAPBooleanParameterHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBooleanParameter_Create(TElXMLSOAPBaseParameterHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSOAPBOOLEANPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPINTEGERPARAMETER
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPIntegerParameter_CreateFromXML(TElXMLDOMElementHandle Element, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPIntegerParameter_CreateFromXML_1(TElXMLSOAPIntegerParameterHandle _Handle, TElXMLDOMElementHandle Element, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPIntegerParameter_Clone(TElXMLSOAPIntegerParameterHandle _Handle, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPIntegerParameter_LoadFromXML(TElXMLSOAPIntegerParameterHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPIntegerParameter_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPIntegerParameter_get_Value(TElXMLSOAPIntegerParameterHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPIntegerParameter_set_Value(TElXMLSOAPIntegerParameterHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPIntegerParameter_Create(TElXMLSOAPBaseParameterHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSOAPINTEGERPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPINT64PARAMETER
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPInt64Parameter_CreateFromXML(TElXMLDOMElementHandle Element, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPInt64Parameter_CreateFromXML_1(TElXMLSOAPInt64ParameterHandle _Handle, TElXMLDOMElementHandle Element, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPInt64Parameter_Clone(TElXMLSOAPInt64ParameterHandle _Handle, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPInt64Parameter_LoadFromXML(TElXMLSOAPInt64ParameterHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPInt64Parameter_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPInt64Parameter_get_Value(TElXMLSOAPInt64ParameterHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPInt64Parameter_set_Value(TElXMLSOAPInt64ParameterHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPInt64Parameter_Create(TElXMLSOAPBaseParameterHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSOAPINT64PARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPDOUBLEPARAMETER
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPDoubleParameter_CreateFromXML(TElXMLDOMElementHandle Element, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPDoubleParameter_CreateFromXML_1(TElXMLSOAPDoubleParameterHandle _Handle, TElXMLDOMElementHandle Element, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPDoubleParameter_Clone(TElXMLSOAPDoubleParameterHandle _Handle, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPDoubleParameter_LoadFromXML(TElXMLSOAPDoubleParameterHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPDoubleParameter_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPDoubleParameter_get_Value(TElXMLSOAPDoubleParameterHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPDoubleParameter_set_Value(TElXMLSOAPDoubleParameterHandle _Handle, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPDoubleParameter_Create(TElXMLSOAPBaseParameterHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSOAPDOUBLEPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPDATETIMEPARAMETER
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPDateTimeParameter_CreateFromXML(TElXMLDOMElementHandle Element, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPDateTimeParameter_CreateFromXML_1(TElXMLSOAPDateTimeParameterHandle _Handle, TElXMLDOMElementHandle Element, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPDateTimeParameter_Clone(TElXMLSOAPDateTimeParameterHandle _Handle, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPDateTimeParameter_LoadFromXML(TElXMLSOAPDateTimeParameterHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPDateTimeParameter_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPDateTimeParameter_get_Value(TElXMLSOAPDateTimeParameterHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPDateTimeParameter_set_Value(TElXMLSOAPDateTimeParameterHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPDateTimeParameter_get_DateTimeFormat(TElXMLSOAPDateTimeParameterHandle _Handle, TSBXMLDateTimeFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPDateTimeParameter_set_DateTimeFormat(TElXMLSOAPDateTimeParameterHandle _Handle, TSBXMLDateTimeFormatRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPDateTimeParameter_get_IncludeTimeZone(TElXMLSOAPDateTimeParameterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPDateTimeParameter_set_IncludeTimeZone(TElXMLSOAPDateTimeParameterHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPDateTimeParameter_Create(TElXMLSOAPDateTimeParameterHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSOAPDATETIMEPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPBASE64BINARYPARAMETER
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBase64BinaryParameter_CreateFromXML(TElXMLDOMElementHandle Element, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBase64BinaryParameter_CreateFromXML_1(TElXMLSOAPBase64BinaryParameterHandle _Handle, TElXMLDOMElementHandle Element, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBase64BinaryParameter_Clone(TElXMLSOAPBase64BinaryParameterHandle _Handle, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBase64BinaryParameter_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBase64BinaryParameter_get_Value(TElXMLSOAPBase64BinaryParameterHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBase64BinaryParameter_set_Value(TElXMLSOAPBase64BinaryParameterHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBase64BinaryParameter_Create(TElXMLSOAPBaseParameterHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSOAPBASE64BINARYPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_CreateFromXML(TElXMLDOMElementHandle Element, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_CreateFromXML_1(TElXMLSOAPCompoundParameterHandle _Handle, TElXMLDOMElementHandle Element, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_Clone(TElXMLSOAPCompoundParameterHandle _Handle, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_Add(TElXMLSOAPCompoundParameterHandle _Handle, TElXMLSOAPCustomParameterHandle Param, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_AddString(TElXMLSOAPCompoundParameterHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcValue, int32_t szValue, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_AddString_1(TElXMLSOAPCompoundParameterHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcValue, int32_t szValue, int8_t NormalizeNEL, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_AddString_2(TElXMLSOAPCompoundParameterHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcParamNamespaceURI, int32_t szParamNamespaceURI, const sb_char16_t * pcValue, int32_t szValue, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_AddString_3(TElXMLSOAPCompoundParameterHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcParamNamespaceURI, int32_t szParamNamespaceURI, const sb_char16_t * pcValue, int32_t szValue, int8_t NormalizeNEL, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_AddBoolean(TElXMLSOAPCompoundParameterHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, int8_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_AddBoolean_1(TElXMLSOAPCompoundParameterHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcParamNamespaceURI, int32_t szParamNamespaceURI, int8_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_AddInteger(TElXMLSOAPCompoundParameterHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, int32_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_AddInteger_1(TElXMLSOAPCompoundParameterHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcParamNamespaceURI, int32_t szParamNamespaceURI, int32_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_AddInt64(TElXMLSOAPCompoundParameterHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, int64_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_AddInt64_1(TElXMLSOAPCompoundParameterHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcParamNamespaceURI, int32_t szParamNamespaceURI, int64_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_AddDouble(TElXMLSOAPCompoundParameterHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, double Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_AddDouble_1(TElXMLSOAPCompoundParameterHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcParamNamespaceURI, int32_t szParamNamespaceURI, double Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_AddDateTime(TElXMLSOAPCompoundParameterHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, int64_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_AddDateTime_1(TElXMLSOAPCompoundParameterHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcParamNamespaceURI, int32_t szParamNamespaceURI, int64_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_AddBase64Binary(TElXMLSOAPCompoundParameterHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const uint8_t pValue[], int32_t szValue, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_AddBase64Binary_1(TElXMLSOAPCompoundParameterHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcParamNamespaceURI, int32_t szParamNamespaceURI, const uint8_t pValue[], int32_t szValue, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_AddCompound(TElXMLSOAPCompoundParameterHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_AddCompound_1(TElXMLSOAPCompoundParameterHandle _Handle, const sb_char16_t * pcParamName, int32_t szParamName, const sb_char16_t * pcParamNamespaceURI, int32_t szParamNamespaceURI, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_Delete(TElXMLSOAPCompoundParameterHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_Clear(TElXMLSOAPCompoundParameterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_LoadFromXML(TElXMLSOAPCompoundParameterHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_SaveToXML(TElXMLSOAPCompoundParameterHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_get_Count(TElXMLSOAPCompoundParameterHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_get_Items(TElXMLSOAPCompoundParameterHandle _Handle, int32_t Index, TElXMLSOAPCustomParameterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCompoundParameter_Create(TElXMLSOAPCompoundParameterHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPPARAMETERSMANAGER
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPParametersManager_Add(TElXMLSOAPParametersManagerHandle _Handle, TElXMLSOAPParameterClassHandle AParamClass);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPParametersManager_Add_1(TElXMLSOAPParametersManagerHandle _Handle, const sb_char16_t * pcAParamName, int32_t szAParamName, const sb_char16_t * pcAParamNamespaceURI, int32_t szAParamNamespaceURI, TElXMLSOAPParameterClassHandle AParamClass);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPParametersManager_RemoveAt(TElXMLSOAPParametersManagerHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPParametersManager_get_Count(TElXMLSOAPParametersManagerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPParametersManager_get_ParamNames(TElXMLSOAPParametersManagerHandle _Handle, int32_t Index, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPParametersManager_get_ParamNamespaceURIs(TElXMLSOAPParametersManagerHandle _Handle, int32_t Index, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPParametersManager_get_ParamClasses(TElXMLSOAPParametersManagerHandle _Handle, int32_t Index, TElXMLSOAPParameterClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPParametersManager_Create(TElXMLSOAPParametersManagerHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSOAPPARAMETERSMANAGER */

#ifdef SB_USE_CLASS_TELXMLSOAPFAULT
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPFault_Clear(TElXMLSOAPFaultHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPFault_LoadFromXML(TElXMLSOAPFaultHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPFault_SaveToXML(TElXMLSOAPFaultHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPFault_get_FaultActor(TElXMLSOAPFaultHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPFault_set_FaultActor(TElXMLSOAPFaultHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPFault_get_FaultCode(TElXMLSOAPFaultHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPFault_set_FaultCode(TElXMLSOAPFaultHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPFault_get_FaultString(TElXMLSOAPFaultHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPFault_set_FaultString(TElXMLSOAPFaultHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPFault_get_Detail(TElXMLSOAPFaultHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPFault_set_Detail(TElXMLSOAPFaultHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPFault_Create(TSBXMLSOAPVersionRaw AVersion, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, TElXMLSOAPFaultHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPFault_Create_1(TSBXMLSOAPVersionRaw AVersion, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, const sb_char16_t * pcAName, int32_t szAName, TElXMLSOAPFaultHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPFault_Create_2(TElXMLDOMElementHandle ParentElement, TSBXMLSOAPVersionRaw AVersion, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, TElXMLSOAPFaultHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPFault_Create_3(TElXMLDOMElementHandle ParentElement, TElXMLDOMElementHandle BeforeChild, TSBXMLSOAPVersionRaw AVersion, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, const sb_char16_t * pcAName, int32_t szAName, TElXMLSOAPFaultHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSOAPFAULT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElXMLSOAPClient;
typedef TElXMLSOAPClient ElXMLSOAPClient;
class TElXMLSOAPCustomParameter;
class TElXMLSOAPBaseParameter;
class TElXMLSOAPStringParameter;
class TElXMLSOAPBooleanParameter;
class TElXMLSOAPIntegerParameter;
class TElXMLSOAPInt64Parameter;
class TElXMLSOAPDoubleParameter;
class TElXMLSOAPDateTimeParameter;
class TElXMLSOAPBase64BinaryParameter;
class TElXMLSOAPCompoundParameter;
class TElXMLSOAPParametersManager;
class TElXMLSOAPFault;

#ifdef SB_USE_CLASS_TELXMLSOAPCLIENT
class TElXMLSOAPClient: public TComponent
{
	private:
		SB_DISABLE_COPY(TElXMLSOAPClient)
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		TElXMLDOMDocument* _Inst_XMLDocument;
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */
#ifdef SB_USE_CLASS_TELXMLSOAPMESSAGE
		TElXMLSOAPMessage* _Inst_SOAPMessage;
#endif /* SB_USE_CLASS_TELXMLSOAPMESSAGE */
#ifdef SB_USE_CLASS_TELXMLNAMESPACEMAP
		TElXMLNamespaceMap* _Inst_MessageNamespaces;
#endif /* SB_USE_CLASS_TELXMLNAMESPACEMAP */
#ifdef SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER
		TElXMLSOAPCompoundParameter* _Inst_RootParameter;
#endif /* SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER */
#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER
		TElXMLSOAPCustomParameter* _Inst_Parameters;
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER */
#ifdef SB_USE_CLASS_TMEMORYSTREAM
		TMemoryStream* _Inst_ResponseStream;
#endif /* SB_USE_CLASS_TMEMORYSTREAM */
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		TElXMLDOMDocument* _Inst_ResponseXMLDocument;
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */
#ifdef SB_USE_CLASS_TELXMLSOAPMESSAGE
		TElXMLSOAPMessage* _Inst_ResponseSOAPMessage;
#endif /* SB_USE_CLASS_TELXMLSOAPMESSAGE */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLDOMElement* _Inst_OperationResponseXMLElement;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#ifdef SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER
		TElXMLSOAPCompoundParameter* _Inst_ResponseRootParameter;
#endif /* SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER */
#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER
		TElXMLSOAPCustomParameter* _Inst_ResponseParameters;
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER */
#ifdef SB_USE_CLASS_TELXMLSOAPFAULT
		TElXMLSOAPFault* _Inst_Faults;
#endif /* SB_USE_CLASS_TELXMLSOAPFAULT */
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		TElHTTPSClient* _Inst_HTTPClient;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TSTREAM
		void ProcessReply(int32_t AHTTPStatusCode, TStream &AResponseStream);

		void ProcessReply(int32_t AHTTPStatusCode, TStream *AResponseStream);
#endif /* SB_USE_CLASS_TSTREAM */

		void Clear();

		void ClearResponse();

		void GenerateMessage();

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		void LoadMessage(TElXMLDOMDocument &ADocument);

		void LoadMessage(TElXMLDOMDocument *ADocument);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TSTREAM
		void LoadMessage(TStream &AStream);

		void LoadMessage(TStream *AStream);
#endif /* SB_USE_CLASS_TSTREAM */

		void LoadMessage(const std::string &AFileName);

		void SendMessage();

#ifdef SB_USE_CLASS_TSTREAM
		void SendMessageWithAttachment(const std::string &PrimaryMessageID, const std::string &ContentID, const std::string &ContentType, TStream &ContentStream, bool CloseStream);

		void SendMessageWithAttachment(const std::string &PrimaryMessageID, const std::string &ContentID, const std::string &ContentType, TStream *ContentStream, bool CloseStream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELHTTPMULTIPARTLIST
		void SendMessageWithAttachments(const std::string &PrimaryMessageID, TElHTTPMultipartList &PartsList);

		void SendMessageWithAttachments(const std::string &PrimaryMessageID, TElHTTPMultipartList *PartsList);
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTLIST */

#ifdef SB_USE_CLASS_TELHTTPMULTIPARTLIST
		void SendMessageWithAttachments(const std::string &PrimaryMessageID, const std::string &RelatedStartInfo, const std::string &RelatedType, TElHTTPMultipartList &PartsList);

		void SendMessageWithAttachments(const std::string &PrimaryMessageID, const std::string &RelatedStartInfo, const std::string &RelatedType, TElHTTPMultipartList *PartsList);
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTLIST */

#ifdef SB_USE_CLASS_TELXMLSOAPBASEPARAMETER
		int32_t AddParameter(TElXMLSOAPBaseParameter &Param);

		int32_t AddParameter(TElXMLSOAPBaseParameter *Param);
#endif /* SB_USE_CLASS_TELXMLSOAPBASEPARAMETER */

		int32_t AddStringParameter(const sb_u16string &ParamName, const sb_u16string &Value);
#ifdef SB_U16STRING_USED
		int32_t AddStringParameter(const std::wstring &ParamName, const std::wstring &Value);
#endif /* SB_U16STRING_USED */

		int32_t AddStringParameter(const sb_u16string &ParamName, const sb_u16string &Value, bool NormalizeNEL);
#ifdef SB_U16STRING_USED
		int32_t AddStringParameter(const std::wstring &ParamName, const std::wstring &Value, bool NormalizeNEL);
#endif /* SB_U16STRING_USED */

		int32_t AddStringParameter(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, const sb_u16string &Value);
#ifdef SB_U16STRING_USED
		int32_t AddStringParameter(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, const std::wstring &Value);
#endif /* SB_U16STRING_USED */

		int32_t AddStringParameter(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, const sb_u16string &Value, bool NormalizeNEL);
#ifdef SB_U16STRING_USED
		int32_t AddStringParameter(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, const std::wstring &Value, bool NormalizeNEL);
#endif /* SB_U16STRING_USED */

		int32_t AddBooleanParameter(const sb_u16string &ParamName, bool Value);
#ifdef SB_U16STRING_USED
		int32_t AddBooleanParameter(const std::wstring &ParamName, bool Value);
#endif /* SB_U16STRING_USED */

		int32_t AddBooleanParameter(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, bool Value);
#ifdef SB_U16STRING_USED
		int32_t AddBooleanParameter(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, bool Value);
#endif /* SB_U16STRING_USED */

		int32_t AddIntegerParameter(const sb_u16string &ParamName, int32_t Value);
#ifdef SB_U16STRING_USED
		int32_t AddIntegerParameter(const std::wstring &ParamName, int32_t Value);
#endif /* SB_U16STRING_USED */

		int32_t AddIntegerParameter(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, int32_t Value);
#ifdef SB_U16STRING_USED
		int32_t AddIntegerParameter(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, int32_t Value);
#endif /* SB_U16STRING_USED */

		int32_t AddInt64Parameter(const sb_u16string &ParamName, int64_t Value);
#ifdef SB_U16STRING_USED
		int32_t AddInt64Parameter(const std::wstring &ParamName, int64_t Value);
#endif /* SB_U16STRING_USED */

		int32_t AddInt64Parameter(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, int64_t Value);
#ifdef SB_U16STRING_USED
		int32_t AddInt64Parameter(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, int64_t Value);
#endif /* SB_U16STRING_USED */

		int32_t AddDoubleParameter(const sb_u16string &ParamName, double Value);
#ifdef SB_U16STRING_USED
		int32_t AddDoubleParameter(const std::wstring &ParamName, double Value);
#endif /* SB_U16STRING_USED */

		int32_t AddDoubleParameter(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, double Value);
#ifdef SB_U16STRING_USED
		int32_t AddDoubleParameter(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, double Value);
#endif /* SB_U16STRING_USED */

		int32_t AddDateTimeParameter(const sb_u16string &ParamName, int64_t Value);
#ifdef SB_U16STRING_USED
		int32_t AddDateTimeParameter(const std::wstring &ParamName, int64_t Value);
#endif /* SB_U16STRING_USED */

		int32_t AddDateTimeParameter(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, int64_t Value);
#ifdef SB_U16STRING_USED
		int32_t AddDateTimeParameter(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, int64_t Value);
#endif /* SB_U16STRING_USED */

		int32_t AddBase64BinaryParameter(const sb_u16string &ParamName, const std::vector<uint8_t> &Value);
#ifdef SB_U16STRING_USED
		int32_t AddBase64BinaryParameter(const std::wstring &ParamName, const std::vector<uint8_t> &Value);
#endif /* SB_U16STRING_USED */

		int32_t AddBase64BinaryParameter(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, const std::vector<uint8_t> &Value);
#ifdef SB_U16STRING_USED
		int32_t AddBase64BinaryParameter(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, const std::vector<uint8_t> &Value);
#endif /* SB_U16STRING_USED */

		int32_t AddCompoundParameter(const sb_u16string &ParamName);
#ifdef SB_U16STRING_USED
		int32_t AddCompoundParameter(const std::wstring &ParamName);
#endif /* SB_U16STRING_USED */

		int32_t AddCompoundParameter(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI);
#ifdef SB_U16STRING_USED
		int32_t AddCompoundParameter(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI);
#endif /* SB_U16STRING_USED */

		void DeleteParameter(int32_t Index);

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual TElXMLDOMDocument* get_XMLDocument();

		SB_DECLARE_PROPERTY_GET(TElXMLDOMDocument*, get_XMLDocument, TElXMLSOAPClient, XMLDocument);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLSOAPMESSAGE
		virtual TElXMLSOAPMessage* get_SOAPMessage();

		SB_DECLARE_PROPERTY_GET(TElXMLSOAPMessage*, get_SOAPMessage, TElXMLSOAPClient, SOAPMessage);
#endif /* SB_USE_CLASS_TELXMLSOAPMESSAGE */

		virtual TSBXMLSOAPVersion get_SOAPVersion();

		virtual void set_SOAPVersion(TSBXMLSOAPVersion Value);

		SB_DECLARE_PROPERTY(TSBXMLSOAPVersion, get_SOAPVersion, set_SOAPVersion, TElXMLSOAPClient, SOAPVersion);

		virtual void get_SOAPPrefix(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_SOAPPrefix(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_SOAPPrefix(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_SOAPPrefix(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLNAMESPACEMAP
		virtual TElXMLNamespaceMap* get_MessageNamespaces();

		SB_DECLARE_PROPERTY_GET(TElXMLNamespaceMap*, get_MessageNamespaces, TElXMLSOAPClient, MessageNamespaces);
#endif /* SB_USE_CLASS_TELXMLNAMESPACEMAP */

		virtual void get_OperationName(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_OperationName(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_OperationName(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_OperationName(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_OperationNamespaceURI(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_OperationNamespaceURI(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_OperationNamespaceURI(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_OperationNamespaceURI(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_OperationResponseName(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_OperationResponseName(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_OperationResponseName(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_OperationResponseName(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_OperationResponseNamespaceURI(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_OperationResponseNamespaceURI(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_OperationResponseNamespaceURI(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_OperationResponseNamespaceURI(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_Encoding(std::string &OutResult);

		virtual void set_Encoding(const std::string &Value);

		virtual void get_SOAPAction(std::string &OutResult);

		virtual void set_SOAPAction(const std::string &Value);

#ifdef SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER
		virtual TElXMLSOAPCompoundParameter* get_RootParameter();

		SB_DECLARE_PROPERTY_GET(TElXMLSOAPCompoundParameter*, get_RootParameter, TElXMLSOAPClient, RootParameter);
#endif /* SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER */

		virtual int32_t get_ParameterCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ParameterCount, TElXMLSOAPClient, ParameterCount);

#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER
		virtual TElXMLSOAPCustomParameter* get_Parameters(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER */

		virtual void get_ParameterNames(int32_t Index, sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ParameterNames(int32_t Index, std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_ParameterValues(int32_t Index, sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ParameterValues(int32_t Index, std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual int32_t get_HTTPStatusCode();

		SB_DECLARE_PROPERTY_GET(int32_t, get_HTTPStatusCode, TElXMLSOAPClient, HTTPStatusCode);

		virtual TSBXMLSOAPResponseType get_ResponseType();

		SB_DECLARE_PROPERTY_GET(TSBXMLSOAPResponseType, get_ResponseType, TElXMLSOAPClient, ResponseType);

#ifdef SB_USE_CLASS_TMEMORYSTREAM
		virtual TMemoryStream* get_ResponseStream();

		SB_DECLARE_PROPERTY_GET(TMemoryStream*, get_ResponseStream, TElXMLSOAPClient, ResponseStream);
#endif /* SB_USE_CLASS_TMEMORYSTREAM */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual TElXMLDOMDocument* get_ResponseXMLDocument();

		SB_DECLARE_PROPERTY_GET(TElXMLDOMDocument*, get_ResponseXMLDocument, TElXMLSOAPClient, ResponseXMLDocument);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLSOAPMESSAGE
		virtual TElXMLSOAPMessage* get_ResponseSOAPMessage();

		SB_DECLARE_PROPERTY_GET(TElXMLSOAPMessage*, get_ResponseSOAPMessage, TElXMLSOAPClient, ResponseSOAPMessage);
#endif /* SB_USE_CLASS_TELXMLSOAPMESSAGE */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual TElXMLDOMElement* get_OperationResponseXMLElement();

		SB_DECLARE_PROPERTY_GET(TElXMLDOMElement*, get_OperationResponseXMLElement, TElXMLSOAPClient, OperationResponseXMLElement);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER
		virtual TElXMLSOAPCompoundParameter* get_ResponseRootParameter();

		SB_DECLARE_PROPERTY_GET(TElXMLSOAPCompoundParameter*, get_ResponseRootParameter, TElXMLSOAPClient, ResponseRootParameter);
#endif /* SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER */

		virtual int32_t get_ResponseParameterCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ResponseParameterCount, TElXMLSOAPClient, ResponseParameterCount);

#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER
		virtual TElXMLSOAPCustomParameter* get_ResponseParameters(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER */

		virtual void get_ResponseParameterNames(int32_t Index, sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ResponseParameterNames(int32_t Index, std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_ResponseParameterValues(int32_t Index, sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ResponseParameterValues(int32_t Index, std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual int32_t get_FaultCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_FaultCount, TElXMLSOAPClient, FaultCount);

#ifdef SB_USE_CLASS_TELXMLSOAPFAULT
		virtual TElXMLSOAPFault* get_Faults(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLSOAPFAULT */

		virtual void get_FaultActor(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_FaultActor(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_FaultCode(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_FaultCode(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_FaultString(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_FaultString(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		virtual TElHTTPSClient* get_HTTPClient();

		virtual void set_HTTPClient(TElHTTPSClient &Value);

		virtual void set_HTTPClient(TElHTTPSClient *Value);

		SB_DECLARE_PROPERTY(TElHTTPSClient*, get_HTTPClient, set_HTTPClient, TElXMLSOAPClient, HTTPClient);
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

		virtual void get_URL(std::string &OutResult);

		virtual void set_URL(const std::string &Value);

		virtual void get_OnFormatElement(TSBXMLFormatElementEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFormatElement(TSBXMLFormatElementEvent pMethodValue, void * pDataValue);

		virtual void get_OnFormatText(TSBXMLFormatTextEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFormatText(TSBXMLFormatTextEvent pMethodValue, void * pDataValue);

		TElXMLSOAPClient(TElXMLSOAPClientHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLSOAPClient(TComponent &AOwner);

		explicit TElXMLSOAPClient(TComponent *AOwner);

		virtual ~TElXMLSOAPClient();

};
#endif /* SB_USE_CLASS_TELXMLSOAPCLIENT */

#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER
class TElXMLSOAPCustomParameter: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLSOAPCustomParameter)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		static TElXMLSOAPCustomParameterHandle CreateFromXML(TElXMLDOMElement &Element);

		static TElXMLSOAPCustomParameterHandle CreateFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual TElXMLSOAPCustomParameterHandle CreateFromXML_Inst(TElXMLDOMElement &Element);

		virtual TElXMLSOAPCustomParameterHandle CreateFromXML_Inst(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual TElXMLSOAPCustomParameterHandle Clone();

		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		static TClassHandle ClassType();

		virtual void get_ParameterName(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ParameterName(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ParameterName(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ParameterName(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_ParameterNamespaceURI(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ParameterNamespaceURI(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ParameterNamespaceURI(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ParameterNamespaceURI(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLSOAPCustomParameter(TElXMLSOAPCustomParameterHandle handle, TElOwnHandle ownHandle);

		TElXMLSOAPCustomParameter();

};
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPBASEPARAMETER
class TElXMLSOAPBaseParameter: public TElXMLSOAPCustomParameter
{
	private:
		SB_DISABLE_COPY(TElXMLSOAPBaseParameter)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		static TElXMLSOAPCustomParameterHandle CreateFromXML(TElXMLDOMElement &Element);

		static TElXMLSOAPCustomParameterHandle CreateFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual TElXMLSOAPCustomParameterHandle CreateFromXML_Inst(TElXMLDOMElement &Element);

		virtual TElXMLSOAPCustomParameterHandle CreateFromXML_Inst(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual TElXMLSOAPCustomParameterHandle Clone();

		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		static TClassHandle ClassType();

		virtual void get_StringValue(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_StringValue(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_StringValue(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_StringValue(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLSOAPBaseParameter(TElXMLSOAPBaseParameterHandle handle, TElOwnHandle ownHandle);

		TElXMLSOAPBaseParameter();

};
#endif /* SB_USE_CLASS_TELXMLSOAPBASEPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPSTRINGPARAMETER
class TElXMLSOAPStringParameter: public TElXMLSOAPBaseParameter
{
	private:
		SB_DISABLE_COPY(TElXMLSOAPStringParameter)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		static TElXMLSOAPCustomParameterHandle CreateFromXML(TElXMLDOMElement &Element);

		static TElXMLSOAPCustomParameterHandle CreateFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual TElXMLSOAPCustomParameterHandle CreateFromXML_Inst(TElXMLDOMElement &Element);

		virtual TElXMLSOAPCustomParameterHandle CreateFromXML_Inst(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual TElXMLSOAPCustomParameterHandle Clone();

		static TClassHandle ClassType();

		virtual void get_Value(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Value(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Value(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Value(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLSOAPStringParameter(TElXMLSOAPStringParameterHandle handle, TElOwnHandle ownHandle);

		TElXMLSOAPStringParameter();

};
#endif /* SB_USE_CLASS_TELXMLSOAPSTRINGPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPBOOLEANPARAMETER
class TElXMLSOAPBooleanParameter: public TElXMLSOAPBaseParameter
{
	private:
		SB_DISABLE_COPY(TElXMLSOAPBooleanParameter)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		static TElXMLSOAPCustomParameterHandle CreateFromXML(TElXMLDOMElement &Element);

		static TElXMLSOAPCustomParameterHandle CreateFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual TElXMLSOAPCustomParameterHandle CreateFromXML_Inst(TElXMLDOMElement &Element);

		virtual TElXMLSOAPCustomParameterHandle CreateFromXML_Inst(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual TElXMLSOAPCustomParameterHandle Clone();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		static TClassHandle ClassType();

		virtual bool get_Value();

		virtual void set_Value(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Value, set_Value, TElXMLSOAPBooleanParameter, Value);

		TElXMLSOAPBooleanParameter(TElXMLSOAPBooleanParameterHandle handle, TElOwnHandle ownHandle);

		TElXMLSOAPBooleanParameter();

};
#endif /* SB_USE_CLASS_TELXMLSOAPBOOLEANPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPINTEGERPARAMETER
class TElXMLSOAPIntegerParameter: public TElXMLSOAPBaseParameter
{
	private:
		SB_DISABLE_COPY(TElXMLSOAPIntegerParameter)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		static TElXMLSOAPCustomParameterHandle CreateFromXML(TElXMLDOMElement &Element);

		static TElXMLSOAPCustomParameterHandle CreateFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual TElXMLSOAPCustomParameterHandle CreateFromXML_Inst(TElXMLDOMElement &Element);

		virtual TElXMLSOAPCustomParameterHandle CreateFromXML_Inst(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual TElXMLSOAPCustomParameterHandle Clone();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		static TClassHandle ClassType();

		virtual int32_t get_Value();

		virtual void set_Value(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Value, set_Value, TElXMLSOAPIntegerParameter, Value);

		TElXMLSOAPIntegerParameter(TElXMLSOAPIntegerParameterHandle handle, TElOwnHandle ownHandle);

		TElXMLSOAPIntegerParameter();

};
#endif /* SB_USE_CLASS_TELXMLSOAPINTEGERPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPINT64PARAMETER
class TElXMLSOAPInt64Parameter: public TElXMLSOAPBaseParameter
{
	private:
		SB_DISABLE_COPY(TElXMLSOAPInt64Parameter)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		static TElXMLSOAPCustomParameterHandle CreateFromXML(TElXMLDOMElement &Element);

		static TElXMLSOAPCustomParameterHandle CreateFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual TElXMLSOAPCustomParameterHandle CreateFromXML_Inst(TElXMLDOMElement &Element);

		virtual TElXMLSOAPCustomParameterHandle CreateFromXML_Inst(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual TElXMLSOAPCustomParameterHandle Clone();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		static TClassHandle ClassType();

		virtual int64_t get_Value();

		virtual void set_Value(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Value, set_Value, TElXMLSOAPInt64Parameter, Value);

		TElXMLSOAPInt64Parameter(TElXMLSOAPInt64ParameterHandle handle, TElOwnHandle ownHandle);

		TElXMLSOAPInt64Parameter();

};
#endif /* SB_USE_CLASS_TELXMLSOAPINT64PARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPDOUBLEPARAMETER
class TElXMLSOAPDoubleParameter: public TElXMLSOAPBaseParameter
{
	private:
		SB_DISABLE_COPY(TElXMLSOAPDoubleParameter)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		static TElXMLSOAPCustomParameterHandle CreateFromXML(TElXMLDOMElement &Element);

		static TElXMLSOAPCustomParameterHandle CreateFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual TElXMLSOAPCustomParameterHandle CreateFromXML_Inst(TElXMLDOMElement &Element);

		virtual TElXMLSOAPCustomParameterHandle CreateFromXML_Inst(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual TElXMLSOAPCustomParameterHandle Clone();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		static TClassHandle ClassType();

		virtual double get_Value();

		virtual void set_Value(double Value);

		SB_DECLARE_PROPERTY(double, get_Value, set_Value, TElXMLSOAPDoubleParameter, Value);

		TElXMLSOAPDoubleParameter(TElXMLSOAPDoubleParameterHandle handle, TElOwnHandle ownHandle);

		TElXMLSOAPDoubleParameter();

};
#endif /* SB_USE_CLASS_TELXMLSOAPDOUBLEPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPDATETIMEPARAMETER
class TElXMLSOAPDateTimeParameter: public TElXMLSOAPBaseParameter
{
	private:
		SB_DISABLE_COPY(TElXMLSOAPDateTimeParameter)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		static TElXMLSOAPCustomParameterHandle CreateFromXML(TElXMLDOMElement &Element);

		static TElXMLSOAPCustomParameterHandle CreateFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual TElXMLSOAPCustomParameterHandle CreateFromXML_Inst(TElXMLDOMElement &Element);

		virtual TElXMLSOAPCustomParameterHandle CreateFromXML_Inst(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual TElXMLSOAPCustomParameterHandle Clone();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		static TClassHandle ClassType();

		virtual int64_t get_Value();

		virtual void set_Value(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Value, set_Value, TElXMLSOAPDateTimeParameter, Value);

		virtual TSBXMLDateTimeFormat get_DateTimeFormat();

		virtual void set_DateTimeFormat(TSBXMLDateTimeFormat Value);

		SB_DECLARE_PROPERTY(TSBXMLDateTimeFormat, get_DateTimeFormat, set_DateTimeFormat, TElXMLSOAPDateTimeParameter, DateTimeFormat);

		virtual bool get_IncludeTimeZone();

		virtual void set_IncludeTimeZone(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeTimeZone, set_IncludeTimeZone, TElXMLSOAPDateTimeParameter, IncludeTimeZone);

		TElXMLSOAPDateTimeParameter(TElXMLSOAPDateTimeParameterHandle handle, TElOwnHandle ownHandle);

		TElXMLSOAPDateTimeParameter();

};
#endif /* SB_USE_CLASS_TELXMLSOAPDATETIMEPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPBASE64BINARYPARAMETER
class TElXMLSOAPBase64BinaryParameter: public TElXMLSOAPBaseParameter
{
	private:
		SB_DISABLE_COPY(TElXMLSOAPBase64BinaryParameter)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		static TElXMLSOAPCustomParameterHandle CreateFromXML(TElXMLDOMElement &Element);

		static TElXMLSOAPCustomParameterHandle CreateFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual TElXMLSOAPCustomParameterHandle CreateFromXML_Inst(TElXMLDOMElement &Element);

		virtual TElXMLSOAPCustomParameterHandle CreateFromXML_Inst(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual TElXMLSOAPCustomParameterHandle Clone();

		static TClassHandle ClassType();

		virtual void get_Value(std::vector<uint8_t> &OutResult);

		virtual void set_Value(const std::vector<uint8_t> &Value);

		TElXMLSOAPBase64BinaryParameter(TElXMLSOAPBase64BinaryParameterHandle handle, TElOwnHandle ownHandle);

		TElXMLSOAPBase64BinaryParameter();

};
#endif /* SB_USE_CLASS_TELXMLSOAPBASE64BINARYPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER
class TElXMLSOAPCompoundParameter: public TElXMLSOAPCustomParameter
{
	private:
		SB_DISABLE_COPY(TElXMLSOAPCompoundParameter)
		TElXMLSOAPCustomParameter* _Inst_Items;

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		static TElXMLSOAPCustomParameterHandle CreateFromXML(TElXMLDOMElement &Element);

		static TElXMLSOAPCustomParameterHandle CreateFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual TElXMLSOAPCustomParameterHandle CreateFromXML_Inst(TElXMLDOMElement &Element);

		virtual TElXMLSOAPCustomParameterHandle CreateFromXML_Inst(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual TElXMLSOAPCustomParameterHandle Clone();

		int32_t Add(TElXMLSOAPCustomParameter &Param);

		int32_t Add(TElXMLSOAPCustomParameter *Param);

		int32_t AddString(const sb_u16string &ParamName, const sb_u16string &Value);
#ifdef SB_U16STRING_USED
		int32_t AddString(const std::wstring &ParamName, const std::wstring &Value);
#endif /* SB_U16STRING_USED */

		int32_t AddString(const sb_u16string &ParamName, const sb_u16string &Value, bool NormalizeNEL);
#ifdef SB_U16STRING_USED
		int32_t AddString(const std::wstring &ParamName, const std::wstring &Value, bool NormalizeNEL);
#endif /* SB_U16STRING_USED */

		int32_t AddString(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, const sb_u16string &Value);
#ifdef SB_U16STRING_USED
		int32_t AddString(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, const std::wstring &Value);
#endif /* SB_U16STRING_USED */

		int32_t AddString(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, const sb_u16string &Value, bool NormalizeNEL);
#ifdef SB_U16STRING_USED
		int32_t AddString(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, const std::wstring &Value, bool NormalizeNEL);
#endif /* SB_U16STRING_USED */

		int32_t AddBoolean(const sb_u16string &ParamName, bool Value);
#ifdef SB_U16STRING_USED
		int32_t AddBoolean(const std::wstring &ParamName, bool Value);
#endif /* SB_U16STRING_USED */

		int32_t AddBoolean(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, bool Value);
#ifdef SB_U16STRING_USED
		int32_t AddBoolean(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, bool Value);
#endif /* SB_U16STRING_USED */

		int32_t AddInteger(const sb_u16string &ParamName, int32_t Value);
#ifdef SB_U16STRING_USED
		int32_t AddInteger(const std::wstring &ParamName, int32_t Value);
#endif /* SB_U16STRING_USED */

		int32_t AddInteger(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, int32_t Value);
#ifdef SB_U16STRING_USED
		int32_t AddInteger(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, int32_t Value);
#endif /* SB_U16STRING_USED */

		int32_t AddInt64(const sb_u16string &ParamName, int64_t Value);
#ifdef SB_U16STRING_USED
		int32_t AddInt64(const std::wstring &ParamName, int64_t Value);
#endif /* SB_U16STRING_USED */

		int32_t AddInt64(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, int64_t Value);
#ifdef SB_U16STRING_USED
		int32_t AddInt64(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, int64_t Value);
#endif /* SB_U16STRING_USED */

		int32_t AddDouble(const sb_u16string &ParamName, double Value);
#ifdef SB_U16STRING_USED
		int32_t AddDouble(const std::wstring &ParamName, double Value);
#endif /* SB_U16STRING_USED */

		int32_t AddDouble(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, double Value);
#ifdef SB_U16STRING_USED
		int32_t AddDouble(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, double Value);
#endif /* SB_U16STRING_USED */

		int32_t AddDateTime(const sb_u16string &ParamName, int64_t Value);
#ifdef SB_U16STRING_USED
		int32_t AddDateTime(const std::wstring &ParamName, int64_t Value);
#endif /* SB_U16STRING_USED */

		int32_t AddDateTime(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, int64_t Value);
#ifdef SB_U16STRING_USED
		int32_t AddDateTime(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, int64_t Value);
#endif /* SB_U16STRING_USED */

		int32_t AddBase64Binary(const sb_u16string &ParamName, const std::vector<uint8_t> &Value);
#ifdef SB_U16STRING_USED
		int32_t AddBase64Binary(const std::wstring &ParamName, const std::vector<uint8_t> &Value);
#endif /* SB_U16STRING_USED */

		int32_t AddBase64Binary(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, const std::vector<uint8_t> &Value);
#ifdef SB_U16STRING_USED
		int32_t AddBase64Binary(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, const std::vector<uint8_t> &Value);
#endif /* SB_U16STRING_USED */

		int32_t AddCompound(const sb_u16string &ParamName);
#ifdef SB_U16STRING_USED
		int32_t AddCompound(const std::wstring &ParamName);
#endif /* SB_U16STRING_USED */

		int32_t AddCompound(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI);
#ifdef SB_U16STRING_USED
		int32_t AddCompound(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI);
#endif /* SB_U16STRING_USED */

		void Delete(int32_t Index);

		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		static TClassHandle ClassType();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLSOAPCompoundParameter, Count);

		virtual TElXMLSOAPCustomParameter* get_Items(int32_t Index);

		TElXMLSOAPCompoundParameter(TElXMLSOAPCompoundParameterHandle handle, TElOwnHandle ownHandle);

		TElXMLSOAPCompoundParameter();

		virtual ~TElXMLSOAPCompoundParameter();

};
#endif /* SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPPARAMETERSMANAGER
class TElXMLSOAPParametersManager: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLSOAPParametersManager)
	public:
		void Add(TElXMLSOAPParameterClassHandle AParamClass);

		void Add(const sb_u16string &AParamName, const sb_u16string &AParamNamespaceURI, TElXMLSOAPParameterClassHandle AParamClass);
#ifdef SB_U16STRING_USED
		void Add(const std::wstring &AParamName, const std::wstring &AParamNamespaceURI, TElXMLSOAPParameterClassHandle AParamClass);
#endif /* SB_U16STRING_USED */

		void RemoveAt(int32_t Index);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLSOAPParametersManager, Count);

		virtual void get_ParamNames(int32_t Index, sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ParamNames(int32_t Index, std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_ParamNamespaceURIs(int32_t Index, sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ParamNamespaceURIs(int32_t Index, std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual TElXMLSOAPParameterClassHandle get_ParamClasses(int32_t Index);

		TElXMLSOAPParametersManager(TElXMLSOAPParametersManagerHandle handle, TElOwnHandle ownHandle);

		TElXMLSOAPParametersManager();

};
#endif /* SB_USE_CLASS_TELXMLSOAPPARAMETERSMANAGER */

#ifdef SB_USE_CLASS_TELXMLSOAPFAULT
class TElXMLSOAPFault: public TElXMLSOAPElement
{
	private:
		SB_DISABLE_COPY(TElXMLSOAPFault)
	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_FaultActor(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_FaultActor(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_FaultActor(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_FaultActor(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_FaultCode(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_FaultCode(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_FaultCode(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_FaultCode(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_FaultString(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_FaultString(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_FaultString(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_FaultString(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_Detail(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Detail(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Detail(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Detail(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLSOAPFault(TElXMLSOAPFaultHandle handle, TElOwnHandle ownHandle);

		TElXMLSOAPFault(TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI);

#ifdef SB_U16STRING_USED
		TElXMLSOAPFault(TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI);

#endif /* SB_U16STRING_USED */
		TElXMLSOAPFault(TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLSOAPFault(TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLSOAPFault(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI);

		TElXMLSOAPFault(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI);

#ifdef SB_U16STRING_USED
		TElXMLSOAPFault(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI);

		TElXMLSOAPFault(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLSOAPFault(TElXMLDOMElement &ParentElement, TElXMLDOMElement &BeforeChild, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName);

		TElXMLSOAPFault(TElXMLDOMElement *ParentElement, TElXMLDOMElement *BeforeChild, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLSOAPFault(TElXMLDOMElement &ParentElement, TElXMLDOMElement &BeforeChild, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName);

		TElXMLSOAPFault(TElXMLDOMElement *ParentElement, TElXMLDOMElement *BeforeChild, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
};
#endif /* SB_USE_CLASS_TELXMLSOAPFAULT */

#ifdef SB_USE_GLOBAL_PROCS_XMLSOAPCLIENT

#ifdef SB_USE_CLASS_TELXMLSOAPPARAMETERSMANAGER
TElXMLSOAPParametersManagerHandle SOAPParametersManager();
#endif /* SB_USE_CLASS_TELXMLSOAPPARAMETERSMANAGER */

#endif /* SB_USE_GLOBAL_PROCS_XMLSOAPCLIENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_XMLSOAPCLIENT
SB_IMPORT uint32_t SB_APIENTRY SBXMLSOAPClient_SOAPParametersManager(TElXMLSOAPParametersManagerHandle * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_XMLSOAPCLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBXMLSOAPCLIENT */

