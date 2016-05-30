#ifndef __INC_SBXMLTRANSFORM
#define __INC_SBXMLTRANSFORM

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbencoding.h"
#include "sbxmldefs.h"
#include "sbxmlcore.h"
#include "sbxmlutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SFXMLCantApplyTransformToBinary 	"Cann\'t apply %s transform to binary data. (%s)"

typedef TElClassHandle TElXMLTransformHandle;

typedef TElXMLTransformHandle ElXMLTransformHandle;

typedef TElClassHandle TElXMLNullTransformHandle;

typedef TElXMLNullTransformHandle ElXMLNullTransformHandle;

typedef TElClassHandle TElXMLBase64TransformHandle;

typedef TElXMLBase64TransformHandle ElXMLBase64TransformHandle;

typedef TElClassHandle TElXMLC14NTransformHandle;

typedef TElXMLC14NTransformHandle ElXMLC14NTransformHandle;

typedef TElClassHandle TElXMLEnvelopedSignatureTransformHandle;

typedef TElXMLEnvelopedSignatureTransformHandle ElXMLEnvelopedSignatureTransformHandle;

typedef TElClassHandle TElXMLXPathTransformHandle;

typedef TElXMLXPathTransformHandle ElXMLXPathTransformHandle;

typedef TElClassHandle TElXMLXPathFilterItemHandle;

typedef TElClassHandle TElXMLXPathFilter2TransformHandle;

typedef TElClassHandle TElXMLTransformChainHandle;

typedef TElXMLTransformChainHandle ElXMLTransformChainHandle;

typedef TElClassHandle TElXMLUnsupportedTransformHandle;

typedef uint32_t TSBTransformPropertiesRaw;

typedef enum 
{
	f_tpConcatenate = 1,
	f_tpC14NCommutative = 2
} TSBTransformProperties;

typedef uint8_t TSBTransformedDataTypeRaw;

typedef enum
{
	tdtBinary = 0,
	tdtNode = 1,
	tdtNodes = 2
} TSBTransformedDataType;

typedef TElClassHandle TElXMLTransformClassHandle;

typedef TElXMLTransformClassHandle ElXMLTransformClassHandle;

typedef uint8_t TSBXPathFilterOperationRaw;

typedef enum
{
	xfIntersect = 0,
	xfSubtract = 1,
	xfUnion = 2
} TSBXPathFilterOperation;

