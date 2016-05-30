#include "sbxmlpath.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELXPATH

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLNAMESPACEMAP_AND_TELXMLNODESET_AND_TELXMLVARMAP
SB_INLINE void TElXPath::ProcessQuery(const sb_u16string &XPathQuery, TElXMLNodeSet &List, TElXMLDOMNode &Node, TElXMLNamespaceMap &NSList, TElXMLVarMap &VarMap)
{
	SBCheckError(TElXPath_ProcessQuery(_Handle, XPathQuery.data(), (int32_t)XPathQuery.length(), List.getHandle(), Node.getHandle(), NSList.getHandle(), VarMap.getHandle()));
}

SB_INLINE void TElXPath::ProcessQuery(const sb_u16string &XPathQuery, TElXMLNodeSet *List, TElXMLDOMNode *Node, TElXMLNamespaceMap *NSList, TElXMLVarMap *VarMap)
{
	SBCheckError(TElXPath_ProcessQuery(_Handle, XPathQuery.data(), (int32_t)XPathQuery.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, (NSList != NULL) ? NSList->getHandle() : SB_NULL_HANDLE, (VarMap != NULL) ? VarMap->getHandle() : SB_NULL_HANDLE));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXPath::ProcessQuery(const std::wstring &XPathQuery, TElXMLNodeSet &List, TElXMLDOMNode &Node, TElXMLNamespaceMap &NSList, TElXMLVarMap &VarMap)
{
	std::string u16XPathQuery;
	sb_to_u16string(XPathQuery, u16XPathQuery);
	SBCheckError(TElXPath_ProcessQuery(_Handle, reinterpret_cast<const sb_char16_t*>(u16XPathQuery.data()), (int32_t)u16XPathQuery.length() >> 1, List.getHandle(), Node.getHandle(), NSList.getHandle(), VarMap.getHandle()));
}

SB_INLINE void TElXPath::ProcessQuery(const std::wstring &XPathQuery, TElXMLNodeSet *List, TElXMLDOMNode *Node, TElXMLNamespaceMap *NSList, TElXMLVarMap *VarMap)
{
	std::string u16XPathQuery;
	sb_to_u16string(XPathQuery, u16XPathQuery);
	SBCheckError(TElXPath_ProcessQuery(_Handle, reinterpret_cast<const sb_char16_t*>(u16XPathQuery.data()), (int32_t)u16XPathQuery.length() >> 1, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, (NSList != NULL) ? NSList->getHandle() : SB_NULL_HANDLE, (VarMap != NULL) ? VarMap->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLNAMESPACEMAP_AND_TELXMLNODESET_AND_TELXMLVARMAP */

SB_INLINE void TElXPath::get_OnCustomFunction(TSBXPathCustomFunctionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXPath_get_OnCustomFunction(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXPath::set_OnCustomFunction(TSBXPathCustomFunctionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXPath_set_OnCustomFunction(_Handle, pMethodValue, pDataValue));
}

TElXPath::TElXPath(TElXPathHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElXPath::TElXPath() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXPath_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELNUMBER

bool TElNumber::IsNaN()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElNumber_IsNaN(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElNumber::IsInteger()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElNumber_IsInteger(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElNumber::GetInteger()
{
	int32_t OutResult;
	SBCheckError(TElNumber_GetInteger(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE double TElNumber::GetReal()
{
	double OutResult;
	SBCheckError(TElNumber_GetReal(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElNumber::SetReal(double Value)
{
	SBCheckError(TElNumber_SetReal(_Handle, Value));
}

TElNumber::TElNumber(TElNumberHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElNumber::TElNumber() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElNumber_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELNUMBER */

#ifdef SB_USE_CLASS_TELBOOLEAN

bool TElBoolean::IsNaN()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBoolean_IsNaN(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBoolean::GetValue()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBoolean_GetValue(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TElBoolean::TElBoolean(TElBooleanHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElBoolean::TElBoolean() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBoolean_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELBOOLEAN */

#ifdef SB_USE_CLASS_TELSTRING

bool TElString::IsNaN()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElString_IsNaN(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElString::GetValue(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElString_GetValue(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-198811903, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElString::GetValue(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElString_GetValue(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-198811903, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

TElString::TElString(TElStringHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElString::TElString() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElString_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSTRING */

#ifdef SB_USE_CLASS_TELXMLVARMAP

SB_INLINE void TElXMLVarMap::Add(const sb_u16string &VarName, TObject &Value)
{
	SBCheckError(TElXMLVarMap_Add(_Handle, VarName.data(), (int32_t)VarName.length(), Value.getHandle()));
}

SB_INLINE void TElXMLVarMap::Add(const sb_u16string &VarName, TObject *Value)
{
	SBCheckError(TElXMLVarMap_Add(_Handle, VarName.data(), (int32_t)VarName.length(), (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLVarMap::Add(const std::wstring &VarName, TObject &Value)
{
	std::string u16VarName;
	sb_to_u16string(VarName, u16VarName);
	SBCheckError(TElXMLVarMap_Add(_Handle, reinterpret_cast<const sb_char16_t*>(u16VarName.data()), (int32_t)u16VarName.length() >> 1, Value.getHandle()));
}

SB_INLINE void TElXMLVarMap::Add(const std::wstring &VarName, TObject *Value)
{
	std::string u16VarName;
	sb_to_u16string(VarName, u16VarName);
	SBCheckError(TElXMLVarMap_Add(_Handle, reinterpret_cast<const sb_char16_t*>(u16VarName.data()), (int32_t)u16VarName.length() >> 1, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLNODESET
SB_INLINE void TElXMLVarMap::AddNodeList(const sb_u16string &VarName, TElXMLNodeSet &Value)
{
	SBCheckError(TElXMLVarMap_AddNodeList(_Handle, VarName.data(), (int32_t)VarName.length(), Value.getHandle()));
}

SB_INLINE void TElXMLVarMap::AddNodeList(const sb_u16string &VarName, TElXMLNodeSet *Value)
{
	SBCheckError(TElXMLVarMap_AddNodeList(_Handle, VarName.data(), (int32_t)VarName.length(), (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLVarMap::AddNodeList(const std::wstring &VarName, TElXMLNodeSet &Value)
{
	std::string u16VarName;
	sb_to_u16string(VarName, u16VarName);
	SBCheckError(TElXMLVarMap_AddNodeList(_Handle, reinterpret_cast<const sb_char16_t*>(u16VarName.data()), (int32_t)u16VarName.length() >> 1, Value.getHandle()));
}

SB_INLINE void TElXMLVarMap::AddNodeList(const std::wstring &VarName, TElXMLNodeSet *Value)
{
	std::string u16VarName;
	sb_to_u16string(VarName, u16VarName);
	SBCheckError(TElXMLVarMap_AddNodeList(_Handle, reinterpret_cast<const sb_char16_t*>(u16VarName.data()), (int32_t)u16VarName.length() >> 1, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLNODESET */

SB_INLINE void TElXMLVarMap::AddBoolean(const sb_u16string &VarName, bool Value)
{
	SBCheckError(TElXMLVarMap_AddBoolean(_Handle, VarName.data(), (int32_t)VarName.length(), (int8_t)Value));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLVarMap::AddBoolean(const std::wstring &VarName, bool Value)
{
	std::string u16VarName;
	sb_to_u16string(VarName, u16VarName);
	SBCheckError(TElXMLVarMap_AddBoolean(_Handle, reinterpret_cast<const sb_char16_t*>(u16VarName.data()), (int32_t)u16VarName.length() >> 1, (int8_t)Value));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElXMLVarMap::AddNumber(const sb_u16string &VarName, double Value)
{
	SBCheckError(TElXMLVarMap_AddNumber(_Handle, VarName.data(), (int32_t)VarName.length(), Value));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLVarMap::AddNumber(const std::wstring &VarName, double Value)
{
	std::string u16VarName;
	sb_to_u16string(VarName, u16VarName);
	SBCheckError(TElXMLVarMap_AddNumber(_Handle, reinterpret_cast<const sb_char16_t*>(u16VarName.data()), (int32_t)u16VarName.length() >> 1, Value));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElXMLVarMap::AddString(const sb_u16string &VarName, const sb_u16string &Value)
{
	SBCheckError(TElXMLVarMap_AddString(_Handle, VarName.data(), (int32_t)VarName.length(), Value.data(), (int32_t)Value.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLVarMap::AddString(const std::wstring &VarName, const std::wstring &Value)
{
	std::string u16VarName;
	sb_to_u16string(VarName, u16VarName);
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLVarMap_AddString(_Handle, reinterpret_cast<const sb_char16_t*>(u16VarName.data()), (int32_t)u16VarName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElXMLVarMap::Clear()
{
	SBCheckError(TElXMLVarMap_Clear(_Handle));
}

SB_INLINE void TElXMLVarMap::Delete(const sb_u16string &VarName)
{
	SBCheckError(TElXMLVarMap_Delete(_Handle, VarName.data(), (int32_t)VarName.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLVarMap::Delete(const std::wstring &VarName)
{
	std::string u16VarName;
	sb_to_u16string(VarName, u16VarName);
	SBCheckError(TElXMLVarMap_Delete(_Handle, reinterpret_cast<const sb_char16_t*>(u16VarName.data()), (int32_t)u16VarName.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE TObjectHandle TElXMLVarMap::GetValue(const sb_u16string &VarName)
{
	TObjectHandle OutResult;
	SBCheckError(TElXMLVarMap_GetValue(_Handle, VarName.data(), (int32_t)VarName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TObjectHandle TElXMLVarMap::GetValue(const std::wstring &VarName)
{
	TObjectHandle OutResult;
	std::string u16VarName;
	sb_to_u16string(VarName, u16VarName);
	SBCheckError(TElXMLVarMap_GetValue(_Handle, reinterpret_cast<const sb_char16_t*>(u16VarName.data()), (int32_t)u16VarName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

TElXMLVarMap::TElXMLVarMap(TElXMLVarMapHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElXMLVarMap::TElXMLVarMap() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLVarMap_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLVARMAP */

#ifdef SB_USE_CLASS_TELXPATHNODE

SB_INLINE void TElXPathNode::DestroyNode(TElXPathNode &Node)
{
	SBCheckError(TElXPathNode_DestroyNode(Node.getHandle()));
}

SB_INLINE void TElXPathNode::DestroyNode(TElXPathNode *Node)
{
	SBCheckError(TElXPathNode_DestroyNode((Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElXPathNode::DestroyNode_Inst(TElXPathNode &Node)
{
	SBCheckError(TElXPathNode_DestroyNode_1(_Handle, Node.getHandle()));
}

SB_INLINE void TElXPathNode::DestroyNode_Inst(TElXPathNode *Node)
{
	SBCheckError(TElXPathNode_DestroyNode_1(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TLIST
SB_INLINE TListHandle TElXPathNode::GetResultList(TList &List)
{
	TListHandle OutResult;
	SBCheckError(TElXPathNode_GetResultList(_Handle, List.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TListHandle TElXPathNode::GetResultList(TList *List)
{
	TListHandle OutResult;
	SBCheckError(TElXPathNode_GetResultList(_Handle, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASSES_TELNUMBER_AND_TELXMLDOMNODE_AND_TLIST
SB_INLINE TElNumberHandle TElXPathNode::GetResultNumber(TElXMLDOMNode &Context, TList &List)
{
	TElNumberHandle OutResult;
	SBCheckError(TElXPathNode_GetResultNumber(_Handle, Context.getHandle(), List.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElNumberHandle TElXPathNode::GetResultNumber(TElXMLDOMNode *Context, TList *List)
{
	TElNumberHandle OutResult;
	SBCheckError(TElXPathNode_GetResultNumber(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELNUMBER_AND_TELXMLDOMNODE_AND_TLIST */

#ifdef SB_USE_CLASSES_TELBOOLEAN_AND_TELXMLDOMNODE_AND_TLIST
SB_INLINE TElBooleanHandle TElXPathNode::GetResultBoolean(TElXMLDOMNode &Context, TList &List)
{
	TElBooleanHandle OutResult;
	SBCheckError(TElXPathNode_GetResultBoolean(_Handle, Context.getHandle(), List.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElBooleanHandle TElXPathNode::GetResultBoolean(TElXMLDOMNode *Context, TList *List)
{
	TElBooleanHandle OutResult;
	SBCheckError(TElXPathNode_GetResultBoolean(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELBOOLEAN_AND_TELXMLDOMNODE_AND_TLIST */

#ifdef SB_USE_CLASSES_TELSTRING_AND_TELXMLDOMNODE_AND_TLIST
SB_INLINE TElStringHandle TElXPathNode::GetResultString(TElXMLDOMNode &Context, TList &List)
{
	TElStringHandle OutResult;
	SBCheckError(TElXPathNode_GetResultString(_Handle, Context.getHandle(), List.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElStringHandle TElXPathNode::GetResultString(TElXMLDOMNode *Context, TList *List)
{
	TElStringHandle OutResult;
	SBCheckError(TElXPathNode_GetResultString(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELSTRING_AND_TELXMLDOMNODE_AND_TLIST */

#ifdef SB_USE_CLASSES_TELBOOLEAN_AND_TELNUMBER_AND_TELSTRING_AND_TELXMLDOMNODE_AND_TLIST
void TElXPathNode::GetResult(TElXMLDOMNode &Context, TList &InList, int32_t &iType, TList &List, TElBoolean &Boolean, TElNumber &Number, TElString &sString)
{
	TElClassHandle hList = List.getHandle();
	TElClassHandle hBoolean = Boolean.getHandle();
	TElClassHandle hNumber = Number.getHandle();
	TElClassHandle hsString = sString.getHandle();
	SBCheckError(TElXPathNode_GetResult(_Handle, Context.getHandle(), InList.getHandle(), &iType, &hList, &hBoolean, &hNumber, &hsString));
	List.updateHandle(hList);
	Boolean.updateHandle(hBoolean);
	Number.updateHandle(hNumber);
	sString.updateHandle(hsString);
}

void TElXPathNode::GetResult(TElXMLDOMNode *Context, TList *InList, int32_t &iType, TList &List, TElBoolean &Boolean, TElNumber &Number, TElString &sString)
{
	TElClassHandle hList = List.getHandle();
	TElClassHandle hBoolean = Boolean.getHandle();
	TElClassHandle hNumber = Number.getHandle();
	TElClassHandle hsString = sString.getHandle();
	SBCheckError(TElXPathNode_GetResult(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, (InList != NULL) ? InList->getHandle() : SB_NULL_HANDLE, &iType, &hList, &hBoolean, &hNumber, &hsString));
	List.updateHandle(hList);
	Boolean.updateHandle(hBoolean);
	Number.updateHandle(hNumber);
	sString.updateHandle(hsString);
}
#endif /* SB_USE_CLASSES_TELBOOLEAN_AND_TELNUMBER_AND_TELSTRING_AND_TELXMLDOMNODE_AND_TLIST */

TElXPathNode::TElXPathNode(TElXPathNodeHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELXPATH
TElXPathNode::TElXPathNode(TElXPath &XPath) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXPathNode_Create(XPath.getHandle(), &_Handle));
}

TElXPathNode::TElXPathNode(TElXPath *XPath) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXPathNode_Create((XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXPATH */

#endif /* SB_USE_CLASS_TELXPATHNODE */

#ifdef SB_USE_CLASS_TELUNIONEXPRNODE

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElUnionExprNode::CreateNode(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElUnionExprNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElUnionExprNode::CreateNode(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElUnionExprNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElUnionExprNode::CreateNode(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElUnionExprNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElUnionExprNode::CreateNode(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElUnionExprNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElUnionExprNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElUnionExprNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElUnionExprNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElUnionExprNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElUnionExprNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElUnionExprNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElUnionExprNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElUnionExprNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE TListHandle TElUnionExprNode::GetResList(TList &List)
{
	TListHandle OutResult;
	SBCheckError(TElUnionExprNode_GetResList(_Handle, List.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TListHandle TElUnionExprNode::GetResList(TList *List)
{
	TListHandle OutResult;
	SBCheckError(TElUnionExprNode_GetResList(_Handle, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TLIST */

TElUnionExprNode::TElUnionExprNode(TElUnionExprNodeHandle handle, TElOwnHandle ownHandle) : TElXPathNode(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELXPATH
TElUnionExprNode::TElUnionExprNode(TElXPath &XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElUnionExprNode_Create(XPath.getHandle(), &_Handle));
}

TElUnionExprNode::TElUnionExprNode(TElXPath *XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElUnionExprNode_Create((XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXPATH */

#endif /* SB_USE_CLASS_TELUNIONEXPRNODE */

#ifdef SB_USE_CLASS_TELPATHEXPRNODE

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElPathExprNode::CreateNode(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElPathExprNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElPathExprNode::CreateNode(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElPathExprNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElPathExprNode::CreateNode(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElPathExprNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElPathExprNode::CreateNode(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElPathExprNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElPathExprNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElPathExprNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElPathExprNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElPathExprNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElPathExprNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElPathExprNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElPathExprNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElPathExprNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE TListHandle TElPathExprNode::GetResList(TList &List)
{
	TListHandle OutResult;
	SBCheckError(TElPathExprNode_GetResList(_Handle, List.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TListHandle TElPathExprNode::GetResList(TList *List)
{
	TListHandle OutResult;
	SBCheckError(TElPathExprNode_GetResList(_Handle, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TLIST */

TElPathExprNode::TElPathExprNode(TElPathExprNodeHandle handle, TElOwnHandle ownHandle) : TElXPathNode(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELXPATH
TElPathExprNode::TElPathExprNode(TElXPath &XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPathExprNode_Create(XPath.getHandle(), &_Handle));
}

TElPathExprNode::TElPathExprNode(TElXPath *XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPathExprNode_Create((XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXPATH */

#endif /* SB_USE_CLASS_TELPATHEXPRNODE */

#ifdef SB_USE_CLASS_TELLOCATIONPATHNODE

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElLocationPathNode::CreateNode(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElLocationPathNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElLocationPathNode::CreateNode(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElLocationPathNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElLocationPathNode::CreateNode(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElLocationPathNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElLocationPathNode::CreateNode(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElLocationPathNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElLocationPathNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElLocationPathNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElLocationPathNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElLocationPathNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElLocationPathNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElLocationPathNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElLocationPathNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElLocationPathNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

TElLocationPathNode::TElLocationPathNode(TElLocationPathNodeHandle handle, TElOwnHandle ownHandle) : TElXPathNode(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELXPATH
TElLocationPathNode::TElLocationPathNode(TElXPath &XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLocationPathNode_Create(XPath.getHandle(), &_Handle));
}

TElLocationPathNode::TElLocationPathNode(TElXPath *XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLocationPathNode_Create((XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXPATH */

#endif /* SB_USE_CLASS_TELLOCATIONPATHNODE */

#ifdef SB_USE_CLASS_TELABSOLUTELOCATIONPATHNODE

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElAbsoluteLocationPathNode::CreateNode(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElAbsoluteLocationPathNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElAbsoluteLocationPathNode::CreateNode(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElAbsoluteLocationPathNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElAbsoluteLocationPathNode::CreateNode(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElAbsoluteLocationPathNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElAbsoluteLocationPathNode::CreateNode(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElAbsoluteLocationPathNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElAbsoluteLocationPathNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElAbsoluteLocationPathNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElAbsoluteLocationPathNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElAbsoluteLocationPathNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElAbsoluteLocationPathNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElAbsoluteLocationPathNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElAbsoluteLocationPathNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElAbsoluteLocationPathNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE TListHandle TElAbsoluteLocationPathNode::GetResList(TList &List)
{
	TListHandle OutResult;
	SBCheckError(TElAbsoluteLocationPathNode_GetResList(_Handle, List.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TListHandle TElAbsoluteLocationPathNode::GetResList(TList *List)
{
	TListHandle OutResult;
	SBCheckError(TElAbsoluteLocationPathNode_GetResList(_Handle, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TLIST */

TElAbsoluteLocationPathNode::TElAbsoluteLocationPathNode(TElAbsoluteLocationPathNodeHandle handle, TElOwnHandle ownHandle) : TElXPathNode(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELXPATH
TElAbsoluteLocationPathNode::TElAbsoluteLocationPathNode(TElXPath &XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAbsoluteLocationPathNode_Create(XPath.getHandle(), &_Handle));
}

TElAbsoluteLocationPathNode::TElAbsoluteLocationPathNode(TElXPath *XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAbsoluteLocationPathNode_Create((XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXPATH */

#endif /* SB_USE_CLASS_TELABSOLUTELOCATIONPATHNODE */

#ifdef SB_USE_CLASS_TELRELATIVELOCATIONPATHNODE

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElRelativeLocationPathNode::CreateNode(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElRelativeLocationPathNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElRelativeLocationPathNode::CreateNode(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElRelativeLocationPathNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElRelativeLocationPathNode::CreateNode(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElRelativeLocationPathNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElRelativeLocationPathNode::CreateNode(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElRelativeLocationPathNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElRelativeLocationPathNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElRelativeLocationPathNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElRelativeLocationPathNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElRelativeLocationPathNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElRelativeLocationPathNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElRelativeLocationPathNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElRelativeLocationPathNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElRelativeLocationPathNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE TListHandle TElRelativeLocationPathNode::GetResList(TList &List)
{
	TListHandle OutResult;
	SBCheckError(TElRelativeLocationPathNode_GetResList(_Handle, List.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TListHandle TElRelativeLocationPathNode::GetResList(TList *List)
{
	TListHandle OutResult;
	SBCheckError(TElRelativeLocationPathNode_GetResList(_Handle, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TLIST */

TElRelativeLocationPathNode::TElRelativeLocationPathNode(TElRelativeLocationPathNodeHandle handle, TElOwnHandle ownHandle) : TElXPathNode(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELXPATH
TElRelativeLocationPathNode::TElRelativeLocationPathNode(TElXPath &XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRelativeLocationPathNode_Create(XPath.getHandle(), &_Handle));
}

TElRelativeLocationPathNode::TElRelativeLocationPathNode(TElXPath *XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRelativeLocationPathNode_Create((XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXPATH */

#endif /* SB_USE_CLASS_TELRELATIVELOCATIONPATHNODE */

#ifdef SB_USE_CLASS_TELSTEPNODE

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElStepNode::CreateNode(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElStepNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElStepNode::CreateNode(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElStepNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElStepNode::CreateNode(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElStepNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElStepNode::CreateNode(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElStepNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElStepNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElStepNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElStepNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElStepNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElStepNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElStepNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElStepNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElStepNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE TListHandle TElStepNode::GetResList(TList &List)
{
	TListHandle OutResult;
	SBCheckError(TElStepNode_GetResList(_Handle, List.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TListHandle TElStepNode::GetResList(TList *List)
{
	TListHandle OutResult;
	SBCheckError(TElStepNode_GetResList(_Handle, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TLIST */

TElStepNode::TElStepNode(TElStepNodeHandle handle, TElOwnHandle ownHandle) : TElXPathNode(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELXPATH
TElStepNode::TElStepNode(TElXPath &XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElStepNode_Create(XPath.getHandle(), &_Handle));
}

TElStepNode::TElStepNode(TElXPath *XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElStepNode_Create((XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXPATH */

#endif /* SB_USE_CLASS_TELSTEPNODE */

#ifdef SB_USE_CLASS_TELPREDICATENODE

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElPredicateNode::CreateNode(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElPredicateNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElPredicateNode::CreateNode(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElPredicateNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElPredicateNode::CreateNode(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElPredicateNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElPredicateNode::CreateNode(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElPredicateNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElPredicateNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElPredicateNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElPredicateNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElPredicateNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElPredicateNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElPredicateNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElPredicateNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElPredicateNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE TListHandle TElPredicateNode::GetResList(TList &List)
{
	TListHandle OutResult;
	SBCheckError(TElPredicateNode_GetResList(_Handle, List.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TListHandle TElPredicateNode::GetResList(TList *List)
{
	TListHandle OutResult;
	SBCheckError(TElPredicateNode_GetResList(_Handle, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TLIST */

TElPredicateNode::TElPredicateNode(TElPredicateNodeHandle handle, TElOwnHandle ownHandle) : TElXPathNode(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELXPATH
TElPredicateNode::TElPredicateNode(TElXPath &XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPredicateNode_Create(XPath.getHandle(), &_Handle));
}

TElPredicateNode::TElPredicateNode(TElXPath *XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPredicateNode_Create((XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXPATH */

#endif /* SB_USE_CLASS_TELPREDICATENODE */

#ifdef SB_USE_CLASS_TELOREXPRNODE

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElOrExprNode::CreateNode(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElOrExprNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElOrExprNode::CreateNode(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElOrExprNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElOrExprNode::CreateNode(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElOrExprNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElOrExprNode::CreateNode(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElOrExprNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElOrExprNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElOrExprNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElOrExprNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElOrExprNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElOrExprNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElOrExprNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElOrExprNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElOrExprNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASSES_TELBOOLEAN_AND_TELXMLDOMNODE_AND_TLIST
SB_INLINE TElBooleanHandle TElOrExprNode::GetResBoolean(TElXMLDOMNode &Context, TList &List)
{
	TElBooleanHandle OutResult;
	SBCheckError(TElOrExprNode_GetResBoolean(_Handle, Context.getHandle(), List.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElBooleanHandle TElOrExprNode::GetResBoolean(TElXMLDOMNode *Context, TList *List)
{
	TElBooleanHandle OutResult;
	SBCheckError(TElOrExprNode_GetResBoolean(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELBOOLEAN_AND_TELXMLDOMNODE_AND_TLIST */

TElOrExprNode::TElOrExprNode(TElOrExprNodeHandle handle, TElOwnHandle ownHandle) : TElXPathNode(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELXPATH
TElOrExprNode::TElOrExprNode(TElXPath &XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOrExprNode_Create(XPath.getHandle(), &_Handle));
}

TElOrExprNode::TElOrExprNode(TElXPath *XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOrExprNode_Create((XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXPATH */

#endif /* SB_USE_CLASS_TELOREXPRNODE */

#ifdef SB_USE_CLASS_TELANDEXPRNODE

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElAndExprNode::CreateNode(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElAndExprNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElAndExprNode::CreateNode(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElAndExprNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElAndExprNode::CreateNode(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElAndExprNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElAndExprNode::CreateNode(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElAndExprNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElAndExprNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElAndExprNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElAndExprNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElAndExprNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElAndExprNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElAndExprNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElAndExprNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElAndExprNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASSES_TELBOOLEAN_AND_TELXMLDOMNODE_AND_TLIST
SB_INLINE TElBooleanHandle TElAndExprNode::GetResBoolean(TElXMLDOMNode &Context, TList &List)
{
	TElBooleanHandle OutResult;
	SBCheckError(TElAndExprNode_GetResBoolean(_Handle, Context.getHandle(), List.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElBooleanHandle TElAndExprNode::GetResBoolean(TElXMLDOMNode *Context, TList *List)
{
	TElBooleanHandle OutResult;
	SBCheckError(TElAndExprNode_GetResBoolean(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELBOOLEAN_AND_TELXMLDOMNODE_AND_TLIST */

TElAndExprNode::TElAndExprNode(TElAndExprNodeHandle handle, TElOwnHandle ownHandle) : TElXPathNode(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELXPATH
TElAndExprNode::TElAndExprNode(TElXPath &XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAndExprNode_Create(XPath.getHandle(), &_Handle));
}

TElAndExprNode::TElAndExprNode(TElXPath *XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAndExprNode_Create((XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXPATH */

#endif /* SB_USE_CLASS_TELANDEXPRNODE */

#ifdef SB_USE_CLASS_TELEQUALITYEXPRNODE

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElEqualityExprNode::CreateNode(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElEqualityExprNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElEqualityExprNode::CreateNode(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElEqualityExprNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElEqualityExprNode::CreateNode(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElEqualityExprNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElEqualityExprNode::CreateNode(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElEqualityExprNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElEqualityExprNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElEqualityExprNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElEqualityExprNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElEqualityExprNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElEqualityExprNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElEqualityExprNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElEqualityExprNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElEqualityExprNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASSES_TELBOOLEAN_AND_TELXMLDOMNODE_AND_TLIST
SB_INLINE TElBooleanHandle TElEqualityExprNode::GetResBoolean(TElXMLDOMNode &Context, TList &List)
{
	TElBooleanHandle OutResult;
	SBCheckError(TElEqualityExprNode_GetResBoolean(_Handle, Context.getHandle(), List.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElBooleanHandle TElEqualityExprNode::GetResBoolean(TElXMLDOMNode *Context, TList *List)
{
	TElBooleanHandle OutResult;
	SBCheckError(TElEqualityExprNode_GetResBoolean(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELBOOLEAN_AND_TELXMLDOMNODE_AND_TLIST */

TElEqualityExprNode::TElEqualityExprNode(TElEqualityExprNodeHandle handle, TElOwnHandle ownHandle) : TElXPathNode(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELXPATH
TElEqualityExprNode::TElEqualityExprNode(TElXPath &XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElEqualityExprNode_Create(XPath.getHandle(), &_Handle));
}

TElEqualityExprNode::TElEqualityExprNode(TElXPath *XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElEqualityExprNode_Create((XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXPATH */

#endif /* SB_USE_CLASS_TELEQUALITYEXPRNODE */

#ifdef SB_USE_CLASS_TELRELATIONALEXPRNODE

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElRelationalExprNode::CreateNode(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElRelationalExprNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElRelationalExprNode::CreateNode(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElRelationalExprNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElRelationalExprNode::CreateNode(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElRelationalExprNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElRelationalExprNode::CreateNode(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElRelationalExprNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElRelationalExprNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElRelationalExprNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElRelationalExprNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElRelationalExprNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElRelationalExprNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElRelationalExprNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElRelationalExprNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElRelationalExprNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASSES_TELBOOLEAN_AND_TELXMLDOMNODE_AND_TLIST
SB_INLINE TElBooleanHandle TElRelationalExprNode::GetResBoolean(TElXMLDOMNode &Context, TList &List)
{
	TElBooleanHandle OutResult;
	SBCheckError(TElRelationalExprNode_GetResBoolean(_Handle, Context.getHandle(), List.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElBooleanHandle TElRelationalExprNode::GetResBoolean(TElXMLDOMNode *Context, TList *List)
{
	TElBooleanHandle OutResult;
	SBCheckError(TElRelationalExprNode_GetResBoolean(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELBOOLEAN_AND_TELXMLDOMNODE_AND_TLIST */

TElRelationalExprNode::TElRelationalExprNode(TElRelationalExprNodeHandle handle, TElOwnHandle ownHandle) : TElXPathNode(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELXPATH
TElRelationalExprNode::TElRelationalExprNode(TElXPath &XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRelationalExprNode_Create(XPath.getHandle(), &_Handle));
}

TElRelationalExprNode::TElRelationalExprNode(TElXPath *XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRelationalExprNode_Create((XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXPATH */

#endif /* SB_USE_CLASS_TELRELATIONALEXPRNODE */

#ifdef SB_USE_CLASS_TELADDITIVEEXPRNODE

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElAdditiveExprNode::CreateNode(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElAdditiveExprNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElAdditiveExprNode::CreateNode(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElAdditiveExprNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElAdditiveExprNode::CreateNode(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElAdditiveExprNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElAdditiveExprNode::CreateNode(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElAdditiveExprNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElAdditiveExprNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElAdditiveExprNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElAdditiveExprNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElAdditiveExprNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElAdditiveExprNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElAdditiveExprNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElAdditiveExprNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElAdditiveExprNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASSES_TELNUMBER_AND_TELXMLDOMNODE_AND_TLIST
SB_INLINE TElNumberHandle TElAdditiveExprNode::GetResNumber(TElXMLDOMNode &Context, TList &List)
{
	TElNumberHandle OutResult;
	SBCheckError(TElAdditiveExprNode_GetResNumber(_Handle, Context.getHandle(), List.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElNumberHandle TElAdditiveExprNode::GetResNumber(TElXMLDOMNode *Context, TList *List)
{
	TElNumberHandle OutResult;
	SBCheckError(TElAdditiveExprNode_GetResNumber(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELNUMBER_AND_TELXMLDOMNODE_AND_TLIST */

TElAdditiveExprNode::TElAdditiveExprNode(TElAdditiveExprNodeHandle handle, TElOwnHandle ownHandle) : TElXPathNode(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELXPATH
TElAdditiveExprNode::TElAdditiveExprNode(TElXPath &XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAdditiveExprNode_Create(XPath.getHandle(), &_Handle));
}

TElAdditiveExprNode::TElAdditiveExprNode(TElXPath *XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAdditiveExprNode_Create((XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXPATH */

#endif /* SB_USE_CLASS_TELADDITIVEEXPRNODE */

#ifdef SB_USE_CLASS_TELMULTIPLICATIVEEXPRNODE

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElMultiplicativeExprNode::CreateNode(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElMultiplicativeExprNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElMultiplicativeExprNode::CreateNode(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElMultiplicativeExprNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElMultiplicativeExprNode::CreateNode(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElMultiplicativeExprNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElMultiplicativeExprNode::CreateNode(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElMultiplicativeExprNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElMultiplicativeExprNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElMultiplicativeExprNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElMultiplicativeExprNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElMultiplicativeExprNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElMultiplicativeExprNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElMultiplicativeExprNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElMultiplicativeExprNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElMultiplicativeExprNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASSES_TELNUMBER_AND_TELXMLDOMNODE_AND_TLIST
SB_INLINE TElNumberHandle TElMultiplicativeExprNode::GetResNumber(TElXMLDOMNode &Context, TList &List)
{
	TElNumberHandle OutResult;
	SBCheckError(TElMultiplicativeExprNode_GetResNumber(_Handle, Context.getHandle(), List.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElNumberHandle TElMultiplicativeExprNode::GetResNumber(TElXMLDOMNode *Context, TList *List)
{
	TElNumberHandle OutResult;
	SBCheckError(TElMultiplicativeExprNode_GetResNumber(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELNUMBER_AND_TELXMLDOMNODE_AND_TLIST */

TElMultiplicativeExprNode::TElMultiplicativeExprNode(TElMultiplicativeExprNodeHandle handle, TElOwnHandle ownHandle) : TElXPathNode(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELXPATH
TElMultiplicativeExprNode::TElMultiplicativeExprNode(TElXPath &XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMultiplicativeExprNode_Create(XPath.getHandle(), &_Handle));
}

TElMultiplicativeExprNode::TElMultiplicativeExprNode(TElXPath *XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMultiplicativeExprNode_Create((XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXPATH */

#endif /* SB_USE_CLASS_TELMULTIPLICATIVEEXPRNODE */

#ifdef SB_USE_CLASS_TELUNARYEXPRNODE

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElUnaryExprNode::CreateNode(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElUnaryExprNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElUnaryExprNode::CreateNode(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElUnaryExprNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElUnaryExprNode::CreateNode(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElUnaryExprNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElUnaryExprNode::CreateNode(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElUnaryExprNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElUnaryExprNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElUnaryExprNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElUnaryExprNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElUnaryExprNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElUnaryExprNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElUnaryExprNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElUnaryExprNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElUnaryExprNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASSES_TELNUMBER_AND_TELXMLDOMNODE_AND_TLIST
SB_INLINE TElNumberHandle TElUnaryExprNode::GetResNumber(TElXMLDOMNode &Context, TList &List)
{
	TElNumberHandle OutResult;
	SBCheckError(TElUnaryExprNode_GetResNumber(_Handle, Context.getHandle(), List.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElNumberHandle TElUnaryExprNode::GetResNumber(TElXMLDOMNode *Context, TList *List)
{
	TElNumberHandle OutResult;
	SBCheckError(TElUnaryExprNode_GetResNumber(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELNUMBER_AND_TELXMLDOMNODE_AND_TLIST */

TElUnaryExprNode::TElUnaryExprNode(TElUnaryExprNodeHandle handle, TElOwnHandle ownHandle) : TElXPathNode(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELXPATH
TElUnaryExprNode::TElUnaryExprNode(TElXPath &XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElUnaryExprNode_Create(XPath.getHandle(), &_Handle));
}

TElUnaryExprNode::TElUnaryExprNode(TElXPath *XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElUnaryExprNode_Create((XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXPATH */

#endif /* SB_USE_CLASS_TELUNARYEXPRNODE */

#ifdef SB_USE_CLASS_TELFILTEREXPRNODE

#ifdef SB_USE_CLASS_TELXPATH
TElXPathNodeHandle TElFilterExprNode::CreateNode(const sb_u16string &sQuery, sb_u16string &sQueryTail, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	int32_t szsQueryTail = (int32_t)sQueryTail.length();
	uint32_t _err = TElFilterExprNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), (sb_char16_t *)sQueryTail.data(), &szsQueryTail, XPath.getHandle(), &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		sQueryTail.resize(szsQueryTail);
		SBCheckError(SBGetLastReturnStringW(772249392, 1, (sb_char16_t *)sQueryTail.data(), &szsQueryTail));
	}
	else
		SBCheckError(_err);

	sQueryTail.resize(szsQueryTail);
	return OutResult;
}

TElXPathNodeHandle TElFilterExprNode::CreateNode(const sb_u16string &sQuery, sb_u16string &sQueryTail, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	int32_t szsQueryTail = (int32_t)sQueryTail.length();
	uint32_t _err = TElFilterExprNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), (sb_char16_t *)sQueryTail.data(), &szsQueryTail, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		sQueryTail.resize(szsQueryTail);
		SBCheckError(SBGetLastReturnStringW(772249392, 1, (sb_char16_t *)sQueryTail.data(), &szsQueryTail));
	}
	else
		SBCheckError(_err);

	sQueryTail.resize(szsQueryTail);
	return OutResult;
}
#ifdef SB_U16STRING_USED
TElXPathNodeHandle TElFilterExprNode::CreateNode(const std::wstring &sQuery, std::wstring &sQueryTail, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	std::string u16sQueryTail;
	sb_to_u16string(sQueryTail, u16sQueryTail);
	int32_t szsQueryTail = (int32_t)u16sQueryTail.length() >> 1;
	uint32_t _err = TElFilterExprNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, reinterpret_cast<sb_char16_t*>((char*)u16sQueryTail.data()), &szsQueryTail, XPath.getHandle(), &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16sQueryTail.resize(szsQueryTail << 1);
		SBCheckError(SBGetLastReturnStringW(772249392, 1, reinterpret_cast<sb_char16_t*>((char*)u16sQueryTail.data()), &szsQueryTail));
	}
	else
		SBCheckError(_err);

	u16sQueryTail.resize(szsQueryTail << 1);
	sb_u16_to_wstring(u16sQueryTail, sQueryTail);
	return OutResult;
}

TElXPathNodeHandle TElFilterExprNode::CreateNode(const std::wstring &sQuery, std::wstring &sQueryTail, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	std::string u16sQueryTail;
	sb_to_u16string(sQueryTail, u16sQueryTail);
	int32_t szsQueryTail = (int32_t)u16sQueryTail.length() >> 1;
	uint32_t _err = TElFilterExprNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, reinterpret_cast<sb_char16_t*>((char*)u16sQueryTail.data()), &szsQueryTail, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16sQueryTail.resize(szsQueryTail << 1);
		SBCheckError(SBGetLastReturnStringW(772249392, 1, reinterpret_cast<sb_char16_t*>((char*)u16sQueryTail.data()), &szsQueryTail));
	}
	else
		SBCheckError(_err);

	u16sQueryTail.resize(szsQueryTail << 1);
	sb_u16_to_wstring(u16sQueryTail, sQueryTail);
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
TElXPathNodeHandle TElFilterExprNode::CreateNode_Inst(const sb_u16string &sQuery, sb_u16string &sQueryTail, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	int32_t szsQueryTail = (int32_t)sQueryTail.length();
	uint32_t _err = TElFilterExprNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), (sb_char16_t *)sQueryTail.data(), &szsQueryTail, XPath.getHandle(), &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		sQueryTail.resize(szsQueryTail);
		SBCheckError(SBGetLastReturnStringW(772249392, 2, (sb_char16_t *)sQueryTail.data(), &szsQueryTail));
	}
	else
		SBCheckError(_err);

	sQueryTail.resize(szsQueryTail);
	return OutResult;
}

TElXPathNodeHandle TElFilterExprNode::CreateNode_Inst(const sb_u16string &sQuery, sb_u16string &sQueryTail, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	int32_t szsQueryTail = (int32_t)sQueryTail.length();
	uint32_t _err = TElFilterExprNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), (sb_char16_t *)sQueryTail.data(), &szsQueryTail, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		sQueryTail.resize(szsQueryTail);
		SBCheckError(SBGetLastReturnStringW(772249392, 2, (sb_char16_t *)sQueryTail.data(), &szsQueryTail));
	}
	else
		SBCheckError(_err);

	sQueryTail.resize(szsQueryTail);
	return OutResult;
}
#ifdef SB_U16STRING_USED
TElXPathNodeHandle TElFilterExprNode::CreateNode_Inst(const std::wstring &sQuery, std::wstring &sQueryTail, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	std::string u16sQueryTail;
	sb_to_u16string(sQueryTail, u16sQueryTail);
	int32_t szsQueryTail = (int32_t)u16sQueryTail.length() >> 1;
	uint32_t _err = TElFilterExprNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, reinterpret_cast<sb_char16_t*>((char*)u16sQueryTail.data()), &szsQueryTail, XPath.getHandle(), &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16sQueryTail.resize(szsQueryTail << 1);
		SBCheckError(SBGetLastReturnStringW(772249392, 2, reinterpret_cast<sb_char16_t*>((char*)u16sQueryTail.data()), &szsQueryTail));
	}
	else
		SBCheckError(_err);

	u16sQueryTail.resize(szsQueryTail << 1);
	sb_u16_to_wstring(u16sQueryTail, sQueryTail);
	return OutResult;
}

TElXPathNodeHandle TElFilterExprNode::CreateNode_Inst(const std::wstring &sQuery, std::wstring &sQueryTail, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	std::string u16sQueryTail;
	sb_to_u16string(sQueryTail, u16sQueryTail);
	int32_t szsQueryTail = (int32_t)u16sQueryTail.length() >> 1;
	uint32_t _err = TElFilterExprNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, reinterpret_cast<sb_char16_t*>((char*)u16sQueryTail.data()), &szsQueryTail, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16sQueryTail.resize(szsQueryTail << 1);
		SBCheckError(SBGetLastReturnStringW(772249392, 2, reinterpret_cast<sb_char16_t*>((char*)u16sQueryTail.data()), &szsQueryTail));
	}
	else
		SBCheckError(_err);

	u16sQueryTail.resize(szsQueryTail << 1);
	sb_u16_to_wstring(u16sQueryTail, sQueryTail);
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE TListHandle TElFilterExprNode::GetResList(TList &List)
{
	TListHandle OutResult;
	SBCheckError(TElFilterExprNode_GetResList(_Handle, List.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TListHandle TElFilterExprNode::GetResList(TList *List)
{
	TListHandle OutResult;
	SBCheckError(TElFilterExprNode_GetResList(_Handle, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TLIST */

TElFilterExprNode::TElFilterExprNode(TElFilterExprNodeHandle handle, TElOwnHandle ownHandle) : TElXPathNode(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELXPATH
TElFilterExprNode::TElFilterExprNode(TElXPath &XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFilterExprNode_Create(XPath.getHandle(), &_Handle));
}

TElFilterExprNode::TElFilterExprNode(TElXPath *XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFilterExprNode_Create((XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXPATH */

#endif /* SB_USE_CLASS_TELFILTEREXPRNODE */

#ifdef SB_USE_CLASS_TELPRIMARYEXPRNODE

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElPrimaryExprNode::CreateNode(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElPrimaryExprNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElPrimaryExprNode::CreateNode(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElPrimaryExprNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElPrimaryExprNode::CreateNode(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElPrimaryExprNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElPrimaryExprNode::CreateNode(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElPrimaryExprNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElPrimaryExprNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElPrimaryExprNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElPrimaryExprNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElPrimaryExprNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElPrimaryExprNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElPrimaryExprNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElPrimaryExprNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElPrimaryExprNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

TElPrimaryExprNode::TElPrimaryExprNode(TElPrimaryExprNodeHandle handle, TElOwnHandle ownHandle) : TElXPathNode(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELXPATH
TElPrimaryExprNode::TElPrimaryExprNode(TElXPath &XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPrimaryExprNode_Create(XPath.getHandle(), &_Handle));
}

TElPrimaryExprNode::TElPrimaryExprNode(TElXPath *XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPrimaryExprNode_Create((XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXPATH */

#endif /* SB_USE_CLASS_TELPRIMARYEXPRNODE */

#ifdef SB_USE_CLASS_TELVARIABLEREFERENCENODE

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElVariableReferenceNode::CreateNode(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElVariableReferenceNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElVariableReferenceNode::CreateNode(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElVariableReferenceNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElVariableReferenceNode::CreateNode(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElVariableReferenceNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElVariableReferenceNode::CreateNode(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElVariableReferenceNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElVariableReferenceNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElVariableReferenceNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElVariableReferenceNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElVariableReferenceNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElVariableReferenceNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElVariableReferenceNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElVariableReferenceNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElVariableReferenceNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASSES_TELBOOLEAN_AND_TELNUMBER_AND_TELSTRING_AND_TELXMLDOMNODE_AND_TLIST
void TElVariableReferenceNode::GetResultLocal(TElXMLDOMNode &Context, TList &InList, int32_t &iType, TList &List, TElBoolean &bBoolean, TElNumber &nNumber, TElString &sString)
{
	TElClassHandle hList = List.getHandle();
	TElClassHandle hbBoolean = bBoolean.getHandle();
	TElClassHandle hnNumber = nNumber.getHandle();
	TElClassHandle hsString = sString.getHandle();
	SBCheckError(TElVariableReferenceNode_GetResultLocal(_Handle, Context.getHandle(), InList.getHandle(), &iType, &hList, &hbBoolean, &hnNumber, &hsString));
	List.updateHandle(hList);
	bBoolean.updateHandle(hbBoolean);
	nNumber.updateHandle(hnNumber);
	sString.updateHandle(hsString);
}

void TElVariableReferenceNode::GetResultLocal(TElXMLDOMNode *Context, TList *InList, int32_t &iType, TList &List, TElBoolean &bBoolean, TElNumber &nNumber, TElString &sString)
{
	TElClassHandle hList = List.getHandle();
	TElClassHandle hbBoolean = bBoolean.getHandle();
	TElClassHandle hnNumber = nNumber.getHandle();
	TElClassHandle hsString = sString.getHandle();
	SBCheckError(TElVariableReferenceNode_GetResultLocal(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, (InList != NULL) ? InList->getHandle() : SB_NULL_HANDLE, &iType, &hList, &hbBoolean, &hnNumber, &hsString));
	List.updateHandle(hList);
	bBoolean.updateHandle(hbBoolean);
	nNumber.updateHandle(hnNumber);
	sString.updateHandle(hsString);
}
#endif /* SB_USE_CLASSES_TELBOOLEAN_AND_TELNUMBER_AND_TELSTRING_AND_TELXMLDOMNODE_AND_TLIST */

TElVariableReferenceNode::TElVariableReferenceNode(TElVariableReferenceNodeHandle handle, TElOwnHandle ownHandle) : TElXPathNode(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELXPATH
TElVariableReferenceNode::TElVariableReferenceNode(TElXPath &XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElVariableReferenceNode_Create(XPath.getHandle(), &_Handle));
}

TElVariableReferenceNode::TElVariableReferenceNode(TElXPath *XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElVariableReferenceNode_Create((XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXPATH */

#endif /* SB_USE_CLASS_TELVARIABLEREFERENCENODE */

#ifdef SB_USE_CLASS_TELLITERALNODE

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElLiteralNode::CreateNode(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElLiteralNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElLiteralNode::CreateNode(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElLiteralNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElLiteralNode::CreateNode(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElLiteralNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElLiteralNode::CreateNode(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElLiteralNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElLiteralNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElLiteralNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElLiteralNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElLiteralNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElLiteralNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElLiteralNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElLiteralNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElLiteralNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

TElLiteralNode::TElLiteralNode(TElLiteralNodeHandle handle, TElOwnHandle ownHandle) : TElXPathNode(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELXPATH
TElLiteralNode::TElLiteralNode(TElXPath &XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLiteralNode_Create(XPath.getHandle(), &_Handle));
}

TElLiteralNode::TElLiteralNode(TElXPath *XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLiteralNode_Create((XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXPATH */

#endif /* SB_USE_CLASS_TELLITERALNODE */

#ifdef SB_USE_CLASS_TELNUMBERNODE

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElNumberNode::CreateNode(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElNumberNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElNumberNode::CreateNode(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElNumberNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElNumberNode::CreateNode(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElNumberNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElNumberNode::CreateNode(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElNumberNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElNumberNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElNumberNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElNumberNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElNumberNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElNumberNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElNumberNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElNumberNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElNumberNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELNUMBER
SB_INLINE TElNumberHandle TElNumberNode::GetResNumber()
{
	TElNumberHandle OutResult;
	SBCheckError(TElNumberNode_GetResNumber(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELNUMBER */

TElNumberNode::TElNumberNode(TElNumberNodeHandle handle, TElOwnHandle ownHandle) : TElXPathNode(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELXPATH
TElNumberNode::TElNumberNode(TElXPath &XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElNumberNode_Create(XPath.getHandle(), &_Handle));
}

TElNumberNode::TElNumberNode(TElXPath *XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElNumberNode_Create((XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXPATH */

#endif /* SB_USE_CLASS_TELNUMBERNODE */

#ifdef SB_USE_CLASS_TELFUNCTIONCALLNODE

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElFunctionCallNode::CreateNode(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElFunctionCallNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElFunctionCallNode::CreateNode(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElFunctionCallNode_CreateNode(sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElFunctionCallNode::CreateNode(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElFunctionCallNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElFunctionCallNode::CreateNode(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElFunctionCallNode_CreateNode(reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASS_TELXPATH
SB_INLINE TElXPathNodeHandle TElFunctionCallNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElFunctionCallNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElFunctionCallNode::CreateNode_Inst(const sb_u16string &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	SBCheckError(TElFunctionCallNode_CreateNode_1(_Handle, sQuery.data(), (int32_t)sQuery.length(), (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXPathNodeHandle TElFunctionCallNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath &XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElFunctionCallNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, XPath.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXPathNodeHandle TElFunctionCallNode::CreateNode_Inst(const std::wstring &sQuery, TElXPath *XPath)
{
	TElXPathNodeHandle OutResult;
	std::string u16sQuery;
	sb_to_u16string(sQuery, u16sQuery);
	SBCheckError(TElFunctionCallNode_CreateNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16sQuery.data()), (int32_t)u16sQuery.length() >> 1, (XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXPATH */

#ifdef SB_USE_CLASSES_TELBOOLEAN_AND_TELNUMBER_AND_TELSTRING_AND_TELXMLDOMNODE_AND_TLIST
void TElFunctionCallNode::GetResultLocal(TElXMLDOMNode &Context, TList &InList, int32_t &iType, TList &List, TElBoolean &bBoolean, TElNumber &nNumber, TElString &sString)
{
	TElClassHandle hList = List.getHandle();
	TElClassHandle hbBoolean = bBoolean.getHandle();
	TElClassHandle hnNumber = nNumber.getHandle();
	TElClassHandle hsString = sString.getHandle();
	SBCheckError(TElFunctionCallNode_GetResultLocal(_Handle, Context.getHandle(), InList.getHandle(), &iType, &hList, &hbBoolean, &hnNumber, &hsString));
	List.updateHandle(hList);
	bBoolean.updateHandle(hbBoolean);
	nNumber.updateHandle(hnNumber);
	sString.updateHandle(hsString);
}

void TElFunctionCallNode::GetResultLocal(TElXMLDOMNode *Context, TList *InList, int32_t &iType, TList &List, TElBoolean &bBoolean, TElNumber &nNumber, TElString &sString)
{
	TElClassHandle hList = List.getHandle();
	TElClassHandle hbBoolean = bBoolean.getHandle();
	TElClassHandle hnNumber = nNumber.getHandle();
	TElClassHandle hsString = sString.getHandle();
	SBCheckError(TElFunctionCallNode_GetResultLocal(_Handle, (Context != NULL) ? Context->getHandle() : SB_NULL_HANDLE, (InList != NULL) ? InList->getHandle() : SB_NULL_HANDLE, &iType, &hList, &hbBoolean, &hnNumber, &hsString));
	List.updateHandle(hList);
	bBoolean.updateHandle(hbBoolean);
	nNumber.updateHandle(hnNumber);
	sString.updateHandle(hsString);
}
#endif /* SB_USE_CLASSES_TELBOOLEAN_AND_TELNUMBER_AND_TELSTRING_AND_TELXMLDOMNODE_AND_TLIST */

TElFunctionCallNode::TElFunctionCallNode(TElFunctionCallNodeHandle handle, TElOwnHandle ownHandle) : TElXPathNode(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELXPATH
TElFunctionCallNode::TElFunctionCallNode(TElXPath &XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFunctionCallNode_Create(XPath.getHandle(), &_Handle));
}

TElFunctionCallNode::TElFunctionCallNode(TElXPath *XPath) : TElXPathNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFunctionCallNode_Create((XPath != NULL) ? XPath->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXPATH */

#endif /* SB_USE_CLASS_TELFUNCTIONCALLNODE */

};	/* namespace SecureBlackbox */

