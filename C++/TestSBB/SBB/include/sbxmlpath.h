#ifndef __INC_SBXMLPATH
#define __INC_SBXMLPATH

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbxmlcore.h"
#include "sbxmldefs.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbstrutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElXPathHandle;

typedef TElXPathHandle ElXPathHandle;

typedef TElClassHandle TElNumberHandle;

typedef TElNumberHandle ElNumberHandle;

typedef TElClassHandle TElBooleanHandle;

typedef TElBooleanHandle ElBooleanHandle;

typedef TElClassHandle TElStringHandle;

typedef TElStringHandle ElStringHandle;

typedef TElClassHandle TElXMLVarMapHandle;

typedef TElXMLVarMapHandle ElXMLVarMapHandle;

typedef TElClassHandle TElXPathNodeHandle;

typedef TElXPathNodeHandle ElXPathNodeHandle;

typedef TElClassHandle TElUnionExprNodeHandle;

typedef TElUnionExprNodeHandle ElUnionExprNodeHandle;

typedef TElClassHandle TElPathExprNodeHandle;

typedef TElPathExprNodeHandle ElPathExprNodeHandle;

typedef TElClassHandle TElLocationPathNodeHandle;

typedef TElLocationPathNodeHandle ElLocationPathNodeHandle;

typedef TElClassHandle TElAbsoluteLocationPathNodeHandle;

typedef TElAbsoluteLocationPathNodeHandle ElAbsoluteLocationPathNodeHandle;

typedef TElClassHandle TElRelativeLocationPathNodeHandle;

typedef TElRelativeLocationPathNodeHandle ElRelativeLocationPathNodeHandle;

typedef TElClassHandle TElStepNodeHandle;

typedef TElStepNodeHandle ElStepNodeHandle;

typedef TElClassHandle TElPredicateNodeHandle;

typedef TElPredicateNodeHandle ElPredicateNodeHandle;

typedef TElClassHandle TElOrExprNodeHandle;

typedef TElOrExprNodeHandle ElOrExprNodeHandle;

typedef TElClassHandle TElAndExprNodeHandle;

typedef TElAndExprNodeHandle ElAndExprNodeHandle;

typedef TElClassHandle TElEqualityExprNodeHandle;

typedef TElEqualityExprNodeHandle ElEqualityExprNodeHandle;

typedef TElClassHandle TElRelationalExprNodeHandle;

typedef TElRelationalExprNodeHandle ElRelationalExprNodeHandle;

typedef TElClassHandle TElAdditiveExprNodeHandle;

typedef TElAdditiveExprNodeHandle ElAdditiveExprNodeHandle;

typedef TElClassHandle TElMultiplicativeExprNodeHandle;

typedef TElMultiplicativeExprNodeHandle ElMultiplicativeExprNodeHandle;

typedef TElClassHandle TElUnaryExprNodeHandle;

typedef TElUnaryExprNodeHandle ElUnaryExprNodeHandle;

typedef TElClassHandle TElFilterExprNodeHandle;

typedef TElFilterExprNodeHandle ElFilterExprNodeHandle;

typedef TElClassHandle TElPrimaryExprNodeHandle;

typedef TElPrimaryExprNodeHandle ElPrimaryExprNodeHandle;

typedef TElClassHandle TElVariableReferenceNodeHandle;

typedef TElVariableReferenceNodeHandle ElVariableReferenceNodeHandle;

typedef TElClassHandle TElLiteralNodeHandle;

typedef TElLiteralNodeHandle ElLiteralNodeHandle;

typedef TElClassHandle TElNumberNodeHandle;

typedef TElNumberNodeHandle ElNumberNodeHandle;

typedef TElClassHandle TElFunctionCallNodeHandle;

typedef TElFunctionCallNodeHandle ElFunctionCallNodeHandle;

typedef uint8_t TXPathNodeTypeRaw;

typedef enum
{
	pntUnknown = 0,
	pntUnionExpr = 1,
	pntPathExpr = 2,
	pntFilterExpr = 3,
	pntAbsoluteLocationPath = 4,
	pntRelativeLocationPath = 5,
	pntStep = 6,
	pntPredicate = 7,
	pntOrExpr = 8,
	pntAndExpr = 9,
	pntEqualityExpr = 10,
	pntRelationalExpr = 11,
	pntAdditiveExpr = 12,
	pntMultiplicativeExpr = 13,
	pntUnaryExpr = 14,
	pntPrimaryExpr = 15,
	pntVariableReference = 16,
	pntLiteral = 17,
	pntNumber = 18,
	pntFunctionCall = 19
} TXPathNodeType;

typedef uint8_t TElAxisTypeRaw;

typedef enum
{
	atAncestor = 0,
	atAncestor_or_self = 1,
	atAttribute = 2,
	atChild = 3,
	atDescendant = 4,
	atDescendant_or_self = 5,
	atFollowing = 6,
	atFollowing_sibling = 7,
	atNamespace = 8,
	atParent = 9,
	atPreceding = 10,
	atPreceding_sibling = 11,
	atSelf = 12
} TElAxisType;

typedef uint8_t TElNodeTestTypeRaw;

typedef enum
{
	ntNameTest = 0,
	ntNodeTypeComent = 1,
	ntNodeTypeText = 2,
	ntNodeTypeProcessingInstruction = 3,
	ntNodeTypeNode = 4
} TElNodeTestType;

typedef uint8_t TElEqualityExprTypeRaw;

typedef enum
{
	eetEqual = 0,
	eetUnequal = 1
} TElEqualityExprType;

typedef uint8_t TElRelationalExprTypeRaw;

typedef enum
{
	retLess = 0,
	retAdvance = 1,
	retLessOrEqual = 2,
	retAdvanceOrEqual = 3
} TElRelationalExprType;

typedef uint8_t TElAdditiveExprTypeRaw;

typedef enum
{
	aetAdd = 0,
	retSub = 1
} TElAdditiveExprType;

typedef uint8_t TElMultiplicativeExprTypeRaw;

typedef enum
{
	metMul = 0,
	metDiv = 1,
	metMod = 2
} TElMultiplicativeExprType;

typedef void (SB_CALLBACK *TSBXPathCustomFunctionEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcFunctionName, int32_t szFunctionName, TListHandle * List);

