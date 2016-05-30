#include "sbboxdatastorage.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELBOXDATASTORAGE

void TElBoxDataStorage::StartAuthorization(const std::string &RedirectURL, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxDataStorage_StartAuthorization(_Handle, RedirectURL.data(), (int32_t)RedirectURL.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-362728436, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBoxDataStorage::CompleteAuthorization(const std::string &AuthorizationCode)
{
	SBCheckError(TElBoxDataStorage_CompleteAuthorization(_Handle, AuthorizationCode.data(), (int32_t)AuthorizationCode.length()));
}

SB_INLINE void TElBoxDataStorage::CloseSession()
{
	SBCheckError(TElBoxDataStorage_CloseSession(_Handle));
}

#ifdef SB_USE_CLASS_TELBOXFILE
SB_INLINE TElBoxFileHandle TElBoxDataStorage::AcquireFile(const std::string &ID)
{
	TElBoxFileHandle OutResult;
	SBCheckError(TElBoxDataStorage_AcquireFile(_Handle, ID.data(), (int32_t)ID.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELBOXFILE */

#ifdef SB_USE_CLASS_TELBOXFOLDER
SB_INLINE TElBoxFolderHandle TElBoxDataStorage::AcquireFolder(const std::string &ID)
{
	TElBoxFolderHandle OutResult;
	SBCheckError(TElBoxDataStorage_AcquireFolder(_Handle, ID.data(), (int32_t)ID.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELBOXFOLDER */

#ifdef SB_USE_CLASSES_TELBOXDATASTORAGEOBJECT_AND_TELBOXFOLDER
SB_INLINE TElBoxDataStorageObjectHandle TElBoxDataStorage::CopyObject(TElBoxDataStorageObject &Obj, TElBoxFolder &Destination)
{
	TElBoxDataStorageObjectHandle OutResult;
	SBCheckError(TElBoxDataStorage_CopyObject(_Handle, Obj.getHandle(), Destination.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElBoxDataStorageObjectHandle TElBoxDataStorage::CopyObject(TElBoxDataStorageObject *Obj, TElBoxFolder *Destination)
{
	TElBoxDataStorageObjectHandle OutResult;
	SBCheckError(TElBoxDataStorage_CopyObject(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELBOXDATASTORAGEOBJECT_AND_TELBOXFOLDER */

#ifdef SB_USE_CLASSES_TELBOXDATASTORAGEOBJECT_AND_TELBOXFOLDER
SB_INLINE TElBoxDataStorageObjectHandle TElBoxDataStorage::CopyObject(TElBoxDataStorageObject &Obj, TElBoxFolder &Destination, const std::string &NewName)
{
	TElBoxDataStorageObjectHandle OutResult;
	SBCheckError(TElBoxDataStorage_CopyObject_1(_Handle, Obj.getHandle(), Destination.getHandle(), NewName.data(), (int32_t)NewName.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElBoxDataStorageObjectHandle TElBoxDataStorage::CopyObject(TElBoxDataStorageObject *Obj, TElBoxFolder *Destination, const std::string &NewName)
{
	TElBoxDataStorageObjectHandle OutResult;
	SBCheckError(TElBoxDataStorage_CopyObject_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE, NewName.data(), (int32_t)NewName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELBOXDATASTORAGEOBJECT_AND_TELBOXFOLDER */

#ifdef SB_USE_CLASS_TELBOXUSER
SB_INLINE TElBoxUserHandle TElBoxDataStorage::GetAccountInfo()
{
	TElBoxUserHandle OutResult;
	SBCheckError(TElBoxDataStorage_GetAccountInfo(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELBOXUSER */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElBoxDataStorage::ListTrashed(TElDataStorageObjectList &Objects)
{
	SBCheckError(TElBoxDataStorage_ListTrashed(_Handle, Objects.getHandle()));
}

SB_INLINE void TElBoxDataStorage::ListTrashed(TElDataStorageObjectList *Objects)
{
	SBCheckError(TElBoxDataStorage_ListTrashed(_Handle, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELBOXDATASTORAGEOBJECT
void TElBoxDataStorage::PurgeObject(TElBoxDataStorageObject &Obj)
{
	TElClassHandle hObj = Obj.getHandle();
	SBCheckError(TElBoxDataStorage_PurgeObject(_Handle, &hObj));
	Obj.updateHandle(hObj);
}
#endif /* SB_USE_CLASS_TELBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELBOXDATASTORAGEOBJECT
SB_INLINE void TElBoxDataStorage::RestoreObject(TElBoxDataStorageObject &Obj)
{
	SBCheckError(TElBoxDataStorage_RestoreObject(_Handle, Obj.getHandle()));
}

SB_INLINE void TElBoxDataStorage::RestoreObject(TElBoxDataStorageObject *Obj)
{
	SBCheckError(TElBoxDataStorage_RestoreObject(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELBOXDATASTORAGEOBJECT_AND_TELBOXFOLDER
SB_INLINE void TElBoxDataStorage::RestoreObject(TElBoxDataStorageObject &Obj, TElBoxFolder &NewParent, const std::string &NewName)
{
	SBCheckError(TElBoxDataStorage_RestoreObject_1(_Handle, Obj.getHandle(), NewParent.getHandle(), NewName.data(), (int32_t)NewName.length()));
}

SB_INLINE void TElBoxDataStorage::RestoreObject(TElBoxDataStorageObject *Obj, TElBoxFolder *NewParent, const std::string &NewName)
{
	SBCheckError(TElBoxDataStorage_RestoreObject_1(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (NewParent != NULL) ? NewParent->getHandle() : SB_NULL_HANDLE, NewName.data(), (int32_t)NewName.length()));
}
#endif /* SB_USE_CLASSES_TELBOXDATASTORAGEOBJECT_AND_TELBOXFOLDER */

void TElBoxDataStorage::get_AccessToken(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxDataStorage_get_AccessToken(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1498661929, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELBOXGROUPS
TElBoxGroups* TElBoxDataStorage::get_Groups()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxDataStorage_get_Groups(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Groups)
		this->_Inst_Groups = new TElBoxGroups(hOutResult, ohFalse);
	else
		this->_Inst_Groups->updateHandle(hOutResult);
	return this->_Inst_Groups;
}
#endif /* SB_USE_CLASS_TELBOXGROUPS */

#ifdef SB_USE_CLASS_TELBOXUSERS
TElBoxUsers* TElBoxDataStorage::get_Users()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxDataStorage_get_Users(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Users)
		this->_Inst_Users = new TElBoxUsers(hOutResult, ohFalse);
	else
		this->_Inst_Users->updateHandle(hOutResult);
	return this->_Inst_Users;
}
#endif /* SB_USE_CLASS_TELBOXUSERS */

void TElBoxDataStorage::get_ClientID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxDataStorage_get_ClientID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1302764093, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBoxDataStorage::set_ClientID(const std::string &Value)
{
	SBCheckError(TElBoxDataStorage_set_ClientID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElBoxDataStorage::get_ClientSecret(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxDataStorage_get_ClientSecret(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1830670917, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBoxDataStorage::set_ClientSecret(const std::string &Value)
{
	SBCheckError(TElBoxDataStorage_set_ClientSecret(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
TElHTTPSClient* TElBoxDataStorage::get_HTTPClient()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxDataStorage_get_HTTPClient(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HTTPClient)
		this->_Inst_HTTPClient = new TElHTTPSClient(hOutResult, ohFalse);
	else
		this->_Inst_HTTPClient->updateHandle(hOutResult);
	return this->_Inst_HTTPClient;
}

SB_INLINE void TElBoxDataStorage::set_HTTPClient(TElHTTPSClient &Value)
{
	SBCheckError(TElBoxDataStorage_set_HTTPClient(_Handle, Value.getHandle()));
}

SB_INLINE void TElBoxDataStorage::set_HTTPClient(TElHTTPSClient *Value)
{
	SBCheckError(TElBoxDataStorage_set_HTTPClient(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

bool TElBoxDataStorage::get_PassthroughMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBoxDataStorage_get_PassthroughMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBoxDataStorage::set_PassthroughMode(bool Value)
{
	SBCheckError(TElBoxDataStorage_set_PassthroughMode(_Handle, (int8_t)Value));
}

void TElBoxDataStorage::get_RefreshToken(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxDataStorage_get_RefreshToken(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1983226843, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBoxDataStorage::set_RefreshToken(const std::string &Value)
{
	SBCheckError(TElBoxDataStorage_set_RefreshToken(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElBoxDataStorage::get_UseETags()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBoxDataStorage_get_UseETags(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBoxDataStorage::set_UseETags(bool Value)
{
	SBCheckError(TElBoxDataStorage_set_UseETags(_Handle, (int8_t)Value));
}

void TElBoxDataStorage::initInstances()
{
#ifdef SB_USE_CLASS_TELBOXGROUPS
	this->_Inst_Groups = NULL;
#endif /* SB_USE_CLASS_TELBOXGROUPS */
#ifdef SB_USE_CLASS_TELBOXUSERS
	this->_Inst_Users = NULL;
#endif /* SB_USE_CLASS_TELBOXUSERS */
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
}

TElBoxDataStorage::TElBoxDataStorage(TElBoxDataStorageHandle handle, TElOwnHandle ownHandle) : TElCustomDataStorage(handle, ownHandle)
{
	initInstances();
}

TElBoxDataStorage::TElBoxDataStorage(TComponent &AOwner) : TElCustomDataStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxDataStorage_Create(AOwner.getHandle(), &_Handle));
}

TElBoxDataStorage::TElBoxDataStorage(TComponent *AOwner) : TElCustomDataStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxDataStorage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElBoxDataStorage::~TElBoxDataStorage()
{
#ifdef SB_USE_CLASS_TELBOXGROUPS
	delete this->_Inst_Groups;
	this->_Inst_Groups = NULL;
#endif /* SB_USE_CLASS_TELBOXGROUPS */
#ifdef SB_USE_CLASS_TELBOXUSERS
	delete this->_Inst_Users;
	this->_Inst_Users = NULL;
#endif /* SB_USE_CLASS_TELBOXUSERS */
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	delete this->_Inst_HTTPClient;
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
}
#endif /* SB_USE_CLASS_TELBOXDATASTORAGE */

#ifdef SB_USE_CLASS_TELBOXDATASTORAGEOBJECT

SB_INLINE void TElBoxDataStorageObject::Assign(TElCustomDataStorageObject &Source)
{
	SBCheckError(TElBoxDataStorageObject_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElBoxDataStorageObject::Assign(TElCustomDataStorageObject *Source)
{
	SBCheckError(TElBoxDataStorageObject_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELBOXFOLDER
SB_INLINE TElBoxDataStorageObjectHandle TElBoxDataStorageObject::Copy(TElBoxFolder &Destination)
{
	TElBoxDataStorageObjectHandle OutResult;
	SBCheckError(TElBoxDataStorageObject_Copy(_Handle, Destination.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElBoxDataStorageObjectHandle TElBoxDataStorageObject::Copy(TElBoxFolder *Destination)
{
	TElBoxDataStorageObjectHandle OutResult;
	SBCheckError(TElBoxDataStorageObject_Copy(_Handle, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELBOXFOLDER */

#ifdef SB_USE_CLASS_TELBOXFOLDER
SB_INLINE TElBoxDataStorageObjectHandle TElBoxDataStorageObject::Copy(TElBoxFolder &Destination, const std::string &NewName)
{
	TElBoxDataStorageObjectHandle OutResult;
	SBCheckError(TElBoxDataStorageObject_Copy_1(_Handle, Destination.getHandle(), NewName.data(), (int32_t)NewName.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElBoxDataStorageObjectHandle TElBoxDataStorageObject::Copy(TElBoxFolder *Destination, const std::string &NewName)
{
	TElBoxDataStorageObjectHandle OutResult;
	SBCheckError(TElBoxDataStorageObject_Copy_1(_Handle, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE, NewName.data(), (int32_t)NewName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELBOXFOLDER */

SB_INLINE void TElBoxDataStorageObject::Delete()
{
	SBCheckError(TElBoxDataStorageObject_Delete(_Handle));
}

#ifdef SB_USE_CLASS_TELBOXFOLDER
SB_INLINE void TElBoxDataStorageObject::Move(TElBoxFolder &Destination)
{
	SBCheckError(TElBoxDataStorageObject_Move(_Handle, Destination.getHandle()));
}

SB_INLINE void TElBoxDataStorageObject::Move(TElBoxFolder *Destination)
{
	SBCheckError(TElBoxDataStorageObject_Move(_Handle, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELBOXFOLDER */

SB_INLINE void TElBoxDataStorageObject::Rename(const std::string &NewName)
{
	SBCheckError(TElBoxDataStorageObject_Rename(_Handle, NewName.data(), (int32_t)NewName.length()));
}

SB_INLINE void TElBoxDataStorageObject::Purge()
{
	SBCheckError(TElBoxDataStorageObject_Purge(_Handle));
}

#ifdef SB_USE_CLASS_TELBOXUSERINFO
SB_INLINE void TElBoxDataStorageObject::TransferOwnership(TElBoxUserInfo &NewOwner)
{
	SBCheckError(TElBoxDataStorageObject_TransferOwnership(_Handle, NewOwner.getHandle()));
}

SB_INLINE void TElBoxDataStorageObject::TransferOwnership(TElBoxUserInfo *NewOwner)
{
	SBCheckError(TElBoxDataStorageObject_TransferOwnership(_Handle, (NewOwner != NULL) ? NewOwner->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELBOXUSERINFO */

SB_INLINE int64_t TElBoxDataStorageObject::get_ContentCreatedAt()
{
	int64_t OutResult;
	SBCheckError(TElBoxDataStorageObject_get_ContentCreatedAt(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElBoxDataStorageObject::get_ContentModifiedAt()
{
	int64_t OutResult;
	SBCheckError(TElBoxDataStorageObject_get_ContentModifiedAt(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElBoxDataStorageObject::get_CreatedAt()
{
	int64_t OutResult;
	SBCheckError(TElBoxDataStorageObject_get_CreatedAt(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELBOXUSERINFO
TElBoxUserInfo* TElBoxDataStorageObject::get_CreatedBy()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxDataStorageObject_get_CreatedBy(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CreatedBy)
		this->_Inst_CreatedBy = new TElBoxUserInfo(hOutResult, ohFalse);
	else
		this->_Inst_CreatedBy->updateHandle(hOutResult);
	return this->_Inst_CreatedBy;
}
#endif /* SB_USE_CLASS_TELBOXUSERINFO */

void TElBoxDataStorageObject::get_Description(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxDataStorageObject_get_Description(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-102291091, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBoxDataStorageObject::set_Description(const std::string &Value)
{
	SBCheckError(TElBoxDataStorageObject_set_Description(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElBoxDataStorageObject::get_ETag(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxDataStorageObject_get_ETag(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(364122006, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBoxDataStorageObject::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxDataStorageObject_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-119831906, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElBoxDataStorageObject::get_ModifiedAt()
{
	int64_t OutResult;
	SBCheckError(TElBoxDataStorageObject_get_ModifiedAt(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELBOXUSERINFO
TElBoxUserInfo* TElBoxDataStorageObject::get_ModifiedBy()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxDataStorageObject_get_ModifiedBy(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ModifiedBy)
		this->_Inst_ModifiedBy = new TElBoxUserInfo(hOutResult, ohFalse);
	else
		this->_Inst_ModifiedBy->updateHandle(hOutResult);
	return this->_Inst_ModifiedBy;
}
#endif /* SB_USE_CLASS_TELBOXUSERINFO */

#ifdef SB_USE_CLASS_TELBOXUSERINFO
TElBoxUserInfo* TElBoxDataStorageObject::get_OwnedBy()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxDataStorageObject_get_OwnedBy(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OwnedBy)
		this->_Inst_OwnedBy = new TElBoxUserInfo(hOutResult, ohFalse);
	else
		this->_Inst_OwnedBy->updateHandle(hOutResult);
	return this->_Inst_OwnedBy;
}
#endif /* SB_USE_CLASS_TELBOXUSERINFO */

void TElBoxDataStorageObject::get_ParentID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxDataStorageObject_get_ParentID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1752510076, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElBoxDataStorageObject::get_PurgedAt()
{
	int64_t OutResult;
	SBCheckError(TElBoxDataStorageObject_get_PurgedAt(_Handle, &OutResult));
	return OutResult;
}

void TElBoxDataStorageObject::get_SequenceID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxDataStorageObject_get_SequenceID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(388772877, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELBOXSHAREDLINK
TElBoxSharedLink* TElBoxDataStorageObject::get_SharedLink()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxDataStorageObject_get_SharedLink(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SharedLink)
		this->_Inst_SharedLink = new TElBoxSharedLink(hOutResult, ohFalse);
	else
		this->_Inst_SharedLink->updateHandle(hOutResult);
	return this->_Inst_SharedLink;
}
#endif /* SB_USE_CLASS_TELBOXSHAREDLINK */

SB_INLINE int64_t TElBoxDataStorageObject::get_Size()
{
	int64_t OutResult;
	SBCheckError(TElBoxDataStorageObject_get_Size(_Handle, &OutResult));
	return OutResult;
}

TSBBoxObjectStatus TElBoxDataStorageObject::get_Status()
{
	TSBBoxObjectStatusRaw OutResultRaw = 0;
	SBCheckError(TElBoxDataStorageObject_get_Status(_Handle, &OutResultRaw));
	return (TSBBoxObjectStatus)OutResultRaw;
}

SB_INLINE int64_t TElBoxDataStorageObject::get_TrashedAt()
{
	int64_t OutResult;
	SBCheckError(TElBoxDataStorageObject_get_TrashedAt(_Handle, &OutResult));
	return OutResult;
}

void TElBoxDataStorageObject::initInstances()
{
#ifdef SB_USE_CLASS_TELBOXUSERINFO
	this->_Inst_CreatedBy = NULL;
#endif /* SB_USE_CLASS_TELBOXUSERINFO */
#ifdef SB_USE_CLASS_TELBOXUSERINFO
	this->_Inst_ModifiedBy = NULL;
#endif /* SB_USE_CLASS_TELBOXUSERINFO */
#ifdef SB_USE_CLASS_TELBOXUSERINFO
	this->_Inst_OwnedBy = NULL;
#endif /* SB_USE_CLASS_TELBOXUSERINFO */
#ifdef SB_USE_CLASS_TELBOXSHAREDLINK
	this->_Inst_SharedLink = NULL;
#endif /* SB_USE_CLASS_TELBOXSHAREDLINK */
}

TElBoxDataStorageObject::TElBoxDataStorageObject(TElBoxDataStorageObjectHandle handle, TElOwnHandle ownHandle) : TElCustomDataStorageObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELBOXDATASTORAGE
TElBoxDataStorageObject::TElBoxDataStorageObject(TElBoxDataStorage &AStorage) : TElCustomDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxDataStorageObject_Create(AStorage.getHandle(), &_Handle));
}

TElBoxDataStorageObject::TElBoxDataStorageObject(TElBoxDataStorage *AStorage) : TElCustomDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxDataStorageObject_Create((AStorage != NULL) ? AStorage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELBOXDATASTORAGE */

TElBoxDataStorageObject::~TElBoxDataStorageObject()
{
#ifdef SB_USE_CLASS_TELBOXUSERINFO
	delete this->_Inst_CreatedBy;
	this->_Inst_CreatedBy = NULL;
#endif /* SB_USE_CLASS_TELBOXUSERINFO */
#ifdef SB_USE_CLASS_TELBOXUSERINFO
	delete this->_Inst_ModifiedBy;
	this->_Inst_ModifiedBy = NULL;
#endif /* SB_USE_CLASS_TELBOXUSERINFO */
#ifdef SB_USE_CLASS_TELBOXUSERINFO
	delete this->_Inst_OwnedBy;
	this->_Inst_OwnedBy = NULL;
#endif /* SB_USE_CLASS_TELBOXUSERINFO */
#ifdef SB_USE_CLASS_TELBOXSHAREDLINK
	delete this->_Inst_SharedLink;
	this->_Inst_SharedLink = NULL;
#endif /* SB_USE_CLASS_TELBOXSHAREDLINK */
}
#endif /* SB_USE_CLASS_TELBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELBOXFILE

SB_INLINE void TElBoxFile::Assign(TElCustomDataStorageObject &Source)
{
	SBCheckError(TElBoxFile_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElBoxFile::Assign(TElCustomDataStorageObject *Source)
{
	SBCheckError(TElBoxFile_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElCustomDataStorageObjectHandle TElBoxFile::Clone()
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElBoxFile_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElBoxFile::Write(TStream &Data, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElBoxFile_Write(_Handle, Data.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElBoxFile::Write(TStream *Data, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElBoxFile_Write(_Handle, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElBoxFile::Write(TStream &Data, int64_t DataModifiedAt, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElBoxFile_Write_1(_Handle, Data.getHandle(), DataModifiedAt, Handler.getHandle()));
}

SB_INLINE void TElBoxFile::Write(TStream *Data, int64_t DataModifiedAt, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElBoxFile_Write_1(_Handle, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, DataModifiedAt, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASS_TELBOXCOMMENTS
TElBoxComments* TElBoxFile::get_Comments()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxFile_get_Comments(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Comments)
		this->_Inst_Comments = new TElBoxComments(hOutResult, ohFalse);
	else
		this->_Inst_Comments->updateHandle(hOutResult);
	return this->_Inst_Comments;
}
#endif /* SB_USE_CLASS_TELBOXCOMMENTS */

void TElBoxFile::get_Sha1(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxFile_get_Sha1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-819425974, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBoxFile::get_VersionNumber(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxFile_get_VersionNumber(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1278669773, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBoxFile::initInstances()
{
#ifdef SB_USE_CLASS_TELBOXCOMMENTS
	this->_Inst_Comments = NULL;
#endif /* SB_USE_CLASS_TELBOXCOMMENTS */
}

TElBoxFile::TElBoxFile(TElBoxFileHandle handle, TElOwnHandle ownHandle) : TElBoxDataStorageObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELBOXDATASTORAGE
TElBoxFile::TElBoxFile(TElBoxDataStorage &AStorage) : TElBoxDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxFile_Create(AStorage.getHandle(), &_Handle));
}

TElBoxFile::TElBoxFile(TElBoxDataStorage *AStorage) : TElBoxDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxFile_Create((AStorage != NULL) ? AStorage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELBOXDATASTORAGE */

TElBoxFile::~TElBoxFile()
{
#ifdef SB_USE_CLASS_TELBOXCOMMENTS
	delete this->_Inst_Comments;
	this->_Inst_Comments = NULL;
#endif /* SB_USE_CLASS_TELBOXCOMMENTS */
}
#endif /* SB_USE_CLASS_TELBOXFILE */

#ifdef SB_USE_CLASS_TELBOXFOLDER

SB_INLINE void TElBoxFolder::Assign(TElCustomDataStorageObject &Source)
{
	SBCheckError(TElBoxFolder_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElBoxFolder::Assign(TElCustomDataStorageObject *Source)
{
	SBCheckError(TElBoxFolder_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElCustomDataStorageObjectHandle TElBoxFolder::Clone()
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElBoxFolder_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE TElBoxFolderHandle TElBoxFolder::CreateFolder(const std::string &Name)
{
	TElBoxFolderHandle OutResult;
	SBCheckError(TElBoxFolder_CreateFolder(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE TElBoxDataStorageObjectHandle TElBoxFolder::CreateObject(const std::string &Name, TStream &Data, TElCustomDataStorageSecurityHandler &Handler)
{
	TElBoxDataStorageObjectHandle OutResult;
	SBCheckError(TElBoxFolder_CreateObject(_Handle, Name.data(), (int32_t)Name.length(), Data.getHandle(), Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElBoxDataStorageObjectHandle TElBoxFolder::CreateObject(const std::string &Name, TStream *Data, TElCustomDataStorageSecurityHandler *Handler)
{
	TElBoxDataStorageObjectHandle OutResult;
	SBCheckError(TElBoxFolder_CreateObject(_Handle, Name.data(), (int32_t)Name.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE TElBoxDataStorageObjectHandle TElBoxFolder::CreateObject(const std::string &Name, TStream &Data, int64_t DataCreatedAt, int64_t DataModifiedAt, TElCustomDataStorageSecurityHandler &Handler)
{
	TElBoxDataStorageObjectHandle OutResult;
	SBCheckError(TElBoxFolder_CreateObject_1(_Handle, Name.data(), (int32_t)Name.length(), Data.getHandle(), DataCreatedAt, DataModifiedAt, Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElBoxDataStorageObjectHandle TElBoxFolder::CreateObject(const std::string &Name, TStream *Data, int64_t DataCreatedAt, int64_t DataModifiedAt, TElCustomDataStorageSecurityHandler *Handler)
{
	TElBoxDataStorageObjectHandle OutResult;
	SBCheckError(TElBoxFolder_CreateObject_1(_Handle, Name.data(), (int32_t)Name.length(), (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, DataCreatedAt, DataModifiedAt, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

SB_INLINE void TElBoxFolder::Delete(bool Recursive)
{
	SBCheckError(TElBoxFolder_Delete(_Handle, (int8_t)Recursive));
}

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElBoxFolder::List(TElDataStorageObjectList &Objects)
{
	SBCheckError(TElBoxFolder_List(_Handle, Objects.getHandle()));
}

SB_INLINE void TElBoxFolder::List(TElDataStorageObjectList *Objects)
{
	SBCheckError(TElBoxFolder_List(_Handle, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELBOXCOLLABORATIONS
TElBoxCollaborations* TElBoxFolder::get_Collaborations()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxFolder_get_Collaborations(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Collaborations)
		this->_Inst_Collaborations = new TElBoxCollaborations(hOutResult, ohFalse);
	else
		this->_Inst_Collaborations->updateHandle(hOutResult);
	return this->_Inst_Collaborations;
}
#endif /* SB_USE_CLASS_TELBOXCOLLABORATIONS */

TSBBoxSyncState TElBoxFolder::get_SyncState()
{
	TSBBoxSyncStateRaw OutResultRaw = 0;
	SBCheckError(TElBoxFolder_get_SyncState(_Handle, &OutResultRaw));
	return (TSBBoxSyncState)OutResultRaw;
}

SB_INLINE void TElBoxFolder::set_SyncState(TSBBoxSyncState Value)
{
	SBCheckError(TElBoxFolder_set_SyncState(_Handle, (TSBBoxSyncStateRaw)Value));
}

void TElBoxFolder::initInstances()
{
#ifdef SB_USE_CLASS_TELBOXCOLLABORATIONS
	this->_Inst_Collaborations = NULL;
#endif /* SB_USE_CLASS_TELBOXCOLLABORATIONS */
}

TElBoxFolder::TElBoxFolder(TElBoxFolderHandle handle, TElOwnHandle ownHandle) : TElBoxDataStorageObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELBOXDATASTORAGE
TElBoxFolder::TElBoxFolder(TElBoxDataStorage &AStorage) : TElBoxDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxFolder_Create(AStorage.getHandle(), &_Handle));
}

TElBoxFolder::TElBoxFolder(TElBoxDataStorage *AStorage) : TElBoxDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxFolder_Create((AStorage != NULL) ? AStorage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELBOXDATASTORAGE */

TElBoxFolder::~TElBoxFolder()
{
#ifdef SB_USE_CLASS_TELBOXCOLLABORATIONS
	delete this->_Inst_Collaborations;
	this->_Inst_Collaborations = NULL;
#endif /* SB_USE_CLASS_TELBOXCOLLABORATIONS */
}
#endif /* SB_USE_CLASS_TELBOXFOLDER */

#ifdef SB_USE_CLASS_TELBOXGROUPINFO

void TElBoxGroupInfo::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxGroupInfo_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-687892733, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBoxGroupInfo::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxGroupInfo_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(194821972, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElBoxGroupInfo::TElBoxGroupInfo(TElBoxGroupInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElBoxGroupInfo::TElBoxGroupInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBoxGroupInfo_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELBOXGROUPINFO */

#ifdef SB_USE_CLASS_TELBOXUSERINFO

SB_INLINE void TElBoxUserInfo::Assign(TElBoxUserInfo &Source)
{
	SBCheckError(TElBoxUserInfo_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElBoxUserInfo::Assign(TElBoxUserInfo *Source)
{
	SBCheckError(TElBoxUserInfo_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElBoxUserInfoHandle TElBoxUserInfo::Clone()
{
	TElBoxUserInfoHandle OutResult;
	SBCheckError(TElBoxUserInfo_Clone(_Handle, &OutResult));
	return OutResult;
}

void TElBoxUserInfo::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxUserInfo_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1112955262, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBoxUserInfo::get_Login(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxUserInfo_get_Login(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1533063583, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBoxUserInfo::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxUserInfo_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-305019919, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElBoxUserInfo::TElBoxUserInfo(TElBoxUserInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElBoxUserInfo::TElBoxUserInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBoxUserInfo_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELBOXUSERINFO */

#ifdef SB_USE_CLASS_TELBOXENTERPRISE

void TElBoxEnterprise::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxEnterprise_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(413544010, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBoxEnterprise::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxEnterprise_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1734701463, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElBoxEnterprise::TElBoxEnterprise(TElBoxEnterpriseHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElBoxEnterprise::TElBoxEnterprise() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBoxEnterprise_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELBOXENTERPRISE */

#ifdef SB_USE_CLASS_TELBOXUSEREMAILALIAS

SB_INLINE void TElBoxUserEmailAlias::Delete()
{
	SBCheckError(TElBoxUserEmailAlias_Delete(_Handle));
}

SB_INLINE void TElBoxUserEmailAlias::MakePrimary()
{
	SBCheckError(TElBoxUserEmailAlias_MakePrimary(_Handle));
}

void TElBoxUserEmailAlias::get_Email(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxUserEmailAlias_get_Email(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1290029953, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBoxUserEmailAlias::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxUserEmailAlias_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1892904461, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElBoxUserEmailAlias::get_IsConfirmed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBoxUserEmailAlias_get_IsConfirmed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBoxUserEmailAlias::get_IsPrimary()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBoxUserEmailAlias_get_IsPrimary(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELBOXUSER
TElBoxUser* TElBoxUserEmailAlias::get_Owner()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxUserEmailAlias_get_Owner(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Owner)
		this->_Inst_Owner = new TElBoxUser(hOutResult, ohFalse);
	else
		this->_Inst_Owner->updateHandle(hOutResult);
	return this->_Inst_Owner;
}
#endif /* SB_USE_CLASS_TELBOXUSER */

void TElBoxUserEmailAlias::initInstances()
{
#ifdef SB_USE_CLASS_TELBOXUSER
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELBOXUSER */
}

TElBoxUserEmailAlias::TElBoxUserEmailAlias(TElBoxUserEmailAliasHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELBOXUSER
TElBoxUserEmailAlias::TElBoxUserEmailAlias(TElBoxUser &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxUserEmailAlias_Create(AOwner.getHandle(), &_Handle));
}

TElBoxUserEmailAlias::TElBoxUserEmailAlias(TElBoxUser *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxUserEmailAlias_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELBOXUSER */

TElBoxUserEmailAlias::~TElBoxUserEmailAlias()
{
#ifdef SB_USE_CLASS_TELBOXUSER
	delete this->_Inst_Owner;
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELBOXUSER */
}
#endif /* SB_USE_CLASS_TELBOXUSEREMAILALIAS */

#ifdef SB_USE_CLASS_TELBOXUSEREMAILALIASES

#ifdef SB_USE_CLASS_TELBOXUSEREMAILALIAS
SB_INLINE TElBoxUserEmailAliasHandle TElBoxUserEmailAliases::Add(const std::string &Email)
{
	TElBoxUserEmailAliasHandle OutResult;
	SBCheckError(TElBoxUserEmailAliases_Add(_Handle, Email.data(), (int32_t)Email.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELBOXUSEREMAILALIAS */

#ifdef SB_USE_CLASS_TELBOXUSEREMAILALIAS
SB_INLINE int32_t TElBoxUserEmailAliases::IndexOf(TElBoxUserEmailAlias &Alias)
{
	int32_t OutResult;
	SBCheckError(TElBoxUserEmailAliases_IndexOf(_Handle, Alias.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElBoxUserEmailAliases::IndexOf(TElBoxUserEmailAlias *Alias)
{
	int32_t OutResult;
	SBCheckError(TElBoxUserEmailAliases_IndexOf(_Handle, (Alias != NULL) ? Alias->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELBOXUSEREMAILALIAS */

SB_INLINE int32_t TElBoxUserEmailAliases::IndexOf(const std::string &ID)
{
	int32_t OutResult;
	SBCheckError(TElBoxUserEmailAliases_IndexOf_1(_Handle, ID.data(), (int32_t)ID.length(), &OutResult));
	return OutResult;
}

SB_INLINE void TElBoxUserEmailAliases::Refresh()
{
	SBCheckError(TElBoxUserEmailAliases_Refresh(_Handle));
}

SB_INLINE int32_t TElBoxUserEmailAliases::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElBoxUserEmailAliases_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELBOXUSEREMAILALIAS
TElBoxUserEmailAlias* TElBoxUserEmailAliases::get_Items(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxUserEmailAliases_get_Items(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Items)
		this->_Inst_Items = new TElBoxUserEmailAlias(hOutResult, ohFalse);
	else
		this->_Inst_Items->updateHandle(hOutResult);
	return this->_Inst_Items;
}
#endif /* SB_USE_CLASS_TELBOXUSEREMAILALIAS */

void TElBoxUserEmailAliases::initInstances()
{
#ifdef SB_USE_CLASS_TELBOXUSEREMAILALIAS
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELBOXUSEREMAILALIAS */
}

TElBoxUserEmailAliases::TElBoxUserEmailAliases(TElBoxUserEmailAliasesHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELBOXUSER
TElBoxUserEmailAliases::TElBoxUserEmailAliases(TElBoxUser &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxUserEmailAliases_Create(AOwner.getHandle(), &_Handle));
}

TElBoxUserEmailAliases::TElBoxUserEmailAliases(TElBoxUser *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxUserEmailAliases_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELBOXUSER */

TElBoxUserEmailAliases::~TElBoxUserEmailAliases()
{
#ifdef SB_USE_CLASS_TELBOXUSEREMAILALIAS
	delete this->_Inst_Items;
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELBOXUSEREMAILALIAS */
}
#endif /* SB_USE_CLASS_TELBOXUSEREMAILALIASES */

#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERSHIP

SB_INLINE void TElBoxGroupMembership::Discontinue()
{
	SBCheckError(TElBoxGroupMembership_Discontinue(_Handle));
}

void TElBoxGroupMembership::get_GroupID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxGroupMembership_get_GroupID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-554459209, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBoxGroupMembership::get_GroupName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxGroupMembership_get_GroupName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2047978282, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBoxGroupMembership::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxGroupMembership_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(951832057, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElBoxGroupMembership::get_JoinedAt()
{
	int64_t OutResult;
	SBCheckError(TElBoxGroupMembership_get_JoinedAt(_Handle, &OutResult));
	return OutResult;
}

TSBBoxGroupRole TElBoxGroupMembership::get_Role()
{
	TSBBoxGroupRoleRaw OutResultRaw = 0;
	SBCheckError(TElBoxGroupMembership_get_Role(_Handle, &OutResultRaw));
	return (TSBBoxGroupRole)OutResultRaw;
}

SB_INLINE void TElBoxGroupMembership::set_Role(TSBBoxGroupRole Value)
{
	SBCheckError(TElBoxGroupMembership_set_Role(_Handle, (TSBBoxGroupRoleRaw)Value));
}

TElBoxGroupMembership::TElBoxGroupMembership(TElBoxGroupMembershipHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELBOXUSER
TElBoxGroupMembership::TElBoxGroupMembership(TElBoxUser &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBoxGroupMembership_Create(AOwner.getHandle(), &_Handle));
}

TElBoxGroupMembership::TElBoxGroupMembership(TElBoxUser *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBoxGroupMembership_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELBOXUSER */

#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERSHIP */

#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERSHIPS

#ifdef SB_USE_CLASSES_TELBOXGROUP_AND_TELBOXGROUPMEMBERSHIP
SB_INLINE TElBoxGroupMembershipHandle TElBoxGroupMemberships::Join(TElBoxGroup &Group)
{
	TElBoxGroupMembershipHandle OutResult;
	SBCheckError(TElBoxGroupMemberships_Join(_Handle, Group.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElBoxGroupMembershipHandle TElBoxGroupMemberships::Join(TElBoxGroup *Group)
{
	TElBoxGroupMembershipHandle OutResult;
	SBCheckError(TElBoxGroupMemberships_Join(_Handle, (Group != NULL) ? Group->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELBOXGROUP_AND_TELBOXGROUPMEMBERSHIP */

SB_INLINE void TElBoxGroupMemberships::Refresh()
{
	SBCheckError(TElBoxGroupMemberships_Refresh(_Handle));
}

SB_INLINE int32_t TElBoxGroupMemberships::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElBoxGroupMemberships_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERSHIP
TElBoxGroupMembership* TElBoxGroupMemberships::get_Items(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxGroupMemberships_get_Items(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Items)
		this->_Inst_Items = new TElBoxGroupMembership(hOutResult, ohFalse);
	else
		this->_Inst_Items->updateHandle(hOutResult);
	return this->_Inst_Items;
}
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERSHIP */

void TElBoxGroupMemberships::initInstances()
{
#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERSHIP
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERSHIP */
}

TElBoxGroupMemberships::TElBoxGroupMemberships(TElBoxGroupMembershipsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELBOXUSER
TElBoxGroupMemberships::TElBoxGroupMemberships(TElBoxUser &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxGroupMemberships_Create(AOwner.getHandle(), &_Handle));
}

TElBoxGroupMemberships::TElBoxGroupMemberships(TElBoxUser *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxGroupMemberships_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELBOXUSER */

TElBoxGroupMemberships::~TElBoxGroupMemberships()
{
#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERSHIP
	delete this->_Inst_Items;
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERSHIP */
}
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERSHIPS */

#ifdef SB_USE_CLASS_TELBOXUSER

SB_INLINE void TElBoxUser::Assign(TElBoxUserInfo &Source)
{
	SBCheckError(TElBoxUser_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElBoxUser::Assign(TElBoxUserInfo *Source)
{
	SBCheckError(TElBoxUser_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElBoxUser::BeginUpdate()
{
	SBCheckError(TElBoxUser_BeginUpdate(_Handle));
}

SB_INLINE TElBoxUserInfoHandle TElBoxUser::Clone()
{
	TElBoxUserInfoHandle OutResult;
	SBCheckError(TElBoxUser_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBoxUser::Delete()
{
	SBCheckError(TElBoxUser_Delete(_Handle));
}

SB_INLINE void TElBoxUser::EndUpdate()
{
	SBCheckError(TElBoxUser_EndUpdate(_Handle));
}

SB_INLINE void TElBoxUser::Refresh(bool RequestSpecialFields)
{
	SBCheckError(TElBoxUser_Refresh(_Handle, (int8_t)RequestSpecialFields));
}

SB_INLINE void TElBoxUser::RemoveFromEnterprise(bool Notify)
{
	SBCheckError(TElBoxUser_RemoveFromEnterprise(_Handle, (int8_t)Notify));
}

SB_INLINE void TElBoxUser::RequestPasswordReset()
{
	SBCheckError(TElBoxUser_RequestPasswordReset(_Handle));
}

void TElBoxUser::get_Address(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxUser_get_Address(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(150292373, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBoxUser::set_Address(const std::string &Value)
{
	SBCheckError(TElBoxUser_set_Address(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElBoxUser::get_CanSeeManagedUsers()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBoxUser_get_CanSeeManagedUsers(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBoxUser::set_CanSeeManagedUsers(bool Value)
{
	SBCheckError(TElBoxUser_set_CanSeeManagedUsers(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELBOXUSEREMAILALIASES
TElBoxUserEmailAliases* TElBoxUser::get_EmailAliases()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxUser_get_EmailAliases(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EmailAliases)
		this->_Inst_EmailAliases = new TElBoxUserEmailAliases(hOutResult, ohFalse);
	else
		this->_Inst_EmailAliases->updateHandle(hOutResult);
	return this->_Inst_EmailAliases;
}
#endif /* SB_USE_CLASS_TELBOXUSEREMAILALIASES */

#ifdef SB_USE_CLASS_TELBOXENTERPRISE
TElBoxEnterprise* TElBoxUser::get_Enterprise()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxUser_get_Enterprise(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Enterprise)
		this->_Inst_Enterprise = new TElBoxEnterprise(hOutResult, ohFalse);
	else
		this->_Inst_Enterprise->updateHandle(hOutResult);
	return this->_Inst_Enterprise;
}
#endif /* SB_USE_CLASS_TELBOXENTERPRISE */

void TElBoxUser::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxUser_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1779615977, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElBoxUser::get_IsExemptFromDeviceLimits()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBoxUser_get_IsExemptFromDeviceLimits(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBoxUser::set_IsExemptFromDeviceLimits(bool Value)
{
	SBCheckError(TElBoxUser_set_IsExemptFromDeviceLimits(_Handle, (int8_t)Value));
}

bool TElBoxUser::get_IsExemptFromLoginVerification()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBoxUser_get_IsExemptFromLoginVerification(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBoxUser::set_IsExemptFromLoginVerification(bool Value)
{
	SBCheckError(TElBoxUser_set_IsExemptFromLoginVerification(_Handle, (int8_t)Value));
}

bool TElBoxUser::get_IsSyncEnabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBoxUser_get_IsSyncEnabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBoxUser::set_IsSyncEnabled(bool Value)
{
	SBCheckError(TElBoxUser_set_IsSyncEnabled(_Handle, (int8_t)Value));
}

void TElBoxUser::get_Login(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxUser_get_Login(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1146393142, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERSHIPS
TElBoxGroupMemberships* TElBoxUser::get_Memberships()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxUser_get_Memberships(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Memberships)
		this->_Inst_Memberships = new TElBoxGroupMemberships(hOutResult, ohFalse);
	else
		this->_Inst_Memberships->updateHandle(hOutResult);
	return this->_Inst_Memberships;
}
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERSHIPS */

void TElBoxUser::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxUser_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-203126533, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBoxUser::set_Name(const std::string &Value)
{
	SBCheckError(TElBoxUser_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElBoxUser::get_JobTitle(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxUser_get_JobTitle(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-121384467, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBoxUser::set_JobTitle(const std::string &Value)
{
	SBCheckError(TElBoxUser_set_JobTitle(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElBoxUser::get_Language(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxUser_get_Language(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(470217069, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBoxUser::set_Language(const std::string &Value)
{
	SBCheckError(TElBoxUser_set_Language(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElBoxUser::get_Phone(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxUser_get_Phone(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1441542407, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBoxUser::set_Phone(const std::string &Value)
{
	SBCheckError(TElBoxUser_set_Phone(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBBoxUserRole TElBoxUser::get_Role()
{
	TSBBoxUserRoleRaw OutResultRaw = 0;
	SBCheckError(TElBoxUser_get_Role(_Handle, &OutResultRaw));
	return (TSBBoxUserRole)OutResultRaw;
}

SB_INLINE void TElBoxUser::set_Role(TSBBoxUserRole Value)
{
	SBCheckError(TElBoxUser_set_Role(_Handle, (TSBBoxUserRoleRaw)Value));
}

SB_INLINE int64_t TElBoxUser::get_SpaceAmount()
{
	int64_t OutResult;
	SBCheckError(TElBoxUser_get_SpaceAmount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBoxUser::set_SpaceAmount(int64_t Value)
{
	SBCheckError(TElBoxUser_set_SpaceAmount(_Handle, Value));
}

SB_INLINE int64_t TElBoxUser::get_SpaceUsed()
{
	int64_t OutResult;
	SBCheckError(TElBoxUser_get_SpaceUsed(_Handle, &OutResult));
	return OutResult;
}

TSBBoxUserStatus TElBoxUser::get_Status()
{
	TSBBoxUserStatusRaw OutResultRaw = 0;
	SBCheckError(TElBoxUser_get_Status(_Handle, &OutResultRaw));
	return (TSBBoxUserStatus)OutResultRaw;
}

SB_INLINE void TElBoxUser::set_Status(TSBBoxUserStatus Value)
{
	SBCheckError(TElBoxUser_set_Status(_Handle, (TSBBoxUserStatusRaw)Value));
}

void TElBoxUser::initInstances()
{
#ifdef SB_USE_CLASS_TELBOXUSEREMAILALIASES
	this->_Inst_EmailAliases = NULL;
#endif /* SB_USE_CLASS_TELBOXUSEREMAILALIASES */
#ifdef SB_USE_CLASS_TELBOXENTERPRISE
	this->_Inst_Enterprise = NULL;
#endif /* SB_USE_CLASS_TELBOXENTERPRISE */
#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERSHIPS
	this->_Inst_Memberships = NULL;
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERSHIPS */
}

TElBoxUser::TElBoxUser(TElBoxUserHandle handle, TElOwnHandle ownHandle) : TElBoxUserInfo(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELBOXDATASTORAGE
TElBoxUser::TElBoxUser(TElBoxDataStorage &AStorage) : TElBoxUserInfo(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxUser_Create(AStorage.getHandle(), &_Handle));
}

TElBoxUser::TElBoxUser(TElBoxDataStorage *AStorage) : TElBoxUserInfo(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxUser_Create((AStorage != NULL) ? AStorage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELBOXDATASTORAGE */

TElBoxUser::~TElBoxUser()
{
#ifdef SB_USE_CLASS_TELBOXUSEREMAILALIASES
	delete this->_Inst_EmailAliases;
	this->_Inst_EmailAliases = NULL;
#endif /* SB_USE_CLASS_TELBOXUSEREMAILALIASES */
#ifdef SB_USE_CLASS_TELBOXENTERPRISE
	delete this->_Inst_Enterprise;
	this->_Inst_Enterprise = NULL;
#endif /* SB_USE_CLASS_TELBOXENTERPRISE */
#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERSHIPS
	delete this->_Inst_Memberships;
	this->_Inst_Memberships = NULL;
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERSHIPS */
}
#endif /* SB_USE_CLASS_TELBOXUSER */

#ifdef SB_USE_CLASS_TELBOXUSERS

#ifdef SB_USE_CLASS_TELBOXUSER
SB_INLINE TElBoxUserHandle TElBoxUsers::Add(const std::string &Login, const std::string &Name)
{
	TElBoxUserHandle OutResult;
	SBCheckError(TElBoxUsers_Add(_Handle, Login.data(), (int32_t)Login.length(), Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELBOXUSER */

SB_INLINE void TElBoxUsers::Clear()
{
	SBCheckError(TElBoxUsers_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELBOXUSER
SB_INLINE int32_t TElBoxUsers::IndexOf(TElBoxUser &User)
{
	int32_t OutResult;
	SBCheckError(TElBoxUsers_IndexOf(_Handle, User.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElBoxUsers::IndexOf(TElBoxUser *User)
{
	int32_t OutResult;
	SBCheckError(TElBoxUsers_IndexOf(_Handle, (User != NULL) ? User->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELBOXUSER */

SB_INLINE int32_t TElBoxUsers::IndexOf(const std::string &ID)
{
	int32_t OutResult;
	SBCheckError(TElBoxUsers_IndexOf_1(_Handle, ID.data(), (int32_t)ID.length(), &OutResult));
	return OutResult;
}

SB_INLINE void TElBoxUsers::Refresh()
{
	SBCheckError(TElBoxUsers_Refresh(_Handle));
}

SB_INLINE int32_t TElBoxUsers::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElBoxUsers_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELBOXUSER
TElBoxUser* TElBoxUsers::get_Items(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxUsers_get_Items(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Items)
		this->_Inst_Items = new TElBoxUser(hOutResult, ohFalse);
	else
		this->_Inst_Items->updateHandle(hOutResult);
	return this->_Inst_Items;
}
#endif /* SB_USE_CLASS_TELBOXUSER */

void TElBoxUsers::initInstances()
{
#ifdef SB_USE_CLASS_TELBOXUSER
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELBOXUSER */
}

TElBoxUsers::TElBoxUsers(TElBoxUsersHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELBOXDATASTORAGE
TElBoxUsers::TElBoxUsers(TElBoxDataStorage &AStorage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxUsers_Create(AStorage.getHandle(), &_Handle));
}

TElBoxUsers::TElBoxUsers(TElBoxDataStorage *AStorage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxUsers_Create((AStorage != NULL) ? AStorage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELBOXDATASTORAGE */

TElBoxUsers::~TElBoxUsers()
{
#ifdef SB_USE_CLASS_TELBOXUSER
	delete this->_Inst_Items;
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELBOXUSER */
}
#endif /* SB_USE_CLASS_TELBOXUSERS */

#ifdef SB_USE_CLASS_TELBOXGROUPMEMBER

SB_INLINE void TElBoxGroupMember::Refresh()
{
	SBCheckError(TElBoxGroupMember_Refresh(_Handle));
}

SB_INLINE void TElBoxGroupMember::Remove()
{
	SBCheckError(TElBoxGroupMember_Remove(_Handle));
}

void TElBoxGroupMember::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxGroupMember_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(550047643, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElBoxGroupMember::get_JoinedAt()
{
	int64_t OutResult;
	SBCheckError(TElBoxGroupMember_get_JoinedAt(_Handle, &OutResult));
	return OutResult;
}

TSBBoxGroupRole TElBoxGroupMember::get_Role()
{
	TSBBoxGroupRoleRaw OutResultRaw = 0;
	SBCheckError(TElBoxGroupMember_get_Role(_Handle, &OutResultRaw));
	return (TSBBoxGroupRole)OutResultRaw;
}

SB_INLINE void TElBoxGroupMember::set_Role(TSBBoxGroupRole Value)
{
	SBCheckError(TElBoxGroupMember_set_Role(_Handle, (TSBBoxGroupRoleRaw)Value));
}

void TElBoxGroupMember::get_UserID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxGroupMember_get_UserID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(752419307, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBoxGroupMember::get_UserLogin(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxGroupMember_get_UserLogin(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1344437753, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBoxGroupMember::get_UserName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxGroupMember_get_UserName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2074670361, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElBoxGroupMember::TElBoxGroupMember(TElBoxGroupMemberHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELBOXGROUP
TElBoxGroupMember::TElBoxGroupMember(TElBoxGroup &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBoxGroupMember_Create(AOwner.getHandle(), &_Handle));
}

TElBoxGroupMember::TElBoxGroupMember(TElBoxGroup *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBoxGroupMember_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELBOXGROUP */

#endif /* SB_USE_CLASS_TELBOXGROUPMEMBER */

#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERS

#ifdef SB_USE_CLASSES_TELBOXGROUPMEMBER_AND_TELBOXUSER
SB_INLINE TElBoxGroupMemberHandle TElBoxGroupMembers::Add(TElBoxUser &User)
{
	TElBoxGroupMemberHandle OutResult;
	SBCheckError(TElBoxGroupMembers_Add(_Handle, User.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElBoxGroupMemberHandle TElBoxGroupMembers::Add(TElBoxUser *User)
{
	TElBoxGroupMemberHandle OutResult;
	SBCheckError(TElBoxGroupMembers_Add(_Handle, (User != NULL) ? User->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELBOXGROUPMEMBER_AND_TELBOXUSER */

SB_INLINE void TElBoxGroupMembers::Refresh()
{
	SBCheckError(TElBoxGroupMembers_Refresh(_Handle));
}

SB_INLINE int32_t TElBoxGroupMembers::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElBoxGroupMembers_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELBOXGROUPMEMBER
TElBoxGroupMember* TElBoxGroupMembers::get_Items(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxGroupMembers_get_Items(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Items)
		this->_Inst_Items = new TElBoxGroupMember(hOutResult, ohFalse);
	else
		this->_Inst_Items->updateHandle(hOutResult);
	return this->_Inst_Items;
}
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBER */

void TElBoxGroupMembers::initInstances()
{
#ifdef SB_USE_CLASS_TELBOXGROUPMEMBER
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBER */
}

TElBoxGroupMembers::TElBoxGroupMembers(TElBoxGroupMembersHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELBOXGROUP
TElBoxGroupMembers::TElBoxGroupMembers(TElBoxGroup &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxGroupMembers_Create(AOwner.getHandle(), &_Handle));
}

TElBoxGroupMembers::TElBoxGroupMembers(TElBoxGroup *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxGroupMembers_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELBOXGROUP */

TElBoxGroupMembers::~TElBoxGroupMembers()
{
#ifdef SB_USE_CLASS_TELBOXGROUPMEMBER
	delete this->_Inst_Items;
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBER */
}
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERS */

#ifdef SB_USE_CLASS_TELBOXGROUP

SB_INLINE void TElBoxGroup::Delete()
{
	SBCheckError(TElBoxGroup_Delete(_Handle));
}

SB_INLINE void TElBoxGroup::Refresh()
{
	SBCheckError(TElBoxGroup_Refresh(_Handle));
}

SB_INLINE int64_t TElBoxGroup::get_CreatedAt()
{
	int64_t OutResult;
	SBCheckError(TElBoxGroup_get_CreatedAt(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERS
TElBoxGroupMembers* TElBoxGroup::get_Members()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxGroup_get_Members(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Members)
		this->_Inst_Members = new TElBoxGroupMembers(hOutResult, ohFalse);
	else
		this->_Inst_Members->updateHandle(hOutResult);
	return this->_Inst_Members;
}
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERS */

SB_INLINE int64_t TElBoxGroup::get_ModifiedAt()
{
	int64_t OutResult;
	SBCheckError(TElBoxGroup_get_ModifiedAt(_Handle, &OutResult));
	return OutResult;
}

void TElBoxGroup::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxGroup_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-786722290, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBoxGroup::set_Name(const std::string &Value)
{
	SBCheckError(TElBoxGroup_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElBoxGroup::initInstances()
{
#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERS
	this->_Inst_Members = NULL;
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERS */
}

TElBoxGroup::TElBoxGroup(TElBoxGroupHandle handle, TElOwnHandle ownHandle) : TElBoxGroupInfo(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELBOXDATASTORAGE
TElBoxGroup::TElBoxGroup(TElBoxDataStorage &AStorage) : TElBoxGroupInfo(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxGroup_Create(AStorage.getHandle(), &_Handle));
}

TElBoxGroup::TElBoxGroup(TElBoxDataStorage *AStorage) : TElBoxGroupInfo(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxGroup_Create((AStorage != NULL) ? AStorage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELBOXDATASTORAGE */

TElBoxGroup::~TElBoxGroup()
{
#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERS
	delete this->_Inst_Members;
	this->_Inst_Members = NULL;
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERS */
}
#endif /* SB_USE_CLASS_TELBOXGROUP */

#ifdef SB_USE_CLASS_TELBOXGROUPS

#ifdef SB_USE_CLASS_TELBOXGROUP
SB_INLINE TElBoxGroupHandle TElBoxGroups::Add(const std::string &Name)
{
	TElBoxGroupHandle OutResult;
	SBCheckError(TElBoxGroups_Add(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELBOXGROUP */

SB_INLINE int32_t TElBoxGroups::IndexOf(const std::string &ID)
{
	int32_t OutResult;
	SBCheckError(TElBoxGroups_IndexOf(_Handle, ID.data(), (int32_t)ID.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELBOXGROUP
SB_INLINE int32_t TElBoxGroups::IndexOf(TElBoxGroup &Group)
{
	int32_t OutResult;
	SBCheckError(TElBoxGroups_IndexOf_1(_Handle, Group.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElBoxGroups::IndexOf(TElBoxGroup *Group)
{
	int32_t OutResult;
	SBCheckError(TElBoxGroups_IndexOf_1(_Handle, (Group != NULL) ? Group->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELBOXGROUP */

SB_INLINE void TElBoxGroups::Refresh()
{
	SBCheckError(TElBoxGroups_Refresh(_Handle));
}

SB_INLINE int32_t TElBoxGroups::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElBoxGroups_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELBOXGROUP
TElBoxGroup* TElBoxGroups::get_Item(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxGroups_get_Item(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Item)
		this->_Inst_Item = new TElBoxGroup(hOutResult, ohFalse);
	else
		this->_Inst_Item->updateHandle(hOutResult);
	return this->_Inst_Item;
}
#endif /* SB_USE_CLASS_TELBOXGROUP */

void TElBoxGroups::initInstances()
{
#ifdef SB_USE_CLASS_TELBOXGROUP
	this->_Inst_Item = NULL;
#endif /* SB_USE_CLASS_TELBOXGROUP */
}

TElBoxGroups::TElBoxGroups(TElBoxGroupsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELBOXDATASTORAGE
TElBoxGroups::TElBoxGroups(TElBoxDataStorage &AStorage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxGroups_Create(AStorage.getHandle(), &_Handle));
}

TElBoxGroups::TElBoxGroups(TElBoxDataStorage *AStorage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxGroups_Create((AStorage != NULL) ? AStorage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELBOXDATASTORAGE */

TElBoxGroups::~TElBoxGroups()
{
#ifdef SB_USE_CLASS_TELBOXGROUP
	delete this->_Inst_Item;
	this->_Inst_Item = NULL;
#endif /* SB_USE_CLASS_TELBOXGROUP */
}
#endif /* SB_USE_CLASS_TELBOXGROUPS */

#ifdef SB_USE_CLASS_TELBOXSHAREDLINK

SB_INLINE void TElBoxSharedLink::Assign(TElBoxSharedLink &Source)
{
	SBCheckError(TElBoxSharedLink_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElBoxSharedLink::Assign(TElBoxSharedLink *Source)
{
	SBCheckError(TElBoxSharedLink_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElBoxSharedLinkHandle TElBoxSharedLink::Clone()
{
	TElBoxSharedLinkHandle OutResult;
	SBCheckError(TElBoxSharedLink_Clone(_Handle, &OutResult));
	return OutResult;
}

TSBBoxSharedLinkAccess TElBoxSharedLink::get_Access()
{
	TSBBoxSharedLinkAccessRaw OutResultRaw = 0;
	SBCheckError(TElBoxSharedLink_get_Access(_Handle, &OutResultRaw));
	return (TSBBoxSharedLinkAccess)OutResultRaw;
}

SB_INLINE int64_t TElBoxSharedLink::get_DownloadCount()
{
	int64_t OutResult;
	SBCheckError(TElBoxSharedLink_get_DownloadCount(_Handle, &OutResult));
	return OutResult;
}

void TElBoxSharedLink::get_DownloadURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxSharedLink_get_DownloadURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1928362791, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElBoxSharedLink::get_IsPasswordEnabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBoxSharedLink_get_IsPasswordEnabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELBOXSHAREDLINKPERMISSIONS
TElBoxSharedLinkPermissions* TElBoxSharedLink::get_Permissions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxSharedLink_get_Permissions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Permissions)
		this->_Inst_Permissions = new TElBoxSharedLinkPermissions(hOutResult, ohFalse);
	else
		this->_Inst_Permissions->updateHandle(hOutResult);
	return this->_Inst_Permissions;
}
#endif /* SB_USE_CLASS_TELBOXSHAREDLINKPERMISSIONS */

SB_INLINE int64_t TElBoxSharedLink::get_PreviewCount()
{
	int64_t OutResult;
	SBCheckError(TElBoxSharedLink_get_PreviewCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElBoxSharedLink::get_UnsharedAt()
{
	int64_t OutResult;
	SBCheckError(TElBoxSharedLink_get_UnsharedAt(_Handle, &OutResult));
	return OutResult;
}

void TElBoxSharedLink::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxSharedLink_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1268603232, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBoxSharedLink::get_VanityURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxSharedLink_get_VanityURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2011200463, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBoxSharedLink::initInstances()
{
#ifdef SB_USE_CLASS_TELBOXSHAREDLINKPERMISSIONS
	this->_Inst_Permissions = NULL;
#endif /* SB_USE_CLASS_TELBOXSHAREDLINKPERMISSIONS */
}

TElBoxSharedLink::TElBoxSharedLink(TElBoxSharedLinkHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELBOXDATASTORAGEOBJECT
TElBoxSharedLink::TElBoxSharedLink(TElBoxDataStorageObject &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxSharedLink_Create(AOwner.getHandle(), &_Handle));
}

TElBoxSharedLink::TElBoxSharedLink(TElBoxDataStorageObject *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxSharedLink_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELBOXDATASTORAGEOBJECT */

TElBoxSharedLink::~TElBoxSharedLink()
{
#ifdef SB_USE_CLASS_TELBOXSHAREDLINKPERMISSIONS
	delete this->_Inst_Permissions;
	this->_Inst_Permissions = NULL;
#endif /* SB_USE_CLASS_TELBOXSHAREDLINKPERMISSIONS */
}
#endif /* SB_USE_CLASS_TELBOXSHAREDLINK */

#ifdef SB_USE_CLASS_TELBOXSHAREDLINKPERMISSIONS

SB_INLINE void TElBoxSharedLinkPermissions::Assign(TElBoxSharedLinkPermissions &Source)
{
	SBCheckError(TElBoxSharedLinkPermissions_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElBoxSharedLinkPermissions::Assign(TElBoxSharedLinkPermissions *Source)
{
	SBCheckError(TElBoxSharedLinkPermissions_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElBoxSharedLinkPermissionsHandle TElBoxSharedLinkPermissions::Clone()
{
	TElBoxSharedLinkPermissionsHandle OutResult;
	SBCheckError(TElBoxSharedLinkPermissions_Clone(_Handle, &OutResult));
	return OutResult;
}

bool TElBoxSharedLinkPermissions::get_CanDownload()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBoxSharedLinkPermissions_get_CanDownload(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBoxSharedLinkPermissions::get_CanPreview()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBoxSharedLinkPermissions_get_CanPreview(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TElBoxSharedLinkPermissions::TElBoxSharedLinkPermissions(TElBoxSharedLinkPermissionsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELBOXSHAREDLINK
TElBoxSharedLinkPermissions::TElBoxSharedLinkPermissions(TElBoxSharedLink &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBoxSharedLinkPermissions_Create(AOwner.getHandle(), &_Handle));
}

TElBoxSharedLinkPermissions::TElBoxSharedLinkPermissions(TElBoxSharedLink *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBoxSharedLinkPermissions_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELBOXSHAREDLINK */

#endif /* SB_USE_CLASS_TELBOXSHAREDLINKPERMISSIONS */

#ifdef SB_USE_CLASS_TELBOXCOLLABORATION

SB_INLINE void TElBoxCollaboration::Accept()
{
	SBCheckError(TElBoxCollaboration_Accept(_Handle));
}

SB_INLINE void TElBoxCollaboration::Delete()
{
	SBCheckError(TElBoxCollaboration_Delete(_Handle));
}

SB_INLINE void TElBoxCollaboration::Refresh()
{
	SBCheckError(TElBoxCollaboration_Refresh(_Handle));
}

SB_INLINE void TElBoxCollaboration::Reject()
{
	SBCheckError(TElBoxCollaboration_Reject(_Handle));
}

SB_INLINE int64_t TElBoxCollaboration::get_AcknowledgedAt()
{
	int64_t OutResult;
	SBCheckError(TElBoxCollaboration_get_AcknowledgedAt(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElBoxCollaboration::get_CreatedAt()
{
	int64_t OutResult;
	SBCheckError(TElBoxCollaboration_get_CreatedAt(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELBOXUSERINFO
TElBoxUserInfo* TElBoxCollaboration::get_CreatedBy()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxCollaboration_get_CreatedBy(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CreatedBy)
		this->_Inst_CreatedBy = new TElBoxUserInfo(hOutResult, ohFalse);
	else
		this->_Inst_CreatedBy->updateHandle(hOutResult);
	return this->_Inst_CreatedBy;
}
#endif /* SB_USE_CLASS_TELBOXUSERINFO */

SB_INLINE int64_t TElBoxCollaboration::get_ExpiresAt()
{
	int64_t OutResult;
	SBCheckError(TElBoxCollaboration_get_ExpiresAt(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELBOXGROUPINFO
TElBoxGroupInfo* TElBoxCollaboration::get_Group()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxCollaboration_get_Group(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Group)
		this->_Inst_Group = new TElBoxGroupInfo(hOutResult, ohFalse);
	else
		this->_Inst_Group->updateHandle(hOutResult);
	return this->_Inst_Group;
}
#endif /* SB_USE_CLASS_TELBOXGROUPINFO */

void TElBoxCollaboration::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxCollaboration_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1514423917, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElBoxCollaboration::get_ModifiedAt()
{
	int64_t OutResult;
	SBCheckError(TElBoxCollaboration_get_ModifiedAt(_Handle, &OutResult));
	return OutResult;
}

TSBBoxCollaborationRole TElBoxCollaboration::get_Role()
{
	TSBBoxCollaborationRoleRaw OutResultRaw = 0;
	SBCheckError(TElBoxCollaboration_get_Role(_Handle, &OutResultRaw));
	return (TSBBoxCollaborationRole)OutResultRaw;
}

SB_INLINE void TElBoxCollaboration::set_Role(TSBBoxCollaborationRole Value)
{
	SBCheckError(TElBoxCollaboration_set_Role(_Handle, (TSBBoxCollaborationRoleRaw)Value));
}

TSBBoxCollaborationStatus TElBoxCollaboration::get_Status()
{
	TSBBoxCollaborationStatusRaw OutResultRaw = 0;
	SBCheckError(TElBoxCollaboration_get_Status(_Handle, &OutResultRaw));
	return (TSBBoxCollaborationStatus)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELBOXUSERINFO
TElBoxUserInfo* TElBoxCollaboration::get_User()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxCollaboration_get_User(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_User)
		this->_Inst_User = new TElBoxUserInfo(hOutResult, ohFalse);
	else
		this->_Inst_User->updateHandle(hOutResult);
	return this->_Inst_User;
}
#endif /* SB_USE_CLASS_TELBOXUSERINFO */

void TElBoxCollaboration::initInstances()
{
#ifdef SB_USE_CLASS_TELBOXUSERINFO
	this->_Inst_CreatedBy = NULL;
#endif /* SB_USE_CLASS_TELBOXUSERINFO */
#ifdef SB_USE_CLASS_TELBOXGROUPINFO
	this->_Inst_Group = NULL;
#endif /* SB_USE_CLASS_TELBOXGROUPINFO */
#ifdef SB_USE_CLASS_TELBOXUSERINFO
	this->_Inst_User = NULL;
#endif /* SB_USE_CLASS_TELBOXUSERINFO */
}

TElBoxCollaboration::TElBoxCollaboration(TElBoxCollaborationHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELBOXFOLDER
TElBoxCollaboration::TElBoxCollaboration(TElBoxFolder &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxCollaboration_Create(AOwner.getHandle(), &_Handle));
}

TElBoxCollaboration::TElBoxCollaboration(TElBoxFolder *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxCollaboration_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELBOXFOLDER */

TElBoxCollaboration::~TElBoxCollaboration()
{
#ifdef SB_USE_CLASS_TELBOXUSERINFO
	delete this->_Inst_CreatedBy;
	this->_Inst_CreatedBy = NULL;
#endif /* SB_USE_CLASS_TELBOXUSERINFO */
#ifdef SB_USE_CLASS_TELBOXGROUPINFO
	delete this->_Inst_Group;
	this->_Inst_Group = NULL;
#endif /* SB_USE_CLASS_TELBOXGROUPINFO */
#ifdef SB_USE_CLASS_TELBOXUSERINFO
	delete this->_Inst_User;
	this->_Inst_User = NULL;
#endif /* SB_USE_CLASS_TELBOXUSERINFO */
}
#endif /* SB_USE_CLASS_TELBOXCOLLABORATION */

#ifdef SB_USE_CLASS_TELBOXCOLLABORATIONS

#ifdef SB_USE_CLASSES_TELBOXCOLLABORATION_AND_TELBOXGROUPINFO
SB_INLINE TElBoxCollaborationHandle TElBoxCollaborations::Add(TElBoxGroupInfo &Group, TSBBoxCollaborationRole Role, bool Notify)
{
	TElBoxCollaborationHandle OutResult;
	SBCheckError(TElBoxCollaborations_Add(_Handle, Group.getHandle(), (TSBBoxCollaborationRoleRaw)Role, (int8_t)Notify, &OutResult));
	return OutResult;
}

SB_INLINE TElBoxCollaborationHandle TElBoxCollaborations::Add(TElBoxGroupInfo *Group, TSBBoxCollaborationRole Role, bool Notify)
{
	TElBoxCollaborationHandle OutResult;
	SBCheckError(TElBoxCollaborations_Add(_Handle, (Group != NULL) ? Group->getHandle() : SB_NULL_HANDLE, (TSBBoxCollaborationRoleRaw)Role, (int8_t)Notify, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELBOXCOLLABORATION_AND_TELBOXGROUPINFO */

#ifdef SB_USE_CLASSES_TELBOXCOLLABORATION_AND_TELBOXUSERINFO
SB_INLINE TElBoxCollaborationHandle TElBoxCollaborations::Add(TElBoxUserInfo &User, TSBBoxCollaborationRole Role, bool Notify)
{
	TElBoxCollaborationHandle OutResult;
	SBCheckError(TElBoxCollaborations_Add_1(_Handle, User.getHandle(), (TSBBoxCollaborationRoleRaw)Role, (int8_t)Notify, &OutResult));
	return OutResult;
}

SB_INLINE TElBoxCollaborationHandle TElBoxCollaborations::Add(TElBoxUserInfo *User, TSBBoxCollaborationRole Role, bool Notify)
{
	TElBoxCollaborationHandle OutResult;
	SBCheckError(TElBoxCollaborations_Add_1(_Handle, (User != NULL) ? User->getHandle() : SB_NULL_HANDLE, (TSBBoxCollaborationRoleRaw)Role, (int8_t)Notify, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELBOXCOLLABORATION_AND_TELBOXUSERINFO */

#ifdef SB_USE_CLASS_TELBOXCOLLABORATION
SB_INLINE TElBoxCollaborationHandle TElBoxCollaborations::Add(const std::string &UserLogin, TSBBoxCollaborationRole Role, bool Notify)
{
	TElBoxCollaborationHandle OutResult;
	SBCheckError(TElBoxCollaborations_Add_2(_Handle, UserLogin.data(), (int32_t)UserLogin.length(), (TSBBoxCollaborationRoleRaw)Role, (int8_t)Notify, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELBOXCOLLABORATION */

SB_INLINE int32_t TElBoxCollaborations::IndexOf(const std::string &ID)
{
	int32_t OutResult;
	SBCheckError(TElBoxCollaborations_IndexOf(_Handle, ID.data(), (int32_t)ID.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELBOXCOLLABORATION
SB_INLINE int32_t TElBoxCollaborations::IndexOf(TElBoxCollaboration &Collaboration)
{
	int32_t OutResult;
	SBCheckError(TElBoxCollaborations_IndexOf_1(_Handle, Collaboration.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElBoxCollaborations::IndexOf(TElBoxCollaboration *Collaboration)
{
	int32_t OutResult;
	SBCheckError(TElBoxCollaborations_IndexOf_1(_Handle, (Collaboration != NULL) ? Collaboration->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELBOXCOLLABORATION */

SB_INLINE void TElBoxCollaborations::Refresh()
{
	SBCheckError(TElBoxCollaborations_Refresh(_Handle));
}

SB_INLINE int32_t TElBoxCollaborations::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElBoxCollaborations_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELBOXCOLLABORATION
TElBoxCollaboration* TElBoxCollaborations::get_Item(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxCollaborations_get_Item(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Item)
		this->_Inst_Item = new TElBoxCollaboration(hOutResult, ohFalse);
	else
		this->_Inst_Item->updateHandle(hOutResult);
	return this->_Inst_Item;
}
#endif /* SB_USE_CLASS_TELBOXCOLLABORATION */

void TElBoxCollaborations::initInstances()
{
#ifdef SB_USE_CLASS_TELBOXCOLLABORATION
	this->_Inst_Item = NULL;
#endif /* SB_USE_CLASS_TELBOXCOLLABORATION */
}

TElBoxCollaborations::TElBoxCollaborations(TElBoxCollaborationsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELBOXFOLDER
TElBoxCollaborations::TElBoxCollaborations(TElBoxFolder &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxCollaborations_Create(AOwner.getHandle(), &_Handle));
}

TElBoxCollaborations::TElBoxCollaborations(TElBoxFolder *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxCollaborations_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELBOXFOLDER */

TElBoxCollaborations::~TElBoxCollaborations()
{
#ifdef SB_USE_CLASS_TELBOXCOLLABORATION
	delete this->_Inst_Item;
	this->_Inst_Item = NULL;
#endif /* SB_USE_CLASS_TELBOXCOLLABORATION */
}
#endif /* SB_USE_CLASS_TELBOXCOLLABORATIONS */

#ifdef SB_USE_CLASS_TELBOXDATASTORAGEOBJECTPERMISSIONS

SB_INLINE void TElBoxDataStorageObjectPermissions::Assign(TElBoxDataStorageObjectPermissions &Source)
{
	SBCheckError(TElBoxDataStorageObjectPermissions_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElBoxDataStorageObjectPermissions::Assign(TElBoxDataStorageObjectPermissions *Source)
{
	SBCheckError(TElBoxDataStorageObjectPermissions_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElBoxDataStorageObjectPermissionsHandle TElBoxDataStorageObjectPermissions::Clone()
{
	TElBoxDataStorageObjectPermissionsHandle OutResult;
	SBCheckError(TElBoxDataStorageObjectPermissions_Clone(_Handle, &OutResult));
	return OutResult;
}

bool TElBoxDataStorageObjectPermissions::get_CanComment()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBoxDataStorageObjectPermissions_get_CanComment(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBoxDataStorageObjectPermissions::get_CanDelete()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBoxDataStorageObjectPermissions_get_CanDelete(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBoxDataStorageObjectPermissions::get_CanDownload()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBoxDataStorageObjectPermissions_get_CanDownload(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBoxDataStorageObjectPermissions::get_CanInviteCollaborator()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBoxDataStorageObjectPermissions_get_CanInviteCollaborator(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBoxDataStorageObjectPermissions::get_CanPreview()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBoxDataStorageObjectPermissions_get_CanPreview(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBoxDataStorageObjectPermissions::get_CanRename()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBoxDataStorageObjectPermissions_get_CanRename(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBoxDataStorageObjectPermissions::get_CanSetShareAccess()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBoxDataStorageObjectPermissions_get_CanSetShareAccess(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBoxDataStorageObjectPermissions::get_CanShare()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBoxDataStorageObjectPermissions_get_CanShare(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBoxDataStorageObjectPermissions::get_CanUpload()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBoxDataStorageObjectPermissions_get_CanUpload(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TElBoxDataStorageObjectPermissions::TElBoxDataStorageObjectPermissions(TElBoxDataStorageObjectPermissionsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELBOXDATASTORAGEOBJECT
TElBoxDataStorageObjectPermissions::TElBoxDataStorageObjectPermissions(TElBoxDataStorageObject &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBoxDataStorageObjectPermissions_Create(AOwner.getHandle(), &_Handle));
}

TElBoxDataStorageObjectPermissions::TElBoxDataStorageObjectPermissions(TElBoxDataStorageObject *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBoxDataStorageObjectPermissions_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELBOXDATASTORAGEOBJECT */

#endif /* SB_USE_CLASS_TELBOXDATASTORAGEOBJECTPERMISSIONS */

#ifdef SB_USE_CLASS_TELBOXCOMMENT

SB_INLINE TElBoxCommentHandle TElBoxComment::Clone()
{
	TElBoxCommentHandle OutResult;
	SBCheckError(TElBoxComment_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBoxComment::Delete()
{
	SBCheckError(TElBoxComment_Delete(_Handle));
}

SB_INLINE void TElBoxComment::Refresh()
{
	SBCheckError(TElBoxComment_Refresh(_Handle));
}

SB_INLINE TElBoxCommentHandle TElBoxComment::Reply(const std::string &Message)
{
	TElBoxCommentHandle OutResult;
	SBCheckError(TElBoxComment_Reply(_Handle, Message.data(), (int32_t)Message.length(), &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElBoxComment::get_CreatedAt()
{
	int64_t OutResult;
	SBCheckError(TElBoxComment_get_CreatedAt(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELBOXUSERINFO
TElBoxUserInfo* TElBoxComment::get_CreatedBy()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxComment_get_CreatedBy(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CreatedBy)
		this->_Inst_CreatedBy = new TElBoxUserInfo(hOutResult, ohFalse);
	else
		this->_Inst_CreatedBy->updateHandle(hOutResult);
	return this->_Inst_CreatedBy;
}
#endif /* SB_USE_CLASS_TELBOXUSERINFO */

void TElBoxComment::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxComment_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(177131509, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElBoxComment::get_IsReply()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBoxComment_get_IsReply(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElBoxComment::get_Message(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxComment_get_Message(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(512250160, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBoxComment::set_Message(const std::string &Value)
{
	SBCheckError(TElBoxComment_set_Message(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElBoxComment::get_ModifiedAt()
{
	int64_t OutResult;
	SBCheckError(TElBoxComment_get_ModifiedAt(_Handle, &OutResult));
	return OutResult;
}

void TElBoxComment::get_TaggedMessage(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBoxComment_get_TaggedMessage(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-786230306, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBoxComment::initInstances()
{
#ifdef SB_USE_CLASS_TELBOXUSERINFO
	this->_Inst_CreatedBy = NULL;
#endif /* SB_USE_CLASS_TELBOXUSERINFO */
}

TElBoxComment::TElBoxComment(TElBoxCommentHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELBOXFILE
TElBoxComment::TElBoxComment(TElBoxFile &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxComment_Create(AOwner.getHandle(), &_Handle));
}

TElBoxComment::TElBoxComment(TElBoxFile *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxComment_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELBOXFILE */

TElBoxComment::~TElBoxComment()
{
#ifdef SB_USE_CLASS_TELBOXUSERINFO
	delete this->_Inst_CreatedBy;
	this->_Inst_CreatedBy = NULL;
#endif /* SB_USE_CLASS_TELBOXUSERINFO */
}
#endif /* SB_USE_CLASS_TELBOXCOMMENT */

#ifdef SB_USE_CLASS_TELBOXCOMMENTS

#ifdef SB_USE_CLASS_TELBOXCOMMENT
SB_INLINE TElBoxCommentHandle TElBoxComments::Add(const std::string &Message)
{
	TElBoxCommentHandle OutResult;
	SBCheckError(TElBoxComments_Add(_Handle, Message.data(), (int32_t)Message.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELBOXCOMMENT */

SB_INLINE int32_t TElBoxComments::IndexOf(const std::string &ID)
{
	int32_t OutResult;
	SBCheckError(TElBoxComments_IndexOf(_Handle, ID.data(), (int32_t)ID.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELBOXCOMMENT
SB_INLINE int32_t TElBoxComments::IndexOf(TElBoxComment &Comment)
{
	int32_t OutResult;
	SBCheckError(TElBoxComments_IndexOf_1(_Handle, Comment.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElBoxComments::IndexOf(TElBoxComment *Comment)
{
	int32_t OutResult;
	SBCheckError(TElBoxComments_IndexOf_1(_Handle, (Comment != NULL) ? Comment->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELBOXCOMMENT */

SB_INLINE void TElBoxComments::Refresh()
{
	SBCheckError(TElBoxComments_Refresh(_Handle));
}

SB_INLINE int32_t TElBoxComments::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElBoxComments_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELBOXCOMMENT
TElBoxComment* TElBoxComments::get_Item(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBoxComments_get_Item(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Item)
		this->_Inst_Item = new TElBoxComment(hOutResult, ohFalse);
	else
		this->_Inst_Item->updateHandle(hOutResult);
	return this->_Inst_Item;
}
#endif /* SB_USE_CLASS_TELBOXCOMMENT */

void TElBoxComments::initInstances()
{
#ifdef SB_USE_CLASS_TELBOXCOMMENT
	this->_Inst_Item = NULL;
#endif /* SB_USE_CLASS_TELBOXCOMMENT */
}

TElBoxComments::TElBoxComments(TElBoxCommentsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELBOXFILE
TElBoxComments::TElBoxComments(TElBoxFile &AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxComments_Create(AOwner.getHandle(), &_Handle));
}

TElBoxComments::TElBoxComments(TElBoxFile *AOwner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBoxComments_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELBOXFILE */

TElBoxComments::~TElBoxComments()
{
#ifdef SB_USE_CLASS_TELBOXCOMMENT
	delete this->_Inst_Item;
	this->_Inst_Item = NULL;
#endif /* SB_USE_CLASS_TELBOXCOMMENT */
}
#endif /* SB_USE_CLASS_TELBOXCOMMENTS */

};	/* namespace SecureBlackbox */

