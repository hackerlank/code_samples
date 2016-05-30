#include "sbwebdavcommon.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFO

SB_INLINE TElWebDavPropertyInfoHandle TElWebDavPropertyInfo::Clone()
{
	TElWebDavPropertyInfoHandle OutResult;
	SBCheckError(TElWebDavPropertyInfo_Clone(_Handle, &OutResult));
	return OutResult;
}

bool TElWebDavPropertyInfo::get_Inited()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPropertyInfo_get_Inited(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDavPropertyInfo::set_Inited(bool Value)
{
	SBCheckError(TElWebDavPropertyInfo_set_Inited(_Handle, (int8_t)Value));
}

void TElWebDavPropertyInfo::get_NS(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavPropertyInfo_get_NS(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-165274285, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavPropertyInfo::set_NS(const std::string &Value)
{
	SBCheckError(TElWebDavPropertyInfo_set_NS(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElWebDavPropertyInfo::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavPropertyInfo_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(955524523, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavPropertyInfo::set_Name(const std::string &Value)
{
	SBCheckError(TElWebDavPropertyInfo_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElWebDavPropertyInfo::get_Value(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavPropertyInfo_get_Value(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1735704503, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavPropertyInfo::set_Value(const std::string &Value)
{
	SBCheckError(TElWebDavPropertyInfo_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElWebDavPropertyInfo::get_Status(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavPropertyInfo_get_Status(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-574006292, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavPropertyInfo::set_Status(const std::string &Value)
{
	SBCheckError(TElWebDavPropertyInfo_set_Status(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElWebDavPropertyInfo::get_Hrefs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavPropertyInfo_get_Hrefs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Hrefs)
		this->_Inst_Hrefs = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Hrefs->updateHandle(hOutResult);
	return this->_Inst_Hrefs;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElWebDavPropertyInfo::get_Hrefs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavPropertyInfo_get_Hrefs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Hrefs)
		this->_Inst_Hrefs = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Hrefs->updateHandle(hOutResult);
	return this->_Inst_Hrefs;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElWebDavPropertyInfo::get_Description(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavPropertyInfo_get_Description(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1792680364, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavPropertyInfo::set_Description(const std::string &Value)
{
	SBCheckError(TElWebDavPropertyInfo_set_Description(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElWebDavPropertyInfo::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Hrefs = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Hrefs = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElWebDavPropertyInfo::TElWebDavPropertyInfo(TElWebDavPropertyInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElWebDavPropertyInfo::TElWebDavPropertyInfo(const std::string &NS, const std::string &Name, const std::string &Value) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDavPropertyInfo_Create(NS.data(), (int32_t)NS.length(), Name.data(), (int32_t)Name.length(), Value.data(), (int32_t)Value.length(), &_Handle));
}

TElWebDavPropertyInfo::~TElWebDavPropertyInfo()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Hrefs;
	this->_Inst_Hrefs = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Hrefs;
	this->_Inst_Hrefs = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFO */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST

SB_INLINE void TElWebDavPropertyInfoList::Clear()
{
	SBCheckError(TElWebDavPropertyInfoList_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFO
SB_INLINE void TElWebDavPropertyInfoList::Add(const TElWebDavPropertyInfo &PropInfo)
{
	SBCheckError(TElWebDavPropertyInfoList_Add(_Handle, PropInfo.getHandle()));
}

SB_INLINE void TElWebDavPropertyInfoList::Add(const TElWebDavPropertyInfo *PropInfo)
{
	SBCheckError(TElWebDavPropertyInfoList_Add(_Handle, (PropInfo != NULL) ? PropInfo->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFO */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFO
SB_INLINE void TElWebDavPropertyInfoList::Remove(const TElWebDavPropertyInfo &PropInfo)
{
	SBCheckError(TElWebDavPropertyInfoList_Remove(_Handle, PropInfo.getHandle()));
}

SB_INLINE void TElWebDavPropertyInfoList::Remove(const TElWebDavPropertyInfo *PropInfo)
{
	SBCheckError(TElWebDavPropertyInfoList_Remove(_Handle, (PropInfo != NULL) ? PropInfo->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFO */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFO
SB_INLINE TElWebDavPropertyInfoHandle TElWebDavPropertyInfoList::Find(const std::string &NS, const std::string &Name)
{
	TElWebDavPropertyInfoHandle OutResult;
	SBCheckError(TElWebDavPropertyInfoList_Find(_Handle, NS.data(), (int32_t)NS.length(), Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFO */

SB_INLINE int32_t TElWebDavPropertyInfoList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElWebDavPropertyInfoList_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFO
TElWebDavPropertyInfo* TElWebDavPropertyInfoList::get_Item(int32_t index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavPropertyInfoList_get_Item(_Handle, index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Item)
		this->_Inst_Item = new TElWebDavPropertyInfo(hOutResult, ohFalse);
	else
		this->_Inst_Item->updateHandle(hOutResult);
	return this->_Inst_Item;
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFO */

void TElWebDavPropertyInfoList::initInstances()
{
#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFO
	this->_Inst_Item = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFO */
}

TElWebDavPropertyInfoList::TElWebDavPropertyInfoList(TElWebDavPropertyInfoListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElWebDavPropertyInfoList::TElWebDavPropertyInfoList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDavPropertyInfoList_Create(&_Handle));
}

TElWebDavPropertyInfoList::~TElWebDavPropertyInfoList()
{
#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFO
	delete this->_Inst_Item;
	this->_Inst_Item = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFO */
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

#ifdef SB_USE_CLASS_TELWEBDAVNAMESPACEPREFIXMAP

SB_INLINE void TElWebDavNamespacePrefixMap::Clear()
{
	SBCheckError(TElWebDavNamespacePrefixMap_Clear(_Handle));
}

SB_INLINE void TElWebDavNamespacePrefixMap::AddNS(const std::string &NS)
{
	SBCheckError(TElWebDavNamespacePrefixMap_AddNS(_Handle, NS.data(), (int32_t)NS.length()));
}

SB_INLINE void TElWebDavNamespacePrefixMap::RemoveNS(const std::string &NS)
{
	SBCheckError(TElWebDavNamespacePrefixMap_RemoveNS(_Handle, NS.data(), (int32_t)NS.length()));
}

void TElWebDavNamespacePrefixMap::GetPrefix(const std::string &NS, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavNamespacePrefixMap_GetPrefix(_Handle, NS.data(), (int32_t)NS.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1611641090, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElWebDavNamespacePrefixMap::TElWebDavNamespacePrefixMap(TElWebDavNamespacePrefixMapHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElWebDavNamespacePrefixMap::TElWebDavNamespacePrefixMap(bool WithDAV) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebDavNamespacePrefixMap_Create((int8_t)WithDAV, &_Handle));
}

#endif /* SB_USE_CLASS_TELWEBDAVNAMESPACEPREFIXMAP */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK

void TElWebDAVLock::TimeoutToString(int32_t Timeout, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVLock_TimeoutToString(Timeout, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-540855014, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWebDAVLock::TimeoutToString_Inst(int32_t Timeout, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVLock_TimeoutToString_1(_Handle, Timeout, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-540855014, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElWebDAVLock::StringToTimeout(const std::string &S)
{
	int64_t OutResult;
	SBCheckError(TElWebDAVLock_StringToTimeout(S.data(), (int32_t)S.length(), &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElWebDAVLock::StringToTimeout_Inst(const std::string &S)
{
	int64_t OutResult;
	SBCheckError(TElWebDAVLock_StringToTimeout_1(_Handle, S.data(), (int32_t)S.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
void TElWebDAVLock::ReadTokenFromXML(TStream &Strm, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVLock_ReadTokenFromXML(Strm.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1105751076, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWebDAVLock::ReadTokenFromXML(TStream *Strm, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVLock_ReadTokenFromXML((Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1105751076, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
void TElWebDAVLock::ReadTokenFromXML_Inst(TStream &Strm, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVLock_ReadTokenFromXML_1(_Handle, Strm.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1105751076, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWebDAVLock::ReadTokenFromXML_Inst(TStream *Strm, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVLock_ReadTokenFromXML_1(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1105751076, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElWebDAVLockHandle TElWebDAVLock::LoadFromXML(TElXMLDOMElement &Elem)
{
	TElWebDAVLockHandle OutResult;
	SBCheckError(TElWebDAVLock_LoadFromXML(Elem.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWebDAVLockHandle TElWebDAVLock::LoadFromXML(TElXMLDOMElement *Elem)
{
	TElWebDAVLockHandle OutResult;
	SBCheckError(TElWebDAVLock_LoadFromXML((Elem != NULL) ? Elem->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElWebDAVLockHandle TElWebDAVLock::LoadFromXML_Inst(TElXMLDOMElement &Elem)
{
	TElWebDAVLockHandle OutResult;
	SBCheckError(TElWebDAVLock_LoadFromXML_1(_Handle, Elem.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWebDAVLockHandle TElWebDAVLock::LoadFromXML_Inst(TElXMLDOMElement *Elem)
{
	TElWebDAVLockHandle OutResult;
	SBCheckError(TElWebDAVLock_LoadFromXML_1(_Handle, (Elem != NULL) ? Elem->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE TElWebDAVLockHandle TElWebDAVLock::Clone()
{
	TElWebDAVLockHandle OutResult;
	SBCheckError(TElWebDAVLock_Clone(_Handle, &OutResult));
	return OutResult;
}

void TElWebDAVLock::ToXML(bool WithToken, const std::string &NS, bool EncodeURL, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVLock_ToXML(_Handle, (int8_t)WithToken, NS.data(), (int32_t)NS.length(), (int8_t)EncodeURL, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1710452917, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMNODE
SB_INLINE void TElWebDAVLock::SaveToXML(const TElXMLDOMDocument &Doc, const TElXMLDOMNode &Base, bool WithToken, bool EncodeURL)
{
	SBCheckError(TElWebDAVLock_SaveToXML(_Handle, Doc.getHandle(), Base.getHandle(), (int8_t)WithToken, (int8_t)EncodeURL));
}

SB_INLINE void TElWebDAVLock::SaveToXML(const TElXMLDOMDocument *Doc, const TElXMLDOMNode *Base, bool WithToken, bool EncodeURL)
{
	SBCheckError(TElWebDAVLock_SaveToXML(_Handle, (Doc != NULL) ? Doc->getHandle() : SB_NULL_HANDLE, (Base != NULL) ? Base->getHandle() : SB_NULL_HANDLE, (int8_t)WithToken, (int8_t)EncodeURL));
}
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMNODE */

bool TElWebDAVLock::LocksURL(const std::string &URL)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVLock_LocksURL(_Handle, URL.data(), (int32_t)URL.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVLock::CompatibleWith(const TElWebDAVLock &Lock)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVLock_CompatibleWith(_Handle, Lock.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVLock::CompatibleWith(const TElWebDAVLock *Lock)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVLock_CompatibleWith(_Handle, (Lock != NULL) ? Lock->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVLock::ConflictsWith(const TElWebDAVLock &Lock)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVLock_ConflictsWith(_Handle, Lock.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVLock::ConflictsWith(const TElWebDAVLock *Lock)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVLock_ConflictsWith(_Handle, (Lock != NULL) ? Lock->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDAVLock::Refresh(int64_t Timeout)
{
	SBCheckError(TElWebDAVLock_Refresh(_Handle, Timeout));
}

SB_INLINE void TElWebDAVLock::Unlock()
{
	SBCheckError(TElWebDAVLock_Unlock(_Handle));
}

bool TElWebDAVLock::BeginUse()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVLock_BeginUse(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDAVLock::EndUse()
{
	SBCheckError(TElWebDAVLock_EndUse(_Handle));
}

void TElWebDAVLock::ToString(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVLock_ToString(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-228926565, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWebDAVLock::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVLock_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-85404274, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWebDAVLock::get_Owner(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVLock_get_Owner(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1934468133, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWebDAVLock::get_Token(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVLock_get_Token(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-484777118, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBWebDavLockScope TElWebDAVLock::get_Scope()
{
	TSBWebDavLockScopeRaw OutResultRaw = 0;
	SBCheckError(TElWebDAVLock_get_Scope(_Handle, &OutResultRaw));
	return (TSBWebDavLockScope)OutResultRaw;
}

TSBWebDavDepth TElWebDAVLock::get_Depth()
{
	TSBWebDavDepthRaw OutResultRaw = 0;
	SBCheckError(TElWebDAVLock_get_Depth(_Handle, &OutResultRaw));
	return (TSBWebDavDepth)OutResultRaw;
}

SB_INLINE int64_t TElWebDAVLock::get_TTL()
{
	int64_t OutResult;
	SBCheckError(TElWebDAVLock_get_TTL(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElWebDAVLock::get_Timeout()
{
	int64_t OutResult;
	SBCheckError(TElWebDAVLock_get_Timeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElWebDAVLock::get_UnlockTime()
{
	int64_t OutResult;
	SBCheckError(TElWebDAVLock_get_UnlockTime(_Handle, &OutResult));
	return OutResult;
}

bool TElWebDAVLock::get_Unlocked()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVLock_get_Unlocked(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVLock::get_InUse()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVLock_get_InUse(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElWebDAVLock::get_ToIfHeader(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVLock_get_ToIfHeader(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(595808698, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElWebDAVLock::TElWebDAVLock(TElWebDAVLockHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElWebDAVLock::TElWebDAVLock(const std::string &URL, const std::string &Owner, TSBWebDavLockScope Scope, TSBWebDavDepth Depth, int64_t Timeout, const std::string &Token) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebDAVLock_Create(URL.data(), (int32_t)URL.length(), Owner.data(), (int32_t)Owner.length(), (TSBWebDavLockScopeRaw)Scope, (TSBWebDavDepthRaw)Depth, Timeout, Token.data(), (int32_t)Token.length(), &_Handle));
}

#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TELWEBDAVFILTER

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
bool TElWebDavFilter::LoadFromXML(TElXMLDOMElement &Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavFilter_LoadFromXML(_Handle, Element.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavFilter::LoadFromXML(TElXMLDOMElement *Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavFilter_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElWebDavFilter::SaveToXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElWebDavFilter_SaveToXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElWebDavFilter::SaveToXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElWebDavFilter_SaveToXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

TElWebDavFilter* TElWebDavFilter::get_Parent()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavFilter_get_Parent(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Parent)
		this->_Inst_Parent = new TElWebDavFilter(hOutResult, ohFalse);
	else
		this->_Inst_Parent->updateHandle(hOutResult);
	return this->_Inst_Parent;
}

SB_INLINE void TElWebDavFilter::set_Parent(TElWebDavFilter &Value)
{
	SBCheckError(TElWebDavFilter_set_Parent(_Handle, Value.getHandle()));
}

SB_INLINE void TElWebDavFilter::set_Parent(TElWebDavFilter *Value)
{
	SBCheckError(TElWebDavFilter_set_Parent(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

void TElWebDavFilter::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavFilter_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-362689675, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavFilter::set_Name(const std::string &Value)
{
	SBCheckError(TElWebDavFilter_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElWebDavFilter::get_FullPath(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavFilter_get_FullPath(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-247951074, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElWebDavFilter::get_Empty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavFilter_get_Empty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElWebDavFilter::initInstances()
{
	this->_Inst_Parent = NULL;
}

TElWebDavFilter::TElWebDavFilter(TElWebDavFilterHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElWebDavFilter::TElWebDavFilter(TElWebDavFilter &Parent) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDavFilter_Create(Parent.getHandle(), &_Handle));
}

TElWebDavFilter::TElWebDavFilter(TElWebDavFilter *Parent) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDavFilter_Create((Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElWebDavFilter::~TElWebDavFilter()
{
	delete this->_Inst_Parent;
	this->_Inst_Parent = NULL;
}
#endif /* SB_USE_CLASS_TELWEBDAVFILTER */

#ifdef SB_USE_CLASS_TELWEBDAVTEXTMATCHFILTER

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
bool TElWebDavTextMatchFilter::LoadFromXML(TElXMLDOMElement &Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavTextMatchFilter_LoadFromXML(_Handle, Element.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavTextMatchFilter::LoadFromXML(TElXMLDOMElement *Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavTextMatchFilter_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElWebDavTextMatchFilter::SaveToXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElWebDavTextMatchFilter_SaveToXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElWebDavTextMatchFilter::SaveToXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElWebDavTextMatchFilter_SaveToXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

TSBWebDavFilterTextMatchCollation TElWebDavTextMatchFilter::get_Collation()
{
	TSBWebDavFilterTextMatchCollationRaw OutResultRaw = 0;
	SBCheckError(TElWebDavTextMatchFilter_get_Collation(_Handle, &OutResultRaw));
	return (TSBWebDavFilterTextMatchCollation)OutResultRaw;
}

SB_INLINE void TElWebDavTextMatchFilter::set_Collation(TSBWebDavFilterTextMatchCollation Value)
{
	SBCheckError(TElWebDavTextMatchFilter_set_Collation(_Handle, (TSBWebDavFilterTextMatchCollationRaw)Value));
}

TSBWebDavFilterTextMatchType TElWebDavTextMatchFilter::get_MatchType()
{
	TSBWebDavFilterTextMatchTypeRaw OutResultRaw = 0;
	SBCheckError(TElWebDavTextMatchFilter_get_MatchType(_Handle, &OutResultRaw));
	return (TSBWebDavFilterTextMatchType)OutResultRaw;
}

SB_INLINE void TElWebDavTextMatchFilter::set_MatchType(TSBWebDavFilterTextMatchType Value)
{
	SBCheckError(TElWebDavTextMatchFilter_set_MatchType(_Handle, (TSBWebDavFilterTextMatchTypeRaw)Value));
}

bool TElWebDavTextMatchFilter::get_NegateCondition()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavTextMatchFilter_get_NegateCondition(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDavTextMatchFilter::set_NegateCondition(bool Value)
{
	SBCheckError(TElWebDavTextMatchFilter_set_NegateCondition(_Handle, (int8_t)Value));
}

void TElWebDavTextMatchFilter::get_Value(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavTextMatchFilter_get_Value(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1227106188, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavTextMatchFilter::set_Value(const std::string &Value)
{
	SBCheckError(TElWebDavTextMatchFilter_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

TElWebDavTextMatchFilter::TElWebDavTextMatchFilter(TElWebDavTextMatchFilterHandle handle, TElOwnHandle ownHandle) : TElWebDavFilter(handle, ownHandle)
{
}

TElWebDavTextMatchFilter::TElWebDavTextMatchFilter(TElWebDavFilter &Parent) : TElWebDavFilter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebDavTextMatchFilter_Create(Parent.getHandle(), &_Handle));
}

TElWebDavTextMatchFilter::TElWebDavTextMatchFilter(TElWebDavFilter *Parent) : TElWebDavFilter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebDavTextMatchFilter_Create((Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELWEBDAVTEXTMATCHFILTER */

#ifdef SB_USE_CLASS_TELCARDDAVTEXTMATCHFILTER

TElCardDavTextMatchFilter::TElCardDavTextMatchFilter(TElCardDavTextMatchFilterHandle handle, TElOwnHandle ownHandle) : TElWebDavTextMatchFilter(handle, ownHandle)
{
}

TElCardDavTextMatchFilter::TElCardDavTextMatchFilter(TElWebDavFilter &Parent) : TElWebDavTextMatchFilter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCardDavTextMatchFilter_Create(Parent.getHandle(), &_Handle));
}

TElCardDavTextMatchFilter::TElCardDavTextMatchFilter(TElWebDavFilter *Parent) : TElWebDavTextMatchFilter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCardDavTextMatchFilter_Create((Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELCARDDAVTEXTMATCHFILTER */

#ifdef SB_USE_CLASS_TELCARDDAVPROPFILTER

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
bool TElCardDavPropFilter::LoadFromXML(TElXMLDOMElement &Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCardDavPropFilter_LoadFromXML(_Handle, Element.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCardDavPropFilter::LoadFromXML(TElXMLDOMElement *Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCardDavPropFilter_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElCardDavPropFilter::SaveToXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElCardDavPropFilter_SaveToXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElCardDavPropFilter::SaveToXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElCardDavPropFilter_SaveToXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE int32_t TElCardDavPropFilter::AddSubFilter(TElWebDavFilter &Filter)
{
	int32_t OutResult;
	SBCheckError(TElCardDavPropFilter_AddSubFilter(_Handle, Filter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCardDavPropFilter::AddSubFilter(TElWebDavFilter *Filter)
{
	int32_t OutResult;
	SBCheckError(TElCardDavPropFilter_AddSubFilter(_Handle, (Filter != NULL) ? Filter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

SB_INLINE void TElCardDavPropFilter::RemoveSubFilter(int32_t Index)
{
	SBCheckError(TElCardDavPropFilter_RemoveSubFilter(_Handle, Index));
}

TSBWebDavFilterTest TElCardDavPropFilter::get_Test()
{
	TSBWebDavFilterTestRaw OutResultRaw = 0;
	SBCheckError(TElCardDavPropFilter_get_Test(_Handle, &OutResultRaw));
	return (TSBWebDavFilterTest)OutResultRaw;
}

SB_INLINE void TElCardDavPropFilter::set_Test(TSBWebDavFilterTest Value)
{
	SBCheckError(TElCardDavPropFilter_set_Test(_Handle, (TSBWebDavFilterTestRaw)Value));
}

bool TElCardDavPropFilter::get_IsNotDefined()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCardDavPropFilter_get_IsNotDefined(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCardDavPropFilter::set_IsNotDefined(bool Value)
{
	SBCheckError(TElCardDavPropFilter_set_IsNotDefined(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElCardDavPropFilter::get_SubFilterCount()
{
	int32_t OutResult;
	SBCheckError(TElCardDavPropFilter_get_SubFilterCount(_Handle, &OutResult));
	return OutResult;
}

TElWebDavFilter* TElCardDavPropFilter::get_SubFilters(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCardDavPropFilter_get_SubFilters(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SubFilters)
		this->_Inst_SubFilters = new TElWebDavFilter(hOutResult, ohFalse);
	else
		this->_Inst_SubFilters->updateHandle(hOutResult);
	return this->_Inst_SubFilters;
}

void TElCardDavPropFilter::initInstances()
{
	this->_Inst_SubFilters = NULL;
}

TElCardDavPropFilter::TElCardDavPropFilter(TElCardDavPropFilterHandle handle, TElOwnHandle ownHandle) : TElWebDavFilter(handle, ownHandle)
{
	initInstances();
}

TElCardDavPropFilter::TElCardDavPropFilter(TElWebDavFilter &Parent) : TElWebDavFilter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCardDavPropFilter_Create(Parent.getHandle(), &_Handle));
}

TElCardDavPropFilter::TElCardDavPropFilter(TElWebDavFilter *Parent) : TElWebDavFilter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCardDavPropFilter_Create((Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElCardDavPropFilter::~TElCardDavPropFilter()
{
	delete this->_Inst_SubFilters;
	this->_Inst_SubFilters = NULL;
}
#endif /* SB_USE_CLASS_TELCARDDAVPROPFILTER */

#ifdef SB_USE_CLASS_TELCARDDAVFILTER

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
bool TElCardDavFilter::LoadFromXML(TElXMLDOMElement &Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCardDavFilter_LoadFromXML(_Handle, Element.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCardDavFilter::LoadFromXML(TElXMLDOMElement *Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCardDavFilter_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElCardDavFilter::SaveToXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElCardDavFilter_SaveToXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElCardDavFilter::SaveToXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElCardDavFilter_SaveToXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELCARDDAVPROPFILTER
SB_INLINE int32_t TElCardDavFilter::AddPropFilter(TElCardDavPropFilter &PropFilter)
{
	int32_t OutResult;
	SBCheckError(TElCardDavFilter_AddPropFilter(_Handle, PropFilter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCardDavFilter::AddPropFilter(TElCardDavPropFilter *PropFilter)
{
	int32_t OutResult;
	SBCheckError(TElCardDavFilter_AddPropFilter(_Handle, (PropFilter != NULL) ? PropFilter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCARDDAVPROPFILTER */

SB_INLINE void TElCardDavFilter::RemovePropFilter(int32_t Index)
{
	SBCheckError(TElCardDavFilter_RemovePropFilter(_Handle, Index));
}

TSBWebDavFilterTest TElCardDavFilter::get_Test()
{
	TSBWebDavFilterTestRaw OutResultRaw = 0;
	SBCheckError(TElCardDavFilter_get_Test(_Handle, &OutResultRaw));
	return (TSBWebDavFilterTest)OutResultRaw;
}

SB_INLINE void TElCardDavFilter::set_Test(TSBWebDavFilterTest Value)
{
	SBCheckError(TElCardDavFilter_set_Test(_Handle, (TSBWebDavFilterTestRaw)Value));
}

SB_INLINE int32_t TElCardDavFilter::get_PropFilterCount()
{
	int32_t OutResult;
	SBCheckError(TElCardDavFilter_get_PropFilterCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCARDDAVPROPFILTER
TElCardDavPropFilter* TElCardDavFilter::get_PropFilters(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCardDavFilter_get_PropFilters(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PropFilters)
		this->_Inst_PropFilters = new TElCardDavPropFilter(hOutResult, ohFalse);
	else
		this->_Inst_PropFilters->updateHandle(hOutResult);
	return this->_Inst_PropFilters;
}
#endif /* SB_USE_CLASS_TELCARDDAVPROPFILTER */

void TElCardDavFilter::initInstances()
{
#ifdef SB_USE_CLASS_TELCARDDAVPROPFILTER
	this->_Inst_PropFilters = NULL;
#endif /* SB_USE_CLASS_TELCARDDAVPROPFILTER */
}

TElCardDavFilter::TElCardDavFilter(TElCardDavFilterHandle handle, TElOwnHandle ownHandle) : TElWebDavFilter(handle, ownHandle)
{
	initInstances();
}

TElCardDavFilter::TElCardDavFilter() : TElWebDavFilter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCardDavFilter_Create(&_Handle));
}

TElCardDavFilter::~TElCardDavFilter()
{
#ifdef SB_USE_CLASS_TELCARDDAVPROPFILTER
	delete this->_Inst_PropFilters;
	this->_Inst_PropFilters = NULL;
#endif /* SB_USE_CLASS_TELCARDDAVPROPFILTER */
}
#endif /* SB_USE_CLASS_TELCARDDAVFILTER */

#ifdef SB_USE_CLASS_TELCARDDAVPARAMFILTER

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
bool TElCardDavParamFilter::LoadFromXML(TElXMLDOMElement &Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCardDavParamFilter_LoadFromXML(_Handle, Element.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCardDavParamFilter::LoadFromXML(TElXMLDOMElement *Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCardDavParamFilter_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElCardDavParamFilter::SaveToXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElCardDavParamFilter_SaveToXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElCardDavParamFilter::SaveToXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElCardDavParamFilter_SaveToXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELCARDDAVTEXTMATCHFILTER
TElCardDavTextMatchFilter* TElCardDavParamFilter::get_TextMatch()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCardDavParamFilter_get_TextMatch(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TextMatch)
		this->_Inst_TextMatch = new TElCardDavTextMatchFilter(hOutResult, ohFalse);
	else
		this->_Inst_TextMatch->updateHandle(hOutResult);
	return this->_Inst_TextMatch;
}

SB_INLINE void TElCardDavParamFilter::set_TextMatch(TElCardDavTextMatchFilter &Value)
{
	SBCheckError(TElCardDavParamFilter_set_TextMatch(_Handle, Value.getHandle()));
}

SB_INLINE void TElCardDavParamFilter::set_TextMatch(TElCardDavTextMatchFilter *Value)
{
	SBCheckError(TElCardDavParamFilter_set_TextMatch(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCARDDAVTEXTMATCHFILTER */

bool TElCardDavParamFilter::get_OwnTextMatch()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCardDavParamFilter_get_OwnTextMatch(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCardDavParamFilter::set_OwnTextMatch(bool Value)
{
	SBCheckError(TElCardDavParamFilter_set_OwnTextMatch(_Handle, (int8_t)Value));
}

bool TElCardDavParamFilter::get_IsNotDefined()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCardDavParamFilter_get_IsNotDefined(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCardDavParamFilter::set_IsNotDefined(bool Value)
{
	SBCheckError(TElCardDavParamFilter_set_IsNotDefined(_Handle, (int8_t)Value));
}

void TElCardDavParamFilter::initInstances()
{
#ifdef SB_USE_CLASS_TELCARDDAVTEXTMATCHFILTER
	this->_Inst_TextMatch = NULL;
#endif /* SB_USE_CLASS_TELCARDDAVTEXTMATCHFILTER */
}

TElCardDavParamFilter::TElCardDavParamFilter(TElCardDavParamFilterHandle handle, TElOwnHandle ownHandle) : TElWebDavFilter(handle, ownHandle)
{
	initInstances();
}

TElCardDavParamFilter::TElCardDavParamFilter(TElWebDavFilter &Parent) : TElWebDavFilter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCardDavParamFilter_Create(Parent.getHandle(), &_Handle));
}

TElCardDavParamFilter::TElCardDavParamFilter(TElWebDavFilter *Parent) : TElWebDavFilter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCardDavParamFilter_Create((Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElCardDavParamFilter::~TElCardDavParamFilter()
{
#ifdef SB_USE_CLASS_TELCARDDAVTEXTMATCHFILTER
	delete this->_Inst_TextMatch;
	this->_Inst_TextMatch = NULL;
#endif /* SB_USE_CLASS_TELCARDDAVTEXTMATCHFILTER */
}
#endif /* SB_USE_CLASS_TELCARDDAVPARAMFILTER */

#ifdef SB_USE_CLASS_TELWEBDAVACE

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElWebDavACE::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElWebDavACE_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElWebDavACE::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElWebDavACE_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElWebDavACE::SaveToXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElWebDavACE_SaveToXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElWebDavACE::SaveToXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElWebDavACE_SaveToXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

TSBPrincipalType TElWebDavACE::get_PrincipalType()
{
	TSBPrincipalTypeRaw OutResultRaw = 0;
	SBCheckError(TElWebDavACE_get_PrincipalType(_Handle, &OutResultRaw));
	return (TSBPrincipalType)OutResultRaw;
}

SB_INLINE void TElWebDavACE::set_PrincipalType(TSBPrincipalType Value)
{
	SBCheckError(TElWebDavACE_set_PrincipalType(_Handle, (TSBPrincipalTypeRaw)Value));
}

void TElWebDavACE::get_Value(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavACE_get_Value(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-254774755, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavACE::set_Value(const std::string &Value)
{
	SBCheckError(TElWebDavACE_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFO
TElWebDavPropertyInfo* TElWebDavACE::get__Property()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavACE_get__Property(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst__Property)
		this->_Inst__Property = new TElWebDavPropertyInfo(hOutResult, ohFalse);
	else
		this->_Inst__Property->updateHandle(hOutResult);
	return this->_Inst__Property;
}

SB_INLINE void TElWebDavACE::set__Property(TElWebDavPropertyInfo &Value)
{
	SBCheckError(TElWebDavACE_set__Property(_Handle, Value.getHandle()));
}

SB_INLINE void TElWebDavACE::set__Property(TElWebDavPropertyInfo *Value)
{
	SBCheckError(TElWebDavACE_set__Property(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFO */

bool TElWebDavACE::get_Invert()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavACE_get_Invert(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDavACE::set_Invert(bool Value)
{
	SBCheckError(TElWebDavACE_set_Invert(_Handle, (int8_t)Value));
}

bool TElWebDavACE::get__Protected()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavACE_get__Protected(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDavACE::set__Protected(bool Value)
{
	SBCheckError(TElWebDavACE_set__Protected(_Handle, (int8_t)Value));
}

bool TElWebDavACE::get__Inherited()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavACE_get__Inherited(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDavACE::set__Inherited(bool Value)
{
	SBCheckError(TElWebDavACE_set__Inherited(_Handle, (int8_t)Value));
}

void TElWebDavACE::get_InheritedHref(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavACE_get_InheritedHref(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(787484521, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavACE::set_InheritedHref(const std::string &Value)
{
	SBCheckError(TElWebDavACE_set_InheritedHref(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int16_t TElWebDavACE::get_Grant()
{
	int16_t OutResult;
	SBCheckError(TElWebDavACE_get_Grant(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElWebDavACE::set_Grant(int16_t Value)
{
	SBCheckError(TElWebDavACE_set_Grant(_Handle, Value));
}

SB_INLINE int16_t TElWebDavACE::get_Deny()
{
	int16_t OutResult;
	SBCheckError(TElWebDavACE_get_Deny(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElWebDavACE::set_Deny(int16_t Value)
{
	SBCheckError(TElWebDavACE_set_Deny(_Handle, Value));
}

void TElWebDavACE::initInstances()
{
#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFO
	this->_Inst__Property = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFO */
}

TElWebDavACE::TElWebDavACE(TElWebDavACEHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElWebDavACE::TElWebDavACE() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDavACE_Create(&_Handle));
}

TElWebDavACE::~TElWebDavACE()
{
#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFO
	delete this->_Inst__Property;
	this->_Inst__Property = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFO */
}
#endif /* SB_USE_CLASS_TELWEBDAVACE */

#ifdef SB_USE_CLASS_TELWEBDAVACL

#ifdef SB_USE_CLASS_TELWEBDAVACE
SB_INLINE int32_t TElWebDavACL::Add(TElWebDavACE &Ace)
{
	int32_t OutResult;
	SBCheckError(TElWebDavACL_Add(_Handle, Ace.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElWebDavACL::Add(TElWebDavACE *Ace)
{
	int32_t OutResult;
	SBCheckError(TElWebDavACL_Add(_Handle, (Ace != NULL) ? Ace->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWEBDAVACE */

SB_INLINE void TElWebDavACL::Remove(int32_t Index)
{
	SBCheckError(TElWebDavACL_Remove(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElWebDavACL::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElWebDavACL_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElWebDavACL::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElWebDavACL_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElWebDavACL::SaveToXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElWebDavACL_SaveToXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElWebDavACL::SaveToXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElWebDavACL_SaveToXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE int32_t TElWebDavACL::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElWebDavACL_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELWEBDAVACE
TElWebDavACE* TElWebDavACL::get_ACEs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavACL_get_ACEs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ACEs)
		this->_Inst_ACEs = new TElWebDavACE(hOutResult, ohFalse);
	else
		this->_Inst_ACEs->updateHandle(hOutResult);
	return this->_Inst_ACEs;
}
#endif /* SB_USE_CLASS_TELWEBDAVACE */

void TElWebDavACL::initInstances()
{
#ifdef SB_USE_CLASS_TELWEBDAVACE
	this->_Inst_ACEs = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVACE */
}

TElWebDavACL::TElWebDavACL(TElWebDavACLHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElWebDavACL::TElWebDavACL() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDavACL_Create(&_Handle));
}

TElWebDavACL::~TElWebDavACL()
{
#ifdef SB_USE_CLASS_TELWEBDAVACE
	delete this->_Inst_ACEs;
	this->_Inst_ACEs = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVACE */
}
#endif /* SB_USE_CLASS_TELWEBDAVACL */

#ifdef SB_USE_CLASS_TELWEBDAVACLRESTRICTIONS

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElWebDavACLRestrictions::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElWebDavACLRestrictions_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElWebDavACLRestrictions::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElWebDavACLRestrictions_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElWebDavACLRestrictions::SaveToXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElWebDavACLRestrictions_SaveToXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElWebDavACLRestrictions::SaveToXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElWebDavACLRestrictions_SaveToXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

bool TElWebDavACLRestrictions::get_GrantOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavACLRestrictions_get_GrantOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDavACLRestrictions::set_GrantOnly(bool Value)
{
	SBCheckError(TElWebDavACLRestrictions_set_GrantOnly(_Handle, (int8_t)Value));
}

bool TElWebDavACLRestrictions::get_NoInvert()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavACLRestrictions_get_NoInvert(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDavACLRestrictions::set_NoInvert(bool Value)
{
	SBCheckError(TElWebDavACLRestrictions_set_NoInvert(_Handle, (int8_t)Value));
}

bool TElWebDavACLRestrictions::get_DenyBeforeGrant()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavACLRestrictions_get_DenyBeforeGrant(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDavACLRestrictions::set_DenyBeforeGrant(bool Value)
{
	SBCheckError(TElWebDavACLRestrictions_set_DenyBeforeGrant(_Handle, (int8_t)Value));
}

TSBPrincipalType TElWebDavACLRestrictions::get_RequiredPrincipal()
{
	TSBPrincipalTypeRaw OutResultRaw = 0;
	SBCheckError(TElWebDavACLRestrictions_get_RequiredPrincipal(_Handle, &OutResultRaw));
	return (TSBPrincipalType)OutResultRaw;
}

SB_INLINE void TElWebDavACLRestrictions::set_RequiredPrincipal(TSBPrincipalType Value)
{
	SBCheckError(TElWebDavACLRestrictions_set_RequiredPrincipal(_Handle, (TSBPrincipalTypeRaw)Value));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElWebDavACLRestrictions::get_Hrefs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavACLRestrictions_get_Hrefs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Hrefs)
		this->_Inst_Hrefs = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Hrefs->updateHandle(hOutResult);
	return this->_Inst_Hrefs;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElWebDavACLRestrictions::get_Hrefs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavACLRestrictions_get_Hrefs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Hrefs)
		this->_Inst_Hrefs = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Hrefs->updateHandle(hOutResult);
	return this->_Inst_Hrefs;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
TElWebDavPropertyInfoList* TElWebDavACLRestrictions::get_Properties()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavACLRestrictions_get_Properties(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Properties)
		this->_Inst_Properties = new TElWebDavPropertyInfoList(hOutResult, ohFalse);
	else
		this->_Inst_Properties->updateHandle(hOutResult);
	return this->_Inst_Properties;
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

void TElWebDavACLRestrictions::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Hrefs = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Hrefs = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
	this->_Inst_Properties = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */
}

TElWebDavACLRestrictions::TElWebDavACLRestrictions(TElWebDavACLRestrictionsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElWebDavACLRestrictions::TElWebDavACLRestrictions() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDavACLRestrictions_Create(&_Handle));
}

TElWebDavACLRestrictions::~TElWebDavACLRestrictions()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Hrefs;
	this->_Inst_Hrefs = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Hrefs;
	this->_Inst_Hrefs = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
	delete this->_Inst_Properties;
	this->_Inst_Properties = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */
}
#endif /* SB_USE_CLASS_TELWEBDAVACLRESTRICTIONS */

#ifdef SB_USE_GLOBAL_PROCS_WEBDAVCOMMON

SB_INLINE int64_t ISOTimeToDateTime(const std::string &s)
{
	int64_t OutResult;
	SBCheckError(SBWebDAVCommon_ISOTimeToDateTime(s.data(), (int32_t)s.length(), &OutResult));
	return OutResult;
}

void DateTimeToISOTime(int64_t DT, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVCommon_DateTimeToISOTime(DT, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1972357133, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void DepthToStr(TSBWebDavDepth Depth, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVCommon_DepthToStr((TSBWebDavDepthRaw)Depth, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1324629652, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBWebDavDepth StrToDepth(const std::string &Depth)
{
	TSBWebDavDepthRaw OutResultRaw = 0;
	SBCheckError(SBWebDAVCommon_StrToDepth(Depth.data(), (int32_t)Depth.length(), &OutResultRaw));
	return (TSBWebDavDepth)OutResultRaw;
}

void ScopeToStr(TSBWebDavLockScope Scope, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVCommon_ScopeToStr((TSBWebDavLockScopeRaw)Scope, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-183590963, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBWebDavLockScope StrToScope(const std::string &Scope)
{
	TSBWebDavLockScopeRaw OutResultRaw = 0;
	SBCheckError(SBWebDAVCommon_StrToScope(Scope.data(), (int32_t)Scope.length(), &OutResultRaw));
	return (TSBWebDavLockScope)OutResultRaw;
}

void Substring(const std::string &S, int32_t StartIndex, int32_t EndIndex, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVCommon_Substring(S.data(), (int32_t)S.length(), StartIndex, EndIndex, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(870696421, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool URLComparePaths(const std::string &URL1, const std::string &URL2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBWebDAVCommon_URLComparePaths(URL1.data(), (int32_t)URL1.length(), URL2.data(), (int32_t)URL2.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool URLChild(const std::string &URL, const std::string &SubURL)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBWebDAVCommon_URLChild(URL.data(), (int32_t)URL.length(), SubURL.data(), (int32_t)SubURL.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void URLExtractParent(const std::string &s, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVCommon_URLExtractParent(s.data(), (int32_t)s.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1955162791, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void URLExtractExtension(const std::string &s, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVCommon_URLExtractExtension(s.data(), (int32_t)s.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1837656028, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void URLExtractResourceName(const std::string &s, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVCommon_URLExtractResourceName(s.data(), (int32_t)s.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(860537251, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool CollectionURL(const std::string &URL)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBWebDAVCommon_CollectionURL(URL.data(), (int32_t)URL.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void URLExtractPath(const std::string &URL, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVCommon_URLExtractPath(URL.data(), (int32_t)URL.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1465855631, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void URLCalculateDestPath(const std::string &SrcURL, const std::string &DestURL, const std::string &URL, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVCommon_URLCalculateDestPath(SrcURL.data(), (int32_t)SrcURL.length(), DestURL.data(), (int32_t)DestURL.length(), URL.data(), (int32_t)URL.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-213373757, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void URLAddPrefixSlash(const std::string &URL, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVCommon_URLAddPrefixSlash(URL.data(), (int32_t)URL.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1651043265, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void URLAddPostfixSlash(const std::string &URL, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVCommon_URLAddPostfixSlash(URL.data(), (int32_t)URL.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-378118136, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void URLRemoveSlash(const std::string &URL, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVCommon_URLRemoveSlash(URL.data(), (int32_t)URL.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(377948605, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void URLFixSlashes(const std::string &URL, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVCommon_URLFixSlashes(URL.data(), (int32_t)URL.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-5857074, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void URLEncodeEx(const std::string &Data, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVCommon_URLEncodeEx(Data.data(), (int32_t)Data.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-32058242, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void URLConcat(const std::string &URL, const std::string &Path, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVCommon_URLConcat(URL.data(), (int32_t)URL.length(), Path.data(), (int32_t)Path.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2033297035, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool CheckStatusCode(const std::string &S)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBWebDAVCommon_CheckStatusCode(S.data(), (int32_t)S.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLDOMNODE
SB_INLINE TElXMLDOMElementHandle SingleChildElement(TElXMLDOMNode &Elem)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBWebDAVCommon_SingleChildElement(Elem.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMElementHandle SingleChildElement(TElXMLDOMNode *Elem)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBWebDAVCommon_SingleChildElement((Elem != NULL) ? Elem->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLDOMNODE */

SB_INLINE int64_t MaxDateTime()
{
	int64_t OutResult;
	SBCheckError(SBWebDAVCommon_MaxDateTime(&OutResult));
	return OutResult;
}

void GenerateRandomStr(int32_t Len, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVCommon_GenerateRandomStr(Len, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1847528668, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int16_t StrToPrivilege(const std::string &S)
{
	int16_t OutResult;
	SBCheckError(SBWebDAVCommon_StrToPrivilege(S.data(), (int32_t)S.length(), &OutResult));
	return OutResult;
}

void PrivilegeToStr(int16_t Privilege, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVCommon_PrivilegeToStr(Privilege, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(962031272, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void PrivilegesArray(int16_t Privileges, bool IncludeAll, bool IncludeRead, bool IncludeWrite, std::vector<int16_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size() * 2;
	uint32_t _err = SBWebDAVCommon_PrivilegesArray(Privileges, (int8_t)IncludeAll, (int8_t)IncludeRead, (int8_t)IncludeWrite, (int16_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult / 2);
		SBCheckError(SBGetLastReturnBuffer(-2099512853, 4, (int16_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult / 2);
}

#endif /* SB_USE_GLOBAL_PROCS_WEBDAVCOMMON */

};	/* namespace SecureBlackbox */
