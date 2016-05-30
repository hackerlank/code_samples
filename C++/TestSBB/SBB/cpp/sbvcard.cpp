#include "sbvcard.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELDIRINFOATTRIBUTE

void TElDirInfoAttribute::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDirInfoAttribute_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(474207099, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDirInfoAttribute::set_Name(const std::string &Value)
{
	SBCheckError(TElDirInfoAttribute_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDirInfoAttribute::get_Value(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDirInfoAttribute_get_Value(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-511452523, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDirInfoAttribute::set_Value(const std::string &Value)
{
	SBCheckError(TElDirInfoAttribute_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

TElDirInfoAttribute::TElDirInfoAttribute(TElDirInfoAttributeHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElDirInfoAttribute::TElDirInfoAttribute() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDirInfoAttribute_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDIRINFOATTRIBUTE */

#ifdef SB_USE_CLASS_TELDIRINFOPROPERTY

#ifdef SB_USE_CLASS_TELDIRINFOATTRIBUTE
SB_INLINE void TElDirInfoProperty::AddAttribute(TElDirInfoAttribute &Attr)
{
	SBCheckError(TElDirInfoProperty_AddAttribute(_Handle, Attr.getHandle()));
}

SB_INLINE void TElDirInfoProperty::AddAttribute(TElDirInfoAttribute *Attr)
{
	SBCheckError(TElDirInfoProperty_AddAttribute(_Handle, (Attr != NULL) ? Attr->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDIRINFOATTRIBUTE */

SB_INLINE void TElDirInfoProperty::RemoveAttribute(int32_t Index)
{
	SBCheckError(TElDirInfoProperty_RemoveAttribute(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELDIRINFOATTRIBUTE
SB_INLINE TElDirInfoAttributeHandle TElDirInfoProperty::AttributeByName(const std::string &Name)
{
	TElDirInfoAttributeHandle OutResult;
	SBCheckError(TElDirInfoProperty_AttributeByName(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDIRINFOATTRIBUTE */

void TElDirInfoProperty::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDirInfoProperty_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-818564222, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDirInfoProperty::set_Name(const std::string &Value)
{
	SBCheckError(TElDirInfoProperty_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDirInfoProperty::get_Value(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDirInfoProperty_get_Value(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(624027213, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDirInfoProperty::set_Value(const std::string &Value)
{
	SBCheckError(TElDirInfoProperty_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDirInfoProperty::get_FullName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDirInfoProperty_get_FullName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1892630518, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELDIRINFOATTRIBUTE
TElDirInfoAttribute* TElDirInfoProperty::get_Attributes(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDirInfoProperty_get_Attributes(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Attributes)
		this->_Inst_Attributes = new TElDirInfoAttribute(hOutResult, ohFalse);
	else
		this->_Inst_Attributes->updateHandle(hOutResult);
	return this->_Inst_Attributes;
}
#endif /* SB_USE_CLASS_TELDIRINFOATTRIBUTE */

SB_INLINE int32_t TElDirInfoProperty::get_AttributeCount()
{
	int32_t OutResult;
	SBCheckError(TElDirInfoProperty_get_AttributeCount(_Handle, &OutResult));
	return OutResult;
}

void TElDirInfoProperty::initInstances()
{
#ifdef SB_USE_CLASS_TELDIRINFOATTRIBUTE
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELDIRINFOATTRIBUTE */
}

TElDirInfoProperty::TElDirInfoProperty(TElDirInfoPropertyHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElDirInfoProperty::TElDirInfoProperty() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDirInfoProperty_Create(&_Handle));
}

TElDirInfoProperty::~TElDirInfoProperty()
{
#ifdef SB_USE_CLASS_TELDIRINFOATTRIBUTE
	delete this->_Inst_Attributes;
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELDIRINFOATTRIBUTE */
}
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTY */

#ifdef SB_USE_CLASS_TELDIRINFOPROPERTIESLIST

SB_INLINE void TElDirInfoPropertiesList::Clear()
{
	SBCheckError(TElDirInfoPropertiesList_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELDIRINFOPROPERTY
SB_INLINE void TElDirInfoPropertiesList::Add(TElDirInfoProperty &Prop)
{
	SBCheckError(TElDirInfoPropertiesList_Add(_Handle, Prop.getHandle()));
}

SB_INLINE void TElDirInfoPropertiesList::Add(TElDirInfoProperty *Prop)
{
	SBCheckError(TElDirInfoPropertiesList_Add(_Handle, (Prop != NULL) ? Prop->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTY */

#ifdef SB_USE_CLASS_TELDIRINFOPROPERTY
SB_INLINE void TElDirInfoPropertiesList::Insert(int32_t Index, TElDirInfoProperty &Prop)
{
	SBCheckError(TElDirInfoPropertiesList_Insert(_Handle, Index, Prop.getHandle()));
}

SB_INLINE void TElDirInfoPropertiesList::Insert(int32_t Index, TElDirInfoProperty *Prop)
{
	SBCheckError(TElDirInfoPropertiesList_Insert(_Handle, Index, (Prop != NULL) ? Prop->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTY */

SB_INLINE void TElDirInfoPropertiesList::Remove(int32_t Index)
{
	SBCheckError(TElDirInfoPropertiesList_Remove(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELDIRINFOPROPERTY
TElDirInfoProperty* TElDirInfoPropertiesList::get_SubProperties(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDirInfoPropertiesList_get_SubProperties(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SubProperties)
		this->_Inst_SubProperties = new TElDirInfoProperty(hOutResult, ohFalse);
	else
		this->_Inst_SubProperties->updateHandle(hOutResult);
	return this->_Inst_SubProperties;
}
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTY */

SB_INLINE int32_t TElDirInfoPropertiesList::get_SubPropertyCount()
{
	int32_t OutResult;
	SBCheckError(TElDirInfoPropertiesList_get_SubPropertyCount(_Handle, &OutResult));
	return OutResult;
}

bool TElDirInfoPropertiesList::get_IsSingle()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDirInfoPropertiesList_get_IsSingle(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELDIRINFOPROPERTY
TElDirInfoProperty* TElDirInfoPropertiesList::get_SingleProperty()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDirInfoPropertiesList_get_SingleProperty(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SingleProperty)
		this->_Inst_SingleProperty = new TElDirInfoProperty(hOutResult, ohFalse);
	else
		this->_Inst_SingleProperty->updateHandle(hOutResult);
	return this->_Inst_SingleProperty;
}
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTY */

void TElDirInfoPropertiesList::initInstances()
{
#ifdef SB_USE_CLASS_TELDIRINFOPROPERTY
	this->_Inst_SubProperties = NULL;
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTY */
#ifdef SB_USE_CLASS_TELDIRINFOPROPERTY
	this->_Inst_SingleProperty = NULL;
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTY */
}

TElDirInfoPropertiesList::TElDirInfoPropertiesList(TElDirInfoPropertiesListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElDirInfoPropertiesList::TElDirInfoPropertiesList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDirInfoPropertiesList_Create(&_Handle));
}

TElDirInfoPropertiesList::~TElDirInfoPropertiesList()
{
#ifdef SB_USE_CLASS_TELDIRINFOPROPERTY
	delete this->_Inst_SubProperties;
	this->_Inst_SubProperties = NULL;
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTY */
#ifdef SB_USE_CLASS_TELDIRINFOPROPERTY
	delete this->_Inst_SingleProperty;
	this->_Inst_SingleProperty = NULL;
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTY */
}
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTIESLIST */

#ifdef SB_USE_CLASS_TELDIRINFO

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElDirInfo::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElDirInfo_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElDirInfo::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElDirInfo_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElDirInfo::SaveToStream(TStream &Stream)
{
	SBCheckError(TElDirInfo_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElDirInfo::SaveToStream(TStream *Stream)
{
	SBCheckError(TElDirInfo_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElDirInfo::LoadFromFile(const std::string &FileName)
{
	SBCheckError(TElDirInfo_LoadFromFile(_Handle, FileName.data(), (int32_t)FileName.length()));
}

SB_INLINE void TElDirInfo::SaveToFile(const std::string &FileName)
{
	SBCheckError(TElDirInfo_SaveToFile(_Handle, FileName.data(), (int32_t)FileName.length()));
}

void TElDirInfo::ToString(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDirInfo_ToString(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1661555400, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TElDirInfoHandle TElDirInfo::AddSection(const std::string &Name)
{
	TElDirInfoHandle OutResult;
	SBCheckError(TElDirInfo_AddSection(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}

SB_INLINE void TElDirInfo::AddSection(TElDirInfo &Sect)
{
	SBCheckError(TElDirInfo_AddSection_1(_Handle, Sect.getHandle()));
}

SB_INLINE void TElDirInfo::AddSection(TElDirInfo *Sect)
{
	SBCheckError(TElDirInfo_AddSection_1(_Handle, (Sect != NULL) ? Sect->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDirInfo::RemoveSection(int32_t Index)
{
	SBCheckError(TElDirInfo_RemoveSection(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELDIRINFOPROPERTY
SB_INLINE void TElDirInfo::AddProperty(TElDirInfoProperty &Prop)
{
	SBCheckError(TElDirInfo_AddProperty(_Handle, Prop.getHandle()));
}

SB_INLINE void TElDirInfo::AddProperty(TElDirInfoProperty *Prop)
{
	SBCheckError(TElDirInfo_AddProperty(_Handle, (Prop != NULL) ? Prop->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTY */

#ifdef SB_USE_CLASS_TELDIRINFOPROPERTY
SB_INLINE void TElDirInfo::InsertProperty(int32_t Index, TElDirInfoProperty &Prop)
{
	SBCheckError(TElDirInfo_InsertProperty(_Handle, Index, Prop.getHandle()));
}

SB_INLINE void TElDirInfo::InsertProperty(int32_t Index, TElDirInfoProperty *Prop)
{
	SBCheckError(TElDirInfo_InsertProperty(_Handle, Index, (Prop != NULL) ? Prop->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTY */

SB_INLINE void TElDirInfo::RemoveProperty(const std::string &Name)
{
	SBCheckError(TElDirInfo_RemoveProperty(_Handle, Name.data(), (int32_t)Name.length()));
}

#ifdef SB_USE_CLASS_TELDIRINFOPROPERTY
SB_INLINE void TElDirInfo::RemoveAndAddProperty(TElDirInfoProperty &Prop)
{
	SBCheckError(TElDirInfo_RemoveAndAddProperty(_Handle, Prop.getHandle()));
}

SB_INLINE void TElDirInfo::RemoveAndAddProperty(TElDirInfoProperty *Prop)
{
	SBCheckError(TElDirInfo_RemoveAndAddProperty(_Handle, (Prop != NULL) ? Prop->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTY */

#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElDirInfo::GetPropertyNames(TStringList &OutResult)
{
	SBCheckError(TElDirInfo_GetPropertyNames(_Handle, OutResult.getHandle()));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

SB_INLINE TElDirInfoHandle TElDirInfo::SectionByName(const std::string &Name)
{
	TElDirInfoHandle OutResult;
	SBCheckError(TElDirInfo_SectionByName(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}

void TElDirInfo::GetPropertyValue(const std::string &Name, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDirInfo_GetPropertyValue(_Handle, Name.data(), (int32_t)Name.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1024937086, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDirInfo::SetPropertyValue(const std::string &Name, const std::string &Value)
{
	SBCheckError(TElDirInfo_SetPropertyValue(_Handle, Name.data(), (int32_t)Name.length(), Value.data(), (int32_t)Value.length()));
}

TElDirInfo* TElDirInfo::get_Parent()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDirInfo_get_Parent(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Parent)
		this->_Inst_Parent = new TElDirInfo(hOutResult, ohFalse);
	else
		this->_Inst_Parent->updateHandle(hOutResult);
	return this->_Inst_Parent;
}

SB_INLINE void TElDirInfo::set_Parent(TElDirInfo &Value)
{
	SBCheckError(TElDirInfo_set_Parent(_Handle, Value.getHandle()));
}

SB_INLINE void TElDirInfo::set_Parent(TElDirInfo *Value)
{
	SBCheckError(TElDirInfo_set_Parent(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

void TElDirInfo::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDirInfo_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1449459406, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDirInfo::set_Name(const std::string &Value)
{
	SBCheckError(TElDirInfo_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElDirInfo::get_Include()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDirInfo_get_Include(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Include)
		this->_Inst_Include = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Include->updateHandle(hOutResult);
	return this->_Inst_Include;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElDirInfo::get_Include()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDirInfo_get_Include(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Include)
		this->_Inst_Include = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Include->updateHandle(hOutResult);
	return this->_Inst_Include;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElDirInfo::get_FullPath(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDirInfo_get_FullPath(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1505004516, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDirInfo::get_FullPathEx(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDirInfo_get_FullPathEx(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1657736317, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElDirInfo::get_GenerateUID()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDirInfo_get_GenerateUID(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDirInfo::set_GenerateUID(bool Value)
{
	SBCheckError(TElDirInfo_set_GenerateUID(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELDIRINFOPROPERTIESLIST
TElDirInfoPropertiesList* TElDirInfo::get_Properties(const std::string &Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDirInfo_get_Properties(_Handle, Index.data(), (int32_t)Index.length(), &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Properties)
		this->_Inst_Properties = new TElDirInfoPropertiesList(hOutResult, ohFalse);
	else
		this->_Inst_Properties->updateHandle(hOutResult);
	return this->_Inst_Properties;
}
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTIESLIST */

SB_INLINE int32_t TElDirInfo::get_PropertyCount()
{
	int32_t OutResult;
	SBCheckError(TElDirInfo_get_PropertyCount(_Handle, &OutResult));
	return OutResult;
}

TElDirInfo* TElDirInfo::get_Sections(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDirInfo_get_Sections(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Sections)
		this->_Inst_Sections = new TElDirInfo(hOutResult, ohFalse);
	else
		this->_Inst_Sections->updateHandle(hOutResult);
	return this->_Inst_Sections;
}

SB_INLINE int32_t TElDirInfo::get_SectionCount()
{
	int32_t OutResult;
	SBCheckError(TElDirInfo_get_SectionCount(_Handle, &OutResult));
	return OutResult;
}

void TElDirInfo::initInstances()
{
	this->_Inst_Parent = NULL;
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Include = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Include = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELDIRINFOPROPERTIESLIST
	this->_Inst_Properties = NULL;
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTIESLIST */
	this->_Inst_Sections = NULL;
}

TElDirInfo::TElDirInfo(TElDirInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElDirInfo::TElDirInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDirInfo_Create(&_Handle));
}

TElDirInfo::~TElDirInfo()
{
	delete this->_Inst_Parent;
	this->_Inst_Parent = NULL;
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Include;
	this->_Inst_Include = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Include;
	this->_Inst_Include = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELDIRINFOPROPERTIESLIST
	delete this->_Inst_Properties;
	this->_Inst_Properties = NULL;
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTIESLIST */
	delete this->_Inst_Sections;
	this->_Inst_Sections = NULL;
}
#endif /* SB_USE_CLASS_TELDIRINFO */

#ifdef SB_USE_CLASS_TELVCARD

SB_INLINE int32_t TElVCard::get_Version()
{
	int32_t OutResult;
	SBCheckError(TElVCard_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElVCard::set_Version(int32_t Value)
{
	SBCheckError(TElVCard_set_Version(_Handle, Value));
}

TElVCard::TElVCard(TElVCardHandle handle, TElOwnHandle ownHandle) : TElDirInfo(handle, ownHandle)
{
}

TElVCard::TElVCard() : TElDirInfo(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElVCard_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELVCARD */

#ifdef SB_USE_CLASS_TELVCALENDAR

TElVCalendar::TElVCalendar(TElVCalendarHandle handle, TElOwnHandle ownHandle) : TElDirInfo(handle, ownHandle)
{
}

TElVCalendar::TElVCalendar() : TElDirInfo(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElVCalendar_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELVCALENDAR */

};	/* namespace SecureBlackbox */