#ifdef SB_USE_CLASS_TELXPATH
SB_IMPORT uint32_t SB_APIENTRY TElXPath_ProcessQuery(TElXPathHandle _Handle, const sb_char16_t * pcXPathQuery, int32_t szXPathQuery, TElXMLNodeSetHandle List, TElXMLDOMNodeHandle Node, TElXMLNamespaceMapHandle NSList, TElXMLVarMapHandle VarMap);
SB_IMPORT uint32_t SB_APIENTRY TElXPath_get_OnCustomFunction(TElXPathHandle _Handle, TSBXPathCustomFunctionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXPath_set_OnCustomFunction(TElXPathHandle _Handle, TSBXPathCustomFunctionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXPath_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELNUMBER
SB_IMPORT uint32_t SB_APIENTRY TElNumber_IsNaN(TElNumberHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElNumber_IsInteger(TElNumberHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElNumber_GetInteger(TElNumberHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElNumber_GetReal(TElNumberHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElNumber_SetReal(TElNumberHandle _Handle, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElNumber_Create(TElNumberHandle * OutResult);
#endif /* SB_USE_CLASS_TELNUMBER */

#ifdef SB_USE_CLASS_TELBOOLEAN
SB_IMPORT uint32_t SB_APIENTRY TElBoolean_IsNaN(TElBooleanHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoolean_GetValue(TElBooleanHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoolean_Create(TElBooleanHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOOLEAN */

#ifdef SB_USE_CLASS_TELSTRING
SB_IMPORT uint32_t SB_APIENTRY TElString_IsNaN(TElStringHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElString_GetValue(TElStringHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElString_Create(TElStringHandle * OutResult);
#endif /* SB_USE_CLASS_TELSTRING */

#ifdef SB_USE_CLASS_TELXMLVARMAP
SB_IMPORT uint32_t SB_APIENTRY TElXMLVarMap_Add(TElXMLVarMapHandle _Handle, const sb_char16_t * pcVarName, int32_t szVarName, TObjectHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVarMap_AddNodeList(TElXMLVarMapHandle _Handle, const sb_char16_t * pcVarName, int32_t szVarName, TElXMLNodeSetHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVarMap_AddBoolean(TElXMLVarMapHandle _Handle, const sb_char16_t * pcVarName, int32_t szVarName, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVarMap_AddNumber(TElXMLVarMapHandle _Handle, const sb_char16_t * pcVarName, int32_t szVarName, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVarMap_AddString(TElXMLVarMapHandle _Handle, const sb_char16_t * pcVarName, int32_t szVarName, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVarMap_Clear(TElXMLVarMapHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVarMap_Delete(TElXMLVarMapHandle _Handle, const sb_char16_t * pcVarName, int32_t szVarName);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVarMap_GetValue(TElXMLVarMapHandle _Handle, const sb_char16_t * pcVarName, int32_t szVarName, TObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVarMap_Create(TElXMLVarMapHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLVARMAP */

#ifdef SB_USE_CLASS_TELXPATHNODE
SB_IMPORT uint32_t SB_APIENTRY TElXPathNode_DestroyNode(TElXPathNodeHandle Node);
SB_IMPORT uint32_t SB_APIENTRY TElXPathNode_DestroyNode_1(TElXPathNodeHandle _Handle, TElXPathNodeHandle Node);
SB_IMPORT uint32_t SB_APIENTRY TElXPathNode_GetResultList(TElXPathNodeHandle _Handle, TListHandle List, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXPathNode_GetResultNumber(TElXPathNodeHandle _Handle, TElXMLDOMNodeHandle Context, TListHandle List, TElNumberHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXPathNode_GetResultBoolean(TElXPathNodeHandle _Handle, TElXMLDOMNodeHandle Context, TListHandle List, TElBooleanHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXPathNode_GetResultString(TElXPathNodeHandle _Handle, TElXMLDOMNodeHandle Context, TListHandle List, TElStringHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXPathNode_GetResult(TElXPathNodeHandle _Handle, TElXMLDOMNodeHandle Context, TListHandle InList, int32_t * iType, TListHandle * List, TElBooleanHandle * Boolean, TElNumberHandle * Number, TElStringHandle * sString);
SB_IMPORT uint32_t SB_APIENTRY TElXPathNode_Create(TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
#endif /* SB_USE_CLASS_TELXPATHNODE */

#ifdef SB_USE_CLASS_TELUNIONEXPRNODE
SB_IMPORT uint32_t SB_APIENTRY TElUnionExprNode_CreateNode(const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUnionExprNode_CreateNode_1(TElUnionExprNodeHandle _Handle, const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUnionExprNode_GetResList(TElUnionExprNodeHandle _Handle, TListHandle List, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUnionExprNode_Create(TElXPathHandle XPath, TElUnionExprNodeHandle * OutResult);
#endif /* SB_USE_CLASS_TELUNIONEXPRNODE */

#ifdef SB_USE_CLASS_TELPATHEXPRNODE
SB_IMPORT uint32_t SB_APIENTRY TElPathExprNode_CreateNode(const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPathExprNode_CreateNode_1(TElPathExprNodeHandle _Handle, const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPathExprNode_GetResList(TElPathExprNodeHandle _Handle, TListHandle List, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPathExprNode_Create(TElXPathHandle XPath, TElPathExprNodeHandle * OutResult);
#endif /* SB_USE_CLASS_TELPATHEXPRNODE */

#ifdef SB_USE_CLASS_TELLOCATIONPATHNODE
SB_IMPORT uint32_t SB_APIENTRY TElLocationPathNode_CreateNode(const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLocationPathNode_CreateNode_1(TElLocationPathNodeHandle _Handle, const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLocationPathNode_Create(TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
#endif /* SB_USE_CLASS_TELLOCATIONPATHNODE */

#ifdef SB_USE_CLASS_TELABSOLUTELOCATIONPATHNODE
SB_IMPORT uint32_t SB_APIENTRY TElAbsoluteLocationPathNode_CreateNode(const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAbsoluteLocationPathNode_CreateNode_1(TElAbsoluteLocationPathNodeHandle _Handle, const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAbsoluteLocationPathNode_GetResList(TElAbsoluteLocationPathNodeHandle _Handle, TListHandle List, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAbsoluteLocationPathNode_Create(TElXPathHandle XPath, TElAbsoluteLocationPathNodeHandle * OutResult);
#endif /* SB_USE_CLASS_TELABSOLUTELOCATIONPATHNODE */

#ifdef SB_USE_CLASS_TELRELATIVELOCATIONPATHNODE
SB_IMPORT uint32_t SB_APIENTRY TElRelativeLocationPathNode_CreateNode(const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeLocationPathNode_CreateNode_1(TElRelativeLocationPathNodeHandle _Handle, const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeLocationPathNode_GetResList(TElRelativeLocationPathNodeHandle _Handle, TListHandle List, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeLocationPathNode_Create(TElXPathHandle XPath, TElRelativeLocationPathNodeHandle * OutResult);
#endif /* SB_USE_CLASS_TELRELATIVELOCATIONPATHNODE */

#ifdef SB_USE_CLASS_TELSTEPNODE
SB_IMPORT uint32_t SB_APIENTRY TElStepNode_CreateNode(const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElStepNode_CreateNode_1(TElStepNodeHandle _Handle, const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElStepNode_GetResList(TElStepNodeHandle _Handle, TListHandle List, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElStepNode_Create(TElXPathHandle XPath, TElStepNodeHandle * OutResult);
#endif /* SB_USE_CLASS_TELSTEPNODE */

#ifdef SB_USE_CLASS_TELPREDICATENODE
SB_IMPORT uint32_t SB_APIENTRY TElPredicateNode_CreateNode(const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPredicateNode_CreateNode_1(TElPredicateNodeHandle _Handle, const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPredicateNode_GetResList(TElPredicateNodeHandle _Handle, TListHandle List, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPredicateNode_Create(TElXPathHandle XPath, TElPredicateNodeHandle * OutResult);
#endif /* SB_USE_CLASS_TELPREDICATENODE */

#ifdef SB_USE_CLASS_TELOREXPRNODE
SB_IMPORT uint32_t SB_APIENTRY TElOrExprNode_CreateNode(const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOrExprNode_CreateNode_1(TElOrExprNodeHandle _Handle, const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOrExprNode_GetResBoolean(TElOrExprNodeHandle _Handle, TElXMLDOMNodeHandle Context, TListHandle List, TElBooleanHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOrExprNode_Create(TElXPathHandle XPath, TElOrExprNodeHandle * OutResult);
#endif /* SB_USE_CLASS_TELOREXPRNODE */

#ifdef SB_USE_CLASS_TELANDEXPRNODE
SB_IMPORT uint32_t SB_APIENTRY TElAndExprNode_CreateNode(const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAndExprNode_CreateNode_1(TElAndExprNodeHandle _Handle, const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAndExprNode_GetResBoolean(TElAndExprNodeHandle _Handle, TElXMLDOMNodeHandle Context, TListHandle List, TElBooleanHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAndExprNode_Create(TElXPathHandle XPath, TElAndExprNodeHandle * OutResult);
#endif /* SB_USE_CLASS_TELANDEXPRNODE */

#ifdef SB_USE_CLASS_TELEQUALITYEXPRNODE
SB_IMPORT uint32_t SB_APIENTRY TElEqualityExprNode_CreateNode(const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElEqualityExprNode_CreateNode_1(TElEqualityExprNodeHandle _Handle, const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElEqualityExprNode_GetResBoolean(TElEqualityExprNodeHandle _Handle, TElXMLDOMNodeHandle Context, TListHandle List, TElBooleanHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElEqualityExprNode_Create(TElXPathHandle XPath, TElEqualityExprNodeHandle * OutResult);
#endif /* SB_USE_CLASS_TELEQUALITYEXPRNODE */

#ifdef SB_USE_CLASS_TELRELATIONALEXPRNODE
SB_IMPORT uint32_t SB_APIENTRY TElRelationalExprNode_CreateNode(const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelationalExprNode_CreateNode_1(TElRelationalExprNodeHandle _Handle, const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelationalExprNode_GetResBoolean(TElRelationalExprNodeHandle _Handle, TElXMLDOMNodeHandle Context, TListHandle List, TElBooleanHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelationalExprNode_Create(TElXPathHandle XPath, TElRelationalExprNodeHandle * OutResult);
#endif /* SB_USE_CLASS_TELRELATIONALEXPRNODE */

#ifdef SB_USE_CLASS_TELADDITIVEEXPRNODE
SB_IMPORT uint32_t SB_APIENTRY TElAdditiveExprNode_CreateNode(const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAdditiveExprNode_CreateNode_1(TElAdditiveExprNodeHandle _Handle, const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAdditiveExprNode_GetResNumber(TElAdditiveExprNodeHandle _Handle, TElXMLDOMNodeHandle Context, TListHandle List, TElNumberHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAdditiveExprNode_Create(TElXPathHandle XPath, TElAdditiveExprNodeHandle * OutResult);
#endif /* SB_USE_CLASS_TELADDITIVEEXPRNODE */

#ifdef SB_USE_CLASS_TELMULTIPLICATIVEEXPRNODE
SB_IMPORT uint32_t SB_APIENTRY TElMultiplicativeExprNode_CreateNode(const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiplicativeExprNode_CreateNode_1(TElMultiplicativeExprNodeHandle _Handle, const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiplicativeExprNode_GetResNumber(TElMultiplicativeExprNodeHandle _Handle, TElXMLDOMNodeHandle Context, TListHandle List, TElNumberHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiplicativeExprNode_Create(TElXPathHandle XPath, TElMultiplicativeExprNodeHandle * OutResult);
#endif /* SB_USE_CLASS_TELMULTIPLICATIVEEXPRNODE */

#ifdef SB_USE_CLASS_TELUNARYEXPRNODE
SB_IMPORT uint32_t SB_APIENTRY TElUnaryExprNode_CreateNode(const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUnaryExprNode_CreateNode_1(TElUnaryExprNodeHandle _Handle, const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUnaryExprNode_GetResNumber(TElUnaryExprNodeHandle _Handle, TElXMLDOMNodeHandle Context, TListHandle List, TElNumberHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUnaryExprNode_Create(TElXPathHandle XPath, TElUnaryExprNodeHandle * OutResult);
#endif /* SB_USE_CLASS_TELUNARYEXPRNODE */

#ifdef SB_USE_CLASS_TELFILTEREXPRNODE
SB_IMPORT uint32_t SB_APIENTRY TElFilterExprNode_CreateNode(const sb_char16_t * pcsQuery, int32_t szsQuery, sb_char16_t * pcsQueryTail, int32_t * szsQueryTail, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFilterExprNode_CreateNode_1(TElFilterExprNodeHandle _Handle, const sb_char16_t * pcsQuery, int32_t szsQuery, sb_char16_t * pcsQueryTail, int32_t * szsQueryTail, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFilterExprNode_GetResList(TElFilterExprNodeHandle _Handle, TListHandle List, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFilterExprNode_Create(TElXPathHandle XPath, TElFilterExprNodeHandle * OutResult);
#endif /* SB_USE_CLASS_TELFILTEREXPRNODE */

#ifdef SB_USE_CLASS_TELPRIMARYEXPRNODE
SB_IMPORT uint32_t SB_APIENTRY TElPrimaryExprNode_CreateNode(const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPrimaryExprNode_CreateNode_1(TElPrimaryExprNodeHandle _Handle, const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPrimaryExprNode_Create(TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
#endif /* SB_USE_CLASS_TELPRIMARYEXPRNODE */

#ifdef SB_USE_CLASS_TELVARIABLEREFERENCENODE
SB_IMPORT uint32_t SB_APIENTRY TElVariableReferenceNode_CreateNode(const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElVariableReferenceNode_CreateNode_1(TElVariableReferenceNodeHandle _Handle, const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElVariableReferenceNode_GetResultLocal(TElVariableReferenceNodeHandle _Handle, TElXMLDOMNodeHandle Context, TListHandle InList, int32_t * iType, TListHandle * List, TElBooleanHandle * bBoolean, TElNumberHandle * nNumber, TElStringHandle * sString);
SB_IMPORT uint32_t SB_APIENTRY TElVariableReferenceNode_Create(TElXPathHandle XPath, TElVariableReferenceNodeHandle * OutResult);
#endif /* SB_USE_CLASS_TELVARIABLEREFERENCENODE */

#ifdef SB_USE_CLASS_TELLITERALNODE
SB_IMPORT uint32_t SB_APIENTRY TElLiteralNode_CreateNode(const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLiteralNode_CreateNode_1(TElLiteralNodeHandle _Handle, const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLiteralNode_Create(TElXPathHandle XPath, TElLiteralNodeHandle * OutResult);
#endif /* SB_USE_CLASS_TELLITERALNODE */

#ifdef SB_USE_CLASS_TELNUMBERNODE
SB_IMPORT uint32_t SB_APIENTRY TElNumberNode_CreateNode(const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElNumberNode_CreateNode_1(TElNumberNodeHandle _Handle, const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElNumberNode_GetResNumber(TElNumberNodeHandle _Handle, TElNumberHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElNumberNode_Create(TElXPathHandle XPath, TElNumberNodeHandle * OutResult);
#endif /* SB_USE_CLASS_TELNUMBERNODE */

#ifdef SB_USE_CLASS_TELFUNCTIONCALLNODE
SB_IMPORT uint32_t SB_APIENTRY TElFunctionCallNode_CreateNode(const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFunctionCallNode_CreateNode_1(TElFunctionCallNodeHandle _Handle, const sb_char16_t * pcsQuery, int32_t szsQuery, TElXPathHandle XPath, TElXPathNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFunctionCallNode_GetResultLocal(TElFunctionCallNodeHandle _Handle, TElXMLDOMNodeHandle Context, TListHandle InList, int32_t * iType, TListHandle * List, TElBooleanHandle * bBoolean, TElNumberHandle * nNumber, TElStringHandle * sString);
SB_IMPORT uint32_t SB_APIENTRY TElFunctionCallNode_Create(TElXPathHandle XPath, TElFunctionCallNodeHandle * OutResult);
#endif /* SB_USE_CLASS_TELFUNCTIONCALLNODE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElXPath;
typedef TElXPath ElXPath;
class TElNumber;
typedef TElNumber ElNumber;
class TElBoolean;
typedef TElBoolean ElBoolean;
class TElString;
typedef TElString ElString;
class TElXMLVarMap;
typedef TElXMLVarMap ElXMLVarMap;
class TElXPathNode;
typedef TElXPathNode ElXPathNode;
class TElUnionExprNode;
typedef TElUnionExprNode ElUnionExprNode;
class TElPathExprNode;
typedef TElPathExprNode ElPathExprNode;
class TElLocationPathNode;
typedef TElLocationPathNode ElLocationPathNode;
class TElAbsoluteLocationPathNode;
typedef TElAbsoluteLocationPathNode ElAbsoluteLocationPathNode;
class TElRelativeLocationPathNode;
typedef TElRelativeLocationPathNode ElRelativeLocationPathNode;
class TElStepNode;
typedef TElStepNode ElStepNode;
class TElPredicateNode;
typedef TElPredicateNode ElPredicateNode;
class TElOrExprNode;
typedef TElOrExprNode ElOrExprNode;
class TElAndExprNode;
typedef TElAndExprNode ElAndExprNode;
class TElEqualityExprNode;
typedef TElEqualityExprNode ElEqualityExprNode;
class TElRelationalExprNode;
typedef TElRelationalExprNode ElRelationalExprNode;
class TElAdditiveExprNode;
typedef TElAdditiveExprNode ElAdditiveExprNode;
class TElMultiplicativeExprNode;
typedef TElMultiplicativeExprNode ElMultiplicativeExprNode;
class TElUnaryExprNode;
typedef TElUnaryExprNode ElUnaryExprNode;
class TElFilterExprNode;
typedef TElFilterExprNode ElFilterExprNode;
class TElPrimaryExprNode;
typedef TElPrimaryExprNode ElPrimaryExprNode;
class TElVariableReferenceNode;
typedef TElVariableReferenceNode ElVariableReferenceNode;
class TElLiteralNode;
typedef TElLiteralNode ElLiteralNode;
class TElNumberNode;
typedef TElNumberNode ElNumberNode;
class TElFunctionCallNode;
typedef TElFunctionCallNode ElFunctionCallNode;

#ifdef SB_USE_CLASS_TELXPATH
class TElXPath: public TObject
{
	private:
		SB_DISABLE_COPY(TElXPath)
	public:
#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLNAMESPACEMAP_AND_TELXMLNODESET_AND_TELXMLVARMAP
		void ProcessQuery(const sb_u16string &XPathQuery, TElXMLNodeSet &List, TElXMLDOMNode &Node, TElXMLNamespaceMap &NSList, TElXMLVarMap &VarMap);

		void ProcessQuery(const sb_u16string &XPathQuery, TElXMLNodeSet *List, TElXMLDOMNode *Node, TElXMLNamespaceMap *NSList, TElXMLVarMap *VarMap);
#ifdef SB_U16STRING_USED
		void ProcessQuery(const std::wstring &XPathQuery, TElXMLNodeSet &List, TElXMLDOMNode &Node, TElXMLNamespaceMap &NSList, TElXMLVarMap &VarMap);

		void ProcessQuery(const std::wstring &XPathQuery, TElXMLNodeSet *List, TElXMLDOMNode *Node, TElXMLNamespaceMap *NSList, TElXMLVarMap *VarMap);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLNAMESPACEMAP_AND_TELXMLNODESET_AND_TELXMLVARMAP */

		virtual void get_OnCustomFunction(TSBXPathCustomFunctionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCustomFunction(TSBXPathCustomFunctionEvent pMethodValue, void * pDataValue);

		TElXPath(TElXPathHandle handle, TElOwnHandle ownHandle);

		TElXPath();

};
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELNUMBER
class TElNumber: public TObject
{
	private:
		SB_DISABLE_COPY(TElNumber)
	public:
		bool IsNaN();

		bool IsInteger();

		int32_t GetInteger();

		double GetReal();

		void SetReal(double Value);

		TElNumber(TElNumberHandle handle, TElOwnHandle ownHandle);

		TElNumber();

};
#endif /* SB_USE_CLASS_TELNUMBER */

#ifdef SB_USE_CLASS_TELBOOLEAN
class TElBoolean: public TObject
{
	private:
		SB_DISABLE_COPY(TElBoolean)
	public:
		bool IsNaN();

		bool GetValue();

		TElBoolean(TElBooleanHandle handle, TElOwnHandle ownHandle);

		TElBoolean();

};
#endif /* SB_USE_CLASS_TELBOOLEAN */

#ifdef SB_USE_CLASS_TELSTRING
class TElString: public TObject
{
	private:
		SB_DISABLE_COPY(TElString)
	public:
		bool IsNaN();

		void GetValue(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		void GetValue(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		TElString(TElStringHandle handle, TElOwnHandle ownHandle);

		TElString();

};
#endif /* SB_USE_CLASS_TELSTRING */

#ifdef SB_USE_CLASS_TELXMLVARMAP
class TElXMLVarMap: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLVarMap)
	public:
		void Add(const sb_u16string &VarName, TObject &Value);

		void Add(const sb_u16string &VarName, TObject *Value);
#ifdef SB_U16STRING_USED
		void Add(const std::wstring &VarName, TObject &Value);

		void Add(const std::wstring &VarName, TObject *Value);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLNODESET
		void AddNodeList(const sb_u16string &VarName, TElXMLNodeSet &Value);

		void AddNodeList(const sb_u16string &VarName, TElXMLNodeSet *Value);
#ifdef SB_U16STRING_USED
		void AddNodeList(const std::wstring &VarName, TElXMLNodeSet &Value);

		void AddNodeList(const std::wstring &VarName, TElXMLNodeSet *Value);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLNODESET */

		void AddBoolean(const sb_u16string &VarName, bool Value);
#ifdef SB_U16STRING_USED
		void AddBoolean(const std::wstring &VarName, bool Value);
#endif /* SB_U16STRING_USED */

		void AddNumber(const sb_u16string &VarName, double Value);
#ifdef SB_U16STRING_USED
		void AddNumber(const std::wstring &VarName, double Value);
#endif /* SB_U16STRING_USED */

		void AddString(const sb_u16string &VarName, const sb_u16string &Value);
#ifdef SB_U16STRING_USED
		void AddString(const std::wstring &VarName, const std::wstring &Value);
#endif /* SB_U16STRING_USED */

		void Clear();

		void Delete(const sb_u16string &VarName);
#ifdef SB_U16STRING_USED
		void Delete(const std::wstring &VarName);
#endif /* SB_U16STRING_USED */

		TObjectHandle GetValue(const sb_u16string &VarName);
#ifdef SB_U16STRING_USED
		TObjectHandle GetValue(const std::wstring &VarName);
#endif /* SB_U16STRING_USED */

		TElXMLVarMap(TElXMLVarMapHandle handle, TElOwnHandle ownHandle);

		TElXMLVarMap();

};
#endif /* SB_USE_CLASS_TELXMLVARMAP */

#ifdef SB_USE_CLASS_TELXPATHNODE
class TElXPathNode: public TObject
{
	private:
		SB_DISABLE_COPY(TElXPathNode)
	public:
		static void DestroyNode(TElXPathNode &Node);

		static void DestroyNode(TElXPathNode *Node);

		void DestroyNode_Inst(TElXPathNode &Node);

		void DestroyNode_Inst(TElXPathNode *Node);

#ifdef SB_USE_CLASS_TLIST
		TListHandle GetResultList(TList &List);

		TListHandle GetResultList(TList *List);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASSES_TELNUMBER_AND_TELXMLDOMNODE_AND_TLIST
		TElNumberHandle GetResultNumber(TElXMLDOMNode &Context, TList &List);

		TElNumberHandle GetResultNumber(TElXMLDOMNode *Context, TList *List);
#endif /* SB_USE_CLASSES_TELNUMBER_AND_TELXMLDOMNODE_AND_TLIST */

#ifdef SB_USE_CLASSES_TELBOOLEAN_AND_TELXMLDOMNODE_AND_TLIST
		TElBooleanHandle GetResultBoolean(TElXMLDOMNode &Context, TList &List);

		TElBooleanHandle GetResultBoolean(TElXMLDOMNode *Context, TList *List);
#endif /* SB_USE_CLASSES_TELBOOLEAN_AND_TELXMLDOMNODE_AND_TLIST */

#ifdef SB_USE_CLASSES_TELSTRING_AND_TELXMLDOMNODE_AND_TLIST
		TElStringHandle GetResultString(TElXMLDOMNode &Context, TList &List);

		TElStringHandle GetResultString(TElXMLDOMNode *Context, TList *List);
#endif /* SB_USE_CLASSES_TELSTRING_AND_TELXMLDOMNODE_AND_TLIST */

#ifdef SB_USE_CLASSES_TELBOOLEAN_AND_TELNUMBER_AND_TELSTRING_AND_TELXMLDOMNODE_AND_TLIST
		void GetResult(TElXMLDOMNode &Context, TList &InList, int32_t &iType, TList &List, TElBoolean &Boolean, TElNumber &Number, TElString &sString);

		void GetResult(TElXMLDOMNode *Context, TList *InList, int32_t &iType, TList &List, TElBoolean &Boolean, TElNumber &Number, TElString &sString);
#endif /* SB_USE_CLASSES_TELBOOLEAN_AND_TELNUMBER_AND_TELSTRING_AND_TELXMLDOMNODE_AND_TLIST */

		TElXPathNode(TElXPathNodeHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXPATH
		explicit TElXPathNode(TElXPath &XPath);

		explicit TElXPathNode(TElXPath *XPath);
#endif /* SB_USE_CLASS_TELXPATH */

};
#endif /* SB_USE_CLASS_TELXPATHNODE */

#ifdef SB_USE_CLASS_TELUNIONEXPRNODE
class TElUnionExprNode: public TElXPathNode
{
	private:
		SB_DISABLE_COPY(TElUnionExprNode)
	public:
#ifdef SB_USE_CLASS_TELXPATH
		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TLIST
		TListHandle GetResList(TList &List);

		TListHandle GetResList(TList *List);
#endif /* SB_USE_CLASS_TLIST */

		TElUnionExprNode(TElUnionExprNodeHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXPATH
		explicit TElUnionExprNode(TElXPath &XPath);

		explicit TElUnionExprNode(TElXPath *XPath);
#endif /* SB_USE_CLASS_TELXPATH */

};
#endif /* SB_USE_CLASS_TELUNIONEXPRNODE */

#ifdef SB_USE_CLASS_TELPATHEXPRNODE
class TElPathExprNode: public TElXPathNode
{
	private:
		SB_DISABLE_COPY(TElPathExprNode)
	public:
#ifdef SB_USE_CLASS_TELXPATH
		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TLIST
		TListHandle GetResList(TList &List);

		TListHandle GetResList(TList *List);
#endif /* SB_USE_CLASS_TLIST */

		TElPathExprNode(TElPathExprNodeHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXPATH
		explicit TElPathExprNode(TElXPath &XPath);

		explicit TElPathExprNode(TElXPath *XPath);
#endif /* SB_USE_CLASS_TELXPATH */

};
#endif /* SB_USE_CLASS_TELPATHEXPRNODE */

#ifdef SB_USE_CLASS_TELLOCATIONPATHNODE
class TElLocationPathNode: public TElXPathNode
{
	private:
		SB_DISABLE_COPY(TElLocationPathNode)
	public:
#ifdef SB_USE_CLASS_TELXPATH
		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

		TElLocationPathNode(TElLocationPathNodeHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXPATH
		explicit TElLocationPathNode(TElXPath &XPath);

		explicit TElLocationPathNode(TElXPath *XPath);
#endif /* SB_USE_CLASS_TELXPATH */

};
#endif /* SB_USE_CLASS_TELLOCATIONPATHNODE */

#ifdef SB_USE_CLASS_TELABSOLUTELOCATIONPATHNODE
class TElAbsoluteLocationPathNode: public TElXPathNode
{
	private:
		SB_DISABLE_COPY(TElAbsoluteLocationPathNode)
	public:
#ifdef SB_USE_CLASS_TELXPATH
		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TLIST
		TListHandle GetResList(TList &List);

		TListHandle GetResList(TList *List);
#endif /* SB_USE_CLASS_TLIST */

		TElAbsoluteLocationPathNode(TElAbsoluteLocationPathNodeHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXPATH
		explicit TElAbsoluteLocationPathNode(TElXPath &XPath);

		explicit TElAbsoluteLocationPathNode(TElXPath *XPath);
#endif /* SB_USE_CLASS_TELXPATH */

};
#endif /* SB_USE_CLASS_TELABSOLUTELOCATIONPATHNODE */

#ifdef SB_USE_CLASS_TELRELATIVELOCATIONPATHNODE
class TElRelativeLocationPathNode: public TElXPathNode
{
	private:
		SB_DISABLE_COPY(TElRelativeLocationPathNode)
	public:
#ifdef SB_USE_CLASS_TELXPATH
		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TLIST
		TListHandle GetResList(TList &List);

		TListHandle GetResList(TList *List);
#endif /* SB_USE_CLASS_TLIST */

		TElRelativeLocationPathNode(TElRelativeLocationPathNodeHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXPATH
		explicit TElRelativeLocationPathNode(TElXPath &XPath);

		explicit TElRelativeLocationPathNode(TElXPath *XPath);
#endif /* SB_USE_CLASS_TELXPATH */

};
#endif /* SB_USE_CLASS_TELRELATIVELOCATIONPATHNODE */

#ifdef SB_USE_CLASS_TELSTEPNODE
class TElStepNode: public TElXPathNode
{
	private:
		SB_DISABLE_COPY(TElStepNode)
	public:
#ifdef SB_USE_CLASS_TELXPATH
		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TLIST
		TListHandle GetResList(TList &List);

		TListHandle GetResList(TList *List);
#endif /* SB_USE_CLASS_TLIST */

		TElStepNode(TElStepNodeHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXPATH
		explicit TElStepNode(TElXPath &XPath);

		explicit TElStepNode(TElXPath *XPath);
#endif /* SB_USE_CLASS_TELXPATH */

};
#endif /* SB_USE_CLASS_TELSTEPNODE */

#ifdef SB_USE_CLASS_TELPREDICATENODE
class TElPredicateNode: public TElXPathNode
{
	private:
		SB_DISABLE_COPY(TElPredicateNode)
	public:
#ifdef SB_USE_CLASS_TELXPATH
		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TLIST
		TListHandle GetResList(TList &List);

		TListHandle GetResList(TList *List);
#endif /* SB_USE_CLASS_TLIST */

		TElPredicateNode(TElPredicateNodeHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXPATH
		explicit TElPredicateNode(TElXPath &XPath);

		explicit TElPredicateNode(TElXPath *XPath);
#endif /* SB_USE_CLASS_TELXPATH */

};
#endif /* SB_USE_CLASS_TELPREDICATENODE */

#ifdef SB_USE_CLASS_TELOREXPRNODE
class TElOrExprNode: public TElXPathNode
{
	private:
		SB_DISABLE_COPY(TElOrExprNode)
	public:
#ifdef SB_USE_CLASS_TELXPATH
		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASSES_TELBOOLEAN_AND_TELXMLDOMNODE_AND_TLIST
		TElBooleanHandle GetResBoolean(TElXMLDOMNode &Context, TList &List);

		TElBooleanHandle GetResBoolean(TElXMLDOMNode *Context, TList *List);
#endif /* SB_USE_CLASSES_TELBOOLEAN_AND_TELXMLDOMNODE_AND_TLIST */

		TElOrExprNode(TElOrExprNodeHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXPATH
		explicit TElOrExprNode(TElXPath &XPath);

		explicit TElOrExprNode(TElXPath *XPath);
#endif /* SB_USE_CLASS_TELXPATH */

};
#endif /* SB_USE_CLASS_TELOREXPRNODE */

#ifdef SB_USE_CLASS_TELANDEXPRNODE
class TElAndExprNode: public TElXPathNode
{
	private:
		SB_DISABLE_COPY(TElAndExprNode)
	public:
#ifdef SB_USE_CLASS_TELXPATH
		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASSES_TELBOOLEAN_AND_TELXMLDOMNODE_AND_TLIST
		TElBooleanHandle GetResBoolean(TElXMLDOMNode &Context, TList &List);

		TElBooleanHandle GetResBoolean(TElXMLDOMNode *Context, TList *List);
#endif /* SB_USE_CLASSES_TELBOOLEAN_AND_TELXMLDOMNODE_AND_TLIST */

		TElAndExprNode(TElAndExprNodeHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXPATH
		explicit TElAndExprNode(TElXPath &XPath);

		explicit TElAndExprNode(TElXPath *XPath);
#endif /* SB_USE_CLASS_TELXPATH */

};
#endif /* SB_USE_CLASS_TELANDEXPRNODE */

#ifdef SB_USE_CLASS_TELEQUALITYEXPRNODE
class TElEqualityExprNode: public TElXPathNode
{
	private:
		SB_DISABLE_COPY(TElEqualityExprNode)
	public:
#ifdef SB_USE_CLASS_TELXPATH
		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASSES_TELBOOLEAN_AND_TELXMLDOMNODE_AND_TLIST
		TElBooleanHandle GetResBoolean(TElXMLDOMNode &Context, TList &List);

		TElBooleanHandle GetResBoolean(TElXMLDOMNode *Context, TList *List);
#endif /* SB_USE_CLASSES_TELBOOLEAN_AND_TELXMLDOMNODE_AND_TLIST */

		TElEqualityExprNode(TElEqualityExprNodeHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXPATH
		explicit TElEqualityExprNode(TElXPath &XPath);

		explicit TElEqualityExprNode(TElXPath *XPath);
#endif /* SB_USE_CLASS_TELXPATH */

};
#endif /* SB_USE_CLASS_TELEQUALITYEXPRNODE */

#ifdef SB_USE_CLASS_TELRELATIONALEXPRNODE
class TElRelationalExprNode: public TElXPathNode
{
	private:
		SB_DISABLE_COPY(TElRelationalExprNode)
	public:
#ifdef SB_USE_CLASS_TELXPATH
		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASSES_TELBOOLEAN_AND_TELXMLDOMNODE_AND_TLIST
		TElBooleanHandle GetResBoolean(TElXMLDOMNode &Context, TList &List);

		TElBooleanHandle GetResBoolean(TElXMLDOMNode *Context, TList *List);
#endif /* SB_USE_CLASSES_TELBOOLEAN_AND_TELXMLDOMNODE_AND_TLIST */

		TElRelationalExprNode(TElRelationalExprNodeHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXPATH
		explicit TElRelationalExprNode(TElXPath &XPath);

		explicit TElRelationalExprNode(TElXPath *XPath);
#endif /* SB_USE_CLASS_TELXPATH */

};
#endif /* SB_USE_CLASS_TELRELATIONALEXPRNODE */

#ifdef SB_USE_CLASS_TELADDITIVEEXPRNODE
class TElAdditiveExprNode: public TElXPathNode
{
	private:
		SB_DISABLE_COPY(TElAdditiveExprNode)
	public:
#ifdef SB_USE_CLASS_TELXPATH
		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASSES_TELNUMBER_AND_TELXMLDOMNODE_AND_TLIST
		TElNumberHandle GetResNumber(TElXMLDOMNode &Context, TList &List);

		TElNumberHandle GetResNumber(TElXMLDOMNode *Context, TList *List);
#endif /* SB_USE_CLASSES_TELNUMBER_AND_TELXMLDOMNODE_AND_TLIST */

		TElAdditiveExprNode(TElAdditiveExprNodeHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXPATH
		explicit TElAdditiveExprNode(TElXPath &XPath);

		explicit TElAdditiveExprNode(TElXPath *XPath);
#endif /* SB_USE_CLASS_TELXPATH */

};
#endif /* SB_USE_CLASS_TELADDITIVEEXPRNODE */

#ifdef SB_USE_CLASS_TELMULTIPLICATIVEEXPRNODE
class TElMultiplicativeExprNode: public TElXPathNode
{
	private:
		SB_DISABLE_COPY(TElMultiplicativeExprNode)
	public:
#ifdef SB_USE_CLASS_TELXPATH
		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASSES_TELNUMBER_AND_TELXMLDOMNODE_AND_TLIST
		TElNumberHandle GetResNumber(TElXMLDOMNode &Context, TList &List);

		TElNumberHandle GetResNumber(TElXMLDOMNode *Context, TList *List);
#endif /* SB_USE_CLASSES_TELNUMBER_AND_TELXMLDOMNODE_AND_TLIST */

		TElMultiplicativeExprNode(TElMultiplicativeExprNodeHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXPATH
		explicit TElMultiplicativeExprNode(TElXPath &XPath);

		explicit TElMultiplicativeExprNode(TElXPath *XPath);
#endif /* SB_USE_CLASS_TELXPATH */

};
#endif /* SB_USE_CLASS_TELMULTIPLICATIVEEXPRNODE */

#ifdef SB_USE_CLASS_TELUNARYEXPRNODE
class TElUnaryExprNode: public TElXPathNode
{
	private:
		SB_DISABLE_COPY(TElUnaryExprNode)
	public:
#ifdef SB_USE_CLASS_TELXPATH
		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASSES_TELNUMBER_AND_TELXMLDOMNODE_AND_TLIST
		TElNumberHandle GetResNumber(TElXMLDOMNode &Context, TList &List);

		TElNumberHandle GetResNumber(TElXMLDOMNode *Context, TList *List);
#endif /* SB_USE_CLASSES_TELNUMBER_AND_TELXMLDOMNODE_AND_TLIST */

		TElUnaryExprNode(TElUnaryExprNodeHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXPATH
		explicit TElUnaryExprNode(TElXPath &XPath);

		explicit TElUnaryExprNode(TElXPath *XPath);
#endif /* SB_USE_CLASS_TELXPATH */

};
#endif /* SB_USE_CLASS_TELUNARYEXPRNODE */

#ifdef SB_USE_CLASS_TELFILTEREXPRNODE
class TElFilterExprNode: public TElXPathNode
{
	private:
		SB_DISABLE_COPY(TElFilterExprNode)
	public:
#ifdef SB_USE_CLASS_TELXPATH
		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, sb_u16string &sQueryTail, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, sb_u16string &sQueryTail, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, std::wstring &sQueryTail, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, std::wstring &sQueryTail, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, sb_u16string &sQueryTail, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, sb_u16string &sQueryTail, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, std::wstring &sQueryTail, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, std::wstring &sQueryTail, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TLIST
		TListHandle GetResList(TList &List);

		TListHandle GetResList(TList *List);
#endif /* SB_USE_CLASS_TLIST */

		TElFilterExprNode(TElFilterExprNodeHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXPATH
		explicit TElFilterExprNode(TElXPath &XPath);

		explicit TElFilterExprNode(TElXPath *XPath);
#endif /* SB_USE_CLASS_TELXPATH */

};
#endif /* SB_USE_CLASS_TELFILTEREXPRNODE */

#ifdef SB_USE_CLASS_TELPRIMARYEXPRNODE
class TElPrimaryExprNode: public TElXPathNode
{
	private:
		SB_DISABLE_COPY(TElPrimaryExprNode)
	public:
#ifdef SB_USE_CLASS_TELXPATH
		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

		TElPrimaryExprNode(TElPrimaryExprNodeHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXPATH
		explicit TElPrimaryExprNode(TElXPath &XPath);

		explicit TElPrimaryExprNode(TElXPath *XPath);
#endif /* SB_USE_CLASS_TELXPATH */

};
#endif /* SB_USE_CLASS_TELPRIMARYEXPRNODE */

#ifdef SB_USE_CLASS_TELVARIABLEREFERENCENODE
class TElVariableReferenceNode: public TElXPathNode
{
	private:
		SB_DISABLE_COPY(TElVariableReferenceNode)
	public:
#ifdef SB_USE_CLASS_TELXPATH
		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASSES_TELBOOLEAN_AND_TELNUMBER_AND_TELSTRING_AND_TELXMLDOMNODE_AND_TLIST
		void GetResultLocal(TElXMLDOMNode &Context, TList &InList, int32_t &iType, TList &List, TElBoolean &bBoolean, TElNumber &nNumber, TElString &sString);

		void GetResultLocal(TElXMLDOMNode *Context, TList *InList, int32_t &iType, TList &List, TElBoolean &bBoolean, TElNumber &nNumber, TElString &sString);
#endif /* SB_USE_CLASSES_TELBOOLEAN_AND_TELNUMBER_AND_TELSTRING_AND_TELXMLDOMNODE_AND_TLIST */

		TElVariableReferenceNode(TElVariableReferenceNodeHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXPATH
		explicit TElVariableReferenceNode(TElXPath &XPath);

		explicit TElVariableReferenceNode(TElXPath *XPath);
#endif /* SB_USE_CLASS_TELXPATH */

};
#endif /* SB_USE_CLASS_TELVARIABLEREFERENCENODE */

#ifdef SB_USE_CLASS_TELLITERALNODE
class TElLiteralNode: public TElXPathNode
{
	private:
		SB_DISABLE_COPY(TElLiteralNode)
	public:
#ifdef SB_USE_CLASS_TELXPATH
		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

		TElLiteralNode(TElLiteralNodeHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXPATH
		explicit TElLiteralNode(TElXPath &XPath);

		explicit TElLiteralNode(TElXPath *XPath);
#endif /* SB_USE_CLASS_TELXPATH */

};
#endif /* SB_USE_CLASS_TELLITERALNODE */

#ifdef SB_USE_CLASS_TELNUMBERNODE
class TElNumberNode: public TElXPathNode
{
	private:
		SB_DISABLE_COPY(TElNumberNode)
	public:
#ifdef SB_USE_CLASS_TELXPATH
		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELNUMBER
		TElNumberHandle GetResNumber();
#endif /* SB_USE_CLASS_TELNUMBER */

		TElNumberNode(TElNumberNodeHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXPATH
		explicit TElNumberNode(TElXPath &XPath);

		explicit TElNumberNode(TElXPath *XPath);
#endif /* SB_USE_CLASS_TELXPATH */

};
#endif /* SB_USE_CLASS_TELNUMBERNODE */

#ifdef SB_USE_CLASS_TELFUNCTIONCALLNODE
class TElFunctionCallNode: public TElXPathNode
{
	private:
		SB_DISABLE_COPY(TElFunctionCallNode)
	public:
#ifdef SB_USE_CLASS_TELXPATH
		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath &XPath);

		static TElXPathNodeHandle CreateNode(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath);
#ifdef SB_U16STRING_USED
		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath);

		TElXPathNodeHandle CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASSES_TELBOOLEAN_AND_TELNUMBER_AND_TELSTRING_AND_TELXMLDOMNODE_AND_TLIST
		void GetResultLocal(TElXMLDOMNode &Context, TList &InList, int32_t &iType, TList &List, TElBoolean &bBoolean, TElNumber &nNumber, TElString &sString);

		void GetResultLocal(TElXMLDOMNode *Context, TList *InList, int32_t &iType, TList &List, TElBoolean &bBoolean, TElNumber &nNumber, TElString &sString);
#endif /* SB_USE_CLASSES_TELBOOLEAN_AND_TELNUMBER_AND_TELSTRING_AND_TELXMLDOMNODE_AND_TLIST */

		TElFunctionCallNode(TElFunctionCallNodeHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXPATH
		explicit TElFunctionCallNode(TElXPath &XPath);

		explicit TElFunctionCallNode(TElXPath *XPath);
#endif /* SB_USE_CLASS_TELXPATH */

};
#endif /* SB_USE_CLASS_TELFUNCTIONCALLNODE */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBXMLPATH */

