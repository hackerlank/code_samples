#include "sbofficebinarycore.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELOFFICEBINARYOBJECT

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeBinaryObject::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeBinaryObject_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeBinaryObject::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeBinaryObject_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeBinaryObject::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeBinaryObject_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeBinaryObject::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeBinaryObject_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

TElOfficeBinaryObject::TElOfficeBinaryObject(TElOfficeBinaryObjectHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElOfficeBinaryObject::TElOfficeBinaryObject() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeBinaryObject_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEBINARYOBJECT */

#ifdef SB_USE_CLASS_TELOFFICEDATASPACEVERSIONINFO

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeDataSpaceVersionInfo::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeDataSpaceVersionInfo_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeDataSpaceVersionInfo::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeDataSpaceVersionInfo_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeDataSpaceVersionInfo::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeDataSpaceVersionInfo_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeDataSpaceVersionInfo::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeDataSpaceVersionInfo_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElOfficeDataSpaceVersionInfo::get_FeatureIdentifier(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeDataSpaceVersionInfo_get_FeatureIdentifier(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1724887295, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeDataSpaceVersionInfo::get_FeatureIdentifier(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeDataSpaceVersionInfo_get_FeatureIdentifier(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1724887295, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeDataSpaceVersionInfo::set_FeatureIdentifier(const sb_u16string &Value)
{
	SBCheckError(TElOfficeDataSpaceVersionInfo_set_FeatureIdentifier(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeDataSpaceVersionInfo::set_FeatureIdentifier(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeDataSpaceVersionInfo_set_FeatureIdentifier(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElOfficeDataSpaceVersionInfo::TElOfficeDataSpaceVersionInfo(TElOfficeDataSpaceVersionInfoHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficeDataSpaceVersionInfo::TElOfficeDataSpaceVersionInfo() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeDataSpaceVersionInfo_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEDATASPACEVERSIONINFO */

#ifdef SB_USE_CLASS_TELOFFICEDATASPACEREFERENCECOMPONENT

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeDataSpaceReferenceComponent::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeDataSpaceReferenceComponent_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeDataSpaceReferenceComponent::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeDataSpaceReferenceComponent_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeDataSpaceReferenceComponent::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeDataSpaceReferenceComponent_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeDataSpaceReferenceComponent::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeDataSpaceReferenceComponent_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE uint32_t TElOfficeDataSpaceReferenceComponent::get_ReferenceComponentType()
{
	uint32_t OutResult;
	SBCheckError(TElOfficeDataSpaceReferenceComponent_get_ReferenceComponentType(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeDataSpaceReferenceComponent::set_ReferenceComponentType(uint32_t Value)
{
	SBCheckError(TElOfficeDataSpaceReferenceComponent_set_ReferenceComponentType(_Handle, Value));
}

void TElOfficeDataSpaceReferenceComponent::get_ReferenceComponent(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeDataSpaceReferenceComponent_get_ReferenceComponent(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1959522345, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeDataSpaceReferenceComponent::get_ReferenceComponent(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeDataSpaceReferenceComponent_get_ReferenceComponent(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1959522345, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeDataSpaceReferenceComponent::set_ReferenceComponent(const sb_u16string &Value)
{
	SBCheckError(TElOfficeDataSpaceReferenceComponent_set_ReferenceComponent(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeDataSpaceReferenceComponent::set_ReferenceComponent(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeDataSpaceReferenceComponent_set_ReferenceComponent(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElOfficeDataSpaceReferenceComponent::TElOfficeDataSpaceReferenceComponent(TElOfficeDataSpaceReferenceComponentHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficeDataSpaceReferenceComponent::TElOfficeDataSpaceReferenceComponent() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeDataSpaceReferenceComponent_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEDATASPACEREFERENCECOMPONENT */

#ifdef SB_USE_CLASS_TELOFFICEDATASPACEMAPENTRY

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeDataSpaceMapEntry::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeDataSpaceMapEntry_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeDataSpaceMapEntry::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeDataSpaceMapEntry_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeDataSpaceMapEntry::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeDataSpaceMapEntry_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeDataSpaceMapEntry::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeDataSpaceMapEntry_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElOfficeDataSpaceMapEntry::Clear()
{
	SBCheckError(TElOfficeDataSpaceMapEntry_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELOFFICEDATASPACEREFERENCECOMPONENT
SB_INLINE int32_t TElOfficeDataSpaceMapEntry::Add(TElOfficeDataSpaceReferenceComponent &ARef)
{
	int32_t OutResult;
	SBCheckError(TElOfficeDataSpaceMapEntry_Add(_Handle, ARef.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeDataSpaceMapEntry::Add(TElOfficeDataSpaceReferenceComponent *ARef)
{
	int32_t OutResult;
	SBCheckError(TElOfficeDataSpaceMapEntry_Add(_Handle, (ARef != NULL) ? ARef->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICEDATASPACEREFERENCECOMPONENT */

#ifdef SB_USE_CLASS_TELOFFICEDATASPACEREFERENCECOMPONENT
SB_INLINE void TElOfficeDataSpaceMapEntry::Insert(int32_t Index, TElOfficeDataSpaceReferenceComponent &ARef)
{
	SBCheckError(TElOfficeDataSpaceMapEntry_Insert(_Handle, Index, ARef.getHandle()));
}

SB_INLINE void TElOfficeDataSpaceMapEntry::Insert(int32_t Index, TElOfficeDataSpaceReferenceComponent *ARef)
{
	SBCheckError(TElOfficeDataSpaceMapEntry_Insert(_Handle, Index, (ARef != NULL) ? ARef->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOFFICEDATASPACEREFERENCECOMPONENT */

SB_INLINE void TElOfficeDataSpaceMapEntry::Delete(int32_t Index)
{
	SBCheckError(TElOfficeDataSpaceMapEntry_Delete(_Handle, Index));
}

SB_INLINE int32_t TElOfficeDataSpaceMapEntry::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElOfficeDataSpaceMapEntry_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICEDATASPACEREFERENCECOMPONENT
TElOfficeDataSpaceReferenceComponent* TElOfficeDataSpaceMapEntry::get_ReferenceComponents(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeDataSpaceMapEntry_get_ReferenceComponents(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ReferenceComponents)
		this->_Inst_ReferenceComponents = new TElOfficeDataSpaceReferenceComponent(hOutResult, ohFalse);
	else
		this->_Inst_ReferenceComponents->updateHandle(hOutResult);
	return this->_Inst_ReferenceComponents;
}
#endif /* SB_USE_CLASS_TELOFFICEDATASPACEREFERENCECOMPONENT */

void TElOfficeDataSpaceMapEntry::get_DataSpaceName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeDataSpaceMapEntry_get_DataSpaceName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(818654366, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeDataSpaceMapEntry::get_DataSpaceName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeDataSpaceMapEntry_get_DataSpaceName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(818654366, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeDataSpaceMapEntry::set_DataSpaceName(const sb_u16string &Value)
{
	SBCheckError(TElOfficeDataSpaceMapEntry_set_DataSpaceName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeDataSpaceMapEntry::set_DataSpaceName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeDataSpaceMapEntry_set_DataSpaceName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeDataSpaceMapEntry::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEDATASPACEREFERENCECOMPONENT
	this->_Inst_ReferenceComponents = NULL;
#endif /* SB_USE_CLASS_TELOFFICEDATASPACEREFERENCECOMPONENT */
}

TElOfficeDataSpaceMapEntry::TElOfficeDataSpaceMapEntry(TElOfficeDataSpaceMapEntryHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
	initInstances();
}

TElOfficeDataSpaceMapEntry::TElOfficeDataSpaceMapEntry() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeDataSpaceMapEntry_Create(&_Handle));
}

TElOfficeDataSpaceMapEntry::~TElOfficeDataSpaceMapEntry()
{
#ifdef SB_USE_CLASS_TELOFFICEDATASPACEREFERENCECOMPONENT
	delete this->_Inst_ReferenceComponents;
	this->_Inst_ReferenceComponents = NULL;
#endif /* SB_USE_CLASS_TELOFFICEDATASPACEREFERENCECOMPONENT */
}
#endif /* SB_USE_CLASS_TELOFFICEDATASPACEMAPENTRY */

#ifdef SB_USE_CLASS_TELOFFICEDATASPACEMAP

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeDataSpaceMap::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeDataSpaceMap_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeDataSpaceMap::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeDataSpaceMap_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeDataSpaceMap::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeDataSpaceMap_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeDataSpaceMap::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeDataSpaceMap_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElOfficeDataSpaceMap::Clear()
{
	SBCheckError(TElOfficeDataSpaceMap_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELOFFICEDATASPACEMAPENTRY
SB_INLINE int32_t TElOfficeDataSpaceMap::Add(TElOfficeDataSpaceMapEntry &AEntry)
{
	int32_t OutResult;
	SBCheckError(TElOfficeDataSpaceMap_Add(_Handle, AEntry.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeDataSpaceMap::Add(TElOfficeDataSpaceMapEntry *AEntry)
{
	int32_t OutResult;
	SBCheckError(TElOfficeDataSpaceMap_Add(_Handle, (AEntry != NULL) ? AEntry->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICEDATASPACEMAPENTRY */

#ifdef SB_USE_CLASS_TELOFFICEDATASPACEMAPENTRY
SB_INLINE void TElOfficeDataSpaceMap::Insert(int32_t Index, TElOfficeDataSpaceMapEntry &AEntry)
{
	SBCheckError(TElOfficeDataSpaceMap_Insert(_Handle, Index, AEntry.getHandle()));
}

SB_INLINE void TElOfficeDataSpaceMap::Insert(int32_t Index, TElOfficeDataSpaceMapEntry *AEntry)
{
	SBCheckError(TElOfficeDataSpaceMap_Insert(_Handle, Index, (AEntry != NULL) ? AEntry->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOFFICEDATASPACEMAPENTRY */

SB_INLINE void TElOfficeDataSpaceMap::Delete(int32_t Index)
{
	SBCheckError(TElOfficeDataSpaceMap_Delete(_Handle, Index));
}

SB_INLINE int32_t TElOfficeDataSpaceMap::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElOfficeDataSpaceMap_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICEDATASPACEMAPENTRY
TElOfficeDataSpaceMapEntry* TElOfficeDataSpaceMap::get_MapEntries(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeDataSpaceMap_get_MapEntries(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_MapEntries)
		this->_Inst_MapEntries = new TElOfficeDataSpaceMapEntry(hOutResult, ohFalse);
	else
		this->_Inst_MapEntries->updateHandle(hOutResult);
	return this->_Inst_MapEntries;
}
#endif /* SB_USE_CLASS_TELOFFICEDATASPACEMAPENTRY */

void TElOfficeDataSpaceMap::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEDATASPACEMAPENTRY
	this->_Inst_MapEntries = NULL;
#endif /* SB_USE_CLASS_TELOFFICEDATASPACEMAPENTRY */
}

TElOfficeDataSpaceMap::TElOfficeDataSpaceMap(TElOfficeDataSpaceMapHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
	initInstances();
}

TElOfficeDataSpaceMap::TElOfficeDataSpaceMap() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeDataSpaceMap_Create(&_Handle));
}

TElOfficeDataSpaceMap::~TElOfficeDataSpaceMap()
{
#ifdef SB_USE_CLASS_TELOFFICEDATASPACEMAPENTRY
	delete this->_Inst_MapEntries;
	this->_Inst_MapEntries = NULL;
#endif /* SB_USE_CLASS_TELOFFICEDATASPACEMAPENTRY */
}
#endif /* SB_USE_CLASS_TELOFFICEDATASPACEMAP */

#ifdef SB_USE_CLASS_TELOFFICEDATASPACEDEFINITION

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeDataSpaceDefinition::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeDataSpaceDefinition_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeDataSpaceDefinition::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeDataSpaceDefinition_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeDataSpaceDefinition::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeDataSpaceDefinition_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeDataSpaceDefinition::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeDataSpaceDefinition_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElOfficeDataSpaceDefinition::Clear()
{
	SBCheckError(TElOfficeDataSpaceDefinition_Clear(_Handle));
}

SB_INLINE int32_t TElOfficeDataSpaceDefinition::Add(const sb_u16string &ARef)
{
	int32_t OutResult;
	SBCheckError(TElOfficeDataSpaceDefinition_Add(_Handle, ARef.data(), (int32_t)ARef.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElOfficeDataSpaceDefinition::Add(const std::wstring &ARef)
{
	int32_t OutResult;
	std::string u16ARef;
	sb_to_u16string(ARef, u16ARef);
	SBCheckError(TElOfficeDataSpaceDefinition_Add(_Handle, reinterpret_cast<const sb_char16_t*>(u16ARef.data()), (int32_t)u16ARef.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElOfficeDataSpaceDefinition::Insert(int32_t Index, const sb_u16string &ARef)
{
	SBCheckError(TElOfficeDataSpaceDefinition_Insert(_Handle, Index, ARef.data(), (int32_t)ARef.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeDataSpaceDefinition::Insert(int32_t Index, const std::wstring &ARef)
{
	std::string u16ARef;
	sb_to_u16string(ARef, u16ARef);
	SBCheckError(TElOfficeDataSpaceDefinition_Insert(_Handle, Index, reinterpret_cast<const sb_char16_t*>(u16ARef.data()), (int32_t)u16ARef.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElOfficeDataSpaceDefinition::Delete(int32_t Index)
{
	SBCheckError(TElOfficeDataSpaceDefinition_Delete(_Handle, Index));
}

SB_INLINE int32_t TElOfficeDataSpaceDefinition::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElOfficeDataSpaceDefinition_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElOfficeDataSpaceDefinition::get_TransformReferences(int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeDataSpaceDefinition_get_TransformReferences(_Handle, Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1625892206, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeDataSpaceDefinition::get_TransformReferences(int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeDataSpaceDefinition_get_TransformReferences(_Handle, Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1625892206, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
TElOfficeDataSpaceDefinition::TElOfficeDataSpaceDefinition(TElOfficeDataSpaceDefinitionHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficeDataSpaceDefinition::TElOfficeDataSpaceDefinition() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeDataSpaceDefinition_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEDATASPACEDEFINITION */

#ifdef SB_USE_CLASS_TELOFFICETRANSFORMINFOHEADER

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeTransformInfoHeader::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeTransformInfoHeader_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeTransformInfoHeader::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeTransformInfoHeader_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeTransformInfoHeader::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeTransformInfoHeader_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeTransformInfoHeader::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeTransformInfoHeader_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElOfficeTransformInfoHeader::get_TransformID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeTransformInfoHeader_get_TransformID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(767021258, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeTransformInfoHeader::get_TransformID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeTransformInfoHeader_get_TransformID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(767021258, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeTransformInfoHeader::set_TransformID(const sb_u16string &Value)
{
	SBCheckError(TElOfficeTransformInfoHeader_set_TransformID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeTransformInfoHeader::set_TransformID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeTransformInfoHeader_set_TransformID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeTransformInfoHeader::get_TransformName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeTransformInfoHeader_get_TransformName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-115540952, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeTransformInfoHeader::get_TransformName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeTransformInfoHeader_get_TransformName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-115540952, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeTransformInfoHeader::set_TransformName(const sb_u16string &Value)
{
	SBCheckError(TElOfficeTransformInfoHeader_set_TransformName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeTransformInfoHeader::set_TransformName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeTransformInfoHeader_set_TransformName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE uint32_t TElOfficeTransformInfoHeader::get_TransformType()
{
	uint32_t OutResult;
	SBCheckError(TElOfficeTransformInfoHeader_get_TransformType(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeTransformInfoHeader::set_TransformType(uint32_t Value)
{
	SBCheckError(TElOfficeTransformInfoHeader_set_TransformType(_Handle, Value));
}

SB_INLINE void TElOfficeTransformInfoHeader::get_ReaderVersion(TSBOfficeVersion &OutResult)
{
	SBCheckError(TElOfficeTransformInfoHeader_get_ReaderVersion(_Handle, &OutResult));
}

SB_INLINE void TElOfficeTransformInfoHeader::set_ReaderVersion(TSBOfficeVersion Value)
{
	SBCheckError(TElOfficeTransformInfoHeader_set_ReaderVersion(_Handle, Value));
}

SB_INLINE void TElOfficeTransformInfoHeader::get_UpdaterVersion(TSBOfficeVersion &OutResult)
{
	SBCheckError(TElOfficeTransformInfoHeader_get_UpdaterVersion(_Handle, &OutResult));
}

SB_INLINE void TElOfficeTransformInfoHeader::set_UpdaterVersion(TSBOfficeVersion Value)
{
	SBCheckError(TElOfficeTransformInfoHeader_set_UpdaterVersion(_Handle, Value));
}

SB_INLINE void TElOfficeTransformInfoHeader::get_WriterVersion(TSBOfficeVersion &OutResult)
{
	SBCheckError(TElOfficeTransformInfoHeader_get_WriterVersion(_Handle, &OutResult));
}

SB_INLINE void TElOfficeTransformInfoHeader::set_WriterVersion(TSBOfficeVersion Value)
{
	SBCheckError(TElOfficeTransformInfoHeader_set_WriterVersion(_Handle, Value));
}

TElOfficeTransformInfoHeader::TElOfficeTransformInfoHeader(TElOfficeTransformInfoHeaderHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficeTransformInfoHeader::TElOfficeTransformInfoHeader() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeTransformInfoHeader_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICETRANSFORMINFOHEADER */

#ifdef SB_USE_CLASS_TELOFFICEENCRYPTIONTRANSFORMINFO

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeEncryptionTransformInfo::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeEncryptionTransformInfo_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeEncryptionTransformInfo::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeEncryptionTransformInfo_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeEncryptionTransformInfo::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeEncryptionTransformInfo_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeEncryptionTransformInfo::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeEncryptionTransformInfo_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElOfficeEncryptionTransformInfo::get_EncryptionName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeEncryptionTransformInfo_get_EncryptionName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-142559156, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeEncryptionTransformInfo::get_EncryptionName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeEncryptionTransformInfo_get_EncryptionName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-142559156, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeEncryptionTransformInfo::set_EncryptionName(const sb_u16string &Value)
{
	SBCheckError(TElOfficeEncryptionTransformInfo_set_EncryptionName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeEncryptionTransformInfo::set_EncryptionName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeEncryptionTransformInfo_set_EncryptionName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE uint32_t TElOfficeEncryptionTransformInfo::get_EncryptionBlockSize()
{
	uint32_t OutResult;
	SBCheckError(TElOfficeEncryptionTransformInfo_get_EncryptionBlockSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeEncryptionTransformInfo::set_EncryptionBlockSize(uint32_t Value)
{
	SBCheckError(TElOfficeEncryptionTransformInfo_set_EncryptionBlockSize(_Handle, Value));
}

SB_INLINE uint32_t TElOfficeEncryptionTransformInfo::get_CipherMode()
{
	uint32_t OutResult;
	SBCheckError(TElOfficeEncryptionTransformInfo_get_CipherMode(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeEncryptionTransformInfo::set_CipherMode(uint32_t Value)
{
	SBCheckError(TElOfficeEncryptionTransformInfo_set_CipherMode(_Handle, Value));
}

TElOfficeEncryptionTransformInfo::TElOfficeEncryptionTransformInfo(TElOfficeEncryptionTransformInfoHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficeEncryptionTransformInfo::TElOfficeEncryptionTransformInfo() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeEncryptionTransformInfo_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEENCRYPTIONTRANSFORMINFO */

#ifdef SB_USE_CLASS_TELOFFICEEXTENSIBILITYHEADER

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeExtensibilityHeader::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeExtensibilityHeader_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeExtensibilityHeader::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeExtensibilityHeader_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeExtensibilityHeader::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeExtensibilityHeader_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeExtensibilityHeader::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeExtensibilityHeader_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE uint32_t TElOfficeExtensibilityHeader::get_Length()
{
	uint32_t OutResult;
	SBCheckError(TElOfficeExtensibilityHeader_get_Length(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeExtensibilityHeader::set_Length(uint32_t Value)
{
	SBCheckError(TElOfficeExtensibilityHeader_set_Length(_Handle, Value));
}

TElOfficeExtensibilityHeader::TElOfficeExtensibilityHeader(TElOfficeExtensibilityHeaderHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficeExtensibilityHeader::TElOfficeExtensibilityHeader() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeExtensibilityHeader_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEEXTENSIBILITYHEADER */

#ifdef SB_USE_CLASS_TELOFFICEIRMDSTRANSFORMINFO

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeIRMDSTransformInfo::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeIRMDSTransformInfo_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeIRMDSTransformInfo::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeIRMDSTransformInfo_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeIRMDSTransformInfo::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeIRMDSTransformInfo_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeIRMDSTransformInfo::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeIRMDSTransformInfo_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELOFFICETRANSFORMINFOHEADER
TElOfficeTransformInfoHeader* TElOfficeIRMDSTransformInfo::get_TransformInfoHeader()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeIRMDSTransformInfo_get_TransformInfoHeader(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TransformInfoHeader)
		this->_Inst_TransformInfoHeader = new TElOfficeTransformInfoHeader(hOutResult, ohFalse);
	else
		this->_Inst_TransformInfoHeader->updateHandle(hOutResult);
	return this->_Inst_TransformInfoHeader;
}
#endif /* SB_USE_CLASS_TELOFFICETRANSFORMINFOHEADER */

#ifdef SB_USE_CLASS_TELOFFICEEXTENSIBILITYHEADER
TElOfficeExtensibilityHeader* TElOfficeIRMDSTransformInfo::get_ExtensibilityHeader()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeIRMDSTransformInfo_get_ExtensibilityHeader(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ExtensibilityHeader)
		this->_Inst_ExtensibilityHeader = new TElOfficeExtensibilityHeader(hOutResult, ohFalse);
	else
		this->_Inst_ExtensibilityHeader->updateHandle(hOutResult);
	return this->_Inst_ExtensibilityHeader;
}
#endif /* SB_USE_CLASS_TELOFFICEEXTENSIBILITYHEADER */

void TElOfficeIRMDSTransformInfo::get_XrMLLicense(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeIRMDSTransformInfo_get_XrMLLicense(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-2007089094, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeIRMDSTransformInfo::get_XrMLLicense(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeIRMDSTransformInfo_get_XrMLLicense(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-2007089094, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeIRMDSTransformInfo::set_XrMLLicense(const sb_u16string &Value)
{
	SBCheckError(TElOfficeIRMDSTransformInfo_set_XrMLLicense(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeIRMDSTransformInfo::set_XrMLLicense(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeIRMDSTransformInfo_set_XrMLLicense(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeIRMDSTransformInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICETRANSFORMINFOHEADER
	this->_Inst_TransformInfoHeader = NULL;
#endif /* SB_USE_CLASS_TELOFFICETRANSFORMINFOHEADER */
#ifdef SB_USE_CLASS_TELOFFICEEXTENSIBILITYHEADER
	this->_Inst_ExtensibilityHeader = NULL;
#endif /* SB_USE_CLASS_TELOFFICEEXTENSIBILITYHEADER */
}

TElOfficeIRMDSTransformInfo::TElOfficeIRMDSTransformInfo(TElOfficeIRMDSTransformInfoHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
	initInstances();
}

TElOfficeIRMDSTransformInfo::TElOfficeIRMDSTransformInfo() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeIRMDSTransformInfo_Create(&_Handle));
}

TElOfficeIRMDSTransformInfo::~TElOfficeIRMDSTransformInfo()
{
#ifdef SB_USE_CLASS_TELOFFICETRANSFORMINFOHEADER
	delete this->_Inst_TransformInfoHeader;
	this->_Inst_TransformInfoHeader = NULL;
#endif /* SB_USE_CLASS_TELOFFICETRANSFORMINFOHEADER */
#ifdef SB_USE_CLASS_TELOFFICEEXTENSIBILITYHEADER
	delete this->_Inst_ExtensibilityHeader;
	this->_Inst_ExtensibilityHeader = NULL;
#endif /* SB_USE_CLASS_TELOFFICEEXTENSIBILITYHEADER */
}
#endif /* SB_USE_CLASS_TELOFFICEIRMDSTRANSFORMINFO */

#ifdef SB_USE_CLASS_TELOFFICEENDUSERLICENSEHEADER

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeEndUserLicenseHeader::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeEndUserLicenseHeader_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeEndUserLicenseHeader::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeEndUserLicenseHeader_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeEndUserLicenseHeader::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeEndUserLicenseHeader_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeEndUserLicenseHeader::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeEndUserLicenseHeader_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElOfficeEndUserLicenseHeader::get_ID_String(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeEndUserLicenseHeader_get_ID_String(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-669079394, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeEndUserLicenseHeader::get_ID_String(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeEndUserLicenseHeader_get_ID_String(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-669079394, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeEndUserLicenseHeader::set_ID_String(const sb_u16string &Value)
{
	SBCheckError(TElOfficeEndUserLicenseHeader_set_ID_String(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeEndUserLicenseHeader::set_ID_String(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeEndUserLicenseHeader_set_ID_String(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElOfficeEndUserLicenseHeader::TElOfficeEndUserLicenseHeader(TElOfficeEndUserLicenseHeaderHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficeEndUserLicenseHeader::TElOfficeEndUserLicenseHeader() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeEndUserLicenseHeader_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEENDUSERLICENSEHEADER */

#ifdef SB_USE_CLASS_TELOFFICEENCRYPTIONHEADER

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeEncryptionHeader::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeEncryptionHeader_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeEncryptionHeader::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeEncryptionHeader_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeEncryptionHeader::LoadFromStream(TStream &Stream, uint32_t Length)
{
	SBCheckError(TElOfficeEncryptionHeader_LoadFromStream_1(_Handle, Stream.getHandle(), Length));
}

SB_INLINE void TElOfficeEncryptionHeader::LoadFromStream(TStream *Stream, uint32_t Length)
{
	SBCheckError(TElOfficeEncryptionHeader_LoadFromStream_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Length));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeEncryptionHeader::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeEncryptionHeader_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeEncryptionHeader::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeEncryptionHeader_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE uint32_t TElOfficeEncryptionHeader::get_Flags()
{
	uint32_t OutResult;
	SBCheckError(TElOfficeEncryptionHeader_get_Flags(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeEncryptionHeader::set_Flags(uint32_t Value)
{
	SBCheckError(TElOfficeEncryptionHeader_set_Flags(_Handle, Value));
}

SB_INLINE int32_t TElOfficeEncryptionHeader::get_AlgID()
{
	int32_t OutResult;
	SBCheckError(TElOfficeEncryptionHeader_get_AlgID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeEncryptionHeader::set_AlgID(int32_t Value)
{
	SBCheckError(TElOfficeEncryptionHeader_set_AlgID(_Handle, Value));
}

SB_INLINE int32_t TElOfficeEncryptionHeader::get_AlgIDHash()
{
	int32_t OutResult;
	SBCheckError(TElOfficeEncryptionHeader_get_AlgIDHash(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeEncryptionHeader::set_AlgIDHash(int32_t Value)
{
	SBCheckError(TElOfficeEncryptionHeader_set_AlgIDHash(_Handle, Value));
}

SB_INLINE uint32_t TElOfficeEncryptionHeader::get_KeySize()
{
	uint32_t OutResult;
	SBCheckError(TElOfficeEncryptionHeader_get_KeySize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeEncryptionHeader::set_KeySize(uint32_t Value)
{
	SBCheckError(TElOfficeEncryptionHeader_set_KeySize(_Handle, Value));
}

SB_INLINE uint32_t TElOfficeEncryptionHeader::get_ProviderType()
{
	uint32_t OutResult;
	SBCheckError(TElOfficeEncryptionHeader_get_ProviderType(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeEncryptionHeader::set_ProviderType(uint32_t Value)
{
	SBCheckError(TElOfficeEncryptionHeader_set_ProviderType(_Handle, Value));
}

void TElOfficeEncryptionHeader::get_CSPName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeEncryptionHeader_get_CSPName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-654900006, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeEncryptionHeader::get_CSPName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeEncryptionHeader_get_CSPName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-654900006, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeEncryptionHeader::set_CSPName(const sb_u16string &Value)
{
	SBCheckError(TElOfficeEncryptionHeader_set_CSPName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeEncryptionHeader::set_CSPName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeEncryptionHeader_set_CSPName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElOfficeEncryptionHeader::TElOfficeEncryptionHeader(TElOfficeEncryptionHeaderHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficeEncryptionHeader::TElOfficeEncryptionHeader() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeEncryptionHeader_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEENCRYPTIONHEADER */

#ifdef SB_USE_CLASS_TELOFFICEENCRYPTIONVERIFIER

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeEncryptionVerifier::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeEncryptionVerifier_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeEncryptionVerifier::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeEncryptionVerifier_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeEncryptionVerifier::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeEncryptionVerifier_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeEncryptionVerifier::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeEncryptionVerifier_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElOfficeEncryptionVerifier::get_Salt(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeEncryptionVerifier_get_Salt(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(874505940, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeEncryptionVerifier::set_Salt(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeEncryptionVerifier_set_Salt(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElOfficeEncryptionVerifier::get_EncryptedVerifier(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeEncryptionVerifier_get_EncryptedVerifier(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(108409809, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeEncryptionVerifier::set_EncryptedVerifier(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeEncryptionVerifier_set_EncryptedVerifier(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE uint32_t TElOfficeEncryptionVerifier::get_VerifierHashSize()
{
	uint32_t OutResult;
	SBCheckError(TElOfficeEncryptionVerifier_get_VerifierHashSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeEncryptionVerifier::set_VerifierHashSize(uint32_t Value)
{
	SBCheckError(TElOfficeEncryptionVerifier_set_VerifierHashSize(_Handle, Value));
}

void TElOfficeEncryptionVerifier::get_EncryptedVerifierHash(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeEncryptionVerifier_get_EncryptedVerifierHash(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2014178538, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeEncryptionVerifier::set_EncryptedVerifierHash(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeEncryptionVerifier_set_EncryptedVerifierHash(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElOfficeEncryptionVerifier::get_ExpectedEncryptedVerifierHashSize()
{
	int32_t OutResult;
	SBCheckError(TElOfficeEncryptionVerifier_get_ExpectedEncryptedVerifierHashSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeEncryptionVerifier::set_ExpectedEncryptedVerifierHashSize(int32_t Value)
{
	SBCheckError(TElOfficeEncryptionVerifier_set_ExpectedEncryptedVerifierHashSize(_Handle, Value));
}

TElOfficeEncryptionVerifier::TElOfficeEncryptionVerifier(TElOfficeEncryptionVerifierHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficeEncryptionVerifier::TElOfficeEncryptionVerifier() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeEncryptionVerifier_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEENCRYPTIONVERIFIER */

#ifdef SB_USE_CLASS_TELOFFICEENCRYPTIONINFO

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeEncryptionInfo::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeEncryptionInfo_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeEncryptionInfo::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeEncryptionInfo_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeEncryptionInfo::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeEncryptionInfo_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeEncryptionInfo::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeEncryptionInfo_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElOfficeEncryptionInfo::get_EncryptionVersionInfo(TSBOfficeVersion &OutResult)
{
	SBCheckError(TElOfficeEncryptionInfo_get_EncryptionVersionInfo(_Handle, &OutResult));
}

SB_INLINE void TElOfficeEncryptionInfo::set_EncryptionVersionInfo(TSBOfficeVersion Value)
{
	SBCheckError(TElOfficeEncryptionInfo_set_EncryptionVersionInfo(_Handle, Value));
}

TElOfficeEncryptionInfo::TElOfficeEncryptionInfo(TElOfficeEncryptionInfoHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficeEncryptionInfo::TElOfficeEncryptionInfo() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeEncryptionInfo_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEENCRYPTIONINFO */

#ifdef SB_USE_CLASS_TELOFFICEENCRYPTIONINFOV1

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeEncryptionInfoV1::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeEncryptionInfoV1_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeEncryptionInfoV1::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeEncryptionInfoV1_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeEncryptionInfoV1::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeEncryptionInfoV1_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeEncryptionInfoV1::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeEncryptionInfoV1_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElOfficeEncryptionInfoV1::get_Salt(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeEncryptionInfoV1_get_Salt(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1375349291, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeEncryptionInfoV1::set_Salt(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeEncryptionInfoV1_set_Salt(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElOfficeEncryptionInfoV1::get_EncryptedVerifier(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeEncryptionInfoV1_get_EncryptedVerifier(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(579308239, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeEncryptionInfoV1::set_EncryptedVerifier(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeEncryptionInfoV1_set_EncryptedVerifier(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElOfficeEncryptionInfoV1::get_EncryptedVerifierHash(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeEncryptionInfoV1_get_EncryptedVerifierHash(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(870333940, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeEncryptionInfoV1::set_EncryptedVerifierHash(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeEncryptionInfoV1_set_EncryptedVerifierHash(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElOfficeEncryptionInfoV1::TElOfficeEncryptionInfoV1(TElOfficeEncryptionInfoV1Handle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficeEncryptionInfoV1::TElOfficeEncryptionInfoV1() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeEncryptionInfoV1_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEENCRYPTIONINFOV1 */

#ifdef SB_USE_CLASS_TELOFFICEENCRYPTIONINFOV2

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeEncryptionInfoV2::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeEncryptionInfoV2_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeEncryptionInfoV2::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeEncryptionInfoV2_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeEncryptionInfoV2::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeEncryptionInfoV2_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeEncryptionInfoV2::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeEncryptionInfoV2_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE uint32_t TElOfficeEncryptionInfoV2::get_EncryptionHeaderFlags()
{
	uint32_t OutResult;
	SBCheckError(TElOfficeEncryptionInfoV2_get_EncryptionHeaderFlags(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeEncryptionInfoV2::set_EncryptionHeaderFlags(uint32_t Value)
{
	SBCheckError(TElOfficeEncryptionInfoV2_set_EncryptionHeaderFlags(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELOFFICEENCRYPTIONHEADER
TElOfficeEncryptionHeader* TElOfficeEncryptionInfoV2::get_EncryptionHeader()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeEncryptionInfoV2_get_EncryptionHeader(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptionHeader)
		this->_Inst_EncryptionHeader = new TElOfficeEncryptionHeader(hOutResult, ohFalse);
	else
		this->_Inst_EncryptionHeader->updateHandle(hOutResult);
	return this->_Inst_EncryptionHeader;
}

SB_INLINE void TElOfficeEncryptionInfoV2::set_EncryptionHeader(TElOfficeEncryptionHeader &Value)
{
	SBCheckError(TElOfficeEncryptionInfoV2_set_EncryptionHeader(_Handle, Value.getHandle()));
}

SB_INLINE void TElOfficeEncryptionInfoV2::set_EncryptionHeader(TElOfficeEncryptionHeader *Value)
{
	SBCheckError(TElOfficeEncryptionInfoV2_set_EncryptionHeader(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOFFICEENCRYPTIONHEADER */

#ifdef SB_USE_CLASS_TELOFFICEENCRYPTIONVERIFIER
TElOfficeEncryptionVerifier* TElOfficeEncryptionInfoV2::get_EncryptionVerifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeEncryptionInfoV2_get_EncryptionVerifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptionVerifier)
		this->_Inst_EncryptionVerifier = new TElOfficeEncryptionVerifier(hOutResult, ohFalse);
	else
		this->_Inst_EncryptionVerifier->updateHandle(hOutResult);
	return this->_Inst_EncryptionVerifier;
}

SB_INLINE void TElOfficeEncryptionInfoV2::set_EncryptionVerifier(TElOfficeEncryptionVerifier &Value)
{
	SBCheckError(TElOfficeEncryptionInfoV2_set_EncryptionVerifier(_Handle, Value.getHandle()));
}

SB_INLINE void TElOfficeEncryptionInfoV2::set_EncryptionVerifier(TElOfficeEncryptionVerifier *Value)
{
	SBCheckError(TElOfficeEncryptionInfoV2_set_EncryptionVerifier(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOFFICEENCRYPTIONVERIFIER */

void TElOfficeEncryptionInfoV2::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEENCRYPTIONHEADER
	this->_Inst_EncryptionHeader = NULL;
#endif /* SB_USE_CLASS_TELOFFICEENCRYPTIONHEADER */
#ifdef SB_USE_CLASS_TELOFFICEENCRYPTIONVERIFIER
	this->_Inst_EncryptionVerifier = NULL;
#endif /* SB_USE_CLASS_TELOFFICEENCRYPTIONVERIFIER */
}

TElOfficeEncryptionInfoV2::TElOfficeEncryptionInfoV2(TElOfficeEncryptionInfoV2Handle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
	initInstances();
}

TElOfficeEncryptionInfoV2::TElOfficeEncryptionInfoV2() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeEncryptionInfoV2_Create(&_Handle));
}

TElOfficeEncryptionInfoV2::~TElOfficeEncryptionInfoV2()
{
#ifdef SB_USE_CLASS_TELOFFICEENCRYPTIONHEADER
	delete this->_Inst_EncryptionHeader;
	this->_Inst_EncryptionHeader = NULL;
#endif /* SB_USE_CLASS_TELOFFICEENCRYPTIONHEADER */
#ifdef SB_USE_CLASS_TELOFFICEENCRYPTIONVERIFIER
	delete this->_Inst_EncryptionVerifier;
	this->_Inst_EncryptionVerifier = NULL;
#endif /* SB_USE_CLASS_TELOFFICEENCRYPTIONVERIFIER */
}
#endif /* SB_USE_CLASS_TELOFFICEENCRYPTIONINFOV2 */

#ifdef SB_USE_CLASS_TELOFFICEENCRYPTIONINFOV3

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeEncryptionInfoV3::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeEncryptionInfoV3_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeEncryptionInfoV3::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeEncryptionInfoV3_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeEncryptionInfoV3::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeEncryptionInfoV3_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeEncryptionInfoV3::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeEncryptionInfoV3_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE uint32_t TElOfficeEncryptionInfoV3::get_EncryptionHeaderFlags()
{
	uint32_t OutResult;
	SBCheckError(TElOfficeEncryptionInfoV3_get_EncryptionHeaderFlags(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeEncryptionInfoV3::set_EncryptionHeaderFlags(uint32_t Value)
{
	SBCheckError(TElOfficeEncryptionInfoV3_set_EncryptionHeaderFlags(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELOFFICEENCRYPTIONHEADER
TElOfficeEncryptionHeader* TElOfficeEncryptionInfoV3::get_EncryptionHeader()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeEncryptionInfoV3_get_EncryptionHeader(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptionHeader)
		this->_Inst_EncryptionHeader = new TElOfficeEncryptionHeader(hOutResult, ohFalse);
	else
		this->_Inst_EncryptionHeader->updateHandle(hOutResult);
	return this->_Inst_EncryptionHeader;
}

SB_INLINE void TElOfficeEncryptionInfoV3::set_EncryptionHeader(TElOfficeEncryptionHeader &Value)
{
	SBCheckError(TElOfficeEncryptionInfoV3_set_EncryptionHeader(_Handle, Value.getHandle()));
}

SB_INLINE void TElOfficeEncryptionInfoV3::set_EncryptionHeader(TElOfficeEncryptionHeader *Value)
{
	SBCheckError(TElOfficeEncryptionInfoV3_set_EncryptionHeader(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOFFICEENCRYPTIONHEADER */

void TElOfficeEncryptionInfoV3::get_EncryptionInfo(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeEncryptionInfoV3_get_EncryptionInfo(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(145205616, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeEncryptionInfoV3::get_EncryptionInfo(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeEncryptionInfoV3_get_EncryptionInfo(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(145205616, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeEncryptionInfoV3::set_EncryptionInfo(const sb_u16string &Value)
{
	SBCheckError(TElOfficeEncryptionInfoV3_set_EncryptionInfo(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeEncryptionInfoV3::set_EncryptionInfo(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeEncryptionInfoV3_set_EncryptionInfo(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeEncryptionInfoV3::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEENCRYPTIONHEADER
	this->_Inst_EncryptionHeader = NULL;
#endif /* SB_USE_CLASS_TELOFFICEENCRYPTIONHEADER */
}

TElOfficeEncryptionInfoV3::TElOfficeEncryptionInfoV3(TElOfficeEncryptionInfoV3Handle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
	initInstances();
}

TElOfficeEncryptionInfoV3::TElOfficeEncryptionInfoV3() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeEncryptionInfoV3_Create(&_Handle));
}

TElOfficeEncryptionInfoV3::~TElOfficeEncryptionInfoV3()
{
#ifdef SB_USE_CLASS_TELOFFICEENCRYPTIONHEADER
	delete this->_Inst_EncryptionHeader;
	this->_Inst_EncryptionHeader = NULL;
#endif /* SB_USE_CLASS_TELOFFICEENCRYPTIONHEADER */
}
#endif /* SB_USE_CLASS_TELOFFICEENCRYPTIONINFOV3 */

#ifdef SB_USE_CLASS_TELOFFICEENCRYPTIONINFOV4

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeEncryptionInfoV4::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeEncryptionInfoV4_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeEncryptionInfoV4::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeEncryptionInfoV4_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeEncryptionInfoV4::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeEncryptionInfoV4_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeEncryptionInfoV4::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeEncryptionInfoV4_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElOfficeEncryptionInfoV4::get_XmlEncryptionDescriptor(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeEncryptionInfoV4_get_XmlEncryptionDescriptor(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1224412850, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeEncryptionInfoV4::set_XmlEncryptionDescriptor(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeEncryptionInfoV4_set_XmlEncryptionDescriptor(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElOfficeEncryptionInfoV4::TElOfficeEncryptionInfoV4(TElOfficeEncryptionInfoV4Handle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficeEncryptionInfoV4::TElOfficeEncryptionInfoV4() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeEncryptionInfoV4_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEENCRYPTIONINFOV4 */

#ifdef SB_USE_CLASS_TELOFFICEXOROBFUSCATION

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeXORObfuscation::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeXORObfuscation_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeXORObfuscation::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeXORObfuscation_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeXORObfuscation::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeXORObfuscation_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeXORObfuscation::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeXORObfuscation_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE uint16_t TElOfficeXORObfuscation::get_Key()
{
	uint16_t OutResult;
	SBCheckError(TElOfficeXORObfuscation_get_Key(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXORObfuscation::set_Key(uint16_t Value)
{
	SBCheckError(TElOfficeXORObfuscation_set_Key(_Handle, Value));
}

SB_INLINE uint16_t TElOfficeXORObfuscation::get_VerificationBytes()
{
	uint16_t OutResult;
	SBCheckError(TElOfficeXORObfuscation_get_VerificationBytes(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXORObfuscation::set_VerificationBytes(uint16_t Value)
{
	SBCheckError(TElOfficeXORObfuscation_set_VerificationBytes(_Handle, Value));
}

TElOfficeXORObfuscation::TElOfficeXORObfuscation(TElOfficeXORObfuscationHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficeXORObfuscation::TElOfficeXORObfuscation() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeXORObfuscation_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEXOROBFUSCATION */

#ifdef SB_USE_CLASS_TELOFFICEENCRYPTEDSTREAMDESCRIPTOR

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeEncryptedStreamDescriptor::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeEncryptedStreamDescriptor_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeEncryptedStreamDescriptor::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeEncryptedStreamDescriptor_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeEncryptedStreamDescriptor::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeEncryptedStreamDescriptor_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeEncryptedStreamDescriptor::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeEncryptedStreamDescriptor_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElOfficeEncryptedStreamDescriptor::get_StreamName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeEncryptedStreamDescriptor_get_StreamName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(2134018760, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeEncryptedStreamDescriptor::get_StreamName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeEncryptedStreamDescriptor_get_StreamName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(2134018760, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeEncryptedStreamDescriptor::set_StreamName(const sb_u16string &Value)
{
	SBCheckError(TElOfficeEncryptedStreamDescriptor_set_StreamName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeEncryptedStreamDescriptor::set_StreamName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeEncryptedStreamDescriptor_set_StreamName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE uint32_t TElOfficeEncryptedStreamDescriptor::get_StreamOffset()
{
	uint32_t OutResult;
	SBCheckError(TElOfficeEncryptedStreamDescriptor_get_StreamOffset(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeEncryptedStreamDescriptor::set_StreamOffset(uint32_t Value)
{
	SBCheckError(TElOfficeEncryptedStreamDescriptor_set_StreamOffset(_Handle, Value));
}

SB_INLINE uint32_t TElOfficeEncryptedStreamDescriptor::get_StreamSize()
{
	uint32_t OutResult;
	SBCheckError(TElOfficeEncryptedStreamDescriptor_get_StreamSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeEncryptedStreamDescriptor::set_StreamSize(uint32_t Value)
{
	SBCheckError(TElOfficeEncryptedStreamDescriptor_set_StreamSize(_Handle, Value));
}

SB_INLINE uint16_t TElOfficeEncryptedStreamDescriptor::get_Block()
{
	uint16_t OutResult;
	SBCheckError(TElOfficeEncryptedStreamDescriptor_get_Block(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeEncryptedStreamDescriptor::set_Block(uint16_t Value)
{
	SBCheckError(TElOfficeEncryptedStreamDescriptor_set_Block(_Handle, Value));
}

SB_INLINE uint8_t TElOfficeEncryptedStreamDescriptor::get_Flags()
{
	uint8_t OutResult;
	SBCheckError(TElOfficeEncryptedStreamDescriptor_get_Flags(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeEncryptedStreamDescriptor::set_Flags(uint8_t Value)
{
	SBCheckError(TElOfficeEncryptedStreamDescriptor_set_Flags(_Handle, Value));
}

TElOfficeEncryptedStreamDescriptor::TElOfficeEncryptedStreamDescriptor(TElOfficeEncryptedStreamDescriptorHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficeEncryptedStreamDescriptor::TElOfficeEncryptedStreamDescriptor() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeEncryptedStreamDescriptor_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEENCRYPTEDSTREAMDESCRIPTOR */

#ifdef SB_USE_CLASS_TELOFFICECERTIFICATEINFO

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeCertificateInfo::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeCertificateInfo_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeCertificateInfo::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeCertificateInfo_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeCertificateInfo::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeCertificateInfo_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeCertificateInfo::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeCertificateInfo_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
SB_INLINE void TElOfficeCertificateInfo::get_ExpireTime(windows_FILETIME &OutResult)
#else
SB_INLINE void TElOfficeCertificateInfo::get_ExpireTime(_FILETIME &OutResult)
#endif
{
	SBCheckError(TElOfficeCertificateInfo_get_ExpireTime(_Handle, &OutResult));
}

#ifdef SB_WINDOWS
SB_INLINE void TElOfficeCertificateInfo::set_ExpireTime(windows_FILETIME &Value)
#else
SB_INLINE void TElOfficeCertificateInfo::set_ExpireTime(_FILETIME &Value)
#endif
{
	SBCheckError(TElOfficeCertificateInfo_set_ExpireTime(_Handle, &Value));
}

#ifdef SB_WINDOWS
SB_INLINE void TElOfficeCertificateInfo::get_SignTime(windows_FILETIME &OutResult)
#else
SB_INLINE void TElOfficeCertificateInfo::get_SignTime(_FILETIME &OutResult)
#endif
{
	SBCheckError(TElOfficeCertificateInfo_get_SignTime(_Handle, &OutResult));
}

#ifdef SB_WINDOWS
SB_INLINE void TElOfficeCertificateInfo::set_SignTime(windows_FILETIME &Value)
#else
SB_INLINE void TElOfficeCertificateInfo::set_SignTime(_FILETIME &Value)
#endif
{
	SBCheckError(TElOfficeCertificateInfo_set_SignTime(_Handle, &Value));
}

SB_INLINE int32_t TElOfficeCertificateInfo::get_AlgIDHash()
{
	int32_t OutResult;
	SBCheckError(TElOfficeCertificateInfo_get_AlgIDHash(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeCertificateInfo::set_AlgIDHash(int32_t Value)
{
	SBCheckError(TElOfficeCertificateInfo_set_AlgIDHash(_Handle, Value));
}

void TElOfficeCertificateInfo::get_SignerName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeCertificateInfo_get_SignerName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(80889531, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeCertificateInfo::get_SignerName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeCertificateInfo_get_SignerName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(80889531, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeCertificateInfo::set_SignerName(const sb_u16string &Value)
{
	SBCheckError(TElOfficeCertificateInfo_set_SignerName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeCertificateInfo::set_SignerName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeCertificateInfo_set_SignerName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeCertificateInfo::get_IssuerName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeCertificateInfo_get_IssuerName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1869059952, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeCertificateInfo::get_IssuerName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeCertificateInfo_get_IssuerName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1869059952, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeCertificateInfo::set_IssuerName(const sb_u16string &Value)
{
	SBCheckError(TElOfficeCertificateInfo_set_IssuerName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeCertificateInfo::set_IssuerName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeCertificateInfo_set_IssuerName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeCertificateInfo::get_Signature(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeCertificateInfo_get_Signature(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1635675090, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeCertificateInfo::set_Signature(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeCertificateInfo_set_Signature(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElOfficeCertificateInfo::get_EncodedCertificate(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeCertificateInfo_get_EncodedCertificate(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1560605152, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeCertificateInfo::set_EncodedCertificate(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeCertificateInfo_set_EncodedCertificate(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElOfficeCertificateInfo::get_SerialNumber(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeCertificateInfo_get_SerialNumber(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1300798470, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeCertificateInfo::set_SerialNumber(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeCertificateInfo_set_SerialNumber(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElOfficeCertificateInfo::get_IssuerBlob(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeCertificateInfo_get_IssuerBlob(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2126820186, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeCertificateInfo::set_IssuerBlob(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeCertificateInfo_set_IssuerBlob(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElOfficeCertificateInfo::TElOfficeCertificateInfo(TElOfficeCertificateInfoHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficeCertificateInfo::TElOfficeCertificateInfo() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeCertificateInfo_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICECERTIFICATEINFO */

#ifdef SB_USE_CLASS_TELOFFICECERTSTORECERTIFICATEGROUP

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeCertStoreCertificateGroup::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeCertStoreCertificateGroup_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeCertStoreCertificateGroup::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeCertStoreCertificateGroup_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeCertStoreCertificateGroup::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeCertStoreCertificateGroup_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeCertStoreCertificateGroup::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeCertStoreCertificateGroup_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElOfficeCertStoreCertificateGroup::get_CertificateData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeCertStoreCertificateGroup_get_CertificateData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(246815794, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeCertStoreCertificateGroup::set_CertificateData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeCertStoreCertificateGroup_set_CertificateData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE uint32_t TElOfficeCertStoreCertificateGroup::get_EncodingType()
{
	uint32_t OutResult;
	SBCheckError(TElOfficeCertStoreCertificateGroup_get_EncodingType(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeCertStoreCertificateGroup::set_EncodingType(uint32_t Value)
{
	SBCheckError(TElOfficeCertStoreCertificateGroup_set_EncodingType(_Handle, Value));
}

TElOfficeCertStoreCertificateGroup::TElOfficeCertStoreCertificateGroup(TElOfficeCertStoreCertificateGroupHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficeCertStoreCertificateGroup::TElOfficeCertStoreCertificateGroup() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeCertStoreCertificateGroup_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICECERTSTORECERTIFICATEGROUP */

#ifdef SB_USE_CLASS_TELOFFICEDOCSIGSERIALIZEDCERTSTORE

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeDocSigSerializedCertStore::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeDocSigSerializedCertStore_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeDocSigSerializedCertStore::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeDocSigSerializedCertStore_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeDocSigSerializedCertStore::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeDocSigSerializedCertStore_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeDocSigSerializedCertStore::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeDocSigSerializedCertStore_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElOfficeDocSigSerializedCertStore::Clear()
{
	SBCheckError(TElOfficeDocSigSerializedCertStore_Clear(_Handle));
}

SB_INLINE int32_t TElOfficeDocSigSerializedCertStore::AddCertificate(const std::vector<uint8_t> &Buf)
{
	int32_t OutResult;
	SBCheckError(TElOfficeDocSigSerializedCertStore_AddCertificate(_Handle, SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICECERTSTORECERTIFICATEGROUP
SB_INLINE int32_t TElOfficeDocSigSerializedCertStore::AddCertificate(TElOfficeCertStoreCertificateGroup &Cert)
{
	int32_t OutResult;
	SBCheckError(TElOfficeDocSigSerializedCertStore_AddCertificate_1(_Handle, Cert.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeDocSigSerializedCertStore::AddCertificate(TElOfficeCertStoreCertificateGroup *Cert)
{
	int32_t OutResult;
	SBCheckError(TElOfficeDocSigSerializedCertStore_AddCertificate_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICECERTSTORECERTIFICATEGROUP */

#ifdef SB_USE_CLASS_TELOFFICECERTSTORECERTIFICATEGROUP
SB_INLINE void TElOfficeDocSigSerializedCertStore::InsertCertificate(int32_t Index, TElOfficeCertStoreCertificateGroup &Cert)
{
	SBCheckError(TElOfficeDocSigSerializedCertStore_InsertCertificate(_Handle, Index, Cert.getHandle()));
}

SB_INLINE void TElOfficeDocSigSerializedCertStore::InsertCertificate(int32_t Index, TElOfficeCertStoreCertificateGroup *Cert)
{
	SBCheckError(TElOfficeDocSigSerializedCertStore_InsertCertificate(_Handle, Index, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOFFICECERTSTORECERTIFICATEGROUP */

SB_INLINE void TElOfficeDocSigSerializedCertStore::DeleteCertificate(int32_t Index)
{
	SBCheckError(TElOfficeDocSigSerializedCertStore_DeleteCertificate(_Handle, Index));
}

SB_INLINE int32_t TElOfficeDocSigSerializedCertStore::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElOfficeDocSigSerializedCertStore_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICECERTSTORECERTIFICATEGROUP
TElOfficeCertStoreCertificateGroup* TElOfficeDocSigSerializedCertStore::get_Certificates(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeDocSigSerializedCertStore_get_Certificates(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElOfficeCertStoreCertificateGroup(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}
#endif /* SB_USE_CLASS_TELOFFICECERTSTORECERTIFICATEGROUP */

void TElOfficeDocSigSerializedCertStore::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICECERTSTORECERTIFICATEGROUP
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELOFFICECERTSTORECERTIFICATEGROUP */
}

TElOfficeDocSigSerializedCertStore::TElOfficeDocSigSerializedCertStore(TElOfficeDocSigSerializedCertStoreHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
	initInstances();
}

TElOfficeDocSigSerializedCertStore::TElOfficeDocSigSerializedCertStore() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeDocSigSerializedCertStore_Create(&_Handle));
}

TElOfficeDocSigSerializedCertStore::~TElOfficeDocSigSerializedCertStore()
{
#ifdef SB_USE_CLASS_TELOFFICECERTSTORECERTIFICATEGROUP
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELOFFICECERTSTORECERTIFICATEGROUP */
}
#endif /* SB_USE_CLASS_TELOFFICEDOCSIGSERIALIZEDCERTSTORE */

#ifdef SB_USE_CLASS_TELOFFICECRYPTOAPIDIGITALSIGNATURE

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeCryptoAPIDigitalSignature::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeCryptoAPIDigitalSignature_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeCryptoAPIDigitalSignature::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeCryptoAPIDigitalSignature_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeCryptoAPIDigitalSignature::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeCryptoAPIDigitalSignature_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeCryptoAPIDigitalSignature::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeCryptoAPIDigitalSignature_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElOfficeCryptoAPIDigitalSignature::Clear()
{
	SBCheckError(TElOfficeCryptoAPIDigitalSignature_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELOFFICECERTIFICATEINFO
SB_INLINE int32_t TElOfficeCryptoAPIDigitalSignature::AddCertificateInfo(TElOfficeCertificateInfo &CertInfo)
{
	int32_t OutResult;
	SBCheckError(TElOfficeCryptoAPIDigitalSignature_AddCertificateInfo(_Handle, CertInfo.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeCryptoAPIDigitalSignature::AddCertificateInfo(TElOfficeCertificateInfo *CertInfo)
{
	int32_t OutResult;
	SBCheckError(TElOfficeCryptoAPIDigitalSignature_AddCertificateInfo(_Handle, (CertInfo != NULL) ? CertInfo->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICECERTIFICATEINFO */

#ifdef SB_USE_CLASS_TELOFFICECERTIFICATEINFO
SB_INLINE void TElOfficeCryptoAPIDigitalSignature::InsertCertificateInfo(int32_t Index, TElOfficeCertificateInfo &CertInfo)
{
	SBCheckError(TElOfficeCryptoAPIDigitalSignature_InsertCertificateInfo(_Handle, Index, CertInfo.getHandle()));
}

SB_INLINE void TElOfficeCryptoAPIDigitalSignature::InsertCertificateInfo(int32_t Index, TElOfficeCertificateInfo *CertInfo)
{
	SBCheckError(TElOfficeCryptoAPIDigitalSignature_InsertCertificateInfo(_Handle, Index, (CertInfo != NULL) ? CertInfo->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOFFICECERTIFICATEINFO */

SB_INLINE void TElOfficeCryptoAPIDigitalSignature::DeleteCertificateInfo(int32_t Index)
{
	SBCheckError(TElOfficeCryptoAPIDigitalSignature_DeleteCertificateInfo(_Handle, Index));
}

SB_INLINE int32_t TElOfficeCryptoAPIDigitalSignature::get_CertificateInfoCount()
{
	int32_t OutResult;
	SBCheckError(TElOfficeCryptoAPIDigitalSignature_get_CertificateInfoCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICECERTIFICATEINFO
TElOfficeCertificateInfo* TElOfficeCryptoAPIDigitalSignature::get_CertificateInfos(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeCryptoAPIDigitalSignature_get_CertificateInfos(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertificateInfos)
		this->_Inst_CertificateInfos = new TElOfficeCertificateInfo(hOutResult, ohFalse);
	else
		this->_Inst_CertificateInfos->updateHandle(hOutResult);
	return this->_Inst_CertificateInfos;
}
#endif /* SB_USE_CLASS_TELOFFICECERTIFICATEINFO */

#ifdef SB_USE_CLASS_TELOFFICEDOCSIGSERIALIZEDCERTSTORE
TElOfficeDocSigSerializedCertStore* TElOfficeCryptoAPIDigitalSignature::get_IntermediateCertificatesStore()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeCryptoAPIDigitalSignature_get_IntermediateCertificatesStore(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IntermediateCertificatesStore)
		this->_Inst_IntermediateCertificatesStore = new TElOfficeDocSigSerializedCertStore(hOutResult, ohFalse);
	else
		this->_Inst_IntermediateCertificatesStore->updateHandle(hOutResult);
	return this->_Inst_IntermediateCertificatesStore;
}
#endif /* SB_USE_CLASS_TELOFFICEDOCSIGSERIALIZEDCERTSTORE */

void TElOfficeCryptoAPIDigitalSignature::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICECERTIFICATEINFO
	this->_Inst_CertificateInfos = NULL;
#endif /* SB_USE_CLASS_TELOFFICECERTIFICATEINFO */
#ifdef SB_USE_CLASS_TELOFFICEDOCSIGSERIALIZEDCERTSTORE
	this->_Inst_IntermediateCertificatesStore = NULL;
#endif /* SB_USE_CLASS_TELOFFICEDOCSIGSERIALIZEDCERTSTORE */
}

TElOfficeCryptoAPIDigitalSignature::TElOfficeCryptoAPIDigitalSignature(TElOfficeCryptoAPIDigitalSignatureHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
	initInstances();
}

TElOfficeCryptoAPIDigitalSignature::TElOfficeCryptoAPIDigitalSignature() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeCryptoAPIDigitalSignature_Create(&_Handle));
}

TElOfficeCryptoAPIDigitalSignature::~TElOfficeCryptoAPIDigitalSignature()
{
#ifdef SB_USE_CLASS_TELOFFICECERTIFICATEINFO
	delete this->_Inst_CertificateInfos;
	this->_Inst_CertificateInfos = NULL;
#endif /* SB_USE_CLASS_TELOFFICECERTIFICATEINFO */
#ifdef SB_USE_CLASS_TELOFFICEDOCSIGSERIALIZEDCERTSTORE
	delete this->_Inst_IntermediateCertificatesStore;
	this->_Inst_IntermediateCertificatesStore = NULL;
#endif /* SB_USE_CLASS_TELOFFICEDOCSIGSERIALIZEDCERTSTORE */
}
#endif /* SB_USE_CLASS_TELOFFICECRYPTOAPIDIGITALSIGNATURE */

#ifdef SB_USE_CLASS_TELOFFICEWORDFIBBASE

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeWordFIBBase::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeWordFIBBase_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeWordFIBBase::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeWordFIBBase_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeWordFIBBase::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeWordFIBBase_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeWordFIBBase::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeWordFIBBase_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE uint16_t TElOfficeWordFIBBase::get_Ident()
{
	uint16_t OutResult;
	SBCheckError(TElOfficeWordFIBBase_get_Ident(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeWordFIBBase::set_Ident(uint16_t Value)
{
	SBCheckError(TElOfficeWordFIBBase_set_Ident(_Handle, Value));
}

SB_INLINE uint16_t TElOfficeWordFIBBase::get_FIB()
{
	uint16_t OutResult;
	SBCheckError(TElOfficeWordFIBBase_get_FIB(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeWordFIBBase::set_FIB(uint16_t Value)
{
	SBCheckError(TElOfficeWordFIBBase_set_FIB(_Handle, Value));
}

SB_INLINE uint16_t TElOfficeWordFIBBase::get_LID()
{
	uint16_t OutResult;
	SBCheckError(TElOfficeWordFIBBase_get_LID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeWordFIBBase::set_LID(uint16_t Value)
{
	SBCheckError(TElOfficeWordFIBBase_set_LID(_Handle, Value));
}

SB_INLINE uint16_t TElOfficeWordFIBBase::get_Next()
{
	uint16_t OutResult;
	SBCheckError(TElOfficeWordFIBBase_get_Next(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeWordFIBBase::set_Next(uint16_t Value)
{
	SBCheckError(TElOfficeWordFIBBase_set_Next(_Handle, Value));
}

SB_INLINE uint16_t TElOfficeWordFIBBase::get_Flags()
{
	uint16_t OutResult;
	SBCheckError(TElOfficeWordFIBBase_get_Flags(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeWordFIBBase::set_Flags(uint16_t Value)
{
	SBCheckError(TElOfficeWordFIBBase_set_Flags(_Handle, Value));
}

SB_INLINE uint16_t TElOfficeWordFIBBase::get_FibBack()
{
	uint16_t OutResult;
	SBCheckError(TElOfficeWordFIBBase_get_FibBack(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeWordFIBBase::set_FibBack(uint16_t Value)
{
	SBCheckError(TElOfficeWordFIBBase_set_FibBack(_Handle, Value));
}

SB_INLINE uint32_t TElOfficeWordFIBBase::get_Key()
{
	uint32_t OutResult;
	SBCheckError(TElOfficeWordFIBBase_get_Key(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeWordFIBBase::set_Key(uint32_t Value)
{
	SBCheckError(TElOfficeWordFIBBase_set_Key(_Handle, Value));
}

SB_INLINE uint8_t TElOfficeWordFIBBase::get_Flags2()
{
	uint8_t OutResult;
	SBCheckError(TElOfficeWordFIBBase_get_Flags2(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeWordFIBBase::set_Flags2(uint8_t Value)
{
	SBCheckError(TElOfficeWordFIBBase_set_Flags2(_Handle, Value));
}

TElOfficeWordFIBBase::TElOfficeWordFIBBase(TElOfficeWordFIBBaseHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficeWordFIBBase::TElOfficeWordFIBBase() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeWordFIBBase_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEWORDFIBBASE */

#ifdef SB_USE_CLASS_TELOFFICEWORDFIBRGFCLCB

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeWordFIBRgFcLcb::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeWordFIBRgFcLcb_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeWordFIBRgFcLcb::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeWordFIBRgFcLcb_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeWordFIBRgFcLcb::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeWordFIBRgFcLcb_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeWordFIBRgFcLcb::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeWordFIBRgFcLcb_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElOfficeWordFIBRgFcLcb::ChangeOffsets(int32_t Shift)
{
	SBCheckError(TElOfficeWordFIBRgFcLcb_ChangeOffsets(_Handle, Shift));
}

void TElOfficeWordFIBRgFcLcb::get_Blob(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeWordFIBRgFcLcb_get_Blob(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1504778513, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeWordFIBRgFcLcb::set_Blob(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeWordFIBRgFcLcb_set_Blob(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElOfficeWordFIBRgFcLcb::TElOfficeWordFIBRgFcLcb(TElOfficeWordFIBRgFcLcbHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficeWordFIBRgFcLcb::TElOfficeWordFIBRgFcLcb() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeWordFIBRgFcLcb_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEWORDFIBRGFCLCB */

#ifdef SB_USE_CLASS_TELOFFICEWORDFIB

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeWordFIB::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeWordFIB_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeWordFIB::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeWordFIB_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeWordFIB::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeWordFIB_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeWordFIB::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeWordFIB_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELOFFICEWORDFIBBASE
TElOfficeWordFIBBase* TElOfficeWordFIB::get_FIBBase()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeWordFIB_get_FIBBase(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FIBBase)
		this->_Inst_FIBBase = new TElOfficeWordFIBBase(hOutResult, ohFalse);
	else
		this->_Inst_FIBBase->updateHandle(hOutResult);
	return this->_Inst_FIBBase;
}
#endif /* SB_USE_CLASS_TELOFFICEWORDFIBBASE */

#ifdef SB_USE_CLASS_TELOFFICEWORDFIBRGFCLCB
TElOfficeWordFIBRgFcLcb* TElOfficeWordFIB::get_FIBRgFcLcb()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeWordFIB_get_FIBRgFcLcb(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FIBRgFcLcb)
		this->_Inst_FIBRgFcLcb = new TElOfficeWordFIBRgFcLcb(hOutResult, ohFalse);
	else
		this->_Inst_FIBRgFcLcb->updateHandle(hOutResult);
	return this->_Inst_FIBRgFcLcb;
}
#endif /* SB_USE_CLASS_TELOFFICEWORDFIBRGFCLCB */

void TElOfficeWordFIB::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEWORDFIBBASE
	this->_Inst_FIBBase = NULL;
#endif /* SB_USE_CLASS_TELOFFICEWORDFIBBASE */
#ifdef SB_USE_CLASS_TELOFFICEWORDFIBRGFCLCB
	this->_Inst_FIBRgFcLcb = NULL;
#endif /* SB_USE_CLASS_TELOFFICEWORDFIBRGFCLCB */
}

TElOfficeWordFIB::TElOfficeWordFIB(TElOfficeWordFIBHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
	initInstances();
}

TElOfficeWordFIB::TElOfficeWordFIB() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeWordFIB_Create(&_Handle));
}

TElOfficeWordFIB::~TElOfficeWordFIB()
{
#ifdef SB_USE_CLASS_TELOFFICEWORDFIBBASE
	delete this->_Inst_FIBBase;
	this->_Inst_FIBBase = NULL;
#endif /* SB_USE_CLASS_TELOFFICEWORDFIBBASE */
#ifdef SB_USE_CLASS_TELOFFICEWORDFIBRGFCLCB
	delete this->_Inst_FIBRgFcLcb;
	this->_Inst_FIBRgFcLcb = NULL;
#endif /* SB_USE_CLASS_TELOFFICEWORDFIBRGFCLCB */
}
#endif /* SB_USE_CLASS_TELOFFICEWORDFIB */

#ifdef SB_USE_CLASS_TELOFFICEWORKBOOKRECORDINFO

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeWorkbookRecordInfo::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeWorkbookRecordInfo_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeWorkbookRecordInfo::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeWorkbookRecordInfo_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeWorkbookRecordInfo::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeWorkbookRecordInfo_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeWorkbookRecordInfo::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeWorkbookRecordInfo_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE uint16_t TElOfficeWorkbookRecordInfo::get_RecordType()
{
	uint16_t OutResult;
	SBCheckError(TElOfficeWorkbookRecordInfo_get_RecordType(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeWorkbookRecordInfo::set_RecordType(uint16_t Value)
{
	SBCheckError(TElOfficeWorkbookRecordInfo_set_RecordType(_Handle, Value));
}

SB_INLINE uint16_t TElOfficeWorkbookRecordInfo::get_RecordSize()
{
	uint16_t OutResult;
	SBCheckError(TElOfficeWorkbookRecordInfo_get_RecordSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeWorkbookRecordInfo::set_RecordSize(uint16_t Value)
{
	SBCheckError(TElOfficeWorkbookRecordInfo_set_RecordSize(_Handle, Value));
}

TElOfficeWorkbookRecordInfo::TElOfficeWorkbookRecordInfo(TElOfficeWorkbookRecordInfoHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficeWorkbookRecordInfo::TElOfficeWorkbookRecordInfo() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeWorkbookRecordInfo_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEWORKBOOKRECORDINFO */

#ifdef SB_USE_CLASS_TELOFFICEWORKBOOKBOF

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeWorkbookBOF::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeWorkbookBOF_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeWorkbookBOF::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeWorkbookBOF_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeWorkbookBOF::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeWorkbookBOF_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeWorkbookBOF::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeWorkbookBOF_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE uint16_t TElOfficeWorkbookBOF::get_Version()
{
	uint16_t OutResult;
	SBCheckError(TElOfficeWorkbookBOF_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeWorkbookBOF::set_Version(uint16_t Value)
{
	SBCheckError(TElOfficeWorkbookBOF_set_Version(_Handle, Value));
}

SB_INLINE uint16_t TElOfficeWorkbookBOF::get_DocumentType()
{
	uint16_t OutResult;
	SBCheckError(TElOfficeWorkbookBOF_get_DocumentType(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeWorkbookBOF::set_DocumentType(uint16_t Value)
{
	SBCheckError(TElOfficeWorkbookBOF_set_DocumentType(_Handle, Value));
}

SB_INLINE uint16_t TElOfficeWorkbookBOF::get_RupBuild()
{
	uint16_t OutResult;
	SBCheckError(TElOfficeWorkbookBOF_get_RupBuild(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeWorkbookBOF::set_RupBuild(uint16_t Value)
{
	SBCheckError(TElOfficeWorkbookBOF_set_RupBuild(_Handle, Value));
}

SB_INLINE uint16_t TElOfficeWorkbookBOF::get_RupYear()
{
	uint16_t OutResult;
	SBCheckError(TElOfficeWorkbookBOF_get_RupYear(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeWorkbookBOF::set_RupYear(uint16_t Value)
{
	SBCheckError(TElOfficeWorkbookBOF_set_RupYear(_Handle, Value));
}

SB_INLINE uint32_t TElOfficeWorkbookBOF::get_Flags()
{
	uint32_t OutResult;
	SBCheckError(TElOfficeWorkbookBOF_get_Flags(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeWorkbookBOF::set_Flags(uint32_t Value)
{
	SBCheckError(TElOfficeWorkbookBOF_set_Flags(_Handle, Value));
}

SB_INLINE uint8_t TElOfficeWorkbookBOF::get_VersionLowestBiff()
{
	uint8_t OutResult;
	SBCheckError(TElOfficeWorkbookBOF_get_VersionLowestBiff(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeWorkbookBOF::set_VersionLowestBiff(uint8_t Value)
{
	SBCheckError(TElOfficeWorkbookBOF_set_VersionLowestBiff(_Handle, Value));
}

SB_INLINE uint8_t TElOfficeWorkbookBOF::get_VersionLastXLSaved()
{
	uint8_t OutResult;
	SBCheckError(TElOfficeWorkbookBOF_get_VersionLastXLSaved(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeWorkbookBOF::set_VersionLastXLSaved(uint8_t Value)
{
	SBCheckError(TElOfficeWorkbookBOF_set_VersionLastXLSaved(_Handle, Value));
}

TElOfficeWorkbookBOF::TElOfficeWorkbookBOF(TElOfficeWorkbookBOFHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficeWorkbookBOF::TElOfficeWorkbookBOF() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeWorkbookBOF_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEWORKBOOKBOF */

#ifdef SB_USE_CLASS_TELOFFICEWORKBOOKFILEPASS

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeWorkbookFilePass::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficeWorkbookFilePass_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeWorkbookFilePass::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficeWorkbookFilePass_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeWorkbookFilePass::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficeWorkbookFilePass_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeWorkbookFilePass::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficeWorkbookFilePass_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE uint16_t TElOfficeWorkbookFilePass::get_EncryptionType()
{
	uint16_t OutResult;
	SBCheckError(TElOfficeWorkbookFilePass_get_EncryptionType(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeWorkbookFilePass::set_EncryptionType(uint16_t Value)
{
	SBCheckError(TElOfficeWorkbookFilePass_set_EncryptionType(_Handle, Value));
}

TElOfficeWorkbookFilePass::TElOfficeWorkbookFilePass(TElOfficeWorkbookFilePassHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficeWorkbookFilePass::TElOfficeWorkbookFilePass() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeWorkbookFilePass_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEWORKBOOKFILEPASS */

#ifdef SB_USE_CLASS_TELOFFICEPOWERPOINTRECORDHEADER

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficePowerPointRecordHeader::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficePowerPointRecordHeader_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficePowerPointRecordHeader::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficePowerPointRecordHeader_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficePowerPointRecordHeader::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficePowerPointRecordHeader_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficePowerPointRecordHeader::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficePowerPointRecordHeader_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE uint8_t TElOfficePowerPointRecordHeader::get_RecordVersion()
{
	uint8_t OutResult;
	SBCheckError(TElOfficePowerPointRecordHeader_get_RecordVersion(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficePowerPointRecordHeader::set_RecordVersion(uint8_t Value)
{
	SBCheckError(TElOfficePowerPointRecordHeader_set_RecordVersion(_Handle, Value));
}

SB_INLINE uint16_t TElOfficePowerPointRecordHeader::get_RecordInstance()
{
	uint16_t OutResult;
	SBCheckError(TElOfficePowerPointRecordHeader_get_RecordInstance(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficePowerPointRecordHeader::set_RecordInstance(uint16_t Value)
{
	SBCheckError(TElOfficePowerPointRecordHeader_set_RecordInstance(_Handle, Value));
}

SB_INLINE uint16_t TElOfficePowerPointRecordHeader::get_RecordType()
{
	uint16_t OutResult;
	SBCheckError(TElOfficePowerPointRecordHeader_get_RecordType(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficePowerPointRecordHeader::set_RecordType(uint16_t Value)
{
	SBCheckError(TElOfficePowerPointRecordHeader_set_RecordType(_Handle, Value));
}

SB_INLINE uint32_t TElOfficePowerPointRecordHeader::get_RecordLength()
{
	uint32_t OutResult;
	SBCheckError(TElOfficePowerPointRecordHeader_get_RecordLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficePowerPointRecordHeader::set_RecordLength(uint32_t Value)
{
	SBCheckError(TElOfficePowerPointRecordHeader_set_RecordLength(_Handle, Value));
}

TElOfficePowerPointRecordHeader::TElOfficePowerPointRecordHeader(TElOfficePowerPointRecordHeaderHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficePowerPointRecordHeader::TElOfficePowerPointRecordHeader() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficePowerPointRecordHeader_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEPOWERPOINTRECORDHEADER */

#ifdef SB_USE_CLASS_TELOFFICEPOWERPOINTUSEREDITATOM

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficePowerPointUserEditAtom::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficePowerPointUserEditAtom_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficePowerPointUserEditAtom::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficePowerPointUserEditAtom_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficePowerPointUserEditAtom::LoadFromStream(TStream &Stream, uint32_t RecordSize)
{
	SBCheckError(TElOfficePowerPointUserEditAtom_LoadFromStream_1(_Handle, Stream.getHandle(), RecordSize));
}

SB_INLINE void TElOfficePowerPointUserEditAtom::LoadFromStream(TStream *Stream, uint32_t RecordSize)
{
	SBCheckError(TElOfficePowerPointUserEditAtom_LoadFromStream_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, RecordSize));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficePowerPointUserEditAtom::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficePowerPointUserEditAtom_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficePowerPointUserEditAtom::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficePowerPointUserEditAtom_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficePowerPointUserEditAtom::SaveToStream(TStream &Stream, bool IncludeEncryptSession)
{
	SBCheckError(TElOfficePowerPointUserEditAtom_SaveToStream_1(_Handle, Stream.getHandle(), (int8_t)IncludeEncryptSession));
}

SB_INLINE void TElOfficePowerPointUserEditAtom::SaveToStream(TStream *Stream, bool IncludeEncryptSession)
{
	SBCheckError(TElOfficePowerPointUserEditAtom_SaveToStream_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeEncryptSession));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE uint32_t TElOfficePowerPointUserEditAtom::get_LastSlideIdRef()
{
	uint32_t OutResult;
	SBCheckError(TElOfficePowerPointUserEditAtom_get_LastSlideIdRef(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficePowerPointUserEditAtom::set_LastSlideIdRef(uint32_t Value)
{
	SBCheckError(TElOfficePowerPointUserEditAtom_set_LastSlideIdRef(_Handle, Value));
}

SB_INLINE uint16_t TElOfficePowerPointUserEditAtom::get_Version()
{
	uint16_t OutResult;
	SBCheckError(TElOfficePowerPointUserEditAtom_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficePowerPointUserEditAtom::set_Version(uint16_t Value)
{
	SBCheckError(TElOfficePowerPointUserEditAtom_set_Version(_Handle, Value));
}

SB_INLINE uint8_t TElOfficePowerPointUserEditAtom::get_MinorVersion()
{
	uint8_t OutResult;
	SBCheckError(TElOfficePowerPointUserEditAtom_get_MinorVersion(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficePowerPointUserEditAtom::set_MinorVersion(uint8_t Value)
{
	SBCheckError(TElOfficePowerPointUserEditAtom_set_MinorVersion(_Handle, Value));
}

SB_INLINE uint8_t TElOfficePowerPointUserEditAtom::get_MajorVersion()
{
	uint8_t OutResult;
	SBCheckError(TElOfficePowerPointUserEditAtom_get_MajorVersion(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficePowerPointUserEditAtom::set_MajorVersion(uint8_t Value)
{
	SBCheckError(TElOfficePowerPointUserEditAtom_set_MajorVersion(_Handle, Value));
}

SB_INLINE uint32_t TElOfficePowerPointUserEditAtom::get_OffsetLastEdit()
{
	uint32_t OutResult;
	SBCheckError(TElOfficePowerPointUserEditAtom_get_OffsetLastEdit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficePowerPointUserEditAtom::set_OffsetLastEdit(uint32_t Value)
{
	SBCheckError(TElOfficePowerPointUserEditAtom_set_OffsetLastEdit(_Handle, Value));
}

SB_INLINE uint32_t TElOfficePowerPointUserEditAtom::get_OffsetPersistDirectory()
{
	uint32_t OutResult;
	SBCheckError(TElOfficePowerPointUserEditAtom_get_OffsetPersistDirectory(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficePowerPointUserEditAtom::set_OffsetPersistDirectory(uint32_t Value)
{
	SBCheckError(TElOfficePowerPointUserEditAtom_set_OffsetPersistDirectory(_Handle, Value));
}

SB_INLINE uint32_t TElOfficePowerPointUserEditAtom::get_DocPersistIdRef()
{
	uint32_t OutResult;
	SBCheckError(TElOfficePowerPointUserEditAtom_get_DocPersistIdRef(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficePowerPointUserEditAtom::set_DocPersistIdRef(uint32_t Value)
{
	SBCheckError(TElOfficePowerPointUserEditAtom_set_DocPersistIdRef(_Handle, Value));
}

SB_INLINE uint32_t TElOfficePowerPointUserEditAtom::get_PersistIdSeed()
{
	uint32_t OutResult;
	SBCheckError(TElOfficePowerPointUserEditAtom_get_PersistIdSeed(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficePowerPointUserEditAtom::set_PersistIdSeed(uint32_t Value)
{
	SBCheckError(TElOfficePowerPointUserEditAtom_set_PersistIdSeed(_Handle, Value));
}

SB_INLINE uint16_t TElOfficePowerPointUserEditAtom::get_LastView()
{
	uint16_t OutResult;
	SBCheckError(TElOfficePowerPointUserEditAtom_get_LastView(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficePowerPointUserEditAtom::set_LastView(uint16_t Value)
{
	SBCheckError(TElOfficePowerPointUserEditAtom_set_LastView(_Handle, Value));
}

SB_INLINE uint32_t TElOfficePowerPointUserEditAtom::get_EncryptSessionPersistIdRef()
{
	uint32_t OutResult;
	SBCheckError(TElOfficePowerPointUserEditAtom_get_EncryptSessionPersistIdRef(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficePowerPointUserEditAtom::set_EncryptSessionPersistIdRef(uint32_t Value)
{
	SBCheckError(TElOfficePowerPointUserEditAtom_set_EncryptSessionPersistIdRef(_Handle, Value));
}

TElOfficePowerPointUserEditAtom::TElOfficePowerPointUserEditAtom(TElOfficePowerPointUserEditAtomHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficePowerPointUserEditAtom::TElOfficePowerPointUserEditAtom() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficePowerPointUserEditAtom_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEPOWERPOINTUSEREDITATOM */

#ifdef SB_USE_CLASS_TELOFFICEPOWERPOINTPERSISTDIRECTORYENTRY

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficePowerPointPersistDirectoryEntry::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficePowerPointPersistDirectoryEntry_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficePowerPointPersistDirectoryEntry::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficePowerPointPersistDirectoryEntry_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficePowerPointPersistDirectoryEntry::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficePowerPointPersistDirectoryEntry_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficePowerPointPersistDirectoryEntry::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficePowerPointPersistDirectoryEntry_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE uint32_t TElOfficePowerPointPersistDirectoryEntry::get_PersistId()
{
	uint32_t OutResult;
	SBCheckError(TElOfficePowerPointPersistDirectoryEntry_get_PersistId(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficePowerPointPersistDirectoryEntry::set_PersistId(uint32_t Value)
{
	SBCheckError(TElOfficePowerPointPersistDirectoryEntry_set_PersistId(_Handle, Value));
}

void TElOfficePowerPointPersistDirectoryEntry::get_PersistOffsets(std::vector<uint32_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size() * 4;
	uint32_t _err = TElOfficePowerPointPersistDirectoryEntry_get_PersistOffsets(_Handle, (uint32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult / 4);
		SBCheckError(SBGetLastReturnBuffer(-70655360, 1, (uint32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult / 4);
}

SB_INLINE void TElOfficePowerPointPersistDirectoryEntry::set_PersistOffsets(const std::vector<uint32_t> &Value)
{
	SBCheckError(TElOfficePowerPointPersistDirectoryEntry_set_PersistOffsets(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElOfficePowerPointPersistDirectoryEntry::TElOfficePowerPointPersistDirectoryEntry(TElOfficePowerPointPersistDirectoryEntryHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
}

TElOfficePowerPointPersistDirectoryEntry::TElOfficePowerPointPersistDirectoryEntry() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficePowerPointPersistDirectoryEntry_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEPOWERPOINTPERSISTDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELOFFICEPOWERPOINTPERSISTDIRECTORYATOM

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficePowerPointPersistDirectoryAtom::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOfficePowerPointPersistDirectoryAtom_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficePowerPointPersistDirectoryAtom::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOfficePowerPointPersistDirectoryAtom_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficePowerPointPersistDirectoryAtom::LoadFromStream(TStream &Stream, uint32_t RecordSize)
{
	SBCheckError(TElOfficePowerPointPersistDirectoryAtom_LoadFromStream_1(_Handle, Stream.getHandle(), RecordSize));
}

SB_INLINE void TElOfficePowerPointPersistDirectoryAtom::LoadFromStream(TStream *Stream, uint32_t RecordSize)
{
	SBCheckError(TElOfficePowerPointPersistDirectoryAtom_LoadFromStream_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, RecordSize));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficePowerPointPersistDirectoryAtom::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOfficePowerPointPersistDirectoryAtom_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficePowerPointPersistDirectoryAtom::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOfficePowerPointPersistDirectoryAtom_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElOfficePowerPointPersistDirectoryAtom::Clear()
{
	SBCheckError(TElOfficePowerPointPersistDirectoryAtom_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELOFFICEPOWERPOINTPERSISTDIRECTORYENTRY
SB_INLINE int32_t TElOfficePowerPointPersistDirectoryAtom::Add(TElOfficePowerPointPersistDirectoryEntry &AEntry)
{
	int32_t OutResult;
	SBCheckError(TElOfficePowerPointPersistDirectoryAtom_Add(_Handle, AEntry.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficePowerPointPersistDirectoryAtom::Add(TElOfficePowerPointPersistDirectoryEntry *AEntry)
{
	int32_t OutResult;
	SBCheckError(TElOfficePowerPointPersistDirectoryAtom_Add(_Handle, (AEntry != NULL) ? AEntry->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICEPOWERPOINTPERSISTDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELOFFICEPOWERPOINTPERSISTDIRECTORYENTRY
SB_INLINE void TElOfficePowerPointPersistDirectoryAtom::Insert(int32_t Index, TElOfficePowerPointPersistDirectoryEntry &AEntry)
{
	SBCheckError(TElOfficePowerPointPersistDirectoryAtom_Insert(_Handle, Index, AEntry.getHandle()));
}

SB_INLINE void TElOfficePowerPointPersistDirectoryAtom::Insert(int32_t Index, TElOfficePowerPointPersistDirectoryEntry *AEntry)
{
	SBCheckError(TElOfficePowerPointPersistDirectoryAtom_Insert(_Handle, Index, (AEntry != NULL) ? AEntry->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOFFICEPOWERPOINTPERSISTDIRECTORYENTRY */

SB_INLINE void TElOfficePowerPointPersistDirectoryAtom::Delete(int32_t Index)
{
	SBCheckError(TElOfficePowerPointPersistDirectoryAtom_Delete(_Handle, Index));
}

SB_INLINE void TElOfficePowerPointPersistDirectoryAtom::AddPersistId(uint32_t PersistId, uint32_t Offset)
{
	SBCheckError(TElOfficePowerPointPersistDirectoryAtom_AddPersistId(_Handle, PersistId, Offset));
}

SB_INLINE uint32_t TElOfficePowerPointPersistDirectoryAtom::GetOffsetById(uint32_t PersistId)
{
	uint32_t OutResult;
	SBCheckError(TElOfficePowerPointPersistDirectoryAtom_GetOffsetById(_Handle, PersistId, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficePowerPointPersistDirectoryAtom::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElOfficePowerPointPersistDirectoryAtom_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICEPOWERPOINTPERSISTDIRECTORYENTRY
TElOfficePowerPointPersistDirectoryEntry* TElOfficePowerPointPersistDirectoryAtom::get_Entries(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficePowerPointPersistDirectoryAtom_get_Entries(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Entries)
		this->_Inst_Entries = new TElOfficePowerPointPersistDirectoryEntry(hOutResult, ohFalse);
	else
		this->_Inst_Entries->updateHandle(hOutResult);
	return this->_Inst_Entries;
}
#endif /* SB_USE_CLASS_TELOFFICEPOWERPOINTPERSISTDIRECTORYENTRY */

void TElOfficePowerPointPersistDirectoryAtom::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEPOWERPOINTPERSISTDIRECTORYENTRY
	this->_Inst_Entries = NULL;
#endif /* SB_USE_CLASS_TELOFFICEPOWERPOINTPERSISTDIRECTORYENTRY */
}

TElOfficePowerPointPersistDirectoryAtom::TElOfficePowerPointPersistDirectoryAtom(TElOfficePowerPointPersistDirectoryAtomHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryObject(handle, ownHandle)
{
	initInstances();
}

TElOfficePowerPointPersistDirectoryAtom::TElOfficePowerPointPersistDirectoryAtom() : TElOfficeBinaryObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficePowerPointPersistDirectoryAtom_Create(&_Handle));
}

TElOfficePowerPointPersistDirectoryAtom::~TElOfficePowerPointPersistDirectoryAtom()
{
#ifdef SB_USE_CLASS_TELOFFICEPOWERPOINTPERSISTDIRECTORYENTRY
	delete this->_Inst_Entries;
	this->_Inst_Entries = NULL;
#endif /* SB_USE_CLASS_TELOFFICEPOWERPOINTPERSISTDIRECTORYENTRY */
}
#endif /* SB_USE_CLASS_TELOFFICEPOWERPOINTPERSISTDIRECTORYATOM */

#ifdef SB_USE_GLOBAL_PROCS_OFFICEBINARYCORE

SB_INLINE int32_t BufferToInt32(const std::vector<uint8_t> &Buffer, int32_t Index)
{
	int32_t OutResult;
	SBCheckError(SBOfficeBinaryCore_BufferToInt32(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, &OutResult));
	return OutResult;
}

SB_INLINE int64_t BufferToInt64(const std::vector<uint8_t> &Buffer, int32_t Index)
{
	int64_t OutResult;
	SBCheckError(SBOfficeBinaryCore_BufferToInt64(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, &OutResult));
	return OutResult;
}

void Int32ToBuffer(std::vector<uint8_t> &Buffer, int32_t Index, int32_t Value)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBOfficeBinaryCore_Int32ToBuffer((uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Index, Value);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-1648009463, 0, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}

void UInt32ToBuffer(std::vector<uint8_t> &Buffer, int32_t Index, uint32_t Value)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBOfficeBinaryCore_UInt32ToBuffer((uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Index, Value);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-1628337707, 0, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}

void Int64ToBuffer(std::vector<uint8_t> &Buffer, int32_t Index, int64_t Value)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBOfficeBinaryCore_Int64ToBuffer((uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Index, Value);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(1933928979, 0, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}

#ifdef SB_WINDOWS
SB_INLINE void SwapTimeEncoding(windows_FILETIME &Value, windows_FILETIME &OutResult)
#else
SB_INLINE void SwapTimeEncoding(_FILETIME &Value, _FILETIME &OutResult)
#endif
{
	SBCheckError(SBOfficeBinaryCore_SwapTimeEncoding(&Value, &OutResult));
}

#endif /* SB_USE_GLOBAL_PROCS_OFFICEBINARYCORE */

};	/* namespace SecureBlackbox */
