#include "sbawsdatastorage.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGE

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT
SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::AcquireObject(const std::string &BucketName, const std::string &Key)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_AcquireObject(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::AcquireObject(const std::string &BucketName, const std::string &Key, TStringList &Headers)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_AcquireObject_1(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::AcquireObject(const std::string &BucketName, const std::string &Key, TStringList *Headers)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_AcquireObject_1(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST
SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::AcquireObject(const std::string &BucketName, const std::string &Key, TElStringList &Headers)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_AcquireObject_1(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::AcquireObject(const std::string &BucketName, const std::string &Key, TElStringList *Headers)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_AcquireObject_1(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELAWSS3DATASTORAGEOBJECT
SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::AcquireObject(TElAWSS3DataStorageBucket &Bucket, const std::string &Key)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_AcquireObject_2(_Handle, Bucket.getHandle(), Key.data(), (int32_t)Key.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::AcquireObject(TElAWSS3DataStorageBucket *Bucket, const std::string &Key)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_AcquireObject_2(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, Key.data(), (int32_t)Key.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElAWSS3DataStorage::List(const std::string &BucketName, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElAWSS3DataStorage_List(_Handle, BucketName.data(), (int32_t)BucketName.length(), Objects.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::List(const std::string &BucketName, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElAWSS3DataStorage_List(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::List(const std::string &BucketName, TElDataStorageObjectList &Objects, TStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_List_1(_Handle, BucketName.data(), (int32_t)BucketName.length(), Objects.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::List(const std::string &BucketName, TElDataStorageObjectList *Objects, TStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_List_1(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::List(const std::string &BucketName, TElDataStorageObjectList &Objects, TElStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_List_1(_Handle, BucketName.data(), (int32_t)BucketName.length(), Objects.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::List(const std::string &BucketName, TElDataStorageObjectList *Objects, TElStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_List_1(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElAWSS3DataStorage::List(TElAWSS3DataStorageBucket &Bucket, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElAWSS3DataStorage_List_2(_Handle, Bucket.getHandle(), Objects.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::List(TElAWSS3DataStorageBucket *Bucket, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElAWSS3DataStorage_List_2(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELDATASTORAGEOBJECTLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::List(const std::string &BucketName, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList &Prefixes, TStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_List_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Objects.getHandle(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, Prefixes.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::List(const std::string &BucketName, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList *Prefixes, TStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_List_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::List(const std::string &BucketName, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList &Prefixes, TElStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_List_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Objects.getHandle(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, Prefixes.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::List(const std::string &BucketName, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList *Prefixes, TElStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_List_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGELISTSTATE
SB_INLINE TElAWSS3DataStorageListStateHandle TElAWSS3DataStorage::ListInit(const std::string &BucketName)
{
	TElAWSS3DataStorageListStateHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_ListInit(_Handle, BucketName.data(), (int32_t)BucketName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGELISTSTATE */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TSTRINGLIST
SB_INLINE TElAWSS3DataStorageListStateHandle TElAWSS3DataStorage::ListInit(const std::string &BucketName, const std::string &Prefix, const std::string &Delimiter, TStringList &Prefixes, TStringList &Headers)
{
	TElAWSS3DataStorageListStateHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_ListInit_1(_Handle, BucketName.data(), (int32_t)BucketName.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), Prefixes.getHandle(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageListStateHandle TElAWSS3DataStorage::ListInit(const std::string &BucketName, const std::string &Prefix, const std::string &Delimiter, TStringList *Prefixes, TStringList *Headers)
{
	TElAWSS3DataStorageListStateHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_ListInit_1(_Handle, BucketName.data(), (int32_t)BucketName.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELSTRINGLIST
SB_INLINE TElAWSS3DataStorageListStateHandle TElAWSS3DataStorage::ListInit(const std::string &BucketName, const std::string &Prefix, const std::string &Delimiter, TElStringList &Prefixes, TElStringList &Headers)
{
	TElAWSS3DataStorageListStateHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_ListInit_1(_Handle, BucketName.data(), (int32_t)BucketName.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), Prefixes.getHandle(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageListStateHandle TElAWSS3DataStorage::ListInit(const std::string &BucketName, const std::string &Prefix, const std::string &Delimiter, TElStringList *Prefixes, TElStringList *Headers)
{
	TElAWSS3DataStorageListStateHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_ListInit_1(_Handle, BucketName.data(), (int32_t)BucketName.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElAWSS3DataStorage::ListNext(TElAWSS3DataStorageListState &State, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElAWSS3DataStorage_ListNext(_Handle, State.getHandle(), Objects.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::ListNext(TElAWSS3DataStorageListState *State, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElAWSS3DataStorage_ListNext(_Handle, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElAWSS3DataStorage::ListNext(TElAWSS3DataStorageListState &State, TElDataStorageObjectList &Objects, int32_t MaxCount)
{
	SBCheckError(TElAWSS3DataStorage_ListNext_1(_Handle, State.getHandle(), Objects.getHandle(), MaxCount));
}

SB_INLINE void TElAWSS3DataStorage::ListNext(TElAWSS3DataStorageListState *State, TElDataStorageObjectList *Objects, int32_t MaxCount)
{
	SBCheckError(TElAWSS3DataStorage_ListNext_1(_Handle, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, MaxCount));
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGELISTSTATE
void TElAWSS3DataStorage::ListFinal(TElAWSS3DataStorageListState &State)
{
	TElClassHandle hState = State.getHandle();
	SBCheckError(TElAWSS3DataStorage_ListFinal(_Handle, &hState));
	State.updateHandle(hState);
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT
SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::CreateObject(const std::string &BucketName, const std::string &ObjName)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateObject(_Handle, BucketName.data(), (int32_t)BucketName.length(), ObjName.data(), (int32_t)ObjName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELAWSS3DATASTORAGEOBJECT
SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::CreateObject(TElAWSS3DataStorageBucket &Bucket, const std::string &ObjName)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateObject_1(_Handle, Bucket.getHandle(), ObjName.data(), (int32_t)ObjName.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::CreateObject(TElAWSS3DataStorageBucket *Bucket, const std::string &ObjName)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateObject_1(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, ObjName.data(), (int32_t)ObjName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::CreateObject(const std::string &BucketName, const std::string &ObjName, TElCustomDataStorageSecurityHandler &Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateObject_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), ObjName.data(), (int32_t)ObjName.length(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::CreateObject(const std::string &BucketName, const std::string &ObjName, TElCustomDataStorageSecurityHandler *Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateObject_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), ObjName.data(), (int32_t)ObjName.length(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::CreateObject(TElAWSS3DataStorageBucket &Bucket, const std::string &ObjName, TElCustomDataStorageSecurityHandler &Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateObject_3(_Handle, Bucket.getHandle(), ObjName.data(), (int32_t)ObjName.length(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::CreateObject(TElAWSS3DataStorageBucket *Bucket, const std::string &ObjName, TElCustomDataStorageSecurityHandler *Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateObject_3(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, ObjName.data(), (int32_t)ObjName.length(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST
SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateObject_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateObject_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST
SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateObject_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateObject_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST
SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateObject_5(_Handle, BucketName.data(), (int32_t)BucketName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateObject_5(_Handle, BucketName.data(), (int32_t)BucketName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST
SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateObject_5(_Handle, BucketName.data(), (int32_t)BucketName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateObject_5(_Handle, BucketName.data(), (int32_t)BucketName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST
SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateObject_6(_Handle, BucketName.data(), (int32_t)BucketName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateObject_6(_Handle, BucketName.data(), (int32_t)BucketName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST
SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateObject_6(_Handle, BucketName.data(), (int32_t)BucketName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorage::CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateObject_6(_Handle, BucketName.data(), (int32_t)BucketName.length(), ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST */
#endif

SB_INLINE void TElAWSS3DataStorage::DeleteObject(const std::string &BucketName, const std::string &Key)
{
	SBCheckError(TElAWSS3DataStorage_DeleteObject(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length()));
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT
void TElAWSS3DataStorage::DeleteObject(TElAWSS3DataStorageObject &Obj)
{
	TElClassHandle hObj = Obj.getHandle();
	SBCheckError(TElAWSS3DataStorage_DeleteObject_1(_Handle, &hObj));
	Obj.updateHandle(hObj);
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::DeleteObject(const std::string &BucketName, const std::string &Key, TStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_DeleteObject_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::DeleteObject(const std::string &BucketName, const std::string &Key, TStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_DeleteObject_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::DeleteObject(const std::string &BucketName, const std::string &Key, TElStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_DeleteObject_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::DeleteObject(const std::string &BucketName, const std::string &Key, TElStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_DeleteObject_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

bool TElAWSS3DataStorage::ObjectExists(const std::string &BucketName, const std::string &Key)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_ObjectExists(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT
bool TElAWSS3DataStorage::ObjectExists(TElAWSS3DataStorageObject &Obj)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_ObjectExists_1(_Handle, Obj.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElAWSS3DataStorage::ObjectExists(TElAWSS3DataStorageObject *Obj)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_ObjectExists_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
bool TElAWSS3DataStorage::ObjectExists(const std::string &BucketName, const std::string &Key, TStringList &Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_ObjectExists_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Headers.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElAWSS3DataStorage::ObjectExists(const std::string &BucketName, const std::string &Key, TStringList *Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_ObjectExists_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
bool TElAWSS3DataStorage::ObjectExists(const std::string &BucketName, const std::string &Key, TElStringList &Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_ObjectExists_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Headers.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElAWSS3DataStorage::ObjectExists(const std::string &BucketName, const std::string &Key, TElStringList *Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_ObjectExists_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT
SB_INLINE void TElAWSS3DataStorage::RefreshObject(TElAWSS3DataStorageObject &Obj)
{
	SBCheckError(TElAWSS3DataStorage_RefreshObject(_Handle, Obj.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::RefreshObject(TElAWSS3DataStorageObject *Obj)
{
	SBCheckError(TElAWSS3DataStorage_RefreshObject(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::RefreshObject(TElAWSS3DataStorageObject &Obj, TStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_RefreshObject_1(_Handle, Obj.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::RefreshObject(TElAWSS3DataStorageObject *Obj, TStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_RefreshObject_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::RefreshObject(TElAWSS3DataStorageObject &Obj, TElStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_RefreshObject_1(_Handle, Obj.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::RefreshObject(TElAWSS3DataStorageObject *Obj, TElStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_RefreshObject_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElAWSS3DataStorage::WriteObject(const std::string &BucketName, const std::string &Key, TStream &Data, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Data.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::WriteObject(const std::string &BucketName, const std::string &Key, TStream *Data, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::WriteObject(const std::string &BucketName, const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_1(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::WriteObject(const std::string &BucketName, const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_1(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElAWSS3DataStorage::WriteObject(const std::string &BucketName, const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_1(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::WriteObject(const std::string &BucketName, const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_1(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::WriteObject(const std::string &BucketName, const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::WriteObject(const std::string &BucketName, const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElAWSS3DataStorage::WriteObject(const std::string &BucketName, const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::WriteObject(const std::string &BucketName, const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::WriteObject(const std::string &BucketName, const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::WriteObject(const std::string &BucketName, const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElAWSS3DataStorage::WriteObject(const std::string &BucketName, const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::WriteObject(const std::string &BucketName, const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
void TElAWSS3DataStorage::WriteObject(const std::string &BucketName, const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, std::string &NewETag)
{
	int32_t szNewETag = (int32_t)NewETag.length();
	uint32_t _err = TElAWSS3DataStorage_WriteObject_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle(), (char *)NewETag.data(), &szNewETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		NewETag.resize(szNewETag);
		SBCheckError(SBGetLastReturnStringA(530716965, 11, (char *)NewETag.data(), &szNewETag));
	}
	else
		SBCheckError(_err);

	NewETag.resize(szNewETag);
}

void TElAWSS3DataStorage::WriteObject(const std::string &BucketName, const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, std::string &NewETag)
{
	int32_t szNewETag = (int32_t)NewETag.length();
	uint32_t _err = TElAWSS3DataStorage_WriteObject_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, (char *)NewETag.data(), &szNewETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		NewETag.resize(szNewETag);
		SBCheckError(SBGetLastReturnStringA(530716965, 11, (char *)NewETag.data(), &szNewETag));
	}
	else
		SBCheckError(_err);

	NewETag.resize(szNewETag);
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
void TElAWSS3DataStorage::WriteObject(const std::string &BucketName, const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, std::string &NewETag)
{
	int32_t szNewETag = (int32_t)NewETag.length();
	uint32_t _err = TElAWSS3DataStorage_WriteObject_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle(), (char *)NewETag.data(), &szNewETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		NewETag.resize(szNewETag);
		SBCheckError(SBGetLastReturnStringA(-52087068, 11, (char *)NewETag.data(), &szNewETag));
	}
	else
		SBCheckError(_err);

	NewETag.resize(szNewETag);
}

void TElAWSS3DataStorage::WriteObject(const std::string &BucketName, const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, std::string &NewETag)
{
	int32_t szNewETag = (int32_t)NewETag.length();
	uint32_t _err = TElAWSS3DataStorage_WriteObject_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, (char *)NewETag.data(), &szNewETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		NewETag.resize(szNewETag);
		SBCheckError(SBGetLastReturnStringA(-52087068, 11, (char *)NewETag.data(), &szNewETag));
	}
	else
		SBCheckError(_err);

	NewETag.resize(szNewETag);
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::WriteObject(TElAWSS3DataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_5(_Handle, Obj.getHandle(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::WriteObject(TElAWSS3DataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_5(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElAWSS3DataStorage::WriteObject(TElAWSS3DataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_5(_Handle, Obj.getHandle(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::WriteObject(TElAWSS3DataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_5(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::WriteObject(TElAWSS3DataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_6(_Handle, Obj.getHandle(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::WriteObject(TElAWSS3DataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_6(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElAWSS3DataStorage::WriteObject(TElAWSS3DataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_6(_Handle, Obj.getHandle(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::WriteObject(TElAWSS3DataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_6(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::WriteObject(TElAWSS3DataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_7(_Handle, Obj.getHandle(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::WriteObject(TElAWSS3DataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_7(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElAWSS3DataStorage::WriteObject(TElAWSS3DataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_7(_Handle, Obj.getHandle(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Headers.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::WriteObject(TElAWSS3DataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorage_WriteObject_7(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElAWSS3DataStorage::ReadObject(const std::string &BucketName, const std::string &Key, TStream &Strm)
{
	SBCheckError(TElAWSS3DataStorage_ReadObject(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Strm.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::ReadObject(const std::string &BucketName, const std::string &Key, TStream *Strm)
{
	SBCheckError(TElAWSS3DataStorage_ReadObject(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElAWSS3DataStorage::ReadObject(const std::string &BucketName, const std::string &Key, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag)
{
	SBCheckError(TElAWSS3DataStorage_ReadObject_1(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Strm.getHandle(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length()));
}

SB_INLINE void TElAWSS3DataStorage::ReadObject(const std::string &BucketName, const std::string &Key, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag)
{
	SBCheckError(TElAWSS3DataStorage_ReadObject_1(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length()));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElAWSS3DataStorage::ReadObject(TElAWSS3DataStorageObject &Obj, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag)
{
	SBCheckError(TElAWSS3DataStorage_ReadObject_2(_Handle, Obj.getHandle(), Strm.getHandle(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length()));
}

SB_INLINE void TElAWSS3DataStorage::ReadObject(TElAWSS3DataStorageObject *Obj, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag)
{
	SBCheckError(TElAWSS3DataStorage_ReadObject_2(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length()));
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElAWSS3DataStorage::ReadObject(const std::string &BucketName, const std::string &Key, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadObject_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Strm.getHandle(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(206883784, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(206883784, 10, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(206883784, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorage::ReadObject(const std::string &BucketName, const std::string &Key, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadObject_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(206883784, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(206883784, 10, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(206883784, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElAWSS3DataStorage::ReadObject(const std::string &BucketName, const std::string &Key, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadObject_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Strm.getHandle(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1753820797, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(1753820797, 10, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1753820797, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorage::ReadObject(const std::string &BucketName, const std::string &Key, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadObject_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1753820797, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(1753820797, 10, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1753820797, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElAWSS3DataStorage::ReadObject(const std::string &BucketName, const std::string &Key, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadObject_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Strm.getHandle(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1638228073, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-1638228073, 10, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1638228073, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1638228073, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorage::ReadObject(const std::string &BucketName, const std::string &Key, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadObject_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1638228073, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-1638228073, 10, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1638228073, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1638228073, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElAWSS3DataStorage::ReadObject(const std::string &BucketName, const std::string &Key, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadObject_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Strm.getHandle(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-794524852, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-794524852, 10, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-794524852, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-794524852, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorage::ReadObject(const std::string &BucketName, const std::string &Key, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadObject_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-794524852, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-794524852, 10, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-794524852, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-794524852, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
void TElAWSS3DataStorage::ReadObject(TElAWSS3DataStorageObject &Obj, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadObject_5(_Handle, Obj.getHandle(), Strm.getHandle(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1684606921, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-1684606921, 9, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1684606921, 10, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorage::ReadObject(TElAWSS3DataStorageObject *Obj, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadObject_5(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1684606921, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-1684606921, 9, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1684606921, 10, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST_AND_TSTREAM
void TElAWSS3DataStorage::ReadObject(TElAWSS3DataStorageObject &Obj, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadObject_5(_Handle, Obj.getHandle(), Strm.getHandle(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(152408534, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(152408534, 9, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(152408534, 10, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorage::ReadObject(TElAWSS3DataStorageObject *Obj, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadObject_5(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(152408534, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(152408534, 9, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(152408534, 10, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
void TElAWSS3DataStorage::ReadObject(TElAWSS3DataStorageObject &Obj, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadObject_6(_Handle, Obj.getHandle(), Strm.getHandle(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1492720684, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-1492720684, 9, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1492720684, 10, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1492720684, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorage::ReadObject(TElAWSS3DataStorageObject *Obj, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadObject_6(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1492720684, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-1492720684, 9, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1492720684, 10, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1492720684, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST_AND_TSTREAM
void TElAWSS3DataStorage::ReadObject(TElAWSS3DataStorageObject &Obj, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadObject_6(_Handle, Obj.getHandle(), Strm.getHandle(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1306886139, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(1306886139, 9, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1306886139, 10, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1306886139, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorage::ReadObject(TElAWSS3DataStorageObject *Obj, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadObject_6(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1306886139, 8, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(1306886139, 9, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1306886139, 10, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1306886139, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElAWSS3DataStorage::ReadBlock(const std::string &BucketName, const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElAWSS3DataStorage_ReadBlock(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Strm.getHandle(), Offset, Size, &Read));
}

SB_INLINE void TElAWSS3DataStorage::ReadBlock(const std::string &BucketName, const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElAWSS3DataStorage_ReadBlock(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElAWSS3DataStorage::ReadBlock(const std::string &BucketName, const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag)
{
	SBCheckError(TElAWSS3DataStorage_ReadBlock_1(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Strm.getHandle(), Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length()));
}

SB_INLINE void TElAWSS3DataStorage::ReadBlock(const std::string &BucketName, const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag)
{
	SBCheckError(TElAWSS3DataStorage_ReadBlock_1(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length()));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElAWSS3DataStorage::ReadBlock(TElAWSS3DataStorageObject &Obj, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag)
{
	SBCheckError(TElAWSS3DataStorage_ReadBlock_2(_Handle, Obj.getHandle(), Strm.getHandle(), Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length()));
}

SB_INLINE void TElAWSS3DataStorage::ReadBlock(TElAWSS3DataStorageObject *Obj, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag)
{
	SBCheckError(TElAWSS3DataStorage_ReadBlock_2(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length()));
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElAWSS3DataStorage::ReadBlock(const std::string &BucketName, const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadBlock_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Strm.getHandle(), Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1319450842, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-1319450842, 13, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1319450842, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorage::ReadBlock(const std::string &BucketName, const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadBlock_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1319450842, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-1319450842, 13, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1319450842, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElAWSS3DataStorage::ReadBlock(const std::string &BucketName, const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadBlock_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Strm.getHandle(), Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(2086667181, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(2086667181, 13, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(2086667181, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorage::ReadBlock(const std::string &BucketName, const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadBlock_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(2086667181, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(2086667181, 13, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(2086667181, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElAWSS3DataStorage::ReadBlock(const std::string &BucketName, const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadBlock_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Strm.getHandle(), Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1947529052, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(1947529052, 13, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1947529052, 14, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1947529052, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorage::ReadBlock(const std::string &BucketName, const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadBlock_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1947529052, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(1947529052, 13, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1947529052, 14, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1947529052, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElAWSS3DataStorage::ReadBlock(const std::string &BucketName, const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadBlock_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Strm.getHandle(), Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(188541942, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(188541942, 13, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(188541942, 14, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(188541942, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorage::ReadBlock(const std::string &BucketName, const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadBlock_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(188541942, 12, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(188541942, 13, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(188541942, 14, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(188541942, 15, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
void TElAWSS3DataStorage::ReadBlock(TElAWSS3DataStorageObject &Obj, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadBlock_5(_Handle, Obj.getHandle(), Strm.getHandle(), Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-611486676, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-611486676, 12, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-611486676, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorage::ReadBlock(TElAWSS3DataStorageObject *Obj, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadBlock_5(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-611486676, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-611486676, 12, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-611486676, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST_AND_TSTREAM
void TElAWSS3DataStorage::ReadBlock(TElAWSS3DataStorageObject &Obj, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadBlock_5(_Handle, Obj.getHandle(), Strm.getHandle(), Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1210353634, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-1210353634, 12, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1210353634, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorage::ReadBlock(TElAWSS3DataStorageObject *Obj, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadBlock_5(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1210353634, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-1210353634, 12, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1210353634, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
void TElAWSS3DataStorage::ReadBlock(TElAWSS3DataStorageObject &Obj, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadBlock_6(_Handle, Obj.getHandle(), Strm.getHandle(), Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1036576927, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-1036576927, 12, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1036576927, 13, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1036576927, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorage::ReadBlock(TElAWSS3DataStorageObject *Obj, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadBlock_6(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1036576927, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-1036576927, 12, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1036576927, 13, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1036576927, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST_AND_TSTREAM
void TElAWSS3DataStorage::ReadBlock(TElAWSS3DataStorageObject &Obj, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadBlock_6(_Handle, Obj.getHandle(), Strm.getHandle(), Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), Headers.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(771852346, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(771852346, 12, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(771852346, 13, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(771852346, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorage::ReadBlock(TElAWSS3DataStorageObject *Obj, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorage_ReadBlock_6(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(771852346, 11, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(771852346, 12, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(771852346, 13, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(771852346, 14, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorage::CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TElCustomDataStorageSecurityHandler &NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CopyObject(_Handle, SourceBucketName.data(), (int32_t)SourceBucketName.length(), SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), NewHandler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorage::CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TElCustomDataStorageSecurityHandler *NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CopyObject(_Handle, SourceBucketName.data(), (int32_t)SourceBucketName.length(), SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (NewHandler != NULL) ? NewHandler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorage::CopyObject(TElAWSS3DataStorageObject &Obj, const std::string &DestBucketName, const std::string &DestKey, TElCustomDataStorageSecurityHandler &NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CopyObject_1(_Handle, Obj.getHandle(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), NewHandler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorage::CopyObject(TElAWSS3DataStorageObject *Obj, const std::string &DestBucketName, const std::string &DestKey, TElCustomDataStorageSecurityHandler *NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CopyObject_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (NewHandler != NULL) ? NewHandler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorage::CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CopyObject_2(_Handle, SourceBucketName.data(), (int32_t)SourceBucketName.length(), SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorage::CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CopyObject_2(_Handle, SourceBucketName.data(), (int32_t)SourceBucketName.length(), SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorage::CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TElStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CopyObject_2(_Handle, SourceBucketName.data(), (int32_t)SourceBucketName.length(), SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorage::CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TElStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CopyObject_2(_Handle, SourceBucketName.data(), (int32_t)SourceBucketName.length(), SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorage::CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TStringList &Metadata, TStringList &Headers)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CopyObject_3(_Handle, SourceBucketName.data(), (int32_t)SourceBucketName.length(), SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorage::CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TStringList *Metadata, TStringList *Headers)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CopyObject_3(_Handle, SourceBucketName.data(), (int32_t)SourceBucketName.length(), SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorage::CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TElStringList &Metadata, TElStringList &Headers)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CopyObject_3(_Handle, SourceBucketName.data(), (int32_t)SourceBucketName.length(), SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorage::CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TElStringList *Metadata, TElStringList *Headers)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CopyObject_3(_Handle, SourceBucketName.data(), (int32_t)SourceBucketName.length(), SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorage::CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TStringList &Metadata, TStringList &Headers)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CopyObject_4(_Handle, SourceBucketName.data(), (int32_t)SourceBucketName.length(), SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), StorageClass.data(), (int32_t)StorageClass.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorage::CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TStringList *Metadata, TStringList *Headers)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CopyObject_4(_Handle, SourceBucketName.data(), (int32_t)SourceBucketName.length(), SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), StorageClass.data(), (int32_t)StorageClass.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorage::CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TElStringList &Metadata, TElStringList &Headers)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CopyObject_4(_Handle, SourceBucketName.data(), (int32_t)SourceBucketName.length(), SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), StorageClass.data(), (int32_t)StorageClass.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorage::CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TElStringList *Metadata, TElStringList *Headers)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CopyObject_4(_Handle, SourceBucketName.data(), (int32_t)SourceBucketName.length(), SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), StorageClass.data(), (int32_t)StorageClass.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

void TElAWSS3DataStorage::GetObjectACL(const std::string &BucketName, const std::string &Key, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetObjectACL(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2055158354, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT
void TElAWSS3DataStorage::GetObjectACL(TElAWSS3DataStorageObject &Obj, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetObjectACL_1(_Handle, Obj.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(475682920, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorage::GetObjectACL(TElAWSS3DataStorageObject *Obj, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetObjectACL_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(475682920, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
void TElAWSS3DataStorage::GetObjectACL(const std::string &BucketName, const std::string &Key, TStringList &Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetObjectACL_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Headers.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(300585446, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorage::GetObjectACL(const std::string &BucketName, const std::string &Key, TStringList *Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetObjectACL_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(300585446, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
void TElAWSS3DataStorage::GetObjectACL(const std::string &BucketName, const std::string &Key, TElStringList &Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetObjectACL_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Headers.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1837593342, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorage::GetObjectACL(const std::string &BucketName, const std::string &Key, TElStringList *Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetObjectACL_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1837593342, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY
SB_INLINE void TElAWSS3DataStorage::GetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy &Policy)
{
	SBCheckError(TElAWSS3DataStorage_GetObjectACL_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Policy.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::GetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy *Policy)
{
	SBCheckError(TElAWSS3DataStorage_GetObjectACL_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY */

#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELAWSS3DATASTORAGEOBJECT
SB_INLINE void TElAWSS3DataStorage::GetObjectACL(TElAWSS3DataStorageObject &Obj, TElAWSS3AccessControlPolicy &Policy)
{
	SBCheckError(TElAWSS3DataStorage_GetObjectACL_4(_Handle, Obj.getHandle(), Policy.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::GetObjectACL(TElAWSS3DataStorageObject *Obj, TElAWSS3AccessControlPolicy *Policy)
{
	SBCheckError(TElAWSS3DataStorage_GetObjectACL_4(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::GetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy &Policy, TStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_GetObjectACL_5(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Policy.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::GetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy *Policy, TStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_GetObjectACL_5(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::GetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy &Policy, TElStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_GetObjectACL_5(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Policy.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::GetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy *Policy, TElStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_GetObjectACL_5(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELSTRINGLIST */
#endif

SB_INLINE void TElAWSS3DataStorage::SetObjectACL(const std::string &BucketName, const std::string &Key, const std::string &ACL)
{
	SBCheckError(TElAWSS3DataStorage_SetObjectACL(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), ACL.data(), (int32_t)ACL.length()));
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT
SB_INLINE void TElAWSS3DataStorage::SetObjectACL(TElAWSS3DataStorageObject &Obj, const std::string &ACL)
{
	SBCheckError(TElAWSS3DataStorage_SetObjectACL_1(_Handle, Obj.getHandle(), ACL.data(), (int32_t)ACL.length()));
}

SB_INLINE void TElAWSS3DataStorage::SetObjectACL(TElAWSS3DataStorageObject *Obj, const std::string &ACL)
{
	SBCheckError(TElAWSS3DataStorage_SetObjectACL_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, ACL.data(), (int32_t)ACL.length()));
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::SetObjectACL(const std::string &BucketName, const std::string &Key, const std::string &ACL, TStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetObjectACL_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), ACL.data(), (int32_t)ACL.length(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetObjectACL(const std::string &BucketName, const std::string &Key, const std::string &ACL, TStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetObjectACL_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), ACL.data(), (int32_t)ACL.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::SetObjectACL(const std::string &BucketName, const std::string &Key, const std::string &ACL, TElStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetObjectACL_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), ACL.data(), (int32_t)ACL.length(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetObjectACL(const std::string &BucketName, const std::string &Key, const std::string &ACL, TElStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetObjectACL_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), ACL.data(), (int32_t)ACL.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY
SB_INLINE void TElAWSS3DataStorage::SetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy &Policy)
{
	SBCheckError(TElAWSS3DataStorage_SetObjectACL_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Policy.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy *Policy)
{
	SBCheckError(TElAWSS3DataStorage_SetObjectACL_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY */

#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELAWSS3DATASTORAGEOBJECT
SB_INLINE void TElAWSS3DataStorage::SetObjectACL(TElAWSS3DataStorageObject &Obj, TElAWSS3AccessControlPolicy &Policy)
{
	SBCheckError(TElAWSS3DataStorage_SetObjectACL_4(_Handle, Obj.getHandle(), Policy.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetObjectACL(TElAWSS3DataStorageObject *Obj, TElAWSS3AccessControlPolicy *Policy)
{
	SBCheckError(TElAWSS3DataStorage_SetObjectACL_4(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::SetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy &Policy, TStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetObjectACL_5(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Policy.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy *Policy, TStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetObjectACL_5(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::SetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy &Policy, TElStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetObjectACL_5(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Policy.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy *Policy, TElStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetObjectACL_5(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TSTREAM
void TElAWSS3DataStorage::GetLocalETag(TStream &Stream, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetLocalETag(_Handle, Stream.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-494985657, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorage::GetLocalETag(TStream *Stream, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetLocalETag(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-494985657, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElAWSS3DataStorage::GetLocalETag(const std::string &Filename, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetLocalETag_1(_Handle, Filename.data(), (int32_t)Filename.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1944342101, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorage::GetRemoteETag(const std::string &BucketName, const std::string &Key, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetRemoteETag(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(901340877, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT
void TElAWSS3DataStorage::GetRemoteETag(TElAWSS3DataStorageObject &Obj, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetRemoteETag_1(_Handle, Obj.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(23751074, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorage::GetRemoteETag(TElAWSS3DataStorageObject *Obj, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetRemoteETag_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(23751074, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
void TElAWSS3DataStorage::GetRemoteETag(const std::string &BucketName, const std::string &Key, TStringList &Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetRemoteETag_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Headers.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1754411105, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorage::GetRemoteETag(const std::string &BucketName, const std::string &Key, TStringList *Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetRemoteETag_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1754411105, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
void TElAWSS3DataStorage::GetRemoteETag(const std::string &BucketName, const std::string &Key, TElStringList &Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetRemoteETag_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Headers.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1198221704, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorage::GetRemoteETag(const std::string &BucketName, const std::string &Key, TElStringList *Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetRemoteETag_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1198221704, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElAWSS3DataStorage::GetObjectTorrent(const std::string &BucketName, const std::string &Key, TStream &Stream)
{
	SBCheckError(TElAWSS3DataStorage_GetObjectTorrent(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Stream.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::GetObjectTorrent(const std::string &BucketName, const std::string &Key, TStream *Stream)
{
	SBCheckError(TElAWSS3DataStorage_GetObjectTorrent(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElAWSS3DataStorage::GetObjectTorrent(TElAWSS3DataStorageObject &Obj, TStream &Stream)
{
	SBCheckError(TElAWSS3DataStorage_GetObjectTorrent_1(_Handle, Obj.getHandle(), Stream.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::GetObjectTorrent(TElAWSS3DataStorageObject *Obj, TStream *Stream)
{
	SBCheckError(TElAWSS3DataStorage_GetObjectTorrent_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::GetObjectTorrent(const std::string &BucketName, const std::string &Key, TStringList &Headers, TStream &Stream)
{
	SBCheckError(TElAWSS3DataStorage_GetObjectTorrent_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Headers.getHandle(), Stream.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::GetObjectTorrent(const std::string &BucketName, const std::string &Key, TStringList *Headers, TStream *Stream)
{
	SBCheckError(TElAWSS3DataStorage_GetObjectTorrent_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElAWSS3DataStorage::GetObjectTorrent(const std::string &BucketName, const std::string &Key, TElStringList &Headers, TStream &Stream)
{
	SBCheckError(TElAWSS3DataStorage_GetObjectTorrent_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), Headers.getHandle(), Stream.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::GetObjectTorrent(const std::string &BucketName, const std::string &Key, TElStringList *Headers, TStream *Stream)
{
	SBCheckError(TElAWSS3DataStorage_GetObjectTorrent_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
SB_INLINE TElAWSS3DataStorageBucketHandle TElAWSS3DataStorage::AcquireBucket(const std::string &BucketName)
{
	TElAWSS3DataStorageBucketHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_AcquireBucket(_Handle, BucketName.data(), (int32_t)BucketName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
void TElAWSS3DataStorage::ReleaseBucket(TElAWSS3DataStorageBucket &Bucket)
{
	TElClassHandle hBucket = Bucket.getHandle();
	SBCheckError(TElAWSS3DataStorage_ReleaseBucket(_Handle, &hBucket));
	Bucket.updateHandle(hBucket);
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
SB_INLINE TElAWSS3DataStorageBucketHandle TElAWSS3DataStorage::CreateBucket(const std::string &BucketName)
{
	TElAWSS3DataStorageBucketHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateBucket(_Handle, BucketName.data(), (int32_t)BucketName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
SB_INLINE TElAWSS3DataStorageBucketHandle TElAWSS3DataStorage::CreateBucket(const std::string &BucketName, const std::string &Location)
{
	TElAWSS3DataStorageBucketHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateBucket_1(_Handle, BucketName.data(), (int32_t)BucketName.length(), Location.data(), (int32_t)Location.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
SB_INLINE TElAWSS3DataStorageBucketHandle TElAWSS3DataStorage::CreateBucket(const std::string &BucketName, const std::string &Location, const std::string &ACL)
{
	TElAWSS3DataStorageBucketHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateBucket_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Location.data(), (int32_t)Location.length(), ACL.data(), (int32_t)ACL.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TSTRINGLIST
SB_INLINE TElAWSS3DataStorageBucketHandle TElAWSS3DataStorage::CreateBucket(const std::string &BucketName, const std::string &Location, TStringList &Headers)
{
	TElAWSS3DataStorageBucketHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateBucket_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Location.data(), (int32_t)Location.length(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageBucketHandle TElAWSS3DataStorage::CreateBucket(const std::string &BucketName, const std::string &Location, TStringList *Headers)
{
	TElAWSS3DataStorageBucketHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateBucket_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Location.data(), (int32_t)Location.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELSTRINGLIST
SB_INLINE TElAWSS3DataStorageBucketHandle TElAWSS3DataStorage::CreateBucket(const std::string &BucketName, const std::string &Location, TElStringList &Headers)
{
	TElAWSS3DataStorageBucketHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateBucket_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Location.data(), (int32_t)Location.length(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageBucketHandle TElAWSS3DataStorage::CreateBucket(const std::string &BucketName, const std::string &Location, TElStringList *Headers)
{
	TElAWSS3DataStorageBucketHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateBucket_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Location.data(), (int32_t)Location.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TSTRINGLIST
SB_INLINE TElAWSS3DataStorageBucketHandle TElAWSS3DataStorage::CreateBucket(const std::string &BucketName, const std::string &Location, const std::string &ACL, TStringList &Headers)
{
	TElAWSS3DataStorageBucketHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateBucket_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), Location.data(), (int32_t)Location.length(), ACL.data(), (int32_t)ACL.length(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageBucketHandle TElAWSS3DataStorage::CreateBucket(const std::string &BucketName, const std::string &Location, const std::string &ACL, TStringList *Headers)
{
	TElAWSS3DataStorageBucketHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateBucket_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), Location.data(), (int32_t)Location.length(), ACL.data(), (int32_t)ACL.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELSTRINGLIST
SB_INLINE TElAWSS3DataStorageBucketHandle TElAWSS3DataStorage::CreateBucket(const std::string &BucketName, const std::string &Location, const std::string &ACL, TElStringList &Headers)
{
	TElAWSS3DataStorageBucketHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateBucket_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), Location.data(), (int32_t)Location.length(), ACL.data(), (int32_t)ACL.length(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageBucketHandle TElAWSS3DataStorage::CreateBucket(const std::string &BucketName, const std::string &Location, const std::string &ACL, TElStringList *Headers)
{
	TElAWSS3DataStorageBucketHandle OutResult;
	SBCheckError(TElAWSS3DataStorage_CreateBucket_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), Location.data(), (int32_t)Location.length(), ACL.data(), (int32_t)ACL.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELSTRINGLIST */
#endif

SB_INLINE void TElAWSS3DataStorage::DeleteBucket(const std::string &BucketName)
{
	SBCheckError(TElAWSS3DataStorage_DeleteBucket(_Handle, BucketName.data(), (int32_t)BucketName.length()));
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
void TElAWSS3DataStorage::DeleteBucket(TElAWSS3DataStorageBucket &Bucket)
{
	TElClassHandle hBucket = Bucket.getHandle();
	SBCheckError(TElAWSS3DataStorage_DeleteBucket_1(_Handle, &hBucket));
	Bucket.updateHandle(hBucket);
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::DeleteBucket(const std::string &BucketName, TStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_DeleteBucket_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::DeleteBucket(const std::string &BucketName, TStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_DeleteBucket_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::DeleteBucket(const std::string &BucketName, TElStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_DeleteBucket_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::DeleteBucket(const std::string &BucketName, TElStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_DeleteBucket_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

bool TElAWSS3DataStorage::BucketExists(const std::string &BucketName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_BucketExists(_Handle, BucketName.data(), (int32_t)BucketName.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
bool TElAWSS3DataStorage::BucketExists(TElAWSS3DataStorageBucket &Bucket)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_BucketExists_1(_Handle, Bucket.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElAWSS3DataStorage::BucketExists(TElAWSS3DataStorageBucket *Bucket)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_BucketExists_1(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
bool TElAWSS3DataStorage::BucketExists(const std::string &BucketName, TStringList &Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_BucketExists_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Headers.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElAWSS3DataStorage::BucketExists(const std::string &BucketName, TStringList *Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_BucketExists_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
bool TElAWSS3DataStorage::BucketExists(const std::string &BucketName, TElStringList &Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_BucketExists_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Headers.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElAWSS3DataStorage::BucketExists(const std::string &BucketName, TElStringList *Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_BucketExists_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElAWSS3DataStorage::GetBucketLocation(const std::string &BucketName, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketLocation(_Handle, BucketName.data(), (int32_t)BucketName.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1377544022, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
void TElAWSS3DataStorage::GetBucketLocation(TElAWSS3DataStorageBucket &Bucket, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketLocation_1(_Handle, Bucket.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-74177289, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorage::GetBucketLocation(TElAWSS3DataStorageBucket *Bucket, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketLocation_1(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-74177289, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
void TElAWSS3DataStorage::GetBucketLocation(const std::string &BucketName, TStringList &Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketLocation_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Headers.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(318667035, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorage::GetBucketLocation(const std::string &BucketName, TStringList *Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketLocation_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(318667035, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
void TElAWSS3DataStorage::GetBucketLocation(const std::string &BucketName, TElStringList &Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketLocation_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Headers.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1648657492, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorage::GetBucketLocation(const std::string &BucketName, TElStringList *Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketLocation_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1648657492, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElAWSS3DataStorage::GetBucketACL(const std::string &BucketName, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketACL(_Handle, BucketName.data(), (int32_t)BucketName.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-145215488, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
void TElAWSS3DataStorage::GetBucketACL(TElAWSS3DataStorageBucket &Bucket, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketACL_1(_Handle, Bucket.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(938038036, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorage::GetBucketACL(TElAWSS3DataStorageBucket *Bucket, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketACL_1(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(938038036, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
void TElAWSS3DataStorage::GetBucketACL(const std::string &BucketName, TStringList &Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketACL_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Headers.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-366339808, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorage::GetBucketACL(const std::string &BucketName, TStringList *Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketACL_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-366339808, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
void TElAWSS3DataStorage::GetBucketACL(const std::string &BucketName, TElStringList &Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketACL_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Headers.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-323285736, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorage::GetBucketACL(const std::string &BucketName, TElStringList *Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketACL_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-323285736, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY
SB_INLINE void TElAWSS3DataStorage::GetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy &Policy)
{
	SBCheckError(TElAWSS3DataStorage_GetBucketACL_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Policy.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::GetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy *Policy)
{
	SBCheckError(TElAWSS3DataStorage_GetBucketACL_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY */

#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELAWSS3DATASTORAGEBUCKET
SB_INLINE void TElAWSS3DataStorage::GetBucketACL(TElAWSS3DataStorageBucket &Bucket, TElAWSS3AccessControlPolicy &Policy)
{
	SBCheckError(TElAWSS3DataStorage_GetBucketACL_4(_Handle, Bucket.getHandle(), Policy.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::GetBucketACL(TElAWSS3DataStorageBucket *Bucket, TElAWSS3AccessControlPolicy *Policy)
{
	SBCheckError(TElAWSS3DataStorage_GetBucketACL_4(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::GetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy &Policy, TStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_GetBucketACL_5(_Handle, BucketName.data(), (int32_t)BucketName.length(), Policy.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::GetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy *Policy, TStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_GetBucketACL_5(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::GetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy &Policy, TElStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_GetBucketACL_5(_Handle, BucketName.data(), (int32_t)BucketName.length(), Policy.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::GetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy *Policy, TElStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_GetBucketACL_5(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELSTRINGLIST */
#endif

SB_INLINE void TElAWSS3DataStorage::SetBucketACL(const std::string &BucketName, const std::string &ACL)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketACL(_Handle, BucketName.data(), (int32_t)BucketName.length(), ACL.data(), (int32_t)ACL.length()));
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
SB_INLINE void TElAWSS3DataStorage::SetBucketACL(TElAWSS3DataStorageBucket &Bucket, const std::string &ACL)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketACL_1(_Handle, Bucket.getHandle(), ACL.data(), (int32_t)ACL.length()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketACL(TElAWSS3DataStorageBucket *Bucket, const std::string &ACL)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketACL_1(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, ACL.data(), (int32_t)ACL.length()));
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::SetBucketACL(const std::string &BucketName, const std::string &ACL, TStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketACL_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), ACL.data(), (int32_t)ACL.length(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketACL(const std::string &BucketName, const std::string &ACL, TStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketACL_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), ACL.data(), (int32_t)ACL.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::SetBucketACL(const std::string &BucketName, const std::string &ACL, TElStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketACL_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), ACL.data(), (int32_t)ACL.length(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketACL(const std::string &BucketName, const std::string &ACL, TElStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketACL_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), ACL.data(), (int32_t)ACL.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY
SB_INLINE void TElAWSS3DataStorage::SetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy &Policy)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketACL_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), Policy.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy *Policy)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketACL_3(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY */

#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELAWSS3DATASTORAGEBUCKET
SB_INLINE void TElAWSS3DataStorage::SetBucketACL(TElAWSS3DataStorageBucket &Bucket, TElAWSS3AccessControlPolicy &Policy)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketACL_4(_Handle, Bucket.getHandle(), Policy.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketACL(TElAWSS3DataStorageBucket *Bucket, TElAWSS3AccessControlPolicy *Policy)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketACL_4(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::SetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy &Policy, TStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketACL_5(_Handle, BucketName.data(), (int32_t)BucketName.length(), Policy.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy *Policy, TStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketACL_5(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::SetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy &Policy, TElStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketACL_5(_Handle, BucketName.data(), (int32_t)BucketName.length(), Policy.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy *Policy, TElStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketACL_5(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELSTRINGLIST */
#endif

void TElAWSS3DataStorage::GetBucketPolicy(const std::string &BucketName, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketPolicy(_Handle, BucketName.data(), (int32_t)BucketName.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1401384711, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
void TElAWSS3DataStorage::GetBucketPolicy(TElAWSS3DataStorageBucket &Bucket, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketPolicy_1(_Handle, Bucket.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(672623441, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorage::GetBucketPolicy(TElAWSS3DataStorageBucket *Bucket, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketPolicy_1(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(672623441, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
void TElAWSS3DataStorage::GetBucketPolicy(const std::string &BucketName, TStringList &Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketPolicy_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Headers.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1655103081, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorage::GetBucketPolicy(const std::string &BucketName, TStringList *Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketPolicy_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1655103081, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
void TElAWSS3DataStorage::GetBucketPolicy(const std::string &BucketName, TElStringList &Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketPolicy_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Headers.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-939514165, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorage::GetBucketPolicy(const std::string &BucketName, TElStringList *Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketPolicy_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-939514165, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

SB_INLINE void TElAWSS3DataStorage::SetBucketPolicy(const std::string &BucketName, const std::string &Policy)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketPolicy(_Handle, BucketName.data(), (int32_t)BucketName.length(), Policy.data(), (int32_t)Policy.length()));
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
SB_INLINE void TElAWSS3DataStorage::SetBucketPolicy(TElAWSS3DataStorageBucket &Bucket, const std::string &Policy)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketPolicy_1(_Handle, Bucket.getHandle(), Policy.data(), (int32_t)Policy.length()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketPolicy(TElAWSS3DataStorageBucket *Bucket, const std::string &Policy)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketPolicy_1(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, Policy.data(), (int32_t)Policy.length()));
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::SetBucketPolicy(const std::string &BucketName, const std::string &Policy, TStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketPolicy_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Policy.data(), (int32_t)Policy.length(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketPolicy(const std::string &BucketName, const std::string &Policy, TStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketPolicy_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Policy.data(), (int32_t)Policy.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::SetBucketPolicy(const std::string &BucketName, const std::string &Policy, TElStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketPolicy_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Policy.data(), (int32_t)Policy.length(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketPolicy(const std::string &BucketName, const std::string &Policy, TElStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketPolicy_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Policy.data(), (int32_t)Policy.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

SB_INLINE void TElAWSS3DataStorage::DeleteBucketPolicy(const std::string &BucketName)
{
	SBCheckError(TElAWSS3DataStorage_DeleteBucketPolicy(_Handle, BucketName.data(), (int32_t)BucketName.length()));
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
SB_INLINE void TElAWSS3DataStorage::DeleteBucketPolicy(TElAWSS3DataStorageBucket &Bucket)
{
	SBCheckError(TElAWSS3DataStorage_DeleteBucketPolicy_1(_Handle, Bucket.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::DeleteBucketPolicy(TElAWSS3DataStorageBucket *Bucket)
{
	SBCheckError(TElAWSS3DataStorage_DeleteBucketPolicy_1(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::DeleteBucketPolicy(const std::string &BucketName, TStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_DeleteBucketPolicy_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::DeleteBucketPolicy(const std::string &BucketName, TStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_DeleteBucketPolicy_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::DeleteBucketPolicy(const std::string &BucketName, TElStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_DeleteBucketPolicy_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::DeleteBucketPolicy(const std::string &BucketName, TElStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_DeleteBucketPolicy_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

SB_INLINE void TElAWSS3DataStorage::SetBucketPaymentConfiguration(const std::string &BucketName, const std::string &PaymentConfig)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketPaymentConfiguration(_Handle, BucketName.data(), (int32_t)BucketName.length(), PaymentConfig.data(), (int32_t)PaymentConfig.length()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketPaymentConfiguration(const std::string &BucketName, bool RequesterPays)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketPaymentConfiguration_1(_Handle, BucketName.data(), (int32_t)BucketName.length(), (int8_t)RequesterPays));
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
SB_INLINE void TElAWSS3DataStorage::SetBucketPaymentConfiguration(TElAWSS3DataStorageBucket &Bucket, const std::string &PaymentConfig)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketPaymentConfiguration_2(_Handle, Bucket.getHandle(), PaymentConfig.data(), (int32_t)PaymentConfig.length()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketPaymentConfiguration(TElAWSS3DataStorageBucket *Bucket, const std::string &PaymentConfig)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketPaymentConfiguration_2(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, PaymentConfig.data(), (int32_t)PaymentConfig.length()));
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
SB_INLINE void TElAWSS3DataStorage::SetBucketPaymentConfiguration(TElAWSS3DataStorageBucket &Bucket, bool RequesterPays)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketPaymentConfiguration_3(_Handle, Bucket.getHandle(), (int8_t)RequesterPays));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketPaymentConfiguration(TElAWSS3DataStorageBucket *Bucket, bool RequesterPays)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketPaymentConfiguration_3(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, (int8_t)RequesterPays));
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::SetBucketPaymentConfiguration(const std::string &BucketName, const std::string &PaymentConfig, TStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketPaymentConfiguration_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), PaymentConfig.data(), (int32_t)PaymentConfig.length(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketPaymentConfiguration(const std::string &BucketName, const std::string &PaymentConfig, TStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketPaymentConfiguration_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), PaymentConfig.data(), (int32_t)PaymentConfig.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::SetBucketPaymentConfiguration(const std::string &BucketName, const std::string &PaymentConfig, TElStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketPaymentConfiguration_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), PaymentConfig.data(), (int32_t)PaymentConfig.length(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketPaymentConfiguration(const std::string &BucketName, const std::string &PaymentConfig, TElStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketPaymentConfiguration_4(_Handle, BucketName.data(), (int32_t)BucketName.length(), PaymentConfig.data(), (int32_t)PaymentConfig.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElAWSS3DataStorage::GetBucketPaymentConfiguration(const std::string &BucketName, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketPaymentConfiguration(_Handle, BucketName.data(), (int32_t)BucketName.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(301626485, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
void TElAWSS3DataStorage::GetBucketPaymentConfiguration(TElAWSS3DataStorageBucket &Bucket, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketPaymentConfiguration_1(_Handle, Bucket.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1899548040, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorage::GetBucketPaymentConfiguration(TElAWSS3DataStorageBucket *Bucket, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketPaymentConfiguration_1(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1899548040, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
void TElAWSS3DataStorage::GetBucketPaymentConfiguration(const std::string &BucketName, TStringList &Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketPaymentConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Headers.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-724326620, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorage::GetBucketPaymentConfiguration(const std::string &BucketName, TStringList *Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketPaymentConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-724326620, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
void TElAWSS3DataStorage::GetBucketPaymentConfiguration(const std::string &BucketName, TElStringList &Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketPaymentConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Headers.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1542559634, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorage::GetBucketPaymentConfiguration(const std::string &BucketName, TElStringList *Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketPaymentConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1542559634, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

bool TElAWSS3DataStorage::IsRequesterPaysBucket(const std::string &BucketName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_IsRequesterPaysBucket(_Handle, BucketName.data(), (int32_t)BucketName.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
bool TElAWSS3DataStorage::IsRequesterPaysBucket(TElAWSS3DataStorageBucket &Bucket)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_IsRequesterPaysBucket_1(_Handle, Bucket.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElAWSS3DataStorage::IsRequesterPaysBucket(TElAWSS3DataStorageBucket *Bucket)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_IsRequesterPaysBucket_1(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
bool TElAWSS3DataStorage::IsRequesterPaysBucket(const std::string &BucketName, TStringList &Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_IsRequesterPaysBucket_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Headers.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElAWSS3DataStorage::IsRequesterPaysBucket(const std::string &BucketName, TStringList *Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_IsRequesterPaysBucket_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
bool TElAWSS3DataStorage::IsRequesterPaysBucket(const std::string &BucketName, TElStringList &Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_IsRequesterPaysBucket_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Headers.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElAWSS3DataStorage::IsRequesterPaysBucket(const std::string &BucketName, TElStringList *Headers)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_IsRequesterPaysBucket_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

TSBAWSS3BucketVersioning TElAWSS3DataStorage::GetBucketVersioning(const std::string &BucketName)
{
	TSBAWSS3BucketVersioningRaw OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_GetBucketVersioning(_Handle, BucketName.data(), (int32_t)BucketName.length(), &OutResultRaw));
	return (TSBAWSS3BucketVersioning)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
TSBAWSS3BucketVersioning TElAWSS3DataStorage::GetBucketVersioning(TElAWSS3DataStorageBucket &Bucket)
{
	TSBAWSS3BucketVersioningRaw OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_GetBucketVersioning_1(_Handle, Bucket.getHandle(), &OutResultRaw));
	return (TSBAWSS3BucketVersioning)OutResultRaw;
}

TSBAWSS3BucketVersioning TElAWSS3DataStorage::GetBucketVersioning(TElAWSS3DataStorageBucket *Bucket)
{
	TSBAWSS3BucketVersioningRaw OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_GetBucketVersioning_1(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBAWSS3BucketVersioning)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TSBAWSS3BucketVersioning TElAWSS3DataStorage::GetBucketVersioning(const std::string &BucketName, TStringList &Headers)
{
	TSBAWSS3BucketVersioningRaw OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_GetBucketVersioning_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Headers.getHandle(), &OutResultRaw));
	return (TSBAWSS3BucketVersioning)OutResultRaw;
}

TSBAWSS3BucketVersioning TElAWSS3DataStorage::GetBucketVersioning(const std::string &BucketName, TStringList *Headers)
{
	TSBAWSS3BucketVersioningRaw OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_GetBucketVersioning_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBAWSS3BucketVersioning)OutResultRaw;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TSBAWSS3BucketVersioning TElAWSS3DataStorage::GetBucketVersioning(const std::string &BucketName, TElStringList &Headers)
{
	TSBAWSS3BucketVersioningRaw OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_GetBucketVersioning_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Headers.getHandle(), &OutResultRaw));
	return (TSBAWSS3BucketVersioning)OutResultRaw;
}

TSBAWSS3BucketVersioning TElAWSS3DataStorage::GetBucketVersioning(const std::string &BucketName, TElStringList *Headers)
{
	TSBAWSS3BucketVersioningRaw OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_GetBucketVersioning_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBAWSS3BucketVersioning)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

SB_INLINE void TElAWSS3DataStorage::SetBucketVersioning(const std::string &BucketName, TSBAWSS3BucketVersioning Value)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketVersioning(_Handle, BucketName.data(), (int32_t)BucketName.length(), (TSBAWSS3BucketVersioningRaw)Value));
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
SB_INLINE void TElAWSS3DataStorage::SetBucketVersioning(TElAWSS3DataStorageBucket &Bucket, TSBAWSS3BucketVersioning Value)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketVersioning_1(_Handle, Bucket.getHandle(), (TSBAWSS3BucketVersioningRaw)Value));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketVersioning(TElAWSS3DataStorageBucket *Bucket, TSBAWSS3BucketVersioning Value)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketVersioning_1(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, (TSBAWSS3BucketVersioningRaw)Value));
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::SetBucketVersioning(const std::string &BucketName, TSBAWSS3BucketVersioning Value, TStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketVersioning_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (TSBAWSS3BucketVersioningRaw)Value, Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketVersioning(const std::string &BucketName, TSBAWSS3BucketVersioning Value, TStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketVersioning_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (TSBAWSS3BucketVersioningRaw)Value, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::SetBucketVersioning(const std::string &BucketName, TSBAWSS3BucketVersioning Value, TElStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketVersioning_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (TSBAWSS3BucketVersioningRaw)Value, Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketVersioning(const std::string &BucketName, TSBAWSS3BucketVersioning Value, TElStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketVersioning_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (TSBAWSS3BucketVersioningRaw)Value, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::GetBucketNotificationConfiguration(const std::string &BucketName, TStringList &Topics, TStringList &Events)
{
	SBCheckError(TElAWSS3DataStorage_GetBucketNotificationConfiguration(_Handle, BucketName.data(), (int32_t)BucketName.length(), Topics.getHandle(), Events.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::GetBucketNotificationConfiguration(const std::string &BucketName, TStringList *Topics, TStringList *Events)
{
	SBCheckError(TElAWSS3DataStorage_GetBucketNotificationConfiguration(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Topics != NULL) ? Topics->getHandle() : SB_NULL_HANDLE, (Events != NULL) ? Events->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::GetBucketNotificationConfiguration(const std::string &BucketName, TElStringList &Topics, TElStringList &Events)
{
	SBCheckError(TElAWSS3DataStorage_GetBucketNotificationConfiguration(_Handle, BucketName.data(), (int32_t)BucketName.length(), Topics.getHandle(), Events.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::GetBucketNotificationConfiguration(const std::string &BucketName, TElStringList *Topics, TElStringList *Events)
{
	SBCheckError(TElAWSS3DataStorage_GetBucketNotificationConfiguration(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Topics != NULL) ? Topics->getHandle() : SB_NULL_HANDLE, (Events != NULL) ? Events->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::GetBucketNotificationConfiguration(TElAWSS3DataStorageBucket &Bucket, TStringList &Topics, TStringList &Events)
{
	SBCheckError(TElAWSS3DataStorage_GetBucketNotificationConfiguration_1(_Handle, Bucket.getHandle(), Topics.getHandle(), Events.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::GetBucketNotificationConfiguration(TElAWSS3DataStorageBucket *Bucket, TStringList *Topics, TStringList *Events)
{
	SBCheckError(TElAWSS3DataStorage_GetBucketNotificationConfiguration_1(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, (Topics != NULL) ? Topics->getHandle() : SB_NULL_HANDLE, (Events != NULL) ? Events->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::GetBucketNotificationConfiguration(TElAWSS3DataStorageBucket &Bucket, TElStringList &Topics, TElStringList &Events)
{
	SBCheckError(TElAWSS3DataStorage_GetBucketNotificationConfiguration_1(_Handle, Bucket.getHandle(), Topics.getHandle(), Events.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::GetBucketNotificationConfiguration(TElAWSS3DataStorageBucket *Bucket, TElStringList *Topics, TElStringList *Events)
{
	SBCheckError(TElAWSS3DataStorage_GetBucketNotificationConfiguration_1(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, (Topics != NULL) ? Topics->getHandle() : SB_NULL_HANDLE, (Events != NULL) ? Events->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::GetBucketNotificationConfiguration(const std::string &BucketName, TStringList &Topics, TStringList &Events, TStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_GetBucketNotificationConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Topics.getHandle(), Events.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::GetBucketNotificationConfiguration(const std::string &BucketName, TStringList *Topics, TStringList *Events, TStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_GetBucketNotificationConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Topics != NULL) ? Topics->getHandle() : SB_NULL_HANDLE, (Events != NULL) ? Events->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::GetBucketNotificationConfiguration(const std::string &BucketName, TElStringList &Topics, TElStringList &Events, TElStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_GetBucketNotificationConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Topics.getHandle(), Events.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::GetBucketNotificationConfiguration(const std::string &BucketName, TElStringList *Topics, TElStringList *Events, TElStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_GetBucketNotificationConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Topics != NULL) ? Topics->getHandle() : SB_NULL_HANDLE, (Events != NULL) ? Events->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::SetBucketNotificationConfiguration(const std::string &BucketName, TStringList &Topics, TStringList &Events)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketNotificationConfiguration(_Handle, BucketName.data(), (int32_t)BucketName.length(), Topics.getHandle(), Events.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketNotificationConfiguration(const std::string &BucketName, TStringList *Topics, TStringList *Events)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketNotificationConfiguration(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Topics != NULL) ? Topics->getHandle() : SB_NULL_HANDLE, (Events != NULL) ? Events->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::SetBucketNotificationConfiguration(const std::string &BucketName, TElStringList &Topics, TElStringList &Events)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketNotificationConfiguration(_Handle, BucketName.data(), (int32_t)BucketName.length(), Topics.getHandle(), Events.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketNotificationConfiguration(const std::string &BucketName, TElStringList *Topics, TElStringList *Events)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketNotificationConfiguration(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Topics != NULL) ? Topics->getHandle() : SB_NULL_HANDLE, (Events != NULL) ? Events->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::SetBucketNotificationConfiguration(TElAWSS3DataStorageBucket &Bucket, TStringList &Topics, TStringList &Events)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketNotificationConfiguration_1(_Handle, Bucket.getHandle(), Topics.getHandle(), Events.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketNotificationConfiguration(TElAWSS3DataStorageBucket *Bucket, TStringList *Topics, TStringList *Events)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketNotificationConfiguration_1(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, (Topics != NULL) ? Topics->getHandle() : SB_NULL_HANDLE, (Events != NULL) ? Events->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::SetBucketNotificationConfiguration(TElAWSS3DataStorageBucket &Bucket, TElStringList &Topics, TElStringList &Events)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketNotificationConfiguration_1(_Handle, Bucket.getHandle(), Topics.getHandle(), Events.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketNotificationConfiguration(TElAWSS3DataStorageBucket *Bucket, TElStringList *Topics, TElStringList *Events)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketNotificationConfiguration_1(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, (Topics != NULL) ? Topics->getHandle() : SB_NULL_HANDLE, (Events != NULL) ? Events->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::SetBucketNotificationConfiguration(const std::string &BucketName, TStringList &Topics, TStringList &Events, TStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketNotificationConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Topics.getHandle(), Events.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketNotificationConfiguration(const std::string &BucketName, TStringList *Topics, TStringList *Events, TStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketNotificationConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Topics != NULL) ? Topics->getHandle() : SB_NULL_HANDLE, (Events != NULL) ? Events->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::SetBucketNotificationConfiguration(const std::string &BucketName, TElStringList &Topics, TElStringList &Events, TElStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketNotificationConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Topics.getHandle(), Events.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketNotificationConfiguration(const std::string &BucketName, TElStringList *Topics, TElStringList *Events, TElStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketNotificationConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Topics != NULL) ? Topics->getHandle() : SB_NULL_HANDLE, (Events != NULL) ? Events->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElAWSS3DataStorage::GetBucketWebSiteConfiguration(const std::string &BucketName, std::string &IndexDocument, std::string &ErrorDocument)
{
	int32_t szIndexDocument = (int32_t)IndexDocument.length();
	int32_t szErrorDocument = (int32_t)ErrorDocument.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketWebSiteConfiguration(_Handle, BucketName.data(), (int32_t)BucketName.length(), (char *)IndexDocument.data(), &szIndexDocument, (char *)ErrorDocument.data(), &szErrorDocument);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		IndexDocument.resize(szIndexDocument);
		SBCheckError(SBGetLastReturnStringA(228582688, 2, (char *)IndexDocument.data(), &szIndexDocument));
		ErrorDocument.resize(szErrorDocument);
		SBCheckError(SBGetLastReturnStringA(228582688, 3, (char *)ErrorDocument.data(), &szErrorDocument));
	}
	else
		SBCheckError(_err);

	IndexDocument.resize(szIndexDocument);
	ErrorDocument.resize(szErrorDocument);
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
void TElAWSS3DataStorage::GetBucketWebSiteConfiguration(TElAWSS3DataStorageBucket &Bucket, std::string &IndexDocument, std::string &ErrorDocument)
{
	int32_t szIndexDocument = (int32_t)IndexDocument.length();
	int32_t szErrorDocument = (int32_t)ErrorDocument.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketWebSiteConfiguration_1(_Handle, Bucket.getHandle(), (char *)IndexDocument.data(), &szIndexDocument, (char *)ErrorDocument.data(), &szErrorDocument);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		IndexDocument.resize(szIndexDocument);
		SBCheckError(SBGetLastReturnStringA(-1536525938, 2, (char *)IndexDocument.data(), &szIndexDocument));
		ErrorDocument.resize(szErrorDocument);
		SBCheckError(SBGetLastReturnStringA(-1536525938, 3, (char *)ErrorDocument.data(), &szErrorDocument));
	}
	else
		SBCheckError(_err);

	IndexDocument.resize(szIndexDocument);
	ErrorDocument.resize(szErrorDocument);
}

void TElAWSS3DataStorage::GetBucketWebSiteConfiguration(TElAWSS3DataStorageBucket *Bucket, std::string &IndexDocument, std::string &ErrorDocument)
{
	int32_t szIndexDocument = (int32_t)IndexDocument.length();
	int32_t szErrorDocument = (int32_t)ErrorDocument.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketWebSiteConfiguration_1(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, (char *)IndexDocument.data(), &szIndexDocument, (char *)ErrorDocument.data(), &szErrorDocument);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		IndexDocument.resize(szIndexDocument);
		SBCheckError(SBGetLastReturnStringA(-1536525938, 2, (char *)IndexDocument.data(), &szIndexDocument));
		ErrorDocument.resize(szErrorDocument);
		SBCheckError(SBGetLastReturnStringA(-1536525938, 3, (char *)ErrorDocument.data(), &szErrorDocument));
	}
	else
		SBCheckError(_err);

	IndexDocument.resize(szIndexDocument);
	ErrorDocument.resize(szErrorDocument);
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
void TElAWSS3DataStorage::GetBucketWebSiteConfiguration(const std::string &BucketName, std::string &IndexDocument, std::string &ErrorDocument, TStringList &Headers)
{
	int32_t szIndexDocument = (int32_t)IndexDocument.length();
	int32_t szErrorDocument = (int32_t)ErrorDocument.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketWebSiteConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (char *)IndexDocument.data(), &szIndexDocument, (char *)ErrorDocument.data(), &szErrorDocument, Headers.getHandle());
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		IndexDocument.resize(szIndexDocument);
		SBCheckError(SBGetLastReturnStringA(-1987729931, 2, (char *)IndexDocument.data(), &szIndexDocument));
		ErrorDocument.resize(szErrorDocument);
		SBCheckError(SBGetLastReturnStringA(-1987729931, 3, (char *)ErrorDocument.data(), &szErrorDocument));
	}
	else
		SBCheckError(_err);

	IndexDocument.resize(szIndexDocument);
	ErrorDocument.resize(szErrorDocument);
}

void TElAWSS3DataStorage::GetBucketWebSiteConfiguration(const std::string &BucketName, std::string &IndexDocument, std::string &ErrorDocument, TStringList *Headers)
{
	int32_t szIndexDocument = (int32_t)IndexDocument.length();
	int32_t szErrorDocument = (int32_t)ErrorDocument.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketWebSiteConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (char *)IndexDocument.data(), &szIndexDocument, (char *)ErrorDocument.data(), &szErrorDocument, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		IndexDocument.resize(szIndexDocument);
		SBCheckError(SBGetLastReturnStringA(-1987729931, 2, (char *)IndexDocument.data(), &szIndexDocument));
		ErrorDocument.resize(szErrorDocument);
		SBCheckError(SBGetLastReturnStringA(-1987729931, 3, (char *)ErrorDocument.data(), &szErrorDocument));
	}
	else
		SBCheckError(_err);

	IndexDocument.resize(szIndexDocument);
	ErrorDocument.resize(szErrorDocument);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
void TElAWSS3DataStorage::GetBucketWebSiteConfiguration(const std::string &BucketName, std::string &IndexDocument, std::string &ErrorDocument, TElStringList &Headers)
{
	int32_t szIndexDocument = (int32_t)IndexDocument.length();
	int32_t szErrorDocument = (int32_t)ErrorDocument.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketWebSiteConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (char *)IndexDocument.data(), &szIndexDocument, (char *)ErrorDocument.data(), &szErrorDocument, Headers.getHandle());
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		IndexDocument.resize(szIndexDocument);
		SBCheckError(SBGetLastReturnStringA(-1530631711, 2, (char *)IndexDocument.data(), &szIndexDocument));
		ErrorDocument.resize(szErrorDocument);
		SBCheckError(SBGetLastReturnStringA(-1530631711, 3, (char *)ErrorDocument.data(), &szErrorDocument));
	}
	else
		SBCheckError(_err);

	IndexDocument.resize(szIndexDocument);
	ErrorDocument.resize(szErrorDocument);
}

void TElAWSS3DataStorage::GetBucketWebSiteConfiguration(const std::string &BucketName, std::string &IndexDocument, std::string &ErrorDocument, TElStringList *Headers)
{
	int32_t szIndexDocument = (int32_t)IndexDocument.length();
	int32_t szErrorDocument = (int32_t)ErrorDocument.length();
	uint32_t _err = TElAWSS3DataStorage_GetBucketWebSiteConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (char *)IndexDocument.data(), &szIndexDocument, (char *)ErrorDocument.data(), &szErrorDocument, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		IndexDocument.resize(szIndexDocument);
		SBCheckError(SBGetLastReturnStringA(-1530631711, 2, (char *)IndexDocument.data(), &szIndexDocument));
		ErrorDocument.resize(szErrorDocument);
		SBCheckError(SBGetLastReturnStringA(-1530631711, 3, (char *)ErrorDocument.data(), &szErrorDocument));
	}
	else
		SBCheckError(_err);

	IndexDocument.resize(szIndexDocument);
	ErrorDocument.resize(szErrorDocument);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

SB_INLINE void TElAWSS3DataStorage::SetBucketWebSiteConfiguration(const std::string &BucketName, const std::string &IndexDocument, const std::string &ErrorDocument)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketWebSiteConfiguration(_Handle, BucketName.data(), (int32_t)BucketName.length(), IndexDocument.data(), (int32_t)IndexDocument.length(), ErrorDocument.data(), (int32_t)ErrorDocument.length()));
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
SB_INLINE void TElAWSS3DataStorage::SetBucketWebSiteConfiguration(TElAWSS3DataStorageBucket &Bucket, const std::string &IndexDocument, const std::string &ErrorDocument)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketWebSiteConfiguration_1(_Handle, Bucket.getHandle(), IndexDocument.data(), (int32_t)IndexDocument.length(), ErrorDocument.data(), (int32_t)ErrorDocument.length()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketWebSiteConfiguration(TElAWSS3DataStorageBucket *Bucket, const std::string &IndexDocument, const std::string &ErrorDocument)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketWebSiteConfiguration_1(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE, IndexDocument.data(), (int32_t)IndexDocument.length(), ErrorDocument.data(), (int32_t)ErrorDocument.length()));
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::SetBucketWebSiteConfiguration(const std::string &BucketName, const std::string &IndexDocument, const std::string &ErrorDocument, TStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketWebSiteConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), IndexDocument.data(), (int32_t)IndexDocument.length(), ErrorDocument.data(), (int32_t)ErrorDocument.length(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketWebSiteConfiguration(const std::string &BucketName, const std::string &IndexDocument, const std::string &ErrorDocument, TStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketWebSiteConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), IndexDocument.data(), (int32_t)IndexDocument.length(), ErrorDocument.data(), (int32_t)ErrorDocument.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::SetBucketWebSiteConfiguration(const std::string &BucketName, const std::string &IndexDocument, const std::string &ErrorDocument, TElStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketWebSiteConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), IndexDocument.data(), (int32_t)IndexDocument.length(), ErrorDocument.data(), (int32_t)ErrorDocument.length(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::SetBucketWebSiteConfiguration(const std::string &BucketName, const std::string &IndexDocument, const std::string &ErrorDocument, TElStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_SetBucketWebSiteConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), IndexDocument.data(), (int32_t)IndexDocument.length(), ErrorDocument.data(), (int32_t)ErrorDocument.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

SB_INLINE void TElAWSS3DataStorage::DeleteBucketWebSiteConfiguration(const std::string &BucketName)
{
	SBCheckError(TElAWSS3DataStorage_DeleteBucketWebSiteConfiguration(_Handle, BucketName.data(), (int32_t)BucketName.length()));
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
SB_INLINE void TElAWSS3DataStorage::DeleteBucketWebSiteConfiguration(TElAWSS3DataStorageBucket &Bucket)
{
	SBCheckError(TElAWSS3DataStorage_DeleteBucketWebSiteConfiguration_1(_Handle, Bucket.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::DeleteBucketWebSiteConfiguration(TElAWSS3DataStorageBucket *Bucket)
{
	SBCheckError(TElAWSS3DataStorage_DeleteBucketWebSiteConfiguration_1(_Handle, (Bucket != NULL) ? Bucket->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::DeleteBucketWebSiteConfiguration(const std::string &BucketName, TStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_DeleteBucketWebSiteConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::DeleteBucketWebSiteConfiguration(const std::string &BucketName, TStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_DeleteBucketWebSiteConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::DeleteBucketWebSiteConfiguration(const std::string &BucketName, TElStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_DeleteBucketWebSiteConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::DeleteBucketWebSiteConfiguration(const std::string &BucketName, TElStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_DeleteBucketWebSiteConfiguration_2(_Handle, BucketName.data(), (int32_t)BucketName.length(), (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::ListBuckets(TStringList &Buckets)
{
	SBCheckError(TElAWSS3DataStorage_ListBuckets(_Handle, Buckets.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::ListBuckets(TStringList *Buckets)
{
	SBCheckError(TElAWSS3DataStorage_ListBuckets(_Handle, (Buckets != NULL) ? Buckets->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::ListBuckets(TElStringList &Buckets)
{
	SBCheckError(TElAWSS3DataStorage_ListBuckets(_Handle, Buckets.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::ListBuckets(TElStringList *Buckets)
{
	SBCheckError(TElAWSS3DataStorage_ListBuckets(_Handle, (Buckets != NULL) ? Buckets->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::ListBuckets(TStringList &Buckets, TStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_ListBuckets_1(_Handle, Buckets.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::ListBuckets(TStringList *Buckets, TStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_ListBuckets_1(_Handle, (Buckets != NULL) ? Buckets->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::ListBuckets(TElStringList &Buckets, TElStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_ListBuckets_1(_Handle, Buckets.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::ListBuckets(TElStringList *Buckets, TElStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_ListBuckets_1(_Handle, (Buckets != NULL) ? Buckets->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKETLIST
SB_INLINE void TElAWSS3DataStorage::ListBuckets(TElAWSS3DataStorageBucketList &Buckets)
{
	SBCheckError(TElAWSS3DataStorage_ListBuckets_2(_Handle, Buckets.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::ListBuckets(TElAWSS3DataStorageBucketList *Buckets)
{
	SBCheckError(TElAWSS3DataStorage_ListBuckets_2(_Handle, (Buckets != NULL) ? Buckets->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKETLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKETLIST_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::ListBuckets(TElAWSS3DataStorageBucketList &Buckets, TStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_ListBuckets_3(_Handle, Buckets.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::ListBuckets(TElAWSS3DataStorageBucketList *Buckets, TStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_ListBuckets_3(_Handle, (Buckets != NULL) ? Buckets->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKETLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKETLIST_AND_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorage::ListBuckets(TElAWSS3DataStorageBucketList &Buckets, TElStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorage_ListBuckets_3(_Handle, Buckets.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::ListBuckets(TElAWSS3DataStorageBucketList *Buckets, TElStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorage_ListBuckets_3(_Handle, (Buckets != NULL) ? Buckets->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKETLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
void TElAWSS3DataStorage::PerformIAMRequest(const std::string &Address, TStringList &Parameters, TStringList &Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_PerformIAMRequest(_Handle, Address.data(), (int32_t)Address.length(), Parameters.getHandle(), Headers.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1865719826, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorage::PerformIAMRequest(const std::string &Address, TStringList *Parameters, TStringList *Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_PerformIAMRequest(_Handle, Address.data(), (int32_t)Address.length(), (Parameters != NULL) ? Parameters->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1865719826, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
void TElAWSS3DataStorage::PerformIAMRequest(const std::string &Address, TElStringList &Parameters, TElStringList &Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_PerformIAMRequest(_Handle, Address.data(), (int32_t)Address.length(), Parameters.getHandle(), Headers.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1330373004, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorage::PerformIAMRequest(const std::string &Address, TElStringList *Parameters, TElStringList *Headers, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_PerformIAMRequest(_Handle, Address.data(), (int32_t)Address.length(), (Parameters != NULL) ? Parameters->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1330373004, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TMEMORYSTREAM
TMemoryStream* TElAWSS3DataStorage::get_OutputStream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAWSS3DataStorage_get_OutputStream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OutputStream)
		this->_Inst_OutputStream = new TMemoryStream(hOutResult, ohFalse);
	else
		this->_Inst_OutputStream->updateHandle(hOutResult);
	return this->_Inst_OutputStream;
}
#endif /* SB_USE_CLASS_TMEMORYSTREAM */

TSBAWSProtocol TElAWSS3DataStorage::get_Protocol()
{
	TSBAWSProtocolRaw OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_get_Protocol(_Handle, &OutResultRaw));
	return (TSBAWSProtocol)OutResultRaw;
}

SB_INLINE void TElAWSS3DataStorage::set_Protocol(TSBAWSProtocol Value)
{
	SBCheckError(TElAWSS3DataStorage_set_Protocol(_Handle, (TSBAWSProtocolRaw)Value));
}

TSBAWSAuthType TElAWSS3DataStorage::get_AuthType()
{
	TSBAWSAuthTypeRaw OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_get_AuthType(_Handle, &OutResultRaw));
	return (TSBAWSAuthType)OutResultRaw;
}

SB_INLINE void TElAWSS3DataStorage::set_AuthType(TSBAWSAuthType Value)
{
	SBCheckError(TElAWSS3DataStorage_set_AuthType(_Handle, (TSBAWSAuthTypeRaw)Value));
}

void TElAWSS3DataStorage::get_KeyID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_get_KeyID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1951604880, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAWSS3DataStorage::set_KeyID(const std::string &Value)
{
	SBCheckError(TElAWSS3DataStorage_set_KeyID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAWSS3DataStorage::get_AccessKey(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_get_AccessKey(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2073704803, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAWSS3DataStorage::set_AccessKey(const std::string &Value)
{
	SBCheckError(TElAWSS3DataStorage_set_AccessKey(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAWSS3DataStorage::get_SecurityToken(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_get_SecurityToken(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1219946926, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAWSS3DataStorage::set_SecurityToken(const std::string &Value)
{
	SBCheckError(TElAWSS3DataStorage_set_SecurityToken(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElAWSS3DataStorage::get_UseSSL()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_get_UseSSL(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAWSS3DataStorage::set_UseSSL(bool Value)
{
	SBCheckError(TElAWSS3DataStorage_set_UseSSL(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
TElHTTPSClient* TElAWSS3DataStorage::get_HTTPClient()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAWSS3DataStorage_get_HTTPClient(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HTTPClient)
		this->_Inst_HTTPClient = new TElHTTPSClient(hOutResult, ohFalse);
	else
		this->_Inst_HTTPClient->updateHandle(hOutResult);
	return this->_Inst_HTTPClient;
}

SB_INLINE void TElAWSS3DataStorage::set_HTTPClient(TElHTTPSClient &Value)
{
	SBCheckError(TElAWSS3DataStorage_set_HTTPClient(_Handle, Value.getHandle()));
}

SB_INLINE void TElAWSS3DataStorage::set_HTTPClient(TElHTTPSClient *Value)
{
	SBCheckError(TElAWSS3DataStorage_set_HTTPClient(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElAWSS3DataStorage::get_AWSHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAWSS3DataStorage_get_AWSHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AWSHeaders)
		this->_Inst_AWSHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_AWSHeaders->updateHandle(hOutResult);
	return this->_Inst_AWSHeaders;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElAWSS3DataStorage::get_AWSHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAWSS3DataStorage_get_AWSHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AWSHeaders)
		this->_Inst_AWSHeaders = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_AWSHeaders->updateHandle(hOutResult);
	return this->_Inst_AWSHeaders;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

bool TElAWSS3DataStorage::get_UseCRCCheck()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_get_UseCRCCheck(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAWSS3DataStorage::set_UseCRCCheck(bool Value)
{
	SBCheckError(TElAWSS3DataStorage_set_UseCRCCheck(_Handle, (int8_t)Value));
}

bool TElAWSS3DataStorage::get_UseDelayedPut()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_get_UseDelayedPut(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAWSS3DataStorage::set_UseDelayedPut(bool Value)
{
	SBCheckError(TElAWSS3DataStorage_set_UseDelayedPut(_Handle, (int8_t)Value));
}

bool TElAWSS3DataStorage::get_UseURLEncoding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_get_UseURLEncoding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAWSS3DataStorage::set_UseURLEncoding(bool Value)
{
	SBCheckError(TElAWSS3DataStorage_set_UseURLEncoding(_Handle, (int8_t)Value));
}

bool TElAWSS3DataStorage::get_UseVersion4Signatures()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_get_UseVersion4Signatures(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAWSS3DataStorage::set_UseVersion4Signatures(bool Value)
{
	SBCheckError(TElAWSS3DataStorage_set_UseVersion4Signatures(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElAWSS3DataStorage::get_Version4SignatureHashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElAWSS3DataStorage_get_Version4SignatureHashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAWSS3DataStorage::set_Version4SignatureHashAlgorithm(int32_t Value)
{
	SBCheckError(TElAWSS3DataStorage_set_Version4SignatureHashAlgorithm(_Handle, Value));
}

void TElAWSS3DataStorage::get_SecMetadataID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_get_SecMetadataID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1746451766, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAWSS3DataStorage::set_SecMetadataID(const std::string &Value)
{
	SBCheckError(TElAWSS3DataStorage_set_SecMetadataID(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElAWSS3DataStorage::get_MultipartUploadPartSize()
{
	int64_t OutResult;
	SBCheckError(TElAWSS3DataStorage_get_MultipartUploadPartSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAWSS3DataStorage::set_MultipartUploadPartSize(int64_t Value)
{
	SBCheckError(TElAWSS3DataStorage_set_MultipartUploadPartSize(_Handle, Value));
}

SB_INLINE int64_t TElAWSS3DataStorage::get_MultipartUploadThreshold()
{
	int64_t OutResult;
	SBCheckError(TElAWSS3DataStorage_get_MultipartUploadThreshold(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAWSS3DataStorage::set_MultipartUploadThreshold(int64_t Value)
{
	SBCheckError(TElAWSS3DataStorage_set_MultipartUploadThreshold(_Handle, Value));
}

SB_INLINE int32_t TElAWSS3DataStorage::get_RetryCount()
{
	int32_t OutResult;
	SBCheckError(TElAWSS3DataStorage_get_RetryCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAWSS3DataStorage::set_RetryCount(int32_t Value)
{
	SBCheckError(TElAWSS3DataStorage_set_RetryCount(_Handle, Value));
}

TSBAWSS3DataStorageOptions TElAWSS3DataStorage::get_Options()
{
	TSBAWSS3DataStorageOptionsRaw OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_get_Options(_Handle, &OutResultRaw));
	return (TSBAWSS3DataStorageOptions)OutResultRaw;
}

SB_INLINE void TElAWSS3DataStorage::set_Options(TSBAWSS3DataStorageOptions Value)
{
	SBCheckError(TElAWSS3DataStorage_set_Options(_Handle, (TSBAWSS3DataStorageOptionsRaw)Value));
}

bool TElAWSS3DataStorage::get_Overwrite()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_get_Overwrite(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAWSS3DataStorage::set_Overwrite(bool Value)
{
	SBCheckError(TElAWSS3DataStorage_set_Overwrite(_Handle, (int8_t)Value));
}

bool TElAWSS3DataStorage::get_PassthroughMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_get_PassthroughMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAWSS3DataStorage::set_PassthroughMode(bool Value)
{
	SBCheckError(TElAWSS3DataStorage_set_PassthroughMode(_Handle, (int8_t)Value));
}

TSBAWSS3BucketAccessType TElAWSS3DataStorage::get_BucketAccessType()
{
	TSBAWSS3BucketAccessTypeRaw OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_get_BucketAccessType(_Handle, &OutResultRaw));
	return (TSBAWSS3BucketAccessType)OutResultRaw;
}

SB_INLINE void TElAWSS3DataStorage::set_BucketAccessType(TSBAWSS3BucketAccessType Value)
{
	SBCheckError(TElAWSS3DataStorage_set_BucketAccessType(_Handle, (TSBAWSS3BucketAccessTypeRaw)Value));
}

bool TElAWSS3DataStorage::get_EmbeddedMetadataMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_get_EmbeddedMetadataMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAWSS3DataStorage::set_EmbeddedMetadataMode(bool Value)
{
	SBCheckError(TElAWSS3DataStorage_set_EmbeddedMetadataMode(_Handle, (int8_t)Value));
}

void TElAWSS3DataStorage::get_BaseURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_get_BaseURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(242297417, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAWSS3DataStorage::set_BaseURL(const std::string &Value)
{
	SBCheckError(TElAWSS3DataStorage_set_BaseURL(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAWSS3DataStorage::get_RegionID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorage_get_RegionID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1684817239, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAWSS3DataStorage::set_RegionID(const std::string &Value)
{
	SBCheckError(TElAWSS3DataStorage_set_RegionID(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBAWSS3Region TElAWSS3DataStorage::get_Region()
{
	TSBAWSS3RegionRaw OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorage_get_Region(_Handle, &OutResultRaw));
	return (TSBAWSS3Region)OutResultRaw;
}

SB_INLINE void TElAWSS3DataStorage::set_Region(TSBAWSS3Region Value)
{
	SBCheckError(TElAWSS3DataStorage_set_Region(_Handle, (TSBAWSS3RegionRaw)Value));
}

SB_INLINE void TElAWSS3DataStorage::get_OnBeforeRequestSigning(TSBAWSS3BeforeRequestSigningEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAWSS3DataStorage_get_OnBeforeRequestSigning(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAWSS3DataStorage::set_OnBeforeRequestSigning(TSBAWSS3BeforeRequestSigningEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAWSS3DataStorage_set_OnBeforeRequestSigning(_Handle, pMethodValue, pDataValue));
}

void TElAWSS3DataStorage::initInstances()
{
#ifdef SB_USE_CLASS_TMEMORYSTREAM
	this->_Inst_OutputStream = NULL;
#endif /* SB_USE_CLASS_TMEMORYSTREAM */
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_AWSHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_AWSHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElAWSS3DataStorage::TElAWSS3DataStorage(TElAWSS3DataStorageHandle handle, TElOwnHandle ownHandle) : TElCustomDataStorage(handle, ownHandle)
{
	initInstances();
}

TElAWSS3DataStorage::TElAWSS3DataStorage(TComponent &AOwner) : TElCustomDataStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAWSS3DataStorage_Create(AOwner.getHandle(), &_Handle));
}

TElAWSS3DataStorage::TElAWSS3DataStorage(TComponent *AOwner) : TElCustomDataStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAWSS3DataStorage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElAWSS3DataStorage::~TElAWSS3DataStorage()
{
#ifdef SB_USE_CLASS_TMEMORYSTREAM
	delete this->_Inst_OutputStream;
	this->_Inst_OutputStream = NULL;
#endif /* SB_USE_CLASS_TMEMORYSTREAM */
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	delete this->_Inst_HTTPClient;
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_AWSHeaders;
	this->_Inst_AWSHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_AWSHeaders;
	this->_Inst_AWSHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGE */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT

SB_INLINE void TElAWSS3DataStorageObject::Assign(TElCustomDataStorageObject &Source)
{
	SBCheckError(TElAWSS3DataStorageObject_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageObject::Assign(TElCustomDataStorageObject *Source)
{
	SBCheckError(TElAWSS3DataStorageObject_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageObject::Clone()
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageObject_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAWSS3DataStorageObject::Delete()
{
	SBCheckError(TElAWSS3DataStorageObject_Delete(_Handle));
}

bool TElAWSS3DataStorageObject::Exists()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorageObject_Exists(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAWSS3DataStorageObject::Refresh()
{
	SBCheckError(TElAWSS3DataStorageObject_Refresh(_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElAWSS3DataStorageObject::Write(TStream &Data, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorageObject_Write(_Handle, Data.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageObject::Write(TStream *Data, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorageObject_Write(_Handle, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorageObject::Write(TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorageObject_Write_1(_Handle, Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), Metadata.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageObject::Write(TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorageObject_Write_1(_Handle, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElAWSS3DataStorageObject::Write(TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorageObject_Write_1(_Handle, Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), Metadata.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageObject::Write(TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorageObject_Write_1(_Handle, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorageObject::Write(TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorageObject_Write_2(_Handle, Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageObject::Write(TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorageObject_Write_2(_Handle, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElAWSS3DataStorageObject::Write(TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorageObject_Write_2(_Handle, Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageObject::Write(TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorageObject_Write_2(_Handle, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorageObject::Write(TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorageObject_Write_3(_Handle, Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageObject::Write(TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorageObject_Write_3(_Handle, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElAWSS3DataStorageObject::Write(TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorageObject_Write_3(_Handle, Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageObject::Write(TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorageObject_Write_3(_Handle, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElAWSS3DataStorageObject::Read(TStream &Strm)
{
	SBCheckError(TElAWSS3DataStorageObject_Read(_Handle, Strm.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageObject::Read(TStream *Strm)
{
	SBCheckError(TElAWSS3DataStorageObject_Read(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElAWSS3DataStorageObject::Read(TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag)
{
	SBCheckError(TElAWSS3DataStorageObject_Read_1(_Handle, Strm.getHandle(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length()));
}

SB_INLINE void TElAWSS3DataStorageObject::Read(TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag)
{
	SBCheckError(TElAWSS3DataStorageObject_Read_1(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length()));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElAWSS3DataStorageObject::Read(TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageObject_Read_2(_Handle, Strm.getHandle(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-951804471, 6, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-951804471, 7, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-951804471, 8, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorageObject::Read(TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageObject_Read_2(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-951804471, 6, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-951804471, 7, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-951804471, 8, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElAWSS3DataStorageObject::Read(TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageObject_Read_2(_Handle, Strm.getHandle(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(2021763404, 6, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(2021763404, 7, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(2021763404, 8, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorageObject::Read(TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageObject_Read_2(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(2021763404, 6, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(2021763404, 7, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(2021763404, 8, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElAWSS3DataStorageObject::Read(TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageObject_Read_3(_Handle, Strm.getHandle(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1624420168, 6, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(1624420168, 7, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1624420168, 8, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1624420168, 9, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorageObject::Read(TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageObject_Read_3(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1624420168, 6, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(1624420168, 7, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(1624420168, 8, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1624420168, 9, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElAWSS3DataStorageObject::Read(TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageObject_Read_3(_Handle, Strm.getHandle(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-84240677, 6, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-84240677, 7, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-84240677, 8, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-84240677, 9, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorageObject::Read(TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageObject_Read_3(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-84240677, 6, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-84240677, 7, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-84240677, 8, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-84240677, 9, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElAWSS3DataStorageObject::ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElAWSS3DataStorageObject_ReadBlock(_Handle, Strm.getHandle(), Offset, Size, &Read));
}

SB_INLINE void TElAWSS3DataStorageObject::ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElAWSS3DataStorageObject_ReadBlock(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElAWSS3DataStorageObject::ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag)
{
	SBCheckError(TElAWSS3DataStorageObject_ReadBlock_1(_Handle, Strm.getHandle(), Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length()));
}

SB_INLINE void TElAWSS3DataStorageObject::ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag)
{
	SBCheckError(TElAWSS3DataStorageObject_ReadBlock_1(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length()));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElAWSS3DataStorageObject::ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageObject_ReadBlock_2(_Handle, Strm.getHandle(), Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1033871525, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-1033871525, 10, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1033871525, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorageObject::ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageObject_ReadBlock_2(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1033871525, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-1033871525, 10, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1033871525, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElAWSS3DataStorageObject::ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageObject_ReadBlock_2(_Handle, Strm.getHandle(), Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1318905708, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(1318905708, 10, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1318905708, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorageObject::ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageObject_ReadBlock_2(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1318905708, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(1318905708, 10, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1318905708, 11, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElAWSS3DataStorageObject::ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageObject_ReadBlock_3(_Handle, Strm.getHandle(), Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(169796746, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(169796746, 10, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(169796746, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(169796746, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorageObject::ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageObject_ReadBlock_3(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(169796746, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(169796746, 10, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(169796746, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(169796746, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElAWSS3DataStorageObject::ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageObject_ReadBlock_3(_Handle, Strm.getHandle(), Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-499592765, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-499592765, 10, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-499592765, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-499592765, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorageObject::ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageObject_ReadBlock_3(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-499592765, 9, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-499592765, 10, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-499592765, 11, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-499592765, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageObject::Copy(const std::string &DestBucketName, const std::string &DestKey, TElCustomDataStorageSecurityHandler &NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageObject_Copy(_Handle, DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), NewHandler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageObject::Copy(const std::string &DestBucketName, const std::string &DestKey, TElCustomDataStorageSecurityHandler *NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageObject_Copy(_Handle, DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (NewHandler != NULL) ? NewHandler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageObject::Copy(const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageObject_Copy_1(_Handle, DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageObject::Copy(const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageObject_Copy_1(_Handle, DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageObject::Copy(const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TElStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageObject_Copy_1(_Handle, DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageObject::Copy(const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TElStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageObject_Copy_1(_Handle, DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageObject::Copy(const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageObject_Copy_2(_Handle, DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageObject::Copy(const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageObject_Copy_2(_Handle, DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageObject::Copy(const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TElStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageObject_Copy_2(_Handle, DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageObject::Copy(const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TElStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageObject_Copy_2(_Handle, DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageObject::Copy(const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageObject_Copy_3(_Handle, DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), StorageClass.data(), (int32_t)StorageClass.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageObject::Copy(const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageObject_Copy_3(_Handle, DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), StorageClass.data(), (int32_t)StorageClass.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageObject::Copy(const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TElStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageObject_Copy_3(_Handle, DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), StorageClass.data(), (int32_t)StorageClass.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageObject::Copy(const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TElStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageObject_Copy_3(_Handle, DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), StorageClass.data(), (int32_t)StorageClass.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElAWSS3DataStorageObject::GetACL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorageObject_GetACL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-399230345, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY
SB_INLINE void TElAWSS3DataStorageObject::GetACL(TElAWSS3AccessControlPolicy &Policy)
{
	SBCheckError(TElAWSS3DataStorageObject_GetACL_1(_Handle, Policy.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageObject::GetACL(TElAWSS3AccessControlPolicy *Policy)
{
	SBCheckError(TElAWSS3DataStorageObject_GetACL_1(_Handle, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY */

SB_INLINE void TElAWSS3DataStorageObject::SetACL(const std::string &ACL)
{
	SBCheckError(TElAWSS3DataStorageObject_SetACL(_Handle, ACL.data(), (int32_t)ACL.length()));
}

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY
SB_INLINE void TElAWSS3DataStorageObject::SetACL(TElAWSS3AccessControlPolicy &Policy)
{
	SBCheckError(TElAWSS3DataStorageObject_SetACL_1(_Handle, Policy.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageObject::SetACL(TElAWSS3AccessControlPolicy *Policy)
{
	SBCheckError(TElAWSS3DataStorageObject_SetACL_1(_Handle, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY */

#ifdef SB_USE_CLASS_TSTREAM
void TElAWSS3DataStorageObject::GetLocalETag(TStream &Stream, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorageObject_GetLocalETag(_Handle, Stream.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-403919905, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorageObject::GetLocalETag(TStream *Stream, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorageObject_GetLocalETag(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-403919905, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElAWSS3DataStorageObject::GetLocalETag(const std::string &Filename, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorageObject_GetLocalETag_1(_Handle, Filename.data(), (int32_t)Filename.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1884307227, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorageObject::GetRemoteETag(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorageObject_GetRemoteETag(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-627842509, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElAWSS3DataStorageObject::GetTorrent(TStream &Stream)
{
	SBCheckError(TElAWSS3DataStorageObject_GetTorrent(_Handle, Stream.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageObject::GetTorrent(TStream *Stream)
{
	SBCheckError(TElAWSS3DataStorageObject_GetTorrent(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElAWSS3DataStorageObject::get_BucketName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorageObject_get_BucketName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1620957128, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorageObject::get_Key(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorageObject_get_Key(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1660008647, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElAWSS3DataStorageObject::get_LastModified()
{
	int64_t OutResult;
	SBCheckError(TElAWSS3DataStorageObject_get_LastModified(_Handle, &OutResult));
	return OutResult;
}

void TElAWSS3DataStorageObject::get_ETag(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorageObject_get_ETag(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-886893959, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElAWSS3DataStorageObject::get_Size()
{
	int64_t OutResult;
	SBCheckError(TElAWSS3DataStorageObject_get_Size(_Handle, &OutResult));
	return OutResult;
}

void TElAWSS3DataStorageObject::get_StorageClass(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorageObject_get_StorageClass(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(558224489, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorageObject::get_OwnerID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorageObject_get_OwnerID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1948391230, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorageObject::get_OwnerDisplayName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorageObject_get_OwnerDisplayName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-939045225, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorageObject::get_ContentType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorageObject_get_ContentType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1352520638, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorageObject::get_ContentDisposition(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorageObject_get_ContentDisposition(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1590714566, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorageObject::get_ContentEncoding(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorageObject_get_ContentEncoding(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(395854118, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElAWSS3DataStorageObject::get_Metadata()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAWSS3DataStorageObject_get_Metadata(_Handle, &hOutResult));
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
TElStringList* TElAWSS3DataStorageObject::get_Metadata()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAWSS3DataStorageObject_get_Metadata(_Handle, &hOutResult));
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
TStringList* TElAWSS3DataStorageObject::get_CustomHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAWSS3DataStorageObject_get_CustomHeaders(_Handle, &hOutResult));
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
TElStringList* TElAWSS3DataStorageObject::get_CustomHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAWSS3DataStorageObject_get_CustomHeaders(_Handle, &hOutResult));
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

void TElAWSS3DataStorageObject::initInstances()
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

TElAWSS3DataStorageObject::TElAWSS3DataStorageObject(TElAWSS3DataStorageObjectHandle handle, TElOwnHandle ownHandle) : TElCustomDataStorageObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGE
TElAWSS3DataStorageObject::TElAWSS3DataStorageObject(TElAWSS3DataStorage &Storage) : TElCustomDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAWSS3DataStorageObject_Create(Storage.getHandle(), &_Handle));
}

TElAWSS3DataStorageObject::TElAWSS3DataStorageObject(TElAWSS3DataStorage *Storage) : TElCustomDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAWSS3DataStorageObject_Create((Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGE */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGE
TElAWSS3DataStorageObject::TElAWSS3DataStorageObject(TElAWSS3DataStorage &Storage, const std::string &BucketName, const std::string &Key) : TElCustomDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAWSS3DataStorageObject_Create_1(Storage.getHandle(), BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), &_Handle));
}

TElAWSS3DataStorageObject::TElAWSS3DataStorageObject(TElAWSS3DataStorage *Storage, const std::string &BucketName, const std::string &Key) : TElCustomDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAWSS3DataStorageObject_Create_1((Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, BucketName.data(), (int32_t)BucketName.length(), Key.data(), (int32_t)Key.length(), &_Handle));
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGE */

TElAWSS3DataStorageObject::~TElAWSS3DataStorageObject()
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
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGELISTSTATE

bool TElAWSS3DataStorageListState::Completed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorageListState_Completed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TElAWSS3DataStorageListState::TElAWSS3DataStorageListState(TElAWSS3DataStorageListStateHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TElAWSS3DataStorageListState::TElAWSS3DataStorageListState(const std::string &BucketName, const std::string &Prefix, const std::string &Delimiter, TStringList &Prefixes, TStringList &Headers) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAWSS3DataStorageListState_Create(BucketName.data(), (int32_t)BucketName.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), Prefixes.getHandle(), Headers.getHandle(), &_Handle));
}

TElAWSS3DataStorageListState::TElAWSS3DataStorageListState(const std::string &BucketName, const std::string &Prefix, const std::string &Delimiter, TStringList *Prefixes, TStringList *Headers) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAWSS3DataStorageListState_Create(BucketName.data(), (int32_t)BucketName.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElAWSS3DataStorageListState::TElAWSS3DataStorageListState(const std::string &BucketName, const std::string &Prefix, const std::string &Delimiter, TElStringList &Prefixes, TElStringList &Headers) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAWSS3DataStorageListState_Create(BucketName.data(), (int32_t)BucketName.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), Prefixes.getHandle(), Headers.getHandle(), &_Handle));
}

TElAWSS3DataStorageListState::TElAWSS3DataStorageListState(const std::string &BucketName, const std::string &Prefix, const std::string &Delimiter, TElStringList *Prefixes, TElStringList *Headers) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAWSS3DataStorageListState_Create(BucketName.data(), (int32_t)BucketName.length(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLGRANT

SB_INLINE void TElAWSS3AccessControlGrant::Reset()
{
	SBCheckError(TElAWSS3AccessControlGrant_Reset(_Handle));
}

void TElAWSS3AccessControlGrant::SaveToXML(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3AccessControlGrant_SaveToXML(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(437683595, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAWSS3AccessControlGrant::LoadFromXML(const std::string &Xml)
{
	SBCheckError(TElAWSS3AccessControlGrant_LoadFromXML(_Handle, Xml.data(), (int32_t)Xml.length()));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElAWSS3AccessControlGrant::LoadFromXML(TStream &XmlStream)
{
	SBCheckError(TElAWSS3AccessControlGrant_LoadFromXML_1(_Handle, XmlStream.getHandle()));
}

SB_INLINE void TElAWSS3AccessControlGrant::LoadFromXML(TStream *XmlStream)
{
	SBCheckError(TElAWSS3AccessControlGrant_LoadFromXML_1(_Handle, (XmlStream != NULL) ? XmlStream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElAWSS3AccessControlGrant::LoadFromXML(TElXMLDOMElement &Elem)
{
	SBCheckError(TElAWSS3AccessControlGrant_LoadFromXML_2(_Handle, Elem.getHandle()));
}

SB_INLINE void TElAWSS3AccessControlGrant::LoadFromXML(TElXMLDOMElement *Elem)
{
	SBCheckError(TElAWSS3AccessControlGrant_LoadFromXML_2(_Handle, (Elem != NULL) ? Elem->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

TSBAWSS3AccessControlGranteeType TElAWSS3AccessControlGrant::get_GranteeType()
{
	TSBAWSS3AccessControlGranteeTypeRaw OutResultRaw = 0;
	SBCheckError(TElAWSS3AccessControlGrant_get_GranteeType(_Handle, &OutResultRaw));
	return (TSBAWSS3AccessControlGranteeType)OutResultRaw;
}

SB_INLINE void TElAWSS3AccessControlGrant::set_GranteeType(TSBAWSS3AccessControlGranteeType Value)
{
	SBCheckError(TElAWSS3AccessControlGrant_set_GranteeType(_Handle, (TSBAWSS3AccessControlGranteeTypeRaw)Value));
}

void TElAWSS3AccessControlGrant::get_UserID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3AccessControlGrant_get_UserID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-9114423, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAWSS3AccessControlGrant::set_UserID(const std::string &Value)
{
	SBCheckError(TElAWSS3AccessControlGrant_set_UserID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAWSS3AccessControlGrant::get_UserDisplayName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3AccessControlGrant_get_UserDisplayName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1936193574, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAWSS3AccessControlGrant::set_UserDisplayName(const std::string &Value)
{
	SBCheckError(TElAWSS3AccessControlGrant_set_UserDisplayName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAWSS3AccessControlGrant::get_GroupURI(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3AccessControlGrant_get_GroupURI(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(798771002, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAWSS3AccessControlGrant::set_GroupURI(const std::string &Value)
{
	SBCheckError(TElAWSS3AccessControlGrant_set_GroupURI(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAWSS3AccessControlGrant::get_Email(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3AccessControlGrant_get_Email(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1318828466, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAWSS3AccessControlGrant::set_Email(const std::string &Value)
{
	SBCheckError(TElAWSS3AccessControlGrant_set_Email(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBAWSS3AccessControlPermission TElAWSS3AccessControlGrant::get_Permission()
{
	TSBAWSS3AccessControlPermissionRaw OutResultRaw = 0;
	SBCheckError(TElAWSS3AccessControlGrant_get_Permission(_Handle, &OutResultRaw));
	return (TSBAWSS3AccessControlPermission)OutResultRaw;
}

SB_INLINE void TElAWSS3AccessControlGrant::set_Permission(TSBAWSS3AccessControlPermission Value)
{
	SBCheckError(TElAWSS3AccessControlGrant_set_Permission(_Handle, (TSBAWSS3AccessControlPermissionRaw)Value));
}

void TElAWSS3AccessControlGrant::get_CustomPermission(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3AccessControlGrant_get_CustomPermission(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(220110599, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAWSS3AccessControlGrant::set_CustomPermission(const std::string &Value)
{
	SBCheckError(TElAWSS3AccessControlGrant_set_CustomPermission(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAWSS3AccessControlGrant::get_CustomGrantee(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3AccessControlGrant_get_CustomGrantee(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2092723606, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAWSS3AccessControlGrant::set_CustomGrantee(const std::string &Value)
{
	SBCheckError(TElAWSS3AccessControlGrant_set_CustomGrantee(_Handle, Value.data(), (int32_t)Value.length()));
}

TElAWSS3AccessControlGrant::TElAWSS3AccessControlGrant(TElAWSS3AccessControlGrantHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElAWSS3AccessControlGrant::TElAWSS3AccessControlGrant() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAWSS3AccessControlGrant_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLGRANT */

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY

SB_INLINE int32_t TElAWSS3AccessControlPolicy::AddGrant()
{
	int32_t OutResult;
	SBCheckError(TElAWSS3AccessControlPolicy_AddGrant(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAWSS3AccessControlPolicy::RemoveGrant(int32_t Index)
{
	SBCheckError(TElAWSS3AccessControlPolicy_RemoveGrant(_Handle, Index));
}

SB_INLINE void TElAWSS3AccessControlPolicy::ClearGrants()
{
	SBCheckError(TElAWSS3AccessControlPolicy_ClearGrants(_Handle));
}

void TElAWSS3AccessControlPolicy::SaveToXML(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3AccessControlPolicy_SaveToXML(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1258478561, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAWSS3AccessControlPolicy::LoadFromXML(const std::string &Xml)
{
	SBCheckError(TElAWSS3AccessControlPolicy_LoadFromXML(_Handle, Xml.data(), (int32_t)Xml.length()));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElAWSS3AccessControlPolicy::LoadFromXML(TStream &XmlStream)
{
	SBCheckError(TElAWSS3AccessControlPolicy_LoadFromXML_1(_Handle, XmlStream.getHandle()));
}

SB_INLINE void TElAWSS3AccessControlPolicy::LoadFromXML(TStream *XmlStream)
{
	SBCheckError(TElAWSS3AccessControlPolicy_LoadFromXML_1(_Handle, (XmlStream != NULL) ? XmlStream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElAWSS3AccessControlPolicy::Reset()
{
	SBCheckError(TElAWSS3AccessControlPolicy_Reset(_Handle));
}

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLGRANT
TElAWSS3AccessControlGrant* TElAWSS3AccessControlPolicy::get_Grants(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAWSS3AccessControlPolicy_get_Grants(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Grants)
		this->_Inst_Grants = new TElAWSS3AccessControlGrant(hOutResult, ohFalse);
	else
		this->_Inst_Grants->updateHandle(hOutResult);
	return this->_Inst_Grants;
}
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLGRANT */

SB_INLINE int32_t TElAWSS3AccessControlPolicy::get_GrantCount()
{
	int32_t OutResult;
	SBCheckError(TElAWSS3AccessControlPolicy_get_GrantCount(_Handle, &OutResult));
	return OutResult;
}

void TElAWSS3AccessControlPolicy::get_OwnerID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3AccessControlPolicy_get_OwnerID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(775981921, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAWSS3AccessControlPolicy::set_OwnerID(const std::string &Value)
{
	SBCheckError(TElAWSS3AccessControlPolicy_set_OwnerID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAWSS3AccessControlPolicy::get_OwnerDisplayName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3AccessControlPolicy_get_OwnerDisplayName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1937457081, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAWSS3AccessControlPolicy::set_OwnerDisplayName(const std::string &Value)
{
	SBCheckError(TElAWSS3AccessControlPolicy_set_OwnerDisplayName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElAWSS3AccessControlPolicy::initInstances()
{
#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLGRANT
	this->_Inst_Grants = NULL;
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLGRANT */
}

TElAWSS3AccessControlPolicy::TElAWSS3AccessControlPolicy(TElAWSS3AccessControlPolicyHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElAWSS3AccessControlPolicy::TElAWSS3AccessControlPolicy() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAWSS3AccessControlPolicy_Create(&_Handle));
}

TElAWSS3AccessControlPolicy::~TElAWSS3AccessControlPolicy()
{
#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLGRANT
	delete this->_Inst_Grants;
	this->_Inst_Grants = NULL;
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLGRANT */
}
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT
SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorageBucket::AcquireObject(const std::string &Key)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_AcquireObject(_Handle, Key.data(), (int32_t)Key.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElAWSS3DataStorageBucket::List(TElDataStorageObjectList &Objects)
{
	SBCheckError(TElAWSS3DataStorageBucket_List(_Handle, Objects.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageBucket::List(TElDataStorageObjectList *Objects)
{
	SBCheckError(TElAWSS3DataStorageBucket_List(_Handle, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorageBucket::List(TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList &Prefixes, TStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorageBucket_List_1(_Handle, Objects.getHandle(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, Prefixes.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageBucket::List(TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList *Prefixes, TStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorageBucket_List_1(_Handle, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorageBucket::List(TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList &Prefixes, TElStringList &Headers)
{
	SBCheckError(TElAWSS3DataStorageBucket_List_1(_Handle, Objects.getHandle(), Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, Prefixes.getHandle(), Headers.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageBucket::List(TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList *Prefixes, TElStringList *Headers)
{
	SBCheckError(TElAWSS3DataStorageBucket_List_1(_Handle, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), MaxCount, (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGELISTSTATE
SB_INLINE TElAWSS3DataStorageListStateHandle TElAWSS3DataStorageBucket::ListInit()
{
	TElAWSS3DataStorageListStateHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_ListInit(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGELISTSTATE */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TSTRINGLIST
SB_INLINE TElAWSS3DataStorageListStateHandle TElAWSS3DataStorageBucket::ListInit(const std::string &Prefix, const std::string &Delimiter, TStringList &Prefixes, TStringList &Headers)
{
	TElAWSS3DataStorageListStateHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_ListInit_1(_Handle, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), Prefixes.getHandle(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageListStateHandle TElAWSS3DataStorageBucket::ListInit(const std::string &Prefix, const std::string &Delimiter, TStringList *Prefixes, TStringList *Headers)
{
	TElAWSS3DataStorageListStateHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_ListInit_1(_Handle, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELSTRINGLIST
SB_INLINE TElAWSS3DataStorageListStateHandle TElAWSS3DataStorageBucket::ListInit(const std::string &Prefix, const std::string &Delimiter, TElStringList &Prefixes, TElStringList &Headers)
{
	TElAWSS3DataStorageListStateHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_ListInit_1(_Handle, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), Prefixes.getHandle(), Headers.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageListStateHandle TElAWSS3DataStorageBucket::ListInit(const std::string &Prefix, const std::string &Delimiter, TElStringList *Prefixes, TElStringList *Headers)
{
	TElAWSS3DataStorageListStateHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_ListInit_1(_Handle, Prefix.data(), (int32_t)Prefix.length(), Delimiter.data(), (int32_t)Delimiter.length(), (Prefixes != NULL) ? Prefixes->getHandle() : SB_NULL_HANDLE, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElAWSS3DataStorageBucket::ListNext(TElAWSS3DataStorageListState &State, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElAWSS3DataStorageBucket_ListNext(_Handle, State.getHandle(), Objects.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageBucket::ListNext(TElAWSS3DataStorageListState *State, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElAWSS3DataStorageBucket_ListNext(_Handle, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElAWSS3DataStorageBucket::ListNext(TElAWSS3DataStorageListState &State, TElDataStorageObjectList &Objects, int32_t MaxCount)
{
	SBCheckError(TElAWSS3DataStorageBucket_ListNext_1(_Handle, State.getHandle(), Objects.getHandle(), MaxCount));
}

SB_INLINE void TElAWSS3DataStorageBucket::ListNext(TElAWSS3DataStorageListState *State, TElDataStorageObjectList *Objects, int32_t MaxCount)
{
	SBCheckError(TElAWSS3DataStorageBucket_ListNext_1(_Handle, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, MaxCount));
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGELISTSTATE
void TElAWSS3DataStorageBucket::ListFinal(TElAWSS3DataStorageListState &State)
{
	TElClassHandle hState = State.getHandle();
	SBCheckError(TElAWSS3DataStorageBucket_ListFinal(_Handle, &hState));
	State.updateHandle(hState);
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT
SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorageBucket::CreateObject(const std::string &ObjName)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CreateObject(_Handle, ObjName.data(), (int32_t)ObjName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorageBucket::CreateObject(const std::string &ObjName, TElCustomDataStorageSecurityHandler &Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CreateObject_1(_Handle, ObjName.data(), (int32_t)ObjName.length(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorageBucket::CreateObject(const std::string &ObjName, TElCustomDataStorageSecurityHandler *Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CreateObject_1(_Handle, ObjName.data(), (int32_t)ObjName.length(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST
SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorageBucket::CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CreateObject_2(_Handle, ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), Metadata.getHandle(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorageBucket::CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CreateObject_2(_Handle, ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST
SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorageBucket::CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CreateObject_2(_Handle, ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), Metadata.getHandle(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorageBucket::CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CreateObject_2(_Handle, ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST
SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorageBucket::CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CreateObject_3(_Handle, ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorageBucket::CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CreateObject_3(_Handle, ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST
SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorageBucket::CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CreateObject_3(_Handle, ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorageBucket::CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CreateObject_3(_Handle, ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST
SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorageBucket::CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CreateObject_4(_Handle, ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorageBucket::CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CreateObject_4(_Handle, ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST
SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorageBucket::CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CreateObject_4(_Handle, ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAWSS3DataStorageObjectHandle TElAWSS3DataStorageBucket::CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	TElAWSS3DataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CreateObject_4(_Handle, ObjName.data(), (int32_t)ObjName.length(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST */
#endif

SB_INLINE void TElAWSS3DataStorageBucket::DeleteObject(const std::string &Key)
{
	SBCheckError(TElAWSS3DataStorageBucket_DeleteObject(_Handle, Key.data(), (int32_t)Key.length()));
}

bool TElAWSS3DataStorageBucket::ObjectExists(const std::string &Key)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorageBucket_ObjectExists(_Handle, Key.data(), (int32_t)Key.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElAWSS3DataStorageBucket::WriteObject(const std::string &Key, TStream &Data, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorageBucket_WriteObject(_Handle, Key.data(), (int32_t)Key.length(), Data.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageBucket::WriteObject(const std::string &Key, TStream *Data, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorageBucket_WriteObject(_Handle, Key.data(), (int32_t)Key.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorageBucket::WriteObject(const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorageBucket_WriteObject_1(_Handle, Key.data(), (int32_t)Key.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), Metadata.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageBucket::WriteObject(const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorageBucket_WriteObject_1(_Handle, Key.data(), (int32_t)Key.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElAWSS3DataStorageBucket::WriteObject(const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorageBucket_WriteObject_1(_Handle, Key.data(), (int32_t)Key.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), Metadata.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageBucket::WriteObject(const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorageBucket_WriteObject_1(_Handle, Key.data(), (int32_t)Key.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorageBucket::WriteObject(const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorageBucket_WriteObject_2(_Handle, Key.data(), (int32_t)Key.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageBucket::WriteObject(const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorageBucket_WriteObject_2(_Handle, Key.data(), (int32_t)Key.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElAWSS3DataStorageBucket::WriteObject(const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorageBucket_WriteObject_2(_Handle, Key.data(), (int32_t)Key.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageBucket::WriteObject(const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorageBucket_WriteObject_2(_Handle, Key.data(), (int32_t)Key.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorageBucket::WriteObject(const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorageBucket_WriteObject_3(_Handle, Key.data(), (int32_t)Key.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageBucket::WriteObject(const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorageBucket_WriteObject_3(_Handle, Key.data(), (int32_t)Key.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElAWSS3DataStorageBucket::WriteObject(const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElAWSS3DataStorageBucket_WriteObject_3(_Handle, Key.data(), (int32_t)Key.length(), Data.getHandle(), ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), Metadata.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageBucket::WriteObject(const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElAWSS3DataStorageBucket_WriteObject_3(_Handle, Key.data(), (int32_t)Key.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), ContentDisposition.data(), (int32_t)ContentDisposition.length(), ContentEncoding.data(), (int32_t)ContentEncoding.length(), StorageClass.data(), (int32_t)StorageClass.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElAWSS3DataStorageBucket::ReadObject(const std::string &Key, TStream &Strm)
{
	SBCheckError(TElAWSS3DataStorageBucket_ReadObject(_Handle, Key.data(), (int32_t)Key.length(), Strm.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageBucket::ReadObject(const std::string &Key, TStream *Strm)
{
	SBCheckError(TElAWSS3DataStorageBucket_ReadObject(_Handle, Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElAWSS3DataStorageBucket::ReadObject(const std::string &Key, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag)
{
	SBCheckError(TElAWSS3DataStorageBucket_ReadObject_1(_Handle, Key.data(), (int32_t)Key.length(), Strm.getHandle(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length()));
}

SB_INLINE void TElAWSS3DataStorageBucket::ReadObject(const std::string &Key, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag)
{
	SBCheckError(TElAWSS3DataStorageBucket_ReadObject_1(_Handle, Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length()));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElAWSS3DataStorageBucket::ReadObject(const std::string &Key, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageBucket_ReadObject_2(_Handle, Key.data(), (int32_t)Key.length(), Strm.getHandle(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1597557558, 7, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(1597557558, 8, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1597557558, 9, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorageBucket::ReadObject(const std::string &Key, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageBucket_ReadObject_2(_Handle, Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1597557558, 7, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(1597557558, 8, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1597557558, 9, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElAWSS3DataStorageBucket::ReadObject(const std::string &Key, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageBucket_ReadObject_2(_Handle, Key.data(), (int32_t)Key.length(), Strm.getHandle(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1772959875, 7, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(1772959875, 8, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1772959875, 9, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorageBucket::ReadObject(const std::string &Key, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageBucket_ReadObject_2(_Handle, Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(1772959875, 7, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(1772959875, 8, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(1772959875, 9, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElAWSS3DataStorageBucket::ReadObject(const std::string &Key, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageBucket_ReadObject_3(_Handle, Key.data(), (int32_t)Key.length(), Strm.getHandle(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(605115752, 7, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(605115752, 8, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(605115752, 9, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(605115752, 10, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorageBucket::ReadObject(const std::string &Key, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageBucket_ReadObject_3(_Handle, Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(605115752, 7, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(605115752, 8, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(605115752, 9, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(605115752, 10, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElAWSS3DataStorageBucket::ReadObject(const std::string &Key, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageBucket_ReadObject_3(_Handle, Key.data(), (int32_t)Key.length(), Strm.getHandle(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(840363448, 7, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(840363448, 8, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(840363448, 9, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(840363448, 10, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorageBucket::ReadObject(const std::string &Key, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageBucket_ReadObject_3(_Handle, Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(840363448, 7, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(840363448, 8, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(840363448, 9, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(840363448, 10, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElAWSS3DataStorageBucket::ReadBlock(const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElAWSS3DataStorageBucket_ReadBlock(_Handle, Key.data(), (int32_t)Key.length(), Strm.getHandle(), Offset, Size, &Read));
}

SB_INLINE void TElAWSS3DataStorageBucket::ReadBlock(const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElAWSS3DataStorageBucket_ReadBlock(_Handle, Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElAWSS3DataStorageBucket::ReadBlock(const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag)
{
	SBCheckError(TElAWSS3DataStorageBucket_ReadBlock_1(_Handle, Key.data(), (int32_t)Key.length(), Strm.getHandle(), Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length()));
}

SB_INLINE void TElAWSS3DataStorageBucket::ReadBlock(const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag)
{
	SBCheckError(TElAWSS3DataStorageBucket_ReadBlock_1(_Handle, Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length()));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElAWSS3DataStorageBucket::ReadBlock(const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageBucket_ReadBlock_2(_Handle, Key.data(), (int32_t)Key.length(), Strm.getHandle(), Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1412467291, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-1412467291, 11, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1412467291, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorageBucket::ReadBlock(const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageBucket_ReadBlock_2(_Handle, Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1412467291, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-1412467291, 11, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1412467291, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElAWSS3DataStorageBucket::ReadBlock(const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageBucket_ReadBlock_2(_Handle, Key.data(), (int32_t)Key.length(), Strm.getHandle(), Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(521702182, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(521702182, 11, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(521702182, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorageBucket::ReadBlock(const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageBucket_ReadBlock_2(_Handle, Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(521702182, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(521702182, 11, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(521702182, 12, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
void TElAWSS3DataStorageBucket::ReadBlock(const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageBucket_ReadBlock_3(_Handle, Key.data(), (int32_t)Key.length(), Strm.getHandle(), Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(2104347988, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(2104347988, 11, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(2104347988, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(2104347988, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorageBucket::ReadBlock(const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageBucket_ReadBlock_3(_Handle, Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(2104347988, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(2104347988, 11, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(2104347988, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(2104347988, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
void TElAWSS3DataStorageBucket::ReadBlock(const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageBucket_ReadBlock_3(_Handle, Key.data(), (int32_t)Key.length(), Strm.getHandle(), Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), Metadata.getHandle(), (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1087252915, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-1087252915, 11, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1087252915, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1087252915, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}

void TElAWSS3DataStorageBucket::ReadBlock(const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag)
{
	int32_t szObjContentType = (int32_t)ObjContentType.length();
	int32_t szObjContentDisposition = (int32_t)ObjContentDisposition.length();
	int32_t szObjContentEncoding = (int32_t)ObjContentEncoding.length();
	int32_t szObjETag = (int32_t)ObjETag.length();
	uint32_t _err = TElAWSS3DataStorageBucket_ReadBlock_3(_Handle, Key.data(), (int32_t)Key.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, (char *)ObjContentType.data(), &szObjContentType, (char *)ObjContentDisposition.data(), &szObjContentDisposition, (char *)ObjContentEncoding.data(), &szObjContentEncoding, (char *)ObjETag.data(), &szObjETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ObjContentType.resize(szObjContentType);
		SBCheckError(SBGetLastReturnStringA(-1087252915, 10, (char *)ObjContentType.data(), &szObjContentType));
		ObjContentDisposition.resize(szObjContentDisposition);
		SBCheckError(SBGetLastReturnStringA(-1087252915, 11, (char *)ObjContentDisposition.data(), &szObjContentDisposition));
		ObjContentEncoding.resize(szObjContentEncoding);
		SBCheckError(SBGetLastReturnStringA(-1087252915, 12, (char *)ObjContentEncoding.data(), &szObjContentEncoding));
		ObjETag.resize(szObjETag);
		SBCheckError(SBGetLastReturnStringA(-1087252915, 13, (char *)ObjETag.data(), &szObjETag));
	}
	else
		SBCheckError(_err);

	ObjContentType.resize(szObjContentType);
	ObjContentDisposition.resize(szObjContentDisposition);
	ObjContentEncoding.resize(szObjContentEncoding);
	ObjETag.resize(szObjETag);
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageBucket::CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TElCustomDataStorageSecurityHandler &NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CopyObject(_Handle, SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), NewHandler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageBucket::CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TElCustomDataStorageSecurityHandler *NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CopyObject(_Handle, SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (NewHandler != NULL) ? NewHandler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageBucket::CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CopyObject_1(_Handle, SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageBucket::CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CopyObject_1(_Handle, SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageBucket::CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TElStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CopyObject_1(_Handle, SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageBucket::CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TElStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CopyObject_1(_Handle, SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageBucket::CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CopyObject_2(_Handle, SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageBucket::CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CopyObject_2(_Handle, SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageBucket::CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TElStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CopyObject_2(_Handle, SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageBucket::CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TElStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CopyObject_2(_Handle, SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageBucket::CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CopyObject_3(_Handle, SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), StorageClass.data(), (int32_t)StorageClass.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageBucket::CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CopyObject_3(_Handle, SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), StorageClass.data(), (int32_t)StorageClass.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageBucket::CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TElStringList &Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CopyObject_3(_Handle, SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), StorageClass.data(), (int32_t)StorageClass.length(), (int8_t)PreserveMetadata, Metadata.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElAWSS3DataStorageBucket::CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TElStringList *Metadata)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_CopyObject_3(_Handle, SourceKey.data(), (int32_t)SourceKey.length(), DestBucketName.data(), (int32_t)DestBucketName.length(), DestKey.data(), (int32_t)DestKey.length(), (TSBAWSS3ReadObjectConditionRaw)Condition, DateTime, ETag.data(), (int32_t)ETag.length(), StorageClass.data(), (int32_t)StorageClass.length(), (int8_t)PreserveMetadata, (Metadata != NULL) ? Metadata->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

void TElAWSS3DataStorageBucket::GetObjectACL(const std::string &Key, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorageBucket_GetObjectACL(_Handle, Key.data(), (int32_t)Key.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1673063495, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAWSS3DataStorageBucket::SetObjectACL(const std::string &Key, const std::string &ACL)
{
	SBCheckError(TElAWSS3DataStorageBucket_SetObjectACL(_Handle, Key.data(), (int32_t)Key.length(), ACL.data(), (int32_t)ACL.length()));
}

void TElAWSS3DataStorageBucket::GetRemoteETag(const std::string &Key, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorageBucket_GetRemoteETag(_Handle, Key.data(), (int32_t)Key.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-861504477, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAWSS3DataStorageBucket::Delete()
{
	SBCheckError(TElAWSS3DataStorageBucket_Delete(_Handle));
}

bool TElAWSS3DataStorageBucket::Exists()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorageBucket_Exists(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElAWSS3DataStorageBucket::GetLocation(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorageBucket_GetLocation(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(252848241, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorageBucket::GetACL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorageBucket_GetACL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-58472415, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY
SB_INLINE void TElAWSS3DataStorageBucket::GetACL(TElAWSS3AccessControlPolicy &Policy)
{
	SBCheckError(TElAWSS3DataStorageBucket_GetACL_1(_Handle, Policy.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageBucket::GetACL(TElAWSS3AccessControlPolicy *Policy)
{
	SBCheckError(TElAWSS3DataStorageBucket_GetACL_1(_Handle, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY */

SB_INLINE void TElAWSS3DataStorageBucket::SetACL(const std::string &ACL)
{
	SBCheckError(TElAWSS3DataStorageBucket_SetACL(_Handle, ACL.data(), (int32_t)ACL.length()));
}

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY
SB_INLINE void TElAWSS3DataStorageBucket::SetACL(TElAWSS3AccessControlPolicy &Policy)
{
	SBCheckError(TElAWSS3DataStorageBucket_SetACL_1(_Handle, Policy.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageBucket::SetACL(TElAWSS3AccessControlPolicy *Policy)
{
	SBCheckError(TElAWSS3DataStorageBucket_SetACL_1(_Handle, (Policy != NULL) ? Policy->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY */

void TElAWSS3DataStorageBucket::GetPolicy(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorageBucket_GetPolicy(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1304740347, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAWSS3DataStorageBucket::SetPolicy(const std::string &Policy)
{
	SBCheckError(TElAWSS3DataStorageBucket_SetPolicy(_Handle, Policy.data(), (int32_t)Policy.length()));
}

SB_INLINE void TElAWSS3DataStorageBucket::DeletePolicy()
{
	SBCheckError(TElAWSS3DataStorageBucket_DeletePolicy(_Handle));
}

SB_INLINE void TElAWSS3DataStorageBucket::SetPaymentConfiguration(const std::string &PaymentConfig)
{
	SBCheckError(TElAWSS3DataStorageBucket_SetPaymentConfiguration(_Handle, PaymentConfig.data(), (int32_t)PaymentConfig.length()));
}

SB_INLINE void TElAWSS3DataStorageBucket::SetPaymentConfiguration(bool RequesterPays)
{
	SBCheckError(TElAWSS3DataStorageBucket_SetPaymentConfiguration_1(_Handle, (int8_t)RequesterPays));
}

void TElAWSS3DataStorageBucket::GetPaymentConfiguration(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorageBucket_GetPaymentConfiguration(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2132684851, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElAWSS3DataStorageBucket::IsRequesterPaysBucket()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorageBucket_IsRequesterPaysBucket(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TSBAWSS3BucketVersioning TElAWSS3DataStorageBucket::GetVersioning()
{
	TSBAWSS3BucketVersioningRaw OutResultRaw = 0;
	SBCheckError(TElAWSS3DataStorageBucket_GetVersioning(_Handle, &OutResultRaw));
	return (TSBAWSS3BucketVersioning)OutResultRaw;
}

SB_INLINE void TElAWSS3DataStorageBucket::SetVersioning(TSBAWSS3BucketVersioning Value)
{
	SBCheckError(TElAWSS3DataStorageBucket_SetVersioning(_Handle, (TSBAWSS3BucketVersioningRaw)Value));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorageBucket::GetNotificationConfiguration(TStringList &Topics, TStringList &Events)
{
	SBCheckError(TElAWSS3DataStorageBucket_GetNotificationConfiguration(_Handle, Topics.getHandle(), Events.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageBucket::GetNotificationConfiguration(TStringList *Topics, TStringList *Events)
{
	SBCheckError(TElAWSS3DataStorageBucket_GetNotificationConfiguration(_Handle, (Topics != NULL) ? Topics->getHandle() : SB_NULL_HANDLE, (Events != NULL) ? Events->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorageBucket::GetNotificationConfiguration(TElStringList &Topics, TElStringList &Events)
{
	SBCheckError(TElAWSS3DataStorageBucket_GetNotificationConfiguration(_Handle, Topics.getHandle(), Events.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageBucket::GetNotificationConfiguration(TElStringList *Topics, TElStringList *Events)
{
	SBCheckError(TElAWSS3DataStorageBucket_GetNotificationConfiguration(_Handle, (Topics != NULL) ? Topics->getHandle() : SB_NULL_HANDLE, (Events != NULL) ? Events->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElAWSS3DataStorageBucket::SetNotificationConfiguration(TStringList &Topics, TStringList &Events)
{
	SBCheckError(TElAWSS3DataStorageBucket_SetNotificationConfiguration(_Handle, Topics.getHandle(), Events.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageBucket::SetNotificationConfiguration(TStringList *Topics, TStringList *Events)
{
	SBCheckError(TElAWSS3DataStorageBucket_SetNotificationConfiguration(_Handle, (Topics != NULL) ? Topics->getHandle() : SB_NULL_HANDLE, (Events != NULL) ? Events->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElAWSS3DataStorageBucket::SetNotificationConfiguration(TElStringList &Topics, TElStringList &Events)
{
	SBCheckError(TElAWSS3DataStorageBucket_SetNotificationConfiguration(_Handle, Topics.getHandle(), Events.getHandle()));
}

SB_INLINE void TElAWSS3DataStorageBucket::SetNotificationConfiguration(TElStringList *Topics, TElStringList *Events)
{
	SBCheckError(TElAWSS3DataStorageBucket_SetNotificationConfiguration(_Handle, (Topics != NULL) ? Topics->getHandle() : SB_NULL_HANDLE, (Events != NULL) ? Events->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElAWSS3DataStorageBucket::GetWebSiteConfiguration(std::string &IndexDocument, std::string &ErrorDocument)
{
	int32_t szIndexDocument = (int32_t)IndexDocument.length();
	int32_t szErrorDocument = (int32_t)ErrorDocument.length();
	uint32_t _err = TElAWSS3DataStorageBucket_GetWebSiteConfiguration(_Handle, (char *)IndexDocument.data(), &szIndexDocument, (char *)ErrorDocument.data(), &szErrorDocument);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		IndexDocument.resize(szIndexDocument);
		SBCheckError(SBGetLastReturnStringA(-1573049520, 1, (char *)IndexDocument.data(), &szIndexDocument));
		ErrorDocument.resize(szErrorDocument);
		SBCheckError(SBGetLastReturnStringA(-1573049520, 2, (char *)ErrorDocument.data(), &szErrorDocument));
	}
	else
		SBCheckError(_err);

	IndexDocument.resize(szIndexDocument);
	ErrorDocument.resize(szErrorDocument);
}

SB_INLINE void TElAWSS3DataStorageBucket::SetWebSiteConfiguration(const std::string &IndexDocument, const std::string &ErrorDocument)
{
	SBCheckError(TElAWSS3DataStorageBucket_SetWebSiteConfiguration(_Handle, IndexDocument.data(), (int32_t)IndexDocument.length(), ErrorDocument.data(), (int32_t)ErrorDocument.length()));
}

SB_INLINE void TElAWSS3DataStorageBucket::DeleteWebSiteConfiguration()
{
	SBCheckError(TElAWSS3DataStorageBucket_DeleteWebSiteConfiguration(_Handle));
}

void TElAWSS3DataStorageBucket::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorageBucket_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(89746230, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElAWSS3DataStorageBucket::get_CreationDate()
{
	int64_t OutResult;
	SBCheckError(TElAWSS3DataStorageBucket_get_CreationDate(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElAWSS3DataStorageBucket::get_CustomHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAWSS3DataStorageBucket_get_CustomHeaders(_Handle, &hOutResult));
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
TElStringList* TElAWSS3DataStorageBucket::get_CustomHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAWSS3DataStorageBucket_get_CustomHeaders(_Handle, &hOutResult));
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

void TElAWSS3DataStorageBucket::initInstances()
{
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

TElAWSS3DataStorageBucket::TElAWSS3DataStorageBucket(TElAWSS3DataStorageBucketHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElAWSS3DataStorageBucket::TElAWSS3DataStorageBucket() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAWSS3DataStorageBucket_Create(&_Handle));
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGE
TElAWSS3DataStorageBucket::TElAWSS3DataStorageBucket(TElAWSS3DataStorage &Storage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAWSS3DataStorageBucket_Create_1(Storage.getHandle(), &_Handle));
}

TElAWSS3DataStorageBucket::TElAWSS3DataStorageBucket(TElAWSS3DataStorage *Storage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAWSS3DataStorageBucket_Create_1((Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGE */

TElAWSS3DataStorageBucket::~TElAWSS3DataStorageBucket()
{
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
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKETLIST

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
TElAWSS3DataStorageBucket* TElAWSS3DataStorageBucketList::get_Buckets(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAWSS3DataStorageBucketList_get_Buckets(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Buckets)
		this->_Inst_Buckets = new TElAWSS3DataStorageBucket(hOutResult, ohFalse);
	else
		this->_Inst_Buckets->updateHandle(hOutResult);
	return this->_Inst_Buckets;
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

SB_INLINE int32_t TElAWSS3DataStorageBucketList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElAWSS3DataStorageBucketList_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElAWSS3DataStorageBucketList::get_OwnerID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorageBucketList_get_OwnerID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1327126255, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorageBucketList::get_OwnerDisplayName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAWSS3DataStorageBucketList_get_OwnerDisplayName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-175379133, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAWSS3DataStorageBucketList::initInstances()
{
#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
	this->_Inst_Buckets = NULL;
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */
}

TElAWSS3DataStorageBucketList::TElAWSS3DataStorageBucketList(TElAWSS3DataStorageBucketListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElAWSS3DataStorageBucketList::TElAWSS3DataStorageBucketList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAWSS3DataStorageBucketList_Create(&_Handle));
}

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGE
TElAWSS3DataStorageBucketList::TElAWSS3DataStorageBucketList(TElAWSS3DataStorage &Storage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAWSS3DataStorageBucketList_Create_1(Storage.getHandle(), &_Handle));
}

TElAWSS3DataStorageBucketList::TElAWSS3DataStorageBucketList(TElAWSS3DataStorage *Storage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAWSS3DataStorageBucketList_Create_1((Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGE */

TElAWSS3DataStorageBucketList::~TElAWSS3DataStorageBucketList()
{
#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
	delete this->_Inst_Buckets;
	this->_Inst_Buckets = NULL;
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */
}
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKETLIST */

#ifdef SB_USE_GLOBAL_PROCS_AWSDATASTORAGE

#ifdef SB_USE_CLASS_TELXMLDOMNODE
void GetNodeInnerXML(TElXMLDOMNode &XmlNode, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBAWSDataStorage_GetNodeInnerXML(XmlNode.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1303587692, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void GetNodeInnerXML(TElXMLDOMNode *XmlNode, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBAWSDataStorage_GetNodeInnerXML((XmlNode != NULL) ? XmlNode->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1303587692, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#endif /* SB_USE_GLOBAL_PROCS_AWSDATASTORAGE */

};	/* namespace SecureBlackbox */
