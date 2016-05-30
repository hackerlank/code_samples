#include "sbgoogledatastorage.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGE

SB_INLINE void TElGoogleDataStorage::Authorize()
{
	SBCheckError(TElGoogleDataStorage_Authorize(_Handle));
}

SB_INLINE void TElGoogleDataStorage::SecondaryAuthorize()
{
	SBCheckError(TElGoogleDataStorage_SecondaryAuthorize(_Handle));
}

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
SB_INLINE TElGoogleDataStorageObjectHandle TElGoogleDataStorage::AcquireObject(const std::string &Title)
{
	TElGoogleDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDataStorage_AcquireObject(_Handle, Title.data(), (int32_t)Title.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
SB_INLINE TElGoogleDataStorageObjectHandle TElGoogleDataStorage::AcquireObject(TElGoogleDataStorageObject &Folder, const std::string &Title)
{
	TElGoogleDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDataStorage_AcquireObject_1(_Handle, Folder.getHandle(), Title.data(), (int32_t)Title.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElGoogleDataStorageObjectHandle TElGoogleDataStorage::AcquireObject(TElGoogleDataStorageObject *Folder, const std::string &Title)
{
	TElGoogleDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDataStorage_AcquireObject_1(_Handle, (Folder != NULL) ? Folder->getHandle() : SB_NULL_HANDLE, Title.data(), (int32_t)Title.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
SB_INLINE TElGoogleDataStorageObjectHandle TElGoogleDataStorage::AcquireObject(TSBGoogleDocType DocType, const std::string &DocID)
{
	TElGoogleDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDataStorage_AcquireObject_2(_Handle, (TSBGoogleDocTypeRaw)DocType, DocID.data(), (int32_t)DocID.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElGoogleDataStorage::List(TElDataStorageObjectList &Objects)
{
	SBCheckError(TElGoogleDataStorage_List(_Handle, Objects.getHandle()));
}

SB_INLINE void TElGoogleDataStorage::List(TElDataStorageObjectList *Objects)
{
	SBCheckError(TElGoogleDataStorage_List(_Handle, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElGoogleDataStorage::List(const std::string &Query, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElGoogleDataStorage_List_1(_Handle, Query.data(), (int32_t)Query.length(), (int8_t)ShowFolders, (int8_t)ShowDeleted, (TSBGoogleEntryOrderRaw)OrderBy, Objects.getHandle()));
}

SB_INLINE void TElGoogleDataStorage::List(const std::string &Query, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElGoogleDataStorage_List_1(_Handle, Query.data(), (int32_t)Query.length(), (int8_t)ShowFolders, (int8_t)ShowDeleted, (TSBGoogleEntryOrderRaw)OrderBy, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELGOOGLEDATASTORAGEOBJECT
SB_INLINE void TElGoogleDataStorage::List(TElGoogleDataStorageObject &Folder, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElGoogleDataStorage_List_2(_Handle, Folder.getHandle(), Objects.getHandle()));
}

SB_INLINE void TElGoogleDataStorage::List(TElGoogleDataStorageObject *Folder, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElGoogleDataStorage_List_2(_Handle, (Folder != NULL) ? Folder->getHandle() : SB_NULL_HANDLE, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELGOOGLEDATASTORAGEOBJECT
SB_INLINE void TElGoogleDataStorage::List(TElGoogleDataStorageObject &Folder, const std::string &Query, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElGoogleDataStorage_List_3(_Handle, Folder.getHandle(), Query.data(), (int32_t)Query.length(), (int8_t)ShowFolders, (int8_t)ShowDeleted, (TSBGoogleEntryOrderRaw)OrderBy, Objects.getHandle()));
}

SB_INLINE void TElGoogleDataStorage::List(TElGoogleDataStorageObject *Folder, const std::string &Query, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElGoogleDataStorage_List_3(_Handle, (Folder != NULL) ? Folder->getHandle() : SB_NULL_HANDLE, Query.data(), (int32_t)Query.length(), (int8_t)ShowFolders, (int8_t)ShowDeleted, (TSBGoogleEntryOrderRaw)OrderBy, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElGoogleDataStorage::List(const std::string &Query, const std::string &Alt, const std::string &Author, int64_t StartIndex, int64_t MaxResults, int64_t UpdatedMin, int64_t UpdatedMax, const std::string &Category, const std::string &Title, bool ExactTitle, int64_t OpenedMin, int64_t OpenedMax, const std::string &Owner, const std::string &Writer, const std::string &Reader, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElGoogleDataStorage_List_4(_Handle, Query.data(), (int32_t)Query.length(), Alt.data(), (int32_t)Alt.length(), Author.data(), (int32_t)Author.length(), StartIndex, MaxResults, UpdatedMin, UpdatedMax, Category.data(), (int32_t)Category.length(), Title.data(), (int32_t)Title.length(), (int8_t)ExactTitle, OpenedMin, OpenedMax, Owner.data(), (int32_t)Owner.length(), Writer.data(), (int32_t)Writer.length(), Reader.data(), (int32_t)Reader.length(), (int8_t)ShowFolders, (int8_t)ShowDeleted, (TSBGoogleEntryOrderRaw)OrderBy, Objects.getHandle()));
}

SB_INLINE void TElGoogleDataStorage::List(const std::string &Query, const std::string &Alt, const std::string &Author, int64_t StartIndex, int64_t MaxResults, int64_t UpdatedMin, int64_t UpdatedMax, const std::string &Category, const std::string &Title, bool ExactTitle, int64_t OpenedMin, int64_t OpenedMax, const std::string &Owner, const std::string &Writer, const std::string &Reader, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElGoogleDataStorage_List_4(_Handle, Query.data(), (int32_t)Query.length(), Alt.data(), (int32_t)Alt.length(), Author.data(), (int32_t)Author.length(), StartIndex, MaxResults, UpdatedMin, UpdatedMax, Category.data(), (int32_t)Category.length(), Title.data(), (int32_t)Title.length(), (int8_t)ExactTitle, OpenedMin, OpenedMax, Owner.data(), (int32_t)Owner.length(), Writer.data(), (int32_t)Writer.length(), Reader.data(), (int32_t)Reader.length(), (int8_t)ShowFolders, (int8_t)ShowDeleted, (TSBGoogleEntryOrderRaw)OrderBy, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELGOOGLEDATASTORAGEOBJECT
SB_INLINE void TElGoogleDataStorage::List(TElGoogleDataStorageObject &Folder, const std::string &Query, const std::string &Alt, const std::string &Author, int64_t StartIndex, int64_t MaxResults, int64_t UpdatedMin, int64_t UpdatedMax, const std::string &Category, const std::string &Title, bool ExactTitle, int64_t OpenedMin, int64_t OpenedMax, const std::string &Owner, const std::string &Writer, const std::string &Reader, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElGoogleDataStorage_List_5(_Handle, Folder.getHandle(), Query.data(), (int32_t)Query.length(), Alt.data(), (int32_t)Alt.length(), Author.data(), (int32_t)Author.length(), StartIndex, MaxResults, UpdatedMin, UpdatedMax, Category.data(), (int32_t)Category.length(), Title.data(), (int32_t)Title.length(), (int8_t)ExactTitle, OpenedMin, OpenedMax, Owner.data(), (int32_t)Owner.length(), Writer.data(), (int32_t)Writer.length(), Reader.data(), (int32_t)Reader.length(), (int8_t)ShowFolders, (int8_t)ShowDeleted, (TSBGoogleEntryOrderRaw)OrderBy, Objects.getHandle()));
}

SB_INLINE void TElGoogleDataStorage::List(TElGoogleDataStorageObject *Folder, const std::string &Query, const std::string &Alt, const std::string &Author, int64_t StartIndex, int64_t MaxResults, int64_t UpdatedMin, int64_t UpdatedMax, const std::string &Category, const std::string &Title, bool ExactTitle, int64_t OpenedMin, int64_t OpenedMax, const std::string &Owner, const std::string &Writer, const std::string &Reader, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElGoogleDataStorage_List_5(_Handle, (Folder != NULL) ? Folder->getHandle() : SB_NULL_HANDLE, Query.data(), (int32_t)Query.length(), Alt.data(), (int32_t)Alt.length(), Author.data(), (int32_t)Author.length(), StartIndex, MaxResults, UpdatedMin, UpdatedMax, Category.data(), (int32_t)Category.length(), Title.data(), (int32_t)Title.length(), (int8_t)ExactTitle, OpenedMin, OpenedMax, Owner.data(), (int32_t)Owner.length(), Writer.data(), (int32_t)Writer.length(), Reader.data(), (int32_t)Reader.length(), (int8_t)ShowFolders, (int8_t)ShowDeleted, (TSBGoogleEntryOrderRaw)OrderBy, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
SB_INLINE TElGoogleDataStorageObjectHandle TElGoogleDataStorage::CreateObject(const std::string &Title, TSBGoogleDocType DocType, const std::string &ContentType)
{
	TElGoogleDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDataStorage_CreateObject(_Handle, Title.data(), (int32_t)Title.length(), (TSBGoogleDocTypeRaw)DocType, ContentType.data(), (int32_t)ContentType.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
SB_INLINE TElGoogleDataStorageObjectHandle TElGoogleDataStorage::CreateFolder(const std::string &Title, TElGoogleDataStorageObject &ParentFolder)
{
	TElGoogleDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDataStorage_CreateFolder(_Handle, Title.data(), (int32_t)Title.length(), ParentFolder.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElGoogleDataStorageObjectHandle TElGoogleDataStorage::CreateFolder(const std::string &Title, TElGoogleDataStorageObject *ParentFolder)
{
	TElGoogleDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDataStorage_CreateFolder(_Handle, Title.data(), (int32_t)Title.length(), (ParentFolder != NULL) ? ParentFolder->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
void TElGoogleDataStorage::DeleteObject(TElGoogleDataStorageObject &Obj)
{
	TElClassHandle hObj = Obj.getHandle();
	SBCheckError(TElGoogleDataStorage_DeleteObject(_Handle, &hObj));
	Obj.updateHandle(hObj);
}
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
void TElGoogleDataStorage::DeleteObject(TElGoogleDataStorageObject &Obj, bool DeletePermanently)
{
	TElClassHandle hObj = Obj.getHandle();
	SBCheckError(TElGoogleDataStorage_DeleteObject_1(_Handle, &hObj, (int8_t)DeletePermanently));
	Obj.updateHandle(hObj);
}
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
SB_INLINE void TElGoogleDataStorage::DeleteObject(TElGoogleDataStorageObject &Folder, const std::string &Title, bool DeletePermanently)
{
	SBCheckError(TElGoogleDataStorage_DeleteObject_2(_Handle, Folder.getHandle(), Title.data(), (int32_t)Title.length(), (int8_t)DeletePermanently));
}

SB_INLINE void TElGoogleDataStorage::DeleteObject(TElGoogleDataStorageObject *Folder, const std::string &Title, bool DeletePermanently)
{
	SBCheckError(TElGoogleDataStorage_DeleteObject_2(_Handle, (Folder != NULL) ? Folder->getHandle() : SB_NULL_HANDLE, Title.data(), (int32_t)Title.length(), (int8_t)DeletePermanently));
}
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
bool TElGoogleDataStorage::ObjectExists(TElGoogleDataStorageObject &Obj)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDataStorage_ObjectExists(_Handle, Obj.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGoogleDataStorage::ObjectExists(TElGoogleDataStorageObject *Obj)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDataStorage_ObjectExists(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

bool TElGoogleDataStorage::ObjectExists(TSBGoogleDocType DocType, const std::string &DocID)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDataStorage_ObjectExists_1(_Handle, (TSBGoogleDocTypeRaw)DocType, DocID.data(), (int32_t)DocID.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
bool TElGoogleDataStorage::ObjectExists(TElGoogleDataStorageObject &Folder, const std::string &Title)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDataStorage_ObjectExists_2(_Handle, Folder.getHandle(), Title.data(), (int32_t)Title.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGoogleDataStorage::ObjectExists(TElGoogleDataStorageObject *Folder, const std::string &Title)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDataStorage_ObjectExists_2(_Handle, (Folder != NULL) ? Folder->getHandle() : SB_NULL_HANDLE, Title.data(), (int32_t)Title.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
SB_INLINE void TElGoogleDataStorage::RefreshObject(TElGoogleDataStorageObject &Obj)
{
	SBCheckError(TElGoogleDataStorage_RefreshObject(_Handle, Obj.getHandle()));
}

SB_INLINE void TElGoogleDataStorage::RefreshObject(TElGoogleDataStorageObject *Obj)
{
	SBCheckError(TElGoogleDataStorage_RefreshObject(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElGoogleDataStorage::WriteObject(const std::string &Title, TStream &Data, TSBGoogleDocType DocType, const std::string &ContentType, bool Convert, TSBGoogleDataStorageEncoding Encoding, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElGoogleDataStorage_WriteObject(_Handle, Title.data(), (int32_t)Title.length(), Data.getHandle(), (TSBGoogleDocTypeRaw)DocType, ContentType.data(), (int32_t)ContentType.length(), (int8_t)Convert, (TSBGoogleDataStorageEncodingRaw)Encoding, Handler.getHandle()));
}

SB_INLINE void TElGoogleDataStorage::WriteObject(const std::string &Title, TStream *Data, TSBGoogleDocType DocType, const std::string &ContentType, bool Convert, TSBGoogleDataStorageEncoding Encoding, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElGoogleDataStorage_WriteObject(_Handle, Title.data(), (int32_t)Title.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (TSBGoogleDocTypeRaw)DocType, ContentType.data(), (int32_t)ContentType.length(), (int8_t)Convert, (TSBGoogleDataStorageEncodingRaw)Encoding, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElGoogleDataStorage::WriteObject(const std::string &Title, TStream &Data, TSBGoogleDocType DocType, const std::string &ContentType, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElGoogleDataStorage_WriteObject_1(_Handle, Title.data(), (int32_t)Title.length(), Data.getHandle(), (TSBGoogleDocTypeRaw)DocType, ContentType.data(), (int32_t)ContentType.length(), Handler.getHandle()));
}

SB_INLINE void TElGoogleDataStorage::WriteObject(const std::string &Title, TStream *Data, TSBGoogleDocType DocType, const std::string &ContentType, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElGoogleDataStorage_WriteObject_1(_Handle, Title.data(), (int32_t)Title.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (TSBGoogleDocTypeRaw)DocType, ContentType.data(), (int32_t)ContentType.length(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELGOOGLEDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElGoogleDataStorage::WriteObject(TElGoogleDataStorageObject &Obj, TStream &Data, bool OverwriteChanges, bool Append, const std::string &ContentType, TSBGoogleDataStorageEncoding Encoding, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElGoogleDataStorage_WriteObject_2(_Handle, Obj.getHandle(), Data.getHandle(), (int8_t)OverwriteChanges, (int8_t)Append, ContentType.data(), (int32_t)ContentType.length(), (TSBGoogleDataStorageEncodingRaw)Encoding, Handler.getHandle()));
}

SB_INLINE void TElGoogleDataStorage::WriteObject(TElGoogleDataStorageObject *Obj, TStream *Data, bool OverwriteChanges, bool Append, const std::string &ContentType, TSBGoogleDataStorageEncoding Encoding, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElGoogleDataStorage_WriteObject_2(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (int8_t)OverwriteChanges, (int8_t)Append, ContentType.data(), (int32_t)ContentType.length(), (TSBGoogleDataStorageEncodingRaw)Encoding, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELGOOGLEDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELGOOGLEDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElGoogleDataStorage::ReadObject(TElGoogleDataStorageObject &Obj, TStream &Strm)
{
	SBCheckError(TElGoogleDataStorage_ReadObject(_Handle, Obj.getHandle(), Strm.getHandle()));
}

SB_INLINE void TElGoogleDataStorage::ReadObject(TElGoogleDataStorageObject *Obj, TStream *Strm)
{
	SBCheckError(TElGoogleDataStorage_ReadObject(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELGOOGLEDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELGOOGLEDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElGoogleDataStorage::ReadObject(TElGoogleDataStorageObject &Obj, TStream &Strm, TSBGoogleDataStorageEncoding Encoding)
{
	SBCheckError(TElGoogleDataStorage_ReadObject_1(_Handle, Obj.getHandle(), Strm.getHandle(), (TSBGoogleDataStorageEncodingRaw)Encoding));
}

SB_INLINE void TElGoogleDataStorage::ReadObject(TElGoogleDataStorageObject *Obj, TStream *Strm, TSBGoogleDataStorageEncoding Encoding)
{
	SBCheckError(TElGoogleDataStorage_ReadObject_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBGoogleDataStorageEncodingRaw)Encoding));
}
#endif /* SB_USE_CLASSES_TELGOOGLEDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELGOOGLEDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElGoogleDataStorage::ReadObject(TElGoogleDataStorageObject &Obj, TStream &Strm, const std::string &Format, TSBGoogleDataStorageEncoding Encoding)
{
	SBCheckError(TElGoogleDataStorage_ReadObject_2(_Handle, Obj.getHandle(), Strm.getHandle(), Format.data(), (int32_t)Format.length(), (TSBGoogleDataStorageEncodingRaw)Encoding));
}

SB_INLINE void TElGoogleDataStorage::ReadObject(TElGoogleDataStorageObject *Obj, TStream *Strm, const std::string &Format, TSBGoogleDataStorageEncoding Encoding)
{
	SBCheckError(TElGoogleDataStorage_ReadObject_2(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Format.data(), (int32_t)Format.length(), (TSBGoogleDataStorageEncodingRaw)Encoding));
}
#endif /* SB_USE_CLASSES_TELGOOGLEDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELGOOGLEDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElGoogleDataStorage::ReadObject(TElGoogleDataStorageObject &Folder, const std::string &Title, TStream &Strm, const std::string &Format, TSBGoogleDataStorageEncoding Encoding)
{
	SBCheckError(TElGoogleDataStorage_ReadObject_3(_Handle, Folder.getHandle(), Title.data(), (int32_t)Title.length(), Strm.getHandle(), Format.data(), (int32_t)Format.length(), (TSBGoogleDataStorageEncodingRaw)Encoding));
}

SB_INLINE void TElGoogleDataStorage::ReadObject(TElGoogleDataStorageObject *Folder, const std::string &Title, TStream *Strm, const std::string &Format, TSBGoogleDataStorageEncoding Encoding)
{
	SBCheckError(TElGoogleDataStorage_ReadObject_3(_Handle, (Folder != NULL) ? Folder->getHandle() : SB_NULL_HANDLE, Title.data(), (int32_t)Title.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Format.data(), (int32_t)Format.length(), (TSBGoogleDataStorageEncodingRaw)Encoding));
}
#endif /* SB_USE_CLASSES_TELGOOGLEDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELGOOGLEDATASTORAGEOBJECT
SB_INLINE TElCustomDataStorageObjectHandle TElGoogleDataStorage::CopyObject(TElGoogleDataStorageObject &Obj, const std::string &DestTitle)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDataStorage_CopyObject(_Handle, Obj.getHandle(), DestTitle.data(), (int32_t)DestTitle.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElGoogleDataStorage::CopyObject(TElGoogleDataStorageObject *Obj, const std::string &DestTitle)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDataStorage_CopyObject(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, DestTitle.data(), (int32_t)DestTitle.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELGOOGLEDATASTORAGEOBJECT
SB_INLINE TElCustomDataStorageObjectHandle TElGoogleDataStorage::CopyObject(TElGoogleDataStorageObject &Folder, const std::string &SrcTitle, const std::string &DestTitle)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDataStorage_CopyObject_1(_Handle, Folder.getHandle(), SrcTitle.data(), (int32_t)SrcTitle.length(), DestTitle.data(), (int32_t)DestTitle.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElGoogleDataStorage::CopyObject(TElGoogleDataStorageObject *Folder, const std::string &SrcTitle, const std::string &DestTitle)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDataStorage_CopyObject_1(_Handle, (Folder != NULL) ? Folder->getHandle() : SB_NULL_HANDLE, SrcTitle.data(), (int32_t)SrcTitle.length(), DestTitle.data(), (int32_t)DestTitle.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
SB_INLINE void TElGoogleDataStorage::MoveObject(TElGoogleDataStorageObject &Obj, TElGoogleDataStorageObject &DestFolder)
{
	SBCheckError(TElGoogleDataStorage_MoveObject(_Handle, Obj.getHandle(), DestFolder.getHandle()));
}

SB_INLINE void TElGoogleDataStorage::MoveObject(TElGoogleDataStorageObject *Obj, TElGoogleDataStorageObject *DestFolder)
{
	SBCheckError(TElGoogleDataStorage_MoveObject(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (DestFolder != NULL) ? DestFolder->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
SB_INLINE void TElGoogleDataStorage::MoveObject(TElGoogleDataStorageObject &Folder, const std::string &Title, TElGoogleDataStorageObject &DestFolder)
{
	SBCheckError(TElGoogleDataStorage_MoveObject_1(_Handle, Folder.getHandle(), Title.data(), (int32_t)Title.length(), DestFolder.getHandle()));
}

SB_INLINE void TElGoogleDataStorage::MoveObject(TElGoogleDataStorageObject *Folder, const std::string &Title, TElGoogleDataStorageObject *DestFolder)
{
	SBCheckError(TElGoogleDataStorage_MoveObject_1(_Handle, (Folder != NULL) ? Folder->getHandle() : SB_NULL_HANDLE, Title.data(), (int32_t)Title.length(), (DestFolder != NULL) ? DestFolder->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
SB_INLINE TElGoogleDataStorageObjectHandle TElGoogleDataStorage::GetObjectFolder(TElGoogleDataStorageObject &Obj)
{
	TElGoogleDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDataStorage_GetObjectFolder(_Handle, Obj.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElGoogleDataStorageObjectHandle TElGoogleDataStorage::GetObjectFolder(TElGoogleDataStorageObject *Obj)
{
	TElGoogleDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDataStorage_GetObjectFolder(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

TSBGoogleAuthType TElGoogleDataStorage::get_AuthType()
{
	TSBGoogleAuthTypeRaw OutResultRaw = 0;
	SBCheckError(TElGoogleDataStorage_get_AuthType(_Handle, &OutResultRaw));
	return (TSBGoogleAuthType)OutResultRaw;
}

SB_INLINE void TElGoogleDataStorage::set_AuthType(TSBGoogleAuthType Value)
{
	SBCheckError(TElGoogleDataStorage_set_AuthType(_Handle, (TSBGoogleAuthTypeRaw)Value));
}

TSBGoogleDataStorageEncoding TElGoogleDataStorage::get_DefObjectEncoding()
{
	TSBGoogleDataStorageEncodingRaw OutResultRaw = 0;
	SBCheckError(TElGoogleDataStorage_get_DefObjectEncoding(_Handle, &OutResultRaw));
	return (TSBGoogleDataStorageEncoding)OutResultRaw;
}

SB_INLINE void TElGoogleDataStorage::set_DefObjectEncoding(TSBGoogleDataStorageEncoding Value)
{
	SBCheckError(TElGoogleDataStorage_set_DefObjectEncoding(_Handle, (TSBGoogleDataStorageEncodingRaw)Value));
}

TSBGDataVersion TElGoogleDataStorage::get_Version()
{
	TSBGDataVersionRaw OutResultRaw = 0;
	SBCheckError(TElGoogleDataStorage_get_Version(_Handle, &OutResultRaw));
	return (TSBGDataVersion)OutResultRaw;
}

SB_INLINE void TElGoogleDataStorage::set_Version(TSBGDataVersion Value)
{
	SBCheckError(TElGoogleDataStorage_set_Version(_Handle, (TSBGDataVersionRaw)Value));
}

bool TElGoogleDataStorage::get_UseSSL()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDataStorage_get_UseSSL(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGoogleDataStorage::set_UseSSL(bool Value)
{
	SBCheckError(TElGoogleDataStorage_set_UseSSL(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
TElHTTPSClient* TElGoogleDataStorage::get_HTTPClient()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDataStorage_get_HTTPClient(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HTTPClient)
		this->_Inst_HTTPClient = new TElHTTPSClient(hOutResult, ohFalse);
	else
		this->_Inst_HTTPClient->updateHandle(hOutResult);
	return this->_Inst_HTTPClient;
}

SB_INLINE void TElGoogleDataStorage::set_HTTPClient(TElHTTPSClient &Value)
{
	SBCheckError(TElGoogleDataStorage_set_HTTPClient(_Handle, Value.getHandle()));
}

SB_INLINE void TElGoogleDataStorage::set_HTTPClient(TElHTTPSClient *Value)
{
	SBCheckError(TElGoogleDataStorage_set_HTTPClient(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

void TElGoogleDataStorage::get_Username(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorage_get_Username(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(414246903, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGoogleDataStorage::set_Username(const std::string &Value)
{
	SBCheckError(TElGoogleDataStorage_set_Username(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElGoogleDataStorage::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorage_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-718493867, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGoogleDataStorage::set_Password(const std::string &Value)
{
	SBCheckError(TElGoogleDataStorage_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElGoogleDataStorage::get_ServiceName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorage_get_ServiceName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1886817259, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGoogleDataStorage::set_ServiceName(const std::string &Value)
{
	SBCheckError(TElGoogleDataStorage_set_ServiceName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElGoogleDataStorage::get_SecondaryServiceName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorage_get_SecondaryServiceName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1290846202, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGoogleDataStorage::set_SecondaryServiceName(const std::string &Value)
{
	SBCheckError(TElGoogleDataStorage_set_SecondaryServiceName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElGoogleDataStorage::get_ServerAddress(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorage_get_ServerAddress(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1497765940, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGoogleDataStorage::set_ServerAddress(const std::string &Value)
{
	SBCheckError(TElGoogleDataStorage_set_ServerAddress(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElGoogleDataStorage::get_AuthServerAddress(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorage_get_AuthServerAddress(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-545497130, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGoogleDataStorage::set_AuthServerAddress(const std::string &Value)
{
	SBCheckError(TElGoogleDataStorage_set_AuthServerAddress(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElGoogleDataStorage::get_AuthSource(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorage_get_AuthSource(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1284800744, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGoogleDataStorage::set_AuthSource(const std::string &Value)
{
	SBCheckError(TElGoogleDataStorage_set_AuthSource(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElGoogleDataStorage::get_AuthToken(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorage_get_AuthToken(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-760242980, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGoogleDataStorage::set_AuthToken(const std::string &Value)
{
	SBCheckError(TElGoogleDataStorage_set_AuthToken(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElGoogleDataStorage::get_SecondaryAuthToken(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorage_get_SecondaryAuthToken(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1734172814, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGoogleDataStorage::set_SecondaryAuthToken(const std::string &Value)
{
	SBCheckError(TElGoogleDataStorage_set_SecondaryAuthToken(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElGoogleDataStorage::get_MaxAuthAttempts()
{
	int32_t OutResult;
	SBCheckError(TElGoogleDataStorage_get_MaxAuthAttempts(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGoogleDataStorage::set_MaxAuthAttempts(int32_t Value)
{
	SBCheckError(TElGoogleDataStorage_set_MaxAuthAttempts(_Handle, Value));
}

void TElGoogleDataStorage::get_SecMetadataID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorage_get_SecMetadataID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(664188437, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGoogleDataStorage::set_SecMetadataID(const std::string &Value)
{
	SBCheckError(TElGoogleDataStorage_set_SecMetadataID(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElGoogleDataStorage::get_UseURLEncoding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDataStorage_get_UseURLEncoding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGoogleDataStorage::set_UseURLEncoding(bool Value)
{
	SBCheckError(TElGoogleDataStorage_set_UseURLEncoding(_Handle, (int8_t)Value));
}

bool TElGoogleDataStorage::get_IgnoreContentSrc()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDataStorage_get_IgnoreContentSrc(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGoogleDataStorage::set_IgnoreContentSrc(bool Value)
{
	SBCheckError(TElGoogleDataStorage_set_IgnoreContentSrc(_Handle, (int8_t)Value));
}

SB_INLINE void TElGoogleDataStorage::get_OnAuthAttempt(TSBGoogleAuthAttemptEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElGoogleDataStorage_get_OnAuthAttempt(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElGoogleDataStorage::set_OnAuthAttempt(TSBGoogleAuthAttemptEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElGoogleDataStorage_set_OnAuthAttempt(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElGoogleDataStorage::get_OnAuthCaptchaRequest(TSBGoogleAuthCaptchaRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElGoogleDataStorage_get_OnAuthCaptchaRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElGoogleDataStorage::set_OnAuthCaptchaRequest(TSBGoogleAuthCaptchaRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElGoogleDataStorage_set_OnAuthCaptchaRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElGoogleDataStorage::get_OnAuthAttemptFailed(TSBGoogleAuthAttemptFailedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElGoogleDataStorage_get_OnAuthAttemptFailed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElGoogleDataStorage::set_OnAuthAttemptFailed(TSBGoogleAuthAttemptFailedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElGoogleDataStorage_set_OnAuthAttemptFailed(_Handle, pMethodValue, pDataValue));
}

void TElGoogleDataStorage::initInstances()
{
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
}

TElGoogleDataStorage::TElGoogleDataStorage(TElGoogleDataStorageHandle handle, TElOwnHandle ownHandle) : TElCustomDataStorage(handle, ownHandle)
{
	initInstances();
}

TElGoogleDataStorage::TElGoogleDataStorage(TComponent &AOwner) : TElCustomDataStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDataStorage_Create(AOwner.getHandle(), &_Handle));
}

TElGoogleDataStorage::TElGoogleDataStorage(TComponent *AOwner) : TElCustomDataStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDataStorage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElGoogleDataStorage::~TElGoogleDataStorage()
{
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	delete this->_Inst_HTTPClient;
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
}
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGE */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTCATEGORIES

SB_INLINE void TElGoogleDataStorageObjectCategories::Assign(TElGoogleDataStorageObjectCategories &Source)
{
	SBCheckError(TElGoogleDataStorageObjectCategories_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElGoogleDataStorageObjectCategories::Assign(TElGoogleDataStorageObjectCategories *Source)
{
	SBCheckError(TElGoogleDataStorageObjectCategories_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElGoogleDataStorageObjectCategories::Clear()
{
	SBCheckError(TElGoogleDataStorageObjectCategories_Clear(_Handle));
}

void TElGoogleDataStorageObjectCategories::get_Schemes(int32_t Index, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorageObjectCategories_get_Schemes(_Handle, Index, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1556140365, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDataStorageObjectCategories::get_Terms(int32_t Index, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorageObjectCategories_get_Terms(_Handle, Index, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1993641199, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDataStorageObjectCategories::get_Labels(int32_t Index, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorageObjectCategories_get_Labels(_Handle, Index, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-336505794, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElGoogleDataStorageObjectCategories::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElGoogleDataStorageObjectCategories_get_Count(_Handle, &OutResult));
	return OutResult;
}

TElGoogleDataStorageObjectCategories::TElGoogleDataStorageObjectCategories(TElGoogleDataStorageObjectCategoriesHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElGoogleDataStorageObjectCategories::TElGoogleDataStorageObjectCategories() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGoogleDataStorageObjectCategories_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTCATEGORIES */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTLINKS

SB_INLINE void TElGoogleDataStorageObjectLinks::Assign(TElGoogleDataStorageObjectLinks &Source)
{
	SBCheckError(TElGoogleDataStorageObjectLinks_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElGoogleDataStorageObjectLinks::Assign(TElGoogleDataStorageObjectLinks *Source)
{
	SBCheckError(TElGoogleDataStorageObjectLinks_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElGoogleDataStorageObjectLinks::Clear()
{
	SBCheckError(TElGoogleDataStorageObjectLinks_Clear(_Handle));
}

void TElGoogleDataStorageObjectLinks::get_Rels(int32_t Index, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorageObjectLinks_get_Rels(_Handle, Index, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1080938102, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDataStorageObjectLinks::get_Types(int32_t Index, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorageObjectLinks_get_Types(_Handle, Index, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-733272488, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDataStorageObjectLinks::get_Hrefs(int32_t Index, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorageObjectLinks_get_Hrefs(_Handle, Index, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2147468209, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDataStorageObjectLinks::get_Titles(int32_t Index, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorageObjectLinks_get_Titles(_Handle, Index, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-587567184, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElGoogleDataStorageObjectLinks::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElGoogleDataStorageObjectLinks_get_Count(_Handle, &OutResult));
	return OutResult;
}

TElGoogleDataStorageObjectLinks::TElGoogleDataStorageObjectLinks(TElGoogleDataStorageObjectLinksHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElGoogleDataStorageObjectLinks::TElGoogleDataStorageObjectLinks() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGoogleDataStorageObjectLinks_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTLINKS */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT

SB_INLINE void TElGoogleDataStorageObject::Assign(TElCustomDataStorageObject &Source)
{
	SBCheckError(TElGoogleDataStorageObject_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElGoogleDataStorageObject::Assign(TElCustomDataStorageObject *Source)
{
	SBCheckError(TElGoogleDataStorageObject_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElCustomDataStorageObjectHandle TElGoogleDataStorageObject::Clone()
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDataStorageObject_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
SB_INLINE void TElGoogleDataStorageObject::ParseEntry(TElXMLDOMNode &Node)
{
	SBCheckError(TElGoogleDataStorageObject_ParseEntry(_Handle, Node.getHandle()));
}

SB_INLINE void TElGoogleDataStorageObject::ParseEntry(TElXMLDOMNode *Node)
{
	SBCheckError(TElGoogleDataStorageObject_ParseEntry(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

SB_INLINE void TElGoogleDataStorageObject::Clear()
{
	SBCheckError(TElGoogleDataStorageObject_Clear(_Handle));
}

SB_INLINE void TElGoogleDataStorageObject::Delete()
{
	SBCheckError(TElGoogleDataStorageObject_Delete(_Handle));
}

SB_INLINE void TElGoogleDataStorageObject::Delete(bool DeletePermanently)
{
	SBCheckError(TElGoogleDataStorageObject_Delete_1(_Handle, (int8_t)DeletePermanently));
}

bool TElGoogleDataStorageObject::Exists()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDataStorageObject_Exists(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGoogleDataStorageObject::Refresh()
{
	SBCheckError(TElGoogleDataStorageObject_Refresh(_Handle));
}

SB_INLINE TElCustomDataStorageObjectHandle TElGoogleDataStorageObject::Copy(const std::string &DestTitle)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDataStorageObject_Copy(_Handle, DestTitle.data(), (int32_t)DestTitle.length(), &OutResult));
	return OutResult;
}

SB_INLINE void TElGoogleDataStorageObject::Move(TElGoogleDataStorageObject &DestFolder)
{
	SBCheckError(TElGoogleDataStorageObject_Move(_Handle, DestFolder.getHandle()));
}

SB_INLINE void TElGoogleDataStorageObject::Move(TElGoogleDataStorageObject *DestFolder)
{
	SBCheckError(TElGoogleDataStorageObject_Move(_Handle, (DestFolder != NULL) ? DestFolder->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElGoogleDataStorageObject::Write(TStream &Data, bool OverwriteChanges, bool Append, const std::string &ContentType, TSBGoogleDataStorageEncoding Encoding, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElGoogleDataStorageObject_Write(_Handle, Data.getHandle(), (int8_t)OverwriteChanges, (int8_t)Append, ContentType.data(), (int32_t)ContentType.length(), (TSBGoogleDataStorageEncodingRaw)Encoding, Handler.getHandle()));
}

SB_INLINE void TElGoogleDataStorageObject::Write(TStream *Data, bool OverwriteChanges, bool Append, const std::string &ContentType, TSBGoogleDataStorageEncoding Encoding, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElGoogleDataStorageObject_Write(_Handle, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (int8_t)OverwriteChanges, (int8_t)Append, ContentType.data(), (int32_t)ContentType.length(), (TSBGoogleDataStorageEncodingRaw)Encoding, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElGoogleDataStorageObject::Read(TStream &Strm)
{
	SBCheckError(TElGoogleDataStorageObject_Read(_Handle, Strm.getHandle()));
}

SB_INLINE void TElGoogleDataStorageObject::Read(TStream *Strm)
{
	SBCheckError(TElGoogleDataStorageObject_Read(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElGoogleDataStorageObject::Read(TStream &Strm, TSBGoogleDataStorageEncoding Encoding)
{
	SBCheckError(TElGoogleDataStorageObject_Read_1(_Handle, Strm.getHandle(), (TSBGoogleDataStorageEncodingRaw)Encoding));
}

SB_INLINE void TElGoogleDataStorageObject::Read(TStream *Strm, TSBGoogleDataStorageEncoding Encoding)
{
	SBCheckError(TElGoogleDataStorageObject_Read_1(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBGoogleDataStorageEncodingRaw)Encoding));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElGoogleDataStorageObject::Read(TStream &Strm, const std::string &Format, TSBGoogleDataStorageEncoding Encoding)
{
	SBCheckError(TElGoogleDataStorageObject_Read_2(_Handle, Strm.getHandle(), Format.data(), (int32_t)Format.length(), (TSBGoogleDataStorageEncodingRaw)Encoding));
}

SB_INLINE void TElGoogleDataStorageObject::Read(TStream *Strm, const std::string &Format, TSBGoogleDataStorageEncoding Encoding)
{
	SBCheckError(TElGoogleDataStorageObject_Read_2(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Format.data(), (int32_t)Format.length(), (TSBGoogleDataStorageEncodingRaw)Encoding));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE TElGoogleDataStorageObjectHandle TElGoogleDataStorageObject::AcquireObject(const std::string &Title)
{
	TElGoogleDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDataStorageObject_AcquireObject(_Handle, Title.data(), (int32_t)Title.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElGoogleDataStorageObject::ReadObject(const std::string &Title, TStream &Strm, const std::string &Format, TSBGoogleDataStorageEncoding Encoding)
{
	SBCheckError(TElGoogleDataStorageObject_ReadObject(_Handle, Title.data(), (int32_t)Title.length(), Strm.getHandle(), Format.data(), (int32_t)Format.length(), (TSBGoogleDataStorageEncodingRaw)Encoding));
}

SB_INLINE void TElGoogleDataStorageObject::ReadObject(const std::string &Title, TStream *Strm, const std::string &Format, TSBGoogleDataStorageEncoding Encoding)
{
	SBCheckError(TElGoogleDataStorageObject_ReadObject(_Handle, Title.data(), (int32_t)Title.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Format.data(), (int32_t)Format.length(), (TSBGoogleDataStorageEncodingRaw)Encoding));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElGoogleDataStorageObject::List(TElDataStorageObjectList &Objects)
{
	SBCheckError(TElGoogleDataStorageObject_List(_Handle, Objects.getHandle()));
}

SB_INLINE void TElGoogleDataStorageObject::List(TElDataStorageObjectList *Objects)
{
	SBCheckError(TElGoogleDataStorageObject_List(_Handle, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElGoogleDataStorageObject::List(const std::string &Query, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElGoogleDataStorageObject_List_1(_Handle, Query.data(), (int32_t)Query.length(), (int8_t)ShowFolders, (int8_t)ShowDeleted, (TSBGoogleEntryOrderRaw)OrderBy, Objects.getHandle()));
}

SB_INLINE void TElGoogleDataStorageObject::List(const std::string &Query, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElGoogleDataStorageObject_List_1(_Handle, Query.data(), (int32_t)Query.length(), (int8_t)ShowFolders, (int8_t)ShowDeleted, (TSBGoogleEntryOrderRaw)OrderBy, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElGoogleDataStorageObject::List(const std::string &Query, const std::string &Alt, const std::string &Author, int64_t StartIndex, int64_t MaxResults, int64_t UpdatedMin, int64_t UpdatedMax, const std::string &Category, const std::string &Title, bool ExactTitle, int64_t OpenedMin, int64_t OpenedMax, const std::string &Owner, const std::string &Writer, const std::string &Reader, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElGoogleDataStorageObject_List_2(_Handle, Query.data(), (int32_t)Query.length(), Alt.data(), (int32_t)Alt.length(), Author.data(), (int32_t)Author.length(), StartIndex, MaxResults, UpdatedMin, UpdatedMax, Category.data(), (int32_t)Category.length(), Title.data(), (int32_t)Title.length(), (int8_t)ExactTitle, OpenedMin, OpenedMax, Owner.data(), (int32_t)Owner.length(), Writer.data(), (int32_t)Writer.length(), Reader.data(), (int32_t)Reader.length(), (int8_t)ShowFolders, (int8_t)ShowDeleted, (TSBGoogleEntryOrderRaw)OrderBy, Objects.getHandle()));
}

SB_INLINE void TElGoogleDataStorageObject::List(const std::string &Query, const std::string &Alt, const std::string &Author, int64_t StartIndex, int64_t MaxResults, int64_t UpdatedMin, int64_t UpdatedMax, const std::string &Category, const std::string &Title, bool ExactTitle, int64_t OpenedMin, int64_t OpenedMax, const std::string &Owner, const std::string &Writer, const std::string &Reader, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElGoogleDataStorageObject_List_2(_Handle, Query.data(), (int32_t)Query.length(), Alt.data(), (int32_t)Alt.length(), Author.data(), (int32_t)Author.length(), StartIndex, MaxResults, UpdatedMin, UpdatedMax, Category.data(), (int32_t)Category.length(), Title.data(), (int32_t)Title.length(), (int8_t)ExactTitle, OpenedMin, OpenedMax, Owner.data(), (int32_t)Owner.length(), Writer.data(), (int32_t)Writer.length(), Reader.data(), (int32_t)Reader.length(), (int8_t)ShowFolders, (int8_t)ShowDeleted, (TSBGoogleEntryOrderRaw)OrderBy, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

SB_INLINE void TElGoogleDataStorageObject::DeleteObject(const std::string &Title, bool DeletePermanently)
{
	SBCheckError(TElGoogleDataStorageObject_DeleteObject(_Handle, Title.data(), (int32_t)Title.length(), (int8_t)DeletePermanently));
}

bool TElGoogleDataStorageObject::ObjectExists(const std::string &Title)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDataStorageObject_ObjectExists(_Handle, Title.data(), (int32_t)Title.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TElCustomDataStorageObjectHandle TElGoogleDataStorageObject::CopyObject(const std::string &SrcTitle, const std::string &DestTitle)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDataStorageObject_CopyObject(_Handle, SrcTitle.data(), (int32_t)SrcTitle.length(), DestTitle.data(), (int32_t)DestTitle.length(), &OutResult));
	return OutResult;
}

SB_INLINE void TElGoogleDataStorageObject::MoveObject(const std::string &Title, TElGoogleDataStorageObject &DestFolder)
{
	SBCheckError(TElGoogleDataStorageObject_MoveObject(_Handle, Title.data(), (int32_t)Title.length(), DestFolder.getHandle()));
}

SB_INLINE void TElGoogleDataStorageObject::MoveObject(const std::string &Title, TElGoogleDataStorageObject *DestFolder)
{
	SBCheckError(TElGoogleDataStorageObject_MoveObject(_Handle, Title.data(), (int32_t)Title.length(), (DestFolder != NULL) ? DestFolder->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElGoogleDataStorageObjectHandle TElGoogleDataStorageObject::GetFolder()
{
	TElGoogleDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDataStorageObject_GetFolder(_Handle, &OutResult));
	return OutResult;
}

bool TElGoogleDataStorageObject::get_Folder()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDataStorageObject_get_Folder(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElGoogleDataStorageObject::get_ObjectType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorageObject_get_ObjectType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-955134422, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDataStorageObject::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorageObject_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2065616811, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDataStorageObject::get_Title(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorageObject_get_Title(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(259808738, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDataStorageObject::get_Summary(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorageObject_get_Summary(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(783591315, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDataStorageObject::get_ContentSrc(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorageObject_get_ContentSrc(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-617244686, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDataStorageObject::get_ContentType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorageObject_get_ContentType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1629641286, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDataStorageObject::get_AuthorName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorageObject_get_AuthorName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(870354700, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDataStorageObject::get_AuthorEmail(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorageObject_get_AuthorEmail(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-718751466, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTCATEGORIES
TElGoogleDataStorageObjectCategories* TElGoogleDataStorageObject::get_Categories()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDataStorageObject_get_Categories(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Categories)
		this->_Inst_Categories = new TElGoogleDataStorageObjectCategories(hOutResult, ohFalse);
	else
		this->_Inst_Categories->updateHandle(hOutResult);
	return this->_Inst_Categories;
}
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTCATEGORIES */

SB_INLINE int64_t TElGoogleDataStorageObject::get_PublicationDate()
{
	int64_t OutResult;
	SBCheckError(TElGoogleDataStorageObject_get_PublicationDate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElGoogleDataStorageObject::get_UpdateDate()
{
	int64_t OutResult;
	SBCheckError(TElGoogleDataStorageObject_get_UpdateDate(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTLINKS
TElGoogleDataStorageObjectLinks* TElGoogleDataStorageObject::get_Links()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDataStorageObject_get_Links(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Links)
		this->_Inst_Links = new TElGoogleDataStorageObjectLinks(hOutResult, ohFalse);
	else
		this->_Inst_Links->updateHandle(hOutResult);
	return this->_Inst_Links;
}
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTLINKS */

void TElGoogleDataStorageObject::get_ResourceID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorageObject_get_ResourceID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-700002501, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDataStorageObject::get_CompleteResourceID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorageObject_get_CompleteResourceID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1688646427, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDataStorageObject::get_ResourceType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorageObject_get_ResourceType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1420889089, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDataStorageObject::get_LastModifiedByName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorageObject_get_LastModifiedByName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1251104707, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDataStorageObject::get_LastModifiedByEmail(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorageObject_get_LastModifiedByEmail(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2073021429, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElGoogleDataStorageObject::get_LastViewedDate()
{
	int64_t OutResult;
	SBCheckError(TElGoogleDataStorageObject_get_LastViewedDate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElGoogleDataStorageObject::get_QuotaBytesUsed()
{
	int64_t OutResult;
	SBCheckError(TElGoogleDataStorageObject_get_QuotaBytesUsed(_Handle, &OutResult));
	return OutResult;
}

bool TElGoogleDataStorageObject::get_WritersCanInvite()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDataStorageObject_get_WritersCanInvite(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGoogleDataStorageObject::get_Starred()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDataStorageObject_get_Starred(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGoogleDataStorageObject::get_Trashed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDataStorageObject_get_Trashed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGoogleDataStorageObject::get_Hidden()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDataStorageObject_get_Hidden(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGoogleDataStorageObject::get_Viewed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDataStorageObject_get_Viewed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGoogleDataStorageObject::get_Mine()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDataStorageObject_get_Mine(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGoogleDataStorageObject::get_PrivateObj()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDataStorageObject_get_PrivateObj(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGoogleDataStorageObject::get_SharedWithDomain()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDataStorageObject_get_SharedWithDomain(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElGoogleDataStorageObject::get_ContainingFolders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDataStorageObject_get_ContainingFolders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ContainingFolders)
		this->_Inst_ContainingFolders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_ContainingFolders->updateHandle(hOutResult);
	return this->_Inst_ContainingFolders;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElGoogleDataStorageObject::get_ContainingFolders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDataStorageObject_get_ContainingFolders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ContainingFolders)
		this->_Inst_ContainingFolders = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_ContainingFolders->updateHandle(hOutResult);
	return this->_Inst_ContainingFolders;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElGoogleDataStorageObject::get_ETag(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDataStorageObject_get_ETag(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(416657289, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBGoogleDocType TElGoogleDataStorageObject::get_DocType()
{
	TSBGoogleDocTypeRaw OutResultRaw = 0;
	SBCheckError(TElGoogleDataStorageObject_get_DocType(_Handle, &OutResultRaw));
	return (TSBGoogleDocType)OutResultRaw;
}

void TElGoogleDataStorageObject::initInstances()
{
#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTCATEGORIES
	this->_Inst_Categories = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTCATEGORIES */
#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTLINKS
	this->_Inst_Links = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTLINKS */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_ContainingFolders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_ContainingFolders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElGoogleDataStorageObject::TElGoogleDataStorageObject(TElGoogleDataStorageObjectHandle handle, TElOwnHandle ownHandle) : TElCustomDataStorageObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGE
TElGoogleDataStorageObject::TElGoogleDataStorageObject(TElGoogleDataStorage &Owner) : TElCustomDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDataStorageObject_Create(Owner.getHandle(), &_Handle));
}

TElGoogleDataStorageObject::TElGoogleDataStorageObject(TElGoogleDataStorage *Owner) : TElCustomDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDataStorageObject_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGE */

TElGoogleDataStorageObject::~TElGoogleDataStorageObject()
{
#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTCATEGORIES
	delete this->_Inst_Categories;
	this->_Inst_Categories = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTCATEGORIES */
#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTLINKS
	delete this->_Inst_Links;
	this->_Inst_Links = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTLINKS */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_ContainingFolders;
	this->_Inst_ContainingFolders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_ContainingFolders;
	this->_Inst_ContainingFolders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEPREFIXEDPOSTFIXEDUPLOADSTREAM

SB_INLINE int32_t TElGooglePrefixedPostfixedUploadStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElGooglePrefixedPostfixedUploadStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElGooglePrefixedPostfixedUploadStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElGooglePrefixedPostfixedUploadStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElGooglePrefixedPostfixedUploadStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TElGooglePrefixedPostfixedUploadStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElGooglePrefixedPostfixedUploadStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElGooglePrefixedPostfixedUploadStream_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

TElGooglePrefixedPostfixedUploadStream::TElGooglePrefixedPostfixedUploadStream(TElGooglePrefixedPostfixedUploadStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
}

TElGooglePrefixedPostfixedUploadStream TElGooglePrefixedPostfixedUploadStream::CreateMultipartRelated(TStream &SourceStream, const std::string &Boundary, const std::vector<uint8_t> &AtomXmlPart, const std::string &ContentType, int64_t Count, bool ReleaseSourceStream)
{
	TElGooglePrefixedPostfixedUploadStreamHandle _Handle;
	SBCheckError(TElGooglePrefixedPostfixedUploadStream_CreateMultipartRelated(SourceStream.getHandle(), Boundary.data(), (int32_t)Boundary.length(), SB_STD_VECTOR_FRONT_ADR(AtomXmlPart), (int32_t)AtomXmlPart.size(), ContentType.data(), (int32_t)ContentType.length(), Count, (int8_t)ReleaseSourceStream, &_Handle));
	return TElGooglePrefixedPostfixedUploadStream(_Handle, SB_OWN_HANDLE);
}

TElGooglePrefixedPostfixedUploadStream TElGooglePrefixedPostfixedUploadStream::CreateMultipartRelated(TStream *SourceStream, const std::string &Boundary, const std::vector<uint8_t> &AtomXmlPart, const std::string &ContentType, int64_t Count, bool ReleaseSourceStream)
{
	TElGooglePrefixedPostfixedUploadStreamHandle _Handle;
	SBCheckError(TElGooglePrefixedPostfixedUploadStream_CreateMultipartRelated((SourceStream != NULL) ? SourceStream->getHandle() : SB_NULL_HANDLE, Boundary.data(), (int32_t)Boundary.length(), SB_STD_VECTOR_FRONT_ADR(AtomXmlPart), (int32_t)AtomXmlPart.size(), ContentType.data(), (int32_t)ContentType.length(), Count, (int8_t)ReleaseSourceStream, &_Handle));
	return TElGooglePrefixedPostfixedUploadStream(_Handle, SB_OWN_HANDLE);
}

TElGooglePrefixedPostfixedUploadStream TElGooglePrefixedPostfixedUploadStream::CreatePrefixed(TStream &SourceStream, const std::vector<uint8_t> &Prefix, int64_t Count, bool ReleaseSourceStream)
{
	TElGooglePrefixedPostfixedUploadStreamHandle _Handle;
	SBCheckError(TElGooglePrefixedPostfixedUploadStream_CreatePrefixed(SourceStream.getHandle(), SB_STD_VECTOR_FRONT_ADR(Prefix), (int32_t)Prefix.size(), Count, (int8_t)ReleaseSourceStream, &_Handle));
	return TElGooglePrefixedPostfixedUploadStream(_Handle, SB_OWN_HANDLE);
}

TElGooglePrefixedPostfixedUploadStream TElGooglePrefixedPostfixedUploadStream::CreatePrefixed(TStream *SourceStream, const std::vector<uint8_t> &Prefix, int64_t Count, bool ReleaseSourceStream)
{
	TElGooglePrefixedPostfixedUploadStreamHandle _Handle;
	SBCheckError(TElGooglePrefixedPostfixedUploadStream_CreatePrefixed((SourceStream != NULL) ? SourceStream->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Prefix), (int32_t)Prefix.size(), Count, (int8_t)ReleaseSourceStream, &_Handle));
	return TElGooglePrefixedPostfixedUploadStream(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TELGOOGLEPREFIXEDPOSTFIXEDUPLOADSTREAM */

#ifdef SB_USE_CLASS_TELGOOGLEBASE64ENCODINGSTREAM

SB_INLINE int32_t TElGoogleBase64EncodingStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElGoogleBase64EncodingStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElGoogleBase64EncodingStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElGoogleBase64EncodingStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElGoogleBase64EncodingStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TElGoogleBase64EncodingStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElGoogleBase64EncodingStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElGoogleBase64EncodingStream_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

TElGoogleBase64EncodingStream::TElGoogleBase64EncodingStream(TElGoogleBase64EncodingStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
}

TElGoogleBase64EncodingStream::TElGoogleBase64EncodingStream(TStream &SourceStream, int64_t Count, int32_t LineLen, TSBEOLMarker EOL, bool ReleaseSourceStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGoogleBase64EncodingStream_Create(SourceStream.getHandle(), Count, LineLen, (TSBEOLMarkerRaw)EOL, (int8_t)ReleaseSourceStream, &_Handle));
}

TElGoogleBase64EncodingStream::TElGoogleBase64EncodingStream(TStream *SourceStream, int64_t Count, int32_t LineLen, TSBEOLMarker EOL, bool ReleaseSourceStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGoogleBase64EncodingStream_Create((SourceStream != NULL) ? SourceStream->getHandle() : SB_NULL_HANDLE, Count, LineLen, (TSBEOLMarkerRaw)EOL, (int8_t)ReleaseSourceStream, &_Handle));
}

#endif /* SB_USE_CLASS_TELGOOGLEBASE64ENCODINGSTREAM */

#ifdef SB_USE_CLASS_TELGOOGLEBASE64DECODINGSTREAM

SB_INLINE int32_t TElGoogleBase64DecodingStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElGoogleBase64DecodingStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElGoogleBase64DecodingStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElGoogleBase64DecodingStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElGoogleBase64DecodingStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TElGoogleBase64DecodingStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElGoogleBase64DecodingStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElGoogleBase64DecodingStream_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

TStream* TElGoogleBase64DecodingStream::get_DestStream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleBase64DecodingStream_get_DestStream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DestStream)
		this->_Inst_DestStream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_DestStream->updateHandle(hOutResult);
	return this->_Inst_DestStream;
}

void TElGoogleBase64DecodingStream::initInstances()
{
	this->_Inst_DestStream = NULL;
}

TElGoogleBase64DecodingStream::TElGoogleBase64DecodingStream(TElGoogleBase64DecodingStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
	initInstances();
}

TElGoogleBase64DecodingStream::TElGoogleBase64DecodingStream(TStream &DestStream, int64_t Count, bool ReleaseDestStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleBase64DecodingStream_Create(DestStream.getHandle(), Count, (int8_t)ReleaseDestStream, &_Handle));
}

TElGoogleBase64DecodingStream::TElGoogleBase64DecodingStream(TStream *DestStream, int64_t Count, bool ReleaseDestStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleBase64DecodingStream_Create((DestStream != NULL) ? DestStream->getHandle() : SB_NULL_HANDLE, Count, (int8_t)ReleaseDestStream, &_Handle));
}

TElGoogleBase64DecodingStream::~TElGoogleBase64DecodingStream()
{
	delete this->_Inst_DestStream;
	this->_Inst_DestStream = NULL;
}
#endif /* SB_USE_CLASS_TELGOOGLEBASE64DECODINGSTREAM */

#ifdef SB_USE_CLASS_TELGOOGLEPREFIXEDMETADATAPROCESSINGSTREAM

SB_INLINE int32_t TElGooglePrefixedMetadataProcessingStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElGooglePrefixedMetadataProcessingStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElGooglePrefixedMetadataProcessingStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElGooglePrefixedMetadataProcessingStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElGooglePrefixedMetadataProcessingStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TElGooglePrefixedMetadataProcessingStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElGooglePrefixedMetadataProcessingStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElGooglePrefixedMetadataProcessingStream_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

TStream* TElGooglePrefixedMetadataProcessingStream::get_DestStream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGooglePrefixedMetadataProcessingStream_get_DestStream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DestStream)
		this->_Inst_DestStream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_DestStream->updateHandle(hOutResult);
	return this->_Inst_DestStream;
}

void TElGooglePrefixedMetadataProcessingStream::get_Metadata(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGooglePrefixedMetadataProcessingStream_get_Metadata(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1393967539, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGooglePrefixedMetadataProcessingStream::initInstances()
{
	this->_Inst_DestStream = NULL;
}

TElGooglePrefixedMetadataProcessingStream::TElGooglePrefixedMetadataProcessingStream(TElGooglePrefixedMetadataProcessingStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
	initInstances();
}

TElGooglePrefixedMetadataProcessingStream::TElGooglePrefixedMetadataProcessingStream(TStream &DestStream, const std::vector<uint8_t> &MetadataID, TSBGooglePrefixedMetadataProcessingStreamMetadataFunc pMethodOnMetadata, void * pDataOnMetadata, TNotifyEvent pMethodOnNoMetadata, void * pDataOnNoMetadata, bool ReleaseDestStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGooglePrefixedMetadataProcessingStream_Create(DestStream.getHandle(), SB_STD_VECTOR_FRONT_ADR(MetadataID), (int32_t)MetadataID.size(), pMethodOnMetadata, pDataOnMetadata, pMethodOnNoMetadata, pDataOnNoMetadata, (int8_t)ReleaseDestStream, &_Handle));
}

TElGooglePrefixedMetadataProcessingStream::TElGooglePrefixedMetadataProcessingStream(TStream *DestStream, const std::vector<uint8_t> &MetadataID, TSBGooglePrefixedMetadataProcessingStreamMetadataFunc pMethodOnMetadata, void * pDataOnMetadata, TNotifyEvent pMethodOnNoMetadata, void * pDataOnNoMetadata, bool ReleaseDestStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGooglePrefixedMetadataProcessingStream_Create((DestStream != NULL) ? DestStream->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(MetadataID), (int32_t)MetadataID.size(), pMethodOnMetadata, pDataOnMetadata, pMethodOnNoMetadata, pDataOnNoMetadata, (int8_t)ReleaseDestStream, &_Handle));
}

TElGooglePrefixedMetadataProcessingStream::~TElGooglePrefixedMetadataProcessingStream()
{
	delete this->_Inst_DestStream;
	this->_Inst_DestStream = NULL;
}
#endif /* SB_USE_CLASS_TELGOOGLEPREFIXEDMETADATAPROCESSINGSTREAM */

};	/* namespace SecureBlackbox */