#ifdef SB_USE_CLASS_TELXMLTRANSFORM
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_GetDefaultTransformAlgorithmURI(sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_GetDefaultTransformAlgorithmURI_1(TElXMLTransformHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_IsTransformAlgorithmSupported(const sb_char16_t * pcAlgorithm, int32_t szAlgorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_IsTransformAlgorithmSupported_1(TElXMLTransformHandle _Handle, const sb_char16_t * pcAlgorithm, int32_t szAlgorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_Clear(TElXMLTransformHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_LoadFromXML(TElXMLTransformHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_SaveToXML(TElXMLTransformHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_TransformData(TElXMLTransformHandle _Handle, const uint8_t pData[], int32_t szData, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_TransformData_1(TElXMLTransformHandle _Handle, TElXMLDOMNodeHandle Node, TElXMLDOMNodeHandle Reference, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_TransformData_2(TElXMLTransformHandle _Handle, TElXMLDOMNodeListHandle Nodes, const TElXMLDOMNodeHandle pReference[], int32_t szReference, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_get_TransformAlgorithmURI(TElXMLTransformHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_set_TransformAlgorithmURI(TElXMLTransformHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_get_TransformedData(TElXMLTransformHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_set_TransformedData(TElXMLTransformHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_get_TransformedNode(TElXMLTransformHandle _Handle, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_set_TransformedNode(TElXMLTransformHandle _Handle, TElXMLDOMNodeHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_get_TransformedNodes(TElXMLTransformHandle _Handle, TElXMLDOMNodeListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_set_TransformedNodes(TElXMLTransformHandle _Handle, TElXMLDOMNodeListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_get_ReferenceNode(TElXMLTransformHandle _Handle, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_set_ReferenceNode(TElXMLTransformHandle _Handle, TElXMLDOMNodeHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_get_ReferenceNodes(TElXMLTransformHandle _Handle, TElXMLDOMNodeHandle pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_set_ReferenceNodes(TElXMLTransformHandle _Handle, const TElXMLDOMNodeHandle pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransform_Create(TElXMLTransformHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLTRANSFORM */

#ifdef SB_USE_CLASS_TELXMLNULLTRANSFORM
SB_IMPORT uint32_t SB_APIENTRY TElXMLNullTransform_GetDefaultTransformAlgorithmURI(sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNullTransform_GetDefaultTransformAlgorithmURI_1(TElXMLNullTransformHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNullTransform_IsTransformAlgorithmSupported(const sb_char16_t * pcAlgorithm, int32_t szAlgorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNullTransform_IsTransformAlgorithmSupported_1(TElXMLNullTransformHandle _Handle, const sb_char16_t * pcAlgorithm, int32_t szAlgorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNullTransform_TransformData(TElXMLNullTransformHandle _Handle, const uint8_t pData[], int32_t szData, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNullTransform_TransformData_1(TElXMLNullTransformHandle _Handle, TElXMLDOMNodeHandle Node, TElXMLDOMNodeHandle Reference, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNullTransform_TransformData_2(TElXMLNullTransformHandle _Handle, TElXMLDOMNodeListHandle Nodes, const TElXMLDOMNodeHandle pReference[], int32_t szReference, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNullTransform_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNullTransform_Create(TElXMLNullTransformHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLNULLTRANSFORM */

#ifdef SB_USE_CLASS_TELXMLBASE64TRANSFORM
SB_IMPORT uint32_t SB_APIENTRY TElXMLBase64Transform_GetDefaultTransformAlgorithmURI(sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBase64Transform_GetDefaultTransformAlgorithmURI_1(TElXMLBase64TransformHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBase64Transform_IsTransformAlgorithmSupported(const sb_char16_t * pcAlgorithm, int32_t szAlgorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBase64Transform_IsTransformAlgorithmSupported_1(TElXMLBase64TransformHandle _Handle, const sb_char16_t * pcAlgorithm, int32_t szAlgorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBase64Transform_TransformData(TElXMLBase64TransformHandle _Handle, const uint8_t pData[], int32_t szData, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBase64Transform_TransformData_1(TElXMLBase64TransformHandle _Handle, TElXMLDOMNodeHandle Node, TElXMLDOMNodeHandle Reference, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBase64Transform_TransformData_2(TElXMLBase64TransformHandle _Handle, TElXMLDOMNodeListHandle Nodes, const TElXMLDOMNodeHandle pReference[], int32_t szReference, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBase64Transform_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBase64Transform_get_OldMode(TElXMLBase64TransformHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBase64Transform_set_OldMode(TElXMLBase64TransformHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBase64Transform_Create(TElXMLBase64TransformHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLBASE64TRANSFORM */

#ifdef SB_USE_CLASS_TELXMLC14NTRANSFORM
SB_IMPORT uint32_t SB_APIENTRY TElXMLC14NTransform_GetDefaultTransformAlgorithmURI(sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLC14NTransform_GetDefaultTransformAlgorithmURI_1(TElXMLC14NTransformHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLC14NTransform_IsTransformAlgorithmSupported(const sb_char16_t * pcAlgorithm, int32_t szAlgorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLC14NTransform_IsTransformAlgorithmSupported_1(TElXMLC14NTransformHandle _Handle, const sb_char16_t * pcAlgorithm, int32_t szAlgorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLC14NTransform_Clear(TElXMLC14NTransformHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLC14NTransform_LoadFromXML(TElXMLC14NTransformHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLC14NTransform_SaveToXML(TElXMLC14NTransformHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLC14NTransform_TransformData(TElXMLC14NTransformHandle _Handle, const uint8_t pData[], int32_t szData, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLC14NTransform_TransformData_1(TElXMLC14NTransformHandle _Handle, TElXMLDOMNodeHandle Node, TElXMLDOMNodeHandle Reference, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLC14NTransform_TransformData_2(TElXMLC14NTransformHandle _Handle, TElXMLDOMNodeListHandle Nodes, const TElXMLDOMNodeHandle pReference[], int32_t szReference, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLC14NTransform_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLC14NTransform_get_CanonicalizationMethod(TElXMLC14NTransformHandle _Handle, TElXMLCanonicalizationMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLC14NTransform_set_CanonicalizationMethod(TElXMLC14NTransformHandle _Handle, TElXMLCanonicalizationMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLC14NTransform_get_ExclusiveCanonicalizationPrefix(TElXMLC14NTransformHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLC14NTransform_set_ExclusiveCanonicalizationPrefix(TElXMLC14NTransformHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLC14NTransform_get_InclusiveNamespacesPrefixList(TElXMLC14NTransformHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLC14NTransform_set_InclusiveNamespacesPrefixList(TElXMLC14NTransformHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLC14NTransform_Create(TElXMLC14NTransformHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLC14NTransform_Create_1(TElXMLCanonicalizationMethodRaw AMethod, TElXMLC14NTransformHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLC14NTRANSFORM */

#ifdef SB_USE_CLASS_TELXMLENVELOPEDSIGNATURETRANSFORM
SB_IMPORT uint32_t SB_APIENTRY TElXMLEnvelopedSignatureTransform_GetDefaultTransformAlgorithmURI(sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEnvelopedSignatureTransform_GetDefaultTransformAlgorithmURI_1(TElXMLEnvelopedSignatureTransformHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEnvelopedSignatureTransform_IsTransformAlgorithmSupported(const sb_char16_t * pcAlgorithm, int32_t szAlgorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEnvelopedSignatureTransform_IsTransformAlgorithmSupported_1(TElXMLEnvelopedSignatureTransformHandle _Handle, const sb_char16_t * pcAlgorithm, int32_t szAlgorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEnvelopedSignatureTransform_GetDefaultStrictMode(int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEnvelopedSignatureTransform_GetDefaultStrictMode_1(TElXMLEnvelopedSignatureTransformHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEnvelopedSignatureTransform_SetDefaultStrictMode(int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEnvelopedSignatureTransform_SetDefaultStrictMode_1(TElXMLEnvelopedSignatureTransformHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEnvelopedSignatureTransform_TransformData(TElXMLEnvelopedSignatureTransformHandle _Handle, const uint8_t pData[], int32_t szData, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEnvelopedSignatureTransform_TransformData_1(TElXMLEnvelopedSignatureTransformHandle _Handle, TElXMLDOMNodeHandle Node, TElXMLDOMNodeHandle Reference, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEnvelopedSignatureTransform_TransformData_2(TElXMLEnvelopedSignatureTransformHandle _Handle, TElXMLDOMNodeListHandle Nodes, const TElXMLDOMNodeHandle pReference[], int32_t szReference, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEnvelopedSignatureTransform_TransformNode(TElXMLEnvelopedSignatureTransformHandle _Handle, TElXMLDOMNodeHandle Node, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEnvelopedSignatureTransform_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEnvelopedSignatureTransform_get_StrictMode(TElXMLEnvelopedSignatureTransformHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEnvelopedSignatureTransform_set_StrictMode(TElXMLEnvelopedSignatureTransformHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEnvelopedSignatureTransform_Create(TElXMLEnvelopedSignatureTransformHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLENVELOPEDSIGNATURETRANSFORM */

#ifdef SB_USE_CLASS_TELXMLXPATHTRANSFORM
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathTransform_GetDefaultTransformAlgorithmURI(sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathTransform_GetDefaultTransformAlgorithmURI_1(TElXMLXPathTransformHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathTransform_IsTransformAlgorithmSupported(const sb_char16_t * pcAlgorithm, int32_t szAlgorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathTransform_IsTransformAlgorithmSupported_1(TElXMLXPathTransformHandle _Handle, const sb_char16_t * pcAlgorithm, int32_t szAlgorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathTransform_Clear(TElXMLXPathTransformHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathTransform_LoadFromXML(TElXMLXPathTransformHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathTransform_SaveToXML(TElXMLXPathTransformHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathTransform_TransformData(TElXMLXPathTransformHandle _Handle, const uint8_t pData[], int32_t szData, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathTransform_TransformData_1(TElXMLXPathTransformHandle _Handle, TElXMLDOMNodeHandle Node, TElXMLDOMNodeHandle Reference, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathTransform_TransformData_2(TElXMLXPathTransformHandle _Handle, TElXMLDOMNodeListHandle Nodes, const TElXMLDOMNodeHandle pReference[], int32_t szReference, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathTransform_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathTransform_get_NamespaceMap(TElXMLXPathTransformHandle _Handle, TElXMLNamespaceMapHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathTransform_get_XPath(TElXMLXPathTransformHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathTransform_set_XPath(TElXMLXPathTransformHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathTransform_Create(TElXMLXPathTransformHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLXPATHTRANSFORM */

#ifdef SB_USE_CLASS_TELXMLXPATHFILTERITEM
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilterItem_get_Filter(TElXMLXPathFilterItemHandle _Handle, TSBXPathFilterOperationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilterItem_set_Filter(TElXMLXPathFilterItemHandle _Handle, TSBXPathFilterOperationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilterItem_get_NamespaceMap(TElXMLXPathFilterItemHandle _Handle, TElXMLNamespaceMapHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilterItem_get_XPath(TElXMLXPathFilterItemHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilterItem_set_XPath(TElXMLXPathFilterItemHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilterItem_get_XMLElement(TElXMLXPathFilterItemHandle _Handle, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilterItem_set_XMLElement(TElXMLXPathFilterItemHandle _Handle, TElXMLDOMElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilterItem_Create(TElXMLXPathFilterItemHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLXPATHFILTERITEM */

#ifdef SB_USE_CLASS_TELXMLXPATHFILTER2TRANSFORM
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilter2Transform_GetDefaultTransformAlgorithmURI(sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilter2Transform_GetDefaultTransformAlgorithmURI_1(TElXMLXPathFilter2TransformHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilter2Transform_IsTransformAlgorithmSupported(const sb_char16_t * pcAlgorithm, int32_t szAlgorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilter2Transform_IsTransformAlgorithmSupported_1(TElXMLXPathFilter2TransformHandle _Handle, const sb_char16_t * pcAlgorithm, int32_t szAlgorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilter2Transform_Add(TElXMLXPathFilter2TransformHandle _Handle, TElXMLXPathFilterItemHandle AFilter, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilter2Transform_Delete(TElXMLXPathFilter2TransformHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilter2Transform_Clear(TElXMLXPathFilter2TransformHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilter2Transform_LoadFromXML(TElXMLXPathFilter2TransformHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilter2Transform_SaveToXML(TElXMLXPathFilter2TransformHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilter2Transform_TransformData(TElXMLXPathFilter2TransformHandle _Handle, const uint8_t pData[], int32_t szData, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilter2Transform_TransformData_1(TElXMLXPathFilter2TransformHandle _Handle, TElXMLDOMNodeHandle Node, TElXMLDOMNodeHandle Reference, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilter2Transform_TransformData_2(TElXMLXPathFilter2TransformHandle _Handle, TElXMLDOMNodeListHandle Nodes, const TElXMLDOMNodeHandle pReference[], int32_t szReference, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilter2Transform_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilter2Transform_get_Count(TElXMLXPathFilter2TransformHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilter2Transform_get_Filter(TElXMLXPathFilter2TransformHandle _Handle, int32_t Index, TElXMLXPathFilterItemHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLXPathFilter2Transform_Create(TElXMLXPathFilter2TransformHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLXPATHFILTER2TRANSFORM */

#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransformChain_TransformData(TElXMLTransformChainHandle _Handle, const uint8_t pData[], int32_t szData, TElXMLCanonicalizationMethodRaw CanonicalizationMethod, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransformChain_TransformData_1(TElXMLTransformChainHandle _Handle, TElXMLDOMNodeHandle Node, TElXMLCanonicalizationMethodRaw CanonicalizationMethod, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransformChain_TransformData_2(TElXMLTransformChainHandle _Handle, TElXMLDOMNodeHandle Node, TElXMLDOMNodeHandle ReferenceNode, TElXMLCanonicalizationMethodRaw CanonicalizationMethod, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransformChain_TransformData_3(TElXMLTransformChainHandle _Handle, TElXMLDOMNodeListHandle Nodes, TElXMLCanonicalizationMethodRaw CanonicalizationMethod, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransformChain_TransformData_4(TElXMLTransformChainHandle _Handle, TElXMLDOMNodeListHandle Nodes, const TElXMLDOMNodeHandle pReferenceNodes[], int32_t szReferenceNodes, TElXMLCanonicalizationMethodRaw CanonicalizationMethod, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransformChain_CloneTransforms(TElXMLTransformChainHandle _Handle, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, TElXMLTransformChainHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransformChain_Add(TElXMLTransformChainHandle _Handle, TElXMLTransformHandle Transform, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransformChain_AddCanonicalizationTransform(TElXMLTransformChainHandle _Handle, TElXMLCanonicalizationMethodRaw AMethod, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransformChain_AddEnvelopedSignatureTransform(TElXMLTransformChainHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransformChain_Insert(TElXMLTransformChainHandle _Handle, int32_t Index, TElXMLTransformHandle Transform);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransformChain_Delete(TElXMLTransformChainHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransformChain_Clear(TElXMLTransformChainHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransformChain_IndexOf(TElXMLTransformChainHandle _Handle, TElXMLTransformHandle Transform, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransformChain_IsEmpty(TElXMLTransformChainHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransformChain_LoadFromXML(TElXMLTransformChainHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransformChain_SaveToXML(TElXMLTransformChainHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransformChain_get_Count(TElXMLTransformChainHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransformChain_get_Transforms(TElXMLTransformChainHandle _Handle, int32_t Index, TElXMLTransformHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTransformChain_Create(const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, TElXMLTransformChainHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */

#ifdef SB_USE_CLASS_TELXMLUNSUPPORTEDTRANSFORM
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsupportedTransform_GetDefaultTransformAlgorithmURI(sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsupportedTransform_GetDefaultTransformAlgorithmURI_1(TElXMLUnsupportedTransformHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsupportedTransform_IsTransformAlgorithmSupported(const sb_char16_t * pcAlgorithm, int32_t szAlgorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsupportedTransform_IsTransformAlgorithmSupported_1(TElXMLUnsupportedTransformHandle _Handle, const sb_char16_t * pcAlgorithm, int32_t szAlgorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsupportedTransform_SaveToXML(TElXMLUnsupportedTransformHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsupportedTransform_TransformData(TElXMLUnsupportedTransformHandle _Handle, const uint8_t pData[], int32_t szData, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsupportedTransform_TransformData_1(TElXMLUnsupportedTransformHandle _Handle, TElXMLDOMNodeHandle Node, TElXMLDOMNodeHandle Reference, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsupportedTransform_TransformData_2(TElXMLUnsupportedTransformHandle _Handle, TElXMLDOMNodeListHandle Nodes, const TElXMLDOMNodeHandle pReference[], int32_t szReference, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsupportedTransform_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsupportedTransform_Create(TElXMLUnsupportedTransformHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLUNSUPPORTEDTRANSFORM */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElXMLTransform;
typedef TElXMLTransform ElXMLTransform;
class TElXMLNullTransform;
typedef TElXMLNullTransform ElXMLNullTransform;
class TElXMLBase64Transform;
typedef TElXMLBase64Transform ElXMLBase64Transform;
class TElXMLC14NTransform;
typedef TElXMLC14NTransform ElXMLC14NTransform;
class TElXMLEnvelopedSignatureTransform;
typedef TElXMLEnvelopedSignatureTransform ElXMLEnvelopedSignatureTransform;
class TElXMLXPathTransform;
typedef TElXMLXPathTransform ElXMLXPathTransform;
class TElXMLXPathFilterItem;
class TElXMLXPathFilter2Transform;
class TElXMLTransformChain;
typedef TElXMLTransformChain ElXMLTransformChain;
class TElXMLUnsupportedTransform;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBTransformProperties)

#ifdef SB_USE_CLASS_TELXMLTRANSFORM
class TElXMLTransform: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLTransform)
#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNode* _Inst_TransformedNode;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
		TElXMLDOMNodeList* _Inst_TransformedNodes;
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */
#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNode* _Inst_ReferenceNode;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		void initInstances();

	public:
		static void GetDefaultTransformAlgorithmURI(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		static void GetDefaultTransformAlgorithmURI(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		virtual void GetDefaultTransformAlgorithmURI_Inst(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		virtual void GetDefaultTransformAlgorithmURI_Inst(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		static bool IsTransformAlgorithmSupported(const sb_u16string &Algorithm);
#ifdef SB_U16STRING_USED
		static bool IsTransformAlgorithmSupported(const std::wstring &Algorithm);
#endif /* SB_U16STRING_USED */

		virtual bool IsTransformAlgorithmSupported_Inst(const sb_u16string &Algorithm);
#ifdef SB_U16STRING_USED
		virtual bool IsTransformAlgorithmSupported_Inst(const std::wstring &Algorithm);
#endif /* SB_U16STRING_USED */

		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual TSBTransformedDataType TransformData(const std::vector<uint8_t> &Data);

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TSBTransformedDataType TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &Reference);

		virtual TSBTransformedDataType TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *Reference);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
		virtual TSBTransformedDataType TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference);

		virtual TSBTransformedDataType TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference);
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

		static TClassHandle ClassType();

		virtual void get_TransformAlgorithmURI(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_TransformAlgorithmURI(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_TransformAlgorithmURI(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_TransformAlgorithmURI(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_TransformedData(std::vector<uint8_t> &OutResult);

		virtual void set_TransformedData(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TElXMLDOMNode* get_TransformedNode();

		virtual void set_TransformedNode(TElXMLDOMNode &Value);

		virtual void set_TransformedNode(TElXMLDOMNode *Value);

		SB_DECLARE_PROPERTY(TElXMLDOMNode*, get_TransformedNode, set_TransformedNode, TElXMLTransform, TransformedNode);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
		virtual TElXMLDOMNodeList* get_TransformedNodes();

		virtual void set_TransformedNodes(TElXMLDOMNodeList &Value);

		virtual void set_TransformedNodes(TElXMLDOMNodeList *Value);

		SB_DECLARE_PROPERTY(TElXMLDOMNodeList*, get_TransformedNodes, set_TransformedNodes, TElXMLTransform, TransformedNodes);
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TElXMLDOMNode* get_ReferenceNode();

		virtual void set_ReferenceNode(TElXMLDOMNode &Value);

		virtual void set_ReferenceNode(TElXMLDOMNode *Value);

		SB_DECLARE_PROPERTY(TElXMLDOMNode*, get_ReferenceNode, set_ReferenceNode, TElXMLTransform, ReferenceNode);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		virtual void get_ReferenceNodes(std::vector<TElXMLDOMNodeHandle> &OutResult);

		virtual void set_ReferenceNodes(const std::vector<TElXMLDOMNodeHandle> &Value);

		TElXMLTransform(TElXMLTransformHandle handle, TElOwnHandle ownHandle);

		TElXMLTransform();

		virtual ~TElXMLTransform();

};
#endif /* SB_USE_CLASS_TELXMLTRANSFORM */

#ifdef SB_USE_CLASS_TELXMLNULLTRANSFORM
class TElXMLNullTransform: public TElXMLTransform
{
	private:
		SB_DISABLE_COPY(TElXMLNullTransform)
	public:
		static void GetDefaultTransformAlgorithmURI(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		static void GetDefaultTransformAlgorithmURI(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		virtual void GetDefaultTransformAlgorithmURI_Inst(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		virtual void GetDefaultTransformAlgorithmURI_Inst(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		static bool IsTransformAlgorithmSupported(const sb_u16string &Algorithm);
#ifdef SB_U16STRING_USED
		static bool IsTransformAlgorithmSupported(const std::wstring &Algorithm);
#endif /* SB_U16STRING_USED */

		virtual bool IsTransformAlgorithmSupported_Inst(const sb_u16string &Algorithm);
#ifdef SB_U16STRING_USED
		virtual bool IsTransformAlgorithmSupported_Inst(const std::wstring &Algorithm);
#endif /* SB_U16STRING_USED */

		virtual TSBTransformedDataType TransformData(const std::vector<uint8_t> &Data);

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TSBTransformedDataType TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &Reference);

		virtual TSBTransformedDataType TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *Reference);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
		virtual TSBTransformedDataType TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference);

		virtual TSBTransformedDataType TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference);
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

		static TClassHandle ClassType();

		TElXMLNullTransform(TElXMLNullTransformHandle handle, TElOwnHandle ownHandle);

		TElXMLNullTransform();

};
#endif /* SB_USE_CLASS_TELXMLNULLTRANSFORM */

#ifdef SB_USE_CLASS_TELXMLBASE64TRANSFORM
class TElXMLBase64Transform: public TElXMLTransform
{
	private:
		SB_DISABLE_COPY(TElXMLBase64Transform)
	public:
		static void GetDefaultTransformAlgorithmURI(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		static void GetDefaultTransformAlgorithmURI(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		virtual void GetDefaultTransformAlgorithmURI_Inst(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		virtual void GetDefaultTransformAlgorithmURI_Inst(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		static bool IsTransformAlgorithmSupported(const sb_u16string &Algorithm);
#ifdef SB_U16STRING_USED
		static bool IsTransformAlgorithmSupported(const std::wstring &Algorithm);
#endif /* SB_U16STRING_USED */

		virtual bool IsTransformAlgorithmSupported_Inst(const sb_u16string &Algorithm);
#ifdef SB_U16STRING_USED
		virtual bool IsTransformAlgorithmSupported_Inst(const std::wstring &Algorithm);
#endif /* SB_U16STRING_USED */

		virtual TSBTransformedDataType TransformData(const std::vector<uint8_t> &Data);

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TSBTransformedDataType TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &Reference);

		virtual TSBTransformedDataType TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *Reference);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
		virtual TSBTransformedDataType TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference);

		virtual TSBTransformedDataType TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference);
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

		static TClassHandle ClassType();

		virtual bool get_OldMode();

		virtual void set_OldMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OldMode, set_OldMode, TElXMLBase64Transform, OldMode);

		TElXMLBase64Transform(TElXMLBase64TransformHandle handle, TElOwnHandle ownHandle);

		TElXMLBase64Transform();

};
#endif /* SB_USE_CLASS_TELXMLBASE64TRANSFORM */

#ifdef SB_USE_CLASS_TELXMLC14NTRANSFORM
class TElXMLC14NTransform: public TElXMLTransform
{
	private:
		SB_DISABLE_COPY(TElXMLC14NTransform)
	public:
		static void GetDefaultTransformAlgorithmURI(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		static void GetDefaultTransformAlgorithmURI(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		virtual void GetDefaultTransformAlgorithmURI_Inst(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		virtual void GetDefaultTransformAlgorithmURI_Inst(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		static bool IsTransformAlgorithmSupported(const sb_u16string &Algorithm);
#ifdef SB_U16STRING_USED
		static bool IsTransformAlgorithmSupported(const std::wstring &Algorithm);
#endif /* SB_U16STRING_USED */

		virtual bool IsTransformAlgorithmSupported_Inst(const sb_u16string &Algorithm);
#ifdef SB_U16STRING_USED
		virtual bool IsTransformAlgorithmSupported_Inst(const std::wstring &Algorithm);
#endif /* SB_U16STRING_USED */

		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual TSBTransformedDataType TransformData(const std::vector<uint8_t> &Data);

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TSBTransformedDataType TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &Reference);

		virtual TSBTransformedDataType TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *Reference);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
		virtual TSBTransformedDataType TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference);

		virtual TSBTransformedDataType TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference);
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

		static TClassHandle ClassType();

		virtual TElXMLCanonicalizationMethod get_CanonicalizationMethod();

		virtual void set_CanonicalizationMethod(TElXMLCanonicalizationMethod Value);

		SB_DECLARE_PROPERTY(TElXMLCanonicalizationMethod, get_CanonicalizationMethod, set_CanonicalizationMethod, TElXMLC14NTransform, CanonicalizationMethod);

		virtual void get_ExclusiveCanonicalizationPrefix(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ExclusiveCanonicalizationPrefix(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ExclusiveCanonicalizationPrefix(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ExclusiveCanonicalizationPrefix(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_InclusiveNamespacesPrefixList(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_InclusiveNamespacesPrefixList(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_InclusiveNamespacesPrefixList(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_InclusiveNamespacesPrefixList(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLC14NTransform(TElXMLC14NTransformHandle handle, TElOwnHandle ownHandle);

		TElXMLC14NTransform();

		explicit TElXMLC14NTransform(TElXMLCanonicalizationMethod AMethod);

};
#endif /* SB_USE_CLASS_TELXMLC14NTRANSFORM */

#ifdef SB_USE_CLASS_TELXMLENVELOPEDSIGNATURETRANSFORM
class TElXMLEnvelopedSignatureTransform: public TElXMLTransform
{
	private:
		SB_DISABLE_COPY(TElXMLEnvelopedSignatureTransform)
	public:
		static void GetDefaultTransformAlgorithmURI(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		static void GetDefaultTransformAlgorithmURI(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		virtual void GetDefaultTransformAlgorithmURI_Inst(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		virtual void GetDefaultTransformAlgorithmURI_Inst(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		static bool IsTransformAlgorithmSupported(const sb_u16string &Algorithm);
#ifdef SB_U16STRING_USED
		static bool IsTransformAlgorithmSupported(const std::wstring &Algorithm);
#endif /* SB_U16STRING_USED */

		virtual bool IsTransformAlgorithmSupported_Inst(const sb_u16string &Algorithm);
#ifdef SB_U16STRING_USED
		virtual bool IsTransformAlgorithmSupported_Inst(const std::wstring &Algorithm);
#endif /* SB_U16STRING_USED */

		static bool GetDefaultStrictMode();

		bool GetDefaultStrictMode_Inst();

		static void SetDefaultStrictMode(bool Value);

		void SetDefaultStrictMode_Inst(bool Value);

		virtual TSBTransformedDataType TransformData(const std::vector<uint8_t> &Data);

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TSBTransformedDataType TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &Reference);

		virtual TSBTransformedDataType TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *Reference);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
		virtual TSBTransformedDataType TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference);

		virtual TSBTransformedDataType TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference);
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNodeHandle TransformNode(TElXMLDOMNode &Node);

		TElXMLDOMNodeHandle TransformNode(TElXMLDOMNode *Node);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		static TClassHandle ClassType();

		virtual bool get_StrictMode();

		virtual void set_StrictMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_StrictMode, set_StrictMode, TElXMLEnvelopedSignatureTransform, StrictMode);

		TElXMLEnvelopedSignatureTransform(TElXMLEnvelopedSignatureTransformHandle handle, TElOwnHandle ownHandle);

		TElXMLEnvelopedSignatureTransform();

};
#endif /* SB_USE_CLASS_TELXMLENVELOPEDSIGNATURETRANSFORM */

#ifdef SB_USE_CLASS_TELXMLXPATHTRANSFORM
class TElXMLXPathTransform: public TElXMLTransform
{
	private:
		SB_DISABLE_COPY(TElXMLXPathTransform)
#ifdef SB_USE_CLASS_TELXMLNAMESPACEMAP
		TElXMLNamespaceMap* _Inst_NamespaceMap;
#endif /* SB_USE_CLASS_TELXMLNAMESPACEMAP */

		void initInstances();

	public:
		static void GetDefaultTransformAlgorithmURI(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		static void GetDefaultTransformAlgorithmURI(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		virtual void GetDefaultTransformAlgorithmURI_Inst(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		virtual void GetDefaultTransformAlgorithmURI_Inst(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		static bool IsTransformAlgorithmSupported(const sb_u16string &Algorithm);
#ifdef SB_U16STRING_USED
		static bool IsTransformAlgorithmSupported(const std::wstring &Algorithm);
#endif /* SB_U16STRING_USED */

		virtual bool IsTransformAlgorithmSupported_Inst(const sb_u16string &Algorithm);
#ifdef SB_U16STRING_USED
		virtual bool IsTransformAlgorithmSupported_Inst(const std::wstring &Algorithm);
#endif /* SB_U16STRING_USED */

		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual TSBTransformedDataType TransformData(const std::vector<uint8_t> &Data);

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TSBTransformedDataType TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &Reference);

		virtual TSBTransformedDataType TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *Reference);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
		virtual TSBTransformedDataType TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference);

		virtual TSBTransformedDataType TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference);
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

		static TClassHandle ClassType();

#ifdef SB_USE_CLASS_TELXMLNAMESPACEMAP
		virtual TElXMLNamespaceMap* get_NamespaceMap();

		SB_DECLARE_PROPERTY_GET(TElXMLNamespaceMap*, get_NamespaceMap, TElXMLXPathTransform, NamespaceMap);
#endif /* SB_USE_CLASS_TELXMLNAMESPACEMAP */

		virtual void get_XPath(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_XPath(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_XPath(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_XPath(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLXPathTransform(TElXMLXPathTransformHandle handle, TElOwnHandle ownHandle);

		TElXMLXPathTransform();

		virtual ~TElXMLXPathTransform();

};
#endif /* SB_USE_CLASS_TELXMLXPATHTRANSFORM */

#ifdef SB_USE_CLASS_TELXMLXPATHFILTERITEM
class TElXMLXPathFilterItem: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLXPathFilterItem)
#ifdef SB_USE_CLASS_TELXMLNAMESPACEMAP
		TElXMLNamespaceMap* _Inst_NamespaceMap;
#endif /* SB_USE_CLASS_TELXMLNAMESPACEMAP */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLDOMElement* _Inst_XMLElement;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		void initInstances();

	public:
		virtual TSBXPathFilterOperation get_Filter();

		virtual void set_Filter(TSBXPathFilterOperation Value);

		SB_DECLARE_PROPERTY(TSBXPathFilterOperation, get_Filter, set_Filter, TElXMLXPathFilterItem, Filter);

#ifdef SB_USE_CLASS_TELXMLNAMESPACEMAP
		virtual TElXMLNamespaceMap* get_NamespaceMap();

		SB_DECLARE_PROPERTY_GET(TElXMLNamespaceMap*, get_NamespaceMap, TElXMLXPathFilterItem, NamespaceMap);
#endif /* SB_USE_CLASS_TELXMLNAMESPACEMAP */

		virtual void get_XPath(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_XPath(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_XPath(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_XPath(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual TElXMLDOMElement* get_XMLElement();

		virtual void set_XMLElement(TElXMLDOMElement &Value);

		virtual void set_XMLElement(TElXMLDOMElement *Value);

		SB_DECLARE_PROPERTY(TElXMLDOMElement*, get_XMLElement, set_XMLElement, TElXMLXPathFilterItem, XMLElement);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		TElXMLXPathFilterItem(TElXMLXPathFilterItemHandle handle, TElOwnHandle ownHandle);

		TElXMLXPathFilterItem();

		virtual ~TElXMLXPathFilterItem();

};
#endif /* SB_USE_CLASS_TELXMLXPATHFILTERITEM */

#ifdef SB_USE_CLASS_TELXMLXPATHFILTER2TRANSFORM
class TElXMLXPathFilter2Transform: public TElXMLTransform
{
	private:
		SB_DISABLE_COPY(TElXMLXPathFilter2Transform)
#ifdef SB_USE_CLASS_TELXMLXPATHFILTERITEM
		TElXMLXPathFilterItem* _Inst_Filter;
#endif /* SB_USE_CLASS_TELXMLXPATHFILTERITEM */

		void initInstances();

	public:
		static void GetDefaultTransformAlgorithmURI(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		static void GetDefaultTransformAlgorithmURI(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		virtual void GetDefaultTransformAlgorithmURI_Inst(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		virtual void GetDefaultTransformAlgorithmURI_Inst(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		static bool IsTransformAlgorithmSupported(const sb_u16string &Algorithm);
#ifdef SB_U16STRING_USED
		static bool IsTransformAlgorithmSupported(const std::wstring &Algorithm);
#endif /* SB_U16STRING_USED */

		virtual bool IsTransformAlgorithmSupported_Inst(const sb_u16string &Algorithm);
#ifdef SB_U16STRING_USED
		virtual bool IsTransformAlgorithmSupported_Inst(const std::wstring &Algorithm);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLXPATHFILTERITEM
		int32_t Add(TElXMLXPathFilterItem &AFilter);

		int32_t Add(TElXMLXPathFilterItem *AFilter);
#endif /* SB_USE_CLASS_TELXMLXPATHFILTERITEM */

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

		virtual TSBTransformedDataType TransformData(const std::vector<uint8_t> &Data);

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TSBTransformedDataType TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &Reference);

		virtual TSBTransformedDataType TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *Reference);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
		virtual TSBTransformedDataType TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference);

		virtual TSBTransformedDataType TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference);
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

		static TClassHandle ClassType();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLXPathFilter2Transform, Count);

#ifdef SB_USE_CLASS_TELXMLXPATHFILTERITEM
		virtual TElXMLXPathFilterItem* get_Filter(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLXPATHFILTERITEM */

		TElXMLXPathFilter2Transform(TElXMLXPathFilter2TransformHandle handle, TElOwnHandle ownHandle);

		TElXMLXPathFilter2Transform();

		virtual ~TElXMLXPathFilter2Transform();

};
#endif /* SB_USE_CLASS_TELXMLXPATHFILTER2TRANSFORM */

#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
class TElXMLTransformChain: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLTransformChain)
#ifdef SB_USE_CLASS_TELXMLTRANSFORM
		TElXMLTransform* _Inst_Transforms;
#endif /* SB_USE_CLASS_TELXMLTRANSFORM */

		void initInstances();

	public:
		void TransformData(const std::vector<uint8_t> &Data, TElXMLCanonicalizationMethod CanonicalizationMethod, std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		void TransformData(TElXMLDOMNode &Node, TElXMLCanonicalizationMethod CanonicalizationMethod, std::vector<uint8_t> &OutResult);

		void TransformData(TElXMLDOMNode *Node, TElXMLCanonicalizationMethod CanonicalizationMethod, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		void TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &ReferenceNode, TElXMLCanonicalizationMethod CanonicalizationMethod, std::vector<uint8_t> &OutResult);

		void TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *ReferenceNode, TElXMLCanonicalizationMethod CanonicalizationMethod, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
		void TransformData(TElXMLDOMNodeList &Nodes, TElXMLCanonicalizationMethod CanonicalizationMethod, std::vector<uint8_t> &OutResult);

		void TransformData(TElXMLDOMNodeList *Nodes, TElXMLCanonicalizationMethod CanonicalizationMethod, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
		void TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &ReferenceNodes, TElXMLCanonicalizationMethod CanonicalizationMethod, std::vector<uint8_t> &OutResult);

		void TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &ReferenceNodes, TElXMLCanonicalizationMethod CanonicalizationMethod, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

		TElXMLTransformChainHandle CloneTransforms(const sb_u16string &ANamespaceURI);
#ifdef SB_U16STRING_USED
		TElXMLTransformChainHandle CloneTransforms(const std::wstring &ANamespaceURI);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLTRANSFORM
		int32_t Add(TElXMLTransform &Transform);

		int32_t Add(TElXMLTransform *Transform);
#endif /* SB_USE_CLASS_TELXMLTRANSFORM */

		int32_t AddCanonicalizationTransform(TElXMLCanonicalizationMethod AMethod);

		int32_t AddEnvelopedSignatureTransform();

#ifdef SB_USE_CLASS_TELXMLTRANSFORM
		void Insert(int32_t Index, TElXMLTransform &Transform);

		void Insert(int32_t Index, TElXMLTransform *Transform);
#endif /* SB_USE_CLASS_TELXMLTRANSFORM */

		void Delete(int32_t Index);

		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLTRANSFORM
		int32_t IndexOf(TElXMLTransform &Transform);

		int32_t IndexOf(TElXMLTransform *Transform);
#endif /* SB_USE_CLASS_TELXMLTRANSFORM */

		bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLTransformChain, Count);

#ifdef SB_USE_CLASS_TELXMLTRANSFORM
		virtual TElXMLTransform* get_Transforms(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLTRANSFORM */

		TElXMLTransformChain(TElXMLTransformChainHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLTransformChain(const sb_u16string &ANamespaceURI);

#ifdef SB_U16STRING_USED
		explicit TElXMLTransformChain(const std::wstring &ANamespaceURI);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLTransformChain();

};
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */

#ifdef SB_USE_CLASS_TELXMLUNSUPPORTEDTRANSFORM
class TElXMLUnsupportedTransform: public TElXMLTransform
{
	private:
		SB_DISABLE_COPY(TElXMLUnsupportedTransform)
	public:
		static void GetDefaultTransformAlgorithmURI(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		static void GetDefaultTransformAlgorithmURI(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		virtual void GetDefaultTransformAlgorithmURI_Inst(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		virtual void GetDefaultTransformAlgorithmURI_Inst(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		static bool IsTransformAlgorithmSupported(const sb_u16string &Algorithm);
#ifdef SB_U16STRING_USED
		static bool IsTransformAlgorithmSupported(const std::wstring &Algorithm);
#endif /* SB_U16STRING_USED */

		virtual bool IsTransformAlgorithmSupported_Inst(const sb_u16string &Algorithm);
#ifdef SB_U16STRING_USED
		virtual bool IsTransformAlgorithmSupported_Inst(const std::wstring &Algorithm);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual TSBTransformedDataType TransformData(const std::vector<uint8_t> &Data);

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TSBTransformedDataType TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &Reference);

		virtual TSBTransformedDataType TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *Reference);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
		virtual TSBTransformedDataType TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference);

		virtual TSBTransformedDataType TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference);
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

		static TClassHandle ClassType();

		TElXMLUnsupportedTransform(TElXMLUnsupportedTransformHandle handle, TElOwnHandle ownHandle);

		TElXMLUnsupportedTransform();

};
#endif /* SB_USE_CLASS_TELXMLUNSUPPORTEDTRANSFORM */

#ifdef SB_USE_GLOBAL_PROCS_XMLTRANSFORM

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
TElXMLDOMDocumentHandle LoadDocumentFromData(const std::vector<uint8_t> &Data);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
TElXMLDOMNodeListHandle NodeToNodeList(const TElXMLDOMNode &Node);
TElXMLDOMNodeListHandle NodeToNodeList(const TElXMLDOMNode *Node);
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

void RegisterTransformClass(TElXMLTransformClassHandle TransformClass);

void UnregisterTransformClass(TElXMLTransformClassHandle TransformClass);

TElXMLTransformClassHandle FindTransformClass(const sb_u16string &Algorithm);
#ifdef SB_U16STRING_USED
TElXMLTransformClassHandle FindTransformClass(const std::wstring &Algorithm);
#endif /* SB_U16STRING_USED */

#endif /* SB_USE_GLOBAL_PROCS_XMLTRANSFORM */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_XMLTRANSFORM
SB_IMPORT uint32_t SB_APIENTRY SBXMLTransform_Initialize(void);
SB_IMPORT uint32_t SB_APIENTRY SBXMLTransform_LoadDocumentFromData(const uint8_t pData[], int32_t szData, TElXMLDOMDocumentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLTransform_NodeToNodeList(const TElXMLDOMNodeHandle Node, TElXMLDOMNodeListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLTransform_RegisterTransformClass(TElXMLTransformClassHandle TransformClass);
SB_IMPORT uint32_t SB_APIENTRY SBXMLTransform_UnregisterTransformClass(TElXMLTransformClassHandle TransformClass);
SB_IMPORT uint32_t SB_APIENTRY SBXMLTransform_FindTransformClass(const sb_char16_t * pcAlgorithm, int32_t szAlgorithm, TElXMLTransformClassHandle * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_XMLTRANSFORM */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBXMLTRANSFORM */

