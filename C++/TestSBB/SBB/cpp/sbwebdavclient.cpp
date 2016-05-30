#include "sbwebdavclient.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELWEBDAVCLIENT

#ifdef SB_USE_CLASS_TELWEBDAVOBJECTLIST
SB_INLINE void TElWebDAVClient::List(TElWebDavObjectList &Objects)
{
	SBCheckError(TElWebDAVClient_List(_Handle, Objects.getHandle()));
}

SB_INLINE void TElWebDAVClient::List(TElWebDavObjectList *Objects)
{
	SBCheckError(TElWebDAVClient_List(_Handle, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVOBJECTLIST */

#ifdef SB_USE_CLASS_TELWEBDAVOBJECTLIST
SB_INLINE void TElWebDAVClient::List(const std::string &URL, TElWebDavObjectList &Objects)
{
	SBCheckError(TElWebDAVClient_List_1(_Handle, URL.data(), (int32_t)URL.length(), Objects.getHandle()));
}

SB_INLINE void TElWebDAVClient::List(const std::string &URL, TElWebDavObjectList *Objects)
{
	SBCheckError(TElWebDAVClient_List_1(_Handle, URL.data(), (int32_t)URL.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVOBJECTLIST */

#ifdef SB_USE_CLASS_TELWEBDAVOBJECTLIST
SB_INLINE void TElWebDAVClient::List(const std::string &URL, TElWebDavObjectList &Objects, TSBWebDavDepth Depth)
{
	SBCheckError(TElWebDAVClient_List_2(_Handle, URL.data(), (int32_t)URL.length(), Objects.getHandle(), (TSBWebDavDepthRaw)Depth));
}

SB_INLINE void TElWebDAVClient::List(const std::string &URL, TElWebDavObjectList *Objects, TSBWebDavDepth Depth)
{
	SBCheckError(TElWebDAVClient_List_2(_Handle, URL.data(), (int32_t)URL.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, (TSBWebDavDepthRaw)Depth));
}
#endif /* SB_USE_CLASS_TELWEBDAVOBJECTLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVOBJECTLIST_AND_TELWEBDAVSTORAGEOBJECT
SB_INLINE void TElWebDAVClient::List(TElWebDAVStorageObject &Obj, TElWebDavObjectList &Objects)
{
	SBCheckError(TElWebDAVClient_List_3(_Handle, Obj.getHandle(), Objects.getHandle()));
}

SB_INLINE void TElWebDAVClient::List(TElWebDAVStorageObject *Obj, TElWebDavObjectList *Objects)
{
	SBCheckError(TElWebDAVClient_List_3(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVOBJECTLIST_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWEBDAVLOCKLIST
SB_INLINE void TElWebDAVClient::CreateCollection(const std::string &URL, TElWebDAVLockList &Locks)
{
	SBCheckError(TElWebDAVClient_CreateCollection(_Handle, URL.data(), (int32_t)URL.length(), Locks.getHandle()));
}

SB_INLINE void TElWebDAVClient::CreateCollection(const std::string &URL, TElWebDAVLockList *Locks)
{
	SBCheckError(TElWebDAVClient_CreateCollection(_Handle, URL.data(), (int32_t)URL.length(), (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT
SB_INLINE void TElWebDAVClient::CreateCollection(TElWebDAVStorageObject &Parent, const std::string &Name)
{
	SBCheckError(TElWebDAVClient_CreateCollection_1(_Handle, Parent.getHandle(), Name.data(), (int32_t)Name.length()));
}

SB_INLINE void TElWebDAVClient::CreateCollection(TElWebDAVStorageObject *Parent, const std::string &Name)
{
	SBCheckError(TElWebDAVClient_CreateCollection_1(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length()));
}
#endif /* SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST
SB_INLINE void TElWebDAVClient::DeleteObject(const std::string &URL, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors)
{
	SBCheckError(TElWebDAVClient_DeleteObject(_Handle, URL.data(), (int32_t)URL.length(), Locks.getHandle(), Errors.getHandle()));
}

SB_INLINE void TElWebDAVClient::DeleteObject(const std::string &URL, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors)
{
	SBCheckError(TElWebDAVClient_DeleteObject(_Handle, URL.data(), (int32_t)URL.length(), (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE, (Errors != NULL) ? Errors->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT
SB_INLINE void TElWebDAVClient::DeleteObject(TElWebDAVStorageObject &Obj, TElWebDavErrorList &Errors)
{
	SBCheckError(TElWebDAVClient_DeleteObject_1(_Handle, Obj.getHandle(), Errors.getHandle()));
}

SB_INLINE void TElWebDAVClient::DeleteObject(TElWebDAVStorageObject *Obj, TElWebDavErrorList *Errors)
{
	SBCheckError(TElWebDAVClient_DeleteObject_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Errors != NULL) ? Errors->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST
SB_INLINE void TElWebDAVClient::CopyObject(const std::string &SrcURL, const std::string &DestURL, bool Overwrite, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors)
{
	SBCheckError(TElWebDAVClient_CopyObject(_Handle, SrcURL.data(), (int32_t)SrcURL.length(), DestURL.data(), (int32_t)DestURL.length(), (int8_t)Overwrite, Locks.getHandle(), Errors.getHandle()));
}

SB_INLINE void TElWebDAVClient::CopyObject(const std::string &SrcURL, const std::string &DestURL, bool Overwrite, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors)
{
	SBCheckError(TElWebDAVClient_CopyObject(_Handle, SrcURL.data(), (int32_t)SrcURL.length(), DestURL.data(), (int32_t)DestURL.length(), (int8_t)Overwrite, (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE, (Errors != NULL) ? Errors->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT
SB_INLINE void TElWebDAVClient::CopyObject(TElWebDAVStorageObject &Src, TElWebDAVStorageObject &Dest, bool Overwrite, TElWebDavErrorList &Errors)
{
	SBCheckError(TElWebDAVClient_CopyObject_1(_Handle, Src.getHandle(), Dest.getHandle(), (int8_t)Overwrite, Errors.getHandle()));
}

SB_INLINE void TElWebDAVClient::CopyObject(TElWebDAVStorageObject *Src, TElWebDAVStorageObject *Dest, bool Overwrite, TElWebDavErrorList *Errors)
{
	SBCheckError(TElWebDAVClient_CopyObject_1(_Handle, (Src != NULL) ? Src->getHandle() : SB_NULL_HANDLE, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE, (int8_t)Overwrite, (Errors != NULL) ? Errors->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST
SB_INLINE void TElWebDAVClient::MoveObject(const std::string &SrcURL, const std::string &DestURL, bool Overwrite, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors)
{
	SBCheckError(TElWebDAVClient_MoveObject(_Handle, SrcURL.data(), (int32_t)SrcURL.length(), DestURL.data(), (int32_t)DestURL.length(), (int8_t)Overwrite, Locks.getHandle(), Errors.getHandle()));
}

SB_INLINE void TElWebDAVClient::MoveObject(const std::string &SrcURL, const std::string &DestURL, bool Overwrite, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors)
{
	SBCheckError(TElWebDAVClient_MoveObject(_Handle, SrcURL.data(), (int32_t)SrcURL.length(), DestURL.data(), (int32_t)DestURL.length(), (int8_t)Overwrite, (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE, (Errors != NULL) ? Errors->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT
SB_INLINE void TElWebDAVClient::MoveObject(TElWebDAVStorageObject &Src, TElWebDAVStorageObject &Dest, bool Overwrite, TElWebDavErrorList &Errors)
{
	SBCheckError(TElWebDAVClient_MoveObject_1(_Handle, Src.getHandle(), Dest.getHandle(), (int8_t)Overwrite, Errors.getHandle()));
}

SB_INLINE void TElWebDAVClient::MoveObject(TElWebDAVStorageObject *Src, TElWebDAVStorageObject *Dest, bool Overwrite, TElWebDavErrorList *Errors)
{
	SBCheckError(TElWebDAVClient_MoveObject_1(_Handle, (Src != NULL) ? Src->getHandle() : SB_NULL_HANDLE, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE, (int8_t)Overwrite, (Errors != NULL) ? Errors->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWEBDAVLOCKLIST
SB_INLINE void TElWebDAVClient::Rename(const std::string &URL, const std::string &NewName, bool MoveToRename, TElWebDAVLockList &Locks)
{
	SBCheckError(TElWebDAVClient_Rename(_Handle, URL.data(), (int32_t)URL.length(), NewName.data(), (int32_t)NewName.length(), (int8_t)MoveToRename, Locks.getHandle()));
}

SB_INLINE void TElWebDAVClient::Rename(const std::string &URL, const std::string &NewName, bool MoveToRename, TElWebDAVLockList *Locks)
{
	SBCheckError(TElWebDAVClient_Rename(_Handle, URL.data(), (int32_t)URL.length(), NewName.data(), (int32_t)NewName.length(), (int8_t)MoveToRename, (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT
SB_INLINE void TElWebDAVClient::Rename(TElWebDAVStorageObject &Obj, const std::string &NewName, bool MoveToRename)
{
	SBCheckError(TElWebDAVClient_Rename_1(_Handle, Obj.getHandle(), NewName.data(), (int32_t)NewName.length(), (int8_t)MoveToRename));
}

SB_INLINE void TElWebDAVClient::Rename(TElWebDAVStorageObject *Obj, const std::string &NewName, bool MoveToRename)
{
	SBCheckError(TElWebDAVClient_Rename_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, NewName.data(), (int32_t)NewName.length(), (int8_t)MoveToRename));
}
#endif /* SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWEBDAVLOCKLIST_AND_TELWEBDAVPROPERTYINFOLIST
SB_INLINE void TElWebDAVClient::ChangeProperties(const std::string &URL, TElWebDavPropertyInfoList &SetProperties, TElWebDavPropertyInfoList &RemoveProperties, TElWebDAVLockList &Locks)
{
	SBCheckError(TElWebDAVClient_ChangeProperties(_Handle, URL.data(), (int32_t)URL.length(), SetProperties.getHandle(), RemoveProperties.getHandle(), Locks.getHandle()));
}

SB_INLINE void TElWebDAVClient::ChangeProperties(const std::string &URL, TElWebDavPropertyInfoList *SetProperties, TElWebDavPropertyInfoList *RemoveProperties, TElWebDAVLockList *Locks)
{
	SBCheckError(TElWebDAVClient_ChangeProperties(_Handle, URL.data(), (int32_t)URL.length(), (SetProperties != NULL) ? SetProperties->getHandle() : SB_NULL_HANDLE, (RemoveProperties != NULL) ? RemoveProperties->getHandle() : SB_NULL_HANDLE, (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVLOCKLIST_AND_TELWEBDAVPROPERTYINFOLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TELWEBDAVSTORAGEOBJECT
SB_INLINE void TElWebDAVClient::ChangeProperties(TElWebDAVStorageObject &Obj, TElWebDavPropertyInfoList &SetProperties, TElWebDavPropertyInfoList &RemoveProperties)
{
	SBCheckError(TElWebDAVClient_ChangeProperties_1(_Handle, Obj.getHandle(), SetProperties.getHandle(), RemoveProperties.getHandle()));
}

SB_INLINE void TElWebDAVClient::ChangeProperties(TElWebDAVStorageObject *Obj, TElWebDavPropertyInfoList *SetProperties, TElWebDavPropertyInfoList *RemoveProperties)
{
	SBCheckError(TElWebDAVClient_ChangeProperties_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (SetProperties != NULL) ? SetProperties->getHandle() : SB_NULL_HANDLE, (RemoveProperties != NULL) ? RemoveProperties->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWEBDAVLOCKLIST_AND_TELWEBDAVPROPERTYINFO
SB_INLINE void TElWebDAVClient::SetProperty(const std::string &URL, TElWebDavPropertyInfo &PropInfo, TElWebDAVLockList &Locks)
{
	SBCheckError(TElWebDAVClient_SetProperty(_Handle, URL.data(), (int32_t)URL.length(), PropInfo.getHandle(), Locks.getHandle()));
}

SB_INLINE void TElWebDAVClient::SetProperty(const std::string &URL, TElWebDavPropertyInfo *PropInfo, TElWebDAVLockList *Locks)
{
	SBCheckError(TElWebDAVClient_SetProperty(_Handle, URL.data(), (int32_t)URL.length(), (PropInfo != NULL) ? PropInfo->getHandle() : SB_NULL_HANDLE, (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVLOCKLIST_AND_TELWEBDAVPROPERTYINFO */

#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFO_AND_TELWEBDAVSTORAGEOBJECT
SB_INLINE void TElWebDAVClient::SetProperty(TElWebDAVStorageObject &Obj, TElWebDavPropertyInfo &PropInfo)
{
	SBCheckError(TElWebDAVClient_SetProperty_1(_Handle, Obj.getHandle(), PropInfo.getHandle()));
}

SB_INLINE void TElWebDAVClient::SetProperty(TElWebDAVStorageObject *Obj, TElWebDavPropertyInfo *PropInfo)
{
	SBCheckError(TElWebDAVClient_SetProperty_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (PropInfo != NULL) ? PropInfo->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFO_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWEBDAVLOCKLIST_AND_TELWEBDAVPROPERTYINFO
SB_INLINE void TElWebDAVClient::RemoveProperty(const std::string &URL, TElWebDavPropertyInfo &PropInfo, TElWebDAVLockList &Locks)
{
	SBCheckError(TElWebDAVClient_RemoveProperty(_Handle, URL.data(), (int32_t)URL.length(), PropInfo.getHandle(), Locks.getHandle()));
}

SB_INLINE void TElWebDAVClient::RemoveProperty(const std::string &URL, TElWebDavPropertyInfo *PropInfo, TElWebDAVLockList *Locks)
{
	SBCheckError(TElWebDAVClient_RemoveProperty(_Handle, URL.data(), (int32_t)URL.length(), (PropInfo != NULL) ? PropInfo->getHandle() : SB_NULL_HANDLE, (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVLOCKLIST_AND_TELWEBDAVPROPERTYINFO */

#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFO_AND_TELWEBDAVSTORAGEOBJECT
SB_INLINE void TElWebDAVClient::RemoveProperty(TElWebDAVStorageObject &Obj, TElWebDavPropertyInfo &PropInfo)
{
	SBCheckError(TElWebDAVClient_RemoveProperty_1(_Handle, Obj.getHandle(), PropInfo.getHandle()));
}

SB_INLINE void TElWebDAVClient::RemoveProperty(TElWebDAVStorageObject *Obj, TElWebDavPropertyInfo *PropInfo)
{
	SBCheckError(TElWebDAVClient_RemoveProperty_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (PropInfo != NULL) ? PropInfo->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFO_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
SB_INLINE void TElWebDAVClient::ReadProperties(const std::string &URL, TElWebDavPropertyInfoList &Properties)
{
	SBCheckError(TElWebDAVClient_ReadProperties(_Handle, URL.data(), (int32_t)URL.length(), Properties.getHandle()));
}

SB_INLINE void TElWebDAVClient::ReadProperties(const std::string &URL, TElWebDavPropertyInfoList *Properties)
{
	SBCheckError(TElWebDAVClient_ReadProperties(_Handle, URL.data(), (int32_t)URL.length(), (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TELWEBDAVSTORAGEOBJECT
SB_INLINE void TElWebDAVClient::ReadProperties(TElWebDAVStorageObject &Obj, TElWebDavPropertyInfoList &Properties)
{
	SBCheckError(TElWebDAVClient_ReadProperties_1(_Handle, Obj.getHandle(), Properties.getHandle()));
}

SB_INLINE void TElWebDAVClient::ReadProperties(TElWebDAVStorageObject *Obj, TElWebDavPropertyInfoList *Properties)
{
	SBCheckError(TElWebDAVClient_ReadProperties_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFO
SB_INLINE TElWebDavPropertyInfoHandle TElWebDAVClient::ReadProperty(const std::string &URL, const std::string &PropName)
{
	TElWebDavPropertyInfoHandle OutResult;
	SBCheckError(TElWebDAVClient_ReadProperty(_Handle, URL.data(), (int32_t)URL.length(), PropName.data(), (int32_t)PropName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFO */

#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFO_AND_TELWEBDAVSTORAGEOBJECT
SB_INLINE TElWebDavPropertyInfoHandle TElWebDAVClient::ReadProperty(TElWebDAVStorageObject &Obj, const std::string &PropName)
{
	TElWebDavPropertyInfoHandle OutResult;
	SBCheckError(TElWebDAVClient_ReadProperty_1(_Handle, Obj.getHandle(), PropName.data(), (int32_t)PropName.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElWebDavPropertyInfoHandle TElWebDAVClient::ReadProperty(TElWebDAVStorageObject *Obj, const std::string &PropName)
{
	TElWebDavPropertyInfoHandle OutResult;
	SBCheckError(TElWebDAVClient_ReadProperty_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, PropName.data(), (int32_t)PropName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFO_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
SB_INLINE void TElWebDAVClient::GetSupportedProperties(const std::string &URL, TElWebDavPropertyInfoList &Properties)
{
	SBCheckError(TElWebDAVClient_GetSupportedProperties(_Handle, URL.data(), (int32_t)URL.length(), Properties.getHandle()));
}

SB_INLINE void TElWebDAVClient::GetSupportedProperties(const std::string &URL, TElWebDavPropertyInfoList *Properties)
{
	SBCheckError(TElWebDAVClient_GetSupportedProperties(_Handle, URL.data(), (int32_t)URL.length(), (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TELWEBDAVSTORAGEOBJECT
SB_INLINE void TElWebDAVClient::GetSupportedProperties(TElWebDAVStorageObject &Obj, TElWebDavPropertyInfoList &Properties)
{
	SBCheckError(TElWebDAVClient_GetSupportedProperties_1(_Handle, Obj.getHandle(), Properties.getHandle()));
}

SB_INLINE void TElWebDAVClient::GetSupportedProperties(TElWebDAVStorageObject *Obj, TElWebDavPropertyInfoList *Properties)
{
	SBCheckError(TElWebDAVClient_GetSupportedProperties_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
SB_INLINE void TElWebDAVClient::ReadSupportedProperties(const std::string &URL, TElWebDavPropertyInfoList &Properties)
{
	SBCheckError(TElWebDAVClient_ReadSupportedProperties(_Handle, URL.data(), (int32_t)URL.length(), Properties.getHandle()));
}

SB_INLINE void TElWebDAVClient::ReadSupportedProperties(const std::string &URL, TElWebDavPropertyInfoList *Properties)
{
	SBCheckError(TElWebDAVClient_ReadSupportedProperties(_Handle, URL.data(), (int32_t)URL.length(), (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TELWEBDAVSTORAGEOBJECT
SB_INLINE void TElWebDAVClient::ReadSupportedProperties(TElWebDAVStorageObject &Obj, TElWebDavPropertyInfoList &Properties)
{
	SBCheckError(TElWebDAVClient_ReadSupportedProperties_1(_Handle, Obj.getHandle(), Properties.getHandle()));
}

SB_INLINE void TElWebDAVClient::ReadSupportedProperties(TElWebDAVStorageObject *Obj, TElWebDavPropertyInfoList *Properties)
{
	SBCheckError(TElWebDAVClient_ReadSupportedProperties_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
SB_INLINE void TElWebDAVClient::ReadAllProperties(const std::string &URL, TElWebDavPropertyInfoList &Properties)
{
	SBCheckError(TElWebDAVClient_ReadAllProperties(_Handle, URL.data(), (int32_t)URL.length(), Properties.getHandle()));
}

SB_INLINE void TElWebDAVClient::ReadAllProperties(const std::string &URL, TElWebDavPropertyInfoList *Properties)
{
	SBCheckError(TElWebDAVClient_ReadAllProperties(_Handle, URL.data(), (int32_t)URL.length(), (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TELWEBDAVSTORAGEOBJECT
SB_INLINE void TElWebDAVClient::ReadAllProperties(TElWebDAVStorageObject &Obj, TElWebDavPropertyInfoList &Properties)
{
	SBCheckError(TElWebDAVClient_ReadAllProperties_1(_Handle, Obj.getHandle(), Properties.getHandle()));
}

SB_INLINE void TElWebDAVClient::ReadAllProperties(TElWebDAVStorageObject *Obj, TElWebDavPropertyInfoList *Properties)
{
	SBCheckError(TElWebDAVClient_ReadAllProperties_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST
SB_INLINE void TElWebDAVClient::Upload(const std::string &FilePath, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors)
{
	SBCheckError(TElWebDAVClient_Upload(_Handle, FilePath.data(), (int32_t)FilePath.length(), Locks.getHandle(), Errors.getHandle()));
}

SB_INLINE void TElWebDAVClient::Upload(const std::string &FilePath, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors)
{
	SBCheckError(TElWebDAVClient_Upload(_Handle, FilePath.data(), (int32_t)FilePath.length(), (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE, (Errors != NULL) ? Errors->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT
SB_INLINE void TElWebDAVClient::Upload(const std::string &FilePath, TElWebDAVStorageObject &Dest, TElWebDavErrorList &Errors)
{
	SBCheckError(TElWebDAVClient_Upload_1(_Handle, FilePath.data(), (int32_t)FilePath.length(), Dest.getHandle(), Errors.getHandle()));
}

SB_INLINE void TElWebDAVClient::Upload(const std::string &FilePath, TElWebDAVStorageObject *Dest, TElWebDavErrorList *Errors)
{
	SBCheckError(TElWebDAVClient_Upload_1(_Handle, FilePath.data(), (int32_t)FilePath.length(), (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE, (Errors != NULL) ? Errors->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST
SB_INLINE void TElWebDAVClient::Upload(const std::string &FilePath, const std::string &DestURL, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors)
{
	SBCheckError(TElWebDAVClient_Upload_2(_Handle, FilePath.data(), (int32_t)FilePath.length(), DestURL.data(), (int32_t)DestURL.length(), Locks.getHandle(), Errors.getHandle()));
}

SB_INLINE void TElWebDAVClient::Upload(const std::string &FilePath, const std::string &DestURL, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors)
{
	SBCheckError(TElWebDAVClient_Upload_2(_Handle, FilePath.data(), (int32_t)FilePath.length(), DestURL.data(), (int32_t)DestURL.length(), (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE, (Errors != NULL) ? Errors->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST
SB_INLINE void TElWebDAVClient::Upload(const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Count, const std::string &DestURL, int64_t RestartFrom, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors)
{
	SBCheckError(TElWebDAVClient_Upload_3(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), StartIndex, Count, DestURL.data(), (int32_t)DestURL.length(), RestartFrom, Locks.getHandle(), Errors.getHandle()));
}

SB_INLINE void TElWebDAVClient::Upload(const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Count, const std::string &DestURL, int64_t RestartFrom, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors)
{
	SBCheckError(TElWebDAVClient_Upload_3(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), StartIndex, Count, DestURL.data(), (int32_t)DestURL.length(), RestartFrom, (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE, (Errors != NULL) ? Errors->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT
SB_INLINE void TElWebDAVClient::Upload(const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Count, TElWebDAVStorageObject &Dest, int64_t RestartFrom, TElWebDavErrorList &Errors)
{
	SBCheckError(TElWebDAVClient_Upload_4(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), StartIndex, Count, Dest.getHandle(), RestartFrom, Errors.getHandle()));
}

SB_INLINE void TElWebDAVClient::Upload(const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Count, TElWebDAVStorageObject *Dest, int64_t RestartFrom, TElWebDavErrorList *Errors)
{
	SBCheckError(TElWebDAVClient_Upload_4(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), StartIndex, Count, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE, RestartFrom, (Errors != NULL) ? Errors->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST_AND_TSTREAM
SB_INLINE void TElWebDAVClient::Upload(TStream &Stream, const std::string &DestURL, int64_t RestartFrom, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors)
{
	SBCheckError(TElWebDAVClient_Upload_5(_Handle, Stream.getHandle(), DestURL.data(), (int32_t)DestURL.length(), RestartFrom, Locks.getHandle(), Errors.getHandle()));
}

SB_INLINE void TElWebDAVClient::Upload(TStream *Stream, const std::string &DestURL, int64_t RestartFrom, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors)
{
	SBCheckError(TElWebDAVClient_Upload_5(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, DestURL.data(), (int32_t)DestURL.length(), RestartFrom, (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE, (Errors != NULL) ? Errors->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElWebDAVClient::Upload(TStream &Stream, TElWebDAVStorageObject &Dest, int64_t RestartFrom, TElWebDavErrorList &Errors)
{
	SBCheckError(TElWebDAVClient_Upload_6(_Handle, Stream.getHandle(), Dest.getHandle(), RestartFrom, Errors.getHandle()));
}

SB_INLINE void TElWebDAVClient::Upload(TStream *Stream, TElWebDAVStorageObject *Dest, int64_t RestartFrom, TElWebDavErrorList *Errors)
{
	SBCheckError(TElWebDAVClient_Upload_6(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE, RestartFrom, (Errors != NULL) ? Errors->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT_AND_TSTREAM */

SB_INLINE void TElWebDAVClient::Download(const std::string &URL, const std::string &FilePath, bool Overwrite)
{
	SBCheckError(TElWebDAVClient_Download(_Handle, URL.data(), (int32_t)URL.length(), FilePath.data(), (int32_t)FilePath.length(), (int8_t)Overwrite));
}

#ifdef SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT
SB_INLINE void TElWebDAVClient::Download(TElWebDAVStorageObject &Obj, const std::string &FilePath, bool Overwrite)
{
	SBCheckError(TElWebDAVClient_Download_1(_Handle, Obj.getHandle(), FilePath.data(), (int32_t)FilePath.length(), (int8_t)Overwrite));
}

SB_INLINE void TElWebDAVClient::Download(TElWebDAVStorageObject *Obj, const std::string &FilePath, bool Overwrite)
{
	SBCheckError(TElWebDAVClient_Download_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, FilePath.data(), (int32_t)FilePath.length(), (int8_t)Overwrite));
}
#endif /* SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWebDAVClient::Download(const std::string &URL, TStream &Stream, int32_t Count, int64_t RestartFrom)
{
	SBCheckError(TElWebDAVClient_Download_2(_Handle, URL.data(), (int32_t)URL.length(), Stream.getHandle(), Count, RestartFrom));
}

SB_INLINE void TElWebDAVClient::Download(const std::string &URL, TStream *Stream, int32_t Count, int64_t RestartFrom)
{
	SBCheckError(TElWebDAVClient_Download_2(_Handle, URL.data(), (int32_t)URL.length(), (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count, RestartFrom));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELWEBDAVSTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElWebDAVClient::Download(TElWebDAVStorageObject &Obj, TStream &Stream, int32_t Count, int64_t RestartFrom)
{
	SBCheckError(TElWebDAVClient_Download_3(_Handle, Obj.getHandle(), Stream.getHandle(), Count, RestartFrom));
}

SB_INLINE void TElWebDAVClient::Download(TElWebDAVStorageObject *Obj, TStream *Stream, int32_t Count, int64_t RestartFrom)
{
	SBCheckError(TElWebDAVClient_Download_3(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count, RestartFrom));
}
#endif /* SB_USE_CLASSES_TELWEBDAVSTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELWEBDAVLOCKLIST_AND_TSTREAM
SB_INLINE void TElWebDAVClient::Download(const std::string &URL, TStream &Stream, int32_t Count, int64_t RestartFrom, TElWebDAVLockList &Locks)
{
	SBCheckError(TElWebDAVClient_Download_4(_Handle, URL.data(), (int32_t)URL.length(), Stream.getHandle(), Count, RestartFrom, Locks.getHandle()));
}

SB_INLINE void TElWebDAVClient::Download(const std::string &URL, TStream *Stream, int32_t Count, int64_t RestartFrom, TElWebDAVLockList *Locks)
{
	SBCheckError(TElWebDAVClient_Download_4(_Handle, URL.data(), (int32_t)URL.length(), (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count, RestartFrom, (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVLOCKLIST_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELWEBDAVLOCKLIST_AND_TELWEBDAVSTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElWebDAVClient::Download(TElWebDAVStorageObject &Obj, TStream &Stream, int32_t Count, int64_t RestartFrom, TElWebDAVLockList &Locks)
{
	SBCheckError(TElWebDAVClient_Download_5(_Handle, Obj.getHandle(), Stream.getHandle(), Count, RestartFrom, Locks.getHandle()));
}

SB_INLINE void TElWebDAVClient::Download(TElWebDAVStorageObject *Obj, TStream *Stream, int32_t Count, int64_t RestartFrom, TElWebDAVLockList *Locks)
{
	SBCheckError(TElWebDAVClient_Download_5(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count, RestartFrom, (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVLOCKLIST_AND_TELWEBDAVSTORAGEOBJECT_AND_TSTREAM */

SB_INLINE void TElWebDAVClient::DownloadFile(const std::string &URL, const std::string &LocalFileName)
{
	SBCheckError(TElWebDAVClient_DownloadFile(_Handle, URL.data(), (int32_t)URL.length(), LocalFileName.data(), (int32_t)LocalFileName.length()));
}

SB_INLINE void TElWebDAVClient::DownloadFile(const std::string &URL, const std::string &LocalFileName, TSBFileTransferMode Mode)
{
	SBCheckError(TElWebDAVClient_DownloadFile_1(_Handle, URL.data(), (int32_t)URL.length(), LocalFileName.data(), (int32_t)LocalFileName.length(), (TSBFileTransferModeRaw)Mode));
}

SB_INLINE void TElWebDAVClient::DownloadFile(const std::string &URL, const std::string &LocalFileName, TSBFileTransferMode Mode, int64_t RestartFrom)
{
	SBCheckError(TElWebDAVClient_DownloadFile_2(_Handle, URL.data(), (int32_t)URL.length(), LocalFileName.data(), (int32_t)LocalFileName.length(), (TSBFileTransferModeRaw)Mode, RestartFrom));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWebDAVClient::DownloadStream(const std::string &URL, TStream &LocalStream, TSBFileTransferMode Mode)
{
	SBCheckError(TElWebDAVClient_DownloadStream(_Handle, URL.data(), (int32_t)URL.length(), LocalStream.getHandle(), (TSBFileTransferModeRaw)Mode));
}

SB_INLINE void TElWebDAVClient::DownloadStream(const std::string &URL, TStream *LocalStream, TSBFileTransferMode Mode)
{
	SBCheckError(TElWebDAVClient_DownloadStream(_Handle, URL.data(), (int32_t)URL.length(), (LocalStream != NULL) ? LocalStream->getHandle() : SB_NULL_HANDLE, (TSBFileTransferModeRaw)Mode));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWebDAVClient::DownloadStream(const std::string &URL, TStream &LocalStream, TSBFileTransferMode Mode, int64_t RestartFrom)
{
	SBCheckError(TElWebDAVClient_DownloadStream_1(_Handle, URL.data(), (int32_t)URL.length(), LocalStream.getHandle(), (TSBFileTransferModeRaw)Mode, RestartFrom));
}

SB_INLINE void TElWebDAVClient::DownloadStream(const std::string &URL, TStream *LocalStream, TSBFileTransferMode Mode, int64_t RestartFrom)
{
	SBCheckError(TElWebDAVClient_DownloadStream_1(_Handle, URL.data(), (int32_t)URL.length(), (LocalStream != NULL) ? LocalStream->getHandle() : SB_NULL_HANDLE, (TSBFileTransferModeRaw)Mode, RestartFrom));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST
SB_INLINE void TElWebDAVClient::UploadFile(const std::string &LocalFileName, const std::string &URL, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors)
{
	SBCheckError(TElWebDAVClient_UploadFile(_Handle, LocalFileName.data(), (int32_t)LocalFileName.length(), URL.data(), (int32_t)URL.length(), Locks.getHandle(), Errors.getHandle()));
}

SB_INLINE void TElWebDAVClient::UploadFile(const std::string &LocalFileName, const std::string &URL, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors)
{
	SBCheckError(TElWebDAVClient_UploadFile(_Handle, LocalFileName.data(), (int32_t)LocalFileName.length(), URL.data(), (int32_t)URL.length(), (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE, (Errors != NULL) ? Errors->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST
SB_INLINE void TElWebDAVClient::UploadFile(const std::string &LocalFileName, const std::string &URL, TSBFileTransferMode Mode, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors)
{
	SBCheckError(TElWebDAVClient_UploadFile_1(_Handle, LocalFileName.data(), (int32_t)LocalFileName.length(), URL.data(), (int32_t)URL.length(), (TSBFileTransferModeRaw)Mode, Locks.getHandle(), Errors.getHandle()));
}

SB_INLINE void TElWebDAVClient::UploadFile(const std::string &LocalFileName, const std::string &URL, TSBFileTransferMode Mode, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors)
{
	SBCheckError(TElWebDAVClient_UploadFile_1(_Handle, LocalFileName.data(), (int32_t)LocalFileName.length(), URL.data(), (int32_t)URL.length(), (TSBFileTransferModeRaw)Mode, (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE, (Errors != NULL) ? Errors->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST
SB_INLINE void TElWebDAVClient::UploadFile(const std::string &LocalFileName, const std::string &URL, TSBFileTransferMode Mode, int64_t RestartFrom, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors)
{
	SBCheckError(TElWebDAVClient_UploadFile_2(_Handle, LocalFileName.data(), (int32_t)LocalFileName.length(), URL.data(), (int32_t)URL.length(), (TSBFileTransferModeRaw)Mode, RestartFrom, Locks.getHandle(), Errors.getHandle()));
}

SB_INLINE void TElWebDAVClient::UploadFile(const std::string &LocalFileName, const std::string &URL, TSBFileTransferMode Mode, int64_t RestartFrom, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors)
{
	SBCheckError(TElWebDAVClient_UploadFile_2(_Handle, LocalFileName.data(), (int32_t)LocalFileName.length(), URL.data(), (int32_t)URL.length(), (TSBFileTransferModeRaw)Mode, RestartFrom, (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE, (Errors != NULL) ? Errors->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST_AND_TSTREAM
SB_INLINE void TElWebDAVClient::UploadStream(TStream &LocalStream, const std::string &URL, TSBFileTransferMode Mode, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors)
{
	SBCheckError(TElWebDAVClient_UploadStream(_Handle, LocalStream.getHandle(), URL.data(), (int32_t)URL.length(), (TSBFileTransferModeRaw)Mode, Locks.getHandle(), Errors.getHandle()));
}

SB_INLINE void TElWebDAVClient::UploadStream(TStream *LocalStream, const std::string &URL, TSBFileTransferMode Mode, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors)
{
	SBCheckError(TElWebDAVClient_UploadStream(_Handle, (LocalStream != NULL) ? LocalStream->getHandle() : SB_NULL_HANDLE, URL.data(), (int32_t)URL.length(), (TSBFileTransferModeRaw)Mode, (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE, (Errors != NULL) ? Errors->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST_AND_TSTREAM
SB_INLINE void TElWebDAVClient::UploadStream(TStream &LocalStream, const std::string &URL, TSBFileTransferMode Mode, int64_t RestartFrom, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors)
{
	SBCheckError(TElWebDAVClient_UploadStream_1(_Handle, LocalStream.getHandle(), URL.data(), (int32_t)URL.length(), (TSBFileTransferModeRaw)Mode, RestartFrom, Locks.getHandle(), Errors.getHandle()));
}

SB_INLINE void TElWebDAVClient::UploadStream(TStream *LocalStream, const std::string &URL, TSBFileTransferMode Mode, int64_t RestartFrom, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors)
{
	SBCheckError(TElWebDAVClient_UploadStream_1(_Handle, (LocalStream != NULL) ? LocalStream->getHandle() : SB_NULL_HANDLE, URL.data(), (int32_t)URL.length(), (TSBFileTransferModeRaw)Mode, RestartFrom, (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE, (Errors != NULL) ? Errors->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST_AND_TSTREAM */

SB_INLINE void TElWebDAVClient::CancelRequest()
{
	SBCheckError(TElWebDAVClient_CancelRequest(_Handle));
}

void TElWebDAVClient::GetFullURL(const std::string &URL, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVClient_GetFullURL(_Handle, URL.data(), (int32_t)URL.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(836956781, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElWebDAVClient::GetFileSize(const std::string &URL)
{
	int64_t OutResult;
	SBCheckError(TElWebDAVClient_GetFileSize(_Handle, URL.data(), (int32_t)URL.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT
SB_INLINE int64_t TElWebDAVClient::GetFileSize(TElWebDAVStorageObject &Obj)
{
	int64_t OutResult;
	SBCheckError(TElWebDAVClient_GetFileSize_1(_Handle, Obj.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElWebDAVClient::GetFileSize(TElWebDAVStorageObject *Obj)
{
	int64_t OutResult;
	SBCheckError(TElWebDAVClient_GetFileSize_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT */

TSBFileType TElWebDAVClient::GetResourceType(const std::string &URL)
{
	TSBFileTypeRaw OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_GetResourceType(_Handle, URL.data(), (int32_t)URL.length(), &OutResultRaw));
	return (TSBFileType)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
SB_INLINE TElWebDAVLockHandle TElWebDAVClient::Lock(const std::string &URL, const std::string &Owner, TSBWebDavLockScope Scope, TSBWebDavDepth Depth, int32_t Timeout)
{
	TElWebDAVLockHandle OutResult;
	SBCheckError(TElWebDAVClient_Lock(_Handle, URL.data(), (int32_t)URL.length(), Owner.data(), (int32_t)Owner.length(), (TSBWebDavLockScopeRaw)Scope, (TSBWebDavDepthRaw)Depth, Timeout, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASSES_TELWEBDAVLOCK_AND_TELWEBDAVSTORAGEOBJECT
SB_INLINE TElWebDAVLockHandle TElWebDAVClient::Lock(TElWebDAVStorageObject &Obj, const std::string &Owner, TSBWebDavLockScope Scope, TSBWebDavDepth Depth, int32_t Timeout)
{
	TElWebDAVLockHandle OutResult;
	SBCheckError(TElWebDAVClient_Lock_1(_Handle, Obj.getHandle(), Owner.data(), (int32_t)Owner.length(), (TSBWebDavLockScopeRaw)Scope, (TSBWebDavDepthRaw)Depth, Timeout, &OutResult));
	return OutResult;
}

SB_INLINE TElWebDAVLockHandle TElWebDAVClient::Lock(TElWebDAVStorageObject *Obj, const std::string &Owner, TSBWebDavLockScope Scope, TSBWebDavDepth Depth, int32_t Timeout)
{
	TElWebDAVLockHandle OutResult;
	SBCheckError(TElWebDAVClient_Lock_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, Owner.data(), (int32_t)Owner.length(), (TSBWebDavLockScopeRaw)Scope, (TSBWebDavDepthRaw)Depth, Timeout, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWEBDAVLOCK_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
SB_INLINE void TElWebDAVClient::Unlock(const std::string &URL, TElWebDAVLock &Lock)
{
	SBCheckError(TElWebDAVClient_Unlock(_Handle, URL.data(), (int32_t)URL.length(), Lock.getHandle()));
}

SB_INLINE void TElWebDAVClient::Unlock(const std::string &URL, TElWebDAVLock *Lock)
{
	SBCheckError(TElWebDAVClient_Unlock(_Handle, URL.data(), (int32_t)URL.length(), (Lock != NULL) ? Lock->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
SB_INLINE void TElWebDAVClient::RefreshLock(const std::string &URL, TElWebDAVLock &Lock)
{
	SBCheckError(TElWebDAVClient_RefreshLock(_Handle, URL.data(), (int32_t)URL.length(), Lock.getHandle()));
}

SB_INLINE void TElWebDAVClient::RefreshLock(const std::string &URL, TElWebDAVLock *Lock)
{
	SBCheckError(TElWebDAVClient_RefreshLock(_Handle, URL.data(), (int32_t)URL.length(), (Lock != NULL) ? Lock->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElWebDAVClient::PrincipalCollectionSet(const std::string &URL, TStringList &URLs)
{
	SBCheckError(TElWebDAVClient_PrincipalCollectionSet(_Handle, URL.data(), (int32_t)URL.length(), URLs.getHandle()));
}

SB_INLINE void TElWebDAVClient::PrincipalCollectionSet(const std::string &URL, TStringList *URLs)
{
	SBCheckError(TElWebDAVClient_PrincipalCollectionSet(_Handle, URL.data(), (int32_t)URL.length(), (URLs != NULL) ? URLs->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElWebDAVClient::PrincipalCollectionSet(const std::string &URL, TElStringList &URLs)
{
	SBCheckError(TElWebDAVClient_PrincipalCollectionSet(_Handle, URL.data(), (int32_t)URL.length(), URLs.getHandle()));
}

SB_INLINE void TElWebDAVClient::PrincipalCollectionSet(const std::string &URL, TElStringList *URLs)
{
	SBCheckError(TElWebDAVClient_PrincipalCollectionSet(_Handle, URL.data(), (int32_t)URL.length(), (URLs != NULL) ? URLs->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELWEBDAVPRINCIPALLIST
SB_INLINE void TElWebDAVClient::ListPrincipals(const std::string &URL, TElWebDavPrincipalList &List, TSBWebDavDepth Depth)
{
	SBCheckError(TElWebDAVClient_ListPrincipals(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), (TSBWebDavDepthRaw)Depth));
}

SB_INLINE void TElWebDAVClient::ListPrincipals(const std::string &URL, TElWebDavPrincipalList *List, TSBWebDavDepth Depth)
{
	SBCheckError(TElWebDAVClient_ListPrincipals(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, (TSBWebDavDepthRaw)Depth));
}
#endif /* SB_USE_CLASS_TELWEBDAVPRINCIPALLIST */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
bool TElWebDAVClient::AclPrincipalPropSetFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList &Properties)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_AclPrincipalPropSetFirst(_Handle, &Ctx, URL.data(), (int32_t)URL.length(), Properties.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVClient::AclPrincipalPropSetFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList *Properties)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_AclPrincipalPropSetFirst(_Handle, &Ctx, URL.data(), (int32_t)URL.length(), (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
bool TElWebDAVClient::AclPrincipalPropSetNext(void * Ctx, TElWebDavPropertyInfoList &Properties)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_AclPrincipalPropSetNext(_Handle, Ctx, Properties.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVClient::AclPrincipalPropSetNext(void * Ctx, TElWebDavPropertyInfoList *Properties)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_AclPrincipalPropSetNext(_Handle, Ctx, (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

SB_INLINE void TElWebDAVClient::AclPrincipalPropSetClose(void * Ctx)
{
	SBCheckError(TElWebDAVClient_AclPrincipalPropSetClose(_Handle, Ctx));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TSTRINGLIST
bool TElWebDAVClient::PrincipalPropertySearchFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList &MatchProperties, TStringList &Matches, TElWebDavPropertyInfoList &Properties, bool ApplyToPrincipalCollectionSet)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_PrincipalPropertySearchFirst(_Handle, &Ctx, URL.data(), (int32_t)URL.length(), MatchProperties.getHandle(), Matches.getHandle(), Properties.getHandle(), (int8_t)ApplyToPrincipalCollectionSet, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVClient::PrincipalPropertySearchFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList *MatchProperties, TStringList *Matches, TElWebDavPropertyInfoList *Properties, bool ApplyToPrincipalCollectionSet)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_PrincipalPropertySearchFirst(_Handle, &Ctx, URL.data(), (int32_t)URL.length(), (MatchProperties != NULL) ? MatchProperties->getHandle() : SB_NULL_HANDLE, (Matches != NULL) ? Matches->getHandle() : SB_NULL_HANDLE, (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE, (int8_t)ApplyToPrincipalCollectionSet, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWEBDAVPROPERTYINFOLIST
bool TElWebDAVClient::PrincipalPropertySearchFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList &MatchProperties, TElStringList &Matches, TElWebDavPropertyInfoList &Properties, bool ApplyToPrincipalCollectionSet)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_PrincipalPropertySearchFirst(_Handle, &Ctx, URL.data(), (int32_t)URL.length(), MatchProperties.getHandle(), Matches.getHandle(), Properties.getHandle(), (int8_t)ApplyToPrincipalCollectionSet, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVClient::PrincipalPropertySearchFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList *MatchProperties, TElStringList *Matches, TElWebDavPropertyInfoList *Properties, bool ApplyToPrincipalCollectionSet)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_PrincipalPropertySearchFirst(_Handle, &Ctx, URL.data(), (int32_t)URL.length(), (MatchProperties != NULL) ? MatchProperties->getHandle() : SB_NULL_HANDLE, (Matches != NULL) ? Matches->getHandle() : SB_NULL_HANDLE, (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE, (int8_t)ApplyToPrincipalCollectionSet, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWEBDAVPROPERTYINFOLIST */
#endif

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
bool TElWebDAVClient::PrincipalPropertySearchNext(void * Ctx, TElWebDavPropertyInfoList &Properties)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_PrincipalPropertySearchNext(_Handle, Ctx, Properties.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVClient::PrincipalPropertySearchNext(void * Ctx, TElWebDavPropertyInfoList *Properties)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_PrincipalPropertySearchNext(_Handle, Ctx, (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

SB_INLINE void TElWebDAVClient::PrincipalPropertySearchClose(void * Ctx)
{
	SBCheckError(TElWebDAVClient_PrincipalPropertySearchClose(_Handle, Ctx));
}

#ifdef SB_USE_CLASSES_TELWEBDAVOBJECTLIST_AND_TELWEBDAVPROPERTYINFO_AND_TELWEBDAVPROPERTYINFOLIST
SB_INLINE void TElWebDAVClient::PrincipalMatch(const std::string &URL, TElWebDavPropertyInfo &PrincipalProperty, TElWebDavPropertyInfoList &Properties, TElWebDavObjectList &Objects)
{
	SBCheckError(TElWebDAVClient_PrincipalMatch(_Handle, URL.data(), (int32_t)URL.length(), PrincipalProperty.getHandle(), Properties.getHandle(), Objects.getHandle()));
}

SB_INLINE void TElWebDAVClient::PrincipalMatch(const std::string &URL, TElWebDavPropertyInfo *PrincipalProperty, TElWebDavPropertyInfoList *Properties, TElWebDavObjectList *Objects)
{
	SBCheckError(TElWebDAVClient_PrincipalMatch(_Handle, URL.data(), (int32_t)URL.length(), (PrincipalProperty != NULL) ? PrincipalProperty->getHandle() : SB_NULL_HANDLE, (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWEBDAVOBJECTLIST_AND_TELWEBDAVPROPERTYINFO_AND_TELWEBDAVPROPERTYINFOLIST */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
SB_INLINE void TElWebDAVClient::PrincipalSearchPropertySet(const std::string &URL, TElWebDavPropertyInfoList &Properties)
{
	SBCheckError(TElWebDAVClient_PrincipalSearchPropertySet(_Handle, URL.data(), (int32_t)URL.length(), Properties.getHandle()));
}

SB_INLINE void TElWebDAVClient::PrincipalSearchPropertySet(const std::string &URL, TElWebDavPropertyInfoList *Properties)
{
	SBCheckError(TElWebDAVClient_PrincipalSearchPropertySet(_Handle, URL.data(), (int32_t)URL.length(), (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElWebDAVClient::InheritedAclSet(const std::string &URL, TStringList &URLs)
{
	SBCheckError(TElWebDAVClient_InheritedAclSet(_Handle, URL.data(), (int32_t)URL.length(), URLs.getHandle()));
}

SB_INLINE void TElWebDAVClient::InheritedAclSet(const std::string &URL, TStringList *URLs)
{
	SBCheckError(TElWebDAVClient_InheritedAclSet(_Handle, URL.data(), (int32_t)URL.length(), (URLs != NULL) ? URLs->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElWebDAVClient::InheritedAclSet(const std::string &URL, TElStringList &URLs)
{
	SBCheckError(TElWebDAVClient_InheritedAclSet(_Handle, URL.data(), (int32_t)URL.length(), URLs.getHandle()));
}

SB_INLINE void TElWebDAVClient::InheritedAclSet(const std::string &URL, TElStringList *URLs)
{
	SBCheckError(TElWebDAVClient_InheritedAclSet(_Handle, URL.data(), (int32_t)URL.length(), (URLs != NULL) ? URLs->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELWEBDAVACLRESTRICTIONS
SB_INLINE void TElWebDAVClient::AclRestrictions(const std::string &URL, TElWebDavACLRestrictions &Restrictions)
{
	SBCheckError(TElWebDAVClient_AclRestrictions(_Handle, URL.data(), (int32_t)URL.length(), Restrictions.getHandle()));
}

SB_INLINE void TElWebDAVClient::AclRestrictions(const std::string &URL, TElWebDavACLRestrictions *Restrictions)
{
	SBCheckError(TElWebDAVClient_AclRestrictions(_Handle, URL.data(), (int32_t)URL.length(), (Restrictions != NULL) ? Restrictions->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVACLRESTRICTIONS */

#ifdef SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGESET
SB_INLINE void TElWebDAVClient::SupportedPrivilegeSet(const std::string &URL, TElWebDavSupportedPrivilegeSet &PrivilegeSet)
{
	SBCheckError(TElWebDAVClient_SupportedPrivilegeSet(_Handle, URL.data(), (int32_t)URL.length(), PrivilegeSet.getHandle()));
}

SB_INLINE void TElWebDAVClient::SupportedPrivilegeSet(const std::string &URL, TElWebDavSupportedPrivilegeSet *PrivilegeSet)
{
	SBCheckError(TElWebDAVClient_SupportedPrivilegeSet(_Handle, URL.data(), (int32_t)URL.length(), (PrivilegeSet != NULL) ? PrivilegeSet->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGESET */

SB_INLINE void TElWebDAVClient::CurrentUserPrivilegeSet(const std::string &URL, int32_t &Privileges)
{
	SBCheckError(TElWebDAVClient_CurrentUserPrivilegeSet(_Handle, URL.data(), (int32_t)URL.length(), &Privileges));
}

#ifdef SB_USE_CLASS_TELWEBDAVACL
SB_INLINE void TElWebDAVClient::GetAcl(const std::string &URL, TElWebDavACL &CurrentAcl)
{
	SBCheckError(TElWebDAVClient_GetAcl(_Handle, URL.data(), (int32_t)URL.length(), CurrentAcl.getHandle()));
}

SB_INLINE void TElWebDAVClient::GetAcl(const std::string &URL, TElWebDavACL *CurrentAcl)
{
	SBCheckError(TElWebDAVClient_GetAcl(_Handle, URL.data(), (int32_t)URL.length(), (CurrentAcl != NULL) ? CurrentAcl->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVACL */

#ifdef SB_USE_CLASS_TELWEBDAVACL
SB_INLINE void TElWebDAVClient::SetAcl(const std::string &URL, TElWebDavACL &NewAcl)
{
	SBCheckError(TElWebDAVClient_SetAcl(_Handle, URL.data(), (int32_t)URL.length(), NewAcl.getHandle()));
}

SB_INLINE void TElWebDAVClient::SetAcl(const std::string &URL, TElWebDavACL *NewAcl)
{
	SBCheckError(TElWebDAVClient_SetAcl(_Handle, URL.data(), (int32_t)URL.length(), (NewAcl != NULL) ? NewAcl->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVACL */

#ifdef SB_USE_CLASS_TELWEBDAVLOCKLIST
SB_INLINE void TElWebDAVClient::CreateAddressBook(const std::string &URL, const std::string &DisplayName, const std::string &Description, const std::string &Lang, TElWebDAVLockList &Locks)
{
	SBCheckError(TElWebDAVClient_CreateAddressBook(_Handle, URL.data(), (int32_t)URL.length(), DisplayName.data(), (int32_t)DisplayName.length(), Description.data(), (int32_t)Description.length(), Lang.data(), (int32_t)Lang.length(), Locks.getHandle()));
}

SB_INLINE void TElWebDAVClient::CreateAddressBook(const std::string &URL, const std::string &DisplayName, const std::string &Description, const std::string &Lang, TElWebDAVLockList *Locks)
{
	SBCheckError(TElWebDAVClient_CreateAddressBook(_Handle, URL.data(), (int32_t)URL.length(), DisplayName.data(), (int32_t)DisplayName.length(), Description.data(), (int32_t)Description.length(), Lang.data(), (int32_t)Lang.length(), (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT
SB_INLINE void TElWebDAVClient::CreateAddressBook(TElWebDAVStorageObject &Parent, const std::string &Name, const std::string &DisplayName, const std::string &Description, const std::string &Lang)
{
	SBCheckError(TElWebDAVClient_CreateAddressBook_1(_Handle, Parent.getHandle(), Name.data(), (int32_t)Name.length(), DisplayName.data(), (int32_t)DisplayName.length(), Description.data(), (int32_t)Description.length(), Lang.data(), (int32_t)Lang.length()));
}

SB_INLINE void TElWebDAVClient::CreateAddressBook(TElWebDAVStorageObject *Parent, const std::string &Name, const std::string &DisplayName, const std::string &Description, const std::string &Lang)
{
	SBCheckError(TElWebDAVClient_CreateAddressBook_1(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), DisplayName.data(), (int32_t)DisplayName.length(), Description.data(), (int32_t)Description.length(), Lang.data(), (int32_t)Lang.length()));
}
#endif /* SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWEBDAVLOCKLIST
SB_INLINE void TElWebDAVClient::CreateAddressBook(const std::string &URL, const std::string &DisplayName, const std::string &Description, TElWebDAVLockList &Locks)
{
	SBCheckError(TElWebDAVClient_CreateAddressBook_2(_Handle, URL.data(), (int32_t)URL.length(), DisplayName.data(), (int32_t)DisplayName.length(), Description.data(), (int32_t)Description.length(), Locks.getHandle()));
}

SB_INLINE void TElWebDAVClient::CreateAddressBook(const std::string &URL, const std::string &DisplayName, const std::string &Description, TElWebDAVLockList *Locks)
{
	SBCheckError(TElWebDAVClient_CreateAddressBook_2(_Handle, URL.data(), (int32_t)URL.length(), DisplayName.data(), (int32_t)DisplayName.length(), Description.data(), (int32_t)Description.length(), (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT
SB_INLINE void TElWebDAVClient::CreateAddressBook(TElWebDAVStorageObject &Parent, const std::string &Name, const std::string &DisplayName, const std::string &Description)
{
	SBCheckError(TElWebDAVClient_CreateAddressBook_3(_Handle, Parent.getHandle(), Name.data(), (int32_t)Name.length(), DisplayName.data(), (int32_t)DisplayName.length(), Description.data(), (int32_t)Description.length()));
}

SB_INLINE void TElWebDAVClient::CreateAddressBook(TElWebDAVStorageObject *Parent, const std::string &Name, const std::string &DisplayName, const std::string &Description)
{
	SBCheckError(TElWebDAVClient_CreateAddressBook_3(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), DisplayName.data(), (int32_t)DisplayName.length(), Description.data(), (int32_t)Description.length()));
}
#endif /* SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST_AND_TSTREAM
void TElWebDAVClient::UploadVCard(const std::string &URL, TStream &Strm, std::string &ETag, TElWebDavErrorList &Errors, TElWebDAVLockList &Locks)
{
	int32_t szETag = (int32_t)ETag.length();
	uint32_t _err = TElWebDAVClient_UploadVCard(_Handle, URL.data(), (int32_t)URL.length(), Strm.getHandle(), (char *)ETag.data(), &szETag, Errors.getHandle(), Locks.getHandle());
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ETag.resize(szETag);
		SBCheckError(SBGetLastReturnStringA(-1437147957, 3, (char *)ETag.data(), &szETag));
	}
	else
		SBCheckError(_err);

	ETag.resize(szETag);
}

void TElWebDAVClient::UploadVCard(const std::string &URL, TStream *Strm, std::string &ETag, TElWebDavErrorList *Errors, TElWebDAVLockList *Locks)
{
	int32_t szETag = (int32_t)ETag.length();
	uint32_t _err = TElWebDAVClient_UploadVCard(_Handle, URL.data(), (int32_t)URL.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (char *)ETag.data(), &szETag, (Errors != NULL) ? Errors->getHandle() : SB_NULL_HANDLE, (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ETag.resize(szETag);
		SBCheckError(SBGetLastReturnStringA(-1437147957, 3, (char *)ETag.data(), &szETag));
	}
	else
		SBCheckError(_err);

	ETag.resize(szETag);
}
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELVCARD_AND_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST
void TElWebDAVClient::UploadVCard(const std::string &URL, TElVCard &VCard, std::string &ETag, TElWebDavErrorList &Errors, TElWebDAVLockList &Locks)
{
	int32_t szETag = (int32_t)ETag.length();
	uint32_t _err = TElWebDAVClient_UploadVCard_1(_Handle, URL.data(), (int32_t)URL.length(), VCard.getHandle(), (char *)ETag.data(), &szETag, Errors.getHandle(), Locks.getHandle());
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ETag.resize(szETag);
		SBCheckError(SBGetLastReturnStringA(823719505, 3, (char *)ETag.data(), &szETag));
	}
	else
		SBCheckError(_err);

	ETag.resize(szETag);
}

void TElWebDAVClient::UploadVCard(const std::string &URL, TElVCard *VCard, std::string &ETag, TElWebDavErrorList *Errors, TElWebDAVLockList *Locks)
{
	int32_t szETag = (int32_t)ETag.length();
	uint32_t _err = TElWebDAVClient_UploadVCard_1(_Handle, URL.data(), (int32_t)URL.length(), (VCard != NULL) ? VCard->getHandle() : SB_NULL_HANDLE, (char *)ETag.data(), &szETag, (Errors != NULL) ? Errors->getHandle() : SB_NULL_HANDLE, (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ETag.resize(szETag);
		SBCheckError(SBGetLastReturnStringA(823719505, 3, (char *)ETag.data(), &szETag));
	}
	else
		SBCheckError(_err);

	ETag.resize(szETag);
}
#endif /* SB_USE_CLASSES_TELVCARD_AND_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASSES_TELVCARD_AND_TELWEBDAVLOCKLIST
void TElWebDAVClient::DownloadVCard(const std::string &URL, TElVCard &VCard, TElWebDAVLockList &Locks)
{
	TElClassHandle hVCard = VCard.getHandle();
	SBCheckError(TElWebDAVClient_DownloadVCard(_Handle, URL.data(), (int32_t)URL.length(), &hVCard, Locks.getHandle()));
	VCard.updateHandle(hVCard);
}

void TElWebDAVClient::DownloadVCard(const std::string &URL, TElVCard &VCard, TElWebDAVLockList *Locks)
{
	TElClassHandle hVCard = VCard.getHandle();
	SBCheckError(TElWebDAVClient_DownloadVCard(_Handle, URL.data(), (int32_t)URL.length(), &hVCard, (Locks != NULL) ? Locks->getHandle() : SB_NULL_HANDLE));
	VCard.updateHandle(hVCard);
}
#endif /* SB_USE_CLASSES_TELVCARD_AND_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASS_TELCARDDAVADDRESSBOOKINFO
SB_INLINE void TElWebDAVClient::GetAddressBookInfo(const std::string &URL, TElCardDavAddressBookInfo &Info)
{
	SBCheckError(TElWebDAVClient_GetAddressBookInfo(_Handle, URL.data(), (int32_t)URL.length(), Info.getHandle()));
}

SB_INLINE void TElWebDAVClient::GetAddressBookInfo(const std::string &URL, TElCardDavAddressBookInfo *Info)
{
	SBCheckError(TElWebDAVClient_GetAddressBookInfo(_Handle, URL.data(), (int32_t)URL.length(), (Info != NULL) ? Info->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCARDDAVADDRESSBOOKINFO */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCARDDAVFILTER_AND_TELWEBDAVPROPERTYINFOLIST_AND_TSTRINGLIST
bool TElWebDAVClient::AddressBookQueryFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList &Properties, TStringList &AddressDataProps, TElCardDavFilter &Filter, int32_t Limit, bool All, TSBWebDavDepth Depth)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_AddressBookQueryFirst(_Handle, &Ctx, URL.data(), (int32_t)URL.length(), Properties.getHandle(), AddressDataProps.getHandle(), Filter.getHandle(), Limit, (int8_t)All, (TSBWebDavDepthRaw)Depth, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVClient::AddressBookQueryFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList *Properties, TStringList *AddressDataProps, TElCardDavFilter *Filter, int32_t Limit, bool All, TSBWebDavDepth Depth)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_AddressBookQueryFirst(_Handle, &Ctx, URL.data(), (int32_t)URL.length(), (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE, (AddressDataProps != NULL) ? AddressDataProps->getHandle() : SB_NULL_HANDLE, (Filter != NULL) ? Filter->getHandle() : SB_NULL_HANDLE, Limit, (int8_t)All, (TSBWebDavDepthRaw)Depth, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELCARDDAVFILTER_AND_TELWEBDAVPROPERTYINFOLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCARDDAVFILTER_AND_TELSTRINGLIST_AND_TELWEBDAVPROPERTYINFOLIST
bool TElWebDAVClient::AddressBookQueryFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList &Properties, TElStringList &AddressDataProps, TElCardDavFilter &Filter, int32_t Limit, bool All, TSBWebDavDepth Depth)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_AddressBookQueryFirst(_Handle, &Ctx, URL.data(), (int32_t)URL.length(), Properties.getHandle(), AddressDataProps.getHandle(), Filter.getHandle(), Limit, (int8_t)All, (TSBWebDavDepthRaw)Depth, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVClient::AddressBookQueryFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList *Properties, TElStringList *AddressDataProps, TElCardDavFilter *Filter, int32_t Limit, bool All, TSBWebDavDepth Depth)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_AddressBookQueryFirst(_Handle, &Ctx, URL.data(), (int32_t)URL.length(), (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE, (AddressDataProps != NULL) ? AddressDataProps->getHandle() : SB_NULL_HANDLE, (Filter != NULL) ? Filter->getHandle() : SB_NULL_HANDLE, Limit, (int8_t)All, (TSBWebDavDepthRaw)Depth, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELCARDDAVFILTER_AND_TELSTRINGLIST_AND_TELWEBDAVPROPERTYINFOLIST */
#endif

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
bool TElWebDAVClient::AddressBookQueryNext(void * Ctx, TElWebDavPropertyInfoList &Properties)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_AddressBookQueryNext(_Handle, Ctx, Properties.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVClient::AddressBookQueryNext(void * Ctx, TElWebDavPropertyInfoList *Properties)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_AddressBookQueryNext(_Handle, Ctx, (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

SB_INLINE void TElWebDAVClient::AddressBookQueryClose(void * Ctx)
{
	SBCheckError(TElWebDAVClient_AddressBookQueryClose(_Handle, Ctx));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TSTRINGLIST
bool TElWebDAVClient::AddressBookMultigetFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList &Properties, TStringList &AddressDataProps, TStringList &Hrefs, bool All, TSBWebDavDepth Depth)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_AddressBookMultigetFirst(_Handle, &Ctx, URL.data(), (int32_t)URL.length(), Properties.getHandle(), AddressDataProps.getHandle(), Hrefs.getHandle(), (int8_t)All, (TSBWebDavDepthRaw)Depth, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVClient::AddressBookMultigetFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList *Properties, TStringList *AddressDataProps, TStringList *Hrefs, bool All, TSBWebDavDepth Depth)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_AddressBookMultigetFirst(_Handle, &Ctx, URL.data(), (int32_t)URL.length(), (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE, (AddressDataProps != NULL) ? AddressDataProps->getHandle() : SB_NULL_HANDLE, (Hrefs != NULL) ? Hrefs->getHandle() : SB_NULL_HANDLE, (int8_t)All, (TSBWebDavDepthRaw)Depth, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWEBDAVPROPERTYINFOLIST
bool TElWebDAVClient::AddressBookMultigetFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList &Properties, TElStringList &AddressDataProps, TElStringList &Hrefs, bool All, TSBWebDavDepth Depth)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_AddressBookMultigetFirst(_Handle, &Ctx, URL.data(), (int32_t)URL.length(), Properties.getHandle(), AddressDataProps.getHandle(), Hrefs.getHandle(), (int8_t)All, (TSBWebDavDepthRaw)Depth, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVClient::AddressBookMultigetFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList *Properties, TElStringList *AddressDataProps, TElStringList *Hrefs, bool All, TSBWebDavDepth Depth)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_AddressBookMultigetFirst(_Handle, &Ctx, URL.data(), (int32_t)URL.length(), (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE, (AddressDataProps != NULL) ? AddressDataProps->getHandle() : SB_NULL_HANDLE, (Hrefs != NULL) ? Hrefs->getHandle() : SB_NULL_HANDLE, (int8_t)All, (TSBWebDavDepthRaw)Depth, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWEBDAVPROPERTYINFOLIST */
#endif

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
bool TElWebDAVClient::AddressBookMultigetNext(void * Ctx, TElWebDavPropertyInfoList &Properties)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_AddressBookMultigetNext(_Handle, Ctx, Properties.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVClient::AddressBookMultigetNext(void * Ctx, TElWebDavPropertyInfoList *Properties)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_AddressBookMultigetNext(_Handle, Ctx, (Properties != NULL) ? Properties->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

SB_INLINE void TElWebDAVClient::AddressBookMultigetClose(void * Ctx)
{
	SBCheckError(TElWebDAVClient_AddressBookMultigetClose(_Handle, Ctx));
}

#ifdef SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL
SBWebDAVClient_TElWebDavPrincipal* TElWebDAVClient::get_CurrentUserPrincipal()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVClient_get_CurrentUserPrincipal(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CurrentUserPrincipal)
		this->_Inst_CurrentUserPrincipal = new SBWebDAVClient_TElWebDavPrincipal(hOutResult, ohFalse);
	else
		this->_Inst_CurrentUserPrincipal->updateHandle(hOutResult);
	return this->_Inst_CurrentUserPrincipal;
}
#endif /* SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL */

bool TElWebDAVClient::get_Authenticated()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_get_Authenticated(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElWebDAVClient::get_AddressBookURLs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVClient_get_AddressBookURLs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AddressBookURLs)
		this->_Inst_AddressBookURLs = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_AddressBookURLs->updateHandle(hOutResult);
	return this->_Inst_AddressBookURLs;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElWebDAVClient::get_AddressBookURLs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVClient_get_AddressBookURLs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AddressBookURLs)
		this->_Inst_AddressBookURLs = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_AddressBookURLs->updateHandle(hOutResult);
	return this->_Inst_AddressBookURLs;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELHTTPSWEBDAVCLIENT
TElHTTPSWebDAVClient* TElWebDAVClient::get_HTTPSWebDAVClient()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVClient_get_HTTPSWebDAVClient(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HTTPSWebDAVClient)
		this->_Inst_HTTPSWebDAVClient = new TElHTTPSWebDAVClient(hOutResult, ohFalse);
	else
		this->_Inst_HTTPSWebDAVClient->updateHandle(hOutResult);
	return this->_Inst_HTTPSWebDAVClient;
}

SB_INLINE void TElWebDAVClient::set_HTTPSWebDAVClient(TElHTTPSWebDAVClient &Value)
{
	SBCheckError(TElWebDAVClient_set_HTTPSWebDAVClient(_Handle, Value.getHandle()));
}

SB_INLINE void TElWebDAVClient::set_HTTPSWebDAVClient(TElHTTPSWebDAVClient *Value)
{
	SBCheckError(TElWebDAVClient_set_HTTPSWebDAVClient(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHTTPSWEBDAVCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
TElCustomFileSystemAdapter* TElWebDAVClient::get_FileSystemAdapter()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVClient_get_FileSystemAdapter(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FileSystemAdapter)
		this->_Inst_FileSystemAdapter = new TElCustomFileSystemAdapter(hOutResult, ohFalse);
	else
		this->_Inst_FileSystemAdapter->updateHandle(hOutResult);
	return this->_Inst_FileSystemAdapter;
}

SB_INLINE void TElWebDAVClient::set_FileSystemAdapter(TElCustomFileSystemAdapter &Value)
{
	SBCheckError(TElWebDAVClient_set_FileSystemAdapter(_Handle, Value.getHandle()));
}

SB_INLINE void TElWebDAVClient::set_FileSystemAdapter(TElCustomFileSystemAdapter *Value)
{
	SBCheckError(TElWebDAVClient_set_FileSystemAdapter(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

void TElWebDAVClient::get_BaseURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVClient_get_BaseURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(243878430, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDAVClient::set_BaseURL(const std::string &Value)
{
	SBCheckError(TElWebDAVClient_set_BaseURL(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElWebDAVClient::get_Owner_AnsiString(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVClient_get_Owner_AnsiString(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1761416245, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDAVClient::set_Owner_AnsiString(const std::string &Value)
{
	SBCheckError(TElWebDAVClient_set_Owner_AnsiString(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElWebDAVClient::get_LastListedURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVClient_get_LastListedURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-310348052, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElWebDAVClient::get_IncludeBackLinks()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_get_IncludeBackLinks(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDAVClient::set_IncludeBackLinks(bool Value)
{
	SBCheckError(TElWebDAVClient_set_IncludeBackLinks(_Handle, (int8_t)Value));
}

bool TElWebDAVClient::get_EncodeURL()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_get_EncodeURL(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDAVClient::set_EncodeURL(bool Value)
{
	SBCheckError(TElWebDAVClient_set_EncodeURL(_Handle, (int8_t)Value));
}

TSBWebDavClasses TElWebDAVClient::get_SupportedClasses()
{
	TSBWebDavClassesRaw OutResultRaw = 0;
	SBCheckError(TElWebDAVClient_get_SupportedClasses(_Handle, &OutResultRaw));
	return (TSBWebDavClasses)OutResultRaw;
}

void TElWebDAVClient::initInstances()
{
#ifdef SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL
	this->_Inst_CurrentUserPrincipal = NULL;
#endif /* SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_AddressBookURLs = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_AddressBookURLs = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELHTTPSWEBDAVCLIENT
	this->_Inst_HTTPSWebDAVClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSWEBDAVCLIENT */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
}

TElWebDAVClient::TElWebDAVClient(TElWebDAVClientHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElWebDAVClient::TElWebDAVClient(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDAVClient_Create(AOwner.getHandle(), &_Handle));
}

TElWebDAVClient::TElWebDAVClient(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDAVClient_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElWebDAVClient::~TElWebDAVClient()
{
#ifdef SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL
	delete this->_Inst_CurrentUserPrincipal;
	this->_Inst_CurrentUserPrincipal = NULL;
#endif /* SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_AddressBookURLs;
	this->_Inst_AddressBookURLs = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_AddressBookURLs;
	this->_Inst_AddressBookURLs = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELHTTPSWEBDAVCLIENT
	delete this->_Inst_HTTPSWebDAVClient;
	this->_Inst_HTTPSWebDAVClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSWEBDAVCLIENT */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	delete this->_Inst_FileSystemAdapter;
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
}
#endif /* SB_USE_CLASS_TELWEBDAVCLIENT */

#ifdef SB_USE_CLASS_TELWEBDAVLOCKLIST

SB_INLINE void TElWebDAVLockList::Merge(const TElWebDAVLockList &List)
{
	SBCheckError(TElWebDAVLockList_Merge(_Handle, List.getHandle()));
}

SB_INLINE void TElWebDAVLockList::Merge(const TElWebDAVLockList *List)
{
	SBCheckError(TElWebDAVLockList_Merge(_Handle, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElWebDAVLockListHandle TElWebDAVLockList::Clone()
{
	TElWebDAVLockListHandle OutResult;
	SBCheckError(TElWebDAVLockList_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
SB_INLINE void TElWebDAVLockList::Add(const TElWebDAVLock &Lock)
{
	SBCheckError(TElWebDAVLockList_Add(_Handle, Lock.getHandle()));
}

SB_INLINE void TElWebDAVLockList::Add(const TElWebDAVLock *Lock)
{
	SBCheckError(TElWebDAVLockList_Add(_Handle, (Lock != NULL) ? Lock->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
SB_INLINE void TElWebDAVLockList::Remove(const TElWebDAVLock &Lock)
{
	SBCheckError(TElWebDAVLockList_Remove(_Handle, Lock.getHandle()));
}

SB_INLINE void TElWebDAVLockList::Remove(const TElWebDAVLock *Lock)
{
	SBCheckError(TElWebDAVLockList_Remove(_Handle, (Lock != NULL) ? Lock->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
TElWebDAVLock* TElWebDAVLockList::get_Locks(int32_t Idx)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVLockList_get_Locks(_Handle, Idx, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Locks)
		this->_Inst_Locks = new TElWebDAVLock(hOutResult, ohFalse);
	else
		this->_Inst_Locks->updateHandle(hOutResult);
	return this->_Inst_Locks;
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

SB_INLINE int32_t TElWebDAVLockList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElWebDAVLockList_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElWebDAVLockList::get_ToIfHeader(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVLockList_get_ToIfHeader(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1992961300, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWebDAVLockList::initInstances()
{
#ifdef SB_USE_CLASS_TELWEBDAVLOCK
	this->_Inst_Locks = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */
}

TElWebDAVLockList::TElWebDAVLockList(TElWebDAVLockListHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElWebDAVLockList::TElWebDAVLockList(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDAVLockList_Create(AOwner.getHandle(), &_Handle));
}

TElWebDAVLockList::TElWebDAVLockList(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDAVLockList_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElWebDAVLockList::~TElWebDAVLockList()
{
#ifdef SB_USE_CLASS_TELWEBDAVLOCK
	delete this->_Inst_Locks;
	this->_Inst_Locks = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASS_TELWEBDAVMULTISTATUSRESPONSE

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWebDAVMultistatusResponse::LoadFromStream(TStream &Strm)
{
	SBCheckError(TElWebDAVMultistatusResponse_LoadFromStream(_Handle, Strm.getHandle()));
}

SB_INLINE void TElWebDAVMultistatusResponse::LoadFromStream(TStream *Strm)
{
	SBCheckError(TElWebDAVMultistatusResponse_LoadFromStream(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TElXMLDOMNode* TElWebDAVMultistatusResponse::get_Responses(int32_t Idx)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVMultistatusResponse_get_Responses(_Handle, Idx, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Responses)
		this->_Inst_Responses = new TElXMLDOMNode(hOutResult, ohFalse);
	else
		this->_Inst_Responses->updateHandle(hOutResult);
	return this->_Inst_Responses;
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

SB_INLINE int32_t TElWebDAVMultistatusResponse::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElWebDAVMultistatusResponse_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElWebDAVMultistatusResponse::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	this->_Inst_Responses = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
}

TElWebDAVMultistatusResponse::TElWebDAVMultistatusResponse(TElWebDAVMultistatusResponseHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElWebDAVMultistatusResponse::TElWebDAVMultistatusResponse() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDAVMultistatusResponse_Create(&_Handle));
}

TElWebDAVMultistatusResponse::~TElWebDAVMultistatusResponse()
{
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	delete this->_Inst_Responses;
	this->_Inst_Responses = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
}
#endif /* SB_USE_CLASS_TELWEBDAVMULTISTATUSRESPONSE */

#ifdef SB_USE_CLASS_TELWEBDAVERROR

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElWebDavError::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElWebDavError_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElWebDavError::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElWebDavError_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

void TElWebDavError::get_NS(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavError_get_NS(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-482115215, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavError::set_NS(const std::string &Value)
{
	SBCheckError(TElWebDavError_set_NS(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElWebDavError::get_Value(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavError_get_Value(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1131315731, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavError::set_Value(const std::string &Value)
{
	SBCheckError(TElWebDavError_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

TElWebDavError::TElWebDavError(TElWebDavErrorHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElWebDavError::TElWebDavError() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebDavError_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELWEBDAVERROR */

#ifdef SB_USE_CLASS_TELWEBDAVPRIVILEGESET

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElWebDavPrivilegeSet::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElWebDavPrivilegeSet_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElWebDavPrivilegeSet::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElWebDavPrivilegeSet_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE int32_t TElWebDavPrivilegeSet::get_Value()
{
	int32_t OutResult;
	SBCheckError(TElWebDavPrivilegeSet_get_Value(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElWebDavPrivilegeSet::set_Value(int32_t Value)
{
	SBCheckError(TElWebDavPrivilegeSet_set_Value(_Handle, Value));
}

TElWebDavPrivilegeSet::TElWebDavPrivilegeSet(TElWebDavPrivilegeSetHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElWebDavPrivilegeSet::TElWebDavPrivilegeSet() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebDavPrivilegeSet_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELWEBDAVPRIVILEGESET */

#ifdef SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGE

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElWebDavSupportedPrivilege::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElWebDavSupportedPrivilege_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElWebDavSupportedPrivilege::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElWebDavSupportedPrivilege_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

void TElWebDavSupportedPrivilege::get_NS(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavSupportedPrivilege_get_NS(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(253102328, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavSupportedPrivilege::set_NS(const std::string &Value)
{
	SBCheckError(TElWebDavSupportedPrivilege_set_NS(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElWebDavSupportedPrivilege::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavSupportedPrivilege_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(416963922, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavSupportedPrivilege::set_Name(const std::string &Value)
{
	SBCheckError(TElWebDavSupportedPrivilege_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElWebDavSupportedPrivilege::get_Description(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavSupportedPrivilege_get_Description(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1567690921, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavSupportedPrivilege::set_Description(const std::string &Value)
{
	SBCheckError(TElWebDavSupportedPrivilege_set_Description(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElWebDavSupportedPrivilege::get_DescLang(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavSupportedPrivilege_get_DescLang(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(246912473, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavSupportedPrivilege::set_DescLang(const std::string &Value)
{
	SBCheckError(TElWebDavSupportedPrivilege_set_DescLang(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElWebDavSupportedPrivilege::get__Abstract()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavSupportedPrivilege_get__Abstract(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDavSupportedPrivilege::set__Abstract(bool Value)
{
	SBCheckError(TElWebDavSupportedPrivilege_set__Abstract(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElWebDavSupportedPrivilege::get_Value()
{
	int32_t OutResult;
	SBCheckError(TElWebDavSupportedPrivilege_get_Value(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElWebDavSupportedPrivilege::set_Value(int32_t Value)
{
	SBCheckError(TElWebDavSupportedPrivilege_set_Value(_Handle, Value));
}

TElWebDavSupportedPrivilege* TElWebDavSupportedPrivilege::get_AggregatedPrivileges(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavSupportedPrivilege_get_AggregatedPrivileges(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AggregatedPrivileges)
		this->_Inst_AggregatedPrivileges = new TElWebDavSupportedPrivilege(hOutResult, ohFalse);
	else
		this->_Inst_AggregatedPrivileges->updateHandle(hOutResult);
	return this->_Inst_AggregatedPrivileges;
}

SB_INLINE int32_t TElWebDavSupportedPrivilege::get_AggregatedPrivilegeCount()
{
	int32_t OutResult;
	SBCheckError(TElWebDavSupportedPrivilege_get_AggregatedPrivilegeCount(_Handle, &OutResult));
	return OutResult;
}

void TElWebDavSupportedPrivilege::initInstances()
{
	this->_Inst_AggregatedPrivileges = NULL;
}

TElWebDavSupportedPrivilege::TElWebDavSupportedPrivilege(TElWebDavSupportedPrivilegeHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElWebDavSupportedPrivilege::TElWebDavSupportedPrivilege() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDavSupportedPrivilege_Create(&_Handle));
}

TElWebDavSupportedPrivilege::~TElWebDavSupportedPrivilege()
{
	delete this->_Inst_AggregatedPrivileges;
	this->_Inst_AggregatedPrivileges = NULL;
}
#endif /* SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGE */

#ifdef SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGESET

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElWebDavSupportedPrivilegeSet::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElWebDavSupportedPrivilegeSet_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElWebDavSupportedPrivilegeSet::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElWebDavSupportedPrivilegeSet_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

bool TElWebDavSupportedPrivilegeSet::IsAbstract(int32_t Privilege)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavSupportedPrivilegeSet_IsAbstract(_Handle, Privilege, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGE
TElWebDavSupportedPrivilege* TElWebDavSupportedPrivilegeSet::get_AggregatedPrivileges(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavSupportedPrivilegeSet_get_AggregatedPrivileges(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AggregatedPrivileges)
		this->_Inst_AggregatedPrivileges = new TElWebDavSupportedPrivilege(hOutResult, ohFalse);
	else
		this->_Inst_AggregatedPrivileges->updateHandle(hOutResult);
	return this->_Inst_AggregatedPrivileges;
}
#endif /* SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGE */

SB_INLINE int32_t TElWebDavSupportedPrivilegeSet::get_AggregatedPrivilegeCount()
{
	int32_t OutResult;
	SBCheckError(TElWebDavSupportedPrivilegeSet_get_AggregatedPrivilegeCount(_Handle, &OutResult));
	return OutResult;
}

void TElWebDavSupportedPrivilegeSet::initInstances()
{
#ifdef SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGE
	this->_Inst_AggregatedPrivileges = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGE */
}

TElWebDavSupportedPrivilegeSet::TElWebDavSupportedPrivilegeSet(TElWebDavSupportedPrivilegeSetHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElWebDavSupportedPrivilegeSet::TElWebDavSupportedPrivilegeSet() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDavSupportedPrivilegeSet_Create(&_Handle));
}

TElWebDavSupportedPrivilegeSet::~TElWebDavSupportedPrivilegeSet()
{
#ifdef SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGE
	delete this->_Inst_AggregatedPrivileges;
	this->_Inst_AggregatedPrivileges = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGE */
}
#endif /* SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGESET */

#ifdef SB_USE_CLASS_TELWEBDAVPRINCIPALSEARCHPROPERTYSETRESPONSE

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWebDAVPrincipalSearchPropertySetResponse::LoadFromStream(TStream &Strm)
{
	SBCheckError(TElWebDAVPrincipalSearchPropertySetResponse_LoadFromStream(_Handle, Strm.getHandle()));
}

SB_INLINE void TElWebDAVPrincipalSearchPropertySetResponse::LoadFromStream(TStream *Strm)
{
	SBCheckError(TElWebDAVPrincipalSearchPropertySetResponse_LoadFromStream(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TElXMLDOMNode* TElWebDAVPrincipalSearchPropertySetResponse::get_Responses(int32_t Idx)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVPrincipalSearchPropertySetResponse_get_Responses(_Handle, Idx, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Responses)
		this->_Inst_Responses = new TElXMLDOMNode(hOutResult, ohFalse);
	else
		this->_Inst_Responses->updateHandle(hOutResult);
	return this->_Inst_Responses;
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

SB_INLINE int32_t TElWebDAVPrincipalSearchPropertySetResponse::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElWebDAVPrincipalSearchPropertySetResponse_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElWebDAVPrincipalSearchPropertySetResponse::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	this->_Inst_Responses = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
}

TElWebDAVPrincipalSearchPropertySetResponse::TElWebDAVPrincipalSearchPropertySetResponse(TElWebDAVPrincipalSearchPropertySetResponseHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElWebDAVPrincipalSearchPropertySetResponse::TElWebDAVPrincipalSearchPropertySetResponse() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDAVPrincipalSearchPropertySetResponse_Create(&_Handle));
}

TElWebDAVPrincipalSearchPropertySetResponse::~TElWebDAVPrincipalSearchPropertySetResponse()
{
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	delete this->_Inst_Responses;
	this->_Inst_Responses = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
}
#endif /* SB_USE_CLASS_TELWEBDAVPRINCIPALSEARCHPROPERTYSETRESPONSE */

#ifdef SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT

SB_INLINE TElWebDAVStorageObjectHandle TElWebDAVStorageObject::Clone()
{
	TElWebDAVStorageObjectHandle OutResult;
	SBCheckError(TElWebDAVStorageObject_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
bool TElWebDAVStorageObject::ReadFromXML(TElXMLDOMNode &Node)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVStorageObject_ReadFromXML(_Handle, Node.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVStorageObject::ReadFromXML(TElXMLDOMNode *Node)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVStorageObject_ReadFromXML(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
SB_INLINE TElWebDAVLockHandle TElWebDAVStorageObject::Lock(TSBWebDavLockScope Scope, TSBWebDavDepth Depth, int32_t Timeout)
{
	TElWebDAVLockHandle OutResult;
	SBCheckError(TElWebDAVStorageObject_Lock(_Handle, (TSBWebDavLockScopeRaw)Scope, (TSBWebDavDepthRaw)Depth, Timeout, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

SB_INLINE void TElWebDAVStorageObject::Unlock()
{
	SBCheckError(TElWebDAVStorageObject_Unlock(_Handle));
}

SB_INLINE void TElWebDAVStorageObject::Unlock(int32_t Idx)
{
	SBCheckError(TElWebDAVStorageObject_Unlock_1(_Handle, Idx));
}

void TElWebDAVStorageObject::GetIfHeader(bool WithETag, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVStorageObject_GetIfHeader(_Handle, (int8_t)WithETag, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1461836289, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELWEBDAVCLIENT
TElWebDAVClient* TElWebDAVStorageObject::get_Storage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVStorageObject_get_Storage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Storage)
		this->_Inst_Storage = new TElWebDAVClient(hOutResult, ohFalse);
	else
		this->_Inst_Storage->updateHandle(hOutResult);
	return this->_Inst_Storage;
}
#endif /* SB_USE_CLASS_TELWEBDAVCLIENT */

void TElWebDAVStorageObject::get_ParentURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVStorageObject_get_ParentURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1478733581, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWebDAVStorageObject::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVStorageObject_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-678335939, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWebDAVStorageObject::get_FullURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVStorageObject_get_FullURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1456642290, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElWebDAVStorageObject::get_CreationDate()
{
	int64_t OutResult;
	SBCheckError(TElWebDAVStorageObject_get_CreationDate(_Handle, &OutResult));
	return OutResult;
}

void TElWebDAVStorageObject::get_DisplayName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVStorageObject_get_DisplayName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-629425909, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWebDAVStorageObject::get_ContentLanguage(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVStorageObject_get_ContentLanguage(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-481993220, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElWebDAVStorageObject::get_ContentLength()
{
	int64_t OutResult;
	SBCheckError(TElWebDAVStorageObject_get_ContentLength(_Handle, &OutResult));
	return OutResult;
}

void TElWebDAVStorageObject::get_ContentType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVStorageObject_get_ContentType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1765305739, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWebDAVStorageObject::get_ETag(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVStorageObject_get_ETag(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2664382, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElWebDAVStorageObject::get_LastModified()
{
	int64_t OutResult;
	SBCheckError(TElWebDAVStorageObject_get_LastModified(_Handle, &OutResult));
	return OutResult;
}

void TElWebDAVStorageObject::get_ResourceType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVStorageObject_get_ResourceType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-93907443, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElWebDAVStorageObject::get_Collection()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVStorageObject_get_Collection(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVStorageObject::get_IsAddressBook()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVStorageObject_get_IsAddressBook(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVStorageObject::get_BackLink()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVStorageObject_get_BackLink(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVStorageObject::get_SupportsExclusiveLock()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVStorageObject_get_SupportsExclusiveLock(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVStorageObject::get_SupportsSharedLock()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVStorageObject_get_SupportsSharedLock(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELWEBDAVLOCKLIST
TElWebDAVLockList* TElWebDAVStorageObject::get_Locks()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVStorageObject_get_Locks(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Locks)
		this->_Inst_Locks = new TElWebDAVLockList(hOutResult, ohFalse);
	else
		this->_Inst_Locks->updateHandle(hOutResult);
	return this->_Inst_Locks;
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCKLIST */

void TElWebDAVStorageObject::initInstances()
{
#ifdef SB_USE_CLASS_TELWEBDAVCLIENT
	this->_Inst_Storage = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVCLIENT */
#ifdef SB_USE_CLASS_TELWEBDAVLOCKLIST
	this->_Inst_Locks = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVLOCKLIST */
}

TElWebDAVStorageObject::TElWebDAVStorageObject(TElWebDAVStorageObjectHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELWEBDAVCLIENT
TElWebDAVStorageObject::TElWebDAVStorageObject(const TElWebDAVClient &Storage, const std::string &URL) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDAVStorageObject_Create(Storage.getHandle(), URL.data(), (int32_t)URL.length(), &_Handle));
}

TElWebDAVStorageObject::TElWebDAVStorageObject(const TElWebDAVClient *Storage, const std::string &URL) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDAVStorageObject_Create((Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, URL.data(), (int32_t)URL.length(), &_Handle));
}
#endif /* SB_USE_CLASS_TELWEBDAVCLIENT */

#ifdef SB_USE_CLASS_TELWEBDAVCLIENT
TElWebDAVStorageObject::TElWebDAVStorageObject(const TElWebDAVClient &Storage, const std::string &URL, bool HrefOnly) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDAVStorageObject_Create_1(Storage.getHandle(), URL.data(), (int32_t)URL.length(), (int8_t)HrefOnly, &_Handle));
}

TElWebDAVStorageObject::TElWebDAVStorageObject(const TElWebDAVClient *Storage, const std::string &URL, bool HrefOnly) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDAVStorageObject_Create_1((Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, URL.data(), (int32_t)URL.length(), (int8_t)HrefOnly, &_Handle));
}
#endif /* SB_USE_CLASS_TELWEBDAVCLIENT */

TElWebDAVStorageObject::~TElWebDAVStorageObject()
{
#ifdef SB_USE_CLASS_TELWEBDAVCLIENT
	delete this->_Inst_Storage;
	this->_Inst_Storage = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVCLIENT */
#ifdef SB_USE_CLASS_TELWEBDAVLOCKLIST
	delete this->_Inst_Locks;
	this->_Inst_Locks = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVLOCKLIST */
}
#endif /* SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWEBDAVERRORRESPONSE

void TElWebDavErrorResponse::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavErrorResponse_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(538312149, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWebDavErrorResponse::get_Status(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavErrorResponse_get_Status(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1169272579, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWebDavErrorResponse::get_Error(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavErrorResponse_get_Error(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1928722256, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWebDavErrorResponse::get_Description(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavErrorResponse_get_Description(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-706791856, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElWebDavErrorResponse::TElWebDavErrorResponse(TElWebDavErrorResponseHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TElWebDavErrorResponse::TElWebDavErrorResponse(const TElXMLDOMNode &Node) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebDavErrorResponse_Create(Node.getHandle(), &_Handle));
}

TElWebDavErrorResponse::TElWebDavErrorResponse(const TElXMLDOMNode *Node) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebDavErrorResponse_Create((Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#endif /* SB_USE_CLASS_TELWEBDAVERRORRESPONSE */

#ifdef SB_USE_CLASS_TELWEBDAVOBJECTLIST

SB_INLINE void TElWebDavObjectList::Clear()
{
	SBCheckError(TElWebDavObjectList_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT
TElWebDAVStorageObject* TElWebDavObjectList::get_Objects(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavObjectList_get_Objects(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Objects)
		this->_Inst_Objects = new TElWebDAVStorageObject(hOutResult, ohFalse);
	else
		this->_Inst_Objects->updateHandle(hOutResult);
	return this->_Inst_Objects;
}
#endif /* SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT */

SB_INLINE int32_t TElWebDavObjectList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElWebDavObjectList_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElWebDavObjectList::initInstances()
{
#ifdef SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT
	this->_Inst_Objects = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT */
}

TElWebDavObjectList::TElWebDavObjectList(TElWebDavObjectListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElWebDavObjectList::TElWebDavObjectList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDavObjectList_Create(&_Handle));
}

TElWebDavObjectList::~TElWebDavObjectList()
{
#ifdef SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT
	delete this->_Inst_Objects;
	this->_Inst_Objects = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT */
}
#endif /* SB_USE_CLASS_TELWEBDAVOBJECTLIST */

#ifdef SB_USE_CLASS_TELWEBDAVERRORLIST

SB_INLINE void TElWebDavErrorList::Clear()
{
	SBCheckError(TElWebDavErrorList_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELWEBDAVERRORRESPONSE
TElWebDavErrorResponse* TElWebDavErrorList::get_Objects(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavErrorList_get_Objects(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Objects)
		this->_Inst_Objects = new TElWebDavErrorResponse(hOutResult, ohFalse);
	else
		this->_Inst_Objects->updateHandle(hOutResult);
	return this->_Inst_Objects;
}
#endif /* SB_USE_CLASS_TELWEBDAVERRORRESPONSE */

SB_INLINE int32_t TElWebDavErrorList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElWebDavErrorList_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElWebDavErrorList::initInstances()
{
#ifdef SB_USE_CLASS_TELWEBDAVERRORRESPONSE
	this->_Inst_Objects = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVERRORRESPONSE */
}

TElWebDavErrorList::TElWebDavErrorList(TElWebDavErrorListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElWebDavErrorList::TElWebDavErrorList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDavErrorList_Create(&_Handle));
}

TElWebDavErrorList::~TElWebDavErrorList()
{
#ifdef SB_USE_CLASS_TELWEBDAVERRORRESPONSE
	delete this->_Inst_Objects;
	this->_Inst_Objects = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVERRORRESPONSE */
}
#endif /* SB_USE_CLASS_TELWEBDAVERRORLIST */

#ifdef SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL

#ifdef SB_USE_CLASS_TELXMLDOMNODE
bool SBWebDAVClient_TElWebDavPrincipal::ReadFromXML(TElXMLDOMNode &Node)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBWebDAVClient_TElWebDavPrincipal_ReadFromXML(_Handle, Node.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool SBWebDAVClient_TElWebDavPrincipal::ReadFromXML(TElXMLDOMNode *Node)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBWebDAVClient_TElWebDavPrincipal_ReadFromXML(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

void SBWebDAVClient_TElWebDavPrincipal::get_DisplayName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVClient_TElWebDavPrincipal_get_DisplayName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1468758278, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SBWebDAVClient_TElWebDavPrincipal::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVClient_TElWebDavPrincipal_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(750393574, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SBWebDAVClient_TElWebDavPrincipal::get_PrincipalURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVClient_TElWebDavPrincipal_get_PrincipalURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(849938150, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* SBWebDAVClient_TElWebDavPrincipal::get_AlternateURISet()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(SBWebDAVClient_TElWebDavPrincipal_get_AlternateURISet(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AlternateURISet)
		this->_Inst_AlternateURISet = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_AlternateURISet->updateHandle(hOutResult);
	return this->_Inst_AlternateURISet;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* SBWebDAVClient_TElWebDavPrincipal::get_AlternateURISet()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(SBWebDAVClient_TElWebDavPrincipal_get_AlternateURISet(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AlternateURISet)
		this->_Inst_AlternateURISet = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_AlternateURISet->updateHandle(hOutResult);
	return this->_Inst_AlternateURISet;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* SBWebDAVClient_TElWebDavPrincipal::get_GroupMemberSet()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(SBWebDAVClient_TElWebDavPrincipal_get_GroupMemberSet(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_GroupMemberSet)
		this->_Inst_GroupMemberSet = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_GroupMemberSet->updateHandle(hOutResult);
	return this->_Inst_GroupMemberSet;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* SBWebDAVClient_TElWebDavPrincipal::get_GroupMemberSet()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(SBWebDAVClient_TElWebDavPrincipal_get_GroupMemberSet(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_GroupMemberSet)
		this->_Inst_GroupMemberSet = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_GroupMemberSet->updateHandle(hOutResult);
	return this->_Inst_GroupMemberSet;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* SBWebDAVClient_TElWebDavPrincipal::get_GroupMembership()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(SBWebDAVClient_TElWebDavPrincipal_get_GroupMembership(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_GroupMembership)
		this->_Inst_GroupMembership = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_GroupMembership->updateHandle(hOutResult);
	return this->_Inst_GroupMembership;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* SBWebDAVClient_TElWebDavPrincipal::get_GroupMembership()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(SBWebDAVClient_TElWebDavPrincipal_get_GroupMembership(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_GroupMembership)
		this->_Inst_GroupMembership = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_GroupMembership->updateHandle(hOutResult);
	return this->_Inst_GroupMembership;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* SBWebDAVClient_TElWebDavPrincipal::get_AddressbookHomeSet()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(SBWebDAVClient_TElWebDavPrincipal_get_AddressbookHomeSet(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AddressbookHomeSet)
		this->_Inst_AddressbookHomeSet = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_AddressbookHomeSet->updateHandle(hOutResult);
	return this->_Inst_AddressbookHomeSet;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* SBWebDAVClient_TElWebDavPrincipal::get_AddressbookHomeSet()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(SBWebDAVClient_TElWebDavPrincipal_get_AddressbookHomeSet(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AddressbookHomeSet)
		this->_Inst_AddressbookHomeSet = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_AddressbookHomeSet->updateHandle(hOutResult);
	return this->_Inst_AddressbookHomeSet;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void SBWebDAVClient_TElWebDavPrincipal::get_AddressURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVClient_TElWebDavPrincipal_get_AddressURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(524150385, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool SBWebDAVClient_TElWebDavPrincipal::get_IsGroup()
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBWebDAVClient_TElWebDavPrincipal_get_IsGroup(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void SBWebDAVClient_TElWebDavPrincipal::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_AlternateURISet = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_AlternateURISet = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_GroupMemberSet = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_GroupMemberSet = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_GroupMembership = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_GroupMembership = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_AddressbookHomeSet = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_AddressbookHomeSet = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

SBWebDAVClient_TElWebDavPrincipal::SBWebDAVClient_TElWebDavPrincipal(SBWebDAVClient_TElWebDavPrincipalHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

SBWebDAVClient_TElWebDavPrincipal::SBWebDAVClient_TElWebDavPrincipal() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(SBWebDAVClient_TElWebDavPrincipal_Create(&_Handle));
}

SBWebDAVClient_TElWebDavPrincipal::~SBWebDAVClient_TElWebDavPrincipal()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_AlternateURISet;
	this->_Inst_AlternateURISet = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_AlternateURISet;
	this->_Inst_AlternateURISet = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_GroupMemberSet;
	this->_Inst_GroupMemberSet = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_GroupMemberSet;
	this->_Inst_GroupMemberSet = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_GroupMembership;
	this->_Inst_GroupMembership = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_GroupMembership;
	this->_Inst_GroupMembership = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_AddressbookHomeSet;
	this->_Inst_AddressbookHomeSet = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_AddressbookHomeSet;
	this->_Inst_AddressbookHomeSet = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL */

#ifdef SB_USE_CLASS_TELWEBDAVPRINCIPALLIST

SB_INLINE void TElWebDavPrincipalList::Clear()
{
	SBCheckError(TElWebDavPrincipalList_Clear(_Handle));
}

#ifdef SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL
SBWebDAVClient_TElWebDavPrincipal* TElWebDavPrincipalList::get_Principals(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavPrincipalList_get_Principals(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Principals)
		this->_Inst_Principals = new SBWebDAVClient_TElWebDavPrincipal(hOutResult, ohFalse);
	else
		this->_Inst_Principals->updateHandle(hOutResult);
	return this->_Inst_Principals;
}
#endif /* SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL */

SB_INLINE int32_t TElWebDavPrincipalList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElWebDavPrincipalList_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElWebDavPrincipalList::initInstances()
{
#ifdef SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL
	this->_Inst_Principals = NULL;
#endif /* SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL */
}

TElWebDavPrincipalList::TElWebDavPrincipalList(TElWebDavPrincipalListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElWebDavPrincipalList::TElWebDavPrincipalList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDavPrincipalList_Create(&_Handle));
}

TElWebDavPrincipalList::~TElWebDavPrincipalList()
{
#ifdef SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL
	delete this->_Inst_Principals;
	this->_Inst_Principals = NULL;
#endif /* SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL */
}
#endif /* SB_USE_CLASS_TELWEBDAVPRINCIPALLIST */

#ifdef SB_USE_CLASS_TELCARDDAVSUPPORTEDADDRESSDATA

void TElCardDavSupportedAddressData::get_ContentType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCardDavSupportedAddressData_get_ContentType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1908383408, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElCardDavSupportedAddressData::get_Version(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCardDavSupportedAddressData_get_Version(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-439106319, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElCardDavSupportedAddressData::TElCardDavSupportedAddressData(TElCardDavSupportedAddressDataHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElCardDavSupportedAddressData::TElCardDavSupportedAddressData() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCardDavSupportedAddressData_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCARDDAVSUPPORTEDADDRESSDATA */

#ifdef SB_USE_CLASS_TELCARDDAVADDRESSBOOKINFO

void TElCardDavAddressBookInfo::get_Description(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCardDavAddressBookInfo_get_Description(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1712660205, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElCardDavAddressBookInfo::get_SupportedAddressDataCount()
{
	int32_t OutResult;
	SBCheckError(TElCardDavAddressBookInfo_get_SupportedAddressDataCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCARDDAVSUPPORTEDADDRESSDATA
TElCardDavSupportedAddressData* TElCardDavAddressBookInfo::get_SupportedAddressData(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCardDavAddressBookInfo_get_SupportedAddressData(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SupportedAddressData)
		this->_Inst_SupportedAddressData = new TElCardDavSupportedAddressData(hOutResult, ohFalse);
	else
		this->_Inst_SupportedAddressData->updateHandle(hOutResult);
	return this->_Inst_SupportedAddressData;
}
#endif /* SB_USE_CLASS_TELCARDDAVSUPPORTEDADDRESSDATA */

SB_INLINE int32_t TElCardDavAddressBookInfo::get_MaxResourceSize()
{
	int32_t OutResult;
	SBCheckError(TElCardDavAddressBookInfo_get_MaxResourceSize(_Handle, &OutResult));
	return OutResult;
}

void TElCardDavAddressBookInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELCARDDAVSUPPORTEDADDRESSDATA
	this->_Inst_SupportedAddressData = NULL;
#endif /* SB_USE_CLASS_TELCARDDAVSUPPORTEDADDRESSDATA */
}

TElCardDavAddressBookInfo::TElCardDavAddressBookInfo(TElCardDavAddressBookInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCardDavAddressBookInfo::TElCardDavAddressBookInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCardDavAddressBookInfo_Create(&_Handle));
}

TElCardDavAddressBookInfo::~TElCardDavAddressBookInfo()
{
#ifdef SB_USE_CLASS_TELCARDDAVSUPPORTEDADDRESSDATA
	delete this->_Inst_SupportedAddressData;
	this->_Inst_SupportedAddressData = NULL;
#endif /* SB_USE_CLASS_TELCARDDAVSUPPORTEDADDRESSDATA */
}
#endif /* SB_USE_CLASS_TELCARDDAVADDRESSBOOKINFO */

#ifdef SB_USE_CLASS_TELCARDDAVREPORTCONTEXT

TElCardDavReportContext::TElCardDavReportContext(TElCardDavReportContextHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElCardDavReportContext::TElCardDavReportContext() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCardDavReportContext_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCARDDAVREPORTCONTEXT */

#ifdef SB_USE_GLOBAL_PROCS_WEBDAVCLIENT

void AddSlash(const std::string &s, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVClient_AddSlash(s.data(), (int32_t)s.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1122899655, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool HTTPSuccess(int32_t Res)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBWebDAVClient_HTTPSuccess(Res, &OutResultRaw));
	return (OutResultRaw != 0);
}

#endif /* SB_USE_GLOBAL_PROCS_WEBDAVCLIENT */

};	/* namespace SecureBlackbox */
