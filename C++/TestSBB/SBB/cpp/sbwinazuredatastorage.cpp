#include "sbwinazuredatastorage.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGE

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::AcquireObject(const std::string &ContainerName, const std::string &ObjName)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_AcquireObject(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::AcquireObject(const std::string &ContainerName, const std::string &ObjName, TStringList &Headers)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_AcquireObject_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::AcquireObject(const std::string &ContainerName, const std::string &ObjName, TStringList *Headers)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_AcquireObject_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::AcquireObject(const std::string &ContainerName, const std::string &ObjName, TElStringList &Headers)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_AcquireObject_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::AcquireObject(const std::string &ContainerName, const std::string &ObjName, TElStringList *Headers)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_AcquireObject_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::AcquireObject(TElWinAzureDataStorageContainer &Container, const std::string &ObjName)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_AcquireObject_2(_Handle, Container.getHandle(), ObjName.data(), (int32_t)ObjName.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::AcquireObject(TElWinAzureDataStorageContainer *Container, const std::string &ObjName)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_AcquireObject_2(_Handle, (Container != NULL) ? Container->getHandle() : SB_NULL_HANDLE, ObjName.data(), (int32_t)ObjName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::AcquireObject(const std::string &ContainerName, const std::string &ObjName, const std::string &SharedAccessSignature)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_AcquireObject_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::AcquireObject(TElWinAzureDataStorageContainer &Container, const std::string &ObjName, const std::string &SharedAccessSignature)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_AcquireObject_4(_Handle, Container.getHandle(), ObjName.data(), (int32_t)ObjName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::AcquireObject(TElWinAzureDataStorageContainer *Container, const std::string &ObjName, const std::string &SharedAccessSignature)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_AcquireObject_4(_Handle, (Container != NULL) ? Container->getHandle() : SB_NULL_HANDLE, ObjName.data(), (int32_t)ObjName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::AcquireObject(const std::string &ContainerName, const std::string &ObjName, const std::string &SharedAccessSignature, TStringList &Headers)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_AcquireObject_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::AcquireObject(const std::string &ContainerName, const std::string &ObjName, const std::string &SharedAccessSignature, TStringList *Headers)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_AcquireObject_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::AcquireObject(const std::string &ContainerName, const std::string &ObjName, const std::string &SharedAccessSignature, TElStringList &Headers)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_AcquireObject_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::AcquireObject(const std::string &ContainerName, const std::string &ObjName, const std::string &SharedAccessSignature, TElStringList *Headers)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_AcquireObject_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElWinAzureDataStorage_List(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Objects.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElWinAzureDataStorage_List(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, TElDataStorageObjectList &Objects, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Objects.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, TElDataStorageObjectList *Objects, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, TElDataStorageObjectList &Objects, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Objects.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, TElDataStorageObjectList *Objects, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList &Prefixes, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Objects.getHandle(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, Prefixes.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList *Prefixes, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList &Prefixes, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Objects.getHandle(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, Prefixes.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList *Prefixes, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Objects.getHandle(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, Prefixes.getHandle(), (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Objects.getHandle(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, Prefixes.getHandle(), (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELWINAZUREDATASTORAGECONTAINER
SB_INLINE void TElWinAzureDataStorage::List(TElWinAzureDataStorageContainer &Container, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElWinAzureDataStorage_List_4(_Handle, Container.getHandle(), Objects.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::List(TElWinAzureDataStorageContainer *Container, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElWinAzureDataStorage_List_4(_Handle, (Container != NULL) ? Container->getHandle() : SB_NULL_HANDLE, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList &Objects, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Objects.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList *Objects, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList &Objects, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Objects.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList *Objects, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList &Prefixes, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_6(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Objects.getHandle(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, Prefixes.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList *Prefixes, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_6(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList &Prefixes, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_6(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Objects.getHandle(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, Prefixes.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList *Prefixes, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_6(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_7(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Objects.getHandle(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, Prefixes.getHandle(), (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_7(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_7(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Objects.getHandle(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, Prefixes.getHandle(), (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_List_7(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE
SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorage::ListInit(const std::string &ContainerName)
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_ListInit(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGELISTSTATE_AND_TSTRINGLIST
SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorage::ListInit(const std::string &ContainerName, const std::string &Prefix, const std::string &Delimiter, TStringList &Prefixes, TStringList &Headers)
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_ListInit_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), Prefixes.getHandle(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorage::ListInit(const std::string &ContainerName, const std::string &Prefix, const std::string &Delimiter, TStringList *Prefixes, TStringList *Headers)
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_ListInit_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGELISTSTATE_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGELISTSTATE
SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorage::ListInit(const std::string &ContainerName, const std::string &Prefix, const std::string &Delimiter, TElStringList &Prefixes, TElStringList &Headers)
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_ListInit_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), Prefixes.getHandle(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorage::ListInit(const std::string &ContainerName, const std::string &Prefix, const std::string &Delimiter, TElStringList *Prefixes, TElStringList *Headers)
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_ListInit_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGELISTSTATE */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGELISTSTATE_AND_TSTRINGLIST
SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorage::ListInit(const std::string &ContainerName, const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList &Headers)
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_ListInit_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), Prefixes.getHandle(), (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorage::ListInit(const std::string &ContainerName, const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList *Headers)
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_ListInit_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGELISTSTATE_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGELISTSTATE
SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorage::ListInit(const std::string &ContainerName, const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TElStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList &Headers)
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_ListInit_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), Prefixes.getHandle(), (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorage::ListInit(const std::string &ContainerName, const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TElStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList *Headers)
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_ListInit_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGELISTSTATE */
#endif

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELWINAZUREDATASTORAGELISTSTATE
SB_INLINE void TElWinAzureDataStorage::ListNext(TElWinAzureDataStorageListState &State, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElWinAzureDataStorage_ListNext(_Handle, State.getHandle(), Objects.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::ListNext(TElWinAzureDataStorageListState *State, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElWinAzureDataStorage_ListNext(_Handle, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELWINAZUREDATASTORAGELISTSTATE
SB_INLINE void TElWinAzureDataStorage::ListNext(TElWinAzureDataStorageListState &State, TElDataStorageObjectList &Objects, int32_t MaxCount)
{
	SBCheckError(TElWinAzureDataStorage_ListNext_1(_Handle, State.getHandle(), Objects.getHandle(), MaxCount));
}

SB_INLINE void TElWinAzureDataStorage::ListNext(TElWinAzureDataStorageListState *State, TElDataStorageObjectList *Objects, int32_t MaxCount)
{
	SBCheckError(TElWinAzureDataStorage_ListNext_1(_Handle, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, MaxCount));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE
void TElWinAzureDataStorage::ListFinal(TElWinAzureDataStorageListState &State)
{
	TElClassHandle hState = State.getHandle();
	SBCheckError(TElWinAzureDataStorage_ListFinal(_Handle, &hState));
	State.updateHandle(hState);
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(TElWinAzureDataStorageContainer &Container, const std::string &ObjName)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_1(_Handle, Container.getHandle(), ObjName.data(), (int32_t)ObjName.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(TElWinAzureDataStorageContainer *Container, const std::string &ObjName)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_1(_Handle, (Container != NULL) ? Container->getHandle() : SB_NULL_HANDLE, ObjName.data(), (int32_t)ObjName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, TElCustomDataStorageSecurityHandler &Handler)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, TElCustomDataStorageSecurityHandler *Handler)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(TElWinAzureDataStorageContainer &Container, const std::string &ObjName, TElCustomDataStorageSecurityHandler &Handler)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_3(_Handle, Container.getHandle(), ObjName.data(), (int32_t)ObjName.length(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(TElWinAzureDataStorageContainer *Container, const std::string &ObjName, TElCustomDataStorageSecurityHandler *Handler)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_3(_Handle, (Container != NULL) ? Container->getHandle() : SB_NULL_HANDLE, ObjName.data(), (int32_t)ObjName.length(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_4(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(TElWinAzureDataStorageContainer &Container, const std::string &ObjName, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_5(_Handle, Container.getHandle(), ObjName.data(), (int32_t)ObjName.length(), InitialSize, &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(TElWinAzureDataStorageContainer *Container, const std::string &ObjName, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_5(_Handle, (Container != NULL) ? Container->getHandle() : SB_NULL_HANDLE, ObjName.data(), (int32_t)ObjName.length(), InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_6(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), Handler.getHandle(), InitialSize, &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_6(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(TElWinAzureDataStorageContainer &Container, const std::string &ObjName, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_7(_Handle, Container.getHandle(), ObjName.data(), (int32_t)ObjName.length(), Handler.getHandle(), InitialSize, &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(TElWinAzureDataStorageContainer *Container, const std::string &ObjName, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_7(_Handle, (Container != NULL) ? Container->getHandle() : SB_NULL_HANDLE, ObjName.data(), (int32_t)ObjName.length(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_8(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle(), InitialSize, &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_8(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_8(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle(), InitialSize, &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_8(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, TStringList &Headers, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_9(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), Headers.getHandle(), InitialSize, &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, TStringList *Headers, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_9(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, TElStringList &Headers, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_9(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), Headers.getHandle(), InitialSize, &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, TElStringList *Headers, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_9(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &SharedAccessSignature)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_10(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler &Handler)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_11(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler *Handler)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_11(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, int64_t InitialSize, const std::string &SharedAccessSignature)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_12(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), InitialSize, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_13(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Handler.getHandle(), InitialSize, &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_13(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_13(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Handler.getHandle(), InitialSize, &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_13(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, TStringList &Headers, const std::string &SharedAccessSignature, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_14(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), Headers.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), InitialSize, &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, TStringList *Headers, const std::string &SharedAccessSignature, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_14(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, TElStringList &Headers, const std::string &SharedAccessSignature, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_14(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), Headers.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), InitialSize, &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorage::CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, TElStringList *Headers, const std::string &SharedAccessSignature, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateObject_14(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

SB_INLINE void TElWinAzureDataStorage::DeleteObject(const std::string &ContainerName, const std::string &Name)
{
	SBCheckError(TElWinAzureDataStorage_DeleteObject(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length()));
}

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
void TElWinAzureDataStorage::DeleteObject(TElWinAzureDataStorageObject &Obj)
{
	TElClassHandle hObj = Obj.getHandle();
	SBCheckError(TElWinAzureDataStorage_DeleteObject_1(_Handle, &hObj));
	Obj.updateHandle(hObj);
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::DeleteObject(const std::string &ContainerName, const std::string &Name, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_DeleteObject_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::DeleteObject(const std::string &ContainerName, const std::string &Name, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_DeleteObject_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::DeleteObject(const std::string &ContainerName, const std::string &Name, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_DeleteObject_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::DeleteObject(const std::string &ContainerName, const std::string &Name, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_DeleteObject_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

SB_INLINE void TElWinAzureDataStorage::DeleteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature)
{
	SBCheckError(TElWinAzureDataStorage_DeleteObject_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length()));
}

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
void TElWinAzureDataStorage::DeleteObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature)
{
	TElClassHandle hObj = Obj.getHandle();
	SBCheckError(TElWinAzureDataStorage_DeleteObject_4(_Handle, &hObj, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length()));
	Obj.updateHandle(hObj);
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::DeleteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_DeleteObject_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::DeleteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_DeleteObject_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::DeleteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_DeleteObject_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::DeleteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_DeleteObject_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

bool TElWinAzureDataStorage::ObjectExists(const std::string &ContainerName, const std::string &Name)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ObjectExists(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
bool TElWinAzureDataStorage::ObjectExists(TElWinAzureDataStorageObject &Obj)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ObjectExists_1(_Handle, Obj.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWinAzureDataStorage::ObjectExists(TElWinAzureDataStorageObject *Obj)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ObjectExists_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
bool TElWinAzureDataStorage::ObjectExists(const std::string &ContainerName, const std::string &Name, TStringList &Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ObjectExists_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Headers.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWinAzureDataStorage::ObjectExists(const std::string &ContainerName, const std::string &Name, TStringList *Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ObjectExists_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
bool TElWinAzureDataStorage::ObjectExists(const std::string &ContainerName, const std::string &Name, TElStringList &Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ObjectExists_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Headers.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWinAzureDataStorage::ObjectExists(const std::string &ContainerName, const std::string &Name, TElStringList *Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ObjectExists_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

bool TElWinAzureDataStorage::ObjectExists(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ObjectExists_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
bool TElWinAzureDataStorage::ObjectExists(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ObjectExists_4(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWinAzureDataStorage::ObjectExists(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ObjectExists_4(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
bool TElWinAzureDataStorage::ObjectExists(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStringList &Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ObjectExists_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Headers.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWinAzureDataStorage::ObjectExists(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStringList *Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ObjectExists_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
bool TElWinAzureDataStorage::ObjectExists(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TElStringList &Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ObjectExists_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Headers.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWinAzureDataStorage::ObjectExists(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TElStringList *Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ObjectExists_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE void TElWinAzureDataStorage::RefreshObject(TElWinAzureDataStorageObject &Obj)
{
	SBCheckError(TElWinAzureDataStorage_RefreshObject(_Handle, Obj.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::RefreshObject(TElWinAzureDataStorageObject *Obj)
{
	SBCheckError(TElWinAzureDataStorage_RefreshObject(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE void TElWinAzureDataStorage::RefreshObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature)
{
	SBCheckError(TElWinAzureDataStorage_RefreshObject_1(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length()));
}

SB_INLINE void TElWinAzureDataStorage::RefreshObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature)
{
	SBCheckError(TElWinAzureDataStorage_RefreshObject_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length()));
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::RefreshObject(TElWinAzureDataStorageObject &Obj, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_RefreshObject_2(_Handle, Obj.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::RefreshObject(TElWinAzureDataStorageObject *Obj, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_RefreshObject_2(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE void TElWinAzureDataStorage::RefreshObject(TElWinAzureDataStorageObject &Obj, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_RefreshObject_2(_Handle, Obj.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::RefreshObject(TElWinAzureDataStorageObject *Obj, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_RefreshObject_2(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::RefreshObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_RefreshObject_3(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::RefreshObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_RefreshObject_3(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE void TElWinAzureDataStorage::RefreshObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_RefreshObject_3(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::RefreshObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_RefreshObject_3(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Data.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, const std::string &LeaseID)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle(), LeaseID.data(), (int32_t)LeaseID.length()));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, const std::string &LeaseID)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, LeaseID.data(), (int32_t)LeaseID.length()));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, const std::string &LeaseID)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle(), LeaseID.data(), (int32_t)LeaseID.length()));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, const std::string &LeaseID)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, LeaseID.data(), (int32_t)LeaseID.length()));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_4(_Handle, Obj.getHandle(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_4(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_4(_Handle, Obj.getHandle(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_4(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_5(_Handle, Obj.getHandle(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_5(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_5(_Handle, Obj.getHandle(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_5(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_6(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Data.getHandle(), Handler.getHandle(), InitialSize));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_6(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_7(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle(), InitialSize));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_7(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_7(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle(), InitialSize));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_7(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, TStringList &Headers, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_8(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), Headers.getHandle(), InitialSize));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, TStringList *Headers, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_8(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, InitialSize));
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, TElStringList &Headers, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_8(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), Headers.getHandle(), InitialSize));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, TElStringList *Headers, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_8(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, InitialSize));
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_9(_Handle, Obj.getHandle(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle(), InitialSize));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_9(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_9(_Handle, Obj.getHandle(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle(), InitialSize));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_9(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, TStringList &Headers, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_10(_Handle, Obj.getHandle(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), Headers.getHandle(), InitialSize));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, TStringList *Headers, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_10(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, InitialSize));
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, TElStringList &Headers, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_10(_Handle, Obj.getHandle(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), Headers.getHandle(), InitialSize));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, TElStringList *Headers, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_10(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, InitialSize));
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_11(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_11(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_12(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_12(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_12(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_12(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_13(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_13(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_13(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_13(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_14(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_14(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_14(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_14(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_15(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_15(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_15(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_15(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_16(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), Handler.getHandle(), InitialSize));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_16(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_17(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle(), InitialSize));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_17(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_17(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle(), InitialSize));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_17(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, TStringList &Headers, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_18(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), Headers.getHandle(), InitialSize));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, TStringList *Headers, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_18(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, InitialSize));
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, TElStringList &Headers, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_18(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), Headers.getHandle(), InitialSize));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, TElStringList *Headers, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_18(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, InitialSize));
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_19(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle(), InitialSize));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_19(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_19(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle(), InitialSize));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_19(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, TStringList &Headers, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_20(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), Headers.getHandle(), InitialSize));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, TStringList *Headers, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_20(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, InitialSize));
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, TElStringList &Headers, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_20(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), Headers.getHandle(), InitialSize));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, TElStringList *Headers, int64_t InitialSize)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_20(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, InitialSize));
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize, const std::string &LeaseID)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_21(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle(), InitialSize, LeaseID.data(), (int32_t)LeaseID.length()));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize, const std::string &LeaseID)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_21(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize, LeaseID.data(), (int32_t)LeaseID.length()));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize, const std::string &LeaseID)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_21(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle(), InitialSize, LeaseID.data(), (int32_t)LeaseID.length()));
}

SB_INLINE void TElWinAzureDataStorage::WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize, const std::string &LeaseID)
{
	SBCheckError(TElWinAzureDataStorage_WriteObject_21(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize, LeaseID.data(), (int32_t)LeaseID.length()));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, TStream &Strm)
{
	SBCheckError(TElWinAzureDataStorage_ReadObject(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Strm.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, TStream *Strm)
{
	SBCheckError(TElWinAzureDataStorage_ReadObject(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorage_ReadObject_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}

SB_INLINE void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorage_ReadObject_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::ReadObject(TElWinAzureDataStorageObject &Obj, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorage_ReadObject_2(_Handle, Obj.getHandle(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}

SB_INLINE void TElWinAzureDataStorage::ReadObject(TElWinAzureDataStorageObject *Obj, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorage_ReadObject_2(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(2096733016, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(2096733016, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(2096733016, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(2096733016, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(2096733016, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(2096733016, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(2096733016, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(2096733016, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(850246078, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(850246078, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(850246078, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(850246078, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(850246078, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(850246078, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(850246078, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(850246078, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_4(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1206000800, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1206000800, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1206000800, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(1206000800, 13, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1206000800, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_4(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1206000800, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1206000800, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1206000800, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(1206000800, 13, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1206000800, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_4(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-798792180, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-798792180, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-798792180, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-798792180, 13, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-798792180, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_4(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-798792180, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-798792180, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-798792180, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-798792180, 13, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-798792180, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorage::ReadObject(TElWinAzureDataStorageObject &Obj, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_5(_Handle, Obj.getHandle(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1073216985, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1073216985, 10, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1073216985, 11, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1073216985, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadObject(TElWinAzureDataStorageObject *Obj, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_5(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1073216985, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1073216985, 10, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1073216985, 11, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1073216985, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
void TElWinAzureDataStorage::ReadObject(TElWinAzureDataStorageObject &Obj, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_5(_Handle, Obj.getHandle(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1011066192, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1011066192, 10, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1011066192, 11, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1011066192, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadObject(TElWinAzureDataStorageObject *Obj, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_5(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1011066192, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1011066192, 10, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1011066192, 11, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1011066192, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorage::ReadObject(TElWinAzureDataStorageObject &Obj, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_6(_Handle, Obj.getHandle(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(391253383, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(391253383, 10, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(391253383, 11, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(391253383, 12, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(391253383, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadObject(TElWinAzureDataStorageObject *Obj, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_6(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(391253383, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(391253383, 10, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(391253383, 11, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(391253383, 12, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(391253383, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
void TElWinAzureDataStorage::ReadObject(TElWinAzureDataStorageObject &Obj, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_6(_Handle, Obj.getHandle(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(2144126848, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(2144126848, 10, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(2144126848, 11, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(2144126848, 12, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(2144126848, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadObject(TElWinAzureDataStorageObject *Obj, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_6(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(2144126848, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(2144126848, 10, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(2144126848, 11, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(2144126848, 12, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(2144126848, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm)
{
	SBCheckError(TElWinAzureDataStorage_ReadObject_7(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm)
{
	SBCheckError(TElWinAzureDataStorage_ReadObject_7(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorage_ReadObject_8(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}

SB_INLINE void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorage_ReadObject_8(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::ReadObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorage_ReadObject_9(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}

SB_INLINE void TElWinAzureDataStorage::ReadObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorage_ReadObject_9(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_10(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1921897369, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1921897369, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1921897369, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1921897369, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_10(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1921897369, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1921897369, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1921897369, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1921897369, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_10(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(775847248, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(775847248, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(775847248, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(775847248, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_10(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(775847248, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(775847248, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(775847248, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(775847248, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_11(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(309143727, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(309143727, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(309143727, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(309143727, 14, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(309143727, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_11(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(309143727, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(309143727, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(309143727, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(309143727, 14, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(309143727, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_11(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(209197801, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(209197801, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(209197801, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(209197801, 14, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(209197801, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_11(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(209197801, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(209197801, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(209197801, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(209197801, 14, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(209197801, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorage::ReadObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_12(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(574472894, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(574472894, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(574472894, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(574472894, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_12(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(574472894, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(574472894, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(574472894, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(574472894, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
void TElWinAzureDataStorage::ReadObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_12(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-2121147172, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-2121147172, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-2121147172, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-2121147172, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_12(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-2121147172, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-2121147172, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-2121147172, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-2121147172, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorage::ReadObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_13(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1759800182, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1759800182, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1759800182, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(1759800182, 13, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1759800182, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_13(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1759800182, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1759800182, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1759800182, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(1759800182, 13, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1759800182, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
void TElWinAzureDataStorage::ReadObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_13(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(2137613379, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(2137613379, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(2137613379, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(2137613379, 13, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(2137613379, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadObject_13(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(2137613379, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(2137613379, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(2137613379, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(2137613379, 13, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(2137613379, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElWinAzureDataStorage_ReadBlock(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Strm.getHandle(), Offset, Size, &Read));
}

SB_INLINE void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElWinAzureDataStorage_ReadBlock(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorage_ReadBlock_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}

SB_INLINE void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorage_ReadBlock_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::ReadBlock(TElWinAzureDataStorageObject &Obj, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorage_ReadBlock_2(_Handle, Obj.getHandle(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}

SB_INLINE void TElWinAzureDataStorage::ReadBlock(TElWinAzureDataStorageObject *Obj, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorage_ReadBlock_2(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(190400745, 13, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(190400745, 14, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(190400745, 15, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(190400745, 16, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(190400745, 13, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(190400745, 14, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(190400745, 15, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(190400745, 16, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(2026521438, 13, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(2026521438, 14, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(2026521438, 15, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(2026521438, 16, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(2026521438, 13, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(2026521438, 14, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(2026521438, 15, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(2026521438, 16, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_4(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(804295628, 13, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(804295628, 14, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(804295628, 15, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(804295628, 16, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(804295628, 17, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_4(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(804295628, 13, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(804295628, 14, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(804295628, 15, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(804295628, 16, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(804295628, 17, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_4(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1885858739, 13, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1885858739, 14, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1885858739, 15, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(1885858739, 16, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1885858739, 17, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_4(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1885858739, 13, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1885858739, 14, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1885858739, 15, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(1885858739, 16, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1885858739, 17, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorage::ReadBlock(TElWinAzureDataStorageObject &Obj, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_5(_Handle, Obj.getHandle(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1366881981, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1366881981, 13, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1366881981, 14, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1366881981, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadBlock(TElWinAzureDataStorageObject *Obj, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_5(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1366881981, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1366881981, 13, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1366881981, 14, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1366881981, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
void TElWinAzureDataStorage::ReadBlock(TElWinAzureDataStorageObject &Obj, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_5(_Handle, Obj.getHandle(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1841044930, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1841044930, 13, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1841044930, 14, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1841044930, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadBlock(TElWinAzureDataStorageObject *Obj, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_5(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1841044930, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1841044930, 13, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1841044930, 14, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1841044930, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorage::ReadBlock(TElWinAzureDataStorageObject &Obj, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_6(_Handle, Obj.getHandle(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1932685021, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1932685021, 13, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1932685021, 14, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(1932685021, 15, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1932685021, 16, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadBlock(TElWinAzureDataStorageObject *Obj, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_6(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1932685021, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1932685021, 13, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1932685021, 14, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(1932685021, 15, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1932685021, 16, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
void TElWinAzureDataStorage::ReadBlock(TElWinAzureDataStorageObject &Obj, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_6(_Handle, Obj.getHandle(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1093692455, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1093692455, 13, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1093692455, 14, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-1093692455, 15, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1093692455, 16, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadBlock(TElWinAzureDataStorageObject *Obj, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_6(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1093692455, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1093692455, 13, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1093692455, 14, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-1093692455, 15, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1093692455, 16, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElWinAzureDataStorage_ReadBlock_7(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), Offset, Size, &Read));
}

SB_INLINE void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElWinAzureDataStorage_ReadBlock_7(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorage_ReadBlock_8(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}

SB_INLINE void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorage_ReadBlock_8(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorage::ReadBlock(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorage_ReadBlock_9(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}

SB_INLINE void TElWinAzureDataStorage::ReadBlock(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorage_ReadBlock_9(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_10(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(838250439, 14, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(838250439, 15, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(838250439, 16, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(838250439, 17, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_10(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(838250439, 14, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(838250439, 15, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(838250439, 16, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(838250439, 17, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_10(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(2065245410, 14, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(2065245410, 15, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(2065245410, 16, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(2065245410, 17, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_10(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(2065245410, 14, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(2065245410, 15, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(2065245410, 16, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(2065245410, 17, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_11(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(20194205, 14, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(20194205, 15, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(20194205, 16, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(20194205, 17, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(20194205, 18, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_11(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(20194205, 14, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(20194205, 15, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(20194205, 16, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(20194205, 17, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(20194205, 18, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_11(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1245158687, 14, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1245158687, 15, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1245158687, 16, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-1245158687, 17, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1245158687, 18, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_11(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1245158687, 14, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1245158687, 15, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1245158687, 16, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-1245158687, 17, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1245158687, 18, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorage::ReadBlock(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_12(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1832145622, 13, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1832145622, 14, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1832145622, 15, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1832145622, 16, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadBlock(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_12(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1832145622, 13, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1832145622, 14, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1832145622, 15, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1832145622, 16, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
void TElWinAzureDataStorage::ReadBlock(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_12(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1246667640, 13, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1246667640, 14, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1246667640, 15, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1246667640, 16, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadBlock(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_12(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1246667640, 13, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1246667640, 14, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1246667640, 15, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1246667640, 16, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorage::ReadBlock(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_13(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(524743416, 13, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(524743416, 14, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(524743416, 15, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(524743416, 16, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(524743416, 17, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadBlock(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_13(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(524743416, 13, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(524743416, 14, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(524743416, 15, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(524743416, 16, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(524743416, 17, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
void TElWinAzureDataStorage::ReadBlock(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_13(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-763552576, 13, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-763552576, 14, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-763552576, 15, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-763552576, 16, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-763552576, 17, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorage::ReadBlock(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorage_ReadBlock_13(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-763552576, 13, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-763552576, 14, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-763552576, 15, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-763552576, 16, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-763552576, 17, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TElCustomDataStorageSecurityHandler &NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), NewHandler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TElCustomDataStorageSecurityHandler *NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (NewHandler != NULL) ? NewHandler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(TElWinAzureDataStorageObject &Obj, const std::string &DestContainerName, const std::string &DestName, TElCustomDataStorageSecurityHandler &NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_1(_Handle, Obj.getHandle(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), NewHandler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(TElWinAzureDataStorageObject *Obj, const std::string &DestContainerName, const std::string &DestName, TElCustomDataStorageSecurityHandler *NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (NewHandler != NULL) ? NewHandler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_2(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_2(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TElStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_2(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TElStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_2(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList &Metadata, TStringList &Headers)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_3(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList *Metadata, TStringList *Headers)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_3(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList &Metadata, TElStringList &Headers)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_3(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList *Metadata, TElStringList *Headers)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_3(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList &Metadata, TStringList &Headers, const std::string &LeaseID, bool Wait)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_4(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), Headers.getHandle(), LeaseID.data(), (int32_t)LeaseID.length(), (int8_t)Wait, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList *Metadata, TStringList *Headers, const std::string &LeaseID, bool Wait)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_4(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, LeaseID.data(), (int32_t)LeaseID.length(), (int8_t)Wait, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList &Metadata, TElStringList &Headers, const std::string &LeaseID, bool Wait)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_4(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), Headers.getHandle(), LeaseID.data(), (int32_t)LeaseID.length(), (int8_t)Wait, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList *Metadata, TElStringList *Headers, const std::string &LeaseID, bool Wait)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_4(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, LeaseID.data(), (int32_t)LeaseID.length(), (int8_t)Wait, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TElCustomDataStorageSecurityHandler &NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_5(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), NewHandler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TElCustomDataStorageSecurityHandler *NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_5(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (NewHandler != NULL) ? NewHandler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TElCustomDataStorageSecurityHandler &NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_6(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), NewHandler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TElCustomDataStorageSecurityHandler *NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_6(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (NewHandler != NULL) ? NewHandler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_7(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_7(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TElStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_7(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TElStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_7(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList &Metadata, TStringList &Headers)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_8(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList *Metadata, TStringList *Headers)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_8(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList &Metadata, TElStringList &Headers)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_8(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList *Metadata, TElStringList *Headers)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_8(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList &Metadata, TStringList &Headers, const std::string &LeaseID, bool Wait)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_9(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), Headers.getHandle(), LeaseID.data(), (int32_t)LeaseID.length(), (int8_t)Wait, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList *Metadata, TStringList *Headers, const std::string &LeaseID, bool Wait)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_9(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, LeaseID.data(), (int32_t)LeaseID.length(), (int8_t)Wait, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList &Metadata, TElStringList &Headers, const std::string &LeaseID, bool Wait)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_9(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), Headers.getHandle(), LeaseID.data(), (int32_t)LeaseID.length(), (int8_t)Wait, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorage::CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList *Metadata, TElStringList *Headers, const std::string &LeaseID, bool Wait)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CopyObject_9(_Handle, SourceContainerName.data(), (int32_t)SourceContainerName.length(), SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, LeaseID.data(), (int32_t)LeaseID.length(), (int8_t)Wait, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

void TElWinAzureDataStorage::GetObjectACL(const std::string &ContainerName, const std::string &Name, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_GetObjectACL(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2101636731, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
void TElWinAzureDataStorage::GetObjectACL(TElWinAzureDataStorageObject &Obj, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_GetObjectACL_1(_Handle, Obj.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1274908090, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWinAzureDataStorage::GetObjectACL(TElWinAzureDataStorageObject *Obj, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_GetObjectACL_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1274908090, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
void TElWinAzureDataStorage::GetObjectACL(const std::string &ContainerName, const std::string &Name, TStringList &Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_GetObjectACL_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Headers.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1540563279, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWinAzureDataStorage::GetObjectACL(const std::string &ContainerName, const std::string &Name, TStringList *Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_GetObjectACL_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1540563279, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
void TElWinAzureDataStorage::GetObjectACL(const std::string &ContainerName, const std::string &Name, TElStringList &Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_GetObjectACL_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Headers.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(651981591, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWinAzureDataStorage::GetObjectACL(const std::string &ContainerName, const std::string &Name, TElStringList *Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_GetObjectACL_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(651981591, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

SB_INLINE void TElWinAzureDataStorage::SetObjectACL(const std::string &ContainerName, const std::string &Name, const std::string &ACL)
{
	SBCheckError(TElWinAzureDataStorage_SetObjectACL(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), ACL.data(), (int32_t)ACL.length()));
}

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE void TElWinAzureDataStorage::SetObjectACL(TElWinAzureDataStorageObject &Obj, const std::string &ACL)
{
	SBCheckError(TElWinAzureDataStorage_SetObjectACL_1(_Handle, Obj.getHandle(), ACL.data(), (int32_t)ACL.length()));
}

SB_INLINE void TElWinAzureDataStorage::SetObjectACL(TElWinAzureDataStorageObject *Obj, const std::string &ACL)
{
	SBCheckError(TElWinAzureDataStorage_SetObjectACL_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, ACL.data(), (int32_t)ACL.length()));
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::SetObjectACL(const std::string &ContainerName, const std::string &Name, const std::string &ACL, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_SetObjectACL_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), ACL.data(), (int32_t)ACL.length(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::SetObjectACL(const std::string &ContainerName, const std::string &Name, const std::string &ACL, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_SetObjectACL_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), ACL.data(), (int32_t)ACL.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::SetObjectACL(const std::string &ContainerName, const std::string &Name, const std::string &ACL, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_SetObjectACL_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), ACL.data(), (int32_t)ACL.length(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::SetObjectACL(const std::string &ContainerName, const std::string &Name, const std::string &ACL, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_SetObjectACL_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), ACL.data(), (int32_t)ACL.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TSTREAM
void TElWinAzureDataStorage::GetLocalETag(TStream &Stream, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_GetLocalETag(_Handle, Stream.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1585892654, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWinAzureDataStorage::GetLocalETag(TStream *Stream, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_GetLocalETag(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1585892654, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElWinAzureDataStorage::GetLocalETag(const std::string &Filename, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_GetLocalETag_1(_Handle, Filename.data(), (int32_t)Filename.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1483668118, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWinAzureDataStorage::GetRemoteETag(const std::string &ContainerName, const std::string &Name, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_GetRemoteETag(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-29835246, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
void TElWinAzureDataStorage::GetRemoteETag(TElWinAzureDataStorageObject &Obj, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_GetRemoteETag_1(_Handle, Obj.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1257512949, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWinAzureDataStorage::GetRemoteETag(TElWinAzureDataStorageObject *Obj, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_GetRemoteETag_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1257512949, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
void TElWinAzureDataStorage::GetRemoteETag(const std::string &ContainerName, const std::string &Name, TStringList &Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_GetRemoteETag_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Headers.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-24199420, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWinAzureDataStorage::GetRemoteETag(const std::string &ContainerName, const std::string &Name, TStringList *Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_GetRemoteETag_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-24199420, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
void TElWinAzureDataStorage::GetRemoteETag(const std::string &ContainerName, const std::string &Name, TElStringList &Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_GetRemoteETag_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Headers.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(585563847, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWinAzureDataStorage::GetRemoteETag(const std::string &ContainerName, const std::string &Name, TElStringList *Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_GetRemoteETag_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(585563847, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

SB_INLINE int64_t TElWinAzureDataStorage::GetObjectAllocatedSize(const std::string &ContainerName, const std::string &Name)
{
	int64_t OutResult;
	SBCheckError(TElWinAzureDataStorage_GetObjectAllocatedSize(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}

SB_INLINE void TElWinAzureDataStorage::SetObjectAllocatedSize(const std::string &ContainerName, const std::string &Name, int64_t Value)
{
	SBCheckError(TElWinAzureDataStorage_SetObjectAllocatedSize(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Value));
}

void TElWinAzureDataStorage::LockObject(const std::string &ContainerName, const std::string &Name, int32_t Seconds, const std::string &SharedAccessSignature, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_LockObject(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Seconds, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(339427358, 5, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWinAzureDataStorage::RenewObjectLock(const std::string &ContainerName, const std::string &Name, int32_t Seconds, const std::string &SharedAccessSignature, const std::string &LeaseID)
{
	SBCheckError(TElWinAzureDataStorage_RenewObjectLock(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), Seconds, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), LeaseID.data(), (int32_t)LeaseID.length()));
}

SB_INLINE void TElWinAzureDataStorage::UnlockObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, const std::string &LeaseID)
{
	SBCheckError(TElWinAzureDataStorage_UnlockObject(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), LeaseID.data(), (int32_t)LeaseID.length()));
}

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
SB_INLINE TElWinAzureDataStorageContainerHandle TElWinAzureDataStorage::AcquireContainer(const std::string &ContainerName)
{
	TElWinAzureDataStorageContainerHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_AcquireContainer(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
SB_INLINE TElWinAzureDataStorageContainerHandle TElWinAzureDataStorage::AcquireContainer(const std::string &ContainerName, const std::string &SharedAccessSignature)
{
	TElWinAzureDataStorageContainerHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_AcquireContainer_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
void TElWinAzureDataStorage::ReleaseContainer(TElWinAzureDataStorageContainer &Container)
{
	TElClassHandle hContainer = Container.getHandle();
	SBCheckError(TElWinAzureDataStorage_ReleaseContainer(_Handle, &hContainer));
	Container.updateHandle(hContainer);
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
SB_INLINE TElWinAzureDataStorageContainerHandle TElWinAzureDataStorage::CreateContainer(const std::string &ContainerName)
{
	TElWinAzureDataStorageContainerHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateContainer(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TSTRINGLIST
SB_INLINE TElWinAzureDataStorageContainerHandle TElWinAzureDataStorage::CreateContainer(const std::string &ContainerName, TStringList &Headers)
{
	TElWinAzureDataStorageContainerHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateContainer_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageContainerHandle TElWinAzureDataStorage::CreateContainer(const std::string &ContainerName, TStringList *Headers)
{
	TElWinAzureDataStorageContainerHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateContainer_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGECONTAINER
SB_INLINE TElWinAzureDataStorageContainerHandle TElWinAzureDataStorage::CreateContainer(const std::string &ContainerName, TElStringList &Headers)
{
	TElWinAzureDataStorageContainerHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateContainer_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageContainerHandle TElWinAzureDataStorage::CreateContainer(const std::string &ContainerName, TElStringList *Headers)
{
	TElWinAzureDataStorageContainerHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateContainer_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGECONTAINER */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
SB_INLINE TElWinAzureDataStorageContainerHandle TElWinAzureDataStorage::CreateContainer(const std::string &ContainerName, const std::string &SharedAccessSignature)
{
	TElWinAzureDataStorageContainerHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateContainer_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TSTRINGLIST
SB_INLINE TElWinAzureDataStorageContainerHandle TElWinAzureDataStorage::CreateContainer(const std::string &ContainerName, const std::string &SharedAccessSignature, TStringList &Headers)
{
	TElWinAzureDataStorageContainerHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateContainer_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageContainerHandle TElWinAzureDataStorage::CreateContainer(const std::string &ContainerName, const std::string &SharedAccessSignature, TStringList *Headers)
{
	TElWinAzureDataStorageContainerHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateContainer_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGECONTAINER
SB_INLINE TElWinAzureDataStorageContainerHandle TElWinAzureDataStorage::CreateContainer(const std::string &ContainerName, const std::string &SharedAccessSignature, TElStringList &Headers)
{
	TElWinAzureDataStorageContainerHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateContainer_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageContainerHandle TElWinAzureDataStorage::CreateContainer(const std::string &ContainerName, const std::string &SharedAccessSignature, TElStringList *Headers)
{
	TElWinAzureDataStorageContainerHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_CreateContainer_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGECONTAINER */
#endif

SB_INLINE void TElWinAzureDataStorage::DeleteContainer(const std::string &ContainerName)
{
	SBCheckError(TElWinAzureDataStorage_DeleteContainer(_Handle, ContainerName.data(), (int32_t)ContainerName.length()));
}

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
void TElWinAzureDataStorage::DeleteContainer(TElWinAzureDataStorageContainer &Container)
{
	TElClassHandle hContainer = Container.getHandle();
	SBCheckError(TElWinAzureDataStorage_DeleteContainer_1(_Handle, &hContainer));
	Container.updateHandle(hContainer);
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::DeleteContainer(const std::string &ContainerName, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_DeleteContainer_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::DeleteContainer(const std::string &ContainerName, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_DeleteContainer_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::DeleteContainer(const std::string &ContainerName, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_DeleteContainer_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::DeleteContainer(const std::string &ContainerName, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_DeleteContainer_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

SB_INLINE void TElWinAzureDataStorage::DeleteContainer(const std::string &ContainerName, const std::string &SharedAccessSignature)
{
	SBCheckError(TElWinAzureDataStorage_DeleteContainer_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length()));
}

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
void TElWinAzureDataStorage::DeleteContainer(TElWinAzureDataStorageContainer &Container, const std::string &SharedAccessSignature)
{
	TElClassHandle hContainer = Container.getHandle();
	SBCheckError(TElWinAzureDataStorage_DeleteContainer_4(_Handle, &hContainer, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length()));
	Container.updateHandle(hContainer);
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::DeleteContainer(const std::string &ContainerName, const std::string &SharedAccessSignature, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_DeleteContainer_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::DeleteContainer(const std::string &ContainerName, const std::string &SharedAccessSignature, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_DeleteContainer_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::DeleteContainer(const std::string &ContainerName, const std::string &SharedAccessSignature, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_DeleteContainer_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::DeleteContainer(const std::string &ContainerName, const std::string &SharedAccessSignature, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_DeleteContainer_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

bool TElWinAzureDataStorage::ContainerExists(const std::string &ContainerName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ContainerExists(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
bool TElWinAzureDataStorage::ContainerExists(TElWinAzureDataStorageContainer &Obj)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ContainerExists_1(_Handle, Obj.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWinAzureDataStorage::ContainerExists(TElWinAzureDataStorageContainer *Obj)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ContainerExists_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
bool TElWinAzureDataStorage::ContainerExists(const std::string &ContainerName, TStringList &Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ContainerExists_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Headers.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWinAzureDataStorage::ContainerExists(const std::string &ContainerName, TStringList *Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ContainerExists_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
bool TElWinAzureDataStorage::ContainerExists(const std::string &ContainerName, TElStringList &Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ContainerExists_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Headers.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWinAzureDataStorage::ContainerExists(const std::string &ContainerName, TElStringList *Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ContainerExists_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

bool TElWinAzureDataStorage::ContainerExists(const std::string &ContainerName, const std::string &SharedAccessSignature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ContainerExists_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
bool TElWinAzureDataStorage::ContainerExists(TElWinAzureDataStorageContainer &Obj, const std::string &SharedAccessSignature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ContainerExists_4(_Handle, Obj.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWinAzureDataStorage::ContainerExists(TElWinAzureDataStorageContainer *Obj, const std::string &SharedAccessSignature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ContainerExists_4(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
bool TElWinAzureDataStorage::ContainerExists(const std::string &ContainerName, const std::string &SharedAccessSignature, TStringList &Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ContainerExists_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Headers.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWinAzureDataStorage::ContainerExists(const std::string &ContainerName, const std::string &SharedAccessSignature, TStringList *Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ContainerExists_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
bool TElWinAzureDataStorage::ContainerExists(const std::string &ContainerName, const std::string &SharedAccessSignature, TElStringList &Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ContainerExists_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Headers.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWinAzureDataStorage::ContainerExists(const std::string &ContainerName, const std::string &SharedAccessSignature, TElStringList *Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_ContainerExists_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREACCESSPOLICY
TSBWinAzureContainerAccessLevel TElWinAzureDataStorage::GetContainerACL(const std::string &ContainerName, TElWinAzureAccessPolicy &Policy)
{
	TSBWinAzureContainerAccessLevelRaw OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_GetContainerACL(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Policy.getHandle(), &OutResultRaw));
	return (TSBWinAzureContainerAccessLevel)OutResultRaw;
}

TSBWinAzureContainerAccessLevel TElWinAzureDataStorage::GetContainerACL(const std::string &ContainerName, TElWinAzureAccessPolicy *Policy)
{
	TSBWinAzureContainerAccessLevelRaw OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_GetContainerACL(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBWinAzureContainerAccessLevel)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELWINAZUREACCESSPOLICY */

#ifdef SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TELWINAZUREDATASTORAGECONTAINER
TSBWinAzureContainerAccessLevel TElWinAzureDataStorage::GetContainerACL(TElWinAzureDataStorageContainer &Container, TElWinAzureAccessPolicy &Policy)
{
	TSBWinAzureContainerAccessLevelRaw OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_GetContainerACL_1(_Handle, Container.getHandle(), Policy.getHandle(), &OutResultRaw));
	return (TSBWinAzureContainerAccessLevel)OutResultRaw;
}

TSBWinAzureContainerAccessLevel TElWinAzureDataStorage::GetContainerACL(TElWinAzureDataStorageContainer *Container, TElWinAzureAccessPolicy *Policy)
{
	TSBWinAzureContainerAccessLevelRaw OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_GetContainerACL_1(_Handle, (Container != NULL) ? Container->getHandle() : SB_NULL_HANDLE, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBWinAzureContainerAccessLevel)OutResultRaw;
}
#endif /* SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TSTRINGLIST
TSBWinAzureContainerAccessLevel TElWinAzureDataStorage::GetContainerACL(const std::string &ContainerName, TElWinAzureAccessPolicy &Policy, TStringList &Headers)
{
	TSBWinAzureContainerAccessLevelRaw OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_GetContainerACL_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Policy.getHandle(), Headers.getHandle(), &OutResultRaw));
	return (TSBWinAzureContainerAccessLevel)OutResultRaw;
}

TSBWinAzureContainerAccessLevel TElWinAzureDataStorage::GetContainerACL(const std::string &ContainerName, TElWinAzureAccessPolicy *Policy, TStringList *Headers)
{
	TSBWinAzureContainerAccessLevelRaw OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_GetContainerACL_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBWinAzureContainerAccessLevel)OutResultRaw;
}
#endif /* SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREACCESSPOLICY
TSBWinAzureContainerAccessLevel TElWinAzureDataStorage::GetContainerACL(const std::string &ContainerName, TElWinAzureAccessPolicy &Policy, TElStringList &Headers)
{
	TSBWinAzureContainerAccessLevelRaw OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_GetContainerACL_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Policy.getHandle(), Headers.getHandle(), &OutResultRaw));
	return (TSBWinAzureContainerAccessLevel)OutResultRaw;
}

TSBWinAzureContainerAccessLevel TElWinAzureDataStorage::GetContainerACL(const std::string &ContainerName, TElWinAzureAccessPolicy *Policy, TElStringList *Headers)
{
	TSBWinAzureContainerAccessLevelRaw OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_GetContainerACL_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBWinAzureContainerAccessLevel)OutResultRaw;
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREACCESSPOLICY */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREACCESSPOLICY
TSBWinAzureContainerAccessLevel TElWinAzureDataStorage::GetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TElWinAzureAccessPolicy &Policy)
{
	TSBWinAzureContainerAccessLevelRaw OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_GetContainerACL_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Policy.getHandle(), &OutResultRaw));
	return (TSBWinAzureContainerAccessLevel)OutResultRaw;
}

TSBWinAzureContainerAccessLevel TElWinAzureDataStorage::GetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TElWinAzureAccessPolicy *Policy)
{
	TSBWinAzureContainerAccessLevelRaw OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_GetContainerACL_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBWinAzureContainerAccessLevel)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELWINAZUREACCESSPOLICY */

#ifdef SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TELWINAZUREDATASTORAGECONTAINER
TSBWinAzureContainerAccessLevel TElWinAzureDataStorage::GetContainerACL(TElWinAzureDataStorageContainer &Container, const std::string &SharedAccessSignature, TElWinAzureAccessPolicy &Policy)
{
	TSBWinAzureContainerAccessLevelRaw OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_GetContainerACL_4(_Handle, Container.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Policy.getHandle(), &OutResultRaw));
	return (TSBWinAzureContainerAccessLevel)OutResultRaw;
}

TSBWinAzureContainerAccessLevel TElWinAzureDataStorage::GetContainerACL(TElWinAzureDataStorageContainer *Container, const std::string &SharedAccessSignature, TElWinAzureAccessPolicy *Policy)
{
	TSBWinAzureContainerAccessLevelRaw OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_GetContainerACL_4(_Handle, (Container != NULL) ? Container->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBWinAzureContainerAccessLevel)OutResultRaw;
}
#endif /* SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TSTRINGLIST
TSBWinAzureContainerAccessLevel TElWinAzureDataStorage::GetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TElWinAzureAccessPolicy &Policy, TStringList &Headers)
{
	TSBWinAzureContainerAccessLevelRaw OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_GetContainerACL_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Policy.getHandle(), Headers.getHandle(), &OutResultRaw));
	return (TSBWinAzureContainerAccessLevel)OutResultRaw;
}

TSBWinAzureContainerAccessLevel TElWinAzureDataStorage::GetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TElWinAzureAccessPolicy *Policy, TStringList *Headers)
{
	TSBWinAzureContainerAccessLevelRaw OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_GetContainerACL_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBWinAzureContainerAccessLevel)OutResultRaw;
}
#endif /* SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREACCESSPOLICY
TSBWinAzureContainerAccessLevel TElWinAzureDataStorage::GetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TElWinAzureAccessPolicy &Policy, TElStringList &Headers)
{
	TSBWinAzureContainerAccessLevelRaw OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_GetContainerACL_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Policy.getHandle(), Headers.getHandle(), &OutResultRaw));
	return (TSBWinAzureContainerAccessLevel)OutResultRaw;
}

TSBWinAzureContainerAccessLevel TElWinAzureDataStorage::GetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TElWinAzureAccessPolicy *Policy, TElStringList *Headers)
{
	TSBWinAzureContainerAccessLevelRaw OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_GetContainerACL_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBWinAzureContainerAccessLevel)OutResultRaw;
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREACCESSPOLICY */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREACCESSPOLICY
SB_INLINE void TElWinAzureDataStorage::SetContainerACL(const std::string &ContainerName, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy &Policy)
{
	SBCheckError(TElWinAzureDataStorage_SetContainerACL(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), (TSBWinAzureContainerAccessLevelRaw)AccessLevel, Policy.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::SetContainerACL(const std::string &ContainerName, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy *Policy)
{
	SBCheckError(TElWinAzureDataStorage_SetContainerACL(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), (TSBWinAzureContainerAccessLevelRaw)AccessLevel, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWINAZUREACCESSPOLICY */

#ifdef SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TELWINAZUREDATASTORAGECONTAINER
SB_INLINE void TElWinAzureDataStorage::SetContainerACL(TElWinAzureDataStorageContainer &Container, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy &Policy)
{
	SBCheckError(TElWinAzureDataStorage_SetContainerACL_1(_Handle, Container.getHandle(), (TSBWinAzureContainerAccessLevelRaw)AccessLevel, Policy.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::SetContainerACL(TElWinAzureDataStorageContainer *Container, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy *Policy)
{
	SBCheckError(TElWinAzureDataStorage_SetContainerACL_1(_Handle, (Container != NULL) ? Container->getHandle() : SB_NULL_HANDLE, (TSBWinAzureContainerAccessLevelRaw)AccessLevel, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::SetContainerACL(const std::string &ContainerName, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy &Policy, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_SetContainerACL_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), (TSBWinAzureContainerAccessLevelRaw)AccessLevel, Policy.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::SetContainerACL(const std::string &ContainerName, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy *Policy, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_SetContainerACL_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), (TSBWinAzureContainerAccessLevelRaw)AccessLevel, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREACCESSPOLICY
SB_INLINE void TElWinAzureDataStorage::SetContainerACL(const std::string &ContainerName, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy &Policy, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_SetContainerACL_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), (TSBWinAzureContainerAccessLevelRaw)AccessLevel, Policy.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::SetContainerACL(const std::string &ContainerName, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy *Policy, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_SetContainerACL_2(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), (TSBWinAzureContainerAccessLevelRaw)AccessLevel, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREACCESSPOLICY */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREACCESSPOLICY
SB_INLINE void TElWinAzureDataStorage::SetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy &Policy)
{
	SBCheckError(TElWinAzureDataStorage_SetContainerACL_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (TSBWinAzureContainerAccessLevelRaw)AccessLevel, Policy.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::SetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy *Policy)
{
	SBCheckError(TElWinAzureDataStorage_SetContainerACL_3(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (TSBWinAzureContainerAccessLevelRaw)AccessLevel, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWINAZUREACCESSPOLICY */

#ifdef SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TELWINAZUREDATASTORAGECONTAINER
SB_INLINE void TElWinAzureDataStorage::SetContainerACL(TElWinAzureDataStorageContainer &Container, const std::string &SharedAccessSignature, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy &Policy)
{
	SBCheckError(TElWinAzureDataStorage_SetContainerACL_4(_Handle, Container.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (TSBWinAzureContainerAccessLevelRaw)AccessLevel, Policy.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::SetContainerACL(TElWinAzureDataStorageContainer *Container, const std::string &SharedAccessSignature, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy *Policy)
{
	SBCheckError(TElWinAzureDataStorage_SetContainerACL_4(_Handle, (Container != NULL) ? Container->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (TSBWinAzureContainerAccessLevelRaw)AccessLevel, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::SetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy &Policy, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_SetContainerACL_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (TSBWinAzureContainerAccessLevelRaw)AccessLevel, Policy.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::SetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy *Policy, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_SetContainerACL_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (TSBWinAzureContainerAccessLevelRaw)AccessLevel, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREACCESSPOLICY
SB_INLINE void TElWinAzureDataStorage::SetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy &Policy, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_SetContainerACL_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (TSBWinAzureContainerAccessLevelRaw)AccessLevel, Policy.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::SetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy *Policy, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_SetContainerACL_5(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (TSBWinAzureContainerAccessLevelRaw)AccessLevel, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREACCESSPOLICY */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::ListContainers(TStringList &Containers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers(_Handle, Containers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::ListContainers(TStringList *Containers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers(_Handle, (Containers != NULL) ? Containers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::ListContainers(TElStringList &Containers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers(_Handle, Containers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::ListContainers(TElStringList *Containers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers(_Handle, (Containers != NULL) ? Containers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::ListContainers(TStringList &Containers, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_1(_Handle, Containers.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::ListContainers(TStringList *Containers, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_1(_Handle, (Containers != NULL) ? Containers->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::ListContainers(TElStringList &Containers, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_1(_Handle, Containers.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::ListContainers(TElStringList *Containers, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_1(_Handle, (Containers != NULL) ? Containers->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINERLIST
SB_INLINE void TElWinAzureDataStorage::ListContainers(TElWinAzureDataStorageContainerList &Containers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_2(_Handle, Containers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::ListContainers(TElWinAzureDataStorageContainerList *Containers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_2(_Handle, (Containers != NULL) ? Containers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINERLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINERLIST_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::ListContainers(TElWinAzureDataStorageContainerList &Containers, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_3(_Handle, Containers.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::ListContainers(TElWinAzureDataStorageContainerList *Containers, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_3(_Handle, (Containers != NULL) ? Containers->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINERLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGECONTAINERLIST
SB_INLINE void TElWinAzureDataStorage::ListContainers(TElWinAzureDataStorageContainerList &Containers, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_3(_Handle, Containers.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::ListContainers(TElWinAzureDataStorageContainerList *Containers, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_3(_Handle, (Containers != NULL) ? Containers->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGECONTAINERLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::ListContainers(const std::string &SharedAccessSignature, TStringList &Containers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_4(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Containers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::ListContainers(const std::string &SharedAccessSignature, TStringList *Containers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_4(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Containers != NULL) ? Containers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::ListContainers(const std::string &SharedAccessSignature, TElStringList &Containers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_4(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Containers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::ListContainers(const std::string &SharedAccessSignature, TElStringList *Containers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_4(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Containers != NULL) ? Containers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::ListContainers(const std::string &SharedAccessSignature, TStringList &Containers, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_5(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Containers.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::ListContainers(const std::string &SharedAccessSignature, TStringList *Containers, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_5(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Containers != NULL) ? Containers->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::ListContainers(const std::string &SharedAccessSignature, TElStringList &Containers, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_5(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Containers.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::ListContainers(const std::string &SharedAccessSignature, TElStringList *Containers, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_5(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Containers != NULL) ? Containers->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINERLIST
SB_INLINE void TElWinAzureDataStorage::ListContainers(const std::string &SharedAccessSignature, TElWinAzureDataStorageContainerList &Containers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_6(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Containers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::ListContainers(const std::string &SharedAccessSignature, TElWinAzureDataStorageContainerList *Containers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_6(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Containers != NULL) ? Containers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINERLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINERLIST_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::ListContainers(const std::string &SharedAccessSignature, TElWinAzureDataStorageContainerList &Containers, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_7(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Containers.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::ListContainers(const std::string &SharedAccessSignature, TElWinAzureDataStorageContainerList *Containers, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_7(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Containers != NULL) ? Containers->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINERLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGECONTAINERLIST
SB_INLINE void TElWinAzureDataStorage::ListContainers(const std::string &SharedAccessSignature, TElWinAzureDataStorageContainerList &Containers, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_7(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Containers.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::ListContainers(const std::string &SharedAccessSignature, TElWinAzureDataStorageContainerList *Containers, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_7(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Containers != NULL) ? Containers->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGECONTAINERLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINERLIST_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorage::ListContainers(const std::string &Prefix, const std::string &SharedAccessSignature, TElWinAzureDataStorageContainerList &Containers, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_8(_Handle, Prefix.data(), (int32_t)Prefix.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Containers.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::ListContainers(const std::string &Prefix, const std::string &SharedAccessSignature, TElWinAzureDataStorageContainerList *Containers, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_8(_Handle, Prefix.data(), (int32_t)Prefix.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Containers != NULL) ? Containers->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINERLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGECONTAINERLIST
SB_INLINE void TElWinAzureDataStorage::ListContainers(const std::string &Prefix, const std::string &SharedAccessSignature, TElWinAzureDataStorageContainerList &Containers, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_8(_Handle, Prefix.data(), (int32_t)Prefix.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Containers.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::ListContainers(const std::string &Prefix, const std::string &SharedAccessSignature, TElWinAzureDataStorageContainerList *Containers, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainers_8(_Handle, Prefix.data(), (int32_t)Prefix.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Containers != NULL) ? Containers->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGECONTAINERLIST */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE
SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorage::ListContainersInit()
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_ListContainersInit(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE
SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorage::ListContainersInit(const std::string &Prefix)
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_ListContainersInit_1(_Handle, Prefix.data(), (int32_t)Prefix.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE
SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorage::ListContainersInit(const std::string &Prefix, const std::string &SharedAccessSignature)
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_ListContainersInit_2(_Handle, Prefix.data(), (int32_t)Prefix.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGELISTSTATE_AND_TSTRINGLIST
SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorage::ListContainersInit(const std::string &Prefix, const std::string &SharedAccessSignature, TStringList &Headers)
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_ListContainersInit_3(_Handle, Prefix.data(), (int32_t)Prefix.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorage::ListContainersInit(const std::string &Prefix, const std::string &SharedAccessSignature, TStringList *Headers)
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_ListContainersInit_3(_Handle, Prefix.data(), (int32_t)Prefix.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGELISTSTATE_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGELISTSTATE
SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorage::ListContainersInit(const std::string &Prefix, const std::string &SharedAccessSignature, TElStringList &Headers)
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_ListContainersInit_3(_Handle, Prefix.data(), (int32_t)Prefix.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorage::ListContainersInit(const std::string &Prefix, const std::string &SharedAccessSignature, TElStringList *Headers)
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorage_ListContainersInit_3(_Handle, Prefix.data(), (int32_t)Prefix.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGELISTSTATE */
#endif

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINERLIST_AND_TELWINAZUREDATASTORAGELISTSTATE
SB_INLINE void TElWinAzureDataStorage::ListContainersNext(TElWinAzureDataStorageListState &State, TElWinAzureDataStorageContainerList &Containers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainersNext(_Handle, State.getHandle(), Containers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::ListContainersNext(TElWinAzureDataStorageListState *State, TElWinAzureDataStorageContainerList *Containers)
{
	SBCheckError(TElWinAzureDataStorage_ListContainersNext(_Handle, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE, (Containers != NULL) ? Containers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINERLIST_AND_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINERLIST_AND_TELWINAZUREDATASTORAGELISTSTATE
SB_INLINE void TElWinAzureDataStorage::ListContainersNext(TElWinAzureDataStorageListState &State, TElWinAzureDataStorageContainerList &Containers, int32_t MaxCount)
{
	SBCheckError(TElWinAzureDataStorage_ListContainersNext_1(_Handle, State.getHandle(), Containers.getHandle(), MaxCount));
}

SB_INLINE void TElWinAzureDataStorage::ListContainersNext(TElWinAzureDataStorageListState *State, TElWinAzureDataStorageContainerList *Containers, int32_t MaxCount)
{
	SBCheckError(TElWinAzureDataStorage_ListContainersNext_1(_Handle, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE, (Containers != NULL) ? Containers->getHandle() : SB_NULL_HANDLE, MaxCount));
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINERLIST_AND_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY
void TElWinAzureDataStorage::CreateSharedAccessSignature(const std::string &ContainerName, const std::string &ObjName, TElWinAzureSingleAccessPolicy &Policy, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_CreateSharedAccessSignature(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), Policy.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1888165035, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWinAzureDataStorage::CreateSharedAccessSignature(const std::string &ContainerName, const std::string &ObjName, TElWinAzureSingleAccessPolicy *Policy, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_CreateSharedAccessSignature(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), ObjName.data(), (int32_t)ObjName.length(), (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1888165035, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY */

#ifdef SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY
void TElWinAzureDataStorage::CreateSharedAccessSignature(const std::string &ContainerName, TElWinAzureSingleAccessPolicy &Policy, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_CreateSharedAccessSignature_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), Policy.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1956109520, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWinAzureDataStorage::CreateSharedAccessSignature(const std::string &ContainerName, TElWinAzureSingleAccessPolicy *Policy, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_CreateSharedAccessSignature_1(_Handle, ContainerName.data(), (int32_t)ContainerName.length(), (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1956109520, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY */

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TELWINAZURESINGLEACCESSPOLICY
void TElWinAzureDataStorage::CreateSharedAccessSignature(TElWinAzureDataStorageObject &Obj, TElWinAzureSingleAccessPolicy &Policy, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_CreateSharedAccessSignature_2(_Handle, Obj.getHandle(), Policy.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1288301391, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWinAzureDataStorage::CreateSharedAccessSignature(TElWinAzureDataStorageObject *Obj, TElWinAzureSingleAccessPolicy *Policy, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_CreateSharedAccessSignature_2(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1288301391, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TELWINAZURESINGLEACCESSPOLICY */

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZURESINGLEACCESSPOLICY
void TElWinAzureDataStorage::CreateSharedAccessSignature(TElWinAzureDataStorageContainer &Container, TElWinAzureSingleAccessPolicy &Policy, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_CreateSharedAccessSignature_3(_Handle, Container.getHandle(), Policy.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(975986831, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWinAzureDataStorage::CreateSharedAccessSignature(TElWinAzureDataStorageContainer *Container, TElWinAzureSingleAccessPolicy *Policy, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_CreateSharedAccessSignature_3(_Handle, (Container != NULL) ? Container->getHandle() : SB_NULL_HANDLE, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(975986831, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZURESINGLEACCESSPOLICY */

void TElWinAzureDataStorage::get_AccountName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_get_AccountName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-86334626, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWinAzureDataStorage::set_AccountName(const std::string &Value)
{
	SBCheckError(TElWinAzureDataStorage_set_AccountName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElWinAzureDataStorage::get_AccountKey(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_get_AccountKey(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1377571095, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWinAzureDataStorage::set_AccountKey(const std::string &Value)
{
	SBCheckError(TElWinAzureDataStorage_set_AccountKey(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElWinAzureDataStorage::get_DevMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_get_DevMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWinAzureDataStorage::set_DevMode(bool Value)
{
	SBCheckError(TElWinAzureDataStorage_set_DevMode(_Handle, (int8_t)Value));
}

bool TElWinAzureDataStorage::get_UseSSL()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_get_UseSSL(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWinAzureDataStorage::set_UseSSL(bool Value)
{
	SBCheckError(TElWinAzureDataStorage_set_UseSSL(_Handle, (int8_t)Value));
}

bool TElWinAzureDataStorage::get_UseCRCCheck()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_get_UseCRCCheck(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWinAzureDataStorage::set_UseCRCCheck(bool Value)
{
	SBCheckError(TElWinAzureDataStorage_set_UseCRCCheck(_Handle, (int8_t)Value));
}

bool TElWinAzureDataStorage::get_UsePadding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_get_UsePadding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWinAzureDataStorage::set_UsePadding(bool Value)
{
	SBCheckError(TElWinAzureDataStorage_set_UsePadding(_Handle, (int8_t)Value));
}

bool TElWinAzureDataStorage::get_UseURLEncoding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_get_UseURLEncoding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWinAzureDataStorage::set_UseURLEncoding(bool Value)
{
	SBCheckError(TElWinAzureDataStorage_set_UseURLEncoding(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
TElHTTPSClient* TElWinAzureDataStorage::get_HTTPClient()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWinAzureDataStorage_get_HTTPClient(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HTTPClient)
		this->_Inst_HTTPClient = new TElHTTPSClient(hOutResult, ohFalse);
	else
		this->_Inst_HTTPClient->updateHandle(hOutResult);
	return this->_Inst_HTTPClient;
}

SB_INLINE void TElWinAzureDataStorage::set_HTTPClient(TElHTTPSClient &Value)
{
	SBCheckError(TElWinAzureDataStorage_set_HTTPClient(_Handle, Value.getHandle()));
}

SB_INLINE void TElWinAzureDataStorage::set_HTTPClient(TElHTTPSClient *Value)
{
	SBCheckError(TElWinAzureDataStorage_set_HTTPClient(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElWinAzureDataStorage::get_AzureHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWinAzureDataStorage_get_AzureHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AzureHeaders)
		this->_Inst_AzureHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_AzureHeaders->updateHandle(hOutResult);
	return this->_Inst_AzureHeaders;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElWinAzureDataStorage::get_AzureHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWinAzureDataStorage_get_AzureHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AzureHeaders)
		this->_Inst_AzureHeaders = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_AzureHeaders->updateHandle(hOutResult);
	return this->_Inst_AzureHeaders;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

bool TElWinAzureDataStorage::get_UseDelayedPut()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_get_UseDelayedPut(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWinAzureDataStorage::set_UseDelayedPut(bool Value)
{
	SBCheckError(TElWinAzureDataStorage_set_UseDelayedPut(_Handle, (int8_t)Value));
}

void TElWinAzureDataStorage::get_SecMetadataID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_get_SecMetadataID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1286527383, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWinAzureDataStorage::set_SecMetadataID(const std::string &Value)
{
	SBCheckError(TElWinAzureDataStorage_set_SecMetadataID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElWinAzureDataStorage::get_ContentLengthMetadataID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorage_get_ContentLengthMetadataID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-104228548, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWinAzureDataStorage::set_ContentLengthMetadataID(const std::string &Value)
{
	SBCheckError(TElWinAzureDataStorage_set_ContentLengthMetadataID(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElWinAzureDataStorage::get_DefaultMaxBlobSize()
{
	int64_t OutResult;
	SBCheckError(TElWinAzureDataStorage_get_DefaultMaxBlobSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElWinAzureDataStorage::set_DefaultMaxBlobSize(int64_t Value)
{
	SBCheckError(TElWinAzureDataStorage_set_DefaultMaxBlobSize(_Handle, Value));
}

SB_INLINE int32_t TElWinAzureDataStorage::get_CopyTimeout()
{
	int32_t OutResult;
	SBCheckError(TElWinAzureDataStorage_get_CopyTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElWinAzureDataStorage::set_CopyTimeout(int32_t Value)
{
	SBCheckError(TElWinAzureDataStorage_set_CopyTimeout(_Handle, Value));
}

bool TElWinAzureDataStorage::get_Overwrite()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_get_Overwrite(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWinAzureDataStorage::set_Overwrite(bool Value)
{
	SBCheckError(TElWinAzureDataStorage_set_Overwrite(_Handle, (int8_t)Value));
}

bool TElWinAzureDataStorage::get_PassthroughMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_get_PassthroughMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWinAzureDataStorage::set_PassthroughMode(bool Value)
{
	SBCheckError(TElWinAzureDataStorage_set_PassthroughMode(_Handle, (int8_t)Value));
}

bool TElWinAzureDataStorage::get_EmbeddedMetadataMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorage_get_EmbeddedMetadataMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWinAzureDataStorage::set_EmbeddedMetadataMode(bool Value)
{
	SBCheckError(TElWinAzureDataStorage_set_EmbeddedMetadataMode(_Handle, (int8_t)Value));
}

SB_INLINE void TElWinAzureDataStorage::get_OnBeforeRequestSigning(TSBWinAzureBeforeRequestSigningEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWinAzureDataStorage_get_OnBeforeRequestSigning(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWinAzureDataStorage::set_OnBeforeRequestSigning(TSBWinAzureBeforeRequestSigningEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWinAzureDataStorage_set_OnBeforeRequestSigning(_Handle, pMethodValue, pDataValue));
}

void TElWinAzureDataStorage::initInstances()
{
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_AzureHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_AzureHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElWinAzureDataStorage::TElWinAzureDataStorage(TElWinAzureDataStorageHandle handle, TElOwnHandle ownHandle) : TElCustomDataStorage(handle, ownHandle)
{
	initInstances();
}

TElWinAzureDataStorage::TElWinAzureDataStorage(TComponent &AOwner) : TElCustomDataStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWinAzureDataStorage_Create(AOwner.getHandle(), &_Handle));
}

TElWinAzureDataStorage::TElWinAzureDataStorage(TComponent *AOwner) : TElCustomDataStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWinAzureDataStorage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElWinAzureDataStorage::~TElWinAzureDataStorage()
{
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	delete this->_Inst_HTTPClient;
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_AzureHeaders;
	this->_Inst_AzureHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_AzureHeaders;
	this->_Inst_AzureHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGE */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE

bool TElWinAzureDataStorageListState::Completed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorageListState_Completed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TElWinAzureDataStorageListState::TElWinAzureDataStorageListState(TElWinAzureDataStorageListStateHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TElWinAzureDataStorageListState::TElWinAzureDataStorageListState(const std::string &ContainerName, const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList &Headers) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWinAzureDataStorageListState_Create(ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), Prefixes.getHandle(), (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, Headers.getHandle(), &_Handle));
}

TElWinAzureDataStorageListState::TElWinAzureDataStorageListState(const std::string &ContainerName, const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList *Headers) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWinAzureDataStorageListState_Create(ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElWinAzureDataStorageListState::TElWinAzureDataStorageListState(const std::string &ContainerName, const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TElStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList &Headers) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWinAzureDataStorageListState_Create(ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), Prefixes.getHandle(), (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, Headers.getHandle(), &_Handle));
}

TElWinAzureDataStorageListState::TElWinAzureDataStorageListState(const std::string &ContainerName, const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TElStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList *Headers) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWinAzureDataStorageListState_Create(ContainerName.data(), (int32_t)ContainerName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY

SB_INLINE void TElWinAzureSingleAccessPolicy::Reset()
{
	SBCheckError(TElWinAzureSingleAccessPolicy_Reset(_Handle));
}

SB_INLINE void TElWinAzureSingleAccessPolicy::PrepareID()
{
	SBCheckError(TElWinAzureSingleAccessPolicy_PrepareID(_Handle));
}

void TElWinAzureSingleAccessPolicy::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureSingleAccessPolicy_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-504308252, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWinAzureSingleAccessPolicy::set_ID(const std::string &Value)
{
	SBCheckError(TElWinAzureSingleAccessPolicy_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElWinAzureSingleAccessPolicy::get_StartTime()
{
	int64_t OutResult;
	SBCheckError(TElWinAzureSingleAccessPolicy_get_StartTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElWinAzureSingleAccessPolicy::set_StartTime(int64_t Value)
{
	SBCheckError(TElWinAzureSingleAccessPolicy_set_StartTime(_Handle, Value));
}

SB_INLINE int64_t TElWinAzureSingleAccessPolicy::get_ExpiryTime()
{
	int64_t OutResult;
	SBCheckError(TElWinAzureSingleAccessPolicy_get_ExpiryTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElWinAzureSingleAccessPolicy::set_ExpiryTime(int64_t Value)
{
	SBCheckError(TElWinAzureSingleAccessPolicy_set_ExpiryTime(_Handle, Value));
}

void TElWinAzureSingleAccessPolicy::get_Permissions(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureSingleAccessPolicy_get_Permissions(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1190776016, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWinAzureSingleAccessPolicy::set_Permissions(const std::string &Value)
{
	SBCheckError(TElWinAzureSingleAccessPolicy_set_Permissions(_Handle, Value.data(), (int32_t)Value.length()));
}

TElWinAzureSingleAccessPolicy::TElWinAzureSingleAccessPolicy(TElWinAzureSingleAccessPolicyHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElWinAzureSingleAccessPolicy::TElWinAzureSingleAccessPolicy() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWinAzureSingleAccessPolicy_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY */

#ifdef SB_USE_CLASS_TELWINAZUREACCESSPOLICY

SB_INLINE int32_t TElWinAzureAccessPolicy::AddPolicy()
{
	int32_t OutResult;
	SBCheckError(TElWinAzureAccessPolicy_AddPolicy(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElWinAzureAccessPolicy::RemovePolicy(int32_t Index)
{
	SBCheckError(TElWinAzureAccessPolicy_RemovePolicy(_Handle, Index));
}

SB_INLINE void TElWinAzureAccessPolicy::Clear()
{
	SBCheckError(TElWinAzureAccessPolicy_Clear(_Handle));
}

SB_INLINE void TElWinAzureAccessPolicy::LoadFromXml(const std::string &Xml)
{
	SBCheckError(TElWinAzureAccessPolicy_LoadFromXml(_Handle, Xml.data(), (int32_t)Xml.length()));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureAccessPolicy::LoadFromXml(TStream &Stream)
{
	SBCheckError(TElWinAzureAccessPolicy_LoadFromXml_1(_Handle, Stream.getHandle()));
}

SB_INLINE void TElWinAzureAccessPolicy::LoadFromXml(TStream *Stream)
{
	SBCheckError(TElWinAzureAccessPolicy_LoadFromXml_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElWinAzureAccessPolicy::SaveToXml(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureAccessPolicy_SaveToXml(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1082512868, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureAccessPolicy::SaveToXml(TStream &Stream)
{
	SBCheckError(TElWinAzureAccessPolicy_SaveToXml_1(_Handle, Stream.getHandle()));
}

SB_INLINE void TElWinAzureAccessPolicy::SaveToXml(TStream *Stream)
{
	SBCheckError(TElWinAzureAccessPolicy_SaveToXml_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY
TElWinAzureSingleAccessPolicy* TElWinAzureAccessPolicy::get_AccessPolicies(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWinAzureAccessPolicy_get_AccessPolicies(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AccessPolicies)
		this->_Inst_AccessPolicies = new TElWinAzureSingleAccessPolicy(hOutResult, ohFalse);
	else
		this->_Inst_AccessPolicies->updateHandle(hOutResult);
	return this->_Inst_AccessPolicies;
}
#endif /* SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY */

SB_INLINE int32_t TElWinAzureAccessPolicy::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElWinAzureAccessPolicy_get_Count(_Handle, &OutResult));
	return OutResult;
}

bool TElWinAzureAccessPolicy::get_UseURLEncoding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureAccessPolicy_get_UseURLEncoding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWinAzureAccessPolicy::set_UseURLEncoding(bool Value)
{
	SBCheckError(TElWinAzureAccessPolicy_set_UseURLEncoding(_Handle, (int8_t)Value));
}

void TElWinAzureAccessPolicy::initInstances()
{
#ifdef SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY
	this->_Inst_AccessPolicies = NULL;
#endif /* SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY */
}

TElWinAzureAccessPolicy::TElWinAzureAccessPolicy(TElWinAzureAccessPolicyHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElWinAzureAccessPolicy::TElWinAzureAccessPolicy() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWinAzureAccessPolicy_Create(&_Handle));
}

TElWinAzureAccessPolicy::~TElWinAzureAccessPolicy()
{
#ifdef SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY
	delete this->_Inst_AccessPolicies;
	this->_Inst_AccessPolicies = NULL;
#endif /* SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY */
}
#endif /* SB_USE_CLASS_TELWINAZUREACCESSPOLICY */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT

SB_INLINE void TElWinAzureDataStorageObject::Assign(TElCustomDataStorageObject &Source)
{
	SBCheckError(TElWinAzureDataStorageObject_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageObject::Assign(TElCustomDataStorageObject *Source)
{
	SBCheckError(TElWinAzureDataStorageObject_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageObject::Clone()
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageObject_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElWinAzureDataStorageObject::Delete()
{
	SBCheckError(TElWinAzureDataStorageObject_Delete(_Handle));
}

SB_INLINE void TElWinAzureDataStorageObject::Delete(const std::string &SharedAccessSignature)
{
	SBCheckError(TElWinAzureDataStorageObject_Delete_1(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length()));
}

bool TElWinAzureDataStorageObject::Exists()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorageObject_Exists(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWinAzureDataStorageObject::Exists(const std::string &SharedAccessSignature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorageObject_Exists_1(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWinAzureDataStorageObject::Refresh()
{
	SBCheckError(TElWinAzureDataStorageObject_Refresh(_Handle));
}

SB_INLINE void TElWinAzureDataStorageObject::Refresh(const std::string &SharedAccessSignature)
{
	SBCheckError(TElWinAzureDataStorageObject_Refresh_1(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length()));
}

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorageObject::Write(TStream &Data, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElWinAzureDataStorageObject_Write(_Handle, Data.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageObject::Write(TStream *Data, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElWinAzureDataStorageObject_Write(_Handle, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorageObject::Write(TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElWinAzureDataStorageObject_Write_1(_Handle, Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageObject::Write(TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElWinAzureDataStorageObject_Write_1(_Handle, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorageObject::Write(TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElWinAzureDataStorageObject_Write_1(_Handle, Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageObject::Write(TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElWinAzureDataStorageObject_Write_1(_Handle, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorageObject::Write(const std::string &SharedAccessSignature, TStream &Data, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElWinAzureDataStorageObject_Write_2(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageObject::Write(const std::string &SharedAccessSignature, TStream *Data, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElWinAzureDataStorageObject_Write_2(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorageObject::Write(const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElWinAzureDataStorageObject_Write_3(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageObject::Write(const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElWinAzureDataStorageObject_Write_3(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorageObject::Write(const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElWinAzureDataStorageObject_Write_3(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageObject::Write(const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElWinAzureDataStorageObject_Write_3(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorageObject::Write(const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata)
{
	SBCheckError(TElWinAzureDataStorageObject_Write_4(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageObject::Write(const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata)
{
	SBCheckError(TElWinAzureDataStorageObject_Write_4(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorageObject::Write(const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata)
{
	SBCheckError(TElWinAzureDataStorageObject_Write_4(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageObject::Write(const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata)
{
	SBCheckError(TElWinAzureDataStorageObject_Write_4(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorageObject::Read(TStream &Strm)
{
	SBCheckError(TElWinAzureDataStorageObject_Read(_Handle, Strm.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageObject::Read(TStream *Strm)
{
	SBCheckError(TElWinAzureDataStorageObject_Read(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorageObject::Read(TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorageObject_Read_1(_Handle, Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}

SB_INLINE void TElWinAzureDataStorageObject::Read(TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorageObject_Read_1(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorageObject::Read(TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_Read_2(_Handle, Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-2010061447, 7, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-2010061447, 8, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-2010061447, 9, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-2010061447, 10, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageObject::Read(TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_Read_2(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-2010061447, 7, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-2010061447, 8, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-2010061447, 9, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-2010061447, 10, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorageObject::Read(TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_Read_2(_Handle, Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1431383803, 7, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1431383803, 8, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1431383803, 9, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1431383803, 10, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageObject::Read(TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_Read_2(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1431383803, 7, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1431383803, 8, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1431383803, 9, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1431383803, 10, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorageObject::Read(TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_Read_3(_Handle, Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-2026547649, 7, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-2026547649, 8, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-2026547649, 9, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-2026547649, 10, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-2026547649, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageObject::Read(TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_Read_3(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-2026547649, 7, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-2026547649, 8, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-2026547649, 9, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-2026547649, 10, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-2026547649, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorageObject::Read(TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_Read_3(_Handle, Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1424930610, 7, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1424930610, 8, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1424930610, 9, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-1424930610, 10, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1424930610, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageObject::Read(TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_Read_3(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1424930610, 7, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1424930610, 8, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1424930610, 9, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-1424930610, 10, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1424930610, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorageObject::Read(const std::string &SharedAccessSignature, TStream &Strm)
{
	SBCheckError(TElWinAzureDataStorageObject_Read_4(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageObject::Read(const std::string &SharedAccessSignature, TStream *Strm)
{
	SBCheckError(TElWinAzureDataStorageObject_Read_4(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorageObject::Read(const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorageObject_Read_5(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}

SB_INLINE void TElWinAzureDataStorageObject::Read(const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorageObject_Read_5(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorageObject::Read(const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_Read_6(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1038255740, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1038255740, 9, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1038255740, 10, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1038255740, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageObject::Read(const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_Read_6(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1038255740, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1038255740, 9, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1038255740, 10, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1038255740, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorageObject::Read(const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_Read_6(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(56795248, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(56795248, 9, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(56795248, 10, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(56795248, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageObject::Read(const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_Read_6(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(56795248, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(56795248, 9, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(56795248, 10, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(56795248, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorageObject::Read(const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_Read_7(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1750463602, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1750463602, 9, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1750463602, 10, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(1750463602, 11, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1750463602, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageObject::Read(const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_Read_7(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1750463602, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1750463602, 9, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1750463602, 10, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(1750463602, 11, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1750463602, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorageObject::Read(const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_Read_7(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-702655454, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-702655454, 9, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-702655454, 10, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-702655454, 11, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-702655454, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageObject::Read(const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_Read_7(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-702655454, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-702655454, 9, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-702655454, 10, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-702655454, 11, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-702655454, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorageObject::ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElWinAzureDataStorageObject_ReadBlock(_Handle, Strm.getHandle(), Offset, Size, &Read));
}

SB_INLINE void TElWinAzureDataStorageObject::ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElWinAzureDataStorageObject_ReadBlock(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorageObject::ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorageObject_ReadBlock_1(_Handle, Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}

SB_INLINE void TElWinAzureDataStorageObject::ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorageObject_ReadBlock_1(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorageObject::ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_ReadBlock_2(_Handle, Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-737523107, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-737523107, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-737523107, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-737523107, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageObject::ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_ReadBlock_2(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-737523107, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-737523107, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-737523107, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-737523107, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorageObject::ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_ReadBlock_2(_Handle, Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(489673440, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(489673440, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(489673440, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(489673440, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageObject::ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_ReadBlock_2(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(489673440, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(489673440, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(489673440, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(489673440, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorageObject::ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_ReadBlock_3(_Handle, Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1354061811, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1354061811, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1354061811, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(1354061811, 13, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1354061811, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageObject::ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_ReadBlock_3(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1354061811, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1354061811, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1354061811, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(1354061811, 13, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1354061811, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorageObject::ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_ReadBlock_3(_Handle, Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1151780966, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1151780966, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1151780966, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-1151780966, 13, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1151780966, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageObject::ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_ReadBlock_3(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1151780966, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1151780966, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1151780966, 12, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-1151780966, 13, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1151780966, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorageObject::ReadBlock(const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElWinAzureDataStorageObject_ReadBlock_4(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), Offset, Size, &Read));
}

SB_INLINE void TElWinAzureDataStorageObject::ReadBlock(const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElWinAzureDataStorageObject_ReadBlock_4(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorageObject::ReadBlock(const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorageObject_ReadBlock_5(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}

SB_INLINE void TElWinAzureDataStorageObject::ReadBlock(const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorageObject_ReadBlock_5(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorageObject::ReadBlock(const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_ReadBlock_6(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-554831691, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-554831691, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-554831691, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-554831691, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageObject::ReadBlock(const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_ReadBlock_6(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-554831691, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-554831691, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-554831691, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-554831691, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorageObject::ReadBlock(const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_ReadBlock_6(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1606616207, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1606616207, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1606616207, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1606616207, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageObject::ReadBlock(const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_ReadBlock_6(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1606616207, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1606616207, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1606616207, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1606616207, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorageObject::ReadBlock(const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_ReadBlock_7(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1694433781, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1694433781, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1694433781, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-1694433781, 14, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1694433781, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageObject::ReadBlock(const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_ReadBlock_7(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1694433781, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1694433781, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1694433781, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-1694433781, 14, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1694433781, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorageObject::ReadBlock(const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_ReadBlock_7(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-935949098, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-935949098, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-935949098, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-935949098, 14, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-935949098, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageObject::ReadBlock(const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageObject_ReadBlock_7(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-935949098, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-935949098, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-935949098, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-935949098, 14, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-935949098, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageObject::Copy(const std::string &DestContainerName, const std::string &DestName, TElCustomDataStorageSecurityHandler &NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageObject_Copy(_Handle, DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), NewHandler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageObject::Copy(const std::string &DestContainerName, const std::string &DestName, TElCustomDataStorageSecurityHandler *NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageObject_Copy(_Handle, DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (NewHandler != NULL) ? NewHandler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageObject::Copy(const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageObject_Copy_1(_Handle, DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageObject::Copy(const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageObject_Copy_1(_Handle, DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageObject::Copy(const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TElStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageObject_Copy_1(_Handle, DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageObject::Copy(const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TElStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageObject_Copy_1(_Handle, DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageObject::Copy(const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageObject_Copy_2(_Handle, DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageObject::Copy(const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageObject_Copy_2(_Handle, DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageObject::Copy(const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageObject_Copy_2(_Handle, DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageObject::Copy(const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageObject_Copy_2(_Handle, DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageObject::Copy(const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TElCustomDataStorageSecurityHandler &NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageObject_Copy_3(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), NewHandler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageObject::Copy(const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TElCustomDataStorageSecurityHandler *NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageObject_Copy_3(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (NewHandler != NULL) ? NewHandler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageObject::Copy(const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageObject_Copy_4(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageObject::Copy(const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageObject_Copy_4(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageObject::Copy(const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TElStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageObject_Copy_4(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageObject::Copy(const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TElStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageObject_Copy_4(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageObject::Copy(const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageObject_Copy_5(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageObject::Copy(const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageObject_Copy_5(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageObject::Copy(const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageObject_Copy_5(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageObject::Copy(const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageObject_Copy_5(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElWinAzureDataStorageObject::GetACL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorageObject_GetACL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-153926513, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWinAzureDataStorageObject::SetACL(const std::string &ACL)
{
	SBCheckError(TElWinAzureDataStorageObject_SetACL(_Handle, ACL.data(), (int32_t)ACL.length()));
}

#ifdef SB_USE_CLASS_TSTREAM
void TElWinAzureDataStorageObject::GetLocalETag(TStream &Stream, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorageObject_GetLocalETag(_Handle, Stream.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1907940698, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWinAzureDataStorageObject::GetLocalETag(TStream *Stream, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorageObject_GetLocalETag(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1907940698, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElWinAzureDataStorageObject::GetLocalETag(const std::string &Filename, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorageObject_GetLocalETag_1(_Handle, Filename.data(), (int32_t)Filename.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2100449925, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWinAzureDataStorageObject::GetRemoteETag(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorageObject_GetRemoteETag(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1225462835, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWinAzureDataStorageObject::Resize(int64_t NewSize)
{
	SBCheckError(TElWinAzureDataStorageObject_Resize(_Handle, NewSize));
}

#ifdef SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY
void TElWinAzureDataStorageObject::CreateSharedAccessSignature(TElWinAzureSingleAccessPolicy &Policy, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorageObject_CreateSharedAccessSignature(_Handle, Policy.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-259430626, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWinAzureDataStorageObject::CreateSharedAccessSignature(TElWinAzureSingleAccessPolicy *Policy, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorageObject_CreateSharedAccessSignature(_Handle, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-259430626, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY */

void TElWinAzureDataStorageObject::get_ContainerName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorageObject_get_ContainerName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-755533234, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElWinAzureDataStorageObject::get_LastModified()
{
	int64_t OutResult;
	SBCheckError(TElWinAzureDataStorageObject_get_LastModified(_Handle, &OutResult));
	return OutResult;
}

void TElWinAzureDataStorageObject::get_ETag(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorageObject_get_ETag(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1469484567, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElWinAzureDataStorageObject::get_Size()
{
	int64_t OutResult;
	SBCheckError(TElWinAzureDataStorageObject_get_Size(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElWinAzureDataStorageObject::get_AllocatedSize()
{
	int64_t OutResult;
	SBCheckError(TElWinAzureDataStorageObject_get_AllocatedSize(_Handle, &OutResult));
	return OutResult;
}

void TElWinAzureDataStorageObject::get_ContentType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorageObject_get_ContentType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(838735034, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWinAzureDataStorageObject::get_ContentEncoding(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorageObject_get_ContentEncoding(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1267617773, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWinAzureDataStorageObject::get_ContentLanguage(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorageObject_get_ContentLanguage(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(149043433, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWinAzureDataStorageObject::get_ContentMD5(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorageObject_get_ContentMD5(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-281857899, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWinAzureDataStorageObject::set_ContentMD5(const std::string &Value)
{
	SBCheckError(TElWinAzureDataStorageObject_set_ContentMD5(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElWinAzureDataStorageObject::get_SequenceNumber()
{
	int64_t OutResult;
	SBCheckError(TElWinAzureDataStorageObject_get_SequenceNumber(_Handle, &OutResult));
	return OutResult;
}

bool TElWinAzureDataStorageObject::get_Locked()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorageObject_get_Locked(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElWinAzureDataStorageObject::get_CopyStatus(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorageObject_get_CopyStatus(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(171541370, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWinAzureDataStorageObject::get_LeaseStatus(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorageObject_get_LeaseStatus(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1640859430, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElWinAzureDataStorageObject::get_Metadata()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWinAzureDataStorageObject_get_Metadata(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Metadata)
		this->_Inst_Metadata = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Metadata->updateHandle(hOutResult);
	return this->_Inst_Metadata;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElWinAzureDataStorageObject::get_Metadata()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWinAzureDataStorageObject_get_Metadata(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Metadata)
		this->_Inst_Metadata = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Metadata->updateHandle(hOutResult);
	return this->_Inst_Metadata;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElWinAzureDataStorageObject::get_CustomHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWinAzureDataStorageObject_get_CustomHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CustomHeaders)
		this->_Inst_CustomHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_CustomHeaders->updateHandle(hOutResult);
	return this->_Inst_CustomHeaders;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElWinAzureDataStorageObject::get_CustomHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWinAzureDataStorageObject_get_CustomHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CustomHeaders)
		this->_Inst_CustomHeaders = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_CustomHeaders->updateHandle(hOutResult);
	return this->_Inst_CustomHeaders;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElWinAzureDataStorageObject::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Metadata = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Metadata = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_CustomHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_CustomHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElWinAzureDataStorageObject::TElWinAzureDataStorageObject(TElWinAzureDataStorageObjectHandle handle, TElOwnHandle ownHandle) : TElCustomDataStorageObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGE
TElWinAzureDataStorageObject::TElWinAzureDataStorageObject(TElWinAzureDataStorage &Storage) : TElCustomDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWinAzureDataStorageObject_Create(Storage.getHandle(), &_Handle));
}

TElWinAzureDataStorageObject::TElWinAzureDataStorageObject(TElWinAzureDataStorage *Storage) : TElCustomDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWinAzureDataStorageObject_Create((Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGE */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGE
TElWinAzureDataStorageObject::TElWinAzureDataStorageObject(TElWinAzureDataStorage &Storage, const std::string &ContainerName, const std::string &Name) : TElCustomDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWinAzureDataStorageObject_Create_1(Storage.getHandle(), ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), &_Handle));
}

TElWinAzureDataStorageObject::TElWinAzureDataStorageObject(TElWinAzureDataStorage *Storage, const std::string &ContainerName, const std::string &Name) : TElCustomDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWinAzureDataStorageObject_Create_1((Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, ContainerName.data(), (int32_t)ContainerName.length(), Name.data(), (int32_t)Name.length(), &_Handle));
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGE */

TElWinAzureDataStorageObject::~TElWinAzureDataStorageObject()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Metadata;
	this->_Inst_Metadata = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Metadata;
	this->_Inst_Metadata = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_CustomHeaders;
	this->_Inst_CustomHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_CustomHeaders;
	this->_Inst_CustomHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::AcquireObject(const std::string &Name)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_AcquireObject(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::AcquireObject(const std::string &Name, const std::string &SharedAccessSignature)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_AcquireObject_1(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElWinAzureDataStorageContainer::List(TElDataStorageObjectList &Objects)
{
	SBCheckError(TElWinAzureDataStorageContainer_List(_Handle, Objects.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::List(TElDataStorageObjectList *Objects)
{
	SBCheckError(TElWinAzureDataStorageContainer_List(_Handle, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorageContainer::List(TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList &Prefixes, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorageContainer_List_1(_Handle, Objects.getHandle(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, Prefixes.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::List(TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList *Prefixes, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorageContainer_List_1(_Handle, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
SB_INLINE void TElWinAzureDataStorageContainer::List(TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList &Prefixes, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorageContainer_List_1(_Handle, Objects.getHandle(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, Prefixes.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::List(TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList *Prefixes, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorageContainer_List_1(_Handle, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorageContainer::List(TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorageContainer_List_2(_Handle, Objects.getHandle(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, Prefixes.getHandle(), (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::List(TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorageContainer_List_2(_Handle, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
SB_INLINE void TElWinAzureDataStorageContainer::List(TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorageContainer_List_2(_Handle, Objects.getHandle(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, Prefixes.getHandle(), (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::List(TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorageContainer_List_2(_Handle, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElWinAzureDataStorageContainer::List(const std::string &SharedAccessSignature, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElWinAzureDataStorageContainer_List_3(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Objects.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::List(const std::string &SharedAccessSignature, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElWinAzureDataStorageContainer_List_3(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorageContainer::List(const std::string &SharedAccessSignature, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList &Prefixes, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorageContainer_List_4(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Objects.getHandle(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, Prefixes.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::List(const std::string &SharedAccessSignature, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList *Prefixes, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorageContainer_List_4(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
SB_INLINE void TElWinAzureDataStorageContainer::List(const std::string &SharedAccessSignature, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList &Prefixes, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorageContainer_List_4(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Objects.getHandle(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, Prefixes.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::List(const std::string &SharedAccessSignature, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList *Prefixes, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorageContainer_List_4(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorageContainer::List(const std::string &SharedAccessSignature, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorageContainer_List_5(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Objects.getHandle(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, Prefixes.getHandle(), (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::List(const std::string &SharedAccessSignature, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorageContainer_List_5(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
SB_INLINE void TElWinAzureDataStorageContainer::List(const std::string &SharedAccessSignature, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList &Headers)
{
	SBCheckError(TElWinAzureDataStorageContainer_List_5(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Objects.getHandle(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, Prefixes.getHandle(), (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, Headers.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::List(const std::string &SharedAccessSignature, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList *Headers)
{
	SBCheckError(TElWinAzureDataStorageContainer_List_5(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE
SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorageContainer::ListInit()
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_ListInit(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGELISTSTATE_AND_TSTRINGLIST
SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorageContainer::ListInit(const std::string &Prefix, const std::string &Delimiter, TStringList &Prefixes, TStringList &Headers)
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_ListInit_1(_Handle, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), Prefixes.getHandle(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorageContainer::ListInit(const std::string &Prefix, const std::string &Delimiter, TStringList *Prefixes, TStringList *Headers)
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_ListInit_1(_Handle, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGELISTSTATE_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGELISTSTATE
SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorageContainer::ListInit(const std::string &Prefix, const std::string &Delimiter, TElStringList &Prefixes, TElStringList &Headers)
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_ListInit_1(_Handle, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), Prefixes.getHandle(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorageContainer::ListInit(const std::string &Prefix, const std::string &Delimiter, TElStringList *Prefixes, TElStringList *Headers)
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_ListInit_1(_Handle, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGELISTSTATE */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGELISTSTATE_AND_TSTRINGLIST
SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorageContainer::ListInit(const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList &Headers)
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_ListInit_2(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), Prefixes.getHandle(), (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorageContainer::ListInit(const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList *Headers)
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_ListInit_2(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGELISTSTATE_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGELISTSTATE
SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorageContainer::ListInit(const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TElStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList &Headers)
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_ListInit_2(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), Prefixes.getHandle(), (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageListStateHandle TElWinAzureDataStorageContainer::ListInit(const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TElStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList *Headers)
{
	TElWinAzureDataStorageListStateHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_ListInit_2(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeSnapshots, (int8_t)IncludeMetadata, (int8_t)IncludeUncommittedBlobs, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGELISTSTATE */
#endif

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELWINAZUREDATASTORAGELISTSTATE
SB_INLINE void TElWinAzureDataStorageContainer::ListNext(TElWinAzureDataStorageListState &State, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElWinAzureDataStorageContainer_ListNext(_Handle, State.getHandle(), Objects.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::ListNext(TElWinAzureDataStorageListState *State, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElWinAzureDataStorageContainer_ListNext(_Handle, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELWINAZUREDATASTORAGELISTSTATE
SB_INLINE void TElWinAzureDataStorageContainer::ListNext(TElWinAzureDataStorageListState &State, TElDataStorageObjectList &Objects, int32_t MaxCount)
{
	SBCheckError(TElWinAzureDataStorageContainer_ListNext_1(_Handle, State.getHandle(), Objects.getHandle(), MaxCount));
}

SB_INLINE void TElWinAzureDataStorageContainer::ListNext(TElWinAzureDataStorageListState *State, TElDataStorageObjectList *Objects, int32_t MaxCount)
{
	SBCheckError(TElWinAzureDataStorageContainer_ListNext_1(_Handle, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, MaxCount));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE
void TElWinAzureDataStorageContainer::ListFinal(TElWinAzureDataStorageListState &State)
{
	TElClassHandle hState = State.getHandle();
	SBCheckError(TElWinAzureDataStorageContainer_ListFinal(_Handle, &hState));
	State.updateHandle(hState);
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, TElCustomDataStorageSecurityHandler &Handler)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_1(_Handle, Name.data(), (int32_t)Name.length(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, TElCustomDataStorageSecurityHandler *Handler)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_1(_Handle, Name.data(), (int32_t)Name.length(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_2(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_2(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_2(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_2(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_3(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_3(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_3(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_3(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_4(_Handle, Name.data(), (int32_t)Name.length(), InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_5(_Handle, Name.data(), (int32_t)Name.length(), Handler.getHandle(), InitialSize, &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_5(_Handle, Name.data(), (int32_t)Name.length(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_6(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Handler.getHandle(), InitialSize, &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_6(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_6(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Handler.getHandle(), InitialSize, &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_6(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_7(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), InitialSize, &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_7(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_7(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), InitialSize, &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_7(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &SharedAccessSignature)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_8(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler &Handler)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_9(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler *Handler)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_9(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler &Handler)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_10(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler *Handler)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_10(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler &Handler)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_10(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler *Handler)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_10(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, const std::string &SharedAccessSignature)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_11(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, const std::string &SharedAccessSignature)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_11(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, const std::string &SharedAccessSignature)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_11(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, const std::string &SharedAccessSignature)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_11(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &SharedAccessSignature, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_12(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_13(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Handler.getHandle(), InitialSize, &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_13(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_14(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Handler.getHandle(), InitialSize, &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_14(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_14(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Handler.getHandle(), InitialSize, &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_14(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, const std::string &SharedAccessSignature, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_15(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), InitialSize, &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, const std::string &SharedAccessSignature, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_15(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, const std::string &SharedAccessSignature, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_15(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), InitialSize, &OutResult));
	return OutResult;
}

SB_INLINE TElWinAzureDataStorageObjectHandle TElWinAzureDataStorageContainer::CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, const std::string &SharedAccessSignature, int64_t InitialSize)
{
	TElWinAzureDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CreateObject_15(_Handle, Name.data(), (int32_t)Name.length(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), InitialSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

SB_INLINE void TElWinAzureDataStorageContainer::DeleteObject(const std::string &Name)
{
	SBCheckError(TElWinAzureDataStorageContainer_DeleteObject(_Handle, Name.data(), (int32_t)Name.length()));
}

SB_INLINE void TElWinAzureDataStorageContainer::DeleteObject(const std::string &Name, const std::string &SharedAccessSignature)
{
	SBCheckError(TElWinAzureDataStorageContainer_DeleteObject_1(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length()));
}

bool TElWinAzureDataStorageContainer::ObjectExists(const std::string &Name)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorageContainer_ObjectExists(_Handle, Name.data(), (int32_t)Name.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWinAzureDataStorageContainer::ObjectExists(const std::string &Name, const std::string &SharedAccessSignature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorageContainer_ObjectExists_1(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorageContainer::WriteObject(const std::string &Name, TStream &Data, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElWinAzureDataStorageContainer_WriteObject(_Handle, Name.data(), (int32_t)Name.length(), Data.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::WriteObject(const std::string &Name, TStream *Data, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElWinAzureDataStorageContainer_WriteObject(_Handle, Name.data(), (int32_t)Name.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorageContainer::WriteObject(const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElWinAzureDataStorageContainer_WriteObject_1(_Handle, Name.data(), (int32_t)Name.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::WriteObject(const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElWinAzureDataStorageContainer_WriteObject_1(_Handle, Name.data(), (int32_t)Name.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorageContainer::WriteObject(const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElWinAzureDataStorageContainer_WriteObject_1(_Handle, Name.data(), (int32_t)Name.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::WriteObject(const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElWinAzureDataStorageContainer_WriteObject_1(_Handle, Name.data(), (int32_t)Name.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorageContainer::WriteObject(const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata)
{
	SBCheckError(TElWinAzureDataStorageContainer_WriteObject_2(_Handle, Name.data(), (int32_t)Name.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::WriteObject(const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata)
{
	SBCheckError(TElWinAzureDataStorageContainer_WriteObject_2(_Handle, Name.data(), (int32_t)Name.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorageContainer::WriteObject(const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata)
{
	SBCheckError(TElWinAzureDataStorageContainer_WriteObject_2(_Handle, Name.data(), (int32_t)Name.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::WriteObject(const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata)
{
	SBCheckError(TElWinAzureDataStorageContainer_WriteObject_2(_Handle, Name.data(), (int32_t)Name.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorageContainer::WriteObject(const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElWinAzureDataStorageContainer_WriteObject_3(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::WriteObject(const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElWinAzureDataStorageContainer_WriteObject_3(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorageContainer::WriteObject(const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElWinAzureDataStorageContainer_WriteObject_4(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::WriteObject(const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElWinAzureDataStorageContainer_WriteObject_4(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorageContainer::WriteObject(const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElWinAzureDataStorageContainer_WriteObject_4(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), Metadata.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::WriteObject(const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElWinAzureDataStorageContainer_WriteObject_4(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElWinAzureDataStorageContainer::WriteObject(const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata)
{
	SBCheckError(TElWinAzureDataStorageContainer_WriteObject_5(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::WriteObject(const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata)
{
	SBCheckError(TElWinAzureDataStorageContainer_WriteObject_5(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElWinAzureDataStorageContainer::WriteObject(const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata)
{
	SBCheckError(TElWinAzureDataStorageContainer_WriteObject_5(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), Metadata.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::WriteObject(const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata)
{
	SBCheckError(TElWinAzureDataStorageContainer_WriteObject_5(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), ContentLanguage.data(), (int32_t)ContentLanguage.length(), ContentMD5.data(), (int32_t)ContentMD5.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, TStream &Strm)
{
	SBCheckError(TElWinAzureDataStorageContainer_ReadObject(_Handle, Name.data(), (int32_t)Name.length(), Strm.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, TStream *Strm)
{
	SBCheckError(TElWinAzureDataStorageContainer_ReadObject(_Handle, Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorageContainer_ReadObject_1(_Handle, Name.data(), (int32_t)Name.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}

SB_INLINE void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorageContainer_ReadObject_1(_Handle, Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadObject_2(_Handle, Name.data(), (int32_t)Name.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-275360272, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-275360272, 9, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-275360272, 10, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-275360272, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadObject_2(_Handle, Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-275360272, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-275360272, 9, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-275360272, 10, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-275360272, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadObject_2(_Handle, Name.data(), (int32_t)Name.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1953618387, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1953618387, 9, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1953618387, 10, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1953618387, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadObject_2(_Handle, Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1953618387, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1953618387, 9, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1953618387, 10, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1953618387, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadObject_3(_Handle, Name.data(), (int32_t)Name.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1224705240, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1224705240, 9, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1224705240, 10, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(1224705240, 11, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1224705240, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadObject_3(_Handle, Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1224705240, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1224705240, 9, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1224705240, 10, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(1224705240, 11, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1224705240, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadObject_3(_Handle, Name.data(), (int32_t)Name.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-755805737, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-755805737, 9, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-755805737, 10, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-755805737, 11, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-755805737, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadObject_3(_Handle, Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-755805737, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-755805737, 9, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-755805737, 10, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-755805737, 11, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-755805737, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm)
{
	SBCheckError(TElWinAzureDataStorageContainer_ReadObject_4(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm)
{
	SBCheckError(TElWinAzureDataStorageContainer_ReadObject_4(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorageContainer_ReadObject_5(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}

SB_INLINE void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorageContainer_ReadObject_5(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadObject_6(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-232237925, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-232237925, 10, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-232237925, 11, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-232237925, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadObject_6(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-232237925, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-232237925, 10, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-232237925, 11, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-232237925, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadObject_6(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(2055256425, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(2055256425, 10, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(2055256425, 11, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(2055256425, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadObject_6(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(2055256425, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(2055256425, 10, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(2055256425, 11, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(2055256425, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadObject_7(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1278164625, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1278164625, 10, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1278164625, 11, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-1278164625, 12, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1278164625, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadObject_7(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1278164625, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1278164625, 10, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1278164625, 11, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-1278164625, 12, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1278164625, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadObject_7(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(2143365016, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(2143365016, 10, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(2143365016, 11, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(2143365016, 12, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(2143365016, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageContainer::ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadObject_7(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(2143365016, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(2143365016, 10, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(2143365016, 11, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(2143365016, 12, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(2143365016, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElWinAzureDataStorageContainer_ReadBlock(_Handle, Name.data(), (int32_t)Name.length(), Strm.getHandle(), Offset, Size, &Read));
}

SB_INLINE void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElWinAzureDataStorageContainer_ReadBlock(_Handle, Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorageContainer_ReadBlock_1(_Handle, Name.data(), (int32_t)Name.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}

SB_INLINE void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorageContainer_ReadBlock_1(_Handle, Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadBlock_2(_Handle, Name.data(), (int32_t)Name.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1704466891, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1704466891, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1704466891, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1704466891, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadBlock_2(_Handle, Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1704466891, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1704466891, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1704466891, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1704466891, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadBlock_2(_Handle, Name.data(), (int32_t)Name.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1869320929, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1869320929, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1869320929, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1869320929, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadBlock_2(_Handle, Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1869320929, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1869320929, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1869320929, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1869320929, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadBlock_3(_Handle, Name.data(), (int32_t)Name.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1728217859, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1728217859, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1728217859, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-1728217859, 14, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1728217859, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadBlock_3(_Handle, Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1728217859, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1728217859, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1728217859, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-1728217859, 14, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1728217859, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadBlock_3(_Handle, Name.data(), (int32_t)Name.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1989792996, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1989792996, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1989792996, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-1989792996, 14, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1989792996, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadBlock_3(_Handle, Name.data(), (int32_t)Name.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1989792996, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1989792996, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1989792996, 13, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-1989792996, 14, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1989792996, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElWinAzureDataStorageContainer_ReadBlock_4(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), Offset, Size, &Read));
}

SB_INLINE void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElWinAzureDataStorageContainer_ReadBlock_4(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorageContainer_ReadBlock_5(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}

SB_INLINE void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum)
{
	SBCheckError(TElWinAzureDataStorageContainer_ReadBlock_5(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadBlock_6(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(379968443, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(379968443, 13, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(379968443, 14, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(379968443, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadBlock_6(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(379968443, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(379968443, 13, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(379968443, 14, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(379968443, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadBlock_6(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1845237769, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1845237769, 13, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1845237769, 14, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1845237769, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadBlock_6(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1845237769, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1845237769, 13, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1845237769, 14, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1845237769, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadBlock_7(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1295855433, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1295855433, 13, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1295855433, 14, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-1295855433, 15, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1295855433, 16, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadBlock_7(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1295855433, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1295855433, 13, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(-1295855433, 14, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(-1295855433, 15, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1295855433, 16, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadBlock_7(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Strm.getHandle(), Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1552959855, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1552959855, 13, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1552959855, 14, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(1552959855, 15, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1552959855, 16, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}

void TElWinAzureDataStorageContainer::ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjContentLanguage = (int32_t)ObjContentLanguage.length();
	int32_t szObjContentMD5 = (int32_t)ObjContentMD5.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElWinAzureDataStorageContainer_ReadBlock_7(_Handle, Name.data(), (int32_t)Name.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), SeqNum, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjContentLanguage.data(), &szObjContentLanguage, (char *)ObjContentMD5.data(), &szObjContentMD5, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1552959855, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1552959855, 13, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjContentLanguage.resize(szObjContentLanguage);
		SBCheckError(SBGetLastReturnStringA(1552959855, 14, (char *)ObjContentLanguage.data(), &szObjContentLanguage));
		ObjContentMD5.resize(szObjContentMD5);
		SBCheckError(SBGetLastReturnStringA(1552959855, 15, (char *)ObjContentMD5.data(), &szObjContentMD5));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1552959855, 16, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjContentLanguage.resize(szObjContentLanguage);
	ObjContentMD5.resize(szObjContentMD5);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageContainer::CopyObject(const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TElCustomDataStorageSecurityHandler &NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CopyObject(_Handle, SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), NewHandler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageContainer::CopyObject(const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TElCustomDataStorageSecurityHandler *NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CopyObject(_Handle, SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (NewHandler != NULL) ? NewHandler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageContainer::CopyObject(const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CopyObject_1(_Handle, SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageContainer::CopyObject(const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CopyObject_1(_Handle, SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageContainer::CopyObject(const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TElStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CopyObject_1(_Handle, SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageContainer::CopyObject(const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TElStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CopyObject_1(_Handle, SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageContainer::CopyObject(const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CopyObject_2(_Handle, SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageContainer::CopyObject(const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CopyObject_2(_Handle, SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageContainer::CopyObject(const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CopyObject_2(_Handle, SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageContainer::CopyObject(const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CopyObject_2(_Handle, SourceName.data(), (int32_t)SourceName.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageContainer::CopyObject(const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TElCustomDataStorageSecurityHandler &NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CopyObject_3(_Handle, SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), NewHandler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageContainer::CopyObject(const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TElCustomDataStorageSecurityHandler *NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CopyObject_3(_Handle, SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (NewHandler != NULL) ? NewHandler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageContainer::CopyObject(const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CopyObject_4(_Handle, SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageContainer::CopyObject(const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CopyObject_4(_Handle, SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageContainer::CopyObject(const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TElStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CopyObject_4(_Handle, SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageContainer::CopyObject(const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TElStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CopyObject_4(_Handle, SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageContainer::CopyObject(const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CopyObject_5(_Handle, SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageContainer::CopyObject(const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CopyObject_5(_Handle, SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageContainer::CopyObject(const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CopyObject_5(_Handle, SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElWinAzureDataStorageContainer::CopyObject(const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_CopyObject_5(_Handle, SourceName.data(), (int32_t)SourceName.length(), SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), DestContainerName.data(), (int32_t)DestContainerName.length(), DestName.data(), (int32_t)DestName.length(), DestSharedAccessSignature.data(), (int32_t)DestSharedAccessSignature.length(), (TSBWinAzureObjectAccessConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (TSBWinAzureObjectAccessConditionRaw)DestCondition, DestDateTime, DestETag.data(), (int32_t)DestETag.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

void TElWinAzureDataStorageContainer::GetObjectACL(const std::string &Name, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorageContainer_GetObjectACL(_Handle, Name.data(), (int32_t)Name.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1265298300, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWinAzureDataStorageContainer::SetObjectACL(const std::string &Name, const std::string &ACL)
{
	SBCheckError(TElWinAzureDataStorageContainer_SetObjectACL(_Handle, Name.data(), (int32_t)Name.length(), ACL.data(), (int32_t)ACL.length()));
}

void TElWinAzureDataStorageContainer::GetRemoteETag(const std::string &Name, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorageContainer_GetRemoteETag(_Handle, Name.data(), (int32_t)Name.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(76797302, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWinAzureDataStorageContainer::Delete()
{
	SBCheckError(TElWinAzureDataStorageContainer_Delete(_Handle));
}

SB_INLINE void TElWinAzureDataStorageContainer::Delete(const std::string &SharedAccessSignature)
{
	SBCheckError(TElWinAzureDataStorageContainer_Delete_1(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length()));
}

bool TElWinAzureDataStorageContainer::Exists()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorageContainer_Exists(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWinAzureDataStorageContainer::Exists(const std::string &SharedAccessSignature)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorageContainer_Exists_1(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELWINAZUREACCESSPOLICY
TSBWinAzureContainerAccessLevel TElWinAzureDataStorageContainer::GetACL(TElWinAzureAccessPolicy &Policy)
{
	TSBWinAzureContainerAccessLevelRaw OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorageContainer_GetACL(_Handle, Policy.getHandle(), &OutResultRaw));
	return (TSBWinAzureContainerAccessLevel)OutResultRaw;
}

TSBWinAzureContainerAccessLevel TElWinAzureDataStorageContainer::GetACL(TElWinAzureAccessPolicy *Policy)
{
	TSBWinAzureContainerAccessLevelRaw OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorageContainer_GetACL(_Handle, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBWinAzureContainerAccessLevel)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELWINAZUREACCESSPOLICY */

#ifdef SB_USE_CLASS_TELWINAZUREACCESSPOLICY
TSBWinAzureContainerAccessLevel TElWinAzureDataStorageContainer::GetACL(const std::string &SharedAccessSignature, TElWinAzureAccessPolicy &Policy)
{
	TSBWinAzureContainerAccessLevelRaw OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorageContainer_GetACL_1(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), Policy.getHandle(), &OutResultRaw));
	return (TSBWinAzureContainerAccessLevel)OutResultRaw;
}

TSBWinAzureContainerAccessLevel TElWinAzureDataStorageContainer::GetACL(const std::string &SharedAccessSignature, TElWinAzureAccessPolicy *Policy)
{
	TSBWinAzureContainerAccessLevelRaw OutResultRaw = 0;
	SBCheckError(TElWinAzureDataStorageContainer_GetACL_1(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBWinAzureContainerAccessLevel)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELWINAZUREACCESSPOLICY */

#ifdef SB_USE_CLASS_TELWINAZUREACCESSPOLICY
SB_INLINE void TElWinAzureDataStorageContainer::SetACL(TSBWinAzureContainerAccessLevel Level, TElWinAzureAccessPolicy &Policy)
{
	SBCheckError(TElWinAzureDataStorageContainer_SetACL(_Handle, (TSBWinAzureContainerAccessLevelRaw)Level, Policy.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::SetACL(TSBWinAzureContainerAccessLevel Level, TElWinAzureAccessPolicy *Policy)
{
	SBCheckError(TElWinAzureDataStorageContainer_SetACL(_Handle, (TSBWinAzureContainerAccessLevelRaw)Level, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWINAZUREACCESSPOLICY */

#ifdef SB_USE_CLASS_TELWINAZUREACCESSPOLICY
SB_INLINE void TElWinAzureDataStorageContainer::SetACL(const std::string &SharedAccessSignature, TSBWinAzureContainerAccessLevel Level, TElWinAzureAccessPolicy &Policy)
{
	SBCheckError(TElWinAzureDataStorageContainer_SetACL_1(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (TSBWinAzureContainerAccessLevelRaw)Level, Policy.getHandle()));
}

SB_INLINE void TElWinAzureDataStorageContainer::SetACL(const std::string &SharedAccessSignature, TSBWinAzureContainerAccessLevel Level, TElWinAzureAccessPolicy *Policy)
{
	SBCheckError(TElWinAzureDataStorageContainer_SetACL_1(_Handle, SharedAccessSignature.data(), (int32_t)SharedAccessSignature.length(), (TSBWinAzureContainerAccessLevelRaw)Level, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWINAZUREACCESSPOLICY */

#ifdef SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY
void TElWinAzureDataStorageContainer::CreateSharedAccessSignature(TElWinAzureSingleAccessPolicy &Policy, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorageContainer_CreateSharedAccessSignature(_Handle, Policy.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(404513250, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWinAzureDataStorageContainer::CreateSharedAccessSignature(TElWinAzureSingleAccessPolicy *Policy, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorageContainer_CreateSharedAccessSignature(_Handle, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(404513250, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY */

void TElWinAzureDataStorageContainer::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorageContainer_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(589433460, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWinAzureDataStorageContainer::get_Address(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorageContainer_get_Address(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1725004108, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElWinAzureDataStorageContainer::get_LastModified()
{
	int64_t OutResult;
	SBCheckError(TElWinAzureDataStorageContainer_get_LastModified(_Handle, &OutResult));
	return OutResult;
}

void TElWinAzureDataStorageContainer::get_ETag(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWinAzureDataStorageContainer_get_ETag(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1808235474, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElWinAzureDataStorageContainer::get_Metadata()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWinAzureDataStorageContainer_get_Metadata(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Metadata)
		this->_Inst_Metadata = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Metadata->updateHandle(hOutResult);
	return this->_Inst_Metadata;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElWinAzureDataStorageContainer::get_Metadata()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWinAzureDataStorageContainer_get_Metadata(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Metadata)
		this->_Inst_Metadata = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Metadata->updateHandle(hOutResult);
	return this->_Inst_Metadata;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElWinAzureDataStorageContainer::get_CustomHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWinAzureDataStorageContainer_get_CustomHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CustomHeaders)
		this->_Inst_CustomHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_CustomHeaders->updateHandle(hOutResult);
	return this->_Inst_CustomHeaders;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElWinAzureDataStorageContainer::get_CustomHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWinAzureDataStorageContainer_get_CustomHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CustomHeaders)
		this->_Inst_CustomHeaders = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_CustomHeaders->updateHandle(hOutResult);
	return this->_Inst_CustomHeaders;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElWinAzureDataStorageContainer::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Metadata = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Metadata = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_CustomHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_CustomHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElWinAzureDataStorageContainer::TElWinAzureDataStorageContainer(TElWinAzureDataStorageContainerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElWinAzureDataStorageContainer::TElWinAzureDataStorageContainer() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWinAzureDataStorageContainer_Create(&_Handle));
}

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGE
TElWinAzureDataStorageContainer::TElWinAzureDataStorageContainer(TElWinAzureDataStorage &Storage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWinAzureDataStorageContainer_Create_1(Storage.getHandle(), &_Handle));
}

TElWinAzureDataStorageContainer::TElWinAzureDataStorageContainer(TElWinAzureDataStorage *Storage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWinAzureDataStorageContainer_Create_1((Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGE */

TElWinAzureDataStorageContainer::~TElWinAzureDataStorageContainer()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Metadata;
	this->_Inst_Metadata = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Metadata;
	this->_Inst_Metadata = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_CustomHeaders;
	this->_Inst_CustomHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_CustomHeaders;
	this->_Inst_CustomHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINERLIST

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
TElWinAzureDataStorageContainer* TElWinAzureDataStorageContainerList::get_Containers(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWinAzureDataStorageContainerList_get_Containers(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Containers)
		this->_Inst_Containers = new TElWinAzureDataStorageContainer(hOutResult, ohFalse);
	else
		this->_Inst_Containers->updateHandle(hOutResult);
	return this->_Inst_Containers;
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

SB_INLINE int32_t TElWinAzureDataStorageContainerList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElWinAzureDataStorageContainerList_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElWinAzureDataStorageContainerList::initInstances()
{
#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
	this->_Inst_Containers = NULL;
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */
}

TElWinAzureDataStorageContainerList::TElWinAzureDataStorageContainerList(TElWinAzureDataStorageContainerListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElWinAzureDataStorageContainerList::TElWinAzureDataStorageContainerList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWinAzureDataStorageContainerList_Create(&_Handle));
}

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGE
TElWinAzureDataStorageContainerList::TElWinAzureDataStorageContainerList(TElWinAzureDataStorage &Storage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWinAzureDataStorageContainerList_Create_1(Storage.getHandle(), &_Handle));
}

TElWinAzureDataStorageContainerList::TElWinAzureDataStorageContainerList(TElWinAzureDataStorage *Storage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWinAzureDataStorageContainerList_Create_1((Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGE */

TElWinAzureDataStorageContainerList::~TElWinAzureDataStorageContainerList()
{
#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
	delete this->_Inst_Containers;
	this->_Inst_Containers = NULL;
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */
}
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINERLIST */

#ifdef SB_USE_GLOBAL_PROCS_WINAZUREDATASTORAGE

#ifdef SB_USE_CLASS_TELXMLDOMNODE
void SBWinAzureDataStorage_GetNodeInnerXML(TElXMLDOMNode &XmlNode, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWinAzureDataStorage_GetNodeInnerXML(XmlNode.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1042628118, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void SBWinAzureDataStorage_GetNodeInnerXML(TElXMLDOMNode *XmlNode, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWinAzureDataStorage_GetNodeInnerXML((XmlNode != NULL) ? XmlNode->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1042628118, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#endif /* SB_USE_GLOBAL_PROCS_WINAZUREDATASTORAGE */

};	/* namespace SecureBlackbox */
