#include "sbdcenc.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELDCENCODING

#ifdef SB_USE_CLASSES_TELDCNODE_AND_TSTREAM
SB_INLINE void TElDCEncoding::Encode(TElDCNode &Root, TStream &Stream)
{
	SBCheckError(TElDCEncoding_Encode(_Handle, Root.getHandle(), Stream.getHandle()));
}

SB_INLINE void TElDCEncoding::Encode(TElDCNode *Root, TStream *Stream)
{
	SBCheckError(TElDCEncoding_Encode(_Handle, (Root != NULL) ? Root->getHandle() : SB_NULL_HANDLE, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDCNODE_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELDCNODE_AND_TSTREAM
SB_INLINE void TElDCEncoding::Decode(TElDCNode &Root, TStream &Stream, int32_t Count)
{
	SBCheckError(TElDCEncoding_Decode(_Handle, Root.getHandle(), Stream.getHandle(), Count));
}

SB_INLINE void TElDCEncoding::Decode(TElDCNode *Root, TStream *Stream, int32_t Count)
{
	SBCheckError(TElDCEncoding_Decode(_Handle, (Root != NULL) ? Root->getHandle() : SB_NULL_HANDLE, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASSES_TELDCNODE_AND_TSTREAM */

void TElDCEncoding::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDCEncoding_GetName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1811729735, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDCEncoding::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDCEncoding_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(966803341, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElDCEncoding::TElDCEncoding(TElDCEncodingHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElDCEncoding::TElDCEncoding() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDCEncoding_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDCENCODING */

#ifdef SB_USE_CLASS_TELDCNODE

SB_INLINE int32_t TElDCNode::AddNode()
{
	int32_t OutResult;
	SBCheckError(TElDCNode_AddNode(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDCNode::AddNode(const std::string &Name, const std::string &Value)
{
	int32_t OutResult;
	SBCheckError(TElDCNode_AddNode_1(_Handle, Name.data(), (int32_t)Name.length(), Value.data(), (int32_t)Value.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDCNode::AddNode(const std::string &Name, int32_t Value)
{
	int32_t OutResult;
	SBCheckError(TElDCNode_AddNode_2(_Handle, Name.data(), (int32_t)Name.length(), Value, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDCNode::AddNode(const std::string &Name, bool Value)
{
	int32_t OutResult;
	SBCheckError(TElDCNode_AddNode_3(_Handle, Name.data(), (int32_t)Name.length(), (int8_t)Value, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE int32_t TElDCNode::AddNode(const std::string &Name, TElRelativeDistinguishedName &Value, const std::string &ElemName)
{
	int32_t OutResult;
	SBCheckError(TElDCNode_AddNode_4(_Handle, Name.data(), (int32_t)Name.length(), Value.getHandle(), ElemName.data(), (int32_t)ElemName.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDCNode::AddNode(const std::string &Name, TElRelativeDistinguishedName *Value, const std::string &ElemName)
{
	int32_t OutResult;
	SBCheckError(TElDCNode_AddNode_4(_Handle, Name.data(), (int32_t)Name.length(), (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE, ElemName.data(), (int32_t)ElemName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE int32_t TElDCNode::AddNode(const std::string &Name, TStringList &Value, const std::string &ElemName)
{
	int32_t OutResult;
	SBCheckError(TElDCNode_AddNode_5(_Handle, Name.data(), (int32_t)Name.length(), Value.getHandle(), ElemName.data(), (int32_t)ElemName.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDCNode::AddNode(const std::string &Name, TStringList *Value, const std::string &ElemName)
{
	int32_t OutResult;
	SBCheckError(TElDCNode_AddNode_5(_Handle, Name.data(), (int32_t)Name.length(), (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE, ElemName.data(), (int32_t)ElemName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE int32_t TElDCNode::AddNode(const std::string &Name, TElStringList &Value, const std::string &ElemName)
{
	int32_t OutResult;
	SBCheckError(TElDCNode_AddNode_5(_Handle, Name.data(), (int32_t)Name.length(), Value.getHandle(), ElemName.data(), (int32_t)ElemName.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDCNode::AddNode(const std::string &Name, TElStringList *Value, const std::string &ElemName)
{
	int32_t OutResult;
	SBCheckError(TElDCNode_AddNode_5(_Handle, Name.data(), (int32_t)Name.length(), (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE, ElemName.data(), (int32_t)ElemName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

SB_INLINE void TElDCNode::RemoveNode(int32_t Index)
{
	SBCheckError(TElDCNode_RemoveNode(_Handle, Index));
}

SB_INLINE void TElDCNode::Clear()
{
	SBCheckError(TElDCNode_Clear(_Handle));
}

void TElDCNode::ReadString(const std::string &Name, const std::string &Default, bool RaiseExceptionIfNotFound, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDCNode_ReadString(_Handle, Name.data(), (int32_t)Name.length(), Default.data(), (int32_t)Default.length(), (int8_t)RaiseExceptionIfNotFound, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1344574873, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElDCNode::ReadInteger(const std::string &Name, int32_t Default, bool RaiseExceptionIfNotFound)
{
	int32_t OutResult;
	SBCheckError(TElDCNode_ReadInteger(_Handle, Name.data(), (int32_t)Name.length(), Default, (int8_t)RaiseExceptionIfNotFound, &OutResult));
	return OutResult;
}

bool TElDCNode::ReadBoolean(const std::string &Name, bool Default, bool RaiseExceptionIfNotFound)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDCNode_ReadBoolean(_Handle, Name.data(), (int32_t)Name.length(), (int8_t)Default, (int8_t)RaiseExceptionIfNotFound, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElDCNode::ReadRDN(const std::string &Name, TElRelativeDistinguishedName &Rdn, bool RaiseExceptionIfNotFound)
{
	SBCheckError(TElDCNode_ReadRDN(_Handle, Name.data(), (int32_t)Name.length(), Rdn.getHandle(), (int8_t)RaiseExceptionIfNotFound));
}

SB_INLINE void TElDCNode::ReadRDN(const std::string &Name, TElRelativeDistinguishedName *Rdn, bool RaiseExceptionIfNotFound)
{
	SBCheckError(TElDCNode_ReadRDN(_Handle, Name.data(), (int32_t)Name.length(), (Rdn != NULL) ? Rdn->getHandle() : SB_NULL_HANDLE, (int8_t)RaiseExceptionIfNotFound));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElDCNode::ReadStringList(const std::string &Name, TStringList &Lst, bool RaiseExceptionIfNotFound)
{
	SBCheckError(TElDCNode_ReadStringList(_Handle, Name.data(), (int32_t)Name.length(), Lst.getHandle(), (int8_t)RaiseExceptionIfNotFound));
}

SB_INLINE void TElDCNode::ReadStringList(const std::string &Name, TStringList *Lst, bool RaiseExceptionIfNotFound)
{
	SBCheckError(TElDCNode_ReadStringList(_Handle, Name.data(), (int32_t)Name.length(), (Lst != NULL) ? Lst->getHandle() : SB_NULL_HANDLE, (int8_t)RaiseExceptionIfNotFound));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElDCNode::ReadStringList(const std::string &Name, TElStringList &Lst, bool RaiseExceptionIfNotFound)
{
	SBCheckError(TElDCNode_ReadStringList(_Handle, Name.data(), (int32_t)Name.length(), Lst.getHandle(), (int8_t)RaiseExceptionIfNotFound));
}

SB_INLINE void TElDCNode::ReadStringList(const std::string &Name, TElStringList *Lst, bool RaiseExceptionIfNotFound)
{
	SBCheckError(TElDCNode_ReadStringList(_Handle, Name.data(), (int32_t)Name.length(), (Lst != NULL) ? Lst->getHandle() : SB_NULL_HANDLE, (int8_t)RaiseExceptionIfNotFound));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM
SB_INLINE void TElDCNode::LoadFromStream(TStream &Stream, int32_t Count, TElDCEncoding &Encoding)
{
	SBCheckError(TElDCNode_LoadFromStream(_Handle, Stream.getHandle(), Count, Encoding.getHandle()));
}

SB_INLINE void TElDCNode::LoadFromStream(TStream *Stream, int32_t Count, TElDCEncoding *Encoding)
{
	SBCheckError(TElDCNode_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count, (Encoding != NULL) ? Encoding->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM
SB_INLINE void TElDCNode::SaveToStream(TStream &Stream, TElDCEncoding &Encoding)
{
	SBCheckError(TElDCNode_SaveToStream(_Handle, Stream.getHandle(), Encoding.getHandle()));
}

SB_INLINE void TElDCNode::SaveToStream(TStream *Stream, TElDCEncoding *Encoding)
{
	SBCheckError(TElDCNode_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (Encoding != NULL) ? Encoding->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM */

TElDCNode* TElDCNode::get_Nodes(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDCNode_get_Nodes(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Nodes)
		this->_Inst_Nodes = new TElDCNode(hOutResult, ohFalse);
	else
		this->_Inst_Nodes->updateHandle(hOutResult);
	return this->_Inst_Nodes;
}

SB_INLINE int32_t TElDCNode::get_NodeCount()
{
	int32_t OutResult;
	SBCheckError(TElDCNode_get_NodeCount(_Handle, &OutResult));
	return OutResult;
}

void TElDCNode::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDCNode_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(723413890, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDCNode::set_Name(const std::string &Value)
{
	SBCheckError(TElDCNode_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDCNode::get_Value(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDCNode_get_Value(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(634768789, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDCNode::set_Value(const std::string &Value)
{
	SBCheckError(TElDCNode_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElDCNode::get_Params()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDCNode_get_Params(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Params)
		this->_Inst_Params = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Params->updateHandle(hOutResult);
	return this->_Inst_Params;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElDCNode::get_Params()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDCNode_get_Params(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Params)
		this->_Inst_Params = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Params->updateHandle(hOutResult);
	return this->_Inst_Params;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElDCNode::initInstances()
{
	this->_Inst_Nodes = NULL;
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Params = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Params = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElDCNode::TElDCNode(TElDCNodeHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElDCNode::TElDCNode() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDCNode_Create(&_Handle));
}

TElDCNode::~TElDCNode()
{
	delete this->_Inst_Nodes;
	this->_Inst_Nodes = NULL;
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Params;
	this->_Inst_Params = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Params;
	this->_Inst_Params = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELDCNODE */

#ifdef SB_USE_GLOBAL_PROCS_DCENC

#ifdef SB_USE_CLASS_TELDCENCODING
SB_INLINE void SetDefaultDCEncoding(TElDCEncoding &Value)
{
	SBCheckError(SBDCEnc_SetDefaultDCEncoding(Value.getHandle()));
}
SB_INLINE void SetDefaultDCEncoding(TElDCEncoding *Value)
{
	SBCheckError(SBDCEnc_SetDefaultDCEncoding((Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDCENCODING */

#ifdef SB_USE_CLASS_TELDCENCODING
SB_INLINE TElDCEncodingHandle GetDefaultDCEncoding()
{
	TElDCEncodingHandle OutResult;
	SBCheckError(SBDCEnc_GetDefaultDCEncoding(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDCENCODING */

#endif /* SB_USE_GLOBAL_PROCS_DCENC */

};	/* namespace SecureBlackbox */
