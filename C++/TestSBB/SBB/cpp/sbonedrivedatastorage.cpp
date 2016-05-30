#include "sbonedrivedatastorage.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE

void TElOneDriveDataStorage::StartAuthorization(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveDataStorage_StartAuthorization(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-20432854, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOneDriveDataStorage::CompleteAuthorization(const std::string &AuthorizationCode)
{
	SBCheckError(TElOneDriveDataStorage_CompleteAuthorization(_Handle, AuthorizationCode.data(), (int32_t)AuthorizationCode.length()));
}

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT
SB_INLINE TElOneDriveDataStorageObjectHandle TElOneDriveDataStorage::AcquireObject(const std::string &ObjectID)
{
	TElOneDriveDataStorageObjectHandle OutResult;
	SBCheckError(TElOneDriveDataStorage_AcquireObject(_Handle, ObjectID.data(), (int32_t)ObjectID.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT */

SB_INLINE void TElOneDriveDataStorage::CloseSession()
{
	SBCheckError(TElOneDriveDataStorage_CloseSession(_Handle));
}

#ifdef SB_USE_CLASSES_TELONEDRIVEDATASTORAGEOBJECT_AND_TELONEDRIVEFOLDER
SB_INLINE TElOneDriveDataStorageObjectHandle TElOneDriveDataStorage::CopyObject(TElOneDriveDataStorageObject &Obj, TElOneDriveFolder &Destination)
{
	TElOneDriveDataStorageObjectHandle OutResult;
	SBCheckError(TElOneDriveDataStorage_CopyObject(_Handle, Obj.getHandle(), Destination.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElOneDriveDataStorageObjectHandle TElOneDriveDataStorage::CopyObject(TElOneDriveDataStorageObject *Obj, TElOneDriveFolder *Destination)
{
	TElOneDriveDataStorageObjectHandle OutResult;
	SBCheckError(TElOneDriveDataStorage_CopyObject(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELONEDRIVEDATASTORAGEOBJECT_AND_TELONEDRIVEFOLDER */

#ifdef SB_USE_CLASS_TELONEDRIVEFOLDER
SB_INLINE TElOneDriveFolderHandle TElOneDriveDataStorage::CreateFolder(TElOneDriveFolder &Parent, const std::string &Name, const std::string &Description)
{
	TElOneDriveFolderHandle OutResult;
	SBCheckError(TElOneDriveDataStorage_CreateFolder(_Handle, Parent.getHandle(), Name.data(), (int32_t)Name.length(), Description.data(), (int32_t)Description.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElOneDriveFolderHandle TElOneDriveDataStorage::CreateFolder(TElOneDriveFolder *Parent, const std::string &Name, const std::string &Description)
{
	TElOneDriveFolderHandle OutResult;
	SBCheckError(TElOneDriveDataStorage_CreateFolder(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), Description.data(), (int32_t)Description.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELONEDRIVEFOLDER */

#ifdef SB_USE_CLASSES_TELONEDRIVEFILE_AND_TELONEDRIVEFOLDER
SB_INLINE TElOneDriveFileHandle TElOneDriveDataStorage::CreateObject(TElOneDriveFolder &Parent, const std::string &Name, bool OverwriteIfExists)
{
	TElOneDriveFileHandle OutResult;
	SBCheckError(TElOneDriveDataStorage_CreateObject(_Handle, Parent.getHandle(), Name.data(), (int32_t)Name.length(), (int8_t)OverwriteIfExists, &OutResult));
	return OutResult;
}

SB_INLINE TElOneDriveFileHandle TElOneDriveDataStorage::CreateObject(TElOneDriveFolder *Parent, const std::string &Name, bool OverwriteIfExists)
{
	TElOneDriveFileHandle OutResult;
	SBCheckError(TElOneDriveDataStorage_CreateObject(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), (int8_t)OverwriteIfExists, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELONEDRIVEFILE_AND_TELONEDRIVEFOLDER */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELONEDRIVEFILE_AND_TELONEDRIVEFOLDER
SB_INLINE TElOneDriveFileHandle TElOneDriveDataStorage::CreateObject(TElOneDriveFolder &Parent, const std::string &Name, bool OverwriteIfExists, TElCustomDataStorageSecurityHandler &Handler)
{
	TElOneDriveFileHandle OutResult;
	SBCheckError(TElOneDriveDataStorage_CreateObject_1(_Handle, Parent.getHandle(), Name.data(), (int32_t)Name.length(), (int8_t)OverwriteIfExists, Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElOneDriveFileHandle TElOneDriveDataStorage::CreateObject(TElOneDriveFolder *Parent, const std::string &Name, bool OverwriteIfExists, TElCustomDataStorageSecurityHandler *Handler)
{
	TElOneDriveFileHandle OutResult;
	SBCheckError(TElOneDriveDataStorage_CreateObject_1(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), (int8_t)OverwriteIfExists, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELONEDRIVEFILE_AND_TELONEDRIVEFOLDER */

SB_INLINE void TElOneDriveDataStorage::GetQuota(int64_t &Total, int64_t &Free)
{
	SBCheckError(TElOneDriveDataStorage_GetQuota(_Handle, &Total, &Free));
}

#ifdef SB_USE_CLASS_TELONEDRIVEUSERINFO
SB_INLINE TElOneDriveUserInfoHandle TElOneDriveDataStorage::GetUserInfo()
{
	TElOneDriveUserInfoHandle OutResult;
	SBCheckError(TElOneDriveDataStorage_GetUserInfo(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELONEDRIVEUSERINFO */

#ifdef SB_USE_CLASS_TELONEDRIVEUSERINFO
SB_INLINE TElOneDriveUserInfoHandle TElOneDriveDataStorage::GetUserInfo(const std::string &UserID)
{
	TElOneDriveUserInfoHandle OutResult;
	SBCheckError(TElOneDriveDataStorage_GetUserInfo_1(_Handle, UserID.data(), (int32_t)UserID.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELONEDRIVEUSERINFO */

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELONEDRIVEFOLDER
SB_INLINE void TElOneDriveDataStorage::List(TElOneDriveFolder &Dir, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElOneDriveDataStorage_List(_Handle, Dir.getHandle(), Objects.getHandle()));
}

SB_INLINE void TElOneDriveDataStorage::List(TElOneDriveFolder *Dir, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElOneDriveDataStorage_List(_Handle, (Dir != NULL) ? Dir->getHandle() : SB_NULL_HANDLE, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELONEDRIVEFOLDER */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElOneDriveDataStorage::ListFriendly(const std::string &FriendlyName, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElOneDriveDataStorage_ListFriendly(_Handle, FriendlyName.data(), (int32_t)FriendlyName.length(), Objects.getHandle()));
}

SB_INLINE void TElOneDriveDataStorage::ListFriendly(const std::string &FriendlyName, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElOneDriveDataStorage_ListFriendly(_Handle, FriendlyName.data(), (int32_t)FriendlyName.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElOneDriveDataStorage::ListRecent(TElDataStorageObjectList &Objects)
{
	SBCheckError(TElOneDriveDataStorage_ListRecent(_Handle, Objects.getHandle()));
}

SB_INLINE void TElOneDriveDataStorage::ListRecent(TElDataStorageObjectList *Objects)
{
	SBCheckError(TElOneDriveDataStorage_ListRecent(_Handle, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElOneDriveDataStorage::ListShared(TElDataStorageObjectList &Objects)
{
	SBCheckError(TElOneDriveDataStorage_ListShared(_Handle, Objects.getHandle()));
}

SB_INLINE void TElOneDriveDataStorage::ListShared(TElDataStorageObjectList *Objects)
{
	SBCheckError(TElOneDriveDataStorage_ListShared(_Handle, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASSES_TELONEDRIVEDATASTORAGEOBJECT_AND_TELONEDRIVEFOLDER
SB_INLINE void TElOneDriveDataStorage::MoveObject(TElOneDriveDataStorageObject &Obj, TElOneDriveFolder &Destination)
{
	SBCheckError(TElOneDriveDataStorage_MoveObject(_Handle, Obj.getHandle(), Destination.getHandle()));
}

SB_INLINE void TElOneDriveDataStorage::MoveObject(TElOneDriveDataStorageObject *Obj, TElOneDriveFolder *Destination)
{
	SBCheckError(TElOneDriveDataStorage_MoveObject(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELONEDRIVEDATASTORAGEOBJECT_AND_TELONEDRIVEFOLDER */

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT
SB_INLINE void TElOneDriveDataStorage::RefreshObject(TElOneDriveDataStorageObject &Obj)
{
	SBCheckError(TElOneDriveDataStorage_RefreshObject(_Handle, Obj.getHandle()));
}

SB_INLINE void TElOneDriveDataStorage::RefreshObject(TElOneDriveDataStorageObject *Obj)
{
	SBCheckError(TElOneDriveDataStorage_RefreshObject(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT
SB_INLINE void TElOneDriveDataStorage::RenameObject(TElOneDriveDataStorageObject &Obj, const std::string &NewName)
{
	SBCheckError(TElOneDriveDataStorage_RenameObject(_Handle, Obj.getHandle(), NewName.data(), (int32_t)NewName.length()));
}

SB_INLINE void TElOneDriveDataStorage::RenameObject(TElOneDriveDataStorageObject *Obj, const std::string &NewName)
{
	SBCheckError(TElOneDriveDataStorage_RenameObject(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, NewName.data(), (int32_t)NewName.length()));
}
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElOneDriveDataStorage::Search(const std::string &Query, TElDataStorageObjectList &Objects)
{
	SBCheckError(TElOneDriveDataStorage_Search(_Handle, Query.data(), (int32_t)Query.length(), Objects.getHandle()));
}

SB_INLINE void TElOneDriveDataStorage::Search(const std::string &Query, TElDataStorageObjectList *Objects)
{
	SBCheckError(TElOneDriveDataStorage_Search(_Handle, Query.data(), (int32_t)Query.length(), (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

void TElOneDriveDataStorage::get_AccessToken(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveDataStorage_get_AccessToken(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1641233852, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOneDriveDataStorage::get_ClientID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveDataStorage_get_ClientID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-444164145, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOneDriveDataStorage::set_ClientID(const std::string &Value)
{
	SBCheckError(TElOneDriveDataStorage_set_ClientID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOneDriveDataStorage::get_ClientSecret(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveDataStorage_get_ClientSecret(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(69439554, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOneDriveDataStorage::set_ClientSecret(const std::string &Value)
{
	SBCheckError(TElOneDriveDataStorage_set_ClientSecret(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
TElHTTPSClient* TElOneDriveDataStorage::get_HTTPClient()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOneDriveDataStorage_get_HTTPClient(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HTTPClient)
		this->_Inst_HTTPClient = new TElHTTPSClient(hOutResult, ohFalse);
	else
		this->_Inst_HTTPClient->updateHandle(hOutResult);
	return this->_Inst_HTTPClient;
}

SB_INLINE void TElOneDriveDataStorage::set_HTTPClient(TElHTTPSClient &Value)
{
	SBCheckError(TElOneDriveDataStorage_set_HTTPClient(_Handle, Value.getHandle()));
}

SB_INLINE void TElOneDriveDataStorage::set_HTTPClient(TElHTTPSClient *Value)
{
	SBCheckError(TElOneDriveDataStorage_set_HTTPClient(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

void TElOneDriveDataStorage::get_Locale(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveDataStorage_get_Locale(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(479558518, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOneDriveDataStorage::set_Locale(const std::string &Value)
{
	SBCheckError(TElOneDriveDataStorage_set_Locale(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElOneDriveDataStorage::get_Overwrite()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOneDriveDataStorage_get_Overwrite(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElOneDriveDataStorage::set_Overwrite(bool Value)
{
	SBCheckError(TElOneDriveDataStorage_set_Overwrite(_Handle, (int8_t)Value));
}

bool TElOneDriveDataStorage::get_PassthroughMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOneDriveDataStorage_get_PassthroughMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElOneDriveDataStorage::set_PassthroughMode(bool Value)
{
	SBCheckError(TElOneDriveDataStorage_set_PassthroughMode(_Handle, (int8_t)Value));
}

bool TElOneDriveDataStorage::get_ReadOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOneDriveDataStorage_get_ReadOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElOneDriveDataStorage::set_ReadOnly(bool Value)
{
	SBCheckError(TElOneDriveDataStorage_set_ReadOnly(_Handle, (int8_t)Value));
}

void TElOneDriveDataStorage::get_RefreshToken(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveDataStorage_get_RefreshToken(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(520872412, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOneDriveDataStorage::set_RefreshToken(const std::string &Value)
{
	SBCheckError(TElOneDriveDataStorage_set_RefreshToken(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElOneDriveDataStorage::get_ChunkedUploadChunkSize()
{
	int64_t OutResult;
	SBCheckError(TElOneDriveDataStorage_get_ChunkedUploadChunkSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOneDriveDataStorage::set_ChunkedUploadChunkSize(int64_t Value)
{
	SBCheckError(TElOneDriveDataStorage_set_ChunkedUploadChunkSize(_Handle, Value));
}

SB_INLINE int64_t TElOneDriveDataStorage::get_ChunkedUploadThreshold()
{
	int64_t OutResult;
	SBCheckError(TElOneDriveDataStorage_get_ChunkedUploadThreshold(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOneDriveDataStorage::set_ChunkedUploadThreshold(int64_t Value)
{
	SBCheckError(TElOneDriveDataStorage_set_ChunkedUploadThreshold(_Handle, Value));
}

void TElOneDriveDataStorage::initInstances()
{
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
}

TElOneDriveDataStorage::TElOneDriveDataStorage(TElOneDriveDataStorageHandle handle, TElOwnHandle ownHandle) : TElCustomDataStorage(handle, ownHandle)
{
	initInstances();
}

TElOneDriveDataStorage::TElOneDriveDataStorage(TComponent &AOwner) : TElCustomDataStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOneDriveDataStorage_Create(AOwner.getHandle(), &_Handle));
}

TElOneDriveDataStorage::TElOneDriveDataStorage(TComponent *AOwner) : TElCustomDataStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOneDriveDataStorage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElOneDriveDataStorage::~TElOneDriveDataStorage()
{
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	delete this->_Inst_HTTPClient;
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
}
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT

SB_INLINE void TElOneDriveDataStorageObject::Assign(TElCustomDataStorageObject &Source)
{
	SBCheckError(TElOneDriveDataStorageObject_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElOneDriveDataStorageObject::Assign(TElCustomDataStorageObject *Source)
{
	SBCheckError(TElOneDriveDataStorageObject_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElOneDriveDataStorageObject::Clear()
{
	SBCheckError(TElOneDriveDataStorageObject_Clear(_Handle));
}

SB_INLINE TElCustomDataStorageObjectHandle TElOneDriveDataStorageObject::Clone()
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElOneDriveDataStorageObject_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELONEDRIVEFOLDER
SB_INLINE TElOneDriveDataStorageObjectHandle TElOneDriveDataStorageObject::Copy(TElOneDriveFolder &Destination)
{
	TElOneDriveDataStorageObjectHandle OutResult;
	SBCheckError(TElOneDriveDataStorageObject_Copy(_Handle, Destination.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElOneDriveDataStorageObjectHandle TElOneDriveDataStorageObject::Copy(TElOneDriveFolder *Destination)
{
	TElOneDriveDataStorageObjectHandle OutResult;
	SBCheckError(TElOneDriveDataStorageObject_Copy(_Handle, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELONEDRIVEFOLDER */

SB_INLINE void TElOneDriveDataStorageObject::Delete()
{
	SBCheckError(TElOneDriveDataStorageObject_Delete(_Handle));
}

#ifdef SB_USE_CLASS_TELONEDRIVEFOLDER
SB_INLINE void TElOneDriveDataStorageObject::Move(TElOneDriveFolder &Destination)
{
	SBCheckError(TElOneDriveDataStorageObject_Move(_Handle, Destination.getHandle()));
}

SB_INLINE void TElOneDriveDataStorageObject::Move(TElOneDriveFolder *Destination)
{
	SBCheckError(TElOneDriveDataStorageObject_Move(_Handle, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELONEDRIVEFOLDER */

SB_INLINE void TElOneDriveDataStorageObject::Refresh()
{
	SBCheckError(TElOneDriveDataStorageObject_Refresh(_Handle));
}

SB_INLINE void TElOneDriveDataStorageObject::Rename(const std::string &NewName)
{
	SBCheckError(TElOneDriveDataStorageObject_Rename(_Handle, NewName.data(), (int32_t)NewName.length()));
}

SB_INLINE int64_t TElOneDriveDataStorageObject::get_ClientUpdatedTime()
{
	int64_t OutResult;
	SBCheckError(TElOneDriveDataStorageObject_get_ClientUpdatedTime(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELONEDRIVECOMMENTS
TElOneDriveComments* TElOneDriveDataStorageObject::get_Comments()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOneDriveDataStorageObject_get_Comments(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Comments)
		this->_Inst_Comments = new TElOneDriveComments(hOutResult, ohFalse);
	else
		this->_Inst_Comments->updateHandle(hOutResult);
	return this->_Inst_Comments;
}
#endif /* SB_USE_CLASS_TELONEDRIVECOMMENTS */

SB_INLINE int64_t TElOneDriveDataStorageObject::get_CreatedTime()
{
	int64_t OutResult;
	SBCheckError(TElOneDriveDataStorageObject_get_CreatedTime(_Handle, &OutResult));
	return OutResult;
}

void TElOneDriveDataStorageObject::get_Description(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveDataStorageObject_get_Description(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-535790145, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOneDriveDataStorageObject::set_Description(const std::string &Value)
{
	SBCheckError(TElOneDriveDataStorageObject_set_Description(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELONEDRIVEFRIEND
TElOneDriveFriend* TElOneDriveDataStorageObject::get_From()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOneDriveDataStorageObject_get_From(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_From)
		this->_Inst_From = new TElOneDriveFriend(hOutResult, ohFalse);
	else
		this->_Inst_From->updateHandle(hOutResult);
	return this->_Inst_From;
}
#endif /* SB_USE_CLASS_TELONEDRIVEFRIEND */

void TElOneDriveDataStorageObject::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveDataStorageObject_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1358663532, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElOneDriveDataStorageObject::get_IsEmbeddable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOneDriveDataStorageObject_get_IsEmbeddable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElOneDriveDataStorageObject::get_Link(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveDataStorageObject_get_Link(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1843777127, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOneDriveDataStorageObject::get_ObjectType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveDataStorageObject_get_ObjectType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1435910481, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOneDriveDataStorageObject::get_ParentID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveDataStorageObject_get_ParentID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1075384001, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOneDriveDataStorageObject::get_SharedWith(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveDataStorageObject_get_SharedWith(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1597057785, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElOneDriveDataStorageObject::get_Size()
{
	int64_t OutResult;
	SBCheckError(TElOneDriveDataStorageObject_get_Size(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
TElOneDriveDataStorage* TElOneDriveDataStorageObject::get_Storage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOneDriveDataStorageObject_get_Storage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Storage)
		this->_Inst_Storage = new TElOneDriveDataStorage(hOutResult, ohFalse);
	else
		this->_Inst_Storage->updateHandle(hOutResult);
	return this->_Inst_Storage;
}
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

SB_INLINE int64_t TElOneDriveDataStorageObject::get_UpdatedTime()
{
	int64_t OutResult;
	SBCheckError(TElOneDriveDataStorageObject_get_UpdatedTime(_Handle, &OutResult));
	return OutResult;
}

void TElOneDriveDataStorageObject::get_UploadLocation(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveDataStorageObject_get_UploadLocation(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-886295467, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOneDriveDataStorageObject::initInstances()
{
#ifdef SB_USE_CLASS_TELONEDRIVECOMMENTS
	this->_Inst_Comments = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVECOMMENTS */
#ifdef SB_USE_CLASS_TELONEDRIVEFRIEND
	this->_Inst_From = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVEFRIEND */
#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
	this->_Inst_Storage = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */
}

TElOneDriveDataStorageObject::TElOneDriveDataStorageObject(TElOneDriveDataStorageObjectHandle handle, TElOwnHandle ownHandle) : TElCustomDataStorageObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
TElOneDriveDataStorageObject::TElOneDriveDataStorageObject(TElOneDriveDataStorage &AStorage) : TElCustomDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOneDriveDataStorageObject_Create(AStorage.getHandle(), &_Handle));
}

TElOneDriveDataStorageObject::TElOneDriveDataStorageObject(TElOneDriveDataStorage *AStorage) : TElCustomDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOneDriveDataStorageObject_Create((AStorage != NULL) ? AStorage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

TElOneDriveDataStorageObject::~TElOneDriveDataStorageObject()
{
#ifdef SB_USE_CLASS_TELONEDRIVECOMMENTS
	delete this->_Inst_Comments;
	this->_Inst_Comments = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVECOMMENTS */
#ifdef SB_USE_CLASS_TELONEDRIVEFRIEND
	delete this->_Inst_From;
	this->_Inst_From = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVEFRIEND */
#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
	delete this->_Inst_Storage;
	this->_Inst_Storage = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */
}
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELONEDRIVEFOLDER

SB_INLINE void TElOneDriveFolder::Assign(TElCustomDataStorageObject &Source)
{
	SBCheckError(TElOneDriveFolder_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElOneDriveFolder::Assign(TElCustomDataStorageObject *Source)
{
	SBCheckError(TElOneDriveFolder_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElOneDriveFolder::Clear()
{
	SBCheckError(TElOneDriveFolder_Clear(_Handle));
}

SB_INLINE TElCustomDataStorageObjectHandle TElOneDriveFolder::Clone()
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElOneDriveFolder_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE TElOneDriveFolderHandle TElOneDriveFolder::CreateFolder(const std::string &Name, const std::string &Description)
{
	TElOneDriveFolderHandle OutResult;
	SBCheckError(TElOneDriveFolder_CreateFolder(_Handle, Name.data(), (int32_t)Name.length(), Description.data(), (int32_t)Description.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELONEDRIVEFILE
SB_INLINE TElOneDriveFileHandle TElOneDriveFolder::CreateObject(const std::string &Name, bool OverwriteIfExists)
{
	TElOneDriveFileHandle OutResult;
	SBCheckError(TElOneDriveFolder_CreateObject(_Handle, Name.data(), (int32_t)Name.length(), (int8_t)OverwriteIfExists, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELONEDRIVEFILE */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELONEDRIVEFILE
SB_INLINE TElOneDriveFileHandle TElOneDriveFolder::CreateObject(const std::string &Name, bool OverwriteIfExists, TElCustomDataStorageSecurityHandler &Handler)
{
	TElOneDriveFileHandle OutResult;
	SBCheckError(TElOneDriveFolder_CreateObject_1(_Handle, Name.data(), (int32_t)Name.length(), (int8_t)OverwriteIfExists, Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElOneDriveFileHandle TElOneDriveFolder::CreateObject(const std::string &Name, bool OverwriteIfExists, TElCustomDataStorageSecurityHandler *Handler)
{
	TElOneDriveFileHandle OutResult;
	SBCheckError(TElOneDriveFolder_CreateObject_1(_Handle, Name.data(), (int32_t)Name.length(), (int8_t)OverwriteIfExists, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELONEDRIVEFILE */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElOneDriveFolder::List(TElDataStorageObjectList &Objects)
{
	SBCheckError(TElOneDriveFolder_List(_Handle, Objects.getHandle()));
}

SB_INLINE void TElOneDriveFolder::List(TElDataStorageObjectList *Objects)
{
	SBCheckError(TElOneDriveFolder_List(_Handle, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElOneDriveFolder::ListFolders(TElDataStorageObjectList &Objects)
{
	SBCheckError(TElOneDriveFolder_ListFolders(_Handle, Objects.getHandle()));
}

SB_INLINE void TElOneDriveFolder::ListFolders(TElDataStorageObjectList *Objects)
{
	SBCheckError(TElOneDriveFolder_ListFolders(_Handle, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

SB_INLINE uint32_t TElOneDriveFolder::get_Count()
{
	uint32_t OutResult;
	SBCheckError(TElOneDriveFolder_get_Count(_Handle, &OutResult));
	return OutResult;
}

TElOneDriveFolder::TElOneDriveFolder(TElOneDriveFolderHandle handle, TElOwnHandle ownHandle) : TElOneDriveDataStorageObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
TElOneDriveFolder::TElOneDriveFolder(TElOneDriveDataStorage &Storage) : TElOneDriveDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOneDriveFolder_Create(Storage.getHandle(), &_Handle));
}

TElOneDriveFolder::TElOneDriveFolder(TElOneDriveDataStorage *Storage) : TElOneDriveDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOneDriveFolder_Create((Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

#endif /* SB_USE_CLASS_TELONEDRIVEFOLDER */

#ifdef SB_USE_CLASS_TELONEDRIVECOMMENTS

#ifdef SB_USE_CLASS_TELONEDRIVECOMMENT
SB_INLINE TElOneDriveCommentHandle TElOneDriveComments::Add(const std::string &Message)
{
	TElOneDriveCommentHandle OutResult;
	SBCheckError(TElOneDriveComments_Add(_Handle, Message.data(), (int32_t)Message.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELONEDRIVECOMMENT */

SB_INLINE void TElOneDriveComments::Assign(TElOneDriveComments &Source)
{
	SBCheckError(TElOneDriveComments_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElOneDriveComments::Assign(TElOneDriveComments *Source)
{
	SBCheckError(TElOneDriveComments_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElOneDriveComments::Clear()
{
	SBCheckError(TElOneDriveComments_Clear(_Handle));
}

SB_INLINE void TElOneDriveComments::Refresh()
{
	SBCheckError(TElOneDriveComments_Refresh(_Handle));
}

SB_INLINE int32_t TElOneDriveComments::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElOneDriveComments_get_Count(_Handle, &OutResult));
	return OutResult;
}

bool TElOneDriveComments::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOneDriveComments_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELONEDRIVECOMMENT
TElOneDriveComment* TElOneDriveComments::get_Items(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOneDriveComments_get_Items(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Items)
		this->_Inst_Items = new TElOneDriveComment(hOutResult, ohFalse);
	else
		this->_Inst_Items->updateHandle(hOutResult);
	return this->_Inst_Items;
}
#endif /* SB_USE_CLASS_TELONEDRIVECOMMENT */

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT
TElOneDriveDataStorageObject* TElOneDriveComments::get_Owner()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOneDriveComments_get_Owner(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Owner)
		this->_Inst_Owner = new TElOneDriveDataStorageObject(hOutResult, ohFalse);
	else
		this->_Inst_Owner->updateHandle(hOutResult);
	return this->_Inst_Owner;
}
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT */

void TElOneDriveComments::initInstances()
{
#ifdef SB_USE_CLASS_TELONEDRIVECOMMENT
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVECOMMENT */
#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT */
}

TElOneDriveComments::TElOneDriveComments(TElOneDriveCommentsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT
TElOneDriveComments::TElOneDriveComments(TElOneDriveDataStorageObject &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOneDriveComments_Create(AOwner.getHandle(), &_Handle));
}

TElOneDriveComments::TElOneDriveComments(TElOneDriveDataStorageObject *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOneDriveComments_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT */

TElOneDriveComments::~TElOneDriveComments()
{
#ifdef SB_USE_CLASS_TELONEDRIVECOMMENT
	delete this->_Inst_Items;
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVECOMMENT */
#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT
	delete this->_Inst_Owner;
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT */
}
#endif /* SB_USE_CLASS_TELONEDRIVECOMMENTS */

#ifdef SB_USE_CLASS_TELONEDRIVETAGS

SB_INLINE void TElOneDriveTags::Assign(TElOneDriveTags &Source)
{
	SBCheckError(TElOneDriveTags_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElOneDriveTags::Assign(TElOneDriveTags *Source)
{
	SBCheckError(TElOneDriveTags_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElOneDriveTags::Clear()
{
	SBCheckError(TElOneDriveTags_Clear(_Handle));
}

SB_INLINE void TElOneDriveTags::Refresh()
{
	SBCheckError(TElOneDriveTags_Refresh(_Handle));
}

SB_INLINE int32_t TElOneDriveTags::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElOneDriveTags_get_Count(_Handle, &OutResult));
	return OutResult;
}

bool TElOneDriveTags::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOneDriveTags_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELONEDRIVETAG
TElOneDriveTag* TElOneDriveTags::get_Items(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOneDriveTags_get_Items(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Items)
		this->_Inst_Items = new TElOneDriveTag(hOutResult, ohFalse);
	else
		this->_Inst_Items->updateHandle(hOutResult);
	return this->_Inst_Items;
}
#endif /* SB_USE_CLASS_TELONEDRIVETAG */

#ifdef SB_USE_CLASS_TELONEDRIVETAGGEDOBJECT
TElOneDriveTaggedObject* TElOneDriveTags::get_Owner()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOneDriveTags_get_Owner(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Owner)
		this->_Inst_Owner = new TElOneDriveTaggedObject(hOutResult, ohFalse);
	else
		this->_Inst_Owner->updateHandle(hOutResult);
	return this->_Inst_Owner;
}
#endif /* SB_USE_CLASS_TELONEDRIVETAGGEDOBJECT */

void TElOneDriveTags::initInstances()
{
#ifdef SB_USE_CLASS_TELONEDRIVETAG
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVETAG */
#ifdef SB_USE_CLASS_TELONEDRIVETAGGEDOBJECT
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVETAGGEDOBJECT */
}

TElOneDriveTags::TElOneDriveTags(TElOneDriveTagsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELONEDRIVETAGGEDOBJECT
TElOneDriveTags::TElOneDriveTags(TElOneDriveTaggedObject &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOneDriveTags_Create(AOwner.getHandle(), &_Handle));
}

TElOneDriveTags::TElOneDriveTags(TElOneDriveTaggedObject *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOneDriveTags_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELONEDRIVETAGGEDOBJECT */

TElOneDriveTags::~TElOneDriveTags()
{
#ifdef SB_USE_CLASS_TELONEDRIVETAG
	delete this->_Inst_Items;
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVETAG */
#ifdef SB_USE_CLASS_TELONEDRIVETAGGEDOBJECT
	delete this->_Inst_Owner;
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVETAGGEDOBJECT */
}
#endif /* SB_USE_CLASS_TELONEDRIVETAGS */

#ifdef SB_USE_CLASS_TELONEDRIVEFILE

SB_INLINE void TElOneDriveFile::Assign(TElCustomDataStorageObject &Source)
{
	SBCheckError(TElOneDriveFile_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElOneDriveFile::Assign(TElCustomDataStorageObject *Source)
{
	SBCheckError(TElOneDriveFile_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElOneDriveFile::CancelUpload()
{
	SBCheckError(TElOneDriveFile_CancelUpload(_Handle));
}

SB_INLINE void TElOneDriveFile::Clear()
{
	SBCheckError(TElOneDriveFile_Clear(_Handle));
}

SB_INLINE TElCustomDataStorageObjectHandle TElOneDriveFile::Clone()
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElOneDriveFile_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOneDriveFile::Read(TStream &Target)
{
	SBCheckError(TElOneDriveFile_Read(_Handle, Target.getHandle()));
}

SB_INLINE void TElOneDriveFile::Read(TStream *Target)
{
	SBCheckError(TElOneDriveFile_Read(_Handle, (Target != NULL) ? Target->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOneDriveFile::Write(TStream &Source)
{
	SBCheckError(TElOneDriveFile_Write(_Handle, Source.getHandle()));
}

SB_INLINE void TElOneDriveFile::Write(TStream *Source)
{
	SBCheckError(TElOneDriveFile_Write(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElOneDriveFile::Write(TStream &Source, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElOneDriveFile_Write_1(_Handle, Source.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElOneDriveFile::Write(TStream *Source, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElOneDriveFile_Write_1(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

void TElOneDriveFile::get_Source(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveFile_get_Source(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1141081693, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElOneDriveFile::TElOneDriveFile(TElOneDriveFileHandle handle, TElOwnHandle ownHandle) : TElOneDriveDataStorageObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
TElOneDriveFile::TElOneDriveFile(TElOneDriveDataStorage &AStorage) : TElOneDriveDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOneDriveFile_Create(AStorage.getHandle(), &_Handle));
}

TElOneDriveFile::TElOneDriveFile(TElOneDriveDataStorage *AStorage) : TElOneDriveDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOneDriveFile_Create((AStorage != NULL) ? AStorage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

#endif /* SB_USE_CLASS_TELONEDRIVEFILE */

#ifdef SB_USE_CLASS_TELONEDRIVEFRIEND

SB_INLINE void TElOneDriveFriend::Assign(TElOneDriveFriend &Source)
{
	SBCheckError(TElOneDriveFriend_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElOneDriveFriend::Assign(TElOneDriveFriend *Source)
{
	SBCheckError(TElOneDriveFriend_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElOneDriveFriend::Clear()
{
	SBCheckError(TElOneDriveFriend_Clear(_Handle));
}

SB_INLINE TElOneDriveFriendHandle TElOneDriveFriend::Clone()
{
	TElOneDriveFriendHandle OutResult;
	SBCheckError(TElOneDriveFriend_Clone(_Handle, &OutResult));
	return OutResult;
}

void TElOneDriveFriend::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveFriend_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1926298813, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOneDriveFriend::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveFriend_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(210238684, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElOneDriveFriend::TElOneDriveFriend(TElOneDriveFriendHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElOneDriveFriend::TElOneDriveFriend() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOneDriveFriend_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELONEDRIVEFRIEND */

#ifdef SB_USE_CLASS_TELONEDRIVECOMMENT

SB_INLINE TElOneDriveCommentHandle TElOneDriveComment::Clone()
{
	TElOneDriveCommentHandle OutResult;
	SBCheckError(TElOneDriveComment_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOneDriveComment::Delete()
{
	SBCheckError(TElOneDriveComment_Delete(_Handle));
}

SB_INLINE int64_t TElOneDriveComment::get_CreatedTime()
{
	int64_t OutResult;
	SBCheckError(TElOneDriveComment_get_CreatedTime(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELONEDRIVEFRIEND
TElOneDriveFriend* TElOneDriveComment::get_From()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOneDriveComment_get_From(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_From)
		this->_Inst_From = new TElOneDriveFriend(hOutResult, ohFalse);
	else
		this->_Inst_From->updateHandle(hOutResult);
	return this->_Inst_From;
}
#endif /* SB_USE_CLASS_TELONEDRIVEFRIEND */

void TElOneDriveComment::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveComment_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-496898025, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOneDriveComment::get_Message(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveComment_get_Message(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-791821567, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOneDriveComment::initInstances()
{
#ifdef SB_USE_CLASS_TELONEDRIVEFRIEND
	this->_Inst_From = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVEFRIEND */
}

TElOneDriveComment::TElOneDriveComment(TElOneDriveCommentHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELONEDRIVECOMMENTS
TElOneDriveComment::TElOneDriveComment(TElOneDriveComments &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOneDriveComment_Create(AOwner.getHandle(), &_Handle));
}

TElOneDriveComment::TElOneDriveComment(TElOneDriveComments *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOneDriveComment_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELONEDRIVECOMMENTS */

TElOneDriveComment::~TElOneDriveComment()
{
#ifdef SB_USE_CLASS_TELONEDRIVEFRIEND
	delete this->_Inst_From;
	this->_Inst_From = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVEFRIEND */
}
#endif /* SB_USE_CLASS_TELONEDRIVECOMMENT */

#ifdef SB_USE_CLASS_TELONEDRIVETAGGEDOBJECT

SB_INLINE void TElOneDriveTaggedObject::Assign(TElCustomDataStorageObject &Source)
{
	SBCheckError(TElOneDriveTaggedObject_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElOneDriveTaggedObject::Assign(TElCustomDataStorageObject *Source)
{
	SBCheckError(TElOneDriveTaggedObject_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElOneDriveTaggedObject::Clear()
{
	SBCheckError(TElOneDriveTaggedObject_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELONEDRIVETAGS
TElOneDriveTags* TElOneDriveTaggedObject::get_Tags()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOneDriveTaggedObject_get_Tags(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Tags)
		this->_Inst_Tags = new TElOneDriveTags(hOutResult, ohFalse);
	else
		this->_Inst_Tags->updateHandle(hOutResult);
	return this->_Inst_Tags;
}
#endif /* SB_USE_CLASS_TELONEDRIVETAGS */

void TElOneDriveTaggedObject::initInstances()
{
#ifdef SB_USE_CLASS_TELONEDRIVETAGS
	this->_Inst_Tags = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVETAGS */
}

TElOneDriveTaggedObject::TElOneDriveTaggedObject(TElOneDriveTaggedObjectHandle handle, TElOwnHandle ownHandle) : TElOneDriveFile(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
TElOneDriveTaggedObject::TElOneDriveTaggedObject(TElOneDriveDataStorage &AStorage) : TElOneDriveFile(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOneDriveTaggedObject_Create(AStorage.getHandle(), &_Handle));
}

TElOneDriveTaggedObject::TElOneDriveTaggedObject(TElOneDriveDataStorage *AStorage) : TElOneDriveFile(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOneDriveTaggedObject_Create((AStorage != NULL) ? AStorage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

TElOneDriveTaggedObject::~TElOneDriveTaggedObject()
{
#ifdef SB_USE_CLASS_TELONEDRIVETAGS
	delete this->_Inst_Tags;
	this->_Inst_Tags = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVETAGS */
}
#endif /* SB_USE_CLASS_TELONEDRIVETAGGEDOBJECT */

#ifdef SB_USE_CLASS_TELONEDRIVETAG

SB_INLINE TElOneDriveTagHandle TElOneDriveTag::Clone()
{
	TElOneDriveTagHandle OutResult;
	SBCheckError(TElOneDriveTag_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElOneDriveTag::get_CreatedTime()
{
	int64_t OutResult;
	SBCheckError(TElOneDriveTag_get_CreatedTime(_Handle, &OutResult));
	return OutResult;
}

void TElOneDriveTag::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveTag_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(792028368, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELONEDRIVEFRIEND
TElOneDriveFriend* TElOneDriveTag::get_User()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOneDriveTag_get_User(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_User)
		this->_Inst_User = new TElOneDriveFriend(hOutResult, ohFalse);
	else
		this->_Inst_User->updateHandle(hOutResult);
	return this->_Inst_User;
}
#endif /* SB_USE_CLASS_TELONEDRIVEFRIEND */

SB_INLINE double TElOneDriveTag::get_X()
{
	double OutResult;
	SBCheckError(TElOneDriveTag_get_X(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE double TElOneDriveTag::get_Y()
{
	double OutResult;
	SBCheckError(TElOneDriveTag_get_Y(_Handle, &OutResult));
	return OutResult;
}

void TElOneDriveTag::initInstances()
{
#ifdef SB_USE_CLASS_TELONEDRIVEFRIEND
	this->_Inst_User = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVEFRIEND */
}

TElOneDriveTag::TElOneDriveTag(TElOneDriveTagHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELONEDRIVETAGS
TElOneDriveTag::TElOneDriveTag(TElOneDriveTags &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOneDriveTag_Create(AOwner.getHandle(), &_Handle));
}

TElOneDriveTag::TElOneDriveTag(TElOneDriveTags *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOneDriveTag_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELONEDRIVETAGS */

TElOneDriveTag::~TElOneDriveTag()
{
#ifdef SB_USE_CLASS_TELONEDRIVEFRIEND
	delete this->_Inst_User;
	this->_Inst_User = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVEFRIEND */
}
#endif /* SB_USE_CLASS_TELONEDRIVETAG */

#ifdef SB_USE_CLASS_TELONEDRIVENOTEBOOK

TElOneDriveNotebook::TElOneDriveNotebook(TElOneDriveNotebookHandle handle, TElOwnHandle ownHandle) : TElOneDriveFile(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
TElOneDriveNotebook::TElOneDriveNotebook(TElOneDriveDataStorage &AStorage) : TElOneDriveFile(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOneDriveNotebook_Create(AStorage.getHandle(), &_Handle));
}

TElOneDriveNotebook::TElOneDriveNotebook(TElOneDriveDataStorage *AStorage) : TElOneDriveFile(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOneDriveNotebook_Create((AStorage != NULL) ? AStorage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

#endif /* SB_USE_CLASS_TELONEDRIVENOTEBOOK */

#ifdef SB_USE_CLASS_TELONEDRIVEAUDIO

SB_INLINE void TElOneDriveAudio::Assign(TElCustomDataStorageObject &Source)
{
	SBCheckError(TElOneDriveAudio_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElOneDriveAudio::Assign(TElCustomDataStorageObject *Source)
{
	SBCheckError(TElOneDriveAudio_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElOneDriveAudio::Clear()
{
	SBCheckError(TElOneDriveAudio_Clear(_Handle));
}

SB_INLINE TElCustomDataStorageObjectHandle TElOneDriveAudio::Clone()
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElOneDriveAudio_Clone(_Handle, &OutResult));
	return OutResult;
}

void TElOneDriveAudio::get_Album(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveAudio_get_Album(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1069550746, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOneDriveAudio::set_Album(const std::string &Value)
{
	SBCheckError(TElOneDriveAudio_set_Album(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOneDriveAudio::get_AlbumArtist(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveAudio_get_AlbumArtist(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1757370723, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOneDriveAudio::set_AlbumArtist(const std::string &Value)
{
	SBCheckError(TElOneDriveAudio_set_AlbumArtist(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOneDriveAudio::get_Artist(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveAudio_get_Artist(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(743590680, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOneDriveAudio::set_Artist(const std::string &Value)
{
	SBCheckError(TElOneDriveAudio_set_Artist(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElOneDriveAudio::get_Duration()
{
	int64_t OutResult;
	SBCheckError(TElOneDriveAudio_get_Duration(_Handle, &OutResult));
	return OutResult;
}

void TElOneDriveAudio::get_Genre(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveAudio_get_Genre(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2063052511, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOneDriveAudio::set_Genre(const std::string &Value)
{
	SBCheckError(TElOneDriveAudio_set_Genre(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOneDriveAudio::get_Picture(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveAudio_get_Picture(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1539037940, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOneDriveAudio::get_Title(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveAudio_get_Title(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(762190514, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOneDriveAudio::set_Title(const std::string &Value)
{
	SBCheckError(TElOneDriveAudio_set_Title(_Handle, Value.data(), (int32_t)Value.length()));
}

TElOneDriveAudio::TElOneDriveAudio(TElOneDriveAudioHandle handle, TElOwnHandle ownHandle) : TElOneDriveFile(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
TElOneDriveAudio::TElOneDriveAudio(TElOneDriveDataStorage &AStorage) : TElOneDriveFile(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOneDriveAudio_Create(AStorage.getHandle(), &_Handle));
}

TElOneDriveAudio::TElOneDriveAudio(TElOneDriveDataStorage *AStorage) : TElOneDriveFile(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOneDriveAudio_Create((AStorage != NULL) ? AStorage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

#endif /* SB_USE_CLASS_TELONEDRIVEAUDIO */

#ifdef SB_USE_CLASS_TELONEDRIVEPHOTO

SB_INLINE void TElOneDrivePhoto::Assign(TElCustomDataStorageObject &Source)
{
	SBCheckError(TElOneDrivePhoto_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElOneDrivePhoto::Assign(TElCustomDataStorageObject *Source)
{
	SBCheckError(TElOneDrivePhoto_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElOneDrivePhoto::Clear()
{
	SBCheckError(TElOneDrivePhoto_Clear(_Handle));
}

SB_INLINE TElCustomDataStorageObjectHandle TElOneDrivePhoto::Clone()
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElOneDrivePhoto_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE double TElOneDrivePhoto::get_Altitude()
{
	double OutResult;
	SBCheckError(TElOneDrivePhoto_get_Altitude(_Handle, &OutResult));
	return OutResult;
}

void TElOneDrivePhoto::get_CameraMaker(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDrivePhoto_get_CameraMaker(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1215691604, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOneDrivePhoto::get_CameraModel(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDrivePhoto_get_CameraModel(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1509553721, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE double TElOneDrivePhoto::get_ExposureDenominator()
{
	double OutResult;
	SBCheckError(TElOneDrivePhoto_get_ExposureDenominator(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE double TElOneDrivePhoto::get_ExposureNumerator()
{
	double OutResult;
	SBCheckError(TElOneDrivePhoto_get_ExposureNumerator(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE double TElOneDrivePhoto::get_FocalLength()
{
	double OutResult;
	SBCheckError(TElOneDrivePhoto_get_FocalLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE double TElOneDrivePhoto::get_FocalRatio()
{
	double OutResult;
	SBCheckError(TElOneDrivePhoto_get_FocalRatio(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOneDrivePhoto::get_Height()
{
	int32_t OutResult;
	SBCheckError(TElOneDrivePhoto_get_Height(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGES
TElOneDrivePhotoImages* TElOneDrivePhoto::get_Images()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOneDrivePhoto_get_Images(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Images)
		this->_Inst_Images = new TElOneDrivePhotoImages(hOutResult, ohFalse);
	else
		this->_Inst_Images->updateHandle(hOutResult);
	return this->_Inst_Images;
}
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGES */

SB_INLINE double TElOneDrivePhoto::get_Latitude()
{
	double OutResult;
	SBCheckError(TElOneDrivePhoto_get_Latitude(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE double TElOneDrivePhoto::get_Longitude()
{
	double OutResult;
	SBCheckError(TElOneDrivePhoto_get_Longitude(_Handle, &OutResult));
	return OutResult;
}

void TElOneDrivePhoto::get_Picture(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDrivePhoto_get_Picture(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-731717316, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElOneDrivePhoto::get_WhenTaken()
{
	int64_t OutResult;
	SBCheckError(TElOneDrivePhoto_get_WhenTaken(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOneDrivePhoto::get_Width()
{
	int32_t OutResult;
	SBCheckError(TElOneDrivePhoto_get_Width(_Handle, &OutResult));
	return OutResult;
}

void TElOneDrivePhoto::initInstances()
{
#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGES
	this->_Inst_Images = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGES */
}

TElOneDrivePhoto::TElOneDrivePhoto(TElOneDrivePhotoHandle handle, TElOwnHandle ownHandle) : TElOneDriveTaggedObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
TElOneDrivePhoto::TElOneDrivePhoto(TElOneDriveDataStorage &Storage) : TElOneDriveTaggedObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOneDrivePhoto_Create(Storage.getHandle(), &_Handle));
}

TElOneDrivePhoto::TElOneDrivePhoto(TElOneDriveDataStorage *Storage) : TElOneDriveTaggedObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOneDrivePhoto_Create((Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

TElOneDrivePhoto::~TElOneDrivePhoto()
{
#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGES
	delete this->_Inst_Images;
	this->_Inst_Images = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGES */
}
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTO */

#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE

SB_INLINE void TElOneDrivePhotoImage::Clear()
{
	SBCheckError(TElOneDrivePhotoImage_Clear(_Handle));
}

SB_INLINE TElOneDrivePhotoImageHandle TElOneDrivePhotoImage::Clone()
{
	TElOneDrivePhotoImageHandle OutResult;
	SBCheckError(TElOneDrivePhotoImage_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOneDrivePhotoImage::get_Height()
{
	int32_t OutResult;
	SBCheckError(TElOneDrivePhotoImage_get_Height(_Handle, &OutResult));
	return OutResult;
}

void TElOneDrivePhotoImage::get_ImageType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDrivePhotoImage_get_ImageType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1409509683, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOneDrivePhotoImage::get_Source(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDrivePhotoImage_get_Source(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-571037465, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElOneDrivePhotoImage::get_Width()
{
	int32_t OutResult;
	SBCheckError(TElOneDrivePhotoImage_get_Width(_Handle, &OutResult));
	return OutResult;
}

TElOneDrivePhotoImage::TElOneDrivePhotoImage(TElOneDrivePhotoImageHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElOneDrivePhotoImage::TElOneDrivePhotoImage() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOneDrivePhotoImage_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */

#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGES

SB_INLINE void TElOneDrivePhotoImages::Assign(TElOneDrivePhotoImages &Source)
{
	SBCheckError(TElOneDrivePhotoImages_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElOneDrivePhotoImages::Assign(TElOneDrivePhotoImages *Source)
{
	SBCheckError(TElOneDrivePhotoImages_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElOneDrivePhotoImages::Clear()
{
	SBCheckError(TElOneDrivePhotoImages_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
TElOneDrivePhotoImage* TElOneDrivePhotoImages::get_Album()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOneDrivePhotoImages_get_Album(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Album)
		this->_Inst_Album = new TElOneDrivePhotoImage(hOutResult, ohFalse);
	else
		this->_Inst_Album->updateHandle(hOutResult);
	return this->_Inst_Album;
}
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */

SB_INLINE int32_t TElOneDrivePhotoImages::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElOneDrivePhotoImages_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
TElOneDrivePhotoImage* TElOneDrivePhotoImages::get_Full()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOneDrivePhotoImages_get_Full(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Full)
		this->_Inst_Full = new TElOneDrivePhotoImage(hOutResult, ohFalse);
	else
		this->_Inst_Full->updateHandle(hOutResult);
	return this->_Inst_Full;
}
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */

#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
TElOneDrivePhotoImage* TElOneDrivePhotoImages::get_Items(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOneDrivePhotoImages_get_Items(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Items)
		this->_Inst_Items = new TElOneDrivePhotoImage(hOutResult, ohFalse);
	else
		this->_Inst_Items->updateHandle(hOutResult);
	return this->_Inst_Items;
}
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */

#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
TElOneDrivePhotoImage* TElOneDrivePhotoImages::get_Normal()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOneDrivePhotoImages_get_Normal(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Normal)
		this->_Inst_Normal = new TElOneDrivePhotoImage(hOutResult, ohFalse);
	else
		this->_Inst_Normal->updateHandle(hOutResult);
	return this->_Inst_Normal;
}
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */

#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
TElOneDrivePhotoImage* TElOneDrivePhotoImages::get_Small()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOneDrivePhotoImages_get_Small(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Small)
		this->_Inst_Small = new TElOneDrivePhotoImage(hOutResult, ohFalse);
	else
		this->_Inst_Small->updateHandle(hOutResult);
	return this->_Inst_Small;
}
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */

void TElOneDrivePhotoImages::initInstances()
{
#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
	this->_Inst_Album = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */
#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
	this->_Inst_Full = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */
#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */
#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
	this->_Inst_Normal = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */
#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
	this->_Inst_Small = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */
}

TElOneDrivePhotoImages::TElOneDrivePhotoImages(TElOneDrivePhotoImagesHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElOneDrivePhotoImages::TElOneDrivePhotoImages() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOneDrivePhotoImages_Create(&_Handle));
}

TElOneDrivePhotoImages::~TElOneDrivePhotoImages()
{
#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
	delete this->_Inst_Album;
	this->_Inst_Album = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */
#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
	delete this->_Inst_Full;
	this->_Inst_Full = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */
#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
	delete this->_Inst_Items;
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */
#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
	delete this->_Inst_Normal;
	this->_Inst_Normal = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */
#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
	delete this->_Inst_Small;
	this->_Inst_Small = NULL;
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */
}
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGES */

#ifdef SB_USE_CLASS_TELONEDRIVEVIDEO

SB_INLINE void TElOneDriveVideo::Assign(TElCustomDataStorageObject &Source)
{
	SBCheckError(TElOneDriveVideo_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElOneDriveVideo::Assign(TElCustomDataStorageObject *Source)
{
	SBCheckError(TElOneDriveVideo_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElOneDriveVideo::Clear()
{
	SBCheckError(TElOneDriveVideo_Clear(_Handle));
}

SB_INLINE TElCustomDataStorageObjectHandle TElOneDriveVideo::Clone()
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElOneDriveVideo_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOneDriveVideo::get_Bitrate()
{
	int32_t OutResult;
	SBCheckError(TElOneDriveVideo_get_Bitrate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElOneDriveVideo::get_Duration()
{
	int64_t OutResult;
	SBCheckError(TElOneDriveVideo_get_Duration(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOneDriveVideo::get_Height()
{
	int32_t OutResult;
	SBCheckError(TElOneDriveVideo_get_Height(_Handle, &OutResult));
	return OutResult;
}

void TElOneDriveVideo::get_Picture(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveVideo_get_Picture(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-126370751, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElOneDriveVideo::get_Width()
{
	int32_t OutResult;
	SBCheckError(TElOneDriveVideo_get_Width(_Handle, &OutResult));
	return OutResult;
}

TElOneDriveVideo::TElOneDriveVideo(TElOneDriveVideoHandle handle, TElOwnHandle ownHandle) : TElOneDriveTaggedObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
TElOneDriveVideo::TElOneDriveVideo(TElOneDriveDataStorage &Storage) : TElOneDriveTaggedObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOneDriveVideo_Create(Storage.getHandle(), &_Handle));
}

TElOneDriveVideo::TElOneDriveVideo(TElOneDriveDataStorage *Storage) : TElOneDriveTaggedObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOneDriveVideo_Create((Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

#endif /* SB_USE_CLASS_TELONEDRIVEVIDEO */

#ifdef SB_USE_CLASS_TELONEDRIVEALBUM

SB_INLINE TElCustomDataStorageObjectHandle TElOneDriveAlbum::Clone()
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElOneDriveAlbum_Clone(_Handle, &OutResult));
	return OutResult;
}

TElOneDriveAlbum::TElOneDriveAlbum(TElOneDriveAlbumHandle handle, TElOwnHandle ownHandle) : TElOneDriveFolder(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
TElOneDriveAlbum::TElOneDriveAlbum(TElOneDriveDataStorage &Storage) : TElOneDriveFolder(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOneDriveAlbum_Create(Storage.getHandle(), &_Handle));
}

TElOneDriveAlbum::TElOneDriveAlbum(TElOneDriveDataStorage *Storage) : TElOneDriveFolder(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOneDriveAlbum_Create((Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

#endif /* SB_USE_CLASS_TELONEDRIVEALBUM */

#ifdef SB_USE_CLASS_TELONEDRIVEUSERINFO

SB_INLINE void TElOneDriveUserInfo::Assign(TElOneDriveUserInfo &Source)
{
	SBCheckError(TElOneDriveUserInfo_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElOneDriveUserInfo::Assign(TElOneDriveUserInfo *Source)
{
	SBCheckError(TElOneDriveUserInfo_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElOneDriveUserInfo::Clear()
{
	SBCheckError(TElOneDriveUserInfo_Clear(_Handle));
}

SB_INLINE TElOneDriveUserInfoHandle TElOneDriveUserInfo::Clone()
{
	TElOneDriveUserInfoHandle OutResult;
	SBCheckError(TElOneDriveUserInfo_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOneDriveUserInfo::Refresh()
{
	SBCheckError(TElOneDriveUserInfo_Refresh(_Handle));
}

void TElOneDriveUserInfo::get_FirstName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveUserInfo_get_FirstName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-377699222, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOneDriveUserInfo::set_FirstName(const std::string &Value)
{
	SBCheckError(TElOneDriveUserInfo_set_FirstName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOneDriveUserInfo::get_Gender(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveUserInfo_get_Gender(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1493794507, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOneDriveUserInfo::set_Gender(const std::string &Value)
{
	SBCheckError(TElOneDriveUserInfo_set_Gender(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOneDriveUserInfo::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveUserInfo_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(213529877, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOneDriveUserInfo::set_ID(const std::string &Value)
{
	SBCheckError(TElOneDriveUserInfo_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOneDriveUserInfo::get_LastName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveUserInfo_get_LastName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-891560865, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOneDriveUserInfo::set_LastName(const std::string &Value)
{
	SBCheckError(TElOneDriveUserInfo_set_LastName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOneDriveUserInfo::get_Link(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveUserInfo_get_Link(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1196684789, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOneDriveUserInfo::set_Link(const std::string &Value)
{
	SBCheckError(TElOneDriveUserInfo_set_Link(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOneDriveUserInfo::get_Locale(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveUserInfo_get_Locale(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(540102127, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOneDriveUserInfo::set_Locale(const std::string &Value)
{
	SBCheckError(TElOneDriveUserInfo_set_Locale(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOneDriveUserInfo::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOneDriveUserInfo_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(802951682, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOneDriveUserInfo::set_Name(const std::string &Value)
{
	SBCheckError(TElOneDriveUserInfo_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElOneDriveUserInfo::get_UpdatedTime()
{
	int64_t OutResult;
	SBCheckError(TElOneDriveUserInfo_get_UpdatedTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOneDriveUserInfo::set_UpdatedTime(int64_t Value)
{
	SBCheckError(TElOneDriveUserInfo_set_UpdatedTime(_Handle, Value));
}

TElOneDriveUserInfo::TElOneDriveUserInfo(TElOneDriveUserInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
TElOneDriveUserInfo::TElOneDriveUserInfo(TElOneDriveDataStorage &AStorage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOneDriveUserInfo_Create(AStorage.getHandle(), &_Handle));
}

TElOneDriveUserInfo::TElOneDriveUserInfo(TElOneDriveDataStorage *AStorage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOneDriveUserInfo_Create((AStorage != NULL) ? AStorage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

#endif /* SB_USE_CLASS_TELONEDRIVEUSERINFO */

};	/* namespace SecureBlackbox */

