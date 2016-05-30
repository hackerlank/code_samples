#include "sbgoogledrivedatastorage.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE

void TElGoogleDriveDataStorage::StartAuthorization(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveDataStorage_StartAuthorization(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1867284013, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGoogleDriveDataStorage::CompleteAuthorization(const std::string &AuthorizationCode)
{
	SBCheckError(TElGoogleDriveDataStorage_CompleteAuthorization(_Handle, AuthorizationCode.data(), (int32_t)AuthorizationCode.length()));
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
SB_INLINE TElGoogleDriveDataStorageObjectHandle TElGoogleDriveDataStorage::AcquireObject(const std::string &ObjectID)
{
	TElGoogleDriveDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDriveDataStorage_AcquireObject(_Handle, ObjectID.data(), (int32_t)ObjectID.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

SB_INLINE void TElGoogleDriveDataStorage::CloseSession()
{
	SBCheckError(TElGoogleDriveDataStorage_CloseSession(_Handle));
}

#ifdef SB_USE_CLASSES_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TELGOOGLEDRIVEFOLDER
SB_INLINE TElGoogleDriveDataStorageObjectHandle TElGoogleDriveDataStorage::CopyObject(TElGoogleDriveDataStorageObject &Obj, TElGoogleDriveFolder &Destination)
{
	TElGoogleDriveDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDriveDataStorage_CopyObject(_Handle, Obj.getHandle(), Destination.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElGoogleDriveDataStorageObjectHandle TElGoogleDriveDataStorage::CopyObject(TElGoogleDriveDataStorageObject *Obj, TElGoogleDriveFolder *Destination)
{
	TElGoogleDriveDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDriveDataStorage_CopyObject(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TELGOOGLEDRIVEFOLDER */

#ifdef SB_USE_CLASSES_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TELGOOGLEDRIVEFOLDER
SB_INLINE TElGoogleDriveDataStorageObjectHandle TElGoogleDriveDataStorage::CopyObject(TElGoogleDriveDataStorageObject &Obj, const std::string &NewName, const std::string &NewDescription, TElGoogleDriveFolder &Destination)
{
	TElGoogleDriveDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDriveDataStorage_CopyObject_1(_Handle, Obj.getHandle(), NewName.data(), (int32_t)NewName.length(), NewDescription.data(), (int32_t)NewDescription.length(), Destination.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElGoogleDriveDataStorageObjectHandle TElGoogleDriveDataStorage::CopyObject(TElGoogleDriveDataStorageObject *Obj, const std::string &NewName, const std::string &NewDescription, TElGoogleDriveFolder *Destination)
{
	TElGoogleDriveDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDriveDataStorage_CopyObject_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, NewName.data(), (int32_t)NewName.length(), NewDescription.data(), (int32_t)NewDescription.length(), (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TELGOOGLEDRIVEFOLDER */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEFOLDER
SB_INLINE TElGoogleDriveFolderHandle TElGoogleDriveDataStorage::CreateFolder(TElGoogleDriveFolder &AParent, const std::string &AName, const std::string &ADescription)
{
	TElGoogleDriveFolderHandle OutResult;
	SBCheckError(TElGoogleDriveDataStorage_CreateFolder(_Handle, AParent.getHandle(), AName.data(), (int32_t)AName.length(), ADescription.data(), (int32_t)ADescription.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElGoogleDriveFolderHandle TElGoogleDriveDataStorage::CreateFolder(TElGoogleDriveFolder *AParent, const std::string &AName, const std::string &ADescription)
{
	TElGoogleDriveFolderHandle OutResult;
	SBCheckError(TElGoogleDriveDataStorage_CreateFolder(_Handle, (AParent != NULL) ? AParent->getHandle() : SB_NULL_HANDLE, AName.data(), (int32_t)AName.length(), ADescription.data(), (int32_t)ADescription.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEFOLDER */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TELGOOGLEDRIVEFOLDER
SB_INLINE TElGoogleDriveDataStorageObjectHandle TElGoogleDriveDataStorage::CreateObject(TElGoogleDriveFolder &AParent, const std::string &AName, const std::string &ADescription, const std::string &AMimeType, bool AHidden, bool ARestricted, bool AStarred, TElCustomDataStorageSecurityHandler &Handler)
{
	TElGoogleDriveDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDriveDataStorage_CreateObject(_Handle, AParent.getHandle(), AName.data(), (int32_t)AName.length(), ADescription.data(), (int32_t)ADescription.length(), AMimeType.data(), (int32_t)AMimeType.length(), (int8_t)AHidden, (int8_t)ARestricted, (int8_t)AStarred, Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElGoogleDriveDataStorageObjectHandle TElGoogleDriveDataStorage::CreateObject(TElGoogleDriveFolder *AParent, const std::string &AName, const std::string &ADescription, const std::string &AMimeType, bool AHidden, bool ARestricted, bool AStarred, TElCustomDataStorageSecurityHandler *Handler)
{
	TElGoogleDriveDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDriveDataStorage_CreateObject(_Handle, (AParent != NULL) ? AParent->getHandle() : SB_NULL_HANDLE, AName.data(), (int32_t)AName.length(), ADescription.data(), (int32_t)ADescription.length(), AMimeType.data(), (int32_t)AMimeType.length(), (int8_t)AHidden, (int8_t)ARestricted, (int8_t)AStarred, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TELGOOGLEDRIVEFOLDER */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEACCOUNTINFO
SB_INLINE TElGoogleDriveAccountInfoHandle TElGoogleDriveDataStorage::GetAccountInfo()
{
	TElGoogleDriveAccountInfoHandle OutResult;
	SBCheckError(TElGoogleDriveDataStorage_GetAccountInfo(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEACCOUNTINFO */

#ifdef SB_USE_CLASSES_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TSTREAM
bool TElGoogleDriveDataStorage::GetObjectThumbnail(TElGoogleDriveDataStorageObject &Obj, TStream &Stream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveDataStorage_GetObjectThumbnail(_Handle, Obj.getHandle(), Stream.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGoogleDriveDataStorage::GetObjectThumbnail(TElGoogleDriveDataStorageObject *Obj, TStream *Stream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveDataStorage_GetObjectThumbnail(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELGOOGLEDRIVEFOLDER
SB_INLINE void TElGoogleDriveDataStorage::List(TElGoogleDriveFolder &Folder, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElGoogleDriveDataStorage_List(_Handle, Folder.getHandle(), Objects.getHandle()));
}

SB_INLINE void TElGoogleDriveDataStorage::List(TElGoogleDriveFolder *Folder, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElGoogleDriveDataStorage_List(_Handle, (Folder != NULL) ? Folder->getHandle() : SB_NULL_HANDLE, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELGOOGLEDRIVEFOLDER */

#ifdef SB_USE_CLASSES_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TELGOOGLEDRIVEFOLDER
SB_INLINE void TElGoogleDriveDataStorage::MoveObject(TElGoogleDriveDataStorageObject &Obj, TElGoogleDriveFolder &Destination)
{
	SBCheckError(TElGoogleDriveDataStorage_MoveObject(_Handle, Obj.getHandle(), Destination.getHandle()));
}

SB_INLINE void TElGoogleDriveDataStorage::MoveObject(TElGoogleDriveDataStorageObject *Obj, TElGoogleDriveFolder *Destination)
{
	SBCheckError(TElGoogleDriveDataStorage_MoveObject(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TELGOOGLEDRIVEFOLDER */

#ifdef SB_USE_CLASSES_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TELGOOGLEDRIVEFOLDER
SB_INLINE void TElGoogleDriveDataStorage::MoveObject(TElGoogleDriveDataStorageObject &Obj, const std::vector<TElGoogleDriveFolderHandle> &Destinations)
{
	SBCheckError(TElGoogleDriveDataStorage_MoveObject_1(_Handle, Obj.getHandle(), SB_STD_VECTOR_FRONT_ADR(Destinations), (int32_t)Destinations.size()));
}

SB_INLINE void TElGoogleDriveDataStorage::MoveObject(TElGoogleDriveDataStorageObject *Obj, const std::vector<TElGoogleDriveFolderHandle> &Destinations)
{
	SBCheckError(TElGoogleDriveDataStorage_MoveObject_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Destinations), (int32_t)Destinations.size()));
}
#endif /* SB_USE_CLASSES_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TELGOOGLEDRIVEFOLDER */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
SB_INLINE void TElGoogleDriveDataStorage::RenameObject(TElGoogleDriveDataStorageObject &Obj, const std::string &NewName)
{
	SBCheckError(TElGoogleDriveDataStorage_RenameObject(_Handle, Obj.getHandle(), NewName.data(), (int32_t)NewName.length()));
}

SB_INLINE void TElGoogleDriveDataStorage::RenameObject(TElGoogleDriveDataStorageObject *Obj, const std::string &NewName)
{
	SBCheckError(TElGoogleDriveDataStorage_RenameObject(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, NewName.data(), (int32_t)NewName.length()));
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElGoogleDriveDataStorage::Search(const std::string &Query, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElGoogleDriveDataStorage_Search(_Handle, Query.data(), (int32_t)Query.length(), Objects.getHandle()));
}

SB_INLINE void TElGoogleDriveDataStorage::Search(const std::string &Query, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElGoogleDriveDataStorage_Search(_Handle, Query.data(), (int32_t)Query.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

void TElGoogleDriveDataStorage::get_AccessToken(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveDataStorage_get_AccessToken(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-320039997, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElGoogleDriveDataStorage::get_ChunkedUploadChunkSize()
{
	int64_t OutResult;
	SBCheckError(TElGoogleDriveDataStorage_get_ChunkedUploadChunkSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGoogleDriveDataStorage::set_ChunkedUploadChunkSize(int64_t Value)
{
	SBCheckError(TElGoogleDriveDataStorage_set_ChunkedUploadChunkSize(_Handle, Value));
}

SB_INLINE int64_t TElGoogleDriveDataStorage::get_ChunkedUploadThreshold()
{
	int64_t OutResult;
	SBCheckError(TElGoogleDriveDataStorage_get_ChunkedUploadThreshold(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGoogleDriveDataStorage::set_ChunkedUploadThreshold(int64_t Value)
{
	SBCheckError(TElGoogleDriveDataStorage_set_ChunkedUploadThreshold(_Handle, Value));
}

void TElGoogleDriveDataStorage::get_ClientID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveDataStorage_get_ClientID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1097659524, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGoogleDriveDataStorage::set_ClientID(const std::string &Value)
{
	SBCheckError(TElGoogleDriveDataStorage_set_ClientID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElGoogleDriveDataStorage::get_ClientSecret(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveDataStorage_get_ClientSecret(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2005747344, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGoogleDriveDataStorage::set_ClientSecret(const std::string &Value)
{
	SBCheckError(TElGoogleDriveDataStorage_set_ClientSecret(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
TElHTTPSClient* TElGoogleDriveDataStorage::get_HTTPClient()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDriveDataStorage_get_HTTPClient(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HTTPClient)
		this->_Inst_HTTPClient = new TElHTTPSClient(hOutResult, ohFalse);
	else
		this->_Inst_HTTPClient->updateHandle(hOutResult);
	return this->_Inst_HTTPClient;
}

SB_INLINE void TElGoogleDriveDataStorage::set_HTTPClient(TElHTTPSClient &Value)
{
	SBCheckError(TElGoogleDriveDataStorage_set_HTTPClient(_Handle, Value.getHandle()));
}

SB_INLINE void TElGoogleDriveDataStorage::set_HTTPClient(TElHTTPSClient *Value)
{
	SBCheckError(TElGoogleDriveDataStorage_set_HTTPClient(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

bool TElGoogleDriveDataStorage::get_PassthroughMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveDataStorage_get_PassthroughMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGoogleDriveDataStorage::set_PassthroughMode(bool Value)
{
	SBCheckError(TElGoogleDriveDataStorage_set_PassthroughMode(_Handle, (int8_t)Value));
}

bool TElGoogleDriveDataStorage::get_ReadOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveDataStorage_get_ReadOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGoogleDriveDataStorage::set_ReadOnly(bool Value)
{
	SBCheckError(TElGoogleDriveDataStorage_set_ReadOnly(_Handle, (int8_t)Value));
}

void TElGoogleDriveDataStorage::get_RedirectURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveDataStorage_get_RedirectURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1767591608, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGoogleDriveDataStorage::set_RedirectURL(const std::string &Value)
{
	SBCheckError(TElGoogleDriveDataStorage_set_RedirectURL(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElGoogleDriveDataStorage::get_RefreshToken(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveDataStorage_get_RefreshToken(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1822766862, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGoogleDriveDataStorage::set_RefreshToken(const std::string &Value)
{
	SBCheckError(TElGoogleDriveDataStorage_set_RefreshToken(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBGoogleDriveRoot TElGoogleDriveDataStorage::get_Root()
{
	TSBGoogleDriveRootRaw OutResultRaw = 0;
	SBCheckError(TElGoogleDriveDataStorage_get_Root(_Handle, &OutResultRaw));
	return (TSBGoogleDriveRoot)OutResultRaw;
}

SB_INLINE void TElGoogleDriveDataStorage::set_Root(TSBGoogleDriveRoot Value)
{
	SBCheckError(TElGoogleDriveDataStorage_set_Root(_Handle, (TSBGoogleDriveRootRaw)Value));
}

bool TElGoogleDriveDataStorage::get_UpdateViewedDateOnAcquire()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveDataStorage_get_UpdateViewedDateOnAcquire(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGoogleDriveDataStorage::set_UpdateViewedDateOnAcquire(bool Value)
{
	SBCheckError(TElGoogleDriveDataStorage_set_UpdateViewedDateOnAcquire(_Handle, (int8_t)Value));
}

bool TElGoogleDriveDataStorage::get_UpdateViewedDateOnWrite()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveDataStorage_get_UpdateViewedDateOnWrite(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGoogleDriveDataStorage::set_UpdateViewedDateOnWrite(bool Value)
{
	SBCheckError(TElGoogleDriveDataStorage_set_UpdateViewedDateOnWrite(_Handle, (int8_t)Value));
}

bool TElGoogleDriveDataStorage::get_UseETags()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveDataStorage_get_UseETags(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGoogleDriveDataStorage::set_UseETags(bool Value)
{
	SBCheckError(TElGoogleDriveDataStorage_set_UseETags(_Handle, (int8_t)Value));
}

bool TElGoogleDriveDataStorage::get_UsePatchMethod()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveDataStorage_get_UsePatchMethod(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGoogleDriveDataStorage::set_UsePatchMethod(bool Value)
{
	SBCheckError(TElGoogleDriveDataStorage_set_UsePatchMethod(_Handle, (int8_t)Value));
}

void TElGoogleDriveDataStorage::initInstances()
{
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
}

TElGoogleDriveDataStorage::TElGoogleDriveDataStorage(TElGoogleDriveDataStorageHandle handle, TElOwnHandle ownHandle) : TElCustomDataStorage(handle, ownHandle)
{
	initInstances();
}

TElGoogleDriveDataStorage::TElGoogleDriveDataStorage(TComponent &AOwner) : TElCustomDataStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDriveDataStorage_Create(AOwner.getHandle(), &_Handle));
}

TElGoogleDriveDataStorage::TElGoogleDriveDataStorage(TComponent *AOwner) : TElCustomDataStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDriveDataStorage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElGoogleDriveDataStorage::~TElGoogleDriveDataStorage()
{
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	delete this->_Inst_HTTPClient;
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT

SB_INLINE void TElGoogleDriveDataStorageObject::Assign(TElCustomDataStorageObject &Source)
{
	SBCheckError(TElGoogleDriveDataStorageObject_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElGoogleDriveDataStorageObject::Assign(TElCustomDataStorageObject *Source)
{
	SBCheckError(TElGoogleDriveDataStorageObject_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElGoogleDriveDataStorageObject::Clear()
{
	SBCheckError(TElGoogleDriveDataStorageObject_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEFOLDER
SB_INLINE TElGoogleDriveDataStorageObjectHandle TElGoogleDriveDataStorageObject::Copy(TElGoogleDriveFolder &Destination)
{
	TElGoogleDriveDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDriveDataStorageObject_Copy(_Handle, Destination.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElGoogleDriveDataStorageObjectHandle TElGoogleDriveDataStorageObject::Copy(TElGoogleDriveFolder *Destination)
{
	TElGoogleDriveDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDriveDataStorageObject_Copy(_Handle, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEFOLDER */

SB_INLINE void TElGoogleDriveDataStorageObject::Delete()
{
	SBCheckError(TElGoogleDriveDataStorageObject_Delete(_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
bool TElGoogleDriveDataStorageObject::GetThumbnail(TStream &Stream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveDataStorageObject_GetThumbnail(_Handle, Stream.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGoogleDriveDataStorageObject::GetThumbnail(TStream *Stream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveDataStorageObject_GetThumbnail(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEFOLDER
SB_INLINE void TElGoogleDriveDataStorageObject::Move(TElGoogleDriveFolder &Destination)
{
	SBCheckError(TElGoogleDriveDataStorageObject_Move(_Handle, Destination.getHandle()));
}

SB_INLINE void TElGoogleDriveDataStorageObject::Move(TElGoogleDriveFolder *Destination)
{
	SBCheckError(TElGoogleDriveDataStorageObject_Move(_Handle, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEFOLDER */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEFOLDER
SB_INLINE void TElGoogleDriveDataStorageObject::Move(const std::vector<TElGoogleDriveFolderHandle> &Destinations)
{
	SBCheckError(TElGoogleDriveDataStorageObject_Move_1(_Handle, SB_STD_VECTOR_FRONT_ADR(Destinations), (int32_t)Destinations.size()));
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEFOLDER */

SB_INLINE void TElGoogleDriveDataStorageObject::Refresh(bool UpdateViewedDate)
{
	SBCheckError(TElGoogleDriveDataStorageObject_Refresh(_Handle, (int8_t)UpdateViewedDate));
}

SB_INLINE void TElGoogleDriveDataStorageObject::Rename(const std::string &NewName)
{
	SBCheckError(TElGoogleDriveDataStorageObject_Rename(_Handle, NewName.data(), (int32_t)NewName.length()));
}

SB_INLINE void TElGoogleDriveDataStorageObject::Touch()
{
	SBCheckError(TElGoogleDriveDataStorageObject_Touch(_Handle));
}

SB_INLINE void TElGoogleDriveDataStorageObject::Trash()
{
	SBCheckError(TElGoogleDriveDataStorageObject_Trash(_Handle));
}

SB_INLINE void TElGoogleDriveDataStorageObject::Untrash()
{
	SBCheckError(TElGoogleDriveDataStorageObject_Untrash(_Handle));
}

void TElGoogleDriveDataStorageObject::get_AlternateLink(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveDataStorageObject_get_AlternateLink(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1067903925, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElGoogleDriveDataStorageObject::get_AppDataContents()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveDataStorageObject_get_AppDataContents(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENTS
TElGoogleDriveComments* TElGoogleDriveDataStorageObject::get_Comments()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDriveDataStorageObject_get_Comments(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Comments)
		this->_Inst_Comments = new TElGoogleDriveComments(hOutResult, ohFalse);
	else
		this->_Inst_Comments->updateHandle(hOutResult);
	return this->_Inst_Comments;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENTS */

SB_INLINE int64_t TElGoogleDriveDataStorageObject::get_CreatedDate()
{
	int64_t OutResult;
	SBCheckError(TElGoogleDriveDataStorageObject_get_CreatedDate(_Handle, &OutResult));
	return OutResult;
}

void TElGoogleDriveDataStorageObject::get_Description(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveDataStorageObject_get_Description(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-940642916, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGoogleDriveDataStorageObject::set_Description(const std::string &Value)
{
	SBCheckError(TElGoogleDriveDataStorageObject_set_Description(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElGoogleDriveDataStorageObject::get_Editable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveDataStorageObject_get_Editable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElGoogleDriveDataStorageObject::get_ETag(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveDataStorageObject_get_ETag(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1967564046, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElGoogleDriveDataStorageObject::get_ExplicitlyTrashed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveDataStorageObject_get_ExplicitlyTrashed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGoogleDriveDataStorageObject::get_Hidden()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveDataStorageObject_get_Hidden(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGoogleDriveDataStorageObject::set_Hidden(bool Value)
{
	SBCheckError(TElGoogleDriveDataStorageObject_set_Hidden(_Handle, (int8_t)Value));
}

void TElGoogleDriveDataStorageObject::get_IconLink(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveDataStorageObject_get_IconLink(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-813338940, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDriveDataStorageObject::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveDataStorageObject_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-200152025, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDriveDataStorageObject::get_Kind(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveDataStorageObject_get_Kind(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1480857207, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
TElGoogleDriveUser* TElGoogleDriveDataStorageObject::get_LastModifyingUser()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDriveDataStorageObject_get_LastModifyingUser(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_LastModifyingUser)
		this->_Inst_LastModifyingUser = new TElGoogleDriveUser(hOutResult, ohFalse);
	else
		this->_Inst_LastModifyingUser->updateHandle(hOutResult);
	return this->_Inst_LastModifyingUser;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */

void TElGoogleDriveDataStorageObject::get_LastModifyingUserName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveDataStorageObject_get_LastModifyingUserName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1179725569, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElGoogleDriveDataStorageObject::get_LastViewedByMeDate()
{
	int64_t OutResult;
	SBCheckError(TElGoogleDriveDataStorageObject_get_LastViewedByMeDate(_Handle, &OutResult));
	return OutResult;
}

void TElGoogleDriveDataStorageObject::get_MimeType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveDataStorageObject_get_MimeType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1876255154, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElGoogleDriveDataStorageObject::get_ModifiedByMeDate()
{
	int64_t OutResult;
	SBCheckError(TElGoogleDriveDataStorageObject_get_ModifiedByMeDate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElGoogleDriveDataStorageObject::get_ModifiedDate()
{
	int64_t OutResult;
	SBCheckError(TElGoogleDriveDataStorageObject_get_ModifiedDate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGoogleDriveDataStorageObject::set_ModifiedDate(int64_t Value)
{
	SBCheckError(TElGoogleDriveDataStorageObject_set_ModifiedDate(_Handle, Value));
}

SB_INLINE void TElGoogleDriveDataStorageObject::get_OwnerNames(TStringList &OutResult)
{
	SBCheckError(TElGoogleDriveDataStorageObject_get_OwnerNames(_Handle, OutResult.getHandle()));
}

SB_INLINE int32_t TElGoogleDriveDataStorageObject::get_OwnerCount()
{
	int32_t OutResult;
	SBCheckError(TElGoogleDriveDataStorageObject_get_OwnerCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
TElGoogleDriveUser* TElGoogleDriveDataStorageObject::get_Owners(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDriveDataStorageObject_get_Owners(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Owners)
		this->_Inst_Owners = new TElGoogleDriveUser(hOutResult, ohFalse);
	else
		this->_Inst_Owners->updateHandle(hOutResult);
	return this->_Inst_Owners;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */

void TElGoogleDriveDataStorageObject::get_Parent(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveDataStorageObject_get_Parent(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2060503713, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGoogleDriveDataStorageObject::get_Parents(TStringList &OutResult)
{
	SBCheckError(TElGoogleDriveDataStorageObject_get_Parents(_Handle, OutResult.getHandle()));
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPERMISSIONS
TElGoogleDrivePermissions* TElGoogleDriveDataStorageObject::get_Permissions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDriveDataStorageObject_get_Permissions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Permissions)
		this->_Inst_Permissions = new TElGoogleDrivePermissions(hOutResult, ohFalse);
	else
		this->_Inst_Permissions->updateHandle(hOutResult);
	return this->_Inst_Permissions;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPERMISSIONS */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPROPERTIES
TElGoogleDriveProperties* TElGoogleDriveDataStorageObject::get_Properties()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDriveDataStorageObject_get_Properties(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Properties)
		this->_Inst_Properties = new TElGoogleDriveProperties(hOutResult, ohFalse);
	else
		this->_Inst_Properties->updateHandle(hOutResult);
	return this->_Inst_Properties;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPROPERTIES */

SB_INLINE int64_t TElGoogleDriveDataStorageObject::get_QuotaBytesUsed()
{
	int64_t OutResult;
	SBCheckError(TElGoogleDriveDataStorageObject_get_QuotaBytesUsed(_Handle, &OutResult));
	return OutResult;
}

bool TElGoogleDriveDataStorageObject::get_Restricted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveDataStorageObject_get_Restricted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGoogleDriveDataStorageObject::set_Restricted(bool Value)
{
	SBCheckError(TElGoogleDriveDataStorageObject_set_Restricted(_Handle, (int8_t)Value));
}

void TElGoogleDriveDataStorageObject::get_SelfLink(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveDataStorageObject_get_SelfLink(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-137736334, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElGoogleDriveDataStorageObject::get_Shared()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveDataStorageObject_get_Shared(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int64_t TElGoogleDriveDataStorageObject::get_SharedWithMeDate()
{
	int64_t OutResult;
	SBCheckError(TElGoogleDriveDataStorageObject_get_SharedWithMeDate(_Handle, &OutResult));
	return OutResult;
}

bool TElGoogleDriveDataStorageObject::get_Starred()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveDataStorageObject_get_Starred(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGoogleDriveDataStorageObject::set_Starred(bool Value)
{
	SBCheckError(TElGoogleDriveDataStorageObject_set_Starred(_Handle, (int8_t)Value));
}

void TElGoogleDriveDataStorageObject::get_ThumbnailLink(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveDataStorageObject_get_ThumbnailLink(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1497983858, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElGoogleDriveDataStorageObject::get_Trashed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveDataStorageObject_get_Trashed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGoogleDriveDataStorageObject::get_Viewed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveDataStorageObject_get_Viewed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElGoogleDriveDataStorageObject::get_WebContentLink(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveDataStorageObject_get_WebContentLink(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-966969945, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElGoogleDriveDataStorageObject::get_WritersCanShare()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveDataStorageObject_get_WritersCanShare(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElGoogleDriveDataStorageObject::initInstances()
{
#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENTS
	this->_Inst_Comments = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENTS */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
	this->_Inst_LastModifyingUser = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
	this->_Inst_Owners = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPERMISSIONS
	this->_Inst_Permissions = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPERMISSIONS */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPROPERTIES
	this->_Inst_Properties = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPROPERTIES */
}

TElGoogleDriveDataStorageObject::TElGoogleDriveDataStorageObject(TElGoogleDriveDataStorageObjectHandle handle, TElOwnHandle ownHandle) : TElCustomDataStorageObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE
TElGoogleDriveDataStorageObject::TElGoogleDriveDataStorageObject(TElGoogleDriveDataStorage &AStorage) : TElCustomDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDriveDataStorageObject_Create(AStorage.getHandle(), &_Handle));
}

TElGoogleDriveDataStorageObject::TElGoogleDriveDataStorageObject(TElGoogleDriveDataStorage *AStorage) : TElCustomDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDriveDataStorageObject_Create((AStorage != NULL) ? AStorage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE */

TElGoogleDriveDataStorageObject::~TElGoogleDriveDataStorageObject()
{
#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENTS
	delete this->_Inst_Comments;
	this->_Inst_Comments = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENTS */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
	delete this->_Inst_LastModifyingUser;
	this->_Inst_LastModifyingUser = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
	delete this->_Inst_Owners;
	this->_Inst_Owners = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPERMISSIONS
	delete this->_Inst_Permissions;
	this->_Inst_Permissions = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPERMISSIONS */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPROPERTIES
	delete this->_Inst_Properties;
	this->_Inst_Properties = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPROPERTIES */
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEFOLDER

SB_INLINE void TElGoogleDriveFolder::Assign(TElCustomDataStorageObject &Source)
{
	SBCheckError(TElGoogleDriveFolder_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElGoogleDriveFolder::Assign(TElCustomDataStorageObject *Source)
{
	SBCheckError(TElGoogleDriveFolder_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElGoogleDriveFolder::Clear()
{
	SBCheckError(TElGoogleDriveFolder_Clear(_Handle));
}

SB_INLINE TElGoogleDriveFolderHandle TElGoogleDriveFolder::CreateFolder(const std::string &Name, const std::string &Description)
{
	TElGoogleDriveFolderHandle OutResult;
	SBCheckError(TElGoogleDriveFolder_CreateFolder(_Handle, Name.data(), (int32_t)Name.length(), Description.data(), (int32_t)Description.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElGoogleDriveDataStorageObjectHandle TElGoogleDriveFolder::CreateObject(const std::string &Name, const std::string &Description, const std::string &MimeType, bool Hidden, bool Restricted, bool Starred, TElCustomDataStorageSecurityHandler &Handler)
{
	TElGoogleDriveDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDriveFolder_CreateObject(_Handle, Name.data(), (int32_t)Name.length(), Description.data(), (int32_t)Description.length(), MimeType.data(), (int32_t)MimeType.length(), (int8_t)Hidden, (int8_t)Restricted, (int8_t)Starred, Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElGoogleDriveDataStorageObjectHandle TElGoogleDriveFolder::CreateObject(const std::string &Name, const std::string &Description, const std::string &MimeType, bool Hidden, bool Restricted, bool Starred, TElCustomDataStorageSecurityHandler *Handler)
{
	TElGoogleDriveDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDriveFolder_CreateObject(_Handle, Name.data(), (int32_t)Name.length(), Description.data(), (int32_t)Description.length(), MimeType.data(), (int32_t)MimeType.length(), (int8_t)Hidden, (int8_t)Restricted, (int8_t)Starred, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */

SB_INLINE TElCustomDataStorageObjectHandle TElGoogleDriveFolder::Clone()
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDriveFolder_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElGoogleDriveFolder::List(TElDataStorageObjectList &Objects)
{
	SBCheckError(TElGoogleDriveFolder_List(_Handle, Objects.getHandle()));
}

SB_INLINE void TElGoogleDriveFolder::List(TElDataStorageObjectList *Objects)
{
	SBCheckError(TElGoogleDriveFolder_List(_Handle, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElGoogleDriveFolder::ListFolders(TElDataStorageObjectList &Objects)
{
	SBCheckError(TElGoogleDriveFolder_ListFolders(_Handle, Objects.getHandle()));
}

SB_INLINE void TElGoogleDriveFolder::ListFolders(TElDataStorageObjectList *Objects)
{
	SBCheckError(TElGoogleDriveFolder_ListFolders(_Handle, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

void TElGoogleDriveFolder::get_WebViewLink(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveFolder_get_WebViewLink(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1851711234, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElGoogleDriveFolder::TElGoogleDriveFolder(TElGoogleDriveFolderHandle handle, TElOwnHandle ownHandle) : TElGoogleDriveDataStorageObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE
TElGoogleDriveFolder::TElGoogleDriveFolder(TElGoogleDriveDataStorage &Storage) : TElGoogleDriveDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGoogleDriveFolder_Create(Storage.getHandle(), &_Handle));
}

TElGoogleDriveFolder::TElGoogleDriveFolder(TElGoogleDriveDataStorage *Storage) : TElGoogleDriveDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGoogleDriveFolder_Create((Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE */

#endif /* SB_USE_CLASS_TELGOOGLEDRIVEFOLDER */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPROPERTIES

SB_INLINE int32_t TElGoogleDriveProperties::Add(const std::string &Key, TSBGoogleDrivePropertyVisibility Visibility, const std::string &Value)
{
	int32_t OutResult;
	SBCheckError(TElGoogleDriveProperties_Add(_Handle, Key.data(), (int32_t)Key.length(), (TSBGoogleDrivePropertyVisibilityRaw)Visibility, Value.data(), (int32_t)Value.length(), &OutResult));
	return OutResult;
}

bool TElGoogleDriveProperties::Exists(const std::string &Key, TSBGoogleDrivePropertyVisibility Visibility)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveProperties_Exists(_Handle, Key.data(), (int32_t)Key.length(), (TSBGoogleDrivePropertyVisibilityRaw)Visibility, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPROPERTY
SB_INLINE int32_t TElGoogleDriveProperties::IndexOf(TElGoogleDriveProperty &Prop)
{
	int32_t OutResult;
	SBCheckError(TElGoogleDriveProperties_IndexOf(_Handle, Prop.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElGoogleDriveProperties::IndexOf(TElGoogleDriveProperty *Prop)
{
	int32_t OutResult;
	SBCheckError(TElGoogleDriveProperties_IndexOf(_Handle, (Prop != NULL) ? Prop->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPROPERTY */

SB_INLINE int32_t TElGoogleDriveProperties::IndexOf(const std::string &Key, TSBGoogleDrivePropertyVisibility Visibility)
{
	int32_t OutResult;
	SBCheckError(TElGoogleDriveProperties_IndexOf_1(_Handle, Key.data(), (int32_t)Key.length(), (TSBGoogleDrivePropertyVisibilityRaw)Visibility, &OutResult));
	return OutResult;
}

SB_INLINE void TElGoogleDriveProperties::Refresh()
{
	SBCheckError(TElGoogleDriveProperties_Refresh(_Handle));
}

void TElGoogleDriveProperties::ValueByKey(const std::string &Key, TSBGoogleDrivePropertyVisibility Visibility, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveProperties_ValueByKey(_Handle, Key.data(), (int32_t)Key.length(), (TSBGoogleDrivePropertyVisibilityRaw)Visibility, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1768416701, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElGoogleDriveProperties::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElGoogleDriveProperties_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElGoogleDriveProperties::get_ETag(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveProperties_get_ETag(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2074972976, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPROPERTY
TElGoogleDriveProperty* TElGoogleDriveProperties::get_Items(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDriveProperties_get_Items(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Items)
		this->_Inst_Items = new TElGoogleDriveProperty(hOutResult, ohFalse);
	else
		this->_Inst_Items->updateHandle(hOutResult);
	return this->_Inst_Items;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPROPERTY */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
TElGoogleDriveDataStorageObject* TElGoogleDriveProperties::get_Owner()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDriveProperties_get_Owner(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Owner)
		this->_Inst_Owner = new TElGoogleDriveDataStorageObject(hOutResult, ohFalse);
	else
		this->_Inst_Owner->updateHandle(hOutResult);
	return this->_Inst_Owner;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

void TElGoogleDriveProperties::initInstances()
{
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPROPERTY
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPROPERTY */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */
}

TElGoogleDriveProperties::TElGoogleDriveProperties(TElGoogleDrivePropertiesHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
TElGoogleDriveProperties::TElGoogleDriveProperties(TElGoogleDriveDataStorageObject &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDriveProperties_Create(AOwner.getHandle(), &_Handle));
}

TElGoogleDriveProperties::TElGoogleDriveProperties(TElGoogleDriveDataStorageObject *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDriveProperties_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

TElGoogleDriveProperties::~TElGoogleDriveProperties()
{
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPROPERTY
	delete this->_Inst_Items;
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPROPERTY */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
	delete this->_Inst_Owner;
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPROPERTIES */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENT

SB_INLINE void TElGoogleDriveComment::Assign(TElGoogleDriveComment &Source)
{
	SBCheckError(TElGoogleDriveComment_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElGoogleDriveComment::Assign(TElGoogleDriveComment *Source)
{
	SBCheckError(TElGoogleDriveComment_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElGoogleDriveCommentHandle TElGoogleDriveComment::Clone()
{
	TElGoogleDriveCommentHandle OutResult;
	SBCheckError(TElGoogleDriveComment_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGoogleDriveComment::Delete()
{
	SBCheckError(TElGoogleDriveComment_Delete(_Handle));
}

SB_INLINE void TElGoogleDriveComment::Refresh()
{
	SBCheckError(TElGoogleDriveComment_Refresh(_Handle));
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
TElGoogleDriveUser* TElGoogleDriveComment::get_Author()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDriveComment_get_Author(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Author)
		this->_Inst_Author = new TElGoogleDriveUser(hOutResult, ohFalse);
	else
		this->_Inst_Author->updateHandle(hOutResult);
	return this->_Inst_Author;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */

void TElGoogleDriveComment::get_Content(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveComment_get_Content(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(772715594, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGoogleDriveComment::set_Content(const std::string &Value)
{
	SBCheckError(TElGoogleDriveComment_set_Content(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElGoogleDriveComment::get_CreatedDate()
{
	int64_t OutResult;
	SBCheckError(TElGoogleDriveComment_get_CreatedDate(_Handle, &OutResult));
	return OutResult;
}

bool TElGoogleDriveComment::get_Deleted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveComment_get_Deleted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElGoogleDriveComment::get_HtmlContent(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveComment_get_HtmlContent(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1428273400, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDriveComment::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveComment_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1542174800, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElGoogleDriveComment::get_ModifiedDate()
{
	int64_t OutResult;
	SBCheckError(TElGoogleDriveComment_get_ModifiedDate(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
TElGoogleDriveDataStorageObject* TElGoogleDriveComment::get_Owner()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDriveComment_get_Owner(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Owner)
		this->_Inst_Owner = new TElGoogleDriveDataStorageObject(hOutResult, ohFalse);
	else
		this->_Inst_Owner->updateHandle(hOutResult);
	return this->_Inst_Owner;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEREPLIES
TElGoogleDriveReplies* TElGoogleDriveComment::get_Replies()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDriveComment_get_Replies(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Replies)
		this->_Inst_Replies = new TElGoogleDriveReplies(hOutResult, ohFalse);
	else
		this->_Inst_Replies->updateHandle(hOutResult);
	return this->_Inst_Replies;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEREPLIES */

TSBGoogleDriveCommentStatus TElGoogleDriveComment::get_Status()
{
	TSBGoogleDriveCommentStatusRaw OutResultRaw = 0;
	SBCheckError(TElGoogleDriveComment_get_Status(_Handle, &OutResultRaw));
	return (TSBGoogleDriveCommentStatus)OutResultRaw;
}

void TElGoogleDriveComment::initInstances()
{
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
	this->_Inst_Author = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEREPLIES
	this->_Inst_Replies = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEREPLIES */
}

TElGoogleDriveComment::TElGoogleDriveComment(TElGoogleDriveCommentHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
TElGoogleDriveComment::TElGoogleDriveComment(TElGoogleDriveDataStorageObject &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDriveComment_Create(AOwner.getHandle(), &_Handle));
}

TElGoogleDriveComment::TElGoogleDriveComment(TElGoogleDriveDataStorageObject *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDriveComment_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

TElGoogleDriveComment::~TElGoogleDriveComment()
{
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
	delete this->_Inst_Author;
	this->_Inst_Author = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
	delete this->_Inst_Owner;
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEREPLIES
	delete this->_Inst_Replies;
	this->_Inst_Replies = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEREPLIES */
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENT */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEREPLIES

SB_INLINE int32_t TElGoogleDriveReplies::Add(const std::string &Content, TSBGoogleDriveReplyAction Action)
{
	int32_t OutResult;
	SBCheckError(TElGoogleDriveReplies_Add(_Handle, Content.data(), (int32_t)Content.length(), (TSBGoogleDriveReplyActionRaw)Action, &OutResult));
	return OutResult;
}

SB_INLINE void TElGoogleDriveReplies::Refresh(bool IncludeDeleted)
{
	SBCheckError(TElGoogleDriveReplies_Refresh(_Handle, (int8_t)IncludeDeleted));
}

SB_INLINE int32_t TElGoogleDriveReplies::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElGoogleDriveReplies_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEREPLY
TElGoogleDriveReply* TElGoogleDriveReplies::get_Items(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDriveReplies_get_Items(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Items)
		this->_Inst_Items = new TElGoogleDriveReply(hOutResult, ohFalse);
	else
		this->_Inst_Items->updateHandle(hOutResult);
	return this->_Inst_Items;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEREPLY */

void TElGoogleDriveReplies::initInstances()
{
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEREPLY
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEREPLY */
}

TElGoogleDriveReplies::TElGoogleDriveReplies(TElGoogleDriveRepliesHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENT
TElGoogleDriveReplies::TElGoogleDriveReplies(TElGoogleDriveComment &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDriveReplies_Create(AOwner.getHandle(), &_Handle));
}

TElGoogleDriveReplies::TElGoogleDriveReplies(TElGoogleDriveComment *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDriveReplies_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENT */

TElGoogleDriveReplies::~TElGoogleDriveReplies()
{
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEREPLY
	delete this->_Inst_Items;
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEREPLY */
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEREPLIES */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER

SB_INLINE TElGoogleDriveUserHandle TElGoogleDriveUser::Clone()
{
	TElGoogleDriveUserHandle OutResult;
	SBCheckError(TElGoogleDriveUser_Clone(_Handle, &OutResult));
	return OutResult;
}

void TElGoogleDriveUser::get_DisplayName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveUser_get_DisplayName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(118356430, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElGoogleDriveUser::get_IsAuthenticated()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveUser_get_IsAuthenticated(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElGoogleDriveUser::get_PermissionID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveUser_get_PermissionID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(189799598, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDriveUser::get_PictureURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveUser_get_PictureURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2007731218, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElGoogleDriveUser::TElGoogleDriveUser(TElGoogleDriveUserHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElGoogleDriveUser::TElGoogleDriveUser() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGoogleDriveUser_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEACCOUNTINFO

SB_INLINE void TElGoogleDriveAccountInfo::Refresh()
{
	SBCheckError(TElGoogleDriveAccountInfo_Refresh(_Handle));
}

void TElGoogleDriveAccountInfo::get_DomainSharingPolicy(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveAccountInfo_get_DomainSharingPolicy(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1824297312, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDriveAccountInfo::get_ETag(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveAccountInfo_get_ETag(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2029420675, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDriveAccountInfo::get_LanguageCode(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveAccountInfo_get_LanguageCode(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(291889219, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElGoogleDriveAccountInfo::get_LargestChangeID()
{
	int64_t OutResult;
	SBCheckError(TElGoogleDriveAccountInfo_get_LargestChangeID(_Handle, &OutResult));
	return OutResult;
}

void TElGoogleDriveAccountInfo::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveAccountInfo_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-806613287, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDriveAccountInfo::get_PermissionID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveAccountInfo_get_PermissionID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(26602571, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElGoogleDriveAccountInfo::get_QuotaBytesTotal()
{
	int64_t OutResult;
	SBCheckError(TElGoogleDriveAccountInfo_get_QuotaBytesTotal(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElGoogleDriveAccountInfo::get_QuotaBytesUsed()
{
	int64_t OutResult;
	SBCheckError(TElGoogleDriveAccountInfo_get_QuotaBytesUsed(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElGoogleDriveAccountInfo::get_QuotaBytesUsedAggregate()
{
	int64_t OutResult;
	SBCheckError(TElGoogleDriveAccountInfo_get_QuotaBytesUsedAggregate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElGoogleDriveAccountInfo::get_QuotaBytesUsedInTrash()
{
	int64_t OutResult;
	SBCheckError(TElGoogleDriveAccountInfo_get_QuotaBytesUsedInTrash(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElGoogleDriveAccountInfo::get_RemainingChangeIDs()
{
	int64_t OutResult;
	SBCheckError(TElGoogleDriveAccountInfo_get_RemainingChangeIDs(_Handle, &OutResult));
	return OutResult;
}

void TElGoogleDriveAccountInfo::get_RootFolderID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveAccountInfo_get_RootFolderID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(764124397, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
TElGoogleDriveUser* TElGoogleDriveAccountInfo::get_User()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDriveAccountInfo_get_User(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_User)
		this->_Inst_User = new TElGoogleDriveUser(hOutResult, ohFalse);
	else
		this->_Inst_User->updateHandle(hOutResult);
	return this->_Inst_User;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */

void TElGoogleDriveAccountInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
	this->_Inst_User = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */
}

TElGoogleDriveAccountInfo::TElGoogleDriveAccountInfo(TElGoogleDriveAccountInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE
TElGoogleDriveAccountInfo::TElGoogleDriveAccountInfo(TElGoogleDriveDataStorage &AStorage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDriveAccountInfo_Create(AStorage.getHandle(), &_Handle));
}

TElGoogleDriveAccountInfo::TElGoogleDriveAccountInfo(TElGoogleDriveDataStorage *AStorage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDriveAccountInfo_Create((AStorage != NULL) ? AStorage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE */

TElGoogleDriveAccountInfo::~TElGoogleDriveAccountInfo()
{
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
	delete this->_Inst_User;
	this->_Inst_User = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEACCOUNTINFO */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENTS

SB_INLINE int32_t TElGoogleDriveComments::Add(const std::string &Content)
{
	int32_t OutResult;
	SBCheckError(TElGoogleDriveComments_Add(_Handle, Content.data(), (int32_t)Content.length(), &OutResult));
	return OutResult;
}

SB_INLINE void TElGoogleDriveComments::Refresh(bool IncludeDeleted)
{
	SBCheckError(TElGoogleDriveComments_Refresh(_Handle, (int8_t)IncludeDeleted));
}

SB_INLINE void TElGoogleDriveComments::Refresh(int64_t UpdatedAfter, bool IncludeDeleted)
{
	SBCheckError(TElGoogleDriveComments_Refresh_1(_Handle, UpdatedAfter, (int8_t)IncludeDeleted));
}

SB_INLINE int32_t TElGoogleDriveComments::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElGoogleDriveComments_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENT
TElGoogleDriveComment* TElGoogleDriveComments::get_Items(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDriveComments_get_Items(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Items)
		this->_Inst_Items = new TElGoogleDriveComment(hOutResult, ohFalse);
	else
		this->_Inst_Items->updateHandle(hOutResult);
	return this->_Inst_Items;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENT */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
TElGoogleDriveDataStorageObject* TElGoogleDriveComments::get_Owner()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDriveComments_get_Owner(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Owner)
		this->_Inst_Owner = new TElGoogleDriveDataStorageObject(hOutResult, ohFalse);
	else
		this->_Inst_Owner->updateHandle(hOutResult);
	return this->_Inst_Owner;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

void TElGoogleDriveComments::initInstances()
{
#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENT
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENT */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */
}

TElGoogleDriveComments::TElGoogleDriveComments(TElGoogleDriveCommentsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
TElGoogleDriveComments::TElGoogleDriveComments(TElGoogleDriveDataStorageObject &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDriveComments_Create(AOwner.getHandle(), &_Handle));
}

TElGoogleDriveComments::TElGoogleDriveComments(TElGoogleDriveDataStorageObject *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDriveComments_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

TElGoogleDriveComments::~TElGoogleDriveComments()
{
#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENT
	delete this->_Inst_Items;
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENT */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
	delete this->_Inst_Owner;
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENTS */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEREPLY

SB_INLINE void TElGoogleDriveReply::Assign(TElGoogleDriveReply &Source)
{
	SBCheckError(TElGoogleDriveReply_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElGoogleDriveReply::Assign(TElGoogleDriveReply *Source)
{
	SBCheckError(TElGoogleDriveReply_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElGoogleDriveReplyHandle TElGoogleDriveReply::Clone()
{
	TElGoogleDriveReplyHandle OutResult;
	SBCheckError(TElGoogleDriveReply_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGoogleDriveReply::Delete()
{
	SBCheckError(TElGoogleDriveReply_Delete(_Handle));
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
TElGoogleDriveUser* TElGoogleDriveReply::get_Author()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDriveReply_get_Author(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Author)
		this->_Inst_Author = new TElGoogleDriveUser(hOutResult, ohFalse);
	else
		this->_Inst_Author->updateHandle(hOutResult);
	return this->_Inst_Author;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */

void TElGoogleDriveReply::get_Content(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveReply_get_Content(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-415908510, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGoogleDriveReply::set_Content(const std::string &Value)
{
	SBCheckError(TElGoogleDriveReply_set_Content(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElGoogleDriveReply::get_CreatedDate()
{
	int64_t OutResult;
	SBCheckError(TElGoogleDriveReply_get_CreatedDate(_Handle, &OutResult));
	return OutResult;
}

bool TElGoogleDriveReply::get_Deleted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDriveReply_get_Deleted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElGoogleDriveReply::get_HtmlContent(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveReply_get_HtmlContent(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-511929974, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDriveReply::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveReply_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-948163864, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElGoogleDriveReply::get_ModifiedDate()
{
	int64_t OutResult;
	SBCheckError(TElGoogleDriveReply_get_ModifiedDate(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENT
TElGoogleDriveComment* TElGoogleDriveReply::get_Owner()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDriveReply_get_Owner(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Owner)
		this->_Inst_Owner = new TElGoogleDriveComment(hOutResult, ohFalse);
	else
		this->_Inst_Owner->updateHandle(hOutResult);
	return this->_Inst_Owner;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENT */

void TElGoogleDriveReply::initInstances()
{
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
	this->_Inst_Author = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENT
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENT */
}

TElGoogleDriveReply::TElGoogleDriveReply(TElGoogleDriveReplyHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENT
TElGoogleDriveReply::TElGoogleDriveReply(TElGoogleDriveComment &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDriveReply_Create(AOwner.getHandle(), &_Handle));
}

TElGoogleDriveReply::TElGoogleDriveReply(TElGoogleDriveComment *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDriveReply_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENT */

TElGoogleDriveReply::~TElGoogleDriveReply()
{
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
	delete this->_Inst_Author;
	this->_Inst_Author = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENT
	delete this->_Inst_Owner;
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENT */
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEREPLY */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPROPERTY

SB_INLINE TElGoogleDrivePropertyHandle TElGoogleDriveProperty::Clone()
{
	TElGoogleDrivePropertyHandle OutResult;
	SBCheckError(TElGoogleDriveProperty_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGoogleDriveProperty::Delete()
{
	SBCheckError(TElGoogleDriveProperty_Delete(_Handle));
}

SB_INLINE void TElGoogleDriveProperty::Refresh()
{
	SBCheckError(TElGoogleDriveProperty_Refresh(_Handle));
}

void TElGoogleDriveProperty::get_ETag(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveProperty_get_ETag(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-280924089, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDriveProperty::get_Key(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveProperty_get_Key(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1271914442, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDriveProperty::get_Value(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveProperty_get_Value(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1159071445, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGoogleDriveProperty::set_Value(const std::string &Value)
{
	SBCheckError(TElGoogleDriveProperty_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBGoogleDrivePropertyVisibility TElGoogleDriveProperty::get_Visibility()
{
	TSBGoogleDrivePropertyVisibilityRaw OutResultRaw = 0;
	SBCheckError(TElGoogleDriveProperty_get_Visibility(_Handle, &OutResultRaw));
	return (TSBGoogleDrivePropertyVisibility)OutResultRaw;
}

TElGoogleDriveProperty::TElGoogleDriveProperty(TElGoogleDrivePropertyHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
TElGoogleDriveProperty::TElGoogleDriveProperty(TElGoogleDriveDataStorageObject &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGoogleDriveProperty_Create(AOwner.getHandle(), &_Handle));
}

TElGoogleDriveProperty::TElGoogleDriveProperty(TElGoogleDriveDataStorageObject *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGoogleDriveProperty_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPROPERTY */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPERMISSION

SB_INLINE TElGoogleDrivePermissionHandle TElGoogleDrivePermission::Clone()
{
	TElGoogleDrivePermissionHandle OutResult;
	SBCheckError(TElGoogleDrivePermission_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGoogleDrivePermission::Delete()
{
	SBCheckError(TElGoogleDrivePermission_Delete(_Handle));
}

SB_INLINE void TElGoogleDrivePermission::Refresh()
{
	SBCheckError(TElGoogleDrivePermission_Refresh(_Handle));
}

SB_INLINE void TElGoogleDrivePermission::TransferOwnership()
{
	SBCheckError(TElGoogleDrivePermission_TransferOwnership(_Handle));
}

void TElGoogleDrivePermission::get_AuthKey(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDrivePermission_get_AuthKey(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1403202482, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElGoogleDrivePermission::get_Commenter()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDrivePermission_get_Commenter(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGoogleDrivePermission::set_Commenter(bool Value)
{
	SBCheckError(TElGoogleDrivePermission_set_Commenter(_Handle, (int8_t)Value));
}

void TElGoogleDrivePermission::get_ETag(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDrivePermission_get_ETag(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(875257874, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDrivePermission::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDrivePermission_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-676322268, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDrivePermission::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDrivePermission_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2093879736, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
TElGoogleDriveDataStorageObject* TElGoogleDrivePermission::get_Owner()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDrivePermission_get_Owner(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Owner)
		this->_Inst_Owner = new TElGoogleDriveDataStorageObject(hOutResult, ohFalse);
	else
		this->_Inst_Owner->updateHandle(hOutResult);
	return this->_Inst_Owner;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

void TElGoogleDrivePermission::get_PhotoLink(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDrivePermission_get_PhotoLink(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-473683396, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBGoogleDriveUserRole TElGoogleDrivePermission::get_Role()
{
	TSBGoogleDriveUserRoleRaw OutResultRaw = 0;
	SBCheckError(TElGoogleDrivePermission_get_Role(_Handle, &OutResultRaw));
	return (TSBGoogleDriveUserRole)OutResultRaw;
}

SB_INLINE void TElGoogleDrivePermission::set_Role(TSBGoogleDriveUserRole Value)
{
	SBCheckError(TElGoogleDrivePermission_set_Role(_Handle, (TSBGoogleDriveUserRoleRaw)Value));
}

TSBGoogleDrivePermissionScope TElGoogleDrivePermission::get_Scope()
{
	TSBGoogleDrivePermissionScopeRaw OutResultRaw = 0;
	SBCheckError(TElGoogleDrivePermission_get_Scope(_Handle, &OutResultRaw));
	return (TSBGoogleDrivePermissionScope)OutResultRaw;
}

void TElGoogleDrivePermission::get_Value(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDrivePermission_get_Value(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1590479294, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElGoogleDrivePermission::get_WithLink()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGoogleDrivePermission_get_WithLink(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElGoogleDrivePermission::initInstances()
{
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */
}

TElGoogleDrivePermission::TElGoogleDrivePermission(TElGoogleDrivePermissionHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
TElGoogleDrivePermission::TElGoogleDrivePermission(TElGoogleDriveDataStorageObject &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDrivePermission_Create(AOwner.getHandle(), &_Handle));
}

TElGoogleDrivePermission::TElGoogleDrivePermission(TElGoogleDriveDataStorageObject *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDrivePermission_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

TElGoogleDrivePermission::~TElGoogleDrivePermission()
{
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
	delete this->_Inst_Owner;
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPERMISSION */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPERMISSIONS

SB_INLINE int32_t TElGoogleDrivePermissions::Add(TSBGoogleDriveUserRole Role, TSBGoogleDrivePermissionScope AccountType, const std::string &Value, bool CanComment, bool WithLink, bool SendNotificationEMails, const std::string &EMailMessage)
{
	int32_t OutResult;
	SBCheckError(TElGoogleDrivePermissions_Add(_Handle, (TSBGoogleDriveUserRoleRaw)Role, (TSBGoogleDrivePermissionScopeRaw)AccountType, Value.data(), (int32_t)Value.length(), (int8_t)CanComment, (int8_t)WithLink, (int8_t)SendNotificationEMails, EMailMessage.data(), (int32_t)EMailMessage.length(), &OutResult));
	return OutResult;
}

SB_INLINE void TElGoogleDrivePermissions::Refresh()
{
	SBCheckError(TElGoogleDrivePermissions_Refresh(_Handle));
}

SB_INLINE int32_t TElGoogleDrivePermissions::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElGoogleDrivePermissions_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElGoogleDrivePermissions::get_ETag(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDrivePermissions_get_ETag(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1181240481, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPERMISSION
TElGoogleDrivePermission* TElGoogleDrivePermissions::get_Items(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDrivePermissions_get_Items(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Items)
		this->_Inst_Items = new TElGoogleDrivePermission(hOutResult, ohFalse);
	else
		this->_Inst_Items->updateHandle(hOutResult);
	return this->_Inst_Items;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPERMISSION */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
TElGoogleDriveDataStorageObject* TElGoogleDrivePermissions::get_Owner()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGoogleDrivePermissions_get_Owner(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Owner)
		this->_Inst_Owner = new TElGoogleDriveDataStorageObject(hOutResult, ohFalse);
	else
		this->_Inst_Owner->updateHandle(hOutResult);
	return this->_Inst_Owner;
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

void TElGoogleDrivePermissions::initInstances()
{
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPERMISSION
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPERMISSION */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */
}

TElGoogleDrivePermissions::TElGoogleDrivePermissions(TElGoogleDrivePermissionsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
TElGoogleDrivePermissions::TElGoogleDrivePermissions(TElGoogleDriveDataStorageObject &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDrivePermissions_Create(AOwner.getHandle(), &_Handle));
}

TElGoogleDrivePermissions::TElGoogleDrivePermissions(TElGoogleDriveDataStorageObject *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGoogleDrivePermissions_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

TElGoogleDrivePermissions::~TElGoogleDrivePermissions()
{
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPERMISSION
	delete this->_Inst_Items;
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPERMISSION */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
	delete this->_Inst_Owner;
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPERMISSIONS */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVECUSTOMFILE

TElGoogleDriveCustomFile::TElGoogleDriveCustomFile(TElGoogleDriveCustomFileHandle handle, TElOwnHandle ownHandle) : TElGoogleDriveDataStorageObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE
TElGoogleDriveCustomFile::TElGoogleDriveCustomFile(TElGoogleDriveDataStorage &AStorage) : TElGoogleDriveDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGoogleDriveCustomFile_Create(AStorage.getHandle(), &_Handle));
}

TElGoogleDriveCustomFile::TElGoogleDriveCustomFile(TElGoogleDriveDataStorage *AStorage) : TElGoogleDriveDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGoogleDriveCustomFile_Create((AStorage != NULL) ? AStorage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE */

#endif /* SB_USE_CLASS_TELGOOGLEDRIVECUSTOMFILE */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEFILE

SB_INLINE void TElGoogleDriveFile::Assign(TElCustomDataStorageObject &Source)
{
	SBCheckError(TElGoogleDriveFile_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElGoogleDriveFile::Assign(TElCustomDataStorageObject *Source)
{
	SBCheckError(TElGoogleDriveFile_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElGoogleDriveFile::Clear()
{
	SBCheckError(TElGoogleDriveFile_Clear(_Handle));
}

SB_INLINE TElCustomDataStorageObjectHandle TElGoogleDriveFile::Clone()
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDriveFile_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElGoogleDriveFile::Read(TStream &Data)
{
	SBCheckError(TElGoogleDriveFile_Read(_Handle, Data.getHandle()));
}

SB_INLINE void TElGoogleDriveFile::Read(TStream *Data)
{
	SBCheckError(TElGoogleDriveFile_Read(_Handle, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElGoogleDriveFile::Write(TStream &Data, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElGoogleDriveFile_Write(_Handle, Data.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElGoogleDriveFile::Write(TStream *Data, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElGoogleDriveFile_Write(_Handle, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

void TElGoogleDriveFile::get_DownloadURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveFile_get_DownloadURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1278070179, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDriveFile::get_FileExtension(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveFile_get_FileExtension(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2069289169, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElGoogleDriveFile::get_FileSize()
{
	int64_t OutResult;
	SBCheckError(TElGoogleDriveFile_get_FileSize(_Handle, &OutResult));
	return OutResult;
}

void TElGoogleDriveFile::get_MD5Checksum(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveFile_get_MD5Checksum(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-808350931, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGoogleDriveFile::get_OriginalFileName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDriveFile_get_OriginalFileName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(612146522, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElGoogleDriveFile::TElGoogleDriveFile(TElGoogleDriveFileHandle handle, TElOwnHandle ownHandle) : TElGoogleDriveCustomFile(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE
TElGoogleDriveFile::TElGoogleDriveFile(TElGoogleDriveDataStorage &AStorage) : TElGoogleDriveCustomFile(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGoogleDriveFile_Create(AStorage.getHandle(), &_Handle));
}

TElGoogleDriveFile::TElGoogleDriveFile(TElGoogleDriveDataStorage *AStorage) : TElGoogleDriveCustomFile(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGoogleDriveFile_Create((AStorage != NULL) ? AStorage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE */

#endif /* SB_USE_CLASS_TELGOOGLEDRIVEFILE */

#ifdef SB_USE_CLASS_TELGOOGLEDOCUMENT

SB_INLINE void TElGoogleDocument::Assign(TElCustomDataStorageObject &Source)
{
	SBCheckError(TElGoogleDocument_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElGoogleDocument::Assign(TElCustomDataStorageObject *Source)
{
	SBCheckError(TElGoogleDocument_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElGoogleDocument::Clear()
{
	SBCheckError(TElGoogleDocument_Clear(_Handle));
}

SB_INLINE TElCustomDataStorageObjectHandle TElGoogleDocument::Clone()
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElGoogleDocument_Clone(_Handle, &OutResult));
	return OutResult;
}

void TElGoogleDocument::get_EmbedLink(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGoogleDocument_get_EmbedLink(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(68790022, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElGoogleDocument::TElGoogleDocument(TElGoogleDocumentHandle handle, TElOwnHandle ownHandle) : TElGoogleDriveCustomFile(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE
TElGoogleDocument::TElGoogleDocument(TElGoogleDriveDataStorage &AStorage) : TElGoogleDriveCustomFile(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGoogleDocument_Create(AStorage.getHandle(), &_Handle));
}

TElGoogleDocument::TElGoogleDocument(TElGoogleDriveDataStorage *AStorage) : TElGoogleDriveCustomFile(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGoogleDocument_Create((AStorage != NULL) ? AStorage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE */

#endif /* SB_USE_CLASS_TELGOOGLEDOCUMENT */

};	/* namespace SecureBlackbox */

