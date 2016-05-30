#include "sbxmltransform.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELXMLTRANSFORM

void TElXMLTransform::GetDefaultTransformAlgorithmURI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLTransform_GetDefaultTransformAlgorithmURI((sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1192175142, 0, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLTransform::GetDefaultTransformAlgorithmURI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLTransform_GetDefaultTransformAlgorithmURI(NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1192175142, 0, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElXMLTransform::GetDefaultTransformAlgorithmURI_Inst(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLTransform_GetDefaultTransformAlgorithmURI_1(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1192175142, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLTransform::GetDefaultTransformAlgorithmURI_Inst(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLTransform_GetDefaultTransformAlgorithmURI_1(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1192175142, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

bool TElXMLTransform::IsTransformAlgorithmSupported(const sb_u16string &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLTransform_IsTransformAlgorithmSupported(Algorithm.data(), (int32_t)Algorithm.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLTransform::IsTransformAlgorithmSupported(const std::wstring &Algorithm)
{
	std::string u16Algorithm;
	sb_to_u16string(Algorithm, u16Algorithm);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLTransform_IsTransformAlgorithmSupported(reinterpret_cast<const sb_char16_t*>(u16Algorithm.data()), (int32_t)u16Algorithm.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

bool TElXMLTransform::IsTransformAlgorithmSupported_Inst(const sb_u16string &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLTransform_IsTransformAlgorithmSupported_1(_Handle, Algorithm.data(), (int32_t)Algorithm.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLTransform::IsTransformAlgorithmSupported_Inst(const std::wstring &Algorithm)
{
	std::string u16Algorithm;
	sb_to_u16string(Algorithm, u16Algorithm);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLTransform_IsTransformAlgorithmSupported_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16Algorithm.data()), (int32_t)u16Algorithm.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElXMLTransform::Clear()
{
	SBCheckError(TElXMLTransform_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLTransform::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLTransform_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLTransform::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLTransform_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLTransform::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLTransform_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLTransform::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLTransform_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

TSBTransformedDataType TElXMLTransform::TransformData(const std::vector<uint8_t> &Data)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLTransform_TransformData(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TSBTransformedDataType TElXMLTransform::TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLTransform_TransformData_1(_Handle, Node.getHandle(), Reference.getHandle(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

TSBTransformedDataType TElXMLTransform::TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLTransform_TransformData_1(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, (Reference != NULL) ? Reference->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
TSBTransformedDataType TElXMLTransform::TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLTransform_TransformData_2(_Handle, Nodes.getHandle(), SB_STD_VECTOR_FRONT_ADR(Reference), (int32_t)Reference.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

TSBTransformedDataType TElXMLTransform::TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLTransform_TransformData_2(_Handle, (Nodes != NULL) ? Nodes->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Reference), (int32_t)Reference.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

SB_INLINE TClassHandle TElXMLTransform::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLTransform_ClassType(&OutResult));
	return OutResult;
}

void TElXMLTransform::get_TransformAlgorithmURI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLTransform_get_TransformAlgorithmURI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1913676402, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLTransform::get_TransformAlgorithmURI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLTransform_get_TransformAlgorithmURI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1913676402, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLTransform::set_TransformAlgorithmURI(const sb_u16string &Value)
{
	SBCheckError(TElXMLTransform_set_TransformAlgorithmURI(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLTransform::set_TransformAlgorithmURI(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLTransform_set_TransformAlgorithmURI(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLTransform::get_TransformedData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLTransform_get_TransformedData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1318213218, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElXMLTransform::set_TransformedData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElXMLTransform_set_TransformedData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TElXMLDOMNode* TElXMLTransform::get_TransformedNode()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLTransform_get_TransformedNode(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TransformedNode)
		this->_Inst_TransformedNode = new TElXMLDOMNode(hOutResult, ohFalse);
	else
		this->_Inst_TransformedNode->updateHandle(hOutResult);
	return this->_Inst_TransformedNode;
}

SB_INLINE void TElXMLTransform::set_TransformedNode(TElXMLDOMNode &Value)
{
	SBCheckError(TElXMLTransform_set_TransformedNode(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLTransform::set_TransformedNode(TElXMLDOMNode *Value)
{
	SBCheckError(TElXMLTransform_set_TransformedNode(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
TElXMLDOMNodeList* TElXMLTransform::get_TransformedNodes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLTransform_get_TransformedNodes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TransformedNodes)
		this->_Inst_TransformedNodes = new TElXMLDOMNodeList(hOutResult, ohFalse);
	else
		this->_Inst_TransformedNodes->updateHandle(hOutResult);
	return this->_Inst_TransformedNodes;
}

SB_INLINE void TElXMLTransform::set_TransformedNodes(TElXMLDOMNodeList &Value)
{
	SBCheckError(TElXMLTransform_set_TransformedNodes(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLTransform::set_TransformedNodes(TElXMLDOMNodeList *Value)
{
	SBCheckError(TElXMLTransform_set_TransformedNodes(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TElXMLDOMNode* TElXMLTransform::get_ReferenceNode()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLTransform_get_ReferenceNode(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ReferenceNode)
		this->_Inst_ReferenceNode = new TElXMLDOMNode(hOutResult, ohFalse);
	else
		this->_Inst_ReferenceNode->updateHandle(hOutResult);
	return this->_Inst_ReferenceNode;
}

SB_INLINE void TElXMLTransform::set_ReferenceNode(TElXMLDOMNode &Value)
{
	SBCheckError(TElXMLTransform_set_ReferenceNode(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLTransform::set_ReferenceNode(TElXMLDOMNode *Value)
{
	SBCheckError(TElXMLTransform_set_ReferenceNode(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

void TElXMLTransform::get_ReferenceNodes(std::vector<TElXMLDOMNodeHandle> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size() * 4;
	uint32_t _err = TElXMLTransform_get_ReferenceNodes(_Handle, (TElXMLDOMNodeHandle *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult / 4);
		SBCheckError(SBGetLastReturnBuffer(-1811549564, 1, (TElXMLDOMNodeHandle *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult / 4);
}

SB_INLINE void TElXMLTransform::set_ReferenceNodes(const std::vector<TElXMLDOMNodeHandle> &Value)
{
	SBCheckError(TElXMLTransform_set_ReferenceNodes(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElXMLTransform::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	this->_Inst_TransformedNode = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
	this->_Inst_TransformedNodes = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	this->_Inst_ReferenceNode = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
}

TElXMLTransform::TElXMLTransform(TElXMLTransformHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
	initInstances();
}

TElXMLTransform::TElXMLTransform() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLTransform_Create(&_Handle));
}

TElXMLTransform::~TElXMLTransform()
{
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	delete this->_Inst_TransformedNode;
	this->_Inst_TransformedNode = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
	delete this->_Inst_TransformedNodes;
	this->_Inst_TransformedNodes = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	delete this->_Inst_ReferenceNode;
	this->_Inst_ReferenceNode = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
}
#endif /* SB_USE_CLASS_TELXMLTRANSFORM */

#ifdef SB_USE_CLASS_TELXMLNULLTRANSFORM

void TElXMLNullTransform::GetDefaultTransformAlgorithmURI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLNullTransform_GetDefaultTransformAlgorithmURI((sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(713229815, 0, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLNullTransform::GetDefaultTransformAlgorithmURI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLNullTransform_GetDefaultTransformAlgorithmURI(NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(713229815, 0, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElXMLNullTransform::GetDefaultTransformAlgorithmURI_Inst(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLNullTransform_GetDefaultTransformAlgorithmURI_1(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(713229815, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLNullTransform::GetDefaultTransformAlgorithmURI_Inst(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLNullTransform_GetDefaultTransformAlgorithmURI_1(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(713229815, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

bool TElXMLNullTransform::IsTransformAlgorithmSupported(const sb_u16string &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLNullTransform_IsTransformAlgorithmSupported(Algorithm.data(), (int32_t)Algorithm.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLNullTransform::IsTransformAlgorithmSupported(const std::wstring &Algorithm)
{
	std::string u16Algorithm;
	sb_to_u16string(Algorithm, u16Algorithm);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLNullTransform_IsTransformAlgorithmSupported(reinterpret_cast<const sb_char16_t*>(u16Algorithm.data()), (int32_t)u16Algorithm.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

bool TElXMLNullTransform::IsTransformAlgorithmSupported_Inst(const sb_u16string &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLNullTransform_IsTransformAlgorithmSupported_1(_Handle, Algorithm.data(), (int32_t)Algorithm.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLNullTransform::IsTransformAlgorithmSupported_Inst(const std::wstring &Algorithm)
{
	std::string u16Algorithm;
	sb_to_u16string(Algorithm, u16Algorithm);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLNullTransform_IsTransformAlgorithmSupported_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16Algorithm.data()), (int32_t)u16Algorithm.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

TSBTransformedDataType TElXMLNullTransform::TransformData(const std::vector<uint8_t> &Data)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLNullTransform_TransformData(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TSBTransformedDataType TElXMLNullTransform::TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLNullTransform_TransformData_1(_Handle, Node.getHandle(), Reference.getHandle(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

TSBTransformedDataType TElXMLNullTransform::TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLNullTransform_TransformData_1(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, (Reference != NULL) ? Reference->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
TSBTransformedDataType TElXMLNullTransform::TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLNullTransform_TransformData_2(_Handle, Nodes.getHandle(), SB_STD_VECTOR_FRONT_ADR(Reference), (int32_t)Reference.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

TSBTransformedDataType TElXMLNullTransform::TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLNullTransform_TransformData_2(_Handle, (Nodes != NULL) ? Nodes->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Reference), (int32_t)Reference.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

SB_INLINE TClassHandle TElXMLNullTransform::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLNullTransform_ClassType(&OutResult));
	return OutResult;
}

TElXMLNullTransform::TElXMLNullTransform(TElXMLNullTransformHandle handle, TElOwnHandle ownHandle) : TElXMLTransform(handle, ownHandle)
{
}

TElXMLNullTransform::TElXMLNullTransform() : TElXMLTransform(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLNullTransform_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLNULLTRANSFORM */

#ifdef SB_USE_CLASS_TELXMLBASE64TRANSFORM

void TElXMLBase64Transform::GetDefaultTransformAlgorithmURI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLBase64Transform_GetDefaultTransformAlgorithmURI((sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-128899505, 0, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLBase64Transform::GetDefaultTransformAlgorithmURI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLBase64Transform_GetDefaultTransformAlgorithmURI(NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-128899505, 0, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElXMLBase64Transform::GetDefaultTransformAlgorithmURI_Inst(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLBase64Transform_GetDefaultTransformAlgorithmURI_1(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-128899505, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLBase64Transform::GetDefaultTransformAlgorithmURI_Inst(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLBase64Transform_GetDefaultTransformAlgorithmURI_1(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-128899505, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

bool TElXMLBase64Transform::IsTransformAlgorithmSupported(const sb_u16string &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLBase64Transform_IsTransformAlgorithmSupported(Algorithm.data(), (int32_t)Algorithm.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLBase64Transform::IsTransformAlgorithmSupported(const std::wstring &Algorithm)
{
	std::string u16Algorithm;
	sb_to_u16string(Algorithm, u16Algorithm);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLBase64Transform_IsTransformAlgorithmSupported(reinterpret_cast<const sb_char16_t*>(u16Algorithm.data()), (int32_t)u16Algorithm.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

bool TElXMLBase64Transform::IsTransformAlgorithmSupported_Inst(const sb_u16string &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLBase64Transform_IsTransformAlgorithmSupported_1(_Handle, Algorithm.data(), (int32_t)Algorithm.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLBase64Transform::IsTransformAlgorithmSupported_Inst(const std::wstring &Algorithm)
{
	std::string u16Algorithm;
	sb_to_u16string(Algorithm, u16Algorithm);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLBase64Transform_IsTransformAlgorithmSupported_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16Algorithm.data()), (int32_t)u16Algorithm.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

TSBTransformedDataType TElXMLBase64Transform::TransformData(const std::vector<uint8_t> &Data)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLBase64Transform_TransformData(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TSBTransformedDataType TElXMLBase64Transform::TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLBase64Transform_TransformData_1(_Handle, Node.getHandle(), Reference.getHandle(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

TSBTransformedDataType TElXMLBase64Transform::TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLBase64Transform_TransformData_1(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, (Reference != NULL) ? Reference->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
TSBTransformedDataType TElXMLBase64Transform::TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLBase64Transform_TransformData_2(_Handle, Nodes.getHandle(), SB_STD_VECTOR_FRONT_ADR(Reference), (int32_t)Reference.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

TSBTransformedDataType TElXMLBase64Transform::TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLBase64Transform_TransformData_2(_Handle, (Nodes != NULL) ? Nodes->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Reference), (int32_t)Reference.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

SB_INLINE TClassHandle TElXMLBase64Transform::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLBase64Transform_ClassType(&OutResult));
	return OutResult;
}

bool TElXMLBase64Transform::get_OldMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLBase64Transform_get_OldMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLBase64Transform::set_OldMode(bool Value)
{
	SBCheckError(TElXMLBase64Transform_set_OldMode(_Handle, (int8_t)Value));
}

TElXMLBase64Transform::TElXMLBase64Transform(TElXMLBase64TransformHandle handle, TElOwnHandle ownHandle) : TElXMLTransform(handle, ownHandle)
{
}

TElXMLBase64Transform::TElXMLBase64Transform() : TElXMLTransform(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLBase64Transform_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLBASE64TRANSFORM */

#ifdef SB_USE_CLASS_TELXMLC14NTRANSFORM

void TElXMLC14NTransform::GetDefaultTransformAlgorithmURI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLC14NTransform_GetDefaultTransformAlgorithmURI((sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1209301160, 0, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLC14NTransform::GetDefaultTransformAlgorithmURI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLC14NTransform_GetDefaultTransformAlgorithmURI(NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1209301160, 0, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElXMLC14NTransform::GetDefaultTransformAlgorithmURI_Inst(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLC14NTransform_GetDefaultTransformAlgorithmURI_1(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1209301160, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLC14NTransform::GetDefaultTransformAlgorithmURI_Inst(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLC14NTransform_GetDefaultTransformAlgorithmURI_1(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1209301160, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

bool TElXMLC14NTransform::IsTransformAlgorithmSupported(const sb_u16string &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLC14NTransform_IsTransformAlgorithmSupported(Algorithm.data(), (int32_t)Algorithm.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLC14NTransform::IsTransformAlgorithmSupported(const std::wstring &Algorithm)
{
	std::string u16Algorithm;
	sb_to_u16string(Algorithm, u16Algorithm);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLC14NTransform_IsTransformAlgorithmSupported(reinterpret_cast<const sb_char16_t*>(u16Algorithm.data()), (int32_t)u16Algorithm.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

bool TElXMLC14NTransform::IsTransformAlgorithmSupported_Inst(const sb_u16string &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLC14NTransform_IsTransformAlgorithmSupported_1(_Handle, Algorithm.data(), (int32_t)Algorithm.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLC14NTransform::IsTransformAlgorithmSupported_Inst(const std::wstring &Algorithm)
{
	std::string u16Algorithm;
	sb_to_u16string(Algorithm, u16Algorithm);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLC14NTransform_IsTransformAlgorithmSupported_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16Algorithm.data()), (int32_t)u16Algorithm.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElXMLC14NTransform::Clear()
{
	SBCheckError(TElXMLC14NTransform_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLC14NTransform::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLC14NTransform_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLC14NTransform::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLC14NTransform_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLC14NTransform::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLC14NTransform_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLC14NTransform::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLC14NTransform_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

TSBTransformedDataType TElXMLC14NTransform::TransformData(const std::vector<uint8_t> &Data)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLC14NTransform_TransformData(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TSBTransformedDataType TElXMLC14NTransform::TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLC14NTransform_TransformData_1(_Handle, Node.getHandle(), Reference.getHandle(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

TSBTransformedDataType TElXMLC14NTransform::TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLC14NTransform_TransformData_1(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, (Reference != NULL) ? Reference->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
TSBTransformedDataType TElXMLC14NTransform::TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLC14NTransform_TransformData_2(_Handle, Nodes.getHandle(), SB_STD_VECTOR_FRONT_ADR(Reference), (int32_t)Reference.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

TSBTransformedDataType TElXMLC14NTransform::TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLC14NTransform_TransformData_2(_Handle, (Nodes != NULL) ? Nodes->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Reference), (int32_t)Reference.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

SB_INLINE TClassHandle TElXMLC14NTransform::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLC14NTransform_ClassType(&OutResult));
	return OutResult;
}

TElXMLCanonicalizationMethod TElXMLC14NTransform::get_CanonicalizationMethod()
{
	TElXMLCanonicalizationMethodRaw OutResultRaw = 0;
	SBCheckError(TElXMLC14NTransform_get_CanonicalizationMethod(_Handle, &OutResultRaw));
	return (TElXMLCanonicalizationMethod)OutResultRaw;
}

SB_INLINE void TElXMLC14NTransform::set_CanonicalizationMethod(TElXMLCanonicalizationMethod Value)
{
	SBCheckError(TElXMLC14NTransform_set_CanonicalizationMethod(_Handle, (TElXMLCanonicalizationMethodRaw)Value));
}

void TElXMLC14NTransform::get_ExclusiveCanonicalizationPrefix(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLC14NTransform_get_ExclusiveCanonicalizationPrefix(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-96234817, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLC14NTransform::get_ExclusiveCanonicalizationPrefix(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLC14NTransform_get_ExclusiveCanonicalizationPrefix(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-96234817, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLC14NTransform::set_ExclusiveCanonicalizationPrefix(const sb_u16string &Value)
{
	SBCheckError(TElXMLC14NTransform_set_ExclusiveCanonicalizationPrefix(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLC14NTransform::set_ExclusiveCanonicalizationPrefix(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLC14NTransform_set_ExclusiveCanonicalizationPrefix(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLC14NTransform::get_InclusiveNamespacesPrefixList(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLC14NTransform_get_InclusiveNamespacesPrefixList(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1781126645, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLC14NTransform::get_InclusiveNamespacesPrefixList(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLC14NTransform_get_InclusiveNamespacesPrefixList(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1781126645, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLC14NTransform::set_InclusiveNamespacesPrefixList(const sb_u16string &Value)
{
	SBCheckError(TElXMLC14NTransform_set_InclusiveNamespacesPrefixList(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLC14NTransform::set_InclusiveNamespacesPrefixList(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLC14NTransform_set_InclusiveNamespacesPrefixList(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLC14NTransform::TElXMLC14NTransform(TElXMLC14NTransformHandle handle, TElOwnHandle ownHandle) : TElXMLTransform(handle, ownHandle)
{
}

TElXMLC14NTransform::TElXMLC14NTransform() : TElXMLTransform(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLC14NTransform_Create(&_Handle));
}

TElXMLC14NTransform::TElXMLC14NTransform(TElXMLCanonicalizationMethod AMethod) : TElXMLTransform(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLC14NTransform_Create_1((TElXMLCanonicalizationMethodRaw)AMethod, &_Handle));
}

#endif /* SB_USE_CLASS_TELXMLC14NTRANSFORM */

#ifdef SB_USE_CLASS_TELXMLENVELOPEDSIGNATURETRANSFORM

void TElXMLEnvelopedSignatureTransform::GetDefaultTransformAlgorithmURI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLEnvelopedSignatureTransform_GetDefaultTransformAlgorithmURI((sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-228595407, 0, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLEnvelopedSignatureTransform::GetDefaultTransformAlgorithmURI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLEnvelopedSignatureTransform_GetDefaultTransformAlgorithmURI(NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-228595407, 0, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElXMLEnvelopedSignatureTransform::GetDefaultTransformAlgorithmURI_Inst(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLEnvelopedSignatureTransform_GetDefaultTransformAlgorithmURI_1(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-228595407, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLEnvelopedSignatureTransform::GetDefaultTransformAlgorithmURI_Inst(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLEnvelopedSignatureTransform_GetDefaultTransformAlgorithmURI_1(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-228595407, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

bool TElXMLEnvelopedSignatureTransform::IsTransformAlgorithmSupported(const sb_u16string &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLEnvelopedSignatureTransform_IsTransformAlgorithmSupported(Algorithm.data(), (int32_t)Algorithm.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLEnvelopedSignatureTransform::IsTransformAlgorithmSupported(const std::wstring &Algorithm)
{
	std::string u16Algorithm;
	sb_to_u16string(Algorithm, u16Algorithm);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLEnvelopedSignatureTransform_IsTransformAlgorithmSupported(reinterpret_cast<const sb_char16_t*>(u16Algorithm.data()), (int32_t)u16Algorithm.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

bool TElXMLEnvelopedSignatureTransform::IsTransformAlgorithmSupported_Inst(const sb_u16string &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLEnvelopedSignatureTransform_IsTransformAlgorithmSupported_1(_Handle, Algorithm.data(), (int32_t)Algorithm.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLEnvelopedSignatureTransform::IsTransformAlgorithmSupported_Inst(const std::wstring &Algorithm)
{
	std::string u16Algorithm;
	sb_to_u16string(Algorithm, u16Algorithm);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLEnvelopedSignatureTransform_IsTransformAlgorithmSupported_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16Algorithm.data()), (int32_t)u16Algorithm.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

bool TElXMLEnvelopedSignatureTransform::GetDefaultStrictMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLEnvelopedSignatureTransform_GetDefaultStrictMode(&OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElXMLEnvelopedSignatureTransform::GetDefaultStrictMode_Inst()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLEnvelopedSignatureTransform_GetDefaultStrictMode_1(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLEnvelopedSignatureTransform::SetDefaultStrictMode(bool Value)
{
	SBCheckError(TElXMLEnvelopedSignatureTransform_SetDefaultStrictMode((int8_t)Value));
}

SB_INLINE void TElXMLEnvelopedSignatureTransform::SetDefaultStrictMode_Inst(bool Value)
{
	SBCheckError(TElXMLEnvelopedSignatureTransform_SetDefaultStrictMode_1(_Handle, (int8_t)Value));
}

TSBTransformedDataType TElXMLEnvelopedSignatureTransform::TransformData(const std::vector<uint8_t> &Data)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLEnvelopedSignatureTransform_TransformData(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TSBTransformedDataType TElXMLEnvelopedSignatureTransform::TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLEnvelopedSignatureTransform_TransformData_1(_Handle, Node.getHandle(), Reference.getHandle(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

TSBTransformedDataType TElXMLEnvelopedSignatureTransform::TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLEnvelopedSignatureTransform_TransformData_1(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, (Reference != NULL) ? Reference->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
TSBTransformedDataType TElXMLEnvelopedSignatureTransform::TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLEnvelopedSignatureTransform_TransformData_2(_Handle, Nodes.getHandle(), SB_STD_VECTOR_FRONT_ADR(Reference), (int32_t)Reference.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

TSBTransformedDataType TElXMLEnvelopedSignatureTransform::TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLEnvelopedSignatureTransform_TransformData_2(_Handle, (Nodes != NULL) ? Nodes->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Reference), (int32_t)Reference.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
SB_INLINE TElXMLDOMNodeHandle TElXMLEnvelopedSignatureTransform::TransformNode(TElXMLDOMNode &Node)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLEnvelopedSignatureTransform_TransformNode(_Handle, Node.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMNodeHandle TElXMLEnvelopedSignatureTransform::TransformNode(TElXMLDOMNode *Node)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLEnvelopedSignatureTransform_TransformNode(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

SB_INLINE TClassHandle TElXMLEnvelopedSignatureTransform::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLEnvelopedSignatureTransform_ClassType(&OutResult));
	return OutResult;
}

bool TElXMLEnvelopedSignatureTransform::get_StrictMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLEnvelopedSignatureTransform_get_StrictMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLEnvelopedSignatureTransform::set_StrictMode(bool Value)
{
	SBCheckError(TElXMLEnvelopedSignatureTransform_set_StrictMode(_Handle, (int8_t)Value));
}

TElXMLEnvelopedSignatureTransform::TElXMLEnvelopedSignatureTransform(TElXMLEnvelopedSignatureTransformHandle handle, TElOwnHandle ownHandle) : TElXMLTransform(handle, ownHandle)
{
}

TElXMLEnvelopedSignatureTransform::TElXMLEnvelopedSignatureTransform() : TElXMLTransform(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLEnvelopedSignatureTransform_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLENVELOPEDSIGNATURETRANSFORM */

#ifdef SB_USE_CLASS_TELXMLXPATHTRANSFORM

void TElXMLXPathTransform::GetDefaultTransformAlgorithmURI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLXPathTransform_GetDefaultTransformAlgorithmURI((sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(2069546845, 0, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLXPathTransform::GetDefaultTransformAlgorithmURI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLXPathTransform_GetDefaultTransformAlgorithmURI(NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(2069546845, 0, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElXMLXPathTransform::GetDefaultTransformAlgorithmURI_Inst(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLXPathTransform_GetDefaultTransformAlgorithmURI_1(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(2069546845, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLXPathTransform::GetDefaultTransformAlgorithmURI_Inst(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLXPathTransform_GetDefaultTransformAlgorithmURI_1(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(2069546845, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

bool TElXMLXPathTransform::IsTransformAlgorithmSupported(const sb_u16string &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLXPathTransform_IsTransformAlgorithmSupported(Algorithm.data(), (int32_t)Algorithm.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLXPathTransform::IsTransformAlgorithmSupported(const std::wstring &Algorithm)
{
	std::string u16Algorithm;
	sb_to_u16string(Algorithm, u16Algorithm);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLXPathTransform_IsTransformAlgorithmSupported(reinterpret_cast<const sb_char16_t*>(u16Algorithm.data()), (int32_t)u16Algorithm.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

bool TElXMLXPathTransform::IsTransformAlgorithmSupported_Inst(const sb_u16string &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLXPathTransform_IsTransformAlgorithmSupported_1(_Handle, Algorithm.data(), (int32_t)Algorithm.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLXPathTransform::IsTransformAlgorithmSupported_Inst(const std::wstring &Algorithm)
{
	std::string u16Algorithm;
	sb_to_u16string(Algorithm, u16Algorithm);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLXPathTransform_IsTransformAlgorithmSupported_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16Algorithm.data()), (int32_t)u16Algorithm.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElXMLXPathTransform::Clear()
{
	SBCheckError(TElXMLXPathTransform_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLXPathTransform::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLXPathTransform_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLXPathTransform::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLXPathTransform_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLXPathTransform::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLXPathTransform_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLXPathTransform::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLXPathTransform_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

TSBTransformedDataType TElXMLXPathTransform::TransformData(const std::vector<uint8_t> &Data)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLXPathTransform_TransformData(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TSBTransformedDataType TElXMLXPathTransform::TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLXPathTransform_TransformData_1(_Handle, Node.getHandle(), Reference.getHandle(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

TSBTransformedDataType TElXMLXPathTransform::TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLXPathTransform_TransformData_1(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, (Reference != NULL) ? Reference->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
TSBTransformedDataType TElXMLXPathTransform::TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLXPathTransform_TransformData_2(_Handle, Nodes.getHandle(), SB_STD_VECTOR_FRONT_ADR(Reference), (int32_t)Reference.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

TSBTransformedDataType TElXMLXPathTransform::TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLXPathTransform_TransformData_2(_Handle, (Nodes != NULL) ? Nodes->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Reference), (int32_t)Reference.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

SB_INLINE TClassHandle TElXMLXPathTransform::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLXPathTransform_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLNAMESPACEMAP
TElXMLNamespaceMap* TElXMLXPathTransform::get_NamespaceMap()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLXPathTransform_get_NamespaceMap(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NamespaceMap)
		this->_Inst_NamespaceMap = new TElXMLNamespaceMap(hOutResult, ohFalse);
	else
		this->_Inst_NamespaceMap->updateHandle(hOutResult);
	return this->_Inst_NamespaceMap;
}
#endif /* SB_USE_CLASS_TELXMLNAMESPACEMAP */

void TElXMLXPathTransform::get_XPath(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLXPathTransform_get_XPath(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1058009468, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLXPathTransform::get_XPath(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLXPathTransform_get_XPath(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1058009468, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLXPathTransform::set_XPath(const sb_u16string &Value)
{
	SBCheckError(TElXMLXPathTransform_set_XPath(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLXPathTransform::set_XPath(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLXPathTransform_set_XPath(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLXPathTransform::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLNAMESPACEMAP
	this->_Inst_NamespaceMap = NULL;
#endif /* SB_USE_CLASS_TELXMLNAMESPACEMAP */
}

TElXMLXPathTransform::TElXMLXPathTransform(TElXMLXPathTransformHandle handle, TElOwnHandle ownHandle) : TElXMLTransform(handle, ownHandle)
{
	initInstances();
}

TElXMLXPathTransform::TElXMLXPathTransform() : TElXMLTransform(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLXPathTransform_Create(&_Handle));
}

TElXMLXPathTransform::~TElXMLXPathTransform()
{
#ifdef SB_USE_CLASS_TELXMLNAMESPACEMAP
	delete this->_Inst_NamespaceMap;
	this->_Inst_NamespaceMap = NULL;
#endif /* SB_USE_CLASS_TELXMLNAMESPACEMAP */
}
#endif /* SB_USE_CLASS_TELXMLXPATHTRANSFORM */

#ifdef SB_USE_CLASS_TELXMLXPATHFILTERITEM

TSBXPathFilterOperation TElXMLXPathFilterItem::get_Filter()
{
	TSBXPathFilterOperationRaw OutResultRaw = 0;
	SBCheckError(TElXMLXPathFilterItem_get_Filter(_Handle, &OutResultRaw));
	return (TSBXPathFilterOperation)OutResultRaw;
}

SB_INLINE void TElXMLXPathFilterItem::set_Filter(TSBXPathFilterOperation Value)
{
	SBCheckError(TElXMLXPathFilterItem_set_Filter(_Handle, (TSBXPathFilterOperationRaw)Value));
}

#ifdef SB_USE_CLASS_TELXMLNAMESPACEMAP
TElXMLNamespaceMap* TElXMLXPathFilterItem::get_NamespaceMap()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLXPathFilterItem_get_NamespaceMap(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NamespaceMap)
		this->_Inst_NamespaceMap = new TElXMLNamespaceMap(hOutResult, ohFalse);
	else
		this->_Inst_NamespaceMap->updateHandle(hOutResult);
	return this->_Inst_NamespaceMap;
}
#endif /* SB_USE_CLASS_TELXMLNAMESPACEMAP */

void TElXMLXPathFilterItem::get_XPath(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLXPathFilterItem_get_XPath(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-472882516, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLXPathFilterItem::get_XPath(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLXPathFilterItem_get_XPath(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-472882516, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLXPathFilterItem::set_XPath(const sb_u16string &Value)
{
	SBCheckError(TElXMLXPathFilterItem_set_XPath(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLXPathFilterItem::set_XPath(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLXPathFilterItem_set_XPath(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLDOMElement* TElXMLXPathFilterItem::get_XMLElement()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLXPathFilterItem_get_XMLElement(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_XMLElement)
		this->_Inst_XMLElement = new TElXMLDOMElement(hOutResult, ohFalse);
	else
		this->_Inst_XMLElement->updateHandle(hOutResult);
	return this->_Inst_XMLElement;
}

SB_INLINE void TElXMLXPathFilterItem::set_XMLElement(TElXMLDOMElement &Value)
{
	SBCheckError(TElXMLXPathFilterItem_set_XMLElement(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLXPathFilterItem::set_XMLElement(TElXMLDOMElement *Value)
{
	SBCheckError(TElXMLXPathFilterItem_set_XMLElement(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

void TElXMLXPathFilterItem::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLNAMESPACEMAP
	this->_Inst_NamespaceMap = NULL;
#endif /* SB_USE_CLASS_TELXMLNAMESPACEMAP */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	this->_Inst_XMLElement = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
}

TElXMLXPathFilterItem::TElXMLXPathFilterItem(TElXMLXPathFilterItemHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElXMLXPathFilterItem::TElXMLXPathFilterItem() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLXPathFilterItem_Create(&_Handle));
}

TElXMLXPathFilterItem::~TElXMLXPathFilterItem()
{
#ifdef SB_USE_CLASS_TELXMLNAMESPACEMAP
	delete this->_Inst_NamespaceMap;
	this->_Inst_NamespaceMap = NULL;
#endif /* SB_USE_CLASS_TELXMLNAMESPACEMAP */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	delete this->_Inst_XMLElement;
	this->_Inst_XMLElement = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
}
#endif /* SB_USE_CLASS_TELXMLXPATHFILTERITEM */

#ifdef SB_USE_CLASS_TELXMLXPATHFILTER2TRANSFORM

void TElXMLXPathFilter2Transform::GetDefaultTransformAlgorithmURI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLXPathFilter2Transform_GetDefaultTransformAlgorithmURI((sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(922357719, 0, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLXPathFilter2Transform::GetDefaultTransformAlgorithmURI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLXPathFilter2Transform_GetDefaultTransformAlgorithmURI(NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(922357719, 0, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElXMLXPathFilter2Transform::GetDefaultTransformAlgorithmURI_Inst(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLXPathFilter2Transform_GetDefaultTransformAlgorithmURI_1(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(922357719, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLXPathFilter2Transform::GetDefaultTransformAlgorithmURI_Inst(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLXPathFilter2Transform_GetDefaultTransformAlgorithmURI_1(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(922357719, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

bool TElXMLXPathFilter2Transform::IsTransformAlgorithmSupported(const sb_u16string &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLXPathFilter2Transform_IsTransformAlgorithmSupported(Algorithm.data(), (int32_t)Algorithm.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLXPathFilter2Transform::IsTransformAlgorithmSupported(const std::wstring &Algorithm)
{
	std::string u16Algorithm;
	sb_to_u16string(Algorithm, u16Algorithm);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLXPathFilter2Transform_IsTransformAlgorithmSupported(reinterpret_cast<const sb_char16_t*>(u16Algorithm.data()), (int32_t)u16Algorithm.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

bool TElXMLXPathFilter2Transform::IsTransformAlgorithmSupported_Inst(const sb_u16string &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLXPathFilter2Transform_IsTransformAlgorithmSupported_1(_Handle, Algorithm.data(), (int32_t)Algorithm.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLXPathFilter2Transform::IsTransformAlgorithmSupported_Inst(const std::wstring &Algorithm)
{
	std::string u16Algorithm;
	sb_to_u16string(Algorithm, u16Algorithm);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLXPathFilter2Transform_IsTransformAlgorithmSupported_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16Algorithm.data()), (int32_t)u16Algorithm.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLXPATHFILTERITEM
SB_INLINE int32_t TElXMLXPathFilter2Transform::Add(TElXMLXPathFilterItem &AFilter)
{
	int32_t OutResult;
	SBCheckError(TElXMLXPathFilter2Transform_Add(_Handle, AFilter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLXPathFilter2Transform::Add(TElXMLXPathFilterItem *AFilter)
{
	int32_t OutResult;
	SBCheckError(TElXMLXPathFilter2Transform_Add(_Handle, (AFilter != NULL) ? AFilter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLXPATHFILTERITEM */

SB_INLINE void TElXMLXPathFilter2Transform::Delete(int32_t Index)
{
	SBCheckError(TElXMLXPathFilter2Transform_Delete(_Handle, Index));
}

SB_INLINE void TElXMLXPathFilter2Transform::Clear()
{
	SBCheckError(TElXMLXPathFilter2Transform_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLXPathFilter2Transform::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLXPathFilter2Transform_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLXPathFilter2Transform::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLXPathFilter2Transform_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLXPathFilter2Transform::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLXPathFilter2Transform_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLXPathFilter2Transform::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLXPathFilter2Transform_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

TSBTransformedDataType TElXMLXPathFilter2Transform::TransformData(const std::vector<uint8_t> &Data)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLXPathFilter2Transform_TransformData(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TSBTransformedDataType TElXMLXPathFilter2Transform::TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLXPathFilter2Transform_TransformData_1(_Handle, Node.getHandle(), Reference.getHandle(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

TSBTransformedDataType TElXMLXPathFilter2Transform::TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLXPathFilter2Transform_TransformData_1(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, (Reference != NULL) ? Reference->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
TSBTransformedDataType TElXMLXPathFilter2Transform::TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLXPathFilter2Transform_TransformData_2(_Handle, Nodes.getHandle(), SB_STD_VECTOR_FRONT_ADR(Reference), (int32_t)Reference.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

TSBTransformedDataType TElXMLXPathFilter2Transform::TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLXPathFilter2Transform_TransformData_2(_Handle, (Nodes != NULL) ? Nodes->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Reference), (int32_t)Reference.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

SB_INLINE TClassHandle TElXMLXPathFilter2Transform::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLXPathFilter2Transform_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLXPathFilter2Transform::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLXPathFilter2Transform_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLXPATHFILTERITEM
TElXMLXPathFilterItem* TElXMLXPathFilter2Transform::get_Filter(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLXPathFilter2Transform_get_Filter(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Filter)
		this->_Inst_Filter = new TElXMLXPathFilterItem(hOutResult, ohFalse);
	else
		this->_Inst_Filter->updateHandle(hOutResult);
	return this->_Inst_Filter;
}
#endif /* SB_USE_CLASS_TELXMLXPATHFILTERITEM */

void TElXMLXPathFilter2Transform::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLXPATHFILTERITEM
	this->_Inst_Filter = NULL;
#endif /* SB_USE_CLASS_TELXMLXPATHFILTERITEM */
}

TElXMLXPathFilter2Transform::TElXMLXPathFilter2Transform(TElXMLXPathFilter2TransformHandle handle, TElOwnHandle ownHandle) : TElXMLTransform(handle, ownHandle)
{
	initInstances();
}

TElXMLXPathFilter2Transform::TElXMLXPathFilter2Transform() : TElXMLTransform(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLXPathFilter2Transform_Create(&_Handle));
}

TElXMLXPathFilter2Transform::~TElXMLXPathFilter2Transform()
{
#ifdef SB_USE_CLASS_TELXMLXPATHFILTERITEM
	delete this->_Inst_Filter;
	this->_Inst_Filter = NULL;
#endif /* SB_USE_CLASS_TELXMLXPATHFILTERITEM */
}
#endif /* SB_USE_CLASS_TELXMLXPATHFILTER2TRANSFORM */

#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN

void TElXMLTransformChain::TransformData(const std::vector<uint8_t> &Data, TElXMLCanonicalizationMethod CanonicalizationMethod, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLTransformChain_TransformData(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), (TElXMLCanonicalizationMethodRaw)CanonicalizationMethod, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1565441212, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
void TElXMLTransformChain::TransformData(TElXMLDOMNode &Node, TElXMLCanonicalizationMethod CanonicalizationMethod, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLTransformChain_TransformData_1(_Handle, Node.getHandle(), (TElXMLCanonicalizationMethodRaw)CanonicalizationMethod, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1037545286, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLTransformChain::TransformData(TElXMLDOMNode *Node, TElXMLCanonicalizationMethod CanonicalizationMethod, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLTransformChain_TransformData_1(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, (TElXMLCanonicalizationMethodRaw)CanonicalizationMethod, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1037545286, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
void TElXMLTransformChain::TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &ReferenceNode, TElXMLCanonicalizationMethod CanonicalizationMethod, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLTransformChain_TransformData_2(_Handle, Node.getHandle(), ReferenceNode.getHandle(), (TElXMLCanonicalizationMethodRaw)CanonicalizationMethod, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-749036313, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLTransformChain::TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *ReferenceNode, TElXMLCanonicalizationMethod CanonicalizationMethod, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLTransformChain_TransformData_2(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, (ReferenceNode != NULL) ? ReferenceNode->getHandle() : SB_NULL_HANDLE, (TElXMLCanonicalizationMethodRaw)CanonicalizationMethod, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-749036313, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
void TElXMLTransformChain::TransformData(TElXMLDOMNodeList &Nodes, TElXMLCanonicalizationMethod CanonicalizationMethod, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLTransformChain_TransformData_3(_Handle, Nodes.getHandle(), (TElXMLCanonicalizationMethodRaw)CanonicalizationMethod, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1148432593, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLTransformChain::TransformData(TElXMLDOMNodeList *Nodes, TElXMLCanonicalizationMethod CanonicalizationMethod, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLTransformChain_TransformData_3(_Handle, (Nodes != NULL) ? Nodes->getHandle() : SB_NULL_HANDLE, (TElXMLCanonicalizationMethodRaw)CanonicalizationMethod, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1148432593, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
void TElXMLTransformChain::TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &ReferenceNodes, TElXMLCanonicalizationMethod CanonicalizationMethod, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLTransformChain_TransformData_4(_Handle, Nodes.getHandle(), SB_STD_VECTOR_FRONT_ADR(ReferenceNodes), (int32_t)ReferenceNodes.size(), (TElXMLCanonicalizationMethodRaw)CanonicalizationMethod, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1020133852, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLTransformChain::TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &ReferenceNodes, TElXMLCanonicalizationMethod CanonicalizationMethod, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLTransformChain_TransformData_4(_Handle, (Nodes != NULL) ? Nodes->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ReferenceNodes), (int32_t)ReferenceNodes.size(), (TElXMLCanonicalizationMethodRaw)CanonicalizationMethod, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1020133852, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

SB_INLINE TElXMLTransformChainHandle TElXMLTransformChain::CloneTransforms(const sb_u16string &ANamespaceURI)
{
	TElXMLTransformChainHandle OutResult;
	SBCheckError(TElXMLTransformChain_CloneTransforms(_Handle, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLTransformChainHandle TElXMLTransformChain::CloneTransforms(const std::wstring &ANamespaceURI)
{
	TElXMLTransformChainHandle OutResult;
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	SBCheckError(TElXMLTransformChain_CloneTransforms(_Handle, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLTRANSFORM
SB_INLINE int32_t TElXMLTransformChain::Add(TElXMLTransform &Transform)
{
	int32_t OutResult;
	SBCheckError(TElXMLTransformChain_Add(_Handle, Transform.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLTransformChain::Add(TElXMLTransform *Transform)
{
	int32_t OutResult;
	SBCheckError(TElXMLTransformChain_Add(_Handle, (Transform != NULL) ? Transform->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLTRANSFORM */

SB_INLINE int32_t TElXMLTransformChain::AddCanonicalizationTransform(TElXMLCanonicalizationMethod AMethod)
{
	int32_t OutResult;
	SBCheckError(TElXMLTransformChain_AddCanonicalizationTransform(_Handle, (TElXMLCanonicalizationMethodRaw)AMethod, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLTransformChain::AddEnvelopedSignatureTransform()
{
	int32_t OutResult;
	SBCheckError(TElXMLTransformChain_AddEnvelopedSignatureTransform(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLTRANSFORM
SB_INLINE void TElXMLTransformChain::Insert(int32_t Index, TElXMLTransform &Transform)
{
	SBCheckError(TElXMLTransformChain_Insert(_Handle, Index, Transform.getHandle()));
}

SB_INLINE void TElXMLTransformChain::Insert(int32_t Index, TElXMLTransform *Transform)
{
	SBCheckError(TElXMLTransformChain_Insert(_Handle, Index, (Transform != NULL) ? Transform->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLTRANSFORM */

SB_INLINE void TElXMLTransformChain::Delete(int32_t Index)
{
	SBCheckError(TElXMLTransformChain_Delete(_Handle, Index));
}

SB_INLINE void TElXMLTransformChain::Clear()
{
	SBCheckError(TElXMLTransformChain_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLTRANSFORM
SB_INLINE int32_t TElXMLTransformChain::IndexOf(TElXMLTransform &Transform)
{
	int32_t OutResult;
	SBCheckError(TElXMLTransformChain_IndexOf(_Handle, Transform.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLTransformChain::IndexOf(TElXMLTransform *Transform)
{
	int32_t OutResult;
	SBCheckError(TElXMLTransformChain_IndexOf(_Handle, (Transform != NULL) ? Transform->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLTRANSFORM */

bool TElXMLTransformChain::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLTransformChain_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLTransformChain::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLTransformChain_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLTransformChain::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLTransformChain_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLTransformChain::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLTransformChain_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLTransformChain::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLTransformChain_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int32_t TElXMLTransformChain::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLTransformChain_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLTRANSFORM
TElXMLTransform* TElXMLTransformChain::get_Transforms(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLTransformChain_get_Transforms(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Transforms)
		this->_Inst_Transforms = new TElXMLTransform(hOutResult, ohFalse);
	else
		this->_Inst_Transforms->updateHandle(hOutResult);
	return this->_Inst_Transforms;
}
#endif /* SB_USE_CLASS_TELXMLTRANSFORM */

void TElXMLTransformChain::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLTRANSFORM
	this->_Inst_Transforms = NULL;
#endif /* SB_USE_CLASS_TELXMLTRANSFORM */
}

TElXMLTransformChain::TElXMLTransformChain(TElXMLTransformChainHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
	initInstances();
}

TElXMLTransformChain::TElXMLTransformChain(const sb_u16string &ANamespaceURI) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLTransformChain_Create(ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLTransformChain::TElXMLTransformChain(const std::wstring &ANamespaceURI) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	SBCheckError(TElXMLTransformChain_Create(reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLTransformChain::~TElXMLTransformChain()
{
#ifdef SB_USE_CLASS_TELXMLTRANSFORM
	delete this->_Inst_Transforms;
	this->_Inst_Transforms = NULL;
#endif /* SB_USE_CLASS_TELXMLTRANSFORM */
}
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */

#ifdef SB_USE_CLASS_TELXMLUNSUPPORTEDTRANSFORM

void TElXMLUnsupportedTransform::GetDefaultTransformAlgorithmURI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLUnsupportedTransform_GetDefaultTransformAlgorithmURI((sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1070751535, 0, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLUnsupportedTransform::GetDefaultTransformAlgorithmURI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLUnsupportedTransform_GetDefaultTransformAlgorithmURI(NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1070751535, 0, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElXMLUnsupportedTransform::GetDefaultTransformAlgorithmURI_Inst(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLUnsupportedTransform_GetDefaultTransformAlgorithmURI_1(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1070751535, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLUnsupportedTransform::GetDefaultTransformAlgorithmURI_Inst(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLUnsupportedTransform_GetDefaultTransformAlgorithmURI_1(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1070751535, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

bool TElXMLUnsupportedTransform::IsTransformAlgorithmSupported(const sb_u16string &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLUnsupportedTransform_IsTransformAlgorithmSupported(Algorithm.data(), (int32_t)Algorithm.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLUnsupportedTransform::IsTransformAlgorithmSupported(const std::wstring &Algorithm)
{
	std::string u16Algorithm;
	sb_to_u16string(Algorithm, u16Algorithm);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLUnsupportedTransform_IsTransformAlgorithmSupported(reinterpret_cast<const sb_char16_t*>(u16Algorithm.data()), (int32_t)u16Algorithm.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

bool TElXMLUnsupportedTransform::IsTransformAlgorithmSupported_Inst(const sb_u16string &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLUnsupportedTransform_IsTransformAlgorithmSupported_1(_Handle, Algorithm.data(), (int32_t)Algorithm.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLUnsupportedTransform::IsTransformAlgorithmSupported_Inst(const std::wstring &Algorithm)
{
	std::string u16Algorithm;
	sb_to_u16string(Algorithm, u16Algorithm);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLUnsupportedTransform_IsTransformAlgorithmSupported_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16Algorithm.data()), (int32_t)u16Algorithm.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLUnsupportedTransform::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLUnsupportedTransform_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLUnsupportedTransform::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLUnsupportedTransform_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

TSBTransformedDataType TElXMLUnsupportedTransform::TransformData(const std::vector<uint8_t> &Data)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLUnsupportedTransform_TransformData(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TSBTransformedDataType TElXMLUnsupportedTransform::TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLUnsupportedTransform_TransformData_1(_Handle, Node.getHandle(), Reference.getHandle(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

TSBTransformedDataType TElXMLUnsupportedTransform::TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLUnsupportedTransform_TransformData_1(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, (Reference != NULL) ? Reference->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
TSBTransformedDataType TElXMLUnsupportedTransform::TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLUnsupportedTransform_TransformData_2(_Handle, Nodes.getHandle(), SB_STD_VECTOR_FRONT_ADR(Reference), (int32_t)Reference.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

TSBTransformedDataType TElXMLUnsupportedTransform::TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLUnsupportedTransform_TransformData_2(_Handle, (Nodes != NULL) ? Nodes->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Reference), (int32_t)Reference.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

SB_INLINE TClassHandle TElXMLUnsupportedTransform::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLUnsupportedTransform_ClassType(&OutResult));
	return OutResult;
}

TElXMLUnsupportedTransform::TElXMLUnsupportedTransform(TElXMLUnsupportedTransformHandle handle, TElOwnHandle ownHandle) : TElXMLTransform(handle, ownHandle)
{
}

TElXMLUnsupportedTransform::TElXMLUnsupportedTransform() : TElXMLTransform(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLUnsupportedTransform_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLUNSUPPORTEDTRANSFORM */

#ifdef SB_USE_GLOBAL_PROCS_XMLTRANSFORM

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE TElXMLDOMDocumentHandle LoadDocumentFromData(const std::vector<uint8_t> &Data)
{
	TElXMLDOMDocumentHandle OutResult;
	SBCheckError(SBXMLTransform_LoadDocumentFromData(SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
SB_INLINE TElXMLDOMNodeListHandle NodeToNodeList(const TElXMLDOMNode &Node)
{
	TElXMLDOMNodeListHandle OutResult;
	SBCheckError(SBXMLTransform_NodeToNodeList(Node.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMNodeListHandle NodeToNodeList(const TElXMLDOMNode *Node)
{
	TElXMLDOMNodeListHandle OutResult;
	SBCheckError(SBXMLTransform_NodeToNodeList((Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

SB_INLINE void RegisterTransformClass(TElXMLTransformClassHandle TransformClass)
{
	SBCheckError(SBXMLTransform_RegisterTransformClass(TransformClass));
}

SB_INLINE void UnregisterTransformClass(TElXMLTransformClassHandle TransformClass)
{
	SBCheckError(SBXMLTransform_UnregisterTransformClass(TransformClass));
}

SB_INLINE TElXMLTransformClassHandle FindTransformClass(const sb_u16string &Algorithm)
{
	TElXMLTransformClassHandle OutResult;
	SBCheckError(SBXMLTransform_FindTransformClass(Algorithm.data(), (int32_t)Algorithm.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLTransformClassHandle FindTransformClass(const std::wstring &Algorithm)
{
	TElXMLTransformClassHandle OutResult;
	std::string u16Algorithm;
	sb_to_u16string(Algorithm, u16Algorithm);
	SBCheckError(SBXMLTransform_FindTransformClass(reinterpret_cast<const sb_char16_t*>(u16Algorithm.data()), (int32_t)u16Algorithm.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

#endif /* SB_USE_GLOBAL_PROCS_XMLTRANSFORM */

};	/* namespace SecureBlackbox */

