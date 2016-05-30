#include "sbdropboxdatastorage.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGE

SB_INLINE void TElDropboxDataStorage::StartAuthorization()
{
	SBCheckError(TElDropboxDataStorage_StartAuthorization(_Handle));
}

void TElDropboxDataStorage::GetAuthorizationURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_GetAuthorizationURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1804495702, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDropboxDataStorage::GetAuthorizationURL(const std::string &Callback, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_GetAuthorizationURL_1(_Handle, Callback.data(), (int32_t)Callback.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-235294303, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDropboxDataStorage::GetAuthorizationURL(const std::string &Callback, const std::string &Locale, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_GetAuthorizationURL_2(_Handle, Callback.data(), (int32_t)Callback.length(), Locale.data(), (int32_t)Locale.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1043002105, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDropboxDataStorage::RequestAccessToken()
{
	SBCheckError(TElDropboxDataStorage_RequestAccessToken(_Handle));
}

void TElDropboxDataStorage::StartAuthorization2(const std::string &RedirectURL, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_StartAuthorization2(_Handle, RedirectURL.data(), (int32_t)RedirectURL.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1134967570, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDropboxDataStorage::CompleteAuthorization2(const std::string &AuthorizationCode)
{
	SBCheckError(TElDropboxDataStorage_CompleteAuthorization2(_Handle, AuthorizationCode.data(), (int32_t)AuthorizationCode.length()));
}

SB_INLINE void TElDropboxDataStorage::CancelAuthorization2()
{
	SBCheckError(TElDropboxDataStorage_CancelAuthorization2(_Handle));
}

void TElDropboxDataStorage::GetAccountInfoStr(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_GetAccountInfoStr(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1948813338, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDropboxDataStorage::GetAccountInfoStr(const std::string &Locale, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_GetAccountInfoStr_1(_Handle, Locale.data(), (int32_t)Locale.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1017424870, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELDROPBOXACCOUNTINFO
SB_INLINE TElDropboxAccountInfoHandle TElDropboxDataStorage::GetAccountInfo()
{
	TElDropboxAccountInfoHandle OutResult;
	SBCheckError(TElDropboxDataStorage_GetAccountInfo(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDROPBOXACCOUNTINFO */

#ifdef SB_USE_CLASS_TELDROPBOXACCOUNTINFO
SB_INLINE TElDropboxAccountInfoHandle TElDropboxDataStorage::GetAccountInfo(const std::string &Locale)
{
	TElDropboxAccountInfoHandle OutResult;
	SBCheckError(TElDropboxDataStorage_GetAccountInfo_1(_Handle, Locale.data(), (int32_t)Locale.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDROPBOXACCOUNTINFO */

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
SB_INLINE TElDropboxDataStorageObjectHandle TElDropboxDataStorage::AcquireObject(const std::string &Path)
{
	TElDropboxDataStorageObjectHandle OutResult;
	SBCheckError(TElDropboxDataStorage_AcquireObject(_Handle, Path.data(), (int32_t)Path.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
SB_INLINE TElDropboxDataStorageObjectHandle TElDropboxDataStorage::AcquireObject(const std::string &Path, const std::string &Rev)
{
	TElDropboxDataStorageObjectHandle OutResult;
	SBCheckError(TElDropboxDataStorage_AcquireObject_1(_Handle, Path.data(), (int32_t)Path.length(), Rev.data(), (int32_t)Rev.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElDropboxDataStorage::List(const std::string &Path, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElDropboxDataStorage_List(_Handle, Path.data(), (int32_t)Path.length(), Objects.getHandle()));
}

SB_INLINE void TElDropboxDataStorage::List(const std::string &Path, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElDropboxDataStorage_List(_Handle, Path.data(), (int32_t)Path.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELDROPBOXDATASTORAGEOBJECT
SB_INLINE void TElDropboxDataStorage::List(TElDropboxDataStorageObject &Dir, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElDropboxDataStorage_List_1(_Handle, Dir.getHandle(), Objects.getHandle()));
}

SB_INLINE void TElDropboxDataStorage::List(TElDropboxDataStorageObject *Dir, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElDropboxDataStorage_List_1(_Handle, (Dir != NULL) ? Dir->getHandle() : SB_NULL_HANDLE, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
SB_INLINE TElDropboxDataStorageObjectHandle TElDropboxDataStorage::CreateObject(const std::string &Path)
{
	TElDropboxDataStorageObjectHandle OutResult;
	SBCheckError(TElDropboxDataStorage_CreateObject(_Handle, Path.data(), (int32_t)Path.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELDROPBOXDATASTORAGEOBJECT
SB_INLINE TElDropboxDataStorageObjectHandle TElDropboxDataStorage::CreateObject(const std::string &Path, TElCustomDataStorageSecurityHandler &Handler)
{
	TElDropboxDataStorageObjectHandle OutResult;
	SBCheckError(TElDropboxDataStorage_CreateObject_1(_Handle, Path.data(), (int32_t)Path.length(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElDropboxDataStorageObjectHandle TElDropboxDataStorage::CreateObject(const std::string &Path, TElCustomDataStorageSecurityHandler *Handler)
{
	TElDropboxDataStorageObjectHandle OutResult;
	SBCheckError(TElDropboxDataStorage_CreateObject_1(_Handle, Path.data(), (int32_t)Path.length(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELDROPBOXDATASTORAGEOBJECT */

SB_INLINE void TElDropboxDataStorage::DeleteObject(const std::string &Path)
{
	SBCheckError(TElDropboxDataStorage_DeleteObject(_Handle, Path.data(), (int32_t)Path.length()));
}

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
void TElDropboxDataStorage::DeleteObject(TElDropboxDataStorageObject &Obj)
{
	TElClassHandle hObj = Obj.getHandle();
	SBCheckError(TElDropboxDataStorage_DeleteObject_1(_Handle, &hObj));
	Obj.updateHandle(hObj);
}
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

bool TElDropboxDataStorage::ObjectExists(const std::string &Path)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDropboxDataStorage_ObjectExists(_Handle, Path.data(), (int32_t)Path.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDropboxDataStorage::ObjectExists(const std::string &Path, const std::string &Rev)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDropboxDataStorage_ObjectExists_1(_Handle, Path.data(), (int32_t)Path.length(), Rev.data(), (int32_t)Rev.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
bool TElDropboxDataStorage::ObjectExists(TElDropboxDataStorageObject &Obj)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDropboxDataStorage_ObjectExists_2(_Handle, Obj.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDropboxDataStorage::ObjectExists(TElDropboxDataStorageObject *Obj)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDropboxDataStorage_ObjectExists_2(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
SB_INLINE void TElDropboxDataStorage::RefreshObject(TElDropboxDataStorageObject &Obj)
{
	SBCheckError(TElDropboxDataStorage_RefreshObject(_Handle, Obj.getHandle()));
}

SB_INLINE void TElDropboxDataStorage::RefreshObject(TElDropboxDataStorageObject *Obj)
{
	SBCheckError(TElDropboxDataStorage_RefreshObject(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElDropboxDataStorage::WriteObject(const std::string &Path, bool Overwrite, const std::string &ParentRev, TStream &Data, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElDropboxDataStorage_WriteObject(_Handle, Path.data(), (int32_t)Path.length(), (int8_t)Overwrite, ParentRev.data(), (int32_t)ParentRev.length(), Data.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElDropboxDataStorage::WriteObject(const std::string &Path, bool Overwrite, const std::string &ParentRev, TStream *Data, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElDropboxDataStorage_WriteObject(_Handle, Path.data(), (int32_t)Path.length(), (int8_t)Overwrite, ParentRev.data(), (int32_t)ParentRev.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElDropboxDataStorage::WriteObject(const std::string &Path, TStream &Data, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElDropboxDataStorage_WriteObject_1(_Handle, Path.data(), (int32_t)Path.length(), Data.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElDropboxDataStorage::WriteObject(const std::string &Path, TStream *Data, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElDropboxDataStorage_WriteObject_1(_Handle, Path.data(), (int32_t)Path.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELDROPBOXDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElDropboxDataStorage::WriteObject(TElDropboxDataStorageObject &Obj, TStream &Data, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElDropboxDataStorage_WriteObject_2(_Handle, Obj.getHandle(), Data.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElDropboxDataStorage::WriteObject(TElDropboxDataStorageObject *Obj, TStream *Data, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElDropboxDataStorage_WriteObject_2(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELDROPBOXDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElDropboxDataStorage::ReadObject(const std::string &Path, TStream &Strm)
{
	SBCheckError(TElDropboxDataStorage_ReadObject(_Handle, Path.data(), (int32_t)Path.length(), Strm.getHandle()));
}

SB_INLINE void TElDropboxDataStorage::ReadObject(const std::string &Path, TStream *Strm)
{
	SBCheckError(TElDropboxDataStorage_ReadObject(_Handle, Path.data(), (int32_t)Path.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElDropboxDataStorage::ReadObject(const std::string &Path, const std::string &Rev, TStream &Strm)
{
	SBCheckError(TElDropboxDataStorage_ReadObject_1(_Handle, Path.data(), (int32_t)Path.length(), Rev.data(), (int32_t)Rev.length(), Strm.getHandle()));
}

SB_INLINE void TElDropboxDataStorage::ReadObject(const std::string &Path, const std::string &Rev, TStream *Strm)
{
	SBCheckError(TElDropboxDataStorage_ReadObject_1(_Handle, Path.data(), (int32_t)Path.length(), Rev.data(), (int32_t)Rev.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELDROPBOXDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElDropboxDataStorage::ReadObject(TElDropboxDataStorageObject &Obj, TStream &Strm)
{
	SBCheckError(TElDropboxDataStorage_ReadObject_2(_Handle, Obj.getHandle(), Strm.getHandle()));
}

SB_INLINE void TElDropboxDataStorage::ReadObject(TElDropboxDataStorageObject *Obj, TStream *Strm)
{
	SBCheckError(TElDropboxDataStorage_ReadObject_2(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDROPBOXDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELDROPBOXDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElDropboxDataStorage::ReadObject(TElDropboxDataStorageObject &Obj, const std::string &Rev, TStream &Strm)
{
	SBCheckError(TElDropboxDataStorage_ReadObject_3(_Handle, Obj.getHandle(), Rev.data(), (int32_t)Rev.length(), Strm.getHandle()));
}

SB_INLINE void TElDropboxDataStorage::ReadObject(TElDropboxDataStorageObject *Obj, const std::string &Rev, TStream *Strm)
{
	SBCheckError(TElDropboxDataStorage_ReadObject_3(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, Rev.data(), (int32_t)Rev.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDROPBOXDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElDropboxDataStorage::ReadBlock(const std::string &Path, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElDropboxDataStorage_ReadBlock(_Handle, Path.data(), (int32_t)Path.length(), Strm.getHandle(), Offset, Size, &Read));
}

SB_INLINE void TElDropboxDataStorage::ReadBlock(const std::string &Path, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElDropboxDataStorage_ReadBlock(_Handle, Path.data(), (int32_t)Path.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElDropboxDataStorage::ReadBlock(const std::string &Path, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, const std::string &Rev)
{
	SBCheckError(TElDropboxDataStorage_ReadBlock_1(_Handle, Path.data(), (int32_t)Path.length(), Strm.getHandle(), Offset, Size, &Read, Rev.data(), (int32_t)Rev.length()));
}

SB_INLINE void TElDropboxDataStorage::ReadBlock(const std::string &Path, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, const std::string &Rev)
{
	SBCheckError(TElDropboxDataStorage_ReadBlock_1(_Handle, Path.data(), (int32_t)Path.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read, Rev.data(), (int32_t)Rev.length()));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElDropboxDataStorage::Search(const std::string &Path, const std::string &Query, bool IncludeDeleted, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElDropboxDataStorage_Search(_Handle, Path.data(), (int32_t)Path.length(), Query.data(), (int32_t)Query.length(), (int8_t)IncludeDeleted, Objects.getHandle()));
}

SB_INLINE void TElDropboxDataStorage::Search(const std::string &Path, const std::string &Query, bool IncludeDeleted, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElDropboxDataStorage_Search(_Handle, Path.data(), (int32_t)Path.length(), Query.data(), (int32_t)Query.length(), (int8_t)IncludeDeleted, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElDropboxDataStorage::Search(const std::string &Path, const std::string &Query, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElDropboxDataStorage_Search_1(_Handle, Path.data(), (int32_t)Path.length(), Query.data(), (int32_t)Query.length(), Objects.getHandle()));
}

SB_INLINE void TElDropboxDataStorage::Search(const std::string &Path, const std::string &Query, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElDropboxDataStorage_Search_1(_Handle, Path.data(), (int32_t)Path.length(), Query.data(), (int32_t)Query.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElCustomDataStorageObjectHandle TElDropboxDataStorage::CopyObject(const std::string &SourcePath, const std::string &DestPath, TElCustomDataStorageSecurityHandler &NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElDropboxDataStorage_CopyObject(_Handle, SourcePath.data(), (int32_t)SourcePath.length(), DestPath.data(), (int32_t)DestPath.length(), NewHandler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElDropboxDataStorage::CopyObject(const std::string &SourcePath, const std::string &DestPath, TElCustomDataStorageSecurityHandler *NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElDropboxDataStorage_CopyObject(_Handle, SourcePath.data(), (int32_t)SourcePath.length(), DestPath.data(), (int32_t)DestPath.length(), (NewHandler != NULL) ? NewHandler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELDROPBOXDATASTORAGEOBJECT
SB_INLINE TElCustomDataStorageObjectHandle TElDropboxDataStorage::CopyObject(TElDropboxDataStorageObject &Obj, const std::string &DestPath, TElCustomDataStorageSecurityHandler &NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElDropboxDataStorage_CopyObject_1(_Handle, Obj.getHandle(), DestPath.data(), (int32_t)DestPath.length(), NewHandler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElDropboxDataStorage::CopyObject(TElDropboxDataStorageObject *Obj, const std::string &DestPath, TElCustomDataStorageSecurityHandler *NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElDropboxDataStorage_CopyObject_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, DestPath.data(), (int32_t)DestPath.length(), (NewHandler != NULL) ? NewHandler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElCustomDataStorageObjectHandle TElDropboxDataStorage::CopyObject(const std::string &SourcePath, const std::string &DestPath, TElCustomDataStorageSecurityHandler &NewHandler, bool AcquireObject)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElDropboxDataStorage_CopyObject_2(_Handle, SourcePath.data(), (int32_t)SourcePath.length(), DestPath.data(), (int32_t)DestPath.length(), NewHandler.getHandle(), (int8_t)AcquireObject, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElDropboxDataStorage::CopyObject(const std::string &SourcePath, const std::string &DestPath, TElCustomDataStorageSecurityHandler *NewHandler, bool AcquireObject)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElDropboxDataStorage_CopyObject_2(_Handle, SourcePath.data(), (int32_t)SourcePath.length(), DestPath.data(), (int32_t)DestPath.length(), (NewHandler != NULL) ? NewHandler->getHandle() : SB_NULL_HANDLE, (int8_t)AcquireObject, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELDROPBOXDATASTORAGEOBJECT
SB_INLINE TElCustomDataStorageObjectHandle TElDropboxDataStorage::CopyObject(TElDropboxDataStorageObject &Obj, const std::string &DestPath, TElCustomDataStorageSecurityHandler &NewHandler, bool AcquireObject)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElDropboxDataStorage_CopyObject_3(_Handle, Obj.getHandle(), DestPath.data(), (int32_t)DestPath.length(), NewHandler.getHandle(), (int8_t)AcquireObject, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElDropboxDataStorage::CopyObject(TElDropboxDataStorageObject *Obj, const std::string &DestPath, TElCustomDataStorageSecurityHandler *NewHandler, bool AcquireObject)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElDropboxDataStorage_CopyObject_3(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, DestPath.data(), (int32_t)DestPath.length(), (NewHandler != NULL) ? NewHandler->getHandle() : SB_NULL_HANDLE, (int8_t)AcquireObject, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElCustomDataStorageObjectHandle TElDropboxDataStorage::CopyObjectFromRef(const std::string &CopyRef, const std::string &DestPath, TElCustomDataStorageSecurityHandler &NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElDropboxDataStorage_CopyObjectFromRef(_Handle, CopyRef.data(), (int32_t)CopyRef.length(), DestPath.data(), (int32_t)DestPath.length(), NewHandler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElDropboxDataStorage::CopyObjectFromRef(const std::string &CopyRef, const std::string &DestPath, TElCustomDataStorageSecurityHandler *NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElDropboxDataStorage_CopyObjectFromRef(_Handle, CopyRef.data(), (int32_t)CopyRef.length(), DestPath.data(), (int32_t)DestPath.length(), (NewHandler != NULL) ? NewHandler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElCustomDataStorageObjectHandle TElDropboxDataStorage::CopyObjectFromRef(const std::string &CopyRef, const std::string &DestPath, TElCustomDataStorageSecurityHandler &NewHandler, bool AcquireObject)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElDropboxDataStorage_CopyObjectFromRef_1(_Handle, CopyRef.data(), (int32_t)CopyRef.length(), DestPath.data(), (int32_t)DestPath.length(), NewHandler.getHandle(), (int8_t)AcquireObject, &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElDropboxDataStorage::CopyObjectFromRef(const std::string &CopyRef, const std::string &DestPath, TElCustomDataStorageSecurityHandler *NewHandler, bool AcquireObject)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElDropboxDataStorage_CopyObjectFromRef_1(_Handle, CopyRef.data(), (int32_t)CopyRef.length(), DestPath.data(), (int32_t)DestPath.length(), (NewHandler != NULL) ? NewHandler->getHandle() : SB_NULL_HANDLE, (int8_t)AcquireObject, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

void TElDropboxDataStorage::CreateCopyReference(const std::string &Path, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_CreateCopyReference(_Handle, Path.data(), (int32_t)Path.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1952279600, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
void TElDropboxDataStorage::CreateCopyReference(TElDropboxDataStorageObject &Obj, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_CreateCopyReference_1(_Handle, Obj.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1297178625, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDropboxDataStorage::CreateCopyReference(TElDropboxDataStorageObject *Obj, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_CreateCopyReference_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1297178625, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

void TElDropboxDataStorage::GetDirectLink(const std::string &Path, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_GetDirectLink(_Handle, Path.data(), (int32_t)Path.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(494592404, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
void TElDropboxDataStorage::GetDirectLink(TElDropboxDataStorageObject &Obj, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_GetDirectLink_1(_Handle, Obj.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-692974712, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDropboxDataStorage::GetDirectLink(TElDropboxDataStorageObject *Obj, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_GetDirectLink_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-692974712, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

void TElDropboxDataStorage::GetPreviewLink(const std::string &Path, bool Short, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_GetPreviewLink(_Handle, Path.data(), (int32_t)Path.length(), (int8_t)Short, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-563713125, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
void TElDropboxDataStorage::GetPreviewLink(TElDropboxDataStorageObject &Obj, bool Short, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_GetPreviewLink_1(_Handle, Obj.getHandle(), (int8_t)Short, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(820585221, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDropboxDataStorage::GetPreviewLink(TElDropboxDataStorageObject *Obj, bool Short, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_GetPreviewLink_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (int8_t)Short, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(820585221, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElDropboxDataStorage::GetThumbnail(const std::string &Path, const std::string &ImageFormat, TSBDropboxImageSize Size, TStream &Stream)
{
	SBCheckError(TElDropboxDataStorage_GetThumbnail(_Handle, Path.data(), (int32_t)Path.length(), ImageFormat.data(), (int32_t)ImageFormat.length(), (TSBDropboxImageSizeRaw)Size, Stream.getHandle()));
}

SB_INLINE void TElDropboxDataStorage::GetThumbnail(const std::string &Path, const std::string &ImageFormat, TSBDropboxImageSize Size, TStream *Stream)
{
	SBCheckError(TElDropboxDataStorage_GetThumbnail(_Handle, Path.data(), (int32_t)Path.length(), ImageFormat.data(), (int32_t)ImageFormat.length(), (TSBDropboxImageSizeRaw)Size, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELDROPBOXDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElDropboxDataStorage::GetThumbnail(TElDropboxDataStorageObject &Obj, const std::string &Format, TSBDropboxImageSize Size, TStream &Stream)
{
	SBCheckError(TElDropboxDataStorage_GetThumbnail_1(_Handle, Obj.getHandle(), Format.data(), (int32_t)Format.length(), (TSBDropboxImageSizeRaw)Size, Stream.getHandle()));
}

SB_INLINE void TElDropboxDataStorage::GetThumbnail(TElDropboxDataStorageObject *Obj, const std::string &Format, TSBDropboxImageSize Size, TStream *Stream)
{
	SBCheckError(TElDropboxDataStorage_GetThumbnail_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, Format.data(), (int32_t)Format.length(), (TSBDropboxImageSizeRaw)Size, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDROPBOXDATASTORAGEOBJECT_AND_TSTREAM */

SB_INLINE void TElDropboxDataStorage::CreateFolder(const std::string &Path)
{
	SBCheckError(TElDropboxDataStorage_CreateFolder(_Handle, Path.data(), (int32_t)Path.length()));
}

SB_INLINE void TElDropboxDataStorage::RenameObject(const std::string &SourcePath, const std::string &DestPath)
{
	SBCheckError(TElDropboxDataStorage_RenameObject(_Handle, SourcePath.data(), (int32_t)SourcePath.length(), DestPath.data(), (int32_t)DestPath.length()));
}

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
SB_INLINE void TElDropboxDataStorage::RenameObject(TElDropboxDataStorageObject &Obj, const std::string &DestPath)
{
	SBCheckError(TElDropboxDataStorage_RenameObject_1(_Handle, Obj.getHandle(), DestPath.data(), (int32_t)DestPath.length()));
}

SB_INLINE void TElDropboxDataStorage::RenameObject(TElDropboxDataStorageObject *Obj, const std::string &DestPath)
{
	SBCheckError(TElDropboxDataStorage_RenameObject_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, DestPath.data(), (int32_t)DestPath.length()));
}
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
SB_INLINE TElDropboxDataStorageObjectHandle TElDropboxDataStorage::RestoreObject(const std::string &Path, const std::string &Rev)
{
	TElDropboxDataStorageObjectHandle OutResult;
	SBCheckError(TElDropboxDataStorage_RestoreObject(_Handle, Path.data(), (int32_t)Path.length(), Rev.data(), (int32_t)Rev.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
SB_INLINE TElDropboxDataStorageObjectHandle TElDropboxDataStorage::RestoreObject(const std::string &Path, const std::string &Rev, bool AcquireObject)
{
	TElDropboxDataStorageObjectHandle OutResult;
	SBCheckError(TElDropboxDataStorage_RestoreObject_1(_Handle, Path.data(), (int32_t)Path.length(), Rev.data(), (int32_t)Rev.length(), (int8_t)AcquireObject, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElDropboxDataStorage::ListRevisions(const std::string &Path, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElDropboxDataStorage_ListRevisions(_Handle, Path.data(), (int32_t)Path.length(), Objects.getHandle()));
}

SB_INLINE void TElDropboxDataStorage::ListRevisions(const std::string &Path, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElDropboxDataStorage_ListRevisions(_Handle, Path.data(), (int32_t)Path.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELDROPBOXDATASTORAGEOBJECT
SB_INLINE void TElDropboxDataStorage::ListRevisions(TElDropboxDataStorageObject &Obj, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElDropboxDataStorage_ListRevisions_1(_Handle, Obj.getHandle(), Objects.getHandle()));
}

SB_INLINE void TElDropboxDataStorage::ListRevisions(TElDropboxDataStorageObject *Obj, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElDropboxDataStorage_ListRevisions_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
TElHTTPSClient* TElDropboxDataStorage::get_HTTPClient()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDropboxDataStorage_get_HTTPClient(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HTTPClient)
		this->_Inst_HTTPClient = new TElHTTPSClient(hOutResult, ohFalse);
	else
		this->_Inst_HTTPClient->updateHandle(hOutResult);
	return this->_Inst_HTTPClient;
}

SB_INLINE void TElDropboxDataStorage::set_HTTPClient(TElHTTPSClient &Value)
{
	SBCheckError(TElDropboxDataStorage_set_HTTPClient(_Handle, Value.getHandle()));
}

SB_INLINE void TElDropboxDataStorage::set_HTTPClient(TElHTTPSClient *Value)
{
	SBCheckError(TElDropboxDataStorage_set_HTTPClient(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

void TElDropboxDataStorage::get_AccessToken(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_get_AccessToken(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(179022786, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDropboxDataStorage::set_AccessToken(const std::string &Value)
{
	SBCheckError(TElDropboxDataStorage_set_AccessToken(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDropboxDataStorage::get_AppKey(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_get_AppKey(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(171814792, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDropboxDataStorage::set_AppKey(const std::string &Value)
{
	SBCheckError(TElDropboxDataStorage_set_AppKey(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDropboxDataStorage::get_AppSecret(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_get_AppSecret(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1449592817, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDropboxDataStorage::set_AppSecret(const std::string &Value)
{
	SBCheckError(TElDropboxDataStorage_set_AppSecret(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDropboxDataStorage::get_AuthToken(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_get_AuthToken(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1133013533, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDropboxDataStorage::set_AuthToken(const std::string &Value)
{
	SBCheckError(TElDropboxDataStorage_set_AuthToken(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDropboxDataStorage::get_AuthTokenSecret(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_get_AuthTokenSecret(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1498813037, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDropboxDataStorage::set_AuthTokenSecret(const std::string &Value)
{
	SBCheckError(TElDropboxDataStorage_set_AuthTokenSecret(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDropboxDataStorage::get_Root(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_get_Root(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-137355361, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDropboxDataStorage::set_Root(const std::string &Value)
{
	SBCheckError(TElDropboxDataStorage_set_Root(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBDropboxMetadataLocation TElDropboxDataStorage::get_MetadataLocation()
{
	TSBDropboxMetadataLocationRaw OutResultRaw = 0;
	SBCheckError(TElDropboxDataStorage_get_MetadataLocation(_Handle, &OutResultRaw));
	return (TSBDropboxMetadataLocation)OutResultRaw;
}

SB_INLINE void TElDropboxDataStorage::set_MetadataLocation(TSBDropboxMetadataLocation Value)
{
	SBCheckError(TElDropboxDataStorage_set_MetadataLocation(_Handle, (TSBDropboxMetadataLocationRaw)Value));
}

void TElDropboxDataStorage::get_MetadataExtension(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_get_MetadataExtension(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(462771696, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDropboxDataStorage::set_MetadataExtension(const std::string &Value)
{
	SBCheckError(TElDropboxDataStorage_set_MetadataExtension(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDropboxDataStorage::get_MetadataDirName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_get_MetadataDirName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-728396742, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDropboxDataStorage::set_MetadataDirName(const std::string &Value)
{
	SBCheckError(TElDropboxDataStorage_set_MetadataDirName(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBDropboxSignatureMethod TElDropboxDataStorage::get_SignatureMethod()
{
	TSBDropboxSignatureMethodRaw OutResultRaw = 0;
	SBCheckError(TElDropboxDataStorage_get_SignatureMethod(_Handle, &OutResultRaw));
	return (TSBDropboxSignatureMethod)OutResultRaw;
}

SB_INLINE void TElDropboxDataStorage::set_SignatureMethod(TSBDropboxSignatureMethod Value)
{
	SBCheckError(TElDropboxDataStorage_set_SignatureMethod(_Handle, (TSBDropboxSignatureMethodRaw)Value));
}

SB_INLINE int64_t TElDropboxDataStorage::get_ChunkedUploadThreshold()
{
	int64_t OutResult;
	SBCheckError(TElDropboxDataStorage_get_ChunkedUploadThreshold(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDropboxDataStorage::set_ChunkedUploadThreshold(int64_t Value)
{
	SBCheckError(TElDropboxDataStorage_set_ChunkedUploadThreshold(_Handle, Value));
}

SB_INLINE int64_t TElDropboxDataStorage::get_ChunkedUploadChunkSize()
{
	int64_t OutResult;
	SBCheckError(TElDropboxDataStorage_get_ChunkedUploadChunkSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDropboxDataStorage::set_ChunkedUploadChunkSize(int64_t Value)
{
	SBCheckError(TElDropboxDataStorage_set_ChunkedUploadChunkSize(_Handle, Value));
}

void TElDropboxDataStorage::get_DefaultLocale(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorage_get_DefaultLocale(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2059025256, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDropboxDataStorage::set_DefaultLocale(const std::string &Value)
{
	SBCheckError(TElDropboxDataStorage_set_DefaultLocale(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElDropboxDataStorage::get_HideMetadataObjects()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDropboxDataStorage_get_HideMetadataObjects(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDropboxDataStorage::set_HideMetadataObjects(bool Value)
{
	SBCheckError(TElDropboxDataStorage_set_HideMetadataObjects(_Handle, (int8_t)Value));
}

bool TElDropboxDataStorage::get_PickMetadataOnList()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDropboxDataStorage_get_PickMetadataOnList(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDropboxDataStorage::set_PickMetadataOnList(bool Value)
{
	SBCheckError(TElDropboxDataStorage_set_PickMetadataOnList(_Handle, (int8_t)Value));
}

bool TElDropboxDataStorage::get_Overwrite()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDropboxDataStorage_get_Overwrite(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDropboxDataStorage::set_Overwrite(bool Value)
{
	SBCheckError(TElDropboxDataStorage_set_Overwrite(_Handle, (int8_t)Value));
}

bool TElDropboxDataStorage::get_PassthroughMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDropboxDataStorage_get_PassthroughMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDropboxDataStorage::set_PassthroughMode(bool Value)
{
	SBCheckError(TElDropboxDataStorage_set_PassthroughMode(_Handle, (int8_t)Value));
}

bool TElDropboxDataStorage::get_EmbeddedMetadataMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDropboxDataStorage_get_EmbeddedMetadataMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDropboxDataStorage::set_EmbeddedMetadataMode(bool Value)
{
	SBCheckError(TElDropboxDataStorage_set_EmbeddedMetadataMode(_Handle, (int8_t)Value));
}

SB_INLINE void TElDropboxDataStorage::get_OnBeforeRequestSigning(TSBDropboxBeforeRequestSigningEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElDropboxDataStorage_get_OnBeforeRequestSigning(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElDropboxDataStorage::set_OnBeforeRequestSigning(TSBDropboxBeforeRequestSigningEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElDropboxDataStorage_set_OnBeforeRequestSigning(_Handle, pMethodValue, pDataValue));
}

void TElDropboxDataStorage::initInstances()
{
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
}

TElDropboxDataStorage::TElDropboxDataStorage(TElDropboxDataStorageHandle handle, TElOwnHandle ownHandle) : TElCustomDataStorage(handle, ownHandle)
{
	initInstances();
}

TElDropboxDataStorage::TElDropboxDataStorage(TComponent &AOwner) : TElCustomDataStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDropboxDataStorage_Create(AOwner.getHandle(), &_Handle));
}

TElDropboxDataStorage::TElDropboxDataStorage(TComponent *AOwner) : TElCustomDataStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDropboxDataStorage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElDropboxDataStorage::~TElDropboxDataStorage()
{
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	delete this->_Inst_HTTPClient;
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
}
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGE */

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT

SB_INLINE void TElDropboxDataStorageObject::Assign(TElCustomDataStorageObject &Source)
{
	SBCheckError(TElDropboxDataStorageObject_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDropboxDataStorageObject::Assign(TElCustomDataStorageObject *Source)
{
	SBCheckError(TElDropboxDataStorageObject_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElCustomDataStorageObjectHandle TElDropboxDataStorageObject::Clone()
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElDropboxDataStorageObject_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDropboxDataStorageObject::Clear()
{
	SBCheckError(TElDropboxDataStorageObject_Clear(_Handle));
}

bool TElDropboxDataStorageObject::IsMetadataObject()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDropboxDataStorageObject_IsMetadataObject(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDropboxDataStorageObject::IsMetadataDirectory()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDropboxDataStorageObject_IsMetadataDirectory(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDropboxDataStorageObject::Delete()
{
	SBCheckError(TElDropboxDataStorageObject_Delete(_Handle));
}

bool TElDropboxDataStorageObject::Exists()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDropboxDataStorageObject_Exists(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDropboxDataStorageObject::Refresh()
{
	SBCheckError(TElDropboxDataStorageObject_Refresh(_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElDropboxDataStorageObject::Write(bool Overwrite, const std::string &ParentRev, TStream &Data, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElDropboxDataStorageObject_Write(_Handle, (int8_t)Overwrite, ParentRev.data(), (int32_t)ParentRev.length(), Data.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElDropboxDataStorageObject::Write(bool Overwrite, const std::string &ParentRev, TStream *Data, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElDropboxDataStorageObject_Write(_Handle, (int8_t)Overwrite, ParentRev.data(), (int32_t)ParentRev.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElDropboxDataStorageObject::Write(TStream &Data, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElDropboxDataStorageObject_Write_1(_Handle, Data.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElDropboxDataStorageObject::Write(TStream *Data, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElDropboxDataStorageObject_Write_1(_Handle, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElDropboxDataStorageObject::Read(TStream &Strm)
{
	SBCheckError(TElDropboxDataStorageObject_Read(_Handle, Strm.getHandle()));
}

SB_INLINE void TElDropboxDataStorageObject::Read(TStream *Strm)
{
	SBCheckError(TElDropboxDataStorageObject_Read(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElDropboxDataStorageObject::Read(const std::string &Rev, TStream &Strm)
{
	SBCheckError(TElDropboxDataStorageObject_Read_1(_Handle, Rev.data(), (int32_t)Rev.length(), Strm.getHandle()));
}

SB_INLINE void TElDropboxDataStorageObject::Read(const std::string &Rev, TStream *Strm)
{
	SBCheckError(TElDropboxDataStorageObject_Read_1(_Handle, Rev.data(), (int32_t)Rev.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElDropboxDataStorageObject::ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElDropboxDataStorageObject_ReadBlock(_Handle, Strm.getHandle(), Offset, Size, &Read));
}

SB_INLINE void TElDropboxDataStorageObject::ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElDropboxDataStorageObject_ReadBlock(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElCustomDataStorageObjectHandle TElDropboxDataStorageObject::Copy(const std::string &DestPath, TElCustomDataStorageSecurityHandler &NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElDropboxDataStorageObject_Copy(_Handle, DestPath.data(), (int32_t)DestPath.length(), NewHandler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElDropboxDataStorageObject::Copy(const std::string &DestPath, TElCustomDataStorageSecurityHandler *NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElDropboxDataStorageObject_Copy(_Handle, DestPath.data(), (int32_t)DestPath.length(), (NewHandler != NULL) ? NewHandler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */

void TElDropboxDataStorageObject::CreateCopyReference(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorageObject_CreateCopyReference(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1034425456, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDropboxDataStorageObject::GetDirectLink(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorageObject_GetDirectLink(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1540388836, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDropboxDataStorageObject::GetPreviewLink(bool Short, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorageObject_GetPreviewLink(_Handle, (int8_t)Short, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1292817116, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElDropboxDataStorageObject::GetThumbnail(const std::string &Format, TSBDropboxImageSize Size, TStream &Stream)
{
	SBCheckError(TElDropboxDataStorageObject_GetThumbnail(_Handle, Format.data(), (int32_t)Format.length(), (TSBDropboxImageSizeRaw)Size, Stream.getHandle()));
}

SB_INLINE void TElDropboxDataStorageObject::GetThumbnail(const std::string &Format, TSBDropboxImageSize Size, TStream *Stream)
{
	SBCheckError(TElDropboxDataStorageObject_GetThumbnail(_Handle, Format.data(), (int32_t)Format.length(), (TSBDropboxImageSizeRaw)Size, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElDropboxDataStorageObject::Rename(const std::string &DestPath)
{
	SBCheckError(TElDropboxDataStorageObject_Rename(_Handle, DestPath.data(), (int32_t)DestPath.length()));
}

SB_INLINE void TElDropboxDataStorageObject::Restore(const std::string &Rev)
{
	SBCheckError(TElDropboxDataStorageObject_Restore(_Handle, Rev.data(), (int32_t)Rev.length()));
}

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElDropboxDataStorageObject::ListRevisions(TElDataStorageObjectList &Objects)
{
	SBCheckError(TElDropboxDataStorageObject_ListRevisions(_Handle, Objects.getHandle()));
}

SB_INLINE void TElDropboxDataStorageObject::ListRevisions(TElDataStorageObjectList *Objects)
{
	SBCheckError(TElDropboxDataStorageObject_ListRevisions(_Handle, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

void TElDropboxDataStorageObject::get_Path(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorageObject_get_Path(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1286611438, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDropboxDataStorageObject::get_Locale(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorageObject_get_Locale(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1899961304, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDropboxDataStorageObject::get_Rev(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorageObject_get_Rev(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1356316687, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDropboxDataStorageObject::get_SizeStr(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorageObject_get_SizeStr(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-272524850, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElDropboxDataStorageObject::get_ThumbExists()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDropboxDataStorageObject_get_ThumbExists(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int64_t TElDropboxDataStorageObject::get_Size()
{
	int64_t OutResult;
	SBCheckError(TElDropboxDataStorageObject_get_Size(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElDropboxDataStorageObject::get_Modified()
{
	int64_t OutResult;
	SBCheckError(TElDropboxDataStorageObject_get_Modified(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElDropboxDataStorageObject::get_ClientModified()
{
	int64_t OutResult;
	SBCheckError(TElDropboxDataStorageObject_get_ClientModified(_Handle, &OutResult));
	return OutResult;
}

bool TElDropboxDataStorageObject::get_Directory()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDropboxDataStorageObject_get_Directory(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElDropboxDataStorageObject::get_Icon(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorageObject_get_Icon(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(577798970, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDropboxDataStorageObject::get_Root(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorageObject_get_Root(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1360024506, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDropboxDataStorageObject::get_MimeType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorageObject_get_MimeType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1859099733, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElDropboxDataStorageObject::get_Revision()
{
	int64_t OutResult;
	SBCheckError(TElDropboxDataStorageObject_get_Revision(_Handle, &OutResult));
	return OutResult;
}

bool TElDropboxDataStorageObject::get_IsDeleted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDropboxDataStorageObject_get_IsDeleted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElDropboxDataStorageObject::get_Hash(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxDataStorageObject_get_Hash(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1772304295, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElDropboxDataStorageObject::get_Listed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDropboxDataStorageObject_get_Listed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TElDropboxDataStorageObject* TElDropboxDataStorageObject::get_Objects(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDropboxDataStorageObject_get_Objects(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Objects)
		this->_Inst_Objects = new TElDropboxDataStorageObject(hOutResult, ohFalse);
	else
		this->_Inst_Objects->updateHandle(hOutResult);
	return this->_Inst_Objects;
}

SB_INLINE int32_t TElDropboxDataStorageObject::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElDropboxDataStorageObject_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElDropboxDataStorageObject::initInstances()
{
	this->_Inst_Objects = NULL;
}

TElDropboxDataStorageObject::TElDropboxDataStorageObject(TElDropboxDataStorageObjectHandle handle, TElOwnHandle ownHandle) : TElCustomDataStorageObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGE
TElDropboxDataStorageObject::TElDropboxDataStorageObject(TElDropboxDataStorage &Owner) : TElCustomDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDropboxDataStorageObject_Create(Owner.getHandle(), &_Handle));
}

TElDropboxDataStorageObject::TElDropboxDataStorageObject(TElDropboxDataStorage *Owner) : TElCustomDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDropboxDataStorageObject_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGE */

TElDropboxDataStorageObject::~TElDropboxDataStorageObject()
{
	delete this->_Inst_Objects;
	this->_Inst_Objects = NULL;
}
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDROPBOXACCOUNTINFO

void TElDropboxAccountInfo::get_DisplayName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxAccountInfo_get_DisplayName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(605291329, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElDropboxAccountInfo::get_UID()
{
	int64_t OutResult;
	SBCheckError(TElDropboxAccountInfo_get_UID(_Handle, &OutResult));
	return OutResult;
}

void TElDropboxAccountInfo::get_Country(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxAccountInfo_get_Country(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-41320254, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDropboxAccountInfo::get_ReferralLink(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDropboxAccountInfo_get_ReferralLink(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-933882448, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElDropboxAccountInfo::get_QuotaAvailable()
{
	int64_t OutResult;
	SBCheckError(TElDropboxAccountInfo_get_QuotaAvailable(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElDropboxAccountInfo::get_RegularFiles()
{
	int64_t OutResult;
	SBCheckError(TElDropboxAccountInfo_get_RegularFiles(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElDropboxAccountInfo::get_SharedFiles()
{
	int64_t OutResult;
	SBCheckError(TElDropboxAccountInfo_get_SharedFiles(_Handle, &OutResult));
	return OutResult;
}

TElDropboxAccountInfo::TElDropboxAccountInfo(TElDropboxAccountInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElDropboxAccountInfo::TElDropboxAccountInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDropboxAccountInfo_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDROPBOXACCOUNTINFO */

};	/* namespace SecureBlackbox */

